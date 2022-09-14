
#ifndef DOXYGEN

#if defined MAXON_COMPILER_GCC
	#pragma GCC diagnostic push
	#if MAXON_COMPILER_GCC >= 600
		#pragma GCC diagnostic ignored "-Wmisleading-indentation"
	#endif
#endif

#if 1
constexpr const maxon::Char* DataDescriptionInterface::PrivateGetCppName() { return "maxon::DataDescription"; }

struct DataDescriptionInterface::MTable
{
	static MTable _instance;
	static MTable _unresolvedInstance;
	static const maxon::Char* const _ids;
	static maxon::Bool InitUnresolved(maxon::NonvirtualInterfaceReference::UnresolvedAssembler assembler, MTable* tbl);
	static const maxon::NULL_RETURN_TYPE _returnTypes[];
	static const maxon::Bool HAS_NONSTATIC = true;
	PRIVATE_MAXON_SF_POINTER(DataDescriptionInterface_Free, Free, MAXON_EXPAND_VA_ARGS, (void), const DataDescriptionInterface* object);
	PRIVATE_MAXON_SF_POINTER(DataDescriptionInterface_Alloc, Alloc, MAXON_IGNORE_VA_ARGS, (DataDescriptionInterface*), const maxon::SourceLocation& allocLocation);
	PRIVATE_MAXON_SF_POINTER(DataDescriptionInterface_Alloc_1, Alloc, MAXON_IGNORE_VA_ARGS, (DataDescriptionInterface*), const maxon::SourceLocation& allocLocation, const DataDescriptionInterface& object);
	PRIVATE_MAXON_MF_POINTER(DataDescriptionInterface_GetInfo, GetInfo, false, DataDescriptionInterface, const, (DataDictionary));
	PRIVATE_MAXON_MF_POINTER(DataDescriptionInterface_SetInfo, SetInfo, false, DataDescriptionInterface,, (Result<void>), const DataDictionary& info);
	PRIVATE_MAXON_MF_POINTER(DataDescriptionInterface_GetEntryCount, GetEntryCount, false, DataDescriptionInterface, const, (Int));
	PRIVATE_MAXON_MF_POINTER(DataDescriptionInterface_GetEntries, GetEntries, false, DataDescriptionInterface, const, (Result<BaseArray<DataDictionary>>));
	PRIVATE_MAXON_MF_POINTER(DataDescriptionInterface_GetEntry, GetEntry, false, DataDescriptionInterface, const, (Result<DataDictionary>), const InternedId& id);
	PRIVATE_MAXON_MF_POINTER(DataDescriptionInterface_FindEntry, FindEntry, false, DataDescriptionInterface, const, (Result<DataDictionary>), const InternedId& id);
	PRIVATE_MAXON_MF_POINTER(DataDescriptionInterface_SetEntry, SetEntry, false, DataDescriptionInterface,, (Result<Bool>), const DataDictionary& props, Bool merge);
	PRIVATE_MAXON_MF_POINTER(DataDescriptionInterface_EraseEntry, EraseEntry, false, DataDescriptionInterface,, (Result<void>), const InternedId& id);
	PRIVATE_MAXON_MF_POINTER(DataDescriptionInterface_Reset, Reset, false, DataDescriptionInterface,, (void));
	PRIVATE_MAXON_MF_POINTER(DataDescriptionInterface_IsEqual, IsEqual, false, DataDescriptionInterface, const, (Bool), const DataDescriptionInterface* other, EQUALITY equality);
	PRIVATE_MAXON_MF_POINTER(DataDescriptionInterface_Compare, Compare, false, DataDescriptionInterface, const, (COMPARERESULT), const DataDescriptionInterface* other);
	PRIVATE_MAXON_MF_POINTER(DataDescriptionInterface_GetHashCode, GetHashCode, false, DataDescriptionInterface, const, (HashInt));
	PRIVATE_MAXON_MF_POINTER(DataDescriptionInterface_GetUniqueHashCode, GetUniqueHashCode, false, DataDescriptionInterface, const, (UniqueHash));
	PRIVATE_MAXON_MF_POINTER(DataDescriptionInterface_ToString, ToString, false, DataDescriptionInterface, const, (String), const FormatStatement* formatStatement);
	PRIVATE_MAXON_SF_POINTER(DataDescriptionInterface_DescribeIO, DescribeIO, MAXON_EXPAND_VA_ARGS, (Result<void>), const DataSerializeInterface& stream);
	template <typename IMPL> void Init()
	{
		DataDescriptionInterface_Free = DataDescriptionInterface_Free_GetPtr<IMPL>(true);
		DataDescriptionInterface_Alloc = DataDescriptionInterface_Alloc_GetPtr<IMPL>(true);
		DataDescriptionInterface_Alloc_1 = DataDescriptionInterface_Alloc_1_GetPtr<IMPL>(true);
		DataDescriptionInterface_GetInfo = DataDescriptionInterface_GetInfo_GetPtr<IMPL>(0, true).first;
		DataDescriptionInterface_SetInfo = DataDescriptionInterface_SetInfo_GetPtr<IMPL>(0, true).first;
		DataDescriptionInterface_GetEntryCount = DataDescriptionInterface_GetEntryCount_GetPtr<IMPL>(0, true).first;
		DataDescriptionInterface_GetEntries = DataDescriptionInterface_GetEntries_GetPtr<IMPL>(0, true).first;
		DataDescriptionInterface_GetEntry = DataDescriptionInterface_GetEntry_GetPtr<IMPL>(0, true).first;
		DataDescriptionInterface_FindEntry = DataDescriptionInterface_FindEntry_GetPtr<IMPL>(0, true).first;
		DataDescriptionInterface_SetEntry = DataDescriptionInterface_SetEntry_GetPtr<IMPL>(0, true).first;
		DataDescriptionInterface_EraseEntry = DataDescriptionInterface_EraseEntry_GetPtr<IMPL>(0, true).first;
		DataDescriptionInterface_Reset = DataDescriptionInterface_Reset_GetPtr<IMPL>(0, true).first;
		DataDescriptionInterface_IsEqual = DataDescriptionInterface_IsEqual_GetPtr<IMPL>(0, true).first;
		DataDescriptionInterface_Compare = DataDescriptionInterface_Compare_GetPtr<IMPL>(0, true).first;
		DataDescriptionInterface_GetHashCode = DataDescriptionInterface_GetHashCode_GetPtr<IMPL>(0, true).first;
		DataDescriptionInterface_GetUniqueHashCode = DataDescriptionInterface_GetUniqueHashCode_GetPtr<IMPL>(0, true).first;
		DataDescriptionInterface_ToString = DataDescriptionInterface_ToString_GetPtr<IMPL>(0, true).first;
		DataDescriptionInterface_DescribeIO = DataDescriptionInterface_DescribeIO_GetPtr<IMPL>(true);
	}
};

