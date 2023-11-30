// This file contains default implementations for the interfaces of imageregionobserver.h. They are intended for copy&paste usage only.

class MyImageRegionObserverImpl : public maxon::Component<MyImageRegionObserverImpl, ImageRegionObserverInterface>
{
	MAXON_COMPONENT();

public:
	MAXON_METHOD Result<void> OnConnect(const IntVector2d& dimensions)
	{
		return HXXRET1(NULLIMPL);
	}

	MAXON_METHOD void OnResize(const IntVector2d& dimensions)
	{
		return maxon::PrivateLogNullptrError();
	}

	MAXON_METHOD void OnRegionDirty(const Range<IntVector2d>& dirtyRegion)
	{
		return maxon::PrivateLogNullptrError();
	}

	MAXON_METHOD void OnDisconnect()
	{
		return maxon::PrivateLogNullptrError();
	}

};
