#include <cat/private/domainimpl.h>

CAT_RETURN_CODE DomainDestroy(DOMAIN **dom)
{
        CatFunctionBegin;
        __HeaderUseTypeMethod(*dom, destroy);
        CatFunction(__HeaderDestroy(dom));
        CatFunctionReturn(CAT_SUCCESS);
}
