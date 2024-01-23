#pragma once

#include <catsys.h>

struct __object {
        MPI_Comm comm;
        int  id;
        char    *class;
        char    *type;
        char    *name;
};


#define CAT_NOT_IMPLEMENTED CatCheck(CAT_FALSE, MPI_COMM_WORLD, CAT_ERR_NOT_IMPLEMENTED, " ")

#define CAT_HEADER struct __object hdr

#define Header(opers) CAT_HEADER; opers ops[1];

#define HeaderSetOps(obj, opers) (obj)->ops[0] = opers

#define HeaderSetClass(h, class) ObjectSetClass((object_p)(h), (class))

#define HeaderSetType(type, h) ObjectSetType((type), (object_p)(h))

#define HeaderGetType(h, type) ObjectGetType((object_p)(h), (type))

#define HeaderGetComm(h, comm) ObjectGetComm((object_p)(h), (comm));

#define HeaderCreate(comm, class, h)                                  \
        ObjectCreate(CatNew(h), (comm), (class), (object_p *)(h))

#define HeaderDestroy(h)                                              \
        ((CAT_RETURN_CODE)(ObjectDestroy((object_p *)(h))             \
                           || CatFree(*h)))

#define HeaderCompareId(h, id, match)                                 \
        ObjectCompareId((object_p)(h), (id), (match))

#define HeaderCompareClass(h, class, match)                           \
        ObjectCompareClass((object_p)(h), (class), (match))

#define HeaderCompareType(h, type, match)                             \
        ObjectCompareType((object_p)(h), (type), (match))

#define HeaderTryTypeMethod(obj, ...)  ``                               \
        {                                                               \
                if ((obj)->ops->CAT_FIRST_ARG((__VA_ARGS__, unused))    \
                    != NULL)                                            \
                {                                                       \
                        CAT_RETURN_CODE ierr__;                         \
                        ierr__ =                                        \
                                (*(obj)->ops->CAT_FIRST_ARG(            \
                                        (__VA_ARGS__, unused)))         \
                                (obj CAT_REST_ARG(__VA_ARGS__));        \
                        CatFunction(ierr__);                            \
                }  else {                                               \
                        CatWarning(MPI_COMM_SELF,                       \
                                   CAT_ERR_OPERATION_NOT_SET, " ");     \
                }                                                       \
        }

#define HeaderUseTypeMethod(obj, ...)``                                 \
        {                                                               \
                if ((obj)->ops->CAT_FIRST_ARG((__VA_ARGS__, unused))    \
                    != NULL)                                            \
                {                                                       \
                        CAT_RETURN_CODE ierr__;                         \
                        ierr__ = (*(obj)->ops->CAT_FIRST_ARG(           \
                                          (__VA_ARGS__, unused)))       \
                                (obj CAT_REST_ARG(__VA_ARGS__));        \
                        CatFunction(ierr__);                            \
                }                                                       \
                else                                                    \
                {                                                       \
                        CatCheck(CAT_FALSE, MPI_COMM_SELF,              \
                                 CAT_ERR_OPERATION_NOT_SET,             \
                                 " " );                                 \
                }                                                       \
        }

#define CAT_FIRST_ARG_HELPER(N, ...) N

#define CAT_FIRST_ARG(args) CAT_FIRST_ARG_HELPER args

#define CAT_SELECT_16TH(a1, a2, a3, a4, a5, a6, a7, a8, a9, a10,        \
                        a11, a12, a13, a14, a15, a16, ...) a16

#define CAT_NUM(...)                                                    \
        CAT_SELECT_16TH(__VA_ARGS__, TWOORMORE, TWOORMORE, TWOORMORE,   \
                        TWOORMORE, TWOORMORE, TWOORMORE, TWOORMORE,     \
                        TWOORMORE, TWOORMORE, TWOORMORE, TWOORMORE,     \
                        TWOORMORE, TWOORMORE, TWOORMORE, ONE,           \
                        throwaway)

#define CAT_REST_HELPER_TWOORMORE(first, ...) , __VA_ARGS__

#define CAT_REST_HELPER_ONE(first)

#define CAT_REST_HELPER2(qty, ...) CAT_REST_HELPER_##qty(__VA_ARGS__)

#define CAT_REST_HELPER(qty, ...) CAT_REST_HELPER2(qty, __VA_ARGS__)

#define CAT_REST_ARG(...) CAT_REST_HELPER(CAT_NUM(__VA_ARGS__), __VA_ARGS__)

CAT_EXTERN CAT_RETURN_CODE ObjectCreate(CAT_RETURN_CODE, MPI_Comm, char *, object_p *);
CAT_EXTERN CAT_RETURN_CODE ObjectDestroy(object_p *);
CAT_EXTERN CAT_RETURN_CODE ObjectCompareId(object_p, int, bool *);
CAT_EXTERN CAT_RETURN_CODE ObjectCompareClass(object_p, char *, bool *);
CAT_EXTERN CAT_RETURN_CODE ObjectCompareType(object_p, char *, bool *);
CAT_EXTERN CAT_RETURN_CODE ObjectSetClass(object_p, char *);
CAT_EXTERN CAT_RETURN_CODE ObjectSetType(char *, object_p);
CAT_EXTERN CAT_RETURN_CODE ObjectGetType(object_p, char **);
CAT_EXTERN CAT_RETURN_CODE ObjectGetComm(object_p , MPI_Comm *);

CAT_EXTERN void CatErrorMeowf(MPI_Comm, const char *, const char *, const int , const char *, const CAT_RETURN_CODE, const char *, ...);
CAT_EXTERN void CatErrorVMeowf(MPI_Comm, const char *, const char *, const int , const char *, const CAT_RETURN_CODE, const char *, va_list);
CAT_EXTERN void MemoryPush(const char *, const char *, const int, const char *);
CAT_EXTERN void MemoryPop(const char *);
CAT_EXTERN void MemoryCheck(void);
CAT_EXTERN void FunctionStackPush(const char *, const char *, const int);
CAT_EXTERN void FunctionStackPop(void);
CAT_EXTERN void FunctionStackUpdateLine(const char *, const int);
CAT_EXTERN void FunctionStackCheck(void);
