
#ifndef DOXYGEN

#if defined MAXON_COMPILER_GCC
	#pragma GCC diagnostic push
	#if MAXON_COMPILER_GCC >= 600
		#pragma GCC diagnostic ignored "-Wmisleading-indentation"
	#endif
#endif

#if 1
#ifndef MAXON_TARGET_64BIT
#endif

struct GenericContainerInterface::MTable
{
	MTable() { }
	template <typename C> explicit MTable(C*) { Init<typename maxon::SFINAEHelper<Hxx2, C>::type::template Wrapper<C>>(); }
	template <typename C> MTable(C*, maxon::Bool) { Init<C>(); }
	void (*_GenericContainerInterface_Free) (const GenericContainerInterface* object);
	const ContainerDataType& (*_GenericContainerInterface_GetType) (const GenericContainerInterface* this_);
	Result<GenericContainerInterface*> (*_GenericContainerInterface_Clone) (const GenericContainerInterface* this_);
	String (*_GenericContainerInterface_ToString) (const GenericContainerInterface* this_, const FormatStatement* formatStatement);
	Int (*_GenericContainerInterface_FindMemberIndex) (const GenericContainerInterface* this_, const InternedId& name);
	Int (*_GenericContainerInterface_GetIteratorStateSize) (const GenericContainerInterface* this_, const MemberMap* map);
	Result<Int> (*_GenericContainerInterface_InitIterator) (const GenericContainerInterface* this_, ViewIteratorMember* members, const MemberMap* map, Char* state);
	Result<Int> (*_GenericContainerInterface_ValidateIterator) (const GenericContainerInterface* this_, Int index, ViewIteratorMember* members, const MemberMap* map, Char* state);
	void (*_GenericContainerInterface_FreeIterator) (const GenericContainerInterface* this_, ViewIteratorMember* members, const MemberMap* map, Char* state);
	Result<Int> (*_GenericContainerInterface_MoveIterator) (const GenericContainerInterface* this_, Int index, ViewIteratorMember* members, const MemberMap* map, Char* state);
	template <typename IMPL> void Init()
	{
		_GenericContainerInterface_Free = &IMPL::_GenericContainerInterface_Free;
		_GenericContainerInterface_GetType = &IMPL::_GenericContainerInterface_GetType;
		_GenericContainerInterface_Clone = &IMPL::_GenericContainerInterface_Clone;
		_GenericContainerInterface_ToString = &IMPL::_GenericContainerInterface_ToString;
		_GenericContainerInterface_FindMemberIndex = &IMPL::_GenericContainerInterface_FindMemberIndex;
		_GenericContainerInterface_GetIteratorStateSize = &IMPL::_GenericContainerInterface_GetIteratorStateSize;
		_GenericContainerInterface_InitIterator = &IMPL::_GenericContainerInterface_InitIterator;
		_GenericContainerInterface_ValidateIterator = &IMPL::_GenericContainerInterface_ValidateIterator;
		_GenericContainerInterface_FreeIterator = &IMPL::_GenericContainerInterface_FreeIterator;
		_GenericContainerInterface_MoveIterator = &IMPL::_GenericContainerInterface_MoveIterator;
	}
};

