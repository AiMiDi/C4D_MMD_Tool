/////////////////////////////////////////////////////////////
// Cinema 4D SDK                                           //
/////////////////////////////////////////////////////////////
// (c) MAXON Computer GmbH, all rights reserved            //
/////////////////////////////////////////////////////////////

#ifndef C4D_BASEBITMAP_H__
#define C4D_BASEBITMAP_H__

#ifdef __API_INTERN__
	#include "ge_sys_math.h"
#else
	#include "ge_math.h"
	#include "operatingsystem.h"
	#include "c4d_gedata.h"
	#include "c4d_baseplugin.h"
	#include "c4d_filterdata.h"
	#include "c4d_customdatatype.h"
#endif

#include "maxon/datadictionary.h"

class BaseContainer;
class Filename;
class GeDialog;

/// @addtogroup PIX
/// @ingroup group_macro
/// @{
/// Number of color info bit for UCHAR depth mode
#define PIX_UCHAR(p) ((PIX_C*)(p))

/// Number of color info bit for UWORD depth mode
#define PIX_UWORD(p) ((PIX_W*)(p))

/// Number of color info bit for FLOAT depth mode
#define PIX_FLOAT(p) ((PIX_F*)(p))
/// @}

/// @addtogroup B3D
/// @ingroup group_macro
/// @{
/// Returns the bit depth for the @formatParam{mode}.
#define B3D_BITDEPTH(mode) (((Int32)mode >> BITDEPTH_SHIFT) & (BITDEPTH_UCHAR | BITDEPTH_UWORD | BITDEPTH_FLOAT))

/// Returns the COLORMODE for the @formatParam{mode}.
#define B3D_COLOR_MODE(mode) (COLORMODE(Int32(mode) & ~((BITDEPTH_UCHAR | BITDEPTH_UWORD | BITDEPTH_FLOAT) << BITDEPTH_SHIFT)))

/// Sets the depth color mode.
#define B3D_SETDEPTH(depth) (COLORMODE(depth << BITDEPTH_SHIFT))

/// Checks if the bit depth @formatParam{mode} is ::BITDEPTH_UCHAR.
#define B3D_IS_CHAR(mode) (B3D_BITDEPTH(mode) == BITDEPTH_UCHAR)

/// Checks if the bit depth @formatParam{mode} is ::BITDEPTH_UWORD.
#define B3D_IS_UWORD(mode) (B3D_BITDEPTH(mode) == BITDEPTH_UWORD)

/// Checks if the bit depth @formatParam{mode} is ::BITDEPTH_FLOAT.
#define B3D_IS_FLOAT(mode) (B3D_BITDEPTH(mode) == BITDEPTH_FLOAT)
/// @}

/// Maximum number of color modes.
#define COLORMODE_MAXCOLOR ((1 << 6) - 1)

/// @addtogroup COLORBYTES
/// @ingroup group_enumeration
/// @{
#define COLORBYTES_GRAY			1																				///< 8-bit grayscale.
#define COLORBYTES_AGRAY		2																				///< 8-bit grayscale with 8-bit alpha.
#define COLORBYTES_RGB			3																				///< 8-bit RGB.
#define COLORBYTES_ARGB			4																				///< 8-bit RGB with 8-bit alpha.
#define COLORBYTES_CMYK			4																				///< 8-bit CMYK.
#define COLORBYTES_ACMYK		5																				///< 8-bit CMYK with 8-bit alpha.

#define COLORBYTES_GRAYw		(COLORBYTES_GRAY * sizeof(PIX_W))				///< 16-bit grayscale.
#define COLORBYTES_AGRAYw		(COLORBYTES_AGRAY * sizeof(PIX_W))			///< 16-bit grayscale with 16-bit alpha.
#define COLORBYTES_RGBw			(COLORBYTES_RGB * sizeof(PIX_W))				///< 16-bit RGB.
#define COLORBYTES_ARGBw		(COLORBYTES_ARGB * sizeof(PIX_W))				///< 16-bit RGB with 16-bit alpha.
#define COLORBYTES_GRAYf		(COLORBYTES_GRAY * sizeof(PIX_F))				///< Floating point grayscale.
#define COLORBYTES_AGRAYf		(COLORBYTES_AGRAY * sizeof(PIX_F))			///< Floating point grayscale with floating point alpha.
#define COLORBYTES_RGBf			(COLORBYTES_RGB * sizeof(PIX_F))				///< Floating point RGB.
#define COLORBYTES_ARGBf		(COLORBYTES_ARGB * sizeof(PIX_F))				///< Floating point RGB with floating point alpha.

#define COLORBYTES_MAX			(COLORBYTES_ARGBf)											///< Maximum number of color bytes.
/// @}

/// @addtogroup BASEBITMAP_DATA
/// @ingroup group_containerid
/// @{
/// Container IDs for BaseBitmap data. @markPrivate
/// @see BaseBitmap::GetData() / BaseBitmap::SetData()
#define BASEBITMAP_DATA_GUIPIXELRATIO			100				///< ::Float.
#define BASEBITMAP_DATA_DPI								101				///< ::Float. @since R19
#define BASEBITMAP_DATA_ASPECTRATIO				102				///< ::Float. @since R19
#define BASEBITMAP_DATA_EXPORTSETTINGS		103				///< BaseContainer. @since R19
#define BASEBITMAP_DATA_NAME							1003			///< String.
#define BASEBITMAP_DATA_PROGRESS_TIME			1004			///< String.
#define BASEBITMAP_DATA_PROGRESS_ACTION		1005			///< String.
#define BASEBITMAP_DATA_PROGRESS_FRAME		1006			///< ::Float (@em 0 to @em 1).
#define BASEBITMAP_DATA_PROGRESS_SEQ			1007			///< ::Float (@em 0 to @em 1).
#define BASEBITMAP_DATA_PROGRESS_FNUM			1008			///< String.
#define BASEBITMAP_DATA_DRAW_REGIONS			1009			///< BaseContainer.
#define BASEBITMAP_DATA_SPINMODE					1010			///< ::Bool.
#define BASEBITMAP_DATA_HOLDTIME					1011			///< ::Int32.
#define BASEBITMAP_DATA_STARTTIME					1012			///< ::Int32.
#define BASEBITMAP_DATA_PROGRESS_PHASE		1013			///< ::RENDERPROGRESSTYPE.
#define BASEBITMAP_DATA_FRAMETIME					1015			///< ::Int32.
#define BASEBITMAP_DATA_TEXTURE_ERROR			1019			///< ::String.
/// @}

/// @addtogroup BITMAP_UPDATEREGION
/// @ingroup group_containerid
/// @{
/// Container IDs for ::BASEBITMAP_DATA_DRAW_REGIONS. @markPrivate
enum class BITMAP_UPDATEREGION
{
	X1				= 1,			///< ::Int32.
	Y1				= 2,			///< ::Int32.
	X2				= 3,			///< ::Int32.
	Y2				= 4,			///< ::Int32.
	TYPE			= 5,			///< ::Int32.
	COLOR			= 6,			///< ::Vector.
	PREPARE		= 7				///< ::Bool.
} MAXON_ENUM_LIST(BITMAP_UPDATEREGION);
/// @}


#ifndef __API_INTERN__

/// ColorProfile custom data ID.
#define CUSTOMDATATYPE_COLORPROFILE		200000266

/// ColorProfile custom GUI ID.
#define CUSTOMGUI_COLORPROFILE				200000267


//------------------------------------------------------------------------------------------------
/// Color Profile custom data type.
/// @addAllocFreeAutoAllocNote
//------------------------------------------------------------------------------------------------
class ColorProfile : public CustomDataType
{
private:
	ColorProfile();
	~ColorProfile();
	ColorProfile(const ColorProfile& src);

public:

	/// @addtogroup COLORPROFILEINFO
	/// @ingroup group_enumeration
	/// @{
	/// ColorProfile information type.
	/// @see ColorProfile::GetInfo()
	enum COLORPROFILEINFO
	{
		COLORPROFILEINFO_DESCRIPTION		= 0,			///< The color profile description.
		COLORPROFILEINFO_MANUFACTURER		= 1,			///< The color profile manufacturer.
		COLORPROFILEINFO_MODEL					= 2,			///< The color profile model.
		COLORPROFILEINFO_COPYRIGHT			= 3				///< The color profile copyright.
	};
	/// @}

public:

	/// @name Alloc/Free
	/// @{

	//----------------------------------------------------------------------------------------
	/// @allocatesA{color profile data}
	/// @return												@allocReturn{color profile data}
	//----------------------------------------------------------------------------------------
	static ColorProfile* Alloc(void);

	//----------------------------------------------------------------------------------------
	/// @destructsAlloc{color profile data}
	/// @param[in] profile						@theToDestruct{color profile data}
	//----------------------------------------------------------------------------------------
	static void Free(ColorProfile*& profile);

	/// @}

	/// @name Operators
	/// @{

	//----------------------------------------------------------------------------------------
	/// Assigns @formatParam{src} to the color profile.
	/// @param[in] src								The source color profile.
	/// @return												@em *this color profile.
	//----------------------------------------------------------------------------------------
	ColorProfile& operator = (const ColorProfile& src);

	//----------------------------------------------------------------------------------------
	/// Checks if @c *this and @formatParam{src} color profiles are identical.
	/// @param[in] src								The source color profile to compare with.
	/// @return												@trueIfOtherwiseFalse{the color profiles are identical}
	//----------------------------------------------------------------------------------------
	Bool operator == (const ColorProfile& src) const;

	//----------------------------------------------------------------------------------------
	/// Checks if @c *this and @formatParam{src} color profiles are not identical.
	/// @param[in] src								The source color profile to compare with.
	/// @return												@trueIfOtherwiseFalse{the color profiles are not identical}
	//----------------------------------------------------------------------------------------
	Bool operator != (const ColorProfile& src) const;

	/// @}

	/// @name Open/Write from File/Memory
	/// @{

