#if 1
namespace maxon
{
#ifndef MAXON_REGISTRATION_EXCLUDE_REFLECTION_NONVIRTUAL
	static maxon::Result<void> RegisterReflection_StringInterface(maxon::reflection::Class* cls, maxon::reflection::FunctionRegistrationCallback callback)
	{
		maxon::reflection::FunctionInfo functions[] =
		{
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(StringInterface::MTable::_instance._StringInterface_Free)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(StringInterface::MTable::_instance._StringInterface_GetLength)>::type>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(StringInterface::MTable::_instance._StringInterface_Init)>::type>(nullptr, maxon::reflection::Member::KIND::INSTANCE_FUNCTION, 20LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(StringInterface::MTable::_instance._StringInterface_Shrink)>::type>(nullptr, maxon::reflection::Member::KIND::INSTANCE_FUNCTION, 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(StringInterface::MTable::_instance._StringInterface_Append)>::type>(nullptr, maxon::reflection::Member::KIND::INSTANCE_FUNCTION, 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(StringInterface::MTable::_instance._StringInterface_Append_1)>::type>(nullptr, maxon::reflection::Member::KIND::INSTANCE_FUNCTION, 20LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(StringInterface::MTable::_instance._StringInterface_FindIndex)>::type>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, 20LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(StringInterface::MTable::_instance._StringInterface_FindLastIndex)>::type>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, 20LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(StringInterface::MTable::_instance._StringInterface_FindIndex_1)>::type>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, 20LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(StringInterface::MTable::_instance._StringInterface_FindLastIndex_1)>::type>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, 20LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(StringInterface::MTable::_instance._StringInterface_FindUpperIndex)>::type>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, 20LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(StringInterface::MTable::_instance._StringInterface_FindLastUpperIndex)>::type>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, 20LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(StringInterface::MTable::_instance._StringInterface_Erase)>::type>(nullptr, maxon::reflection::Member::KIND::INSTANCE_FUNCTION, 20LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(StringInterface::MTable::_instance._StringInterface_Insert)>::type>(nullptr, maxon::reflection::Member::KIND::INSTANCE_FUNCTION, 340LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(StringInterface::MTable::_instance._StringInterface_Insert_1)>::type>(nullptr, maxon::reflection::Member::KIND::INSTANCE_FUNCTION, 20LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(StringInterface::MTable::_instance._StringInterface_GetPart)>::type>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, 20LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(StringInterface::MTable::_instance._StringInterface_ToUpper)>::type>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(StringInterface::MTable::_instance._StringInterface_ToLower)>::type>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(StringInterface::MTable::_instance._StringInterface_ComparePart)>::type>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, 340LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(StringInterface::MTable::_instance._StringInterface_GetHashCode)>::type>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(StringInterface::MTable::_instance._StringInterface_SetChar)>::type>(nullptr, maxon::reflection::Member::KIND::INSTANCE_FUNCTION, 20LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(StringInterface::MTable::_instance._StringInterface_GetChar)>::type>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, 4LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(StringInterface::MTable::_instance._StringInterface_GetUtf32)>::type>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, 8LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(StringInterface::MTable::_instance._StringInterface_TrimLeft)>::type>(nullptr, maxon::reflection::Member::KIND::INSTANCE_FUNCTION, 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(StringInterface::MTable::_instance._StringInterface_TrimRight)>::type>(nullptr, maxon::reflection::Member::KIND::INSTANCE_FUNCTION, 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(StringInterface::MTable::_instance._StringInterface_Split)>::type>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, 148LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(StringInterface::MTable::_instance._StringInterface_Replace)>::type>(nullptr, maxon::reflection::Member::KIND::INSTANCE_FUNCTION, 20LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(StringInterface::MTable::_instance._StringInterface_Replace_1)>::type>(nullptr, maxon::reflection::Member::KIND::INSTANCE_FUNCTION, 20LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(StringInterface::MTable::_instance._StringInterface_Replace_2)>::type>(nullptr, maxon::reflection::Member::KIND::INSTANCE_FUNCTION, 20LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(StringInterface::MTable::_instance._StringInterface_Alloc)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(StringInterface::MTable::_instance._StringInterface_Alloc_1)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(StringInterface::MTable::_instance._StringInterface_GetCStringBlock)>::type>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, 28LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(StringInterface::MTable::_instance._StringInterface_GetCStringAppendArray)>::type>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, 28LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(StringInterface::MTable::_instance._StringInterface_GetCString)>::type>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, 4LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(StringInterface::MTable::_instance._StringInterface_SetCString)>::type>(nullptr, maxon::reflection::Member::KIND::INSTANCE_FUNCTION, 88LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(StringInterface::MTable::_instance._StringInterface_GetSystemEncoding)>::type>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(StringInterface::MTable::_instance._StringInterface_SetSystemEncoding)>::type>(nullptr, maxon::reflection::Member::KIND::INSTANCE_FUNCTION, 20LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(StringInterface::MTable::_instance._StringInterface_SetUtf32)>::type>(nullptr, maxon::reflection::Member::KIND::INSTANCE_FUNCTION, 20LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(StringInterface::MTable::_instance._StringInterface_GetUtf16)>::type>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, 8LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(StringInterface::MTable::_instance._StringInterface_SetUtf16)>::type>(nullptr, maxon::reflection::Member::KIND::INSTANCE_FUNCTION, 20LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(StringInterface::MTable::_instance._StringInterface_GetAndCacheConstString)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(StringInterface::MTable::_instance._StringInterface_GetAndCacheConstString_1)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(StringInterface::MTable::_instance._StringInterface_PrivateEnumToString)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, 5461LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(StringInterface::MTable::_instance._StringInterface_GetVariableInternalData)>::type>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(StringInterface::MTable::_instance._StringInterface_GetCharacterWidth)>::type>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, 0LL, nullptr),
		};
		return callback(cls, reinterpret_cast<const maxon::EntityReference*>(&StringInterface::_interface), maxon::ToBlock(functions));
	}
	static maxon::reflection::ContainerInfo g_reflection_StringInterface("net.maxon.interface.string", nullptr, &RegisterReflection_StringInterface, &PRIVATE_MAXON_MODULE);
#endif
#ifndef MAXON_REGISTRATION_EXCLUDE_REFLECTION_NONVIRTUAL
	static maxon::Result<void> RegisterReflection_CStringInterface(maxon::reflection::Class* cls, maxon::reflection::FunctionRegistrationCallback callback)
	{
		maxon::reflection::FunctionInfo functions[] =
		{
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(CStringInterface::MTable::_instance._CStringInterface_Free)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(CStringInterface::MTable::_instance._CStringInterface_GetLength)>::type>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(CStringInterface::MTable::_instance._CStringInterface_Init)>::type>(nullptr, maxon::reflection::Member::KIND::INSTANCE_FUNCTION, 20LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(CStringInterface::MTable::_instance._CStringInterface_Shrink)>::type>(nullptr, maxon::reflection::Member::KIND::INSTANCE_FUNCTION, 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(CStringInterface::MTable::_instance._CStringInterface_Append)>::type>(nullptr, maxon::reflection::Member::KIND::INSTANCE_FUNCTION, 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(CStringInterface::MTable::_instance._CStringInterface_Append_1)>::type>(nullptr, maxon::reflection::Member::KIND::INSTANCE_FUNCTION, 20LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(CStringInterface::MTable::_instance._CStringInterface_FindIndex)>::type>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, 20LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(CStringInterface::MTable::_instance._CStringInterface_FindLastIndex)>::type>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, 20LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(CStringInterface::MTable::_instance._CStringInterface_FindIndex_1)>::type>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, 20LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(CStringInterface::MTable::_instance._CStringInterface_FindLastIndex_1)>::type>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, 20LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(CStringInterface::MTable::_instance._CStringInterface_FindUpperIndex)>::type>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, 20LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(CStringInterface::MTable::_instance._CStringInterface_FindLastUpperIndex)>::type>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, 20LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(CStringInterface::MTable::_instance._CStringInterface_Erase)>::type>(nullptr, maxon::reflection::Member::KIND::INSTANCE_FUNCTION, 20LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(CStringInterface::MTable::_instance._CStringInterface_Insert)>::type>(nullptr, maxon::reflection::Member::KIND::INSTANCE_FUNCTION, 340LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(CStringInterface::MTable::_instance._CStringInterface_Insert_1)>::type>(nullptr, maxon::reflection::Member::KIND::INSTANCE_FUNCTION, 20LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(CStringInterface::MTable::_instance._CStringInterface_GetPart)>::type>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, 20LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(CStringInterface::MTable::_instance._CStringInterface_ToUpper)>::type>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(CStringInterface::MTable::_instance._CStringInterface_ToLower)>::type>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(CStringInterface::MTable::_instance._CStringInterface_ComparePart)>::type>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, 340LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(CStringInterface::MTable::_instance._CStringInterface_GetHashCode)>::type>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(CStringInterface::MTable::_instance._CStringInterface_SetChar)>::type>(nullptr, maxon::reflection::Member::KIND::INSTANCE_FUNCTION, 20LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(CStringInterface::MTable::_instance._CStringInterface_GetChar)>::type>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, 4LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(CStringInterface::MTable::_instance._CStringInterface_GetUtf32)>::type>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, 8LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(CStringInterface::MTable::_instance._CStringInterface_TrimLeft)>::type>(nullptr, maxon::reflection::Member::KIND::INSTANCE_FUNCTION, 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(CStringInterface::MTable::_instance._CStringInterface_TrimRight)>::type>(nullptr, maxon::reflection::Member::KIND::INSTANCE_FUNCTION, 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(CStringInterface::MTable::_instance._CStringInterface_Split)>::type>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, 148LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(CStringInterface::MTable::_instance._CStringInterface_Replace)>::type>(nullptr, maxon::reflection::Member::KIND::INSTANCE_FUNCTION, 20LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(CStringInterface::MTable::_instance._CStringInterface_Replace_1)>::type>(nullptr, maxon::reflection::Member::KIND::INSTANCE_FUNCTION, 20LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(CStringInterface::MTable::_instance._CStringInterface_Replace_2)>::type>(nullptr, maxon::reflection::Member::KIND::INSTANCE_FUNCTION, 20LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(CStringInterface::MTable::_instance._CStringInterface_Alloc)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(CStringInterface::MTable::_instance._CStringInterface_Alloc_1)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(CStringInterface::MTable::_instance._CStringInterface_GetCStringBlock)>::type>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, 12LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(CStringInterface::MTable::_instance._CStringInterface_GetCStringAppendArray)>::type>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, 12LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(CStringInterface::MTable::_instance._CStringInterface_SetCString)>::type>(nullptr, maxon::reflection::Member::KIND::INSTANCE_FUNCTION, 24LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(CStringInterface::MTable::_instance._CStringInterface_GetCString)>::type>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(CStringInterface::MTable::_instance._CStringInterface_GetInternalData)>::type>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(CStringInterface::MTable::_instance._CStringInterface_GetAndCacheConstString)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, 0LL, nullptr),
		};
		return callback(cls, reinterpret_cast<const maxon::EntityReference*>(&CStringInterface::_interface), maxon::ToBlock(functions));
	}
	static maxon::reflection::ContainerInfo g_reflection_CStringInterface("net.maxon.interface.cstring", nullptr, &RegisterReflection_CStringInterface, &PRIVATE_MAXON_MODULE);
#endif
#if !(defined MAXON_COMPILER_INTEL)
#else
#endif
}
#endif
