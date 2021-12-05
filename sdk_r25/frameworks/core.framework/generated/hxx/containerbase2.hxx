
#ifndef DOXYGEN

#if defined MAXON_COMPILER_GCC
	#pragma GCC diagnostic push
	#if MAXON_COMPILER_GCC >= 600
		#pragma GCC diagnostic ignored "-Wmisleading-indentation"
	#endif
#endif

#if 1

struct GenericContainerInterface::MTable
{
	MTable() { }
	template <typename C> explicit MTable(C*) { Init<typename maxon::SFINAEHelper<Hxx2, C>::type::template Wrapper<C>>(); }
	template <typename C> MTable(C*, maxon::Bool) { Init<C>(); }
	const ContainerDataType<>& (*_GenericContainerInterface_GetContainerType) (const GenericContainerInterface* this_);
	INTERFACES (*_GenericContainerInterface_GetInterfaces) (const GenericContainerInterface* this_);
	Result<GenericContainerInterface*> (*_GenericContainerInterface_MakeWritable) (const GenericContainerInterface* this_, Bool cloneElements);
	Result<GenericContainerInterface*> (*_GenericContainerInterface_Clone) (const GenericContainerInterface* this_, Bool cloneElements);
	String (*_GenericContainerInterface_ToString) (const GenericContainerInterface* this_, const FormatStatement* formatStatement);
	HashInt (*_GenericContainerInterface_GetHashCode) (const GenericContainerInterface* this_);
	HashValue (*_GenericContainerInterface_GetHashValue) (const GenericContainerInterface* this_);
	Bool (*_GenericContainerInterface_IsEqual) (const GenericContainerInterface* this_, const GenericContainerInterface* other, EQUALITY equality);
	Int (*_GenericContainerInterface_FindMemberIndex) (const GenericContainerInterface* this_, const InternedId& name);
	Result<Int> (*_GenericContainerInterface_GetCount) (const GenericContainerInterface* this_);
	Int (*_GenericContainerInterface_GetIteratorStateSize) (const GenericContainerInterface* this_, const MemberMap* map);
	Result<Int> (*_GenericContainerInterface_InitIterator) (const GenericContainerInterface* this_, ViewIteratorMember* members, const MemberMap* map, Char* state, PersistentIdBuffer* idBuffer);
	Result<Int> (*_GenericContainerInterface_ValidateIterator) (const GenericContainerInterface* this_, Int index, ViewIteratorMember* members, const MemberMap* map, Char* state, PersistentIdBuffer* idBuffer);
	void (*_GenericContainerInterface_FreeIterator) (const GenericContainerInterface* this_, ViewIteratorMember* members, const MemberMap* map, Char* state, PersistentIdBuffer* idBuffer);
	Result<Int> (*_GenericContainerInterface_MoveIterator) (const GenericContainerInterface* this_, Int index, ViewIteratorMember* members, const MemberMap* map, Char* state, PersistentIdBuffer* idBuffer);
	Result<void> (*_GenericContainerInterface_AdvancePersistentId) (const GenericContainerInterface* this_, Int index, const Char* state, PersistentIdBuffer& idBuffer);
	void* _MAXON_METHOD_RESERVE19;
	void* _MAXON_METHOD_RESERVE20;
	maxon::ClassInfoBase _info;
	template <typename IMPL> void Init()
	{
		void (*free) (const GenericContainerInterface*) = &IMPL::Implementation::Free;
		_info._free = reinterpret_cast<void(*)(const void*)>(free);
		_GenericContainerInterface_GetContainerType = &IMPL::_GenericContainerInterface_GetContainerType;
		_GenericContainerInterface_GetInterfaces = &IMPL::_GenericContainerInterface_GetInterfaces;
		_GenericContainerInterface_MakeWritable = &IMPL::_GenericContainerInterface_MakeWritable;
		_GenericContainerInterface_Clone = &IMPL::_GenericContainerInterface_Clone;
		_GenericContainerInterface_ToString = &IMPL::_GenericContainerInterface_ToString;
		_GenericContainerInterface_GetHashCode = &IMPL::_GenericContainerInterface_GetHashCode;
		_GenericContainerInterface_GetHashValue = &IMPL::_GenericContainerInterface_GetHashValue;
		_GenericContainerInterface_IsEqual = &IMPL::_GenericContainerInterface_IsEqual;
		_GenericContainerInterface_FindMemberIndex = &IMPL::_GenericContainerInterface_FindMemberIndex;
		_GenericContainerInterface_GetCount = &IMPL::_GenericContainerInterface_GetCount;
		_GenericContainerInterface_GetIteratorStateSize = &IMPL::_GenericContainerInterface_GetIteratorStateSize;
		_GenericContainerInterface_InitIterator = &IMPL::_GenericContainerInterface_InitIterator;
		_GenericContainerInterface_ValidateIterator = &IMPL::_GenericContainerInterface_ValidateIterator;
		_GenericContainerInterface_FreeIterator = &IMPL::_GenericContainerInterface_FreeIterator;
		_GenericContainerInterface_MoveIterator = &IMPL::_GenericContainerInterface_MoveIterator;
		_GenericContainerInterface_AdvancePersistentId = &IMPL::_GenericContainerInterface_AdvancePersistentId;
		_MAXON_METHOD_RESERVE19 = nullptr;
		_MAXON_METHOD_RESERVE20 = nullptr;
	}
	template <typename W> static maxon::Bool InitWithBases(maxon::ClassInfo* info, maxon::Int offset) { return true; }
	template <typename S> using CombinedMTable = S;
};

