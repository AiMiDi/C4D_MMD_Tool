#if 1
namespace maxon
{
	namespace enum27
	{
		enum class DESCRIPTIONMESSAGECHECKFLAGS
		{
			NONE = 0,							///< no flags
			ENABLED = 1 << 0,			///< menu entry should be enable.
			VISIBLE = 1 << 1,			///< visible menu entry is visible
			CHECKED = 1 << 2,			///< menu entry is checked with a check mark symbol.
			SORTSUBMENU = 1 << 3, ///< true to sort sub menu entries
		} ;
		static const maxon::UInt64 DESCRIPTIONMESSAGECHECKFLAGS_values[] = {maxon::UInt64(enum27::DESCRIPTIONMESSAGECHECKFLAGS::NONE), maxon::UInt64(enum27::DESCRIPTIONMESSAGECHECKFLAGS::ENABLED), maxon::UInt64(enum27::DESCRIPTIONMESSAGECHECKFLAGS::VISIBLE), maxon::UInt64(enum27::DESCRIPTIONMESSAGECHECKFLAGS::CHECKED), maxon::UInt64(enum27::DESCRIPTIONMESSAGECHECKFLAGS::SORTSUBMENU)};
		static const maxon::EnumInfo DESCRIPTIONMESSAGECHECKFLAGS_info{"DESCRIPTIONMESSAGECHECKFLAGS", SIZEOF(DESCRIPTIONMESSAGECHECKFLAGS), true, "NONE\0ENABLED\0VISIBLE\0CHECKED\0SORTSUBMENU\0", DESCRIPTIONMESSAGECHECKFLAGS_values, std::extent<decltype(DESCRIPTIONMESSAGECHECKFLAGS_values)>::value};
	}
	const maxon::EnumInfo& PrivateGetEnumInfo_DESCRIPTIONMESSAGECHECKFLAGS27(){ return enum27::DESCRIPTIONMESSAGECHECKFLAGS_info; }
	PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(DT_DescriptionMessageCall,, "net.maxon.datatype.descriptionmessagecall");
	namespace enum81
	{
		enum class LOADDESCRIPTIONMODE
		{
			COMPLETE,			///< returns the complete description
			OVERWRITTEN,	///< returns the data description editor description with overwritten parameters.
		} ;
		static const maxon::UInt64 LOADDESCRIPTIONMODE_values[] = {maxon::UInt64(enum81::LOADDESCRIPTIONMODE::COMPLETE), maxon::UInt64(enum81::LOADDESCRIPTIONMODE::OVERWRITTEN)};
		static const maxon::EnumInfo LOADDESCRIPTIONMODE_info{"LOADDESCRIPTIONMODE", SIZEOF(LOADDESCRIPTIONMODE), false, "COMPLETE\0OVERWRITTEN\0", LOADDESCRIPTIONMODE_values, std::extent<decltype(LOADDESCRIPTIONMODE_values)>::value};
	}
	const maxon::EnumInfo& PrivateGetEnumInfo_LOADDESCRIPTIONMODE81(){ return enum81::LOADDESCRIPTIONMODE_info; }
	const maxon::Char* const DataDescriptionDefinitionDatabaseInterface::MTable::_ids = 
		"LoadDescription@addab36457927282\0" // Result<DataDescriptionDefinition> LoadDescription(LOADDESCRIPTIONMODE mode, const Id& category, const LanguageRef& language, const IdAndVersion& dataType, Id* foundInDatabase)
		"StoreDescription@e5f51d6463381ebd\0" // Result<void> StoreDescription(const Id& databaseId, const Id& category, const LanguageRef& language, const IdAndVersion& dataType, const DataDescriptionDefinition& description, const DataDescriptionDefinition& overwrittenDescription, Bool usePendingSystem)
		"DeleteDescription@bc38fe0a0922d689\0" // Result<Bool> DeleteDescription(const Id& category, const LanguageRef& language, const IdAndVersion& dataType)
		"GetRegisteredDescriptions@632cb1f538a78388\0" // Result<BaseArray<IdAndVersion>> GetRegisteredDescriptions(const Id& databaseId, const Id& category, const LanguageRef& language)
		"WriteDataBases@a0cff72f181cfa62\0" // Result<void> WriteDataBases()
		"QueryNeedsWriteDataBases@12e73654ffd67c7b\0" // Bool QueryNeedsWriteDataBases()
		"RenameId@297425d505a20073\0" // Result<Int> RenameId(const Id& oldId, const Id& newId)
		"RenameAttribute@af961873425486cb\0" // Result<Int> RenameAttribute(const InternedId& oldId, const InternedId& newId)
		"CheckUniqueAttributeName@dc6d74c33b96d8f9\0" // Result<Bool> CheckUniqueAttributeName(const InternedId& searchId)
		"UpdateDescription@5cd3b5e8d21e20ca\0" // Result<DataDescription> UpdateDescription(const Id& databaseId, const Id& category, const LanguageRef& language, const IdAndVersion& dataType, DataDescriptionDefinition& descRef, Bool notifyParents)
		"UpdateDescriptionI@7e173219459b76ae\0" // Result<DataDescription> UpdateDescriptionI(const Id& databaseId, const Id& category, const LanguageRef& language, DataDescriptionDefinition& descRef, const IdAndVersion& dataType)
		"RegisterDatabaseWithUrl@52e3944895ac83ec\0" // Result<void> RegisterDatabaseWithUrl(const Id& databaseId, const Url& url)
		"RegisterDatabase@f6c4b9356f7d3428\0" // Result<void> RegisterDatabase(const Id& databaseId, const DataDescriptionDefinitionDatabaseImplRef& ddb)
		"UnregisterDatabase@fced3ac458970392\0" // Result<void> UnregisterDatabase(const Id& databaseId)
		"IsWritableDatabase@6c190c9d2571de9b\0" // Bool IsWritableDatabase(const Id& databaseId, const Id& languageId)
		"GetRegisteredDatabases@164fd43e2bd6da99\0" // Result<BaseArray<Id>> GetRegisteredDatabases()
		"BuildDescription@39a48e2813a0d91\0" // Result<DataDescription> BuildDescription(const Id& category, const IdAndVersion& dataTypeId, const LanguageRef& language)
		"RegisterMessage@f56f8613c320d1d4\0" // Result<void> RegisterMessage(const Id& dataTypeId, const Id& attributeId, const Id& cmdId, const DescriptionMessageFunction& func)
		"FindNodeMessage@af9ddbde2a8248e4\0" // DescriptionMessageFunction* FindNodeMessage(const Id& dataTypeId, const Id& attributeId, const Id& cmdId)
		"FixDatabaseProps@2735755406090f24\0" // Result<void> FixDatabaseProps(DBVERSION version, DataDictionary& entry)
		"ObservableSaveDatabase@9c542ab47f94e668\0" // maxon::ObservableRef<ObservableSaveDatabaseDelegate> ObservableSaveDatabase()
		"ObservableDatabaseRegistrationChange@b5ca13f31e263f28\0" // maxon::ObservableRef<ObservableDatabaseRegistrationChangeDelegate> ObservableDatabaseRegistrationChange()
	"";
	MAXON_WARNING_PUSH
	MAXON_WARNING_DISABLE_DEPRECATED
	class DataDescriptionDefinitionDatabaseInterface::Hxx2::Unresolved : public DataDescriptionDefinitionDatabaseInterface
	{
	public:
		static const Unresolved* Get(const DataDescriptionDefinitionDatabaseInterface* o) { return (const Unresolved*) o; }
		static Unresolved* Get(DataDescriptionDefinitionDatabaseInterface* o) { return (Unresolved*) o; }
		static Result<DataDescriptionDefinition> LoadDescription(LOADDESCRIPTIONMODE mode, const Id& category, const LanguageRef& language, const IdAndVersion& dataType, Id* foundInDatabase) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return DataDescriptionDefinitionDatabaseInterface::LoadDescription(mode, category, language, dataType, foundInDatabase); return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::UNRESOLVED);}
		static Result<void> StoreDescription(const Id& databaseId, const Id& category, const LanguageRef& language, const IdAndVersion& dataType, const DataDescriptionDefinition& description, const DataDescriptionDefinition& overwrittenDescription, Bool usePendingSystem) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return DataDescriptionDefinitionDatabaseInterface::StoreDescription(databaseId, category, language, dataType, description, overwrittenDescription, usePendingSystem); return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::UNRESOLVED);}
		static Result<Bool> DeleteDescription(const Id& category, const LanguageRef& language, const IdAndVersion& dataType) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return DataDescriptionDefinitionDatabaseInterface::DeleteDescription(category, language, dataType); return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::UNRESOLVED);}
		static Result<BaseArray<IdAndVersion>> GetRegisteredDescriptions(const Id& databaseId, const Id& category, const LanguageRef& language) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return DataDescriptionDefinitionDatabaseInterface::GetRegisteredDescriptions(databaseId, category, language); return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::UNRESOLVED);}
		static Result<void> WriteDataBases() { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return DataDescriptionDefinitionDatabaseInterface::WriteDataBases(); return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::UNRESOLVED);}
		static Bool QueryNeedsWriteDataBases() { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return DataDescriptionDefinitionDatabaseInterface::QueryNeedsWriteDataBases(); return maxon::PrivateLogNullptrError(false);}
		static Result<Int> RenameId(const Id& oldId, const Id& newId) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return DataDescriptionDefinitionDatabaseInterface::RenameId(oldId, newId); return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::UNRESOLVED);}
		static Result<Int> RenameAttribute(const InternedId& oldId, const InternedId& newId) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return DataDescriptionDefinitionDatabaseInterface::RenameAttribute(oldId, newId); return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::UNRESOLVED);}
		static Result<Bool> CheckUniqueAttributeName(const InternedId& searchId) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return DataDescriptionDefinitionDatabaseInterface::CheckUniqueAttributeName(searchId); return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::UNRESOLVED);}
		static Result<DataDescription> UpdateDescription(const Id& databaseId, const Id& category, const LanguageRef& language, const IdAndVersion& dataType, DataDescriptionDefinition& descRef, Bool notifyParents) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return DataDescriptionDefinitionDatabaseInterface::UpdateDescription(databaseId, category, language, dataType, descRef, notifyParents); return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::UNRESOLVED);}
		static Result<DataDescription> UpdateDescriptionI(const Id& databaseId, const Id& category, const LanguageRef& language, DataDescriptionDefinition& descRef, const IdAndVersion& dataType) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return DataDescriptionDefinitionDatabaseInterface::UpdateDescriptionI(databaseId, category, language, descRef, dataType); return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::UNRESOLVED);}
		static Result<void> RegisterDatabaseWithUrl(const Id& databaseId, const Url& url) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return DataDescriptionDefinitionDatabaseInterface::RegisterDatabaseWithUrl(databaseId, url); return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::UNRESOLVED);}
		static Result<void> RegisterDatabase(const Id& databaseId, const DataDescriptionDefinitionDatabaseImplRef& ddb) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return DataDescriptionDefinitionDatabaseInterface::RegisterDatabase(databaseId, ddb); return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::UNRESOLVED);}
		static Result<void> UnregisterDatabase(const Id& databaseId) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return DataDescriptionDefinitionDatabaseInterface::UnregisterDatabase(databaseId); return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::UNRESOLVED);}
		static Bool IsWritableDatabase(const Id& databaseId, const Id& languageId) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return DataDescriptionDefinitionDatabaseInterface::IsWritableDatabase(databaseId, languageId); return maxon::PrivateLogNullptrError(false);}
		static Result<BaseArray<Id>> GetRegisteredDatabases() { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return DataDescriptionDefinitionDatabaseInterface::GetRegisteredDatabases(); return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::UNRESOLVED);}
		static Result<DataDescription> BuildDescription(const Id& category, const IdAndVersion& dataTypeId, const LanguageRef& language) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return DataDescriptionDefinitionDatabaseInterface::BuildDescription(category, dataTypeId, language); return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::UNRESOLVED);}
		static Result<void> RegisterMessage(const Id& dataTypeId, const Id& attributeId, const Id& cmdId, const DescriptionMessageFunction& func) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return DataDescriptionDefinitionDatabaseInterface::RegisterMessage(dataTypeId, attributeId, cmdId, func); return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::UNRESOLVED);}
		static DescriptionMessageFunction* FindNodeMessage(const Id& dataTypeId, const Id& attributeId, const Id& cmdId) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return DataDescriptionDefinitionDatabaseInterface::FindNodeMessage(dataTypeId, attributeId, cmdId); return nullptr;}
		static Result<void> FixDatabaseProps(DBVERSION version, DataDictionary& entry) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return DataDescriptionDefinitionDatabaseInterface::FixDatabaseProps(version, entry); return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::UNRESOLVED);}
		static maxon::ObservableRef<ObservableSaveDatabaseDelegate> ObservableSaveDatabase() { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return DataDescriptionDefinitionDatabaseInterface::ObservableSaveDatabase(); return maxon::ObservableRef<ObservableSaveDatabaseDelegate>::NullValue();}
		static maxon::ObservableRef<ObservableDatabaseRegistrationChangeDelegate> ObservableDatabaseRegistrationChange() { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return DataDescriptionDefinitionDatabaseInterface::ObservableDatabaseRegistrationChange(); return maxon::ObservableRef<ObservableDatabaseRegistrationChangeDelegate>::NullValue();}
	};
	MAXON_WARNING_POP
