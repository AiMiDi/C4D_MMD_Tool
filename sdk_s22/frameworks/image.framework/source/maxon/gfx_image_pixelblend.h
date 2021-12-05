#ifndef GFX_IMAGE_PIXELBLEND_H__
#define GFX_IMAGE_PIXELBLEND_H__

#include "maxon/gfx_image_pixelformat.h"

namespace maxon
{

/// @addtogroup Graphics
/// @{

//----------------------------------------------------------------------------------------
/// Flags to control the BlendPixel functions.
//----------------------------------------------------------------------------------------
enum class BLENDPIXELFLAGS
{
	NONE,									///< no options set.
} MAXON_ENUM_FLAGS(BLENDPIXELFLAGS);

//----------------------------------------------------------------------------------------
/// Helper class returned by GetBlendPixelHandler. This class provides/caches a fast the access to blend pixels.
/// A lambda contains the most efficient code to access the pixel data.
/// This object is only valid as long as the bitmap properties (pixel format, pixel storage layout, width, height) wont change.
//----------------------------------------------------------------------------------------
struct BlendPixelHandlerStruct
{
	MAXON_DISALLOW_COPY_AND_ASSIGN(BlendPixelHandlerStruct);

public:
	using BlendFunc = Delegate<Result<void>(const PixelMutableBuffer& result, const PixelConstBuffer& background,
		const PixelConstBuffer& foreground, Int pixelCnt, BLENDPIXELFLAGS flags)>;
	using FreeFunc = Delegate<void(BlendPixelHandlerStruct& selfPtr)>;

	//----------------------------------------------------------------------------------------
	/// Default Constructor. Initializes everything with nullptr.
	//----------------------------------------------------------------------------------------
	BlendPixelHandlerStruct()
	{
	}

	//----------------------------------------------------------------------------------------
	/// Move Constructor.
	//----------------------------------------------------------------------------------------
	BlendPixelHandlerStruct(BlendPixelHandlerStruct&& other) :
		_blendFunc(std::move(other._blendFunc)),
		_freeFunc(std::move(other._freeFunc))
	{
	}

	//----------------------------------------------------------------------------------------
	/// Constructor to initialize the helper class.
	/// @param[in] blendFunc					Blend pixel function callback.
	/// @param[in] freeFunc						Free pixel handler callback.
	//----------------------------------------------------------------------------------------
	template <typename BLENDFUNC, typename FREEFUNC>
	BlendPixelHandlerStruct(BLENDFUNC&& blendFunc, FREEFUNC&& freeFunc) :
		_blendFunc(std::forward<BlendFunc>(blendFunc)),
		_freeFunc(std::forward<FreeFunc>(freeFunc))
	{
	}

	//----------------------------------------------------------------------------------------
	/// Destructor.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE ~BlendPixelHandlerStruct()
	{
		if (_freeFunc)
			_freeFunc(*this);
	}

	MAXON_OPERATOR_MOVE_ASSIGNMENT(BlendPixelHandlerStruct);

	//----------------------------------------------------------------------------------------
	/// Returns true if the structure is initialized correctly and a GetBlendPixelHandler is set.
	//----------------------------------------------------------------------------------------
	Bool IsValid() const
	{
		return _blendFunc.IsPopulated();
	}

	//----------------------------------------------------------------------------------------
	/// Blends the pixel data between background and foreground. The result will end up in background.
	/// @param[in] background					Background image data to process.
	/// @param[in] foreground					Foreground image data to process.
	/// @param[in] pixelCnt						Number of pixels to precess.
	/// @param[in] flags							(optional) flags for later extend.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE Result<void> BlendPixel(const PixelMutableBuffer& result, const PixelConstBuffer& background,
		const PixelConstBuffer& foreground, Int pixelCnt, BLENDPIXELFLAGS flags) const
	{
		return _blendFunc(result, background, foreground, pixelCnt, flags);
	}

private:
	BlendFunc _blendFunc;
	FreeFunc	_freeFunc;
};

using BlendPixelHandlerRef = StrongRef<BlendPixelHandlerStruct>;

MAXON_DATATYPE(BlendPixelHandlerRef, "net.maxon.datatype.blendpixelhandlerref");

//----------------------------------------------------------------------------------------
/// This class allows to implement and use pixel blending methods.
/// Each pixel blending should has it's own implementation.
/// A enumeration of all available blending methods can be found under ImagePixelBlends registry.
//----------------------------------------------------------------------------------------
class ImagePixelBlendInterface : MAXON_INTERFACE_BASES(ObjectInterface)
{
	MAXON_INTERFACE(ImagePixelBlendInterface, MAXON_REFERENCE_CONST, "net.maxon.image.interface.imagepixelblend");

public:
	//----------------------------------------------------------------------------------------
	/// GetOptimalPixelFormat returns the optimal blending PixelFormat.
	/// @param[in] formats						Input formats to respect. Depending on that formats the result might change.
	/// @return												Optimal blending pixel format to deliver to GetBlendPixel() function.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<PixelFormat> GetOptimalPixelFormat(const Block<PixelFormat>& formats);

