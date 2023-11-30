#ifndef COLOR_NODES_H__
#define COLOR_NODES_H__

#include "maxon/fid.h"
#include "maxon/vector.h"
#include "maxon/vector2d.h"
#include "maxon/vector4d.h"

//----------------------------------------------------------------------------------------
// BEGIN - auto generated code, do not edit
//----------------------------------------------------------------------------------------
namespace maxon
{
namespace PATTERN
{
	namespace NODE
	{
		namespace CONVERSION
		{
			namespace COLORPROFILE
			{
				MAXON_RESOURCE_DATABASE_SCOPE("net.maxon.pattern.node.conversion.colorprofile");

				// supports MAXON::NODE::BASE::FILTERTAGS
				// supports MAXON::NODE::BASE::NODEPREVIEWIMAGE
				// supports MAXON::NODE::BASE::MATERIALPREVIEWIMAGE
				// supports MAXON::NODE::BASE::NAME
				// supports MAXON::NODE::BASE::ASSETVERSION
				// supports MAXON::NODE::BASE::COLOR
				// supports MAXON::NODE::BASE::PORTDISPLAY
				// supports MAXON::NODE::BASE::DISPLAYPREVIEW
				// supports MAXON::NODE::BASE::DISPLAYCOMMENT
				// supports MAXON::NODE::BASE::COMMENT
				// supports MAXON::NODE::BASE::CATEGORY
				// supports MAXON::NODE::BASE::ICON
				// supports MAXON::NODE::BASE::UPDATEPOLICY
				// supports MAXON::ASSET::BASE::PROTECTED
				// supports MAXON::PATTERN::INCLUDE::COLORMASK::MASKBLEND
				// supports MAXON::PATTERN::INCLUDE::COLORMASK::MASKRED
				// supports MAXON::PATTERN::INCLUDE::COLORMASK::MASKGREEN
				// supports MAXON::PATTERN::INCLUDE::COLORMASK::MASKBLUE
				// supports MAXON::PATTERN::INCLUDE::COLORMASK::MASKALPHA

				MAXON_ATTRIBUTE(ColorA, COLOR, "color");

				MAXON_ATTRIBUTE(InternedId, INPROFILE, "inprofile");
				MAXON_ATTRIBUTE(void, INPROFILE_ENUM_SRGB, "srgb");
				MAXON_ATTRIBUTE(void, INPROFILE_ENUM_GAMMA, "gamma");
				MAXON_ATTRIBUTE(void, INPROFILE_ENUM_LINEAR, "linear");
				MAXON_ATTRIBUTE(void, INPROFILE_ENUM_REC709, "rec709");
				MAXON_ATTRIBUTE(void, INPROFILE_ENUM_CINEON, "cineon");

				MAXON_ATTRIBUTE(InternedId, OUTPROFILE, "outprofile");
				MAXON_ATTRIBUTE(void, OUTPROFILE_ENUM_SRGB, "srgb");
				MAXON_ATTRIBUTE(void, OUTPROFILE_ENUM_GAMMA, "gamma");
				MAXON_ATTRIBUTE(void, OUTPROFILE_ENUM_LINEAR, "linear");
				MAXON_ATTRIBUTE(void, OUTPROFILE_ENUM_REC709, "rec709");
				MAXON_ATTRIBUTE(void, OUTPROFILE_ENUM_CINEON, "cineon");

				MAXON_ATTRIBUTE(Float, GAMMA, "gamma");

				MAXON_ATTRIBUTE(Float, BLACKPOINT, "blackpoint");

				MAXON_ATTRIBUTE(Float, WHITEPOINT, "whitepoint");

				MAXON_ATTRIBUTE(Float, FILMGAMMA, "filmgamma");

				MAXON_ATTRIBUTE(ColorA, RESULT, "result");

				MAXON_ATTRIBUTE(InternedId, DIRECTION, "direction");
				MAXON_ATTRIBUTE(void, DIRECTION_ENUM_FORWARD, "forward");
				MAXON_ATTRIBUTE(void, DIRECTION_ENUM_INVERSE, "inverse");
			}

			namespace COLORSPACE
			{
				MAXON_RESOURCE_DATABASE_SCOPE("net.maxon.pattern.node.conversion.colorspace");

				// supports MAXON::NODE::BASE::FILTERTAGS
				// supports MAXON::NODE::BASE::NODEPREVIEWIMAGE
				// supports MAXON::NODE::BASE::MATERIALPREVIEWIMAGE
				// supports MAXON::NODE::BASE::NAME
				// supports MAXON::NODE::BASE::ASSETVERSION
				// supports MAXON::NODE::BASE::COLOR
				// supports MAXON::NODE::BASE::PORTDISPLAY
				// supports MAXON::NODE::BASE::DISPLAYPREVIEW
				// supports MAXON::NODE::BASE::DISPLAYCOMMENT
				// supports MAXON::NODE::BASE::COMMENT
				// supports MAXON::NODE::BASE::CATEGORY
				// supports MAXON::NODE::BASE::ICON
				// supports MAXON::NODE::BASE::UPDATEPOLICY
				// supports MAXON::ASSET::BASE::PROTECTED
				// supports MAXON::PATTERN::INCLUDE::COLORMASK::MASKBLEND
				// supports MAXON::PATTERN::INCLUDE::COLORMASK::MASKRED
				// supports MAXON::PATTERN::INCLUDE::COLORMASK::MASKGREEN
				// supports MAXON::PATTERN::INCLUDE::COLORMASK::MASKBLUE
				// supports MAXON::PATTERN::INCLUDE::COLORMASK::MASKALPHA

