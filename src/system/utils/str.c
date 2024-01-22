#include <catstring.h>

CAT_RETURN_CODE CatStrToArray(const char *s, char sp, int *argc, char ***args)
{
        size_t                         str_len;
        int     i, j, n, *lens = NULL, cnt = 0;
        bool                 flg = CAT_FALSE;

        CatFunctionBegin;
        if (!s) {
                n = 0;
        } else {
                CatFunction(CatStrlen(s, &str_len));
                n = (int)str_len;
        }
        *argc = 0;
        *args = NULL;
        for (; n > 0; n--) {
                if (s[n - 1] != sp) break;
        }
        if (n == 0) CatFunctionReturn(CAT_SUCCESS);
        for (i = 0; i < n; i++) {
                if (s[i] != sp) break;
        }
        for (; i < n + 1; i++) {
                if ((s[i] == sp || s[i] == 0) && !flg) {
                        flg = CAT_TRUE;
                        (*argc)++;
                } else if (s[i] != sp) {
                        flg = CAT_FALSE;
                }
        }
        CatFunction(CatCalloc(((*argc) + 1) * sizeof(char *), args));
        CatFunction(CatCalloc((*argc) * sizeof(int), &lens));
        for (i = 0; i < *argc; i++) lens[i] = 0;
        *argc = 0;
        for (i = 0; i < n; i++) {
                if (s[i] != sp) break;
        }
        for (; i < n + 1; i++) {
                if ((s[i] == sp || s[i] == 0) && !flg) {
                        flg = CAT_TRUE;
                        (*argc)++;
                } else if (s[i] != sp) {
                        lens[*argc]++;
                        flg = CAT_FALSE;
                }
        }
        for (i = 0; i < *argc; i++) {
                CatFunction(CatCalloc((lens[i] + 1) * sizeof(char), &((*args)[i])));
                if (!(*args)[i]) {
                        CatFunction(CatFree(lens));
                        for (j = 0; j < i; j++) CatFunction(CatFree((*args)[j]));
                        CatFunction(CatFree(*args));
                }
        }
        CatFunction(CatFree(lens));
        (*args)[*argc] = NULL;
        *argc = 0;
        for (i = 0; i < n; i++) {
                if (s[i] != sp) break;
        }
        for (; i < n + 1; i++) {
                if ((s[i] == sp || s[i] == 0) && !flg) {
                        flg = CAT_TRUE;
                        (*args)[*argc][cnt++] = 0;
                        (*argc)++;
                        cnt = 0;
                } else if (s[i] != sp && s[i] != 0) {
                        (*args)[*argc][cnt++] = s[i];
                        flg = CAT_FALSE;
                }
        }
        CatFunctionReturn(CAT_SUCCESS);
}

CAT_RETURN_CODE CatStrArrayDestroy(char ***arr)
{
        int n = 0;

        CatFunctionBegin;
        if (!*arr) CatFunctionReturn(CAT_SUCCESS);
        while ((*arr)[n]) {
                CatFunction(CatFree((*arr)[n]));
                n++;
        }
        CatFunction(CatFree(*arr));
        CatFunctionReturn(CAT_SUCCESS);
}
