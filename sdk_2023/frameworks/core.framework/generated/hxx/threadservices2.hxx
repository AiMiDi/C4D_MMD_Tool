
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
			if constexpr (!S::Implementation::PROXY)
			{
				if (!(Super0::InitMTablesWithBases(info, offset))) return false;
			}
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
	PRIVATE_MAXON_SF_POINTER(ThreadServices_Start, Start, MAXON_EXPAND_VA_ARGS, (Result<void>), const JobInterfacePOD& pod, THREADPRIORITY priority);
	PRIVATE_MAXON_SF_POINTER(ThreadServices_Enqueue, Enqueue, MAXON_EXPAND_VA_ARGS, (void), const JobInterfacePOD& pod, JobQueueInterface* queue);
	PRIVATE_MAXON_SF_POINTER(ThreadServices_Wait, Wait, MAXON_EXPAND_VA_ARGS, (Bool), const JobInterfacePOD& pod, Float64 timeout, WAITMODE mode);
	PRIVATE_MAXON_SF_POINTER(ThreadServices_GetResult, GetResult, MAXON_EXPAND_VA_ARGS, (Result<void>), const JobInterfacePOD& pod, Float64 timeout, WAITMODE mode);
	PRIVATE_MAXON_SF_POINTER(ThreadServices_Reset, Reset, MAXON_EXPAND_VA_ARGS, (Result<void>), const JobInterfacePOD& pod);
	PRIVATE_MAXON_SF_POINTER(ThreadServices_Cancel, Cancel, MAXON_EXPAND_VA_ARGS, (void), const JobInterfacePOD& pod);
	PRIVATE_MAXON_SF_POINTER(ThreadServices_AddFinishedObserver, AddFinishedObserver, MAXON_EXPAND_VA_ARGS, (Result<void>), const JobInterfacePOD& pod, const JobInterfacePOD& observerPod, JobQueueInterface* observerQueue);
	PRIVATE_MAXON_SF_POINTER(ThreadServices_AddCancelledObserver, AddCancelledObserver, MAXON_EXPAND_VA_ARGS, (Result<void>), const JobInterfacePOD& pod, const JobInterfacePOD& observerPod, JobQueueInterface* observerQueue);
	PRIVATE_MAXON_SF_POINTER(ThreadServices_RemoveCancelledObserver, RemoveCancelledObserver, MAXON_EXPAND_VA_ARGS, (Result<void>), const JobInterfacePOD& pod, const JobInterfacePOD& observerPod);
	PRIVATE_MAXON_SF_POINTER(ThreadServices_IsRunning, IsRunning, MAXON_EXPAND_VA_ARGS, (Bool), const JobInterfacePOD& pod);
	PRIVATE_MAXON_SF_POINTER(ThreadServices_IsCancelled, IsCancelled, MAXON_EXPAND_VA_ARGS, (Bool), const JobInterfacePOD& pod);
	PRIVATE_MAXON_SF_POINTER(ThreadServices_AddJobReference, AddJobReference, MAXON_EXPAND_VA_ARGS, (void), const JobInterfacePOD& pod);
	PRIVATE_MAXON_SF_POINTER(ThreadServices_RemoveJobReference, RemoveJobReference, MAXON_EXPAND_VA_ARGS, (void), const JobInterfacePOD& pod);
	PRIVATE_MAXON_SF_POINTER(ThreadServices_CreateStrongJobReference, CreateStrongJobReference, MAXON_EXPAND_VA_ARGS, (Bool), const JobInterfacePOD& pod);
	PRIVATE_MAXON_SF_POINTER(ThreadServices_AddWeakJobReference, AddWeakJobReference, MAXON_EXPAND_VA_ARGS, (void), const JobInterfacePOD& pod, WeakRefBase& weakRef);
	PRIVATE_MAXON_SF_POINTER(ThreadServices_GetGroup, GetGroup, MAXON_EXPAND_VA_ARGS, (CoreJobGroup*), const JobInterfacePOD& pod);
	PRIVATE_MAXON_SF_POINTER(ThreadServices_GetCurrentJob, GetCurrentJob, MAXON_EXPAND_VA_ARGS, (const JobInterface*));
	PRIVATE_MAXON_SF_POINTER(ThreadServices_GetCurrentThread, GetCurrentThread, MAXON_EXPAND_VA_ARGS, (const ThreadInterface*));
	PRIVATE_MAXON_SF_POINTER(ThreadServices_GetCurrentThreadType, GetCurrentThreadType, MAXON_EXPAND_VA_ARGS, (THREADTYPE));
	PRIVATE_MAXON_SF_POINTER(ThreadServices_GetCurrentThreadType_1, GetCurrentThreadType, MAXON_EXPAND_VA_ARGS, (THREADTYPE), Int& threadIdentifier);
	PRIVATE_MAXON_SF_POINTER(ThreadServices_GetCpuCount, GetCpuCount, MAXON_EXPAND_VA_ARGS, (Int));
	PRIVATE_MAXON_SF_POINTER(ThreadServices_GetStackEnd, GetStackEnd, MAXON_EXPAND_VA_ARGS, (void*));
	PRIVATE_MAXON_SF_POINTER(ThreadServices_CreateGroup, CreateGroup, MAXON_EXPAND_VA_ARGS, (CoreJobGroup*), Int cnt, Int jobSize, UInt flags);
	PRIVATE_MAXON_SF_POINTER(ThreadServices_CreateGroupForQueue, CreateGroupForQueue, MAXON_EXPAND_VA_ARGS, (CoreJobGroup*), JobQueueInterface* queue, Int& cnt, Int jobSize, UInt flags);
	PRIVATE_MAXON_SF_POINTER(ThreadServices_AddGroupReference, AddGroupReference, MAXON_EXPAND_VA_ARGS, (void), CoreJobGroup& group);
	PRIVATE_MAXON_SF_POINTER(ThreadServices_RemoveGroupReference, RemoveGroupReference, MAXON_EXPAND_VA_ARGS, (void), CoreJobGroup& group);
	PRIVATE_MAXON_SF_POINTER(ThreadServices_WaitGroup, WaitGroup, MAXON_EXPAND_VA_ARGS, (Bool), CoreJobGroup& group, Float64 timeout, WAITMODE mode);
	PRIVATE_MAXON_SF_POINTER(ThreadServices_GroupGetResult, GroupGetResult, MAXON_EXPAND_VA_ARGS, (Result<void>), CoreJobGroup& group, Float64 timeout, WAITMODE mode);
	PRIVATE_MAXON_SF_POINTER(ThreadServices_AddJob, AddJob, MAXON_EXPAND_VA_ARGS, (Result<void>), CoreJobGroup& group, const JobInterfacePOD& pod);
	PRIVATE_MAXON_SF_POINTER(ThreadServices_AddGroup, AddGroup, MAXON_EXPAND_VA_ARGS, (Result<void>), CoreJobGroup& group, CoreJobGroup* subGroup);
	PRIVATE_MAXON_SF_POINTER(ThreadServices_EnqueueGroup, EnqueueGroup, MAXON_EXPAND_VA_ARGS, (void), CoreJobGroup& group, JobQueueInterface* queue);
	PRIVATE_MAXON_SF_POINTER(ThreadServices_EnqueueGroupAndWait, EnqueueGroupAndWait, MAXON_EXPAND_VA_ARGS, (Result<void>), CoreJobGroup& group, JobQueueInterface* queue);
	PRIVATE_MAXON_SF_POINTER(ThreadServices_GetStaticJobBuffer, GetStaticJobBuffer, MAXON_EXPAND_VA_ARGS, (void*), const CoreJobGroup& group, Int* capacity);
	PRIVATE_MAXON_SF_POINTER(ThreadServices_GroupBatchAdd, GroupBatchAdd, MAXON_EXPAND_VA_ARGS, (Result<void>), CoreJobGroup& group, const JobInterfacePOD* first, void* memory, Int cnt, Int size);
	PRIVATE_MAXON_SF_POINTER(ThreadServices_AddGroupFinishedObserver, AddGroupFinishedObserver, MAXON_EXPAND_VA_ARGS, (Result<void>), CoreJobGroup& group, const JobInterfacePOD& observerPod, JobQueueInterface* observerQueue);
	PRIVATE_MAXON_SF_POINTER(ThreadServices_GroupCancel, GroupCancel, MAXON_EXPAND_VA_ARGS, (void), CoreJobGroup& group);
	PRIVATE_MAXON_SF_POINTER(ThreadServices_GroupMarkAsFinished, GroupMarkAsFinished, MAXON_EXPAND_VA_ARGS, (void), CoreJobGroup& group);
	PRIVATE_MAXON_SF_POINTER(ThreadServices_GetCurrentWorkerThreadIndex, GetCurrentWorkerThreadIndex, MAXON_EXPAND_VA_ARGS, (Int));
	PRIVATE_MAXON_SF_POINTER(ThreadServices_IsCurrentJobCancelled, IsCurrentJobCancelled, MAXON_EXPAND_VA_ARGS, (Bool));
	PRIVATE_MAXON_SF_POINTER(ThreadServices_AssimilateAlienThread, AssimilateAlienThread, MAXON_EXPAND_VA_ARGS, (Result<void>));
	PRIVATE_MAXON_SF_POINTER(ThreadServices_ThreadedExclusiveResource, ThreadedExclusiveResource, MAXON_EXPAND_VA_ARGS, (const void*), Int selector, const void* resourcePtr);
	PRIVATE_MAXON_SF_POINTER(ThreadServices_AddJobStatusReference, AddJobStatusReference, MAXON_EXPAND_VA_ARGS, (void), const JobInterfacePOD& pod);
	PRIVATE_MAXON_SF_POINTER(ThreadServices_RemoveJobStatusReference, RemoveJobStatusReference, MAXON_EXPAND_VA_ARGS, (void), const JobInterfacePOD& pod);
	PRIVATE_MAXON_SF_POINTER(ThreadServices_DisconnectPredecessor, DisconnectPredecessor, MAXON_EXPAND_VA_ARGS, (void), const JobInterfacePOD& pod, JobInterface** prev);
	template <typename IMPL> void Init()
	{
		ThreadServices_Start = ThreadServices_Start_GetPtr<IMPL>(true);
		ThreadServices_Enqueue = ThreadServices_Enqueue_GetPtr<IMPL>(true);
		ThreadServices_Wait = ThreadServices_Wait_GetPtr<IMPL>(true);
		ThreadServices_GetResult = ThreadServices_GetResult_GetPtr<IMPL>(true);
		ThreadServices_Reset = ThreadServices_Reset_GetPtr<IMPL>(true);
		ThreadServices_Cancel = ThreadServices_Cancel_GetPtr<IMPL>(true);
		ThreadServices_AddFinishedObserver = ThreadServices_AddFinishedObserver_GetPtr<IMPL>(true);
		ThreadServices_AddCancelledObserver = ThreadServices_AddCancelledObserver_GetPtr<IMPL>(true);
		ThreadServices_RemoveCancelledObserver = ThreadServices_RemoveCancelledObserver_GetPtr<IMPL>(true);
		ThreadServices_IsRunning = ThreadServices_IsRunning_GetPtr<IMPL>(true);
		ThreadServices_IsCancelled = ThreadServices_IsCancelled_GetPtr<IMPL>(true);
		ThreadServices_AddJobReference = ThreadServices_AddJobReference_GetPtr<IMPL>(true);
		ThreadServices_RemoveJobReference = ThreadServices_RemoveJobReference_GetPtr<IMPL>(true);
		ThreadServices_CreateStrongJobReference = ThreadServices_CreateStrongJobReference_GetPtr<IMPL>(true);
		ThreadServices_AddWeakJobReference = ThreadServices_AddWeakJobReference_GetPtr<IMPL>(true);
		ThreadServices_GetGroup = ThreadServices_GetGroup_GetPtr<IMPL>(true);
		ThreadServices_GetCurrentJob = ThreadServices_GetCurrentJob_GetPtr<IMPL>(true);
		ThreadServices_GetCurrentThread = ThreadServices_GetCurrentThread_GetPtr<IMPL>(true);
		ThreadServices_GetCurrentThreadType = ThreadServices_GetCurrentThreadType_GetPtr<IMPL>(true);
		ThreadServices_GetCurrentThreadType_1 = ThreadServices_GetCurrentThreadType_1_GetPtr<IMPL>(true);
		ThreadServices_GetCpuCount = ThreadServices_GetCpuCount_GetPtr<IMPL>(true);
		ThreadServices_GetStackEnd = ThreadServices_GetStackEnd_GetPtr<IMPL>(true);
		ThreadServices_CreateGroup = ThreadServices_CreateGroup_GetPtr<IMPL>(true);
		ThreadServices_CreateGroupForQueue = ThreadServices_CreateGroupForQueue_GetPtr<IMPL>(true);
		ThreadServices_AddGroupReference = ThreadServices_AddGroupReference_GetPtr<IMPL>(true);
		ThreadServices_RemoveGroupReference = ThreadServices_RemoveGroupReference_GetPtr<IMPL>(true);
		ThreadServices_WaitGroup = ThreadServices_WaitGroup_GetPtr<IMPL>(true);
		ThreadServices_GroupGetResult = ThreadServices_GroupGetResult_GetPtr<IMPL>(true);
		ThreadServices_AddJob = ThreadServices_AddJob_GetPtr<IMPL>(true);
		ThreadServices_AddGroup = ThreadServices_AddGroup_GetPtr<IMPL>(true);
		ThreadServices_EnqueueGroup = ThreadServices_EnqueueGroup_GetPtr<IMPL>(true);
		ThreadServices_EnqueueGroupAndWait = ThreadServices_EnqueueGroupAndWait_GetPtr<IMPL>(true);
		ThreadServices_GetStaticJobBuffer = ThreadServices_GetStaticJobBuffer_GetPtr<IMPL>(true);
		ThreadServices_GroupBatchAdd = ThreadServices_GroupBatchAdd_GetPtr<IMPL>(true);
		ThreadServices_AddGroupFinishedObserver = ThreadServices_AddGroupFinishedObserver_GetPtr<IMPL>(true);
		ThreadServices_GroupCancel = ThreadServices_GroupCancel_GetPtr<IMPL>(true);
		ThreadServices_GroupMarkAsFinished = ThreadServices_GroupMarkAsFinished_GetPtr<IMPL>(true);
		ThreadServices_GetCurrentWorkerThreadIndex = ThreadServices_GetCurrentWorkerThreadIndex_GetPtr<IMPL>(true);
		ThreadServices_IsCurrentJobCancelled = ThreadServices_IsCurrentJobCancelled_GetPtr<IMPL>(true);
		ThreadServices_AssimilateAlienThread = ThreadServices_AssimilateAlienThread_GetPtr<IMPL>(true);
		ThreadServices_ThreadedExclusiveResource = ThreadServices_ThreadedExclusiveResource_GetPtr<IMPL>(true);
		ThreadServices_AddJobStatusReference = ThreadServices_AddJobStatusReference_GetPtr<IMPL>(true);
		ThreadServices_RemoveJobStatusReference = ThreadServices_RemoveJobStatusReference_GetPtr<IMPL>(true);
		ThreadServices_DisconnectPredecessor = ThreadServices_DisconnectPredecessor_GetPtr<IMPL>(true);
	}
};

struct ThreadServices::Hxx2
{
	class Unresolved;
	template <typename C> class Wrapper
	{
	public:
		using Implementation = C;
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
		static CoreJobGroup* ThreadServices_CreateGroupForQueue(JobQueueInterface* queue, Int& cnt, Int jobSize, UInt flags) { return C::CreateGroupForQueue(queue, cnt, jobSize, flags); }
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
		static void ThreadServices_DisconnectPredecessor(const JobInterfacePOD& pod, JobInterface** prev) { return C::DisconnectPredecessor(pod, prev); }
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
MAXON_ATTRIBUTE_FORCE_INLINE auto ThreadServices::CreateGroupForQueue(JobQueueInterface* queue, Int& cnt, Int jobSize, UInt flags) -> CoreJobGroup*
{
	return MTable::_instance.ThreadServices_CreateGroupForQueue(queue, cnt, jobSize, flags);
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
MAXON_ATTRIBUTE_FORCE_INLINE auto ThreadServices::DisconnectPredecessor(const JobInterfacePOD& pod, JobInterface** prev) -> void
{
	return MTable::_instance.ThreadServices_DisconnectPredecessor(pod, prev);
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

