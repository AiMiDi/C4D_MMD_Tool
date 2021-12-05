#if 1
namespace maxon
{
	const maxon::Char* const AudioObjectInterface::MTable::_ids = 
		"Init@d6803f381ed0e6a4\0" // Result<void> Init(Int channelCount, Int bitsPerChannel, Float sampleRate, Int sampleCount, const TimeValue& length, const Block<const Char>& data)
		"GetChannelCount@7d0e6f3d29c239e7\0" // Int GetChannelCount() const
		"GetBitsPerChannel@7d0e6f3d29c239e7\0" // Int GetBitsPerChannel() const
		"GetSampleRate@e6d3186387d3ce58\0" // Float GetSampleRate() const
		"GetSampleCount@7d0e6f3d29c239e7\0" // Int GetSampleCount() const
		"GetLength@9a3c0bd9da107c0\0" // TimeValue GetLength() const
		"GetDataPtr@760f6b0f3d05169a\0" // Block<const Char> GetDataPtr() const
	"";
	PRIVATE_MAXON_INTERFACE_REGISTER_VIRTUAL_SINGLE_BASE(AudioObjectInterface, , "net.maxon.image.interface.audioobject", "maxon.AudioObjectInterface", (DataDictionaryObjectInterface::PrivateGetInterface()));
	template <typename DUMMY> maxon::Int AudioObjectInterface::PrivateInstantiateNullValueHelper()
	{
		return 0
		| maxon::details::InstantiateNullReturnValue<Block<const Char>>(OVERLOAD_MAX_RANK)
		| maxon::details::InstantiateNullReturnValue<TimeValue>(OVERLOAD_MAX_RANK)
		;
	}
	PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(AudioObjectClass, , "net.maxon.image.class.audioobject");
}
#endif
static maxon::details::ForceEvaluation s_forceEval_audioobject(0
	| maxon::AudioObjectInterface::PrivateInstantiateNullValueHelper<maxon::Int>()
);
