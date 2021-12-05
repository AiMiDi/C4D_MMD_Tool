#ifndef GFX_IMAGE_H__
#define GFX_IMAGE_H__

#include "maxon/datadictionaryobject.h"
#include "maxon/fid.h"
#include "maxon/gfx_basictypes.h"
#include "maxon/gfx_image_pixelhandler.h"
#include "maxon/gfx_image_storage.h"
#include "maxon/gfx_image_updateregion.h"
#include "maxon/hierarchyobject.h"
#include "maxon/mediasession_session.h"
#include "maxon/object.h"
#include "maxon/url.h"
#include "maxon/vector.h"

namespace maxon
{

/// @addtogroup Graphics
/// @{

class ImagePixelBlend;
class ImagePixelStorage;
class ImageBaseRef;
class ImageRef;
class ImageTextureRef;
class ImageLayerRef;
class ImageLayerInterface;
class MediaOutputRef;
class MediaOutputUrlRef;
class AudioObjectRef;
class MediaSessionRef;
class ObserverObjectRef;
class LayerSetInterface;
enum class MEDIASESSIONFLAGS;

//----------------------------------------------------------------------------------------
/// Properties for Set/Get on ImageBaseInterface.
//----------------------------------------------------------------------------------------
namespace IMAGEPROPERTIES
{
	enum class ITYPE
	{
		UNDEFINED,
		TEXTURE,
		IMAGE,
		ALPHA,
		LAYER,
		LAYERMASK,
		FOLDER,
		ADJUSTMENT,
		DEEPIMAGEDATA,
	} MAXON_ENUM_LIST(ITYPE);

	MAXON_ATTRIBUTE(ITYPE, TYPE, "net.maxon.image.type");																///< type of the layer
	MAXON_ATTRIBUTE(String, NAME, "net.maxon.image.name");															///< Optional: Name of the texture/image/layer.
	MAXON_ATTRIBUTE(String, ALPHANAME, "net.maxon.image.alphaname");													///< Optional: Alpha Name of the texture/image/layer.

	namespace TEXTURE
	{
		MAXON_ATTRIBUTE(AudioObjectRef, AUDIODATA, "net.maxon.image.audiodata");									///< Optional: Audio data to write to the file
	}

	namespace IMAGE
	{
		MAXON_ATTRIBUTE(Float, ASPECTRATIO, "net.maxon.image.aspectratio", RESOURCE_DEFAULT(1.0));	///< Optional: Pixel Aspect Ratio of the texture/image/layer. You should get this value with a default of 1.0
		MAXON_ATTRIBUTE(Float, DPI, "net.maxon.image.dpi");																///< Optional: DPI (dots per inch) value.
		MAXON_ATTRIBUTE(ColorProfile, COLORPROFILE, "net.maxon.image.colorprofile");								///< Optional: Image color profile.
		MAXON_ATTRIBUTE(Float, FPS, "net.maxon.image.fps");																///< Optional: Movie: Average frames per second of the stream
		MAXON_ATTRIBUTE(TimeValue, DURATION, "net.maxon.image.duration");												///< Optional: Movie: Duration of the stream, TIMEVALUE_INFINITE is set if the stream is infinite
		MAXON_ATTRIBUTE(TimeValue, SAMPLETIME, "net.maxon.image.sampletime");											///< Optional: Movie: Time when the stream should be (dis-)played.
		MAXON_ATTRIBUTE(DataDictionary, EXPORTSETTINGS, "net.maxon.image.exportsettings");						///< Export: Custom export settings (see MEDIAEXPORTOPTIONS).
		MAXON_ATTRIBUTE(Int, HOTSPOTX, "net.maxon.image.hotspotx");															///< Optional: Hotspot x coordinate of a pointer/cursor.
		MAXON_ATTRIBUTE(Int, HOTSPOTY, "net.maxon.image.hotspoty");															///< Optional: Hotspot y coordinate of a pointer/cursor.
		MAXON_ATTRIBUTE(Int, SUBIMAGEINDEX, "net.maxon.image.subimageindex");										///< Optional: Sub-Image index of a multi-image file.
	}

