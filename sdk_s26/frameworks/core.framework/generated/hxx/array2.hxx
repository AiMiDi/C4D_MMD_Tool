
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
	Result<void> (*PersistentIdGeneratorInterface_InitializeBuffer) (const PersistentIdGeneratorInterface* this_, PersistentIdBuffer& buffer);
	void (*PersistentIdGeneratorInterface_FreeBuffer) (const PersistentIdGeneratorInterface* this_, PersistentIdBuffer& buffer);
	Result<void> (*PersistentIdGeneratorInterface_Move) (const PersistentIdGeneratorInterface* this_, Int index, PersistentIdBuffer& buffer);
	Result<void> (*PersistentIdGeneratorInterface_Advance) (const PersistentIdGeneratorInterface* this_, Int index, PersistentIdBuffer& buffer);
	maxon::ClassInfoBase _info;
	template <typename IMPL> void Init()
	{
		void (*free) (const PersistentIdGeneratorInterface*) = &IMPL::Implementation::Free;
		_info._free = reinterpret_cast<void(*)(const void*)>(free);
		PersistentIdGeneratorInterface_InitializeBuffer = &IMPL::PersistentIdGeneratorInterface_InitializeBuffer;
		PersistentIdGeneratorInterface_FreeBuffer = &IMPL::PersistentIdGeneratorInterface_FreeBuffer;
		PersistentIdGeneratorInterface_Move = &IMPL::PersistentIdGeneratorInterface_Move;
		PersistentIdGeneratorInterface_Advance = &IMPL::PersistentIdGeneratorInterface_Advance;
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
		static Result<void> PersistentIdGeneratorInterface_InitializeBuffer(const PersistentIdGeneratorInterface* this_, PersistentIdBuffer& buffer) { return C::Get(this_)->InitializeBuffer(buffer); }
		static void PersistentIdGeneratorInterface_FreeBuffer(const PersistentIdGeneratorInterface* this_, PersistentIdBuffer& buffer) { return C::Get(this_)->FreeBuffer(buffer); }
		static Result<void> PersistentIdGeneratorInterface_Move(const PersistentIdGeneratorInterface* this_, Int index, PersistentIdBuffer& buffer) { return C::Get(this_)->Move(index, buffer); }
		static Result<void> PersistentIdGeneratorInterface_Advance(const PersistentIdGeneratorInterface* this_, Int index, PersistentIdBuffer& buffer) { return C::Get(this_)->Advance(index, buffer); }
	};

};
MAXON_ATTRIBUTE_FORCE_INLINE auto PersistentIdGeneratorInterface::InitializeBuffer(PersistentIdBuffer& buffer) const -> Result<void>
{
	return ((PersistentIdGeneratorInterface::MTable*) (this->_vtableCls + 1))[-1].PersistentIdGeneratorInterface_InitializeBuffer(this, buffer);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto PersistentIdGeneratorInterface::FreeBuffer(PersistentIdBuffer& buffer) const -> void
{
	return ((PersistentIdGeneratorInterface::MTable*) (this->_vtableCls + 1))[-1].PersistentIdGeneratorInterface_FreeBuffer(this, buffer);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto PersistentIdGeneratorInterface::Move(Int index, PersistentIdBuffer& buffer) const -> Result<void>
{
	return ((PersistentIdGeneratorInterface::MTable*) (this->_vtableCls + 1))[-1].PersistentIdGeneratorInterface_Move(this, index, buffer);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto PersistentIdGeneratorInterface::Advance(Int index, PersistentIdBuffer& buffer) const -> Result<void>
{
	return ((PersistentIdGeneratorInterface::MTable*) (this->_vtableCls + 1))[-1].PersistentIdGeneratorInterface_Advance(this, index, buffer);
}

PersistentIdGeneratorInterface::PersistentIdGeneratorInterface(const MTable& vtable) : _vtableCls(&vtable._info) { }
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto PersistentIdGeneratorInterface::Hxx1::ConstFn<S>::InitializeBuffer(PersistentIdBuffer& buffer) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const PersistentIdGeneratorInterface* o_ = (const PersistentIdGeneratorInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = PersistentIdGeneratorInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (((PersistentIdGeneratorInterface::MTable*) (o_->_vtableCls + 1))[-1].PersistentIdGeneratorInterface_InitializeBuffer(o_, buffer));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto PersistentIdGeneratorInterface::Hxx1::ConstFn<S>::FreeBuffer(PersistentIdBuffer& buffer) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const PersistentIdGeneratorInterface* o_ = (const PersistentIdGeneratorInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = PersistentIdGeneratorInterface::NullValuePtr(); if (!o_) return maxon::PrivateLogNullptrError(); } 
	((PersistentIdGeneratorInterface::MTable*) (o_->_vtableCls + 1))[-1].PersistentIdGeneratorInterface_FreeBuffer(o_, buffer);
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto PersistentIdGeneratorInterface::Hxx1::ConstFn<S>::Move(Int index, PersistentIdBuffer& buffer) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const PersistentIdGeneratorInterface* o_ = (const PersistentIdGeneratorInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = PersistentIdGeneratorInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (((PersistentIdGeneratorInterface::MTable*) (o_->_vtableCls + 1))[-1].PersistentIdGeneratorInterface_Move(o_, index, buffer));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto PersistentIdGeneratorInterface::Hxx1::ConstFn<S>::Advance(Int index, PersistentIdBuffer& buffer) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const PersistentIdGeneratorInterface* o_ = (const PersistentIdGeneratorInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = PersistentIdGeneratorInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (((PersistentIdGeneratorInterface::MTable*) (o_->_vtableCls + 1))[-1].PersistentIdGeneratorInterface_Advance(o_, index, buffer));
}

template <typename TYPE> struct StaticArrayInterface<TYPE>::MTable
{
	MTable() { }
	template <typename C> explicit MTable(C*) { Init<typename maxon::SFINAEHelper<Hxx2, C>::type::template Wrapper<C>>(); }
	template <typename C> MTable(C*, maxon::Bool) { Init<C>(); }
	Int (*StaticArrayInterface_GetCount) (const StaticArrayInterface* this_);
	const TYPE& (*StaticArrayInterface_operatorIndex) (const StaticArrayInterface* this_, Int index);
	ResultRef<TYPE> (*StaticArrayInterface_GetWritable) (StaticArrayInterface* this_, Int index);
	Int (*StaticArrayInterface_GetBlock) (const StaticArrayInterface* this_, Int index, SimdBlock<const TYPE>& block);
	Result<Int> (*StaticArrayInterface_GetBlock_1) (StaticArrayInterface* this_, Int index, SimdBlock<NonConstValueType>& block);
	const DataType& (*StaticArrayInterface_GetValueDataType) (const StaticArrayInterface* this_);
	const PersistentIdGenerator& (*StaticArrayInterface_GetPersistentIdGenerator) (const StaticArrayInterface* this_);
	Result<void> (*StaticArrayInterface_MakeAllElementsWritable) (StaticArrayInterface* this_, Bool copyElements);
	Result<void> (*StaticArrayInterface_MakeElementsWritable) (StaticArrayInterface* this_, Int start, Int end, Bool copyElements);
	PRIVATE_MAXON_ALLOC_TYPENAME GenericIndexableContainerInterface::MTable super;
	template <typename IMPL> void Init()
	{
		StaticArrayInterface_GetCount = &IMPL::StaticArrayInterface_GetCount;
		StaticArrayInterface_operatorIndex = &IMPL::StaticArrayInterface_operatorIndex;
		StaticArrayInterface_GetWritable = &IMPL::StaticArrayInterface_GetWritable;
		StaticArrayInterface_GetBlock = &IMPL::StaticArrayInterface_GetBlock;
		StaticArrayInterface_GetBlock_1 = &IMPL::StaticArrayInterface_GetBlock_1;
		StaticArrayInterface_GetValueDataType = &IMPL::StaticArrayInterface_GetValueDataType;
		StaticArrayInterface_GetPersistentIdGenerator = &IMPL::StaticArrayInterface_GetPersistentIdGenerator;
		StaticArrayInterface_MakeAllElementsWritable = &IMPL::StaticArrayInterface_MakeAllElementsWritable;
		StaticArrayInterface_MakeElementsWritable = &IMPL::StaticArrayInterface_MakeElementsWritable;
		super.template Init<IMPL>();
	}
	template <typename W> static maxon::Bool InitWithBases(maxon::ClassInfo* info, maxon::Int offset) { return true; }
	template <typename S> using CombinedMTable = S;
};

template <typename TYPE> struct StaticArrayInterface<TYPE>::Hxx2
{
	template <typename C> using CWrapper = C;
	template <typename C> class Wrapper : public GenericIndexableContainerInterface::Hxx2::PRIVATE_MAXON_TEMPLATE_PREFIX Wrapper<C>
	{
	public:
		static Int StaticArrayInterface_GetCount(const StaticArrayInterface* this_) { return C::Get(this_)->GetCount(); }
		static const TYPE& StaticArrayInterface_operatorIndex(const StaticArrayInterface* this_, Int index) { return C::Get(this_)->operator [](index); }
		static ResultRef<TYPE> StaticArrayInterface_GetWritable(StaticArrayInterface* this_, Int index) { return C::Get(this_)->GetWritable(index); }
		static Int StaticArrayInterface_GetBlock(const StaticArrayInterface* this_, Int index, SimdBlock<const TYPE>& block) { return C::Get(this_)->GetBlock(index, block); }
		static Result<Int> StaticArrayInterface_GetBlock_1(StaticArrayInterface* this_, Int index, SimdBlock<NonConstValueType>& block) { return C::Get(this_)->GetBlock(index, block); }
		static const DataType& StaticArrayInterface_GetValueDataType(const StaticArrayInterface* this_) { return C::Get(this_)->GetValueDataType(); }
		static const PersistentIdGenerator& StaticArrayInterface_GetPersistentIdGenerator(const StaticArrayInterface* this_) { return C::Get(this_)->GetPersistentIdGenerator(); }
		static Result<void> StaticArrayInterface_MakeAllElementsWritable(StaticArrayInterface* this_, Bool copyElements) { return C::Get(this_)->MakeAllElementsWritable(copyElements); }
		static Result<void> StaticArrayInterface_MakeElementsWritable(StaticArrayInterface* this_, Int start, Int end, Bool copyElements) { return C::Get(this_)->MakeElementsWritable(start, end, copyElements); }
	};

};
template <typename TYPE> MAXON_ATTRIBUTE_FORCE_INLINE auto StaticArrayInterface<TYPE>::GetCount() const -> Int
{
	return ((StaticArrayInterface::MTable*) (this->_vtableCls + 1))[-1].StaticArrayInterface_GetCount(this);
}
template <typename TYPE> MAXON_ATTRIBUTE_FORCE_INLINE auto StaticArrayInterface<TYPE>::operator [](Int index) const -> const TYPE&
{
	return ((StaticArrayInterface::MTable*) (this->_vtableCls + 1))[-1].StaticArrayInterface_operatorIndex(this, index);
}
template <typename TYPE> MAXON_ATTRIBUTE_FORCE_INLINE auto StaticArrayInterface<TYPE>::GetWritable(Int index) -> ResultRef<TYPE>
{
	return ((StaticArrayInterface::MTable*) (this->_vtableCls + 1))[-1].StaticArrayInterface_GetWritable(this, index);
}
template <typename TYPE> MAXON_ATTRIBUTE_FORCE_INLINE auto StaticArrayInterface<TYPE>::GetBlock(Int index, SimdBlock<const TYPE>& block) const -> Int
{
	return ((StaticArrayInterface::MTable*) (this->_vtableCls + 1))[-1].StaticArrayInterface_GetBlock(this, index, block);
}
template <typename TYPE> MAXON_ATTRIBUTE_FORCE_INLINE auto StaticArrayInterface<TYPE>::GetBlock(Int index, SimdBlock<NonConstValueType>& block) -> Result<Int>
{
	return ((StaticArrayInterface::MTable*) (this->_vtableCls + 1))[-1].StaticArrayInterface_GetBlock_1(this, index, block);
}
template <typename TYPE> MAXON_ATTRIBUTE_FORCE_INLINE auto StaticArrayInterface<TYPE>::GetValueDataType() const -> const DataType&
{
	return ((StaticArrayInterface::MTable*) (this->_vtableCls + 1))[-1].StaticArrayInterface_GetValueDataType(this);
}
template <typename TYPE> MAXON_ATTRIBUTE_FORCE_INLINE auto StaticArrayInterface<TYPE>::GetPersistentIdGenerator() const -> const PersistentIdGenerator&
{
	return ((StaticArrayInterface::MTable*) (this->_vtableCls + 1))[-1].StaticArrayInterface_GetPersistentIdGenerator(this);
}
template <typename TYPE> MAXON_ATTRIBUTE_FORCE_INLINE auto StaticArrayInterface<TYPE>::MakeAllElementsWritable(Bool copyElements) -> Result<void>
{
	return ((StaticArrayInterface::MTable*) (this->_vtableCls + 1))[-1].StaticArrayInterface_MakeAllElementsWritable(this, copyElements);
}
template <typename TYPE> MAXON_ATTRIBUTE_FORCE_INLINE auto StaticArrayInterface<TYPE>::MakeElementsWritable(Int start, Int end, Bool copyElements) -> Result<void>
{
	return ((StaticArrayInterface::MTable*) (this->_vtableCls + 1))[-1].StaticArrayInterface_MakeElementsWritable(this, start, end, copyElements);
}

template <typename TYPE> StaticArrayInterface<TYPE>::StaticArrayInterface(const MTable& vtable) : GenericIndexableContainerInterface(vtable.super) { }
template <typename TYPE> template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto StaticArrayInterface<TYPE>::Hxx1::ConstFn<S>::GetCount() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const StaticArrayInterface* o_ = (const StaticArrayInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = StaticArrayInterface::NullValuePtr(); if (!o_) return 0; } 
	return (((StaticArrayInterface::MTable*) (o_->_vtableCls + 1))[-1].StaticArrayInterface_GetCount(o_));
}
template <typename TYPE> template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto StaticArrayInterface<TYPE>::Hxx1::ConstFn<S>::IsEmpty() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const StaticArrayInterface* o_ = (const StaticArrayInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = StaticArrayInterface::NullValuePtr(); if (!o_) return true; } 
	return (o_->IsEmpty());
}
template <typename TYPE> template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto StaticArrayInterface<TYPE>::Hxx1::ConstFn<S>::IsPopulated() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const StaticArrayInterface* o_ = (const StaticArrayInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = StaticArrayInterface::NullValuePtr(); if (!o_) return maxon::PrivateLogNullptrError(false); } 
	return (o_->IsPopulated());
}
template <typename TYPE> template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto StaticArrayInterface<TYPE>::Hxx1::ConstFn<S>::operator [](Int index) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<const TYPE&>, const TYPE&>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<const TYPE&>, const TYPE&>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const StaticArrayInterface* o_ = (const StaticArrayInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = StaticArrayInterface::NullValuePtr(); if (!o_) return maxon::PrivateNullReturnValue<const TYPE&>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } 
	return (((StaticArrayInterface::MTable*) (o_->_vtableCls + 1))[-1].StaticArrayInterface_operatorIndex(o_, index));
}
template <typename TYPE> template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto StaticArrayInterface<TYPE>::Hxx1::Fn<S>::GetWritable(Int index) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<TYPE&>, ResultRef<TYPE>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<TYPE&>, ResultRef<TYPE>>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); StaticArrayInterface* o_ = (StaticArrayInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateNullReturnValue<ResultRef<TYPE>>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } 
	return (((StaticArrayInterface::MTable*) (o_->_vtableCls + 1))[-1].StaticArrayInterface_GetWritable(o_, index));
}
template <typename TYPE> template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto StaticArrayInterface<TYPE>::Hxx1::COWFn<S>::GetWritable(Int index) -> typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), ResultRef<TYPE>, maxon::Result<TYPE&>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), ResultRef<TYPE>, maxon::Result<TYPE&>>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); StaticArrayInterface* o_ = (StaticArrayInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } 
	return (((StaticArrayInterface::MTable*) (o_->_vtableCls + 1))[-1].StaticArrayInterface_GetWritable(o_, index));
}
template <typename TYPE> template <typename S> template <typename A> MAXON_ATTRIBUTE_FORCE_INLINE auto StaticArrayInterface<TYPE>::Hxx1::Fn<S>::Set(Int index, A&& value) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<void>, ResultMem>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<void>, ResultMem>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); StaticArrayInterface* o_ = (StaticArrayInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateNullReturnValue<ResultMem>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } 
	return (o_->Set<A>(index, std::forward<A>(value)));
}
template <typename TYPE> template <typename S> template <typename A> MAXON_ATTRIBUTE_FORCE_INLINE auto StaticArrayInterface<TYPE>::Hxx1::COWFn<S>::Set(Int index, A&& value) -> typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), ResultMem, maxon::Result<void>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), ResultMem, maxon::Result<void>>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); StaticArrayInterface* o_ = (StaticArrayInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } 
	return (o_->Set<A>(index, std::forward<A>(value)));
}
template <typename TYPE> template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto StaticArrayInterface<TYPE>::Hxx1::ConstFn<S>::GetBlock(Int index, SimdBlock<const TYPE>& block) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const StaticArrayInterface* o_ = (const StaticArrayInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = StaticArrayInterface::NullValuePtr(); if (!o_) return 0; } 
	return (((StaticArrayInterface::MTable*) (o_->_vtableCls + 1))[-1].StaticArrayInterface_GetBlock(o_, index, block));
}
template <typename TYPE> template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto StaticArrayInterface<TYPE>::Hxx1::Fn<S>::GetBlock(Int index, SimdBlock<NonConstValueType>& block) const -> Result<Int>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<Int>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); StaticArrayInterface* o_ = (StaticArrayInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (((StaticArrayInterface::MTable*) (o_->_vtableCls + 1))[-1].StaticArrayInterface_GetBlock_1(o_, index, block));
}
template <typename TYPE> template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto StaticArrayInterface<TYPE>::Hxx1::COWFn<S>::GetWritableBlock(Int index, SimdBlock<NonConstValueType>& block) -> Result<Int>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<Int>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); StaticArrayInterface* o_ = (StaticArrayInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } 
	return (((StaticArrayInterface::MTable*) (o_->_vtableCls + 1))[-1].StaticArrayInterface_GetBlock_1(o_, index, block));
}
template <typename TYPE> template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto StaticArrayInterface<TYPE>::Hxx1::ConstFn<S>::GetValueDataType() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<const DataType&>, const DataType&>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<const DataType&>, const DataType&>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const StaticArrayInterface* o_ = (const StaticArrayInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = StaticArrayInterface::NullValuePtr(); if (!o_) return maxon::PrivateNullReturnValue<const DataType&>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } 
	return (((StaticArrayInterface::MTable*) (o_->_vtableCls + 1))[-1].StaticArrayInterface_GetValueDataType(o_));
}
template <typename TYPE> template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto StaticArrayInterface<TYPE>::Hxx1::ConstFn<S>::GetPersistentIdGenerator() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<const PersistentIdGenerator&>, const PersistentIdGenerator&>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<const PersistentIdGenerator&>, const PersistentIdGenerator&>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const StaticArrayInterface* o_ = (const StaticArrayInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = StaticArrayInterface::NullValuePtr(); if (!o_) return maxon::PrivateNullReturnValue<const PersistentIdGenerator&>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } 
	return (((StaticArrayInterface::MTable*) (o_->_vtableCls + 1))[-1].StaticArrayInterface_GetPersistentIdGenerator(o_));
}
template <typename TYPE> template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto StaticArrayInterface<TYPE>::Hxx1::Fn<S>::MakeAllElementsWritable(Bool copyElements) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); StaticArrayInterface* o_ = (StaticArrayInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (((StaticArrayInterface::MTable*) (o_->_vtableCls + 1))[-1].StaticArrayInterface_MakeAllElementsWritable(o_, copyElements));
}
template <typename TYPE> template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto StaticArrayInterface<TYPE>::Hxx1::COWFn<S>::MakeAllElementsWritable(Bool copyElements) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); StaticArrayInterface* o_ = (StaticArrayInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } 
	return (((StaticArrayInterface::MTable*) (o_->_vtableCls + 1))[-1].StaticArrayInterface_MakeAllElementsWritable(o_, copyElements));
}
template <typename TYPE> template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto StaticArrayInterface<TYPE>::Hxx1::Fn<S>::MakeElementsWritable(Int start, Int end, Bool copyElements) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); StaticArrayInterface* o_ = (StaticArrayInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (((StaticArrayInterface::MTable*) (o_->_vtableCls + 1))[-1].StaticArrayInterface_MakeElementsWritable(o_, start, end, copyElements));
}
template <typename TYPE> template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto StaticArrayInterface<TYPE>::Hxx1::COWFn<S>::MakeElementsWritable(Int start, Int end, Bool copyElements) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); StaticArrayInterface* o_ = (StaticArrayInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } 
	return (((StaticArrayInterface::MTable*) (o_->_vtableCls + 1))[-1].StaticArrayInterface_MakeElementsWritable(o_, start, end, copyElements));
}
template <typename TYPE> template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto StaticArrayInterface<TYPE>::Hxx1::ConstFn<S>::Begin() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<typename StaticArrayInterface<TYPE>::ConstIterator>, typename StaticArrayInterface<TYPE>::ConstIterator>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<typename StaticArrayInterface<TYPE>::ConstIterator>, typename StaticArrayInterface<TYPE>::ConstIterator>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const StaticArrayInterface* o_ = (const StaticArrayInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = StaticArrayInterface::NullValuePtr(); if (!o_) return maxon::PrivateNullReturnValue<typename StaticArrayInterface<TYPE>::ConstIterator>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } 
	return (o_->Begin());
}
template <typename TYPE> template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto StaticArrayInterface<TYPE>::Hxx1::ConstFn<S>::End() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<typename StaticArrayInterface<TYPE>::ConstIterator>, typename StaticArrayInterface<TYPE>::ConstIterator>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<typename StaticArrayInterface<TYPE>::ConstIterator>, typename StaticArrayInterface<TYPE>::ConstIterator>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const StaticArrayInterface* o_ = (const StaticArrayInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = StaticArrayInterface::NullValuePtr(); if (!o_) return maxon::PrivateNullReturnValue<typename StaticArrayInterface<TYPE>::ConstIterator>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } 
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
	Int (*ArrayInterface_GetBlock) (const ArrayInterface* this_, Int index, Block<const TYPE>& block);
	void* _MAXON_METHOD_RESERVE11;
	Result<void> (*ArrayInterface_PrivateInsert) (ArrayInterface* this_, Int index, const StridedBlock<const TYPE>& values, Bool move);
	ResultMem (*ArrayInterface_Resize) (ArrayInterface* this_, Int count, COLLECTION_RESIZE_FLAGS resizeFlags);
	ResultMem (*ArrayInterface_SetCapacityHint) (ArrayInterface* this_, Int requestedCapacity, COLLECTION_RESIZE_FLAGS resizeFlags);
	ResultRef<TYPE> (*ArrayInterface_Insert) (ArrayInterface* this_, Int index);
	ResultMem (*ArrayInterface_Insert_1) (ArrayInterface* this_, Int index, const Block<const TYPE>& values);
	ResultMem (*ArrayInterface_Insert_2) (ArrayInterface* this_, Int index, const MoveBlock<TYPE>& values);
	ResultRef<TYPE> (*ArrayInterface_Append) (ArrayInterface* this_);
	ResultMem (*ArrayInterface_Erase) (ArrayInterface* this_, Int index, Int count);
	ResultMem (*ArrayInterface_SwapErase) (ArrayInterface* this_, Int index, Int count);
	void (*ArrayInterface_Reset) (ArrayInterface* this_);
	void (*ArrayInterface_Flush) (ArrayInterface* this_);
	Result<void> (*ArrayInterface_CopyFrom) (ArrayInterface* this_, const ArrayInterface& other);
	void (*ArrayInterface_SetPersistentIdGenerator) (ArrayInterface* this_, const PersistentIdGenerator& generator);
	Int (*ArrayInterface_GetMemorySize) (const ArrayInterface* this_);
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
	PRIVATE_MAXON_ALLOC_TYPENAME ArrayBase0<ArrayInterface<TYPE>, TYPE, StaticArrayInterface<TYPE>, DefaultCompare>::MTable super;
	template <typename IMPL> void Init()
	{
		ArrayInterface_GetBlock = &IMPL::ArrayInterface_GetBlock;
		_MAXON_METHOD_RESERVE11 = nullptr;
		ArrayInterface_PrivateInsert = &IMPL::ArrayInterface_PrivateInsert;
		ArrayInterface_Resize = &IMPL::ArrayInterface_Resize;
		ArrayInterface_SetCapacityHint = &IMPL::ArrayInterface_SetCapacityHint;
		ArrayInterface_Insert = &IMPL::ArrayInterface_Insert;
		ArrayInterface_Insert_1 = &IMPL::ArrayInterface_Insert_1;
		ArrayInterface_Insert_2 = &IMPL::ArrayInterface_Insert_2;
		ArrayInterface_Append = &IMPL::ArrayInterface_Append;
		ArrayInterface_Erase = &IMPL::ArrayInterface_Erase;
		ArrayInterface_SwapErase = &IMPL::ArrayInterface_SwapErase;
		ArrayInterface_Reset = &IMPL::ArrayInterface_Reset;
		ArrayInterface_Flush = &IMPL::ArrayInterface_Flush;
		ArrayInterface_CopyFrom = &IMPL::ArrayInterface_CopyFrom;
		ArrayInterface_SetPersistentIdGenerator = &IMPL::ArrayInterface_SetPersistentIdGenerator;
		ArrayInterface_GetMemorySize = &IMPL::ArrayInterface_GetMemorySize;
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
	template <typename C> class Wrapper : public ArrayBase0<ArrayInterface<TYPE>, TYPE, StaticArrayInterface<TYPE>, DefaultCompare>::Hxx2::PRIVATE_MAXON_TEMPLATE_PREFIX Wrapper<C>
	{
	public:
		static Int ArrayInterface_GetBlock(const ArrayInterface* this_, Int index, Block<const TYPE>& block) { return C::Get(this_)->GetBlock(index, block); }
		static Result<void> ArrayInterface_PrivateInsert(ArrayInterface* this_, Int index, const StridedBlock<const TYPE>& values, Bool move) { return C::Get(this_)->PrivateInsert(index, values, move); }
		static ResultMem ArrayInterface_Resize(ArrayInterface* this_, Int count, COLLECTION_RESIZE_FLAGS resizeFlags) { return C::Get(this_)->Resize(count, resizeFlags); }
		static ResultMem ArrayInterface_SetCapacityHint(ArrayInterface* this_, Int requestedCapacity, COLLECTION_RESIZE_FLAGS resizeFlags) { return C::Get(this_)->SetCapacityHint(requestedCapacity, resizeFlags); }
		static ResultRef<TYPE> ArrayInterface_Insert(ArrayInterface* this_, Int index) { return C::Get(this_)->Insert(index); }
		static ResultMem ArrayInterface_Insert_1(ArrayInterface* this_, Int index, const Block<const TYPE>& values) { return C::Get(this_)->Insert(index, values); }
		static ResultMem ArrayInterface_Insert_2(ArrayInterface* this_, Int index, const MoveBlock<TYPE>& values) { return C::Get(this_)->Insert(index, values); }
		static ResultRef<TYPE> ArrayInterface_Append(ArrayInterface* this_) { return C::Get(this_)->Append(); }
		static ResultMem ArrayInterface_Erase(ArrayInterface* this_, Int index, Int count) { return C::Get(this_)->Erase(index, count); }
		static ResultMem ArrayInterface_SwapErase(ArrayInterface* this_, Int index, Int count) { return C::Get(this_)->SwapErase(index, count); }
		static void ArrayInterface_Reset(ArrayInterface* this_) { return C::Get(this_)->Reset(); }
		static void ArrayInterface_Flush(ArrayInterface* this_) { return C::Get(this_)->Flush(); }
		static Result<void> ArrayInterface_CopyFrom(ArrayInterface* this_, const ArrayInterface& other) { return C::Get(this_)->CopyFrom(other); }
		static void ArrayInterface_SetPersistentIdGenerator(ArrayInterface* this_, const PersistentIdGenerator& generator) { return C::Get(this_)->SetPersistentIdGenerator(generator); }
		static Int ArrayInterface_GetMemorySize(const ArrayInterface* this_) { return C::Get(this_)->GetMemorySize(); }
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
	return ((ArrayInterface::MTable*) (this->_vtableCls + 1))[-1].ArrayInterface_GetBlock(this, index, block);
}
template <typename TYPE> MAXON_ATTRIBUTE_FORCE_INLINE auto ArrayInterface<TYPE>::PrivateInsert(Int index, const StridedBlock<const TYPE>& values, Bool move) -> Result<void>
{
	return ((ArrayInterface::MTable*) (this->_vtableCls + 1))[-1].ArrayInterface_PrivateInsert(this, index, values, move);
}
template <typename TYPE> MAXON_ATTRIBUTE_FORCE_INLINE auto ArrayInterface<TYPE>::Resize(Int count, COLLECTION_RESIZE_FLAGS resizeFlags) -> ResultMem
{
	return ((ArrayInterface::MTable*) (this->_vtableCls + 1))[-1].ArrayInterface_Resize(this, count, resizeFlags);
}
template <typename TYPE> MAXON_ATTRIBUTE_FORCE_INLINE auto ArrayInterface<TYPE>::SetCapacityHint(Int requestedCapacity, COLLECTION_RESIZE_FLAGS resizeFlags) -> ResultMem
{
	return ((ArrayInterface::MTable*) (this->_vtableCls + 1))[-1].ArrayInterface_SetCapacityHint(this, requestedCapacity, resizeFlags);
}
template <typename TYPE> MAXON_ATTRIBUTE_FORCE_INLINE auto ArrayInterface<TYPE>::Insert(Int index) -> ResultRef<TYPE>
{
	return ((ArrayInterface::MTable*) (this->_vtableCls + 1))[-1].ArrayInterface_Insert(this, index);
}
template <typename TYPE> MAXON_ATTRIBUTE_FORCE_INLINE auto ArrayInterface<TYPE>::Insert(Int index, const Block<const TYPE>& values) -> ResultMem
{
	return ((ArrayInterface::MTable*) (this->_vtableCls + 1))[-1].ArrayInterface_Insert_1(this, index, values);
}
template <typename TYPE> MAXON_ATTRIBUTE_FORCE_INLINE auto ArrayInterface<TYPE>::Insert(Int index, const MoveBlock<TYPE>& values) -> ResultMem
{
	return ((ArrayInterface::MTable*) (this->_vtableCls + 1))[-1].ArrayInterface_Insert_2(this, index, values);
}
template <typename TYPE> MAXON_ATTRIBUTE_FORCE_INLINE auto ArrayInterface<TYPE>::Append() -> ResultRef<TYPE>
{
	return ((ArrayInterface::MTable*) (this->_vtableCls + 1))[-1].ArrayInterface_Append(this);
}
template <typename TYPE> MAXON_ATTRIBUTE_FORCE_INLINE auto ArrayInterface<TYPE>::Erase(Int index, Int count) -> ResultMem
{
	return ((ArrayInterface::MTable*) (this->_vtableCls + 1))[-1].ArrayInterface_Erase(this, index, count);
}
template <typename TYPE> MAXON_ATTRIBUTE_FORCE_INLINE auto ArrayInterface<TYPE>::SwapErase(Int index, Int count) -> ResultMem
{
	return ((ArrayInterface::MTable*) (this->_vtableCls + 1))[-1].ArrayInterface_SwapErase(this, index, count);
}
template <typename TYPE> MAXON_ATTRIBUTE_FORCE_INLINE auto ArrayInterface<TYPE>::Reset() -> void
{
	return ((ArrayInterface::MTable*) (this->_vtableCls + 1))[-1].ArrayInterface_Reset(this);
}
template <typename TYPE> MAXON_ATTRIBUTE_FORCE_INLINE auto ArrayInterface<TYPE>::Flush() -> void
{
	return ((ArrayInterface::MTable*) (this->_vtableCls + 1))[-1].ArrayInterface_Flush(this);
}
template <typename TYPE> MAXON_ATTRIBUTE_FORCE_INLINE auto ArrayInterface<TYPE>::CopyFrom(const ArrayInterface& other) -> Result<void>
{
	return ((ArrayInterface::MTable*) (this->_vtableCls + 1))[-1].ArrayInterface_CopyFrom(this, other);
}
template <typename TYPE> MAXON_ATTRIBUTE_FORCE_INLINE auto ArrayInterface<TYPE>::SetPersistentIdGenerator(const PersistentIdGenerator& generator) -> void
{
	return ((ArrayInterface::MTable*) (this->_vtableCls + 1))[-1].ArrayInterface_SetPersistentIdGenerator(this, generator);
}
template <typename TYPE> MAXON_ATTRIBUTE_FORCE_INLINE auto ArrayInterface<TYPE>::GetMemorySize() const -> Int
{
	return ((ArrayInterface::MTable*) (this->_vtableCls + 1))[-1].ArrayInterface_GetMemorySize(this);
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
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const ArrayInterface* o_ = (const ArrayInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = ArrayInterface::NullValuePtr(); if (!o_) return 0; } 
	return (((ArrayInterface::MTable*) (o_->_vtableCls + 1))[-1].ArrayInterface_GetBlock(o_, index, block));
}
template <typename TYPE> template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ArrayInterface<TYPE>::Hxx1::Fn<S>::Resize(Int count, COLLECTION_RESIZE_FLAGS resizeFlags) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<void>, ResultMem>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<void>, ResultMem>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); ArrayInterface* o_ = (ArrayInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateNullReturnValue<ResultMem>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } 
	return (((ArrayInterface::MTable*) (o_->_vtableCls + 1))[-1].ArrayInterface_Resize(o_, count, resizeFlags));
}
template <typename TYPE> template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ArrayInterface<TYPE>::Hxx1::COWFn<S>::Resize(Int count, COLLECTION_RESIZE_FLAGS resizeFlags) -> typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), ResultMem, maxon::Result<void>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), ResultMem, maxon::Result<void>>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); ArrayInterface* o_ = (ArrayInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } 
	return (((ArrayInterface::MTable*) (o_->_vtableCls + 1))[-1].ArrayInterface_Resize(o_, count, resizeFlags));
}
template <typename TYPE> template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ArrayInterface<TYPE>::Hxx1::Fn<S>::SetCapacityHint(Int requestedCapacity, COLLECTION_RESIZE_FLAGS resizeFlags) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<void>, ResultMem>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<void>, ResultMem>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); ArrayInterface* o_ = (ArrayInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateNullReturnValue<ResultMem>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } 
	return (((ArrayInterface::MTable*) (o_->_vtableCls + 1))[-1].ArrayInterface_SetCapacityHint(o_, requestedCapacity, resizeFlags));
}
template <typename TYPE> template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ArrayInterface<TYPE>::Hxx1::COWFn<S>::SetCapacityHint(Int requestedCapacity, COLLECTION_RESIZE_FLAGS resizeFlags) -> typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), ResultMem, maxon::Result<void>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), ResultMem, maxon::Result<void>>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); ArrayInterface* o_ = (ArrayInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } 
	return (((ArrayInterface::MTable*) (o_->_vtableCls + 1))[-1].ArrayInterface_SetCapacityHint(o_, requestedCapacity, resizeFlags));
}
template <typename TYPE> template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ArrayInterface<TYPE>::Hxx1::Fn<S>::Insert(Int index) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<TYPE&>, ResultRef<TYPE>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<TYPE&>, ResultRef<TYPE>>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); ArrayInterface* o_ = (ArrayInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateNullReturnValue<ResultRef<TYPE>>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } 
	return (((ArrayInterface::MTable*) (o_->_vtableCls + 1))[-1].ArrayInterface_Insert(o_, index));
}
template <typename TYPE> template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ArrayInterface<TYPE>::Hxx1::COWFn<S>::Insert(Int index) -> typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), ResultRef<TYPE>, maxon::Result<TYPE&>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), ResultRef<TYPE>, maxon::Result<TYPE&>>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); ArrayInterface* o_ = (ArrayInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } 
	return (((ArrayInterface::MTable*) (o_->_vtableCls + 1))[-1].ArrayInterface_Insert(o_, index));
}
template <typename TYPE> template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ArrayInterface<TYPE>::Hxx1::Fn<S>::Insert(Int index, const TYPE& value) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<TYPE&>, ResultRef<TYPE>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<TYPE&>, ResultRef<TYPE>>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); ArrayInterface* o_ = (ArrayInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateNullReturnValue<ResultRef<TYPE>>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } 
	return (o_->Insert(index, value));
}
template <typename TYPE> template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ArrayInterface<TYPE>::Hxx1::COWFn<S>::Insert(Int index, const TYPE& value) -> typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), ResultRef<TYPE>, maxon::Result<TYPE&>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), ResultRef<TYPE>, maxon::Result<TYPE&>>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); ArrayInterface* o_ = (ArrayInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } 
	return (o_->Insert(index, value));
}
template <typename TYPE> template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ArrayInterface<TYPE>::Hxx1::Fn<S>::Insert(Int index, TYPE&& value) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<TYPE&>, ResultRef<TYPE>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<TYPE&>, ResultRef<TYPE>>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); ArrayInterface* o_ = (ArrayInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateNullReturnValue<ResultRef<TYPE>>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } 
	return (o_->Insert(index, std::forward<TYPE>(value)));
}
template <typename TYPE> template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ArrayInterface<TYPE>::Hxx1::COWFn<S>::Insert(Int index, TYPE&& value) -> typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), ResultRef<TYPE>, maxon::Result<TYPE&>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), ResultRef<TYPE>, maxon::Result<TYPE&>>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); ArrayInterface* o_ = (ArrayInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } 
	return (o_->Insert(index, std::forward<TYPE>(value)));
}
template <typename TYPE> template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ArrayInterface<TYPE>::Hxx1::Fn<S>::Insert(Int index, const Block<const TYPE>& values) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<void>, ResultMem>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<void>, ResultMem>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); ArrayInterface* o_ = (ArrayInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateNullReturnValue<ResultMem>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } 
	return (((ArrayInterface::MTable*) (o_->_vtableCls + 1))[-1].ArrayInterface_Insert_1(o_, index, values));
}
template <typename TYPE> template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ArrayInterface<TYPE>::Hxx1::COWFn<S>::Insert(Int index, const Block<const TYPE>& values) -> typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), ResultMem, maxon::Result<void>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), ResultMem, maxon::Result<void>>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); ArrayInterface* o_ = (ArrayInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } 
	return (((ArrayInterface::MTable*) (o_->_vtableCls + 1))[-1].ArrayInterface_Insert_1(o_, index, values));
}
template <typename TYPE> template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ArrayInterface<TYPE>::Hxx1::Fn<S>::Insert(Int index, const MoveBlock<TYPE>& values) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<void>, ResultMem>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<void>, ResultMem>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); ArrayInterface* o_ = (ArrayInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateNullReturnValue<ResultMem>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } 
	return (((ArrayInterface::MTable*) (o_->_vtableCls + 1))[-1].ArrayInterface_Insert_2(o_, index, values));
}
template <typename TYPE> template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ArrayInterface<TYPE>::Hxx1::COWFn<S>::Insert(Int index, const MoveBlock<TYPE>& values) -> typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), ResultMem, maxon::Result<void>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), ResultMem, maxon::Result<void>>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); ArrayInterface* o_ = (ArrayInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } 
	return (((ArrayInterface::MTable*) (o_->_vtableCls + 1))[-1].ArrayInterface_Insert_2(o_, index, values));
}
template <typename TYPE> template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ArrayInterface<TYPE>::Hxx1::Fn<S>::Append() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<TYPE&>, ResultRef<TYPE>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<TYPE&>, ResultRef<TYPE>>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); ArrayInterface* o_ = (ArrayInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateNullReturnValue<ResultRef<TYPE>>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } 
	return (((ArrayInterface::MTable*) (o_->_vtableCls + 1))[-1].ArrayInterface_Append(o_));
}
template <typename TYPE> template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ArrayInterface<TYPE>::Hxx1::COWFn<S>::Append() -> typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), ResultRef<TYPE>, maxon::Result<TYPE&>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), ResultRef<TYPE>, maxon::Result<TYPE&>>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); ArrayInterface* o_ = (ArrayInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } 
	return (((ArrayInterface::MTable*) (o_->_vtableCls + 1))[-1].ArrayInterface_Append(o_));
}
template <typename TYPE> template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ArrayInterface<TYPE>::Hxx1::Fn<S>::Append(const TYPE& value) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<TYPE&>, ResultRef<TYPE>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<TYPE&>, ResultRef<TYPE>>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); ArrayInterface* o_ = (ArrayInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateNullReturnValue<ResultRef<TYPE>>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } 
	return (o_->Append(value));
}
template <typename TYPE> template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ArrayInterface<TYPE>::Hxx1::COWFn<S>::Append(const TYPE& value) -> typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), ResultRef<TYPE>, maxon::Result<TYPE&>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), ResultRef<TYPE>, maxon::Result<TYPE&>>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); ArrayInterface* o_ = (ArrayInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } 
	return (o_->Append(value));
}
template <typename TYPE> template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ArrayInterface<TYPE>::Hxx1::Fn<S>::Append(TYPE&& value) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<TYPE&>, ResultRef<TYPE>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<TYPE&>, ResultRef<TYPE>>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); ArrayInterface* o_ = (ArrayInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateNullReturnValue<ResultRef<TYPE>>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } 
	return (o_->Append(std::forward<TYPE>(value)));
}
template <typename TYPE> template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ArrayInterface<TYPE>::Hxx1::COWFn<S>::Append(TYPE&& value) -> typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), ResultRef<TYPE>, maxon::Result<TYPE&>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), ResultRef<TYPE>, maxon::Result<TYPE&>>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); ArrayInterface* o_ = (ArrayInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } 
	return (o_->Append(std::forward<TYPE>(value)));
}
template <typename TYPE> template <typename S> template <typename A> MAXON_ATTRIBUTE_FORCE_INLINE auto ArrayInterface<TYPE>::Hxx1::Fn<S>::Append(A&& value) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<TYPE&>, ResultRef<TYPE>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<TYPE&>, ResultRef<TYPE>>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); ArrayInterface* o_ = (ArrayInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateNullReturnValue<ResultRef<TYPE>>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } 
	return (o_->Append<A>(std::forward<A>(value)));
}
template <typename TYPE> template <typename S> template <typename A> MAXON_ATTRIBUTE_FORCE_INLINE auto ArrayInterface<TYPE>::Hxx1::COWFn<S>::Append(A&& value) -> typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), ResultRef<TYPE>, maxon::Result<TYPE&>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), ResultRef<TYPE>, maxon::Result<TYPE&>>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); ArrayInterface* o_ = (ArrayInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } 
	return (o_->Append<A>(std::forward<A>(value)));
}
template <typename TYPE> template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ArrayInterface<TYPE>::Hxx1::Fn<S>::Pop() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); ArrayInterface* o_ = (ArrayInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateLogNullptrError(false); } 
	return (o_->Pop());
}
template <typename TYPE> template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ArrayInterface<TYPE>::Hxx1::COWFn<S>::Pop() -> typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), Bool, maxon::Result<Bool>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), Bool, maxon::Result<Bool>>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); ArrayInterface* o_ = (ArrayInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } 
	return (o_->Pop());
}
template <typename TYPE> template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ArrayInterface<TYPE>::Hxx1::Fn<S>::Pop(TYPE* dst) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); ArrayInterface* o_ = (ArrayInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateLogNullptrError(false); } 
	return (o_->Pop(dst));
}
template <typename TYPE> template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ArrayInterface<TYPE>::Hxx1::COWFn<S>::Pop(TYPE* dst) -> typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), Bool, maxon::Result<Bool>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), Bool, maxon::Result<Bool>>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); ArrayInterface* o_ = (ArrayInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } 
	return (o_->Pop(dst));
}
template <typename TYPE> template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ArrayInterface<TYPE>::Hxx1::Fn<S>::Erase(Int index, Int count) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<void>, ResultMem>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<void>, ResultMem>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); ArrayInterface* o_ = (ArrayInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateNullReturnValue<ResultMem>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } 
	return (((ArrayInterface::MTable*) (o_->_vtableCls + 1))[-1].ArrayInterface_Erase(o_, index, count));
}
template <typename TYPE> template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ArrayInterface<TYPE>::Hxx1::COWFn<S>::Erase(Int index, Int count) -> typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), ResultMem, maxon::Result<void>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), ResultMem, maxon::Result<void>>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); ArrayInterface* o_ = (ArrayInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } 
	return (((ArrayInterface::MTable*) (o_->_vtableCls + 1))[-1].ArrayInterface_Erase(o_, index, count));
}
template <typename TYPE> template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ArrayInterface<TYPE>::Hxx1::Fn<S>::SwapErase(Int index, Int count) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<void>, ResultMem>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<void>, ResultMem>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); ArrayInterface* o_ = (ArrayInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateNullReturnValue<ResultMem>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } 
	return (((ArrayInterface::MTable*) (o_->_vtableCls + 1))[-1].ArrayInterface_SwapErase(o_, index, count));
}
template <typename TYPE> template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ArrayInterface<TYPE>::Hxx1::COWFn<S>::SwapErase(Int index, Int count) -> typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), ResultMem, maxon::Result<void>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), ResultMem, maxon::Result<void>>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); ArrayInterface* o_ = (ArrayInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } 
	return (((ArrayInterface::MTable*) (o_->_vtableCls + 1))[-1].ArrayInterface_SwapErase(o_, index, count));
}
template <typename TYPE> template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ArrayInterface<TYPE>::Hxx1::Fn<S>::Reset() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); ArrayInterface* o_ = (ArrayInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { DebugStop(); return maxon::PrivateLogNullptrError(); } 
	((ArrayInterface::MTable*) (o_->_vtableCls + 1))[-1].ArrayInterface_Reset(o_);
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
template <typename TYPE> template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ArrayInterface<TYPE>::Hxx1::COWFn<S>::Reset() -> typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), void, maxon::Result<void>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), void, maxon::Result<void>>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); ArrayInterface* o_ = (ArrayInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } 
	((ArrayInterface::MTable*) (o_->_vtableCls + 1))[-1].ArrayInterface_Reset(o_);
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
template <typename TYPE> template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ArrayInterface<TYPE>::Hxx1::Fn<S>::Flush() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); ArrayInterface* o_ = (ArrayInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { DebugStop(); return maxon::PrivateLogNullptrError(); } 
	((ArrayInterface::MTable*) (o_->_vtableCls + 1))[-1].ArrayInterface_Flush(o_);
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
template <typename TYPE> template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ArrayInterface<TYPE>::Hxx1::COWFn<S>::Flush() -> typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), void, maxon::Result<void>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), void, maxon::Result<void>>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); ArrayInterface* o_ = (ArrayInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } 
	((ArrayInterface::MTable*) (o_->_vtableCls + 1))[-1].ArrayInterface_Flush(o_);
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
template <typename TYPE> template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ArrayInterface<TYPE>::Hxx1::Fn<S>::CopyFrom(const ArrayInterface& other) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); ArrayInterface* o_ = (ArrayInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (((ArrayInterface::MTable*) (o_->_vtableCls + 1))[-1].ArrayInterface_CopyFrom(o_, other));
}
template <typename TYPE> template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ArrayInterface<TYPE>::Hxx1::COWFn<S>::CopyFrom(const ArrayInterface& other) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); ArrayInterface* o_ = (ArrayInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } 
	return (((ArrayInterface::MTable*) (o_->_vtableCls + 1))[-1].ArrayInterface_CopyFrom(o_, other));
}
template <typename TYPE> template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ArrayInterface<TYPE>::Hxx1::Fn<S>::SetPersistentIdGenerator(const PersistentIdGenerator& generator) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); ArrayInterface* o_ = (ArrayInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { DebugStop(); return maxon::PrivateLogNullptrError(); } 
	((ArrayInterface::MTable*) (o_->_vtableCls + 1))[-1].ArrayInterface_SetPersistentIdGenerator(o_, generator);
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
template <typename TYPE> template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ArrayInterface<TYPE>::Hxx1::COWFn<S>::SetPersistentIdGenerator(const PersistentIdGenerator& generator) -> typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), void, maxon::Result<void>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), void, maxon::Result<void>>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); ArrayInterface* o_ = (ArrayInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } 
	((ArrayInterface::MTable*) (o_->_vtableCls + 1))[-1].ArrayInterface_SetPersistentIdGenerator(o_, generator);
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
template <typename TYPE> template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ArrayInterface<TYPE>::Hxx1::ConstFn<S>::GetMemorySize() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const ArrayInterface* o_ = (const ArrayInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = ArrayInterface::NullValuePtr(); if (!o_) return 0; } 
	return (((ArrayInterface::MTable*) (o_->_vtableCls + 1))[-1].ArrayInterface_GetMemorySize(o_));
}
template <typename TYPE> template <typename S> template <typename DT> MAXON_ATTRIBUTE_FORCE_INLINE auto ArrayInterface<TYPE>::Hxx1::ConstFn<S>::HasType() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const ArrayInterface* o_ = (const ArrayInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = ArrayInterface::NullValuePtr(); if (!o_) return maxon::PrivateLogNullptrError(false); } 
	return (o_->HasType<DT>());
}
template <typename TYPE> template <typename S> template <typename DT> MAXON_ATTRIBUTE_FORCE_INLINE auto ArrayInterface<TYPE>::Hxx1::ConstFn<S>::AssertType() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const ArrayInterface* o_ = (const ArrayInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = ArrayInterface::NullValuePtr(); if (!o_) return maxon::PrivateLogNullptrError(); } 
	o_->AssertType<DT>();
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
#ifdef MAXON_COMPILER_INTEL
#endif
#ifdef MAXON_COMPILER_INTEL
#endif
template <typename TYPE> template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ArrayInterface<TYPE>::Hxx1::ConstFn<S>::Begin() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<typename ArrayInterface<TYPE>::ConstIterator>, typename ArrayInterface<TYPE>::ConstIterator>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<typename ArrayInterface<TYPE>::ConstIterator>, typename ArrayInterface<TYPE>::ConstIterator>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const ArrayInterface* o_ = (const ArrayInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = ArrayInterface::NullValuePtr(); if (!o_) return maxon::PrivateNullReturnValue<typename ArrayInterface<TYPE>::ConstIterator>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } 
	return (o_->Begin());
}
template <typename TYPE> template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ArrayInterface<TYPE>::Hxx1::ConstFn<S>::End() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<typename ArrayInterface<TYPE>::ConstIterator>, typename ArrayInterface<TYPE>::ConstIterator>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<typename ArrayInterface<TYPE>::ConstIterator>, typename ArrayInterface<TYPE>::ConstIterator>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const ArrayInterface* o_ = (const ArrayInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = ArrayInterface::NullValuePtr(); if (!o_) return maxon::PrivateNullReturnValue<typename ArrayInterface<TYPE>::ConstIterator>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } 
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
	Result<ArrayInterface<Generic>*> (*ArrayFactory_NewBaseArray) (const DataType& elementType, const Generic* src, Bool move);
	Result<ArrayInterface<Generic>*> (*ArrayFactory_NewBaseArrayFromContainerType) (const ContainerDataType<>& containerType, const Generic* src, Bool move);
	Result<ArrayInterface<Generic>*> (*ArrayFactory_NewBlockArray) (const DataType& elementType, const Generic* src, Bool move);
	Result<Array<Generic>> (*ArrayFactory_NewPagedArray) (const DataType& elementType, const Generic* defaultValue, Bool useRefCountForDefault);
	Result<Array<Generic>> (*ArrayFactory_NewPagedArrayFromContainerType) (const ContainerDataType<>& containerType, const Generic* defaultValue, Bool useRefCountForDefault);
	Result<Array<Generic>> (*ArrayFactory_Slice) (const Array<Generic>& base, Int start, Int end, Bool cycle, const Generic* defaultValue, Bool useRefCountForDefault);
	Result<Array<Generic>> (*ArrayFactory_NewSingleValueArray) (const ConstDataPtr& value, Int count, const ContainerDataType<>& containerType);
	Result<Array<Generic>> (*ArrayFactory_ExtractMember) (const Array<Generic>& base, Int offset, const ContainerDataType<>& containerType);
	Result<Array<Generic>> (*ArrayFactory_Reinterpret) (const Array<Generic>& base, const ContainerDataType<>& containerType);
	Result<Array<Generic>> (*ArrayFactory_PrivateNewPagedArrayFromBase) (const Array<Generic>& base, const Generic* defaultValue, Bool useRefCountForDefault);
	template <typename IMPL> void Init()
	{
		ArrayFactory_NewBaseArray = &IMPL::ArrayFactory_NewBaseArray;
		ArrayFactory_NewBaseArrayFromContainerType = &IMPL::ArrayFactory_NewBaseArrayFromContainerType;
		ArrayFactory_NewBlockArray = &IMPL::ArrayFactory_NewBlockArray;
		ArrayFactory_NewPagedArray = &IMPL::ArrayFactory_NewPagedArray;
		ArrayFactory_NewPagedArrayFromContainerType = &IMPL::ArrayFactory_NewPagedArrayFromContainerType;
		ArrayFactory_Slice = &IMPL::ArrayFactory_Slice;
		ArrayFactory_NewSingleValueArray = &IMPL::ArrayFactory_NewSingleValueArray;
		ArrayFactory_ExtractMember = &IMPL::ArrayFactory_ExtractMember;
		ArrayFactory_Reinterpret = &IMPL::ArrayFactory_Reinterpret;
		ArrayFactory_PrivateNewPagedArrayFromBase = &IMPL::ArrayFactory_PrivateNewPagedArrayFromBase;
	}
};

