
#ifndef DOXYGEN

#if defined MAXON_COMPILER_GCC
	#pragma GCC diagnostic push
	#if MAXON_COMPILER_GCC >= 600
		#pragma GCC diagnostic ignored "-Wmisleading-indentation"
	#endif
#endif

#if 1
constexpr const maxon::Char* TimerInterface::PrivateGetCppName() { return "maxon::TimerRef"; }
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
	PRIVATE_MAXON_SF_POINTER(TimerInterface_Free, Free, MAXON_EXPAND_VA_ARGS, (void), const TimerInterface* object);
	PRIVATE_MAXON_SF_POINTER(TimerInterface_Alloc, Alloc, MAXON_IGNORE_VA_ARGS, (TimerInterface*), const maxon::SourceLocation& allocLocation);
	PRIVATE_MAXON_MF_POINTER(TimerInterface_CancelAndWait, CancelAndWait, false, TimerInterface,, (void));
	PRIVATE_MAXON_MF_POINTER(TimerInterface_Cancel, Cancel, false, TimerInterface,, (void));
	PRIVATE_MAXON_MF_POINTER(TimerInterface_ObservableTimerStarted, ObservableTimerStarted, false, TimerInterface, const, (maxon::ObservableRef<ObservableTimerStartedDelegate>));
	PRIVATE_MAXON_MF_POINTER(TimerInterface_ObservableTimerFinished, ObservableTimerFinished, false, TimerInterface, const, (maxon::ObservableRef<ObservableTimerFinishedDelegate>));
	PRIVATE_MAXON_MF_POINTER(TimerInterface_ObservableTimerOverload, ObservableTimerOverload, false, TimerInterface, const, (maxon::ObservableRef<ObservableTimerOverloadDelegate>));
/// @cond IGNORE

	PRIVATE_MAXON_SF_POINTER(TimerInterface_PrivateDisableAllTimers, PrivateDisableAllTimers, MAXON_EXPAND_VA_ARGS, (void));
	PRIVATE_MAXON_MF_POINTER(TimerInterface_Start, Start, false, TimerInterface,, (Result<void>), Float64 interval, Float64 startOffset, Float64 tolerance, const JobInterfacePOD& pod, JobQueueInterface* queue);
/// @endcond

	template <typename IMPL> void Init()
	{
		TimerInterface_Free = TimerInterface_Free_GetPtr<IMPL>(true);
		TimerInterface_Alloc = TimerInterface_Alloc_GetPtr<IMPL>(true);
		TimerInterface_CancelAndWait = TimerInterface_CancelAndWait_GetPtr<IMPL>(0, true).first;
		TimerInterface_Cancel = TimerInterface_Cancel_GetPtr<IMPL>(0, true).first;
		TimerInterface_ObservableTimerStarted = TimerInterface_ObservableTimerStarted_GetPtr<IMPL>(0, true).first;
		TimerInterface_ObservableTimerFinished = TimerInterface_ObservableTimerFinished_GetPtr<IMPL>(0, true).first;
		TimerInterface_ObservableTimerOverload = TimerInterface_ObservableTimerOverload_GetPtr<IMPL>(0, true).first;
/// @cond IGNORE

		TimerInterface_PrivateDisableAllTimers = TimerInterface_PrivateDisableAllTimers_GetPtr<IMPL>(true);
		TimerInterface_Start = TimerInterface_Start_GetPtr<IMPL>(0, true).first;
/// @endcond

	}
};

