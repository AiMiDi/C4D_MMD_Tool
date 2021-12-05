#if 1
namespace maxon
{
	const maxon::Char* const DataDescriptionInterface::MTable::_ids = 
		"Free@25130b8900cb12ec\0" // Free(const DataDescriptionInterface* object)
		"Alloc@1788cf55fba75bd3\0" // Alloc(const maxon::SourceLocation& allocLocation)
		"Alloc@709c2536bb19193d\0" // Alloc(const maxon::SourceLocation& allocLocation, const DataDescriptionInterface& object)
		"GetInfo@c916016dbfde0077\0" // GetInfo() const
		"SetInfo@bb78c22b6e6bfbd1\0" // SetInfo(const DataDictionary& info)
		"GetEntryCount@4386c86\0" // GetEntryCount() const
		"GetEntries@2474341e113931aa\0" // GetEntries() const
		"GetEntry@a270be6211772801\0" // GetEntry(const InternedId& id) const
		"SetEntry@a428cbd938c7a87b\0" // SetEntry(const DataDictionary& props, Bool merge)
		"EraseEntry@f84e364681bdea85\0" // EraseEntry(const InternedId& id)
		"Reset@6b2e10f\0" // Reset()
		"IsEqual@fc7d5cd28f7ed521\0" // IsEqual(const DataDescriptionInterface* other, EQUALITY equality) const
		"Compare@d15927ec95fd7135\0" // Compare(const DataDescriptionInterface* other) const
		"GetHashCode@95445951\0" // GetHashCode() const
		"ToString@7de9f6f51c89c899\0" // ToString(const FormatStatement* formatStatement) const
		"DescribeIO@0c0a05550eef0455\0" // DescribeIO(const DataSerializeInterface& stream)
	"";
	class DataDescriptionInterface::Unresolved : public DataDescriptionInterface
	{
	public:
		static const Unresolved* Get(const DataDescriptionInterface* o) { return (const Unresolved*) o; }
		static Unresolved* Get(DataDescriptionInterface* o) { return (Unresolved*) o; }
		static void Free(const DataDescriptionInterface* object) { if (object && maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return DataDescriptionInterface::Free(object); return maxon::PrivateLogNullptrError();}
		static DataDescriptionInterface* Alloc(const maxon::SourceLocation& allocLocation) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return DataDescriptionInterface::Alloc(allocLocation); return nullptr;}
		static DataDescriptionInterface* Alloc(const maxon::SourceLocation& allocLocation, const DataDescriptionInterface& object) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return DataDescriptionInterface::Alloc(allocLocation, object); return nullptr;}
		DataDictionary GetInfo() const { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ((const DataDescriptionInterface*) this)->GetInfo(); return maxon::PrivateIncompleteNullReturnValue<DataDictionary>(maxon::NULL_RETURN_REASON::UNRESOLVED, OVERLOAD_MAX_RANK);}
		Result<void> SetInfo(const DataDictionary& info) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return ((DataDescriptionInterface*) this)->SetInfo(info); return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::UNRESOLVED);}
		Int GetEntryCount() const { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ((const DataDescriptionInterface*) this)->GetEntryCount(); return 0;}
		Result<BaseArray<DataDictionary>> GetEntries() const { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return ((const DataDescriptionInterface*) this)->GetEntries(); return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::UNRESOLVED);}
		Result<DataDictionary> GetEntry(const InternedId& id) const { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return ((const DataDescriptionInterface*) this)->GetEntry(id); return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::UNRESOLVED);}
		Result<Bool> SetEntry(const DataDictionary& props, Bool merge) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return ((DataDescriptionInterface*) this)->SetEntry(props, merge); return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::UNRESOLVED);}
		Result<void> EraseEntry(const InternedId& id) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return ((DataDescriptionInterface*) this)->EraseEntry(id); return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::UNRESOLVED);}
		void Reset() { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ((DataDescriptionInterface*) this)->Reset(); return maxon::PrivateLogNullptrError();}
		Bool IsEqual(const DataDescriptionInterface* other, EQUALITY equality) const { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ((const DataDescriptionInterface*) this)->IsEqual(other, equality); return maxon::PrivateLogNullptrError(false);}
		COMPARERESULT Compare(const DataDescriptionInterface* other) const { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ((const DataDescriptionInterface*) this)->Compare(other); return maxon::PrivateIncompleteNullReturnValue<COMPARERESULT>(maxon::NULL_RETURN_REASON::UNRESOLVED, OVERLOAD_MAX_RANK);}
		UInt GetHashCode() const { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ((const DataDescriptionInterface*) this)->GetHashCode(); return 0;}
		String ToString(const FormatStatement* formatStatement) const { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ((const DataDescriptionInterface*) this)->ToString(formatStatement); return maxon::PrivateIncompleteNullReturnValue<String>(maxon::NULL_RETURN_REASON::UNRESOLVED, OVERLOAD_MAX_RANK);}
		static Result<void> DescribeIO(const DataSerializeInterface& stream) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return DataDescriptionInterface::DescribeIO(stream); return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::UNRESOLVED);}
	};
