#if 1
namespace maxon
{
#if defined(PRIVATE_MAXON_REGISTRATION_FRAMEWORK) && !defined(MAXON_REGISTRATION_EXCLUDE_REFLECTION_NONVIRTUAL)
	static maxon::Result<void> RegisterReflection_System(maxon::reflection::Class* cls, maxon::reflection::FunctionRegistrationCallback callback)
	{
		maxon::reflection::FunctionInfo functions[] =
		{
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(System::MTable::_instance.System__ConsoleOutput)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "s\0loc\0", 5LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(System::MTable::_instance.System__ConsoleOutput_1)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "s\0loc\0flags\0", 21LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(System::MTable::_instance.System_GetConsoleOutputType)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(System::MTable::_instance.System_Alloc)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "size\0location\0", 5LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(System::MTable::_instance.System_AllocClear)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "size\0location\0", 5LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(System::MTable::_instance.System_Realloc)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "data\0size\0location\0", 21LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(System::MTable::_instance.System_Free)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "data\0", 1LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(System::MTable::_instance.System_GetAllocSize)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "data\0", 1LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(System::MTable::_instance.System_MemoryDiagnostics)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "mode\0totalAllocation\0freePhysicalMemoryEstimate\0", 41LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(System::MTable::_instance.System_MemoryAddObserver)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "mode\0observer\0", 5LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(System::MTable::_instance.System_SetMemoryAllocationThreshold)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "warnMemoryAllocationThreshold\0", 1LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(System::MTable::_instance.System_GetCustomTimer)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(System::MTable::_instance.System_GetConfigurationCount)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(System::MTable::_instance.System_GetConfiguration)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "index\0config\0", 1LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(System::MTable::_instance.System_ConfigurationRegister)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "config\0", 1LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(System::MTable::_instance.System_GetCriticalLog)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "index\0count\0", 9LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(System::MTable::_instance.System_GetDefinitionCount)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "type\0", 1LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(System::MTable::_instance.System_GetVirtualInterfaceReference)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "idWithoutHash\0", 1LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(System::MTable::_instance.System_FindDefinition)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "type\0eid\0", 5LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(System::MTable::_instance.System_SetDebugErrorObserver)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "observer\0", 1LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(System::MTable::_instance.System_ResetDebugErrorObserver)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "observer\0", 1LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(System::MTable::_instance.System_SetCurrentError)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "error\0", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(System::MTable::_instance.System_SetCurrentError_1)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "error\0", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(System::MTable::_instance.System_GetLastError)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(System::MTable::_instance.System_SetDebugError)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "preallocated\0error\0", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(System::MTable::_instance.System_GetDebugError)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "preallocated\0", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(System::MTable::_instance.System_PrivateGetInternedId)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "value\0", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(System::MTable::_instance.System_PrivateFreeInternedId)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "ptr\0", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(System::MTable::_instance.System_GetBinaries)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(System::MTable::_instance.System_PrivateShowSynchronizedHashMapDiagnostics)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "size\0capacity\0signature\0", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(System::MTable::_instance.System_GetPreferencesPathSuffix)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(System::MTable::_instance.System_GetApplicationId)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(System::MTable::_instance.System_SetApplicationType)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "dna\0", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(System::MTable::_instance.System_PrivateInitExternalDependency)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "initSystemTable\0externalDependency\0", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(System::MTable::_instance.System_PrivateResetExternalDependency)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "safeShutdownMethods\0externalDependency\0", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(System::MTable::_instance.System_FreeWithDestructorI)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "object\0destruct\0", 5LL, nullptr),
		};
		return callback(cls, reinterpret_cast<const maxon::EntityReference*>(&System::_interface), maxon::ToBlock(functions));
	}
#endif
#ifndef MAXON_REGISTRATION_EXCLUDE_REFLECTION_NONVIRTUAL
	static maxon::reflection::ContainerInfo g_reflection_System("net.maxon.interface.system", nullptr, &RegisterReflection_System, &PRIVATE_MAXON_MODULE);
#endif
}
#endif