	//----------------------------------------------------------------------------------------
	/// Loads the color profile data from the given file.
	/// @param[in] fn									The filename of the color profile file.
	/// @return												@trueIfOtherwiseFalse{successful}
	//----------------------------------------------------------------------------------------
	Bool OpenProfileFromFile(const Filename& fn);

	//----------------------------------------------------------------------------------------
	/// Loads the color profile from the memory location @formatParam{mem}.
	/// @param[in] mem								The pointer to the memory buffer containing the color profile. @callerOwnsPointed{memory buffer}
	/// @param[in] memsize						The size of the memory buffer @formatParam{mem}.
	/// @return												@trueIfOtherwiseFalse{successful}
	//----------------------------------------------------------------------------------------
	Bool OpenProfileFromMemory(const void* mem, Int64 memsize);

	//----------------------------------------------------------------------------------------
	/// Writes the color profile data to the given file.
	/// @param[in] fn									The filename of the color profile file.
	/// @return												@trueIfOtherwiseFalse{successful}
	//----------------------------------------------------------------------------------------
	Bool WriteProfileToFile(const Filename& fn) const;

	//----------------------------------------------------------------------------------------
	/// Writes the color profile to memory location @formatParam{mem}.
	/// @param[out] mem								Assigned a pointer to the color profile. @callerOwnsPointed{memory buffer}
	/// @param[out] memsize						Assigned the size of the written memory buffer @formatParam{mem}.
	/// @return												@trueIfOtherwiseFalse{successful}
	//----------------------------------------------------------------------------------------
	Bool WriteProfileToMemory(void*& mem, Int64& memsize) const;

	/// @}

	/// @name Monitor Color Profile
	/// @{

	//----------------------------------------------------------------------------------------
	/// Checks if the color profile is linked to the monitor color profile.
	/// @return												@trueIfOtherwiseFalse{the color profile is linked to the monitor color profile}
	//----------------------------------------------------------------------------------------
	Bool IsMonitorProfileMode() const;

	//----------------------------------------------------------------------------------------
	/// Links the color profile to the monitor color profile.
	/// @param[in] on									@trueOtherwiseFalse{to link the color profile to the monitor profile}
	/// @return												@trueIfOtherwiseFalse{successful}
	//----------------------------------------------------------------------------------------
	Bool SetMonitorProfileMode(Bool on);

	/// @}

	/// @name Miscellaneous
	/// @{

	//----------------------------------------------------------------------------------------
	/// Checks if the color profile is compatible with the passed color mode.
	/// @param[in] colormode					The color mode to check: @enumerateEnum{COLORMODE}
	/// @return												@trueIfOtherwiseFalse{the color profile is compatible with the passed color mode}
	//----------------------------------------------------------------------------------------
	Bool CheckColorMode(COLORMODE colormode) const;

	//----------------------------------------------------------------------------------------
	/// Retrieves the monitor color profile of the passed dialog window.
	/// @param[in] dlg								The dialog window to obtain the monitor color profile for. @callerOwnsPointed{dialog}
	/// @return												@trueOtherwiseFalse{successful}
	//----------------------------------------------------------------------------------------
	Bool CreateDefaultWindow(GeDialog* dlg);

	//----------------------------------------------------------------------------------------
	/// Retrieves information about the color profile.
	/// @param[in] info								The type of information: @enumerateEnum{COLORPROFILEINFO}
	/// @return												The information string.
	//----------------------------------------------------------------------------------------
	String GetInfo(COLORPROFILEINFO info) const;

	//----------------------------------------------------------------------------------------
	/// Checks if the color profile exists.
	/// @return												@trueIfOtherwiseFalse{the object contains a color profile}
	//----------------------------------------------------------------------------------------
	Bool HasProfile() const;

	/// @}

	/// @name Default Color Profiles
	/// @{

	//----------------------------------------------------------------------------------------
	/// Retrieves @C4D's default sRGB color profile.
	/// @return												The default sRGB color profile. @cinemaOwnsPointed{ColorProfile}
	//----------------------------------------------------------------------------------------
	static const ColorProfile* GetDefaultSRGB();

	//----------------------------------------------------------------------------------------
	/// Retrieves @C4D's default linear color profile.
	/// @return												The default linear color profile. @cinemaOwnsPointed{ColorProfile}
	//----------------------------------------------------------------------------------------
	static const ColorProfile* GetDefaultLinearRGB();

	//----------------------------------------------------------------------------------------
	/// Retrieves @C4D's default sRGB grayscale color profile.
	/// @return												The default sRGB grayscale color profile. @cinemaOwnsPointed{ColorProfile}
	//----------------------------------------------------------------------------------------
	static const ColorProfile* GetDefaultSGray();

	//----------------------------------------------------------------------------------------
	/// Retrieves @C4D's default linear grayscale color profile.
	/// @return												The default linear grayscale color profile. @cinemaOwnsPointed{ColorProfile}
	//----------------------------------------------------------------------------------------
	static const ColorProfile* GetDefaultLinearGray();

	//----------------------------------------------------------------------------------------
	/// Retrieves the internal color profile. @markPrivate
	/// @since R19
	/// @return												The internal color profile.
	//----------------------------------------------------------------------------------------
	const void* GetInternalProfile() const;

	/// @}
};


//-------------------------------------------------------------------------------------------------
/// A helper class to convert the ColorProfile of @link BaseBitmap bitmaps@endlink.
/// @addAllocFreeAutoAllocNote
/// @see BaseBitmap::GetPixelCnt()
//-------------------------------------------------------------------------------------------------
class ColorProfileConvert
{
private:
	ColorProfileConvert();
	~ColorProfileConvert();
	ColorProfileConvert(const ColorProfileConvert& src);
	ColorProfileConvert& operator = (const ColorProfileConvert& src);

public:

	/// @name Alloc/Free
	/// @{

	//----------------------------------------------------------------------------------------
	/// @allocatesA{ColorProfileConvert instance}
	/// @return												@allocReturn{ColorProfileConvert object}
	//----------------------------------------------------------------------------------------
	static ColorProfileConvert* Alloc(void);

	//----------------------------------------------------------------------------------------
	/// @destructsAlloc{ColorProfileConvert instances}
	/// @param[in,out] convert				@theToDestruct{ColorProfileConvert instance}
	//----------------------------------------------------------------------------------------
	static void Free(ColorProfileConvert*& convert);

	/// @}

	/// @name Conversion
	/// @{

	//----------------------------------------------------------------------------------------
	/// Prepares the color conversion i.e. checks if a conversion is needed.\n
	/// A conversion is only necessary if @formatConstant{true} is returned. Two identical color spaces will return @formatConstant{false}.
	/// @param[in] srccolormode				The source color mode: @enumerateEnum{COLORMODE}
	/// @param[in] srcprofile					The source color profile: @callerOwnsPointed{color profile}
	/// @param[in] dstcolormode				The destination color mode: @enumerateEnum{COLORMODE}
	/// @param[in] dstprofile					The destination color profile: @callerOwnsPointed{color profile}
	/// @param[in] bgr								@trueOtherwiseFalse{to swap the RGB channels}. Only necessary when working directly with @em Windows bitmaps.
	/// @return												@trueIfOtherwiseFalse{a conversion is necessary}
	//----------------------------------------------------------------------------------------
	Bool PrepareTransform(COLORMODE srccolormode, const ColorProfile* srcprofile, COLORMODE dstcolormode, const ColorProfile* dstprofile, Bool bgr);

	//----------------------------------------------------------------------------------------
	/// Converts the color profiles of the pixel data.
	/// @param[in] src								The pointer to the source pixel buffer. @callerOwnsPointed{buffer}
	/// @param[out] dst								The pointer to the destination pixel buffer. @callerOwnsPointed{buffer}
	/// @param[in] cnt								The number of pixels to convert.
	/// @param[in] SkipInputComponents	The number of bytes to skip in the source buffer after each converted pixel. For instance a RGB pixel contains 3 bytes.\n
	///																After conversion the number of @formatParam{SkipInputComponents} bytes is added to the source pointer.
	/// @param[in] SkipOutputComponents	The number of bytes to skip in the destination buffer after each converted pixel. For instance a RGB pixel contains 3 bytes.\n
	/// 															After conversion the number of @formatParam{SkipOutputComponents} bytes is added to the destination pointer.
	//----------------------------------------------------------------------------------------
	void Convert(const PIX* src, PIX* dst, Int32 cnt, Int32 SkipInputComponents, Int32 SkipOutputComponents) const;

	/// @}
};



//-------------------------------------------------------------------------------------------------
/// The bitmap class can be used to load, read, draw and save bitmap pictures of various formats.\n
/// Bitmaps are organized so that the 2D point <i>[0,0]</i> is the top left corner. Be sure to call Init() before you attempt to use a newly allocated bitmap.
/// @addAllocFreeAutoAllocNote
/// @warning	Though BaseBitmap can work with other bit depths than @em 24 and @em 32, note that only these function support other bit depths:\n
///						GetBw(), GetBh(), GetBt(), GetBpz(), Init(), GetLine(), SetLine(), GetPixelCnt(), SetPixelCnt(), SetCMAP(),\n
///						AddChannel(), RemoveChannel(), GetAlphaPixel(), SetAlphaPixel(), GetInternalChannel(), GetChannelCount(), GetChannelNum()\n
///						To use higher bit depths or multiple channels, see MultipassBitmap.
//-------------------------------------------------------------------------------------------------
class BaseBitmap
{
private:
	BaseBitmap();
	~BaseBitmap();

public:

	/// @name Alloc/Free
	/// @{

	//----------------------------------------------------------------------------------------
	/// @allocatesA{bitmap}
	/// @return												@allocReturn{bitmap}
	//----------------------------------------------------------------------------------------
	static BaseBitmap* Alloc(void);

	//----------------------------------------------------------------------------------------
	/// @destructsAlloc{bitmaps}
	/// @param[in,out] bm							@theToDestruct{bitmap}
	//----------------------------------------------------------------------------------------
	static void Free(BaseBitmap*& bm);

	/// @}

