
#ifndef DOXYGEN

#if defined MAXON_COMPILER_GCC
	#pragma GCC diagnostic push
	#if MAXON_COMPILER_GCC >= 600
		#pragma GCC diagnostic ignored "-Wmisleading-indentation"
	#endif
#endif

#if 1

struct DataDescriptionDefinitionInterface::MTable
{
	PRIVATE_MAXON_IMPLEMENTS_CHECK(AddEntry);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(EraseEntry);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(FindEntry);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(GetEntries);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(GetEntry);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(GetEntryCount);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(GetInfo);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(ReplaceEntry);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(Reset);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(SetInfo);
	static const maxon::Char* const _ids;
	static const maxon::METHOD_FLAGS _flags[];
	static const maxon::Bool HAS_NONSTATIC = false;
	PRIVATE_MAXON_MF_POINTER(DataDescriptionDefinitionInterface_GetInfo, GetInfo, true, maxon::GenericComponent, const, (DataDictionary));
	maxon::Int DataDescriptionDefinitionInterface_GetInfo_Offset;
	PRIVATE_MAXON_MF_POINTER(DataDescriptionDefinitionInterface_SetInfo, SetInfo, true, maxon::GenericComponent,, (Result<void>), const DataDictionary& info);
	maxon::Int DataDescriptionDefinitionInterface_SetInfo_Offset;
	PRIVATE_MAXON_MF_POINTER(DataDescriptionDefinitionInterface_GetEntryCount, GetEntryCount, true, maxon::GenericComponent, const, (Int));
	maxon::Int DataDescriptionDefinitionInterface_GetEntryCount_Offset;
	PRIVATE_MAXON_MF_POINTER(DataDescriptionDefinitionInterface_GetEntries, GetEntries, true, maxon::GenericComponent, const, (Result<BaseArray<DataDescriptionEntry>>));
	maxon::Int DataDescriptionDefinitionInterface_GetEntries_Offset;
	PRIVATE_MAXON_MF_POINTER(DataDescriptionDefinitionInterface_GetEntry, GetEntry, true, maxon::GenericComponent, const, (Result<DataDescriptionEntry>), Int idx);
	maxon::Int DataDescriptionDefinitionInterface_GetEntry_Offset;
	PRIVATE_MAXON_MF_POINTER(DataDescriptionDefinitionInterface_FindEntry, FindEntry, true, maxon::GenericComponent, const, (Result<DataDescriptionEntry>), const InternedId& id);
	maxon::Int DataDescriptionDefinitionInterface_FindEntry_Offset;
	PRIVATE_MAXON_MF_POINTER(DataDescriptionDefinitionInterface_AddEntry, AddEntry, true, maxon::GenericComponent,, (Result<Int>), const DataDescriptionEntry& props);
	maxon::Int DataDescriptionDefinitionInterface_AddEntry_Offset;
	PRIVATE_MAXON_MF_POINTER(DataDescriptionDefinitionInterface_ReplaceEntry, ReplaceEntry, true, maxon::GenericComponent,, (Result<void>), const DataDescriptionEntry& props);
	maxon::Int DataDescriptionDefinitionInterface_ReplaceEntry_Offset;
	PRIVATE_MAXON_MF_POINTER(DataDescriptionDefinitionInterface_ReplaceEntry_1, ReplaceEntry, true, maxon::GenericComponent,, (Result<Bool>), Int idx, const DataDescriptionEntry& props);
	maxon::Int DataDescriptionDefinitionInterface_ReplaceEntry_1_Offset;
	PRIVATE_MAXON_MF_POINTER(DataDescriptionDefinitionInterface_EraseEntry, EraseEntry, true, maxon::GenericComponent,, (Result<void>), Int idx);
	maxon::Int DataDescriptionDefinitionInterface_EraseEntry_Offset;
	PRIVATE_MAXON_MF_POINTER(DataDescriptionDefinitionInterface_EraseEntry_1, EraseEntry, true, maxon::GenericComponent,, (Result<void>), const InternedId& id);
	maxon::Int DataDescriptionDefinitionInterface_EraseEntry_1_Offset;
	PRIVATE_MAXON_MF_POINTER(DataDescriptionDefinitionInterface_Reset, Reset, true, maxon::GenericComponent,, (void));
	maxon::Int DataDescriptionDefinitionInterface_Reset_Offset;
	template <typename W> void Init(maxon::Int offset)
	{
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, DataDescriptionDefinitionInterface, GetInfo))
	{
		maxon::Tie(DataDescriptionDefinitionInterface_GetInfo, DataDescriptionDefinitionInterface_GetInfo_Offset) = DataDescriptionDefinitionInterface_GetInfo_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, DataDescriptionDefinitionInterface, SetInfo))
	{
		maxon::Tie(DataDescriptionDefinitionInterface_SetInfo, DataDescriptionDefinitionInterface_SetInfo_Offset) = DataDescriptionDefinitionInterface_SetInfo_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, DataDescriptionDefinitionInterface, GetEntryCount))
	{
		maxon::Tie(DataDescriptionDefinitionInterface_GetEntryCount, DataDescriptionDefinitionInterface_GetEntryCount_Offset) = DataDescriptionDefinitionInterface_GetEntryCount_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, DataDescriptionDefinitionInterface, GetEntries))
	{
		maxon::Tie(DataDescriptionDefinitionInterface_GetEntries, DataDescriptionDefinitionInterface_GetEntries_Offset) = DataDescriptionDefinitionInterface_GetEntries_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, DataDescriptionDefinitionInterface, GetEntry))
	{
		maxon::Tie(DataDescriptionDefinitionInterface_GetEntry, DataDescriptionDefinitionInterface_GetEntry_Offset) = DataDescriptionDefinitionInterface_GetEntry_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, DataDescriptionDefinitionInterface, FindEntry))
	{
		maxon::Tie(DataDescriptionDefinitionInterface_FindEntry, DataDescriptionDefinitionInterface_FindEntry_Offset) = DataDescriptionDefinitionInterface_FindEntry_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, DataDescriptionDefinitionInterface, AddEntry))
	{
		maxon::Tie(DataDescriptionDefinitionInterface_AddEntry, DataDescriptionDefinitionInterface_AddEntry_Offset) = DataDescriptionDefinitionInterface_AddEntry_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, DataDescriptionDefinitionInterface, ReplaceEntry))
	{
		maxon::Tie(DataDescriptionDefinitionInterface_ReplaceEntry, DataDescriptionDefinitionInterface_ReplaceEntry_Offset) = DataDescriptionDefinitionInterface_ReplaceEntry_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, DataDescriptionDefinitionInterface, ReplaceEntry))
	{
		maxon::Tie(DataDescriptionDefinitionInterface_ReplaceEntry_1, DataDescriptionDefinitionInterface_ReplaceEntry_1_Offset) = DataDescriptionDefinitionInterface_ReplaceEntry_1_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, DataDescriptionDefinitionInterface, EraseEntry))
	{
		maxon::Tie(DataDescriptionDefinitionInterface_EraseEntry, DataDescriptionDefinitionInterface_EraseEntry_Offset) = DataDescriptionDefinitionInterface_EraseEntry_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, DataDescriptionDefinitionInterface, EraseEntry))
	{
		maxon::Tie(DataDescriptionDefinitionInterface_EraseEntry_1, DataDescriptionDefinitionInterface_EraseEntry_1_Offset) = DataDescriptionDefinitionInterface_EraseEntry_1_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, DataDescriptionDefinitionInterface, Reset))
	{
		maxon::Tie(DataDescriptionDefinitionInterface_Reset, DataDescriptionDefinitionInterface_Reset_Offset) = DataDescriptionDefinitionInterface_Reset_GetPtr<W>(offset, true);
	}
	}
	template <typename S> using CombinedMTable = maxon::CombinedMTable<DataDescriptionDefinitionInterface, typename ObjectInterface::MTable::template CombinedMTable<S>>;
	template <typename SUPER> using CompBase = maxon::PrivateComponentBase<DataDescriptionDefinitionInterface, SUPER>;
	template <typename I> static const typename I::MTable& GetMTable() { return maxon::GetZeroRef<typename I::MTable>(); }
};

