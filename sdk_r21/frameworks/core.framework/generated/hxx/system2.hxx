
#ifndef DOXYGEN

#if defined MAXON_COMPILER_GCC
	#pragma GCC diagnostic push
	#if MAXON_COMPILER_GCC >= 600
		#pragma GCC diagnostic ignored "-Wmisleading-indentation"
	#endif
#endif

#if 1
/// @endcond


struct System::MTable
{
	static MTable _instance;
	static MTable _unresolvedInstance;
	static const maxon::Char* const _ids;
	static maxon::Bool InitUnresolved(maxon::NonvirtualInterfaceReference::UnresolvedAssembler assembler, MTable* tbl);
	static const maxon::NULL_RETURN_TYPE _returnTypes[];
	static const maxon::Bool HAS_NONSTATIC = false;
	void (*_System__ConsoleOutput) (const Char* s, const SourceLocation& loc);
	OUTPUT (*_System_GetConsoleOutputType) ();
	void* (*_System_Alloc) (Int size, const SourceLocation& location);
	void* (*_System_AllocClear) (Int size, const SourceLocation& location);
	void* (*_System_Realloc) (void* data, Int size, const SourceLocation& location);
	void (*_System_Free) (const void* data);
	Int (*_System_GetAllocSize) (void* data);
	Int (*_System_MemoryDiagnostics) (MEMORYDIAGNOSTICSMODE mode, Int* totalAllocation, Int* freePhysicalMemoryEstimate);
	Bool (*_System_MemoryAddObserver) (MEMORYOBSERVERMODE mode, Delegate<void()>&& observer);
	void (*_System_SetMemoryAllocationThreshold) (UInt warnMemoryAllocationThreshold);
	Float64 (*_System_GetCustomTimer) ();
	Int (*_System_GetConfigurationCount) ();
	Bool (*_System_GetConfiguration) (Int index, ConfigInit& config);
	Bool (*_System_ConfigurationRegister) (const ConfigInit& config);
	Char* (*_System_GetCriticalLog) (Int index, Int* count);
	Int (*_System_GetDefinitionCount) (EntityBase::TYPE type);
	const InterfaceReference* (*_System_GetVirtualInterfaceReference) (const Id& idWithoutHash);
	EntityDefinition* (*_System_FindDefinition) (EntityBase::TYPE type, const Id& eid);
	void* (*_System_SetDebugErrorObserver) (Delegate<void(const ErrorInterface*)>&& observer);
	void (*_System_ResetDebugErrorObserver) (void* observer);
	const Error* (*_System_SetCurrentError) (const Error& error);
	const Error* (*_System_SetCurrentError_1) (Error&& error);
	const Error* (*_System_GetLastError) ();
	void (*_System_SetDebugError) (const Error* preallocated, const Error& error);
	const ErrorInterface* (*_System_GetDebugError) (const Error* preallocated);
	Result<const Id*> (*_System_PrivateGetInternedId) (const Id& value);
	void (*_System_PrivateFreeInternedId) (const Id* ptr);
	const Block<const Binary* const>& (*_System_GetBinaries) ();
	void (*_System_PrivateShowSynchronizedHashMapDiagnostics) (Int size, Int capacity, const Char* signature);
	const Char* (*_System_GetPreferencesPathSuffix) ();
	Id (*_System_GetApplicationId) ();
	void (*_System_SetApplicationType) (const Char* dna);
	void (*_System_FreeWithDestructorI) (void* object, DestructorPointer destruct);
/// @endcond

