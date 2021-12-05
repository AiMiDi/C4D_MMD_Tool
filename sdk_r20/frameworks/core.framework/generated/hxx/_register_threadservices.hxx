#if 1
namespace maxon
{
	MAXON_INTERFACE_REGISTER_VIRTUAL_SINGLE_BASE(JobErrorInterface, "net.maxon.interface.joberror", "maxon.JobErrorInterface", , &ErrorInterface::_interface);
	const maxon::Char* const JobErrorInterface::MTable::_ids = 
	"";
	template <typename DUMMY> maxon::Int JobErrorInterface::PrivateInstantiateNullValueHelper()
	{
		return 0
		;
	}
	PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(JobErrorObject, , "net.maxon.error.job");
/// @cond INTERNAL

	const maxon::Char* const ThreadServices::MTable::_ids = 
		"Start@7edeb738ce5b3afb\0" // Start(const JobInterfacePOD& pod, THREADPRIORITY priority)
		"Enqueue@e4048116549c2b9b\0" // Enqueue(const JobInterfacePOD& pod, JobQueueInterface* queue)
		"Wait@ebeb78d3765f9b60\0" // Wait(const JobInterfacePOD& pod, Float64 timeout, WAITMODE mode)
		"GetResult@d00b577d05fba29f\0" // GetResult(const JobInterfacePOD& pod, Float64 timeout, WAITMODE mode)
		"Reset@0f44428d4a5045f1\0" // Reset(const JobInterfacePOD& pod)
		"Cancel@1659ebc1f694f39a\0" // Cancel(const JobInterfacePOD& pod)
		"AddFinishedObserver@4f067409c64d3ac6\0" // AddFinishedObserver(const JobInterfacePOD& pod, const JobInterfacePOD& observerPod, JobQueueInterface* observerQueue)
		"AddCancelledObserver@4f067409c64d3ac6\0" // AddCancelledObserver(const JobInterfacePOD& pod, const JobInterfacePOD& observerPod, JobQueueInterface* observerQueue)
		"IsRunning@87a4e7f738b9cf10\0" // IsRunning(const JobInterfacePOD& pod)
		"IsCancelled@87a4e7f738b9cf10\0" // IsCancelled(const JobInterfacePOD& pod)
		"AddJobReference@1659ebc1f694f39a\0" // AddJobReference(const JobInterfacePOD& pod)
		"RemoveJobReference@1659ebc1f694f39a\0" // RemoveJobReference(const JobInterfacePOD& pod)
		"CreateStrongJobReference@87a4e7f738b9cf10\0" // CreateStrongJobReference(const JobInterfacePOD& pod)
		"AddWeakJobReference@1dd2057551272a46\0" // AddWeakJobReference(const JobInterfacePOD& pod, WeakRefBase& weakRef)
		"GetGroup@ca0cb4d84d0395af\0" // GetGroup(const JobInterfacePOD& pod)
		"GetCurrentJob@00294dc84e62bfb1\0" // GetCurrentJob()
		"GetCurrentThread@a96b1b2609e4e558\0" // GetCurrentThread()
		"GetCurrentThreadType@1e782cc59e4b77a4\0" // GetCurrentThreadType()
		"GetCpuCount@4386c6f\0" // GetCpuCount()
		"GetStackEnd@19257ef7f6\0" // GetStackEnd()
		"CreateGroup@3bd45ad1e4aaddf5\0" // CreateGroup(Int cnt, Int jobSize, UInt flags)
		"AddGroupReference@ed5283de56720ced\0" // AddGroupReference(CoreJobGroup& group)
		"RemoveGroupReference@ed5283de56720ced\0" // RemoveGroupReference(CoreJobGroup& group)
		"WaitGroup@26cf71ebb51e3899\0" // WaitGroup(CoreJobGroup& group, Float64 timeout, WAITMODE mode)
		"GroupGetResult@331d78d9ac043e7a\0" // GroupGetResult(CoreJobGroup& group, Float64 timeout, WAITMODE mode)
		"AddJob@3c48a3118a7241ea\0" // AddJob(CoreJobGroup& group, const JobInterfacePOD& pod)
		"AddGroup@d2ff4f93e6c46519\0" // AddGroup(CoreJobGroup& group, CoreJobGroup* subGroup)
		"EnqueueGroup@dadc13358d06f368\0" // EnqueueGroup(CoreJobGroup& group, JobQueueInterface* queue)
		"EnqueueGroupAndWait@b9699ae58dfc84ff\0" // EnqueueGroupAndWait(CoreJobGroup& group, JobQueueInterface* queue)
		"GetStaticJobBuffer@948e56dce0e3de17\0" // GetStaticJobBuffer(const CoreJobGroup& group, Int* capacity)
		"GroupBatchAdd@86662f0f6d2b2df6\0" // GroupBatchAdd(CoreJobGroup& group, const JobInterfacePOD* first, void* memory, Int cnt, Int size)
		"AddGroupFinishedObserver@07af6f31a3831b4b\0" // AddGroupFinishedObserver(CoreJobGroup& group, const JobInterfacePOD& observerPod, JobQueueInterface* observerQueue)
		"GroupCancel@ed5283de56720ced\0" // GroupCancel(CoreJobGroup& group)
		"GroupMarkAsFinished@ed5283de56720ced\0" // GroupMarkAsFinished(CoreJobGroup& group)
		"GetCurrentWorkerThreadIndex@4386c6f\0" // GetCurrentWorkerThreadIndex()
		"IsCurrentJobCancelled@76f018ea\0" // IsCurrentJobCancelled()
		"CreateBarrier@62772b8c6ff158ab\0" // CreateBarrier()
		"EnqueueBarrier@ea66158b6d24e008\0" // EnqueueBarrier(JobBarrierInterface& barrier, JobQueueInterface* queue)
		"AssimilateAlienThread@0499ab9fb052ee8b\0" // AssimilateAlienThread()
		"ThreadedExclusiveResource@7d9a99a7958cad11\0" // ThreadedExclusiveResource(Int selector, const void* resourcePtr)
		"ThreadProfiling@c1344c263db7d2ce\0" // ThreadProfiling(Int mode, Block<ThreadInterface*> threads, Block<JobQueueInterface*> queues, QueueProfileData& data)
	"";
	class ThreadServices::Unresolved : public ThreadServices
	{
	public:
		static const Unresolved* Get(const ThreadServices* o) { return (const Unresolved*) o; }
		static Unresolved* Get(ThreadServices* o) { return (Unresolved*) o; }
		static Result<void> Start(const JobInterfacePOD& pod, THREADPRIORITY priority) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return ThreadServices::Start(pod, priority); return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::UNRESOLVED);}
		static void Enqueue(const JobInterfacePOD& pod, JobQueueInterface* queue) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ThreadServices::Enqueue(pod, queue); return maxon::PrivateLogNullptrError();}
		static Bool Wait(const JobInterfacePOD& pod, Float64 timeout, WAITMODE mode) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ThreadServices::Wait(pod, timeout, mode); return maxon::PrivateLogNullptrError(false);}
		static Result<void> GetResult(const JobInterfacePOD& pod, Float64 timeout, WAITMODE mode) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return ThreadServices::GetResult(pod, timeout, mode); return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::UNRESOLVED);}
		static Result<void> Reset(const JobInterfacePOD& pod) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return ThreadServices::Reset(pod); return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::UNRESOLVED);}
		static void Cancel(const JobInterfacePOD& pod) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ThreadServices::Cancel(pod); return maxon::PrivateLogNullptrError();}
		static Result<void> AddFinishedObserver(const JobInterfacePOD& pod, const JobInterfacePOD& observerPod, JobQueueInterface* observerQueue) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return ThreadServices::AddFinishedObserver(pod, observerPod, observerQueue); return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::UNRESOLVED);}
		static Result<void> AddCancelledObserver(const JobInterfacePOD& pod, const JobInterfacePOD& observerPod, JobQueueInterface* observerQueue) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return ThreadServices::AddCancelledObserver(pod, observerPod, observerQueue); return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::UNRESOLVED);}
		static Bool IsRunning(const JobInterfacePOD& pod) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ThreadServices::IsRunning(pod); return maxon::PrivateLogNullptrError(false);}
		static Bool IsCancelled(const JobInterfacePOD& pod) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ThreadServices::IsCancelled(pod); return maxon::PrivateLogNullptrError(false);}
		static void AddJobReference(const JobInterfacePOD& pod) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ThreadServices::AddJobReference(pod); return maxon::PrivateLogNullptrError();}
		static void RemoveJobReference(const JobInterfacePOD& pod) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ThreadServices::RemoveJobReference(pod); return maxon::PrivateLogNullptrError();}
		static Bool CreateStrongJobReference(const JobInterfacePOD& pod) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ThreadServices::CreateStrongJobReference(pod); return maxon::PrivateLogNullptrError(false);}
		static void AddWeakJobReference(const JobInterfacePOD& pod, WeakRefBase& weakRef) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ThreadServices::AddWeakJobReference(pod, weakRef); return maxon::PrivateLogNullptrError();}
		static CoreJobGroup* GetGroup(const JobInterfacePOD& pod) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ThreadServices::GetGroup(pod); return nullptr;}
		static const JobInterface* GetCurrentJob() { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ThreadServices::GetCurrentJob(); return nullptr;}
		static const ThreadInterface* GetCurrentThread() { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ThreadServices::GetCurrentThread(); return nullptr;}
		static THREADTYPE GetCurrentThreadType() { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ThreadServices::GetCurrentThreadType(); return maxon::PrivateIncompleteNullReturnValue<THREADTYPE>(maxon::NULL_RETURN_REASON::UNRESOLVED, OVERLOAD_MAX_RANK);}
		static Int GetCpuCount() { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ThreadServices::GetCpuCount(); return 0;}
		static void* GetStackEnd() { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ThreadServices::GetStackEnd(); return nullptr;}
		static CoreJobGroup* CreateGroup(Int cnt, Int jobSize, UInt flags) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ThreadServices::CreateGroup(cnt, jobSize, flags); return nullptr;}
		static void AddGroupReference(CoreJobGroup& group) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ThreadServices::AddGroupReference(group); return maxon::PrivateLogNullptrError();}
		static void RemoveGroupReference(CoreJobGroup& group) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ThreadServices::RemoveGroupReference(group); return maxon::PrivateLogNullptrError();}
		static Bool WaitGroup(CoreJobGroup& group, Float64 timeout, WAITMODE mode) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ThreadServices::WaitGroup(group, timeout, mode); return maxon::PrivateLogNullptrError(false);}
		static Result<void> GroupGetResult(CoreJobGroup& group, Float64 timeout, WAITMODE mode) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return ThreadServices::GroupGetResult(group, timeout, mode); return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::UNRESOLVED);}
		static Result<void> AddJob(CoreJobGroup& group, const JobInterfacePOD& pod) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return ThreadServices::AddJob(group, pod); return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::UNRESOLVED);}
		static Result<void> AddGroup(CoreJobGroup& group, CoreJobGroup* subGroup) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return ThreadServices::AddGroup(group, subGroup); return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::UNRESOLVED);}
		static void EnqueueGroup(CoreJobGroup& group, JobQueueInterface* queue) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ThreadServices::EnqueueGroup(group, queue); return maxon::PrivateLogNullptrError();}
		static Result<void> EnqueueGroupAndWait(CoreJobGroup& group, JobQueueInterface* queue) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return ThreadServices::EnqueueGroupAndWait(group, queue); return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::UNRESOLVED);}
		static void* GetStaticJobBuffer(const CoreJobGroup& group, Int* capacity) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ThreadServices::GetStaticJobBuffer(group, capacity); return nullptr;}
		static Result<void> GroupBatchAdd(CoreJobGroup& group, const JobInterfacePOD* first, void* memory, Int cnt, Int size) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return ThreadServices::GroupBatchAdd(group, first, memory, cnt, size); return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::UNRESOLVED);}
		static Result<void> AddGroupFinishedObserver(CoreJobGroup& group, const JobInterfacePOD& observerPod, JobQueueInterface* observerQueue) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return ThreadServices::AddGroupFinishedObserver(group, observerPod, observerQueue); return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::UNRESOLVED);}
		static void GroupCancel(CoreJobGroup& group) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ThreadServices::GroupCancel(group); return maxon::PrivateLogNullptrError();}
		static void GroupMarkAsFinished(CoreJobGroup& group) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ThreadServices::GroupMarkAsFinished(group); return maxon::PrivateLogNullptrError();}
		static Int GetCurrentWorkerThreadIndex() { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ThreadServices::GetCurrentWorkerThreadIndex(); return 0;}
		static Bool IsCurrentJobCancelled() { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ThreadServices::IsCurrentJobCancelled(); return maxon::PrivateLogNullptrError(false);}
		static JobBarrierInterface* CreateBarrier() { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ThreadServices::CreateBarrier(); return nullptr;}
		static void EnqueueBarrier(JobBarrierInterface& barrier, JobQueueInterface* queue) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ThreadServices::EnqueueBarrier(barrier, queue); return maxon::PrivateLogNullptrError();}
		static Result<void> AssimilateAlienThread() { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return ThreadServices::AssimilateAlienThread(); return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::UNRESOLVED);}
		static const void* ThreadedExclusiveResource(Int selector, const void* resourcePtr) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ThreadServices::ThreadedExclusiveResource(selector, resourcePtr); return nullptr;}
		static Result<void> ThreadProfiling(Int mode, Block<ThreadInterface*> threads, Block<JobQueueInterface*> queues, QueueProfileData& data) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return ThreadServices::ThreadProfiling(mode, std::forward<Block<ThreadInterface*>>(threads), std::forward<Block<JobQueueInterface*>>(queues), data); return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::UNRESOLVED);}
	};
