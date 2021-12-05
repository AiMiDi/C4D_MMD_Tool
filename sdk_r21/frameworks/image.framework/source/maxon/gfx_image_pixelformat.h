#ifndef GFX_IMAGE_PIXELFORMAT_H__
#define GFX_IMAGE_PIXELFORMAT_H__

#include "maxon/objectbase.h"
#include "maxon/gfx_image_bits.h"
#include "maxon/gfx_image_colorspace.h"
#include "maxon/gfx_image_imagechannel.h"

namespace maxon
{

/// @addtogroup Graphics
/// @{

class ColorProfile;
class PixelFormat;
class PixelFormatGroup;
class PixelFormatIterator;

//----------------------------------------------------------------------------------------
/// ChannelOffsets describe the offset of each channel of a pixel format.
/// There is always one channel more than the channel count. This last value contains usually the total size.
//----------------------------------------------------------------------------------------
using ChannelOffsets = Block<const BITS>;

//----------------------------------------------------------------------------------------
/// Flags to control the GetPixel functions.
//----------------------------------------------------------------------------------------
enum class CONVERTPIXELFLAGS
{
	NONE													= 0,				///< no options set.
	FORCECOLORPROFILECONVERSION		= (1 << 0),	///< if set it forces color profile conversion even if the color space are identical, otherwise the conversion will be performed only if the color spaces are different.
} MAXON_ENUM_FLAGS(CONVERTPIXELFLAGS);

//----------------------------------------------------------------------------------------
/// Flags to control the GetPixelHandler functions.
//----------------------------------------------------------------------------------------
enum class GETPIXELHANDLERFLAGS
{
	NONE,																		///< no options set.
	FORCECOLORPROFILECONVERSION = (1 << 0), ///< if set it forces color profile conversion even if the color space are identical, otherwise
																					///< the conversion will be performed only if the color spaces are different.
	DEEPIMAGE = (1 << 1),										///< request a deep image pixel handler.
	DONTAPPLYMASK = (1 << 2),								///< do not apply the alpha layer to the image data.
} MAXON_ENUM_FLAGS(GETPIXELHANDLERFLAGS);


//----------------------------------------------------------------------------------------
/// Flags to control the GetPixel functions.
//----------------------------------------------------------------------------------------
enum class GETPIXELFLAGS
{
	NONE,									///< no options set.
	DEEPIMAGE = (1 << 1), ///< provided a DeepImageConst/MutableBuffer structure.
} MAXON_ENUM_FLAGS(GETPIXELFLAGS);



//----------------------------------------------------------------------------------------
/// Flags to control the SetPixelHandler functions.
//----------------------------------------------------------------------------------------
enum class SETPIXELHANDLERFLAGS
{
	/// No options set.
	NONE = 0,
	FORCECOLORPROFILECONVERSION = (1 << 0), ///< if set it forces color profile conversion even if the color space are identical, otherwise
																					///< the conversion will be performed only if the color spaces are different.
	DEEPIMAGE = (1 << 1),										///< request a deep image pixel handler.
} MAXON_ENUM_FLAGS(SETPIXELHANDLERFLAGS);

//----------------------------------------------------------------------------------------
/// Flags to control the SetPixel functions.
//----------------------------------------------------------------------------------------
enum class SETPIXELFLAGS
{
	NONE = 0,							///< No options set.
	DEEPIMAGE = (1 << 1), ///< provided a DeepImagePixelConst/MutableBuffer.
} MAXON_ENUM_FLAGS(SETPIXELFLAGS);



//----------------------------------------------------------------------------------------
/// Several functions use this helper structure to pass the image data to functions.
//----------------------------------------------------------------------------------------
struct PixelConstBuffer
{
public:
	using PIXELTYPE = const Pix;

	PixelConstBuffer() = default;

	//----------------------------------------------------------------------------------------
	/// Copy constructor.
	//----------------------------------------------------------------------------------------
	PixelConstBuffer(const PixelConstBuffer& src) : _buffer(src._buffer), _inc(src._inc)
	{
	}

