#if 1
class FunctionBaseRef;

struct FunctionBaseInterface::HasBase { template <typename I> struct Check { static const maxon::Bool value = std::is_same<I, FunctionBaseInterface>::value || ObjectInterface::HasBase::template Check<I>::value; static I* Cast(FunctionBaseInterface* ptr) { return static_cast<I*>(static_cast<maxon::ObjectInterface*>(ptr)); } }; };
struct FunctionBaseInterface::Hxx1
{
	class Reference;
	using ReferenceClass = FunctionBaseRef;
	template <template <typename...> class TEMPL> using SubstituteBases = TEMPL<ObjectInterface>;
	/// Intermediate helper class for FunctionBaseInterface.
	template <typename S> class ConstReferenceFunctionsImpl DOXYGEN_SWITCH(: public S,)
	{
	public:
		ConstReferenceFunctionsImpl() = default;
		using PrivateBaseClass = S;
		using PrivateBaseClass::PrivateBaseClass;
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type GetOwner(ObserverObjectRef& res) const;
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type GetObserver(ObserverObjectRef& res) const;
/// Internal function. Do not use this pointer to call anything. Just compare this value to ObserverObjectInterface*.
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<const void*>, const void*>::type GetObserverPointer() const;
	};
	/// Intermediate helper class for FunctionBaseInterface.
	template <typename S> class ReferenceFunctionsImpl : public ConstReferenceFunctionsImpl<S>
	{
	public:
		ReferenceFunctionsImpl() = default;
		using PrivateBaseClass = ConstReferenceFunctionsImpl<S>;
		using PrivateBaseClass::PrivateBaseClass;
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
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type Set(ObserverObjectInterface* owner, ObserverObjectInterface* observer) const;
/// @param[in] args								Block with a number of arguments.
		inline Result<Data> Execute(const Block<const ConstDataPtr>& args) const;
	};
	/// Intermediate helper class for FunctionBaseInterface.
	template <typename S> class COWReferenceFunctionsImpl : public ConstReferenceFunctionsImpl<S>
	{
	public:
		COWReferenceFunctionsImpl() = default;
		using PrivateBaseClass = ConstReferenceFunctionsImpl<S>;
		using PrivateBaseClass::PrivateBaseClass;
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
		inline typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), void, maxon::Result<void>>::type Set(ObserverObjectInterface* owner, ObserverObjectInterface* observer);
/// @param[in] args								Block with a number of arguments.
		inline Result<Data> Execute(const Block<const ConstDataPtr>& args);
	};
	template <typename ST> struct ReferenceFunctionsHelper : public std::conditional<maxon::Bool(ST::type::Handler::KIND & (maxon::VALUEKIND::COW_MASK | maxon::VALUEKIND::DEEP_CONSTNESS)), COWReferenceFunctionsImpl<typename ObjectInterface::Hxx1::template ReferenceFunctionsHelper<ST>::type>, typename std::conditional<std::is_const<typename ST::type::PrivateReferencedType>::value, ConstReferenceFunctionsImpl<typename ObjectInterface::Hxx1::template ReferenceFunctionsHelper<ST>::type>, ReferenceFunctionsImpl<typename ObjectInterface::Hxx1::template ReferenceFunctionsHelper<ST>::type>>::type> { };
};
class FunctionBaseInterface::Hxx1::Reference :
#ifdef DOXYGEN
public ReferenceFunctionsImplDoxy<FunctionBaseRef>
#else
public maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<FunctionBaseInterface, maxon::StrongRefHandler, FunctionBaseRef>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(Reference, maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<FunctionBaseInterface, maxon::StrongRefHandler, FunctionBaseRef>>>>);
	using NonConst = typename Super::ReferenceClass;
};

/// FunctionBaseRef is the reference class of FunctionBaseInterface.
///
/// This object stores the callback function for observable notifications.
class FunctionBaseRef : public FunctionBaseInterface::Hxx1::Reference
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(FunctionBaseRef, typename FunctionBaseInterface::Hxx1::Reference);
};

class CombinerRef;

