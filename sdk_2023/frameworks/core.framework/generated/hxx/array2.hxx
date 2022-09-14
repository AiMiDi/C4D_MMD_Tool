
#ifndef DOXYGEN

#if defined MAXON_COMPILER_GCC
	#pragma GCC diagnostic push
	#if MAXON_COMPILER_GCC >= 600
		#pragma GCC diagnostic ignored "-Wmisleading-indentation"
	#endif
#endif

#if 1

struct PersistentIdGeneratorInterface::MTable
{
	MTable() { }
	template <typename C> explicit MTable(C*) { Init<typename maxon::SFINAEHelper<Hxx2, C>::type::template Wrapper<C>>(); }
	template <typename C> MTable(C*, maxon::Bool) { Init<C>(); }
	PRIVATE_MAXON_MF_POINTER(PersistentIdGeneratorInterface_InitializeBuffer, InitializeBuffer, false, PersistentIdGeneratorInterface, const, (Result<void>), PersistentIdBuffer& buffer);
	PRIVATE_MAXON_MF_POINTER(PersistentIdGeneratorInterface_FreeBuffer, FreeBuffer, false, PersistentIdGeneratorInterface, const, (void), PersistentIdBuffer& buffer);
	PRIVATE_MAXON_MF_POINTER(PersistentIdGeneratorInterface_Move, Move, false, PersistentIdGeneratorInterface, const, (Result<void>), Int index, PersistentIdBuffer& buffer);
	PRIVATE_MAXON_MF_POINTER(PersistentIdGeneratorInterface_Advance, Advance, false, PersistentIdGeneratorInterface, const, (Result<void>), Int index, PersistentIdBuffer& buffer);
	maxon::ClassInfoBase _info;
	template <typename IMPL> void Init()
	{
		void (*free) (const PersistentIdGeneratorInterface*) = &IMPL::Implementation::Free;
		_info._free = reinterpret_cast<void(*)(const void*)>(free);
		_info.PrivateInitName(maxon::details::GetTypeNameHelper<typename IMPL::Implementation>());
		PersistentIdGeneratorInterface_InitializeBuffer = PersistentIdGeneratorInterface_InitializeBuffer_GetPtr<IMPL>(0, true).first;
		PersistentIdGeneratorInterface_FreeBuffer = PersistentIdGeneratorInterface_FreeBuffer_GetPtr<IMPL>(0, true).first;
		PersistentIdGeneratorInterface_Move = PersistentIdGeneratorInterface_Move_GetPtr<IMPL>(0, true).first;
		PersistentIdGeneratorInterface_Advance = PersistentIdGeneratorInterface_Advance_GetPtr<IMPL>(0, true).first;
	}
	template <typename W> static maxon::Bool InitWithBases(maxon::ClassInfo* info, maxon::Int offset) { return true; }
	template <typename S> using CombinedMTable = S;
};

