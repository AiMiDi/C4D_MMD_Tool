
#ifndef DOXYGEN

#ifdef MAXON_COMPILER_GCC
	#pragma GCC diagnostic push
	#pragma GCC diagnostic ignored "-Wmisleading-indentation"
#endif

#if 1

struct DataDescriptionDatabaseInterface::MTable
{
	static MTable _instance;
	static MTable _unresolvedInstance;
	static const maxon::Char* const _ids;
	static maxon::Bool InitUnresolved(maxon::NonvirtualInterfaceReference::UnresolvedAssembler assembler, MTable* tbl);
	static const maxon::NULL_RETURN_TYPE _returnTypes[];
	static const maxon::Bool HAS_NONSTATIC = false;
	Result<DataDescription> (*_DataDescriptionDatabaseInterface_LoadDescription) (const Id& category, const LanguageRef& language, const Id& dataType);
	Result<DataDescription> (*_DataDescriptionDatabaseInterface_LoadDescription_1) (const Id& category, const LanguageRef& language, const IdAndVersion& dataType);
	Result<void> (*_DataDescriptionDatabaseInterface_StoreDescription) (const Id& category, const LanguageRef& language, const Id& dataType, DataDescription& description);
	Result<void> (*_DataDescriptionDatabaseInterface_StoreDescription_1) (const Id& category, const LanguageRef& language, const IdAndVersion& dataType, DataDescription& description);
	Result<void> (*_DataDescriptionDatabaseInterface_DescriptionDefinitionChanged) (const Id& category, const LanguageRef& language, const IdAndVersion& dataType);
	Result<BaseArray<Tuple<Id, Data, String>>> (*_DataDescriptionDatabaseInterface_GetEffectiveEnumList) (const DataDictionary& dataEntry, const DataDictionary& guiEntry, const DataDescription& stringDescription, Bool resolveExtensionPointsAndGui, const AssetRepositoryRef& repository);
	Result<void> (*_DataDescriptionDatabaseInterface_PostProcessStringDescription) (DataDescription& description, const BaseArray<DataDictionary>& entries);
	template <typename IMPL> static void Init(MTable* tbl)
	{
		tbl->_DataDescriptionDatabaseInterface_LoadDescription = &IMPL::_DataDescriptionDatabaseInterface_LoadDescription;
		tbl->_DataDescriptionDatabaseInterface_LoadDescription_1 = &IMPL::_DataDescriptionDatabaseInterface_LoadDescription_1;
		tbl->_DataDescriptionDatabaseInterface_StoreDescription = &IMPL::_DataDescriptionDatabaseInterface_StoreDescription;
		tbl->_DataDescriptionDatabaseInterface_StoreDescription_1 = &IMPL::_DataDescriptionDatabaseInterface_StoreDescription_1;
		tbl->_DataDescriptionDatabaseInterface_DescriptionDefinitionChanged = &IMPL::_DataDescriptionDatabaseInterface_DescriptionDefinitionChanged;
		tbl->_DataDescriptionDatabaseInterface_GetEffectiveEnumList = &IMPL::_DataDescriptionDatabaseInterface_GetEffectiveEnumList;
		tbl->_DataDescriptionDatabaseInterface_PostProcessStringDescription = &IMPL::_DataDescriptionDatabaseInterface_PostProcessStringDescription;
	}
};

