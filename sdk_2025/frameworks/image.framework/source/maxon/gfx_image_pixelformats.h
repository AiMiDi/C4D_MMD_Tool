#ifndef GFX_IMAGE_PIXELFORMATS_H__
#define GFX_IMAGE_PIXELFORMATS_H__

#include "maxon/gfx_image_pixelformat.h"
#include "maxon/vector.h"
#include "maxon/vector4d.h"

namespace maxon
{

/// @addtogroup Graphics
/// @{

//----------------------------------------------------------------------------------------
/// Registry to register PixelFormats.
//----------------------------------------------------------------------------------------
namespace PixelFormats
{
	/// Registry to register RGB pixel formats.
	namespace RGB
	{
		MAXON_DECLARATION(PixelFormat, U8, "net.maxon.image.pixelformat.rgb.u8", MAXON_IMPLEMENTATION_MODULE("net.maxon.image"));				///< RGB pixel format using Pix8u.
		MAXON_DECLARATION(PixelFormat, U16, "net.maxon.image.pixelformat.rgb.u16", MAXON_IMPLEMENTATION_MODULE("net.maxon.image"));			///< RGB pixel format using Pix16u.
		MAXON_DECLARATION(PixelFormat, U32, "net.maxon.image.pixelformat.rgb.u32", MAXON_IMPLEMENTATION_MODULE("net.maxon.image"));			///< RGB pixel format using Pix32u.
		MAXON_DECLARATION(PixelFormat, S32, "net.maxon.image.pixelformat.rgb.s32", MAXON_IMPLEMENTATION_MODULE("net.maxon.image"));			///< RGB pixel format using Pix32s.
		MAXON_DECLARATION(PixelFormat, F16, "net.maxon.image.pixelformat.rgb.f16", MAXON_IMPLEMENTATION_MODULE("net.maxon.image"));			///< RGB pixel format using Pix16f.
		MAXON_DECLARATION(PixelFormat, F32, "net.maxon.image.pixelformat.rgb.f32", MAXON_IMPLEMENTATION_MODULE("net.maxon.image"));			///< RGB pixel format using Pix32f.
		MAXON_DECLARATION(PixelFormat, F64, "net.maxon.image.pixelformat.rgb.f64", MAXON_IMPLEMENTATION_MODULE("net.maxon.image"));			///< RGB pixel format using Pix64f.
		MAXON_DECLARATION(PixelFormat, U444, "net.maxon.image.pixelformat.rgb.u444", MAXON_IMPLEMENTATION_MODULE("net.maxon.image"));		///< RGB pixel format using 16 bits per pixel with 4 bits for each r, g and b. memory layout: XXXXrrrrggggbbbb.
		MAXON_DECLARATION(PixelFormat, U555, "net.maxon.image.pixelformat.rgb.u555", MAXON_IMPLEMENTATION_MODULE("net.maxon.image"));		///< RGB pixel format using 16 bits per pixel with 5 bits for each r, g and b. memory layout: Xrrrrrgggggbbbbb.
		MAXON_DECLARATION(PixelFormat, U565, "net.maxon.image.pixelformat.rgb.u565", MAXON_IMPLEMENTATION_MODULE("net.maxon.image"));		///< RGB pixel format using 16 bits per pixel with 5 bits for r, b and 6 bits for g. memory layout: rrrrrggggggbbbbb.
		MAXON_DECLARATION(PixelFormat, RGBE, "net.maxon.image.pixelformat.rgb.rgbe", MAXON_IMPLEMENTATION_MODULE("net.maxon.image"));		///< RGB pixel format using 32 bits per pixel with 8 bits for each r, g, b mantissa and a common 8 bit exponent.
	}

