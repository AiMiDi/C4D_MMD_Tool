#ifndef GFX_IMAGE_COLORPROFILE_H__
#define GFX_IMAGE_COLORPROFILE_H__


#include "maxon/gfx_image_pixelformat.h"
#include "maxon/vector.h"
#include "maxon/interface.h"
#include "maxon/url.h"

namespace maxon
{

class PixelFormat;



//----------------------------------------------------------------------------------------
/// Return value of ColorProfile.GetInfo() function.
//----------------------------------------------------------------------------------------
enum class COLORPROFILEINFO
{
	DESCRIPTION		= 0,	///< Description of the color profile.
	MANUFACTURER	= 1,	///< Manufacturer of the color profile.
	MODEL					= 2,	///< Model of the color profile.
	COPYRIGHT			= 3		///< Copyright informations of the color profile.
} MAXON_ENUM_LIST(COLORPROFILEINFO);



//----------------------------------------------------------------------------------------
/// Color Conversion intent.
/// This value controls the intent of the color conversion.
/// Members docs copied from http://www.littlecms.com/LittleCMS2.6%20tutorial.pdf
//----------------------------------------------------------------------------------------
enum class COLORCONVERSIONINTENT
{
	/// Hue hopefully maintained (but not required), lightness and saturation sacrificed to
	/// maintain the perceived color. White point changed to result in neutral grays.
	/// Intended for images.
	PERCEPTUAL						= 0,

	/// Within and outside gamut; same as Absolute Colorimetric. White point changed to
	/// result in neutral grays.
	RELATIVE_COLORIMETRIC	= 1,

	/// Hue and saturation maintained with lightnesssacrificed to maintain saturation.
	/// White point changed to result in neutral grays. Intended for business graphics
	/// (make it colorful charts, graphs, overheads, ...)
	SATURATION						= 2,

	/// Within the destination device gamut; hue, lightness and saturation are
	/// maintained. Outside the gamut; hue and lightness are maintained, saturation is
	/// sacrificed. White point for source and destination; unchanged. Intended for spot
	/// colors (Pantone, TruMatch, logo colors, ...)
	ABSOLUTE_COLORIMETRIC = 3
} MAXON_ENUM_LIST(COLORCONVERSIONINTENT);

//----------------------------------------------------------------------------------------
/// Color Conversion intent.
/// This value controls the intent of the color conversion.
/// Members docs copied from http://www.littlecms.com/LittleCMS2.6%20tutorial.pdf
//----------------------------------------------------------------------------------------
enum class COLORCONVERSIONFLAGS
{
	NONE = 0,

	/// Black Point Compensation (BPC) controls whether to adjust for differences in black points when
	/// converting colors between color spaces. When Black Point Compensation is enabled, color
	/// transforms map white to white and luminance of black to luminance of black. The black point
	/// compensation feature does work better in conjunction with relative colorimetric intent.
	/// Perceptual intent should make no difference, although it may affect some (wrong) profiles.
	BLACKPOINTCOMPENSATION = (1 << 0)

} MAXON_ENUM_FLAGS(COLORCONVERSIONFLAGS);


class ColorProfile;

//----------------------------------------------------------------------------------------
/// This class allows to deal with color profiles. Color profiles are used to map colors from a
/// given color space (e.g. image color space) into a destination color space (e.g. calibrated monitor).
//----------------------------------------------------------------------------------------
class ColorProfileInterface
{
	MAXON_INTERFACE_NONVIRTUAL(ColorProfileInterface, MAXON_REFERENCE_ALWAYS_COPY_ON_WRITE, "net.maxon.image.interface.colorprofile");
public:
	MAXON_METHOD Bool IsEqual(const ColorProfileInterface* other) const;

	//----------------------------------------------------------------------------------------
	/// Create a color profile from a Url.
	/// @param[in] fn									Url of the preset. This could be an icc file from the hard drive.
	/// @return												A valid color profile if the operation was successful.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<ColorProfile> OpenProfileFromFile(const Url& fn);

	//----------------------------------------------------------------------------------------
	/// Create a color profile from a memory block. This can be used to read the color profiles within images.
	/// @param[in] mem								Memory block representing the icc color profile.
	/// @return												A valid color profile if the operation was successful.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<ColorProfile> OpenProfileFromMemory(const Block<const Byte>& mem);