	//----------------------------------------------------------------------------------------
	/// Copy constructor with alignment.
	//----------------------------------------------------------------------------------------
	PixelConstBuffer(const PixelConstBuffer& src, Int offset) : _buffer(src._buffer + offset), _inc(src._inc)
	{
	}

	//----------------------------------------------------------------------------------------
	/// Constructs the helper object.
	/// @param[in] buffer							Pointer to the memory block of the pixel data.
	/// @param[in] inc								Distance in number of bytes from one pixel to the next. For packed pixels this value is equal to BytesPerPixel().
	//----------------------------------------------------------------------------------------
	PixelConstBuffer(const Pix* buffer, BITS inc) : _buffer(buffer), _inc(inc)
	{
	}

	PixelConstBuffer& operator = (const PixelConstBuffer& src)
	{
		this->~PixelConstBuffer();
		new (this) PixelConstBuffer(src);
		return *this;
	}

public:
	const Pix* _buffer = nullptr;
	BITS			 _inc;
};



//----------------------------------------------------------------------------------------
/// Several functions use this helper structure to pass the image data to functions.
//----------------------------------------------------------------------------------------
struct PixelMutableBuffer
{
public:
	using PIXELTYPE = Pix;

	PixelMutableBuffer() = default;

	//----------------------------------------------------------------------------------------
	/// Copy constructor.
	//----------------------------------------------------------------------------------------
	PixelMutableBuffer(const PixelMutableBuffer& src) : _buffer(src._buffer), _inc(src._inc)
	{
	}

	//----------------------------------------------------------------------------------------
	/// Copy constructor with alignment.
	//----------------------------------------------------------------------------------------
	PixelMutableBuffer(const PixelMutableBuffer& src, Int offset) : _buffer(src._buffer + offset), _inc(src._inc)
	{
	}

	//----------------------------------------------------------------------------------------
	/// Constructs the helper object.
	/// @param[in] buffer							Pointer to the memory block of the pixel data.
	/// @param[in] inc								Distance in number of bytes from one pixel to the next. For packed pixels this value is equal to BytesPerPixel().
	//----------------------------------------------------------------------------------------
	PixelMutableBuffer(Pix* buffer, BITS inc) : _buffer(buffer), _inc(inc)
	{
	}

	PixelMutableBuffer& operator = (const PixelMutableBuffer& src)
	{
		this->~PixelMutableBuffer();
		new (this) PixelMutableBuffer(src);
		return *this;
	}

	operator const PixelConstBuffer& () const
	{
		return reinterpret_cast<const PixelConstBuffer&>(*this);
	}

public:
	Pix* _buffer = nullptr;
	BITS _inc;
};



template <typename BASECLASS> struct ImageBufferTemplate;
using ImageConstBuffer = ImageBufferTemplate<PixelConstBuffer>;
using ImageMutableBuffer = ImageBufferTemplate<PixelMutableBuffer>;


using CONVERTPIXELFUNC = Delegate<Result<void>(const PixelMutableBuffer& dst, Int count, const PixelConstBuffer& src, GETPIXELFLAGS flags)>;


using CONVERTPIXELFUNCSTATIC = Result<void>(*)(const PixelMutableBuffer& dst, Int count, const PixelConstBuffer& src, GETPIXELFLAGS flags, const ChannelOffsets& dstChannelOffset, const ChannelOffsets& srcChannelOffset);


struct ConvertFuncChannelHelper
{
public:
	BaseArray<BITS> _srcChannelOffsetArray, _dstChannelOffsetArray;
	Block<BITS> _srcChannelOffsets, _dstChannelOffsets;

