
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
	static const maxon::UNRESOLVED_RETURN_TYPE _returnTypes[];
	static const maxon::Bool HAS_NONSTATIC = true;
	PRIVATE_MAXON_SF_POINTER(DataDictionaryInterface_Free, Free, MAXON_EXPAND_VA_ARGS, (void), const DataDictionaryInterface* object);
	PRIVATE_MAXON_SF_POINTER(DataDictionaryInterface_Alloc, Alloc, MAXON_IGNORE_VA_ARGS, (DataDictionaryInterface*), const maxon::SourceLocation& allocLocation);
	PRIVATE_MAXON_SF_POINTER(DataDictionaryInterface_Alloc_1, Alloc, MAXON_IGNORE_VA_ARGS, (DataDictionaryInterface*), const maxon::SourceLocation& allocLocation, const DataDictionaryInterface& object);
	PRIVATE_MAXON_MF_POINTER(DataDictionaryInterface_SetData, SetData, false, DataDictionaryInterface,, (Result<void>), ForwardingDataPtr&& key, const Data& data);
	PRIVATE_MAXON_MF_POINTER(DataDictionaryInterface_SetData_1, SetData, false, DataDictionaryInterface,, (Result<void>), ForwardingDataPtr&& key, Data&& data);
	PRIVATE_MAXON_MF_POINTER(DataDictionaryInterface_SetData_2, SetData, false, DataDictionaryInterface,, (Result<void>), ForwardingDataPtr&& key, ForwardingDataPtr&& data);
	PRIVATE_MAXON_MF_POINTER(DataDictionaryInterface_GetData, GetData, false, DataDictionaryInterface, const, (Result<Data>), const ConstDataPtr& key);
	PRIVATE_MAXON_MF_POINTER(DataDictionaryInterface_EraseData, EraseData, false, DataDictionaryInterface,, (Result<void>), const ConstDataPtr& key);
	PRIVATE_MAXON_MF_POINTER(DataDictionaryInterface_Reset, Reset, false, DataDictionaryInterface,, (void));
	PRIVATE_MAXON_MF_POINTER(DataDictionaryInterface_GetCount, GetCount, false, DataDictionaryInterface, const, (Int));
	PRIVATE_MAXON_MF_POINTER(DataDictionaryInterface_ToString, ToString, false, DataDictionaryInterface, const, (String), const FormatStatement* formatStatement);
	PRIVATE_MAXON_SF_POINTER(DataDictionaryInterface_DescribeIO, DescribeIO, MAXON_EXPAND_VA_ARGS, (Result<void>), const DataSerializeInterface& stream);
	PRIVATE_MAXON_MF_POINTER(DataDictionaryInterface_IsEqual, IsEqual, false, DataDictionaryInterface, const, (Bool), const DataDictionaryInterface* other, EQUALITY equality);
	PRIVATE_MAXON_MF_POINTER(DataDictionaryInterface_GetHashCode, GetHashCode, false, DataDictionaryInterface, const, (HashInt));
	PRIVATE_MAXON_MF_POINTER(DataDictionaryInterface_GetUniqueHashCode, GetUniqueHashCode, false, DataDictionaryInterface, const, (UniqueHash));
	PRIVATE_MAXON_MF_POINTER(DataDictionaryInterface_InitIterator, InitIterator, false, DataDictionaryInterface, const, (void), DataDictionaryIteratorInterface* iterator, Bool end);
	PRIVATE_MAXON_MF_POINTER(DataDictionaryInterface_PrivateGetData, PrivateGetData, false, DataDictionaryInterface, const, (const Data*), const ConstDataPtr& key);
	template <typename IMPL> void Init()
	{
		DataDictionaryInterface_Free = DataDictionaryInterface_Free_GetPtr<IMPL>(true);
		DataDictionaryInterface_Alloc = DataDictionaryInterface_Alloc_GetPtr<IMPL>(true);
		DataDictionaryInterface_Alloc_1 = DataDictionaryInterface_Alloc_1_GetPtr<IMPL>(true);
		DataDictionaryInterface_SetData = DataDictionaryInterface_SetData_GetPtr<IMPL>(0, true).first;
		DataDictionaryInterface_SetData_1 = DataDictionaryInterface_SetData_1_GetPtr<IMPL>(0, true).first;
		DataDictionaryInterface_SetData_2 = DataDictionaryInterface_SetData_2_GetPtr<IMPL>(0, true).first;
		DataDictionaryInterface_GetData = DataDictionaryInterface_GetData_GetPtr<IMPL>(0, true).first;
		DataDictionaryInterface_EraseData = DataDictionaryInterface_EraseData_GetPtr<IMPL>(0, true).first;
		DataDictionaryInterface_Reset = DataDictionaryInterface_Reset_GetPtr<IMPL>(0, true).first;
		DataDictionaryInterface_GetCount = DataDictionaryInterface_GetCount_GetPtr<IMPL>(0, true).first;
		DataDictionaryInterface_ToString = DataDictionaryInterface_ToString_GetPtr<IMPL>(0, true).first;
		DataDictionaryInterface_DescribeIO = DataDictionaryInterface_DescribeIO_GetPtr<IMPL>(true);
		DataDictionaryInterface_IsEqual = DataDictionaryInterface_IsEqual_GetPtr<IMPL>(0, true).first;
		DataDictionaryInterface_GetHashCode = DataDictionaryInterface_GetHashCode_GetPtr<IMPL>(0, true).first;
		DataDictionaryInterface_GetUniqueHashCode = DataDictionaryInterface_GetUniqueHashCode_GetPtr<IMPL>(0, true).first;
		DataDictionaryInterface_InitIterator = DataDictionaryInterface_InitIterator_GetPtr<IMPL>(0, true).first;
		DataDictionaryInterface_PrivateGetData = DataDictionaryInterface_PrivateGetData_GetPtr<IMPL>(0, true).first;
	}
};

