package com.multiplatform.freshworks.model

data class FreshchatEvent(
    val type: FreshchatEventType,
    val rawName: String,
    val data: Map<String, Any?> = emptyMap(),
)