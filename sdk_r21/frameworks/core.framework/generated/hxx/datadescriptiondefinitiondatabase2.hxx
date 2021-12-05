
#ifndef DOXYGEN

#if defined MAXON_COMPILER_GCC
	#pragma GCC diagnostic push
	#if MAXON_COMPILER_GCC >= 600
		#pragma GCC diagnostic ignored "-Wmisleading-indentation"
	#endif
#endif

#if 1

struct DataDescriptionDefinitionDatabaseInterface::MTable
{
	static MTable _instance;
	static MTable _unresolvedInstance;
	static const maxon::Char* const _ids;
	static maxon::Bool InitUnresolved(maxon::NonvirtualInterfaceReference::UnresolvedAssembler assembler, MTable* tbl);
	static const maxon::NULL_RETURN_TYPE _returnTypes[];
	static const maxon::Bool HAS_NONSTATIC = false;
	Result<DataDescriptionDefinition> (*_DataDescriptionDefinitionDatabaseInterface_LoadDescription) (LOADDESCRIPTIONMODE mode, const Id& category, const LanguageRef& language, const IdAndVersion& dataType, Id* foundInDatabase);
	Result<void> (*_DataDescriptionDefinitionDatabaseInterface_StoreDescription) (const Id& databaseId, const Id& category, const LanguageRef& language, const IdAndVersion& dataType, const DataDescriptionDefinition& description, const DataDescriptionDefinition& overwrittenDescription, Bool usePendingSystem);
	Result<Bool> (*_DataDescriptionDefinitionDatabaseInterface_DeleteDescription) (const Id& category, const LanguageRef& language, const IdAndVersion& dataType);
	Result<BaseArray<IdAndVersion>> (*_DataDescriptionDefinitionDatabaseInterface_GetRegisteredDescriptions) (const Id& databaseId, const Id& category, const LanguageRef& language);
	Result<void> (*_DataDescriptionDefinitionDatabaseInterface_WriteDataBases) ();
	Bool (*_DataDescriptionDefinitionDatabaseInterface_QueryNeedsWriteDataBases) ();
	Result<Int> (*_DataDescriptionDefinitionDatabaseInterface_RenameId) (const Id& oldId, const Id& newId);
	Result<Int> (*_DataDescriptionDefinitionDatabaseInterface_RenameAttribute) (const InternedId& oldId, const InternedId& newId);
	Result<Bool> (*_DataDescriptionDefinitionDatabaseInterface_CheckUniqueAttributeName) (const InternedId& searchId);
	Result<DataDescription> (*_DataDescriptionDefinitionDatabaseInterface_UpdateDescription) (const Id& databaseId, const Id& category, const LanguageRef& language, const IdAndVersion& dataType, DataDescriptionDefinition& descRef, Bool notifyParents);
	Result<DataDescription> (*_DataDescriptionDefinitionDatabaseInterface_UpdateDescriptionI) (const Id& databaseId, const Id& category, const LanguageRef& language, DataDescriptionDefinition& descRef, const IdAndVersion& dataType);
	Result<void> (*_DataDescriptionDefinitionDatabaseInterface_RegisterDatabaseWithUrl) (const Id& databaseId, const Url& url);
	Result<void> (*_DataDescriptionDefinitionDatabaseInterface_RegisterDatabase) (const Id& databaseId, const DataDescriptionDefinitionDatabaseImplRef& ddb);
	Result<void> (*_DataDescriptionDefinitionDatabaseInterface_UnregisterDatabase) (const Id& databaseId);
	Bool (*_DataDescriptionDefinitionDatabaseInterface_IsWritableDatabase) (const Id& databaseId, const Id& languageId);
	Result<BaseArray<Id>> (*_DataDescriptionDefinitionDatabaseInterface_GetRegisteredDatabases) ();
	Result<DataDescription> (*_DataDescriptionDefinitionDatabaseInterface_BuildDescription) (const Id& category, const IdAndVersion& dataTypeId, const LanguageRef& language);
	Result<void> (*_DataDescriptionDefinitionDatabaseInterface_RegisterMessage) (const Id& dataTypeId, const Id& attributeId, const Id& cmdId, const DescriptionMessageFunction& func);
	DescriptionMessageFunction* (*_DataDescriptionDefinitionDatabaseInterface_FindNodeMessage) (const Id& dataTypeId, const Id& attributeId, const Id& cmdId);
	maxon::ObservableRef<ObservableSaveDatabaseDelegate> (*_DataDescriptionDefinitionDatabaseInterface_ObservableSaveDatabase) ();
	maxon::ObservableRef<ObservableDatabaseRegistrationChangeDelegate> (*_DataDescriptionDefinitionDatabaseInterface_ObservableDatabaseRegistrationChange) ();
	template <typename IMPL> void Init()
	{
		_DataDescriptionDefinitionDatabaseInterface_LoadDescription = &IMPL::_DataDescriptionDefinitionDatabaseInterface_LoadDescription;
		_DataDescriptionDefinitionDatabaseInterface_StoreDescription = &IMPL::_DataDescriptionDefinitionDatabaseInterface_StoreDescription;
		_DataDescriptionDefinitionDatabaseInterface_DeleteDescription = &IMPL::_DataDescriptionDefinitionDatabaseInterface_DeleteDescription;
		_DataDescriptionDefinitionDatabaseInterface_GetRegisteredDescriptions = &IMPL::_DataDescriptionDefinitionDatabaseInterface_GetRegisteredDescriptions;
		_DataDescriptionDefinitionDatabaseInterface_WriteDataBases = &IMPL::_DataDescriptionDefinitionDatabaseInterface_WriteDataBases;
		_DataDescriptionDefinitionDatabaseInterface_QueryNeedsWriteDataBases = &IMPL::_DataDescriptionDefinitionDatabaseInterface_QueryNeedsWriteDataBases;
		_DataDescriptionDefinitionDatabaseInterface_RenameId = &IMPL::_DataDescriptionDefinitionDatabaseInterface_RenameId;
		_DataDescriptionDefinitionDatabaseInterface_RenameAttribute = &IMPL::_DataDescriptionDefinitionDatabaseInterface_RenameAttribute;
		_DataDescriptionDefinitionDatabaseInterface_CheckUniqueAttributeName = &IMPL::_DataDescriptionDefinitionDatabaseInterface_CheckUniqueAttributeName;
		_DataDescriptionDefinitionDatabaseInterface_UpdateDescription = &IMPL::_DataDescriptionDefinitionDatabaseInterface_UpdateDescription;
		_DataDescriptionDefinitionDatabaseInterface_UpdateDescriptionI = &IMPL::_DataDescriptionDefinitionDatabaseInterface_UpdateDescriptionI;
		_DataDescriptionDefinitionDatabaseInterface_RegisterDatabaseWithUrl = &IMPL::_DataDescriptionDefinitionDatabaseInterface_RegisterDatabaseWithUrl;
		_DataDescriptionDefinitionDatabaseInterface_RegisterDatabase = &IMPL::_DataDescriptionDefinitionDatabaseInterface_RegisterDatabase;
		_DataDescriptionDefinitionDatabaseInterface_UnregisterDatabase = &IMPL::_DataDescriptionDefinitionDatabaseInterface_UnregisterDatabase;
		_DataDescriptionDefinitionDatabaseInterface_IsWritableDatabase = &IMPL::_DataDescriptionDefinitionDatabaseInterface_IsWritableDatabase;
		_DataDescriptionDefinitionDatabaseInterface_GetRegisteredDatabases = &IMPL::_DataDescriptionDefinitionDatabaseInterface_GetRegisteredDatabases;
		_DataDescriptionDefinitionDatabaseInterface_BuildDescription = &IMPL::_DataDescriptionDefinitionDatabaseInterface_BuildDescription;
		_DataDescriptionDefinitionDatabaseInterface_RegisterMessage = &IMPL::_DataDescriptionDefinitionDatabaseInterface_RegisterMessage;
		_DataDescriptionDefinitionDatabaseInterface_FindNodeMessage = &IMPL::_DataDescriptionDefinitionDatabaseInterface_FindNodeMessage;
		_DataDescriptionDefinitionDatabaseInterface_ObservableSaveDatabase = &IMPL::_DataDescriptionDefinitionDatabaseInterface_ObservableSaveDatabase;
		_DataDescriptionDefinitionDatabaseInterface_ObservableDatabaseRegistrationChange = &IMPL::_DataDescriptionDefinitionDatabaseInterface_ObservableDatabaseRegistrationChange;
	}
};

