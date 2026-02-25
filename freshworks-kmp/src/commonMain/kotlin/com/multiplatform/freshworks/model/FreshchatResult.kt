package com.multiplatform.freshworks.model

sealed class FreshchatResult {
    data class Success(val message: String = "", val metadata: Map<String, Any?> = emptyMap()) :
        FreshchatResult()

    data class Failure(
        val error: Throwable,
        val message: String = error.message ?: "Unknown error"
    ) : FreshchatResult()

    val isSuccess get() = this is Success
    val isFailure get() = this is Failure

    companion object {
        fun success(
            message: String = "",
            metadata: Map<String, Any?> = emptyMap()
        ): FreshchatResult =
            Success(message, metadata)

        fun failure(error: Throwable): FreshchatResult = Failure(error)
        fun failure(message: String): FreshchatResult = Failure(RuntimeException(message), message)
    }
}