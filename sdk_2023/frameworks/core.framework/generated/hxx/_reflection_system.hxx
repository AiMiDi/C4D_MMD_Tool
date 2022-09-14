#if 1
namespace maxon
{
#if defined(PRIVATE_MAXON_REGISTRATION_FRAMEWORK) && !defined(MAXON_REGISTRATION_EXCLUDE_REFLECTION_NONVIRTUAL)
	static maxon::Result<void> RegisterReflection_System(maxon::reflection::Class* cls, maxon::reflection::FunctionRegistrationCallback callback)
	{
		maxon::reflection::FunctionInfo functions[] =
		{
			maxon::reflection::GetFunctionInfo<decltype(System::MTable::_instance.System__ConsoleOutput)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "s\0loc\0flags\0", 21LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(System::MTable::_instance.System_GetConsoleOutputType)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(System::MTable::_instance.System_Alloc)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "size\0location\0", 5LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(System::MTable::_instance.System_AllocClear)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "size\0location\0", 5LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(System::MTable::_instance.System_Realloc)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "data\0size\0location\0", 21LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(System::MTable::_instance.System_Free)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "data\0", 1LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(System::MTable::_instance.System_GetAllocSize)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "data\0", 1LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(System::MTable::_instance.System_MemoryDiagnostics)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "mode\0totalAllocation\0freePhysicalMemoryEstimate\0", 41LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(System::MTable::_instance.System_MemoryAddObserver)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "mode\0observer\0", 5LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(System::MTable::_instance.System_SetMemoryAllocationThreshold)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "warnMemoryAllocationThreshold\0", 1LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(System::MTable::_instance.System_GetCustomTimer)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(System::MTable::_instance.System_GetConfigurationCount)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(System::MTable::_instance.System_GetConfiguration)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "index\0config\0", 1LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(System::MTable::_instance.System_ConfigurationRegister)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "config\0", 1LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(System::MTable::_instance.System_GetCriticalLog)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "index\0count\0", 9LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(System::MTable::_instance.System_GetDefinitionCount)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "type\0", 1LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(System::MTable::_instance.System_GetVirtualInterfaceReference)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "idWithoutHash\0", 1LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(System::MTable::_instance.System_FindDefinition)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "type\0eid\0", 5LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(System::MTable::_instance.System_SetDebugErrorObserver)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "observer\0", 1LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(System::MTable::_instance.System_ResetDebugErrorObserver)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "observer\0", 1LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(System::MTable::_instance.System_SetCurrentError)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "error\0", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(System::MTable::_instance.System_SetCurrentError_1)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "error\0", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(System::MTable::_instance.System_GetLastError)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(System::MTable::_instance.System_SetDebugError)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "preallocated\0error\0", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(System::MTable::_instance.System_GetDebugError)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "preallocated\0", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(System::MTable::_instance.System_PrivateGetInternedId)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "value\0", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(System::MTable::_instance.System_PrivateFreeInternedId)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "ptr\0", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(System::MTable::_instance.System_GetBinaries)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(System::MTable::_instance.System_PrivateShowSynchronizedHashMapDiagnostics)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "size\0capacity\0signature\0", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(System::MTable::_instance.System_GetPreferencesPathSuffix)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(System::MTable::_instance.System_GetApplicationId)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(System::MTable::_instance.System_SetApplicationType)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "dna\0", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(System::MTable::_instance.System_PrivateInitExternalDependency)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "initSystemTable\0externalDependency\0", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(System::MTable::_instance.System_PrivateResetExternalDependency)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "safeShutdownMethods\0externalDependency\0", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(System::MTable::_instance.System_PrivateGetUniqueHashCode)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "ptr\0count\0", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(System::MTable::_instance.System_PrivateHasherInitialize)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "state\0", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(System::MTable::_instance.System_PrivateHasherCombine)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "state\0ptr\0count\0", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(System::MTable::_instance.System_PrivateHasherCombine_1)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "state\0hash\0", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(System::MTable::_instance.System_PrivateHasherFinialize)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "state\0", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(System::MTable::_instance.System_PrivateFreeWithDestructor)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "object\0destruct\0", 5LL, nullptr),
		};
		return callback(cls, reinterpret_cast<const maxon::EntityReference*>(&System::_interface), maxon::ToBlock(functions));
	}
#endif
#ifndef MAXON_REGISTRATION_EXCLUDE_REFLECTION_NONVIRTUAL
	static maxon::reflection::ContainerInfo g_reflection_System("net.maxon.interface.system", nullptr, &RegisterReflection_System, &PRIVATE_MAXON_MODULE);
#endif
}
#endif