	Result<void> Init(const ChannelOffsets& dstChannelOffset, const ChannelOffsets& srcChannelOffset)
	{
		iferr_scope;

		_srcChannelOffsetArray.CopyFrom(srcChannelOffset) iferr_return;
		_dstChannelOffsetArray.CopyFrom(dstChannelOffset) iferr_return;

		_srcChannelOffsets = _srcChannelOffsetArray.ToBlock();
		_dstChannelOffsets = _dstChannelOffsetArray.ToBlock();

		return OK;
	}
};

using ConvertFuncChannelHelperRef = StrongRef<ConvertFuncChannelHelper>;



inline Result<CONVERTPIXELFUNC> LambdaWrapper(CONVERTPIXELFUNCSTATIC func, const ChannelOffsets& dstChannelOffsets, const ChannelOffsets& srcChannelOffsets)
{
	iferr_scope;

	// this is important: the offsets needs to be copied into the lambda.
	// otherwise the references are later lost.
	// the helper needs to be copied into the lambda as well!
	ConvertFuncChannelHelperRef helper = NewObj(ConvertFuncChannelHelper) iferr_return;
	helper->Init(dstChannelOffsets, srcChannelOffsets) iferr_return;

	const ChannelOffsets& dstChannelOffsetsI = helper->_dstChannelOffsets;
	const ChannelOffsets& srcChannelOffsetsI = helper->_srcChannelOffsets;

	CONVERTPIXELFUNC f;
	f.CopyFrom(
		[func, helper, dstChannelOffsetsI, srcChannelOffsetsI](const PixelMutableBuffer& dst, Int count, const PixelConstBuffer& src, GETPIXELFLAGS flags) -> Result<void>
		{
			return func(dst, count, src, flags, dstChannelOffsetsI, srcChannelOffsetsI);
		}) iferr_return;

	return std::move(f);
}


class PixelFormatIterator;


//----------------------------------------------------------------------------------------
/// Every pixel format belongs to a specific group. This interface define this group.
/// The group should define a general pixel format, e.g. RGB or BGRA etc. All the different implementations for different bit depths should
/// be grouped under that group.
//----------------------------------------------------------------------------------------
class PixelFormatGroupInterface : MAXON_INTERFACE_BASES(ObjectInterface)
{
	MAXON_INTERFACE(PixelFormatGroupInterface, MAXON_REFERENCE_CONST, "net.maxon.image.interface.pixelformatgroup");

public:
	MAXON_METHOD PixelFormatIterator GetEntries() const;
};

//----------------------------------------------------------------------------------------
/// This class handles image pixel formats.
/// Each pixel format should has it's own implementation. The memory layout of different pixels is free.
/// This class offers functions to convert from and to other pixel formats.
///
/// This interface has only const functions and will not change it's pointers.
/// That's why it's possible to compare PixelFormats by comparing the pointers.
/// The PixelFormats registry provides all registered pixel formats.
///
/// One exception is the PixelFormatIndexedColor. It allows to set a color table
/// so this breaks the link and the object is no longer comparable by the pointer.
/// In that case use Cast<PixelFormatIndexedColor>(pixelFormat) to check whether it's this type or not.
//----------------------------------------------------------------------------------------
class PixelFormatInterface : MAXON_INTERFACE_BASES(ObjectInterface)
{
	MAXON_INTERFACE(PixelFormatInterface, MAXON_REFERENCE_COPY_ON_WRITE, "net.maxon.image.interface.pixelformat");

public:
	//----------------------------------------------------------------------------------------
	/// Private.
	/// @param[in] group							TODO: (Tilo) please document
	/// @param[in] shortName					Short name of the color format for diagnostic outputs.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> Init(const PixelFormatGroup& group, const Char* shortName);

	//----------------------------------------------------------------------------------------
	/// Returns a description of all the channels of this pixel format.
	/// @return												Block with the description of all channels.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Block<const ImageChannel> GetChannels() const;

	//----------------------------------------------------------------------------------------
	/// Returns the corresponding PixelFormatGroup
	//----------------------------------------------------------------------------------------
	MAXON_METHOD const PixelFormatGroup& GetPixelFormatGroup() const;

	//----------------------------------------------------------------------------------------
	/// Allocates a buffer for a rectangle of pixels of this PixelFormat.
	/// @param[in] width							Width of the rectangle.
	/// @param[in] height							Height of the rectangle.
	/// @param[in] lineAlignment			Alignment for each line. E.g. 4 means that each line is aligned to a byte count of 4.
	/// @return												Pointer to a memory block with the given size. You must free the memory using DeleteMem.
	/// 															You can access the Pixels by (pointer + yPos * GetBytesPerLine(width, lineAlignment) + GetBitsPerPixel().GetOffset(xPos)).
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<Pix*> CreatePix(Int width, Int height, Int lineAlignment = 1) const;

