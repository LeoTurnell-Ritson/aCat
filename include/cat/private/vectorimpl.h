#pragma once

#include <catvector.h>
#include <cat/private/catimpl.h>

struct __vector {
        int size;
        scalar_t *arr;
};


static CAT_INLINE CAT_RETURN_CODE __VectorSizeCompare(vector_p a, vector_p b, bool *t)
{
        CatFunctionBegin;
        *t = CAT_FALSE;
        *t = (a->size == b->size) ? CAT_TRUE : CAT_FALSE;
        CatFunctionReturn(CAT_SUCCESS);
}
