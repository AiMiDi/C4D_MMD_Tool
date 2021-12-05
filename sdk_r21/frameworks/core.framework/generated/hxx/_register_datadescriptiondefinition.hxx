#if 1
namespace maxon
{
	namespace enum24 { enum class GETDATAFLAGS
	{
		NONE = 0,																///< no flags
		INTENT_ENABLING = (1 << 0),							///< Set this flag to get the effective value for the enabling with out port links (but the effective coming
																						///< from the linked port)
		INTENT_ENABLING_ISCONNECTED = (1 << 1),	///< Check only if the property is connected.
		INTENT_ENABLING_GRAPHNODE = (1 << 2),		///< Return the GraphNode of the property.
	} ; }
	maxon::String PrivateToString_GETDATAFLAGS24(std::underlying_type<enum24::GETDATAFLAGS>::type x, const maxon::FormatStatement* fmt)
	{
		const maxon::UInt64 values[] = {(maxon::UInt64) enum24::GETDATAFLAGS::NONE, (maxon::UInt64) enum24::GETDATAFLAGS::INTENT_ENABLING, (maxon::UInt64) enum24::GETDATAFLAGS::INTENT_ENABLING_ISCONNECTED, (maxon::UInt64) enum24::GETDATAFLAGS::INTENT_ENABLING_GRAPHNODE};
		return maxon::StringInterface::PrivateEnumToString((maxon::UInt64) x, "GETDATAFLAGS", SIZEOF(x), true, values, "NONE\0INTENT_ENABLING\0INTENT_ENABLING_ISCONNECTED\0INTENT_ENABLING_GRAPHNODE\0", fmt);
	}
	MAXON_WARNING_PUSH
	MAXON_WARNING_DISABLE_DEPRECATED
	class DataDescriptionDefinitionInterface::Hxx2::Unresolved : public DataDescriptionDefinitionInterface
	{
	public:
		static Result<void> MergeDescriptionDefinition(DataDescriptionDefinition& target, const DataDescriptionDefinition& source, Bool overwriteIncludes, Bool skipIncludes) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_staticInterface, false)) return DataDescriptionDefinitionInterface::MergeDescriptionDefinition(target, source, overwriteIncludes, skipIncludes); return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::UNRESOLVED);}
		static Result<Data> GetDataDefaults(const DataDictionary& dataEntry) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_staticInterface, false)) return DataDescriptionDefinitionInterface::GetDataDefaults(dataEntry); return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::UNRESOLVED);}
		static Result<Data> GetDataValueOrDefaults(const InternedId& dataId, const DataDictionary& dataEntry, GETDATAFLAGS flags, const GetDataCallbackType& getDataCallback) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_staticInterface, false)) return DataDescriptionDefinitionInterface::GetDataValueOrDefaults(dataId, dataEntry, flags, getDataCallback); return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::UNRESOLVED);}
		static DataDescriptionDefinitionInterface* Create() { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_staticInterface, true)) return DataDescriptionDefinitionInterface::Create(); return nullptr;}
		static const DataDescriptionDefinitionInterface* NullValuePtr() { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_staticInterface, true)) return DataDescriptionDefinitionInterface::NullValuePtr(); return nullptr;}
	};
	MAXON_WARNING_POP
#ifdef PRIVATE_MAXON_ASSEMBLE_UNRESOLVED
	const maxon::NULL_RETURN_TYPE DataDescriptionDefinitionInterface::Hxx2::StaticMTable::_returnTypes[] = 
	{
		maxon::details::NullReturnType<Result<void>>::value,
		maxon::details::NullReturnType<Result<Data>>::value,
		maxon::details::NullReturnType<Result<Data>>::value,
		maxon::details::NullReturnType<DataDescriptionDefinitionInterface*>::value,
		maxon::details::NullReturnType<const DataDescriptionDefinitionInterface*>::value,
		maxon::NULL_RETURN_TYPE::OTHER
	};
