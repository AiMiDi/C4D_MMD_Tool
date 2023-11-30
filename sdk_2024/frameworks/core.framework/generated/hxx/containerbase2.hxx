
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
	PRIVATE_MAXON_MF_POINTER(GenericContainerInterface_GetContainerType, GetContainerType, false, GenericContainerInterface, const, (const ContainerDataType<>&));
	PRIVATE_MAXON_MF_POINTER(GenericContainerInterface_GetInterfaces, GetInterfaces, false, GenericContainerInterface, const, (INTERFACES));
	PRIVATE_MAXON_MF_POINTER(GenericContainerInterface_MakeWritable, MakeWritable, false, GenericContainerInterface, const, (Result<GenericContainerInterface*>), Bool copyContent);
	PRIVATE_MAXON_MF_POINTER(GenericContainerInterface_ToString, ToString, false, GenericContainerInterface, const, (String), const FormatStatement* formatStatement);
	PRIVATE_MAXON_MF_POINTER(GenericContainerInterface_GetHashCode, GetHashCode, false, GenericContainerInterface, const, (HashInt));
	PRIVATE_MAXON_MF_POINTER(GenericContainerInterface_GetUniqueHashCode, GetUniqueHashCode, false, GenericContainerInterface, const, (UniqueHash));
	PRIVATE_MAXON_MF_POINTER(GenericContainerInterface_IsEqual, IsEqual, false, GenericContainerInterface, const, (Bool), const GenericContainerInterface* other, EQUALITY equality);
	PRIVATE_MAXON_MF_POINTER(GenericContainerInterface_FindMemberIndex, FindMemberIndex, false, GenericContainerInterface, const, (Int), const InternedId& name);
	PRIVATE_MAXON_MF_POINTER(GenericContainerInterface_GetCount, GetCount, false, GenericContainerInterface, const, (Result<Int>));
	PRIVATE_MAXON_MF_POINTER(GenericContainerInterface_GetIteratorStateSize, GetIteratorStateSize, false, GenericContainerInterface, const, (Int), const MemberMap* map);
	PRIVATE_MAXON_MF_POINTER(GenericContainerInterface_InitIterator, InitIterator, false, GenericContainerInterface, const, (Result<Int>), ViewIteratorMember* members, const MemberMap* map, Char* state, PersistentIdBuffer* idBuffer, ITERATOR_ACCESS access);
	PRIVATE_MAXON_MF_POINTER(GenericContainerInterface_ValidateIterator, ValidateIterator, false, GenericContainerInterface, const, (Result<Int>), Int index, ViewIteratorMember* members, const MemberMap* map, Char* state, PersistentIdBuffer* idBuffer);
	PRIVATE_MAXON_MF_POINTER(GenericContainerInterface_FreeIterator, FreeIterator, false, GenericContainerInterface, const, (void), ViewIteratorMember* members, const MemberMap* map, Char* state, PersistentIdBuffer* idBuffer);
	PRIVATE_MAXON_MF_POINTER(GenericContainerInterface_MoveIterator, MoveIterator, false, GenericContainerInterface, const, (Result<Int>), Int index, ViewIteratorMember* members, const MemberMap* map, Char* state, PersistentIdBuffer* idBuffer);
	PRIVATE_MAXON_MF_POINTER(GenericContainerInterface_AdvancePersistentId, AdvancePersistentId, false, GenericContainerInterface, const, (Result<void>), Int index, const Char* state, PersistentIdBuffer& idBuffer);
	void* _MAXON_METHOD_RESERVE22;
	void* _MAXON_METHOD_RESERVE23;
	void* _MAXON_METHOD_RESERVE24;
	maxon::ClassInfoBase _info;
	template <typename IMPL> void Init()
	{
		void (*free) (const GenericContainerInterface*) = &IMPL::Implementation::Free;
		_info._free = reinterpret_cast<void(*)(const void*)>(free);
		_info.PrivateInitName(maxon::details::GetTypeNameHelper<typename IMPL::Implementation>());
		GenericContainerInterface_GetContainerType = GenericContainerInterface_GetContainerType_GetPtr<IMPL>(0, true).first;
		GenericContainerInterface_GetInterfaces = GenericContainerInterface_GetInterfaces_GetPtr<IMPL>(0, true).first;
		GenericContainerInterface_MakeWritable = GenericContainerInterface_MakeWritable_GetPtr<IMPL>(0, true).first;
		GenericContainerInterface_ToString = GenericContainerInterface_ToString_GetPtr<IMPL>(0, true).first;
		GenericContainerInterface_GetHashCode = GenericContainerInterface_GetHashCode_GetPtr<IMPL>(0, true).first;
		GenericContainerInterface_GetUniqueHashCode = GenericContainerInterface_GetUniqueHashCode_GetPtr<IMPL>(0, true).first;
		GenericContainerInterface_IsEqual = GenericContainerInterface_IsEqual_GetPtr<IMPL>(0, true).first;
		GenericContainerInterface_FindMemberIndex = GenericContainerInterface_FindMemberIndex_GetPtr<IMPL>(0, true).first;
		GenericContainerInterface_GetCount = GenericContainerInterface_GetCount_GetPtr<IMPL>(0, true).first;
		GenericContainerInterface_GetIteratorStateSize = GenericContainerInterface_GetIteratorStateSize_GetPtr<IMPL>(0, true).first;
		GenericContainerInterface_InitIterator = GenericContainerInterface_InitIterator_GetPtr<IMPL>(0, true).first;
		GenericContainerInterface_ValidateIterator = GenericContainerInterface_ValidateIterator_GetPtr<IMPL>(0, true).first;
		GenericContainerInterface_FreeIterator = GenericContainerInterface_FreeIterator_GetPtr<IMPL>(0, true).first;
		GenericContainerInterface_MoveIterator = GenericContainerInterface_MoveIterator_GetPtr<IMPL>(0, true).first;
		GenericContainerInterface_AdvancePersistentId = GenericContainerInterface_AdvancePersistentId_GetPtr<IMPL>(0, true).first;
		_MAXON_METHOD_RESERVE22 = nullptr;
		_MAXON_METHOD_RESERVE23 = nullptr;
		_MAXON_METHOD_RESERVE24 = nullptr;
	}
	template <typename W> static maxon::Bool InitWithBases(maxon::ClassInfo* info, maxon::Int offset) { return true; }
	template <typename S> using CombinedMTable = S;
};

