
#ifndef DOXYGEN

#ifdef MAXON_COMPILER_GCC
	#pragma GCC diagnostic push
	#pragma GCC diagnostic ignored "-Wmisleading-indentation"
#endif

#if 1
#ifdef MAXON_COMPILER_INTEL
#endif
#ifdef MAXON_COMPILER_INTEL
#endif
#ifdef CPP_853_HACK
#ifdef MAXON_COMPILER_GCC
#else
#endif
#endif
#ifdef CPP_853_HACK
#endif

template <typename TYPE> struct ArrayInterface<TYPE>::MTable
{
	MTable() { }
	template <typename C> explicit MTable(C*) { Init<Wrapper<C>>(this); }
	template <typename C> MTable(C*, maxon::Bool) { Init<C>(this); }
	void (*_ArrayInterface_Free) (const ArrayInterface* object);
	Int (*_ArrayInterface_GetCount) (const ArrayInterface* this_);
	const TYPE& (*_ArrayInterface_operatorIndex) (const ArrayInterface* this_, Int index);
	Int (*_ArrayInterface_GetBlock) (const ArrayInterface* this_, Int index, Block<const TYPE, false>& block);
	Int (*_ArrayInterface_GetBlock_1) (const ArrayInterface* this_, Int index, StridedBlock<const TYPE>& block);
	ResultMem (*_ArrayInterface_Resize) (ArrayInterface* this_, Int count, COLLECTION_RESIZE_FLAGS resizeFlags);
	ResultMem (*_ArrayInterface_SetCapacityHint) (ArrayInterface* this_, Int requestedCapacity, COLLECTION_RESIZE_FLAGS resizeFlags);
	ResultRef<TYPE> (*_ArrayInterface_Insert) (ArrayInterface* this_, Int index);
	ResultMem (*_ArrayInterface_Insert_1) (ArrayInterface* this_, Int index, const Block<const ValueType>& values);
	ResultMem (*_ArrayInterface_Insert_2) (ArrayInterface* this_, Int index, const MoveBlock<ValueType>& values);
	ResultRef<TYPE> (*_ArrayInterface_Append) (ArrayInterface* this_);
	ResultMem (*_ArrayInterface_Erase) (ArrayInterface* this_, Int index, Int count);
	ResultMem (*_ArrayInterface_SwapErase) (ArrayInterface* this_, Int index, Int count);
	void (*_ArrayInterface_Reset) (ArrayInterface* this_);
	void (*_ArrayInterface_Flush) (ArrayInterface* this_);
	Result<void> (*_ArrayInterface_CopyFrom) (ArrayInterface* this_, const ArrayInterface& other);
	Result<ArrayInterface*> (*_ArrayInterface_Clone) (const ArrayInterface* this_, Bool cloneElements);
	const DataType* (*_ArrayInterface_GetValueDataType) (const ArrayInterface* this_);
	String (*_ArrayInterface_ToString) (const ArrayInterface* this_, const FormatStatement* formatStatement);
	Int (*_ArrayInterface_GetMemorySize) (const ArrayInterface* this_);
	Bool (*_ArrayInterface_IsEqual) (const ArrayInterface* this_, const ArrayInterface* other, EQUALITY equality);
	UInt (*_ArrayInterface_GetHashCode) (const ArrayInterface* this_);
#ifdef MAXON_COMPILER_INTEL
#endif
#ifdef MAXON_COMPILER_INTEL
#endif
#ifdef CPP_853_HACK
#ifdef MAXON_COMPILER_GCC
#else
#endif
#endif
#ifdef CPP_853_HACK
#endif
	template <typename IMPL> static void Init(MTable* tbl)
	{
		tbl->_ArrayInterface_Free = &IMPL::_ArrayInterface_Free;
		tbl->_ArrayInterface_GetCount = &IMPL::_ArrayInterface_GetCount;
		tbl->_ArrayInterface_operatorIndex = &IMPL::_ArrayInterface_operatorIndex;
		tbl->_ArrayInterface_GetBlock = &IMPL::_ArrayInterface_GetBlock;
		tbl->_ArrayInterface_GetBlock_1 = &IMPL::_ArrayInterface_GetBlock_1;
		tbl->_ArrayInterface_Resize = &IMPL::_ArrayInterface_Resize;
		tbl->_ArrayInterface_SetCapacityHint = &IMPL::_ArrayInterface_SetCapacityHint;
		tbl->_ArrayInterface_Insert = &IMPL::_ArrayInterface_Insert;
		tbl->_ArrayInterface_Insert_1 = &IMPL::_ArrayInterface_Insert_1;
		tbl->_ArrayInterface_Insert_2 = &IMPL::_ArrayInterface_Insert_2;
		tbl->_ArrayInterface_Append = &IMPL::_ArrayInterface_Append;
		tbl->_ArrayInterface_Erase = &IMPL::_ArrayInterface_Erase;
		tbl->_ArrayInterface_SwapErase = &IMPL::_ArrayInterface_SwapErase;
		tbl->_ArrayInterface_Reset = &IMPL::_ArrayInterface_Reset;
		tbl->_ArrayInterface_Flush = &IMPL::_ArrayInterface_Flush;
		tbl->_ArrayInterface_CopyFrom = &IMPL::_ArrayInterface_CopyFrom;
		tbl->_ArrayInterface_Clone = &IMPL::_ArrayInterface_Clone;
		tbl->_ArrayInterface_GetValueDataType = &IMPL::_ArrayInterface_GetValueDataType;
		tbl->_ArrayInterface_ToString = &IMPL::_ArrayInterface_ToString;
		tbl->_ArrayInterface_GetMemorySize = &IMPL::_ArrayInterface_GetMemorySize;
		tbl->_ArrayInterface_IsEqual = &IMPL::_ArrayInterface_IsEqual;
		tbl->_ArrayInterface_GetHashCode = &IMPL::_ArrayInterface_GetHashCode;
#ifdef MAXON_COMPILER_INTEL
#endif
#ifdef MAXON_COMPILER_INTEL
#endif
#ifdef CPP_853_HACK
#ifdef MAXON_COMPILER_GCC
#else
#endif
#endif
#ifdef CPP_853_HACK
#endif
	}
};

