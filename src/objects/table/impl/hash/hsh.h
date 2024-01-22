#pragma once

#include <cat/private/tableimpl.h>

struct __node {
        char            *key;
        int         argc;
        char          **argv;
        struct __node  *next;
};

struct __hash {
        struct __node **items;
};

CAT_EXTERN CAT_RETURN_CODE __TableHashCreate(TABLE *);
CAT_EXTERN CAT_RETURN_CODE __TableHashDestroy(TABLE *);
CAT_EXTERN CAT_RETURN_CODE __TableHashPop(TABLE *, char *);
CAT_EXTERN CAT_RETURN_CODE __TableHashPush(TABLE *, char *, int, char **);
CAT_EXTERN CAT_RETURN_CODE __TableHashSeach(TABLE *, const char *, bool *);
CAT_EXTERN CAT_RETURN_CODE __TableHashLookup(TABLE *, const char *, int *, char ***, bool *);
