#if 1
namespace maxon
{
	namespace enum23 { enum class JOBQUEUETYPE
	{
		MAINTHREAD				= 0,											///< Jobs are executed on the main thread whenever the event loop can spare some time: there is only one queue of this type: use GetMainThreadQueue() to access it.
		NONE							= 1,											///< Jobs are not enqueued but executed in the current context.
		LOWESTPRIORITY		= 2,											///< Use lowest priority threads (worker threads have lowest priority and will not idle when waiting for new jobs or waiting for a group to finish).
		LOWPRIORITY				= 3,											///< Use low priority threads.
		NORMALPRIORITY		= 4,											///< Use normal priority threads (You should rarely have to create a queue with normal priority. Most of the time low priority is sufficient: This makes sure that you don't interfere with really important tasks and if available you still get all cpu power).
		SERVICEIO					= 5,											///< Queue is used for IO and priority is adapted accordingly. Spinning on idle is not allowed.
		THREADLESS				= 6
	} ; }
	maxon::String PrivateToString_JOBQUEUETYPE23(std::underlying_type<enum23::JOBQUEUETYPE>::type x, const maxon::FormatStatement* fmt)
	{
		const maxon::UInt64 values[] = {(maxon::UInt64) enum23::JOBQUEUETYPE::MAINTHREAD, (maxon::UInt64) enum23::JOBQUEUETYPE::NONE, (maxon::UInt64) enum23::JOBQUEUETYPE::LOWESTPRIORITY, (maxon::UInt64) enum23::JOBQUEUETYPE::LOWPRIORITY, (maxon::UInt64) enum23::JOBQUEUETYPE::NORMALPRIORITY, (maxon::UInt64) enum23::JOBQUEUETYPE::SERVICEIO, (maxon::UInt64) enum23::JOBQUEUETYPE::THREADLESS};
		return maxon::StringInterface::PrivateEnumToString((maxon::UInt64) x, "JOBQUEUETYPE", SIZEOF(x), false, values, "MAINTHREAD\0NONE\0LOWESTPRIORITY\0LOWPRIORITY\0NORMALPRIORITY\0SERVICEIO\0THREADLESS\0", fmt);
	}
	namespace enum33 { enum class JOBQUEUEMODE
	{
		DEFAULT					= 0,												///< Use default settings for the queue.
		SPIN_ON_IDLE		= 1,												///< When there are no jobs threads will be spinning for a short moment before they go to sleep (low latency and highest performance but might unnecessary steals cycles from other threads).
		SLEEP_ON_IDLE		= 2,												///< When there are no jobs threads will immediately go to sleep (results in higher latency).
		DETACH_THREADS	= 3,												///< When there are no jobs the threads will immediately go to sleep and make themselves available to other queues (results in higher latency but less memory/resource usage).
		PSEUDO_THREADS	= 4													///< The workers behave like ordinary threads (JOBQUEUE_CURRENT points to the default queue and the threads don't have a worker thread index).
	} ; }
	maxon::String PrivateToString_JOBQUEUEMODE33(std::underlying_type<enum33::JOBQUEUEMODE>::type x, const maxon::FormatStatement* fmt)
	{
		const maxon::UInt64 values[] = {(maxon::UInt64) enum33::JOBQUEUEMODE::DEFAULT, (maxon::UInt64) enum33::JOBQUEUEMODE::SPIN_ON_IDLE, (maxon::UInt64) enum33::JOBQUEUEMODE::SLEEP_ON_IDLE, (maxon::UInt64) enum33::JOBQUEUEMODE::DETACH_THREADS, (maxon::UInt64) enum33::JOBQUEUEMODE::PSEUDO_THREADS};
		return maxon::StringInterface::PrivateEnumToString((maxon::UInt64) x, "JOBQUEUEMODE", SIZEOF(x), false, values, "DEFAULT\0SPIN_ON_IDLE\0SLEEP_ON_IDLE\0DETACH_THREADS\0PSEUDO_THREADS\0", fmt);
	}
/// @cond IGNORE

/// @endcond

