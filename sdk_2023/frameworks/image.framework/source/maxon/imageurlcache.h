#ifndef IMAGEURLCACHE_H__
#define IMAGEURLCACHE_H__

#include "maxon/gfx_image.h"
#include "maxon/observable.h"


namespace maxon
{

class ImageUrlCacheRef;

//----------------------------------------------------------------------------------------
/// Cache class to allow delayed load of images with notification when it's ready to display.
/// Multiple requests are combined (the first request loads the image and notifies all others)
//----------------------------------------------------------------------------------------
class ImageUrlCacheInterface : MAXON_INTERFACE_BASES(ObserverObjectInterface)
{
	MAXON_INTERFACE(ImageUrlCacheInterface, MAXON_REFERENCE_NORMAL, "net.maxon.image.interface.imageurlcache");

public:
	/// Delegate which is called if the cache was updated.
	/// @param[in] url          url of the image
	/// @param[in] loaded				ImageBaseRef with the loaded image.
	using UpdateCacheDelegate = Delegate<Result<void>(const Url& url, const ImageBaseRef& loaded)>;

	//----------------------------------------------------------------------------------------
	/// InvalidateCache invalidates and removed the image from the cache. The next request will reload the image.
	/// @param[in] url								Image to discard from the cache.
	/// @return                       OK on success.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<void> InvalidateCache(const Url& url);

	//----------------------------------------------------------------------------------------
	/// FindOrCreate returns the cache for the requested image resource.
	/// @param[in] url								Url of the image to load.
	/// @return                       Cache on success.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<ImageUrlCacheRef> FindOrCreate(const Url& url);

	MAXON_OBSERVABLE(void, ObservableFreeCache, (const Url& url), ObservableCombinerRunAllComponent);

	//----------------------------------------------------------------------------------------
	/// GetImage returns the image from the cache, if there is one. If nullptr then the image is 
	/// still loading. In that case the delegate is triggered once the image is loaded.
	/// @param[in] updateDelegate			Delegate which is called once the image is loaded.
	/// @return                       Image or nullptr on success.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<Opt<ImageBaseRef>> GetImage(UpdateCacheDelegate&& updateDelegate) const;
};

#include "imageurlcache1.hxx"
#include "imageurlcache2.hxx"

} // namespace maxon


#endif // IMAGEURLCACHE_H__
