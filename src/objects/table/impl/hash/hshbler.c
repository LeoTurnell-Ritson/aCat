#include <../src/objects/table/impl/hash/hsh.h>

static struct __tabops hashops = {
        .create  = __TableHashCreate,
        .destroy =__TableHashDestroy,
        .pop     = __TableHashPop,
        .push    = __TableHashPush,
        .search  = __TableHashSeach,
        .lookup  = __TableHashLookup
};

CAT_RETURN_CODE __TableBuildInternalHash(TABLE *tab)
{
        CatFunctionBegin;
        __HeaderSetOps(tab, hashops);
        __HeaderUseTypeMethod(tab, create);
        CatFunctionReturn(CAT_SUCCESS);
}