	MAXON_DECLARATION(PixelFormatGroup, RGBAGroup, "net.maxon.image.pixelformat.rgbagroup", MAXON_IMPLEMENTATION_MODULE("net.maxon.image"));
	MAXON_REGISTRY(PixelFormat, RGBA, "net.maxon.image.registry.rgba");
	/// Registry to register RGBA pixel formats.
	namespace RGBA
	{
		MAXON_DECLARATION(PixelFormat, U8, "net.maxon.image.pixelformat.rgba.u8", MAXON_IMPLEMENTATION_MODULE("net.maxon.image"));				///< RGBA pixel format using Pix8u.
		MAXON_DECLARATION(PixelFormat, U16, "net.maxon.image.pixelformat.rgba.u16", MAXON_IMPLEMENTATION_MODULE("net.maxon.image"));			///< RGBA pixel format using Pix16u.
		MAXON_DECLARATION(PixelFormat, U32, "net.maxon.image.pixelformat.rgba.u32", MAXON_IMPLEMENTATION_MODULE("net.maxon.image"));			///< RGBA pixel format using Pix32u.
		MAXON_DECLARATION(PixelFormat, S32, "net.maxon.image.pixelformat.rgba.s32", MAXON_IMPLEMENTATION_MODULE("net.maxon.image"));			///< RGBA pixel format using Pix32s.
		MAXON_DECLARATION(PixelFormat, F16, "net.maxon.image.pixelformat.rgba.f16", MAXON_IMPLEMENTATION_MODULE("net.maxon.image"));			///< RGBA pixel format using Pix16f.
		MAXON_DECLARATION(PixelFormat, F32, "net.maxon.image.pixelformat.rgba.f32", MAXON_IMPLEMENTATION_MODULE("net.maxon.image"));			///< RGBA pixel format using Pix32f.
		MAXON_DECLARATION(PixelFormat, F64, "net.maxon.image.pixelformat.rgba.f64", MAXON_IMPLEMENTATION_MODULE("net.maxon.image"));			///< RGBA pixel format using Pix64f.
	}

	MAXON_DECLARATION(PixelFormatGroup, ARGBGroup, "net.maxon.image.pixelformat.argbgroup", MAXON_IMPLEMENTATION_MODULE("net.maxon.image"));
	MAXON_REGISTRY(PixelFormat, ARGB, "net.maxon.image.registry.argb");
	/// Registry to register ARGB pixel formats.
	namespace ARGB
	{
		MAXON_DECLARATION(PixelFormat, U8, "net.maxon.image.pixelformat.argb.u8", MAXON_IMPLEMENTATION_MODULE("net.maxon.image"));				///< ARGB pixel format using Pix8u.
		MAXON_DECLARATION(PixelFormat, U16, "net.maxon.image.pixelformat.argb.u16", MAXON_IMPLEMENTATION_MODULE("net.maxon.image"));			///< ARGB pixel format using Pix16u.
		MAXON_DECLARATION(PixelFormat, F32, "net.maxon.image.pixelformat.argb.f32", MAXON_IMPLEMENTATION_MODULE("net.maxon.image"));			///< ARGB pixel format using Pix32f.
		MAXON_DECLARATION(PixelFormat, F64, "net.maxon.image.pixelformat.argb.f64", MAXON_IMPLEMENTATION_MODULE("net.maxon.image"));			///< ARGB pixel format using Pix64f.
		MAXON_DECLARATION(PixelFormat, U1555, "net.maxon.image.pixelformat.argb.u1555", MAXON_IMPLEMENTATION_MODULE("net.maxon.image"));	///< ARGB pixel format using 16 bits per pixel with 5 bits for each r, g and b plus the topmost single bit for the alpha. memory layout: arrrrrgggggbbbbb.
		MAXON_DECLARATION(PixelFormat, U4444, "net.maxon.image.pixelformat.argb.u4444", MAXON_IMPLEMENTATION_MODULE("net.maxon.image"));	///< ARGB pixel format using 16 bits per pixel with 4 bits for each r, g, b and alpha. memory layout: aaaarrrrggggbbbb.
	}

	MAXON_DECLARATION(PixelFormatGroup, RGBXGroup, "net.maxon.image.pixelformat.rgbxgroup", MAXON_IMPLEMENTATION_MODULE("net.maxon.image"));
	MAXON_REGISTRY(PixelFormat, RGBX, "net.maxon.image.registry.rgbx");
	/// Registry to register RGBX pixel formats. X is a unused component.
	namespace RGBX
	{
		MAXON_DECLARATION(PixelFormat, U8, "net.maxon.image.pixelformat.rgbx.u8", MAXON_IMPLEMENTATION_MODULE("net.maxon.image"));				///< RGBX pixel format using Pix8u. The x channel is unused.
	}

