
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
	Int (*SetInterface_GetCount) (const SetInterface* this_);
	Bool (*SetInterface_Contains) (const SetInterface* this_, const TYPE& value);
	Result<void> (*SetInterface_Insert) (SetInterface* this_, const TYPE& value, Bool& added);
	Result<void> (*SetInterface_Insert_1) (SetInterface* this_, TYPE&& value, Bool& added);
	Result<Bool> (*SetInterface_Erase) (SetInterface* this_, const TYPE& value);
	Iterator (*SetInterface_Erase_1) (SetInterface* this_, const Iterator& iterator);
	void (*SetInterface_Reset) (SetInterface* this_);
	void (*SetInterface_Flush) (SetInterface* this_);
	Result<void> (*SetInterface_CopyFrom) (SetInterface* this_, const SetInterface& other);
	Result<SetInterface*> (*SetInterface_Clone) (const SetInterface* this_, Bool copyContent);
	const DataType& (*SetInterface_GetValueDataType) (const SetInterface* this_);
	String (*SetInterface_ToString) (const SetInterface* this_, const FormatStatement* formatStatement);
	Int (*SetInterface_GetMemorySize) (const SetInterface* this_);
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
	void (*SetInterface_IteratorInit) (SetInterface* this_, Iterator* it, Bool end);
	void (*SetInterface_IteratorInit_1) (const SetInterface* this_, ConstIterator* it, Bool end);
	void (*SetInterface_IteratorInitMove) (const SetInterface* this_, Iterator* dest, Iterator* src);
	void (*SetInterface_IteratorInitMove_1) (const SetInterface* this_, ConstIterator* dest, ConstIterator* src);
	void (*SetInterface_IteratorFree) (const SetInterface* this_, Iterator* it);
	void (*SetInterface_IteratorFree_1) (const SetInterface* this_, ConstIterator* it);
	Bool (*SetInterface_IteratorIsEqual) (const SetInterface* this_, const Iterator* a, const Iterator* b);
	Bool (*SetInterface_IteratorIsEqual_1) (const SetInterface* this_, const ConstIterator* a, const ConstIterator* b);
	void (*SetInterface_IteratorInc) (const SetInterface* this_, Iterator* it);
	void (*SetInterface_IteratorInc_1) (const SetInterface* this_, ConstIterator* it);
	const TYPE* (*SetInterface_IteratorGet) (const SetInterface* this_, const Iterator* it);
	const TYPE* (*SetInterface_IteratorGet_1) (const SetInterface* this_, const ConstIterator* it);
	maxon::ClassInfoBase _info;
	template <typename IMPL> void Init()
	{
		void (*free) (const SetInterface*) = &IMPL::Implementation::Free;
		_info._free = reinterpret_cast<void(*)(const void*)>(free);
		SetInterface_GetCount = &IMPL::SetInterface_GetCount;
		SetInterface_Contains = &IMPL::SetInterface_Contains;
		SetInterface_Insert = &IMPL::SetInterface_Insert;
		SetInterface_Insert_1 = &IMPL::SetInterface_Insert_1;
		SetInterface_Erase = &IMPL::SetInterface_Erase;
		SetInterface_Erase_1 = &IMPL::SetInterface_Erase_1;
		SetInterface_Reset = &IMPL::SetInterface_Reset;
		SetInterface_Flush = &IMPL::SetInterface_Flush;
		SetInterface_CopyFrom = &IMPL::SetInterface_CopyFrom;
		SetInterface_Clone = &IMPL::SetInterface_Clone;
		SetInterface_GetValueDataType = &IMPL::SetInterface_GetValueDataType;
		SetInterface_ToString = &IMPL::SetInterface_ToString;
		SetInterface_GetMemorySize = &IMPL::SetInterface_GetMemorySize;
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
		SetInterface_IteratorInit = &IMPL::SetInterface_IteratorInit;
		SetInterface_IteratorInit_1 = &IMPL::SetInterface_IteratorInit_1;
		SetInterface_IteratorInitMove = &IMPL::SetInterface_IteratorInitMove;
		SetInterface_IteratorInitMove_1 = &IMPL::SetInterface_IteratorInitMove_1;
		SetInterface_IteratorFree = &IMPL::SetInterface_IteratorFree;
		SetInterface_IteratorFree_1 = &IMPL::SetInterface_IteratorFree_1;
		SetInterface_IteratorIsEqual = &IMPL::SetInterface_IteratorIsEqual;
		SetInterface_IteratorIsEqual_1 = &IMPL::SetInterface_IteratorIsEqual_1;
		SetInterface_IteratorInc = &IMPL::SetInterface_IteratorInc;
		SetInterface_IteratorInc_1 = &IMPL::SetInterface_IteratorInc_1;
		SetInterface_IteratorGet = &IMPL::SetInterface_IteratorGet;
		SetInterface_IteratorGet_1 = &IMPL::SetInterface_IteratorGet_1;
	}
	template <typename W> static maxon::Bool InitWithBases(maxon::ClassInfo* info, maxon::Int offset) { return true; }
	template <typename S> using CombinedMTable = S;
};