	template <typename TYPE> MAXON_FUNCTION Result<TYPE*> CreatePix(Int width, Int height, Int lineAlignment = 1) const
	{
		iferr_scope;
		Pix* pix = CreatePix(width, height, lineAlignment) iferr_return;
		return (TYPE*)pix;
	}

	//----------------------------------------------------------------------------------------
	/// Returns the number of channels of the pixel format. E.g. RGB8i returns 3 for the 3 channels R, G and B.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Int GetChannelCount() const;

	//----------------------------------------------------------------------------------------
	/// Returns the offset in bits of each channel. The block is one element bigger then the channel count. offsets[GetChannelCount()] is
	/// identical to GetBitsPerPixel().
	//----------------------------------------------------------------------------------------
	MAXON_METHOD const ChannelOffsets& GetChannelOffsets() const;

	//----------------------------------------------------------------------------------------
	/// Returns the size in bits of each pixel (the sum of all channels).
	//----------------------------------------------------------------------------------------
	MAXON_METHOD BITS GetBitsPerPixel() const;

	//----------------------------------------------------------------------------------------
	/// Returns the number of bytes for a line with the given lineAlignment.
	/// @param[in] width							Number of Pixels.
	/// @param[in] lineAlignment			Value to which a line should be aligned to (e.g. 4 would align the memory to Int32 borders).
	/// @return												The number of bytes for the requested number of bytes with the given alignment.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Int GetBytesPerLine(Int width, Int lineAlignment) const;

	//----------------------------------------------------------------------------------------
	/// Returns the number of pixels that are packed together within this image format.
	/// This means that it's not possible to access chunks with smaller pixel counts than this value.
	/// e.g. yuv encoding packs 2 pixels into 4 bytes (Y0U0Y1V1) but the u and v value is the same for both pixels.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Int GetPackedPixelCount() const;

	//----------------------------------------------------------------------------------------
	/// Returns true if the pixel format supports alpha.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Bool HasAlpha() const;

	//----------------------------------------------------------------------------------------
	/// Returns the alpha pixel format (PixelFormats::ALPHA::U8/GREY16I/GREY32F/GREY64F) if a alpha channel is present.
	/// The return value contains a Tuple with the alpha pixel format as first and the byteoffset as the 2nd parameter.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<Tuple<PixelFormat, Int>> GetAlphaPixelFormat() const;

	//----------------------------------------------------------------------------------------
	/// Returns the color space used by the pixel format.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD ColorSpace GetColorSpace() const;

	//----------------------------------------------------------------------------------------
	/// Returns the default color space
	//----------------------------------------------------------------------------------------
	MAXON_METHOD const ColorProfile& GetDefaultColorProfile() const;

	//----------------------------------------------------------------------------------------
	/// Creates a CONVERTPIXELFUNC which is able to convert from a given srcFormatPtr to the own pixel format.
	/// The function builds dynamic code which converts the 2 pixel formats effectively from one into the other.
	/// This function is slow and should be cached. It uses spin locks internally.
	/// @param[in] srcFormatPtr				The pixel format to convert from.
	/// @param[in] srcChannelOffset		Channel offset in bytes of the src pixel format.
	/// @param[in] dstChannelOffset		Channel offset in bytes of the destination (own) pixel format.
	/// @param[in] srcColorProfile		Optional parameter which is only necessary if the color spaces of the given pixel formats doesn't match. In that case the conversion will be performed using the correct color conversion.
	/// @param[in,out] dstColorProfile	Optional parameter which is only necessary if the color spaces of the given pixel formats doesn't match. In that case the conversion will be performed using the correct color conversion.
	/// 															Returns the effective destination color profile after the conversion is applied.
	/// 															If the color space of the source and dest pixel format is identical no color profile conversion is performed and the result is srcColorProfile.
	/// 															If the color spaces are different the resulting color profile is the same as dstColorProfile.
	/// @param[in] forceColorProfileConversion	True to force the color profile conversion even is the color space is identical, false will not perform color profile transformation if the color space is identical.
	/// @param[out] disableCaching		Set to true if the conversion must not be cached (e.g. because a color table is used like in the indexed pixel format). Otherwise let the value unchanged!
	/// @return												Closure to call directly to convert from one format to the other. This closure is only valid for the given channel offsets of both formats.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<CONVERTPIXELFUNC> GetConvertPixelFunc(const PixelFormat& srcFormatPtr, const ChannelOffsets& srcChannelOffset,
		const ChannelOffsets& dstChannelOffset, const ColorProfile& srcColorProfile, ColorProfile* dstColorProfile,
		Bool forceColorProfileConversion, Bool& disableCaching) const;