	MAXON_DECLARATION(PixelFormatGroup, XRGBGroup, "net.maxon.image.pixelformat.xrgbgroup", MAXON_IMPLEMENTATION_MODULE("net.maxon.image"));
	MAXON_REGISTRY(PixelFormat, XRGB, "net.maxon.image.registry.xrgb");
	/// Registry to register RGBX pixel formats. X is a unused component.
	namespace XRGB
	{
		MAXON_DECLARATION(PixelFormat, U8, "net.maxon.image.pixelformat.xrgb.u8", MAXON_IMPLEMENTATION_MODULE("net.maxon.image"));				///< XRGB pixel format using Pix8u. The x channel is unused.
}

	MAXON_DECLARATION(PixelFormatGroup, BGRGroup, "net.maxon.image.pixelformat.bgrgroup", MAXON_IMPLEMENTATION_MODULE("net.maxon.image"));
	MAXON_REGISTRY(PixelFormat, BGR, "net.maxon.image.registry.bgr");
	/// Registry to register BGR pixel formats.
	namespace BGR
	{
		MAXON_DECLARATION(PixelFormat, U8, "net.maxon.image.pixelformat.bgr.u8", MAXON_IMPLEMENTATION_MODULE("net.maxon.image"));				///< BGR pixel format using Pix8u.
		MAXON_DECLARATION(PixelFormat, U16, "net.maxon.image.pixelformat.bgr.u16", MAXON_IMPLEMENTATION_MODULE("net.maxon.image"));			///< BGR pixel format using Pix16u.
		MAXON_DECLARATION(PixelFormat, F32, "net.maxon.image.pixelformat.bgr.f32", MAXON_IMPLEMENTATION_MODULE("net.maxon.image"));			///< BGR pixel format using Pix32f.
		MAXON_DECLARATION(PixelFormat, U444, "net.maxon.image.pixelformat.bgr.u444", MAXON_IMPLEMENTATION_MODULE("net.maxon.image"));		///< BGR pixel format using 16 bits per pixel with 4 bits for each r, g and b. memory layout: XXXXbbbbggggrrrr.
		MAXON_DECLARATION(PixelFormat, U555, "net.maxon.image.pixelformat.bgr.u555", MAXON_IMPLEMENTATION_MODULE("net.maxon.image"));		///< BGR pixel format using 16 bits per pixel with 5 bits for each r, g and b. memory layout: Xbbbbbgggggrrrrr.
		MAXON_DECLARATION(PixelFormat, U565, "net.maxon.image.pixelformat.bgr.u565", MAXON_IMPLEMENTATION_MODULE("net.maxon.image"));		///< BGR pixel format using 16 bits per pixel with 5 bits for r, b and 6 bits for g. memory layout: bbbbbggggggrrrrr.
	}

	MAXON_DECLARATION(PixelFormatGroup, BGRAGroup, "net.maxon.image.pixelformat.bgragroup", MAXON_IMPLEMENTATION_MODULE("net.maxon.image"));
	MAXON_REGISTRY(PixelFormat, BGRA, "net.maxon.image.registry.bgra");
	/// Registry to register BGRA pixel formats.
	namespace BGRA
	{
		MAXON_DECLARATION(PixelFormat, U8, "net.maxon.image.pixelformat.bgra.u8", MAXON_IMPLEMENTATION_MODULE("net.maxon.image"));				///< BGRA pixel format using Pix8u.
		MAXON_DECLARATION(PixelFormat, U16, "net.maxon.image.pixelformat.bgra.u16", MAXON_IMPLEMENTATION_MODULE("net.maxon.image"));			///< BGRA pixel format using Pix16u.
		MAXON_DECLARATION(PixelFormat, F16, "net.maxon.image.pixelformat.bgra.f16", MAXON_IMPLEMENTATION_MODULE("net.maxon.image"));			///< BGRA pixel format using Pix16f.
		MAXON_DECLARATION(PixelFormat, F32, "net.maxon.image.pixelformat.bgra.f32", MAXON_IMPLEMENTATION_MODULE("net.maxon.image"));			///< BGRA pixel format using Pix32f.
	}

