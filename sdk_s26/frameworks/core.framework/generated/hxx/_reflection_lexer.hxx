#if 1
namespace maxon
{
#if defined(PRIVATE_MAXON_REGISTRATION_FRAMEWORK) && !defined(MAXON_REGISTRATION_EXCLUDE_REFLECTION_NONVIRTUAL)
	static maxon::Result<void> RegisterReflection_LexerInterface(maxon::reflection::Class* cls, maxon::reflection::FunctionRegistrationCallback callback)
	{
		maxon::reflection::FunctionInfo functions[] =
		{
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(LexerInterface::MTable::_instance.LexerInterface_Free)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "object\0", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(LexerInterface::MTable::_instance.LexerInterface_Alloc)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "allocLocation\0", 1LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(LexerInterface::MTable::_instance.LexerInterface_Init)>::type>(nullptr, maxon::reflection::Member::KIND::INSTANCE_FUNCTION, "fileName\0flags\0stringEscapeCharacters\0stringDecoding\0firstParseFlag\0", 341LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(LexerInterface::MTable::_instance.LexerInterface_AddOperator)>::type>(nullptr, maxon::reflection::Member::KIND::INSTANCE_FUNCTION, "chars\0", 1LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(LexerInterface::MTable::_instance.LexerInterface_Close)>::type>(nullptr, maxon::reflection::Member::KIND::INSTANCE_FUNCTION, "", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(LexerInterface::MTable::_instance.LexerInterface_ReadNextChar)>::type>(nullptr, maxon::reflection::Member::KIND::INSTANCE_FUNCTION, "", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(LexerInterface::MTable::_instance.LexerInterface_SkipSpaces)>::type>(nullptr, maxon::reflection::Member::KIND::INSTANCE_FUNCTION, "", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(LexerInterface::MTable::_instance.LexerInterface_SkipLineToEnd)>::type>(nullptr, maxon::reflection::Member::KIND::INSTANCE_FUNCTION, "collectSkipped\0", 1LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(LexerInterface::MTable::_instance.LexerInterface_ReadNextSymbol)>::type>(nullptr, maxon::reflection::Member::KIND::INSTANCE_FUNCTION, "flags\0", 1LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(LexerInterface::MTable::_instance.LexerInterface_ReadNextSymbolExpected)>::type>(nullptr, maxon::reflection::Member::KIND::INSTANCE_FUNCTION, "expectedSymbols\0flags\0", 5LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(LexerInterface::MTable::_instance.LexerInterface_RewindSymbol)>::type>(nullptr, maxon::reflection::Member::KIND::INSTANCE_FUNCTION, "", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(LexerInterface::MTable::_instance.LexerInterface_GetSymbol)>::type>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, "", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(LexerInterface::MTable::_instance.LexerInterface_GetLeadingSpace)>::type>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, "", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(LexerInterface::MTable::_instance.LexerInterface_GetIdent)>::type>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, "", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(LexerInterface::MTable::_instance.LexerInterface_GetFloat)>::type>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, "val\0", 2LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(LexerInterface::MTable::_instance.LexerInterface_GetFloat_1)>::type>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, "val\0", 1LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(LexerInterface::MTable::_instance.LexerInterface_GetInt)>::type>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, "val\0", 1LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(LexerInterface::MTable::_instance.LexerInterface_GetInt_1)>::type>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, "val\0", 1LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(LexerInterface::MTable::_instance.LexerInterface_GetUInt)>::type>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, "val\0", 1LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(LexerInterface::MTable::_instance.LexerInterface_GetUInt_1)>::type>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, "val\0", 1LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(LexerInterface::MTable::_instance.LexerInterface_GetCurrentReadPosition)>::type>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, "", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(LexerInterface::MTable::_instance.LexerInterface_GetSymbolPosition)>::type>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, "", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(LexerInterface::MTable::_instance.LexerInterface_CheckIdent)>::type>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, "cmp\0", 1LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(LexerInterface::MTable::_instance.LexerInterface_CheckIdent_1)>::type>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, "cmp\0", 1LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(LexerInterface::MTable::_instance.LexerInterface_GetLine)>::type>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, "", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(LexerInterface::MTable::_instance.LexerInterface_SetStringQuoteCharacters)>::type>(nullptr, maxon::reflection::Member::KIND::INSTANCE_FUNCTION, "quoteChar\0", 1LL, nullptr),
		};
		return callback(cls, reinterpret_cast<const maxon::EntityReference*>(&LexerInterface::_interface), maxon::ToBlock(functions));
	}
#endif
#ifndef MAXON_REGISTRATION_EXCLUDE_REFLECTION_NONVIRTUAL
	static maxon::reflection::ContainerInfo g_reflection_LexerInterface("net.maxon.interface.lexer", nullptr, &RegisterReflection_LexerInterface, &PRIVATE_MAXON_MODULE);
#endif
}
#endif