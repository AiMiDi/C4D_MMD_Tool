
#ifndef DOXYGEN

#if defined MAXON_COMPILER_GCC
	#pragma GCC diagnostic push
	#if MAXON_COMPILER_GCC >= 600
		#pragma GCC diagnostic ignored "-Wmisleading-indentation"
	#endif
#endif

#if 1

struct DataDescriptionInterface::MTable
{
	static MTable _instance;
	static MTable _unresolvedInstance;
	static const maxon::Char* const _ids;
	static maxon::Bool InitUnresolved(maxon::NonvirtualInterfaceReference::UnresolvedAssembler assembler, MTable* tbl);
	static const maxon::NULL_RETURN_TYPE _returnTypes[];
	static const maxon::Bool HAS_NONSTATIC = true;
	void (*_DataDescriptionInterface_Free) (const DataDescriptionInterface* object);
	DataDescriptionInterface* (*_DataDescriptionInterface_Alloc) (const maxon::SourceLocation& allocLocation);
	DataDescriptionInterface* (*_DataDescriptionInterface_Alloc_1) (const maxon::SourceLocation& allocLocation, const DataDescriptionInterface& object);
	DataDictionary (*_DataDescriptionInterface_GetInfo) (const DataDescriptionInterface* this_);
	Result<void> (*_DataDescriptionInterface_SetInfo) (DataDescriptionInterface* this_, const DataDictionary& info);
	Int (*_DataDescriptionInterface_GetEntryCount) (const DataDescriptionInterface* this_);
	Result<BaseArray<DataDictionary>> (*_DataDescriptionInterface_GetEntries) (const DataDescriptionInterface* this_);
	Result<DataDictionary> (*_DataDescriptionInterface_GetEntry) (const DataDescriptionInterface* this_, const InternedId& id);
	Result<Bool> (*_DataDescriptionInterface_SetEntry) (DataDescriptionInterface* this_, const DataDictionary& props, Bool merge);
	Result<void> (*_DataDescriptionInterface_EraseEntry) (DataDescriptionInterface* this_, const InternedId& id);
	void (*_DataDescriptionInterface_Reset) (DataDescriptionInterface* this_);
	Bool (*_DataDescriptionInterface_IsEqual) (const DataDescriptionInterface* this_, const DataDescriptionInterface* other, EQUALITY equality);
	COMPARERESULT (*_DataDescriptionInterface_Compare) (const DataDescriptionInterface* this_, const DataDescriptionInterface* other);
	UInt (*_DataDescriptionInterface_GetHashCode) (const DataDescriptionInterface* this_);
	String (*_DataDescriptionInterface_ToString) (const DataDescriptionInterface* this_, const FormatStatement* formatStatement);
	Result<void> (*_DataDescriptionInterface_DescribeIO) (const DataSerializeInterface& stream);
	template <typename IMPL> void Init()
	{
		_DataDescriptionInterface_Free = &IMPL::_DataDescriptionInterface_Free;
		_DataDescriptionInterface_Alloc = &IMPL::_DataDescriptionInterface_Alloc;
		_DataDescriptionInterface_Alloc_1 = &IMPL::_DataDescriptionInterface_Alloc_1;
		_DataDescriptionInterface_GetInfo = &IMPL::_DataDescriptionInterface_GetInfo;
		_DataDescriptionInterface_SetInfo = &IMPL::_DataDescriptionInterface_SetInfo;
		_DataDescriptionInterface_GetEntryCount = &IMPL::_DataDescriptionInterface_GetEntryCount;
		_DataDescriptionInterface_GetEntries = &IMPL::_DataDescriptionInterface_GetEntries;
		_DataDescriptionInterface_GetEntry = &IMPL::_DataDescriptionInterface_GetEntry;
		_DataDescriptionInterface_SetEntry = &IMPL::_DataDescriptionInterface_SetEntry;
		_DataDescriptionInterface_EraseEntry = &IMPL::_DataDescriptionInterface_EraseEntry;
		_DataDescriptionInterface_Reset = &IMPL::_DataDescriptionInterface_Reset;
		_DataDescriptionInterface_IsEqual = &IMPL::_DataDescriptionInterface_IsEqual;
		_DataDescriptionInterface_Compare = &IMPL::_DataDescriptionInterface_Compare;
		_DataDescriptionInterface_GetHashCode = &IMPL::_DataDescriptionInterface_GetHashCode;
		_DataDescriptionInterface_ToString = &IMPL::_DataDescriptionInterface_ToString;
		_DataDescriptionInterface_DescribeIO = &IMPL::_DataDescriptionInterface_DescribeIO;
	}
};

