#pragma once

#include <catsys.h>

struct __object {
        MPI_Comm comm;
        int  id;
        char    *class;
        char    *type;
        char    *name;
};

#define OBJECT_DOMAIN "domain"

#define OBJECT_TABLE "table"

#define __CAT_NOT_IMPLEMENTED CatCheck(CAT_FALSE, MPI_COMM_WORLD, CAT_ERR_NOT_IMPLEMENTED, " ")

#define __HEADER struct __object hdr

#define __Header(opers) __HEADER; opers ops[1];

#define __HeaderSetOps(obj, opers) (obj)->ops[0] = opers

#define __HeaderSetClass(h, class) __ObjectSetClass((object_p)(h), (class))

#define __HeaderSetType(type, h) __ObjectSetType((type), (object_p)(h))

#define __HeaderGetType(h, type) __ObjectGetType((object_p)(h), (type))

#define __HeaderGetComm(h, comm) __ObjectGetComm((object_p)(h), (comm));

#define __HeaderCreate(comm, class, h)                                  \
        __ObjectCreate(CatNew(h), (comm), (class), (object_p *)(h))

#define __HeaderDestroy(h)                                              \
        ((CAT_RETURN_CODE)(__ObjectDestroy((object_p *)(h))             \
                           || CatFree(*h)))

#define __HeaderCompareId(h, id, match)                                 \
        __ObjectCompareId((object_p)(h), (id), (match))

#define __HeaderCompareClass(h, class, match)                           \
        __ObjectCompareClass((object_p)(h), (class), (match))

#define __HeaderCompareType(h, type, match)                             \
        __ObjectCompareType((object_p)(h), (type), (match))

#define __HeaderTryTypeMethod(obj, ...)                                 \
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

#define __HeaderUseTypeMethod(obj, ...)                                 \
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

CAT_EXTERN CAT_RETURN_CODE __ObjectCreate(CAT_RETURN_CODE, MPI_Comm, char *, object_p *);
CAT_EXTERN CAT_RETURN_CODE __ObjectDestroy(object_p *);
CAT_EXTERN CAT_RETURN_CODE __ObjectCompareId(object_p, int, bool *);
CAT_EXTERN CAT_RETURN_CODE __ObjectCompareClass(object_p, char *, bool *);
CAT_EXTERN CAT_RETURN_CODE __ObjectCompareType(object_p, char *, bool *);
CAT_EXTERN CAT_RETURN_CODE __ObjectSetClass(object_p, char *);
CAT_EXTERN CAT_RETURN_CODE __ObjectSetType(char *, object_p);
CAT_EXTERN CAT_RETURN_CODE __ObjectGetType(object_p, char **);
CAT_EXTERN CAT_RETURN_CODE __ObjectGetComm(object_p , MPI_Comm *);

CAT_EXTERN void __CatErrorMeowf(MPI_Comm, const char *, const char *, const int , const char *, const CAT_RETURN_CODE, const char *, ...);
CAT_EXTERN void __CatErrorVMeowf(MPI_Comm, const char *, const char *, const int , const char *, const CAT_RETURN_CODE, const char *, va_list);
CAT_EXTERN void __MemoryPush(const char *, const char *, const int, const char *);
CAT_EXTERN void __MemoryPop(const char *);
CAT_EXTERN void __MemoryCheck(void);
CAT_EXTERN void __FunctionStackPush(const char *, const char *, const int);
CAT_EXTERN void __FunctionStackPop(void);
CAT_EXTERN void __FunctionStackUpdateLine(const char *, const int);
CAT_EXTERN void __FunctionStackCheck(void);