	namespace LAYER
	{
		MAXON_ATTRIBUTE(Bool, ENABLED, "net.maxon.image.layer.enabled");											///< layer enabled (visible).
		MAXON_ATTRIBUTE(ImagePixelBlend, BLENDMODE, "net.maxon.image.layer.blendmode");				///< layer blend mode see MEDIAFORMATBLENDMODE.
		MAXON_ATTRIBUTE(Float, OPACITY, "net.maxon.image.layer.opacity");										///< layer opacity 0.0 ... 1.0
		MAXON_ATTRIBUTE(Float, FILLOPACITY, "net.maxon.image.layer.fillopacity");								///< layer fill opacity 0.0 ... 1.0
		MAXON_ATTRIBUTE(Bool, TRANSPARENCYPROTECTED, "net.maxon.image.layer.transparencyprotected");				///< true if layer transparency is protected
		MAXON_ATTRIBUTE(Int, LAYERGROUP, "net.maxon.image.layer.layergroup");										///< group id for grouped layers
		MAXON_ATTRIBUTE(Pix8u, MASKDEFCOLOR, "net.maxon.image.layer.maskdefcolor");								///< default mask color 0..255
		MAXON_ATTRIBUTE(Int, BOUNDINGBOX_X, "net.maxon.image.layer.boundingbox_x");								///< bounding box of the region with image content.
		MAXON_ATTRIBUTE(Int, BOUNDINGBOX_Y, "net.maxon.image.layer.boundingbox_y");								///< bounding box of the region with image content.
		MAXON_ATTRIBUTE(Int, BOUNDINGBOX_W, "net.maxon.image.layer.boundingbox_w");								///< bounding box of the region with image content.
		MAXON_ATTRIBUTE(Int, BOUNDINGBOX_H, "net.maxon.image.layer.boundingbox_h");								///< bounding box of the region with image content.

		namespace FOLDER
		{
			MAXON_ATTRIBUTE(Bool, ISOPEN, "net.maxon.image.layer.isopen");										///< true if the layer folder is opened in the ui
		}
		namespace ADJUSTMENT
		{
			MAXON_ATTRIBUTE(Int, PSD_FILTERID, "net.maxon.image.layer.psd_filterid");								///< adjustment layer filter id
			MAXON_ATTRIBUTE(BaseArray<Char>, PSD_DATA, "net.maxon.image.layer.psd_data");				///< adjustment layer data
		}
	}
}

//----------------------------------------------------------------------------------------
/// used by ImageBaseInterface to add layers/alphas/images to the right sub tree in the hierarchy.
//----------------------------------------------------------------------------------------
enum class IMAGEHIERARCHY
{
	TEXTURE,				///< Root of everything. Must not be used with AddChildren.
	IMAGE,					///< Adds a subImage to a texture. Images are only allowed under Textures.
	ALPHA,					///< Adds an alpha to a image. Alphas are allowed to insert under images.
	LAYER,					///< Adds an image layer to a image. Layers are only allowed under Images or other layers.
	MASK,						///< Adds a layer mask to a layer. Layer masks are allowed to insert under layers (layer mask).
	DEEPIMAGEDATA,	///< Adds deep image data to an image. Allowed to insert under images.
	MAX_ELEMENTS,
} MAXON_ENUM_LIST(IMAGEHIERARCHY);

struct ImageHierarchy
{
	using type = ImageBaseRef;
	template <typename I> using Sibling = ImageHierarchy;
	template <typename I> using Parent = ImageHierarchy;
	template <typename I> using Child = ImageHierarchy;
};

//----------------------------------------------------------------------------------------
/// Base class of all image classes. E.g. ImageLayerInterface, ImageTextureInterface inherits all this functions.
/// This base class is able to handle layers in hierarchical order.
//----------------------------------------------------------------------------------------
class ImageBaseInterface : MAXON_INTERFACE_BASES(DataDictionaryObjectInterface, HierarchyObjectInterface<ImageHierarchy>)
{
	MAXON_INTERFACE(ImageBaseInterface, MAXON_REFERENCE_NORMAL, "net.maxon.image.interface.imagebase");

public:
	//----------------------------------------------------------------------------------------
	/// Initializes the bitmap with a given size/height.
	/// The bitmap content is cleared with 0 bytes.
	/// @param[in] width							Image width.
	/// @param[in] height							Image height.
	/// @param[in] pixelFormat				Image PixelFormat.
	/// @param[in] type								Image type set into IMAGEPROPERTIES::TYPE. You can query this with image.Get(IMAGEPROPERTIES::TYPE).
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> InitBase(Int width, Int height, const PixelFormat& pixelFormat, IMAGEPROPERTIES::ITYPE type);

