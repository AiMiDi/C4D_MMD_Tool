#if 1
class GenericFunction;

struct FunctionInterface::HasBase { template <typename I> struct Check { static const maxon::Bool value = std::is_same<I, FunctionInterface>::value || ObjectInterface::HasBase::template Check<I>::value; static I* Cast(FunctionInterface* ptr) { return static_cast<I*>(static_cast<maxon::ObjectInterface*>(ptr)); } }; };
struct FunctionInterface::Hxx1
{
	class Reference;
	class NonConstRef;
	using ReferenceClass = GenericFunction;
	template <template <typename...> class TEMPL> using SubstituteBases = TEMPL<ObjectInterface>;
	/// Intermediate helper class for FunctionInterface.
	template <typename S> class ConstReferenceFunctionsImpl DOXYGEN_SWITCH(: public S,)
	{
	public:
		ConstReferenceFunctionsImpl() = default;
		using PrivateBaseClass = S;
		using PrivateBaseClass::PrivateBaseClass;
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongRefHandler, GenericFunction, false>::type&() const { return reinterpret_cast<const GenericFunction&>(this->GetBaseRef()); }
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongRefHandler, GenericFunction, false>::type&() { return reinterpret_cast<const GenericFunction&>(this->GetBaseRef()); }
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<const FunctionDataType&>, const FunctionDataType&>::type GetFunctionType() const;
		inline Result<void> Invoke(GenericSingletonContainerInterface* outputs, GenericSingletonContainerInterface* inputs) const;
		inline Result<void> Invoke(GenericSingletonContainerInterface* outputs, GenericSingletonContainerInterface* inputs, Data& cacheData) const;
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<ConstDataPtr>, ConstDataPtr>::type GetConstantValue(const Member& output) const;
	};
	/// Intermediate helper class for FunctionInterface.
	template <typename S> class ReferenceFunctionsImpl : public ConstReferenceFunctionsImpl<S>
	{
	public:
		ReferenceFunctionsImpl() = default;
		using PrivateBaseClass = ConstReferenceFunctionsImpl<S>;
		using PrivateBaseClass::PrivateBaseClass;
	};
	/// Intermediate helper class for FunctionInterface.
	template <typename S> class COWReferenceFunctionsImpl : public ConstReferenceFunctionsImpl<S>
	{
	public:
		COWReferenceFunctionsImpl() = default;
		using PrivateBaseClass = ConstReferenceFunctionsImpl<S>;
		using PrivateBaseClass::PrivateBaseClass;
	};
	template <typename ST> struct ReferenceFunctionsHelper : public std::conditional<maxon::Bool(ST::type::Handler::KIND & (maxon::VALUEKIND::COW_MASK | maxon::VALUEKIND::DEEP_CONSTNESS)), COWReferenceFunctionsImpl<typename ObjectInterface::Hxx1::template ReferenceFunctionsHelper<ST>::type>, typename std::conditional<std::is_const<typename ST::type::PrivateReferencedType>::value, ConstReferenceFunctionsImpl<typename ObjectInterface::Hxx1::template ReferenceFunctionsHelper<ST>::type>, ReferenceFunctionsImpl<typename ObjectInterface::Hxx1::template ReferenceFunctionsHelper<ST>::type>>::type> { };
};
class FunctionInterface::Hxx1::Reference :
#ifdef DOXYGEN
public ConstReferenceFunctionsImplDoxy<GenericFunction>
#else
public maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<const FunctionInterface, maxon::StrongRefHandler, GenericFunction>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(Reference, maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<const FunctionInterface, maxon::StrongRefHandler, GenericFunction>>>>);
	using NonConst = Hxx1::NonConstRef;
};

class FunctionInterface::Hxx1::NonConstRef :
#ifdef DOXYGEN
public ReferenceFunctionsImplDoxy<NonConstRef>
#else
public maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<FunctionInterface, maxon::StrongRefHandler, NonConstRef>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(NonConstRef, maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<FunctionInterface, maxon::StrongRefHandler, NonConstRef>>>>);
};

/// GenericFunction is the reference class of FunctionInterface.
class GenericFunction : public FunctionInterface::Hxx1::Reference
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(GenericFunction, typename FunctionInterface::Hxx1::Reference);
};

#endif
