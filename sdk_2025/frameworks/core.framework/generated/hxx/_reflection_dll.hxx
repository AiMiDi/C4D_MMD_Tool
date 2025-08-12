#if 1
namespace maxon
{
#if defined(PRIVATE_MAXON_REGISTRATION_FRAMEWORK) && !defined(MAXON_REGISTRATION_EXCLUDE_REFLECTION_NONVIRTUAL)
	static maxon::Result<void> RegisterReflection_DllInterface(maxon::reflection::Class* cls, maxon::reflection::FunctionRegistrationCallback callback)
	{
		maxon::reflection::FunctionInfo functions[] =
		{
			maxon::reflection::GetFunctionInfo<decltype(DllInterface::MTable::_instance.DllInterface_Free)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "object\0", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(DllInterface::MTable::_instance.DllInterface_LoadDll)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "fileName\0registerDll\0requireCoreModule\0systemDependentFlags\0", 85LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(DllInterface::MTable::_instance.DllInterface_GetModule)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "handle\0processId\0", 5LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(DllInterface::MTable::_instance.DllInterface_AddDllPath)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "dllDirectory\0", 1LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(DllInterface::MTable::_instance.DllInterface_RemoveDllPath)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "dllDirectory\0", 1LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(DllInterface::MTable::_instance.DllInterface_GetLoadedDlls)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "dlls\0", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(DllInterface::MTable::_instance.DllInterface_Unload)>(nullptr, maxon::reflection::Member::KIND::INSTANCE_FUNCTION, "", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(DllInterface::MTable::_instance.DllInterface_Release)>(nullptr, maxon::reflection::Member::KIND::INSTANCE_FUNCTION, "", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(DllInterface::MTable::_instance.DllInterface_FindSymbolPointer)>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, "symbol\0", 1LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(DllInterface::MTable::_instance.DllInterface_GetBinary)>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, "", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(DllInterface::MTable::_instance.DllInterface_UpdateSymbolData)>(nullptr, maxon::reflection::Member::KIND::INSTANCE_FUNCTION, "", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(DllInterface::MTable::_instance.DllInterface_GetPath)>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, "", 0LL, nullptr),
		};
		return callback(cls, reinterpret_cast<const maxon::EntityReference*>(&DllInterface::_interface), maxon::ToBlock(functions));
	}
#endif
#ifndef MAXON_REGISTRATION_EXCLUDE_REFLECTION_NONVIRTUAL
	static maxon::reflection::ContainerInfo g_reflection_DllInterface("net.maxon.interface.dll", nullptr, &RegisterReflection_DllInterface, &PRIVATE_MAXON_MODULE);
#endif
}
#endif