struct DataDescriptionDefinitionInterface::Hxx2
{
	class Unresolved;
	struct StaticMTable
	{
		static StaticMTable _instance;
		static StaticMTable _unresolvedInstance;
		static maxon::Bool InitUnresolved(maxon::NonvirtualInterfaceReference::UnresolvedAssembler assembler, StaticMTable* tbl);
		static const maxon::Char* const _ids;
		static const maxon::NULL_RETURN_TYPE _returnTypes[];
	PRIVATE_MAXON_SF_POINTER(DataDescriptionDefinitionInterface_MergeDescriptionDefinition, MergeDescriptionDefinition, MAXON_EXPAND_VA_ARGS, (Result<void>), DataDescriptionDefinition& target, const DataDescriptionDefinition& source, Bool overwriteIncludes, Bool skipIncludes);
	PRIVATE_MAXON_SF_POINTER(DataDescriptionDefinitionInterface_GetDataDefaults, GetDataDefaults, MAXON_EXPAND_VA_ARGS, (Result<Data>), const DataDictionary& dataEntry);
	PRIVATE_MAXON_SF_POINTER(DataDescriptionDefinitionInterface_GetDataValueOrDefaults, GetDataValueOrDefaults, MAXON_EXPAND_VA_ARGS, (Result<Data>), const InternedId& dataId, const DataDictionary& dataEntry, GETDATAFLAGS flags, const GetDataCallbackType& getDataCallback);
	PRIVATE_MAXON_SF_POINTER(DataDescriptionDefinitionInterface_Create, Create, MAXON_EXPAND_VA_ARGS, (DataDescriptionDefinitionInterface*));
	PRIVATE_MAXON_SF_POINTER(DataDescriptionDefinitionInterface_NullValuePtr, NullValuePtr, MAXON_EXPAND_VA_ARGS, (const DataDescriptionDefinitionInterface*));
		StaticMTable() = default;
		template <typename IMPL> static void Init(StaticMTable* tbl)
		{
		tbl->DataDescriptionDefinitionInterface_MergeDescriptionDefinition = DataDescriptionDefinitionInterface_MergeDescriptionDefinition_GetPtr<IMPL>(true);
		tbl->DataDescriptionDefinitionInterface_GetDataDefaults = DataDescriptionDefinitionInterface_GetDataDefaults_GetPtr<IMPL>(true);
		tbl->DataDescriptionDefinitionInterface_GetDataValueOrDefaults = DataDescriptionDefinitionInterface_GetDataValueOrDefaults_GetPtr<IMPL>(true);
		tbl->DataDescriptionDefinitionInterface_Create = DataDescriptionDefinitionInterface_Create_GetPtr<IMPL>(true);
		tbl->DataDescriptionDefinitionInterface_NullValuePtr = DataDescriptionDefinitionInterface_NullValuePtr_GetPtr<IMPL>(true);
		}
	};
	template <typename S> class CWrapper : public ObjectInterface::Hxx2::template CWrapper<S>
	{
	public:
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(AddEntry);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(EraseEntry);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(FindEntry);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(GetEntries);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(GetEntry);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(GetEntryCount);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(GetInfo);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(ReplaceEntry);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(Reset);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(SetInfo);
		static maxon::Bool InitMTablesWithBases(maxon::ClassInfo* info, maxon::Int offset)
		{
			using Super0 = typename ObjectInterface::Hxx2::template CWrapper<S>;
			if constexpr (!S::Implementation::PROXY)
			{
				if (!(Super0::InitMTablesWithBases(info, offset))) return false;
			}
			auto* vt = (DataDescriptionDefinitionInterface::MTable*) maxon::ObjectInterface::PrivateGetOrCreateMTable(info, DataDescriptionDefinitionInterface::_interface); if (!vt) return false;
			vt->template Init<CWrapper>(offset);
			return true;
		}
		PRIVATE_MAXON_MF_WRAPPER(DataDescriptionDefinitionInterface_GetInfo, maxon::GenericComponent, const, (DataDictionary)) { return ((const typename S::Implementation*) PRIVATE_MAXON_MF_THIS(const maxon::GenericComponent))->GetInfo(); }
		PRIVATE_MAXON_MF_WRAPPER(DataDescriptionDefinitionInterface_SetInfo, maxon::GenericComponent,, (Result<void>), const DataDictionary& info) { return ((typename S::Implementation*) PRIVATE_MAXON_MF_THIS(maxon::GenericComponent))->SetInfo(info); }
		PRIVATE_MAXON_MF_WRAPPER(DataDescriptionDefinitionInterface_GetEntryCount, maxon::GenericComponent, const, (Int)) { return ((const typename S::Implementation*) PRIVATE_MAXON_MF_THIS(const maxon::GenericComponent))->GetEntryCount(); }
		PRIVATE_MAXON_MF_WRAPPER(DataDescriptionDefinitionInterface_GetEntries, maxon::GenericComponent, const, (Result<BaseArray<DataDescriptionEntry>>)) { return ((const typename S::Implementation*) PRIVATE_MAXON_MF_THIS(const maxon::GenericComponent))->GetEntries(); }
		PRIVATE_MAXON_MF_WRAPPER(DataDescriptionDefinitionInterface_GetEntry, maxon::GenericComponent, const, (Result<DataDescriptionEntry>), Int idx) { return ((const typename S::Implementation*) PRIVATE_MAXON_MF_THIS(const maxon::GenericComponent))->GetEntry(idx); }
		PRIVATE_MAXON_MF_WRAPPER(DataDescriptionDefinitionInterface_FindEntry, maxon::GenericComponent, const, (Result<DataDescriptionEntry>), const InternedId& id) { return ((const typename S::Implementation*) PRIVATE_MAXON_MF_THIS(const maxon::GenericComponent))->FindEntry(id); }
		PRIVATE_MAXON_MF_WRAPPER(DataDescriptionDefinitionInterface_AddEntry, maxon::GenericComponent,, (Result<Int>), const DataDescriptionEntry& props) { return ((typename S::Implementation*) PRIVATE_MAXON_MF_THIS(maxon::GenericComponent))->AddEntry(props); }
		PRIVATE_MAXON_MF_WRAPPER(DataDescriptionDefinitionInterface_ReplaceEntry, maxon::GenericComponent,, (Result<void>), const DataDescriptionEntry& props) { return ((typename S::Implementation*) PRIVATE_MAXON_MF_THIS(maxon::GenericComponent))->ReplaceEntry(props); }
		PRIVATE_MAXON_MF_WRAPPER(DataDescriptionDefinitionInterface_ReplaceEntry_1, maxon::GenericComponent,, (Result<Bool>), Int idx, const DataDescriptionEntry& props) { return ((typename S::Implementation*) PRIVATE_MAXON_MF_THIS(maxon::GenericComponent))->ReplaceEntry(idx, props); }
		PRIVATE_MAXON_MF_WRAPPER(DataDescriptionDefinitionInterface_EraseEntry, maxon::GenericComponent,, (Result<void>), Int idx) { return ((typename S::Implementation*) PRIVATE_MAXON_MF_THIS(maxon::GenericComponent))->EraseEntry(idx); }
		PRIVATE_MAXON_MF_WRAPPER(DataDescriptionDefinitionInterface_EraseEntry_1, maxon::GenericComponent,, (Result<void>), const InternedId& id) { return ((typename S::Implementation*) PRIVATE_MAXON_MF_THIS(maxon::GenericComponent))->EraseEntry(id); }
		PRIVATE_MAXON_MF_WRAPPER(DataDescriptionDefinitionInterface_Reset, maxon::GenericComponent,, (void)) { return ((typename S::Implementation*) PRIVATE_MAXON_MF_THIS(maxon::GenericComponent))->Reset(); }
		static Result<void> DataDescriptionDefinitionInterface_MergeDescriptionDefinition(DataDescriptionDefinition& target, const DataDescriptionDefinition& source, Bool overwriteIncludes, Bool skipIncludes) { return S::Implementation::MergeDescriptionDefinition(target, source, overwriteIncludes, skipIncludes); }
		static Result<Data> DataDescriptionDefinitionInterface_GetDataDefaults(const DataDictionary& dataEntry) { return S::Implementation::GetDataDefaults(dataEntry); }
		static Result<Data> DataDescriptionDefinitionInterface_GetDataValueOrDefaults(const InternedId& dataId, const DataDictionary& dataEntry, GETDATAFLAGS flags, const GetDataCallbackType& getDataCallback) { return S::Implementation::GetDataValueOrDefaults(dataId, dataEntry, flags, getDataCallback); }
		static DataDescriptionDefinitionInterface* DataDescriptionDefinitionInterface_Create() { return S::Implementation::Create(); }
		static const DataDescriptionDefinitionInterface* DataDescriptionDefinitionInterface_NullValuePtr() { return S::Implementation::NullValuePtr(); }
	};

};
MAXON_ATTRIBUTE_FORCE_INLINE auto DataDescriptionDefinitionInterface::GetInfo() const -> DataDictionary
{
	const DataDescriptionDefinitionInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(DataDescriptionDefinitionInterface, this); return PRIVATE_MAXON_MF_INVOKE(((const maxon::GenericComponent*) this + mt_.DataDescriptionDefinitionInterface_GetInfo_Offset), mt_.DataDescriptionDefinitionInterface_GetInfo);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto DataDescriptionDefinitionInterface::SetInfo(const DataDictionary& info) -> Result<void>
{
	const DataDescriptionDefinitionInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(DataDescriptionDefinitionInterface, this); return PRIVATE_MAXON_MF_INVOKE(((maxon::GenericComponent*) this + mt_.DataDescriptionDefinitionInterface_SetInfo_Offset), mt_.DataDescriptionDefinitionInterface_SetInfo, info);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto DataDescriptionDefinitionInterface::GetEntryCount() const -> Int
{
	const DataDescriptionDefinitionInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(DataDescriptionDefinitionInterface, this); return PRIVATE_MAXON_MF_INVOKE(((const maxon::GenericComponent*) this + mt_.DataDescriptionDefinitionInterface_GetEntryCount_Offset), mt_.DataDescriptionDefinitionInterface_GetEntryCount);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto DataDescriptionDefinitionInterface::GetEntries() const -> Result<BaseArray<DataDescriptionEntry>>
{
	const DataDescriptionDefinitionInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(DataDescriptionDefinitionInterface, this); return PRIVATE_MAXON_MF_INVOKE(((const maxon::GenericComponent*) this + mt_.DataDescriptionDefinitionInterface_GetEntries_Offset), mt_.DataDescriptionDefinitionInterface_GetEntries);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto DataDescriptionDefinitionInterface::GetEntry(Int idx) const -> Result<DataDescriptionEntry>
{
	const DataDescriptionDefinitionInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(DataDescriptionDefinitionInterface, this); return PRIVATE_MAXON_MF_INVOKE(((const maxon::GenericComponent*) this + mt_.DataDescriptionDefinitionInterface_GetEntry_Offset), mt_.DataDescriptionDefinitionInterface_GetEntry, idx);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto DataDescriptionDefinitionInterface::FindEntry(const InternedId& id) const -> Result<DataDescriptionEntry>
{
	const DataDescriptionDefinitionInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(DataDescriptionDefinitionInterface, this); return PRIVATE_MAXON_MF_INVOKE(((const maxon::GenericComponent*) this + mt_.DataDescriptionDefinitionInterface_FindEntry_Offset), mt_.DataDescriptionDefinitionInterface_FindEntry, id);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto DataDescriptionDefinitionInterface::AddEntry(const DataDescriptionEntry& props) -> Result<Int>
{
	const DataDescriptionDefinitionInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(DataDescriptionDefinitionInterface, this); return PRIVATE_MAXON_MF_INVOKE(((maxon::GenericComponent*) this + mt_.DataDescriptionDefinitionInterface_AddEntry_Offset), mt_.DataDescriptionDefinitionInterface_AddEntry, props);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto DataDescriptionDefinitionInterface::ReplaceEntry(const DataDescriptionEntry& props) -> Result<void>
{
	const DataDescriptionDefinitionInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(DataDescriptionDefinitionInterface, this); return PRIVATE_MAXON_MF_INVOKE(((maxon::GenericComponent*) this + mt_.DataDescriptionDefinitionInterface_ReplaceEntry_Offset), mt_.DataDescriptionDefinitionInterface_ReplaceEntry, props);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto DataDescriptionDefinitionInterface::ReplaceEntry(Int idx, const DataDescriptionEntry& props) -> Result<Bool>
{
	const DataDescriptionDefinitionInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(DataDescriptionDefinitionInterface, this); return PRIVATE_MAXON_MF_INVOKE(((maxon::GenericComponent*) this + mt_.DataDescriptionDefinitionInterface_ReplaceEntry_1_Offset), mt_.DataDescriptionDefinitionInterface_ReplaceEntry_1, idx, props);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto DataDescriptionDefinitionInterface::EraseEntry(Int idx) -> Result<void>
{
	const DataDescriptionDefinitionInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(DataDescriptionDefinitionInterface, this); return PRIVATE_MAXON_MF_INVOKE(((maxon::GenericComponent*) this + mt_.DataDescriptionDefinitionInterface_EraseEntry_Offset), mt_.DataDescriptionDefinitionInterface_EraseEntry, idx);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto DataDescriptionDefinitionInterface::EraseEntry(const InternedId& id) -> Result<void>
{
	const DataDescriptionDefinitionInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(DataDescriptionDefinitionInterface, this); return PRIVATE_MAXON_MF_INVOKE(((maxon::GenericComponent*) this + mt_.DataDescriptionDefinitionInterface_EraseEntry_1_Offset), mt_.DataDescriptionDefinitionInterface_EraseEntry_1, id);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto DataDescriptionDefinitionInterface::Reset() -> void
{
	const DataDescriptionDefinitionInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(DataDescriptionDefinitionInterface, this); return PRIVATE_MAXON_MF_INVOKE(((maxon::GenericComponent*) this + mt_.DataDescriptionDefinitionInterface_Reset_Offset), mt_.DataDescriptionDefinitionInterface_Reset);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto DataDescriptionDefinitionInterface::MergeDescriptionDefinition(DataDescriptionDefinition& target, const DataDescriptionDefinition& source, Bool overwriteIncludes, Bool skipIncludes) -> Result<void>
{
	return Hxx2::StaticMTable::_instance.DataDescriptionDefinitionInterface_MergeDescriptionDefinition(target, source, overwriteIncludes, skipIncludes);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto DataDescriptionDefinitionInterface::GetDataDefaults(const DataDictionary& dataEntry) -> Result<Data>
{
	return Hxx2::StaticMTable::_instance.DataDescriptionDefinitionInterface_GetDataDefaults(dataEntry);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto DataDescriptionDefinitionInterface::GetDataValueOrDefaults(const InternedId& dataId, const DataDictionary& dataEntry, GETDATAFLAGS flags, const GetDataCallbackType& getDataCallback) -> Result<Data>
{
	return Hxx2::StaticMTable::_instance.DataDescriptionDefinitionInterface_GetDataValueOrDefaults(dataId, dataEntry, flags, getDataCallback);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto DataDescriptionDefinitionInterface::Create() -> DataDescriptionDefinitionInterface*
{
	return Hxx2::StaticMTable::_instance.DataDescriptionDefinitionInterface_Create();
}
MAXON_ATTRIBUTE_FORCE_INLINE auto DataDescriptionDefinitionInterface::NullValuePtr() -> const DataDescriptionDefinitionInterface*
{
	return Hxx2::StaticMTable::_instance.DataDescriptionDefinitionInterface_NullValuePtr();
}

template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto DataDescriptionDefinitionInterface::Hxx1::ConstFn<S>::GetInfo() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<DataDictionary>, DataDictionary>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<DataDictionary>, DataDictionary>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const DataDescriptionDefinitionInterface* o_ = (const DataDescriptionDefinitionInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = DataDescriptionDefinitionInterface::NullValuePtr(); if (!o_) return maxon::PrivateIncompleteNullReturnValue<DataDictionary>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(DataDescriptionDefinitionInterface, o_, DataDescriptionDefinitionInterface_GetInfo) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<DataDescriptionDefinitionInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<DataDescriptionDefinitionInterface>() : PRIVATE_MAXON_VTABLE(DataDescriptionDefinitionInterface, o_); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.DataDescriptionDefinitionInterface_GetInfo_Offset), mt_.DataDescriptionDefinitionInterface_GetInfo));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto DataDescriptionDefinitionInterface::Hxx1::Fn<S>::SetInfo(const DataDictionary& info) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); DataDescriptionDefinitionInterface* o_ = (DataDescriptionDefinitionInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(DataDescriptionDefinitionInterface, o_, DataDescriptionDefinitionInterface_SetInfo) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<DataDescriptionDefinitionInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<DataDescriptionDefinitionInterface>() : PRIVATE_MAXON_VTABLE(DataDescriptionDefinitionInterface, o_); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.DataDescriptionDefinitionInterface_SetInfo_Offset), mt_.DataDescriptionDefinitionInterface_SetInfo, info));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto DataDescriptionDefinitionInterface::Hxx1::COWFn<S>::SetInfo(const DataDictionary& info) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); DataDescriptionDefinitionInterface* o_ = (DataDescriptionDefinitionInterface*) this->MakeWritable(true).GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(DataDescriptionDefinitionInterface, o_, DataDescriptionDefinitionInterface_SetInfo) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<DataDescriptionDefinitionInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<DataDescriptionDefinitionInterface>() : PRIVATE_MAXON_VTABLE(DataDescriptionDefinitionInterface, o_); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.DataDescriptionDefinitionInterface_SetInfo_Offset), mt_.DataDescriptionDefinitionInterface_SetInfo, info));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto DataDescriptionDefinitionInterface::Hxx1::ConstFn<S>::GetEntryCount() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const DataDescriptionDefinitionInterface* o_ = (const DataDescriptionDefinitionInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = DataDescriptionDefinitionInterface::NullValuePtr(); if (!o_) return 0; } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(DataDescriptionDefinitionInterface, o_, DataDescriptionDefinitionInterface_GetEntryCount) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<DataDescriptionDefinitionInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<DataDescriptionDefinitionInterface>() : PRIVATE_MAXON_VTABLE(DataDescriptionDefinitionInterface, o_); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.DataDescriptionDefinitionInterface_GetEntryCount_Offset), mt_.DataDescriptionDefinitionInterface_GetEntryCount));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto DataDescriptionDefinitionInterface::Hxx1::ConstFn<S>::GetEntries() const -> Result<BaseArray<DataDescriptionEntry>>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<BaseArray<DataDescriptionEntry>>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const DataDescriptionDefinitionInterface* o_ = (const DataDescriptionDefinitionInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = DataDescriptionDefinitionInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(DataDescriptionDefinitionInterface, o_, DataDescriptionDefinitionInterface_GetEntries) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<DataDescriptionDefinitionInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<DataDescriptionDefinitionInterface>() : PRIVATE_MAXON_VTABLE(DataDescriptionDefinitionInterface, o_); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.DataDescriptionDefinitionInterface_GetEntries_Offset), mt_.DataDescriptionDefinitionInterface_GetEntries));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto DataDescriptionDefinitionInterface::Hxx1::ConstFn<S>::GetEntry(Int idx) const -> Result<DataDescriptionEntry>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<DataDescriptionEntry>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const DataDescriptionDefinitionInterface* o_ = (const DataDescriptionDefinitionInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = DataDescriptionDefinitionInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(DataDescriptionDefinitionInterface, o_, DataDescriptionDefinitionInterface_GetEntry) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<DataDescriptionDefinitionInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<DataDescriptionDefinitionInterface>() : PRIVATE_MAXON_VTABLE(DataDescriptionDefinitionInterface, o_); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.DataDescriptionDefinitionInterface_GetEntry_Offset), mt_.DataDescriptionDefinitionInterface_GetEntry, idx));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto DataDescriptionDefinitionInterface::Hxx1::ConstFn<S>::FindEntry(const InternedId& id) const -> Result<DataDescriptionEntry>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<DataDescriptionEntry>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const DataDescriptionDefinitionInterface* o_ = (const DataDescriptionDefinitionInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = DataDescriptionDefinitionInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(DataDescriptionDefinitionInterface, o_, DataDescriptionDefinitionInterface_FindEntry) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<DataDescriptionDefinitionInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<DataDescriptionDefinitionInterface>() : PRIVATE_MAXON_VTABLE(DataDescriptionDefinitionInterface, o_); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.DataDescriptionDefinitionInterface_FindEntry_Offset), mt_.DataDescriptionDefinitionInterface_FindEntry, id));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto DataDescriptionDefinitionInterface::Hxx1::Fn<S>::AddEntry(const DataDescriptionEntry& props) const -> Result<Int>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<Int>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); DataDescriptionDefinitionInterface* o_ = (DataDescriptionDefinitionInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(DataDescriptionDefinitionInterface, o_, DataDescriptionDefinitionInterface_AddEntry) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<DataDescriptionDefinitionInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<DataDescriptionDefinitionInterface>() : PRIVATE_MAXON_VTABLE(DataDescriptionDefinitionInterface, o_); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.DataDescriptionDefinitionInterface_AddEntry_Offset), mt_.DataDescriptionDefinitionInterface_AddEntry, props));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto DataDescriptionDefinitionInterface::Hxx1::COWFn<S>::AddEntry(const DataDescriptionEntry& props) -> Result<Int>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<Int>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); DataDescriptionDefinitionInterface* o_ = (DataDescriptionDefinitionInterface*) this->MakeWritable(true).GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(DataDescriptionDefinitionInterface, o_, DataDescriptionDefinitionInterface_AddEntry) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<DataDescriptionDefinitionInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<DataDescriptionDefinitionInterface>() : PRIVATE_MAXON_VTABLE(DataDescriptionDefinitionInterface, o_); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.DataDescriptionDefinitionInterface_AddEntry_Offset), mt_.DataDescriptionDefinitionInterface_AddEntry, props));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto DataDescriptionDefinitionInterface::Hxx1::Fn<S>::ReplaceEntry(const DataDescriptionEntry& props) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); DataDescriptionDefinitionInterface* o_ = (DataDescriptionDefinitionInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(DataDescriptionDefinitionInterface, o_, DataDescriptionDefinitionInterface_ReplaceEntry) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<DataDescriptionDefinitionInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<DataDescriptionDefinitionInterface>() : PRIVATE_MAXON_VTABLE(DataDescriptionDefinitionInterface, o_); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.DataDescriptionDefinitionInterface_ReplaceEntry_Offset), mt_.DataDescriptionDefinitionInterface_ReplaceEntry, props));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto DataDescriptionDefinitionInterface::Hxx1::COWFn<S>::ReplaceEntry(const DataDescriptionEntry& props) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); DataDescriptionDefinitionInterface* o_ = (DataDescriptionDefinitionInterface*) this->MakeWritable(true).GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(DataDescriptionDefinitionInterface, o_, DataDescriptionDefinitionInterface_ReplaceEntry) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<DataDescriptionDefinitionInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<DataDescriptionDefinitionInterface>() : PRIVATE_MAXON_VTABLE(DataDescriptionDefinitionInterface, o_); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.DataDescriptionDefinitionInterface_ReplaceEntry_Offset), mt_.DataDescriptionDefinitionInterface_ReplaceEntry, props));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto DataDescriptionDefinitionInterface::Hxx1::Fn<S>::ReplaceEntry(Int idx, const DataDescriptionEntry& props) const -> Result<Bool>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<Bool>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); DataDescriptionDefinitionInterface* o_ = (DataDescriptionDefinitionInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(DataDescriptionDefinitionInterface, o_, DataDescriptionDefinitionInterface_ReplaceEntry_1) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<DataDescriptionDefinitionInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<DataDescriptionDefinitionInterface>() : PRIVATE_MAXON_VTABLE(DataDescriptionDefinitionInterface, o_); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.DataDescriptionDefinitionInterface_ReplaceEntry_1_Offset), mt_.DataDescriptionDefinitionInterface_ReplaceEntry_1, idx, props));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto DataDescriptionDefinitionInterface::Hxx1::COWFn<S>::ReplaceEntry(Int idx, const DataDescriptionEntry& props) -> Result<Bool>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<Bool>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); DataDescriptionDefinitionInterface* o_ = (DataDescriptionDefinitionInterface*) this->MakeWritable(true).GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(DataDescriptionDefinitionInterface, o_, DataDescriptionDefinitionInterface_ReplaceEntry_1) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<DataDescriptionDefinitionInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<DataDescriptionDefinitionInterface>() : PRIVATE_MAXON_VTABLE(DataDescriptionDefinitionInterface, o_); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.DataDescriptionDefinitionInterface_ReplaceEntry_1_Offset), mt_.DataDescriptionDefinitionInterface_ReplaceEntry_1, idx, props));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto DataDescriptionDefinitionInterface::Hxx1::Fn<S>::EraseEntry(Int idx) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); DataDescriptionDefinitionInterface* o_ = (DataDescriptionDefinitionInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(DataDescriptionDefinitionInterface, o_, DataDescriptionDefinitionInterface_EraseEntry) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<DataDescriptionDefinitionInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<DataDescriptionDefinitionInterface>() : PRIVATE_MAXON_VTABLE(DataDescriptionDefinitionInterface, o_); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.DataDescriptionDefinitionInterface_EraseEntry_Offset), mt_.DataDescriptionDefinitionInterface_EraseEntry, idx));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto DataDescriptionDefinitionInterface::Hxx1::COWFn<S>::EraseEntry(Int idx) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); DataDescriptionDefinitionInterface* o_ = (DataDescriptionDefinitionInterface*) this->MakeWritable(true).GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(DataDescriptionDefinitionInterface, o_, DataDescriptionDefinitionInterface_EraseEntry) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<DataDescriptionDefinitionInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<DataDescriptionDefinitionInterface>() : PRIVATE_MAXON_VTABLE(DataDescriptionDefinitionInterface, o_); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.DataDescriptionDefinitionInterface_EraseEntry_Offset), mt_.DataDescriptionDefinitionInterface_EraseEntry, idx));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto DataDescriptionDefinitionInterface::Hxx1::Fn<S>::EraseEntry(const InternedId& id) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); DataDescriptionDefinitionInterface* o_ = (DataDescriptionDefinitionInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(DataDescriptionDefinitionInterface, o_, DataDescriptionDefinitionInterface_EraseEntry_1) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<DataDescriptionDefinitionInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<DataDescriptionDefinitionInterface>() : PRIVATE_MAXON_VTABLE(DataDescriptionDefinitionInterface, o_); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.DataDescriptionDefinitionInterface_EraseEntry_1_Offset), mt_.DataDescriptionDefinitionInterface_EraseEntry_1, id));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto DataDescriptionDefinitionInterface::Hxx1::COWFn<S>::EraseEntry(const InternedId& id) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); DataDescriptionDefinitionInterface* o_ = (DataDescriptionDefinitionInterface*) this->MakeWritable(true).GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(DataDescriptionDefinitionInterface, o_, DataDescriptionDefinitionInterface_EraseEntry_1) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<DataDescriptionDefinitionInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<DataDescriptionDefinitionInterface>() : PRIVATE_MAXON_VTABLE(DataDescriptionDefinitionInterface, o_); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.DataDescriptionDefinitionInterface_EraseEntry_1_Offset), mt_.DataDescriptionDefinitionInterface_EraseEntry_1, id));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto DataDescriptionDefinitionInterface::Hxx1::Fn<S>::Reset() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); DataDescriptionDefinitionInterface* o_ = (DataDescriptionDefinitionInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { DebugStop(); return maxon::PrivateLogNullptrError(); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(DataDescriptionDefinitionInterface, o_, DataDescriptionDefinitionInterface_Reset) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<DataDescriptionDefinitionInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<DataDescriptionDefinitionInterface>() : PRIVATE_MAXON_VTABLE(DataDescriptionDefinitionInterface, o_); 
	PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.DataDescriptionDefinitionInterface_Reset_Offset), mt_.DataDescriptionDefinitionInterface_Reset);
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto DataDescriptionDefinitionInterface::Hxx1::COWFn<S>::Reset() -> typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), void, maxon::Result<void>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), void, maxon::Result<void>>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); DataDescriptionDefinitionInterface* o_ = (DataDescriptionDefinitionInterface*) this->MakeWritable(true).GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(DataDescriptionDefinitionInterface, o_, DataDescriptionDefinitionInterface_Reset) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<DataDescriptionDefinitionInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<DataDescriptionDefinitionInterface>() : PRIVATE_MAXON_VTABLE(DataDescriptionDefinitionInterface, o_); 
	PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.DataDescriptionDefinitionInterface_Reset_Offset), mt_.DataDescriptionDefinitionInterface_Reset);
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto DataDescriptionDefinitionInterface::Hxx1::ConstFn<S>::MergeDescriptionDefinition(DataDescriptionDefinition& target, const DataDescriptionDefinition& source, Bool overwriteIncludes, Bool skipIncludes) -> Result<void>
{
	return (Hxx2::StaticMTable::_instance.DataDescriptionDefinitionInterface_MergeDescriptionDefinition(target, source, overwriteIncludes, skipIncludes));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto DataDescriptionDefinitionInterface::Hxx1::ConstFn<S>::GetDataDefaults(const DataDictionary& dataEntry) -> Result<Data>
{
	return (Hxx2::StaticMTable::_instance.DataDescriptionDefinitionInterface_GetDataDefaults(dataEntry));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto DataDescriptionDefinitionInterface::Hxx1::ConstFn<S>::GetDataValueOrDefaults(const InternedId& dataId, const DataDictionary& dataEntry, GETDATAFLAGS flags, const GetDataCallbackType& getDataCallback) -> Result<Data>
{
	return (Hxx2::StaticMTable::_instance.DataDescriptionDefinitionInterface_GetDataValueOrDefaults(dataId, dataEntry, flags, getDataCallback));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto DataDescriptionDefinitionInterface::Hxx1::ConstFn<S>::Create() -> DataDescriptionDefinition
{
	return DataDescriptionDefinition(Hxx2::StaticMTable::_instance.DataDescriptionDefinitionInterface_Create());
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto DataDescriptionDefinitionInterface::Hxx1::ConstFn<S>::NullValuePtr() -> const DataDescriptionDefinitionInterface*
{
	return (Hxx2::StaticMTable::_instance.DataDescriptionDefinitionInterface_NullValuePtr());
}
auto DataDescriptionDefinitionInterface::GetPtr() -> Ptr { return Ptr(this); }
auto DataDescriptionDefinitionInterface::GetPtr() const -> ConstPtr { return ConstPtr(this); }
#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT) && !defined(MAXON_DEPENDENCY_DISABLE_datadescriptiondefinition)
#ifdef MAXON_USE_REGISTER_FUNCTION
MAXON_STATIC_STORAGE(maxon::EntityUse, s_ui_maxon_DataDescriptionDefinitionInterface); \
MAXON_ATTRIBUTE_CONSTRUCTOR static void Register_s_ui_maxon_DataDescriptionDefinitionInterface() { new (s_ui_maxon_DataDescriptionDefinitionInterface) maxon::EntityUse(DataDescriptionDefinitionInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/datadescriptiondefinition.h", false); }
#else // !MAXON_USE_REGISTER_FUNCTION
static maxon::EntityUse s_ui_maxon_DataDescriptionDefinitionInterface(DataDescriptionDefinitionInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/datadescriptiondefinition.h", false);
#endif // MAXON_USE_REGISTER_FUNCTION
#endif
#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT) && !defined(MAXON_DEPENDENCY_DISABLE_datadescriptiondefinition)
#ifdef MAXON_USE_REGISTER_FUNCTION
MAXON_STATIC_STORAGE(maxon::EntityUse, s_usi_maxon_DataDescriptionDefinitionInterface); \
MAXON_ATTRIBUTE_CONSTRUCTOR static void Register_s_usi_maxon_DataDescriptionDefinitionInterface() { new (s_usi_maxon_DataDescriptionDefinitionInterface) maxon::EntityUse(DataDescriptionDefinitionInterface::_staticInterface.GetReference(), &maxon::g_translationUnit, "maxon/datadescriptiondefinition.h", false); }
#else // !MAXON_USE_REGISTER_FUNCTION
static maxon::EntityUse s_usi_maxon_DataDescriptionDefinitionInterface(DataDescriptionDefinitionInterface::_staticInterface.GetReference(), &maxon::g_translationUnit, "maxon/datadescriptiondefinition.h", false);
#endif // MAXON_USE_REGISTER_FUNCTION
#endif
#endif

#ifdef MAXON_COMPILER_GCC
	#pragma GCC diagnostic pop
#endif

#endif

