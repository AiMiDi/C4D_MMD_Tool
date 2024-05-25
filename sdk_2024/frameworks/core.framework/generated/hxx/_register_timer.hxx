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
		"ObservableTimerStarted@55b5d0c692fb6651\0" // maxon::ObservableRef<ObservableTimerStartedDelegate> ObservableTimerStarted(Bool create) const
		"ObservableTimerFinished@572b13a4cbe4b0e0\0" // maxon::ObservableRef<ObservableTimerFinishedDelegate> ObservableTimerFinished(Bool create) const
		"ObservableTimerOverload@e92061e235e3ba4\0" // maxon::ObservableRef<ObservableTimerOverloadDelegate> ObservableTimerOverload(Bool create) const
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
		maxon::ObservableRef<ObservableTimerStartedDelegate> ObservableTimerStarted(Bool create) const { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ((const TimerInterface*) this)->ObservableTimerStarted(create); return maxon::ObservableRef<ObservableTimerStartedDelegate>::DefaultValue();}
		maxon::ObservableRef<ObservableTimerFinishedDelegate> ObservableTimerFinished(Bool create) const { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ((const TimerInterface*) this)->ObservableTimerFinished(create); return maxon::ObservableRef<ObservableTimerFinishedDelegate>::DefaultValue();}
		maxon::ObservableRef<ObservableTimerOverloadDelegate> ObservableTimerOverload(Bool create) const { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ((const TimerInterface*) this)->ObservableTimerOverload(create); return maxon::ObservableRef<ObservableTimerOverloadDelegate>::DefaultValue();}
/// @cond IGNORE

		static void PrivateDisableAllTimers() { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return TimerInterface::PrivateDisableAllTimers(); return maxon::PrivateLogNullptrError();}
		Result<void> Start(Float64 interval, Float64 startOffset, Float64 tolerance, const JobInterfacePOD& pod, JobQueueInterface* queue) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return ((TimerInterface*) this)->Start(interval, startOffset, tolerance, pod, queue); return HXXRET1(UNRESOLVED);}
/// @endcond

	};
	MAXON_WARNING_POP
#ifdef PRIVATE_MAXON_ASSEMBLE_UNRESOLVED
	const maxon::UNRESOLVED_RETURN_TYPE TimerInterface::MTable::_returnTypes[] = 
	{
		maxon::UNRESOLVED_RETURN_TYPE::VOID_ZERO_FREE_FUNCTION,
		maxon::details::UnresolvedReturnType<TimerInterface*>::value,
		maxon::details::UnresolvedReturnType<void>::value | maxon::UNRESOLVED_RETURN_TYPE::MEMBER_FUNCTION_FLAG,
		maxon::details::UnresolvedReturnType<void>::value | maxon::UNRESOLVED_RETURN_TYPE::MEMBER_FUNCTION_FLAG,
		maxon::details::UnresolvedReturnType<maxon::ObservableRef<ObservableTimerStartedDelegate>>::value | maxon::UNRESOLVED_RETURN_TYPE::MEMBER_FUNCTION_FLAG,
		maxon::details::UnresolvedReturnType<maxon::ObservableRef<ObservableTimerFinishedDelegate>>::value | maxon::UNRESOLVED_RETURN_TYPE::MEMBER_FUNCTION_FLAG,
		maxon::details::UnresolvedReturnType<maxon::ObservableRef<ObservableTimerOverloadDelegate>>::value | maxon::UNRESOLVED_RETURN_TYPE::MEMBER_FUNCTION_FLAG,
/// @cond IGNORE

		maxon::details::UnresolvedReturnType<void>::value,
		maxon::details::UnresolvedReturnType<Result<void>>::value | maxon::UNRESOLVED_RETURN_TYPE::MEMBER_FUNCTION_FLAG,
/// @endcond

		maxon::UNRESOLVED_RETURN_TYPE::OTHER
	};
