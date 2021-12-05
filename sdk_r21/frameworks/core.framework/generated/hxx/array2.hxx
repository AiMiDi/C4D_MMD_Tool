
#ifndef DOXYGEN

#if defined MAXON_COMPILER_GCC
	#pragma GCC diagnostic push
	#if MAXON_COMPILER_GCC >= 600
		#pragma GCC diagnostic ignored "-Wmisleading-indentation"
	#endif
#endif

#if 1

template <typename TYPE> struct VArrayInterface<TYPE>::MTable
{
	MTable() { }
	template <typename C> explicit MTable(C*) { Init<typename maxon::SFINAEHelper<Hxx2, C>::type::template Wrapper<C>>(); }
	template <typename C> MTable(C*, maxon::Bool) { Init<C>(); }
	void (*_VArrayInterface_Free) (const VArrayInterface* object);
	Int (*_VArrayInterface_GetCount) (const VArrayInterface* this_);
	const TYPE& (*_VArrayInterface_operatorIndex) (const VArrayInterface* this_, Int index);
	ResultRef<TYPE> (*_VArrayInterface_GetWritable) (VArrayInterface* this_, Int index);
	Int (*_VArrayInterface_GetBlock) (const VArrayInterface* this_, Int index, SimdBlock<const TYPE>& block);
	Result<Int> (*_VArrayInterface_GetWritableBlock) (VArrayInterface* this_, Int index, SimdBlock<TYPE>& block);
	Result<VArrayInterface*> (*_VArrayInterface_Clone) (const VArrayInterface* this_, Bool cloneElements);
	const DataType& (*_VArrayInterface_GetValueDataType) (const VArrayInterface* this_);
	String (*_VArrayInterface_ToString) (const VArrayInterface* this_, const FormatStatement* formatStatement);
	Bool (*_VArrayInterface_IsEqual) (const VArrayInterface* this_, const VArrayInterface* other, EQUALITY equality);
	UInt (*_VArrayInterface_GetHashCode) (const VArrayInterface* this_);
	Result<void> (*_VArrayInterface_PrivateInsert) (VArrayInterface* this_, Int index, const StridedBlock<const TYPE>& values, Bool move);
	ResultMem (*_VArrayInterface_Resize) (VArrayInterface* this_, Int count, COLLECTION_RESIZE_FLAGS resizeFlags);
	ResultMem (*_VArrayInterface_SetCapacityHint) (VArrayInterface* this_, Int requestedCapacity, COLLECTION_RESIZE_FLAGS resizeFlags);
	ResultRef<TYPE> (*_VArrayInterface_Insert) (VArrayInterface* this_, Int index);
	ResultMem (*_VArrayInterface_Insert_1) (VArrayInterface* this_, Int index, const Block<const TYPE>& values);
	ResultMem (*_VArrayInterface_Insert_2) (VArrayInterface* this_, Int index, const MoveBlock<TYPE>& values);
	ResultRef<TYPE> (*_VArrayInterface_Append) (VArrayInterface* this_);
	ResultMem (*_VArrayInterface_Erase) (VArrayInterface* this_, Int index, Int count);
	ResultMem (*_VArrayInterface_SwapErase) (VArrayInterface* this_, Int index, Int count);
	void (*_VArrayInterface_Reset) (VArrayInterface* this_);
	void (*_VArrayInterface_Flush) (VArrayInterface* this_);
	Result<void> (*_VArrayInterface_CopyFrom) (VArrayInterface* this_, const VArrayInterface& other);
	template <typename IMPL> void Init()
	{
		_VArrayInterface_Free = &IMPL::_VArrayInterface_Free;
		_VArrayInterface_GetCount = &IMPL::_VArrayInterface_GetCount;
		_VArrayInterface_operatorIndex = &IMPL::_VArrayInterface_operatorIndex;
		_VArrayInterface_GetWritable = &IMPL::_VArrayInterface_GetWritable;
		_VArrayInterface_GetBlock = &IMPL::_VArrayInterface_GetBlock;
		_VArrayInterface_GetWritableBlock = &IMPL::_VArrayInterface_GetWritableBlock;
		_VArrayInterface_Clone = &IMPL::_VArrayInterface_Clone;
		_VArrayInterface_GetValueDataType = &IMPL::_VArrayInterface_GetValueDataType;
		_VArrayInterface_ToString = &IMPL::_VArrayInterface_ToString;
		_VArrayInterface_IsEqual = &IMPL::_VArrayInterface_IsEqual;
		_VArrayInterface_GetHashCode = &IMPL::_VArrayInterface_GetHashCode;
		_VArrayInterface_PrivateInsert = &IMPL::_VArrayInterface_PrivateInsert;
		_VArrayInterface_Resize = &IMPL::_VArrayInterface_Resize;
		_VArrayInterface_SetCapacityHint = &IMPL::_VArrayInterface_SetCapacityHint;
		_VArrayInterface_Insert = &IMPL::_VArrayInterface_Insert;
		_VArrayInterface_Insert_1 = &IMPL::_VArrayInterface_Insert_1;
		_VArrayInterface_Insert_2 = &IMPL::_VArrayInterface_Insert_2;
		_VArrayInterface_Append = &IMPL::_VArrayInterface_Append;
		_VArrayInterface_Erase = &IMPL::_VArrayInterface_Erase;
		_VArrayInterface_SwapErase = &IMPL::_VArrayInterface_SwapErase;
		_VArrayInterface_Reset = &IMPL::_VArrayInterface_Reset;
		_VArrayInterface_Flush = &IMPL::_VArrayInterface_Flush;
		_VArrayInterface_CopyFrom = &IMPL::_VArrayInterface_CopyFrom;
	}
};