template <typename TYPE> struct SetInterface<TYPE>::Hxx2
{
	template <typename C> using CWrapper = C;
	template <typename C> class Wrapper
	{
	public:
		using Implementation = C;
		static Int SetInterface_GetCount(const SetInterface* this_) { return C::Get(this_)->GetCount(); }
		static Bool SetInterface_Contains(const SetInterface* this_, const TYPE& value) { return C::Get(this_)->Contains(value); }
		static Result<void> SetInterface_Insert(SetInterface* this_, const TYPE& value, Bool& added) { return C::Get(this_)->Insert(value, added); }
		static Result<void> SetInterface_Insert_1(SetInterface* this_, TYPE&& value, Bool& added) { return C::Get(this_)->Insert(std::forward<TYPE>(value), added); }
		static Result<Bool> SetInterface_Erase(SetInterface* this_, const TYPE& value) { return C::Get(this_)->Erase(value); }
		static Iterator SetInterface_Erase_1(SetInterface* this_, const Iterator& iterator) { return C::Get(this_)->Erase(iterator); }
		static void SetInterface_Reset(SetInterface* this_) { return C::Get(this_)->Reset(); }
		static void SetInterface_Flush(SetInterface* this_) { return C::Get(this_)->Flush(); }
		static Result<void> SetInterface_CopyFrom(SetInterface* this_, const SetInterface& other) { return C::Get(this_)->CopyFrom(other); }
		static Result<SetInterface*> SetInterface_Clone(const SetInterface* this_, Bool copyContent) { return C::Get(this_)->Clone(copyContent); }
		static const DataType& SetInterface_GetValueDataType(const SetInterface* this_) { return C::Get(this_)->GetValueDataType(); }
		static String SetInterface_ToString(const SetInterface* this_, const FormatStatement* formatStatement) { return C::Get(this_)->ToString(formatStatement); }
		static Int SetInterface_GetMemorySize(const SetInterface* this_) { return C::Get(this_)->GetMemorySize(); }
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
		static void SetInterface_IteratorInit(SetInterface* this_, Iterator* it, Bool end) { return C::Get(this_)->IteratorInit(it, end); }
		static void SetInterface_IteratorInit_1(const SetInterface* this_, ConstIterator* it, Bool end) { return C::Get(this_)->IteratorInit(it, end); }
		static void SetInterface_IteratorInitMove(const SetInterface* this_, Iterator* dest, Iterator* src) { return C::Get(this_)->IteratorInitMove(dest, src); }
		static void SetInterface_IteratorInitMove_1(const SetInterface* this_, ConstIterator* dest, ConstIterator* src) { return C::Get(this_)->IteratorInitMove(dest, src); }
		static void SetInterface_IteratorFree(const SetInterface* this_, Iterator* it) { return C::Get(this_)->IteratorFree(it); }
		static void SetInterface_IteratorFree_1(const SetInterface* this_, ConstIterator* it) { return C::Get(this_)->IteratorFree(it); }
		static Bool SetInterface_IteratorIsEqual(const SetInterface* this_, const Iterator* a, const Iterator* b) { return C::Get(this_)->IteratorIsEqual(a, b); }
		static Bool SetInterface_IteratorIsEqual_1(const SetInterface* this_, const ConstIterator* a, const ConstIterator* b) { return C::Get(this_)->IteratorIsEqual(a, b); }
		static void SetInterface_IteratorInc(const SetInterface* this_, Iterator* it) { return C::Get(this_)->IteratorInc(it); }
		static void SetInterface_IteratorInc_1(const SetInterface* this_, ConstIterator* it) { return C::Get(this_)->IteratorInc(it); }
		static const TYPE* SetInterface_IteratorGet(const SetInterface* this_, const Iterator* it) { return C::Get(this_)->IteratorGet(it); }
		static const TYPE* SetInterface_IteratorGet_1(const SetInterface* this_, const ConstIterator* it) { return C::Get(this_)->IteratorGet(it); }
	};

};
template <typename TYPE> MAXON_ATTRIBUTE_FORCE_INLINE auto SetInterface<TYPE>::GetCount() const -> Int
{
	return ((SetInterface::MTable*) (this->_vtableCls + 1))[-1].SetInterface_GetCount(this);
}
template <typename TYPE> MAXON_ATTRIBUTE_FORCE_INLINE auto SetInterface<TYPE>::Contains(const TYPE& value) const -> Bool
{
	return ((SetInterface::MTable*) (this->_vtableCls + 1))[-1].SetInterface_Contains(this, value);
}
template <typename TYPE> MAXON_ATTRIBUTE_FORCE_INLINE auto SetInterface<TYPE>::Insert(const TYPE& value, Bool& added) -> Result<void>
{
	return ((SetInterface::MTable*) (this->_vtableCls + 1))[-1].SetInterface_Insert(this, value, added);
}
template <typename TYPE> MAXON_ATTRIBUTE_FORCE_INLINE auto SetInterface<TYPE>::Insert(TYPE&& value, Bool& added) -> Result<void>
{
	return ((SetInterface::MTable*) (this->_vtableCls + 1))[-1].SetInterface_Insert_1(this, std::forward<TYPE>(value), added);
}
template <typename TYPE> MAXON_ATTRIBUTE_FORCE_INLINE auto SetInterface<TYPE>::Erase(const TYPE& value) -> Result<Bool>
{
	return ((SetInterface::MTable*) (this->_vtableCls + 1))[-1].SetInterface_Erase(this, value);
}
template <typename TYPE> MAXON_ATTRIBUTE_FORCE_INLINE auto SetInterface<TYPE>::Erase(const Iterator& iterator) -> Iterator
{
	return ((SetInterface::MTable*) (this->_vtableCls + 1))[-1].SetInterface_Erase_1(this, iterator);
}
template <typename TYPE> MAXON_ATTRIBUTE_FORCE_INLINE auto SetInterface<TYPE>::Reset() -> void
{
	return ((SetInterface::MTable*) (this->_vtableCls + 1))[-1].SetInterface_Reset(this);
}
template <typename TYPE> MAXON_ATTRIBUTE_FORCE_INLINE auto SetInterface<TYPE>::Flush() -> void
{
	return ((SetInterface::MTable*) (this->_vtableCls + 1))[-1].SetInterface_Flush(this);
}
template <typename TYPE> MAXON_ATTRIBUTE_FORCE_INLINE auto SetInterface<TYPE>::CopyFrom(const SetInterface& other) -> Result<void>
{
	return ((SetInterface::MTable*) (this->_vtableCls + 1))[-1].SetInterface_CopyFrom(this, other);
}
template <typename TYPE> MAXON_ATTRIBUTE_FORCE_INLINE auto SetInterface<TYPE>::Clone(Bool copyContent) const -> Result<SetInterface*>
{
	return ((SetInterface::MTable*) (this->_vtableCls + 1))[-1].SetInterface_Clone(this, copyContent);
}
template <typename TYPE> MAXON_ATTRIBUTE_FORCE_INLINE auto SetInterface<TYPE>::GetValueDataType() const -> const DataType&
{
	return ((SetInterface::MTable*) (this->_vtableCls + 1))[-1].SetInterface_GetValueDataType(this);
}
template <typename TYPE> MAXON_ATTRIBUTE_FORCE_INLINE auto SetInterface<TYPE>::ToString(const FormatStatement* formatStatement) const -> String
{
	return ((SetInterface::MTable*) (this->_vtableCls + 1))[-1].SetInterface_ToString(this, formatStatement);
}
template <typename TYPE> MAXON_ATTRIBUTE_FORCE_INLINE auto SetInterface<TYPE>::GetMemorySize() const -> Int
{
	return ((SetInterface::MTable*) (this->_vtableCls + 1))[-1].SetInterface_GetMemorySize(this);
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
	return ((SetInterface::MTable*) (this->_vtableCls + 1))[-1].SetInterface_IteratorInit(this, it, end);
}
template <typename TYPE> MAXON_ATTRIBUTE_FORCE_INLINE auto SetInterface<TYPE>::IteratorInit(ConstIterator* it, Bool end) const -> void
{
	return ((SetInterface::MTable*) (this->_vtableCls + 1))[-1].SetInterface_IteratorInit_1(this, it, end);
}
template <typename TYPE> MAXON_ATTRIBUTE_FORCE_INLINE auto SetInterface<TYPE>::IteratorInitMove(Iterator* dest, Iterator* src) const -> void
{
	return ((SetInterface::MTable*) (this->_vtableCls + 1))[-1].SetInterface_IteratorInitMove(this, dest, src);
}
template <typename TYPE> MAXON_ATTRIBUTE_FORCE_INLINE auto SetInterface<TYPE>::IteratorInitMove(ConstIterator* dest, ConstIterator* src) const -> void
{
	return ((SetInterface::MTable*) (this->_vtableCls + 1))[-1].SetInterface_IteratorInitMove_1(this, dest, src);
}
template <typename TYPE> MAXON_ATTRIBUTE_FORCE_INLINE auto SetInterface<TYPE>::IteratorFree(Iterator* it) const -> void
{
	return ((SetInterface::MTable*) (this->_vtableCls + 1))[-1].SetInterface_IteratorFree(this, it);
}
template <typename TYPE> MAXON_ATTRIBUTE_FORCE_INLINE auto SetInterface<TYPE>::IteratorFree(ConstIterator* it) const -> void
{
	return ((SetInterface::MTable*) (this->_vtableCls + 1))[-1].SetInterface_IteratorFree_1(this, it);
}
template <typename TYPE> MAXON_ATTRIBUTE_FORCE_INLINE auto SetInterface<TYPE>::IteratorIsEqual(const Iterator* a, const Iterator* b) const -> Bool
{
	return ((SetInterface::MTable*) (this->_vtableCls + 1))[-1].SetInterface_IteratorIsEqual(this, a, b);
}
template <typename TYPE> MAXON_ATTRIBUTE_FORCE_INLINE auto SetInterface<TYPE>::IteratorIsEqual(const ConstIterator* a, const ConstIterator* b) const -> Bool
{
	return ((SetInterface::MTable*) (this->_vtableCls + 1))[-1].SetInterface_IteratorIsEqual_1(this, a, b);
}
template <typename TYPE> MAXON_ATTRIBUTE_FORCE_INLINE auto SetInterface<TYPE>::IteratorInc(Iterator* it) const -> void
{
	return ((SetInterface::MTable*) (this->_vtableCls + 1))[-1].SetInterface_IteratorInc(this, it);
}
template <typename TYPE> MAXON_ATTRIBUTE_FORCE_INLINE auto SetInterface<TYPE>::IteratorInc(ConstIterator* it) const -> void
{
	return ((SetInterface::MTable*) (this->_vtableCls + 1))[-1].SetInterface_IteratorInc_1(this, it);
}
template <typename TYPE> MAXON_ATTRIBUTE_FORCE_INLINE auto SetInterface<TYPE>::IteratorGet(const Iterator* it) const -> const TYPE*
{
	return ((SetInterface::MTable*) (this->_vtableCls + 1))[-1].SetInterface_IteratorGet(this, it);
}
template <typename TYPE> MAXON_ATTRIBUTE_FORCE_INLINE auto SetInterface<TYPE>::IteratorGet(const ConstIterator* it) const -> const TYPE*
{
	return ((SetInterface::MTable*) (this->_vtableCls + 1))[-1].SetInterface_IteratorGet_1(this, it);
}

