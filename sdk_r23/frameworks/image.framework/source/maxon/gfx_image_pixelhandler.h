#ifndef GFX_IMAGE_PIXELHANDLER_H__
#define GFX_IMAGE_PIXELHANDLER_H__

#include "maxon/gfx_image_pixelformat.h"
#include "maxon/gfx_image_colorprofile.h"
#include "maxon/job.h"
#include "maxon/vector2d.h"
#include "maxon/range.h"


namespace maxon
{

//----------------------------------------------------------------------------------------
/// Several functions use this helper structure to pass the position within an image and number of pixels to functions.
//----------------------------------------------------------------------------------------
struct ImagePos
{
	Int xPos, yPos, count;

	ImagePos(Int xPosition, Int yPosition, Int countValue) : xPos(xPosition), yPos(yPosition), count(countValue) { }
};



//----------------------------------------------------------------------------------------
/// Helper class returned by GetPixelHandler. This class provides/caches a fast the access to pixels.
/// A lambda contains the most efficient code to access the pixel data.
/// This object is only valid as long as the bitmap properties (pixel format, pixel storage layout, width, height) wont change.
//----------------------------------------------------------------------------------------
struct GetPixelHandlerStruct
{
	MAXON_DISALLOW_COPY_AND_ASSIGN(GetPixelHandlerStruct);

public:
	using GetFunc = Delegate<Result<void>(const ImagePos &pos, const PixelMutableBuffer &buffer, GETPIXELFLAGS flags)>;
	using FreeFunc = Delegate<void(GetPixelHandlerStruct& selfPtr)>;

	//----------------------------------------------------------------------------------------
	/// Default Constructor. Initializes everything with nullptr.
	//----------------------------------------------------------------------------------------
	GetPixelHandlerStruct()
	{
	}

	//----------------------------------------------------------------------------------------
	/// Move Constructor.
	//----------------------------------------------------------------------------------------
	GetPixelHandlerStruct(GetPixelHandlerStruct&& other) :
		_getFunc(std::move(other._getFunc)),
		_freeFunc(std::move(other._freeFunc)),
		_targetColorProfile(std::move(other._targetColorProfile))
	{
	}

	//----------------------------------------------------------------------------------------
	/// Constructor to initialize the helper class.
	/// @param[in] getFunc						Get pixel function callback.
	/// @param[in] freeFunc						Free pixel handler callback.
	/// @param[in] destinationProfile	TODO: (Tilo) please document
	//----------------------------------------------------------------------------------------
	template <typename GETFUNC, typename FREEFUNC>
	GetPixelHandlerStruct(GETFUNC&& getFunc, FREEFUNC&& freeFunc, const ColorProfile& destinationProfile) :
		_getFunc(std::forward<GetFunc>(getFunc)),
		_freeFunc(std::forward<FreeFunc>(freeFunc)),
		_targetColorProfile(destinationProfile)
	{
	}

	//----------------------------------------------------------------------------------------
	/// Destructor.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE ~GetPixelHandlerStruct()
	{
		if (_freeFunc)
			_freeFunc(*this);
	}

	MAXON_OPERATOR_MOVE_ASSIGNMENT(GetPixelHandlerStruct);

	//----------------------------------------------------------------------------------------
	/// Returns true if the structure is initialized correctly and a GetPixelHandler is set.
	//----------------------------------------------------------------------------------------
	Bool IsValid() const
	{
		return _getFunc.IsPopulated();
	}

	//----------------------------------------------------------------------------------------
	/// Copies/Read the pixel data from the source to the given buffer.
	/// @param[in] pos								ImagePos of the pixel data to read from.
	/// @param[in] buffer							Destination of the pixel data.
	/// @param[in] flags							Control the operation with the flags.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE Result<void> GetPixel(const ImagePos& pos, const PixelMutableBuffer& buffer, GETPIXELFLAGS flags) const
	{
		return _getFunc(pos, buffer, flags);
	}

