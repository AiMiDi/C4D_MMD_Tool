#if 1
class TimerRef;

/// @cond IGNORE

/// @endcond

struct TimerInterface::Hxx1
{
	class Reference;
	using ReferenceClass = TimerRef;
	/// Intermediate helper class for TimerInterface.
	template <typename S> class ConstReferenceFunctionsImpl DOXYGEN_SWITCH(: public S,)
	{
	public:
		ConstReferenceFunctionsImpl() = default;
		using PrivateBaseClass = S;
		using PrivateBaseClass::PrivateBaseClass;
/// Adds a job to be called periodically at the specified interval. The timer will be
/// removed when CancelAndWait() is called.
/// The timer will fire for the first time after the specified interval and with a default
///  tolerance. For more options you might have to create a TimerRef directly.
/// Please note that on Windows - and only there - you usually won't get a smaller interval
/// and granularity than 15 milliseconds. For all other operating systems one millisecond or
/// below is no problem, but of course this will take a lot of CPU cycles.
/// If you have specified a queue other than JOBQUEUE_NONE and for one reason or another your
/// job has not finished in the specified interval (e.g. because there were so many other jobs
/// in the queue) the next call will be dropped - you won't get a sudden accumulation of calls.
/// <B> If you specify JOBQUEUE_NONE your job must execute very fast: It MUST NOT LOCK, MUST
/// NOT take longer than a millisecond, preferrably it should be faster than a microsecond. </B>
/// Specifying the main thread queue as destination is equivalent to creating a RunLoop/UI
/// timer, but you can do this from any thread.
/// @param[in] interval						Timer interval.
/// @param[in] job								A JobInterface or lambda to be executed periodically.
/// @param[in] queue							The queue, use JOBQUEUE_CURRENT for the current queue or JOBQUEUE_NONE if the job should be executed immediately.
/// @tparam FN										Type of object/lambda, deduced by the compiler.
/// @return												Timer reference.
		template <typename FN> static inline Result<TimerRef> AddPeriodicTimer(TimeValue interval, FN&& job, JobQueueInterface* queue);
/// Adds a job to be called once after the specified delay. The timer will be removed
/// after it has fired once or when CancelAndWait() is called.
/// Please note that on Windows - and only there - you usually will have a granularity of
/// about 15 milliseconds. For all other operating systems the granularity is usually one
/// millisecond or lower (high CPU load might lead to deferred timers nonetheless).
/// If you have specified a queue other than JOBQUEUE_NONE and for one reason or another your
/// job has not finished in the specified interval (e.g. because there were so many other jobs
/// in the queue) the next call will be dropped - you won't get a sudden accumulation of calls.
/// <B> If you specify JOBQUEUE_NONE your job must execute very fast: It MUST NOT LOCK, MUST
/// NOT take longer than a millisecond, preferrably it should be faster than a microsecond. </B>
/// Specifying the main thread queue as destination is equivalent to creating a RunLoop/UI
/// timer, but you can do this from any thread.
/// @param[in] delay							Delay until job will be enqueued.
/// @param[in] queue							The queue, use JOBQUEUE_CURRENT for the current queue or JOBQUEUE_NONE if the job should be executed immediately.
/// @param[in] job								A JobInterface or lambda to be executed once after the specified delay.
/// @tparam FN										Type of object/lambda, deduced by the compiler.
/// @return												Timer reference.
		template <typename FN> static inline Result<TimerRef> AddOneShotTimer(TimeValue delay, FN&& job, JobQueueInterface* queue);
/// Notifies the observers that the timer has started.
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<maxon::ObservableRef<ObservableTimerStartedDelegate>>, maxon::ObservableRef<ObservableTimerStartedDelegate>>::type ObservableTimerStarted() const;
/// Notifies the observers that the timer has finished.
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<maxon::ObservableRef<ObservableTimerFinishedDelegate>>, maxon::ObservableRef<ObservableTimerFinishedDelegate>>::type ObservableTimerFinished() const;
/// Notifies the observers that the timer job took longer than the specified interval.
/// param[in] duration						The duration spend in the observable.
/// param[in] maxDuration				Maximum time that was suggested.
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<maxon::ObservableRef<ObservableTimerOverloadDelegate>>, maxon::ObservableRef<ObservableTimerOverloadDelegate>>::type ObservableTimerOverload() const;
/// @cond IGNORE

/// @endcond

	};
	/// Intermediate helper class for TimerInterface.
	template <typename S> class ReferenceFunctionsImpl : public ConstReferenceFunctionsImpl<S>
	{
	public:
		ReferenceFunctionsImpl() = default;
		using PrivateBaseClass = ConstReferenceFunctionsImpl<S>;
		using PrivateBaseClass::PrivateBaseClass;
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongRefHandler, TimerRef, true>::type&() const { return reinterpret_cast<const TimerRef&>(this->GetBaseRef()); }
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongRefHandler, TimerRef, false>::type&() { return reinterpret_cast<const TimerRef&>(this->GetBaseRef()); }
/// Schedules a job to be called periodically at the specified interval. If the interval
/// is 0.0 the timer is fired once after the specified delay.
/// After a job has been started you must call CancelAndWait() and restart it to change
/// the interval or other parameters.
/// <B> If you specify JOBQUEUE_NONE your job must execute very fast: It MUST NOT LOCK, MUST
/// NOT take longer than a millisecond, preferrably it should be faster than a microsecond. </B>
/// Specifying the main thread queue as destination is equivalent to creating a RunLoop/UI
/// timer, but you can do this from any thread.
/// @param[in] interval						Timer interval.
/// @param[in] delay							Delay until the timer fires the first time.
/// @param[in] tolerance					Maximum tolerance of execution (used for timer coalescing).
/// @param[in] job								The job to be executed (periodically).
/// @param[in] queue							The queue, use JOBQUEUE_CURRENT for the current queue or JOBQUEUE_NONE if the job should be executed immediately.
/// @return												OK on success.
		inline Result<void> Start(TimeValue interval, TimeValue delay, TimeValue tolerance, JobInterface* job, JobQueueInterface* queue) const;
/// Schedules a job to be called periodically at the specified interval. If the interval
/// is 0.0 the timer is fired once after the specified delay.
/// After a job has been started you must call CancelAndWait() and restart it to change
/// the interval or other parameters.
/// <B> If you specify JOBQUEUE_NONE your job must execute very fast: It MUST NOT LOCK, MUST
/// NOT take longer than a millisecond, preferably it should be faster than a microsecond. </B>
/// Specifying the main thread queue as destination is equivalent to creating a RunLoop/UI
/// timer, but you can do this from any thread.
/// @param[in] interval						Timer interval.
/// @param[in] delay							Delay until the timer fires the first time.
/// @param[in] tolerance					Maximum tolerance of execution (used for timer coalescing).
/// @param[in] src								A lambda to be executed (periodically).
/// @param[in] queue							The queue, use JOBQUEUE_CURRENT for the current queue or JOBQUEUE_NONE if the job should be executed immediately.
/// @return												OK on success.
		template <typename FN> inline typename std::conditional<S::HAS_ERROR, maxon::Result<DISABLE_IF_JOBREF(FN,Result<void>)>, DISABLE_IF_JOBREF(FN,Result<void>)>::type Start(TimeValue interval, TimeValue delay, TimeValue tolerance, FN&& src, JobQueueInterface* queue) const;
/// Cancels a timer and if necessary waits until a currently pending timer job has finished.
/// Does nothing if no timer was started.
/// Don't call CancelAndWait() from inside a timer job because it cant't wait - use Cancel().
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type CancelAndWait() const;
/// Cancels a timer. Might have to wait for a currently pending timer job.
/// Can be called from within the timer job.
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type Cancel() const;
/// @cond IGNORE

/// @endcond

	};
	/// Intermediate helper class for TimerInterface.
	template <typename S> class COWReferenceFunctionsImpl : public ConstReferenceFunctionsImpl<S>
	{
	public:
		COWReferenceFunctionsImpl() = default;
		using PrivateBaseClass = ConstReferenceFunctionsImpl<S>;
		using PrivateBaseClass::PrivateBaseClass;
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, void, TimerRef, false>::type&() { return reinterpret_cast<const TimerRef&>(this->GetBaseRef()); }
/// @cond IGNORE

/// @endcond

	};
	template <typename ST> struct ReferenceFunctionsHelper : public std::conditional<maxon::Bool(ST::type::Handler::KIND & (maxon::VALUEKIND::COW_MASK | maxon::VALUEKIND::DEEP_CONSTNESS)), COWReferenceFunctionsImpl<typename ST::type>, typename std::conditional<std::is_const<typename ST::type::PrivateReferencedType>::value, ConstReferenceFunctionsImpl<typename ST::type>, ReferenceFunctionsImpl<typename ST::type>>::type> { };
};
class TimerInterface::Hxx1::Reference :
#ifdef DOXYGEN
public ReferenceFunctionsImplDoxy<TimerRef>
#else
public maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<TimerInterface, maxon::StrongRefHandler, TimerRef>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(Reference, maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<TimerInterface, maxon::StrongRefHandler, TimerRef>>>>);
	using NonConst = typename Super::ReferenceClass;
