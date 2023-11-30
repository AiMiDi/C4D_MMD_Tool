#if 1
class ObserverObjectRef;

/// @cond INTERNAL

/// @endcond

struct ObserverObjectInterface::HasBaseDetector { template <typename I> struct Check { static const maxon::Bool value = std::is_same<I, ObserverObjectInterface>::value || ObjectInterface::HasBaseDetector::template Check<I>::value; static I* Cast(ObserverObjectInterface* ptr) { return reinterpret_cast<I*>(ptr); } }; };
struct ObserverObjectInterface::Hxx1
{
	class Reference;
	using ReferenceClass = ObserverObjectRef;
	template <template <typename...> class TEMPL> using SubstituteBases = TEMPL<ObjectInterface>;
	/// Intermediate helper class for ObserverObjectInterface.
	template <typename S> class ConstFn DOXYGEN_SWITCH_REVERSED(, : public S)
	{
	public:
		ConstFn() = default;
		using PrivateBaseClass = S;
		using PrivateBaseClass::PrivateBaseClass;
		using PrivateInterface = ObserverObjectInterface;
		using PrivateBaseClass::PrivateLookupFn;
		static ConstFn PrivateLookupFn(ObserverObjectInterface**);
/// @cond INTERNAL

/// @endcond

/// Returns the name of the object.
		inline HXXADDRET2(String) GetName() const;
/// observable: This observable is fired as soon as the object is destroyed.
/// Please be aware of that it's not longer possible to create BaseRef to this object within this code!
/// The reason is that the Destroy is called as soon as the last reference is going to 0. As soon as you would do that it would crash!
/// -observableparam[in] sender				A pointer to the destroyed object. Do not convert this pointer into a BaseRef (see comments above).
		inline HXXADDRET2(maxon::ObservableRef<ObserverDestroyedDelegate>) ObserverDestroyed(Bool create) const;
/// Observable: This observable is fired as soon as anybody disconnects from a observable of this object.
/// -observableparam[in] owner				A reference to the object which owns the observable.
/// -observableparam[in] observableId	The name of the observable that has been disconnected.
/// -observableparam[in] observer			A reference to the connected object. This parameter can be zero.
		inline HXXADDRET2(maxon::ObservableRef<ObserverDisconnectNotifyDelegate>) ObserverDisconnectNotify(Bool create) const;
/// Observable: This observable is fired as soon as anybody connects to a observable of this object.
/// -observableparam[in] owner				A reference to the object which owns the observable.
/// -observableparam[in] observableId	The name of the observable that will be connected.
/// -observableparam[in] observer			A reference to the connected object. This parameter can be zero, e.g. if a lambda function is connected.
		inline HXXADDRET2(maxon::ObservableRef<ObserverConnectNotifyDelegate>) ObserverConnectNotify(Bool create) const;
	};
	/// Intermediate helper class for ObserverObjectInterface.
	template <typename S> class Fn : public ConstFn<S>
	{
	public:
		Fn() = default;
		using PrivateBaseClass = ConstFn<S>;
		using PrivateBaseClass::PrivateBaseClass;
		using PrivateInterface = ObserverObjectInterface;
		using PrivateBaseClass::PrivateLookupFn;
		static Fn PrivateLookupFn(ObserverObjectInterface**);
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongRefHandler, ObserverObjectRef, true>::type&() const { return reinterpret_cast<const ObserverObjectRef&>(this->GetBaseRef()); }
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongRefHandler, ObserverObjectRef, false>::type&() { return reinterpret_cast<const ObserverObjectRef&>(this->GetBaseRef()); }
/// @cond INTERNAL

/// Private.
/// Adds a observable to this object. AddObserver calls this function to connect observables to objects.
/// @param[in] observable					Adds the given observable to this object.
		inline Result<void> AddSenderSignal(ObservableBaseInterface* observable) const;
/// Private.
/// Removes a observable from this object. DisconnectAll calls this function to disconnect observables from objects.
/// @param[in] observable					Adds the given observable to this object.
		inline HXXADDRET2(void) RemoveSenderSignal(ObservableBaseInterface* observable) const;
/// @endcond

/// Sets the name of the object.
/// @param[in] name								New name to be set.
		inline HXXADDRET2(void) SetName(const String& name) const;
	};
	/// Intermediate helper class for ObserverObjectInterface.
	template <typename S> class COWFn : public ConstFn<S>
	{
	public:
		COWFn() = default;
		using PrivateBaseClass = ConstFn<S>;
		using PrivateBaseClass::PrivateBaseClass;
		using PrivateInterface = ObserverObjectInterface;
		using PrivateBaseClass::PrivateLookupFn;
		static COWFn PrivateLookupFn(ObserverObjectInterface**);
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, void, ObserverObjectRef, false>::type&() { return reinterpret_cast<const ObserverObjectRef&>(this->GetBaseRef()); }
/// @cond INTERNAL

/// Private.
/// Adds a observable to this object. AddObserver calls this function to connect observables to objects.
/// @param[in] observable					Adds the given observable to this object.
		inline Result<void> AddSenderSignal(ObservableBaseInterface* observable);
/// Private.
/// Removes a observable from this object. DisconnectAll calls this function to disconnect observables from objects.
/// @param[in] observable					Adds the given observable to this object.
		inline HXXADDRET1(void) RemoveSenderSignal(ObservableBaseInterface* observable);
/// @endcond

/// Sets the name of the object.
/// @param[in] name								New name to be set.
		inline HXXADDRET1(void) SetName(const String& name);
	};
	template <typename ST> struct FnHelper : public std::conditional<
	maxon::Bool(ST::type::Handler::KIND & (maxon::VALUEKIND::COW_MASK | maxon::VALUEKIND::DEEP_CONSTNESS)),
	COWFn<typename ObjectInterface::Hxx1::template FnHelper<ST>::type>,
	typename std::conditional<std::is_const<typename ST::type::PrivateReferencedType>::value, ConstFn<typename ObjectInterface::Hxx1::template FnHelper<ST>::type>, Fn<typename ObjectInterface::Hxx1::template FnHelper<ST>::type>>::type
	> { };
};
class ObserverObjectInterface::Hxx1::Reference :
#ifdef DOXYGEN
public FnDoxy<ObserverObjectRef>
#else
public maxon::RefBase<Hxx1::FnHelper<maxon::RefBaseFn<maxon::DirectRef<ObserverObjectInterface, maxon::StrongRefHandler, ObserverObjectRef>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(Reference, maxon::RefBase<Hxx1::FnHelper<maxon::RefBaseFn<maxon::DirectRef<ObserverObjectInterface, maxon::StrongRefHandler, ObserverObjectRef>>>>);
	using NonConst = typename Super::ReferenceClass;
};

