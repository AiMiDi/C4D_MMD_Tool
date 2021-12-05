
#ifndef DOXYGEN

#if defined MAXON_COMPILER_GCC
	#pragma GCC diagnostic push
	#if MAXON_COMPILER_GCC >= 600
		#pragma GCC diagnostic ignored "-Wmisleading-indentation"
	#endif
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

template <typename TYPE> struct SetInterface<TYPE>::MTable
{
	MTable() { }
	template <typename C> explicit MTable(C*) { Init<typename maxon::SFINAEHelper<Hxx2, C>::type::template Wrapper<C>>(); }
	template <typename C> MTable(C*, maxon::Bool) { Init<C>(); }
	void (*_SetInterface_Free) (const SetInterface* object);
	Int (*_SetInterface_GetCount) (const SetInterface* this_);
	Bool (*_SetInterface_Contains) (const SetInterface* this_, const TYPE& value);
	Result<void> (*_SetInterface_Insert) (SetInterface* this_, const TYPE& value, Bool& added);
	Result<void> (*_SetInterface_Insert_1) (SetInterface* this_, TYPE&& value, Bool& added);
	Result<Bool> (*_SetInterface_Erase) (SetInterface* this_, const TYPE& value);
	Iterator (*_SetInterface_Erase_1) (SetInterface* this_, const Iterator& iterator);
	void (*_SetInterface_Reset) (SetInterface* this_);
	void (*_SetInterface_Flush) (SetInterface* this_);
	Result<void> (*_SetInterface_CopyFrom) (SetInterface* this_, const SetInterface& other);
	Result<SetInterface*> (*_SetInterface_Clone) (const SetInterface* this_, Bool cloneElements);
	const DataType& (*_SetInterface_GetValueDataType) (const SetInterface* this_);
	String (*_SetInterface_ToString) (const SetInterface* this_, const FormatStatement* formatStatement);
	Int (*_SetInterface_GetMemorySize) (const SetInterface* this_);
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
	void (*_SetInterface_IteratorInit) (SetInterface* this_, Iterator* it, Bool end);
	void (*_SetInterface_IteratorInit_1) (const SetInterface* this_, ConstIterator* it, Bool end);
	void (*_SetInterface_IteratorInitMove) (const SetInterface* this_, Iterator* dest, Iterator* src);
	void (*_SetInterface_IteratorInitMove_1) (const SetInterface* this_, ConstIterator* dest, ConstIterator* src);
	void (*_SetInterface_IteratorFree) (const SetInterface* this_, Iterator* it);
	void (*_SetInterface_IteratorFree_1) (const SetInterface* this_, ConstIterator* it);
	Bool (*_SetInterface_IteratorIsEqual) (const SetInterface* this_, const Iterator* a, const Iterator* b);
	Bool (*_SetInterface_IteratorIsEqual_1) (const SetInterface* this_, const ConstIterator* a, const ConstIterator* b);
	void (*_SetInterface_IteratorInc) (const SetInterface* this_, Iterator* it);
	void (*_SetInterface_IteratorInc_1) (const SetInterface* this_, ConstIterator* it);
	const TYPE* (*_SetInterface_IteratorGet) (const SetInterface* this_, const Iterator* it);
	const TYPE* (*_SetInterface_IteratorGet_1) (const SetInterface* this_, const ConstIterator* it);
	template <typename IMPL> void Init()
	{
		_SetInterface_Free = &IMPL::_SetInterface_Free;
		_SetInterface_GetCount = &IMPL::_SetInterface_GetCount;
		_SetInterface_Contains = &IMPL::_SetInterface_Contains;
		_SetInterface_Insert = &IMPL::_SetInterface_Insert;
		_SetInterface_Insert_1 = &IMPL::_SetInterface_Insert_1;
		_SetInterface_Erase = &IMPL::_SetInterface_Erase;
		_SetInterface_Erase_1 = &IMPL::_SetInterface_Erase_1;
		_SetInterface_Reset = &IMPL::_SetInterface_Reset;
		_SetInterface_Flush = &IMPL::_SetInterface_Flush;
		_SetInterface_CopyFrom = &IMPL::_SetInterface_CopyFrom;
		_SetInterface_Clone = &IMPL::_SetInterface_Clone;
		_SetInterface_GetValueDataType = &IMPL::_SetInterface_GetValueDataType;
		_SetInterface_ToString = &IMPL::_SetInterface_ToString;
		_SetInterface_GetMemorySize = &IMPL::_SetInterface_GetMemorySize;
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
		_SetInterface_IteratorInit = &IMPL::_SetInterface_IteratorInit;
		_SetInterface_IteratorInit_1 = &IMPL::_SetInterface_IteratorInit_1;
		_SetInterface_IteratorInitMove = &IMPL::_SetInterface_IteratorInitMove;
		_SetInterface_IteratorInitMove_1 = &IMPL::_SetInterface_IteratorInitMove_1;
		_SetInterface_IteratorFree = &IMPL::_SetInterface_IteratorFree;
		_SetInterface_IteratorFree_1 = &IMPL::_SetInterface_IteratorFree_1;
		_SetInterface_IteratorIsEqual = &IMPL::_SetInterface_IteratorIsEqual;
		_SetInterface_IteratorIsEqual_1 = &IMPL::_SetInterface_IteratorIsEqual_1;
		_SetInterface_IteratorInc = &IMPL::_SetInterface_IteratorInc;
		_SetInterface_IteratorInc_1 = &IMPL::_SetInterface_IteratorInc_1;
		_SetInterface_IteratorGet = &IMPL::_SetInterface_IteratorGet;
		_SetInterface_IteratorGet_1 = &IMPL::_SetInterface_IteratorGet_1;
	}
};

