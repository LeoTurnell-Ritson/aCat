#include <cat/private/catimpl.h>

CAT_EXTERN void CatFunctionPush(const char *file, const char *func, const int line)
{
#if CAT_USING_DEBUG_FUNCTION_STACK
        __FunctionStackPush(file, func, line);
#else
        (void)file;
        (void)func;
        (void)line;
#endif
}

CAT_EXTERN void CatFunctionPop(void)
{
#if CAT_USING_DEBUG_FUNCTION_STACK
        __FunctionStackPop();
#endif
}

CAT_EXTERN void CatFunctionUpdateLine(const char *func, const int line)
{
#if CAT_USING_DEBUG_FUNCTION_STACK
        __FunctionStackUpdateLine(func, line);
#else
        (void)func;
        (void)line;
#endif
}
