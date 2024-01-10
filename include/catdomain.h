#pragma once

#include <catsys.h>

#define DOMAIN_BLOCK "block"

CAT_EXTERN CAT_RETURN_CODE DomainCreate(MPI_Comm, domain_p *);
CAT_EXTERN CAT_RETURN_CODE DomainDestroy(domain_p *);
CAT_EXTERN CAT_RETURN_CODE DomainSetFromOptions(domain_p);
CAT_EXTERN CAT_RETURN_CODE DomainSetType(char *, domain_p);
CAT_EXTERN CAT_RETURN_CODE DomainSetDimensions(label_t, domain_p);
