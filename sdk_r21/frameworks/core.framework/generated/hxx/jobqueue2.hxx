
#ifndef DOXYGEN

#if defined MAXON_COMPILER_GCC
	#pragma GCC diagnostic push
	#if MAXON_COMPILER_GCC >= 600
		#pragma GCC diagnostic ignored "-Wmisleading-indentation"
	#endif
#endif

#if 1
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
	void (*_JobQueueInterface_Free) (const JobQueueInterface* object);
	Result<JobQueueInterface*> (*_JobQueueInterface_Alloc) (const maxon::SourceLocation& allocLocation, JOBQUEUETYPE type, Int threadCnt, JOBQUEUEMODE mode, const Char* name, UInt* ownerId);
	Int (*_JobQueueInterface_GetThreadCount) (const JobQueueInterface* this_);
	Int (*_JobQueueInterface_GetThreadCount_1) (JobQueueInterface* queue, Int maxWaitSessionLevel);
	void (*_JobQueueInterface_Cancel) (JobQueueInterface* this_, UInt ownerId);
	void (*_JobQueueInterface_CancelAndWait) (JobQueueInterface* this_, UInt ownerId);
	JobQueueInterface* (*_JobQueueInterface_GetDestinationQueue) ();
	Result<void> (*_JobQueueInterface_SetDestinationQueue) (JobQueueInterface* queue);
	JobQueueInterface* (*_JobQueueInterface_GetMainThreadQueue) ();
	ServiceIOJobQueueInterface* (*_JobQueueInterface_GetServiceIOQueue) ();
/// @cond IGNORE

	void (*_JobQueueInterface_ExecuteJobs) (JobQueueInterface* this_, TimeValue timeout);
/// @endcond

	template <typename IMPL> void Init()
	{
		_JobQueueInterface_Free = &IMPL::_JobQueueInterface_Free;
		_JobQueueInterface_Alloc = &IMPL::_JobQueueInterface_Alloc;
		_JobQueueInterface_GetThreadCount = &IMPL::_JobQueueInterface_GetThreadCount;
		_JobQueueInterface_GetThreadCount_1 = &IMPL::_JobQueueInterface_GetThreadCount_1;
		_JobQueueInterface_Cancel = &IMPL::_JobQueueInterface_Cancel;
		_JobQueueInterface_CancelAndWait = &IMPL::_JobQueueInterface_CancelAndWait;
		_JobQueueInterface_GetDestinationQueue = &IMPL::_JobQueueInterface_GetDestinationQueue;
		_JobQueueInterface_SetDestinationQueue = &IMPL::_JobQueueInterface_SetDestinationQueue;
		_JobQueueInterface_GetMainThreadQueue = &IMPL::_JobQueueInterface_GetMainThreadQueue;
		_JobQueueInterface_GetServiceIOQueue = &IMPL::_JobQueueInterface_GetServiceIOQueue;
/// @cond IGNORE

		_JobQueueInterface_ExecuteJobs = &IMPL::_JobQueueInterface_ExecuteJobs;
/// @endcond

	}
};