	const maxon::Char* const JobQueueInterface::MTable::_ids = 
		"Free@62fc138e00c811b2\0" // void Free(const JobQueueInterface* object)
		"Alloc@49d181f952f4a215\0" // Result<JobQueueInterface*> Alloc(const maxon::SourceLocation& allocLocation, JOBQUEUETYPE type, Int threadCnt, JOBQUEUEMODE mode, const Char* name, UInt* ownerId)
		"GetThreadCount@4386c86\0" // Int GetThreadCount() const
		"GetThreadCount@c84b02c7b8c9da27\0" // Int GetThreadCount(JobQueueInterface* queue, Int maxWaitSessionLevel)
		"Cancel@5e65c15584e9\0" // void Cancel(UInt ownerId)
		"CancelAndWait@5e65c15584e9\0" // void CancelAndWait(UInt ownerId)
		"GetDestinationQueue@e73b7a3823e783c5\0" // JobQueueInterface* GetDestinationQueue()
		"SetDestinationQueue@67011626f513a486\0" // Result<void> SetDestinationQueue(JobQueueInterface* queue)
		"GetMainThreadQueue@e73b7a3823e783c5\0" // JobQueueInterface* GetMainThreadQueue()
		"GetServiceIOQueue@b94734451cdd8ec0\0" // ServiceIOJobQueueInterface* GetServiceIOQueue()
/// @cond IGNORE

		"ExecuteJobs@152dc1ffb7620655\0" // void ExecuteJobs(TimeValue timeout)
/// @endcond

	"";
	MAXON_WARNING_PUSH
	MAXON_WARNING_DISABLE_DEPRECATED
	class JobQueueInterface::Hxx2::Unresolved : public JobQueueInterface
	{
	public:
		static const Unresolved* Get(const JobQueueInterface* o) { return (const Unresolved*) o; }
		static Unresolved* Get(JobQueueInterface* o) { return (Unresolved*) o; }
		static void Free(const JobQueueInterface* object) { if (object && maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return JobQueueInterface::Free(object); return maxon::PrivateLogNullptrError();}
		static Result<JobQueueInterface*> Alloc(const maxon::SourceLocation& allocLocation, JOBQUEUETYPE type, Int threadCnt, JOBQUEUEMODE mode, const Char* name, UInt* ownerId) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return JobQueueInterface::Alloc(allocLocation, type, threadCnt, mode, name, ownerId); return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::UNRESOLVED);}
		Int GetThreadCount() const { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ((const JobQueueInterface*) this)->GetThreadCount(); return 0;}
		static Int GetThreadCount(JobQueueInterface* queue, Int maxWaitSessionLevel) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return JobQueueInterface::GetThreadCount(queue, maxWaitSessionLevel); return 0;}
		void Cancel(UInt ownerId) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ((JobQueueInterface*) this)->Cancel(ownerId); return maxon::PrivateLogNullptrError();}
		void CancelAndWait(UInt ownerId) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ((JobQueueInterface*) this)->CancelAndWait(ownerId); return maxon::PrivateLogNullptrError();}
		static JobQueueInterface* GetDestinationQueue() { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return JobQueueInterface::GetDestinationQueue(); return nullptr;}
		static Result<void> SetDestinationQueue(JobQueueInterface* queue) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return JobQueueInterface::SetDestinationQueue(queue); return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::UNRESOLVED);}
		static JobQueueInterface* GetMainThreadQueue() { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return JobQueueInterface::GetMainThreadQueue(); return nullptr;}
		static ServiceIOJobQueueInterface* GetServiceIOQueue() { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return JobQueueInterface::GetServiceIOQueue(); return nullptr;}
/// @cond IGNORE

		void ExecuteJobs(TimeValue timeout) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ((JobQueueInterface*) this)->ExecuteJobs(std::forward<TimeValue>(timeout)); return maxon::PrivateLogNullptrError();}
