#include <catsys.h>

CAT_RETURN_CODE CatVFMeowf(MPI_Comm comm, FILE *stream, const char *format, va_list arg)
{
        int rank;

        CatFunctionBegin;
        CatMPIFunction(MPI_Comm_rank(comm, &rank));
        if (rank == 0 && comm == MPI_COMM_WORLD) {
                vfprintf(stream, format, arg);
                CatFunctionReturn(CAT_SUCCESS);
        } else if (rank == 0 && comm == MPI_COMM_SELF) {
                vfprintf(stream, format, arg);
                CatFunctionReturn(CAT_SUCCESS);
        } else {
                CatFunctionReturn(CAT_SUCCESS);
        }
}

CAT_RETURN_CODE CatMeowf(MPI_Comm comm, const char *format, ...)
{
        va_list arg;

        CatFunctionBegin;
        va_start(arg, format);
        CatFunction(CatVFMeowf(comm, CAT_STDOUT, format, arg));
        va_end(arg);
        CatFunctionReturn(CAT_SUCCESS);
}

CAT_RETURN_CODE CatFMeowf(MPI_Comm comm, FILE *f, const char *format, ...)
{
        va_list arg;

        CatFunctionBegin;
        va_start(arg, format);
        CatFunction(CatVFMeowf(comm, f, format, arg));
        va_end(arg);
        CatFunctionReturn(CAT_SUCCESS);
}

CAT_RETURN_CODE CatSNMeowf(char *str, size_t len, const char *format, ...)
{
        va_list arg;

        CatFunctionBegin;
        va_start(arg, format);
        CatFunction(CatVSNMeowf(str, len, format, arg));
        va_end(arg);
        CatFunctionReturn(CAT_SUCCESS);
}


CAT_RETURN_CODE CatVSNMeowf(char *str, size_t len, const char *format, va_list arg)
{
        CatFunctionBegin;
        vsnprintf(str, len, format, arg);
        CatFunctionReturn(CAT_SUCCESS);
}
