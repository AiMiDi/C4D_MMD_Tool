#ifndef SYSTEM_H__
#define SYSTEM_H__

#include "maxon/interfacebase.h"

namespace maxon
{

/// @addtogroup SYSTEM System
/// @{

struct ConfigInit;
class StrongReferenceCounter;
template <typename ARGS> class Delegate;

using SystemFreeObject = void (*)(void* self);
using DestructorPointer = void (*)(void*);

MAXON_MEMBERFUNCTION_DETECTOR(GetReferenceCounter);

// List of common application Ids as returned by System::GetApplicationId
// Due to the dependency system MAXON_ATTRIBUTE cannot be used here.
namespace APPLICATIONID
{
	// declare IDs

	static const Id UNKNOWN = Id("net.maxon.application.unknown");
	static const Id LITE = Id("net.maxon.application.lite");
	static const Id CINEBENCH = Id("net.maxon.application.cinebench");
	static const Id UPDATER = Id("net.maxon.application.updater");
	static const Id TEAMRENDER_SERVER = Id("net.maxon.application.trserver");
	static const Id TEAMRENDER_CLIENT = Id("net.maxon.application.trclient");
	static const Id CINEMA4D = Id("net.maxon.application.cinema4d");
	static const Id COMMANDLINE = Id("net.maxon.application.commandline");
	static const Id CINEWARE = Id("net.maxon.application.cineware");
	static const Id PYTHON = Id("net.maxon.application.python");
	static const Id PYTHON3 = Id("net.maxon.application.python3");
}

//----------------------------------------------------------------------------------------
/// Application wide system functions. Do not use any of those functions directly.
/// Implement this interface to link against the kernel library.
//----------------------------------------------------------------------------------------
class System
{
	MAXON_INTERFACE_NONVIRTUAL(System, MAXON_REFERENCE_STATIC, "net.maxon.interface.system");
public:
	enum class MEMORYDIAGNOSTICSMODE : Int
	{
		ESTIMATEONLY	= -1,	///< Just return current total allocation estimate.
		QUIET					= 0,	///< Just return allocation numbers.
		VERBOSE				= 1,	///< Additional details will be sent to the console.
		LEAKGRAPH			= 2,	///< Create a memory leak graph (circular references).
		PRIVATE_OFF		= 3,
		PRIVATE_ON		= 4
	} MAXON_ENUM_LIST_CLASS(MEMORYDIAGNOSTICSMODE);

	enum class MEMORYOBSERVERMODE : Int
	{
		LOWMEM_CLEANUP = 0,		///< The observer should free resources/caches and then the allocator will retry.
		LOWMEM_FAILURE = 1,		///< An allocation failed (even retry didn't change that).
		WARNMEM_LIMIT = 2			///< The allocations exceed a user specified amount of memory.
	} MAXON_ENUM_LIST_CLASS(MEMORYOBSERVERMODE);

	enum class SPECIALBEHAVIOR : Int
	{
		NONE											= 0,
		OMIT_HELP									= (1 << 0),	///< If set "-help" will not start help mode of the underlying base system, whereas "help" will. This is legacy behavior for C4D.
		DONTWARN_MISSINGARGUMENTS	= (1 << 1)	///< If set there will be no output in the console if an argument is passed but not defined in the code.
	} MAXON_ENUM_FLAGS_CLASS(SPECIALBEHAVIOR);

	//----------------------------------------------------------------------------------------
	/// Prints debug information into the console window.
	/// @param[in] s									Char* to print out.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD void _ConsoleOutput(const Char* s, const SourceLocation& loc);

	//----------------------------------------------------------------------------------------
	/// Retrieves which types of output shall be supported.
	/// @return												Diagnostic, warning and/or critical output.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD OUTPUT GetConsoleOutputType();

	//----------------------------------------------------------------------------------------
	/// Allocates a memory block, does not clear memory (similar to malloc).
	/// The memory is not cleared, it may contain a certain byte pattern in debug mode.
	/// @param[in] size								Block size in bytes (values < 0 will return nullptr).
	/// @param[in] location						MemoryAllocationStructure (filled out by a define).
	/// @return												Memory block address or nullptr.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD void* Alloc(Int size, const SourceLocation& location);

	//----------------------------------------------------------------------------------------
	/// Allocates a memory block and clears it (similar to calloc).
	/// @param[in] size								Block size in bytes (values < 0 will return nullptr).
	/// @param[in] location						MemoryAllocationStructure (filled out by a define).
	/// @return												Memory block address or nullptr.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD void* AllocClear(Int size, const SourceLocation& location);