#ifdef PRIVATE_MAXON_ASSEMBLE_UNRESOLVED
	const maxon::NULL_RETURN_TYPE ThreadServices::MTable::_returnTypes[] = 
	{
		maxon::details::NullReturnType<Result<void>>::value,
		maxon::details::NullReturnType<void>::value,
		maxon::details::NullReturnType<Bool>::value,
		maxon::details::NullReturnType<Result<void>>::value,
		maxon::details::NullReturnType<Result<void>>::value,
		maxon::details::NullReturnType<void>::value,
		maxon::details::NullReturnType<Result<void>>::value,
		maxon::details::NullReturnType<Result<void>>::value,
		maxon::details::NullReturnType<Bool>::value,
		maxon::details::NullReturnType<Bool>::value,
		maxon::details::NullReturnType<void>::value,
		maxon::details::NullReturnType<void>::value,
		maxon::details::NullReturnType<Bool>::value,
		maxon::details::NullReturnType<void>::value,
		maxon::details::NullReturnType<CoreJobGroup*>::value,
		maxon::details::NullReturnType<const JobInterface*>::value,
		maxon::details::NullReturnType<const ThreadInterface*>::value,
		maxon::details::NullReturnType<THREADTYPE>::value,
		maxon::details::NullReturnType<Int>::value,
		maxon::details::NullReturnType<void*>::value,
		maxon::details::NullReturnType<CoreJobGroup*>::value,
		maxon::details::NullReturnType<void>::value,
		maxon::details::NullReturnType<void>::value,
		maxon::details::NullReturnType<Bool>::value,
		maxon::details::NullReturnType<Result<void>>::value,
		maxon::details::NullReturnType<Result<void>>::value,
		maxon::details::NullReturnType<Result<void>>::value,
		maxon::details::NullReturnType<void>::value,
		maxon::details::NullReturnType<Result<void>>::value,
		maxon::details::NullReturnType<void*>::value,
		maxon::details::NullReturnType<Result<void>>::value,
		maxon::details::NullReturnType<Result<void>>::value,
		maxon::details::NullReturnType<void>::value,
		maxon::details::NullReturnType<void>::value,
		maxon::details::NullReturnType<Int>::value,
		maxon::details::NullReturnType<Bool>::value,
		maxon::details::NullReturnType<JobBarrierInterface*>::value,
		maxon::details::NullReturnType<void>::value,
		maxon::details::NullReturnType<Result<void>>::value,
		maxon::details::NullReturnType<const void*>::value,
		maxon::details::NullReturnType<Result<void>>::value,
		maxon::NULL_RETURN_TYPE::OTHER
	};
