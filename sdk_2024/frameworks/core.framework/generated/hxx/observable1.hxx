#if 1
class FunctionBaseRef;

struct FunctionBaseInterface::HasBaseDetector { template <typename I> struct Check { static const maxon::Bool value = std::is_same<I, FunctionBaseInterface>::value || ObjectInterface::HasBaseDetector::template Check<I>::value; static I* Cast(FunctionBaseInterface* ptr) { return reinterpret_cast<I*>(ptr); } }; };
struct FunctionBaseInterface::Hxx1
{
	class Reference;
	using ReferenceClass = FunctionBaseRef;
	template <template <typename...> class TEMPL> using SubstituteBases = TEMPL<ObjectInterface>;
	/// Intermediate helper class for FunctionBaseInterface.
	template <typename S> class ConstFn DOXYGEN_SWITCH_REVERSED(, : public S)
	{
	public:
		ConstFn() = default;
		using PrivateBaseClass = S;
		using PrivateBaseClass::PrivateBaseClass;
		using PrivateInterface = FunctionBaseInterface;
		using PrivateBaseClass::PrivateLookupFn;
		static ConstFn PrivateLookupFn(FunctionBaseInterface**);
		inline HXXADDRET2(void) GetOwner(ObserverObjectRef& res) const;
		inline HXXADDRET2(void) GetObserver(ObserverObjectRef& res) const;
/// Internal function. Do not use this pointer to call anything. Just compare this value to ObserverObjectInterface*.
		inline HXXADDRET2(const void*) GetObserverPointer() const;
	};
	/// Intermediate helper class for FunctionBaseInterface.
	template <typename S> class Fn : public ConstFn<S>
	{
	public:
		Fn() = default;
		using PrivateBaseClass = ConstFn<S>;
		using PrivateBaseClass::PrivateBaseClass;
		using PrivateInterface = FunctionBaseInterface;
		using PrivateBaseClass::PrivateLookupFn;
		static Fn PrivateLookupFn(FunctionBaseInterface**);
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongRefHandler, FunctionBaseRef, true>::type&() const { return reinterpret_cast<const FunctionBaseRef&>(this->GetBaseRef()); }
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongRefHandler, FunctionBaseRef, false>::type&() { return reinterpret_cast<const FunctionBaseRef&>(this->GetBaseRef()); }
/// Initializes the object for execution on JOBQUEUE_NONE.
/// @param[in] forwardFunction		Pointer to a function which unpacks the parameters and forwards them to the delegate: static maxon::Result<maxon::Data> Execute(const DelegateBase&, const maxon::Block<maxon::ConstDataPtr>&)
/// @param[in] function						Delegate of the observer (only base class is required here).
/// @return												OK on success.
		inline Result<void> Init(const ObservableForwardFunction forwardFunction, DelegateBase&& function) const;
/// Initializes the object for execution on a dedicated queue.
/// @param[in] forwardFunction		Pointer to a function which unpacks the parameters and forwards them to the delegate: static maxon::Result<maxon::Data> Execute(const DelegateBase&, const maxon::Block<maxon::ConstDataPtr>&)
/// @param[in] function						Delegate of the observer (only base class is required here).
/// @param[in] queue							Queue for the execution of the observer,
/// @return												OK on success.
		inline Result<void> Init(const ObservableForwardFunction forwardFunction, DelegateBase&& function, const JobQueueRef& queue) const;
/// @param[in] owner							...
/// @param[in] observer						...
		inline HXXADDRET2(void) Set(ObserverObjectInterface* owner, ObserverObjectInterface* observer) const;
/// @param[in] args								Block with a number of arguments.
		inline Result<Data> Execute(const Block<const ConstDataPtr>& args) const;
	};
	/// Intermediate helper class for FunctionBaseInterface.
	template <typename S> class COWFn : public ConstFn<S>
	{
	public:
		COWFn() = default;
		using PrivateBaseClass = ConstFn<S>;
		using PrivateBaseClass::PrivateBaseClass;
		using PrivateInterface = FunctionBaseInterface;
		using PrivateBaseClass::PrivateLookupFn;
		static COWFn PrivateLookupFn(FunctionBaseInterface**);
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, void, FunctionBaseRef, false>::type&() { return reinterpret_cast<const FunctionBaseRef&>(this->GetBaseRef()); }
/// Initializes the object for execution on JOBQUEUE_NONE.
/// @param[in] forwardFunction		Pointer to a function which unpacks the parameters and forwards them to the delegate: static maxon::Result<maxon::Data> Execute(const DelegateBase&, const maxon::Block<maxon::ConstDataPtr>&)
/// @param[in] function						Delegate of the observer (only base class is required here).
/// @return												OK on success.
		inline Result<void> Init(const ObservableForwardFunction forwardFunction, DelegateBase&& function);
/// Initializes the object for execution on a dedicated queue.
/// @param[in] forwardFunction		Pointer to a function which unpacks the parameters and forwards them to the delegate: static maxon::Result<maxon::Data> Execute(const DelegateBase&, const maxon::Block<maxon::ConstDataPtr>&)
/// @param[in] function						Delegate of the observer (only base class is required here).
/// @param[in] queue							Queue for the execution of the observer,
/// @return												OK on success.
		inline Result<void> Init(const ObservableForwardFunction forwardFunction, DelegateBase&& function, const JobQueueRef& queue);
/// @param[in] owner							...
/// @param[in] observer						...
		inline HXXADDRET1(void) Set(ObserverObjectInterface* owner, ObserverObjectInterface* observer);
/// @param[in] args								Block with a number of arguments.
		inline Result<Data> Execute(const Block<const ConstDataPtr>& args);
	};
	template <typename ST> struct FnHelper : public std::conditional<
	maxon::Bool(ST::type::Handler::KIND & (maxon::VALUEKIND::COW_MASK | maxon::VALUEKIND::DEEP_CONSTNESS)),
	COWFn<typename ObjectInterface::Hxx1::template FnHelper<ST>::type>,
	typename std::conditional<std::is_const<typename ST::type::PrivateReferencedType>::value, ConstFn<typename ObjectInterface::Hxx1::template FnHelper<ST>::type>, Fn<typename ObjectInterface::Hxx1::template FnHelper<ST>::type>>::type
	> { };
};
class FunctionBaseInterface::Hxx1::Reference :
#ifdef DOXYGEN
public FnDoxy<FunctionBaseRef>
#else
public maxon::RefBase<Hxx1::FnHelper<maxon::RefBaseFn<maxon::DirectRef<FunctionBaseInterface, maxon::StrongRefHandler, FunctionBaseRef>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(Reference, maxon::RefBase<Hxx1::FnHelper<maxon::RefBaseFn<maxon::DirectRef<FunctionBaseInterface, maxon::StrongRefHandler, FunctionBaseRef>>>>);
	using NonConst = typename Super::ReferenceClass;
};

