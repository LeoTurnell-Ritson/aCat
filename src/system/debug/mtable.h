#pragma once

#define DEBUG_MEMORY_TABLE_SIZE 1213

struct __mnode {
        const char  *key;
        const char  *func;
        const char  *file;
        int         line;
        struct __mnode *next;
};

struct __mtable {
        struct __mnode *nodes[DEBUG_MEMORY_TABLE_SIZE];
};
