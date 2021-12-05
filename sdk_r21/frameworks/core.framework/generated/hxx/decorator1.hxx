#if 1
class DecoratorRef;

struct DecoratorInterface::HasBase { template <typename I> struct Check { static const maxon::Bool value = std::is_same<I, DecoratorInterface>::value || ObjectInterface::HasBase::template Check<I>::value; static I* Cast(DecoratorInterface* ptr) { return static_cast<I*>(static_cast<maxon::ObjectInterface*>(ptr)); } }; };
struct DecoratorInterface::Hxx1
{
	class Reference;
	using ReferenceClass = DecoratorRef;
	template <template <typename...> class TEMPL> using SubstituteBases = TEMPL<ObjectInterface>;
	/// Intermediate helper class for DecoratorInterface.
	template <typename S> class ConstReferenceFunctionsImpl DOXYGEN_SWITCH(: public S,)
	{
	public:
		ConstReferenceFunctionsImpl() = default;
		using PrivateBaseClass = S;
		using PrivateBaseClass::PrivateBaseClass;
/// @return												The decorated object.
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<ObjectRef>, ObjectRef>::type PrivateGetDecoratedObject() const;
/// @return												The decorated object.
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<ObjectBaseRef<maxon::details::GetPrivateReferencedType<S>>>, ObjectBaseRef<maxon::details::GetPrivateReferencedType<S>>>::type GetDecoratedObject() const;
	};
	/// Intermediate helper class for DecoratorInterface.
	template <typename S> class ReferenceFunctionsImpl : public ConstReferenceFunctionsImpl<S>
	{
	public:
		ReferenceFunctionsImpl() = default;
		using PrivateBaseClass = ConstReferenceFunctionsImpl<S>;
		using PrivateBaseClass::PrivateBaseClass;
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongRefHandler, DecoratorRef, true>::type&() const { return reinterpret_cast<const DecoratorRef&>(this->GetBaseRef()); }
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongRefHandler, DecoratorRef, false>::type&() { return reinterpret_cast<const DecoratorRef&>(this->GetBaseRef()); }
	};
	/// Intermediate helper class for DecoratorInterface.
	template <typename S> class COWReferenceFunctionsImpl : public ConstReferenceFunctionsImpl<S>
	{
	public:
		COWReferenceFunctionsImpl() = default;
		using PrivateBaseClass = ConstReferenceFunctionsImpl<S>;
		using PrivateBaseClass::PrivateBaseClass;
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, void, DecoratorRef, false>::type&() { return reinterpret_cast<const DecoratorRef&>(this->GetBaseRef()); }
	};
	template <typename ST> struct ReferenceFunctionsHelper : public std::conditional<maxon::Bool(ST::type::Handler::KIND & (maxon::VALUEKIND::COW_MASK | maxon::VALUEKIND::DEEP_CONSTNESS)), COWReferenceFunctionsImpl<typename ObjectInterface::Hxx1::template ReferenceFunctionsHelper<ST>::type>, typename std::conditional<std::is_const<typename ST::type::PrivateReferencedType>::value, ConstReferenceFunctionsImpl<typename ObjectInterface::Hxx1::template ReferenceFunctionsHelper<ST>::type>, ReferenceFunctionsImpl<typename ObjectInterface::Hxx1::template ReferenceFunctionsHelper<ST>::type>>::type> { };
};
class DecoratorInterface::Hxx1::Reference :
#ifdef DOXYGEN
public ReferenceFunctionsImplDoxy<DecoratorRef>
#else
public maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<DecoratorInterface, maxon::StrongRefHandler, DecoratorRef>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(Reference, maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<DecoratorInterface, maxon::StrongRefHandler, DecoratorRef>>>>);
	using NonConst = typename Super::ReferenceClass;
};

/// DecoratorRef is the reference class of DecoratorInterface.
///
/// This interface is implemented by decorator classes which forward calls to the base object.
class DecoratorRef : public DecoratorInterface::Hxx1::Reference
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(DecoratorRef, typename DecoratorInterface::Hxx1::Reference);
};

class EagerDecoratorRef;