	MAXON_DECLARATION(PixelFormatGroup, ABGRGroup, "net.maxon.image.pixelformat.abgrgroup", MAXON_IMPLEMENTATION_MODULE("net.maxon.image"));
	MAXON_REGISTRY(PixelFormat, ABGR, "net.maxon.image.registry.abgr");
	/// Registry to register ABGR pixel formats.
	namespace ABGR
	{
		MAXON_DECLARATION(PixelFormat, U8, "net.maxon.image.pixelformat.abgr.u8", MAXON_IMPLEMENTATION_MODULE("net.maxon.image"));				///< ABGR pixel format using Pix8u.
		MAXON_DECLARATION(PixelFormat, U1555, "net.maxon.image.pixelformat.abgr.u1555", MAXON_IMPLEMENTATION_MODULE("net.maxon.image"));	///< ABGR pixel format using 16 bits per pixel with 5 bits for each r, g and b plus the topmost single bit for the alpha. memory layout: Abbbbbgggggrrrrr.
		MAXON_DECLARATION(PixelFormat, U4444, "net.maxon.image.pixelformat.abgr.u4444", MAXON_IMPLEMENTATION_MODULE("net.maxon.image"));	///< ABGR pixel format using 16 bits per pixel with 4 bits for each r, g, b and alpha. memory layout: aaaabbbbggggrrrr.
		MAXON_DECLARATION(PixelFormat, F32, "net.maxon.image.pixelformat.abgr.f32", MAXON_IMPLEMENTATION_MODULE("net.maxon.image"));			///< ABGR pixel format using Pix32f.
	}

	MAXON_DECLARATION(PixelFormatGroup, BGRXGroup, "net.maxon.image.pixelformat.bgrxgroup", MAXON_IMPLEMENTATION_MODULE("net.maxon.image"));
	MAXON_REGISTRY(PixelFormat, BGRX, "net.maxon.image.registry.bgrx");
	/// Registry to register BGRX pixel formats. X is a unused component.
	namespace BGRX
	{
		MAXON_DECLARATION(PixelFormat, U8, "net.maxon.image.pixelformat.bgrx.u8", MAXON_IMPLEMENTATION_MODULE("net.maxon.image"));				///< BGRX pixel format using Pix8u.
	}

	MAXON_DECLARATION(PixelFormatGroup, ALPHAGroup, "net.maxon.image.pixelformat.alphagroup", MAXON_IMPLEMENTATION_MODULE("net.maxon.image"));
	MAXON_REGISTRY(PixelFormat, ALPHA, "net.maxon.image.registry.alpha");
	/// Registry to register ALPHA pixel formats.
	namespace ALPHA
	{
		MAXON_DECLARATION(PixelFormat, U8, "net.maxon.image.pixelformat.alpha.u8", MAXON_IMPLEMENTATION_MODULE("net.maxon.image"));				///< ALPHA pixel format using Pix8u.
		MAXON_DECLARATION(PixelFormat, U16, "net.maxon.image.pixelformat.alpha.u16", MAXON_IMPLEMENTATION_MODULE("net.maxon.image"));			///< ALPHA pixel format using Pix16u.
		MAXON_DECLARATION(PixelFormat, F16, "net.maxon.image.pixelformat.alpha.f16", MAXON_IMPLEMENTATION_MODULE("net.maxon.image"));			///< ALPHA pixel format using Pix16f.
		MAXON_DECLARATION(PixelFormat, F32, "net.maxon.image.pixelformat.alpha.f32", MAXON_IMPLEMENTATION_MODULE("net.maxon.image"));			///< ALPHA pixel format using Pix32f.
		MAXON_DECLARATION(PixelFormat, F64, "net.maxon.image.pixelformat.alpha.f64", MAXON_IMPLEMENTATION_MODULE("net.maxon.image"));			///< ALPHA pixel format using Pix64f.
	}

