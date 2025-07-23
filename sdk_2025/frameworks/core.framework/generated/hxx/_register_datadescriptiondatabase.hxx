#if 1
namespace maxon
{
	const maxon::Char* const DataDescriptionDatabaseInterface::MTable::_ids = 
		"LoadDescription@6d3615f1caba8be4\0" // Result<DataDescription> LoadDescription(const Id& category, const LanguageRef& language, const Id& dataType)
		"LoadDescription@b51ade6505b5b5b\0" // Result<DataDescription> LoadDescription(const Id& category, const LanguageRef& language, const IdAndVersion& dataType)
		"DescriptionDefinitionChanged@cd81069121dc5be3\0" // Result<void> DescriptionDefinitionChanged(const Id& category, const LanguageRef& language, const IdAndVersion& dataType)
		"GetEffectiveEnumList@dd51da156284be7c\0" // Result<BaseArray<Tuple<Id, Data, String>>> GetEffectiveEnumList(const DataDictionary& dataEntry, const DataDictionary& guiEntry, const DataDescription& stringDescription, Bool resolveExtensionPointsAndGui, Bool withStrings, const LanguageRef& language, const AssetRepositoryRef& repository, const Data* filterData)
		"GetEffectiveEnumList@e13376725c1c8f36\0" // Result<BaseArray<Tuple<Id, Data, String>>> GetEffectiveEnumList(const DataDictionary& dataEntry, const DataDictionary& guiEntry, const DataDescription& stringDescription, Bool resolveExtensionPointsAndGui, Bool withStrings, const LanguageRef& language, const AssetRepositoryRef& repository, const GetDataCallbackType& getDataCallback, const Data* filterData)
		"PostProcessStringDescription@21b625553298761\0" // Result<void> PostProcessStringDescription(DataDescription& description, const BaseArray<DataDictionary>& entries)
		"ResolveVariableIdentifier@8274ecbb5d155ce9\0" // Result<Id> ResolveVariableIdentifier(const Id& identifier, const AssetRepositoryRef& repository, const GetDataCallbackType& getDataCallback, Opt<const DataDictionary&> dataEntry, Opt<const DataDictionary&> guiEntry)
		"GetAndResolvePresetIdentifier@1c8ad70d6db5b75a\0" // Result<Id> GetAndResolvePresetIdentifier(const AssetRepositoryRef& repository, const GetDataCallbackType& getDataCallback, const DataDictionary& guiEntry, Opt<const DataDictionary&> dataEntry, Bool& outResolveSuccess)
	"";
	MAXON_WARNING_PUSH
	MAXON_WARNING_DISABLE_DEPRECATED
	class DataDescriptionDatabaseInterface::Hxx2::Unresolved : public DataDescriptionDatabaseInterface
	{
	public:
		static const Unresolved* Get(const DataDescriptionDatabaseInterface* o) { return (const Unresolved*) o; }
		static Unresolved* Get(DataDescriptionDatabaseInterface* o) { return (Unresolved*) o; }
		static Result<DataDescription> LoadDescription(const Id& category, const LanguageRef& language, const Id& dataType) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return DataDescriptionDatabaseInterface::LoadDescription(category, language, dataType); return HXXRET1(UNRESOLVED);}
		static Result<DataDescription> LoadDescription(const Id& category, const LanguageRef& language, const IdAndVersion& dataType) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return DataDescriptionDatabaseInterface::LoadDescription(category, language, dataType); return HXXRET1(UNRESOLVED);}
		static Result<void> DescriptionDefinitionChanged(const Id& category, const LanguageRef& language, const IdAndVersion& dataType) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return DataDescriptionDatabaseInterface::DescriptionDefinitionChanged(category, language, dataType); return HXXRET1(UNRESOLVED);}
		static Result<BaseArray<Tuple<Id, Data, String>>> GetEffectiveEnumList(const DataDictionary& dataEntry, const DataDictionary& guiEntry, const DataDescription& stringDescription, Bool resolveExtensionPointsAndGui, Bool withStrings, const LanguageRef& language, const AssetRepositoryRef& repository, const Data* filterData) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return DataDescriptionDatabaseInterface::GetEffectiveEnumList(dataEntry, guiEntry, stringDescription, resolveExtensionPointsAndGui, withStrings, language, repository, filterData); return HXXRET1(UNRESOLVED);}
		static Result<BaseArray<Tuple<Id, Data, String>>> GetEffectiveEnumList(const DataDictionary& dataEntry, const DataDictionary& guiEntry, const DataDescription& stringDescription, Bool resolveExtensionPointsAndGui, Bool withStrings, const LanguageRef& language, const AssetRepositoryRef& repository, const GetDataCallbackType& getDataCallback, const Data* filterData) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return DataDescriptionDatabaseInterface::GetEffectiveEnumList(dataEntry, guiEntry, stringDescription, resolveExtensionPointsAndGui, withStrings, language, repository, getDataCallback, filterData); return HXXRET1(UNRESOLVED);}
		static Result<void> PostProcessStringDescription(DataDescription& description, const BaseArray<DataDictionary>& entries) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return DataDescriptionDatabaseInterface::PostProcessStringDescription(description, entries); return HXXRET1(UNRESOLVED);}
		static Result<Id> ResolveVariableIdentifier(const Id& identifier, const AssetRepositoryRef& repository, const GetDataCallbackType& getDataCallback, Opt<const DataDictionary&> dataEntry, Opt<const DataDictionary&> guiEntry) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return DataDescriptionDatabaseInterface::ResolveVariableIdentifier(identifier, repository, getDataCallback, std::forward<Opt<const DataDictionary&>>(dataEntry), std::forward<Opt<const DataDictionary&>>(guiEntry)); return HXXRET1(UNRESOLVED);}
		static Result<Id> GetAndResolvePresetIdentifier(const AssetRepositoryRef& repository, const GetDataCallbackType& getDataCallback, const DataDictionary& guiEntry, Opt<const DataDictionary&> dataEntry, Bool& outResolveSuccess) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return DataDescriptionDatabaseInterface::GetAndResolvePresetIdentifier(repository, getDataCallback, guiEntry, std::forward<Opt<const DataDictionary&>>(dataEntry), outResolveSuccess); return HXXRET1(UNRESOLVED);}
	};
	MAXON_WARNING_POP
