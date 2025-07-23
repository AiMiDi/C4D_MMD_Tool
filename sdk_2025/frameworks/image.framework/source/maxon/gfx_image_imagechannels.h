#ifndef GFX_IMAGE_IMAGECHANNELS_H__
#define GFX_IMAGE_IMAGECHANNELS_H__

#include "maxon/gfx_image_imagechannel.h"



namespace maxon
{


MAXON_REGISTRY(ImageChannelType, ImageChannelTypes, "net.maxon.image.registry.imagechanneltypes");

namespace ImageChannelTypes
{
	MAXON_DECLARATION(ImageChannelType, Red, "net.maxon.image.imagechanneltype.red", MAXON_IMPLEMENTATION_MODULE("net.maxon.image"));						///< red channel.
	MAXON_DECLARATION(ImageChannelType, Green, "net.maxon.image.imagechanneltype.green", MAXON_IMPLEMENTATION_MODULE("net.maxon.image"));				///< green channel.
	MAXON_DECLARATION(ImageChannelType, Blue, "net.maxon.image.imagechanneltype.blue", MAXON_IMPLEMENTATION_MODULE("net.maxon.image"));					///< blue channel.
	MAXON_DECLARATION(ImageChannelType, Grey, "net.maxon.image.imagechanneltype.grey", MAXON_IMPLEMENTATION_MODULE("net.maxon.image"));					///< grey channel.
	MAXON_DECLARATION(ImageChannelType, Alpha, "net.maxon.image.imagechanneltype.alpha", MAXON_IMPLEMENTATION_MODULE("net.maxon.image"));				///< alpha channel.

	MAXON_DECLARATION(ImageChannelType, CMYK_C, "net.maxon.image.imagechanneltype.cmyk_c", MAXON_IMPLEMENTATION_MODULE("net.maxon.image"));			///< cmyk c channel.
	MAXON_DECLARATION(ImageChannelType, CMYK_M, "net.maxon.image.imagechanneltype.cmyk_m", MAXON_IMPLEMENTATION_MODULE("net.maxon.image"));			///< cmyk m channel.
	MAXON_DECLARATION(ImageChannelType, CMYK_Y, "net.maxon.image.imagechanneltype.cmyk_y", MAXON_IMPLEMENTATION_MODULE("net.maxon.image"));			///< cmyk y channel.
	MAXON_DECLARATION(ImageChannelType, CMYK_K, "net.maxon.image.imagechanneltype.cmyk_k", MAXON_IMPLEMENTATION_MODULE("net.maxon.image"));			///< cmyk k channel.
	MAXON_DECLARATION(ImageChannelType, CMYK_iC, "net.maxon.image.imagechanneltype.cmyk_ic", MAXON_IMPLEMENTATION_MODULE("net.maxon.image"));		///< inverse cmyk c channel.
	MAXON_DECLARATION(ImageChannelType, CMYK_iM, "net.maxon.image.imagechanneltype.cmyk_im", MAXON_IMPLEMENTATION_MODULE("net.maxon.image"));		///< inverse cmyk m channel.
	MAXON_DECLARATION(ImageChannelType, CMYK_iY, "net.maxon.image.imagechanneltype.cmyk_iy", MAXON_IMPLEMENTATION_MODULE("net.maxon.image"));		///< inverse cmyk y channel.
	MAXON_DECLARATION(ImageChannelType, CMYK_iK, "net.maxon.image.imagechanneltype.cmyk_ik", MAXON_IMPLEMENTATION_MODULE("net.maxon.image"));		///< inverse cmyk k channel.

	MAXON_DECLARATION(ImageChannelType, Depth, "net.maxon.image.imagechanneltype.depth", MAXON_IMPLEMENTATION_MODULE("net.maxon.image"));				///< depth channel. This is the start value of the depth channel.
	MAXON_DECLARATION(ImageChannelType, DepthBack, "net.maxon.image.imagechanneltype.depthback", MAXON_IMPLEMENTATION_MODULE("net.maxon.image")); ///< depth back channel (this is where the z buffer ends if it defined a volume together with Depth.

	MAXON_DECLARATION(ImageChannelType, MaterialId, "net.maxon.image.imagechanneltype.materialid", MAXON_IMPLEMENTATION_MODULE("net.maxon.image"));			///< MaterialId.
	MAXON_DECLARATION(ImageChannelType, NodeId, "net.maxon.image.imagechanneltype.nodeid", MAXON_IMPLEMENTATION_MODULE("net.maxon.image"));							///< NodeId.
	MAXON_DECLARATION(ImageChannelType, UvU, "net.maxon.image.imagechanneltype.uvu", MAXON_IMPLEMENTATION_MODULE("net.maxon.image"));										///< UV u value.
	MAXON_DECLARATION(ImageChannelType, UvV, "net.maxon.image.imagechanneltype.uvv", MAXON_IMPLEMENTATION_MODULE("net.maxon.image"));										///< UV v value.
	MAXON_DECLARATION(ImageChannelType, Normal, "net.maxon.image.imagechanneltype.normal", MAXON_IMPLEMENTATION_MODULE("net.maxon.image"));							///< Normal value.
	MAXON_DECLARATION(ImageChannelType, RealPix, "net.maxon.image.imagechanneltype.realpix", MAXON_IMPLEMENTATION_MODULE("net.maxon.image"));						///< RealPix value.
	MAXON_DECLARATION(ImageChannelType, Coverage, "net.maxon.image.imagechanneltype.coverage", MAXON_IMPLEMENTATION_MODULE("net.maxon.image"));					///< Coverage value.
	MAXON_DECLARATION(ImageChannelType, BG, "net.maxon.image.imagechanneltype.bg", MAXON_IMPLEMENTATION_MODULE("net.maxon.image"));											///< BG color value.
	MAXON_DECLARATION(ImageChannelType, NodeRenderId, "net.maxon.image.imagechanneltype.noderenderid", MAXON_IMPLEMENTATION_MODULE("net.maxon.image"));	///< NodeRenderId value.
	MAXON_DECLARATION(ImageChannelType, Transparency, "net.maxon.image.imagechanneltype.transparency", MAXON_IMPLEMENTATION_MODULE("net.maxon.image"));	///< Transparency value.
	MAXON_DECLARATION(ImageChannelType, Velocity, "net.maxon.image.imagechanneltype.velocity", MAXON_IMPLEMENTATION_MODULE("net.maxon.image"));					///< Velocity value.
	MAXON_DECLARATION(ImageChannelType, Weight, "net.maxon.image.imagechanneltype.weight", MAXON_IMPLEMENTATION_MODULE("net.maxon.image"));							///< Weight value.
	MAXON_DECLARATION(ImageChannelType, Mask, "net.maxon.image.imagechanneltype.mask", MAXON_IMPLEMENTATION_MODULE("net.maxon.image"));									///< Mask value.

	MAXON_DECLARATION(ImageChannelType, Unused, "net.maxon.image.imagechanneltype.unused", MAXON_IMPLEMENTATION_MODULE("net.maxon.image"));			///< unused channel. This could be the X for RGBX format
	MAXON_DECLARATION(ImageChannelType, Unknown, "net.maxon.image.imagechanneltype.unknown", MAXON_IMPLEMENTATION_MODULE("net.maxon.image"));		///< unknown channel.
}


/// @}

} // namespace maxon


#endif // GFX_IMAGE_IMAGECHANNELS_H__
