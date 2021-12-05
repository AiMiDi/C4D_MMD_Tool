
#ifndef DOXYGEN

#ifdef MAXON_COMPILER_GCC
	#pragma GCC diagnostic push
	#pragma GCC diagnostic ignored "-Wmisleading-indentation"
#endif

#if 1
/// @cond INTERNAL


struct RegistryEntryIteratorInterface::MTable
{
	static MTable _instance;
	static MTable _unresolvedInstance;
	static const maxon::Char* const _ids;
	static maxon::Bool InitUnresolved(maxon::NonvirtualInterfaceReference::UnresolvedAssembler assembler, MTable* tbl);
	static const maxon::NULL_RETURN_TYPE _returnTypes[];
	static const maxon::Bool HAS_NONSTATIC = true;
	void (*_RegistryEntryIteratorInterface_Free) (const RegistryEntryIteratorInterface* iterator);
	Bool (*_RegistryEntryIteratorInterface_HasValue) (const RegistryEntryIteratorInterface* this_);
	void (*_RegistryEntryIteratorInterface_MoveToNext) (RegistryEntryIteratorInterface* this_);
	const Id& (*_RegistryEntryIteratorInterface_GetId) (const RegistryEntryIteratorInterface* this_);
	ConstDataPtr (*_RegistryEntryIteratorInterface_GetEntry) (const RegistryEntryIteratorInterface* this_);
	template <typename IMPL> static void Init(MTable* tbl)
	{
		tbl->_RegistryEntryIteratorInterface_Free = &IMPL::_RegistryEntryIteratorInterface_Free;
		tbl->_RegistryEntryIteratorInterface_HasValue = &IMPL::_RegistryEntryIteratorInterface_HasValue;
		tbl->_RegistryEntryIteratorInterface_MoveToNext = &IMPL::_RegistryEntryIteratorInterface_MoveToNext;
		tbl->_RegistryEntryIteratorInterface_GetId = &IMPL::_RegistryEntryIteratorInterface_GetId;
		tbl->_RegistryEntryIteratorInterface_GetEntry = &IMPL::_RegistryEntryIteratorInterface_GetEntry;
	}
};

template <typename C> class RegistryEntryIteratorInterface::Wrapper
{
public:
	static void _RegistryEntryIteratorInterface_Free(const RegistryEntryIteratorInterface* iterator) { return C::Free(iterator); }
	static Bool _RegistryEntryIteratorInterface_HasValue(const RegistryEntryIteratorInterface* this_) { return ((const C*) this_)->HasValue(); }
	static void _RegistryEntryIteratorInterface_MoveToNext(RegistryEntryIteratorInterface* this_) { return ((C*) this_)->MoveToNext(); }
	static const Id& _RegistryEntryIteratorInterface_GetId(const RegistryEntryIteratorInterface* this_) { return ((const C*) this_)->GetId(); }
	static ConstDataPtr _RegistryEntryIteratorInterface_GetEntry(const RegistryEntryIteratorInterface* this_) { return ((const C*) this_)->GetEntry(); }
};