#endif
	maxon::Bool TimerInterface::MTable::InitUnresolved(maxon::NonvirtualInterfaceReference::UnresolvedAssembler assembler, MTable* tbl)
	{
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->TimerInterface_Free = PRIVATE_MAXON_MF_CAST(decltype(TimerInterface_Free), &Hxx2::Wrapper<Hxx2::Unresolved>::TimerInterface_Free);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->TimerInterface_Alloc = PRIVATE_MAXON_MF_CAST(decltype(TimerInterface_Alloc), &Hxx2::Wrapper<Hxx2::Unresolved>::TimerInterface_Alloc);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->TimerInterface_CancelAndWait = PRIVATE_MAXON_MF_CAST(decltype(TimerInterface_CancelAndWait), &Hxx2::Wrapper<Hxx2::Unresolved>::TimerInterface_CancelAndWait);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->TimerInterface_Cancel = PRIVATE_MAXON_MF_CAST(decltype(TimerInterface_Cancel), &Hxx2::Wrapper<Hxx2::Unresolved>::TimerInterface_Cancel);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if constexpr (maxon::details::UnresolvedReturnType<maxon::ObservableRef<ObservableTimerStartedDelegate>>::value == maxon::UNRESOLVED_RETURN_TYPE::OTHER) tbl->TimerInterface_ObservableTimerStarted = PRIVATE_MAXON_MF_CAST(decltype(TimerInterface_ObservableTimerStarted), &Hxx2::Wrapper<Hxx2::Unresolved>::TimerInterface_ObservableTimerStarted);
		#else
		tbl->TimerInterface_ObservableTimerStarted = PRIVATE_MAXON_MF_CAST(decltype(TimerInterface_ObservableTimerStarted), &Hxx2::Wrapper<Hxx2::Unresolved>::TimerInterface_ObservableTimerStarted);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if constexpr (maxon::details::UnresolvedReturnType<maxon::ObservableRef<ObservableTimerFinishedDelegate>>::value == maxon::UNRESOLVED_RETURN_TYPE::OTHER) tbl->TimerInterface_ObservableTimerFinished = PRIVATE_MAXON_MF_CAST(decltype(TimerInterface_ObservableTimerFinished), &Hxx2::Wrapper<Hxx2::Unresolved>::TimerInterface_ObservableTimerFinished);
		#else
		tbl->TimerInterface_ObservableTimerFinished = PRIVATE_MAXON_MF_CAST(decltype(TimerInterface_ObservableTimerFinished), &Hxx2::Wrapper<Hxx2::Unresolved>::TimerInterface_ObservableTimerFinished);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if constexpr (maxon::details::UnresolvedReturnType<maxon::ObservableRef<ObservableTimerOverloadDelegate>>::value == maxon::UNRESOLVED_RETURN_TYPE::OTHER) tbl->TimerInterface_ObservableTimerOverload = PRIVATE_MAXON_MF_CAST(decltype(TimerInterface_ObservableTimerOverload), &Hxx2::Wrapper<Hxx2::Unresolved>::TimerInterface_ObservableTimerOverload);
		#else
		tbl->TimerInterface_ObservableTimerOverload = PRIVATE_MAXON_MF_CAST(decltype(TimerInterface_ObservableTimerOverload), &Hxx2::Wrapper<Hxx2::Unresolved>::TimerInterface_ObservableTimerOverload);
		#endif
/// @cond IGNORE

		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->TimerInterface_PrivateDisableAllTimers = PRIVATE_MAXON_MF_CAST(decltype(TimerInterface_PrivateDisableAllTimers), &Hxx2::Wrapper<Hxx2::Unresolved>::TimerInterface_PrivateDisableAllTimers);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if constexpr (maxon::details::UnresolvedReturnType<Result<void>>::value == maxon::UNRESOLVED_RETURN_TYPE::OTHER) tbl->TimerInterface_Start = PRIVATE_MAXON_MF_CAST(decltype(TimerInterface_Start), &Hxx2::Wrapper<Hxx2::Unresolved>::TimerInterface_Start);
		#else
		tbl->TimerInterface_Start = PRIVATE_MAXON_MF_CAST(decltype(TimerInterface_Start), &Hxx2::Wrapper<Hxx2::Unresolved>::TimerInterface_Start);
		#endif
/// @endcond

	#ifdef PRIVATE_MAXON_ASSEMBLE_UNRESOLVED
		return assembler(&_interface, (const void**) tbl, _returnTypes, SIZEOF(MTable) / SIZEOF(void*));
	#else
		return true;
	#endif
	}
	MAXON_INTERFACE_REGISTER(TimerInterface, "net.maxon.interface.timer", nullptr, maxon::EntityBase::FLAGS::NONE);
}
#endif
