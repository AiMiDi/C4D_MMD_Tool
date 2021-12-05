#if 1
namespace maxon
{
	const maxon::Char* const AudioObjectInterface::MTable::_ids = 
		"Init@df32d31d8203b0f5\0" // Result<void> Init(Int channelCount, Int bitsPerChannel, Float sampleRate, Int sampleCount, const TimeValue& length, const Block<const Char>& data)
		"GetChannelCount@4386c86\0" // Int GetChannelCount() const
		"GetBitsPerChannel@4386c86\0" // Int GetBitsPerChannel() const
		"GetSampleRate@f358997b3\0" // Float GetSampleRate() const
		"GetSampleCount@4386c86\0" // Int GetSampleCount() const
		"GetLength@fecda69b2a99fb\0" // TimeValue GetLength() const
		"GetDataPtr@c0d4f1cbab9b3d33\0" // Block<const Char> GetDataPtr() const
	"";
	PRIVATE_MAXON_INTERFACE_REGISTER_VIRTUAL_SINGLE_BASE(AudioObjectInterface, , "net.maxon.image.interface.audioobject", "maxon.AudioObjectInterface", (&DataDictionaryObjectInterface::_interface));
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