	//----------------------------------------------------------------------------------------
	/// Returns the color profile for the pixel data delivered by this handler.
	/// This function is important the pixelhandler was requested without the GETPIXELHANDLERFLAGS::FORCECOLORPROFILECONVERSION flag!
	/// In that case the pixel handler will not process color profile conversions if the color space matches between the internal and
	/// requested pixel format. This speeds up the conversion and allows to pass the profile to the gpu or to the exporter. (e.g. a bitmap
	/// with a sRGB color profile will return the original data if the pixel handler requests a linear rgb profile).
	/// @return												The color profile in which the pixel data will be delivered.
	///																If GETPIXELHANDLERFLAGS::FORCECOLORPROFILECONVERSION was set on request of the pixel handler the color profile is
	///																the same as the requested profile.
	///																If GETPIXELHANDLERFLAGS::FORCECOLORPROFILECONVERSION was NOT set on request of the pixel handler the color
	///																profile might be different if the color space matched.
	//----------------------------------------------------------------------------------------
	const ColorProfile& GetTargetColorProfile()
	{
		return _targetColorProfile;
	}

private:
	GetFunc				_getFunc;
	FreeFunc			_freeFunc;
	ColorProfile	_targetColorProfile;
};



//----------------------------------------------------------------------------------------
/// Helper class returned by SetPixelHandler. This class provides/caches a fast the access to pixels.
/// A lambda contains the most efficient code to access the pixel data.
/// This object is only valid as long as the bitmap properties (pixel format, pixel storage layout, width, height) wont change.
/// The SetPixelHandlerStruct must be accessed only from once thread. If you want to sett pixel in a multi threaded way you need to get a
/// SetPixelHandlerStruct for each thread.
//----------------------------------------------------------------------------------------
struct SetPixelHandlerStruct
{
	MAXON_DISALLOW_COPY_AND_ASSIGN(SetPixelHandlerStruct);

public:
	using SetFunc = Delegate<Result<void>(const ImagePos &pos, const PixelConstBuffer &buffer, SETPIXELFLAGS flags)>;
	using FreeFunc = Delegate<void(SetPixelHandlerStruct& selfPtr)>;

	//----------------------------------------------------------------------------------------
	/// Default Constructor. Initializes everything with nullptr.
	//----------------------------------------------------------------------------------------
	SetPixelHandlerStruct()
	{
	}

	//----------------------------------------------------------------------------------------
	/// Move Constructor.
	//----------------------------------------------------------------------------------------
	SetPixelHandlerStruct(SetPixelHandlerStruct&& other) : _setFunc(std::move(other._setFunc)), _freeFunc(std::move(other._freeFunc))
	{
	}

	//----------------------------------------------------------------------------------------
	/// Returns true if the structure is initialized correctly and a SetPixelHandler is set.
	//----------------------------------------------------------------------------------------
	Bool IsValid() const
	{
		return _setFunc.IsPopulated();
	}

	//----------------------------------------------------------------------------------------
	/// Constructor to initialize the helper class.
	/// @param[in] setFunc						Set pixel function callback.
	/// @param[in] freeFunc						Free pixel handler callback.
	//----------------------------------------------------------------------------------------
	template <typename SETFUNC, typename FREEFUNC>
	SetPixelHandlerStruct(SETFUNC&& setFunc, FREEFUNC&& freeFunc) : _setFunc(std::forward<SetFunc>(setFunc)), _freeFunc(std::forward<FreeFunc>(freeFunc))
	{
	}

	//----------------------------------------------------------------------------------------
	/// Destructor.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE ~SetPixelHandlerStruct()
	{
		if (_freeFunc)
			_freeFunc(*this);
	}

	MAXON_OPERATOR_MOVE_ASSIGNMENT(SetPixelHandlerStruct);

	//----------------------------------------------------------------------------------------
	/// Copies/Writes the pixel data from the buffer to the bitmap.
	/// @param[in] pos								ImagePos of the pixel data to write into the bitmap.
	/// @param[in] buffer							Destination of the pixel data.
	/// @param[in] flags							Control the operation with the flags.
	/// @return												True if the operation operates successful.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE Result<void> SetPixel(const ImagePos& pos, const PixelConstBuffer& buffer, SETPIXELFLAGS flags) const
	{
		_region.Add(Range<IntVector2d>(IntVector2d(pos.xPos, pos.yPos), IntVector2d(pos.xPos + pos.count - 1, pos.yPos)));

		return _setFunc(pos, buffer, flags);
	}

	//----------------------------------------------------------------------------------------
	/// Returns the modified region that was touched by all the SetPixel() calls of this handler.
	//----------------------------------------------------------------------------------------
	const Range<IntVector2d>& GetModifiedRegion() const
	{
		return _region;
	}

private:
	SetFunc _setFunc;
	FreeFunc _freeFunc;
	mutable Range<IntVector2d> _region;
};

}


#endif // GFX_IMAGE_PIXELHANDLER_H__