				MAXON_ATTRIBUTE(ColorA, COLOR, "color");

				MAXON_ATTRIBUTE(InternedId, INCOLORSPACE, "incolorspace");
				MAXON_ATTRIBUTE(void, INCOLORSPACE_ENUM_RGB, "rgb");
				MAXON_ATTRIBUTE(void, INCOLORSPACE_ENUM_HSV, "hsv");
				MAXON_ATTRIBUTE(void, INCOLORSPACE_ENUM_HSL, "hsl");
				MAXON_ATTRIBUTE(void, INCOLORSPACE_ENUM_XYZ, "xyz");
				MAXON_ATTRIBUTE(void, INCOLORSPACE_ENUM_CMY, "cmy");

				MAXON_ATTRIBUTE(InternedId, OUTCOLORSPACE, "outcolorspace");
				MAXON_ATTRIBUTE(void, OUTCOLORSPACE_ENUM_RGB, "rgb");
				MAXON_ATTRIBUTE(void, OUTCOLORSPACE_ENUM_HSV, "hsv");
				MAXON_ATTRIBUTE(void, OUTCOLORSPACE_ENUM_HSL, "hsl");
				MAXON_ATTRIBUTE(void, OUTCOLORSPACE_ENUM_XYZ, "xyz");
				MAXON_ATTRIBUTE(void, OUTCOLORSPACE_ENUM_CMY, "cmy");

				MAXON_ATTRIBUTE(ColorA, RESULT, "result");
			}

			namespace OCIO
			{
				MAXON_RESOURCE_DATABASE_SCOPE("net.maxon.pattern.node.conversion.ocio");

				// supports MAXON::NODE::BASE::FILTERTAGS
				// supports MAXON::NODE::BASE::NODEPREVIEWIMAGE
				// supports MAXON::NODE::BASE::MATERIALPREVIEWIMAGE
				// supports MAXON::NODE::BASE::NAME
				// supports MAXON::NODE::BASE::ASSETVERSION
				// supports MAXON::NODE::BASE::COLOR
				// supports MAXON::NODE::BASE::PORTDISPLAY
				// supports MAXON::NODE::BASE::DISPLAYPREVIEW
				// supports MAXON::NODE::BASE::DISPLAYCOMMENT
				// supports MAXON::NODE::BASE::COMMENT
				// supports MAXON::NODE::BASE::CATEGORY
				// supports MAXON::NODE::BASE::ICON
				// supports MAXON::NODE::BASE::UPDATEPOLICY
				// supports MAXON::ASSET::BASE::PROTECTED

				MAXON_ATTRIBUTE(ColorA, COLOR, "color");

				MAXON_ATTRIBUTE(CString, INPROFILE, "inprofile");

				MAXON_ATTRIBUTE(CString, OUTPROFILE, "outprofile");

				MAXON_ATTRIBUTE(ColorA, RESULT, "result");
			}
		}

		namespace EFFECT
		{
			namespace BIASGAIN
			{
				MAXON_RESOURCE_DATABASE_SCOPE("net.maxon.pattern.node.effect.biasgain");

				// supports MAXON::NODE::BASE::FILTERTAGS
				// supports MAXON::NODE::BASE::NODEPREVIEWIMAGE
				// supports MAXON::NODE::BASE::MATERIALPREVIEWIMAGE
				// supports MAXON::NODE::BASE::NAME
				// supports MAXON::NODE::BASE::ASSETVERSION
				// supports MAXON::NODE::BASE::COLOR
				// supports MAXON::NODE::BASE::PORTDISPLAY
				// supports MAXON::NODE::BASE::DISPLAYPREVIEW
				// supports MAXON::NODE::BASE::DISPLAYCOMMENT
				// supports MAXON::NODE::BASE::COMMENT
				// supports MAXON::NODE::BASE::CATEGORY
				// supports MAXON::NODE::BASE::ICON
				// supports MAXON::NODE::BASE::UPDATEPOLICY
				// supports MAXON::ASSET::BASE::PROTECTED
				// supports MAXON::PATTERN::INCLUDE::COLORMASK::MASKBLEND
				// supports MAXON::PATTERN::INCLUDE::COLORMASK::MASKRED
				// supports MAXON::PATTERN::INCLUDE::COLORMASK::MASKGREEN
				// supports MAXON::PATTERN::INCLUDE::COLORMASK::MASKBLUE
				// supports MAXON::PATTERN::INCLUDE::COLORMASK::MASKALPHA

				MAXON_ATTRIBUTE(ColorA, COLOR, "color");

				MAXON_ATTRIBUTE(Float, BIAS, "bias");

				MAXON_ATTRIBUTE(Float, GAIN, "gain");

				MAXON_ATTRIBUTE(ColorA, RESULT, "result");
			}

			namespace BLEND
			{
				MAXON_RESOURCE_DATABASE_SCOPE("net.maxon.pattern.node.effect.blend");

