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

struct IoPipeInOutputStreamInterface::HasBaseDetector { template <typename I> struct Check { static const maxon::Bool value = std::is_same<I, IoPipeInOutputStreamInterface>::value || InOutputStreamInterface::HasBaseDetector::template Check<I>::value; static I* Cast(IoPipeInOutputStreamInterface* ptr) { return reinterpret_cast<I*>(ptr); } }; };
struct IoPipeInOutputStreamInterface::Hxx1
{
	class Reference;
	using ReferenceClass = IoPipeInOutputStreamRef;
	template <template <typename...> class TEMPL> using SubstituteBases = TEMPL<InOutputStreamInterface>;
	/// Intermediate helper class for IoPipeInOutputStreamInterface.
	template <typename S> class ConstFn DOXYGEN_SWITCH_REVERSED(, : public S)
	{
	public:
		ConstFn() = default;
		using PrivateBaseClass = S;
		using PrivateBaseClass::PrivateBaseClass;
		using PrivateBaseClass::PrivateLookupFn;
		static ConstFn PrivateLookupFn(IoPipeInOutputStreamInterface**);
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<PIPEHANDLE>, PIPEHANDLE>::type GetReadHandle() const;
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<PIPEHANDLE>, PIPEHANDLE>::type GetWriteHandle() const;
	};
	/// Intermediate helper class for IoPipeInOutputStreamInterface.
	template <typename S> class Fn : public ConstFn<S>
	{
	public:
		Fn() = default;
		using PrivateBaseClass = ConstFn<S>;
		using PrivateBaseClass::PrivateBaseClass;
		using PrivateBaseClass::PrivateLookupFn;
		static Fn PrivateLookupFn(IoPipeInOutputStreamInterface**);
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongRefHandler, IoPipeInOutputStreamRef, true>::type&() const { return reinterpret_cast<const IoPipeInOutputStreamRef&>(this->GetBaseRef()); }
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongRefHandler, IoPipeInOutputStreamRef, false>::type&() { return reinterpret_cast<const IoPipeInOutputStreamRef&>(this->GetBaseRef()); }
	};
	/// Intermediate helper class for IoPipeInOutputStreamInterface.
	template <typename S> class COWFn : public ConstFn<S>
	{
	public:
		COWFn() = default;
		using PrivateBaseClass = ConstFn<S>;
		using PrivateBaseClass::PrivateBaseClass;
		using PrivateBaseClass::PrivateLookupFn;
		static COWFn PrivateLookupFn(IoPipeInOutputStreamInterface**);
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, void, IoPipeInOutputStreamRef, false>::type&() { return reinterpret_cast<const IoPipeInOutputStreamRef&>(this->GetBaseRef()); }
	};
	template <typename ST> struct FnHelper : public std::conditional<
	maxon::Bool(ST::type::Handler::KIND & (maxon::VALUEKIND::COW_MASK | maxon::VALUEKIND::DEEP_CONSTNESS)),
	COWFn<typename InOutputStreamInterface::Hxx1::template FnHelper<ST>::type>,
	typename std::conditional<std::is_const<typename ST::type::PrivateReferencedType>::value, ConstFn<typename InOutputStreamInterface::Hxx1::template FnHelper<ST>::type>, Fn<typename InOutputStreamInterface::Hxx1::template FnHelper<ST>::type>>::type
	> { };
};
class IoPipeInOutputStreamInterface::Hxx1::Reference :
#ifdef DOXYGEN
public FnDoxy<IoPipeInOutputStreamRef>
#else
public maxon::RefBase<Hxx1::FnHelper<maxon::RefBaseFn<maxon::DirectRef<IoPipeInOutputStreamInterface, maxon::StrongRefHandler, IoPipeInOutputStreamRef>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(Reference, maxon::RefBase<Hxx1::FnHelper<maxon::RefBaseFn<maxon::DirectRef<IoPipeInOutputStreamInterface, maxon::StrongRefHandler, IoPipeInOutputStreamRef>>>>);
	using NonConst = typename Super::ReferenceClass;
};

/// IoPipeInOutputStreamRef is the reference class of IoPipeInOutputStreamInterface.
///
/// Creates a pipe stream for in and output
class IoPipeInOutputStreamRef : public IoPipeInOutputStreamInterface::Hxx1::Reference
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(IoPipeInOutputStreamRef, typename IoPipeInOutputStreamInterface::Hxx1::Reference);
	using ConstPtr = typename IoPipeInOutputStreamInterface::ConstPtr;
};

#endif
