#ifndef VM_H__
#define VM_H__

#include "maxon/apibase.h"
#include "maxon/interface.h"
#include "maxon/url.h"
#include "maxon/datatypebase.h"
#include "maxon/datadictionary.h"
#include "maxon/tuple.h"
#include "maxon/blockarray.h"
#include "maxon/registrybase.h"

namespace maxon
{

enum class VMSETTINGS
{
	MOVE_ERRORS_TO_RESULT,
	USE_AUTO_GIL
} MAXON_ENUM_FLAGS(VMSETTINGS);

// for the settings Dictionary
enum class VMINITSETTINGS
{
	CPYTHON_ADDITIONAL_SYS_PATH,				///< maxon::Url
	CPYTHON_INTERPRETERFLAGS,						///< py::PYTHONFLAG
	CPYTHON_SUBINTERPRETER,							///< Bool

	PYPY_EXECUTABLE											///< Private.
} MAXON_ENUM_LIST(VMINITSETTINGS);

enum class ERRORHANDLING
{
	PRINT,                  ///<  Any thrown exception will be handled internally
	CLEAR,                  ///<  Any thrown exception will be cleared automatically
	REDIRECT								///<  Any thrown exception will result in a corresponding maxon.Error. The internal error state of the virtual machine is untouched.
} MAXON_ENUM_LIST(ERRORHANDLING);

void DiagnosticOutputFlags(EntityBase::FLAGS flags);
void DiagnosticOutputValueKind(const DataType& dt);

// Helper class to get the offset of _value of the base address of Result<...>
struct ResultOffsetHelper : public Result<Generic*>
{
	using ResultBase<Generic*>::_value;
};

class LocalStringStorage
{
public:
	MAXON_IMPLICIT LocalStringStorage(const String& str)
	{
		if (_arr.Resize(str.GetLength() + 1) == OK)
			MAXON_WARN_MUTE_UNUSED str.GetCStringBlock(_arr);
	}

	LocalStringStorage()
	{

	}

	LocalStringStorage(LocalStringStorage&& o) : _arr(std::move(o._arr))
	{
	}

	operator const Char*() const
	{
		return _arr.GetFirst();
	}

	Int GetLength() const
	{
		return _arr.GetCount() - 1;
	}

private:
	BaseArray<Char> _arr;
};

enum class DEFAULTRUNTIME
{
	NONE,
	SYSTEM_27,
	SYSTEM_36,

// #ifdef MAXON_TARGET_WINDOWS
	DEBUG_27_VS2008, // For Windows Only
	DEBUG_27_VS2013, // For Windows Only
	DEBUG_27_VS2015, // For Windows Only
	DEBUG_36_VS2015, // For Windows Only

	RELEASE_27_VS2008, // For Windows Only
	RELEASE_27_VS2015, // For Windows Only
	RELEASE_36_VS2015, // For Windows Only
// #else
	DEBUG_27,
	RELEASE_27,

	DEBUG_36,
	RELEASE_36,
// #endif

	DEFAULT_27, // auto detect of debug (and vs version on win)
	DEFAULT_36, // auto detect of debug (and vs version on win)

	DEFAULT
} MAXON_ENUM_LIST(DEFAULTRUNTIME);

//----------------------------------------------------------------------------------------
/// A helper struct containg information about a virtual machine and it's libraries.
//----------------------------------------------------------------------------------------
struct Runtime
{
	Int _majorVersion = 0;																	// Major version.
	Int _minorVersion = 0;																	// Minor version.
	Int _microVersion = 0;																	// Micro version.

	Url _path;																							// Default path to the virtual machine.
	Url _home;																							// Default home path to the virtual machine.
	Bool _isRelease = false;																// True if the virtual machine is in release- or debug mode.
	Bool _systemLib = false;																// True if the virtual machine is installed on the system, or is part of Cinema 4D.
	DEFAULTRUNTIME _defaultRuntime = DEFAULTRUNTIME::NONE;	// Default runtime information.

