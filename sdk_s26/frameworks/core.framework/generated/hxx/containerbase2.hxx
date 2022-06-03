
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
	const ContainerDataType<>& (*GenericContainerInterface_GetContainerType) (const GenericContainerInterface* this_);
	INTERFACES (*GenericContainerInterface_GetInterfaces) (const GenericContainerInterface* this_);
	Result<GenericContainerInterface*> (*GenericContainerInterface_MakeWritable) (const GenericContainerInterface* this_, Bool copyContent);
	Result<GenericContainerInterface*> (*GenericContainerInterface_Clone) (const GenericContainerInterface* this_, Bool copyContent);
	String (*GenericContainerInterface_ToString) (const GenericContainerInterface* this_, const FormatStatement* formatStatement);
	HashInt (*GenericContainerInterface_GetHashCode) (const GenericContainerInterface* this_);
	HashValue (*GenericContainerInterface_GetHashValue) (const GenericContainerInterface* this_);
	Bool (*GenericContainerInterface_IsEqual) (const GenericContainerInterface* this_, const GenericContainerInterface* other, EQUALITY equality);
	Int (*GenericContainerInterface_FindMemberIndex) (const GenericContainerInterface* this_, const InternedId& name);
	Result<Int> (*GenericContainerInterface_GetCount) (const GenericContainerInterface* this_);
	Int (*GenericContainerInterface_GetIteratorStateSize) (const GenericContainerInterface* this_, const MemberMap* map);
	Result<Int> (*GenericContainerInterface_InitIterator) (const GenericContainerInterface* this_, ViewIteratorMember* members, const MemberMap* map, Char* state, PersistentIdBuffer* idBuffer);
	Result<Int> (*GenericContainerInterface_ValidateIterator) (const GenericContainerInterface* this_, Int index, ViewIteratorMember* members, const MemberMap* map, Char* state, PersistentIdBuffer* idBuffer);
	void (*GenericContainerInterface_FreeIterator) (const GenericContainerInterface* this_, ViewIteratorMember* members, const MemberMap* map, Char* state, PersistentIdBuffer* idBuffer);
	Result<Int> (*GenericContainerInterface_MoveIterator) (const GenericContainerInterface* this_, Int index, ViewIteratorMember* members, const MemberMap* map, Char* state, PersistentIdBuffer* idBuffer);
	Result<void> (*GenericContainerInterface_AdvancePersistentId) (const GenericContainerInterface* this_, Int index, const Char* state, PersistentIdBuffer& idBuffer);
	Result<Int> (*GenericContainerInterface_InitIterator_1) (const GenericContainerInterface* this_, ViewIteratorMember* members, const MemberMap* map, Char* state, PersistentIdBuffer* idBuffer, Bool constAccess);
	void* _MAXON_METHOD_RESERVE23;
	maxon::ClassInfoBase _info;
	template <typename IMPL> void Init()
	{
		void (*free) (const GenericContainerInterface*) = &IMPL::Implementation::Free;
		_info._free = reinterpret_cast<void(*)(const void*)>(free);
		GenericContainerInterface_GetContainerType = &IMPL::GenericContainerInterface_GetContainerType;
		GenericContainerInterface_GetInterfaces = &IMPL::GenericContainerInterface_GetInterfaces;
		GenericContainerInterface_MakeWritable = &IMPL::GenericContainerInterface_MakeWritable;
		GenericContainerInterface_Clone = &IMPL::GenericContainerInterface_Clone;
		GenericContainerInterface_ToString = &IMPL::GenericContainerInterface_ToString;
		GenericContainerInterface_GetHashCode = &IMPL::GenericContainerInterface_GetHashCode;
		GenericContainerInterface_GetHashValue = &IMPL::GenericContainerInterface_GetHashValue;
		GenericContainerInterface_IsEqual = &IMPL::GenericContainerInterface_IsEqual;
		GenericContainerInterface_FindMemberIndex = &IMPL::GenericContainerInterface_FindMemberIndex;
		GenericContainerInterface_GetCount = &IMPL::GenericContainerInterface_GetCount;
		GenericContainerInterface_GetIteratorStateSize = &IMPL::GenericContainerInterface_GetIteratorStateSize;
		GenericContainerInterface_InitIterator = &IMPL::GenericContainerInterface_InitIterator;
		GenericContainerInterface_ValidateIterator = &IMPL::GenericContainerInterface_ValidateIterator;
		GenericContainerInterface_FreeIterator = &IMPL::GenericContainerInterface_FreeIterator;
		GenericContainerInterface_MoveIterator = &IMPL::GenericContainerInterface_MoveIterator;
		GenericContainerInterface_AdvancePersistentId = &IMPL::GenericContainerInterface_AdvancePersistentId;
		GenericContainerInterface_InitIterator_1 = &IMPL::GenericContainerInterface_InitIterator_1;
		_MAXON_METHOD_RESERVE23 = nullptr;
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
		static const ContainerDataType<>& GenericContainerInterface_GetContainerType(const GenericContainerInterface* this_) { return C::Get(this_)->GetContainerType(); }
		static INTERFACES GenericContainerInterface_GetInterfaces(const GenericContainerInterface* this_) { return C::Get(this_)->GetInterfaces(); }
		static Result<GenericContainerInterface*> GenericContainerInterface_MakeWritable(const GenericContainerInterface* this_, Bool copyContent) { return C::Get(this_)->MakeWritable(copyContent); }
		static Result<GenericContainerInterface*> GenericContainerInterface_Clone(const GenericContainerInterface* this_, Bool copyContent) { return C::Get(this_)->Clone(copyContent); }
		static String GenericContainerInterface_ToString(const GenericContainerInterface* this_, const FormatStatement* formatStatement) { return C::Get(this_)->ToString(formatStatement); }
		static HashInt GenericContainerInterface_GetHashCode(const GenericContainerInterface* this_) { return C::Get(this_)->GetHashCode(); }
		static HashValue GenericContainerInterface_GetHashValue(const GenericContainerInterface* this_) { return C::Get(this_)->GetHashValue(); }
		static Bool GenericContainerInterface_IsEqual(const GenericContainerInterface* this_, const GenericContainerInterface* other, EQUALITY equality) { return C::Get(this_)->IsEqual(other, equality); }
		static Int GenericContainerInterface_FindMemberIndex(const GenericContainerInterface* this_, const InternedId& name) { return C::Get(this_)->FindMemberIndex(name); }
		static Result<Int> GenericContainerInterface_GetCount(const GenericContainerInterface* this_) { return C::Get(this_)->GetCount(); }
		static Int GenericContainerInterface_GetIteratorStateSize(const GenericContainerInterface* this_, const MemberMap* map) { return C::Get(this_)->GetIteratorStateSize(map); }
		static Result<Int> GenericContainerInterface_InitIterator(const GenericContainerInterface* this_, ViewIteratorMember* members, const MemberMap* map, Char* state, PersistentIdBuffer* idBuffer) { return C::Get(this_)->InitIterator(members, map, state, idBuffer); }
		static Result<Int> GenericContainerInterface_ValidateIterator(const GenericContainerInterface* this_, Int index, ViewIteratorMember* members, const MemberMap* map, Char* state, PersistentIdBuffer* idBuffer) { return C::Get(this_)->ValidateIterator(index, members, map, state, idBuffer); }
		static void GenericContainerInterface_FreeIterator(const GenericContainerInterface* this_, ViewIteratorMember* members, const MemberMap* map, Char* state, PersistentIdBuffer* idBuffer) { return C::Get(this_)->FreeIterator(members, map, state, idBuffer); }
		static Result<Int> GenericContainerInterface_MoveIterator(const GenericContainerInterface* this_, Int index, ViewIteratorMember* members, const MemberMap* map, Char* state, PersistentIdBuffer* idBuffer) { return C::Get(this_)->MoveIterator(index, members, map, state, idBuffer); }
		static Result<void> GenericContainerInterface_AdvancePersistentId(const GenericContainerInterface* this_, Int index, const Char* state, PersistentIdBuffer& idBuffer) { return C::Get(this_)->AdvancePersistentId(index, state, idBuffer); }
		static Result<Int> GenericContainerInterface_InitIterator_1(const GenericContainerInterface* this_, ViewIteratorMember* members, const MemberMap* map, Char* state, PersistentIdBuffer* idBuffer, Bool constAccess) { return C::Get(this_)->InitIterator(members, map, state, idBuffer, constAccess); }
	};

};
MAXON_ATTRIBUTE_FORCE_INLINE auto GenericContainerInterface::GetContainerType() const -> const ContainerDataType<>&
{
	return ((GenericContainerInterface::MTable*) (this->_vtableCls + 1))[-1].GenericContainerInterface_GetContainerType(this);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto GenericContainerInterface::GetInterfaces() const -> INTERFACES
{
	return ((GenericContainerInterface::MTable*) (this->_vtableCls + 1))[-1].GenericContainerInterface_GetInterfaces(this);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto GenericContainerInterface::MakeWritable(Bool copyContent) const -> Result<GenericContainerInterface*>
{
	return ((GenericContainerInterface::MTable*) (this->_vtableCls + 1))[-1].GenericContainerInterface_MakeWritable(this, copyContent);
}
[[deprecated]] MAXON_ATTRIBUTE_FORCE_INLINE auto GenericContainerInterface::Clone(Bool copyContent) const -> Result<GenericContainerInterface*>
{
	return ((GenericContainerInterface::MTable*) (this->_vtableCls + 1))[-1].GenericContainerInterface_Clone(this, copyContent);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto GenericContainerInterface::ToString(const FormatStatement* formatStatement) const -> String
{
	return ((GenericContainerInterface::MTable*) (this->_vtableCls + 1))[-1].GenericContainerInterface_ToString(this, formatStatement);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto GenericContainerInterface::GetHashCode() const -> HashInt
{
	return ((GenericContainerInterface::MTable*) (this->_vtableCls + 1))[-1].GenericContainerInterface_GetHashCode(this);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto GenericContainerInterface::GetHashValue() const -> HashValue
{
	return ((GenericContainerInterface::MTable*) (this->_vtableCls + 1))[-1].GenericContainerInterface_GetHashValue(this);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto GenericContainerInterface::IsEqual(const GenericContainerInterface* other, EQUALITY equality) const -> Bool
{
	return ((GenericContainerInterface::MTable*) (this->_vtableCls + 1))[-1].GenericContainerInterface_IsEqual(this, other, equality);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto GenericContainerInterface::FindMemberIndex(const InternedId& name) const -> Int
{
	return ((GenericContainerInterface::MTable*) (this->_vtableCls + 1))[-1].GenericContainerInterface_FindMemberIndex(this, name);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto GenericContainerInterface::GetCount() const -> Result<Int>
{
	return ((GenericContainerInterface::MTable*) (this->_vtableCls + 1))[-1].GenericContainerInterface_GetCount(this);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto GenericContainerInterface::GetIteratorStateSize(const MemberMap* map) const -> Int
{
	return ((GenericContainerInterface::MTable*) (this->_vtableCls + 1))[-1].GenericContainerInterface_GetIteratorStateSize(this, map);
}
[[deprecated]] MAXON_ATTRIBUTE_FORCE_INLINE auto GenericContainerInterface::InitIterator(ViewIteratorMember* members, const MemberMap* map, Char* state, PersistentIdBuffer* idBuffer) const -> Result<Int>
{
	return ((GenericContainerInterface::MTable*) (this->_vtableCls + 1))[-1].GenericContainerInterface_InitIterator(this, members, map, state, idBuffer);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto GenericContainerInterface::ValidateIterator(Int index, ViewIteratorMember* members, const MemberMap* map, Char* state, PersistentIdBuffer* idBuffer) const -> Result<Int>
{
	return ((GenericContainerInterface::MTable*) (this->_vtableCls + 1))[-1].GenericContainerInterface_ValidateIterator(this, index, members, map, state, idBuffer);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto GenericContainerInterface::FreeIterator(ViewIteratorMember* members, const MemberMap* map, Char* state, PersistentIdBuffer* idBuffer) const -> void
{
	return ((GenericContainerInterface::MTable*) (this->_vtableCls + 1))[-1].GenericContainerInterface_FreeIterator(this, members, map, state, idBuffer);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto GenericContainerInterface::MoveIterator(Int index, ViewIteratorMember* members, const MemberMap* map, Char* state, PersistentIdBuffer* idBuffer) const -> Result<Int>
{
	return ((GenericContainerInterface::MTable*) (this->_vtableCls + 1))[-1].GenericContainerInterface_MoveIterator(this, index, members, map, state, idBuffer);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto GenericContainerInterface::AdvancePersistentId(Int index, const Char* state, PersistentIdBuffer& idBuffer) const -> Result<void>
{
	return ((GenericContainerInterface::MTable*) (this->_vtableCls + 1))[-1].GenericContainerInterface_AdvancePersistentId(this, index, state, idBuffer);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto GenericContainerInterface::InitIterator(ViewIteratorMember* members, const MemberMap* map, Char* state, PersistentIdBuffer* idBuffer, Bool constAccess) const -> Result<Int>
{
	return ((GenericContainerInterface::MTable*) (this->_vtableCls + 1))[-1].GenericContainerInterface_InitIterator_1(this, members, map, state, idBuffer, constAccess);
}

GenericContainerInterface::GenericContainerInterface(const MTable& vtable) : _vtableCls(&vtable._info) { }
template <typename S, typename T_> MAXON_ATTRIBUTE_FORCE_INLINE auto GenericContainerInterface::Hxx1::ConstFn<S, T_>::GetContainerType() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<const ContainerDataType<>&>, const ContainerDataType<>&>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<const ContainerDataType<>&>, const ContainerDataType<>&>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const GenericContainerInterface* o_ = (const GenericContainerInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = GenericContainerInterface::NullValuePtr(); if (!o_) return maxon::PrivateNullReturnValue<const ContainerDataType<>&>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } 
	return (((GenericContainerInterface::MTable*) (o_->_vtableCls + 1))[-1].GenericContainerInterface_GetContainerType(o_));
}
template <typename S, typename T_> MAXON_ATTRIBUTE_FORCE_INLINE auto GenericContainerInterface::Hxx1::ConstFn<S, T_>::GetInterfaces() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<INTERFACES>, INTERFACES>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<INTERFACES>, INTERFACES>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const GenericContainerInterface* o_ = (const GenericContainerInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = GenericContainerInterface::NullValuePtr(); if (!o_) return maxon::PrivateNullReturnValue<INTERFACES>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } 
	return (((GenericContainerInterface::MTable*) (o_->_vtableCls + 1))[-1].GenericContainerInterface_GetInterfaces(o_));
}
template <typename S, typename T_> MAXON_ATTRIBUTE_FORCE_INLINE auto GenericContainerInterface::Hxx1::ConstFn<S, T_>::Clone(Bool copyContent) const -> Result<GenericContainerInterface*>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<GenericContainerInterface*>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const GenericContainerInterface* o_ = (const GenericContainerInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = GenericContainerInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (((GenericContainerInterface::MTable*) (o_->_vtableCls + 1))[-1].GenericContainerInterface_Clone(o_, copyContent));
}
template <typename S, typename T_> MAXON_ATTRIBUTE_FORCE_INLINE auto GenericContainerInterface::Hxx1::ConstFn<S, T_>::ToString(const FormatStatement* formatStatement) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<String>, String>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<String>, String>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const GenericContainerInterface* o_ = (const GenericContainerInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = GenericContainerInterface::NullValuePtr(); if (!o_) return maxon::PrivateNullReturnValue<String>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } 
	return (((GenericContainerInterface::MTable*) (o_->_vtableCls + 1))[-1].GenericContainerInterface_ToString(o_, formatStatement));
}
template <typename S, typename T_> MAXON_ATTRIBUTE_FORCE_INLINE auto GenericContainerInterface::Hxx1::ConstFn<S, T_>::GetHashValue() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<HashValue>, HashValue>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<HashValue>, HashValue>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const GenericContainerInterface* o_ = (const GenericContainerInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = GenericContainerInterface::NullValuePtr(); if (!o_) return maxon::PrivateNullReturnValue<HashValue>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } 
	return (((GenericContainerInterface::MTable*) (o_->_vtableCls + 1))[-1].GenericContainerInterface_GetHashValue(o_));
}
template <typename S, typename T_> MAXON_ATTRIBUTE_FORCE_INLINE auto GenericContainerInterface::Hxx1::ConstFn<S, T_>::IsEqual(const GenericContainerInterface* other, EQUALITY equality) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const GenericContainerInterface* o_ = (const GenericContainerInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = GenericContainerInterface::NullValuePtr(); if (!o_) return maxon::PrivateLogNullptrError(false); } 
	return (((GenericContainerInterface::MTable*) (o_->_vtableCls + 1))[-1].GenericContainerInterface_IsEqual(o_, other, equality));
}
template <typename S, typename T_> MAXON_ATTRIBUTE_FORCE_INLINE auto GenericContainerInterface::Hxx1::ConstFn<S, T_>::FindMemberIndex(const InternedId& name) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const GenericContainerInterface* o_ = (const GenericContainerInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = GenericContainerInterface::NullValuePtr(); if (!o_) return -1; } 
	return (((GenericContainerInterface::MTable*) (o_->_vtableCls + 1))[-1].GenericContainerInterface_FindMemberIndex(o_, name));
}
template <typename S, typename T_> MAXON_ATTRIBUTE_FORCE_INLINE auto GenericContainerInterface::Hxx1::ConstFn<S, T_>::FindMemberIndex(const Member& member) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const GenericContainerInterface* o_ = (const GenericContainerInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = GenericContainerInterface::NullValuePtr(); if (!o_) return 0; } 
	return (o_->FindMemberIndex(member));
}
template <typename S, typename T_> MAXON_ATTRIBUTE_FORCE_INLINE auto GenericContainerInterface::Hxx1::ConstFn<S, T_>::GetCount() const -> Result<Int>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<Int>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const GenericContainerInterface* o_ = (const GenericContainerInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = GenericContainerInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (((GenericContainerInterface::MTable*) (o_->_vtableCls + 1))[-1].GenericContainerInterface_GetCount(o_));
}

struct GenericIndexableContainerInterface::MTable
{
	MTable() { }
	template <typename C> explicit MTable(C*) { Init<typename maxon::SFINAEHelper<Hxx2, C>::type::template Wrapper<C>>(); }
	template <typename C> MTable(C*, maxon::Bool) { Init<C>(); }
	PRIVATE_MAXON_ALLOC_TYPENAME GenericContainerInterface::MTable super;
	template <typename IMPL> void Init()
	{
		super.template Init<IMPL>();
	}
	template <typename W> static maxon::Bool InitWithBases(maxon::ClassInfo* info, maxon::Int offset) { return true; }
	template <typename S> using CombinedMTable = S;
};

struct GenericIndexableContainerInterface::Hxx2
{
	template <typename C> using CWrapper = C;
	template <typename C> class Wrapper : public GenericContainerInterface::Hxx2::Wrapper<C>
	{
	public:
	};

};

GenericIndexableContainerInterface::GenericIndexableContainerInterface(const MTable& vtable) : GenericContainerInterface(vtable.super) { }
#endif

#ifdef MAXON_COMPILER_GCC
	#pragma GCC diagnostic pop
#endif

#endif