#endif
	maxon::Bool ThreadServices::MTable::InitUnresolved(maxon::NonvirtualInterfaceReference::UnresolvedAssembler assembler, MTable* tbl)
	{
	#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<void>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_ThreadServices_Start = &Wrapper<Unresolved>::_ThreadServices_Start;
	#else
		tbl->_ThreadServices_Start = &Wrapper<Unresolved>::_ThreadServices_Start;
	#endif
	#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
	#else
		tbl->_ThreadServices_Enqueue = &Wrapper<Unresolved>::_ThreadServices_Enqueue;
	#endif
	#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
	#else
		tbl->_ThreadServices_Wait = &Wrapper<Unresolved>::_ThreadServices_Wait;
	#endif
	#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<void>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_ThreadServices_GetResult = &Wrapper<Unresolved>::_ThreadServices_GetResult;
	#else
		tbl->_ThreadServices_GetResult = &Wrapper<Unresolved>::_ThreadServices_GetResult;
	#endif
	#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<void>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_ThreadServices_Reset = &Wrapper<Unresolved>::_ThreadServices_Reset;
	#else
		tbl->_ThreadServices_Reset = &Wrapper<Unresolved>::_ThreadServices_Reset;
	#endif
	#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
	#else
		tbl->_ThreadServices_Cancel = &Wrapper<Unresolved>::_ThreadServices_Cancel;
	#endif
	#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<void>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_ThreadServices_AddFinishedObserver = &Wrapper<Unresolved>::_ThreadServices_AddFinishedObserver;
	#else
		tbl->_ThreadServices_AddFinishedObserver = &Wrapper<Unresolved>::_ThreadServices_AddFinishedObserver;
	#endif
	#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<void>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_ThreadServices_AddCancelledObserver = &Wrapper<Unresolved>::_ThreadServices_AddCancelledObserver;
	#else
		tbl->_ThreadServices_AddCancelledObserver = &Wrapper<Unresolved>::_ThreadServices_AddCancelledObserver;
	#endif
	#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
	#else
		tbl->_ThreadServices_IsRunning = &Wrapper<Unresolved>::_ThreadServices_IsRunning;
	#endif
	#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
	#else
		tbl->_ThreadServices_IsCancelled = &Wrapper<Unresolved>::_ThreadServices_IsCancelled;
	#endif
	#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
	#else
		tbl->_ThreadServices_AddJobReference = &Wrapper<Unresolved>::_ThreadServices_AddJobReference;
	#endif
	#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
	#else
		tbl->_ThreadServices_RemoveJobReference = &Wrapper<Unresolved>::_ThreadServices_RemoveJobReference;
	#endif
	#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
	#else
		tbl->_ThreadServices_CreateStrongJobReference = &Wrapper<Unresolved>::_ThreadServices_CreateStrongJobReference;
	#endif
	#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
	#else
		tbl->_ThreadServices_AddWeakJobReference = &Wrapper<Unresolved>::_ThreadServices_AddWeakJobReference;
	#endif
	#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
	#else
		tbl->_ThreadServices_GetGroup = &Wrapper<Unresolved>::_ThreadServices_GetGroup;
	#endif
	#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
	#else
		tbl->_ThreadServices_GetCurrentJob = &Wrapper<Unresolved>::_ThreadServices_GetCurrentJob;
	#endif
	#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
	#else
		tbl->_ThreadServices_GetCurrentThread = &Wrapper<Unresolved>::_ThreadServices_GetCurrentThread;
	#endif
	#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<THREADTYPE>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_ThreadServices_GetCurrentThreadType = &Wrapper<Unresolved>::_ThreadServices_GetCurrentThreadType;
	#else
		tbl->_ThreadServices_GetCurrentThreadType = &Wrapper<Unresolved>::_ThreadServices_GetCurrentThreadType;
	#endif
	#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
	#else
		tbl->_ThreadServices_GetCpuCount = &Wrapper<Unresolved>::_ThreadServices_GetCpuCount;
	#endif
	#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
	#else
		tbl->_ThreadServices_GetStackEnd = &Wrapper<Unresolved>::_ThreadServices_GetStackEnd;
	#endif
	#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
	#else
		tbl->_ThreadServices_CreateGroup = &Wrapper<Unresolved>::_ThreadServices_CreateGroup;
	#endif
	#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
	#else
		tbl->_ThreadServices_AddGroupReference = &Wrapper<Unresolved>::_ThreadServices_AddGroupReference;
	#endif
	#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
	#else
		tbl->_ThreadServices_RemoveGroupReference = &Wrapper<Unresolved>::_ThreadServices_RemoveGroupReference;
	#endif
	#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
	#else
		tbl->_ThreadServices_WaitGroup = &Wrapper<Unresolved>::_ThreadServices_WaitGroup;
	#endif
	#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<void>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_ThreadServices_GroupGetResult = &Wrapper<Unresolved>::_ThreadServices_GroupGetResult;
	#else
		tbl->_ThreadServices_GroupGetResult = &Wrapper<Unresolved>::_ThreadServices_GroupGetResult;
	#endif
	#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<void>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_ThreadServices_AddJob = &Wrapper<Unresolved>::_ThreadServices_AddJob;
	#else
		tbl->_ThreadServices_AddJob = &Wrapper<Unresolved>::_ThreadServices_AddJob;
	#endif
	#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<void>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_ThreadServices_AddGroup = &Wrapper<Unresolved>::_ThreadServices_AddGroup;
	#else
		tbl->_ThreadServices_AddGroup = &Wrapper<Unresolved>::_ThreadServices_AddGroup;
	#endif
	#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
	#else
		tbl->_ThreadServices_EnqueueGroup = &Wrapper<Unresolved>::_ThreadServices_EnqueueGroup;
	#endif
	#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<void>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_ThreadServices_EnqueueGroupAndWait = &Wrapper<Unresolved>::_ThreadServices_EnqueueGroupAndWait;
	#else
		tbl->_ThreadServices_EnqueueGroupAndWait = &Wrapper<Unresolved>::_ThreadServices_EnqueueGroupAndWait;
	#endif
	#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
	#else
		tbl->_ThreadServices_GetStaticJobBuffer = &Wrapper<Unresolved>::_ThreadServices_GetStaticJobBuffer;
	#endif
	#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<void>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_ThreadServices_GroupBatchAdd = &Wrapper<Unresolved>::_ThreadServices_GroupBatchAdd;
	#else
		tbl->_ThreadServices_GroupBatchAdd = &Wrapper<Unresolved>::_ThreadServices_GroupBatchAdd;
	#endif
	#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<void>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_ThreadServices_AddGroupFinishedObserver = &Wrapper<Unresolved>::_ThreadServices_AddGroupFinishedObserver;
	#else
		tbl->_ThreadServices_AddGroupFinishedObserver = &Wrapper<Unresolved>::_ThreadServices_AddGroupFinishedObserver;
	#endif
	#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
	#else
		tbl->_ThreadServices_GroupCancel = &Wrapper<Unresolved>::_ThreadServices_GroupCancel;
	#endif
	#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
	#else
		tbl->_ThreadServices_GroupMarkAsFinished = &Wrapper<Unresolved>::_ThreadServices_GroupMarkAsFinished;
	#endif
	#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
	#else
		tbl->_ThreadServices_GetCurrentWorkerThreadIndex = &Wrapper<Unresolved>::_ThreadServices_GetCurrentWorkerThreadIndex;
	#endif
	#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
	#else
		tbl->_ThreadServices_IsCurrentJobCancelled = &Wrapper<Unresolved>::_ThreadServices_IsCurrentJobCancelled;
	#endif
	#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
	#else
		tbl->_ThreadServices_CreateBarrier = &Wrapper<Unresolved>::_ThreadServices_CreateBarrier;
	#endif
	#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
	#else
		tbl->_ThreadServices_EnqueueBarrier = &Wrapper<Unresolved>::_ThreadServices_EnqueueBarrier;
	#endif
	#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<void>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_ThreadServices_AssimilateAlienThread = &Wrapper<Unresolved>::_ThreadServices_AssimilateAlienThread;
	#else
		tbl->_ThreadServices_AssimilateAlienThread = &Wrapper<Unresolved>::_ThreadServices_AssimilateAlienThread;
	#endif
	#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
	#else
		tbl->_ThreadServices_ThreadedExclusiveResource = &Wrapper<Unresolved>::_ThreadServices_ThreadedExclusiveResource;
	#endif
	#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<void>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_ThreadServices_ThreadProfiling = &Wrapper<Unresolved>::_ThreadServices_ThreadProfiling;
	#else
		tbl->_ThreadServices_ThreadProfiling = &Wrapper<Unresolved>::_ThreadServices_ThreadProfiling;
	#endif
	#ifdef PRIVATE_MAXON_ASSEMBLE_UNRESOLVED
		return assembler(&_interface, (maxon::Char*) tbl, _returnTypes, SIZEOF(_returnTypes) - 1);
	#else
		return true;
	#endif
	}
	MAXON_INTERFACE_REGISTER(ThreadServices, "net.maxon.interface.threadservices", nullptr);
	template <typename DUMMY> maxon::Int ThreadServices::PrivateInstantiateNullValueHelper()
	{
		return 0
		| maxon::details::InstantiateNullReturnValue<THREADTYPE>(OVERLOAD_MAX_RANK)
		;
	}
/// @endcond

}
#endif
static maxon::details::ForceEvaluation s_forceEval_threadservices(0
	| maxon::JobErrorInterface::PrivateInstantiateNullValueHelper<maxon::Int>()
	| maxon::ThreadServices::PrivateInstantiateNullValueHelper<maxon::Int>()
);
