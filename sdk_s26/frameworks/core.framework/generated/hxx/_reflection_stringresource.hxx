#if 1
namespace maxon
{
#if defined(PRIVATE_MAXON_REGISTRATION_FRAMEWORK) && !defined(MAXON_REGISTRATION_EXCLUDE_REFLECTION_NONVIRTUAL)
	static maxon::Result<void> RegisterReflection_LanguageInterface(maxon::reflection::Class* cls, maxon::reflection::FunctionRegistrationCallback callback)
	{
		maxon::reflection::FunctionInfo functions[] =
		{
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(LanguageInterface::MTable::_instance.LanguageInterface_Free)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "object\0", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(LanguageInterface::MTable::_instance.LanguageInterface_Alloc)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "allocLocation\0", 1LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(LanguageInterface::MTable::_instance.LanguageInterface_LoadResourceString)>::type>(nullptr, maxon::reflection::Member::KIND::INSTANCE_FUNCTION, "scope\0keyValue\0", 5LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(LanguageInterface::MTable::_instance.LanguageInterface_GetName)>::type>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, "", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(LanguageInterface::MTable::_instance.LanguageInterface_GetIdentifier)>::type>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, "", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(LanguageInterface::MTable::_instance.LanguageInterface_GetFallbackLanguage)>::type>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, "", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(LanguageInterface::MTable::_instance.LanguageInterface_ToString)>::type>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, "fs\0", 0LL, nullptr),
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
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(Resource::MTable::_instance.Resource_GetDefaultLanguage)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(Resource::MTable::_instance.Resource_GetCurrentLanguage)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(Resource::MTable::_instance.Resource_FindLanguage)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "identifier\0", 1LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(Resource::MTable::_instance.Resource_SetCurrentLanguage)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "language\0", 1LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(Resource::MTable::_instance.Resource_GetAllLanguages)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(Resource::MTable::_instance.Resource_LoadResourceString)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "scope\0keyValue\0", 5LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(Resource::MTable::_instance.Resource_WriteLanguagePrf)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "language\0", 1LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(Resource::MTable::_instance.Resource_ObservableLanguageChanged)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "", 0LL, nullptr),
		};
		return callback(cls, reinterpret_cast<const maxon::EntityReference*>(&Resource::_interface), maxon::ToBlock(functions));
	}
#endif
#ifndef MAXON_REGISTRATION_EXCLUDE_REFLECTION_NONVIRTUAL
	static maxon::reflection::ContainerInfo g_reflection_Resource("net.maxon.interface.resource", nullptr, &RegisterReflection_Resource, &PRIVATE_MAXON_MODULE);
#endif
}
#endif
