#if 1
struct FunctionInterface::HasBase { template <typename I> struct Check { static const maxon::Bool value = std::is_same<I, FunctionInterface>::value || Object::HasBase::Check<I>::value; static I* Cast(FunctionInterface* ptr) { return static_cast<I*>(static_cast<maxon::Object*>(ptr)); } }; };
class GenericFunction;

struct FunctionInterface::ReferenceClassHelper { using type = GenericFunction; };

/// Intermediate helper class for FunctionInterface.
template <typename S> class FunctionInterface::ConstReferenceFunctionsImpl DOXYGEN_SWITCH(: public S,)
{
public:
	ConstReferenceFunctionsImpl() = default;
	using PrivateBaseClass = S;
	using PrivateBaseClass::PrivateBaseClass;
	operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongRefHandler, GenericFunction, false>::type&() const { return reinterpret_cast<const GenericFunction&>(this->GetBaseRef()); }
	operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongRefHandler, GenericFunction, false>::type&() { return reinterpret_cast<const GenericFunction&>(this->GetBaseRef()); }
	inline typename std::conditional<S::HAS_ERROR, maxon::Result<const FunctionDataType*>, const FunctionDataType*>::type GetFunctionType() const;
	inline Result<void> Invoke(DynamicTupleInterface* outputs, DynamicTupleInterface* inputs) const;
	inline Result<void> Invoke(DynamicTupleInterface* outputs, DynamicTupleInterface* inputs, Data& cacheData) const;
	inline typename std::conditional<S::HAS_ERROR, maxon::Result<ConstDataPtr>, ConstDataPtr>::type GetConstantValue(const Member& output) const;
};
#ifdef DOXYGEN
template <typename REF> class FunctionInterface::ConstReferenceFunctionsImplDoxy : public FunctionInterface::ConstReferenceFunctionsImpl<REF>, public Object::ConstReferenceFunctionsImplDoxy<REF> { };
#endif

/// Intermediate helper class for FunctionInterface.
template <typename S> class FunctionInterface::ReferenceFunctionsImpl : public ConstReferenceFunctionsImpl<S>
{
public:
	ReferenceFunctionsImpl() = default;
	using PrivateBaseClass = ConstReferenceFunctionsImpl<S>;
	using PrivateBaseClass::PrivateBaseClass;
};
#ifdef DOXYGEN
template <typename REF> class FunctionInterface::ReferenceFunctionsImplDoxy : public FunctionInterface::ReferenceFunctionsImpl<REF>, public Object::ReferenceFunctionsImplDoxy<REF> { };
#endif

/// Intermediate helper class for FunctionInterface.
template <typename S> class FunctionInterface::COWReferenceFunctionsImpl : public ConstReferenceFunctionsImpl<S>
{
public:
	COWReferenceFunctionsImpl() = default;
	using PrivateBaseClass = ConstReferenceFunctionsImpl<S>;
	using PrivateBaseClass::PrivateBaseClass;
};
#ifdef DOXYGEN
template <typename REF> class FunctionInterface::COWReferenceFunctionsImplDoxy : public FunctionInterface::COWReferenceFunctionsImpl<REF>, public Object::COWReferenceFunctionsImplDoxy<REF> { };
#endif

template <typename ST> struct FunctionInterface::ReferenceFunctions { using type = typename std::conditional<maxon::Bool(ST::type::Handler::KIND & (maxon::VALUEKIND::COW_MASK | maxon::VALUEKIND::DEEP_CONSTNESS)), COWReferenceFunctionsImpl<typename Object::ReferenceFunctions<ST>::type>, typename std::conditional<std::is_const<typename ST::type::PrivateReferencedType>::value, ConstReferenceFunctionsImpl<typename Object::ReferenceFunctions<ST>::type>, ReferenceFunctionsImpl<typename Object::ReferenceFunctions<ST>::type>>::type>::type; };
class FunctionInterface::Reference :
#ifdef DOXYGEN
public ConstReferenceFunctionsImplDoxy<GenericFunction>
#else
public maxon::ReferenceBase<ReferenceFunctions<maxon::RefBaseFunctions<maxon::DirectRef<const FunctionInterface, maxon::StrongRefHandler, GenericFunction>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(Reference, maxon::ReferenceBase<ReferenceFunctions<maxon::RefBaseFunctions<maxon::DirectRef<const FunctionInterface, maxon::StrongRefHandler, GenericFunction>>>>);
	using NonConst = NonConstRef;
};

class FunctionInterface::NonConstRef :
#ifdef DOXYGEN
public ReferenceFunctionsImplDoxy<NonConstRef>
#else
public maxon::ReferenceBase<ReferenceFunctions<maxon::RefBaseFunctions<maxon::DirectRef<FunctionInterface, maxon::StrongRefHandler, NonConstRef>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(NonConstRef, maxon::ReferenceBase<ReferenceFunctions<maxon::RefBaseFunctions<maxon::DirectRef<FunctionInterface, maxon::StrongRefHandler, NonConstRef>>>>);
};

/// GenericFunction is the reference class of FunctionInterface.
class GenericFunction : public FunctionInterface::Reference
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(GenericFunction, Reference);
};

#endif
