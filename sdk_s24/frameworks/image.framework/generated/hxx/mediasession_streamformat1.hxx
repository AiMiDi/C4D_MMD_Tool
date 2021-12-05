#if 1
class MediaStreamFormat;

struct MediaStreamFormatInterface::HasBaseDetector { template <typename I> struct Check { static const maxon::Bool value = std::is_same<I, MediaStreamFormatInterface>::value || DataDictionaryObjectInterface::HasBaseDetector::template Check<I>::value; static I* Cast(MediaStreamFormatInterface* ptr) { return reinterpret_cast<I*>(ptr); } }; };
struct MediaStreamFormatInterface::Hxx1
{
	class Reference;
	class NonConstRef;
	using ReferenceClass = MediaStreamFormat;
	template <template <typename...> class TEMPL> using SubstituteBases = TEMPL<DataDictionaryObjectInterface>;
	/// Intermediate helper class for MediaStreamFormatInterface.
	template <typename S> class COWReferenceFunctionsImpl : public S
	{
	public:
		COWReferenceFunctionsImpl() = default;
		using PrivateBaseClass = S;
		using PrivateBaseClass::PrivateBaseClass;
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongCOWRefHandler, MediaStreamFormat, false>::type&() const { return reinterpret_cast<const MediaStreamFormat&>(this->GetBaseRef()); }
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongCOWRefHandler, MediaStreamFormat, false>::type&() { return reinterpret_cast<const MediaStreamFormat&>(this->GetBaseRef()); }
	};
	template <typename ST> struct ReferenceFunctionsHelper : public std::conditional<
	maxon::Bool(ST::type::Handler::KIND & (maxon::VALUEKIND::COW_MASK | maxon::VALUEKIND::DEEP_CONSTNESS)),
	COWReferenceFunctionsImpl<typename DataDictionaryObjectInterface::Hxx1::template ReferenceFunctionsHelper<ST>::type>,
	typename DataDictionaryObjectInterface::Hxx1::template ReferenceFunctionsHelper<ST>::type
	> { };
};
class MediaStreamFormatInterface::Hxx1::Reference :
#ifdef DOXYGEN
public COWReferenceFunctionsImplDoxy<MediaStreamFormat>
#else
public maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<const MediaStreamFormatInterface, maxon::StrongCOWRefHandler, MediaStreamFormat>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(Reference, maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<const MediaStreamFormatInterface, maxon::StrongCOWRefHandler, MediaStreamFormat>>>>);
	using NonConst = Hxx1::NonConstRef;
};

class MediaStreamFormatInterface::Hxx1::NonConstRef :
#ifdef DOXYGEN
public ReferenceFunctionsImplDoxy<NonConstRef>
#else
public maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<MediaStreamFormatInterface, maxon::StrongRefHandler, NonConstRef>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(NonConstRef, maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<MediaStreamFormatInterface, maxon::StrongRefHandler, NonConstRef>>>>);
};

/// MediaStreamFormat is the reference class of MediaStreamFormatInterface.
///
/// Single Stream within a MediaConverterInterface.
class MediaStreamFormat : public MediaStreamFormatInterface::Hxx1::Reference
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(MediaStreamFormat, typename MediaStreamFormatInterface::Hxx1::Reference);
};

class MediaStreamProperties;

struct MediaStreamPropertiesInterface::HasBaseDetector { template <typename I> struct Check { static const maxon::Bool value = std::is_same<I, MediaStreamPropertiesInterface>::value || MediaStreamFormatInterface::HasBaseDetector::template Check<I>::value; static I* Cast(MediaStreamPropertiesInterface* ptr) { return reinterpret_cast<I*>(ptr); } }; };
struct MediaStreamPropertiesInterface::Hxx1
{
	class Reference;
	class NonConstRef;
	using ReferenceClass = MediaStreamProperties;
	template <template <typename...> class TEMPL> using SubstituteBases = TEMPL<MediaStreamFormatInterface>;
	/// Intermediate helper class for MediaStreamPropertiesInterface.
	template <typename S> class ReferenceFunctionsImpl : public S
	{
	public:
		ReferenceFunctionsImpl() = default;
		using PrivateBaseClass = S;
		using PrivateBaseClass::PrivateBaseClass;
		inline maxon::Result<DOXYGEN_SWITCH(maxon::RefMemberType<S const>, S)> Init(const MediaStreamFormat& withFormat) const;
		inline maxon::Result<DOXYGEN_SWITCH(maxon::RefMemberType<S const>, S)> Init(const MediaStreamRef& withStream) const;
	};
	/// Intermediate helper class for MediaStreamPropertiesInterface.
	template <typename S> class COWReferenceFunctionsImpl : public S
	{
	public:
		COWReferenceFunctionsImpl() = default;
		using PrivateBaseClass = S;
		using PrivateBaseClass::PrivateBaseClass;
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongCOWRefHandler, MediaStreamProperties, false>::type&() const { return reinterpret_cast<const MediaStreamProperties&>(this->GetBaseRef()); }
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongCOWRefHandler, MediaStreamProperties, false>::type&() { return reinterpret_cast<const MediaStreamProperties&>(this->GetBaseRef()); }
		inline maxon::Result<DOXYGEN_SWITCH(maxon::RefMemberType<S>, S)> Init(const MediaStreamFormat& withFormat);
		inline maxon::Result<DOXYGEN_SWITCH(maxon::RefMemberType<S>, S)> Init(const MediaStreamRef& withStream);
	};
	template <typename ST> struct ReferenceFunctionsHelper : public std::conditional<
	maxon::Bool(ST::type::Handler::KIND & (maxon::VALUEKIND::COW_MASK | maxon::VALUEKIND::DEEP_CONSTNESS)),
	COWReferenceFunctionsImpl<typename MediaStreamFormatInterface::Hxx1::template ReferenceFunctionsHelper<ST>::type>,
	typename std::conditional<std::is_const<typename ST::type::PrivateReferencedType>::value, typename MediaStreamFormatInterface::Hxx1::template ReferenceFunctionsHelper<ST>::type, ReferenceFunctionsImpl<typename MediaStreamFormatInterface::Hxx1::template ReferenceFunctionsHelper<ST>::type>>::type
	> { };
};
class MediaStreamPropertiesInterface::Hxx1::Reference :
#ifdef DOXYGEN
public COWReferenceFunctionsImplDoxy<MediaStreamProperties>
#else
public maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<const MediaStreamPropertiesInterface, maxon::StrongCOWRefHandler, MediaStreamProperties>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(Reference, maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<const MediaStreamPropertiesInterface, maxon::StrongCOWRefHandler, MediaStreamProperties>>>>);
	using NonConst = Hxx1::NonConstRef;
};

class MediaStreamPropertiesInterface::Hxx1::NonConstRef :
#ifdef DOXYGEN
public ReferenceFunctionsImplDoxy<NonConstRef>
#else
public maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<MediaStreamPropertiesInterface, maxon::StrongRefHandler, NonConstRef>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(NonConstRef, maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<MediaStreamPropertiesInterface, maxon::StrongRefHandler, NonConstRef>>>>);
};

/// MediaStreamProperties is the reference class of MediaStreamPropertiesInterface.
///
/// Single Stream within a MediaConverterInterface.
class MediaStreamProperties : public MediaStreamPropertiesInterface::Hxx1::Reference
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(MediaStreamProperties, typename MediaStreamPropertiesInterface::Hxx1::Reference);
};

#endif
