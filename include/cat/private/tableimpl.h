#pragma once

#include <cattable.h>
#include <cat/private/catimpl.h>

struct __tabops {
        CAT_RETURN_CODE (*create)(table_p);
        CAT_RETURN_CODE (*destroy)(table_p);
        CAT_RETURN_CODE (*pop)(table_p, char *);
        CAT_RETURN_CODE (*push)(table_p, char *, label_t, char **);
        CAT_RETURN_CODE (*search)(table_p, const char *, bool_t *);
        CAT_RETURN_CODE (*lookup)(table_p, const char *, label_t *, char ***, bool_t *);
};

struct __table {
        __Header(struct __tabops);
        label_t size;
        void *data;
};

CAT_EXTERN CAT_RETURN_CODE __TableBuildInternal(table_p);
CAT_EXTERN CAT_RETURN_CODE __TableBuildInternalHash(table_p);
