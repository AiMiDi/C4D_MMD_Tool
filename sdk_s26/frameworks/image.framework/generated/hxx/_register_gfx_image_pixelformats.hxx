#if 1
namespace maxon
{
	namespace PixelFormats
	{
		namespace RGB
		{
			PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(U8, , "net.maxon.image.pixelformat.rgb.u8");
			PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(U16, , "net.maxon.image.pixelformat.rgb.u16");
			PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(U32, , "net.maxon.image.pixelformat.rgb.u32");
			PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(S32, , "net.maxon.image.pixelformat.rgb.s32");
			PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(F16, , "net.maxon.image.pixelformat.rgb.f16");
			PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(F32, , "net.maxon.image.pixelformat.rgb.f32");
			PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(F64, , "net.maxon.image.pixelformat.rgb.f64");
			PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(U444, , "net.maxon.image.pixelformat.rgb.u444");
			PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(U555, , "net.maxon.image.pixelformat.rgb.u555");
			PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(U565, , "net.maxon.image.pixelformat.rgb.u565");
			PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(RGBE, , "net.maxon.image.pixelformat.rgb.rgbe");
		}
		PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(RGBAGroup, , "net.maxon.image.pixelformat.rgbagroup");
		MAXON_REGISTRY_REGISTER(RGBA);
		namespace RGBA
		{
			PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(U8, , "net.maxon.image.pixelformat.rgba.u8");
			PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(U16, , "net.maxon.image.pixelformat.rgba.u16");
			PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(U32, , "net.maxon.image.pixelformat.rgba.u32");
			PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(S32, , "net.maxon.image.pixelformat.rgba.s32");
			PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(F16, , "net.maxon.image.pixelformat.rgba.f16");
			PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(F32, , "net.maxon.image.pixelformat.rgba.f32");
			PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(F64, , "net.maxon.image.pixelformat.rgba.f64");
		}
		PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(ARGBGroup, , "net.maxon.image.pixelformat.argbgroup");
		MAXON_REGISTRY_REGISTER(ARGB);
		namespace ARGB
		{
			PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(U8, , "net.maxon.image.pixelformat.argb.u8");
			PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(U16, , "net.maxon.image.pixelformat.argb.u16");
			PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(F32, , "net.maxon.image.pixelformat.argb.f32");
			PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(F64, , "net.maxon.image.pixelformat.argb.f64");
			PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(U1555, , "net.maxon.image.pixelformat.argb.u1555");
			PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(U4444, , "net.maxon.image.pixelformat.argb.u4444");
		}
		PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(RGBXGroup, , "net.maxon.image.pixelformat.rgbxgroup");
		MAXON_REGISTRY_REGISTER(RGBX);
		namespace RGBX
		{
			PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(U8, , "net.maxon.image.pixelformat.rgbx.u8");
		}
		PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(XRGBGroup, , "net.maxon.image.pixelformat.xrgbgroup");
		MAXON_REGISTRY_REGISTER(XRGB);
		namespace XRGB
		{
			PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(U8, , "net.maxon.image.pixelformat.xrgb.u8");
		}
		PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(BGRGroup, , "net.maxon.image.pixelformat.bgrgroup");
		MAXON_REGISTRY_REGISTER(BGR);
		namespace BGR
		{
			PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(U8, , "net.maxon.image.pixelformat.bgr.u8");
			PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(U16, , "net.maxon.image.pixelformat.bgr.u16");
			PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(F32, , "net.maxon.image.pixelformat.bgr.f32");
			PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(U444, , "net.maxon.image.pixelformat.bgr.u444");
			PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(U555, , "net.maxon.image.pixelformat.bgr.u555");
			PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(U565, , "net.maxon.image.pixelformat.bgr.u565");
		}
		PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(BGRAGroup, , "net.maxon.image.pixelformat.bgragroup");
		MAXON_REGISTRY_REGISTER(BGRA);
		namespace BGRA
		{
			PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(U8, , "net.maxon.image.pixelformat.bgra.u8");
			PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(U16, , "net.maxon.image.pixelformat.bgra.u16");
			PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(F16, , "net.maxon.image.pixelformat.bgra.f16");
			PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(F32, , "net.maxon.image.pixelformat.bgra.f32");
		}
		PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(ABGRGroup, , "net.maxon.image.pixelformat.abgrgroup");
		MAXON_REGISTRY_REGISTER(ABGR);
		namespace ABGR
		{
			PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(U8, , "net.maxon.image.pixelformat.abgr.u8");
			PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(U1555, , "net.maxon.image.pixelformat.abgr.u1555");
			PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(U4444, , "net.maxon.image.pixelformat.abgr.u4444");
		}
		PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(BGRXGroup, , "net.maxon.image.pixelformat.bgrxgroup");
		MAXON_REGISTRY_REGISTER(BGRX);
		namespace BGRX
		{
			PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(U8, , "net.maxon.image.pixelformat.bgrx.u8");
		}
		PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(ALPHAGroup, , "net.maxon.image.pixelformat.alphagroup");
		MAXON_REGISTRY_REGISTER(ALPHA);
		namespace ALPHA
		{
			PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(U8, , "net.maxon.image.pixelformat.alpha.u8");
			PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(U16, , "net.maxon.image.pixelformat.alpha.u16");
			PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(F16, , "net.maxon.image.pixelformat.alpha.f16");
			PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(F32, , "net.maxon.image.pixelformat.alpha.f32");
			PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(F64, , "net.maxon.image.pixelformat.alpha.f64");
		}
		PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(GREYGroup, , "net.maxon.image.pixelformat.greygroup");
		MAXON_REGISTRY_REGISTER(GREY);
		namespace GREY
		{
			PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(U8, , "net.maxon.image.pixelformat.grey.u8");
			PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(U16, , "net.maxon.image.pixelformat.grey.u16");
			PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(F16, , "net.maxon.image.pixelformat.grey.f16");
			PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(F32, , "net.maxon.image.pixelformat.grey.f32");
			PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(F64, , "net.maxon.image.pixelformat.grey.f64");
		}
		PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(AGREYGroup, , "net.maxon.image.pixelformat.agreygroup");
		MAXON_REGISTRY_REGISTER(AGREY);
		namespace AGREY
		{
			PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(U8, , "net.maxon.image.pixelformat.agrey.u8");
			PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(U16, , "net.maxon.image.pixelformat.agrey.u16");
			PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(F16, , "net.maxon.image.pixelformat.agrey.f16");
			PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(F32, , "net.maxon.image.pixelformat.agrey.f32");
			PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(F64, , "net.maxon.image.pixelformat.agrey.f64");
		}
		PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(GREYAGroup, , "net.maxon.image.pixelformat.greyagroup");
		MAXON_REGISTRY_REGISTER(GREYA);
		namespace GREYA
		{
			PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(U8, , "net.maxon.image.pixelformat.greya.u8");
			PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(U16, , "net.maxon.image.pixelformat.greya.u16");
			PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(F16, , "net.maxon.image.pixelformat.greya.f16");
			PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(F32, , "net.maxon.image.pixelformat.greya.f32");
			PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(F64, , "net.maxon.image.pixelformat.greya.f64");
		}
		PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(CMYKGroup, , "net.maxon.image.pixelformat.cmykgroup");
		MAXON_REGISTRY_REGISTER(CMYK);
		namespace CMYK
		{
			PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(U8, , "net.maxon.image.pixelformat.cmyk.u8");
			PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(U16, , "net.maxon.image.pixelformat.cmyk.u16");
			PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(F32, , "net.maxon.image.pixelformat.cmyk.f32");
		}
		PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(ACMYKGroup, , "net.maxon.image.pixelformat.acmykgroup");
		MAXON_REGISTRY_REGISTER(ACMYK);
		namespace ACMYK
		{
			PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(U8, , "net.maxon.image.pixelformat.acmyk.u8");
			PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(U16, , "net.maxon.image.pixelformat.acmyk.u16");
			PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(F32, , "net.maxon.image.pixelformat.acmyk.f32");
		}
		PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(CMYK_INVGroup, , "net.maxon.image.pixelformat.cmyk_invgroup");
		MAXON_REGISTRY_REGISTER(CMYK_INV);
		namespace CMYK_INV
		{
			PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(U8, , "net.maxon.image.pixelformat.cmyk_inv.u8");
			PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(U16, , "net.maxon.image.pixelformat.cmyk_inv.u16");
			PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(F32, , "net.maxon.image.pixelformat.cmyk_inv.f32");
		}
		PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(ACMYK_INVGroup, , "net.maxon.image.pixelformat.acmyk_invgroup");
		MAXON_REGISTRY_REGISTER(ACMYK_INV);
		namespace ACMYK_INV
		{
			PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(U8, , "net.maxon.image.pixelformat.acmyk_inv.u8");
			PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(U16, , "net.maxon.image.pixelformat.acmyk_inv.u16");
			PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(F32, , "net.maxon.image.pixelformat.acmyk_inv.f32");
		}
		PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(YUVGroup, , "net.maxon.image.pixelformat.yuvgroup");
		MAXON_REGISTRY_REGISTER(YUV);
		namespace YUV
		{
			PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(I422A, , "net.maxon.image.pixelformat.yuv.i422a");
			PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(I422B, , "net.maxon.image.pixelformat.yuv.i422b");
		}
		PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(IndexedGroup, , "net.maxon.image.pixelformat.indexedgroup");
		MAXON_REGISTRY_REGISTER(Indexed);
		namespace Indexed
		{
			PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(u1bit, , "net.maxon.image.pixelformat.indexed.u1bit");
			PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(u2bit, , "net.maxon.image.pixelformat.indexed.u2bit");
			PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(u3bit, , "net.maxon.image.pixelformat.indexed.u3bit");
			PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(u4bit, , "net.maxon.image.pixelformat.indexed.u4bit");
			PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(u5bit, , "net.maxon.image.pixelformat.indexed.u5bit");
			PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(u6bit, , "net.maxon.image.pixelformat.indexed.u6bit");
			PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(u7bit, , "net.maxon.image.pixelformat.indexed.u7bit");
			PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(u8bit, , "net.maxon.image.pixelformat.indexed.u8bit");
			PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(u16bit, , "net.maxon.image.pixelformat.indexed.u16bit");
		}
	}
}
#endif
