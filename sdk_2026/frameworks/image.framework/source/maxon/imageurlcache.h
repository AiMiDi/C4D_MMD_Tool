#ifndef IMAGEURLCACHE_H__
#define IMAGEURLCACHE_H__

#include "maxon/asyncresourcecache.h"
#include "maxon/gfx_image.h"

namespace maxon
{

namespace AsyncResourceCacheTypes
{
	MAXON_DECLARATION(MAXON_MACROARG_TYPE(AsyncResourceCacheRef<Url, ImageBaseRef>), ImageBaseRefCache, "net.maxon.asyncresourcecachetypes.imagebaseref", MAXON_IMPLEMENTATION_MODULE("net.maxon.image")); ///< ImageBaseRef cache loader
}

} // namespace maxon


#endif // IMAGEURLCACHE_H__
