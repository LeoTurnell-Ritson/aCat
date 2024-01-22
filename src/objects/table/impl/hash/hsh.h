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

CAT_EXTERN CAT_RETURN_CODE __TableHashCreate(table_p);
CAT_EXTERN CAT_RETURN_CODE __TableHashDestroy(table_p);
CAT_EXTERN CAT_RETURN_CODE __TableHashPop(table_p, char *);
CAT_EXTERN CAT_RETURN_CODE __TableHashPush(table_p, char *, int, char **);
CAT_EXTERN CAT_RETURN_CODE __TableHashSeach(table_p, const char *, bool *);
CAT_EXTERN CAT_RETURN_CODE __TableHashLookup(table_p, const char *, int *, char ***, bool *);
