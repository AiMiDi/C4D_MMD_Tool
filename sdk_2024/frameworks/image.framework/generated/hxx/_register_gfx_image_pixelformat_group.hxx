#if 1
namespace maxon
{
	const maxon::Char* const PixelFormatGroupInterface::MTable::_ids = 
		"GetEntries@14b7555b25e63e3\0" // PixelFormatIterator GetEntries() const
	"";
	const maxon::METHOD_FLAGS PixelFormatGroupInterface::MTable::_flags[] = 
	{
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE
	};
	PRIVATE_MAXON_INTERFACE_REGISTER_VIRTUAL_SINGLE_BASE(PixelFormatGroupInterface, , "net.maxon.image.interface.pixelformatgroup", (ObjectInterface::PrivateGetInterface()));
	template <typename DUMMY> maxon::Int PixelFormatGroupInterface::PrivateInstantiateDefaultValueHelper()
	{
		return 0
		| maxon::details::InstantiateDefaultReturnValue<PixelFormatIterator>(OVERLOAD_MAX_RANK)
		;
	}
	MAXON_REGISTRY_REGISTER(PixelFormats);
	namespace PixelFormats
	{
		PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(RGBGroup, , "net.maxon.image.pixelformat.rgbgroup");
	}
}
#endif
static maxon::details::ForceEvaluation s_forceEval_gfx_image_pixelformat_group(0
	| maxon::PixelFormatGroupInterface::PrivateInstantiateDefaultValueHelper<maxon::Int>()
);
