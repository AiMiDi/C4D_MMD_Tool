#if 1
namespace maxon
{
	const maxon::Char* const PixelFormatDynamicInterface::MTable::_ids = 
		"AddChannel@fd52110b31b8b847\0" // Result<Int> AddChannel(const ImageChannel& channel)
	"";
	PRIVATE_MAXON_INTERFACE_REGISTER_VIRTUAL_SINGLE_BASE(PixelFormatDynamicInterface, , "net.maxon.image.interface.pixelformatdynamic", "maxon.PixelFormatDynamicInterface", (PixelFormatInterface::PrivateGetInterface()));
	namespace PixelFormats
	{
		PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(DynamicGroup, , "net.maxon.image.pixelformat.dynamicgroup");
		MAXON_REGISTRY_REGISTER(Dynamic);
		namespace Dynamic
		{
			PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(RedU8, , "net.maxon.image.pixelformat.dynamic.redu8");
			PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(RedU16, , "net.maxon.image.pixelformat.dynamic.redu16");
			PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(RedU32, , "net.maxon.image.pixelformat.dynamic.redu32");
			PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(RedS8, , "net.maxon.image.pixelformat.dynamic.reds8");
			PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(RedS16, , "net.maxon.image.pixelformat.dynamic.reds16");
			PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(RedS32, , "net.maxon.image.pixelformat.dynamic.reds32");
			PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(RedF16, , "net.maxon.image.pixelformat.dynamic.redf16");
			PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(RedF32, , "net.maxon.image.pixelformat.dynamic.redf32");
			PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(RedGreenU8, , "net.maxon.image.pixelformat.dynamic.redgreenu8");
			PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(RedGreenU16, , "net.maxon.image.pixelformat.dynamic.redgreenu16");
			PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(RedGreenU32, , "net.maxon.image.pixelformat.dynamic.redgreenu32");
			PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(RedGreenS8, , "net.maxon.image.pixelformat.dynamic.redgreens8");
			PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(RedGreenS16, , "net.maxon.image.pixelformat.dynamic.redgreens16");
			PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(RedGreenS32, , "net.maxon.image.pixelformat.dynamic.redgreens32");
			PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(RedGreenF16, , "net.maxon.image.pixelformat.dynamic.redgreenf16");
			PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(RedGreenF32, , "net.maxon.image.pixelformat.dynamic.redgreenf32");
		}
	}
}
#endif
