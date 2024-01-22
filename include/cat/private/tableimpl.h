#pragma once

#include <cattable.h>
#include <cat/private/catimpl.h>

struct __tabops {
        CAT_RETURN_CODE (*create)(TABLE *);
        CAT_RETURN_CODE (*destroy)(TABLE *);
        CAT_RETURN_CODE (*pop)(TABLE *, char *);
        CAT_RETURN_CODE (*push)(TABLE *, char *, int, char **);
        CAT_RETURN_CODE (*search)(TABLE *, const char *, bool *);
        CAT_RETURN_CODE (*lookup)(TABLE *, const char *, int *, char ***, bool *);
};

struct __table {
        __Header(struct __tabops);
        int size;
        void *data;
};

CAT_EXTERN CAT_RETURN_CODE __TableBuildInternal(TABLE *);
CAT_EXTERN CAT_RETURN_CODE __TableBuildInternalHash(TABLE *);