	//----------------------------------------------------------------------------------------
	/// @param[in] hierarchy					Defines the hierarchy to which the children belongs to.
	/// @param[in] newChildren				New children to add under this object.
	/// @param[in] insertBefore				Insert the children before this object. nullptr will append the object at the end.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> AddChildren(IMAGEHIERARCHY hierarchy, const ImageBaseRef& newChildren, const ImageBaseRef& insertBefore);

	//----------------------------------------------------------------------------------------
	/// Returns the width of the bitmap.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Int GetWidth() const;

	//----------------------------------------------------------------------------------------
	/// Returns the height of the bitmap.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Int GetHeight() const;

	//----------------------------------------------------------------------------------------
	/// Returns the channel count of the bitmap.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Int GetChannelCount() const;

	//----------------------------------------------------------------------------------------
	/// Returns the pixel format connected to this bitmap.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD PixelFormat GetPixelFormat() const;

	//----------------------------------------------------------------------------------------
	/// To access pixel data a GetPixelHandlerStruct is needed. This optimizes the access to the pixel data see GetPixelHandlerStruct.
	/// @param[in] dstFormat					Destination pixel format that should be read with this pixel handler.
	/// @param[in] channelOffsets			Destination channel offsets in bits.
	/// @param[in] dstColorProfile		Optional parameter which is only necessary if the color spaces of the given pixel formats doesn't match.
	/// 															In that case the conversion will be performed using the correct color conversion.
	/// @param[in] flags							Flags for the GetPixel operation.
	/// @param[in] layerSet						Optional LayerSet or nullptr.
	/// @return												A valid GetPixelHandlerStruct struct if successful.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<GetPixelHandlerStruct> GetPixelHandler(const PixelFormat& dstFormat, const ChannelOffsets& channelOffsets,
		const ColorProfile& dstColorProfile, GETPIXELHANDLERFLAGS flags, const LayerSetInterface* layerSet) const;

	//----------------------------------------------------------------------------------------
	/// To access pixel data a SetPixelHandlerStruct is needed. This optimizes the access to the pixel data see SetPixelHandlerStruct.
	/// @param[in] srcFormat					Source pixel format that should be written with this pixel handler.
	/// @param[in] channelOffsets			Source channel offsets in bits.
	/// @param[in] srcColorProfile		Optional parameter which is only necessary if the color spaces of the given pixel formats doesn't match.
	/// 															In that case the conversion will be performed using the correct color conversion.
	/// @param[in] flags							Flags for the SetPixel operation.
	/// @return												A valid SetPixelHandlerStruct struct if successful.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<SetPixelHandlerStruct> SetPixelHandler(const PixelFormat& srcFormat, const ChannelOffsets& channelOffsets,
		const ColorProfile& srcColorProfile, SETPIXELHANDLERFLAGS flags);

	/// @cond INTERNAL

	//----------------------------------------------------------------------------------------
	/// Private.
	// TODO: (Tilo) Please describe
	//----------------------------------------------------------------------------------------
	MAXON_METHOD void FreePixelHandler(GetPixelHandlerStruct& pixel) const;

	//----------------------------------------------------------------------------------------
	/// Private.
	// TODO: (Tilo) Please describe
	//----------------------------------------------------------------------------------------
	MAXON_METHOD void FreePixelHandler(SetPixelHandlerStruct& pixel) const;

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
	MAXON_METHOD Result<void> GetComponent(
		Int component, const ImagePos& pos, Pix* data, Int inc, GETPIXELFLAGS flags) const;

	//----------------------------------------------------------------------------------------
	/// Access single components of the image.
	/// @param[in] component					Index of the component.
	/// @param[in] pos								ImagePos of the data to write.
	/// @param[in] data								Source buffer.
	/// @param[in] inc								Distance between 2 pixels in the source buffer.
	/// @param[in] flags							Flags to control the write operation.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> SetComponent(
		Int component, const ImagePos& pos, const Pix* data, Int inc, SETPIXELFLAGS flags);

	//----------------------------------------------------------------------------------------
	/// Create a new ImageBaseRef as a sub image of the given image with the given rectangle.
	/// The image will not be copied! It generates only a reference to the original image with the rectangle set to the portion of the image.
	/// @param[in] rect								Part of the image.
	/// @return												New Image as part of the given image.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<ImageBaseRef> CreateSubImagePart(const DrawRectInt& rect) const;

	//----------------------------------------------------------------------------------------
	/// Observable: This observable is fired as soon as anybody modifies the pixel data of this object.
	//----------------------------------------------------------------------------------------
	MAXON_OBSERVABLE(void, ObservableRegionChanged, (const ObserverObjectRef& owner, const UpdateRegion& region), ObservableCombinerRunAllComponent);
};


