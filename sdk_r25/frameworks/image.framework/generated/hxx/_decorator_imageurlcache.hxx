// This file contains decorator implementations for the interfaces of imageurlcache.h. They are intended for copy&paste usage only.

class ImageUrlCacheDecoratorImpl : public maxon::Component<ImageUrlCacheDecoratorImpl, ImageUrlCacheInterface, maxon::DecoratorInterface>
{
	MAXON_COMPONENT();

public:
	MAXON_METHOD Result<ImageBaseRef> GetImageRef(UpdateCacheDelegate&& updateDelegate) const
	{
		return maxon::Cast<ImageUrlCacheRef>(self.GetDecoratedObject()).GetImageRef(std::forward<UpdateCacheDelegate>(updateDelegate));
	}

	MAXON_METHOD maxon::ObservableRef<ObservableFreeCacheDelegate> ObservableFreeCache() const
	{
		return maxon::Cast<ImageUrlCacheRef>(self.GetDecoratedObject()).ObservableFreeCache();
	}

};
