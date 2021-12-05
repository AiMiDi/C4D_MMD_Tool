#ifndef OBSERVABLE_H__
#define OBSERVABLE_H__

#include "maxon/object.h"
#include "maxon/parametertype.h"

namespace maxon
{

class JobQueueRef;
class ObserverObjectRef;
class ObserverObjectInterface;
class FunctionBaseRef;


//----------------------------------------------------------------------------------------
/// Helper class for templates.
//----------------------------------------------------------------------------------------
struct Undefined
{
};


namespace details
{

// Helper Class to wrap ANY return value of a function call into a Data.
template <typename T> class CallMe
{
public:
	template <typename FUNC, typename... ARGS> static Result<Data> Call(FUNC& func, ARGS&&... args) { return Data(func(std::forward<ARGS>(args)...)); }
};

template <> class CallMe<void>
{
public:
	template <typename FUNC, typename... ARGS> static Result<Data> Call(FUNC& func, ARGS&&... args) { func(std::forward<ARGS>(args)...); return Data(); }
};

template <typename T> class CallMe<Result<T>>
{
public:
	template <typename FUNC, typename... ARGS> static Result<Data> Call(FUNC& func, ARGS&&... args)
	{
		iferr (T res = func(std::forward<ARGS>(args)...))
			return err;
		return Data(res);
	}
};

template <> class CallMe<Result<void>>
{
public:
	template <typename FUNC, typename... ARGS> static Result<Data> Call(FUNC& func, ARGS&&... args)
	{
		iferr (func(std::forward<ARGS>(args)...))
			return err;
		return Data();
	}
};

template <typename T> class UnpackConstData;

template <typename RESULT, typename... ARGS> class UnpackConstData<RESULT (ARGS...)>
{
public:
	static Result<Data> Invoke(const DelegateBase& dlgt, const Block<const ConstDataPtr>& args)
	{
		return CallImpl(dlgt, args, std::make_index_sequence<sizeof...(ARGS)>());
	}

private:
	template <size_t... INDICES> static Result<Data> CallImpl(const DelegateBase& dlgt, const Block<const ConstDataPtr>& args, const std::index_sequence<INDICES...>&)
	{
		// Forward a Result<TYPE> for every data member of the block.
		return ForwardWithError(dlgt, args[INDICES].Get<typename std::decay<ARGS>::type>()...);
	}

	template <typename... RESULTARGS> static Result<Data> ForwardWithError(const DelegateBase& dlgt, const RESULTARGS&... args)
	{
		Error err;

		// Check for errors and return if parameter unpacking fails.
		if (CheckForErrors(err, args...))
			return err;

		// Forward the parameters.
		return CallMe<RESULT>::Call((const Delegate<RESULT (ARGS...)>&)dlgt, args.GetValue()...);
	}

	// Returns true if any of the Results contained an error.
	template <typename... RESULTARGS> static Bool CheckForErrors(Error& err, const RESULTARGS&... args)
	{
		// Call CheckError() for each argument.
		ForEach{CheckError(args.GetError(), err)...};
		return err != nullptr;
	}

	static int CheckError(const Error& in, Error& out)
	{
		if (in)
		{
			// Return first error only.
			if (out == nullptr)
				out = in;
		}
		// Dummy return value for ForEach.
		return 0;
	}
};

template <typename... ARGS> static auto GetUnpackConstData(const Delegate<ARGS...>&) -> UnpackConstData<ARGS...>
{
	return UnpackConstData<ARGS...>();
}

template <typename... ARGS> class PackConstData
{
public:
	template <typename... WRAPPER> static void ToWrapper(const ARGS&... args, WRAPPER&... wrapper)
	{
		ForEach{ToDataEntry(args, wrapper)...};
	}

private:
	template <typename T, typename WRAPPER> static int ToDataEntry(const T& arg, WRAPPER& wrapper)
	{
		iferr (wrapper.Init(arg))
			DebugStop("ConstDataPtr::Wrapper::Init must not fail (ResultOk).");

		return 0;
	}
};

//----------------------------------------------------------------------------------------
/// Helper class to detect and convert to the right Result<T> for ObservableRef::Notify()
/// This is necessary because the Notify returns Result<Data>. The Data is created locally on the stack.
/// Now all return types which return a reference needs to convert the value into a value instead of returning a reference.
//----------------------------------------------------------------------------------------
template <typename T> struct MAXON_WARN_UNUSED_CLASS GetResultType
{
	using type = Result<T>;
	using vartype = T;
	using resulttype = Result<typename std::decay<T>::type>;

	static resulttype ReturnData(Data&& val)
	{
		iferr (auto& res = val.Get<typename std::decay<T>::type>())
			return err;
		return res;
	}
};

template <> struct MAXON_WARN_UNUSED_CLASS GetResultType<Data>
{
	using type = Result<Data>;
	using vartype = void;
	using resulttype = Result<Data>;

	static resulttype ReturnData(Data&& val)
	{
		return std::move(val);
	}
};

template <> struct MAXON_WARN_UNUSED_CLASS GetResultType<void>
{
	using type = Result<void>;
	using vartype = void;
	using resulttype = Result<void>;

	static resulttype ReturnData(Data&& val)
	{
		return OK;
	}
};

template <typename T> struct MAXON_WARN_UNUSED_CLASS GetResultType<Result<T>>
{
	using type = Result<T>;
	using vartype = T;
	using resulttype = Result<typename std::decay<T>::type>;

	static resulttype ReturnData(Data&& val)
	{
		iferr (auto& res = val.Get<typename std::decay<T>::type>())
			return err;
		return res;
	}
};

template <> struct MAXON_WARN_UNUSED_CLASS GetResultType<Result<Data>>
{
	using type = Result<Data>;
	using vartype = void;
	using resulttype = Result<Data>;

	static resulttype ReturnData(Data&& val)
	{
		return std::move(val);
	}
};

template <> struct MAXON_WARN_UNUSED_CLASS GetResultType<Result<void>>
{
	using type = Result<void>;
	using vartype = void;
	using resulttype = Result<void>;

	static resulttype ReturnData(Data&& val)
	{
		return OK;
	}
};

}

#define PRIVATE_MAXON_OBSERVABLE_IMPL(NAME, Interface) \
	maxon::ObservableImplRef<maxon::ObservableClassPrivateHelper, Interface::MAXON_CONCAT(NAME, Delegate)>	MAXON_CONCAT(_, NAME); \
	maxon::ObservableRef<Interface::MAXON_CONCAT(NAME, Delegate)> NAME() const { return MAXON_CONCAT(_, NAME); }

#define PRIVATE_MAXON_OBSERVABLE_IMPL_ DUMMY, Interface

//----------------------------------------------------------------------------------------
/// Macro for observable implementation. Use MAXON_OBSERVABLE_IMPL(observableName) within the implementation of interfaces which offer observables.
/// @param[in] NAME								Name of the observable in the interface class.
/// @param[in] ...								Optional: The interface of NAME. You need to specify this when the component doesn't implement exactly the interface of NAME,
///																but e.g. a derived interface or additional interfaces.
/// @code
/// Example usage:
/// class NetworkZeroConfBonjourBrowserImpl : public Component<NetworkZeroConfBonjourBrowserImpl, NetworkZeroConfBrowserInterface>
/// {
/// 	MAXON_COMPONENT();
///
/// public:
/// 	Result<void> InitComponent()
/// 	{
/// 		iferr (_ObservableDetected.Init(self, Id("ObservableDetected")))
/// 			return err;
/// 		iferr (_ObservableResolved.Init(self, Id("ObservableResolved")))
/// 			return err;
/// 		return true;
/// 	}
///
/// 	void FreeComponent()
/// 	{
/// 		_ObservableDetected.Free();
/// 		_ObservableResolved.Free();
/// 	}
///
/// 	MAXON_OBSERVABLE_IMPL(ObservableDetected);
/// 	MAXON_OBSERVABLE_IMPL(ObservableResolved);
/// };
/// @endcode
//----------------------------------------------------------------------------------------
#define MAXON_OBSERVABLE_IMPL(NAME, ...) PRIVATE_MAXON_OBSERVABLE_IMPL(NAME, MAXON_SECONDARG(PRIVATE_MAXON_OBSERVABLE_IMPL_##__VA_ARGS__, __VA_ARGS__))

//----------------------------------------------------------------------------------------
/// Macro for observable implementation in non-virtual interfaces.
/// @param[in] NAME								Name of the observable in the interface class.
/// @code
/// Example usage:
/// class TimerImpl : public TimerInterface
/// {
/// 	MAXON_IMPLEMENTATION(TimerImpl)
///
/// public:
/// 	TimerImpl()
/// 	{
/// 		_notificationObject = ObserverObjectClass().Create().GetPointer();
/// 		_ObservableTimerStarted.Init(_notificationObject, Id("ObservableTimerStarted"));
/// 	}
///
/// 	~TimerImpl()
/// 	{
/// 		_ObservableTimerStarted.Free();
/// 	}
///
/// 	void Start()
/// 	{
/// 		_ObservableTimerStarted.Notify();
/// 	}
///
/// 	OBSERVABLE_IMPL_NONVIRTUAL(ObservableTimerStarted);
///
/// private:
/// 	ObserverObjectRef	_notificationObject;
/// };
/// @endcode
//----------------------------------------------------------------------------------------
#define OBSERVABLE_IMPL_NONVIRTUAL(NAME) \
	ObservableImplRef<ObservableClassPrivateHelper, Interface::MAXON_CONCAT(NAME, Delegate)>	MAXON_CONCAT(_, NAME); \
	ObservableRef<Interface::MAXON_CONCAT(NAME, Delegate)> NAME() const { return MAXON_CONCAT(_, NAME); }


using ObservableForwardFunction = Result<Data> (*)(const DelegateBase& observerFunction, const Block<const ConstDataPtr>& data);


//----------------------------------------------------------------------------------------
/// This object stores the callback function for observable notifications.
//----------------------------------------------------------------------------------------
class FunctionBaseInterface : MAXON_INTERFACE_BASES(ObjectInterface)
{
	MAXON_INTERFACE(FunctionBaseInterface, MAXON_REFERENCE_NORMAL, "net.maxon.interface.functionbase");

public:
	//----------------------------------------------------------------------------------------
	/// Initializes the object for execution on JOBQUEUE_NONE.
	/// @param[in] forwardFunction		Pointer to a function which unpacks the parameters and forwards them to the delegate: static maxon::Result<maxon::Data> Execute(const DelegateBase&, const maxon::Block<maxon::ConstDataPtr>&)
	/// @param[in] function						Delegate of the observer (only base class is required here).
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> Init(const ObservableForwardFunction forwardFunction, DelegateBase&& function);