struct GenericContainerInterface::Hxx2
{
	template <typename C> using CWrapper = C;
	template <typename C> class Wrapper
	{
	public:
		using Implementation = C;
		static const ContainerDataType<>& _GenericContainerInterface_GetContainerType(const GenericContainerInterface* this_) { return C::Get(this_)->GetContainerType(); }
		static INTERFACES _GenericContainerInterface_GetInterfaces(const GenericContainerInterface* this_) { return C::Get(this_)->GetInterfaces(); }
		static Result<GenericContainerInterface*> _GenericContainerInterface_MakeWritable(const GenericContainerInterface* this_, Bool cloneElements) { return C::Get(this_)->MakeWritable(cloneElements); }
		static Result<GenericContainerInterface*> _GenericContainerInterface_Clone(const GenericContainerInterface* this_, Bool cloneElements) { return C::Get(this_)->Clone(cloneElements); }
		static String _GenericContainerInterface_ToString(const GenericContainerInterface* this_, const FormatStatement* formatStatement) { return C::Get(this_)->ToString(formatStatement); }
		static HashInt _GenericContainerInterface_GetHashCode(const GenericContainerInterface* this_) { return C::Get(this_)->GetHashCode(); }
		static HashValue _GenericContainerInterface_GetHashValue(const GenericContainerInterface* this_) { return C::Get(this_)->GetHashValue(); }
		static Bool _GenericContainerInterface_IsEqual(const GenericContainerInterface* this_, const GenericContainerInterface* other, EQUALITY equality) { return C::Get(this_)->IsEqual(other, equality); }
		static Int _GenericContainerInterface_FindMemberIndex(const GenericContainerInterface* this_, const InternedId& name) { return C::Get(this_)->FindMemberIndex(name); }
		static Result<Int> _GenericContainerInterface_GetCount(const GenericContainerInterface* this_) { return C::Get(this_)->GetCount(); }
		static Int _GenericContainerInterface_GetIteratorStateSize(const GenericContainerInterface* this_, const MemberMap* map) { return C::Get(this_)->GetIteratorStateSize(map); }
		static Result<Int> _GenericContainerInterface_InitIterator(const GenericContainerInterface* this_, ViewIteratorMember* members, const MemberMap* map, Char* state, PersistentIdBuffer* idBuffer) { return C::Get(this_)->InitIterator(members, map, state, idBuffer); }
		static Result<Int> _GenericContainerInterface_ValidateIterator(const GenericContainerInterface* this_, Int index, ViewIteratorMember* members, const MemberMap* map, Char* state, PersistentIdBuffer* idBuffer) { return C::Get(this_)->ValidateIterator(index, members, map, state, idBuffer); }
		static void _GenericContainerInterface_FreeIterator(const GenericContainerInterface* this_, ViewIteratorMember* members, const MemberMap* map, Char* state, PersistentIdBuffer* idBuffer) { return C::Get(this_)->FreeIterator(members, map, state, idBuffer); }
		static Result<Int> _GenericContainerInterface_MoveIterator(const GenericContainerInterface* this_, Int index, ViewIteratorMember* members, const MemberMap* map, Char* state, PersistentIdBuffer* idBuffer) { return C::Get(this_)->MoveIterator(index, members, map, state, idBuffer); }
		static Result<void> _GenericContainerInterface_AdvancePersistentId(const GenericContainerInterface* this_, Int index, const Char* state, PersistentIdBuffer& idBuffer) { return C::Get(this_)->AdvancePersistentId(index, state, idBuffer); }
	};

};
MAXON_ATTRIBUTE_FORCE_INLINE auto GenericContainerInterface::GetContainerType() const -> const ContainerDataType<>&
{
	return ((GenericContainerInterface::MTable*) (this->_vtableCls + 1))[-1]._GenericContainerInterface_GetContainerType(this);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto GenericContainerInterface::GetInterfaces() const -> INTERFACES
{
	return ((GenericContainerInterface::MTable*) (this->_vtableCls + 1))[-1]._GenericContainerInterface_GetInterfaces(this);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto GenericContainerInterface::MakeWritable(Bool cloneElements) const -> Result<GenericContainerInterface*>
{
	return ((GenericContainerInterface::MTable*) (this->_vtableCls + 1))[-1]._GenericContainerInterface_MakeWritable(this, cloneElements);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto GenericContainerInterface::Clone(Bool cloneElements) const -> Result<GenericContainerInterface*>
{
	return ((GenericContainerInterface::MTable*) (this->_vtableCls + 1))[-1]._GenericContainerInterface_Clone(this, cloneElements);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto GenericContainerInterface::ToString(const FormatStatement* formatStatement) const -> String
{
	return ((GenericContainerInterface::MTable*) (this->_vtableCls + 1))[-1]._GenericContainerInterface_ToString(this, formatStatement);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto GenericContainerInterface::GetHashCode() const -> HashInt
{
	return ((GenericContainerInterface::MTable*) (this->_vtableCls + 1))[-1]._GenericContainerInterface_GetHashCode(this);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto GenericContainerInterface::GetHashValue() const -> HashValue
{
	return ((GenericContainerInterface::MTable*) (this->_vtableCls + 1))[-1]._GenericContainerInterface_GetHashValue(this);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto GenericContainerInterface::IsEqual(const GenericContainerInterface* other, EQUALITY equality) const -> Bool
{
	return ((GenericContainerInterface::MTable*) (this->_vtableCls + 1))[-1]._GenericContainerInterface_IsEqual(this, other, equality);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto GenericContainerInterface::FindMemberIndex(const InternedId& name) const -> Int
{
	return ((GenericContainerInterface::MTable*) (this->_vtableCls + 1))[-1]._GenericContainerInterface_FindMemberIndex(this, name);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto GenericContainerInterface::GetCount() const -> Result<Int>
{
	return ((GenericContainerInterface::MTable*) (this->_vtableCls + 1))[-1]._GenericContainerInterface_GetCount(this);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto GenericContainerInterface::GetIteratorStateSize(const MemberMap* map) const -> Int
{
	return ((GenericContainerInterface::MTable*) (this->_vtableCls + 1))[-1]._GenericContainerInterface_GetIteratorStateSize(this, map);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto GenericContainerInterface::InitIterator(ViewIteratorMember* members, const MemberMap* map, Char* state, PersistentIdBuffer* idBuffer) const -> Result<Int>
{
	return ((GenericContainerInterface::MTable*) (this->_vtableCls + 1))[-1]._GenericContainerInterface_InitIterator(this, members, map, state, idBuffer);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto GenericContainerInterface::ValidateIterator(Int index, ViewIteratorMember* members, const MemberMap* map, Char* state, PersistentIdBuffer* idBuffer) const -> Result<Int>
{
	return ((GenericContainerInterface::MTable*) (this->_vtableCls + 1))[-1]._GenericContainerInterface_ValidateIterator(this, index, members, map, state, idBuffer);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto GenericContainerInterface::FreeIterator(ViewIteratorMember* members, const MemberMap* map, Char* state, PersistentIdBuffer* idBuffer) const -> void
{
	return ((GenericContainerInterface::MTable*) (this->_vtableCls + 1))[-1]._GenericContainerInterface_FreeIterator(this, members, map, state, idBuffer);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto GenericContainerInterface::MoveIterator(Int index, ViewIteratorMember* members, const MemberMap* map, Char* state, PersistentIdBuffer* idBuffer) const -> Result<Int>
{
	return ((GenericContainerInterface::MTable*) (this->_vtableCls + 1))[-1]._GenericContainerInterface_MoveIterator(this, index, members, map, state, idBuffer);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto GenericContainerInterface::AdvancePersistentId(Int index, const Char* state, PersistentIdBuffer& idBuffer) const -> Result<void>
{
	return ((GenericContainerInterface::MTable*) (this->_vtableCls + 1))[-1]._GenericContainerInterface_AdvancePersistentId(this, index, state, idBuffer);
}

GenericContainerInterface::GenericContainerInterface(const MTable& vtable) : _vtableCls(&vtable._info) { }
template <typename S, typename T_> MAXON_ATTRIBUTE_FORCE_INLINE auto GenericContainerInterface::Hxx1::ConstReferenceFunctionsImpl<S, T_>::GetContainerType() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<const ContainerDataType<>&>, const ContainerDataType<>&>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<const ContainerDataType<>&>, const ContainerDataType<>&>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const GenericContainerInterface* o_ = (const GenericContainerInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = GenericContainerInterface::NullValuePtr(); if (!o_) return maxon::PrivateNullReturnValue<const ContainerDataType<>&>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } 
	return (((GenericContainerInterface::MTable*) (o_->_vtableCls + 1))[-1]._GenericContainerInterface_GetContainerType(o_));
}
template <typename S, typename T_> MAXON_ATTRIBUTE_FORCE_INLINE auto GenericContainerInterface::Hxx1::ConstReferenceFunctionsImpl<S, T_>::GetInterfaces() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<INTERFACES>, INTERFACES>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<INTERFACES>, INTERFACES>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const GenericContainerInterface* o_ = (const GenericContainerInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = GenericContainerInterface::NullValuePtr(); if (!o_) return maxon::PrivateNullReturnValue<INTERFACES>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } 
	return (((GenericContainerInterface::MTable*) (o_->_vtableCls + 1))[-1]._GenericContainerInterface_GetInterfaces(o_));
}
template <typename S, typename T_> MAXON_ATTRIBUTE_FORCE_INLINE auto GenericContainerInterface::Hxx1::ConstReferenceFunctionsImpl<S, T_>::Clone(Bool cloneElements) const -> Result<GenericContainerInterface*>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<GenericContainerInterface*>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const GenericContainerInterface* o_ = (const GenericContainerInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = GenericContainerInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (((GenericContainerInterface::MTable*) (o_->_vtableCls + 1))[-1]._GenericContainerInterface_Clone(o_, cloneElements));
}
template <typename S, typename T_> MAXON_ATTRIBUTE_FORCE_INLINE auto GenericContainerInterface::Hxx1::ConstReferenceFunctionsImpl<S, T_>::ToString(const FormatStatement* formatStatement) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<String>, String>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<String>, String>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const GenericContainerInterface* o_ = (const GenericContainerInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = GenericContainerInterface::NullValuePtr(); if (!o_) return maxon::PrivateNullReturnValue<String>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } 
	return (((GenericContainerInterface::MTable*) (o_->_vtableCls + 1))[-1]._GenericContainerInterface_ToString(o_, formatStatement));
}
template <typename S, typename T_> MAXON_ATTRIBUTE_FORCE_INLINE auto GenericContainerInterface::Hxx1::ConstReferenceFunctionsImpl<S, T_>::GetHashValue() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<HashValue>, HashValue>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<HashValue>, HashValue>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const GenericContainerInterface* o_ = (const GenericContainerInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = GenericContainerInterface::NullValuePtr(); if (!o_) return maxon::PrivateNullReturnValue<HashValue>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } 
	return (((GenericContainerInterface::MTable*) (o_->_vtableCls + 1))[-1]._GenericContainerInterface_GetHashValue(o_));
}
template <typename S, typename T_> MAXON_ATTRIBUTE_FORCE_INLINE auto GenericContainerInterface::Hxx1::ConstReferenceFunctionsImpl<S, T_>::IsEqual(const GenericContainerInterface* other, EQUALITY equality) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const GenericContainerInterface* o_ = (const GenericContainerInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = GenericContainerInterface::NullValuePtr(); if (!o_) return maxon::PrivateLogNullptrError(false); } 
	return (((GenericContainerInterface::MTable*) (o_->_vtableCls + 1))[-1]._GenericContainerInterface_IsEqual(o_, other, equality));
}
template <typename S, typename T_> MAXON_ATTRIBUTE_FORCE_INLINE auto GenericContainerInterface::Hxx1::ConstReferenceFunctionsImpl<S, T_>::FindMemberIndex(const InternedId& name) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const GenericContainerInterface* o_ = (const GenericContainerInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = GenericContainerInterface::NullValuePtr(); if (!o_) return -1; } 
	return (((GenericContainerInterface::MTable*) (o_->_vtableCls + 1))[-1]._GenericContainerInterface_FindMemberIndex(o_, name));
}
template <typename S, typename T_> MAXON_ATTRIBUTE_FORCE_INLINE auto GenericContainerInterface::Hxx1::ConstReferenceFunctionsImpl<S, T_>::FindMemberIndex(const Member& member) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const GenericContainerInterface* o_ = (const GenericContainerInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = GenericContainerInterface::NullValuePtr(); if (!o_) return 0; } 
	return (o_->FindMemberIndex(member));
}
template <typename S, typename T_> MAXON_ATTRIBUTE_FORCE_INLINE auto GenericContainerInterface::Hxx1::ConstReferenceFunctionsImpl<S, T_>::GetCount() const -> Result<Int>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<Int>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const GenericContainerInterface* o_ = (const GenericContainerInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = GenericContainerInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (((GenericContainerInterface::MTable*) (o_->_vtableCls + 1))[-1]._GenericContainerInterface_GetCount(o_));
}
#endif

#ifdef MAXON_COMPILER_GCC
	#pragma GCC diagnostic pop
#endif

#endif