template <typename C> class DataDescriptionDatabaseInterface::Wrapper
{
public:
	static Result<DataDescription> _DataDescriptionDatabaseInterface_LoadDescription(const Id& category, const LanguageRef& language, const Id& dataType) { return C::LoadDescription(category, language, dataType); }
	static Result<DataDescription> _DataDescriptionDatabaseInterface_LoadDescription_1(const Id& category, const LanguageRef& language, const IdAndVersion& dataType) { return C::LoadDescription(category, language, dataType); }
	static Result<void> _DataDescriptionDatabaseInterface_StoreDescription(const Id& category, const LanguageRef& language, const Id& dataType, DataDescription& description) { return C::StoreDescription(category, language, dataType, description); }
	static Result<void> _DataDescriptionDatabaseInterface_StoreDescription_1(const Id& category, const LanguageRef& language, const IdAndVersion& dataType, DataDescription& description) { return C::StoreDescription(category, language, dataType, description); }
	static Result<void> _DataDescriptionDatabaseInterface_DescriptionDefinitionChanged(const Id& category, const LanguageRef& language, const IdAndVersion& dataType) { return C::DescriptionDefinitionChanged(category, language, dataType); }
	static Result<BaseArray<Tuple<Id, Data, String>>> _DataDescriptionDatabaseInterface_GetEffectiveEnumList(const DataDictionary& dataEntry, const DataDictionary& guiEntry, const DataDescription& stringDescription, Bool resolveExtensionPointsAndGui, const AssetRepositoryRef& repository) { return C::GetEffectiveEnumList(dataEntry, guiEntry, stringDescription, resolveExtensionPointsAndGui, repository); }
	static Result<void> _DataDescriptionDatabaseInterface_PostProcessStringDescription(DataDescription& description, const BaseArray<DataDictionary>& entries) { return C::PostProcessStringDescription(description, entries); }
};

MAXON_ATTRIBUTE_FORCE_INLINE auto DataDescriptionDatabaseInterface::LoadDescription(const Id& category, const LanguageRef& language, const Id& dataType) -> Result<DataDescription>
{
	return MTable::_instance._DataDescriptionDatabaseInterface_LoadDescription(category, language, dataType);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto DataDescriptionDatabaseInterface::LoadDescription(const Id& category, const LanguageRef& language, const IdAndVersion& dataType) -> Result<DataDescription>
{
	return MTable::_instance._DataDescriptionDatabaseInterface_LoadDescription_1(category, language, dataType);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto DataDescriptionDatabaseInterface::StoreDescription(const Id& category, const LanguageRef& language, const Id& dataType, DataDescription& description) -> Result<void>
{
	return MTable::_instance._DataDescriptionDatabaseInterface_StoreDescription(category, language, dataType, description);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto DataDescriptionDatabaseInterface::StoreDescription(const Id& category, const LanguageRef& language, const IdAndVersion& dataType, DataDescription& description) -> Result<void>
{
	return MTable::_instance._DataDescriptionDatabaseInterface_StoreDescription_1(category, language, dataType, description);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto DataDescriptionDatabaseInterface::DescriptionDefinitionChanged(const Id& category, const LanguageRef& language, const IdAndVersion& dataType) -> Result<void>
{
	return MTable::_instance._DataDescriptionDatabaseInterface_DescriptionDefinitionChanged(category, language, dataType);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto DataDescriptionDatabaseInterface::GetEffectiveEnumList(const DataDictionary& dataEntry, const DataDictionary& guiEntry, const DataDescription& stringDescription, Bool resolveExtensionPointsAndGui, const AssetRepositoryRef& repository) -> Result<BaseArray<Tuple<Id, Data, String>>>
{
	return MTable::_instance._DataDescriptionDatabaseInterface_GetEffectiveEnumList(dataEntry, guiEntry, stringDescription, resolveExtensionPointsAndGui, repository);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto DataDescriptionDatabaseInterface::PostProcessStringDescription(DataDescription& description, const BaseArray<DataDictionary>& entries) -> Result<void>
{
	return MTable::_instance._DataDescriptionDatabaseInterface_PostProcessStringDescription(description, entries);
}

#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT)
static maxon::EntityUse s_ui_maxon_DataDescriptionDatabaseInterface(DataDescriptionDatabaseInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/datadescriptiondatabase.h", false);
#endif
#endif

#ifdef MAXON_COMPILER_GCC
	#pragma GCC diagnostic pop
#endif

#endif

