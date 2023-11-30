#if 1
class DecoratorRef;

struct DecoratorInterface::HasBaseDetector { template <typename I> struct Check { static const maxon::Bool value = std::is_same<I, DecoratorInterface>::value || ObjectInterface::HasBaseDetector::template Check<I>::value; static I* Cast(DecoratorInterface* ptr) { return reinterpret_cast<I*>(ptr); } }; };
struct DecoratorInterface::Hxx1
{
	class Reference;
	using ReferenceClass = DecoratorRef;
	template <template <typename...> class TEMPL> using SubstituteBases = TEMPL<ObjectInterface>;
	/// Intermediate helper class for DecoratorInterface.
	template <typename S> class ConstFn DOXYGEN_SWITCH_REVERSED(, : public S)
	{
	public:
		ConstFn() = default;
		using PrivateBaseClass = S;
		using PrivateBaseClass::PrivateBaseClass;
		using PrivateInterface = DecoratorInterface;
		using PrivateBaseClass::PrivateLookupFn;
		static ConstFn PrivateLookupFn(DecoratorInterface**);
/// @return												The decorated object.
		inline HXXADDRET2(ObjectRef) PrivateGetDecoratedObject() const;
/// @return												The decorated object.
		inline HXXADDRET2(ObjectBaseRef<maxon::details::GetPrivateReferencedType<S>>) GetDecoratedObject() const;
	};
	/// Intermediate helper class for DecoratorInterface.
	template <typename S> class Fn : public ConstFn<S>
	{
	public:
		Fn() = default;
		using PrivateBaseClass = ConstFn<S>;
		using PrivateBaseClass::PrivateBaseClass;
		using PrivateInterface = DecoratorInterface;
		using PrivateBaseClass::PrivateLookupFn;
		static Fn PrivateLookupFn(DecoratorInterface**);
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongRefHandler, DecoratorRef, true>::type&() const { return reinterpret_cast<const DecoratorRef&>(this->GetBaseRef()); }
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongRefHandler, DecoratorRef, false>::type&() { return reinterpret_cast<const DecoratorRef&>(this->GetBaseRef()); }
	};
	/// Intermediate helper class for DecoratorInterface.
	template <typename S> class COWFn : public ConstFn<S>
	{
	public:
		COWFn() = default;
		using PrivateBaseClass = ConstFn<S>;
		using PrivateBaseClass::PrivateBaseClass;
		using PrivateInterface = DecoratorInterface;
		using PrivateBaseClass::PrivateLookupFn;
		static COWFn PrivateLookupFn(DecoratorInterface**);
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, void, DecoratorRef, false>::type&() { return reinterpret_cast<const DecoratorRef&>(this->GetBaseRef()); }
	};
	template <typename ST> struct FnHelper : public std::conditional<
	maxon::Bool(ST::type::Handler::KIND & (maxon::VALUEKIND::COW_MASK | maxon::VALUEKIND::DEEP_CONSTNESS)),
	COWFn<typename ObjectInterface::Hxx1::template FnHelper<ST>::type>,
	typename std::conditional<std::is_const<typename ST::type::PrivateReferencedType>::value, ConstFn<typename ObjectInterface::Hxx1::template FnHelper<ST>::type>, Fn<typename ObjectInterface::Hxx1::template FnHelper<ST>::type>>::type
	> { };
};
class DecoratorInterface::Hxx1::Reference :
#ifdef DOXYGEN
public FnDoxy<DecoratorRef>
#else
public maxon::RefBase<Hxx1::FnHelper<maxon::RefBaseFn<maxon::DirectRef<DecoratorInterface, maxon::StrongRefHandler, DecoratorRef>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(Reference, maxon::RefBase<Hxx1::FnHelper<maxon::RefBaseFn<maxon::DirectRef<DecoratorInterface, maxon::StrongRefHandler, DecoratorRef>>>>);
	using NonConst = typename Super::ReferenceClass;
};

/// DecoratorRef is the reference class of DecoratorInterface.
///
/// This interface is implemented by decorator classes which forward calls to the base object.
class DecoratorRef : public DecoratorInterface::Hxx1::Reference
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(DecoratorRef, typename DecoratorInterface::Hxx1::Reference);
	using ConstPtr = typename DecoratorInterface::ConstPtr;
};

class EagerDecoratorRef;

