
#ifndef DOXYGEN

#if defined MAXON_COMPILER_GCC
	#pragma GCC diagnostic push
	#if MAXON_COMPILER_GCC >= 600
		#pragma GCC diagnostic ignored "-Wmisleading-indentation"
	#endif
#endif

#if 1
constexpr const maxon::Char* JobQueueInterface::PrivateGetCppName() { return "maxon::JobQueueRef"; }
/// @cond IGNORE

/// @endcond


struct JobQueueInterface::MTable
{
	static MTable _instance;
	static MTable _unresolvedInstance;
	static const maxon::Char* const _ids;
	static maxon::Bool InitUnresolved(maxon::NonvirtualInterfaceReference::UnresolvedAssembler assembler, MTable* tbl);
	static const maxon::UNRESOLVED_RETURN_TYPE _returnTypes[];
	static const maxon::Bool HAS_NONSTATIC = true;
	PRIVATE_MAXON_SF_POINTER(JobQueueInterface_Free, Free, MAXON_EXPAND_VA_ARGS, (void), const JobQueueInterface* object);
	PRIVATE_MAXON_SF_POINTER(JobQueueInterface_Alloc, Alloc, MAXON_IGNORE_VA_ARGS, (Result<JobQueueInterface*>), const maxon::SourceLocation& allocLocation, JOBQUEUETYPE type, Int threadCnt, JOBQUEUEMODE mode, const Char* name, UInt* ownerId);
	PRIVATE_MAXON_MF_POINTER(JobQueueInterface_GetThreadCount, GetThreadCount, false, JobQueueInterface, const, (Int));
	PRIVATE_MAXON_SF_POINTER(JobQueueInterface_GetThreadCount_1, GetThreadCount, MAXON_EXPAND_VA_ARGS, (Int), JobQueueInterface* queue, Int maxWaitSessionLevel);
	PRIVATE_MAXON_MF_POINTER(JobQueueInterface_Cancel, Cancel, false, JobQueueInterface,, (void), UInt ownerId);
	PRIVATE_MAXON_MF_POINTER(JobQueueInterface_CancelAndWait, CancelAndWait, false, JobQueueInterface,, (void), UInt ownerId);
	PRIVATE_MAXON_MF_POINTER(JobQueueInterface_EnableThreadAffinity, EnableThreadAffinity, false, JobQueueInterface,, (void), UInt ownerId);
	PRIVATE_MAXON_MF_POINTER(JobQueueInterface_AlwaysUseCurrentThread, AlwaysUseCurrentThread, false, JobQueueInterface,, (void), UInt ownerId);
	PRIVATE_MAXON_MF_POINTER(JobQueueInterface_SetIdleSpinTime, SetIdleSpinTime, false, JobQueueInterface,, (void), UInt ownerId, TimeValue spinTime);
	PRIVATE_MAXON_SF_POINTER(JobQueueInterface_GetDestinationQueue, GetDestinationQueue, MAXON_EXPAND_VA_ARGS, (JobQueueInterface*));
	PRIVATE_MAXON_SF_POINTER(JobQueueInterface_SetDestinationQueue, SetDestinationQueue, MAXON_EXPAND_VA_ARGS, (Result<void>), JobQueueInterface* queue);
	PRIVATE_MAXON_SF_POINTER(JobQueueInterface_GetMainThreadQueue, GetMainThreadQueue, MAXON_EXPAND_VA_ARGS, (JobQueueInterface*));
	PRIVATE_MAXON_SF_POINTER(JobQueueInterface_GetServiceIOQueue, GetServiceIOQueue, MAXON_EXPAND_VA_ARGS, (ServiceIOJobQueueInterface*));
/// @cond IGNORE

	PRIVATE_MAXON_MF_POINTER(JobQueueInterface_ExecuteJobs, ExecuteJobs, false, JobQueueInterface,, (void), TimeValue timeout);
/// @endcond

