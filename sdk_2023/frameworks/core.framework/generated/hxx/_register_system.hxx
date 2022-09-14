#if 1
namespace maxon
{
	namespace enum36
	{
		enum class MEMORYDIAGNOSTICSMODE : Int
			{
				ESTIMATEONLY	= -1,	///< Just return current total allocation estimate.
				QUIET					= 0,	///< Just return allocation numbers.
				VERBOSE				= 1,	///< Additional details will be sent to the console.
				LEAKGRAPH			= 2,	///< Create a memory leak graph (circular references).
				PRIVATE_OFF		= 3,
				PRIVATE_ON		= 4,
				PRIVATE_GARBAGE = 5
			} ;
		static const maxon::UInt64 MEMORYDIAGNOSTICSMODE_values[] = {maxon::UInt64(enum36::MEMORYDIAGNOSTICSMODE::ESTIMATEONLY), maxon::UInt64(enum36::MEMORYDIAGNOSTICSMODE::QUIET), maxon::UInt64(enum36::MEMORYDIAGNOSTICSMODE::VERBOSE), maxon::UInt64(enum36::MEMORYDIAGNOSTICSMODE::LEAKGRAPH), maxon::UInt64(enum36::MEMORYDIAGNOSTICSMODE::PRIVATE_OFF), maxon::UInt64(enum36::MEMORYDIAGNOSTICSMODE::PRIVATE_ON), maxon::UInt64(enum36::MEMORYDIAGNOSTICSMODE::PRIVATE_GARBAGE)};
		static const maxon::EnumInfo MEMORYDIAGNOSTICSMODE_info{"System::MEMORYDIAGNOSTICSMODE", SIZEOF(MEMORYDIAGNOSTICSMODE), false, "ESTIMATEONLY\0QUIET\0VERBOSE\0LEAKGRAPH\0PRIVATE_OFF\0PRIVATE_ON\0PRIVATE_GARBAGE\0", MEMORYDIAGNOSTICSMODE_values, std::extent<decltype(MEMORYDIAGNOSTICSMODE_values)>::value};
	}
	const maxon::EnumInfo& PrivateGetEnumInfo_MEMORYDIAGNOSTICSMODE36(void*){ return enum36::MEMORYDIAGNOSTICSMODE_info; }
	namespace enum43
	{
		enum class MEMORYOBSERVERMODE : Int
			{
				LOWMEM_CLEANUP = 0,		///< The observer should free resources/caches and then the allocator will retry.
				LOWMEM_FAILURE = 1,		///< An allocation failed (even retry didn't change that).
				WARNMEM_LIMIT = 2			///< The allocations exceed a user specified amount of memory.
			} ;
		static const maxon::UInt64 MEMORYOBSERVERMODE_values[] = {maxon::UInt64(enum43::MEMORYOBSERVERMODE::LOWMEM_CLEANUP), maxon::UInt64(enum43::MEMORYOBSERVERMODE::LOWMEM_FAILURE), maxon::UInt64(enum43::MEMORYOBSERVERMODE::WARNMEM_LIMIT)};
		static const maxon::EnumInfo MEMORYOBSERVERMODE_info{"System::MEMORYOBSERVERMODE", SIZEOF(MEMORYOBSERVERMODE), false, "LOWMEM_CLEANUP\0LOWMEM_FAILURE\0WARNMEM_LIMIT\0", MEMORYOBSERVERMODE_values, std::extent<decltype(MEMORYOBSERVERMODE_values)>::value};
	}
	const maxon::EnumInfo& PrivateGetEnumInfo_MEMORYOBSERVERMODE43(void*){ return enum43::MEMORYOBSERVERMODE_info; }
	namespace enum50
	{
		enum class SPECIALBEHAVIOR : Int
			{
				NONE											= 0,
				OMIT_HELP									= (1 << 0),	///< If set "-help" will not start help mode of the underlying base system, whereas "help" will. This is legacy behavior for C4D.
				DONTWARN_MISSINGARGUMENTS	= (1 << 1)	///< If set there will be no output in the console if an argument is passed but not defined in the code.
			} ;
		static const maxon::UInt64 SPECIALBEHAVIOR_values[] = {maxon::UInt64(enum50::SPECIALBEHAVIOR::NONE), maxon::UInt64(enum50::SPECIALBEHAVIOR::OMIT_HELP), maxon::UInt64(enum50::SPECIALBEHAVIOR::DONTWARN_MISSINGARGUMENTS)};
		static const maxon::EnumInfo SPECIALBEHAVIOR_info{"System::SPECIALBEHAVIOR", SIZEOF(SPECIALBEHAVIOR), true, "NONE\0OMIT_HELP\0DONTWARN_MISSINGARGUMENTS\0", SPECIALBEHAVIOR_values, std::extent<decltype(SPECIALBEHAVIOR_values)>::value};
	}
	const maxon::EnumInfo& PrivateGetEnumInfo_SPECIALBEHAVIOR50(void*){ return enum50::SPECIALBEHAVIOR_info; }
	const maxon::Char* const System::MTable::_ids = 
		"_ConsoleOutput@9b8bcc27db87c600\0" // void _ConsoleOutput(const Char* s, const SourceLocation& loc, OUTPUT flags)
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
		"PrivateGetUniqueHashCode@33d9e0da2639de94\0" // UniqueHash PrivateGetUniqueHashCode(const Byte* ptr, Int count)
		"PrivateHasherInitialize@a3c144800dfdea1b\0" // void PrivateHasherInitialize(UniqueHasher& state)
		"PrivateHasherCombine@16277e3d037775a9\0" // void PrivateHasherCombine(UniqueHasher& state, const Byte* ptr, Int count)
		"PrivateHasherCombine@3823f01a3fe9bd7b\0" // void PrivateHasherCombine(UniqueHasher& state, const UniqueHash& hash)
		"PrivateHasherFinialize@9bf3a5391f0aaf9d\0" // UniqueHash PrivateHasherFinialize(const UniqueHasher& state)
		"PrivateFreeWithDestructor@994373841ad509d0\0" // void PrivateFreeWithDestructor(const void* object, DestructorPointer destruct)
	"";
	MAXON_WARNING_PUSH
	MAXON_WARNING_DISABLE_DEPRECATED
	class System::Hxx2::Unresolved : public System
	{
	public:
		static const Unresolved* Get(const System* o) { return (const Unresolved*) o; }
		static Unresolved* Get(System* o) { return (Unresolved*) o; }
		static void _ConsoleOutput(const Char* s, const SourceLocation& loc, OUTPUT flags) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return System::_ConsoleOutput(s, loc, flags); return maxon::PrivateLogNullptrError();}
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
		static UniqueHash PrivateGetUniqueHashCode(const Byte* ptr, Int count) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return System::PrivateGetUniqueHashCode(ptr, count); return maxon::PrivateIncompleteNullReturnValue<UniqueHash>(maxon::NULL_RETURN_REASON::UNRESOLVED, OVERLOAD_MAX_RANK);}
		static void PrivateHasherInitialize(UniqueHasher& state) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return System::PrivateHasherInitialize(state); return maxon::PrivateLogNullptrError();}
		static void PrivateHasherCombine(UniqueHasher& state, const Byte* ptr, Int count) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return System::PrivateHasherCombine(state, ptr, count); return maxon::PrivateLogNullptrError();}
		static void PrivateHasherCombine(UniqueHasher& state, const UniqueHash& hash) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return System::PrivateHasherCombine(state, hash); return maxon::PrivateLogNullptrError();}
		static UniqueHash PrivateHasherFinialize(const UniqueHasher& state) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return System::PrivateHasherFinialize(state); return maxon::PrivateIncompleteNullReturnValue<UniqueHash>(maxon::NULL_RETURN_REASON::UNRESOLVED, OVERLOAD_MAX_RANK);}
		static void PrivateFreeWithDestructor(const void* object, DestructorPointer destruct) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return System::PrivateFreeWithDestructor(object, std::forward<DestructorPointer>(destruct)); return maxon::PrivateLogNullptrError();}
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
		maxon::details::NullReturnType<UniqueHash>::value,
		maxon::details::NullReturnType<void>::value,
		maxon::details::NullReturnType<void>::value,
		maxon::details::NullReturnType<void>::value,
		maxon::details::NullReturnType<UniqueHash>::value,
		maxon::details::NullReturnType<void>::value,
		maxon::NULL_RETURN_TYPE::OTHER
	};
