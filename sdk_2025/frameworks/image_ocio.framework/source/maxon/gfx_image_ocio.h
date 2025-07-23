#ifndef GFX_IMAGE_OCIO_H__
#define GFX_IMAGE_OCIO_H__

#include "maxon/error.h"
#include "maxon/vector.h"
#include "maxon/matrix.h"
#include "maxon/forwardref.h"
#include "maxon/url.h"

namespace maxon
{

class OcioProcessor;
class OcioConfig;
class ColorProfileGpuHandlerRef;

enum class COLORCONVERSIONFLAGS_GPU;
enum class COLORCONVERSION_OPTIMIZATION_GPU_FLAGS;

//----------------------------------------------------------------------------------------
/// This class allows to deal with color profiles. Color profiles are used to map colors from a
/// given color space (e.g. image color space) into a destination color space (e.g. calibrated monitor).
/// @MAXON_ANNOTATION{nullimpl=true,dependencies=false}
/// @markPrivate
//----------------------------------------------------------------------------------------
class OcioProcessorInterface
{
	MAXON_INTERFACE_NONVIRTUAL(OcioProcessorInterface, MAXON_REFERENCE_ALWAYS_COPY_ON_WRITE, "net.maxon.image.interface.ocioprocessor");
public:

	MAXON_METHOD Bool IsEqual(const OcioProcessorInterface* other) const;

	//----------------------------------------------------------------------------------------
	/// Opens a LUT from a Url.
	/// @param[in] fn									Url to load.
	/// @param[in] tryToCreateReverse	If true then the loader tries to create the reverse direction (not all luts provide the reverse operation).
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<OcioProcessor> OpenLUTFromFile(const Url& fn, Bool tryToCreateReverse);

	//----------------------------------------------------------------------------------------
	/// Returns true if the OcioProcessor supports the reverse operation. If this is given ConvertPixels can be called with reverse = true.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Bool SupportsReverse() const;

	//----------------------------------------------------------------------------------------
	/// ConvertPixels description.
	/// @param[in] pixelBuffer				RGB values with Float32 buffer to convert.
	/// @param[in] inc								Increment in bytes from one pixel to the next.
	/// @param[in] pixelCnt						Number of pixels to convert.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> ConvertPixels(Float32* pixelBuffer, Int inc, Int pixelCnt, Bool reverse) const;
	MAXON_METHOD Result<void> ConvertPixels(UChar* pixelBuffer, Int inc, Int pixelCnt, Bool reverse) const;

	MAXON_METHOD Result<void> ConvertPixels(const Float32* srcPixelBuffer, Float32* dstPixelBuffer, Int inc, Int pixelCnt, Bool reverse) const;

	//----------------------------------------------------------------------------------------
	/// Transforms a color according to the loaded LUT.
	/// @param[in] color							The color to transform.
	/// @return												The resulting color after application of the LUT transform.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Color32 TransformColor(const Color32& color) const;

	//----------------------------------------------------------------------------------------
	/// Gets the GPU handler for the processor.
	/// @return												The GPU handler.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<ForwardRef<ColorProfileGpuHandlerRef>> GetGpuHandler() const;

	//----------------------------------------------------------------------------------------
	/// Gets the color spaces that are used in this processor.
	/// @return												The color spaces.
	//----------------------------------------------------------------------------------------
	Block<const CString> GetColorSpaces() const;
};

/// @markPrivate
class OcioConfigInterface
{
	MAXON_INTERFACE_NONVIRTUAL(OcioConfigInterface, MAXON_REFERENCE_ALWAYS_COPY_ON_WRITE, "net.maxon.image.interface.ocioconfig");

public:
	struct ColorSpace
	{
		MAXON_DISALLOW_COPY_AND_ASSIGN(ColorSpace);

		ColorSpace() = default;
		ColorSpace(ColorSpace&& src) : MAXON_MOVE_MEMBERS(space, family, name, categories) {}
		MAXON_OPERATOR_MOVE_ASSIGNMENT(ColorSpace);


		Result<void> CopyFrom(const ColorSpace& src)
		{
			iferr_scope;
			space = src.space;
			family = src.family;
			name = src.name;
			categories.CopyFrom(src.categories) iferr_return;
			return OK;
		};

		CString space;
		CString family;
		CString name;
		BaseArray<CString> categories;
	};
	
	struct Role
	{
		CString name;
		CString colorSpaceName;
	};

