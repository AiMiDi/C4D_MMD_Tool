
#ifndef DOXYGEN

#if defined MAXON_COMPILER_GCC
	#pragma GCC diagnostic push
	#if MAXON_COMPILER_GCC >= 600
		#pragma GCC diagnostic ignored "-Wmisleading-indentation"
	#endif
#endif

#if 1
constexpr const maxon::Char* System::PrivateGetCppName() { return nullptr; }

struct System::MTable
{
	static MTable _instance;
	static MTable _unresolvedInstance;
	static const maxon::Char* const _ids;
	static maxon::Bool InitUnresolved(maxon::NonvirtualInterfaceReference::UnresolvedAssembler assembler, MTable* tbl);
	static const maxon::NULL_RETURN_TYPE _returnTypes[];
	static const maxon::Bool HAS_NONSTATIC = false;
	PRIVATE_MAXON_SF_POINTER(System__ConsoleOutput, _ConsoleOutput, MAXON_EXPAND_VA_ARGS, (void), const Char* s, const SourceLocation& loc, OUTPUT flags);
	PRIVATE_MAXON_SF_POINTER(System_GetConsoleOutputType, GetConsoleOutputType, MAXON_EXPAND_VA_ARGS, (OUTPUT));
	PRIVATE_MAXON_SF_POINTER(System_Alloc, Alloc, MAXON_EXPAND_VA_ARGS, (void*), Int size, const SourceLocation& location);
	PRIVATE_MAXON_SF_POINTER(System_AllocClear, AllocClear, MAXON_EXPAND_VA_ARGS, (void*), Int size, const SourceLocation& location);
	PRIVATE_MAXON_SF_POINTER(System_Realloc, Realloc, MAXON_EXPAND_VA_ARGS, (void*), void* data, Int size, const SourceLocation& location);
	PRIVATE_MAXON_SF_POINTER(System_Free, Free, MAXON_EXPAND_VA_ARGS, (void), const void* data);
	PRIVATE_MAXON_SF_POINTER(System_GetAllocSize, GetAllocSize, MAXON_EXPAND_VA_ARGS, (Int), void* data);
	PRIVATE_MAXON_SF_POINTER(System_MemoryDiagnostics, MemoryDiagnostics, MAXON_EXPAND_VA_ARGS, (Int), MEMORYDIAGNOSTICSMODE mode, Int* totalAllocation, Int* freePhysicalMemoryEstimate);
	PRIVATE_MAXON_SF_POINTER(System_MemoryAddObserver, MemoryAddObserver, MAXON_EXPAND_VA_ARGS, (Bool), MEMORYOBSERVERMODE mode, Delegate<void()>&& observer);
	PRIVATE_MAXON_SF_POINTER(System_SetMemoryAllocationThreshold, SetMemoryAllocationThreshold, MAXON_EXPAND_VA_ARGS, (void), UInt warnMemoryAllocationThreshold);
	PRIVATE_MAXON_SF_POINTER(System_GetCustomTimer, GetCustomTimer, MAXON_EXPAND_VA_ARGS, (Float64));
	PRIVATE_MAXON_SF_POINTER(System_GetConfigurationCount, GetConfigurationCount, MAXON_EXPAND_VA_ARGS, (Int));
	PRIVATE_MAXON_SF_POINTER(System_GetConfiguration, GetConfiguration, MAXON_EXPAND_VA_ARGS, (Bool), Int index, ConfigInit& config);
	PRIVATE_MAXON_SF_POINTER(System_ConfigurationRegister, ConfigurationRegister, MAXON_EXPAND_VA_ARGS, (Bool), const ConfigInit& config);
	PRIVATE_MAXON_SF_POINTER(System_GetCriticalLog, GetCriticalLog, MAXON_EXPAND_VA_ARGS, (Char*), Int index, Int* count);
	PRIVATE_MAXON_SF_POINTER(System_GetDefinitionCount, GetDefinitionCount, MAXON_EXPAND_VA_ARGS, (Int), EntityBase::TYPE type);
	PRIVATE_MAXON_SF_POINTER(System_GetVirtualInterfaceReference, GetVirtualInterfaceReference, MAXON_EXPAND_VA_ARGS, (const InterfaceReference*), const Id& idWithoutHash);
	PRIVATE_MAXON_SF_POINTER(System_FindDefinition, FindDefinition, MAXON_EXPAND_VA_ARGS, (EntityDefinition*), EntityBase::TYPE type, const Id& eid);
	PRIVATE_MAXON_SF_POINTER(System_SetDebugErrorObserver, SetDebugErrorObserver, MAXON_EXPAND_VA_ARGS, (void*), Delegate<void(const ErrorInterface*)>&& observer);
	PRIVATE_MAXON_SF_POINTER(System_ResetDebugErrorObserver, ResetDebugErrorObserver, MAXON_EXPAND_VA_ARGS, (void), void* observer);
	PRIVATE_MAXON_SF_POINTER(System_SetCurrentError, SetCurrentError, MAXON_EXPAND_VA_ARGS, (const Error*), const Error& error);
	PRIVATE_MAXON_SF_POINTER(System_SetCurrentError_1, SetCurrentError, MAXON_EXPAND_VA_ARGS, (const Error*), Error&& error);
	PRIVATE_MAXON_SF_POINTER(System_GetLastError, GetLastError, MAXON_EXPAND_VA_ARGS, (const Error*));
	PRIVATE_MAXON_SF_POINTER(System_SetDebugError, SetDebugError, MAXON_EXPAND_VA_ARGS, (void), const Error* preallocated, const Error& error);
	PRIVATE_MAXON_SF_POINTER(System_GetDebugError, GetDebugError, MAXON_EXPAND_VA_ARGS, (const ErrorInterface*), const Error* preallocated);
	PRIVATE_MAXON_SF_POINTER(System_PrivateGetInternedId, PrivateGetInternedId, MAXON_EXPAND_VA_ARGS, (Result<const Id*>), const Id& value);
	PRIVATE_MAXON_SF_POINTER(System_PrivateFreeInternedId, PrivateFreeInternedId, MAXON_EXPAND_VA_ARGS, (void), const Id* ptr);
	PRIVATE_MAXON_SF_POINTER(System_GetBinaries, GetBinaries, MAXON_EXPAND_VA_ARGS, (const Block<const Binary* const>&));
	PRIVATE_MAXON_SF_POINTER(System_PrivateShowSynchronizedHashMapDiagnostics, PrivateShowSynchronizedHashMapDiagnostics, MAXON_EXPAND_VA_ARGS, (void), Int size, Int capacity, const Char* signature);
	PRIVATE_MAXON_SF_POINTER(System_GetPreferencesPathSuffix, GetPreferencesPathSuffix, MAXON_EXPAND_VA_ARGS, (const Char*));
	PRIVATE_MAXON_SF_POINTER(System_GetApplicationId, GetApplicationId, MAXON_EXPAND_VA_ARGS, (Id));
	PRIVATE_MAXON_SF_POINTER(System_SetApplicationType, SetApplicationType, MAXON_EXPAND_VA_ARGS, (void), const Char* dna);
	PRIVATE_MAXON_SF_POINTER(System_PrivateInitExternalDependency, PrivateInitExternalDependency, MAXON_EXPAND_VA_ARGS, (Bool), InitMTable initSystemTable, Binary* externalDependency);
	PRIVATE_MAXON_SF_POINTER(System_PrivateResetExternalDependency, PrivateResetExternalDependency, MAXON_EXPAND_VA_ARGS, (Bool), const Block<Tuple<Id, const char*, void*>>& safeShutdownMethods, Binary* externalDependency);
	PRIVATE_MAXON_SF_POINTER(System_PrivateGetUniqueHashCode, PrivateGetUniqueHashCode, MAXON_EXPAND_VA_ARGS, (UniqueHash), const Byte* ptr, Int count);
	PRIVATE_MAXON_SF_POINTER(System_PrivateHasherInitialize, PrivateHasherInitialize, MAXON_EXPAND_VA_ARGS, (void), UniqueHasher& state);
	PRIVATE_MAXON_SF_POINTER(System_PrivateHasherCombine, PrivateHasherCombine, MAXON_EXPAND_VA_ARGS, (void), UniqueHasher& state, const Byte* ptr, Int count);
	PRIVATE_MAXON_SF_POINTER(System_PrivateHasherCombine_1, PrivateHasherCombine, MAXON_EXPAND_VA_ARGS, (void), UniqueHasher& state, const UniqueHash& hash);
	PRIVATE_MAXON_SF_POINTER(System_PrivateHasherFinialize, PrivateHasherFinialize, MAXON_EXPAND_VA_ARGS, (UniqueHash), const UniqueHasher& state);
	PRIVATE_MAXON_SF_POINTER(System_PrivateFreeWithDestructor, PrivateFreeWithDestructor, MAXON_EXPAND_VA_ARGS, (void), const void* object, DestructorPointer destruct);
	template <typename IMPL> void Init()
	{
		System__ConsoleOutput = System__ConsoleOutput_GetPtr<IMPL>(true);
		System_GetConsoleOutputType = System_GetConsoleOutputType_GetPtr<IMPL>(true);
		System_Alloc = System_Alloc_GetPtr<IMPL>(true);
		System_AllocClear = System_AllocClear_GetPtr<IMPL>(true);
		System_Realloc = System_Realloc_GetPtr<IMPL>(true);
		System_Free = System_Free_GetPtr<IMPL>(true);
		System_GetAllocSize = System_GetAllocSize_GetPtr<IMPL>(true);
		System_MemoryDiagnostics = System_MemoryDiagnostics_GetPtr<IMPL>(true);
		System_MemoryAddObserver = System_MemoryAddObserver_GetPtr<IMPL>(true);
		System_SetMemoryAllocationThreshold = System_SetMemoryAllocationThreshold_GetPtr<IMPL>(true);
		System_GetCustomTimer = System_GetCustomTimer_GetPtr<IMPL>(true);
		System_GetConfigurationCount = System_GetConfigurationCount_GetPtr<IMPL>(true);
		System_GetConfiguration = System_GetConfiguration_GetPtr<IMPL>(true);
		System_ConfigurationRegister = System_ConfigurationRegister_GetPtr<IMPL>(true);
		System_GetCriticalLog = System_GetCriticalLog_GetPtr<IMPL>(true);
		System_GetDefinitionCount = System_GetDefinitionCount_GetPtr<IMPL>(true);
		System_GetVirtualInterfaceReference = System_GetVirtualInterfaceReference_GetPtr<IMPL>(true);
		System_FindDefinition = System_FindDefinition_GetPtr<IMPL>(true);
		System_SetDebugErrorObserver = System_SetDebugErrorObserver_GetPtr<IMPL>(true);
		System_ResetDebugErrorObserver = System_ResetDebugErrorObserver_GetPtr<IMPL>(true);
		System_SetCurrentError = System_SetCurrentError_GetPtr<IMPL>(true);
		System_SetCurrentError_1 = System_SetCurrentError_1_GetPtr<IMPL>(true);
		System_GetLastError = System_GetLastError_GetPtr<IMPL>(true);
		System_SetDebugError = System_SetDebugError_GetPtr<IMPL>(true);
		System_GetDebugError = System_GetDebugError_GetPtr<IMPL>(true);
		System_PrivateGetInternedId = System_PrivateGetInternedId_GetPtr<IMPL>(true);
		System_PrivateFreeInternedId = System_PrivateFreeInternedId_GetPtr<IMPL>(true);
		System_GetBinaries = System_GetBinaries_GetPtr<IMPL>(true);
		System_PrivateShowSynchronizedHashMapDiagnostics = System_PrivateShowSynchronizedHashMapDiagnostics_GetPtr<IMPL>(true);
		System_GetPreferencesPathSuffix = System_GetPreferencesPathSuffix_GetPtr<IMPL>(true);
		System_GetApplicationId = System_GetApplicationId_GetPtr<IMPL>(true);
		System_SetApplicationType = System_SetApplicationType_GetPtr<IMPL>(true);
		System_PrivateInitExternalDependency = System_PrivateInitExternalDependency_GetPtr<IMPL>(true);
		System_PrivateResetExternalDependency = System_PrivateResetExternalDependency_GetPtr<IMPL>(true);
		System_PrivateGetUniqueHashCode = System_PrivateGetUniqueHashCode_GetPtr<IMPL>(true);
		System_PrivateHasherInitialize = System_PrivateHasherInitialize_GetPtr<IMPL>(true);
		System_PrivateHasherCombine = System_PrivateHasherCombine_GetPtr<IMPL>(true);
		System_PrivateHasherCombine_1 = System_PrivateHasherCombine_1_GetPtr<IMPL>(true);
		System_PrivateHasherFinialize = System_PrivateHasherFinialize_GetPtr<IMPL>(true);
		System_PrivateFreeWithDestructor = System_PrivateFreeWithDestructor_GetPtr<IMPL>(true);
	}
};

