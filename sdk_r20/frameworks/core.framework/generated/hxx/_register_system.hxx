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
/// @endcond

	const maxon::Char* const System::MTable::_ids = 
		"_ConsoleOutput@cf78c5c1924d0b0e\0" // _ConsoleOutput(const Char* s, const SourceLocation& loc)
		"GetConsoleOutputType@20c32d4d521\0" // GetConsoleOutputType()
		"Alloc@ea0e9c2880c712f4\0" // Alloc(Int size, const SourceLocation& location)
		"AllocClear@ea0e9c2880c712f4\0" // AllocClear(Int size, const SourceLocation& location)
		"Realloc@2162956cfcc7778a\0" // Realloc(void* data, Int size, const SourceLocation& location)
		"Free@9d3e826847b8afb9\0" // Free(const void* data)
		"GetAllocSize@733ab7b84a501\0" // GetAllocSize(void* data)
		"MemoryDiagnostics@b13b1bfb893ef329\0" // MemoryDiagnostics(MEMORYDIAGNOSTICSMODE mode, Int* totalAllocation, Int* freePhysicalMemoryEstimate)
		"MemoryAddObserver@17054db324f65bd8\0" // MemoryAddObserver(MEMORYOBSERVERMODE mode, Delegate<void()>&& observer)
		"SetMemoryAllocationThreshold@b6e52695b185a\0" // SetMemoryAllocationThreshold(UInt warnMemoryAllocationThreshold)
		"GetCustomTimer@3917f98b07da\0" // GetCustomTimer()
		"GetConfigurationCount@4386c6f\0" // GetConfigurationCount()
		"GetConfiguration@7ef3f5cb1a6df6e5\0" // GetConfiguration(Int index, ConfigInit& config)
		"ConfigurationRegister@0c43770b3722cf85\0" // ConfigurationRegister(const ConfigInit& config)
		"GetCriticalLog@3dfca79618bd0edc\0" // GetCriticalLog(Int index, Int* count)
		"GetDefinitionCount@f88e3537d9c8d941\0" // GetDefinitionCount(EntityBase::TYPE type)
		"GetVirtualInterfaceReference@f133fc078980835d\0" // GetVirtualInterfaceReference(const Id& idWithoutHash)
		"FindDefinition@bfd492a4ef1f9284\0" // FindDefinition(EntityBase::TYPE type, const Id& eid)
		"SetDebugErrorObserver@17e3cdfeb8e6c2fc\0" // SetDebugErrorObserver(Delegate<void(const ErrorInterface*)>&& observer)
		"ResetDebugErrorObserver@1625bfafc6cdb9c\0" // ResetDebugErrorObserver(void* observer)
		"SetCurrentError@3236b8134637e204\0" // SetCurrentError(const Error& error)
		"SetCurrentError@8985c0f811dcb1df\0" // SetCurrentError(Error&& error)
		"GetLastError@f0c5c3de858bdf3f\0" // GetLastError()
		"PrivateGetInternedId@b33c653c5378ea0d\0" // PrivateGetInternedId(const Id& value)
		"GetBinaries@4011b8604c8649a3\0" // GetBinaries(Block<const ModuleInfo* const>& result)
		"GetBinaries@a2d2c677af4ddeeb\0" // GetBinaries()
		"FreeWithDestructorI@6b1a30c0b982b124\0" // FreeWithDestructorI(void* object, DestructorPointer destruct)
/// @endcond

	"";
	class System::Unresolved : public System
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
		static Result<const Id*> PrivateGetInternedId(const Id& value) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return System::PrivateGetInternedId(value); return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::UNRESOLVED);}
		static void GetBinaries(Block<const ModuleInfo* const>& result) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return System::GetBinaries(result); return maxon::PrivateLogNullptrError();}
		static const Block<const Binary* const>& GetBinaries() { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return System::GetBinaries(); return maxon::PrivateIncompleteNullReturnValue<const Block<const Binary* const>&>(maxon::NULL_RETURN_REASON::UNRESOLVED, OVERLOAD_MAX_RANK);}
		static void FreeWithDestructorI(void* object, DestructorPointer destruct) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return System::FreeWithDestructorI(object, std::forward<DestructorPointer>(destruct)); return maxon::PrivateLogNullptrError();}
/// @endcond

	};
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
		maxon::details::NullReturnType<Result<const Id*>>::value,
		maxon::details::NullReturnType<void>::value,
		maxon::details::NullReturnType<const Block<const Binary* const>&>::value,
		maxon::details::NullReturnType<void>::value,
/// @endcond

		maxon::NULL_RETURN_TYPE::OTHER
	};
