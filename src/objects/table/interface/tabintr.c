#include <cat/private/tableimpl.h>

CAT_RETURN_CODE TableTypeSet(char *type, table_p tab)
{
        CatFunctionBegin;
        CatFunction(__HeaderSetType(type, tab));
        CatFunction(__TableBuildInternal(tab));
        CatFunctionReturn(CAT_SUCCESS);
}

CAT_RETURN_CODE TableSizeSet(label_t size, table_p tab)
{
        MPI_Comm comm;

        CatFunctionBegin;
        CatFunction(__HeaderGetComm(tab, &comm));
        CatCheck(tab->size == 0, comm, CAT_ERR_BAD_INITIALIZATION, "re-setting table size disallowed, try TableSizeReset");
        CatCheck(size > 0, comm, CAT_ERR_BAD_DIMENSIONS, "setting table size to %d disallowed, try TableDestroy", size);
        tab->size = size;
        CatFunctionReturn(CAT_SUCCESS);
}

CAT_RETURN_CODE TablePush(char *key, label_t argc, char **argv, table_p tab)
{
        CatFunctionBegin;
        __HeaderUseTypeMethod(tab, push, key, argc, argv);
        CatFunctionReturn(CAT_SUCCESS);
}

CAT_RETURN_CODE TableSearch(table_p tab, const char *key, bool_t *in)
{
        MPI_Comm comm;

        CatFunctionBegin;
        __HeaderUseTypeMethod(tab, search, key, in);
        CatFunction(__HeaderGetComm(tab, &comm));
        if (!(*in)) CatWarning(comm, CAT_ERR_BAD_LOOKUP,"%s not found", key);
        CatFunctionReturn(CAT_SUCCESS);
}

CAT_RETURN_CODE TableLookup(table_p tab, const char *key, label_t *argc, char ***argv, bool_t *in)
{
        MPI_Comm comm;

        CatFunctionBegin;
        __HeaderUseTypeMethod(tab, lookup, key, argc, argv, in);
        CatFunction(__HeaderGetComm(tab, &comm));
        if (!(*in)) {
                CatWarning(comm, CAT_ERR_BAD_LOOKUP,"%s not found", key);
        }
        CatFunctionReturn(CAT_SUCCESS);
}
