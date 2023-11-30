#if 1
namespace maxon
{
	const maxon::Char* const ColorSpaceInterface::MTable::_ids = 
		"GetDefaultNonlinearColorProfile@7d9b125a5b255027\0" // const ColorProfile& GetDefaultNonlinearColorProfile() const
		"GetDefaultLinearColorProfile@7d9b125a5b255027\0" // const ColorProfile& GetDefaultLinearColorProfile() const
	"";
	const maxon::METHOD_FLAGS ColorSpaceInterface::MTable::_flags[] = 
	{
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE
	};
	PRIVATE_MAXON_INTERFACE_REGISTER_VIRTUAL_SINGLE_BASE(ColorSpaceInterface, , "net.maxon.image.interface.colorspace", (ObjectInterface::PrivateGetInterface()));
	template <typename DUMMY> maxon::Int ColorSpaceInterface::PrivateInstantiateDefaultValueHelper()
	{
		return 0
		| maxon::details::InstantiateDefaultReturnValue<const ColorProfile&>(OVERLOAD_MAX_RANK)
		;
	}
}
#endif
static maxon::details::ForceEvaluation s_forceEval_gfx_image_colorspace(0
	| maxon::ColorSpaceInterface::PrivateInstantiateDefaultValueHelper<maxon::Int>()
);
