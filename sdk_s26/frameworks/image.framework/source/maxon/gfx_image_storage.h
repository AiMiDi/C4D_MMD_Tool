#ifndef GFX_IMAGE_STORAGE_H__
#define GFX_IMAGE_STORAGE_H__

#include "maxon/gfx_image_pixelformat.h"
#include "maxon/gfx_image_colorprofile.h"
#include "maxon/gfx_image_pixelhandler.h"
#include "maxon/gfx_image_updateregion.h"


namespace maxon
{

class ImagePixelStorage;
class LayerSetInterface;

//----------------------------------------------------------------------------------------
/// Object that can store pixel data in a special layout (e.g. compact, plain, or tiles).
//----------------------------------------------------------------------------------------
class ImagePixelStorageInterface : MAXON_INTERFACE_BASES(ObjectInterface)
{
	MAXON_INTERFACE(ImagePixelStorageInterface, MAXON_REFERENCE_COPY_ON_WRITE, "net.maxon.image.interface.imagepixelstorage");

public:
	//----------------------------------------------------------------------------------------
	/// Initializes the pixel storage.
	/// @param[in] width							Width of the image data.
	/// @param[in] height							Height of the image data.
	/// @param[in] format							Pixel format of the pixel storage, e.g. ImagePixelStorageClasses::Normal.
	/// @param[in] defaultColor				Optional default color to return if no image data is present. Must be in the given PixelFormat. Can be nullptr.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> Init(Int width, Int height, const PixelFormat& format, const Block<Pix>* defaultColor);

	//----------------------------------------------------------------------------------------
	/// Returns the width of the pixel storage.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Int GetWidth() const;

	//----------------------------------------------------------------------------------------
	/// Returns the height of the pixel storage.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Int GetHeight() const;

	//----------------------------------------------------------------------------------------
	/// Returns the total number of channels of the pixel storage.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Int GetChannelCount() const;

	//----------------------------------------------------------------------------------------
	/// Returns the pixel format connected to this pixel storage.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD PixelFormat GetPixelFormat() const;

	//----------------------------------------------------------------------------------------
	/// To access pixel data a GetPixelHandlerStruct is needed. This optimizes the access to the pixel data see GetPixelHandlerStruct.
	/// @param[in] dstFormat					Destination pixel format that should be read with this pixel handler.
	/// @param[in] channelOffsets			Destination channel offset in bits.
	/// @param[in] srcColorProfile		Optional parameter which is only necessary if the color spaces of the given pixel formats doesn't match. In that case the conversion will be performed using the correct color conversion.
	/// @param[in] dstColorProfile		Optional parameter which is only necessary if the color spaces of the given pixel formats doesn't match. In that case the conversion will be performed using the correct color conversion.
	/// @param[in] flags							Flags for the GetPixel operation.
	/// @return												A valid GetPixelHandlerStruct struct if successful.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<GetPixelHandlerStruct> GetPixelHandler(const PixelFormat& dstFormat, const ChannelOffsets& channelOffsets, 
		const ColorProfile& srcColorProfile, const ColorProfile& dstColorProfile, GETPIXELHANDLERFLAGS flags) const;

