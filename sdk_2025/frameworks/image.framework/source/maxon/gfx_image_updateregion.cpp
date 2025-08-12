#include "maxon/gfx_image_updateregion.h"
#include "maxon/gfx_image.h"


namespace maxon
{

UpdateRegionObserver::~UpdateRegionObserver()
{
	RemoveObserver();
}

Result<void> UpdateRegionObserver::AddObserver(const ImageBaseRef& image)
{
	iferr_scope;

	RemoveObserver();

	_image = image;

	_observer = image.ObservableRegionChanged(true).AddObserver(
		[this](const ObserverObjectRef& owner, const UpdateRegion& region)
		{
			_dirtyRegion.Add(region);
		}) iferr_return;

	return OK;
}

void UpdateRegionObserver::RemoveObserver()
{
	iferr_scope;

	if (_observer)
	{
		ImageBaseRef image = _image;
		if (image)
		{
			image.ObservableRegionChanged(false).RemoveObserver(_observer);
		}
		_observer = nullptr;
		_image = nullptr;
	}
}

Range<IntVector2d> UpdateRegionObserver::GetRegionAndReset()
{
	Range<IntVector2d> region = _dirtyRegion;
	_dirtyRegion.Reset();
	return region;
}

}
