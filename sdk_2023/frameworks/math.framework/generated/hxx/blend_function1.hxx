#if 1
class BlendFunctionRef;

struct BlendFunctionInterface::HasBaseDetector { template <typename I> struct Check { static const maxon::Bool value = std::is_same<I, BlendFunctionInterface>::value || ObjectInterface::HasBaseDetector::template Check<I>::value; static I* Cast(BlendFunctionInterface* ptr) { return reinterpret_cast<I*>(ptr); } }; };
struct BlendFunctionInterface::Hxx1
{
	class Reference;
	using ReferenceClass = BlendFunctionRef;
	template <template <typename...> class TEMPL> using SubstituteBases = TEMPL<ObjectInterface>;
	/// Intermediate helper class for BlendFunctionInterface.
	template <typename S> class Fn : public S
	{
	public:
		Fn() = default;
		using PrivateBaseClass = S;
		using PrivateBaseClass::PrivateBaseClass;
		using PrivateBaseClass::PrivateLookupFn;
		static Fn PrivateLookupFn(BlendFunctionInterface**);
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongRefHandler, BlendFunctionRef, true>::type&() const { return reinterpret_cast<const BlendFunctionRef&>(this->GetBaseRef()); }
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongRefHandler, BlendFunctionRef, false>::type&() { return reinterpret_cast<const BlendFunctionRef&>(this->GetBaseRef()); }
/// Maps a value for a given x value based on the given startValue and endValue.
		inline Result<Data> MapValue(Float x, const Data& startValue, const Data& endValue) const;
	};
	/// Intermediate helper class for BlendFunctionInterface.
	template <typename S> class COWFn : public S
	{
	public:
		COWFn() = default;
		using PrivateBaseClass = S;
		using PrivateBaseClass::PrivateBaseClass;
		using PrivateBaseClass::PrivateLookupFn;
		static COWFn PrivateLookupFn(BlendFunctionInterface**);
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, void, BlendFunctionRef, false>::type&() { return reinterpret_cast<const BlendFunctionRef&>(this->GetBaseRef()); }
/// Maps a value for a given x value based on the given startValue and endValue.
		inline Result<Data> MapValue(Float x, const Data& startValue, const Data& endValue);
	};
	template <typename ST> struct FnHelper : public std::conditional<
	maxon::Bool(ST::type::Handler::KIND & (maxon::VALUEKIND::COW_MASK | maxon::VALUEKIND::DEEP_CONSTNESS)),
	COWFn<typename ObjectInterface::Hxx1::template FnHelper<ST>::type>,
	typename std::conditional<std::is_const<typename ST::type::PrivateReferencedType>::value, typename ObjectInterface::Hxx1::template FnHelper<ST>::type, Fn<typename ObjectInterface::Hxx1::template FnHelper<ST>::type>>::type
	> { };
};
class BlendFunctionInterface::Hxx1::Reference :
#ifdef DOXYGEN
public FnDoxy<BlendFunctionRef>
#else
public maxon::RefBase<Hxx1::FnHelper<maxon::RefBaseFn<maxon::DirectRef<BlendFunctionInterface, maxon::StrongRefHandler, BlendFunctionRef>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(Reference, maxon::RefBase<Hxx1::FnHelper<maxon::RefBaseFn<maxon::DirectRef<BlendFunctionInterface, maxon::StrongRefHandler, BlendFunctionRef>>>>);
	using NonConst = typename Super::ReferenceClass;
};

/// BlendFunctionRef is the reference class of BlendFunctionInterface.
///
/// Blend function class.
/// The registry BlendFunctions allow to iterate over all available blend functions.
class BlendFunctionRef : public BlendFunctionInterface::Hxx1::Reference
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(BlendFunctionRef, typename BlendFunctionInterface::Hxx1::Reference);
	using ConstPtr = typename BlendFunctionInterface::ConstPtr;
};

#endif