	//----------------------------------------------------------------------------------------
	/// Write the current profile to memory.
	/// @param[out] mem								Array which receives the memory.
	/// @return												True if the function operates successful.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> WriteProfileToMemory(WritableArrayInterface<Char>& mem) const;

	//----------------------------------------------------------------------------------------
	/// Write the current profile to a file stream.
	/// @param[in] fn									Name of the file/stream.
	/// @return												True if the function operates successful.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> WriteProfileToFile(const Url& fn) const;

	//----------------------------------------------------------------------------------------
	/// Returns additional informations to the color profile.
	/// @param[in] info								Requested information. See COLORPROFILEINFO.
	/// @return												String with the information stored in the color profile.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD String GetInfo(COLORPROFILEINFO info) const;

	//----------------------------------------------------------------------------------------
	/// Returns the crc representing this color profile.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD UInt32 GetCrc() const;

	//----------------------------------------------------------------------------------------
	/// Returns whether this object contains a valid color profile.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Bool HasProfile() const;

	//----------------------------------------------------------------------------------------
	/// Check the color profile if it's compatible with the given pixel format. 8e.g. if gray scale matches)
	/// @return												True if the pixel format is compatible with the color profile.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Bool CheckCompatiblePixelFormat(const PixelFormat& pixelFormat) const;

	//----------------------------------------------------------------------------------------
	/// Returns whether the color profile is linked to a color profile of a monitor.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Bool IsMonitorProfileMode() const;

	//----------------------------------------------------------------------------------------
	/// Returns the hash code of the object.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD UInt GetHashCode() const;

	//----------------------------------------------------------------------------------------
	/// Returns the color space for which the profile is valid.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD ColorSpace GetColorSpace() const;

	//----------------------------------------------------------------------------------------
	/// Returns a readable string of the content.
	/// @param[in] formatStatement		Nullptr or additional formatting instruction. Currently no additional formatting instructions are supported.
	/// @return												The converted result. By default, this is the name of the class, followed by \@, followed by the hexadecimal memory address of this object.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD String ToString(const FormatStatement* formatStatement) const;

	/// @cond INTERNAL

	//----------------------------------------------------------------------------------------
	/// Private.
	// TODO: (Tilo) Please describe
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Bool SetMonitorProfileMode(Bool on);

	//----------------------------------------------------------------------------------------
	/// Describe all elements of this class for I/O operations.
	/// @param[in] stream							The stream that is used to register the class members.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<void> DescribeIO(const DataSerializeInterface& stream);

	/// @endcond
};


class ColorProfileConvert;

//----------------------------------------------------------------------------------------
/// Helper class to convert pixel data from one color profile to another.
//----------------------------------------------------------------------------------------
class ColorProfileConvertInterface
{
	MAXON_INTERFACE_NONVIRTUAL(ColorProfileConvertInterface, MAXON_REFERENCE_CONST, "net.maxon.image.interface.colorprofileconvert");
public:
	//----------------------------------------------------------------------------------------
	/// Create a new helper class to convert from srcPixelFormat to dstPixelFormat.
	/// @param[in] srcPixelFormat			Source color pixel format.
	/// @param[in] srcProfile					Source color profile.
	/// @param[in] dstPixelFormat			Destination color profile.
	/// @param[in] dstProfile					Destination color profile.
	/// @param[in] intent							TODO: (Tilo) please describe
	/// @param[in] flags							TODO: (Tilo) please describe
	/// @return												A object to convert pixel data. If nullptr then there is no need to convert pixels because the profiles are identical.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<ColorProfileConvert> Init(const PixelFormat& srcPixelFormat, const ColorProfile& srcProfile, const PixelFormat& dstPixelFormat, const ColorProfile& dstProfile, COLORCONVERSIONINTENT intent, COLORCONVERSIONFLAGS flags);

	//----------------------------------------------------------------------------------------
	/// Call to convert pixel data from one profile to another.
	/// @param[in] src								Pointer to the memory block with the source pixel data. The pixel data needs to be in the srcPixelFormat and srcProfile (see Init).
	/// @param[in] dst								Pointer to the memory block with the dest pixel data. The pixel data will be written with dstPixelFormat and dstProfile (see Init).
	/// @param[in] cnt								Number of source pixels to convert.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> Convert(const ImageConstBuffer& src, const ImageMutableBuffer& dst, Int cnt) const;