	Runtime() = default;
	Runtime(Int majorVersion, Int minorVersion, Int microVersion, Url path, Url home, Bool isRelease, Bool systemLib, DEFAULTRUNTIME _private = DEFAULTRUNTIME::NONE) : _majorVersion(majorVersion), _minorVersion(minorVersion), _microVersion(microVersion), _path(path), _home(home), _isRelease(isRelease), _systemLib(systemLib), _defaultRuntime(_private) { }
};

//----------------------------------------------------------------------------------------
/// A helper struct to initialized a virtual machine. Can be initialized by a predefined enum, or a given custom runtime object.
//----------------------------------------------------------------------------------------
struct LoadRuntime
{
public:
	MAXON_IMPLICIT LoadRuntime(DEFAULTRUNTIME defaultRuntime) : _defaultRuntime(defaultRuntime) { }
	MAXON_IMPLICIT LoadRuntime(const Runtime& runtime) : _runtime(&runtime) { }

	const Runtime* GetRuntime() const
	{
		return _runtime;
	}

	DEFAULTRUNTIME GetDefaultRuntime() const
	{
		return _defaultRuntime;
	}

private:
	DEFAULTRUNTIME _defaultRuntime = DEFAULTRUNTIME::NONE;
	const Url _runtimePath {};
	const Runtime* _runtime = nullptr;
};

//----------------------------------------------------------------------------------------
/// A helper interface with convenient functions, which are needed when dealing with other
/// interfaces in this framework
//----------------------------------------------------------------------------------------
class LibraryInterface : MAXON_INTERFACE_BASES(ObjectInterface)
{
	MAXON_INTERFACE(LibraryInterface, MAXON_REFERENCE_NORMAL, "net.maxon.python.interface.library");

public:
	//----------------------------------------------------------------------------------------
	/// Checks if a console is attached to the current process
	/// @return												True if a console is attached, otherwise False.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Bool ConsoleIsAvailable();
	
#ifdef MAXON_TARGET_WINDOWS
	//----------------------------------------------------------------------------------------
	/// Returns the Visual Studio version of a given MSC compiler version.
	/// @param[in] compilerVersion		Compiler version, e, g. MSC 1310.
	/// @return												Visual Studio version number or returns an UnknownError, if the version is unknown.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<Int32> GetVsVersion(Int32 compilerVersion);

	//----------------------------------------------------------------------------------------
	/// Returns the path to a runtime redistributable library by giving a Visual Studio version number and a flag if you need the release- or debug version.
	/// This function does not look for known paths, or browses the disk. The path is only determined by browsing through all libraries which are already attached
	/// to the current process. If the version number and the flag matches, the absolute path is returned.
	/// E.g. version=2015, and release=True returns C:\Windows\System32\ucrtbase.dll on a 64-bit system.
	/// E.g. version=2008, and release=True returns C:\Windows\System32\msvcr90.dll on a 64-bit system.
	/// E.g. version=2010, and release=True returns C:\Windows\System32\msvcr100.dll on a 64-bit system.
	/// @return												Absolute path to the given library, or an error is returned.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<Url> GetVsRuntimeLibrary(Int32 version, Bool release);
#endif

	//----------------------------------------------------------------------------------------
	/// Returns the content of a given file in a string. The file is expected to be encoded in UTF-8.
	/// @param[in] filepath						Path of the file.
	/// @return												Content of the file in a string, or returns an error if reading failed.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<String> GetFileContent(const Url& filepath);

	//----------------------------------------------------------------------------------------
	/// Writes the content of a string to a given file. The content will be encoded in UTF-8.
	/// @param[in] filepath						Path of the file.
	/// @param[in] str								Content to write.
	/// @param[in] append							True to append the content to the file, or False to overwrite the entire content with the new string.
	/// @return												Returns OK if the operation succeeded.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<void> SetFileContent(const Url& filepath, const String& str, Bool append);
};

class VirtualMachineScopeRef;
class VirtualMachineRef;
class LibraryRef;

//----------------------------------------------------------------------------------------
/// Struct which contains information about a doc string
/// interfaces in this framework
//----------------------------------------------------------------------------------------
struct DocStringMeta
{
	MAXON_DISALLOW_COPY_AND_ASSIGN(DocStringMeta);
	
