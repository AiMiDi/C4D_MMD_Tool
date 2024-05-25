#if 1
namespace maxon
{
	const maxon::Char* const RunLoop::MTable::_ids = 
		"EnterLoop@ecd6102785cf4eea\0" // Result<void> EnterLoop(Bool isInternalLoop)
		"EnterLoop@cabe5983adfac1f2\0" // Result<void> EnterLoop(Bool isInternalLoop, void* osSpecific)
		"ExitLoop@c52e0d8d7af2df35\0" // void ExitLoop()
		"TriggerMainThreadQueue@c52e0d8d7af2df35\0" // void TriggerMainThreadQueue()
		"AddTimer@318db05d4bc8d427\0" // Result<Timer*> AddTimer(TimeValue interval, TimeValue delay, TimeValue tolerance, TimerCallback callback, void* self)
		"RemoveTimer@900e3424b4333cba\0" // void RemoveTimer(Timer* timer)
		"GetLinuxDefaultDisplayAndScreen@b71efc4b3b555ad8\0" // void GetLinuxDefaultDisplayAndScreen(void*& display, int& screen)
		"ObservableExitLoop@7c6b459a99412f12\0" // maxon::ObservableRef<ObservableExitLoopDelegate> ObservableExitLoop(Bool create)
		"ObservableActivationChange@fe9ba29b9e9f3ae8\0" // maxon::ObservableRef<ObservableActivationChangeDelegate> ObservableActivationChange(Bool create)
		"ObservableRunLoopMessage@2b0bec52788ca5c2\0" // maxon::ObservableRef<ObservableRunLoopMessageDelegate> ObservableRunLoopMessage(Bool create)
		"PrivateGetMainThreadQueueTrigger@ead2003396c1aab5\0" // void** PrivateGetMainThreadQueueTrigger()
		"PrivateSetWaitInterval@e127c6957280255b\0" // void PrivateSetWaitInterval(TimeValue waitInterval)
		"PrivateSetDefaultDisplayAndScreen@b0687b299ad2142e\0" // void PrivateSetDefaultDisplayAndScreen(void* display, int screen)
	"";
	MAXON_WARNING_PUSH
	MAXON_WARNING_DISABLE_DEPRECATED
	class RunLoop::Hxx2::Unresolved : public RunLoop
	{
	public:
		static const Unresolved* Get(const RunLoop* o) { return (const Unresolved*) o; }
		static Unresolved* Get(RunLoop* o) { return (Unresolved*) o; }
		static Result<void> EnterLoop(Bool isInternalLoop) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return RunLoop::EnterLoop(isInternalLoop); return HXXRET1(UNRESOLVED);}
		static Result<void> EnterLoop(Bool isInternalLoop, void* osSpecific) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return RunLoop::EnterLoop(isInternalLoop, osSpecific); return HXXRET1(UNRESOLVED);}
		static void ExitLoop() { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return RunLoop::ExitLoop(); return maxon::PrivateLogNullptrError();}
		static void TriggerMainThreadQueue() { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return RunLoop::TriggerMainThreadQueue(); return maxon::PrivateLogNullptrError();}
		static Result<Timer*> AddTimer(TimeValue interval, TimeValue delay, TimeValue tolerance, TimerCallback callback, void* self) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return RunLoop::AddTimer(std::forward<TimeValue>(interval), std::forward<TimeValue>(delay), std::forward<TimeValue>(tolerance), std::forward<TimerCallback>(callback), self); return HXXRET1(UNRESOLVED);}
		static void RemoveTimer(Timer* timer) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return RunLoop::RemoveTimer(timer); return maxon::PrivateLogNullptrError();}
		static void GetLinuxDefaultDisplayAndScreen(void*& display, int& screen) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return RunLoop::GetLinuxDefaultDisplayAndScreen(display, screen); return maxon::PrivateLogNullptrError();}
		static maxon::ObservableRef<ObservableExitLoopDelegate> ObservableExitLoop(Bool create) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return RunLoop::ObservableExitLoop(create); return maxon::ObservableRef<ObservableExitLoopDelegate>::DefaultValue();}
		static maxon::ObservableRef<ObservableActivationChangeDelegate> ObservableActivationChange(Bool create) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return RunLoop::ObservableActivationChange(create); return maxon::ObservableRef<ObservableActivationChangeDelegate>::DefaultValue();}
		static maxon::ObservableRef<ObservableRunLoopMessageDelegate> ObservableRunLoopMessage(Bool create) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return RunLoop::ObservableRunLoopMessage(create); return maxon::ObservableRef<ObservableRunLoopMessageDelegate>::DefaultValue();}
		static void** PrivateGetMainThreadQueueTrigger() { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return RunLoop::PrivateGetMainThreadQueueTrigger(); return nullptr;}
		static void PrivateSetWaitInterval(TimeValue waitInterval) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return RunLoop::PrivateSetWaitInterval(std::forward<TimeValue>(waitInterval)); return maxon::PrivateLogNullptrError();}
		static void PrivateSetDefaultDisplayAndScreen(void* display, int screen) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return RunLoop::PrivateSetDefaultDisplayAndScreen(display, screen); return maxon::PrivateLogNullptrError();}
	};
	MAXON_WARNING_POP
