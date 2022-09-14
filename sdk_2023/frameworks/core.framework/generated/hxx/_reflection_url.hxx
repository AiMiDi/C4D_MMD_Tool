#if 1
namespace maxon
{
#if defined(PRIVATE_MAXON_REGISTRATION_FRAMEWORK) && !defined(MAXON_REGISTRATION_EXCLUDE_REFLECTION_NONVIRTUAL)
	static maxon::Result<void> RegisterReflection_UrlInterface(maxon::reflection::Class* cls, maxon::reflection::FunctionRegistrationCallback callback)
	{
		maxon::reflection::FunctionInfo functions[] =
		{
			maxon::reflection::GetFunctionInfo<decltype(UrlInterface::MTable::_instance.UrlInterface_Free)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "object\0", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(UrlInterface::MTable::_instance.UrlInterface_Alloc)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "allocLocation\0", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(UrlInterface::MTable::_instance.UrlInterface_Alloc_1)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "allocLocation\0object\0", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(UrlInterface::MTable::_instance.UrlInterface_GetScheme)>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, "", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(UrlInterface::MTable::_instance.UrlInterface_SetScheme)>(nullptr, maxon::reflection::Member::KIND::INSTANCE_FUNCTION, "scheme\0", 1LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(UrlInterface::MTable::_instance.UrlInterface_Append)>(nullptr, maxon::reflection::Member::KIND::INSTANCE_FUNCTION, "name\0", 1LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(UrlInterface::MTable::_instance.UrlInterface_Append_1)>(nullptr, maxon::reflection::Member::KIND::INSTANCE_FUNCTION, "relativeUrl\0", 1LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(UrlInterface::MTable::_instance.UrlInterface_RemoveName)>(nullptr, maxon::reflection::Member::KIND::INSTANCE_FUNCTION, "", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(UrlInterface::MTable::_instance.UrlInterface_GetEmbeddedUrl)>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, "", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(UrlInterface::MTable::_instance.UrlInterface_SetEmbeddedUrl)>(nullptr, maxon::reflection::Member::KIND::INSTANCE_FUNCTION, "url\0", 1LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(UrlInterface::MTable::_instance.UrlInterface_GetName)>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, "", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(UrlInterface::MTable::_instance.UrlInterface_SetName)>(nullptr, maxon::reflection::Member::KIND::INSTANCE_FUNCTION, "name\0", 1LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(UrlInterface::MTable::_instance.UrlInterface_GetDirectory)>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, "", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(UrlInterface::MTable::_instance.UrlInterface_SetPath)>(nullptr, maxon::reflection::Member::KIND::INSTANCE_FUNCTION, "path\0", 1LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(UrlInterface::MTable::_instance.UrlInterface_SetPath_1)>(nullptr, maxon::reflection::Member::KIND::INSTANCE_FUNCTION, "path\0convertWindowsBackslashes\0", 5LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(UrlInterface::MTable::_instance.UrlInterface_GetPath)>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, "", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(UrlInterface::MTable::_instance.UrlInterface_SetSystemPath)>(nullptr, maxon::reflection::Member::KIND::INSTANCE_FUNCTION, "path\0", 1LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(UrlInterface::MTable::_instance.UrlInterface_GetSystemPath)>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, "", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(UrlInterface::MTable::_instance.UrlInterface_SetUrl)>(nullptr, maxon::reflection::Member::KIND::INSTANCE_FUNCTION, "urlString\0enableDefaultFallbackScheme\0", 5LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(UrlInterface::MTable::_instance.UrlInterface_GetUrl)>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, "", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(UrlInterface::MTable::_instance.UrlInterface_SetAuthority)>(nullptr, maxon::reflection::Member::KIND::INSTANCE_FUNCTION, "authority\0", 1LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(UrlInterface::MTable::_instance.UrlInterface_SetAuthority_1)>(nullptr, maxon::reflection::Member::KIND::INSTANCE_FUNCTION, "authority\0", 1LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(UrlInterface::MTable::_instance.UrlInterface_GetAuthority)>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, "", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(UrlInterface::MTable::_instance.UrlInterface_GetComponents)>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, "parts\0", 2LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(UrlInterface::MTable::_instance.UrlInterface_GetRelativeUrl)>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, "basePath\0", 1LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(UrlInterface::MTable::_instance.UrlInterface_GetSuffix)>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, "", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(UrlInterface::MTable::_instance.UrlInterface_CheckSuffix)>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, "suffix\0", 1LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(UrlInterface::MTable::_instance.UrlInterface_SetSuffix)>(nullptr, maxon::reflection::Member::KIND::INSTANCE_FUNCTION, "suffix\0", 1LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(UrlInterface::MTable::_instance.UrlInterface_ClearSuffix)>(nullptr, maxon::reflection::Member::KIND::INSTANCE_FUNCTION, "", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(UrlInterface::MTable::_instance.UrlInterface_IsEmpty)>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, "", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(UrlInterface::MTable::_instance.UrlInterface_Compare)>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, "name\0mode\0", 5LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(UrlInterface::MTable::_instance.UrlInterface_GetData)>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, "key\0", 1LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(UrlInterface::MTable::_instance.UrlInterface_SetData)>(nullptr, maxon::reflection::Member::KIND::INSTANCE_FUNCTION, "key\0data\0persistent\0", 21LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(UrlInterface::MTable::_instance.UrlInterface_SetData_1)>(nullptr, maxon::reflection::Member::KIND::INSTANCE_FUNCTION, "key\0data\0persistent\0", 21LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(UrlInterface::MTable::_instance.UrlInterface_EraseData)>(nullptr, maxon::reflection::Member::KIND::INSTANCE_FUNCTION, "key\0persistent\0", 5LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(UrlInterface::MTable::_instance.UrlInterface_ToString)>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, "formatStatement\0", 1LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(UrlInterface::MTable::_instance.UrlInterface_ToCString)>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, "", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(UrlInterface::MTable::_instance.UrlInterface_ConvertToUiName)>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, "flags\0", 1LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(UrlInterface::MTable::_instance.UrlInterface_ConvertFromUiName)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "str\0", 1LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(UrlInterface::MTable::_instance.UrlInterface_DescribeIO)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "stream\0", 1LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(UrlInterface::MTable::_instance.UrlInterface_ConvertToUiNameWithRepository)>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, "flags\0lookupRepository\0", 5LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(UrlInterface::MTable::_instance.UrlInterface_ConvertFromUiNameWithRepository)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "str\0lookupRepository\0", 5LL, nullptr),
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
