#if 1
namespace maxon
{
#if defined(PRIVATE_MAXON_REGISTRATION_FRAMEWORK) && !defined(MAXON_REGISTRATION_EXCLUDE_REFLECTION_NONVIRTUAL)
	static maxon::Result<void> RegisterReflection_DataDictionaryInterface(maxon::reflection::Class* cls, maxon::reflection::FunctionRegistrationCallback callback)
	{
		maxon::reflection::FunctionInfo functions[] =
		{
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(DataDictionaryInterface::MTable::_instance.DataDictionaryInterface_Free)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "object\0", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(DataDictionaryInterface::MTable::_instance.DataDictionaryInterface_Alloc)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "allocLocation\0", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(DataDictionaryInterface::MTable::_instance.DataDictionaryInterface_Alloc_1)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "allocLocation\0object\0", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(DataDictionaryInterface::MTable::_instance.DataDictionaryInterface_SetData)>::type>(nullptr, maxon::reflection::Member::KIND::INSTANCE_FUNCTION, "key\0data\0", 5LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(DataDictionaryInterface::MTable::_instance.DataDictionaryInterface_SetData_1)>::type>(nullptr, maxon::reflection::Member::KIND::INSTANCE_FUNCTION, "key\0data\0", 5LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(DataDictionaryInterface::MTable::_instance.DataDictionaryInterface_SetData_2)>::type>(nullptr, maxon::reflection::Member::KIND::INSTANCE_FUNCTION, "key\0data\0", 5LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(DataDictionaryInterface::MTable::_instance.DataDictionaryInterface_GetData)>::type>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, "key\0", 1LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(DataDictionaryInterface::MTable::_instance.DataDictionaryInterface_EraseData)>::type>(nullptr, maxon::reflection::Member::KIND::INSTANCE_FUNCTION, "key\0", 1LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(DataDictionaryInterface::MTable::_instance.DataDictionaryInterface_Reset)>::type>(nullptr, maxon::reflection::Member::KIND::INSTANCE_FUNCTION, "", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(DataDictionaryInterface::MTable::_instance.DataDictionaryInterface_IsEmpty)>::type>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, "", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(DataDictionaryInterface::MTable::_instance.DataDictionaryInterface_GetCount)>::type>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, "", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(DataDictionaryInterface::MTable::_instance.DataDictionaryInterface_ToString)>::type>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, "formatStatement\0", 1LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(DataDictionaryInterface::MTable::_instance.DataDictionaryInterface_DescribeIO)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "stream\0", 1LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(DataDictionaryInterface::MTable::_instance.DataDictionaryInterface_IsEqual)>::type>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, "other\0equality\0", 1LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(DataDictionaryInterface::MTable::_instance.DataDictionaryInterface_GetHashCode)>::type>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, "", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(DataDictionaryInterface::MTable::_instance.DataDictionaryInterface_InitIterator)>::type>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, "iterator\0end\0", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(DataDictionaryInterface::MTable::_instance.DataDictionaryInterface_PrivateGetData)>::type>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, "key\0", 1LL, nullptr),
		};
		return callback(cls, reinterpret_cast<const maxon::EntityReference*>(&DataDictionaryInterface::_interface), maxon::ToBlock(functions));
	}
#endif
#ifndef MAXON_REGISTRATION_EXCLUDE_REFLECTION_NONVIRTUAL
	static maxon::reflection::ContainerInfo g_reflection_DataDictionaryInterface("net.maxon.interface.datadictionary", nullptr, &RegisterReflection_DataDictionaryInterface, &PRIVATE_MAXON_MODULE);
#endif
#if (defined MAXON_TARGET_WINDOWS) && (defined MAXON_TARGET_DEBUG)
#endif
}
#endif
