
#ifndef DOXYGEN

#ifdef MAXON_COMPILER_GCC
	#pragma GCC diagnostic push
	#pragma GCC diagnostic ignored "-Wmisleading-indentation"
#endif

#if 1

struct ParametricTypeInterface::MTable
{
	MTable() { }
	template <typename C> explicit MTable(C*) { Init<Wrapper<C>>(this); }
	template <typename C> MTable(C*, maxon::Bool) { Init<C>(this); }
	void (*_ParametricTypeInterface_Free) (const ParametricTypeInterface* object);
	const Id& (*_ParametricTypeInterface_GetId) (const ParametricTypeInterface* this_);
	Result<const DataType*> (*_ParametricTypeInterface_Instantiate) (const ParametricTypeInterface* this_, const Block<const Member>& args, const Block<const Int64>& iargs);
	Bool (*_ParametricTypeInterface_IsBaseOfOrSame) (const ParametricTypeInterface* this_, const DataType* type, const DataType* other);
	Result<void> (*_ParametricTypeInterface_Convert) (const ParametricTypeInterface* this_, const DataPtr& dest, const ConstDataPtr& src, CONVERSION_FLAGS ignore);
	Result<Tuple<const DataType*, const Char*>> (*_ParametricTypeInterface_Parse) (const ParametricTypeInterface* this_, const Char* params);
	Result<const DataType*> (*_ParametricTypeInterface_Substitute) (const ParametricTypeInterface* this_, const DataType* orig, const Delegate<Result<const DataType*>(const DataType*)>& replace);
	template <typename IMPL> static void Init(MTable* tbl)
	{
		tbl->_ParametricTypeInterface_Free = &IMPL::_ParametricTypeInterface_Free;
		tbl->_ParametricTypeInterface_GetId = &IMPL::_ParametricTypeInterface_GetId;
		tbl->_ParametricTypeInterface_Instantiate = &IMPL::_ParametricTypeInterface_Instantiate;
		tbl->_ParametricTypeInterface_IsBaseOfOrSame = &IMPL::_ParametricTypeInterface_IsBaseOfOrSame;
		tbl->_ParametricTypeInterface_Convert = &IMPL::_ParametricTypeInterface_Convert;
		tbl->_ParametricTypeInterface_Parse = &IMPL::_ParametricTypeInterface_Parse;
		tbl->_ParametricTypeInterface_Substitute = &IMPL::_ParametricTypeInterface_Substitute;
	}
};

template <typename C> class ParametricTypeInterface::Wrapper
{
public:
	static void _ParametricTypeInterface_Free(const ParametricTypeInterface* object) { return C::Free((const C*) object); }
	static const Id& _ParametricTypeInterface_GetId(const ParametricTypeInterface* this_) { return ((const C*) this_)->GetId(); }
	static Result<const DataType*> _ParametricTypeInterface_Instantiate(const ParametricTypeInterface* this_, const Block<const Member>& args, const Block<const Int64>& iargs) { return ((const C*) this_)->Instantiate(args, iargs); }
	static Bool _ParametricTypeInterface_IsBaseOfOrSame(const ParametricTypeInterface* this_, const DataType* type, const DataType* other) { return ((const C*) this_)->IsBaseOfOrSame(type, other); }
	static Result<void> _ParametricTypeInterface_Convert(const ParametricTypeInterface* this_, const DataPtr& dest, const ConstDataPtr& src, CONVERSION_FLAGS ignore) { return ((const C*) this_)->Convert(dest, src, ignore); }
	static Result<Tuple<const DataType*, const Char*>> _ParametricTypeInterface_Parse(const ParametricTypeInterface* this_, const Char* params) { return ((const C*) this_)->Parse(params); }
	static Result<const DataType*> _ParametricTypeInterface_Substitute(const ParametricTypeInterface* this_, const DataType* orig, const Delegate<Result<const DataType*>(const DataType*)>& replace) { return ((const C*) this_)->Substitute(orig, replace); }
};