struct TimerInterface::Hxx2
{
	class Unresolved;
	template <typename C> class Wrapper
	{
	public:
		using Implementation = C;
		static void TimerInterface_Free(const TimerInterface* object) { return C::Free(object); }
		static TimerInterface* TimerInterface_Alloc(const maxon::SourceLocation& allocLocation) { return C::Alloc(allocLocation); }
		PRIVATE_MAXON_MF_WRAPPER(TimerInterface_CancelAndWait, TimerInterface,, (void)) { return C::Get(PRIVATE_MAXON_MF_THIS(TimerInterface))->CancelAndWait(); }
		PRIVATE_MAXON_MF_WRAPPER(TimerInterface_Cancel, TimerInterface,, (void)) { return C::Get(PRIVATE_MAXON_MF_THIS(TimerInterface))->Cancel(); }
		PRIVATE_MAXON_MF_WRAPPER(TimerInterface_ObservableTimerStarted, TimerInterface, const, (maxon::ObservableRef<ObservableTimerStartedDelegate>)) { return C::Get(PRIVATE_MAXON_MF_THIS(const TimerInterface))->ObservableTimerStarted(); }
		PRIVATE_MAXON_MF_WRAPPER(TimerInterface_ObservableTimerFinished, TimerInterface, const, (maxon::ObservableRef<ObservableTimerFinishedDelegate>)) { return C::Get(PRIVATE_MAXON_MF_THIS(const TimerInterface))->ObservableTimerFinished(); }
		PRIVATE_MAXON_MF_WRAPPER(TimerInterface_ObservableTimerOverload, TimerInterface, const, (maxon::ObservableRef<ObservableTimerOverloadDelegate>)) { return C::Get(PRIVATE_MAXON_MF_THIS(const TimerInterface))->ObservableTimerOverload(); }
/// @cond IGNORE

		static void TimerInterface_PrivateDisableAllTimers() { return C::PrivateDisableAllTimers(); }
		PRIVATE_MAXON_MF_WRAPPER(TimerInterface_Start, TimerInterface,, (Result<void>), Float64 interval, Float64 startOffset, Float64 tolerance, const JobInterfacePOD& pod, JobQueueInterface* queue) { return C::Get(PRIVATE_MAXON_MF_THIS(TimerInterface))->Start(interval, startOffset, tolerance, pod, queue); }
/// @endcond

	};

};
MAXON_ATTRIBUTE_FORCE_INLINE auto TimerInterface::Free(const TimerInterface* object) -> void
{
	return MTable::_instance.TimerInterface_Free(object);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto TimerInterface::Alloc(const maxon::SourceLocation& allocLocation) -> TimerInterface*
{
	return MTable::_instance.TimerInterface_Alloc(allocLocation);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto TimerInterface::CancelAndWait() -> void
{
	return PRIVATE_MAXON_MF_INVOKE((this), MTable::_instance.TimerInterface_CancelAndWait);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto TimerInterface::Cancel() -> void
{
	return PRIVATE_MAXON_MF_INVOKE((this), MTable::_instance.TimerInterface_Cancel);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto TimerInterface::ObservableTimerStarted() const -> maxon::ObservableRef<ObservableTimerStartedDelegate>
{
	return PRIVATE_MAXON_MF_INVOKE((this), MTable::_instance.TimerInterface_ObservableTimerStarted);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto TimerInterface::ObservableTimerFinished() const -> maxon::ObservableRef<ObservableTimerFinishedDelegate>
{
	return PRIVATE_MAXON_MF_INVOKE((this), MTable::_instance.TimerInterface_ObservableTimerFinished);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto TimerInterface::ObservableTimerOverload() const -> maxon::ObservableRef<ObservableTimerOverloadDelegate>
{
	return PRIVATE_MAXON_MF_INVOKE((this), MTable::_instance.TimerInterface_ObservableTimerOverload);
}
/// @cond IGNORE

MAXON_ATTRIBUTE_FORCE_INLINE auto TimerInterface::PrivateDisableAllTimers() -> void
{
	return MTable::_instance.TimerInterface_PrivateDisableAllTimers();
}
MAXON_ATTRIBUTE_FORCE_INLINE auto TimerInterface::Start(Float64 interval, Float64 startOffset, Float64 tolerance, const JobInterfacePOD& pod, JobQueueInterface* queue) -> Result<void>
{
	return PRIVATE_MAXON_MF_INVOKE((this), MTable::_instance.TimerInterface_Start, interval, startOffset, tolerance, pod, queue);
}
/// @endcond


auto TimerInterface::Hxx1::Reference::Create() -> maxon::ResultMemT<TimerRef>
{
	TimerInterface* res_ = TimerInterface::Alloc(MAXON_SOURCE_LOCATION);
	return TimerRef(maxon::ForwardResultPtr<TimerInterface>(res_));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto TimerInterface::Hxx1::Fn<S>::Start(TimeValue interval, TimeValue delay, TimeValue tolerance, JobInterface* job, JobQueueInterface* queue) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); TimerInterface* o_ = (TimerInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (o_->Start(std::forward<TimeValue>(interval), std::forward<TimeValue>(delay), std::forward<TimeValue>(tolerance), job, queue));
}
template <typename S> template <typename FN> MAXON_ATTRIBUTE_FORCE_INLINE auto TimerInterface::Hxx1::Fn<S>::Start(TimeValue interval, TimeValue delay, TimeValue tolerance, FN&& src, JobQueueInterface* queue) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<DISABLE_IF_JOBREF(FN,Result<void>)>, DISABLE_IF_JOBREF(FN,Result<void>)>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<DISABLE_IF_JOBREF(FN,Result<void>)>, DISABLE_IF_JOBREF(FN,Result<void>)>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); TimerInterface* o_ = (TimerInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return maxon::PrivateNullReturnValue<DISABLE_IF_JOBREF(FN,Result<void>)>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } 
	return (o_->Start<FN>(std::forward<TimeValue>(interval), std::forward<TimeValue>(delay), std::forward<TimeValue>(tolerance), std::forward<FN>(src), queue));
}
template <typename S> template <typename FN> MAXON_ATTRIBUTE_FORCE_INLINE auto TimerInterface::Hxx1::ConstFn<S>::AddPeriodicTimer(TimeValue interval, FN&& job, JobQueueInterface* queue) -> Result<TimerRef>
{
	return (TimerInterface::template AddPeriodicTimer<FN>(std::forward<TimeValue>(interval), std::forward<FN>(job), queue));
}
template <typename S> template <typename FN> MAXON_ATTRIBUTE_FORCE_INLINE auto TimerInterface::Hxx1::ConstFn<S>::AddOneShotTimer(TimeValue delay, FN&& job, JobQueueInterface* queue) -> Result<TimerRef>
{
	return (TimerInterface::template AddOneShotTimer<FN>(std::forward<TimeValue>(delay), std::forward<FN>(job), queue));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto TimerInterface::Hxx1::Fn<S>::CancelAndWait() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); TimerInterface* o_ = (TimerInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { DebugStop(); return maxon::PrivateLogNullptrError(); } 
	PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.TimerInterface_CancelAndWait);
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto TimerInterface::Hxx1::Fn<S>::Cancel() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); TimerInterface* o_ = (TimerInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { DebugStop(); return maxon::PrivateLogNullptrError(); } 
	PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.TimerInterface_Cancel);
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto TimerInterface::Hxx1::ConstFn<S>::ObservableTimerStarted() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<maxon::ObservableRef<ObservableTimerStartedDelegate>>, maxon::ObservableRef<ObservableTimerStartedDelegate>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<maxon::ObservableRef<ObservableTimerStartedDelegate>>, maxon::ObservableRef<ObservableTimerStartedDelegate>>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const TimerInterface* o_ = (const TimerInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = TimerInterface::NullValuePtr(); if (!o_) return maxon::ObservableRef<ObservableTimerStartedDelegate>::NullValue(); } 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.TimerInterface_ObservableTimerStarted));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto TimerInterface::Hxx1::ConstFn<S>::ObservableTimerFinished() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<maxon::ObservableRef<ObservableTimerFinishedDelegate>>, maxon::ObservableRef<ObservableTimerFinishedDelegate>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<maxon::ObservableRef<ObservableTimerFinishedDelegate>>, maxon::ObservableRef<ObservableTimerFinishedDelegate>>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const TimerInterface* o_ = (const TimerInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = TimerInterface::NullValuePtr(); if (!o_) return maxon::ObservableRef<ObservableTimerFinishedDelegate>::NullValue(); } 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.TimerInterface_ObservableTimerFinished));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto TimerInterface::Hxx1::ConstFn<S>::ObservableTimerOverload() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<maxon::ObservableRef<ObservableTimerOverloadDelegate>>, maxon::ObservableRef<ObservableTimerOverloadDelegate>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<maxon::ObservableRef<ObservableTimerOverloadDelegate>>, maxon::ObservableRef<ObservableTimerOverloadDelegate>>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const TimerInterface* o_ = (const TimerInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = TimerInterface::NullValuePtr(); if (!o_) return maxon::ObservableRef<ObservableTimerOverloadDelegate>::NullValue(); } 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.TimerInterface_ObservableTimerOverload));
}
/// @cond IGNORE

/// @endcond

#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT) && !defined(MAXON_DEPENDENCY_DISABLE_timer)
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