	//----------------------------------------------------------------------------------------
	/// Initializes the object for execution on a dedicated queue.
	/// @param[in] forwardFunction		Pointer to a function which unpacks the parameters and forwards them to the delegate: static maxon::Result<maxon::Data> Execute(const DelegateBase&, const maxon::Block<maxon::ConstDataPtr>&)
	/// @param[in] function						Delegate of the observer (only base class is required here).
	/// @param[in] queue							Queue for the execution of the observer,
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> Init(const ObservableForwardFunction forwardFunction, DelegateBase&& function, const JobQueueRef& queue);

	//----------------------------------------------------------------------------------------
	/// @param[in] owner							...
	/// @param[in] observer						...
	//----------------------------------------------------------------------------------------
	MAXON_METHOD void Set(ObserverObjectInterface* owner, ObserverObjectInterface* observer);

	MAXON_METHOD void GetOwner(ObserverObjectRef& res) const;

	MAXON_METHOD void GetObserver(ObserverObjectRef& res) const;

	//----------------------------------------------------------------------------------------
	/// Internal function. Do not use this pointer to call anything. Just compare this value to ObserverObjectInterface*.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD const void* GetObserverPointer() const;

	//----------------------------------------------------------------------------------------
	/// @param[in] args								Block with a number of arguments.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<Data> Execute(const Block<const ConstDataPtr>& args);
};



//----------------------------------------------------------------------------------------
/// Combiners allow to combine the result of multiple observable subscribers.
/// There are some default implementations: see ObservableCombinerRunAllComponent, ObservableCombinerRunAllBoolOrComponent.
//----------------------------------------------------------------------------------------
class CombinerInterface : MAXON_INTERFACE_BASES(ObjectInterface)
{
	MAXON_INTERFACE(CombinerInterface, MAXON_REFERENCE_NORMAL, "net.maxon.interface.combiner");

public:
	//----------------------------------------------------------------------------------------
	/// Called first before the observable notification starts. In general the start result value will be copied to the result value.
	/// @param[out] combinedRes				Receives the start value.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> InitCombine(Result<Data>& combinedRes) const;

