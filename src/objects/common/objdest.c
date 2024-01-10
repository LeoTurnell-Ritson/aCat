#include <catstring.h>
#include <cat/private/catimpl.h>

CAT_RETURN_CODE __ObjectDestroy(object_p *obj)
{
        CatFunctionBegin;
        if (!(*obj)) return CAT_ERR_INVALID_POINTER;
        if ((*obj)->class) CatFunction(CatFree((*obj)->class));
        if ((*obj)->type) CatFunction(CatFree((*obj)->type));
        CatFunctionReturn(CAT_SUCCESS);
}
