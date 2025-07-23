#if 1
namespace maxon
{
#if defined(PRIVATE_MAXON_REGISTRATION_FRAMEWORK) && !defined(MAXON_REGISTRATION_EXCLUDE_REFLECTION_NONVIRTUAL)
	static maxon::Result<void> RegisterReflection_ColorProfileLegacyProcessorInterface(maxon::reflection::Class* cls, maxon::reflection::FunctionRegistrationCallback callback)
	{
		maxon::reflection::FunctionInfo functions[] =
		{
			maxon::reflection::GetFunctionInfo<decltype(ColorProfileLegacyProcessorInterface::MTable::_instance.ColorProfileLegacyProcessorInterface_Free)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "object\0", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(ColorProfileLegacyProcessorInterface::MTable::_instance.ColorProfileLegacyProcessorInterface_Alloc)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "allocLocation\0", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(ColorProfileLegacyProcessorInterface::MTable::_instance.ColorProfileLegacyProcessorInterface_Alloc_1)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "allocLocation\0object\0", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(ColorProfileLegacyProcessorInterface::MTable::_instance.ColorProfileLegacyProcessorInterface_CreateHandler)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "srcProfile\0dstProfile\0flags\0optimization\0", 0LL, nullptr),
		};
		return callback(cls, reinterpret_cast<const maxon::EntityReference*>(&ColorProfileLegacyProcessorInterface::_interface), maxon::ToBlock(functions));
	}
#endif
#ifndef MAXON_REGISTRATION_EXCLUDE_REFLECTION_NONVIRTUAL
	static maxon::reflection::ContainerInfo g_reflection_ColorProfileLegacyProcessorInterface("net.maxon.image.interface.legacygpuprocessor", nullptr, &RegisterReflection_ColorProfileLegacyProcessorInterface, &PRIVATE_MAXON_MODULE);
#endif
}
#endif
