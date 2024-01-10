#include <../src/objects/domain/impl/block/blo.h>

CAT_EXTERN CAT_RETURN_CODE __DomainBlockCreate(domain_p dom)
{
        struct __block *blo;

        CatFunctionBegin;
        CatFunction(CatNew(&blo));
        dom->data = (void *)blo;
        dom->ops->create = NULL;
        CatFunctionReturn(CAT_SUCCESS);
}