struct DataDescriptionInterface::Hxx2
{
	class Unresolved;
	template <typename C> class Wrapper
	{
	public:
		using Implementation = C;
		static void DataDescriptionInterface_Free(const DataDescriptionInterface* object) { return C::Free(object); }
		static DataDescriptionInterface* DataDescriptionInterface_Alloc(const maxon::SourceLocation& allocLocation) { return C::Alloc(allocLocation); }
		static DataDescriptionInterface* DataDescriptionInterface_Alloc_1(const maxon::SourceLocation& allocLocation, const DataDescriptionInterface& object) { return C::Alloc(allocLocation, ((const C&) object)); }
		PRIVATE_MAXON_MF_WRAPPER(DataDescriptionInterface_GetInfo, DataDescriptionInterface, const, (DataDictionary)) { return C::Get(PRIVATE_MAXON_MF_THIS(const DataDescriptionInterface))->GetInfo(); }
		PRIVATE_MAXON_MF_WRAPPER(DataDescriptionInterface_SetInfo, DataDescriptionInterface,, (Result<void>), const DataDictionary& info) { return C::Get(PRIVATE_MAXON_MF_THIS(DataDescriptionInterface))->SetInfo(info); }
		PRIVATE_MAXON_MF_WRAPPER(DataDescriptionInterface_GetEntryCount, DataDescriptionInterface, const, (Int)) { return C::Get(PRIVATE_MAXON_MF_THIS(const DataDescriptionInterface))->GetEntryCount(); }
		PRIVATE_MAXON_MF_WRAPPER(DataDescriptionInterface_GetEntries, DataDescriptionInterface, const, (Result<BaseArray<DataDictionary>>)) { return C::Get(PRIVATE_MAXON_MF_THIS(const DataDescriptionInterface))->GetEntries(); }
		PRIVATE_MAXON_MF_WRAPPER(DataDescriptionInterface_GetEntry, DataDescriptionInterface, const, (Result<DataDictionary>), const InternedId& id) { return C::Get(PRIVATE_MAXON_MF_THIS(const DataDescriptionInterface))->GetEntry(id); }
		PRIVATE_MAXON_MF_WRAPPER(DataDescriptionInterface_FindEntry, DataDescriptionInterface, const, (Result<DataDictionary>), const InternedId& id) { return C::Get(PRIVATE_MAXON_MF_THIS(const DataDescriptionInterface))->FindEntry(id); }
		PRIVATE_MAXON_MF_WRAPPER(DataDescriptionInterface_SetEntry, DataDescriptionInterface,, (Result<Bool>), const DataDictionary& props, Bool merge) { return C::Get(PRIVATE_MAXON_MF_THIS(DataDescriptionInterface))->SetEntry(props, merge); }
		PRIVATE_MAXON_MF_WRAPPER(DataDescriptionInterface_EraseEntry, DataDescriptionInterface,, (Result<void>), const InternedId& id) { return C::Get(PRIVATE_MAXON_MF_THIS(DataDescriptionInterface))->EraseEntry(id); }
		PRIVATE_MAXON_MF_WRAPPER(DataDescriptionInterface_Reset, DataDescriptionInterface,, (void)) { return C::Get(PRIVATE_MAXON_MF_THIS(DataDescriptionInterface))->Reset(); }
		PRIVATE_MAXON_MF_WRAPPER(DataDescriptionInterface_IsEqual, DataDescriptionInterface, const, (Bool), const DataDescriptionInterface* other, EQUALITY equality) { return C::Get(PRIVATE_MAXON_MF_THIS(const DataDescriptionInterface))->IsEqual(other, equality); }
		PRIVATE_MAXON_MF_WRAPPER(DataDescriptionInterface_Compare, DataDescriptionInterface, const, (COMPARERESULT), const DataDescriptionInterface* other) { return C::Get(PRIVATE_MAXON_MF_THIS(const DataDescriptionInterface))->Compare(other); }
		PRIVATE_MAXON_MF_WRAPPER(DataDescriptionInterface_GetHashCode, DataDescriptionInterface, const, (HashInt)) { return C::Get(PRIVATE_MAXON_MF_THIS(const DataDescriptionInterface))->GetHashCode(); }
		PRIVATE_MAXON_MF_WRAPPER(DataDescriptionInterface_GetUniqueHashCode, DataDescriptionInterface, const, (UniqueHash)) { return C::Get(PRIVATE_MAXON_MF_THIS(const DataDescriptionInterface))->GetUniqueHashCode(); }
		PRIVATE_MAXON_MF_WRAPPER(DataDescriptionInterface_ToString, DataDescriptionInterface, const, (String), const FormatStatement* formatStatement) { return C::Get(PRIVATE_MAXON_MF_THIS(const DataDescriptionInterface))->ToString(formatStatement); }
		static Result<void> DataDescriptionInterface_DescribeIO(const DataSerializeInterface& stream) { return C::DescribeIO(stream); }
	};

};
MAXON_ATTRIBUTE_FORCE_INLINE auto DataDescriptionInterface::Free(const DataDescriptionInterface* object) -> void
{
	return MTable::_instance.DataDescriptionInterface_Free(object);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto DataDescriptionInterface::Alloc(const maxon::SourceLocation& allocLocation) -> DataDescriptionInterface*
{
	return MTable::_instance.DataDescriptionInterface_Alloc(allocLocation);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto DataDescriptionInterface::Alloc(const maxon::SourceLocation& allocLocation, const DataDescriptionInterface& object) -> DataDescriptionInterface*
{
	return MTable::_instance.DataDescriptionInterface_Alloc_1(allocLocation, object);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto DataDescriptionInterface::GetInfo() const -> DataDictionary
{
	return PRIVATE_MAXON_MF_INVOKE((this), MTable::_instance.DataDescriptionInterface_GetInfo);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto DataDescriptionInterface::SetInfo(const DataDictionary& info) -> Result<void>
{
	return PRIVATE_MAXON_MF_INVOKE((this), MTable::_instance.DataDescriptionInterface_SetInfo, info);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto DataDescriptionInterface::GetEntryCount() const -> Int
{
	return PRIVATE_MAXON_MF_INVOKE((this), MTable::_instance.DataDescriptionInterface_GetEntryCount);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto DataDescriptionInterface::GetEntries() const -> Result<BaseArray<DataDictionary>>
{
	return PRIVATE_MAXON_MF_INVOKE((this), MTable::_instance.DataDescriptionInterface_GetEntries);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto DataDescriptionInterface::GetEntry(const InternedId& id) const -> Result<DataDictionary>
{
	return PRIVATE_MAXON_MF_INVOKE((this), MTable::_instance.DataDescriptionInterface_GetEntry, id);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto DataDescriptionInterface::FindEntry(const InternedId& id) const -> Result<DataDictionary>
{
	return PRIVATE_MAXON_MF_INVOKE((this), MTable::_instance.DataDescriptionInterface_FindEntry, id);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto DataDescriptionInterface::SetEntry(const DataDictionary& props, Bool merge) -> Result<Bool>
{
	return PRIVATE_MAXON_MF_INVOKE((this), MTable::_instance.DataDescriptionInterface_SetEntry, props, merge);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto DataDescriptionInterface::EraseEntry(const InternedId& id) -> Result<void>
{
	return PRIVATE_MAXON_MF_INVOKE((this), MTable::_instance.DataDescriptionInterface_EraseEntry, id);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto DataDescriptionInterface::Reset() -> void
{
	return PRIVATE_MAXON_MF_INVOKE((this), MTable::_instance.DataDescriptionInterface_Reset);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto DataDescriptionInterface::IsEqual(const DataDescriptionInterface* other, EQUALITY equality) const -> Bool
{
	return PRIVATE_MAXON_MF_INVOKE((this), MTable::_instance.DataDescriptionInterface_IsEqual, other, equality);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto DataDescriptionInterface::Compare(const DataDescriptionInterface* other) const -> COMPARERESULT
{
	return PRIVATE_MAXON_MF_INVOKE((this), MTable::_instance.DataDescriptionInterface_Compare, other);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto DataDescriptionInterface::GetHashCode() const -> HashInt
{
	return PRIVATE_MAXON_MF_INVOKE((this), MTable::_instance.DataDescriptionInterface_GetHashCode);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto DataDescriptionInterface::GetUniqueHashCode() const -> UniqueHash
{
	return PRIVATE_MAXON_MF_INVOKE((this), MTable::_instance.DataDescriptionInterface_GetUniqueHashCode);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto DataDescriptionInterface::ToString(const FormatStatement* formatStatement) const -> String
{
	return PRIVATE_MAXON_MF_INVOKE((this), MTable::_instance.DataDescriptionInterface_ToString, formatStatement);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto DataDescriptionInterface::DescribeIO(const DataSerializeInterface& stream) -> Result<void>
{
	return MTable::_instance.DataDescriptionInterface_DescribeIO(stream);
}

auto DataDescriptionInterface::Hxx1::Reference::Create() -> maxon::ResultMemT<DataDescription>
{
	DataDescriptionInterface* res_ = DataDescriptionInterface::Alloc(MAXON_SOURCE_LOCATION);
	return DataDescription(maxon::ForwardResultPtr<DataDescriptionInterface>(res_));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto DataDescriptionInterface::Hxx1::ConstFn<S>::GetInfo() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<DataDictionary>, DataDictionary>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<DataDictionary>, DataDictionary>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const DataDescriptionInterface* o_ = (const DataDescriptionInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = DataDescriptionInterface::NullValuePtr(); if (!o_) return maxon::PrivateIncompleteNullReturnValue<DataDictionary>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.DataDescriptionInterface_GetInfo));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto DataDescriptionInterface::Hxx1::Fn<S>::SetInfo(const DataDictionary& info) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); DataDescriptionInterface* o_ = (DataDescriptionInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.DataDescriptionInterface_SetInfo, info));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto DataDescriptionInterface::Hxx1::COWFn<S>::SetInfo(const DataDictionary& info) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); DataDescriptionInterface* o_ = (DataDescriptionInterface*) this->MakeWritable(true).GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.DataDescriptionInterface_SetInfo, info));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto DataDescriptionInterface::Hxx1::ConstFn<S>::GetEntryCount() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const DataDescriptionInterface* o_ = (const DataDescriptionInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = DataDescriptionInterface::NullValuePtr(); if (!o_) return 0; } 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.DataDescriptionInterface_GetEntryCount));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto DataDescriptionInterface::Hxx1::ConstFn<S>::GetEntries() const -> Result<BaseArray<DataDictionary>>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<BaseArray<DataDictionary>>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const DataDescriptionInterface* o_ = (const DataDescriptionInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = DataDescriptionInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.DataDescriptionInterface_GetEntries));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto DataDescriptionInterface::Hxx1::ConstFn<S>::GetEntry(const InternedId& id) const -> Result<DataDictionary>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<DataDictionary>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const DataDescriptionInterface* o_ = (const DataDescriptionInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = DataDescriptionInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.DataDescriptionInterface_GetEntry, id));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto DataDescriptionInterface::Hxx1::ConstFn<S>::FindEntry(const InternedId& id) const -> Result<DataDictionary>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<DataDictionary>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const DataDescriptionInterface* o_ = (const DataDescriptionInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = DataDescriptionInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.DataDescriptionInterface_FindEntry, id));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto DataDescriptionInterface::Hxx1::Fn<S>::SetEntry(const DataDictionary& props, Bool merge) const -> Result<Bool>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<Bool>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); DataDescriptionInterface* o_ = (DataDescriptionInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.DataDescriptionInterface_SetEntry, props, merge));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto DataDescriptionInterface::Hxx1::COWFn<S>::SetEntry(const DataDictionary& props, Bool merge) -> Result<Bool>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<Bool>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); DataDescriptionInterface* o_ = (DataDescriptionInterface*) this->MakeWritable(true).GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.DataDescriptionInterface_SetEntry, props, merge));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto DataDescriptionInterface::Hxx1::Fn<S>::EraseEntry(const InternedId& id) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); DataDescriptionInterface* o_ = (DataDescriptionInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.DataDescriptionInterface_EraseEntry, id));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto DataDescriptionInterface::Hxx1::COWFn<S>::EraseEntry(const InternedId& id) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); DataDescriptionInterface* o_ = (DataDescriptionInterface*) this->MakeWritable(true).GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.DataDescriptionInterface_EraseEntry, id));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto DataDescriptionInterface::Hxx1::Fn<S>::Reset() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); DataDescriptionInterface* o_ = (DataDescriptionInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { DebugStop(); return maxon::PrivateLogNullptrError(); } 
	PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.DataDescriptionInterface_Reset);
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto DataDescriptionInterface::Hxx1::COWFn<S>::Reset() -> typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), void, maxon::Result<void>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), void, maxon::Result<void>>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); DataDescriptionInterface* o_ = (DataDescriptionInterface*) this->MakeWritable(true).GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } 
	PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.DataDescriptionInterface_Reset);
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto DataDescriptionInterface::Hxx1::ConstFn<S>::IsEqual(const DataDescriptionInterface* other, EQUALITY equality) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const DataDescriptionInterface* o_ = (const DataDescriptionInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = DataDescriptionInterface::NullValuePtr(); if (!o_) return maxon::PrivateLogNullptrError(false); } 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.DataDescriptionInterface_IsEqual, other, equality));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto DataDescriptionInterface::Hxx1::ConstFn<S>::Compare(const DataDescriptionInterface* other) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<COMPARERESULT>, COMPARERESULT>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<COMPARERESULT>, COMPARERESULT>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const DataDescriptionInterface* o_ = (const DataDescriptionInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = DataDescriptionInterface::NullValuePtr(); if (!o_) return maxon::PrivateIncompleteNullReturnValue<COMPARERESULT>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.DataDescriptionInterface_Compare, other));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto DataDescriptionInterface::Hxx1::ConstFn<S>::ToString(const FormatStatement* formatStatement) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<String>, String>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<String>, String>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const DataDescriptionInterface* o_ = (const DataDescriptionInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = DataDescriptionInterface::NullValuePtr(); if (!o_) return maxon::PrivateIncompleteNullReturnValue<String>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.DataDescriptionInterface_ToString, formatStatement));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto DataDescriptionInterface::Hxx1::ConstFn<S>::DescribeIO(const DataSerializeInterface& stream) -> Result<void>
{
	return (MTable::_instance.DataDescriptionInterface_DescribeIO(stream));
}
#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT) && !defined(MAXON_DEPENDENCY_DISABLE_datadescription)
#ifdef MAXON_USE_REGISTER_FUNCTION
MAXON_STATIC_STORAGE(maxon::EntityUse, s_ui_maxon_DataDescriptionInterface); \
MAXON_ATTRIBUTE_CONSTRUCTOR static void Register_s_ui_maxon_DataDescriptionInterface() { new (s_ui_maxon_DataDescriptionInterface) maxon::EntityUse(DataDescriptionInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/datadescription.h", false); }
#else // !MAXON_USE_REGISTER_FUNCTION
static maxon::EntityUse s_ui_maxon_DataDescriptionInterface(DataDescriptionInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/datadescription.h", false);
#endif // MAXON_USE_REGISTER_FUNCTION
#endif
#endif

#ifdef MAXON_COMPILER_GCC
	#pragma GCC diagnostic pop
#endif

#endif