	//----------------------------------------------------------------------------------------
	/// Converts Pixels from one format into another. This is a convenience function.
	/// This function is not as fast pixelFormat.GetConvertPixelFunc() followed by calls of the returned closure.
	/// @param[in] dst								ImageMutableBuffer of the destination data/format.
	/// @param[in] count							Number of pixels to convert.
	/// @param[in] src								ImageConstBuffer of the source data/format.
	/// @param[in] srcColorProfile		Optional parameter which is only necessary if the color spaces of the given pixel formats doesn't match. In that case the conversion will be performed using the correct color conversion.
	/// @param[in,out] dstColorProfile	Optional parameter which is only necessary if the color spaces of the given pixel formats doesn't match. In that case the conversion will be performed using the correct color conversion.
	/// 															Returns the effective destination color profile after the conversion is applied.
	/// 															If the color space of the source and dest pixel format is identical no color profile conversion is performed and the result is srcColorProfile.
	/// 															If the color spaces are different the resulting color profile is the same as dstColorProfile.
	/// @param[in] cflags							Flags to control the conversion. See CONVERTPIXELFLAGS.
	/// @param[in] flags							Flags to control the conversion. See GETPIXELFLAGS;.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> ConvertPixelFromSlow(const ImageMutableBuffer& dst, Int count, const ImageConstBuffer& src, const ColorProfile& srcColorProfile, ColorProfile* dstColorProfile, CONVERTPIXELFLAGS cflags, GETPIXELFLAGS flags) const;

	//----------------------------------------------------------------------------------------
	/// Compares 2 pixels. Both pixels must be in the same pixel format!
	/// @param[in] a									ImageConstBuffer pointing to the first pixel.
	/// @param[in] b									ImageConstBuffer pointing to the second pixel.
	/// @param[in] oneTolerance				True if a tolerance of one digit is allowed. Tolerances can happen when converting from formats with different resolutions.
	/// @return												True if the pixels are identical.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Bool IsIdenticalPixel(const ImageConstBuffer& a, const ImageConstBuffer& b, Int oneTolerance) const;

	//----------------------------------------------------------------------------------------
	/// Converts a pixel into a readable format.
	/// @param[in] src								Pointer to the data of one packed pixel.
	/// @return												String representation of the pixel.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD String PixToString(const Pix* src) const;

	//----------------------------------------------------------------------------------------
	/// for overloading in your own implementation. do not call from outside!
	/// @param[in] srcFormatPtr				TODO: (Tilo) please document
	/// @param[in] srcChannelOffset		TODO: (Tilo) please document
	/// @param[in] dstChannelOffset		TODO: (Tilo) please document
	/// @param[in] fastSize						TODO: (Tilo) please document
	/// @param[out] disableCaching		Set to true if the conversion must not be cached (e.g. because a color table is used like in the indexed pixel format). Otherwise let the value unchanged!
	/// @return												Conversion function or nullptr if no conversion found. An error will only be returned in case of a real error (out of memory etc).
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<CONVERTPIXELFUNC> GetConvertPixelFromFunc(const PixelFormat& srcFormatPtr, const ChannelOffsets& srcChannelOffset, const ChannelOffsets& dstChannelOffset, Bool fastSize, Bool& disableCaching) const;