template <typename TYPE> template <typename C> class ArrayInterface<TYPE>::Wrapper
{
public:
	static void _ArrayInterface_Free(const ArrayInterface* object) { return C::Free((const C*) object); }
	static Int _ArrayInterface_GetCount(const ArrayInterface* this_) { return ((const C*) this_)->GetCount(); }
	static const TYPE& _ArrayInterface_operatorIndex(const ArrayInterface* this_, Int index) { return ((const C*) this_)->operator [](index); }
	static Int _ArrayInterface_GetBlock(const ArrayInterface* this_, Int index, Block<const TYPE, false>& block) { return ((const C*) this_)->GetBlock(index, block); }
	static Int _ArrayInterface_GetBlock_1(const ArrayInterface* this_, Int index, StridedBlock<const TYPE>& block) { return ((const C*) this_)->GetBlock(index, block); }
	static ResultMem _ArrayInterface_Resize(ArrayInterface* this_, Int count, COLLECTION_RESIZE_FLAGS resizeFlags) { return ((C*) this_)->Resize(count, resizeFlags); }
	static ResultMem _ArrayInterface_SetCapacityHint(ArrayInterface* this_, Int requestedCapacity, COLLECTION_RESIZE_FLAGS resizeFlags) { return ((C*) this_)->SetCapacityHint(requestedCapacity, resizeFlags); }
	static ResultRef<TYPE> _ArrayInterface_Insert(ArrayInterface* this_, Int index) { return ((C*) this_)->Insert(index); }
	static ResultMem _ArrayInterface_Insert_1(ArrayInterface* this_, Int index, const Block<const ValueType>& values) { return ((C*) this_)->Insert(index, values); }
	static ResultMem _ArrayInterface_Insert_2(ArrayInterface* this_, Int index, const MoveBlock<ValueType>& values) { return ((C*) this_)->Insert(index, values); }
	static ResultRef<TYPE> _ArrayInterface_Append(ArrayInterface* this_) { return ((C*) this_)->Append(); }
	static ResultMem _ArrayInterface_Erase(ArrayInterface* this_, Int index, Int count) { return ((C*) this_)->Erase(index, count); }
	static ResultMem _ArrayInterface_SwapErase(ArrayInterface* this_, Int index, Int count) { return ((C*) this_)->SwapErase(index, count); }
	static void _ArrayInterface_Reset(ArrayInterface* this_) { return ((C*) this_)->Reset(); }
	static void _ArrayInterface_Flush(ArrayInterface* this_) { return ((C*) this_)->Flush(); }
	static Result<void> _ArrayInterface_CopyFrom(ArrayInterface* this_, const ArrayInterface& other) { return ((C*) this_)->CopyFrom(other); }
	static Result<ArrayInterface*> _ArrayInterface_Clone(const ArrayInterface* this_, Bool cloneElements) { return ((const C*) this_)->Clone(cloneElements); }
	static const DataType* _ArrayInterface_GetValueDataType(const ArrayInterface* this_) { return ((const C*) this_)->GetValueDataType(); }
	static String _ArrayInterface_ToString(const ArrayInterface* this_, const FormatStatement* formatStatement) { return ((const C*) this_)->ToString(formatStatement); }
	static Int _ArrayInterface_GetMemorySize(const ArrayInterface* this_) { return ((const C*) this_)->GetMemorySize(); }
	static Bool _ArrayInterface_IsEqual(const ArrayInterface* this_, const ArrayInterface* other, EQUALITY equality) { return ((const C*) this_)->IsEqual(other, equality); }
	static UInt _ArrayInterface_GetHashCode(const ArrayInterface* this_) { return ((const C*) this_)->GetHashCode(); }
#ifdef MAXON_COMPILER_INTEL
#endif
#ifdef MAXON_COMPILER_INTEL
#endif
#ifdef CPP_853_HACK
#ifdef MAXON_COMPILER_GCC
#else
#endif
#endif
#ifdef CPP_853_HACK
#endif
};