#ifdef PRIVATE_MAXON_ASSEMBLE_UNRESOLVED
	const maxon::NULL_RETURN_TYPE DataDescriptionInterface::MTable::_returnTypes[] = 
	{
		maxon::NULL_RETURN_TYPE::VOID_ZERO_FREE_FUNCTION,
		maxon::details::NullReturnType<DataDescriptionInterface*>::value,
		maxon::details::NullReturnType<DataDescriptionInterface*>::value,
		maxon::details::NullReturnType<DataDictionary>::value,
		maxon::details::NullReturnType<Result<void>>::value,
		maxon::details::NullReturnType<Int>::value,
		maxon::details::NullReturnType<Result<BaseArray<DataDictionary>>>::value,
		maxon::details::NullReturnType<Result<DataDictionary>>::value,
		maxon::details::NullReturnType<Result<Bool>>::value,
		maxon::details::NullReturnType<Result<void>>::value,
		maxon::details::NullReturnType<void>::value,
		maxon::details::NullReturnType<Bool>::value,
		maxon::details::NullReturnType<COMPARERESULT>::value,
		maxon::details::NullReturnType<UInt>::value,
		maxon::details::NullReturnType<String>::value,
		maxon::details::NullReturnType<Result<void>>::value,
		maxon::NULL_RETURN_TYPE::OTHER
	};
