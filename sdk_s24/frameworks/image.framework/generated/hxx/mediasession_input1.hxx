#if 1
namespace MEDIAINPUTPROPERTIES
{
#ifndef PRIVATE_MAXON_GUARD_maxon_MEDIAINPUTPROPERTIES
#define PRIVATE_MAXON_GUARD_maxon_MEDIAINPUTPROPERTIES
	class RESTRICT : public maxon::RESTRICT { }; template <typename T> RESTRICT TestRestriction(T y, maxon::OverloadRank1);
#endif
}
class MediaInputRef;

struct MediaInputInterface::HasBaseDetector { template <typename I> struct Check { static const maxon::Bool value = std::is_same<I, MediaInputInterface>::value || MediaConverterInterface::HasBaseDetector::template Check<I>::value; static I* Cast(MediaInputInterface* ptr) { return reinterpret_cast<I*>(ptr); } }; };
struct MediaInputInterface::Hxx1
{
	class Reference;
	using ReferenceClass = MediaInputRef;
	template <template <typename...> class TEMPL> using SubstituteBases = TEMPL<MediaConverterInterface>;
	/// Intermediate helper class for MediaInputInterface.
	template <typename S> class ReferenceFunctionsImpl : public S
	{
	public:
		ReferenceFunctionsImpl() = default;
		using PrivateBaseClass = S;
		using PrivateBaseClass::PrivateBaseClass;
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongRefHandler, MediaInputRef, true>::type&() const { return reinterpret_cast<const MediaInputRef&>(this->GetBaseRef()); }
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongRefHandler, MediaInputRef, false>::type&() { return reinterpret_cast<const MediaInputRef&>(this->GetBaseRef()); }
	};
	/// Intermediate helper class for MediaInputInterface.
	template <typename S> class COWReferenceFunctionsImpl : public S
	{
	public:
		COWReferenceFunctionsImpl() = default;
		using PrivateBaseClass = S;
		using PrivateBaseClass::PrivateBaseClass;
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, void, MediaInputRef, false>::type&() { return reinterpret_cast<const MediaInputRef&>(this->GetBaseRef()); }
	};
	template <typename ST> struct ReferenceFunctionsHelper : public std::conditional<
	maxon::Bool(ST::type::Handler::KIND & (maxon::VALUEKIND::COW_MASK | maxon::VALUEKIND::DEEP_CONSTNESS)),
	COWReferenceFunctionsImpl<typename MediaConverterInterface::Hxx1::template ReferenceFunctionsHelper<ST>::type>,
	typename std::conditional<std::is_const<typename ST::type::PrivateReferencedType>::value, typename MediaConverterInterface::Hxx1::template ReferenceFunctionsHelper<ST>::type, ReferenceFunctionsImpl<typename MediaConverterInterface::Hxx1::template ReferenceFunctionsHelper<ST>::type>>::type
	> { };
};
class MediaInputInterface::Hxx1::Reference :
#ifdef DOXYGEN
public ReferenceFunctionsImplDoxy<MediaInputRef>
#else
public maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<MediaInputInterface, maxon::StrongRefHandler, MediaInputRef>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(Reference, maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<MediaInputInterface, maxon::StrongRefHandler, MediaInputRef>>>>);
	using NonConst = typename Super::ReferenceClass;
};

/// MediaInputRef is the reference class of MediaInputInterface.
///
/// The MediaInputInterface class provides an specific implementation to provide input data from a given source.
class MediaInputRef : public MediaInputInterface::Hxx1::Reference
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(MediaInputRef, typename MediaInputInterface::Hxx1::Reference);
	using ConstPtr = typename MediaInputInterface::ConstPtr;
};

#endif
