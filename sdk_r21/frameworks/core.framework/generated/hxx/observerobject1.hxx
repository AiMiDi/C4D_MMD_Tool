#if 1
class ObserverObjectRef;

/// @cond INTERNAL

/// @endcond

struct ObserverObjectInterface::HasBase { template <typename I> struct Check { static const maxon::Bool value = std::is_same<I, ObserverObjectInterface>::value || ObjectInterface::HasBase::template Check<I>::value; static I* Cast(ObserverObjectInterface* ptr) { return static_cast<I*>(static_cast<maxon::ObjectInterface*>(ptr)); } }; };
struct ObserverObjectInterface::Hxx1
{
	class Reference;
	using ReferenceClass = ObserverObjectRef;
	template <template <typename...> class TEMPL> using SubstituteBases = TEMPL<ObjectInterface>;
	/// Intermediate helper class for ObserverObjectInterface.
	template <typename S> class ConstReferenceFunctionsImpl DOXYGEN_SWITCH(: public S,)
	{
	public:
		ConstReferenceFunctionsImpl() = default;
		using PrivateBaseClass = S;
		using PrivateBaseClass::PrivateBaseClass;
/// @cond INTERNAL

/// @endcond

/// Returns the name of the object.
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<String>, String>::type GetName() const;
/// observable: This observable is fired as soon as the object is destroyed.
/// Please be aware of that it's not longer possible to create BaseRef to this object within this code!
/// The reason is that the Destroy is called as soon as the last reference is going to 0. As soon as you would do that it would crash!
/// -observableparam[in] sender				A pointer to the destroyed object. Do not convert this pointer into a BaseRef (see comments above).
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<maxon::ObservableRef<ObserverDestroyedDelegate>>, maxon::ObservableRef<ObserverDestroyedDelegate>>::type ObserverDestroyed() const;
/// Observable: This observable is fired as soon as anybody disconnects from a observable of this object.
/// -observableparam[in] owner				A reference to the object which owns the observable.
/// -observableparam[in] observableId	The name of the observable that has been disconnected.
/// -observableparam[in] observer			A reference to the connected object. This parameter can be zero.
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<maxon::ObservableRef<ObserverDisconnectNotifyDelegate>>, maxon::ObservableRef<ObserverDisconnectNotifyDelegate>>::type ObserverDisconnectNotify() const;
/// Observable: This observable is fired as soon as anybody connects to a observable of this object.
/// -observableparam[in] owner				A reference to the object which owns the observable.
/// -observableparam[in] observableId	The name of the observable that will be connected.
/// -observableparam[in] observer			A reference to the connected object. This parameter can be zero, e.g. if a lambda function is connected.
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<maxon::ObservableRef<ObserverConnectNotifyDelegate>>, maxon::ObservableRef<ObserverConnectNotifyDelegate>>::type ObserverConnectNotify() const;
	};
	/// Intermediate helper class for ObserverObjectInterface.
	template <typename S> class ReferenceFunctionsImpl : public ConstReferenceFunctionsImpl<S>
	{
	public:
		ReferenceFunctionsImpl() = default;
		using PrivateBaseClass = ConstReferenceFunctionsImpl<S>;
		using PrivateBaseClass::PrivateBaseClass;
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
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type RemoveSenderSignal(ObservableBaseInterface* observable) const;
/// @endcond

/// Sets the name of the object.
/// @param[in] name								New name to be set.
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type SetName(const String& name) const;
	};
	/// Intermediate helper class for ObserverObjectInterface.
	template <typename S> class COWReferenceFunctionsImpl : public ConstReferenceFunctionsImpl<S>
	{
	public:
		COWReferenceFunctionsImpl() = default;
		using PrivateBaseClass = ConstReferenceFunctionsImpl<S>;
		using PrivateBaseClass::PrivateBaseClass;
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, void, ObserverObjectRef, false>::type&() { return reinterpret_cast<const ObserverObjectRef&>(this->GetBaseRef()); }
/// @cond INTERNAL

/// Private.
/// Adds a observable to this object. AddObserver calls this function to connect observables to objects.
/// @param[in] observable					Adds the given observable to this object.
		inline Result<void> AddSenderSignal(ObservableBaseInterface* observable);
/// Private.
/// Removes a observable from this object. DisconnectAll calls this function to disconnect observables from objects.
/// @param[in] observable					Adds the given observable to this object.
		inline typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), void, maxon::Result<void>>::type RemoveSenderSignal(ObservableBaseInterface* observable);
/// @endcond

/// Sets the name of the object.
/// @param[in] name								New name to be set.
		inline typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), void, maxon::Result<void>>::type SetName(const String& name);
	};
	template <typename ST> struct ReferenceFunctionsHelper : public std::conditional<maxon::Bool(ST::type::Handler::KIND & (maxon::VALUEKIND::COW_MASK | maxon::VALUEKIND::DEEP_CONSTNESS)), COWReferenceFunctionsImpl<typename ObjectInterface::Hxx1::template ReferenceFunctionsHelper<ST>::type>, typename std::conditional<std::is_const<typename ST::type::PrivateReferencedType>::value, ConstReferenceFunctionsImpl<typename ObjectInterface::Hxx1::template ReferenceFunctionsHelper<ST>::type>, ReferenceFunctionsImpl<typename ObjectInterface::Hxx1::template ReferenceFunctionsHelper<ST>::type>>::type> { };
};
class ObserverObjectInterface::Hxx1::Reference :
#ifdef DOXYGEN
public ReferenceFunctionsImplDoxy<ObserverObjectRef>
#else
public maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<ObserverObjectInterface, maxon::StrongRefHandler, ObserverObjectRef>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(Reference, maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<ObserverObjectInterface, maxon::StrongRefHandler, ObserverObjectRef>>>>);
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
};

