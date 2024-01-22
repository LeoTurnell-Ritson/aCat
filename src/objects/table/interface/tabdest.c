#include <cat/private/tableimpl.h>

CAT_RETURN_CODE TableDestroy(TABLE **tab)
{
        CatFunctionBegin;
        __HeaderUseTypeMethod(*tab, destroy);
        CatFunction(__HeaderDestroy(tab));
        CatFunctionReturn(CAT_SUCCESS);
}
