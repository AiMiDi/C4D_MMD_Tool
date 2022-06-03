#if 1
namespace maxon
{
#if defined(PRIVATE_MAXON_REGISTRATION_FRAMEWORK) && !defined(MAXON_REGISTRATION_EXCLUDE_REFLECTION_NONVIRTUAL)
	static maxon::Result<void> RegisterReflection_UrlInterface(maxon::reflection::Class* cls, maxon::reflection::FunctionRegistrationCallback callback)
	{
		maxon::reflection::FunctionInfo functions[] =
		{
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(UrlInterface::MTable::_instance.UrlInterface_Free)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "object\0", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(UrlInterface::MTable::_instance.UrlInterface_Alloc)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "allocLocation\0", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(UrlInterface::MTable::_instance.UrlInterface_Alloc_1)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "allocLocation\0object\0", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(UrlInterface::MTable::_instance.UrlInterface_GetScheme)>::type>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, "", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(UrlInterface::MTable::_instance.UrlInterface_SetScheme)>::type>(nullptr, maxon::reflection::Member::KIND::INSTANCE_FUNCTION, "scheme\0", 1LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(UrlInterface::MTable::_instance.UrlInterface_Append)>::type>(nullptr, maxon::reflection::Member::KIND::INSTANCE_FUNCTION, "name\0", 1LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(UrlInterface::MTable::_instance.UrlInterface_Append_1)>::type>(nullptr, maxon::reflection::Member::KIND::INSTANCE_FUNCTION, "relativeUrl\0", 1LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(UrlInterface::MTable::_instance.UrlInterface_RemoveName)>::type>(nullptr, maxon::reflection::Member::KIND::INSTANCE_FUNCTION, "", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(UrlInterface::MTable::_instance.UrlInterface_GetEmbeddedUrl)>::type>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, "", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(UrlInterface::MTable::_instance.UrlInterface_SetEmbeddedUrl)>::type>(nullptr, maxon::reflection::Member::KIND::INSTANCE_FUNCTION, "url\0", 1LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(UrlInterface::MTable::_instance.UrlInterface_GetName)>::type>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, "", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(UrlInterface::MTable::_instance.UrlInterface_SetName)>::type>(nullptr, maxon::reflection::Member::KIND::INSTANCE_FUNCTION, "name\0", 1LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(UrlInterface::MTable::_instance.UrlInterface_GetDirectory)>::type>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, "", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(UrlInterface::MTable::_instance.UrlInterface_SetPath)>::type>(nullptr, maxon::reflection::Member::KIND::INSTANCE_FUNCTION, "path\0", 1LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(UrlInterface::MTable::_instance.UrlInterface_GetPath)>::type>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, "", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(UrlInterface::MTable::_instance.UrlInterface_SetSystemPath)>::type>(nullptr, maxon::reflection::Member::KIND::INSTANCE_FUNCTION, "path\0", 1LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(UrlInterface::MTable::_instance.UrlInterface_GetSystemPath)>::type>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, "", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(UrlInterface::MTable::_instance.UrlInterface_SetUrl)>::type>(nullptr, maxon::reflection::Member::KIND::INSTANCE_FUNCTION, "urlString\0enableDefaultFallbackScheme\0", 5LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(UrlInterface::MTable::_instance.UrlInterface_GetUrl)>::type>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, "", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(UrlInterface::MTable::_instance.UrlInterface_SetAuthority)>::type>(nullptr, maxon::reflection::Member::KIND::INSTANCE_FUNCTION, "authority\0", 1LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(UrlInterface::MTable::_instance.UrlInterface_SetAuthority_1)>::type>(nullptr, maxon::reflection::Member::KIND::INSTANCE_FUNCTION, "authority\0", 1LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(UrlInterface::MTable::_instance.UrlInterface_GetAuthority)>::type>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, "", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(UrlInterface::MTable::_instance.UrlInterface_GetComponents)>::type>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, "parts\0", 2LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(UrlInterface::MTable::_instance.UrlInterface_GetRelativeUrl)>::type>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, "basePath\0", 1LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(UrlInterface::MTable::_instance.UrlInterface_GetSuffix)>::type>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, "", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(UrlInterface::MTable::_instance.UrlInterface_CheckSuffix)>::type>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, "suffix\0", 1LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(UrlInterface::MTable::_instance.UrlInterface_SetSuffix)>::type>(nullptr, maxon::reflection::Member::KIND::INSTANCE_FUNCTION, "suffix\0", 1LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(UrlInterface::MTable::_instance.UrlInterface_ClearSuffix)>::type>(nullptr, maxon::reflection::Member::KIND::INSTANCE_FUNCTION, "", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(UrlInterface::MTable::_instance.UrlInterface_IsEmpty)>::type>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, "", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(UrlInterface::MTable::_instance.UrlInterface_Compare)>::type>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, "name\0mode\0", 5LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(UrlInterface::MTable::_instance.UrlInterface_GetData)>::type>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, "key\0", 1LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(UrlInterface::MTable::_instance.UrlInterface_SetData)>::type>(nullptr, maxon::reflection::Member::KIND::INSTANCE_FUNCTION, "key\0data\0persistent\0", 21LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(UrlInterface::MTable::_instance.UrlInterface_SetData_1)>::type>(nullptr, maxon::reflection::Member::KIND::INSTANCE_FUNCTION, "key\0data\0persistent\0", 21LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(UrlInterface::MTable::_instance.UrlInterface_EraseData)>::type>(nullptr, maxon::reflection::Member::KIND::INSTANCE_FUNCTION, "key\0persistent\0", 5LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(UrlInterface::MTable::_instance.UrlInterface_ToString)>::type>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, "formatStatement\0", 1LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(UrlInterface::MTable::_instance.UrlInterface_ConvertToUiName)>::type>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, "flags\0", 1LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(UrlInterface::MTable::_instance.UrlInterface_ConvertFromUiName)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "str\0", 1LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(UrlInterface::MTable::_instance.UrlInterface_DescribeIO)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "stream\0", 1LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(UrlInterface::MTable::_instance.UrlInterface_ConvertToUiNameWithRepository)>::type>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, "flags\0lookupRepository\0", 5LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(UrlInterface::MTable::_instance.UrlInterface_ConvertFromUiNameWithRepository)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "str\0lookupRepository\0", 5LL, nullptr),
		};
		return callback(cls, reinterpret_cast<const maxon::EntityReference*>(&UrlInterface::_interface), maxon::ToBlock(functions));
	}
#endif
#ifndef MAXON_REGISTRATION_EXCLUDE_REFLECTION_NONVIRTUAL
	static maxon::reflection::ContainerInfo g_reflection_UrlInterface("net.maxon.interface.url", nullptr, &RegisterReflection_UrlInterface, &PRIVATE_MAXON_MODULE);
#endif
#ifdef URLSCHEME_UNC_ENABLED
#endif
#ifndef MAXON_REGISTRATION_EXCLUDE_INTERFACES
	PRIVATE_MAXON_REGISTRY_DEFINE(UrlIoShowInOSRegistry);
#endif
}
#endif
