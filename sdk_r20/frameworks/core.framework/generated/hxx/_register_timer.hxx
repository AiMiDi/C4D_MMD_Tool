#if 1
namespace maxon
{
/// @cond IGNORE

/// @endcond

	const maxon::Char* const TimerInterface::MTable::_ids = 
		"Free@3b3f40f7ff1016b9\0" // Free(const TimerInterface* object)
		"Alloc@fa873f252381fe26\0" // Alloc(const maxon::SourceLocation& allocLocation)
		"CancelAndWait@6b2e10f\0" // CancelAndWait()
		"Cancel@6b2e10f\0" // Cancel()
		"ObservableTimerStarted@9b11a666c6b3c1e2\0" // ObservableTimerStarted() const
		"ObservableTimerFinished@63d42bd2034c448b\0" // ObservableTimerFinished() const
		"ObservableTimerOverload@43de56394fdeb043\0" // ObservableTimerOverload() const
/// @cond IGNORE

		"PrivateDisableAllTimers@cfa940f4\0" // PrivateDisableAllTimers()
		"Start@ac8785535140b689\0" // Start(Float64 interval, Float64 startOffset, Float64 tolerance, const JobInterfacePOD& pod, JobQueueInterface* queue)
/// @endcond

	"";
	class TimerInterface::Unresolved : public TimerInterface
	{
	public:
		static const Unresolved* Get(const TimerInterface* o) { return (const Unresolved*) o; }
		static Unresolved* Get(TimerInterface* o) { return (Unresolved*) o; }
		static void Free(const TimerInterface* object) { if (object && maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return TimerInterface::Free(object); return maxon::PrivateLogNullptrError();}
		static TimerInterface* Alloc(const maxon::SourceLocation& allocLocation) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return TimerInterface::Alloc(allocLocation); return nullptr;}
		void CancelAndWait() { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ((TimerInterface*) this)->CancelAndWait(); return maxon::PrivateLogNullptrError();}
		void Cancel() { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ((TimerInterface*) this)->Cancel(); return maxon::PrivateLogNullptrError();}
		maxon::ObservableRef<ObservableTimerStartedDelegate> ObservableTimerStarted() const { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ((const TimerInterface*) this)->ObservableTimerStarted(); return maxon::ObservableRef<ObservableTimerStartedDelegate>::NullValue();}
		maxon::ObservableRef<ObservableTimerFinishedDelegate> ObservableTimerFinished() const { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ((const TimerInterface*) this)->ObservableTimerFinished(); return maxon::ObservableRef<ObservableTimerFinishedDelegate>::NullValue();}
		maxon::ObservableRef<ObservableTimerOverloadDelegate> ObservableTimerOverload() const { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ((const TimerInterface*) this)->ObservableTimerOverload(); return maxon::ObservableRef<ObservableTimerOverloadDelegate>::NullValue();}
/// @cond IGNORE

		static void PrivateDisableAllTimers() { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return TimerInterface::PrivateDisableAllTimers(); return maxon::PrivateLogNullptrError();}
		Result<void> Start(Float64 interval, Float64 startOffset, Float64 tolerance, const JobInterfacePOD& pod, JobQueueInterface* queue) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return ((TimerInterface*) this)->Start(interval, startOffset, tolerance, pod, queue); return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::UNRESOLVED);}
/// @endcond

	};
#ifdef PRIVATE_MAXON_ASSEMBLE_UNRESOLVED
	const maxon::NULL_RETURN_TYPE TimerInterface::MTable::_returnTypes[] = 
	{
		maxon::NULL_RETURN_TYPE::VOID_ZERO_FREE_FUNCTION,
		maxon::details::NullReturnType<TimerInterface*>::value,
		maxon::details::NullReturnType<void>::value,
		maxon::details::NullReturnType<void>::value,
		maxon::details::NullReturnType<maxon::ObservableRef<ObservableTimerStartedDelegate>>::value,
		maxon::details::NullReturnType<maxon::ObservableRef<ObservableTimerFinishedDelegate>>::value,
		maxon::details::NullReturnType<maxon::ObservableRef<ObservableTimerOverloadDelegate>>::value,
/// @cond IGNORE

		maxon::details::NullReturnType<void>::value,
		maxon::details::NullReturnType<Result<void>>::value,
/// @endcond

		maxon::NULL_RETURN_TYPE::OTHER
	};
#endif
	maxon::Bool TimerInterface::MTable::InitUnresolved(maxon::NonvirtualInterfaceReference::UnresolvedAssembler assembler, MTable* tbl)
	{
	#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
	#else
		tbl->_TimerInterface_Free = &Wrapper<Unresolved>::_TimerInterface_Free;
	#endif
	#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
	#else
		tbl->_TimerInterface_Alloc = &Wrapper<Unresolved>::_TimerInterface_Alloc;
	#endif
	#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
	#else
		tbl->_TimerInterface_CancelAndWait = &Wrapper<Unresolved>::_TimerInterface_CancelAndWait;
	#endif
	#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
	#else
		tbl->_TimerInterface_Cancel = &Wrapper<Unresolved>::_TimerInterface_Cancel;
	#endif
	#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<maxon::ObservableRef<ObservableTimerStartedDelegate>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_TimerInterface_ObservableTimerStarted = &Wrapper<Unresolved>::_TimerInterface_ObservableTimerStarted;
	#else
		tbl->_TimerInterface_ObservableTimerStarted = &Wrapper<Unresolved>::_TimerInterface_ObservableTimerStarted;
	#endif
	#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<maxon::ObservableRef<ObservableTimerFinishedDelegate>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_TimerInterface_ObservableTimerFinished = &Wrapper<Unresolved>::_TimerInterface_ObservableTimerFinished;
	#else
		tbl->_TimerInterface_ObservableTimerFinished = &Wrapper<Unresolved>::_TimerInterface_ObservableTimerFinished;
	#endif
	#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<maxon::ObservableRef<ObservableTimerOverloadDelegate>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_TimerInterface_ObservableTimerOverload = &Wrapper<Unresolved>::_TimerInterface_ObservableTimerOverload;
	#else
		tbl->_TimerInterface_ObservableTimerOverload = &Wrapper<Unresolved>::_TimerInterface_ObservableTimerOverload;
	#endif
/// @cond IGNORE

	#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
	#else
		tbl->_TimerInterface_PrivateDisableAllTimers = &Wrapper<Unresolved>::_TimerInterface_PrivateDisableAllTimers;
	#endif
	#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<void>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_TimerInterface_Start = &Wrapper<Unresolved>::_TimerInterface_Start;
	#else
		tbl->_TimerInterface_Start = &Wrapper<Unresolved>::_TimerInterface_Start;
	#endif
/// @endcond

	#ifdef PRIVATE_MAXON_ASSEMBLE_UNRESOLVED
		return assembler(&_interface, (maxon::Char*) tbl, _returnTypes, SIZEOF(_returnTypes) - 1);
	#else
		return true;
	#endif
	}
	MAXON_INTERFACE_REGISTER(TimerInterface, "net.maxon.interface.timer", nullptr);
	template <typename DUMMY> maxon::Int TimerInterface::PrivateInstantiateNullValueHelper()
	{
		return 0
		;
	}
}
#endif
static maxon::details::ForceEvaluation s_forceEval_timer(0
	| maxon::TimerInterface::PrivateInstantiateNullValueHelper<maxon::Int>()
);