//----------------------------------------------------------------------------------------
/// A Image texture represents a texture object with layers.
//----------------------------------------------------------------------------------------
class ImageTextureInterface : MAXON_INTERFACE_BASES(ImageBaseInterface)
{
	MAXON_INTERFACE(ImageTextureInterface, MAXON_REFERENCE_NORMAL, "net.maxon.image.interface.imagetexture");

public:
	//----------------------------------------------------------------------------------------
	/// Creates a new texture and loads the given url into this texture.
	/// @param[in] name								Url to load.
	/// @param[in] targetTime					Target time to receive the media samples from.
	/// @param[in] flags							See MEDIASESSIONFLAGS for details.
	/// @param[in] pixelStorageClass	Defines the storage class for all layers of the texture. See ImagePixelStorageClasses::
	/// @param[in] layerSet						Optional LayerSet or nullptr.
	/// @return												Return an instance to a MediaSessionRef for further reading if necessary.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<ImageTextureRef> LoadTexture(
		const Url& name, const TimeValue& targetTime = TimeValue(), MEDIASESSIONFLAGS flags = MEDIASESSIONFLAGS::NONE, 
		const Class<ImagePixelStorage>& pixelStorageClass = ImagePixelStorageClasses::Normal(), const LayerSetInterface* layerSet = nullptr);

	//----------------------------------------------------------------------------------------
	/// Loads a media into this texture.
	/// @param[in] url								Url to the media to load.
	/// @param[in] targetTime					Target time to receive the media samples from.
	/// @param[in] flags							See MEDIASESSIONFLAGS for details.
	/// @param[in] pixelStorageClass	Defines the storage class for all layers of the texture. See ImagePixelStorageClasses::
	/// @param[in] layerSet						Optional LayerSet or nullptr.
	/// @return												Return an instance to a MediaSessionRef for further reading if necessary.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<MediaSessionRef> Load(const Url& url, const TimeValue& targetTime, MEDIASESSIONFLAGS flags, 
		const Class<ImagePixelStorage>& pixelStorageClass = ImagePixelStorageClasses::Normal(), const LayerSetInterface* layerSet = nullptr);

	//----------------------------------------------------------------------------------------
	/// Saves this texture using the media session interface.
	/// @param[in] fileFormat					A ready to use MediaOutputRef which will be used as output node of the media session.
	/// @param[in] flags							See MEDIASESSIONFLAGS for details.
	/// @param[in] returnOpenSession	If nullptr the session will be closed directly. If a pointer to a MediaSessionRef is given the session will stay open. Don't forget session.Close() in that case.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> Save(
		const MediaOutputRef& fileFormat, MEDIASESSIONFLAGS flags, MediaSessionRef* returnOpenSession = nullptr) const;

	//----------------------------------------------------------------------------------------
	/// Saves this texture using the media session interface.
	/// This function simplifies the use of registered ImageSaverClasses from their registry.
	/// The usage is simple:
	/// @code
	/// imageTexture.Save(url, ImageSaverClasses::Bmp) iferr_return;
	/// @endcode
	/// @param[in] fileName						Url to write to.
	/// @param[in] fileFormat					A MediaOutputUrlRef which will be used as output node of the media session. MediaOutputUrlRef::SetOutputUrl will be called in this function to set the url.
	/// @param[in] flags							See MEDIASESSIONFLAGS for details.
	/// @param[in] returnOpenSession	If nullptr the session will be closed directly. If a pointer to a MediaSessionRef is given the session will stay open. Don't forget session.Close() in that case.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	MAXON_FUNCTION Result<void> Save(
		const Url& fileName, const MediaOutputUrlRef& fileFormat, MEDIASESSIONFLAGS flags, MediaSessionRef* returnOpenSession = nullptr) const;
};