				// supports MAXON::NODE::BASE::FILTERTAGS
				// supports MAXON::NODE::BASE::NODEPREVIEWIMAGE
				// supports MAXON::NODE::BASE::MATERIALPREVIEWIMAGE
				// supports MAXON::NODE::BASE::NAME
				// supports MAXON::NODE::BASE::ASSETVERSION
				// supports MAXON::NODE::BASE::COLOR
				// supports MAXON::NODE::BASE::PORTDISPLAY
				// supports MAXON::NODE::BASE::DISPLAYPREVIEW
				// supports MAXON::NODE::BASE::DISPLAYCOMMENT
				// supports MAXON::NODE::BASE::COMMENT
				// supports MAXON::NODE::BASE::CATEGORY
				// supports MAXON::NODE::BASE::ICON
				// supports MAXON::NODE::BASE::UPDATEPOLICY
				// supports MAXON::ASSET::BASE::PROTECTED
				// supports MAXON::PATTERN::INCLUDE::COLORMASK::MASKBLEND
				// supports MAXON::PATTERN::INCLUDE::COLORMASK::MASKRED
				// supports MAXON::PATTERN::INCLUDE::COLORMASK::MASKGREEN
				// supports MAXON::PATTERN::INCLUDE::COLORMASK::MASKBLUE
				// supports MAXON::PATTERN::INCLUDE::COLORMASK::MASKALPHA

				MAXON_ATTRIBUTE(ColorA, FOREGROUND, "foreground");

				MAXON_ATTRIBUTE(ColorA, BACKGROUND, "background");

				MAXON_ATTRIBUTE(Id, BLENDMODE, "blendmode");

				MAXON_ATTRIBUTE(InternedId, ALPHAHANDLING, "alphahandling");
				MAXON_ATTRIBUTE(void, ALPHAHANDLING_ENUM_COMPOSITING, "compositing");
				MAXON_ATTRIBUTE(void, ALPHAHANDLING_ENUM_BLEND, "blend");
				MAXON_ATTRIBUTE(void, ALPHAHANDLING_ENUM_BACKGROUND, "background");
				MAXON_ATTRIBUTE(void, ALPHAHANDLING_ENUM_FOREGROUND, "foreground");
				MAXON_ATTRIBUTE(void, ALPHAHANDLING_ENUM_ZERO, "zero");
				MAXON_ATTRIBUTE(void, ALPHAHANDLING_ENUM_ONE, "one");

				MAXON_ATTRIBUTE(ColorA, RESULT, "result");

				// supports MAXON::RENDER::INCLUDE::CONTEXT::CONTEXT
			}

			namespace COLORCORRECTION
			{
				MAXON_RESOURCE_DATABASE_SCOPE("net.maxon.pattern.node.effect.colorcorrection");

				// supports MAXON::NODE::BASE::FILTERTAGS
				// supports MAXON::NODE::BASE::NODEPREVIEWIMAGE
				// supports MAXON::NODE::BASE::MATERIALPREVIEWIMAGE
				// supports MAXON::NODE::BASE::NAME
				// supports MAXON::NODE::BASE::ASSETVERSION
				// supports MAXON::NODE::BASE::COLOR
				// supports MAXON::NODE::BASE::PORTDISPLAY
				// supports MAXON::NODE::BASE::DISPLAYPREVIEW
				// supports MAXON::NODE::BASE::DISPLAYCOMMENT
				// supports MAXON::NODE::BASE::COMMENT
				// supports MAXON::NODE::BASE::CATEGORY
				// supports MAXON::NODE::BASE::ICON
				// supports MAXON::NODE::BASE::UPDATEPOLICY
				// supports MAXON::ASSET::BASE::PROTECTED

				MAXON_ATTRIBUTE(ColorA, COLOR, "color");

				MAXON_ATTRIBUTE(Float, HUERED, "huered");

				MAXON_ATTRIBUTE(Float, HUEORANGE, "hueorange");

				MAXON_ATTRIBUTE(Float, HUEYELLOW, "hueyellow");

				MAXON_ATTRIBUTE(Float, HUEGREEN, "huegreen");

				MAXON_ATTRIBUTE(Float, HUEAQUA, "hueaqua");

				MAXON_ATTRIBUTE(Float, HUEBLUE, "hueblue");

				MAXON_ATTRIBUTE(Float, HUEPURPLE, "huepurple");

				MAXON_ATTRIBUTE(Float, HUEMAGENTA, "huemagenta");

				MAXON_ATTRIBUTE(Float, SATURATIONRED, "saturationred");

				MAXON_ATTRIBUTE(Float, SATURATIONORANGE, "saturationorange");

				MAXON_ATTRIBUTE(Float, SATURATIONYELLOW, "saturationyellow");

				MAXON_ATTRIBUTE(Float, SATURATIONGREEN, "saturationgreen");

				MAXON_ATTRIBUTE(Float, SATURATIONAQUA, "saturationaqua");

				MAXON_ATTRIBUTE(Float, SATURATIONBLUE, "saturationblue");

				MAXON_ATTRIBUTE(Float, SATURATIONPURPLE, "saturationpurple");

				MAXON_ATTRIBUTE(Float, SATURATIONMAGENTA, "saturationmagenta");

				MAXON_ATTRIBUTE(Float, LUMINANCERED, "luminancered");

				MAXON_ATTRIBUTE(Float, LUMINANCEORANGE, "luminanceorange");

				MAXON_ATTRIBUTE(Float, LUMINANCEYELLOW, "luminanceyellow");

				MAXON_ATTRIBUTE(Float, LUMINANCEGREEN, "luminancegreen");

				MAXON_ATTRIBUTE(Float, LUMINANCEAQUA, "luminanceaqua");

				MAXON_ATTRIBUTE(Float, LUMINANCEBLUE, "luminanceblue");

				MAXON_ATTRIBUTE(Float, LUMINANCEPURPLE, "luminancepurple");

				MAXON_ATTRIBUTE(Float, LUMINANCEMAGENTA, "luminancemagenta");

				MAXON_ATTRIBUTE(ColorA, RESULT, "result");