	/// @name Init
	/// @{

	//----------------------------------------------------------------------------------------
	/// Loads a bitmap file. The format is automatically detected.
	/// @note The bitmap class only supports up to @em 4 channels. Also, most image loaders will only load one alpha channel.
	/// @param[out] res								Assigned a pointer to a bitmap. @callerOwnsPointed{bitmap}
	/// @param[in] name								A valid filename that can either refer a movie or a picture.
	/// @param[in] frame							The frame number to load in a movie.
	/// @param[in] ismovie						If not @formatConstant{nullptr} this pointer is assigned @formatConstant{true} if the loaded picture is a movie, otherwise @formatConstant{false}.
	/// @param[in] loaderplugin				If not @formatConstant{nullptr} this pointer is assigned a bitmap loader plugin instance of the same type as the loaded bitmap. @callerOwnsPointed{bitmap loader}
	/// @param[in] progressCallback		Callback which is triggered if the loader supports progress reporting. Since R19.
	/// @return												The image result: @enumerateEnum{IMAGERESULT}
	//----------------------------------------------------------------------------------------
	static IMAGERESULT Init(BaseBitmap*& res, const Filename& name, Int32 frame = -1, Bool* ismovie = nullptr,
		BitmapLoaderPlugin** loaderplugin = nullptr, const maxon::Delegate<void(Float progress)>& progressCallback = nullptr);

	//----------------------------------------------------------------------------------------
	/// Loads a file into the bitmap. The file format is automatically detected.
	/// @warning Any previous data in the bitmap object is lost.
	/// @note The bitmap class only supports up to @em 4 channels. Also, most image loaders will only load one alpha channel.
	/// @param[in] name								A valid filename that can either refer a movie or a picture.
	/// @param[in] frame							The frame number to load in a movie.
	/// @param[in] ismovie						If not @formatConstant{nullptr} this pointer is assigned @formatConstant{true} if the loaded picture is a movie, otherwise @formatConstant{false}.
	/// @return												The image result: @enumerateEnum{IMAGERESULT}
	//----------------------------------------------------------------------------------------
	IMAGERESULT Init(const Filename& name, Int32 frame = -1, Bool* ismovie = nullptr);

	//----------------------------------------------------------------------------------------
	/// Initializes the bitmap to the given [@formatParam{x},@formatParam{y}] dimensions and @formatParam{depth}.\n
	/// @warning Any previous data in the bitmap object is lost.
	/// @param[in] x									The requested width in pixels (Maximum 16 000 pixels).
	/// @param[in] y									The requested height in pixels (Max. 16000 pixels).
	/// @param[in] depth							The requested bit depth. The possible values are (@em 1,  @em 4,  @em 8,  @em 16,  @em 24,  @em 32,  @em 64,  @em 96). On some platforms <i>32</i>-bit will be used even if @em 24 is requested, to allow for padding. In this case GetBt() will return  @em 32.
	/// @param[in] flags							The initialization flags: @enumerateEnum{INITBITMAPFLAGS}
	/// @return												The image result: @enumerateEnum{IMAGERESULT}
	//----------------------------------------------------------------------------------------
	IMAGERESULT Init(Int32 x, Int32 y, Int32 depth = 24, INITBITMAPFLAGS flags = INITBITMAPFLAGS::NONE);

	/// @}

	/// @name Reset
	/// @{

	//-------------------------------------------------------------------------------------------------
	/// Resets the bitmap to its initial state and frees allocated memory. Requires a call to Init() before the bitmap can be used again.
	//-------------------------------------------------------------------------------------------------
	void FlushAll(void);

	/// @}

	/// @name Save
	/// @{

	//----------------------------------------------------------------------------------------
	/// Saves the bitmap to a file.
	/// @param[in] name								A valid filename that can either refer a movie or a picture.
	/// @param[in] format							The image format: @enumerateEnum{FILTER}
	/// @param[in] data								The additional settings for some formats. @enumerateEnum{MISCSAVER}\n
	/// 															Can be @formatConstant{nullptr}, which means the same as an empty container. @callerOwnsPointed{container}
	/// @param[in] savebits						A combination of the following flags: @enumerateEnum{SAVEBIT}
	/// @return												The image result: @enumerateEnum{IMAGERESULT}
	//----------------------------------------------------------------------------------------
	IMAGERESULT Save(const Filename& name, Int32 format, BaseContainer* data, SAVEBIT savebits) const;

	/// @}

	/// @name Copy
	/// @{

	//----------------------------------------------------------------------------------------
	/// Copies the bitmap.
	/// @warning Do not use GetClone() in a NodeData::CopyTo method. This will cause memory leaks. Use CopyTo() instead.
	/// @return												The cloned bitmap, or @formatConstant{nullptr} if an error occured. @callerOwnsPointed{bitmap}
	//----------------------------------------------------------------------------------------
	BaseBitmap* GetClone(void) const;

	//----------------------------------------------------------------------------------------
	/// Copies a part of the bitmap, specified by the rectangle [@formatParam{x},@formatParam{y}] to [@formatParam{x}+@formatParam{w},@formatParam{y}+@formatParam{h}].
	/// @param[in] x									The upper left @em X coordinate of the rectangle.
	/// @param[in] y									The upper left @em Y coordinate of the rectangle.
	/// @param[in] w									The width of the rectangle.
	/// @param[in] h									The height of the rectangle.
	/// @return												The cloned part of the bitmap, or @formatConstant{nullptr} if an error occured. @callerOwnsPointed{bitmap}
	//----------------------------------------------------------------------------------------
	BaseBitmap* GetClonePart(Int32 x, Int32 y, Int32 w, Int32 h) const;

	//----------------------------------------------------------------------------------------
	/// Copies the bitmap from @c *this to @formatParam{*dst}.
	/// @param[out] dst								The bitmap to copy this bitmap to. @callerOwnsPointed{bitmap}
	/// @return												@trueIfOtherwiseFalse{the bitmap was successfully copied}
	//----------------------------------------------------------------------------------------
	Bool CopyTo(BaseBitmap* dst) const;

	//----------------------------------------------------------------------------------------
	/// Copies a part of the bitmap from @c *this to @formatParam{*dst}.
	/// @param[out] dst								The bitmap to copy this bitmap to. @callerOwnsPointed{bitmap}
	/// @param[in] x									The @em X position of the part to be copied from @c *this.
	/// @param[in] y									The @em Y position of the part to be copied from @c *this.
	/// @param[in] w									The width of the part to be copied.
	/// @param[in] h									The height of the part to be copied.
	/// @return												@trueIfOtherwiseFalse{the bitmap part was successfully copied}
	//----------------------------------------------------------------------------------------
	Bool CopyPartTo(BaseBitmap* dst, Int32 x, Int32 y, Int32 w, Int32 h) const;

	/// @}

	/// @name Bitmap Information
	/// @{

	//----------------------------------------------------------------------------------------
	/// Gets the width of the bitmap in pixels. If the bitmap has not been initialized the return value is 0.
	/// @note Calling this method is the only way to see if a bitmap passed by @C4D or some other source has been initialized.
	/// @return												The bitmap width in pixels, or @em 0 if the bitmap is not initialized.
	//----------------------------------------------------------------------------------------
	Int32 GetBw(void) const { return C4DOS.Bm->GetBw(this); }

	//----------------------------------------------------------------------------------------
	/// Gets the height of the bitmap in pixels.
	/// @return												The bitmap height in pixels.
	//----------------------------------------------------------------------------------------
	Int32 GetBh(void) const { return C4DOS.Bm->GetBh(this); }

	//----------------------------------------------------------------------------------------
	/// Gets the number of bits per pixel.
	/// @return												The number of bits per pixel.
	//----------------------------------------------------------------------------------------
	Int32 GetBt(void) const { return C4DOS.Bm->GetBt(this); }

	//----------------------------------------------------------------------------------------
	/// Gets the number of bytes per line.
	/// @return												The number of bytes per line.
	//----------------------------------------------------------------------------------------
	Int32 GetBpz(void) const { return C4DOS.Bm->GetBpz(this); }

	//----------------------------------------------------------------------------------------
	/// Gets the color mode of the bitmap.
	/// @return												The color mode: @enumerateEnum{COLORMODE}
	//----------------------------------------------------------------------------------------
	COLORMODE GetColorMode(void) const;

	/// @}

	/// @name Scaling
	/// @{

	//----------------------------------------------------------------------------------------
	/// Scales the bitmap to fit in the destination bitmap and copies it there.\n
	/// The destination bitmap @formatParam{dst} needs to be initialized with the destination size before calling this function.
	/// @param[out] dst								The destination bitmap. @callerOwnsPointed{bitmap}
	/// @param[in] intens							Lets you change brightness of the image (@em 128 = <i>50</i>% brightness, @em 256 = unchanged).
	/// @param[in] sample							If @formatConstant{true} a better scaling algorithm is used, which results in a better quality but a bit slower.
	/// @param[in] nprop							Must be @formatConstant{true} if non-proportional scaling is wanted.
	//----------------------------------------------------------------------------------------
	void ScaleIt(BaseBitmap* dst, Int32 intens, Bool sample, Bool nprop) const;

	//----------------------------------------------------------------------------------------
	/// Scales the bitmap rectangle [@formatParam{src_xmin},@formatParam{src_ymin},@formatParam{src_xmax},@formatParam{src_ymax}] to fit in the destination bitmap rectangle [@formatParam{dst_xmin},@formatParam{dst_ymin},@formatParam{dst_xmax},@formatParam{dst_ymax}] and copies it there.\n
	/// The scaling, if necessary, is done using Bicubic interpolation.\n
	/// The destination bitmap @formatParam{dst} needs to be initialized before calling this function.
	/// @note This function can currently only scale down, i.e. the destination needs to be smaller to the source in size.
	/// @param[out] dst								The destination bitmap. @callerOwnsPointed{bitmap}
	/// @param[in] src_xmin						The source top left X coordinate.
	/// @param[in] src_ymin						The source top left Y coordinate.
	/// @param[in] src_xmax						The source bottom right X coordinate.
	/// @param[in] src_ymax						The source bottom right Y coordinate.
	/// @param[in] dst_xmin						The destination top left X coordinate.
	/// @param[in] dst_ymin						The destination top left Y coordinate.
	/// @param[in] dst_xmax						The destination bottom right X coordinate.
	/// @param[in] dst_ymax						The destination bottom right Y coordinate.
	//----------------------------------------------------------------------------------------
	void ScaleBicubic(BaseBitmap* dst, Int32 src_xmin, Int32 src_ymin, Int32 src_xmax, Int32 src_ymax, Int32 dst_xmin, Int32 dst_ymin, Int32 dst_xmax, Int32 dst_ymax) const;

