
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


struct TimerInterface::MTable
{
	static MTable _instance;
	static MTable _unresolvedInstance;
	static const maxon::Char* const _ids;
	static maxon::Bool InitUnresolved(maxon::NonvirtualInterfaceReference::UnresolvedAssembler assembler, MTable* tbl);
	static const maxon::NULL_RETURN_TYPE _returnTypes[];
	static const maxon::Bool HAS_NONSTATIC = true;
	void (*_TimerInterface_Free) (const TimerInterface* object);
	TimerInterface* (*_TimerInterface_Alloc) (const maxon::SourceLocation& allocLocation);
	void (*_TimerInterface_CancelAndWait) (TimerInterface* this_);
	void (*_TimerInterface_Cancel) (TimerInterface* this_);
	maxon::ObservableRef<ObservableTimerStartedDelegate> (*_TimerInterface_ObservableTimerStarted) (const TimerInterface* this_);
	maxon::ObservableRef<ObservableTimerFinishedDelegate> (*_TimerInterface_ObservableTimerFinished) (const TimerInterface* this_);
	maxon::ObservableRef<ObservableTimerOverloadDelegate> (*_TimerInterface_ObservableTimerOverload) (const TimerInterface* this_);
/// @cond IGNORE

	void (*_TimerInterface_PrivateDisableAllTimers) ();
	Result<void> (*_TimerInterface_Start) (TimerInterface* this_, Float64 interval, Float64 startOffset, Float64 tolerance, const JobInterfacePOD& pod, JobQueueInterface* queue);
/// @endcond

	template <typename IMPL> void Init()
	{
		_TimerInterface_Free = &IMPL::_TimerInterface_Free;
		_TimerInterface_Alloc = &IMPL::_TimerInterface_Alloc;
		_TimerInterface_CancelAndWait = &IMPL::_TimerInterface_CancelAndWait;
		_TimerInterface_Cancel = &IMPL::_TimerInterface_Cancel;
		_TimerInterface_ObservableTimerStarted = &IMPL::_TimerInterface_ObservableTimerStarted;
		_TimerInterface_ObservableTimerFinished = &IMPL::_TimerInterface_ObservableTimerFinished;
		_TimerInterface_ObservableTimerOverload = &IMPL::_TimerInterface_ObservableTimerOverload;
/// @cond IGNORE

		_TimerInterface_PrivateDisableAllTimers = &IMPL::_TimerInterface_PrivateDisableAllTimers;
		_TimerInterface_Start = &IMPL::_TimerInterface_Start;
/// @endcond

	}
};