struct PersistentIdGeneratorInterface::Hxx2
{
	template <typename C> using CWrapper = C;
	template <typename C> class Wrapper
	{
	public:
		using Implementation = C;
		PRIVATE_MAXON_MF_WRAPPER(PersistentIdGeneratorInterface_InitializeBuffer, PersistentIdGeneratorInterface, const, (Result<void>), PersistentIdBuffer& buffer) { return C::Get(PRIVATE_MAXON_MF_THIS(const PersistentIdGeneratorInterface))->InitializeBuffer(buffer); }
		PRIVATE_MAXON_MF_WRAPPER(PersistentIdGeneratorInterface_FreeBuffer, PersistentIdGeneratorInterface, const, (void), PersistentIdBuffer& buffer) { return C::Get(PRIVATE_MAXON_MF_THIS(const PersistentIdGeneratorInterface))->FreeBuffer(buffer); }
		PRIVATE_MAXON_MF_WRAPPER(PersistentIdGeneratorInterface_Move, PersistentIdGeneratorInterface, const, (Result<void>), Int index, PersistentIdBuffer& buffer) { return C::Get(PRIVATE_MAXON_MF_THIS(const PersistentIdGeneratorInterface))->Move(index, buffer); }
		PRIVATE_MAXON_MF_WRAPPER(PersistentIdGeneratorInterface_Advance, PersistentIdGeneratorInterface, const, (Result<void>), Int index, PersistentIdBuffer& buffer) { return C::Get(PRIVATE_MAXON_MF_THIS(const PersistentIdGeneratorInterface))->Advance(index, buffer); }
	};

};
MAXON_ATTRIBUTE_FORCE_INLINE auto PersistentIdGeneratorInterface::InitializeBuffer(PersistentIdBuffer& buffer) const -> Result<void>
{
	return PRIVATE_MAXON_MF_INVOKE((this), ((PersistentIdGeneratorInterface::MTable*) (this->_vtableCls + 1))[-1].PersistentIdGeneratorInterface_InitializeBuffer, buffer);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto PersistentIdGeneratorInterface::FreeBuffer(PersistentIdBuffer& buffer) const -> void
{
	return PRIVATE_MAXON_MF_INVOKE((this), ((PersistentIdGeneratorInterface::MTable*) (this->_vtableCls + 1))[-1].PersistentIdGeneratorInterface_FreeBuffer, buffer);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto PersistentIdGeneratorInterface::Move(Int index, PersistentIdBuffer& buffer) const -> Result<void>
{
	return PRIVATE_MAXON_MF_INVOKE((this), ((PersistentIdGeneratorInterface::MTable*) (this->_vtableCls + 1))[-1].PersistentIdGeneratorInterface_Move, index, buffer);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto PersistentIdGeneratorInterface::Advance(Int index, PersistentIdBuffer& buffer) const -> Result<void>
{
	return PRIVATE_MAXON_MF_INVOKE((this), ((PersistentIdGeneratorInterface::MTable*) (this->_vtableCls + 1))[-1].PersistentIdGeneratorInterface_Advance, index, buffer);
}

PersistentIdGeneratorInterface::PersistentIdGeneratorInterface(const MTable& vtable) : _vtableCls(&vtable._info) { }
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto PersistentIdGeneratorInterface::Hxx1::ConstFn<S>::InitializeBuffer(PersistentIdBuffer& buffer) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const PersistentIdGeneratorInterface* o_ = (const PersistentIdGeneratorInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = PersistentIdGeneratorInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (PRIVATE_MAXON_MF_INVOKE((o_), ((PersistentIdGeneratorInterface::MTable*) (o_->_vtableCls + 1))[-1].PersistentIdGeneratorInterface_InitializeBuffer, buffer));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto PersistentIdGeneratorInterface::Hxx1::ConstFn<S>::FreeBuffer(PersistentIdBuffer& buffer) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const PersistentIdGeneratorInterface* o_ = (const PersistentIdGeneratorInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = PersistentIdGeneratorInterface::NullValuePtr(); if (!o_) return maxon::PrivateLogNullptrError(); } 
	PRIVATE_MAXON_MF_INVOKE((o_), ((PersistentIdGeneratorInterface::MTable*) (o_->_vtableCls + 1))[-1].PersistentIdGeneratorInterface_FreeBuffer, buffer);
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto PersistentIdGeneratorInterface::Hxx1::ConstFn<S>::Move(Int index, PersistentIdBuffer& buffer) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const PersistentIdGeneratorInterface* o_ = (const PersistentIdGeneratorInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = PersistentIdGeneratorInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (PRIVATE_MAXON_MF_INVOKE((o_), ((PersistentIdGeneratorInterface::MTable*) (o_->_vtableCls + 1))[-1].PersistentIdGeneratorInterface_Move, index, buffer));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto PersistentIdGeneratorInterface::Hxx1::ConstFn<S>::Advance(Int index, PersistentIdBuffer& buffer) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const PersistentIdGeneratorInterface* o_ = (const PersistentIdGeneratorInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = PersistentIdGeneratorInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (PRIVATE_MAXON_MF_INVOKE((o_), ((PersistentIdGeneratorInterface::MTable*) (o_->_vtableCls + 1))[-1].PersistentIdGeneratorInterface_Advance, index, buffer));
}

template <typename TYPE> struct StaticArrayInterface<TYPE>::MTable
{
	MTable() { }
	template <typename C> explicit MTable(C*) { Init<typename maxon::SFINAEHelper<Hxx2, C>::type::template Wrapper<C>>(); }
	template <typename C> MTable(C*, maxon::Bool) { Init<C>(); }
	PRIVATE_MAXON_MF_POINTER(StaticArrayInterface_operatorIndex, operatorIndex, false, StaticArrayInterface, const, (const TYPE&), Int index);
	PRIVATE_MAXON_MF_POINTER(StaticArrayInterface_GetWritable, GetWritable, false, StaticArrayInterface,, (ResultRef<TYPE>), Int index);
	PRIVATE_MAXON_MF_POINTER(StaticArrayInterface_GetBlock, GetBlock, false, StaticArrayInterface, const, (Int), Int index, SimdBlock<const TYPE>& block);
	PRIVATE_MAXON_MF_POINTER(StaticArrayInterface_GetBlock_1, GetBlock, false, StaticArrayInterface,, (Result<Int>), Int index, SimdBlock<NonConstValueType>& block);
	PRIVATE_MAXON_MF_POINTER(StaticArrayInterface_GetValueDataType, GetValueDataType, false, StaticArrayInterface, const, (const DataType&));
	PRIVATE_MAXON_MF_POINTER(StaticArrayInterface_GetPersistentIdGenerator, GetPersistentIdGenerator, false, StaticArrayInterface, const, (const PersistentIdGenerator&));
	PRIVATE_MAXON_MF_POINTER(StaticArrayInterface_MakeAllElementsWritable, MakeAllElementsWritable, false, StaticArrayInterface,, (Result<void>), Bool copyElements);
	PRIVATE_MAXON_MF_POINTER(StaticArrayInterface_MakeElementsWritable, MakeElementsWritable, false, StaticArrayInterface,, (Result<void>), Int start, Int end, Bool copyElements);
	void* _MAXON_METHOD_RESERVE14;
	void* _MAXON_METHOD_RESERVE15;
	void* _MAXON_METHOD_RESERVE16;
	void* _MAXON_METHOD_RESERVE17;
	typename GenericIndexableContainerInterface::MTable super;
	template <typename IMPL> void Init()
	{
		StaticArrayInterface_operatorIndex = StaticArrayInterface_operatorIndex_GetPtr<IMPL>(0, true).first;
		StaticArrayInterface_GetWritable = StaticArrayInterface_GetWritable_GetPtr<IMPL>(0, true).first;
		StaticArrayInterface_GetBlock = StaticArrayInterface_GetBlock_GetPtr<IMPL>(0, true).first;
		StaticArrayInterface_GetBlock_1 = StaticArrayInterface_GetBlock_1_GetPtr<IMPL>(0, true).first;
		StaticArrayInterface_GetValueDataType = StaticArrayInterface_GetValueDataType_GetPtr<IMPL>(0, true).first;
		StaticArrayInterface_GetPersistentIdGenerator = StaticArrayInterface_GetPersistentIdGenerator_GetPtr<IMPL>(0, true).first;
		StaticArrayInterface_MakeAllElementsWritable = StaticArrayInterface_MakeAllElementsWritable_GetPtr<IMPL>(0, true).first;
		StaticArrayInterface_MakeElementsWritable = StaticArrayInterface_MakeElementsWritable_GetPtr<IMPL>(0, true).first;
		_MAXON_METHOD_RESERVE14 = nullptr;
		_MAXON_METHOD_RESERVE15 = nullptr;
		_MAXON_METHOD_RESERVE16 = nullptr;
		_MAXON_METHOD_RESERVE17 = nullptr;
		super.template Init<IMPL>();
	}
	template <typename W> static maxon::Bool InitWithBases(maxon::ClassInfo* info, maxon::Int offset) { return true; }
	template <typename S> using CombinedMTable = S;
};

template <typename TYPE> struct StaticArrayInterface<TYPE>::Hxx2
{
	template <typename C> using CWrapper = C;
	template <typename C> class Wrapper : public GenericIndexableContainerInterface::Hxx2::template Wrapper<C>
	{
	public:
		PRIVATE_MAXON_MF_WRAPPER(StaticArrayInterface_operatorIndex, StaticArrayInterface, const, (const TYPE&), Int index) { return C::Get(PRIVATE_MAXON_MF_THIS(const StaticArrayInterface))->operator [](index); }
		PRIVATE_MAXON_MF_WRAPPER(StaticArrayInterface_GetWritable, StaticArrayInterface,, (ResultRef<TYPE>), Int index) { return C::Get(PRIVATE_MAXON_MF_THIS(StaticArrayInterface))->GetWritable(index); }
		PRIVATE_MAXON_MF_WRAPPER(StaticArrayInterface_GetBlock, StaticArrayInterface, const, (Int), Int index, SimdBlock<const TYPE>& block) { return C::Get(PRIVATE_MAXON_MF_THIS(const StaticArrayInterface))->GetBlock(index, block); }
		PRIVATE_MAXON_MF_WRAPPER(StaticArrayInterface_GetBlock_1, StaticArrayInterface,, (Result<Int>), Int index, SimdBlock<NonConstValueType>& block) { return C::Get(PRIVATE_MAXON_MF_THIS(StaticArrayInterface))->GetBlock(index, block); }
		PRIVATE_MAXON_MF_WRAPPER(StaticArrayInterface_GetValueDataType, StaticArrayInterface, const, (const DataType&)) { return C::Get(PRIVATE_MAXON_MF_THIS(const StaticArrayInterface))->GetValueDataType(); }
		PRIVATE_MAXON_MF_WRAPPER(StaticArrayInterface_GetPersistentIdGenerator, StaticArrayInterface, const, (const PersistentIdGenerator&)) { return C::Get(PRIVATE_MAXON_MF_THIS(const StaticArrayInterface))->GetPersistentIdGenerator(); }
		PRIVATE_MAXON_MF_WRAPPER(StaticArrayInterface_MakeAllElementsWritable, StaticArrayInterface,, (Result<void>), Bool copyElements) { return C::Get(PRIVATE_MAXON_MF_THIS(StaticArrayInterface))->MakeAllElementsWritable(copyElements); }
		PRIVATE_MAXON_MF_WRAPPER(StaticArrayInterface_MakeElementsWritable, StaticArrayInterface,, (Result<void>), Int start, Int end, Bool copyElements) { return C::Get(PRIVATE_MAXON_MF_THIS(StaticArrayInterface))->MakeElementsWritable(start, end, copyElements); }
	};

};
template <typename TYPE> MAXON_ATTRIBUTE_FORCE_INLINE auto StaticArrayInterface<TYPE>::operator [](Int index) const -> const TYPE&
{
	return PRIVATE_MAXON_MF_INVOKE((this), ((StaticArrayInterface::MTable*) (this->_vtableCls + 1))[-1].StaticArrayInterface_operatorIndex, index);
}
template <typename TYPE> MAXON_ATTRIBUTE_FORCE_INLINE auto StaticArrayInterface<TYPE>::GetWritable(Int index) -> ResultRef<TYPE>
{
	return PRIVATE_MAXON_MF_INVOKE((this), ((StaticArrayInterface::MTable*) (this->_vtableCls + 1))[-1].StaticArrayInterface_GetWritable, index);
}
template <typename TYPE> MAXON_ATTRIBUTE_FORCE_INLINE auto StaticArrayInterface<TYPE>::GetBlock(Int index, SimdBlock<const TYPE>& block) const -> Int
{
	return PRIVATE_MAXON_MF_INVOKE((this), ((StaticArrayInterface::MTable*) (this->_vtableCls + 1))[-1].StaticArrayInterface_GetBlock, index, block);
}
template <typename TYPE> MAXON_ATTRIBUTE_FORCE_INLINE auto StaticArrayInterface<TYPE>::GetBlock(Int index, SimdBlock<NonConstValueType>& block) -> Result<Int>
{
	return PRIVATE_MAXON_MF_INVOKE((this), ((StaticArrayInterface::MTable*) (this->_vtableCls + 1))[-1].StaticArrayInterface_GetBlock_1, index, block);
}
template <typename TYPE> MAXON_ATTRIBUTE_FORCE_INLINE auto StaticArrayInterface<TYPE>::GetValueDataType() const -> const DataType&
{
	return PRIVATE_MAXON_MF_INVOKE((this), ((StaticArrayInterface::MTable*) (this->_vtableCls + 1))[-1].StaticArrayInterface_GetValueDataType);
}
template <typename TYPE> MAXON_ATTRIBUTE_FORCE_INLINE auto StaticArrayInterface<TYPE>::GetPersistentIdGenerator() const -> const PersistentIdGenerator&
{
	return PRIVATE_MAXON_MF_INVOKE((this), ((StaticArrayInterface::MTable*) (this->_vtableCls + 1))[-1].StaticArrayInterface_GetPersistentIdGenerator);
}
template <typename TYPE> MAXON_ATTRIBUTE_FORCE_INLINE auto StaticArrayInterface<TYPE>::MakeAllElementsWritable(Bool copyElements) -> Result<void>
{
	return PRIVATE_MAXON_MF_INVOKE((this), ((StaticArrayInterface::MTable*) (this->_vtableCls + 1))[-1].StaticArrayInterface_MakeAllElementsWritable, copyElements);
}
template <typename TYPE> MAXON_ATTRIBUTE_FORCE_INLINE auto StaticArrayInterface<TYPE>::MakeElementsWritable(Int start, Int end, Bool copyElements) -> Result<void>
{
	return PRIVATE_MAXON_MF_INVOKE((this), ((StaticArrayInterface::MTable*) (this->_vtableCls + 1))[-1].StaticArrayInterface_MakeElementsWritable, start, end, copyElements);
}

template <typename TYPE> StaticArrayInterface<TYPE>::StaticArrayInterface(const MTable& vtable) : GenericIndexableContainerInterface(vtable.super) { }
template <typename TYPE> template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto StaticArrayInterface<TYPE>::Hxx1::ConstFn<S>::operator [](Int index) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<const TYPE&>, const TYPE&>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<const TYPE&>, const TYPE&>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const StaticArrayInterface* o_ = (const StaticArrayInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = StaticArrayInterface::NullValuePtr(); if (!o_) return maxon::PrivateNullReturnValue<const TYPE&>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } 
	return (PRIVATE_MAXON_MF_INVOKE((o_), ((StaticArrayInterface::MTable*) (o_->_vtableCls + 1))[-1].StaticArrayInterface_operatorIndex, index));
}
template <typename TYPE> template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto StaticArrayInterface<TYPE>::Hxx1::Fn<S>::GetWritable(Int index) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<TYPE&>, ResultRef<TYPE>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<TYPE&>, ResultRef<TYPE>>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); StaticArrayInterface* o_ = (StaticArrayInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return maxon::PrivateNullReturnValue<ResultRef<TYPE>>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } 
	return (PRIVATE_MAXON_MF_INVOKE((o_), ((StaticArrayInterface::MTable*) (o_->_vtableCls + 1))[-1].StaticArrayInterface_GetWritable, index));
}
template <typename TYPE> template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto StaticArrayInterface<TYPE>::Hxx1::COWFn<S>::GetWritable(Int index) -> typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), ResultRef<TYPE>, maxon::Result<TYPE&>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), ResultRef<TYPE>, maxon::Result<TYPE&>>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); StaticArrayInterface* o_ = (StaticArrayInterface*) this->MakeWritable(true).GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } 
	return (PRIVATE_MAXON_MF_INVOKE((o_), ((StaticArrayInterface::MTable*) (o_->_vtableCls + 1))[-1].StaticArrayInterface_GetWritable, index));
}
template <typename TYPE> template <typename S> template <typename A> MAXON_ATTRIBUTE_FORCE_INLINE auto StaticArrayInterface<TYPE>::Hxx1::Fn<S>::Set(Int index, A&& value) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<void>, ResultMem>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<void>, ResultMem>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); StaticArrayInterface* o_ = (StaticArrayInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return maxon::PrivateNullReturnValue<ResultMem>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } 
	return (o_->Set<A>(index, std::forward<A>(value)));
}
template <typename TYPE> template <typename S> template <typename A> MAXON_ATTRIBUTE_FORCE_INLINE auto StaticArrayInterface<TYPE>::Hxx1::COWFn<S>::Set(Int index, A&& value) -> typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), ResultMem, maxon::Result<void>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), ResultMem, maxon::Result<void>>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); StaticArrayInterface* o_ = (StaticArrayInterface*) this->MakeWritable(true).GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } 
	return (o_->Set<A>(index, std::forward<A>(value)));
}
template <typename TYPE> template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto StaticArrayInterface<TYPE>::Hxx1::ConstFn<S>::GetBlock(Int index, SimdBlock<const TYPE>& block) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const StaticArrayInterface* o_ = (const StaticArrayInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = StaticArrayInterface::NullValuePtr(); if (!o_) return 0; } 
	return (PRIVATE_MAXON_MF_INVOKE((o_), ((StaticArrayInterface::MTable*) (o_->_vtableCls + 1))[-1].StaticArrayInterface_GetBlock, index, block));
}
template <typename TYPE> template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto StaticArrayInterface<TYPE>::Hxx1::Fn<S>::GetBlock(Int index, SimdBlock<NonConstValueType>& block) const -> Result<Int>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<Int>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); StaticArrayInterface* o_ = (StaticArrayInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (PRIVATE_MAXON_MF_INVOKE((o_), ((StaticArrayInterface::MTable*) (o_->_vtableCls + 1))[-1].StaticArrayInterface_GetBlock_1, index, block));
}
template <typename TYPE> template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto StaticArrayInterface<TYPE>::Hxx1::COWFn<S>::GetWritableBlock(Int index, SimdBlock<NonConstValueType>& block) -> Result<Int>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<Int>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); StaticArrayInterface* o_ = (StaticArrayInterface*) this->MakeWritable(true).GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } 
	return (PRIVATE_MAXON_MF_INVOKE((o_), ((StaticArrayInterface::MTable*) (o_->_vtableCls + 1))[-1].StaticArrayInterface_GetBlock_1, index, block));
}
template <typename TYPE> template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto StaticArrayInterface<TYPE>::Hxx1::ConstFn<S>::GetValueDataType() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<const DataType&>, const DataType&>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<const DataType&>, const DataType&>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const StaticArrayInterface* o_ = (const StaticArrayInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = StaticArrayInterface::NullValuePtr(); if (!o_) return maxon::PrivateNullReturnValue<const DataType&>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } 
	return (PRIVATE_MAXON_MF_INVOKE((o_), ((StaticArrayInterface::MTable*) (o_->_vtableCls + 1))[-1].StaticArrayInterface_GetValueDataType));
}
template <typename TYPE> template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto StaticArrayInterface<TYPE>::Hxx1::ConstFn<S>::GetPersistentIdGenerator() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<const PersistentIdGenerator&>, const PersistentIdGenerator&>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<const PersistentIdGenerator&>, const PersistentIdGenerator&>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const StaticArrayInterface* o_ = (const StaticArrayInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = StaticArrayInterface::NullValuePtr(); if (!o_) return maxon::PrivateNullReturnValue<const PersistentIdGenerator&>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } 
	return (PRIVATE_MAXON_MF_INVOKE((o_), ((StaticArrayInterface::MTable*) (o_->_vtableCls + 1))[-1].StaticArrayInterface_GetPersistentIdGenerator));
}
template <typename TYPE> template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto StaticArrayInterface<TYPE>::Hxx1::Fn<S>::MakeAllElementsWritable(Bool copyElements) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); StaticArrayInterface* o_ = (StaticArrayInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (PRIVATE_MAXON_MF_INVOKE((o_), ((StaticArrayInterface::MTable*) (o_->_vtableCls + 1))[-1].StaticArrayInterface_MakeAllElementsWritable, copyElements));
}
template <typename TYPE> template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto StaticArrayInterface<TYPE>::Hxx1::COWFn<S>::MakeAllElementsWritable(Bool copyElements) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); StaticArrayInterface* o_ = (StaticArrayInterface*) this->MakeWritable(true).GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } 
	return (PRIVATE_MAXON_MF_INVOKE((o_), ((StaticArrayInterface::MTable*) (o_->_vtableCls + 1))[-1].StaticArrayInterface_MakeAllElementsWritable, copyElements));
}
template <typename TYPE> template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto StaticArrayInterface<TYPE>::Hxx1::Fn<S>::MakeElementsWritable(Int start, Int end, Bool copyElements) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); StaticArrayInterface* o_ = (StaticArrayInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (PRIVATE_MAXON_MF_INVOKE((o_), ((StaticArrayInterface::MTable*) (o_->_vtableCls + 1))[-1].StaticArrayInterface_MakeElementsWritable, start, end, copyElements));
}
template <typename TYPE> template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto StaticArrayInterface<TYPE>::Hxx1::COWFn<S>::MakeElementsWritable(Int start, Int end, Bool copyElements) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); StaticArrayInterface* o_ = (StaticArrayInterface*) this->MakeWritable(true).GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } 
	return (PRIVATE_MAXON_MF_INVOKE((o_), ((StaticArrayInterface::MTable*) (o_->_vtableCls + 1))[-1].StaticArrayInterface_MakeElementsWritable, start, end, copyElements));
}
template <typename TYPE> template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto StaticArrayInterface<TYPE>::Hxx1::ConstFn<S>::Begin() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<typename StaticArrayInterface<TYPE>::ConstIterator>, typename StaticArrayInterface<TYPE>::ConstIterator>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<typename StaticArrayInterface<TYPE>::ConstIterator>, typename StaticArrayInterface<TYPE>::ConstIterator>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const StaticArrayInterface* o_ = (const StaticArrayInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = StaticArrayInterface::NullValuePtr(); if (!o_) return maxon::PrivateNullReturnValue<typename StaticArrayInterface<TYPE>::ConstIterator>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } 
	return (o_->Begin());
}
template <typename TYPE> template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto StaticArrayInterface<TYPE>::Hxx1::ConstFn<S>::End() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<typename StaticArrayInterface<TYPE>::ConstIterator>, typename StaticArrayInterface<TYPE>::ConstIterator>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<typename StaticArrayInterface<TYPE>::ConstIterator>, typename StaticArrayInterface<TYPE>::ConstIterator>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const StaticArrayInterface* o_ = (const StaticArrayInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = StaticArrayInterface::NullValuePtr(); if (!o_) return maxon::PrivateNullReturnValue<typename StaticArrayInterface<TYPE>::ConstIterator>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } 
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
	PRIVATE_MAXON_MF_POINTER(ArrayInterface_GetBlock, GetBlock, false, ArrayInterface, const, (Int), Int index, Block<const TYPE>& block);
	PRIVATE_MAXON_MF_POINTER(ArrayInterface_PrivateInsert, PrivateInsert, false, ArrayInterface,, (Result<void>), Int index, const StridedBlock<const TYPE>& values, Bool move, COLLECTION_RESIZE_FLAGS resizeFlags);
	PRIVATE_MAXON_MF_POINTER(ArrayInterface_Resize, Resize, false, ArrayInterface,, (ResultMem), Int count, COLLECTION_RESIZE_FLAGS resizeFlags);
	PRIVATE_MAXON_MF_POINTER(ArrayInterface_SetCapacityHint, SetCapacityHint, false, ArrayInterface,, (ResultMem), Int requestedCapacity, COLLECTION_RESIZE_FLAGS resizeFlags);
	PRIVATE_MAXON_MF_POINTER(ArrayInterface_Insert, Insert, false, ArrayInterface,, (ResultRef<TYPE>), Int index);
	PRIVATE_MAXON_MF_POINTER(ArrayInterface_Insert_1, Insert, false, ArrayInterface,, (ResultMem), Int index, const Block<const TYPE>& values);
	PRIVATE_MAXON_MF_POINTER(ArrayInterface_Insert_2, Insert, false, ArrayInterface,, (ResultMem), Int index, const MoveBlock<TYPE>& values);
	PRIVATE_MAXON_MF_POINTER(ArrayInterface_Append, Append, false, ArrayInterface,, (ResultRef<TYPE>));
	PRIVATE_MAXON_MF_POINTER(ArrayInterface_Erase, Erase, false, ArrayInterface,, (ResultMem), Int index, Int count);
	PRIVATE_MAXON_MF_POINTER(ArrayInterface_SwapErase, SwapErase, false, ArrayInterface,, (ResultMem), Int index, Int count);
	PRIVATE_MAXON_MF_POINTER(ArrayInterface_Reset, Reset, false, ArrayInterface,, (void));
	PRIVATE_MAXON_MF_POINTER(ArrayInterface_Flush, Flush, false, ArrayInterface,, (void));
	PRIVATE_MAXON_MF_POINTER(ArrayInterface_CopyFrom, CopyFrom, false, ArrayInterface,, (Result<void>), const ArrayInterface& other);
	PRIVATE_MAXON_MF_POINTER(ArrayInterface_SetPersistentIdGenerator, SetPersistentIdGenerator, false, ArrayInterface,, (void), const PersistentIdGenerator& generator);
	PRIVATE_MAXON_MF_POINTER(ArrayInterface_GetMemorySize, GetMemorySize, false, ArrayInterface, const, (Int));
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
	typename ArrayBase0<ArrayInterface<TYPE>, TYPE, StaticArrayInterface<TYPE>, DefaultCompare>::MTable super;
	template <typename IMPL> void Init()
	{
		ArrayInterface_GetBlock = ArrayInterface_GetBlock_GetPtr<IMPL>(0, true).first;
		ArrayInterface_PrivateInsert = ArrayInterface_PrivateInsert_GetPtr<IMPL>(0, true).first;
		ArrayInterface_Resize = ArrayInterface_Resize_GetPtr<IMPL>(0, true).first;
		ArrayInterface_SetCapacityHint = ArrayInterface_SetCapacityHint_GetPtr<IMPL>(0, true).first;
		ArrayInterface_Insert = ArrayInterface_Insert_GetPtr<IMPL>(0, true).first;
		ArrayInterface_Insert_1 = ArrayInterface_Insert_1_GetPtr<IMPL>(0, true).first;
		ArrayInterface_Insert_2 = ArrayInterface_Insert_2_GetPtr<IMPL>(0, true).first;
		ArrayInterface_Append = ArrayInterface_Append_GetPtr<IMPL>(0, true).first;
		ArrayInterface_Erase = ArrayInterface_Erase_GetPtr<IMPL>(0, true).first;
		ArrayInterface_SwapErase = ArrayInterface_SwapErase_GetPtr<IMPL>(0, true).first;
		ArrayInterface_Reset = ArrayInterface_Reset_GetPtr<IMPL>(0, true).first;
		ArrayInterface_Flush = ArrayInterface_Flush_GetPtr<IMPL>(0, true).first;
		ArrayInterface_CopyFrom = ArrayInterface_CopyFrom_GetPtr<IMPL>(0, true).first;
		ArrayInterface_SetPersistentIdGenerator = ArrayInterface_SetPersistentIdGenerator_GetPtr<IMPL>(0, true).first;
		ArrayInterface_GetMemorySize = ArrayInterface_GetMemorySize_GetPtr<IMPL>(0, true).first;
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
		super.template Init<IMPL>();
	}
	template <typename W> static maxon::Bool InitWithBases(maxon::ClassInfo* info, maxon::Int offset) { return true; }
	template <typename S> using CombinedMTable = S;
};