struct GenericContainerInterface::Hxx2
{
	template <typename C> class Wrapper
	{
	public:
	static void _GenericContainerInterface_Free(const GenericContainerInterface* object) { return C::Free((const C*) object); }
	static const ContainerDataType& _GenericContainerInterface_GetType(const GenericContainerInterface* this_) { return ((const C*) this_)->GetType(); }
	static Result<GenericContainerInterface*> _GenericContainerInterface_Clone(const GenericContainerInterface* this_) { return ((const C*) this_)->Clone(); }
	static String _GenericContainerInterface_ToString(const GenericContainerInterface* this_, const FormatStatement* formatStatement) { return ((const C*) this_)->ToString(formatStatement); }
	static Int _GenericContainerInterface_FindMemberIndex(const GenericContainerInterface* this_, const InternedId& name) { return ((const C*) this_)->FindMemberIndex(name); }
	static Int _GenericContainerInterface_GetIteratorStateSize(const GenericContainerInterface* this_, const MemberMap* map) { return ((const C*) this_)->GetIteratorStateSize(map); }
	static Result<Int> _GenericContainerInterface_InitIterator(const GenericContainerInterface* this_, ViewIteratorMember* members, const MemberMap* map, Char* state) { return ((const C*) this_)->InitIterator(members, map, state); }
	static Result<Int> _GenericContainerInterface_ValidateIterator(const GenericContainerInterface* this_, Int index, ViewIteratorMember* members, const MemberMap* map, Char* state) { return ((const C*) this_)->ValidateIterator(index, members, map, state); }
	static void _GenericContainerInterface_FreeIterator(const GenericContainerInterface* this_, ViewIteratorMember* members, const MemberMap* map, Char* state) { return ((const C*) this_)->FreeIterator(members, map, state); }
	static Result<Int> _GenericContainerInterface_MoveIterator(const GenericContainerInterface* this_, Int index, ViewIteratorMember* members, const MemberMap* map, Char* state) { return ((const C*) this_)->MoveIterator(index, members, map, state); }
	};

};
MAXON_ATTRIBUTE_FORCE_INLINE auto GenericContainerInterface::Free(const GenericContainerInterface* object) -> void
{
	if (!object)
		return;
	return ((GenericContainerInterface::MTable*) object->_vtable)->_GenericContainerInterface_Free(object);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto GenericContainerInterface::GetType() const -> const ContainerDataType&
{
	return ((GenericContainerInterface::MTable*) this->_vtable)->_GenericContainerInterface_GetType(this);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto GenericContainerInterface::Clone() const -> Result<GenericContainerInterface*>
{
	return ((GenericContainerInterface::MTable*) this->_vtable)->_GenericContainerInterface_Clone(this);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto GenericContainerInterface::ToString(const FormatStatement* formatStatement) const -> String
{
	return ((GenericContainerInterface::MTable*) this->_vtable)->_GenericContainerInterface_ToString(this, formatStatement);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto GenericContainerInterface::FindMemberIndex(const InternedId& name) const -> Int
{
	return ((GenericContainerInterface::MTable*) this->_vtable)->_GenericContainerInterface_FindMemberIndex(this, name);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto GenericContainerInterface::GetIteratorStateSize(const MemberMap* map) const -> Int
{
	return ((GenericContainerInterface::MTable*) this->_vtable)->_GenericContainerInterface_GetIteratorStateSize(this, map);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto GenericContainerInterface::InitIterator(ViewIteratorMember* members, const MemberMap* map, Char* state) const -> Result<Int>
{
	return ((GenericContainerInterface::MTable*) this->_vtable)->_GenericContainerInterface_InitIterator(this, members, map, state);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto GenericContainerInterface::ValidateIterator(Int index, ViewIteratorMember* members, const MemberMap* map, Char* state) const -> Result<Int>
{
	return ((GenericContainerInterface::MTable*) this->_vtable)->_GenericContainerInterface_ValidateIterator(this, index, members, map, state);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto GenericContainerInterface::FreeIterator(ViewIteratorMember* members, const MemberMap* map, Char* state) const -> void
{
	return ((GenericContainerInterface::MTable*) this->_vtable)->_GenericContainerInterface_FreeIterator(this, members, map, state);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto GenericContainerInterface::MoveIterator(Int index, ViewIteratorMember* members, const MemberMap* map, Char* state) const -> Result<Int>
{
	return ((GenericContainerInterface::MTable*) this->_vtable)->_GenericContainerInterface_MoveIterator(this, index, members, map, state);
}

template <typename S, typename T_> MAXON_ATTRIBUTE_FORCE_INLINE auto GenericContainerInterface::Hxx1::ConstReferenceFunctionsImpl<S, T_>::GetType() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<const ContainerDataType&>, const ContainerDataType&>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<const ContainerDataType&>, const ContainerDataType&>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const GenericContainerInterface* o_ = (const GenericContainerInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = GenericContainerInterface::NullValuePtr(); if (!o_) return maxon::PrivateNullReturnValue<const ContainerDataType&>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } 
	return (((GenericContainerInterface::MTable*) o_->_vtable)->_GenericContainerInterface_GetType(o_));
}
template <typename S, typename T_> MAXON_ATTRIBUTE_FORCE_INLINE auto GenericContainerInterface::Hxx1::ConstReferenceFunctionsImpl<S, T_>::Clone() const -> Result<GenericContainerInterface*>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<GenericContainerInterface*>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const GenericContainerInterface* o_ = (const GenericContainerInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = GenericContainerInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (((GenericContainerInterface::MTable*) o_->_vtable)->_GenericContainerInterface_Clone(o_));
}
template <typename S, typename T_> MAXON_ATTRIBUTE_FORCE_INLINE auto GenericContainerInterface::Hxx1::ConstReferenceFunctionsImpl<S, T_>::ToString(const FormatStatement* formatStatement) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<String>, String>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<String>, String>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const GenericContainerInterface* o_ = (const GenericContainerInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = GenericContainerInterface::NullValuePtr(); if (!o_) return maxon::PrivateNullReturnValue<String>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } 
	return (((GenericContainerInterface::MTable*) o_->_vtable)->_GenericContainerInterface_ToString(o_, formatStatement));
}
template <typename S, typename T_> MAXON_ATTRIBUTE_FORCE_INLINE auto GenericContainerInterface::Hxx1::ConstReferenceFunctionsImpl<S, T_>::FindMemberIndex(const InternedId& name) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const GenericContainerInterface* o_ = (const GenericContainerInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = GenericContainerInterface::NullValuePtr(); if (!o_) return -1; } 
	return (((GenericContainerInterface::MTable*) o_->_vtable)->_GenericContainerInterface_FindMemberIndex(o_, name));
}
template <typename S, typename T_> MAXON_ATTRIBUTE_FORCE_INLINE auto GenericContainerInterface::Hxx1::ConstReferenceFunctionsImpl<S, T_>::FindMemberIndex(const Member& member) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const GenericContainerInterface* o_ = (const GenericContainerInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = GenericContainerInterface::NullValuePtr(); if (!o_) return 0; } 
	return (o_->FindMemberIndex(member));
}
template <typename S, typename T_> MAXON_ATTRIBUTE_FORCE_INLINE auto GenericContainerInterface::Hxx1::ConstReferenceFunctionsImpl<S, T_>::GetIteratorStateSize(const MemberMap* map) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const GenericContainerInterface* o_ = (const GenericContainerInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = GenericContainerInterface::NullValuePtr(); if (!o_) return 0; } 
	return (((GenericContainerInterface::MTable*) o_->_vtable)->_GenericContainerInterface_GetIteratorStateSize(o_, map));
}
template <typename S, typename T_> MAXON_ATTRIBUTE_FORCE_INLINE auto GenericContainerInterface::Hxx1::ConstReferenceFunctionsImpl<S, T_>::InitIterator(ViewIteratorMember* members, const MemberMap* map, Char* state) const -> Result<Int>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<Int>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const GenericContainerInterface* o_ = (const GenericContainerInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = GenericContainerInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (((GenericContainerInterface::MTable*) o_->_vtable)->_GenericContainerInterface_InitIterator(o_, members, map, state));
}
template <typename S, typename T_> MAXON_ATTRIBUTE_FORCE_INLINE auto GenericContainerInterface::Hxx1::ConstReferenceFunctionsImpl<S, T_>::ValidateIterator(Int index, ViewIteratorMember* members, const MemberMap* map, Char* state) const -> Result<Int>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<Int>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const GenericContainerInterface* o_ = (const GenericContainerInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = GenericContainerInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (((GenericContainerInterface::MTable*) o_->_vtable)->_GenericContainerInterface_ValidateIterator(o_, index, members, map, state));
}
template <typename S, typename T_> MAXON_ATTRIBUTE_FORCE_INLINE auto GenericContainerInterface::Hxx1::ConstReferenceFunctionsImpl<S, T_>::FreeIterator(ViewIteratorMember* members, const MemberMap* map, Char* state) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const GenericContainerInterface* o_ = (const GenericContainerInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = GenericContainerInterface::NullValuePtr(); if (!o_) return maxon::PrivateLogNullptrError(); } 
	((GenericContainerInterface::MTable*) o_->_vtable)->_GenericContainerInterface_FreeIterator(o_, members, map, state);
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
template <typename S, typename T_> MAXON_ATTRIBUTE_FORCE_INLINE auto GenericContainerInterface::Hxx1::ConstReferenceFunctionsImpl<S, T_>::MoveIterator(Int index, ViewIteratorMember* members, const MemberMap* map, Char* state) const -> Result<Int>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<Int>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const GenericContainerInterface* o_ = (const GenericContainerInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = GenericContainerInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (((GenericContainerInterface::MTable*) o_->_vtable)->_GenericContainerInterface_MoveIterator(o_, index, members, map, state));
}
template <typename S, typename T_> MAXON_ATTRIBUTE_FORCE_INLINE auto GenericContainerInterface::Hxx1::ConstReferenceFunctionsImpl<S, T_>::Begin() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<maxon::details::ContainerIterator<T_, true>>, maxon::details::ContainerIterator<T_, true>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<maxon::details::ContainerIterator<T_, true>>, maxon::details::ContainerIterator<T_, true>>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const GenericContainerInterface* o_ = (const GenericContainerInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = GenericContainerInterface::NullValuePtr(); if (!o_) return maxon::PrivateNullReturnValue<maxon::details::ContainerIterator<T_, true>>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } 
	return (o_->Begin<T_>());
}
template <typename S, typename T_> MAXON_ATTRIBUTE_FORCE_INLINE auto GenericContainerInterface::Hxx1::ConstReferenceFunctionsImpl<S, T_>::End() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<PRIVATE_MAXON_RBF_SENTINEL(maxon::details::ContainerIterator<T_,true>)>, PRIVATE_MAXON_RBF_SENTINEL(maxon::details::ContainerIterator<T_,true>)>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<PRIVATE_MAXON_RBF_SENTINEL(maxon::details::ContainerIterator<T_,true>)>, PRIVATE_MAXON_RBF_SENTINEL(maxon::details::ContainerIterator<T_,true>)>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const GenericContainerInterface* o_ = (const GenericContainerInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = GenericContainerInterface::NullValuePtr(); if (!o_) return maxon::PrivateNullReturnValue<PRIVATE_MAXON_RBF_SENTINEL(maxon::details::ContainerIterator<T_,true>)>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } 
	return (o_->End<T_>());
}
template <typename S, typename T_> MAXON_ATTRIBUTE_FORCE_INLINE auto GenericContainerInterface::Hxx1::ReferenceFunctionsImpl<S, T_>::Begin() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<maxon::details::ContainerIterator<T_, false>>, maxon::details::ContainerIterator<T_, false>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<maxon::details::ContainerIterator<T_, false>>, maxon::details::ContainerIterator<T_, false>>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); GenericContainerInterface* o_ = (GenericContainerInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) return maxon::PrivateNullReturnValue<maxon::details::ContainerIterator<T_, false>>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); 
	return (o_->Begin<T_>());
}
template <typename S, typename T_> MAXON_ATTRIBUTE_FORCE_INLINE auto GenericContainerInterface::Hxx1::ReferenceFunctionsImpl<S, T_>::End() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<PRIVATE_MAXON_RBF_SENTINEL(maxon::details::ContainerIterator<T_,false>)>, PRIVATE_MAXON_RBF_SENTINEL(maxon::details::ContainerIterator<T_,false>)>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<PRIVATE_MAXON_RBF_SENTINEL(maxon::details::ContainerIterator<T_,false>)>, PRIVATE_MAXON_RBF_SENTINEL(maxon::details::ContainerIterator<T_,false>)>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); GenericContainerInterface* o_ = (GenericContainerInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) return maxon::PrivateNullReturnValue<PRIVATE_MAXON_RBF_SENTINEL(maxon::details::ContainerIterator<T_,false>)>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); 
	return (o_->End<T_>());
}
#endif

#ifdef MAXON_COMPILER_GCC
	#pragma GCC diagnostic pop
#endif

#endif