	//----------------------------------------------------------------------------------------
	/// for overloading in your own implementation. do not call from outside!
	/// @param[in] dstFormatPtr				TODO: (Tilo) please document
	/// @param[in] dstChannelOffset		TODO: (Tilo) please document
	/// @param[in] srcChannelOffset		TODO: (Tilo) please document
	/// @param[in] fastSize						TODO: (Tilo) please document
	/// @param[out] disableCaching		Set to true if the conversion must not be cached (e.g. because a color table is used like in the indexed pixel format). Otherwise let the value unchanged!
	/// @return												Conversion function or nullptr if no conversion found. An error will only be returned in case of a real error (out of memory etc.).
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<CONVERTPIXELFUNC> GetConvertPixelToFunc(const PixelFormat& dstFormatPtr, const ChannelOffsets& dstChannelOffset, const ChannelOffsets& srcChannelOffset, Bool fastSize, Bool& disableCaching) const;

	//----------------------------------------------------------------------------------------
	/// Returns the short name set in the init function.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD const Char* GetShortName() const;
};


//----------------------------------------------------------------------------------------
/// PixelFormatIndexedColorInterface extends the PixelFormatInterface with the ability to handle color palettes/tables.
//----------------------------------------------------------------------------------------
class PixelFormatIndexedColorInterface : MAXON_INTERFACE_BASES(PixelFormatInterface)
{
	MAXON_INTERFACE(PixelFormatIndexedColorInterface, MAXON_REFERENCE_COPY_ON_WRITE, "net.maxon.image.interface.pixelformatindexedcolor");

public:
	//----------------------------------------------------------------------------------------
	/// Initialize the pixel format with a specific number of color entries and a given pixel format for the color entries.
	/// @param[in] count							Number of color entries in the table.
	/// @param[in] srcFormatPtr				Pixel format of the color entries.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> InitColorTable(Int count, const PixelFormat& srcFormatPtr);

	//----------------------------------------------------------------------------------------
	/// Returns the pixel format of the color table.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD PixelFormat GetColorTablePixelFormat() const;

	//----------------------------------------------------------------------------------------
	/// Returns the number of color entries.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Int GetColorTableSize() const;

	//----------------------------------------------------------------------------------------
	/// Sets a specific color entry.
	/// @param[in] idx								Index of the entry to set.
	/// @param[in] srcPixelData				Source color data. The color will be automatically converted into the color format provided in the Init function.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> SetIndex(Int idx, const ImageConstBuffer& srcPixelData);

	//----------------------------------------------------------------------------------------
	/// Returns a single color entry from the color table.
	/// @param[in] idx								Index of the entry to get.
	/// @param[in] dstPixelData				Destination color pointer. The color will be automatically converted into the color format provided in the dstPixelData.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> GetIndex(Int idx, const ImageMutableBuffer& dstPixelData) const;
};



//----------------------------------------------------------------------------------------
/// PixelFormatsInterface is a static interface which provides general functions for pixel format management.
//----------------------------------------------------------------------------------------
class PixelFormatsInterface
{
	MAXON_INTERFACE_NONVIRTUAL(PixelFormatsInterface, MAXON_REFERENCE_NONE, "net.maxon.image.interface.pixelformats");

public:
	//----------------------------------------------------------------------------------------
	/// Create of find a pixel format.
	/// @param[in] channels						Block with image channels to look for or to create.
	/// @return												Pixel format on success.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<PixelFormat> FindOrCreatePixelFormat(const Block<const ImageChannel>& channels);

	//----------------------------------------------------------------------------------------
	/// Create of find a pixel format. This function simplifies the usage without the need to create the block of channels on the stack:
	/// @code
	/// PixelFormat formatGBR32f = PixelFormatsInterface::FindOrCreatePixelFormat<ImageChannels::Green, ImageChannels::Blue, ImageChannels::Red>() iferr_return;
	/// @endcode
	/// @return												Pixel format on success.
	//----------------------------------------------------------------------------------------
	template <typename PIXELTYPE, typename... CHANNELS> static MAXON_FUNCTION Result<PixelFormat> FindOrCreatePixelFormat();