struct EagerDecoratorInterface::HasBase { template <typename I> struct Check { static const maxon::Bool value = std::is_same<I, EagerDecoratorInterface>::value || DecoratorInterface::HasBase::template Check<I>::value; static I* Cast(EagerDecoratorInterface* ptr) { return static_cast<I*>(static_cast<maxon::ObjectInterface*>(ptr)); } }; };
struct EagerDecoratorInterface::Hxx1
{
	class Reference;
	using ReferenceClass = EagerDecoratorRef;
	template <template <typename...> class TEMPL> using SubstituteBases = TEMPL<DecoratorInterface>;
	/// Intermediate helper class for EagerDecoratorInterface.
	template <typename S> class ConstReferenceFunctionsImpl DOXYGEN_SWITCH(: public S,)
	{
	public:
		ConstReferenceFunctionsImpl() = default;
		using PrivateBaseClass = S;
		using PrivateBaseClass::PrivateBaseClass;
	};
	/// Intermediate helper class for EagerDecoratorInterface.
	template <typename S> class ReferenceFunctionsImpl : public ConstReferenceFunctionsImpl<S>
	{
	public:
		ReferenceFunctionsImpl() = default;
		using PrivateBaseClass = ConstReferenceFunctionsImpl<S>;
		using PrivateBaseClass::PrivateBaseClass;
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongRefHandler, EagerDecoratorRef, true>::type&() const { return reinterpret_cast<const EagerDecoratorRef&>(this->GetBaseRef()); }
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongRefHandler, EagerDecoratorRef, false>::type&() { return reinterpret_cast<const EagerDecoratorRef&>(this->GetBaseRef()); }
/// Sets the object where all calls should be forwarded to.
/// @param[in] object							The object to decorate.
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type PrivateSetDecoratedObject(const ObjectRef& object) const;
/// Sets the object where all calls should be forwarded to.
/// @param[in] object							The object to decorate.
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type SetDecoratedObject(const ObjectBaseRef<maxon::details::GetPrivateReferencedType<S>>& object) const;
/// Sets the object where all calls should be forwarded to.
/// @param[in] object							The object to decorate.
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type PrivateSetDecoratedObject(ObjectRef&& object) const;
/// Sets the object where all calls should be forwarded to.
/// @param[in] object							The object to decorate.
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type SetDecoratedObject(ObjectBaseRef<maxon::details::GetPrivateReferencedType<S>>&& object) const;
	};
	/// Intermediate helper class for EagerDecoratorInterface.
	template <typename S> class COWReferenceFunctionsImpl : public ConstReferenceFunctionsImpl<S>
	{
	public:
		COWReferenceFunctionsImpl() = default;
		using PrivateBaseClass = ConstReferenceFunctionsImpl<S>;
		using PrivateBaseClass::PrivateBaseClass;
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, void, EagerDecoratorRef, false>::type&() { return reinterpret_cast<const EagerDecoratorRef&>(this->GetBaseRef()); }
/// Sets the object where all calls should be forwarded to.
/// @param[in] object							The object to decorate.
		inline typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), void, maxon::Result<void>>::type PrivateSetDecoratedObject(const ObjectRef& object);
/// Sets the object where all calls should be forwarded to.
/// @param[in] object							The object to decorate.
		inline typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), void, maxon::Result<void>>::type SetDecoratedObject(const ObjectBaseRef<maxon::details::GetPrivateReferencedType<S>>& object);
/// Sets the object where all calls should be forwarded to.
/// @param[in] object							The object to decorate.
		inline typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), void, maxon::Result<void>>::type PrivateSetDecoratedObject(ObjectRef&& object);
/// Sets the object where all calls should be forwarded to.
/// @param[in] object							The object to decorate.
		inline typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), void, maxon::Result<void>>::type SetDecoratedObject(ObjectBaseRef<maxon::details::GetPrivateReferencedType<S>>&& object);
	};
	template <typename ST> struct ReferenceFunctionsHelper : public std::conditional<maxon::Bool(ST::type::Handler::KIND & (maxon::VALUEKIND::COW_MASK | maxon::VALUEKIND::DEEP_CONSTNESS)), COWReferenceFunctionsImpl<typename DecoratorInterface::Hxx1::template ReferenceFunctionsHelper<ST>::type>, typename std::conditional<std::is_const<typename ST::type::PrivateReferencedType>::value, ConstReferenceFunctionsImpl<typename DecoratorInterface::Hxx1::template ReferenceFunctionsHelper<ST>::type>, ReferenceFunctionsImpl<typename DecoratorInterface::Hxx1::template ReferenceFunctionsHelper<ST>::type>>::type> { };
};
class EagerDecoratorInterface::Hxx1::Reference :
#ifdef DOXYGEN
public ReferenceFunctionsImplDoxy<EagerDecoratorRef>
#else
public maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<EagerDecoratorInterface, maxon::StrongRefHandler, EagerDecoratorRef>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(Reference, maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<EagerDecoratorInterface, maxon::StrongRefHandler, EagerDecoratorRef>>>>);
	using NonConst = typename Super::ReferenceClass;
};

/// EagerDecoratorRef is the reference class of EagerDecoratorInterface.
///
/// An eager decorator is a decorator which knows its decorated object already on construction (eagerly).
class EagerDecoratorRef : public EagerDecoratorInterface::Hxx1::Reference
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(EagerDecoratorRef, typename EagerDecoratorInterface::Hxx1::Reference);
};

