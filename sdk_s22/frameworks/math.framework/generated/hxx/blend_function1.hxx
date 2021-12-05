#if 1
class BlendFunctionRef;

struct BlendFunctionInterface::HasBase { template <typename I> struct Check { static const maxon::Bool value = std::is_same<I, BlendFunctionInterface>::value || ObjectInterface::HasBase::template Check<I>::value; static I* Cast(BlendFunctionInterface* ptr) { return static_cast<I*>(static_cast<maxon::ObjectInterface*>(ptr)); } }; };
struct BlendFunctionInterface::Hxx1
{
	class Reference;
	using ReferenceClass = BlendFunctionRef;
	template <template <typename...> class TEMPL> using SubstituteBases = TEMPL<ObjectInterface>;
	/// Intermediate helper class for BlendFunctionInterface.
	template <typename S> class ConstReferenceFunctionsImpl DOXYGEN_SWITCH(: public S,)
	{
	public:
		ConstReferenceFunctionsImpl() = default;
		using PrivateBaseClass = S;
		using PrivateBaseClass::PrivateBaseClass;
	};
	/// Intermediate helper class for BlendFunctionInterface.
	template <typename S> class ReferenceFunctionsImpl : public ConstReferenceFunctionsImpl<S>
	{
	public:
		ReferenceFunctionsImpl() = default;
		using PrivateBaseClass = ConstReferenceFunctionsImpl<S>;
		using PrivateBaseClass::PrivateBaseClass;
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongRefHandler, BlendFunctionRef, true>::type&() const { return reinterpret_cast<const BlendFunctionRef&>(this->GetBaseRef()); }
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongRefHandler, BlendFunctionRef, false>::type&() { return reinterpret_cast<const BlendFunctionRef&>(this->GetBaseRef()); }
/// Maps a value for a given x value based on the given startValue and endValue.
		inline Result<Data> MapValue(Float x, const Data& startValue, const Data& endValue) const;
	};
	/// Intermediate helper class for BlendFunctionInterface.
	template <typename S> class COWReferenceFunctionsImpl : public ConstReferenceFunctionsImpl<S>
	{
	public:
		COWReferenceFunctionsImpl() = default;
		using PrivateBaseClass = ConstReferenceFunctionsImpl<S>;
		using PrivateBaseClass::PrivateBaseClass;
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, void, BlendFunctionRef, false>::type&() { return reinterpret_cast<const BlendFunctionRef&>(this->GetBaseRef()); }
/// Maps a value for a given x value based on the given startValue and endValue.
		inline Result<Data> MapValue(Float x, const Data& startValue, const Data& endValue);
	};
	template <typename ST> struct ReferenceFunctionsHelper : public std::conditional<maxon::Bool(ST::type::Handler::KIND & (maxon::VALUEKIND::COW_MASK | maxon::VALUEKIND::DEEP_CONSTNESS)), COWReferenceFunctionsImpl<typename ObjectInterface::Hxx1::template ReferenceFunctionsHelper<ST>::type>, typename std::conditional<std::is_const<typename ST::type::PrivateReferencedType>::value, ConstReferenceFunctionsImpl<typename ObjectInterface::Hxx1::template ReferenceFunctionsHelper<ST>::type>, ReferenceFunctionsImpl<typename ObjectInterface::Hxx1::template ReferenceFunctionsHelper<ST>::type>>::type> { };
};
class BlendFunctionInterface::Hxx1::Reference :
#ifdef DOXYGEN
public ReferenceFunctionsImplDoxy<BlendFunctionRef>
#else
public maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<BlendFunctionInterface, maxon::StrongRefHandler, BlendFunctionRef>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(Reference, maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<BlendFunctionInterface, maxon::StrongRefHandler, BlendFunctionRef>>>>);
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
