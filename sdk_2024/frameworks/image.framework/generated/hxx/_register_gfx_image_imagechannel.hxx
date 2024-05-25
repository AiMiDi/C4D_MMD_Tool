#if 1
namespace maxon
{
	const maxon::Char* const ImageChannelTypeInterface::MTable::_ids = 
		"GetDefaultFillValue@33297a27208f6958\0" // Pix8u GetDefaultFillValue() const
		"GetColorSpace@38fcf0c8f66c1007\0" // ColorSpace GetColorSpace() const
		"GetChannel@d02ffaa40b54e5df\0" // ImageChannel GetChannel(const DataType& pixelType) const
	"";
	const maxon::METHOD_FLAGS ImageChannelTypeInterface::MTable::_flags[] = 
	{
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE
	};
	PRIVATE_MAXON_INTERFACE_REGISTER_VIRTUAL_SINGLE_BASE(ImageChannelTypeInterface, , "net.maxon.image.interface.imagechanneltype", (ObjectInterface::PrivateGetInterface()));
	template <typename DUMMY> maxon::Int ImageChannelTypeInterface::PrivateInstantiateDefaultValueHelper()
	{
		return 0
		| maxon::details::InstantiateDefaultReturnValue<ColorSpace>(OVERLOAD_MAX_RANK)
		| maxon::details::InstantiateDefaultReturnValue<ImageChannel>(OVERLOAD_MAX_RANK)
		| maxon::details::InstantiateDefaultReturnValue<Pix8u>(OVERLOAD_MAX_RANK)
		;
	}
	const maxon::Char* const ImageChannelInterface::MTable::_ids = 
		"GetChannelBits@4f41d0db287c303c\0" // BITS GetChannelBits() const
		"GetChannelType@a654e4f8db54eff8\0" // ImageChannelType GetChannelType() const
		"GetDataType@a6c0b400f1ac4207\0" // const DataType& GetDataType() const
		"IsIdenticalComponent@7bb696e3e2743fb\0" // Bool IsIdenticalComponent(const void* a, const void* b, Int oneTolerance) const
	"";
	const maxon::METHOD_FLAGS ImageChannelInterface::MTable::_flags[] = 
	{
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE
	};
	PRIVATE_MAXON_INTERFACE_REGISTER_VIRTUAL_SINGLE_BASE(ImageChannelInterface, , "net.maxon.image.interface.imagechannel", (ObjectInterface::PrivateGetInterface()));
	template <typename DUMMY> maxon::Int ImageChannelInterface::PrivateInstantiateDefaultValueHelper()
	{
		return 0
		| maxon::details::InstantiateDefaultReturnValue<BITS>(OVERLOAD_MAX_RANK)
		| maxon::details::InstantiateDefaultReturnValue<ImageChannelType>(OVERLOAD_MAX_RANK)
		| maxon::details::InstantiateDefaultReturnValue<const DataType&>(OVERLOAD_MAX_RANK)
		;
	}
}
#endif
static maxon::details::ForceEvaluation s_forceEval_gfx_image_imagechannel(0
	| maxon::ImageChannelTypeInterface::PrivateInstantiateDefaultValueHelper<maxon::Int>()
	| maxon::ImageChannelInterface::PrivateInstantiateDefaultValueHelper<maxon::Int>()
);
