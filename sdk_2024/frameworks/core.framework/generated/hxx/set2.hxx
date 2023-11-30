
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
	PRIVATE_MAXON_MF_POINTER(SetInterface_GetCount, GetCount, false, SetInterface, const, (Int));
	PRIVATE_MAXON_MF_POINTER(SetInterface_Contains, Contains, false, SetInterface, const, (Bool), const TYPE& value);
	PRIVATE_MAXON_MF_POINTER(SetInterface_Insert, Insert, false, SetInterface,, (Result<void>), const TYPE& value, Bool& added);
	PRIVATE_MAXON_MF_POINTER(SetInterface_Insert_1, Insert, false, SetInterface,, (Result<void>), TYPE&& value, Bool& added);
	PRIVATE_MAXON_MF_POINTER(SetInterface_Erase, Erase, false, SetInterface,, (Result<Bool>), const TYPE& value);
	PRIVATE_MAXON_MF_POINTER(SetInterface_Erase_1, Erase, false, SetInterface,, (Iterator), const Iterator& iterator);
	PRIVATE_MAXON_MF_POINTER(SetInterface_Reset, Reset, false, SetInterface,, (void));
	PRIVATE_MAXON_MF_POINTER(SetInterface_Flush, Flush, false, SetInterface,, (void));
	PRIVATE_MAXON_MF_POINTER(SetInterface_CopyFrom, CopyFrom, false, SetInterface,, (Result<void>), const SetInterface& other);
	PRIVATE_MAXON_MF_POINTER(SetInterface_Clone, Clone, false, SetInterface, const, (Result<SetInterface*>), Bool copyContent);
	PRIVATE_MAXON_MF_POINTER(SetInterface_GetValueDataType, GetValueDataType, false, SetInterface, const, (const DataType&));
	PRIVATE_MAXON_MF_POINTER(SetInterface_ToString, ToString, false, SetInterface, const, (String), const FormatStatement* formatStatement);
	PRIVATE_MAXON_MF_POINTER(SetInterface_GetMemorySize, GetMemorySize, false, SetInterface, const, (Int));
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
	PRIVATE_MAXON_MF_POINTER(SetInterface_IteratorInit, IteratorInit, false, SetInterface,, (void), Iterator* it, Bool end);
	PRIVATE_MAXON_MF_POINTER(SetInterface_IteratorInit_1, IteratorInit, false, SetInterface, const, (void), ConstIterator* it, Bool end);
	PRIVATE_MAXON_MF_POINTER(SetInterface_IteratorInitMove, IteratorInitMove, false, SetInterface, const, (void), Iterator* dest, Iterator* src);
	PRIVATE_MAXON_MF_POINTER(SetInterface_IteratorInitMove_1, IteratorInitMove, false, SetInterface, const, (void), ConstIterator* dest, ConstIterator* src);
	PRIVATE_MAXON_MF_POINTER(SetInterface_IteratorFree, IteratorFree, false, SetInterface, const, (void), Iterator* it);
	PRIVATE_MAXON_MF_POINTER(SetInterface_IteratorFree_1, IteratorFree, false, SetInterface, const, (void), ConstIterator* it);
	PRIVATE_MAXON_MF_POINTER(SetInterface_IteratorIsEqual, IteratorIsEqual, false, SetInterface, const, (Bool), const Iterator* a, const Iterator* b);
	PRIVATE_MAXON_MF_POINTER(SetInterface_IteratorIsEqual_1, IteratorIsEqual, false, SetInterface, const, (Bool), const ConstIterator* a, const ConstIterator* b);
	PRIVATE_MAXON_MF_POINTER(SetInterface_IteratorInc, IteratorInc, false, SetInterface, const, (void), Iterator* it);
	PRIVATE_MAXON_MF_POINTER(SetInterface_IteratorInc_1, IteratorInc, false, SetInterface, const, (void), ConstIterator* it);
	PRIVATE_MAXON_MF_POINTER(SetInterface_IteratorGet, IteratorGet, false, SetInterface, const, (const TYPE*), const Iterator* it);
	PRIVATE_MAXON_MF_POINTER(SetInterface_IteratorGet_1, IteratorGet, false, SetInterface, const, (const TYPE*), const ConstIterator* it);
	maxon::ClassInfoBase _info;
	template <typename IMPL> void Init()
	{
		void (*free) (const SetInterface*) = &IMPL::Implementation::Free;
		_info._free = reinterpret_cast<void(*)(const void*)>(free);
		_info.PrivateInitName(maxon::details::GetTypeNameHelper<typename IMPL::Implementation>());
		SetInterface_GetCount = SetInterface_GetCount_GetPtr<IMPL>(0, true).first;
		SetInterface_Contains = SetInterface_Contains_GetPtr<IMPL>(0, true).first;
		SetInterface_Insert = SetInterface_Insert_GetPtr<IMPL>(0, true).first;
		SetInterface_Insert_1 = SetInterface_Insert_1_GetPtr<IMPL>(0, true).first;
		SetInterface_Erase = SetInterface_Erase_GetPtr<IMPL>(0, true).first;
		SetInterface_Erase_1 = SetInterface_Erase_1_GetPtr<IMPL>(0, true).first;
		SetInterface_Reset = SetInterface_Reset_GetPtr<IMPL>(0, true).first;
		SetInterface_Flush = SetInterface_Flush_GetPtr<IMPL>(0, true).first;
		SetInterface_CopyFrom = SetInterface_CopyFrom_GetPtr<IMPL>(0, true).first;
		SetInterface_Clone = SetInterface_Clone_GetPtr<IMPL>(0, true).first;
		SetInterface_GetValueDataType = SetInterface_GetValueDataType_GetPtr<IMPL>(0, true).first;
		SetInterface_ToString = SetInterface_ToString_GetPtr<IMPL>(0, true).first;
		SetInterface_GetMemorySize = SetInterface_GetMemorySize_GetPtr<IMPL>(0, true).first;
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
		SetInterface_IteratorInit = SetInterface_IteratorInit_GetPtr<IMPL>(0, true).first;
		SetInterface_IteratorInit_1 = SetInterface_IteratorInit_1_GetPtr<IMPL>(0, true).first;
		SetInterface_IteratorInitMove = SetInterface_IteratorInitMove_GetPtr<IMPL>(0, true).first;
		SetInterface_IteratorInitMove_1 = SetInterface_IteratorInitMove_1_GetPtr<IMPL>(0, true).first;
		SetInterface_IteratorFree = SetInterface_IteratorFree_GetPtr<IMPL>(0, true).first;
		SetInterface_IteratorFree_1 = SetInterface_IteratorFree_1_GetPtr<IMPL>(0, true).first;
		SetInterface_IteratorIsEqual = SetInterface_IteratorIsEqual_GetPtr<IMPL>(0, true).first;
		SetInterface_IteratorIsEqual_1 = SetInterface_IteratorIsEqual_1_GetPtr<IMPL>(0, true).first;
		SetInterface_IteratorInc = SetInterface_IteratorInc_GetPtr<IMPL>(0, true).first;
		SetInterface_IteratorInc_1 = SetInterface_IteratorInc_1_GetPtr<IMPL>(0, true).first;
		SetInterface_IteratorGet = SetInterface_IteratorGet_GetPtr<IMPL>(0, true).first;
		SetInterface_IteratorGet_1 = SetInterface_IteratorGet_1_GetPtr<IMPL>(0, true).first;
	}
	template <typename W> static maxon::Bool InitWithBases(maxon::ClassInfo* info, maxon::Int offset) { return true; }
	template <typename S> using CombinedMTable = S;
};

