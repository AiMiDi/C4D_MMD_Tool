// This file contains decorator implementations for the interfaces of imageregionobserver.h. They are intended for copy&paste usage only.

class ImageRegionObserverDecoratorImpl : public maxon::Component<ImageRegionObserverDecoratorImpl, ImageRegionObserverInterface, maxon::DecoratorInterface>
{
	MAXON_COMPONENT();

public:
	MAXON_METHOD Result<void> OnConnect(const IntVector2d& dimensions)
	{
		return maxon::Cast<ImageRegionObserverRef>(self.GetDecoratedObject()).OnConnect(dimensions);
	}

	MAXON_METHOD void OnResize(const IntVector2d& dimensions)
	{
		return maxon::Cast<ImageRegionObserverRef>(self.GetDecoratedObject()).OnResize(dimensions);
	}

	MAXON_METHOD void OnRegionDirty(const Range<IntVector2d>& dirtyRegion)
	{
		return maxon::Cast<ImageRegionObserverRef>(self.GetDecoratedObject()).OnRegionDirty(dirtyRegion);
	}

	MAXON_METHOD void OnDisconnect()
	{
		return maxon::Cast<ImageRegionObserverRef>(self.GetDecoratedObject()).OnDisconnect();
	}

};
