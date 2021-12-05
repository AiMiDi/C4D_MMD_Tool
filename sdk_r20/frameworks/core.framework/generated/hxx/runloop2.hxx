
#ifndef DOXYGEN

#ifdef MAXON_COMPILER_GCC
	#pragma GCC diagnostic push
	#pragma GCC diagnostic ignored "-Wmisleading-indentation"
#endif

#if 1

struct RunLoop::MTable
{
	static MTable _instance;
	static MTable _unresolvedInstance;
	static const maxon::Char* const _ids;
	static maxon::Bool InitUnresolved(maxon::NonvirtualInterfaceReference::UnresolvedAssembler assembler, MTable* tbl);
	static const maxon::NULL_RETURN_TYPE _returnTypes[];
	static const maxon::Bool HAS_NONSTATIC = false;
	Result<void> (*_RunLoop_EnterLoop) ();
	void (*_RunLoop_ExitLoop) ();
	void (*_RunLoop_TriggerMainThreadQueue) ();
	Result<Timer*> (*_RunLoop_AddTimer) (TimeValue interval, TimeValue delay, TimeValue tolerance, TimerCallback callback, void* self);
	void (*_RunLoop_RemoveTimer) (Timer* timer);
	void (*_RunLoop_GetLinuxDefaultDisplayAndScreen) (void*& display, int& screen);
	maxon::ObservableRef<ObservableExitLoopDelegate> (*_RunLoop_ObservableExitLoop) ();
	maxon::ObservableRef<ObservableFilterSystemMessageDelegate> (*_RunLoop_ObservableFilterSystemMessage) ();
	void** (*_RunLoop_PrivateGetMainThreadQueueTrigger) ();
	void (*_RunLoop_PrivateSetWaitInterval) (TimeValue waitInterval);
	void (*_RunLoop_PrivateSetDefaultDisplayAndScreen) (void* display, int screen);
	template <typename IMPL> static void Init(MTable* tbl)
	{
		tbl->_RunLoop_EnterLoop = &IMPL::_RunLoop_EnterLoop;
		tbl->_RunLoop_ExitLoop = &IMPL::_RunLoop_ExitLoop;
		tbl->_RunLoop_TriggerMainThreadQueue = &IMPL::_RunLoop_TriggerMainThreadQueue;
		tbl->_RunLoop_AddTimer = &IMPL::_RunLoop_AddTimer;
		tbl->_RunLoop_RemoveTimer = &IMPL::_RunLoop_RemoveTimer;
		tbl->_RunLoop_GetLinuxDefaultDisplayAndScreen = &IMPL::_RunLoop_GetLinuxDefaultDisplayAndScreen;
		tbl->_RunLoop_ObservableExitLoop = &IMPL::_RunLoop_ObservableExitLoop;
		tbl->_RunLoop_ObservableFilterSystemMessage = &IMPL::_RunLoop_ObservableFilterSystemMessage;
		tbl->_RunLoop_PrivateGetMainThreadQueueTrigger = &IMPL::_RunLoop_PrivateGetMainThreadQueueTrigger;
		tbl->_RunLoop_PrivateSetWaitInterval = &IMPL::_RunLoop_PrivateSetWaitInterval;
		tbl->_RunLoop_PrivateSetDefaultDisplayAndScreen = &IMPL::_RunLoop_PrivateSetDefaultDisplayAndScreen;
	}
};

