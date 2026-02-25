package com.multiplatform.freshworks.model

/**
 * Represents a Freshchat user.
 */
data class FreshchatUser(
    val firstName: String? = null,
    val lastName: String? = null,
    val email: String? = null,
    val phoneCountryCode: String? = null,
    val phone: String? = null,
)