#if 1
namespace maxon
{
	const maxon::Char* const PixelFormatIndexedColorInterface::MTable::_ids = 
		"InitColorTable@2c7ae5e41eff96fb\0" // Result<void> InitColorTable(Int count, const PixelFormat& srcFormatPtr)
		"GetColorTablePixelFormat@90e8ba3989f75b34\0" // PixelFormat GetColorTablePixelFormat() const
		"GetColorTableSize@4386c86\0" // Int GetColorTableSize() const
		"SetIndex@d44b9c0b076b91ec\0" // Result<void> SetIndex(Int idx, const ImageConstBuffer& srcPixelData)
		"GetIndex@8e0e9d3b3011c6d1\0" // Result<void> GetIndex(Int idx, const ImageMutableBuffer& dstPixelData) const
	"";
	PRIVATE_MAXON_INTERFACE_REGISTER_VIRTUAL_SINGLE_BASE(PixelFormatIndexedColorInterface, , "net.maxon.image.interface.pixelformatindexedcolor", "maxon.PixelFormatIndexedColorInterface", (&PixelFormatInterface::_interface));
	template <typename DUMMY> maxon::Int PixelFormatIndexedColorInterface::PrivateInstantiateNullValueHelper()
	{
		return 0
		| maxon::details::InstantiateNullReturnValue<PixelFormat>(OVERLOAD_MAX_RANK)
		;
	}
}
#endif
static maxon::details::ForceEvaluation s_forceEval_gfx_image_pixelformat_indexed(0
	| maxon::PixelFormatIndexedColorInterface::PrivateInstantiateNullValueHelper<maxon::Int>()
);
