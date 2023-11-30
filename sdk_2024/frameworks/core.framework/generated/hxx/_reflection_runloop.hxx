#if 1
namespace maxon
{
#if defined(PRIVATE_MAXON_REGISTRATION_FRAMEWORK) && !defined(MAXON_REGISTRATION_EXCLUDE_REFLECTION_NONVIRTUAL)
	static maxon::Result<void> RegisterReflection_RunLoop(maxon::reflection::Class* cls, maxon::reflection::FunctionRegistrationCallback callback)
	{
		maxon::reflection::FunctionInfo functions[] =
		{
			maxon::reflection::GetFunctionInfo<decltype(RunLoop::MTable::_instance.RunLoop_EnterLoop)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "isInternalLoop\0", 1LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(RunLoop::MTable::_instance.RunLoop_EnterLoop_1)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "isInternalLoop\0osSpecific\0", 5LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(RunLoop::MTable::_instance.RunLoop_ExitLoop)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(RunLoop::MTable::_instance.RunLoop_TriggerMainThreadQueue)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(RunLoop::MTable::_instance.RunLoop_AddTimer)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "interval\0delay\0tolerance\0callback\0self\0", 341LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(RunLoop::MTable::_instance.RunLoop_RemoveTimer)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "timer\0", 1LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(RunLoop::MTable::_instance.RunLoop_GetLinuxDefaultDisplayAndScreen)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "display\0screen\0", 10LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(RunLoop::MTable::_instance.RunLoop_ObservableExitLoop)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "create\0", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(RunLoop::MTable::_instance.RunLoop_ObservableActivationChange)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "create\0", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(RunLoop::MTable::_instance.RunLoop_ObservableRunLoopMessage)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "create\0", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(RunLoop::MTable::_instance.RunLoop_PrivateGetMainThreadQueueTrigger)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(RunLoop::MTable::_instance.RunLoop_PrivateSetWaitInterval)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "waitInterval\0", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(RunLoop::MTable::_instance.RunLoop_PrivateSetDefaultDisplayAndScreen)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "display\0screen\0", 0LL, nullptr),
		};
		return callback(cls, reinterpret_cast<const maxon::EntityReference*>(&RunLoop::_interface), maxon::ToBlock(functions));
	}
#endif
#ifndef MAXON_REGISTRATION_EXCLUDE_REFLECTION_NONVIRTUAL
	static maxon::reflection::ContainerInfo g_reflection_RunLoop("net.maxon.interface.runloop", nullptr, &RegisterReflection_RunLoop, &PRIVATE_MAXON_MODULE);
#endif
}
#endif
