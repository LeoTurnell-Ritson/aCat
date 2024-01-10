#include <cat/private/vectorimpl.h>

CAT_EXTERN CAT_RETURN_CODE VectorCreate(vector_p *vec)
{
        vector_p v;

        CatFunctionBegin;
        CatFunction(CatNew(&v));
        v->size = 0;
        *vec = NULL;
        *vec = v;
        CatFunctionReturn(CAT_SUCCESS);
}

CAT_EXTERN CAT_RETURN_CODE VectorDestroy(vector_p *vec)
{
        CatFunctionBegin;
        if (!(*vec))
                return CAT_ERR_INVALID_POINTER;
        if ((*vec)->size != 0)
                CatFunction(CatFree((*vec)->arr));
        CatFunction(CatFree(*vec));
        CatFunctionReturn(CAT_SUCCESS);
}

CAT_EXTERN CAT_RETURN_CODE VectorSizeSet(label_t size, vector_p vec)
{
        CatFunctionBegin;
        CatCheck(vec->size == 0, MPI_COMM_WORLD, CAT_ERR_BAD_INITIALIZATION, "Can't reset seve of vector_p, try VectorSizeReset(...).\n");
        CatCheck(size != 0, MPI_COMM_WORLD, CAT_ERR_BAD_INITIALIZATION, "Setting vector_p to zero is disallowed, try VectoyDestroy(...).\n");
        vec->size = size;
        CatFunction(CatCalloc(size * sizeof (scalar_t), &vec->arr));
        CatFunctionReturn(CAT_SUCCESS);
}

CAT_EXTERN CAT_RETURN_CODE VectorSizeGet(vector_p vec, label_t *s)
{
        CatFunctionBegin;
        *s = vec->size;
        CatFunctionReturn(CAT_SUCCESS);
}
