#if 1
namespace maxon
{
#ifndef MAXON_REGISTRATION_EXCLUDE_INTERFACES
	PRIVATE_MAXON_DATATYPE_REGISTER_ENUM(SUBSYSTEM, "net.maxon.datatype.enum.subsystem", SIZEOF(SUBSYSTEM), false, "UNDEFINED\0CONSOLE\0WINDOWS\0", const maxon::UInt64 values[] = {(maxon::UInt64) SUBSYSTEM::UNDEFINED, (maxon::UInt64) SUBSYSTEM::CONSOLE, (maxon::UInt64) SUBSYSTEM::WINDOWS})
#endif
#ifndef MAXON_REGISTRATION_EXCLUDE_INTERFACES
	PRIVATE_MAXON_DATATYPE_REGISTER_ENUM(APPLICATION_URLTYPE, "net.maxon.datatype.enum.application_urltype", SIZEOF(APPLICATION_URLTYPE), false, "STARTUP_DIR\0APPLICATION\0APP_EXECUTABLE\0CORELIBS_DIR\0RESOURCE_DIR\0TEMP_DIR\0PREFS_DIR\0GLOBALPREFS_DIR\0DESKTOP_DIR\0USER_HOME_DIR\0USER_DOCUMENTS_DIR\0SYSTEM_PROGRAMS_DIR\0CURRENT_WORKING_DIR\0CURRENT_MODULE_DIR\0CURRENT_MODULE_RESOURCE_DIR\0", const maxon::UInt64 values[] = {(maxon::UInt64) APPLICATION_URLTYPE::STARTUP_DIR, (maxon::UInt64) APPLICATION_URLTYPE::APPLICATION, (maxon::UInt64) APPLICATION_URLTYPE::APP_EXECUTABLE, (maxon::UInt64) APPLICATION_URLTYPE::CORELIBS_DIR, (maxon::UInt64) APPLICATION_URLTYPE::RESOURCE_DIR, (maxon::UInt64) APPLICATION_URLTYPE::TEMP_DIR, (maxon::UInt64) APPLICATION_URLTYPE::PREFS_DIR, (maxon::UInt64) APPLICATION_URLTYPE::GLOBALPREFS_DIR, (maxon::UInt64) APPLICATION_URLTYPE::DESKTOP_DIR, (maxon::UInt64) APPLICATION_URLTYPE::USER_HOME_DIR, (maxon::UInt64) APPLICATION_URLTYPE::USER_DOCUMENTS_DIR, (maxon::UInt64) APPLICATION_URLTYPE::SYSTEM_PROGRAMS_DIR, (maxon::UInt64) APPLICATION_URLTYPE::CURRENT_WORKING_DIR, (maxon::UInt64) APPLICATION_URLTYPE::CURRENT_MODULE_DIR, (maxon::UInt64) APPLICATION_URLTYPE::CURRENT_MODULE_RESOURCE_DIR})
#endif
#ifndef MAXON_REGISTRATION_EXCLUDE_INTERFACES
	PRIVATE_MAXON_DATATYPE_REGISTER_ENUM(APPLICATIONMODE, "net.maxon.datatype.enum.applicationmode", SIZEOF(APPLICATIONMODE), false, "DONTWAIT\0KEEPRUNNING\0SHUTDOWN\0", const maxon::UInt64 values[] = {(maxon::UInt64) APPLICATIONMODE::DONTWAIT, (maxon::UInt64) APPLICATIONMODE::KEEPRUNNING, (maxon::UInt64) APPLICATIONMODE::SHUTDOWN})
#endif
#ifdef MAXON_TARGET_WINDOWS
#endif
#if defined(PRIVATE_MAXON_REGISTRATION_FRAMEWORK) && !defined(MAXON_REGISTRATION_EXCLUDE_REFLECTION_NONVIRTUAL)
	static maxon::Result<void> RegisterReflection_Application(maxon::reflection::Class* cls, maxon::reflection::FunctionRegistrationCallback callback)
	{
		maxon::reflection::FunctionInfo functions[] =
		{
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(Application::MTable::_instance._Application_GetTempUrl)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "directory\0", 1LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(Application::MTable::_instance._Application_GetModulePaths)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(Application::MTable::_instance._Application_GetCommandLineArgCount)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(Application::MTable::_instance._Application_GetCommandLineArg)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "idx\0", 1LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(Application::MTable::_instance._Application_GetMachineInfo)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(Application::MTable::_instance._Application_GetApplicationMode)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(Application::MTable::_instance._Application_SetApplicationMode)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "mode\0", 1LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(Application::MTable::_instance._Application_GetFeature)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "feature\0", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(Application::MTable::_instance._Application_SetFeature)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "feature\0value\0", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(Application::MTable::_instance._Application_GetVersion)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "version\0buildID\0", 10LL, nullptr),
#ifdef MAXON_TARGET_WINDOWS
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(Application::MTable::_instance._Application_GetWindowsSubsystem)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "", 0LL, nullptr),
#endif
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(Application::MTable::_instance._Application_GetUrlI)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "urlType\0", 0LL, nullptr),
		};
		return callback(cls, reinterpret_cast<const maxon::EntityReference*>(&Application::_interface), maxon::ToBlock(functions));
	}
#endif
#ifndef MAXON_REGISTRATION_EXCLUDE_REFLECTION_NONVIRTUAL
	static maxon::reflection::ContainerInfo g_reflection_Application("net.maxon.interface.application", nullptr, &RegisterReflection_Application, &PRIVATE_MAXON_MODULE);
#endif
}
#endif
