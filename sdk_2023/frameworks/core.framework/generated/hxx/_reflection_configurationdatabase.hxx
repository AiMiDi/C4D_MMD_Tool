#if 1
namespace maxon
{
#if defined(PRIVATE_MAXON_REGISTRATION_FRAMEWORK) && !defined(MAXON_REGISTRATION_EXCLUDE_REFLECTION_NONVIRTUAL)
	static maxon::Result<void> RegisterReflection_Configuration(maxon::reflection::Class* cls, maxon::reflection::FunctionRegistrationCallback callback)
	{
		maxon::reflection::FunctionInfo functions[] =
		{
			maxon::reflection::GetFunctionInfo<decltype(Configuration::MTable::_instance.Configuration_QueryBool)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "key\0result\0origin\0state\0", 169LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(Configuration::MTable::_instance.Configuration_QueryInt)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "key\0result\0origin\0state\0", 169LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(Configuration::MTable::_instance.Configuration_QueryFloat)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "key\0result\0origin\0state\0", 169LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(Configuration::MTable::_instance.Configuration_QueryString)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "key\0result\0origin\0state\0", 169LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(Configuration::MTable::_instance.Configuration_AddHelpForBool)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "key\0defaultValue\0category\0help\0", 85LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(Configuration::MTable::_instance.Configuration_AddHelpForInt)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "key\0defaultValue\0minValue\0maxValue\0category\0help\0", 1365LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(Configuration::MTable::_instance.Configuration_AddHelpForFloat)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "key\0defaultValue\0minValue\0maxValue\0category\0help\0", 1365LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(Configuration::MTable::_instance.Configuration_AddHelpForString)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "key\0defaultValue\0category\0help\0", 85LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(Configuration::MTable::_instance.Configuration_AddHelpForOption)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "key\0option\0isDefaultValue\0caseSensitive\0category\0help\0", 1365LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(Configuration::MTable::_instance.Configuration_BroadcastBool)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "key\0value\0", 5LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(Configuration::MTable::_instance.Configuration_BroadcastInt)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "key\0value\0", 5LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(Configuration::MTable::_instance.Configuration_BroadcastFloat)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "key\0value\0", 5LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(Configuration::MTable::_instance.Configuration_BroadcastString)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "key\0value\0", 5LL, nullptr),
		};
		return callback(cls, reinterpret_cast<const maxon::EntityReference*>(&Configuration::_interface), maxon::ToBlock(functions));
	}
#endif
#ifndef MAXON_REGISTRATION_EXCLUDE_REFLECTION_NONVIRTUAL
	static maxon::reflection::ContainerInfo g_reflection_Configuration("net.maxon.interface.configuration", nullptr, &RegisterReflection_Configuration, &PRIVATE_MAXON_MODULE);
#endif
}
#endif
