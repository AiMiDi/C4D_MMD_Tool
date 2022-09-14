#if 1
namespace maxon
{
#if defined(PRIVATE_MAXON_REGISTRATION_FRAMEWORK) && !defined(MAXON_REGISTRATION_EXCLUDE_REFLECTION_NONVIRTUAL)
	static maxon::Result<void> RegisterReflection_CrashHandler(maxon::reflection::Class* cls, maxon::reflection::FunctionRegistrationCallback callback)
	{
		maxon::reflection::FunctionInfo functions[] =
		{
			maxon::reflection::GetFunctionInfo<decltype(CrashHandler::MTable::_instance.CrashHandler_SetCallback)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "callback\0", 1LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(CrashHandler::MTable::_instance.CrashHandler_SetSecondaryCallback)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "callback\0", 1LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(CrashHandler::MTable::_instance.CrashHandler_SetCrashDataDirectory)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "dataDirectory\0", 1LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(CrashHandler::MTable::_instance.CrashHandler_DisplayCrashDialog)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "title\0message\0", 5LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(CrashHandler::MTable::_instance.CrashHandler_GetProcessModules)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "modules\0", 2LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(CrashHandler::MTable::_instance.CrashHandler_ResolveBugReport)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "report\0symbolFileArchives\0temporaryDir\0", 21LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(CrashHandler::MTable::_instance.CrashHandler_ObservableCrashDataDirectory)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "", 0LL, nullptr),
		};
		return callback(cls, reinterpret_cast<const maxon::EntityReference*>(&CrashHandler::_interface), maxon::ToBlock(functions));
	}
#endif
#ifndef MAXON_REGISTRATION_EXCLUDE_REFLECTION_NONVIRTUAL
	static maxon::reflection::ContainerInfo g_reflection_CrashHandler("net.maxon.interface.crashhandler", nullptr, &RegisterReflection_CrashHandler, &PRIVATE_MAXON_MODULE);
#endif
}
#endif
