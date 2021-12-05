#if 1
namespace maxon
{
#ifndef MAXON_REGISTRATION_EXCLUDE_REFLECTION_NONVIRTUAL
	static maxon::Result<void> RegisterReflection_DataDescriptionInterface(maxon::reflection::Class* cls, maxon::reflection::FunctionRegistrationCallback callback)
	{
		maxon::reflection::FunctionInfo functions[] =
		{
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(DataDescriptionInterface::MTable::_instance._DataDescriptionInterface_Free)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(DataDescriptionInterface::MTable::_instance._DataDescriptionInterface_Alloc)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(DataDescriptionInterface::MTable::_instance._DataDescriptionInterface_Alloc_1)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(DataDescriptionInterface::MTable::_instance._DataDescriptionInterface_GetInfo)>::type>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(DataDescriptionInterface::MTable::_instance._DataDescriptionInterface_SetInfo)>::type>(nullptr, maxon::reflection::Member::KIND::INSTANCE_FUNCTION, 4LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(DataDescriptionInterface::MTable::_instance._DataDescriptionInterface_GetEntryCount)>::type>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(DataDescriptionInterface::MTable::_instance._DataDescriptionInterface_GetEntries)>::type>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(DataDescriptionInterface::MTable::_instance._DataDescriptionInterface_GetEntry)>::type>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, 4LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(DataDescriptionInterface::MTable::_instance._DataDescriptionInterface_SetEntry)>::type>(nullptr, maxon::reflection::Member::KIND::INSTANCE_FUNCTION, 20LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(DataDescriptionInterface::MTable::_instance._DataDescriptionInterface_EraseEntry)>::type>(nullptr, maxon::reflection::Member::KIND::INSTANCE_FUNCTION, 4LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(DataDescriptionInterface::MTable::_instance._DataDescriptionInterface_Reset)>::type>(nullptr, maxon::reflection::Member::KIND::INSTANCE_FUNCTION, 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(DataDescriptionInterface::MTable::_instance._DataDescriptionInterface_IsEqual)>::type>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, 20LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(DataDescriptionInterface::MTable::_instance._DataDescriptionInterface_Compare)>::type>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(DataDescriptionInterface::MTable::_instance._DataDescriptionInterface_GetHashCode)>::type>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(DataDescriptionInterface::MTable::_instance._DataDescriptionInterface_ToString)>::type>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, 4LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(DataDescriptionInterface::MTable::_instance._DataDescriptionInterface_DescribeIO)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, 1LL, nullptr),
		};
		return callback(cls, reinterpret_cast<const maxon::EntityReference*>(&DataDescriptionInterface::_interface), maxon::ToBlock(functions));
	}
	static maxon::reflection::ContainerInfo g_reflection_DataDescriptionInterface("net.maxon.interface.datadescription", nullptr, &RegisterReflection_DataDescriptionInterface, &PRIVATE_MAXON_MODULE);
#endif
#ifndef MAXON_REGISTRATION_EXCLUDE_INTERFACES
	PRIVATE_MAXON_REGISTRY_DEFINE(DataTypeCppIdentifiers);
#endif
}
#endif
