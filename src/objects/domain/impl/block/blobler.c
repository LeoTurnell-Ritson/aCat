#include <../src/objects/domain/impl/block/blo.h>

static struct __domops blockops = {
        .create         = __DomainBlockCreate,
        .destroy        = __DomainBlockDestroy,
        .setfromoptions = __DomainBlockSetFromOptions
};

CAT_RETURN_CODE __DomainBuildInternalBlock(domain_p dom)
{
        CatFunctionBegin;
        __HeaderSetOps(dom, blockops);
        __HeaderUseTypeMethod(dom, create);
        CatFunctionReturn(CAT_SUCCESS);
}
