#if 1
namespace maxon
{
	namespace MEDIAINPUTPROPERTIES
	{
		SUPPORTS_IMAGE_PrivateAttribute SUPPORTS_IMAGE;
		SUPPORTS_VIDEO_PrivateAttribute SUPPORTS_VIDEO;
		SUPPORTS_AUDIO_PrivateAttribute SUPPORTS_AUDIO;
	}
	const maxon::Char* const MediaInputInterface::MTable::_ids = 
	"";
	const maxon::METHOD_FLAGS MediaInputInterface::MTable::_flags[] = 
	{
		maxon::METHOD_FLAGS::NONE
	};
	PRIVATE_MAXON_INTERFACE_REGISTER_VIRTUAL_SINGLE_BASE(MediaInputInterface, , "net.maxon.image.interface.mediainput", "maxon.MediaInputInterface", (MediaConverterInterface::PrivateGetInterface()));
}
#endif
