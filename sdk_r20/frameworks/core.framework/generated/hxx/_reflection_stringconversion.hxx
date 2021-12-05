#if 1
namespace maxon
{
#ifndef MAXON_REGISTRATION_EXCLUDE_REFLECTION_NONVIRTUAL
	static maxon::Result<void> RegisterReflection_StringConversion(maxon::reflection::Class* cls, maxon::reflection::FunctionRegistrationCallback callback)
	{
		maxon::reflection::FunctionInfo functions[] =
		{
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(StringConversion::MTable::_instance._StringConversion_FloatToString)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, 1365LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(StringConversion::MTable::_instance._StringConversion_FloatToString_1)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, 1365LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(StringConversion::MTable::_instance._StringConversion_AppendInt)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, 85LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(StringConversion::MTable::_instance._StringConversion_AppendUInt)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, 85LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(StringConversion::MTable::_instance._StringConversion_AppendInt_1)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, 85LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(StringConversion::MTable::_instance._StringConversion_AppendUInt_1)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, 85LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(StringConversion::MTable::_instance._StringConversion_MemorySizeToString)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, 5LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(StringConversion::MTable::_instance._StringConversion_HexToString)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, 85LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(StringConversion::MTable::_instance._StringConversion_HexToString_1)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, 85LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(StringConversion::MTable::_instance._StringConversion_ToFloat32)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, 5LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(StringConversion::MTable::_instance._StringConversion_ToFloat64)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, 5LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(StringConversion::MTable::_instance._StringConversion_ToInt64)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, 5LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(StringConversion::MTable::_instance._StringConversion_ToInt32)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, 5LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(StringConversion::MTable::_instance._StringConversion_ToUInt64)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, 5LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(StringConversion::MTable::_instance._StringConversion_ToUInt32)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, 5LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(StringConversion::MTable::_instance._StringConversion_StringToFloat)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, 9LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(StringConversion::MTable::_instance._StringConversion_StringToInteger)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, 597LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(StringConversion::MTable::_instance._StringConversion_GetLineEnd)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(StringConversion::MTable::_instance._StringConversion_GetLineEndC)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(StringConversion::MTable::_instance._StringConversion_FormatXArgs)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(StringConversion::MTable::_instance._StringConversion_ScanStringXArgs)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(StringConversion::MTable::_instance._StringConversion_ScanParameterBasic)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, 0LL, nullptr),
		};
		return callback(cls, reinterpret_cast<const maxon::EntityReference*>(&StringConversion::_interface), maxon::ToBlock(functions));
	}
	static maxon::reflection::ContainerInfo g_reflection_StringConversion("net.maxon.interface.stringconversion", nullptr, &RegisterReflection_StringConversion, &PRIVATE_MAXON_MODULE);
#endif
}
#endif
