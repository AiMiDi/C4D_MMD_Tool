// This file contains decorator implementations for the interfaces of imageregionobserver_helpers.h. They are intended for copy&paste usage only.

class ImageRegionTilesObserverDecoratorImpl : public maxon::Component<ImageRegionTilesObserverDecoratorImpl, ImageRegionTilesObserverInterface, maxon::DecoratorInterface>
{
	MAXON_COMPONENT();

public:
	MAXON_METHOD Result<void> Init(Int tileSize)
	{
		return maxon::Cast<ImageRegionTilesObserverRef>(self.GetDecoratedObject()).Init(tileSize);
	}

	MAXON_METHOD Result<void> GetAndResetDirtyState(DirtyState& dirtyState)
	{
		return maxon::Cast<ImageRegionTilesObserverRef>(self.GetDecoratedObject()).GetAndResetDirtyState(dirtyState);
	}

};