#ifdef PRIVATE_MAXON_ASSEMBLE_UNRESOLVED
	const maxon::UNRESOLVED_RETURN_TYPE RunLoop::MTable::_returnTypes[] = 
	{
		maxon::details::UnresolvedReturnType<Result<void>>::value,
		maxon::details::UnresolvedReturnType<Result<void>>::value,
		maxon::details::UnresolvedReturnType<void>::value,
		maxon::details::UnresolvedReturnType<void>::value,
		maxon::details::UnresolvedReturnType<Result<Timer*>>::value,
		maxon::details::UnresolvedReturnType<void>::value,
		maxon::details::UnresolvedReturnType<void>::value,
		maxon::details::UnresolvedReturnType<maxon::ObservableRef<ObservableExitLoopDelegate>>::value,
		maxon::details::UnresolvedReturnType<maxon::ObservableRef<ObservableActivationChangeDelegate>>::value,
		maxon::details::UnresolvedReturnType<maxon::ObservableRef<ObservableRunLoopMessageDelegate>>::value,
		maxon::details::UnresolvedReturnType<void**>::value,
		maxon::details::UnresolvedReturnType<void>::value,
		maxon::details::UnresolvedReturnType<void>::value,
		maxon::UNRESOLVED_RETURN_TYPE::OTHER
	};
