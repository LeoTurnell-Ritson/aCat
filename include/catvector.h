#pragma once

#include <catsys.h>

CAT_EXTERN CAT_RETURN_CODE VectorCreate(vector_p *);
CAT_EXTERN CAT_RETURN_CODE VectorDestroy(vector_p *);
CAT_EXTERN CAT_RETURN_CODE VectorSizeSet(int, vector_p);
CAT_EXTERN CAT_RETURN_CODE VectorSizeGet(vector_p, int *);

/* Scalar result operations */
CAT_EXTERN CAT_RETURN_CODE VectorMax(vector_p, scalar_t *); /* max(y) = alpha */
CAT_EXTERN CAT_RETURN_CODE VectorMin(vector_p, scalar_t *); /* min(y) = alpha */
CAT_EXTERN CAT_RETURN_CODE VectorSum(vector_p, scalar_t *); /* sum(y) = alpha */

/* Vector result pointwise operations */
CAT_EXTERN CAT_RETURN_CODE VectorPointwiseZero(vector_p); /* 0 = y[i] */
CAT_EXTERN CAT_RETURN_CODE VectorPointwiseUnity(vector_p); /* 1 = y[i] */
CAT_EXTERN CAT_RETURN_CODE VectorPointwiseSet(scalar_t, vector_p); /* alpha = y[i] */
CAT_EXTERN CAT_RETURN_CODE VectorPointwiseCpy(vector_p, vector_p); /* x[i] = y[i] */
CAT_EXTERN CAT_RETURN_CODE VectorPointwiseAbs(vector_p, vector_p); /* abs(x[i]) = y[i] */
CAT_EXTERN CAT_RETURN_CODE VectorPointwiseMax(vector_p, vector_p, vector_p); /* max(x[i], y[i]) = w[i] */
CAT_EXTERN CAT_RETURN_CODE VectorPointwiseMin(vector_p, vector_p, vector_p); /* min(x[i], y[i]) = w[i] */
CAT_EXTERN CAT_RETURN_CODE VectorPointwiseMult(vector_p, vector_p, vector_p); /* x[i] * y[i] = w[i] */
CAT_EXTERN CAT_RETURN_CODE VectorPointwiseDivide(vector_p, vector_p, vector_p); /* x[i] / y[i] = w[i] */
CAT_EXTERN CAT_RETURN_CODE VectorPointwiseAdd(vector_p, vector_p, vector_p); /* x[i] + y[i] = w[i] */
