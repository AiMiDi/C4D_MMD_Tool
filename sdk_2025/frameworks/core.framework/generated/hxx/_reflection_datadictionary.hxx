#if 1
namespace maxon
{
#if defined(PRIVATE_MAXON_REGISTRATION_FRAMEWORK) && !defined(MAXON_REGISTRATION_EXCLUDE_REFLECTION_NONVIRTUAL)
	static maxon::Result<void> RegisterReflection_DataDictionaryInterface(maxon::reflection::Class* cls, maxon::reflection::FunctionRegistrationCallback callback)
	{
		maxon::reflection::FunctionInfo functions[] =
		{
			maxon::reflection::GetFunctionInfo<decltype(DataDictionaryInterface::MTable::_instance.DataDictionaryInterface_Free)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "object\0", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(DataDictionaryInterface::MTable::_instance.DataDictionaryInterface_Alloc)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "allocLocation\0", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(DataDictionaryInterface::MTable::_instance.DataDictionaryInterface_Alloc_1)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "allocLocation\0object\0", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(DataDictionaryInterface::MTable::_instance.DataDictionaryInterface_SetData)>(nullptr, maxon::reflection::Member::KIND::INSTANCE_FUNCTION, "key\0data\0", 5LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(DataDictionaryInterface::MTable::_instance.DataDictionaryInterface_SetData_1)>(nullptr, maxon::reflection::Member::KIND::INSTANCE_FUNCTION, "key\0data\0", 5LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(DataDictionaryInterface::MTable::_instance.DataDictionaryInterface_SetData_2)>(nullptr, maxon::reflection::Member::KIND::INSTANCE_FUNCTION, "key\0data\0", 5LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(DataDictionaryInterface::MTable::_instance.DataDictionaryInterface_GetData)>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, "key\0", 1LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(DataDictionaryInterface::MTable::_instance.DataDictionaryInterface_EraseData)>(nullptr, maxon::reflection::Member::KIND::INSTANCE_FUNCTION, "key\0", 1LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(DataDictionaryInterface::MTable::_instance.DataDictionaryInterface_Reset)>(nullptr, maxon::reflection::Member::KIND::INSTANCE_FUNCTION, "", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(DataDictionaryInterface::MTable::_instance.DataDictionaryInterface_GetCount)>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, "", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(DataDictionaryInterface::MTable::_instance.DataDictionaryInterface_ToString)>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, "formatStatement\0", 1LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(DataDictionaryInterface::MTable::_instance.DataDictionaryInterface_DescribeIO)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "stream\0", 1LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(DataDictionaryInterface::MTable::_instance.DataDictionaryInterface_IsEqual)>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, "other\0equality\0", 1LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(DataDictionaryInterface::MTable::_instance.DataDictionaryInterface_GetHashCode)>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, "", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(DataDictionaryInterface::MTable::_instance.DataDictionaryInterface_GetUniqueHashCode)>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, "", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(DataDictionaryInterface::MTable::_instance.DataDictionaryInterface_InitIterator)>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, "iterator\0end\0", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(DataDictionaryInterface::MTable::_instance.DataDictionaryInterface_PrivateGetData)>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, "key\0", 1LL, nullptr),
		};
		return callback(cls, reinterpret_cast<const maxon::EntityReference*>(&DataDictionaryInterface::_interface), maxon::ToBlock(functions));
	}
#endif
#ifndef MAXON_REGISTRATION_EXCLUDE_REFLECTION_NONVIRTUAL
	static maxon::reflection::ContainerInfo g_reflection_DataDictionaryInterface("net.maxon.interface.datadictionary", nullptr, &RegisterReflection_DataDictionaryInterface, &PRIVATE_MAXON_MODULE);
#endif
}
#endif
