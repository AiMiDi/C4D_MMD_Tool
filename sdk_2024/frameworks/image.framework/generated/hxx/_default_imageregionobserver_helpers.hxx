// This file contains default implementations for the interfaces of imageregionobserver_helpers.h. They are intended for copy&paste usage only.

class MyImageRegionTilesObserverImpl : public maxon::Component<MyImageRegionTilesObserverImpl, ImageRegionTilesObserverInterface>
{
	MAXON_COMPONENT();

public:
	MAXON_METHOD Result<void> Init(Int tileSize)
	{
		return HXXRET1(NULLIMPL);
	}

	MAXON_METHOD Result<void> GetAndResetDirtyState(DirtyState& dirtyState)
	{
		return HXXRET1(NULLIMPL);
	}

};
