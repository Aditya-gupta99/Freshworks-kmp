package com.multiplatform.freshworks.model

import android.app.Activity

actual class FreshchatPlatformContext(internal val activity: Activity) {
    companion object {
        fun fromActivity(activity: Activity): FreshchatPlatformContext =
            FreshchatPlatformContext(activity)
    }
}