#endif
	maxon::Bool DataDescriptionInterface::MTable::InitUnresolved(maxon::NonvirtualInterfaceReference::UnresolvedAssembler assembler, MTable* tbl)
	{
	#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
	#else
		tbl->_DataDescriptionInterface_Free = &Wrapper<Unresolved>::_DataDescriptionInterface_Free;
	#endif
	#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
	#else
		tbl->_DataDescriptionInterface_Alloc = &Wrapper<Unresolved>::_DataDescriptionInterface_Alloc;
	#endif
	#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
	#else
		tbl->_DataDescriptionInterface_Alloc_1 = &Wrapper<Unresolved>::_DataDescriptionInterface_Alloc_1;
	#endif
	#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<DataDictionary>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_DataDescriptionInterface_GetInfo = &Wrapper<Unresolved>::_DataDescriptionInterface_GetInfo;
	#else
		tbl->_DataDescriptionInterface_GetInfo = &Wrapper<Unresolved>::_DataDescriptionInterface_GetInfo;
	#endif
	#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<void>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_DataDescriptionInterface_SetInfo = &Wrapper<Unresolved>::_DataDescriptionInterface_SetInfo;
	#else
		tbl->_DataDescriptionInterface_SetInfo = &Wrapper<Unresolved>::_DataDescriptionInterface_SetInfo;
	#endif
	#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
	#else
		tbl->_DataDescriptionInterface_GetEntryCount = &Wrapper<Unresolved>::_DataDescriptionInterface_GetEntryCount;
	#endif
	#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<BaseArray<DataDictionary>>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_DataDescriptionInterface_GetEntries = &Wrapper<Unresolved>::_DataDescriptionInterface_GetEntries;
	#else
		tbl->_DataDescriptionInterface_GetEntries = &Wrapper<Unresolved>::_DataDescriptionInterface_GetEntries;
	#endif
	#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<DataDictionary>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_DataDescriptionInterface_GetEntry = &Wrapper<Unresolved>::_DataDescriptionInterface_GetEntry;
	#else
		tbl->_DataDescriptionInterface_GetEntry = &Wrapper<Unresolved>::_DataDescriptionInterface_GetEntry;
	#endif
	#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<Bool>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_DataDescriptionInterface_SetEntry = &Wrapper<Unresolved>::_DataDescriptionInterface_SetEntry;
	#else
		tbl->_DataDescriptionInterface_SetEntry = &Wrapper<Unresolved>::_DataDescriptionInterface_SetEntry;
	#endif
	#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<void>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_DataDescriptionInterface_EraseEntry = &Wrapper<Unresolved>::_DataDescriptionInterface_EraseEntry;
	#else
		tbl->_DataDescriptionInterface_EraseEntry = &Wrapper<Unresolved>::_DataDescriptionInterface_EraseEntry;
	#endif
	#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
	#else
		tbl->_DataDescriptionInterface_Reset = &Wrapper<Unresolved>::_DataDescriptionInterface_Reset;
	#endif
	#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
	#else
		tbl->_DataDescriptionInterface_IsEqual = &Wrapper<Unresolved>::_DataDescriptionInterface_IsEqual;
	#endif
	#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<COMPARERESULT>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_DataDescriptionInterface_Compare = &Wrapper<Unresolved>::_DataDescriptionInterface_Compare;
	#else
		tbl->_DataDescriptionInterface_Compare = &Wrapper<Unresolved>::_DataDescriptionInterface_Compare;
	#endif
	#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
	#else
		tbl->_DataDescriptionInterface_GetHashCode = &Wrapper<Unresolved>::_DataDescriptionInterface_GetHashCode;
	#endif
	#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<String>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_DataDescriptionInterface_ToString = &Wrapper<Unresolved>::_DataDescriptionInterface_ToString;
	#else
		tbl->_DataDescriptionInterface_ToString = &Wrapper<Unresolved>::_DataDescriptionInterface_ToString;
	#endif
	#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<void>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_DataDescriptionInterface_DescribeIO = &Wrapper<Unresolved>::_DataDescriptionInterface_DescribeIO;
	#else
		tbl->_DataDescriptionInterface_DescribeIO = &Wrapper<Unresolved>::_DataDescriptionInterface_DescribeIO;
	#endif
	#ifdef PRIVATE_MAXON_ASSEMBLE_UNRESOLVED
		return assembler(&_interface, (maxon::Char*) tbl, _returnTypes, SIZEOF(_returnTypes) - 1);
	#else
		return true;
	#endif
	}
	MAXON_INTERFACE_REGISTER(DataDescriptionInterface, "net.maxon.interface.datadescription", nullptr);
	template <typename DUMMY> maxon::Int DataDescriptionInterface::PrivateInstantiateNullValueHelper()
	{
		return 0
		| maxon::details::InstantiateNullReturnValue<COMPARERESULT>(OVERLOAD_MAX_RANK)
		| maxon::details::InstantiateNullReturnValue<DataDictionary>(OVERLOAD_MAX_RANK)
		| maxon::details::InstantiateNullReturnValue<String>(OVERLOAD_MAX_RANK)
		;
	}
	MAXON_REGISTRY_REGISTER(DataTypeCppIdentifiers);
	PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(DT_LanguageStringDataDescription,, "net.maxon.datatype.languagestringdatadescription");
}
#endif
static maxon::details::ForceEvaluation s_forceEval_datadescription(0
	| maxon::DataDescriptionInterface::PrivateInstantiateNullValueHelper<maxon::Int>()
);