/// Allocators for common use.
	static MAXON_ATTRIBUTE_FORCE_INLINE maxon::ResultMemT<TimerRef> Create();
};

/// TimerRef is the reference class of TimerInterface.
///
/// The timer interface consists of several methods for periodic events.
class TimerRef : public TimerInterface::Hxx1::Reference
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(TimerRef, typename TimerInterface::Hxx1::Reference);
};

class TimerInterface::ObservableTimerStartedDelegate : public maxon::Delegate<void()>
{
public:
	using Super = maxon::Delegate<void()>;
	MAXON_MEMBERFUNCTION_DETECTOR(HandleTimerStarted);
	ObservableTimerStartedDelegate() = default;
	template <typename FN> static maxon::ResultOk<Super> Create(FN&& src, typename std::enable_if<HasHandleTimerStarted<typename maxon::Dereference<typename std::decay<FN>::type, false>::type>::value, void>::type* = nullptr) { return Super::CreateByReference(std::forward<FN>(src), &maxon::Dereference<typename std::decay<FN>::type, false>::type::HandleTimerStarted); }
	template <typename FN> static maxon::Result<Super> Create(FN&& src, typename std::enable_if<!HasHandleTimerStarted<typename maxon::Dereference<typename std::decay<FN>::type, false>::type>::value, void>::type* = nullptr){ return Super::Create(std::forward<FN>(src)); }
	using OBSERVABLECOMBINER = ObservableCombinerRunAllComponentPrivateHelper;
};