	//----------------------------------------------------------------------------------------
	/// Called after each notification. This function defines how the results are combined together.
	/// The return value controls if following subscribers should be called.
	/// @param[in,out] combinedRes		Contains the last result and receives the new result.
	/// @param[in] newRes							The new result that needs to be combined with combinedRes.
	/// @return												True if the the next subscriber should be called. False if the notification should stop here.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<Bool> CombineResult(Result<Data>& combinedRes, Result<Data>&& newRes) const;
};

//----------------------------------------------------------------------------------------
/// Implementation of CombinerInterface. Using this combiner ensures that all subscribers are called.
/// The result of the last notification will be returned.
//----------------------------------------------------------------------------------------
MAXON_DECLARATION(ComponentDescriptor, ObservableCombinerRunAllComponent, "net.maxon.component.observablecombinerrunall");

//----------------------------------------------------------------------------------------
/// Implementation of CombinerInterface. Using this combiner ensures that all subscribers are called.
/// The result is combined by an OR operation.
//----------------------------------------------------------------------------------------
MAXON_DECLARATION(ComponentDescriptor, ObservableCombinerRunAllBoolOrComponent, "net.maxon.component.observablecombinerrunallboolor");

//----------------------------------------------------------------------------------------
/// Implementation of CombinerInterface.
/// The result is initialized with true and runs until the first false occurs.
//----------------------------------------------------------------------------------------
MAXON_DECLARATION(ComponentDescriptor, ObservableCombinerRunAllBoolUntilFalse, "net.maxon.component.observablecombinerrunallbooluntilfalse");

//----------------------------------------------------------------------------------------
/// Implementation of CombinerInterface.
/// The result is initialized with false and runs until the first true occurs.
//----------------------------------------------------------------------------------------
MAXON_DECLARATION(ComponentDescriptor, ObservableCombinerRunAllBoolUntilTrue, "net.maxon.component.observablecombinerrunallbooluntiltrue");

//----------------------------------------------------------------------------------------
/// Implementation of CombinerInterface. Using this combiner ensures that all subscribers are called.
/// The result is combined by an OR operation.
//----------------------------------------------------------------------------------------
MAXON_DECLARATION(ComponentDescriptor, ObservableCombinerRunAllEnumFlagsOrComponent, "net.maxon.component.observablecombinerrunallenumflagsor");

//----------------------------------------------------------------------------------------
/// Implementation of CombinerInterface. Using this combiner ensures that all subscribers are called.
/// The result is combined by an OR operation. Use this for 64-bit-wide enums.
//----------------------------------------------------------------------------------------
MAXON_DECLARATION(ComponentDescriptor, ObservableCombinerRunAllEnumFlags64OrComponent, "net.maxon.component.observablecombinerrunallenumflags64or");

//----------------------------------------------------------------------------------------
/// Implementation of CombinerInterface. Using this combiner ensures that all subscribers are called.
/// All errors returned by the subscribers will be aggregated and returnd as AggregatedError.
//----------------------------------------------------------------------------------------
MAXON_DECLARATION(ComponentDescriptor, ObservableCombinerRunAllAggregateErrorsComponent, "net.maxon.component.observablecombinerrunallaggregateerrors");


//----------------------------------------------------------------------------------------
/// Base Observable Class that allows to add subscribers to observables.
/// Never use this directly, instead use ObservableRef<>.
//----------------------------------------------------------------------------------------
class ObservableBaseInterface : MAXON_INTERFACE_BASES(ObjectInterface)
{
	MAXON_INTERFACE(ObservableBaseInterface, MAXON_REFERENCE_NORMAL, "net.maxon.interface.observablebase");

public:

	//----------------------------------------------------------------------------------------
	/// This function needs to be called in the implementation InitComponent() function.
	/// @param[in] owner							Pointer to the observable owner.
	/// @param[in] observableName			Name of the observable. This observable name is sent via ObserverConnectNotify/ObserverDisconnectNotify.
	/// @return												True if the function operates successful.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> Init(ObserverObjectInterface* owner, const Id& observableName);

	//----------------------------------------------------------------------------------------
	/// This function returns the Id given in the Init function.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Id GetObservableId() const;

	// stylecheck.naming=false

	//----------------------------------------------------------------------------------------
	/// This function needs to be called in the implementation FreeComponent() function.
	/// Don't use this function directly, only for internal use!
	/// @param[in] observer						Nullptr if all observables should be disconnected. If a object is given only this specific observables are disconnected.
	/// @param[in] pass								Internal use only.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD void _intDisconnectAll(ObserverObjectInterface* observer, Int pass);

	// stylecheck.naming=true

	//----------------------------------------------------------------------------------------
	/// This function needs to be called in the implementation FreeComponent() function.
	/// @param[in] observer						Nullptr if all observables should be disconnected. If a object is given only this specific observables are disconnected.
	//----------------------------------------------------------------------------------------
	MAXON_FUNCTION void Disconnect(ObserverObjectInterface* observer)
	{
		ObservableBaseInterface::_intDisconnectAll(observer, 0);
		ObservableBaseInterface::_intDisconnectAll(observer, 1);
	}