	/// @}

	/// @name Drawing
	/// @{

	//----------------------------------------------------------------------------------------
	/// Sets the color for the following drawing operations.\n
	/// The range of the parameters is @em 0 to @em 255, where (@em 255,@em 255,@em 255) is white, regardless of the bit depth of the image.
	/// @note This method only works with bit depth @em 24 and @em 32.
	/// @param[in] r									The red component.
	/// @param[in] g									The green component.
	/// @param[in] b									The blue component.
	//----------------------------------------------------------------------------------------
	void SetPen(Int32 r, Int32 g, Int32 b) { C4DOS.Bm->SetPen(this, r, g, b); }

	//----------------------------------------------------------------------------------------
	/// Sets all pixels in the bitmap to the color specified by (@formatParam{r},@formatParam{g},@formatParam{b}).\n
	/// The range of the parameters is @em 0 to @em 255, where (@em 255,@em 255,@em 255) is white, regardless of the bit depth of the image.
	/// @note This method only works with bit depth @em 24 and @em 32.
	/// @param[in] r									The red component.
	/// @param[in] g									The green component.
	/// @param[in] b									The blue component.
	//----------------------------------------------------------------------------------------
	void Clear(Int32 r, Int32 g, Int32 b);

	//----------------------------------------------------------------------------------------
	/// Sets all pixels within the rectangle specified by [@formatParam{x1},@formatParam{y1}] and [@formatParam{x2},@formatParam{y2}] to the color specified by (@formatParam{r},@formatParam{g},@formatParam{b}).\n
	/// The range of the parameters is @em 0 to @em 255, where (@em 255,@em 255,@em 255) is white, regardless of the bit depth of the image.
	/// @note This method only works with bit depth @em 24 and @em 32.
	/// @param[in] x1									The top left X coordinate of the rectangle.
	/// @param[in] y1									The top left Y coordinate of the rectangle.
	/// @param[in] x2									The bottom right X coordinate of the rectangle.
	/// @param[in] y2									The bottom right Y coordinate of the rectangle.
	/// @param[in] r									The red component.
	/// @param[in] g									The green component.
	/// @param[in] b									The blue component.
	//----------------------------------------------------------------------------------------
	void Clear(Int32 x1, Int32 y1, Int32 x2, Int32 y2, Int32 r, Int32 g, Int32 b);

	//----------------------------------------------------------------------------------------
	/// Draws a line with the current pen color between (@formatParam{x1},@formatParam{y1}) and (@formatParam{x2},@formatParam{y2}).
	/// @note This method only works with bit depth @em 24 and @em 32.
	/// @param[in] x1									The start X coordinate.
	/// @param[in] y1									The start Y coordinate.
	/// @param[in] x2									The end X coordinate.
	/// @param[in] y2									The end Y coordinate.
	//----------------------------------------------------------------------------------------
	void Line(Int32 x1, Int32 y1, Int32 x2, Int32 y2) { C4DOS.Bm->Line(this, x1, y1, x2, y2); }

	//----------------------------------------------------------------------------------------
	/// Draws an arc (section of a circle) with the current @link SetPen() pen@endlink color at [@formatParam{x},@formatParam{y}].
	/// @param[in] x									The X coordinate.
	/// @param[in] y									The Y coordinate.
	/// @param[in] radius							The radius of the ellipse.
	/// @param[in] angle_start				The start of the angle in radians.
	/// @param[in] angle_end					The end of the angle in radians.
	/// @param[in] subdiv							The range between @formatParam{angle_start} and @formatParam{angle_end} is divided into @formatParam{subdiv} line segments.
	//----------------------------------------------------------------------------------------
	void Arc(Int32 x, Int32 y, Float radius, Float angle_start, Float angle_end, Int32 subdiv = 32) { C4DOS.Bm->Arc(this, x, y, radius, angle_start, angle_end, subdiv); }

	/// @}

	/// @name Get/Set Pixels
	/// @{

	//----------------------------------------------------------------------------------------
	/// Gets the color at [@formatParam{x},@formatParam{y}] and assigns it to the passed (@formatParam{r},@formatParam{g},@formatParam{b}) parameters.\n
	/// The range of the assigned @formatParam{r}, @formatParam{g} and @formatParam{b} parameters is @em 0 to @em 255, where (@em 255,@em 255,@em 255) is white, regardless of the bit depth of the image.
	/// @param[in] x									The X coordinate.
	/// @param[in] y									The Y coordinate.
	/// @param[out] r									Assigned the red component.
	/// @param[out] g									Assigned the green component.
	/// @param[out] b									Assigned the blue component.
	//----------------------------------------------------------------------------------------
	void GetPixel(Int32 x, Int32 y, UInt16* r, UInt16* g, UInt16* b) const { C4DOS.Bm->GetPixel(this, x, y, r, g, b); }

	//----------------------------------------------------------------------------------------
	/// Sets the pixel at [@formatParam{x},@formatParam{y}] to the color specified by (@formatParam{r},@formatParam{g},@formatParam{b}) (0 <= r/g/b <= 255).\n
	/// The range of the @formatParam{r}, @formatParam{g} and @formatParam{b} parameters is @em 0 to @em 255, where (@em 255,@em 255,@em 255) is white, regardless of the bit depth of the image.
	/// @param[in] x									The X coordinate.
	/// @param[in] y									The Y coordinate.
	/// @param[in] r									The red component.
	/// @param[in] g									The green component.
	/// @param[in] b									The blue component.
	/// @return												@trueIfOtherwiseFalse{the pixel was successfully set}
	//----------------------------------------------------------------------------------------
	Bool SetPixel(Int32 x, Int32 y, Int32 r, Int32 g, Int32 b) { return C4DOS.Bm->SetPixel(this, x, y, r, g, b); }

	//----------------------------------------------------------------------------------------
	/// Gets the alpha value at [@formatParam{x},@formatParam{y}] and assigns it to the passed parameter @formatParam{val} (@em 0 <= @formatParam{val} <= @em 255).
	/// @param[in] channel						The alpha channel to use.
	/// @param[in] x									The X coordinate.
	/// @param[in] y									The Y coordinate.
	/// @param[out] val								Assigned the alpha value.
	//----------------------------------------------------------------------------------------
	void GetAlphaPixel(BaseBitmap* channel, Int32 x, Int32 y, UInt16* val) const { C4DOS.Bm->GetAlphaPixel(this, channel, x, y, val); }

	//----------------------------------------------------------------------------------------
	/// Sets the alpha value at [@formatParam{x},@formatParam{y}] to @formatParam{val}.
	/// @param[in] channel						The alpha channel to use.
	/// @param[in] x									The X coordinate.
	/// @param[in] y									The Y coordinate.
	/// @param[in] val								The alpha value. @em 0 <= @formatParam{val} <= @em 255
	//----------------------------------------------------------------------------------------
	Bool SetAlphaPixel(BaseBitmap* channel, Int32 x, Int32 y, Int32 val) { return C4DOS.Bm->SetAlphaPixel(this, channel, x, y, val); }

	//----------------------------------------------------------------------------------------
	/// Reads @formatParam{cnt} pixels from [@formatParam{x},@formatParam{y}] in the bitmap to the @formatParam{buffer} with the color mode @formatParam{dstmode}, incrementing @formatParam{inc} bytes for each pixel.
	/// @param[in] x									The X coordinate of the first pixel to get.
	/// @param[in] y									The Y coordinate of the first pixel to get.
	/// @param[in] cnt								The number of pixels to get.
	/// @param[out] buffer						A pointer to a large enough memory buffer where the pixel data will be written. @callerOwnsPointed{buffer}
	/// @param[in] inc								The byte increment per pixel in the buffer.
	/// @param[in] dstmode						The destination color mode: @enumerateEnum{COLORMODE}
	/// @param[in] flags							The flags: @enumerateEnum{PIXELCNT}
	/// @param[in] conversion					This should be normally set to @formatConstant{nullptr}. Pass a color profile only if a conversion is wanted before retrieving the pixel data.\n
	/// 															This only works if either the bitmap is <i>32</i>-bit per component (so no <i>8</i>/<i>16</i>-bit images) or the @formatParam{dstmode} is <i>32</i>-bit per component.\n
	/// 															The conversion is done before color reduction (e.g. if @formatParam{dstmode} is <i>16</i>-bit the profile is first applied and then the data resampled to <i>16</i>-bit).
	//----------------------------------------------------------------------------------------
	void GetPixelCnt(Int32 x, Int32 y, Int32 cnt, UChar* buffer, Int32 inc, COLORMODE dstmode, PIXELCNT flags, ColorProfileConvert* conversion = nullptr) const { C4DOS.Bm->GetPixelCnt(this, x, y, cnt, buffer, inc, dstmode, flags, conversion); }

