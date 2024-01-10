#include <catstring.h>
#include <../src/objects/table/impl/hash/hsh.h>

static CAT_RETURN_CODE __TableHashPushToTail(struct __node **h, struct __node **n)
{
        CatFunctionBegin;
        if (!(*h)) {
                *h = *n;
                CatFunctionReturn(CAT_SUCCESS);
        }
        CatFunction(__TableHashPushToTail(&((*h)->next), n));
        CatFunctionReturn(CAT_SUCCESS);
}

static CAT_RETURN_CODE __TableHashHashKey(table_p tab, const char *key, label_t *loc)
{
        label_t hash;
        int c;

        CatFunctionBegin;
        hash = 5381;
        while ((c = *key++)) hash = ((hash << 5) + hash) + c;
        *loc = hash % tab->size;
        CatFunctionReturn(CAT_SUCCESS);
}

static CAT_RETURN_CODE __TableHashNodeDestroy(struct __node *node)
{
        label_t i;


        CatFunctionBegin;
        if (node) {
                CatFunction(__TableHashNodeDestroy(node->next));
                for (i = 0; i < node->argc; i++) {
                        CatFunction(CatFree(node->argv[i]));
                }
                node->argc = 0;
                CatFunction(CatFree(node->key));
                CatFunction(CatFree(node->argv));
                CatFunction(CatFree(node));
        }
        CatFunctionReturn(CAT_SUCCESS);
}

CAT_RETURN_CODE __TableHashDestroy(table_p tab)
{
        struct __hash *hsh;
        label_t          i;

        CatFunctionBegin;
        hsh = (struct __hash *)tab->data;
        for (i = 0; i < tab->size; i++) {
                CatFunction(__TableHashNodeDestroy(hsh->items[i]));
        }
        CatFunction(CatFree(hsh->items));
        CatFunction(CatFree(tab->data));
        CatFunctionReturn(CAT_SUCCESS);
}

CAT_RETURN_CODE __TableHashPop(table_p tab, char *key)
{
        CatFunctionBegin;
        __CAT_NOT_IMPLEMENTED;
        (void)tab;
        (void)key;
        CatFunctionReturn(CAT_SUCCESS);
}

CAT_RETURN_CODE __TableHashPush(table_p tab, char *key, label_t argc, char **argv)
{
        struct __hash         *hsh;
        struct __node        *node;
        size_t                 len;
        label_t             i, loc;

        CatFunctionBegin;
        hsh = (struct __hash *)tab->data;
        CatFunction(CatNew(&node));
        node->argc = argc;
        node->next = NULL;
        CatFunction(CatStrlen(key, &len));
        CatFunction(CatCalloc((len + 1) * sizeof (char), &(node->key)));
        CatFunction(CatStrcpy(node->key, key));
        CatFunction(CatCalloc((argc + 1) * sizeof (char *), &(node->argv)));
        for (i = 0; i < argc; i++) {
                CatFunction(CatStrlen(argv[i], &len));
                CatFunction(CatCalloc((len + 1) * sizeof (char), &(node->argv[i])));
                CatFunction(CatStrcpy(node->argv[i], argv[i]));
        }
        node->argv[argc] = NULL;
        CatFunction(__TableHashHashKey(tab, key, &loc));
        CatFunction(__TableHashPushToTail(&(hsh->items[loc]), &node));
        CatFunctionReturn(CAT_SUCCESS);
}

CAT_RETURN_CODE __TableHashSeach(table_p tab, const char *key, bool_t *in)
{
        struct __hash  *hsh;
        struct __node  *cur;
        label_t         loc;
        char       *arg_key;

        CatFunctionBegin;
        hsh = (struct __hash *)tab->data;
        CatFunction(__TableHashHashKey(tab, key, &loc));
        cur = hsh->items[loc];
        *in = CAT_FALSE;
        while (cur) {
                arg_key = cur->key;
                CatFunction(CatStrcmp(key, arg_key, in));
                if (*in) break;
                cur = cur->next;
        }
        CatFunctionReturn(CAT_SUCCESS);
}

CAT_RETURN_CODE __TableHashLookup(table_p tab, const char *key, label_t *argc, char ***argv, bool_t *in)
{
        struct __hash  *hsh;
        struct __node  *cur;
        label_t         loc;
        char       *arg_key;

        CatFunctionBegin;
        hsh = (struct __hash *)tab->data;
        CatFunction(__TableHashHashKey(tab, key, &loc));
        cur = hsh->items[loc];
        *in = CAT_FALSE;
        while (cur) {
                arg_key = cur->key;
                CatFunction(CatStrcmp(key, arg_key, in));
                if (*in) {
                        *argc = cur->argc;
                        *argv = cur->argv;
                        break;
                }
                cur = cur->next;
        }
        CatFunctionReturn(CAT_SUCCESS);
}
