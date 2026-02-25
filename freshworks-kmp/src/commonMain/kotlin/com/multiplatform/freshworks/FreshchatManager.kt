package com.multiplatform.freshworks

import com.multiplatform.freshworks.FreshchatManager.initialize
import com.multiplatform.freshworks.FreshchatManager.isFreshchatNotification
import com.multiplatform.freshworks.FreshchatManager.setPushRegistrationToken
import com.multiplatform.freshworks.model.FreshchatConfig
import com.multiplatform.freshworks.model.FreshchatEventObserver
import com.multiplatform.freshworks.model.FreshchatFaqOptions
import com.multiplatform.freshworks.model.FreshchatPlatformContext
import com.multiplatform.freshworks.model.FreshchatResult
import com.multiplatform.freshworks.model.FreshchatUser

/**
 * KMP Freshchat Manager — common expect interface.
 *
 * Use [FreshchatManager.instance] (after calling [initialize]) to interact
 * with the Freshchat SDK on both Android and iOS.
 *
 * Typical on-demand usage (mirrors your FreshchatInitializer pattern):
 * ```kotlin
 * // When user opens support
 * FreshchatManager.instance.initialize(config)
 * FreshchatManager.instance.showConversations()
 * ```
 */
expect object FreshchatManager {

    /**
     * Initialize the Freshchat SDK with the given [config].
     * Must be called before any other API. Safe to call multiple times
     * (subsequent calls are no-ops if already initialized).
     */
    suspend fun initialize(config: FreshchatConfig): FreshchatResult

    /**
     * Returns true if the SDK has been successfully initialized.
     */
    val isInitialized: Boolean

    // ─── Push Notifications ───────────────────────────────────────────────────

    /**
     * Register a device push token with Freshchat.
     * - Android: pass the FCM token string
     * - iOS: pass the raw APNS [ByteArray] device token
     *        (bridge converts it automatically on the actual side)
     */
    fun setPushRegistrationToken(token: String)

    /**
     * iOS only: Pass the raw APNS device token bytes.
     * On Android this is a no-op (use [setPushRegistrationToken] with FCM string).
     */
    fun setPushRegistrationTokenData(tokenData: ByteArray)

    /**
     * Returns true if the given notification payload originated from Freshchat.
     * - Android: pass the RemoteMessage data map as a [Map<String, String>]
     * - iOS:     pass the userInfo dictionary as a [Map<String, Any>]
     */
    fun isFreshchatNotification(payload: Map<String, Any?>): Boolean

    /**
     * Let Freshchat handle the notification.
     * Call this after confirming [isFreshchatNotification] returns true.
     */
    fun handlePushNotification(payload: Map<String, Any?>)

    // ─── User Management ──────────────────────────────────────────────────────

    /**
     * Set basic user info (name, email, phone).
     */
    fun setUser(user: FreshchatUser)

    /**
     * Authenticate / restore a user using a JWT token.
     */
    fun restoreUserWithToken(jwtToken: String)

    /**
     * Identify a user by external ID (and optionally a restore ID).
     * Pass null for [restoreId] on first-time identification.
     */
    fun identifyUser(externalId: String, restoreId: String?)

    /**
     * Set custom user properties for segmentation / agent context.
     */
    fun setUserProperties(properties: Map<String, String>)

    /**
     * Clear all user data — call on logout.
     */
    fun resetUser()

    // ─── Conversations / FAQs ─────────────────────────────────────────────────

    /**
     * Show the conversations screen.
     * On Android: requires an Activity context — pass via [FreshchatPlatformContext].
     * On iOS:     the presenting view controller is inferred automatically.
     */
    fun showConversations(
        platformContext: FreshchatPlatformContext? = null,
        options: FreshchatFaqOptions?
    )

    /**
     * Show the FAQs screen.
     */
    fun showFAQs(
        platformContext: FreshchatPlatformContext? = null,
        options: FreshchatFaqOptions? = null,
    )

    // ─── Events ───────────────────────────────────────────────────────────────

    /**
     * Track a custom user event.
     */
    fun trackEvent(name: String, properties: Map<String, Any?>? = null)

    /**
     * Observe Freshchat SDK events (restore-ID generated, JWT status changes…).
     * Call [FreshchatEventObserver.unregister] when done.
     */
    fun addEventObserver(observer: FreshchatEventObserver): FreshchatEventObserver

    /**
     * Remove a previously registered observer.
     */
    fun removeEventObserver(observer: FreshchatEventObserver)
}