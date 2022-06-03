
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
	static const maxon::METHOD_FLAGS _flags[];
	static const maxon::Bool HAS_NONSTATIC = false;
	template <typename S> using CombinedMTable = maxon::CombinedMTable<JobErrorInterface, typename ErrorInterface::MTable::template CombinedMTable<S>>;
	template <typename SUPER> using CompBase = maxon::PrivateComponentBase<JobErrorInterface, SUPER>;
	template <typename I> static const typename I::MTable& GetMTable() { return maxon::GetZeroRef<typename I::MTable>(); }
};

struct JobErrorInterface::Hxx2
{
	template <typename S> class CWrapper : public ErrorInterface::Hxx2::template CWrapper<S>
	{
	public:
		static maxon::Bool InitMTablesWithBases(maxon::ClassInfo* info, maxon::Int offset)
		{
			using Super0 = typename ErrorInterface::Hxx2::template CWrapper<S>;
			if (!S::Implementation::PROXY && !(Super0::InitMTablesWithBases(info, offset))) return false;
			auto* vt = (JobErrorInterface::MTable*) maxon::ObjectInterface::PrivateGetOrCreateMTable(info, JobErrorInterface::_interface); if (!vt) return false;
			return true;
		}
	};

};

auto JobErrorInterface::GetPtr() -> Ptr { return Ptr(this); }
auto JobErrorInterface::GetPtr() const -> ConstPtr { return ConstPtr(this); }
#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT) && !defined(MAXON_DEPENDENCY_DISABLE_threadservices)
#ifdef MAXON_USE_REGISTER_FUNCTION
MAXON_STATIC_STORAGE(maxon::EntityUse, s_ui_maxon_JobErrorInterface); \
MAXON_ATTRIBUTE_CONSTRUCTOR static void Register_s_ui_maxon_JobErrorInterface() { new (s_ui_maxon_JobErrorInterface) maxon::EntityUse(JobErrorInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/threadservices.h", false); }
#else // !MAXON_USE_REGISTER_FUNCTION
static maxon::EntityUse s_ui_maxon_JobErrorInterface(JobErrorInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/threadservices.h", false);
#endif // MAXON_USE_REGISTER_FUNCTION
#endif
/// @cond INTERNAL

constexpr const maxon::Char* ThreadServices::PrivateGetCppName() { return nullptr; }

struct ThreadServices::MTable
{
	static MTable _instance;
	static MTable _unresolvedInstance;
	static const maxon::Char* const _ids;
	static maxon::Bool InitUnresolved(maxon::NonvirtualInterfaceReference::UnresolvedAssembler assembler, MTable* tbl);
	static const maxon::NULL_RETURN_TYPE _returnTypes[];
	static const maxon::Bool HAS_NONSTATIC = false;
	Result<void> (*ThreadServices_Start) (const JobInterfacePOD& pod, THREADPRIORITY priority);
	void (*ThreadServices_Enqueue) (const JobInterfacePOD& pod, JobQueueInterface* queue);
	Bool (*ThreadServices_Wait) (const JobInterfacePOD& pod, Float64 timeout, WAITMODE mode);
	Result<void> (*ThreadServices_GetResult) (const JobInterfacePOD& pod, Float64 timeout, WAITMODE mode);
	Result<void> (*ThreadServices_Reset) (const JobInterfacePOD& pod);
	void (*ThreadServices_Cancel) (const JobInterfacePOD& pod);
	Result<void> (*ThreadServices_AddFinishedObserver) (const JobInterfacePOD& pod, const JobInterfacePOD& observerPod, JobQueueInterface* observerQueue);
	Result<void> (*ThreadServices_AddCancelledObserver) (const JobInterfacePOD& pod, const JobInterfacePOD& observerPod, JobQueueInterface* observerQueue);
	Result<void> (*ThreadServices_RemoveCancelledObserver) (const JobInterfacePOD& pod, const JobInterfacePOD& observerPod);
	Bool (*ThreadServices_IsRunning) (const JobInterfacePOD& pod);
	Bool (*ThreadServices_IsCancelled) (const JobInterfacePOD& pod);
	void (*ThreadServices_AddJobReference) (const JobInterfacePOD& pod);
	void (*ThreadServices_RemoveJobReference) (const JobInterfacePOD& pod);
	Bool (*ThreadServices_CreateStrongJobReference) (const JobInterfacePOD& pod);
	void (*ThreadServices_AddWeakJobReference) (const JobInterfacePOD& pod, WeakRefBase& weakRef);
	CoreJobGroup* (*ThreadServices_GetGroup) (const JobInterfacePOD& pod);
	const JobInterface* (*ThreadServices_GetCurrentJob) ();
	const ThreadInterface* (*ThreadServices_GetCurrentThread) ();
	THREADTYPE (*ThreadServices_GetCurrentThreadType) ();
	THREADTYPE (*ThreadServices_GetCurrentThreadType_1) (Int& threadIdentifier);
	Int (*ThreadServices_GetCpuCount) ();
	void* (*ThreadServices_GetStackEnd) ();
	CoreJobGroup* (*ThreadServices_CreateGroup) (Int cnt, Int jobSize, UInt flags);
	void (*ThreadServices_AddGroupReference) (CoreJobGroup& group);
	void (*ThreadServices_RemoveGroupReference) (CoreJobGroup& group);
	Bool (*ThreadServices_WaitGroup) (CoreJobGroup& group, Float64 timeout, WAITMODE mode);
	Result<void> (*ThreadServices_GroupGetResult) (CoreJobGroup& group, Float64 timeout, WAITMODE mode);
	Result<void> (*ThreadServices_AddJob) (CoreJobGroup& group, const JobInterfacePOD& pod);
	Result<void> (*ThreadServices_AddGroup) (CoreJobGroup& group, CoreJobGroup* subGroup);
	void (*ThreadServices_EnqueueGroup) (CoreJobGroup& group, JobQueueInterface* queue);
	Result<void> (*ThreadServices_EnqueueGroupAndWait) (CoreJobGroup& group, JobQueueInterface* queue);
	void* (*ThreadServices_GetStaticJobBuffer) (const CoreJobGroup& group, Int* capacity);
	Result<void> (*ThreadServices_GroupBatchAdd) (CoreJobGroup& group, const JobInterfacePOD* first, void* memory, Int cnt, Int size);
	Result<void> (*ThreadServices_AddGroupFinishedObserver) (CoreJobGroup& group, const JobInterfacePOD& observerPod, JobQueueInterface* observerQueue);
	void (*ThreadServices_GroupCancel) (CoreJobGroup& group);
	void (*ThreadServices_GroupMarkAsFinished) (CoreJobGroup& group);
	Int (*ThreadServices_GetCurrentWorkerThreadIndex) ();
	Bool (*ThreadServices_IsCurrentJobCancelled) ();
	Result<void> (*ThreadServices_AssimilateAlienThread) ();
	const void* (*ThreadServices_ThreadedExclusiveResource) (Int selector, const void* resourcePtr);
	void (*ThreadServices_AddJobStatusReference) (const JobInterfacePOD& pod);
	void (*ThreadServices_RemoveJobStatusReference) (const JobInterfacePOD& pod);
	template <typename IMPL> void Init()
	{
		ThreadServices_Start = &IMPL::ThreadServices_Start;
		ThreadServices_Enqueue = &IMPL::ThreadServices_Enqueue;
		ThreadServices_Wait = &IMPL::ThreadServices_Wait;
		ThreadServices_GetResult = &IMPL::ThreadServices_GetResult;
		ThreadServices_Reset = &IMPL::ThreadServices_Reset;
		ThreadServices_Cancel = &IMPL::ThreadServices_Cancel;
		ThreadServices_AddFinishedObserver = &IMPL::ThreadServices_AddFinishedObserver;
		ThreadServices_AddCancelledObserver = &IMPL::ThreadServices_AddCancelledObserver;
		ThreadServices_RemoveCancelledObserver = &IMPL::ThreadServices_RemoveCancelledObserver;
		ThreadServices_IsRunning = &IMPL::ThreadServices_IsRunning;
		ThreadServices_IsCancelled = &IMPL::ThreadServices_IsCancelled;
		ThreadServices_AddJobReference = &IMPL::ThreadServices_AddJobReference;
		ThreadServices_RemoveJobReference = &IMPL::ThreadServices_RemoveJobReference;
		ThreadServices_CreateStrongJobReference = &IMPL::ThreadServices_CreateStrongJobReference;
		ThreadServices_AddWeakJobReference = &IMPL::ThreadServices_AddWeakJobReference;
		ThreadServices_GetGroup = &IMPL::ThreadServices_GetGroup;
		ThreadServices_GetCurrentJob = &IMPL::ThreadServices_GetCurrentJob;
		ThreadServices_GetCurrentThread = &IMPL::ThreadServices_GetCurrentThread;
		ThreadServices_GetCurrentThreadType = &IMPL::ThreadServices_GetCurrentThreadType;
		ThreadServices_GetCurrentThreadType_1 = &IMPL::ThreadServices_GetCurrentThreadType_1;
		ThreadServices_GetCpuCount = &IMPL::ThreadServices_GetCpuCount;
		ThreadServices_GetStackEnd = &IMPL::ThreadServices_GetStackEnd;
		ThreadServices_CreateGroup = &IMPL::ThreadServices_CreateGroup;
		ThreadServices_AddGroupReference = &IMPL::ThreadServices_AddGroupReference;
		ThreadServices_RemoveGroupReference = &IMPL::ThreadServices_RemoveGroupReference;
		ThreadServices_WaitGroup = &IMPL::ThreadServices_WaitGroup;
		ThreadServices_GroupGetResult = &IMPL::ThreadServices_GroupGetResult;
		ThreadServices_AddJob = &IMPL::ThreadServices_AddJob;
		ThreadServices_AddGroup = &IMPL::ThreadServices_AddGroup;
		ThreadServices_EnqueueGroup = &IMPL::ThreadServices_EnqueueGroup;
		ThreadServices_EnqueueGroupAndWait = &IMPL::ThreadServices_EnqueueGroupAndWait;
		ThreadServices_GetStaticJobBuffer = &IMPL::ThreadServices_GetStaticJobBuffer;
		ThreadServices_GroupBatchAdd = &IMPL::ThreadServices_GroupBatchAdd;
		ThreadServices_AddGroupFinishedObserver = &IMPL::ThreadServices_AddGroupFinishedObserver;
		ThreadServices_GroupCancel = &IMPL::ThreadServices_GroupCancel;
		ThreadServices_GroupMarkAsFinished = &IMPL::ThreadServices_GroupMarkAsFinished;
		ThreadServices_GetCurrentWorkerThreadIndex = &IMPL::ThreadServices_GetCurrentWorkerThreadIndex;
		ThreadServices_IsCurrentJobCancelled = &IMPL::ThreadServices_IsCurrentJobCancelled;
		ThreadServices_AssimilateAlienThread = &IMPL::ThreadServices_AssimilateAlienThread;
		ThreadServices_ThreadedExclusiveResource = &IMPL::ThreadServices_ThreadedExclusiveResource;
		ThreadServices_AddJobStatusReference = &IMPL::ThreadServices_AddJobStatusReference;
		ThreadServices_RemoveJobStatusReference = &IMPL::ThreadServices_RemoveJobStatusReference;
	}
};

struct ThreadServices::Hxx2
{
	class Unresolved;
	template <typename C> class Wrapper
	{
	public:
		static Result<void> ThreadServices_Start(const JobInterfacePOD& pod, THREADPRIORITY priority) { return C::Start(pod, priority); }
		static void ThreadServices_Enqueue(const JobInterfacePOD& pod, JobQueueInterface* queue) { return C::Enqueue(pod, queue); }
		static Bool ThreadServices_Wait(const JobInterfacePOD& pod, Float64 timeout, WAITMODE mode) { return C::Wait(pod, timeout, mode); }
		static Result<void> ThreadServices_GetResult(const JobInterfacePOD& pod, Float64 timeout, WAITMODE mode) { return C::GetResult(pod, timeout, mode); }
		static Result<void> ThreadServices_Reset(const JobInterfacePOD& pod) { return C::Reset(pod); }
		static void ThreadServices_Cancel(const JobInterfacePOD& pod) { return C::Cancel(pod); }
		static Result<void> ThreadServices_AddFinishedObserver(const JobInterfacePOD& pod, const JobInterfacePOD& observerPod, JobQueueInterface* observerQueue) { return C::AddFinishedObserver(pod, observerPod, observerQueue); }
		static Result<void> ThreadServices_AddCancelledObserver(const JobInterfacePOD& pod, const JobInterfacePOD& observerPod, JobQueueInterface* observerQueue) { return C::AddCancelledObserver(pod, observerPod, observerQueue); }
		static Result<void> ThreadServices_RemoveCancelledObserver(const JobInterfacePOD& pod, const JobInterfacePOD& observerPod) { return C::RemoveCancelledObserver(pod, observerPod); }
		static Bool ThreadServices_IsRunning(const JobInterfacePOD& pod) { return C::IsRunning(pod); }
		static Bool ThreadServices_IsCancelled(const JobInterfacePOD& pod) { return C::IsCancelled(pod); }
		static void ThreadServices_AddJobReference(const JobInterfacePOD& pod) { return C::AddJobReference(pod); }
		static void ThreadServices_RemoveJobReference(const JobInterfacePOD& pod) { return C::RemoveJobReference(pod); }
		static Bool ThreadServices_CreateStrongJobReference(const JobInterfacePOD& pod) { return C::CreateStrongJobReference(pod); }
		static void ThreadServices_AddWeakJobReference(const JobInterfacePOD& pod, WeakRefBase& weakRef) { return C::AddWeakJobReference(pod, weakRef); }
		static CoreJobGroup* ThreadServices_GetGroup(const JobInterfacePOD& pod) { return C::GetGroup(pod); }
		static const JobInterface* ThreadServices_GetCurrentJob() { return C::GetCurrentJob(); }
		static const ThreadInterface* ThreadServices_GetCurrentThread() { return C::GetCurrentThread(); }
		static THREADTYPE ThreadServices_GetCurrentThreadType() { return C::GetCurrentThreadType(); }
		static THREADTYPE ThreadServices_GetCurrentThreadType_1(Int& threadIdentifier) { return C::GetCurrentThreadType(threadIdentifier); }
		static Int ThreadServices_GetCpuCount() { return C::GetCpuCount(); }
		static void* ThreadServices_GetStackEnd() { return C::GetStackEnd(); }
		static CoreJobGroup* ThreadServices_CreateGroup(Int cnt, Int jobSize, UInt flags) { return C::CreateGroup(cnt, jobSize, flags); }
		static void ThreadServices_AddGroupReference(CoreJobGroup& group) { return C::AddGroupReference(group); }
		static void ThreadServices_RemoveGroupReference(CoreJobGroup& group) { return C::RemoveGroupReference(group); }
		static Bool ThreadServices_WaitGroup(CoreJobGroup& group, Float64 timeout, WAITMODE mode) { return C::WaitGroup(group, timeout, mode); }
		static Result<void> ThreadServices_GroupGetResult(CoreJobGroup& group, Float64 timeout, WAITMODE mode) { return C::GroupGetResult(group, timeout, mode); }
		static Result<void> ThreadServices_AddJob(CoreJobGroup& group, const JobInterfacePOD& pod) { return C::AddJob(group, pod); }
		static Result<void> ThreadServices_AddGroup(CoreJobGroup& group, CoreJobGroup* subGroup) { return C::AddGroup(group, subGroup); }
		static void ThreadServices_EnqueueGroup(CoreJobGroup& group, JobQueueInterface* queue) { return C::EnqueueGroup(group, queue); }
		static Result<void> ThreadServices_EnqueueGroupAndWait(CoreJobGroup& group, JobQueueInterface* queue) { return C::EnqueueGroupAndWait(group, queue); }
		static void* ThreadServices_GetStaticJobBuffer(const CoreJobGroup& group, Int* capacity) { return C::GetStaticJobBuffer(group, capacity); }
		static Result<void> ThreadServices_GroupBatchAdd(CoreJobGroup& group, const JobInterfacePOD* first, void* memory, Int cnt, Int size) { return C::GroupBatchAdd(group, first, memory, cnt, size); }
		static Result<void> ThreadServices_AddGroupFinishedObserver(CoreJobGroup& group, const JobInterfacePOD& observerPod, JobQueueInterface* observerQueue) { return C::AddGroupFinishedObserver(group, observerPod, observerQueue); }
		static void ThreadServices_GroupCancel(CoreJobGroup& group) { return C::GroupCancel(group); }
		static void ThreadServices_GroupMarkAsFinished(CoreJobGroup& group) { return C::GroupMarkAsFinished(group); }
		static Int ThreadServices_GetCurrentWorkerThreadIndex() { return C::GetCurrentWorkerThreadIndex(); }
		static Bool ThreadServices_IsCurrentJobCancelled() { return C::IsCurrentJobCancelled(); }
		static Result<void> ThreadServices_AssimilateAlienThread() { return C::AssimilateAlienThread(); }
		static const void* ThreadServices_ThreadedExclusiveResource(Int selector, const void* resourcePtr) { return C::ThreadedExclusiveResource(selector, resourcePtr); }
		static void ThreadServices_AddJobStatusReference(const JobInterfacePOD& pod) { return C::AddJobStatusReference(pod); }
		static void ThreadServices_RemoveJobStatusReference(const JobInterfacePOD& pod) { return C::RemoveJobStatusReference(pod); }
	};

};
MAXON_ATTRIBUTE_FORCE_INLINE auto ThreadServices::Start(const JobInterfacePOD& pod, THREADPRIORITY priority) -> Result<void>
{
	return MTable::_instance.ThreadServices_Start(pod, priority);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ThreadServices::Enqueue(const JobInterfacePOD& pod, JobQueueInterface* queue) -> void
{
	return MTable::_instance.ThreadServices_Enqueue(pod, queue);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ThreadServices::Wait(const JobInterfacePOD& pod, Float64 timeout, WAITMODE mode) -> Bool
{
	return MTable::_instance.ThreadServices_Wait(pod, timeout, mode);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ThreadServices::GetResult(const JobInterfacePOD& pod, Float64 timeout, WAITMODE mode) -> Result<void>
{
	return MTable::_instance.ThreadServices_GetResult(pod, timeout, mode);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ThreadServices::Reset(const JobInterfacePOD& pod) -> Result<void>
{
	return MTable::_instance.ThreadServices_Reset(pod);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ThreadServices::Cancel(const JobInterfacePOD& pod) -> void
{
	return MTable::_instance.ThreadServices_Cancel(pod);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ThreadServices::AddFinishedObserver(const JobInterfacePOD& pod, const JobInterfacePOD& observerPod, JobQueueInterface* observerQueue) -> Result<void>
{
	return MTable::_instance.ThreadServices_AddFinishedObserver(pod, observerPod, observerQueue);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ThreadServices::AddCancelledObserver(const JobInterfacePOD& pod, const JobInterfacePOD& observerPod, JobQueueInterface* observerQueue) -> Result<void>
{
	return MTable::_instance.ThreadServices_AddCancelledObserver(pod, observerPod, observerQueue);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ThreadServices::RemoveCancelledObserver(const JobInterfacePOD& pod, const JobInterfacePOD& observerPod) -> Result<void>
{
	return MTable::_instance.ThreadServices_RemoveCancelledObserver(pod, observerPod);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ThreadServices::IsRunning(const JobInterfacePOD& pod) -> Bool
{
	return MTable::_instance.ThreadServices_IsRunning(pod);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ThreadServices::IsCancelled(const JobInterfacePOD& pod) -> Bool
{
	return MTable::_instance.ThreadServices_IsCancelled(pod);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ThreadServices::AddJobReference(const JobInterfacePOD& pod) -> void
{
	return MTable::_instance.ThreadServices_AddJobReference(pod);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ThreadServices::RemoveJobReference(const JobInterfacePOD& pod) -> void
{
	return MTable::_instance.ThreadServices_RemoveJobReference(pod);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ThreadServices::CreateStrongJobReference(const JobInterfacePOD& pod) -> Bool
{
	return MTable::_instance.ThreadServices_CreateStrongJobReference(pod);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ThreadServices::AddWeakJobReference(const JobInterfacePOD& pod, WeakRefBase& weakRef) -> void
{
	return MTable::_instance.ThreadServices_AddWeakJobReference(pod, weakRef);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ThreadServices::GetGroup(const JobInterfacePOD& pod) -> CoreJobGroup*
{
	return MTable::_instance.ThreadServices_GetGroup(pod);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ThreadServices::GetCurrentJob() -> const JobInterface*
{
	return MTable::_instance.ThreadServices_GetCurrentJob();
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ThreadServices::GetCurrentThread() -> const ThreadInterface*
{
	return MTable::_instance.ThreadServices_GetCurrentThread();
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ThreadServices::GetCurrentThreadType() -> THREADTYPE
{
	return MTable::_instance.ThreadServices_GetCurrentThreadType();
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ThreadServices::GetCurrentThreadType(Int& threadIdentifier) -> THREADTYPE
{
	return MTable::_instance.ThreadServices_GetCurrentThreadType_1(threadIdentifier);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ThreadServices::GetCpuCount() -> Int
{
	return MTable::_instance.ThreadServices_GetCpuCount();
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ThreadServices::GetStackEnd() -> void*
{
	return MTable::_instance.ThreadServices_GetStackEnd();
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ThreadServices::CreateGroup(Int cnt, Int jobSize, UInt flags) -> CoreJobGroup*
{
	return MTable::_instance.ThreadServices_CreateGroup(cnt, jobSize, flags);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ThreadServices::AddGroupReference(CoreJobGroup& group) -> void
{
	return MTable::_instance.ThreadServices_AddGroupReference(group);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ThreadServices::RemoveGroupReference(CoreJobGroup& group) -> void
{
	return MTable::_instance.ThreadServices_RemoveGroupReference(group);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ThreadServices::WaitGroup(CoreJobGroup& group, Float64 timeout, WAITMODE mode) -> Bool
{
	return MTable::_instance.ThreadServices_WaitGroup(group, timeout, mode);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ThreadServices::GroupGetResult(CoreJobGroup& group, Float64 timeout, WAITMODE mode) -> Result<void>
{
	return MTable::_instance.ThreadServices_GroupGetResult(group, timeout, mode);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ThreadServices::AddJob(CoreJobGroup& group, const JobInterfacePOD& pod) -> Result<void>
{
	return MTable::_instance.ThreadServices_AddJob(group, pod);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ThreadServices::AddGroup(CoreJobGroup& group, CoreJobGroup* subGroup) -> Result<void>
{
	return MTable::_instance.ThreadServices_AddGroup(group, subGroup);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ThreadServices::EnqueueGroup(CoreJobGroup& group, JobQueueInterface* queue) -> void
{
	return MTable::_instance.ThreadServices_EnqueueGroup(group, queue);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ThreadServices::EnqueueGroupAndWait(CoreJobGroup& group, JobQueueInterface* queue) -> Result<void>
{
	return MTable::_instance.ThreadServices_EnqueueGroupAndWait(group, queue);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ThreadServices::GetStaticJobBuffer(const CoreJobGroup& group, Int* capacity) -> void*
{
	return MTable::_instance.ThreadServices_GetStaticJobBuffer(group, capacity);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ThreadServices::GroupBatchAdd(CoreJobGroup& group, const JobInterfacePOD* first, void* memory, Int cnt, Int size) -> Result<void>
{
	return MTable::_instance.ThreadServices_GroupBatchAdd(group, first, memory, cnt, size);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ThreadServices::AddGroupFinishedObserver(CoreJobGroup& group, const JobInterfacePOD& observerPod, JobQueueInterface* observerQueue) -> Result<void>
{
	return MTable::_instance.ThreadServices_AddGroupFinishedObserver(group, observerPod, observerQueue);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ThreadServices::GroupCancel(CoreJobGroup& group) -> void
{
	return MTable::_instance.ThreadServices_GroupCancel(group);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ThreadServices::GroupMarkAsFinished(CoreJobGroup& group) -> void
{
	return MTable::_instance.ThreadServices_GroupMarkAsFinished(group);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ThreadServices::GetCurrentWorkerThreadIndex() -> Int
{
	return MTable::_instance.ThreadServices_GetCurrentWorkerThreadIndex();
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ThreadServices::IsCurrentJobCancelled() -> Bool
{
	return MTable::_instance.ThreadServices_IsCurrentJobCancelled();
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ThreadServices::AssimilateAlienThread() -> Result<void>
{
	return MTable::_instance.ThreadServices_AssimilateAlienThread();
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ThreadServices::ThreadedExclusiveResource(Int selector, const void* resourcePtr) -> const void*
{
	return MTable::_instance.ThreadServices_ThreadedExclusiveResource(selector, resourcePtr);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ThreadServices::AddJobStatusReference(const JobInterfacePOD& pod) -> void
{
	return MTable::_instance.ThreadServices_AddJobStatusReference(pod);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ThreadServices::RemoveJobStatusReference(const JobInterfacePOD& pod) -> void
{
	return MTable::_instance.ThreadServices_RemoveJobStatusReference(pod);
}

#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT) && !defined(MAXON_DEPENDENCY_DISABLE_threadservices)
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

