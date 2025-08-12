#if 1
namespace maxon
{
#if defined(PRIVATE_MAXON_REGISTRATION_FRAMEWORK) && !defined(MAXON_REGISTRATION_EXCLUDE_REFLECTION_NONVIRTUAL)
	static maxon::Result<void> RegisterReflection_UrlFileCacheEntryInterface(maxon::reflection::Class* cls, maxon::reflection::FunctionRegistrationCallback callback)
	{
		maxon::reflection::FunctionInfo functions[] =
		{
			maxon::reflection::GetFunctionInfo<decltype(UrlFileCacheEntryInterface::MTable::_instance.UrlFileCacheEntryInterface_Free)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "object\0", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(UrlFileCacheEntryInterface::MTable::_instance.UrlFileCacheEntryInterface_GetSourceUrl)>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, "", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(UrlFileCacheEntryInterface::MTable::_instance.UrlFileCacheEntryInterface_GetCacheUrl)>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, "", 0LL, nullptr),
		};
		return callback(cls, reinterpret_cast<const maxon::EntityReference*>(&UrlFileCacheEntryInterface::_interface), maxon::ToBlock(functions));
	}
#endif
#ifndef MAXON_REGISTRATION_EXCLUDE_REFLECTION_NONVIRTUAL
	static maxon::reflection::ContainerInfo g_reflection_UrlFileCacheEntryInterface("net.maxon.interface.urlfilecacheentry", nullptr, &RegisterReflection_UrlFileCacheEntryInterface, &PRIVATE_MAXON_MODULE);
#endif
#if defined(PRIVATE_MAXON_REGISTRATION_FRAMEWORK) && !defined(MAXON_REGISTRATION_EXCLUDE_REFLECTION_NONVIRTUAL)
	static maxon::Result<void> RegisterReflection_UrlFileCacheInterface(maxon::reflection::Class* cls, maxon::reflection::FunctionRegistrationCallback callback)
	{
		maxon::reflection::FunctionInfo functions[] =
		{
			maxon::reflection::GetFunctionInfo<decltype(UrlFileCacheInterface::MTable::_instance.UrlFileCacheInterface_IsAccessible)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "url\0", 1LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(UrlFileCacheInterface::MTable::_instance.UrlFileCacheInterface_FindOrCreateUrl)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "sourceUrl\0maxCacheTime\0flags\0", 21LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(UrlFileCacheInterface::MTable::_instance.UrlFileCacheInterface_FlushCache)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "url\0", 0LL, nullptr),
		};
		return callback(cls, reinterpret_cast<const maxon::EntityReference*>(&UrlFileCacheInterface::_interface), maxon::ToBlock(functions));
	}
#endif
#ifndef MAXON_REGISTRATION_EXCLUDE_REFLECTION_NONVIRTUAL
	static maxon::reflection::ContainerInfo g_reflection_UrlFileCacheInterface("net.maxon.interface.urlfilecache", nullptr, &RegisterReflection_UrlFileCacheInterface, &PRIVATE_MAXON_MODULE);
#endif
}
#endif