struct DataDictionaryInterface::Hxx2
{
	class Unresolved;
	template <typename S> class Wrapper
	{
	public:
		using Implementation = S;
		static void DataDictionaryInterface_Free(const DataDictionaryInterface* object) { return S::Free(object); }
		static DataDictionaryInterface* DataDictionaryInterface_Alloc(const maxon::SourceLocation& allocLocation) { return S::Alloc(allocLocation); }
		static DataDictionaryInterface* DataDictionaryInterface_Alloc_1(const maxon::SourceLocation& allocLocation, const DataDictionaryInterface& object) { return S::Alloc(allocLocation, ((const S&) object)); }
		PRIVATE_MAXON_MF_WRAPPER(DataDictionaryInterface_SetData, DataDictionaryInterface,, (Result<void>), ForwardingDataPtr&& key, const Data& data) { return S::Get(PRIVATE_MAXON_MF_THIS(DataDictionaryInterface))->SetData(std::forward<ForwardingDataPtr>(key), data); }
		PRIVATE_MAXON_MF_WRAPPER(DataDictionaryInterface_SetData_1, DataDictionaryInterface,, (Result<void>), ForwardingDataPtr&& key, Data&& data) { return S::Get(PRIVATE_MAXON_MF_THIS(DataDictionaryInterface))->SetData(std::forward<ForwardingDataPtr>(key), std::forward<Data>(data)); }
		PRIVATE_MAXON_MF_WRAPPER(DataDictionaryInterface_SetData_2, DataDictionaryInterface,, (Result<void>), ForwardingDataPtr&& key, ForwardingDataPtr&& data) { return S::Get(PRIVATE_MAXON_MF_THIS(DataDictionaryInterface))->SetData(std::forward<ForwardingDataPtr>(key), std::forward<ForwardingDataPtr>(data)); }
		PRIVATE_MAXON_MF_WRAPPER(DataDictionaryInterface_GetData, DataDictionaryInterface, const, (Result<Data>), const ConstDataPtr& key) { return S::Get(PRIVATE_MAXON_MF_THIS(const DataDictionaryInterface))->GetData(key); }
		PRIVATE_MAXON_MF_WRAPPER(DataDictionaryInterface_EraseData, DataDictionaryInterface,, (Result<void>), const ConstDataPtr& key) { return S::Get(PRIVATE_MAXON_MF_THIS(DataDictionaryInterface))->EraseData(key); }
		PRIVATE_MAXON_MF_WRAPPER(DataDictionaryInterface_Reset, DataDictionaryInterface,, (void)) { return S::Get(PRIVATE_MAXON_MF_THIS(DataDictionaryInterface))->Reset(); }
		PRIVATE_MAXON_MF_WRAPPER(DataDictionaryInterface_GetCount, DataDictionaryInterface, const, (Int)) { return S::Get(PRIVATE_MAXON_MF_THIS(const DataDictionaryInterface))->GetCount(); }
		PRIVATE_MAXON_MF_WRAPPER(DataDictionaryInterface_ToString, DataDictionaryInterface, const, (String), const FormatStatement* formatStatement) { return S::Get(PRIVATE_MAXON_MF_THIS(const DataDictionaryInterface))->ToString(formatStatement); }
		static Result<void> DataDictionaryInterface_DescribeIO(const DataSerializeInterface& stream) { return S::DescribeIO(stream); }
		PRIVATE_MAXON_MF_WRAPPER(DataDictionaryInterface_IsEqual, DataDictionaryInterface, const, (Bool), const DataDictionaryInterface* other, EQUALITY equality) { return S::Get(PRIVATE_MAXON_MF_THIS(const DataDictionaryInterface))->IsEqual(other, equality); }
		PRIVATE_MAXON_MF_WRAPPER(DataDictionaryInterface_GetHashCode, DataDictionaryInterface, const, (HashInt)) { return S::Get(PRIVATE_MAXON_MF_THIS(const DataDictionaryInterface))->GetHashCode(); }
		PRIVATE_MAXON_MF_WRAPPER(DataDictionaryInterface_GetUniqueHashCode, DataDictionaryInterface, const, (UniqueHash)) { return S::Get(PRIVATE_MAXON_MF_THIS(const DataDictionaryInterface))->GetUniqueHashCode(); }
		PRIVATE_MAXON_MF_WRAPPER(DataDictionaryInterface_InitIterator, DataDictionaryInterface, const, (void), DataDictionaryIteratorInterface* iterator, Bool end) { return S::Get(PRIVATE_MAXON_MF_THIS(const DataDictionaryInterface))->InitIterator(iterator, end); }
		PRIVATE_MAXON_MF_WRAPPER(DataDictionaryInterface_PrivateGetData, DataDictionaryInterface, const, (const Data*), const ConstDataPtr& key) { return S::Get(PRIVATE_MAXON_MF_THIS(const DataDictionaryInterface))->PrivateGetData(key); }
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
	return PRIVATE_MAXON_MF_INVOKE((this), MTable::_instance.DataDictionaryInterface_SetData, std::forward<ForwardingDataPtr>(key), data);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto DataDictionaryInterface::SetData(ForwardingDataPtr&& key, Data&& data) -> Result<void>
{
	return PRIVATE_MAXON_MF_INVOKE((this), MTable::_instance.DataDictionaryInterface_SetData_1, std::forward<ForwardingDataPtr>(key), std::forward<Data>(data));
}
MAXON_ATTRIBUTE_FORCE_INLINE auto DataDictionaryInterface::SetData(ForwardingDataPtr&& key, ForwardingDataPtr&& data) -> Result<void>
{
	return PRIVATE_MAXON_MF_INVOKE((this), MTable::_instance.DataDictionaryInterface_SetData_2, std::forward<ForwardingDataPtr>(key), std::forward<ForwardingDataPtr>(data));
}
MAXON_ATTRIBUTE_FORCE_INLINE auto DataDictionaryInterface::GetData(const ConstDataPtr& key) const -> Result<Data>
{
	return PRIVATE_MAXON_MF_INVOKE((this), MTable::_instance.DataDictionaryInterface_GetData, key);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto DataDictionaryInterface::EraseData(const ConstDataPtr& key) -> Result<void>
{
	return PRIVATE_MAXON_MF_INVOKE((this), MTable::_instance.DataDictionaryInterface_EraseData, key);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto DataDictionaryInterface::Reset() -> void
{
	return PRIVATE_MAXON_MF_INVOKE((this), MTable::_instance.DataDictionaryInterface_Reset);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto DataDictionaryInterface::GetCount() const -> Int
{
	return PRIVATE_MAXON_MF_INVOKE((this), MTable::_instance.DataDictionaryInterface_GetCount);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto DataDictionaryInterface::ToString(const FormatStatement* formatStatement) const -> String
{
	return PRIVATE_MAXON_MF_INVOKE((this), MTable::_instance.DataDictionaryInterface_ToString, formatStatement);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto DataDictionaryInterface::DescribeIO(const DataSerializeInterface& stream) -> Result<void>
{
	return MTable::_instance.DataDictionaryInterface_DescribeIO(stream);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto DataDictionaryInterface::IsEqual(const DataDictionaryInterface* other, EQUALITY equality) const -> Bool
{
	return PRIVATE_MAXON_MF_INVOKE((this), MTable::_instance.DataDictionaryInterface_IsEqual, other, equality);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto DataDictionaryInterface::GetHashCode() const -> HashInt
{
	return PRIVATE_MAXON_MF_INVOKE((this), MTable::_instance.DataDictionaryInterface_GetHashCode);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto DataDictionaryInterface::GetUniqueHashCode() const -> UniqueHash
{
	return PRIVATE_MAXON_MF_INVOKE((this), MTable::_instance.DataDictionaryInterface_GetUniqueHashCode);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto DataDictionaryInterface::InitIterator(DataDictionaryIteratorInterface* iterator, Bool end) const -> void
{
	return PRIVATE_MAXON_MF_INVOKE((this), MTable::_instance.DataDictionaryInterface_InitIterator, iterator, end);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto DataDictionaryInterface::PrivateGetData(const ConstDataPtr& key) const -> const Data*
{
	return PRIVATE_MAXON_MF_INVOKE((this), MTable::_instance.DataDictionaryInterface_PrivateGetData, key);
}

auto DataDictionaryInterface::Hxx1::Reference::Create() -> maxon::ResultMemT<DataDictionary>
{
	DataDictionaryInterface* res_ = DataDictionaryInterface::Alloc(MAXON_SOURCE_LOCATION);
	return DataDictionary(maxon::ForwardResultPtr<DataDictionaryInterface>(res_));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto DataDictionaryInterface::Hxx1::Fn<S>::SetData(ForwardingDataPtr&& key, const Data& data) const -> maxon::Result<DOXYGEN_SWITCH(maxon::RefMemberType<S const>, S)>
{
	HXXRETURN1(maxon::Result<DOXYGEN_SWITCH(maxon::RefMemberType<S const>, S)>); HXXRES; HXXNONCONST(, , false, HXXRET2b(NULLPTR)) 
	auto res_ = PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.DataDictionaryInterface_SetData, std::forward<ForwardingDataPtr>(key), data);
	return ReturnHelper::Return(this, res_.GetErrorStorage());
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto DataDictionaryInterface::Hxx1::COWFn<S>::SetData(ForwardingDataPtr&& key, const Data& data) -> maxon::Result<DOXYGEN_SWITCH(maxon::RefMemberType<S>, S)>
{
	HXXRETURN1(maxon::Result<DOXYGEN_SWITCH(maxon::RefMemberType<S>, S)>); HXXRES; HXXNONCONST(, MakeWritable(true)., true, HXXRET2b(MAKE_WRITABLE_FAILED)) 
	auto res_ = PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.DataDictionaryInterface_SetData, std::forward<ForwardingDataPtr>(key), data);
	return ReturnHelper::Return(this, res_.GetErrorStorage());
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto DataDictionaryInterface::Hxx1::Fn<S>::SetData(ForwardingDataPtr&& key, Data&& data) const -> maxon::Result<DOXYGEN_SWITCH(maxon::RefMemberType<S const>, S)>
{
	HXXRETURN1(maxon::Result<DOXYGEN_SWITCH(maxon::RefMemberType<S const>, S)>); HXXRES; HXXNONCONST(, , false, HXXRET2b(NULLPTR)) 
	auto res_ = PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.DataDictionaryInterface_SetData_1, std::forward<ForwardingDataPtr>(key), std::forward<Data>(data));
	return ReturnHelper::Return(this, res_.GetErrorStorage());
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto DataDictionaryInterface::Hxx1::COWFn<S>::SetData(ForwardingDataPtr&& key, Data&& data) -> maxon::Result<DOXYGEN_SWITCH(maxon::RefMemberType<S>, S)>
{
	HXXRETURN1(maxon::Result<DOXYGEN_SWITCH(maxon::RefMemberType<S>, S)>); HXXRES; HXXNONCONST(, MakeWritable(true)., true, HXXRET2b(MAKE_WRITABLE_FAILED)) 
	auto res_ = PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.DataDictionaryInterface_SetData_1, std::forward<ForwardingDataPtr>(key), std::forward<Data>(data));
	return ReturnHelper::Return(this, res_.GetErrorStorage());
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto DataDictionaryInterface::Hxx1::Fn<S>::SetData(ForwardingDataPtr&& key, ForwardingDataPtr&& data) const -> maxon::Result<DOXYGEN_SWITCH(maxon::RefMemberType<S const>, S)>
{
	HXXRETURN1(maxon::Result<DOXYGEN_SWITCH(maxon::RefMemberType<S const>, S)>); HXXRES; HXXNONCONST(, , false, HXXRET2b(NULLPTR)) 
	auto res_ = PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.DataDictionaryInterface_SetData_2, std::forward<ForwardingDataPtr>(key), std::forward<ForwardingDataPtr>(data));
	return ReturnHelper::Return(this, res_.GetErrorStorage());
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto DataDictionaryInterface::Hxx1::COWFn<S>::SetData(ForwardingDataPtr&& key, ForwardingDataPtr&& data) -> maxon::Result<DOXYGEN_SWITCH(maxon::RefMemberType<S>, S)>
{
	HXXRETURN1(maxon::Result<DOXYGEN_SWITCH(maxon::RefMemberType<S>, S)>); HXXRES; HXXNONCONST(, MakeWritable(true)., true, HXXRET2b(MAKE_WRITABLE_FAILED)) 
	auto res_ = PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.DataDictionaryInterface_SetData_2, std::forward<ForwardingDataPtr>(key), std::forward<ForwardingDataPtr>(data));
	return ReturnHelper::Return(this, res_.GetErrorStorage());
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto DataDictionaryInterface::Hxx1::ConstFn<S>::GetData(const ConstDataPtr& key) const -> Result<Data>
{
	HXXRETURN0(Result<Data>); HXXRES; HXXCONST(HXXRET1(NULLPTR)) 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.DataDictionaryInterface_GetData, key));
}
template <typename S> template <typename KEY> MAXON_ATTRIBUTE_FORCE_INLINE auto DataDictionaryInterface::Hxx1::ConstFn<S>::Contains(KEY&& key) const -> HXXADDRET2(Bool)
{
	HXXRETURN0(HXXADDRET2(Bool)); HXXRES; HXXCONST(maxon::PrivateLogNullptrError(false)) 
	return (o_->Contains<KEY>(std::forward<KEY>(key)));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto DataDictionaryInterface::Hxx1::Fn<S>::EraseData(const ConstDataPtr& key) const -> Result<void>
{
	HXXRETURN0(Result<void>); HXXRES; HXXNONCONST(, , false, HXXRET1(NULLPTR)) 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.DataDictionaryInterface_EraseData, key));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto DataDictionaryInterface::Hxx1::COWFn<S>::EraseData(const ConstDataPtr& key) -> Result<void>
{
	HXXRETURN0(Result<void>); HXXRES; HXXNONCONST(, MakeWritable(true)., true, HXXRET2a(HXXRET1(MAKE_WRITABLE_FAILED))) 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.DataDictionaryInterface_EraseData, key));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto DataDictionaryInterface::Hxx1::Fn<S>::Reset() const -> HXXADDRET2(void)
{
	HXXRETURN0(HXXADDRET2(void)); HXXRES; HXXNONCONST(DebugStop(), , false, maxon::PrivateLogNullptrError()) 
	PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.DataDictionaryInterface_Reset);
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto DataDictionaryInterface::Hxx1::COWFn<S>::Reset() -> HXXADDRET1(void)
{
	HXXRETURN0(HXXADDRET1(void)); HXXRES; HXXNONCONST(, MakeWritable(true)., true, HXXRET2a(HXXRET1(MAKE_WRITABLE_FAILED))) 
	PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.DataDictionaryInterface_Reset);
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto DataDictionaryInterface::Hxx1::ConstFn<S>::IsEmpty() const -> HXXADDRET2(Bool)
{
	HXXRETURN0(HXXADDRET2(Bool)); HXXRES; HXXCONST(maxon::PrivateLogNullptrError(false)) 
	return (o_->IsEmpty());
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto DataDictionaryInterface::Hxx1::ConstFn<S>::IsPopulated() const -> HXXADDRET2(Bool)
{
	HXXRETURN0(HXXADDRET2(Bool)); HXXRES; HXXCONST(maxon::PrivateLogNullptrError(false)) 
	return (o_->IsPopulated());
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto DataDictionaryInterface::Hxx1::ConstFn<S>::GetCount() const -> HXXADDRET2(Int)
{
	HXXRETURN0(HXXADDRET2(Int)); HXXRES; HXXCONST(0) 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.DataDictionaryInterface_GetCount));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto DataDictionaryInterface::Hxx1::ConstFn<S>::ToString(const FormatStatement* formatStatement) const -> HXXADDRET2(String)
{
	HXXRETURN0(HXXADDRET2(String)); HXXRES; HXXCONST(HXXRET3(NULLPTR, String)) 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.DataDictionaryInterface_ToString, formatStatement));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto DataDictionaryInterface::Hxx1::ConstFn<S>::DescribeIO(const DataSerializeInterface& stream) -> Result<void>
{
	return (MTable::_instance.DataDictionaryInterface_DescribeIO(stream));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto DataDictionaryInterface::Hxx1::ConstFn<S>::IsEqual(const DataDictionaryInterface* other, EQUALITY equality) const -> HXXADDRET2(Bool)
{
	HXXRETURN0(HXXADDRET2(Bool)); HXXRES; HXXCONST(maxon::PrivateLogNullptrError(false)) 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.DataDictionaryInterface_IsEqual, other, equality));
}
template <typename S> template <typename T, typename KEY> MAXON_ATTRIBUTE_FORCE_INLINE auto DataDictionaryInterface::Hxx1::ConstFn<S>::Get(KEY&& key) const -> Result<typename std::conditional<std::is_void<T>::value, typename IsFidClass<KEY>::type, T>::type>
{
	HXXRETURN0(Result<typename std::conditional<std::is_void<T>::value, typename IsFidClass<KEY>::type, T>::type>); HXXRES; HXXCONST(HXXRET1(NULLPTR)) 
	return (o_->Get<T, KEY>(std::forward<KEY>(key)));
}
template <typename S> template <typename T, typename KEY> MAXON_ATTRIBUTE_FORCE_INLINE auto DataDictionaryInterface::Hxx1::ConstFn<S>::Get(KEY&& key, const T& defaultValue) const -> HXXADDRET2(typename std::conditional<IsFidClass<KEY>::value&&GetCollectionKind<T>::value!=COLLECTION_KIND::ARRAY, typename IsFidClass<KEY>::type, T>::type)
{
	HXXRETURN0(HXXADDRET2(typename std::conditional<IsFidClass<KEY>::value&&GetCollectionKind<T>::value!=COLLECTION_KIND::ARRAY, typename IsFidClass<KEY>::type, T>::type)); HXXRES; HXXCONST(maxon::PrivateDefaultReturnValue<typename std::conditional<IsFidClass<KEY>::value&&GetCollectionKind<T>::value!=COLLECTION_KIND::ARRAY, typename IsFidClass<KEY>::type, T>::type>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK)) 
	return (o_->Get<T, KEY>(std::forward<KEY>(key), defaultValue));
}
template <typename S> template <typename T, typename KEY> MAXON_ATTRIBUTE_FORCE_INLINE auto DataDictionaryInterface::Hxx1::ConstFn<S>::Get(KEY&& key, T&& defaultValue) const -> HXXADDRET2(typename std::conditional<IsFidClass<KEY>::value&&GetCollectionKind<T>::value!=COLLECTION_KIND::ARRAY, typename IsFidClass<KEY>::type, T>::type)
{
	HXXRETURN0(HXXADDRET2(typename std::conditional<IsFidClass<KEY>::value&&GetCollectionKind<T>::value!=COLLECTION_KIND::ARRAY, typename IsFidClass<KEY>::type, T>::type)); HXXRES; HXXCONST(maxon::PrivateDefaultReturnValue<typename std::conditional<IsFidClass<KEY>::value&&GetCollectionKind<T>::value!=COLLECTION_KIND::ARRAY, typename IsFidClass<KEY>::type, T>::type>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK)) 
	return (o_->Get<T, KEY>(std::forward<KEY>(key), std::forward<T>(defaultValue)));
}
template <typename S> template <typename T, typename KEY> MAXON_ATTRIBUTE_FORCE_INLINE auto DataDictionaryInterface::Hxx1::ConstFn<S>::GetOrDefault(KEY&& key) const -> HXXADDRET2(typename std::conditional<std::is_void<T>::value, typename IsFidClass<KEY>::type, T>::type)
{
	HXXRETURN0(HXXADDRET2(typename std::conditional<std::is_void<T>::value, typename IsFidClass<KEY>::type, T>::type)); HXXRES; HXXCONST(maxon::PrivateDefaultReturnValue<typename std::conditional<std::is_void<T>::value, typename IsFidClass<KEY>::type, T>::type>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK)) 
	return (o_->GetOrDefault<T, KEY>(std::forward<KEY>(key)));
}
template <typename S> template <typename T, typename KEY> MAXON_ATTRIBUTE_FORCE_INLINE auto DataDictionaryInterface::Hxx1::Fn<S>::Set(KEY&& key, T&& data) const -> maxon::Result<DOXYGEN_SWITCH(maxon::RefMemberType<S const>, S)>
{
	HXXRETURN1(maxon::Result<DOXYGEN_SWITCH(maxon::RefMemberType<S const>, S)>); HXXRES; HXXNONCONST(, , false, HXXRET2b(NULLPTR)) 
	auto res_ = o_->Set<T, KEY>(std::forward<KEY>(key), std::forward<T>(data));
	return ReturnHelper::Return(this, res_.GetErrorStorage());
}
template <typename S> template <typename T, typename KEY> MAXON_ATTRIBUTE_FORCE_INLINE auto DataDictionaryInterface::Hxx1::COWFn<S>::Set(KEY&& key, T&& data) -> maxon::Result<DOXYGEN_SWITCH(maxon::RefMemberType<S>, S)>
{
	HXXRETURN1(maxon::Result<DOXYGEN_SWITCH(maxon::RefMemberType<S>, S)>); HXXRES; HXXNONCONST(, MakeWritable(true)., true, HXXRET2b(MAKE_WRITABLE_FAILED)) 
	auto res_ = o_->Set<T, KEY>(std::forward<KEY>(key), std::forward<T>(data));
	return ReturnHelper::Return(this, res_.GetErrorStorage());
}
template <typename S> template <typename KEY> MAXON_ATTRIBUTE_FORCE_INLINE auto DataDictionaryInterface::Hxx1::Fn<S>::Erase(KEY&& key) const -> Result<void>
{
	HXXRETURN0(Result<void>); HXXRES; HXXNONCONST(, , false, HXXRET1(NULLPTR)) 
	return (o_->Erase<KEY>(std::forward<KEY>(key)));
}
template <typename S> template <typename KEY> MAXON_ATTRIBUTE_FORCE_INLINE auto DataDictionaryInterface::Hxx1::COWFn<S>::Erase(KEY&& key) -> Result<void>
{
	HXXRETURN0(Result<void>); HXXRES; HXXNONCONST(, MakeWritable(true)., true, HXXRET2a(HXXRET1(MAKE_WRITABLE_FAILED))) 
	return (o_->Erase<KEY>(std::forward<KEY>(key)));
}
template <typename S> template <typename T, typename KEY> MAXON_ATTRIBUTE_FORCE_INLINE auto DataDictionaryInterface::Hxx1::ConstFn<S>::GetCopy(KEY&& key, T& dst) const -> Result<void>
{
	HXXRETURN0(Result<void>); HXXRES; HXXCONST(HXXRET1(NULLPTR)) 
	return (o_->GetCopy<T, KEY>(std::forward<KEY>(key), dst));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto DataDictionaryInterface::Hxx1::ConstFn<S>::InitIterator(DataDictionaryIteratorInterface* iterator, Bool end) const -> HXXADDRET2(void)
{
	HXXRETURN0(HXXADDRET2(void)); HXXRES; HXXCONST(maxon::PrivateLogNullptrError()) 
	PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.DataDictionaryInterface_InitIterator, iterator, end);
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto DataDictionaryInterface::Hxx1::ConstFn<S>::Begin() const -> HXXADDRET2(ConstIterator)
{
	HXXRETURN0(HXXADDRET2(ConstIterator)); HXXRES; HXXCONST(HXXRET3(NULLPTR, ConstIterator)) 
	return (o_->Begin());
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto DataDictionaryInterface::Hxx1::ConstFn<S>::End() const -> HXXADDRET2(ConstIterator)
{
	HXXRETURN0(HXXADDRET2(ConstIterator)); HXXRES; HXXCONST(HXXRET3(NULLPTR, ConstIterator)) 
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
#endif

#ifdef MAXON_COMPILER_GCC
	#pragma GCC diagnostic pop
#endif

#endif

