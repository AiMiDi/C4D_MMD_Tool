
#ifndef DOXYGEN

#ifdef MAXON_COMPILER_GCC
	#pragma GCC diagnostic push
	#pragma GCC diagnostic ignored "-Wmisleading-indentation"
#endif

#if 1

struct JobErrorInterface::MTable
{
	static const maxon::Char* const _ids;
	static const maxon::Bool HAS_NONSTATIC = false;
	template <typename W> void Init(maxon::Int offset)
	{
	}
	template <typename W> static maxon::Bool InitWithBases(maxon::ClassInfo* info, maxon::Int offset)
	{
		if (!W::Implementation::PROXY && (!ErrorInterface::MTable::InitWithBases<W>(info, offset))) return false;
		MTable* vt = (MTable*) maxon::Object::PrivateGetOrCreateMTable(info, _interface); if (!vt) return false;
		vt->Init<W>(offset); return true;
	}
	template <typename S> using CombinedMTable = maxon::CombinedMTable<JobErrorInterface, ErrorInterface::MTable::CombinedMTable<S>>;
	PRIVATE_MAXON_COMPBASE(JobErrorInterface);
	template <typename I> static const typename I::MTable& GetMTable() { return maxon::GetZeroRef<typename I::MTable>(); }
};

template <typename S> class JobErrorInterface::Wrapper : public ErrorInterface::Wrapper<S>
{
public:
};