				// supports MAXON::PATTERN::INCLUDE::COLORMASK::MASKBLEND
				// supports MAXON::PATTERN::INCLUDE::COLORMASK::MASKRED
				// supports MAXON::PATTERN::INCLUDE::COLORMASK::MASKGREEN
				// supports MAXON::PATTERN::INCLUDE::COLORMASK::MASKBLUE
				// supports MAXON::PATTERN::INCLUDE::COLORMASK::MASKALPHA

				MAXON_ATTRIBUTE(Group, HUE, "hue");

				MAXON_ATTRIBUTE(Group, SATURATION, "saturation");

				MAXON_ATTRIBUTE(Group, LUMINANCE, "luminance");
			}

			namespace COLORHSL
			{
				MAXON_RESOURCE_DATABASE_SCOPE("net.maxon.pattern.node.effect.colorhsl");

				// supports MAXON::NODE::BASE::FILTERTAGS
				// supports MAXON::NODE::BASE::NODEPREVIEWIMAGE
				// supports MAXON::NODE::BASE::MATERIALPREVIEWIMAGE
				// supports MAXON::NODE::BASE::NAME
				// supports MAXON::NODE::BASE::ASSETVERSION
				// supports MAXON::NODE::BASE::COLOR
				// supports MAXON::NODE::BASE::PORTDISPLAY
				// supports MAXON::NODE::BASE::DISPLAYPREVIEW
				// supports MAXON::NODE::BASE::DISPLAYCOMMENT
				// supports MAXON::NODE::BASE::COMMENT
				// supports MAXON::NODE::BASE::CATEGORY
				// supports MAXON::NODE::BASE::ICON
				// supports MAXON::NODE::BASE::UPDATEPOLICY
				// supports MAXON::ASSET::BASE::PROTECTED

				MAXON_ATTRIBUTE(ColorA, COLOR, "color");

				MAXON_ATTRIBUTE(Float, HUE, "hue");

				MAXON_ATTRIBUTE(Float, SATURATION, "saturation");

				MAXON_ATTRIBUTE(Float, VALUE, "value");

				MAXON_ATTRIBUTE(Bool, COLORIZE, "colorize");

				MAXON_ATTRIBUTE(ColorA, RESULT, "result");

				// supports MAXON::PATTERN::INCLUDE::COLORMASK::MASKBLEND
				// supports MAXON::PATTERN::INCLUDE::COLORMASK::MASKRED
				// supports MAXON::PATTERN::INCLUDE::COLORMASK::MASKGREEN
				// supports MAXON::PATTERN::INCLUDE::COLORMASK::MASKBLUE
				// supports MAXON::PATTERN::INCLUDE::COLORMASK::MASKALPHA
			}

			namespace COLORTEMPERATURE
			{
				MAXON_RESOURCE_DATABASE_SCOPE("net.maxon.pattern.node.effect.colortemperature");

				// supports MAXON::NODE::BASE::FILTERTAGS
				// supports MAXON::NODE::BASE::NODEPREVIEWIMAGE
				// supports MAXON::NODE::BASE::MATERIALPREVIEWIMAGE
				// supports MAXON::NODE::BASE::NAME
				// supports MAXON::NODE::BASE::ASSETVERSION
				// supports MAXON::NODE::BASE::COLOR
				// supports MAXON::NODE::BASE::PORTDISPLAY
				// supports MAXON::NODE::BASE::DISPLAYPREVIEW
				// supports MAXON::NODE::BASE::DISPLAYCOMMENT
				// supports MAXON::NODE::BASE::COMMENT
				// supports MAXON::NODE::BASE::CATEGORY
				// supports MAXON::NODE::BASE::ICON
				// supports MAXON::NODE::BASE::UPDATEPOLICY
				// supports MAXON::ASSET::BASE::PROTECTED

				MAXON_ATTRIBUTE(ColorA, COLOR, "color");

				MAXON_ATTRIBUTE(Float, TEMPERATURE, "temperature");

				MAXON_ATTRIBUTE(Float, TINT, "tint");

				MAXON_ATTRIBUTE(ColorA, RESULT, "result");

				// supports MAXON::PATTERN::INCLUDE::COLORMASK::MASKBLEND
				// supports MAXON::PATTERN::INCLUDE::COLORMASK::MASKRED
				// supports MAXON::PATTERN::INCLUDE::COLORMASK::MASKGREEN
				// supports MAXON::PATTERN::INCLUDE::COLORMASK::MASKBLUE
				// supports MAXON::PATTERN::INCLUDE::COLORMASK::MASKALPHA
			}

			namespace CONTRAST
			{
				MAXON_RESOURCE_DATABASE_SCOPE("net.maxon.pattern.node.effect.contrast");

				// supports MAXON::NODE::BASE::FILTERTAGS
				// supports MAXON::NODE::BASE::NODEPREVIEWIMAGE
				// supports MAXON::NODE::BASE::MATERIALPREVIEWIMAGE
				// supports MAXON::NODE::BASE::NAME
				// supports MAXON::NODE::BASE::ASSETVERSION
				// supports MAXON::NODE::BASE::COLOR
				// supports MAXON::NODE::BASE::PORTDISPLAY
				// supports MAXON::NODE::BASE::DISPLAYPREVIEW
				// supports MAXON::NODE::BASE::DISPLAYCOMMENT
				// supports MAXON::NODE::BASE::COMMENT
				// supports MAXON::NODE::BASE::CATEGORY
				// supports MAXON::NODE::BASE::ICON
				// supports MAXON::NODE::BASE::UPDATEPOLICY
				// supports MAXON::ASSET::BASE::PROTECTED

