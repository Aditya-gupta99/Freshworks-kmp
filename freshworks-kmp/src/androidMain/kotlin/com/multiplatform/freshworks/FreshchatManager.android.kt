package com.multiplatform.freshworks

import android.content.BroadcastReceiver
import android.content.Context
import android.content.Intent
import android.content.IntentFilter
import android.util.Log
import androidx.localbroadcastmanager.content.LocalBroadcastManager
import com.freshchat.consumer.sdk.ConversationOptions
import com.freshchat.consumer.sdk.Event
import com.freshchat.consumer.sdk.FaqOptions
import com.freshchat.consumer.sdk.Freshchat
import com.multiplatform.freshworks.FreshchatManager.initialize
import com.multiplatform.freshworks.FreshchatManager.setPushRegistrationToken
import com.multiplatform.freshworks.model.FreshchatConfig
import com.multiplatform.freshworks.model.FreshchatEvent
import com.multiplatform.freshworks.model.FreshchatEventObserver
import com.multiplatform.freshworks.model.FreshchatEventType
import com.multiplatform.freshworks.model.FreshchatFaqFilterType
import com.multiplatform.freshworks.model.FreshchatFaqOptions
import com.multiplatform.freshworks.model.FreshchatPlatformContext
import com.multiplatform.freshworks.model.FreshchatResult
import com.multiplatform.freshworks.model.FreshchatUser
import kotlinx.coroutines.Dispatchers
import kotlinx.coroutines.withContext
import java.util.concurrent.CopyOnWriteArrayList
import com.freshchat.consumer.sdk.FreshchatConfig as SdkFreshchatConfig
import com.freshchat.consumer.sdk.FreshchatUser as SdkFreshchatUser

private const val TAG = "FreshchatManager"


