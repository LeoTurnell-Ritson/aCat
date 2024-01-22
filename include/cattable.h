#pragma once

#include <catsys.h>

#define TABLE_HASH "hash"

CAT_EXTERN CAT_RETURN_CODE TableCreate(MPI_Comm, table_p *);
CAT_EXTERN CAT_RETURN_CODE TableDestroy(table_p *);
CAT_EXTERN CAT_RETURN_CODE TableSetType(char *, table_p);
CAT_EXTERN CAT_RETURN_CODE TableSetSize(int, table_p);
CAT_EXTERN CAT_RETURN_CODE TablePush(char *, int, char **, table_p);
CAT_EXTERN CAT_RETURN_CODE TableSearch(table_p , const char *, bool *);
CAT_EXTERN CAT_RETURN_CODE TableLookup(table_p, const char *, int *, char ***, bool *);

/*
CAT_EXTERN CAT_RETURN_CODE TablePop(char *, int, char **, table_p);
CAT_EXTERN CAT_RETURN_CODE TableSizeSet(int, table_p);
CAT_EXTERN CAT_RETURN_CODE TableSizeGet(table_p, int *);
CAT_EXTERN CAT_RETURN_CODE TablePush(char *, table_p);
CAT_EXTERN CAT_RETURN_CODE TablePop(char *, table_p);
*/