class WeakDecoratorRef;

struct WeakDecoratorInterface::HasBase { template <typename I> struct Check { static const maxon::Bool value = std::is_same<I, WeakDecoratorInterface>::value || DecoratorInterface::HasBase::template Check<I>::value; static I* Cast(WeakDecoratorInterface* ptr) { return static_cast<I*>(static_cast<maxon::ObjectInterface*>(ptr)); } }; };
struct WeakDecoratorInterface::Hxx1
{
	class Reference;
	using ReferenceClass = WeakDecoratorRef;
	template <template <typename...> class TEMPL> using SubstituteBases = TEMPL<DecoratorInterface>;
	/// Intermediate helper class for WeakDecoratorInterface.
	template <typename S> class ConstReferenceFunctionsImpl DOXYGEN_SWITCH(: public S,)
	{
	public:
		ConstReferenceFunctionsImpl() = default;
		using PrivateBaseClass = S;
		using PrivateBaseClass::PrivateBaseClass;
	};
	/// Intermediate helper class for WeakDecoratorInterface.
	template <typename S> class ReferenceFunctionsImpl : public ConstReferenceFunctionsImpl<S>
	{
	public:
		ReferenceFunctionsImpl() = default;
		using PrivateBaseClass = ConstReferenceFunctionsImpl<S>;
		using PrivateBaseClass::PrivateBaseClass;
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongRefHandler, WeakDecoratorRef, true>::type&() const { return reinterpret_cast<const WeakDecoratorRef&>(this->GetBaseRef()); }
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongRefHandler, WeakDecoratorRef, false>::type&() { return reinterpret_cast<const WeakDecoratorRef&>(this->GetBaseRef()); }
/// Sets the object where all calls should be forwarded to.
/// @param[in] object							The object to decorate.
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type PrivateSetDecoratedObject(const ObjectRef& object) const;
/// Sets the object where all calls should be forwarded to.
/// @param[in] object							The object to decorate.
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type SetDecoratedObject(const ObjectBaseRef<maxon::details::GetPrivateReferencedType<S>>& object) const;
	};
	/// Intermediate helper class for WeakDecoratorInterface.
	template <typename S> class COWReferenceFunctionsImpl : public ConstReferenceFunctionsImpl<S>
	{
	public:
		COWReferenceFunctionsImpl() = default;
		using PrivateBaseClass = ConstReferenceFunctionsImpl<S>;
		using PrivateBaseClass::PrivateBaseClass;
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, void, WeakDecoratorRef, false>::type&() { return reinterpret_cast<const WeakDecoratorRef&>(this->GetBaseRef()); }
/// Sets the object where all calls should be forwarded to.
/// @param[in] object							The object to decorate.
		inline typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), void, maxon::Result<void>>::type PrivateSetDecoratedObject(const ObjectRef& object);
/// Sets the object where all calls should be forwarded to.
/// @param[in] object							The object to decorate.
		inline typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), void, maxon::Result<void>>::type SetDecoratedObject(const ObjectBaseRef<maxon::details::GetPrivateReferencedType<S>>& object);
	};
	template <typename ST> struct ReferenceFunctionsHelper : public std::conditional<maxon::Bool(ST::type::Handler::KIND & (maxon::VALUEKIND::COW_MASK | maxon::VALUEKIND::DEEP_CONSTNESS)), COWReferenceFunctionsImpl<typename DecoratorInterface::Hxx1::template ReferenceFunctionsHelper<ST>::type>, typename std::conditional<std::is_const<typename ST::type::PrivateReferencedType>::value, ConstReferenceFunctionsImpl<typename DecoratorInterface::Hxx1::template ReferenceFunctionsHelper<ST>::type>, ReferenceFunctionsImpl<typename DecoratorInterface::Hxx1::template ReferenceFunctionsHelper<ST>::type>>::type> { };
};
class WeakDecoratorInterface::Hxx1::Reference :
#ifdef DOXYGEN
public ReferenceFunctionsImplDoxy<WeakDecoratorRef>
#else
public maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<WeakDecoratorInterface, maxon::StrongRefHandler, WeakDecoratorRef>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(Reference, maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<WeakDecoratorInterface, maxon::StrongRefHandler, WeakDecoratorRef>>>>);
	using NonConst = typename Super::ReferenceClass;
};

/// WeakDecoratorRef is the reference class of WeakDecoratorInterface.
///
/// A weak decorator is a decorator which stores its decorated object as a weak reference.
class WeakDecoratorRef : public WeakDecoratorInterface::Hxx1::Reference
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(WeakDecoratorRef, typename WeakDecoratorInterface::Hxx1::Reference);
};

#endif
