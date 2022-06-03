
#ifndef DOXYGEN

#if defined MAXON_COMPILER_GCC
	#pragma GCC diagnostic push
	#if MAXON_COMPILER_GCC >= 600
		#pragma GCC diagnostic ignored "-Wmisleading-indentation"
	#endif
#endif

#if 1
constexpr const maxon::Char* RunLoop::PrivateGetCppName() { return nullptr; }

struct RunLoop::MTable
{
	static MTable _instance;
	static MTable _unresolvedInstance;
	static const maxon::Char* const _ids;
	static maxon::Bool InitUnresolved(maxon::NonvirtualInterfaceReference::UnresolvedAssembler assembler, MTable* tbl);
	static const maxon::NULL_RETURN_TYPE _returnTypes[];
	static const maxon::Bool HAS_NONSTATIC = false;
	Result<void> (*RunLoop_EnterLoop) (Bool isInternalLoop);
	Result<void> (*RunLoop_EnterLoop_1) (Bool isInternalLoop, void* osSpecific);
	void (*RunLoop_ExitLoop) ();
	void (*RunLoop_TriggerMainThreadQueue) ();
	Result<Timer*> (*RunLoop_AddTimer) (TimeValue interval, TimeValue delay, TimeValue tolerance, TimerCallback callback, void* self);
	void (*RunLoop_RemoveTimer) (Timer* timer);
	void (*RunLoop_GetLinuxDefaultDisplayAndScreen) (void*& display, int& screen);
	maxon::ObservableRef<ObservableExitLoopDelegate> (*RunLoop_ObservableExitLoop) ();
	maxon::ObservableRef<ObservableActivationChangeDelegate> (*RunLoop_ObservableActivationChange) ();
	maxon::ObservableRef<ObservableRunLoopMessageDelegate> (*RunLoop_ObservableRunLoopMessage) ();
	void** (*RunLoop_PrivateGetMainThreadQueueTrigger) ();
	void (*RunLoop_PrivateSetWaitInterval) (TimeValue waitInterval);
	void (*RunLoop_PrivateSetDefaultDisplayAndScreen) (void* display, int screen);
	template <typename IMPL> void Init()
	{
		RunLoop_EnterLoop = &IMPL::RunLoop_EnterLoop;
		RunLoop_EnterLoop_1 = &IMPL::RunLoop_EnterLoop_1;
		RunLoop_ExitLoop = &IMPL::RunLoop_ExitLoop;
		RunLoop_TriggerMainThreadQueue = &IMPL::RunLoop_TriggerMainThreadQueue;
		RunLoop_AddTimer = &IMPL::RunLoop_AddTimer;
		RunLoop_RemoveTimer = &IMPL::RunLoop_RemoveTimer;
		RunLoop_GetLinuxDefaultDisplayAndScreen = &IMPL::RunLoop_GetLinuxDefaultDisplayAndScreen;
		RunLoop_ObservableExitLoop = &IMPL::RunLoop_ObservableExitLoop;
		RunLoop_ObservableActivationChange = &IMPL::RunLoop_ObservableActivationChange;
		RunLoop_ObservableRunLoopMessage = &IMPL::RunLoop_ObservableRunLoopMessage;
		RunLoop_PrivateGetMainThreadQueueTrigger = &IMPL::RunLoop_PrivateGetMainThreadQueueTrigger;
		RunLoop_PrivateSetWaitInterval = &IMPL::RunLoop_PrivateSetWaitInterval;
		RunLoop_PrivateSetDefaultDisplayAndScreen = &IMPL::RunLoop_PrivateSetDefaultDisplayAndScreen;
	}
};

