package com.multiplatform.freshworks.model

/**
 * Configuration for initializing the Freshchat SDK.
 *
 * @param appId         Your Freshchat App ID (Admin > Mobile SDK)
 * @param appKey        Your Freshchat App Key
 * @param domain        Your Freshchat domain e.g. "msdk.in.freshchat.com"
 * @param cameraCaptureEnabled      Allow camera capture in chat
 * @param gallerySelectionEnabled   Allow gallery selection in chat
 * @param responseExpectationEnabled Show response time expectation
 * @param teamMemberInfoVisible     Show agent avatar
 * @param fileAttachmentEnabled     Allow file attachments
 * @param showNotificationBanner    iOS only: show in-app notification banner
 * @param notificationSoundEnabled  iOS only: play notification sound
 */
data class FreshchatConfig(
    val appId: String,
    val appKey: String,
    val domain: String,
    val cameraCaptureEnabled: Boolean = true,
    val gallerySelectionEnabled: Boolean = true,
    val responseExpectationEnabled: Boolean = true,
    val teamMemberInfoVisible: Boolean = true,
    val fileAttachmentEnabled: Boolean = true,
    // iOS specific
    val showNotificationBanner: Boolean = true,
    val notificationSoundEnabled: Boolean = true,
)