#if 1
namespace maxon
{
	const maxon::Char* const MediaStreamFormatInterface::MTable::_ids = 
	"";
	PRIVATE_MAXON_INTERFACE_REGISTER_VIRTUAL_SINGLE_BASE(MediaStreamFormatInterface, , "net.maxon.image.interface.mediastreamformat", "maxon.MediaStreamFormatInterface", (&DataDictionaryObjectInterface::_interface));
	const maxon::Char* const MediaStreamPropertiesInterface::MTable::_ids = 
		"Init@6cb7ba814b263280\0" // Result<void> Init(const MediaStreamFormat& withFormat)
		"Init@a987c0c070c64c22\0" // Result<void> Init(const MediaStreamRef& withStream)
	"";
	PRIVATE_MAXON_INTERFACE_REGISTER_VIRTUAL_SINGLE_BASE(MediaStreamPropertiesInterface, , "net.maxon.image.interface.mediastreamproperties", "maxon.MediaStreamPropertiesInterface", (&MediaStreamFormatInterface::_interface));
	PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(MediaStreamFormatClass, , "net.maxon.image.class.mediastreamformat");
	PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(MediaStreamPropertiesClass, , "net.maxon.image.class.mediastreamproperties");
}
#endif
