#if 1
namespace maxon
{
#if defined(PRIVATE_MAXON_REGISTRATION_FRAMEWORK) && !defined(MAXON_REGISTRATION_EXCLUDE_REFLECTION_NONVIRTUAL)
	static maxon::Result<void> RegisterReflection_StringConversion(maxon::reflection::Class* cls, maxon::reflection::FunctionRegistrationCallback callback)
	{
		maxon::reflection::FunctionInfo functions[] =
		{
			maxon::reflection::GetFunctionInfo<decltype(StringConversion::MTable::_instance.StringConversion_FloatToString)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "value\0charsBeforeComma\0digitsAfterComma\0exponent\0fillChar\0formatStatement\0", 1365LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(StringConversion::MTable::_instance.StringConversion_FloatToString_1)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "value\0charsBeforeComma\0digitsAfterComma\0exponent\0fillChar\0formatStatement\0", 1365LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(StringConversion::MTable::_instance.StringConversion_AppendInt)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "str\0value\0datatypeSize\0formatStatement\0", 85LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(StringConversion::MTable::_instance.StringConversion_AppendUInt)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "str\0value\0datatypeSize\0formatStatement\0", 85LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(StringConversion::MTable::_instance.StringConversion_AppendInt_1)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "str\0value\0datatypeSize\0formatStatement\0", 85LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(StringConversion::MTable::_instance.StringConversion_AppendUInt_1)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "str\0value\0datatypeSize\0formatStatement\0", 85LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(StringConversion::MTable::_instance.StringConversion_MemorySizeToString)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "mem\0mebibytes\0", 5LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(StringConversion::MTable::_instance.StringConversion_HexToString)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "value\0prefix0x\0leadingZeros\0formatStatement\0", 85LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(StringConversion::MTable::_instance.StringConversion_HexToString_1)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "value\0prefix0x\0leadingZeros\0formatStatement\0", 85LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(StringConversion::MTable::_instance.StringConversion_ToFloat32)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "str\0flags\0", 5LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(StringConversion::MTable::_instance.StringConversion_ToFloat64)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "str\0flags\0", 5LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(StringConversion::MTable::_instance.StringConversion_ToInt64)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "str\0flags\0", 5LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(StringConversion::MTable::_instance.StringConversion_ToInt32)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "str\0flags\0", 5LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(StringConversion::MTable::_instance.StringConversion_ToUInt64)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "str\0flags\0", 5LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(StringConversion::MTable::_instance.StringConversion_ToUInt32)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "str\0flags\0", 5LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(StringConversion::MTable::_instance.StringConversion_StringToFloat)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "str\0processedChars\0", 9LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(StringConversion::MTable::_instance.StringConversion_StringToInteger)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "str\0base\0autodetect0x\0signedMode\0processedChars\0", 597LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(StringConversion::MTable::_instance.StringConversion_GetLineEnd)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(StringConversion::MTable::_instance.StringConversion_GetLineEndC)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(StringConversion::MTable::_instance.StringConversion_FormatXArgs)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "formatString\0argsCnt\0args\0argFuncs\0", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(StringConversion::MTable::_instance.StringConversion_ScanStringXArgs)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "str\0format\0parsedCharacters\0argsCnt\0args\0argFuncs\0", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(StringConversion::MTable::_instance.StringConversion_ScanParameterBasic)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "str\0signedMode\0processed\0formatStatement\0error\0", 0LL, nullptr),
		};
		return callback(cls, reinterpret_cast<const maxon::EntityReference*>(&StringConversion::_interface), maxon::ToBlock(functions));
	}
#endif
#ifndef MAXON_REGISTRATION_EXCLUDE_REFLECTION_NONVIRTUAL
	static maxon::reflection::ContainerInfo g_reflection_StringConversion("net.maxon.interface.stringconversion", nullptr, &RegisterReflection_StringConversion, &PRIVATE_MAXON_MODULE);
#endif
}
#endif
