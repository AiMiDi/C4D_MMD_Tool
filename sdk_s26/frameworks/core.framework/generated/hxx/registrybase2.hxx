
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
	static const maxon::NULL_RETURN_TYPE _returnTypes[];
	static const maxon::Bool HAS_NONSTATIC = true;
	void (*RegistryEntryIteratorInterface_Free) (const RegistryEntryIteratorInterface* iterator);
	Bool (*RegistryEntryIteratorInterface_HasValue) (const RegistryEntryIteratorInterface* this_);
	void (*RegistryEntryIteratorInterface_MoveToNext) (RegistryEntryIteratorInterface* this_);
	const Id& (*RegistryEntryIteratorInterface_GetId) (const RegistryEntryIteratorInterface* this_);
	ConstDataPtr (*RegistryEntryIteratorInterface_GetEntry) (const RegistryEntryIteratorInterface* this_);
	template <typename IMPL> void Init()
	{
		RegistryEntryIteratorInterface_Free = &IMPL::RegistryEntryIteratorInterface_Free;
		RegistryEntryIteratorInterface_HasValue = &IMPL::RegistryEntryIteratorInterface_HasValue;
		RegistryEntryIteratorInterface_MoveToNext = &IMPL::RegistryEntryIteratorInterface_MoveToNext;
		RegistryEntryIteratorInterface_GetId = &IMPL::RegistryEntryIteratorInterface_GetId;
		RegistryEntryIteratorInterface_GetEntry = &IMPL::RegistryEntryIteratorInterface_GetEntry;
	}
};

