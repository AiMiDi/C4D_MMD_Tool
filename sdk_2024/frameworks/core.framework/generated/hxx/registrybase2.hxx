
#ifndef DOXYGEN

#if defined MAXON_COMPILER_GCC
	#pragma GCC diagnostic push
	#if MAXON_COMPILER_GCC >= 600
		#pragma GCC diagnostic ignored "-Wmisleading-indentation"
	#endif
#endif

#if 1
/// @cond INTERNAL

constexpr const maxon::Char* RegistryEntryIteratorInterface::PrivateGetCppName() { return nullptr; }

struct RegistryEntryIteratorInterface::MTable
{
	static MTable _instance;
	static MTable _unresolvedInstance;
	static const maxon::Char* const _ids;
	static maxon::Bool InitUnresolved(maxon::NonvirtualInterfaceReference::UnresolvedAssembler assembler, MTable* tbl);
	static const maxon::UNRESOLVED_RETURN_TYPE _returnTypes[];
	static const maxon::Bool HAS_NONSTATIC = true;
	PRIVATE_MAXON_SF_POINTER(RegistryEntryIteratorInterface_Free, Free, MAXON_EXPAND_VA_ARGS, (void), const RegistryEntryIteratorInterface* iterator);
	PRIVATE_MAXON_MF_POINTER(RegistryEntryIteratorInterface_HasValue, HasValue, false, RegistryEntryIteratorInterface, const, (Bool));
	PRIVATE_MAXON_MF_POINTER(RegistryEntryIteratorInterface_MoveToNext, MoveToNext, false, RegistryEntryIteratorInterface,, (void));
	PRIVATE_MAXON_MF_POINTER(RegistryEntryIteratorInterface_GetId, GetId, false, RegistryEntryIteratorInterface, const, (const Id&));
	PRIVATE_MAXON_MF_POINTER(RegistryEntryIteratorInterface_GetEntry, GetEntry, false, RegistryEntryIteratorInterface, const, (ConstDataPtr));
	template <typename IMPL> void Init()
	{
		RegistryEntryIteratorInterface_Free = RegistryEntryIteratorInterface_Free_GetPtr<IMPL>(true);
		RegistryEntryIteratorInterface_HasValue = RegistryEntryIteratorInterface_HasValue_GetPtr<IMPL>(0, true).first;
		RegistryEntryIteratorInterface_MoveToNext = RegistryEntryIteratorInterface_MoveToNext_GetPtr<IMPL>(0, true).first;
		RegistryEntryIteratorInterface_GetId = RegistryEntryIteratorInterface_GetId_GetPtr<IMPL>(0, true).first;
		RegistryEntryIteratorInterface_GetEntry = RegistryEntryIteratorInterface_GetEntry_GetPtr<IMPL>(0, true).first;
	}
};