template <typename TYPE> SetInterface<TYPE>::SetInterface(const MTable& vtable) : _vtableCls(&vtable._info) { }
template <typename TYPE> template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto SetInterface<TYPE>::Hxx1::ConstFn<S>::GetCount() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const SetInterface* o_ = (const SetInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = SetInterface::NullValuePtr(); if (!o_) return 0; } 
	return (((SetInterface::MTable*) (o_->_vtableCls + 1))[-1].SetInterface_GetCount(o_));
}
template <typename TYPE> template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto SetInterface<TYPE>::Hxx1::ConstFn<S>::IsEmpty() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const SetInterface* o_ = (const SetInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = SetInterface::NullValuePtr(); if (!o_) return true; } 
	return (o_->IsEmpty());
}
template <typename TYPE> template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto SetInterface<TYPE>::Hxx1::ConstFn<S>::IsPopulated() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const SetInterface* o_ = (const SetInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = SetInterface::NullValuePtr(); if (!o_) return maxon::PrivateLogNullptrError(false); } 
	return (o_->IsPopulated());
}
template <typename TYPE> template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto SetInterface<TYPE>::Hxx1::ConstFn<S>::Contains(const TYPE& value) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const SetInterface* o_ = (const SetInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = SetInterface::NullValuePtr(); if (!o_) return maxon::PrivateLogNullptrError(false); } 
	return (((SetInterface::MTable*) (o_->_vtableCls + 1))[-1].SetInterface_Contains(o_, value));
}
template <typename TYPE> template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto SetInterface<TYPE>::Hxx1::Fn<S>::Insert(const TYPE& value, Bool& added) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); SetInterface* o_ = (SetInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (((SetInterface::MTable*) (o_->_vtableCls + 1))[-1].SetInterface_Insert(o_, value, added));
}
template <typename TYPE> template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto SetInterface<TYPE>::Hxx1::COWFn<S>::Insert(const TYPE& value, Bool& added) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); SetInterface* o_ = (SetInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } 
	return (((SetInterface::MTable*) (o_->_vtableCls + 1))[-1].SetInterface_Insert(o_, value, added));
}
template <typename TYPE> template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto SetInterface<TYPE>::Hxx1::Fn<S>::Insert(TYPE&& value, Bool& added) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); SetInterface* o_ = (SetInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (((SetInterface::MTable*) (o_->_vtableCls + 1))[-1].SetInterface_Insert_1(o_, std::forward<TYPE>(value), added));
}
template <typename TYPE> template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto SetInterface<TYPE>::Hxx1::COWFn<S>::Insert(TYPE&& value, Bool& added) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); SetInterface* o_ = (SetInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } 
	return (((SetInterface::MTable*) (o_->_vtableCls + 1))[-1].SetInterface_Insert_1(o_, std::forward<TYPE>(value), added));
}
template <typename TYPE> template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto SetInterface<TYPE>::Hxx1::Fn<S>::Erase(const TYPE& value) const -> Result<Bool>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<Bool>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); SetInterface* o_ = (SetInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (((SetInterface::MTable*) (o_->_vtableCls + 1))[-1].SetInterface_Erase(o_, value));
}
template <typename TYPE> template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto SetInterface<TYPE>::Hxx1::COWFn<S>::Erase(const TYPE& value) -> Result<Bool>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<Bool>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); SetInterface* o_ = (SetInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } 
	return (((SetInterface::MTable*) (o_->_vtableCls + 1))[-1].SetInterface_Erase(o_, value));
}
template <typename TYPE> template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto SetInterface<TYPE>::Hxx1::Fn<S>::Erase(const Iterator& iterator) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Iterator>, Iterator>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Iterator>, Iterator>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); SetInterface* o_ = (SetInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateNullReturnValue<Iterator>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } 
	return (((SetInterface::MTable*) (o_->_vtableCls + 1))[-1].SetInterface_Erase_1(o_, iterator));
}
template <typename TYPE> template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto SetInterface<TYPE>::Hxx1::COWFn<S>::Erase(const Iterator& iterator) -> typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), Iterator, maxon::Result<Iterator>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), Iterator, maxon::Result<Iterator>>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); SetInterface* o_ = (SetInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } 
	return (((SetInterface::MTable*) (o_->_vtableCls + 1))[-1].SetInterface_Erase_1(o_, iterator));
}
template <typename TYPE> template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto SetInterface<TYPE>::Hxx1::Fn<S>::Reset() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); SetInterface* o_ = (SetInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { DebugStop(); return maxon::PrivateLogNullptrError(); } 
	((SetInterface::MTable*) (o_->_vtableCls + 1))[-1].SetInterface_Reset(o_);
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
template <typename TYPE> template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto SetInterface<TYPE>::Hxx1::COWFn<S>::Reset() -> typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), void, maxon::Result<void>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), void, maxon::Result<void>>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); SetInterface* o_ = (SetInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } 
	((SetInterface::MTable*) (o_->_vtableCls + 1))[-1].SetInterface_Reset(o_);
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
template <typename TYPE> template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto SetInterface<TYPE>::Hxx1::Fn<S>::Flush() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); SetInterface* o_ = (SetInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { DebugStop(); return maxon::PrivateLogNullptrError(); } 
	((SetInterface::MTable*) (o_->_vtableCls + 1))[-1].SetInterface_Flush(o_);
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
template <typename TYPE> template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto SetInterface<TYPE>::Hxx1::COWFn<S>::Flush() -> typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), void, maxon::Result<void>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), void, maxon::Result<void>>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); SetInterface* o_ = (SetInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } 
	((SetInterface::MTable*) (o_->_vtableCls + 1))[-1].SetInterface_Flush(o_);
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
template <typename TYPE> template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto SetInterface<TYPE>::Hxx1::Fn<S>::CopyFrom(const SetInterface& other) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); SetInterface* o_ = (SetInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (((SetInterface::MTable*) (o_->_vtableCls + 1))[-1].SetInterface_CopyFrom(o_, other));
}
template <typename TYPE> template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto SetInterface<TYPE>::Hxx1::COWFn<S>::CopyFrom(const SetInterface& other) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); SetInterface* o_ = (SetInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } 
	return (((SetInterface::MTable*) (o_->_vtableCls + 1))[-1].SetInterface_CopyFrom(o_, other));
}
template <typename TYPE> template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto SetInterface<TYPE>::Hxx1::ConstFn<S>::Clone(Bool copyContent) const -> Result<SetInterface*>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<SetInterface*>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const SetInterface* o_ = (const SetInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = SetInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (((SetInterface::MTable*) (o_->_vtableCls + 1))[-1].SetInterface_Clone(o_, copyContent));
}
template <typename TYPE> template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto SetInterface<TYPE>::Hxx1::ConstFn<S>::GetValueDataType() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<const DataType&>, const DataType&>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<const DataType&>, const DataType&>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const SetInterface* o_ = (const SetInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = SetInterface::NullValuePtr(); if (!o_) return maxon::PrivateNullReturnValue<const DataType&>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } 
	return (((SetInterface::MTable*) (o_->_vtableCls + 1))[-1].SetInterface_GetValueDataType(o_));
}
template <typename TYPE> template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto SetInterface<TYPE>::Hxx1::ConstFn<S>::ToString(const FormatStatement* formatStatement) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<String>, String>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<String>, String>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const SetInterface* o_ = (const SetInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = SetInterface::NullValuePtr(); if (!o_) return maxon::PrivateNullReturnValue<String>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } 
	return (((SetInterface::MTable*) (o_->_vtableCls + 1))[-1].SetInterface_ToString(o_, formatStatement));
}
template <typename TYPE> template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto SetInterface<TYPE>::Hxx1::ConstFn<S>::GetMemorySize() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const SetInterface* o_ = (const SetInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = SetInterface::NullValuePtr(); if (!o_) return 0; } 
	return (((SetInterface::MTable*) (o_->_vtableCls + 1))[-1].SetInterface_GetMemorySize(o_));
}
template <typename TYPE> template <typename S> template <typename T> MAXON_ATTRIBUTE_FORCE_INLINE auto SetInterface<TYPE>::Hxx1::ConstFn<S>::HasType() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const SetInterface* o_ = (const SetInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = SetInterface::NullValuePtr(); if (!o_) return maxon::PrivateLogNullptrError(false); } 
	return (o_->HasType<T>());
}
template <typename TYPE> template <typename S> template <typename T> MAXON_ATTRIBUTE_FORCE_INLINE auto SetInterface<TYPE>::Hxx1::ConstFn<S>::AssertType() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type
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

