#include <catstring.h>
#include <cattable.h>
#include <../src/objects/domain/impl/block/blo.h>

static CAT_INLINE CAT_RETURN_CODE __SetLimsFromOptions(table_p options, domain_p dom, MPI_Comm comm, const char *key, scalar_t *min, scalar_t *max)
{
        label_t    key_argc;
        bool_t        found;
        char     **key_argv;

        CatFunctionBegin;
        CatFunction(TableLookup(options, key, &key_argc, &key_argv, &found));
        CatCheck(found, comm, CAT_ERR_BAD_INITIALIZATION,
                 "limits, i.e. %s (min) (max), required for domain block with %d dimension(s)", key,  dom->ndims);
        CatCheck(key_argc == 2, comm, CAT_ERR_BAD_INITIALIZATION,
                 "%s expects two arguments, i.e. %s (min) (max)", key, key);
        CatFunction(CatStrtoscalar(key_argv[0], min));
        CatFunction(CatStrtoscalar(key_argv[1], max));
        CatFunctionReturn(CAT_SUCCESS);
}

static CAT_INLINE CAT_RETURN_CODE __SetSpacingFromOptions(table_p options, MPI_Comm comm, const char *key, scalar_t *spa)
{
        label_t    key_argc;
        bool_t        found;
        char     **key_argv;

        CatFunctionBegin;
        CatFunction(TableLookup(options, key, &key_argc, &key_argv, &found));
        CatCheck(found, comm, CAT_ERR_BAD_INITIALIZATION,
                 "spacing, i.e. %s (spacing), required for domain block", key);
        CatCheck(key_argc == 1, comm, CAT_ERR_BAD_INITIALIZATION,
                 "%s expects one argument, i.e. %s (spacing)", key, key);
        CatFunction(CatStrtoscalar(key_argv[0], spa));
        CatFunctionReturn(CAT_SUCCESS);
}

CAT_RETURN_CODE __DomainBlockDestroy(domain_p dom)
{
        CatFunctionBegin;
        CatFunction(CatFree(dom->data));
        CatFunctionReturn(CAT_SUCCESS);
}

CAT_RETURN_CODE __DomainBlockSetFromOptions(domain_p dom)
{
        table_p     options;
        label_t    key_argc;
        bool_t        found;
        char     **key_argv;
        MPI_Comm       comm;
        struct __block *blo;

        CatFunctionBegin;
        CatFunction(__HeaderGetComm(dom, &comm));
        CatFunction(CatGetOptions(&options));
        blo = (struct __block *)dom->data;
        CatFunction(TableLookup(options, "--dom_file", &key_argc, &key_argv, &found));
        if (found) {
                __CAT_NOT_IMPLEMENTED;
        } else {
                CatCheck(dom->ndims > 0, comm, CAT_ERR_BAD_INITIALIZATION, "--dom_dims not set in options");
                if (dom->ndims > 0) {
                        CatFunction(__SetLimsFromOptions(options, dom, comm, "--dom_block_xlim", &(blo->world_xlim[0]), &(blo->world_xlim[1])));
                }
                if (dom->ndims > 1) {
                        CatFunction(__SetLimsFromOptions(options, dom, comm, "--dom_block_ylim", &(blo->world_ylim[0]), &(blo->world_ylim[1])));
                }
                if (dom->ndims == 3) {
                        CatFunction(__SetLimsFromOptions(options, dom, comm, "--dom_block_zlim", &(blo->world_zlim[0]), &(blo->world_zlim[1])));
                }
                CatFunction(__SetSpacingFromOptions(options, comm, "--dom_block_spacing", &(blo->world_spacing)));
        }
        CatFunction(__DomainBlockPrivateDecompose(dom));
        CatFunctionReturn(CAT_SUCCESS);
}
