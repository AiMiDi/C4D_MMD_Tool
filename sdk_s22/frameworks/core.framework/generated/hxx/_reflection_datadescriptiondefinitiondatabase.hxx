#if 1
namespace maxon
{
#if defined(PRIVATE_MAXON_REGISTRATION_FRAMEWORK) && !defined(MAXON_REGISTRATION_EXCLUDE_REFLECTION_NONVIRTUAL)
	static maxon::Result<void> RegisterReflection_DataDescriptionDefinitionDatabaseInterface(maxon::reflection::Class* cls, maxon::reflection::FunctionRegistrationCallback callback)
	{
		maxon::reflection::FunctionInfo functions[] =
		{
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(DataDescriptionDefinitionDatabaseInterface::MTable::_instance._DataDescriptionDefinitionDatabaseInterface_LoadDescription)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "mode\0category\0language\0dataType\0foundInDatabase\0", 596LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(DataDescriptionDefinitionDatabaseInterface::MTable::_instance._DataDescriptionDefinitionDatabaseInterface_StoreDescription)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "databaseId\0category\0language\0dataType\0description\0overwrittenDescription\0usePendingSystem\0", 341LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(DataDescriptionDefinitionDatabaseInterface::MTable::_instance._DataDescriptionDefinitionDatabaseInterface_DeleteDescription)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "category\0language\0dataType\0", 21LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(DataDescriptionDefinitionDatabaseInterface::MTable::_instance._DataDescriptionDefinitionDatabaseInterface_GetRegisteredDescriptions)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "databaseId\0category\0language\0", 21LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(DataDescriptionDefinitionDatabaseInterface::MTable::_instance._DataDescriptionDefinitionDatabaseInterface_WriteDataBases)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(DataDescriptionDefinitionDatabaseInterface::MTable::_instance._DataDescriptionDefinitionDatabaseInterface_QueryNeedsWriteDataBases)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(DataDescriptionDefinitionDatabaseInterface::MTable::_instance._DataDescriptionDefinitionDatabaseInterface_RenameId)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "oldId\0newId\0", 5LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(DataDescriptionDefinitionDatabaseInterface::MTable::_instance._DataDescriptionDefinitionDatabaseInterface_RenameAttribute)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "oldId\0newId\0", 5LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(DataDescriptionDefinitionDatabaseInterface::MTable::_instance._DataDescriptionDefinitionDatabaseInterface_CheckUniqueAttributeName)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "searchId\0", 1LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(DataDescriptionDefinitionDatabaseInterface::MTable::_instance._DataDescriptionDefinitionDatabaseInterface_UpdateDescription)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "databaseId\0category\0language\0dataType\0descRef\0notifyParents\0", 1365LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(DataDescriptionDefinitionDatabaseInterface::MTable::_instance._DataDescriptionDefinitionDatabaseInterface_UpdateDescriptionI)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "databaseId\0category\0language\0descRef\0dataType\0", 341LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(DataDescriptionDefinitionDatabaseInterface::MTable::_instance._DataDescriptionDefinitionDatabaseInterface_RegisterDatabaseWithUrl)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "databaseId\0url\0", 5LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(DataDescriptionDefinitionDatabaseInterface::MTable::_instance._DataDescriptionDefinitionDatabaseInterface_RegisterDatabase)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "databaseId\0ddb\0", 5LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(DataDescriptionDefinitionDatabaseInterface::MTable::_instance._DataDescriptionDefinitionDatabaseInterface_UnregisterDatabase)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "databaseId\0", 1LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(DataDescriptionDefinitionDatabaseInterface::MTable::_instance._DataDescriptionDefinitionDatabaseInterface_IsWritableDatabase)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "databaseId\0languageId\0", 5LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(DataDescriptionDefinitionDatabaseInterface::MTable::_instance._DataDescriptionDefinitionDatabaseInterface_GetRegisteredDatabases)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(DataDescriptionDefinitionDatabaseInterface::MTable::_instance._DataDescriptionDefinitionDatabaseInterface_BuildDescription)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "category\0dataTypeId\0language\0", 4LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(DataDescriptionDefinitionDatabaseInterface::MTable::_instance._DataDescriptionDefinitionDatabaseInterface_RegisterMessage)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "dataTypeId\0attributeId\0cmdId\0func\0", 85LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(DataDescriptionDefinitionDatabaseInterface::MTable::_instance._DataDescriptionDefinitionDatabaseInterface_FindNodeMessage)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "dataTypeId\0attributeId\0cmdId\0", 21LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(DataDescriptionDefinitionDatabaseInterface::MTable::_instance._DataDescriptionDefinitionDatabaseInterface_ObservableSaveDatabase)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(DataDescriptionDefinitionDatabaseInterface::MTable::_instance._DataDescriptionDefinitionDatabaseInterface_ObservableDatabaseRegistrationChange)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "", 0LL, nullptr),
		};
		return callback(cls, reinterpret_cast<const maxon::EntityReference*>(&DataDescriptionDefinitionDatabaseInterface::_interface), maxon::ToBlock(functions));
	}
#endif
#ifndef MAXON_REGISTRATION_EXCLUDE_REFLECTION_NONVIRTUAL
	static maxon::reflection::ContainerInfo g_reflection_DataDescriptionDefinitionDatabaseInterface("net.maxon.interface.datadescriptiondefinitiondatabase", nullptr, &RegisterReflection_DataDescriptionDefinitionDatabaseInterface, &PRIVATE_MAXON_MODULE);
#endif
}
#endif
