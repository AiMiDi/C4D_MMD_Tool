
#ifndef DOXYGEN

#if defined MAXON_COMPILER_GCC
	#pragma GCC diagnostic push
	#if MAXON_COMPILER_GCC >= 600
		#pragma GCC diagnostic ignored "-Wmisleading-indentation"
	#endif
#endif

#if 1

struct DataDictionaryInterface::MTable
{
	static MTable _instance;
	static MTable _unresolvedInstance;
	static const maxon::Char* const _ids;
	static maxon::Bool InitUnresolved(maxon::NonvirtualInterfaceReference::UnresolvedAssembler assembler, MTable* tbl);
	static const maxon::NULL_RETURN_TYPE _returnTypes[];
	static const maxon::Bool HAS_NONSTATIC = true;
	void (*_DataDictionaryInterface_Free) (const DataDictionaryInterface* object);
	DataDictionaryInterface* (*_DataDictionaryInterface_Alloc) (const maxon::SourceLocation& allocLocation);
	DataDictionaryInterface* (*_DataDictionaryInterface_Alloc_1) (const maxon::SourceLocation& allocLocation, const DataDictionaryInterface& object);
	Result<void> (*_DataDictionaryInterface_SetData) (DataDictionaryInterface* this_, ForwardingDataPtr&& key, const Data& data);
	Result<void> (*_DataDictionaryInterface_SetData_1) (DataDictionaryInterface* this_, ForwardingDataPtr&& key, Data&& data);
	Result<Data> (*_DataDictionaryInterface_GetData) (const DataDictionaryInterface* this_, const ConstDataPtr& key);
	Result<void> (*_DataDictionaryInterface_EraseData) (DataDictionaryInterface* this_, const ConstDataPtr& key);
	void (*_DataDictionaryInterface_Reset) (DataDictionaryInterface* this_);
	Bool (*_DataDictionaryInterface_IsEmpty) (const DataDictionaryInterface* this_);
	String (*_DataDictionaryInterface_ToString) (const DataDictionaryInterface* this_, const FormatStatement* formatStatement);
	Result<void> (*_DataDictionaryInterface_DescribeIO) (const DataSerializeInterface& stream);
	Bool (*_DataDictionaryInterface_IsEqual) (const DataDictionaryInterface* this_, const DataDictionaryInterface* other, EQUALITY equality);
	UInt (*_DataDictionaryInterface_GetHashCode) (const DataDictionaryInterface* this_);
	void (*_DataDictionaryInterface_InitIterator) (const DataDictionaryInterface* this_, DataDictionaryIteratorInterface* iterator, Bool end);
	const Data* (*_DataDictionaryInterface_PrivateGetData) (const DataDictionaryInterface* this_, const ConstDataPtr& key);
	template <typename IMPL> void Init()
	{
		_DataDictionaryInterface_Free = &IMPL::_DataDictionaryInterface_Free;
		_DataDictionaryInterface_Alloc = &IMPL::_DataDictionaryInterface_Alloc;
		_DataDictionaryInterface_Alloc_1 = &IMPL::_DataDictionaryInterface_Alloc_1;
		_DataDictionaryInterface_SetData = &IMPL::_DataDictionaryInterface_SetData;
		_DataDictionaryInterface_SetData_1 = &IMPL::_DataDictionaryInterface_SetData_1;
		_DataDictionaryInterface_GetData = &IMPL::_DataDictionaryInterface_GetData;
		_DataDictionaryInterface_EraseData = &IMPL::_DataDictionaryInterface_EraseData;
		_DataDictionaryInterface_Reset = &IMPL::_DataDictionaryInterface_Reset;
		_DataDictionaryInterface_IsEmpty = &IMPL::_DataDictionaryInterface_IsEmpty;
		_DataDictionaryInterface_ToString = &IMPL::_DataDictionaryInterface_ToString;
		_DataDictionaryInterface_DescribeIO = &IMPL::_DataDictionaryInterface_DescribeIO;
		_DataDictionaryInterface_IsEqual = &IMPL::_DataDictionaryInterface_IsEqual;
		_DataDictionaryInterface_GetHashCode = &IMPL::_DataDictionaryInterface_GetHashCode;
		_DataDictionaryInterface_InitIterator = &IMPL::_DataDictionaryInterface_InitIterator;
		_DataDictionaryInterface_PrivateGetData = &IMPL::_DataDictionaryInterface_PrivateGetData;
	}
};

