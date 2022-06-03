#if 1
namespace maxon
{
	const maxon::Char* const JobErrorInterface::MTable::_ids = 
	"";
	const maxon::METHOD_FLAGS JobErrorInterface::MTable::_flags[] = 
	{
		maxon::METHOD_FLAGS::NONE
	};
	PRIVATE_MAXON_INTERFACE_REGISTER_VIRTUAL_SINGLE_BASE(JobErrorInterface, , "net.maxon.interface.joberror", "maxon.JobErrorInterface", (ErrorInterface::PrivateGetInterface()));
	PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(JobErrorObject, , "net.maxon.error.job");
/// @cond INTERNAL

	const maxon::Char* const ThreadServices::MTable::_ids = 
		"Start@fae58db089ee5a98\0" // Result<void> Start(const JobInterfacePOD& pod, THREADPRIORITY priority)
		"Enqueue@e2541cbed58b374a\0" // void Enqueue(const JobInterfacePOD& pod, JobQueueInterface* queue)
		"Wait@2306fad3fc91e209\0" // Bool Wait(const JobInterfacePOD& pod, Float64 timeout, WAITMODE mode)
		"GetResult@9347a74448aaf356\0" // Result<void> GetResult(const JobInterfacePOD& pod, Float64 timeout, WAITMODE mode)
		"Reset@8db3a32d23d2d652\0" // Result<void> Reset(const JobInterfacePOD& pod)
		"Cancel@ca1cb126039bc9e9\0" // void Cancel(const JobInterfacePOD& pod)
		"AddFinishedObserver@c3508bf0425fea5\0" // Result<void> AddFinishedObserver(const JobInterfacePOD& pod, const JobInterfacePOD& observerPod, JobQueueInterface* observerQueue)
		"AddCancelledObserver@c3508bf0425fea5\0" // Result<void> AddCancelledObserver(const JobInterfacePOD& pod, const JobInterfacePOD& observerPod, JobQueueInterface* observerQueue)
		"RemoveCancelledObserver@e2e1ffc7ee5c5a0c\0" // Result<void> RemoveCancelledObserver(const JobInterfacePOD& pod, const JobInterfacePOD& observerPod)
		"IsRunning@47758000a817d8b3\0" // Bool IsRunning(const JobInterfacePOD& pod)
		"IsCancelled@47758000a817d8b3\0" // Bool IsCancelled(const JobInterfacePOD& pod)
		"AddJobReference@ca1cb126039bc9e9\0" // void AddJobReference(const JobInterfacePOD& pod)
		"RemoveJobReference@ca1cb126039bc9e9\0" // void RemoveJobReference(const JobInterfacePOD& pod)
		"CreateStrongJobReference@47758000a817d8b3\0" // Bool CreateStrongJobReference(const JobInterfacePOD& pod)
		"AddWeakJobReference@9f2c39030db7da17\0" // void AddWeakJobReference(const JobInterfacePOD& pod, WeakRefBase& weakRef)
		"GetGroup@b938d0fe8b1cf188\0" // CoreJobGroup* GetGroup(const JobInterfacePOD& pod)
		"GetCurrentJob@677a0e704746ebda\0" // const JobInterface* GetCurrentJob()
		"GetCurrentThread@a81e967aba79eb9d\0" // const ThreadInterface* GetCurrentThread()
		"GetCurrentThreadType@fa83887c9a9d4f17\0" // THREADTYPE GetCurrentThreadType()
		"GetCurrentThreadType@919c09ddbdc40688\0" // THREADTYPE GetCurrentThreadType(Int& threadIdentifier)
		"GetCpuCount@7d0e6f3d10c2128c\0" // Int GetCpuCount()
		"GetStackEnd@d3e5147a07f76d45\0" // void* GetStackEnd()
		"CreateGroup@3db076c1037f5438\0" // CoreJobGroup* CreateGroup(Int cnt, Int jobSize, UInt flags)
		"AddGroupReference@eefb614e0e0b6686\0" // void AddGroupReference(CoreJobGroup& group)
		"RemoveGroupReference@eefb614e0e0b6686\0" // void RemoveGroupReference(CoreJobGroup& group)
		"WaitGroup@52ce447000d3aa5c\0" // Bool WaitGroup(CoreJobGroup& group, Float64 timeout, WAITMODE mode)
		"GroupGetResult@34bfeae270c81e71\0" // Result<void> GroupGetResult(CoreJobGroup& group, Float64 timeout, WAITMODE mode)
		"AddJob@1e0ad82cac29c1db\0" // Result<void> AddJob(CoreJobGroup& group, const JobInterfacePOD& pod)
		"AddGroup@a55c74cbe28ec7a4\0" // Result<void> AddGroup(CoreJobGroup& group, CoreJobGroup* subGroup)
		"EnqueueGroup@aeb9826d5c22423b\0" // void EnqueueGroup(CoreJobGroup& group, JobQueueInterface* queue)
		"EnqueueGroupAndWait@7029e1730519ca80\0" // Result<void> EnqueueGroupAndWait(CoreJobGroup& group, JobQueueInterface* queue)
		"GetStaticJobBuffer@17f8e4c558e99e80\0" // void* GetStaticJobBuffer(const CoreJobGroup& group, Int* capacity)
		"GroupBatchAdd@4a1d840597b9da53\0" // Result<void> GroupBatchAdd(CoreJobGroup& group, const JobInterfacePOD* first, void* memory, Int cnt, Int size)
		"AddGroupFinishedObserver@fdccb1793d3fd880\0" // Result<void> AddGroupFinishedObserver(CoreJobGroup& group, const JobInterfacePOD& observerPod, JobQueueInterface* observerQueue)
		"GroupCancel@eefb614e0e0b6686\0" // void GroupCancel(CoreJobGroup& group)
		"GroupMarkAsFinished@eefb614e0e0b6686\0" // void GroupMarkAsFinished(CoreJobGroup& group)
		"GetCurrentWorkerThreadIndex@7d0e6f3d10c2128c\0" // Int GetCurrentWorkerThreadIndex()
		"IsCurrentJobCancelled@12e73654ffd67c7b\0" // Bool IsCurrentJobCancelled()
		"AssimilateAlienThread@a0cff72f181cfa62\0" // Result<void> AssimilateAlienThread()
		"ThreadedExclusiveResource@a14fe0b61b93b246\0" // const void* ThreadedExclusiveResource(Int selector, const void* resourcePtr)
		"AddJobStatusReference@ca1cb126039bc9e9\0" // void AddJobStatusReference(const JobInterfacePOD& pod)
		"RemoveJobStatusReference@ca1cb126039bc9e9\0" // void RemoveJobStatusReference(const JobInterfacePOD& pod)
	"";
	MAXON_WARNING_PUSH
	MAXON_WARNING_DISABLE_DEPRECATED
	class ThreadServices::Hxx2::Unresolved : public ThreadServices
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
		static Result<void> RemoveCancelledObserver(const JobInterfacePOD& pod, const JobInterfacePOD& observerPod) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return ThreadServices::RemoveCancelledObserver(pod, observerPod); return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::UNRESOLVED);}
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
		static THREADTYPE GetCurrentThreadType(Int& threadIdentifier) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ThreadServices::GetCurrentThreadType(threadIdentifier); return maxon::PrivateIncompleteNullReturnValue<THREADTYPE>(maxon::NULL_RETURN_REASON::UNRESOLVED, OVERLOAD_MAX_RANK);}
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
		static Result<void> AssimilateAlienThread() { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return ThreadServices::AssimilateAlienThread(); return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::UNRESOLVED);}
		static const void* ThreadedExclusiveResource(Int selector, const void* resourcePtr) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ThreadServices::ThreadedExclusiveResource(selector, resourcePtr); return nullptr;}
		static void AddJobStatusReference(const JobInterfacePOD& pod) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ThreadServices::AddJobStatusReference(pod); return maxon::PrivateLogNullptrError();}
		static void RemoveJobStatusReference(const JobInterfacePOD& pod) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ThreadServices::RemoveJobStatusReference(pod); return maxon::PrivateLogNullptrError();}
	};
	MAXON_WARNING_POP
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
		maxon::details::NullReturnType<Result<void>>::value,
		maxon::details::NullReturnType<const void*>::value,
		maxon::details::NullReturnType<void>::value,
		maxon::details::NullReturnType<void>::value,
		maxon::NULL_RETURN_TYPE::OTHER
	};