				MAXON_ATTRIBUTE(ColorA, COLOR, "color");

				MAXON_ATTRIBUTE(Float, CONTRAST, "contrast");

				MAXON_ATTRIBUTE(ColorA, RESULT, "result");

				// supports MAXON::PATTERN::INCLUDE::COLORMASK::MASKBLEND
				// supports MAXON::PATTERN::INCLUDE::COLORMASK::MASKRED
				// supports MAXON::PATTERN::INCLUDE::COLORMASK::MASKGREEN
				// supports MAXON::PATTERN::INCLUDE::COLORMASK::MASKBLUE
				// supports MAXON::PATTERN::INCLUDE::COLORMASK::MASKALPHA
			}

			namespace EXPOSURE
			{
				MAXON_RESOURCE_DATABASE_SCOPE("net.maxon.pattern.node.effect.exposure");

				// supports MAXON::NODE::BASE::FILTERTAGS
				// supports MAXON::NODE::BASE::NODEPREVIEWIMAGE
				// supports MAXON::NODE::BASE::MATERIALPREVIEWIMAGE
				// supports MAXON::NODE::BASE::NAME
				// supports MAXON::NODE::BASE::ASSETVERSION
				// supports MAXON::NODE::BASE::COLOR
				// supports MAXON::NODE::BASE::PORTDISPLAY
				// supports MAXON::NODE::BASE::DISPLAYPREVIEW
				// supports MAXON::NODE::BASE::DISPLAYCOMMENT
				// supports MAXON::NODE::BASE::COMMENT
				// supports MAXON::NODE::BASE::CATEGORY
				// supports MAXON::NODE::BASE::ICON
				// supports MAXON::NODE::BASE::UPDATEPOLICY
				// supports MAXON::ASSET::BASE::PROTECTED
				// supports MAXON::PATTERN::INCLUDE::COLORMASK::MASKBLEND
				// supports MAXON::PATTERN::INCLUDE::COLORMASK::MASKRED
				// supports MAXON::PATTERN::INCLUDE::COLORMASK::MASKGREEN
				// supports MAXON::PATTERN::INCLUDE::COLORMASK::MASKBLUE
				// supports MAXON::PATTERN::INCLUDE::COLORMASK::MASKALPHA

				MAXON_ATTRIBUTE(ColorA, COLOR, "color");

				MAXON_ATTRIBUTE(Float, EXPOSURE, "exposure");

				MAXON_ATTRIBUTE(Float, OFFSET, "offset");

				MAXON_ATTRIBUTE(Float, GAMMA, "gamma");

				MAXON_ATTRIBUTE(ColorA, RESULT, "result");
			}

			namespace INVERTCOLOR
			{
				MAXON_RESOURCE_DATABASE_SCOPE("net.maxon.pattern.node.effect.invertcolor");

				// supports MAXON::NODE::BASE::FILTERTAGS
				// supports MAXON::NODE::BASE::NODEPREVIEWIMAGE
				// supports MAXON::NODE::BASE::MATERIALPREVIEWIMAGE
				// supports MAXON::NODE::BASE::NAME
				// supports MAXON::NODE::BASE::ASSETVERSION
				// supports MAXON::NODE::BASE::COLOR
				// supports MAXON::NODE::BASE::PORTDISPLAY
				// supports MAXON::NODE::BASE::DISPLAYPREVIEW
				// supports MAXON::NODE::BASE::DISPLAYCOMMENT
				// supports MAXON::NODE::BASE::COMMENT
				// supports MAXON::NODE::BASE::CATEGORY
				// supports MAXON::NODE::BASE::ICON
				// supports MAXON::NODE::BASE::UPDATEPOLICY
				// supports MAXON::ASSET::BASE::PROTECTED
				// supports MAXON::PATTERN::INCLUDE::COLORMASK::MASKBLEND
				// supports MAXON::PATTERN::INCLUDE::COLORMASK::MASKRED
				// supports MAXON::PATTERN::INCLUDE::COLORMASK::MASKGREEN
				// supports MAXON::PATTERN::INCLUDE::COLORMASK::MASKBLUE
				// supports MAXON::PATTERN::INCLUDE::COLORMASK::MASKALPHA

				MAXON_ATTRIBUTE(ColorA, COLOR, "color");

				MAXON_ATTRIBUTE(ColorA, RESULT, "result");
			}

			namespace KEYER
			{
				MAXON_RESOURCE_DATABASE_SCOPE("net.maxon.pattern.node.effect.keyer");

				// supports MAXON::NODE::BASE::FILTERTAGS
				// supports MAXON::NODE::BASE::NODEPREVIEWIMAGE
				// supports MAXON::NODE::BASE::MATERIALPREVIEWIMAGE
				// supports MAXON::NODE::BASE::NAME
				// supports MAXON::NODE::BASE::ASSETVERSION
				// supports MAXON::NODE::BASE::COLOR
				// supports MAXON::NODE::BASE::PORTDISPLAY
				// supports MAXON::NODE::BASE::DISPLAYPREVIEW
				// supports MAXON::NODE::BASE::DISPLAYCOMMENT
				// supports MAXON::NODE::BASE::COMMENT
				// supports MAXON::NODE::BASE::CATEGORY
				// supports MAXON::NODE::BASE::ICON
				// supports MAXON::NODE::BASE::UPDATEPOLICY
				// supports MAXON::ASSET::BASE::PROTECTED

				MAXON_ATTRIBUTE(ColorA, COLOR, "color");

				MAXON_ATTRIBUTE(Color, KEY, "key");

