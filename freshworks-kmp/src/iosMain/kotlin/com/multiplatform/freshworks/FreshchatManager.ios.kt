@file:OptIn(ExperimentalForeignApi::class)

package com.multiplatform.freshworks

import cocoapods.FreshchatSDK.ConversationOptions
import cocoapods.FreshchatSDK.FAQOptions
import cocoapods.FreshchatSDK.FCEvent
import cocoapods.FreshchatSDK.FRESHCHAT_EVENTS
import cocoapods.FreshchatSDK.FRESHCHAT_USER_RESTORE_ID_GENERATED
import cocoapods.FreshchatSDK.Freshchat
import com.multiplatform.freshworks.model.FreshchatConfig
import com.multiplatform.freshworks.model.FreshchatEvent
import com.multiplatform.freshworks.model.FreshchatEventObserver
import com.multiplatform.freshworks.model.FreshchatEventType
import com.multiplatform.freshworks.model.FreshchatFaqOptions
import com.multiplatform.freshworks.model.FreshchatPlatformContext
import com.multiplatform.freshworks.model.FreshchatResult
import com.multiplatform.freshworks.model.FreshchatUser
import kotlinx.cinterop.ExperimentalForeignApi
import kotlinx.cinterop.addressOf
import kotlinx.cinterop.usePinned
import platform.Foundation.NSData
import platform.Foundation.NSNotificationCenter
import platform.Foundation.NSOperationQueue
import platform.Foundation.dataWithBytes
import platform.UIKit.UIApplication
import platform.UIKit.UIViewController
import platform.darwin.NSObjectProtocol
import kotlin.concurrent.Volatile

// ─── iOS Actual – FreshchatManager ───────────────────────────────────────────