struct TimerInterface::Hxx2
{
	class Unresolved;
	template <typename C> class Wrapper
	{
	public:
	static void _TimerInterface_Free(const TimerInterface* object) { return C::Free(object); }
	static TimerInterface* _TimerInterface_Alloc(const maxon::SourceLocation& allocLocation) { return C::Alloc(allocLocation); }
	static void _TimerInterface_CancelAndWait(TimerInterface* this_) { return ((C*) this_)->CancelAndWait(); }
	static void _TimerInterface_Cancel(TimerInterface* this_) { return ((C*) this_)->Cancel(); }
	static maxon::ObservableRef<ObservableTimerStartedDelegate> _TimerInterface_ObservableTimerStarted(const TimerInterface* this_) { return ((const C*) this_)->ObservableTimerStarted(); }
	static maxon::ObservableRef<ObservableTimerFinishedDelegate> _TimerInterface_ObservableTimerFinished(const TimerInterface* this_) { return ((const C*) this_)->ObservableTimerFinished(); }
	static maxon::ObservableRef<ObservableTimerOverloadDelegate> _TimerInterface_ObservableTimerOverload(const TimerInterface* this_) { return ((const C*) this_)->ObservableTimerOverload(); }
/// @cond IGNORE

	static void _TimerInterface_PrivateDisableAllTimers() { return C::PrivateDisableAllTimers(); }
	static Result<void> _TimerInterface_Start(TimerInterface* this_, Float64 interval, Float64 startOffset, Float64 tolerance, const JobInterfacePOD& pod, JobQueueInterface* queue) { return ((C*) this_)->Start(interval, startOffset, tolerance, pod, queue); }
/// @endcond

	};

};
MAXON_ATTRIBUTE_FORCE_INLINE auto TimerInterface::Free(const TimerInterface* object) -> void
{
	return MTable::_instance._TimerInterface_Free(object);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto TimerInterface::Alloc(const maxon::SourceLocation& allocLocation) -> TimerInterface*
{
	return MTable::_instance._TimerInterface_Alloc(allocLocation);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto TimerInterface::CancelAndWait() -> void
{
	return MTable::_instance._TimerInterface_CancelAndWait(this);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto TimerInterface::Cancel() -> void
{
	return MTable::_instance._TimerInterface_Cancel(this);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto TimerInterface::ObservableTimerStarted() const -> maxon::ObservableRef<ObservableTimerStartedDelegate>
{
	return MTable::_instance._TimerInterface_ObservableTimerStarted(this);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto TimerInterface::ObservableTimerFinished() const -> maxon::ObservableRef<ObservableTimerFinishedDelegate>
{
	return MTable::_instance._TimerInterface_ObservableTimerFinished(this);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto TimerInterface::ObservableTimerOverload() const -> maxon::ObservableRef<ObservableTimerOverloadDelegate>
{
	return MTable::_instance._TimerInterface_ObservableTimerOverload(this);
}
/// @cond IGNORE

MAXON_ATTRIBUTE_FORCE_INLINE auto TimerInterface::PrivateDisableAllTimers() -> void
{
	return MTable::_instance._TimerInterface_PrivateDisableAllTimers();
}
MAXON_ATTRIBUTE_FORCE_INLINE auto TimerInterface::Start(Float64 interval, Float64 startOffset, Float64 tolerance, const JobInterfacePOD& pod, JobQueueInterface* queue) -> Result<void>
{
	return MTable::_instance._TimerInterface_Start(this, interval, startOffset, tolerance, pod, queue);
}
/// @endcond


auto TimerInterface::Hxx1::Reference::Create() -> maxon::ResultMemT<TimerRef>
{
	TimerInterface* res_ = TimerInterface::Alloc(MAXON_SOURCE_LOCATION);
	return TimerRef(maxon::ForwardResultPtr<TimerInterface>(res_));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto TimerInterface::Hxx1::ReferenceFunctionsImpl<S>::Start(TimeValue interval, TimeValue delay, TimeValue tolerance, JobInterface* job, JobQueueInterface* queue) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); TimerInterface* o_ = (TimerInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); 
	return (o_->Start(std::forward<TimeValue>(interval), std::forward<TimeValue>(delay), std::forward<TimeValue>(tolerance), job, queue));
}
template <typename S> template <typename FN> MAXON_ATTRIBUTE_FORCE_INLINE auto TimerInterface::Hxx1::ReferenceFunctionsImpl<S>::Start(TimeValue interval, TimeValue delay, TimeValue tolerance, FN&& src, JobQueueInterface* queue) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<DISABLE_IF_JOBREF(FN,Result<void>)>, DISABLE_IF_JOBREF(FN,Result<void>)>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<DISABLE_IF_JOBREF(FN,Result<void>)>, DISABLE_IF_JOBREF(FN,Result<void>)>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); TimerInterface* o_ = (TimerInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) return maxon::PrivateNullReturnValue<DISABLE_IF_JOBREF(FN,Result<void>)>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); 
	return (o_->Start<FN>(std::forward<TimeValue>(interval), std::forward<TimeValue>(delay), std::forward<TimeValue>(tolerance), std::forward<FN>(src), queue));
}
template <typename S> template <typename FN> MAXON_ATTRIBUTE_FORCE_INLINE auto TimerInterface::Hxx1::ConstReferenceFunctionsImpl<S>::AddPeriodicTimer(TimeValue interval, FN&& job, JobQueueInterface* queue) -> Result<TimerRef> { return (TimerInterface::AddPeriodicTimer<FN>(std::forward<TimeValue>(interval), std::forward<FN>(job), queue)); }
template <typename S> template <typename FN> MAXON_ATTRIBUTE_FORCE_INLINE auto TimerInterface::Hxx1::ConstReferenceFunctionsImpl<S>::AddOneShotTimer(TimeValue delay, FN&& job, JobQueueInterface* queue) -> Result<TimerRef> { return (TimerInterface::AddOneShotTimer<FN>(std::forward<TimeValue>(delay), std::forward<FN>(job), queue)); }
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto TimerInterface::Hxx1::ReferenceFunctionsImpl<S>::CancelAndWait() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); TimerInterface* o_ = (TimerInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) return maxon::PrivateLogNullptrError(); 
	MTable::_instance._TimerInterface_CancelAndWait(o_);
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto TimerInterface::Hxx1::ReferenceFunctionsImpl<S>::Cancel() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); TimerInterface* o_ = (TimerInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) return maxon::PrivateLogNullptrError(); 
	MTable::_instance._TimerInterface_Cancel(o_);
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto TimerInterface::Hxx1::ConstReferenceFunctionsImpl<S>::ObservableTimerStarted() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<maxon::ObservableRef<ObservableTimerStartedDelegate>>, maxon::ObservableRef<ObservableTimerStartedDelegate>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<maxon::ObservableRef<ObservableTimerStartedDelegate>>, maxon::ObservableRef<ObservableTimerStartedDelegate>>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const TimerInterface* o_ = (const TimerInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = TimerInterface::NullValuePtr(); if (!o_) return maxon::ObservableRef<ObservableTimerStartedDelegate>::NullValue(); } 
	return (MTable::_instance._TimerInterface_ObservableTimerStarted(o_));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto TimerInterface::Hxx1::ConstReferenceFunctionsImpl<S>::ObservableTimerFinished() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<maxon::ObservableRef<ObservableTimerFinishedDelegate>>, maxon::ObservableRef<ObservableTimerFinishedDelegate>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<maxon::ObservableRef<ObservableTimerFinishedDelegate>>, maxon::ObservableRef<ObservableTimerFinishedDelegate>>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const TimerInterface* o_ = (const TimerInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = TimerInterface::NullValuePtr(); if (!o_) return maxon::ObservableRef<ObservableTimerFinishedDelegate>::NullValue(); } 
	return (MTable::_instance._TimerInterface_ObservableTimerFinished(o_));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto TimerInterface::Hxx1::ConstReferenceFunctionsImpl<S>::ObservableTimerOverload() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<maxon::ObservableRef<ObservableTimerOverloadDelegate>>, maxon::ObservableRef<ObservableTimerOverloadDelegate>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<maxon::ObservableRef<ObservableTimerOverloadDelegate>>, maxon::ObservableRef<ObservableTimerOverloadDelegate>>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const TimerInterface* o_ = (const TimerInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = TimerInterface::NullValuePtr(); if (!o_) return maxon::ObservableRef<ObservableTimerOverloadDelegate>::NullValue(); } 
	return (MTable::_instance._TimerInterface_ObservableTimerOverload(o_));
}
/// @cond IGNORE

/// @endcond

#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT)
#ifdef MAXON_USE_REGISTER_FUNCTION
MAXON_STATIC_STORAGE(maxon::EntityUse, s_ui_maxon_TimerInterface); \
MAXON_ATTRIBUTE_CONSTRUCTOR static void Register_s_ui_maxon_TimerInterface() { new (s_ui_maxon_TimerInterface) maxon::EntityUse(TimerInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/timer.h", false); }
#else // !MAXON_USE_REGISTER_FUNCTION
static maxon::EntityUse s_ui_maxon_TimerInterface(TimerInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/timer.h", false);
#endif // MAXON_USE_REGISTER_FUNCTION
#endif
#endif

#ifdef MAXON_COMPILER_GCC
	#pragma GCC diagnostic pop
#endif

#endif

