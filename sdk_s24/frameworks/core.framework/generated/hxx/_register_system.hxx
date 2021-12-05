#if 1
namespace maxon
{
	namespace enum37
	{
		enum class MEMORYDIAGNOSTICSMODE : Int
			{
				ESTIMATEONLY	= -1,	///< Just return current total allocation estimate.
				QUIET					= 0,	///< Just return allocation numbers.
				VERBOSE				= 1,	///< Additional details will be sent to the console.
				LEAKGRAPH			= 2,	///< Create a memory leak graph (circular references).
				PRIVATE_OFF		= 3,
				PRIVATE_ON		= 4
			} ;
		static const maxon::UInt64 MEMORYDIAGNOSTICSMODE_values[] = {maxon::UInt64(enum37::MEMORYDIAGNOSTICSMODE::ESTIMATEONLY), maxon::UInt64(enum37::MEMORYDIAGNOSTICSMODE::QUIET), maxon::UInt64(enum37::MEMORYDIAGNOSTICSMODE::VERBOSE), maxon::UInt64(enum37::MEMORYDIAGNOSTICSMODE::LEAKGRAPH), maxon::UInt64(enum37::MEMORYDIAGNOSTICSMODE::PRIVATE_OFF), maxon::UInt64(enum37::MEMORYDIAGNOSTICSMODE::PRIVATE_ON)};
		static const maxon::EnumInfo MEMORYDIAGNOSTICSMODE_info{"System::MEMORYDIAGNOSTICSMODE", SIZEOF(MEMORYDIAGNOSTICSMODE), false, "ESTIMATEONLY\0QUIET\0VERBOSE\0LEAKGRAPH\0PRIVATE_OFF\0PRIVATE_ON\0", MEMORYDIAGNOSTICSMODE_values, std::extent<decltype(MEMORYDIAGNOSTICSMODE_values)>::value};
	}
	const maxon::EnumInfo& PrivateGetEnumInfo_MEMORYDIAGNOSTICSMODE37(void*){ return enum37::MEMORYDIAGNOSTICSMODE_info; }
	namespace enum44
	{
		enum class MEMORYOBSERVERMODE : Int
			{
				LOWMEM_CLEANUP = 0,		///< The observer should free resources/caches and then the allocator will retry.
				LOWMEM_FAILURE = 1,		///< An allocation failed (even retry didn't change that).
				WARNMEM_LIMIT = 2			///< The allocations exceed a user specified amount of memory.
			} ;
		static const maxon::UInt64 MEMORYOBSERVERMODE_values[] = {maxon::UInt64(enum44::MEMORYOBSERVERMODE::LOWMEM_CLEANUP), maxon::UInt64(enum44::MEMORYOBSERVERMODE::LOWMEM_FAILURE), maxon::UInt64(enum44::MEMORYOBSERVERMODE::WARNMEM_LIMIT)};
		static const maxon::EnumInfo MEMORYOBSERVERMODE_info{"System::MEMORYOBSERVERMODE", SIZEOF(MEMORYOBSERVERMODE), false, "LOWMEM_CLEANUP\0LOWMEM_FAILURE\0WARNMEM_LIMIT\0", MEMORYOBSERVERMODE_values, std::extent<decltype(MEMORYOBSERVERMODE_values)>::value};
	}
	const maxon::EnumInfo& PrivateGetEnumInfo_MEMORYOBSERVERMODE44(void*){ return enum44::MEMORYOBSERVERMODE_info; }
	namespace enum51
	{
		enum class SPECIALBEHAVIOR : Int
			{
				NONE											= 0,
				OMIT_HELP									= (1 << 0),	///< If set "-help" will not start help mode of the underlying base system, whereas "help" will. This is legacy behavior for C4D.
				DONTWARN_MISSINGARGUMENTS	= (1 << 1)	///< If set there will be no output in the console if an argument is passed but not defined in the code.
			} ;
		static const maxon::UInt64 SPECIALBEHAVIOR_values[] = {maxon::UInt64(enum51::SPECIALBEHAVIOR::NONE), maxon::UInt64(enum51::SPECIALBEHAVIOR::OMIT_HELP), maxon::UInt64(enum51::SPECIALBEHAVIOR::DONTWARN_MISSINGARGUMENTS)};
		static const maxon::EnumInfo SPECIALBEHAVIOR_info{"System::SPECIALBEHAVIOR", SIZEOF(SPECIALBEHAVIOR), true, "NONE\0OMIT_HELP\0DONTWARN_MISSINGARGUMENTS\0", SPECIALBEHAVIOR_values, std::extent<decltype(SPECIALBEHAVIOR_values)>::value};
	}
	const maxon::EnumInfo& PrivateGetEnumInfo_SPECIALBEHAVIOR51(void*){ return enum51::SPECIALBEHAVIOR_info; }
	const maxon::Char* const System::MTable::_ids = 
		"_ConsoleOutput@bed46b61629a68bb\0" // void _ConsoleOutput(const Char* s, const SourceLocation& loc)
		"GetConsoleOutputType@73a0d452f0eb4232\0" // OUTPUT GetConsoleOutputType()
		"Alloc@d4943981fe847ee3\0" // void* Alloc(Int size, const SourceLocation& location)
		"AllocClear@d4943981fe847ee3\0" // void* AllocClear(Int size, const SourceLocation& location)
		"Realloc@e65f8d6571ea11af\0" // void* Realloc(void* data, Int size, const SourceLocation& location)
		"Free@fd4f2d19abfff044\0" // void Free(const void* data)
		"GetAllocSize@54a448944afadd0e\0" // Int GetAllocSize(void* data)
		"MemoryDiagnostics@c6740bbd1348029a\0" // Int MemoryDiagnostics(MEMORYDIAGNOSTICSMODE mode, Int* totalAllocation, Int* freePhysicalMemoryEstimate)
		"MemoryAddObserver@7ac08cd0f603aab3\0" // Bool MemoryAddObserver(MEMORYOBSERVERMODE mode, Delegate<void()>&& observer)
		"SetMemoryAllocationThreshold@b4bbab464631374d\0" // void SetMemoryAllocationThreshold(UInt warnMemoryAllocationThreshold)
		"GetCustomTimer@7d4d1634b4d7437d\0" // Float64 GetCustomTimer()
		"GetConfigurationCount@7d0e6f3d10c2128c\0" // Int GetConfigurationCount()
		"GetConfiguration@399b8c14cc23f7da\0" // Bool GetConfiguration(Int index, ConfigInit& config)
		"ConfigurationRegister@5b17997de64ab6c8\0" // Bool ConfigurationRegister(const ConfigInit& config)
		"GetCriticalLog@2cffadb95fa33a3d\0" // Char* GetCriticalLog(Int index, Int* count)
		"GetDefinitionCount@50b8c765c2370d3a\0" // Int GetDefinitionCount(EntityBase::TYPE type)
		"GetVirtualInterfaceReference@5f3385e6b75d17b0\0" // const InterfaceReference* GetVirtualInterfaceReference(const Id& idWithoutHash)
		"FindDefinition@49ec72a774b57e59\0" // EntityDefinition* FindDefinition(EntityBase::TYPE type, const Id& eid)
		"SetDebugErrorObserver@cc1dc2473139212f\0" // void* SetDebugErrorObserver(Delegate<void(const ErrorInterface*)>&& observer)
		"ResetDebugErrorObserver@ab6877447cc15245\0" // void ResetDebugErrorObserver(void* observer)
		"SetCurrentError@5c92a89e5387b461\0" // const Error* SetCurrentError(const Error& error)
		"SetCurrentError@290a739c0e312992\0" // const Error* SetCurrentError(Error&& error)
		"GetLastError@1aefaf357403a56e\0" // const Error* GetLastError()
		"SetDebugError@922cf7935fb4da33\0" // void SetDebugError(const Error* preallocated, const Error& error)
		"GetDebugError@c50b9b7eaec79b9c\0" // const ErrorInterface* GetDebugError(const Error* preallocated)
		"PrivateGetInternedId@f21dc0b7464c4c1a\0" // Result<const Id*> PrivateGetInternedId(const Id& value)
		"PrivateFreeInternedId@291f3856c54318a7\0" // void PrivateFreeInternedId(const Id* ptr)
		"GetBinaries@673d8507fbb65a22\0" // const Block<const Binary* const>& GetBinaries()
		"PrivateShowSynchronizedHashMapDiagnostics@3871f4377739d6f6\0" // void PrivateShowSynchronizedHashMapDiagnostics(Int size, Int capacity, const Char* signature)
		"GetPreferencesPathSuffix@f7184b4ea7b20d84\0" // const Char* GetPreferencesPathSuffix()
		"GetApplicationId@33636d5332f4d14e\0" // Id GetApplicationId()
		"SetApplicationType@1f70af880d2deb42\0" // void SetApplicationType(const Char* dna)
		"PrivateInitExternalDependency@a11a3f045d96c641\0" // Bool PrivateInitExternalDependency(InitMTable initSystemTable, Binary* externalDependency)
		"PrivateResetExternalDependency@fe2f14635b8717a8\0" // Bool PrivateResetExternalDependency(const Block<Tuple<Id, const char*, void*>>& safeShutdownMethods, Binary* externalDependency)
		"FreeWithDestructorI@5ecead73482df405\0" // void FreeWithDestructorI(void* object, DestructorPointer destruct)
	"";
	MAXON_WARNING_PUSH
	MAXON_WARNING_DISABLE_DEPRECATED
	class System::Hxx2::Unresolved : public System
	{
	public:
		static const Unresolved* Get(const System* o) { return (const Unresolved*) o; }
		static Unresolved* Get(System* o) { return (Unresolved*) o; }
		static void _ConsoleOutput(const Char* s, const SourceLocation& loc) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return System::_ConsoleOutput(s, loc); return maxon::PrivateLogNullptrError();}
		static OUTPUT GetConsoleOutputType() { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return System::GetConsoleOutputType(); return maxon::PrivateIncompleteNullReturnValue<OUTPUT>(maxon::NULL_RETURN_REASON::UNRESOLVED, OVERLOAD_MAX_RANK);}
		static void* Alloc(Int size, const SourceLocation& location) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return System::Alloc(size, location); return nullptr;}
		static void* AllocClear(Int size, const SourceLocation& location) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return System::AllocClear(size, location); return nullptr;}
		static void* Realloc(void* data, Int size, const SourceLocation& location) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return System::Realloc(data, size, location); return nullptr;}
		static void Free(const void* data) { if (data && maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return System::Free(data); return maxon::PrivateLogNullptrError();}
		static Int GetAllocSize(void* data) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return System::GetAllocSize(data); return 0;}
		static Int MemoryDiagnostics(MEMORYDIAGNOSTICSMODE mode, Int* totalAllocation, Int* freePhysicalMemoryEstimate) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return System::MemoryDiagnostics(mode, totalAllocation, freePhysicalMemoryEstimate); return 0;}
		static Bool MemoryAddObserver(MEMORYOBSERVERMODE mode, Delegate<void()>&& observer) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return System::MemoryAddObserver(mode, std::forward<Delegate<void()>>(observer)); return maxon::PrivateLogNullptrError(false);}
		static void SetMemoryAllocationThreshold(UInt warnMemoryAllocationThreshold) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return System::SetMemoryAllocationThreshold(warnMemoryAllocationThreshold); return maxon::PrivateLogNullptrError();}
		static Float64 GetCustomTimer() { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return System::GetCustomTimer(); return 0;}
		static Int GetConfigurationCount() { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return System::GetConfigurationCount(); return 0;}
		static Bool GetConfiguration(Int index, ConfigInit& config) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return System::GetConfiguration(index, config); return maxon::PrivateLogNullptrError(false);}
		static Bool ConfigurationRegister(const ConfigInit& config) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return System::ConfigurationRegister(config); return maxon::PrivateLogNullptrError(false);}
		static Char* GetCriticalLog(Int index, Int* count) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return System::GetCriticalLog(index, count); return nullptr;}
		static Int GetDefinitionCount(EntityBase::TYPE type) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return System::GetDefinitionCount(type); return 0;}
		static const InterfaceReference* GetVirtualInterfaceReference(const Id& idWithoutHash) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return System::GetVirtualInterfaceReference(idWithoutHash); return nullptr;}
		static EntityDefinition* FindDefinition(EntityBase::TYPE type, const Id& eid) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return System::FindDefinition(type, eid); return nullptr;}
		static void* SetDebugErrorObserver(Delegate<void(const ErrorInterface*)>&& observer) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return System::SetDebugErrorObserver(std::forward<Delegate<void(const ErrorInterface*)>>(observer)); return nullptr;}
		static void ResetDebugErrorObserver(void* observer) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return System::ResetDebugErrorObserver(observer); return maxon::PrivateLogNullptrError();}
		static const Error* SetCurrentError(const Error& error) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return System::SetCurrentError(error); return nullptr;}
		static const Error* SetCurrentError(Error&& error) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return System::SetCurrentError(std::forward<Error>(error)); return nullptr;}
		static const Error* GetLastError() { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return System::GetLastError(); return nullptr;}
		static void SetDebugError(const Error* preallocated, const Error& error) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return System::SetDebugError(preallocated, error); return maxon::PrivateLogNullptrError();}
		static const ErrorInterface* GetDebugError(const Error* preallocated) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return System::GetDebugError(preallocated); return nullptr;}
		static Result<const Id*> PrivateGetInternedId(const Id& value) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return System::PrivateGetInternedId(value); return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::UNRESOLVED);}
		static void PrivateFreeInternedId(const Id* ptr) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return System::PrivateFreeInternedId(ptr); return maxon::PrivateLogNullptrError();}
		static const Block<const Binary* const>& GetBinaries() { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return System::GetBinaries(); return maxon::PrivateIncompleteNullReturnValue<const Block<const Binary* const>&>(maxon::NULL_RETURN_REASON::UNRESOLVED, OVERLOAD_MAX_RANK);}
		static void PrivateShowSynchronizedHashMapDiagnostics(Int size, Int capacity, const Char* signature) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return System::PrivateShowSynchronizedHashMapDiagnostics(size, capacity, signature); return maxon::PrivateLogNullptrError();}
		static const Char* GetPreferencesPathSuffix() { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return System::GetPreferencesPathSuffix(); return nullptr;}
		static Id GetApplicationId() { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return System::GetApplicationId(); return maxon::PrivateIncompleteNullReturnValue<Id>(maxon::NULL_RETURN_REASON::UNRESOLVED, OVERLOAD_MAX_RANK);}
		static void SetApplicationType(const Char* dna) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return System::SetApplicationType(dna); return maxon::PrivateLogNullptrError();}
		static Bool PrivateInitExternalDependency(InitMTable initSystemTable, Binary* externalDependency) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return System::PrivateInitExternalDependency(std::forward<InitMTable>(initSystemTable), externalDependency); return maxon::PrivateLogNullptrError(false);}
		static Bool PrivateResetExternalDependency(const Block<Tuple<Id, const char*, void*>>& safeShutdownMethods, Binary* externalDependency) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return System::PrivateResetExternalDependency(safeShutdownMethods, externalDependency); return maxon::PrivateLogNullptrError(false);}
		static void FreeWithDestructorI(void* object, DestructorPointer destruct) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return System::FreeWithDestructorI(object, std::forward<DestructorPointer>(destruct)); return maxon::PrivateLogNullptrError();}
	};
	MAXON_WARNING_POP