MAXON_ATTRIBUTE_FORCE_INLINE auto RegistryEntryIteratorInterface::Free(const RegistryEntryIteratorInterface* iterator) -> void
{
	return MTable::_instance._RegistryEntryIteratorInterface_Free(iterator);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto RegistryEntryIteratorInterface::HasValue() const -> Bool
{
	return MTable::_instance._RegistryEntryIteratorInterface_HasValue(this);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto RegistryEntryIteratorInterface::MoveToNext() -> void
{
	return MTable::_instance._RegistryEntryIteratorInterface_MoveToNext(this);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto RegistryEntryIteratorInterface::GetId() const -> const Id&
{
	return MTable::_instance._RegistryEntryIteratorInterface_GetId(this);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto RegistryEntryIteratorInterface::GetEntry() const -> ConstDataPtr
{
	return MTable::_instance._RegistryEntryIteratorInterface_GetEntry(this);
}

#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT)
static maxon::EntityUse s_ui_maxon_RegistryEntryIteratorInterface(RegistryEntryIteratorInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/registrybase.h", false);
#endif

struct RegistryInterface::MTable
{
	static MTable _instance;
	static MTable _unresolvedInstance;
	static const maxon::Char* const _ids;
	static maxon::Bool InitUnresolved(maxon::NonvirtualInterfaceReference::UnresolvedAssembler assembler, MTable* tbl);
	static const maxon::NULL_RETURN_TYPE _returnTypes[];
	static const maxon::Bool HAS_NONSTATIC = true;
	const Id& (*_RegistryInterface_GetId) (const RegistryInterface* this_);
	UInt (*_RegistryInterface_GetStamp) (const RegistryInterface* this_);
	const DataType* (*_RegistryInterface_GetDataType) (const RegistryInterface* this_);
	const RegistryInterface* (*_RegistryInterface_Find) (const Id& registry);
	Result<void> (*_RegistryInterface_InsertEntry) (const RegistryInterface* registry, const Id& eid, ForwardingDataPtr&& value, const ModuleInfo* module);
	Result<Bool> (*_RegistryInterface_EraseEntry) (const RegistryInterface* registry, const Id& eid);
	ConstDataPtr (*_RegistryInterface_FindEntryValue) (const RegistryInterface* registry, const Id& eid);
	RegistryEntryIteratorInterface* (*_RegistryInterface_PrivateCreateIterator) (const RegistryInterface* registry);
	template <typename IMPL> static void Init(MTable* tbl)
	{
		tbl->_RegistryInterface_GetId = &IMPL::_RegistryInterface_GetId;
		tbl->_RegistryInterface_GetStamp = &IMPL::_RegistryInterface_GetStamp;
		tbl->_RegistryInterface_GetDataType = &IMPL::_RegistryInterface_GetDataType;
		tbl->_RegistryInterface_Find = &IMPL::_RegistryInterface_Find;
		tbl->_RegistryInterface_InsertEntry = &IMPL::_RegistryInterface_InsertEntry;
		tbl->_RegistryInterface_EraseEntry = &IMPL::_RegistryInterface_EraseEntry;
		tbl->_RegistryInterface_FindEntryValue = &IMPL::_RegistryInterface_FindEntryValue;
		tbl->_RegistryInterface_PrivateCreateIterator = &IMPL::_RegistryInterface_PrivateCreateIterator;
	}
};

template <typename C> class RegistryInterface::Wrapper
{
public:
	static const Id& _RegistryInterface_GetId(const RegistryInterface* this_) { return ((const C*) this_)->GetId(); }
	static UInt _RegistryInterface_GetStamp(const RegistryInterface* this_) { return ((const C*) this_)->GetStamp(); }
	static const DataType* _RegistryInterface_GetDataType(const RegistryInterface* this_) { return ((const C*) this_)->GetDataType(); }
	static const RegistryInterface* _RegistryInterface_Find(const Id& registry) { return C::Find(registry); }
	static Result<void> _RegistryInterface_InsertEntry(const RegistryInterface* registry, const Id& eid, ForwardingDataPtr&& value, const ModuleInfo* module) { return C::InsertEntry(registry, eid, std::forward<ForwardingDataPtr>(value), module); }
	static Result<Bool> _RegistryInterface_EraseEntry(const RegistryInterface* registry, const Id& eid) { return C::EraseEntry(registry, eid); }
	static ConstDataPtr _RegistryInterface_FindEntryValue(const RegistryInterface* registry, const Id& eid) { return C::FindEntryValue(registry, eid); }
	static RegistryEntryIteratorInterface* _RegistryInterface_PrivateCreateIterator(const RegistryInterface* registry) { return C::PrivateCreateIterator(registry); }
};

MAXON_ATTRIBUTE_FORCE_INLINE auto RegistryInterface::GetId() const -> const Id&
{
	return MTable::_instance._RegistryInterface_GetId(this);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto RegistryInterface::GetStamp() const -> UInt
{
	return MTable::_instance._RegistryInterface_GetStamp(this);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto RegistryInterface::GetDataType() const -> const DataType*
{
	return MTable::_instance._RegistryInterface_GetDataType(this);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto RegistryInterface::Find(const Id& registry) -> const RegistryInterface*
{
	return MTable::_instance._RegistryInterface_Find(registry);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto RegistryInterface::InsertEntry(const RegistryInterface* registry, const Id& eid, ForwardingDataPtr&& value, const ModuleInfo* module) -> Result<void>
{
	return MTable::_instance._RegistryInterface_InsertEntry(registry, eid, std::forward<ForwardingDataPtr>(value), module);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto RegistryInterface::EraseEntry(const RegistryInterface* registry, const Id& eid) -> Result<Bool>
{
	return MTable::_instance._RegistryInterface_EraseEntry(registry, eid);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto RegistryInterface::FindEntryValue(const RegistryInterface* registry, const Id& eid) -> ConstDataPtr
{
	return MTable::_instance._RegistryInterface_FindEntryValue(registry, eid);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto RegistryInterface::PrivateCreateIterator(const RegistryInterface* registry) -> RegistryEntryIteratorInterface*
{
	return MTable::_instance._RegistryInterface_PrivateCreateIterator(registry);
}

#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT)
static maxon::EntityUse s_ui_maxon_RegistryInterface(RegistryInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/registrybase.h", false);
#endif
/// @endcond

#if defined(MAXON_COMPILER_INTEL) || defined(MAXON_COMPILER_GCC)
#else
#endif
#endif

#ifdef MAXON_COMPILER_GCC
	#pragma GCC diagnostic pop
#endif

#endif

