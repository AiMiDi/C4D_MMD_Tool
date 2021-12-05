#if 1
namespace maxon
{
	const maxon::Char* const RunLoop::MTable::_ids = 
		"EnterLoop@ecd6102785cf4eea\0" // Result<void> EnterLoop(Bool isInternalLoop)
		"ExitLoop@c52e0d8d7af2df35\0" // void ExitLoop()
		"TriggerMainThreadQueue@c52e0d8d7af2df35\0" // void TriggerMainThreadQueue()
		"AddTimer@318db05d4bc8d427\0" // Result<Timer*> AddTimer(TimeValue interval, TimeValue delay, TimeValue tolerance, TimerCallback callback, void* self)
		"RemoveTimer@900e3424b4333cba\0" // void RemoveTimer(Timer* timer)
		"GetLinuxDefaultDisplayAndScreen@b71efc4b3b555ad8\0" // void GetLinuxDefaultDisplayAndScreen(void*& display, int& screen)
		"ObservableExitLoop@7db87a328f62307a\0" // maxon::ObservableRef<ObservableExitLoopDelegate> ObservableExitLoop()
		"ObservableActivationChange@124167b1d9ca86d4\0" // maxon::ObservableRef<ObservableActivationChangeDelegate> ObservableActivationChange()
		"ObservableRunLoopMessage@b3a9899990d673ea\0" // maxon::ObservableRef<ObservableRunLoopMessageDelegate> ObservableRunLoopMessage()
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
		static Result<void> EnterLoop(Bool isInternalLoop) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return RunLoop::EnterLoop(isInternalLoop); return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::UNRESOLVED);}
		static void ExitLoop() { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return RunLoop::ExitLoop(); return maxon::PrivateLogNullptrError();}
		static void TriggerMainThreadQueue() { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return RunLoop::TriggerMainThreadQueue(); return maxon::PrivateLogNullptrError();}
		static Result<Timer*> AddTimer(TimeValue interval, TimeValue delay, TimeValue tolerance, TimerCallback callback, void* self) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return RunLoop::AddTimer(std::forward<TimeValue>(interval), std::forward<TimeValue>(delay), std::forward<TimeValue>(tolerance), std::forward<TimerCallback>(callback), self); return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::UNRESOLVED);}
		static void RemoveTimer(Timer* timer) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return RunLoop::RemoveTimer(timer); return maxon::PrivateLogNullptrError();}
		static void GetLinuxDefaultDisplayAndScreen(void*& display, int& screen) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return RunLoop::GetLinuxDefaultDisplayAndScreen(display, screen); return maxon::PrivateLogNullptrError();}
		static maxon::ObservableRef<ObservableExitLoopDelegate> ObservableExitLoop() { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return RunLoop::ObservableExitLoop(); return maxon::ObservableRef<ObservableExitLoopDelegate>::NullValue();}
		static maxon::ObservableRef<ObservableActivationChangeDelegate> ObservableActivationChange() { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return RunLoop::ObservableActivationChange(); return maxon::ObservableRef<ObservableActivationChangeDelegate>::NullValue();}
		static maxon::ObservableRef<ObservableRunLoopMessageDelegate> ObservableRunLoopMessage() { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return RunLoop::ObservableRunLoopMessage(); return maxon::ObservableRef<ObservableRunLoopMessageDelegate>::NullValue();}
		static void** PrivateGetMainThreadQueueTrigger() { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return RunLoop::PrivateGetMainThreadQueueTrigger(); return nullptr;}
		static void PrivateSetWaitInterval(TimeValue waitInterval) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return RunLoop::PrivateSetWaitInterval(std::forward<TimeValue>(waitInterval)); return maxon::PrivateLogNullptrError();}
		static void PrivateSetDefaultDisplayAndScreen(void* display, int screen) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return RunLoop::PrivateSetDefaultDisplayAndScreen(display, screen); return maxon::PrivateLogNullptrError();}
	};
	MAXON_WARNING_POP
