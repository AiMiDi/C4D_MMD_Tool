#ifndef GFX_IMAGE_UPDATEREGION_H__
#define GFX_IMAGE_UPDATEREGION_H__

#include "maxon/observable.h"
#include "maxon/range.h"
#include "maxon/vector2d.h"


namespace maxon
{

//----------------------------------------------------------------------------------------
/// Typedef for a Update Region which contains the boundary of a modified range of pixels.
//----------------------------------------------------------------------------------------
using UpdateRegion = Range<IntVector2d>;

MAXON_DATATYPE(UpdateRegion, "net.maxon.image.updateregion");

class ImageBaseRef;

class UpdateRegionObserver
{
public:
	Result<void> AddObserver(const ImageBaseRef& image);
	Range<IntVector2d> GetRegionAndReset();

private:
	FunctionBaseRef _observer;
	UpdateRegion _dirtyRegion;
};

#include "gfx_image_updateregion1.hxx"
#include "gfx_image_updateregion2.hxx"

}
#endif // GFX_IMAGE_UPDATEREGION_H__
