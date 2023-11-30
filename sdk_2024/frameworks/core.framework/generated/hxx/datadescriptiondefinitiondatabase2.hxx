
#ifndef DOXYGEN

#if defined MAXON_COMPILER_GCC
	#pragma GCC diagnostic push
	#if MAXON_COMPILER_GCC >= 600
		#pragma GCC diagnostic ignored "-Wmisleading-indentation"
	#endif
#endif

#if 1
constexpr const maxon::Char* DataDescriptionDefinitionDatabaseInterface::PrivateGetCppName() { return nullptr; }

struct DataDescriptionDefinitionDatabaseInterface::MTable
{
	static MTable _instance;
	static MTable _unresolvedInstance;
	static const maxon::Char* const _ids;
	static maxon::Bool InitUnresolved(maxon::NonvirtualInterfaceReference::UnresolvedAssembler assembler, MTable* tbl);
	static const maxon::UNRESOLVED_RETURN_TYPE _returnTypes[];
	static const maxon::Bool HAS_NONSTATIC = false;
	PRIVATE_MAXON_SF_POINTER(DataDescriptionDefinitionDatabaseInterface_LoadDescription, LoadDescription, MAXON_EXPAND_VA_ARGS, (Result<DataDescriptionDefinition>), LOADDESCRIPTIONMODE mode, const Id& category, const LanguageRef& language, const IdAndVersion& dataType, Id* foundInDatabase);
	PRIVATE_MAXON_SF_POINTER(DataDescriptionDefinitionDatabaseInterface_StoreDescription, StoreDescription, MAXON_EXPAND_VA_ARGS, (Result<void>), const Id& databaseId, const Id& category, const LanguageRef& language, const IdAndVersion& dataType, const DataDescriptionDefinition& description, const DataDescriptionDefinition& overwrittenDescription, Bool usePendingSystem);
	PRIVATE_MAXON_SF_POINTER(DataDescriptionDefinitionDatabaseInterface_DeleteDescription, DeleteDescription, MAXON_EXPAND_VA_ARGS, (Result<Bool>), const Id& category, const LanguageRef& language, const IdAndVersion& dataType);
	PRIVATE_MAXON_SF_POINTER(DataDescriptionDefinitionDatabaseInterface_GetRegisteredDescriptions, GetRegisteredDescriptions, MAXON_EXPAND_VA_ARGS, (Result<BaseArray<IdAndVersion>>), const Id& databaseId, const Id& category, const LanguageRef& language);
	PRIVATE_MAXON_SF_POINTER(DataDescriptionDefinitionDatabaseInterface_WriteDataBases, WriteDataBases, MAXON_EXPAND_VA_ARGS, (Result<void>));
	PRIVATE_MAXON_SF_POINTER(DataDescriptionDefinitionDatabaseInterface_WriteUserChangedDataBases, WriteUserChangedDataBases, MAXON_EXPAND_VA_ARGS, (Result<void>));
	PRIVATE_MAXON_SF_POINTER(DataDescriptionDefinitionDatabaseInterface_QueryNeedsWriteDataBases, QueryNeedsWriteDataBases, MAXON_EXPAND_VA_ARGS, (Bool));
	PRIVATE_MAXON_SF_POINTER(DataDescriptionDefinitionDatabaseInterface_QueryNeedsWriteDataBasesForUserChanges, QueryNeedsWriteDataBasesForUserChanges, MAXON_EXPAND_VA_ARGS, (Bool));
	PRIVATE_MAXON_SF_POINTER(DataDescriptionDefinitionDatabaseInterface_RenameId, RenameId, MAXON_EXPAND_VA_ARGS, (Result<Int>), const Id& oldId, const Id& newId);
	PRIVATE_MAXON_SF_POINTER(DataDescriptionDefinitionDatabaseInterface_RenameAttribute, RenameAttribute, MAXON_EXPAND_VA_ARGS, (Result<Int>), const InternedId& oldId, const InternedId& newId);
	PRIVATE_MAXON_SF_POINTER(DataDescriptionDefinitionDatabaseInterface_CheckUniqueAttributeName, CheckUniqueAttributeName, MAXON_EXPAND_VA_ARGS, (Result<Bool>), const InternedId& searchId);
	PRIVATE_MAXON_SF_POINTER(DataDescriptionDefinitionDatabaseInterface_UpdateDescription, UpdateDescription, MAXON_EXPAND_VA_ARGS, (Result<DataDescription>), const Id& databaseId, const Id& category, const LanguageRef& language, const IdAndVersion& dataType, DataDescriptionDefinition& descRef, Bool notifyParents);
	PRIVATE_MAXON_SF_POINTER(DataDescriptionDefinitionDatabaseInterface_RegisterDatabaseWithUrl, RegisterDatabaseWithUrl, MAXON_EXPAND_VA_ARGS, (Result<void>), const Id& databaseId, const Url& url, const CString& version);
	PRIVATE_MAXON_SF_POINTER(DataDescriptionDefinitionDatabaseInterface_RegisterDatabase, RegisterDatabase, MAXON_EXPAND_VA_ARGS, (Result<void>), const Id& databaseId, const DataDescriptionDefinitionDatabaseImplRef& ddb);
	PRIVATE_MAXON_SF_POINTER(DataDescriptionDefinitionDatabaseInterface_UnregisterDatabase, UnregisterDatabase, MAXON_EXPAND_VA_ARGS, (Result<void>), const Id& databaseId);
	PRIVATE_MAXON_SF_POINTER(DataDescriptionDefinitionDatabaseInterface_IsWritableDatabase, IsWritableDatabase, MAXON_EXPAND_VA_ARGS, (Bool), const Id& databaseId, const Id& languageId);
	PRIVATE_MAXON_SF_POINTER(DataDescriptionDefinitionDatabaseInterface_GetRegisteredDatabases, GetRegisteredDatabases, MAXON_EXPAND_VA_ARGS, (Result<BaseArray<Id>>));
	PRIVATE_MAXON_SF_POINTER(DataDescriptionDefinitionDatabaseInterface_BuildDescription, BuildDescription, MAXON_EXPAND_VA_ARGS, (Result<DataDescription>), const Id& category, const IdAndVersion& dataTypeId, const LanguageRef& language);
	PRIVATE_MAXON_SF_POINTER(DataDescriptionDefinitionDatabaseInterface_BuildDescription_1, BuildDescription, MAXON_EXPAND_VA_ARGS, (Result<DataDescription>), const Id& category, const LanguageRef& language, const IdAndVersion& descriptionId, const DataDescriptionDefinition& srcDefinition);
	PRIVATE_MAXON_SF_POINTER(DataDescriptionDefinitionDatabaseInterface_RegisterMessage, RegisterMessage, MAXON_EXPAND_VA_ARGS, (Result<void>), const Id& dataTypeId, const Id& attributeId, const Id& cmdId, const DescriptionMessageFunction& func);
	PRIVATE_MAXON_SF_POINTER(DataDescriptionDefinitionDatabaseInterface_RegisterValueChangedMessage, RegisterValueChangedMessage, MAXON_EXPAND_VA_ARGS, (Result<void>), const Id& dataTypeId, const Id& attributeId, const DescriptionMessageFunction& func);
	PRIVATE_MAXON_SF_POINTER(DataDescriptionDefinitionDatabaseInterface_FindNodeMessage, FindNodeMessage, MAXON_EXPAND_VA_ARGS, (DescriptionMessageFunction*), const Id& dataTypeId, const Id& attributeId, const Id& cmdId);
	PRIVATE_MAXON_SF_POINTER(DataDescriptionDefinitionDatabaseInterface_FindNodeValueChangedMessage, FindNodeValueChangedMessage, MAXON_EXPAND_VA_ARGS, (Result<Bool>), const Id& dataTypeId, const Id& attributeId, const ValueReceiver<DescriptionMessageFunction&>& receiver);
	PRIVATE_MAXON_SF_POINTER(DataDescriptionDefinitionDatabaseInterface_FixDatabaseProps, FixDatabaseProps, MAXON_EXPAND_VA_ARGS, (Result<void>), DBVERSION version, DataDictionary& entry);
	PRIVATE_MAXON_SF_POINTER(DataDescriptionDefinitionDatabaseInterface_ObservableSaveDatabase, ObservableSaveDatabase, MAXON_EXPAND_VA_ARGS, (maxon::ObservableRef<ObservableSaveDatabaseDelegate>), Bool create);
	PRIVATE_MAXON_SF_POINTER(DataDescriptionDefinitionDatabaseInterface_ObservableDatabaseRegistrationChange, ObservableDatabaseRegistrationChange, MAXON_EXPAND_VA_ARGS, (maxon::ObservableRef<ObservableDatabaseRegistrationChangeDelegate>), Bool create);
	template <typename IMPL> void Init()
	{
		DataDescriptionDefinitionDatabaseInterface_LoadDescription = DataDescriptionDefinitionDatabaseInterface_LoadDescription_GetPtr<IMPL>(true);
		DataDescriptionDefinitionDatabaseInterface_StoreDescription = DataDescriptionDefinitionDatabaseInterface_StoreDescription_GetPtr<IMPL>(true);
		DataDescriptionDefinitionDatabaseInterface_DeleteDescription = DataDescriptionDefinitionDatabaseInterface_DeleteDescription_GetPtr<IMPL>(true);
		DataDescriptionDefinitionDatabaseInterface_GetRegisteredDescriptions = DataDescriptionDefinitionDatabaseInterface_GetRegisteredDescriptions_GetPtr<IMPL>(true);
		DataDescriptionDefinitionDatabaseInterface_WriteDataBases = DataDescriptionDefinitionDatabaseInterface_WriteDataBases_GetPtr<IMPL>(true);
		DataDescriptionDefinitionDatabaseInterface_WriteUserChangedDataBases = DataDescriptionDefinitionDatabaseInterface_WriteUserChangedDataBases_GetPtr<IMPL>(true);
		DataDescriptionDefinitionDatabaseInterface_QueryNeedsWriteDataBases = DataDescriptionDefinitionDatabaseInterface_QueryNeedsWriteDataBases_GetPtr<IMPL>(true);
		DataDescriptionDefinitionDatabaseInterface_QueryNeedsWriteDataBasesForUserChanges = DataDescriptionDefinitionDatabaseInterface_QueryNeedsWriteDataBasesForUserChanges_GetPtr<IMPL>(true);
		DataDescriptionDefinitionDatabaseInterface_RenameId = DataDescriptionDefinitionDatabaseInterface_RenameId_GetPtr<IMPL>(true);
		DataDescriptionDefinitionDatabaseInterface_RenameAttribute = DataDescriptionDefinitionDatabaseInterface_RenameAttribute_GetPtr<IMPL>(true);
		DataDescriptionDefinitionDatabaseInterface_CheckUniqueAttributeName = DataDescriptionDefinitionDatabaseInterface_CheckUniqueAttributeName_GetPtr<IMPL>(true);
		DataDescriptionDefinitionDatabaseInterface_UpdateDescription = DataDescriptionDefinitionDatabaseInterface_UpdateDescription_GetPtr<IMPL>(true);
		DataDescriptionDefinitionDatabaseInterface_RegisterDatabaseWithUrl = DataDescriptionDefinitionDatabaseInterface_RegisterDatabaseWithUrl_GetPtr<IMPL>(true);
		DataDescriptionDefinitionDatabaseInterface_RegisterDatabase = DataDescriptionDefinitionDatabaseInterface_RegisterDatabase_GetPtr<IMPL>(true);
		DataDescriptionDefinitionDatabaseInterface_UnregisterDatabase = DataDescriptionDefinitionDatabaseInterface_UnregisterDatabase_GetPtr<IMPL>(true);
		DataDescriptionDefinitionDatabaseInterface_IsWritableDatabase = DataDescriptionDefinitionDatabaseInterface_IsWritableDatabase_GetPtr<IMPL>(true);
		DataDescriptionDefinitionDatabaseInterface_GetRegisteredDatabases = DataDescriptionDefinitionDatabaseInterface_GetRegisteredDatabases_GetPtr<IMPL>(true);
		DataDescriptionDefinitionDatabaseInterface_BuildDescription = DataDescriptionDefinitionDatabaseInterface_BuildDescription_GetPtr<IMPL>(true);
		DataDescriptionDefinitionDatabaseInterface_BuildDescription_1 = DataDescriptionDefinitionDatabaseInterface_BuildDescription_1_GetPtr<IMPL>(true);
		DataDescriptionDefinitionDatabaseInterface_RegisterMessage = DataDescriptionDefinitionDatabaseInterface_RegisterMessage_GetPtr<IMPL>(true);
		DataDescriptionDefinitionDatabaseInterface_RegisterValueChangedMessage = DataDescriptionDefinitionDatabaseInterface_RegisterValueChangedMessage_GetPtr<IMPL>(true);
		DataDescriptionDefinitionDatabaseInterface_FindNodeMessage = DataDescriptionDefinitionDatabaseInterface_FindNodeMessage_GetPtr<IMPL>(true);
		DataDescriptionDefinitionDatabaseInterface_FindNodeValueChangedMessage = DataDescriptionDefinitionDatabaseInterface_FindNodeValueChangedMessage_GetPtr<IMPL>(true);
		DataDescriptionDefinitionDatabaseInterface_FixDatabaseProps = DataDescriptionDefinitionDatabaseInterface_FixDatabaseProps_GetPtr<IMPL>(true);
		DataDescriptionDefinitionDatabaseInterface_ObservableSaveDatabase = DataDescriptionDefinitionDatabaseInterface_ObservableSaveDatabase_GetPtr<IMPL>(true);
		DataDescriptionDefinitionDatabaseInterface_ObservableDatabaseRegistrationChange = DataDescriptionDefinitionDatabaseInterface_ObservableDatabaseRegistrationChange_GetPtr<IMPL>(true);
	}
};