	//----------------------------------------------------------------------------------------
	/// This function needs to be called in the implementation FreeComponent() function.
	//----------------------------------------------------------------------------------------
	MAXON_FUNCTION void Free()
	{
		ObservableBaseInterface::_intDisconnectAll(nullptr, 0);
		ObservableBaseInterface::_intDisconnectAll(nullptr, 1);
	}

	//----------------------------------------------------------------------------------------
	/// Add a subscriber to the observable.
	/// Notes: the implementation need to take the ownership of the observerFunction only if the function succeeds.
	/// in the case of an error (returning nullptr) the wrapper class outside frees the memory!
	/// @param[in] observer						Pointer to a observer object. This parameter can be nullptr.
	/// @param[in] observerFunction		Function object that is stored with in the observable.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> AddObserver(ObserverObjectInterface* observer, const FunctionBaseRef& observerFunction);

	//----------------------------------------------------------------------------------------
	/// Send a notification to all subscribers.
	/// @param[in] args								Arguments packed into a Block<ConstDataPtr>.
	/// @return												The combined result of the observable. See CombinerInterface.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<Data> Notify(const Block<const ConstDataPtr>& args) const;

	//----------------------------------------------------------------------------------------
	/// Remove a observable entry from the subscriber list.
	/// @param[in] observerEntry			Entry to remove.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> RemoveObserver(const FunctionBaseRef& observerEntry);

