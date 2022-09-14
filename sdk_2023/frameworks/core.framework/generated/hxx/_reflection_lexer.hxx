#if 1
namespace maxon
{
#if defined(PRIVATE_MAXON_REGISTRATION_FRAMEWORK) && !defined(MAXON_REGISTRATION_EXCLUDE_REFLECTION_NONVIRTUAL)
	static maxon::Result<void> RegisterReflection_LexerInterface(maxon::reflection::Class* cls, maxon::reflection::FunctionRegistrationCallback callback)
	{
		maxon::reflection::FunctionInfo functions[] =
		{
			maxon::reflection::GetFunctionInfo<decltype(LexerInterface::MTable::_instance.LexerInterface_Free)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "object\0", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(LexerInterface::MTable::_instance.LexerInterface_Alloc)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "allocLocation\0", 1LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(LexerInterface::MTable::_instance.LexerInterface_Init)>(nullptr, maxon::reflection::Member::KIND::INSTANCE_FUNCTION, "fileName\0flags\0stringEscapeCharacters\0stringDecoding\0firstParseFlag\0", 341LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(LexerInterface::MTable::_instance.LexerInterface_AddOperator)>(nullptr, maxon::reflection::Member::KIND::INSTANCE_FUNCTION, "chars\0", 1LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(LexerInterface::MTable::_instance.LexerInterface_Close)>(nullptr, maxon::reflection::Member::KIND::INSTANCE_FUNCTION, "", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(LexerInterface::MTable::_instance.LexerInterface_ReadNextChar)>(nullptr, maxon::reflection::Member::KIND::INSTANCE_FUNCTION, "", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(LexerInterface::MTable::_instance.LexerInterface_SkipSpaces)>(nullptr, maxon::reflection::Member::KIND::INSTANCE_FUNCTION, "", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(LexerInterface::MTable::_instance.LexerInterface_SkipLineToEnd)>(nullptr, maxon::reflection::Member::KIND::INSTANCE_FUNCTION, "collectSkipped\0", 1LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(LexerInterface::MTable::_instance.LexerInterface_ReadNextSymbol)>(nullptr, maxon::reflection::Member::KIND::INSTANCE_FUNCTION, "flags\0", 1LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(LexerInterface::MTable::_instance.LexerInterface_ReadNextSymbolExpected)>(nullptr, maxon::reflection::Member::KIND::INSTANCE_FUNCTION, "expectedSymbols\0flags\0", 5LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(LexerInterface::MTable::_instance.LexerInterface_RewindSymbol)>(nullptr, maxon::reflection::Member::KIND::INSTANCE_FUNCTION, "", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(LexerInterface::MTable::_instance.LexerInterface_GetSymbol)>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, "", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(LexerInterface::MTable::_instance.LexerInterface_GetLeadingSpace)>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, "", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(LexerInterface::MTable::_instance.LexerInterface_GetIdent)>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, "", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(LexerInterface::MTable::_instance.LexerInterface_GetFloat)>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, "val\0", 2LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(LexerInterface::MTable::_instance.LexerInterface_GetFloat_1)>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, "val\0", 1LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(LexerInterface::MTable::_instance.LexerInterface_GetInt)>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, "val\0", 1LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(LexerInterface::MTable::_instance.LexerInterface_GetInt_1)>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, "val\0", 1LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(LexerInterface::MTable::_instance.LexerInterface_GetUInt)>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, "val\0", 1LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(LexerInterface::MTable::_instance.LexerInterface_GetUInt_1)>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, "val\0", 1LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(LexerInterface::MTable::_instance.LexerInterface_GetCurrentReadPosition)>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, "", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(LexerInterface::MTable::_instance.LexerInterface_GetSymbolPosition)>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, "", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(LexerInterface::MTable::_instance.LexerInterface_CheckIdent)>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, "cmp\0", 1LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(LexerInterface::MTable::_instance.LexerInterface_CheckIdent_1)>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, "cmp\0", 1LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(LexerInterface::MTable::_instance.LexerInterface_GetLine)>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, "", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(LexerInterface::MTable::_instance.LexerInterface_SetStringQuoteCharacters)>(nullptr, maxon::reflection::Member::KIND::INSTANCE_FUNCTION, "quoteChar\0", 1LL, nullptr),
		};
		return callback(cls, reinterpret_cast<const maxon::EntityReference*>(&LexerInterface::_interface), maxon::ToBlock(functions));
	}
#endif
#ifndef MAXON_REGISTRATION_EXCLUDE_REFLECTION_NONVIRTUAL
	static maxon::reflection::ContainerInfo g_reflection_LexerInterface("net.maxon.interface.lexer", nullptr, &RegisterReflection_LexerInterface, &PRIVATE_MAXON_MODULE);
#endif
}
#endif