				MAXON_ATTRIBUTE(InternedId, MODE, "mode");
				MAXON_ATTRIBUTE(void, MODE_ENUM_KEYIN, "keyin");
				MAXON_ATTRIBUTE(void, MODE_ENUM_KEYOUT, "keyout");

				MAXON_ATTRIBUTE(Float, TOLERANCEMIN, "tolerancemin");

				MAXON_ATTRIBUTE(Float, TOLERANCEMAX, "tolerancemax");

				MAXON_ATTRIBUTE(ColorA, RESULT, "result");

				MAXON_ATTRIBUTE(Float, MASK, "mask");

				MAXON_ATTRIBUTE(Group, GROUPTOLERANCE, "grouptolerance");
			}

			namespace PREMULTIPLY
			{
				MAXON_RESOURCE_DATABASE_SCOPE("net.maxon.pattern.node.effect.premultiply");

				// supports MAXON::NODE::BASE::FILTERTAGS
				// supports MAXON::NODE::BASE::NODEPREVIEWIMAGE
				// supports MAXON::NODE::BASE::MATERIALPREVIEWIMAGE
				// supports MAXON::NODE::BASE::NAME
				// supports MAXON::NODE::BASE::ASSETVERSION
				// supports MAXON::NODE::BASE::COLOR
				// supports MAXON::NODE::BASE::PORTDISPLAY
				// supports MAXON::NODE::BASE::DISPLAYPREVIEW
				// supports MAXON::NODE::BASE::DISPLAYCOMMENT
				// supports MAXON::NODE::BASE::COMMENT
				// supports MAXON::NODE::BASE::CATEGORY
				// supports MAXON::NODE::BASE::ICON
				// supports MAXON::NODE::BASE::UPDATEPOLICY
				// supports MAXON::ASSET::BASE::PROTECTED
				// supports MAXON::PATTERN::INCLUDE::COLORMASK::MASKBLEND
				// supports MAXON::PATTERN::INCLUDE::COLORMASK::MASKRED
				// supports MAXON::PATTERN::INCLUDE::COLORMASK::MASKGREEN
				// supports MAXON::PATTERN::INCLUDE::COLORMASK::MASKBLUE
				// supports MAXON::PATTERN::INCLUDE::COLORMASK::MASKALPHA

				MAXON_ATTRIBUTE(ColorA, COLOR, "color");

				MAXON_ATTRIBUTE(ColorA, RESULT, "result");
			}

			namespace SHUFFLE
			{
				MAXON_RESOURCE_DATABASE_SCOPE("net.maxon.pattern.node.effect.shuffle");

				// supports MAXON::NODE::BASE::FILTERTAGS
				// supports MAXON::NODE::BASE::NODEPREVIEWIMAGE
				// supports MAXON::NODE::BASE::MATERIALPREVIEWIMAGE
				// supports MAXON::NODE::BASE::NAME
				// supports MAXON::NODE::BASE::ASSETVERSION
				// supports MAXON::NODE::BASE::COLOR
				// supports MAXON::NODE::BASE::PORTDISPLAY
				// supports MAXON::NODE::BASE::DISPLAYPREVIEW
				// supports MAXON::NODE::BASE::DISPLAYCOMMENT
				// supports MAXON::NODE::BASE::COMMENT
				// supports MAXON::NODE::BASE::CATEGORY
				// supports MAXON::NODE::BASE::ICON
				// supports MAXON::NODE::BASE::UPDATEPOLICY
				// supports MAXON::ASSET::BASE::PROTECTED

				MAXON_ATTRIBUTE(ColorA, COLOR, "color");

				MAXON_ATTRIBUTE(InternedId, REDCOMPONENT, "redcomponent");
				MAXON_ATTRIBUTE(void, REDCOMPONENT_ENUM_RED, "red");
				MAXON_ATTRIBUTE(void, REDCOMPONENT_ENUM_GREEN, "green");
				MAXON_ATTRIBUTE(void, REDCOMPONENT_ENUM_BLUE, "blue");
				MAXON_ATTRIBUTE(void, REDCOMPONENT_ENUM_ALPHA, "alpha");
				MAXON_ATTRIBUTE(void, REDCOMPONENT_ENUM_ZERO, "zero");
				MAXON_ATTRIBUTE(void, REDCOMPONENT_ENUM_ONE, "one");

				MAXON_ATTRIBUTE(InternedId, GREENCOMPONENT, "greencomponent");
				MAXON_ATTRIBUTE(void, GREENCOMPONENT_ENUM_RED, "red");
				MAXON_ATTRIBUTE(void, GREENCOMPONENT_ENUM_GREEN, "green");
				MAXON_ATTRIBUTE(void, GREENCOMPONENT_ENUM_BLUE, "blue");
				MAXON_ATTRIBUTE(void, GREENCOMPONENT_ENUM_ALPHA, "alpha");
				MAXON_ATTRIBUTE(void, GREENCOMPONENT_ENUM_ZERO, "zero");
				MAXON_ATTRIBUTE(void, GREENCOMPONENT_ENUM_ONE, "one");

				MAXON_ATTRIBUTE(InternedId, BLUECOMPONENT, "bluecomponent");
				MAXON_ATTRIBUTE(void, BLUECOMPONENT_ENUM_RED, "red");
				MAXON_ATTRIBUTE(void, BLUECOMPONENT_ENUM_GREEN, "green");
				MAXON_ATTRIBUTE(void, BLUECOMPONENT_ENUM_BLUE, "blue");
				MAXON_ATTRIBUTE(void, BLUECOMPONENT_ENUM_ALPHA, "alpha");
				MAXON_ATTRIBUTE(void, BLUECOMPONENT_ENUM_ZERO, "zero");
				MAXON_ATTRIBUTE(void, BLUECOMPONENT_ENUM_ONE, "one");

