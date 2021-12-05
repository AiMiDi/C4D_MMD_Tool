#if 1
class AudioObjectRef;

struct AudioObjectInterface::HasBase { template <typename I> struct Check { static const maxon::Bool value = std::is_same<I, AudioObjectInterface>::value || DataDictionaryObjectInterface::HasBase::template Check<I>::value; static I* Cast(AudioObjectInterface* ptr) { return reinterpret_cast<I*>(ptr); } }; };
struct AudioObjectInterface::Hxx1
{
	class Reference;
	using ReferenceClass = AudioObjectRef;
	template <template <typename...> class TEMPL> using SubstituteBases = TEMPL<DataDictionaryObjectInterface>;
	/// Intermediate helper class for AudioObjectInterface.
	template <typename S> class ConstReferenceFunctionsImpl DOXYGEN_SWITCH(: public S,)
	{
	public:
		ConstReferenceFunctionsImpl() = default;
		using PrivateBaseClass = S;
		using PrivateBaseClass::PrivateBaseClass;
/// Return the number of channels.
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type GetChannelCount() const;
/// Return the number of bits per channel.
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type GetBitsPerChannel() const;
/// Return the sample rate in Hz.
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<Float>, Float>::type GetSampleRate() const;
/// Return the duration/length of the sound in samples.
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type GetSampleCount() const;
/// Return the length as BaseTime
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<TimeValue>, TimeValue>::type GetLength() const;
/// Read only data buffer access
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<Block<const Char>>, Block<const Char>>::type GetDataPtr() const;
	};
	/// Intermediate helper class for AudioObjectInterface.
	template <typename S> class ReferenceFunctionsImpl : public ConstReferenceFunctionsImpl<S>
	{
	public:
		ReferenceFunctionsImpl() = default;
		using PrivateBaseClass = ConstReferenceFunctionsImpl<S>;
		using PrivateBaseClass::PrivateBaseClass;
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongRefHandler, AudioObjectRef, true>::type&() const { return reinterpret_cast<const AudioObjectRef&>(this->GetBaseRef()); }
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongRefHandler, AudioObjectRef, false>::type&() { return reinterpret_cast<const AudioObjectRef&>(this->GetBaseRef()); }
/// Initializes the object with some sound data.
/// @param[in] channelCount				Number of sound channels to set.
/// @param[in] bitsPerChannel			Bits per channel (e.g. 16).
/// @param[in] sampleRate					Sample Rate.
/// @param[in] sampleCount				Number of Samples.
/// @param[in] length							Sound length in Time units.
/// @param[in] data								Block with the sound data.
/// @return												OK on success.
		inline Result<void> Init(Int channelCount, Int bitsPerChannel, Float sampleRate, Int sampleCount, const TimeValue& length, const Block<const Char>& data) const;
	};
	/// Intermediate helper class for AudioObjectInterface.
	template <typename S> class COWReferenceFunctionsImpl : public ConstReferenceFunctionsImpl<S>
	{
	public:
		COWReferenceFunctionsImpl() = default;
		using PrivateBaseClass = ConstReferenceFunctionsImpl<S>;
		using PrivateBaseClass::PrivateBaseClass;
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, void, AudioObjectRef, false>::type&() { return reinterpret_cast<const AudioObjectRef&>(this->GetBaseRef()); }
/// Initializes the object with some sound data.
/// @param[in] channelCount				Number of sound channels to set.
/// @param[in] bitsPerChannel			Bits per channel (e.g. 16).
/// @param[in] sampleRate					Sample Rate.
/// @param[in] sampleCount				Number of Samples.
/// @param[in] length							Sound length in Time units.
/// @param[in] data								Block with the sound data.
/// @return												OK on success.
		inline Result<void> Init(Int channelCount, Int bitsPerChannel, Float sampleRate, Int sampleCount, const TimeValue& length, const Block<const Char>& data);
	};
	template <typename ST> struct ReferenceFunctionsHelper : public std::conditional<maxon::Bool(ST::type::Handler::KIND & (maxon::VALUEKIND::COW_MASK | maxon::VALUEKIND::DEEP_CONSTNESS)), COWReferenceFunctionsImpl<typename DataDictionaryObjectInterface::Hxx1::template ReferenceFunctionsHelper<ST>::type>, typename std::conditional<std::is_const<typename ST::type::PrivateReferencedType>::value, ConstReferenceFunctionsImpl<typename DataDictionaryObjectInterface::Hxx1::template ReferenceFunctionsHelper<ST>::type>, ReferenceFunctionsImpl<typename DataDictionaryObjectInterface::Hxx1::template ReferenceFunctionsHelper<ST>::type>>::type> { };
};
class AudioObjectInterface::Hxx1::Reference :
#ifdef DOXYGEN
public ReferenceFunctionsImplDoxy<AudioObjectRef>
#else
public maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<AudioObjectInterface, maxon::StrongRefHandler, AudioObjectRef>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(Reference, maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<AudioObjectInterface, maxon::StrongRefHandler, AudioObjectRef>>>>);
	using NonConst = typename Super::ReferenceClass;
};

/// AudioObjectRef is the reference class of AudioObjectInterface.
class AudioObjectRef : public AudioObjectInterface::Hxx1::Reference
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(AudioObjectRef, typename AudioObjectInterface::Hxx1::Reference);
	using ConstPtr = typename AudioObjectInterface::ConstPtr;
};

#endif