actual object FreshchatManager {

    @Volatile
    private var _isInitialized: Boolean = false

    actual val isInitialized: Boolean
        get() = _isInitialized

    private val observers = mutableListOf<FreshchatEventObserver>()
    private var notificationObservers = mutableListOf<NSObjectProtocol>()

    // ─── Init ─────────────────────────────────────────────────────────────────

    actual suspend fun initialize(config: FreshchatConfig): FreshchatResult {
        if (isInitialized) return FreshchatResult.success("Freshchat already initialized")

        return try {
            val sdkConfig = cocoapods.FreshchatSDK.FreshchatConfig()
            sdkConfig.appID = config.appId
            sdkConfig.appKey = config.appKey
            sdkConfig.domain = config.domain
            sdkConfig.cameraCaptureEnabled = config.cameraCaptureEnabled
            sdkConfig.gallerySelectionEnabled = config.gallerySelectionEnabled
            sdkConfig.teamMemberInfoVisible = config.teamMemberInfoVisible
            sdkConfig.notificationSoundEnabled = config.notificationSoundEnabled

            Freshchat.sharedInstance().initWithConfig(sdkConfig)
            registerNotificationObservers()
            _isInitialized = true

            FreshchatResult.success(
                message = "Freshchat initialized (iOS)",
                metadata = mapOf("domain" to config.domain),
            )
        } catch (e: Throwable) {
            FreshchatResult.failure(e)
        }
    }

    // ─── Push Notifications ───────────────────────────────────────────────────

    /** On iOS pass the FCM token string (if using FCM for APNs delivery). */
    actual fun setPushRegistrationToken(token: String) {
        // Used when routing through FCM — converts string to Data internally.
        Freshchat.sharedInstance().setPushRegistrationToken(token.encodeToByteArray().toNSData())
    }

    /** Pass the raw APNS deviceToken bytes from didRegisterForRemoteNotificationsWithDeviceToken. */
    actual fun setPushRegistrationTokenData(tokenData: ByteArray) {
        Freshchat.sharedInstance().setPushRegistrationToken(tokenData.toNSData())
    }

    actual fun isFreshchatNotification(payload: Map<String, Any?>): Boolean {
        @Suppress("UNCHECKED_CAST")
        val userInfo = payload as? Map<Any?, *> ?: return false
        return Freshchat.sharedInstance().isFreshchatNotification(userInfo)
    }

    actual fun handlePushNotification(payload: Map<String, Any?>) {
        @Suppress("UNCHECKED_CAST")
        val userInfo = payload as? Map<Any?, *> ?: return
        Freshchat.sharedInstance().handleRemoteNotification(
            userInfo,
            andAppstate = UIApplication.sharedApplication.applicationState,
        )
    }

    // ─── User ─────────────────────────────────────────────────────────────────

    actual fun setUser(user: FreshchatUser) {
        val sdkUser = cocoapods.FreshchatSDK.FreshchatUser.sharedInstance()
        user.firstName?.let { sdkUser.firstName = it }
        user.lastName?.let { sdkUser.lastName = it }
        user.email?.let { sdkUser.email = it }
        user.phoneCountryCode?.let { sdkUser.phoneCountryCode = it }
        user.phone?.let { sdkUser.phoneNumber = it }
        Freshchat.sharedInstance().setUser(sdkUser)
    }

    actual fun restoreUserWithToken(jwtToken: String) {
        Freshchat.sharedInstance().restoreUserWithIdToken(jwtToken)
    }

    actual fun identifyUser(externalId: String, restoreId: String?) {
        Freshchat.sharedInstance().identifyUserWithExternalID(externalId, restoreID = restoreId)
    }

    actual fun setUserProperties(properties: Map<String, String>) {
        properties.forEach { (key, value) ->
            Freshchat.sharedInstance().setUserPropertyforKey(key, withValue = value)
        }
    }

    actual fun resetUser() {
        Freshchat.sharedInstance().resetUserWithCompletion(null)
    }

    // ─── UI ───────────────────────────────────────────────────────────────────

    actual fun showConversations(
        platformContext: FreshchatPlatformContext?,
        options: FreshchatFaqOptions?
    ) {
        val vc = platformContext?.viewController ?: topViewController() ?: return
        val convOptions = ConversationOptions().apply {
            if (!options?.tags.isNullOrEmpty()) {
                filterByTags(
                    options.tags,
                    options.filteredViewTitle ?: "",
                )
            }
        }
        Freshchat.sharedInstance().showConversations(vc, convOptions)
    }

    actual fun showFAQs(platformContext: FreshchatPlatformContext?, options: FreshchatFaqOptions?) {
        val vc = platformContext?.viewController ?: topViewController() ?: return
        if (options == null) {
            Freshchat.sharedInstance().showFAQs(vc)
        } else {
            FAQOptions().apply {
                showFaqCategoriesAsGrid = options.showFaqCategoriesAsGrid
                showContactUsOnFaqScreens = options.showContactUsOnFaqScreens
                showContactUsOnFaqNotHelpful = options.showContactUsOnFaqNotHelpful
                showContactUsOnAppBar = options.showContactUsOnAppBar
//                if (!options.tags.isNullOrEmpty()) {
//                    filter(
//                        byTags = options.tags,
//                        withTitle = options.filteredViewTitle ?: "",
//                        andType = when (options.filterType) {
//                            FreshchatFaqFilterType.CATEGORY -> CATEGORY
//                            FreshchatFaqFilterType.ARTICLE -> ARTICLE
//                        },
//                    )
//                }
            }
            Freshchat.sharedInstance().showFAQs(vc)
        }
    }

    // ─── Events ───────────────────────────────────────────────────────────────

    actual fun trackEvent(name: String, properties: Map<String, Any?>?) {
        (properties as? Map<Any?, *>)?.let {
            @Suppress("UNCHECKED_CAST")
            Freshchat.sharedInstance().trackEvent(name, withProperties = it)
        }
    }

    actual fun addEventObserver(observer: FreshchatEventObserver): FreshchatEventObserver {
        observers.add(observer)
        return observer
    }

    actual fun removeEventObserver(observer: FreshchatEventObserver) {
        observers.remove(observer)
    }

    // ─── Internal NSNotification observers ───────────────────────────────────

    private fun registerNotificationObservers() {
        val nc = NSNotificationCenter.defaultCenter

        // Restore ID generated
        val restoreObserver = nc.addObserverForName(
            name = FRESHCHAT_USER_RESTORE_ID_GENERATED,
            `object` = null,
            queue = NSOperationQueue.mainQueue,
        ) { notification ->
            val restoreId = cocoapods.FreshchatSDK.FreshchatUser.sharedInstance().restoreID ?: ""
            dispatchEvent(
                FreshchatEvent(
                    type = FreshchatEventType.RESTORE_ID_GENERATED,
                    rawName = FRESHCHAT_USER_RESTORE_ID_GENERATED,
                    data = mapOf("restoreId" to restoreId),
                )
            )
        }
        notificationObservers.add(restoreObserver)

        // Generic events
        val eventsObserver = nc.addObserverForName(
            name = FRESHCHAT_EVENTS,
            `object` = null,
            queue = NSOperationQueue.mainQueue,
        ) { notification ->
            val fcEvent =
                notification?.userInfo?.get("event") as? cocoapods.FreshchatSDK.FreshchatEvent
            val type = when {
                fcEvent?.name == FCEvent.FCEventIdTokenStatusChange -> FreshchatEventType.JWT_TOKEN_STATUS_CHANGE
                else -> FreshchatEventType.OTHER
            }
            dispatchEvent(
                FreshchatEvent(
                    type = type,
                    rawName = fcEvent?.name?.toString() ?: "UNKNOWN",
                    data = emptyMap(),
                )
            )
        }
        notificationObservers.add(eventsObserver)
    }

    /**
     * Call when you want to release observers (e.g. app going to background for good).
     */
    fun unregisterObservers() {
        val nc = NSNotificationCenter.defaultCenter
        notificationObservers.forEach { nc.removeObserver(it) }
        notificationObservers.clear()
    }

    private fun dispatchEvent(event: FreshchatEvent) {
        observers.forEach { it.onEvent(event) }
    }

    // ─── Helper: top view controller ─────────────────────────────────────────

    private fun topViewController(): UIViewController? {
        var vc = UIApplication.sharedApplication.keyWindow?.rootViewController
        while (vc?.presentedViewController != null) {
            vc = vc.presentedViewController
        }
        return vc
    }
}

// ─── ByteArray ↔ NSData ───────────────────────────────────────────────────────

private fun ByteArray.toNSData(): NSData =
    this.usePinned { pinned ->
        NSData.dataWithBytes(pinned.addressOf(0), size.toULong())
    }