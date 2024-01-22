#include <catstring.h>
#include <cattable.h>
#include <cat/private/domainimpl.h>

CAT_RETURN_CODE DomainSetFromOptions(DOMAIN *dom)
{
        table_p    options;
        int   key_argc;
        bool       found;
        char    **key_argv;
        MPI_Comm      comm;

        CatFunctionBegin;
        CatFunction(__HeaderGetComm(dom, &comm));
        CatFunction(CatGetOptions(&options));
        CatFunction(TableLookup(options, "--dom_file", &key_argc, &key_argv, &found));
        if (found) {
                __CAT_NOT_IMPLEMENTED;
                __HeaderUseTypeMethod(dom, setfromoptions);
        } else {
                int ndims;

                CatFunction(TableLookup(options, "--dom_type", &key_argc, &key_argv, &found));
                CatCheck(found && key_argc > 0, comm, CAT_ERR_BAD_INITIALIZATION, "--dom_type not set in options");
                CatFunction(DomainSetType(key_argv[0], dom));
                CatFunction(TableLookup(options, "--dom_dim", &key_argc, &key_argv, &found));
                if (found && key_argc > 0){
                        CatFunction(CatStrtolabel(key_argv[0], &ndims));
                        CatFunction(DomainSetDimensions(ndims, dom));
                }
                __HeaderUseTypeMethod(dom, setfromoptions);
        }
        CatFunctionReturn(CAT_SUCCESS);
}

CAT_RETURN_CODE DomainSetType(char *type, DOMAIN *dom)
{
        CatFunctionBegin;
        CatFunction(__HeaderSetType(type, dom));
        CatFunction(__DomainBuildInternal(dom));
        CatFunctionReturn(CAT_SUCCESS);
}

CAT_RETURN_CODE DomainGetType(DOMAIN *dom, char **type)
{
        CatFunctionBegin;
        CatFunction(__HeaderGetType(dom, type));
        CatFunctionReturn(CAT_SUCCESS);
}

CAT_RETURN_CODE DomainSetDimensions(int ndims, DOMAIN *dom)
{
        MPI_Comm comm;

        CatFunctionBegin;
        CatFunction(__HeaderGetComm(dom, &comm));
        CatCheck(dom->ndims == 0, comm, CAT_ERR_BAD_INITIALIZATION, "domain dimensions have already been set");
        CatCheck(0 < ndims && ndims <= 3, comm, CAT_ERR_BAD_DIMENSIONS, "domain dimensions must be between 1 and 3, not %d", ndims);
        dom->ndims = ndims;
        CatFunctionReturn(CAT_SUCCESS);
}
