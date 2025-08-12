#if 1
namespace maxon
{
	MAXON_REGISTRY_REGISTER(ColorSpaces);
	namespace ColorSpaces
	{
		PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(RGBspace, , "net.maxon.image.colorspace.rgb");
		PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(GREYspace, , "net.maxon.image.colorspace.grey");
		PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(CMYKspace, , "net.maxon.image.colorspace.cmyk");
		PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(YUVspace, , "net.maxon.image.colorspace.yuv");
		PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(ALPHAspace, , "net.maxon.image.colorspace.alpha");
	}
}
#endif
