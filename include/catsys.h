#pragma once

#include <cattypes.h>
#include <catprims.h>
#include <catobjs.h>

#include <stdarg.h>
#include <stdio.h>
#include <errno.h>

#include <mpi.h>
#include <omp.h>

#define CAT_RETURN_CODE error_t

#define CAT_USING_DEBUG_FUNCTION_STACK 1

#define CAT_USING_DEBUG_MEMORY_TABLE 1

#define CAT_EXTERN extern

#define CAT_INLINE __inline

#define CAT_STDOUT stdout

#define CAT_STDERR stderr

#define CatNew(r)  CatMallocAlign(CAT_TRUE, __FILE__,  __FUNCTION__, __LINE__, (sizeof(**(r))), (void*)r)

#define CatCalloc(m, r) CatMallocAlign(CAT_TRUE, __FILE__,  __FUNCTION__, __LINE__, (size_t)(m), (void*)r)

#define CatFree(a) ((CAT_RETURN_CODE)(CatFreeAlign(__FILE__, __FUNCTION__, __LINE__, (void *)(a)) || ((a) = NULL, CAT_SUCCESS)))

#define CatUnlikely(cond) __builtin_expect(!!(cond), 0)

#define CatLikely(cond) __builtin_expect(!!(cond), 1)

#define CatFunctionBegin CatFunctionPush(__FILE__, __FUNCTION__, __LINE__)

#define CatFunctionReturn(...) CatFunctionPop(); return __VA_ARGS__

#define CatAssert(cond, comm, ...) {if (CatUnlikely(!(cond))) return CatError(comm, __FILE__, __FUNCTION__, __LINE__, "error", CAT_ERR_ASSERTION, __VA_ARGS__);}

#define CatCheck(cond, comm, err, ...) {if (CatUnlikely(!(cond))) return CatError(comm, __FILE__, __FUNCTION__, __LINE__, "error", err, __VA_ARGS__);}

#define CatWarning(comm, err, ...) {CatWarnNoReturn(comm, __FILE__, __FUNCTION__, __LINE__, "warning", err, __VA_ARGS__);}

#define CatFunction(...) {CatFunctionUpdateLine(__FUNCTION__, __LINE__); CAT_RETURN_CODE err = __VA_ARGS__; if (CatUnlikely(err)) return CatError(MPI_COMM_SELF, __FILE__, __FUNCTION__, __LINE__, "error", err, " ");}

#define CatCheckNoReturn(cond, comm, err, ...) {if (CatUnlikely(!(cond))) CatErrorNoReturn(comm, __FILE__, __FUNCTION__, __LINE__, "error",err, __VA_ARGS__);}

#define CatMPIFunction(err) {CatFunctionUpdateLine(__FUNCTION__, __LINE__); if (CatUnlikely(err != MPI_SUCCESS)) return CatMPIError(err);}

CAT_EXTERN CAT_RETURN_CODE CatInitialize(int *, char ***);
CAT_EXTERN CAT_RETURN_CODE CatFinalize(void);
CAT_EXTERN CAT_RETURN_CODE CatGetOptions(table_p *);

CAT_EXTERN CAT_RETURN_CODE CatMallocAlign(bool_t, const char *, const char *, const int, const size_t, void **);
CAT_EXTERN CAT_RETURN_CODE CatFreeAlign(const char *, const char *, const int, void *);
CAT_EXTERN CAT_RETURN_CODE CatError(MPI_Comm, const char *, const char *, const int, const char *, const CAT_RETURN_CODE, const char *, ...);

CAT_EXTERN CAT_RETURN_CODE CatMPIError(const int);

CAT_EXTERN CAT_RETURN_CODE CatMeowf(MPI_Comm, const char *, ...);
CAT_EXTERN CAT_RETURN_CODE CatFMeowf(MPI_Comm, FILE *, const char *, ...);
CAT_EXTERN CAT_RETURN_CODE CatVFMeowf(MPI_Comm, FILE *, const char *, va_list);
CAT_EXTERN CAT_RETURN_CODE CatSNMeowf(char *, size_t, const char *, ...);
CAT_EXTERN CAT_RETURN_CODE CatVSNMeowf(char *, size_t, const char *, va_list);

CAT_EXTERN void CatFunctionPush(const char *, const char *, const int);
CAT_EXTERN void CatFunctionPop(void);
CAT_EXTERN void CatFunctionUpdateLine(const char *, const int);
CAT_EXTERN void CatErrorNoReturn(MPI_Comm, const char *, const char *, const int, const char *, const CAT_RETURN_CODE, const char *, ...);
CAT_EXTERN void CatWarnNoReturn(MPI_Comm, const char *, const char *, const int, const char *, const CAT_RETURN_CODE, const char *, ...);