	//----------------------------------------------------------------------------------------
	/// Sets @formatParam{cnt} pixels at [@formatParam{x},@formatParam{y}] in the bitmap from @formatParam{buffer} with color mode @formatParam{srcmode}, incrementing @formatParam{inc} bytes for each pixel.
	/// @param[in] x									The X coordinate of the first pixel to set.
	/// @param[in] y									The Y coordinate of the first pixel to set.
	/// @param[in] cnt								The number of pixels to set.
	/// @param[in] buffer							A pointer to a large enough memory buffer containing the pixels to set. @callerOwnsPointed{buffer}
	/// @param[in] inc								The byte increment per pixel in the buffer.
	/// @param[in] srcmode						The source color mode: @enumerateEnum{COLORMODE} @warning None of the alpha modes are supported.
	/// @param[in] flags							The flags: @enumerateEnum{PIXELCNT}
	/// @return												@trueIfOtherwiseFalse{successful}
	//----------------------------------------------------------------------------------------
	Bool SetPixelCnt(Int32 x, Int32 y, Int32 cnt, UChar* buffer, Int32 inc, COLORMODE srcmode, PIXELCNT flags) { return C4DOS.Bm->SetPixelCnt(this, x, y, cnt, buffer, inc, srcmode, flags); }

	/// @}

	/// @name Channels
	/// @{

	//----------------------------------------------------------------------------------------
	/// Adds a new alpha channel to the bitmap.
	/// @note The bitmap class only supports up to @em 4 channels.
	/// @param[in] internal						Should only be @formatConstant{true} for the first alpha. The internal alpha will be stored within a bitmaps if its format supports alphas.
	/// @param[in] straight						Should be @formatConstant{true} if the bitmap has to be interpreted as straight.\n
	/// 															For information about straight alphas please take a look at the corresponding option in the render settings and the manual of @C4D.
	/// @return												The newly added channel if successful, otherwise @formatConstant{nullptr}.
	//----------------------------------------------------------------------------------------
	BaseBitmap* AddChannel(Bool internal, Bool straight);

	//----------------------------------------------------------------------------------------
	/// Removes the specified @formatParam{channel} from the bitmap.
	/// @param[in] channel						The alpha channel to remove.
	//----------------------------------------------------------------------------------------
	void RemoveChannel(BaseBitmap* channel);

	//----------------------------------------------------------------------------------------
	/// Gets the internal read-only alpha channel.\n
	/// @note The internal alpha channel is the one that is saved together with the picture, with those formats that support this.
	/// @return												The read-only internal alpha channel, or @formatConstant{nullptr} if no internal alpha is available. @theOwnsPointed{bitmap, channel}
	//----------------------------------------------------------------------------------------
	const BaseBitmap* GetInternalChannel(void) const;

	//----------------------------------------------------------------------------------------
	/// Gets the internal alpha channel.\n
	/// @note  The internal alpha channel is the one that is saved together with the picture, with those formats that support this.
	/// @return												The read-only internal alpha channel, or @formatConstant{nullptr} if no internal alpha is available. @theOwnsPointed{bitmap, channel}
	//----------------------------------------------------------------------------------------
	BaseBitmap* GetInternalChannel(void);

	//----------------------------------------------------------------------------------------
	/// Gets the number of alpha channels in the bitmap, including the internal channel.
	/// @return												The number of alpha channels.
	//----------------------------------------------------------------------------------------
	Int32 GetChannelCount(void) const;

	//----------------------------------------------------------------------------------------
	/// Gets the read-only alpha channel specified by @formatParam{num}.
	/// @param[in] num								An alpha channel index between @em 0 and GetChannelCount().
	/// @return												The requested read-only channel.
	//----------------------------------------------------------------------------------------
	const BaseBitmap* GetChannelNum(Int32 num) const;

	//----------------------------------------------------------------------------------------
	/// Gets the alpha channel specified by @formatParam{num}.
	/// @param[in] num								An alpha channel index between @em 0 and GetChannelCount().
	/// @return												The requested channel.
	//----------------------------------------------------------------------------------------
	BaseBitmap* GetChannelNum(Int32 num);

	/// @}

	/// @name Get/Set Data
	/// @{

	//----------------------------------------------------------------------------------------
	/// Gets bitmap data. @markPrivate
	/// @param[in] id									The data ID to Get: @enumerateEnum{BASEBITMAP_DATA}
	/// @param[in] t_default					The default data to use.
	/// @return												The retrieved data.
	//----------------------------------------------------------------------------------------
	GeData GetData(Int32 id, const GeData& t_default) const;

	//----------------------------------------------------------------------------------------
	/// Sets bitmap data. @markPrivate
	/// @param[in] id									The data ID to set: @enumerateEnum{BASEBITMAP_DATA}
	/// @param[in] data								The data to set.
	/// @return												@trueIfOtherwiseFalse{the data could be set}
	//----------------------------------------------------------------------------------------
	Bool SetData(Int32 id, const GeData& data);

	/// @}

	/// @name Dirty
	/// @{

	//----------------------------------------------------------------------------------------
	/// Gets the incremented dirty count when the bitmap changes. @markPrivate
	/// @return												The dirty count.
	//----------------------------------------------------------------------------------------
	UInt32 GetDirty() const { return C4DOS.Bm->GetDirty(this); }

	//----------------------------------------------------------------------------------------
	/// Makes the bitmap dirty. @markPrivate
	//----------------------------------------------------------------------------------------
	void SetDirty() { C4DOS.Bm->SetDirty(this); }

	/// @}

	/// @name Update Region
	/// @{

	//----------------------------------------------------------------------------------------
	/// Gets the updated region of a bitmap (read-only).
	/// @return												The updated region.
	//----------------------------------------------------------------------------------------
	const BaseBitmap* GetUpdateRegionBitmap() const { return C4DOS.Bm->GetUpdateRegionBitmap(this); }

	//----------------------------------------------------------------------------------------
	/// Gets the updated region of a bitmap.
	/// @return												The updated region.
	//----------------------------------------------------------------------------------------
	BaseBitmap* GetUpdateRegionBitmap() { return C4DOS.Bm->GetUpdateRegionBitmap(this); }

	/// @}

	/// @name Color Profile
	/// @{

	//----------------------------------------------------------------------------------------
	/// Sets the color profile for the bitmap.
	/// @param[in] profile						The new color profile. @callerOwnsPointed{color profile}
	/// @return												@trueIfOtherwiseFalse{the color profile was successfully set}
	//----------------------------------------------------------------------------------------
	Bool SetColorProfile(const ColorProfile* profile) { return C4DOS.Bm->SetColorProfile(this, profile); }

	//----------------------------------------------------------------------------------------
	/// Gets the color profile of the bitmap.
	/// @return												The color profile of the bitmap, or @formatConstant{nullptr} if not available.
	//----------------------------------------------------------------------------------------
	const ColorProfile* GetColorProfile() const { return C4DOS.Bm->GetColorProfile(this); }

	/// @}

	/// @name Miscellaneous
	/// @{

	//----------------------------------------------------------------------------------------
	/// Gets the size of the memory used by the bitmap.
	/// @return												The memory size of the bitmap.
	//----------------------------------------------------------------------------------------
	Int GetMemoryInfo(void) const { return C4DOS.Bm->GetMemoryInfo(this); }

	//----------------------------------------------------------------------------------------
	/// Checks if this BaseBitmap instance is a MultipassBitmap.
	/// @return												@trueIfOtherwiseFalse{the instance can be safely cast to MultipassBitmap}
	//----------------------------------------------------------------------------------------
	Bool IsMultipassBitmap(void) const;

	//----------------------------------------------------------------------------------------
	/// If the image in the bitmap has <i>8</i>-bit indexed color, this function can be used to set the palette entries.
	/// @note All four parameters must be between @em 0 and @em 255.
	/// @param[in] i									The index. @em 0 <= @formatParam{i} <= @em 255
	/// @param[in] r									The red component. @em 0 <= @formatParam{r} <= @em 255
	/// @param[in] g									The green component. @em 0 <= @formatParam{g} <= @em 255
	/// @param[in] b									The blue component. @em 0 <= @formatParam{b} <= @em 255
	//----------------------------------------------------------------------------------------
	void SetCMAP(Int32 i, Int32 r, Int32 g, Int32 b);

	//----------------------------------------------------------------------------------------
	/// Gets the ImageRef for a BaseBitmap. The reference is stored internally. For the same saveBit / alpha pair you will get the same reference.
	/// @param[in] saveBit						A combination of the following flags: @enumerateEnum{SAVEBIT}
	/// @param[in] alpha							True, if you need the alpha image, false otherwise.
	/// @param[out] imageRef					A reference that gets the imageRef assigned.
	/// @return												@trueIfOtherwiseFalse{the function succeeded}
	//----------------------------------------------------------------------------------------
	Bool GetImageRef(SAVEBIT saveBit, Bool alpha, maxon::ImageRef& imageRef) const { return C4DOS.Bm->GetImageRef(this, saveBit, alpha, imageRef); }

	/// @}
};


//-------------------------------------------------------------------------------------------------
/// This is an extension of the BaseBitmap class that supports higher bit depths, floating point images and multiple layers.\n
/// The layers are stored hierarchically. There are three kinds of layers:
/// - Layer : A regular layer, with full range of functionality.
/// - Folder : A collection of layers. This is a dummy element that has no image content, but other stuff like name, visibility etc.
/// - Alpha : An alpha channel layer, with full range of functionality.
///
/// @addAllocFreeAutoAllocNote
/// @note This represents internally the same class as VPBuffer, so a VPBuffer can be cast to a MultipassBitmap and vice versa.
//-------------------------------------------------------------------------------------------------
class MultipassBitmap : public BaseBitmap
{
private:
	MultipassBitmap();
	~MultipassBitmap();

public:

	/// @name Alloc/Free
	/// @{

	//----------------------------------------------------------------------------------------
	/// Allocates a multipass bitmap of size [@formatParam{bx},@formatParam{by}] and bit depth given by @formatParam{mode}. The first RGBA layer is also created.\n
	/// Use Free() to deallocate the bitmap.
	/// @param[in] bx									The width in pixels.
	/// @param[in] by									The height in pixels.
	/// @param[in] mode								The color mode: @enumerateEnum{COLORMODE}
	/// @return												@allocReturn{multipass bitmap}
	//----------------------------------------------------------------------------------------
	static MultipassBitmap* Alloc(Int32 bx, Int32 by, COLORMODE mode) { return C4DOS.Bm->MPB_AllocWrapperPB(bx, by, mode); }

