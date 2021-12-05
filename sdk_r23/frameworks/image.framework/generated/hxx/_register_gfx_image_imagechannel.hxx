#if 1
namespace maxon
{
	PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(DT_Pix16f,, "net.maxon.image.pix16f");
	const maxon::Char* const ImageChannelTypeInterface::MTable::_ids = 
		"GetDefaultFillValue@33297a27208f6958\0" // Pix8u GetDefaultFillValue() const
		"GetColorSpace@38fcf0c8f66c1007\0" // ColorSpace GetColorSpace() const
		"GetChannel@d02ffaa40b54e5df\0" // ImageChannel GetChannel(const DataType& pixelType) const
	"";
	PRIVATE_MAXON_INTERFACE_REGISTER_VIRTUAL_SINGLE_BASE(ImageChannelTypeInterface, , "net.maxon.image.interface.imagechanneltype", "maxon.ImageChannelTypeInterface", (ObjectInterface::PrivateGetInterface()));
	template <typename DUMMY> maxon::Int ImageChannelTypeInterface::PrivateInstantiateNullValueHelper()
	{
		return 0
		| maxon::details::InstantiateNullReturnValue<ColorSpace>(OVERLOAD_MAX_RANK)
		| maxon::details::InstantiateNullReturnValue<ImageChannel>(OVERLOAD_MAX_RANK)
		| maxon::details::InstantiateNullReturnValue<Pix8u>(OVERLOAD_MAX_RANK)
		;
	}
	const maxon::Char* const ImageChannelInterface::MTable::_ids = 
		"GetChannelBits@4f41d0db287c303c\0" // BITS GetChannelBits() const
		"GetChannelType@a654e4f8db54eff8\0" // ImageChannelType GetChannelType() const
		"GetDataType@a6c0b400f1ac4207\0" // const DataType& GetDataType() const
		"IsIdenticalComponent@7bb696e3e2743fb\0" // Bool IsIdenticalComponent(const void* a, const void* b, Int oneTolerance) const
	"";
	PRIVATE_MAXON_INTERFACE_REGISTER_VIRTUAL_SINGLE_BASE(ImageChannelInterface, , "net.maxon.image.interface.imagechannel", "maxon.ImageChannelInterface", (ObjectInterface::PrivateGetInterface()));
	template <typename DUMMY> maxon::Int ImageChannelInterface::PrivateInstantiateNullValueHelper()
	{
		return 0
		| maxon::details::InstantiateNullReturnValue<BITS>(OVERLOAD_MAX_RANK)
		| maxon::details::InstantiateNullReturnValue<ImageChannelType>(OVERLOAD_MAX_RANK)
		| maxon::details::InstantiateNullReturnValue<const DataType&>(OVERLOAD_MAX_RANK)
		;
	}
}
#endif
static maxon::details::ForceEvaluation s_forceEval_gfx_image_imagechannel(0
	| maxon::ImageChannelTypeInterface::PrivateInstantiateNullValueHelper<maxon::Int>()
	| maxon::ImageChannelInterface::PrivateInstantiateNullValueHelper<maxon::Int>()
);