template <typename TYPE> struct VArrayInterface<TYPE>::Hxx2
{
	template <typename C> class Wrapper
	{
	public:
	static void _VArrayInterface_Free(const VArrayInterface* object) { return C::Free((const C*) object); }
	static Int _VArrayInterface_GetCount(const VArrayInterface* this_) { return ((const C*) this_)->GetCount(); }
	static const TYPE& _VArrayInterface_operatorIndex(const VArrayInterface* this_, Int index) { return ((const C*) this_)->operator [](index); }
	static ResultRef<TYPE> _VArrayInterface_GetWritable(VArrayInterface* this_, Int index) { return ((C*) this_)->GetWritable(index); }
	static Int _VArrayInterface_GetBlock(const VArrayInterface* this_, Int index, SimdBlock<const TYPE>& block) { return ((const C*) this_)->GetBlock(index, block); }
	static Result<Int> _VArrayInterface_GetWritableBlock(VArrayInterface* this_, Int index, SimdBlock<TYPE>& block) { return ((C*) this_)->GetWritableBlock(index, block); }
	static Result<VArrayInterface*> _VArrayInterface_Clone(const VArrayInterface* this_, Bool cloneElements) { return ((const C*) this_)->Clone(cloneElements); }
	static const DataType& _VArrayInterface_GetValueDataType(const VArrayInterface* this_) { return ((const C*) this_)->GetValueDataType(); }
	static String _VArrayInterface_ToString(const VArrayInterface* this_, const FormatStatement* formatStatement) { return ((const C*) this_)->ToString(formatStatement); }
	static Bool _VArrayInterface_IsEqual(const VArrayInterface* this_, const VArrayInterface* other, EQUALITY equality) { return ((const C*) this_)->IsEqual(other, equality); }
	static UInt _VArrayInterface_GetHashCode(const VArrayInterface* this_) { return ((const C*) this_)->GetHashCode(); }
	static Result<void> _VArrayInterface_PrivateInsert(VArrayInterface* this_, Int index, const StridedBlock<const TYPE>& values, Bool move) { return ((C*) this_)->PrivateInsert(index, values, move); }
	static ResultMem _VArrayInterface_Resize(VArrayInterface* this_, Int count, COLLECTION_RESIZE_FLAGS resizeFlags) { return ((C*) this_)->Resize(count, resizeFlags); }
	static ResultMem _VArrayInterface_SetCapacityHint(VArrayInterface* this_, Int requestedCapacity, COLLECTION_RESIZE_FLAGS resizeFlags) { return ((C*) this_)->SetCapacityHint(requestedCapacity, resizeFlags); }
	static ResultRef<TYPE> _VArrayInterface_Insert(VArrayInterface* this_, Int index) { return ((C*) this_)->Insert(index); }
	static ResultMem _VArrayInterface_Insert_1(VArrayInterface* this_, Int index, const Block<const TYPE>& values) { return ((C*) this_)->Insert(index, values); }
	static ResultMem _VArrayInterface_Insert_2(VArrayInterface* this_, Int index, const MoveBlock<TYPE>& values) { return ((C*) this_)->Insert(index, values); }
	static ResultRef<TYPE> _VArrayInterface_Append(VArrayInterface* this_) { return ((C*) this_)->Append(); }
	static ResultMem _VArrayInterface_Erase(VArrayInterface* this_, Int index, Int count) { return ((C*) this_)->Erase(index, count); }
	static ResultMem _VArrayInterface_SwapErase(VArrayInterface* this_, Int index, Int count) { return ((C*) this_)->SwapErase(index, count); }
	static void _VArrayInterface_Reset(VArrayInterface* this_) { return ((C*) this_)->Reset(); }
	static void _VArrayInterface_Flush(VArrayInterface* this_) { return ((C*) this_)->Flush(); }
	static Result<void> _VArrayInterface_CopyFrom(VArrayInterface* this_, const VArrayInterface& other) { return ((C*) this_)->CopyFrom(other); }
	};

};
template <typename TYPE> MAXON_ATTRIBUTE_FORCE_INLINE auto VArrayInterface<TYPE>::Free(const VArrayInterface* object) -> void
{
	if (!object)
		return;
	return ((VArrayInterface::MTable*) object->_vtable)->_VArrayInterface_Free(object);
}
template <typename TYPE> MAXON_ATTRIBUTE_FORCE_INLINE auto VArrayInterface<TYPE>::GetCount() const -> Int
{
	return ((VArrayInterface::MTable*) this->_vtable)->_VArrayInterface_GetCount(this);
}
template <typename TYPE> MAXON_ATTRIBUTE_FORCE_INLINE auto VArrayInterface<TYPE>::operator [](Int index) const -> const TYPE&
{
	return ((VArrayInterface::MTable*) this->_vtable)->_VArrayInterface_operatorIndex(this, index);
}
template <typename TYPE> MAXON_ATTRIBUTE_FORCE_INLINE auto VArrayInterface<TYPE>::GetWritable(Int index) -> ResultRef<TYPE>
{
	return ((VArrayInterface::MTable*) this->_vtable)->_VArrayInterface_GetWritable(this, index);
}
template <typename TYPE> MAXON_ATTRIBUTE_FORCE_INLINE auto VArrayInterface<TYPE>::GetBlock(Int index, SimdBlock<const TYPE>& block) const -> Int
{
	return ((VArrayInterface::MTable*) this->_vtable)->_VArrayInterface_GetBlock(this, index, block);
}
template <typename TYPE> MAXON_ATTRIBUTE_FORCE_INLINE auto VArrayInterface<TYPE>::GetWritableBlock(Int index, SimdBlock<TYPE>& block) -> Result<Int>
{
	return ((VArrayInterface::MTable*) this->_vtable)->_VArrayInterface_GetWritableBlock(this, index, block);
}
template <typename TYPE> MAXON_ATTRIBUTE_FORCE_INLINE auto VArrayInterface<TYPE>::Clone(Bool cloneElements) const -> Result<VArrayInterface*>
{
	return ((VArrayInterface::MTable*) this->_vtable)->_VArrayInterface_Clone(this, cloneElements);
}
template <typename TYPE> MAXON_ATTRIBUTE_FORCE_INLINE auto VArrayInterface<TYPE>::GetValueDataType() const -> const DataType&
{
	return ((VArrayInterface::MTable*) this->_vtable)->_VArrayInterface_GetValueDataType(this);
}
template <typename TYPE> MAXON_ATTRIBUTE_FORCE_INLINE auto VArrayInterface<TYPE>::ToString(const FormatStatement* formatStatement) const -> String
{
	return ((VArrayInterface::MTable*) this->_vtable)->_VArrayInterface_ToString(this, formatStatement);
}
template <typename TYPE> MAXON_ATTRIBUTE_FORCE_INLINE auto VArrayInterface<TYPE>::IsEqual(const VArrayInterface* other, EQUALITY equality) const -> Bool
{
	return ((VArrayInterface::MTable*) this->_vtable)->_VArrayInterface_IsEqual(this, other, equality);
}
template <typename TYPE> MAXON_ATTRIBUTE_FORCE_INLINE auto VArrayInterface<TYPE>::GetHashCode() const -> UInt
{
	return ((VArrayInterface::MTable*) this->_vtable)->_VArrayInterface_GetHashCode(this);
}
template <typename TYPE> MAXON_ATTRIBUTE_FORCE_INLINE auto VArrayInterface<TYPE>::PrivateInsert(Int index, const StridedBlock<const TYPE>& values, Bool move) -> Result<void>
{
	return ((VArrayInterface::MTable*) this->_vtable)->_VArrayInterface_PrivateInsert(this, index, values, move);
}
template <typename TYPE> MAXON_ATTRIBUTE_FORCE_INLINE auto VArrayInterface<TYPE>::Resize(Int count, COLLECTION_RESIZE_FLAGS resizeFlags) -> ResultMem
{
	return ((VArrayInterface::MTable*) this->_vtable)->_VArrayInterface_Resize(this, count, resizeFlags);
}
template <typename TYPE> MAXON_ATTRIBUTE_FORCE_INLINE auto VArrayInterface<TYPE>::SetCapacityHint(Int requestedCapacity, COLLECTION_RESIZE_FLAGS resizeFlags) -> ResultMem
{
	return ((VArrayInterface::MTable*) this->_vtable)->_VArrayInterface_SetCapacityHint(this, requestedCapacity, resizeFlags);
}
template <typename TYPE> MAXON_ATTRIBUTE_FORCE_INLINE auto VArrayInterface<TYPE>::Insert(Int index) -> ResultRef<TYPE>
{
	return ((VArrayInterface::MTable*) this->_vtable)->_VArrayInterface_Insert(this, index);
}
template <typename TYPE> MAXON_ATTRIBUTE_FORCE_INLINE auto VArrayInterface<TYPE>::Insert(Int index, const Block<const TYPE>& values) -> ResultMem
{
	return ((VArrayInterface::MTable*) this->_vtable)->_VArrayInterface_Insert_1(this, index, values);
}
template <typename TYPE> MAXON_ATTRIBUTE_FORCE_INLINE auto VArrayInterface<TYPE>::Insert(Int index, const MoveBlock<TYPE>& values) -> ResultMem
{
	return ((VArrayInterface::MTable*) this->_vtable)->_VArrayInterface_Insert_2(this, index, values);
}
template <typename TYPE> MAXON_ATTRIBUTE_FORCE_INLINE auto VArrayInterface<TYPE>::Append() -> ResultRef<TYPE>
{
	return ((VArrayInterface::MTable*) this->_vtable)->_VArrayInterface_Append(this);
}
template <typename TYPE> MAXON_ATTRIBUTE_FORCE_INLINE auto VArrayInterface<TYPE>::Erase(Int index, Int count) -> ResultMem
{
	return ((VArrayInterface::MTable*) this->_vtable)->_VArrayInterface_Erase(this, index, count);
}
template <typename TYPE> MAXON_ATTRIBUTE_FORCE_INLINE auto VArrayInterface<TYPE>::SwapErase(Int index, Int count) -> ResultMem
{
	return ((VArrayInterface::MTable*) this->_vtable)->_VArrayInterface_SwapErase(this, index, count);
}
template <typename TYPE> MAXON_ATTRIBUTE_FORCE_INLINE auto VArrayInterface<TYPE>::Reset() -> void
{
	return ((VArrayInterface::MTable*) this->_vtable)->_VArrayInterface_Reset(this);
}
template <typename TYPE> MAXON_ATTRIBUTE_FORCE_INLINE auto VArrayInterface<TYPE>::Flush() -> void
{
	return ((VArrayInterface::MTable*) this->_vtable)->_VArrayInterface_Flush(this);
}
template <typename TYPE> MAXON_ATTRIBUTE_FORCE_INLINE auto VArrayInterface<TYPE>::CopyFrom(const VArrayInterface& other) -> Result<void>
{
	return ((VArrayInterface::MTable*) this->_vtable)->_VArrayInterface_CopyFrom(this, other);
}