#endif
	maxon::Bool System::MTable::InitUnresolved(maxon::NonvirtualInterfaceReference::UnresolvedAssembler assembler, MTable* tbl)
	{
	#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
	#else
		tbl->_System__ConsoleOutput = &Wrapper<Unresolved>::_System__ConsoleOutput;
	#endif
	#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<OUTPUT>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_System_GetConsoleOutputType = &Wrapper<Unresolved>::_System_GetConsoleOutputType;
	#else
		tbl->_System_GetConsoleOutputType = &Wrapper<Unresolved>::_System_GetConsoleOutputType;
	#endif
	#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
	#else
		tbl->_System_Alloc = &Wrapper<Unresolved>::_System_Alloc;
	#endif
	#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
	#else
		tbl->_System_AllocClear = &Wrapper<Unresolved>::_System_AllocClear;
	#endif
	#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
	#else
		tbl->_System_Realloc = &Wrapper<Unresolved>::_System_Realloc;
	#endif
	#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
	#else
		tbl->_System_Free = &Wrapper<Unresolved>::_System_Free;
	#endif
	#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
	#else
		tbl->_System_GetAllocSize = &Wrapper<Unresolved>::_System_GetAllocSize;
	#endif
	#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
	#else
		tbl->_System_MemoryDiagnostics = &Wrapper<Unresolved>::_System_MemoryDiagnostics;
	#endif
	#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
	#else
		tbl->_System_MemoryAddObserver = &Wrapper<Unresolved>::_System_MemoryAddObserver;
	#endif
	#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
	#else
		tbl->_System_SetMemoryAllocationThreshold = &Wrapper<Unresolved>::_System_SetMemoryAllocationThreshold;
	#endif
	#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
	#else
		tbl->_System_GetCustomTimer = &Wrapper<Unresolved>::_System_GetCustomTimer;
	#endif
	#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
	#else
		tbl->_System_GetConfigurationCount = &Wrapper<Unresolved>::_System_GetConfigurationCount;
	#endif
	#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
	#else
		tbl->_System_GetConfiguration = &Wrapper<Unresolved>::_System_GetConfiguration;
	#endif
	#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
	#else
		tbl->_System_ConfigurationRegister = &Wrapper<Unresolved>::_System_ConfigurationRegister;
	#endif
	#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
	#else
		tbl->_System_GetCriticalLog = &Wrapper<Unresolved>::_System_GetCriticalLog;
	#endif
	#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
	#else
		tbl->_System_GetDefinitionCount = &Wrapper<Unresolved>::_System_GetDefinitionCount;
	#endif
	#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
	#else
		tbl->_System_GetVirtualInterfaceReference = &Wrapper<Unresolved>::_System_GetVirtualInterfaceReference;
	#endif
	#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
	#else
		tbl->_System_FindDefinition = &Wrapper<Unresolved>::_System_FindDefinition;
	#endif
	#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
	#else
		tbl->_System_SetDebugErrorObserver = &Wrapper<Unresolved>::_System_SetDebugErrorObserver;
	#endif
	#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
	#else
		tbl->_System_ResetDebugErrorObserver = &Wrapper<Unresolved>::_System_ResetDebugErrorObserver;
	#endif
	#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
	#else
		tbl->_System_SetCurrentError = &Wrapper<Unresolved>::_System_SetCurrentError;
	#endif
	#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
	#else
		tbl->_System_SetCurrentError_1 = &Wrapper<Unresolved>::_System_SetCurrentError_1;
	#endif
	#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
	#else
		tbl->_System_GetLastError = &Wrapper<Unresolved>::_System_GetLastError;
	#endif
	#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<const Id*>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_System_PrivateGetInternedId = &Wrapper<Unresolved>::_System_PrivateGetInternedId;
	#else
		tbl->_System_PrivateGetInternedId = &Wrapper<Unresolved>::_System_PrivateGetInternedId;
	#endif
	#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
	#else
		tbl->_System_GetBinaries = &Wrapper<Unresolved>::_System_GetBinaries;
	#endif
	#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<const Block<const Binary* const>&>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_System_GetBinaries_1 = &Wrapper<Unresolved>::_System_GetBinaries_1;
	#else
		tbl->_System_GetBinaries_1 = &Wrapper<Unresolved>::_System_GetBinaries_1;
	#endif
	#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
	#else
		tbl->_System_FreeWithDestructorI = &Wrapper<Unresolved>::_System_FreeWithDestructorI;
	#endif
/// @endcond

	#ifdef PRIVATE_MAXON_ASSEMBLE_UNRESOLVED
		return assembler(&_interface, (maxon::Char*) tbl, _returnTypes, SIZEOF(_returnTypes) - 1);
	#else
		return true;
	#endif
	}
	MAXON_INTERFACE_REGISTER(System, "net.maxon.interface.system", nullptr);
	template <typename DUMMY> maxon::Int System::PrivateInstantiateNullValueHelper()
	{
		return 0
		| maxon::details::InstantiateNullReturnValue<OUTPUT>(OVERLOAD_MAX_RANK)
		| maxon::details::InstantiateNullReturnValue<const Block<const Binary* const>&>(OVERLOAD_MAX_RANK)
		;
	}
}
#endif
static maxon::details::ForceEvaluation s_forceEval_system(0
	| maxon::System::PrivateInstantiateNullValueHelper<maxon::Int>()
);