template <typename TYPE> MAXON_ATTRIBUTE_FORCE_INLINE auto ArrayInterface<TYPE>::Free(const ArrayInterface* object) -> void
{
	if (!object)
		return;
	return ((MTable*) object->_vtable)->_ArrayInterface_Free(object);
}
template <typename TYPE> MAXON_ATTRIBUTE_FORCE_INLINE auto ArrayInterface<TYPE>::GetCount() const -> Int
{
	return ((MTable*) this->_vtable)->_ArrayInterface_GetCount(this);
}
template <typename TYPE> MAXON_ATTRIBUTE_FORCE_INLINE auto ArrayInterface<TYPE>::operator [](Int index) const -> const TYPE&
{
	return ((MTable*) this->_vtable)->_ArrayInterface_operatorIndex(this, index);
}
template <typename TYPE> MAXON_ATTRIBUTE_FORCE_INLINE auto ArrayInterface<TYPE>::GetBlock(Int index, Block<const TYPE, false>& block) const -> Int
{
	return ((MTable*) this->_vtable)->_ArrayInterface_GetBlock(this, index, block);
}
template <typename TYPE> MAXON_ATTRIBUTE_FORCE_INLINE auto ArrayInterface<TYPE>::GetBlock(Int index, StridedBlock<const TYPE>& block) const -> Int
{
	return ((MTable*) this->_vtable)->_ArrayInterface_GetBlock_1(this, index, block);
}
template <typename TYPE> MAXON_ATTRIBUTE_FORCE_INLINE auto ArrayInterface<TYPE>::Resize(Int count, COLLECTION_RESIZE_FLAGS resizeFlags) -> ResultMem
{
	return ((MTable*) this->_vtable)->_ArrayInterface_Resize(this, count, resizeFlags);
}
template <typename TYPE> MAXON_ATTRIBUTE_FORCE_INLINE auto ArrayInterface<TYPE>::SetCapacityHint(Int requestedCapacity, COLLECTION_RESIZE_FLAGS resizeFlags) -> ResultMem
{
	return ((MTable*) this->_vtable)->_ArrayInterface_SetCapacityHint(this, requestedCapacity, resizeFlags);
}
template <typename TYPE> MAXON_ATTRIBUTE_FORCE_INLINE auto ArrayInterface<TYPE>::Insert(Int index) -> ResultRef<TYPE>
{
	return ((MTable*) this->_vtable)->_ArrayInterface_Insert(this, index);
}
template <typename TYPE> MAXON_ATTRIBUTE_FORCE_INLINE auto ArrayInterface<TYPE>::Insert(Int index, const Block<const ValueType>& values) -> ResultMem
{
	return ((MTable*) this->_vtable)->_ArrayInterface_Insert_1(this, index, values);
}
template <typename TYPE> MAXON_ATTRIBUTE_FORCE_INLINE auto ArrayInterface<TYPE>::Insert(Int index, const MoveBlock<ValueType>& values) -> ResultMem
{
	return ((MTable*) this->_vtable)->_ArrayInterface_Insert_2(this, index, values);
}
template <typename TYPE> MAXON_ATTRIBUTE_FORCE_INLINE auto ArrayInterface<TYPE>::Append() -> ResultRef<TYPE>
{
	return ((MTable*) this->_vtable)->_ArrayInterface_Append(this);
}
template <typename TYPE> MAXON_ATTRIBUTE_FORCE_INLINE auto ArrayInterface<TYPE>::Erase(Int index, Int count) -> ResultMem
{
	return ((MTable*) this->_vtable)->_ArrayInterface_Erase(this, index, count);
}
template <typename TYPE> MAXON_ATTRIBUTE_FORCE_INLINE auto ArrayInterface<TYPE>::SwapErase(Int index, Int count) -> ResultMem
{
	return ((MTable*) this->_vtable)->_ArrayInterface_SwapErase(this, index, count);
}
template <typename TYPE> MAXON_ATTRIBUTE_FORCE_INLINE auto ArrayInterface<TYPE>::Reset() -> void
{
	return ((MTable*) this->_vtable)->_ArrayInterface_Reset(this);
}
template <typename TYPE> MAXON_ATTRIBUTE_FORCE_INLINE auto ArrayInterface<TYPE>::Flush() -> void
{
	return ((MTable*) this->_vtable)->_ArrayInterface_Flush(this);
}
template <typename TYPE> MAXON_ATTRIBUTE_FORCE_INLINE auto ArrayInterface<TYPE>::CopyFrom(const ArrayInterface& other) -> Result<void>
{
	return ((MTable*) this->_vtable)->_ArrayInterface_CopyFrom(this, other);
}
template <typename TYPE> MAXON_ATTRIBUTE_FORCE_INLINE auto ArrayInterface<TYPE>::Clone(Bool cloneElements) const -> Result<ArrayInterface*>
{
	return ((MTable*) this->_vtable)->_ArrayInterface_Clone(this, cloneElements);
}
template <typename TYPE> MAXON_ATTRIBUTE_FORCE_INLINE auto ArrayInterface<TYPE>::GetValueDataType() const -> const DataType*
{
	return ((MTable*) this->_vtable)->_ArrayInterface_GetValueDataType(this);
}
template <typename TYPE> MAXON_ATTRIBUTE_FORCE_INLINE auto ArrayInterface<TYPE>::ToString(const FormatStatement* formatStatement) const -> String
{
	return ((MTable*) this->_vtable)->_ArrayInterface_ToString(this, formatStatement);
}
template <typename TYPE> MAXON_ATTRIBUTE_FORCE_INLINE auto ArrayInterface<TYPE>::GetMemorySize() const -> Int
{
	return ((MTable*) this->_vtable)->_ArrayInterface_GetMemorySize(this);
}
template <typename TYPE> MAXON_ATTRIBUTE_FORCE_INLINE auto ArrayInterface<TYPE>::IsEqual(const ArrayInterface* other, EQUALITY equality) const -> Bool
{
	return ((MTable*) this->_vtable)->_ArrayInterface_IsEqual(this, other, equality);
}
template <typename TYPE> MAXON_ATTRIBUTE_FORCE_INLINE auto ArrayInterface<TYPE>::GetHashCode() const -> UInt
{
	return ((MTable*) this->_vtable)->_ArrayInterface_GetHashCode(this);
}
#ifdef MAXON_COMPILER_INTEL
#endif
#ifdef MAXON_COMPILER_INTEL
#endif
#ifdef CPP_853_HACK
#ifdef MAXON_COMPILER_GCC
#else
#endif
#endif
#ifdef CPP_853_HACK
#endif