template <typename TYPE> struct ArrayInterface<TYPE>::Hxx2
{
	template <typename C> using CWrapper = C;
	template <typename C> class Wrapper : public ArrayBase0<ArrayInterface<TYPE>, TYPE, StaticArrayInterface<TYPE>, DefaultCompare>::Hxx2::template Wrapper<C>
	{
	public:
		PRIVATE_MAXON_MF_WRAPPER(ArrayInterface_GetBlock, ArrayInterface, const, (Int), Int index, Block<const TYPE>& block) { return C::Get(PRIVATE_MAXON_MF_THIS(const ArrayInterface))->GetBlock(index, block); }
		PRIVATE_MAXON_MF_WRAPPER(ArrayInterface_PrivateInsert, ArrayInterface,, (Result<void>), Int index, const StridedBlock<const TYPE>& values, Bool move, COLLECTION_RESIZE_FLAGS resizeFlags) { return C::Get(PRIVATE_MAXON_MF_THIS(ArrayInterface))->PrivateInsert(index, values, move, resizeFlags); }
		PRIVATE_MAXON_MF_WRAPPER(ArrayInterface_Resize, ArrayInterface,, (ResultMem), Int count, COLLECTION_RESIZE_FLAGS resizeFlags) { return C::Get(PRIVATE_MAXON_MF_THIS(ArrayInterface))->Resize(count, resizeFlags); }
		PRIVATE_MAXON_MF_WRAPPER(ArrayInterface_SetCapacityHint, ArrayInterface,, (ResultMem), Int requestedCapacity, COLLECTION_RESIZE_FLAGS resizeFlags) { return C::Get(PRIVATE_MAXON_MF_THIS(ArrayInterface))->SetCapacityHint(requestedCapacity, resizeFlags); }
		PRIVATE_MAXON_MF_WRAPPER(ArrayInterface_Insert, ArrayInterface,, (ResultRef<TYPE>), Int index) { return C::Get(PRIVATE_MAXON_MF_THIS(ArrayInterface))->Insert(index); }
		PRIVATE_MAXON_MF_WRAPPER(ArrayInterface_Insert_1, ArrayInterface,, (ResultMem), Int index, const Block<const TYPE>& values) { return C::Get(PRIVATE_MAXON_MF_THIS(ArrayInterface))->Insert(index, values); }
		PRIVATE_MAXON_MF_WRAPPER(ArrayInterface_Insert_2, ArrayInterface,, (ResultMem), Int index, const MoveBlock<TYPE>& values) { return C::Get(PRIVATE_MAXON_MF_THIS(ArrayInterface))->Insert(index, values); }
		PRIVATE_MAXON_MF_WRAPPER(ArrayInterface_Append, ArrayInterface,, (ResultRef<TYPE>)) { return C::Get(PRIVATE_MAXON_MF_THIS(ArrayInterface))->Append(); }
		PRIVATE_MAXON_MF_WRAPPER(ArrayInterface_Erase, ArrayInterface,, (ResultMem), Int index, Int count) { return C::Get(PRIVATE_MAXON_MF_THIS(ArrayInterface))->Erase(index, count); }
		PRIVATE_MAXON_MF_WRAPPER(ArrayInterface_SwapErase, ArrayInterface,, (ResultMem), Int index, Int count) { return C::Get(PRIVATE_MAXON_MF_THIS(ArrayInterface))->SwapErase(index, count); }
		PRIVATE_MAXON_MF_WRAPPER(ArrayInterface_Reset, ArrayInterface,, (void)) { return C::Get(PRIVATE_MAXON_MF_THIS(ArrayInterface))->Reset(); }
		PRIVATE_MAXON_MF_WRAPPER(ArrayInterface_Flush, ArrayInterface,, (void)) { return C::Get(PRIVATE_MAXON_MF_THIS(ArrayInterface))->Flush(); }
		PRIVATE_MAXON_MF_WRAPPER(ArrayInterface_CopyFrom, ArrayInterface,, (Result<void>), const ArrayInterface& other) { return C::Get(PRIVATE_MAXON_MF_THIS(ArrayInterface))->CopyFrom(other); }
		PRIVATE_MAXON_MF_WRAPPER(ArrayInterface_SetPersistentIdGenerator, ArrayInterface,, (void), const PersistentIdGenerator& generator) { return C::Get(PRIVATE_MAXON_MF_THIS(ArrayInterface))->SetPersistentIdGenerator(generator); }
		PRIVATE_MAXON_MF_WRAPPER(ArrayInterface_GetMemorySize, ArrayInterface, const, (Int)) { return C::Get(PRIVATE_MAXON_MF_THIS(const ArrayInterface))->GetMemorySize(); }
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
template <typename TYPE> MAXON_ATTRIBUTE_FORCE_INLINE auto ArrayInterface<TYPE>::GetBlock(Int index, Block<const TYPE>& block) const -> Int
{
	return PRIVATE_MAXON_MF_INVOKE((this), ((ArrayInterface::MTable*) (this->_vtableCls + 1))[-1].ArrayInterface_GetBlock, index, block);
}
template <typename TYPE> MAXON_ATTRIBUTE_FORCE_INLINE auto ArrayInterface<TYPE>::PrivateInsert(Int index, const StridedBlock<const TYPE>& values, Bool move, COLLECTION_RESIZE_FLAGS resizeFlags) -> Result<void>
{
	return PRIVATE_MAXON_MF_INVOKE((this), ((ArrayInterface::MTable*) (this->_vtableCls + 1))[-1].ArrayInterface_PrivateInsert, index, values, move, resizeFlags);
}
template <typename TYPE> MAXON_ATTRIBUTE_FORCE_INLINE auto ArrayInterface<TYPE>::Resize(Int count, COLLECTION_RESIZE_FLAGS resizeFlags) -> ResultMem
{
	return PRIVATE_MAXON_MF_INVOKE((this), ((ArrayInterface::MTable*) (this->_vtableCls + 1))[-1].ArrayInterface_Resize, count, resizeFlags);
}
template <typename TYPE> MAXON_ATTRIBUTE_FORCE_INLINE auto ArrayInterface<TYPE>::SetCapacityHint(Int requestedCapacity, COLLECTION_RESIZE_FLAGS resizeFlags) -> ResultMem
{
	return PRIVATE_MAXON_MF_INVOKE((this), ((ArrayInterface::MTable*) (this->_vtableCls + 1))[-1].ArrayInterface_SetCapacityHint, requestedCapacity, resizeFlags);
}
template <typename TYPE> MAXON_ATTRIBUTE_FORCE_INLINE auto ArrayInterface<TYPE>::Insert(Int index) -> ResultRef<TYPE>
{
	return PRIVATE_MAXON_MF_INVOKE((this), ((ArrayInterface::MTable*) (this->_vtableCls + 1))[-1].ArrayInterface_Insert, index);
}
template <typename TYPE> MAXON_ATTRIBUTE_FORCE_INLINE auto ArrayInterface<TYPE>::Insert(Int index, const Block<const TYPE>& values) -> ResultMem
{
	return PRIVATE_MAXON_MF_INVOKE((this), ((ArrayInterface::MTable*) (this->_vtableCls + 1))[-1].ArrayInterface_Insert_1, index, values);
}
template <typename TYPE> MAXON_ATTRIBUTE_FORCE_INLINE auto ArrayInterface<TYPE>::Insert(Int index, const MoveBlock<TYPE>& values) -> ResultMem
{
	return PRIVATE_MAXON_MF_INVOKE((this), ((ArrayInterface::MTable*) (this->_vtableCls + 1))[-1].ArrayInterface_Insert_2, index, values);
}
template <typename TYPE> MAXON_ATTRIBUTE_FORCE_INLINE auto ArrayInterface<TYPE>::Append() -> ResultRef<TYPE>
{
	return PRIVATE_MAXON_MF_INVOKE((this), ((ArrayInterface::MTable*) (this->_vtableCls + 1))[-1].ArrayInterface_Append);
}
template <typename TYPE> MAXON_ATTRIBUTE_FORCE_INLINE auto ArrayInterface<TYPE>::Erase(Int index, Int count) -> ResultMem
{
	return PRIVATE_MAXON_MF_INVOKE((this), ((ArrayInterface::MTable*) (this->_vtableCls + 1))[-1].ArrayInterface_Erase, index, count);
}
template <typename TYPE> MAXON_ATTRIBUTE_FORCE_INLINE auto ArrayInterface<TYPE>::SwapErase(Int index, Int count) -> ResultMem
{
	return PRIVATE_MAXON_MF_INVOKE((this), ((ArrayInterface::MTable*) (this->_vtableCls + 1))[-1].ArrayInterface_SwapErase, index, count);
}
template <typename TYPE> MAXON_ATTRIBUTE_FORCE_INLINE auto ArrayInterface<TYPE>::Reset() -> void
{
	return PRIVATE_MAXON_MF_INVOKE((this), ((ArrayInterface::MTable*) (this->_vtableCls + 1))[-1].ArrayInterface_Reset);
}
template <typename TYPE> MAXON_ATTRIBUTE_FORCE_INLINE auto ArrayInterface<TYPE>::Flush() -> void
{
	return PRIVATE_MAXON_MF_INVOKE((this), ((ArrayInterface::MTable*) (this->_vtableCls + 1))[-1].ArrayInterface_Flush);
}
template <typename TYPE> MAXON_ATTRIBUTE_FORCE_INLINE auto ArrayInterface<TYPE>::CopyFrom(const ArrayInterface& other) -> Result<void>
{
	return PRIVATE_MAXON_MF_INVOKE((this), ((ArrayInterface::MTable*) (this->_vtableCls + 1))[-1].ArrayInterface_CopyFrom, other);
}
template <typename TYPE> MAXON_ATTRIBUTE_FORCE_INLINE auto ArrayInterface<TYPE>::SetPersistentIdGenerator(const PersistentIdGenerator& generator) -> void
{
	return PRIVATE_MAXON_MF_INVOKE((this), ((ArrayInterface::MTable*) (this->_vtableCls + 1))[-1].ArrayInterface_SetPersistentIdGenerator, generator);
}
template <typename TYPE> MAXON_ATTRIBUTE_FORCE_INLINE auto ArrayInterface<TYPE>::GetMemorySize() const -> Int
{
	return PRIVATE_MAXON_MF_INVOKE((this), ((ArrayInterface::MTable*) (this->_vtableCls + 1))[-1].ArrayInterface_GetMemorySize);
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

template <typename TYPE> ArrayInterface<TYPE>::ArrayInterface(const MTable& vtable) : ArrayBase0<ArrayInterface<TYPE>, TYPE, StaticArrayInterface<TYPE>, DefaultCompare>(vtable.super) { }
template <typename TYPE> template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ArrayInterface<TYPE>::Hxx1::ConstFn<S>::GetBlock(Int index, Block<const TYPE>& block) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const ArrayInterface* o_ = (const ArrayInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = ArrayInterface::NullValuePtr(); if (!o_) return 0; } 
	return (PRIVATE_MAXON_MF_INVOKE((o_), ((ArrayInterface::MTable*) (o_->_vtableCls + 1))[-1].ArrayInterface_GetBlock, index, block));
}
template <typename TYPE> template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ArrayInterface<TYPE>::Hxx1::Fn<S>::Resize(Int count, COLLECTION_RESIZE_FLAGS resizeFlags) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<void>, ResultMem>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<void>, ResultMem>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); ArrayInterface* o_ = (ArrayInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return maxon::PrivateNullReturnValue<ResultMem>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } 
	return (PRIVATE_MAXON_MF_INVOKE((o_), ((ArrayInterface::MTable*) (o_->_vtableCls + 1))[-1].ArrayInterface_Resize, count, resizeFlags));
}
template <typename TYPE> template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ArrayInterface<TYPE>::Hxx1::COWFn<S>::Resize(Int count, COLLECTION_RESIZE_FLAGS resizeFlags) -> typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), ResultMem, maxon::Result<void>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), ResultMem, maxon::Result<void>>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); ArrayInterface* o_ = (ArrayInterface*) this->MakeWritable(true).GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } 
	return (PRIVATE_MAXON_MF_INVOKE((o_), ((ArrayInterface::MTable*) (o_->_vtableCls + 1))[-1].ArrayInterface_Resize, count, resizeFlags));
}
template <typename TYPE> template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ArrayInterface<TYPE>::Hxx1::Fn<S>::SetCapacityHint(Int requestedCapacity, COLLECTION_RESIZE_FLAGS resizeFlags) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<void>, ResultMem>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<void>, ResultMem>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); ArrayInterface* o_ = (ArrayInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return maxon::PrivateNullReturnValue<ResultMem>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } 
	return (PRIVATE_MAXON_MF_INVOKE((o_), ((ArrayInterface::MTable*) (o_->_vtableCls + 1))[-1].ArrayInterface_SetCapacityHint, requestedCapacity, resizeFlags));
}
template <typename TYPE> template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ArrayInterface<TYPE>::Hxx1::COWFn<S>::SetCapacityHint(Int requestedCapacity, COLLECTION_RESIZE_FLAGS resizeFlags) -> typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), ResultMem, maxon::Result<void>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), ResultMem, maxon::Result<void>>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); ArrayInterface* o_ = (ArrayInterface*) this->MakeWritable(true).GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } 
	return (PRIVATE_MAXON_MF_INVOKE((o_), ((ArrayInterface::MTable*) (o_->_vtableCls + 1))[-1].ArrayInterface_SetCapacityHint, requestedCapacity, resizeFlags));
}
template <typename TYPE> template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ArrayInterface<TYPE>::Hxx1::Fn<S>::Insert(Int index) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<TYPE&>, ResultRef<TYPE>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<TYPE&>, ResultRef<TYPE>>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); ArrayInterface* o_ = (ArrayInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return maxon::PrivateNullReturnValue<ResultRef<TYPE>>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } 
	return (PRIVATE_MAXON_MF_INVOKE((o_), ((ArrayInterface::MTable*) (o_->_vtableCls + 1))[-1].ArrayInterface_Insert, index));
}
template <typename TYPE> template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ArrayInterface<TYPE>::Hxx1::COWFn<S>::Insert(Int index) -> typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), ResultRef<TYPE>, maxon::Result<TYPE&>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), ResultRef<TYPE>, maxon::Result<TYPE&>>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); ArrayInterface* o_ = (ArrayInterface*) this->MakeWritable(true).GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } 
	return (PRIVATE_MAXON_MF_INVOKE((o_), ((ArrayInterface::MTable*) (o_->_vtableCls + 1))[-1].ArrayInterface_Insert, index));
}
template <typename TYPE> template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ArrayInterface<TYPE>::Hxx1::Fn<S>::Insert(Int index, const TYPE& value) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<TYPE&>, ResultRef<TYPE>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<TYPE&>, ResultRef<TYPE>>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); ArrayInterface* o_ = (ArrayInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return maxon::PrivateNullReturnValue<ResultRef<TYPE>>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } 
	return (o_->Insert(index, value));
}
template <typename TYPE> template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ArrayInterface<TYPE>::Hxx1::COWFn<S>::Insert(Int index, const TYPE& value) -> typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), ResultRef<TYPE>, maxon::Result<TYPE&>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), ResultRef<TYPE>, maxon::Result<TYPE&>>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); ArrayInterface* o_ = (ArrayInterface*) this->MakeWritable(true).GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } 
	return (o_->Insert(index, value));
}
template <typename TYPE> template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ArrayInterface<TYPE>::Hxx1::Fn<S>::Insert(Int index, TYPE&& value) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<TYPE&>, ResultRef<TYPE>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<TYPE&>, ResultRef<TYPE>>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); ArrayInterface* o_ = (ArrayInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return maxon::PrivateNullReturnValue<ResultRef<TYPE>>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } 
	return (o_->Insert(index, std::forward<TYPE>(value)));
}
template <typename TYPE> template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ArrayInterface<TYPE>::Hxx1::COWFn<S>::Insert(Int index, TYPE&& value) -> typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), ResultRef<TYPE>, maxon::Result<TYPE&>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), ResultRef<TYPE>, maxon::Result<TYPE&>>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); ArrayInterface* o_ = (ArrayInterface*) this->MakeWritable(true).GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } 
	return (o_->Insert(index, std::forward<TYPE>(value)));
}
template <typename TYPE> template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ArrayInterface<TYPE>::Hxx1::Fn<S>::Insert(Int index, const Block<const TYPE>& values) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<void>, ResultMem>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<void>, ResultMem>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); ArrayInterface* o_ = (ArrayInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return maxon::PrivateNullReturnValue<ResultMem>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } 
	return (PRIVATE_MAXON_MF_INVOKE((o_), ((ArrayInterface::MTable*) (o_->_vtableCls + 1))[-1].ArrayInterface_Insert_1, index, values));
}
template <typename TYPE> template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ArrayInterface<TYPE>::Hxx1::COWFn<S>::Insert(Int index, const Block<const TYPE>& values) -> typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), ResultMem, maxon::Result<void>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), ResultMem, maxon::Result<void>>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); ArrayInterface* o_ = (ArrayInterface*) this->MakeWritable(true).GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } 
	return (PRIVATE_MAXON_MF_INVOKE((o_), ((ArrayInterface::MTable*) (o_->_vtableCls + 1))[-1].ArrayInterface_Insert_1, index, values));
}
template <typename TYPE> template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ArrayInterface<TYPE>::Hxx1::Fn<S>::Insert(Int index, const MoveBlock<TYPE>& values) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<void>, ResultMem>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<void>, ResultMem>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); ArrayInterface* o_ = (ArrayInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return maxon::PrivateNullReturnValue<ResultMem>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } 
	return (PRIVATE_MAXON_MF_INVOKE((o_), ((ArrayInterface::MTable*) (o_->_vtableCls + 1))[-1].ArrayInterface_Insert_2, index, values));
}
template <typename TYPE> template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ArrayInterface<TYPE>::Hxx1::COWFn<S>::Insert(Int index, const MoveBlock<TYPE>& values) -> typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), ResultMem, maxon::Result<void>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), ResultMem, maxon::Result<void>>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); ArrayInterface* o_ = (ArrayInterface*) this->MakeWritable(true).GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } 
	return (PRIVATE_MAXON_MF_INVOKE((o_), ((ArrayInterface::MTable*) (o_->_vtableCls + 1))[-1].ArrayInterface_Insert_2, index, values));
}
template <typename TYPE> template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ArrayInterface<TYPE>::Hxx1::Fn<S>::InsertBlock(Int index, const Block<const TYPE>& values) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<void>, ResultMem>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<void>, ResultMem>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); ArrayInterface* o_ = (ArrayInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return maxon::PrivateNullReturnValue<ResultMem>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } 
	return (o_->InsertBlock(index, values));
}
template <typename TYPE> template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ArrayInterface<TYPE>::Hxx1::COWFn<S>::InsertBlock(Int index, const Block<const TYPE>& values) -> typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), ResultMem, maxon::Result<void>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), ResultMem, maxon::Result<void>>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); ArrayInterface* o_ = (ArrayInterface*) this->MakeWritable(true).GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } 
	return (o_->InsertBlock(index, values));
}
template <typename TYPE> template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ArrayInterface<TYPE>::Hxx1::Fn<S>::InsertBlock(Int index, const MoveBlock<TYPE>& values) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<void>, ResultMem>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<void>, ResultMem>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); ArrayInterface* o_ = (ArrayInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return maxon::PrivateNullReturnValue<ResultMem>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } 
	return (o_->InsertBlock(index, values));
}
template <typename TYPE> template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ArrayInterface<TYPE>::Hxx1::COWFn<S>::InsertBlock(Int index, const MoveBlock<TYPE>& values) -> typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), ResultMem, maxon::Result<void>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), ResultMem, maxon::Result<void>>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); ArrayInterface* o_ = (ArrayInterface*) this->MakeWritable(true).GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } 
	return (o_->InsertBlock(index, values));
}
template <typename TYPE> template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ArrayInterface<TYPE>::Hxx1::Fn<S>::Append() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<TYPE&>, ResultRef<TYPE>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<TYPE&>, ResultRef<TYPE>>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); ArrayInterface* o_ = (ArrayInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return maxon::PrivateNullReturnValue<ResultRef<TYPE>>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } 
	return (PRIVATE_MAXON_MF_INVOKE((o_), ((ArrayInterface::MTable*) (o_->_vtableCls + 1))[-1].ArrayInterface_Append));
}
template <typename TYPE> template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ArrayInterface<TYPE>::Hxx1::COWFn<S>::Append() -> typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), ResultRef<TYPE>, maxon::Result<TYPE&>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), ResultRef<TYPE>, maxon::Result<TYPE&>>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); ArrayInterface* o_ = (ArrayInterface*) this->MakeWritable(true).GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } 
	return (PRIVATE_MAXON_MF_INVOKE((o_), ((ArrayInterface::MTable*) (o_->_vtableCls + 1))[-1].ArrayInterface_Append));
}
template <typename TYPE> template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ArrayInterface<TYPE>::Hxx1::Fn<S>::Append(const TYPE& value) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<TYPE&>, ResultRef<TYPE>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<TYPE&>, ResultRef<TYPE>>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); ArrayInterface* o_ = (ArrayInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return maxon::PrivateNullReturnValue<ResultRef<TYPE>>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } 
	return (o_->Append(value));
}
template <typename TYPE> template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ArrayInterface<TYPE>::Hxx1::COWFn<S>::Append(const TYPE& value) -> typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), ResultRef<TYPE>, maxon::Result<TYPE&>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), ResultRef<TYPE>, maxon::Result<TYPE&>>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); ArrayInterface* o_ = (ArrayInterface*) this->MakeWritable(true).GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } 
	return (o_->Append(value));
}
template <typename TYPE> template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ArrayInterface<TYPE>::Hxx1::Fn<S>::Append(TYPE&& value) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<TYPE&>, ResultRef<TYPE>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<TYPE&>, ResultRef<TYPE>>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); ArrayInterface* o_ = (ArrayInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return maxon::PrivateNullReturnValue<ResultRef<TYPE>>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } 
	return (o_->Append(std::forward<TYPE>(value)));
}
template <typename TYPE> template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ArrayInterface<TYPE>::Hxx1::COWFn<S>::Append(TYPE&& value) -> typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), ResultRef<TYPE>, maxon::Result<TYPE&>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), ResultRef<TYPE>, maxon::Result<TYPE&>>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); ArrayInterface* o_ = (ArrayInterface*) this->MakeWritable(true).GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } 
	return (o_->Append(std::forward<TYPE>(value)));
}
template <typename TYPE> template <typename S> template <typename A> MAXON_ATTRIBUTE_FORCE_INLINE auto ArrayInterface<TYPE>::Hxx1::Fn<S>::Append(A&& value) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<TYPE&>, ResultRef<TYPE>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<TYPE&>, ResultRef<TYPE>>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); ArrayInterface* o_ = (ArrayInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return maxon::PrivateNullReturnValue<ResultRef<TYPE>>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } 
	return (o_->Append<A>(std::forward<A>(value)));
}
template <typename TYPE> template <typename S> template <typename A> MAXON_ATTRIBUTE_FORCE_INLINE auto ArrayInterface<TYPE>::Hxx1::COWFn<S>::Append(A&& value) -> typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), ResultRef<TYPE>, maxon::Result<TYPE&>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), ResultRef<TYPE>, maxon::Result<TYPE&>>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); ArrayInterface* o_ = (ArrayInterface*) this->MakeWritable(true).GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } 
	return (o_->Append<A>(std::forward<A>(value)));
}
template <typename TYPE> template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ArrayInterface<TYPE>::Hxx1::Fn<S>::Pop() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); ArrayInterface* o_ = (ArrayInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return maxon::PrivateLogNullptrError(false); } 
	return (o_->Pop());
}
template <typename TYPE> template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ArrayInterface<TYPE>::Hxx1::COWFn<S>::Pop() -> typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), Bool, maxon::Result<Bool>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), Bool, maxon::Result<Bool>>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); ArrayInterface* o_ = (ArrayInterface*) this->MakeWritable(true).GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } 
	return (o_->Pop());
}
template <typename TYPE> template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ArrayInterface<TYPE>::Hxx1::Fn<S>::Pop(TYPE* dst) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); ArrayInterface* o_ = (ArrayInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return maxon::PrivateLogNullptrError(false); } 
	return (o_->Pop(dst));
}
template <typename TYPE> template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ArrayInterface<TYPE>::Hxx1::COWFn<S>::Pop(TYPE* dst) -> typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), Bool, maxon::Result<Bool>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), Bool, maxon::Result<Bool>>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); ArrayInterface* o_ = (ArrayInterface*) this->MakeWritable(true).GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } 
	return (o_->Pop(dst));
}
template <typename TYPE> template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ArrayInterface<TYPE>::Hxx1::Fn<S>::Erase(Int index, Int count) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<void>, ResultMem>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<void>, ResultMem>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); ArrayInterface* o_ = (ArrayInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return maxon::PrivateNullReturnValue<ResultMem>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } 
	return (PRIVATE_MAXON_MF_INVOKE((o_), ((ArrayInterface::MTable*) (o_->_vtableCls + 1))[-1].ArrayInterface_Erase, index, count));
}
template <typename TYPE> template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ArrayInterface<TYPE>::Hxx1::COWFn<S>::Erase(Int index, Int count) -> typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), ResultMem, maxon::Result<void>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), ResultMem, maxon::Result<void>>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); ArrayInterface* o_ = (ArrayInterface*) this->MakeWritable(true).GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } 
	return (PRIVATE_MAXON_MF_INVOKE((o_), ((ArrayInterface::MTable*) (o_->_vtableCls + 1))[-1].ArrayInterface_Erase, index, count));
}
template <typename TYPE> template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ArrayInterface<TYPE>::Hxx1::Fn<S>::SwapErase(Int index, Int count) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<void>, ResultMem>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<void>, ResultMem>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); ArrayInterface* o_ = (ArrayInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return maxon::PrivateNullReturnValue<ResultMem>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } 
	return (PRIVATE_MAXON_MF_INVOKE((o_), ((ArrayInterface::MTable*) (o_->_vtableCls + 1))[-1].ArrayInterface_SwapErase, index, count));
}
template <typename TYPE> template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ArrayInterface<TYPE>::Hxx1::COWFn<S>::SwapErase(Int index, Int count) -> typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), ResultMem, maxon::Result<void>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), ResultMem, maxon::Result<void>>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); ArrayInterface* o_ = (ArrayInterface*) this->MakeWritable(true).GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } 
	return (PRIVATE_MAXON_MF_INVOKE((o_), ((ArrayInterface::MTable*) (o_->_vtableCls + 1))[-1].ArrayInterface_SwapErase, index, count));
}
template <typename TYPE> template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ArrayInterface<TYPE>::Hxx1::Fn<S>::Reset() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); ArrayInterface* o_ = (ArrayInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { DebugStop(); return maxon::PrivateLogNullptrError(); } 
	PRIVATE_MAXON_MF_INVOKE((o_), ((ArrayInterface::MTable*) (o_->_vtableCls + 1))[-1].ArrayInterface_Reset);
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
template <typename TYPE> template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ArrayInterface<TYPE>::Hxx1::COWFn<S>::Reset() -> typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), void, maxon::Result<void>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), void, maxon::Result<void>>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); ArrayInterface* o_ = (ArrayInterface*) this->MakeWritable(true).GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } 
	PRIVATE_MAXON_MF_INVOKE((o_), ((ArrayInterface::MTable*) (o_->_vtableCls + 1))[-1].ArrayInterface_Reset);
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
template <typename TYPE> template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ArrayInterface<TYPE>::Hxx1::Fn<S>::Flush() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); ArrayInterface* o_ = (ArrayInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { DebugStop(); return maxon::PrivateLogNullptrError(); } 
	PRIVATE_MAXON_MF_INVOKE((o_), ((ArrayInterface::MTable*) (o_->_vtableCls + 1))[-1].ArrayInterface_Flush);
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
template <typename TYPE> template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ArrayInterface<TYPE>::Hxx1::COWFn<S>::Flush() -> typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), void, maxon::Result<void>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), void, maxon::Result<void>>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); ArrayInterface* o_ = (ArrayInterface*) this->MakeWritable(true).GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } 
	PRIVATE_MAXON_MF_INVOKE((o_), ((ArrayInterface::MTable*) (o_->_vtableCls + 1))[-1].ArrayInterface_Flush);
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
template <typename TYPE> template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ArrayInterface<TYPE>::Hxx1::Fn<S>::CopyFrom(const ArrayInterface& other) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); ArrayInterface* o_ = (ArrayInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (PRIVATE_MAXON_MF_INVOKE((o_), ((ArrayInterface::MTable*) (o_->_vtableCls + 1))[-1].ArrayInterface_CopyFrom, other));
}
template <typename TYPE> template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ArrayInterface<TYPE>::Hxx1::COWFn<S>::CopyFrom(const ArrayInterface& other) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); ArrayInterface* o_ = (ArrayInterface*) this->MakeWritable(true).GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } 
	return (PRIVATE_MAXON_MF_INVOKE((o_), ((ArrayInterface::MTable*) (o_->_vtableCls + 1))[-1].ArrayInterface_CopyFrom, other));
}
template <typename TYPE> template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ArrayInterface<TYPE>::Hxx1::Fn<S>::SetPersistentIdGenerator(const PersistentIdGenerator& generator) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); ArrayInterface* o_ = (ArrayInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { DebugStop(); return maxon::PrivateLogNullptrError(); } 
	PRIVATE_MAXON_MF_INVOKE((o_), ((ArrayInterface::MTable*) (o_->_vtableCls + 1))[-1].ArrayInterface_SetPersistentIdGenerator, generator);
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
template <typename TYPE> template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ArrayInterface<TYPE>::Hxx1::COWFn<S>::SetPersistentIdGenerator(const PersistentIdGenerator& generator) -> typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), void, maxon::Result<void>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), void, maxon::Result<void>>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); ArrayInterface* o_ = (ArrayInterface*) this->MakeWritable(true).GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } 
	PRIVATE_MAXON_MF_INVOKE((o_), ((ArrayInterface::MTable*) (o_->_vtableCls + 1))[-1].ArrayInterface_SetPersistentIdGenerator, generator);
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
template <typename TYPE> template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ArrayInterface<TYPE>::Hxx1::ConstFn<S>::GetMemorySize() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const ArrayInterface* o_ = (const ArrayInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = ArrayInterface::NullValuePtr(); if (!o_) return 0; } 
	return (PRIVATE_MAXON_MF_INVOKE((o_), ((ArrayInterface::MTable*) (o_->_vtableCls + 1))[-1].ArrayInterface_GetMemorySize));
}
template <typename TYPE> template <typename S> template <typename DT> MAXON_ATTRIBUTE_FORCE_INLINE auto ArrayInterface<TYPE>::Hxx1::ConstFn<S>::HasType() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const ArrayInterface* o_ = (const ArrayInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = ArrayInterface::NullValuePtr(); if (!o_) return maxon::PrivateLogNullptrError(false); } 
	return (o_->HasType<DT>());
}
template <typename TYPE> template <typename S> template <typename DT> MAXON_ATTRIBUTE_FORCE_INLINE auto ArrayInterface<TYPE>::Hxx1::ConstFn<S>::AssertType() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const ArrayInterface* o_ = (const ArrayInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = ArrayInterface::NullValuePtr(); if (!o_) return maxon::PrivateLogNullptrError(); } 
	o_->AssertType<DT>();
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
#ifdef MAXON_COMPILER_INTEL
#endif
#ifdef MAXON_COMPILER_INTEL
#endif
template <typename TYPE> template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ArrayInterface<TYPE>::Hxx1::ConstFn<S>::Begin() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<typename ArrayInterface<TYPE>::ConstIterator>, typename ArrayInterface<TYPE>::ConstIterator>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<typename ArrayInterface<TYPE>::ConstIterator>, typename ArrayInterface<TYPE>::ConstIterator>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const ArrayInterface* o_ = (const ArrayInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = ArrayInterface::NullValuePtr(); if (!o_) return maxon::PrivateNullReturnValue<typename ArrayInterface<TYPE>::ConstIterator>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } 
	return (o_->Begin());
}
template <typename TYPE> template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ArrayInterface<TYPE>::Hxx1::ConstFn<S>::End() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<typename ArrayInterface<TYPE>::ConstIterator>, typename ArrayInterface<TYPE>::ConstIterator>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<typename ArrayInterface<TYPE>::ConstIterator>, typename ArrayInterface<TYPE>::ConstIterator>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const ArrayInterface* o_ = (const ArrayInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = ArrayInterface::NullValuePtr(); if (!o_) return maxon::PrivateNullReturnValue<typename ArrayInterface<TYPE>::ConstIterator>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } 
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
constexpr const maxon::Char* ArrayFactory::PrivateGetCppName() { return nullptr; }

