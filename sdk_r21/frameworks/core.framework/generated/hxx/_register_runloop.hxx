#if 1
namespace maxon
{
	const maxon::Char* const RunLoop::MTable::_ids = 
		"EnterLoop@0499ab9fb052ee8b\0" // Result<void> EnterLoop()
		"ExitLoop@cfa940f4\0" // void ExitLoop()
		"TriggerMainThreadQueue@cfa940f4\0" // void TriggerMainThreadQueue()
		"AddTimer@bc02ffe3c3a28010\0" // Result<Timer*> AddTimer(TimeValue interval, TimeValue delay, TimeValue tolerance, TimerCallback callback, void* self)
		"RemoveTimer@2ae9235d8097872f\0" // void RemoveTimer(Timer* timer)
		"GetLinuxDefaultDisplayAndScreen@a3f119511c2c009f\0" // void GetLinuxDefaultDisplayAndScreen(void*& display, int& screen)
		"ObservableExitLoop@3630f5d6897e81a5\0" // maxon::ObservableRef<ObservableExitLoopDelegate> ObservableExitLoop()
		"ObservableActivationChange@3e7fd9c7deecf5a1\0" // maxon::ObservableRef<ObservableActivationChangeDelegate> ObservableActivationChange()
		"ObservableFilterSystemMessage@480253946227dfeb\0" // maxon::ObservableRef<ObservableRunLoopMessageDelegate> ObservableRunLoopMessage()
		"PrivateGetMainThreadQueueTrigger@30b8a602134\0" // void** PrivateGetMainThreadQueueTrigger()
		"PrivateSetWaitInterval@908a7df734dec46e\0" // void PrivateSetWaitInterval(TimeValue waitInterval)
		"PrivateSetDefaultDisplayAndScreen@908db41afdcde739\0" // void PrivateSetDefaultDisplayAndScreen(void* display, int screen)
	"";
	MAXON_WARNING_PUSH
	MAXON_WARNING_DISABLE_DEPRECATED
	class RunLoop::Hxx2::Unresolved : public RunLoop
	{
	public:
		static const Unresolved* Get(const RunLoop* o) { return (const Unresolved*) o; }
		static Unresolved* Get(RunLoop* o) { return (Unresolved*) o; }
		static Result<void> EnterLoop() { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return RunLoop::EnterLoop(); return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::UNRESOLVED);}
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
