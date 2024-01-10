#include <cat/private/domainimpl.h>

struct __block {
        scalar_t world_xlim[2], world_ylim[2], world_zlim[2];
        scalar_t world_spacing;
};

/* Public access */
CAT_EXTERN CAT_RETURN_CODE __DomainBlockCreate(domain_p);
CAT_EXTERN CAT_RETURN_CODE __DomainBlockDestroy(domain_p);
CAT_EXTERN CAT_RETURN_CODE __DomainBlockSetFromOptions(domain_p);

/* Internal only access */
CAT_RETURN_CODE __DomainBlockPrivateDecompose(domain_p dom);