template <typename TYPE> template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto VArrayInterface<TYPE>::Hxx1::ConstReferenceFunctionsImpl<S>::GetCount() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const VArrayInterface* o_ = (const VArrayInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = VArrayInterface::NullValuePtr(); if (!o_) return 0; } 
	return (((VArrayInterface::MTable*) o_->_vtable)->_VArrayInterface_GetCount(o_));
}
template <typename TYPE> template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto VArrayInterface<TYPE>::Hxx1::ConstReferenceFunctionsImpl<S>::IsEmpty() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const VArrayInterface* o_ = (const VArrayInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = VArrayInterface::NullValuePtr(); if (!o_) return true; } 
	return (o_->IsEmpty());
}
template <typename TYPE> template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto VArrayInterface<TYPE>::Hxx1::ConstReferenceFunctionsImpl<S>::IsPopulated() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const VArrayInterface* o_ = (const VArrayInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = VArrayInterface::NullValuePtr(); if (!o_) return maxon::PrivateLogNullptrError(false); } 
	return (o_->IsPopulated());
}
template <typename TYPE> template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto VArrayInterface<TYPE>::Hxx1::ConstReferenceFunctionsImpl<S>::operator [](Int index) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<const TYPE&>, const TYPE&>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<const TYPE&>, const TYPE&>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const VArrayInterface* o_ = (const VArrayInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = VArrayInterface::NullValuePtr(); if (!o_) return maxon::PrivateNullReturnValue<const TYPE&>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } 
	return (((VArrayInterface::MTable*) o_->_vtable)->_VArrayInterface_operatorIndex(o_, index));
}
template <typename TYPE> template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto VArrayInterface<TYPE>::Hxx1::ReferenceFunctionsImpl<S>::GetWritable(Int index) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<TYPE&>, ResultRef<TYPE>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<TYPE&>, ResultRef<TYPE>>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); VArrayInterface* o_ = (VArrayInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) return maxon::PrivateNullReturnValue<ResultRef<TYPE>>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); 
	return (((VArrayInterface::MTable*) o_->_vtable)->_VArrayInterface_GetWritable(o_, index));
}
template <typename TYPE> template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto VArrayInterface<TYPE>::Hxx1::COWReferenceFunctionsImpl<S>::GetWritable(Int index) -> typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), ResultRef<TYPE>, maxon::Result<TYPE&>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), ResultRef<TYPE>, maxon::Result<TYPE&>>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); VArrayInterface* o_ = (VArrayInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); 
	return (((VArrayInterface::MTable*) o_->_vtable)->_VArrayInterface_GetWritable(o_, index));
}
template <typename TYPE> template <typename S> template <typename T> MAXON_ATTRIBUTE_FORCE_INLINE auto VArrayInterface<TYPE>::Hxx1::ReferenceFunctionsImpl<S>::Set(Int index, T&& value) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<void>, ResultMem>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<void>, ResultMem>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); VArrayInterface* o_ = (VArrayInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) return maxon::PrivateNullReturnValue<ResultMem>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); 
	return (o_->Set<T>(index, std::forward<T>(value)));
}
template <typename TYPE> template <typename S> template <typename T> MAXON_ATTRIBUTE_FORCE_INLINE auto VArrayInterface<TYPE>::Hxx1::COWReferenceFunctionsImpl<S>::Set(Int index, T&& value) -> typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), ResultMem, maxon::Result<void>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), ResultMem, maxon::Result<void>>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); VArrayInterface* o_ = (VArrayInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); 
	return (o_->Set<T>(index, std::forward<T>(value)));
}
template <typename TYPE> template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto VArrayInterface<TYPE>::Hxx1::ConstReferenceFunctionsImpl<S>::GetBlock(Int index, SimdBlock<const TYPE>& block) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const VArrayInterface* o_ = (const VArrayInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = VArrayInterface::NullValuePtr(); if (!o_) return 0; } 
	return (((VArrayInterface::MTable*) o_->_vtable)->_VArrayInterface_GetBlock(o_, index, block));
}
template <typename TYPE> template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto VArrayInterface<TYPE>::Hxx1::ReferenceFunctionsImpl<S>::GetWritableBlock(Int index, SimdBlock<TYPE>& block) const -> Result<Int>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<Int>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); VArrayInterface* o_ = (VArrayInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); 
	return (((VArrayInterface::MTable*) o_->_vtable)->_VArrayInterface_GetWritableBlock(o_, index, block));
}
template <typename TYPE> template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto VArrayInterface<TYPE>::Hxx1::COWReferenceFunctionsImpl<S>::GetWritableBlock(Int index, SimdBlock<TYPE>& block) -> Result<Int>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<Int>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); VArrayInterface* o_ = (VArrayInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); 
	return (((VArrayInterface::MTable*) o_->_vtable)->_VArrayInterface_GetWritableBlock(o_, index, block));
}
template <typename TYPE> template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto VArrayInterface<TYPE>::Hxx1::ConstReferenceFunctionsImpl<S>::Clone(Bool cloneElements) const -> Result<VArrayInterface*>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<VArrayInterface*>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const VArrayInterface* o_ = (const VArrayInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = VArrayInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (((VArrayInterface::MTable*) o_->_vtable)->_VArrayInterface_Clone(o_, cloneElements));
}
template <typename TYPE> template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto VArrayInterface<TYPE>::Hxx1::ConstReferenceFunctionsImpl<S>::GetValueDataType() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<const DataType&>, const DataType&>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<const DataType&>, const DataType&>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const VArrayInterface* o_ = (const VArrayInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = VArrayInterface::NullValuePtr(); if (!o_) return maxon::PrivateNullReturnValue<const DataType&>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } 
	return (((VArrayInterface::MTable*) o_->_vtable)->_VArrayInterface_GetValueDataType(o_));
}
template <typename TYPE> template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto VArrayInterface<TYPE>::Hxx1::ConstReferenceFunctionsImpl<S>::ToString(const FormatStatement* formatStatement) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<String>, String>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<String>, String>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const VArrayInterface* o_ = (const VArrayInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = VArrayInterface::NullValuePtr(); if (!o_) return maxon::PrivateNullReturnValue<String>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } 
	return (((VArrayInterface::MTable*) o_->_vtable)->_VArrayInterface_ToString(o_, formatStatement));
}
template <typename TYPE> template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto VArrayInterface<TYPE>::Hxx1::ConstReferenceFunctionsImpl<S>::IsEqual(const VArrayInterface* other, EQUALITY equality) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const VArrayInterface* o_ = (const VArrayInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = VArrayInterface::NullValuePtr(); if (!o_) return maxon::PrivateLogNullptrError(false); } 
	return (((VArrayInterface::MTable*) o_->_vtable)->_VArrayInterface_IsEqual(o_, other, equality));
}
template <typename TYPE> template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto VArrayInterface<TYPE>::Hxx1::ReferenceFunctionsImpl<S>::Resize(Int count, COLLECTION_RESIZE_FLAGS resizeFlags) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<void>, ResultMem>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<void>, ResultMem>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); VArrayInterface* o_ = (VArrayInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) return maxon::PrivateNullReturnValue<ResultMem>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); 
	return (((VArrayInterface::MTable*) o_->_vtable)->_VArrayInterface_Resize(o_, count, resizeFlags));
}
template <typename TYPE> template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto VArrayInterface<TYPE>::Hxx1::COWReferenceFunctionsImpl<S>::Resize(Int count, COLLECTION_RESIZE_FLAGS resizeFlags) -> typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), ResultMem, maxon::Result<void>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), ResultMem, maxon::Result<void>>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); VArrayInterface* o_ = (VArrayInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); 
	return (((VArrayInterface::MTable*) o_->_vtable)->_VArrayInterface_Resize(o_, count, resizeFlags));
}
template <typename TYPE> template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto VArrayInterface<TYPE>::Hxx1::ReferenceFunctionsImpl<S>::SetCapacityHint(Int requestedCapacity, COLLECTION_RESIZE_FLAGS resizeFlags) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<void>, ResultMem>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<void>, ResultMem>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); VArrayInterface* o_ = (VArrayInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) return maxon::PrivateNullReturnValue<ResultMem>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); 
	return (((VArrayInterface::MTable*) o_->_vtable)->_VArrayInterface_SetCapacityHint(o_, requestedCapacity, resizeFlags));
}
template <typename TYPE> template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto VArrayInterface<TYPE>::Hxx1::COWReferenceFunctionsImpl<S>::SetCapacityHint(Int requestedCapacity, COLLECTION_RESIZE_FLAGS resizeFlags) -> typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), ResultMem, maxon::Result<void>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), ResultMem, maxon::Result<void>>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); VArrayInterface* o_ = (VArrayInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); 
	return (((VArrayInterface::MTable*) o_->_vtable)->_VArrayInterface_SetCapacityHint(o_, requestedCapacity, resizeFlags));
}
template <typename TYPE> template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto VArrayInterface<TYPE>::Hxx1::ReferenceFunctionsImpl<S>::Insert(Int index) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<TYPE&>, ResultRef<TYPE>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<TYPE&>, ResultRef<TYPE>>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); VArrayInterface* o_ = (VArrayInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) return maxon::PrivateNullReturnValue<ResultRef<TYPE>>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); 
	return (((VArrayInterface::MTable*) o_->_vtable)->_VArrayInterface_Insert(o_, index));
}
template <typename TYPE> template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto VArrayInterface<TYPE>::Hxx1::COWReferenceFunctionsImpl<S>::Insert(Int index) -> typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), ResultRef<TYPE>, maxon::Result<TYPE&>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), ResultRef<TYPE>, maxon::Result<TYPE&>>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); VArrayInterface* o_ = (VArrayInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); 
	return (((VArrayInterface::MTable*) o_->_vtable)->_VArrayInterface_Insert(o_, index));
}
template <typename TYPE> template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto VArrayInterface<TYPE>::Hxx1::ReferenceFunctionsImpl<S>::Insert(Int index, const TYPE& value) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<TYPE&>, ResultRef<TYPE>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<TYPE&>, ResultRef<TYPE>>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); VArrayInterface* o_ = (VArrayInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) return maxon::PrivateNullReturnValue<ResultRef<TYPE>>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); 
	return (o_->Insert(index, value));
}
template <typename TYPE> template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto VArrayInterface<TYPE>::Hxx1::COWReferenceFunctionsImpl<S>::Insert(Int index, const TYPE& value) -> typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), ResultRef<TYPE>, maxon::Result<TYPE&>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), ResultRef<TYPE>, maxon::Result<TYPE&>>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); VArrayInterface* o_ = (VArrayInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); 
	return (o_->Insert(index, value));
}
template <typename TYPE> template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto VArrayInterface<TYPE>::Hxx1::ReferenceFunctionsImpl<S>::Insert(Int index, TYPE&& value) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<TYPE&>, ResultRef<TYPE>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<TYPE&>, ResultRef<TYPE>>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); VArrayInterface* o_ = (VArrayInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) return maxon::PrivateNullReturnValue<ResultRef<TYPE>>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); 
	return (o_->Insert(index, std::forward<TYPE>(value)));
}
template <typename TYPE> template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto VArrayInterface<TYPE>::Hxx1::COWReferenceFunctionsImpl<S>::Insert(Int index, TYPE&& value) -> typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), ResultRef<TYPE>, maxon::Result<TYPE&>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), ResultRef<TYPE>, maxon::Result<TYPE&>>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); VArrayInterface* o_ = (VArrayInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); 
	return (o_->Insert(index, std::forward<TYPE>(value)));
}
template <typename TYPE> template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto VArrayInterface<TYPE>::Hxx1::ReferenceFunctionsImpl<S>::Insert(Int index, const Block<const TYPE>& values) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<void>, ResultMem>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<void>, ResultMem>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); VArrayInterface* o_ = (VArrayInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) return maxon::PrivateNullReturnValue<ResultMem>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); 
	return (((VArrayInterface::MTable*) o_->_vtable)->_VArrayInterface_Insert_1(o_, index, values));
}
template <typename TYPE> template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto VArrayInterface<TYPE>::Hxx1::COWReferenceFunctionsImpl<S>::Insert(Int index, const Block<const TYPE>& values) -> typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), ResultMem, maxon::Result<void>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), ResultMem, maxon::Result<void>>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); VArrayInterface* o_ = (VArrayInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); 
	return (((VArrayInterface::MTable*) o_->_vtable)->_VArrayInterface_Insert_1(o_, index, values));
}
template <typename TYPE> template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto VArrayInterface<TYPE>::Hxx1::ReferenceFunctionsImpl<S>::Insert(Int index, const MoveBlock<TYPE>& values) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<void>, ResultMem>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<void>, ResultMem>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); VArrayInterface* o_ = (VArrayInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) return maxon::PrivateNullReturnValue<ResultMem>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); 
	return (((VArrayInterface::MTable*) o_->_vtable)->_VArrayInterface_Insert_2(o_, index, values));
}
template <typename TYPE> template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto VArrayInterface<TYPE>::Hxx1::COWReferenceFunctionsImpl<S>::Insert(Int index, const MoveBlock<TYPE>& values) -> typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), ResultMem, maxon::Result<void>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), ResultMem, maxon::Result<void>>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); VArrayInterface* o_ = (VArrayInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); 
	return (((VArrayInterface::MTable*) o_->_vtable)->_VArrayInterface_Insert_2(o_, index, values));
}
template <typename TYPE> template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto VArrayInterface<TYPE>::Hxx1::ReferenceFunctionsImpl<S>::Append() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<TYPE&>, ResultRef<TYPE>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<TYPE&>, ResultRef<TYPE>>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); VArrayInterface* o_ = (VArrayInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) return maxon::PrivateNullReturnValue<ResultRef<TYPE>>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); 
	return (((VArrayInterface::MTable*) o_->_vtable)->_VArrayInterface_Append(o_));
}
template <typename TYPE> template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto VArrayInterface<TYPE>::Hxx1::COWReferenceFunctionsImpl<S>::Append() -> typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), ResultRef<TYPE>, maxon::Result<TYPE&>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), ResultRef<TYPE>, maxon::Result<TYPE&>>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); VArrayInterface* o_ = (VArrayInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); 
	return (((VArrayInterface::MTable*) o_->_vtable)->_VArrayInterface_Append(o_));
}
template <typename TYPE> template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto VArrayInterface<TYPE>::Hxx1::ReferenceFunctionsImpl<S>::Append(const TYPE& value) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<TYPE&>, ResultRef<TYPE>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<TYPE&>, ResultRef<TYPE>>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); VArrayInterface* o_ = (VArrayInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) return maxon::PrivateNullReturnValue<ResultRef<TYPE>>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); 
	return (o_->Append(value));
}
template <typename TYPE> template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto VArrayInterface<TYPE>::Hxx1::COWReferenceFunctionsImpl<S>::Append(const TYPE& value) -> typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), ResultRef<TYPE>, maxon::Result<TYPE&>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), ResultRef<TYPE>, maxon::Result<TYPE&>>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); VArrayInterface* o_ = (VArrayInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); 
	return (o_->Append(value));
}
template <typename TYPE> template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto VArrayInterface<TYPE>::Hxx1::ReferenceFunctionsImpl<S>::Append(TYPE&& value) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<TYPE&>, ResultRef<TYPE>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<TYPE&>, ResultRef<TYPE>>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); VArrayInterface* o_ = (VArrayInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) return maxon::PrivateNullReturnValue<ResultRef<TYPE>>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); 
	return (o_->Append(std::forward<TYPE>(value)));
}
template <typename TYPE> template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto VArrayInterface<TYPE>::Hxx1::COWReferenceFunctionsImpl<S>::Append(TYPE&& value) -> typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), ResultRef<TYPE>, maxon::Result<TYPE&>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), ResultRef<TYPE>, maxon::Result<TYPE&>>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); VArrayInterface* o_ = (VArrayInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); 
	return (o_->Append(std::forward<TYPE>(value)));
}
template <typename TYPE> template <typename S> template <typename T> MAXON_ATTRIBUTE_FORCE_INLINE auto VArrayInterface<TYPE>::Hxx1::ReferenceFunctionsImpl<S>::Append(T&& value) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<TYPE&>, ResultRef<TYPE>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<TYPE&>, ResultRef<TYPE>>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); VArrayInterface* o_ = (VArrayInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) return maxon::PrivateNullReturnValue<ResultRef<TYPE>>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); 
	return (o_->Append<T>(std::forward<T>(value)));
}
template <typename TYPE> template <typename S> template <typename T> MAXON_ATTRIBUTE_FORCE_INLINE auto VArrayInterface<TYPE>::Hxx1::COWReferenceFunctionsImpl<S>::Append(T&& value) -> typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), ResultRef<TYPE>, maxon::Result<TYPE&>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), ResultRef<TYPE>, maxon::Result<TYPE&>>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); VArrayInterface* o_ = (VArrayInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); 
	return (o_->Append<T>(std::forward<T>(value)));
}
template <typename TYPE> template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto VArrayInterface<TYPE>::Hxx1::ReferenceFunctionsImpl<S>::Pop() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); VArrayInterface* o_ = (VArrayInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) return maxon::PrivateLogNullptrError(false); 
	return (o_->Pop());
}
template <typename TYPE> template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto VArrayInterface<TYPE>::Hxx1::COWReferenceFunctionsImpl<S>::Pop() -> typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), Bool, maxon::Result<Bool>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), Bool, maxon::Result<Bool>>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); VArrayInterface* o_ = (VArrayInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); 
	return (o_->Pop());
}
template <typename TYPE> template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto VArrayInterface<TYPE>::Hxx1::ReferenceFunctionsImpl<S>::Pop(TYPE* dst) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); VArrayInterface* o_ = (VArrayInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) return maxon::PrivateLogNullptrError(false); 
	return (o_->Pop(dst));
}
template <typename TYPE> template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto VArrayInterface<TYPE>::Hxx1::COWReferenceFunctionsImpl<S>::Pop(TYPE* dst) -> typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), Bool, maxon::Result<Bool>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), Bool, maxon::Result<Bool>>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); VArrayInterface* o_ = (VArrayInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); 
	return (o_->Pop(dst));
}
template <typename TYPE> template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto VArrayInterface<TYPE>::Hxx1::ReferenceFunctionsImpl<S>::Erase(Int index, Int count) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<void>, ResultMem>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<void>, ResultMem>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); VArrayInterface* o_ = (VArrayInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) return maxon::PrivateNullReturnValue<ResultMem>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); 
	return (((VArrayInterface::MTable*) o_->_vtable)->_VArrayInterface_Erase(o_, index, count));
}
template <typename TYPE> template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto VArrayInterface<TYPE>::Hxx1::COWReferenceFunctionsImpl<S>::Erase(Int index, Int count) -> typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), ResultMem, maxon::Result<void>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), ResultMem, maxon::Result<void>>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); VArrayInterface* o_ = (VArrayInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); 
	return (((VArrayInterface::MTable*) o_->_vtable)->_VArrayInterface_Erase(o_, index, count));
}
template <typename TYPE> template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto VArrayInterface<TYPE>::Hxx1::ReferenceFunctionsImpl<S>::SwapErase(Int index, Int count) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<void>, ResultMem>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<void>, ResultMem>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); VArrayInterface* o_ = (VArrayInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) return maxon::PrivateNullReturnValue<ResultMem>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); 
	return (((VArrayInterface::MTable*) o_->_vtable)->_VArrayInterface_SwapErase(o_, index, count));
}
template <typename TYPE> template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto VArrayInterface<TYPE>::Hxx1::COWReferenceFunctionsImpl<S>::SwapErase(Int index, Int count) -> typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), ResultMem, maxon::Result<void>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), ResultMem, maxon::Result<void>>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); VArrayInterface* o_ = (VArrayInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); 
	return (((VArrayInterface::MTable*) o_->_vtable)->_VArrayInterface_SwapErase(o_, index, count));
}
template <typename TYPE> template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto VArrayInterface<TYPE>::Hxx1::ReferenceFunctionsImpl<S>::Reset() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); VArrayInterface* o_ = (VArrayInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) return maxon::PrivateLogNullptrError(); 
	((VArrayInterface::MTable*) o_->_vtable)->_VArrayInterface_Reset(o_);
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
template <typename TYPE> template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto VArrayInterface<TYPE>::Hxx1::COWReferenceFunctionsImpl<S>::Reset() -> typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), void, maxon::Result<void>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), void, maxon::Result<void>>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); VArrayInterface* o_ = (VArrayInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); 
	((VArrayInterface::MTable*) o_->_vtable)->_VArrayInterface_Reset(o_);
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
template <typename TYPE> template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto VArrayInterface<TYPE>::Hxx1::ReferenceFunctionsImpl<S>::Flush() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); VArrayInterface* o_ = (VArrayInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) return maxon::PrivateLogNullptrError(); 
	((VArrayInterface::MTable*) o_->_vtable)->_VArrayInterface_Flush(o_);
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
template <typename TYPE> template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto VArrayInterface<TYPE>::Hxx1::COWReferenceFunctionsImpl<S>::Flush() -> typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), void, maxon::Result<void>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), void, maxon::Result<void>>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); VArrayInterface* o_ = (VArrayInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); 
	((VArrayInterface::MTable*) o_->_vtable)->_VArrayInterface_Flush(o_);
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
template <typename TYPE> template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto VArrayInterface<TYPE>::Hxx1::ReferenceFunctionsImpl<S>::CopyFrom(const VArrayInterface& other) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); VArrayInterface* o_ = (VArrayInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); 
	return (((VArrayInterface::MTable*) o_->_vtable)->_VArrayInterface_CopyFrom(o_, other));
}
template <typename TYPE> template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto VArrayInterface<TYPE>::Hxx1::COWReferenceFunctionsImpl<S>::CopyFrom(const VArrayInterface& other) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); VArrayInterface* o_ = (VArrayInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); 
	return (((VArrayInterface::MTable*) o_->_vtable)->_VArrayInterface_CopyFrom(o_, other));
}
template <typename TYPE> template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto VArrayInterface<TYPE>::Hxx1::ConstReferenceFunctionsImpl<S>::Begin() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<ConstIterator>, ConstIterator>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<ConstIterator>, ConstIterator>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const VArrayInterface* o_ = (const VArrayInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = VArrayInterface::NullValuePtr(); if (!o_) return maxon::PrivateNullReturnValue<ConstIterator>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } 
	return (o_->Begin());
}
template <typename TYPE> template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto VArrayInterface<TYPE>::Hxx1::ConstReferenceFunctionsImpl<S>::End() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<ConstIterator>, ConstIterator>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<ConstIterator>, ConstIterator>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const VArrayInterface* o_ = (const VArrayInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = VArrayInterface::NullValuePtr(); if (!o_) return maxon::PrivateNullReturnValue<ConstIterator>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } 
	return (o_->End());
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

