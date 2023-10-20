#include "catsys.h"

CatErrorCode bar()
{
  CatFunctionBegin;
  CatFunctionReturn(CAT_SUCCESS);
}

CatErrorCode foo()
{
    CatFunctionBegin;
    CatCall(bar());
    CatFunctionReturn(CAT_SUCCESS);
}

int main(int argc, char **argv)
{
    CatFunctionBegin;
    CatCall(CatInitialise(&argc, &argv));
    CatCall(foo());
    CatCall(CatFinalise());
    return 0;
}
