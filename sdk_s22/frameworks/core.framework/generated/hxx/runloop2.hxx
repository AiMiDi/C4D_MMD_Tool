
#ifndef DOXYGEN

#if defined MAXON_COMPILER_GCC
	#pragma GCC diagnostic push
	#if MAXON_COMPILER_GCC >= 600
		#pragma GCC diagnostic ignored "-Wmisleading-indentation"
	#endif
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
	maxon::ObservableRef<ObservableActivationChangeDelegate> (*_RunLoop_ObservableActivationChange) ();
	maxon::ObservableRef<ObservableRunLoopMessageDelegate> (*_RunLoop_ObservableRunLoopMessage) ();
	void** (*_RunLoop_PrivateGetMainThreadQueueTrigger) ();
	void (*_RunLoop_PrivateSetWaitInterval) (TimeValue waitInterval);
	void (*_RunLoop_PrivateSetDefaultDisplayAndScreen) (void* display, int screen);
	template <typename IMPL> void Init()
	{
		_RunLoop_EnterLoop = &IMPL::_RunLoop_EnterLoop;
		_RunLoop_ExitLoop = &IMPL::_RunLoop_ExitLoop;
		_RunLoop_TriggerMainThreadQueue = &IMPL::_RunLoop_TriggerMainThreadQueue;
		_RunLoop_AddTimer = &IMPL::_RunLoop_AddTimer;
		_RunLoop_RemoveTimer = &IMPL::_RunLoop_RemoveTimer;
		_RunLoop_GetLinuxDefaultDisplayAndScreen = &IMPL::_RunLoop_GetLinuxDefaultDisplayAndScreen;
		_RunLoop_ObservableExitLoop = &IMPL::_RunLoop_ObservableExitLoop;
		_RunLoop_ObservableActivationChange = &IMPL::_RunLoop_ObservableActivationChange;
		_RunLoop_ObservableRunLoopMessage = &IMPL::_RunLoop_ObservableRunLoopMessage;
		_RunLoop_PrivateGetMainThreadQueueTrigger = &IMPL::_RunLoop_PrivateGetMainThreadQueueTrigger;
		_RunLoop_PrivateSetWaitInterval = &IMPL::_RunLoop_PrivateSetWaitInterval;
		_RunLoop_PrivateSetDefaultDisplayAndScreen = &IMPL::_RunLoop_PrivateSetDefaultDisplayAndScreen;
	}
};

struct RunLoop::Hxx2
{
	class Unresolved;
	template <typename C> class Wrapper
	{
	public:
	static Result<void> _RunLoop_EnterLoop() { return C::EnterLoop(); }
	static void _RunLoop_ExitLoop() { return C::ExitLoop(); }
	static void _RunLoop_TriggerMainThreadQueue() { return C::TriggerMainThreadQueue(); }
	static Result<Timer*> _RunLoop_AddTimer(TimeValue interval, TimeValue delay, TimeValue tolerance, TimerCallback callback, void* self) { return C::AddTimer(std::forward<TimeValue>(interval), std::forward<TimeValue>(delay), std::forward<TimeValue>(tolerance), std::forward<TimerCallback>(callback), self); }
	static void _RunLoop_RemoveTimer(Timer* timer) { return C::RemoveTimer(timer); }
	static void _RunLoop_GetLinuxDefaultDisplayAndScreen(void*& display, int& screen) { return C::GetLinuxDefaultDisplayAndScreen(display, screen); }
	static maxon::ObservableRef<ObservableExitLoopDelegate> _RunLoop_ObservableExitLoop() { return C::ObservableExitLoop(); }
	static maxon::ObservableRef<ObservableActivationChangeDelegate> _RunLoop_ObservableActivationChange() { return C::ObservableActivationChange(); }
	static maxon::ObservableRef<ObservableRunLoopMessageDelegate> _RunLoop_ObservableRunLoopMessage() { return C::ObservableRunLoopMessage(); }
	static void** _RunLoop_PrivateGetMainThreadQueueTrigger() { return C::PrivateGetMainThreadQueueTrigger(); }
	static void _RunLoop_PrivateSetWaitInterval(TimeValue waitInterval) { return C::PrivateSetWaitInterval(std::forward<TimeValue>(waitInterval)); }
	static void _RunLoop_PrivateSetDefaultDisplayAndScreen(void* display, int screen) { return C::PrivateSetDefaultDisplayAndScreen(display, screen); }
	};

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
MAXON_ATTRIBUTE_FORCE_INLINE auto RunLoop::ObservableActivationChange() -> maxon::ObservableRef<ObservableActivationChangeDelegate>
{
	return MTable::_instance._RunLoop_ObservableActivationChange();
}
MAXON_ATTRIBUTE_FORCE_INLINE auto RunLoop::ObservableRunLoopMessage() -> maxon::ObservableRef<ObservableRunLoopMessageDelegate>
{
	return MTable::_instance._RunLoop_ObservableRunLoopMessage();
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
#ifdef MAXON_USE_REGISTER_FUNCTION
MAXON_STATIC_STORAGE(maxon::EntityUse, s_ui_maxon_RunLoop); \
MAXON_ATTRIBUTE_CONSTRUCTOR static void Register_s_ui_maxon_RunLoop() { new (s_ui_maxon_RunLoop) maxon::EntityUse(RunLoop::_interface.GetReference(), &maxon::g_translationUnit, "maxon/runloop.h", false); }
#else // !MAXON_USE_REGISTER_FUNCTION
static maxon::EntityUse s_ui_maxon_RunLoop(RunLoop::_interface.GetReference(), &maxon::g_translationUnit, "maxon/runloop.h", false);
#endif // MAXON_USE_REGISTER_FUNCTION
#endif
#endif

#ifdef MAXON_COMPILER_GCC
	#pragma GCC diagnostic pop
#endif

#endif