				MAXON_ATTRIBUTE(InternedId, ALPHACOMPONENT, "alphacomponent");
				MAXON_ATTRIBUTE(void, ALPHACOMPONENT_ENUM_RED, "red");
				MAXON_ATTRIBUTE(void, ALPHACOMPONENT_ENUM_GREEN, "green");
				MAXON_ATTRIBUTE(void, ALPHACOMPONENT_ENUM_BLUE, "blue");
				MAXON_ATTRIBUTE(void, ALPHACOMPONENT_ENUM_ALPHA, "alpha");
				MAXON_ATTRIBUTE(void, ALPHACOMPONENT_ENUM_ZERO, "zero");
				MAXON_ATTRIBUTE(void, ALPHACOMPONENT_ENUM_ONE, "one");

				MAXON_ATTRIBUTE(ColorA, RESULT, "result");
			}

			namespace SHUFFLECOMBINE
			{
				MAXON_RESOURCE_DATABASE_SCOPE("net.maxon.pattern.node.effect.shufflecombine");

				// supports MAXON::NODE::BASE::FILTERTAGS
				// supports MAXON::NODE::BASE::NODEPREVIEWIMAGE
				// supports MAXON::NODE::BASE::MATERIALPREVIEWIMAGE
				// supports MAXON::NODE::BASE::NAME
				// supports MAXON::NODE::BASE::ASSETVERSION
				// supports MAXON::NODE::BASE::COLOR
				// supports MAXON::NODE::BASE::PORTDISPLAY
				// supports MAXON::NODE::BASE::DISPLAYPREVIEW
				// supports MAXON::NODE::BASE::DISPLAYCOMMENT
				// supports MAXON::NODE::BASE::COMMENT
				// supports MAXON::NODE::BASE::CATEGORY
				// supports MAXON::NODE::BASE::ICON
				// supports MAXON::NODE::BASE::UPDATEPOLICY
				// supports MAXON::ASSET::BASE::PROTECTED

				MAXON_ATTRIBUTE(ColorA, COLOR1, "color1");

				MAXON_ATTRIBUTE(ColorA, COLOR2, "color2");

				MAXON_ATTRIBUTE(InternedId, REDCOMPONENT, "redcomponent");
				MAXON_ATTRIBUTE(void, REDCOMPONENT_ENUM_RED1, "red1");
				MAXON_ATTRIBUTE(void, REDCOMPONENT_ENUM_RED2, "red2");
				MAXON_ATTRIBUTE(void, REDCOMPONENT_ENUM_GREEN1, "green1");
				MAXON_ATTRIBUTE(void, REDCOMPONENT_ENUM_GREEN2, "green2");
				MAXON_ATTRIBUTE(void, REDCOMPONENT_ENUM_BLUE1, "blue1");
				MAXON_ATTRIBUTE(void, REDCOMPONENT_ENUM_BLUE2, "blue2");
				MAXON_ATTRIBUTE(void, REDCOMPONENT_ENUM_ALPHA1, "alpha1");
				MAXON_ATTRIBUTE(void, REDCOMPONENT_ENUM_ALPHA2, "alpha2");
				MAXON_ATTRIBUTE(void, REDCOMPONENT_ENUM_ZERO, "zero");
				MAXON_ATTRIBUTE(void, REDCOMPONENT_ENUM_ONE, "one");

				MAXON_ATTRIBUTE(InternedId, GREENCOMPONENT, "greencomponent");
				MAXON_ATTRIBUTE(void, GREENCOMPONENT_ENUM_RED1, "red1");
				MAXON_ATTRIBUTE(void, GREENCOMPONENT_ENUM_RED2, "red2");
				MAXON_ATTRIBUTE(void, GREENCOMPONENT_ENUM_GREEN1, "green1");
				MAXON_ATTRIBUTE(void, GREENCOMPONENT_ENUM_GREEN2, "green2");
				MAXON_ATTRIBUTE(void, GREENCOMPONENT_ENUM_BLUE1, "blue1");
				MAXON_ATTRIBUTE(void, GREENCOMPONENT_ENUM_BLUE2, "blue2");
				MAXON_ATTRIBUTE(void, GREENCOMPONENT_ENUM_ALPHA1, "alpha1");
				MAXON_ATTRIBUTE(void, GREENCOMPONENT_ENUM_ALPHA2, "alpha2");
				MAXON_ATTRIBUTE(void, GREENCOMPONENT_ENUM_ZERO, "zero");
				MAXON_ATTRIBUTE(void, GREENCOMPONENT_ENUM_ONE, "one");

				MAXON_ATTRIBUTE(InternedId, BLUECOMPONENT, "bluecomponent");
				MAXON_ATTRIBUTE(void, BLUECOMPONENT_ENUM_RED1, "red1");
				MAXON_ATTRIBUTE(void, BLUECOMPONENT_ENUM_RED2, "red2");
				MAXON_ATTRIBUTE(void, BLUECOMPONENT_ENUM_GREEN1, "green1");
				MAXON_ATTRIBUTE(void, BLUECOMPONENT_ENUM_GREEN2, "green2");
				MAXON_ATTRIBUTE(void, BLUECOMPONENT_ENUM_BLUE1, "blue1");
				MAXON_ATTRIBUTE(void, BLUECOMPONENT_ENUM_BLUE2, "blue2");
				MAXON_ATTRIBUTE(void, BLUECOMPONENT_ENUM_ALPHA1, "alpha1");
				MAXON_ATTRIBUTE(void, BLUECOMPONENT_ENUM_ALPHA2, "alpha2");
				MAXON_ATTRIBUTE(void, BLUECOMPONENT_ENUM_ZERO, "zero");
				MAXON_ATTRIBUTE(void, BLUECOMPONENT_ENUM_ONE, "one");

