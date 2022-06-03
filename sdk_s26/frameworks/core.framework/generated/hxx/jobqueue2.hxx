
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
	static const maxon::NULL_RETURN_TYPE _returnTypes[];
	static const maxon::Bool HAS_NONSTATIC = true;
	void (*JobQueueInterface_Free) (const JobQueueInterface* object);
	Result<JobQueueInterface*> (*JobQueueInterface_Alloc) (const maxon::SourceLocation& allocLocation, JOBQUEUETYPE type, Int threadCnt, JOBQUEUEMODE mode, const Char* name, UInt* ownerId);
	Int (*JobQueueInterface_GetThreadCount) (const JobQueueInterface* this_);
	Int (*JobQueueInterface_GetThreadCount_1) (JobQueueInterface* queue, Int maxWaitSessionLevel);
	void (*JobQueueInterface_Cancel) (JobQueueInterface* this_, UInt ownerId);
	void (*JobQueueInterface_CancelAndWait) (JobQueueInterface* this_, UInt ownerId);
	void (*JobQueueInterface_EnableThreadAffinity) (JobQueueInterface* this_, UInt ownerId);
	JobQueueInterface* (*JobQueueInterface_GetDestinationQueue) ();
	Result<void> (*JobQueueInterface_SetDestinationQueue) (JobQueueInterface* queue);
	JobQueueInterface* (*JobQueueInterface_GetMainThreadQueue) ();
	ServiceIOJobQueueInterface* (*JobQueueInterface_GetServiceIOQueue) ();
/// @cond IGNORE

	void (*JobQueueInterface_ExecuteJobs) (JobQueueInterface* this_, TimeValue timeout);
/// @endcond

	template <typename IMPL> void Init()
	{
		JobQueueInterface_Free = &IMPL::JobQueueInterface_Free;
		JobQueueInterface_Alloc = &IMPL::JobQueueInterface_Alloc;
		JobQueueInterface_GetThreadCount = &IMPL::JobQueueInterface_GetThreadCount;
		JobQueueInterface_GetThreadCount_1 = &IMPL::JobQueueInterface_GetThreadCount_1;
		JobQueueInterface_Cancel = &IMPL::JobQueueInterface_Cancel;
		JobQueueInterface_CancelAndWait = &IMPL::JobQueueInterface_CancelAndWait;
		JobQueueInterface_EnableThreadAffinity = &IMPL::JobQueueInterface_EnableThreadAffinity;
		JobQueueInterface_GetDestinationQueue = &IMPL::JobQueueInterface_GetDestinationQueue;
		JobQueueInterface_SetDestinationQueue = &IMPL::JobQueueInterface_SetDestinationQueue;
		JobQueueInterface_GetMainThreadQueue = &IMPL::JobQueueInterface_GetMainThreadQueue;
		JobQueueInterface_GetServiceIOQueue = &IMPL::JobQueueInterface_GetServiceIOQueue;
/// @cond IGNORE

		JobQueueInterface_ExecuteJobs = &IMPL::JobQueueInterface_ExecuteJobs;
/// @endcond

	}
};

