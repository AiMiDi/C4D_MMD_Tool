
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
	Result<void> (*_PersistentIdGeneratorInterface_InitializeBuffer) (const PersistentIdGeneratorInterface* this_, PersistentIdBuffer& buffer);
	void (*_PersistentIdGeneratorInterface_FreeBuffer) (const PersistentIdGeneratorInterface* this_, PersistentIdBuffer& buffer);
	Result<void> (*_PersistentIdGeneratorInterface_Move) (const PersistentIdGeneratorInterface* this_, Int index, PersistentIdBuffer& buffer);
	Result<void> (*_PersistentIdGeneratorInterface_Advance) (const PersistentIdGeneratorInterface* this_, Int index, PersistentIdBuffer& buffer);
	template <typename IMPL> auto GetFreeMethod(maxon::OverloadRank1) { return &IMPL::_PersistentIdGeneratorInterface_Free; }
	template <typename IMPL, typename = typename IMPL::Implementation::PrivateComponentWithBase> auto GetFreeMethod(maxon::OverloadRank2) { return reinterpret_cast<decltype(_PersistentIdGeneratorInterface_Free)>(&maxon::ObjectInterface::PrivateFreeInstance); }
	void (*_PersistentIdGeneratorInterface_Free) (const PersistentIdGeneratorInterface* object);
	const maxon::ClassInterface* _class;
	template <typename IMPL> void Init()
	{
		_PersistentIdGeneratorInterface_InitializeBuffer = &IMPL::_PersistentIdGeneratorInterface_InitializeBuffer;
		_PersistentIdGeneratorInterface_FreeBuffer = &IMPL::_PersistentIdGeneratorInterface_FreeBuffer;
		_PersistentIdGeneratorInterface_Move = &IMPL::_PersistentIdGeneratorInterface_Move;
		_PersistentIdGeneratorInterface_Advance = &IMPL::_PersistentIdGeneratorInterface_Advance;
		_PersistentIdGeneratorInterface_Free = GetFreeMethod<IMPL>(OVERLOAD_MAX_RANK);
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
		static Result<void> _PersistentIdGeneratorInterface_InitializeBuffer(const PersistentIdGeneratorInterface* this_, PersistentIdBuffer& buffer) { return C::Get(this_)->InitializeBuffer(buffer); }
		static void _PersistentIdGeneratorInterface_FreeBuffer(const PersistentIdGeneratorInterface* this_, PersistentIdBuffer& buffer) { return C::Get(this_)->FreeBuffer(buffer); }
		static Result<void> _PersistentIdGeneratorInterface_Move(const PersistentIdGeneratorInterface* this_, Int index, PersistentIdBuffer& buffer) { return C::Get(this_)->Move(index, buffer); }
		static Result<void> _PersistentIdGeneratorInterface_Advance(const PersistentIdGeneratorInterface* this_, Int index, PersistentIdBuffer& buffer) { return C::Get(this_)->Advance(index, buffer); }
		static void _PersistentIdGeneratorInterface_Free(const PersistentIdGeneratorInterface* object) { return C::Free(C::Get(object)); }
	};

};
MAXON_ATTRIBUTE_FORCE_INLINE auto PersistentIdGeneratorInterface::InitializeBuffer(PersistentIdBuffer& buffer) const -> Result<void>
{
	return ((PersistentIdGeneratorInterface::MTable*) (this->_vtableCls + 1))[-1]._PersistentIdGeneratorInterface_InitializeBuffer(this, buffer);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto PersistentIdGeneratorInterface::FreeBuffer(PersistentIdBuffer& buffer) const -> void
{
	return ((PersistentIdGeneratorInterface::MTable*) (this->_vtableCls + 1))[-1]._PersistentIdGeneratorInterface_FreeBuffer(this, buffer);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto PersistentIdGeneratorInterface::Move(Int index, PersistentIdBuffer& buffer) const -> Result<void>
{
	return ((PersistentIdGeneratorInterface::MTable*) (this->_vtableCls + 1))[-1]._PersistentIdGeneratorInterface_Move(this, index, buffer);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto PersistentIdGeneratorInterface::Advance(Int index, PersistentIdBuffer& buffer) const -> Result<void>
{
	return ((PersistentIdGeneratorInterface::MTable*) (this->_vtableCls + 1))[-1]._PersistentIdGeneratorInterface_Advance(this, index, buffer);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto PersistentIdGeneratorInterface::Free(const PersistentIdGeneratorInterface* object) -> void
{
	if (!object)
		return;
	return ((PersistentIdGeneratorInterface::MTable*) (object->_vtableCls + 1))[-1]._PersistentIdGeneratorInterface_Free(object);
}

PersistentIdGeneratorInterface::PersistentIdGeneratorInterface(const MTable& vtable) : _vtableCls(&vtable._class) { }
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto PersistentIdGeneratorInterface::Hxx1::ConstReferenceFunctionsImpl<S>::InitializeBuffer(PersistentIdBuffer& buffer) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const PersistentIdGeneratorInterface* o_ = (const PersistentIdGeneratorInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = PersistentIdGeneratorInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (((PersistentIdGeneratorInterface::MTable*) (o_->_vtableCls + 1))[-1]._PersistentIdGeneratorInterface_InitializeBuffer(o_, buffer));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto PersistentIdGeneratorInterface::Hxx1::ConstReferenceFunctionsImpl<S>::FreeBuffer(PersistentIdBuffer& buffer) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const PersistentIdGeneratorInterface* o_ = (const PersistentIdGeneratorInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = PersistentIdGeneratorInterface::NullValuePtr(); if (!o_) return maxon::PrivateLogNullptrError(); } 
	((PersistentIdGeneratorInterface::MTable*) (o_->_vtableCls + 1))[-1]._PersistentIdGeneratorInterface_FreeBuffer(o_, buffer);
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto PersistentIdGeneratorInterface::Hxx1::ConstReferenceFunctionsImpl<S>::Move(Int index, PersistentIdBuffer& buffer) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const PersistentIdGeneratorInterface* o_ = (const PersistentIdGeneratorInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = PersistentIdGeneratorInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (((PersistentIdGeneratorInterface::MTable*) (o_->_vtableCls + 1))[-1]._PersistentIdGeneratorInterface_Move(o_, index, buffer));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto PersistentIdGeneratorInterface::Hxx1::ConstReferenceFunctionsImpl<S>::Advance(Int index, PersistentIdBuffer& buffer) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const PersistentIdGeneratorInterface* o_ = (const PersistentIdGeneratorInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = PersistentIdGeneratorInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (((PersistentIdGeneratorInterface::MTable*) (o_->_vtableCls + 1))[-1]._PersistentIdGeneratorInterface_Advance(o_, index, buffer));
}

template <typename TYPE> struct StaticArrayInterface<TYPE>::MTable
{
	MTable() { }
	template <typename C> explicit MTable(C*) { Init<typename maxon::SFINAEHelper<Hxx2, C>::type::template Wrapper<C>>(); }
	template <typename C> MTable(C*, maxon::Bool) { Init<C>(); }
	Int (*_StaticArrayInterface_GetCount) (const StaticArrayInterface* this_);
	const TYPE& (*_StaticArrayInterface_operatorIndex) (const StaticArrayInterface* this_, Int index);
	ResultRef<TYPE> (*_StaticArrayInterface_GetWritable) (StaticArrayInterface* this_, Int index);
	Int (*_StaticArrayInterface_GetBlock) (const StaticArrayInterface* this_, Int index, SimdBlock<const TYPE>& block);
	Result<Int> (*_StaticArrayInterface_GetBlock_1) (StaticArrayInterface* this_, Int index, SimdBlock<NonConstValueType>& block);
	const DataType& (*_StaticArrayInterface_GetValueDataType) (const StaticArrayInterface* this_);
	const PersistentIdGenerator& (*_StaticArrayInterface_GetPersistentIdGenerator) (const StaticArrayInterface* this_);
	void* _MAXON_METHOD_RESERVE15;
	void* _MAXON_METHOD_RESERVE16;
	PRIVATE_MAXON_ALLOC_TYPENAME GenericContainerInterface::MTable super;
	template <typename IMPL> void Init()
	{
		_StaticArrayInterface_GetCount = &IMPL::_StaticArrayInterface_GetCount;
		_StaticArrayInterface_operatorIndex = &IMPL::_StaticArrayInterface_operatorIndex;
		_StaticArrayInterface_GetWritable = &IMPL::_StaticArrayInterface_GetWritable;
		_StaticArrayInterface_GetBlock = &IMPL::_StaticArrayInterface_GetBlock;
		_StaticArrayInterface_GetBlock_1 = &IMPL::_StaticArrayInterface_GetBlock_1;
		_StaticArrayInterface_GetValueDataType = &IMPL::_StaticArrayInterface_GetValueDataType;
		_StaticArrayInterface_GetPersistentIdGenerator = &IMPL::_StaticArrayInterface_GetPersistentIdGenerator;
		_MAXON_METHOD_RESERVE15 = nullptr;
		_MAXON_METHOD_RESERVE16 = nullptr;
		super.template Init<IMPL>();
	}
	template <typename W> static maxon::Bool InitWithBases(maxon::ClassInfo* info, maxon::Int offset) { return true; }
	template <typename S> using CombinedMTable = S;
};

template <typename TYPE> struct StaticArrayInterface<TYPE>::Hxx2
{
	template <typename C> using CWrapper = C;
	template <typename C> class Wrapper : public GenericContainerInterface::Hxx2::PRIVATE_MAXON_TEMPLATE_PREFIX Wrapper<C>
	{
	public:
		static Int _StaticArrayInterface_GetCount(const StaticArrayInterface* this_) { return C::Get(this_)->GetCount(); }
		static const TYPE& _StaticArrayInterface_operatorIndex(const StaticArrayInterface* this_, Int index) { return C::Get(this_)->operator [](index); }
		static ResultRef<TYPE> _StaticArrayInterface_GetWritable(StaticArrayInterface* this_, Int index) { return C::Get(this_)->GetWritable(index); }
		static Int _StaticArrayInterface_GetBlock(const StaticArrayInterface* this_, Int index, SimdBlock<const TYPE>& block) { return C::Get(this_)->GetBlock(index, block); }
		static Result<Int> _StaticArrayInterface_GetBlock_1(StaticArrayInterface* this_, Int index, SimdBlock<NonConstValueType>& block) { return C::Get(this_)->GetBlock(index, block); }
		static const DataType& _StaticArrayInterface_GetValueDataType(const StaticArrayInterface* this_) { return C::Get(this_)->GetValueDataType(); }
		static const PersistentIdGenerator& _StaticArrayInterface_GetPersistentIdGenerator(const StaticArrayInterface* this_) { return C::Get(this_)->GetPersistentIdGenerator(); }
	};

};
template <typename TYPE> MAXON_ATTRIBUTE_FORCE_INLINE auto StaticArrayInterface<TYPE>::GetCount() const -> Int
{
	return ((StaticArrayInterface::MTable*) (this->_vtableCls + 1))[-1]._StaticArrayInterface_GetCount(this);
}
template <typename TYPE> MAXON_ATTRIBUTE_FORCE_INLINE auto StaticArrayInterface<TYPE>::operator [](Int index) const -> const TYPE&
{
	return ((StaticArrayInterface::MTable*) (this->_vtableCls + 1))[-1]._StaticArrayInterface_operatorIndex(this, index);
}
template <typename TYPE> MAXON_ATTRIBUTE_FORCE_INLINE auto StaticArrayInterface<TYPE>::GetWritable(Int index) -> ResultRef<TYPE>
{
	return ((StaticArrayInterface::MTable*) (this->_vtableCls + 1))[-1]._StaticArrayInterface_GetWritable(this, index);
}
template <typename TYPE> MAXON_ATTRIBUTE_FORCE_INLINE auto StaticArrayInterface<TYPE>::GetBlock(Int index, SimdBlock<const TYPE>& block) const -> Int
{
	return ((StaticArrayInterface::MTable*) (this->_vtableCls + 1))[-1]._StaticArrayInterface_GetBlock(this, index, block);
}
template <typename TYPE> MAXON_ATTRIBUTE_FORCE_INLINE auto StaticArrayInterface<TYPE>::GetBlock(Int index, SimdBlock<NonConstValueType>& block) -> Result<Int>
{
	return ((StaticArrayInterface::MTable*) (this->_vtableCls + 1))[-1]._StaticArrayInterface_GetBlock_1(this, index, block);
}
template <typename TYPE> MAXON_ATTRIBUTE_FORCE_INLINE auto StaticArrayInterface<TYPE>::GetValueDataType() const -> const DataType&
{
	return ((StaticArrayInterface::MTable*) (this->_vtableCls + 1))[-1]._StaticArrayInterface_GetValueDataType(this);
}
template <typename TYPE> MAXON_ATTRIBUTE_FORCE_INLINE auto StaticArrayInterface<TYPE>::GetPersistentIdGenerator() const -> const PersistentIdGenerator&
{
	return ((StaticArrayInterface::MTable*) (this->_vtableCls + 1))[-1]._StaticArrayInterface_GetPersistentIdGenerator(this);
}

template <typename TYPE> StaticArrayInterface<TYPE>::StaticArrayInterface(const MTable& vtable) : GenericContainerInterface(vtable.super) { }
template <typename TYPE> template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto StaticArrayInterface<TYPE>::Hxx1::ConstReferenceFunctionsImpl<S>::GetCount() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const StaticArrayInterface* o_ = (const StaticArrayInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = StaticArrayInterface::NullValuePtr(); if (!o_) return 0; } 
	return (((StaticArrayInterface::MTable*) (o_->_vtableCls + 1))[-1]._StaticArrayInterface_GetCount(o_));
}
template <typename TYPE> template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto StaticArrayInterface<TYPE>::Hxx1::ConstReferenceFunctionsImpl<S>::IsEmpty() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const StaticArrayInterface* o_ = (const StaticArrayInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = StaticArrayInterface::NullValuePtr(); if (!o_) return true; } 
	return (o_->IsEmpty());
}
template <typename TYPE> template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto StaticArrayInterface<TYPE>::Hxx1::ConstReferenceFunctionsImpl<S>::IsPopulated() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const StaticArrayInterface* o_ = (const StaticArrayInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = StaticArrayInterface::NullValuePtr(); if (!o_) return maxon::PrivateLogNullptrError(false); } 
	return (o_->IsPopulated());
}
template <typename TYPE> template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto StaticArrayInterface<TYPE>::Hxx1::ConstReferenceFunctionsImpl<S>::operator [](Int index) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<const TYPE&>, const TYPE&>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<const TYPE&>, const TYPE&>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const StaticArrayInterface* o_ = (const StaticArrayInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = StaticArrayInterface::NullValuePtr(); if (!o_) return maxon::PrivateNullReturnValue<const TYPE&>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } 
	return (((StaticArrayInterface::MTable*) (o_->_vtableCls + 1))[-1]._StaticArrayInterface_operatorIndex(o_, index));
}
template <typename TYPE> template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto StaticArrayInterface<TYPE>::Hxx1::ReferenceFunctionsImpl<S>::GetWritable(Int index) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<TYPE&>, ResultRef<TYPE>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<TYPE&>, ResultRef<TYPE>>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); StaticArrayInterface* o_ = (StaticArrayInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateNullReturnValue<ResultRef<TYPE>>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } 
	return (((StaticArrayInterface::MTable*) (o_->_vtableCls + 1))[-1]._StaticArrayInterface_GetWritable(o_, index));
}
template <typename TYPE> template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto StaticArrayInterface<TYPE>::Hxx1::COWReferenceFunctionsImpl<S>::GetWritable(Int index) -> typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), ResultRef<TYPE>, maxon::Result<TYPE&>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), ResultRef<TYPE>, maxon::Result<TYPE&>>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); StaticArrayInterface* o_ = (StaticArrayInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } 
	return (((StaticArrayInterface::MTable*) (o_->_vtableCls + 1))[-1]._StaticArrayInterface_GetWritable(o_, index));
}
template <typename TYPE> template <typename S> template <typename A> MAXON_ATTRIBUTE_FORCE_INLINE auto StaticArrayInterface<TYPE>::Hxx1::ReferenceFunctionsImpl<S>::Set(Int index, A&& value) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<void>, ResultMem>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<void>, ResultMem>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); StaticArrayInterface* o_ = (StaticArrayInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateNullReturnValue<ResultMem>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } 
	return (o_->Set<A>(index, std::forward<A>(value)));
}
template <typename TYPE> template <typename S> template <typename A> MAXON_ATTRIBUTE_FORCE_INLINE auto StaticArrayInterface<TYPE>::Hxx1::COWReferenceFunctionsImpl<S>::Set(Int index, A&& value) -> typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), ResultMem, maxon::Result<void>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), ResultMem, maxon::Result<void>>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); StaticArrayInterface* o_ = (StaticArrayInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } 
	return (o_->Set<A>(index, std::forward<A>(value)));
}
template <typename TYPE> template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto StaticArrayInterface<TYPE>::Hxx1::ConstReferenceFunctionsImpl<S>::GetBlock(Int index, SimdBlock<const TYPE>& block) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const StaticArrayInterface* o_ = (const StaticArrayInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = StaticArrayInterface::NullValuePtr(); if (!o_) return 0; } 
	return (((StaticArrayInterface::MTable*) (o_->_vtableCls + 1))[-1]._StaticArrayInterface_GetBlock(o_, index, block));
}
template <typename TYPE> template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto StaticArrayInterface<TYPE>::Hxx1::ReferenceFunctionsImpl<S>::GetBlock(Int index, SimdBlock<NonConstValueType>& block) const -> Result<Int>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<Int>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); StaticArrayInterface* o_ = (StaticArrayInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (((StaticArrayInterface::MTable*) (o_->_vtableCls + 1))[-1]._StaticArrayInterface_GetBlock_1(o_, index, block));
}
template <typename TYPE> template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto StaticArrayInterface<TYPE>::Hxx1::COWReferenceFunctionsImpl<S>::GetWritableBlock(Int index, SimdBlock<NonConstValueType>& block) -> Result<Int>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<Int>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); StaticArrayInterface* o_ = (StaticArrayInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } 
	return (((StaticArrayInterface::MTable*) (o_->_vtableCls + 1))[-1]._StaticArrayInterface_GetBlock_1(o_, index, block));
}
template <typename TYPE> template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto StaticArrayInterface<TYPE>::Hxx1::ConstReferenceFunctionsImpl<S>::GetValueDataType() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<const DataType&>, const DataType&>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<const DataType&>, const DataType&>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const StaticArrayInterface* o_ = (const StaticArrayInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = StaticArrayInterface::NullValuePtr(); if (!o_) return maxon::PrivateNullReturnValue<const DataType&>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } 
	return (((StaticArrayInterface::MTable*) (o_->_vtableCls + 1))[-1]._StaticArrayInterface_GetValueDataType(o_));
}
template <typename TYPE> template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto StaticArrayInterface<TYPE>::Hxx1::ConstReferenceFunctionsImpl<S>::GetPersistentIdGenerator() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<const PersistentIdGenerator&>, const PersistentIdGenerator&>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<const PersistentIdGenerator&>, const PersistentIdGenerator&>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const StaticArrayInterface* o_ = (const StaticArrayInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = StaticArrayInterface::NullValuePtr(); if (!o_) return maxon::PrivateNullReturnValue<const PersistentIdGenerator&>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } 
	return (((StaticArrayInterface::MTable*) (o_->_vtableCls + 1))[-1]._StaticArrayInterface_GetPersistentIdGenerator(o_));
}
template <typename TYPE> template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto StaticArrayInterface<TYPE>::Hxx1::ConstReferenceFunctionsImpl<S>::Begin() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<typename StaticArrayInterface<TYPE>::ConstIterator>, typename StaticArrayInterface<TYPE>::ConstIterator>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<typename StaticArrayInterface<TYPE>::ConstIterator>, typename StaticArrayInterface<TYPE>::ConstIterator>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const StaticArrayInterface* o_ = (const StaticArrayInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = StaticArrayInterface::NullValuePtr(); if (!o_) return maxon::PrivateNullReturnValue<typename StaticArrayInterface<TYPE>::ConstIterator>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } 
	return (o_->Begin());
}
template <typename TYPE> template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto StaticArrayInterface<TYPE>::Hxx1::ConstReferenceFunctionsImpl<S>::End() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<typename StaticArrayInterface<TYPE>::ConstIterator>, typename StaticArrayInterface<TYPE>::ConstIterator>::type
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
	Int (*_ArrayInterface_GetBlock) (const ArrayInterface* this_, Int index, Block<const TYPE>& block);
	void* _MAXON_METHOD_RESERVE11;
	Result<void> (*_ArrayInterface_PrivateInsert) (ArrayInterface* this_, Int index, const StridedBlock<const TYPE>& values, Bool move);
	ResultMem (*_ArrayInterface_Resize) (ArrayInterface* this_, Int count, COLLECTION_RESIZE_FLAGS resizeFlags);
	ResultMem (*_ArrayInterface_SetCapacityHint) (ArrayInterface* this_, Int requestedCapacity, COLLECTION_RESIZE_FLAGS resizeFlags);
	ResultRef<TYPE> (*_ArrayInterface_Insert) (ArrayInterface* this_, Int index);
	ResultMem (*_ArrayInterface_Insert_1) (ArrayInterface* this_, Int index, const Block<const TYPE>& values);
	ResultMem (*_ArrayInterface_Insert_2) (ArrayInterface* this_, Int index, const MoveBlock<TYPE>& values);
	ResultRef<TYPE> (*_ArrayInterface_Append) (ArrayInterface* this_);
	ResultMem (*_ArrayInterface_Erase) (ArrayInterface* this_, Int index, Int count);
	ResultMem (*_ArrayInterface_SwapErase) (ArrayInterface* this_, Int index, Int count);
	void (*_ArrayInterface_Reset) (ArrayInterface* this_);
	void (*_ArrayInterface_Flush) (ArrayInterface* this_);
	Result<void> (*_ArrayInterface_CopyFrom) (ArrayInterface* this_, const ArrayInterface& other);
	void (*_ArrayInterface_SetPersistentIdGenerator) (ArrayInterface* this_, const PersistentIdGenerator& generator);
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
	PRIVATE_MAXON_ALLOC_TYPENAME ArrayBase0<ArrayInterface<TYPE>, TYPE, StaticArrayInterface<TYPE>, DefaultCompare>::MTable super;
	template <typename IMPL> void Init()
	{
		_ArrayInterface_GetBlock = &IMPL::_ArrayInterface_GetBlock;
		_MAXON_METHOD_RESERVE11 = nullptr;
		_ArrayInterface_PrivateInsert = &IMPL::_ArrayInterface_PrivateInsert;
		_ArrayInterface_Resize = &IMPL::_ArrayInterface_Resize;
		_ArrayInterface_SetCapacityHint = &IMPL::_ArrayInterface_SetCapacityHint;
		_ArrayInterface_Insert = &IMPL::_ArrayInterface_Insert;
		_ArrayInterface_Insert_1 = &IMPL::_ArrayInterface_Insert_1;
		_ArrayInterface_Insert_2 = &IMPL::_ArrayInterface_Insert_2;
		_ArrayInterface_Append = &IMPL::_ArrayInterface_Append;
		_ArrayInterface_Erase = &IMPL::_ArrayInterface_Erase;
		_ArrayInterface_SwapErase = &IMPL::_ArrayInterface_SwapErase;
		_ArrayInterface_Reset = &IMPL::_ArrayInterface_Reset;
		_ArrayInterface_Flush = &IMPL::_ArrayInterface_Flush;
		_ArrayInterface_CopyFrom = &IMPL::_ArrayInterface_CopyFrom;
		_ArrayInterface_SetPersistentIdGenerator = &IMPL::_ArrayInterface_SetPersistentIdGenerator;
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
		static Int _ArrayInterface_GetBlock(const ArrayInterface* this_, Int index, Block<const TYPE>& block) { return C::Get(this_)->GetBlock(index, block); }
		static Result<void> _ArrayInterface_PrivateInsert(ArrayInterface* this_, Int index, const StridedBlock<const TYPE>& values, Bool move) { return C::Get(this_)->PrivateInsert(index, values, move); }
		static ResultMem _ArrayInterface_Resize(ArrayInterface* this_, Int count, COLLECTION_RESIZE_FLAGS resizeFlags) { return C::Get(this_)->Resize(count, resizeFlags); }
		static ResultMem _ArrayInterface_SetCapacityHint(ArrayInterface* this_, Int requestedCapacity, COLLECTION_RESIZE_FLAGS resizeFlags) { return C::Get(this_)->SetCapacityHint(requestedCapacity, resizeFlags); }
		static ResultRef<TYPE> _ArrayInterface_Insert(ArrayInterface* this_, Int index) { return C::Get(this_)->Insert(index); }
		static ResultMem _ArrayInterface_Insert_1(ArrayInterface* this_, Int index, const Block<const TYPE>& values) { return C::Get(this_)->Insert(index, values); }
		static ResultMem _ArrayInterface_Insert_2(ArrayInterface* this_, Int index, const MoveBlock<TYPE>& values) { return C::Get(this_)->Insert(index, values); }
		static ResultRef<TYPE> _ArrayInterface_Append(ArrayInterface* this_) { return C::Get(this_)->Append(); }
		static ResultMem _ArrayInterface_Erase(ArrayInterface* this_, Int index, Int count) { return C::Get(this_)->Erase(index, count); }
		static ResultMem _ArrayInterface_SwapErase(ArrayInterface* this_, Int index, Int count) { return C::Get(this_)->SwapErase(index, count); }
		static void _ArrayInterface_Reset(ArrayInterface* this_) { return C::Get(this_)->Reset(); }
		static void _ArrayInterface_Flush(ArrayInterface* this_) { return C::Get(this_)->Flush(); }
		static Result<void> _ArrayInterface_CopyFrom(ArrayInterface* this_, const ArrayInterface& other) { return C::Get(this_)->CopyFrom(other); }
		static void _ArrayInterface_SetPersistentIdGenerator(ArrayInterface* this_, const PersistentIdGenerator& generator) { return C::Get(this_)->SetPersistentIdGenerator(generator); }
		static Int _ArrayInterface_GetMemorySize(const ArrayInterface* this_) { return C::Get(this_)->GetMemorySize(); }
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
	return ((ArrayInterface::MTable*) (this->_vtableCls + 1))[-1]._ArrayInterface_GetBlock(this, index, block);
}
template <typename TYPE> MAXON_ATTRIBUTE_FORCE_INLINE auto ArrayInterface<TYPE>::PrivateInsert(Int index, const StridedBlock<const TYPE>& values, Bool move) -> Result<void>
{
	return ((ArrayInterface::MTable*) (this->_vtableCls + 1))[-1]._ArrayInterface_PrivateInsert(this, index, values, move);
}
template <typename TYPE> MAXON_ATTRIBUTE_FORCE_INLINE auto ArrayInterface<TYPE>::Resize(Int count, COLLECTION_RESIZE_FLAGS resizeFlags) -> ResultMem
{
	return ((ArrayInterface::MTable*) (this->_vtableCls + 1))[-1]._ArrayInterface_Resize(this, count, resizeFlags);
}
template <typename TYPE> MAXON_ATTRIBUTE_FORCE_INLINE auto ArrayInterface<TYPE>::SetCapacityHint(Int requestedCapacity, COLLECTION_RESIZE_FLAGS resizeFlags) -> ResultMem
{
	return ((ArrayInterface::MTable*) (this->_vtableCls + 1))[-1]._ArrayInterface_SetCapacityHint(this, requestedCapacity, resizeFlags);
}
template <typename TYPE> MAXON_ATTRIBUTE_FORCE_INLINE auto ArrayInterface<TYPE>::Insert(Int index) -> ResultRef<TYPE>
{
	return ((ArrayInterface::MTable*) (this->_vtableCls + 1))[-1]._ArrayInterface_Insert(this, index);
}
template <typename TYPE> MAXON_ATTRIBUTE_FORCE_INLINE auto ArrayInterface<TYPE>::Insert(Int index, const Block<const TYPE>& values) -> ResultMem
{
	return ((ArrayInterface::MTable*) (this->_vtableCls + 1))[-1]._ArrayInterface_Insert_1(this, index, values);
}
template <typename TYPE> MAXON_ATTRIBUTE_FORCE_INLINE auto ArrayInterface<TYPE>::Insert(Int index, const MoveBlock<TYPE>& values) -> ResultMem
{
	return ((ArrayInterface::MTable*) (this->_vtableCls + 1))[-1]._ArrayInterface_Insert_2(this, index, values);
}
template <typename TYPE> MAXON_ATTRIBUTE_FORCE_INLINE auto ArrayInterface<TYPE>::Append() -> ResultRef<TYPE>
{
	return ((ArrayInterface::MTable*) (this->_vtableCls + 1))[-1]._ArrayInterface_Append(this);
}
template <typename TYPE> MAXON_ATTRIBUTE_FORCE_INLINE auto ArrayInterface<TYPE>::Erase(Int index, Int count) -> ResultMem
{
	return ((ArrayInterface::MTable*) (this->_vtableCls + 1))[-1]._ArrayInterface_Erase(this, index, count);
}
template <typename TYPE> MAXON_ATTRIBUTE_FORCE_INLINE auto ArrayInterface<TYPE>::SwapErase(Int index, Int count) -> ResultMem
{
	return ((ArrayInterface::MTable*) (this->_vtableCls + 1))[-1]._ArrayInterface_SwapErase(this, index, count);
}
template <typename TYPE> MAXON_ATTRIBUTE_FORCE_INLINE auto ArrayInterface<TYPE>::Reset() -> void
{
	return ((ArrayInterface::MTable*) (this->_vtableCls + 1))[-1]._ArrayInterface_Reset(this);
}
template <typename TYPE> MAXON_ATTRIBUTE_FORCE_INLINE auto ArrayInterface<TYPE>::Flush() -> void
{
	return ((ArrayInterface::MTable*) (this->_vtableCls + 1))[-1]._ArrayInterface_Flush(this);
}
template <typename TYPE> MAXON_ATTRIBUTE_FORCE_INLINE auto ArrayInterface<TYPE>::CopyFrom(const ArrayInterface& other) -> Result<void>
{
	return ((ArrayInterface::MTable*) (this->_vtableCls + 1))[-1]._ArrayInterface_CopyFrom(this, other);
}
template <typename TYPE> MAXON_ATTRIBUTE_FORCE_INLINE auto ArrayInterface<TYPE>::SetPersistentIdGenerator(const PersistentIdGenerator& generator) -> void
{
	return ((ArrayInterface::MTable*) (this->_vtableCls + 1))[-1]._ArrayInterface_SetPersistentIdGenerator(this, generator);
}
template <typename TYPE> MAXON_ATTRIBUTE_FORCE_INLINE auto ArrayInterface<TYPE>::GetMemorySize() const -> Int
{
	return ((ArrayInterface::MTable*) (this->_vtableCls + 1))[-1]._ArrayInterface_GetMemorySize(this);
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
template <typename TYPE> template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ArrayInterface<TYPE>::Hxx1::ConstReferenceFunctionsImpl<S>::GetBlock(Int index, Block<const TYPE>& block) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const ArrayInterface* o_ = (const ArrayInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = ArrayInterface::NullValuePtr(); if (!o_) return 0; } 
	return (((ArrayInterface::MTable*) (o_->_vtableCls + 1))[-1]._ArrayInterface_GetBlock(o_, index, block));
}
template <typename TYPE> template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ArrayInterface<TYPE>::Hxx1::ReferenceFunctionsImpl<S>::Resize(Int count, COLLECTION_RESIZE_FLAGS resizeFlags) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<void>, ResultMem>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<void>, ResultMem>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); ArrayInterface* o_ = (ArrayInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateNullReturnValue<ResultMem>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } 
	return (((ArrayInterface::MTable*) (o_->_vtableCls + 1))[-1]._ArrayInterface_Resize(o_, count, resizeFlags));
}
template <typename TYPE> template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ArrayInterface<TYPE>::Hxx1::COWReferenceFunctionsImpl<S>::Resize(Int count, COLLECTION_RESIZE_FLAGS resizeFlags) -> typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), ResultMem, maxon::Result<void>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), ResultMem, maxon::Result<void>>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); ArrayInterface* o_ = (ArrayInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } 
	return (((ArrayInterface::MTable*) (o_->_vtableCls + 1))[-1]._ArrayInterface_Resize(o_, count, resizeFlags));
}
template <typename TYPE> template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ArrayInterface<TYPE>::Hxx1::ReferenceFunctionsImpl<S>::SetCapacityHint(Int requestedCapacity, COLLECTION_RESIZE_FLAGS resizeFlags) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<void>, ResultMem>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<void>, ResultMem>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); ArrayInterface* o_ = (ArrayInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateNullReturnValue<ResultMem>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } 
	return (((ArrayInterface::MTable*) (o_->_vtableCls + 1))[-1]._ArrayInterface_SetCapacityHint(o_, requestedCapacity, resizeFlags));
}
template <typename TYPE> template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ArrayInterface<TYPE>::Hxx1::COWReferenceFunctionsImpl<S>::SetCapacityHint(Int requestedCapacity, COLLECTION_RESIZE_FLAGS resizeFlags) -> typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), ResultMem, maxon::Result<void>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), ResultMem, maxon::Result<void>>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); ArrayInterface* o_ = (ArrayInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } 
	return (((ArrayInterface::MTable*) (o_->_vtableCls + 1))[-1]._ArrayInterface_SetCapacityHint(o_, requestedCapacity, resizeFlags));
}
template <typename TYPE> template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ArrayInterface<TYPE>::Hxx1::ReferenceFunctionsImpl<S>::Insert(Int index) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<TYPE&>, ResultRef<TYPE>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<TYPE&>, ResultRef<TYPE>>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); ArrayInterface* o_ = (ArrayInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateNullReturnValue<ResultRef<TYPE>>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } 
	return (((ArrayInterface::MTable*) (o_->_vtableCls + 1))[-1]._ArrayInterface_Insert(o_, index));
}
template <typename TYPE> template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ArrayInterface<TYPE>::Hxx1::COWReferenceFunctionsImpl<S>::Insert(Int index) -> typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), ResultRef<TYPE>, maxon::Result<TYPE&>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), ResultRef<TYPE>, maxon::Result<TYPE&>>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); ArrayInterface* o_ = (ArrayInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } 
	return (((ArrayInterface::MTable*) (o_->_vtableCls + 1))[-1]._ArrayInterface_Insert(o_, index));
}
template <typename TYPE> template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ArrayInterface<TYPE>::Hxx1::ReferenceFunctionsImpl<S>::Insert(Int index, const TYPE& value) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<TYPE&>, ResultRef<TYPE>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<TYPE&>, ResultRef<TYPE>>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); ArrayInterface* o_ = (ArrayInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateNullReturnValue<ResultRef<TYPE>>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } 
	return (o_->Insert(index, value));
}
template <typename TYPE> template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ArrayInterface<TYPE>::Hxx1::COWReferenceFunctionsImpl<S>::Insert(Int index, const TYPE& value) -> typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), ResultRef<TYPE>, maxon::Result<TYPE&>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), ResultRef<TYPE>, maxon::Result<TYPE&>>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); ArrayInterface* o_ = (ArrayInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } 
	return (o_->Insert(index, value));
}
template <typename TYPE> template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ArrayInterface<TYPE>::Hxx1::ReferenceFunctionsImpl<S>::Insert(Int index, TYPE&& value) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<TYPE&>, ResultRef<TYPE>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<TYPE&>, ResultRef<TYPE>>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); ArrayInterface* o_ = (ArrayInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateNullReturnValue<ResultRef<TYPE>>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } 
	return (o_->Insert(index, std::forward<TYPE>(value)));
}
template <typename TYPE> template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ArrayInterface<TYPE>::Hxx1::COWReferenceFunctionsImpl<S>::Insert(Int index, TYPE&& value) -> typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), ResultRef<TYPE>, maxon::Result<TYPE&>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), ResultRef<TYPE>, maxon::Result<TYPE&>>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); ArrayInterface* o_ = (ArrayInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } 
	return (o_->Insert(index, std::forward<TYPE>(value)));
}
template <typename TYPE> template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ArrayInterface<TYPE>::Hxx1::ReferenceFunctionsImpl<S>::Insert(Int index, const Block<const TYPE>& values) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<void>, ResultMem>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<void>, ResultMem>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); ArrayInterface* o_ = (ArrayInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateNullReturnValue<ResultMem>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } 
	return (((ArrayInterface::MTable*) (o_->_vtableCls + 1))[-1]._ArrayInterface_Insert_1(o_, index, values));
}
template <typename TYPE> template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ArrayInterface<TYPE>::Hxx1::COWReferenceFunctionsImpl<S>::Insert(Int index, const Block<const TYPE>& values) -> typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), ResultMem, maxon::Result<void>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), ResultMem, maxon::Result<void>>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); ArrayInterface* o_ = (ArrayInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } 
	return (((ArrayInterface::MTable*) (o_->_vtableCls + 1))[-1]._ArrayInterface_Insert_1(o_, index, values));
}
template <typename TYPE> template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ArrayInterface<TYPE>::Hxx1::ReferenceFunctionsImpl<S>::Insert(Int index, const MoveBlock<TYPE>& values) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<void>, ResultMem>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<void>, ResultMem>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); ArrayInterface* o_ = (ArrayInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateNullReturnValue<ResultMem>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } 
	return (((ArrayInterface::MTable*) (o_->_vtableCls + 1))[-1]._ArrayInterface_Insert_2(o_, index, values));
}
template <typename TYPE> template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ArrayInterface<TYPE>::Hxx1::COWReferenceFunctionsImpl<S>::Insert(Int index, const MoveBlock<TYPE>& values) -> typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), ResultMem, maxon::Result<void>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), ResultMem, maxon::Result<void>>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); ArrayInterface* o_ = (ArrayInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } 
	return (((ArrayInterface::MTable*) (o_->_vtableCls + 1))[-1]._ArrayInterface_Insert_2(o_, index, values));
}
template <typename TYPE> template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ArrayInterface<TYPE>::Hxx1::ReferenceFunctionsImpl<S>::Append() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<TYPE&>, ResultRef<TYPE>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<TYPE&>, ResultRef<TYPE>>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); ArrayInterface* o_ = (ArrayInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateNullReturnValue<ResultRef<TYPE>>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } 
	return (((ArrayInterface::MTable*) (o_->_vtableCls + 1))[-1]._ArrayInterface_Append(o_));
}
template <typename TYPE> template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ArrayInterface<TYPE>::Hxx1::COWReferenceFunctionsImpl<S>::Append() -> typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), ResultRef<TYPE>, maxon::Result<TYPE&>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), ResultRef<TYPE>, maxon::Result<TYPE&>>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); ArrayInterface* o_ = (ArrayInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } 
	return (((ArrayInterface::MTable*) (o_->_vtableCls + 1))[-1]._ArrayInterface_Append(o_));
}
template <typename TYPE> template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ArrayInterface<TYPE>::Hxx1::ReferenceFunctionsImpl<S>::Append(const TYPE& value) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<TYPE&>, ResultRef<TYPE>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<TYPE&>, ResultRef<TYPE>>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); ArrayInterface* o_ = (ArrayInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateNullReturnValue<ResultRef<TYPE>>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } 
	return (o_->Append(value));
}
template <typename TYPE> template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ArrayInterface<TYPE>::Hxx1::COWReferenceFunctionsImpl<S>::Append(const TYPE& value) -> typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), ResultRef<TYPE>, maxon::Result<TYPE&>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), ResultRef<TYPE>, maxon::Result<TYPE&>>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); ArrayInterface* o_ = (ArrayInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } 
	return (o_->Append(value));
}
template <typename TYPE> template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ArrayInterface<TYPE>::Hxx1::ReferenceFunctionsImpl<S>::Append(TYPE&& value) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<TYPE&>, ResultRef<TYPE>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<TYPE&>, ResultRef<TYPE>>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); ArrayInterface* o_ = (ArrayInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateNullReturnValue<ResultRef<TYPE>>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } 
	return (o_->Append(std::forward<TYPE>(value)));
}
template <typename TYPE> template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ArrayInterface<TYPE>::Hxx1::COWReferenceFunctionsImpl<S>::Append(TYPE&& value) -> typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), ResultRef<TYPE>, maxon::Result<TYPE&>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), ResultRef<TYPE>, maxon::Result<TYPE&>>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); ArrayInterface* o_ = (ArrayInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } 
	return (o_->Append(std::forward<TYPE>(value)));
}
template <typename TYPE> template <typename S> template <typename A> MAXON_ATTRIBUTE_FORCE_INLINE auto ArrayInterface<TYPE>::Hxx1::ReferenceFunctionsImpl<S>::Append(A&& value) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<TYPE&>, ResultRef<TYPE>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<TYPE&>, ResultRef<TYPE>>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); ArrayInterface* o_ = (ArrayInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateNullReturnValue<ResultRef<TYPE>>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } 
	return (o_->Append<A>(std::forward<A>(value)));
}
template <typename TYPE> template <typename S> template <typename A> MAXON_ATTRIBUTE_FORCE_INLINE auto ArrayInterface<TYPE>::Hxx1::COWReferenceFunctionsImpl<S>::Append(A&& value) -> typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), ResultRef<TYPE>, maxon::Result<TYPE&>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), ResultRef<TYPE>, maxon::Result<TYPE&>>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); ArrayInterface* o_ = (ArrayInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } 
	return (o_->Append<A>(std::forward<A>(value)));
}
template <typename TYPE> template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ArrayInterface<TYPE>::Hxx1::ReferenceFunctionsImpl<S>::Pop() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); ArrayInterface* o_ = (ArrayInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateLogNullptrError(false); } 
	return (o_->Pop());
}
template <typename TYPE> template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ArrayInterface<TYPE>::Hxx1::COWReferenceFunctionsImpl<S>::Pop() -> typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), Bool, maxon::Result<Bool>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), Bool, maxon::Result<Bool>>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); ArrayInterface* o_ = (ArrayInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } 
	return (o_->Pop());
}
template <typename TYPE> template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ArrayInterface<TYPE>::Hxx1::ReferenceFunctionsImpl<S>::Pop(TYPE* dst) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); ArrayInterface* o_ = (ArrayInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateLogNullptrError(false); } 
	return (o_->Pop(dst));
}
template <typename TYPE> template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ArrayInterface<TYPE>::Hxx1::COWReferenceFunctionsImpl<S>::Pop(TYPE* dst) -> typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), Bool, maxon::Result<Bool>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), Bool, maxon::Result<Bool>>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); ArrayInterface* o_ = (ArrayInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } 
	return (o_->Pop(dst));
}
template <typename TYPE> template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ArrayInterface<TYPE>::Hxx1::ReferenceFunctionsImpl<S>::Erase(Int index, Int count) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<void>, ResultMem>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<void>, ResultMem>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); ArrayInterface* o_ = (ArrayInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateNullReturnValue<ResultMem>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } 
	return (((ArrayInterface::MTable*) (o_->_vtableCls + 1))[-1]._ArrayInterface_Erase(o_, index, count));
}
template <typename TYPE> template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ArrayInterface<TYPE>::Hxx1::COWReferenceFunctionsImpl<S>::Erase(Int index, Int count) -> typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), ResultMem, maxon::Result<void>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), ResultMem, maxon::Result<void>>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); ArrayInterface* o_ = (ArrayInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } 
	return (((ArrayInterface::MTable*) (o_->_vtableCls + 1))[-1]._ArrayInterface_Erase(o_, index, count));
}
template <typename TYPE> template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ArrayInterface<TYPE>::Hxx1::ReferenceFunctionsImpl<S>::SwapErase(Int index, Int count) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<void>, ResultMem>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<void>, ResultMem>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); ArrayInterface* o_ = (ArrayInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateNullReturnValue<ResultMem>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } 
	return (((ArrayInterface::MTable*) (o_->_vtableCls + 1))[-1]._ArrayInterface_SwapErase(o_, index, count));
}
template <typename TYPE> template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ArrayInterface<TYPE>::Hxx1::COWReferenceFunctionsImpl<S>::SwapErase(Int index, Int count) -> typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), ResultMem, maxon::Result<void>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), ResultMem, maxon::Result<void>>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); ArrayInterface* o_ = (ArrayInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } 
	return (((ArrayInterface::MTable*) (o_->_vtableCls + 1))[-1]._ArrayInterface_SwapErase(o_, index, count));
}
template <typename TYPE> template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ArrayInterface<TYPE>::Hxx1::ReferenceFunctionsImpl<S>::Reset() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); ArrayInterface* o_ = (ArrayInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { DebugStop(); return maxon::PrivateLogNullptrError(); } 
	((ArrayInterface::MTable*) (o_->_vtableCls + 1))[-1]._ArrayInterface_Reset(o_);
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
template <typename TYPE> template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ArrayInterface<TYPE>::Hxx1::COWReferenceFunctionsImpl<S>::Reset() -> typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), void, maxon::Result<void>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), void, maxon::Result<void>>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); ArrayInterface* o_ = (ArrayInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } 
	((ArrayInterface::MTable*) (o_->_vtableCls + 1))[-1]._ArrayInterface_Reset(o_);
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
template <typename TYPE> template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ArrayInterface<TYPE>::Hxx1::ReferenceFunctionsImpl<S>::Flush() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); ArrayInterface* o_ = (ArrayInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { DebugStop(); return maxon::PrivateLogNullptrError(); } 
	((ArrayInterface::MTable*) (o_->_vtableCls + 1))[-1]._ArrayInterface_Flush(o_);
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
template <typename TYPE> template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ArrayInterface<TYPE>::Hxx1::COWReferenceFunctionsImpl<S>::Flush() -> typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), void, maxon::Result<void>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), void, maxon::Result<void>>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); ArrayInterface* o_ = (ArrayInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } 
	((ArrayInterface::MTable*) (o_->_vtableCls + 1))[-1]._ArrayInterface_Flush(o_);
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
template <typename TYPE> template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ArrayInterface<TYPE>::Hxx1::ReferenceFunctionsImpl<S>::CopyFrom(const ArrayInterface& other) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); ArrayInterface* o_ = (ArrayInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (((ArrayInterface::MTable*) (o_->_vtableCls + 1))[-1]._ArrayInterface_CopyFrom(o_, other));
}
template <typename TYPE> template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ArrayInterface<TYPE>::Hxx1::COWReferenceFunctionsImpl<S>::CopyFrom(const ArrayInterface& other) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); ArrayInterface* o_ = (ArrayInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } 
	return (((ArrayInterface::MTable*) (o_->_vtableCls + 1))[-1]._ArrayInterface_CopyFrom(o_, other));
}
template <typename TYPE> template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ArrayInterface<TYPE>::Hxx1::ReferenceFunctionsImpl<S>::SetPersistentIdGenerator(const PersistentIdGenerator& generator) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); ArrayInterface* o_ = (ArrayInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { DebugStop(); return maxon::PrivateLogNullptrError(); } 
	((ArrayInterface::MTable*) (o_->_vtableCls + 1))[-1]._ArrayInterface_SetPersistentIdGenerator(o_, generator);
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
template <typename TYPE> template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ArrayInterface<TYPE>::Hxx1::COWReferenceFunctionsImpl<S>::SetPersistentIdGenerator(const PersistentIdGenerator& generator) -> typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), void, maxon::Result<void>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), void, maxon::Result<void>>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); ArrayInterface* o_ = (ArrayInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } 
	((ArrayInterface::MTable*) (o_->_vtableCls + 1))[-1]._ArrayInterface_SetPersistentIdGenerator(o_, generator);
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
template <typename TYPE> template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ArrayInterface<TYPE>::Hxx1::ConstReferenceFunctionsImpl<S>::GetMemorySize() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const ArrayInterface* o_ = (const ArrayInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = ArrayInterface::NullValuePtr(); if (!o_) return 0; } 
	return (((ArrayInterface::MTable*) (o_->_vtableCls + 1))[-1]._ArrayInterface_GetMemorySize(o_));
}
template <typename TYPE> template <typename S> template <typename DT> MAXON_ATTRIBUTE_FORCE_INLINE auto ArrayInterface<TYPE>::Hxx1::ConstReferenceFunctionsImpl<S>::HasType() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const ArrayInterface* o_ = (const ArrayInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = ArrayInterface::NullValuePtr(); if (!o_) return maxon::PrivateLogNullptrError(false); } 
	return (o_->HasType<DT>());
}
template <typename TYPE> template <typename S> template <typename DT> MAXON_ATTRIBUTE_FORCE_INLINE auto ArrayInterface<TYPE>::Hxx1::ConstReferenceFunctionsImpl<S>::AssertType() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const ArrayInterface* o_ = (const ArrayInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = ArrayInterface::NullValuePtr(); if (!o_) return maxon::PrivateLogNullptrError(); } 
	o_->AssertType<DT>();
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
#ifdef MAXON_COMPILER_INTEL
#endif
#ifdef MAXON_COMPILER_INTEL
#endif
template <typename TYPE> template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ArrayInterface<TYPE>::Hxx1::ConstReferenceFunctionsImpl<S>::Begin() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<typename ArrayInterface<TYPE>::ConstIterator>, typename ArrayInterface<TYPE>::ConstIterator>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<typename ArrayInterface<TYPE>::ConstIterator>, typename ArrayInterface<TYPE>::ConstIterator>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const ArrayInterface* o_ = (const ArrayInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = ArrayInterface::NullValuePtr(); if (!o_) return maxon::PrivateNullReturnValue<typename ArrayInterface<TYPE>::ConstIterator>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } 
	return (o_->Begin());
}
template <typename TYPE> template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ArrayInterface<TYPE>::Hxx1::ConstReferenceFunctionsImpl<S>::End() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<typename ArrayInterface<TYPE>::ConstIterator>, typename ArrayInterface<TYPE>::ConstIterator>::type
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
	Result<ArrayInterface<Generic>*> (*_ArrayFactory_NewBaseArray) (const DataType& type, const Generic* src, Bool move);
	Result<ArrayInterface<Generic>*> (*_ArrayFactory_NewBaseArrayFromContainerType) (const ContainerDataType<>& containerType, const Generic* src, Bool move);
	Result<ArrayInterface<Generic>*> (*_ArrayFactory_NewBlockArray) (const DataType& type, const Generic* src, Bool move);
	template <typename IMPL> void Init()
	{
		_ArrayFactory_NewBaseArray = &IMPL::_ArrayFactory_NewBaseArray;
		_ArrayFactory_NewBaseArrayFromContainerType = &IMPL::_ArrayFactory_NewBaseArrayFromContainerType;
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
		static Result<ArrayInterface<Generic>*> _ArrayFactory_NewBaseArrayFromContainerType(const ContainerDataType<>& containerType, const Generic* src, Bool move) { return C::NewBaseArrayFromContainerType(containerType, src, move); }
		static Result<ArrayInterface<Generic>*> _ArrayFactory_NewBlockArray(const DataType& type, const Generic* src, Bool move) { return C::NewBlockArray(type, src, move); }
	};

};
MAXON_ATTRIBUTE_FORCE_INLINE auto ArrayFactory::NewBaseArray(const DataType& type, const Generic* src, Bool move) -> Result<ArrayInterface<Generic>*>
{
	return MTable::_instance._ArrayFactory_NewBaseArray(type, src, move);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ArrayFactory::NewBaseArrayFromContainerType(const ContainerDataType<>& containerType, const Generic* src, Bool move) -> Result<ArrayInterface<Generic>*>
{
	return MTable::_instance._ArrayFactory_NewBaseArrayFromContainerType(containerType, src, move);
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

