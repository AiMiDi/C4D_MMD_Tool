
#ifndef DOXYGEN

#ifdef MAXON_COMPILER_GCC
	#pragma GCC diagnostic push
	#pragma GCC diagnostic ignored "-Wmisleading-indentation"
#endif

#if 1

struct DynamicTupleInterface::MTable
{
	MTable() { }
	template <typename C> explicit MTable(C*) { Init<Wrapper<C>>(this); }
	template <typename C> MTable(C*, maxon::Bool) { Init<C>(this); }
	void (*_DynamicTupleInterface_Free) (const DynamicTupleInterface* object);
	void (*_DynamicTupleInterface_GetMemberPointers) (const DynamicTupleInterface* this_, const Generic** pointers, const TupleDataType* members);
	const Generic* (*_DynamicTupleInterface_GetMemberPointer) (const DynamicTupleInterface* this_, InternedId name, const DataType* type);
	const TupleDataType* (*_DynamicTupleInterface_GetType) (const DynamicTupleInterface* this_);
	Int (*_DynamicTupleInterface_FindMemberIndex) (const DynamicTupleInterface* this_, InternedId name, const DataType* type);
	const Generic* (*_DynamicTupleInterface_GetAllMemberPointers) (const DynamicTupleInterface* this_, const Generic** pointers, Bool skipPointersIfTupleLayout);
	const Generic* (*_DynamicTupleInterface_GetMemberPointer_1) (const DynamicTupleInterface* this_, Int index);
	template <typename IMPL> static void Init(MTable* tbl)
	{
		tbl->_DynamicTupleInterface_Free = &IMPL::_DynamicTupleInterface_Free;
		tbl->_DynamicTupleInterface_GetMemberPointers = &IMPL::_DynamicTupleInterface_GetMemberPointers;
		tbl->_DynamicTupleInterface_GetMemberPointer = &IMPL::_DynamicTupleInterface_GetMemberPointer;
		tbl->_DynamicTupleInterface_GetType = &IMPL::_DynamicTupleInterface_GetType;
		tbl->_DynamicTupleInterface_FindMemberIndex = &IMPL::_DynamicTupleInterface_FindMemberIndex;
		tbl->_DynamicTupleInterface_GetAllMemberPointers = &IMPL::_DynamicTupleInterface_GetAllMemberPointers;
		tbl->_DynamicTupleInterface_GetMemberPointer_1 = &IMPL::_DynamicTupleInterface_GetMemberPointer_1;
	}
};

template <typename C> class DynamicTupleInterface::Wrapper
{
public:
	static void _DynamicTupleInterface_Free(const DynamicTupleInterface* object) { return C::Free((const C*) object); }
	static void _DynamicTupleInterface_GetMemberPointers(const DynamicTupleInterface* this_, const Generic** pointers, const TupleDataType* members) { return ((const C*) this_)->GetMemberPointers(pointers, members); }
	static const Generic* _DynamicTupleInterface_GetMemberPointer(const DynamicTupleInterface* this_, InternedId name, const DataType* type) { return ((const C*) this_)->GetMemberPointer(std::forward<InternedId>(name), type); }
	static const TupleDataType* _DynamicTupleInterface_GetType(const DynamicTupleInterface* this_) { return ((const C*) this_)->GetType(); }
	static Int _DynamicTupleInterface_FindMemberIndex(const DynamicTupleInterface* this_, InternedId name, const DataType* type) { return ((const C*) this_)->FindMemberIndex(std::forward<InternedId>(name), type); }
	static const Generic* _DynamicTupleInterface_GetAllMemberPointers(const DynamicTupleInterface* this_, const Generic** pointers, Bool skipPointersIfTupleLayout) { return ((const C*) this_)->GetAllMemberPointers(pointers, skipPointersIfTupleLayout); }
	static const Generic* _DynamicTupleInterface_GetMemberPointer_1(const DynamicTupleInterface* this_, Int index) { return ((const C*) this_)->GetMemberPointer(index); }
};

