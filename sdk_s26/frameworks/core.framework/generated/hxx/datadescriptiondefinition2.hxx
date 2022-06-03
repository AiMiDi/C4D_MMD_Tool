
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
	DataDictionary (*DataDescriptionDefinitionInterface_GetInfo) (const maxon::GenericComponent* this_);
	maxon::Int DataDescriptionDefinitionInterface_GetInfo_Offset;
	Result<void> (*DataDescriptionDefinitionInterface_SetInfo) (maxon::GenericComponent* this_, const DataDictionary& info);
	maxon::Int DataDescriptionDefinitionInterface_SetInfo_Offset;
	Int (*DataDescriptionDefinitionInterface_GetEntryCount) (const maxon::GenericComponent* this_);
	maxon::Int DataDescriptionDefinitionInterface_GetEntryCount_Offset;
	Result<BaseArray<DataDescriptionEntry>> (*DataDescriptionDefinitionInterface_GetEntries) (const maxon::GenericComponent* this_);
	maxon::Int DataDescriptionDefinitionInterface_GetEntries_Offset;
	Result<DataDescriptionEntry> (*DataDescriptionDefinitionInterface_GetEntry) (const maxon::GenericComponent* this_, Int idx);
	maxon::Int DataDescriptionDefinitionInterface_GetEntry_Offset;
	Result<DataDescriptionEntry> (*DataDescriptionDefinitionInterface_FindEntry) (const maxon::GenericComponent* this_, const InternedId& id);
	maxon::Int DataDescriptionDefinitionInterface_FindEntry_Offset;
	Result<Int> (*DataDescriptionDefinitionInterface_AddEntry) (maxon::GenericComponent* this_, const DataDescriptionEntry& props);
	maxon::Int DataDescriptionDefinitionInterface_AddEntry_Offset;
	Result<void> (*DataDescriptionDefinitionInterface_ReplaceEntry) (maxon::GenericComponent* this_, const DataDescriptionEntry& props);
	maxon::Int DataDescriptionDefinitionInterface_ReplaceEntry_Offset;
	Result<Bool> (*DataDescriptionDefinitionInterface_ReplaceEntry_1) (maxon::GenericComponent* this_, Int idx, const DataDescriptionEntry& props);
	maxon::Int DataDescriptionDefinitionInterface_ReplaceEntry_1_Offset;
	Result<void> (*DataDescriptionDefinitionInterface_EraseEntry) (maxon::GenericComponent* this_, Int idx);
	maxon::Int DataDescriptionDefinitionInterface_EraseEntry_Offset;
	void (*DataDescriptionDefinitionInterface_Reset) (maxon::GenericComponent* this_);
	maxon::Int DataDescriptionDefinitionInterface_Reset_Offset;
	template <typename W> void Init(maxon::Int offset)
	{
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, DataDescriptionDefinitionInterface, GetInfo))
	{
		DataDescriptionDefinitionInterface_GetInfo = &W::DataDescriptionDefinitionInterface_GetInfo;
		DataDescriptionDefinitionInterface_GetInfo_Offset = offset;
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, DataDescriptionDefinitionInterface, SetInfo))
	{
		DataDescriptionDefinitionInterface_SetInfo = &W::DataDescriptionDefinitionInterface_SetInfo;
		DataDescriptionDefinitionInterface_SetInfo_Offset = offset;
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, DataDescriptionDefinitionInterface, GetEntryCount))
	{
		DataDescriptionDefinitionInterface_GetEntryCount = &W::DataDescriptionDefinitionInterface_GetEntryCount;
		DataDescriptionDefinitionInterface_GetEntryCount_Offset = offset;
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, DataDescriptionDefinitionInterface, GetEntries))
	{
		DataDescriptionDefinitionInterface_GetEntries = &W::DataDescriptionDefinitionInterface_GetEntries;
		DataDescriptionDefinitionInterface_GetEntries_Offset = offset;
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, DataDescriptionDefinitionInterface, GetEntry))
	{
		DataDescriptionDefinitionInterface_GetEntry = &W::DataDescriptionDefinitionInterface_GetEntry;
		DataDescriptionDefinitionInterface_GetEntry_Offset = offset;
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, DataDescriptionDefinitionInterface, FindEntry))
	{
		DataDescriptionDefinitionInterface_FindEntry = &W::DataDescriptionDefinitionInterface_FindEntry;
		DataDescriptionDefinitionInterface_FindEntry_Offset = offset;
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, DataDescriptionDefinitionInterface, AddEntry))
	{
		DataDescriptionDefinitionInterface_AddEntry = &W::DataDescriptionDefinitionInterface_AddEntry;
		DataDescriptionDefinitionInterface_AddEntry_Offset = offset;
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, DataDescriptionDefinitionInterface, ReplaceEntry))
	{
		DataDescriptionDefinitionInterface_ReplaceEntry = &W::DataDescriptionDefinitionInterface_ReplaceEntry;
		DataDescriptionDefinitionInterface_ReplaceEntry_Offset = offset;
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, DataDescriptionDefinitionInterface, ReplaceEntry))
	{
		DataDescriptionDefinitionInterface_ReplaceEntry_1 = &W::DataDescriptionDefinitionInterface_ReplaceEntry_1;
		DataDescriptionDefinitionInterface_ReplaceEntry_1_Offset = offset;
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, DataDescriptionDefinitionInterface, EraseEntry))
	{
		DataDescriptionDefinitionInterface_EraseEntry = &W::DataDescriptionDefinitionInterface_EraseEntry;
		DataDescriptionDefinitionInterface_EraseEntry_Offset = offset;
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, DataDescriptionDefinitionInterface, Reset))
	{
		DataDescriptionDefinitionInterface_Reset = &W::DataDescriptionDefinitionInterface_Reset;
		DataDescriptionDefinitionInterface_Reset_Offset = offset;
	}
	}
	template <typename S> using CombinedMTable = maxon::CombinedMTable<DataDescriptionDefinitionInterface, typename ObserverObjectInterface::MTable::template CombinedMTable<S>>;
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
	Result<void> (*DataDescriptionDefinitionInterface_MergeDescriptionDefinition) (DataDescriptionDefinition& target, const DataDescriptionDefinition& source, Bool overwriteIncludes, Bool skipIncludes);
	Result<Data> (*DataDescriptionDefinitionInterface_GetDataDefaults) (const DataDictionary& dataEntry);
	Result<Data> (*DataDescriptionDefinitionInterface_GetDataValueOrDefaults) (const InternedId& dataId, const DataDictionary& dataEntry, GETDATAFLAGS flags, const GetDataCallbackType& getDataCallback);
	DataDescriptionDefinitionInterface* (*DataDescriptionDefinitionInterface_Create) ();
	const DataDescriptionDefinitionInterface* (*DataDescriptionDefinitionInterface_NullValuePtr) ();
		StaticMTable() = default;
		template <typename IMPL> static void Init(StaticMTable* tbl)
		{
		tbl->DataDescriptionDefinitionInterface_MergeDescriptionDefinition = &IMPL::DataDescriptionDefinitionInterface_MergeDescriptionDefinition;
		tbl->DataDescriptionDefinitionInterface_GetDataDefaults = &IMPL::DataDescriptionDefinitionInterface_GetDataDefaults;
		tbl->DataDescriptionDefinitionInterface_GetDataValueOrDefaults = &IMPL::DataDescriptionDefinitionInterface_GetDataValueOrDefaults;
		tbl->DataDescriptionDefinitionInterface_Create = &IMPL::DataDescriptionDefinitionInterface_Create;
		tbl->DataDescriptionDefinitionInterface_NullValuePtr = &IMPL::DataDescriptionDefinitionInterface_NullValuePtr;
		}
	};
	template <typename S> class CWrapper : public ObserverObjectInterface::Hxx2::template CWrapper<S>
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
			using Super0 = typename ObserverObjectInterface::Hxx2::template CWrapper<S>;
			if (!S::Implementation::PROXY && !(Super0::InitMTablesWithBases(info, offset))) return false;
			auto* vt = (DataDescriptionDefinitionInterface::MTable*) maxon::ObjectInterface::PrivateGetOrCreateMTable(info, DataDescriptionDefinitionInterface::_interface); if (!vt) return false;
			vt->template Init<CWrapper>(offset);
			return true;
		}
		static DataDictionary DataDescriptionDefinitionInterface_GetInfo(const maxon::GenericComponent* this_) { return ((const typename S::Implementation*) this_)->GetInfo(); }
		static Result<void> DataDescriptionDefinitionInterface_SetInfo(maxon::GenericComponent* this_, const DataDictionary& info) { return ((typename S::Implementation*) this_)->SetInfo(info); }
		static Int DataDescriptionDefinitionInterface_GetEntryCount(const maxon::GenericComponent* this_) { return ((const typename S::Implementation*) this_)->GetEntryCount(); }
		static Result<BaseArray<DataDescriptionEntry>> DataDescriptionDefinitionInterface_GetEntries(const maxon::GenericComponent* this_) { return ((const typename S::Implementation*) this_)->GetEntries(); }
		static Result<DataDescriptionEntry> DataDescriptionDefinitionInterface_GetEntry(const maxon::GenericComponent* this_, Int idx) { return ((const typename S::Implementation*) this_)->GetEntry(idx); }
		static Result<DataDescriptionEntry> DataDescriptionDefinitionInterface_FindEntry(const maxon::GenericComponent* this_, const InternedId& id) { return ((const typename S::Implementation*) this_)->FindEntry(id); }
		static Result<Int> DataDescriptionDefinitionInterface_AddEntry(maxon::GenericComponent* this_, const DataDescriptionEntry& props) { return ((typename S::Implementation*) this_)->AddEntry(props); }
		static Result<void> DataDescriptionDefinitionInterface_ReplaceEntry(maxon::GenericComponent* this_, const DataDescriptionEntry& props) { return ((typename S::Implementation*) this_)->ReplaceEntry(props); }
		static Result<Bool> DataDescriptionDefinitionInterface_ReplaceEntry_1(maxon::GenericComponent* this_, Int idx, const DataDescriptionEntry& props) { return ((typename S::Implementation*) this_)->ReplaceEntry(idx, props); }
		static Result<void> DataDescriptionDefinitionInterface_EraseEntry(maxon::GenericComponent* this_, Int idx) { return ((typename S::Implementation*) this_)->EraseEntry(idx); }
		static void DataDescriptionDefinitionInterface_Reset(maxon::GenericComponent* this_) { return ((typename S::Implementation*) this_)->Reset(); }
		static Result<void> DataDescriptionDefinitionInterface_MergeDescriptionDefinition(DataDescriptionDefinition& target, const DataDescriptionDefinition& source, Bool overwriteIncludes, Bool skipIncludes) { return S::Implementation::MergeDescriptionDefinition(target, source, overwriteIncludes, skipIncludes); }
		static Result<Data> DataDescriptionDefinitionInterface_GetDataDefaults(const DataDictionary& dataEntry) { return S::Implementation::GetDataDefaults(dataEntry); }
		static Result<Data> DataDescriptionDefinitionInterface_GetDataValueOrDefaults(const InternedId& dataId, const DataDictionary& dataEntry, GETDATAFLAGS flags, const GetDataCallbackType& getDataCallback) { return S::Implementation::GetDataValueOrDefaults(dataId, dataEntry, flags, getDataCallback); }
		static DataDescriptionDefinitionInterface* DataDescriptionDefinitionInterface_Create() { return S::Implementation::Create(); }
		static const DataDescriptionDefinitionInterface* DataDescriptionDefinitionInterface_NullValuePtr() { return S::Implementation::NullValuePtr(); }
	};

};
MAXON_ATTRIBUTE_FORCE_INLINE auto DataDescriptionDefinitionInterface::GetInfo() const -> DataDictionary
{
	const DataDescriptionDefinitionInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(DataDescriptionDefinitionInterface, this); return mt_.DataDescriptionDefinitionInterface_GetInfo((const maxon::GenericComponent*) this + mt_.DataDescriptionDefinitionInterface_GetInfo_Offset);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto DataDescriptionDefinitionInterface::SetInfo(const DataDictionary& info) -> Result<void>
{
	const DataDescriptionDefinitionInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(DataDescriptionDefinitionInterface, this); return mt_.DataDescriptionDefinitionInterface_SetInfo((maxon::GenericComponent*) this + mt_.DataDescriptionDefinitionInterface_SetInfo_Offset, info);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto DataDescriptionDefinitionInterface::GetEntryCount() const -> Int
{
	const DataDescriptionDefinitionInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(DataDescriptionDefinitionInterface, this); return mt_.DataDescriptionDefinitionInterface_GetEntryCount((const maxon::GenericComponent*) this + mt_.DataDescriptionDefinitionInterface_GetEntryCount_Offset);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto DataDescriptionDefinitionInterface::GetEntries() const -> Result<BaseArray<DataDescriptionEntry>>
{
	const DataDescriptionDefinitionInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(DataDescriptionDefinitionInterface, this); return mt_.DataDescriptionDefinitionInterface_GetEntries((const maxon::GenericComponent*) this + mt_.DataDescriptionDefinitionInterface_GetEntries_Offset);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto DataDescriptionDefinitionInterface::GetEntry(Int idx) const -> Result<DataDescriptionEntry>
{
	const DataDescriptionDefinitionInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(DataDescriptionDefinitionInterface, this); return mt_.DataDescriptionDefinitionInterface_GetEntry((const maxon::GenericComponent*) this + mt_.DataDescriptionDefinitionInterface_GetEntry_Offset, idx);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto DataDescriptionDefinitionInterface::FindEntry(const InternedId& id) const -> Result<DataDescriptionEntry>
{
	const DataDescriptionDefinitionInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(DataDescriptionDefinitionInterface, this); return mt_.DataDescriptionDefinitionInterface_FindEntry((const maxon::GenericComponent*) this + mt_.DataDescriptionDefinitionInterface_FindEntry_Offset, id);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto DataDescriptionDefinitionInterface::AddEntry(const DataDescriptionEntry& props) -> Result<Int>
{
	const DataDescriptionDefinitionInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(DataDescriptionDefinitionInterface, this); return mt_.DataDescriptionDefinitionInterface_AddEntry((maxon::GenericComponent*) this + mt_.DataDescriptionDefinitionInterface_AddEntry_Offset, props);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto DataDescriptionDefinitionInterface::ReplaceEntry(const DataDescriptionEntry& props) -> Result<void>
{
	const DataDescriptionDefinitionInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(DataDescriptionDefinitionInterface, this); return mt_.DataDescriptionDefinitionInterface_ReplaceEntry((maxon::GenericComponent*) this + mt_.DataDescriptionDefinitionInterface_ReplaceEntry_Offset, props);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto DataDescriptionDefinitionInterface::ReplaceEntry(Int idx, const DataDescriptionEntry& props) -> Result<Bool>
{
	const DataDescriptionDefinitionInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(DataDescriptionDefinitionInterface, this); return mt_.DataDescriptionDefinitionInterface_ReplaceEntry_1((maxon::GenericComponent*) this + mt_.DataDescriptionDefinitionInterface_ReplaceEntry_1_Offset, idx, props);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto DataDescriptionDefinitionInterface::EraseEntry(Int idx) -> Result<void>
{
	const DataDescriptionDefinitionInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(DataDescriptionDefinitionInterface, this); return mt_.DataDescriptionDefinitionInterface_EraseEntry((maxon::GenericComponent*) this + mt_.DataDescriptionDefinitionInterface_EraseEntry_Offset, idx);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto DataDescriptionDefinitionInterface::Reset() -> void
{
	const DataDescriptionDefinitionInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(DataDescriptionDefinitionInterface, this); return mt_.DataDescriptionDefinitionInterface_Reset((maxon::GenericComponent*) this + mt_.DataDescriptionDefinitionInterface_Reset_Offset);
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
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<DataDictionary>, DataDictionary>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const DataDescriptionDefinitionInterface* o_ = (const DataDescriptionDefinitionInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = DataDescriptionDefinitionInterface::NullValuePtr(); if (!o_) return maxon::PrivateIncompleteNullReturnValue<DataDictionary>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(DataDescriptionDefinitionInterface, o_, DataDescriptionDefinitionInterface_GetInfo) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<DataDescriptionDefinitionInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<DataDescriptionDefinitionInterface>() : PRIVATE_MAXON_VTABLE(DataDescriptionDefinitionInterface, o_); 
	return (mt_.DataDescriptionDefinitionInterface_GetInfo(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.DataDescriptionDefinitionInterface_GetInfo_Offset));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto DataDescriptionDefinitionInterface::Hxx1::Fn<S>::SetInfo(const DataDictionary& info) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); DataDescriptionDefinitionInterface* o_ = (DataDescriptionDefinitionInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(DataDescriptionDefinitionInterface, o_, DataDescriptionDefinitionInterface_SetInfo) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<DataDescriptionDefinitionInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<DataDescriptionDefinitionInterface>() : PRIVATE_MAXON_VTABLE(DataDescriptionDefinitionInterface, o_); 
	return (mt_.DataDescriptionDefinitionInterface_SetInfo(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.DataDescriptionDefinitionInterface_SetInfo_Offset, info));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto DataDescriptionDefinitionInterface::Hxx1::COWFn<S>::SetInfo(const DataDictionary& info) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); DataDescriptionDefinitionInterface* o_ = (DataDescriptionDefinitionInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(DataDescriptionDefinitionInterface, o_, DataDescriptionDefinitionInterface_SetInfo) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<DataDescriptionDefinitionInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<DataDescriptionDefinitionInterface>() : PRIVATE_MAXON_VTABLE(DataDescriptionDefinitionInterface, o_); 
	return (mt_.DataDescriptionDefinitionInterface_SetInfo(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.DataDescriptionDefinitionInterface_SetInfo_Offset, info));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto DataDescriptionDefinitionInterface::Hxx1::ConstFn<S>::GetEntryCount() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const DataDescriptionDefinitionInterface* o_ = (const DataDescriptionDefinitionInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = DataDescriptionDefinitionInterface::NullValuePtr(); if (!o_) return 0; } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(DataDescriptionDefinitionInterface, o_, DataDescriptionDefinitionInterface_GetEntryCount) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<DataDescriptionDefinitionInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<DataDescriptionDefinitionInterface>() : PRIVATE_MAXON_VTABLE(DataDescriptionDefinitionInterface, o_); 
	return (mt_.DataDescriptionDefinitionInterface_GetEntryCount(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.DataDescriptionDefinitionInterface_GetEntryCount_Offset));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto DataDescriptionDefinitionInterface::Hxx1::ConstFn<S>::GetEntries() const -> Result<BaseArray<DataDescriptionEntry>>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<BaseArray<DataDescriptionEntry>>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const DataDescriptionDefinitionInterface* o_ = (const DataDescriptionDefinitionInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = DataDescriptionDefinitionInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(DataDescriptionDefinitionInterface, o_, DataDescriptionDefinitionInterface_GetEntries) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<DataDescriptionDefinitionInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<DataDescriptionDefinitionInterface>() : PRIVATE_MAXON_VTABLE(DataDescriptionDefinitionInterface, o_); 
	return (mt_.DataDescriptionDefinitionInterface_GetEntries(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.DataDescriptionDefinitionInterface_GetEntries_Offset));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto DataDescriptionDefinitionInterface::Hxx1::ConstFn<S>::GetEntry(Int idx) const -> Result<DataDescriptionEntry>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<DataDescriptionEntry>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const DataDescriptionDefinitionInterface* o_ = (const DataDescriptionDefinitionInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = DataDescriptionDefinitionInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(DataDescriptionDefinitionInterface, o_, DataDescriptionDefinitionInterface_GetEntry) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<DataDescriptionDefinitionInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<DataDescriptionDefinitionInterface>() : PRIVATE_MAXON_VTABLE(DataDescriptionDefinitionInterface, o_); 
	return (mt_.DataDescriptionDefinitionInterface_GetEntry(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.DataDescriptionDefinitionInterface_GetEntry_Offset, idx));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto DataDescriptionDefinitionInterface::Hxx1::ConstFn<S>::FindEntry(const InternedId& id) const -> Result<DataDescriptionEntry>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<DataDescriptionEntry>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const DataDescriptionDefinitionInterface* o_ = (const DataDescriptionDefinitionInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = DataDescriptionDefinitionInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(DataDescriptionDefinitionInterface, o_, DataDescriptionDefinitionInterface_FindEntry) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<DataDescriptionDefinitionInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<DataDescriptionDefinitionInterface>() : PRIVATE_MAXON_VTABLE(DataDescriptionDefinitionInterface, o_); 
	return (mt_.DataDescriptionDefinitionInterface_FindEntry(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.DataDescriptionDefinitionInterface_FindEntry_Offset, id));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto DataDescriptionDefinitionInterface::Hxx1::Fn<S>::AddEntry(const DataDescriptionEntry& props) const -> Result<Int>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<Int>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); DataDescriptionDefinitionInterface* o_ = (DataDescriptionDefinitionInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(DataDescriptionDefinitionInterface, o_, DataDescriptionDefinitionInterface_AddEntry) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<DataDescriptionDefinitionInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<DataDescriptionDefinitionInterface>() : PRIVATE_MAXON_VTABLE(DataDescriptionDefinitionInterface, o_); 
	return (mt_.DataDescriptionDefinitionInterface_AddEntry(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.DataDescriptionDefinitionInterface_AddEntry_Offset, props));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto DataDescriptionDefinitionInterface::Hxx1::COWFn<S>::AddEntry(const DataDescriptionEntry& props) -> Result<Int>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<Int>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); DataDescriptionDefinitionInterface* o_ = (DataDescriptionDefinitionInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(DataDescriptionDefinitionInterface, o_, DataDescriptionDefinitionInterface_AddEntry) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<DataDescriptionDefinitionInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<DataDescriptionDefinitionInterface>() : PRIVATE_MAXON_VTABLE(DataDescriptionDefinitionInterface, o_); 
	return (mt_.DataDescriptionDefinitionInterface_AddEntry(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.DataDescriptionDefinitionInterface_AddEntry_Offset, props));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto DataDescriptionDefinitionInterface::Hxx1::Fn<S>::ReplaceEntry(const DataDescriptionEntry& props) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); DataDescriptionDefinitionInterface* o_ = (DataDescriptionDefinitionInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(DataDescriptionDefinitionInterface, o_, DataDescriptionDefinitionInterface_ReplaceEntry) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<DataDescriptionDefinitionInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<DataDescriptionDefinitionInterface>() : PRIVATE_MAXON_VTABLE(DataDescriptionDefinitionInterface, o_); 
	return (mt_.DataDescriptionDefinitionInterface_ReplaceEntry(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.DataDescriptionDefinitionInterface_ReplaceEntry_Offset, props));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto DataDescriptionDefinitionInterface::Hxx1::COWFn<S>::ReplaceEntry(const DataDescriptionEntry& props) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); DataDescriptionDefinitionInterface* o_ = (DataDescriptionDefinitionInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(DataDescriptionDefinitionInterface, o_, DataDescriptionDefinitionInterface_ReplaceEntry) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<DataDescriptionDefinitionInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<DataDescriptionDefinitionInterface>() : PRIVATE_MAXON_VTABLE(DataDescriptionDefinitionInterface, o_); 
	return (mt_.DataDescriptionDefinitionInterface_ReplaceEntry(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.DataDescriptionDefinitionInterface_ReplaceEntry_Offset, props));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto DataDescriptionDefinitionInterface::Hxx1::Fn<S>::ReplaceEntry(Int idx, const DataDescriptionEntry& props) const -> Result<Bool>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<Bool>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); DataDescriptionDefinitionInterface* o_ = (DataDescriptionDefinitionInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(DataDescriptionDefinitionInterface, o_, DataDescriptionDefinitionInterface_ReplaceEntry_1) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<DataDescriptionDefinitionInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<DataDescriptionDefinitionInterface>() : PRIVATE_MAXON_VTABLE(DataDescriptionDefinitionInterface, o_); 
	return (mt_.DataDescriptionDefinitionInterface_ReplaceEntry_1(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.DataDescriptionDefinitionInterface_ReplaceEntry_1_Offset, idx, props));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto DataDescriptionDefinitionInterface::Hxx1::COWFn<S>::ReplaceEntry(Int idx, const DataDescriptionEntry& props) -> Result<Bool>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<Bool>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); DataDescriptionDefinitionInterface* o_ = (DataDescriptionDefinitionInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(DataDescriptionDefinitionInterface, o_, DataDescriptionDefinitionInterface_ReplaceEntry_1) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<DataDescriptionDefinitionInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<DataDescriptionDefinitionInterface>() : PRIVATE_MAXON_VTABLE(DataDescriptionDefinitionInterface, o_); 
	return (mt_.DataDescriptionDefinitionInterface_ReplaceEntry_1(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.DataDescriptionDefinitionInterface_ReplaceEntry_1_Offset, idx, props));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto DataDescriptionDefinitionInterface::Hxx1::Fn<S>::EraseEntry(Int idx) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); DataDescriptionDefinitionInterface* o_ = (DataDescriptionDefinitionInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(DataDescriptionDefinitionInterface, o_, DataDescriptionDefinitionInterface_EraseEntry) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<DataDescriptionDefinitionInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<DataDescriptionDefinitionInterface>() : PRIVATE_MAXON_VTABLE(DataDescriptionDefinitionInterface, o_); 
	return (mt_.DataDescriptionDefinitionInterface_EraseEntry(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.DataDescriptionDefinitionInterface_EraseEntry_Offset, idx));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto DataDescriptionDefinitionInterface::Hxx1::COWFn<S>::EraseEntry(Int idx) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); DataDescriptionDefinitionInterface* o_ = (DataDescriptionDefinitionInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(DataDescriptionDefinitionInterface, o_, DataDescriptionDefinitionInterface_EraseEntry) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<DataDescriptionDefinitionInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<DataDescriptionDefinitionInterface>() : PRIVATE_MAXON_VTABLE(DataDescriptionDefinitionInterface, o_); 
	return (mt_.DataDescriptionDefinitionInterface_EraseEntry(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.DataDescriptionDefinitionInterface_EraseEntry_Offset, idx));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto DataDescriptionDefinitionInterface::Hxx1::Fn<S>::Reset() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); DataDescriptionDefinitionInterface* o_ = (DataDescriptionDefinitionInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { DebugStop(); return maxon::PrivateLogNullptrError(); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(DataDescriptionDefinitionInterface, o_, DataDescriptionDefinitionInterface_Reset) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<DataDescriptionDefinitionInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<DataDescriptionDefinitionInterface>() : PRIVATE_MAXON_VTABLE(DataDescriptionDefinitionInterface, o_); 
	mt_.DataDescriptionDefinitionInterface_Reset(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.DataDescriptionDefinitionInterface_Reset_Offset);
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto DataDescriptionDefinitionInterface::Hxx1::COWFn<S>::Reset() -> typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), void, maxon::Result<void>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), void, maxon::Result<void>>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); DataDescriptionDefinitionInterface* o_ = (DataDescriptionDefinitionInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(DataDescriptionDefinitionInterface, o_, DataDescriptionDefinitionInterface_Reset) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<DataDescriptionDefinitionInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<DataDescriptionDefinitionInterface>() : PRIVATE_MAXON_VTABLE(DataDescriptionDefinitionInterface, o_); 
	mt_.DataDescriptionDefinitionInterface_Reset(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.DataDescriptionDefinitionInterface_Reset_Offset);
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

