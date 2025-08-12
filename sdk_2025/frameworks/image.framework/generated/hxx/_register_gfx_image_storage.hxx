#if 1
namespace maxon
{
/// @cond INTERNAL

/// @endcond

	const maxon::Char* const ImagePixelStorageInterface::MTable::_ids = 
		"Init@48447629d7aafd6c\0" // Result<void> Init(Int width, Int height, const PixelFormat& format, const Block<Pix>* defaultColor)
		"GetWidth@7d0e6f3d29c239e7\0" // Int GetWidth() const
		"GetHeight@7d0e6f3d29c239e7\0" // Int GetHeight() const
		"GetChannelCount@7d0e6f3d29c239e7\0" // Int GetChannelCount() const
		"GetPixelFormat@8b8260adda7d69d9\0" // PixelFormat GetPixelFormat() const
		"GetPixelHandler@b2b2a01ad6c4a265\0" // Result<GetPixelHandlerStruct> GetPixelHandler(const PixelFormat& dstFormat, const ChannelOffsets& channelOffsets, const ColorProfile& srcColorProfile, const ColorProfile& dstColorProfile, GETPIXELHANDLERFLAGS flags) const
		"SetPixelHandler@a1757be796be39fa\0" // Result<SetPixelHandlerStruct> SetPixelHandler(const PixelFormat& srcFormat, const ChannelOffsets& channelOffsets, const ColorProfile& srcColorProfile, const ColorProfile& dstColorProfile, SETPIXELHANDLERFLAGS flags, const Delegate<void(const UpdateRegion&)>& updateRegionNotification)
/// @cond INTERNAL

		"FreePixelHandler@940fb7680bc396b9\0" // void FreePixelHandler(GetPixelHandlerStruct& pixel) const
		"FreePixelHandler@571471fc6f7bdb0\0" // void FreePixelHandler(SetPixelHandlerStruct& pixel, const Delegate<void(const UpdateRegion&)>& updateRegionNotification) const
/// @endcond

		"GetComponent@3056c68bbd120ddf\0" // Result<void> GetComponent(Int component, const ImagePos& pos, Pix* data, Int inc, GETPIXELFLAGS flags) const
		"SetComponent@32ef25d2e51865d6\0" // Result<void> SetComponent(Int component, const ImagePos& pos, const Pix* data, Int inc, SETPIXELFLAGS flags)
	"";
	const maxon::METHOD_FLAGS ImagePixelStorageInterface::MTable::_flags[] = 
	{
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE,
/// @cond INTERNAL

		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE,
/// @endcond

		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE
	};
	PRIVATE_MAXON_INTERFACE_REGISTER_VIRTUAL_SINGLE_BASE(ImagePixelStorageInterface, , "net.maxon.image.interface.imagepixelstorage", (ObjectInterface::PrivateGetInterface()));
	template <typename DUMMY> maxon::Int ImagePixelStorageInterface::PrivateInstantiateDefaultValueHelper()
	{
		return 0
		| maxon::details::InstantiateDefaultReturnValue<PixelFormat>(OVERLOAD_MAX_RANK)
		;
	}
	MAXON_REGISTRY_REGISTER(ImagePixelStorageClasses);
	namespace ImagePixelStorageClasses
	{
		PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(NoData, , "net.maxon.image.imagepixelstorageclass.nodata");
		PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(Normal, , "net.maxon.image.imagepixelstorageclass.normal");
		PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(Planes, , "net.maxon.image.imagepixelstorageclass.planes");
		PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(Voxel, , "net.maxon.image.imagepixelstorageclass.voxel");
	}
}
#endif
static maxon::details::ForceEvaluation s_forceEval_gfx_image_storage(0
	| maxon::ImagePixelStorageInterface::PrivateInstantiateDefaultValueHelper<maxon::Int>()
);
