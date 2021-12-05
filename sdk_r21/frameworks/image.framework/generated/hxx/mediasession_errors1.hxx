#if 1
class MediaSessionWrongTypeError;

struct MediaSessionWrongTypeErrorInterface::HasBase { template <typename I> struct Check { static const maxon::Bool value = std::is_same<I, MediaSessionWrongTypeErrorInterface>::value || ErrorInterface::HasBase::template Check<I>::value; static I* Cast(MediaSessionWrongTypeErrorInterface* ptr) { return static_cast<I*>(static_cast<maxon::ObjectInterface*>(ptr)); } }; };
struct MediaSessionWrongTypeErrorObjectPrivateHelper;
struct MediaSessionWrongTypeErrorInterface::Hxx1
{
	class Reference;
	class NonConstRef;
	using ErrObj = MediaSessionWrongTypeErrorObjectPrivateHelper;
	using ReferenceClass = MediaSessionWrongTypeError;
	template <template <typename...> class TEMPL> using SubstituteBases = TEMPL<ErrorInterface>;
	/// Intermediate helper class for MediaSessionWrongTypeErrorInterface.
	template <typename S> class ConstReferenceFunctionsImpl DOXYGEN_SWITCH(: public S,)
	{
	public:
		ConstReferenceFunctionsImpl() = default;
		using PrivateBaseClass = S;
		using PrivateBaseClass::PrivateBaseClass;
	};
	/// Intermediate helper class for MediaSessionWrongTypeErrorInterface.
	template <typename S> class ReferenceFunctionsImpl : public ConstReferenceFunctionsImpl<S>
	{
	public:
		ReferenceFunctionsImpl() = default;
		using PrivateBaseClass = ConstReferenceFunctionsImpl<S>;
		using PrivateBaseClass::PrivateBaseClass;
	};
	/// Intermediate helper class for MediaSessionWrongTypeErrorInterface.
	template <typename S> class COWReferenceFunctionsImpl : public ConstReferenceFunctionsImpl<S>
	{
	public:
		COWReferenceFunctionsImpl() = default;
		using PrivateBaseClass = ConstReferenceFunctionsImpl<S>;
		using PrivateBaseClass::PrivateBaseClass;
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongCOWRefHandler, MediaSessionWrongTypeError, false>::type&() const { return reinterpret_cast<const MediaSessionWrongTypeError&>(this->GetBaseRef()); }
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongCOWRefHandler, MediaSessionWrongTypeError, false>::type&() { return reinterpret_cast<const MediaSessionWrongTypeError&>(this->GetBaseRef()); }
	};
	template <typename ST> struct ReferenceFunctionsHelper : public std::conditional<maxon::Bool(ST::type::Handler::KIND & (maxon::VALUEKIND::COW_MASK | maxon::VALUEKIND::DEEP_CONSTNESS)), COWReferenceFunctionsImpl<typename ErrorInterface::Hxx1::template ReferenceFunctionsHelper<ST>::type>, typename std::conditional<std::is_const<typename ST::type::PrivateReferencedType>::value, ConstReferenceFunctionsImpl<typename ErrorInterface::Hxx1::template ReferenceFunctionsHelper<ST>::type>, ReferenceFunctionsImpl<typename ErrorInterface::Hxx1::template ReferenceFunctionsHelper<ST>::type>>::type> { };
};
class MediaSessionWrongTypeErrorInterface::Hxx1::Reference :
#ifdef DOXYGEN
public COWReferenceFunctionsImplDoxy<MediaSessionWrongTypeError>
#else
public maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<const MediaSessionWrongTypeErrorInterface, maxon::StrongCOWRefHandler, MediaSessionWrongTypeError>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(Reference, maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<const MediaSessionWrongTypeErrorInterface, maxon::StrongCOWRefHandler, MediaSessionWrongTypeError>>>>);
	using NonConst = Hxx1::NonConstRef;
};

class MediaSessionWrongTypeErrorInterface::Hxx1::NonConstRef :
#ifdef DOXYGEN
public ReferenceFunctionsImplDoxy<NonConstRef>
#else
public maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<MediaSessionWrongTypeErrorInterface, maxon::StrongRefHandler, NonConstRef>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(NonConstRef, maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<MediaSessionWrongTypeErrorInterface, maxon::StrongRefHandler, NonConstRef>>>>);
};

/// MediaSessionWrongTypeError is the reference class of MediaSessionWrongTypeErrorInterface.
///
/// Wrong image type error.
/// This error is returned if the file structure of an image is corrupted.
class MediaSessionWrongTypeError : public MediaSessionWrongTypeErrorInterface::Hxx1::Reference
{
public:
	friend class MediaSessionWrongTypeErrorObject;
	friend class maxon::ResultBase<MediaSessionWrongTypeError>;
	MediaSessionWrongTypeError(maxon::ERROR_OK) { }
	PRIVATE_MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(MediaSessionWrongTypeError, typename MediaSessionWrongTypeErrorInterface::Hxx1::Reference);
	template <typename D> MediaSessionWrongTypeError(const D& allocLocation, typename D::SourceLocationMarker* dummy = nullptr) { maxon::SFINAEHelper<MediaSessionWrongTypeError, D>::type::Create(MAXON_SOURCE_LOCATION_FORWARD); }
	template <typename ARG1, typename... ARGS> MediaSessionWrongTypeError(MAXON_SOURCE_LOCATION_DECLARATION, ARG1&& arg1, ARGS&&... args) { maxon::SFINAEHelper<MediaSessionWrongTypeError, ARG1>::type::Create(MAXON_SOURCE_LOCATION_FORWARD, std::forward<ARG1>(arg1), std::forward<ARGS>(args)...); }
private:
	MediaSessionWrongTypeError() = default;
};

