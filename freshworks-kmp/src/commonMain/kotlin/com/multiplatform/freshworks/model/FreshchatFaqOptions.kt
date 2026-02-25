package com.multiplatform.freshworks.model

data class FreshchatFaqOptions(
    val tags: List<String>? = null,
    val filteredViewTitle: String? = null,
    val filterType: FreshchatFaqFilterType = FreshchatFaqFilterType.CATEGORY,
    val showFaqCategoriesAsGrid: Boolean = true,
    val showContactUsOnFaqScreens: Boolean = true,
    val showContactUsOnFaqNotHelpful: Boolean = true,
    val showContactUsOnAppBar: Boolean = true,
)