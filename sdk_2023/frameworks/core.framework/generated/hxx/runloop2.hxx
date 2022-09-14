
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
	PRIVATE_MAXON_SF_POINTER(RunLoop_EnterLoop, EnterLoop, MAXON_EXPAND_VA_ARGS, (Result<void>), Bool isInternalLoop);
	PRIVATE_MAXON_SF_POINTER(RunLoop_EnterLoop_1, EnterLoop, MAXON_EXPAND_VA_ARGS, (Result<void>), Bool isInternalLoop, void* osSpecific);
	PRIVATE_MAXON_SF_POINTER(RunLoop_ExitLoop, ExitLoop, MAXON_EXPAND_VA_ARGS, (void));
	PRIVATE_MAXON_SF_POINTER(RunLoop_TriggerMainThreadQueue, TriggerMainThreadQueue, MAXON_EXPAND_VA_ARGS, (void));
	PRIVATE_MAXON_SF_POINTER(RunLoop_AddTimer, AddTimer, MAXON_EXPAND_VA_ARGS, (Result<Timer*>), TimeValue interval, TimeValue delay, TimeValue tolerance, TimerCallback callback, void* self);
	PRIVATE_MAXON_SF_POINTER(RunLoop_RemoveTimer, RemoveTimer, MAXON_EXPAND_VA_ARGS, (void), Timer* timer);
	PRIVATE_MAXON_SF_POINTER(RunLoop_GetLinuxDefaultDisplayAndScreen, GetLinuxDefaultDisplayAndScreen, MAXON_EXPAND_VA_ARGS, (void), void*& display, int& screen);
	PRIVATE_MAXON_SF_POINTER(RunLoop_ObservableExitLoop, ObservableExitLoop, MAXON_EXPAND_VA_ARGS, (maxon::ObservableRef<ObservableExitLoopDelegate>));
	PRIVATE_MAXON_SF_POINTER(RunLoop_ObservableActivationChange, ObservableActivationChange, MAXON_EXPAND_VA_ARGS, (maxon::ObservableRef<ObservableActivationChangeDelegate>));
	PRIVATE_MAXON_SF_POINTER(RunLoop_ObservableRunLoopMessage, ObservableRunLoopMessage, MAXON_EXPAND_VA_ARGS, (maxon::ObservableRef<ObservableRunLoopMessageDelegate>));
	PRIVATE_MAXON_SF_POINTER(RunLoop_PrivateGetMainThreadQueueTrigger, PrivateGetMainThreadQueueTrigger, MAXON_EXPAND_VA_ARGS, (void**));
	PRIVATE_MAXON_SF_POINTER(RunLoop_PrivateSetWaitInterval, PrivateSetWaitInterval, MAXON_EXPAND_VA_ARGS, (void), TimeValue waitInterval);
	PRIVATE_MAXON_SF_POINTER(RunLoop_PrivateSetDefaultDisplayAndScreen, PrivateSetDefaultDisplayAndScreen, MAXON_EXPAND_VA_ARGS, (void), void* display, int screen);
	template <typename IMPL> void Init()
	{
		RunLoop_EnterLoop = RunLoop_EnterLoop_GetPtr<IMPL>(true);
		RunLoop_EnterLoop_1 = RunLoop_EnterLoop_1_GetPtr<IMPL>(true);
		RunLoop_ExitLoop = RunLoop_ExitLoop_GetPtr<IMPL>(true);
		RunLoop_TriggerMainThreadQueue = RunLoop_TriggerMainThreadQueue_GetPtr<IMPL>(true);
		RunLoop_AddTimer = RunLoop_AddTimer_GetPtr<IMPL>(true);
		RunLoop_RemoveTimer = RunLoop_RemoveTimer_GetPtr<IMPL>(true);
		RunLoop_GetLinuxDefaultDisplayAndScreen = RunLoop_GetLinuxDefaultDisplayAndScreen_GetPtr<IMPL>(true);
		RunLoop_ObservableExitLoop = RunLoop_ObservableExitLoop_GetPtr<IMPL>(true);
		RunLoop_ObservableActivationChange = RunLoop_ObservableActivationChange_GetPtr<IMPL>(true);
		RunLoop_ObservableRunLoopMessage = RunLoop_ObservableRunLoopMessage_GetPtr<IMPL>(true);
		RunLoop_PrivateGetMainThreadQueueTrigger = RunLoop_PrivateGetMainThreadQueueTrigger_GetPtr<IMPL>(true);
		RunLoop_PrivateSetWaitInterval = RunLoop_PrivateSetWaitInterval_GetPtr<IMPL>(true);
		RunLoop_PrivateSetDefaultDisplayAndScreen = RunLoop_PrivateSetDefaultDisplayAndScreen_GetPtr<IMPL>(true);
	}
};

struct RunLoop::Hxx2
{
	class Unresolved;
	template <typename C> class Wrapper
	{
	public:
		using Implementation = C;
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

