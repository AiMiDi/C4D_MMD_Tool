
#ifndef DOXYGEN

#if defined MAXON_COMPILER_GCC
	#pragma GCC diagnostic push
	#if MAXON_COMPILER_GCC >= 600
		#pragma GCC diagnostic ignored "-Wmisleading-indentation"
	#endif
#endif

#if 1

struct GenericSingletonContainerInterface::MTable
{
	MTable() { }
	template <typename C> explicit MTable(C*) { Init<typename maxon::SFINAEHelper<Hxx2, C>::type::template Wrapper<C>>(); }
	template <typename C> MTable(C*, maxon::Bool) { Init<C>(); }
	PRIVATE_MAXON_ALLOC_TYPENAME GenericContainerInterface::MTable super;
	const TupleDataType& (*_GenericSingletonContainerInterface_GetTupleType) (const GenericSingletonContainerInterface* this_);
	void (*_GenericSingletonContainerInterface_GetMemberPointers) (const GenericSingletonContainerInterface* this_, const Block<const Generic*>& pointers, const TupleDataType& members);
	const Generic* (*_GenericSingletonContainerInterface_GetMemberPointer) (const GenericSingletonContainerInterface* this_, const InternedId& name);
	const Generic* (*_GenericSingletonContainerInterface_GetAllMemberPointers) (const GenericSingletonContainerInterface* this_, const Block<const Generic*>& pointers, Bool skipPointersIfTupleLayout);
	const Generic& (*_GenericSingletonContainerInterface_Get) (const GenericSingletonContainerInterface* this_, Int index);
	template <typename IMPL> void Init()
	{
		super.template Init<IMPL>();
		_GenericSingletonContainerInterface_GetTupleType = &IMPL::_GenericSingletonContainerInterface_GetTupleType;
		_GenericSingletonContainerInterface_GetMemberPointers = &IMPL::_GenericSingletonContainerInterface_GetMemberPointers;
		_GenericSingletonContainerInterface_GetMemberPointer = &IMPL::_GenericSingletonContainerInterface_GetMemberPointer;
		_GenericSingletonContainerInterface_GetAllMemberPointers = &IMPL::_GenericSingletonContainerInterface_GetAllMemberPointers;
		_GenericSingletonContainerInterface_Get = &IMPL::_GenericSingletonContainerInterface_Get;
	}
};

