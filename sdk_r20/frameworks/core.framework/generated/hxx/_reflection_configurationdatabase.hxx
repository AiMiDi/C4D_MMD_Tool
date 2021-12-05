#if 1
namespace maxon
{
#ifndef MAXON_REGISTRATION_EXCLUDE_REFLECTION_NONVIRTUAL
	static maxon::Result<void> RegisterReflection_Configuration(maxon::reflection::Class* cls, maxon::reflection::FunctionRegistrationCallback callback)
	{
		maxon::reflection::FunctionInfo functions[] =
		{
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(Configuration::MTable::_instance._Configuration_QueryBool)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, 169LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(Configuration::MTable::_instance._Configuration_QueryInt)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, 169LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(Configuration::MTable::_instance._Configuration_QueryFloat)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, 169LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(Configuration::MTable::_instance._Configuration_QueryString)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, 169LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(Configuration::MTable::_instance._Configuration_AddHelpForBool)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, 85LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(Configuration::MTable::_instance._Configuration_AddHelpForInt)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, 1365LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(Configuration::MTable::_instance._Configuration_AddHelpForFloat)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, 1365LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(Configuration::MTable::_instance._Configuration_AddHelpForString)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, 85LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(Configuration::MTable::_instance._Configuration_AddHelpForOption)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, 1365LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(Configuration::MTable::_instance._Configuration_BroadcastBool)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, 5LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(Configuration::MTable::_instance._Configuration_BroadcastInt)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, 5LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(Configuration::MTable::_instance._Configuration_BroadcastFloat)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, 5LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(Configuration::MTable::_instance._Configuration_BroadcastString)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, 5LL, nullptr),
		};
		return callback(cls, reinterpret_cast<const maxon::EntityReference*>(&Configuration::_interface), maxon::ToBlock(functions));
	}
	static maxon::reflection::ContainerInfo g_reflection_Configuration("net.maxon.interface.configuration", nullptr, &RegisterReflection_Configuration, &PRIVATE_MAXON_MODULE);
#endif
}
#endif
