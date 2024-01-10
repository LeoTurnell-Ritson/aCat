#include <cat/private/domainimpl.h>

struct __block {
        label_t  world_grid[3];
        label_t  world_processors[3];
};

/* Public access */
CAT_EXTERN CAT_RETURN_CODE __DomainBlockCreate(domain_p);
CAT_EXTERN CAT_RETURN_CODE __DomainBlockDestroy(domain_p);
CAT_EXTERN CAT_RETURN_CODE __DomainBlockSetFromOptions(domain_p);

/* Internal only access */
CAT_EXTERN CAT_RETURN_CODE __DomainBlockDecompose(domain_p);
CAT_EXTERN CAT_RETURN_CODE __DomainBlockCheckOptions(domain_p);