	DocStringMeta() = default;

	// Contains the entire original docstring block.
	String _entireString;

	// Only the docstring.
	String _docString;

	// Contains additional type-, name-, description information in the doc string.
	BaseArray<Tuple<String, String, String>> _parameter;

	// Contains additional type-, description- information in the doc string
	Tuple<String, String> _return;
};

class VmDebuggerConnectionRef;
class VmDebuggerConnectionInterface : MAXON_INTERFACE_BASES(ObjectInterface)
{
	MAXON_INTERFACE(VmDebuggerConnectionInterface, MAXON_REFERENCE_NORMAL, "net.maxon.python.interface.vmdebuggerconnection");
public:

	//----------------------------------------------------------------------------------------
	/// Returns the name of the debugger connection.
	/// @return												Name, e.g. PyDev
	//----------------------------------------------------------------------------------------
	MAXON_METHOD String GetName() const;

	//----------------------------------------------------------------------------------------
	/// Returns the path of the debugger. 
	/// @return												Path to the debugger, allowed to be empty.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Url GetPath() const;

#ifdef MAXON_COMPILER_GCC
	_Pragma("GCC diagnostic push")
	_Pragma("GCC system_header")
#endif

	//----------------------------------------------------------------------------------------
	/// The debugger shutdown code which gets executed in the target language, before the original script gets executed.
	/// If the code fails executing, the error is printed to sys.stderr and the actual script will be executed regardless.
	/// E.g. For Python:
	/// @code
	/// MAXON_METHOD String GetStartupScript() const
	/// {
	/// 	return String("try:\n"
	/// 	             	"    import mydebugger\n"
	/// 		            "    ptvsd.enable_attach(None)\n"
	/// 		            "except:\n"
	/// 		            "    mydebugger = None\n"  // before reraising the error, set ptvsd to None,
	///                                            // so a check can be performed in the shutdown script
	/// 		            "    raise\n"); // reraise only in case the current error should be printed to sys.stderr
	/// }
	/// @endcode
	/// @return			Startup script, including \\n and 4-spaces. Can return an empty string.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD String GetStartupScript() const;

	//----------------------------------------------------------------------------------------
	/// The debugger shutdown code which gets executed in the target language, which gets executed after the actual script got executed.
	/// If the code fails executing, the error is printed to sys.stderr.
	/// E.g. For Python:
	/// @code
	/// MAXON_METHOD String GetShutdownScript() const
	/// {
	/// 	return String("if mydebugger:\n"
	/// 		            "    mydebugger.shutdown()\n")
	/// }
	/// @endcode
	/// @return			Shutdown script, including \\n and 4-spaces. Can return an empty string.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD String GetShutdownScript() const;

#ifdef MAXON_COMPILER_GCC
	_Pragma("GCC diagnostic pop")
#endif

};

class VirtualMachineScopeInterface : MAXON_INTERFACE_BASES(ObjectInterface)
{
	MAXON_INTERFACE(VirtualMachineScopeInterface, MAXON_REFERENCE_NORMAL, "net.maxon.python.interface.virtualmachinescope");
public:

	//----------------------------------------------------------------------------------------
	/// Initialized the virtual machine scope. Needs to be executed before any other function of the interface is used.
	/// @param[in] identifier					Human readable unique identifier. Depending on the engine, some exception handlers might print this into their exception to
	/// 															make it easier to understand where the exception comes from.
	/// @param[in] code								Code to be executed.
	/// @param[in] errorHandling			Adjust how the virtual machine should treat an exception.
	/// @param[in] debug							Optional virtual machine debugger connection, to debug the code.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> Init(const String& identifier, const String& code, ERRORHANDLING errorHandling, const VmDebuggerConnectionRef* debug = nullptr);

