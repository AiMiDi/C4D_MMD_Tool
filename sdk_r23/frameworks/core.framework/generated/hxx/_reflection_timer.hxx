#if 1
namespace maxon
{
/// @cond IGNORE

/// @endcond

#if defined(PRIVATE_MAXON_REGISTRATION_FRAMEWORK) && !defined(MAXON_REGISTRATION_EXCLUDE_REFLECTION_NONVIRTUAL)
	static maxon::Result<void> RegisterReflection_TimerInterface(maxon::reflection::Class* cls, maxon::reflection::FunctionRegistrationCallback callback)
	{
		maxon::reflection::FunctionInfo functions[] =
		{
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(TimerInterface::MTable::_instance._TimerInterface_Free)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "object\0", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(TimerInterface::MTable::_instance._TimerInterface_Alloc)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "allocLocation\0", 1LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(TimerInterface::MTable::_instance._TimerInterface_CancelAndWait)>::type>(nullptr, maxon::reflection::Member::KIND::INSTANCE_FUNCTION, "", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(TimerInterface::MTable::_instance._TimerInterface_Cancel)>::type>(nullptr, maxon::reflection::Member::KIND::INSTANCE_FUNCTION, "", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(TimerInterface::MTable::_instance._TimerInterface_ObservableTimerStarted)>::type>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, "", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(TimerInterface::MTable::_instance._TimerInterface_ObservableTimerFinished)>::type>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, "", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(TimerInterface::MTable::_instance._TimerInterface_ObservableTimerOverload)>::type>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, "", 0LL, nullptr),
/// @cond IGNORE

			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(TimerInterface::MTable::_instance._TimerInterface_PrivateDisableAllTimers)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(TimerInterface::MTable::_instance._TimerInterface_Start)>::type>(nullptr, maxon::reflection::Member::KIND::INSTANCE_FUNCTION, "interval\0startOffset\0tolerance\0pod\0queue\0", 0LL, nullptr),
/// @endcond

		};
		return callback(cls, reinterpret_cast<const maxon::EntityReference*>(&TimerInterface::_interface), maxon::ToBlock(functions));
	}
#endif
#ifndef MAXON_REGISTRATION_EXCLUDE_REFLECTION_NONVIRTUAL
	static maxon::reflection::ContainerInfo g_reflection_TimerInterface("net.maxon.interface.timer", nullptr, &RegisterReflection_TimerInterface, &PRIVATE_MAXON_MODULE);
#endif
}
#endif