struct JobQueueInterface::Hxx2
{
	class Unresolved;
	template <typename C> class Wrapper
	{
	public:
		static void JobQueueInterface_Free(const JobQueueInterface* object) { return C::Free(object); }
		static Result<JobQueueInterface*> JobQueueInterface_Alloc(const maxon::SourceLocation& allocLocation, JOBQUEUETYPE type, Int threadCnt, JOBQUEUEMODE mode, const Char* name, UInt* ownerId) { return C::Alloc(allocLocation, type, threadCnt, mode, name, ownerId); }
		static Int JobQueueInterface_GetThreadCount(const JobQueueInterface* this_) { return C::Get(this_)->GetThreadCount(); }
		static Int JobQueueInterface_GetThreadCount_1(JobQueueInterface* queue, Int maxWaitSessionLevel) { return C::GetThreadCount(queue, maxWaitSessionLevel); }
		static void JobQueueInterface_Cancel(JobQueueInterface* this_, UInt ownerId) { return C::Get(this_)->Cancel(ownerId); }
		static void JobQueueInterface_CancelAndWait(JobQueueInterface* this_, UInt ownerId) { return C::Get(this_)->CancelAndWait(ownerId); }
		static void JobQueueInterface_EnableThreadAffinity(JobQueueInterface* this_, UInt ownerId) { return C::Get(this_)->EnableThreadAffinity(ownerId); }
		static JobQueueInterface* JobQueueInterface_GetDestinationQueue() { return C::GetDestinationQueue(); }
		static Result<void> JobQueueInterface_SetDestinationQueue(JobQueueInterface* queue) { return C::SetDestinationQueue(queue); }
		static JobQueueInterface* JobQueueInterface_GetMainThreadQueue() { return C::GetMainThreadQueue(); }
		static ServiceIOJobQueueInterface* JobQueueInterface_GetServiceIOQueue() { return C::GetServiceIOQueue(); }
/// @cond IGNORE

		static void JobQueueInterface_ExecuteJobs(JobQueueInterface* this_, TimeValue timeout) { return C::Get(this_)->ExecuteJobs(std::forward<TimeValue>(timeout)); }
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
	return MTable::_instance.JobQueueInterface_GetThreadCount(this);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto JobQueueInterface::GetThreadCount(JobQueueInterface* queue, Int maxWaitSessionLevel) -> Int
{
	return MTable::_instance.JobQueueInterface_GetThreadCount_1(queue, maxWaitSessionLevel);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto JobQueueInterface::Cancel(UInt ownerId) -> void
{
	return MTable::_instance.JobQueueInterface_Cancel(this, ownerId);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto JobQueueInterface::CancelAndWait(UInt ownerId) -> void
{
	return MTable::_instance.JobQueueInterface_CancelAndWait(this, ownerId);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto JobQueueInterface::EnableThreadAffinity(UInt ownerId) -> void
{
	return MTable::_instance.JobQueueInterface_EnableThreadAffinity(this, ownerId);
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
	return MTable::_instance.JobQueueInterface_ExecuteJobs(this, std::forward<TimeValue>(timeout));
}
/// @endcond


auto JobQueueInterface::Reference::Create(JOBQUEUETYPE type, Int threadCnt, JOBQUEUEMODE mode, const Char* name, UInt* ownerId) -> maxon::Result<JobQueueRef>
{
	auto res_ = JobQueueInterface::Alloc(MAXON_SOURCE_LOCATION, type, threadCnt, mode, name, ownerId);
	if (res_ == maxon::FAILED) return res_.GetError(); else return JobQueueRef(res_.GetValue());
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto JobQueueInterface::Hxx1::ConstFn<S>::GetThreadCount() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const JobQueueInterface* o_ = (const JobQueueInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = JobQueueInterface::NullValuePtr(); if (!o_) return 0; } 
	return (MTable::_instance.JobQueueInterface_GetThreadCount(o_));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto JobQueueInterface::Hxx1::ConstFn<S>::GetThreadCount(JobQueueInterface* queue, Int maxWaitSessionLevel) -> Int
{
	return (MTable::_instance.JobQueueInterface_GetThreadCount_1(queue, maxWaitSessionLevel));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto JobQueueInterface::Hxx1::Fn<S>::Cancel(UInt ownerId) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); JobQueueInterface* o_ = (JobQueueInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { DebugStop(); return maxon::PrivateLogNullptrError(); } 
	MTable::_instance.JobQueueInterface_Cancel(o_, ownerId);
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto JobQueueInterface::Hxx1::Fn<S>::CancelAndWait(UInt ownerId) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); JobQueueInterface* o_ = (JobQueueInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { DebugStop(); return maxon::PrivateLogNullptrError(); } 
	MTable::_instance.JobQueueInterface_CancelAndWait(o_, ownerId);
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto JobQueueInterface::Hxx1::Fn<S>::EnableThreadAffinity(UInt ownerId) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); JobQueueInterface* o_ = (JobQueueInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { DebugStop(); return maxon::PrivateLogNullptrError(); } 
	MTable::_instance.JobQueueInterface_EnableThreadAffinity(o_, ownerId);
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

template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto JobQueueInterface::Hxx1::Fn<S>::ExecuteJobs(TimeValue timeout) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); JobQueueInterface* o_ = (JobQueueInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { DebugStop(); return maxon::PrivateLogNullptrError(); } 
	MTable::_instance.JobQueueInterface_ExecuteJobs(o_, std::forward<TimeValue>(timeout));
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

