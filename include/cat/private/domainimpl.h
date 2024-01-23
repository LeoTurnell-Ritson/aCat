#pragma once

#include <catdomain.h>
#include <cat/private/catimpl.h>

struct __domops {
        CAT_RETURN_CODE (*create)(DOMAIN *);
        CAT_RETURN_CODE (*destroy)(DOMAIN *);
        CAT_RETURN_CODE (*setfromoptions)(DOMAIN *);
};

struct __domain {
        Header(struct __domops);
        int   ndims;
        void *data;
};

CAT_EXTERN CAT_RETURN_CODE DomainBuildInternal(DOMAIN *);
CAT_EXTERN CAT_RETURN_CODE DomainBuildInternalBlock(DOMAIN *);