template <typename TYPE> template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ArrayInterface<TYPE>::ConstReferenceFunctionsImpl<S>::GetCount() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, false, typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const ArrayInterface* o_ = (const ArrayInterface*) this->GetPointer(); if (!(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS) && MAXON_UNLIKELY(!o_)) { o_ = ArrayInterface::NullValuePtr(); if (!o_) return 0; } 
	return (((MTable*) o_->_vtable)->_ArrayInterface_GetCount(o_));
}
template <typename TYPE> template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ArrayInterface<TYPE>::ConstReferenceFunctionsImpl<S>::IsEmpty() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, false, typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const ArrayInterface* o_ = (const ArrayInterface*) this->GetPointer(); if (!(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS) && MAXON_UNLIKELY(!o_)) { o_ = ArrayInterface::NullValuePtr(); if (!o_) return true; } 
	return (o_->IsEmpty());
}
template <typename TYPE> template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ArrayInterface<TYPE>::ConstReferenceFunctionsImpl<S>::IsPopulated() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, false, typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const ArrayInterface* o_ = (const ArrayInterface*) this->GetPointer(); if (!(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS) && MAXON_UNLIKELY(!o_)) { o_ = ArrayInterface::NullValuePtr(); if (!o_) return maxon::PrivateLogNullptrError(false); } 
	return (o_->IsPopulated());
}
template <typename TYPE> template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ArrayInterface<TYPE>::ConstReferenceFunctionsImpl<S>::operator [](Int index) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<const TYPE&>, const TYPE&>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, false, typename std::conditional<S::HAS_ERROR, maxon::Result<const TYPE&>, const TYPE&>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const ArrayInterface* o_ = (const ArrayInterface*) this->GetPointer(); if (!(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS) && MAXON_UNLIKELY(!o_)) { o_ = ArrayInterface::NullValuePtr(); if (!o_) return maxon::PrivateNullReturnValue<const TYPE&>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } 
	return (((MTable*) o_->_vtable)->_ArrayInterface_operatorIndex(o_, index));
}
template <typename TYPE> template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ArrayInterface<TYPE>::COWReferenceFunctionsImpl<S>::GetWritable(Int index) -> typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), TYPE&, maxon::Result<TYPE&>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, false, typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), TYPE&, maxon::Result<TYPE&>>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); ArrayInterface* o_ = (ArrayInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS) && MAXON_UNLIKELY(!o_)) return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); 
	return (o_->operator [](index));
}
template <typename TYPE> template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ArrayInterface<TYPE>::ReferenceFunctionsImpl<S>::Set(Int index, TYPE&& value) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, false, typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); ArrayInterface* o_ = (ArrayInterface*) this->GetPointer(); if (MAXON_UNLIKELY(!o_)) return maxon::PrivateLogNullptrError(); 
	o_->Set(index, std::forward<TYPE>(value));
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
template <typename TYPE> template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ArrayInterface<TYPE>::COWReferenceFunctionsImpl<S>::Set(Int index, TYPE&& value) -> typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), void, maxon::Result<void>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, false, typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), void, maxon::Result<void>>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); ArrayInterface* o_ = (ArrayInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS) && MAXON_UNLIKELY(!o_)) return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); 
	o_->Set(index, std::forward<TYPE>(value));
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
template <typename TYPE> template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ArrayInterface<TYPE>::ConstReferenceFunctionsImpl<S>::GetBlock(Int index, Block<const TYPE, false>& block) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, false, typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const ArrayInterface* o_ = (const ArrayInterface*) this->GetPointer(); if (!(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS) && MAXON_UNLIKELY(!o_)) { o_ = ArrayInterface::NullValuePtr(); if (!o_) return 0; } 
	return (((MTable*) o_->_vtable)->_ArrayInterface_GetBlock(o_, index, block));
}
template <typename TYPE> template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ArrayInterface<TYPE>::ReferenceFunctionsImpl<S>::GetBlock(Int index, Block<TYPE, false>& block) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, false, typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); ArrayInterface* o_ = (ArrayInterface*) this->GetPointer(); if (MAXON_UNLIKELY(!o_)) return 0; 
	return (o_->GetBlock(index, block));
}
template <typename TYPE> template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ArrayInterface<TYPE>::COWReferenceFunctionsImpl<S>::GetWritableBlock(Int index, Block<TYPE, false>& block) -> typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), Int, maxon::Result<Int>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, false, typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), Int, maxon::Result<Int>>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); ArrayInterface* o_ = (ArrayInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS) && MAXON_UNLIKELY(!o_)) return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); 
	return (o_->GetBlock(index, block));
}
template <typename TYPE> template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ArrayInterface<TYPE>::ConstReferenceFunctionsImpl<S>::GetBlock(Int index, StridedBlock<const TYPE>& block) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, false, typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const ArrayInterface* o_ = (const ArrayInterface*) this->GetPointer(); if (!(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS) && MAXON_UNLIKELY(!o_)) { o_ = ArrayInterface::NullValuePtr(); if (!o_) return 0; } 
	return (((MTable*) o_->_vtable)->_ArrayInterface_GetBlock_1(o_, index, block));
}
template <typename TYPE> template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ArrayInterface<TYPE>::ReferenceFunctionsImpl<S>::GetBlock(Int index, StridedBlock<TYPE>& block) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, false, typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); ArrayInterface* o_ = (ArrayInterface*) this->GetPointer(); if (MAXON_UNLIKELY(!o_)) return 0; 
	return (o_->GetBlock(index, block));
}
template <typename TYPE> template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ArrayInterface<TYPE>::COWReferenceFunctionsImpl<S>::GetWritableBlock(Int index, StridedBlock<TYPE>& block) -> typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), Int, maxon::Result<Int>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, false, typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), Int, maxon::Result<Int>>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); ArrayInterface* o_ = (ArrayInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS) && MAXON_UNLIKELY(!o_)) return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); 
	return (o_->GetBlock(index, block));
}
template <typename TYPE> template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ArrayInterface<TYPE>::ReferenceFunctionsImpl<S>::Resize(Int count, COLLECTION_RESIZE_FLAGS resizeFlags) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<void>, ResultMem>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, false, typename std::conditional<S::HAS_ERROR, maxon::Result<void>, ResultMem>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); ArrayInterface* o_ = (ArrayInterface*) this->GetPointer(); if (MAXON_UNLIKELY(!o_)) return maxon::PrivateNullReturnValue<ResultMem>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); 
	return (((MTable*) o_->_vtable)->_ArrayInterface_Resize(o_, count, resizeFlags));
}
template <typename TYPE> template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ArrayInterface<TYPE>::COWReferenceFunctionsImpl<S>::Resize(Int count, COLLECTION_RESIZE_FLAGS resizeFlags) -> typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), ResultMem, maxon::Result<void>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, false, typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), ResultMem, maxon::Result<void>>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); ArrayInterface* o_ = (ArrayInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS) && MAXON_UNLIKELY(!o_)) return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); 
	return (((MTable*) o_->_vtable)->_ArrayInterface_Resize(o_, count, resizeFlags));
}
template <typename TYPE> template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ArrayInterface<TYPE>::ReferenceFunctionsImpl<S>::SetCapacityHint(Int requestedCapacity, COLLECTION_RESIZE_FLAGS resizeFlags) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<void>, ResultMem>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, false, typename std::conditional<S::HAS_ERROR, maxon::Result<void>, ResultMem>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); ArrayInterface* o_ = (ArrayInterface*) this->GetPointer(); if (MAXON_UNLIKELY(!o_)) return maxon::PrivateNullReturnValue<ResultMem>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); 
	return (((MTable*) o_->_vtable)->_ArrayInterface_SetCapacityHint(o_, requestedCapacity, resizeFlags));
}
template <typename TYPE> template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ArrayInterface<TYPE>::COWReferenceFunctionsImpl<S>::SetCapacityHint(Int requestedCapacity, COLLECTION_RESIZE_FLAGS resizeFlags) -> typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), ResultMem, maxon::Result<void>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, false, typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), ResultMem, maxon::Result<void>>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); ArrayInterface* o_ = (ArrayInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS) && MAXON_UNLIKELY(!o_)) return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); 
	return (((MTable*) o_->_vtable)->_ArrayInterface_SetCapacityHint(o_, requestedCapacity, resizeFlags));
}
template <typename TYPE> template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ArrayInterface<TYPE>::ReferenceFunctionsImpl<S>::Insert(Int index) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<TYPE&>, ResultRef<TYPE>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, false, typename std::conditional<S::HAS_ERROR, maxon::Result<TYPE&>, ResultRef<TYPE>>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); ArrayInterface* o_ = (ArrayInterface*) this->GetPointer(); if (MAXON_UNLIKELY(!o_)) return maxon::PrivateNullReturnValue<ResultRef<TYPE>>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); 
	return (((MTable*) o_->_vtable)->_ArrayInterface_Insert(o_, index));
}
template <typename TYPE> template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ArrayInterface<TYPE>::COWReferenceFunctionsImpl<S>::Insert(Int index) -> typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), ResultRef<TYPE>, maxon::Result<TYPE&>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, false, typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), ResultRef<TYPE>, maxon::Result<TYPE&>>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); ArrayInterface* o_ = (ArrayInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS) && MAXON_UNLIKELY(!o_)) return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); 
	return (((MTable*) o_->_vtable)->_ArrayInterface_Insert(o_, index));
}
template <typename TYPE> template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ArrayInterface<TYPE>::ReferenceFunctionsImpl<S>::Insert(Int index, const TYPE& data) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<TYPE&>, ResultRef<TYPE>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, false, typename std::conditional<S::HAS_ERROR, maxon::Result<TYPE&>, ResultRef<TYPE>>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); ArrayInterface* o_ = (ArrayInterface*) this->GetPointer(); if (MAXON_UNLIKELY(!o_)) return maxon::PrivateNullReturnValue<ResultRef<TYPE>>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); 
	return (o_->Insert(index, data));
}
template <typename TYPE> template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ArrayInterface<TYPE>::COWReferenceFunctionsImpl<S>::Insert(Int index, const TYPE& data) -> typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), ResultRef<TYPE>, maxon::Result<TYPE&>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, false, typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), ResultRef<TYPE>, maxon::Result<TYPE&>>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); ArrayInterface* o_ = (ArrayInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS) && MAXON_UNLIKELY(!o_)) return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); 
	return (o_->Insert(index, data));
}
template <typename TYPE> template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ArrayInterface<TYPE>::ReferenceFunctionsImpl<S>::Insert(Int index, NonConstValueType&& data) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<TYPE&>, ResultRef<TYPE>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, false, typename std::conditional<S::HAS_ERROR, maxon::Result<TYPE&>, ResultRef<TYPE>>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); ArrayInterface* o_ = (ArrayInterface*) this->GetPointer(); if (MAXON_UNLIKELY(!o_)) return maxon::PrivateNullReturnValue<ResultRef<TYPE>>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); 
	return (o_->Insert(index, std::forward<NonConstValueType>(data)));
}
template <typename TYPE> template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ArrayInterface<TYPE>::COWReferenceFunctionsImpl<S>::Insert(Int index, NonConstValueType&& data) -> typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), ResultRef<TYPE>, maxon::Result<TYPE&>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, false, typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), ResultRef<TYPE>, maxon::Result<TYPE&>>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); ArrayInterface* o_ = (ArrayInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS) && MAXON_UNLIKELY(!o_)) return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); 
	return (o_->Insert(index, std::forward<NonConstValueType>(data)));
}
template <typename TYPE> template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ArrayInterface<TYPE>::ReferenceFunctionsImpl<S>::Insert(Int index, const Block<const ValueType>& values) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<void>, ResultMem>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, false, typename std::conditional<S::HAS_ERROR, maxon::Result<void>, ResultMem>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); ArrayInterface* o_ = (ArrayInterface*) this->GetPointer(); if (MAXON_UNLIKELY(!o_)) return maxon::PrivateNullReturnValue<ResultMem>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); 
	return (((MTable*) o_->_vtable)->_ArrayInterface_Insert_1(o_, index, values));
}
template <typename TYPE> template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ArrayInterface<TYPE>::COWReferenceFunctionsImpl<S>::Insert(Int index, const Block<const ValueType>& values) -> typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), ResultMem, maxon::Result<void>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, false, typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), ResultMem, maxon::Result<void>>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); ArrayInterface* o_ = (ArrayInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS) && MAXON_UNLIKELY(!o_)) return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); 
	return (((MTable*) o_->_vtable)->_ArrayInterface_Insert_1(o_, index, values));
}
template <typename TYPE> template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ArrayInterface<TYPE>::ReferenceFunctionsImpl<S>::Insert(Int index, const MoveBlock<ValueType>& values) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<void>, ResultMem>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, false, typename std::conditional<S::HAS_ERROR, maxon::Result<void>, ResultMem>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); ArrayInterface* o_ = (ArrayInterface*) this->GetPointer(); if (MAXON_UNLIKELY(!o_)) return maxon::PrivateNullReturnValue<ResultMem>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); 
	return (((MTable*) o_->_vtable)->_ArrayInterface_Insert_2(o_, index, values));
}
template <typename TYPE> template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ArrayInterface<TYPE>::COWReferenceFunctionsImpl<S>::Insert(Int index, const MoveBlock<ValueType>& values) -> typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), ResultMem, maxon::Result<void>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, false, typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), ResultMem, maxon::Result<void>>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); ArrayInterface* o_ = (ArrayInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS) && MAXON_UNLIKELY(!o_)) return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); 
	return (((MTable*) o_->_vtable)->_ArrayInterface_Insert_2(o_, index, values));
}
template <typename TYPE> template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ArrayInterface<TYPE>::ReferenceFunctionsImpl<S>::Append() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<TYPE&>, ResultRef<TYPE>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, false, typename std::conditional<S::HAS_ERROR, maxon::Result<TYPE&>, ResultRef<TYPE>>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); ArrayInterface* o_ = (ArrayInterface*) this->GetPointer(); if (MAXON_UNLIKELY(!o_)) return maxon::PrivateNullReturnValue<ResultRef<TYPE>>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); 
	return (((MTable*) o_->_vtable)->_ArrayInterface_Append(o_));
}
template <typename TYPE> template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ArrayInterface<TYPE>::COWReferenceFunctionsImpl<S>::Append() -> typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), ResultRef<TYPE>, maxon::Result<TYPE&>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, false, typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), ResultRef<TYPE>, maxon::Result<TYPE&>>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); ArrayInterface* o_ = (ArrayInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS) && MAXON_UNLIKELY(!o_)) return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); 
	return (((MTable*) o_->_vtable)->_ArrayInterface_Append(o_));
}
template <typename TYPE> template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ArrayInterface<TYPE>::ReferenceFunctionsImpl<S>::Append(const TYPE& data) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<TYPE&>, ResultRef<TYPE>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, false, typename std::conditional<S::HAS_ERROR, maxon::Result<TYPE&>, ResultRef<TYPE>>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); ArrayInterface* o_ = (ArrayInterface*) this->GetPointer(); if (MAXON_UNLIKELY(!o_)) return maxon::PrivateNullReturnValue<ResultRef<TYPE>>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); 
	return (o_->Append(data));
}
template <typename TYPE> template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ArrayInterface<TYPE>::COWReferenceFunctionsImpl<S>::Append(const TYPE& data) -> typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), ResultRef<TYPE>, maxon::Result<TYPE&>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, false, typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), ResultRef<TYPE>, maxon::Result<TYPE&>>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); ArrayInterface* o_ = (ArrayInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS) && MAXON_UNLIKELY(!o_)) return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); 
	return (o_->Append(data));
}
template <typename TYPE> template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ArrayInterface<TYPE>::ReferenceFunctionsImpl<S>::Append(NonConstValueType&& data) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<TYPE&>, ResultRef<TYPE>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, false, typename std::conditional<S::HAS_ERROR, maxon::Result<TYPE&>, ResultRef<TYPE>>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); ArrayInterface* o_ = (ArrayInterface*) this->GetPointer(); if (MAXON_UNLIKELY(!o_)) return maxon::PrivateNullReturnValue<ResultRef<TYPE>>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); 
	return (o_->Append(std::forward<NonConstValueType>(data)));
}
template <typename TYPE> template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ArrayInterface<TYPE>::COWReferenceFunctionsImpl<S>::Append(NonConstValueType&& data) -> typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), ResultRef<TYPE>, maxon::Result<TYPE&>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, false, typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), ResultRef<TYPE>, maxon::Result<TYPE&>>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); ArrayInterface* o_ = (ArrayInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS) && MAXON_UNLIKELY(!o_)) return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); 
	return (o_->Append(std::forward<NonConstValueType>(data)));
}
template <typename TYPE> template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ArrayInterface<TYPE>::ReferenceFunctionsImpl<S>::Pop() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, false, typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); ArrayInterface* o_ = (ArrayInterface*) this->GetPointer(); if (MAXON_UNLIKELY(!o_)) return maxon::PrivateLogNullptrError(false); 
	return (o_->Pop());
}
template <typename TYPE> template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ArrayInterface<TYPE>::COWReferenceFunctionsImpl<S>::Pop() -> typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), Bool, maxon::Result<Bool>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, false, typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), Bool, maxon::Result<Bool>>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); ArrayInterface* o_ = (ArrayInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS) && MAXON_UNLIKELY(!o_)) return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); 
	return (o_->Pop());
}
template <typename TYPE> template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ArrayInterface<TYPE>::ReferenceFunctionsImpl<S>::Pop(TYPE* dst) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, false, typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); ArrayInterface* o_ = (ArrayInterface*) this->GetPointer(); if (MAXON_UNLIKELY(!o_)) return maxon::PrivateLogNullptrError(false); 
	return (o_->Pop(dst));
}
template <typename TYPE> template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ArrayInterface<TYPE>::COWReferenceFunctionsImpl<S>::Pop(TYPE* dst) -> typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), Bool, maxon::Result<Bool>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, false, typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), Bool, maxon::Result<Bool>>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); ArrayInterface* o_ = (ArrayInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS) && MAXON_UNLIKELY(!o_)) return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); 
	return (o_->Pop(dst));
}
template <typename TYPE> template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ArrayInterface<TYPE>::ReferenceFunctionsImpl<S>::Erase(Int index, Int count) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<void>, ResultMem>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, false, typename std::conditional<S::HAS_ERROR, maxon::Result<void>, ResultMem>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); ArrayInterface* o_ = (ArrayInterface*) this->GetPointer(); if (MAXON_UNLIKELY(!o_)) return maxon::PrivateNullReturnValue<ResultMem>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); 
	return (((MTable*) o_->_vtable)->_ArrayInterface_Erase(o_, index, count));
}
template <typename TYPE> template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ArrayInterface<TYPE>::COWReferenceFunctionsImpl<S>::Erase(Int index, Int count) -> typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), ResultMem, maxon::Result<void>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, false, typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), ResultMem, maxon::Result<void>>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); ArrayInterface* o_ = (ArrayInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS) && MAXON_UNLIKELY(!o_)) return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); 
	return (((MTable*) o_->_vtable)->_ArrayInterface_Erase(o_, index, count));
}
template <typename TYPE> template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ArrayInterface<TYPE>::ReferenceFunctionsImpl<S>::SwapErase(Int index, Int count) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<void>, ResultMem>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, false, typename std::conditional<S::HAS_ERROR, maxon::Result<void>, ResultMem>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); ArrayInterface* o_ = (ArrayInterface*) this->GetPointer(); if (MAXON_UNLIKELY(!o_)) return maxon::PrivateNullReturnValue<ResultMem>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); 
	return (((MTable*) o_->_vtable)->_ArrayInterface_SwapErase(o_, index, count));
}
template <typename TYPE> template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ArrayInterface<TYPE>::COWReferenceFunctionsImpl<S>::SwapErase(Int index, Int count) -> typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), ResultMem, maxon::Result<void>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, false, typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), ResultMem, maxon::Result<void>>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); ArrayInterface* o_ = (ArrayInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS) && MAXON_UNLIKELY(!o_)) return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); 
	return (((MTable*) o_->_vtable)->_ArrayInterface_SwapErase(o_, index, count));
}
template <typename TYPE> template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ArrayInterface<TYPE>::ReferenceFunctionsImpl<S>::Reset() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, false, typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); ArrayInterface* o_ = (ArrayInterface*) this->GetPointer(); if (MAXON_UNLIKELY(!o_)) return maxon::PrivateLogNullptrError(); 
	((MTable*) o_->_vtable)->_ArrayInterface_Reset(o_);
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
template <typename TYPE> template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ArrayInterface<TYPE>::COWReferenceFunctionsImpl<S>::Reset() -> typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), void, maxon::Result<void>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, false, typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), void, maxon::Result<void>>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); ArrayInterface* o_ = (ArrayInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS) && MAXON_UNLIKELY(!o_)) return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); 
	((MTable*) o_->_vtable)->_ArrayInterface_Reset(o_);
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
template <typename TYPE> template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ArrayInterface<TYPE>::ReferenceFunctionsImpl<S>::Flush() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, false, typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); ArrayInterface* o_ = (ArrayInterface*) this->GetPointer(); if (MAXON_UNLIKELY(!o_)) return maxon::PrivateLogNullptrError(); 
	((MTable*) o_->_vtable)->_ArrayInterface_Flush(o_);
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
template <typename TYPE> template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ArrayInterface<TYPE>::COWReferenceFunctionsImpl<S>::Flush() -> typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), void, maxon::Result<void>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, false, typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), void, maxon::Result<void>>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); ArrayInterface* o_ = (ArrayInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS) && MAXON_UNLIKELY(!o_)) return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); 
	((MTable*) o_->_vtable)->_ArrayInterface_Flush(o_);
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
template <typename TYPE> template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ArrayInterface<TYPE>::ReferenceFunctionsImpl<S>::CopyFrom(const ArrayInterface& other) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); ArrayInterface* o_ = (ArrayInterface*) this->GetPointer(); if (MAXON_UNLIKELY(!o_)) return maxon::PrivateNullReturnValue<Result<void>>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); 
	return (((MTable*) o_->_vtable)->_ArrayInterface_CopyFrom(o_, other));
}
template <typename TYPE> template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ArrayInterface<TYPE>::COWReferenceFunctionsImpl<S>::CopyFrom(const ArrayInterface& other) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); ArrayInterface* o_ = (ArrayInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS) && MAXON_UNLIKELY(!o_)) return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); 
	return (((MTable*) o_->_vtable)->_ArrayInterface_CopyFrom(o_, other));
}
template <typename TYPE> template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ArrayInterface<TYPE>::ConstReferenceFunctionsImpl<S>::Clone(Bool cloneElements) const -> Result<ArrayInterface*>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, false, Result<ArrayInterface*>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const ArrayInterface* o_ = (const ArrayInterface*) this->GetPointer(); if (!(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS) && MAXON_UNLIKELY(!o_)) { o_ = ArrayInterface::NullValuePtr(); if (!o_) return maxon::PrivateNullReturnValue<Result<ArrayInterface*>>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } 
	return (((MTable*) o_->_vtable)->_ArrayInterface_Clone(o_, cloneElements));
}
template <typename TYPE> template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ArrayInterface<TYPE>::ConstReferenceFunctionsImpl<S>::GetValueDataType() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<const DataType*>, const DataType*>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, false, typename std::conditional<S::HAS_ERROR, maxon::Result<const DataType*>, const DataType*>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const ArrayInterface* o_ = (const ArrayInterface*) this->GetPointer(); if (!(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS) && MAXON_UNLIKELY(!o_)) { o_ = ArrayInterface::NullValuePtr(); if (!o_) return nullptr; } 
	return (((MTable*) o_->_vtable)->_ArrayInterface_GetValueDataType(o_));
}
template <typename TYPE> template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ArrayInterface<TYPE>::ConstReferenceFunctionsImpl<S>::ToString(const FormatStatement* formatStatement) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<String>, String>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, false, typename std::conditional<S::HAS_ERROR, maxon::Result<String>, String>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const ArrayInterface* o_ = (const ArrayInterface*) this->GetPointer(); if (!(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS) && MAXON_UNLIKELY(!o_)) { o_ = ArrayInterface::NullValuePtr(); if (!o_) return maxon::PrivateNullReturnValue<String>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } 
	return (((MTable*) o_->_vtable)->_ArrayInterface_ToString(o_, formatStatement));
}
template <typename TYPE> template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ArrayInterface<TYPE>::ConstReferenceFunctionsImpl<S>::GetMemorySize() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, false, typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const ArrayInterface* o_ = (const ArrayInterface*) this->GetPointer(); if (!(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS) && MAXON_UNLIKELY(!o_)) { o_ = ArrayInterface::NullValuePtr(); if (!o_) return 0; } 
	return (((MTable*) o_->_vtable)->_ArrayInterface_GetMemorySize(o_));
}
template <typename TYPE> template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ArrayInterface<TYPE>::ConstReferenceFunctionsImpl<S>::IsEqual(const ArrayInterface* other, EQUALITY equality) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, false, typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const ArrayInterface* o_ = (const ArrayInterface*) this->GetPointer(); if (!(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS) && MAXON_UNLIKELY(!o_)) { o_ = ArrayInterface::NullValuePtr(); if (!o_) return maxon::PrivateLogNullptrError(false); } 
	return (((MTable*) o_->_vtable)->_ArrayInterface_IsEqual(o_, other, equality));
}
template <typename TYPE> template <typename S> template <typename T> MAXON_ATTRIBUTE_FORCE_INLINE auto ArrayInterface<TYPE>::ConstReferenceFunctionsImpl<S>::HasType() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, false, typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const ArrayInterface* o_ = (const ArrayInterface*) this->GetPointer(); if (!(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS) && MAXON_UNLIKELY(!o_)) { o_ = ArrayInterface::NullValuePtr(); if (!o_) return maxon::PrivateLogNullptrError(false); } 
	return (o_->HasType<T>());
}
template <typename TYPE> template <typename S> template <typename T> MAXON_ATTRIBUTE_FORCE_INLINE auto ArrayInterface<TYPE>::ConstReferenceFunctionsImpl<S>::AssertType() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, false, typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const ArrayInterface* o_ = (const ArrayInterface*) this->GetPointer(); if (!(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS) && MAXON_UNLIKELY(!o_)) { o_ = ArrayInterface::NullValuePtr(); if (!o_) return maxon::PrivateLogNullptrError(); } 
	o_->AssertType<T>();
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
#ifdef MAXON_COMPILER_INTEL
#endif
#ifdef MAXON_COMPILER_INTEL
#endif
template <typename TYPE> template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ArrayInterface<TYPE>::ConstReferenceFunctionsImpl<S>::Begin() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<ConstIterator>, ConstIterator>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, false, typename std::conditional<S::HAS_ERROR, maxon::Result<ConstIterator>, ConstIterator>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const ArrayInterface* o_ = (const ArrayInterface*) this->GetPointer(); if (!(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS) && MAXON_UNLIKELY(!o_)) { o_ = ArrayInterface::NullValuePtr(); if (!o_) return maxon::PrivateNullReturnValue<ConstIterator>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } 
	return (o_->Begin());
}
template <typename TYPE> template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ArrayInterface<TYPE>::ConstReferenceFunctionsImpl<S>::End() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<ConstIterator>, ConstIterator>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, false, typename std::conditional<S::HAS_ERROR, maxon::Result<ConstIterator>, ConstIterator>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const ArrayInterface* o_ = (const ArrayInterface*) this->GetPointer(); if (!(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS) && MAXON_UNLIKELY(!o_)) { o_ = ArrayInterface::NullValuePtr(); if (!o_) return maxon::PrivateNullReturnValue<ConstIterator>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } 
	return (o_->End());
}
#ifdef CPP_853_HACK
#ifdef MAXON_COMPILER_GCC
#else
#endif
#endif
#ifdef CPP_853_HACK
#endif
#ifdef CPP_853_HACK
#ifdef MAXON_COMPILER_GCC
#else
#endif
#endif
#ifdef CPP_853_HACK
#else
#endif
#ifdef MAXON_COMPILER_BUG_CONST_TYPE_ALIAS
#else
#endif