	MAXON_DECLARATION(PixelFormatGroup, GREYGroup, "net.maxon.image.pixelformat.greygroup", MAXON_IMPLEMENTATION_MODULE("net.maxon.image"));
	MAXON_REGISTRY(PixelFormat, GREY, "net.maxon.image.registry.grey");
	/// Registry to register grey scale pixel formats.
	namespace GREY
	{
		MAXON_DECLARATION(PixelFormat, U8, "net.maxon.image.pixelformat.grey.u8", MAXON_IMPLEMENTATION_MODULE("net.maxon.image"));				///< GREY pixel format using Pix8u.
		MAXON_DECLARATION(PixelFormat, U16, "net.maxon.image.pixelformat.grey.u16", MAXON_IMPLEMENTATION_MODULE("net.maxon.image"));			///< GREY pixel format using Pix16u.
		MAXON_DECLARATION(PixelFormat, F16, "net.maxon.image.pixelformat.grey.f16", MAXON_IMPLEMENTATION_MODULE("net.maxon.image"));			///< GREY pixel format using Pix16f.
		MAXON_DECLARATION(PixelFormat, F32, "net.maxon.image.pixelformat.grey.f32", MAXON_IMPLEMENTATION_MODULE("net.maxon.image"));			///< GREY pixel format using Pix32f.
		MAXON_DECLARATION(PixelFormat, F64, "net.maxon.image.pixelformat.grey.f64", MAXON_IMPLEMENTATION_MODULE("net.maxon.image"));			///< GREY pixel format using Pix64f.
	}

	MAXON_DECLARATION(PixelFormatGroup, AGREYGroup, "net.maxon.image.pixelformat.agreygroup", MAXON_IMPLEMENTATION_MODULE("net.maxon.image"));
	MAXON_REGISTRY(PixelFormat, AGREY, "net.maxon.image.registry.agrey");
	/// Registry to register alpha + grey scale pixel formats.
	namespace AGREY
	{
		MAXON_DECLARATION(PixelFormat, U8, "net.maxon.image.pixelformat.agrey.u8", MAXON_IMPLEMENTATION_MODULE("net.maxon.image"));			///< AGREY pixel format using Pix8u.
		MAXON_DECLARATION(PixelFormat, U16, "net.maxon.image.pixelformat.agrey.u16", MAXON_IMPLEMENTATION_MODULE("net.maxon.image"));		///< AGREY pixel format using Pix16u.
		MAXON_DECLARATION(PixelFormat, F16, "net.maxon.image.pixelformat.agrey.f16", MAXON_IMPLEMENTATION_MODULE("net.maxon.image"));		///< AGREY pixel format using Pix16f.
		MAXON_DECLARATION(PixelFormat, F32, "net.maxon.image.pixelformat.agrey.f32", MAXON_IMPLEMENTATION_MODULE("net.maxon.image"));		///< AGREY pixel format using Pix32f.
		MAXON_DECLARATION(PixelFormat, F64, "net.maxon.image.pixelformat.agrey.f64", MAXON_IMPLEMENTATION_MODULE("net.maxon.image"));		///< AGREY pixel format using Pix64f.
	}

	MAXON_DECLARATION(PixelFormatGroup, GREYAGroup, "net.maxon.image.pixelformat.greyagroup", MAXON_IMPLEMENTATION_MODULE("net.maxon.image"));
	MAXON_REGISTRY(PixelFormat, GREYA, "net.maxon.image.registry.greya");
	/// Registry to register grey scale + alpha pixel formats.
	namespace GREYA
	{
		MAXON_DECLARATION(PixelFormat, U8, "net.maxon.image.pixelformat.greya.u8", MAXON_IMPLEMENTATION_MODULE("net.maxon.image"));			///< GREYA pixel format using Pix8u.
		MAXON_DECLARATION(PixelFormat, U16, "net.maxon.image.pixelformat.greya.u16", MAXON_IMPLEMENTATION_MODULE("net.maxon.image"));		///< GREYA pixel format using Pix16u.
		MAXON_DECLARATION(PixelFormat, F16, "net.maxon.image.pixelformat.greya.f16", MAXON_IMPLEMENTATION_MODULE("net.maxon.image"));		///< GREYA pixel format using Pix16f.
		MAXON_DECLARATION(PixelFormat, F32, "net.maxon.image.pixelformat.greya.f32", MAXON_IMPLEMENTATION_MODULE("net.maxon.image"));		///< GREYA pixel format using Pix32f.
		MAXON_DECLARATION(PixelFormat, F64, "net.maxon.image.pixelformat.greya.f64", MAXON_IMPLEMENTATION_MODULE("net.maxon.image"));		///< GREYA pixel format using Pix64f.
	}

