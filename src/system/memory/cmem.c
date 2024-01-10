#include <cat/private/catimpl.h>
#include <stdlib.h>

CAT_RETURN_CODE CatMallocAlign(bool_t clear, const char *file, const char *func, const int line, const size_t mem, void **result)
{
        #if CAT_USING_DEBUG_MEMORY_TABLE
        char buff[64];
        #endif

        CatFunctionBegin;
        if (!mem) {
                *result = NULL;
                CatFunctionReturn(CAT_SUCCESS);
        }
        if (clear)
                *result = calloc(1 + mem / sizeof (int), sizeof (int));
        else
                *result = malloc(mem);
        CatCheck(*result, MPI_COMM_SELF, CAT_ERR_MEMORY, "Requested %ld bytes of memory\n", mem);
#if CAT_USING_DEBUG_MEMORY_TABLE
        CatFunction(CatSNMeowf(buff, sizeof (buff), "%p", (void *)(*result)));
        __MemoryPush(file, func, line, buff);
#else
        (void)file;
        (void)func;
        (void)line;
#endif
        CatFunctionReturn(CAT_SUCCESS);
}

CAT_RETURN_CODE CatFreeAlign(const char *file, const char *func, const int line, void *memory)
{
        #if CAT_USING_DEBUG_MEMORY_TABLE
        char buff[64];
        #endif

        CatFunctionBegin;
#if CAT_USING_DEBUG_MEMORY_TABLE
        CatFunction(CatSNMeowf(buff, sizeof (buff), "%p", (void *)(memory)));
        __MemoryPop(buff);
#endif
        (void)file;
        (void)func;
        (void)line;
        free(memory);
        CatFunctionReturn(CAT_SUCCESS);
}
