#pragma once

#include <catdomain.h>
#include <cat/private/catimpl.h>

struct __domops {
        CAT_RETURN_CODE (*create)(domain_p);
        CAT_RETURN_CODE (*destroy)(domain_p);
        CAT_RETURN_CODE (*setfromoptions)(domain_p);
};

struct __domain {
        __Header(struct __domops);
        int  ndims;
        void     *data;
};

CAT_EXTERN CAT_RETURN_CODE __DomainBuildInternal(domain_p);
CAT_EXTERN CAT_RETURN_CODE __DomainBuildInternalBlock(domain_p);
