#if 1
struct AskPasswordInterface::HasBase { template <typename I> struct Check { static const maxon::Bool value = std::is_same<I, AskPasswordInterface>::value || Object::HasBase::Check<I>::value; static I* Cast(AskPasswordInterface* ptr) { return static_cast<I*>(static_cast<maxon::Object*>(ptr)); } }; };
class AskPasswordRef;

struct AskPasswordInterface::ReferenceClassHelper { using type = AskPasswordRef; };

/// Intermediate helper class for AskPasswordInterface.
template <typename S> class AskPasswordInterface::ConstReferenceFunctionsImpl DOXYGEN_SWITCH(: public S,)
{
public:
	ConstReferenceFunctionsImpl() = default;
	using PrivateBaseClass = S;
	using PrivateBaseClass::PrivateBaseClass;
/// @param[in] text								TODO: (Thomas) please document.
	inline Result<String> AskPasswordFromUser(const String& text) const;
};
#ifdef DOXYGEN
template <typename REF> class AskPasswordInterface::ConstReferenceFunctionsImplDoxy : public AskPasswordInterface::ConstReferenceFunctionsImpl<REF>, public Object::ConstReferenceFunctionsImplDoxy<REF> { };
#endif

/// Intermediate helper class for AskPasswordInterface.
template <typename S> class AskPasswordInterface::ReferenceFunctionsImpl : public ConstReferenceFunctionsImpl<S>
{
public:
	ReferenceFunctionsImpl() = default;
	using PrivateBaseClass = ConstReferenceFunctionsImpl<S>;
	using PrivateBaseClass::PrivateBaseClass;
	operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongRefHandler, AskPasswordRef, true>::type&() const { return reinterpret_cast<const AskPasswordRef&>(this->GetBaseRef()); }
	operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongRefHandler, AskPasswordRef, false>::type&() { return reinterpret_cast<const AskPasswordRef&>(this->GetBaseRef()); }
};
#ifdef DOXYGEN
template <typename REF> class AskPasswordInterface::ReferenceFunctionsImplDoxy : public AskPasswordInterface::ReferenceFunctionsImpl<REF>, public Object::ReferenceFunctionsImplDoxy<REF> { };
#endif

/// Intermediate helper class for AskPasswordInterface.
template <typename S> class AskPasswordInterface::COWReferenceFunctionsImpl : public ConstReferenceFunctionsImpl<S>
{
public:
	COWReferenceFunctionsImpl() = default;
	using PrivateBaseClass = ConstReferenceFunctionsImpl<S>;
	using PrivateBaseClass::PrivateBaseClass;
	operator const typename maxon::RefConversionTarget<S, typename S::Handler, void, AskPasswordRef, false>::type&() { return reinterpret_cast<const AskPasswordRef&>(this->GetBaseRef()); }
};
#ifdef DOXYGEN
template <typename REF> class AskPasswordInterface::COWReferenceFunctionsImplDoxy : public AskPasswordInterface::COWReferenceFunctionsImpl<REF>, public Object::COWReferenceFunctionsImplDoxy<REF> { };
#endif

template <typename ST> struct AskPasswordInterface::ReferenceFunctions { using type = typename std::conditional<maxon::Bool(ST::type::Handler::KIND & (maxon::VALUEKIND::COW_MASK | maxon::VALUEKIND::DEEP_CONSTNESS)), COWReferenceFunctionsImpl<typename Object::ReferenceFunctions<ST>::type>, typename std::conditional<std::is_const<typename ST::type::PrivateReferencedType>::value, ConstReferenceFunctionsImpl<typename Object::ReferenceFunctions<ST>::type>, ReferenceFunctionsImpl<typename Object::ReferenceFunctions<ST>::type>>::type>::type; };
class AskPasswordInterface::Reference :
#ifdef DOXYGEN
public ReferenceFunctionsImplDoxy<AskPasswordRef>
#else
public maxon::ReferenceBase<ReferenceFunctions<maxon::RefBaseFunctions<maxon::DirectRef<AskPasswordInterface, maxon::StrongRefHandler, AskPasswordRef>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(Reference, maxon::ReferenceBase<ReferenceFunctions<maxon::RefBaseFunctions<maxon::DirectRef<AskPasswordInterface, maxon::StrongRefHandler, AskPasswordRef>>>>);
	using NonConst = Super::ReferenceClass;
};

/// AskPasswordRef is the reference class of AskPasswordInterface.
///
/// TODO: (Thomas) please document.
class AskPasswordRef : public AskPasswordInterface::Reference
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(AskPasswordRef, Reference);
};

#endif
