#ifndef VECTOR4D_H__
#define VECTOR4D_H__

#include "maxon/matrix.h"

#define MAXON_VECTORMODE

// Include generic versions with arbitrary stride
#include "math/vec4.h"
#include "math/col4.h"

// Include specialized version with no stride
#define STRIDE 1
#include "math/vec4.h"
#include "math/col4.h"
#undef STRIDE

#undef MAXON_VECTORMODE

namespace maxon
{

/// @addtogroup MATH
/// @{

/// Single-Precision Vector.
/// A vector contains three components X, Y, Z and W
using Vector4d32 = Vec4<Float32, 1>;

/// Double-Precision Vector.
/// A vector contains three components X, Y, Z and W
using Vector4d64 = Vec4<Float64, 1>;

/// Vector with the precision of Float.
/// A vector contains four components X, Y, Z and W
using Vector4d = Vec4<Float, 1>;

/// 32-bit Int Vector.
/// A vector contains four components X, Y, Z and W
using IntVector4d32 = Vec4<Int32, 1>;

/// 64-bit Int Vector.
/// A vector contains four components X, Y, Z and W
using IntVector4d64 = Vec4<Int64, 1>;

/// Vector of Int.
/// A vector contains four components X, Y, Z and W
using IntVector4d = Vec4<Int, 1>;

/// Single-Precision Color with Alpha.
/// A color contains three components R, G, B and A
using ColorA32 = Col4<Float32, 1>;

/// Double-Precision Color with Alpha.
/// A color contains three components R, G, B and A
using ColorA64 = Col4<Float64, 1>;

/// Color with Alpha with the precision of Float.
/// A color contains four components R, G, B and A
using ColorA = Col4<Float, 1>;

/// Generic arithmetic vector type.
using GenericVector4d = Vec4<GenericArithmetic, 1>;


//----------------------------------------------------------------------------------------
/// predefined colors
//----------------------------------------------------------------------------------------
namespace ColorTable
{
	// Light colors
	inline ColorA White				(Float alpha = 1.0) { return ColorA(1.0,	1.0, 	1.0,	alpha); }
	inline ColorA LightGray		(Float alpha = 1.0) { return ColorA(0.75,	0.75,	0.75,	alpha); }
	inline ColorA LightRed		(Float alpha = 1.0) { return ColorA(1.0, 	0.6,	0.6,	alpha); }
	inline ColorA LightOrange	(Float alpha = 1.0) { return ColorA(1.0,	0.75,	0.5,	alpha); }
	inline ColorA LightYellow	(Float alpha = 1.0) { return ColorA(1.0,	1.0,	0.6,	alpha); }
	inline ColorA LightGreen	(Float alpha = 1.0) { return ColorA(0.6,	1.0,	0.6,	alpha); }
	inline ColorA LightBlue		(Float alpha = 1.0) { return ColorA(0.6,	1.0,	1.0,	alpha); }
	inline ColorA LightPurple	(Float alpha = 1.0) { return ColorA(0.75,	0.6,	1.0,	alpha); }
	inline ColorA LightMagenta(Float alpha = 1.0) { return ColorA(1.0,	0.6,	1.0,	alpha); }
	
	// Medium/pure colors
	inline ColorA Gray				(Float alpha = 1.0) { return ColorA(0.5,	0.5,	0.5,	alpha); }
	inline ColorA Red					(Float alpha = 1.0) { return ColorA(1.0, 	0.0,	0.0,	alpha); }
	inline ColorA Orange			(Float alpha = 1.0) { return ColorA(1.0,	0.6,	0.0,	alpha); }
	inline ColorA Yellow			(Float alpha = 1.0) { return ColorA(1.0,	1.0,	0.0,	alpha); }
	inline ColorA Green				(Float alpha = 1.0) { return ColorA(0.0,	1.0,	0.0,	alpha); }
	inline ColorA Blue				(Float alpha = 1.0) { return ColorA(0.0,	0.0,	1.0,	alpha); }
	inline ColorA BlueMedium	(Float alpha = 1.0) { return ColorA(0.0,	0.5,	1.0,	alpha); }
	inline ColorA Cyan				(Float alpha = 1.0) { return ColorA(0.0,	1.0,	1.0,	alpha); }
	inline ColorA Purple			(Float alpha = 1.0) { return ColorA(0.5,	0.0,	1.0,	alpha); }
	inline ColorA Magenta			(Float alpha = 1.0) { return ColorA(1.0,	0.0,	1.0,	alpha); }
	