#endif
	maxon::Bool System::MTable::InitUnresolved(maxon::NonvirtualInterfaceReference::UnresolvedAssembler assembler, MTable* tbl)
	{
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->System__ConsoleOutput = PRIVATE_MAXON_MF_CAST(decltype(System__ConsoleOutput), &Hxx2::Wrapper<Hxx2::Unresolved>::System__ConsoleOutput);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<OUTPUT>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->System_GetConsoleOutputType = PRIVATE_MAXON_MF_CAST(decltype(System_GetConsoleOutputType), &Hxx2::Wrapper<Hxx2::Unresolved>::System_GetConsoleOutputType);
		#else
		tbl->System_GetConsoleOutputType = PRIVATE_MAXON_MF_CAST(decltype(System_GetConsoleOutputType), &Hxx2::Wrapper<Hxx2::Unresolved>::System_GetConsoleOutputType);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->System_Alloc = PRIVATE_MAXON_MF_CAST(decltype(System_Alloc), &Hxx2::Wrapper<Hxx2::Unresolved>::System_Alloc);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->System_AllocClear = PRIVATE_MAXON_MF_CAST(decltype(System_AllocClear), &Hxx2::Wrapper<Hxx2::Unresolved>::System_AllocClear);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->System_Realloc = PRIVATE_MAXON_MF_CAST(decltype(System_Realloc), &Hxx2::Wrapper<Hxx2::Unresolved>::System_Realloc);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->System_Free = PRIVATE_MAXON_MF_CAST(decltype(System_Free), &Hxx2::Wrapper<Hxx2::Unresolved>::System_Free);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->System_GetAllocSize = PRIVATE_MAXON_MF_CAST(decltype(System_GetAllocSize), &Hxx2::Wrapper<Hxx2::Unresolved>::System_GetAllocSize);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->System_MemoryDiagnostics = PRIVATE_MAXON_MF_CAST(decltype(System_MemoryDiagnostics), &Hxx2::Wrapper<Hxx2::Unresolved>::System_MemoryDiagnostics);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->System_MemoryAddObserver = PRIVATE_MAXON_MF_CAST(decltype(System_MemoryAddObserver), &Hxx2::Wrapper<Hxx2::Unresolved>::System_MemoryAddObserver);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->System_SetMemoryAllocationThreshold = PRIVATE_MAXON_MF_CAST(decltype(System_SetMemoryAllocationThreshold), &Hxx2::Wrapper<Hxx2::Unresolved>::System_SetMemoryAllocationThreshold);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->System_GetCustomTimer = PRIVATE_MAXON_MF_CAST(decltype(System_GetCustomTimer), &Hxx2::Wrapper<Hxx2::Unresolved>::System_GetCustomTimer);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->System_GetConfigurationCount = PRIVATE_MAXON_MF_CAST(decltype(System_GetConfigurationCount), &Hxx2::Wrapper<Hxx2::Unresolved>::System_GetConfigurationCount);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->System_GetConfiguration = PRIVATE_MAXON_MF_CAST(decltype(System_GetConfiguration), &Hxx2::Wrapper<Hxx2::Unresolved>::System_GetConfiguration);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->System_ConfigurationRegister = PRIVATE_MAXON_MF_CAST(decltype(System_ConfigurationRegister), &Hxx2::Wrapper<Hxx2::Unresolved>::System_ConfigurationRegister);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->System_GetCriticalLog = PRIVATE_MAXON_MF_CAST(decltype(System_GetCriticalLog), &Hxx2::Wrapper<Hxx2::Unresolved>::System_GetCriticalLog);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->System_GetDefinitionCount = PRIVATE_MAXON_MF_CAST(decltype(System_GetDefinitionCount), &Hxx2::Wrapper<Hxx2::Unresolved>::System_GetDefinitionCount);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->System_GetVirtualInterfaceReference = PRIVATE_MAXON_MF_CAST(decltype(System_GetVirtualInterfaceReference), &Hxx2::Wrapper<Hxx2::Unresolved>::System_GetVirtualInterfaceReference);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->System_FindDefinition = PRIVATE_MAXON_MF_CAST(decltype(System_FindDefinition), &Hxx2::Wrapper<Hxx2::Unresolved>::System_FindDefinition);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->System_SetDebugErrorObserver = PRIVATE_MAXON_MF_CAST(decltype(System_SetDebugErrorObserver), &Hxx2::Wrapper<Hxx2::Unresolved>::System_SetDebugErrorObserver);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->System_ResetDebugErrorObserver = PRIVATE_MAXON_MF_CAST(decltype(System_ResetDebugErrorObserver), &Hxx2::Wrapper<Hxx2::Unresolved>::System_ResetDebugErrorObserver);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->System_SetCurrentError = PRIVATE_MAXON_MF_CAST(decltype(System_SetCurrentError), &Hxx2::Wrapper<Hxx2::Unresolved>::System_SetCurrentError);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->System_SetCurrentError_1 = PRIVATE_MAXON_MF_CAST(decltype(System_SetCurrentError_1), &Hxx2::Wrapper<Hxx2::Unresolved>::System_SetCurrentError_1);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->System_GetLastError = PRIVATE_MAXON_MF_CAST(decltype(System_GetLastError), &Hxx2::Wrapper<Hxx2::Unresolved>::System_GetLastError);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->System_SetDebugError = PRIVATE_MAXON_MF_CAST(decltype(System_SetDebugError), &Hxx2::Wrapper<Hxx2::Unresolved>::System_SetDebugError);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->System_GetDebugError = PRIVATE_MAXON_MF_CAST(decltype(System_GetDebugError), &Hxx2::Wrapper<Hxx2::Unresolved>::System_GetDebugError);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<const Id*>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->System_PrivateGetInternedId = PRIVATE_MAXON_MF_CAST(decltype(System_PrivateGetInternedId), &Hxx2::Wrapper<Hxx2::Unresolved>::System_PrivateGetInternedId);
		#else
		tbl->System_PrivateGetInternedId = PRIVATE_MAXON_MF_CAST(decltype(System_PrivateGetInternedId), &Hxx2::Wrapper<Hxx2::Unresolved>::System_PrivateGetInternedId);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->System_PrivateFreeInternedId = PRIVATE_MAXON_MF_CAST(decltype(System_PrivateFreeInternedId), &Hxx2::Wrapper<Hxx2::Unresolved>::System_PrivateFreeInternedId);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<const Block<const Binary* const>&>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->System_GetBinaries = PRIVATE_MAXON_MF_CAST(decltype(System_GetBinaries), &Hxx2::Wrapper<Hxx2::Unresolved>::System_GetBinaries);
		#else
		tbl->System_GetBinaries = PRIVATE_MAXON_MF_CAST(decltype(System_GetBinaries), &Hxx2::Wrapper<Hxx2::Unresolved>::System_GetBinaries);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->System_PrivateShowSynchronizedHashMapDiagnostics = PRIVATE_MAXON_MF_CAST(decltype(System_PrivateShowSynchronizedHashMapDiagnostics), &Hxx2::Wrapper<Hxx2::Unresolved>::System_PrivateShowSynchronizedHashMapDiagnostics);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->System_GetPreferencesPathSuffix = PRIVATE_MAXON_MF_CAST(decltype(System_GetPreferencesPathSuffix), &Hxx2::Wrapper<Hxx2::Unresolved>::System_GetPreferencesPathSuffix);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Id>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->System_GetApplicationId = PRIVATE_MAXON_MF_CAST(decltype(System_GetApplicationId), &Hxx2::Wrapper<Hxx2::Unresolved>::System_GetApplicationId);
		#else
		tbl->System_GetApplicationId = PRIVATE_MAXON_MF_CAST(decltype(System_GetApplicationId), &Hxx2::Wrapper<Hxx2::Unresolved>::System_GetApplicationId);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->System_SetApplicationType = PRIVATE_MAXON_MF_CAST(decltype(System_SetApplicationType), &Hxx2::Wrapper<Hxx2::Unresolved>::System_SetApplicationType);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->System_PrivateInitExternalDependency = PRIVATE_MAXON_MF_CAST(decltype(System_PrivateInitExternalDependency), &Hxx2::Wrapper<Hxx2::Unresolved>::System_PrivateInitExternalDependency);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->System_PrivateResetExternalDependency = PRIVATE_MAXON_MF_CAST(decltype(System_PrivateResetExternalDependency), &Hxx2::Wrapper<Hxx2::Unresolved>::System_PrivateResetExternalDependency);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<UniqueHash>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->System_PrivateGetUniqueHashCode = PRIVATE_MAXON_MF_CAST(decltype(System_PrivateGetUniqueHashCode), &Hxx2::Wrapper<Hxx2::Unresolved>::System_PrivateGetUniqueHashCode);
		#else
		tbl->System_PrivateGetUniqueHashCode = PRIVATE_MAXON_MF_CAST(decltype(System_PrivateGetUniqueHashCode), &Hxx2::Wrapper<Hxx2::Unresolved>::System_PrivateGetUniqueHashCode);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->System_PrivateHasherInitialize = PRIVATE_MAXON_MF_CAST(decltype(System_PrivateHasherInitialize), &Hxx2::Wrapper<Hxx2::Unresolved>::System_PrivateHasherInitialize);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->System_PrivateHasherCombine = PRIVATE_MAXON_MF_CAST(decltype(System_PrivateHasherCombine), &Hxx2::Wrapper<Hxx2::Unresolved>::System_PrivateHasherCombine);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->System_PrivateHasherCombine_1 = PRIVATE_MAXON_MF_CAST(decltype(System_PrivateHasherCombine_1), &Hxx2::Wrapper<Hxx2::Unresolved>::System_PrivateHasherCombine_1);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<UniqueHash>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->System_PrivateHasherFinialize = PRIVATE_MAXON_MF_CAST(decltype(System_PrivateHasherFinialize), &Hxx2::Wrapper<Hxx2::Unresolved>::System_PrivateHasherFinialize);
		#else
		tbl->System_PrivateHasherFinialize = PRIVATE_MAXON_MF_CAST(decltype(System_PrivateHasherFinialize), &Hxx2::Wrapper<Hxx2::Unresolved>::System_PrivateHasherFinialize);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->System_PrivateFreeWithDestructor = PRIVATE_MAXON_MF_CAST(decltype(System_PrivateFreeWithDestructor), &Hxx2::Wrapper<Hxx2::Unresolved>::System_PrivateFreeWithDestructor);
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
		| maxon::details::InstantiateNullReturnValue<UniqueHash>(OVERLOAD_MAX_RANK)
		| maxon::details::InstantiateNullReturnValue<const Block<const Binary* const>&>(OVERLOAD_MAX_RANK)
		;
	}
}
#endif
static maxon::details::ForceEvaluation s_forceEval_system(0
	| maxon::System::PrivateInstantiateNullValueHelper<maxon::Int>()
);
