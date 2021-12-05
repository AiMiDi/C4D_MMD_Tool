#if 1
namespace maxon
{
	namespace enum22
	{
		enum class GETDATAFLAGS
		{
			NONE = 0,																///< no flags
			INTENT_ENABLING = (1 << 0),							///< Set this flag to get the effective value for the enabling with out port links (but the effective coming
																							///< from the linked port)
			INTENT_ENABLING_ISCONNECTED = (1 << 1),	///< Check only if the property is connected.
			INTENT_ENABLING_GRAPHNODE = (1 << 2),		///< Return the GraphNode of the property.
		} ;
		static const maxon::UInt64 GETDATAFLAGS_values[] = {maxon::UInt64(enum22::GETDATAFLAGS::NONE), maxon::UInt64(enum22::GETDATAFLAGS::INTENT_ENABLING), maxon::UInt64(enum22::GETDATAFLAGS::INTENT_ENABLING_ISCONNECTED), maxon::UInt64(enum22::GETDATAFLAGS::INTENT_ENABLING_GRAPHNODE)};
		static const maxon::EnumInfo GETDATAFLAGS_info{"GETDATAFLAGS", SIZEOF(GETDATAFLAGS), true, "NONE\0INTENT_ENABLING\0INTENT_ENABLING_ISCONNECTED\0INTENT_ENABLING_GRAPHNODE\0", GETDATAFLAGS_values, std::extent<decltype(GETDATAFLAGS_values)>::value};
	}
	const maxon::EnumInfo& PrivateGetEnumInfo_GETDATAFLAGS22(){ return enum22::GETDATAFLAGS_info; }
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
		if (maxon::details::NullReturnType<Result<void>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_DataDescriptionDefinitionInterface_MergeDescriptionDefinition = &Hxx2::CWrapper<maxon::StaticHelper<Hxx2::Unresolved>>::_DataDescriptionDefinitionInterface_MergeDescriptionDefinition;
		#else
		tbl->_DataDescriptionDefinitionInterface_MergeDescriptionDefinition = &Hxx2::CWrapper<maxon::StaticHelper<Hxx2::Unresolved>>::_DataDescriptionDefinitionInterface_MergeDescriptionDefinition;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<Data>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_DataDescriptionDefinitionInterface_GetDataDefaults = &Hxx2::CWrapper<maxon::StaticHelper<Hxx2::Unresolved>>::_DataDescriptionDefinitionInterface_GetDataDefaults;
		#else
		tbl->_DataDescriptionDefinitionInterface_GetDataDefaults = &Hxx2::CWrapper<maxon::StaticHelper<Hxx2::Unresolved>>::_DataDescriptionDefinitionInterface_GetDataDefaults;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<Data>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_DataDescriptionDefinitionInterface_GetDataValueOrDefaults = &Hxx2::CWrapper<maxon::StaticHelper<Hxx2::Unresolved>>::_DataDescriptionDefinitionInterface_GetDataValueOrDefaults;
		#else
		tbl->_DataDescriptionDefinitionInterface_GetDataValueOrDefaults = &Hxx2::CWrapper<maxon::StaticHelper<Hxx2::Unresolved>>::_DataDescriptionDefinitionInterface_GetDataValueOrDefaults;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->_DataDescriptionDefinitionInterface_Create = &Hxx2::CWrapper<maxon::StaticHelper<Hxx2::Unresolved>>::_DataDescriptionDefinitionInterface_Create;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->_DataDescriptionDefinitionInterface_NullValuePtr = &Hxx2::CWrapper<maxon::StaticHelper<Hxx2::Unresolved>>::_DataDescriptionDefinitionInterface_NullValuePtr;
		#endif
	#ifdef PRIVATE_MAXON_ASSEMBLE_UNRESOLVED
		return assembler(&_staticInterface, (maxon::Char*) tbl, _returnTypes, SIZEOF(StaticMTable) / SIZEOF(void*));
	#else
		return true;
	#endif
	}
	const maxon::Char* const DataDescriptionDefinitionInterface::MTable::_ids = 
		"GetInfo@72a97bfbf261be68\0" // DataDictionary GetInfo() const
		"SetInfo@c224a0816826789a\0" // Result<void> SetInfo(const DataDictionary& info)
		"GetEntryCount@7d0e6f3d29c239e7\0" // Int GetEntryCount() const
		"GetEntries@a38807f2749c29e1\0" // Result<BaseArray<DataDescriptionEntry>> GetEntries() const
		"GetEntry@2bfbdfc6608d16ac\0" // Result<DataDescriptionEntry> GetEntry(Int idx) const
		"FindEntry@f817cfd5109d014c\0" // Result<DataDescriptionEntry> FindEntry(const InternedId& id) const
		"AddEntry@97d1644544d36645\0" // Result<Int> AddEntry(const DataDescriptionEntry& props)
		"ReplaceEntry@2e756213c7b15000\0" // Result<void> ReplaceEntry(const DataDescriptionEntry& props)
		"ReplaceEntry@ffad52f48cde4ff7\0" // Result<Bool> ReplaceEntry(Int idx, const DataDescriptionEntry& props)
		"EraseEntry@c49f7df11faba36e\0" // Result<void> EraseEntry(Int idx)
		"Reset@780cdac8f1a33934\0" // void Reset()
	"";
	const maxon::METHOD_FLAGS DataDescriptionDefinitionInterface::MTable::_flags[] = 
	{
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE
	};
	PRIVATE_MAXON_INTERFACE_REGISTER_VIRTUAL_SINGLE_BASE(DataDescriptionDefinitionInterface, , "net.maxon.interface.datadescriptiondefinition", "maxon.DataDescriptionDefinitionInterface", (ObserverObjectInterface::PrivateGetInterface()));
	const maxon::Char* const DataDescriptionDefinitionInterface::Hxx2::StaticMTable::_ids = 
		"MergeDescriptionDefinition@ab3b0188c1903051\0" // Result<void> MergeDescriptionDefinition(DataDescriptionDefinition& target, const DataDescriptionDefinition& source, Bool overwriteIncludes, Bool skipIncludes)
		"GetDataDefaults@deb259fcda554d09\0" // Result<Data> GetDataDefaults(const DataDictionary& dataEntry)
		"GetDataValueOrDefaults@1323eb052cffe7bb\0" // Result<Data> GetDataValueOrDefaults(const InternedId& dataId, const DataDictionary& dataEntry, GETDATAFLAGS flags, const GetDataCallbackType& getDataCallback)
		"Create@9154f5fcfdc70075\0" // DataDescriptionDefinitionInterface* Create()
		"NullValuePtr@6f6494e43f30f9e2\0" // const DataDescriptionDefinitionInterface* NullValuePtr()
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
