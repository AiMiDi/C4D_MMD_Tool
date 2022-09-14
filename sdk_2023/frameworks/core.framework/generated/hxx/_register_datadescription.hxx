#if 1
namespace maxon
{
	const maxon::Char* const DataDescriptionInterface::MTable::_ids = 
		"Free@55dc67f7837a3f8b\0" // void Free(const DataDescriptionInterface* object)
		"Alloc@364075206d6a3720\0" // DataDescriptionInterface* Alloc(const maxon::SourceLocation& allocLocation)
		"Alloc@179716f53acf986\0" // DataDescriptionInterface* Alloc(const maxon::SourceLocation& allocLocation, const DataDescriptionInterface& object)
		"GetInfo@72a97bfbf261be68\0" // DataDictionary GetInfo() const
		"SetInfo@c224a0816826789a\0" // Result<void> SetInfo(const DataDictionary& info)
		"GetEntryCount@7d0e6f3d29c239e7\0" // Int GetEntryCount() const
		"GetEntries@127d72d0d8d3a4ef\0" // Result<BaseArray<DataDictionary>> GetEntries() const
		"GetEntry@aeba86b336a0b1fa\0" // Result<DataDictionary> GetEntry(const InternedId& id) const
		"FindEntry@aeba86b336a0b1fa\0" // Result<DataDictionary> FindEntry(const InternedId& id) const
		"SetEntry@566e28e14d5d8454\0" // Result<Bool> SetEntry(const DataDictionary& props, Bool merge)
		"EraseEntry@d66b72e91f9ac52e\0" // Result<void> EraseEntry(const InternedId& id)
		"Reset@780cdac8f1a33934\0" // void Reset()
		"IsEqual@178fb0bd39bae55a\0" // Bool IsEqual(const DataDescriptionInterface* other, EQUALITY equality) const
		"Compare@491723e5983f4912\0" // COMPARERESULT Compare(const DataDescriptionInterface* other) const
		"GetHashCode@b22918402154097b\0" // HashInt GetHashCode() const
		"GetUniqueHashCode@c78267ca5e388263\0" // UniqueHash GetUniqueHashCode() const
		"ToString@a73a45c584c879d4\0" // String ToString(const FormatStatement* formatStatement) const
		"DescribeIO@fe3f1bd5a495cc32\0" // Result<void> DescribeIO(const DataSerializeInterface& stream)
	"";
	MAXON_WARNING_PUSH
	MAXON_WARNING_DISABLE_DEPRECATED
	class DataDescriptionInterface::Hxx2::Unresolved : public DataDescriptionInterface
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
		Result<DataDictionary> FindEntry(const InternedId& id) const { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return ((const DataDescriptionInterface*) this)->FindEntry(id); return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::UNRESOLVED);}
		Result<Bool> SetEntry(const DataDictionary& props, Bool merge) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return ((DataDescriptionInterface*) this)->SetEntry(props, merge); return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::UNRESOLVED);}
		Result<void> EraseEntry(const InternedId& id) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return ((DataDescriptionInterface*) this)->EraseEntry(id); return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::UNRESOLVED);}
		void Reset() { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ((DataDescriptionInterface*) this)->Reset(); return maxon::PrivateLogNullptrError();}
		Bool IsEqual(const DataDescriptionInterface* other, EQUALITY equality) const { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ((const DataDescriptionInterface*) this)->IsEqual(other, equality); return maxon::PrivateLogNullptrError(false);}
		COMPARERESULT Compare(const DataDescriptionInterface* other) const { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ((const DataDescriptionInterface*) this)->Compare(other); return maxon::PrivateIncompleteNullReturnValue<COMPARERESULT>(maxon::NULL_RETURN_REASON::UNRESOLVED, OVERLOAD_MAX_RANK);}
		HashInt GetHashCode() const { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ((const DataDescriptionInterface*) this)->GetHashCode(); return maxon::PrivateIncompleteNullReturnValue<HashInt>(maxon::NULL_RETURN_REASON::UNRESOLVED, OVERLOAD_MAX_RANK);}
		UniqueHash GetUniqueHashCode() const { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ((const DataDescriptionInterface*) this)->GetUniqueHashCode(); return maxon::PrivateIncompleteNullReturnValue<UniqueHash>(maxon::NULL_RETURN_REASON::UNRESOLVED, OVERLOAD_MAX_RANK);}
		String ToString(const FormatStatement* formatStatement) const { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ((const DataDescriptionInterface*) this)->ToString(formatStatement); return maxon::PrivateIncompleteNullReturnValue<String>(maxon::NULL_RETURN_REASON::UNRESOLVED, OVERLOAD_MAX_RANK);}
		static Result<void> DescribeIO(const DataSerializeInterface& stream) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return DataDescriptionInterface::DescribeIO(stream); return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::UNRESOLVED);}
	};
	MAXON_WARNING_POP
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
		maxon::details::NullReturnType<Result<DataDictionary>>::value,
		maxon::details::NullReturnType<Result<Bool>>::value,
		maxon::details::NullReturnType<Result<void>>::value,
		maxon::details::NullReturnType<void>::value,
		maxon::details::NullReturnType<Bool>::value,
		maxon::details::NullReturnType<COMPARERESULT>::value,
		maxon::details::NullReturnType<HashInt>::value,
		maxon::details::NullReturnType<UniqueHash>::value,
		maxon::details::NullReturnType<String>::value,
		maxon::details::NullReturnType<Result<void>>::value,
		maxon::NULL_RETURN_TYPE::OTHER
	};
