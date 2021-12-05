#if 1
namespace maxon
{
/// @endcond

#if defined(PRIVATE_MAXON_REGISTRATION_FRAMEWORK) && !defined(MAXON_REGISTRATION_EXCLUDE_REFLECTION_NONVIRTUAL)
	static maxon::Result<void> RegisterReflection_System(maxon::reflection::Class* cls, maxon::reflection::FunctionRegistrationCallback callback)
	{
		maxon::reflection::FunctionInfo functions[] =
		{
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(System::MTable::_instance._System__ConsoleOutput)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "s\0loc\0", 1LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(System::MTable::_instance._System_GetConsoleOutputType)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(System::MTable::_instance._System_Alloc)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "size\0location\0", 5LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(System::MTable::_instance._System_AllocClear)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "size\0location\0", 5LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(System::MTable::_instance._System_Realloc)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "data\0size\0location\0", 21LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(System::MTable::_instance._System_Free)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "data\0", 1LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(System::MTable::_instance._System_GetAllocSize)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "data\0", 1LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(System::MTable::_instance._System_MemoryDiagnostics)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "mode\0totalAllocation\0freePhysicalMemoryEstimate\0", 41LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(System::MTable::_instance._System_MemoryAddObserver)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "mode\0observer\0", 5LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(System::MTable::_instance._System_SetMemoryAllocationThreshold)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "warnMemoryAllocationThreshold\0", 1LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(System::MTable::_instance._System_GetCustomTimer)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(System::MTable::_instance._System_GetConfigurationCount)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(System::MTable::_instance._System_GetConfiguration)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "index\0config\0", 1LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(System::MTable::_instance._System_ConfigurationRegister)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "config\0", 1LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(System::MTable::_instance._System_GetCriticalLog)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "index\0count\0", 9LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(System::MTable::_instance._System_GetDefinitionCount)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "type\0", 1LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(System::MTable::_instance._System_GetVirtualInterfaceReference)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "idWithoutHash\0", 1LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(System::MTable::_instance._System_FindDefinition)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "type\0eid\0", 5LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(System::MTable::_instance._System_SetDebugErrorObserver)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "observer\0", 1LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(System::MTable::_instance._System_ResetDebugErrorObserver)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "observer\0", 1LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(System::MTable::_instance._System_SetCurrentError)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "error\0", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(System::MTable::_instance._System_SetCurrentError_1)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "error\0", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(System::MTable::_instance._System_GetLastError)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(System::MTable::_instance._System_SetDebugError)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "preallocated\0error\0", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(System::MTable::_instance._System_GetDebugError)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "preallocated\0", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(System::MTable::_instance._System_PrivateGetInternedId)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "value\0", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(System::MTable::_instance._System_PrivateFreeInternedId)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "ptr\0", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(System::MTable::_instance._System_GetBinaries)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(System::MTable::_instance._System_PrivateShowSynchronizedHashMapDiagnostics)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "size\0capacity\0signature\0", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(System::MTable::_instance._System_GetPreferencesPathSuffix)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(System::MTable::_instance._System_GetApplicationId)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(System::MTable::_instance._System_SetApplicationType)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "dna\0", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(System::MTable::_instance._System_FreeWithDestructorI)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "object\0destruct\0", 5LL, nullptr),
/// @endcond

		};
		return callback(cls, reinterpret_cast<const maxon::EntityReference*>(&System::_interface), maxon::ToBlock(functions));
	}
#endif
#ifndef MAXON_REGISTRATION_EXCLUDE_REFLECTION_NONVIRTUAL
	static maxon::reflection::ContainerInfo g_reflection_System("net.maxon.interface.system", nullptr, &RegisterReflection_System, &PRIVATE_MAXON_MODULE);
#endif
}
#endif
