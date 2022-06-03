
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
	void (*System__ConsoleOutput) (const Char* s, const SourceLocation& loc);
	void (*System__ConsoleOutput_1) (const Char* s, const SourceLocation& loc, OUTPUT flags);
	OUTPUT (*System_GetConsoleOutputType) ();
	void* (*System_Alloc) (Int size, const SourceLocation& location);
	void* (*System_AllocClear) (Int size, const SourceLocation& location);
	void* (*System_Realloc) (void* data, Int size, const SourceLocation& location);
	void (*System_Free) (const void* data);
	Int (*System_GetAllocSize) (void* data);
	Int (*System_MemoryDiagnostics) (MEMORYDIAGNOSTICSMODE mode, Int* totalAllocation, Int* freePhysicalMemoryEstimate);
	Bool (*System_MemoryAddObserver) (MEMORYOBSERVERMODE mode, Delegate<void()>&& observer);
	void (*System_SetMemoryAllocationThreshold) (UInt warnMemoryAllocationThreshold);
	Float64 (*System_GetCustomTimer) ();
	Int (*System_GetConfigurationCount) ();
	Bool (*System_GetConfiguration) (Int index, ConfigInit& config);
	Bool (*System_ConfigurationRegister) (const ConfigInit& config);
	Char* (*System_GetCriticalLog) (Int index, Int* count);
	Int (*System_GetDefinitionCount) (EntityBase::TYPE type);
	const InterfaceReference* (*System_GetVirtualInterfaceReference) (const Id& idWithoutHash);
	EntityDefinition* (*System_FindDefinition) (EntityBase::TYPE type, const Id& eid);
	void* (*System_SetDebugErrorObserver) (Delegate<void(const ErrorInterface*)>&& observer);
	void (*System_ResetDebugErrorObserver) (void* observer);
	const Error* (*System_SetCurrentError) (const Error& error);
	const Error* (*System_SetCurrentError_1) (Error&& error);
	const Error* (*System_GetLastError) ();
	void (*System_SetDebugError) (const Error* preallocated, const Error& error);
	const ErrorInterface* (*System_GetDebugError) (const Error* preallocated);
	Result<const Id*> (*System_PrivateGetInternedId) (const Id& value);
	void (*System_PrivateFreeInternedId) (const Id* ptr);
	const Block<const Binary* const>& (*System_GetBinaries) ();
	void (*System_PrivateShowSynchronizedHashMapDiagnostics) (Int size, Int capacity, const Char* signature);
	const Char* (*System_GetPreferencesPathSuffix) ();
	Id (*System_GetApplicationId) ();
	void (*System_SetApplicationType) (const Char* dna);
	Bool (*System_PrivateInitExternalDependency) (InitMTable initSystemTable, Binary* externalDependency);
	Bool (*System_PrivateResetExternalDependency) (const Block<Tuple<Id, const char*, void*>>& safeShutdownMethods, Binary* externalDependency);
	void (*System_FreeWithDestructorI) (void* object, DestructorPointer destruct);
	template <typename IMPL> void Init()
	{
		System__ConsoleOutput = &IMPL::System__ConsoleOutput;
		System__ConsoleOutput_1 = &IMPL::System__ConsoleOutput_1;
		System_GetConsoleOutputType = &IMPL::System_GetConsoleOutputType;
		System_Alloc = &IMPL::System_Alloc;
		System_AllocClear = &IMPL::System_AllocClear;
		System_Realloc = &IMPL::System_Realloc;
		System_Free = &IMPL::System_Free;
		System_GetAllocSize = &IMPL::System_GetAllocSize;
		System_MemoryDiagnostics = &IMPL::System_MemoryDiagnostics;
		System_MemoryAddObserver = &IMPL::System_MemoryAddObserver;
		System_SetMemoryAllocationThreshold = &IMPL::System_SetMemoryAllocationThreshold;
		System_GetCustomTimer = &IMPL::System_GetCustomTimer;
		System_GetConfigurationCount = &IMPL::System_GetConfigurationCount;
		System_GetConfiguration = &IMPL::System_GetConfiguration;
		System_ConfigurationRegister = &IMPL::System_ConfigurationRegister;
		System_GetCriticalLog = &IMPL::System_GetCriticalLog;
		System_GetDefinitionCount = &IMPL::System_GetDefinitionCount;
		System_GetVirtualInterfaceReference = &IMPL::System_GetVirtualInterfaceReference;
		System_FindDefinition = &IMPL::System_FindDefinition;
		System_SetDebugErrorObserver = &IMPL::System_SetDebugErrorObserver;
		System_ResetDebugErrorObserver = &IMPL::System_ResetDebugErrorObserver;
		System_SetCurrentError = &IMPL::System_SetCurrentError;
		System_SetCurrentError_1 = &IMPL::System_SetCurrentError_1;
		System_GetLastError = &IMPL::System_GetLastError;
		System_SetDebugError = &IMPL::System_SetDebugError;
		System_GetDebugError = &IMPL::System_GetDebugError;
		System_PrivateGetInternedId = &IMPL::System_PrivateGetInternedId;
		System_PrivateFreeInternedId = &IMPL::System_PrivateFreeInternedId;
		System_GetBinaries = &IMPL::System_GetBinaries;
		System_PrivateShowSynchronizedHashMapDiagnostics = &IMPL::System_PrivateShowSynchronizedHashMapDiagnostics;
		System_GetPreferencesPathSuffix = &IMPL::System_GetPreferencesPathSuffix;
		System_GetApplicationId = &IMPL::System_GetApplicationId;
		System_SetApplicationType = &IMPL::System_SetApplicationType;
		System_PrivateInitExternalDependency = &IMPL::System_PrivateInitExternalDependency;
		System_PrivateResetExternalDependency = &IMPL::System_PrivateResetExternalDependency;
		System_FreeWithDestructorI = &IMPL::System_FreeWithDestructorI;
	}
};

struct System::Hxx2
{
	class Unresolved;
	template <typename C> class Wrapper
	{
	public:
		static void System__ConsoleOutput(const Char* s, const SourceLocation& loc) { return C::_ConsoleOutput(s, loc); }
		static void System__ConsoleOutput_1(const Char* s, const SourceLocation& loc, OUTPUT flags) { return C::_ConsoleOutput(s, loc, flags); }
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
		static void System_FreeWithDestructorI(void* object, DestructorPointer destruct) { return C::FreeWithDestructorI(object, std::forward<DestructorPointer>(destruct)); }
	};

};
MAXON_ATTRIBUTE_FORCE_INLINE auto System::_ConsoleOutput(const Char* s, const SourceLocation& loc) -> void
{
	return MTable::_instance.System__ConsoleOutput(s, loc);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto System::_ConsoleOutput(const Char* s, const SourceLocation& loc, OUTPUT flags) -> void
{
	return MTable::_instance.System__ConsoleOutput_1(s, loc, flags);
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
MAXON_ATTRIBUTE_FORCE_INLINE auto System::FreeWithDestructorI(void* object, DestructorPointer destruct) -> void
{
	return MTable::_instance.System_FreeWithDestructorI(object, std::forward<DestructorPointer>(destruct));
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

