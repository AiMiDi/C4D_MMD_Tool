#if 1
namespace maxon
{
#ifndef MAXON_REGISTRATION_EXCLUDE_REFLECTION_NONVIRTUAL
	static maxon::Result<void> RegisterReflection_CrashReportServices(maxon::reflection::Class* cls, maxon::reflection::FunctionRegistrationCallback callback)
	{
		maxon::reflection::FunctionInfo functions[] =
		{
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(CrashReportServices::MTable::_instance._CrashReportServices_CreateCrashReportProperty)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, 5LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(CrashReportServices::MTable::_instance._CrashReportServices_FreeCrashReportProperty)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, 1LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(CrashReportServices::MTable::_instance._CrashReportServices_GetCrashReportProperties)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, 1LL, nullptr),
		};
		return callback(cls, reinterpret_cast<const maxon::EntityReference*>(&CrashReportServices::_interface), maxon::ToBlock(functions));
	}
	static maxon::reflection::ContainerInfo g_reflection_CrashReportServices("net.maxon.interface.crashreportservices", nullptr, &RegisterReflection_CrashReportServices, &PRIVATE_MAXON_MODULE);
#endif
}
#endif