template <typename TYPE> struct SetInterface<TYPE>::Hxx2
{
	template <typename C> using CWrapper = C;
	template <typename S> class Wrapper
	{
	public:
		using Implementation = S;
		PRIVATE_MAXON_MF_WRAPPER(SetInterface_GetCount, SetInterface, const, (Int)) { return S::Get(PRIVATE_MAXON_MF_THIS(const SetInterface))->GetCount(); }
		PRIVATE_MAXON_MF_WRAPPER(SetInterface_Contains, SetInterface, const, (Bool), const TYPE& value) { return S::Get(PRIVATE_MAXON_MF_THIS(const SetInterface))->Contains(value); }
		PRIVATE_MAXON_MF_WRAPPER(SetInterface_Insert, SetInterface,, (Result<void>), const TYPE& value, Bool& added) { return S::Get(PRIVATE_MAXON_MF_THIS(SetInterface))->Insert(value, added); }
		PRIVATE_MAXON_MF_WRAPPER(SetInterface_Insert_1, SetInterface,, (Result<void>), TYPE&& value, Bool& added) { return S::Get(PRIVATE_MAXON_MF_THIS(SetInterface))->Insert(std::forward<TYPE>(value), added); }
		PRIVATE_MAXON_MF_WRAPPER(SetInterface_Erase, SetInterface,, (Result<Bool>), const TYPE& value) { return S::Get(PRIVATE_MAXON_MF_THIS(SetInterface))->Erase(value); }
		PRIVATE_MAXON_MF_WRAPPER(SetInterface_Erase_1, SetInterface,, (Iterator), const Iterator& iterator) { return S::Get(PRIVATE_MAXON_MF_THIS(SetInterface))->Erase(iterator); }
		PRIVATE_MAXON_MF_WRAPPER(SetInterface_Reset, SetInterface,, (void)) { return S::Get(PRIVATE_MAXON_MF_THIS(SetInterface))->Reset(); }
		PRIVATE_MAXON_MF_WRAPPER(SetInterface_Flush, SetInterface,, (void)) { return S::Get(PRIVATE_MAXON_MF_THIS(SetInterface))->Flush(); }
		PRIVATE_MAXON_MF_WRAPPER(SetInterface_CopyFrom, SetInterface,, (Result<void>), const SetInterface& other) { return S::Get(PRIVATE_MAXON_MF_THIS(SetInterface))->CopyFrom(other); }
		PRIVATE_MAXON_MF_WRAPPER(SetInterface_Clone, SetInterface, const, (Result<SetInterface*>), Bool copyContent) { return S::Get(PRIVATE_MAXON_MF_THIS(const SetInterface))->Clone(copyContent); }
		PRIVATE_MAXON_MF_WRAPPER(SetInterface_GetValueDataType, SetInterface, const, (const DataType&)) { return S::Get(PRIVATE_MAXON_MF_THIS(const SetInterface))->GetValueDataType(); }
		PRIVATE_MAXON_MF_WRAPPER(SetInterface_ToString, SetInterface, const, (String), const FormatStatement* formatStatement) { return S::Get(PRIVATE_MAXON_MF_THIS(const SetInterface))->ToString(formatStatement); }
		PRIVATE_MAXON_MF_WRAPPER(SetInterface_GetMemorySize, SetInterface, const, (Int)) { return S::Get(PRIVATE_MAXON_MF_THIS(const SetInterface))->GetMemorySize(); }
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
		PRIVATE_MAXON_MF_WRAPPER(SetInterface_IteratorInit, SetInterface,, (void), Iterator* it, Bool end) { return S::Get(PRIVATE_MAXON_MF_THIS(SetInterface))->IteratorInit(it, end); }
		PRIVATE_MAXON_MF_WRAPPER(SetInterface_IteratorInit_1, SetInterface, const, (void), ConstIterator* it, Bool end) { return S::Get(PRIVATE_MAXON_MF_THIS(const SetInterface))->IteratorInit(it, end); }
		PRIVATE_MAXON_MF_WRAPPER(SetInterface_IteratorInitMove, SetInterface, const, (void), Iterator* dest, Iterator* src) { return S::Get(PRIVATE_MAXON_MF_THIS(const SetInterface))->IteratorInitMove(dest, src); }
		PRIVATE_MAXON_MF_WRAPPER(SetInterface_IteratorInitMove_1, SetInterface, const, (void), ConstIterator* dest, ConstIterator* src) { return S::Get(PRIVATE_MAXON_MF_THIS(const SetInterface))->IteratorInitMove(dest, src); }
		PRIVATE_MAXON_MF_WRAPPER(SetInterface_IteratorFree, SetInterface, const, (void), Iterator* it) { return S::Get(PRIVATE_MAXON_MF_THIS(const SetInterface))->IteratorFree(it); }
		PRIVATE_MAXON_MF_WRAPPER(SetInterface_IteratorFree_1, SetInterface, const, (void), ConstIterator* it) { return S::Get(PRIVATE_MAXON_MF_THIS(const SetInterface))->IteratorFree(it); }
		PRIVATE_MAXON_MF_WRAPPER(SetInterface_IteratorIsEqual, SetInterface, const, (Bool), const Iterator* a, const Iterator* b) { return S::Get(PRIVATE_MAXON_MF_THIS(const SetInterface))->IteratorIsEqual(a, b); }
		PRIVATE_MAXON_MF_WRAPPER(SetInterface_IteratorIsEqual_1, SetInterface, const, (Bool), const ConstIterator* a, const ConstIterator* b) { return S::Get(PRIVATE_MAXON_MF_THIS(const SetInterface))->IteratorIsEqual(a, b); }
		PRIVATE_MAXON_MF_WRAPPER(SetInterface_IteratorInc, SetInterface, const, (void), Iterator* it) { return S::Get(PRIVATE_MAXON_MF_THIS(const SetInterface))->IteratorInc(it); }
		PRIVATE_MAXON_MF_WRAPPER(SetInterface_IteratorInc_1, SetInterface, const, (void), ConstIterator* it) { return S::Get(PRIVATE_MAXON_MF_THIS(const SetInterface))->IteratorInc(it); }
		PRIVATE_MAXON_MF_WRAPPER(SetInterface_IteratorGet, SetInterface, const, (const TYPE*), const Iterator* it) { return S::Get(PRIVATE_MAXON_MF_THIS(const SetInterface))->IteratorGet(it); }
		PRIVATE_MAXON_MF_WRAPPER(SetInterface_IteratorGet_1, SetInterface, const, (const TYPE*), const ConstIterator* it) { return S::Get(PRIVATE_MAXON_MF_THIS(const SetInterface))->IteratorGet(it); }
	};

};
template <typename TYPE> MAXON_ATTRIBUTE_FORCE_INLINE auto SetInterface<TYPE>::GetCount() const -> Int
{
	return PRIVATE_MAXON_MF_INVOKE((this), ((SetInterface::MTable*) (this->_vtableCls + 1))[-1].SetInterface_GetCount);
}
template <typename TYPE> MAXON_ATTRIBUTE_FORCE_INLINE auto SetInterface<TYPE>::Contains(const TYPE& value) const -> Bool
{
	return PRIVATE_MAXON_MF_INVOKE((this), ((SetInterface::MTable*) (this->_vtableCls + 1))[-1].SetInterface_Contains, value);
}
template <typename TYPE> MAXON_ATTRIBUTE_FORCE_INLINE auto SetInterface<TYPE>::Insert(const TYPE& value, Bool& added) -> Result<void>
{
	return PRIVATE_MAXON_MF_INVOKE((this), ((SetInterface::MTable*) (this->_vtableCls + 1))[-1].SetInterface_Insert, value, added);
}
template <typename TYPE> MAXON_ATTRIBUTE_FORCE_INLINE auto SetInterface<TYPE>::Insert(TYPE&& value, Bool& added) -> Result<void>
{
	return PRIVATE_MAXON_MF_INVOKE((this), ((SetInterface::MTable*) (this->_vtableCls + 1))[-1].SetInterface_Insert_1, std::forward<TYPE>(value), added);
}
template <typename TYPE> MAXON_ATTRIBUTE_FORCE_INLINE auto SetInterface<TYPE>::Erase(const TYPE& value) -> Result<Bool>
{
	return PRIVATE_MAXON_MF_INVOKE((this), ((SetInterface::MTable*) (this->_vtableCls + 1))[-1].SetInterface_Erase, value);
}
template <typename TYPE> MAXON_ATTRIBUTE_FORCE_INLINE auto SetInterface<TYPE>::Erase(const Iterator& iterator) -> Iterator
{
	return PRIVATE_MAXON_MF_INVOKE((this), ((SetInterface::MTable*) (this->_vtableCls + 1))[-1].SetInterface_Erase_1, iterator);
}
template <typename TYPE> MAXON_ATTRIBUTE_FORCE_INLINE auto SetInterface<TYPE>::Reset() -> void
{
	return PRIVATE_MAXON_MF_INVOKE((this), ((SetInterface::MTable*) (this->_vtableCls + 1))[-1].SetInterface_Reset);
}
template <typename TYPE> MAXON_ATTRIBUTE_FORCE_INLINE auto SetInterface<TYPE>::Flush() -> void
{
	return PRIVATE_MAXON_MF_INVOKE((this), ((SetInterface::MTable*) (this->_vtableCls + 1))[-1].SetInterface_Flush);
}
template <typename TYPE> MAXON_ATTRIBUTE_FORCE_INLINE auto SetInterface<TYPE>::CopyFrom(const SetInterface& other) -> Result<void>
{
	return PRIVATE_MAXON_MF_INVOKE((this), ((SetInterface::MTable*) (this->_vtableCls + 1))[-1].SetInterface_CopyFrom, other);
}
template <typename TYPE> MAXON_ATTRIBUTE_FORCE_INLINE auto SetInterface<TYPE>::Clone(Bool copyContent) const -> Result<SetInterface*>
{
	return PRIVATE_MAXON_MF_INVOKE((this), ((SetInterface::MTable*) (this->_vtableCls + 1))[-1].SetInterface_Clone, copyContent);
}
template <typename TYPE> MAXON_ATTRIBUTE_FORCE_INLINE auto SetInterface<TYPE>::GetValueDataType() const -> const DataType&
{
	return PRIVATE_MAXON_MF_INVOKE((this), ((SetInterface::MTable*) (this->_vtableCls + 1))[-1].SetInterface_GetValueDataType);
}
template <typename TYPE> MAXON_ATTRIBUTE_FORCE_INLINE auto SetInterface<TYPE>::ToString(const FormatStatement* formatStatement) const -> String
{
	return PRIVATE_MAXON_MF_INVOKE((this), ((SetInterface::MTable*) (this->_vtableCls + 1))[-1].SetInterface_ToString, formatStatement);
}
template <typename TYPE> MAXON_ATTRIBUTE_FORCE_INLINE auto SetInterface<TYPE>::GetMemorySize() const -> Int
{
	return PRIVATE_MAXON_MF_INVOKE((this), ((SetInterface::MTable*) (this->_vtableCls + 1))[-1].SetInterface_GetMemorySize);
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
	return PRIVATE_MAXON_MF_INVOKE((this), ((SetInterface::MTable*) (this->_vtableCls + 1))[-1].SetInterface_IteratorInit, it, end);
}
template <typename TYPE> MAXON_ATTRIBUTE_FORCE_INLINE auto SetInterface<TYPE>::IteratorInit(ConstIterator* it, Bool end) const -> void
{
	return PRIVATE_MAXON_MF_INVOKE((this), ((SetInterface::MTable*) (this->_vtableCls + 1))[-1].SetInterface_IteratorInit_1, it, end);
}
template <typename TYPE> MAXON_ATTRIBUTE_FORCE_INLINE auto SetInterface<TYPE>::IteratorInitMove(Iterator* dest, Iterator* src) const -> void
{
	return PRIVATE_MAXON_MF_INVOKE((this), ((SetInterface::MTable*) (this->_vtableCls + 1))[-1].SetInterface_IteratorInitMove, dest, src);
}
template <typename TYPE> MAXON_ATTRIBUTE_FORCE_INLINE auto SetInterface<TYPE>::IteratorInitMove(ConstIterator* dest, ConstIterator* src) const -> void
{
	return PRIVATE_MAXON_MF_INVOKE((this), ((SetInterface::MTable*) (this->_vtableCls + 1))[-1].SetInterface_IteratorInitMove_1, dest, src);
}
template <typename TYPE> MAXON_ATTRIBUTE_FORCE_INLINE auto SetInterface<TYPE>::IteratorFree(Iterator* it) const -> void
{
	return PRIVATE_MAXON_MF_INVOKE((this), ((SetInterface::MTable*) (this->_vtableCls + 1))[-1].SetInterface_IteratorFree, it);
}
template <typename TYPE> MAXON_ATTRIBUTE_FORCE_INLINE auto SetInterface<TYPE>::IteratorFree(ConstIterator* it) const -> void
{
	return PRIVATE_MAXON_MF_INVOKE((this), ((SetInterface::MTable*) (this->_vtableCls + 1))[-1].SetInterface_IteratorFree_1, it);
}
template <typename TYPE> MAXON_ATTRIBUTE_FORCE_INLINE auto SetInterface<TYPE>::IteratorIsEqual(const Iterator* a, const Iterator* b) const -> Bool
{
	return PRIVATE_MAXON_MF_INVOKE((this), ((SetInterface::MTable*) (this->_vtableCls + 1))[-1].SetInterface_IteratorIsEqual, a, b);
}
template <typename TYPE> MAXON_ATTRIBUTE_FORCE_INLINE auto SetInterface<TYPE>::IteratorIsEqual(const ConstIterator* a, const ConstIterator* b) const -> Bool
{
	return PRIVATE_MAXON_MF_INVOKE((this), ((SetInterface::MTable*) (this->_vtableCls + 1))[-1].SetInterface_IteratorIsEqual_1, a, b);
}
template <typename TYPE> MAXON_ATTRIBUTE_FORCE_INLINE auto SetInterface<TYPE>::IteratorInc(Iterator* it) const -> void
{
	return PRIVATE_MAXON_MF_INVOKE((this), ((SetInterface::MTable*) (this->_vtableCls + 1))[-1].SetInterface_IteratorInc, it);
}
template <typename TYPE> MAXON_ATTRIBUTE_FORCE_INLINE auto SetInterface<TYPE>::IteratorInc(ConstIterator* it) const -> void
{
	return PRIVATE_MAXON_MF_INVOKE((this), ((SetInterface::MTable*) (this->_vtableCls + 1))[-1].SetInterface_IteratorInc_1, it);
}
template <typename TYPE> MAXON_ATTRIBUTE_FORCE_INLINE auto SetInterface<TYPE>::IteratorGet(const Iterator* it) const -> const TYPE*
{
	return PRIVATE_MAXON_MF_INVOKE((this), ((SetInterface::MTable*) (this->_vtableCls + 1))[-1].SetInterface_IteratorGet, it);
}
template <typename TYPE> MAXON_ATTRIBUTE_FORCE_INLINE auto SetInterface<TYPE>::IteratorGet(const ConstIterator* it) const -> const TYPE*
{
	return PRIVATE_MAXON_MF_INVOKE((this), ((SetInterface::MTable*) (this->_vtableCls + 1))[-1].SetInterface_IteratorGet_1, it);
}