struct RunLoop::Hxx2
{
	class Unresolved;
	template <typename C> class Wrapper
	{
	public:
		static Result<void> RunLoop_EnterLoop(Bool isInternalLoop) { return C::EnterLoop(isInternalLoop); }
		static Result<void> RunLoop_EnterLoop_1(Bool isInternalLoop, void* osSpecific) { return C::EnterLoop(isInternalLoop, osSpecific); }
		static void RunLoop_ExitLoop() { return C::ExitLoop(); }
		static void RunLoop_TriggerMainThreadQueue() { return C::TriggerMainThreadQueue(); }
		static Result<Timer*> RunLoop_AddTimer(TimeValue interval, TimeValue delay, TimeValue tolerance, TimerCallback callback, void* self) { return C::AddTimer(std::forward<TimeValue>(interval), std::forward<TimeValue>(delay), std::forward<TimeValue>(tolerance), std::forward<TimerCallback>(callback), self); }
		static void RunLoop_RemoveTimer(Timer* timer) { return C::RemoveTimer(timer); }
		static void RunLoop_GetLinuxDefaultDisplayAndScreen(void*& display, int& screen) { return C::GetLinuxDefaultDisplayAndScreen(display, screen); }
		static maxon::ObservableRef<ObservableExitLoopDelegate> RunLoop_ObservableExitLoop() { return C::ObservableExitLoop(); }
		static maxon::ObservableRef<ObservableActivationChangeDelegate> RunLoop_ObservableActivationChange() { return C::ObservableActivationChange(); }
		static maxon::ObservableRef<ObservableRunLoopMessageDelegate> RunLoop_ObservableRunLoopMessage() { return C::ObservableRunLoopMessage(); }
		static void** RunLoop_PrivateGetMainThreadQueueTrigger() { return C::PrivateGetMainThreadQueueTrigger(); }
		static void RunLoop_PrivateSetWaitInterval(TimeValue waitInterval) { return C::PrivateSetWaitInterval(std::forward<TimeValue>(waitInterval)); }
		static void RunLoop_PrivateSetDefaultDisplayAndScreen(void* display, int screen) { return C::PrivateSetDefaultDisplayAndScreen(display, screen); }
	};

};
MAXON_ATTRIBUTE_FORCE_INLINE auto RunLoop::EnterLoop(Bool isInternalLoop) -> Result<void>
{
	return MTable::_instance.RunLoop_EnterLoop(isInternalLoop);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto RunLoop::EnterLoop(Bool isInternalLoop, void* osSpecific) -> Result<void>
{
	return MTable::_instance.RunLoop_EnterLoop_1(isInternalLoop, osSpecific);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto RunLoop::ExitLoop() -> void
{
	return MTable::_instance.RunLoop_ExitLoop();
}
MAXON_ATTRIBUTE_FORCE_INLINE auto RunLoop::TriggerMainThreadQueue() -> void
{
	return MTable::_instance.RunLoop_TriggerMainThreadQueue();
}
MAXON_ATTRIBUTE_FORCE_INLINE auto RunLoop::AddTimer(TimeValue interval, TimeValue delay, TimeValue tolerance, TimerCallback callback, void* self) -> Result<Timer*>
{
	return MTable::_instance.RunLoop_AddTimer(std::forward<TimeValue>(interval), std::forward<TimeValue>(delay), std::forward<TimeValue>(tolerance), std::forward<TimerCallback>(callback), self);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto RunLoop::RemoveTimer(Timer* timer) -> void
{
	return MTable::_instance.RunLoop_RemoveTimer(timer);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto RunLoop::GetLinuxDefaultDisplayAndScreen(void*& display, int& screen) -> void
{
	return MTable::_instance.RunLoop_GetLinuxDefaultDisplayAndScreen(display, screen);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto RunLoop::ObservableExitLoop() -> maxon::ObservableRef<ObservableExitLoopDelegate>
{
	return MTable::_instance.RunLoop_ObservableExitLoop();
}
MAXON_ATTRIBUTE_FORCE_INLINE auto RunLoop::ObservableActivationChange() -> maxon::ObservableRef<ObservableActivationChangeDelegate>
{
	return MTable::_instance.RunLoop_ObservableActivationChange();
}
MAXON_ATTRIBUTE_FORCE_INLINE auto RunLoop::ObservableRunLoopMessage() -> maxon::ObservableRef<ObservableRunLoopMessageDelegate>
{
	return MTable::_instance.RunLoop_ObservableRunLoopMessage();
}
MAXON_ATTRIBUTE_FORCE_INLINE auto RunLoop::PrivateGetMainThreadQueueTrigger() -> void**
{
	return MTable::_instance.RunLoop_PrivateGetMainThreadQueueTrigger();
}
MAXON_ATTRIBUTE_FORCE_INLINE auto RunLoop::PrivateSetWaitInterval(TimeValue waitInterval) -> void
{
	return MTable::_instance.RunLoop_PrivateSetWaitInterval(std::forward<TimeValue>(waitInterval));
}
MAXON_ATTRIBUTE_FORCE_INLINE auto RunLoop::PrivateSetDefaultDisplayAndScreen(void* display, int screen) -> void
{
	return MTable::_instance.RunLoop_PrivateSetDefaultDisplayAndScreen(display, screen);
}

#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT) && !defined(MAXON_DEPENDENCY_DISABLE_runloop)
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