class ObserverObjectInterface::ObserverDestroyedDelegate : public maxon::Delegate<void(ObserverObjectInterface*)>
{
public:
	using Super = maxon::Delegate<void(ObserverObjectInterface*)>;
	MAXON_MEMBERFUNCTION_DETECTOR(HandleObserverDestroyed);
	ObserverDestroyedDelegate() = default;
	template <typename FN> static maxon::ResultOk<Super> Create(FN&& src, typename std::enable_if<HasHandleObserverDestroyed<typename maxon::Dereference<typename std::decay<FN>::type, false>::type>::value, void>::type* = nullptr) { return Super::CreateByReference(std::forward<FN>(src), &maxon::Dereference<typename std::decay<FN>::type, false>::type::HandleObserverDestroyed); }
	template <typename FN> static maxon::Result<Super> Create(FN&& src, typename std::enable_if<!HasHandleObserverDestroyed<typename maxon::Dereference<typename std::decay<FN>::type, false>::type>::value, void>::type* = nullptr){ return Super::Create(std::forward<FN>(src)); }
	using OBSERVABLECOMBINER = ObservableCombinerRunAllComponentPrivateHelper;
};

class ObserverObjectInterface::ObserverDisconnectNotifyDelegate : public maxon::Delegate<void(const ObserverObjectRef&,const Id&,const ObserverObjectRef&)>
{
public:
	using Super = maxon::Delegate<void(const ObserverObjectRef&,const Id&,const ObserverObjectRef&)>;
	MAXON_MEMBERFUNCTION_DETECTOR(HandleObserverDisconnectNotify);
	ObserverDisconnectNotifyDelegate() = default;
	template <typename FN> static maxon::ResultOk<Super> Create(FN&& src, typename std::enable_if<HasHandleObserverDisconnectNotify<typename maxon::Dereference<typename std::decay<FN>::type, false>::type>::value, void>::type* = nullptr) { return Super::CreateByReference(std::forward<FN>(src), &maxon::Dereference<typename std::decay<FN>::type, false>::type::HandleObserverDisconnectNotify); }
	template <typename FN> static maxon::Result<Super> Create(FN&& src, typename std::enable_if<!HasHandleObserverDisconnectNotify<typename maxon::Dereference<typename std::decay<FN>::type, false>::type>::value, void>::type* = nullptr){ return Super::Create(std::forward<FN>(src)); }
	using OBSERVABLECOMBINER = ObservableCombinerRunAllComponentPrivateHelper;
};

class ObserverObjectInterface::ObserverConnectNotifyDelegate : public maxon::Delegate<Result<void>(const ObserverObjectRef&,const Id&,const ObserverObjectRef&)>
{
public:
	using Super = maxon::Delegate<Result<void>(const ObserverObjectRef&,const Id&,const ObserverObjectRef&)>;
	MAXON_MEMBERFUNCTION_DETECTOR(HandleObserverConnectNotify);
	ObserverConnectNotifyDelegate() = default;
	template <typename FN> static maxon::ResultOk<Super> Create(FN&& src, typename std::enable_if<HasHandleObserverConnectNotify<typename maxon::Dereference<typename std::decay<FN>::type, false>::type>::value, void>::type* = nullptr) { return Super::CreateByReference(std::forward<FN>(src), &maxon::Dereference<typename std::decay<FN>::type, false>::type::HandleObserverConnectNotify); }
	template <typename FN> static maxon::Result<Super> Create(FN&& src, typename std::enable_if<!HasHandleObserverConnectNotify<typename maxon::Dereference<typename std::decay<FN>::type, false>::type>::value, void>::type* = nullptr){ return Super::Create(std::forward<FN>(src)); }
	using OBSERVABLECOMBINER = ObservableCombinerRunAllComponentPrivateHelper;
};

#endif