auto JobErrorInterface::GetPtr() -> Ptr { return Ptr(this); }
auto JobErrorInterface::GetPtr() const -> ConstPtr { return ConstPtr(this); }
#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT)
static maxon::EntityUse s_ui_maxon_JobErrorInterface(JobErrorInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/threadservices.h", false);
#endif
/// @cond INTERNAL


struct ThreadServices::MTable
{
	static MTable _instance;
	static MTable _unresolvedInstance;
	static const maxon::Char* const _ids;
	static maxon::Bool InitUnresolved(maxon::NonvirtualInterfaceReference::UnresolvedAssembler assembler, MTable* tbl);
	static const maxon::NULL_RETURN_TYPE _returnTypes[];
	static const maxon::Bool HAS_NONSTATIC = false;
	Result<void> (*_ThreadServices_Start) (const JobInterfacePOD& pod, THREADPRIORITY priority);
	void (*_ThreadServices_Enqueue) (const JobInterfacePOD& pod, JobQueueInterface* queue);
	Bool (*_ThreadServices_Wait) (const JobInterfacePOD& pod, Float64 timeout, WAITMODE mode);
	Result<void> (*_ThreadServices_GetResult) (const JobInterfacePOD& pod, Float64 timeout, WAITMODE mode);
	Result<void> (*_ThreadServices_Reset) (const JobInterfacePOD& pod);
	void (*_ThreadServices_Cancel) (const JobInterfacePOD& pod);
	Result<void> (*_ThreadServices_AddFinishedObserver) (const JobInterfacePOD& pod, const JobInterfacePOD& observerPod, JobQueueInterface* observerQueue);
	Result<void> (*_ThreadServices_AddCancelledObserver) (const JobInterfacePOD& pod, const JobInterfacePOD& observerPod, JobQueueInterface* observerQueue);
	Bool (*_ThreadServices_IsRunning) (const JobInterfacePOD& pod);
	Bool (*_ThreadServices_IsCancelled) (const JobInterfacePOD& pod);
	void (*_ThreadServices_AddJobReference) (const JobInterfacePOD& pod);
	void (*_ThreadServices_RemoveJobReference) (const JobInterfacePOD& pod);
	Bool (*_ThreadServices_CreateStrongJobReference) (const JobInterfacePOD& pod);
	void (*_ThreadServices_AddWeakJobReference) (const JobInterfacePOD& pod, WeakRefBase& weakRef);
	CoreJobGroup* (*_ThreadServices_GetGroup) (const JobInterfacePOD& pod);
	const JobInterface* (*_ThreadServices_GetCurrentJob) ();
	const ThreadInterface* (*_ThreadServices_GetCurrentThread) ();
	THREADTYPE (*_ThreadServices_GetCurrentThreadType) ();
	Int (*_ThreadServices_GetCpuCount) ();
	void* (*_ThreadServices_GetStackEnd) ();
	CoreJobGroup* (*_ThreadServices_CreateGroup) (Int cnt, Int jobSize, UInt flags);
	void (*_ThreadServices_AddGroupReference) (CoreJobGroup& group);
	void (*_ThreadServices_RemoveGroupReference) (CoreJobGroup& group);
	Bool (*_ThreadServices_WaitGroup) (CoreJobGroup& group, Float64 timeout, WAITMODE mode);
	Result<void> (*_ThreadServices_GroupGetResult) (CoreJobGroup& group, Float64 timeout, WAITMODE mode);
	Result<void> (*_ThreadServices_AddJob) (CoreJobGroup& group, const JobInterfacePOD& pod);
	Result<void> (*_ThreadServices_AddGroup) (CoreJobGroup& group, CoreJobGroup* subGroup);
	void (*_ThreadServices_EnqueueGroup) (CoreJobGroup& group, JobQueueInterface* queue);
	Result<void> (*_ThreadServices_EnqueueGroupAndWait) (CoreJobGroup& group, JobQueueInterface* queue);
	void* (*_ThreadServices_GetStaticJobBuffer) (const CoreJobGroup& group, Int* capacity);
	Result<void> (*_ThreadServices_GroupBatchAdd) (CoreJobGroup& group, const JobInterfacePOD* first, void* memory, Int cnt, Int size);
	Result<void> (*_ThreadServices_AddGroupFinishedObserver) (CoreJobGroup& group, const JobInterfacePOD& observerPod, JobQueueInterface* observerQueue);
	void (*_ThreadServices_GroupCancel) (CoreJobGroup& group);
	void (*_ThreadServices_GroupMarkAsFinished) (CoreJobGroup& group);
	Int (*_ThreadServices_GetCurrentWorkerThreadIndex) ();
	Bool (*_ThreadServices_IsCurrentJobCancelled) ();
	JobBarrierInterface* (*_ThreadServices_CreateBarrier) ();
	void (*_ThreadServices_EnqueueBarrier) (JobBarrierInterface& barrier, JobQueueInterface* queue);
	Result<void> (*_ThreadServices_AssimilateAlienThread) ();
	const void* (*_ThreadServices_ThreadedExclusiveResource) (Int selector, const void* resourcePtr);
	Result<void> (*_ThreadServices_ThreadProfiling) (Int mode, Block<ThreadInterface*> threads, Block<JobQueueInterface*> queues, QueueProfileData& data);
	template <typename IMPL> static void Init(MTable* tbl)
	{
		tbl->_ThreadServices_Start = &IMPL::_ThreadServices_Start;
		tbl->_ThreadServices_Enqueue = &IMPL::_ThreadServices_Enqueue;
		tbl->_ThreadServices_Wait = &IMPL::_ThreadServices_Wait;
		tbl->_ThreadServices_GetResult = &IMPL::_ThreadServices_GetResult;
		tbl->_ThreadServices_Reset = &IMPL::_ThreadServices_Reset;
		tbl->_ThreadServices_Cancel = &IMPL::_ThreadServices_Cancel;
		tbl->_ThreadServices_AddFinishedObserver = &IMPL::_ThreadServices_AddFinishedObserver;
		tbl->_ThreadServices_AddCancelledObserver = &IMPL::_ThreadServices_AddCancelledObserver;
		tbl->_ThreadServices_IsRunning = &IMPL::_ThreadServices_IsRunning;
		tbl->_ThreadServices_IsCancelled = &IMPL::_ThreadServices_IsCancelled;
		tbl->_ThreadServices_AddJobReference = &IMPL::_ThreadServices_AddJobReference;
		tbl->_ThreadServices_RemoveJobReference = &IMPL::_ThreadServices_RemoveJobReference;
		tbl->_ThreadServices_CreateStrongJobReference = &IMPL::_ThreadServices_CreateStrongJobReference;
		tbl->_ThreadServices_AddWeakJobReference = &IMPL::_ThreadServices_AddWeakJobReference;
		tbl->_ThreadServices_GetGroup = &IMPL::_ThreadServices_GetGroup;
		tbl->_ThreadServices_GetCurrentJob = &IMPL::_ThreadServices_GetCurrentJob;
		tbl->_ThreadServices_GetCurrentThread = &IMPL::_ThreadServices_GetCurrentThread;
		tbl->_ThreadServices_GetCurrentThreadType = &IMPL::_ThreadServices_GetCurrentThreadType;
		tbl->_ThreadServices_GetCpuCount = &IMPL::_ThreadServices_GetCpuCount;
		tbl->_ThreadServices_GetStackEnd = &IMPL::_ThreadServices_GetStackEnd;
		tbl->_ThreadServices_CreateGroup = &IMPL::_ThreadServices_CreateGroup;
		tbl->_ThreadServices_AddGroupReference = &IMPL::_ThreadServices_AddGroupReference;
		tbl->_ThreadServices_RemoveGroupReference = &IMPL::_ThreadServices_RemoveGroupReference;
		tbl->_ThreadServices_WaitGroup = &IMPL::_ThreadServices_WaitGroup;
		tbl->_ThreadServices_GroupGetResult = &IMPL::_ThreadServices_GroupGetResult;
		tbl->_ThreadServices_AddJob = &IMPL::_ThreadServices_AddJob;
		tbl->_ThreadServices_AddGroup = &IMPL::_ThreadServices_AddGroup;
		tbl->_ThreadServices_EnqueueGroup = &IMPL::_ThreadServices_EnqueueGroup;
		tbl->_ThreadServices_EnqueueGroupAndWait = &IMPL::_ThreadServices_EnqueueGroupAndWait;
		tbl->_ThreadServices_GetStaticJobBuffer = &IMPL::_ThreadServices_GetStaticJobBuffer;
		tbl->_ThreadServices_GroupBatchAdd = &IMPL::_ThreadServices_GroupBatchAdd;
		tbl->_ThreadServices_AddGroupFinishedObserver = &IMPL::_ThreadServices_AddGroupFinishedObserver;
		tbl->_ThreadServices_GroupCancel = &IMPL::_ThreadServices_GroupCancel;
		tbl->_ThreadServices_GroupMarkAsFinished = &IMPL::_ThreadServices_GroupMarkAsFinished;
		tbl->_ThreadServices_GetCurrentWorkerThreadIndex = &IMPL::_ThreadServices_GetCurrentWorkerThreadIndex;
		tbl->_ThreadServices_IsCurrentJobCancelled = &IMPL::_ThreadServices_IsCurrentJobCancelled;
		tbl->_ThreadServices_CreateBarrier = &IMPL::_ThreadServices_CreateBarrier;
		tbl->_ThreadServices_EnqueueBarrier = &IMPL::_ThreadServices_EnqueueBarrier;
		tbl->_ThreadServices_AssimilateAlienThread = &IMPL::_ThreadServices_AssimilateAlienThread;
		tbl->_ThreadServices_ThreadedExclusiveResource = &IMPL::_ThreadServices_ThreadedExclusiveResource;
		tbl->_ThreadServices_ThreadProfiling = &IMPL::_ThreadServices_ThreadProfiling;
	}
};

template <typename C> class ThreadServices::Wrapper
{
public:
	static Result<void> _ThreadServices_Start(const JobInterfacePOD& pod, THREADPRIORITY priority) { return C::Start(pod, priority); }
	static void _ThreadServices_Enqueue(const JobInterfacePOD& pod, JobQueueInterface* queue) { return C::Enqueue(pod, queue); }
	static Bool _ThreadServices_Wait(const JobInterfacePOD& pod, Float64 timeout, WAITMODE mode) { return C::Wait(pod, timeout, mode); }
	static Result<void> _ThreadServices_GetResult(const JobInterfacePOD& pod, Float64 timeout, WAITMODE mode) { return C::GetResult(pod, timeout, mode); }
	static Result<void> _ThreadServices_Reset(const JobInterfacePOD& pod) { return C::Reset(pod); }
	static void _ThreadServices_Cancel(const JobInterfacePOD& pod) { return C::Cancel(pod); }
	static Result<void> _ThreadServices_AddFinishedObserver(const JobInterfacePOD& pod, const JobInterfacePOD& observerPod, JobQueueInterface* observerQueue) { return C::AddFinishedObserver(pod, observerPod, observerQueue); }
	static Result<void> _ThreadServices_AddCancelledObserver(const JobInterfacePOD& pod, const JobInterfacePOD& observerPod, JobQueueInterface* observerQueue) { return C::AddCancelledObserver(pod, observerPod, observerQueue); }
	static Bool _ThreadServices_IsRunning(const JobInterfacePOD& pod) { return C::IsRunning(pod); }
	static Bool _ThreadServices_IsCancelled(const JobInterfacePOD& pod) { return C::IsCancelled(pod); }
	static void _ThreadServices_AddJobReference(const JobInterfacePOD& pod) { return C::AddJobReference(pod); }
	static void _ThreadServices_RemoveJobReference(const JobInterfacePOD& pod) { return C::RemoveJobReference(pod); }
	static Bool _ThreadServices_CreateStrongJobReference(const JobInterfacePOD& pod) { return C::CreateStrongJobReference(pod); }
	static void _ThreadServices_AddWeakJobReference(const JobInterfacePOD& pod, WeakRefBase& weakRef) { return C::AddWeakJobReference(pod, weakRef); }
	static CoreJobGroup* _ThreadServices_GetGroup(const JobInterfacePOD& pod) { return C::GetGroup(pod); }
	static const JobInterface* _ThreadServices_GetCurrentJob() { return C::GetCurrentJob(); }
	static const ThreadInterface* _ThreadServices_GetCurrentThread() { return C::GetCurrentThread(); }
	static THREADTYPE _ThreadServices_GetCurrentThreadType() { return C::GetCurrentThreadType(); }
	static Int _ThreadServices_GetCpuCount() { return C::GetCpuCount(); }
	static void* _ThreadServices_GetStackEnd() { return C::GetStackEnd(); }
	static CoreJobGroup* _ThreadServices_CreateGroup(Int cnt, Int jobSize, UInt flags) { return C::CreateGroup(cnt, jobSize, flags); }
	static void _ThreadServices_AddGroupReference(CoreJobGroup& group) { return C::AddGroupReference(group); }
	static void _ThreadServices_RemoveGroupReference(CoreJobGroup& group) { return C::RemoveGroupReference(group); }
	static Bool _ThreadServices_WaitGroup(CoreJobGroup& group, Float64 timeout, WAITMODE mode) { return C::WaitGroup(group, timeout, mode); }
	static Result<void> _ThreadServices_GroupGetResult(CoreJobGroup& group, Float64 timeout, WAITMODE mode) { return C::GroupGetResult(group, timeout, mode); }
	static Result<void> _ThreadServices_AddJob(CoreJobGroup& group, const JobInterfacePOD& pod) { return C::AddJob(group, pod); }
	static Result<void> _ThreadServices_AddGroup(CoreJobGroup& group, CoreJobGroup* subGroup) { return C::AddGroup(group, subGroup); }
	static void _ThreadServices_EnqueueGroup(CoreJobGroup& group, JobQueueInterface* queue) { return C::EnqueueGroup(group, queue); }
	static Result<void> _ThreadServices_EnqueueGroupAndWait(CoreJobGroup& group, JobQueueInterface* queue) { return C::EnqueueGroupAndWait(group, queue); }
	static void* _ThreadServices_GetStaticJobBuffer(const CoreJobGroup& group, Int* capacity) { return C::GetStaticJobBuffer(group, capacity); }
	static Result<void> _ThreadServices_GroupBatchAdd(CoreJobGroup& group, const JobInterfacePOD* first, void* memory, Int cnt, Int size) { return C::GroupBatchAdd(group, first, memory, cnt, size); }
	static Result<void> _ThreadServices_AddGroupFinishedObserver(CoreJobGroup& group, const JobInterfacePOD& observerPod, JobQueueInterface* observerQueue) { return C::AddGroupFinishedObserver(group, observerPod, observerQueue); }
	static void _ThreadServices_GroupCancel(CoreJobGroup& group) { return C::GroupCancel(group); }
	static void _ThreadServices_GroupMarkAsFinished(CoreJobGroup& group) { return C::GroupMarkAsFinished(group); }
	static Int _ThreadServices_GetCurrentWorkerThreadIndex() { return C::GetCurrentWorkerThreadIndex(); }
	static Bool _ThreadServices_IsCurrentJobCancelled() { return C::IsCurrentJobCancelled(); }
	static JobBarrierInterface* _ThreadServices_CreateBarrier() { return C::CreateBarrier(); }
	static void _ThreadServices_EnqueueBarrier(JobBarrierInterface& barrier, JobQueueInterface* queue) { return C::EnqueueBarrier(barrier, queue); }
	static Result<void> _ThreadServices_AssimilateAlienThread() { return C::AssimilateAlienThread(); }
	static const void* _ThreadServices_ThreadedExclusiveResource(Int selector, const void* resourcePtr) { return C::ThreadedExclusiveResource(selector, resourcePtr); }
	static Result<void> _ThreadServices_ThreadProfiling(Int mode, Block<ThreadInterface*> threads, Block<JobQueueInterface*> queues, QueueProfileData& data) { return C::ThreadProfiling(mode, std::forward<Block<ThreadInterface*>>(threads), std::forward<Block<JobQueueInterface*>>(queues), data); }
};

MAXON_ATTRIBUTE_FORCE_INLINE auto ThreadServices::Start(const JobInterfacePOD& pod, THREADPRIORITY priority) -> Result<void>
{
	return MTable::_instance._ThreadServices_Start(pod, priority);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ThreadServices::Enqueue(const JobInterfacePOD& pod, JobQueueInterface* queue) -> void
{
	return MTable::_instance._ThreadServices_Enqueue(pod, queue);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ThreadServices::Wait(const JobInterfacePOD& pod, Float64 timeout, WAITMODE mode) -> Bool
{
	return MTable::_instance._ThreadServices_Wait(pod, timeout, mode);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ThreadServices::GetResult(const JobInterfacePOD& pod, Float64 timeout, WAITMODE mode) -> Result<void>
{
	return MTable::_instance._ThreadServices_GetResult(pod, timeout, mode);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ThreadServices::Reset(const JobInterfacePOD& pod) -> Result<void>
{
	return MTable::_instance._ThreadServices_Reset(pod);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ThreadServices::Cancel(const JobInterfacePOD& pod) -> void
{
	return MTable::_instance._ThreadServices_Cancel(pod);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ThreadServices::AddFinishedObserver(const JobInterfacePOD& pod, const JobInterfacePOD& observerPod, JobQueueInterface* observerQueue) -> Result<void>
{
	return MTable::_instance._ThreadServices_AddFinishedObserver(pod, observerPod, observerQueue);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ThreadServices::AddCancelledObserver(const JobInterfacePOD& pod, const JobInterfacePOD& observerPod, JobQueueInterface* observerQueue) -> Result<void>
{
	return MTable::_instance._ThreadServices_AddCancelledObserver(pod, observerPod, observerQueue);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ThreadServices::IsRunning(const JobInterfacePOD& pod) -> Bool
{
	return MTable::_instance._ThreadServices_IsRunning(pod);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ThreadServices::IsCancelled(const JobInterfacePOD& pod) -> Bool
{
	return MTable::_instance._ThreadServices_IsCancelled(pod);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ThreadServices::AddJobReference(const JobInterfacePOD& pod) -> void
{
	return MTable::_instance._ThreadServices_AddJobReference(pod);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ThreadServices::RemoveJobReference(const JobInterfacePOD& pod) -> void
{
	return MTable::_instance._ThreadServices_RemoveJobReference(pod);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ThreadServices::CreateStrongJobReference(const JobInterfacePOD& pod) -> Bool
{
	return MTable::_instance._ThreadServices_CreateStrongJobReference(pod);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ThreadServices::AddWeakJobReference(const JobInterfacePOD& pod, WeakRefBase& weakRef) -> void
{
	return MTable::_instance._ThreadServices_AddWeakJobReference(pod, weakRef);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ThreadServices::GetGroup(const JobInterfacePOD& pod) -> CoreJobGroup*
{
	return MTable::_instance._ThreadServices_GetGroup(pod);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ThreadServices::GetCurrentJob() -> const JobInterface*
{
	return MTable::_instance._ThreadServices_GetCurrentJob();
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ThreadServices::GetCurrentThread() -> const ThreadInterface*
{
	return MTable::_instance._ThreadServices_GetCurrentThread();
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ThreadServices::GetCurrentThreadType() -> THREADTYPE
{
	return MTable::_instance._ThreadServices_GetCurrentThreadType();
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ThreadServices::GetCpuCount() -> Int
{
	return MTable::_instance._ThreadServices_GetCpuCount();
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ThreadServices::GetStackEnd() -> void*
{
	return MTable::_instance._ThreadServices_GetStackEnd();
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ThreadServices::CreateGroup(Int cnt, Int jobSize, UInt flags) -> CoreJobGroup*
{
	return MTable::_instance._ThreadServices_CreateGroup(cnt, jobSize, flags);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ThreadServices::AddGroupReference(CoreJobGroup& group) -> void
{
	return MTable::_instance._ThreadServices_AddGroupReference(group);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ThreadServices::RemoveGroupReference(CoreJobGroup& group) -> void
{
	return MTable::_instance._ThreadServices_RemoveGroupReference(group);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ThreadServices::WaitGroup(CoreJobGroup& group, Float64 timeout, WAITMODE mode) -> Bool
{
	return MTable::_instance._ThreadServices_WaitGroup(group, timeout, mode);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ThreadServices::GroupGetResult(CoreJobGroup& group, Float64 timeout, WAITMODE mode) -> Result<void>
{
	return MTable::_instance._ThreadServices_GroupGetResult(group, timeout, mode);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ThreadServices::AddJob(CoreJobGroup& group, const JobInterfacePOD& pod) -> Result<void>
{
	return MTable::_instance._ThreadServices_AddJob(group, pod);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ThreadServices::AddGroup(CoreJobGroup& group, CoreJobGroup* subGroup) -> Result<void>
{
	return MTable::_instance._ThreadServices_AddGroup(group, subGroup);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ThreadServices::EnqueueGroup(CoreJobGroup& group, JobQueueInterface* queue) -> void
{
	return MTable::_instance._ThreadServices_EnqueueGroup(group, queue);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ThreadServices::EnqueueGroupAndWait(CoreJobGroup& group, JobQueueInterface* queue) -> Result<void>
{
	return MTable::_instance._ThreadServices_EnqueueGroupAndWait(group, queue);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ThreadServices::GetStaticJobBuffer(const CoreJobGroup& group, Int* capacity) -> void*
{
	return MTable::_instance._ThreadServices_GetStaticJobBuffer(group, capacity);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ThreadServices::GroupBatchAdd(CoreJobGroup& group, const JobInterfacePOD* first, void* memory, Int cnt, Int size) -> Result<void>
{
	return MTable::_instance._ThreadServices_GroupBatchAdd(group, first, memory, cnt, size);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ThreadServices::AddGroupFinishedObserver(CoreJobGroup& group, const JobInterfacePOD& observerPod, JobQueueInterface* observerQueue) -> Result<void>
{
	return MTable::_instance._ThreadServices_AddGroupFinishedObserver(group, observerPod, observerQueue);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ThreadServices::GroupCancel(CoreJobGroup& group) -> void
{
	return MTable::_instance._ThreadServices_GroupCancel(group);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ThreadServices::GroupMarkAsFinished(CoreJobGroup& group) -> void
{
	return MTable::_instance._ThreadServices_GroupMarkAsFinished(group);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ThreadServices::GetCurrentWorkerThreadIndex() -> Int
{
	return MTable::_instance._ThreadServices_GetCurrentWorkerThreadIndex();
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ThreadServices::IsCurrentJobCancelled() -> Bool
{
	return MTable::_instance._ThreadServices_IsCurrentJobCancelled();
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ThreadServices::CreateBarrier() -> JobBarrierInterface*
{
	return MTable::_instance._ThreadServices_CreateBarrier();
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ThreadServices::EnqueueBarrier(JobBarrierInterface& barrier, JobQueueInterface* queue) -> void
{
	return MTable::_instance._ThreadServices_EnqueueBarrier(barrier, queue);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ThreadServices::AssimilateAlienThread() -> Result<void>
{
	return MTable::_instance._ThreadServices_AssimilateAlienThread();
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ThreadServices::ThreadedExclusiveResource(Int selector, const void* resourcePtr) -> const void*
{
	return MTable::_instance._ThreadServices_ThreadedExclusiveResource(selector, resourcePtr);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ThreadServices::ThreadProfiling(Int mode, Block<ThreadInterface*> threads, Block<JobQueueInterface*> queues, QueueProfileData& data) -> Result<void>
{
	return MTable::_instance._ThreadServices_ThreadProfiling(mode, std::forward<Block<ThreadInterface*>>(threads), std::forward<Block<JobQueueInterface*>>(queues), data);
}

#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT)
static maxon::EntityUse s_ui_maxon_ThreadServices(ThreadServices::_interface.GetReference(), &maxon::g_translationUnit, "maxon/threadservices.h", false);
#endif
/// @endcond

#endif

#ifdef MAXON_COMPILER_GCC
	#pragma GCC diagnostic pop
#endif

#endif

