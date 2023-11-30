// This file contains default implementations for the interfaces of imageurlcache.h. They are intended for copy&paste usage only.

class MyImageUrlCacheImpl : public maxon::Component<MyImageUrlCacheImpl, ImageUrlCacheInterface>
{
	MAXON_COMPONENT();

public:
	MAXON_METHOD maxon::ObservableRef<ObservableFreeCacheDelegate> ObservableFreeCache(Bool create) const
	{
		return maxon::ObservableRef<ObservableFreeCacheDelegate>::DefaultValue();
	}

	MAXON_METHOD Result<Opt<ImageBaseRef>> GetImage(UpdateCacheDelegate&& updateDelegate) const
	{
		return HXXRET1(NULLIMPL);
	}

	MAXON_METHOD Result<Opt<ImageBaseRef>> GetImage(UpdateCacheDelegate&& updateDelegate, Bool async) const
	{
		return HXXRET1(NULLIMPL);
	}

};