	// Dark colors
	inline ColorA Black				(Float alpha = 1.0) { return ColorA(0.0,	0.0, 	0.0,	alpha); }
	inline ColorA DarkGray		(Float alpha = 1.0) { return ColorA(0.25,	0.25,	0.25,	alpha); }
	inline ColorA DarkRed			(Float alpha = 1.0) { return ColorA(0.5, 	0.0,	0.0,	alpha); }
	inline ColorA DarkOrange	(Float alpha = 1.0) { return ColorA(0.4,	0.2,	0.0,	alpha); }
	inline ColorA DarkYellow	(Float alpha = 1.0) { return ColorA(0.5,	0.5,	0.0,	alpha); }
	inline ColorA DarkGreen		(Float alpha = 1.0) { return ColorA(0.0,	0.4,	0.0,	alpha); }
	inline ColorA DarkBlue		(Float alpha = 1.0) { return ColorA(0.0,	0.0,	0.5,	alpha); }
	inline ColorA DarkPurple	(Float alpha = 1.0) { return ColorA(0.25,	0.0,	0.5,	alpha); }
	inline ColorA DarkMagenta	(Float alpha = 1.0) { return ColorA(0.5,	0.0,	0.5,	alpha); }

	// Special colors
	inline ColorA Transparent() { return ColorA(0.0, 0.0, 0.0, 0.0); }
}

//----------------------------------------------------------------------------------------
/// Converts RGBA UInt [0, 255] values to a ColorA.
/// @param[in] r          Red value.
/// @param[in] g          Green value
/// @param[in] b          Blue value.
/// @param[in] a          Alpha value.
/// @return               Converted ColorA.
//----------------------------------------------------------------------------------------
MAXON_ATTRIBUTE_FORCE_INLINE ColorA IntToColor(UInt r, UInt g, UInt b, UInt a)
{
	return ColorA(Float(r), Float(g), Float(b), Float(a)) / 255.0;
}

//----------------------------------------------------------------------------------------
/// Converts RGB UInt [0, 255] values to a ColorA.
/// @param[in] r          Red value.
/// @param[in] g          Green value
/// @param[in] b          Blue value.
/// @return               Converted ColorA.
//----------------------------------------------------------------------------------------
MAXON_ATTRIBUTE_FORCE_INLINE ColorA IntToColor(UInt r, UInt g, UInt b)
{
	return ColorA(Float(r), Float(g), Float(b), 255.0) / 255.0;
}

//----------------------------------------------------------------------------------------
/// Converts RGBA Float [0.0, 1.0] values to a ColorA.
/// @param[in] r          Red value.
/// @param[in] g          Green value
/// @param[in] b          Blue value.
/// @param[in] a          Alpha value.
/// @return               Converted ColorA.
//----------------------------------------------------------------------------------------
MAXON_ATTRIBUTE_FORCE_INLINE ColorA FloatToColor(Float r, Float g, Float b, Float a)
{
	return ColorA(Float(r), Float(g), Float(b), Float(a));
}

//----------------------------------------------------------------------------------------
/// Converts RGB Float [0.0, 1.0] values to a ColorA.
/// @param[in] r          Red value.
/// @param[in] g          Green value
/// @param[in] b          Blue value.
/// @return               Converted ColorA.
//----------------------------------------------------------------------------------------
MAXON_ATTRIBUTE_FORCE_INLINE ColorA FloatToColor(Float r, Float g, Float b)
{
	return ColorA(Float(r), Float(g), Float(b), 1.0);
}

//----------------------------------------------------------------------------------------
/// Sets the alpha value of a ColorA.
/// @param[in] col        Given ColorA.
/// @param[in] alpha      Alpha value.
/// @return               Converted ColorA.
//----------------------------------------------------------------------------------------
MAXON_ATTRIBUTE_FORCE_INLINE ColorA ColorSetAlpha(const ColorA& col, Float alpha)
{
	return ColorA(col.r, col.g, col.b, alpha);
}

//----------------------------------------------------------------------------------------
/// Multiplies a ColorA with an alpha value.
/// @param[in] col        Given ColorA.
/// @param[in] alpha      Multiply alpha value.
/// @return               Converted ColorA.
//----------------------------------------------------------------------------------------
MAXON_ATTRIBUTE_FORCE_INLINE ColorA ColorMultiplyAlpha(const ColorA& col, Float alpha)
{
	return ColorA(col.r, col.g, col.b, col.a * alpha);
}

//----------------------------------------------------------------------------------------
/// Blends two colors based on an alpha factor.
/// @param[in] col1				First color.
/// @param[in] col2				Second color.
/// @param[in] alpha			Alpha blending factor. Valid range goes from 0.0 (Col1) to 1.0 (Col2).
/// @return								Blended color.
//----------------------------------------------------------------------------------------
MAXON_ATTRIBUTE_FORCE_INLINE Color BlendColors(const Color& col1, const Color& col2, Float alpha)
{
	return (1.0 - alpha) * col1 + alpha * col2;
}

//----------------------------------------------------------------------------------------
/// Blends two colors based on an alpha factor. Note: only RGB values are used, color alpha values are ignored.
/// @param[in] col1				First color. Alpha is ignored.
/// @param[in] col2				Second color. Alpha is ignored.
/// @param[in] alpha			Alpha blending factor. Valid range goes from 0.0 (Col1) to 1.0 (Col2).
/// @return								Blended color with an alpha value of 1.0.
//----------------------------------------------------------------------------------------
MAXON_ATTRIBUTE_FORCE_INLINE ColorA BlendColors(const ColorA& col1, const ColorA& col2, Float alpha)
{
	return ColorA(BlendColors(col1.GetColor3(), col2.GetColor3(), alpha), 1.0);
}

//----------------------------------------------------------------------------------------
/// Blend linear between two CanvasColors.
/// @param[in] col1       First ColorA.
/// @param[in] col2       Second ColorA.
/// @param[in] blendValue Blend value [0.0, 1.0].
/// @return               Blended ColorA value
//----------------------------------------------------------------------------------------
template <typename COLORTYPE> MAXON_ATTRIBUTE_FORCE_INLINE COLORTYPE BlendColor(const COLORTYPE& col1, const COLORTYPE& col2, const typename COLORTYPE::ValueType blendValue)
{
	typename COLORTYPE::ValueType blendValue1 = typename COLORTYPE::ValueType(1.0) - blendValue;
	return COLORTYPE(col2.r * blendValue + col1.r * blendValue1, col2.g * blendValue + col1.g * blendValue1, col2.b * blendValue + col1.b * blendValue1, col2.a * blendValue + col1.a * blendValue1);
}

static const Float PERCEIVED_BRIGHTNESS_FACTOR_RED   = 0.299;
static const Float PERCEIVED_BRIGHTNESS_FACTOR_GREEN = 0.587;
static const Float PERCEIVED_BRIGHTNESS_FACTOR_BLUE  = 0.114;
static const Float PERCEIVED_BRIGHTNESS_CUTOFF       = 0.5098; // Cutoff value for determining if a color is perceived as dark/bright by human eye in the Float color system (0.0 - 1.0). Is equal to 130/255 (130 is the cutoff value in the int color system (0 - 255)).

//----------------------------------------------------------------------------------------
/// Gets the perceived brightness from the color.
/// Source: http://stackoverflow.com/a/596243/1577282
/// @param[in] color              The color whose perceived brightness will be calculated.
/// @return                        The perceived brightness value.
//----------------------------------------------------------------------------------------
MAXON_ATTRIBUTE_FORCE_INLINE Float GetPerceivedBrightness(const ColorA& color)
{
  return color.r * PERCEIVED_BRIGHTNESS_FACTOR_RED + color.g * PERCEIVED_BRIGHTNESS_FACTOR_GREEN + color.b * PERCEIVED_BRIGHTNESS_FACTOR_BLUE;
}

//----------------------------------------------------------------------------------------
/// Checks if a color is perceived as dark by the human eye.
/// Source: http://www.nbdtech.com/Blog/archive/2008/04/27/Calculating-the-Perceived-Brightness-of-a-Color.aspx
/// Source: https://robots.thoughtbot.com/closer-look-color-lightness
/// @param[in] color              The color whose darkness will be evaluated.
/// @return                        True: the color is perceived as dark, False: the color is perceived as light.
//----------------------------------------------------------------------------------------
MAXON_ATTRIBUTE_FORCE_INLINE Bool IsColorPerceivedAsDark(const ColorA& color)
{
  return GetPerceivedBrightness(color) < PERCEIVED_BRIGHTNESS_CUTOFF;
}

/// @}

#ifndef MAXON_COMPILER_GCC
static_assert(STD_IS_REPLACEMENT(trivially_copyable, Vector4d), "Vector not trivially copyable.");
#endif

} // namespace maxon

#endif // VECTOR4D_H__