template <typename TYPE> struct ArrayInterface<TYPE>::MTable
{
	MTable() { }
	template <typename C> explicit MTable(C*) { Init<typename maxon::SFINAEHelper<Hxx2, C>::type::template Wrapper<C>>(); }
	template <typename C> MTable(C*, maxon::Bool) { Init<C>(); }
	PRIVATE_MAXON_ALLOC_TYPENAME ArrayBase0<ArrayInterface<TYPE>, TYPE, VArrayInterface<TYPE>, DefaultCompare>::MTable super;
	Int (*_ArrayInterface_GetBlock) (const ArrayInterface* this_, Int index, Block<const TYPE, false>& block);
	Int (*_ArrayInterface_GetMemorySize) (const ArrayInterface* this_);
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
	template <typename IMPL> void Init()
	{
		super.template Init<IMPL>();
		_ArrayInterface_GetBlock = &IMPL::_ArrayInterface_GetBlock;
		_ArrayInterface_GetMemorySize = &IMPL::_ArrayInterface_GetMemorySize;
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

template <typename TYPE> struct ArrayInterface<TYPE>::Hxx2
{
	template <typename C> class Wrapper : public ArrayBase0<ArrayInterface<TYPE>, TYPE, VArrayInterface<TYPE>, DefaultCompare>::Hxx2::PRIVATE_MAXON_TEMPLATE_PREFIX Wrapper<C>
	{
	public:
	static Int _ArrayInterface_GetBlock(const ArrayInterface* this_, Int index, Block<const TYPE, false>& block) { return ((const C*) this_)->GetBlock(index, block); }
	static Int _ArrayInterface_GetMemorySize(const ArrayInterface* this_) { return ((const C*) this_)->GetMemorySize(); }
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

};
template <typename TYPE> MAXON_ATTRIBUTE_FORCE_INLINE auto ArrayInterface<TYPE>::GetBlock(Int index, Block<const TYPE, false>& block) const -> Int
{
	return ((ArrayInterface::MTable*) this->_vtable)->_ArrayInterface_GetBlock(this, index, block);
}
template <typename TYPE> MAXON_ATTRIBUTE_FORCE_INLINE auto ArrayInterface<TYPE>::GetMemorySize() const -> Int
{
	return ((ArrayInterface::MTable*) this->_vtable)->_ArrayInterface_GetMemorySize(this);
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

template <typename TYPE> ArrayInterface<TYPE>::ArrayInterface(const MTable& vtable) : ArrayBase0<ArrayInterface<TYPE>, TYPE, VArrayInterface<TYPE>, DefaultCompare>(vtable.super) { }
template <typename TYPE> template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ArrayInterface<TYPE>::Hxx1::ConstReferenceFunctionsImpl<S>::GetBlock(Int index, Block<const TYPE, false>& block) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const ArrayInterface* o_ = (const ArrayInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = ArrayInterface::NullValuePtr(); if (!o_) return 0; } 
	return (((ArrayInterface::MTable*) o_->_vtable)->_ArrayInterface_GetBlock(o_, index, block));
}
template <typename TYPE> template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ArrayInterface<TYPE>::Hxx1::ConstReferenceFunctionsImpl<S>::GetMemorySize() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const ArrayInterface* o_ = (const ArrayInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = ArrayInterface::NullValuePtr(); if (!o_) return 0; } 
	return (((ArrayInterface::MTable*) o_->_vtable)->_ArrayInterface_GetMemorySize(o_));
}
template <typename TYPE> template <typename S> template <typename T> MAXON_ATTRIBUTE_FORCE_INLINE auto ArrayInterface<TYPE>::Hxx1::ConstReferenceFunctionsImpl<S>::HasType() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const ArrayInterface* o_ = (const ArrayInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = ArrayInterface::NullValuePtr(); if (!o_) return maxon::PrivateLogNullptrError(false); } 
	return (o_->HasType<T>());
}
template <typename TYPE> template <typename S> template <typename T> MAXON_ATTRIBUTE_FORCE_INLINE auto ArrayInterface<TYPE>::Hxx1::ConstReferenceFunctionsImpl<S>::AssertType() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const ArrayInterface* o_ = (const ArrayInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = ArrayInterface::NullValuePtr(); if (!o_) return maxon::PrivateLogNullptrError(); } 
	o_->AssertType<T>();
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
#ifdef MAXON_COMPILER_INTEL
#endif
#ifdef MAXON_COMPILER_INTEL
#endif
template <typename TYPE> template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ArrayInterface<TYPE>::Hxx1::ConstReferenceFunctionsImpl<S>::Begin() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<ConstIterator>, ConstIterator>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<ConstIterator>, ConstIterator>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const ArrayInterface* o_ = (const ArrayInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = ArrayInterface::NullValuePtr(); if (!o_) return maxon::PrivateNullReturnValue<ConstIterator>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } 
	return (o_->Begin());
}
template <typename TYPE> template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ArrayInterface<TYPE>::Hxx1::ConstReferenceFunctionsImpl<S>::End() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<ConstIterator>, ConstIterator>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<ConstIterator>, ConstIterator>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const ArrayInterface* o_ = (const ArrayInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = ArrayInterface::NullValuePtr(); if (!o_) return maxon::PrivateNullReturnValue<ConstIterator>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } 
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
	Result<ArrayInterface<Generic>*> (*_ArrayFactory_NewBaseArray) (const DataType& type, const Generic* src, Bool move);
	Result<ArrayInterface<Generic>*> (*_ArrayFactory_NewBlockArray) (const DataType& type, const Generic* src, Bool move);
	template <typename IMPL> void Init()
	{
		_ArrayFactory_NewBaseArray = &IMPL::_ArrayFactory_NewBaseArray;
		_ArrayFactory_NewBlockArray = &IMPL::_ArrayFactory_NewBlockArray;
	}
};

