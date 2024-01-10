#include <catstring.h>
#include <cat/private/domainimpl.h>

CAT_RETURN_CODE __ObjectSetType(char *type, object_p obj)
{
        size_t len;

        CatFunctionBegin;
        CatFunction(CatStrlen(type, &len));
        CatFunction(CatCalloc((len + 1) * sizeof (char), &(obj->type)));
        CatFunction(CatStrcpy(obj->type, type));
        CatFunctionReturn(CAT_SUCCESS);
}

CAT_RETURN_CODE __ObjectGetType(object_p obj, char **type)
{
        CatFunctionBegin;
        *type = obj->type;
        CatFunctionReturn(CAT_SUCCESS);
}

CAT_RETURN_CODE __ObjectGetComm(object_p obj, MPI_Comm *comm)
{
        CatFunctionBegin;
        *comm = obj->comm;
        CatFunctionReturn(CAT_SUCCESS);
}
