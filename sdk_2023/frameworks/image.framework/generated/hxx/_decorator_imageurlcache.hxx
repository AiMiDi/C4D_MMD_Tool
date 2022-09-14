// This file contains decorator implementations for the interfaces of imageurlcache.h. They are intended for copy&paste usage only.

class ImageUrlCacheDecoratorImpl : public maxon::Component<ImageUrlCacheDecoratorImpl, ImageUrlCacheInterface, maxon::DecoratorInterface>
{
	MAXON_COMPONENT();

public:
	MAXON_METHOD maxon::ObservableRef<ObservableFreeCacheDelegate> ObservableFreeCache() const
	{
		return maxon::Cast<ImageUrlCacheRef>(self.GetDecoratedObject()).ObservableFreeCache();
	}

	MAXON_METHOD Result<Opt<ImageBaseRef>> GetImage(UpdateCacheDelegate&& updateDelegate) const
	{
		return maxon::Cast<ImageUrlCacheRef>(self.GetDecoratedObject()).GetImage(std::forward<UpdateCacheDelegate>(updateDelegate));
	}

};
