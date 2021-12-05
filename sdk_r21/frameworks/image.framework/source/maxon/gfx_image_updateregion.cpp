#include "maxon/gfx_image_updateregion.h"
#include "maxon/gfx_image.h"


namespace maxon
{

Result<void> UpdateRegionObserver::AddObserver(const ImageBaseRef& image)
{
	iferr_scope;

	_observer = image.ObservableRegionChanged().AddObserver(
		[this](const ObserverObjectRef& owner, const UpdateRegion& region)
		{
			_dirtyRegion.Add(region);
		}) iferr_return;

	return OK;
}

Range<IntVector2d> UpdateRegionObserver::GetRegionAndReset()
{
	Range<IntVector2d> region = _dirtyRegion;
	_dirtyRegion.Reset();
	return region;
}

}