	template <typename IMPL> void Init()
	{
		_System__ConsoleOutput = &IMPL::_System__ConsoleOutput;
		_System_GetConsoleOutputType = &IMPL::_System_GetConsoleOutputType;
		_System_Alloc = &IMPL::_System_Alloc;
		_System_AllocClear = &IMPL::_System_AllocClear;
		_System_Realloc = &IMPL::_System_Realloc;
		_System_Free = &IMPL::_System_Free;
		_System_GetAllocSize = &IMPL::_System_GetAllocSize;
		_System_MemoryDiagnostics = &IMPL::_System_MemoryDiagnostics;
		_System_MemoryAddObserver = &IMPL::_System_MemoryAddObserver;
		_System_SetMemoryAllocationThreshold = &IMPL::_System_SetMemoryAllocationThreshold;
		_System_GetCustomTimer = &IMPL::_System_GetCustomTimer;
		_System_GetConfigurationCount = &IMPL::_System_GetConfigurationCount;
		_System_GetConfiguration = &IMPL::_System_GetConfiguration;
		_System_ConfigurationRegister = &IMPL::_System_ConfigurationRegister;
		_System_GetCriticalLog = &IMPL::_System_GetCriticalLog;
		_System_GetDefinitionCount = &IMPL::_System_GetDefinitionCount;
		_System_GetVirtualInterfaceReference = &IMPL::_System_GetVirtualInterfaceReference;
		_System_FindDefinition = &IMPL::_System_FindDefinition;
		_System_SetDebugErrorObserver = &IMPL::_System_SetDebugErrorObserver;
		_System_ResetDebugErrorObserver = &IMPL::_System_ResetDebugErrorObserver;
		_System_SetCurrentError = &IMPL::_System_SetCurrentError;
		_System_SetCurrentError_1 = &IMPL::_System_SetCurrentError_1;
		_System_GetLastError = &IMPL::_System_GetLastError;
		_System_SetDebugError = &IMPL::_System_SetDebugError;
		_System_GetDebugError = &IMPL::_System_GetDebugError;
		_System_PrivateGetInternedId = &IMPL::_System_PrivateGetInternedId;
		_System_PrivateFreeInternedId = &IMPL::_System_PrivateFreeInternedId;
		_System_GetBinaries = &IMPL::_System_GetBinaries;
		_System_PrivateShowSynchronizedHashMapDiagnostics = &IMPL::_System_PrivateShowSynchronizedHashMapDiagnostics;
		_System_GetPreferencesPathSuffix = &IMPL::_System_GetPreferencesPathSuffix;
		_System_GetApplicationId = &IMPL::_System_GetApplicationId;
		_System_SetApplicationType = &IMPL::_System_SetApplicationType;
		_System_FreeWithDestructorI = &IMPL::_System_FreeWithDestructorI;
/// @endcond

	}
};