	//----------------------------------------------------------------------------------------
	/// Create of find a pixel format. This function simplifies the usage without the need to create the array of channels on the stack:
	/// @param[in] imageChannelTypes	Image Channel types.
	/// @code
	/// PixelFormat formatGBR32f = PixelFormatsInterface::FindOrCreatePixelFormat<ImageChannels::Green, ImageChannels::Blue, ImageChannels::Red>() iferr_return;
	/// @endcode
	/// @return												Pixel format on success.
	//----------------------------------------------------------------------------------------
	template <typename PIXELTYPE> static MAXON_FUNCTION Result<PixelFormat> FindOrCreatePixelFormat(const Block<const ImageChannelType>& imageChannelTypes);

	//----------------------------------------------------------------------------------------
	/// Create of find a pixel format. This function simplifies the usage without the need to create the array of channels on the stack:
	/// @param[in] pixelType					Pixel data type e.g. GetDataType<Pix32f>().
	/// @param[in] imageChannelTypes	Image Channel types.
	/// @code
	/// PixelFormat formatGBR32f = PixelFormatsInterface::FindOrCreatePixelFormat<ImageChannels::Green, ImageChannels::Blue, ImageChannels::Red>() iferr_return;
	/// @endcode
	/// @return												Pixel format on success.
	//----------------------------------------------------------------------------------------
	static MAXON_FUNCTION Result<PixelFormat> FindOrCreatePixelFormat(const DataType& pixelType, const Block<const ImageChannelType>& imageChannelTypes);
};




// include autogenerated headerfile here
#include "gfx_image_pixelformat1.hxx"

/// Base channels which implements a bunch of default functions for all pixel formats
MAXON_DECLARATION(Class<PixelFormat>, PixelFormatBaseClass, "net.maxon.image.class.pixelformatbase");

MAXON_REGISTRY(PixelFormatGroup, PixelFormats, "net.maxon.image.registry.pixelformats");

//----------------------------------------------------------------------------------------
/// Registry to register PixelFormats.
//----------------------------------------------------------------------------------------
namespace PixelFormats
{
	MAXON_DECLARATION(PixelFormatGroup, RGBGroup, "net.maxon.image.pixelformat.rgbgroup");
	MAXON_REGISTRY(PixelFormat, RGB, "net.maxon.image.registry.rgb");
}

class PixelFormatIterator : public PixelFormats::RGB::Registry::Iterator
{
	MAXON_DISALLOW_COPY_AND_ASSIGN(PixelFormatIterator);

public:
	PixelFormatIterator() = default;
	PixelFormatIterator(PixelFormatIterator&& other) : PixelFormats::RGB::Registry::Iterator(std::move(other))
	{
	}
	MAXON_OPERATOR_MOVE_ASSIGNMENT(PixelFormatIterator);
};

// include autogenerated headerfile here
#include "gfx_image_pixelformat2.hxx"


