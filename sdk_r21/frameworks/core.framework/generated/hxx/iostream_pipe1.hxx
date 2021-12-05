#if 1
namespace URLFLAGS
{
#ifndef PRIVATE_MAXON_GUARD_maxon_URLFLAGS
#define PRIVATE_MAXON_GUARD_maxon_URLFLAGS
	class RESTRICT : public maxon::RESTRICT { }; template <typename T> RESTRICT TestRestriction(T y, maxon::OverloadRank1);
#endif
}
#ifdef MAXON_TARGET_WINDOWS
#else
#endif
class IoPipeInOutputStreamRef;

struct IoPipeInOutputStreamInterface::HasBase { template <typename I> struct Check { static const maxon::Bool value = std::is_same<I, IoPipeInOutputStreamInterface>::value || InOutputStreamInterface::HasBase::template Check<I>::value; static I* Cast(IoPipeInOutputStreamInterface* ptr) { return static_cast<I*>(static_cast<maxon::ObjectInterface*>(ptr)); } }; };
struct IoPipeInOutputStreamInterface::Hxx1
{
	class Reference;
	using ReferenceClass = IoPipeInOutputStreamRef;
	template <template <typename...> class TEMPL> using SubstituteBases = TEMPL<InOutputStreamInterface>;
	/// Intermediate helper class for IoPipeInOutputStreamInterface.
	template <typename S> class ConstReferenceFunctionsImpl DOXYGEN_SWITCH(: public S,)
	{
	public:
		ConstReferenceFunctionsImpl() = default;
		using PrivateBaseClass = S;
		using PrivateBaseClass::PrivateBaseClass;
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<PIPEHANDLE>, PIPEHANDLE>::type GetReadHandle() const;
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<PIPEHANDLE>, PIPEHANDLE>::type GetWriteHandle() const;
	};
	/// Intermediate helper class for IoPipeInOutputStreamInterface.
	template <typename S> class ReferenceFunctionsImpl : public ConstReferenceFunctionsImpl<S>
	{
	public:
		ReferenceFunctionsImpl() = default;
		using PrivateBaseClass = ConstReferenceFunctionsImpl<S>;
		using PrivateBaseClass::PrivateBaseClass;
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongRefHandler, IoPipeInOutputStreamRef, true>::type&() const { return reinterpret_cast<const IoPipeInOutputStreamRef&>(this->GetBaseRef()); }
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongRefHandler, IoPipeInOutputStreamRef, false>::type&() { return reinterpret_cast<const IoPipeInOutputStreamRef&>(this->GetBaseRef()); }
	};
	/// Intermediate helper class for IoPipeInOutputStreamInterface.
	template <typename S> class COWReferenceFunctionsImpl : public ConstReferenceFunctionsImpl<S>
	{
	public:
		COWReferenceFunctionsImpl() = default;
		using PrivateBaseClass = ConstReferenceFunctionsImpl<S>;
		using PrivateBaseClass::PrivateBaseClass;
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, void, IoPipeInOutputStreamRef, false>::type&() { return reinterpret_cast<const IoPipeInOutputStreamRef&>(this->GetBaseRef()); }
	};
	template <typename ST> struct ReferenceFunctionsHelper : public std::conditional<maxon::Bool(ST::type::Handler::KIND & (maxon::VALUEKIND::COW_MASK | maxon::VALUEKIND::DEEP_CONSTNESS)), COWReferenceFunctionsImpl<typename InOutputStreamInterface::Hxx1::template ReferenceFunctionsHelper<ST>::type>, typename std::conditional<std::is_const<typename ST::type::PrivateReferencedType>::value, ConstReferenceFunctionsImpl<typename InOutputStreamInterface::Hxx1::template ReferenceFunctionsHelper<ST>::type>, ReferenceFunctionsImpl<typename InOutputStreamInterface::Hxx1::template ReferenceFunctionsHelper<ST>::type>>::type> { };
};
class IoPipeInOutputStreamInterface::Hxx1::Reference :
#ifdef DOXYGEN
public ReferenceFunctionsImplDoxy<IoPipeInOutputStreamRef>
#else
public maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<IoPipeInOutputStreamInterface, maxon::StrongRefHandler, IoPipeInOutputStreamRef>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(Reference, maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<IoPipeInOutputStreamInterface, maxon::StrongRefHandler, IoPipeInOutputStreamRef>>>>);
	using NonConst = typename Super::ReferenceClass;
};

/// IoPipeInOutputStreamRef is the reference class of IoPipeInOutputStreamInterface.
///
/// Creates a pipe stream for in and output
class IoPipeInOutputStreamRef : public IoPipeInOutputStreamInterface::Hxx1::Reference
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(IoPipeInOutputStreamRef, typename IoPipeInOutputStreamInterface::Hxx1::Reference);
};

#endif
