#if 1
namespace maxon
{
	PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(DT_Pix16f,, "net.maxon.image.pix16f");
	const maxon::Char* const ImageChannelTypeInterface::MTable::_ids = 
		"GetDefaultFillValue@1141d59273\0" // Pix8u GetDefaultFillValue() const
		"GetColorSpace@18edbd6218df033a\0" // ColorSpace GetColorSpace() const
		"GetChannel@68afc5e94b2cf2b0\0" // ImageChannel GetChannel(const DataType& pixelType) const
	"";
	PRIVATE_MAXON_INTERFACE_REGISTER_VIRTUAL_SINGLE_BASE(ImageChannelTypeInterface, , "net.maxon.image.interface.imagechanneltype", "maxon.ImageChannelTypeInterface", (&ObjectInterface::_interface));
	template <typename DUMMY> maxon::Int ImageChannelTypeInterface::PrivateInstantiateNullValueHelper()
	{
		return 0
		| maxon::details::InstantiateNullReturnValue<ColorSpace>(OVERLOAD_MAX_RANK)
		| maxon::details::InstantiateNullReturnValue<ImageChannel>(OVERLOAD_MAX_RANK)
		| maxon::details::InstantiateNullReturnValue<Pix8u>(OVERLOAD_MAX_RANK)
		;
	}
	const maxon::Char* const ImageChannelInterface::MTable::_ids = 
		"GetChannelBits@74cbf7fd\0" // BITS GetChannelBits() const
		"GetChannelType@bac5256ea93a9699\0" // ImageChannelType GetChannelType() const
		"GetDataType@f6200306f4b3253c\0" // const DataType& GetDataType() const
		"IsIdenticalComponent@a5efde88fa11c00a\0" // Bool IsIdenticalComponent(const void* a, const void* b, Int oneTolerance) const
	"";
	PRIVATE_MAXON_INTERFACE_REGISTER_VIRTUAL_SINGLE_BASE(ImageChannelInterface, , "net.maxon.image.interface.imagechannel", "maxon.ImageChannelInterface", (&ObjectInterface::_interface));
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
