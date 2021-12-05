#if 1
namespace maxon
{
	const maxon::Char* const ThreadCancelledErrorInterface::MTable::_ids = 
	"";
	PRIVATE_MAXON_INTERFACE_REGISTER_VIRTUAL_SINGLE_BASE(ThreadCancelledErrorInterface, , "net.maxon.interface.threadcancellederror", "maxon.ThreadCancelledErrorInterface", (&ErrorInterface::_interface));
	PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(ThreadCancelledErrorObject, , "net.maxon.error.threadcancelled");
	const maxon::Char* const JobErrorInterface::MTable::_ids = 
	"";
	PRIVATE_MAXON_INTERFACE_REGISTER_VIRTUAL_SINGLE_BASE(JobErrorInterface, , "net.maxon.interface.joberror", "maxon.JobErrorInterface", (&ErrorInterface::_interface));
	PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(JobErrorObject, , "net.maxon.error.job");
/// @cond INTERNAL

	const maxon::Char* const ThreadServices::MTable::_ids = 
		"Start@7edeb738ce5b3afb\0" // Result<void> Start(const JobInterfacePOD& pod, THREADPRIORITY priority)
		"Enqueue@e4048116549c2b9b\0" // void Enqueue(const JobInterfacePOD& pod, JobQueueInterface* queue)
		"Wait@ebeb78d3765f9b60\0" // Bool Wait(const JobInterfacePOD& pod, Float64 timeout, WAITMODE mode)
		"GetResult@d00b577d05fba29f\0" // Result<void> GetResult(const JobInterfacePOD& pod, Float64 timeout, WAITMODE mode)
		"Reset@0f44428d4a5045f1\0" // Result<void> Reset(const JobInterfacePOD& pod)
		"Cancel@1659ebc1f694f39a\0" // void Cancel(const JobInterfacePOD& pod)
		"AddFinishedObserver@4f067409c64d3ac6\0" // Result<void> AddFinishedObserver(const JobInterfacePOD& pod, const JobInterfacePOD& observerPod, JobQueueInterface* observerQueue)
		"AddCancelledObserver@4f067409c64d3ac6\0" // Result<void> AddCancelledObserver(const JobInterfacePOD& pod, const JobInterfacePOD& observerPod, JobQueueInterface* observerQueue)
		"RemoveCancelledObserver@1c06e4e2e395364f\0" // Result<void> RemoveCancelledObserver(const JobInterfacePOD& pod, const JobInterfacePOD& observerPod)
		"IsRunning@87a4e7f738b9cf10\0" // Bool IsRunning(const JobInterfacePOD& pod)
		"IsCancelled@87a4e7f738b9cf10\0" // Bool IsCancelled(const JobInterfacePOD& pod)
		"AddJobReference@1659ebc1f694f39a\0" // void AddJobReference(const JobInterfacePOD& pod)
		"RemoveJobReference@1659ebc1f694f39a\0" // void RemoveJobReference(const JobInterfacePOD& pod)
		"CreateStrongJobReference@87a4e7f738b9cf10\0" // Bool CreateStrongJobReference(const JobInterfacePOD& pod)
		"AddWeakJobReference@1dd2057551272a46\0" // void AddWeakJobReference(const JobInterfacePOD& pod, WeakRefBase& weakRef)
		"GetGroup@ca0cb4d84d0395af\0" // CoreJobGroup* GetGroup(const JobInterfacePOD& pod)
		"GetCurrentJob@00294dc84e62bfb1\0" // const JobInterface* GetCurrentJob()
		"GetCurrentThread@a96b1b2609e4e558\0" // const ThreadInterface* GetCurrentThread()
		"GetCurrentThreadType@1e782cc59e4b77a4\0" // THREADTYPE GetCurrentThreadType()
		"GetCurrentThreadType@9962f8ee190a3bcd\0" // THREADTYPE GetCurrentThreadType(Int& threadIdentifier)
		"GetCpuCount@4386c6f\0" // Int GetCpuCount()
		"GetStackEnd@19257ef7f6\0" // void* GetStackEnd()
		"CreateGroup@3bd45ad1e4aaddf5\0" // CoreJobGroup* CreateGroup(Int cnt, Int jobSize, UInt flags)
		"AddGroupReference@ed5283de56720ced\0" // void AddGroupReference(CoreJobGroup& group)
		"RemoveGroupReference@ed5283de56720ced\0" // void RemoveGroupReference(CoreJobGroup& group)
		"WaitGroup@26cf71ebb51e3899\0" // Bool WaitGroup(CoreJobGroup& group, Float64 timeout, WAITMODE mode)
		"GroupGetResult@331d78d9ac043e7a\0" // Result<void> GroupGetResult(CoreJobGroup& group, Float64 timeout, WAITMODE mode)
		"AddJob@3c48a3118a7241ea\0" // Result<void> AddJob(CoreJobGroup& group, const JobInterfacePOD& pod)
		"AddGroup@d2ff4f93e6c46519\0" // Result<void> AddGroup(CoreJobGroup& group, CoreJobGroup* subGroup)
		"EnqueueGroup@dadc13358d06f368\0" // void EnqueueGroup(CoreJobGroup& group, JobQueueInterface* queue)
		"EnqueueGroupAndWait@b9699ae58dfc84ff\0" // Result<void> EnqueueGroupAndWait(CoreJobGroup& group, JobQueueInterface* queue)
		"GetStaticJobBuffer@948e56dce0e3de17\0" // void* GetStaticJobBuffer(const CoreJobGroup& group, Int* capacity)
		"GroupBatchAdd@86662f0f6d2b2df6\0" // Result<void> GroupBatchAdd(CoreJobGroup& group, const JobInterfacePOD* first, void* memory, Int cnt, Int size)
		"AddGroupFinishedObserver@07af6f31a3831b4b\0" // Result<void> AddGroupFinishedObserver(CoreJobGroup& group, const JobInterfacePOD& observerPod, JobQueueInterface* observerQueue)
		"GroupCancel@ed5283de56720ced\0" // void GroupCancel(CoreJobGroup& group)
		"GroupMarkAsFinished@ed5283de56720ced\0" // void GroupMarkAsFinished(CoreJobGroup& group)
		"GetCurrentWorkerThreadIndex@4386c6f\0" // Int GetCurrentWorkerThreadIndex()
		"IsCurrentJobCancelled@76f018ea\0" // Bool IsCurrentJobCancelled()
		"AssimilateAlienThread@0499ab9fb052ee8b\0" // Result<void> AssimilateAlienThread()
		"ThreadedExclusiveResource@7d9a99a7958cad11\0" // const void* ThreadedExclusiveResource(Int selector, const void* resourcePtr)
		"AddJobStatusReference@1659ebc1f694f39a\0" // void AddJobStatusReference(const JobInterfacePOD& pod)
		"RemoveJobStatusReference@1659ebc1f694f39a\0" // void RemoveJobStatusReference(const JobInterfacePOD& pod)
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
		if (maxon::details::NullReturnType<Result<void>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_ThreadServices_Start = &Hxx2::Wrapper<Hxx2::Unresolved>::_ThreadServices_Start;
		#else
		tbl->_ThreadServices_Start = &Hxx2::Wrapper<Hxx2::Unresolved>::_ThreadServices_Start;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->_ThreadServices_Enqueue = &Hxx2::Wrapper<Hxx2::Unresolved>::_ThreadServices_Enqueue;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->_ThreadServices_Wait = &Hxx2::Wrapper<Hxx2::Unresolved>::_ThreadServices_Wait;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<void>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_ThreadServices_GetResult = &Hxx2::Wrapper<Hxx2::Unresolved>::_ThreadServices_GetResult;
		#else
		tbl->_ThreadServices_GetResult = &Hxx2::Wrapper<Hxx2::Unresolved>::_ThreadServices_GetResult;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<void>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_ThreadServices_Reset = &Hxx2::Wrapper<Hxx2::Unresolved>::_ThreadServices_Reset;
		#else
		tbl->_ThreadServices_Reset = &Hxx2::Wrapper<Hxx2::Unresolved>::_ThreadServices_Reset;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->_ThreadServices_Cancel = &Hxx2::Wrapper<Hxx2::Unresolved>::_ThreadServices_Cancel;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<void>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_ThreadServices_AddFinishedObserver = &Hxx2::Wrapper<Hxx2::Unresolved>::_ThreadServices_AddFinishedObserver;
		#else
		tbl->_ThreadServices_AddFinishedObserver = &Hxx2::Wrapper<Hxx2::Unresolved>::_ThreadServices_AddFinishedObserver;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<void>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_ThreadServices_AddCancelledObserver = &Hxx2::Wrapper<Hxx2::Unresolved>::_ThreadServices_AddCancelledObserver;
		#else
		tbl->_ThreadServices_AddCancelledObserver = &Hxx2::Wrapper<Hxx2::Unresolved>::_ThreadServices_AddCancelledObserver;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<void>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_ThreadServices_RemoveCancelledObserver = &Hxx2::Wrapper<Hxx2::Unresolved>::_ThreadServices_RemoveCancelledObserver;
		#else
		tbl->_ThreadServices_RemoveCancelledObserver = &Hxx2::Wrapper<Hxx2::Unresolved>::_ThreadServices_RemoveCancelledObserver;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->_ThreadServices_IsRunning = &Hxx2::Wrapper<Hxx2::Unresolved>::_ThreadServices_IsRunning;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->_ThreadServices_IsCancelled = &Hxx2::Wrapper<Hxx2::Unresolved>::_ThreadServices_IsCancelled;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->_ThreadServices_AddJobReference = &Hxx2::Wrapper<Hxx2::Unresolved>::_ThreadServices_AddJobReference;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->_ThreadServices_RemoveJobReference = &Hxx2::Wrapper<Hxx2::Unresolved>::_ThreadServices_RemoveJobReference;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->_ThreadServices_CreateStrongJobReference = &Hxx2::Wrapper<Hxx2::Unresolved>::_ThreadServices_CreateStrongJobReference;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->_ThreadServices_AddWeakJobReference = &Hxx2::Wrapper<Hxx2::Unresolved>::_ThreadServices_AddWeakJobReference;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->_ThreadServices_GetGroup = &Hxx2::Wrapper<Hxx2::Unresolved>::_ThreadServices_GetGroup;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->_ThreadServices_GetCurrentJob = &Hxx2::Wrapper<Hxx2::Unresolved>::_ThreadServices_GetCurrentJob;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->_ThreadServices_GetCurrentThread = &Hxx2::Wrapper<Hxx2::Unresolved>::_ThreadServices_GetCurrentThread;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<THREADTYPE>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_ThreadServices_GetCurrentThreadType = &Hxx2::Wrapper<Hxx2::Unresolved>::_ThreadServices_GetCurrentThreadType;
		#else
		tbl->_ThreadServices_GetCurrentThreadType = &Hxx2::Wrapper<Hxx2::Unresolved>::_ThreadServices_GetCurrentThreadType;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<THREADTYPE>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_ThreadServices_GetCurrentThreadType_1 = &Hxx2::Wrapper<Hxx2::Unresolved>::_ThreadServices_GetCurrentThreadType_1;
		#else
		tbl->_ThreadServices_GetCurrentThreadType_1 = &Hxx2::Wrapper<Hxx2::Unresolved>::_ThreadServices_GetCurrentThreadType_1;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->_ThreadServices_GetCpuCount = &Hxx2::Wrapper<Hxx2::Unresolved>::_ThreadServices_GetCpuCount;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->_ThreadServices_GetStackEnd = &Hxx2::Wrapper<Hxx2::Unresolved>::_ThreadServices_GetStackEnd;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->_ThreadServices_CreateGroup = &Hxx2::Wrapper<Hxx2::Unresolved>::_ThreadServices_CreateGroup;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->_ThreadServices_AddGroupReference = &Hxx2::Wrapper<Hxx2::Unresolved>::_ThreadServices_AddGroupReference;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->_ThreadServices_RemoveGroupReference = &Hxx2::Wrapper<Hxx2::Unresolved>::_ThreadServices_RemoveGroupReference;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->_ThreadServices_WaitGroup = &Hxx2::Wrapper<Hxx2::Unresolved>::_ThreadServices_WaitGroup;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<void>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_ThreadServices_GroupGetResult = &Hxx2::Wrapper<Hxx2::Unresolved>::_ThreadServices_GroupGetResult;
		#else
		tbl->_ThreadServices_GroupGetResult = &Hxx2::Wrapper<Hxx2::Unresolved>::_ThreadServices_GroupGetResult;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<void>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_ThreadServices_AddJob = &Hxx2::Wrapper<Hxx2::Unresolved>::_ThreadServices_AddJob;
		#else
		tbl->_ThreadServices_AddJob = &Hxx2::Wrapper<Hxx2::Unresolved>::_ThreadServices_AddJob;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<void>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_ThreadServices_AddGroup = &Hxx2::Wrapper<Hxx2::Unresolved>::_ThreadServices_AddGroup;
		#else
		tbl->_ThreadServices_AddGroup = &Hxx2::Wrapper<Hxx2::Unresolved>::_ThreadServices_AddGroup;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->_ThreadServices_EnqueueGroup = &Hxx2::Wrapper<Hxx2::Unresolved>::_ThreadServices_EnqueueGroup;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<void>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_ThreadServices_EnqueueGroupAndWait = &Hxx2::Wrapper<Hxx2::Unresolved>::_ThreadServices_EnqueueGroupAndWait;
		#else
		tbl->_ThreadServices_EnqueueGroupAndWait = &Hxx2::Wrapper<Hxx2::Unresolved>::_ThreadServices_EnqueueGroupAndWait;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->_ThreadServices_GetStaticJobBuffer = &Hxx2::Wrapper<Hxx2::Unresolved>::_ThreadServices_GetStaticJobBuffer;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<void>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_ThreadServices_GroupBatchAdd = &Hxx2::Wrapper<Hxx2::Unresolved>::_ThreadServices_GroupBatchAdd;
		#else
		tbl->_ThreadServices_GroupBatchAdd = &Hxx2::Wrapper<Hxx2::Unresolved>::_ThreadServices_GroupBatchAdd;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<void>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_ThreadServices_AddGroupFinishedObserver = &Hxx2::Wrapper<Hxx2::Unresolved>::_ThreadServices_AddGroupFinishedObserver;
		#else
		tbl->_ThreadServices_AddGroupFinishedObserver = &Hxx2::Wrapper<Hxx2::Unresolved>::_ThreadServices_AddGroupFinishedObserver;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->_ThreadServices_GroupCancel = &Hxx2::Wrapper<Hxx2::Unresolved>::_ThreadServices_GroupCancel;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->_ThreadServices_GroupMarkAsFinished = &Hxx2::Wrapper<Hxx2::Unresolved>::_ThreadServices_GroupMarkAsFinished;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->_ThreadServices_GetCurrentWorkerThreadIndex = &Hxx2::Wrapper<Hxx2::Unresolved>::_ThreadServices_GetCurrentWorkerThreadIndex;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->_ThreadServices_IsCurrentJobCancelled = &Hxx2::Wrapper<Hxx2::Unresolved>::_ThreadServices_IsCurrentJobCancelled;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<void>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_ThreadServices_AssimilateAlienThread = &Hxx2::Wrapper<Hxx2::Unresolved>::_ThreadServices_AssimilateAlienThread;
		#else
		tbl->_ThreadServices_AssimilateAlienThread = &Hxx2::Wrapper<Hxx2::Unresolved>::_ThreadServices_AssimilateAlienThread;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->_ThreadServices_ThreadedExclusiveResource = &Hxx2::Wrapper<Hxx2::Unresolved>::_ThreadServices_ThreadedExclusiveResource;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->_ThreadServices_AddJobStatusReference = &Hxx2::Wrapper<Hxx2::Unresolved>::_ThreadServices_AddJobStatusReference;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->_ThreadServices_RemoveJobStatusReference = &Hxx2::Wrapper<Hxx2::Unresolved>::_ThreadServices_RemoveJobStatusReference;
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