struct ArrayFactory::MTable
{
	static MTable _instance;
	static MTable _unresolvedInstance;
	static const maxon::Char* const _ids;
	static maxon::Bool InitUnresolved(maxon::NonvirtualInterfaceReference::UnresolvedAssembler assembler, MTable* tbl);
	static const maxon::NULL_RETURN_TYPE _returnTypes[];
	static const maxon::Bool HAS_NONSTATIC = false;
	PRIVATE_MAXON_SF_POINTER(ArrayFactory_NewBaseArray, NewBaseArray, MAXON_EXPAND_VA_ARGS, (Result<Array<Generic>::NonConst>), const DataType& elementType, const Generic* src, Bool move);
	PRIVATE_MAXON_SF_POINTER(ArrayFactory_NewBaseArrayFromContainerType, NewBaseArrayFromContainerType, MAXON_EXPAND_VA_ARGS, (Result<Array<Generic>::NonConst>), const ContainerDataType<>& containerType, const Generic* src, Bool move);
	PRIVATE_MAXON_SF_POINTER(ArrayFactory_NewBlockArray, NewBlockArray, MAXON_EXPAND_VA_ARGS, (Result<Array<Generic>::NonConst>), const DataType& elementType, const Generic* src, Bool move);
	PRIVATE_MAXON_SF_POINTER(ArrayFactory_NewPagedArray, NewPagedArray, MAXON_EXPAND_VA_ARGS, (Result<Array<Generic>::NonConst>), const DataType& elementType, const Generic* defaultValue, Bool useRefCountForDefault);
	PRIVATE_MAXON_SF_POINTER(ArrayFactory_NewPagedArrayFromContainerType, NewPagedArrayFromContainerType, MAXON_EXPAND_VA_ARGS, (Result<Array<Generic>::NonConst>), const ContainerDataType<>& containerType, const Generic* defaultValue, Bool useRefCountForDefault);
	PRIVATE_MAXON_SF_POINTER(ArrayFactory_Slice, Slice, MAXON_EXPAND_VA_ARGS, (Result<Array<Generic>>), const Array<Generic>& base, Int start, Int end, Bool cycle, const Generic* defaultValue, Bool useRefCountForDefault);
	PRIVATE_MAXON_SF_POINTER(ArrayFactory_NewSingleValueArray, NewSingleValueArray, MAXON_EXPAND_VA_ARGS, (Result<Array<Generic>>), const ConstDataPtr& value, Int count, const ContainerDataType<>& containerType);
	PRIVATE_MAXON_SF_POINTER(ArrayFactory_ExtractMember, ExtractMember, MAXON_EXPAND_VA_ARGS, (Result<Array<Generic>>), const Array<Generic>& base, Int offset, const ContainerDataType<>& containerType);
	PRIVATE_MAXON_SF_POINTER(ArrayFactory_Reinterpret, Reinterpret, MAXON_EXPAND_VA_ARGS, (Result<Array<Generic>>), const Array<Generic>& base, const ContainerDataType<>& containerType);
	PRIVATE_MAXON_SF_POINTER(ArrayFactory_PrivateNewPagedArrayFromBase, PrivateNewPagedArrayFromBase, MAXON_EXPAND_VA_ARGS, (Result<Array<Generic>::NonConst>), const Array<Generic>& base, const Generic* defaultValue, Bool useRefCountForDefault);
	PRIVATE_MAXON_SF_POINTER(ArrayFactory_ConvertToSingleBlock, ConvertToSingleBlock, MAXON_EXPAND_VA_ARGS, (Result<Array<Generic>>), const Array<Generic>& source);
	template <typename IMPL> void Init()
	{
		ArrayFactory_NewBaseArray = ArrayFactory_NewBaseArray_GetPtr<IMPL>(true);
		ArrayFactory_NewBaseArrayFromContainerType = ArrayFactory_NewBaseArrayFromContainerType_GetPtr<IMPL>(true);
		ArrayFactory_NewBlockArray = ArrayFactory_NewBlockArray_GetPtr<IMPL>(true);
		ArrayFactory_NewPagedArray = ArrayFactory_NewPagedArray_GetPtr<IMPL>(true);
		ArrayFactory_NewPagedArrayFromContainerType = ArrayFactory_NewPagedArrayFromContainerType_GetPtr<IMPL>(true);
		ArrayFactory_Slice = ArrayFactory_Slice_GetPtr<IMPL>(true);
		ArrayFactory_NewSingleValueArray = ArrayFactory_NewSingleValueArray_GetPtr<IMPL>(true);
		ArrayFactory_ExtractMember = ArrayFactory_ExtractMember_GetPtr<IMPL>(true);
		ArrayFactory_Reinterpret = ArrayFactory_Reinterpret_GetPtr<IMPL>(true);
		ArrayFactory_PrivateNewPagedArrayFromBase = ArrayFactory_PrivateNewPagedArrayFromBase_GetPtr<IMPL>(true);
		ArrayFactory_ConvertToSingleBlock = ArrayFactory_ConvertToSingleBlock_GetPtr<IMPL>(true);
	}
};