//----------------------------------------------------------------------------------------
/// Several functions use this helper structure to pass the image data to functions.
//----------------------------------------------------------------------------------------
template <typename BASECLASS> struct ImageBufferTemplate : public BASECLASS
{
public:
	//----------------------------------------------------------------------------------------
	/// Copy constructor.
	//----------------------------------------------------------------------------------------
	ImageBufferTemplate(const ImageBufferTemplate& src)
		: BASECLASS(src._buffer, src._inc), _channelOffsets(src._channelOffsets), _format(src._format)
	{
	}

	//----------------------------------------------------------------------------------------
	/// Constructs the ImageBuffer object. The channelOffsets and increment is automatically taken from the pixelformat.
	//----------------------------------------------------------------------------------------
	ImageBufferTemplate(typename BASECLASS::PIXELTYPE* buffer, const PixelFormat& format)
		: BASECLASS(buffer, format.GetBitsPerPixel()), _channelOffsets(format.GetChannelOffsets()), _format(format)
	{
	}

	//----------------------------------------------------------------------------------------
	/// Constructs the helper object.
	/// @param[in] buffer							Pointer to the memory block of the pixel data.
	/// @param[in] inc								Distance in number of bytes from one pixel to the next. For packed pixels this value is equal to BytesPerPixel().
	/// @param[in] channelOffsets			Distance of the channels of a pixel. This can be used to work with planes. For packed pixels this value is equal to BytesPerChannel().
	/// @param[in] format							Pixel format of the buffer.
	//----------------------------------------------------------------------------------------
	ImageBufferTemplate(typename BASECLASS::PIXELTYPE* buffer, BITS inc, const ChannelOffsets& channelOffsets, const PixelFormat& format)
		: BASECLASS(buffer, inc), _channelOffsets(channelOffsets), _format(format)
	{
	}

	//----------------------------------------------------------------------------------------
	/// Constructs the helper object.
	/// @param[in] buffer							PixelConst/MutableBuffer that points to the pixel memory/offset.
	/// @param[in] channelOffsets			Distance of the channels of a pixel. This can be used to work with planes. For packed pixels this value is equal to BytesPerChannel().
	/// @param[in] format							Pixel format of the buffer.
	//----------------------------------------------------------------------------------------
	ImageBufferTemplate(const BASECLASS& buffer, const ChannelOffsets& channelOffsets, const PixelFormat& format)
		: BASECLASS(buffer), _channelOffsets(channelOffsets), _format(format)
	{
	}

	ImageBufferTemplate& operator = (const ImageBufferTemplate& src)
	{
		this->~ImageBufferTemplate();
		new (this) ImageBufferTemplate(src);
		return *this;
	}

	const ImageConstBuffer& ToConst() const
	{
		return reinterpret_cast<const ImageConstBuffer&>(*this);
	}

public:
	const ChannelOffsets& _channelOffsets;
	PixelFormat						_format;
};


inline Result<PixelFormat> PixelFormatsInterface::FindOrCreatePixelFormat(const DataType& pixelType, const Block<const ImageChannelType>& imageChannelTypes)
{
	iferr_scope;

	if (!pixelType)
		return IllegalArgumentError(MAXON_SOURCE_LOCATION);

	BaseArray<ImageChannel> imageChannels;
	for (const ImageChannelType& c : imageChannelTypes)
	{
		ImageChannel ch = c.GetChannel(pixelType);
		if (!ch)
			return IllegalArgumentError(MAXON_SOURCE_LOCATION);
		imageChannels.Append(ch) iferr_return;
	}

	return FindOrCreatePixelFormat(imageChannels.ToBlock());
}

template <typename PIXELTYPE> Result<PixelFormat> PixelFormatsInterface::FindOrCreatePixelFormat(const Block<const ImageChannelType>& imageChannelTypes)
{
	return FindOrCreatePixelFormat(GetDataType<PIXELTYPE>(), imageChannelTypes);
}

template <typename PIXELTYPE, typename... CHANNELS> Result<PixelFormat> PixelFormatsInterface::FindOrCreatePixelFormat()
{
	ImageChannel channelBlock[] = { CHANNELS::GetInstance()().template GetChannel<PIXELTYPE>()... };
	return FindOrCreatePixelFormat(ToBlock<const ImageChannel>(channelBlock));
}

//----------------------------------------------------------------------------------------
/// Joins 2 pixel formats together. The result pixel format will have all channels from the first format followed by the channels of the second format.
/// @param[in] format1						First pixel format.
/// @param[in] format2						Second pixel format.
/// @return												Returns the new joined pixel format.
//----------------------------------------------------------------------------------------
inline Result<PixelFormat> JoinPixelFormats(const PixelFormat& format1, const PixelFormat& format2)
{
	iferr_scope;

	auto channels1 = format1.GetChannels();
	auto channels2 = format2.GetChannels();

	BaseArray<ImageChannel> joinedChannels;
	joinedChannels.AppendAll(channels1) iferr_return;
	joinedChannels.AppendAll(channels2) iferr_return;

	return PixelFormatsInterface::FindOrCreatePixelFormat(joinedChannels);
}

/// @}

} // namespace maxon

#endif // GFX_IMAGE_PIXELFORMAT_H__
