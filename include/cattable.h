#pragma once

#include <catsys.h>

#define TABLE_HASH "hash"

CAT_EXTERN CAT_RETURN_CODE TableCreate(MPI_Comm, table_p *);
CAT_EXTERN CAT_RETURN_CODE TableDestroy(table_p *);
CAT_EXTERN CAT_RETURN_CODE TableTypeSet(char *, table_p);
CAT_EXTERN CAT_RETURN_CODE TableSizeSet(label_t, table_p);
CAT_EXTERN CAT_RETURN_CODE TablePush(char *, label_t, char **, table_p);
CAT_EXTERN CAT_RETURN_CODE TableSearch(table_p , const char *, bool_t *);
CAT_EXTERN CAT_RETURN_CODE TableLookup(table_p, const char *, label_t *, char ***, bool_t *);

/*
CAT_EXTERN CAT_RETURN_CODE TablePop(char *, label_t, char **, table_p);
CAT_EXTERN CAT_RETURN_CODE TableSizeSet(label_t, table_p);
CAT_EXTERN CAT_RETURN_CODE TableSizeGet(table_p, label_t *);
CAT_EXTERN CAT_RETURN_CODE TablePush(char *, table_p);
CAT_EXTERN CAT_RETURN_CODE TablePop(char *, table_p);
*/