#ifdef PRIVATE_MAXON_ASSEMBLE_UNRESOLVED
	const maxon::NULL_RETURN_TYPE RunLoop::MTable::_returnTypes[] = 
	{
		maxon::details::NullReturnType<Result<void>>::value,
		maxon::details::NullReturnType<void>::value,
		maxon::details::NullReturnType<void>::value,
		maxon::details::NullReturnType<Result<Timer*>>::value,
		maxon::details::NullReturnType<void>::value,
		maxon::details::NullReturnType<void>::value,
		maxon::details::NullReturnType<maxon::ObservableRef<ObservableExitLoopDelegate>>::value,
		maxon::details::NullReturnType<maxon::ObservableRef<ObservableActivationChangeDelegate>>::value,
		maxon::details::NullReturnType<maxon::ObservableRef<ObservableRunLoopMessageDelegate>>::value,
		maxon::details::NullReturnType<void**>::value,
		maxon::details::NullReturnType<void>::value,
		maxon::details::NullReturnType<void>::value,
		maxon::NULL_RETURN_TYPE::OTHER
	};
#endif
	maxon::Bool RunLoop::MTable::InitUnresolved(maxon::NonvirtualInterfaceReference::UnresolvedAssembler assembler, MTable* tbl)
	{
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<void>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_RunLoop_EnterLoop = &Hxx2::Wrapper<Hxx2::Unresolved>::_RunLoop_EnterLoop;
		#else
		tbl->_RunLoop_EnterLoop = &Hxx2::Wrapper<Hxx2::Unresolved>::_RunLoop_EnterLoop;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->_RunLoop_ExitLoop = &Hxx2::Wrapper<Hxx2::Unresolved>::_RunLoop_ExitLoop;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->_RunLoop_TriggerMainThreadQueue = &Hxx2::Wrapper<Hxx2::Unresolved>::_RunLoop_TriggerMainThreadQueue;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<Timer*>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_RunLoop_AddTimer = &Hxx2::Wrapper<Hxx2::Unresolved>::_RunLoop_AddTimer;
		#else
		tbl->_RunLoop_AddTimer = &Hxx2::Wrapper<Hxx2::Unresolved>::_RunLoop_AddTimer;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->_RunLoop_RemoveTimer = &Hxx2::Wrapper<Hxx2::Unresolved>::_RunLoop_RemoveTimer;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->_RunLoop_GetLinuxDefaultDisplayAndScreen = &Hxx2::Wrapper<Hxx2::Unresolved>::_RunLoop_GetLinuxDefaultDisplayAndScreen;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<maxon::ObservableRef<ObservableExitLoopDelegate>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_RunLoop_ObservableExitLoop = &Hxx2::Wrapper<Hxx2::Unresolved>::_RunLoop_ObservableExitLoop;
		#else
		tbl->_RunLoop_ObservableExitLoop = &Hxx2::Wrapper<Hxx2::Unresolved>::_RunLoop_ObservableExitLoop;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<maxon::ObservableRef<ObservableActivationChangeDelegate>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_RunLoop_ObservableActivationChange = &Hxx2::Wrapper<Hxx2::Unresolved>::_RunLoop_ObservableActivationChange;
		#else
		tbl->_RunLoop_ObservableActivationChange = &Hxx2::Wrapper<Hxx2::Unresolved>::_RunLoop_ObservableActivationChange;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<maxon::ObservableRef<ObservableRunLoopMessageDelegate>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_RunLoop_ObservableRunLoopMessage = &Hxx2::Wrapper<Hxx2::Unresolved>::_RunLoop_ObservableRunLoopMessage;
		#else
		tbl->_RunLoop_ObservableRunLoopMessage = &Hxx2::Wrapper<Hxx2::Unresolved>::_RunLoop_ObservableRunLoopMessage;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->_RunLoop_PrivateGetMainThreadQueueTrigger = &Hxx2::Wrapper<Hxx2::Unresolved>::_RunLoop_PrivateGetMainThreadQueueTrigger;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->_RunLoop_PrivateSetWaitInterval = &Hxx2::Wrapper<Hxx2::Unresolved>::_RunLoop_PrivateSetWaitInterval;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->_RunLoop_PrivateSetDefaultDisplayAndScreen = &Hxx2::Wrapper<Hxx2::Unresolved>::_RunLoop_PrivateSetDefaultDisplayAndScreen;
		#endif
	#ifdef PRIVATE_MAXON_ASSEMBLE_UNRESOLVED
		return assembler(&_interface, (maxon::Char*) tbl, _returnTypes, SIZEOF(MTable) / SIZEOF(void*));
	#else
		return true;
	#endif
	}
	MAXON_INTERFACE_REGISTER(RunLoop, "net.maxon.interface.runloop", nullptr);
}
#endif
