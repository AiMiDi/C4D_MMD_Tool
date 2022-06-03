
#ifndef DOXYGEN

#if defined MAXON_COMPILER_GCC
	#pragma GCC diagnostic push
	#if MAXON_COMPILER_GCC >= 600
		#pragma GCC diagnostic ignored "-Wmisleading-indentation"
	#endif
#endif

#if 1
constexpr const maxon::Char* DataDictionaryInterface::PrivateGetCppName() { return "maxon::DataDictionary"; }

struct DataDictionaryInterface::MTable
{
	static MTable _instance;
	static MTable _unresolvedInstance;
	static const maxon::Char* const _ids;
	static maxon::Bool InitUnresolved(maxon::NonvirtualInterfaceReference::UnresolvedAssembler assembler, MTable* tbl);
	static const maxon::NULL_RETURN_TYPE _returnTypes[];
	static const maxon::Bool HAS_NONSTATIC = true;
	void (*DataDictionaryInterface_Free) (const DataDictionaryInterface* object);
	DataDictionaryInterface* (*DataDictionaryInterface_Alloc) (const maxon::SourceLocation& allocLocation);
	DataDictionaryInterface* (*DataDictionaryInterface_Alloc_1) (const maxon::SourceLocation& allocLocation, const DataDictionaryInterface& object);
	Result<void> (*DataDictionaryInterface_SetData) (DataDictionaryInterface* this_, ForwardingDataPtr&& key, const Data& data);
	Result<void> (*DataDictionaryInterface_SetData_1) (DataDictionaryInterface* this_, ForwardingDataPtr&& key, Data&& data);
	Result<void> (*DataDictionaryInterface_SetData_2) (DataDictionaryInterface* this_, ForwardingDataPtr&& key, ForwardingDataPtr&& data);
	Result<Data> (*DataDictionaryInterface_GetData) (const DataDictionaryInterface* this_, const ConstDataPtr& key);
	Result<void> (*DataDictionaryInterface_EraseData) (DataDictionaryInterface* this_, const ConstDataPtr& key);
	void (*DataDictionaryInterface_Reset) (DataDictionaryInterface* this_);
	Bool (*DataDictionaryInterface_IsEmpty) (const DataDictionaryInterface* this_);
	Int (*DataDictionaryInterface_GetCount) (const DataDictionaryInterface* this_);
	String (*DataDictionaryInterface_ToString) (const DataDictionaryInterface* this_, const FormatStatement* formatStatement);
	Result<void> (*DataDictionaryInterface_DescribeIO) (const DataSerializeInterface& stream);
	Bool (*DataDictionaryInterface_IsEqual) (const DataDictionaryInterface* this_, const DataDictionaryInterface* other, EQUALITY equality);
	HashInt (*DataDictionaryInterface_GetHashCode) (const DataDictionaryInterface* this_);
	void (*DataDictionaryInterface_InitIterator) (const DataDictionaryInterface* this_, DataDictionaryIteratorInterface* iterator, Bool end);
	const Data* (*DataDictionaryInterface_PrivateGetData) (const DataDictionaryInterface* this_, const ConstDataPtr& key);
	template <typename IMPL> void Init()
	{
		DataDictionaryInterface_Free = &IMPL::DataDictionaryInterface_Free;
		DataDictionaryInterface_Alloc = &IMPL::DataDictionaryInterface_Alloc;
		DataDictionaryInterface_Alloc_1 = &IMPL::DataDictionaryInterface_Alloc_1;
		DataDictionaryInterface_SetData = &IMPL::DataDictionaryInterface_SetData;
		DataDictionaryInterface_SetData_1 = &IMPL::DataDictionaryInterface_SetData_1;
		DataDictionaryInterface_SetData_2 = &IMPL::DataDictionaryInterface_SetData_2;
		DataDictionaryInterface_GetData = &IMPL::DataDictionaryInterface_GetData;
		DataDictionaryInterface_EraseData = &IMPL::DataDictionaryInterface_EraseData;
		DataDictionaryInterface_Reset = &IMPL::DataDictionaryInterface_Reset;
		DataDictionaryInterface_IsEmpty = &IMPL::DataDictionaryInterface_IsEmpty;
		DataDictionaryInterface_GetCount = &IMPL::DataDictionaryInterface_GetCount;
		DataDictionaryInterface_ToString = &IMPL::DataDictionaryInterface_ToString;
		DataDictionaryInterface_DescribeIO = &IMPL::DataDictionaryInterface_DescribeIO;
		DataDictionaryInterface_IsEqual = &IMPL::DataDictionaryInterface_IsEqual;
		DataDictionaryInterface_GetHashCode = &IMPL::DataDictionaryInterface_GetHashCode;
		DataDictionaryInterface_InitIterator = &IMPL::DataDictionaryInterface_InitIterator;
		DataDictionaryInterface_PrivateGetData = &IMPL::DataDictionaryInterface_PrivateGetData;
	}
};

