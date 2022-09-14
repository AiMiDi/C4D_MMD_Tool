
#ifndef DOXYGEN

#if defined MAXON_COMPILER_GCC
	#pragma GCC diagnostic push
	#if MAXON_COMPILER_GCC >= 600
		#pragma GCC diagnostic ignored "-Wmisleading-indentation"
	#endif
#endif

#if 1
constexpr const maxon::Char* DataDescriptionDatabaseInterface::PrivateGetCppName() { return nullptr; }

struct DataDescriptionDatabaseInterface::MTable
{
	static MTable _instance;
	static MTable _unresolvedInstance;
	static const maxon::Char* const _ids;
	static maxon::Bool InitUnresolved(maxon::NonvirtualInterfaceReference::UnresolvedAssembler assembler, MTable* tbl);
	static const maxon::NULL_RETURN_TYPE _returnTypes[];
	static const maxon::Bool HAS_NONSTATIC = false;
	PRIVATE_MAXON_SF_POINTER(DataDescriptionDatabaseInterface_LoadDescription, LoadDescription, MAXON_EXPAND_VA_ARGS, (Result<DataDescription>), const Id& category, const LanguageRef& language, const Id& dataType);
	PRIVATE_MAXON_SF_POINTER(DataDescriptionDatabaseInterface_LoadDescription_1, LoadDescription, MAXON_EXPAND_VA_ARGS, (Result<DataDescription>), const Id& category, const LanguageRef& language, const IdAndVersion& dataType);
	PRIVATE_MAXON_SF_POINTER(DataDescriptionDatabaseInterface_DescriptionDefinitionChanged, DescriptionDefinitionChanged, MAXON_EXPAND_VA_ARGS, (Result<void>), const Id& category, const LanguageRef& language, const IdAndVersion& dataType);
	PRIVATE_MAXON_SF_POINTER(DataDescriptionDatabaseInterface_GetEffectiveEnumList, GetEffectiveEnumList, MAXON_EXPAND_VA_ARGS, (Result<BaseArray<Tuple<Id, Data, String>>>), const DataDictionary& dataEntry, const DataDictionary& guiEntry, const DataDescription& stringDescription, Bool resolveExtensionPointsAndGui, Bool withStrings, const LanguageRef& language, const AssetRepositoryRef& repository, const Data* filterData);
	PRIVATE_MAXON_SF_POINTER(DataDescriptionDatabaseInterface_GetEffectiveEnumList_1, GetEffectiveEnumList, MAXON_EXPAND_VA_ARGS, (Result<BaseArray<Tuple<Id, Data, String>>>), const DataDictionary& dataEntry, const DataDictionary& guiEntry, const DataDescription& stringDescription, Bool resolveExtensionPointsAndGui, Bool withStrings, const LanguageRef& language, const AssetRepositoryRef& repository, const GetDataCallbackType& getDataCallback, const Data* filterData);
	PRIVATE_MAXON_SF_POINTER(DataDescriptionDatabaseInterface_PostProcessStringDescription, PostProcessStringDescription, MAXON_EXPAND_VA_ARGS, (Result<void>), DataDescription& description, const BaseArray<DataDictionary>& entries);
	PRIVATE_MAXON_SF_POINTER(DataDescriptionDatabaseInterface_ResolveVariableIdentifier, ResolveVariableIdentifier, MAXON_EXPAND_VA_ARGS, (Result<Id>), const Id& identifier, const AssetRepositoryRef& repository, const GetDataCallbackType& getDataCallback, Opt<const DataDictionary&> dataEntry, Opt<const DataDictionary&> guiEntry);
	PRIVATE_MAXON_SF_POINTER(DataDescriptionDatabaseInterface_GetAndResolvePresetIdentifier, GetAndResolvePresetIdentifier, MAXON_EXPAND_VA_ARGS, (Result<Id>), const AssetRepositoryRef& repository, const GetDataCallbackType& getDataCallback, const DataDictionary& guiEntry, Opt<const DataDictionary&> dataEntry, Bool& outResolveSuccess);
	template <typename IMPL> void Init()
	{
		DataDescriptionDatabaseInterface_LoadDescription = DataDescriptionDatabaseInterface_LoadDescription_GetPtr<IMPL>(true);
		DataDescriptionDatabaseInterface_LoadDescription_1 = DataDescriptionDatabaseInterface_LoadDescription_1_GetPtr<IMPL>(true);
		DataDescriptionDatabaseInterface_DescriptionDefinitionChanged = DataDescriptionDatabaseInterface_DescriptionDefinitionChanged_GetPtr<IMPL>(true);
		DataDescriptionDatabaseInterface_GetEffectiveEnumList = DataDescriptionDatabaseInterface_GetEffectiveEnumList_GetPtr<IMPL>(true);
		DataDescriptionDatabaseInterface_GetEffectiveEnumList_1 = DataDescriptionDatabaseInterface_GetEffectiveEnumList_1_GetPtr<IMPL>(true);
		DataDescriptionDatabaseInterface_PostProcessStringDescription = DataDescriptionDatabaseInterface_PostProcessStringDescription_GetPtr<IMPL>(true);
		DataDescriptionDatabaseInterface_ResolveVariableIdentifier = DataDescriptionDatabaseInterface_ResolveVariableIdentifier_GetPtr<IMPL>(true);
		DataDescriptionDatabaseInterface_GetAndResolvePresetIdentifier = DataDescriptionDatabaseInterface_GetAndResolvePresetIdentifier_GetPtr<IMPL>(true);
	}
};