	//----------------------------------------------------------------------------------------
	/// To access pixel data a SetPixelHandlerStruct is needed. This optimizes the access to the pixel data see SetPixelHandlerStruct.
	/// @param[in] srcFormat					Source pixel format that should be written with this pixel handler.
	/// @param[in] channelOffsets			Source channel offsets in bits.
	/// @param[in] srcColorProfile		Optional parameter which is only necessary if the color spaces of the given pixel formats doesn't match. In that case the conversion will be performed using the correct color conversion.
	/// @param[in] dstColorProfile		Optional parameter which is only necessary if the color spaces of the given pixel formats doesn't match. In that case the conversion will be performed using the correct color conversion.
	/// @param[in] flags							Flags for the SetPixel operation.
	/// @return												A valid SetPixelHandlerStruct struct if successful.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<SetPixelHandlerStruct> SetPixelHandler(const PixelFormat& srcFormat, const ChannelOffsets& channelOffsets,
		const ColorProfile& srcColorProfile, const ColorProfile& dstColorProfile, SETPIXELHANDLERFLAGS flags,
		const Delegate<void(const UpdateRegion&)>& updateRegionNotification);

	/// @cond INTERNAL

	//----------------------------------------------------------------------------------------
	/// Private.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD void FreePixelHandler(GetPixelHandlerStruct& pixel) const;

	//----------------------------------------------------------------------------------------
	/// Private.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD void FreePixelHandler(SetPixelHandlerStruct& pixel, const Delegate<void(const UpdateRegion&)>& updateRegionNotification) const;

	/// @endcond

	//----------------------------------------------------------------------------------------
	/// Access single components of the image.
	/// @param[in] component					Index of the component.
	/// @param[in] pos								ImagePos of the data to read.
	/// @param[in] data								Destination buffer.
	/// @param[in] inc								Distance between 2 pixels in the destination buffer.
	/// @param[in] flags							Flags to control the read operation.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> GetComponent(Int component, const ImagePos& pos, Pix* data, Int inc, GETPIXELFLAGS flags) const;

	//----------------------------------------------------------------------------------------
	/// Access single components of the image.
	/// @param[in] component					Index of the component.
	/// @param[in] pos								ImagePos of the data to write.
	/// @param[in] data								Source buffer.
	/// @param[in] inc								Distance between 2 pixels in the source buffer.
	/// @param[in] flags							Flags to control the write operation.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> SetComponent(Int component, const ImagePos& pos, const Pix* data, Int inc, SETPIXELFLAGS flags);
};

// include autogenerated headerfile here
#include "gfx_image_storage1.hxx"

MAXON_REGISTRY(Class<ImagePixelStorage>, ImagePixelStorageClasses, "net.maxon.image.registry.imagepixelstorageclasses");

namespace ImagePixelStorageClasses
{
	//----------------------------------------------------------------------------------------
	/// ImagePixelStorageClasses::NoData stores no data at all. It's a placeholder for ImageLayers which have no data but calculate the layer
	/// data on the fly.
	//----------------------------------------------------------------------------------------
	MAXON_DECLARATION(ImagePixelStorageClasses::EntryType, NoData, "net.maxon.image.imagepixelstorageclass.nodata");

	//----------------------------------------------------------------------------------------
	/// ImagePixelStorageClasses::Normal stores the image data in a interleaved way. E.g. if you have an RGB pixel format all pixels are
	/// stored in that order: R1, G1, B1, R2, G2, B2 ...
	/// The memory for the storage of the image data is one chunk with the size is: height * pixelFormat.GetBpl().
	//----------------------------------------------------------------------------------------
	MAXON_DECLARATION(ImagePixelStorageClasses::EntryType, Normal, "net.maxon.image.imagepixelstorageclass.normal");

	//----------------------------------------------------------------------------------------
	/// ImagePixelStorageClasses::Planes stores the image data channels in seperated planes. E.g. if you have an RGB pixel format all pixels are
	/// stored in that order: R1, R2, R3, R4 ... G1, G2, G3, G4 ... B1, B2, B3, B4 ...
	/// The memory for the storage of the image data is one chunk with the size is: height * pixelFormat.GetBpl().
	//----------------------------------------------------------------------------------------
	MAXON_DECLARATION(ImagePixelStorageClasses::EntryType, Planes, "net.maxon.image.imagepixelstorageclass.planes");

	//----------------------------------------------------------------------------------------
	/// ImagePixelStorageClasses::Voxel stores the image data channels in voxels of 64x64 pixels.
	/// This means that memory is only allocated where pixels are set.
	//----------------------------------------------------------------------------------------
	MAXON_DECLARATION(ImagePixelStorageClasses::EntryType, Voxel, "net.maxon.image.imagepixelstorageclass.voxel");
}

#include "gfx_image_storage2.hxx"

}


#endif // GFX_IMAGE_STORAGE_H__

