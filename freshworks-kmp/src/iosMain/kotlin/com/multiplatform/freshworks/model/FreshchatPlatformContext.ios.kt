package com.multiplatform.freshworks.model

import platform.UIKit.UIViewController

actual class FreshchatPlatformContext(internal val viewController: UIViewController?) {
    companion object {
        fun fromViewController(vc: UIViewController): FreshchatPlatformContext =
            FreshchatPlatformContext(vc)

        /** Infer the top-most presented view controller automatically. */
        fun inferred(): FreshchatPlatformContext = FreshchatPlatformContext(null)
    }
}