struct ArrayFactory::MTable
{
	static MTable _instance;
	static MTable _unresolvedInstance;
	static const maxon::Char* const _ids;
	static maxon::Bool InitUnresolved(maxon::NonvirtualInterfaceReference::UnresolvedAssembler assembler, MTable* tbl);
	static const maxon::NULL_RETURN_TYPE _returnTypes[];
	static const maxon::Bool HAS_NONSTATIC = false;
	Result<ArrayInterface<Generic>*> (*_ArrayFactory_NewBaseArray) (const DataType* type, const Generic* src, Bool move);
	Result<ArrayInterface<Generic>*> (*_ArrayFactory_NewBlockArray) (const DataType* type, const Generic* src, Bool move);
	template <typename IMPL> static void Init(MTable* tbl)
	{
		tbl->_ArrayFactory_NewBaseArray = &IMPL::_ArrayFactory_NewBaseArray;
		tbl->_ArrayFactory_NewBlockArray = &IMPL::_ArrayFactory_NewBlockArray;
	}
};

template <typename C> class ArrayFactory::Wrapper
{
public:
	static Result<ArrayInterface<Generic>*> _ArrayFactory_NewBaseArray(const DataType* type, const Generic* src, Bool move) { return C::NewBaseArray(type, src, move); }
	static Result<ArrayInterface<Generic>*> _ArrayFactory_NewBlockArray(const DataType* type, const Generic* src, Bool move) { return C::NewBlockArray(type, src, move); }
};

MAXON_ATTRIBUTE_FORCE_INLINE auto ArrayFactory::NewBaseArray(const DataType* type, const Generic* src, Bool move) -> Result<ArrayInterface<Generic>*>
{
	return MTable::_instance._ArrayFactory_NewBaseArray(type, src, move);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ArrayFactory::NewBlockArray(const DataType* type, const Generic* src, Bool move) -> Result<ArrayInterface<Generic>*>
{
	return MTable::_instance._ArrayFactory_NewBlockArray(type, src, move);
}

#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT)
static maxon::EntityUse s_ui_maxon_ArrayFactory(ArrayFactory::_interface.GetReference(), &maxon::g_translationUnit, "maxon/array.h", false);
#endif
#ifdef CPP_853_HACK
#endif
#ifdef CPP_853_HACK
#else
#endif
#endif

#ifdef MAXON_COMPILER_GCC
	#pragma GCC diagnostic pop
#endif

#endif

