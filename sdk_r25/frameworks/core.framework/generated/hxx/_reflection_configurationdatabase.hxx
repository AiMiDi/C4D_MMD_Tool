#if 1
namespace maxon
{
#if defined(PRIVATE_MAXON_REGISTRATION_FRAMEWORK) && !defined(MAXON_REGISTRATION_EXCLUDE_REFLECTION_NONVIRTUAL)
	static maxon::Result<void> RegisterReflection_Configuration(maxon::reflection::Class* cls, maxon::reflection::FunctionRegistrationCallback callback)
	{
		maxon::reflection::FunctionInfo functions[] =
		{
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(Configuration::MTable::_instance._Configuration_QueryBool)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "key\0result\0origin\0state\0", 169LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(Configuration::MTable::_instance._Configuration_QueryInt)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "key\0result\0origin\0state\0", 169LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(Configuration::MTable::_instance._Configuration_QueryFloat)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "key\0result\0origin\0state\0", 169LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(Configuration::MTable::_instance._Configuration_QueryString)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "key\0result\0origin\0state\0", 169LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(Configuration::MTable::_instance._Configuration_AddHelpForBool)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "key\0defaultValue\0category\0help\0", 85LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(Configuration::MTable::_instance._Configuration_AddHelpForInt)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "key\0defaultValue\0minValue\0maxValue\0category\0help\0", 1365LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(Configuration::MTable::_instance._Configuration_AddHelpForFloat)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "key\0defaultValue\0minValue\0maxValue\0category\0help\0", 1365LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(Configuration::MTable::_instance._Configuration_AddHelpForString)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "key\0defaultValue\0category\0help\0", 85LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(Configuration::MTable::_instance._Configuration_AddHelpForOption)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "key\0option\0isDefaultValue\0caseSensitive\0category\0help\0", 1365LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(Configuration::MTable::_instance._Configuration_BroadcastBool)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "key\0value\0", 5LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(Configuration::MTable::_instance._Configuration_BroadcastInt)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "key\0value\0", 5LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(Configuration::MTable::_instance._Configuration_BroadcastFloat)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "key\0value\0", 5LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(Configuration::MTable::_instance._Configuration_BroadcastString)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "key\0value\0", 5LL, nullptr),
		};
		return callback(cls, reinterpret_cast<const maxon::EntityReference*>(&Configuration::_interface), maxon::ToBlock(functions));
	}
#endif
#ifndef MAXON_REGISTRATION_EXCLUDE_REFLECTION_NONVIRTUAL
	static maxon::reflection::ContainerInfo g_reflection_Configuration("net.maxon.interface.configuration", nullptr, &RegisterReflection_Configuration, &PRIVATE_MAXON_MODULE);
#endif
}
#endif