/// @endcond

	};
	MAXON_WARNING_POP
#ifdef PRIVATE_MAXON_ASSEMBLE_UNRESOLVED
	const maxon::NULL_RETURN_TYPE JobQueueInterface::MTable::_returnTypes[] = 
	{
		maxon::NULL_RETURN_TYPE::VOID_ZERO_FREE_FUNCTION,
		maxon::details::NullReturnType<Result<JobQueueInterface*>>::value,
		maxon::details::NullReturnType<Int>::value,
		maxon::details::NullReturnType<Int>::value,
		maxon::details::NullReturnType<void>::value,
		maxon::details::NullReturnType<void>::value,
		maxon::details::NullReturnType<JobQueueInterface*>::value,
		maxon::details::NullReturnType<Result<void>>::value,
		maxon::details::NullReturnType<JobQueueInterface*>::value,
		maxon::details::NullReturnType<ServiceIOJobQueueInterface*>::value,
/// @cond IGNORE

		maxon::details::NullReturnType<void>::value,
/// @endcond

		maxon::NULL_RETURN_TYPE::OTHER
	};
#endif
	maxon::Bool JobQueueInterface::MTable::InitUnresolved(maxon::NonvirtualInterfaceReference::UnresolvedAssembler assembler, MTable* tbl)
	{
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->_JobQueueInterface_Free = &Hxx2::Wrapper<Hxx2::Unresolved>::_JobQueueInterface_Free;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<JobQueueInterface*>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_JobQueueInterface_Alloc = &Hxx2::Wrapper<Hxx2::Unresolved>::_JobQueueInterface_Alloc;
		#else
		tbl->_JobQueueInterface_Alloc = &Hxx2::Wrapper<Hxx2::Unresolved>::_JobQueueInterface_Alloc;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->_JobQueueInterface_GetThreadCount = &Hxx2::Wrapper<Hxx2::Unresolved>::_JobQueueInterface_GetThreadCount;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->_JobQueueInterface_GetThreadCount_1 = &Hxx2::Wrapper<Hxx2::Unresolved>::_JobQueueInterface_GetThreadCount_1;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->_JobQueueInterface_Cancel = &Hxx2::Wrapper<Hxx2::Unresolved>::_JobQueueInterface_Cancel;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->_JobQueueInterface_CancelAndWait = &Hxx2::Wrapper<Hxx2::Unresolved>::_JobQueueInterface_CancelAndWait;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->_JobQueueInterface_GetDestinationQueue = &Hxx2::Wrapper<Hxx2::Unresolved>::_JobQueueInterface_GetDestinationQueue;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<void>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_JobQueueInterface_SetDestinationQueue = &Hxx2::Wrapper<Hxx2::Unresolved>::_JobQueueInterface_SetDestinationQueue;
		#else
		tbl->_JobQueueInterface_SetDestinationQueue = &Hxx2::Wrapper<Hxx2::Unresolved>::_JobQueueInterface_SetDestinationQueue;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->_JobQueueInterface_GetMainThreadQueue = &Hxx2::Wrapper<Hxx2::Unresolved>::_JobQueueInterface_GetMainThreadQueue;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->_JobQueueInterface_GetServiceIOQueue = &Hxx2::Wrapper<Hxx2::Unresolved>::_JobQueueInterface_GetServiceIOQueue;
		#endif
/// @cond IGNORE

		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->_JobQueueInterface_ExecuteJobs = &Hxx2::Wrapper<Hxx2::Unresolved>::_JobQueueInterface_ExecuteJobs;
		#endif
/// @endcond

	#ifdef PRIVATE_MAXON_ASSEMBLE_UNRESOLVED
		return assembler(&_interface, (maxon::Char*) tbl, _returnTypes, SIZEOF(MTable) / SIZEOF(void*));
	#else
		return true;
	#endif
	}
	MAXON_INTERFACE_REGISTER(JobQueueInterface, "net.maxon.interface.jobqueue", nullptr);
}
#endif
