#if 1
namespace maxon
{
#if defined(PRIVATE_MAXON_REGISTRATION_FRAMEWORK) && !defined(MAXON_REGISTRATION_EXCLUDE_REFLECTION_NONVIRTUAL)
	static maxon::Result<void> RegisterReflection_StringInterface(maxon::reflection::Class* cls, maxon::reflection::FunctionRegistrationCallback callback)
	{
		maxon::reflection::FunctionInfo functions[] =
		{
			maxon::reflection::GetFunctionInfo<decltype(StringInterface::MTable::_instance.StringInterface_Free)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "object\0", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(StringInterface::MTable::_instance.StringInterface_GetLength)>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, "", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(StringInterface::MTable::_instance.StringInterface_Init)>(nullptr, maxon::reflection::Member::KIND::INSTANCE_FUNCTION, "count\0fillChar\0", 5LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(StringInterface::MTable::_instance.StringInterface_Shrink)>(nullptr, maxon::reflection::Member::KIND::INSTANCE_FUNCTION, "", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(StringInterface::MTable::_instance.StringInterface_Append)>(nullptr, maxon::reflection::Member::KIND::INSTANCE_FUNCTION, "str\0", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(StringInterface::MTable::_instance.StringInterface_Append_1)>(nullptr, maxon::reflection::Member::KIND::INSTANCE_FUNCTION, "str\0len\0", 5LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(StringInterface::MTable::_instance.StringInterface_FindIndex)>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, "str\0start\0", 5LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(StringInterface::MTable::_instance.StringInterface_FindLastIndex)>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, "str\0start\0", 5LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(StringInterface::MTable::_instance.StringInterface_FindIndex_1)>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, "ch\0start\0", 5LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(StringInterface::MTable::_instance.StringInterface_FindLastIndex_1)>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, "ch\0start\0", 5LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(StringInterface::MTable::_instance.StringInterface_FindUpperIndex)>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, "str\0start\0", 5LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(StringInterface::MTable::_instance.StringInterface_FindLastUpperIndex)>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, "str\0start\0", 5LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(StringInterface::MTable::_instance.StringInterface_Erase)>(nullptr, maxon::reflection::Member::KIND::INSTANCE_FUNCTION, "position\0count\0", 5LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(StringInterface::MTable::_instance.StringInterface_Insert)>(nullptr, maxon::reflection::Member::KIND::INSTANCE_FUNCTION, "position\0str\0strStart\0strCount\0", 85LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(StringInterface::MTable::_instance.StringInterface_Insert_1)>(nullptr, maxon::reflection::Member::KIND::INSTANCE_FUNCTION, "position\0ch\0", 5LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(StringInterface::MTable::_instance.StringInterface_GetPart)>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, "start\0count\0", 5LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(StringInterface::MTable::_instance.StringInterface_ToUpper)>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, "", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(StringInterface::MTable::_instance.StringInterface_ToLower)>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, "", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(StringInterface::MTable::_instance.StringInterface_ComparePart)>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, "str\0mode\0position\0count\0", 85LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(StringInterface::MTable::_instance.StringInterface_GetHashCode)>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, "", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(StringInterface::MTable::_instance.StringInterface_GetUniqueHashCode)>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, "", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(StringInterface::MTable::_instance.StringInterface_SetChar)>(nullptr, maxon::reflection::Member::KIND::INSTANCE_FUNCTION, "pos\0ch\0", 5LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(StringInterface::MTable::_instance.StringInterface_GetChar)>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, "pos\0", 1LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(StringInterface::MTable::_instance.StringInterface_GetUtf32)>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, "stringData\0", 2LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(StringInterface::MTable::_instance.StringInterface_TrimLeft)>(nullptr, maxon::reflection::Member::KIND::INSTANCE_FUNCTION, "", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(StringInterface::MTable::_instance.StringInterface_TrimRight)>(nullptr, maxon::reflection::Member::KIND::INSTANCE_FUNCTION, "", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(StringInterface::MTable::_instance.StringInterface_Split)>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, "splitSymbol\0trim\0parts\0", 37LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(StringInterface::MTable::_instance.StringInterface_Replace)>(nullptr, maxon::reflection::Member::KIND::INSTANCE_FUNCTION, "find\0replace\0", 5LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(StringInterface::MTable::_instance.StringInterface_Replace_1)>(nullptr, maxon::reflection::Member::KIND::INSTANCE_FUNCTION, "find\0replace\0", 5LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(StringInterface::MTable::_instance.StringInterface_Replace_2)>(nullptr, maxon::reflection::Member::KIND::INSTANCE_FUNCTION, "find\0replace\0", 5LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(StringInterface::MTable::_instance.StringInterface_Alloc)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "allocLocation\0", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(StringInterface::MTable::_instance.StringInterface_Alloc_1)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "allocLocation\0object\0", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(StringInterface::MTable::_instance.StringInterface_GetCStringBlock)>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, "buffer\0stringEncoding\0", 7LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(StringInterface::MTable::_instance.StringInterface_GetCStringAppendArray)>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, "array\0stringEncoding\0", 7LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(StringInterface::MTable::_instance.StringInterface_GetCString)>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, "stringEncoding\0", 1LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(StringInterface::MTable::_instance.StringInterface_SetCString)>(nullptr, maxon::reflection::Member::KIND::INSTANCE_FUNCTION, "buffer\0count\0stringDecoding\0", 22LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(StringInterface::MTable::_instance.StringInterface_GetSystemEncoding)>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, "", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(StringInterface::MTable::_instance.StringInterface_SetSystemEncoding)>(nullptr, maxon::reflection::Member::KIND::INSTANCE_FUNCTION, "buffer\0count\0", 5LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(StringInterface::MTable::_instance.StringInterface_SetUtf32)>(nullptr, maxon::reflection::Member::KIND::INSTANCE_FUNCTION, "buffer\0count\0", 5LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(StringInterface::MTable::_instance.StringInterface_GetUtf16)>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, "stringData\0", 2LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(StringInterface::MTable::_instance.StringInterface_SetUtf16)>(nullptr, maxon::reflection::Member::KIND::INSTANCE_FUNCTION, "buffer\0count\0", 5LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(StringInterface::MTable::_instance.StringInterface_GetAndCacheConstString)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "chr\0len\0", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(StringInterface::MTable::_instance.StringInterface_GetAndCacheConstString_1)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "chr\0len\0isUtf8\0", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(StringInterface::MTable::_instance.StringInterface_PrivateEnumToString)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "info\0value\0formatStatement\0", 21LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(StringInterface::MTable::_instance.StringInterface_GetVariableInternalData)>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, "", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(StringInterface::MTable::_instance.StringInterface_GetCharacterWidth)>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, "", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(StringInterface::MTable::_instance.StringInterface_Prettify)>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, "indent\0indentStr\0breakUpThreshold\0angularBrackets\0", 85LL, nullptr),
		};
		return callback(cls, reinterpret_cast<const maxon::EntityReference*>(&StringInterface::_interface), maxon::ToBlock(functions));
	}
#endif
#ifndef MAXON_REGISTRATION_EXCLUDE_REFLECTION_NONVIRTUAL
	static maxon::reflection::ContainerInfo g_reflection_StringInterface("net.maxon.interface.string", nullptr, &RegisterReflection_StringInterface, &PRIVATE_MAXON_MODULE);
#endif
#if defined(PRIVATE_MAXON_REGISTRATION_FRAMEWORK) && !defined(MAXON_REGISTRATION_EXCLUDE_REFLECTION_NONVIRTUAL)
	static maxon::Result<void> RegisterReflection_CStringInterface(maxon::reflection::Class* cls, maxon::reflection::FunctionRegistrationCallback callback)
	{
		maxon::reflection::FunctionInfo functions[] =
		{
			maxon::reflection::GetFunctionInfo<decltype(CStringInterface::MTable::_instance.CStringInterface_Free)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "object\0", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(CStringInterface::MTable::_instance.CStringInterface_GetLength)>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, "", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(CStringInterface::MTable::_instance.CStringInterface_Init)>(nullptr, maxon::reflection::Member::KIND::INSTANCE_FUNCTION, "count\0fillChar\0", 5LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(CStringInterface::MTable::_instance.CStringInterface_Shrink)>(nullptr, maxon::reflection::Member::KIND::INSTANCE_FUNCTION, "", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(CStringInterface::MTable::_instance.CStringInterface_Append)>(nullptr, maxon::reflection::Member::KIND::INSTANCE_FUNCTION, "str\0", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(CStringInterface::MTable::_instance.CStringInterface_Append_1)>(nullptr, maxon::reflection::Member::KIND::INSTANCE_FUNCTION, "str\0len\0", 5LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(CStringInterface::MTable::_instance.CStringInterface_FindIndex)>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, "str\0start\0", 5LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(CStringInterface::MTable::_instance.CStringInterface_FindLastIndex)>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, "str\0start\0", 5LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(CStringInterface::MTable::_instance.CStringInterface_FindIndex_1)>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, "ch\0start\0", 5LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(CStringInterface::MTable::_instance.CStringInterface_FindLastIndex_1)>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, "ch\0start\0", 5LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(CStringInterface::MTable::_instance.CStringInterface_FindUpperIndex)>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, "str\0start\0", 5LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(CStringInterface::MTable::_instance.CStringInterface_FindLastUpperIndex)>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, "str\0start\0", 5LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(CStringInterface::MTable::_instance.CStringInterface_Erase)>(nullptr, maxon::reflection::Member::KIND::INSTANCE_FUNCTION, "position\0count\0", 5LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(CStringInterface::MTable::_instance.CStringInterface_Insert)>(nullptr, maxon::reflection::Member::KIND::INSTANCE_FUNCTION, "position\0str\0strStart\0strCount\0", 85LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(CStringInterface::MTable::_instance.CStringInterface_Insert_1)>(nullptr, maxon::reflection::Member::KIND::INSTANCE_FUNCTION, "position\0ch\0", 5LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(CStringInterface::MTable::_instance.CStringInterface_GetPart)>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, "start\0count\0", 5LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(CStringInterface::MTable::_instance.CStringInterface_ToUpper)>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, "", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(CStringInterface::MTable::_instance.CStringInterface_ToLower)>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, "", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(CStringInterface::MTable::_instance.CStringInterface_ComparePart)>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, "str\0mode\0position\0count\0", 85LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(CStringInterface::MTable::_instance.CStringInterface_GetHashCode)>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, "", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(CStringInterface::MTable::_instance.CStringInterface_GetUniqueHashCode)>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, "", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(CStringInterface::MTable::_instance.CStringInterface_SetChar)>(nullptr, maxon::reflection::Member::KIND::INSTANCE_FUNCTION, "pos\0ch\0", 5LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(CStringInterface::MTable::_instance.CStringInterface_GetChar)>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, "pos\0", 1LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(CStringInterface::MTable::_instance.CStringInterface_GetUtf32)>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, "stringData\0", 2LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(CStringInterface::MTable::_instance.CStringInterface_TrimLeft)>(nullptr, maxon::reflection::Member::KIND::INSTANCE_FUNCTION, "", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(CStringInterface::MTable::_instance.CStringInterface_TrimRight)>(nullptr, maxon::reflection::Member::KIND::INSTANCE_FUNCTION, "", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(CStringInterface::MTable::_instance.CStringInterface_Split)>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, "splitSymbol\0trim\0parts\0", 37LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(CStringInterface::MTable::_instance.CStringInterface_Replace)>(nullptr, maxon::reflection::Member::KIND::INSTANCE_FUNCTION, "find\0replace\0", 5LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(CStringInterface::MTable::_instance.CStringInterface_Replace_1)>(nullptr, maxon::reflection::Member::KIND::INSTANCE_FUNCTION, "find\0replace\0", 5LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(CStringInterface::MTable::_instance.CStringInterface_Replace_2)>(nullptr, maxon::reflection::Member::KIND::INSTANCE_FUNCTION, "find\0replace\0", 5LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(CStringInterface::MTable::_instance.CStringInterface_Alloc)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "allocLocation\0", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(CStringInterface::MTable::_instance.CStringInterface_Alloc_1)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "allocLocation\0object\0", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(CStringInterface::MTable::_instance.CStringInterface_GetCStringBlock)>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, "buffer\0", 3LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(CStringInterface::MTable::_instance.CStringInterface_GetCStringAppendArray)>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, "array\0", 3LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(CStringInterface::MTable::_instance.CStringInterface_Disconnect)>(nullptr, maxon::reflection::Member::KIND::INSTANCE_FUNCTION, "", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(CStringInterface::MTable::_instance.CStringInterface_SetCString)>(nullptr, maxon::reflection::Member::KIND::INSTANCE_FUNCTION, "buffer\0count\0", 6LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(CStringInterface::MTable::_instance.CStringInterface_GetCString)>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, "", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(CStringInterface::MTable::_instance.CStringInterface_GetInternalData)>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, "", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(CStringInterface::MTable::_instance.CStringInterface_GetAndCacheConstString)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "chr\0len\0", 0LL, nullptr),
		};
		return callback(cls, reinterpret_cast<const maxon::EntityReference*>(&CStringInterface::_interface), maxon::ToBlock(functions));
	}
#endif
#ifndef MAXON_REGISTRATION_EXCLUDE_REFLECTION_NONVIRTUAL
	static maxon::reflection::ContainerInfo g_reflection_CStringInterface("net.maxon.interface.cstring", nullptr, &RegisterReflection_CStringInterface, &PRIVATE_MAXON_MODULE);
#endif
#ifdef _HAS_CHAR8_T
#endif
}
#endif
