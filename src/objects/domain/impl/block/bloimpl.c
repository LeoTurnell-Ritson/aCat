#include <catstring.h>
#include <cattable.h>
#include <../src/objects/domain/impl/block/blo.h>

static CAT_INLINE CAT_RETURN_CODE __SetLabelFromOptions(TABLE *options, const char *key, int *arg)
{
        int    key_argc;
        bool        found;
        char     **key_argv;
        MPI_Comm       comm;

        CatFunctionBegin;
        CatFunction(__HeaderGetComm(options, &comm));
        CatFunction(TableLookup(options, key, &key_argc, &key_argv, &found));
        if (found) {
                CatCheck(key_argc > 0, comm, CAT_ERR_BAD_INITIALIZATION, "%s requires a value", key);
                CatFunction(CatStrtolabel(key_argv[0], arg));
        }
        CatFunctionReturn(CAT_SUCCESS);
}

CAT_RETURN_CODE __DomainBlockDestroy(DOMAIN *dom)
{
        CatFunctionBegin;
        CatFunction(CatFree(dom->data));
        CatFunctionReturn(CAT_SUCCESS);
}

CAT_RETURN_CODE __DomainBlockSetFromOptions(DOMAIN *dom)
{
        TABLE *    options;
        int    key_argc;
        bool        found;
        char     **key_argv;
        MPI_Comm       comm;
        struct __block *blo;

        CatFunctionBegin;
        CatFunction(__HeaderGetComm(dom, &comm));
        CatFunction(CatGetOptions(&options));
        blo = (struct __block *)dom->data;
        CatFunction(TableLookup(options, "--dom_file", &key_argc, &key_argv, &found));
        if (found) {
                CAT_NOT_IMPLEMENTED;
        } else {
                CatCheck(dom->ndims > 0, comm, CAT_ERR_BAD_INITIALIZATION, "--dom_dim (n) required");
                if (dom->ndims > 0) {
                        CatFunction(__SetLabelFromOptions(options, "--dom_grid_x", &(blo->world_grid[0])));
                        CatFunction(__SetLabelFromOptions(options, "--dom_processors_x", &(blo->world_processors[0])));
                }
                if (dom->ndims > 1) {
                        CatFunction(__SetLabelFromOptions(options, "--dom_grid_y", &(blo->world_grid[1])));
                        CatFunction(__SetLabelFromOptions(options, "--dom_processors_y", &(blo->world_processors[1])));
                }
                if (dom->ndims == 3) {
                        CatFunction(__SetLabelFromOptions(options, "--dom_grid_z", &(blo->world_grid[2])));
                        CatFunction(__SetLabelFromOptions(options, "--dom_processors_z", &(blo->world_processors[3])));
                }
        }
        CatFunction(__DomainBlockCheckOptions(dom));
        CatFunction(__DomainBlockDecompose(dom));
        CatFunctionReturn(CAT_SUCCESS);
}