	//----------------------------------------------------------------------------------------
	/// Allocates a multipass wrapper for @formatParam{bmp}.\n
	/// The wrapped bitmap has to stay alive and not be freed until after the allocated wrapper has been freed.\n
	/// The returned multipass wrapper can be modified freely.
	/// @param[in] bmp								The bitmap to wrap. @callerOwnsPointed{bitmap}
	/// @return												@allocReturn{wrapper bitmap}
	//----------------------------------------------------------------------------------------
	static MultipassBitmap* AllocWrapper(BaseBitmap* bmp) { return C4DOS.Bm->MPB_AllocWrapper(bmp); }

	//----------------------------------------------------------------------------------------
	/// @destructsAlloc{multipass bitmaps}
	/// @param[in] bm									@theToDestruct{multipass bitmap}
	//----------------------------------------------------------------------------------------
	static void Free(MultipassBitmap*& bm);

	/// @}

	/// @name Layers
	/// @{

	//----------------------------------------------------------------------------------------
	/// Gets the number of layers in the bitmap. This is the sum of the number of layers, folders and alphas that are direct children of the multipass bitmap.
	/// @return												The layer count.
	//----------------------------------------------------------------------------------------
	Int32 GetLayerCount() const { return C4DOS.Bm->MPB_GetLayerCount(this); }

	//----------------------------------------------------------------------------------------
	/// Gets the number of alpha layers in the multipass bitmap.
	/// @return												The alpha layer count.
	//----------------------------------------------------------------------------------------
	Int32 GetAlphaLayerCount() const { return C4DOS.Bm->MPB_GetAlphaLayerCount(this); }

	//----------------------------------------------------------------------------------------
	/// Gets the number of hidden layers in the multipass bitmap.
	/// @return												The hidden layer count.
	//----------------------------------------------------------------------------------------
	Int32 GetHiddenLayerCount() const { return C4DOS.Bm->MPB_GetHiddenLayerCount(this); }

	//----------------------------------------------------------------------------------------
	/// Gets the currently selected layer.
	/// @return												The selected layer, or @formatConstant{nullptr} if the operation failed. @theOwnsPointed{multipass bitmap, layer}
	//----------------------------------------------------------------------------------------
	MultipassBitmap* GetSelectedLayer() { return C4DOS.Bm->MPB_GetSelectedLayer(this); }

	//----------------------------------------------------------------------------------------
	/// Gets the layer at index @formatParam{num}.
	/// @param[in] num								The layer index: @em 0 <= @formatParam{num} < GetLayerCount().
	/// @return												The retrieved layer, or @formatConstant{nullptr} if the operation failed. @theOwnsPointed{multipass bitmap, layer}
	//----------------------------------------------------------------------------------------
	MultipassBitmap* GetLayerNum(Int32 num) { return C4DOS.Bm->MPB_GetLayerNum(this, num); }

	//----------------------------------------------------------------------------------------
	/// Gets the alpha layer at index @formatParam{num}.
	/// @param[in] num								The alpha layer index: @em 0 <= @formatParam{num} < GetAlphaLayerCount().
	/// @return												The retrieved alpha layer, or @formatConstant{nullptr} if the operation failed. @theOwnsPointed{multipass bitmap, alpha layer}
	//----------------------------------------------------------------------------------------
	MultipassBitmap* GetAlphaLayerNum(Int32 num) { return C4DOS.Bm->MPB_GetAlphaLayerNum(this, num); }

	//----------------------------------------------------------------------------------------
	/// Gets the hidden layer at index @formatParam{num}.
	/// @param[in] num								The hidden layer index: @em 0 <= @formatParam{num} < GetHiddenLayerCount().
	/// @return												The retrieved hidden layer, or @formatConstant{nullptr} if the operation failed. @theOwnsPointed{multipass bitmap, alpha layer}
	//----------------------------------------------------------------------------------------
	MultipassBitmap* GetHiddenLayerNum(Int32 num) { return C4DOS.Bm->MPB_GetHiddenLayerNum(this, num); }

	//----------------------------------------------------------------------------------------
	/// Adds a layer with mode @formatParam{colormode} after @formatParam{insertafter} in the multipass bitmap.
	/// @param[in] insertafter				The layer to insert after. Pass @formatConstant{nullptr} to insert first or ::BMP_INSERTLAST to insert last.
	/// @param[in] colormode					The color mode of the new layer: @enumerateEnum{COLORMODE}
	/// @param[in] hidden							If @formatConstant{true} the layer is hidden.
	/// @return												The added layer, or @formatConstant{nullptr} if the operation failed. @theOwnsPointed{multipass bitmap, layer}
	//----------------------------------------------------------------------------------------
	MultipassBitmap* AddLayer(MultipassBitmap* insertafter, COLORMODE colormode, Bool hidden = false) { return C4DOS.Bm->MPB_AddLayer(this, insertafter, colormode, hidden); }

	//----------------------------------------------------------------------------------------
	/// Adds a folder after @formatParam{insertafter} in the bitmap.
	/// @param[in] insertafter				The layer to insert after. Pass @formatConstant{nullptr} to insert first or ::BMP_INSERTLAST to insert last.
	/// @param[in] hidden							If @formatConstant{true} the layer is hidden.
	/// @return												The added folder, or @formatConstant{nullptr} if the operation failed. @theOwnsPointed{multipass bitmap, folder}
	//----------------------------------------------------------------------------------------
	MultipassBitmap* AddFolder(MultipassBitmap* insertafter, Bool hidden = false) { return C4DOS.Bm->MPB_AddFolder(this, insertafter, hidden); }

	//----------------------------------------------------------------------------------------
	/// Adds an alpha layer with mode @formatParam{colormode} after @formatParam{insertafter} in the bitmap.
	/// @param[in] insertafter				The layer to insert after. Pass @formatConstant{nullptr} to insert first or ::BMP_INSERTLAST to insert last.
	/// @param[in] colormode					The color mode of the new alpha layer: @enumerateEnum{COLORMODE}
	/// @return												The added alpha layer, or @formatConstant{nullptr} if the operation failed. @theOwnsPointed{multipass bitmap, alpha layer}
	//----------------------------------------------------------------------------------------
	MultipassBitmap* AddAlpha(MultipassBitmap* insertafter, COLORMODE colormode) { return C4DOS.Bm->MPB_AddAlpha(this, insertafter, colormode); }

	//----------------------------------------------------------------------------------------
	/// Deletes @formatParam{layer} from the bitmap, freeing its memory.
	/// @param[in] layer							The layer to delete. The pointer will be set to @formatConstant{nullptr} if the operation is successful, since the layer does not exist afterwards.
	/// @return												@trueIfOtherwiseFalse{@formatParam{layer} was successfully deleted}
	//----------------------------------------------------------------------------------------
	Bool DeleteLayer(MultipassBitmap*& layer) { Bool ret = C4DOS.Bm->MPB_DeleteLayer(this, layer); layer = nullptr; return ret; }

	//----------------------------------------------------------------------------------------
	/// Sets the master alpha layer. This just stores the pointer, it does not add a new layer.
	/// @param[in] master							The new master alpha layer.
	//----------------------------------------------------------------------------------------
	void SetMasterAlpha(BaseBitmap* master) { C4DOS.Bm->MPB_SetMasterAlpha(this, master); }

	//-------------------------------------------------------------------------------------------------
	/// Free the hidden layers.
	//-------------------------------------------------------------------------------------------------
	void FreeHiddenLayers() { C4DOS.Bm->MPB_FreeHiddenLayers(this); }

	/// @}

	/// @name Get Layers
	/// @{

	//----------------------------------------------------------------------------------------
	/// Fills the passed array with all the layers specified by @formatParam{flags}.
	/// @param[in] list								The array filled with the layers as BaseBitmap*.
	/// @param[in] flags							The flags: @enumerateEnum{MPB_GETLAYERS}
	/// @return												@trueIfOtherwiseFalse{the layers could be obtained}
	//----------------------------------------------------------------------------------------
	Bool GetLayers(maxon::BaseArray<BaseBitmap*>& list, MPB_GETLAYERS flags = MPB_GETLAYERS::IMAGE | MPB_GETLAYERS::ALPHA);

	//----------------------------------------------------------------------------------------
	/// Fills the passed array with all the layers specified by @formatParam{flags}.
	/// @param[in] list								The array filled with the layers as MultipassBitmap*.
	/// @param[in] flags							The flags: @enumerateEnum{MPB_GETLAYERS}
	/// @return												@trueIfOtherwiseFalse{the layers could be obtained}
	//----------------------------------------------------------------------------------------
	Bool GetLayers(maxon::BaseArray<MultipassBitmap*>& list, MPB_GETLAYERS flags = MPB_GETLAYERS::IMAGE | MPB_GETLAYERS::ALPHA);

	/// @}

	/// @name Get/Set Layers Parameter
	/// @{

	//----------------------------------------------------------------------------------------
	/// Gets a layer parameter.
	/// @param[in] id									The layer parameter ID: @enumerateEnum{MPBTYPE}
	/// @return												The retrieved layer parameter data.
	//----------------------------------------------------------------------------------------
	GeData GetParameter(MPBTYPE id) const { return C4DOS.Bm->MPB_GetParameter(this, id); }

	//----------------------------------------------------------------------------------------
	/// Sets a layer parameter.
	/// @param[in] id									The layer parameter ID: @enumerateEnum{MPBTYPE}
	/// @param[in] par								The new parameter data.
	/// @return												@trueIfOtherwiseFalse{the layer parameter was successfully set}
	//----------------------------------------------------------------------------------------
	Bool SetParameter(MPBTYPE id, const GeData& par) { return C4DOS.Bm->MPB_SetParameter(this, id, par); }

	/// @}

	/// @name Miscellaneous
	/// @{

	//-------------------------------------------------------------------------------------------------
	/// Clears the image data for all layers. The layers themselves are not removed or deleted.
	//-------------------------------------------------------------------------------------------------
	void ClearImageData(void) { C4DOS.Bm->MPB_ClearImageData(this); }

