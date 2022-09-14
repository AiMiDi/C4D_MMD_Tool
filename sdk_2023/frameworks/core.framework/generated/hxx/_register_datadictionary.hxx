#if 1
namespace maxon
{
	const maxon::Char* const DataDictionaryInterface::MTable::_ids = 
		"Free@27b45b1030b8e767\0" // void Free(const DataDictionaryInterface* object)
		"Alloc@5845cf5b540cbb9c\0" // DataDictionaryInterface* Alloc(const maxon::SourceLocation& allocLocation)
		"Alloc@b8d395d82bf2d158\0" // DataDictionaryInterface* Alloc(const maxon::SourceLocation& allocLocation, const DataDictionaryInterface& object)
		"SetData@d6bc5a29ae638c7d\0" // Result<void> SetData(ForwardingDataPtr&& key, const Data& data)
		"SetData@5ad8bc0e8a8c4eb4\0" // Result<void> SetData(ForwardingDataPtr&& key, Data&& data)
		"SetData@2a7a44c909d5344f\0" // Result<void> SetData(ForwardingDataPtr&& key, ForwardingDataPtr&& data)
		"GetData@2650f729e23305a1\0" // Result<Data> GetData(const ConstDataPtr& key) const
		"EraseData@c5d3e89b5a93d41f\0" // Result<void> EraseData(const ConstDataPtr& key)
		"Reset@780cdac8f1a33934\0" // void Reset()
		"GetCount@7d0e6f3d29c239e7\0" // Int GetCount() const
		"ToString@a73a45c584c879d4\0" // String ToString(const FormatStatement* formatStatement) const
		"DescribeIO@fe3f1bd5a495cc32\0" // Result<void> DescribeIO(const DataSerializeInterface& stream)
		"IsEqual@6be0d5c18a85f80e\0" // Bool IsEqual(const DataDictionaryInterface* other, EQUALITY equality) const
		"GetHashCode@b22918402154097b\0" // HashInt GetHashCode() const
		"GetUniqueHashCode@c78267ca5e388263\0" // UniqueHash GetUniqueHashCode() const
		"InitIterator@f436aec054ec7c6b\0" // void InitIterator(DataDictionaryIteratorInterface* iterator, Bool end) const
		"PrivateGetData@d7b63e43cdf7e441\0" // const Data* PrivateGetData(const ConstDataPtr& key) const
	"";
	MAXON_WARNING_PUSH
	MAXON_WARNING_DISABLE_DEPRECATED
	class DataDictionaryInterface::Hxx2::Unresolved : public DataDictionaryInterface
	{
	public:
		static const Unresolved* Get(const DataDictionaryInterface* o) { return (const Unresolved*) o; }
		static Unresolved* Get(DataDictionaryInterface* o) { return (Unresolved*) o; }
		static void Free(const DataDictionaryInterface* object) { if (object && maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return DataDictionaryInterface::Free(object); return maxon::PrivateLogNullptrError();}
		static DataDictionaryInterface* Alloc(const maxon::SourceLocation& allocLocation) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return DataDictionaryInterface::Alloc(allocLocation); return nullptr;}
		static DataDictionaryInterface* Alloc(const maxon::SourceLocation& allocLocation, const DataDictionaryInterface& object) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return DataDictionaryInterface::Alloc(allocLocation, object); return nullptr;}
		Result<void> SetData(ForwardingDataPtr&& key, const Data& data) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return ((DataDictionaryInterface*) this)->SetData(std::forward<ForwardingDataPtr>(key), data); return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::UNRESOLVED);}
		Result<void> SetData(ForwardingDataPtr&& key, Data&& data) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return ((DataDictionaryInterface*) this)->SetData(std::forward<ForwardingDataPtr>(key), std::forward<Data>(data)); return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::UNRESOLVED);}
		Result<void> SetData(ForwardingDataPtr&& key, ForwardingDataPtr&& data) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return ((DataDictionaryInterface*) this)->SetData(std::forward<ForwardingDataPtr>(key), std::forward<ForwardingDataPtr>(data)); return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::UNRESOLVED);}
		Result<Data> GetData(const ConstDataPtr& key) const { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return ((const DataDictionaryInterface*) this)->GetData(key); return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::UNRESOLVED);}
		Result<void> EraseData(const ConstDataPtr& key) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return ((DataDictionaryInterface*) this)->EraseData(key); return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::UNRESOLVED);}
		void Reset() { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ((DataDictionaryInterface*) this)->Reset(); return maxon::PrivateLogNullptrError();}
		Int GetCount() const { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ((const DataDictionaryInterface*) this)->GetCount(); return 0;}
		String ToString(const FormatStatement* formatStatement) const { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ((const DataDictionaryInterface*) this)->ToString(formatStatement); return maxon::PrivateIncompleteNullReturnValue<String>(maxon::NULL_RETURN_REASON::UNRESOLVED, OVERLOAD_MAX_RANK);}
		static Result<void> DescribeIO(const DataSerializeInterface& stream) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return DataDictionaryInterface::DescribeIO(stream); return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::UNRESOLVED);}
		Bool IsEqual(const DataDictionaryInterface* other, EQUALITY equality) const { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ((const DataDictionaryInterface*) this)->IsEqual(other, equality); return maxon::PrivateLogNullptrError(false);}
		HashInt GetHashCode() const { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ((const DataDictionaryInterface*) this)->GetHashCode(); return maxon::PrivateIncompleteNullReturnValue<HashInt>(maxon::NULL_RETURN_REASON::UNRESOLVED, OVERLOAD_MAX_RANK);}
		UniqueHash GetUniqueHashCode() const { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ((const DataDictionaryInterface*) this)->GetUniqueHashCode(); return maxon::PrivateIncompleteNullReturnValue<UniqueHash>(maxon::NULL_RETURN_REASON::UNRESOLVED, OVERLOAD_MAX_RANK);}
		void InitIterator(DataDictionaryIteratorInterface* iterator, Bool end) const { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ((const DataDictionaryInterface*) this)->InitIterator(iterator, end); return maxon::PrivateLogNullptrError();}
		const Data* PrivateGetData(const ConstDataPtr& key) const { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ((const DataDictionaryInterface*) this)->PrivateGetData(key); return nullptr;}
	};
	MAXON_WARNING_POP