	enum class DISPLAY_TYPE
	{
		FROM_CONFIG				= 0, ///< Display is defined in config file.
		VIRTUAL_MONITOR		= 1, ///< Virtual display, created from monitor.
		VIRTUAL_ICC				= 2  ///< Virtual display, created from icc file.
	} MAXON_ENUM_LIST_CLASS(DISPLAY_TYPE);

	struct Display
	{
		Display(const CString& n, DISPLAY_TYPE t) : name(n), type(t) { }
		CString name;
		DISPLAY_TYPE type;
	};

	enum class COLORSPACE_NAME
	{
		SRGB_NON_LINEAR = 0,
		SRGB_LINEAR			= 1,
		RAW							= 2
	} MAXON_ENUM_LIST_CLASS(COLORSPACE_NAME);

	enum class CONVERSIONFUNCTION_FLAGS
	{
		NONE							= 0,
		INVERSE_DIRECTION = (1 << 0),
		PIXELFORMAT_UINT8	= (1 << 5),
	} MAXON_ENUM_FLAGS_CLASS(CONVERSIONFUNCTION_FLAGS);

	MAXON_METHOD Bool IsEqual(const OcioConfigInterface* other) const;
	MAXON_METHOD HashInt GetHashCode() const;
	MAXON_METHOD String ToString(const FormatStatement* fs = nullptr) const;

	static MAXON_METHOD Result<OcioConfig> Load(const Url& url);
	MAXON_METHOD const Url& GetConfigUrl() const;
	MAXON_METHOD Result<CString> AddIccDisplayProfile(const Url& url);

	MAXON_METHOD const BaseArray<ColorSpace>& GetColorSpaces() const;
	MAXON_METHOD const BaseArray<Role>& GetRoles() const;

	MAXON_METHOD Result<OcioProcessor> CreateConversionFunction(const CString& inputColorSpace, const CString& outputColorSpace, CONVERSIONFUNCTION_FLAGS flags) const;
	MAXON_METHOD Result<OcioProcessor> CreateConversionFunctionWithViewTransform(const CString& inputColorSpace, const CString& viewTransform, const CString& displayColorSpace, CONVERSIONFUNCTION_FLAGS flags) const;
	MAXON_METHOD Result<OcioProcessor> CreateGpuProcessor(const CString& inputColorSpace, const CString& outputColorSpace, COLORCONVERSIONFLAGS_GPU flags, COLORCONVERSION_OPTIMIZATION_GPU_FLAGS optimization) const;
	MAXON_METHOD Result<OcioProcessor> CreateGpuProcessorWithViewTransform(const CString& inputColorSpace, const CString& viewTransform, const CString& displayColorSpace, COLORCONVERSIONFLAGS_GPU flags, COLORCONVERSION_OPTIMIZATION_GPU_FLAGS optimization) const;
	MAXON_METHOD Bool ComputeColorTransformMatrix(const CString& srcColorSpaceName, const CString& dstColorSpaceName, SquareMatrix32& retMatrix) const;
	MAXON_METHOD Result<CString> GetColorSpaceFamily(const CString& colorSpaceName) const;
	MAXON_METHOD Result<BaseArray<CString>> GetColorSpaceCategories(const CString& colorSpaceName) const;
	MAXON_METHOD Result<BaseArray<CString>> GetRenderingColorSpaceNames() const;
	MAXON_METHOD Result<BaseArray<Display>> GetDisplays(Bool activeOnly) const;
	MAXON_METHOD Result<BaseArray<CString>> GetViewTransformNames(const CString& displayColorSpaceName) const;
	MAXON_METHOD const CString& GetColorSpaceName(COLORSPACE_NAME name) const;
	MAXON_METHOD const CString& GetDefaultDisplayName() const;
	MAXON_METHOD const BaseArray<CString>& GetLutLocations() const;
	MAXON_METHOD const BaseArray<CString>& GetMonitorNames() const;
	MAXON_METHOD Result<CString> GetColorspaceNameForFile(const Url& path) const;
	MAXON_METHOD const CString& GetMonitorColorSpaceName(UInt64 monitorSystemHandle) const;
	MAXON_METHOD void SetDisallowFileRules(Bool value = true);
	/// @private
	static MAXON_METHOD Result<void> DescribeIO(const DataSerializeInterface& stream);
};

#include "gfx_image_ocio1.hxx"
#include "gfx_image_ocio2.hxx"

}

#endif // GFX_IMAGE_OCIO_H__