	//----------------------------------------------------------------------------------------
	/// Set true to Notify() in inverse order.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD void SetInverseNotification(Bool inverse);

	//----------------------------------------------------------------------------------------
	/// Gets the number of observers.
	/// @return												The number of observers.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Int GetObserverCount();

	//----------------------------------------------------------------------------------------
	/// Gets the owner of the observable.
	/// @return												The owner of the observable.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD ObserverObjectInterface* GetOwner() const;
};



#include "observable1.hxx"


MAXON_DECLARATION(Class<FunctionBaseRef>, FunctionBaseClass, "net.maxon.class.functionbase");
MAXON_DECLARATION(Class<ObservableBaseRef>, ObservableClass, "net.maxon.class.observable");


template <typename T> class ObservableNotifyRef;

// ICC and MSVC require this specialization because they fail with arrays of [sizeof...(ARGS)] when there is a function without parameters.
template <typename RESULT> class ObservableNotifyRef<Delegate<RESULT (void)>> : public ObservableBaseRef
{
public:
	using ObservableBaseRef::AddObserver;

	//----------------------------------------------------------------------------------------
	/// Notifies all subscribers of the observable.
	/// @return												Return value of the delegate.
	//----------------------------------------------------------------------------------------
	typename maxon::details::GetResultType<RESULT>::resulttype Notify() const
	{
		iferr (Data val = ObservableBaseRef::Notify(Block<ConstDataPtr>(nullptr, 0)))
			return err;

		return maxon::details::GetResultType<RESULT>::ReturnData(std::move(val));
	}
};

template <typename RESULT, typename... ARGS> class ObservableNotifyRef<Delegate<RESULT (ARGS...)>> : public ObservableBaseRef
{
	template <size_t... INDICES> Result<Data> NotifyWithData(const ARGS&... args, const std::index_sequence<INDICES ...>&) const
	{
		Tuple<typename ConstDataPtr::Wrapper<typename std::decay<ARGS>::type>...> wrapper;

		// Store each argument (or if applicable only the reference) in the ConstDataPtr::Wrapper. The wrapper is necessary to convert arrays on the fly.
		maxon::details::PackConstData<ARGS...>::ToWrapper(args..., TupleGet<INDICES>(wrapper)...);

		// Build an array of ConstDataPtr which is expected by the Execute method.
		ConstDataPtr data[sizeof...(ARGS)] = { TupleGet<INDICES>(wrapper)... };

		// Notify the observers.
		return ObservableBaseRef::Notify(Block<ConstDataPtr>(data, sizeof...(ARGS)));
	}

public:
	using ObservableBaseRef::AddObserver;

	//----------------------------------------------------------------------------------------
	/// Notifies all subscribers of the observable.
	/// @param[in] args								Parameters for the notification (taken from the delegate).
	/// @return												Return value of the delegate.
	//----------------------------------------------------------------------------------------
	typename maxon::details::GetResultType<RESULT>::resulttype Notify(const ARGS&... args) const
	{
		std::make_index_sequence<sizeof...(ARGS)> indices;

		iferr (Data val = NotifyWithData(args..., indices))
			return err;

		return maxon::details::GetResultType<RESULT>::ReturnData(std::move(val));
	}
};


//----------------------------------------------------------------------------------------
/// Observable Class that allows to add subscribers to observables.
/// @tparam DELEGATE							Delegate of the observable class defined in the MAXON_OBSERVABLE macro. Usually "Delegate" is appended to the observable name, e.g. ObservableMachineStateChangedDelegate.
//----------------------------------------------------------------------------------------
template <typename DELEGATE> class MAXON_WARN_UNUSED_CLASS ObservableRef : public ObservableNotifyRef<typename DELEGATE::Super>
{
public:
	using ObservableNotifyRef<typename DELEGATE::Super>::AddObserver;

	// TODO: (Tilo) Please add HasObservers(). For some classes you can avoid unnecessary calls when there is
	// no observer and sometimes you'll want diagnostic output when there is no one to be notified.


	//----------------------------------------------------------------------------------------
	/// Adds a notification lambda as a subscriber to a observable.
	/// @param[in] observer						Object to connect with the observable. This can be nullptr.
	/// @param[in] fn									Lambda function (or object with Handle* method) that should be called when the observable is fired.
//	/// @param[in] queue							Queue in which the notification should be send. queuing is only possible if the observable has no return value.
	/// @return												If successful the entry object is returned. In case of failures a nullptr.
	//----------------------------------------------------------------------------------------
	template <typename FN> Result<FunctionBaseRef> AddObserver(ObserverObjectInterface* observer, FN&& fn) const
	{
		iferr_scope;

		// Create a delegate of the lambda.
		auto observerFunction = DELEGATE::Create(std::forward<FN>(fn)) iferr_return;

		// Get a callback which unpacks all the parameters from a ConstData block and invokes the delegate.
		ObservableForwardFunction forwardFunction = &maxon::details::GetUnpackConstData(observerFunction).Invoke;

		// Initialize with FunctionBaseRef with callback and delegate and execute on JOBQUEUE_NONE.
		FunctionBaseRef func = FunctionBaseClass().Create() iferr_return;
		func.Init(forwardFunction, std::move(observerFunction)) iferr_return;

		ObservableBaseRef::AddObserver(observer, func) iferr_return;

		return func;
	}

	//----------------------------------------------------------------------------------------
	/// Adds a notification lambda as a subscriber to a observable.
	/// @param[in] observer						Object to connect with the observable. This can be nullptr.
	/// @param[in] fn									Lambda function (or object with Handle* method) that should be called when the observable is fired.
	/// @param[in] queue							Queue in which the notification should be send. queuing is only possible if the observable has no return value.
	/// @return												If successful the entry object is returned. In case of failures a nullptr.
	//----------------------------------------------------------------------------------------
	template <typename FN> Result<FunctionBaseRef> AddObserver(ObserverObjectInterface* observer, FN&& fn, const JobQueueRef& queue) const
	{
		iferr_scope;

		// The observer must not return a value when a queue other than JOBQUEUE_NONE is used.
		static_assert(std::is_same<typename DELEGATE::Super::ResultValueType, void>::value, "Enqueued observers must not return a value.");

// TODO: (Tilo) replace later
// 		if (queue && !observableNameFunc::NCombiner::QUEUE_ALLOWED)
// 		{
// 			// queuing not allowed for this kind of combiner
// 			DebugStop();
// 			return nullptr;
// 		}

		// Create a delegate of the lambda.
		auto observerFunction = DELEGATE::Create(std::forward<FN>(fn)) iferr_return;

		// Get a callback which unpacks all the parameters from a ConstData block and invokes the delegate.
		ObservableForwardFunction forwardFunction = &maxon::details::GetUnpackConstData(observerFunction).Invoke;

		// Initialize with FunctionBaseRef with callback and delegate.
		FunctionBaseRef func = FunctionBaseClass().Create() iferr_return;
		func.Init(forwardFunction, std::move(observerFunction), queue) iferr_return;

		ObservableBaseRef::AddObserver(observer, func) iferr_return;

		return func;
	}


	//----------------------------------------------------------------------------------------
	/// Adds a notification lambda as a subscriber to a observable.
	/// @param[in] fn									Lambda function (or object with Handle* method) that should be called when the observable is fired.
	/// @return												If successful the entry object is returned. In case of failures a nullptr.
	//----------------------------------------------------------------------------------------
	template <typename FN> Result<FunctionBaseRef> AddObserver(FN&& fn) const
	{
		return AddObserver(nullptr, std::forward<FN>(fn));
	}

	//----------------------------------------------------------------------------------------
	/// Adds a notification lambda as a subscriber to a observable.
	/// @param[in] fn									Lambda function (or object with Handle* method) that should be called when the observable is fired.
	/// @param[in] queue							Queue in which the notification should be send. queuing is only possible if the observable has no return value.
	/// @return												If successful the entry object is returned. In case of failures a nullptr.
	//----------------------------------------------------------------------------------------
	template <typename FN, typename = typename std::enable_if<!std::is_convertible<typename std::decay<FN>::type, ObserverObjectInterface*>::value>::type> Result<FunctionBaseRef> AddObserver(FN&& fn, const JobQueueRef& queue) const
	{
		return AddObserver(nullptr, std::forward<FN>(fn), queue);
	}

	//----------------------------------------------------------------------------------------
	/// Helper function for data type registration.
	//----------------------------------------------------------------------------------------
	static ObservableRef<DELEGATE> NullValue() { return ObservableRef<DELEGATE>(); }
};






//----------------------------------------------------------------------------------------
/// Helper for static interface
//----------------------------------------------------------------------------------------
class ObservableStaticInterface
{
	MAXON_INTERFACE_NONVIRTUAL(ObservableStaticInterface, MAXON_REFERENCE_NONE, "net.maxon.interface.observablestatic");
public:
	static MAXON_METHOD const ClassInterface* GetOrAllocClass(const Id& id, const ClassInterface* id1, const ComponentDescriptor* id2);
};

//----------------------------------------------------------------------------------------
/// Helper template reference class for implementation of observables.
/// @tparam ObservableClass				Can be either ObservableClass or ObservableRPCClass.
/// @tparam DELEGATE							Delegate of the observable class defined in the MAXON_OBSERVABLE macro. Usually "Delegate" is appended to the observable name, e.g. ObservableMachineStateChangedDelegate.
//----------------------------------------------------------------------------------------
template <typename ObservableClass, typename DELEGATE> class ObservableImplRef : public ObservableRef<DELEGATE>
{
public:
	//----------------------------------------------------------------------------------------
	/// Default constructor, allocates the object.
	//----------------------------------------------------------------------------------------
	ObservableImplRef()
	{
		const ClassInterface* cl = ObservableStaticInterface::GetOrAllocClass(ObservableClass::GetId(), ObservableClass::GetInstance()(), &DELEGATE::OBSERVABLECOMBINER::GetInstance()());

		iferr (ObservableBaseRef observable = Class<ObservableBaseRef>(cl).Create())
		{
			DebugStop();
			return;
		}

		*((ObservableBaseRef*)this) = observable;
	}
};






//----------------------------------------------------------------------------------------
/// Defined Observables for the source processor
//----------------------------------------------------------------------------------------
#ifndef DOXYGEN
	#define MAXON_OBSERVABLE(RETTYPE, NAME, ...) \
		class MAXON_CONCAT(NAME, Delegate); \
		MAXON_METHOD maxon::ObservableRef<MAXON_CONCAT(NAME, Delegate)> NAME() const;

	#define MAXON_OBSERVABLE_STATIC(RETTYPE, NAME, ...) \
		class MAXON_CONCAT(NAME, Delegate); \
		static MAXON_METHOD maxon::ObservableRef<MAXON_CONCAT(NAME, Delegate)> NAME();
#else
	// special defines for doxygen, this simulates a normal function
	#define MAXON_OBSERVABLE(RETTYPE, NAME, ARGUMENTLIST, COMBINER) ObservableRef<> NAME() const -> RETTYPE (*) ARGUMENTLIST
	#define MAXON_OBSERVABLE_STATIC(RETTYPE, NAME, ARGUMENTLIST, COMBINER) ObservableRef<> NAME() const -> RETTYPE (*) ARGUMENTLIST
#endif

#include "observable2.hxx"

}

#endif // OBSERVABLE_H__
