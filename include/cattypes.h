#pragma once

typedef enum {
        CAT_FALSE = 0,
        CAT_TRUE = 1
} bool_t;

typedef enum {
        CAT_SUCCESS = 0,
        CAT_ERR_BOOLEAN_MACRO_FAILURE,
        CAT_ERR_ASSERTION,
        CAT_ERR_NOT_IMPLEMENTED,
        CAT_ERR_MEMORY,
        CAT_ERR_SYSTEM_LIBARY,
        CAT_ERR_INVALID_POINTER,
        CAT_ERR_UNREACHABLE,
        CAT_ERR_OPERATION_NOT_SET,
        CAT_ERR_DEBUG_MEMORY_MALLOC,
        CAT_ERR_DEBUG_MEMORY_FREE,
        CAT_ERR_BAD_INITIALIZATION,
        CAT_ERR_BAD_DIMENSIONS,
        CAT_ERR_MEMORY_LEAK,
        CAT_ERR_BAD_LOOKUP
} error_t;

typedef double scalar_t;

typedef unsigned int label_t;
