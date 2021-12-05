#if 1
namespace maxon
{
#ifndef MAXON_REGISTRATION_EXCLUDE_REFLECTION_NONVIRTUAL
	static maxon::Result<void> RegisterReflection_DllInterface(maxon::reflection::Class* cls, maxon::reflection::FunctionRegistrationCallback callback)
	{
		maxon::reflection::FunctionInfo functions[] =
		{
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(DllInterface::MTable::_instance._DllInterface_Free)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(DllInterface::MTable::_instance._DllInterface_LoadDll)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, 21LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(DllInterface::MTable::_instance._DllInterface_GetModule)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, 5LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(DllInterface::MTable::_instance._DllInterface_AddDllPath)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, 1LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(DllInterface::MTable::_instance._DllInterface_RemoveDllPath)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, 1LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(DllInterface::MTable::_instance._DllInterface_GetLoadedDlls)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(DllInterface::MTable::_instance._DllInterface_Unload)>::type>(nullptr, maxon::reflection::Member::KIND::INSTANCE_FUNCTION, 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(DllInterface::MTable::_instance._DllInterface_Release)>::type>(nullptr, maxon::reflection::Member::KIND::INSTANCE_FUNCTION, 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(DllInterface::MTable::_instance._DllInterface_FindSymbolPointer)>::type>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, 4LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(DllInterface::MTable::_instance._DllInterface_UpdateSymbolData)>::type>(nullptr, maxon::reflection::Member::KIND::INSTANCE_FUNCTION, 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(DllInterface::MTable::_instance._DllInterface_GetPath)>::type>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, 0LL, nullptr),
		};
		return callback(cls, reinterpret_cast<const maxon::EntityReference*>(&DllInterface::_interface), maxon::ToBlock(functions));
	}
	static maxon::reflection::ContainerInfo g_reflection_DllInterface("net.maxon.interface.dll", nullptr, &RegisterReflection_DllInterface, &PRIVATE_MAXON_MODULE);
#endif
}
#endif