struct ArrayFactory::Hxx2
{
	class Unresolved;
	template <typename C> class Wrapper
	{
	public:
		static Result<ArrayInterface<Generic>*> ArrayFactory_NewBaseArray(const DataType& elementType, const Generic* src, Bool move) { return C::NewBaseArray(elementType, src, move); }
		static Result<ArrayInterface<Generic>*> ArrayFactory_NewBaseArrayFromContainerType(const ContainerDataType<>& containerType, const Generic* src, Bool move) { return C::NewBaseArrayFromContainerType(containerType, src, move); }
		static Result<ArrayInterface<Generic>*> ArrayFactory_NewBlockArray(const DataType& elementType, const Generic* src, Bool move) { return C::NewBlockArray(elementType, src, move); }
		static Result<Array<Generic>> ArrayFactory_NewPagedArray(const DataType& elementType, const Generic* defaultValue, Bool useRefCountForDefault) { return C::NewPagedArray(elementType, defaultValue, useRefCountForDefault); }
		static Result<Array<Generic>> ArrayFactory_NewPagedArrayFromContainerType(const ContainerDataType<>& containerType, const Generic* defaultValue, Bool useRefCountForDefault) { return C::NewPagedArrayFromContainerType(containerType, defaultValue, useRefCountForDefault); }
		static Result<Array<Generic>> ArrayFactory_Slice(const Array<Generic>& base, Int start, Int end, Bool cycle, const Generic* defaultValue, Bool useRefCountForDefault) { return C::Slice(base, start, end, cycle, defaultValue, useRefCountForDefault); }
		static Result<Array<Generic>> ArrayFactory_NewSingleValueArray(const ConstDataPtr& value, Int count, const ContainerDataType<>& containerType) { return C::NewSingleValueArray(value, count, containerType); }
		static Result<Array<Generic>> ArrayFactory_ExtractMember(const Array<Generic>& base, Int offset, const ContainerDataType<>& containerType) { return C::ExtractMember(base, offset, containerType); }
		static Result<Array<Generic>> ArrayFactory_Reinterpret(const Array<Generic>& base, const ContainerDataType<>& containerType) { return C::Reinterpret(base, containerType); }
		static Result<Array<Generic>> ArrayFactory_PrivateNewPagedArrayFromBase(const Array<Generic>& base, const Generic* defaultValue, Bool useRefCountForDefault) { return C::PrivateNewPagedArrayFromBase(base, defaultValue, useRefCountForDefault); }
	};

};
MAXON_ATTRIBUTE_FORCE_INLINE auto ArrayFactory::NewBaseArray(const DataType& elementType, const Generic* src, Bool move) -> Result<ArrayInterface<Generic>*>
{
	return MTable::_instance.ArrayFactory_NewBaseArray(elementType, src, move);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ArrayFactory::NewBaseArrayFromContainerType(const ContainerDataType<>& containerType, const Generic* src, Bool move) -> Result<ArrayInterface<Generic>*>
{
	return MTable::_instance.ArrayFactory_NewBaseArrayFromContainerType(containerType, src, move);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ArrayFactory::NewBlockArray(const DataType& elementType, const Generic* src, Bool move) -> Result<ArrayInterface<Generic>*>
{
	return MTable::_instance.ArrayFactory_NewBlockArray(elementType, src, move);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ArrayFactory::NewPagedArray(const DataType& elementType, const Generic* defaultValue, Bool useRefCountForDefault) -> Result<Array<Generic>>
{
	return MTable::_instance.ArrayFactory_NewPagedArray(elementType, defaultValue, useRefCountForDefault);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ArrayFactory::NewPagedArrayFromContainerType(const ContainerDataType<>& containerType, const Generic* defaultValue, Bool useRefCountForDefault) -> Result<Array<Generic>>
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
MAXON_ATTRIBUTE_FORCE_INLINE auto ArrayFactory::PrivateNewPagedArrayFromBase(const Array<Generic>& base, const Generic* defaultValue, Bool useRefCountForDefault) -> Result<Array<Generic>>
{
	return MTable::_instance.ArrayFactory_PrivateNewPagedArrayFromBase(base, defaultValue, useRefCountForDefault);
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

