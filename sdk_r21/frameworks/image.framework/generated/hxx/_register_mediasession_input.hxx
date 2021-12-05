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
	PRIVATE_MAXON_INTERFACE_REGISTER_VIRTUAL_SINGLE_BASE(MediaInputInterface, , "net.maxon.image.interface.mediainput", "maxon.MediaInputInterface", (&MediaConverterInterface::_interface));
}
#endif