class TimerInterface::ObservableTimerFinishedDelegate : public maxon::Delegate<void()>
{
public:
	using Super = maxon::Delegate<void()>;
	MAXON_MEMBERFUNCTION_DETECTOR(HandleTimerFinished);
	ObservableTimerFinishedDelegate() = default;
	template <typename FN> static maxon::ResultOk<Super> Create(FN&& src, typename std::enable_if<HasHandleTimerFinished<typename maxon::Dereference<typename std::decay<FN>::type, false>::type>::value, void>::type* = nullptr) { return Super::CreateByReference(std::forward<FN>(src), &maxon::Dereference<typename std::decay<FN>::type, false>::type::HandleTimerFinished); }
	template <typename FN> static maxon::Result<Super> Create(FN&& src, typename std::enable_if<!HasHandleTimerFinished<typename maxon::Dereference<typename std::decay<FN>::type, false>::type>::value, void>::type* = nullptr){ return Super::Create(std::forward<FN>(src)); }
	using OBSERVABLECOMBINER = ObservableCombinerRunAllComponentPrivateHelper;
};

class TimerInterface::ObservableTimerOverloadDelegate : public maxon::Delegate<void(const TimeValue&,const TimeValue&)>
{
public:
	using Super = maxon::Delegate<void(const TimeValue&,const TimeValue&)>;
	MAXON_MEMBERFUNCTION_DETECTOR(HandleTimerOverload);
	ObservableTimerOverloadDelegate() = default;
	template <typename FN> static maxon::ResultOk<Super> Create(FN&& src, typename std::enable_if<HasHandleTimerOverload<typename maxon::Dereference<typename std::decay<FN>::type, false>::type>::value, void>::type* = nullptr) { return Super::CreateByReference(std::forward<FN>(src), &maxon::Dereference<typename std::decay<FN>::type, false>::type::HandleTimerOverload); }
	template <typename FN> static maxon::Result<Super> Create(FN&& src, typename std::enable_if<!HasHandleTimerOverload<typename maxon::Dereference<typename std::decay<FN>::type, false>::type>::value, void>::type* = nullptr){ return Super::Create(std::forward<FN>(src)); }
	using OBSERVABLECOMBINER = ObservableCombinerRunAllComponentPrivateHelper;
};

#endif