struct GenericContainerInterface::Hxx2
{
	template <typename C> using CWrapper = C;
	template <typename S> class Wrapper
	{
	public:
		using Implementation = S;
		PRIVATE_MAXON_MF_WRAPPER(GenericContainerInterface_GetContainerType, GenericContainerInterface, const, (const ContainerDataType<>&)) { return S::Get(PRIVATE_MAXON_MF_THIS(const GenericContainerInterface))->GetContainerType(); }
		PRIVATE_MAXON_MF_WRAPPER(GenericContainerInterface_GetInterfaces, GenericContainerInterface, const, (INTERFACES)) { return S::Get(PRIVATE_MAXON_MF_THIS(const GenericContainerInterface))->GetInterfaces(); }
		PRIVATE_MAXON_MF_WRAPPER(GenericContainerInterface_MakeWritable, GenericContainerInterface, const, (Result<GenericContainerInterface*>), Bool copyContent) { return S::Get(PRIVATE_MAXON_MF_THIS(const GenericContainerInterface))->MakeWritable(copyContent); }
		PRIVATE_MAXON_MF_WRAPPER(GenericContainerInterface_ToString, GenericContainerInterface, const, (String), const FormatStatement* formatStatement) { return S::Get(PRIVATE_MAXON_MF_THIS(const GenericContainerInterface))->ToString(formatStatement); }
		PRIVATE_MAXON_MF_WRAPPER(GenericContainerInterface_GetHashCode, GenericContainerInterface, const, (HashInt)) { return S::Get(PRIVATE_MAXON_MF_THIS(const GenericContainerInterface))->GetHashCode(); }
		PRIVATE_MAXON_MF_WRAPPER(GenericContainerInterface_GetUniqueHashCode, GenericContainerInterface, const, (UniqueHash)) { return S::Get(PRIVATE_MAXON_MF_THIS(const GenericContainerInterface))->GetUniqueHashCode(); }
		PRIVATE_MAXON_MF_WRAPPER(GenericContainerInterface_IsEqual, GenericContainerInterface, const, (Bool), const GenericContainerInterface* other, EQUALITY equality) { return S::Get(PRIVATE_MAXON_MF_THIS(const GenericContainerInterface))->IsEqual(other, equality); }
		PRIVATE_MAXON_MF_WRAPPER(GenericContainerInterface_FindMemberIndex, GenericContainerInterface, const, (Int), const InternedId& name) { return S::Get(PRIVATE_MAXON_MF_THIS(const GenericContainerInterface))->FindMemberIndex(name); }
		PRIVATE_MAXON_MF_WRAPPER(GenericContainerInterface_GetCount, GenericContainerInterface, const, (Result<Int>)) { return S::Get(PRIVATE_MAXON_MF_THIS(const GenericContainerInterface))->GetCount(); }
		PRIVATE_MAXON_MF_WRAPPER(GenericContainerInterface_GetIteratorStateSize, GenericContainerInterface, const, (Int), const MemberMap* map) { return S::Get(PRIVATE_MAXON_MF_THIS(const GenericContainerInterface))->GetIteratorStateSize(map); }
		PRIVATE_MAXON_MF_WRAPPER(GenericContainerInterface_InitIterator, GenericContainerInterface, const, (Result<Int>), ViewIteratorMember* members, const MemberMap* map, Char* state, PersistentIdBuffer* idBuffer, ITERATOR_ACCESS access) { return S::Get(PRIVATE_MAXON_MF_THIS(const GenericContainerInterface))->InitIterator(members, map, state, idBuffer, access); }
		PRIVATE_MAXON_MF_WRAPPER(GenericContainerInterface_ValidateIterator, GenericContainerInterface, const, (Result<Int>), Int index, ViewIteratorMember* members, const MemberMap* map, Char* state, PersistentIdBuffer* idBuffer) { return S::Get(PRIVATE_MAXON_MF_THIS(const GenericContainerInterface))->ValidateIterator(index, members, map, state, idBuffer); }
		PRIVATE_MAXON_MF_WRAPPER(GenericContainerInterface_FreeIterator, GenericContainerInterface, const, (void), ViewIteratorMember* members, const MemberMap* map, Char* state, PersistentIdBuffer* idBuffer) { return S::Get(PRIVATE_MAXON_MF_THIS(const GenericContainerInterface))->FreeIterator(members, map, state, idBuffer); }
		PRIVATE_MAXON_MF_WRAPPER(GenericContainerInterface_MoveIterator, GenericContainerInterface, const, (Result<Int>), Int index, ViewIteratorMember* members, const MemberMap* map, Char* state, PersistentIdBuffer* idBuffer) { return S::Get(PRIVATE_MAXON_MF_THIS(const GenericContainerInterface))->MoveIterator(index, members, map, state, idBuffer); }
		PRIVATE_MAXON_MF_WRAPPER(GenericContainerInterface_AdvancePersistentId, GenericContainerInterface, const, (Result<void>), Int index, const Char* state, PersistentIdBuffer& idBuffer) { return S::Get(PRIVATE_MAXON_MF_THIS(const GenericContainerInterface))->AdvancePersistentId(index, state, idBuffer); }
	};

};
MAXON_ATTRIBUTE_FORCE_INLINE auto GenericContainerInterface::GetContainerType() const -> const ContainerDataType<>&
{
	return PRIVATE_MAXON_MF_INVOKE((this), ((GenericContainerInterface::MTable*) (this->_vtableCls + 1))[-1].GenericContainerInterface_GetContainerType);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto GenericContainerInterface::GetInterfaces() const -> INTERFACES
{
	return PRIVATE_MAXON_MF_INVOKE((this), ((GenericContainerInterface::MTable*) (this->_vtableCls + 1))[-1].GenericContainerInterface_GetInterfaces);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto GenericContainerInterface::MakeWritable(Bool copyContent) const -> Result<GenericContainerInterface*>
{
	return PRIVATE_MAXON_MF_INVOKE((this), ((GenericContainerInterface::MTable*) (this->_vtableCls + 1))[-1].GenericContainerInterface_MakeWritable, copyContent);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto GenericContainerInterface::ToString(const FormatStatement* formatStatement) const -> String
{
	return PRIVATE_MAXON_MF_INVOKE((this), ((GenericContainerInterface::MTable*) (this->_vtableCls + 1))[-1].GenericContainerInterface_ToString, formatStatement);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto GenericContainerInterface::GetHashCode() const -> HashInt
{
	return PRIVATE_MAXON_MF_INVOKE((this), ((GenericContainerInterface::MTable*) (this->_vtableCls + 1))[-1].GenericContainerInterface_GetHashCode);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto GenericContainerInterface::GetUniqueHashCode() const -> UniqueHash
{
	return PRIVATE_MAXON_MF_INVOKE((this), ((GenericContainerInterface::MTable*) (this->_vtableCls + 1))[-1].GenericContainerInterface_GetUniqueHashCode);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto GenericContainerInterface::IsEqual(const GenericContainerInterface* other, EQUALITY equality) const -> Bool
{
	return PRIVATE_MAXON_MF_INVOKE((this), ((GenericContainerInterface::MTable*) (this->_vtableCls + 1))[-1].GenericContainerInterface_IsEqual, other, equality);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto GenericContainerInterface::FindMemberIndex(const InternedId& name) const -> Int
{
	return PRIVATE_MAXON_MF_INVOKE((this), ((GenericContainerInterface::MTable*) (this->_vtableCls + 1))[-1].GenericContainerInterface_FindMemberIndex, name);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto GenericContainerInterface::GetCount() const -> Result<Int>
{
	return PRIVATE_MAXON_MF_INVOKE((this), ((GenericContainerInterface::MTable*) (this->_vtableCls + 1))[-1].GenericContainerInterface_GetCount);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto GenericContainerInterface::GetIteratorStateSize(const MemberMap* map) const -> Int
{
	return PRIVATE_MAXON_MF_INVOKE((this), ((GenericContainerInterface::MTable*) (this->_vtableCls + 1))[-1].GenericContainerInterface_GetIteratorStateSize, map);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto GenericContainerInterface::InitIterator(ViewIteratorMember* members, const MemberMap* map, Char* state, PersistentIdBuffer* idBuffer, ITERATOR_ACCESS access) const -> Result<Int>
{
	return PRIVATE_MAXON_MF_INVOKE((this), ((GenericContainerInterface::MTable*) (this->_vtableCls + 1))[-1].GenericContainerInterface_InitIterator, members, map, state, idBuffer, access);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto GenericContainerInterface::ValidateIterator(Int index, ViewIteratorMember* members, const MemberMap* map, Char* state, PersistentIdBuffer* idBuffer) const -> Result<Int>
{
	return PRIVATE_MAXON_MF_INVOKE((this), ((GenericContainerInterface::MTable*) (this->_vtableCls + 1))[-1].GenericContainerInterface_ValidateIterator, index, members, map, state, idBuffer);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto GenericContainerInterface::FreeIterator(ViewIteratorMember* members, const MemberMap* map, Char* state, PersistentIdBuffer* idBuffer) const -> void
{
	return PRIVATE_MAXON_MF_INVOKE((this), ((GenericContainerInterface::MTable*) (this->_vtableCls + 1))[-1].GenericContainerInterface_FreeIterator, members, map, state, idBuffer);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto GenericContainerInterface::MoveIterator(Int index, ViewIteratorMember* members, const MemberMap* map, Char* state, PersistentIdBuffer* idBuffer) const -> Result<Int>
{
	return PRIVATE_MAXON_MF_INVOKE((this), ((GenericContainerInterface::MTable*) (this->_vtableCls + 1))[-1].GenericContainerInterface_MoveIterator, index, members, map, state, idBuffer);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto GenericContainerInterface::AdvancePersistentId(Int index, const Char* state, PersistentIdBuffer& idBuffer) const -> Result<void>
{
	return PRIVATE_MAXON_MF_INVOKE((this), ((GenericContainerInterface::MTable*) (this->_vtableCls + 1))[-1].GenericContainerInterface_AdvancePersistentId, index, state, idBuffer);
}

GenericContainerInterface::GenericContainerInterface(const MTable& vtable) : _vtableCls(&vtable._info) { }
template <typename S, typename T_> MAXON_ATTRIBUTE_FORCE_INLINE auto GenericContainerInterface::Hxx1::ConstFn<S, T_>::GetContainerType() const -> HXXADDRET2(const ContainerDataType<>&)
{
	HXXRETURN0(HXXADDRET2(const ContainerDataType<>&)); HXXRES; HXXCONST(maxon::PrivateDefaultReturnValue<const ContainerDataType<>&>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK)) 
	return (PRIVATE_MAXON_MF_INVOKE((o_), ((GenericContainerInterface::MTable*) (o_->_vtableCls + 1))[-1].GenericContainerInterface_GetContainerType));
}
template <typename S, typename T_> MAXON_ATTRIBUTE_FORCE_INLINE auto GenericContainerInterface::Hxx1::ConstFn<S, T_>::GetInterfaces() const -> HXXADDRET2(INTERFACES)
{
	HXXRETURN0(HXXADDRET2(INTERFACES)); HXXRES; HXXCONST(maxon::PrivateDefaultReturnValue<INTERFACES>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK)) 
	return (PRIVATE_MAXON_MF_INVOKE((o_), ((GenericContainerInterface::MTable*) (o_->_vtableCls + 1))[-1].GenericContainerInterface_GetInterfaces));
}
template <typename S, typename T_> MAXON_ATTRIBUTE_FORCE_INLINE auto GenericContainerInterface::Hxx1::ConstFn<S, T_>::ToString(const FormatStatement* formatStatement) const -> HXXADDRET2(String)
{
	HXXRETURN0(HXXADDRET2(String)); HXXRES; HXXCONST(maxon::PrivateDefaultReturnValue<String>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK)) 
	return (PRIVATE_MAXON_MF_INVOKE((o_), ((GenericContainerInterface::MTable*) (o_->_vtableCls + 1))[-1].GenericContainerInterface_ToString, formatStatement));
}
template <typename S, typename T_> MAXON_ATTRIBUTE_FORCE_INLINE auto GenericContainerInterface::Hxx1::ConstFn<S, T_>::IsEqual(const GenericContainerInterface* other, EQUALITY equality) const -> HXXADDRET2(Bool)
{
	HXXRETURN0(HXXADDRET2(Bool)); HXXRES; HXXCONST(maxon::PrivateLogNullptrError(false)) 
	return (PRIVATE_MAXON_MF_INVOKE((o_), ((GenericContainerInterface::MTable*) (o_->_vtableCls + 1))[-1].GenericContainerInterface_IsEqual, other, equality));
}
template <typename S, typename T_> MAXON_ATTRIBUTE_FORCE_INLINE auto GenericContainerInterface::Hxx1::ConstFn<S, T_>::FindMemberIndex(const InternedId& name) const -> HXXADDRET2(Int)
{
	HXXRETURN0(HXXADDRET2(Int)); HXXRES; HXXCONST(-1) 
	return (PRIVATE_MAXON_MF_INVOKE((o_), ((GenericContainerInterface::MTable*) (o_->_vtableCls + 1))[-1].GenericContainerInterface_FindMemberIndex, name));
}
template <typename S, typename T_> MAXON_ATTRIBUTE_FORCE_INLINE auto GenericContainerInterface::Hxx1::ConstFn<S, T_>::FindMemberIndex(const Member& member) const -> HXXADDRET2(Int)
{
	HXXRETURN0(HXXADDRET2(Int)); HXXRES; HXXCONST(0) 
	return (o_->FindMemberIndex(member));
}
template <typename S, typename T_> MAXON_ATTRIBUTE_FORCE_INLINE auto GenericContainerInterface::Hxx1::ConstFn<S, T_>::GetCount() const -> Result<Int>
{
	HXXRETURN0(Result<Int>); HXXRES; HXXCONST(0) 
	return (PRIVATE_MAXON_MF_INVOKE((o_), ((GenericContainerInterface::MTable*) (o_->_vtableCls + 1))[-1].GenericContainerInterface_GetCount));
}

struct GenericIndexableContainerInterface::MTable
{
	MTable() { }
	template <typename C> explicit MTable(C*) { Init<typename maxon::SFINAEHelper<Hxx2, C>::type::template Wrapper<C>>(); }
	template <typename C> MTable(C*, maxon::Bool) { Init<C>(); }
	PRIVATE_MAXON_MF_POINTER(GenericIndexableContainerInterface_GetCount, GetCount, false, GenericIndexableContainerInterface, const, (Int));
	void* _MAXON_METHOD_RESERVE3;
	void* _MAXON_METHOD_RESERVE4;
	void* _MAXON_METHOD_RESERVE5;
	typename GenericContainerInterface::MTable super;
	template <typename IMPL> void Init()
	{
		GenericIndexableContainerInterface_GetCount = GenericIndexableContainerInterface_GetCount_GetPtr<IMPL>(0, true).first;
		_MAXON_METHOD_RESERVE3 = nullptr;
		_MAXON_METHOD_RESERVE4 = nullptr;
		_MAXON_METHOD_RESERVE5 = nullptr;
		super.template Init<IMPL>();
	}
	template <typename W> static maxon::Bool InitWithBases(maxon::ClassInfo* info, maxon::Int offset) { return true; }
	template <typename S> using CombinedMTable = S;
};

struct GenericIndexableContainerInterface::Hxx2
{
	template <typename C> using CWrapper = C;
	template <typename S> class Wrapper : public GenericContainerInterface::Hxx2::Wrapper<S>
	{
	public:
		PRIVATE_MAXON_MF_WRAPPER(GenericIndexableContainerInterface_GetCount, GenericIndexableContainerInterface, const, (Int)) { return S::Get(PRIVATE_MAXON_MF_THIS(const GenericIndexableContainerInterface))->GetCount(); }
	};

};
MAXON_ATTRIBUTE_FORCE_INLINE auto GenericIndexableContainerInterface::GetCount() const -> Int
{
	return PRIVATE_MAXON_MF_INVOKE((this), ((GenericIndexableContainerInterface::MTable*) (this->_vtableCls + 1))[-1].GenericIndexableContainerInterface_GetCount);
}

GenericIndexableContainerInterface::GenericIndexableContainerInterface(const MTable& vtable) : GenericContainerInterface(vtable.super) { }
template <typename S, typename T_> MAXON_ATTRIBUTE_FORCE_INLINE auto GenericIndexableContainerInterface::Hxx1::ConstFn<S, T_>::GetCount() const -> HXXADDRET2(Int)
{
	HXXRETURN0(HXXADDRET2(Int)); HXXRES; HXXCONST(0) 
	return (PRIVATE_MAXON_MF_INVOKE((o_), ((GenericIndexableContainerInterface::MTable*) (o_->_vtableCls + 1))[-1].GenericIndexableContainerInterface_GetCount));
}
template <typename S, typename T_> MAXON_ATTRIBUTE_FORCE_INLINE auto GenericIndexableContainerInterface::Hxx1::ConstFn<S, T_>::IsEmpty() const -> HXXADDRET2(Bool)
{
	HXXRETURN0(HXXADDRET2(Bool)); HXXRES; HXXCONST(true) 
	return (o_->IsEmpty());
}
template <typename S, typename T_> MAXON_ATTRIBUTE_FORCE_INLINE auto GenericIndexableContainerInterface::Hxx1::ConstFn<S, T_>::IsPopulated() const -> HXXADDRET2(Bool)
{
	HXXRETURN0(HXXADDRET2(Bool)); HXXRES; HXXCONST(maxon::PrivateLogNullptrError(false)) 
	return (o_->IsPopulated());
}
#endif

#ifdef MAXON_COMPILER_GCC
	#pragma GCC diagnostic pop
#endif

#endif