	//----------------------------------------------------------------------------------------
	/// Resizes a memory block (similar to realloc).
	/// The additional memory is not cleared, it may contain a certain byte pattern in debug mode.
	/// @param[in] data								Current memory block (can be nullptr).
	/// @param[in] size								New block size in bytes (values < 0 will return nullptr).
	/// @param[in] location						MemoryAllocationStructure (filled out by a define).
	/// @return												Memory block address or nullptr if resize is not possible (p is still valid in this case).
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD void* Realloc(void* data, Int size, const SourceLocation& location);

	//----------------------------------------------------------------------------------------
	/// Frees a memory block (free).
	/// @param[in] data								Memory block address (can be nullptr).
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD void Free(const void* data);

	template <typename T> static MAXON_FUNCTION void FreeWithDestructor(T* object, void (*destructor)(T*))
	{
		FreeWithDestructorI((void*) object, (void (*)(void*)) destructor);
	}

	//----------------------------------------------------------------------------------------
	/// Returns the size of a memory block.
	/// @param[in] data								Memory block address (can be nullptr, but otherwise must be valid).
	/// @return												Size of the allocated block in bytes.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Int GetAllocSize(void* data);

	//----------------------------------------------------------------------------------------
	/// Returns information about memory usage and optionally prints details to the console.
	/// @param[in] mode								See MEMORYDIAGNOSTICSMODE.
	/// @param[out] totalAllocation		Used to return the total amount of memory allocated including blocks being cached, used for management and so on. This might be considerably bigger than what was allocated by the application.
	/// @param[out] freePhysicalMemoryEstimate	Used to return a very rough estimate of the free physical memory (if any).
	/// @return												Memory allocated by the application in bytes.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Int MemoryDiagnostics(MEMORYDIAGNOSTICSMODE mode = MEMORYDIAGNOSTICSMODE::VERBOSE, Int* totalAllocation = nullptr, Int* freePhysicalMemoryEstimate = nullptr);

	//----------------------------------------------------------------------------------------
	/// Adds an observer for low memory situations. The observer will be active until shutdown.
	/// @param[in] mode								See MEMORYOBSERVERMODE.
	/// @param[in] observer						Observer.
	/// @return												True on success.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Bool MemoryAddObserver(MEMORYOBSERVERMODE mode, Delegate<void()>&& observer);

	//----------------------------------------------------------------------------------------
	/// Sets the threshold value when observers of mode MEMORYOBSERVERMODE::WARNMEM_LIMIT will be executed. Calling the function again overwrites the older value.
	/// @param[in] warnMemoryAllocationThreshold	The value when the observer will be executed.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD void SetMemoryAllocationThreshold(UInt warnMemoryAllocationThreshold);

	//----------------------------------------------------------------------------------------
	/// Returns the current system time which is being used by the Timer class.
	/// @return												Seconds of the system time.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Float64 GetCustomTimer();

	//----------------------------------------------------------------------------------------
	/// Returns the number of configuration values registered with ConfigurationRegister
	/// @return												Number of configuration values.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Int GetConfigurationCount();

	//----------------------------------------------------------------------------------------
	/// Gets the configuration value by a given index.
	/// @param[in] index							Index of the configuration value. @em 0 <= @formatParam{index} < GetConfigurationCount()
	/// @return												True on success or false if the index is out of range.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Bool GetConfiguration(Int index, ConfigInit& config);

	//----------------------------------------------------------------------------------------
	/// Registers a configuration value @ref ConfigValues with the main application.
	/// @param[in] config							The configuration value and related data (default, limits etc.).
	/// @return												Success of the registration.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Bool ConfigurationRegister(const ConfigInit& config);

	//----------------------------------------------------------------------------------------
	/// Reads information from the critical log (which is automatically stored in memory). It contains messages that were generated calling CriticalOutput().
	/// THREADSAFE.
	/// @param[in] index							Index to the log, starting at zero. If the return value is nullptr then no more log entries exist.
	/// @param[out] count							Pointer to a value that will receive the number of log entries or nullptr.
	/// @return												C-Style string containing the critical message or nullptr if no log entry exists for this index.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Char* GetCriticalLog(Int index, Int* count);

	//----------------------------------------------------------------------------------------
	/// Returns the total number of definitions for the given entity type. This is used for
	/// statistics about the complexity of the whole application.
	/// @param[in] type								Entity type. Use EntityBase::TYPE::COUNT for the total number of methods of all (virtual and non-virtual) interfaces.
	/// @return												Number of definitions of the given type.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Int GetDefinitionCount(EntityBase::TYPE type);

	//----------------------------------------------------------------------------------------
	/// Returns the virtual references of a given class.
	/// @param[in] idWithoutHash			Class ID without hash.
	/// @return												Found interface references
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD const InterfaceReference* GetVirtualInterfaceReference(const Id& idWithoutHash);

