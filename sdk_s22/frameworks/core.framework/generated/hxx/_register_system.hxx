#if 1
namespace maxon
{
	namespace enum37 { enum class MEMORYDIAGNOSTICSMODE : Int
		{
			ESTIMATEONLY	= -1,	///< Just return current total allocation estimate.
			QUIET					= 0,	///< Just return allocation numbers.
			VERBOSE				= 1,	///< Additional details will be sent to the console.
			LEAKGRAPH			= 2,	///< Create a memory leak graph (circular references).
			PRIVATE_OFF		= 3,
			PRIVATE_ON		= 4
		} ; }
	maxon::String PrivateToString_MEMORYDIAGNOSTICSMODE37(std::underlying_type<enum37::MEMORYDIAGNOSTICSMODE>::type x, const maxon::FormatStatement* fmt, void*)
	{
		const maxon::UInt64 values[] = {(maxon::UInt64) enum37::MEMORYDIAGNOSTICSMODE::ESTIMATEONLY, (maxon::UInt64) enum37::MEMORYDIAGNOSTICSMODE::QUIET, (maxon::UInt64) enum37::MEMORYDIAGNOSTICSMODE::VERBOSE, (maxon::UInt64) enum37::MEMORYDIAGNOSTICSMODE::LEAKGRAPH, (maxon::UInt64) enum37::MEMORYDIAGNOSTICSMODE::PRIVATE_OFF, (maxon::UInt64) enum37::MEMORYDIAGNOSTICSMODE::PRIVATE_ON};
		return maxon::StringInterface::PrivateEnumToString((maxon::UInt64) x, "System::MEMORYDIAGNOSTICSMODE", SIZEOF(x), false, values, "ESTIMATEONLY\0QUIET\0VERBOSE\0LEAKGRAPH\0PRIVATE_OFF\0PRIVATE_ON\0", fmt);
	}
	namespace enum44 { enum class MEMORYOBSERVERMODE : Int
		{
			LOWMEM_CLEANUP = 0,		///< The observer should free resources/caches and then the allocator will retry.
			LOWMEM_FAILURE = 1,		///< An allocation failed (even retry didn't change that).
			WARNMEM_LIMIT = 2			///< The allocations exceed a user specified amount of memory.
		} ; }
	maxon::String PrivateToString_MEMORYOBSERVERMODE44(std::underlying_type<enum44::MEMORYOBSERVERMODE>::type x, const maxon::FormatStatement* fmt, void*)
	{
		const maxon::UInt64 values[] = {(maxon::UInt64) enum44::MEMORYOBSERVERMODE::LOWMEM_CLEANUP, (maxon::UInt64) enum44::MEMORYOBSERVERMODE::LOWMEM_FAILURE, (maxon::UInt64) enum44::MEMORYOBSERVERMODE::WARNMEM_LIMIT};
		return maxon::StringInterface::PrivateEnumToString((maxon::UInt64) x, "System::MEMORYOBSERVERMODE", SIZEOF(x), false, values, "LOWMEM_CLEANUP\0LOWMEM_FAILURE\0WARNMEM_LIMIT\0", fmt);
	}
	namespace enum51 { enum class SPECIALBEHAVIOR : Int
		{
			NONE											= 0,
			OMIT_HELP									= (1 << 0),	///< If set "-help" will not start help mode of the underlying base system, whereas "help" will. This is legacy behavior for C4D.
			DONTWARN_MISSINGARGUMENTS	= (1 << 1)	///< If set there will be no output in the console if an argument is passed but not defined in the code.
		} ; }
	maxon::String PrivateToString_SPECIALBEHAVIOR51(std::underlying_type<enum51::SPECIALBEHAVIOR>::type x, const maxon::FormatStatement* fmt, void*)
	{
		const maxon::UInt64 values[] = {(maxon::UInt64) enum51::SPECIALBEHAVIOR::NONE, (maxon::UInt64) enum51::SPECIALBEHAVIOR::OMIT_HELP, (maxon::UInt64) enum51::SPECIALBEHAVIOR::DONTWARN_MISSINGARGUMENTS};
		return maxon::StringInterface::PrivateEnumToString((maxon::UInt64) x, "System::SPECIALBEHAVIOR", SIZEOF(x), true, values, "NONE\0OMIT_HELP\0DONTWARN_MISSINGARGUMENTS\0", fmt);
	}
	const maxon::Char* const System::MTable::_ids = 
		"_ConsoleOutput@cf78c5c1924d0b0e\0" // void _ConsoleOutput(const Char* s, const SourceLocation& loc)
		"GetConsoleOutputType@20c32d4d521\0" // OUTPUT GetConsoleOutputType()
		"Alloc@ea0e9c2880c712f4\0" // void* Alloc(Int size, const SourceLocation& location)
		"AllocClear@ea0e9c2880c712f4\0" // void* AllocClear(Int size, const SourceLocation& location)
		"Realloc@2162956cfcc7778a\0" // void* Realloc(void* data, Int size, const SourceLocation& location)
		"Free@9d3e826847b8afb9\0" // void Free(const void* data)
		"GetAllocSize@733ab7b84a501\0" // Int GetAllocSize(void* data)
		"MemoryDiagnostics@b13b1bfb893ef329\0" // Int MemoryDiagnostics(MEMORYDIAGNOSTICSMODE mode, Int* totalAllocation, Int* freePhysicalMemoryEstimate)
		"MemoryAddObserver@17054db324f65bd8\0" // Bool MemoryAddObserver(MEMORYOBSERVERMODE mode, Delegate<void()>&& observer)
		"SetMemoryAllocationThreshold@b6e52695b185a\0" // void SetMemoryAllocationThreshold(UInt warnMemoryAllocationThreshold)
		"GetCustomTimer@3917f98b07da\0" // Float64 GetCustomTimer()
		"GetConfigurationCount@4386c6f\0" // Int GetConfigurationCount()
		"GetConfiguration@7ef3f5cb1a6df6e5\0" // Bool GetConfiguration(Int index, ConfigInit& config)
		"ConfigurationRegister@0c43770b3722cf85\0" // Bool ConfigurationRegister(const ConfigInit& config)
		"GetCriticalLog@3dfca79618bd0edc\0" // Char* GetCriticalLog(Int index, Int* count)
		"GetDefinitionCount@f88e3537d9c8d941\0" // Int GetDefinitionCount(EntityBase::TYPE type)
		"GetVirtualInterfaceReference@f133fc078980835d\0" // const InterfaceReference* GetVirtualInterfaceReference(const Id& idWithoutHash)
		"FindDefinition@bfd492a4ef1f9284\0" // EntityDefinition* FindDefinition(EntityBase::TYPE type, const Id& eid)
		"SetDebugErrorObserver@17e3cdfeb8e6c2fc\0" // void* SetDebugErrorObserver(Delegate<void(const ErrorInterface*)>&& observer)
		"ResetDebugErrorObserver@1625bfafc6cdb9c\0" // void ResetDebugErrorObserver(void* observer)
		"SetCurrentError@3236b8134637e204\0" // const Error* SetCurrentError(const Error& error)
		"SetCurrentError@8985c0f811dcb1df\0" // const Error* SetCurrentError(Error&& error)
		"GetLastError@f0c5c3de858bdf3f\0" // const Error* GetLastError()
		"SetDebugError@b9bc3af5feaf94ea\0" // void SetDebugError(const Error* preallocated, const Error& error)
		"GetDebugError@1c7b97313427d07d\0" // const ErrorInterface* GetDebugError(const Error* preallocated)
		"PrivateGetInternedId@b33c653c5378ea0d\0" // Result<const Id*> PrivateGetInternedId(const Id& value)
		"PrivateFreeInternedId@908beb5b7acca4a0\0" // void PrivateFreeInternedId(const Id* ptr)
		"GetBinaries@a2d2c677af4ddeeb\0" // const Block<const Binary* const>& GetBinaries()
		"PrivateShowSynchronizedHashMapDiagnostics@a98b8922ca309d15\0" // void PrivateShowSynchronizedHashMapDiagnostics(Int size, Int capacity, const Char* signature)
		"GetPreferencesPathSuffix@629b065104619f17\0" // const Char* GetPreferencesPathSuffix()
		"GetApplicationId@22aadb\0" // Id GetApplicationId()
		"SetApplicationType@9d3e8267f04b751b\0" // void SetApplicationType(const Char* dna)
		"FreeWithDestructorI@6b1a30c0b982b124\0" // void FreeWithDestructorI(void* object, DestructorPointer destruct)
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