				MAXON_ATTRIBUTE(InternedId, ALPHACOMPONENT, "alphacomponent");
				MAXON_ATTRIBUTE(void, ALPHACOMPONENT_ENUM_RED1, "red1");
				MAXON_ATTRIBUTE(void, ALPHACOMPONENT_ENUM_RED2, "red2");
				MAXON_ATTRIBUTE(void, ALPHACOMPONENT_ENUM_GREEN1, "green1");
				MAXON_ATTRIBUTE(void, ALPHACOMPONENT_ENUM_GREEN2, "green2");
				MAXON_ATTRIBUTE(void, ALPHACOMPONENT_ENUM_BLUE1, "blue1");
				MAXON_ATTRIBUTE(void, ALPHACOMPONENT_ENUM_BLUE2, "blue2");
				MAXON_ATTRIBUTE(void, ALPHACOMPONENT_ENUM_ALPHA1, "alpha1");
				MAXON_ATTRIBUTE(void, ALPHACOMPONENT_ENUM_ALPHA2, "alpha2");
				MAXON_ATTRIBUTE(void, ALPHACOMPONENT_ENUM_ZERO, "zero");
				MAXON_ATTRIBUTE(void, ALPHACOMPONENT_ENUM_ONE, "one");

				MAXON_ATTRIBUTE(ColorA, RESULT, "result");
			}

			namespace UNPREMULTIPLY
			{
				MAXON_RESOURCE_DATABASE_SCOPE("net.maxon.pattern.node.effect.unpremultiply");

				// supports MAXON::NODE::BASE::FILTERTAGS
				// supports MAXON::NODE::BASE::NODEPREVIEWIMAGE
				// supports MAXON::NODE::BASE::MATERIALPREVIEWIMAGE
				// supports MAXON::NODE::BASE::NAME
				// supports MAXON::NODE::BASE::ASSETVERSION
				// supports MAXON::NODE::BASE::COLOR
				// supports MAXON::NODE::BASE::PORTDISPLAY
				// supports MAXON::NODE::BASE::DISPLAYPREVIEW
				// supports MAXON::NODE::BASE::DISPLAYCOMMENT
				// supports MAXON::NODE::BASE::COMMENT
				// supports MAXON::NODE::BASE::CATEGORY
				// supports MAXON::NODE::BASE::ICON
				// supports MAXON::NODE::BASE::UPDATEPOLICY
				// supports MAXON::ASSET::BASE::PROTECTED
				// supports MAXON::PATTERN::INCLUDE::COLORMASK::MASKBLEND
				// supports MAXON::PATTERN::INCLUDE::COLORMASK::MASKRED
				// supports MAXON::PATTERN::INCLUDE::COLORMASK::MASKGREEN
				// supports MAXON::PATTERN::INCLUDE::COLORMASK::MASKBLUE
				// supports MAXON::PATTERN::INCLUDE::COLORMASK::MASKALPHA

				MAXON_ATTRIBUTE(ColorA, COLOR, "color");

				MAXON_ATTRIBUTE(ColorA, RESULT, "result");
			}

			namespace WHITEBALANCE
			{
				MAXON_RESOURCE_DATABASE_SCOPE("net.maxon.pattern.node.effect.whitebalance");

				// supports MAXON::NODE::BASE::FILTERTAGS
				// supports MAXON::NODE::BASE::NODEPREVIEWIMAGE
				// supports MAXON::NODE::BASE::MATERIALPREVIEWIMAGE
				// supports MAXON::NODE::BASE::NAME
				// supports MAXON::NODE::BASE::ASSETVERSION
				// supports MAXON::NODE::BASE::COLOR
				// supports MAXON::NODE::BASE::PORTDISPLAY
				// supports MAXON::NODE::BASE::DISPLAYPREVIEW
				// supports MAXON::NODE::BASE::DISPLAYCOMMENT
				// supports MAXON::NODE::BASE::COMMENT
				// supports MAXON::NODE::BASE::CATEGORY
				// supports MAXON::NODE::BASE::ICON
				// supports MAXON::NODE::BASE::UPDATEPOLICY
				// supports MAXON::ASSET::BASE::PROTECTED

				MAXON_ATTRIBUTE(ColorA, COLOR, "color");

				MAXON_ATTRIBUTE(Color, WHITEPOINT, "whitepoint");

				MAXON_ATTRIBUTE(ColorA, RESULT, "result");

				// supports MAXON::PATTERN::INCLUDE::COLORMASK::MASKBLEND
				// supports MAXON::PATTERN::INCLUDE::COLORMASK::MASKRED
				// supports MAXON::PATTERN::INCLUDE::COLORMASK::MASKGREEN
				// supports MAXON::PATTERN::INCLUDE::COLORMASK::MASKBLUE
				// supports MAXON::PATTERN::INCLUDE::COLORMASK::MASKALPHA
			}
		}
	}
}
}
//----------------------------------------------------------------------------------------
// END - auto generated code, do not edit
//----------------------------------------------------------------------------------------

#include "nodes_color1.hxx"
	
#include "nodes_color2.hxx"

#endif // COLOR_NODES_H__
