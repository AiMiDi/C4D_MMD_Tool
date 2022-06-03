#if 1
namespace maxon
{
	const maxon::Char* const MediaStreamAudioDataExportInterface::MTable::_ids = 
		"InitWithAudioData@c545d488912d263c\0" // Result<void> InitWithAudioData(const AudioObjectRef& audioData)
		"GetAudioObject@f661e2c7402d03f2\0" // AudioObjectRef GetAudioObject() const
		"SetCallbackHandler@3008090429c5a175\0" // Result<void> SetCallbackHandler()
		"InitStream@7cfad6976c5d929c\0" // Result<void> InitStream(MediaStreamProperties& props)
		"FinishStream@d0b0f978b6e63019\0" // Result<void> FinishStream(const MediaStreamProperties& props)
	"";
	const maxon::METHOD_FLAGS MediaStreamAudioDataExportInterface::MTable::_flags[] = 
	{
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE
	};
	PRIVATE_MAXON_INTERFACE_REGISTER_VIRTUAL_SINGLE_BASE(MediaStreamAudioDataExportInterface, , "net.maxon.image.interface.mediastreamaudiodataexport", "maxon.MediaStreamAudioDataExportInterface", (MediaStreamInterface::PrivateGetInterface()));
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