	//----------------------------------------------------------------------------------------
	/// Add an object to the scope. The Data object will be converted through the underlying library implementation. So the Data object must be representable in the target virtual machine.
	/// @param[in] name								Variable name of the object in the scope.
	/// @param[in] data								Object that will be added to the scope.
	/// @return												Return state, depending on VirtualMachineScopeInterface::Init(errorHandling).
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> Add(const String& name, const Data& data);

	//----------------------------------------------------------------------------------------
	/// Returns an object from the scope.
	/// @param[in] name								Variable name of the object in the scope.
	/// @return												Requested object or error.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<Data> Get(const String& name);

	//----------------------------------------------------------------------------------------
	/// Execute the virtual machine scope. Before, and after executing the code, the optionally given debugger code from the VmDebuggerConnection will be executed.
	/// @return												Return state, depending on VirtualMachineScopeInterface::Init(errorHandling).
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> Execute();

	//----------------------------------------------------------------------------------------
	/// Executes a callable object from the scope. Must only be called after VirtualMachineScopeInterface.Execute.
	/// @param[in] name								Name of the callable object, e.g a function name
	/// @param[in] helperStack				A temporary helper stack for the return value.
	/// @param[in] expected						(Optional) Datatype of the returned object, otherwise the type of the object will be chosen automatically.
	/// @param[in] arguments					(Optional) Arguments which will be passed to the callable object.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<Data*> PrivateInvoke(const String& name, BlockArray<Data>& helperStack, const DataType& expected = DataType::NullValue(), const Block<Data*>* arguments = nullptr);

	//----------------------------------------------------------------------------------------
	/// Normally to reset the error state of the internal virtual machine. E.g. In Python PyErr_Print is executed.
	/// Normally used after VirtualMachineScopeInterface.Execute or VirtualMachineScopeInterface.PrivateInvoke failed, but only if scope is initialized with ERRORHANDLING.REDIRECT.
	/// @return												OK if the error was handled, otherwise an exception is returned.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> ErrorHandling();

	//----------------------------------------------------------------------------------------
	/// Private.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> _PrivateInit(const LibraryRef& lib);
};

class VirtualMachineInterface : MAXON_INTERFACE_BASES(ObjectInterface)
{
	MAXON_INTERFACE(VirtualMachineInterface, MAXON_REFERENCE_NORMAL, "net.maxon.python.interface.virtualmachine");
public:
	//----------------------------------------------------------------------------------------
	// Initializes the virtual machine. This is normally not necessary and only used if you implemented your own virtual machine.
	// To get access to e.g. a default Python 2.7 use the macro MAXON_CPYTHONVM() which returns a fully working Python environment
	// and doesn't need to be initialized (nor should be freed, since the system owns it!).
	//----------------------------------------------------------------------------------------
	/// @param[in] runtimeInfo				Information about the virtual machine, how to start it up.
	/// @param[in] settings						Optional settings which might be needed by the virtual machine.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> Init(const LoadRuntime& runtimeInfo, const DataDictionary& settings = DataDictionary::NullValue());

	//----------------------------------------------------------------------------------------
	/// Frees and shuts down the virtual machine. Should never be called on virtual machines which are owned by the system.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD void Free();

	//----------------------------------------------------------------------------------------
	/// Creates a virtual machine scope. The scope must be deleted before the virtual machine will be shutdown.
	/// @return												New virtual machine scope.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<VirtualMachineScopeRef> CreateScope();

	//----------------------------------------------------------------------------------------
	/// Returns the name of the underlying library, e.g. "Python".
	/// @return												Name of the virtual machine.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD String GetName();

	//----------------------------------------------------------------------------------------
	/// Returns the human readable version string of the underlying library.
	/// @return												Version details.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD String GetVersion();