#endif
	maxon::Bool RunLoop::MTable::InitUnresolved(maxon::NonvirtualInterfaceReference::UnresolvedAssembler assembler, MTable* tbl)
	{
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if constexpr (maxon::details::UnresolvedReturnType<Result<void>>::value == maxon::UNRESOLVED_RETURN_TYPE::OTHER) tbl->RunLoop_EnterLoop = PRIVATE_MAXON_MF_CAST(decltype(RunLoop_EnterLoop), &Hxx2::Wrapper<Hxx2::Unresolved>::RunLoop_EnterLoop);
		#else
		tbl->RunLoop_EnterLoop = PRIVATE_MAXON_MF_CAST(decltype(RunLoop_EnterLoop), &Hxx2::Wrapper<Hxx2::Unresolved>::RunLoop_EnterLoop);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if constexpr (maxon::details::UnresolvedReturnType<Result<void>>::value == maxon::UNRESOLVED_RETURN_TYPE::OTHER) tbl->RunLoop_EnterLoop_1 = PRIVATE_MAXON_MF_CAST(decltype(RunLoop_EnterLoop_1), &Hxx2::Wrapper<Hxx2::Unresolved>::RunLoop_EnterLoop_1);
		#else
		tbl->RunLoop_EnterLoop_1 = PRIVATE_MAXON_MF_CAST(decltype(RunLoop_EnterLoop_1), &Hxx2::Wrapper<Hxx2::Unresolved>::RunLoop_EnterLoop_1);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->RunLoop_ExitLoop = PRIVATE_MAXON_MF_CAST(decltype(RunLoop_ExitLoop), &Hxx2::Wrapper<Hxx2::Unresolved>::RunLoop_ExitLoop);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->RunLoop_TriggerMainThreadQueue = PRIVATE_MAXON_MF_CAST(decltype(RunLoop_TriggerMainThreadQueue), &Hxx2::Wrapper<Hxx2::Unresolved>::RunLoop_TriggerMainThreadQueue);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if constexpr (maxon::details::UnresolvedReturnType<Result<Timer*>>::value == maxon::UNRESOLVED_RETURN_TYPE::OTHER) tbl->RunLoop_AddTimer = PRIVATE_MAXON_MF_CAST(decltype(RunLoop_AddTimer), &Hxx2::Wrapper<Hxx2::Unresolved>::RunLoop_AddTimer);
		#else
		tbl->RunLoop_AddTimer = PRIVATE_MAXON_MF_CAST(decltype(RunLoop_AddTimer), &Hxx2::Wrapper<Hxx2::Unresolved>::RunLoop_AddTimer);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->RunLoop_RemoveTimer = PRIVATE_MAXON_MF_CAST(decltype(RunLoop_RemoveTimer), &Hxx2::Wrapper<Hxx2::Unresolved>::RunLoop_RemoveTimer);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->RunLoop_GetLinuxDefaultDisplayAndScreen = PRIVATE_MAXON_MF_CAST(decltype(RunLoop_GetLinuxDefaultDisplayAndScreen), &Hxx2::Wrapper<Hxx2::Unresolved>::RunLoop_GetLinuxDefaultDisplayAndScreen);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if constexpr (maxon::details::UnresolvedReturnType<maxon::ObservableRef<ObservableExitLoopDelegate>>::value == maxon::UNRESOLVED_RETURN_TYPE::OTHER) tbl->RunLoop_ObservableExitLoop = PRIVATE_MAXON_MF_CAST(decltype(RunLoop_ObservableExitLoop), &Hxx2::Wrapper<Hxx2::Unresolved>::RunLoop_ObservableExitLoop);
		#else
		tbl->RunLoop_ObservableExitLoop = PRIVATE_MAXON_MF_CAST(decltype(RunLoop_ObservableExitLoop), &Hxx2::Wrapper<Hxx2::Unresolved>::RunLoop_ObservableExitLoop);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if constexpr (maxon::details::UnresolvedReturnType<maxon::ObservableRef<ObservableActivationChangeDelegate>>::value == maxon::UNRESOLVED_RETURN_TYPE::OTHER) tbl->RunLoop_ObservableActivationChange = PRIVATE_MAXON_MF_CAST(decltype(RunLoop_ObservableActivationChange), &Hxx2::Wrapper<Hxx2::Unresolved>::RunLoop_ObservableActivationChange);
		#else
		tbl->RunLoop_ObservableActivationChange = PRIVATE_MAXON_MF_CAST(decltype(RunLoop_ObservableActivationChange), &Hxx2::Wrapper<Hxx2::Unresolved>::RunLoop_ObservableActivationChange);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if constexpr (maxon::details::UnresolvedReturnType<maxon::ObservableRef<ObservableRunLoopMessageDelegate>>::value == maxon::UNRESOLVED_RETURN_TYPE::OTHER) tbl->RunLoop_ObservableRunLoopMessage = PRIVATE_MAXON_MF_CAST(decltype(RunLoop_ObservableRunLoopMessage), &Hxx2::Wrapper<Hxx2::Unresolved>::RunLoop_ObservableRunLoopMessage);
		#else
		tbl->RunLoop_ObservableRunLoopMessage = PRIVATE_MAXON_MF_CAST(decltype(RunLoop_ObservableRunLoopMessage), &Hxx2::Wrapper<Hxx2::Unresolved>::RunLoop_ObservableRunLoopMessage);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->RunLoop_PrivateGetMainThreadQueueTrigger = PRIVATE_MAXON_MF_CAST(decltype(RunLoop_PrivateGetMainThreadQueueTrigger), &Hxx2::Wrapper<Hxx2::Unresolved>::RunLoop_PrivateGetMainThreadQueueTrigger);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->RunLoop_PrivateSetWaitInterval = PRIVATE_MAXON_MF_CAST(decltype(RunLoop_PrivateSetWaitInterval), &Hxx2::Wrapper<Hxx2::Unresolved>::RunLoop_PrivateSetWaitInterval);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->RunLoop_PrivateSetDefaultDisplayAndScreen = PRIVATE_MAXON_MF_CAST(decltype(RunLoop_PrivateSetDefaultDisplayAndScreen), &Hxx2::Wrapper<Hxx2::Unresolved>::RunLoop_PrivateSetDefaultDisplayAndScreen);
		#endif
	#ifdef PRIVATE_MAXON_ASSEMBLE_UNRESOLVED
		return assembler(&_interface, (const void**) tbl, _returnTypes, SIZEOF(MTable) / SIZEOF(void*));
	#else
		return true;
	#endif
	}
	MAXON_INTERFACE_REGISTER(RunLoop, "net.maxon.interface.runloop", nullptr, maxon::EntityBase::FLAGS::NONE);
}
#endif
