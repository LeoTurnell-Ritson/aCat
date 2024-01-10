#include <cattable.h>
#include <catstring.h>
#include <cat/private/catimpl.h>

static table_p __CatDefaultOptions;

static CAT_RETURN_CODE __ParseArgs(int *argc, char ***argv)
{
        label_t    i, j, k;
        label_t   sub_argc;
        bool_t       match;
        size_t         len;
        char          *key;
        char    **sub_argv;

        CatFunctionBegin;
        for (i = 0; i < (label_t)(*argc); i++) {
                key = (*argv)[i];
                CatFunction(CatStrncmp(key, "--", 2, &match));
                if (match) {
                        for (j = i + 1; j < (label_t)(*argc); j++) {
                                key = (*argv)[j];
                                CatFunction(CatStrncmp(key, "--", 2, &match));
                                if (match) {
                                        break;
                                }
                        }
                        sub_argc = (j - 1) - i;
                        CatFunction(CatCalloc((sub_argc + 1) * sizeof (char *), &sub_argv));
                        for (k = 0; k < sub_argc; k++) {
                                CatFunction(CatStrlen((*argv)[i + k + 1], &len));
                                CatFunction(CatCalloc((len + 1) * sizeof (char), &(sub_argv[k])));
                                CatFunction(CatStrcpy(sub_argv[k], (*argv)[i + k + 1]));
                        }
                        sub_argv[sub_argc] = NULL;
                        key = (*argv)[i];
                        CatFunction(TablePush(key, sub_argc, sub_argv, __CatDefaultOptions));
                        for (k = 0; k < sub_argc; k++) {
                                CatFunction(CatFree(sub_argv[k]));
                        }
                        CatFunction(CatFree(sub_argv));
                }
        }
        CatFunctionReturn(CAT_SUCCESS);
}


CAT_RETURN_CODE CatInitialize(int *argc, char ***argv)
{
        CatFunctionBegin;
        CatMPIFunction(MPI_Init(argc, argv));
        CatFunction(TableCreate(MPI_COMM_SELF, &__CatDefaultOptions));
        CatFunction(TableSizeSet(*argc * 2, __CatDefaultOptions));
        CatFunction(TableTypeSet(TABLE_HASH, __CatDefaultOptions));
        CatFunction(__ParseArgs(argc, argv));
        CatFunctionReturn(CAT_SUCCESS);
}

CAT_RETURN_CODE CatFinalize()
{
        CatFunctionBegin;
        CatFunction(TableDestroy(&__CatDefaultOptions));
#if CAT_USING_DEBUG_MEMORY_TABLE
        __MemoryCheck();
#endif
        CatMPIFunction(MPI_Finalize());
        CatFunctionReturn(CAT_SUCCESS);
}

CAT_RETURN_CODE CatGetOptions(table_p *args)
{
        CatFunctionBegin;
        *args = __CatDefaultOptions;
        CatFunctionReturn(CAT_SUCCESS);
}

CAT_RETURN_CODE CatAddOptions(const char *add)
{
        int     argc;
        char  **argv;

        CatFunctionBegin;
        CatFunction(CatStrToArray(add, ' ', &argc, &argv));
        CatFunction(__ParseArgs(&argc, &argv));
        CatFunction(CatStrArrayDestroy(&argv));
        CatFunctionReturn(CAT_SUCCESS);
}