#endif
	maxon::Bool ThreadServices::MTable::InitUnresolved(maxon::NonvirtualInterfaceReference::UnresolvedAssembler assembler, MTable* tbl)
	{
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<void>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->ThreadServices_Start = &Hxx2::Wrapper<Hxx2::Unresolved>::ThreadServices_Start;
		#else
		tbl->ThreadServices_Start = &Hxx2::Wrapper<Hxx2::Unresolved>::ThreadServices_Start;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->ThreadServices_Enqueue = &Hxx2::Wrapper<Hxx2::Unresolved>::ThreadServices_Enqueue;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->ThreadServices_Wait = &Hxx2::Wrapper<Hxx2::Unresolved>::ThreadServices_Wait;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<void>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->ThreadServices_GetResult = &Hxx2::Wrapper<Hxx2::Unresolved>::ThreadServices_GetResult;
		#else
		tbl->ThreadServices_GetResult = &Hxx2::Wrapper<Hxx2::Unresolved>::ThreadServices_GetResult;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<void>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->ThreadServices_Reset = &Hxx2::Wrapper<Hxx2::Unresolved>::ThreadServices_Reset;
		#else
		tbl->ThreadServices_Reset = &Hxx2::Wrapper<Hxx2::Unresolved>::ThreadServices_Reset;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->ThreadServices_Cancel = &Hxx2::Wrapper<Hxx2::Unresolved>::ThreadServices_Cancel;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<void>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->ThreadServices_AddFinishedObserver = &Hxx2::Wrapper<Hxx2::Unresolved>::ThreadServices_AddFinishedObserver;
		#else
		tbl->ThreadServices_AddFinishedObserver = &Hxx2::Wrapper<Hxx2::Unresolved>::ThreadServices_AddFinishedObserver;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<void>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->ThreadServices_AddCancelledObserver = &Hxx2::Wrapper<Hxx2::Unresolved>::ThreadServices_AddCancelledObserver;
		#else
		tbl->ThreadServices_AddCancelledObserver = &Hxx2::Wrapper<Hxx2::Unresolved>::ThreadServices_AddCancelledObserver;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<void>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->ThreadServices_RemoveCancelledObserver = &Hxx2::Wrapper<Hxx2::Unresolved>::ThreadServices_RemoveCancelledObserver;
		#else
		tbl->ThreadServices_RemoveCancelledObserver = &Hxx2::Wrapper<Hxx2::Unresolved>::ThreadServices_RemoveCancelledObserver;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->ThreadServices_IsRunning = &Hxx2::Wrapper<Hxx2::Unresolved>::ThreadServices_IsRunning;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->ThreadServices_IsCancelled = &Hxx2::Wrapper<Hxx2::Unresolved>::ThreadServices_IsCancelled;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->ThreadServices_AddJobReference = &Hxx2::Wrapper<Hxx2::Unresolved>::ThreadServices_AddJobReference;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->ThreadServices_RemoveJobReference = &Hxx2::Wrapper<Hxx2::Unresolved>::ThreadServices_RemoveJobReference;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->ThreadServices_CreateStrongJobReference = &Hxx2::Wrapper<Hxx2::Unresolved>::ThreadServices_CreateStrongJobReference;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->ThreadServices_AddWeakJobReference = &Hxx2::Wrapper<Hxx2::Unresolved>::ThreadServices_AddWeakJobReference;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->ThreadServices_GetGroup = &Hxx2::Wrapper<Hxx2::Unresolved>::ThreadServices_GetGroup;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->ThreadServices_GetCurrentJob = &Hxx2::Wrapper<Hxx2::Unresolved>::ThreadServices_GetCurrentJob;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->ThreadServices_GetCurrentThread = &Hxx2::Wrapper<Hxx2::Unresolved>::ThreadServices_GetCurrentThread;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<THREADTYPE>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->ThreadServices_GetCurrentThreadType = &Hxx2::Wrapper<Hxx2::Unresolved>::ThreadServices_GetCurrentThreadType;
		#else
		tbl->ThreadServices_GetCurrentThreadType = &Hxx2::Wrapper<Hxx2::Unresolved>::ThreadServices_GetCurrentThreadType;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<THREADTYPE>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->ThreadServices_GetCurrentThreadType_1 = &Hxx2::Wrapper<Hxx2::Unresolved>::ThreadServices_GetCurrentThreadType_1;
		#else
		tbl->ThreadServices_GetCurrentThreadType_1 = &Hxx2::Wrapper<Hxx2::Unresolved>::ThreadServices_GetCurrentThreadType_1;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->ThreadServices_GetCpuCount = &Hxx2::Wrapper<Hxx2::Unresolved>::ThreadServices_GetCpuCount;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->ThreadServices_GetStackEnd = &Hxx2::Wrapper<Hxx2::Unresolved>::ThreadServices_GetStackEnd;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->ThreadServices_CreateGroup = &Hxx2::Wrapper<Hxx2::Unresolved>::ThreadServices_CreateGroup;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->ThreadServices_AddGroupReference = &Hxx2::Wrapper<Hxx2::Unresolved>::ThreadServices_AddGroupReference;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->ThreadServices_RemoveGroupReference = &Hxx2::Wrapper<Hxx2::Unresolved>::ThreadServices_RemoveGroupReference;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->ThreadServices_WaitGroup = &Hxx2::Wrapper<Hxx2::Unresolved>::ThreadServices_WaitGroup;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<void>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->ThreadServices_GroupGetResult = &Hxx2::Wrapper<Hxx2::Unresolved>::ThreadServices_GroupGetResult;
		#else
		tbl->ThreadServices_GroupGetResult = &Hxx2::Wrapper<Hxx2::Unresolved>::ThreadServices_GroupGetResult;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<void>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->ThreadServices_AddJob = &Hxx2::Wrapper<Hxx2::Unresolved>::ThreadServices_AddJob;
		#else
		tbl->ThreadServices_AddJob = &Hxx2::Wrapper<Hxx2::Unresolved>::ThreadServices_AddJob;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<void>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->ThreadServices_AddGroup = &Hxx2::Wrapper<Hxx2::Unresolved>::ThreadServices_AddGroup;
		#else
		tbl->ThreadServices_AddGroup = &Hxx2::Wrapper<Hxx2::Unresolved>::ThreadServices_AddGroup;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->ThreadServices_EnqueueGroup = &Hxx2::Wrapper<Hxx2::Unresolved>::ThreadServices_EnqueueGroup;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<void>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->ThreadServices_EnqueueGroupAndWait = &Hxx2::Wrapper<Hxx2::Unresolved>::ThreadServices_EnqueueGroupAndWait;
		#else
		tbl->ThreadServices_EnqueueGroupAndWait = &Hxx2::Wrapper<Hxx2::Unresolved>::ThreadServices_EnqueueGroupAndWait;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->ThreadServices_GetStaticJobBuffer = &Hxx2::Wrapper<Hxx2::Unresolved>::ThreadServices_GetStaticJobBuffer;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<void>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->ThreadServices_GroupBatchAdd = &Hxx2::Wrapper<Hxx2::Unresolved>::ThreadServices_GroupBatchAdd;
		#else
		tbl->ThreadServices_GroupBatchAdd = &Hxx2::Wrapper<Hxx2::Unresolved>::ThreadServices_GroupBatchAdd;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<void>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->ThreadServices_AddGroupFinishedObserver = &Hxx2::Wrapper<Hxx2::Unresolved>::ThreadServices_AddGroupFinishedObserver;
		#else
		tbl->ThreadServices_AddGroupFinishedObserver = &Hxx2::Wrapper<Hxx2::Unresolved>::ThreadServices_AddGroupFinishedObserver;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->ThreadServices_GroupCancel = &Hxx2::Wrapper<Hxx2::Unresolved>::ThreadServices_GroupCancel;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->ThreadServices_GroupMarkAsFinished = &Hxx2::Wrapper<Hxx2::Unresolved>::ThreadServices_GroupMarkAsFinished;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->ThreadServices_GetCurrentWorkerThreadIndex = &Hxx2::Wrapper<Hxx2::Unresolved>::ThreadServices_GetCurrentWorkerThreadIndex;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->ThreadServices_IsCurrentJobCancelled = &Hxx2::Wrapper<Hxx2::Unresolved>::ThreadServices_IsCurrentJobCancelled;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<void>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->ThreadServices_AssimilateAlienThread = &Hxx2::Wrapper<Hxx2::Unresolved>::ThreadServices_AssimilateAlienThread;
		#else
		tbl->ThreadServices_AssimilateAlienThread = &Hxx2::Wrapper<Hxx2::Unresolved>::ThreadServices_AssimilateAlienThread;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->ThreadServices_ThreadedExclusiveResource = &Hxx2::Wrapper<Hxx2::Unresolved>::ThreadServices_ThreadedExclusiveResource;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->ThreadServices_AddJobStatusReference = &Hxx2::Wrapper<Hxx2::Unresolved>::ThreadServices_AddJobStatusReference;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->ThreadServices_RemoveJobStatusReference = &Hxx2::Wrapper<Hxx2::Unresolved>::ThreadServices_RemoveJobStatusReference;
		#endif
	#ifdef PRIVATE_MAXON_ASSEMBLE_UNRESOLVED
		return assembler(&_interface, (maxon::Char*) tbl, _returnTypes, SIZEOF(MTable) / SIZEOF(void*));
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
	| maxon::ThreadServices::PrivateInstantiateNullValueHelper<maxon::Int>()
);