struct System::Hxx2
{
	class Unresolved;
	template <typename C> class Wrapper
	{
	public:
		using Implementation = C;
		static void System__ConsoleOutput(const Char* s, const SourceLocation& loc, OUTPUT flags) { return C::_ConsoleOutput(s, loc, flags); }
		static OUTPUT System_GetConsoleOutputType() { return C::GetConsoleOutputType(); }
		static void* System_Alloc(Int size, const SourceLocation& location) { return C::Alloc(size, location); }
		static void* System_AllocClear(Int size, const SourceLocation& location) { return C::AllocClear(size, location); }
		static void* System_Realloc(void* data, Int size, const SourceLocation& location) { return C::Realloc(data, size, location); }
		static void System_Free(const void* data) { return C::Free(data); }
		static Int System_GetAllocSize(void* data) { return C::GetAllocSize(data); }
		static Int System_MemoryDiagnostics(MEMORYDIAGNOSTICSMODE mode, Int* totalAllocation, Int* freePhysicalMemoryEstimate) { return C::MemoryDiagnostics(mode, totalAllocation, freePhysicalMemoryEstimate); }
		static Bool System_MemoryAddObserver(MEMORYOBSERVERMODE mode, Delegate<void()>&& observer) { return C::MemoryAddObserver(mode, std::forward<Delegate<void()>>(observer)); }
		static void System_SetMemoryAllocationThreshold(UInt warnMemoryAllocationThreshold) { return C::SetMemoryAllocationThreshold(warnMemoryAllocationThreshold); }
		static Float64 System_GetCustomTimer() { return C::GetCustomTimer(); }
		static Int System_GetConfigurationCount() { return C::GetConfigurationCount(); }
		static Bool System_GetConfiguration(Int index, ConfigInit& config) { return C::GetConfiguration(index, config); }
		static Bool System_ConfigurationRegister(const ConfigInit& config) { return C::ConfigurationRegister(config); }
		static Char* System_GetCriticalLog(Int index, Int* count) { return C::GetCriticalLog(index, count); }
		static Int System_GetDefinitionCount(EntityBase::TYPE type) { return C::GetDefinitionCount(type); }
		static const InterfaceReference* System_GetVirtualInterfaceReference(const Id& idWithoutHash) { return C::GetVirtualInterfaceReference(idWithoutHash); }
		static EntityDefinition* System_FindDefinition(EntityBase::TYPE type, const Id& eid) { return C::FindDefinition(type, eid); }
		static void* System_SetDebugErrorObserver(Delegate<void(const ErrorInterface*)>&& observer) { return C::SetDebugErrorObserver(std::forward<Delegate<void(const ErrorInterface*)>>(observer)); }
		static void System_ResetDebugErrorObserver(void* observer) { return C::ResetDebugErrorObserver(observer); }
		static const Error* System_SetCurrentError(const Error& error) { return C::SetCurrentError(error); }
		static const Error* System_SetCurrentError_1(Error&& error) { return C::SetCurrentError(std::forward<Error>(error)); }
		static const Error* System_GetLastError() { return C::GetLastError(); }
		static void System_SetDebugError(const Error* preallocated, const Error& error) { return C::SetDebugError(preallocated, error); }
		static const ErrorInterface* System_GetDebugError(const Error* preallocated) { return C::GetDebugError(preallocated); }
		static Result<const Id*> System_PrivateGetInternedId(const Id& value) { return C::PrivateGetInternedId(value); }
		static void System_PrivateFreeInternedId(const Id* ptr) { return C::PrivateFreeInternedId(ptr); }
		static const Block<const Binary* const>& System_GetBinaries() { return C::GetBinaries(); }
		static void System_PrivateShowSynchronizedHashMapDiagnostics(Int size, Int capacity, const Char* signature) { return C::PrivateShowSynchronizedHashMapDiagnostics(size, capacity, signature); }
		static const Char* System_GetPreferencesPathSuffix() { return C::GetPreferencesPathSuffix(); }
		static Id System_GetApplicationId() { return C::GetApplicationId(); }
		static void System_SetApplicationType(const Char* dna) { return C::SetApplicationType(dna); }
		static Bool System_PrivateInitExternalDependency(InitMTable initSystemTable, Binary* externalDependency) { return C::PrivateInitExternalDependency(std::forward<InitMTable>(initSystemTable), externalDependency); }
		static Bool System_PrivateResetExternalDependency(const Block<Tuple<Id, const char*, void*>>& safeShutdownMethods, Binary* externalDependency) { return C::PrivateResetExternalDependency(safeShutdownMethods, externalDependency); }
		static UniqueHash System_PrivateGetUniqueHashCode(const Byte* ptr, Int count) { return C::PrivateGetUniqueHashCode(ptr, count); }
		static void System_PrivateHasherInitialize(UniqueHasher& state) { return C::PrivateHasherInitialize(state); }
		static void System_PrivateHasherCombine(UniqueHasher& state, const Byte* ptr, Int count) { return C::PrivateHasherCombine(state, ptr, count); }
		static void System_PrivateHasherCombine_1(UniqueHasher& state, const UniqueHash& hash) { return C::PrivateHasherCombine(state, hash); }
		static UniqueHash System_PrivateHasherFinialize(const UniqueHasher& state) { return C::PrivateHasherFinialize(state); }
		static void System_PrivateFreeWithDestructor(const void* object, DestructorPointer destruct) { return C::PrivateFreeWithDestructor(object, std::forward<DestructorPointer>(destruct)); }
	};

};
MAXON_ATTRIBUTE_FORCE_INLINE auto System::_ConsoleOutput(const Char* s, const SourceLocation& loc, OUTPUT flags) -> void
{
	return MTable::_instance.System__ConsoleOutput(s, loc, flags);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto System::GetConsoleOutputType() -> OUTPUT
{
	return MTable::_instance.System_GetConsoleOutputType();
}
MAXON_ATTRIBUTE_FORCE_INLINE auto System::Alloc(Int size, const SourceLocation& location) -> void*
{
	return MTable::_instance.System_Alloc(size, location);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto System::AllocClear(Int size, const SourceLocation& location) -> void*
{
	return MTable::_instance.System_AllocClear(size, location);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto System::Realloc(void* data, Int size, const SourceLocation& location) -> void*
{
	return MTable::_instance.System_Realloc(data, size, location);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto System::Free(const void* data) -> void
{
	return MTable::_instance.System_Free(data);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto System::GetAllocSize(void* data) -> Int
{
	return MTable::_instance.System_GetAllocSize(data);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto System::MemoryDiagnostics(MEMORYDIAGNOSTICSMODE mode, Int* totalAllocation, Int* freePhysicalMemoryEstimate) -> Int
{
	return MTable::_instance.System_MemoryDiagnostics(mode, totalAllocation, freePhysicalMemoryEstimate);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto System::MemoryAddObserver(MEMORYOBSERVERMODE mode, Delegate<void()>&& observer) -> Bool
{
	return MTable::_instance.System_MemoryAddObserver(mode, std::forward<Delegate<void()>>(observer));
}
MAXON_ATTRIBUTE_FORCE_INLINE auto System::SetMemoryAllocationThreshold(UInt warnMemoryAllocationThreshold) -> void
{
	return MTable::_instance.System_SetMemoryAllocationThreshold(warnMemoryAllocationThreshold);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto System::GetCustomTimer() -> Float64
{
	return MTable::_instance.System_GetCustomTimer();
}
MAXON_ATTRIBUTE_FORCE_INLINE auto System::GetConfigurationCount() -> Int
{
	return MTable::_instance.System_GetConfigurationCount();
}
MAXON_ATTRIBUTE_FORCE_INLINE auto System::GetConfiguration(Int index, ConfigInit& config) -> Bool
{
	return MTable::_instance.System_GetConfiguration(index, config);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto System::ConfigurationRegister(const ConfigInit& config) -> Bool
{
	return MTable::_instance.System_ConfigurationRegister(config);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto System::GetCriticalLog(Int index, Int* count) -> Char*
{
	return MTable::_instance.System_GetCriticalLog(index, count);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto System::GetDefinitionCount(EntityBase::TYPE type) -> Int
{
	return MTable::_instance.System_GetDefinitionCount(type);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto System::GetVirtualInterfaceReference(const Id& idWithoutHash) -> const InterfaceReference*
{
	return MTable::_instance.System_GetVirtualInterfaceReference(idWithoutHash);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto System::FindDefinition(EntityBase::TYPE type, const Id& eid) -> EntityDefinition*
{
	return MTable::_instance.System_FindDefinition(type, eid);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto System::SetDebugErrorObserver(Delegate<void(const ErrorInterface*)>&& observer) -> void*
{
	return MTable::_instance.System_SetDebugErrorObserver(std::forward<Delegate<void(const ErrorInterface*)>>(observer));
}
MAXON_ATTRIBUTE_FORCE_INLINE auto System::ResetDebugErrorObserver(void* observer) -> void
{
	return MTable::_instance.System_ResetDebugErrorObserver(observer);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto System::SetCurrentError(const Error& error) -> const Error*
{
	return MTable::_instance.System_SetCurrentError(error);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto System::SetCurrentError(Error&& error) -> const Error*
{
	return MTable::_instance.System_SetCurrentError_1(std::forward<Error>(error));
}
MAXON_ATTRIBUTE_FORCE_INLINE auto System::GetLastError() -> const Error*
{
	return MTable::_instance.System_GetLastError();
}
MAXON_ATTRIBUTE_FORCE_INLINE auto System::SetDebugError(const Error* preallocated, const Error& error) -> void
{
	return MTable::_instance.System_SetDebugError(preallocated, error);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto System::GetDebugError(const Error* preallocated) -> const ErrorInterface*
{
	return MTable::_instance.System_GetDebugError(preallocated);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto System::PrivateGetInternedId(const Id& value) -> Result<const Id*>
{
	return MTable::_instance.System_PrivateGetInternedId(value);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto System::PrivateFreeInternedId(const Id* ptr) -> void
{
	return MTable::_instance.System_PrivateFreeInternedId(ptr);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto System::GetBinaries() -> const Block<const Binary* const>&
{
	return MTable::_instance.System_GetBinaries();
}
MAXON_ATTRIBUTE_FORCE_INLINE auto System::PrivateShowSynchronizedHashMapDiagnostics(Int size, Int capacity, const Char* signature) -> void
{
	return MTable::_instance.System_PrivateShowSynchronizedHashMapDiagnostics(size, capacity, signature);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto System::GetPreferencesPathSuffix() -> const Char*
{
	return MTable::_instance.System_GetPreferencesPathSuffix();
}
MAXON_ATTRIBUTE_FORCE_INLINE auto System::GetApplicationId() -> Id
{
	return MTable::_instance.System_GetApplicationId();
}
MAXON_ATTRIBUTE_FORCE_INLINE auto System::SetApplicationType(const Char* dna) -> void
{
	return MTable::_instance.System_SetApplicationType(dna);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto System::PrivateInitExternalDependency(InitMTable initSystemTable, Binary* externalDependency) -> Bool
{
	return MTable::_instance.System_PrivateInitExternalDependency(std::forward<InitMTable>(initSystemTable), externalDependency);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto System::PrivateResetExternalDependency(const Block<Tuple<Id, const char*, void*>>& safeShutdownMethods, Binary* externalDependency) -> Bool
{
	return MTable::_instance.System_PrivateResetExternalDependency(safeShutdownMethods, externalDependency);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto System::PrivateGetUniqueHashCode(const Byte* ptr, Int count) -> UniqueHash
{
	return MTable::_instance.System_PrivateGetUniqueHashCode(ptr, count);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto System::PrivateHasherInitialize(UniqueHasher& state) -> void
{
	return MTable::_instance.System_PrivateHasherInitialize(state);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto System::PrivateHasherCombine(UniqueHasher& state, const Byte* ptr, Int count) -> void
{
	return MTable::_instance.System_PrivateHasherCombine(state, ptr, count);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto System::PrivateHasherCombine(UniqueHasher& state, const UniqueHash& hash) -> void
{
	return MTable::_instance.System_PrivateHasherCombine_1(state, hash);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto System::PrivateHasherFinialize(const UniqueHasher& state) -> UniqueHash
{
	return MTable::_instance.System_PrivateHasherFinialize(state);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto System::PrivateFreeWithDestructor(const void* object, DestructorPointer destruct) -> void
{
	return MTable::_instance.System_PrivateFreeWithDestructor(object, std::forward<DestructorPointer>(destruct));
}

#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT) && !defined(MAXON_DEPENDENCY_DISABLE_system)
#ifdef MAXON_USE_REGISTER_FUNCTION
MAXON_STATIC_STORAGE(maxon::EntityUse, s_ui_maxon_System); \
MAXON_ATTRIBUTE_CONSTRUCTOR static void Register_s_ui_maxon_System() { new (s_ui_maxon_System) maxon::EntityUse(System::_interface.GetReference(), &maxon::g_translationUnit, "maxon/system.h", false); }
#else // !MAXON_USE_REGISTER_FUNCTION
static maxon::EntityUse s_ui_maxon_System(System::_interface.GetReference(), &maxon::g_translationUnit, "maxon/system.h", false);
#endif // MAXON_USE_REGISTER_FUNCTION
#endif
#endif

#ifdef MAXON_COMPILER_GCC
	#pragma GCC diagnostic pop
#endif

#endif

