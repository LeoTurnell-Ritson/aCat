#include <catstring.h>
#include <cat/private/domainimpl.h>

CAT_RETURN_CODE __DomainBuildInternal(DOMAIN *dom)
{
        bool    match;
        char      *type;
        MPI_Comm   comm;

        CatFunctionBegin;
        CatFunction(__HeaderGetComm(dom, &comm));
        CatFunction(__HeaderGetType(dom, &type));
        if (!type) return CAT_ERR_BAD_INITIALIZATION;
        CatFunction(CatStrcmp(type, DOMAIN_BLOCK, &match));
        if (match) {
                CatFunction(__DomainBuildInternalBlock(dom));
                CatFunctionReturn(CAT_SUCCESS);
        } else {
                CatCheck(CAT_FALSE, comm, CAT_ERR_BAD_INITIALIZATION, "type %s not recognised for domain objects", type)
        }
}
