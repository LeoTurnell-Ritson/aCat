#include <catstring.h>
#include <cat/private/catimpl.h>
#include <stdlib.h>
#include <stdint.h>

#define DEBUG_MEMORY_TABLE_SIZE 1031

struct __mnode {
        int               line;
        char             *key;
        char             *func;
        char             *file;
        struct __mnode   *next;
};

struct __mtable {
        struct __mnode *nodes[DEBUG_MEMORY_TABLE_SIZE];
};

static struct __mtable table;

static label_t __free_count = 0;

static label_t __malloc_count = 0;

static void __HashKey(const char *key, label_t *loc)
{
        label_t   hash;
        int       c;

        hash = 5381;
        while ((c = *key++)) hash = ((hash << 5) + hash) + c;
        *loc = hash % DEBUG_MEMORY_TABLE_SIZE;
}

static void __NodeCpyItem(const char *item, char **elem)
{
        int   len;

        len = strlen(item);
        *elem = (char *)malloc((len + 1) * sizeof (char));
        __malloc_count++;
        strcpy(*elem, item);
}

void __MemoryPush(const char *file, const char *func, const int line, const char *ptr)
{

        label_t           loc;
        struct __mnode   *new;

        new = (struct __mnode *)malloc(sizeof (struct __mnode));
        __malloc_count++;
        new->line = line;
        new->next = NULL;
        __NodeCpyItem(file, &(new->file));
        __NodeCpyItem(func, &(new->func));
        __NodeCpyItem(ptr, &(new->key));
        __HashKey(ptr, &loc);
        if (!(table.nodes[loc])) {
                table.nodes[loc] = new;
        } else {
                struct __mnode   *cur, *prv;

                prv = table.nodes[loc];
                cur = table.nodes[loc]->next;
                while (cur) {
                        prv = cur;
                        cur = cur->next;
                }
                prv->next = new;
        }

}

void __MemoryPop(const char *ptr)
{
        label_t           loc;
        struct __mnode   *cur, *nxt, *prv;

        __HashKey(ptr, &loc);
        CatCheckNoReturn(table.nodes[loc], MPI_COMM_SELF, CAT_ERR_DEBUG_MEMORY_FREE, " ");
        cur = table.nodes[loc];
        if (strcmp(ptr, cur->key) == 0) {
                nxt = cur->next;
                free(cur->key);
                free(cur->file);
                free(cur->func);
                free(cur);
                __free_count += 4;
                table.nodes[loc] = nxt;
        } else {
                prv = cur;
                cur = cur->next;
                while (cur) {
                        if (strcmp(ptr, cur->key) == 0) {
                                prv ->next = cur->next;
                                free(cur->key);
                                free(cur->file);
                                free(cur->func);
                                free(cur);
                                __free_count += 4;
                                cur = NULL;
                        } else {
                                prv = cur;
                                cur = cur->next;
                        }
                }
        }
}

void __MemoryCheck(void)
{
        label_t           i;
        struct __mnode   *cur;

        for (i = 0; i < DEBUG_MEMORY_TABLE_SIZE; i++) {
                cur = table.nodes[i];
                while (cur) {
                        __CatErrorMeowf(MPI_COMM_SELF, cur->file, cur->func, cur->line, "leak", CAT_ERR_MEMORY_LEAK, " ");
                        cur = cur->next;
                }
        }
/*
  CatCheckNoReturn(__malloc_count == __free_count, MPI_COMM_SELF, CAT_ERR_DEBUG_MEMORY_FREE,
  "internal memory table error, __malloc_count(%d) != __free_count(%d)", __malloc_count, __free_count);
*/
}
