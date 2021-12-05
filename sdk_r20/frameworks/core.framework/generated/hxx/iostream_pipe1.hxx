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
struct IoPipeInOutputStreamInterface::HasBase { template <typename I> struct Check { static const maxon::Bool value = std::is_same<I, IoPipeInOutputStreamInterface>::value || InOutputStreamInterface::HasBase::Check<I>::value; static I* Cast(IoPipeInOutputStreamInterface* ptr) { return static_cast<I*>(static_cast<maxon::Object*>(ptr)); } }; };
class IoPipeInOutputStreamRef;

struct IoPipeInOutputStreamInterface::ReferenceClassHelper { using type = IoPipeInOutputStreamRef; };

/// Intermediate helper class for IoPipeInOutputStreamInterface.
template <typename S> class IoPipeInOutputStreamInterface::ConstReferenceFunctionsImpl DOXYGEN_SWITCH(: public S,)
{
public:
	ConstReferenceFunctionsImpl() = default;
	using PrivateBaseClass = S;
	using PrivateBaseClass::PrivateBaseClass;
	inline typename std::conditional<S::HAS_ERROR, maxon::Result<PIPEHANDLE>, PIPEHANDLE>::type GetReadHandle() const;
	inline typename std::conditional<S::HAS_ERROR, maxon::Result<PIPEHANDLE>, PIPEHANDLE>::type GetWriteHandle() const;
};
#ifdef DOXYGEN
template <typename REF> class IoPipeInOutputStreamInterface::ConstReferenceFunctionsImplDoxy : public IoPipeInOutputStreamInterface::ConstReferenceFunctionsImpl<REF>, public InOutputStreamInterface::ConstReferenceFunctionsImplDoxy<REF> { };
#endif

/// Intermediate helper class for IoPipeInOutputStreamInterface.
template <typename S> class IoPipeInOutputStreamInterface::ReferenceFunctionsImpl : public ConstReferenceFunctionsImpl<S>
{
public:
	ReferenceFunctionsImpl() = default;
	using PrivateBaseClass = ConstReferenceFunctionsImpl<S>;
	using PrivateBaseClass::PrivateBaseClass;
	operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongRefHandler, IoPipeInOutputStreamRef, true>::type&() const { return reinterpret_cast<const IoPipeInOutputStreamRef&>(this->GetBaseRef()); }
	operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongRefHandler, IoPipeInOutputStreamRef, false>::type&() { return reinterpret_cast<const IoPipeInOutputStreamRef&>(this->GetBaseRef()); }
};
#ifdef DOXYGEN
template <typename REF> class IoPipeInOutputStreamInterface::ReferenceFunctionsImplDoxy : public IoPipeInOutputStreamInterface::ReferenceFunctionsImpl<REF>, public InOutputStreamInterface::ReferenceFunctionsImplDoxy<REF> { };
#endif

/// Intermediate helper class for IoPipeInOutputStreamInterface.
template <typename S> class IoPipeInOutputStreamInterface::COWReferenceFunctionsImpl : public ConstReferenceFunctionsImpl<S>
{
public:
	COWReferenceFunctionsImpl() = default;
	using PrivateBaseClass = ConstReferenceFunctionsImpl<S>;
	using PrivateBaseClass::PrivateBaseClass;
	operator const typename maxon::RefConversionTarget<S, typename S::Handler, void, IoPipeInOutputStreamRef, false>::type&() { return reinterpret_cast<const IoPipeInOutputStreamRef&>(this->GetBaseRef()); }
};
#ifdef DOXYGEN
template <typename REF> class IoPipeInOutputStreamInterface::COWReferenceFunctionsImplDoxy : public IoPipeInOutputStreamInterface::COWReferenceFunctionsImpl<REF>, public InOutputStreamInterface::COWReferenceFunctionsImplDoxy<REF> { };
#endif

template <typename ST> struct IoPipeInOutputStreamInterface::ReferenceFunctions { using type = typename std::conditional<maxon::Bool(ST::type::Handler::KIND & (maxon::VALUEKIND::COW_MASK | maxon::VALUEKIND::DEEP_CONSTNESS)), COWReferenceFunctionsImpl<typename InOutputStreamInterface::ReferenceFunctions<ST>::type>, typename std::conditional<std::is_const<typename ST::type::PrivateReferencedType>::value, ConstReferenceFunctionsImpl<typename InOutputStreamInterface::ReferenceFunctions<ST>::type>, ReferenceFunctionsImpl<typename InOutputStreamInterface::ReferenceFunctions<ST>::type>>::type>::type; };
class IoPipeInOutputStreamInterface::Reference :
#ifdef DOXYGEN
public ReferenceFunctionsImplDoxy<IoPipeInOutputStreamRef>
#else
public maxon::ReferenceBase<ReferenceFunctions<maxon::RefBaseFunctions<maxon::DirectRef<IoPipeInOutputStreamInterface, maxon::StrongRefHandler, IoPipeInOutputStreamRef>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(Reference, maxon::ReferenceBase<ReferenceFunctions<maxon::RefBaseFunctions<maxon::DirectRef<IoPipeInOutputStreamInterface, maxon::StrongRefHandler, IoPipeInOutputStreamRef>>>>);
	using NonConst = Super::ReferenceClass;
};

/// IoPipeInOutputStreamRef is the reference class of IoPipeInOutputStreamInterface.
///
/// Creates a pipe stream for in and output
class IoPipeInOutputStreamRef : public IoPipeInOutputStreamInterface::Reference
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(IoPipeInOutputStreamRef, Reference);
};

#endif