MAXON_ATTRIBUTE_FORCE_INLINE auto DynamicTupleInterface::Free(const DynamicTupleInterface* object) -> void
{
	if (!object)
		return;
	return ((MTable*) object->_vtable)->_DynamicTupleInterface_Free(object);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto DynamicTupleInterface::GetMemberPointers(const Generic** pointers, const TupleDataType* members) const -> void
{
	return ((MTable*) this->_vtable)->_DynamicTupleInterface_GetMemberPointers(this, pointers, members);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto DynamicTupleInterface::GetMemberPointer(InternedId name, const DataType* type) const -> const Generic*
{
	return ((MTable*) this->_vtable)->_DynamicTupleInterface_GetMemberPointer(this, std::forward<InternedId>(name), type);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto DynamicTupleInterface::GetType() const -> const TupleDataType*
{
	return ((MTable*) this->_vtable)->_DynamicTupleInterface_GetType(this);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto DynamicTupleInterface::FindMemberIndex(InternedId name, const DataType* type) const -> Int
{
	return ((MTable*) this->_vtable)->_DynamicTupleInterface_FindMemberIndex(this, std::forward<InternedId>(name), type);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto DynamicTupleInterface::GetAllMemberPointers(const Generic** pointers, Bool skipPointersIfTupleLayout) const -> const Generic*
{
	return ((MTable*) this->_vtable)->_DynamicTupleInterface_GetAllMemberPointers(this, pointers, skipPointersIfTupleLayout);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto DynamicTupleInterface::GetMemberPointer(Int index) const -> const Generic*
{
	return ((MTable*) this->_vtable)->_DynamicTupleInterface_GetMemberPointer_1(this, index);
}

template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto DynamicTupleInterface::ConstReferenceFunctionsImpl<S>::GetMemberPointers(const Generic** pointers, const TupleDataType* members) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, false, typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const DynamicTupleInterface* o_ = (const DynamicTupleInterface*) this->GetPointer(); if (!(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS) && MAXON_UNLIKELY(!o_)) { o_ = DynamicTupleInterface::NullValuePtr(); if (!o_) return maxon::PrivateLogNullptrError(); } 
	((MTable*) o_->_vtable)->_DynamicTupleInterface_GetMemberPointers(o_, pointers, members);
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto DynamicTupleInterface::ReferenceFunctionsImpl<S>::GetMemberPointers(Generic** pointers, const TupleDataType* members) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, false, typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); DynamicTupleInterface* o_ = (DynamicTupleInterface*) this->GetPointer(); if (MAXON_UNLIKELY(!o_)) return maxon::PrivateLogNullptrError(); 
	o_->GetMemberPointers(pointers, members);
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto DynamicTupleInterface::ConstReferenceFunctionsImpl<S>::GetMemberPointer(InternedId name, const DataType* type) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<const Generic*>, const Generic*>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, false, typename std::conditional<S::HAS_ERROR, maxon::Result<const Generic*>, const Generic*>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const DynamicTupleInterface* o_ = (const DynamicTupleInterface*) this->GetPointer(); if (!(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS) && MAXON_UNLIKELY(!o_)) { o_ = DynamicTupleInterface::NullValuePtr(); if (!o_) return nullptr; } 
	return (((MTable*) o_->_vtable)->_DynamicTupleInterface_GetMemberPointer(o_, std::forward<InternedId>(name), type));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto DynamicTupleInterface::ReferenceFunctionsImpl<S>::GetMemberPointer(InternedId name, const DataType* type) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Generic*>, Generic*>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, false, typename std::conditional<S::HAS_ERROR, maxon::Result<Generic*>, Generic*>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); DynamicTupleInterface* o_ = (DynamicTupleInterface*) this->GetPointer(); if (MAXON_UNLIKELY(!o_)) return nullptr; 
	return (o_->GetMemberPointer(std::forward<InternedId>(name), type));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto DynamicTupleInterface::ConstReferenceFunctionsImpl<S>::GetMemberPointer(const Member& member) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<const Generic*>, const Generic*>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, false, typename std::conditional<S::HAS_ERROR, maxon::Result<const Generic*>, const Generic*>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const DynamicTupleInterface* o_ = (const DynamicTupleInterface*) this->GetPointer(); if (!(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS) && MAXON_UNLIKELY(!o_)) { o_ = DynamicTupleInterface::NullValuePtr(); if (!o_) return nullptr; } 
	return (o_->GetMemberPointer(member));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto DynamicTupleInterface::ReferenceFunctionsImpl<S>::GetMemberPointer(const Member& member) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Generic*>, Generic*>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, false, typename std::conditional<S::HAS_ERROR, maxon::Result<Generic*>, Generic*>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); DynamicTupleInterface* o_ = (DynamicTupleInterface*) this->GetPointer(); if (MAXON_UNLIKELY(!o_)) return nullptr; 
	return (o_->GetMemberPointer(member));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto DynamicTupleInterface::ConstReferenceFunctionsImpl<S>::GetType() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<const TupleDataType*>, const TupleDataType*>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, false, typename std::conditional<S::HAS_ERROR, maxon::Result<const TupleDataType*>, const TupleDataType*>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const DynamicTupleInterface* o_ = (const DynamicTupleInterface*) this->GetPointer(); if (!(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS) && MAXON_UNLIKELY(!o_)) { o_ = DynamicTupleInterface::NullValuePtr(); if (!o_) return nullptr; } 
	return (((MTable*) o_->_vtable)->_DynamicTupleInterface_GetType(o_));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto DynamicTupleInterface::ConstReferenceFunctionsImpl<S>::FindMemberIndex(InternedId name, const DataType* type) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, false, typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const DynamicTupleInterface* o_ = (const DynamicTupleInterface*) this->GetPointer(); if (!(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS) && MAXON_UNLIKELY(!o_)) { o_ = DynamicTupleInterface::NullValuePtr(); if (!o_) return -1; } 
	return (((MTable*) o_->_vtable)->_DynamicTupleInterface_FindMemberIndex(o_, std::forward<InternedId>(name), type));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto DynamicTupleInterface::ConstReferenceFunctionsImpl<S>::FindMemberIndex(const Member& member) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, false, typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const DynamicTupleInterface* o_ = (const DynamicTupleInterface*) this->GetPointer(); if (!(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS) && MAXON_UNLIKELY(!o_)) { o_ = DynamicTupleInterface::NullValuePtr(); if (!o_) return 0; } 
	return (o_->FindMemberIndex(member));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto DynamicTupleInterface::ConstReferenceFunctionsImpl<S>::GetAllMemberPointers(const Generic** pointers, Bool skipPointersIfTupleLayout) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<const Generic*>, const Generic*>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, false, typename std::conditional<S::HAS_ERROR, maxon::Result<const Generic*>, const Generic*>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const DynamicTupleInterface* o_ = (const DynamicTupleInterface*) this->GetPointer(); if (!(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS) && MAXON_UNLIKELY(!o_)) { o_ = DynamicTupleInterface::NullValuePtr(); if (!o_) return nullptr; } 
	return (((MTable*) o_->_vtable)->_DynamicTupleInterface_GetAllMemberPointers(o_, pointers, skipPointersIfTupleLayout));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto DynamicTupleInterface::ConstReferenceFunctionsImpl<S>::GetMemberPointer(Int index) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<const Generic*>, const Generic*>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, false, typename std::conditional<S::HAS_ERROR, maxon::Result<const Generic*>, const Generic*>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const DynamicTupleInterface* o_ = (const DynamicTupleInterface*) this->GetPointer(); if (!(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS) && MAXON_UNLIKELY(!o_)) { o_ = DynamicTupleInterface::NullValuePtr(); if (!o_) return nullptr; } 
	return (((MTable*) o_->_vtable)->_DynamicTupleInterface_GetMemberPointer_1(o_, index));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto DynamicTupleInterface::ReferenceFunctionsImpl<S>::GetMemberPointer(Int index) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Generic*>, Generic*>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, false, typename std::conditional<S::HAS_ERROR, maxon::Result<Generic*>, Generic*>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); DynamicTupleInterface* o_ = (DynamicTupleInterface*) this->GetPointer(); if (MAXON_UNLIKELY(!o_)) return nullptr; 
	return (o_->GetMemberPointer(index));
}
template <typename S> template <typename MEMBER> MAXON_ATTRIBUTE_FORCE_INLINE auto DynamicTupleInterface::ConstReferenceFunctionsImpl<S>::Get() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Opt<const typename MEMBER::Type&>>, Opt<const typename MEMBER::Type&>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, false, typename std::conditional<S::HAS_ERROR, maxon::Result<Opt<const typename MEMBER::Type&>>, Opt<const typename MEMBER::Type&>>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const DynamicTupleInterface* o_ = (const DynamicTupleInterface*) this->GetPointer(); if (!(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS) && MAXON_UNLIKELY(!o_)) { o_ = DynamicTupleInterface::NullValuePtr(); if (!o_) return maxon::PrivateNullReturnValue<Opt<const typename MEMBER::Type&>>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } 
	return (o_->Get<MEMBER>());
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto DynamicTupleInterface::ConstReferenceFunctionsImpl<S>::Get(const Member& member) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<const Generic*>, const Generic*>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, false, typename std::conditional<S::HAS_ERROR, maxon::Result<const Generic*>, const Generic*>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const DynamicTupleInterface* o_ = (const DynamicTupleInterface*) this->GetPointer(); if (!(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS) && MAXON_UNLIKELY(!o_)) { o_ = DynamicTupleInterface::NullValuePtr(); if (!o_) return nullptr; } 
	return (o_->Get(member));
}
#endif

#ifdef MAXON_COMPILER_GCC
	#pragma GCC diagnostic pop
#endif

#endif

