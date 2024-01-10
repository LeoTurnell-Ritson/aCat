#include <catmath.h>
#include <cat/private/vectorimpl.h>

CAT_RETURN_CODE VectorMax(vector_p x, scalar_t *res)
{
        label_t i;
        scalar_t max;

        CatFunctionBegin;
        if (x->size == 0) {
                CatFunctionReturn(CAT_SUCCESS);
        }
        max = CAT_MIN;
        for (i = 0; i < x->size; i++) {
                max = CatMax(max, x->arr[i]);
        }
        *res = max;
        CatFunctionReturn(CAT_SUCCESS);
}

CAT_RETURN_CODE VectorMin(vector_p x, scalar_t *res)
{
        label_t i;
        scalar_t min;

        CatFunctionBegin;
        if (x->size == 0) {
                CatFunctionReturn(CAT_SUCCESS);
        }
        min = CAT_MAX;
        for (i = 0; i < x->size; i++) {
                min = CatMin(min, x->arr[i]);
        }
        *res = min;
        CatFunctionReturn(CAT_SUCCESS);
}

CAT_RETURN_CODE VectorSum(vector_p v, scalar_t *res)
{
        scalar_t sum;
        label_t i;

        CatFunctionBegin;
        CatCheck(v->size > 0, MPI_COMM_SELF, CAT_ERR_BAD_DIMENSIONS, "Can't find sum of a vector with length zero.\n ");
        sum = 0;
#pragma omp parallel for reduction(+:sum)
        for (i = 0; i < v->size; i++) {
                sum += v->arr[i];
        }
        *res = sum;
        CatFunctionReturn(CAT_SUCCESS);
}
