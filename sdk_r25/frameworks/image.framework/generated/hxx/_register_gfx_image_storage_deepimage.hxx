#if 1
namespace maxon
{
	const maxon::Char* const ImagePixelDeepImageStorageInterface::MTable::_ids = 
	"";
	const maxon::METHOD_FLAGS ImagePixelDeepImageStorageInterface::MTable::_flags[] = 
	{
		maxon::METHOD_FLAGS::NONE
	};
	PRIVATE_MAXON_INTERFACE_REGISTER_VIRTUAL_SINGLE_BASE(ImagePixelDeepImageStorageInterface, , "net.maxon.image.interface.imagepixeldeepimagestorage", "maxon.ImagePixelDeepImageStorageInterface", (ImagePixelStorageInterface::PrivateGetInterface()));
	namespace ImagePixelStorageClasses
	{
		PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(DeepImage, , "net.maxon.image.imagepixelstorageclass.deepimage");
	}
}
#endif
