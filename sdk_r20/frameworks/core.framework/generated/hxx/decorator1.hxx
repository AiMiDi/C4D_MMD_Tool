#if 1
struct DecoratorInterface::HasBase { template <typename I> struct Check { static const maxon::Bool value = std::is_same<I, DecoratorInterface>::value || Object::HasBase::Check<I>::value; static I* Cast(DecoratorInterface* ptr) { return static_cast<I*>(static_cast<maxon::Object*>(ptr)); } }; };
class DecoratorRef;

struct DecoratorInterface::ReferenceClassHelper { using type = DecoratorRef; };

/// Intermediate helper class for DecoratorInterface.
template <typename S> class DecoratorInterface::ConstReferenceFunctionsImpl DOXYGEN_SWITCH(: public S,)
{
public:
	ConstReferenceFunctionsImpl() = default;
	using PrivateBaseClass = S;
	using PrivateBaseClass::PrivateBaseClass;
/// @return												The decorated object.
	inline typename std::conditional<S::HAS_ERROR, maxon::Result<const ObjectBaseRef<typename S::PrivateReferencedType>&>, const ObjectBaseRef<typename S::PrivateReferencedType>&>::type GetDecoratedObject() const;
};
#ifdef DOXYGEN
template <typename REF> class DecoratorInterface::ConstReferenceFunctionsImplDoxy : public DecoratorInterface::ConstReferenceFunctionsImpl<REF>, public Object::ConstReferenceFunctionsImplDoxy<REF> { };
#endif

/// Intermediate helper class for DecoratorInterface.
template <typename S> class DecoratorInterface::ReferenceFunctionsImpl : public ConstReferenceFunctionsImpl<S>
{
public:
	ReferenceFunctionsImpl() = default;
	using PrivateBaseClass = ConstReferenceFunctionsImpl<S>;
	using PrivateBaseClass::PrivateBaseClass;
	operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongRefHandler, DecoratorRef, true>::type&() const { return reinterpret_cast<const DecoratorRef&>(this->GetBaseRef()); }
	operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongRefHandler, DecoratorRef, false>::type&() { return reinterpret_cast<const DecoratorRef&>(this->GetBaseRef()); }
};
#ifdef DOXYGEN
template <typename REF> class DecoratorInterface::ReferenceFunctionsImplDoxy : public DecoratorInterface::ReferenceFunctionsImpl<REF>, public Object::ReferenceFunctionsImplDoxy<REF> { };
#endif

/// Intermediate helper class for DecoratorInterface.
template <typename S> class DecoratorInterface::COWReferenceFunctionsImpl : public ConstReferenceFunctionsImpl<S>
{
public:
	COWReferenceFunctionsImpl() = default;
	using PrivateBaseClass = ConstReferenceFunctionsImpl<S>;
	using PrivateBaseClass::PrivateBaseClass;
	operator const typename maxon::RefConversionTarget<S, typename S::Handler, void, DecoratorRef, false>::type&() { return reinterpret_cast<const DecoratorRef&>(this->GetBaseRef()); }
};
#ifdef DOXYGEN
template <typename REF> class DecoratorInterface::COWReferenceFunctionsImplDoxy : public DecoratorInterface::COWReferenceFunctionsImpl<REF>, public Object::COWReferenceFunctionsImplDoxy<REF> { };
#endif

template <typename ST> struct DecoratorInterface::ReferenceFunctions { using type = typename std::conditional<maxon::Bool(ST::type::Handler::KIND & (maxon::VALUEKIND::COW_MASK | maxon::VALUEKIND::DEEP_CONSTNESS)), COWReferenceFunctionsImpl<typename Object::ReferenceFunctions<ST>::type>, typename std::conditional<std::is_const<typename ST::type::PrivateReferencedType>::value, ConstReferenceFunctionsImpl<typename Object::ReferenceFunctions<ST>::type>, ReferenceFunctionsImpl<typename Object::ReferenceFunctions<ST>::type>>::type>::type; };
class DecoratorInterface::Reference :
#ifdef DOXYGEN
public ReferenceFunctionsImplDoxy<DecoratorRef>
#else
public maxon::ReferenceBase<ReferenceFunctions<maxon::RefBaseFunctions<maxon::DirectRef<DecoratorInterface, maxon::StrongRefHandler, DecoratorRef>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(Reference, maxon::ReferenceBase<ReferenceFunctions<maxon::RefBaseFunctions<maxon::DirectRef<DecoratorInterface, maxon::StrongRefHandler, DecoratorRef>>>>);
	using NonConst = Super::ReferenceClass;
};

/// DecoratorRef is the reference class of DecoratorInterface.
///
/// This interface is implemented by decorator classes which forward calls to the base object.
class DecoratorRef : public DecoratorInterface::Reference
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(DecoratorRef, Reference);
};

struct EagerDecoratorInterface::HasBase { template <typename I> struct Check { static const maxon::Bool value = std::is_same<I, EagerDecoratorInterface>::value || DecoratorInterface::HasBase::Check<I>::value; static I* Cast(EagerDecoratorInterface* ptr) { return static_cast<I*>(static_cast<maxon::Object*>(ptr)); } }; };
class EagerDecoratorRef;

