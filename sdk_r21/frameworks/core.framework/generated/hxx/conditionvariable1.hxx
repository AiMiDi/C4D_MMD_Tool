#if 1
class ConditionVariableRef;

struct ConditionVariableInterface::Hxx1
{
	class Reference;
	using ReferenceClass = ConditionVariableRef;
	/// Intermediate helper class for ConditionVariableInterface.
	template <typename S> class ConstReferenceFunctionsImpl DOXYGEN_SWITCH(: public S,)
	{
	public:
		ConstReferenceFunctionsImpl() = default;
		using PrivateBaseClass = S;
		using PrivateBaseClass::PrivateBaseClass;
/// Waits until the condition has been set or a certain amount of time has passed.
/// <B>Does not execute other jobs on the current queue while waiting. Therefore
/// waiting for a condition variable in a job might result in a deadlock. It's recommended
/// to call this from a thread only - other uses (e.g. from a job) might be unsafe and dead-lock.</B>
/// THREADSAFE.
/// @param[in] timeout						Maximum wait interval (or TIMEVALUE_INFINITE for no time-out).
/// @param[in] mode								WAITMODE::DEFAULT by default. WAITMODE::RETURN_ON_CANCEL means that Wait() will return if the caller has been cancelled even if the condition has not been set yet.
/// @return												True if the condition has been set, false for time out or error.
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type Wait(const TimeValue& timeout = TIMEVALUE_INFINITE, WAITMODE mode = WAITMODE::DEFAULT) const;
	};
	/// Intermediate helper class for ConditionVariableInterface.
	template <typename S> class ReferenceFunctionsImpl : public ConstReferenceFunctionsImpl<S>
	{
	public:
		ReferenceFunctionsImpl() = default;
		using PrivateBaseClass = ConstReferenceFunctionsImpl<S>;
		using PrivateBaseClass::PrivateBaseClass;
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongRefHandler, ConditionVariableRef, true>::type&() const { return reinterpret_cast<const ConditionVariableRef&>(this->GetBaseRef()); }
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongRefHandler, ConditionVariableRef, false>::type&() { return reinterpret_cast<const ConditionVariableRef&>(this->GetBaseRef()); }
/// Clears the condition variable and sets the number of dependencies (the number of threads
/// that have to call Set() before the condition is met). By default this is one.
/// When Clear() is called after Wait() you must make sure that there are no more threads
/// still waiting for the same condition. Only after the last thread has left Wait() you are
/// allowed to call Clear(). Otherwise one of the threads may keep waiting because the
/// condition was cleared before it was able to wake up.
/// @param[in] dependencyCnt			The number of times Set() has to be called before the waiting threads will be woken up.
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type Clear(Int32 dependencyCnt = 1) const;
/// Adds another dependency to the condition, e.g. another thread that has to call Set()
/// before the state is considered set.
/// <B> The condition state must not be set yet. This means you must call this from a
/// thread which hasn't done its Set() call yet.</B>
/// THREADSAFE.
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type AddDependency() const;
/// Wakes up all threads waiting for this condition (if the dependency count reaches 0, see Clear()).
/// THREADSAFE.
/// @return												True if successful.
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type Set() const;
/// ObservableFinished is an observable that is triggered after the condition is set.
/// Is not supported for auto-clear because it requires a sticky state.
/// THREADSAFE.
/// @return												Custom observable.
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<ObservableFinishedBase<ConditionVariableInterface>>, ObservableFinishedBase<ConditionVariableInterface>>::type ObservableFinished() const;
	};
	/// Intermediate helper class for ConditionVariableInterface.
	template <typename S> class COWReferenceFunctionsImpl : public ConstReferenceFunctionsImpl<S>
	{
	public:
		COWReferenceFunctionsImpl() = default;
		using PrivateBaseClass = ConstReferenceFunctionsImpl<S>;
		using PrivateBaseClass::PrivateBaseClass;
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, void, ConditionVariableRef, false>::type&() { return reinterpret_cast<const ConditionVariableRef&>(this->GetBaseRef()); }
	};
	template <typename ST> struct ReferenceFunctionsHelper : public std::conditional<maxon::Bool(ST::type::Handler::KIND & (maxon::VALUEKIND::COW_MASK | maxon::VALUEKIND::DEEP_CONSTNESS)), COWReferenceFunctionsImpl<typename ST::type>, typename std::conditional<std::is_const<typename ST::type::PrivateReferencedType>::value, ConstReferenceFunctionsImpl<typename ST::type>, ReferenceFunctionsImpl<typename ST::type>>::type> { };
};
class ConditionVariableInterface::Hxx1::Reference :
#ifdef DOXYGEN
public ReferenceFunctionsImplDoxy<ConditionVariableRef>
#else
public maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<ConditionVariableInterface, maxon::StrongRefHandler, ConditionVariableRef>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(Reference, maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<ConditionVariableInterface, maxon::StrongRefHandler, ConditionVariableRef>>>>);
	using NonConst = typename Super::ReferenceClass;
	static MAXON_ATTRIBUTE_FORCE_INLINE maxon::ResultMemT<ConditionVariableRef> Create();
/// If at all times only one thread waits for a condition variable you can make it auto-clear.
/// This means a Wait() call will automatically clear the condition variable upon return.
/// @param[in] isAutoClear				True: Wait() will automatically clear the condition variable. False: The state is sticky until Clear() is called.
	static MAXON_ATTRIBUTE_FORCE_INLINE maxon::ResultMemT<ConditionVariableRef> Create(Bool isAutoClear);
};

/// ConditionVariableRef is the reference class of ConditionVariableInterface.
///
/// After the condition variable has been constructed its state will be cleared until Set()
/// is called. This state is sticky until someone calls Clear() unless the condition variable
/// has been created as auto-clear.
class ConditionVariableRef : public ConditionVariableInterface::Hxx1::Reference
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(ConditionVariableRef, typename ConditionVariableInterface::Hxx1::Reference);
};

#endif
