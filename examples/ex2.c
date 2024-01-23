#include <catdomain.h>

int main(int argc, char **argv)
{
        DOMAIN *dom;

        CatFunctionBegin;
        CatFunction(CatInitialize(&argc, &argv));
        CatFunction(CatAddOptions("--dom_type block --dom_dim 1 --dom_grid_x 100 --dom_processors_x 4"));
        CatFunction(DomainCreate(MPI_COMM_SELF, &dom));
        CatFunction(DomainSetFromOptions(dom));
        CatFunction(DomainDestroy(&dom));
        CatFunction(CatFinalize());

        return 0;
}
