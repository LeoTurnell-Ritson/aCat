#include <catsys.h>
#include <cattable.h>
#include <catdomain.h>

int main(int argc, char **argv)
{
        domain_p dom;

        CatFunctionBegin;
        CatFunction(CatInitialize(&argc, &argv));
        CatFunction(DomainCreate(MPI_COMM_SELF, &dom));
        CatFunction(DomainSetFromOptions(dom));
        CatFunction(DomainDestroy(&dom));
        CatFunction(CatFinalize());

        return 0;
}
