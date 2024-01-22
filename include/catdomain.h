#pragma once

#include <catsys.h>

#define DOMAIN_BLOCK "block"

CAT_EXTERN CAT_RETURN_CODE DomainCreate(MPI_Comm, DOMAIN **);
CAT_EXTERN CAT_RETURN_CODE DomainDestroy(DOMAIN **);
CAT_EXTERN CAT_RETURN_CODE DomainSetFromOptions(DOMAIN *);
CAT_EXTERN CAT_RETURN_CODE DomainSetType(char *, DOMAIN *);
CAT_EXTERN CAT_RETURN_CODE DomainSetDimensions(int, DOMAIN *);