template <typename TYPE> struct SetInterface<TYPE>::Hxx2
{
	template <typename C> class Wrapper
	{
	public:
	static void _SetInterface_Free(const SetInterface* object) { return C::Free((const C*) object); }
	static Int _SetInterface_GetCount(const SetInterface* this_) { return ((const C*) this_)->GetCount(); }
	static Bool _SetInterface_Contains(const SetInterface* this_, const TYPE& value) { return ((const C*) this_)->Contains(value); }
	static Result<void> _SetInterface_Insert(SetInterface* this_, const TYPE& value, Bool& added) { return ((C*) this_)->Insert(value, added); }
	static Result<void> _SetInterface_Insert_1(SetInterface* this_, TYPE&& value, Bool& added) { return ((C*) this_)->Insert(std::forward<TYPE>(value), added); }
	static Result<Bool> _SetInterface_Erase(SetInterface* this_, const TYPE& value) { return ((C*) this_)->Erase(value); }
	static Iterator _SetInterface_Erase_1(SetInterface* this_, const Iterator& iterator) { return ((C*) this_)->Erase(iterator); }
	static void _SetInterface_Reset(SetInterface* this_) { return ((C*) this_)->Reset(); }
	static void _SetInterface_Flush(SetInterface* this_) { return ((C*) this_)->Flush(); }
	static Result<void> _SetInterface_CopyFrom(SetInterface* this_, const SetInterface& other) { return ((C*) this_)->CopyFrom(other); }
	static Result<SetInterface*> _SetInterface_Clone(const SetInterface* this_, Bool cloneElements) { return ((const C*) this_)->Clone(cloneElements); }
	static const DataType& _SetInterface_GetValueDataType(const SetInterface* this_) { return ((const C*) this_)->GetValueDataType(); }
	static String _SetInterface_ToString(const SetInterface* this_, const FormatStatement* formatStatement) { return ((const C*) this_)->ToString(formatStatement); }
	static Int _SetInterface_GetMemorySize(const SetInterface* this_) { return ((const C*) this_)->GetMemorySize(); }
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
	static void _SetInterface_IteratorInit(SetInterface* this_, Iterator* it, Bool end) { return ((C*) this_)->IteratorInit(it, end); }
	static void _SetInterface_IteratorInit_1(const SetInterface* this_, ConstIterator* it, Bool end) { return ((const C*) this_)->IteratorInit(it, end); }
	static void _SetInterface_IteratorInitMove(const SetInterface* this_, Iterator* dest, Iterator* src) { return ((const C*) this_)->IteratorInitMove(dest, src); }
	static void _SetInterface_IteratorInitMove_1(const SetInterface* this_, ConstIterator* dest, ConstIterator* src) { return ((const C*) this_)->IteratorInitMove(dest, src); }
	static void _SetInterface_IteratorFree(const SetInterface* this_, Iterator* it) { return ((const C*) this_)->IteratorFree(it); }
	static void _SetInterface_IteratorFree_1(const SetInterface* this_, ConstIterator* it) { return ((const C*) this_)->IteratorFree(it); }
	static Bool _SetInterface_IteratorIsEqual(const SetInterface* this_, const Iterator* a, const Iterator* b) { return ((const C*) this_)->IteratorIsEqual(a, b); }
	static Bool _SetInterface_IteratorIsEqual_1(const SetInterface* this_, const ConstIterator* a, const ConstIterator* b) { return ((const C*) this_)->IteratorIsEqual(a, b); }
	static void _SetInterface_IteratorInc(const SetInterface* this_, Iterator* it) { return ((const C*) this_)->IteratorInc(it); }
	static void _SetInterface_IteratorInc_1(const SetInterface* this_, ConstIterator* it) { return ((const C*) this_)->IteratorInc(it); }
	static const TYPE* _SetInterface_IteratorGet(const SetInterface* this_, const Iterator* it) { return ((const C*) this_)->IteratorGet(it); }
	static const TYPE* _SetInterface_IteratorGet_1(const SetInterface* this_, const ConstIterator* it) { return ((const C*) this_)->IteratorGet(it); }
	};

};
template <typename TYPE> MAXON_ATTRIBUTE_FORCE_INLINE auto SetInterface<TYPE>::Free(const SetInterface* object) -> void
{
	if (!object)
		return;
	return ((SetInterface::MTable*) object->_vtable)->_SetInterface_Free(object);
}
template <typename TYPE> MAXON_ATTRIBUTE_FORCE_INLINE auto SetInterface<TYPE>::GetCount() const -> Int
{
	return ((SetInterface::MTable*) this->_vtable)->_SetInterface_GetCount(this);
}
template <typename TYPE> MAXON_ATTRIBUTE_FORCE_INLINE auto SetInterface<TYPE>::Contains(const TYPE& value) const -> Bool
{
	return ((SetInterface::MTable*) this->_vtable)->_SetInterface_Contains(this, value);
}
template <typename TYPE> MAXON_ATTRIBUTE_FORCE_INLINE auto SetInterface<TYPE>::Insert(const TYPE& value, Bool& added) -> Result<void>
{
	return ((SetInterface::MTable*) this->_vtable)->_SetInterface_Insert(this, value, added);
}
template <typename TYPE> MAXON_ATTRIBUTE_FORCE_INLINE auto SetInterface<TYPE>::Insert(TYPE&& value, Bool& added) -> Result<void>
{
	return ((SetInterface::MTable*) this->_vtable)->_SetInterface_Insert_1(this, std::forward<TYPE>(value), added);
}
template <typename TYPE> MAXON_ATTRIBUTE_FORCE_INLINE auto SetInterface<TYPE>::Erase(const TYPE& value) -> Result<Bool>
{
	return ((SetInterface::MTable*) this->_vtable)->_SetInterface_Erase(this, value);
}
template <typename TYPE> MAXON_ATTRIBUTE_FORCE_INLINE auto SetInterface<TYPE>::Erase(const Iterator& iterator) -> Iterator
{
	return ((SetInterface::MTable*) this->_vtable)->_SetInterface_Erase_1(this, iterator);
}
template <typename TYPE> MAXON_ATTRIBUTE_FORCE_INLINE auto SetInterface<TYPE>::Reset() -> void
{
	return ((SetInterface::MTable*) this->_vtable)->_SetInterface_Reset(this);
}
template <typename TYPE> MAXON_ATTRIBUTE_FORCE_INLINE auto SetInterface<TYPE>::Flush() -> void
{
	return ((SetInterface::MTable*) this->_vtable)->_SetInterface_Flush(this);
}
template <typename TYPE> MAXON_ATTRIBUTE_FORCE_INLINE auto SetInterface<TYPE>::CopyFrom(const SetInterface& other) -> Result<void>
{
	return ((SetInterface::MTable*) this->_vtable)->_SetInterface_CopyFrom(this, other);
}
template <typename TYPE> MAXON_ATTRIBUTE_FORCE_INLINE auto SetInterface<TYPE>::Clone(Bool cloneElements) const -> Result<SetInterface*>
{
	return ((SetInterface::MTable*) this->_vtable)->_SetInterface_Clone(this, cloneElements);
}
template <typename TYPE> MAXON_ATTRIBUTE_FORCE_INLINE auto SetInterface<TYPE>::GetValueDataType() const -> const DataType&
{
	return ((SetInterface::MTable*) this->_vtable)->_SetInterface_GetValueDataType(this);
}
template <typename TYPE> MAXON_ATTRIBUTE_FORCE_INLINE auto SetInterface<TYPE>::ToString(const FormatStatement* formatStatement) const -> String
{
	return ((SetInterface::MTable*) this->_vtable)->_SetInterface_ToString(this, formatStatement);
}
template <typename TYPE> MAXON_ATTRIBUTE_FORCE_INLINE auto SetInterface<TYPE>::GetMemorySize() const -> Int
{
	return ((SetInterface::MTable*) this->_vtable)->_SetInterface_GetMemorySize(this);
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
template <typename TYPE> MAXON_ATTRIBUTE_FORCE_INLINE auto SetInterface<TYPE>::IteratorInit(Iterator* it, Bool end) -> void
{
	return ((SetInterface::MTable*) this->_vtable)->_SetInterface_IteratorInit(this, it, end);
}
template <typename TYPE> MAXON_ATTRIBUTE_FORCE_INLINE auto SetInterface<TYPE>::IteratorInit(ConstIterator* it, Bool end) const -> void
{
	return ((SetInterface::MTable*) this->_vtable)->_SetInterface_IteratorInit_1(this, it, end);
}
template <typename TYPE> MAXON_ATTRIBUTE_FORCE_INLINE auto SetInterface<TYPE>::IteratorInitMove(Iterator* dest, Iterator* src) const -> void
{
	return ((SetInterface::MTable*) this->_vtable)->_SetInterface_IteratorInitMove(this, dest, src);
}
template <typename TYPE> MAXON_ATTRIBUTE_FORCE_INLINE auto SetInterface<TYPE>::IteratorInitMove(ConstIterator* dest, ConstIterator* src) const -> void
{
	return ((SetInterface::MTable*) this->_vtable)->_SetInterface_IteratorInitMove_1(this, dest, src);
}
template <typename TYPE> MAXON_ATTRIBUTE_FORCE_INLINE auto SetInterface<TYPE>::IteratorFree(Iterator* it) const -> void
{
	return ((SetInterface::MTable*) this->_vtable)->_SetInterface_IteratorFree(this, it);
}
template <typename TYPE> MAXON_ATTRIBUTE_FORCE_INLINE auto SetInterface<TYPE>::IteratorFree(ConstIterator* it) const -> void
{
	return ((SetInterface::MTable*) this->_vtable)->_SetInterface_IteratorFree_1(this, it);
}
template <typename TYPE> MAXON_ATTRIBUTE_FORCE_INLINE auto SetInterface<TYPE>::IteratorIsEqual(const Iterator* a, const Iterator* b) const -> Bool
{
	return ((SetInterface::MTable*) this->_vtable)->_SetInterface_IteratorIsEqual(this, a, b);
}
template <typename TYPE> MAXON_ATTRIBUTE_FORCE_INLINE auto SetInterface<TYPE>::IteratorIsEqual(const ConstIterator* a, const ConstIterator* b) const -> Bool
{
	return ((SetInterface::MTable*) this->_vtable)->_SetInterface_IteratorIsEqual_1(this, a, b);
}
template <typename TYPE> MAXON_ATTRIBUTE_FORCE_INLINE auto SetInterface<TYPE>::IteratorInc(Iterator* it) const -> void
{
	return ((SetInterface::MTable*) this->_vtable)->_SetInterface_IteratorInc(this, it);
}
template <typename TYPE> MAXON_ATTRIBUTE_FORCE_INLINE auto SetInterface<TYPE>::IteratorInc(ConstIterator* it) const -> void
{
	return ((SetInterface::MTable*) this->_vtable)->_SetInterface_IteratorInc_1(this, it);
}
template <typename TYPE> MAXON_ATTRIBUTE_FORCE_INLINE auto SetInterface<TYPE>::IteratorGet(const Iterator* it) const -> const TYPE*
{
	return ((SetInterface::MTable*) this->_vtable)->_SetInterface_IteratorGet(this, it);
}
template <typename TYPE> MAXON_ATTRIBUTE_FORCE_INLINE auto SetInterface<TYPE>::IteratorGet(const ConstIterator* it) const -> const TYPE*
{
	return ((SetInterface::MTable*) this->_vtable)->_SetInterface_IteratorGet_1(this, it);
}

template <typename TYPE> template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto SetInterface<TYPE>::Hxx1::ConstReferenceFunctionsImpl<S>::GetCount() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const SetInterface* o_ = (const SetInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = SetInterface::NullValuePtr(); if (!o_) return 0; } 
	return (((SetInterface::MTable*) o_->_vtable)->_SetInterface_GetCount(o_));
}
template <typename TYPE> template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto SetInterface<TYPE>::Hxx1::ConstReferenceFunctionsImpl<S>::IsEmpty() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const SetInterface* o_ = (const SetInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = SetInterface::NullValuePtr(); if (!o_) return true; } 
	return (o_->IsEmpty());
}
template <typename TYPE> template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto SetInterface<TYPE>::Hxx1::ConstReferenceFunctionsImpl<S>::IsPopulated() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const SetInterface* o_ = (const SetInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = SetInterface::NullValuePtr(); if (!o_) return maxon::PrivateLogNullptrError(false); } 
	return (o_->IsPopulated());
}
template <typename TYPE> template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto SetInterface<TYPE>::Hxx1::ConstReferenceFunctionsImpl<S>::Contains(const TYPE& value) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const SetInterface* o_ = (const SetInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = SetInterface::NullValuePtr(); if (!o_) return maxon::PrivateLogNullptrError(false); } 
	return (((SetInterface::MTable*) o_->_vtable)->_SetInterface_Contains(o_, value));
}
template <typename TYPE> template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto SetInterface<TYPE>::Hxx1::ReferenceFunctionsImpl<S>::Insert(const TYPE& value, Bool& added) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); SetInterface* o_ = (SetInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); 
	return (((SetInterface::MTable*) o_->_vtable)->_SetInterface_Insert(o_, value, added));
}
template <typename TYPE> template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto SetInterface<TYPE>::Hxx1::COWReferenceFunctionsImpl<S>::Insert(const TYPE& value, Bool& added) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); SetInterface* o_ = (SetInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); 
	return (((SetInterface::MTable*) o_->_vtable)->_SetInterface_Insert(o_, value, added));
}
template <typename TYPE> template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto SetInterface<TYPE>::Hxx1::ReferenceFunctionsImpl<S>::Insert(TYPE&& value, Bool& added) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); SetInterface* o_ = (SetInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); 
	return (((SetInterface::MTable*) o_->_vtable)->_SetInterface_Insert_1(o_, std::forward<TYPE>(value), added));
}
template <typename TYPE> template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto SetInterface<TYPE>::Hxx1::COWReferenceFunctionsImpl<S>::Insert(TYPE&& value, Bool& added) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); SetInterface* o_ = (SetInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); 
	return (((SetInterface::MTable*) o_->_vtable)->_SetInterface_Insert_1(o_, std::forward<TYPE>(value), added));
}
template <typename TYPE> template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto SetInterface<TYPE>::Hxx1::ReferenceFunctionsImpl<S>::Erase(const TYPE& value) const -> Result<Bool>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<Bool>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); SetInterface* o_ = (SetInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); 
	return (((SetInterface::MTable*) o_->_vtable)->_SetInterface_Erase(o_, value));
}
template <typename TYPE> template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto SetInterface<TYPE>::Hxx1::COWReferenceFunctionsImpl<S>::Erase(const TYPE& value) -> Result<Bool>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<Bool>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); SetInterface* o_ = (SetInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); 
	return (((SetInterface::MTable*) o_->_vtable)->_SetInterface_Erase(o_, value));
}
template <typename TYPE> template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto SetInterface<TYPE>::Hxx1::ReferenceFunctionsImpl<S>::Erase(const Iterator& iterator) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Iterator>, Iterator>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Iterator>, Iterator>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); SetInterface* o_ = (SetInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) return maxon::PrivateNullReturnValue<Iterator>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); 
	return (((SetInterface::MTable*) o_->_vtable)->_SetInterface_Erase_1(o_, iterator));
}
template <typename TYPE> template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto SetInterface<TYPE>::Hxx1::COWReferenceFunctionsImpl<S>::Erase(const Iterator& iterator) -> typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), Iterator, maxon::Result<Iterator>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), Iterator, maxon::Result<Iterator>>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); SetInterface* o_ = (SetInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); 
	return (((SetInterface::MTable*) o_->_vtable)->_SetInterface_Erase_1(o_, iterator));
}
template <typename TYPE> template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto SetInterface<TYPE>::Hxx1::ReferenceFunctionsImpl<S>::Reset() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); SetInterface* o_ = (SetInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) return maxon::PrivateLogNullptrError(); 
	((SetInterface::MTable*) o_->_vtable)->_SetInterface_Reset(o_);
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
template <typename TYPE> template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto SetInterface<TYPE>::Hxx1::COWReferenceFunctionsImpl<S>::Reset() -> typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), void, maxon::Result<void>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), void, maxon::Result<void>>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); SetInterface* o_ = (SetInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); 
	((SetInterface::MTable*) o_->_vtable)->_SetInterface_Reset(o_);
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
template <typename TYPE> template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto SetInterface<TYPE>::Hxx1::ReferenceFunctionsImpl<S>::Flush() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); SetInterface* o_ = (SetInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) return maxon::PrivateLogNullptrError(); 
	((SetInterface::MTable*) o_->_vtable)->_SetInterface_Flush(o_);
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
template <typename TYPE> template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto SetInterface<TYPE>::Hxx1::COWReferenceFunctionsImpl<S>::Flush() -> typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), void, maxon::Result<void>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), void, maxon::Result<void>>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); SetInterface* o_ = (SetInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); 
	((SetInterface::MTable*) o_->_vtable)->_SetInterface_Flush(o_);
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
template <typename TYPE> template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto SetInterface<TYPE>::Hxx1::ReferenceFunctionsImpl<S>::CopyFrom(const SetInterface& other) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); SetInterface* o_ = (SetInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); 
	return (((SetInterface::MTable*) o_->_vtable)->_SetInterface_CopyFrom(o_, other));
}
template <typename TYPE> template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto SetInterface<TYPE>::Hxx1::COWReferenceFunctionsImpl<S>::CopyFrom(const SetInterface& other) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); SetInterface* o_ = (SetInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); 
	return (((SetInterface::MTable*) o_->_vtable)->_SetInterface_CopyFrom(o_, other));
}
template <typename TYPE> template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto SetInterface<TYPE>::Hxx1::ConstReferenceFunctionsImpl<S>::Clone(Bool cloneElements) const -> Result<SetInterface*>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<SetInterface*>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const SetInterface* o_ = (const SetInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = SetInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (((SetInterface::MTable*) o_->_vtable)->_SetInterface_Clone(o_, cloneElements));
}
template <typename TYPE> template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto SetInterface<TYPE>::Hxx1::ConstReferenceFunctionsImpl<S>::GetValueDataType() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<const DataType&>, const DataType&>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<const DataType&>, const DataType&>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const SetInterface* o_ = (const SetInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = SetInterface::NullValuePtr(); if (!o_) return maxon::PrivateNullReturnValue<const DataType&>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } 
	return (((SetInterface::MTable*) o_->_vtable)->_SetInterface_GetValueDataType(o_));
}
template <typename TYPE> template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto SetInterface<TYPE>::Hxx1::ConstReferenceFunctionsImpl<S>::ToString(const FormatStatement* formatStatement) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<String>, String>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<String>, String>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const SetInterface* o_ = (const SetInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = SetInterface::NullValuePtr(); if (!o_) return maxon::PrivateNullReturnValue<String>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } 
	return (((SetInterface::MTable*) o_->_vtable)->_SetInterface_ToString(o_, formatStatement));
}
template <typename TYPE> template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto SetInterface<TYPE>::Hxx1::ConstReferenceFunctionsImpl<S>::GetMemorySize() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const SetInterface* o_ = (const SetInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = SetInterface::NullValuePtr(); if (!o_) return 0; } 
	return (((SetInterface::MTable*) o_->_vtable)->_SetInterface_GetMemorySize(o_));
}
template <typename TYPE> template <typename S> template <typename T> MAXON_ATTRIBUTE_FORCE_INLINE auto SetInterface<TYPE>::Hxx1::ConstReferenceFunctionsImpl<S>::HasType() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const SetInterface* o_ = (const SetInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = SetInterface::NullValuePtr(); if (!o_) return maxon::PrivateLogNullptrError(false); } 
	return (o_->HasType<T>());
}
template <typename TYPE> template <typename S> template <typename T> MAXON_ATTRIBUTE_FORCE_INLINE auto SetInterface<TYPE>::Hxx1::ConstReferenceFunctionsImpl<S>::AssertType() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const SetInterface* o_ = (const SetInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = SetInterface::NullValuePtr(); if (!o_) return maxon::PrivateLogNullptrError(); } 
	o_->AssertType<T>();
	return (typename ReturnHelper::ReturnType) maxon::OK;
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

