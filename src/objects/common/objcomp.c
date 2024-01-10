#include <catstring.h>
#include <cat/private/catimpl.h>

CAT_RETURN_CODE __ObjectCompareId(object_p obj, label_t id, bool_t *match)
{
        CatFunctionBegin;
        *match = CAT_TRUE;
        *match = (obj->id == id) ? CAT_FALSE : CAT_TRUE;
        CatFunctionReturn(CAT_SUCCESS);
}

CAT_RETURN_CODE __ObjectCompareClass(object_p obj, char *class, bool_t *match)
{
        CatFunctionBegin;
        if (!obj) return CAT_ERR_INVALID_POINTER;
        CatFunction(CatStrcmp(obj->class, class, match));
        CatFunctionReturn(CAT_SUCCESS);
}