/// FunctionBaseRef is the reference class of FunctionBaseInterface.
///
/// This object stores the callback function for observable notifications.
class FunctionBaseRef : public FunctionBaseInterface::Hxx1::Reference
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(FunctionBaseRef, typename FunctionBaseInterface::Hxx1::Reference);
	using ConstPtr = typename FunctionBaseInterface::ConstPtr;
};

class CombinerRef;

struct CombinerInterface::HasBaseDetector { template <typename I> struct Check { static const maxon::Bool value = std::is_same<I, CombinerInterface>::value || ObjectInterface::HasBaseDetector::template Check<I>::value; static I* Cast(CombinerInterface* ptr) { return reinterpret_cast<I*>(ptr); } }; };
struct CombinerInterface::Hxx1
{
	class Reference;
	using ReferenceClass = CombinerRef;
	template <template <typename...> class TEMPL> using SubstituteBases = TEMPL<ObjectInterface>;
	/// Intermediate helper class for CombinerInterface.
	template <typename S> class ConstFn DOXYGEN_SWITCH_REVERSED(, : public S)
	{
	public:
		ConstFn() = default;
		using PrivateBaseClass = S;
		using PrivateBaseClass::PrivateBaseClass;
		using PrivateInterface = CombinerInterface;
		using PrivateBaseClass::PrivateLookupFn;
		static ConstFn PrivateLookupFn(CombinerInterface**);
/// Called first before the observable notification starts. In general the start result value will be copied to the result value.
/// @param[out] combinedRes				Receives the start value.
/// @return												OK on success.
		inline Result<void> InitCombine(Result<Data>& combinedRes) const;
/// Called after each notification. This function defines how the results are combined together.
/// The return value controls if following subscribers should be called.
/// @param[in,out] combinedRes		Contains the last result and receives the new result.
/// @param[in] newRes							The new result that needs to be combined with combinedRes.
/// @return												True if the the next subscriber should be called. False if the notification should stop here.
		inline Result<Bool> CombineResult(Result<Data>& combinedRes, Result<Data>&& newRes) const;
	};
	/// Intermediate helper class for CombinerInterface.
	template <typename S> class Fn : public ConstFn<S>
	{
	public:
		Fn() = default;
		using PrivateBaseClass = ConstFn<S>;
		using PrivateBaseClass::PrivateBaseClass;
		using PrivateInterface = CombinerInterface;
		using PrivateBaseClass::PrivateLookupFn;
		static Fn PrivateLookupFn(CombinerInterface**);
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongRefHandler, CombinerRef, true>::type&() const { return reinterpret_cast<const CombinerRef&>(this->GetBaseRef()); }
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongRefHandler, CombinerRef, false>::type&() { return reinterpret_cast<const CombinerRef&>(this->GetBaseRef()); }
	};
	/// Intermediate helper class for CombinerInterface.
	template <typename S> class COWFn : public ConstFn<S>
	{
	public:
		COWFn() = default;
		using PrivateBaseClass = ConstFn<S>;
		using PrivateBaseClass::PrivateBaseClass;
		using PrivateInterface = CombinerInterface;
		using PrivateBaseClass::PrivateLookupFn;
		static COWFn PrivateLookupFn(CombinerInterface**);
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, void, CombinerRef, false>::type&() { return reinterpret_cast<const CombinerRef&>(this->GetBaseRef()); }
	};
	template <typename ST> struct FnHelper : public std::conditional<
	maxon::Bool(ST::type::Handler::KIND & (maxon::VALUEKIND::COW_MASK | maxon::VALUEKIND::DEEP_CONSTNESS)),
	COWFn<typename ObjectInterface::Hxx1::template FnHelper<ST>::type>,
	typename std::conditional<std::is_const<typename ST::type::PrivateReferencedType>::value, ConstFn<typename ObjectInterface::Hxx1::template FnHelper<ST>::type>, Fn<typename ObjectInterface::Hxx1::template FnHelper<ST>::type>>::type
	> { };
};
class CombinerInterface::Hxx1::Reference :
#ifdef DOXYGEN
public FnDoxy<CombinerRef>
#else
public maxon::RefBase<Hxx1::FnHelper<maxon::RefBaseFn<maxon::DirectRef<CombinerInterface, maxon::StrongRefHandler, CombinerRef>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(Reference, maxon::RefBase<Hxx1::FnHelper<maxon::RefBaseFn<maxon::DirectRef<CombinerInterface, maxon::StrongRefHandler, CombinerRef>>>>);
	using NonConst = typename Super::ReferenceClass;
};