struct DataDescriptionInterface::Hxx2
{
	class Unresolved;
	template <typename C> class Wrapper
	{
	public:
	static void _DataDescriptionInterface_Free(const DataDescriptionInterface* object) { return C::Free(object); }
	static DataDescriptionInterface* _DataDescriptionInterface_Alloc(const maxon::SourceLocation& allocLocation) { return C::Alloc(allocLocation); }
	static DataDescriptionInterface* _DataDescriptionInterface_Alloc_1(const maxon::SourceLocation& allocLocation, const DataDescriptionInterface& object) { return C::Alloc(allocLocation, ((const C&) object)); }
	static DataDictionary _DataDescriptionInterface_GetInfo(const DataDescriptionInterface* this_) { return ((const C*) this_)->GetInfo(); }
	static Result<void> _DataDescriptionInterface_SetInfo(DataDescriptionInterface* this_, const DataDictionary& info) { return ((C*) this_)->SetInfo(info); }
	static Int _DataDescriptionInterface_GetEntryCount(const DataDescriptionInterface* this_) { return ((const C*) this_)->GetEntryCount(); }
	static Result<BaseArray<DataDictionary>> _DataDescriptionInterface_GetEntries(const DataDescriptionInterface* this_) { return ((const C*) this_)->GetEntries(); }
	static Result<DataDictionary> _DataDescriptionInterface_GetEntry(const DataDescriptionInterface* this_, const InternedId& id) { return ((const C*) this_)->GetEntry(id); }
	static Result<Bool> _DataDescriptionInterface_SetEntry(DataDescriptionInterface* this_, const DataDictionary& props, Bool merge) { return ((C*) this_)->SetEntry(props, merge); }
	static Result<void> _DataDescriptionInterface_EraseEntry(DataDescriptionInterface* this_, const InternedId& id) { return ((C*) this_)->EraseEntry(id); }
	static void _DataDescriptionInterface_Reset(DataDescriptionInterface* this_) { return ((C*) this_)->Reset(); }
	static Bool _DataDescriptionInterface_IsEqual(const DataDescriptionInterface* this_, const DataDescriptionInterface* other, EQUALITY equality) { return ((const C*) this_)->IsEqual(other, equality); }
	static COMPARERESULT _DataDescriptionInterface_Compare(const DataDescriptionInterface* this_, const DataDescriptionInterface* other) { return ((const C*) this_)->Compare(other); }
	static UInt _DataDescriptionInterface_GetHashCode(const DataDescriptionInterface* this_) { return ((const C*) this_)->GetHashCode(); }
	static String _DataDescriptionInterface_ToString(const DataDescriptionInterface* this_, const FormatStatement* formatStatement) { return ((const C*) this_)->ToString(formatStatement); }
	static Result<void> _DataDescriptionInterface_DescribeIO(const DataSerializeInterface& stream) { return C::DescribeIO(stream); }
	};

};
MAXON_ATTRIBUTE_FORCE_INLINE auto DataDescriptionInterface::Free(const DataDescriptionInterface* object) -> void
{
	return MTable::_instance._DataDescriptionInterface_Free(object);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto DataDescriptionInterface::Alloc(const maxon::SourceLocation& allocLocation) -> DataDescriptionInterface*
{
	return MTable::_instance._DataDescriptionInterface_Alloc(allocLocation);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto DataDescriptionInterface::Alloc(const maxon::SourceLocation& allocLocation, const DataDescriptionInterface& object) -> DataDescriptionInterface*
{
	return MTable::_instance._DataDescriptionInterface_Alloc_1(allocLocation, object);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto DataDescriptionInterface::GetInfo() const -> DataDictionary
{
	return MTable::_instance._DataDescriptionInterface_GetInfo(this);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto DataDescriptionInterface::SetInfo(const DataDictionary& info) -> Result<void>
{
	return MTable::_instance._DataDescriptionInterface_SetInfo(this, info);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto DataDescriptionInterface::GetEntryCount() const -> Int
{
	return MTable::_instance._DataDescriptionInterface_GetEntryCount(this);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto DataDescriptionInterface::GetEntries() const -> Result<BaseArray<DataDictionary>>
{
	return MTable::_instance._DataDescriptionInterface_GetEntries(this);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto DataDescriptionInterface::GetEntry(const InternedId& id) const -> Result<DataDictionary>
{
	return MTable::_instance._DataDescriptionInterface_GetEntry(this, id);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto DataDescriptionInterface::SetEntry(const DataDictionary& props, Bool merge) -> Result<Bool>
{
	return MTable::_instance._DataDescriptionInterface_SetEntry(this, props, merge);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto DataDescriptionInterface::EraseEntry(const InternedId& id) -> Result<void>
{
	return MTable::_instance._DataDescriptionInterface_EraseEntry(this, id);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto DataDescriptionInterface::Reset() -> void
{
	return MTable::_instance._DataDescriptionInterface_Reset(this);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto DataDescriptionInterface::IsEqual(const DataDescriptionInterface* other, EQUALITY equality) const -> Bool
{
	return MTable::_instance._DataDescriptionInterface_IsEqual(this, other, equality);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto DataDescriptionInterface::Compare(const DataDescriptionInterface* other) const -> COMPARERESULT
{
	return MTable::_instance._DataDescriptionInterface_Compare(this, other);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto DataDescriptionInterface::GetHashCode() const -> UInt
{
	return MTable::_instance._DataDescriptionInterface_GetHashCode(this);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto DataDescriptionInterface::ToString(const FormatStatement* formatStatement) const -> String
{
	return MTable::_instance._DataDescriptionInterface_ToString(this, formatStatement);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto DataDescriptionInterface::DescribeIO(const DataSerializeInterface& stream) -> Result<void>
{
	return MTable::_instance._DataDescriptionInterface_DescribeIO(stream);
}

auto DataDescriptionInterface::Hxx1::Reference::Create() -> maxon::ResultMemT<DataDescription>
{
	DataDescriptionInterface* res_ = DataDescriptionInterface::Alloc(MAXON_SOURCE_LOCATION);
	return DataDescription(maxon::ForwardResultPtr<DataDescriptionInterface>(res_));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto DataDescriptionInterface::Hxx1::ConstReferenceFunctionsImpl<S>::GetInfo() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<DataDictionary>, DataDictionary>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<DataDictionary>, DataDictionary>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const DataDescriptionInterface* o_ = (const DataDescriptionInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = DataDescriptionInterface::NullValuePtr(); if (!o_) return maxon::PrivateIncompleteNullReturnValue<DataDictionary>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } 
	return (MTable::_instance._DataDescriptionInterface_GetInfo(o_));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto DataDescriptionInterface::Hxx1::ReferenceFunctionsImpl<S>::SetInfo(const DataDictionary& info) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); DataDescriptionInterface* o_ = (DataDescriptionInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); 
	return (MTable::_instance._DataDescriptionInterface_SetInfo(o_, info));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto DataDescriptionInterface::Hxx1::COWReferenceFunctionsImpl<S>::SetInfo(const DataDictionary& info) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); DataDescriptionInterface* o_ = (DataDescriptionInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); 
	return (MTable::_instance._DataDescriptionInterface_SetInfo(o_, info));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto DataDescriptionInterface::Hxx1::ConstReferenceFunctionsImpl<S>::GetEntryCount() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const DataDescriptionInterface* o_ = (const DataDescriptionInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = DataDescriptionInterface::NullValuePtr(); if (!o_) return 0; } 
	return (MTable::_instance._DataDescriptionInterface_GetEntryCount(o_));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto DataDescriptionInterface::Hxx1::ConstReferenceFunctionsImpl<S>::GetEntries() const -> Result<BaseArray<DataDictionary>>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<BaseArray<DataDictionary>>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const DataDescriptionInterface* o_ = (const DataDescriptionInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = DataDescriptionInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (MTable::_instance._DataDescriptionInterface_GetEntries(o_));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto DataDescriptionInterface::Hxx1::ConstReferenceFunctionsImpl<S>::GetEntry(const InternedId& id) const -> Result<DataDictionary>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<DataDictionary>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const DataDescriptionInterface* o_ = (const DataDescriptionInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = DataDescriptionInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (MTable::_instance._DataDescriptionInterface_GetEntry(o_, id));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto DataDescriptionInterface::Hxx1::ReferenceFunctionsImpl<S>::SetEntry(const DataDictionary& props, Bool merge) const -> Result<Bool>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<Bool>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); DataDescriptionInterface* o_ = (DataDescriptionInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); 
	return (MTable::_instance._DataDescriptionInterface_SetEntry(o_, props, merge));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto DataDescriptionInterface::Hxx1::COWReferenceFunctionsImpl<S>::SetEntry(const DataDictionary& props, Bool merge) -> Result<Bool>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<Bool>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); DataDescriptionInterface* o_ = (DataDescriptionInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); 
	return (MTable::_instance._DataDescriptionInterface_SetEntry(o_, props, merge));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto DataDescriptionInterface::Hxx1::ReferenceFunctionsImpl<S>::EraseEntry(const InternedId& id) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); DataDescriptionInterface* o_ = (DataDescriptionInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); 
	return (MTable::_instance._DataDescriptionInterface_EraseEntry(o_, id));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto DataDescriptionInterface::Hxx1::COWReferenceFunctionsImpl<S>::EraseEntry(const InternedId& id) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); DataDescriptionInterface* o_ = (DataDescriptionInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); 
	return (MTable::_instance._DataDescriptionInterface_EraseEntry(o_, id));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto DataDescriptionInterface::Hxx1::ReferenceFunctionsImpl<S>::Reset() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); DataDescriptionInterface* o_ = (DataDescriptionInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) return maxon::PrivateLogNullptrError(); 
	MTable::_instance._DataDescriptionInterface_Reset(o_);
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto DataDescriptionInterface::Hxx1::COWReferenceFunctionsImpl<S>::Reset() -> typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), void, maxon::Result<void>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), void, maxon::Result<void>>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); DataDescriptionInterface* o_ = (DataDescriptionInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); 
	MTable::_instance._DataDescriptionInterface_Reset(o_);
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto DataDescriptionInterface::Hxx1::ConstReferenceFunctionsImpl<S>::IsEqual(const DataDescriptionInterface* other, EQUALITY equality) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const DataDescriptionInterface* o_ = (const DataDescriptionInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = DataDescriptionInterface::NullValuePtr(); if (!o_) return maxon::PrivateLogNullptrError(false); } 
	return (MTable::_instance._DataDescriptionInterface_IsEqual(o_, other, equality));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto DataDescriptionInterface::Hxx1::ConstReferenceFunctionsImpl<S>::Compare(const DataDescriptionInterface* other) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<COMPARERESULT>, COMPARERESULT>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<COMPARERESULT>, COMPARERESULT>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const DataDescriptionInterface* o_ = (const DataDescriptionInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = DataDescriptionInterface::NullValuePtr(); if (!o_) return maxon::PrivateIncompleteNullReturnValue<COMPARERESULT>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } 
	return (MTable::_instance._DataDescriptionInterface_Compare(o_, other));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto DataDescriptionInterface::Hxx1::ConstReferenceFunctionsImpl<S>::ToString(const FormatStatement* formatStatement) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<String>, String>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<String>, String>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const DataDescriptionInterface* o_ = (const DataDescriptionInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = DataDescriptionInterface::NullValuePtr(); if (!o_) return maxon::PrivateIncompleteNullReturnValue<String>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } 
	return (MTable::_instance._DataDescriptionInterface_ToString(o_, formatStatement));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto DataDescriptionInterface::Hxx1::ConstReferenceFunctionsImpl<S>::DescribeIO(const DataSerializeInterface& stream) -> Result<void> { return (MTable::_instance._DataDescriptionInterface_DescribeIO(stream)); }
#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT)
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