#ifdef PRIVATE_MAXON_ASSEMBLE_UNRESOLVED
	const maxon::NULL_RETURN_TYPE DataDictionaryInterface::MTable::_returnTypes[] = 
	{
		maxon::NULL_RETURN_TYPE::VOID_ZERO_FREE_FUNCTION,
		maxon::details::NullReturnType<DataDictionaryInterface*>::value,
		maxon::details::NullReturnType<DataDictionaryInterface*>::value,
		maxon::details::NullReturnType<Result<void>>::value,
		maxon::details::NullReturnType<Result<void>>::value,
		maxon::details::NullReturnType<Result<void>>::value,
		maxon::details::NullReturnType<Result<Data>>::value,
		maxon::details::NullReturnType<Result<void>>::value,
		maxon::details::NullReturnType<void>::value,
		maxon::details::NullReturnType<Int>::value,
		maxon::details::NullReturnType<String>::value,
		maxon::details::NullReturnType<Result<void>>::value,
		maxon::details::NullReturnType<Bool>::value,
		maxon::details::NullReturnType<HashInt>::value,
		maxon::details::NullReturnType<UniqueHash>::value,
		maxon::details::NullReturnType<void>::value,
		maxon::details::NullReturnType<const Data*>::value,
		maxon::NULL_RETURN_TYPE::OTHER
	};