struct EagerDecoratorInterface::HasBaseDetector { template <typename I> struct Check { static const maxon::Bool value = std::is_same<I, EagerDecoratorInterface>::value || DecoratorInterface::HasBaseDetector::template Check<I>::value; static I* Cast(EagerDecoratorInterface* ptr) { return reinterpret_cast<I*>(ptr); } }; };
struct EagerDecoratorInterface::Hxx1
{
	class Reference;
	using ReferenceClass = EagerDecoratorRef;
	template <template <typename...> class TEMPL> using SubstituteBases = TEMPL<DecoratorInterface>;
	/// Intermediate helper class for EagerDecoratorInterface.
	template <typename S> class Fn : public S
	{
	public:
		Fn() = default;
		using PrivateBaseClass = S;
		using PrivateBaseClass::PrivateBaseClass;
		using PrivateInterface = EagerDecoratorInterface;
		using PrivateBaseClass::PrivateLookupFn;
		static Fn PrivateLookupFn(EagerDecoratorInterface**);
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongRefHandler, EagerDecoratorRef, true>::type&() const { return reinterpret_cast<const EagerDecoratorRef&>(this->GetBaseRef()); }
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongRefHandler, EagerDecoratorRef, false>::type&() { return reinterpret_cast<const EagerDecoratorRef&>(this->GetBaseRef()); }
/// Sets the object where all calls should be forwarded to.
/// @param[in] object							The object to decorate.
		inline HXXADDRET2(void) PrivateSetDecoratedObject(const ObjectRef& object) const;
/// Sets the object where all calls should be forwarded to.
/// @param[in] object							The object to decorate.
		inline HXXADDRET2(void) SetDecoratedObject(const ObjectBaseRef<maxon::details::GetPrivateReferencedType<S>>& object) const;
/// Sets the object where all calls should be forwarded to.
/// @param[in] object							The object to decorate.
		inline HXXADDRET2(void) PrivateSetDecoratedObject(ObjectRef&& object) const;
/// Sets the object where all calls should be forwarded to.
/// @param[in] object							The object to decorate.
		inline HXXADDRET2(void) SetDecoratedObject(ObjectBaseRef<maxon::details::GetPrivateReferencedType<S>>&& object) const;
	};
	/// Intermediate helper class for EagerDecoratorInterface.
	template <typename S> class COWFn : public S
	{
	public:
		COWFn() = default;
		using PrivateBaseClass = S;
		using PrivateBaseClass::PrivateBaseClass;
		using PrivateInterface = EagerDecoratorInterface;
		using PrivateBaseClass::PrivateLookupFn;
		static COWFn PrivateLookupFn(EagerDecoratorInterface**);
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, void, EagerDecoratorRef, false>::type&() { return reinterpret_cast<const EagerDecoratorRef&>(this->GetBaseRef()); }
/// Sets the object where all calls should be forwarded to.
/// @param[in] object							The object to decorate.
		inline HXXADDRET1(void) PrivateSetDecoratedObject(const ObjectRef& object);
/// Sets the object where all calls should be forwarded to.
/// @param[in] object							The object to decorate.
		inline HXXADDRET1(void) SetDecoratedObject(const ObjectBaseRef<maxon::details::GetPrivateReferencedType<S>>& object);
/// Sets the object where all calls should be forwarded to.
/// @param[in] object							The object to decorate.
		inline HXXADDRET1(void) PrivateSetDecoratedObject(ObjectRef&& object);
/// Sets the object where all calls should be forwarded to.
/// @param[in] object							The object to decorate.
		inline HXXADDRET1(void) SetDecoratedObject(ObjectBaseRef<maxon::details::GetPrivateReferencedType<S>>&& object);
	};
	template <typename ST> struct FnHelper : public std::conditional<
	maxon::Bool(ST::type::Handler::KIND & (maxon::VALUEKIND::COW_MASK | maxon::VALUEKIND::DEEP_CONSTNESS)),
	COWFn<typename DecoratorInterface::Hxx1::template FnHelper<ST>::type>,
	typename std::conditional<std::is_const<typename ST::type::PrivateReferencedType>::value, typename DecoratorInterface::Hxx1::template FnHelper<ST>::type, Fn<typename DecoratorInterface::Hxx1::template FnHelper<ST>::type>>::type
	> { };
};
class EagerDecoratorInterface::Hxx1::Reference :
#ifdef DOXYGEN
public FnDoxy<EagerDecoratorRef>
#else
public maxon::RefBase<Hxx1::FnHelper<maxon::RefBaseFn<maxon::DirectRef<EagerDecoratorInterface, maxon::StrongRefHandler, EagerDecoratorRef>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(Reference, maxon::RefBase<Hxx1::FnHelper<maxon::RefBaseFn<maxon::DirectRef<EagerDecoratorInterface, maxon::StrongRefHandler, EagerDecoratorRef>>>>);
	using NonConst = typename Super::ReferenceClass;
};

/// EagerDecoratorRef is the reference class of EagerDecoratorInterface.
///
/// An eager decorator is a decorator which knows its decorated object already on construction (eagerly).
class EagerDecoratorRef : public EagerDecoratorInterface::Hxx1::Reference
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(EagerDecoratorRef, typename EagerDecoratorInterface::Hxx1::Reference);
	using ConstPtr = typename EagerDecoratorInterface::ConstPtr;
};

