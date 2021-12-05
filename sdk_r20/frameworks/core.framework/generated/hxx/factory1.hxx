#if 1
struct FactoryInterface::HasBase { template <typename I> struct Check { static const maxon::Bool value = std::is_same<I, FactoryInterface>::value || DataDictionaryObjectInterface::HasBase::Check<I>::value; static I* Cast(FactoryInterface* ptr) { return static_cast<I*>(static_cast<maxon::Object*>(ptr)); } }; };
class GenericFactory;

struct FactoryInterface::ReferenceClassHelper { using type = GenericFactory; };

/// Intermediate helper class for FactoryInterface.
template <typename S> class FactoryInterface::ConstReferenceFunctionsImpl DOXYGEN_SWITCH(: public S,)
{
public:
	ConstReferenceFunctionsImpl() = default;
	using PrivateBaseClass = S;
	using PrivateBaseClass::PrivateBaseClass;
	operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongRefHandler, GenericFactory, false>::type&() const { return reinterpret_cast<const GenericFactory&>(this->GetBaseRef()); }
	operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongRefHandler, GenericFactory, false>::type&() { return reinterpret_cast<const GenericFactory&>(this->GetBaseRef()); }
};
#ifdef DOXYGEN
template <typename REF> class FactoryInterface::ConstReferenceFunctionsImplDoxy : public FactoryInterface::ConstReferenceFunctionsImpl<REF>, public DataDictionaryObjectInterface::ConstReferenceFunctionsImplDoxy<REF> { };
#endif

/// Intermediate helper class for FactoryInterface.
template <typename S> class FactoryInterface::ReferenceFunctionsImpl : public ConstReferenceFunctionsImpl<S>
{
public:
	ReferenceFunctionsImpl() = default;
	using PrivateBaseClass = ConstReferenceFunctionsImpl<S>;
	using PrivateBaseClass::PrivateBaseClass;
};
#ifdef DOXYGEN
template <typename REF> class FactoryInterface::ReferenceFunctionsImplDoxy : public FactoryInterface::ReferenceFunctionsImpl<REF>, public DataDictionaryObjectInterface::ReferenceFunctionsImplDoxy<REF> { };
#endif

/// Intermediate helper class for FactoryInterface.
template <typename S> class FactoryInterface::COWReferenceFunctionsImpl : public ConstReferenceFunctionsImpl<S>
{
public:
	COWReferenceFunctionsImpl() = default;
	using PrivateBaseClass = ConstReferenceFunctionsImpl<S>;
	using PrivateBaseClass::PrivateBaseClass;
};
#ifdef DOXYGEN
template <typename REF> class FactoryInterface::COWReferenceFunctionsImplDoxy : public FactoryInterface::COWReferenceFunctionsImpl<REF>, public DataDictionaryObjectInterface::COWReferenceFunctionsImplDoxy<REF> { };
#endif

template <typename ST> struct FactoryInterface::ReferenceFunctions { using type = typename std::conditional<maxon::Bool(ST::type::Handler::KIND & (maxon::VALUEKIND::COW_MASK | maxon::VALUEKIND::DEEP_CONSTNESS)), COWReferenceFunctionsImpl<typename DataDictionaryObjectInterface::ReferenceFunctions<ST>::type>, typename std::conditional<std::is_const<typename ST::type::PrivateReferencedType>::value, ConstReferenceFunctionsImpl<typename DataDictionaryObjectInterface::ReferenceFunctions<ST>::type>, ReferenceFunctionsImpl<typename DataDictionaryObjectInterface::ReferenceFunctions<ST>::type>>::type>::type; };
class FactoryInterface::Reference :
#ifdef DOXYGEN
public ConstReferenceFunctionsImplDoxy<GenericFactory>
#else
public maxon::ReferenceBase<ReferenceFunctions<maxon::RefBaseFunctions<maxon::DirectRef<const FactoryInterface, maxon::StrongRefHandler, GenericFactory>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(Reference, maxon::ReferenceBase<ReferenceFunctions<maxon::RefBaseFunctions<maxon::DirectRef<const FactoryInterface, maxon::StrongRefHandler, GenericFactory>>>>);
	using NonConst = NonConstRef;
};

class FactoryInterface::NonConstRef :
#ifdef DOXYGEN
public ReferenceFunctionsImplDoxy<NonConstRef>
#else
public maxon::ReferenceBase<ReferenceFunctions<maxon::RefBaseFunctions<maxon::DirectRef<FactoryInterface, maxon::StrongRefHandler, NonConstRef>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(NonConstRef, maxon::ReferenceBase<ReferenceFunctions<maxon::RefBaseFunctions<maxon::DirectRef<FactoryInterface, maxon::StrongRefHandler, NonConstRef>>>>);
};

/// GenericFactory is the reference class of FactoryInterface.
///
/// Interface for factories. Factories create new objects based on parameters.
/// @see Factory
class GenericFactory : public FactoryInterface::Reference
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(GenericFactory, Reference);
};

#endif
