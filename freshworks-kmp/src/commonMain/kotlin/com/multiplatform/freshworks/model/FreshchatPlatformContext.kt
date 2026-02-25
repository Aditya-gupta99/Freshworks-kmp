package com.multiplatform.freshworks.model

/**
 * Wraps platform-specific context needed to show UI.
 * Create via platform-specific factories:
 * - Android: [FreshchatPlatformContext.fromActivity]
 * - iOS:     [FreshchatPlatformContext.fromViewController]  (or pass null — SDK infers)
 */
expect class FreshchatPlatformContext