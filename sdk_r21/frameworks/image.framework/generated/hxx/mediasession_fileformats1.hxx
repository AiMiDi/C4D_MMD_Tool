#if 1
class MediaSessionFileFormatHandler;

struct MediaSessionFileFormatHandlerInterface::HasBase { template <typename I> struct Check { static const maxon::Bool value = std::is_same<I, MediaSessionFileFormatHandlerInterface>::value || FileFormatHandlerInterface::HasBase::template Check<I>::value; static I* Cast(MediaSessionFileFormatHandlerInterface* ptr) { return static_cast<I*>(static_cast<maxon::ObjectInterface*>(ptr)); } }; };
struct MediaSessionFileFormatHandlerInterface::Hxx1
{
	class Reference;
	class NonConstRef;
	using ReferenceClass = MediaSessionFileFormatHandler;
	template <template <typename...> class TEMPL> using SubstituteBases = TEMPL<FileFormatHandlerInterface>;
	/// Intermediate helper class for MediaSessionFileFormatHandlerInterface.
	template <typename S> class ConstReferenceFunctionsImpl DOXYGEN_SWITCH(: public S,)
	{
	public:
		ConstReferenceFunctionsImpl() = default;
		using PrivateBaseClass = S;
		using PrivateBaseClass::PrivateBaseClass;
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongRefHandler, MediaSessionFileFormatHandler, false>::type&() const { return reinterpret_cast<const MediaSessionFileFormatHandler&>(this->GetBaseRef()); }
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongRefHandler, MediaSessionFileFormatHandler, false>::type&() { return reinterpret_cast<const MediaSessionFileFormatHandler&>(this->GetBaseRef()); }
	};
	/// Intermediate helper class for MediaSessionFileFormatHandlerInterface.
	template <typename S> class ReferenceFunctionsImpl : public ConstReferenceFunctionsImpl<S>
	{
	public:
		ReferenceFunctionsImpl() = default;
		using PrivateBaseClass = ConstReferenceFunctionsImpl<S>;
		using PrivateBaseClass::PrivateBaseClass;
	};
	/// Intermediate helper class for MediaSessionFileFormatHandlerInterface.
	template <typename S> class COWReferenceFunctionsImpl : public ConstReferenceFunctionsImpl<S>
	{
	public:
		COWReferenceFunctionsImpl() = default;
		using PrivateBaseClass = ConstReferenceFunctionsImpl<S>;
		using PrivateBaseClass::PrivateBaseClass;
	};
	template <typename ST> struct ReferenceFunctionsHelper : public std::conditional<maxon::Bool(ST::type::Handler::KIND & (maxon::VALUEKIND::COW_MASK | maxon::VALUEKIND::DEEP_CONSTNESS)), COWReferenceFunctionsImpl<typename FileFormatHandlerInterface::Hxx1::template ReferenceFunctionsHelper<ST>::type>, typename std::conditional<std::is_const<typename ST::type::PrivateReferencedType>::value, ConstReferenceFunctionsImpl<typename FileFormatHandlerInterface::Hxx1::template ReferenceFunctionsHelper<ST>::type>, ReferenceFunctionsImpl<typename FileFormatHandlerInterface::Hxx1::template ReferenceFunctionsHelper<ST>::type>>::type> { };
};
class MediaSessionFileFormatHandlerInterface::Hxx1::Reference :
#ifdef DOXYGEN
public ConstReferenceFunctionsImplDoxy<MediaSessionFileFormatHandler>
#else
public maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<const MediaSessionFileFormatHandlerInterface, maxon::StrongRefHandler, MediaSessionFileFormatHandler>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(Reference, maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<const MediaSessionFileFormatHandlerInterface, maxon::StrongRefHandler, MediaSessionFileFormatHandler>>>>);
	using NonConst = Hxx1::NonConstRef;
};

class MediaSessionFileFormatHandlerInterface::Hxx1::NonConstRef :
#ifdef DOXYGEN
public ReferenceFunctionsImplDoxy<NonConstRef>
#else
public maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<MediaSessionFileFormatHandlerInterface, maxon::StrongRefHandler, NonConstRef>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(NonConstRef, maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<MediaSessionFileFormatHandlerInterface, maxon::StrongRefHandler, NonConstRef>>>>);
};

/// MediaSessionFileFormatHandler is the reference class of MediaSessionFileFormatHandlerInterface.
///
/// FileFormatHandlerInterface implements a handler for a specific FileFormat.
/// E.g. two different implementations could offer different loaders for one and the same FileFormat.
/// FileFormat::Zip implements one handler for Directory Browsing (IoBrowseRef) and one for ReadArchiveRef.
class MediaSessionFileFormatHandler : public MediaSessionFileFormatHandlerInterface::Hxx1::Reference
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(MediaSessionFileFormatHandler, typename MediaSessionFileFormatHandlerInterface::Hxx1::Reference);
};

namespace URLFLAGS
{
#ifndef PRIVATE_MAXON_GUARD_maxon_URLFLAGS
#define PRIVATE_MAXON_GUARD_maxon_URLFLAGS
	class RESTRICT : public maxon::RESTRICT { }; template <typename T> RESTRICT TestRestriction(T y, maxon::OverloadRank1);
#endif
}
#endif
