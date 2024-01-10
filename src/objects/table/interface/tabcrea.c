#include <cat/private/tableimpl.h>

CAT_EXTERN CAT_RETURN_CODE TableCreate(MPI_Comm comm, table_p *tab)
{
        CatFunctionBegin;
        CatFunction(__HeaderCreate(comm, OBJECT_TABLE, tab));
        CatFunctionReturn(CAT_SUCCESS);
}
