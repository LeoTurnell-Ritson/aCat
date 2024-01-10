#include <catstring.h>
#include <cat/private/catimpl.h>

static label_t nid;

CAT_RETURN_CODE __ObjectCreate(CAT_RETURN_CODE nerr, MPI_Comm comm, char *class, object_p *obj)
{
        size_t len;

        CatFunctionBegin;
        if (nerr) return nerr;
        if (!(*obj)) return CAT_ERR_INVALID_POINTER;
        (*obj)->comm = comm;
        (*obj)->id = nid++;
        CatFunction(CatStrlen(class, &len));
        CatFunction(CatCalloc((len + 1) * sizeof (char), &((*obj)->class)));
        CatFunction(CatStrcpy((*obj)->class, class));
        CatFunctionReturn(CAT_SUCCESS);
}
