#include "catsys.h"
#include "catvec.h"

int main(int argc, char **argv)
{
    Vec   v;

    CatFunctionBegin;
    CatCall(CatInitialise(&argc, &argv));
    CatCall(VecCreateNative(MPI_COMM_WORLD, 10, 10, &v));
    CatCall(VecDestroy(&v));
    CatCall(CatFinalise());
    return 0;
}