struct DataDescriptionDefinitionDatabaseInterface::Hxx2
{
	class Unresolved;
	template <typename S> class Wrapper
	{
	public:
		using Implementation = S;
		static Result<DataDescriptionDefinition> DataDescriptionDefinitionDatabaseInterface_LoadDescription(LOADDESCRIPTIONMODE mode, const Id& category, const LanguageRef& language, const IdAndVersion& dataType, Id* foundInDatabase) { return S::LoadDescription(mode, category, language, dataType, foundInDatabase); }
		static Result<void> DataDescriptionDefinitionDatabaseInterface_StoreDescription(const Id& databaseId, const Id& category, const LanguageRef& language, const IdAndVersion& dataType, const DataDescriptionDefinition& description, const DataDescriptionDefinition& overwrittenDescription, Bool usePendingSystem) { return S::StoreDescription(databaseId, category, language, dataType, description, overwrittenDescription, usePendingSystem); }
		static Result<Bool> DataDescriptionDefinitionDatabaseInterface_DeleteDescription(const Id& category, const LanguageRef& language, const IdAndVersion& dataType) { return S::DeleteDescription(category, language, dataType); }
		static Result<BaseArray<IdAndVersion>> DataDescriptionDefinitionDatabaseInterface_GetRegisteredDescriptions(const Id& databaseId, const Id& category, const LanguageRef& language) { return S::GetRegisteredDescriptions(databaseId, category, language); }
		static Result<void> DataDescriptionDefinitionDatabaseInterface_WriteDataBases() { return S::WriteDataBases(); }
		static Result<void> DataDescriptionDefinitionDatabaseInterface_WriteUserChangedDataBases() { return S::WriteUserChangedDataBases(); }
		static Bool DataDescriptionDefinitionDatabaseInterface_QueryNeedsWriteDataBases() { return S::QueryNeedsWriteDataBases(); }
		static Bool DataDescriptionDefinitionDatabaseInterface_QueryNeedsWriteDataBasesForUserChanges() { return S::QueryNeedsWriteDataBasesForUserChanges(); }
		static Result<Int> DataDescriptionDefinitionDatabaseInterface_RenameId(const Id& oldId, const Id& newId) { return S::RenameId(oldId, newId); }
		static Result<Int> DataDescriptionDefinitionDatabaseInterface_RenameAttribute(const InternedId& oldId, const InternedId& newId) { return S::RenameAttribute(oldId, newId); }
		static Result<Bool> DataDescriptionDefinitionDatabaseInterface_CheckUniqueAttributeName(const InternedId& searchId) { return S::CheckUniqueAttributeName(searchId); }
		static Result<DataDescription> DataDescriptionDefinitionDatabaseInterface_UpdateDescription(const Id& databaseId, const Id& category, const LanguageRef& language, const IdAndVersion& dataType, DataDescriptionDefinition& descRef, Bool notifyParents) { return S::UpdateDescription(databaseId, category, language, dataType, descRef, notifyParents); }
		static Result<void> DataDescriptionDefinitionDatabaseInterface_RegisterDatabaseWithUrl(const Id& databaseId, const Url& url, const CString& version) { return S::RegisterDatabaseWithUrl(databaseId, url, version); }
		static Result<void> DataDescriptionDefinitionDatabaseInterface_RegisterDatabase(const Id& databaseId, const DataDescriptionDefinitionDatabaseImplRef& ddb) { return S::RegisterDatabase(databaseId, ddb); }
		static Result<void> DataDescriptionDefinitionDatabaseInterface_UnregisterDatabase(const Id& databaseId) { return S::UnregisterDatabase(databaseId); }
		static Bool DataDescriptionDefinitionDatabaseInterface_IsWritableDatabase(const Id& databaseId, const Id& languageId) { return S::IsWritableDatabase(databaseId, languageId); }
		static Result<BaseArray<Id>> DataDescriptionDefinitionDatabaseInterface_GetRegisteredDatabases() { return S::GetRegisteredDatabases(); }
		static Result<DataDescription> DataDescriptionDefinitionDatabaseInterface_BuildDescription(const Id& category, const IdAndVersion& dataTypeId, const LanguageRef& language) { return S::BuildDescription(category, dataTypeId, language); }
		static Result<DataDescription> DataDescriptionDefinitionDatabaseInterface_BuildDescription_1(const Id& category, const LanguageRef& language, const IdAndVersion& descriptionId, const DataDescriptionDefinition& srcDefinition) { return S::BuildDescription(category, language, descriptionId, srcDefinition); }
		static Result<void> DataDescriptionDefinitionDatabaseInterface_RegisterMessage(const Id& dataTypeId, const Id& attributeId, const Id& cmdId, const DescriptionMessageFunction& func) { return S::RegisterMessage(dataTypeId, attributeId, cmdId, func); }
		static Result<void> DataDescriptionDefinitionDatabaseInterface_RegisterValueChangedMessage(const Id& dataTypeId, const Id& attributeId, const DescriptionMessageFunction& func) { return S::RegisterValueChangedMessage(dataTypeId, attributeId, func); }
		static DescriptionMessageFunction* DataDescriptionDefinitionDatabaseInterface_FindNodeMessage(const Id& dataTypeId, const Id& attributeId, const Id& cmdId) { return S::FindNodeMessage(dataTypeId, attributeId, cmdId); }
		static Result<Bool> DataDescriptionDefinitionDatabaseInterface_FindNodeValueChangedMessage(const Id& dataTypeId, const Id& attributeId, const ValueReceiver<DescriptionMessageFunction&>& receiver) { return S::FindNodeValueChangedMessage(dataTypeId, attributeId, receiver); }
		static Result<void> DataDescriptionDefinitionDatabaseInterface_FixDatabaseProps(DBVERSION version, DataDictionary& entry) { return S::FixDatabaseProps(version, entry); }
		static maxon::ObservableRef<ObservableSaveDatabaseDelegate> DataDescriptionDefinitionDatabaseInterface_ObservableSaveDatabase(Bool create) { return S::ObservableSaveDatabase(create); }
		static maxon::ObservableRef<ObservableDatabaseRegistrationChangeDelegate> DataDescriptionDefinitionDatabaseInterface_ObservableDatabaseRegistrationChange(Bool create) { return S::ObservableDatabaseRegistrationChange(create); }
	};

};
MAXON_ATTRIBUTE_FORCE_INLINE auto DataDescriptionDefinitionDatabaseInterface::LoadDescription(LOADDESCRIPTIONMODE mode, const Id& category, const LanguageRef& language, const IdAndVersion& dataType, Id* foundInDatabase) -> Result<DataDescriptionDefinition>
{
	return MTable::_instance.DataDescriptionDefinitionDatabaseInterface_LoadDescription(mode, category, language, dataType, foundInDatabase);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto DataDescriptionDefinitionDatabaseInterface::StoreDescription(const Id& databaseId, const Id& category, const LanguageRef& language, const IdAndVersion& dataType, const DataDescriptionDefinition& description, const DataDescriptionDefinition& overwrittenDescription, Bool usePendingSystem) -> Result<void>
{
	return MTable::_instance.DataDescriptionDefinitionDatabaseInterface_StoreDescription(databaseId, category, language, dataType, description, overwrittenDescription, usePendingSystem);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto DataDescriptionDefinitionDatabaseInterface::DeleteDescription(const Id& category, const LanguageRef& language, const IdAndVersion& dataType) -> Result<Bool>
{
	return MTable::_instance.DataDescriptionDefinitionDatabaseInterface_DeleteDescription(category, language, dataType);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto DataDescriptionDefinitionDatabaseInterface::GetRegisteredDescriptions(const Id& databaseId, const Id& category, const LanguageRef& language) -> Result<BaseArray<IdAndVersion>>
{
	return MTable::_instance.DataDescriptionDefinitionDatabaseInterface_GetRegisteredDescriptions(databaseId, category, language);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto DataDescriptionDefinitionDatabaseInterface::WriteDataBases() -> Result<void>
{
	return MTable::_instance.DataDescriptionDefinitionDatabaseInterface_WriteDataBases();
}
MAXON_ATTRIBUTE_FORCE_INLINE auto DataDescriptionDefinitionDatabaseInterface::WriteUserChangedDataBases() -> Result<void>
{
	return MTable::_instance.DataDescriptionDefinitionDatabaseInterface_WriteUserChangedDataBases();
}
MAXON_ATTRIBUTE_FORCE_INLINE auto DataDescriptionDefinitionDatabaseInterface::QueryNeedsWriteDataBases() -> Bool
{
	return MTable::_instance.DataDescriptionDefinitionDatabaseInterface_QueryNeedsWriteDataBases();
}
MAXON_ATTRIBUTE_FORCE_INLINE auto DataDescriptionDefinitionDatabaseInterface::QueryNeedsWriteDataBasesForUserChanges() -> Bool
{
	return MTable::_instance.DataDescriptionDefinitionDatabaseInterface_QueryNeedsWriteDataBasesForUserChanges();
}
MAXON_ATTRIBUTE_FORCE_INLINE auto DataDescriptionDefinitionDatabaseInterface::RenameId(const Id& oldId, const Id& newId) -> Result<Int>
{
	return MTable::_instance.DataDescriptionDefinitionDatabaseInterface_RenameId(oldId, newId);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto DataDescriptionDefinitionDatabaseInterface::RenameAttribute(const InternedId& oldId, const InternedId& newId) -> Result<Int>
{
	return MTable::_instance.DataDescriptionDefinitionDatabaseInterface_RenameAttribute(oldId, newId);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto DataDescriptionDefinitionDatabaseInterface::CheckUniqueAttributeName(const InternedId& searchId) -> Result<Bool>
{
	return MTable::_instance.DataDescriptionDefinitionDatabaseInterface_CheckUniqueAttributeName(searchId);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto DataDescriptionDefinitionDatabaseInterface::UpdateDescription(const Id& databaseId, const Id& category, const LanguageRef& language, const IdAndVersion& dataType, DataDescriptionDefinition& descRef, Bool notifyParents) -> Result<DataDescription>
{
	return MTable::_instance.DataDescriptionDefinitionDatabaseInterface_UpdateDescription(databaseId, category, language, dataType, descRef, notifyParents);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto DataDescriptionDefinitionDatabaseInterface::RegisterDatabaseWithUrl(const Id& databaseId, const Url& url, const CString& version) -> Result<void>
{
	return MTable::_instance.DataDescriptionDefinitionDatabaseInterface_RegisterDatabaseWithUrl(databaseId, url, version);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto DataDescriptionDefinitionDatabaseInterface::RegisterDatabase(const Id& databaseId, const DataDescriptionDefinitionDatabaseImplRef& ddb) -> Result<void>
{
	return MTable::_instance.DataDescriptionDefinitionDatabaseInterface_RegisterDatabase(databaseId, ddb);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto DataDescriptionDefinitionDatabaseInterface::UnregisterDatabase(const Id& databaseId) -> Result<void>
{
	return MTable::_instance.DataDescriptionDefinitionDatabaseInterface_UnregisterDatabase(databaseId);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto DataDescriptionDefinitionDatabaseInterface::IsWritableDatabase(const Id& databaseId, const Id& languageId) -> Bool
{
	return MTable::_instance.DataDescriptionDefinitionDatabaseInterface_IsWritableDatabase(databaseId, languageId);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto DataDescriptionDefinitionDatabaseInterface::GetRegisteredDatabases() -> Result<BaseArray<Id>>
{
	return MTable::_instance.DataDescriptionDefinitionDatabaseInterface_GetRegisteredDatabases();
}
MAXON_ATTRIBUTE_FORCE_INLINE auto DataDescriptionDefinitionDatabaseInterface::BuildDescription(const Id& category, const IdAndVersion& dataTypeId, const LanguageRef& language) -> Result<DataDescription>
{
	return MTable::_instance.DataDescriptionDefinitionDatabaseInterface_BuildDescription(category, dataTypeId, language);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto DataDescriptionDefinitionDatabaseInterface::BuildDescription(const Id& category, const LanguageRef& language, const IdAndVersion& descriptionId, const DataDescriptionDefinition& srcDefinition) -> Result<DataDescription>
{
	return MTable::_instance.DataDescriptionDefinitionDatabaseInterface_BuildDescription_1(category, language, descriptionId, srcDefinition);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto DataDescriptionDefinitionDatabaseInterface::RegisterMessage(const Id& dataTypeId, const Id& attributeId, const Id& cmdId, const DescriptionMessageFunction& func) -> Result<void>
{
	return MTable::_instance.DataDescriptionDefinitionDatabaseInterface_RegisterMessage(dataTypeId, attributeId, cmdId, func);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto DataDescriptionDefinitionDatabaseInterface::RegisterValueChangedMessage(const Id& dataTypeId, const Id& attributeId, const DescriptionMessageFunction& func) -> Result<void>
{
	return MTable::_instance.DataDescriptionDefinitionDatabaseInterface_RegisterValueChangedMessage(dataTypeId, attributeId, func);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto DataDescriptionDefinitionDatabaseInterface::FindNodeMessage(const Id& dataTypeId, const Id& attributeId, const Id& cmdId) -> DescriptionMessageFunction*
{
	return MTable::_instance.DataDescriptionDefinitionDatabaseInterface_FindNodeMessage(dataTypeId, attributeId, cmdId);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto DataDescriptionDefinitionDatabaseInterface::FindNodeValueChangedMessage(const Id& dataTypeId, const Id& attributeId, const ValueReceiver<DescriptionMessageFunction&>& receiver) -> Result<Bool>
{
	return MTable::_instance.DataDescriptionDefinitionDatabaseInterface_FindNodeValueChangedMessage(dataTypeId, attributeId, receiver);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto DataDescriptionDefinitionDatabaseInterface::FixDatabaseProps(DBVERSION version, DataDictionary& entry) -> Result<void>
{
	return MTable::_instance.DataDescriptionDefinitionDatabaseInterface_FixDatabaseProps(version, entry);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto DataDescriptionDefinitionDatabaseInterface::ObservableSaveDatabase(Bool create) -> maxon::ObservableRef<ObservableSaveDatabaseDelegate>
{
	return MTable::_instance.DataDescriptionDefinitionDatabaseInterface_ObservableSaveDatabase(create);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto DataDescriptionDefinitionDatabaseInterface::ObservableDatabaseRegistrationChange(Bool create) -> maxon::ObservableRef<ObservableDatabaseRegistrationChangeDelegate>
{
	return MTable::_instance.DataDescriptionDefinitionDatabaseInterface_ObservableDatabaseRegistrationChange(create);
}

#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT) && !defined(MAXON_DEPENDENCY_DISABLE_datadescriptiondefinitiondatabase)
#ifdef MAXON_USE_REGISTER_FUNCTION
MAXON_STATIC_STORAGE(maxon::EntityUse, s_ui_maxon_DataDescriptionDefinitionDatabaseInterface); \
MAXON_ATTRIBUTE_CONSTRUCTOR static void Register_s_ui_maxon_DataDescriptionDefinitionDatabaseInterface() { new (s_ui_maxon_DataDescriptionDefinitionDatabaseInterface) maxon::EntityUse(DataDescriptionDefinitionDatabaseInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/datadescriptiondefinitiondatabase.h", false); }
#else // !MAXON_USE_REGISTER_FUNCTION
static maxon::EntityUse s_ui_maxon_DataDescriptionDefinitionDatabaseInterface(DataDescriptionDefinitionDatabaseInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/datadescriptiondefinitiondatabase.h", false);
#endif // MAXON_USE_REGISTER_FUNCTION
#endif
#endif

#ifdef MAXON_COMPILER_GCC
	#pragma GCC diagnostic pop
#endif

#endif

