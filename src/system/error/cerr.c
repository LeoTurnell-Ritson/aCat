#include <cat/private/catimpl.h>
#include <catstring.h>

static bool_t errf = CAT_TRUE;

static char *errstr[] = {
        "Success",
        "Boolian macro failure",
        "Assertion is false",
        "Function not implemented",
        "Out of memory",
        "System library function returned an error",
        "Invalid pointer",
        "Unreachable",
        "Operation has not been set for given object",
        "Runtime debugger caught attempt to allocate to a used pointer",
        "Runtime debugger caught attempt to free unset pointer",
        "CAT_ERR_BAD_INITIALIZATION",
        "CAT_ERR_BAD_DIMENSIONS",
        "Un-freed memory detected",
        "CAT_ERR_BAD_LOOKUP"
};


CAT_RETURN_CODE CatError(MPI_Comm comm, const char *file, const char *func, const int line, const char *name, const CAT_RETURN_CODE err, const char *msg, ...)
{
        bool_t ismain;
        va_list arg;

        if (errf) {
                va_start(arg, msg);
                __CatErrorVMeowf(comm, file, func, line, name, err, msg, arg);
                va_end(arg);
                errf = CAT_FALSE;
        }
        (void)CatStrncmp(func, "main", 4, &ismain);
        if (ismain) {
#if CAT_USING_DEBUG_FUNCTION_STACK
                __FunctionStackCheck();
#endif
                MPI_Abort(comm, err);
        }
        return err;
}

void CatErrorNoReturn(MPI_Comm comm, const char *file, const char *func, const int line, const char *name, const CAT_RETURN_CODE err, const char *msg, ...)
{
        va_list arg;

        if (errf) {
                va_start(arg, msg);
                __CatErrorVMeowf(comm, file, func, line, name, err, msg, arg);
                va_end(arg);
                errf = CAT_FALSE;
        }
#if CAT_USING_DEBUG_FUNCTION_STACK
                __FunctionStackCheck();
#endif
        MPI_Abort(comm, err);
}

void CatWarnNoReturn(MPI_Comm comm, const char *file, const char *func, const int line, const char *name, const CAT_RETURN_CODE err, const char *msg, ...)
{
        va_list arg;

        va_start(arg, msg);
        __CatErrorVMeowf(comm, file, func, line, name, err, msg, arg);
        va_end(arg);
}


CAT_RETURN_CODE CatMPIError(const int err)
{
        CatCheck(CAT_FALSE, MPI_COMM_SELF, CAT_ERR_NOT_IMPLEMENTED, "MPI error handler not implemented");
        return err;
}

void __CatErrorMeowf(MPI_Comm comm, const char *file, const char *func, const int line, const char *name, const CAT_RETURN_CODE err, const char *msg, ...)
{
        va_list arg;
        va_start(arg, msg);
        __CatErrorVMeowf(comm, file, func, line, name, err, msg, arg);
        va_end(arg);
}

void __CatErrorVMeowf(MPI_Comm comm, const char *file, const char *func, const int line, const char *name, const CAT_RETURN_CODE err, const char *msg, va_list arg)
{
        bool_t nmsg;
        char *emsg;

        (void)CatStrncmp(msg, " ", 1, &nmsg);
        emsg = errstr[err];
        (void)CatFMeowf(comm, CAT_STDERR, "\033[1;36m%s:\033[0m In function ‘\033[1;36m%s\033[0m’:\n", file, func);
        (void)CatFMeowf(comm, CAT_STDERR, "\033[1;36m%s:%d: \033[1;31m%s:\033[0m %s", file, line, name, emsg);

        if (!nmsg) {
                (void)CatFMeowf(comm, CAT_STDERR, "; ");
                (void)CatVFMeowf(comm, CAT_STDERR, msg, arg);
        }

        (void)CatFMeowf(comm, CAT_STDERR, "\n");
}
