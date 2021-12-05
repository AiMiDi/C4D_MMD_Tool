#if 1
namespace maxon
{
#ifndef MAXON_REGISTRATION_EXCLUDE_REFLECTION_NONVIRTUAL
	static maxon::Result<void> RegisterReflection_UrlInterface(maxon::reflection::Class* cls, maxon::reflection::FunctionRegistrationCallback callback)
	{
		maxon::reflection::FunctionInfo functions[] =
		{
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(UrlInterface::MTable::_instance._UrlInterface_Free)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(UrlInterface::MTable::_instance._UrlInterface_Alloc)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(UrlInterface::MTable::_instance._UrlInterface_Alloc_1)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(UrlInterface::MTable::_instance._UrlInterface_GetScheme)>::type>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(UrlInterface::MTable::_instance._UrlInterface_SetScheme)>::type>(nullptr, maxon::reflection::Member::KIND::INSTANCE_FUNCTION, 4LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(UrlInterface::MTable::_instance._UrlInterface_Append)>::type>(nullptr, maxon::reflection::Member::KIND::INSTANCE_FUNCTION, 4LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(UrlInterface::MTable::_instance._UrlInterface_Append_1)>::type>(nullptr, maxon::reflection::Member::KIND::INSTANCE_FUNCTION, 4LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(UrlInterface::MTable::_instance._UrlInterface_RemoveName)>::type>(nullptr, maxon::reflection::Member::KIND::INSTANCE_FUNCTION, 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(UrlInterface::MTable::_instance._UrlInterface_GetEmbeddedUrl)>::type>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(UrlInterface::MTable::_instance._UrlInterface_SetEmbeddedUrl)>::type>(nullptr, maxon::reflection::Member::KIND::INSTANCE_FUNCTION, 4LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(UrlInterface::MTable::_instance._UrlInterface_GetName)>::type>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(UrlInterface::MTable::_instance._UrlInterface_SetName)>::type>(nullptr, maxon::reflection::Member::KIND::INSTANCE_FUNCTION, 4LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(UrlInterface::MTable::_instance._UrlInterface_GetDirectory)>::type>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(UrlInterface::MTable::_instance._UrlInterface_SetPath)>::type>(nullptr, maxon::reflection::Member::KIND::INSTANCE_FUNCTION, 4LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(UrlInterface::MTable::_instance._UrlInterface_GetPath)>::type>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(UrlInterface::MTable::_instance._UrlInterface_SetSystemPath)>::type>(nullptr, maxon::reflection::Member::KIND::INSTANCE_FUNCTION, 4LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(UrlInterface::MTable::_instance._UrlInterface_GetSystemPath)>::type>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(UrlInterface::MTable::_instance._UrlInterface_SetUrl)>::type>(nullptr, maxon::reflection::Member::KIND::INSTANCE_FUNCTION, 20LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(UrlInterface::MTable::_instance._UrlInterface_GetUrl)>::type>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(UrlInterface::MTable::_instance._UrlInterface_SetAuthority)>::type>(nullptr, maxon::reflection::Member::KIND::INSTANCE_FUNCTION, 4LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(UrlInterface::MTable::_instance._UrlInterface_SetAuthority_1)>::type>(nullptr, maxon::reflection::Member::KIND::INSTANCE_FUNCTION, 4LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(UrlInterface::MTable::_instance._UrlInterface_GetAuthority)>::type>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(UrlInterface::MTable::_instance._UrlInterface_GetComponents)>::type>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, 8LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(UrlInterface::MTable::_instance._UrlInterface_GetRelativeUrl)>::type>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, 4LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(UrlInterface::MTable::_instance._UrlInterface_GetSuffix)>::type>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(UrlInterface::MTable::_instance._UrlInterface_CheckSuffix)>::type>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, 4LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(UrlInterface::MTable::_instance._UrlInterface_SetSuffix)>::type>(nullptr, maxon::reflection::Member::KIND::INSTANCE_FUNCTION, 4LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(UrlInterface::MTable::_instance._UrlInterface_ClearSuffix)>::type>(nullptr, maxon::reflection::Member::KIND::INSTANCE_FUNCTION, 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(UrlInterface::MTable::_instance._UrlInterface_IsEmpty)>::type>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(UrlInterface::MTable::_instance._UrlInterface_Compare)>::type>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, 20LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(UrlInterface::MTable::_instance._UrlInterface_GetData)>::type>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, 4LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(UrlInterface::MTable::_instance._UrlInterface_SetData)>::type>(nullptr, maxon::reflection::Member::KIND::INSTANCE_FUNCTION, 84LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(UrlInterface::MTable::_instance._UrlInterface_SetData_1)>::type>(nullptr, maxon::reflection::Member::KIND::INSTANCE_FUNCTION, 84LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(UrlInterface::MTable::_instance._UrlInterface_ToString)>::type>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, 4LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(UrlInterface::MTable::_instance._UrlInterface_DescribeIO)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, 1LL, nullptr),
		};
		return callback(cls, reinterpret_cast<const maxon::EntityReference*>(&UrlInterface::_interface), maxon::ToBlock(functions));
	}
	static maxon::reflection::ContainerInfo g_reflection_UrlInterface("net.maxon.interface.url", nullptr, &RegisterReflection_UrlInterface, &PRIVATE_MAXON_MODULE);
#endif
#ifdef URLSCHEME_UNC_ENABLED
#endif
}
#endif
