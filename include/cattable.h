#pragma once

#include <catsys.h>

#define TABLE_HASH "hash"

CAT_EXTERN CAT_RETURN_CODE TableCreate(MPI_Comm, TABLE **);
CAT_EXTERN CAT_RETURN_CODE TableDestroy(TABLE **);
CAT_EXTERN CAT_RETURN_CODE TableSetType(char *, TABLE *);
CAT_EXTERN CAT_RETURN_CODE TableSetSize(int, TABLE *);
CAT_EXTERN CAT_RETURN_CODE TablePush(char *, int, char **, TABLE *);
CAT_EXTERN CAT_RETURN_CODE TableSearch(TABLE *, const char *, bool *);
CAT_EXTERN CAT_RETURN_CODE TableLookup(TABLE *, const char *, int *, char ***, bool *);

/*
CAT_EXTERN CAT_RETURN_CODE TablePop(char *, int, char **, TABLE *);
CAT_EXTERN CAT_RETURN_CODE TableSizeSet(int, TABLE *);
CAT_EXTERN CAT_RETURN_CODE TableSizeGet(TABLE *, int *);
CAT_EXTERN CAT_RETURN_CODE TablePush(char *, TABLE *);
CAT_EXTERN CAT_RETURN_CODE TablePop(char *, TABLE *);
*/