MAXON_DECLARATION(MediaSessionWrongTypeError, MediaSessionWrongTypeErrorObject, "net.maxon.image.error.mediasessionwrongtype");
class MediaStreamEOFError;

struct MediaStreamEOFErrorInterface::HasBase { template <typename I> struct Check { static const maxon::Bool value = std::is_same<I, MediaStreamEOFErrorInterface>::value || ErrorInterface::HasBase::template Check<I>::value; static I* Cast(MediaStreamEOFErrorInterface* ptr) { return static_cast<I*>(static_cast<maxon::ObjectInterface*>(ptr)); } }; };
struct MediaStreamEOFErrorObjectPrivateHelper;
struct MediaStreamEOFErrorInterface::Hxx1
{
	class Reference;
	class NonConstRef;
	using ErrObj = MediaStreamEOFErrorObjectPrivateHelper;
	using ReferenceClass = MediaStreamEOFError;
	template <template <typename...> class TEMPL> using SubstituteBases = TEMPL<ErrorInterface>;
	/// Intermediate helper class for MediaStreamEOFErrorInterface.
	template <typename S> class ConstReferenceFunctionsImpl DOXYGEN_SWITCH(: public S,)
	{
	public:
		ConstReferenceFunctionsImpl() = default;
		using PrivateBaseClass = S;
		using PrivateBaseClass::PrivateBaseClass;
	};
	/// Intermediate helper class for MediaStreamEOFErrorInterface.
	template <typename S> class ReferenceFunctionsImpl : public ConstReferenceFunctionsImpl<S>
	{
	public:
		ReferenceFunctionsImpl() = default;
		using PrivateBaseClass = ConstReferenceFunctionsImpl<S>;
		using PrivateBaseClass::PrivateBaseClass;
	};
	/// Intermediate helper class for MediaStreamEOFErrorInterface.
	template <typename S> class COWReferenceFunctionsImpl : public ConstReferenceFunctionsImpl<S>
	{
	public:
		COWReferenceFunctionsImpl() = default;
		using PrivateBaseClass = ConstReferenceFunctionsImpl<S>;
		using PrivateBaseClass::PrivateBaseClass;
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongCOWRefHandler, MediaStreamEOFError, false>::type&() const { return reinterpret_cast<const MediaStreamEOFError&>(this->GetBaseRef()); }
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongCOWRefHandler, MediaStreamEOFError, false>::type&() { return reinterpret_cast<const MediaStreamEOFError&>(this->GetBaseRef()); }
	};
	template <typename ST> struct ReferenceFunctionsHelper : public std::conditional<maxon::Bool(ST::type::Handler::KIND & (maxon::VALUEKIND::COW_MASK | maxon::VALUEKIND::DEEP_CONSTNESS)), COWReferenceFunctionsImpl<typename ErrorInterface::Hxx1::template ReferenceFunctionsHelper<ST>::type>, typename std::conditional<std::is_const<typename ST::type::PrivateReferencedType>::value, ConstReferenceFunctionsImpl<typename ErrorInterface::Hxx1::template ReferenceFunctionsHelper<ST>::type>, ReferenceFunctionsImpl<typename ErrorInterface::Hxx1::template ReferenceFunctionsHelper<ST>::type>>::type> { };
};
class MediaStreamEOFErrorInterface::Hxx1::Reference :
#ifdef DOXYGEN
public COWReferenceFunctionsImplDoxy<MediaStreamEOFError>
#else
public maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<const MediaStreamEOFErrorInterface, maxon::StrongCOWRefHandler, MediaStreamEOFError>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(Reference, maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<const MediaStreamEOFErrorInterface, maxon::StrongCOWRefHandler, MediaStreamEOFError>>>>);
	using NonConst = Hxx1::NonConstRef;
};

class MediaStreamEOFErrorInterface::Hxx1::NonConstRef :
#ifdef DOXYGEN
public ReferenceFunctionsImplDoxy<NonConstRef>
#else
public maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<MediaStreamEOFErrorInterface, maxon::StrongRefHandler, NonConstRef>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(NonConstRef, maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<MediaStreamEOFErrorInterface, maxon::StrongRefHandler, NonConstRef>>>>);
};

/// MediaStreamEOFError is the reference class of MediaStreamEOFErrorInterface.
///
/// End of Media Stream is reached.
class MediaStreamEOFError : public MediaStreamEOFErrorInterface::Hxx1::Reference
{
public:
	friend class MediaStreamEOFErrorObject;
	friend class maxon::ResultBase<MediaStreamEOFError>;
	MediaStreamEOFError(maxon::ERROR_OK) { }
	PRIVATE_MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(MediaStreamEOFError, typename MediaStreamEOFErrorInterface::Hxx1::Reference);
	template <typename D> MediaStreamEOFError(const D& allocLocation, typename D::SourceLocationMarker* dummy = nullptr) { maxon::SFINAEHelper<MediaStreamEOFError, D>::type::Create(MAXON_SOURCE_LOCATION_FORWARD); }
	template <typename ARG1, typename... ARGS> MediaStreamEOFError(MAXON_SOURCE_LOCATION_DECLARATION, ARG1&& arg1, ARGS&&... args) { maxon::SFINAEHelper<MediaStreamEOFError, ARG1>::type::Create(MAXON_SOURCE_LOCATION_FORWARD, std::forward<ARG1>(arg1), std::forward<ARGS>(args)...); }
private:
	MediaStreamEOFError() = default;
};

MAXON_DECLARATION(MediaStreamEOFError, MediaStreamEOFErrorObject, "net.maxon.image.error.mediastreameof");
#endif