template <typename TYPE> SetInterface<TYPE>::SetInterface(const MTable& vtable) : _vtableCls(&vtable._info) { }
template <typename TYPE> template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto SetInterface<TYPE>::Hxx1::ConstFn<S>::GetCount() const -> HXXADDRET2(Int)
{
	HXXRETURN0(HXXADDRET2(Int)); HXXRES; HXXCONST(0) 
	return (PRIVATE_MAXON_MF_INVOKE((o_), ((SetInterface::MTable*) (o_->_vtableCls + 1))[-1].SetInterface_GetCount));
}
template <typename TYPE> template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto SetInterface<TYPE>::Hxx1::ConstFn<S>::IsEmpty() const -> HXXADDRET2(Bool)
{
	HXXRETURN0(HXXADDRET2(Bool)); HXXRES; HXXCONST(true) 
	return (o_->IsEmpty());
}
template <typename TYPE> template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto SetInterface<TYPE>::Hxx1::ConstFn<S>::IsPopulated() const -> HXXADDRET2(Bool)
{
	HXXRETURN0(HXXADDRET2(Bool)); HXXRES; HXXCONST(maxon::PrivateLogNullptrError(false)) 
	return (o_->IsPopulated());
}
template <typename TYPE> template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto SetInterface<TYPE>::Hxx1::ConstFn<S>::Contains(const TYPE& value) const -> HXXADDRET2(Bool)
{
	HXXRETURN0(HXXADDRET2(Bool)); HXXRES; HXXCONST(maxon::PrivateLogNullptrError(false)) 
	return (PRIVATE_MAXON_MF_INVOKE((o_), ((SetInterface::MTable*) (o_->_vtableCls + 1))[-1].SetInterface_Contains, value));
}
template <typename TYPE> template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto SetInterface<TYPE>::Hxx1::Fn<S>::Insert(const TYPE& value, Bool& added) const -> Result<void>
{
	HXXRETURN0(Result<void>); HXXRES; HXXNONCONST(, , false, HXXRET1(NULLPTR)) 
	return (PRIVATE_MAXON_MF_INVOKE((o_), ((SetInterface::MTable*) (o_->_vtableCls + 1))[-1].SetInterface_Insert, value, added));
}
template <typename TYPE> template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto SetInterface<TYPE>::Hxx1::COWFn<S>::Insert(const TYPE& value, Bool& added) -> Result<void>
{
	HXXRETURN0(Result<void>); HXXRES; HXXNONCONST(, MakeWritable(true)., true, HXXRET2a(HXXRET1(MAKE_WRITABLE_FAILED))) 
	return (PRIVATE_MAXON_MF_INVOKE((o_), ((SetInterface::MTable*) (o_->_vtableCls + 1))[-1].SetInterface_Insert, value, added));
}
template <typename TYPE> template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto SetInterface<TYPE>::Hxx1::Fn<S>::Insert(TYPE&& value, Bool& added) const -> Result<void>
{
	HXXRETURN0(Result<void>); HXXRES; HXXNONCONST(, , false, HXXRET1(NULLPTR)) 
	return (PRIVATE_MAXON_MF_INVOKE((o_), ((SetInterface::MTable*) (o_->_vtableCls + 1))[-1].SetInterface_Insert_1, std::forward<TYPE>(value), added));
}
template <typename TYPE> template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto SetInterface<TYPE>::Hxx1::COWFn<S>::Insert(TYPE&& value, Bool& added) -> Result<void>
{
	HXXRETURN0(Result<void>); HXXRES; HXXNONCONST(, MakeWritable(true)., true, HXXRET2a(HXXRET1(MAKE_WRITABLE_FAILED))) 
	return (PRIVATE_MAXON_MF_INVOKE((o_), ((SetInterface::MTable*) (o_->_vtableCls + 1))[-1].SetInterface_Insert_1, std::forward<TYPE>(value), added));
}
template <typename TYPE> template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto SetInterface<TYPE>::Hxx1::Fn<S>::Erase(const TYPE& value) const -> Result<Bool>
{
	HXXRETURN0(Result<Bool>); HXXRES; HXXNONCONST(, , false, HXXRET1(NULLPTR)) 
	return (PRIVATE_MAXON_MF_INVOKE((o_), ((SetInterface::MTable*) (o_->_vtableCls + 1))[-1].SetInterface_Erase, value));
}
template <typename TYPE> template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto SetInterface<TYPE>::Hxx1::COWFn<S>::Erase(const TYPE& value) -> Result<Bool>
{
	HXXRETURN0(Result<Bool>); HXXRES; HXXNONCONST(, MakeWritable(true)., true, HXXRET2a(HXXRET1(MAKE_WRITABLE_FAILED))) 
	return (PRIVATE_MAXON_MF_INVOKE((o_), ((SetInterface::MTable*) (o_->_vtableCls + 1))[-1].SetInterface_Erase, value));
}
template <typename TYPE> template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto SetInterface<TYPE>::Hxx1::Fn<S>::Erase(const Iterator& iterator) const -> HXXADDRET2(Iterator)
{
	HXXRETURN0(HXXADDRET2(Iterator)); HXXRES; HXXNONCONST(, , false, maxon::PrivateDefaultReturnValue<Iterator>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK)) 
	return (PRIVATE_MAXON_MF_INVOKE((o_), ((SetInterface::MTable*) (o_->_vtableCls + 1))[-1].SetInterface_Erase_1, iterator));
}
template <typename TYPE> template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto SetInterface<TYPE>::Hxx1::COWFn<S>::Erase(const Iterator& iterator) -> HXXADDRET1(Iterator)
{
	HXXRETURN0(HXXADDRET1(Iterator)); HXXRES; HXXNONCONST(, MakeWritable(true)., true, HXXRET2a(HXXRET1(MAKE_WRITABLE_FAILED))) 
	return (PRIVATE_MAXON_MF_INVOKE((o_), ((SetInterface::MTable*) (o_->_vtableCls + 1))[-1].SetInterface_Erase_1, iterator));
}
template <typename TYPE> template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto SetInterface<TYPE>::Hxx1::Fn<S>::Reset() const -> HXXADDRET2(void)
{
	HXXRETURN0(HXXADDRET2(void)); HXXRES; HXXNONCONST(DebugStop(), , false, maxon::PrivateLogNullptrError()) 
	PRIVATE_MAXON_MF_INVOKE((o_), ((SetInterface::MTable*) (o_->_vtableCls + 1))[-1].SetInterface_Reset);
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
template <typename TYPE> template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto SetInterface<TYPE>::Hxx1::COWFn<S>::Reset() -> HXXADDRET1(void)
{
	HXXRETURN0(HXXADDRET1(void)); HXXRES; HXXNONCONST(, MakeWritable(true)., true, HXXRET2a(HXXRET1(MAKE_WRITABLE_FAILED))) 
	PRIVATE_MAXON_MF_INVOKE((o_), ((SetInterface::MTable*) (o_->_vtableCls + 1))[-1].SetInterface_Reset);
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
template <typename TYPE> template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto SetInterface<TYPE>::Hxx1::Fn<S>::Flush() const -> HXXADDRET2(void)
{
	HXXRETURN0(HXXADDRET2(void)); HXXRES; HXXNONCONST(DebugStop(), , false, maxon::PrivateLogNullptrError()) 
	PRIVATE_MAXON_MF_INVOKE((o_), ((SetInterface::MTable*) (o_->_vtableCls + 1))[-1].SetInterface_Flush);
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
template <typename TYPE> template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto SetInterface<TYPE>::Hxx1::COWFn<S>::Flush() -> HXXADDRET1(void)
{
	HXXRETURN0(HXXADDRET1(void)); HXXRES; HXXNONCONST(, MakeWritable(true)., true, HXXRET2a(HXXRET1(MAKE_WRITABLE_FAILED))) 
	PRIVATE_MAXON_MF_INVOKE((o_), ((SetInterface::MTable*) (o_->_vtableCls + 1))[-1].SetInterface_Flush);
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
template <typename TYPE> template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto SetInterface<TYPE>::Hxx1::Fn<S>::CopyFrom(const SetInterface& other) const -> Result<void>
{
	HXXRETURN0(Result<void>); HXXRES; HXXNONCONST(, , false, HXXRET1(NULLPTR)) 
	return (PRIVATE_MAXON_MF_INVOKE((o_), ((SetInterface::MTable*) (o_->_vtableCls + 1))[-1].SetInterface_CopyFrom, other));
}
template <typename TYPE> template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto SetInterface<TYPE>::Hxx1::COWFn<S>::CopyFrom(const SetInterface& other) -> Result<void>
{
	HXXRETURN0(Result<void>); HXXRES; HXXNONCONST(, MakeWritable(true)., true, HXXRET2a(HXXRET1(MAKE_WRITABLE_FAILED))) 
	return (PRIVATE_MAXON_MF_INVOKE((o_), ((SetInterface::MTable*) (o_->_vtableCls + 1))[-1].SetInterface_CopyFrom, other));
}
template <typename TYPE> template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto SetInterface<TYPE>::Hxx1::ConstFn<S>::Clone(Bool copyContent) const -> Result<SetInterface*>
{
	HXXRETURN0(Result<SetInterface*>); HXXRES; HXXCONST(HXXRET1(NULLPTR)) 
	return (PRIVATE_MAXON_MF_INVOKE((o_), ((SetInterface::MTable*) (o_->_vtableCls + 1))[-1].SetInterface_Clone, copyContent));
}
template <typename TYPE> template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto SetInterface<TYPE>::Hxx1::ConstFn<S>::GetValueDataType() const -> HXXADDRET2(const DataType&)
{
	HXXRETURN0(HXXADDRET2(const DataType&)); HXXRES; HXXCONST(maxon::PrivateDefaultReturnValue<const DataType&>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK)) 
	return (PRIVATE_MAXON_MF_INVOKE((o_), ((SetInterface::MTable*) (o_->_vtableCls + 1))[-1].SetInterface_GetValueDataType));
}
template <typename TYPE> template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto SetInterface<TYPE>::Hxx1::ConstFn<S>::ToString(const FormatStatement* formatStatement) const -> HXXADDRET2(String)
{
	HXXRETURN0(HXXADDRET2(String)); HXXRES; HXXCONST(maxon::PrivateDefaultReturnValue<String>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK)) 
	return (PRIVATE_MAXON_MF_INVOKE((o_), ((SetInterface::MTable*) (o_->_vtableCls + 1))[-1].SetInterface_ToString, formatStatement));
}
template <typename TYPE> template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto SetInterface<TYPE>::Hxx1::ConstFn<S>::GetMemorySize() const -> HXXADDRET2(Int)
{
	HXXRETURN0(HXXADDRET2(Int)); HXXRES; HXXCONST(0) 
	return (PRIVATE_MAXON_MF_INVOKE((o_), ((SetInterface::MTable*) (o_->_vtableCls + 1))[-1].SetInterface_GetMemorySize));
}
template <typename TYPE> template <typename S> template <typename T> MAXON_ATTRIBUTE_FORCE_INLINE auto SetInterface<TYPE>::Hxx1::ConstFn<S>::HasType() const -> HXXADDRET2(Bool)
{
	HXXRETURN0(HXXADDRET2(Bool)); HXXRES; HXXCONST(maxon::PrivateLogNullptrError(false)) 
	return (o_->HasType<T>());
}
template <typename TYPE> template <typename S> template <typename T> MAXON_ATTRIBUTE_FORCE_INLINE auto SetInterface<TYPE>::Hxx1::ConstFn<S>::AssertType() const -> HXXADDRET2(void)
{
	HXXRETURN0(HXXADDRET2(void)); HXXRES; HXXCONST(maxon::PrivateLogNullptrError()) 
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