#ifdef PRIVATE_MAXON_ASSEMBLE_UNRESOLVED
	const maxon::NULL_RETURN_TYPE DataDescriptionDefinitionDatabaseInterface::MTable::_returnTypes[] = 
	{
		maxon::details::NullReturnType<Result<DataDescriptionDefinition>>::value,
		maxon::details::NullReturnType<Result<void>>::value,
		maxon::details::NullReturnType<Result<Bool>>::value,
		maxon::details::NullReturnType<Result<BaseArray<IdAndVersion>>>::value,
		maxon::details::NullReturnType<Result<void>>::value,
		maxon::details::NullReturnType<Bool>::value,
		maxon::details::NullReturnType<Result<Int>>::value,
		maxon::details::NullReturnType<Result<Int>>::value,
		maxon::details::NullReturnType<Result<Bool>>::value,
		maxon::details::NullReturnType<Result<DataDescription>>::value,
		maxon::details::NullReturnType<Result<DataDescription>>::value,
		maxon::details::NullReturnType<Result<void>>::value,
		maxon::details::NullReturnType<Result<void>>::value,
		maxon::details::NullReturnType<Result<void>>::value,
		maxon::details::NullReturnType<Bool>::value,
		maxon::details::NullReturnType<Result<BaseArray<Id>>>::value,
		maxon::details::NullReturnType<Result<DataDescription>>::value,
		maxon::details::NullReturnType<Result<void>>::value,
		maxon::details::NullReturnType<DescriptionMessageFunction*>::value,
		maxon::details::NullReturnType<Result<void>>::value,
		maxon::details::NullReturnType<maxon::ObservableRef<ObservableSaveDatabaseDelegate>>::value,
		maxon::details::NullReturnType<maxon::ObservableRef<ObservableDatabaseRegistrationChangeDelegate>>::value,
		maxon::NULL_RETURN_TYPE::OTHER
	};
