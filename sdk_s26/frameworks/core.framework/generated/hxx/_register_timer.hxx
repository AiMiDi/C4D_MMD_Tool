#if 1
namespace maxon
{
/// @cond IGNORE

/// @endcond

	const maxon::Char* const TimerInterface::MTable::_ids = 
		"Free@72ac02298b10e17e\0" // void Free(const TimerInterface* object)
		"Alloc@6a40610be2a72bf7\0" // TimerInterface* Alloc(const maxon::SourceLocation& allocLocation)
		"CancelAndWait@780cdac8f1a33934\0" // void CancelAndWait()
		"Cancel@780cdac8f1a33934\0" // void Cancel()
		"ObservableTimerStarted@6a31b38c97408d1\0" // maxon::ObservableRef<ObservableTimerStartedDelegate> ObservableTimerStarted() const
		"ObservableTimerFinished@53b738c5d20aa8a4\0" // maxon::ObservableRef<ObservableTimerFinishedDelegate> ObservableTimerFinished() const
		"ObservableTimerOverload@56dec2659f66e340\0" // maxon::ObservableRef<ObservableTimerOverloadDelegate> ObservableTimerOverload() const
/// @cond IGNORE

		"PrivateDisableAllTimers@c52e0d8d7af2df35\0" // void PrivateDisableAllTimers()
		"Start@879cd8aa6c1d53aa\0" // Result<void> Start(Float64 interval, Float64 startOffset, Float64 tolerance, const JobInterfacePOD& pod, JobQueueInterface* queue)
/// @endcond

	"";
	MAXON_WARNING_PUSH
	MAXON_WARNING_DISABLE_DEPRECATED
	class TimerInterface::Hxx2::Unresolved : public TimerInterface
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
	MAXON_WARNING_POP
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
		tbl->TimerInterface_Free = &Hxx2::Wrapper<Hxx2::Unresolved>::TimerInterface_Free;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->TimerInterface_Alloc = &Hxx2::Wrapper<Hxx2::Unresolved>::TimerInterface_Alloc;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->TimerInterface_CancelAndWait = &Hxx2::Wrapper<Hxx2::Unresolved>::TimerInterface_CancelAndWait;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->TimerInterface_Cancel = &Hxx2::Wrapper<Hxx2::Unresolved>::TimerInterface_Cancel;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<maxon::ObservableRef<ObservableTimerStartedDelegate>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->TimerInterface_ObservableTimerStarted = &Hxx2::Wrapper<Hxx2::Unresolved>::TimerInterface_ObservableTimerStarted;
		#else
		tbl->TimerInterface_ObservableTimerStarted = &Hxx2::Wrapper<Hxx2::Unresolved>::TimerInterface_ObservableTimerStarted;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<maxon::ObservableRef<ObservableTimerFinishedDelegate>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->TimerInterface_ObservableTimerFinished = &Hxx2::Wrapper<Hxx2::Unresolved>::TimerInterface_ObservableTimerFinished;
		#else
		tbl->TimerInterface_ObservableTimerFinished = &Hxx2::Wrapper<Hxx2::Unresolved>::TimerInterface_ObservableTimerFinished;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<maxon::ObservableRef<ObservableTimerOverloadDelegate>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->TimerInterface_ObservableTimerOverload = &Hxx2::Wrapper<Hxx2::Unresolved>::TimerInterface_ObservableTimerOverload;
		#else
		tbl->TimerInterface_ObservableTimerOverload = &Hxx2::Wrapper<Hxx2::Unresolved>::TimerInterface_ObservableTimerOverload;
		#endif
/// @cond IGNORE

		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->TimerInterface_PrivateDisableAllTimers = &Hxx2::Wrapper<Hxx2::Unresolved>::TimerInterface_PrivateDisableAllTimers;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<void>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->TimerInterface_Start = &Hxx2::Wrapper<Hxx2::Unresolved>::TimerInterface_Start;
		#else
		tbl->TimerInterface_Start = &Hxx2::Wrapper<Hxx2::Unresolved>::TimerInterface_Start;
		#endif
/// @endcond

	#ifdef PRIVATE_MAXON_ASSEMBLE_UNRESOLVED
		return assembler(&_interface, (maxon::Char*) tbl, _returnTypes, SIZEOF(MTable) / SIZEOF(void*));
	#else
		return true;
	#endif
	}
	MAXON_INTERFACE_REGISTER(TimerInterface, "net.maxon.interface.timer", nullptr);
}
#endif