class WeakDecoratorRef;

struct WeakDecoratorInterface::HasBaseDetector { template <typename I> struct Check { static const maxon::Bool value = std::is_same<I, WeakDecoratorInterface>::value || DecoratorInterface::HasBaseDetector::template Check<I>::value; static I* Cast(WeakDecoratorInterface* ptr) { return reinterpret_cast<I*>(ptr); } }; };
struct WeakDecoratorInterface::Hxx1
{
	class Reference;
	using ReferenceClass = WeakDecoratorRef;
	template <template <typename...> class TEMPL> using SubstituteBases = TEMPL<DecoratorInterface>;
	/// Intermediate helper class for WeakDecoratorInterface.
	template <typename S> class Fn : public S
	{
	public:
		Fn() = default;
		using PrivateBaseClass = S;
		using PrivateBaseClass::PrivateBaseClass;
		using PrivateInterface = WeakDecoratorInterface;
		using PrivateBaseClass::PrivateLookupFn;
		static Fn PrivateLookupFn(WeakDecoratorInterface**);
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongRefHandler, WeakDecoratorRef, true>::type&() const { return reinterpret_cast<const WeakDecoratorRef&>(this->GetBaseRef()); }
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongRefHandler, WeakDecoratorRef, false>::type&() { return reinterpret_cast<const WeakDecoratorRef&>(this->GetBaseRef()); }
/// Sets the object where all calls should be forwarded to.
/// @param[in] object							The object to decorate.
		inline HXXADDRET2(void) PrivateSetDecoratedObject(const ObjectRef& object) const;
/// Sets the object where all calls should be forwarded to.
/// @param[in] object							The object to decorate.
		inline HXXADDRET2(void) SetDecoratedObject(const ObjectBaseRef<maxon::details::GetPrivateReferencedType<S>>& object) const;
	};
	/// Intermediate helper class for WeakDecoratorInterface.
	template <typename S> class COWFn : public S
	{
	public:
		COWFn() = default;
		using PrivateBaseClass = S;
		using PrivateBaseClass::PrivateBaseClass;
		using PrivateInterface = WeakDecoratorInterface;
		using PrivateBaseClass::PrivateLookupFn;
		static COWFn PrivateLookupFn(WeakDecoratorInterface**);
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, void, WeakDecoratorRef, false>::type&() { return reinterpret_cast<const WeakDecoratorRef&>(this->GetBaseRef()); }
/// Sets the object where all calls should be forwarded to.
/// @param[in] object							The object to decorate.
		inline HXXADDRET1(void) PrivateSetDecoratedObject(const ObjectRef& object);
/// Sets the object where all calls should be forwarded to.
/// @param[in] object							The object to decorate.
		inline HXXADDRET1(void) SetDecoratedObject(const ObjectBaseRef<maxon::details::GetPrivateReferencedType<S>>& object);
	};
	template <typename ST> struct FnHelper : public std::conditional<
	maxon::Bool(ST::type::Handler::KIND & (maxon::VALUEKIND::COW_MASK | maxon::VALUEKIND::DEEP_CONSTNESS)),
	COWFn<typename DecoratorInterface::Hxx1::template FnHelper<ST>::type>,
	typename std::conditional<std::is_const<typename ST::type::PrivateReferencedType>::value, typename DecoratorInterface::Hxx1::template FnHelper<ST>::type, Fn<typename DecoratorInterface::Hxx1::template FnHelper<ST>::type>>::type
	> { };
};
class WeakDecoratorInterface::Hxx1::Reference :
#ifdef DOXYGEN
public FnDoxy<WeakDecoratorRef>
#else
public maxon::RefBase<Hxx1::FnHelper<maxon::RefBaseFn<maxon::DirectRef<WeakDecoratorInterface, maxon::StrongRefHandler, WeakDecoratorRef>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(Reference, maxon::RefBase<Hxx1::FnHelper<maxon::RefBaseFn<maxon::DirectRef<WeakDecoratorInterface, maxon::StrongRefHandler, WeakDecoratorRef>>>>);
	using NonConst = typename Super::ReferenceClass;
};

/// WeakDecoratorRef is the reference class of WeakDecoratorInterface.
///
/// A weak decorator is a decorator which stores its decorated object as a weak reference.
class WeakDecoratorRef : public WeakDecoratorInterface::Hxx1::Reference
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(WeakDecoratorRef, typename WeakDecoratorInterface::Hxx1::Reference);
	using ConstPtr = typename WeakDecoratorInterface::ConstPtr;
};

#endif
