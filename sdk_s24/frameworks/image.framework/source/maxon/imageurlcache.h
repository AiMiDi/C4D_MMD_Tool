#ifndef IMAGEURLCACHE_H__
#define IMAGEURLCACHE_H__

#include "maxon/gfx_image.h"
#include "maxon/observable.h"


namespace maxon
{

class ImageUrlCacheRef;


class ImageUrlCacheInterface : MAXON_INTERFACE_BASES(ObserverObjectInterface)
{
	MAXON_INTERFACE(ImageUrlCacheInterface, MAXON_REFERENCE_NORMAL, "net.maxon.image.interface.imageurlcache");

public:
	using UpdateCacheDelegate = Delegate<Result<void>(const Url& url, const ImageBaseRef& loaded)>;

	static MAXON_METHOD Result<void> InvalidateCache(const Url& url);

	static MAXON_METHOD Result<ImageUrlCacheRef> FindOrCreate(const Url& url);

	MAXON_METHOD Result<ImageBaseRef> GetImageRef(UpdateCacheDelegate&& updateDelegate) const;

	MAXON_OBSERVABLE(void, ObservableFreeCache, (const Url& url), ObservableCombinerRunAllComponent);
};

#include "imageurlcache1.hxx"
#include "imageurlcache2.hxx"

} // namespace maxon


#endif // IMAGEURLCACHE_H__
