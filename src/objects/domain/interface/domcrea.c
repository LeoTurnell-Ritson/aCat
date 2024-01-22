#include <cat/private/domainimpl.h>

CAT_RETURN_CODE DomainCreate(MPI_Comm comm, DOMAIN **dom)
{
        CatFunctionBegin;
        CatFunction(__HeaderCreate(comm, OBJECT_DOMAIN, dom));
        (*dom)->ndims = 0;
        CatFunctionReturn(CAT_SUCCESS);
}