struct ArrayFactory::Hxx2
{
	class Unresolved;
	template <typename C> class Wrapper
	{
	public:
	static Result<ArrayInterface<Generic>*> _ArrayFactory_NewBaseArray(const DataType& type, const Generic* src, Bool move) { return C::NewBaseArray(type, src, move); }
	static Result<ArrayInterface<Generic>*> _ArrayFactory_NewBlockArray(const DataType& type, const Generic* src, Bool move) { return C::NewBlockArray(type, src, move); }
	};

};
MAXON_ATTRIBUTE_FORCE_INLINE auto ArrayFactory::NewBaseArray(const DataType& type, const Generic* src, Bool move) -> Result<ArrayInterface<Generic>*>
{
	return MTable::_instance._ArrayFactory_NewBaseArray(type, src, move);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ArrayFactory::NewBlockArray(const DataType& type, const Generic* src, Bool move) -> Result<ArrayInterface<Generic>*>
{
	return MTable::_instance._ArrayFactory_NewBlockArray(type, src, move);
}

#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT)
#ifdef MAXON_USE_REGISTER_FUNCTION
MAXON_STATIC_STORAGE(maxon::EntityUse, s_ui_maxon_ArrayFactory); \
MAXON_ATTRIBUTE_CONSTRUCTOR static void Register_s_ui_maxon_ArrayFactory() { new (s_ui_maxon_ArrayFactory) maxon::EntityUse(ArrayFactory::_interface.GetReference(), &maxon::g_translationUnit, "maxon/array.h", false); }
#else // !MAXON_USE_REGISTER_FUNCTION
static maxon::EntityUse s_ui_maxon_ArrayFactory(ArrayFactory::_interface.GetReference(), &maxon::g_translationUnit, "maxon/array.h", false);
#endif // MAXON_USE_REGISTER_FUNCTION
#endif
#ifndef CPP_853_HACK
#else
#endif
#ifdef CPP_853_HACK
#else
#endif
#ifdef CPP_853_HACK
#else
#endif
#endif

#ifdef MAXON_COMPILER_GCC
	#pragma GCC diagnostic pop
#endif

#endif

