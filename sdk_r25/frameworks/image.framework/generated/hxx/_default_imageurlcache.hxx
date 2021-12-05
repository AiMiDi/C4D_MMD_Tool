// This file contains default implementations for the interfaces of imageurlcache.h. They are intended for copy&paste usage only.

class MyImageUrlCacheImpl : public maxon::Component<MyImageUrlCacheImpl, ImageUrlCacheInterface>
{
	MAXON_COMPONENT();

public:
	MAXON_METHOD Result<ImageBaseRef> GetImageRef(UpdateCacheDelegate&& updateDelegate) const
	{
		return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
	}

	MAXON_METHOD maxon::ObservableRef<ObservableFreeCacheDelegate> ObservableFreeCache() const
	{
		return maxon::ObservableRef<ObservableFreeCacheDelegate>::NullValue();
	}

};