	//----------------------------------------------------------------------------------------
	/// Finds a layer in the bitmap with its @formatParam{id}.
	/// @param[in] id									The main layer ID. @see ::MPBTYPE::USERID.
	/// @param[in] subid							The sub layer ID. @see ::MPBTYPE::USERID.
	/// @return												The found layer, or @formatConstant{nullptr} if the operation failed. @theOwnsPointed{multipass bitmap, layer}
	//----------------------------------------------------------------------------------------
	MultipassBitmap* FindUserID(Int32 id, Int32 subid = 0) { return C4DOS.Bm->MPB_FindUserID(this, id, subid); }

	//----------------------------------------------------------------------------------------
	/// Gets a @BP3D paint bitmap for the multipass bitmap.
	/// @return												The paint bitmap.
	//----------------------------------------------------------------------------------------
	PaintBitmap* GetPaintBitmap() { return C4DOS.Bm->MPB_GetPaintBitmap(this); }

	//----------------------------------------------------------------------------------------
	/// Gets the user ID for the layer. In the renderer this is @em VPBUFFER_XXX.
	/// @return												The user ID for the layer.
	//----------------------------------------------------------------------------------------
	Int32 GetUserID(void) const;

	//----------------------------------------------------------------------------------------
	/// Sets the user ID for the layer. In the renderer this is @em VPBUFFER_XXX.
	/// @param[in] id									The new user ID for the layer.
	//----------------------------------------------------------------------------------------
	void SetUserID(Int32 id);

	//----------------------------------------------------------------------------------------
	/// Sets the user sub-id for the layer. In the renderer this is used for blend channels for instance.
	/// @param[in] subid							The new user sub-ID for the layer.
	//----------------------------------------------------------------------------------------
	void SetUserSubID(Int32 subid);

	//----------------------------------------------------------------------------------------
	/// Adjusts the blend mode of a layer. This also shows up in the description UI of a layer (::ID_PAINTLAYER_BLEND parameter).
	/// @param[in] mode								The values are declared in @em bplayer.h under the ::ID_PAINTLAYER_BLEND parameter.
	//----------------------------------------------------------------------------------------
	void SetBlendMode(Int32 mode);

	//----------------------------------------------------------------------------------------
	/// Sets the name of the layer.
	/// @param[in] name								The new name.
	//----------------------------------------------------------------------------------------
	void SetName(const maxon::String& name);

	//----------------------------------------------------------------------------------------
	/// Sets the color mode for the layer.
	/// @param[in] mode								The new color mode.
	//----------------------------------------------------------------------------------------
	void SetColorMode(COLORMODE mode);

	//-------------------------------------------------------------------------------------------------
	/// @markPrivate
	//-------------------------------------------------------------------------------------------------
	void SetDpi(Int32 dpi);

	//-------------------------------------------------------------------------------------------------
	/// @markPrivate
	//-------------------------------------------------------------------------------------------------
	Bool SetTempColorProfile(const ColorProfile* profile, Bool dithering);

	//-------------------------------------------------------------------------------------------------
	/// @markPrivate
	//-------------------------------------------------------------------------------------------------
	void SetSave(Bool save);

	//-------------------------------------------------------------------------------------------------
	/// @markPrivate
	//-------------------------------------------------------------------------------------------------
	void SetComponent(Int32 c);

	/// @}
};

/// A special MultipassBitmap that can be used to indicate to position a layer last in the list.
/// @see MultipassBitmap::AddLayer() / MultipassBitmap::AddFolder() / MultipassBitmap::AddAlpha()
#define BMP_INSERTLAST ((MultipassBitmap*)-1)


//-------------------------------------------------------------------------------------------------
/// An alias link to a @link BaseBitmap bitmap@endlink. If the bitmap is deleted it will return @formatConstant{nullptr}.
/// @addAllocFreeAutoAllocNote
//-------------------------------------------------------------------------------------------------
class BaseBitmapLink
{
private:
	BaseBitmapLink ();
	~BaseBitmapLink ();

public:

	/// @name Alloc/Free
	/// @{

	//----------------------------------------------------------------------------------------
	/// @allocatesA{bitmap link}
	/// @return												@allocReturn{bitmap link}
	//----------------------------------------------------------------------------------------
	static BaseBitmapLink* Alloc(void);

	//----------------------------------------------------------------------------------------
	/// @destructsAlloc{bitmap links}
	/// @param[in] bll								@theToDestruct{bitmap link}
	//----------------------------------------------------------------------------------------
	static void Free(BaseBitmapLink*& bll);

/// @}

	/// @name Get/Set Link
	/// @{

	//----------------------------------------------------------------------------------------
	/// Gets the linked bitmap.
	/// @return												The linked bitmap, or @formatConstant{nullptr} if the bitmap was deleted.
	//----------------------------------------------------------------------------------------
	BaseBitmap* Get() const;

	//----------------------------------------------------------------------------------------
	/// Sets the link for the bitmap.
	/// @param[in] bmp								The bitmap to be linked.
	//----------------------------------------------------------------------------------------
	void Set(BaseBitmap* bmp);

/// @}
};

//-------------------------------------------------------------------------------------------------
/// The movie loader class is used to read movie streams.
/// @addAllocFreeAutoAllocNote
//-------------------------------------------------------------------------------------------------
class MovieLoader
{
private:
	MovieLoader();
	~MovieLoader();

	void InitData(void);
	void FreeData(void);

public:

	/// @name Alloc/Free
	/// @{

	//----------------------------------------------------------------------------------------
	/// @allocatesA{movie loader}
	/// @return												@allocReturn{movie loader}
	//----------------------------------------------------------------------------------------
	static MovieLoader* Alloc(void);

	//----------------------------------------------------------------------------------------
	/// @destructsAlloc{movie loaders}
	/// @param[in] ml									@theToDestruct{ml}
	//----------------------------------------------------------------------------------------
	static void Free(MovieLoader*& ml);

/// @}

	//----------------------------------------------------------------------------------------
	/// Opens a movie file.
	/// @param[in] fn									The filename of the movie clip to open.
	/// @return												The result. The possible values are: @enumerateEnum{IMAGERESULT}
	//----------------------------------------------------------------------------------------
	IMAGERESULT Open(const Filename& fn);

	//-------------------------------------------------------------------------------------------------
	/// Close the loaded movie file.
	//-------------------------------------------------------------------------------------------------
	void Close(void);

	//----------------------------------------------------------------------------------------
	/// Reads a frame of the loaded movie clip.
	/// @param[in] new_frame_idx			The frame number of the frame to be read.
	/// @param[out] _result						The result. Assigned one of these values: @enumerateEnum{IMAGERESULT}
	/// @return												The frame's bitmap.
	//----------------------------------------------------------------------------------------
	BaseBitmap* Read(Int32 new_frame_idx = -1, Int32* _result = nullptr);

	//----------------------------------------------------------------------------------------
	/// Gets information about the movie's frame count and frames per second.
	/// @param[out] _fps							Assigned the frames per second.
	/// @return												The frame count.
	//----------------------------------------------------------------------------------------
	Int32 GetInfo(Float* _fps);

private:
	BitmapLoaderPlugin* plugin;
	BitmapLoaderAnimatedData plugin_data;
	BaseBitmap* bm;
	Bool is_movie;
	Int32 frame_cnt;
	Float fps;
	Int32 frame_idx;
	IMAGERESULT result;
};


//-------------------------------------------------------------------------------------------------
/// The movie saver class is used to write movie streams.
/// @addAllocFreeAutoAllocNote
//-------------------------------------------------------------------------------------------------
class MovieSaver
{
private:
	MovieSaver();
	~MovieSaver();

public:

	/// @name Alloc/Free
	/// @{

	//----------------------------------------------------------------------------------------
	/// @allocatesA{movie saver}
	/// @return												@allocReturn{movie saver}
	//----------------------------------------------------------------------------------------
	static MovieSaver* Alloc(void);

	//----------------------------------------------------------------------------------------
	/// @destructsAlloc{movie savers}
	/// @param[in] ms									@theToDestruct{movie saver}
	//----------------------------------------------------------------------------------------
	static void Free(MovieSaver*& ms);

	/// @}

	//----------------------------------------------------------------------------------------
	/// Opens a movie stream to the file name. The resolution and bit depth are defined by the first frame in @formatParam{bm}. The framerate is specified by @formatParam{fps}.
	/// @param[in] name								A valid filename to save the movie to.
	/// @param[in] bm									A typical frame of the movie, used for dimensions. @callerOwnsPointed{bitmap}
	/// @param[in] fps								The frame rate in frames per second.
	/// @param[in] format							The file format. Valid values are:
	/// 															- ::FILTER_AVI
	/// 															- ::FILTER_MOVIE.
	/// @param[in] data								The additional settings for the file format. @callerOwnsPointed{container} Valid IDs are:\n
	/// 															For ::FILTER_AVI: @enumerateEnum{AVISAVER}\n
	/// 															For ::FILTER_MOVIE: @enumerateEnum{QTSAVER}
	/// @param[in] savebits						Can be a combination of the following flags: @enumerateEnum{SAVEBIT}
	/// @param[in] sound							The sound data to be written to the movie.
	/// @return												The result. Possible values are: @enumerateEnum{IMAGERESULT}
	//----------------------------------------------------------------------------------------
	IMAGERESULT Open(const Filename& name, BaseBitmap* bm, Int32 fps, Int32 format, BaseContainer* data, SAVEBIT savebits, BaseSound* sound = nullptr);

	//----------------------------------------------------------------------------------------
	/// Adds another frame to the end of the movie stream.
	/// @param[in] bm									The frame to add. The pointed bitmap is copied.
	/// @return												The result: @enumerateEnum{IMAGERESULT}
	//----------------------------------------------------------------------------------------
	IMAGERESULT Write(BaseBitmap* bm);

	//-------------------------------------------------------------------------------------------------
	/// Closes the movie stream.
	//-------------------------------------------------------------------------------------------------
	void Close(void);

