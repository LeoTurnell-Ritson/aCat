#include <catstring.h>
#include <cattable.h>

int main(int argc, char **argv)
{
        table_p         tab;
        bool_t     fnd, mch;
        label_t    opt_argc;
        char     **opt_argv;

        CatFunctionBegin;
        CatFunction(CatInitialize(&argc, &argv));
        CatFunction(CatAddOptions("--added_option a b c"));
        CatFunction(CatGetOptions(&tab));
        CatFunction(TableLookup(tab, "--added_option", &opt_argc, &opt_argv, &fnd));
        CatAssert(fnd, MPI_COMM_SELF, " ");
        CatAssert(opt_argc == 3, MPI_COMM_SELF, " ");
        CatFunction(CatStrcmp("a", opt_argv[0], &mch));
        CatAssert(mch, MPI_COMM_SELF, " ");
        CatFunction(CatStrcmp("b", opt_argv[1], &mch));
        CatAssert(mch, MPI_COMM_SELF, " ");
        CatFunction(CatStrcmp("c", opt_argv[2], &mch));
        CatAssert(mch, MPI_COMM_SELF, " ");
        CatFunction(CatFinalize());

        return 0;
}