struct CombinerInterface::HasBase { template <typename I> struct Check { static const maxon::Bool value = std::is_same<I, CombinerInterface>::value || ObjectInterface::HasBase::template Check<I>::value; static I* Cast(CombinerInterface* ptr) { return static_cast<I*>(static_cast<maxon::ObjectInterface*>(ptr)); } }; };
struct CombinerInterface::Hxx1
{
	class Reference;
	using ReferenceClass = CombinerRef;
	template <template <typename...> class TEMPL> using SubstituteBases = TEMPL<ObjectInterface>;
	/// Intermediate helper class for CombinerInterface.
	template <typename S> class ConstReferenceFunctionsImpl DOXYGEN_SWITCH(: public S,)
	{
	public:
		ConstReferenceFunctionsImpl() = default;
		using PrivateBaseClass = S;
		using PrivateBaseClass::PrivateBaseClass;
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
	template <typename S> class ReferenceFunctionsImpl : public ConstReferenceFunctionsImpl<S>
	{
	public:
		ReferenceFunctionsImpl() = default;
		using PrivateBaseClass = ConstReferenceFunctionsImpl<S>;
		using PrivateBaseClass::PrivateBaseClass;
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongRefHandler, CombinerRef, true>::type&() const { return reinterpret_cast<const CombinerRef&>(this->GetBaseRef()); }
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongRefHandler, CombinerRef, false>::type&() { return reinterpret_cast<const CombinerRef&>(this->GetBaseRef()); }
	};
	/// Intermediate helper class for CombinerInterface.
	template <typename S> class COWReferenceFunctionsImpl : public ConstReferenceFunctionsImpl<S>
	{
	public:
		COWReferenceFunctionsImpl() = default;
		using PrivateBaseClass = ConstReferenceFunctionsImpl<S>;
		using PrivateBaseClass::PrivateBaseClass;
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, void, CombinerRef, false>::type&() { return reinterpret_cast<const CombinerRef&>(this->GetBaseRef()); }
	};
	template <typename ST> struct ReferenceFunctionsHelper : public std::conditional<maxon::Bool(ST::type::Handler::KIND & (maxon::VALUEKIND::COW_MASK | maxon::VALUEKIND::DEEP_CONSTNESS)), COWReferenceFunctionsImpl<typename ObjectInterface::Hxx1::template ReferenceFunctionsHelper<ST>::type>, typename std::conditional<std::is_const<typename ST::type::PrivateReferencedType>::value, ConstReferenceFunctionsImpl<typename ObjectInterface::Hxx1::template ReferenceFunctionsHelper<ST>::type>, ReferenceFunctionsImpl<typename ObjectInterface::Hxx1::template ReferenceFunctionsHelper<ST>::type>>::type> { };
};
class CombinerInterface::Hxx1::Reference :
#ifdef DOXYGEN
public ReferenceFunctionsImplDoxy<CombinerRef>
#else
public maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<CombinerInterface, maxon::StrongRefHandler, CombinerRef>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(Reference, maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<CombinerInterface, maxon::StrongRefHandler, CombinerRef>>>>);
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
};

class ObservableBaseRef;

