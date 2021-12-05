
#ifndef DOXYGEN

#if defined MAXON_COMPILER_GCC
	#pragma GCC diagnostic push
	#if MAXON_COMPILER_GCC >= 600
		#pragma GCC diagnostic ignored "-Wmisleading-indentation"
	#endif
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
		if (!W::Implementation::PROXY && (!ErrorInterface::MTable::template InitWithBases<W>(info, offset))) return false;
		MTable* vt = (MTable*) maxon::ObjectInterface::PrivateGetOrCreateMTable(info, _interface); if (!vt) return false;
		vt->Init<W>(offset); return true;
	}
	template <typename S> using CombinedMTable = maxon::CombinedMTable<JobErrorInterface, typename ErrorInterface::MTable::template CombinedMTable<S>>;
	PRIVATE_MAXON_COMPBASE(JobErrorInterface);
	template <typename I> static const typename I::MTable& GetMTable() { return maxon::GetZeroRef<typename I::MTable>(); }
};

struct JobErrorInterface::Hxx2
{
	template <typename S> class Wrapper : public ErrorInterface::Hxx2::template Wrapper<S>
	{
	public:
	};

};

auto JobErrorInterface::GetPtr() -> Ptr { return Ptr(this); }
auto JobErrorInterface::GetPtr() const -> ConstPtr { return ConstPtr(this); }
#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT)
#ifdef MAXON_USE_REGISTER_FUNCTION
MAXON_STATIC_STORAGE(maxon::EntityUse, s_ui_maxon_JobErrorInterface); \
MAXON_ATTRIBUTE_CONSTRUCTOR static void Register_s_ui_maxon_JobErrorInterface() { new (s_ui_maxon_JobErrorInterface) maxon::EntityUse(JobErrorInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/threadservices.h", false); }
#else // !MAXON_USE_REGISTER_FUNCTION
static maxon::EntityUse s_ui_maxon_JobErrorInterface(JobErrorInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/threadservices.h", false);
#endif // MAXON_USE_REGISTER_FUNCTION
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
	Result<void> (*_ThreadServices_RemoveCancelledObserver) (const JobInterfacePOD& pod, const JobInterfacePOD& observerPod);
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
	Result<void> (*_ThreadServices_AssimilateAlienThread) ();
	const void* (*_ThreadServices_ThreadedExclusiveResource) (Int selector, const void* resourcePtr);
	template <typename IMPL> void Init()
	{
		_ThreadServices_Start = &IMPL::_ThreadServices_Start;
		_ThreadServices_Enqueue = &IMPL::_ThreadServices_Enqueue;
		_ThreadServices_Wait = &IMPL::_ThreadServices_Wait;
		_ThreadServices_GetResult = &IMPL::_ThreadServices_GetResult;
		_ThreadServices_Reset = &IMPL::_ThreadServices_Reset;
		_ThreadServices_Cancel = &IMPL::_ThreadServices_Cancel;
		_ThreadServices_AddFinishedObserver = &IMPL::_ThreadServices_AddFinishedObserver;
		_ThreadServices_AddCancelledObserver = &IMPL::_ThreadServices_AddCancelledObserver;
		_ThreadServices_RemoveCancelledObserver = &IMPL::_ThreadServices_RemoveCancelledObserver;
		_ThreadServices_IsRunning = &IMPL::_ThreadServices_IsRunning;
		_ThreadServices_IsCancelled = &IMPL::_ThreadServices_IsCancelled;
		_ThreadServices_AddJobReference = &IMPL::_ThreadServices_AddJobReference;
		_ThreadServices_RemoveJobReference = &IMPL::_ThreadServices_RemoveJobReference;
		_ThreadServices_CreateStrongJobReference = &IMPL::_ThreadServices_CreateStrongJobReference;
		_ThreadServices_AddWeakJobReference = &IMPL::_ThreadServices_AddWeakJobReference;
		_ThreadServices_GetGroup = &IMPL::_ThreadServices_GetGroup;
		_ThreadServices_GetCurrentJob = &IMPL::_ThreadServices_GetCurrentJob;
		_ThreadServices_GetCurrentThread = &IMPL::_ThreadServices_GetCurrentThread;
		_ThreadServices_GetCurrentThreadType = &IMPL::_ThreadServices_GetCurrentThreadType;
		_ThreadServices_GetCpuCount = &IMPL::_ThreadServices_GetCpuCount;
		_ThreadServices_GetStackEnd = &IMPL::_ThreadServices_GetStackEnd;
		_ThreadServices_CreateGroup = &IMPL::_ThreadServices_CreateGroup;
		_ThreadServices_AddGroupReference = &IMPL::_ThreadServices_AddGroupReference;
		_ThreadServices_RemoveGroupReference = &IMPL::_ThreadServices_RemoveGroupReference;
		_ThreadServices_WaitGroup = &IMPL::_ThreadServices_WaitGroup;
		_ThreadServices_GroupGetResult = &IMPL::_ThreadServices_GroupGetResult;
		_ThreadServices_AddJob = &IMPL::_ThreadServices_AddJob;
		_ThreadServices_AddGroup = &IMPL::_ThreadServices_AddGroup;
		_ThreadServices_EnqueueGroup = &IMPL::_ThreadServices_EnqueueGroup;
		_ThreadServices_EnqueueGroupAndWait = &IMPL::_ThreadServices_EnqueueGroupAndWait;
		_ThreadServices_GetStaticJobBuffer = &IMPL::_ThreadServices_GetStaticJobBuffer;
		_ThreadServices_GroupBatchAdd = &IMPL::_ThreadServices_GroupBatchAdd;
		_ThreadServices_AddGroupFinishedObserver = &IMPL::_ThreadServices_AddGroupFinishedObserver;
		_ThreadServices_GroupCancel = &IMPL::_ThreadServices_GroupCancel;
		_ThreadServices_GroupMarkAsFinished = &IMPL::_ThreadServices_GroupMarkAsFinished;
		_ThreadServices_GetCurrentWorkerThreadIndex = &IMPL::_ThreadServices_GetCurrentWorkerThreadIndex;
		_ThreadServices_IsCurrentJobCancelled = &IMPL::_ThreadServices_IsCurrentJobCancelled;
		_ThreadServices_AssimilateAlienThread = &IMPL::_ThreadServices_AssimilateAlienThread;
		_ThreadServices_ThreadedExclusiveResource = &IMPL::_ThreadServices_ThreadedExclusiveResource;
	}
};

struct ThreadServices::Hxx2
{
	class Unresolved;
	template <typename C> class Wrapper
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
	static Result<void> _ThreadServices_RemoveCancelledObserver(const JobInterfacePOD& pod, const JobInterfacePOD& observerPod) { return C::RemoveCancelledObserver(pod, observerPod); }
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
	static Result<void> _ThreadServices_AssimilateAlienThread() { return C::AssimilateAlienThread(); }
	static const void* _ThreadServices_ThreadedExclusiveResource(Int selector, const void* resourcePtr) { return C::ThreadedExclusiveResource(selector, resourcePtr); }
	};

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
MAXON_ATTRIBUTE_FORCE_INLINE auto ThreadServices::RemoveCancelledObserver(const JobInterfacePOD& pod, const JobInterfacePOD& observerPod) -> Result<void>
{
	return MTable::_instance._ThreadServices_RemoveCancelledObserver(pod, observerPod);
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
MAXON_ATTRIBUTE_FORCE_INLINE auto ThreadServices::AssimilateAlienThread() -> Result<void>
{
	return MTable::_instance._ThreadServices_AssimilateAlienThread();
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ThreadServices::ThreadedExclusiveResource(Int selector, const void* resourcePtr) -> const void*
{
	return MTable::_instance._ThreadServices_ThreadedExclusiveResource(selector, resourcePtr);
}

#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT)
#ifdef MAXON_USE_REGISTER_FUNCTION
MAXON_STATIC_STORAGE(maxon::EntityUse, s_ui_maxon_ThreadServices); \
MAXON_ATTRIBUTE_CONSTRUCTOR static void Register_s_ui_maxon_ThreadServices() { new (s_ui_maxon_ThreadServices) maxon::EntityUse(ThreadServices::_interface.GetReference(), &maxon::g_translationUnit, "maxon/threadservices.h", false); }
#else // !MAXON_USE_REGISTER_FUNCTION
static maxon::EntityUse s_ui_maxon_ThreadServices(ThreadServices::_interface.GetReference(), &maxon::g_translationUnit, "maxon/threadservices.h", false);
#endif // MAXON_USE_REGISTER_FUNCTION
#endif
/// @endcond

#endif

#ifdef MAXON_COMPILER_GCC
	#pragma GCC diagnostic pop
#endif

#endif