	MAXON_DECLARATION(PixelFormatGroup, CMYKGroup, "net.maxon.image.pixelformat.cmykgroup", MAXON_IMPLEMENTATION_MODULE("net.maxon.image"));
	MAXON_REGISTRY(PixelFormat, CMYK, "net.maxon.image.registry.cmyk");
	/// Registry to register cmyk pixel formats.
	namespace CMYK
	{
		MAXON_DECLARATION(PixelFormat, U8, "net.maxon.image.pixelformat.cmyk.u8", MAXON_IMPLEMENTATION_MODULE("net.maxon.image"));				///< CMYK pixel format using Pix8u.
		MAXON_DECLARATION(PixelFormat, U16, "net.maxon.image.pixelformat.cmyk.u16", MAXON_IMPLEMENTATION_MODULE("net.maxon.image"));			///< CMYK pixel format using Pix16u.
		MAXON_DECLARATION(PixelFormat, F32, "net.maxon.image.pixelformat.cmyk.f32", MAXON_IMPLEMENTATION_MODULE("net.maxon.image"));			///< CMYK pixel format using Pix32f.
	}

	MAXON_DECLARATION(PixelFormatGroup, ACMYKGroup, "net.maxon.image.pixelformat.acmykgroup", MAXON_IMPLEMENTATION_MODULE("net.maxon.image"));
	MAXON_REGISTRY(PixelFormat, ACMYK, "net.maxon.image.registry.acmyk");
	/// Registry to register alpha + cmyk pixel formats.
	namespace ACMYK
	{
		MAXON_DECLARATION(PixelFormat, U8, "net.maxon.image.pixelformat.acmyk.u8", MAXON_IMPLEMENTATION_MODULE("net.maxon.image"));			///< ACMYK pixel format using Pix8u.
		MAXON_DECLARATION(PixelFormat, U16, "net.maxon.image.pixelformat.acmyk.u16", MAXON_IMPLEMENTATION_MODULE("net.maxon.image"));		///< ACMYK pixel format using Pix16u.
		MAXON_DECLARATION(PixelFormat, F32, "net.maxon.image.pixelformat.acmyk.f32", MAXON_IMPLEMENTATION_MODULE("net.maxon.image"));		///< ACMYK pixel format using Pix32f.
	}

	MAXON_DECLARATION(PixelFormatGroup, CMYK_INVGroup, "net.maxon.image.pixelformat.cmyk_invgroup", MAXON_IMPLEMENTATION_MODULE("net.maxon.image"));
	MAXON_REGISTRY(PixelFormat, CMYK_INV, "net.maxon.image.registry.cmyk_inv");
	/// Registry to register inverse cmyk pixel formats.
	namespace CMYK_INV
	{
		MAXON_DECLARATION(PixelFormat, U8, "net.maxon.image.pixelformat.cmyk_inv.u8", MAXON_IMPLEMENTATION_MODULE("net.maxon.image"));		///< CMYK pixel format using Pix8u. CMYK values are 1.0 - CMYK.
		MAXON_DECLARATION(PixelFormat, U16, "net.maxon.image.pixelformat.cmyk_inv.u16", MAXON_IMPLEMENTATION_MODULE("net.maxon.image"));	///< CMYK pixel format using Pix16u. CMYK values are 1.0 - CMYK.
		MAXON_DECLARATION(PixelFormat, F32, "net.maxon.image.pixelformat.cmyk_inv.f32", MAXON_IMPLEMENTATION_MODULE("net.maxon.image"));	///< CMYK pixel format using Pix32f. CMYK values are 1.0 - CMYK.
	}

