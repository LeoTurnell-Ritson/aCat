#pragma once

#include <catsys.h>
#include <stdlib.h>
#include <string.h>

CAT_EXTERN CAT_RETURN_CODE CatStrToArray(const char *s, char sp, int *argc, char ***args);
CAT_EXTERN CAT_RETURN_CODE CatStrArrayDestroy(char ***arr);


static CAT_INLINE CAT_RETURN_CODE CatStrncmp(const char a[], const char b[], size_t n, bool *t)
{
        CatFunctionBegin;
        if (!a) return CAT_ERR_INVALID_POINTER;
        if (!b) return CAT_ERR_INVALID_POINTER;
        *t = CAT_TRUE;
        *t = strncmp(a, b, n) ? CAT_FALSE : CAT_TRUE;
        CatFunctionReturn(CAT_SUCCESS);
}

static CAT_INLINE CAT_RETURN_CODE CatStrcmp(const char a[], const char b[], bool *t)
{
        CatFunctionBegin;
        if (!a) return CAT_ERR_INVALID_POINTER;
        if (!b) return CAT_ERR_INVALID_POINTER;
        *t = CAT_TRUE;
        *t = strcmp(a, b) ? CAT_FALSE : CAT_TRUE;
        CatFunctionReturn(CAT_SUCCESS);
}

static CAT_INLINE CAT_RETURN_CODE CatStrcpy(char a[], const char b[])
{
        CatFunctionBegin;
        if (!a) return CAT_ERR_INVALID_POINTER;
        if (!b) return CAT_ERR_INVALID_POINTER;
        strcpy(a, b);
        CatFunctionReturn(CAT_SUCCESS);
}

static CAT_INLINE CAT_RETURN_CODE CatStrlen(const char a[], size_t *l)
{
        CatFunctionBegin;
        if (!a) return CAT_ERR_INVALID_POINTER;
        *l = strlen(a);
        CatFunctionReturn(CAT_SUCCESS);
}

static CAT_INLINE CAT_RETURN_CODE CatStrtoi(const char a[], int *l)
{
        CatFunctionBegin;
        if (!a) return CAT_ERR_INVALID_POINTER;
        *l = (int)atoi(a);
        CatFunctionReturn(CAT_SUCCESS);
}

static CAT_INLINE CAT_RETURN_CODE CatStrtod(const char a[], double *f)
{
        CatFunctionBegin;
        if (!a) return CAT_ERR_INVALID_POINTER;
        *f = (double)atod(a);
        CatFunctionReturn(CAT_SUCCESS);
}