struct GenericSingletonContainerInterface::Hxx2
{
	template <typename C> class Wrapper : public GenericContainerInterface::Hxx2::Wrapper<C>
	{
	public:
	static const TupleDataType& _GenericSingletonContainerInterface_GetTupleType(const GenericSingletonContainerInterface* this_) { return ((const C*) this_)->GetTupleType(); }
	static void _GenericSingletonContainerInterface_GetMemberPointers(const GenericSingletonContainerInterface* this_, const Block<const Generic*>& pointers, const TupleDataType& members) { return ((const C*) this_)->GetMemberPointers(pointers, members); }
	static const Generic* _GenericSingletonContainerInterface_GetMemberPointer(const GenericSingletonContainerInterface* this_, const InternedId& name) { return ((const C*) this_)->GetMemberPointer(name); }
	static const Generic* _GenericSingletonContainerInterface_GetAllMemberPointers(const GenericSingletonContainerInterface* this_, const Block<const Generic*>& pointers, Bool skipPointersIfTupleLayout) { return ((const C*) this_)->GetAllMemberPointers(pointers, skipPointersIfTupleLayout); }
	static const Generic& _GenericSingletonContainerInterface_Get(const GenericSingletonContainerInterface* this_, Int index) { return ((const C*) this_)->Get(index); }
	};

};
MAXON_ATTRIBUTE_FORCE_INLINE auto GenericSingletonContainerInterface::GetTupleType() const -> const TupleDataType&
{
	return ((GenericSingletonContainerInterface::MTable*) this->_vtable)->_GenericSingletonContainerInterface_GetTupleType(this);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto GenericSingletonContainerInterface::GetMemberPointers(const Block<const Generic*>& pointers, const TupleDataType& members) const -> void
{
	return ((GenericSingletonContainerInterface::MTable*) this->_vtable)->_GenericSingletonContainerInterface_GetMemberPointers(this, pointers, members);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto GenericSingletonContainerInterface::GetMemberPointer(const InternedId& name) const -> const Generic*
{
	return ((GenericSingletonContainerInterface::MTable*) this->_vtable)->_GenericSingletonContainerInterface_GetMemberPointer(this, name);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto GenericSingletonContainerInterface::GetAllMemberPointers(const Block<const Generic*>& pointers, Bool skipPointersIfTupleLayout) const -> const Generic*
{
	return ((GenericSingletonContainerInterface::MTable*) this->_vtable)->_GenericSingletonContainerInterface_GetAllMemberPointers(this, pointers, skipPointersIfTupleLayout);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto GenericSingletonContainerInterface::Get(Int index) const -> const Generic&
{
	return ((GenericSingletonContainerInterface::MTable*) this->_vtable)->_GenericSingletonContainerInterface_Get(this, index);
}

GenericSingletonContainerInterface::GenericSingletonContainerInterface(const MTable& vtable) : GenericContainerInterface(vtable.super) { }
template <typename S, typename T_> MAXON_ATTRIBUTE_FORCE_INLINE auto GenericSingletonContainerInterface::Hxx1::ConstReferenceFunctionsImpl<S, T_>::GetTupleType() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<const TupleDataType&>, const TupleDataType&>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<const TupleDataType&>, const TupleDataType&>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const GenericSingletonContainerInterface* o_ = (const GenericSingletonContainerInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = GenericSingletonContainerInterface::NullValuePtr(); if (!o_) return maxon::PrivateNullReturnValue<const TupleDataType&>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } 
	return (((GenericSingletonContainerInterface::MTable*) o_->_vtable)->_GenericSingletonContainerInterface_GetTupleType(o_));
}
template <typename S, typename T_> MAXON_ATTRIBUTE_FORCE_INLINE auto GenericSingletonContainerInterface::Hxx1::ConstReferenceFunctionsImpl<S, T_>::GetMemberPointers(const Block<const Generic*>& pointers, const TupleDataType& members) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const GenericSingletonContainerInterface* o_ = (const GenericSingletonContainerInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = GenericSingletonContainerInterface::NullValuePtr(); if (!o_) return maxon::PrivateLogNullptrError(); } 
	((GenericSingletonContainerInterface::MTable*) o_->_vtable)->_GenericSingletonContainerInterface_GetMemberPointers(o_, pointers, members);
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
template <typename S, typename T_> MAXON_ATTRIBUTE_FORCE_INLINE auto GenericSingletonContainerInterface::Hxx1::ReferenceFunctionsImpl<S, T_>::GetMemberPointers(const Block<Generic*>& pointers, const TupleDataType& members) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); GenericSingletonContainerInterface* o_ = (GenericSingletonContainerInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) return maxon::PrivateLogNullptrError(); 
	o_->GetMemberPointers(pointers, members);
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
template <typename S, typename T_> MAXON_ATTRIBUTE_FORCE_INLINE auto GenericSingletonContainerInterface::Hxx1::ConstReferenceFunctionsImpl<S, T_>::GetMemberPointer(const InternedId& name) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<const Generic*>, const Generic*>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<const Generic*>, const Generic*>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const GenericSingletonContainerInterface* o_ = (const GenericSingletonContainerInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = GenericSingletonContainerInterface::NullValuePtr(); if (!o_) return nullptr; } 
	return (((GenericSingletonContainerInterface::MTable*) o_->_vtable)->_GenericSingletonContainerInterface_GetMemberPointer(o_, name));
}
template <typename S, typename T_> MAXON_ATTRIBUTE_FORCE_INLINE auto GenericSingletonContainerInterface::Hxx1::ReferenceFunctionsImpl<S, T_>::GetMemberPointer(const InternedId& name) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Generic*>, Generic*>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Generic*>, Generic*>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); GenericSingletonContainerInterface* o_ = (GenericSingletonContainerInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) return nullptr; 
	return (o_->GetMemberPointer(name));
}
template <typename S, typename T_> MAXON_ATTRIBUTE_FORCE_INLINE auto GenericSingletonContainerInterface::Hxx1::ConstReferenceFunctionsImpl<S, T_>::GetAllMemberPointers(const Block<const Generic*>& pointers, Bool skipPointersIfTupleLayout) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<const Generic*>, const Generic*>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<const Generic*>, const Generic*>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const GenericSingletonContainerInterface* o_ = (const GenericSingletonContainerInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = GenericSingletonContainerInterface::NullValuePtr(); if (!o_) return nullptr; } 
	return (((GenericSingletonContainerInterface::MTable*) o_->_vtable)->_GenericSingletonContainerInterface_GetAllMemberPointers(o_, pointers, skipPointersIfTupleLayout));
}
template <typename S, typename T_> MAXON_ATTRIBUTE_FORCE_INLINE auto GenericSingletonContainerInterface::Hxx1::ConstReferenceFunctionsImpl<S, T_>::Get(Int index) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<const Generic&>, const Generic&>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<const Generic&>, const Generic&>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const GenericSingletonContainerInterface* o_ = (const GenericSingletonContainerInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = GenericSingletonContainerInterface::NullValuePtr(); if (!o_) return maxon::PrivateNullReturnValue<const Generic&>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } 
	return (((GenericSingletonContainerInterface::MTable*) o_->_vtable)->_GenericSingletonContainerInterface_Get(o_, index));
}
template <typename S, typename T_> template <typename ATTR> MAXON_ATTRIBUTE_FORCE_INLINE auto GenericSingletonContainerInterface::Hxx1::ConstReferenceFunctionsImpl<S, T_>::Get() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Opt<const typename ATTR::ValueType&>>, Opt<const typename ATTR::ValueType&>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Opt<const typename ATTR::ValueType&>>, Opt<const typename ATTR::ValueType&>>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const GenericSingletonContainerInterface* o_ = (const GenericSingletonContainerInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = GenericSingletonContainerInterface::NullValuePtr(); if (!o_) return maxon::PrivateNullReturnValue<Opt<const typename ATTR::ValueType&>>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } 
	return (o_->Get<ATTR>());
}
#endif

#ifdef MAXON_COMPILER_GCC
	#pragma GCC diagnostic pop
#endif

#endif

