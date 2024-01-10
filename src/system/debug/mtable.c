#include <cat/private/catimpl.h>
#include <../src/system/debug/mtable.h>

#include <stdlib.h>

static struct __mtable table;

static void __HashKey(const char *key, label_t *loc)
{
        label_t hash;
        int c;

        hash = 5381;
        while ((c = *key++)) hash = ((hash << 5) + hash) + c;
        *loc = hash % DEBUG_MEMORY_TABLE_SIZE;
}

void __MemoryPush(const char *file, const char *func, const int line, const char *key)
{
        label_t loc;
        struct __mnode *node;

        node = (struct __mnode *)malloc(sizeof (struct __mnode));
        node->next = NULL;
        node->key = key;
        node->file = file;
        node->func = func;
        node->line = line;
        __HashKey(key, &loc);
        if (!(table.nodes[loc]))
                table.nodes[loc] = node;
        else
                CatCheckNoReturn(CAT_FALSE, MPI_COMM_SELF, CAT_ERR_NOT_IMPLEMENTED, "Node key conflicts not implemented");
}

void __MemoryPop(const char *key)
{
        label_t loc;

        __HashKey(key, &loc);
        CatCheckNoReturn(table.nodes[loc], MPI_COMM_SELF, CAT_ERR_DEBUG_MEMORY_FREE, " ");
        free(table.nodes[loc]);
        table.nodes[loc] = NULL;
}

void __MemoryCheck(void)
{
        label_t i;

        for (i = 0; i < DEBUG_MEMORY_TABLE_SIZE; i++) {
                if (table.nodes[i]) {
                        __CatErrorMeowf(MPI_COMM_SELF, table.nodes[i]->file, table.nodes[i]->func, table.nodes[i]->line, "leak", CAT_ERR_MEMORY_LEAK, " ");
                }
        }
}