	template <typename IMPL> void Init()
	{
		JobQueueInterface_Free = JobQueueInterface_Free_GetPtr<IMPL>(true);
		JobQueueInterface_Alloc = JobQueueInterface_Alloc_GetPtr<IMPL>(true);
		JobQueueInterface_GetThreadCount = JobQueueInterface_GetThreadCount_GetPtr<IMPL>(0, true).first;
		JobQueueInterface_GetThreadCount_1 = JobQueueInterface_GetThreadCount_1_GetPtr<IMPL>(true);
		JobQueueInterface_Cancel = JobQueueInterface_Cancel_GetPtr<IMPL>(0, true).first;
		JobQueueInterface_CancelAndWait = JobQueueInterface_CancelAndWait_GetPtr<IMPL>(0, true).first;
		JobQueueInterface_EnableThreadAffinity = JobQueueInterface_EnableThreadAffinity_GetPtr<IMPL>(0, true).first;
		JobQueueInterface_AlwaysUseCurrentThread = JobQueueInterface_AlwaysUseCurrentThread_GetPtr<IMPL>(0, true).first;
		JobQueueInterface_SetIdleSpinTime = JobQueueInterface_SetIdleSpinTime_GetPtr<IMPL>(0, true).first;
		JobQueueInterface_GetDestinationQueue = JobQueueInterface_GetDestinationQueue_GetPtr<IMPL>(true);
		JobQueueInterface_SetDestinationQueue = JobQueueInterface_SetDestinationQueue_GetPtr<IMPL>(true);
		JobQueueInterface_GetMainThreadQueue = JobQueueInterface_GetMainThreadQueue_GetPtr<IMPL>(true);
		JobQueueInterface_GetServiceIOQueue = JobQueueInterface_GetServiceIOQueue_GetPtr<IMPL>(true);
/// @cond IGNORE

		JobQueueInterface_ExecuteJobs = JobQueueInterface_ExecuteJobs_GetPtr<IMPL>(0, true).first;
/// @endcond

	}
};

