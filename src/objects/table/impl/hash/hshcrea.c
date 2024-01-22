#include <../src/objects/table/impl/hash/hsh.h>

CAT_EXTERN CAT_RETURN_CODE __TableHashCreate(TABLE *tab)
{
        struct __hash *hsh;
        MPI_Comm       comm;

        CatFunctionBegin;
        CatFunction(__HeaderGetComm(tab, &comm));
        CatCheck(tab->size > 0, comm, CAT_ERR_BAD_INITIALIZATION, "table size must greater that %d for hash table internal creation", tab->size);
        CatFunction(CatNew(&hsh));
        CatFunction(CatCalloc(tab->size * sizeof (struct __node *), &(hsh->items)));
        tab->data = (void *)hsh;
        tab->ops->create = NULL;
        CatFunctionReturn(CAT_SUCCESS);
}