/// CombinerRef is the reference class of CombinerInterface.
///
/// Combiners allow to combine the result of multiple observable subscribers.
/// There are some default implementations: see ObservableCombinerRunAllComponent, ObservableCombinerRunAllBoolOrComponent.
class CombinerRef : public CombinerInterface::Hxx1::Reference
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(CombinerRef, typename CombinerInterface::Hxx1::Reference);
	using ConstPtr = typename CombinerInterface::ConstPtr;
};

class ObservableBaseRef;

struct ObservableBaseInterface::HasBaseDetector { template <typename I> struct Check { static const maxon::Bool value = std::is_same<I, ObservableBaseInterface>::value || ObjectInterface::HasBaseDetector::template Check<I>::value; static I* Cast(ObservableBaseInterface* ptr) { return reinterpret_cast<I*>(ptr); } }; };
struct ObservableBaseInterface::Hxx1
{
	class Reference;
	using ReferenceClass = ObservableBaseRef;
	template <template <typename...> class TEMPL> using SubstituteBases = TEMPL<ObjectInterface>;
	/// Intermediate helper class for ObservableBaseInterface.
	template <typename S> class ConstFn DOXYGEN_SWITCH_REVERSED(, : public S)
	{
	public:
		ConstFn() = default;
		using PrivateBaseClass = S;
		using PrivateBaseClass::PrivateBaseClass;
		using PrivateInterface = ObservableBaseInterface;
		using PrivateBaseClass::PrivateLookupFn;
		static ConstFn PrivateLookupFn(ObservableBaseInterface**);
/// This function returns the Id given in the Init function.
		inline HXXADDRET2(Id) GetObservableId() const;
/// Send a notification to all subscribers.
/// @param[in] args								Arguments packed into a Block<ConstDataPtr>.
/// @return												The combined result of the observable. See CombinerInterface.
		inline Result<Data> Notify(const Block<const ConstDataPtr>& args) const;
/// Gets the owner of the observable.
/// @return												The owner of the observable.
		inline HXXADDRET2(ObserverObjectInterface*) GetOwner() const;
	};
	/// Intermediate helper class for ObservableBaseInterface.
	template <typename S> class Fn : public ConstFn<S>
	{
	public:
		Fn() = default;
		using PrivateBaseClass = ConstFn<S>;
		using PrivateBaseClass::PrivateBaseClass;
		using PrivateInterface = ObservableBaseInterface;
		using PrivateBaseClass::PrivateLookupFn;
		static Fn PrivateLookupFn(ObservableBaseInterface**);
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongRefHandler, ObservableBaseRef, true>::type&() const { return reinterpret_cast<const ObservableBaseRef&>(this->GetBaseRef()); }
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongRefHandler, ObservableBaseRef, false>::type&() { return reinterpret_cast<const ObservableBaseRef&>(this->GetBaseRef()); }
/// This function needs to be called in the implementation InitComponent() function.
/// @param[in] owner							Pointer to the observable owner.
/// @param[in] observableName			Name of the observable. This observable name is sent via ObserverConnectNotify/ObserverDisconnectNotify.
/// @return												True if the function operates successful.
		inline Result<void> Init(ObserverObjectInterface* owner, const Id& observableName) const;
/// This function needs to be called in the implementation FreeComponent() function.
/// Don't use this function directly, only for internal use!
/// @param[in] observer						Nullptr if all observables should be disconnected. If a object is given only this specific observables are disconnected.
/// @param[in] pass								Internal use only.
		inline HXXADDRET2(void) PrivateDisconnectAll(ObserverObjectInterface* observer, Int pass) const;
/// This function needs to be called in the implementation FreeComponent() function.
/// @param[in] observer						Nullptr if all observables should be disconnected. If a object is given only this specific observables are disconnected.
		inline HXXADDRET2(void) Disconnect(ObserverObjectInterface* observer) const;
/// This function needs to be called in the implementation FreeComponent() function.
		inline HXXADDRET2(void) Free() const;
/// Add a subscriber to the observable.
/// Notes: the implementation need to take the ownership of the observerFunction only if the function succeeds.
/// in the case of an error (returning nullptr) the wrapper class outside frees the memory!
/// @param[in] observer						Pointer to a observer object. This parameter can be nullptr.
/// @param[in] observerFunction		Function object that is stored with in the observable.
/// @param[in] priority						Priority in execution. Use ADDOBSERVER_DEFAULTPRIORITY as default. Greater values will execute later.
/// @return												OK on success.
		inline Result<void> AddObserver(ObserverObjectInterface* observer, const FunctionBaseRef& observerFunction, Int priority = ADDOBSERVER_DEFAULTPRIORITY) const;
/// Remove a observable entry from the subscriber list.
/// @param[in] observerEntry			Entry to remove.
		inline HXXADDRET2(Bool) RemoveObserver(const FunctionBaseRef& observerEntry) const;
/// Set true to Notify() in inverse order.
		inline HXXADDRET2(void) SetInverseNotification(Bool inverse) const;
/// Gets the number of observers.
/// @return												The number of observers.
		inline HXXADDRET2(Int) GetObserverCount() const;
	};
	/// Intermediate helper class for ObservableBaseInterface.
	template <typename S> class COWFn : public ConstFn<S>
	{
	public:
		COWFn() = default;
		using PrivateBaseClass = ConstFn<S>;
		using PrivateBaseClass::PrivateBaseClass;
		using PrivateInterface = ObservableBaseInterface;
		using PrivateBaseClass::PrivateLookupFn;
		static COWFn PrivateLookupFn(ObservableBaseInterface**);
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, void, ObservableBaseRef, false>::type&() { return reinterpret_cast<const ObservableBaseRef&>(this->GetBaseRef()); }
/// This function needs to be called in the implementation InitComponent() function.
/// @param[in] owner							Pointer to the observable owner.
/// @param[in] observableName			Name of the observable. This observable name is sent via ObserverConnectNotify/ObserverDisconnectNotify.
/// @return												True if the function operates successful.
		inline Result<void> Init(ObserverObjectInterface* owner, const Id& observableName);
/// This function needs to be called in the implementation FreeComponent() function.
/// Don't use this function directly, only for internal use!
/// @param[in] observer						Nullptr if all observables should be disconnected. If a object is given only this specific observables are disconnected.
/// @param[in] pass								Internal use only.
		inline HXXADDRET1(void) PrivateDisconnectAll(ObserverObjectInterface* observer, Int pass);
/// This function needs to be called in the implementation FreeComponent() function.
/// @param[in] observer						Nullptr if all observables should be disconnected. If a object is given only this specific observables are disconnected.
		inline HXXADDRET1(void) Disconnect(ObserverObjectInterface* observer);
/// This function needs to be called in the implementation FreeComponent() function.
		inline HXXADDRET1(void) Free();
/// Add a subscriber to the observable.
/// Notes: the implementation need to take the ownership of the observerFunction only if the function succeeds.
/// in the case of an error (returning nullptr) the wrapper class outside frees the memory!
/// @param[in] observer						Pointer to a observer object. This parameter can be nullptr.
/// @param[in] observerFunction		Function object that is stored with in the observable.
/// @param[in] priority						Priority in execution. Use ADDOBSERVER_DEFAULTPRIORITY as default. Greater values will execute later.
/// @return												OK on success.
		inline Result<void> AddObserver(ObserverObjectInterface* observer, const FunctionBaseRef& observerFunction, Int priority = ADDOBSERVER_DEFAULTPRIORITY);
/// Remove a observable entry from the subscriber list.
/// @param[in] observerEntry			Entry to remove.
		inline HXXADDRET1(Bool) RemoveObserver(const FunctionBaseRef& observerEntry);
/// Set true to Notify() in inverse order.
		inline HXXADDRET1(void) SetInverseNotification(Bool inverse);
/// Gets the number of observers.
/// @return												The number of observers.
		inline HXXADDRET1(Int) GetObserverCount();
	};
	template <typename ST> struct FnHelper : public std::conditional<
	maxon::Bool(ST::type::Handler::KIND & (maxon::VALUEKIND::COW_MASK | maxon::VALUEKIND::DEEP_CONSTNESS)),
	COWFn<typename ObjectInterface::Hxx1::template FnHelper<ST>::type>,
	typename std::conditional<std::is_const<typename ST::type::PrivateReferencedType>::value, ConstFn<typename ObjectInterface::Hxx1::template FnHelper<ST>::type>, Fn<typename ObjectInterface::Hxx1::template FnHelper<ST>::type>>::type
	> { };
};
class ObservableBaseInterface::Hxx1::Reference :
#ifdef DOXYGEN
public FnDoxy<ObservableBaseRef>
#else
public maxon::RefBase<Hxx1::FnHelper<maxon::RefBaseFn<maxon::DirectRef<ObservableBaseInterface, maxon::StrongRefHandler, ObservableBaseRef>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(Reference, maxon::RefBase<Hxx1::FnHelper<maxon::RefBaseFn<maxon::DirectRef<ObservableBaseInterface, maxon::StrongRefHandler, ObservableBaseRef>>>>);
	using NonConst = typename Super::ReferenceClass;
};

/// ObservableBaseRef is the reference class of ObservableBaseInterface.
///
/// Base Observable Class that allows to add subscribers to observables.
/// Never use this directly, instead use ObservableRef<>.
class ObservableBaseRef : public ObservableBaseInterface::Hxx1::Reference
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(ObservableBaseRef, typename ObservableBaseInterface::Hxx1::Reference);
	using ConstPtr = typename ObservableBaseInterface::ConstPtr;
};

#ifndef DOXYGEN
#else
#endif
#endif
