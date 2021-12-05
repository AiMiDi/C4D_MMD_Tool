#ifndef GFX_IMAGE_COLORSPACES_H__
#define GFX_IMAGE_COLORSPACES_H__

#include "maxon/gfx_image_colorspace.h"

namespace maxon
{

//----------------------------------------------------------------------------------------
/// Registry for color spaces.
//----------------------------------------------------------------------------------------
MAXON_REGISTRY(ColorSpace, ColorSpaces, "net.maxon.image.registry.colorspaces");

namespace ColorSpaces
{
	MAXON_DECLARATION(ColorSpace, RGBspace, "net.maxon.image.colorspace.rgb");
	MAXON_DECLARATION(ColorSpace, GREYspace, "net.maxon.image.colorspace.grey");
	MAXON_DECLARATION(ColorSpace, CMYKspace, "net.maxon.image.colorspace.cmyk");
	MAXON_DECLARATION(ColorSpace, YUVspace, "net.maxon.image.colorspace.yuv");
	MAXON_DECLARATION(ColorSpace, ALPHAspace, "net.maxon.image.colorspace.alpha");
}

}

#endif // GFX_IMAGE_COLORSPACES_H__
