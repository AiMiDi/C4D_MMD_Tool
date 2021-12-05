
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
	static const maxon::Bool HAS_NONSTATIC = false;
	DataDictionary (*_DataDescriptionDefinitionInterface_GetInfo) (const maxon::GenericComponent* this_);
	maxon::Int _DataDescriptionDefinitionInterface_GetInfo_Offset;
	Result<void> (*_DataDescriptionDefinitionInterface_SetInfo) (maxon::GenericComponent* this_, const DataDictionary& info);
	maxon::Int _DataDescriptionDefinitionInterface_SetInfo_Offset;
	Int (*_DataDescriptionDefinitionInterface_GetEntryCount) (const maxon::GenericComponent* this_);
	maxon::Int _DataDescriptionDefinitionInterface_GetEntryCount_Offset;
	Result<BaseArray<DataDescriptionEntry>> (*_DataDescriptionDefinitionInterface_GetEntries) (const maxon::GenericComponent* this_);
	maxon::Int _DataDescriptionDefinitionInterface_GetEntries_Offset;
	Result<DataDescriptionEntry> (*_DataDescriptionDefinitionInterface_GetEntry) (const maxon::GenericComponent* this_, Int idx);
	maxon::Int _DataDescriptionDefinitionInterface_GetEntry_Offset;
	Result<DataDescriptionEntry> (*_DataDescriptionDefinitionInterface_FindEntry) (const maxon::GenericComponent* this_, const InternedId& id);
	maxon::Int _DataDescriptionDefinitionInterface_FindEntry_Offset;
	Result<Int> (*_DataDescriptionDefinitionInterface_AddEntry) (maxon::GenericComponent* this_, const DataDescriptionEntry& props);
	maxon::Int _DataDescriptionDefinitionInterface_AddEntry_Offset;
	Result<void> (*_DataDescriptionDefinitionInterface_ReplaceEntry) (maxon::GenericComponent* this_, const DataDescriptionEntry& props);
	maxon::Int _DataDescriptionDefinitionInterface_ReplaceEntry_Offset;
	Result<Bool> (*_DataDescriptionDefinitionInterface_ReplaceEntry_1) (maxon::GenericComponent* this_, Int idx, const DataDescriptionEntry& props);
	maxon::Int _DataDescriptionDefinitionInterface_ReplaceEntry_1_Offset;
	Result<void> (*_DataDescriptionDefinitionInterface_EraseEntry) (maxon::GenericComponent* this_, Int idx);
	maxon::Int _DataDescriptionDefinitionInterface_EraseEntry_Offset;
	void (*_DataDescriptionDefinitionInterface_Reset) (maxon::GenericComponent* this_);
	maxon::Int _DataDescriptionDefinitionInterface_Reset_Offset;
	template <typename W> void Init(maxon::Int offset)
	{
		if (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, DataDescriptionDefinitionInterface, GetInfo))
		{
			auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, DataDescriptionDefinitionInterface, GetInfo), W, MTable>::type::_DataDescriptionDefinitionInterface_GetInfo;
			_DataDescriptionDefinitionInterface_GetInfo = reinterpret_cast<const decltype(_DataDescriptionDefinitionInterface_GetInfo)&>(ptr);
			_DataDescriptionDefinitionInterface_GetInfo_Offset = offset;
		}
		if (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, DataDescriptionDefinitionInterface, SetInfo))
		{
			auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, DataDescriptionDefinitionInterface, SetInfo), W, MTable>::type::_DataDescriptionDefinitionInterface_SetInfo;
			_DataDescriptionDefinitionInterface_SetInfo = reinterpret_cast<const decltype(_DataDescriptionDefinitionInterface_SetInfo)&>(ptr);
			_DataDescriptionDefinitionInterface_SetInfo_Offset = offset;
		}
		if (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, DataDescriptionDefinitionInterface, GetEntryCount))
		{
			auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, DataDescriptionDefinitionInterface, GetEntryCount), W, MTable>::type::_DataDescriptionDefinitionInterface_GetEntryCount;
			_DataDescriptionDefinitionInterface_GetEntryCount = reinterpret_cast<const decltype(_DataDescriptionDefinitionInterface_GetEntryCount)&>(ptr);
			_DataDescriptionDefinitionInterface_GetEntryCount_Offset = offset;
		}
		if (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, DataDescriptionDefinitionInterface, GetEntries))
		{
			auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, DataDescriptionDefinitionInterface, GetEntries), W, MTable>::type::_DataDescriptionDefinitionInterface_GetEntries;
			_DataDescriptionDefinitionInterface_GetEntries = reinterpret_cast<const decltype(_DataDescriptionDefinitionInterface_GetEntries)&>(ptr);
			_DataDescriptionDefinitionInterface_GetEntries_Offset = offset;
		}
		if (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, DataDescriptionDefinitionInterface, GetEntry))
		{
			auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, DataDescriptionDefinitionInterface, GetEntry), W, MTable>::type::_DataDescriptionDefinitionInterface_GetEntry;
			_DataDescriptionDefinitionInterface_GetEntry = reinterpret_cast<const decltype(_DataDescriptionDefinitionInterface_GetEntry)&>(ptr);
			_DataDescriptionDefinitionInterface_GetEntry_Offset = offset;
		}
		if (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, DataDescriptionDefinitionInterface, FindEntry))
		{
			auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, DataDescriptionDefinitionInterface, FindEntry), W, MTable>::type::_DataDescriptionDefinitionInterface_FindEntry;
			_DataDescriptionDefinitionInterface_FindEntry = reinterpret_cast<const decltype(_DataDescriptionDefinitionInterface_FindEntry)&>(ptr);
			_DataDescriptionDefinitionInterface_FindEntry_Offset = offset;
		}
		if (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, DataDescriptionDefinitionInterface, AddEntry))
		{
			auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, DataDescriptionDefinitionInterface, AddEntry), W, MTable>::type::_DataDescriptionDefinitionInterface_AddEntry;
			_DataDescriptionDefinitionInterface_AddEntry = reinterpret_cast<const decltype(_DataDescriptionDefinitionInterface_AddEntry)&>(ptr);
			_DataDescriptionDefinitionInterface_AddEntry_Offset = offset;
		}
		if (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, DataDescriptionDefinitionInterface, ReplaceEntry))
		{
			auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, DataDescriptionDefinitionInterface, ReplaceEntry), W, MTable>::type::_DataDescriptionDefinitionInterface_ReplaceEntry;
			_DataDescriptionDefinitionInterface_ReplaceEntry = reinterpret_cast<const decltype(_DataDescriptionDefinitionInterface_ReplaceEntry)&>(ptr);
			_DataDescriptionDefinitionInterface_ReplaceEntry_Offset = offset;
		}
		if (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, DataDescriptionDefinitionInterface, ReplaceEntry))
		{
			auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, DataDescriptionDefinitionInterface, ReplaceEntry), W, MTable>::type::_DataDescriptionDefinitionInterface_ReplaceEntry_1;
			_DataDescriptionDefinitionInterface_ReplaceEntry_1 = reinterpret_cast<const decltype(_DataDescriptionDefinitionInterface_ReplaceEntry_1)&>(ptr);
			_DataDescriptionDefinitionInterface_ReplaceEntry_1_Offset = offset;
		}
		if (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, DataDescriptionDefinitionInterface, EraseEntry))
		{
			auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, DataDescriptionDefinitionInterface, EraseEntry), W, MTable>::type::_DataDescriptionDefinitionInterface_EraseEntry;
			_DataDescriptionDefinitionInterface_EraseEntry = reinterpret_cast<const decltype(_DataDescriptionDefinitionInterface_EraseEntry)&>(ptr);
			_DataDescriptionDefinitionInterface_EraseEntry_Offset = offset;
		}
		if (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, DataDescriptionDefinitionInterface, Reset))
		{
			auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, DataDescriptionDefinitionInterface, Reset), W, MTable>::type::_DataDescriptionDefinitionInterface_Reset;
			_DataDescriptionDefinitionInterface_Reset = reinterpret_cast<const decltype(_DataDescriptionDefinitionInterface_Reset)&>(ptr);
			_DataDescriptionDefinitionInterface_Reset_Offset = offset;
		}
	}
	template <typename W> static maxon::Bool InitWithBases(maxon::ClassInfo* info, maxon::Int offset)
	{
		if (!W::Implementation::PROXY && (!ObserverObjectInterface::MTable::template InitWithBases<W>(info, offset))) return false;
		MTable* vt = (MTable*) maxon::ObjectInterface::PrivateGetOrCreateMTable(info, _interface); if (!vt) return false;
		vt->Init<W>(offset); return true;
	}
	template <typename S> using CombinedMTable = maxon::CombinedMTable<DataDescriptionDefinitionInterface, typename ObserverObjectInterface::MTable::template CombinedMTable<S>>;
	PRIVATE_MAXON_COMPBASE(DataDescriptionDefinitionInterface);
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
	Result<void> (*_DataDescriptionDefinitionInterface_MergeDescriptionDefinition) (DataDescriptionDefinition& target, const DataDescriptionDefinition& source, Bool overwriteIncludes, Bool skipIncludes);
	Result<Data> (*_DataDescriptionDefinitionInterface_GetDataDefaults) (const DataDictionary& dataEntry);
	Result<Data> (*_DataDescriptionDefinitionInterface_GetDataValueOrDefaults) (const InternedId& dataId, const DataDictionary& dataEntry, GETDATAFLAGS flags, const GetDataCallbackType& getDataCallback);
	DataDescriptionDefinitionInterface* (*_DataDescriptionDefinitionInterface_Create) ();
	const DataDescriptionDefinitionInterface* (*_DataDescriptionDefinitionInterface_NullValuePtr) ();
		StaticMTable() = default;
		template <typename IMPL> static void Init(StaticMTable* tbl)
		{
		tbl->_DataDescriptionDefinitionInterface_MergeDescriptionDefinition = &IMPL::_DataDescriptionDefinitionInterface_MergeDescriptionDefinition;
		tbl->_DataDescriptionDefinitionInterface_GetDataDefaults = &IMPL::_DataDescriptionDefinitionInterface_GetDataDefaults;
		tbl->_DataDescriptionDefinitionInterface_GetDataValueOrDefaults = &IMPL::_DataDescriptionDefinitionInterface_GetDataValueOrDefaults;
		tbl->_DataDescriptionDefinitionInterface_Create = &IMPL::_DataDescriptionDefinitionInterface_Create;
		tbl->_DataDescriptionDefinitionInterface_NullValuePtr = &IMPL::_DataDescriptionDefinitionInterface_NullValuePtr;
		}
	};
	template <typename S> class Wrapper : public ObserverObjectInterface::Hxx2::template Wrapper<S>
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
	static DataDictionary _DataDescriptionDefinitionInterface_GetInfo(const maxon::GenericComponent* this_) { return ((const typename S::Implementation*) this_)->GetInfo(); }
	static Result<void> _DataDescriptionDefinitionInterface_SetInfo(maxon::GenericComponent* this_, const DataDictionary& info) { return ((typename S::Implementation*) this_)->SetInfo(info); }
	static Int _DataDescriptionDefinitionInterface_GetEntryCount(const maxon::GenericComponent* this_) { return ((const typename S::Implementation*) this_)->GetEntryCount(); }
	static Result<BaseArray<DataDescriptionEntry>> _DataDescriptionDefinitionInterface_GetEntries(const maxon::GenericComponent* this_) { return ((const typename S::Implementation*) this_)->GetEntries(); }
	static Result<DataDescriptionEntry> _DataDescriptionDefinitionInterface_GetEntry(const maxon::GenericComponent* this_, Int idx) { return ((const typename S::Implementation*) this_)->GetEntry(idx); }
	static Result<DataDescriptionEntry> _DataDescriptionDefinitionInterface_FindEntry(const maxon::GenericComponent* this_, const InternedId& id) { return ((const typename S::Implementation*) this_)->FindEntry(id); }
	static Result<Int> _DataDescriptionDefinitionInterface_AddEntry(maxon::GenericComponent* this_, const DataDescriptionEntry& props) { return ((typename S::Implementation*) this_)->AddEntry(props); }
	static Result<void> _DataDescriptionDefinitionInterface_ReplaceEntry(maxon::GenericComponent* this_, const DataDescriptionEntry& props) { return ((typename S::Implementation*) this_)->ReplaceEntry(props); }
	static Result<Bool> _DataDescriptionDefinitionInterface_ReplaceEntry_1(maxon::GenericComponent* this_, Int idx, const DataDescriptionEntry& props) { return ((typename S::Implementation*) this_)->ReplaceEntry(idx, props); }
	static Result<void> _DataDescriptionDefinitionInterface_EraseEntry(maxon::GenericComponent* this_, Int idx) { return ((typename S::Implementation*) this_)->EraseEntry(idx); }
	static void _DataDescriptionDefinitionInterface_Reset(maxon::GenericComponent* this_) { return ((typename S::Implementation*) this_)->Reset(); }
	static Result<void> _DataDescriptionDefinitionInterface_MergeDescriptionDefinition(DataDescriptionDefinition& target, const DataDescriptionDefinition& source, Bool overwriteIncludes, Bool skipIncludes) { return S::Implementation::MergeDescriptionDefinition(target, source, overwriteIncludes, skipIncludes); }
	static Result<Data> _DataDescriptionDefinitionInterface_GetDataDefaults(const DataDictionary& dataEntry) { return S::Implementation::GetDataDefaults(dataEntry); }
	static Result<Data> _DataDescriptionDefinitionInterface_GetDataValueOrDefaults(const InternedId& dataId, const DataDictionary& dataEntry, GETDATAFLAGS flags, const GetDataCallbackType& getDataCallback) { return S::Implementation::GetDataValueOrDefaults(dataId, dataEntry, flags, getDataCallback); }
	static DataDescriptionDefinitionInterface* _DataDescriptionDefinitionInterface_Create() { return S::Implementation::Create(); }
	static const DataDescriptionDefinitionInterface* _DataDescriptionDefinitionInterface_NullValuePtr() { return S::Implementation::NullValuePtr(); }
	};

};
MAXON_ATTRIBUTE_FORCE_INLINE auto DataDescriptionDefinitionInterface::GetInfo() const -> DataDictionary
{
	const DataDescriptionDefinitionInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(DataDescriptionDefinitionInterface, this); return mt_._DataDescriptionDefinitionInterface_GetInfo((const maxon::GenericComponent*) this + mt_._DataDescriptionDefinitionInterface_GetInfo_Offset);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto DataDescriptionDefinitionInterface::SetInfo(const DataDictionary& info) -> Result<void>
{
	const DataDescriptionDefinitionInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(DataDescriptionDefinitionInterface, this); return mt_._DataDescriptionDefinitionInterface_SetInfo((maxon::GenericComponent*) this + mt_._DataDescriptionDefinitionInterface_SetInfo_Offset, info);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto DataDescriptionDefinitionInterface::GetEntryCount() const -> Int
{
	const DataDescriptionDefinitionInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(DataDescriptionDefinitionInterface, this); return mt_._DataDescriptionDefinitionInterface_GetEntryCount((const maxon::GenericComponent*) this + mt_._DataDescriptionDefinitionInterface_GetEntryCount_Offset);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto DataDescriptionDefinitionInterface::GetEntries() const -> Result<BaseArray<DataDescriptionEntry>>
{
	const DataDescriptionDefinitionInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(DataDescriptionDefinitionInterface, this); return mt_._DataDescriptionDefinitionInterface_GetEntries((const maxon::GenericComponent*) this + mt_._DataDescriptionDefinitionInterface_GetEntries_Offset);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto DataDescriptionDefinitionInterface::GetEntry(Int idx) const -> Result<DataDescriptionEntry>
{
	const DataDescriptionDefinitionInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(DataDescriptionDefinitionInterface, this); return mt_._DataDescriptionDefinitionInterface_GetEntry((const maxon::GenericComponent*) this + mt_._DataDescriptionDefinitionInterface_GetEntry_Offset, idx);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto DataDescriptionDefinitionInterface::FindEntry(const InternedId& id) const -> Result<DataDescriptionEntry>
{
	const DataDescriptionDefinitionInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(DataDescriptionDefinitionInterface, this); return mt_._DataDescriptionDefinitionInterface_FindEntry((const maxon::GenericComponent*) this + mt_._DataDescriptionDefinitionInterface_FindEntry_Offset, id);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto DataDescriptionDefinitionInterface::AddEntry(const DataDescriptionEntry& props) -> Result<Int>
{
	const DataDescriptionDefinitionInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(DataDescriptionDefinitionInterface, this); return mt_._DataDescriptionDefinitionInterface_AddEntry((maxon::GenericComponent*) this + mt_._DataDescriptionDefinitionInterface_AddEntry_Offset, props);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto DataDescriptionDefinitionInterface::ReplaceEntry(const DataDescriptionEntry& props) -> Result<void>
{
	const DataDescriptionDefinitionInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(DataDescriptionDefinitionInterface, this); return mt_._DataDescriptionDefinitionInterface_ReplaceEntry((maxon::GenericComponent*) this + mt_._DataDescriptionDefinitionInterface_ReplaceEntry_Offset, props);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto DataDescriptionDefinitionInterface::ReplaceEntry(Int idx, const DataDescriptionEntry& props) -> Result<Bool>
{
	const DataDescriptionDefinitionInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(DataDescriptionDefinitionInterface, this); return mt_._DataDescriptionDefinitionInterface_ReplaceEntry_1((maxon::GenericComponent*) this + mt_._DataDescriptionDefinitionInterface_ReplaceEntry_1_Offset, idx, props);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto DataDescriptionDefinitionInterface::EraseEntry(Int idx) -> Result<void>
{
	const DataDescriptionDefinitionInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(DataDescriptionDefinitionInterface, this); return mt_._DataDescriptionDefinitionInterface_EraseEntry((maxon::GenericComponent*) this + mt_._DataDescriptionDefinitionInterface_EraseEntry_Offset, idx);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto DataDescriptionDefinitionInterface::Reset() -> void
{
	const DataDescriptionDefinitionInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(DataDescriptionDefinitionInterface, this); return mt_._DataDescriptionDefinitionInterface_Reset((maxon::GenericComponent*) this + mt_._DataDescriptionDefinitionInterface_Reset_Offset);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto DataDescriptionDefinitionInterface::MergeDescriptionDefinition(DataDescriptionDefinition& target, const DataDescriptionDefinition& source, Bool overwriteIncludes, Bool skipIncludes) -> Result<void>
{
	return Hxx2::StaticMTable::_instance._DataDescriptionDefinitionInterface_MergeDescriptionDefinition(target, source, overwriteIncludes, skipIncludes);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto DataDescriptionDefinitionInterface::GetDataDefaults(const DataDictionary& dataEntry) -> Result<Data>
{
	return Hxx2::StaticMTable::_instance._DataDescriptionDefinitionInterface_GetDataDefaults(dataEntry);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto DataDescriptionDefinitionInterface::GetDataValueOrDefaults(const InternedId& dataId, const DataDictionary& dataEntry, GETDATAFLAGS flags, const GetDataCallbackType& getDataCallback) -> Result<Data>
{
	return Hxx2::StaticMTable::_instance._DataDescriptionDefinitionInterface_GetDataValueOrDefaults(dataId, dataEntry, flags, getDataCallback);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto DataDescriptionDefinitionInterface::Create() -> DataDescriptionDefinitionInterface*
{
	return Hxx2::StaticMTable::_instance._DataDescriptionDefinitionInterface_Create();
}
MAXON_ATTRIBUTE_FORCE_INLINE auto DataDescriptionDefinitionInterface::NullValuePtr() -> const DataDescriptionDefinitionInterface*
{
	return Hxx2::StaticMTable::_instance._DataDescriptionDefinitionInterface_NullValuePtr();
}

template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto DataDescriptionDefinitionInterface::Hxx1::ConstReferenceFunctionsImpl<S>::GetInfo() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<DataDictionary>, DataDictionary>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<DataDictionary>, DataDictionary>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const DataDescriptionDefinitionInterface* o_ = (const DataDescriptionDefinitionInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = DataDescriptionDefinitionInterface::NullValuePtr(); if (!o_) return maxon::PrivateIncompleteNullReturnValue<DataDictionary>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(DataDescriptionDefinitionInterface, o_, DataDescriptionDefinitionInterface_GetInfo) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<DataDescriptionDefinitionInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<DataDescriptionDefinitionInterface>() : PRIVATE_MAXON_VTABLE(DataDescriptionDefinitionInterface, o_); 
	return (mt_._DataDescriptionDefinitionInterface_GetInfo(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_._DataDescriptionDefinitionInterface_GetInfo_Offset));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto DataDescriptionDefinitionInterface::Hxx1::ReferenceFunctionsImpl<S>::SetInfo(const DataDictionary& info) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); DataDescriptionDefinitionInterface* o_ = (DataDescriptionDefinitionInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(DataDescriptionDefinitionInterface, o_, DataDescriptionDefinitionInterface_SetInfo) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<DataDescriptionDefinitionInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<DataDescriptionDefinitionInterface>() : PRIVATE_MAXON_VTABLE(DataDescriptionDefinitionInterface, o_); 
	return (mt_._DataDescriptionDefinitionInterface_SetInfo(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._DataDescriptionDefinitionInterface_SetInfo_Offset, info));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto DataDescriptionDefinitionInterface::Hxx1::COWReferenceFunctionsImpl<S>::SetInfo(const DataDictionary& info) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); DataDescriptionDefinitionInterface* o_ = (DataDescriptionDefinitionInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(DataDescriptionDefinitionInterface, o_, DataDescriptionDefinitionInterface_SetInfo) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<DataDescriptionDefinitionInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<DataDescriptionDefinitionInterface>() : PRIVATE_MAXON_VTABLE(DataDescriptionDefinitionInterface, o_); 
	return (mt_._DataDescriptionDefinitionInterface_SetInfo(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._DataDescriptionDefinitionInterface_SetInfo_Offset, info));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto DataDescriptionDefinitionInterface::Hxx1::ConstReferenceFunctionsImpl<S>::GetEntryCount() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const DataDescriptionDefinitionInterface* o_ = (const DataDescriptionDefinitionInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = DataDescriptionDefinitionInterface::NullValuePtr(); if (!o_) return 0; } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(DataDescriptionDefinitionInterface, o_, DataDescriptionDefinitionInterface_GetEntryCount) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<DataDescriptionDefinitionInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<DataDescriptionDefinitionInterface>() : PRIVATE_MAXON_VTABLE(DataDescriptionDefinitionInterface, o_); 
	return (mt_._DataDescriptionDefinitionInterface_GetEntryCount(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_._DataDescriptionDefinitionInterface_GetEntryCount_Offset));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto DataDescriptionDefinitionInterface::Hxx1::ConstReferenceFunctionsImpl<S>::GetEntries() const -> Result<BaseArray<DataDescriptionEntry>>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<BaseArray<DataDescriptionEntry>>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const DataDescriptionDefinitionInterface* o_ = (const DataDescriptionDefinitionInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = DataDescriptionDefinitionInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(DataDescriptionDefinitionInterface, o_, DataDescriptionDefinitionInterface_GetEntries) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<DataDescriptionDefinitionInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<DataDescriptionDefinitionInterface>() : PRIVATE_MAXON_VTABLE(DataDescriptionDefinitionInterface, o_); 
	return (mt_._DataDescriptionDefinitionInterface_GetEntries(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_._DataDescriptionDefinitionInterface_GetEntries_Offset));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto DataDescriptionDefinitionInterface::Hxx1::ConstReferenceFunctionsImpl<S>::GetEntry(Int idx) const -> Result<DataDescriptionEntry>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<DataDescriptionEntry>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const DataDescriptionDefinitionInterface* o_ = (const DataDescriptionDefinitionInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = DataDescriptionDefinitionInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(DataDescriptionDefinitionInterface, o_, DataDescriptionDefinitionInterface_GetEntry) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<DataDescriptionDefinitionInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<DataDescriptionDefinitionInterface>() : PRIVATE_MAXON_VTABLE(DataDescriptionDefinitionInterface, o_); 
	return (mt_._DataDescriptionDefinitionInterface_GetEntry(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_._DataDescriptionDefinitionInterface_GetEntry_Offset, idx));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto DataDescriptionDefinitionInterface::Hxx1::ConstReferenceFunctionsImpl<S>::FindEntry(const InternedId& id) const -> Result<DataDescriptionEntry>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<DataDescriptionEntry>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const DataDescriptionDefinitionInterface* o_ = (const DataDescriptionDefinitionInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = DataDescriptionDefinitionInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(DataDescriptionDefinitionInterface, o_, DataDescriptionDefinitionInterface_FindEntry) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<DataDescriptionDefinitionInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<DataDescriptionDefinitionInterface>() : PRIVATE_MAXON_VTABLE(DataDescriptionDefinitionInterface, o_); 
	return (mt_._DataDescriptionDefinitionInterface_FindEntry(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_._DataDescriptionDefinitionInterface_FindEntry_Offset, id));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto DataDescriptionDefinitionInterface::Hxx1::ReferenceFunctionsImpl<S>::AddEntry(const DataDescriptionEntry& props) const -> Result<Int>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<Int>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); DataDescriptionDefinitionInterface* o_ = (DataDescriptionDefinitionInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(DataDescriptionDefinitionInterface, o_, DataDescriptionDefinitionInterface_AddEntry) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<DataDescriptionDefinitionInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<DataDescriptionDefinitionInterface>() : PRIVATE_MAXON_VTABLE(DataDescriptionDefinitionInterface, o_); 
	return (mt_._DataDescriptionDefinitionInterface_AddEntry(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._DataDescriptionDefinitionInterface_AddEntry_Offset, props));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto DataDescriptionDefinitionInterface::Hxx1::COWReferenceFunctionsImpl<S>::AddEntry(const DataDescriptionEntry& props) -> Result<Int>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<Int>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); DataDescriptionDefinitionInterface* o_ = (DataDescriptionDefinitionInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(DataDescriptionDefinitionInterface, o_, DataDescriptionDefinitionInterface_AddEntry) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<DataDescriptionDefinitionInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<DataDescriptionDefinitionInterface>() : PRIVATE_MAXON_VTABLE(DataDescriptionDefinitionInterface, o_); 
	return (mt_._DataDescriptionDefinitionInterface_AddEntry(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._DataDescriptionDefinitionInterface_AddEntry_Offset, props));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto DataDescriptionDefinitionInterface::Hxx1::ReferenceFunctionsImpl<S>::ReplaceEntry(const DataDescriptionEntry& props) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); DataDescriptionDefinitionInterface* o_ = (DataDescriptionDefinitionInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(DataDescriptionDefinitionInterface, o_, DataDescriptionDefinitionInterface_ReplaceEntry) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<DataDescriptionDefinitionInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<DataDescriptionDefinitionInterface>() : PRIVATE_MAXON_VTABLE(DataDescriptionDefinitionInterface, o_); 
	return (mt_._DataDescriptionDefinitionInterface_ReplaceEntry(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._DataDescriptionDefinitionInterface_ReplaceEntry_Offset, props));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto DataDescriptionDefinitionInterface::Hxx1::COWReferenceFunctionsImpl<S>::ReplaceEntry(const DataDescriptionEntry& props) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); DataDescriptionDefinitionInterface* o_ = (DataDescriptionDefinitionInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(DataDescriptionDefinitionInterface, o_, DataDescriptionDefinitionInterface_ReplaceEntry) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<DataDescriptionDefinitionInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<DataDescriptionDefinitionInterface>() : PRIVATE_MAXON_VTABLE(DataDescriptionDefinitionInterface, o_); 
	return (mt_._DataDescriptionDefinitionInterface_ReplaceEntry(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._DataDescriptionDefinitionInterface_ReplaceEntry_Offset, props));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto DataDescriptionDefinitionInterface::Hxx1::ReferenceFunctionsImpl<S>::ReplaceEntry(Int idx, const DataDescriptionEntry& props) const -> Result<Bool>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<Bool>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); DataDescriptionDefinitionInterface* o_ = (DataDescriptionDefinitionInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(DataDescriptionDefinitionInterface, o_, DataDescriptionDefinitionInterface_ReplaceEntry_1) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<DataDescriptionDefinitionInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<DataDescriptionDefinitionInterface>() : PRIVATE_MAXON_VTABLE(DataDescriptionDefinitionInterface, o_); 
	return (mt_._DataDescriptionDefinitionInterface_ReplaceEntry_1(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._DataDescriptionDefinitionInterface_ReplaceEntry_1_Offset, idx, props));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto DataDescriptionDefinitionInterface::Hxx1::COWReferenceFunctionsImpl<S>::ReplaceEntry(Int idx, const DataDescriptionEntry& props) -> Result<Bool>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<Bool>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); DataDescriptionDefinitionInterface* o_ = (DataDescriptionDefinitionInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(DataDescriptionDefinitionInterface, o_, DataDescriptionDefinitionInterface_ReplaceEntry_1) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<DataDescriptionDefinitionInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<DataDescriptionDefinitionInterface>() : PRIVATE_MAXON_VTABLE(DataDescriptionDefinitionInterface, o_); 
	return (mt_._DataDescriptionDefinitionInterface_ReplaceEntry_1(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._DataDescriptionDefinitionInterface_ReplaceEntry_1_Offset, idx, props));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto DataDescriptionDefinitionInterface::Hxx1::ReferenceFunctionsImpl<S>::EraseEntry(Int idx) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); DataDescriptionDefinitionInterface* o_ = (DataDescriptionDefinitionInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(DataDescriptionDefinitionInterface, o_, DataDescriptionDefinitionInterface_EraseEntry) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<DataDescriptionDefinitionInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<DataDescriptionDefinitionInterface>() : PRIVATE_MAXON_VTABLE(DataDescriptionDefinitionInterface, o_); 
	return (mt_._DataDescriptionDefinitionInterface_EraseEntry(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._DataDescriptionDefinitionInterface_EraseEntry_Offset, idx));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto DataDescriptionDefinitionInterface::Hxx1::COWReferenceFunctionsImpl<S>::EraseEntry(Int idx) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); DataDescriptionDefinitionInterface* o_ = (DataDescriptionDefinitionInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(DataDescriptionDefinitionInterface, o_, DataDescriptionDefinitionInterface_EraseEntry) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<DataDescriptionDefinitionInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<DataDescriptionDefinitionInterface>() : PRIVATE_MAXON_VTABLE(DataDescriptionDefinitionInterface, o_); 
	return (mt_._DataDescriptionDefinitionInterface_EraseEntry(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._DataDescriptionDefinitionInterface_EraseEntry_Offset, idx));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto DataDescriptionDefinitionInterface::Hxx1::ReferenceFunctionsImpl<S>::Reset() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); DataDescriptionDefinitionInterface* o_ = (DataDescriptionDefinitionInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) return maxon::PrivateLogNullptrError(); const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(DataDescriptionDefinitionInterface, o_, DataDescriptionDefinitionInterface_Reset) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<DataDescriptionDefinitionInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<DataDescriptionDefinitionInterface>() : PRIVATE_MAXON_VTABLE(DataDescriptionDefinitionInterface, o_); 
	mt_._DataDescriptionDefinitionInterface_Reset(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._DataDescriptionDefinitionInterface_Reset_Offset);
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto DataDescriptionDefinitionInterface::Hxx1::COWReferenceFunctionsImpl<S>::Reset() -> typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), void, maxon::Result<void>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), void, maxon::Result<void>>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); DataDescriptionDefinitionInterface* o_ = (DataDescriptionDefinitionInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(DataDescriptionDefinitionInterface, o_, DataDescriptionDefinitionInterface_Reset) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<DataDescriptionDefinitionInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<DataDescriptionDefinitionInterface>() : PRIVATE_MAXON_VTABLE(DataDescriptionDefinitionInterface, o_); 
	mt_._DataDescriptionDefinitionInterface_Reset(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._DataDescriptionDefinitionInterface_Reset_Offset);
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto DataDescriptionDefinitionInterface::Hxx1::ConstReferenceFunctionsImpl<S>::MergeDescriptionDefinition(DataDescriptionDefinition& target, const DataDescriptionDefinition& source, Bool overwriteIncludes, Bool skipIncludes) -> Result<void> { return (Hxx2::StaticMTable::_instance._DataDescriptionDefinitionInterface_MergeDescriptionDefinition(target, source, overwriteIncludes, skipIncludes)); }
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto DataDescriptionDefinitionInterface::Hxx1::ConstReferenceFunctionsImpl<S>::GetDataDefaults(const DataDictionary& dataEntry) -> Result<Data> { return (Hxx2::StaticMTable::_instance._DataDescriptionDefinitionInterface_GetDataDefaults(dataEntry)); }
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto DataDescriptionDefinitionInterface::Hxx1::ConstReferenceFunctionsImpl<S>::GetDataValueOrDefaults(const InternedId& dataId, const DataDictionary& dataEntry, GETDATAFLAGS flags, const GetDataCallbackType& getDataCallback) -> Result<Data> { return (Hxx2::StaticMTable::_instance._DataDescriptionDefinitionInterface_GetDataValueOrDefaults(dataId, dataEntry, flags, getDataCallback)); }
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto DataDescriptionDefinitionInterface::Hxx1::ConstReferenceFunctionsImpl<S>::Create() -> DataDescriptionDefinition { return DataDescriptionDefinition(Hxx2::StaticMTable::_instance._DataDescriptionDefinitionInterface_Create()); }
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto DataDescriptionDefinitionInterface::Hxx1::ConstReferenceFunctionsImpl<S>::NullValuePtr() -> const DataDescriptionDefinitionInterface* { return (Hxx2::StaticMTable::_instance._DataDescriptionDefinitionInterface_NullValuePtr()); }
auto DataDescriptionDefinitionInterface::GetPtr() -> Ptr { return Ptr(this); }
auto DataDescriptionDefinitionInterface::GetPtr() const -> ConstPtr { return ConstPtr(this); }
#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT)
#ifdef MAXON_USE_REGISTER_FUNCTION
MAXON_STATIC_STORAGE(maxon::EntityUse, s_ui_maxon_DataDescriptionDefinitionInterface); \
MAXON_ATTRIBUTE_CONSTRUCTOR static void Register_s_ui_maxon_DataDescriptionDefinitionInterface() { new (s_ui_maxon_DataDescriptionDefinitionInterface) maxon::EntityUse(DataDescriptionDefinitionInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/datadescriptiondefinition.h", false); }
#else // !MAXON_USE_REGISTER_FUNCTION
static maxon::EntityUse s_ui_maxon_DataDescriptionDefinitionInterface(DataDescriptionDefinitionInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/datadescriptiondefinition.h", false);
#endif // MAXON_USE_REGISTER_FUNCTION
#endif
#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT)
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