	MAXON_DECLARATION(PixelFormatGroup, ACMYK_INVGroup, "net.maxon.image.pixelformat.acmyk_invgroup", MAXON_IMPLEMENTATION_MODULE("net.maxon.image"));
	MAXON_REGISTRY(PixelFormat, ACMYK_INV, "net.maxon.image.registry.acmyk_inv");
	/// Registry to register alpha + inverse cmyk pixel formats.
	namespace ACMYK_INV
	{
		MAXON_DECLARATION(PixelFormat, U8, "net.maxon.image.pixelformat.acmyk_inv.u8", MAXON_IMPLEMENTATION_MODULE("net.maxon.image"));		///< CMYK pixel format using Pix8u. CMYK values are 1.0 - CMYK.
		MAXON_DECLARATION(PixelFormat, U16, "net.maxon.image.pixelformat.acmyk_inv.u16", MAXON_IMPLEMENTATION_MODULE("net.maxon.image"));	///< CMYK pixel format using Pix8u. CMYK values are 1.0 - CMYK.
		MAXON_DECLARATION(PixelFormat, F32, "net.maxon.image.pixelformat.acmyk_inv.f32", MAXON_IMPLEMENTATION_MODULE("net.maxon.image"));	///< CMYK pixel format using Pix8u. CMYK values are 1.0 - CMYK.
	}

	MAXON_DECLARATION(PixelFormatGroup, YUVGroup, "net.maxon.image.pixelformat.yuvgroup", MAXON_IMPLEMENTATION_MODULE("net.maxon.image"));
	MAXON_REGISTRY(PixelFormat, YUV, "net.maxon.image.registry.yuv");
	/// Registry to register yuv pixel formats.
	namespace YUV
	{
		MAXON_DECLARATION(PixelFormat, I422A, "net.maxon.image.pixelformat.yuv.i422a", MAXON_IMPLEMENTATION_MODULE("net.maxon.image"));		///< YUV format in BT.601. Layout for 2 Pixels: Y0/U/Y1/V, MS calls it 'YUY2'.
		MAXON_DECLARATION(PixelFormat, I422B, "net.maxon.image.pixelformat.yuv.i422b", MAXON_IMPLEMENTATION_MODULE("net.maxon.image"));		///< YUV format in BT.601. Layout for 2 Pixels: U/Y0/V/Y1, MS calls it 'YVYU'.
	}

