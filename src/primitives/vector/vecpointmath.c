#include <catmath.h>
#include <cat/private/vectorimpl.h>

CAT_RETURN_CODE VectorPointwiseZero(vector_p v)
{
        CatFunctionBegin;
        CatFunction(VectorPointwiseSet((scalar_t)0.f, v));
        CatFunctionReturn(CAT_SUCCESS);
}

CAT_RETURN_CODE VectorPointwiseUnity(vector_p v)
{
        CatFunctionBegin;
        CatFunction(VectorPointwiseSet((scalar_t)1.f, v));
        CatFunctionReturn(CAT_SUCCESS);
}

CAT_RETURN_CODE VectorPointwiseSet(scalar_t alpha, vector_p v)
{
        int i;

        CatFunctionBegin;
        if (v->size == 0) {
                CatFunctionReturn(CAT_SUCCESS);
        }
#pragma omp parallel for
        for (i = 0; i < v->size; i++) {
                v->arr[i] = alpha;
        }
        CatFunctionReturn(CAT_SUCCESS);
}

CAT_RETURN_CODE VectorPointwiseCpy(vector_p a, vector_p b)
{
        int i;
        bool same;

        CatFunctionBegin;
        CatFunction(__VectorSizeCompare(a, b, &same));
        CatCheck(same, MPI_COMM_SELF, CAT_ERR_BAD_DIMENSIONS, "Vector sizes are different.\n ");
        if (a->size == 0) {
                CatFunctionReturn(CAT_SUCCESS);
        }
#pragma omp parallel for
        for (i = 0; i < b->size; i++) {
                b->arr[i] = a->arr[i];
        }
        CatFunctionReturn(CAT_SUCCESS);
}

CAT_RETURN_CODE VectorPointwiseAbs(vector_p x, vector_p y)
{
        int i;
        bool same;

        CatFunctionBegin;
        CatFunction(__VectorSizeCompare(x, y, &same));
        CatCheck(same, MPI_COMM_SELF, CAT_ERR_BAD_DIMENSIONS, "Vector sizes are different.\n ");
        if (x->size == 0) {
                CatFunctionReturn(CAT_SUCCESS);
        }
#pragma omp parallel for
        for (i = 0; i < x->size; i++) {
                y->arr[i] = CatAbs(x->arr[i]);
        }
        CatFunctionReturn(CAT_SUCCESS);
}

CAT_EXTERN CAT_RETURN_CODE VectorPointwiseMult(vector_p x, vector_p y, vector_p w)
{
        int i;
        bool s1, s2;

        CatFunctionBegin;
        CatFunction(__VectorSizeCompare(x, y, &s1));
        CatFunction(__VectorSizeCompare(x, w, &s2));
        CatCheck(s1 && s2, MPI_COMM_SELF, CAT_ERR_BAD_DIMENSIONS, "Vector sizes are different.\n ");
        if (x->size == 0) {
                CatFunctionReturn(CAT_SUCCESS);
        }
#pragma omp parallel for
        for (i = 0; i < x->size; i++) {
                w->arr[i] = x->arr[i] * y->arr[i];
        }
        CatFunctionReturn(CAT_SUCCESS);
}

CAT_EXTERN CAT_RETURN_CODE VectorPointwiseDivide(vector_p x, vector_p y, vector_p w)
{
        int i;
        bool s1, s2;

        CatFunctionBegin;
        CatFunction(__VectorSizeCompare(x, y, &s1));
        CatFunction(__VectorSizeCompare(x, w, &s2));
        CatCheck(s1 && s2, MPI_COMM_SELF, CAT_ERR_BAD_DIMENSIONS, "Vector sizes are different.\n ");
        if (x->size == 0) {
                CatFunctionReturn(CAT_SUCCESS);
        }
#pragma omp parallel for
        for (i = 0; i < x->size; i++) {
                w->arr[i] = x->arr[i] / y->arr[i];
        }
        CatFunctionReturn(CAT_SUCCESS);
}

CAT_EXTERN CAT_RETURN_CODE VectorPointwiseAdd(vector_p x, vector_p y, vector_p w)
{
        int i;
        bool s1, s2;

        CatFunctionBegin;
        CatFunction(__VectorSizeCompare(x, y, &s1));
        CatFunction(__VectorSizeCompare(x, w, &s2));
        CatCheck(s1 && s2, MPI_COMM_SELF, CAT_ERR_BAD_DIMENSIONS, "Vector sizes are different.\n ");
        if (x->size == 0) {
                CatFunctionReturn(CAT_SUCCESS);
        }
#pragma omp parallel for
        for (i = 0; i < x->size; i++) {
                w->arr[i] = x->arr[i] + y->arr[i];
        }
        CatFunctionReturn(CAT_SUCCESS);
}