actual object FreshchatManager {

    // Application context — set lazily via initialize()
    private var appContext: Context? = null

    @Volatile
    private var _isInitialized: Boolean = false

    actual val isInitialized: Boolean
        get() = _isInitialized

    private val observers = CopyOnWriteArrayList<ObserverEntry>()

    // Receivers kept so we can unregister them
    private var restoreIdReceiver: BroadcastReceiver? = null
    private var eventsReceiver: BroadcastReceiver? = null

    // ─── Init ─────────────────────────────────────────────────────────────────

    actual suspend fun initialize(config: FreshchatConfig): FreshchatResult {
        if (_isInitialized) {
            return FreshchatResult.success("Freshchat already initialized")
        }
        val ctx = requireNotNull(appContext) {
            "Call FreshchatManager.setApplicationContext(context) from Application.onCreate() first."
        }

        return withContext(Dispatchers.IO) {
            try {
                val sdkConfig = SdkFreshchatConfig(config.appId, config.appKey).apply {
                    domain = config.domain
                    isCameraCaptureEnabled = config.cameraCaptureEnabled
                    isGallerySelectionEnabled = config.gallerySelectionEnabled
                    isResponseExpectationEnabled = config.responseExpectationEnabled
                    isTeamMemberInfoVisible = config.teamMemberInfoVisible
                    isFileSelectionEnabled = config.fileAttachmentEnabled
                }

                withContext(Dispatchers.Main) {
                    Freshchat.getInstance(ctx).init(sdkConfig)
                }

                registerBroadcastReceivers(ctx)
                _isInitialized = true

                FreshchatResult.success(
                    message = "Freshchat initialized",
                    metadata = mapOf("domain" to config.domain),
                )
            } catch (e: Exception) {
                Log.e(TAG, "Freshchat initialization failed", e)
                FreshchatResult.failure(e)
            }
        }
    }

    /**
     * Must be called once from your Application class before [initialize].
     * ```kotlin
     * class MyApp : Application() {
     *     override fun onCreate() {
     *         super.onCreate()
     *         FreshchatManager.setApplicationContext(this)
     *     }
     * }
     * ```
     */
    fun setApplicationContext(context: Context) {
        appContext = context.applicationContext
    }

    // ─── Push Notifications ───────────────────────────────────────────────────

    actual fun setPushRegistrationToken(token: String) {
        val ctx = appContext ?: run { Log.w(TAG, "Context not set"); return }
        Freshchat.getInstance(ctx).setPushRegistrationToken(token)
    }

    /** No-op on Android — use [setPushRegistrationToken] with FCM string. */
    actual fun setPushRegistrationTokenData(tokenData: ByteArray) {
        Log.d(TAG, "setPushRegistrationTokenData is a no-op on Android")
    }

    actual fun isFreshchatNotification(payload: Map<String, Any?>): Boolean {
        // On Android the payload comes as RemoteMessage.data (Map<String,String>)
        // We can't use the SDK's isFreshchatNotification(RemoteMessage) directly here,
        // so check for the Freshchat-specific key manually.
        return payload.containsKey("freshchat_notification") ||
                payload.containsKey("notification_id") &&
                payload["source"] == "freshchat"
    }

    actual fun handlePushNotification(payload: Map<String, Any?>) {
        // Callers who have access to RemoteMessage should call
        // Freshchat.handleFcmMessage(context, remoteMessage) directly.
        // This common API covers the data-only path.
        Log.d(TAG, "handlePushNotification called with ${payload.size} keys")
        appContext?.let { Freshchat.handleFcmMessage(it, payload) }
    }

    // ─── User ─────────────────────────────────────────────────────────────────

    actual fun setUser(user: FreshchatUser) {
        val ctx = appContext ?: return
        val sdkUser: SdkFreshchatUser = Freshchat.getInstance(ctx).user
        sdkUser?.apply {
            user.firstName?.let { firstName = it }
            user.lastName?.let { lastName = it }
            user.email?.let { email = it }
            if (user.phoneCountryCode != null && user.phone != null) {
                setPhone(user.phoneCountryCode, user.phone)
            }
        }
        sdkUser?.let { Freshchat.getInstance(ctx).setUser(it) }
    }

    actual fun restoreUserWithToken(jwtToken: String) {
        val ctx = appContext ?: return
        Freshchat.getInstance(ctx).restoreUser(jwtToken)
    }

    actual fun identifyUser(externalId: String, restoreId: String?) {
        val ctx = appContext ?: return
        Freshchat.getInstance(ctx).identifyUser(externalId, restoreId)
    }

    actual fun setUserProperties(properties: Map<String, String>) {
        val ctx = appContext ?: return
        Freshchat.getInstance(ctx).setUserProperties(properties)
    }

    actual fun resetUser() {
        val ctx = appContext ?: return
        Freshchat.resetUser(ctx)
    }

    // ─── UI ───────────────────────────────────────────────────────────────────

    actual fun showConversations(
        platformContext: FreshchatPlatformContext?,
        options: FreshchatFaqOptions?
    ) {
        val ctx = platformContext?.activity ?: appContext ?: run {
            Log.e(TAG, "No context available to show conversations")
            return
        }
        val convOptions = ConversationOptions().apply {
            if (!options?.tags.isNullOrEmpty()) {
                filterByTags(
                    options.tags,
                    options.filteredViewTitle ?: "",
                )
            }
        }
        Freshchat.showConversations(ctx, convOptions)
    }

    actual fun showFAQs(platformContext: FreshchatPlatformContext?, options: FreshchatFaqOptions?) {
        val ctx = platformContext?.activity ?: appContext ?: run {
            Log.e(TAG, "No context available to show FAQs")
            return
        }
        if (options == null) {
            Freshchat.showFAQs(ctx)
        } else {
            val sdkOptions = FaqOptions().apply {
                showFaqCategoriesAsGrid(options.showFaqCategoriesAsGrid)
                showContactUsOnAppBar(options.showContactUsOnAppBar)
                showContactUsOnFaqScreens(options.showContactUsOnFaqScreens)
                showContactUsOnFaqNotHelpful(options.showContactUsOnFaqNotHelpful)
                if (!options.tags.isNullOrEmpty()) {
                    filterByTags(
                        options.tags,
                        options.filteredViewTitle ?: "",
                        when (options.filterType) {
                            FreshchatFaqFilterType.CATEGORY -> FaqOptions.FilterType.CATEGORY
                            FreshchatFaqFilterType.ARTICLE -> FaqOptions.FilterType.ARTICLE
                        },
                    )
                }
            }
            Freshchat.showFAQs(ctx, sdkOptions)
        }
    }

    // ─── Events ───────────────────────────────────────────────────────────────

    actual fun trackEvent(name: String, properties: Map<String, Any?>?) {
        val ctx = appContext ?: return
        @Suppress("UNCHECKED_CAST")
        Freshchat.trackEvent(ctx, name, properties as? Map<String, Any>)
    }

    actual fun addEventObserver(observer: FreshchatEventObserver): FreshchatEventObserver {
        observers.add(ObserverEntry(observer))
        return observer
    }

    actual fun removeEventObserver(observer: FreshchatEventObserver) {
        observers.removeIf { it.observer === observer }
    }

    // ─── Internal broadcast receivers ─────────────────────────────────────────

    private fun registerBroadcastReceivers(ctx: Context) {
        val lbm = LocalBroadcastManager.getInstance(ctx)

        // Restore ID generated
        restoreIdReceiver = object : BroadcastReceiver() {
            override fun onReceive(context: Context?, intent: Intent?) {
                val restoreId = Freshchat.getInstance(ctx).user?.restoreId ?: return
                Log.d(TAG, "Restore ID generated: $restoreId")
                dispatchEvent(
                    FreshchatEvent(
                        type = FreshchatEventType.RESTORE_ID_GENERATED,
                        rawName = Freshchat.FRESHCHAT_USER_RESTORE_ID_GENERATED,
                        data = mapOf("restoreId" to restoreId),
                    )
                )
            }
        }.also {
            lbm.registerReceiver(it, IntentFilter(Freshchat.FRESHCHAT_USER_RESTORE_ID_GENERATED))
        }

        // Generic Freshchat events (JWT status, unread count…)
        eventsReceiver = object : BroadcastReceiver() {
            override fun onReceive(context: Context?, intent: Intent?) {
                val extras = intent?.extras ?: return
                val sdkEvent: Event? = Freshchat.getEventFromBundle(extras)
                val type = when (sdkEvent?.eventName) {
                    Event.EventName.FCEventIdTokenStatusChange -> FreshchatEventType.JWT_TOKEN_STATUS_CHANGE
//                    Event.EventName.FCEventUnreadMessageCountChanged -> FreshchatEventType.UNREAD_MESSAGE_COUNT_CHANGED
                    else -> FreshchatEventType.OTHER
                }
                val rawData = intent.getStringExtra("FRESHCHAT_EVENTS")
                dispatchEvent(
                    FreshchatEvent(
                        type = type,
                        rawName = sdkEvent?.eventName?.name ?: "UNKNOWN",
                        data = mapOf("raw" to rawData),
                    )
                )
            }
        }.also {
            lbm.registerReceiver(it, IntentFilter(Freshchat.FRESHCHAT_EVENTS))
        }
    }

    /**
     * Unregister receivers — call from Application.onTerminate() or when done.
     */
    fun unregisterReceivers() {
        val ctx = appContext ?: return
        val lbm = LocalBroadcastManager.getInstance(ctx)
        restoreIdReceiver?.let { lbm.unregisterReceiver(it) }
        eventsReceiver?.let { lbm.unregisterReceiver(it) }
    }

    private fun dispatchEvent(event: FreshchatEvent) {
        observers.forEach { it.observer.onEvent(event) }
    }

    private data class ObserverEntry(val observer: FreshchatEventObserver)
}

// ─── Extension helpers ────────────────────────────────────────────────────────

/**
 * Helper for FirebaseMessagingService — pass [RemoteMessage] directly.
 * ```kotlin
 * override fun onMessageReceived(remoteMessage: RemoteMessage) {
 *     if (remoteMessage.isFreshchat(context)) {
 *         remoteMessage.handleFreshchat(context)
 *     }
 * }
 * ```
 */
fun com.google.firebase.messaging.RemoteMessage.isFreshchat(context: Context): Boolean =
    Freshchat.isFreshchatNotification(this)

fun com.google.firebase.messaging.RemoteMessage.handleFreshchat(context: Context) =
    Freshchat.handleFcmMessage(context, this)
