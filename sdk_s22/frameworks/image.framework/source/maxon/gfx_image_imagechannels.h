#ifndef GFX_IMAGE_IMAGECHANNELS_H__
#define GFX_IMAGE_IMAGECHANNELS_H__

#include "maxon/gfx_image_imagechannel.h"



namespace maxon
{


MAXON_REGISTRY(ImageChannelType, ImageChannelTypes, "net.maxon.image.registry.imagechanneltypes");

namespace ImageChannelTypes
{
	MAXON_DECLARATION(ImageChannelType, Red, "net.maxon.image.imagechanneltype.red");						///< red channel.
	MAXON_DECLARATION(ImageChannelType, Green, "net.maxon.image.imagechanneltype.green");				///< green channel.
	MAXON_DECLARATION(ImageChannelType, Blue, "net.maxon.image.imagechanneltype.blue");					///< blue channel.
	MAXON_DECLARATION(ImageChannelType, Grey, "net.maxon.image.imagechanneltype.grey");					///< grey channel.
	MAXON_DECLARATION(ImageChannelType, Alpha, "net.maxon.image.imagechanneltype.alpha");				///< alpha channel.

	MAXON_DECLARATION(ImageChannelType, CMYK_C, "net.maxon.image.imagechanneltype.cmyk_c");			///< cmyk c channel.
	MAXON_DECLARATION(ImageChannelType, CMYK_M, "net.maxon.image.imagechanneltype.cmyk_m");			///< cmyk m channel.
	MAXON_DECLARATION(ImageChannelType, CMYK_Y, "net.maxon.image.imagechanneltype.cmyk_y");			///< cmyk y channel.
	MAXON_DECLARATION(ImageChannelType, CMYK_K, "net.maxon.image.imagechanneltype.cmyk_k");			///< cmyk k channel.
	MAXON_DECLARATION(ImageChannelType, CMYK_iC, "net.maxon.image.imagechanneltype.cmyk_ic");		///< inverse cmyk c channel.
	MAXON_DECLARATION(ImageChannelType, CMYK_iM, "net.maxon.image.imagechanneltype.cmyk_im");		///< inverse cmyk m channel.
	MAXON_DECLARATION(ImageChannelType, CMYK_iY, "net.maxon.image.imagechanneltype.cmyk_iy");		///< inverse cmyk y channel.
	MAXON_DECLARATION(ImageChannelType, CMYK_iK, "net.maxon.image.imagechanneltype.cmyk_ik");		///< inverse cmyk k channel.

	MAXON_DECLARATION(ImageChannelType, Depth, "net.maxon.image.imagechanneltype.depth");				///< depth channel. This is the start value of the depth channel.
	MAXON_DECLARATION(ImageChannelType, DepthBack, "net.maxon.image.imagechanneltype.depthback"); ///< depth back channel (this is where the z buffer ends if it defined a volume together with Depth.

	MAXON_DECLARATION(ImageChannelType, MaterialId, "net.maxon.image.imagechanneltype.materialid");			///< MaterialId.
	MAXON_DECLARATION(ImageChannelType, NodeId, "net.maxon.image.imagechanneltype.nodeid");							///< NodeId.
	MAXON_DECLARATION(ImageChannelType, UvU, "net.maxon.image.imagechanneltype.uvu");										///< UV u value.
	MAXON_DECLARATION(ImageChannelType, UvV, "net.maxon.image.imagechanneltype.uvv");										///< UV v value.
	MAXON_DECLARATION(ImageChannelType, Normal, "net.maxon.image.imagechanneltype.normal");							///< Normal value.
	MAXON_DECLARATION(ImageChannelType, RealPix, "net.maxon.image.imagechanneltype.realpix");						///< RealPix value.
	MAXON_DECLARATION(ImageChannelType, Coverage, "net.maxon.image.imagechanneltype.coverage");					///< Coverage value.
	MAXON_DECLARATION(ImageChannelType, BG, "net.maxon.image.imagechanneltype.bg");											///< BG color value.
	MAXON_DECLARATION(ImageChannelType, NodeRenderId, "net.maxon.image.imagechanneltype.noderenderid");	///< NodeRenderId value.
	MAXON_DECLARATION(ImageChannelType, Transparency, "net.maxon.image.imagechanneltype.transparency");	///< Transparency value.
	MAXON_DECLARATION(ImageChannelType, Velocity, "net.maxon.image.imagechanneltype.velocity");					///< Velocity value.
	MAXON_DECLARATION(ImageChannelType, Weight, "net.maxon.image.imagechanneltype.weight");							///< Weight value.
	MAXON_DECLARATION(ImageChannelType, Mask, "net.maxon.image.imagechanneltype.mask");									///< Mask value.

	MAXON_DECLARATION(ImageChannelType, Unused, "net.maxon.image.imagechanneltype.unused");			///< unused channel. This could be the X for RGBX format
	MAXON_DECLARATION(ImageChannelType, Unknown, "net.maxon.image.imagechanneltype.unknown");		///< unknown channel.
}


/// @}

} // namespace maxon


#endif // GFX_IMAGE_IMAGECHANNELS_H__
