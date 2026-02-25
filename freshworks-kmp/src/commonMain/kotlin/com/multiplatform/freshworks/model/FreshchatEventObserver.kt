package com.multiplatform.freshworks.model

fun interface FreshchatEventObserver {
    fun onEvent(event: FreshchatEvent)

    /** Convenience — implemented on actual sides. */
    fun unregister() {}
}