#endif
	maxon::Bool DataDictionaryInterface::MTable::InitUnresolved(maxon::NonvirtualInterfaceReference::UnresolvedAssembler assembler, MTable* tbl)
	{
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->DataDictionaryInterface_Free = PRIVATE_MAXON_MF_CAST(decltype(DataDictionaryInterface_Free), &Hxx2::Wrapper<Hxx2::Unresolved>::DataDictionaryInterface_Free);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->DataDictionaryInterface_Alloc = PRIVATE_MAXON_MF_CAST(decltype(DataDictionaryInterface_Alloc), &Hxx2::Wrapper<Hxx2::Unresolved>::DataDictionaryInterface_Alloc);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->DataDictionaryInterface_Alloc_1 = PRIVATE_MAXON_MF_CAST(decltype(DataDictionaryInterface_Alloc_1), &Hxx2::Wrapper<Hxx2::Unresolved>::DataDictionaryInterface_Alloc_1);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<void>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->DataDictionaryInterface_SetData = PRIVATE_MAXON_MF_CAST(decltype(DataDictionaryInterface_SetData), &Hxx2::Wrapper<Hxx2::Unresolved>::DataDictionaryInterface_SetData);
		#else
		tbl->DataDictionaryInterface_SetData = PRIVATE_MAXON_MF_CAST(decltype(DataDictionaryInterface_SetData), &Hxx2::Wrapper<Hxx2::Unresolved>::DataDictionaryInterface_SetData);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<void>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->DataDictionaryInterface_SetData_1 = PRIVATE_MAXON_MF_CAST(decltype(DataDictionaryInterface_SetData_1), &Hxx2::Wrapper<Hxx2::Unresolved>::DataDictionaryInterface_SetData_1);
		#else
		tbl->DataDictionaryInterface_SetData_1 = PRIVATE_MAXON_MF_CAST(decltype(DataDictionaryInterface_SetData_1), &Hxx2::Wrapper<Hxx2::Unresolved>::DataDictionaryInterface_SetData_1);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<void>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->DataDictionaryInterface_SetData_2 = PRIVATE_MAXON_MF_CAST(decltype(DataDictionaryInterface_SetData_2), &Hxx2::Wrapper<Hxx2::Unresolved>::DataDictionaryInterface_SetData_2);
		#else
		tbl->DataDictionaryInterface_SetData_2 = PRIVATE_MAXON_MF_CAST(decltype(DataDictionaryInterface_SetData_2), &Hxx2::Wrapper<Hxx2::Unresolved>::DataDictionaryInterface_SetData_2);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<Data>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->DataDictionaryInterface_GetData = PRIVATE_MAXON_MF_CAST(decltype(DataDictionaryInterface_GetData), &Hxx2::Wrapper<Hxx2::Unresolved>::DataDictionaryInterface_GetData);
		#else
		tbl->DataDictionaryInterface_GetData = PRIVATE_MAXON_MF_CAST(decltype(DataDictionaryInterface_GetData), &Hxx2::Wrapper<Hxx2::Unresolved>::DataDictionaryInterface_GetData);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<void>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->DataDictionaryInterface_EraseData = PRIVATE_MAXON_MF_CAST(decltype(DataDictionaryInterface_EraseData), &Hxx2::Wrapper<Hxx2::Unresolved>::DataDictionaryInterface_EraseData);
		#else
		tbl->DataDictionaryInterface_EraseData = PRIVATE_MAXON_MF_CAST(decltype(DataDictionaryInterface_EraseData), &Hxx2::Wrapper<Hxx2::Unresolved>::DataDictionaryInterface_EraseData);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->DataDictionaryInterface_Reset = PRIVATE_MAXON_MF_CAST(decltype(DataDictionaryInterface_Reset), &Hxx2::Wrapper<Hxx2::Unresolved>::DataDictionaryInterface_Reset);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->DataDictionaryInterface_GetCount = PRIVATE_MAXON_MF_CAST(decltype(DataDictionaryInterface_GetCount), &Hxx2::Wrapper<Hxx2::Unresolved>::DataDictionaryInterface_GetCount);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<String>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->DataDictionaryInterface_ToString = PRIVATE_MAXON_MF_CAST(decltype(DataDictionaryInterface_ToString), &Hxx2::Wrapper<Hxx2::Unresolved>::DataDictionaryInterface_ToString);
		#else
		tbl->DataDictionaryInterface_ToString = PRIVATE_MAXON_MF_CAST(decltype(DataDictionaryInterface_ToString), &Hxx2::Wrapper<Hxx2::Unresolved>::DataDictionaryInterface_ToString);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<void>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->DataDictionaryInterface_DescribeIO = PRIVATE_MAXON_MF_CAST(decltype(DataDictionaryInterface_DescribeIO), &Hxx2::Wrapper<Hxx2::Unresolved>::DataDictionaryInterface_DescribeIO);
		#else
		tbl->DataDictionaryInterface_DescribeIO = PRIVATE_MAXON_MF_CAST(decltype(DataDictionaryInterface_DescribeIO), &Hxx2::Wrapper<Hxx2::Unresolved>::DataDictionaryInterface_DescribeIO);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->DataDictionaryInterface_IsEqual = PRIVATE_MAXON_MF_CAST(decltype(DataDictionaryInterface_IsEqual), &Hxx2::Wrapper<Hxx2::Unresolved>::DataDictionaryInterface_IsEqual);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<HashInt>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->DataDictionaryInterface_GetHashCode = PRIVATE_MAXON_MF_CAST(decltype(DataDictionaryInterface_GetHashCode), &Hxx2::Wrapper<Hxx2::Unresolved>::DataDictionaryInterface_GetHashCode);
		#else
		tbl->DataDictionaryInterface_GetHashCode = PRIVATE_MAXON_MF_CAST(decltype(DataDictionaryInterface_GetHashCode), &Hxx2::Wrapper<Hxx2::Unresolved>::DataDictionaryInterface_GetHashCode);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<UniqueHash>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->DataDictionaryInterface_GetUniqueHashCode = PRIVATE_MAXON_MF_CAST(decltype(DataDictionaryInterface_GetUniqueHashCode), &Hxx2::Wrapper<Hxx2::Unresolved>::DataDictionaryInterface_GetUniqueHashCode);
		#else
		tbl->DataDictionaryInterface_GetUniqueHashCode = PRIVATE_MAXON_MF_CAST(decltype(DataDictionaryInterface_GetUniqueHashCode), &Hxx2::Wrapper<Hxx2::Unresolved>::DataDictionaryInterface_GetUniqueHashCode);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->DataDictionaryInterface_InitIterator = PRIVATE_MAXON_MF_CAST(decltype(DataDictionaryInterface_InitIterator), &Hxx2::Wrapper<Hxx2::Unresolved>::DataDictionaryInterface_InitIterator);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->DataDictionaryInterface_PrivateGetData = PRIVATE_MAXON_MF_CAST(decltype(DataDictionaryInterface_PrivateGetData), &Hxx2::Wrapper<Hxx2::Unresolved>::DataDictionaryInterface_PrivateGetData);
		#endif
	#ifdef PRIVATE_MAXON_ASSEMBLE_UNRESOLVED
		return assembler(&_interface, (maxon::Char*) tbl, _returnTypes, SIZEOF(MTable) / SIZEOF(void*));
	#else
		return true;
	#endif
	}
	MAXON_INTERFACE_REGISTER(DataDictionaryInterface, "net.maxon.interface.datadictionary", nullptr);
	template <typename DUMMY> maxon::Int DataDictionaryInterface::PrivateInstantiateNullValueHelper()
	{
		return 0
		| maxon::details::InstantiateNullReturnValue<ConstIterator>(OVERLOAD_MAX_RANK)
		| maxon::details::InstantiateNullReturnValue<HashInt>(OVERLOAD_MAX_RANK)
		| maxon::details::InstantiateNullReturnValue<String>(OVERLOAD_MAX_RANK)
		| maxon::details::InstantiateNullReturnValue<UniqueHash>(OVERLOAD_MAX_RANK)
		;
	}
}
#endif
static maxon::details::ForceEvaluation s_forceEval_datadictionary(0
	| maxon::DataDictionaryInterface::PrivateInstantiateNullValueHelper<maxon::Int>()
);