struct RegistryEntryIteratorInterface::Hxx2
{
	class Unresolved;
	template <typename C> class Wrapper
	{
	public:
		static void RegistryEntryIteratorInterface_Free(const RegistryEntryIteratorInterface* iterator) { return C::Free(iterator); }
		static Bool RegistryEntryIteratorInterface_HasValue(const RegistryEntryIteratorInterface* this_) { return C::Get(this_)->HasValue(); }
		static void RegistryEntryIteratorInterface_MoveToNext(RegistryEntryIteratorInterface* this_) { return C::Get(this_)->MoveToNext(); }
		static const Id& RegistryEntryIteratorInterface_GetId(const RegistryEntryIteratorInterface* this_) { return C::Get(this_)->GetId(); }
		static ConstDataPtr RegistryEntryIteratorInterface_GetEntry(const RegistryEntryIteratorInterface* this_) { return C::Get(this_)->GetEntry(); }
	};

};
MAXON_ATTRIBUTE_FORCE_INLINE auto RegistryEntryIteratorInterface::Free(const RegistryEntryIteratorInterface* iterator) -> void
{
	return MTable::_instance.RegistryEntryIteratorInterface_Free(iterator);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto RegistryEntryIteratorInterface::HasValue() const -> Bool
{
	return MTable::_instance.RegistryEntryIteratorInterface_HasValue(this);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto RegistryEntryIteratorInterface::MoveToNext() -> void
{
	return MTable::_instance.RegistryEntryIteratorInterface_MoveToNext(this);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto RegistryEntryIteratorInterface::GetId() const -> const Id&
{
	return MTable::_instance.RegistryEntryIteratorInterface_GetId(this);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto RegistryEntryIteratorInterface::GetEntry() const -> ConstDataPtr
{
	return MTable::_instance.RegistryEntryIteratorInterface_GetEntry(this);
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
	static const maxon::NULL_RETURN_TYPE _returnTypes[];
	static const maxon::Bool HAS_NONSTATIC = true;
	const Id& (*RegistryInterface_GetId) (const RegistryInterface* this_);
	UInt (*RegistryInterface_GetStamp) (const RegistryInterface* this_);
	const DataType& (*RegistryInterface_GetDataType) (const RegistryInterface* this_);
	Result<GenericData> (*RegistryInterface_AddObserver) (const RegistryInterface* this_, Delegate<void(const Id&eid,const ConstDataPtr&value,Bool inserted)>&& observer, Bool notifyDuringRegistration);
	const RegistryInterface* (*RegistryInterface_Find) (const Id& registry);
	Result<void> (*RegistryInterface_InsertEntry) (const RegistryInterface* registry, const Id& eid, ForwardingDataPtr&& value, const ModuleInfo* module);
	Result<Bool> (*RegistryInterface_EraseEntry) (const RegistryInterface* registry, const Id& eid);
	Result<GenericData> (*RegistryInterface_Register) (const RegistryInterface* registry, const Id& eid, ForwardingDataPtr&& value);
	ConstDataPtr (*RegistryInterface_FindEntryValue) (const RegistryInterface* registry, const Id& eid);
	RegistryEntryIteratorInterface* (*RegistryInterface_PrivateCreateIterator) (const RegistryInterface* registry);
	template <typename IMPL> void Init()
	{
		RegistryInterface_GetId = &IMPL::RegistryInterface_GetId;
		RegistryInterface_GetStamp = &IMPL::RegistryInterface_GetStamp;
		RegistryInterface_GetDataType = &IMPL::RegistryInterface_GetDataType;
		RegistryInterface_AddObserver = &IMPL::RegistryInterface_AddObserver;
		RegistryInterface_Find = &IMPL::RegistryInterface_Find;
		RegistryInterface_InsertEntry = &IMPL::RegistryInterface_InsertEntry;
		RegistryInterface_EraseEntry = &IMPL::RegistryInterface_EraseEntry;
		RegistryInterface_Register = &IMPL::RegistryInterface_Register;
		RegistryInterface_FindEntryValue = &IMPL::RegistryInterface_FindEntryValue;
		RegistryInterface_PrivateCreateIterator = &IMPL::RegistryInterface_PrivateCreateIterator;
	}
};

struct RegistryInterface::Hxx2
{
	class Unresolved;
	template <typename C> class Wrapper
	{
	public:
		static const Id& RegistryInterface_GetId(const RegistryInterface* this_) { return C::Get(this_)->GetId(); }
		static UInt RegistryInterface_GetStamp(const RegistryInterface* this_) { return C::Get(this_)->GetStamp(); }
		static const DataType& RegistryInterface_GetDataType(const RegistryInterface* this_) { return C::Get(this_)->GetDataType(); }
		static Result<GenericData> RegistryInterface_AddObserver(const RegistryInterface* this_, Delegate<void(const Id&eid,const ConstDataPtr&value,Bool inserted)>&& observer, Bool notifyDuringRegistration) { return C::Get(this_)->AddObserver(std::forward<Delegate<void(const Id&eid,const ConstDataPtr&value,Bool inserted)>>(observer), notifyDuringRegistration); }
		static const RegistryInterface* RegistryInterface_Find(const Id& registry) { return C::Find(registry); }
		static Result<void> RegistryInterface_InsertEntry(const RegistryInterface* registry, const Id& eid, ForwardingDataPtr&& value, const ModuleInfo* module) { return C::InsertEntry(registry, eid, std::forward<ForwardingDataPtr>(value), module); }
		static Result<Bool> RegistryInterface_EraseEntry(const RegistryInterface* registry, const Id& eid) { return C::EraseEntry(registry, eid); }
		static Result<GenericData> RegistryInterface_Register(const RegistryInterface* registry, const Id& eid, ForwardingDataPtr&& value) { return C::Register(registry, eid, std::forward<ForwardingDataPtr>(value)); }
		static ConstDataPtr RegistryInterface_FindEntryValue(const RegistryInterface* registry, const Id& eid) { return C::FindEntryValue(registry, eid); }
		static RegistryEntryIteratorInterface* RegistryInterface_PrivateCreateIterator(const RegistryInterface* registry) { return C::PrivateCreateIterator(registry); }
	};

};
MAXON_ATTRIBUTE_FORCE_INLINE auto RegistryInterface::GetId() const -> const Id&
{
	return MTable::_instance.RegistryInterface_GetId(this);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto RegistryInterface::GetStamp() const -> UInt
{
	return MTable::_instance.RegistryInterface_GetStamp(this);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto RegistryInterface::GetDataType() const -> const DataType&
{
	return MTable::_instance.RegistryInterface_GetDataType(this);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto RegistryInterface::AddObserver(Delegate<void(const Id&eid,const ConstDataPtr&value,Bool inserted)>&& observer, Bool notifyDuringRegistration) const -> Result<GenericData>
{
	return MTable::_instance.RegistryInterface_AddObserver(this, std::forward<Delegate<void(const Id&eid,const ConstDataPtr&value,Bool inserted)>>(observer), notifyDuringRegistration);
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