	MAXON_DECLARATION(PixelFormatGroup, IndexedGroup, "net.maxon.image.pixelformat.indexedgroup", MAXON_IMPLEMENTATION_MODULE("net.maxon.image"));
	MAXON_REGISTRY(PixelFormat, Indexed, "net.maxon.image.registry.indexed");
	/// Registry to register indexed color pixel formats.
	namespace Indexed
	{
		MAXON_DECLARATION(PixelFormat, u1bit, "net.maxon.image.pixelformat.indexed.u1bit", MAXON_IMPLEMENTATION_MODULE("net.maxon.image"));	///< Indexed color pixel format using 1 bit per pixel. See PixelFormatIndexedColor for details.
		MAXON_DECLARATION(PixelFormat, u2bit, "net.maxon.image.pixelformat.indexed.u2bit", MAXON_IMPLEMENTATION_MODULE("net.maxon.image"));	///< Indexed color pixel format using 2 bit per pixel. See PixelFormatIndexedColor for details.
		MAXON_DECLARATION(PixelFormat, u3bit, "net.maxon.image.pixelformat.indexed.u3bit", MAXON_IMPLEMENTATION_MODULE("net.maxon.image"));	///< Indexed color pixel format using 3 bit per pixel. See PixelFormatIndexedColor for details.
		MAXON_DECLARATION(PixelFormat, u4bit, "net.maxon.image.pixelformat.indexed.u4bit", MAXON_IMPLEMENTATION_MODULE("net.maxon.image"));	///< Indexed color pixel format using 4 bit per pixel. See PixelFormatIndexedColor for details.
		MAXON_DECLARATION(PixelFormat, u5bit, "net.maxon.image.pixelformat.indexed.u5bit", MAXON_IMPLEMENTATION_MODULE("net.maxon.image"));	///< Indexed color pixel format using 5 bit per pixel. See PixelFormatIndexedColor for details.
		MAXON_DECLARATION(PixelFormat, u6bit, "net.maxon.image.pixelformat.indexed.u6bit", MAXON_IMPLEMENTATION_MODULE("net.maxon.image"));	///< Indexed color pixel format using 6 bit per pixel. See PixelFormatIndexedColor for details.
		MAXON_DECLARATION(PixelFormat, u7bit, "net.maxon.image.pixelformat.indexed.u7bit", MAXON_IMPLEMENTATION_MODULE("net.maxon.image"));	///< Indexed color pixel format using 7 bit per pixel. See PixelFormatIndexedColor for details.
		MAXON_DECLARATION(PixelFormat, u8bit, "net.maxon.image.pixelformat.indexed.u8bit", MAXON_IMPLEMENTATION_MODULE("net.maxon.image"));	///< Indexed color pixel format using 8 bit per pixel. See PixelFormatIndexedColor for details.
		MAXON_DECLARATION(PixelFormat, u16bit, "net.maxon.image.pixelformat.indexed.u16bit", MAXON_IMPLEMENTATION_MODULE("net.maxon.image"));	///< Indexed color pixel format using 16 bit per pixel. See PixelFormatIndexedColor for details.
	}
}

//----------------------------------------------------------------------------------------
/// Use this macro to define a new pixel format, e.g.:
/// MAXON_REGISTER_PIXELFORMAT("rgb8i", PixelFormat::RGB::U8);
//----------------------------------------------------------------------------------------
#define MAXON_REGISTER_PIXELFORMAT(group, name, className) \
	MAXON_REGISTER_PIXELFORMAT_X(group, name, className)

#define MAXON_REGISTER_PIXELFORMAT_X(group, name, className) \
	MAXON_COMPONENT_CLASS_REGISTER(className, "net.maxon.image.class.pixelformat."#group"."#name); \
	MAXON_DECLARATION_REGISTER(PixelFormats::group::name) \
	{	\
		iferr (PixelFormat object = className::GetClass().Create()) return err;	\
		iferr (object.Init(PixelFormats::group##Group(), #group "::" #name)) return err;	\
		return object; \
	}

#define MAXON_REGISTER_PIXELFORMAT_TEMPLATE(group, name, className) \
	MAXON_REGISTER_PIXELFORMAT_TEMPLATE_X(group, name, className)

#define MAXON_REGISTER_PIXELFORMAT_TEMPLATE_X(group, name, className) \
	MAXON_COMPONENT_CLASS_REGISTER_TEMPLATE(className, "net.maxon.image.class.pixelformat." #group "." #name); \
	MAXON_DECLARATION_REGISTER(PixelFormats::group::name) \
	{	\
		iferr (PixelFormat object = className::GetClass().Create()) return err;	\
		iferr (object.Init(PixelFormats::group##Group(), #group"::"#name)) return err;	\
		return object; \
	}

//----------------------------------------------------------------------------------------
/// This macro allows to register a new pixel format group with a single line:
/// @code
/// REGISTER_PIXELFORMATGROUP(MyGroup);
/// @endcode
//----------------------------------------------------------------------------------------
#define REGISTER_PIXELFORMATGROUP(name) \
	class PixelFormatGroup##name##Impl : public Component<PixelFormatGroup##name##Impl, PixelFormatGroupInterface> \
	{ \
		MAXON_COMPONENT(); \
	public: \
		PixelFormatIterator GetEntries() const \
		{ \
			auto it = PixelFormats::name::GetEntries(); \
			return std::move(*(PixelFormatIterator*)&it); \
		} \
	}; \
	MAXON_COMPONENT_OBJECT_REGISTER(PixelFormatGroup##name##Impl, PixelFormats::name##Group)

//----------------------------------------------------------------------------------------
/// GetNativeFloatColorAlphaFormat returns the ColorA 32 or 64 PixelFormat depending on the system.
/// @return												PixelFormat on success.
//----------------------------------------------------------------------------------------
MAXON_ATTRIBUTE_FORCE_INLINE PixelFormat GetNativeFloatColorAlphaFormat()
{
	return sizeof(ColorA32) == sizeof(ColorA) ? PixelFormats::RGBA::F32() : PixelFormats::RGBA::F64();
}

//----------------------------------------------------------------------------------------
/// GetNativeFloatColorFormat returns the Color 32 or 64 PixelFormat depending on the system.
/// @return												PixelFormat on success.
//----------------------------------------------------------------------------------------
MAXON_ATTRIBUTE_FORCE_INLINE PixelFormat GetNativeFloatColorFormat()
{
	return sizeof(Color32) == sizeof(Color) ? PixelFormats::RGB::F32() : PixelFormats::RGB::F64();
}

/// @}

} // namespace maxon


#endif // GFX_IMAGE_PIXELFORMATS_H__