struct ObservableBaseInterface::HasBase { template <typename I> struct Check { static const maxon::Bool value = std::is_same<I, ObservableBaseInterface>::value || ObjectInterface::HasBase::template Check<I>::value; static I* Cast(ObservableBaseInterface* ptr) { return static_cast<I*>(static_cast<maxon::ObjectInterface*>(ptr)); } }; };
struct ObservableBaseInterface::Hxx1
{
	class Reference;
	using ReferenceClass = ObservableBaseRef;
	template <template <typename...> class TEMPL> using SubstituteBases = TEMPL<ObjectInterface>;
	/// Intermediate helper class for ObservableBaseInterface.
	template <typename S> class ConstReferenceFunctionsImpl DOXYGEN_SWITCH(: public S,)
	{
	public:
		ConstReferenceFunctionsImpl() = default;
		using PrivateBaseClass = S;
		using PrivateBaseClass::PrivateBaseClass;
/// This function returns the Id given in the Init function.
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<Id>, Id>::type GetObservableId() const;
/// Send a notification to all subscribers.
/// @param[in] args								Arguments packed into a Block<ConstDataPtr>.
/// @return												The combined result of the observable. See CombinerInterface.
		inline Result<Data> Notify(const Block<const ConstDataPtr>& args) const;
/// Gets the owner of the observable.
/// @return												The owner of the observable.
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<ObserverObjectInterface*>, ObserverObjectInterface*>::type GetOwner() const;
	};
	/// Intermediate helper class for ObservableBaseInterface.
	template <typename S> class ReferenceFunctionsImpl : public ConstReferenceFunctionsImpl<S>
	{
	public:
		ReferenceFunctionsImpl() = default;
		using PrivateBaseClass = ConstReferenceFunctionsImpl<S>;
		using PrivateBaseClass::PrivateBaseClass;
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
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type _intDisconnectAll(ObserverObjectInterface* observer, Int pass) const;
/// This function needs to be called in the implementation FreeComponent() function.
/// @param[in] observer						Nullptr if all observables should be disconnected. If a object is given only this specific observables are disconnected.
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type Disconnect(ObserverObjectInterface* observer) const;
/// This function needs to be called in the implementation FreeComponent() function.
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type Free() const;
/// Add a subscriber to the observable.
/// Notes: the implementation need to take the ownership of the observerFunction only if the function succeeds.
/// in the case of an error (returning nullptr) the wrapper class outside frees the memory!
/// @param[in] observer						Pointer to a observer object. This parameter can be nullptr.
/// @param[in] observerFunction		Function object that is stored with in the observable.
/// @return												OK on success.
		inline Result<void> AddObserver(ObserverObjectInterface* observer, const FunctionBaseRef& observerFunction) const;
/// Remove a observable entry from the subscriber list.
/// @param[in] observerEntry			Entry to remove.
/// @return												OK on success.
		inline Result<void> RemoveObserver(const FunctionBaseRef& observerEntry) const;
/// Set true to Notify() in inverse order.
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type SetInverseNotification(Bool inverse) const;
/// Gets the number of observers.
/// @return												The number of observers.
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type GetObserverCount() const;
	};
	/// Intermediate helper class for ObservableBaseInterface.
	template <typename S> class COWReferenceFunctionsImpl : public ConstReferenceFunctionsImpl<S>
	{
	public:
		COWReferenceFunctionsImpl() = default;
		using PrivateBaseClass = ConstReferenceFunctionsImpl<S>;
		using PrivateBaseClass::PrivateBaseClass;
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
		inline typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), void, maxon::Result<void>>::type _intDisconnectAll(ObserverObjectInterface* observer, Int pass);
/// This function needs to be called in the implementation FreeComponent() function.
/// @param[in] observer						Nullptr if all observables should be disconnected. If a object is given only this specific observables are disconnected.
		inline typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), void, maxon::Result<void>>::type Disconnect(ObserverObjectInterface* observer);
/// This function needs to be called in the implementation FreeComponent() function.
		inline typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), void, maxon::Result<void>>::type Free();
/// Add a subscriber to the observable.
/// Notes: the implementation need to take the ownership of the observerFunction only if the function succeeds.
/// in the case of an error (returning nullptr) the wrapper class outside frees the memory!
/// @param[in] observer						Pointer to a observer object. This parameter can be nullptr.
/// @param[in] observerFunction		Function object that is stored with in the observable.
/// @return												OK on success.
		inline Result<void> AddObserver(ObserverObjectInterface* observer, const FunctionBaseRef& observerFunction);
/// Remove a observable entry from the subscriber list.
/// @param[in] observerEntry			Entry to remove.
/// @return												OK on success.
		inline Result<void> RemoveObserver(const FunctionBaseRef& observerEntry);
/// Set true to Notify() in inverse order.
		inline typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), void, maxon::Result<void>>::type SetInverseNotification(Bool inverse);
/// Gets the number of observers.
/// @return												The number of observers.
		inline typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), Int, maxon::Result<Int>>::type GetObserverCount();
	};
	template <typename ST> struct ReferenceFunctionsHelper : public std::conditional<maxon::Bool(ST::type::Handler::KIND & (maxon::VALUEKIND::COW_MASK | maxon::VALUEKIND::DEEP_CONSTNESS)), COWReferenceFunctionsImpl<typename ObjectInterface::Hxx1::template ReferenceFunctionsHelper<ST>::type>, typename std::conditional<std::is_const<typename ST::type::PrivateReferencedType>::value, ConstReferenceFunctionsImpl<typename ObjectInterface::Hxx1::template ReferenceFunctionsHelper<ST>::type>, ReferenceFunctionsImpl<typename ObjectInterface::Hxx1::template ReferenceFunctionsHelper<ST>::type>>::type> { };
};
class ObservableBaseInterface::Hxx1::Reference :
#ifdef DOXYGEN
public ReferenceFunctionsImplDoxy<ObservableBaseRef>
#else
public maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<ObservableBaseInterface, maxon::StrongRefHandler, ObservableBaseRef>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(Reference, maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<ObservableBaseInterface, maxon::StrongRefHandler, ObservableBaseRef>>>>);
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
};

#ifndef DOXYGEN
#else
#endif
#endif