#endif
	maxon::Bool DataDescriptionDefinitionInterface::Hxx2::StaticMTable::InitUnresolved(maxon::NonvirtualInterfaceReference::UnresolvedAssembler assembler, Hxx2::StaticMTable* tbl)
	{
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<void>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_DataDescriptionDefinitionInterface_MergeDescriptionDefinition = &Hxx2::Wrapper<maxon::StaticHelper<Hxx2::Unresolved>>::_DataDescriptionDefinitionInterface_MergeDescriptionDefinition;
		#else
		tbl->_DataDescriptionDefinitionInterface_MergeDescriptionDefinition = &Hxx2::Wrapper<maxon::StaticHelper<Hxx2::Unresolved>>::_DataDescriptionDefinitionInterface_MergeDescriptionDefinition;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<Data>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_DataDescriptionDefinitionInterface_GetDataDefaults = &Hxx2::Wrapper<maxon::StaticHelper<Hxx2::Unresolved>>::_DataDescriptionDefinitionInterface_GetDataDefaults;
		#else
		tbl->_DataDescriptionDefinitionInterface_GetDataDefaults = &Hxx2::Wrapper<maxon::StaticHelper<Hxx2::Unresolved>>::_DataDescriptionDefinitionInterface_GetDataDefaults;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<Data>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_DataDescriptionDefinitionInterface_GetDataValueOrDefaults = &Hxx2::Wrapper<maxon::StaticHelper<Hxx2::Unresolved>>::_DataDescriptionDefinitionInterface_GetDataValueOrDefaults;
		#else
		tbl->_DataDescriptionDefinitionInterface_GetDataValueOrDefaults = &Hxx2::Wrapper<maxon::StaticHelper<Hxx2::Unresolved>>::_DataDescriptionDefinitionInterface_GetDataValueOrDefaults;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->_DataDescriptionDefinitionInterface_Create = &Hxx2::Wrapper<maxon::StaticHelper<Hxx2::Unresolved>>::_DataDescriptionDefinitionInterface_Create;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->_DataDescriptionDefinitionInterface_NullValuePtr = &Hxx2::Wrapper<maxon::StaticHelper<Hxx2::Unresolved>>::_DataDescriptionDefinitionInterface_NullValuePtr;
		#endif
	#ifdef PRIVATE_MAXON_ASSEMBLE_UNRESOLVED
		return assembler(&_staticInterface, (maxon::Char*) tbl, _returnTypes, SIZEOF(StaticMTable) / SIZEOF(void*));
	#else
		return true;
	#endif
	}
	const maxon::Char* const DataDescriptionDefinitionInterface::MTable::_ids = 
		"GetInfo@c916016dbfde0077\0" // DataDictionary GetInfo() const
		"SetInfo@bb78c22b6e6bfbd1\0" // Result<void> SetInfo(const DataDictionary& info)
		"GetEntryCount@4386c86\0" // Int GetEntryCount() const
		"GetEntries@cf76aa98b038b92a\0" // Result<BaseArray<DataDescriptionEntry>> GetEntries() const
		"GetEntry@4664d4b53f2e380f\0" // Result<DataDescriptionEntry> GetEntry(Int idx) const
		"FindEntry@c9a98a0f8df6ae81\0" // Result<DataDescriptionEntry> FindEntry(const InternedId& id) const
		"AddEntry@8b825bf5f861b8d4\0" // Result<Int> AddEntry(const DataDescriptionEntry& props)
		"ReplaceEntry@e71e43244d2cfdd1\0" // Result<void> ReplaceEntry(const DataDescriptionEntry& props)
		"ReplaceEntry@e2eaa2150717dabe\0" // Result<Bool> ReplaceEntry(Int idx, const DataDescriptionEntry& props)
		"EraseEntry@44dd4274e7521437\0" // Result<void> EraseEntry(Int idx)
		"Reset@6b2e10f\0" // void Reset()
	"";
	PRIVATE_MAXON_INTERFACE_REGISTER_VIRTUAL_SINGLE_BASE(DataDescriptionDefinitionInterface, , "net.maxon.interface.datadescriptiondefinition", "maxon.DataDescriptionDefinitionInterface", (&ObserverObjectInterface::_interface));
	const maxon::Char* const DataDescriptionDefinitionInterface::Hxx2::StaticMTable::_ids = 
		"MergeDescriptionDefinition@47e7b799e6a7a632\0" // Result<void> MergeDescriptionDefinition(DataDescriptionDefinition& target, const DataDescriptionDefinition& source, Bool overwriteIncludes, Bool skipIncludes)
		"GetDataDefaults@ec8c560cbb96cea8\0" // Result<Data> GetDataDefaults(const DataDictionary& dataEntry)
		"GetDataValueOrDefaults@4018dc4d8cd2453a\0" // Result<Data> GetDataValueOrDefaults(const InternedId& dataId, const DataDictionary& dataEntry, GETDATAFLAGS flags, const GetDataCallbackType& getDataCallback)
		"Create@aa6de80e0a082b96\0" // DataDescriptionDefinitionInterface* Create()
		"NullValuePtr@f880eb1ab5415499\0" // const DataDescriptionDefinitionInterface* NullValuePtr()
	"";
	PRIVATE_MAXON_INTERFACE_REGISTER_STATIC(DataDescriptionDefinitionInterface, , "net.maxon.interface.datadescriptiondefinition");
	template <typename DUMMY> maxon::Int DataDescriptionDefinitionInterface::PrivateInstantiateNullValueHelper()
	{
		return 0
		| maxon::details::InstantiateNullReturnValue<DataDictionary>(OVERLOAD_MAX_RANK)
		;
	}
	PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(DataDescriptionDefinitionClass, , "net.maxon.class.datadescriptiondefinition");
	PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(DT_LanguageStringDataDescriptionDefinition,, "net.maxon.datatype.languagestringdatadescriptiondefinition");
}
#endif
static maxon::details::ForceEvaluation s_forceEval_datadescriptiondefinition(0
	| maxon::DataDescriptionDefinitionInterface::PrivateInstantiateNullValueHelper<maxon::Int>()
);