struct RegistryEntryIteratorInterface::Hxx2
{
	class Unresolved;
	template <typename S> class Wrapper
	{
	public:
		using Implementation = S;
		static void RegistryEntryIteratorInterface_Free(const RegistryEntryIteratorInterface* iterator) { return S::Free(iterator); }
		PRIVATE_MAXON_MF_WRAPPER(RegistryEntryIteratorInterface_HasValue, RegistryEntryIteratorInterface, const, (Bool)) { return S::Get(PRIVATE_MAXON_MF_THIS(const RegistryEntryIteratorInterface))->HasValue(); }
		PRIVATE_MAXON_MF_WRAPPER(RegistryEntryIteratorInterface_MoveToNext, RegistryEntryIteratorInterface,, (void)) { return S::Get(PRIVATE_MAXON_MF_THIS(RegistryEntryIteratorInterface))->MoveToNext(); }
		PRIVATE_MAXON_MF_WRAPPER(RegistryEntryIteratorInterface_GetId, RegistryEntryIteratorInterface, const, (const Id&)) { return S::Get(PRIVATE_MAXON_MF_THIS(const RegistryEntryIteratorInterface))->GetId(); }
		PRIVATE_MAXON_MF_WRAPPER(RegistryEntryIteratorInterface_GetEntry, RegistryEntryIteratorInterface, const, (ConstDataPtr)) { return S::Get(PRIVATE_MAXON_MF_THIS(const RegistryEntryIteratorInterface))->GetEntry(); }
	};

};
MAXON_ATTRIBUTE_FORCE_INLINE auto RegistryEntryIteratorInterface::Free(const RegistryEntryIteratorInterface* iterator) -> void
{
	return MTable::_instance.RegistryEntryIteratorInterface_Free(iterator);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto RegistryEntryIteratorInterface::HasValue() const -> Bool
{
	return PRIVATE_MAXON_MF_INVOKE((this), MTable::_instance.RegistryEntryIteratorInterface_HasValue);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto RegistryEntryIteratorInterface::MoveToNext() -> void
{
	return PRIVATE_MAXON_MF_INVOKE((this), MTable::_instance.RegistryEntryIteratorInterface_MoveToNext);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto RegistryEntryIteratorInterface::GetId() const -> const Id&
{
	return PRIVATE_MAXON_MF_INVOKE((this), MTable::_instance.RegistryEntryIteratorInterface_GetId);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto RegistryEntryIteratorInterface::GetEntry() const -> ConstDataPtr
{
	return PRIVATE_MAXON_MF_INVOKE((this), MTable::_instance.RegistryEntryIteratorInterface_GetEntry);
}

#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT) && !defined(MAXON_DEPENDENCY_DISABLE_registrybase)
#ifdef MAXON_USE_REGISTER_FUNCTION
MAXON_STATIC_STORAGE(maxon::EntityUse, s_ui_maxon_RegistryEntryIteratorInterface); \
MAXON_ATTRIBUTE_CONSTRUCTOR static void Register_s_ui_maxon_RegistryEntryIteratorInterface() { new (s_ui_maxon_RegistryEntryIteratorInterface) maxon::EntityUse(RegistryEntryIteratorInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/registrybase.h", false); }
#else // !MAXON_USE_REGISTER_FUNCTION
static maxon::EntityUse s_ui_maxon_RegistryEntryIteratorInterface(RegistryEntryIteratorInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/registrybase.h", false);
#endif // MAXON_USE_REGISTER_FUNCTION
#endif
constexpr const maxon::Char* RegistryInterface::PrivateGetCppName() { return nullptr; }

struct RegistryInterface::MTable
{
	static MTable _instance;
	static MTable _unresolvedInstance;
	static const maxon::Char* const _ids;
	static maxon::Bool InitUnresolved(maxon::NonvirtualInterfaceReference::UnresolvedAssembler assembler, MTable* tbl);
	static const maxon::UNRESOLVED_RETURN_TYPE _returnTypes[];
	static const maxon::Bool HAS_NONSTATIC = true;
	PRIVATE_MAXON_MF_POINTER(RegistryInterface_GetId, GetId, false, RegistryInterface, const, (const Id&));
	PRIVATE_MAXON_MF_POINTER(RegistryInterface_GetStamp, GetStamp, false, RegistryInterface, const, (UInt));
	PRIVATE_MAXON_MF_POINTER(RegistryInterface_GetDataType, GetDataType, false, RegistryInterface, const, (const DataType&));
	PRIVATE_MAXON_MF_POINTER(RegistryInterface_AddObserver, AddObserver, false, RegistryInterface, const, (Result<GenericData>), Delegate<void(const Id&eid,const ConstDataPtr&value,Bool inserted)>&& observer, Bool notifyDuringRegistration);
	PRIVATE_MAXON_SF_POINTER(RegistryInterface_Find, Find, MAXON_EXPAND_VA_ARGS, (const RegistryInterface*), const Id& registry);
	PRIVATE_MAXON_SF_POINTER(RegistryInterface_InsertEntry, InsertEntry, MAXON_EXPAND_VA_ARGS, (Result<void>), const RegistryInterface* registry, const Id& eid, ForwardingDataPtr&& value, const ModuleInfo* module);
	PRIVATE_MAXON_SF_POINTER(RegistryInterface_EraseEntry, EraseEntry, MAXON_EXPAND_VA_ARGS, (Result<Bool>), const RegistryInterface* registry, const Id& eid);
	PRIVATE_MAXON_SF_POINTER(RegistryInterface_Register, Register, MAXON_EXPAND_VA_ARGS, (Result<GenericData>), const RegistryInterface* registry, const Id& eid, ForwardingDataPtr&& value);
	PRIVATE_MAXON_SF_POINTER(RegistryInterface_FindEntryValue, FindEntryValue, MAXON_EXPAND_VA_ARGS, (ConstDataPtr), const RegistryInterface* registry, const Id& eid);
	PRIVATE_MAXON_SF_POINTER(RegistryInterface_PrivateCreateIterator, PrivateCreateIterator, MAXON_EXPAND_VA_ARGS, (RegistryEntryIteratorInterface*), const RegistryInterface* registry);
	template <typename IMPL> void Init()
	{
		RegistryInterface_GetId = RegistryInterface_GetId_GetPtr<IMPL>(0, true).first;
		RegistryInterface_GetStamp = RegistryInterface_GetStamp_GetPtr<IMPL>(0, true).first;
		RegistryInterface_GetDataType = RegistryInterface_GetDataType_GetPtr<IMPL>(0, true).first;
		RegistryInterface_AddObserver = RegistryInterface_AddObserver_GetPtr<IMPL>(0, true).first;
		RegistryInterface_Find = RegistryInterface_Find_GetPtr<IMPL>(true);
		RegistryInterface_InsertEntry = RegistryInterface_InsertEntry_GetPtr<IMPL>(true);
		RegistryInterface_EraseEntry = RegistryInterface_EraseEntry_GetPtr<IMPL>(true);
		RegistryInterface_Register = RegistryInterface_Register_GetPtr<IMPL>(true);
		RegistryInterface_FindEntryValue = RegistryInterface_FindEntryValue_GetPtr<IMPL>(true);
		RegistryInterface_PrivateCreateIterator = RegistryInterface_PrivateCreateIterator_GetPtr<IMPL>(true);
	}
};

struct RegistryInterface::Hxx2
{
	class Unresolved;
	template <typename S> class Wrapper
	{
	public:
		using Implementation = S;
		PRIVATE_MAXON_MF_WRAPPER(RegistryInterface_GetId, RegistryInterface, const, (const Id&)) { return S::Get(PRIVATE_MAXON_MF_THIS(const RegistryInterface))->GetId(); }
		PRIVATE_MAXON_MF_WRAPPER(RegistryInterface_GetStamp, RegistryInterface, const, (UInt)) { return S::Get(PRIVATE_MAXON_MF_THIS(const RegistryInterface))->GetStamp(); }
		PRIVATE_MAXON_MF_WRAPPER(RegistryInterface_GetDataType, RegistryInterface, const, (const DataType&)) { return S::Get(PRIVATE_MAXON_MF_THIS(const RegistryInterface))->GetDataType(); }
		PRIVATE_MAXON_MF_WRAPPER(RegistryInterface_AddObserver, RegistryInterface, const, (Result<GenericData>), Delegate<void(const Id&eid,const ConstDataPtr&value,Bool inserted)>&& observer, Bool notifyDuringRegistration) { return S::Get(PRIVATE_MAXON_MF_THIS(const RegistryInterface))->AddObserver(std::forward<Delegate<void(const Id&eid,const ConstDataPtr&value,Bool inserted)>>(observer), notifyDuringRegistration); }
		static const RegistryInterface* RegistryInterface_Find(const Id& registry) { return S::Find(registry); }
		static Result<void> RegistryInterface_InsertEntry(const RegistryInterface* registry, const Id& eid, ForwardingDataPtr&& value, const ModuleInfo* module) { return S::InsertEntry(registry, eid, std::forward<ForwardingDataPtr>(value), module); }
		static Result<Bool> RegistryInterface_EraseEntry(const RegistryInterface* registry, const Id& eid) { return S::EraseEntry(registry, eid); }
		static Result<GenericData> RegistryInterface_Register(const RegistryInterface* registry, const Id& eid, ForwardingDataPtr&& value) { return S::Register(registry, eid, std::forward<ForwardingDataPtr>(value)); }
		static ConstDataPtr RegistryInterface_FindEntryValue(const RegistryInterface* registry, const Id& eid) { return S::FindEntryValue(registry, eid); }
		static RegistryEntryIteratorInterface* RegistryInterface_PrivateCreateIterator(const RegistryInterface* registry) { return S::PrivateCreateIterator(registry); }
	};

};
MAXON_ATTRIBUTE_FORCE_INLINE auto RegistryInterface::GetId() const -> const Id&
{
	return PRIVATE_MAXON_MF_INVOKE((this), MTable::_instance.RegistryInterface_GetId);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto RegistryInterface::GetStamp() const -> UInt
{
	return PRIVATE_MAXON_MF_INVOKE((this), MTable::_instance.RegistryInterface_GetStamp);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto RegistryInterface::GetDataType() const -> const DataType&
{
	return PRIVATE_MAXON_MF_INVOKE((this), MTable::_instance.RegistryInterface_GetDataType);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto RegistryInterface::AddObserver(Delegate<void(const Id&eid,const ConstDataPtr&value,Bool inserted)>&& observer, Bool notifyDuringRegistration) const -> Result<GenericData>
{
	return PRIVATE_MAXON_MF_INVOKE((this), MTable::_instance.RegistryInterface_AddObserver, std::forward<Delegate<void(const Id&eid,const ConstDataPtr&value,Bool inserted)>>(observer), notifyDuringRegistration);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto RegistryInterface::Find(const Id& registry) -> const RegistryInterface*
{
	return MTable::_instance.RegistryInterface_Find(registry);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto RegistryInterface::InsertEntry(const RegistryInterface* registry, const Id& eid, ForwardingDataPtr&& value, const ModuleInfo* module) -> Result<void>
{
	return MTable::_instance.RegistryInterface_InsertEntry(registry, eid, std::forward<ForwardingDataPtr>(value), module);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto RegistryInterface::EraseEntry(const RegistryInterface* registry, const Id& eid) -> Result<Bool>
{
	return MTable::_instance.RegistryInterface_EraseEntry(registry, eid);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto RegistryInterface::Register(const RegistryInterface* registry, const Id& eid, ForwardingDataPtr&& value) -> Result<GenericData>
{
	return MTable::_instance.RegistryInterface_Register(registry, eid, std::forward<ForwardingDataPtr>(value));
}
MAXON_ATTRIBUTE_FORCE_INLINE auto RegistryInterface::FindEntryValue(const RegistryInterface* registry, const Id& eid) -> ConstDataPtr
{
	return MTable::_instance.RegistryInterface_FindEntryValue(registry, eid);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto RegistryInterface::PrivateCreateIterator(const RegistryInterface* registry) -> RegistryEntryIteratorInterface*
{
	return MTable::_instance.RegistryInterface_PrivateCreateIterator(registry);
}

#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT) && !defined(MAXON_DEPENDENCY_DISABLE_registrybase)
#ifdef MAXON_USE_REGISTER_FUNCTION
MAXON_STATIC_STORAGE(maxon::EntityUse, s_ui_maxon_RegistryInterface); \
MAXON_ATTRIBUTE_CONSTRUCTOR static void Register_s_ui_maxon_RegistryInterface() { new (s_ui_maxon_RegistryInterface) maxon::EntityUse(RegistryInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/registrybase.h", false); }
#else // !MAXON_USE_REGISTER_FUNCTION
static maxon::EntityUse s_ui_maxon_RegistryInterface(RegistryInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/registrybase.h", false);
#endif // MAXON_USE_REGISTER_FUNCTION
#endif
/// @endcond

#endif

#ifdef MAXON_COMPILER_GCC
	#pragma GCC diagnostic pop
#endif

#endif

