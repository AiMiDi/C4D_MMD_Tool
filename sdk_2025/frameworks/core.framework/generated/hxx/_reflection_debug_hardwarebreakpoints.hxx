#if 1
namespace maxon
{
#if defined(PRIVATE_MAXON_REGISTRATION_FRAMEWORK) && !defined(MAXON_REGISTRATION_EXCLUDE_REFLECTION_NONVIRTUAL)
	static maxon::Result<void> RegisterReflection_DebugHardwareBreakPointInterface(maxon::reflection::Class* cls, maxon::reflection::FunctionRegistrationCallback callback)
	{
		maxon::reflection::FunctionInfo functions[] =
		{
			maxon::reflection::GetFunctionInfo<decltype(DebugHardwareBreakPointInterface::MTable::_instance.DebugHardwareBreakPointInterface_Free)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "object\0", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(DebugHardwareBreakPointInterface::MTable::_instance.DebugHardwareBreakPointInterface_SetHardwareBreakpoint)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "type\0size\0watchAddress\0", 21LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(DebugHardwareBreakPointInterface::MTable::_instance.DebugHardwareBreakPointInterface_RemoveHardwareBreakpoint)>(nullptr, maxon::reflection::Member::KIND::INSTANCE_FUNCTION, "", 0LL, nullptr),
		};
		return callback(cls, reinterpret_cast<const maxon::EntityReference*>(&DebugHardwareBreakPointInterface::_interface), maxon::ToBlock(functions));
	}
#endif
#ifndef MAXON_REGISTRATION_EXCLUDE_REFLECTION_NONVIRTUAL
	static maxon::reflection::ContainerInfo g_reflection_DebugHardwareBreakPointInterface("net.maxon.interface.debughardwarebreakpoint", nullptr, &RegisterReflection_DebugHardwareBreakPointInterface, &PRIVATE_MAXON_MODULE);
#endif
}
#endif