struct JobQueueInterface::Hxx2
{
	class Unresolved;
	template <typename S> class Wrapper
	{
	public:
		using Implementation = S;
		static void JobQueueInterface_Free(const JobQueueInterface* object) { return S::Free(object); }
		static Result<JobQueueInterface*> JobQueueInterface_Alloc(const maxon::SourceLocation& allocLocation, JOBQUEUETYPE type, Int threadCnt, JOBQUEUEMODE mode, const Char* name, UInt* ownerId) { return S::Alloc(allocLocation, type, threadCnt, mode, name, ownerId); }
		PRIVATE_MAXON_MF_WRAPPER(JobQueueInterface_GetThreadCount, JobQueueInterface, const, (Int)) { return S::Get(PRIVATE_MAXON_MF_THIS(const JobQueueInterface))->GetThreadCount(); }
		static Int JobQueueInterface_GetThreadCount_1(JobQueueInterface* queue, Int maxWaitSessionLevel) { return S::GetThreadCount(queue, maxWaitSessionLevel); }
		PRIVATE_MAXON_MF_WRAPPER(JobQueueInterface_Cancel, JobQueueInterface,, (void), UInt ownerId) { return S::Get(PRIVATE_MAXON_MF_THIS(JobQueueInterface))->Cancel(ownerId); }
		PRIVATE_MAXON_MF_WRAPPER(JobQueueInterface_CancelAndWait, JobQueueInterface,, (void), UInt ownerId) { return S::Get(PRIVATE_MAXON_MF_THIS(JobQueueInterface))->CancelAndWait(ownerId); }
		PRIVATE_MAXON_MF_WRAPPER(JobQueueInterface_EnableThreadAffinity, JobQueueInterface,, (void), UInt ownerId) { return S::Get(PRIVATE_MAXON_MF_THIS(JobQueueInterface))->EnableThreadAffinity(ownerId); }
		PRIVATE_MAXON_MF_WRAPPER(JobQueueInterface_AlwaysUseCurrentThread, JobQueueInterface,, (void), UInt ownerId) { return S::Get(PRIVATE_MAXON_MF_THIS(JobQueueInterface))->AlwaysUseCurrentThread(ownerId); }
		PRIVATE_MAXON_MF_WRAPPER(JobQueueInterface_SetIdleSpinTime, JobQueueInterface,, (void), UInt ownerId, TimeValue spinTime) { return S::Get(PRIVATE_MAXON_MF_THIS(JobQueueInterface))->SetIdleSpinTime(ownerId, std::forward<TimeValue>(spinTime)); }
		static JobQueueInterface* JobQueueInterface_GetDestinationQueue() { return S::GetDestinationQueue(); }
		static Result<void> JobQueueInterface_SetDestinationQueue(JobQueueInterface* queue) { return S::SetDestinationQueue(queue); }
		static JobQueueInterface* JobQueueInterface_GetMainThreadQueue() { return S::GetMainThreadQueue(); }
		static ServiceIOJobQueueInterface* JobQueueInterface_GetServiceIOQueue() { return S::GetServiceIOQueue(); }
/// @cond IGNORE

		PRIVATE_MAXON_MF_WRAPPER(JobQueueInterface_ExecuteJobs, JobQueueInterface,, (void), TimeValue timeout) { return S::Get(PRIVATE_MAXON_MF_THIS(JobQueueInterface))->ExecuteJobs(std::forward<TimeValue>(timeout)); }
/// @endcond

	};

};
MAXON_ATTRIBUTE_FORCE_INLINE auto JobQueueInterface::Free(const JobQueueInterface* object) -> void
{
	return MTable::_instance.JobQueueInterface_Free(object);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto JobQueueInterface::Alloc(const maxon::SourceLocation& allocLocation, JOBQUEUETYPE type, Int threadCnt, JOBQUEUEMODE mode, const Char* name, UInt* ownerId) -> Result<JobQueueInterface*>
{
	return MTable::_instance.JobQueueInterface_Alloc(allocLocation, type, threadCnt, mode, name, ownerId);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto JobQueueInterface::GetThreadCount() const -> Int
{
	return PRIVATE_MAXON_MF_INVOKE((this), MTable::_instance.JobQueueInterface_GetThreadCount);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto JobQueueInterface::GetThreadCount(JobQueueInterface* queue, Int maxWaitSessionLevel) -> Int
{
	return MTable::_instance.JobQueueInterface_GetThreadCount_1(queue, maxWaitSessionLevel);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto JobQueueInterface::Cancel(UInt ownerId) -> void
{
	return PRIVATE_MAXON_MF_INVOKE((this), MTable::_instance.JobQueueInterface_Cancel, ownerId);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto JobQueueInterface::CancelAndWait(UInt ownerId) -> void
{
	return PRIVATE_MAXON_MF_INVOKE((this), MTable::_instance.JobQueueInterface_CancelAndWait, ownerId);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto JobQueueInterface::EnableThreadAffinity(UInt ownerId) -> void
{
	return PRIVATE_MAXON_MF_INVOKE((this), MTable::_instance.JobQueueInterface_EnableThreadAffinity, ownerId);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto JobQueueInterface::AlwaysUseCurrentThread(UInt ownerId) -> void
{
	return PRIVATE_MAXON_MF_INVOKE((this), MTable::_instance.JobQueueInterface_AlwaysUseCurrentThread, ownerId);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto JobQueueInterface::SetIdleSpinTime(UInt ownerId, TimeValue spinTime) -> void
{
	return PRIVATE_MAXON_MF_INVOKE((this), MTable::_instance.JobQueueInterface_SetIdleSpinTime, ownerId, std::forward<TimeValue>(spinTime));
}
MAXON_ATTRIBUTE_FORCE_INLINE auto JobQueueInterface::GetDestinationQueue() -> JobQueueInterface*
{
	return MTable::_instance.JobQueueInterface_GetDestinationQueue();
}
MAXON_ATTRIBUTE_FORCE_INLINE auto JobQueueInterface::SetDestinationQueue(JobQueueInterface* queue) -> Result<void>
{
	return MTable::_instance.JobQueueInterface_SetDestinationQueue(queue);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto JobQueueInterface::GetMainThreadQueue() -> JobQueueInterface*
{
	return MTable::_instance.JobQueueInterface_GetMainThreadQueue();
}
MAXON_ATTRIBUTE_FORCE_INLINE auto JobQueueInterface::GetServiceIOQueue() -> ServiceIOJobQueueInterface*
{
	return MTable::_instance.JobQueueInterface_GetServiceIOQueue();
}
/// @cond IGNORE

MAXON_ATTRIBUTE_FORCE_INLINE auto JobQueueInterface::ExecuteJobs(TimeValue timeout) -> void
{
	return PRIVATE_MAXON_MF_INVOKE((this), MTable::_instance.JobQueueInterface_ExecuteJobs, std::forward<TimeValue>(timeout));
}
/// @endcond


auto JobQueueInterface::Reference::Create(JOBQUEUETYPE type, Int threadCnt, JOBQUEUEMODE mode, const Char* name, UInt* ownerId) -> maxon::Result<JobQueueRef>
{
	auto res_ = JobQueueInterface::Alloc(MAXON_SOURCE_LOCATION, type, threadCnt, mode, name, ownerId);
	if (res_ == maxon::FAILED) return res_.GetError(); else return JobQueueRef(res_.GetValue());
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto JobQueueInterface::Hxx1::ConstFn<S>::GetThreadCount() const -> HXXADDRET2(Int)
{
	HXXRETURN0(HXXADDRET2(Int)); HXXRES; HXXCONST(0) 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.JobQueueInterface_GetThreadCount));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto JobQueueInterface::Hxx1::ConstFn<S>::GetThreadCount(JobQueueInterface* queue, Int maxWaitSessionLevel) -> Int
{
	return (MTable::_instance.JobQueueInterface_GetThreadCount_1(queue, maxWaitSessionLevel));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto JobQueueInterface::Hxx1::Fn<S>::Cancel(UInt ownerId) const -> HXXADDRET2(void)
{
	HXXRETURN0(HXXADDRET2(void)); HXXRES; HXXNONCONST(DebugStop(), , false, maxon::PrivateLogNullptrError()) 
	PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.JobQueueInterface_Cancel, ownerId);
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto JobQueueInterface::Hxx1::Fn<S>::CancelAndWait(UInt ownerId) const -> HXXADDRET2(void)
{
	HXXRETURN0(HXXADDRET2(void)); HXXRES; HXXNONCONST(DebugStop(), , false, maxon::PrivateLogNullptrError()) 
	PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.JobQueueInterface_CancelAndWait, ownerId);
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto JobQueueInterface::Hxx1::Fn<S>::EnableThreadAffinity(UInt ownerId) const -> HXXADDRET2(void)
{
	HXXRETURN0(HXXADDRET2(void)); HXXRES; HXXNONCONST(DebugStop(), , false, maxon::PrivateLogNullptrError()) 
	PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.JobQueueInterface_EnableThreadAffinity, ownerId);
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto JobQueueInterface::Hxx1::Fn<S>::AlwaysUseCurrentThread(UInt ownerId) const -> HXXADDRET2(void)
{
	HXXRETURN0(HXXADDRET2(void)); HXXRES; HXXNONCONST(DebugStop(), , false, maxon::PrivateLogNullptrError()) 
	PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.JobQueueInterface_AlwaysUseCurrentThread, ownerId);
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto JobQueueInterface::Hxx1::Fn<S>::SetIdleSpinTime(UInt ownerId, TimeValue spinTime) const -> HXXADDRET2(void)
{
	HXXRETURN0(HXXADDRET2(void)); HXXRES; HXXNONCONST(DebugStop(), , false, maxon::PrivateLogNullptrError()) 
	PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.JobQueueInterface_SetIdleSpinTime, ownerId, std::forward<TimeValue>(spinTime));
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto JobQueueInterface::Hxx1::ConstFn<S>::GetDestinationQueue() -> JobQueueRef
{
	return JobQueueRef(MTable::_instance.JobQueueInterface_GetDestinationQueue());
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto JobQueueInterface::Hxx1::ConstFn<S>::SetDestinationQueue(JobQueueInterface* queue) -> Result<void>
{
	return (MTable::_instance.JobQueueInterface_SetDestinationQueue(queue));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto JobQueueInterface::Hxx1::ConstFn<S>::GetMainThreadQueue() -> JobQueueRef
{
	return JobQueueRef(MTable::_instance.JobQueueInterface_GetMainThreadQueue());
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto JobQueueInterface::Hxx1::ConstFn<S>::GetServiceIOQueue() -> ServiceIOJobQueueInterface*
{
	return (MTable::_instance.JobQueueInterface_GetServiceIOQueue());
}
/// @cond IGNORE

template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto JobQueueInterface::Hxx1::Fn<S>::ExecuteJobs(TimeValue timeout) const -> HXXADDRET2(void)
{
	HXXRETURN0(HXXADDRET2(void)); HXXRES; HXXNONCONST(DebugStop(), , false, maxon::PrivateLogNullptrError()) 
	PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.JobQueueInterface_ExecuteJobs, std::forward<TimeValue>(timeout));
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
/// @endcond

#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT) && !defined(MAXON_DEPENDENCY_DISABLE_jobqueue)
#ifdef MAXON_USE_REGISTER_FUNCTION
MAXON_STATIC_STORAGE(maxon::EntityUse, s_ui_maxon_JobQueueInterface); \
MAXON_ATTRIBUTE_CONSTRUCTOR static void Register_s_ui_maxon_JobQueueInterface() { new (s_ui_maxon_JobQueueInterface) maxon::EntityUse(JobQueueInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/jobqueue.h", false); }
#else // !MAXON_USE_REGISTER_FUNCTION
static maxon::EntityUse s_ui_maxon_JobQueueInterface(JobQueueInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/jobqueue.h", false);
#endif // MAXON_USE_REGISTER_FUNCTION
#endif
#endif

#ifdef MAXON_COMPILER_GCC
	#pragma GCC diagnostic pop
#endif

#endif