	//----------------------------------------------------------------------------------------
	/// Opens the standard compression chooser for movie formats. The new settings are stored in @formatParam{bc} if the user clicks @em OK.
	/// @param[in] format							The file format. Valid values are:
	/// 															- ::FILTER_AVI
	/// 															- ::FILTER_MOVIE.
	/// @param[out] bc								Used to pass the default settings, and to read the settings the user has chosen. @callerOwnsPointed{container}
	/// @return												@trueIfOtherwiseFalse{the user clicks @em OK and everything is alright}
	//----------------------------------------------------------------------------------------
	Bool Choose(Int32 format, BaseContainer* bc);
};


class PluginMovieData;

//-------------------------------------------------------------------------------------------------
/// The @link BaseBitmap bitmap@endlink loader class is used to read images. Cannot be instantiated.\n
/// Call FindPlugin() or FilterPluginList() with the plugin type ::PLUGINTYPE::BITMAPFILTER to retrieve bitmap loader instances.\n
/// Alternatively browse through all the plugin instances with GetFirstPlugin().
//-------------------------------------------------------------------------------------------------
class BitmapLoaderPlugin : public BasePlugin
{
private:
	BitmapLoaderPlugin();
	~BitmapLoaderPlugin();

public:
	//-------------------------------------------------------------------------------------------------
	/// Calls BitmapLoaderData::Identify().
	//-------------------------------------------------------------------------------------------------
	Bool BmIdentify(const Filename& name, UChar* probe, Int32 size);

	//-------------------------------------------------------------------------------------------------
	/// Calls BitmapLoaderData::Load().
	//-------------------------------------------------------------------------------------------------
	IMAGERESULT BmLoad(const Filename& name, BaseBitmap* bm, Int32 frame);

	//-------------------------------------------------------------------------------------------------
	/// Calls BitmapLoaderData::GetSaver().
	//-------------------------------------------------------------------------------------------------
	Int32 BmGetSaver(void);

	//-------------------------------------------------------------------------------------------------
	/// Calls BitmapLoaderData::GetInformation().
	//-------------------------------------------------------------------------------------------------
	Bool BmGetInformation(const Filename& name, Int32* frames, Float* fps);

	//-------------------------------------------------------------------------------------------------
	/// Calls BitmapLoaderData::LoadAnimated().
	//-------------------------------------------------------------------------------------------------
	IMAGERESULT BmLoadAnimated(BitmapLoaderAnimatedData* bd, BITMAPLOADERACTION action, BaseBitmap* bm, Int32 frame);

	//-------------------------------------------------------------------------------------------------
	/// Calls BitmapLoaderData::ExtractSound().
	//-------------------------------------------------------------------------------------------------
	IMAGERESULT BmExtractSound(BitmapLoaderAnimatedData* bd, BaseSound* snd);

	//-------------------------------------------------------------------------------------------------
	/// Calls BitmapLoaderData::HasSound().
	//-------------------------------------------------------------------------------------------------
	IMAGERESULT BmHasSound(BitmapLoaderAnimatedData* bd);
};


//-------------------------------------------------------------------------------------------------
/// The @link BaseBitmap bitmap@endlink saver class is used to write images. Cannot be instantiated\n
/// Call FindPlugin() or FilterPluginList() with the plugin type ::PLUGINTYPE::BITMAPFILTER to retrieve bitmap loader instances.\n
/// Alternatively browse through all the plugin instances with GetFirstPlugin().
//-------------------------------------------------------------------------------------------------
class BitmapSaverPlugin : public BasePlugin
{
private:
	BitmapSaverPlugin();
	~BitmapSaverPlugin();

public:

	//----------------------------------------------------------------------------------------
	/// Retrieves the BitmapSaverData::GetMaxAlphas() information and the registered suffix of the saver.
	/// @param[out] alpha							Assigned the number of alpha channels.
	/// @param[out] suffix						Assigned the registered suffix string.
	//----------------------------------------------------------------------------------------
	void BmGetDetails(Int32* alpha, maxon::String* suffix);

	//-------------------------------------------------------------------------------------------------
	/// Calls BitmapSaverData::Edit().
	//-------------------------------------------------------------------------------------------------
	Bool BmEdit(BaseContainer* data);

	//-------------------------------------------------------------------------------------------------
	/// Calls BitmapSaverData::GetMaxResolution().
	//-------------------------------------------------------------------------------------------------
	Int32 BmGetMaxResolution(Bool layers);

	//----------------------------------------------------------------------------------------
	/// CorrectResolution corrects the given input size to the preferred saver size.
	/// @since R19
	/// @param[in] settings						Optional settings to use.
	/// @param[in] videoWidth					Resolution width to check.
	/// @param[in] videoHeight				Resolution height to check.
	/// @param[out] videoWidthPadded	Corrected resolution width.
	/// @param[out] videoHeightPadded	Corrected resolution height.
	//----------------------------------------------------------------------------------------
	void BmCorrectResolution(const BaseContainer* settings, Int32 videoWidth, Int32 videoHeight, Int32& videoWidthPadded, Int32& videoHeightPadded);

	//-------------------------------------------------------------------------------------------------
	/// Calls BitmapSaverData::Save().
	//-------------------------------------------------------------------------------------------------
	IMAGERESULT BmSave(const Filename& name, BaseBitmap* bm, BaseContainer* data, SAVEBIT savebits);

	//-------------------------------------------------------------------------------------------------
	/// Calls BitmapSaverData::Open().
	//-------------------------------------------------------------------------------------------------
	IMAGERESULT BmOpen(PluginMovieData*& md, const Filename& name, BaseBitmap* bm, BaseContainer* data, SAVEBIT savebits, Int32 fps);

	//-------------------------------------------------------------------------------------------------
	/// Calls BitmapSaverData::Write().
	//-------------------------------------------------------------------------------------------------
	IMAGERESULT BmWrite(PluginMovieData* md, BaseBitmap* bm);

	//-------------------------------------------------------------------------------------------------
	/// Calls BitmapSaverData::Close().
	//-------------------------------------------------------------------------------------------------
	void BmClose(PluginMovieData*& md);
};

//-------------------------------------------------------------------------------------------------
/// A simple BaseBitmap wrapper created from a filename or resource ID.
//-------------------------------------------------------------------------------------------------
class AutoBitmap
{
private:
	BaseBitmap* bmp;

public:

	/// @name  Allocations
	/// @{

	//----------------------------------------------------------------------------------------
	/// Allocates a bitmap by filename string and optional pixel ratio.
	/// @param[in] str								The bitmap filename string. Must be inside the @em res folder of a plugin data.
	/// @param[in] pixelRatio					An optional pixel ratio.
	//----------------------------------------------------------------------------------------
	explicit AutoBitmap(const maxon::String& str, Float pixelRatio = 1.0);

	//----------------------------------------------------------------------------------------
	/// Allocates a bitmap by icon ID registered with RegisterIcon().
	/// @param[in] id									A registered icon ID.
	//----------------------------------------------------------------------------------------
	explicit AutoBitmap(Int32 id);

	//-------------------------------------------------------------------------------------------------
	/// Destructs the allocated AutoBitmap.
	//-------------------------------------------------------------------------------------------------
	~AutoBitmap();

	/// @}

	/// @name Operators
	/// @{

	//----------------------------------------------------------------------------------------
	/// Gets the internal BaseBitmap pointer.
	/// @return												The internal BaseBitmap pointer, or @formatConstant{nullptr} if no bitmap has been allocated.
	//----------------------------------------------------------------------------------------
	operator BaseBitmap*() const { return bmp; }

	/// @}
};

//----------------------------------------------------------------------------------------
/// Loads the global icon with ID @formatParam{resource_id}.\n
/// @C4D registers hundreds of its icons at program start and this way you can access them, for example ::RESOURCEIMAGE_MOVE is the move symbol. It is also possible to access the icons for commands.
/// @param[in] resource_id				The resource ID to load.
/// @return												The loaded icon.
//----------------------------------------------------------------------------------------
IconData InitResourceIcon(Int32 resource_id);

//----------------------------------------------------------------------------------------
/// Loads the global icon with ID @formatParam{resource_id} as a @link BaseBitmap bitmap@endlink.\n
/// @C4D registers hundreds of its icons at program start and this way you can access them, for example ::RESOURCEIMAGE_MOVE is the move symbol. It is also possible to access the icons for commands.
/// @param[in] resource_id				The resource ID to load.
/// @return												The loaded bitmap.
//----------------------------------------------------------------------------------------
BaseBitmap* InitResourceBitmap(Int32 resource_id);

//----------------------------------------------------------------------------------------
/// Extracts the DataDictionary from the BaseContainer.\n
/// The DataDictionary stores the image format settings.
/// @param[in] data								BaseContainer to extract.
/// @param[in] filterId						Filter id to separate settings between different filters.
/// @return												Extracted DataDictionary.
//----------------------------------------------------------------------------------------
maxon::Result<maxon::DataDictionary> GetImageSettingsDictionary(const BaseContainer* data, Int32 filterId);

//----------------------------------------------------------------------------------------
/// Replaces the DataDictionary in the BaseContainer.\n
/// The DataDictionary stores the image format settings.
/// @param[in] settings						Settings to replace
/// @param[out] data							BaseContainer to modify.
/// @param[in] filterId						Filter id to separate settings between different filters.
/// @return												OK on success.
//----------------------------------------------------------------------------------------
maxon::Result<void> SetImageSettingsDictionary(const maxon::DataDictionary& settings, BaseContainer* data, Int32 filterId);

#endif

class BitmapSaverPlugin;

Bool BitmapSaverPluginSupport(BitmapSaverPlugin* bp, Int flags);
Bool BitmapSaverPluginSupport(Int32 format, Int flags);

Bool BitmapSaverPluginIsMovie(BitmapSaverPlugin* bp);
Bool BitmapSaverPluginIsMovie(Int32 format);

#endif // C4D_BASEBITMAP_H__