	//----------------------------------------------------------------------------------------
	/// Returns the definition of the given entity type.
	/// @param[in] type								Entity type. Use EntityBase::TYPE::COUNT for the total number of methods of all (virtual and non-virtual) interfaces.
	/// @param[in] eid								Entity id.
	/// @return												Found EntityDefinition or nullptr if no entity was found with the given name or type.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD EntityDefinition* FindDefinition(EntityBase::TYPE type, const Id& eid);

	//----------------------------------------------------------------------------------------
	/// Sets a callback which shall be invoked when an error occurs. This should be used only for
	/// debugging purposes. For example, if you want to have a DebugStop on any error during
	/// a function call, you can write:
	/// @code
	/// void* callback = System::SetDebugErrorObserver([] (const ErrorInterface* error) { DiagnosticOutput("@", error); DebugStop(); });
	/// SomeFunctionToDebug();
	/// System::ResetDebugErrorObserver(callback);
	/// @endcode
	/// You could even make the DebugStop() depend on the type of the error by checking the
	/// type of the error parameter.
	///
	/// You should clear the error callback after the code to debug by calling ResetErrorCallback().
	/// @warning This method is not thread-safe.
	/// @param[in] observer						Observer for errors.
	/// @return												Pointer to the installed observer or nullptr on failure.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD void* SetDebugErrorObserver(Delegate<void(const ErrorInterface*)>&& observer);

	//----------------------------------------------------------------------------------------
	/// Resets a previously set error callback.
	/// @warning This method is not thread-safe.
	/// @see SetErrorCallback
	/// @param[in] observer						The observer to remove.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD void ResetDebugErrorObserver(void* observer);

	// Since ThreadServices includes error.h we can't define these over there. If we'll need more methods we should add an ErrorServices interface.
	static MAXON_METHOD const Error* SetCurrentError(const Error& error);
	static MAXON_METHOD const Error* SetCurrentError(Error&& error);
	static MAXON_METHOD const Error* GetLastError();
	static MAXON_METHOD void SetDebugError(const Error* preallocated, const Error& error);
	static MAXON_METHOD const ErrorInterface* GetDebugError(const Error* preallocated);

	//----------------------------------------------------------------------------------------
	/// @return												Nullptr indicates OutOfMemory.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<const Id*> PrivateGetInternedId(const Id& value);

	static MAXON_METHOD void PrivateFreeInternedId(const Id* ptr);

	//----------------------------------------------------------------------------------------
	/// Returns the reference counter for classes which do not implement custom AddReference/RemoveReference methods.
	//----------------------------------------------------------------------------------------
	static StrongReferenceCounter& GetReferenceCounter(const void* object)
	{
		return StrongReferenceCounter::Get(object);
	}

	static MAXON_METHOD const Block<const Binary* const>& GetBinaries();

	static MAXON_METHOD void PrivateShowSynchronizedHashMapDiagnostics(Int size, Int capacity, const Char* signature);

	static MAXON_METHOD const Char* GetPreferencesPathSuffix();

	//----------------------------------------------------------------------------------------
	/// Returns the kind of application. Common definitions can be found in APPLICATIONID.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Id GetApplicationId();

	static MAXON_METHOD void SetApplicationType(const Char* dna);

private:
	//----------------------------------------------------------------------------------------
	/// @param[in] object							Object/memory block address (guaranteed not to be nullptr).
	/// @param[in] destruct						Object destructor (guaranteed not to be nullptr).
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD void FreeWithDestructorI(void* object, DestructorPointer destruct);

/// @endcond
};

namespace details
{
template <typename T> StrongReferenceCounter& PrivateGetReferenceCounter(const T* object)
{
	return System::GetReferenceCounter(object);
}

template <typename T> void PrivateFreeWithDestructor(const T* obj)
{
	// For types which do not require a destructor call Free directly.
	if (std::is_scalar<T>::value)
	{
		System::Free((void*) obj);
	}
	else
	{
		using T_NONCONST = typename std::remove_const<T>::type;
		DestructorPointer ptr = DestructorPointer(static_cast<void(*)(T_NONCONST*)>(&Destruct<T_NONCONST>));
		System::FreeWithDestructor((void*)obj, ptr);
	}
}

}
class CoreThread;

//----------------------------------------------------------------------------------------
extern System::SPECIALBEHAVIOR g_systemBehavior; ///< Defines mostly legacy behaviour.

// include autogenerated headerfile here
#include "system1.hxx"
// include autogenerated headerfile here
#include "system2.hxx"

/// @}

} // namespace maxon



#endif // SYSTEM_H__