MAXON_ATTRIBUTE_FORCE_INLINE auto ParametricTypeInterface::Free(const ParametricTypeInterface* object) -> void
{
	if (!object)
		return;
	return ((MTable*) object->_vtable)->_ParametricTypeInterface_Free(object);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ParametricTypeInterface::GetId() const -> const Id&
{
	return ((MTable*) this->_vtable)->_ParametricTypeInterface_GetId(this);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ParametricTypeInterface::Instantiate(const Block<const Member>& args, const Block<const Int64>& iargs) const -> Result<const DataType*>
{
	return ((MTable*) this->_vtable)->_ParametricTypeInterface_Instantiate(this, args, iargs);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ParametricTypeInterface::IsBaseOfOrSame(const DataType* type, const DataType* other) const -> Bool
{
	return ((MTable*) this->_vtable)->_ParametricTypeInterface_IsBaseOfOrSame(this, type, other);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ParametricTypeInterface::Convert(const DataPtr& dest, const ConstDataPtr& src, CONVERSION_FLAGS ignore) const -> Result<void>
{
	return ((MTable*) this->_vtable)->_ParametricTypeInterface_Convert(this, dest, src, ignore);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ParametricTypeInterface::Parse(const Char* params) const -> Result<Tuple<const DataType*, const Char*>>
{
	return ((MTable*) this->_vtable)->_ParametricTypeInterface_Parse(this, params);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ParametricTypeInterface::Substitute(const DataType* orig, const Delegate<Result<const DataType*>(const DataType*)>& replace) const -> Result<const DataType*>
{
	return ((MTable*) this->_vtable)->_ParametricTypeInterface_Substitute(this, orig, replace);
}

template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ParametricTypeInterface::ConstReferenceFunctionsImpl<S>::GetId() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<const Id&>, const Id&>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, false, typename std::conditional<S::HAS_ERROR, maxon::Result<const Id&>, const Id&>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const ParametricTypeInterface* o_ = (const ParametricTypeInterface*) this->GetPointer(); if (!(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS) && MAXON_UNLIKELY(!o_)) { o_ = ParametricTypeInterface::NullValuePtr(); if (!o_) return maxon::PrivateIncompleteNullReturnValue<const Id&>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } 
	return (((MTable*) o_->_vtable)->_ParametricTypeInterface_GetId(o_));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ParametricTypeInterface::ConstReferenceFunctionsImpl<S>::Instantiate(const Block<const Member>& args, const Block<const Int64>& iargs) const -> Result<const DataType*>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, false, Result<const DataType*>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const ParametricTypeInterface* o_ = (const ParametricTypeInterface*) this->GetPointer(); if (!(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS) && MAXON_UNLIKELY(!o_)) { o_ = ParametricTypeInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (((MTable*) o_->_vtable)->_ParametricTypeInterface_Instantiate(o_, args, iargs));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ParametricTypeInterface::ConstReferenceFunctionsImpl<S>::Instantiate(const DataType* type, const Block<const Int64>& iargs) const -> Result<const DataType*>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, false, Result<const DataType*>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const ParametricTypeInterface* o_ = (const ParametricTypeInterface*) this->GetPointer(); if (!(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS) && MAXON_UNLIKELY(!o_)) { o_ = ParametricTypeInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (o_->Instantiate(type, iargs));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ParametricTypeInterface::ConstReferenceFunctionsImpl<S>::IsBaseOfOrSame(const DataType* type, const DataType* other) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, false, typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const ParametricTypeInterface* o_ = (const ParametricTypeInterface*) this->GetPointer(); if (!(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS) && MAXON_UNLIKELY(!o_)) { o_ = ParametricTypeInterface::NullValuePtr(); if (!o_) return maxon::PrivateLogNullptrError(false); } 
	return (((MTable*) o_->_vtable)->_ParametricTypeInterface_IsBaseOfOrSame(o_, type, other));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ParametricTypeInterface::ConstReferenceFunctionsImpl<S>::Convert(const DataPtr& dest, const ConstDataPtr& src, CONVERSION_FLAGS ignore) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const ParametricTypeInterface* o_ = (const ParametricTypeInterface*) this->GetPointer(); if (!(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS) && MAXON_UNLIKELY(!o_)) { o_ = ParametricTypeInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (((MTable*) o_->_vtable)->_ParametricTypeInterface_Convert(o_, dest, src, ignore));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ParametricTypeInterface::ConstReferenceFunctionsImpl<S>::Parse(const Char* params) const -> Result<Tuple<const DataType*, const Char*>>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, false, Result<Tuple<const DataType*, const Char*>>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const ParametricTypeInterface* o_ = (const ParametricTypeInterface*) this->GetPointer(); if (!(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS) && MAXON_UNLIKELY(!o_)) { o_ = ParametricTypeInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (((MTable*) o_->_vtable)->_ParametricTypeInterface_Parse(o_, params));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ParametricTypeInterface::ConstReferenceFunctionsImpl<S>::Substitute(const DataType* orig, const Delegate<Result<const DataType*>(const DataType*)>& replace) const -> Result<const DataType*>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, false, Result<const DataType*>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const ParametricTypeInterface* o_ = (const ParametricTypeInterface*) this->GetPointer(); if (!(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS) && MAXON_UNLIKELY(!o_)) { o_ = ParametricTypeInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (((MTable*) o_->_vtable)->_ParametricTypeInterface_Substitute(o_, orig, replace));
}
#endif

#ifdef MAXON_COMPILER_GCC
	#pragma GCC diagnostic pop
#endif

#endif

