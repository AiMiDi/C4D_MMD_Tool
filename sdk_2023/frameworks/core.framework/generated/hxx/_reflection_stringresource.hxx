#if 1
namespace maxon
{
#if defined(PRIVATE_MAXON_REGISTRATION_FRAMEWORK) && !defined(MAXON_REGISTRATION_EXCLUDE_REFLECTION_NONVIRTUAL)
	static maxon::Result<void> RegisterReflection_LanguageInterface(maxon::reflection::Class* cls, maxon::reflection::FunctionRegistrationCallback callback)
	{
		maxon::reflection::FunctionInfo functions[] =
		{
			maxon::reflection::GetFunctionInfo<decltype(LanguageInterface::MTable::_instance.LanguageInterface_Free)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "object\0", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(LanguageInterface::MTable::_instance.LanguageInterface_Alloc)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "allocLocation\0", 1LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(LanguageInterface::MTable::_instance.LanguageInterface_LoadResourceString)>(nullptr, maxon::reflection::Member::KIND::INSTANCE_FUNCTION, "scope\0keyValue\0", 5LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(LanguageInterface::MTable::_instance.LanguageInterface_GetName)>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, "", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(LanguageInterface::MTable::_instance.LanguageInterface_GetIdentifier)>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, "", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(LanguageInterface::MTable::_instance.LanguageInterface_GetFallbackLanguage)>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, "", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(LanguageInterface::MTable::_instance.LanguageInterface_ToString)>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, "fs\0", 0LL, nullptr),
		};
		return callback(cls, reinterpret_cast<const maxon::EntityReference*>(&LanguageInterface::_interface), maxon::ToBlock(functions));
	}
#endif
#ifndef MAXON_REGISTRATION_EXCLUDE_REFLECTION_NONVIRTUAL
	static maxon::reflection::ContainerInfo g_reflection_LanguageInterface("net.maxon.interface.language", nullptr, &RegisterReflection_LanguageInterface, &PRIVATE_MAXON_MODULE);
#endif
#if defined(PRIVATE_MAXON_REGISTRATION_FRAMEWORK) && !defined(MAXON_REGISTRATION_EXCLUDE_REFLECTION_NONVIRTUAL)
	static maxon::Result<void> RegisterReflection_Resource(maxon::reflection::Class* cls, maxon::reflection::FunctionRegistrationCallback callback)
	{
		maxon::reflection::FunctionInfo functions[] =
		{
			maxon::reflection::GetFunctionInfo<decltype(Resource::MTable::_instance.Resource_GetDefaultLanguage)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(Resource::MTable::_instance.Resource_GetCurrentLanguage)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(Resource::MTable::_instance.Resource_FindLanguage)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "identifier\0", 1LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(Resource::MTable::_instance.Resource_SetCurrentLanguage)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "language\0", 1LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(Resource::MTable::_instance.Resource_GetAllLanguages)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(Resource::MTable::_instance.Resource_LoadResourceString)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "scope\0keyValue\0", 5LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(Resource::MTable::_instance.Resource_WriteLanguagePrf)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "language\0", 1LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(Resource::MTable::_instance.Resource_ObservableLanguageChanged)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "", 0LL, nullptr),
		};
		return callback(cls, reinterpret_cast<const maxon::EntityReference*>(&Resource::_interface), maxon::ToBlock(functions));
	}
#endif
#ifndef MAXON_REGISTRATION_EXCLUDE_REFLECTION_NONVIRTUAL
	static maxon::reflection::ContainerInfo g_reflection_Resource("net.maxon.interface.resource", nullptr, &RegisterReflection_Resource, &PRIVATE_MAXON_MODULE);
#endif
}
#endif
