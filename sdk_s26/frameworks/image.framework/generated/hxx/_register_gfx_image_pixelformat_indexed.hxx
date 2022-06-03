#if 1
namespace maxon
{
	const maxon::Char* const PixelFormatIndexedColorInterface::MTable::_ids = 
		"InitColorTable@7ea0a83c8eed6884\0" // Result<void> InitColorTable(Int count, const PixelFormat& srcFormatPtr)
		"GetColorTablePixelFormat@8b8260adda7d69d9\0" // PixelFormat GetColorTablePixelFormat() const
		"GetColorTableSize@7d0e6f3d29c239e7\0" // Int GetColorTableSize() const
		"SetIndex@afc4e65417944e39\0" // Result<void> SetIndex(Int idx, const ImageConstBuffer& srcPixelData)
		"GetIndex@ffa34a36595df548\0" // Result<void> GetIndex(Int idx, const ImageMutableBuffer& dstPixelData) const
	"";
	const maxon::METHOD_FLAGS PixelFormatIndexedColorInterface::MTable::_flags[] = 
	{
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE
	};
	PRIVATE_MAXON_INTERFACE_REGISTER_VIRTUAL_SINGLE_BASE(PixelFormatIndexedColorInterface, , "net.maxon.image.interface.pixelformatindexedcolor", "maxon.PixelFormatIndexedColorInterface", (PixelFormatInterface::PrivateGetInterface()));
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