	//----------------------------------------------------------------------------------------
	/// Returns the human readable copyright information of the underlying library.
	/// @return												Copyright text.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD String GetCopyright();

	//----------------------------------------------------------------------------------------
	/// Returns a human readable compiler info text.
	/// @return												Compiler which got used to compile the underlying library.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD String GetCompiler();

	//----------------------------------------------------------------------------------------
	/// Returns a human readable build information.
	/// @return												Build info with information about the build.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD String GetBuildInfo();

	//----------------------------------------------------------------------------------------
	/// Enters the interactive mode of the virtual machine.
	/// @return												OK after the interactive mode was left, or FunctionNotImplementedError
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> EnterInteractiveMode();

	//----------------------------------------------------------------------------------------
	/// Executes a given code in the global scope of the virtual machine.
	/// @param[in] code								Code to execute.
	/// @return												Returns an error if an error occurred. Virtual machine clears all error states when function returns.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> Execute(const String& code);

	//----------------------------------------------------------------------------------------
	/// Executes a given file in the global scope of the virtual machine.
	/// @param[in] filepath						Path of file to execute.
	/// @return												Returns an error if an error occurred. Virtual machine clears all error states when function returns.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> Execute(const Url& filepath);

	//----------------------------------------------------------------------------------------
	/// Executes a given module in the virtual machine.
	/// @param[in] name								Name of the module.
	/// @return												Returns an error if an error occurred. Virtual machine clears all error states when function returns.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> ExecuteModule(const String& name);

	//----------------------------------------------------------------------------------------
	/// Returns docstrings of a given code.
	/// @param[in] code								String code.
	/// @param[out] meta							Returns the docstrings.
	/// @return												Returns OK if the extraction succeeded, otherwise None.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> GetDocumentString(const String& code, DocStringMeta& meta);

	//----------------------------------------------------------------------------------------
	/// Returns the underlying library.
	/// @return												Underlying virtual machine library.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD LibraryRef GetLibraryRef();

	//----------------------------------------------------------------------------------------
	/// Returns all available virtual machine libraries.
	/// @return												An array of available virtual machines libraries.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<BaseArray<Runtime>> GetAllAvailableVirtualMachineLibraries() const;

	// A few helper functions
};

#include "vm1.hxx"

// Virtual Machine Classes
MAXON_REGISTRY(Class<VirtualMachineRef>, VirtualMachines, "net.maxon.python.registry.virtualmachines");
namespace VirtualMachines
{
	MAXON_DECLARATION(Class<VirtualMachineRef>, CPython, "net.maxon.python.virtualmachine.cpython");
	MAXON_DECLARATION(Class<VirtualMachineRef>, PyPy, "net.maxon.python.virtualmachine.pypy");
}

// Pre configured Python debugger handlers
MAXON_REGISTRY(VmDebuggerConnectionRef, VmDebuggerConnections, "net.maxon.python.registry.vmdebuggerconnections");
namespace VmDebuggerConnections
{
	MAXON_DECLARATION(VmDebuggerConnectionRef, Ptvs, "net.maxon.python.vmdebuggerconnection.ptvs");
	MAXON_DECLARATION(VmDebuggerConnectionRef, Pydev, "net.maxon.python.vmdebuggerconnection.pydev");
}

MAXON_DECLARATION(Class<VirtualMachineScopeRef>, CPythonScope, "net.maxon.python.virtualmachine.scope");

// Pre configured Python virtual machines
MAXON_REGISTRY(VirtualMachineRef, PythonVms, "net.maxon.python.virtualmachines");
namespace PythonVms
{
// In R20 same as MAXON_CPYTHON27VM()
#define MAXON_CPYTHONVM() maxon::PythonVms::Get(maxon::Id("net.maxon.python.virtualmachine.c4dpy27"))

#define MAXON_CPYTHON27VM() maxon::PythonVms::Get(maxon::Id("net.maxon.python.virtualmachine.c4dpy27"))
}

#include "vm2.hxx"

} // namespace maxon

#endif // VM_H__