//----------------------------------------------------------------------------------------
/// The ImageInterface represents a single image with a ImageTextureRef.
/// one or more Images can be part of a ImageTextureRef.
//----------------------------------------------------------------------------------------
class ImageInterface : MAXON_INTERFACE_BASES(ImageBaseInterface)
{
	MAXON_INTERFACE(ImageInterface, MAXON_REFERENCE_NORMAL, "net.maxon.image.interface.image");

public:
	//----------------------------------------------------------------------------------------
	/// Initializes the pixel storage.
	/// @param[in] width							Width of the image data.
	/// @param[in] height							Height of the image data.
	/// @param[in] storageFormat			Storage format of the pixel data.
	/// @param[in] pixelFormat				Pixel format of the pixel storage.
	/// @param[in] defaultColor				Optional default color to return if no image data is present. Must be in the given PixelFormat. Can be nullptr.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> Init(Int width, Int height, const Class<ImagePixelStorage>& storageFormat, const PixelFormat& pixelFormat, const Block<Pix>* defaultColor = nullptr);
};


//----------------------------------------------------------------------------------------
/// A Image layer represents a single layer within a image texture.
//----------------------------------------------------------------------------------------
class ImageLayerInterface : MAXON_INTERFACE_BASES(ImageInterface)
{
	MAXON_INTERFACE(ImageLayerInterface, MAXON_REFERENCE_NORMAL, "net.maxon.image.interface.imagelayer");

public:
};



//----------------------------------------------------------------------------------------
/// Helper functions for image classes.
//----------------------------------------------------------------------------------------
class ImageFunctionsInterface
{
	MAXON_INTERFACE_NONVIRTUAL(ImageFunctionsInterface, MAXON_REFERENCE_NONE, "net.maxon.image.interface.imagefunctions");

public:
	//----------------------------------------------------------------------------------------
	/// Create a new ImageBaseRef as a sub image of the given image with the given rectangle.
	/// The image will not be copied! It generates only a reference to the original image with the rectangle set to the portion of the image.
	/// @param[in] imageRef						Image to be referenced.
	/// @param[in] rect								Part of the image.
	/// @return												New Image as part of the given image.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<ImageBaseRef> CreateSubImagePart(const ImageBaseRef& imageRef, const DrawRectInt& rect);
};


// include autogenerated headerfile here
#include "gfx_image1.hxx"

MAXON_REGISTRY(Class<ImageBaseRef>, ImageBaseClasses, "net.maxon.image.registry.imagebaseclasses");
MAXON_REGISTRY(Class<ImageTextureRef>, ImageTextureClasses, "net.maxon.image.registry.imagetextureclasses");
MAXON_REGISTRY(Class<ImageRef>, ImageClasses, "net.maxon.image.registry.imageclasses");
MAXON_REGISTRY(Class<ImageLayerRef>, ImageLayerClasses, "net.maxon.image.registry.imagelayerclasses");

namespace ImageBaseClasses
{
	MAXON_DECLARATION(ImageBaseClasses::EntryType, BASE, "net.maxon.image.imagebaseclass.base");
}

namespace ImageTextureClasses
{
	MAXON_DECLARATION(ImageTextureClasses::EntryType, TEXTURE, "net.maxon.image.imagetextureclass.texture");
}

namespace ImageClasses
{
	MAXON_DECLARATION(ImageClasses::EntryType, IMAGE, "net.maxon.image.imageclass.image");
}

namespace ImageLayerClasses
{
	MAXON_DECLARATION(ImageLayerClasses::EntryType, RASTER, "net.maxon.image.imagelayerclass.raster");
}

// include autogenerated headerfile here
#include "gfx_image2.hxx"

//----------------------------------------------------------------------------------------
/// GetImageOf extracts the first image in a texture or if bmp is already a bmp itself.
/// @param[in] bmp								ImageBaseRef of type texture or image.
/// @return												ImageRef pointing the the first image of a texture or itself if it was a texture.
//----------------------------------------------------------------------------------------
ImageRef GetImageOf(const ImageBaseRef &bmp);

//----------------------------------------------------------------------------------------
/// GetFirstAlphaOf returns the alpha channel of a texture or image.
/// @param[in] bmp								Texture or image.
/// @return												Alpha channel on success.
//----------------------------------------------------------------------------------------
ImageLayerRef GetFirstAlphaOf(const ImageBaseRef &bmp);

/// @}

} // namespace maxon


#endif // GFX_IMAGE_H__
