#include <catstring.h>
#include <cat/private/tableimpl.h>

CAT_RETURN_CODE __TableBuildInternal(table_p tab)
{
        bool_t match;

        CatFunctionBegin;
        if (!(((object_p)tab)->type)) return CAT_ERR_BAD_INITIALIZATION;
        CatFunction(CatStrcmp(((object_p)tab)->type, TABLE_HASH, &match));
        if (match) {
                CatFunction(__TableBuildInternalHash(tab));
                CatFunctionReturn(CAT_SUCCESS);
        }
        if (!match) return CAT_ERR_UNREACHABLE;
        CatFunctionReturn(CAT_SUCCESS);
}
