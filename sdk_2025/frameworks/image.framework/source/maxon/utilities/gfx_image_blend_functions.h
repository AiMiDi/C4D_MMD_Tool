#ifndef GFX_IMAGE_BLEND_FUNCTIONS_H__
#define GFX_IMAGE_BLEND_FUNCTIONS_H__

#include "maxon/utilities/gfx_image_functions_color_conversions.h"



namespace maxon
{

//----------------------------------------------------------------------------------------------------
/// Implementations of commonly used blend modes which can be applied per-component
//----------------------------------------------------------------------------------------------------

//----------------------------------------------------------------------------------------------------
/// Blend Modes
/// Blend results are not necessarily meant to match the result in Photoshop (or any other application). 
/// Photoshop in particular has some rather "creative" alpha handling which is not attempted to be
/// reproduced here. Moreover, Photoshop doesn't support half of their blend modes in 32-bit mode, so 
/// it's impossible to compare results in any meaningful way.
///
/// These implementations are mostly based on those from Bodypaint as well as the Fusion shader.
//----------------------------------------------------------------------------------------------------

//----------------------------------------------------------------------------------------------------
/// Over (Normal)
//----------------------------------------------------------------------------------------------------
template <typename FLOATTYPE> MAXON_ATTRIBUTE_FORCE_INLINE FLOATTYPE BlendOver(FLOATTYPE background, FLOATTYPE foreground)
{
	return foreground;
}

//----------------------------------------------------------------------------------------------------
/// Average
//----------------------------------------------------------------------------------------------------
template <typename FLOATTYPE> MAXON_ATTRIBUTE_FORCE_INLINE FLOATTYPE BlendAverage(FLOATTYPE background, FLOATTYPE foreground)
{
	return (foreground + background) / FLOATTYPE(2.0);
}

//----------------------------------------------------------------------------------------------------
/// Multiply
//----------------------------------------------------------------------------------------------------
template <typename FLOATTYPE> MAXON_ATTRIBUTE_FORCE_INLINE FLOATTYPE BlendMultiply(FLOATTYPE background, FLOATTYPE foreground)
{
	return foreground * background;
}

//----------------------------------------------------------------------------------------------------
/// Screen
//----------------------------------------------------------------------------------------------------
template <typename FLOATTYPE> MAXON_ATTRIBUTE_FORCE_INLINE FLOATTYPE BlendScreen(FLOATTYPE background, FLOATTYPE foreground)
{
	return foreground + background - foreground * background;
}

//----------------------------------------------------------------------------------------------------
/// Subtract
//----------------------------------------------------------------------------------------------------
template <typename FLOATTYPE> MAXON_ATTRIBUTE_FORCE_INLINE FLOATTYPE BlendSubtract(FLOATTYPE background, FLOATTYPE foreground)
{
	return background - foreground;
}

//----------------------------------------------------------------------------------------------------
/// Divide
//----------------------------------------------------------------------------------------------------
template <typename FLOATTYPE> MAXON_ATTRIBUTE_FORCE_INLINE FLOATTYPE BlendDivide(FLOATTYPE background, FLOATTYPE foreground)
{
	return (foreground <= FLOATTYPE(1e-4)) ? background : background / foreground;
}

//----------------------------------------------------------------------------------------------------
/// Add
//----------------------------------------------------------------------------------------------------
template <typename FLOATTYPE> MAXON_ATTRIBUTE_FORCE_INLINE FLOATTYPE BlendAdd(FLOATTYPE background, FLOATTYPE foreground)
{
	return foreground + background;
}

//----------------------------------------------------------------------------------------------------
/// Overlay
//----------------------------------------------------------------------------------------------------
template <typename FLOATTYPE> MAXON_ATTRIBUTE_FORCE_INLINE FLOATTYPE BlendOverlay(FLOATTYPE background, FLOATTYPE foreground)
{
	if (background < FLOATTYPE(0.5))
		return FLOATTYPE(2.0) * (background * foreground);
	else
		return FLOATTYPE(1.0) - FLOATTYPE(2.0) * (FLOATTYPE(1.0) - background) * (FLOATTYPE(1.0) - foreground);
}

//----------------------------------------------------------------------------------------------------
/// Hard Light
//----------------------------------------------------------------------------------------------------
template <typename FLOATTYPE> MAXON_ATTRIBUTE_FORCE_INLINE FLOATTYPE BlendHardLight(FLOATTYPE background, FLOATTYPE foreground)
{
	if (foreground < FLOATTYPE(0.5))
		return FLOATTYPE(2.0) * (background * foreground);
	else
		return FLOATTYPE(1.0) - FLOATTYPE(2.0) * (FLOATTYPE(1.0) - background) * (FLOATTYPE(1.0) - foreground);
}

//----------------------------------------------------------------------------------------------------
/// Soft Light
//----------------------------------------------------------------------------------------------------
template <typename FLOATTYPE> MAXON_ATTRIBUTE_FORCE_INLINE FLOATTYPE BlendSoftLight(FLOATTYPE background, FLOATTYPE foreground)
{
	FLOATTYPE tmp = FLOATTYPE(2.0) * foreground * background;
	return tmp + foreground * foreground - tmp * foreground;
}

//----------------------------------------------------------------------------------------------------
/// Darken (Min)
//----------------------------------------------------------------------------------------------------
template <typename FLOATTYPE> MAXON_ATTRIBUTE_FORCE_INLINE FLOATTYPE BlendDarken(FLOATTYPE background, FLOATTYPE foreground)
{
	return Min(background, foreground);
}

//----------------------------------------------------------------------------------------------------
/// Lighten (Max)
//----------------------------------------------------------------------------------------------------
template <typename FLOATTYPE> MAXON_ATTRIBUTE_FORCE_INLINE FLOATTYPE BlendLighten(FLOATTYPE background, FLOATTYPE foreground)
{
	return Max(background, foreground);
}

//----------------------------------------------------------------------------------------------------
/// Pin Light
//----------------------------------------------------------------------------------------------------
template <typename FLOATTYPE> MAXON_ATTRIBUTE_FORCE_INLINE FLOATTYPE BlendPinLight(FLOATTYPE background, FLOATTYPE foreground)
{
	return foreground < FLOATTYPE(0.5) ? Min(background, foreground * FLOATTYPE(2.0)) : Max(background, (foreground - FLOATTYPE(0.5)) * FLOATTYPE(2.0));
}

//----------------------------------------------------------------------------------------------------
/// Difference
//----------------------------------------------------------------------------------------------------
template <typename FLOATTYPE> MAXON_ATTRIBUTE_FORCE_INLINE FLOATTYPE BlendDifference(FLOATTYPE background, FLOATTYPE foreground)
{
	return Abs(background - foreground);
}

//----------------------------------------------------------------------------------------------------
/// Exclusion
//----------------------------------------------------------------------------------------------------
template <typename FLOATTYPE> MAXON_ATTRIBUTE_FORCE_INLINE FLOATTYPE BlendExclusion(FLOATTYPE background, FLOATTYPE foreground)
{
	return background + foreground - FLOATTYPE(2.0) * (background * foreground);
}

//----------------------------------------------------------------------------------------------------
/// Negative
//----------------------------------------------------------------------------------------------------
template <typename FLOATTYPE> MAXON_ATTRIBUTE_FORCE_INLINE FLOATTYPE BlendNegative(FLOATTYPE background, FLOATTYPE foreground)
{
	return FLOATTYPE(1.0) - Abs(FLOATTYPE(1.0) - background - foreground);
}

//----------------------------------------------------------------------------------------------------
/// Stamp
//----------------------------------------------------------------------------------------------------
template <typename FLOATTYPE> MAXON_ATTRIBUTE_FORCE_INLINE FLOATTYPE BlendStamp(FLOATTYPE background, FLOATTYPE foreground)
{
	return Clamp01(background + FLOATTYPE(2.0) * foreground - FLOATTYPE(1.0));
}

//----------------------------------------------------------------------------------------------------
/// Xor
//----------------------------------------------------------------------------------------------------
template <typename FLOATTYPE> MAXON_ATTRIBUTE_FORCE_INLINE FLOATTYPE BlendXor(FLOATTYPE background, FLOATTYPE foreground)
{
	return (FLOATTYPE)(((Int32)(background * 255)) ^ ((Int32)(foreground * 255))) / FLOATTYPE(255.0);
}

//----------------------------------------------------------------------------------------------------
/// Glow
//----------------------------------------------------------------------------------------------------
template <typename FLOATTYPE> MAXON_ATTRIBUTE_FORCE_INLINE FLOATTYPE BlendGlow(FLOATTYPE background, FLOATTYPE foreground)
{
	const FLOATTYPE tmp = FLOATTYPE(1.0) - background;
	if (tmp <= FLOATTYPE(1e-4))
		return FLOATTYPE(1.0);
	else
		return Min(foreground * foreground / tmp, FLOATTYPE(1.0));
}

//----------------------------------------------------------------------------------------------------
/// Reflect
//----------------------------------------------------------------------------------------------------
template <typename FLOATTYPE> MAXON_ATTRIBUTE_FORCE_INLINE FLOATTYPE BlendReflect(FLOATTYPE background, FLOATTYPE foreground)
{
	const FLOATTYPE tmp = FLOATTYPE(1.0) - foreground;
	if (tmp <= FLOATTYPE(1e-4))
		return FLOATTYPE(1.0);
	else
		return Min(background * background / tmp, FLOATTYPE(1.0));
}

//----------------------------------------------------------------------------------------------------
/// Heat
//----------------------------------------------------------------------------------------------------
template <typename FLOATTYPE> MAXON_ATTRIBUTE_FORCE_INLINE FLOATTYPE BlendHeat(FLOATTYPE background, FLOATTYPE foreground)
{
	const FLOATTYPE tmp = FLOATTYPE(1.0) - foreground;
	if (background < FLOATTYPE(1e-4))
		return FLOATTYPE(0.0);
	else
		return Max(FLOATTYPE(1.0) - tmp * tmp / background, FLOATTYPE(0.0));
}


//----------------------------------------------------------------------------------------------------
/// Freeze
//----------------------------------------------------------------------------------------------------
template <typename FLOATTYPE> MAXON_ATTRIBUTE_FORCE_INLINE FLOATTYPE BlendFreeze(FLOATTYPE background, FLOATTYPE foreground)
{
	const FLOATTYPE tmp = FLOATTYPE(1.0) - background;
	if (foreground < FLOATTYPE(1e-4))
		return FLOATTYPE(0.0);
	else
		return Max(FLOATTYPE(1.0) - tmp * tmp / foreground, FLOATTYPE(0.0));
}

//----------------------------------------------------------------------------------------------------
/// Hypot (similar effect to screen but a bit weaker)
//----------------------------------------------------------------------------------------------------
template <typename FLOATTYPE> MAXON_ATTRIBUTE_FORCE_INLINE FLOATTYPE BlendHypot(FLOATTYPE background, FLOATTYPE foreground)
{
	return Sqrt(background * background + foreground * foreground);
}

//----------------------------------------------------------------------------------------------------
/// Dissolve
//----------------------------------------------------------------------------------------------------
template <typename FLOATTYPE> MAXON_ATTRIBUTE_FORCE_INLINE FLOATTYPE Dissolve(FLOATTYPE background, FLOATTYPE foreground)
{
	DebugStop(); // not implemented yet, this needs 
	return BlendOver(background, foreground);
}

//----------------------------------------------------------------------------------------------------
/// Hard Mix
//----------------------------------------------------------------------------------------------------
template <typename FLOATTYPE> MAXON_ATTRIBUTE_FORCE_INLINE FLOATTYPE BlendHardMix(FLOATTYPE background, FLOATTYPE foreground)
{
	FLOATTYPE result;
	if (background + foreground > FLOATTYPE(1.0))
	{
		if (foreground == FLOATTYPE(1.0))
		{
			result = FLOATTYPE(1.0);
		}
		else
		{
			result = background / (FLOATTYPE(1.0) - foreground);
			if (result > FLOATTYPE(1.0))
				result = FLOATTYPE(1.0);
		}
	}
	else
	{
		if (background == FLOATTYPE(1.0))
		{
			result = FLOATTYPE(1.0);
		}
		else if (background == FLOATTYPE(0.0))
		{
			result = FLOATTYPE(0.0);
		}
		else
		{
			result = FLOATTYPE(1.0) - (FLOATTYPE(1.0) - foreground) / background;
			if (result < FLOATTYPE(0.0))
				result = FLOATTYPE(0.0);
		}
	}
	return result;
}

//----------------------------------------------------------------------------------------------------
/// Color Dodge
//----------------------------------------------------------------------------------------------------
template <typename FLOATTYPE> MAXON_ATTRIBUTE_FORCE_INLINE FLOATTYPE BlendColorDodge(FLOATTYPE background, FLOATTYPE foreground)
{
	return (foreground == FLOATTYPE(1.0)) ? foreground : Min(background / (FLOATTYPE(1.0) - foreground), FLOATTYPE(1.0));
}

//----------------------------------------------------------------------------------------------------
/// Color Burn
//----------------------------------------------------------------------------------------------------
template <typename FLOATTYPE> MAXON_ATTRIBUTE_FORCE_INLINE FLOATTYPE BlendColorBurn(FLOATTYPE background, FLOATTYPE foreground)
{
	return (foreground == FLOATTYPE(0.0)) ? foreground : Max((FLOATTYPE(1.0) - ((FLOATTYPE(1.0) - background) / foreground)), FLOATTYPE(0.0));
}

//----------------------------------------------------------------------------------------------------
/// Linear Dodge
//----------------------------------------------------------------------------------------------------
template <typename FLOATTYPE> MAXON_ATTRIBUTE_FORCE_INLINE FLOATTYPE BlendLinearDodge(FLOATTYPE background, FLOATTYPE foreground)
{
	return Min(background + foreground, FLOATTYPE(1.0));
}

//----------------------------------------------------------------------------------------------------
/// Linear Burn
//----------------------------------------------------------------------------------------------------
template <typename FLOATTYPE> MAXON_ATTRIBUTE_FORCE_INLINE FLOATTYPE BlendLinearBurn(FLOATTYPE background, FLOATTYPE foreground)
{
	return Max(FLOATTYPE(0.0), background + foreground - FLOATTYPE(1.0));
}

//----------------------------------------------------------------------------------------------------
/// Vivid Light
//----------------------------------------------------------------------------------------------------
template <typename FLOATTYPE> MAXON_ATTRIBUTE_FORCE_INLINE FLOATTYPE BlendVividLight(FLOATTYPE background, FLOATTYPE foreground)
{
	return (foreground < FLOATTYPE(0.5)) ? BlendColorBurn(background, (FLOATTYPE(2.0) * foreground)) : BlendColorDodge(background, FLOATTYPE(2.0) * (foreground - FLOATTYPE(0.5)));
}

//----------------------------------------------------------------------------------------------------
/// "Complex" blend modes
/// These modes cannot be applied per-component. Alpha has no meaning with these blend modes, so we just 
/// return the background layer's alpha value.
//----------------------------------------------------------------------------------------------------

//----------------------------------------------------------------------------------------------------
/// Hue
//----------------------------------------------------------------------------------------------------
template <typename COLORTYPE> MAXON_ATTRIBUTE_FORCE_INLINE COLORTYPE BlendHue(const COLORTYPE& background, const COLORTYPE& foreground)
{
	COLORTYPE hsvBackground = RgbToHsv(background);
	COLORTYPE hsvForeground = RgbToHsv(foreground);

	COLORTYPE result = HsvToRgb(COLORTYPE(hsvForeground.r, hsvBackground.g, hsvBackground.b));

	return result;
}

//----------------------------------------------------------------------------------------------------
/// Saturation
//----------------------------------------------------------------------------------------------------
template <typename COLORTYPE> MAXON_ATTRIBUTE_FORCE_INLINE COLORTYPE BlendSaturation(const COLORTYPE& background, const COLORTYPE& foreground)
{
	COLORTYPE hsvBackground = RgbToHsl(background);
	COLORTYPE hsvForeground = RgbToHsl(foreground);

	COLORTYPE result = HslToRgb(COLORTYPE(hsvBackground.r, hsvForeground.g, hsvBackground.b));

	return result;
}

//----------------------------------------------------------------------------------------------------
/// Luminance
//----------------------------------------------------------------------------------------------------
template <typename COLORTYPE> MAXON_ATTRIBUTE_FORCE_INLINE COLORTYPE BlendLuminance(const COLORTYPE& background, const COLORTYPE& foreground)
{
	COLORTYPE hslBackground = RgbToHsl(background);
	COLORTYPE hslForeground = RgbToHsl(foreground);

	COLORTYPE result = HslToRgb(COLORTYPE(hslBackground.r, hslBackground.g, hslForeground.b));

	return result;
}

//----------------------------------------------------------------------------------------------------
/// Color
//----------------------------------------------------------------------------------------------------
template <typename COLORTYPE> MAXON_ATTRIBUTE_FORCE_INLINE COLORTYPE BlendColor(const COLORTYPE& background, const COLORTYPE& foreground)
{
	COLORTYPE hsvBackground = RgbToHsv(background);
	COLORTYPE hsvForeground = RgbToHsv(foreground);

	COLORTYPE result = HsvToRgb(COLORTYPE(hsvForeground.r, hsvForeground.g, hsvBackground.b));

	return result;
}

//----------------------------------------------------------------------------------------------------
/// Levr
//----------------------------------------------------------------------------------------------------
template <typename COLORTYPE> MAXON_ATTRIBUTE_FORCE_INLINE COLORTYPE BlendLevr(const COLORTYPE& background, const COLORTYPE& foreground)
{
	using FLOATTYPE = typename COLORTYPE::ValueType;
	auto lowClip = background.GetAverage();
	auto highClip = Blend(FLOATTYPE(0.0), FLOATTYPE(1.0), background.GetAverage());
	return COLORTYPE(SmoothStep(lowClip, highClip, foreground.r));
}

//----------------------------------------------------------------------------------------------------
// Returns the luminance of a color in RGB space
//----------------------------------------------------------------------------------------------------
template <typename COLORTYPE> static MAXON_ATTRIBUTE_FORCE_INLINE typename COLORTYPE::ValueType LuminanceColor(const COLORTYPE& color)
{
	// Algorithm from "Graphics Shaders: Theory and Practice"
	using FLOATTYPE = typename COLORTYPE::ValueType;
	return Dot(color.GetVector(), COLORTYPE(FLOATTYPE(0.2125), FLOATTYPE(0.7154), FLOATTYPE(0.0721)).GetVector());
}

template <typename COLORATYPE> static MAXON_ATTRIBUTE_FORCE_INLINE typename COLORATYPE::ValueType LuminanceColorA(const COLORATYPE& color)
{
	using FLOATTYPE = typename COLORATYPE::ValueType;
	return FLOATTYPE(LuminanceColor(color.GetColor3()));
}

//----------------------------------------------------------------------------------------------------
/// Darker
//----------------------------------------------------------------------------------------------------
template <typename COLORTYPE> MAXON_ATTRIBUTE_FORCE_INLINE COLORTYPE BlendDarker(const COLORTYPE& background, const COLORTYPE& foreground)
{
	if (LuminanceColor(background) < LuminanceColor(foreground))
		return background;
	else
		return foreground;
}

//----------------------------------------------------------------------------------------------------
/// Lighter
//----------------------------------------------------------------------------------------------------
template <typename COLORTYPE> MAXON_ATTRIBUTE_FORCE_INLINE COLORTYPE BlendLighter(const COLORTYPE& background, const COLORTYPE& foreground)
{
	if (LuminanceColor(background) > LuminanceColor(foreground))
		return background;
	else
		return foreground;
}

#define SIMPLE_BLEND_RGB(background, foreground, blendFunction)									\
	COLORTYPE(blendFunction(background.r, foreground.r),													\
						blendFunction(background.g, foreground.g),													\
						blendFunction(background.b, foreground.b))

enum class BLEND_MODES
{
	ADD,
	AVERAGE,
	COLOR,
	COLORBURN,
	COLORDODGE,
	DARKEN,
	DARKER,
	DIFFERENCE,
	DISSOLVE,
	DIVIDE,
	EXCLUSION,
	FREEZE,
	GLOW,
	HARDLIGHT,
	HARDMIX,
	HEAT,
	HUE,
	HYPOT,
	LEVR,
	LIGHTEN,
	LIGHTER,
	LINEARBURN,
	LINEARDODGE,
	LUMINANCE,
	MULTIPLY,
	OVER,
	OVERLAY,
	PINLIGHT,
	REFLECT,
	SATURATION,
	SCREEN,
	SOFTLIGHT,
	SUBTRACT,
	VIVIDLIGHT,
	XOR,
	PASSFOLDER,
	STAMP
} MAXON_ENUM_LIST(BLEND_MODES);

template<BLEND_MODES MODE, typename COLORATYPE>
static MAXON_ATTRIBUTE_FORCE_INLINE COLORATYPE BlendRGBA(const COLORATYPE& background, const COLORATYPE& foreground, typename COLORATYPE::ValueType opacity)
{
	using FLOATTYPE = typename COLORATYPE::ValueType;
	using COLORTYPE = Col3<FLOATTYPE, 1>;

	// Reference: https://www.adobe.com/content/dam/acom/en/devnet/acrobat/pdfs/PDF32000_2008.pdf, Page 322ff
	// See also: Porter/Duff Compositing Algebra (http://ssp.impulsetrain.com/porterduff.html)

	FLOATTYPE foregroundOpacity = foreground.a * opacity;

	// Nothing to do if the foreground is completely transparent
	if (foregroundOpacity == FLOATTYPE(0.0))
		return background;

	// The compositing formulas work on regular colors without alpha components. The alpha handling itself is an 
	// outside consideration and done at the end of this routine.
	const COLORTYPE& fore = foreground.GetColor3();
	const COLORTYPE& back = background.GetColor3();
	COLORTYPE blendResult;

	MAXON_SWITCH_CHECKALLENUMS_BEGIN;
	switch (MODE)
	{
		// The following blend modes are applied per-component (RGB + A)
		default:
		case BLEND_MODES::PASSFOLDER:
		case BLEND_MODES::OVER:
			blendResult = SIMPLE_BLEND_RGB(back, fore, BlendOver);
			break;
		case BLEND_MODES::AVERAGE:
			blendResult = SIMPLE_BLEND_RGB(back, fore, BlendAverage);
			break;
		case BLEND_MODES::ADD:
			blendResult = SIMPLE_BLEND_RGB(back, fore, BlendAdd);
			break;
		case BLEND_MODES::MULTIPLY:
			blendResult = SIMPLE_BLEND_RGB(back, fore, BlendMultiply);
			break;
		case BLEND_MODES::SUBTRACT:
			blendResult = SIMPLE_BLEND_RGB(back, fore, BlendSubtract);
			break;
		case BLEND_MODES::LINEARBURN:
			blendResult = SIMPLE_BLEND_RGB(back, fore, BlendLinearBurn);
			break;
		case BLEND_MODES::LINEARDODGE:
			blendResult = SIMPLE_BLEND_RGB(back, fore, BlendLinearDodge);
			break;
		case BLEND_MODES::DIVIDE:
			blendResult = SIMPLE_BLEND_RGB(back, fore, BlendDivide);
			break;
		case BLEND_MODES::SCREEN:
			blendResult = SIMPLE_BLEND_RGB(back, fore, BlendScreen);
			break;
		case BLEND_MODES::LIGHTEN:
			blendResult = SIMPLE_BLEND_RGB(back, fore, BlendLighten);
			break;
		case BLEND_MODES::DARKEN:
			blendResult = SIMPLE_BLEND_RGB(back, fore, BlendDarken);
			break;
		case BLEND_MODES::OVERLAY:
			blendResult = SIMPLE_BLEND_RGB(back, fore, BlendOverlay);
			break;
		case BLEND_MODES::HARDLIGHT:
			blendResult = SIMPLE_BLEND_RGB(back, fore, BlendHardLight);
			break;
		case BLEND_MODES::SOFTLIGHT:
			blendResult = SIMPLE_BLEND_RGB(back, fore, BlendSoftLight);
			break;
		case BLEND_MODES::DIFFERENCE:
			blendResult = SIMPLE_BLEND_RGB(back, fore, BlendDifference);
			break;
		case BLEND_MODES::EXCLUSION:
			blendResult = SIMPLE_BLEND_RGB(back, fore, BlendExclusion);
			break;
		case BLEND_MODES::GLOW:
			blendResult = SIMPLE_BLEND_RGB(back, fore, BlendGlow);
			break;
		case BLEND_MODES::FREEZE:
			blendResult = SIMPLE_BLEND_RGB(back, fore, BlendFreeze);
			break;
		case BLEND_MODES::HEAT:
			blendResult = SIMPLE_BLEND_RGB(back, fore, BlendHeat);
			break;
		case BLEND_MODES::REFLECT:
			blendResult = SIMPLE_BLEND_RGB(back, fore, BlendReflect);
			break;
		case BLEND_MODES::PINLIGHT:
			blendResult = SIMPLE_BLEND_RGB(back, fore, BlendPinLight);
			break;
		case BLEND_MODES::VIVIDLIGHT:
			blendResult = SIMPLE_BLEND_RGB(back, fore, BlendVividLight);
			break;
		case BLEND_MODES::HARDMIX:
			blendResult = SIMPLE_BLEND_RGB(back, fore, BlendHardMix);
			break;
		case BLEND_MODES::COLORBURN:
			blendResult = SIMPLE_BLEND_RGB(back, fore, BlendColorBurn);
			break;
		case BLEND_MODES::COLORDODGE:
			blendResult = SIMPLE_BLEND_RGB(back, fore, BlendColorDodge);
			break;
		case BLEND_MODES::XOR:
			blendResult = SIMPLE_BLEND_RGB(back, fore, BlendXor);
			break;
		case BLEND_MODES::HYPOT:
			blendResult = SIMPLE_BLEND_RGB(back, fore, BlendHypot);
			break;
		case BLEND_MODES::DISSOLVE:
			blendResult = SIMPLE_BLEND_RGB(back, fore, Dissolve);
			break;
		case BLEND_MODES::STAMP:
			blendResult = SIMPLE_BLEND_RGB(back, fore, BlendStamp);
			break;

			// The following blend modes cannot be applied per component and are calculated as a whole.
		case BLEND_MODES::HUE:
			blendResult = BlendHue(back, fore);
			break;
		case BLEND_MODES::COLOR:
			blendResult = BlendColor(back, fore);
			break;
		case BLEND_MODES::SATURATION:
			blendResult = BlendSaturation(back, fore);
			break;
		case BLEND_MODES::LUMINANCE:
			blendResult = BlendLuminance(back, fore);
			break;
		case BLEND_MODES::LEVR:
			blendResult = BlendLevr(back, fore);
			break;
		case BLEND_MODES::DARKER:
			blendResult = BlendDarker(back, fore);
			break;
		case BLEND_MODES::LIGHTER:
			blendResult = BlendLighter(back, fore);
			break;
	}
	MAXON_SWITCH_CHECKALLENUMS_END;

	// Basic compositing formula as documented in Adobe's PDF format documentation.
	// ALPHAs    = foreground.a
	// ALPHAb    = background.a
	// ALPHAr    = foreground.a + background.a - foreground.a * background.a  (see 11.3.7.3)
	// Cs        = fore
	// Cb        = back
	// B(Cb, Cs) = blendResult

	FLOATTYPE resultAlpha = foregroundOpacity + background.a - foregroundOpacity * background.a;

	// resultAlpha cannot be zero as foreground.a is guaranteed to be > FLOATTYPE(0.0) (see above)
	FLOATTYPE alphaFactor = foregroundOpacity / resultAlpha;

	blendResult = (FLOATTYPE(1.0) - alphaFactor) * back + alphaFactor * ((FLOATTYPE(1.0) - background.a) * fore + background.a * blendResult);

	return COLORATYPE(blendResult.r, blendResult.g, blendResult.b, resultAlpha);
}

}

#endif // GFX_IMAGE_BLEND_FUNCTIONS_H__