	//----------------------------------------------------------------------------------------
	/// GetBlendPixelHandler create a handler object to be used when conversion pixel data.
	/// @param[in] bgFormat						PixelFormat for the background layer.
	/// @param[in] bgChannelOffsets		Channel offsets for the background layer.
	/// @param[in] fgFormat						PixelFormat for the foreground layer.
	/// @param[in] fgChannelOffsets		Channel offsets for the foreground layer.
	/// @param[in] opacity						Blend opacity to use.
	/// @return												BlendPixelHandlerStruct on success. On that object BlendPixel() can be called to use the optimized
	///																blending function for a line of pixels.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<BlendPixelHandlerStruct> GetBlendPixelHandler(const PixelFormat& bgFormat, const ChannelOffsets& bgChannelOffsets,
		const PixelFormat& fgFormat, const ChannelOffsets& fgChannelOffsets, Float opacity) const;
};



// include autogenerated headerfile here
#include "gfx_image_pixelblend1.hxx"

MAXON_REGISTRY(ImagePixelBlend, ImagePixelBlends, "net.maxon.render.registry.blendmodeclasses");

namespace ImagePixelBlends
{
	MAXON_DECLARATION(ImagePixelBlend, Add, "net.maxon.render.blendmode.add");
	MAXON_DECLARATION(ImagePixelBlend, Average, "net.maxon.render.blendmode.average");
	MAXON_DECLARATION(ImagePixelBlend, Color, "net.maxon.render.blendmode.color");
	MAXON_DECLARATION(ImagePixelBlend, Colorburn, "net.maxon.render.blendmode.colorburn");
	MAXON_DECLARATION(ImagePixelBlend, Colordodge, "net.maxon.render.blendmode.colordodge");
	MAXON_DECLARATION(ImagePixelBlend, Darken, "net.maxon.render.blendmode.darken");
	MAXON_DECLARATION(ImagePixelBlend, Darker, "net.maxon.render.blendmode.darker");
	MAXON_DECLARATION(ImagePixelBlend, Difference, "net.maxon.render.blendmode.difference");
	MAXON_DECLARATION(ImagePixelBlend, Dissolve, "net.maxon.render.blendmode.dissolve");
	MAXON_DECLARATION(ImagePixelBlend, Divide, "net.maxon.render.blendmode.divide");
	MAXON_DECLARATION(ImagePixelBlend, Exclusion, "net.maxon.render.blendmode.exclusion");
	MAXON_DECLARATION(ImagePixelBlend, Freeze, "net.maxon.render.blendmode.freeze");
	MAXON_DECLARATION(ImagePixelBlend, Glow, "net.maxon.render.blendmode.glow");
	MAXON_DECLARATION(ImagePixelBlend, Hardlight, "net.maxon.render.blendmode.hardlight");
	MAXON_DECLARATION(ImagePixelBlend, Hardmix, "net.maxon.render.blendmode.hardmix");
	MAXON_DECLARATION(ImagePixelBlend, Heat, "net.maxon.render.blendmode.heat");
	MAXON_DECLARATION(ImagePixelBlend, Hue, "net.maxon.render.blendmode.hue");
	MAXON_DECLARATION(ImagePixelBlend, Hypot, "net.maxon.render.blendmode.hypot");
	MAXON_DECLARATION(ImagePixelBlend, Levr, "net.maxon.render.blendmode.levr");
	MAXON_DECLARATION(ImagePixelBlend, Lighten, "net.maxon.render.blendmode.lighten");
	MAXON_DECLARATION(ImagePixelBlend, Lighter, "net.maxon.render.blendmode.lighter");
	MAXON_DECLARATION(ImagePixelBlend, Linearburn, "net.maxon.render.blendmode.linearburn");
	MAXON_DECLARATION(ImagePixelBlend, Lineardodge, "net.maxon.render.blendmode.lineardodge");
	MAXON_DECLARATION(ImagePixelBlend, Luminance, "net.maxon.render.blendmode.luminance");
	MAXON_DECLARATION(ImagePixelBlend, Multiply, "net.maxon.render.blendmode.multiply");
	MAXON_DECLARATION(ImagePixelBlend, Over, "net.maxon.render.blendmode.over");
	MAXON_DECLARATION(ImagePixelBlend, Overlay, "net.maxon.render.blendmode.overlay");
	MAXON_DECLARATION(ImagePixelBlend, Passfolder, "net.maxon.render.blendmode.passfolder");
	MAXON_DECLARATION(ImagePixelBlend, Pinlight, "net.maxon.render.blendmode.pinlight");
	MAXON_DECLARATION(ImagePixelBlend, Reflect, "net.maxon.render.blendmode.reflect");
	MAXON_DECLARATION(ImagePixelBlend, Saturation, "net.maxon.render.blendmode.saturation");
	MAXON_DECLARATION(ImagePixelBlend, Screen, "net.maxon.render.blendmode.screen");
	MAXON_DECLARATION(ImagePixelBlend, Softlight, "net.maxon.render.blendmode.softlight");
	MAXON_DECLARATION(ImagePixelBlend, Stamp, "net.maxon.render.blendmode.stamp");
	MAXON_DECLARATION(ImagePixelBlend, Subtract, "net.maxon.render.blendmode.subtract");
	MAXON_DECLARATION(ImagePixelBlend, Vividlight, "net.maxon.render.blendmode.vividlight");
	MAXON_DECLARATION(ImagePixelBlend, Xor, "net.maxon.render.blendmode.xor");
}

namespace ImagePixelBlendsInternal
{
	MAXON_DECLARATION(ImagePixelBlend, ApplyAlpha, "net.maxon.render.blendmode.applyalpha");
}

// include autogenerated headerfile here
#include "gfx_image_pixelblend2.hxx"

/// @}

} // namespace maxon


#endif // GFX_IMAGE_PIXELBLEND_H__
