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
/// Blend linear between two CanvasColors.
/// @param[in] col1       First ColorA.
/// @param[in] col2       Second ColorA.
/// @param[in] blendValue Blend value [0.0, 1.0].
/// @return               Blended ColorA value
//----------------------------------------------------------------------------------------
MAXON_ATTRIBUTE_FORCE_INLINE ColorA BlendColor(const ColorA& col1, const ColorA& col2, const Float blendValue)
{
  Float blendValue1 = Float(1.0) - blendValue;
  return ColorA(col2.r * blendValue + col1.r *blendValue1, col2.g * blendValue + col1.g *blendValue1, col2.b * blendValue + col1.b *blendValue1, col2.a * blendValue + col1.a *blendValue1);
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
static_assert(std::is_trivially_copyable<Vector4d>::value, "Vector not trivially copyable.");
#endif

} // namespace maxon

#endif // VECTOR4D_H__