	//----------------------------------------------------------------------------------------
	/// Gets the hash code of the conversion.
	/// @return												The hash code of the conversion.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD UInt GetHashCode() const;

	//----------------------------------------------------------------------------------------
	/// Returns the closest compatible pixel format for the given format.
	/// If the pixel format is supported natively be the color conversion the given format is returned.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<PixelFormat> GetNearestNativeFormat(const PixelFormat& format);
};

template <typename T> inline T SRGBtoLinear(const T& v)
{
	const typename T::ValueTypeParam v1 = (typename T::ValueTypeParam) 0.04045;
	const typename T::ValueTypeParam v2 = (typename T::ValueTypeParam) (1.0 / 12.92);
	const typename T::ValueTypeParam v3 = (typename T::ValueTypeParam) 0.055;
	const typename T::ValueTypeParam v4 = (typename T::ValueTypeParam) (1.0 / 1.055);
	const typename T::ValueTypeParam v5 = (typename T::ValueTypeParam) 2.4;

	// Copy data to preserve possible alpha
	T dst(v);
	if (dst[0] > 0.0)
		dst[0] = (dst[0] <= v1) ? dst[0] * v2 : Pow((dst[0] + v3) * v4, v5);
	if (dst[1] > 0.0)
		dst[1] = (dst[1] <= v1) ? dst[1] * v2 : Pow((dst[1] + v3) * v4, v5);
	if (dst[2] > 0.0)
		dst[2] = (dst[2] <= v1) ? dst[2] * v2 : Pow((dst[2] + v3) * v4, v5);

	return dst;
}

template <typename T> inline T LinearToSRGB(const T& v)
{
	const typename T::ValueTypeParam v1 = (typename T::ValueTypeParam) 0.0031308;
	const typename T::ValueTypeParam v2 = (typename T::ValueTypeParam) 12.92;
	const typename T::ValueTypeParam v3 = (typename T::ValueTypeParam) 0.055;
	const typename T::ValueTypeParam v4 = (typename T::ValueTypeParam) 1.055;
	const typename T::ValueTypeParam v5 = (typename T::ValueTypeParam) (1.0 / 2.4);

	// Copy data to preserve possible alpha
	T dst(v);
	dst[0] = (dst[0] <= v1) ? dst[0] * v2 : (v4 * Pow(dst[0], v5) - v3);
	dst[1] = (dst[1] <= v1) ? dst[1] * v2 : (v4 * Pow(dst[1], v5) - v3);
	dst[2] = (dst[2] <= v1) ? dst[2] * v2 : (v4 * Pow(dst[2], v5) - v3);

	return dst;
}

#include "gfx_image_colorprofile1.hxx"


MAXON_REGISTRY(ColorProfile, ColorProfiles, "net.maxon.image.registry.colorprofiles");

namespace ColorProfiles
{
	MAXON_DECLARATION(ColorProfile, NONE, "net.maxon.image.colorprofile.none");								///< Null color profile.
	MAXON_DECLARATION(ColorProfile, SRGB, "net.maxon.image.colorprofile.srgb");								///< Default SRGB profile for rgb images.
	MAXON_DECLARATION(ColorProfile, SGREY, "net.maxon.image.colorprofile.sgrey");							///< Default profile for gray images.
	MAXON_DECLARATION(ColorProfile, CMYKdefault, "net.maxon.image.colorprofile.cmykdefault");					///< Default profile for cmyk images.
	MAXON_DECLARATION(ColorProfile, YUVdefault, "net.maxon.image.colorprofile.yuvdefault");						///< Default profile for yuv images.
	MAXON_DECLARATION(ColorProfile, LINEAR_RGB, "net.maxon.image.colorprofile.linear_rgb");		///< Default Linear profile for rgb images.
	MAXON_DECLARATION(ColorProfile, LINEAR_GREY, "net.maxon.image.colorprofile.linear_grey");	///< Default Linear profile for gray images.
}


#include "gfx_image_colorprofile2.hxx"


}



#endif // GFX_IMAGE_COLORPROFILE_H__