struct DataDictionaryInterface::Hxx2
{
	class Unresolved;
	template <typename C> class Wrapper
	{
	public:
	static void _DataDictionaryInterface_Free(const DataDictionaryInterface* object) { return C::Free(object); }
	static DataDictionaryInterface* _DataDictionaryInterface_Alloc(const maxon::SourceLocation& allocLocation) { return C::Alloc(allocLocation); }
	static DataDictionaryInterface* _DataDictionaryInterface_Alloc_1(const maxon::SourceLocation& allocLocation, const DataDictionaryInterface& object) { return C::Alloc(allocLocation, ((const C&) object)); }
	static Result<void> _DataDictionaryInterface_SetData(DataDictionaryInterface* this_, ForwardingDataPtr&& key, const Data& data) { return ((C*) this_)->SetData(std::forward<ForwardingDataPtr>(key), data); }
	static Result<void> _DataDictionaryInterface_SetData_1(DataDictionaryInterface* this_, ForwardingDataPtr&& key, Data&& data) { return ((C*) this_)->SetData(std::forward<ForwardingDataPtr>(key), std::forward<Data>(data)); }
	static Result<Data> _DataDictionaryInterface_GetData(const DataDictionaryInterface* this_, const ConstDataPtr& key) { return ((const C*) this_)->GetData(key); }
	static Result<void> _DataDictionaryInterface_EraseData(DataDictionaryInterface* this_, const ConstDataPtr& key) { return ((C*) this_)->EraseData(key); }
	static void _DataDictionaryInterface_Reset(DataDictionaryInterface* this_) { return ((C*) this_)->Reset(); }
	static Bool _DataDictionaryInterface_IsEmpty(const DataDictionaryInterface* this_) { return ((const C*) this_)->IsEmpty(); }
	static String _DataDictionaryInterface_ToString(const DataDictionaryInterface* this_, const FormatStatement* formatStatement) { return ((const C*) this_)->ToString(formatStatement); }
	static Result<void> _DataDictionaryInterface_DescribeIO(const DataSerializeInterface& stream) { return C::DescribeIO(stream); }
	static Bool _DataDictionaryInterface_IsEqual(const DataDictionaryInterface* this_, const DataDictionaryInterface* other, EQUALITY equality) { return ((const C*) this_)->IsEqual(other, equality); }
	static UInt _DataDictionaryInterface_GetHashCode(const DataDictionaryInterface* this_) { return ((const C*) this_)->GetHashCode(); }
	static void _DataDictionaryInterface_InitIterator(const DataDictionaryInterface* this_, DataDictionaryIteratorInterface* iterator, Bool end) { return ((const C*) this_)->InitIterator(iterator, end); }
	static const Data* _DataDictionaryInterface_PrivateGetData(const DataDictionaryInterface* this_, const ConstDataPtr& key) { return ((const C*) this_)->PrivateGetData(key); }
	};

};
MAXON_ATTRIBUTE_FORCE_INLINE auto DataDictionaryInterface::Free(const DataDictionaryInterface* object) -> void
{
	return MTable::_instance._DataDictionaryInterface_Free(object);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto DataDictionaryInterface::Alloc(const maxon::SourceLocation& allocLocation) -> DataDictionaryInterface*
{
	return MTable::_instance._DataDictionaryInterface_Alloc(allocLocation);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto DataDictionaryInterface::Alloc(const maxon::SourceLocation& allocLocation, const DataDictionaryInterface& object) -> DataDictionaryInterface*
{
	return MTable::_instance._DataDictionaryInterface_Alloc_1(allocLocation, object);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto DataDictionaryInterface::SetData(ForwardingDataPtr&& key, const Data& data) -> Result<void>
{
	return MTable::_instance._DataDictionaryInterface_SetData(this, std::forward<ForwardingDataPtr>(key), data);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto DataDictionaryInterface::SetData(ForwardingDataPtr&& key, Data&& data) -> Result<void>
{
	return MTable::_instance._DataDictionaryInterface_SetData_1(this, std::forward<ForwardingDataPtr>(key), std::forward<Data>(data));
}
MAXON_ATTRIBUTE_FORCE_INLINE auto DataDictionaryInterface::GetData(const ConstDataPtr& key) const -> Result<Data>
{
	return MTable::_instance._DataDictionaryInterface_GetData(this, key);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto DataDictionaryInterface::EraseData(const ConstDataPtr& key) -> Result<void>
{
	return MTable::_instance._DataDictionaryInterface_EraseData(this, key);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto DataDictionaryInterface::Reset() -> void
{
	return MTable::_instance._DataDictionaryInterface_Reset(this);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto DataDictionaryInterface::IsEmpty() const -> Bool
{
	return MTable::_instance._DataDictionaryInterface_IsEmpty(this);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto DataDictionaryInterface::ToString(const FormatStatement* formatStatement) const -> String
{
	return MTable::_instance._DataDictionaryInterface_ToString(this, formatStatement);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto DataDictionaryInterface::DescribeIO(const DataSerializeInterface& stream) -> Result<void>
{
	return MTable::_instance._DataDictionaryInterface_DescribeIO(stream);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto DataDictionaryInterface::IsEqual(const DataDictionaryInterface* other, EQUALITY equality) const -> Bool
{
	return MTable::_instance._DataDictionaryInterface_IsEqual(this, other, equality);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto DataDictionaryInterface::GetHashCode() const -> UInt
{
	return MTable::_instance._DataDictionaryInterface_GetHashCode(this);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto DataDictionaryInterface::InitIterator(DataDictionaryIteratorInterface* iterator, Bool end) const -> void
{
	return MTable::_instance._DataDictionaryInterface_InitIterator(this, iterator, end);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto DataDictionaryInterface::PrivateGetData(const ConstDataPtr& key) const -> const Data*
{
	return MTable::_instance._DataDictionaryInterface_PrivateGetData(this, key);
}

auto DataDictionaryInterface::Hxx1::Reference::Create() -> maxon::ResultMemT<DataDictionary>
{
	DataDictionaryInterface* res_ = DataDictionaryInterface::Alloc(MAXON_SOURCE_LOCATION);
	return DataDictionary(maxon::ForwardResultPtr<DataDictionaryInterface>(res_));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto DataDictionaryInterface::Hxx1::ReferenceFunctionsImpl<S>::SetData(ForwardingDataPtr&& key, const Data& data) const -> maxon::Result<DOXYGEN_SWITCH(maxon::RefMemberType<S const>, S)>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), true, maxon::Result<DOXYGEN_SWITCH(maxon::RefMemberType<S const>, S)>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); DataDictionaryInterface* o_ = (DataDictionaryInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR)); 
	auto res_ = MTable::_instance._DataDictionaryInterface_SetData(o_, std::forward<ForwardingDataPtr>(key), data);
	return ReturnHelper::Return(this, res_.GetErrorStorage());
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto DataDictionaryInterface::Hxx1::COWReferenceFunctionsImpl<S>::SetData(ForwardingDataPtr&& key, const Data& data) -> maxon::Result<DOXYGEN_SWITCH(maxon::RefMemberType<S>, S)>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), true, maxon::Result<DOXYGEN_SWITCH(maxon::RefMemberType<S>, S)>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); DataDictionaryInterface* o_ = (DataDictionaryInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); 
	auto res_ = MTable::_instance._DataDictionaryInterface_SetData(o_, std::forward<ForwardingDataPtr>(key), data);
	return ReturnHelper::Return(this, res_.GetErrorStorage());
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto DataDictionaryInterface::Hxx1::ReferenceFunctionsImpl<S>::SetData(ForwardingDataPtr&& key, Data&& data) const -> maxon::Result<DOXYGEN_SWITCH(maxon::RefMemberType<S const>, S)>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), true, maxon::Result<DOXYGEN_SWITCH(maxon::RefMemberType<S const>, S)>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); DataDictionaryInterface* o_ = (DataDictionaryInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR)); 
	auto res_ = MTable::_instance._DataDictionaryInterface_SetData_1(o_, std::forward<ForwardingDataPtr>(key), std::forward<Data>(data));
	return ReturnHelper::Return(this, res_.GetErrorStorage());
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto DataDictionaryInterface::Hxx1::COWReferenceFunctionsImpl<S>::SetData(ForwardingDataPtr&& key, Data&& data) -> maxon::Result<DOXYGEN_SWITCH(maxon::RefMemberType<S>, S)>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), true, maxon::Result<DOXYGEN_SWITCH(maxon::RefMemberType<S>, S)>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); DataDictionaryInterface* o_ = (DataDictionaryInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); 
	auto res_ = MTable::_instance._DataDictionaryInterface_SetData_1(o_, std::forward<ForwardingDataPtr>(key), std::forward<Data>(data));
	return ReturnHelper::Return(this, res_.GetErrorStorage());
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto DataDictionaryInterface::Hxx1::ConstReferenceFunctionsImpl<S>::GetData(const ConstDataPtr& key) const -> Result<Data>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<Data>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const DataDictionaryInterface* o_ = (const DataDictionaryInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = DataDictionaryInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (MTable::_instance._DataDictionaryInterface_GetData(o_, key));
}
template <typename S> template <typename KEY> MAXON_ATTRIBUTE_FORCE_INLINE auto DataDictionaryInterface::Hxx1::ConstReferenceFunctionsImpl<S>::Existing(KEY&& key) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const DataDictionaryInterface* o_ = (const DataDictionaryInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = DataDictionaryInterface::NullValuePtr(); if (!o_) return maxon::PrivateLogNullptrError(false); } 
	return (o_->Existing<KEY>(std::forward<KEY>(key)));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto DataDictionaryInterface::Hxx1::ReferenceFunctionsImpl<S>::EraseData(const ConstDataPtr& key) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); DataDictionaryInterface* o_ = (DataDictionaryInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); 
	return (MTable::_instance._DataDictionaryInterface_EraseData(o_, key));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto DataDictionaryInterface::Hxx1::COWReferenceFunctionsImpl<S>::EraseData(const ConstDataPtr& key) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); DataDictionaryInterface* o_ = (DataDictionaryInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); 
	return (MTable::_instance._DataDictionaryInterface_EraseData(o_, key));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto DataDictionaryInterface::Hxx1::ReferenceFunctionsImpl<S>::Reset() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); DataDictionaryInterface* o_ = (DataDictionaryInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) return maxon::PrivateLogNullptrError(); 
	MTable::_instance._DataDictionaryInterface_Reset(o_);
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto DataDictionaryInterface::Hxx1::COWReferenceFunctionsImpl<S>::Reset() -> typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), void, maxon::Result<void>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), void, maxon::Result<void>>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); DataDictionaryInterface* o_ = (DataDictionaryInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); 
	MTable::_instance._DataDictionaryInterface_Reset(o_);
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto DataDictionaryInterface::Hxx1::ConstReferenceFunctionsImpl<S>::IsEmpty() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const DataDictionaryInterface* o_ = (const DataDictionaryInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = DataDictionaryInterface::NullValuePtr(); if (!o_) return maxon::PrivateLogNullptrError(false); } 
	return (MTable::_instance._DataDictionaryInterface_IsEmpty(o_));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto DataDictionaryInterface::Hxx1::ConstReferenceFunctionsImpl<S>::IsPopulated() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const DataDictionaryInterface* o_ = (const DataDictionaryInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = DataDictionaryInterface::NullValuePtr(); if (!o_) return maxon::PrivateLogNullptrError(false); } 
	return (o_->IsPopulated());
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto DataDictionaryInterface::Hxx1::ConstReferenceFunctionsImpl<S>::ToString(const FormatStatement* formatStatement) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<String>, String>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<String>, String>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const DataDictionaryInterface* o_ = (const DataDictionaryInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = DataDictionaryInterface::NullValuePtr(); if (!o_) return maxon::PrivateIncompleteNullReturnValue<String>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } 
	return (MTable::_instance._DataDictionaryInterface_ToString(o_, formatStatement));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto DataDictionaryInterface::Hxx1::ConstReferenceFunctionsImpl<S>::DescribeIO(const DataSerializeInterface& stream) -> Result<void> { return (MTable::_instance._DataDictionaryInterface_DescribeIO(stream)); }
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto DataDictionaryInterface::Hxx1::ConstReferenceFunctionsImpl<S>::IsEqual(const DataDictionaryInterface* other, EQUALITY equality) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const DataDictionaryInterface* o_ = (const DataDictionaryInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = DataDictionaryInterface::NullValuePtr(); if (!o_) return maxon::PrivateLogNullptrError(false); } 
	return (MTable::_instance._DataDictionaryInterface_IsEqual(o_, other, equality));
}
template <typename S> template <typename T, typename KEY> MAXON_ATTRIBUTE_FORCE_INLINE auto DataDictionaryInterface::Hxx1::ConstReferenceFunctionsImpl<S>::Get(KEY&& key) const -> Result<typename std::conditional<IsFidClass<KEY>::value, typename IsFidClass<KEY>::type, T>::type>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<typename std::conditional<IsFidClass<KEY>::value, typename IsFidClass<KEY>::type, T>::type>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const DataDictionaryInterface* o_ = (const DataDictionaryInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = DataDictionaryInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (o_->Get<T, KEY>(std::forward<KEY>(key)));
}
template <typename S> template <typename T, typename KEY> MAXON_ATTRIBUTE_FORCE_INLINE auto DataDictionaryInterface::Hxx1::ConstReferenceFunctionsImpl<S>::Get(KEY&& key, const T& defaultValue) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<typename std::conditional<IsFidClass<KEY>::value, typename IsFidClass<KEY>::type, T>::type>, typename std::conditional<IsFidClass<KEY>::value, typename IsFidClass<KEY>::type, T>::type>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<typename std::conditional<IsFidClass<KEY>::value, typename IsFidClass<KEY>::type, T>::type>, typename std::conditional<IsFidClass<KEY>::value, typename IsFidClass<KEY>::type, T>::type>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const DataDictionaryInterface* o_ = (const DataDictionaryInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = DataDictionaryInterface::NullValuePtr(); if (!o_) return maxon::PrivateNullReturnValue<typename std::conditional<IsFidClass<KEY>::value, typename IsFidClass<KEY>::type, T>::type>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } 
	return (o_->Get<T, KEY>(std::forward<KEY>(key), defaultValue));
}
template <typename S> template <typename T, typename KEY> MAXON_ATTRIBUTE_FORCE_INLINE auto DataDictionaryInterface::Hxx1::ConstReferenceFunctionsImpl<S>::Get(KEY&& key, T&& defaultValue) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<typename std::conditional<IsFidClass<KEY>::value, typename IsFidClass<KEY>::type, T>::type>, typename std::conditional<IsFidClass<KEY>::value, typename IsFidClass<KEY>::type, T>::type>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<typename std::conditional<IsFidClass<KEY>::value, typename IsFidClass<KEY>::type, T>::type>, typename std::conditional<IsFidClass<KEY>::value, typename IsFidClass<KEY>::type, T>::type>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const DataDictionaryInterface* o_ = (const DataDictionaryInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = DataDictionaryInterface::NullValuePtr(); if (!o_) return maxon::PrivateNullReturnValue<typename std::conditional<IsFidClass<KEY>::value, typename IsFidClass<KEY>::type, T>::type>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } 
	return (o_->Get<T, KEY>(std::forward<KEY>(key), std::forward<T>(defaultValue)));
}
template <typename S> template <typename KEY> MAXON_ATTRIBUTE_FORCE_INLINE auto DataDictionaryInterface::Hxx1::ConstReferenceFunctionsImpl<S>::GetOrDefault(KEY&& key) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<typename IsFidClass<KEY>::type>, typename IsFidClass<KEY>::type>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<typename IsFidClass<KEY>::type>, typename IsFidClass<KEY>::type>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const DataDictionaryInterface* o_ = (const DataDictionaryInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = DataDictionaryInterface::NullValuePtr(); if (!o_) return maxon::PrivateNullReturnValue<typename IsFidClass<KEY>::type>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } 
	return (o_->GetOrDefault<KEY>(std::forward<KEY>(key)));
}
template <typename S> template <typename T, typename KEY> MAXON_ATTRIBUTE_FORCE_INLINE auto DataDictionaryInterface::Hxx1::ReferenceFunctionsImpl<S>::Set(KEY&& key, T&& data) const -> maxon::Result<DOXYGEN_SWITCH(maxon::RefMemberType<S const>, S)>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), true, maxon::Result<DOXYGEN_SWITCH(maxon::RefMemberType<S const>, S)>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); DataDictionaryInterface* o_ = (DataDictionaryInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR)); 
	auto res_ = o_->Set<T, KEY>(std::forward<KEY>(key), std::forward<T>(data));
	return ReturnHelper::Return(this, res_.GetErrorStorage());
}
template <typename S> template <typename T, typename KEY> MAXON_ATTRIBUTE_FORCE_INLINE auto DataDictionaryInterface::Hxx1::COWReferenceFunctionsImpl<S>::Set(KEY&& key, T&& data) -> maxon::Result<DOXYGEN_SWITCH(maxon::RefMemberType<S>, S)>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), true, maxon::Result<DOXYGEN_SWITCH(maxon::RefMemberType<S>, S)>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); DataDictionaryInterface* o_ = (DataDictionaryInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); 
	auto res_ = o_->Set<T, KEY>(std::forward<KEY>(key), std::forward<T>(data));
	return ReturnHelper::Return(this, res_.GetErrorStorage());
}
template <typename S> template <typename KEY> MAXON_ATTRIBUTE_FORCE_INLINE auto DataDictionaryInterface::Hxx1::ReferenceFunctionsImpl<S>::Erase(KEY&& key) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); DataDictionaryInterface* o_ = (DataDictionaryInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); 
	return (o_->Erase<KEY>(std::forward<KEY>(key)));
}
template <typename S> template <typename KEY> MAXON_ATTRIBUTE_FORCE_INLINE auto DataDictionaryInterface::Hxx1::COWReferenceFunctionsImpl<S>::Erase(KEY&& key) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); DataDictionaryInterface* o_ = (DataDictionaryInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); 
	return (o_->Erase<KEY>(std::forward<KEY>(key)));
}
template <typename S> template <typename T, typename KEY> MAXON_ATTRIBUTE_FORCE_INLINE auto DataDictionaryInterface::Hxx1::ConstReferenceFunctionsImpl<S>::GetCopy(KEY&& key, T& dst) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const DataDictionaryInterface* o_ = (const DataDictionaryInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = DataDictionaryInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (o_->GetCopy<T, KEY>(std::forward<KEY>(key), dst));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto DataDictionaryInterface::Hxx1::ConstReferenceFunctionsImpl<S>::InitIterator(DataDictionaryIteratorInterface* iterator, Bool end) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const DataDictionaryInterface* o_ = (const DataDictionaryInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = DataDictionaryInterface::NullValuePtr(); if (!o_) return maxon::PrivateLogNullptrError(); } 
	MTable::_instance._DataDictionaryInterface_InitIterator(o_, iterator, end);
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto DataDictionaryInterface::Hxx1::ConstReferenceFunctionsImpl<S>::Begin() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<ConstIterator>, ConstIterator>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<ConstIterator>, ConstIterator>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const DataDictionaryInterface* o_ = (const DataDictionaryInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = DataDictionaryInterface::NullValuePtr(); if (!o_) return maxon::PrivateIncompleteNullReturnValue<ConstIterator>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } 
	return (o_->Begin());
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto DataDictionaryInterface::Hxx1::ConstReferenceFunctionsImpl<S>::End() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<ConstIterator>, ConstIterator>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<ConstIterator>, ConstIterator>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const DataDictionaryInterface* o_ = (const DataDictionaryInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = DataDictionaryInterface::NullValuePtr(); if (!o_) return maxon::PrivateIncompleteNullReturnValue<ConstIterator>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } 
	return (o_->End());
}
#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT)
#ifdef MAXON_USE_REGISTER_FUNCTION
MAXON_STATIC_STORAGE(maxon::EntityUse, s_ui_maxon_DataDictionaryInterface); \
MAXON_ATTRIBUTE_CONSTRUCTOR static void Register_s_ui_maxon_DataDictionaryInterface() { new (s_ui_maxon_DataDictionaryInterface) maxon::EntityUse(DataDictionaryInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/datadictionary.h", false); }
#else // !MAXON_USE_REGISTER_FUNCTION
static maxon::EntityUse s_ui_maxon_DataDictionaryInterface(DataDictionaryInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/datadictionary.h", false);
#endif // MAXON_USE_REGISTER_FUNCTION
#endif
#if (defined MAXON_TARGET_WINDOWS) && (defined MAXON_TARGET_DEBUG)
#endif
#endif

#ifdef MAXON_COMPILER_GCC
	#pragma GCC diagnostic pop
#endif

#endif