#ifdef PRIVATE_MAXON_ASSEMBLE_UNRESOLVED
	const maxon::NULL_RETURN_TYPE System::MTable::_returnTypes[] = 
	{
		maxon::details::NullReturnType<void>::value,
		maxon::details::NullReturnType<OUTPUT>::value,
		maxon::details::NullReturnType<void*>::value,
		maxon::details::NullReturnType<void*>::value,
		maxon::details::NullReturnType<void*>::value,
		maxon::NULL_RETURN_TYPE::VOID_ZERO_FREE_FUNCTION,
		maxon::details::NullReturnType<Int>::value,
		maxon::details::NullReturnType<Int>::value,
		maxon::details::NullReturnType<Bool>::value,
		maxon::details::NullReturnType<void>::value,
		maxon::details::NullReturnType<Float64>::value,
		maxon::details::NullReturnType<Int>::value,
		maxon::details::NullReturnType<Bool>::value,
		maxon::details::NullReturnType<Bool>::value,
		maxon::details::NullReturnType<Char*>::value,
		maxon::details::NullReturnType<Int>::value,
		maxon::details::NullReturnType<const InterfaceReference*>::value,
		maxon::details::NullReturnType<EntityDefinition*>::value,
		maxon::details::NullReturnType<void*>::value,
		maxon::details::NullReturnType<void>::value,
		maxon::details::NullReturnType<const Error*>::value,
		maxon::details::NullReturnType<const Error*>::value,
		maxon::details::NullReturnType<const Error*>::value,
		maxon::details::NullReturnType<void>::value,
		maxon::details::NullReturnType<const ErrorInterface*>::value,
		maxon::details::NullReturnType<Result<const Id*>>::value,
		maxon::details::NullReturnType<void>::value,
		maxon::details::NullReturnType<const Block<const Binary* const>&>::value,
		maxon::details::NullReturnType<void>::value,
		maxon::details::NullReturnType<const Char*>::value,
		maxon::details::NullReturnType<Id>::value,
		maxon::details::NullReturnType<void>::value,
		maxon::details::NullReturnType<Bool>::value,
		maxon::details::NullReturnType<Bool>::value,
		maxon::details::NullReturnType<void>::value,
		maxon::NULL_RETURN_TYPE::OTHER
	};