#ifdef PRIVATE_MAXON_ASSEMBLE_UNRESOLVED
	const maxon::UNRESOLVED_RETURN_TYPE DataDescriptionDatabaseInterface::MTable::_returnTypes[] = 
	{
		maxon::details::UnresolvedReturnType<Result<DataDescription>>::value,
		maxon::details::UnresolvedReturnType<Result<DataDescription>>::value,
		maxon::details::UnresolvedReturnType<Result<void>>::value,
		maxon::details::UnresolvedReturnType<Result<BaseArray<Tuple<Id, Data, String>>>>::value,
		maxon::details::UnresolvedReturnType<Result<BaseArray<Tuple<Id, Data, String>>>>::value,
		maxon::details::UnresolvedReturnType<Result<void>>::value,
		maxon::details::UnresolvedReturnType<Result<Id>>::value,
		maxon::details::UnresolvedReturnType<Result<Id>>::value,
		maxon::UNRESOLVED_RETURN_TYPE::OTHER
	};
#endif
	maxon::Bool DataDescriptionDatabaseInterface::MTable::InitUnresolved(maxon::NonvirtualInterfaceReference::UnresolvedAssembler assembler, MTable* tbl)
	{
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if constexpr (maxon::details::UnresolvedReturnType<Result<DataDescription>>::value == maxon::UNRESOLVED_RETURN_TYPE::OTHER) tbl->DataDescriptionDatabaseInterface_LoadDescription = PRIVATE_MAXON_MF_CAST(decltype(DataDescriptionDatabaseInterface_LoadDescription), &Hxx2::Wrapper<Hxx2::Unresolved>::DataDescriptionDatabaseInterface_LoadDescription);
		#else
		tbl->DataDescriptionDatabaseInterface_LoadDescription = PRIVATE_MAXON_MF_CAST(decltype(DataDescriptionDatabaseInterface_LoadDescription), &Hxx2::Wrapper<Hxx2::Unresolved>::DataDescriptionDatabaseInterface_LoadDescription);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if constexpr (maxon::details::UnresolvedReturnType<Result<DataDescription>>::value == maxon::UNRESOLVED_RETURN_TYPE::OTHER) tbl->DataDescriptionDatabaseInterface_LoadDescription_1 = PRIVATE_MAXON_MF_CAST(decltype(DataDescriptionDatabaseInterface_LoadDescription_1), &Hxx2::Wrapper<Hxx2::Unresolved>::DataDescriptionDatabaseInterface_LoadDescription_1);
		#else
		tbl->DataDescriptionDatabaseInterface_LoadDescription_1 = PRIVATE_MAXON_MF_CAST(decltype(DataDescriptionDatabaseInterface_LoadDescription_1), &Hxx2::Wrapper<Hxx2::Unresolved>::DataDescriptionDatabaseInterface_LoadDescription_1);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if constexpr (maxon::details::UnresolvedReturnType<Result<void>>::value == maxon::UNRESOLVED_RETURN_TYPE::OTHER) tbl->DataDescriptionDatabaseInterface_DescriptionDefinitionChanged = PRIVATE_MAXON_MF_CAST(decltype(DataDescriptionDatabaseInterface_DescriptionDefinitionChanged), &Hxx2::Wrapper<Hxx2::Unresolved>::DataDescriptionDatabaseInterface_DescriptionDefinitionChanged);
		#else
		tbl->DataDescriptionDatabaseInterface_DescriptionDefinitionChanged = PRIVATE_MAXON_MF_CAST(decltype(DataDescriptionDatabaseInterface_DescriptionDefinitionChanged), &Hxx2::Wrapper<Hxx2::Unresolved>::DataDescriptionDatabaseInterface_DescriptionDefinitionChanged);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if constexpr (maxon::details::UnresolvedReturnType<Result<BaseArray<Tuple<Id, Data, String>>>>::value == maxon::UNRESOLVED_RETURN_TYPE::OTHER) tbl->DataDescriptionDatabaseInterface_GetEffectiveEnumList = PRIVATE_MAXON_MF_CAST(decltype(DataDescriptionDatabaseInterface_GetEffectiveEnumList), &Hxx2::Wrapper<Hxx2::Unresolved>::DataDescriptionDatabaseInterface_GetEffectiveEnumList);
		#else
		tbl->DataDescriptionDatabaseInterface_GetEffectiveEnumList = PRIVATE_MAXON_MF_CAST(decltype(DataDescriptionDatabaseInterface_GetEffectiveEnumList), &Hxx2::Wrapper<Hxx2::Unresolved>::DataDescriptionDatabaseInterface_GetEffectiveEnumList);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if constexpr (maxon::details::UnresolvedReturnType<Result<BaseArray<Tuple<Id, Data, String>>>>::value == maxon::UNRESOLVED_RETURN_TYPE::OTHER) tbl->DataDescriptionDatabaseInterface_GetEffectiveEnumList_1 = PRIVATE_MAXON_MF_CAST(decltype(DataDescriptionDatabaseInterface_GetEffectiveEnumList_1), &Hxx2::Wrapper<Hxx2::Unresolved>::DataDescriptionDatabaseInterface_GetEffectiveEnumList_1);
		#else
		tbl->DataDescriptionDatabaseInterface_GetEffectiveEnumList_1 = PRIVATE_MAXON_MF_CAST(decltype(DataDescriptionDatabaseInterface_GetEffectiveEnumList_1), &Hxx2::Wrapper<Hxx2::Unresolved>::DataDescriptionDatabaseInterface_GetEffectiveEnumList_1);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if constexpr (maxon::details::UnresolvedReturnType<Result<void>>::value == maxon::UNRESOLVED_RETURN_TYPE::OTHER) tbl->DataDescriptionDatabaseInterface_PostProcessStringDescription = PRIVATE_MAXON_MF_CAST(decltype(DataDescriptionDatabaseInterface_PostProcessStringDescription), &Hxx2::Wrapper<Hxx2::Unresolved>::DataDescriptionDatabaseInterface_PostProcessStringDescription);
		#else
		tbl->DataDescriptionDatabaseInterface_PostProcessStringDescription = PRIVATE_MAXON_MF_CAST(decltype(DataDescriptionDatabaseInterface_PostProcessStringDescription), &Hxx2::Wrapper<Hxx2::Unresolved>::DataDescriptionDatabaseInterface_PostProcessStringDescription);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if constexpr (maxon::details::UnresolvedReturnType<Result<Id>>::value == maxon::UNRESOLVED_RETURN_TYPE::OTHER) tbl->DataDescriptionDatabaseInterface_ResolveVariableIdentifier = PRIVATE_MAXON_MF_CAST(decltype(DataDescriptionDatabaseInterface_ResolveVariableIdentifier), &Hxx2::Wrapper<Hxx2::Unresolved>::DataDescriptionDatabaseInterface_ResolveVariableIdentifier);
		#else
		tbl->DataDescriptionDatabaseInterface_ResolveVariableIdentifier = PRIVATE_MAXON_MF_CAST(decltype(DataDescriptionDatabaseInterface_ResolveVariableIdentifier), &Hxx2::Wrapper<Hxx2::Unresolved>::DataDescriptionDatabaseInterface_ResolveVariableIdentifier);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if constexpr (maxon::details::UnresolvedReturnType<Result<Id>>::value == maxon::UNRESOLVED_RETURN_TYPE::OTHER) tbl->DataDescriptionDatabaseInterface_GetAndResolvePresetIdentifier = PRIVATE_MAXON_MF_CAST(decltype(DataDescriptionDatabaseInterface_GetAndResolvePresetIdentifier), &Hxx2::Wrapper<Hxx2::Unresolved>::DataDescriptionDatabaseInterface_GetAndResolvePresetIdentifier);
		#else
		tbl->DataDescriptionDatabaseInterface_GetAndResolvePresetIdentifier = PRIVATE_MAXON_MF_CAST(decltype(DataDescriptionDatabaseInterface_GetAndResolvePresetIdentifier), &Hxx2::Wrapper<Hxx2::Unresolved>::DataDescriptionDatabaseInterface_GetAndResolvePresetIdentifier);
		#endif
	#ifdef PRIVATE_MAXON_ASSEMBLE_UNRESOLVED
		return assembler(&_interface, (const void**) tbl, _returnTypes, SIZEOF(MTable) / SIZEOF(void*));
	#else
		return true;
	#endif
	}
	MAXON_INTERFACE_REGISTER(DataDescriptionDatabaseInterface, "net.maxon.interface.datadescriptiondatabase", nullptr, maxon::EntityBase::FLAGS::NONE);
	PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(DT_ProcessEnumListDelegate,, "net.maxon.datatype.processenumlistdelegate");
	MAXON_REGISTRY_REGISTER(ProcessEnumListDelegates);
	PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(DT_EnumVariableResolveDelegate,, "net.maxon.datatype.delegate.enumvariableresolve");
	MAXON_REGISTRY_REGISTER(EnumVariableResolveDelegates);
}
#endif