struct DataDescriptionDatabaseInterface::Hxx2
{
	class Unresolved;
	template <typename C> class Wrapper
	{
	public:
		using Implementation = C;
		static Result<DataDescription> DataDescriptionDatabaseInterface_LoadDescription(const Id& category, const LanguageRef& language, const Id& dataType) { return C::LoadDescription(category, language, dataType); }
		static Result<DataDescription> DataDescriptionDatabaseInterface_LoadDescription_1(const Id& category, const LanguageRef& language, const IdAndVersion& dataType) { return C::LoadDescription(category, language, dataType); }
		static Result<void> DataDescriptionDatabaseInterface_DescriptionDefinitionChanged(const Id& category, const LanguageRef& language, const IdAndVersion& dataType) { return C::DescriptionDefinitionChanged(category, language, dataType); }
		static Result<BaseArray<Tuple<Id, Data, String>>> DataDescriptionDatabaseInterface_GetEffectiveEnumList(const DataDictionary& dataEntry, const DataDictionary& guiEntry, const DataDescription& stringDescription, Bool resolveExtensionPointsAndGui, Bool withStrings, const LanguageRef& language, const AssetRepositoryRef& repository, const Data* filterData) { return C::GetEffectiveEnumList(dataEntry, guiEntry, stringDescription, resolveExtensionPointsAndGui, withStrings, language, repository, filterData); }
		static Result<BaseArray<Tuple<Id, Data, String>>> DataDescriptionDatabaseInterface_GetEffectiveEnumList_1(const DataDictionary& dataEntry, const DataDictionary& guiEntry, const DataDescription& stringDescription, Bool resolveExtensionPointsAndGui, Bool withStrings, const LanguageRef& language, const AssetRepositoryRef& repository, const GetDataCallbackType& getDataCallback, const Data* filterData) { return C::GetEffectiveEnumList(dataEntry, guiEntry, stringDescription, resolveExtensionPointsAndGui, withStrings, language, repository, getDataCallback, filterData); }
		static Result<void> DataDescriptionDatabaseInterface_PostProcessStringDescription(DataDescription& description, const BaseArray<DataDictionary>& entries) { return C::PostProcessStringDescription(description, entries); }
		static Result<Id> DataDescriptionDatabaseInterface_ResolveVariableIdentifier(const Id& identifier, const AssetRepositoryRef& repository, const GetDataCallbackType& getDataCallback, Opt<const DataDictionary&> dataEntry, Opt<const DataDictionary&> guiEntry) { return C::ResolveVariableIdentifier(identifier, repository, getDataCallback, std::forward<Opt<const DataDictionary&>>(dataEntry), std::forward<Opt<const DataDictionary&>>(guiEntry)); }
		static Result<Id> DataDescriptionDatabaseInterface_GetAndResolvePresetIdentifier(const AssetRepositoryRef& repository, const GetDataCallbackType& getDataCallback, const DataDictionary& guiEntry, Opt<const DataDictionary&> dataEntry, Bool& outResolveSuccess) { return C::GetAndResolvePresetIdentifier(repository, getDataCallback, guiEntry, std::forward<Opt<const DataDictionary&>>(dataEntry), outResolveSuccess); }
	};

};
MAXON_ATTRIBUTE_FORCE_INLINE auto DataDescriptionDatabaseInterface::LoadDescription(const Id& category, const LanguageRef& language, const Id& dataType) -> Result<DataDescription>
{
	return MTable::_instance.DataDescriptionDatabaseInterface_LoadDescription(category, language, dataType);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto DataDescriptionDatabaseInterface::LoadDescription(const Id& category, const LanguageRef& language, const IdAndVersion& dataType) -> Result<DataDescription>
{
	return MTable::_instance.DataDescriptionDatabaseInterface_LoadDescription_1(category, language, dataType);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto DataDescriptionDatabaseInterface::DescriptionDefinitionChanged(const Id& category, const LanguageRef& language, const IdAndVersion& dataType) -> Result<void>
{
	return MTable::_instance.DataDescriptionDatabaseInterface_DescriptionDefinitionChanged(category, language, dataType);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto DataDescriptionDatabaseInterface::GetEffectiveEnumList(const DataDictionary& dataEntry, const DataDictionary& guiEntry, const DataDescription& stringDescription, Bool resolveExtensionPointsAndGui, Bool withStrings, const LanguageRef& language, const AssetRepositoryRef& repository, const Data* filterData) -> Result<BaseArray<Tuple<Id, Data, String>>>
{
	return MTable::_instance.DataDescriptionDatabaseInterface_GetEffectiveEnumList(dataEntry, guiEntry, stringDescription, resolveExtensionPointsAndGui, withStrings, language, repository, filterData);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto DataDescriptionDatabaseInterface::GetEffectiveEnumList(const DataDictionary& dataEntry, const DataDictionary& guiEntry, const DataDescription& stringDescription, Bool resolveExtensionPointsAndGui, Bool withStrings, const LanguageRef& language, const AssetRepositoryRef& repository, const GetDataCallbackType& getDataCallback, const Data* filterData) -> Result<BaseArray<Tuple<Id, Data, String>>>
{
	return MTable::_instance.DataDescriptionDatabaseInterface_GetEffectiveEnumList_1(dataEntry, guiEntry, stringDescription, resolveExtensionPointsAndGui, withStrings, language, repository, getDataCallback, filterData);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto DataDescriptionDatabaseInterface::PostProcessStringDescription(DataDescription& description, const BaseArray<DataDictionary>& entries) -> Result<void>
{
	return MTable::_instance.DataDescriptionDatabaseInterface_PostProcessStringDescription(description, entries);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto DataDescriptionDatabaseInterface::ResolveVariableIdentifier(const Id& identifier, const AssetRepositoryRef& repository, const GetDataCallbackType& getDataCallback, Opt<const DataDictionary&> dataEntry, Opt<const DataDictionary&> guiEntry) -> Result<Id>
{
	return MTable::_instance.DataDescriptionDatabaseInterface_ResolveVariableIdentifier(identifier, repository, getDataCallback, std::forward<Opt<const DataDictionary&>>(dataEntry), std::forward<Opt<const DataDictionary&>>(guiEntry));
}
MAXON_ATTRIBUTE_FORCE_INLINE auto DataDescriptionDatabaseInterface::GetAndResolvePresetIdentifier(const AssetRepositoryRef& repository, const GetDataCallbackType& getDataCallback, const DataDictionary& guiEntry, Opt<const DataDictionary&> dataEntry, Bool& outResolveSuccess) -> Result<Id>
{
	return MTable::_instance.DataDescriptionDatabaseInterface_GetAndResolvePresetIdentifier(repository, getDataCallback, guiEntry, std::forward<Opt<const DataDictionary&>>(dataEntry), outResolveSuccess);
}

#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT) && !defined(MAXON_DEPENDENCY_DISABLE_datadescriptiondatabase)
#ifdef MAXON_USE_REGISTER_FUNCTION
MAXON_STATIC_STORAGE(maxon::EntityUse, s_ui_maxon_DataDescriptionDatabaseInterface); \
MAXON_ATTRIBUTE_CONSTRUCTOR static void Register_s_ui_maxon_DataDescriptionDatabaseInterface() { new (s_ui_maxon_DataDescriptionDatabaseInterface) maxon::EntityUse(DataDescriptionDatabaseInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/datadescriptiondatabase.h", false); }
#else // !MAXON_USE_REGISTER_FUNCTION
static maxon::EntityUse s_ui_maxon_DataDescriptionDatabaseInterface(DataDescriptionDatabaseInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/datadescriptiondatabase.h", false);
#endif // MAXON_USE_REGISTER_FUNCTION
#endif
#endif

#ifdef MAXON_COMPILER_GCC
	#pragma GCC diagnostic pop
#endif

#endif