#endif
	maxon::Bool System::MTable::InitUnresolved(maxon::NonvirtualInterfaceReference::UnresolvedAssembler assembler, MTable* tbl)
	{
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->_System__ConsoleOutput = &Hxx2::Wrapper<Hxx2::Unresolved>::_System__ConsoleOutput;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<OUTPUT>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_System_GetConsoleOutputType = &Hxx2::Wrapper<Hxx2::Unresolved>::_System_GetConsoleOutputType;
		#else
		tbl->_System_GetConsoleOutputType = &Hxx2::Wrapper<Hxx2::Unresolved>::_System_GetConsoleOutputType;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->_System_Alloc = &Hxx2::Wrapper<Hxx2::Unresolved>::_System_Alloc;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->_System_AllocClear = &Hxx2::Wrapper<Hxx2::Unresolved>::_System_AllocClear;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->_System_Realloc = &Hxx2::Wrapper<Hxx2::Unresolved>::_System_Realloc;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->_System_Free = &Hxx2::Wrapper<Hxx2::Unresolved>::_System_Free;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->_System_GetAllocSize = &Hxx2::Wrapper<Hxx2::Unresolved>::_System_GetAllocSize;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->_System_MemoryDiagnostics = &Hxx2::Wrapper<Hxx2::Unresolved>::_System_MemoryDiagnostics;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->_System_MemoryAddObserver = &Hxx2::Wrapper<Hxx2::Unresolved>::_System_MemoryAddObserver;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->_System_SetMemoryAllocationThreshold = &Hxx2::Wrapper<Hxx2::Unresolved>::_System_SetMemoryAllocationThreshold;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->_System_GetCustomTimer = &Hxx2::Wrapper<Hxx2::Unresolved>::_System_GetCustomTimer;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->_System_GetConfigurationCount = &Hxx2::Wrapper<Hxx2::Unresolved>::_System_GetConfigurationCount;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->_System_GetConfiguration = &Hxx2::Wrapper<Hxx2::Unresolved>::_System_GetConfiguration;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->_System_ConfigurationRegister = &Hxx2::Wrapper<Hxx2::Unresolved>::_System_ConfigurationRegister;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->_System_GetCriticalLog = &Hxx2::Wrapper<Hxx2::Unresolved>::_System_GetCriticalLog;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->_System_GetDefinitionCount = &Hxx2::Wrapper<Hxx2::Unresolved>::_System_GetDefinitionCount;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->_System_GetVirtualInterfaceReference = &Hxx2::Wrapper<Hxx2::Unresolved>::_System_GetVirtualInterfaceReference;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->_System_FindDefinition = &Hxx2::Wrapper<Hxx2::Unresolved>::_System_FindDefinition;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->_System_SetDebugErrorObserver = &Hxx2::Wrapper<Hxx2::Unresolved>::_System_SetDebugErrorObserver;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->_System_ResetDebugErrorObserver = &Hxx2::Wrapper<Hxx2::Unresolved>::_System_ResetDebugErrorObserver;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->_System_SetCurrentError = &Hxx2::Wrapper<Hxx2::Unresolved>::_System_SetCurrentError;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->_System_SetCurrentError_1 = &Hxx2::Wrapper<Hxx2::Unresolved>::_System_SetCurrentError_1;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->_System_GetLastError = &Hxx2::Wrapper<Hxx2::Unresolved>::_System_GetLastError;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->_System_SetDebugError = &Hxx2::Wrapper<Hxx2::Unresolved>::_System_SetDebugError;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->_System_GetDebugError = &Hxx2::Wrapper<Hxx2::Unresolved>::_System_GetDebugError;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<const Id*>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_System_PrivateGetInternedId = &Hxx2::Wrapper<Hxx2::Unresolved>::_System_PrivateGetInternedId;
		#else
		tbl->_System_PrivateGetInternedId = &Hxx2::Wrapper<Hxx2::Unresolved>::_System_PrivateGetInternedId;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->_System_PrivateFreeInternedId = &Hxx2::Wrapper<Hxx2::Unresolved>::_System_PrivateFreeInternedId;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<const Block<const Binary* const>&>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_System_GetBinaries = &Hxx2::Wrapper<Hxx2::Unresolved>::_System_GetBinaries;
		#else
		tbl->_System_GetBinaries = &Hxx2::Wrapper<Hxx2::Unresolved>::_System_GetBinaries;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->_System_PrivateShowSynchronizedHashMapDiagnostics = &Hxx2::Wrapper<Hxx2::Unresolved>::_System_PrivateShowSynchronizedHashMapDiagnostics;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->_System_GetPreferencesPathSuffix = &Hxx2::Wrapper<Hxx2::Unresolved>::_System_GetPreferencesPathSuffix;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Id>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_System_GetApplicationId = &Hxx2::Wrapper<Hxx2::Unresolved>::_System_GetApplicationId;
		#else
		tbl->_System_GetApplicationId = &Hxx2::Wrapper<Hxx2::Unresolved>::_System_GetApplicationId;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->_System_SetApplicationType = &Hxx2::Wrapper<Hxx2::Unresolved>::_System_SetApplicationType;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->_System_PrivateInitExternalDependency = &Hxx2::Wrapper<Hxx2::Unresolved>::_System_PrivateInitExternalDependency;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->_System_PrivateResetExternalDependency = &Hxx2::Wrapper<Hxx2::Unresolved>::_System_PrivateResetExternalDependency;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->_System_FreeWithDestructorI = &Hxx2::Wrapper<Hxx2::Unresolved>::_System_FreeWithDestructorI;
		#endif
	#ifdef PRIVATE_MAXON_ASSEMBLE_UNRESOLVED
		return assembler(&_interface, (maxon::Char*) tbl, _returnTypes, SIZEOF(MTable) / SIZEOF(void*));
	#else
		return true;
	#endif
	}
	MAXON_INTERFACE_REGISTER(System, "net.maxon.interface.system", nullptr);
	template <typename DUMMY> maxon::Int System::PrivateInstantiateNullValueHelper()
	{
		return 0
		| maxon::details::InstantiateNullReturnValue<Id>(OVERLOAD_MAX_RANK)
		| maxon::details::InstantiateNullReturnValue<OUTPUT>(OVERLOAD_MAX_RANK)
		| maxon::details::InstantiateNullReturnValue<const Block<const Binary* const>&>(OVERLOAD_MAX_RANK)
		;
	}
}
#endif
static maxon::details::ForceEvaluation s_forceEval_system(0
	| maxon::System::PrivateInstantiateNullValueHelper<maxon::Int>()
);
