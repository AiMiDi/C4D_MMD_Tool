#if 1
namespace maxon
{
#ifndef MAXON_REGISTRATION_EXCLUDE_REFLECTION_NONVIRTUAL
	static maxon::Result<void> RegisterReflection_DataDescriptionDatabaseInterface(maxon::reflection::Class* cls, maxon::reflection::FunctionRegistrationCallback callback)
	{
		maxon::reflection::FunctionInfo functions[] =
		{
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(DataDescriptionDatabaseInterface::MTable::_instance._DataDescriptionDatabaseInterface_LoadDescription)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, 21LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(DataDescriptionDatabaseInterface::MTable::_instance._DataDescriptionDatabaseInterface_LoadDescription_1)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(DataDescriptionDatabaseInterface::MTable::_instance._DataDescriptionDatabaseInterface_StoreDescription)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, 85LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(DataDescriptionDatabaseInterface::MTable::_instance._DataDescriptionDatabaseInterface_StoreDescription_1)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(DataDescriptionDatabaseInterface::MTable::_instance._DataDescriptionDatabaseInterface_DescriptionDefinitionChanged)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(DataDescriptionDatabaseInterface::MTable::_instance._DataDescriptionDatabaseInterface_GetEffectiveEnumList)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, 341LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(DataDescriptionDatabaseInterface::MTable::_instance._DataDescriptionDatabaseInterface_PostProcessStringDescription)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, 5LL, nullptr),
		};
		return callback(cls, reinterpret_cast<const maxon::EntityReference*>(&DataDescriptionDatabaseInterface::_interface), maxon::ToBlock(functions));
	}
	static maxon::reflection::ContainerInfo g_reflection_DataDescriptionDatabaseInterface("net.maxon.interface.datadescriptiondatabase", nullptr, &RegisterReflection_DataDescriptionDatabaseInterface, &PRIVATE_MAXON_MODULE);
#endif
#ifndef MAXON_REGISTRATION_EXCLUDE_INTERFACES
	PRIVATE_MAXON_REGISTRY_DEFINE(ProcessEnumListDelegates);
#endif
}
#endif