struct EagerDecoratorInterface::ReferenceClassHelper { using type = EagerDecoratorRef; };

/// Intermediate helper class for EagerDecoratorInterface.
template <typename S> class EagerDecoratorInterface::ConstReferenceFunctionsImpl DOXYGEN_SWITCH(: public S,)
{
public:
	ConstReferenceFunctionsImpl() = default;
	using PrivateBaseClass = S;
	using PrivateBaseClass::PrivateBaseClass;
};
#ifdef DOXYGEN
template <typename REF> class EagerDecoratorInterface::ConstReferenceFunctionsImplDoxy : public EagerDecoratorInterface::ConstReferenceFunctionsImpl<REF>, public DecoratorInterface::ConstReferenceFunctionsImplDoxy<REF> { };
#endif

/// Intermediate helper class for EagerDecoratorInterface.
template <typename S> class EagerDecoratorInterface::ReferenceFunctionsImpl : public ConstReferenceFunctionsImpl<S>
{
public:
	ReferenceFunctionsImpl() = default;
	using PrivateBaseClass = ConstReferenceFunctionsImpl<S>;
	using PrivateBaseClass::PrivateBaseClass;
	operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongRefHandler, EagerDecoratorRef, true>::type&() const { return reinterpret_cast<const EagerDecoratorRef&>(this->GetBaseRef()); }
	operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongRefHandler, EagerDecoratorRef, false>::type&() { return reinterpret_cast<const EagerDecoratorRef&>(this->GetBaseRef()); }
/// Sets the object where all calls should be forwarded to.
/// @param[in] object							The object to decorate.
	inline typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type SetDecoratedObject(const ObjectBaseRef<typename S::PrivateReferencedType>& object) const;
/// Sets the object where all calls should be forwarded to.
/// @param[in] object							The object to decorate.
	inline typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type SetDecoratedObject(ObjectBaseRef<typename S::PrivateReferencedType>&& object) const;
};
#ifdef DOXYGEN
template <typename REF> class EagerDecoratorInterface::ReferenceFunctionsImplDoxy : public EagerDecoratorInterface::ReferenceFunctionsImpl<REF>, public DecoratorInterface::ReferenceFunctionsImplDoxy<REF> { };
#endif

/// Intermediate helper class for EagerDecoratorInterface.
template <typename S> class EagerDecoratorInterface::COWReferenceFunctionsImpl : public ConstReferenceFunctionsImpl<S>
{
public:
	COWReferenceFunctionsImpl() = default;
	using PrivateBaseClass = ConstReferenceFunctionsImpl<S>;
	using PrivateBaseClass::PrivateBaseClass;
	operator const typename maxon::RefConversionTarget<S, typename S::Handler, void, EagerDecoratorRef, false>::type&() { return reinterpret_cast<const EagerDecoratorRef&>(this->GetBaseRef()); }
/// Sets the object where all calls should be forwarded to.
/// @param[in] object							The object to decorate.
	inline typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), void, maxon::Result<void>>::type SetDecoratedObject(const ObjectBaseRef<typename S::PrivateReferencedType>& object);
/// Sets the object where all calls should be forwarded to.
/// @param[in] object							The object to decorate.
	inline typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), void, maxon::Result<void>>::type SetDecoratedObject(ObjectBaseRef<typename S::PrivateReferencedType>&& object);
};
#ifdef DOXYGEN
template <typename REF> class EagerDecoratorInterface::COWReferenceFunctionsImplDoxy : public EagerDecoratorInterface::COWReferenceFunctionsImpl<REF>, public DecoratorInterface::COWReferenceFunctionsImplDoxy<REF> { };
#endif

template <typename ST> struct EagerDecoratorInterface::ReferenceFunctions { using type = typename std::conditional<maxon::Bool(ST::type::Handler::KIND & (maxon::VALUEKIND::COW_MASK | maxon::VALUEKIND::DEEP_CONSTNESS)), COWReferenceFunctionsImpl<typename DecoratorInterface::ReferenceFunctions<ST>::type>, typename std::conditional<std::is_const<typename ST::type::PrivateReferencedType>::value, ConstReferenceFunctionsImpl<typename DecoratorInterface::ReferenceFunctions<ST>::type>, ReferenceFunctionsImpl<typename DecoratorInterface::ReferenceFunctions<ST>::type>>::type>::type; };
class EagerDecoratorInterface::Reference :
#ifdef DOXYGEN
public ReferenceFunctionsImplDoxy<EagerDecoratorRef>
#else
public maxon::ReferenceBase<ReferenceFunctions<maxon::RefBaseFunctions<maxon::DirectRef<EagerDecoratorInterface, maxon::StrongRefHandler, EagerDecoratorRef>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(Reference, maxon::ReferenceBase<ReferenceFunctions<maxon::RefBaseFunctions<maxon::DirectRef<EagerDecoratorInterface, maxon::StrongRefHandler, EagerDecoratorRef>>>>);
	using NonConst = Super::ReferenceClass;
};

/// EagerDecoratorRef is the reference class of EagerDecoratorInterface.
///
/// An eager decorator is a decorator which knows its decorated object already on construction (eagerly).
class EagerDecoratorRef : public EagerDecoratorInterface::Reference
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(EagerDecoratorRef, Reference);
};

#endif
