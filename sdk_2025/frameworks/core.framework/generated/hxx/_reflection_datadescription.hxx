#if 1
namespace maxon
{
#if defined(PRIVATE_MAXON_REGISTRATION_FRAMEWORK) && !defined(MAXON_REGISTRATION_EXCLUDE_REFLECTION_NONVIRTUAL)
	static maxon::Result<void> RegisterReflection_DataDescriptionInterface(maxon::reflection::Class* cls, maxon::reflection::FunctionRegistrationCallback callback)
	{
		maxon::reflection::FunctionInfo functions[] =
		{
			maxon::reflection::GetFunctionInfo<decltype(DataDescriptionInterface::MTable::_instance.DataDescriptionInterface_Free)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "object\0", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(DataDescriptionInterface::MTable::_instance.DataDescriptionInterface_Alloc)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "allocLocation\0", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(DataDescriptionInterface::MTable::_instance.DataDescriptionInterface_Alloc_1)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "allocLocation\0object\0", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(DataDescriptionInterface::MTable::_instance.DataDescriptionInterface_GetInfo)>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, "", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(DataDescriptionInterface::MTable::_instance.DataDescriptionInterface_SetInfo)>(nullptr, maxon::reflection::Member::KIND::INSTANCE_FUNCTION, "info\0", 1LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(DataDescriptionInterface::MTable::_instance.DataDescriptionInterface_GetEntryCount)>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, "", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(DataDescriptionInterface::MTable::_instance.DataDescriptionInterface_GetEntries)>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, "", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(DataDescriptionInterface::MTable::_instance.DataDescriptionInterface_GetEntry)>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, "id\0", 1LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(DataDescriptionInterface::MTable::_instance.DataDescriptionInterface_FindEntry)>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, "id\0", 1LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(DataDescriptionInterface::MTable::_instance.DataDescriptionInterface_SetEntry)>(nullptr, maxon::reflection::Member::KIND::INSTANCE_FUNCTION, "props\0merge\0", 5LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(DataDescriptionInterface::MTable::_instance.DataDescriptionInterface_EraseEntry)>(nullptr, maxon::reflection::Member::KIND::INSTANCE_FUNCTION, "id\0", 1LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(DataDescriptionInterface::MTable::_instance.DataDescriptionInterface_Reset)>(nullptr, maxon::reflection::Member::KIND::INSTANCE_FUNCTION, "", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(DataDescriptionInterface::MTable::_instance.DataDescriptionInterface_IsEqual)>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, "other\0equality\0", 5LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(DataDescriptionInterface::MTable::_instance.DataDescriptionInterface_Compare)>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, "other\0", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(DataDescriptionInterface::MTable::_instance.DataDescriptionInterface_GetHashCode)>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, "", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(DataDescriptionInterface::MTable::_instance.DataDescriptionInterface_GetUniqueHashCode)>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, "", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(DataDescriptionInterface::MTable::_instance.DataDescriptionInterface_ToString)>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, "formatStatement\0", 1LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(DataDescriptionInterface::MTable::_instance.DataDescriptionInterface_DescribeIO)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "stream\0", 1LL, nullptr),
		};
		return callback(cls, reinterpret_cast<const maxon::EntityReference*>(&DataDescriptionInterface::_interface), maxon::ToBlock(functions));
	}
#endif
#ifndef MAXON_REGISTRATION_EXCLUDE_REFLECTION_NONVIRTUAL
	static maxon::reflection::ContainerInfo g_reflection_DataDescriptionInterface("net.maxon.interface.datadescription", nullptr, &RegisterReflection_DataDescriptionInterface, &PRIVATE_MAXON_MODULE);
#endif
#ifndef MAXON_REGISTRATION_EXCLUDE_INTERFACES
	PRIVATE_MAXON_REGISTRY_DEFINE(LegacyDataTypeIdentifiers);
#endif
}
#endif