struct DataDictionaryInterface::Hxx2
{
	class Unresolved;
	template <typename C> class Wrapper
	{
	public:
		static void DataDictionaryInterface_Free(const DataDictionaryInterface* object) { return C::Free(object); }
		static DataDictionaryInterface* DataDictionaryInterface_Alloc(const maxon::SourceLocation& allocLocation) { return C::Alloc(allocLocation); }
		static DataDictionaryInterface* DataDictionaryInterface_Alloc_1(const maxon::SourceLocation& allocLocation, const DataDictionaryInterface& object) { return C::Alloc(allocLocation, ((const C&) object)); }
		static Result<void> DataDictionaryInterface_SetData(DataDictionaryInterface* this_, ForwardingDataPtr&& key, const Data& data) { return C::Get(this_)->SetData(std::forward<ForwardingDataPtr>(key), data); }
		static Result<void> DataDictionaryInterface_SetData_1(DataDictionaryInterface* this_, ForwardingDataPtr&& key, Data&& data) { return C::Get(this_)->SetData(std::forward<ForwardingDataPtr>(key), std::forward<Data>(data)); }
		static Result<void> DataDictionaryInterface_SetData_2(DataDictionaryInterface* this_, ForwardingDataPtr&& key, ForwardingDataPtr&& data) { return C::Get(this_)->SetData(std::forward<ForwardingDataPtr>(key), std::forward<ForwardingDataPtr>(data)); }
		static Result<Data> DataDictionaryInterface_GetData(const DataDictionaryInterface* this_, const ConstDataPtr& key) { return C::Get(this_)->GetData(key); }
		static Result<void> DataDictionaryInterface_EraseData(DataDictionaryInterface* this_, const ConstDataPtr& key) { return C::Get(this_)->EraseData(key); }
		static void DataDictionaryInterface_Reset(DataDictionaryInterface* this_) { return C::Get(this_)->Reset(); }
		static Bool DataDictionaryInterface_IsEmpty(const DataDictionaryInterface* this_) { return C::Get(this_)->IsEmpty(); }
		static Int DataDictionaryInterface_GetCount(const DataDictionaryInterface* this_) { return C::Get(this_)->GetCount(); }
		static String DataDictionaryInterface_ToString(const DataDictionaryInterface* this_, const FormatStatement* formatStatement) { return C::Get(this_)->ToString(formatStatement); }
		static Result<void> DataDictionaryInterface_DescribeIO(const DataSerializeInterface& stream) { return C::DescribeIO(stream); }
		static Bool DataDictionaryInterface_IsEqual(const DataDictionaryInterface* this_, const DataDictionaryInterface* other, EQUALITY equality) { return C::Get(this_)->IsEqual(other, equality); }
		static HashInt DataDictionaryInterface_GetHashCode(const DataDictionaryInterface* this_) { return C::Get(this_)->GetHashCode(); }
		static void DataDictionaryInterface_InitIterator(const DataDictionaryInterface* this_, DataDictionaryIteratorInterface* iterator, Bool end) { return C::Get(this_)->InitIterator(iterator, end); }
		static const Data* DataDictionaryInterface_PrivateGetData(const DataDictionaryInterface* this_, const ConstDataPtr& key) { return C::Get(this_)->PrivateGetData(key); }
	};

};
MAXON_ATTRIBUTE_FORCE_INLINE auto DataDictionaryInterface::Free(const DataDictionaryInterface* object) -> void
{
	return MTable::_instance.DataDictionaryInterface_Free(object);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto DataDictionaryInterface::Alloc(const maxon::SourceLocation& allocLocation) -> DataDictionaryInterface*
{
	return MTable::_instance.DataDictionaryInterface_Alloc(allocLocation);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto DataDictionaryInterface::Alloc(const maxon::SourceLocation& allocLocation, const DataDictionaryInterface& object) -> DataDictionaryInterface*
{
	return MTable::_instance.DataDictionaryInterface_Alloc_1(allocLocation, object);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto DataDictionaryInterface::SetData(ForwardingDataPtr&& key, const Data& data) -> Result<void>
{
	return MTable::_instance.DataDictionaryInterface_SetData(this, std::forward<ForwardingDataPtr>(key), data);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto DataDictionaryInterface::SetData(ForwardingDataPtr&& key, Data&& data) -> Result<void>
{
	return MTable::_instance.DataDictionaryInterface_SetData_1(this, std::forward<ForwardingDataPtr>(key), std::forward<Data>(data));
}
MAXON_ATTRIBUTE_FORCE_INLINE auto DataDictionaryInterface::SetData(ForwardingDataPtr&& key, ForwardingDataPtr&& data) -> Result<void>
{
	return MTable::_instance.DataDictionaryInterface_SetData_2(this, std::forward<ForwardingDataPtr>(key), std::forward<ForwardingDataPtr>(data));
}
MAXON_ATTRIBUTE_FORCE_INLINE auto DataDictionaryInterface::GetData(const ConstDataPtr& key) const -> Result<Data>
{
	return MTable::_instance.DataDictionaryInterface_GetData(this, key);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto DataDictionaryInterface::EraseData(const ConstDataPtr& key) -> Result<void>
{
	return MTable::_instance.DataDictionaryInterface_EraseData(this, key);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto DataDictionaryInterface::Reset() -> void
{
	return MTable::_instance.DataDictionaryInterface_Reset(this);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto DataDictionaryInterface::IsEmpty() const -> Bool
{
	return MTable::_instance.DataDictionaryInterface_IsEmpty(this);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto DataDictionaryInterface::GetCount() const -> Int
{
	return MTable::_instance.DataDictionaryInterface_GetCount(this);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto DataDictionaryInterface::ToString(const FormatStatement* formatStatement) const -> String
{
	return MTable::_instance.DataDictionaryInterface_ToString(this, formatStatement);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto DataDictionaryInterface::DescribeIO(const DataSerializeInterface& stream) -> Result<void>
{
	return MTable::_instance.DataDictionaryInterface_DescribeIO(stream);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto DataDictionaryInterface::IsEqual(const DataDictionaryInterface* other, EQUALITY equality) const -> Bool
{
	return MTable::_instance.DataDictionaryInterface_IsEqual(this, other, equality);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto DataDictionaryInterface::GetHashCode() const -> HashInt
{
	return MTable::_instance.DataDictionaryInterface_GetHashCode(this);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto DataDictionaryInterface::InitIterator(DataDictionaryIteratorInterface* iterator, Bool end) const -> void
{
	return MTable::_instance.DataDictionaryInterface_InitIterator(this, iterator, end);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto DataDictionaryInterface::PrivateGetData(const ConstDataPtr& key) const -> const Data*
{
	return MTable::_instance.DataDictionaryInterface_PrivateGetData(this, key);
}

auto DataDictionaryInterface::Hxx1::Reference::Create() -> maxon::ResultMemT<DataDictionary>
{
	DataDictionaryInterface* res_ = DataDictionaryInterface::Alloc(MAXON_SOURCE_LOCATION);
	return DataDictionary(maxon::ForwardResultPtr<DataDictionaryInterface>(res_));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto DataDictionaryInterface::Hxx1::Fn<S>::SetData(ForwardingDataPtr&& key, const Data& data) const -> maxon::Result<DOXYGEN_SWITCH(maxon::RefMemberType<S const>, S)>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), true, maxon::Result<DOXYGEN_SWITCH(maxon::RefMemberType<S const>, S)>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); DataDictionaryInterface* o_ = (DataDictionaryInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR)); } 
	auto res_ = MTable::_instance.DataDictionaryInterface_SetData(o_, std::forward<ForwardingDataPtr>(key), data);
	return ReturnHelper::Return(this, res_.GetErrorStorage());
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto DataDictionaryInterface::Hxx1::COWFn<S>::SetData(ForwardingDataPtr&& key, const Data& data) -> maxon::Result<DOXYGEN_SWITCH(maxon::RefMemberType<S>, S)>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), true, maxon::Result<DOXYGEN_SWITCH(maxon::RefMemberType<S>, S)>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); DataDictionaryInterface* o_ = (DataDictionaryInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } 
	auto res_ = MTable::_instance.DataDictionaryInterface_SetData(o_, std::forward<ForwardingDataPtr>(key), data);
	return ReturnHelper::Return(this, res_.GetErrorStorage());
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto DataDictionaryInterface::Hxx1::Fn<S>::SetData(ForwardingDataPtr&& key, Data&& data) const -> maxon::Result<DOXYGEN_SWITCH(maxon::RefMemberType<S const>, S)>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), true, maxon::Result<DOXYGEN_SWITCH(maxon::RefMemberType<S const>, S)>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); DataDictionaryInterface* o_ = (DataDictionaryInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR)); } 
	auto res_ = MTable::_instance.DataDictionaryInterface_SetData_1(o_, std::forward<ForwardingDataPtr>(key), std::forward<Data>(data));
	return ReturnHelper::Return(this, res_.GetErrorStorage());
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto DataDictionaryInterface::Hxx1::COWFn<S>::SetData(ForwardingDataPtr&& key, Data&& data) -> maxon::Result<DOXYGEN_SWITCH(maxon::RefMemberType<S>, S)>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), true, maxon::Result<DOXYGEN_SWITCH(maxon::RefMemberType<S>, S)>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); DataDictionaryInterface* o_ = (DataDictionaryInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } 
	auto res_ = MTable::_instance.DataDictionaryInterface_SetData_1(o_, std::forward<ForwardingDataPtr>(key), std::forward<Data>(data));
	return ReturnHelper::Return(this, res_.GetErrorStorage());
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto DataDictionaryInterface::Hxx1::Fn<S>::SetData(ForwardingDataPtr&& key, ForwardingDataPtr&& data) const -> maxon::Result<DOXYGEN_SWITCH(maxon::RefMemberType<S const>, S)>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), true, maxon::Result<DOXYGEN_SWITCH(maxon::RefMemberType<S const>, S)>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); DataDictionaryInterface* o_ = (DataDictionaryInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR)); } 
	auto res_ = MTable::_instance.DataDictionaryInterface_SetData_2(o_, std::forward<ForwardingDataPtr>(key), std::forward<ForwardingDataPtr>(data));
	return ReturnHelper::Return(this, res_.GetErrorStorage());
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto DataDictionaryInterface::Hxx1::COWFn<S>::SetData(ForwardingDataPtr&& key, ForwardingDataPtr&& data) -> maxon::Result<DOXYGEN_SWITCH(maxon::RefMemberType<S>, S)>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), true, maxon::Result<DOXYGEN_SWITCH(maxon::RefMemberType<S>, S)>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); DataDictionaryInterface* o_ = (DataDictionaryInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } 
	auto res_ = MTable::_instance.DataDictionaryInterface_SetData_2(o_, std::forward<ForwardingDataPtr>(key), std::forward<ForwardingDataPtr>(data));
	return ReturnHelper::Return(this, res_.GetErrorStorage());
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto DataDictionaryInterface::Hxx1::ConstFn<S>::GetData(const ConstDataPtr& key) const -> Result<Data>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<Data>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const DataDictionaryInterface* o_ = (const DataDictionaryInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = DataDictionaryInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (MTable::_instance.DataDictionaryInterface_GetData(o_, key));
}
template <typename S> template <typename KEY> MAXON_ATTRIBUTE_FORCE_INLINE auto DataDictionaryInterface::Hxx1::ConstFn<S>::Contains(KEY&& key) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const DataDictionaryInterface* o_ = (const DataDictionaryInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = DataDictionaryInterface::NullValuePtr(); if (!o_) return maxon::PrivateLogNullptrError(false); } 
	return (o_->Contains<KEY>(std::forward<KEY>(key)));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto DataDictionaryInterface::Hxx1::Fn<S>::EraseData(const ConstDataPtr& key) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); DataDictionaryInterface* o_ = (DataDictionaryInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (MTable::_instance.DataDictionaryInterface_EraseData(o_, key));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto DataDictionaryInterface::Hxx1::COWFn<S>::EraseData(const ConstDataPtr& key) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); DataDictionaryInterface* o_ = (DataDictionaryInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } 
	return (MTable::_instance.DataDictionaryInterface_EraseData(o_, key));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto DataDictionaryInterface::Hxx1::Fn<S>::Reset() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); DataDictionaryInterface* o_ = (DataDictionaryInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { DebugStop(); return maxon::PrivateLogNullptrError(); } 
	MTable::_instance.DataDictionaryInterface_Reset(o_);
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto DataDictionaryInterface::Hxx1::COWFn<S>::Reset() -> typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), void, maxon::Result<void>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), void, maxon::Result<void>>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); DataDictionaryInterface* o_ = (DataDictionaryInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } 
	MTable::_instance.DataDictionaryInterface_Reset(o_);
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto DataDictionaryInterface::Hxx1::ConstFn<S>::IsEmpty() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const DataDictionaryInterface* o_ = (const DataDictionaryInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = DataDictionaryInterface::NullValuePtr(); if (!o_) return maxon::PrivateLogNullptrError(false); } 
	return (MTable::_instance.DataDictionaryInterface_IsEmpty(o_));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto DataDictionaryInterface::Hxx1::ConstFn<S>::IsPopulated() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const DataDictionaryInterface* o_ = (const DataDictionaryInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = DataDictionaryInterface::NullValuePtr(); if (!o_) return maxon::PrivateLogNullptrError(false); } 
	return (o_->IsPopulated());
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto DataDictionaryInterface::Hxx1::ConstFn<S>::GetCount() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const DataDictionaryInterface* o_ = (const DataDictionaryInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = DataDictionaryInterface::NullValuePtr(); if (!o_) return 0; } 
	return (MTable::_instance.DataDictionaryInterface_GetCount(o_));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto DataDictionaryInterface::Hxx1::ConstFn<S>::ToString(const FormatStatement* formatStatement) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<String>, String>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<String>, String>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const DataDictionaryInterface* o_ = (const DataDictionaryInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = DataDictionaryInterface::NullValuePtr(); if (!o_) return maxon::PrivateIncompleteNullReturnValue<String>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } 
	return (MTable::_instance.DataDictionaryInterface_ToString(o_, formatStatement));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto DataDictionaryInterface::Hxx1::ConstFn<S>::DescribeIO(const DataSerializeInterface& stream) -> Result<void>
{
	return (MTable::_instance.DataDictionaryInterface_DescribeIO(stream));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto DataDictionaryInterface::Hxx1::ConstFn<S>::IsEqual(const DataDictionaryInterface* other, EQUALITY equality) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const DataDictionaryInterface* o_ = (const DataDictionaryInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = DataDictionaryInterface::NullValuePtr(); if (!o_) return maxon::PrivateLogNullptrError(false); } 
	return (MTable::_instance.DataDictionaryInterface_IsEqual(o_, other, equality));
}
template <typename S> template <typename T, typename KEY> MAXON_ATTRIBUTE_FORCE_INLINE auto DataDictionaryInterface::Hxx1::ConstFn<S>::Get(KEY&& key) const -> Result<typename std::conditional<std::is_void<T>::value, typename IsFidClass<KEY>::type, T>::type>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<typename std::conditional<std::is_void<T>::value, typename IsFidClass<KEY>::type, T>::type>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const DataDictionaryInterface* o_ = (const DataDictionaryInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = DataDictionaryInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (o_->Get<T, KEY>(std::forward<KEY>(key)));
}
template <typename S> template <typename T, typename KEY> MAXON_ATTRIBUTE_FORCE_INLINE auto DataDictionaryInterface::Hxx1::ConstFn<S>::Get(KEY&& key, const T& defaultValue) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<typename std::conditional<IsFidClass<KEY>::value&&GetCollectionKind<T>::value!=COLLECTION_KIND::ARRAY, typename IsFidClass<KEY>::type, T>::type>, typename std::conditional<IsFidClass<KEY>::value&&GetCollectionKind<T>::value!=COLLECTION_KIND::ARRAY, typename IsFidClass<KEY>::type, T>::type>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<typename std::conditional<IsFidClass<KEY>::value&&GetCollectionKind<T>::value!=COLLECTION_KIND::ARRAY, typename IsFidClass<KEY>::type, T>::type>, typename std::conditional<IsFidClass<KEY>::value&&GetCollectionKind<T>::value!=COLLECTION_KIND::ARRAY, typename IsFidClass<KEY>::type, T>::type>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const DataDictionaryInterface* o_ = (const DataDictionaryInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = DataDictionaryInterface::NullValuePtr(); if (!o_) return maxon::PrivateNullReturnValue<typename std::conditional<IsFidClass<KEY>::value&&GetCollectionKind<T>::value!=COLLECTION_KIND::ARRAY, typename IsFidClass<KEY>::type, T>::type>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } 
	return (o_->Get<T, KEY>(std::forward<KEY>(key), defaultValue));
}
template <typename S> template <typename T, typename KEY> MAXON_ATTRIBUTE_FORCE_INLINE auto DataDictionaryInterface::Hxx1::ConstFn<S>::Get(KEY&& key, T&& defaultValue) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<typename std::conditional<IsFidClass<KEY>::value&&GetCollectionKind<T>::value!=COLLECTION_KIND::ARRAY, typename IsFidClass<KEY>::type, T>::type>, typename std::conditional<IsFidClass<KEY>::value&&GetCollectionKind<T>::value!=COLLECTION_KIND::ARRAY, typename IsFidClass<KEY>::type, T>::type>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<typename std::conditional<IsFidClass<KEY>::value&&GetCollectionKind<T>::value!=COLLECTION_KIND::ARRAY, typename IsFidClass<KEY>::type, T>::type>, typename std::conditional<IsFidClass<KEY>::value&&GetCollectionKind<T>::value!=COLLECTION_KIND::ARRAY, typename IsFidClass<KEY>::type, T>::type>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const DataDictionaryInterface* o_ = (const DataDictionaryInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = DataDictionaryInterface::NullValuePtr(); if (!o_) return maxon::PrivateNullReturnValue<typename std::conditional<IsFidClass<KEY>::value&&GetCollectionKind<T>::value!=COLLECTION_KIND::ARRAY, typename IsFidClass<KEY>::type, T>::type>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } 
	return (o_->Get<T, KEY>(std::forward<KEY>(key), std::forward<T>(defaultValue)));
}
template <typename S> template <typename T, typename KEY> MAXON_ATTRIBUTE_FORCE_INLINE auto DataDictionaryInterface::Hxx1::ConstFn<S>::GetOrDefault(KEY&& key) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<typename std::conditional<std::is_void<T>::value, typename IsFidClass<KEY>::type, T>::type>, typename std::conditional<std::is_void<T>::value, typename IsFidClass<KEY>::type, T>::type>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<typename std::conditional<std::is_void<T>::value, typename IsFidClass<KEY>::type, T>::type>, typename std::conditional<std::is_void<T>::value, typename IsFidClass<KEY>::type, T>::type>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const DataDictionaryInterface* o_ = (const DataDictionaryInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = DataDictionaryInterface::NullValuePtr(); if (!o_) return maxon::PrivateNullReturnValue<typename std::conditional<std::is_void<T>::value, typename IsFidClass<KEY>::type, T>::type>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } 
	return (o_->GetOrDefault<T, KEY>(std::forward<KEY>(key)));
}
template <typename S> template <typename T, typename KEY> MAXON_ATTRIBUTE_FORCE_INLINE auto DataDictionaryInterface::Hxx1::Fn<S>::Set(KEY&& key, T&& data) const -> maxon::Result<DOXYGEN_SWITCH(maxon::RefMemberType<S const>, S)>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), true, maxon::Result<DOXYGEN_SWITCH(maxon::RefMemberType<S const>, S)>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); DataDictionaryInterface* o_ = (DataDictionaryInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR)); } 
	auto res_ = o_->Set<T, KEY>(std::forward<KEY>(key), std::forward<T>(data));
	return ReturnHelper::Return(this, res_.GetErrorStorage());
}
template <typename S> template <typename T, typename KEY> MAXON_ATTRIBUTE_FORCE_INLINE auto DataDictionaryInterface::Hxx1::COWFn<S>::Set(KEY&& key, T&& data) -> maxon::Result<DOXYGEN_SWITCH(maxon::RefMemberType<S>, S)>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), true, maxon::Result<DOXYGEN_SWITCH(maxon::RefMemberType<S>, S)>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); DataDictionaryInterface* o_ = (DataDictionaryInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } 
	auto res_ = o_->Set<T, KEY>(std::forward<KEY>(key), std::forward<T>(data));
	return ReturnHelper::Return(this, res_.GetErrorStorage());
}
template <typename S> template <typename KEY> MAXON_ATTRIBUTE_FORCE_INLINE auto DataDictionaryInterface::Hxx1::Fn<S>::Erase(KEY&& key) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); DataDictionaryInterface* o_ = (DataDictionaryInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (o_->Erase<KEY>(std::forward<KEY>(key)));
}
template <typename S> template <typename KEY> MAXON_ATTRIBUTE_FORCE_INLINE auto DataDictionaryInterface::Hxx1::COWFn<S>::Erase(KEY&& key) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); DataDictionaryInterface* o_ = (DataDictionaryInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } 
	return (o_->Erase<KEY>(std::forward<KEY>(key)));
}
template <typename S> template <typename T, typename KEY> MAXON_ATTRIBUTE_FORCE_INLINE auto DataDictionaryInterface::Hxx1::ConstFn<S>::GetCopy(KEY&& key, T& dst) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const DataDictionaryInterface* o_ = (const DataDictionaryInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = DataDictionaryInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (o_->GetCopy<T, KEY>(std::forward<KEY>(key), dst));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto DataDictionaryInterface::Hxx1::ConstFn<S>::InitIterator(DataDictionaryIteratorInterface* iterator, Bool end) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const DataDictionaryInterface* o_ = (const DataDictionaryInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = DataDictionaryInterface::NullValuePtr(); if (!o_) return maxon::PrivateLogNullptrError(); } 
	MTable::_instance.DataDictionaryInterface_InitIterator(o_, iterator, end);
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto DataDictionaryInterface::Hxx1::ConstFn<S>::Begin() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<ConstIterator>, ConstIterator>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<ConstIterator>, ConstIterator>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const DataDictionaryInterface* o_ = (const DataDictionaryInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = DataDictionaryInterface::NullValuePtr(); if (!o_) return maxon::PrivateIncompleteNullReturnValue<ConstIterator>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } 
	return (o_->Begin());
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto DataDictionaryInterface::Hxx1::ConstFn<S>::End() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<ConstIterator>, ConstIterator>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<ConstIterator>, ConstIterator>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const DataDictionaryInterface* o_ = (const DataDictionaryInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = DataDictionaryInterface::NullValuePtr(); if (!o_) return maxon::PrivateIncompleteNullReturnValue<ConstIterator>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } 
	return (o_->End());
}
#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT) && !defined(MAXON_DEPENDENCY_DISABLE_datadictionary)
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