/// ObserverObjectRef is the reference class of ObserverObjectInterface.
///
/// Component to allow objects to use the observable concept.
/// Object interfaces can define observables by writing:
/// @code
/// MAXON_OBSERVABLE(void, ObserverDestroyed, (ObserverObjectInterface* sender), ObservableCombinerRunAllComponent);
/// @endcode
/// A observable can be hooked up by external objects. As soon as a observable is fired all objects get this notification.
class ObserverObjectRef : public ObserverObjectInterface::Hxx1::Reference
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(ObserverObjectRef, typename ObserverObjectInterface::Hxx1::Reference);
	using ConstPtr = typename ObserverObjectInterface::ConstPtr;
};

class ObserverObjectInterface::ObserverDestroyedDelegate : public maxon::Delegate<void(ObserverObjectInterface*)>
{
public:
	using Super = maxon::Delegate<void(ObserverObjectInterface*)>;
	MAXON_MEMBERFUNCTION_DETECTOR(HandleObserverDestroyed);
	ObserverDestroyedDelegate() = default;
	template <typename FN> static maxon::ResultOk<Super> Create(FN&& src, typename std::enable_if<HasHandleObserverDestroyed<typename maxon::Dereference<typename std::decay<FN>::type, false>::type>::value, void>::type* = nullptr) { return Super::CreateByReference(std::forward<FN>(src), &maxon::Dereference<typename std::decay<FN>::type, false>::type::HandleObserverDestroyed); }
	template <typename FN> static maxon::Result<Super> Create(FN&& src, typename std::enable_if<!HasHandleObserverDestroyed<typename maxon::Dereference<typename std::decay<FN>::type, false>::type>::value, void>::type* = nullptr){ return Super::Create(std::forward<FN>(src)); }
	using OBSERVABLECOMBINER = ObservableCombinerRunAllComponent_PrivateHelper;
};

class ObserverObjectInterface::ObserverDisconnectNotifyDelegate : public maxon::Delegate<void(const ObserverObjectRef&,const Id&,const ObserverObjectRef&)>
{
public:
	using Super = maxon::Delegate<void(const ObserverObjectRef&,const Id&,const ObserverObjectRef&)>;
	MAXON_MEMBERFUNCTION_DETECTOR(HandleObserverDisconnectNotify);
	ObserverDisconnectNotifyDelegate() = default;
	template <typename FN> static maxon::ResultOk<Super> Create(FN&& src, typename std::enable_if<HasHandleObserverDisconnectNotify<typename maxon::Dereference<typename std::decay<FN>::type, false>::type>::value, void>::type* = nullptr) { return Super::CreateByReference(std::forward<FN>(src), &maxon::Dereference<typename std::decay<FN>::type, false>::type::HandleObserverDisconnectNotify); }
	template <typename FN> static maxon::Result<Super> Create(FN&& src, typename std::enable_if<!HasHandleObserverDisconnectNotify<typename maxon::Dereference<typename std::decay<FN>::type, false>::type>::value, void>::type* = nullptr){ return Super::Create(std::forward<FN>(src)); }
	using OBSERVABLECOMBINER = ObservableCombinerRunAllComponent_PrivateHelper;
};

class ObserverObjectInterface::ObserverConnectNotifyDelegate : public maxon::Delegate<Result<void>(const ObserverObjectRef&,const Id&,const ObserverObjectRef&)>
{
public:
	using Super = maxon::Delegate<Result<void>(const ObserverObjectRef&,const Id&,const ObserverObjectRef&)>;
	MAXON_MEMBERFUNCTION_DETECTOR(HandleObserverConnectNotify);
	ObserverConnectNotifyDelegate() = default;
	template <typename FN> static maxon::ResultOk<Super> Create(FN&& src, typename std::enable_if<HasHandleObserverConnectNotify<typename maxon::Dereference<typename std::decay<FN>::type, false>::type>::value, void>::type* = nullptr) { return Super::CreateByReference(std::forward<FN>(src), &maxon::Dereference<typename std::decay<FN>::type, false>::type::HandleObserverConnectNotify); }
	template <typename FN> static maxon::Result<Super> Create(FN&& src, typename std::enable_if<!HasHandleObserverConnectNotify<typename maxon::Dereference<typename std::decay<FN>::type, false>::type>::value, void>::type* = nullptr){ return Super::Create(std::forward<FN>(src)); }
	using OBSERVABLECOMBINER = ObservableCombinerRunAllComponent_PrivateHelper;
};

#endif