struct JobQueueInterface::Hxx2
{
	class Unresolved;
	template <typename C> class Wrapper
	{
	public:
	static void _JobQueueInterface_Free(const JobQueueInterface* object) { return C::Free(object); }
	static Result<JobQueueInterface*> _JobQueueInterface_Alloc(const maxon::SourceLocation& allocLocation, JOBQUEUETYPE type, Int threadCnt, JOBQUEUEMODE mode, const Char* name, UInt* ownerId) { return C::Alloc(allocLocation, type, threadCnt, mode, name, ownerId); }
	static Int _JobQueueInterface_GetThreadCount(const JobQueueInterface* this_) { return ((const C*) this_)->GetThreadCount(); }
	static Int _JobQueueInterface_GetThreadCount_1(JobQueueInterface* queue, Int maxWaitSessionLevel) { return C::GetThreadCount(queue, maxWaitSessionLevel); }
	static void _JobQueueInterface_Cancel(JobQueueInterface* this_, UInt ownerId) { return ((C*) this_)->Cancel(ownerId); }
	static void _JobQueueInterface_CancelAndWait(JobQueueInterface* this_, UInt ownerId) { return ((C*) this_)->CancelAndWait(ownerId); }
	static JobQueueInterface* _JobQueueInterface_GetDestinationQueue() { return C::GetDestinationQueue(); }
	static Result<void> _JobQueueInterface_SetDestinationQueue(JobQueueInterface* queue) { return C::SetDestinationQueue(queue); }
	static JobQueueInterface* _JobQueueInterface_GetMainThreadQueue() { return C::GetMainThreadQueue(); }
	static ServiceIOJobQueueInterface* _JobQueueInterface_GetServiceIOQueue() { return C::GetServiceIOQueue(); }
/// @cond IGNORE

	static void _JobQueueInterface_ExecuteJobs(JobQueueInterface* this_, TimeValue timeout) { return ((C*) this_)->ExecuteJobs(std::forward<TimeValue>(timeout)); }
/// @endcond

	};

};
MAXON_ATTRIBUTE_FORCE_INLINE auto JobQueueInterface::Free(const JobQueueInterface* object) -> void
{
	return MTable::_instance._JobQueueInterface_Free(object);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto JobQueueInterface::Alloc(const maxon::SourceLocation& allocLocation, JOBQUEUETYPE type, Int threadCnt, JOBQUEUEMODE mode, const Char* name, UInt* ownerId) -> Result<JobQueueInterface*>
{
	return MTable::_instance._JobQueueInterface_Alloc(allocLocation, type, threadCnt, mode, name, ownerId);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto JobQueueInterface::GetThreadCount() const -> Int
{
	return MTable::_instance._JobQueueInterface_GetThreadCount(this);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto JobQueueInterface::GetThreadCount(JobQueueInterface* queue, Int maxWaitSessionLevel) -> Int
{
	return MTable::_instance._JobQueueInterface_GetThreadCount_1(queue, maxWaitSessionLevel);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto JobQueueInterface::Cancel(UInt ownerId) -> void
{
	return MTable::_instance._JobQueueInterface_Cancel(this, ownerId);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto JobQueueInterface::CancelAndWait(UInt ownerId) -> void
{
	return MTable::_instance._JobQueueInterface_CancelAndWait(this, ownerId);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto JobQueueInterface::GetDestinationQueue() -> JobQueueInterface*
{
	return MTable::_instance._JobQueueInterface_GetDestinationQueue();
}
MAXON_ATTRIBUTE_FORCE_INLINE auto JobQueueInterface::SetDestinationQueue(JobQueueInterface* queue) -> Result<void>
{
	return MTable::_instance._JobQueueInterface_SetDestinationQueue(queue);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto JobQueueInterface::GetMainThreadQueue() -> JobQueueInterface*
{
	return MTable::_instance._JobQueueInterface_GetMainThreadQueue();
}
MAXON_ATTRIBUTE_FORCE_INLINE auto JobQueueInterface::GetServiceIOQueue() -> ServiceIOJobQueueInterface*
{
	return MTable::_instance._JobQueueInterface_GetServiceIOQueue();
}
/// @cond IGNORE

MAXON_ATTRIBUTE_FORCE_INLINE auto JobQueueInterface::ExecuteJobs(TimeValue timeout) -> void
{
	return MTable::_instance._JobQueueInterface_ExecuteJobs(this, std::forward<TimeValue>(timeout));
}
/// @endcond


auto JobQueueInterface::Reference::Create(JOBQUEUETYPE type, Int threadCnt, JOBQUEUEMODE mode, const Char* name, UInt* ownerId) -> maxon::Result<JobQueueRef>
{
	auto res_ = JobQueueInterface::Alloc(MAXON_SOURCE_LOCATION, type, threadCnt, mode, name, ownerId);
	if (res_ == maxon::FAILED) return res_.GetError(); else return JobQueueRef(res_.GetValue());
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto JobQueueInterface::Hxx1::ConstReferenceFunctionsImpl<S>::GetThreadCount() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const JobQueueInterface* o_ = (const JobQueueInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = JobQueueInterface::NullValuePtr(); if (!o_) return 0; } 
	return (MTable::_instance._JobQueueInterface_GetThreadCount(o_));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto JobQueueInterface::Hxx1::ConstReferenceFunctionsImpl<S>::GetThreadCount(JobQueueInterface* queue, Int maxWaitSessionLevel) -> Int { return (MTable::_instance._JobQueueInterface_GetThreadCount_1(queue, maxWaitSessionLevel)); }
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto JobQueueInterface::Hxx1::ReferenceFunctionsImpl<S>::Cancel(UInt ownerId) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); JobQueueInterface* o_ = (JobQueueInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) return maxon::PrivateLogNullptrError(); 
	MTable::_instance._JobQueueInterface_Cancel(o_, ownerId);
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto JobQueueInterface::Hxx1::ReferenceFunctionsImpl<S>::CancelAndWait(UInt ownerId) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); JobQueueInterface* o_ = (JobQueueInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) return maxon::PrivateLogNullptrError(); 
	MTable::_instance._JobQueueInterface_CancelAndWait(o_, ownerId);
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto JobQueueInterface::Hxx1::ConstReferenceFunctionsImpl<S>::GetDestinationQueue() -> JobQueueRef { return JobQueueRef(MTable::_instance._JobQueueInterface_GetDestinationQueue()); }
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto JobQueueInterface::Hxx1::ConstReferenceFunctionsImpl<S>::SetDestinationQueue(JobQueueInterface* queue) -> Result<void> { return (MTable::_instance._JobQueueInterface_SetDestinationQueue(queue)); }
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto JobQueueInterface::Hxx1::ConstReferenceFunctionsImpl<S>::GetMainThreadQueue() -> JobQueueRef { return JobQueueRef(MTable::_instance._JobQueueInterface_GetMainThreadQueue()); }
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto JobQueueInterface::Hxx1::ConstReferenceFunctionsImpl<S>::GetServiceIOQueue() -> ServiceIOJobQueueInterface* { return (MTable::_instance._JobQueueInterface_GetServiceIOQueue()); }
/// @cond IGNORE

template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto JobQueueInterface::Hxx1::ReferenceFunctionsImpl<S>::ExecuteJobs(TimeValue timeout) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); JobQueueInterface* o_ = (JobQueueInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) return maxon::PrivateLogNullptrError(); 
	MTable::_instance._JobQueueInterface_ExecuteJobs(o_, std::forward<TimeValue>(timeout));
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
/// @endcond

#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT)
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