struct System::Hxx2
{
	class Unresolved;
	template <typename C> class Wrapper
	{
	public:
	static void _System__ConsoleOutput(const Char* s, const SourceLocation& loc) { return C::_ConsoleOutput(s, loc); }
	static OUTPUT _System_GetConsoleOutputType() { return C::GetConsoleOutputType(); }
	static void* _System_Alloc(Int size, const SourceLocation& location) { return C::Alloc(size, location); }
	static void* _System_AllocClear(Int size, const SourceLocation& location) { return C::AllocClear(size, location); }
	static void* _System_Realloc(void* data, Int size, const SourceLocation& location) { return C::Realloc(data, size, location); }
	static void _System_Free(const void* data) { return C::Free(data); }
	static Int _System_GetAllocSize(void* data) { return C::GetAllocSize(data); }
	static Int _System_MemoryDiagnostics(MEMORYDIAGNOSTICSMODE mode, Int* totalAllocation, Int* freePhysicalMemoryEstimate) { return C::MemoryDiagnostics(mode, totalAllocation, freePhysicalMemoryEstimate); }
	static Bool _System_MemoryAddObserver(MEMORYOBSERVERMODE mode, Delegate<void()>&& observer) { return C::MemoryAddObserver(mode, std::forward<Delegate<void()>>(observer)); }
	static void _System_SetMemoryAllocationThreshold(UInt warnMemoryAllocationThreshold) { return C::SetMemoryAllocationThreshold(warnMemoryAllocationThreshold); }
	static Float64 _System_GetCustomTimer() { return C::GetCustomTimer(); }
	static Int _System_GetConfigurationCount() { return C::GetConfigurationCount(); }
	static Bool _System_GetConfiguration(Int index, ConfigInit& config) { return C::GetConfiguration(index, config); }
	static Bool _System_ConfigurationRegister(const ConfigInit& config) { return C::ConfigurationRegister(config); }
	static Char* _System_GetCriticalLog(Int index, Int* count) { return C::GetCriticalLog(index, count); }
	static Int _System_GetDefinitionCount(EntityBase::TYPE type) { return C::GetDefinitionCount(type); }
	static const InterfaceReference* _System_GetVirtualInterfaceReference(const Id& idWithoutHash) { return C::GetVirtualInterfaceReference(idWithoutHash); }
	static EntityDefinition* _System_FindDefinition(EntityBase::TYPE type, const Id& eid) { return C::FindDefinition(type, eid); }
	static void* _System_SetDebugErrorObserver(Delegate<void(const ErrorInterface*)>&& observer) { return C::SetDebugErrorObserver(std::forward<Delegate<void(const ErrorInterface*)>>(observer)); }
	static void _System_ResetDebugErrorObserver(void* observer) { return C::ResetDebugErrorObserver(observer); }
	static const Error* _System_SetCurrentError(const Error& error) { return C::SetCurrentError(error); }
	static const Error* _System_SetCurrentError_1(Error&& error) { return C::SetCurrentError(std::forward<Error>(error)); }
	static const Error* _System_GetLastError() { return C::GetLastError(); }
	static void _System_SetDebugError(const Error* preallocated, const Error& error) { return C::SetDebugError(preallocated, error); }
	static const ErrorInterface* _System_GetDebugError(const Error* preallocated) { return C::GetDebugError(preallocated); }
	static Result<const Id*> _System_PrivateGetInternedId(const Id& value) { return C::PrivateGetInternedId(value); }
	static void _System_PrivateFreeInternedId(const Id* ptr) { return C::PrivateFreeInternedId(ptr); }
	static const Block<const Binary* const>& _System_GetBinaries() { return C::GetBinaries(); }
	static void _System_PrivateShowSynchronizedHashMapDiagnostics(Int size, Int capacity, const Char* signature) { return C::PrivateShowSynchronizedHashMapDiagnostics(size, capacity, signature); }
	static const Char* _System_GetPreferencesPathSuffix() { return C::GetPreferencesPathSuffix(); }
	static Id _System_GetApplicationId() { return C::GetApplicationId(); }
	static void _System_SetApplicationType(const Char* dna) { return C::SetApplicationType(dna); }
	static void _System_FreeWithDestructorI(void* object, DestructorPointer destruct) { return C::FreeWithDestructorI(object, std::forward<DestructorPointer>(destruct)); }
/// @endcond

	};

};
MAXON_ATTRIBUTE_FORCE_INLINE auto System::_ConsoleOutput(const Char* s, const SourceLocation& loc) -> void
{
	return MTable::_instance._System__ConsoleOutput(s, loc);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto System::GetConsoleOutputType() -> OUTPUT
{
	return MTable::_instance._System_GetConsoleOutputType();
}
MAXON_ATTRIBUTE_FORCE_INLINE auto System::Alloc(Int size, const SourceLocation& location) -> void*
{
	return MTable::_instance._System_Alloc(size, location);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto System::AllocClear(Int size, const SourceLocation& location) -> void*
{
	return MTable::_instance._System_AllocClear(size, location);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto System::Realloc(void* data, Int size, const SourceLocation& location) -> void*
{
	return MTable::_instance._System_Realloc(data, size, location);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto System::Free(const void* data) -> void
{
	return MTable::_instance._System_Free(data);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto System::GetAllocSize(void* data) -> Int
{
	return MTable::_instance._System_GetAllocSize(data);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto System::MemoryDiagnostics(MEMORYDIAGNOSTICSMODE mode, Int* totalAllocation, Int* freePhysicalMemoryEstimate) -> Int
{
	return MTable::_instance._System_MemoryDiagnostics(mode, totalAllocation, freePhysicalMemoryEstimate);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto System::MemoryAddObserver(MEMORYOBSERVERMODE mode, Delegate<void()>&& observer) -> Bool
{
	return MTable::_instance._System_MemoryAddObserver(mode, std::forward<Delegate<void()>>(observer));
}
MAXON_ATTRIBUTE_FORCE_INLINE auto System::SetMemoryAllocationThreshold(UInt warnMemoryAllocationThreshold) -> void
{
	return MTable::_instance._System_SetMemoryAllocationThreshold(warnMemoryAllocationThreshold);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto System::GetCustomTimer() -> Float64
{
	return MTable::_instance._System_GetCustomTimer();
}
MAXON_ATTRIBUTE_FORCE_INLINE auto System::GetConfigurationCount() -> Int
{
	return MTable::_instance._System_GetConfigurationCount();
}
MAXON_ATTRIBUTE_FORCE_INLINE auto System::GetConfiguration(Int index, ConfigInit& config) -> Bool
{
	return MTable::_instance._System_GetConfiguration(index, config);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto System::ConfigurationRegister(const ConfigInit& config) -> Bool
{
	return MTable::_instance._System_ConfigurationRegister(config);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto System::GetCriticalLog(Int index, Int* count) -> Char*
{
	return MTable::_instance._System_GetCriticalLog(index, count);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto System::GetDefinitionCount(EntityBase::TYPE type) -> Int
{
	return MTable::_instance._System_GetDefinitionCount(type);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto System::GetVirtualInterfaceReference(const Id& idWithoutHash) -> const InterfaceReference*
{
	return MTable::_instance._System_GetVirtualInterfaceReference(idWithoutHash);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto System::FindDefinition(EntityBase::TYPE type, const Id& eid) -> EntityDefinition*
{
	return MTable::_instance._System_FindDefinition(type, eid);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto System::SetDebugErrorObserver(Delegate<void(const ErrorInterface*)>&& observer) -> void*
{
	return MTable::_instance._System_SetDebugErrorObserver(std::forward<Delegate<void(const ErrorInterface*)>>(observer));
}
MAXON_ATTRIBUTE_FORCE_INLINE auto System::ResetDebugErrorObserver(void* observer) -> void
{
	return MTable::_instance._System_ResetDebugErrorObserver(observer);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto System::SetCurrentError(const Error& error) -> const Error*
{
	return MTable::_instance._System_SetCurrentError(error);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto System::SetCurrentError(Error&& error) -> const Error*
{
	return MTable::_instance._System_SetCurrentError_1(std::forward<Error>(error));
}
MAXON_ATTRIBUTE_FORCE_INLINE auto System::GetLastError() -> const Error*
{
	return MTable::_instance._System_GetLastError();
}
MAXON_ATTRIBUTE_FORCE_INLINE auto System::SetDebugError(const Error* preallocated, const Error& error) -> void
{
	return MTable::_instance._System_SetDebugError(preallocated, error);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto System::GetDebugError(const Error* preallocated) -> const ErrorInterface*
{
	return MTable::_instance._System_GetDebugError(preallocated);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto System::PrivateGetInternedId(const Id& value) -> Result<const Id*>
{
	return MTable::_instance._System_PrivateGetInternedId(value);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto System::PrivateFreeInternedId(const Id* ptr) -> void
{
	return MTable::_instance._System_PrivateFreeInternedId(ptr);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto System::GetBinaries() -> const Block<const Binary* const>&
{
	return MTable::_instance._System_GetBinaries();
}
MAXON_ATTRIBUTE_FORCE_INLINE auto System::PrivateShowSynchronizedHashMapDiagnostics(Int size, Int capacity, const Char* signature) -> void
{
	return MTable::_instance._System_PrivateShowSynchronizedHashMapDiagnostics(size, capacity, signature);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto System::GetPreferencesPathSuffix() -> const Char*
{
	return MTable::_instance._System_GetPreferencesPathSuffix();
}
MAXON_ATTRIBUTE_FORCE_INLINE auto System::GetApplicationId() -> Id
{
	return MTable::_instance._System_GetApplicationId();
}
MAXON_ATTRIBUTE_FORCE_INLINE auto System::SetApplicationType(const Char* dna) -> void
{
	return MTable::_instance._System_SetApplicationType(dna);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto System::FreeWithDestructorI(void* object, DestructorPointer destruct) -> void
{
	return MTable::_instance._System_FreeWithDestructorI(object, std::forward<DestructorPointer>(destruct));
}
/// @endcond


#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT)
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

