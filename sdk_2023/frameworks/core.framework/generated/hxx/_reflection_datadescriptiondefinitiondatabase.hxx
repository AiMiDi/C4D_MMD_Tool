#if 1
namespace maxon
{
#if defined(PRIVATE_MAXON_REGISTRATION_FRAMEWORK) && !defined(MAXON_REGISTRATION_EXCLUDE_REFLECTION_NONVIRTUAL)
	static maxon::Result<void> RegisterReflection_DataDescriptionDefinitionDatabaseInterface(maxon::reflection::Class* cls, maxon::reflection::FunctionRegistrationCallback callback)
	{
		maxon::reflection::FunctionInfo functions[] =
		{
			maxon::reflection::GetFunctionInfo<decltype(DataDescriptionDefinitionDatabaseInterface::MTable::_instance.DataDescriptionDefinitionDatabaseInterface_LoadDescription)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "mode\0category\0language\0dataType\0foundInDatabase\0", 596LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(DataDescriptionDefinitionDatabaseInterface::MTable::_instance.DataDescriptionDefinitionDatabaseInterface_StoreDescription)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "databaseId\0category\0language\0dataType\0description\0overwrittenDescription\0usePendingSystem\0", 341LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(DataDescriptionDefinitionDatabaseInterface::MTable::_instance.DataDescriptionDefinitionDatabaseInterface_DeleteDescription)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "category\0language\0dataType\0", 21LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(DataDescriptionDefinitionDatabaseInterface::MTable::_instance.DataDescriptionDefinitionDatabaseInterface_GetRegisteredDescriptions)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "databaseId\0category\0language\0", 21LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(DataDescriptionDefinitionDatabaseInterface::MTable::_instance.DataDescriptionDefinitionDatabaseInterface_WriteDataBases)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(DataDescriptionDefinitionDatabaseInterface::MTable::_instance.DataDescriptionDefinitionDatabaseInterface_WriteUserChangedDataBases)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(DataDescriptionDefinitionDatabaseInterface::MTable::_instance.DataDescriptionDefinitionDatabaseInterface_QueryNeedsWriteDataBases)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(DataDescriptionDefinitionDatabaseInterface::MTable::_instance.DataDescriptionDefinitionDatabaseInterface_QueryNeedsWriteDataBasesForUserChanges)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(DataDescriptionDefinitionDatabaseInterface::MTable::_instance.DataDescriptionDefinitionDatabaseInterface_RenameId)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "oldId\0newId\0", 5LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(DataDescriptionDefinitionDatabaseInterface::MTable::_instance.DataDescriptionDefinitionDatabaseInterface_RenameAttribute)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "oldId\0newId\0", 5LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(DataDescriptionDefinitionDatabaseInterface::MTable::_instance.DataDescriptionDefinitionDatabaseInterface_CheckUniqueAttributeName)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "searchId\0", 1LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(DataDescriptionDefinitionDatabaseInterface::MTable::_instance.DataDescriptionDefinitionDatabaseInterface_UpdateDescription)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "databaseId\0category\0language\0dataType\0descRef\0notifyParents\0", 1365LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(DataDescriptionDefinitionDatabaseInterface::MTable::_instance.DataDescriptionDefinitionDatabaseInterface_RegisterDatabaseWithUrl)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "databaseId\0url\0version\0", 21LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(DataDescriptionDefinitionDatabaseInterface::MTable::_instance.DataDescriptionDefinitionDatabaseInterface_RegisterDatabase)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "databaseId\0ddb\0", 5LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(DataDescriptionDefinitionDatabaseInterface::MTable::_instance.DataDescriptionDefinitionDatabaseInterface_UnregisterDatabase)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "databaseId\0", 1LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(DataDescriptionDefinitionDatabaseInterface::MTable::_instance.DataDescriptionDefinitionDatabaseInterface_IsWritableDatabase)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "databaseId\0languageId\0", 5LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(DataDescriptionDefinitionDatabaseInterface::MTable::_instance.DataDescriptionDefinitionDatabaseInterface_GetRegisteredDatabases)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(DataDescriptionDefinitionDatabaseInterface::MTable::_instance.DataDescriptionDefinitionDatabaseInterface_BuildDescription)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "category\0dataTypeId\0language\0", 4LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(DataDescriptionDefinitionDatabaseInterface::MTable::_instance.DataDescriptionDefinitionDatabaseInterface_RegisterMessage)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "dataTypeId\0attributeId\0cmdId\0func\0", 85LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(DataDescriptionDefinitionDatabaseInterface::MTable::_instance.DataDescriptionDefinitionDatabaseInterface_RegisterValueChangedMessage)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "dataTypeId\0attributeId\0func\0", 21LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(DataDescriptionDefinitionDatabaseInterface::MTable::_instance.DataDescriptionDefinitionDatabaseInterface_FindNodeMessage)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "dataTypeId\0attributeId\0cmdId\0", 21LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(DataDescriptionDefinitionDatabaseInterface::MTable::_instance.DataDescriptionDefinitionDatabaseInterface_FindNodeValueChangedMessage)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "dataTypeId\0attributeId\0receiver\0", 21LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(DataDescriptionDefinitionDatabaseInterface::MTable::_instance.DataDescriptionDefinitionDatabaseInterface_FixDatabaseProps)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "version\0entry\0", 5LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(DataDescriptionDefinitionDatabaseInterface::MTable::_instance.DataDescriptionDefinitionDatabaseInterface_ObservableSaveDatabase)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(DataDescriptionDefinitionDatabaseInterface::MTable::_instance.DataDescriptionDefinitionDatabaseInterface_ObservableDatabaseRegistrationChange)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "", 0LL, nullptr),
		};
		return callback(cls, reinterpret_cast<const maxon::EntityReference*>(&DataDescriptionDefinitionDatabaseInterface::_interface), maxon::ToBlock(functions));
	}
#endif
#ifndef MAXON_REGISTRATION_EXCLUDE_REFLECTION_NONVIRTUAL
	static maxon::reflection::ContainerInfo g_reflection_DataDescriptionDefinitionDatabaseInterface("net.maxon.interface.datadescriptiondefinitiondatabase", nullptr, &RegisterReflection_DataDescriptionDefinitionDatabaseInterface, &PRIVATE_MAXON_MODULE);
#endif
}
#endif