#endif
	maxon::Bool DataDescriptionDefinitionDatabaseInterface::MTable::InitUnresolved(maxon::NonvirtualInterfaceReference::UnresolvedAssembler assembler, MTable* tbl)
	{
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<DataDescriptionDefinition>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_DataDescriptionDefinitionDatabaseInterface_LoadDescription = &Hxx2::Wrapper<Hxx2::Unresolved>::_DataDescriptionDefinitionDatabaseInterface_LoadDescription;
		#else
		tbl->_DataDescriptionDefinitionDatabaseInterface_LoadDescription = &Hxx2::Wrapper<Hxx2::Unresolved>::_DataDescriptionDefinitionDatabaseInterface_LoadDescription;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<void>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_DataDescriptionDefinitionDatabaseInterface_StoreDescription = &Hxx2::Wrapper<Hxx2::Unresolved>::_DataDescriptionDefinitionDatabaseInterface_StoreDescription;
		#else
		tbl->_DataDescriptionDefinitionDatabaseInterface_StoreDescription = &Hxx2::Wrapper<Hxx2::Unresolved>::_DataDescriptionDefinitionDatabaseInterface_StoreDescription;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<Bool>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_DataDescriptionDefinitionDatabaseInterface_DeleteDescription = &Hxx2::Wrapper<Hxx2::Unresolved>::_DataDescriptionDefinitionDatabaseInterface_DeleteDescription;
		#else
		tbl->_DataDescriptionDefinitionDatabaseInterface_DeleteDescription = &Hxx2::Wrapper<Hxx2::Unresolved>::_DataDescriptionDefinitionDatabaseInterface_DeleteDescription;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<BaseArray<IdAndVersion>>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_DataDescriptionDefinitionDatabaseInterface_GetRegisteredDescriptions = &Hxx2::Wrapper<Hxx2::Unresolved>::_DataDescriptionDefinitionDatabaseInterface_GetRegisteredDescriptions;
		#else
		tbl->_DataDescriptionDefinitionDatabaseInterface_GetRegisteredDescriptions = &Hxx2::Wrapper<Hxx2::Unresolved>::_DataDescriptionDefinitionDatabaseInterface_GetRegisteredDescriptions;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<void>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_DataDescriptionDefinitionDatabaseInterface_WriteDataBases = &Hxx2::Wrapper<Hxx2::Unresolved>::_DataDescriptionDefinitionDatabaseInterface_WriteDataBases;
		#else
		tbl->_DataDescriptionDefinitionDatabaseInterface_WriteDataBases = &Hxx2::Wrapper<Hxx2::Unresolved>::_DataDescriptionDefinitionDatabaseInterface_WriteDataBases;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->_DataDescriptionDefinitionDatabaseInterface_QueryNeedsWriteDataBases = &Hxx2::Wrapper<Hxx2::Unresolved>::_DataDescriptionDefinitionDatabaseInterface_QueryNeedsWriteDataBases;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<Int>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_DataDescriptionDefinitionDatabaseInterface_RenameId = &Hxx2::Wrapper<Hxx2::Unresolved>::_DataDescriptionDefinitionDatabaseInterface_RenameId;
		#else
		tbl->_DataDescriptionDefinitionDatabaseInterface_RenameId = &Hxx2::Wrapper<Hxx2::Unresolved>::_DataDescriptionDefinitionDatabaseInterface_RenameId;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<Int>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_DataDescriptionDefinitionDatabaseInterface_RenameAttribute = &Hxx2::Wrapper<Hxx2::Unresolved>::_DataDescriptionDefinitionDatabaseInterface_RenameAttribute;
		#else
		tbl->_DataDescriptionDefinitionDatabaseInterface_RenameAttribute = &Hxx2::Wrapper<Hxx2::Unresolved>::_DataDescriptionDefinitionDatabaseInterface_RenameAttribute;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<Bool>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_DataDescriptionDefinitionDatabaseInterface_CheckUniqueAttributeName = &Hxx2::Wrapper<Hxx2::Unresolved>::_DataDescriptionDefinitionDatabaseInterface_CheckUniqueAttributeName;
		#else
		tbl->_DataDescriptionDefinitionDatabaseInterface_CheckUniqueAttributeName = &Hxx2::Wrapper<Hxx2::Unresolved>::_DataDescriptionDefinitionDatabaseInterface_CheckUniqueAttributeName;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<DataDescription>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_DataDescriptionDefinitionDatabaseInterface_UpdateDescription = &Hxx2::Wrapper<Hxx2::Unresolved>::_DataDescriptionDefinitionDatabaseInterface_UpdateDescription;
		#else
		tbl->_DataDescriptionDefinitionDatabaseInterface_UpdateDescription = &Hxx2::Wrapper<Hxx2::Unresolved>::_DataDescriptionDefinitionDatabaseInterface_UpdateDescription;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<DataDescription>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_DataDescriptionDefinitionDatabaseInterface_UpdateDescriptionI = &Hxx2::Wrapper<Hxx2::Unresolved>::_DataDescriptionDefinitionDatabaseInterface_UpdateDescriptionI;
		#else
		tbl->_DataDescriptionDefinitionDatabaseInterface_UpdateDescriptionI = &Hxx2::Wrapper<Hxx2::Unresolved>::_DataDescriptionDefinitionDatabaseInterface_UpdateDescriptionI;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<void>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_DataDescriptionDefinitionDatabaseInterface_RegisterDatabaseWithUrl = &Hxx2::Wrapper<Hxx2::Unresolved>::_DataDescriptionDefinitionDatabaseInterface_RegisterDatabaseWithUrl;
		#else
		tbl->_DataDescriptionDefinitionDatabaseInterface_RegisterDatabaseWithUrl = &Hxx2::Wrapper<Hxx2::Unresolved>::_DataDescriptionDefinitionDatabaseInterface_RegisterDatabaseWithUrl;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<void>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_DataDescriptionDefinitionDatabaseInterface_RegisterDatabase = &Hxx2::Wrapper<Hxx2::Unresolved>::_DataDescriptionDefinitionDatabaseInterface_RegisterDatabase;
		#else
		tbl->_DataDescriptionDefinitionDatabaseInterface_RegisterDatabase = &Hxx2::Wrapper<Hxx2::Unresolved>::_DataDescriptionDefinitionDatabaseInterface_RegisterDatabase;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<void>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_DataDescriptionDefinitionDatabaseInterface_UnregisterDatabase = &Hxx2::Wrapper<Hxx2::Unresolved>::_DataDescriptionDefinitionDatabaseInterface_UnregisterDatabase;
		#else
		tbl->_DataDescriptionDefinitionDatabaseInterface_UnregisterDatabase = &Hxx2::Wrapper<Hxx2::Unresolved>::_DataDescriptionDefinitionDatabaseInterface_UnregisterDatabase;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->_DataDescriptionDefinitionDatabaseInterface_IsWritableDatabase = &Hxx2::Wrapper<Hxx2::Unresolved>::_DataDescriptionDefinitionDatabaseInterface_IsWritableDatabase;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<BaseArray<Id>>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_DataDescriptionDefinitionDatabaseInterface_GetRegisteredDatabases = &Hxx2::Wrapper<Hxx2::Unresolved>::_DataDescriptionDefinitionDatabaseInterface_GetRegisteredDatabases;
		#else
		tbl->_DataDescriptionDefinitionDatabaseInterface_GetRegisteredDatabases = &Hxx2::Wrapper<Hxx2::Unresolved>::_DataDescriptionDefinitionDatabaseInterface_GetRegisteredDatabases;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<DataDescription>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_DataDescriptionDefinitionDatabaseInterface_BuildDescription = &Hxx2::Wrapper<Hxx2::Unresolved>::_DataDescriptionDefinitionDatabaseInterface_BuildDescription;
		#else
		tbl->_DataDescriptionDefinitionDatabaseInterface_BuildDescription = &Hxx2::Wrapper<Hxx2::Unresolved>::_DataDescriptionDefinitionDatabaseInterface_BuildDescription;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<void>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_DataDescriptionDefinitionDatabaseInterface_RegisterMessage = &Hxx2::Wrapper<Hxx2::Unresolved>::_DataDescriptionDefinitionDatabaseInterface_RegisterMessage;
		#else
		tbl->_DataDescriptionDefinitionDatabaseInterface_RegisterMessage = &Hxx2::Wrapper<Hxx2::Unresolved>::_DataDescriptionDefinitionDatabaseInterface_RegisterMessage;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->_DataDescriptionDefinitionDatabaseInterface_FindNodeMessage = &Hxx2::Wrapper<Hxx2::Unresolved>::_DataDescriptionDefinitionDatabaseInterface_FindNodeMessage;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<void>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_DataDescriptionDefinitionDatabaseInterface_FixDatabaseProps = &Hxx2::Wrapper<Hxx2::Unresolved>::_DataDescriptionDefinitionDatabaseInterface_FixDatabaseProps;
		#else
		tbl->_DataDescriptionDefinitionDatabaseInterface_FixDatabaseProps = &Hxx2::Wrapper<Hxx2::Unresolved>::_DataDescriptionDefinitionDatabaseInterface_FixDatabaseProps;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<maxon::ObservableRef<ObservableSaveDatabaseDelegate>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_DataDescriptionDefinitionDatabaseInterface_ObservableSaveDatabase = &Hxx2::Wrapper<Hxx2::Unresolved>::_DataDescriptionDefinitionDatabaseInterface_ObservableSaveDatabase;
		#else
		tbl->_DataDescriptionDefinitionDatabaseInterface_ObservableSaveDatabase = &Hxx2::Wrapper<Hxx2::Unresolved>::_DataDescriptionDefinitionDatabaseInterface_ObservableSaveDatabase;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<maxon::ObservableRef<ObservableDatabaseRegistrationChangeDelegate>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_DataDescriptionDefinitionDatabaseInterface_ObservableDatabaseRegistrationChange = &Hxx2::Wrapper<Hxx2::Unresolved>::_DataDescriptionDefinitionDatabaseInterface_ObservableDatabaseRegistrationChange;
		#else
		tbl->_DataDescriptionDefinitionDatabaseInterface_ObservableDatabaseRegistrationChange = &Hxx2::Wrapper<Hxx2::Unresolved>::_DataDescriptionDefinitionDatabaseInterface_ObservableDatabaseRegistrationChange;
		#endif
	#ifdef PRIVATE_MAXON_ASSEMBLE_UNRESOLVED
		return assembler(&_interface, (maxon::Char*) tbl, _returnTypes, SIZEOF(MTable) / SIZEOF(void*));
	#else
		return true;
	#endif
	}
	MAXON_INTERFACE_REGISTER(DataDescriptionDefinitionDatabaseInterface, "net.maxon.interface.datadescriptiondefinitiondatabase", nullptr);
}
#endif