template <typename C> class RunLoop::Wrapper
{
public:
	static Result<void> _RunLoop_EnterLoop() { return C::EnterLoop(); }
	static void _RunLoop_ExitLoop() { return C::ExitLoop(); }
	static void _RunLoop_TriggerMainThreadQueue() { return C::TriggerMainThreadQueue(); }
	static Result<Timer*> _RunLoop_AddTimer(TimeValue interval, TimeValue delay, TimeValue tolerance, TimerCallback callback, void* self) { return C::AddTimer(std::forward<TimeValue>(interval), std::forward<TimeValue>(delay), std::forward<TimeValue>(tolerance), std::forward<TimerCallback>(callback), self); }
	static void _RunLoop_RemoveTimer(Timer* timer) { return C::RemoveTimer(timer); }
	static void _RunLoop_GetLinuxDefaultDisplayAndScreen(void*& display, int& screen) { return C::GetLinuxDefaultDisplayAndScreen(display, screen); }
	static maxon::ObservableRef<ObservableExitLoopDelegate> _RunLoop_ObservableExitLoop() { return C::ObservableExitLoop(); }
	static maxon::ObservableRef<ObservableFilterSystemMessageDelegate> _RunLoop_ObservableFilterSystemMessage() { return C::ObservableFilterSystemMessage(); }
	static void** _RunLoop_PrivateGetMainThreadQueueTrigger() { return C::PrivateGetMainThreadQueueTrigger(); }
	static void _RunLoop_PrivateSetWaitInterval(TimeValue waitInterval) { return C::PrivateSetWaitInterval(std::forward<TimeValue>(waitInterval)); }
	static void _RunLoop_PrivateSetDefaultDisplayAndScreen(void* display, int screen) { return C::PrivateSetDefaultDisplayAndScreen(display, screen); }
};

MAXON_ATTRIBUTE_FORCE_INLINE auto RunLoop::EnterLoop() -> Result<void>
{
	return MTable::_instance._RunLoop_EnterLoop();
}
MAXON_ATTRIBUTE_FORCE_INLINE auto RunLoop::ExitLoop() -> void
{
	return MTable::_instance._RunLoop_ExitLoop();
}
MAXON_ATTRIBUTE_FORCE_INLINE auto RunLoop::TriggerMainThreadQueue() -> void
{
	return MTable::_instance._RunLoop_TriggerMainThreadQueue();
}
MAXON_ATTRIBUTE_FORCE_INLINE auto RunLoop::AddTimer(TimeValue interval, TimeValue delay, TimeValue tolerance, TimerCallback callback, void* self) -> Result<Timer*>
{
	return MTable::_instance._RunLoop_AddTimer(std::forward<TimeValue>(interval), std::forward<TimeValue>(delay), std::forward<TimeValue>(tolerance), std::forward<TimerCallback>(callback), self);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto RunLoop::RemoveTimer(Timer* timer) -> void
{
	return MTable::_instance._RunLoop_RemoveTimer(timer);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto RunLoop::GetLinuxDefaultDisplayAndScreen(void*& display, int& screen) -> void
{
	return MTable::_instance._RunLoop_GetLinuxDefaultDisplayAndScreen(display, screen);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto RunLoop::ObservableExitLoop() -> maxon::ObservableRef<ObservableExitLoopDelegate>
{
	return MTable::_instance._RunLoop_ObservableExitLoop();
}
MAXON_ATTRIBUTE_FORCE_INLINE auto RunLoop::ObservableFilterSystemMessage() -> maxon::ObservableRef<ObservableFilterSystemMessageDelegate>
{
	return MTable::_instance._RunLoop_ObservableFilterSystemMessage();
}
MAXON_ATTRIBUTE_FORCE_INLINE auto RunLoop::PrivateGetMainThreadQueueTrigger() -> void**
{
	return MTable::_instance._RunLoop_PrivateGetMainThreadQueueTrigger();
}
MAXON_ATTRIBUTE_FORCE_INLINE auto RunLoop::PrivateSetWaitInterval(TimeValue waitInterval) -> void
{
	return MTable::_instance._RunLoop_PrivateSetWaitInterval(std::forward<TimeValue>(waitInterval));
}
MAXON_ATTRIBUTE_FORCE_INLINE auto RunLoop::PrivateSetDefaultDisplayAndScreen(void* display, int screen) -> void
{
	return MTable::_instance._RunLoop_PrivateSetDefaultDisplayAndScreen(display, screen);
}

#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT)
static maxon::EntityUse s_ui_maxon_RunLoop(RunLoop::_interface.GetReference(), &maxon::g_translationUnit, "maxon/runloop.h", false);
#endif
#endif

#ifdef MAXON_COMPILER_GCC
	#pragma GCC diagnostic pop
#endif

#endif

