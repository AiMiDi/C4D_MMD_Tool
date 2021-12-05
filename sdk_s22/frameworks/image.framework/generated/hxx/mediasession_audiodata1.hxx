#if 1
class MediaStreamAudioDataExportRef;

struct MediaStreamAudioDataExportInterface::HasBase { template <typename I> struct Check { static const maxon::Bool value = std::is_same<I, MediaStreamAudioDataExportInterface>::value || MediaStreamInterface::HasBase::template Check<I>::value; static I* Cast(MediaStreamAudioDataExportInterface* ptr) { return static_cast<I*>(static_cast<maxon::ObjectInterface*>(ptr)); } }; };
struct MediaStreamAudioDataExportInterface::Hxx1
{
	class Reference;
	using ReferenceClass = MediaStreamAudioDataExportRef;
	template <template <typename...> class TEMPL> using SubstituteBases = TEMPL<MediaStreamInterface>;
	/// Intermediate helper class for MediaStreamAudioDataExportInterface.
	template <typename S> class ConstReferenceFunctionsImpl DOXYGEN_SWITCH(: public S,)
	{
	public:
		ConstReferenceFunctionsImpl() = default;
		using PrivateBaseClass = S;
		using PrivateBaseClass::PrivateBaseClass;
/// Returns the object given at Init.
/// @return												OK on success.
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<AudioObjectRef>, AudioObjectRef>::type GetAudioObject() const;
	};
	/// Intermediate helper class for MediaStreamAudioDataExportInterface.
	template <typename S> class ReferenceFunctionsImpl : public ConstReferenceFunctionsImpl<S>
	{
	public:
		ReferenceFunctionsImpl() = default;
		using PrivateBaseClass = ConstReferenceFunctionsImpl<S>;
		using PrivateBaseClass::PrivateBaseClass;
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongRefHandler, MediaStreamAudioDataExportRef, true>::type&() const { return reinterpret_cast<const MediaStreamAudioDataExportRef&>(this->GetBaseRef()); }
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongRefHandler, MediaStreamAudioDataExportRef, false>::type&() { return reinterpret_cast<const MediaStreamAudioDataExportRef&>(this->GetBaseRef()); }
/// InitWithAudioData init with a given soundDataRef.
/// @param[in] audioData					Audio data to set.
/// @return												OK on success.
		inline Result<void> InitWithAudioData(const AudioObjectRef& audioData) const;
/// Subscribes to the stream.
/// @return												OK on success.
		inline Result<void> SetCallbackHandler() const;
/// called by the input media converter implementation before loading a stream.
/// @param[in] props							Properties of the image stream.
/// @return												OK on success.
		inline Result<void> InitStream(MediaStreamProperties& props) const;
/// called by the input media converter implementation when loading the stream is completed.
/// @param[in] props							Properties of the image stream.
/// @return												OK on success.
		inline Result<void> FinishStream(const MediaStreamProperties& props) const;
	};
	/// Intermediate helper class for MediaStreamAudioDataExportInterface.
	template <typename S> class COWReferenceFunctionsImpl : public ConstReferenceFunctionsImpl<S>
	{
	public:
		COWReferenceFunctionsImpl() = default;
		using PrivateBaseClass = ConstReferenceFunctionsImpl<S>;
		using PrivateBaseClass::PrivateBaseClass;
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, void, MediaStreamAudioDataExportRef, false>::type&() { return reinterpret_cast<const MediaStreamAudioDataExportRef&>(this->GetBaseRef()); }
/// InitWithAudioData init with a given soundDataRef.
/// @param[in] audioData					Audio data to set.
/// @return												OK on success.
		inline Result<void> InitWithAudioData(const AudioObjectRef& audioData);
/// Subscribes to the stream.
/// @return												OK on success.
		inline Result<void> SetCallbackHandler();
/// called by the input media converter implementation before loading a stream.
/// @param[in] props							Properties of the image stream.
/// @return												OK on success.
		inline Result<void> InitStream(MediaStreamProperties& props);
/// called by the input media converter implementation when loading the stream is completed.
/// @param[in] props							Properties of the image stream.
/// @return												OK on success.
		inline Result<void> FinishStream(const MediaStreamProperties& props);
	};
	template <typename ST> struct ReferenceFunctionsHelper : public std::conditional<maxon::Bool(ST::type::Handler::KIND & (maxon::VALUEKIND::COW_MASK | maxon::VALUEKIND::DEEP_CONSTNESS)), COWReferenceFunctionsImpl<typename MediaStreamInterface::Hxx1::template ReferenceFunctionsHelper<ST>::type>, typename std::conditional<std::is_const<typename ST::type::PrivateReferencedType>::value, ConstReferenceFunctionsImpl<typename MediaStreamInterface::Hxx1::template ReferenceFunctionsHelper<ST>::type>, ReferenceFunctionsImpl<typename MediaStreamInterface::Hxx1::template ReferenceFunctionsHelper<ST>::type>>::type> { };
};
class MediaStreamAudioDataExportInterface::Hxx1::Reference :
#ifdef DOXYGEN
public ReferenceFunctionsImplDoxy<MediaStreamAudioDataExportRef>
#else
public maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<MediaStreamAudioDataExportInterface, maxon::StrongRefHandler, MediaStreamAudioDataExportRef>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(Reference, maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<MediaStreamAudioDataExportInterface, maxon::StrongRefHandler, MediaStreamAudioDataExportRef>>>>);
	using NonConst = typename Super::ReferenceClass;
};

/// MediaStreamAudioDataExportRef is the reference class of MediaStreamAudioDataExportInterface.
///
/// Stream which represents sound data.
class MediaStreamAudioDataExportRef : public MediaStreamAudioDataExportInterface::Hxx1::Reference
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(MediaStreamAudioDataExportRef, typename MediaStreamAudioDataExportInterface::Hxx1::Reference);
	using ConstPtr = typename MediaStreamAudioDataExportInterface::ConstPtr;
};

#endif
