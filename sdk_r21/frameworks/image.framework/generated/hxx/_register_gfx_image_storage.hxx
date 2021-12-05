#if 1
namespace maxon
{
/// @cond INTERNAL

/// @endcond

	const maxon::Char* const ImagePixelStorageInterface::MTable::_ids = 
		"Init@7f27d61cc2cf70eb\0" // Result<void> Init(Int width, Int height, const PixelFormat& format, const Block<Pix>* defaultColor)
		"GetWidth@4386c86\0" // Int GetWidth() const
		"GetHeight@4386c86\0" // Int GetHeight() const
		"GetChannelCount@4386c86\0" // Int GetChannelCount() const
		"GetPixelFormat@90e8ba3989f75b34\0" // PixelFormat GetPixelFormat() const
		"GetPixelHandler@9d9e59091753d2aa\0" // Result<GetPixelHandlerStruct> GetPixelHandler(const PixelFormat& dstFormat, const ChannelOffsets& channelOffsets, const ColorProfile& srcColorProfile, const ColorProfile& dstColorProfile, GETPIXELHANDLERFLAGS flags) const
		"SetPixelHandler@a255b82dead0e253\0" // Result<SetPixelHandlerStruct> SetPixelHandler(const PixelFormat& srcFormat, const ChannelOffsets& channelOffsets, const ColorProfile& srcColorProfile, const ColorProfile& dstColorProfile, SETPIXELHANDLERFLAGS flags, const Delegate<void(const UpdateRegion&)>& updateRegionNotification)
/// @cond INTERNAL

		"FreePixelHandler@ebc685a3edcb7bd4\0" // void FreePixelHandler(GetPixelHandlerStruct& pixel) const
		"FreePixelHandler@c92fe899e52f9169\0" // void FreePixelHandler(SetPixelHandlerStruct& pixel, const Delegate<void(const UpdateRegion&)>& updateRegionNotification) const
/// @endcond

		"GetComponent@b860f8ea3c0c8570\0" // Result<void> GetComponent(Int component, const ImagePos& pos, Pix* data, Int inc, GETPIXELFLAGS flags) const
		"SetComponent@52e00d08ba432ab3\0" // Result<void> SetComponent(Int component, const ImagePos& pos, const Pix* data, Int inc, SETPIXELFLAGS flags)
	"";
	PRIVATE_MAXON_INTERFACE_REGISTER_VIRTUAL_SINGLE_BASE(ImagePixelStorageInterface, , "net.maxon.image.interface.imagepixelstorage", "maxon.ImagePixelStorageInterface", (&ObjectInterface::_interface));
	template <typename DUMMY> maxon::Int ImagePixelStorageInterface::PrivateInstantiateNullValueHelper()
	{
		return 0
		| maxon::details::InstantiateNullReturnValue<PixelFormat>(OVERLOAD_MAX_RANK)
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
	| maxon::ImagePixelStorageInterface::PrivateInstantiateNullValueHelper<maxon::Int>()
);
