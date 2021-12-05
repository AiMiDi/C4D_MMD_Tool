#if 1
namespace maxon
{
	const maxon::Char* const VectorImageInterface::MTable::_ids = 
		"Init@1db4eca46d9225b9\0" // Result<void> Init(const Url& vectorIconUrl)
		"Init@d584185136fcfd0b\0" // Result<void> Init(const SVGDocument& vectorIcon)
		"GetVectorIcon@8aab0b37c428e054\0" // Result<ForwardRef<SVGDocument>> GetVectorIcon() const
	"";
	const maxon::METHOD_FLAGS VectorImageInterface::MTable::_flags[] = 
	{
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE
	};
	PRIVATE_MAXON_INTERFACE_REGISTER_VIRTUAL_SINGLE_BASE(VectorImageInterface, , "net.maxon.image.interface.vectorimage", "maxon.VectorImageInterface", (ImageBaseInterface::PrivateGetInterface()));
	MAXON_REGISTRY_REGISTER(VectorImageClasses);
	namespace VectorImageClasses
	{
		PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(BASE, , "net.maxon.image.vectorimageclass.base");
	}
}
#endif