#endif
	maxon::Bool DataDescriptionInterface::MTable::InitUnresolved(maxon::NonvirtualInterfaceReference::UnresolvedAssembler assembler, MTable* tbl)
	{
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->DataDescriptionInterface_Free = PRIVATE_MAXON_MF_CAST(decltype(DataDescriptionInterface_Free), &Hxx2::Wrapper<Hxx2::Unresolved>::DataDescriptionInterface_Free);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->DataDescriptionInterface_Alloc = PRIVATE_MAXON_MF_CAST(decltype(DataDescriptionInterface_Alloc), &Hxx2::Wrapper<Hxx2::Unresolved>::DataDescriptionInterface_Alloc);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->DataDescriptionInterface_Alloc_1 = PRIVATE_MAXON_MF_CAST(decltype(DataDescriptionInterface_Alloc_1), &Hxx2::Wrapper<Hxx2::Unresolved>::DataDescriptionInterface_Alloc_1);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<DataDictionary>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->DataDescriptionInterface_GetInfo = PRIVATE_MAXON_MF_CAST(decltype(DataDescriptionInterface_GetInfo), &Hxx2::Wrapper<Hxx2::Unresolved>::DataDescriptionInterface_GetInfo);
		#else
		tbl->DataDescriptionInterface_GetInfo = PRIVATE_MAXON_MF_CAST(decltype(DataDescriptionInterface_GetInfo), &Hxx2::Wrapper<Hxx2::Unresolved>::DataDescriptionInterface_GetInfo);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<void>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->DataDescriptionInterface_SetInfo = PRIVATE_MAXON_MF_CAST(decltype(DataDescriptionInterface_SetInfo), &Hxx2::Wrapper<Hxx2::Unresolved>::DataDescriptionInterface_SetInfo);
		#else
		tbl->DataDescriptionInterface_SetInfo = PRIVATE_MAXON_MF_CAST(decltype(DataDescriptionInterface_SetInfo), &Hxx2::Wrapper<Hxx2::Unresolved>::DataDescriptionInterface_SetInfo);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->DataDescriptionInterface_GetEntryCount = PRIVATE_MAXON_MF_CAST(decltype(DataDescriptionInterface_GetEntryCount), &Hxx2::Wrapper<Hxx2::Unresolved>::DataDescriptionInterface_GetEntryCount);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<BaseArray<DataDictionary>>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->DataDescriptionInterface_GetEntries = PRIVATE_MAXON_MF_CAST(decltype(DataDescriptionInterface_GetEntries), &Hxx2::Wrapper<Hxx2::Unresolved>::DataDescriptionInterface_GetEntries);
		#else
		tbl->DataDescriptionInterface_GetEntries = PRIVATE_MAXON_MF_CAST(decltype(DataDescriptionInterface_GetEntries), &Hxx2::Wrapper<Hxx2::Unresolved>::DataDescriptionInterface_GetEntries);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<DataDictionary>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->DataDescriptionInterface_GetEntry = PRIVATE_MAXON_MF_CAST(decltype(DataDescriptionInterface_GetEntry), &Hxx2::Wrapper<Hxx2::Unresolved>::DataDescriptionInterface_GetEntry);
		#else
		tbl->DataDescriptionInterface_GetEntry = PRIVATE_MAXON_MF_CAST(decltype(DataDescriptionInterface_GetEntry), &Hxx2::Wrapper<Hxx2::Unresolved>::DataDescriptionInterface_GetEntry);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<DataDictionary>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->DataDescriptionInterface_FindEntry = PRIVATE_MAXON_MF_CAST(decltype(DataDescriptionInterface_FindEntry), &Hxx2::Wrapper<Hxx2::Unresolved>::DataDescriptionInterface_FindEntry);
		#else
		tbl->DataDescriptionInterface_FindEntry = PRIVATE_MAXON_MF_CAST(decltype(DataDescriptionInterface_FindEntry), &Hxx2::Wrapper<Hxx2::Unresolved>::DataDescriptionInterface_FindEntry);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<Bool>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->DataDescriptionInterface_SetEntry = PRIVATE_MAXON_MF_CAST(decltype(DataDescriptionInterface_SetEntry), &Hxx2::Wrapper<Hxx2::Unresolved>::DataDescriptionInterface_SetEntry);
		#else
		tbl->DataDescriptionInterface_SetEntry = PRIVATE_MAXON_MF_CAST(decltype(DataDescriptionInterface_SetEntry), &Hxx2::Wrapper<Hxx2::Unresolved>::DataDescriptionInterface_SetEntry);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<void>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->DataDescriptionInterface_EraseEntry = PRIVATE_MAXON_MF_CAST(decltype(DataDescriptionInterface_EraseEntry), &Hxx2::Wrapper<Hxx2::Unresolved>::DataDescriptionInterface_EraseEntry);
		#else
		tbl->DataDescriptionInterface_EraseEntry = PRIVATE_MAXON_MF_CAST(decltype(DataDescriptionInterface_EraseEntry), &Hxx2::Wrapper<Hxx2::Unresolved>::DataDescriptionInterface_EraseEntry);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->DataDescriptionInterface_Reset = PRIVATE_MAXON_MF_CAST(decltype(DataDescriptionInterface_Reset), &Hxx2::Wrapper<Hxx2::Unresolved>::DataDescriptionInterface_Reset);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->DataDescriptionInterface_IsEqual = PRIVATE_MAXON_MF_CAST(decltype(DataDescriptionInterface_IsEqual), &Hxx2::Wrapper<Hxx2::Unresolved>::DataDescriptionInterface_IsEqual);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<COMPARERESULT>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->DataDescriptionInterface_Compare = PRIVATE_MAXON_MF_CAST(decltype(DataDescriptionInterface_Compare), &Hxx2::Wrapper<Hxx2::Unresolved>::DataDescriptionInterface_Compare);
		#else
		tbl->DataDescriptionInterface_Compare = PRIVATE_MAXON_MF_CAST(decltype(DataDescriptionInterface_Compare), &Hxx2::Wrapper<Hxx2::Unresolved>::DataDescriptionInterface_Compare);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<HashInt>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->DataDescriptionInterface_GetHashCode = PRIVATE_MAXON_MF_CAST(decltype(DataDescriptionInterface_GetHashCode), &Hxx2::Wrapper<Hxx2::Unresolved>::DataDescriptionInterface_GetHashCode);
		#else
		tbl->DataDescriptionInterface_GetHashCode = PRIVATE_MAXON_MF_CAST(decltype(DataDescriptionInterface_GetHashCode), &Hxx2::Wrapper<Hxx2::Unresolved>::DataDescriptionInterface_GetHashCode);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<UniqueHash>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->DataDescriptionInterface_GetUniqueHashCode = PRIVATE_MAXON_MF_CAST(decltype(DataDescriptionInterface_GetUniqueHashCode), &Hxx2::Wrapper<Hxx2::Unresolved>::DataDescriptionInterface_GetUniqueHashCode);
		#else
		tbl->DataDescriptionInterface_GetUniqueHashCode = PRIVATE_MAXON_MF_CAST(decltype(DataDescriptionInterface_GetUniqueHashCode), &Hxx2::Wrapper<Hxx2::Unresolved>::DataDescriptionInterface_GetUniqueHashCode);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<String>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->DataDescriptionInterface_ToString = PRIVATE_MAXON_MF_CAST(decltype(DataDescriptionInterface_ToString), &Hxx2::Wrapper<Hxx2::Unresolved>::DataDescriptionInterface_ToString);
		#else
		tbl->DataDescriptionInterface_ToString = PRIVATE_MAXON_MF_CAST(decltype(DataDescriptionInterface_ToString), &Hxx2::Wrapper<Hxx2::Unresolved>::DataDescriptionInterface_ToString);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<void>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->DataDescriptionInterface_DescribeIO = PRIVATE_MAXON_MF_CAST(decltype(DataDescriptionInterface_DescribeIO), &Hxx2::Wrapper<Hxx2::Unresolved>::DataDescriptionInterface_DescribeIO);
		#else
		tbl->DataDescriptionInterface_DescribeIO = PRIVATE_MAXON_MF_CAST(decltype(DataDescriptionInterface_DescribeIO), &Hxx2::Wrapper<Hxx2::Unresolved>::DataDescriptionInterface_DescribeIO);
		#endif
	#ifdef PRIVATE_MAXON_ASSEMBLE_UNRESOLVED
		return assembler(&_interface, (maxon::Char*) tbl, _returnTypes, SIZEOF(MTable) / SIZEOF(void*));
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
		| maxon::details::InstantiateNullReturnValue<HashInt>(OVERLOAD_MAX_RANK)
		| maxon::details::InstantiateNullReturnValue<String>(OVERLOAD_MAX_RANK)
		| maxon::details::InstantiateNullReturnValue<UniqueHash>(OVERLOAD_MAX_RANK)
		;
	}
	MAXON_REGISTRY_REGISTER(LegacyDataTypeIdentifiers);
	PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(DT_LanguageStringDataDescription,, "net.maxon.datatype.languagestringdatadescription");
}
#endif
static maxon::details::ForceEvaluation s_forceEval_datadescription(0
	| maxon::DataDescriptionInterface::PrivateInstantiateNullValueHelper<maxon::Int>()
);
