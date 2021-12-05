#if 1
namespace maxon
{
	const maxon::Char* const MediaStreamAudioDataExportInterface::MTable::_ids = 
		"InitWithAudioData@6efc070103a90dd3\0" // Result<void> InitWithAudioData(const AudioObjectRef& audioData)
		"GetAudioObject@85fb574ad2432eb5\0" // AudioObjectRef GetAudioObject() const
		"SetCallbackHandler@a54f4799cbe1a498\0" // Result<void> SetCallbackHandler()
		"InitStream@1b7d4cd9a8ac24e7\0" // Result<void> InitStream(MediaStreamProperties& props)
		"FinishStream@7d86195c0d162444\0" // Result<void> FinishStream(const MediaStreamProperties& props)
	"";
	PRIVATE_MAXON_INTERFACE_REGISTER_VIRTUAL_SINGLE_BASE(MediaStreamAudioDataExportInterface, , "net.maxon.image.interface.mediastreamaudiodataexport", "maxon.MediaStreamAudioDataExportInterface", (&MediaStreamInterface::_interface));
	template <typename DUMMY> maxon::Int MediaStreamAudioDataExportInterface::PrivateInstantiateNullValueHelper()
	{
		return 0
		| maxon::details::InstantiateNullReturnValue<AudioObjectRef>(OVERLOAD_MAX_RANK)
		;
	}
	PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(MediaStreamAudioDataExportClass, , "net.maxon.image.class.mediastreamaudiodataexport");
}
#endif
static maxon::details::ForceEvaluation s_forceEval_mediasession_audiodata(0
	| maxon::MediaStreamAudioDataExportInterface::PrivateInstantiateNullValueHelper<maxon::Int>()
);