struct DataDescriptionDefinitionDatabaseInterface::Hxx2
{
	class Unresolved;
	template <typename C> class Wrapper
	{
	public:
	static Result<DataDescriptionDefinition> _DataDescriptionDefinitionDatabaseInterface_LoadDescription(LOADDESCRIPTIONMODE mode, const Id& category, const LanguageRef& language, const IdAndVersion& dataType, Id* foundInDatabase) { return C::LoadDescription(mode, category, language, dataType, foundInDatabase); }
	static Result<void> _DataDescriptionDefinitionDatabaseInterface_StoreDescription(const Id& databaseId, const Id& category, const LanguageRef& language, const IdAndVersion& dataType, const DataDescriptionDefinition& description, const DataDescriptionDefinition& overwrittenDescription, Bool usePendingSystem) { return C::StoreDescription(databaseId, category, language, dataType, description, overwrittenDescription, usePendingSystem); }
	static Result<Bool> _DataDescriptionDefinitionDatabaseInterface_DeleteDescription(const Id& category, const LanguageRef& language, const IdAndVersion& dataType) { return C::DeleteDescription(category, language, dataType); }
	static Result<BaseArray<IdAndVersion>> _DataDescriptionDefinitionDatabaseInterface_GetRegisteredDescriptions(const Id& databaseId, const Id& category, const LanguageRef& language) { return C::GetRegisteredDescriptions(databaseId, category, language); }
	static Result<void> _DataDescriptionDefinitionDatabaseInterface_WriteDataBases() { return C::WriteDataBases(); }
	static Bool _DataDescriptionDefinitionDatabaseInterface_QueryNeedsWriteDataBases() { return C::QueryNeedsWriteDataBases(); }
	static Result<Int> _DataDescriptionDefinitionDatabaseInterface_RenameId(const Id& oldId, const Id& newId) { return C::RenameId(oldId, newId); }
	static Result<Int> _DataDescriptionDefinitionDatabaseInterface_RenameAttribute(const InternedId& oldId, const InternedId& newId) { return C::RenameAttribute(oldId, newId); }
	static Result<Bool> _DataDescriptionDefinitionDatabaseInterface_CheckUniqueAttributeName(const InternedId& searchId) { return C::CheckUniqueAttributeName(searchId); }
	static Result<DataDescription> _DataDescriptionDefinitionDatabaseInterface_UpdateDescription(const Id& databaseId, const Id& category, const LanguageRef& language, const IdAndVersion& dataType, DataDescriptionDefinition& descRef, Bool notifyParents) { return C::UpdateDescription(databaseId, category, language, dataType, descRef, notifyParents); }
	static Result<DataDescription> _DataDescriptionDefinitionDatabaseInterface_UpdateDescriptionI(const Id& databaseId, const Id& category, const LanguageRef& language, DataDescriptionDefinition& descRef, const IdAndVersion& dataType) { return C::UpdateDescriptionI(databaseId, category, language, descRef, dataType); }
	static Result<void> _DataDescriptionDefinitionDatabaseInterface_RegisterDatabaseWithUrl(const Id& databaseId, const Url& url) { return C::RegisterDatabaseWithUrl(databaseId, url); }
	static Result<void> _DataDescriptionDefinitionDatabaseInterface_RegisterDatabase(const Id& databaseId, const DataDescriptionDefinitionDatabaseImplRef& ddb) { return C::RegisterDatabase(databaseId, ddb); }
	static Result<void> _DataDescriptionDefinitionDatabaseInterface_UnregisterDatabase(const Id& databaseId) { return C::UnregisterDatabase(databaseId); }
	static Bool _DataDescriptionDefinitionDatabaseInterface_IsWritableDatabase(const Id& databaseId, const Id& languageId) { return C::IsWritableDatabase(databaseId, languageId); }
	static Result<BaseArray<Id>> _DataDescriptionDefinitionDatabaseInterface_GetRegisteredDatabases() { return C::GetRegisteredDatabases(); }
	static Result<DataDescription> _DataDescriptionDefinitionDatabaseInterface_BuildDescription(const Id& category, const IdAndVersion& dataTypeId, const LanguageRef& language) { return C::BuildDescription(category, dataTypeId, language); }
	static Result<void> _DataDescriptionDefinitionDatabaseInterface_RegisterMessage(const Id& dataTypeId, const Id& attributeId, const Id& cmdId, const DescriptionMessageFunction& func) { return C::RegisterMessage(dataTypeId, attributeId, cmdId, func); }
	static DescriptionMessageFunction* _DataDescriptionDefinitionDatabaseInterface_FindNodeMessage(const Id& dataTypeId, const Id& attributeId, const Id& cmdId) { return C::FindNodeMessage(dataTypeId, attributeId, cmdId); }
	static maxon::ObservableRef<ObservableSaveDatabaseDelegate> _DataDescriptionDefinitionDatabaseInterface_ObservableSaveDatabase() { return C::ObservableSaveDatabase(); }
	static maxon::ObservableRef<ObservableDatabaseRegistrationChangeDelegate> _DataDescriptionDefinitionDatabaseInterface_ObservableDatabaseRegistrationChange() { return C::ObservableDatabaseRegistrationChange(); }
	};

};
MAXON_ATTRIBUTE_FORCE_INLINE auto DataDescriptionDefinitionDatabaseInterface::LoadDescription(LOADDESCRIPTIONMODE mode, const Id& category, const LanguageRef& language, const IdAndVersion& dataType, Id* foundInDatabase) -> Result<DataDescriptionDefinition>
{
	return MTable::_instance._DataDescriptionDefinitionDatabaseInterface_LoadDescription(mode, category, language, dataType, foundInDatabase);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto DataDescriptionDefinitionDatabaseInterface::StoreDescription(const Id& databaseId, const Id& category, const LanguageRef& language, const IdAndVersion& dataType, const DataDescriptionDefinition& description, const DataDescriptionDefinition& overwrittenDescription, Bool usePendingSystem) -> Result<void>
{
	return MTable::_instance._DataDescriptionDefinitionDatabaseInterface_StoreDescription(databaseId, category, language, dataType, description, overwrittenDescription, usePendingSystem);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto DataDescriptionDefinitionDatabaseInterface::DeleteDescription(const Id& category, const LanguageRef& language, const IdAndVersion& dataType) -> Result<Bool>
{
	return MTable::_instance._DataDescriptionDefinitionDatabaseInterface_DeleteDescription(category, language, dataType);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto DataDescriptionDefinitionDatabaseInterface::GetRegisteredDescriptions(const Id& databaseId, const Id& category, const LanguageRef& language) -> Result<BaseArray<IdAndVersion>>
{
	return MTable::_instance._DataDescriptionDefinitionDatabaseInterface_GetRegisteredDescriptions(databaseId, category, language);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto DataDescriptionDefinitionDatabaseInterface::WriteDataBases() -> Result<void>
{
	return MTable::_instance._DataDescriptionDefinitionDatabaseInterface_WriteDataBases();
}
MAXON_ATTRIBUTE_FORCE_INLINE auto DataDescriptionDefinitionDatabaseInterface::QueryNeedsWriteDataBases() -> Bool
{
	return MTable::_instance._DataDescriptionDefinitionDatabaseInterface_QueryNeedsWriteDataBases();
}
MAXON_ATTRIBUTE_FORCE_INLINE auto DataDescriptionDefinitionDatabaseInterface::RenameId(const Id& oldId, const Id& newId) -> Result<Int>
{
	return MTable::_instance._DataDescriptionDefinitionDatabaseInterface_RenameId(oldId, newId);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto DataDescriptionDefinitionDatabaseInterface::RenameAttribute(const InternedId& oldId, const InternedId& newId) -> Result<Int>
{
	return MTable::_instance._DataDescriptionDefinitionDatabaseInterface_RenameAttribute(oldId, newId);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto DataDescriptionDefinitionDatabaseInterface::CheckUniqueAttributeName(const InternedId& searchId) -> Result<Bool>
{
	return MTable::_instance._DataDescriptionDefinitionDatabaseInterface_CheckUniqueAttributeName(searchId);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto DataDescriptionDefinitionDatabaseInterface::UpdateDescription(const Id& databaseId, const Id& category, const LanguageRef& language, const IdAndVersion& dataType, DataDescriptionDefinition& descRef, Bool notifyParents) -> Result<DataDescription>
{
	return MTable::_instance._DataDescriptionDefinitionDatabaseInterface_UpdateDescription(databaseId, category, language, dataType, descRef, notifyParents);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto DataDescriptionDefinitionDatabaseInterface::UpdateDescriptionI(const Id& databaseId, const Id& category, const LanguageRef& language, DataDescriptionDefinition& descRef, const IdAndVersion& dataType) -> Result<DataDescription>
{
	return MTable::_instance._DataDescriptionDefinitionDatabaseInterface_UpdateDescriptionI(databaseId, category, language, descRef, dataType);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto DataDescriptionDefinitionDatabaseInterface::RegisterDatabaseWithUrl(const Id& databaseId, const Url& url) -> Result<void>
{
	return MTable::_instance._DataDescriptionDefinitionDatabaseInterface_RegisterDatabaseWithUrl(databaseId, url);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto DataDescriptionDefinitionDatabaseInterface::RegisterDatabase(const Id& databaseId, const DataDescriptionDefinitionDatabaseImplRef& ddb) -> Result<void>
{
	return MTable::_instance._DataDescriptionDefinitionDatabaseInterface_RegisterDatabase(databaseId, ddb);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto DataDescriptionDefinitionDatabaseInterface::UnregisterDatabase(const Id& databaseId) -> Result<void>
{
	return MTable::_instance._DataDescriptionDefinitionDatabaseInterface_UnregisterDatabase(databaseId);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto DataDescriptionDefinitionDatabaseInterface::IsWritableDatabase(const Id& databaseId, const Id& languageId) -> Bool
{
	return MTable::_instance._DataDescriptionDefinitionDatabaseInterface_IsWritableDatabase(databaseId, languageId);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto DataDescriptionDefinitionDatabaseInterface::GetRegisteredDatabases() -> Result<BaseArray<Id>>
{
	return MTable::_instance._DataDescriptionDefinitionDatabaseInterface_GetRegisteredDatabases();
}
MAXON_ATTRIBUTE_FORCE_INLINE auto DataDescriptionDefinitionDatabaseInterface::BuildDescription(const Id& category, const IdAndVersion& dataTypeId, const LanguageRef& language) -> Result<DataDescription>
{
	return MTable::_instance._DataDescriptionDefinitionDatabaseInterface_BuildDescription(category, dataTypeId, language);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto DataDescriptionDefinitionDatabaseInterface::RegisterMessage(const Id& dataTypeId, const Id& attributeId, const Id& cmdId, const DescriptionMessageFunction& func) -> Result<void>
{
	return MTable::_instance._DataDescriptionDefinitionDatabaseInterface_RegisterMessage(dataTypeId, attributeId, cmdId, func);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto DataDescriptionDefinitionDatabaseInterface::FindNodeMessage(const Id& dataTypeId, const Id& attributeId, const Id& cmdId) -> DescriptionMessageFunction*
{
	return MTable::_instance._DataDescriptionDefinitionDatabaseInterface_FindNodeMessage(dataTypeId, attributeId, cmdId);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto DataDescriptionDefinitionDatabaseInterface::ObservableSaveDatabase() -> maxon::ObservableRef<ObservableSaveDatabaseDelegate>
{
	return MTable::_instance._DataDescriptionDefinitionDatabaseInterface_ObservableSaveDatabase();
}
MAXON_ATTRIBUTE_FORCE_INLINE auto DataDescriptionDefinitionDatabaseInterface::ObservableDatabaseRegistrationChange() -> maxon::ObservableRef<ObservableDatabaseRegistrationChangeDelegate>
{
	return MTable::_instance._DataDescriptionDefinitionDatabaseInterface_ObservableDatabaseRegistrationChange();
}

#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT)
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

