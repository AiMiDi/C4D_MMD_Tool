#if 1
class JobQueueRef;

/// @cond IGNORE

/// @endcond

struct JobQueueInterface::Hxx1
{
	using ReferenceClass = JobQueueRef;
	/// Intermediate helper class for JobQueueInterface.
	template <typename S> class ConstReferenceFunctionsImpl DOXYGEN_SWITCH(: public S,)
	{
	public:
		ConstReferenceFunctionsImpl() = default;
		using PrivateBaseClass = S;
		using PrivateBaseClass::PrivateBaseClass;
		using Current = JobQueueInterface::Current;
		using None = JobQueueInterface::None;
/// Returns the number of threads used for the queue.
/// THREADSAFE.
/// @return												Number of threads.
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type GetThreadCount() const;
/// Returns the number of threads to be used.
/// THREADSAFE.
/// @param[in] queue							Queue interface pointer or JOBQUEUE_CURRENT, JOBQUEUE_NONE.
/// @param[in] maxWaitSessionLevel	Private: Maximum number of nested Wait() calls.
/// @return												Number of threads. Guaranteed to be >= 1 (even for JOBQUEUE_NONE).
		static inline Int GetThreadCount(JobQueueInterface* queue, Int maxWaitSessionLevel = LIMIT<Int>::MAX);
/// Returns the queue being used when you specify JOBQUEUE_CURRENT.
/// Usually the destination queue is the same as the queue of the current thread, but there
/// are exceptions: The main (UI) thread for example belongs to the main thread queue (returned
/// by GetMainThreadQueue()), but it has the default queue as target if you specify JOBQUEUE_CURRENT.
/// Furthermore there are rare cases (backward compatibility) where the destination queue
/// has been modified using SetDestinationQueue().
/// THREADSAFE.
/// @return												Destination queue (guaranteed to be a valid pointer).
		static inline JobQueueRef GetDestinationQueue();
/// Changes the queue that will be used when you enqueue a job/group from this thread and
/// specify JOBQUEUE_CURRENT. All threads created by the caller from now on will inherit
/// the queue.
/// <B> You must own the thread to call this method. Since all child threads will own the
/// the queue you must make sure it'll be referenced for the whole life time of these threads.
/// Removing a reference before these child threads have finished can result in a crash
/// because the threads will not own the queue or add a reference to it. </B>
/// If you have made sure the queue is not used anymore you can call SetDestinationQueue()
/// and switch back to the previous destination queue.
/// <B> Calling this method from within a job or group will result in an error. </B>
/// @param[in] queue							The queue to be used as JOBQUEUE_CURRENT.
/// @return												OK on success.
		static inline Result<void> SetDestinationQueue(JobQueueInterface* queue);
/// Returns the main thread job queue. If you want to run a job in the main thread's
/// context you can enqueue it specifying this queue. Jobs in the main thread queue will
/// be executed whenever the main thread checks for events. This means execution of a job
/// might be delayed if somebody performs a long blocking polling loop.
/// THREADSAFE.
/// @return												Main thread job queue (guaranteed to be a valid pointer).
		static inline JobQueueRef GetMainThreadQueue();
/// Returns a queue for asynchronous I/O and service jobs.
/// THREADSAFE.
/// @return												Service I/O queue (guaranteed to be a valid pointer).
		static inline ServiceIOJobQueueInterface* GetServiceIOQueue();
/// @cond IGNORE

/// @endcond

	};
	/// Intermediate helper class for JobQueueInterface.
	template <typename S> class ReferenceFunctionsImpl : public ConstReferenceFunctionsImpl<S>
	{
	public:
		ReferenceFunctionsImpl() = default;
		using PrivateBaseClass = ConstReferenceFunctionsImpl<S>;
		using PrivateBaseClass::PrivateBaseClass;
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongRefHandler, JobQueueRef, true>::type&() const { return reinterpret_cast<const JobQueueRef&>(this->GetBaseRef()); }
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongRefHandler, JobQueueRef, false>::type&() { return reinterpret_cast<const JobQueueRef&>(this->GetBaseRef()); }
/// Cancels execution of all jobs in the queue (including jobs which are enqueued after
/// this call). Usually the next step is to release the queue and free all its resources.
/// Only the owner of a queue can cancel it (requires the id returned by Init()). As usual
/// Cancel() will not wait and returns immediately after the cancel condition has been set.
/// THREADSAFE.
/// @param[in] ownerId						Owner id of the queue (only the owner is allowed to cancel a queue).
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type Cancel(UInt ownerId) const;
/// Cancels execution of all jobs in the queue (including jobs which are enqueued after
/// this call). Waits until the currently running jobs have finished.
/// Only the owner of a queue can cancel it (requires the id returned by Init()).
/// THREADSAFE.
/// @param[in] ownerId						Owner id of the queue (only the owner is allowed to cancel a queue).
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type CancelAndWait(UInt ownerId) const;
/// @cond IGNORE

/// Private: Executes the jobs in the main thread queue. Returns when the queue is empty or
/// the time-out duration has been exceeded.
/// @param[in] timeout						Maximum execution interval (or TIMEVALUE_INFINITE for no time-out).
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type ExecuteJobs(TimeValue timeout = TIMEVALUE_INFINITE) const;
/// @endcond

	};
	/// Intermediate helper class for JobQueueInterface.
	template <typename S> class COWReferenceFunctionsImpl : public ConstReferenceFunctionsImpl<S>
	{
	public:
		COWReferenceFunctionsImpl() = default;
		using PrivateBaseClass = ConstReferenceFunctionsImpl<S>;
		using PrivateBaseClass::PrivateBaseClass;
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, void, JobQueueRef, false>::type&() { return reinterpret_cast<const JobQueueRef&>(this->GetBaseRef()); }
/// @cond IGNORE

/// @endcond

	};
	template <typename ST> struct ReferenceFunctionsHelper : public std::conditional<maxon::Bool(ST::type::Handler::KIND & (maxon::VALUEKIND::COW_MASK | maxon::VALUEKIND::DEEP_CONSTNESS)), COWReferenceFunctionsImpl<typename ST::type>, typename std::conditional<std::is_const<typename ST::type::PrivateReferencedType>::value, ConstReferenceFunctionsImpl<typename ST::type>, ReferenceFunctionsImpl<typename ST::type>>::type> { };
};
class JobQueueInterface::Reference :
#ifdef DOXYGEN
public ReferenceFunctionsImplDoxy<JobQueueRef>
#else
public maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<JobQueueInterface, maxon::StrongRefHandler, JobQueueRef>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(Reference, maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<JobQueueInterface, maxon::StrongRefHandler, JobQueueRef>>>>);
	using NonConst = typename Super::ReferenceClass;
/// Creates and initializes a job queue.
/// Do not request more threads than CPU cores are available (use JOBQUEUE_USEMAXIMUMTHREADS
/// to request the maximum thread count or Application::GetMachineInfo() to get that information).
/// @param[in] type								Queue type.
/// @param[in] threadCnt					The number of threads used by the queue.
/// @param[in] mode								Scheduling options for the queue. Most of the time there's no need to specify something else than JOBQUEUEMODE::DEFAULT.
/// @param[in] name								The queue name.
/// @param[out] ownerId						Used to return the optional owner id of the queue (can be used for CancelAndWait).
	static MAXON_ATTRIBUTE_FORCE_INLINE maxon::Result<JobQueueRef> Create(JOBQUEUETYPE type, Int threadCnt, JOBQUEUEMODE mode, const Char* name, UInt* ownerId = nullptr);
};

#endif