struct ArrayFactory::Hxx2
{
	class Unresolved;
	template <typename C> class Wrapper
	{
	public:
		using Implementation = C;
		static Result<Array<Generic>::NonConst> ArrayFactory_NewBaseArray(const DataType& elementType, const Generic* src, Bool move) { return C::NewBaseArray(elementType, src, move); }
		static Result<Array<Generic>::NonConst> ArrayFactory_NewBaseArrayFromContainerType(const ContainerDataType<>& containerType, const Generic* src, Bool move) { return C::NewBaseArrayFromContainerType(containerType, src, move); }
		static Result<Array<Generic>::NonConst> ArrayFactory_NewBlockArray(const DataType& elementType, const Generic* src, Bool move) { return C::NewBlockArray(elementType, src, move); }
		static Result<Array<Generic>::NonConst> ArrayFactory_NewPagedArray(const DataType& elementType, const Generic* defaultValue, Bool useRefCountForDefault) { return C::NewPagedArray(elementType, defaultValue, useRefCountForDefault); }
		static Result<Array<Generic>::NonConst> ArrayFactory_NewPagedArrayFromContainerType(const ContainerDataType<>& containerType, const Generic* defaultValue, Bool useRefCountForDefault) { return C::NewPagedArrayFromContainerType(containerType, defaultValue, useRefCountForDefault); }
		static Result<Array<Generic>> ArrayFactory_Slice(const Array<Generic>& base, Int start, Int end, Bool cycle, const Generic* defaultValue, Bool useRefCountForDefault) { return C::Slice(base, start, end, cycle, defaultValue, useRefCountForDefault); }
		static Result<Array<Generic>> ArrayFactory_NewSingleValueArray(const ConstDataPtr& value, Int count, const ContainerDataType<>& containerType) { return C::NewSingleValueArray(value, count, containerType); }
		static Result<Array<Generic>> ArrayFactory_ExtractMember(const Array<Generic>& base, Int offset, const ContainerDataType<>& containerType) { return C::ExtractMember(base, offset, containerType); }
		static Result<Array<Generic>> ArrayFactory_Reinterpret(const Array<Generic>& base, const ContainerDataType<>& containerType) { return C::Reinterpret(base, containerType); }
		static Result<Array<Generic>::NonConst> ArrayFactory_PrivateNewPagedArrayFromBase(const Array<Generic>& base, const Generic* defaultValue, Bool useRefCountForDefault) { return C::PrivateNewPagedArrayFromBase(base, defaultValue, useRefCountForDefault); }
		static Result<Array<Generic>> ArrayFactory_ConvertToSingleBlock(const Array<Generic>& source) { return C::ConvertToSingleBlock(source); }
	};

};
MAXON_ATTRIBUTE_FORCE_INLINE auto ArrayFactory::NewBaseArray(const DataType& elementType, const Generic* src, Bool move) -> Result<Array<Generic>::NonConst>
{
	return MTable::_instance.ArrayFactory_NewBaseArray(elementType, src, move);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ArrayFactory::NewBaseArrayFromContainerType(const ContainerDataType<>& containerType, const Generic* src, Bool move) -> Result<Array<Generic>::NonConst>
{
	return MTable::_instance.ArrayFactory_NewBaseArrayFromContainerType(containerType, src, move);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ArrayFactory::NewBlockArray(const DataType& elementType, const Generic* src, Bool move) -> Result<Array<Generic>::NonConst>
{
	return MTable::_instance.ArrayFactory_NewBlockArray(elementType, src, move);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ArrayFactory::NewPagedArray(const DataType& elementType, const Generic* defaultValue, Bool useRefCountForDefault) -> Result<Array<Generic>::NonConst>
{
	return MTable::_instance.ArrayFactory_NewPagedArray(elementType, defaultValue, useRefCountForDefault);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ArrayFactory::NewPagedArrayFromContainerType(const ContainerDataType<>& containerType, const Generic* defaultValue, Bool useRefCountForDefault) -> Result<Array<Generic>::NonConst>
{
	return MTable::_instance.ArrayFactory_NewPagedArrayFromContainerType(containerType, defaultValue, useRefCountForDefault);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ArrayFactory::Slice(const Array<Generic>& base, Int start, Int end, Bool cycle, const Generic* defaultValue, Bool useRefCountForDefault) -> Result<Array<Generic>>
{
	return MTable::_instance.ArrayFactory_Slice(base, start, end, cycle, defaultValue, useRefCountForDefault);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ArrayFactory::NewSingleValueArray(const ConstDataPtr& value, Int count, const ContainerDataType<>& containerType) -> Result<Array<Generic>>
{
	return MTable::_instance.ArrayFactory_NewSingleValueArray(value, count, containerType);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ArrayFactory::ExtractMember(const Array<Generic>& base, Int offset, const ContainerDataType<>& containerType) -> Result<Array<Generic>>
{
	return MTable::_instance.ArrayFactory_ExtractMember(base, offset, containerType);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ArrayFactory::Reinterpret(const Array<Generic>& base, const ContainerDataType<>& containerType) -> Result<Array<Generic>>
{
	return MTable::_instance.ArrayFactory_Reinterpret(base, containerType);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ArrayFactory::PrivateNewPagedArrayFromBase(const Array<Generic>& base, const Generic* defaultValue, Bool useRefCountForDefault) -> Result<Array<Generic>::NonConst>
{
	return MTable::_instance.ArrayFactory_PrivateNewPagedArrayFromBase(base, defaultValue, useRefCountForDefault);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ArrayFactory::ConvertToSingleBlock(const Array<Generic>& source) -> Result<Array<Generic>>
{
	return MTable::_instance.ArrayFactory_ConvertToSingleBlock(source);
}

#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT) && !defined(MAXON_DEPENDENCY_DISABLE_array)
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

