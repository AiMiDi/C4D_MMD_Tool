#ifndef CPYTHON_H__
#define CPYTHON_H__

#include "maxon/apibase.h"
#include "maxon/interface.h"
#include "maxon/datadictionary.h"
#include "maxon/registrybase.h"
#include "maxon/delegate.h"
#include "maxon/dll.h"
#include "maxon/objectbase.h"
#include "maxon/stringencoding.h"
#include "maxon/weakref.h"
#include "maxon/logger.h"

#include "maxon/vm.h"
#include "maxon/cpython_raw.h"
#include "maxon/cpython_ref.h"

MAXON_DEPENDENCY_WEAK("maxon/vm.h");
MAXON_DEPENDENCY_WEAK("maxon/cpython_raw.h");
MAXON_DEPENDENCY_WEAK("maxon/cpython_ref.h");

namespace maxon
{

extern const Id ID_LOGGER_PYTHON;

//-------------------------------------------------
// Ownership information
// 
// @return          
//-------------------------------------------------
enum class OWNERSHIP
{
	NORMAL = 1,			/// Default ownership
	CALLER = 2,			/// Caller owns the object
	CALLEE = 3,			/// Callee owns the object
	CALLER_BUT_COPY = 4,/// Callee owns the object but needs a copy
} MAXON_ENUM_LIST(OWNERSHIP);

//-------------------------------------------------
// Private. Internal error storage helper for module registration
//-------------------------------------------------
struct ErrorStorage
{
	Error _err;
};

using FunctionRegistration = Delegate<Result<void>(py::NativePyCFunctionWithKeywords func)>;

//-------------------------------------------------
// Private. operator for module registration
// 
// @param reg        Meta function object.
// @param func       Python wrapper function to register
// @return           Error object.
//-------------------------------------------------
MAXON_ATTRIBUTE_FORCE_INLINE ErrorStorage operator /(const FunctionRegistration& reg, py::NativePyCFunctionWithKeywords func)
{
	MAXON_WARN_MUTE_UNUSED reg(func);
	return {};
}

namespace py
{

enum class PATHHANDLE
{
	OVERWRITE,					/// Overwrite sys.path
	APPEND_AT_END,			/// Append array to sys.path
	INSERT_AT_BEGINNING	/// Insert array at sys.path[0]
} MAXON_ENUM_LIST(PATHHANDLE);

enum class GILSTATE
{
	NOT_ACTIVE = 0,											/// GIL is not hold by any thread.
	ACTIVE_BUT_NOT_CURRENT_THREAD = 1,	/// GIL is hold by another thread.
	ACTIVE_AND_CURRENT_THREAD = 2				/// GIL is hold by the current thread
} MAXON_ENUM_LIST(GILSTATE);


//-------------------------------------------------
// Private. Helper structure to register a Python module.
//-------------------------------------------------
struct ModuleDefinition
{
	ModuleDefinition() = default;
	ModuleDefinition(const Char* name, py::NativePyMethodDef* methods, const Char* doc) : m_name(name), m_doc(doc), m_methods(methods) { }

	const Char* m_name = nullptr;								/// Name of the module.
	const Char* m_doc = "";											/// Optional docstring.
	Int64 m_size = -1;													/// Private
	py::NativePyMethodDef* m_methods = nullptr; /// Array of methods
};

//-------------------------------------------------
// Python pylib object with information about the shared library of Python.
//-------------------------------------------------
struct PythonDll
{
	DllRef _dll;									/// The dll to the loaded Python library
	Url _path;										/// Path of the library

	Int32 _major = 0;							/// Major version of Python, e.g. 2
	Int32 _minor = 0;							/// Minor version of Python, e.g. 7
	Int32 _micro = 0;							/// Micro version of Python, e.g. 14
	Bool _isRelease = false;			/// True if the library is a release, otherwise false.

#ifdef MAXON_TARGET_WINDOWS
	Int32 _compiledWithMsvc = 0;	/// MSVC version Python got compiled with.
	DllRef _runtimeLibrary;				/// Library object to the VS runtime.
#endif

	Int32 _apiVersion = 0;				/// Internal Python API version.

	Bool _staticallyLinked = false;	/// True if Python got loaded implicitly, otherwise false.
	StringDecodingRef _defaultStringDecoder;	/// Default decoder of Python
	StringEncodingRef _defaultStringEncoder;	/// Default encoder of Python
};

// function declarations
template <typename T = Generic>
using DelegatePyObject_FromData = Delegate<CPyRef(const T*, const CPyTypeRef& expected)>;
using CPyCapsule_Destructor = void(NativePyObject*);
using DelegatePyObject_AsData = Delegate<Result<Bool>(const DataType& expected, const CPyRef& src, Data* dst)>;

enum class SPECIALPATH
{
	MAXON_MODULES,												/// Path to the 'maxon' module.
	PREFS_PYTHON_GENERATED_DIRECTORY,			/// Path to the 'generated' directory.
	PREFS_PYTHON_GLOBAL_LIBS,							/// Path to the globals 'libs directory which all Cinema 4D instances share.
	PREFS_PYTHON_LOCAL_LIBS								/// Path to the local 'libs directory which only the current Cinema 4D instance uses.
} MAXON_ENUM_LIST(SPECIALPATH);

enum class PYGILSTATE
{
	LOCKED,				/// GIL is locked.
	UNLOCKED			/// GIL is unlocked.
} MAXON_ENUM_LIST(PYGILSTATE);

enum class PYINPUT
{
	SINGLE = 256,				/// The start symbol from the Python grammar for a single statement
	FILE = 257,					/// The start symbol from the Python grammar for sequences of statements as read from a file or other source
	EVAL = 258					/// The start symbol from the Python grammar for isolated expressions
} MAXON_ENUM_LIST(PYINPUT);

enum class PYSTARTOPERATION
{
	NONE,
	EXECUTE_CODE, 	/// maxon::String
	EXECUTE_MODULE, /// maxon::String
	EXECUTE_FILE, 	/// maxon:Url
	VERSION					/// Version mode
} MAXON_ENUM_LIST(PYSTARTOPERATION);

//----------------------------------------------------------------------------------------
/// A PythonError indicates that the last Python call failed. If the error has a cause,
/// it is an AggregatedError, which is a collection of PythonTracebackErrors.
/// If a function returns this error, the exception indicator in Python and remains until
/// it is manually cleared or if a function explicitly describes the meaning of this error differently.
//----------------------------------------------------------------------------------------
class PythonErrorInterface : MAXON_INTERFACE_BASES(ErrorInterface)
{
	MAXON_INTERFACE(PythonErrorInterface, MAXON_REFERENCE_COPY_ON_WRITE, "net.maxon.python.interface.pythonerror");
};

//----------------------------------------------------------------------------------------
/// A PythonTracebackError is always part of an AgrregatedError which is further the cause in a PythonError. This error is never a top-level error.
/// Contains information about the traceback if an exception.
//----------------------------------------------------------------------------------------
class PythonTracebackErrorInterface : MAXON_INTERFACE_BASES(ErrorInterface)
{
	MAXON_INTERFACE(PythonTracebackErrorInterface, MAXON_REFERENCE_COPY_ON_WRITE, "net.maxon.python.interface.pythontracebackerror");
public:
	//----------------------------------------------------------------------------------------
	/// Sets the url of the traceback entry.
	/// @param[in] url								Path.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD void SetUrl(const Url& url);
	
	//----------------------------------------------------------------------------------------
	/// Returns the path of the traceback entry.
	/// @return												Path.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD const Url& GetUrl() const;

	//----------------------------------------------------------------------------------------
	/// Sets the line of the traceback entry.
	/// @param[in] line								Line number.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD void SetLineNumber(Int line);
	
	//----------------------------------------------------------------------------------------
	/// Returns line of the traceback entry.
	/// @return												Line number..
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Int GetLineNumber() const;
};

//-------------------------------------------------
/// A PythonSystemExitError is thrown if the previous function executed sys.exit. Only thrown in VirtualMachineInterface::Execute(String)
//-------------------------------------------------
class PythonSystemExitErrorInterface : MAXON_INTERFACE_BASES(ErrorInterface)
{
	MAXON_INTERFACE(PythonSystemExitErrorInterface, MAXON_REFERENCE_COPY_ON_WRITE, "net.maxon.python.interface.pythonsystemerror");
};

//-------------------------------------------------
// Private. Helper struct to register a Python proxy object for virtual interfaces.
//-------------------------------------------------
struct ProxyDefinition
{
	ProxyDefinition(const BaseArray<Id>& interfaceIds, const BaseArray<Id>& baseClassIds) : _interfaceIds(interfaceIds), _baseClassIds(baseClassIds) { }

	const BaseArray<Id>& _interfaceIds;	/// Array of interface IDs.
	const BaseArray<Id>& _baseClassIds; /// Array of baseclass IDs.
};

class CPythonLibraryRef;
class CPythonLibraryInterface : MAXON_INTERFACE_BASES(LibraryInterface)
{
	MAXON_INTERFACE(CPythonLibraryInterface, MAXON_REFERENCE_NORMAL, "net.maxon.python.interface.python.cpythonlibrary");

public:
	static MAXON_METHOD Result<PYSTARTOPERATION> ParseCommandLine(BaseArray<String>* args = nullptr, Data* res = nullptr, PYTHONFLAG* flags = nullptr);

	//----------------------------------------------------------------------------------------
	/// Initializes a new library object. Must not be called on the pre-allocated Python instances!
	/// 
	/// @param[in] librarypath				Path to the Python library.
	/// @param[in] createSubLibrary		True to create a sub-interpreter.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> Init(const Url& librarypath, Bool createSubLibrary);

	//----------------------------------------------------------------------------------------
	/// Initializes all types after proper initialization. Must not be called on the pre-allocated Python instances!
	/// 
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> InitTypes();

	//----------------------------------------------------------------------------------------
	/// Initializes all builtin modules after initialization. Must not be called on the pre-allocated Python instances!
	/// 
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> InitBuiltinModules();

	//-------------------------------------------------
	/// Initializes Python. Must not be called on the pre-allocated Python instances!
	//-------------------------------------------------
	MAXON_METHOD void CPy_Initialize();

	//-------------------------------------------------
	/// Finalizes Python. Must not be called on the pre-allocated Python instances!
	//-------------------------------------------------
	MAXON_METHOD void CPy_Finalize();

	//-------------------------------------------------
	/// Initializes Python random module. Must not be called on the pre-allocated Python instances!
	//-------------------------------------------------
	MAXON_METHOD void PrivateCPyRandom_Init();

	//----------------------------------------------------------------------------------------
	/// Initialize a Python module by the information passed in the module definition. GIL must be held.
	/// 
	/// @param[in] module							Information about the builtin module.
	/// @return												Reference 
	//----------------------------------------------------------------------------------------
	MAXON_METHOD CPyRef CPy_InitModule(const ModuleDefinition& module);

	//-------------------------------------------------
	/// Free all resources and internals of Python.  Must not be called on the pre-allocated Python instances!
	//
	//----------------------------------------------------------------------------------------
	/// @param[in] shutdownEngine			Delegate which must execute Py_Finalize. GIL got released.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD void Free(const Delegate<void()>& shutdownEngine);

	//----------------------------------------------------------------------------------------
	/// Meta information of Python library.
	/// 
	/// @return												Meta information object.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD const PythonDll& GetDll() const;

	//----------------------------------------------------------------------------------------
	/// Should be used whenever the native Python API requires a FILE pointer.
	/// Whenever a Python library function takes a FILE pointer it must be guaranteed that a valid FILE object is passed.
	/// When Python is for instance compiled with VS2012 and the host application is compiled with VS2013 the FILE object must not be mixed
	/// between runtimes (msvcr110.dll != msvcr120.dll). The FILE object must always be from the same runtime.
	/// PythonLibrary::FopenNative() and PythonLibrary::fclose() garantuee that always the correct FILE structure is created.
	/// 
	/// @param[in] name								Name object of fopen(name, ...)
	/// @param[in] mode								File mode, like fopen(..., "rb");
	/// @return												File object or nullptr on failure.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD FILE_native* FopenNative(const Char* name, const Char* mode);

	//----------------------------------------------------------------------------------------
	/// Returns a Python error with an AggregatedError which is aggreated with PythonTracebackErrors.
	/// 
	/// @param[in] restoreError				True to keep the exception indicator untouched, or False to keep the exception indicator.
	/// @return												PythonError.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Error LastPythonCallFailed(MAXON_SOURCE_LOCATION_DECLARATION, Bool withTraceback, Bool restoreError);

	//----------------------------------------------------------------------------------------
	/// Register a proxy component for virtual-, and non-virtual interfaces and adds the object to the Classes registry.
	/// Used internally by the Python counterpart of MAXON_COMPONENT_OBJECT_REGISTER and MAXON_COMPONENT_CLASS_REGISTER to register a Python type.
	/// GIL must be held.
	/// 
	/// @param[in] type								Python type which represents the implementation.
	/// @param[in] registryId					Optional ID to which registry the object should be published to, can be empty.
	/// @param[in] baseAndInterfaceIds	Definition object with information about the baseclasses and interfaces the type implements.
	/// @param[in] cid								ID of the object, e.g. "net.maxon.iohandler.gzip"
	/// @param[in] printErrors				True if the error of a failed Python function should be printed to the console, otherwise false.
	/// 															If false, all exceptions within the overwritten functions must be handled for exceptions properly.
	/// @param[in] kind								KIND type of the class.
	/// @param[in] loc								Location information where the object got registered from.
	/// @param[in] createObject				True to create and publish a new instance in the registry instead of the class.
	/// 															True for MAXON_COMPONENT_OBJECT_REGISTER, and false for MAXON_COMPONENT_CLASS_REGISTER.
	/// @param[in] dtOfObject					Necessary information of which type the ObjectRef instance is.
	/// @return												MPyDataRef of the new class object.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<MPyDataRef> RegisterComponentProxy(const CPyRef& type, const Id& registryId, const ProxyDefinition& baseAndInterfaceIds, const Id& cid, Bool printErrors, ClassInterface::KIND kind, const SourceLocation& loc, Bool createObject, const DataType& dtOfObject);

	//----------------------------------------------------------------------------------------
	/// Returns true when Python has been initialized, otherwise False.
	/// 
	/// @return												True or False.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Bool CPy_IsInitialized();

	//----------------------------------------------------------------------------------------
	/// Return the version of this Python interpreter. The value is available to Python code as sys.version.
	/// 
	/// @return												Version string.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD const Char* CPy_GetVersion();

	//----------------------------------------------------------------------------------------
	/// Return the platform identifier for the current platform. The value is available to Python code as sys.platform.
	/// 
	/// @return												Platform string.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD const Char* CPy_GetPlatform();

	//----------------------------------------------------------------------------------------
	/// Return the official copyright string The value is available to Python code as sys.copyright.
	/// 
	/// @return												Copright string.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD const Char* CPy_GetCopyright();

	//----------------------------------------------------------------------------------------
	/// Return an indication of the compiler used to build the current Python version.
	/// The value is available to Python code as part of the variable sys.version.
	/// 
	/// @return												Copright string.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD const Char* CPy_GetCompiler();

	//----------------------------------------------------------------------------------------
	/// Return information about the sequence number and build date and time of the current
	/// Python interpreter instance. The value is available to Python code as part of the variable sys.version.
	/// 
	/// @return												Build info.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD const Char* CPy_GetBuildInfo();

	//----------------------------------------------------------------------------------------
	/// This function should be called before Py_Initialize() is called for the first time.
	/// @param[in] name								Name for the current program.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> CPy_SetProgramName(const String& name);
	
	//----------------------------------------------------------------------------------------
	/// Set the default "home" directory, that is, the location of the standard Python libraries.
	/// @param[in] name								Name for the current program.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> CPy_SetPythonHome(const Url& name);
	
	//----------------------------------------------------------------------------------------
	/// Return the program name set with Py_SetProgramName(), or the default.
	/// @return												Program name.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD String CPy_GetProgramName();
	
	//----------------------------------------------------------------------------------------
	/// Return the default "home", that is, the value set by a previous call to Py_SetPythonHome().
	/// @return												Python home.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD String CPy_GetPythonHome();

	//----------------------------------------------------------------------------------------
	/// Executes a Python module by its name. GIL must be held.
	/// 
	/// @param[in] name								Name of the module.
	/// @return												True on success, otherwise false. Exception indicator is cleared before function returns.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Bool ExecuteModule(const String& name);

	//----------------------------------------------------------------------------------------
	/// Private. Create caller context object which contains a pointer to this object. The context gets passed to all
	/// C-functions as the first self parameter. This is used in PrivateExtractCPythonLibrary{XX} to achieve the convenient
	/// wrapping method for C++ functions. GIL must be held.
	/// 
	/// @return												New caller context.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD MPyCallerContextRef CPyCallerContext_New();

	//----------------------------------------------------------------------------------------
	/// Executes the Python source code from a file. If '__main__' does not already exist, it is created. If the function fails,
	/// Checks for CPyErr_Occured and clear the exception indicator of Python accordingly. GIL must be held.
	/// 
	/// @param[in] fp									File pointer where to read the source from.
	/// @param[in] filename						Path of the file.
	/// @param[in] closeit						True if Python should close the pointer using fclose, otherwise false.
	/// @param[in] flags							Optional compiler flags. Can be nullptr.
	/// @return												True on success.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Bool CPyRun_SimpleFileExFlags(FILE_native* fp, const Char* filename, Int32 closeit, CPyCompilerFlags* flags);
	
	//----------------------------------------------------------------------------------------
	/// Executes the Python source code from a file. If '__main__' does not already exist, it is created. If the function fails,
	/// Checks for CPyErr_Occured and clear the exception indicator of Python accordingly. GIL must be held.
	/// 
	/// @param[in] url								Url where the source is read from.
	/// @param[in] flags							Optional compiler flags. Can be nullptr.
	/// @return												True on success.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Bool CPyRun_SimpleFileExFlags(const Url& url, CPyCompilerFlags* flags);

	//----------------------------------------------------------------------------------------
	/// Executes the Python source code from a source string. If the function fails,
	/// Checks for CPyErr_Occured and clear the exception indicator of Python accordingly. GIL must be held.
	/// 
	/// @param[in] code								Python source code.
	/// @param[in] flags							Optional compiler flags. Can be nullptr.
	/// @return												True on success.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD CPyRef CPyRun_SimpleStringFlags(const String& code, CPyCompilerFlags* flags);

	//-------------------------------------------------
	/// Execute Python source code from fp in the context specified by the objects globals and locals with the compiler flags specified by flags.
	/// locals must be a dictionary; locals can be any object that implements the mapping protocol. The parameter start specifies the start token that should be used to parse the source code.If the function fails,
	//----------------------------------------------------------------------------------------
	/// Checks for CPyErr_Occured and clear the exception indicator of Python accordingly. GIL must be held.
	///
	/// @param[in] fp									File pointer where to read the source from.
	/// @param[in] filename						Path of the file.
	/// @param[in] start							Key start like PY_FILE_INPUT
	/// @param[in] globals						Dict object.
	/// @param[in] locals							Any object that implements the mapping protocol.
	/// @param[in] closeit						True if Python should close the pointer using fclose, otherwise false.
	/// @param[in] flags							Optional compiler flags. Can be nullptr.
	/// @return												True on success.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD NativePyObject* CPyRun_FileExFlags(FILE_native* fp, const Char* filename, Int32 start, NativePyObject* globals, NativePyObject* locals, Int32 closeit, CPyCompilerFlags* flags);

	//----------------------------------------------------------------------------------------
	/// Enters the interactive loop of the Python interpreter. If an exception occurrs, it stays in the loop. Only a sys.exit() will
	/// exit the function with OK. Raises exceptions only for internal errors. GIL must be held.
	/// 
	/// @param[in] fp									File stream of the input stream, normally stdin.
	/// @param[in] filename						Name of the interactive loop.
	/// @param[in] flags							Optional compiler flags. Can be nullptr.
	/// @return												OK on success, and sys.exit().
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> CPyRun_InteractiveLoopFlags(FILE* fp, const Char* filename, CPyCompilerFlags* flags);

	//----------------------------------------------------------------------------------------
	/// Ensure that the current thread is ready to call the Python C API regardless of the current state of Python, or of the global interpreter lock.
	/// See https://docs.python.org/2/c-api/init.html#c.PyGILState_Ensure for more information.
	/// @return												GIL state.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD PYGILSTATE CPyGilState_Ensure();

	//----------------------------------------------------------------------------------------
	/// Release any resources previously acquired. After this call, Python's state will be the same as it was prior to the corresponding CPyGILState_Ensure() call. GIL must be held.
	/// See https://docs.python.org/2/c-api/init.html#c.PyGILState_Release for more information.
	/// 
	/// @param[in] state							GIL state.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD void CPyGilState_Release(PYGILSTATE state);

	//----------------------------------------------------------------------------------------
	/// Returns the current GIL state.
	/// 
	/// @return												Current GIL state.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD GILSTATE GetGilState() const;

	//----------------------------------------------------------------------------------------
	/// Returns the current thread state object.
	/// 
	/// @return												Thread state object or nullptr if no thread state object is available.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD NativePyThreadState* CPyGILState_GetThisThreadState();

	//-------------------------------------------------
	/// Swap the current thread state with the passed one. 
	///
	/// @param state    Thread State to swap with.
	/// @return         Old thread state.
	//-------------------------------------------------
	MAXON_METHOD NativePyThreadState* CPyThreadState_Swap(NativePyThreadState* state);
	
	//-------------------------------------------------
	/// Get the dictionary of the current thread state.
	///
	/// @return         Dict of the current thread state.
	//-------------------------------------------------
	MAXON_METHOD CPyRef CPyThreadState_GetDict();

	//----------------------------------------------------------------------------------------
	/// Parse and compile a given Python source code returning the resulting code object. GIL must be held.
	/// 
	/// @param[in] code								Python source code.
	/// @param[in] filename						Filename of the code object and might appear in the traceback or SyntaxError exception messages.
	/// @param[in] start							Start token.
	/// @param[in] flags							Optional compiler flags. Can be nullptr.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD CPyCodeRef CPy_CompileStringFlags(const Char* code, const Char* filename, PYINPUT start, CPyCompilerFlags* flags = nullptr);

	//----------------------------------------------------------------------------------------
	/// Increments the reference count for object o. The object must not be nullptr. GIL must be held.
	/// See https://docs.python.org/2/c-api/refcounting.html#c.Py_INCREF for more information.
	/// 
	/// @param[in] o									Object to increment its reference count from.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD void CPy_Incref(NativePyObject* o) const;

	//----------------------------------------------------------------------------------------
	/// Decrements the reference count for object o. The object must not be nullptr. GIL must be held.
	/// See https://docs.python.org/2/c-api/refcounting.html#c.Py_DECREF for more information.
	/// 
	/// @param[in] o									Object to decrement its reference count from.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD void CPy_Decref(NativePyObject* o) const;

	//----------------------------------------------------------------------------------------
	/// Increments the reference count for object o. If the object is nullptr, the call has no effect. GIL must be held.
	/// See https://docs.python.org/2/c-api/refcounting.html#c.Py_XINCREF for more information.
	/// 
	/// @param[in] o									Object to decrement its reference count from.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD void CPy_SafeIncref(NativePyObject* o) const;

	//----------------------------------------------------------------------------------------
	/// Decrements the reference count for object o. If the object is nullptr, the call has no effect. GIL must be held.
	/// See https://docs.python.org/2/c-api/refcounting.html#c.Py_XDECREF for more information.
	/// 
	/// @param[in] o									Object to decrement its reference count from.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD void CPy_SafeDecref(NativePyObject* o) const;

	template<typename T>
	MAXON_FUNCTION void CPy_SafeClear(T*& o) const
	{
		CPy_SafeDecref(o);
		o = nullptr;
	}

	//----------------------------------------------------------------------------------------
	/// Runs the garbage collector of Python. GIL must be held.
	/// 
	/// @return												Number of items collected
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Int64 CPyGC_Collect();

	//----------------------------------------------------------------------------------------
	/// Returns the line number of a code object with a given instruction.
	/// 
	/// @param[in] codeObject					Code object.
	/// @param[in] x									Instruction in bytes.
	/// @return												Line number or -1 on failure.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Int32 CPyCode_Addr2Line(const CPyCodeRef& codeObject, Int32 x);

	//----------------------------------------------------------------------------------------
	/// Returns the internal DataType capsule of a maxon.DataType object. GIL must be held.
	/// 
	/// @param[in] obj								Object of type maxon.DataType.
	/// @return												DataType capsule. Can be safely casted to MPyDataType
	//----------------------------------------------------------------------------------------
	MAXON_METHOD CPyRef UnpackDataType(const CPyRef& obj);

	//----------------------------------------------------------------------------------------
	/// Returns the internal Data capsule of a maxon.Data object. GIL must be held.
	/// 
	/// @param[in] obj								Object of type maxon.Data.
	/// @return												Data capsule. Can be safely casted to MPyData
	//----------------------------------------------------------------------------------------
	MAXON_METHOD CPyRef UnpackData(const CPyRef& obj);

	//----------------------------------------------------------------------------------------
	/// Returns a None object. GIL must be held.
	/// 
	/// @return												None object.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD CPyConstRef CPy_None() const;

	//----------------------------------------------------------------------------------------
	/// Returns a False object. GIL must be held.
	/// 
	/// @return												False object.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD CPyConstRef CPy_True() const;

	//----------------------------------------------------------------------------------------
	/// Returns a True object. GIL must be held.
	/// 
	/// @return												True object.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD CPyConstRef CPy_False() const;

	//----------------------------------------------------------------------------------------
	/// Returns the not implemented value object. GIL must be held.
	/// 
	/// @return												NotImplemented (is not the same as NotImplementedError)
	//----------------------------------------------------------------------------------------
	MAXON_METHOD CPyConstRef CPy_NotImplemented() const;

	//-------------------------------------------------
	/// Print a standard traceback to sys.stderr and clear the error indicator. Call this function only when the error indicator is set (Otherwise it will cause a fatal error!).  GIL must be held.
	//-------------------------------------------------
	MAXON_METHOD void CPyErr_Print();

	//-------------------------------------------------
	/// Clears the error indicator of Python. If the error indicator is not set, the call has no effect. GIL must be held.
	//-------------------------------------------------
	MAXON_METHOD void CPyErr_Clear();

	//----------------------------------------------------------------------------------------
	/// Checks if the error indicator is set. GIL must be held.
	/// 
	/// @param[out] type							Private. Exception type.
	/// @return												True if the error indicator is set, otherwise false.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Bool CPyErr_Occurred(CPyRef* type = nullptr);

	//----------------------------------------------------------------------------------------
	/// Sets the error indicator. GIL must be held.
	/// 
	/// @param[in] errorType					Exception type object.
	/// @param[in] errorString				Human readbale exception message.
	/// @return												Always returns an empty CPyRef object.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD CPyRef CPyErr_SetString(const CPyRef& errorType, const Char* errorString = nullptr);
	
	//----------------------------------------------------------------------------------------
	/// Sets the error indicator with a filename and errno. GIL must be held.
	///
	/// @param[in] errorType					Exception type object.
	/// @param[in] errorNumber				Error indicator.
	/// @param[in] filename						Filename object.
	/// @return												Always returns an empty CPyRef object.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD CPyRef CPyErr_SetWithErrnoAndFilename(const CPyRef& errorType, Int32 errorNumber, const Char* filename);
	
	//----------------------------------------------------------------------------------------
	/// Sets the error indicator. GIL must be held.
	///
	/// @param[in] errorType					Exception type object.
	/// @param[in] errorNumber				Error indicator.
	/// @return												Always returns an empty CPyRef object.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD CPyRef CPyErr_SetWithErrno(const CPyRef& errorType, Int32 errorNumber);
	
	//----------------------------------------------------------------------------------------
	/// Sets the error indicator. GIL must be held.
	/// 
	/// @param[in] errorType					Exception type object.
	/// @param[in] errorString				Human readbale exception message.
	/// @return												Always returns an empty CPyRef object.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD CPyRef CPyErr_SetString(const CPyRef& errorType, const String& errorString);

	//----------------------------------------------------------------------------------------
	/// Sets the error indicator without a message. GIL must be held.
	///
	/// @param[in] errorType					Exception type object.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD void CPyErr_SetNone(const CPyRef& errorType);

	//----------------------------------------------------------------------------------------
	/// Retrieve the error indicator into three variables whose addresses are passed. If the error indicator is not set, all three objects are empty.
	/// 
	/// @param[out] type							Exception type.
	/// @param[out] value							Exception value.
	/// @param[out] traceback					Traceback object.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD void CPyErr_Fetch(CPyRef& type, CPyRef& value, CPyRef& traceback);

	//----------------------------------------------------------------------------------------
	/// Normalizes the objects, retrieved by CPyErr_Fetched.
	/// See https://docs.python.org/2/c-api/exceptions.html#c.PyErr_NormalizeException for more information.
	///
	/// @param[out] type							Exception type.
	/// @param[out] value							Exception value.
	/// @param[out] traceback					Traceback object.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD void CPyErr_NormalizeException(CPyRef& type, CPyRef& value, CPyRef& traceback);

	//----------------------------------------------------------------------------------------
	/// Restores the exception which got retrieved by CPyErr_Fetch.
	/// 
	/// @param[in] type								Exception type.
	/// @param[in] value							Exception value.
	/// @param[in] traceback					Traceback object.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD void CPyErr_Restore(const CPyRef& type, const CPyRef& value, const CPyRef& traceback);

	//----------------------------------------------------------------------------------------
	/// Checks if the current set exception is of a given exception.
	/// 
	/// @param[in] exc								A given object.
	/// @return												True when equal, otherwise false.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Bool CPyErr_ExceptionMatches(const CPyRef& exc);

	//----------------------------------------------------------------------------------------
	/// Checks if the given object is an exception. GIL must be held.
	/// 
	/// @param[in] o									A given object.
	/// @return												True if o is an exception.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Bool CPyExceptionClass_Check(const CPyRef& o);

	//----------------------------------------------------------------------------------------
	/// Create a capsule encapsulating a given pointer. The pointer argument may not be nullptr. GIL must be held.
	/// 
	/// @param[in] pointer						Pointer to encapsulate.
	/// @param[in] name								Name of the capsule.
	/// @param[in] destructor					Function pointer which gets called on destruction of the capsule.
	/// @return												capsule object.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD CPyRef CPyCapsule_New(void *pointer, const Char* name, CPyCapsule_Destructor* destructor) const;

	//----------------------------------------------------------------------------------------
	/// Set the pointer of the capsule. GIL must be held.
	/// 
	/// @param[in] capsule						Capsule object.
	/// @param[in] pointer						Set, or overwrite the pointer of the capsule.
	/// @return												True on success.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Bool CPyCapsule_SetPointer(const CPyRef& capsule, void* pointer);

	//----------------------------------------------------------------------------------------
	/// Retrieve the pointer stored in the capsule. On failure, returns nullptr. GIL must be held.
	/// 
	/// @param[in] capsule						Capsule to extract the pointer from.
	/// @param[in] name								Name of the capsule. On mismatch, the function returns nullptr.
	/// @return												Pointer from capsule.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD void* CPyCapsule_GetPointer(const CPyRef& capsule, const Char* name);

	//----------------------------------------------------------------------------------------
	/// Retrieve the context stored in the capsule, which was set by CPyCapsule_SetContext. On failure, returns nullptr. GIL must be held.
	/// 
	/// @param[in] capsule						Capsule to extract the context from.
	/// @return												Pointer to the capsule.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD void* CPyCapsule_GetContext(const CPyRef& capsule);

	//----------------------------------------------------------------------------------------
	/// Set a context pointer to a capsule. GIL must be held.
	/// 
	/// @param[in] capsule						Set, or overwrite the pointer of the capsule.
	/// @return												Context pointer.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Bool CPyCapsule_SetContext(const CPyRef& capsule, void* context);

	//----------------------------------------------------------------------------------------
	/// Checks if the given object is a capsule. GIL must be held.
	/// 
	/// @param[in] o									A given object.
	/// @return												True if o is a capsule.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Bool CPyCapsule_CheckExact(const CPyRef& o);

	//----------------------------------------------------------------------------------------
	/// Checks if the given object is a traceback. GIL must be held.
	/// 
	/// @param[in] o									A given object.
	/// @return												True if o is a traceback.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Bool CPyTraceBack_Check(const CPyRef& o);

	//----------------------------------------------------------------------------------------
	/// Checks if the given object is a class. GIL must be held.
	/// 
	/// @param[in] o									A given object.
	/// @return												True if o is a class.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Bool CPyClass_Check(const CPyRef& o);

	//----------------------------------------------------------------------------------------
	/// Creates a new immutable tuple. The tuple must be initialized right after it got created by using CPyTuple_SetItem. GIL must be held.
	/// 
	/// @param[in] size								Size of the new tuple.
	/// @return												New tuple or empty object if if exception indicator is set.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD CPyRef CPyTuple_New(UInt size) const;

	//----------------------------------------------------------------------------------------
	/// Returns the size of a tuple. GIL must be held. GIL must be held.
	/// 
	/// @return												Size of the tuple, or -1 if exception indicator is set.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD UInt CPyTuple_Size(const CPyRef& tuple);

	//----------------------------------------------------------------------------------------
	/// Retrieves an item of a tuple by its index. GIL must be held.
	/// 
	/// @param[in] tuple							Tuple object.
	/// @param[in] index							Index of the element. Raises an IndexError, if index is out of range.
	/// @return												Element of the item at the given index, or empty object if exception indicator is set.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD CPyRef CPyTuple_GetItem(const CPyRef& tuple, UInt index);
	
	//----------------------------------------------------------------------------------------
	/// Sets an item in a tuple at a given index. GIL must be held.
	/// 
	/// @param[in] tuple							Tuple object.
	/// @param[in] index							Index of the element. Raises an IndexError, if index is out of range.
	/// @param[in] item								Item to set.
	/// @return												True on success. Returns false if exception indicator is set.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Bool CPyTuple_SetItem(const CPyRef& tuple, UInt index, const CPyRef& item);
	
	//----------------------------------------------------------------------------------------
	/// Retrieves a slice object from a given slice range. GIL must be held.
	/// 
	/// @param[in] tuple							Tuple object.
	/// @param[in] from								Start index (including the object at this given index).
	/// @param[in] to									End index (excluding the object at this given index).
	/// @return												Slice objector empty object if exception indicator is set.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD CPyRef CPyTuple_GetSlice(const CPyRef& tuple, UInt from, UInt to);

	//----------------------------------------------------------------------------------------
	/// Checks if a given object is a tuple. GIL must be held.
	/// 
	/// @param[in] tuple							Tuple object.
	/// @return												True if o is a tuple.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Bool CPyTuple_CheckExact(const CPyRef& tuple);

	//----------------------------------------------------------------------------------------
	/// Checks if a given object has a specific attribute name. Equivalent to getattr(o, "name"). GIL must be held.
	/// 
	/// @param[in] o									Object to Checks the attribute for.
	/// @param[in] attrName						Name of the attribute.
	/// @return												True on match, otherwise False.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Bool CPyObject_HasAttrString(const CPyRef& o, const Char* attrName);

	//----------------------------------------------------------------------------------------
	/// Sets the value of the attribute named attrName, for object o, to the value item. GIL must be held.
	/// 
	/// @param[in] o									Object which will get the attribute.
	/// @param[in] name								Name of the attribute.
	/// @param[in] item								Value of the attribute.
	/// @return												True on success, otherwise False if the exception indicator is set.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Bool CPyObject_SetAttrString(const CPyRef& o, const Char* name, const CPyRef& item);

	//----------------------------------------------------------------------------------------
	/// Gets the attribute of an object by an attribute name. GIL must be held.
	/// 
	/// @param[in] o									Object to get the attribute from.
	/// @param[in] name								Name of the attribute.
	/// @return												Attribute on success or empty object if attribute could not be found and exception indicator is set.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD CPyRef CPyObject_GetAttrString(const CPyRef& o, const Char* name);

	//----------------------------------------------------------------------------------------
	/// Calls an object with optional argument list or a keyword dictionary. GIL must be held.
	/// 
	/// @param[in] callable_object		Object to call.
	/// @param[in] tupleArg						Argument list. Can be empty.
	/// @param[in] kw									Dictionary list. Can be empty.
	/// @return												Result or empty object if the call failed and the exception indicator got set.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD CPyRef CPyObject_Call(const CPyRef& callable_object, const CPyRef& tupleArg, const CPyRef& kw);

	//----------------------------------------------------------------------------------------
	/// Computes a string representation of an object. Equivalent to str(o). GIL must be held.
	/// 
	/// @param[in] o									Object to stringify.
	/// @return												Result or empty object if the call failed and the exception indicator got set.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD CPyRef CPyObject_Str(const CPyRef& o);

	//----------------------------------------------------------------------------------------
	/// Computes a string representation of an object. Equivalent to repr(o). GIL must be held.
	/// 
	/// @param[in] o									Object to stringify.
	/// @return												Result or empty object if the call failed and the exception indicator got set.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD CPyRef CPyObject_Repr(const CPyRef& o);

	//----------------------------------------------------------------------------------------
	/// Gets the internal dictionary of an object. Equivalent to dir(o). GIL must be held.
	/// 
	/// @param[in] o									Object to get the dictionary from..
	/// @return												Result or empty object if the call failed and the exception indicator got set.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD CPyRef CPyObject_Dir(const CPyRef& o);

	//----------------------------------------------------------------------------------------
	/// Rich compares two objects with each other and returns its result. Equivalent to "o1 op o2". GIL must be held.
	/// 
	/// @param[in] o1									Left operand.
	/// @param[in] o2									Right operand.
	/// @return												Result or empty object if the call failed and the exception indicator got set.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD CPyRef CPyObject_RichCompare(const CPyRef& o1, const CPyRef& o2, Int32 opid);

	//----------------------------------------------------------------------------------------
	/// Computes the hash of an object. Equivalent to hash(o). GIL must be held.
	/// 
	/// @param[in] o									Left operand.
	/// @return												The hash or -1 if the exception indicator got set.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Int64 CPyObject_Hash(const CPyRef& o);

	//----------------------------------------------------------------------------------------
	/// Returns true if the object is considered to be true, and false otherwise. This is equivalent to the Python expression 'not not o'. GIL must be held.
	/// 
	/// @param[in] o									Left operand.
	/// @return												True if the object is true, otherwise false.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Bool CPyObject_IsTrue(const CPyRef& o);

	//----------------------------------------------------------------------------------------
	/// Returns false if the object is considered to be true, and true otherwise. This is equivalent to the Python expression 'not o'. GIL must be held.
	/// 
	/// @param[in] o									Left operand.
	/// @return												True if the object is true, otherwise false.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Bool CPyObject_Not(const CPyRef& o);

	//----------------------------------------------------------------------------------------
	/// Checks if a given object is a callable. GIL must be held.
	/// 
	/// @param[in] o									A given object.
	/// @return												True if o is callable.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Bool CPyCallable_Check(const CPyRef& o);

	//----------------------------------------------------------------------------------------
	/// Returns the length of an object. GIL must be held.
	/// 
	/// @param[in] o									A given object.
	/// @return												Length or -1 if the exception indicator is set.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Int CPyObject_Length(const CPyRef& o);

	//----------------------------------------------------------------------------------------
	/// Gets the item of an object. Equivalent to getitem(o). GIL must be held.
	/// 
	/// @param[in] o									Object.
	/// @param[in] key								Key object.
	/// @return												Result object or empty object if the exception indicator got set.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD CPyRef CPyObject_GetItem(const CPyRef& o, const CPyRef& key);
	
	//----------------------------------------------------------------------------------------
	/// Gets the item of an object by an index. Equivalent to getitem(o, intValue). GIL must be held.
	/// 
	/// @param[in] o									Object.
	/// @param[in] index							Int key.
	/// @return												Result object or empty object if the exception indicator got set.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD CPyRef CPyObject_GetItemInt(const CPyRef& o, Int index);
	
	//----------------------------------------------------------------------------------------
	/// Gets the item of an object by a string. Equivalent to getitem(o, strValue). GIL must be held.
	/// 
	/// @param[in] o									Object.
	/// @param[in] index							String key.
	/// @return												Result object or empty object if the exception indicator got set.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD CPyRef CPyObject_GetItemString(const CPyRef& o, const Char* index);

	//----------------------------------------------------------------------------------------
	/// Deletes an item of an object by a given key.
	/// 
	/// @param[in] o									Object.
	/// @param[in] key								Object key.
	/// @return												True on success, or false if the exception indicator got set.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Bool CPyObject_DelItem(const CPyRef& o, const CPyRef& key);
	
	//----------------------------------------------------------------------------------------
	/// Sets an item to an object at a given key. Equivalent to o[key]. GIL must be held.
	/// 
	/// @param[in] o									Object.
	/// @param[in] key								String key.
	/// @param[in] item								Object item.
	/// @return												True on success, or false if the exception indicator got set.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Bool CPyObject_SetItem(const CPyRef& o, const CPyRef& key, const CPyRef& item);

	//----------------------------------------------------------------------------------------
	/// Check if a given object is of a certain type.
	/// 
	/// @param[in] object							Object to check.
	/// @param[in] type								Type object.
	/// @return												True on match, otherwise False.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Bool CPyObject_TypeCheck(const CPyRef& object, const CPyTypeRef& type);

	//----------------------------------------------------------------------------------------
	/// Calls an object. Equivalent to o(). GIL must be held.
	/// 
	/// @param[in] o									Object to call.
	/// @return												Result object or empty object if the exception indicator got set.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD CPyRef CPyObject_CallFunction(const CPyRef& o);

	//----------------------------------------------------------------------------------------
	/// Retrieves an object from the sys module by its name. GIL must be held.
	/// 
	/// @param[in] name								Name of the object.
	/// @return												Result object or empty object if the exception indicator got set.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD CPyRef CPySys_GetObject(const Char* name);
	
	//----------------------------------------------------------------------------------------
	/// Sets an object to the sys module. GIL must be held.
	/// 
	/// @param[in] name								Name of the object.
	/// @param[in] o									Object to set.
	/// @return												True on success, or false if the exception indicator got set.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Bool CPySys_SetObject(const Char* name, const CPyRef& o);

	//----------------------------------------------------------------------------------------
	/// Sets an array of paths to sys.path. GIL must be held.
	/// 
	/// @param[in] paths							Array of paths to set. None of the elements must be empty.
	/// @param[in] add								Mode of the operation.
	/// @return												OK on success or error, if the exception indicator got set.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> CPySys_SetPath(const BaseArray<Url>& paths, PATHHANDLE add);

	//----------------------------------------------------------------------------------------
	/// Sets the arguments to sys.argv.
	/// 
	/// @param[in] args								New arguments.
	/// @param[in] updatepath					Bool to update sys.path, otherwise false.
	/// @return												OK on success or error, if the exception indicator got set.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> CPySys_SetArgvEx(const BaseArray<String>& args, Bool updatepath);

	//----------------------------------------------------------------------------------------
	/// Returns an array of URLs which are in sys.path.
	/// 
	/// @return												Array of Url objects.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD BaseArray<Url> CPySys_GetPath();

	//----------------------------------------------------------------------------------------
	/// Adds a directory to sys.path and process its .pth files.
	/// 
	/// @param[in] siteDir						Directory to add.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> CPySite_AddSiteDir(const Url& siteDir);

	//----------------------------------------------------------------------------------------
	/// Checks if the given object is a str or a subtype of StringType. GIL must be held.
	/// 
	/// @param[in] o									A given object.
	/// @return												True if o is a str.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Bool CPyString_Check(const CPyRef& o);

	//----------------------------------------------------------------------------------------
	/// Converts a given string to a string object. GIL must be held.
	/// 
	/// @param[in] str								String constant.
	/// @return												String object or empty object if the exception indicator got set.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD CPyRef CPyString_FromString(const Char* str) const;

	//----------------------------------------------------------------------------------------
	/// Converts a given block to a string object. GIL must be held.
	/// 
	/// @param[in] block							Char block.
	/// @return												String object or empty object if the exception indicator got set.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD CPyRef CPyString_FromStringAndSize(const Block<const Char>& block);

	//----------------------------------------------------------------------------------------
	/// Converts a string object to a string. GIL must be held.
	/// 
	/// @param[in] str								String object.
	/// @return												String or error if the exception indicator got set.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<String> CPyString_AsString(const CPyRef& str);

	//----------------------------------------------------------------------------------------
	/// Retrieves the pointer to a chary array of a string object. The char array is alive as long as the string object
	/// is alive. Until the string object gets deleted, the char array will be deleted too. GIL must be held.
	/// 
	/// @param[in] str								String object.
	/// @return												Pointer to char array, or nullptr if the the exception indicator got set.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD const Char* CPyString_AsCString(const CPyRef& str);

	//----------------------------------------------------------------------------------------
	/// Gets the size of a string. GIL must be held.
	/// 
	/// @param[in] str								String object.
	/// @return												Length or -1 if the exception indicator got set.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Int CPyString_Size(const CPyRef& str);

	//----------------------------------------------------------------------------------------
	/// Gets the iterator of an object. Equivalent to iter(o). GIL must be held.
	/// 
	/// @param[in] o									Object to get the iterator from/
	/// @return												Iterator object.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD CPyRef CPyObject_GetIter(const CPyRef& o) const;

	//----------------------------------------------------------------------------------------
	/// Iterate next in an iterator. Equivalent to next(it)
	/// 
	/// @param[in] it									Iterator object.
	/// @return												Next object or empty object if the exception indicator is set. If the last element got reached, StopIteration is set.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD CPyRef CPyIter_Next(const CPyRef& it) const;

	//----------------------------------------------------------------------------------------
	/// Creates a new empty dictionary. GIL must be held.
	/// 
	/// @return												Dictionary object.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD CPyRef CPyDict_New() const;

	//----------------------------------------------------------------------------------------
	/// Gets the item of a dictionary. GIL must be held.
	/// 
	/// @param[in] dict								Dict object.
	/// @param[in] key								Key object.
	/// @param[in] raiseKeyError			True to raise a KeyError if the item was not found, otherwise false and only an empty object is returned.
	/// @return												Value of the passed key. Depending on raiseKeyError, an exception is set if the key was found, or not.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD CPyRef CPyDict_GetItem(const CPyRef& dict, const CPyRef& key, Bool raiseKeyError);

	//----------------------------------------------------------------------------------------
	/// Gets the item of a dictionary by a given key string. 
	/// 
	/// @param[in] dict								Dict object.
	/// @param[in] key								Key string.
	/// @param[in] raiseKeyError			True to raise a KeyError if the item was not found, otherwise false and only an empty object is returned.
	/// @return												Value of the passed key. Depending on raiseKeyError, an exception is set if the key was found, or not.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD CPyRef CPyDict_GetItemString(const CPyRef& dict, const Char* key, Bool raiseKeyError);

	//----------------------------------------------------------------------------------------
	/// Sets an item to a dictionary. GIL must be held.
	/// 
	/// @param[in] dict								Dict object.
	/// @param[in] key								Key object.
	/// @param[in] item								Value item.
	/// @return               True on sucess, or false if the exception indicator got set.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Bool CPyDict_SetItem(const CPyRef& dict, const CPyRef& key, const CPyRef& item);

	//----------------------------------------------------------------------------------------
	/// Deletes an item from a dictionary. GIL must be held.
	/// 
	/// @param[in] dict								Dict object.
	/// @param[in] key								Key object.
	/// @return               True on sucess, or false if the item was not found and the exception indicator got set.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Bool CPyDict_DelItem(const CPyRef& dict, const CPyRef& key);
	MAXON_METHOD CONTAINS CPyDict_Contains(const CPyRef& dict, const CPyRef& key);

	//----------------------------------------------------------------------------------------
	/// Removes all elements from the dictionary. GIL must be held.
	/// 
	/// @param[in] dict								Dict object.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD void CPyDict_Clear(const CPyRef& dict);

	//----------------------------------------------------------------------------------------
	/// Goes to the next element in the dictionary, starting from a given index.
	/// 
	/// @param[in] dict								Dict object.
	/// @param[in,out] pos						Index start and gets incremented by one when the function leaves.
	/// @param[in] key								Key object.
	/// @param[in] value							Value object.
	/// @return               True on sucess, or false if the item was not found and the exception indicator got set.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Bool CPyDict_Next(const CPyRef& dict, Int& pos, CPyRef& key, CPyRef& value);

	//----------------------------------------------------------------------------------------
	/// Gets all keys of a dictionary in a list. GIL must be held.
	/// 
	/// @param[in] dict								Dict object.
	/// @return												List of keys.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD CPyRef CPyDict_Keys(const CPyRef& dict);

	//----------------------------------------------------------------------------------------
	/// Gets all values of a dictionary in a list. GIL must be held.
	/// 
	/// @param[in] dict								Dict object.
	/// @return												List of values.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD CPyRef CPyDict_Values(const CPyRef& dict);

	//----------------------------------------------------------------------------------------
	/// Gets all items of a dictionary in a list. GIL must be held.
	/// 
	/// @param[in] dict								Dict object.
	/// @return												List of items.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD CPyRef CPyDict_Items(const CPyRef& dict);

	//----------------------------------------------------------------------------------------
	/// Return the number of items in the dictionary. This is equivalent to len(p) on a dictionary. GIL must be held.
	/// 
	/// @param[in] dict								Dict object.
	/// @return												Number of items.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Int CPyDict_Size(const CPyRef& dict);

	//----------------------------------------------------------------------------------------
	/// Gets a copy of a given dictionary. Does not make a deepcopy. GIL must be held.
	/// 
	/// @param[in] dict								Dict object.
	/// @return												Number of items.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD CPyRef CPyDict_Copy(const CPyRef& dict);

	//----------------------------------------------------------------------------------------
	/// Sets an item to a dictionary at a given key.
	/// 
	/// @param[in] dict								Dict object.
	/// @param[in] key								String key.
	/// @param[in] item								Item to set.
	/// @return												True on sucess, or false if the exception indicator got set.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Bool CPyDict_SetItemString(const CPyRef& dict, const Char* key, const CPyRef& item) const;

	//----------------------------------------------------------------------------------------
	/// Checks if the given object is a dict. GIL must be held.
	/// 
	/// @param[in] o									A given object.
	/// @return												True if o is a dict.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Bool CPyDict_Check(const CPyRef& o) const;

	//----------------------------------------------------------------------------------------
	/// Creates a new list of a certain size. GIL must be held.
	/// 
	/// @param[in] size								Size of the list.
	/// @return												New list object.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD CPyRef CPyList_New(UInt size);

	//----------------------------------------------------------------------------------------
	/// Checks if a list is a list. No subtype check is performed. GIL must be held.
	/// 
	/// @param[in] list								Object to check.
	/// @return												True if the object is a list, otherwise false.
	//----------------------------------------------------------------------------------------

	MAXON_METHOD Bool CPyList_CheckExact(const CPyRef& list);
	
	MAXON_METHOD Int CPyList_Size(const CPyRef& list);
	MAXON_METHOD CPyRef CPyList_GetItem(const CPyRef& list, UInt index);
	MAXON_METHOD Bool CPyList_SetItem(const CPyRef& list, UInt, const CPyRef& item);
	MAXON_METHOD Bool CPyList_Insert(const CPyRef& list, UInt, const CPyRef& item);
	MAXON_METHOD Bool CPyList_Append(const CPyRef& list, const CPyRef& item);
	MAXON_METHOD CPyRef CPyList_GetSlice(const CPyRef& list, UInt from, UInt to);
	MAXON_METHOD Bool CPyList_SetSlice(const CPyRef& list, UInt from, UInt to, const CPyRef& item);
	MAXON_METHOD Bool CPyList_Sort(const CPyRef& list);
	MAXON_METHOD Bool CPyList_Reverse(const CPyRef& list);
	MAXON_METHOD CPyRef CPyList_AsTuple(const CPyRef& list);
	MAXON_METHOD Bool CPyDict_DelItemString(const CPyRef& p, const Char* key);


	//----------------------------------------------------------------------------------------
	/// Checks if the given object is a module. GIL must be held.
	/// 
	/// @param[in] o									A given object.
	/// @return												True if o is a module.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Bool CPyModule_Check(const CPyRef& o);
	MAXON_METHOD Bool CPyModule_AddObject(const CPyRef& module, const Char* name, const CPyRef& value);
	MAXON_METHOD CPyRef CPyModule_GetDict(const CPyRef& module);
	MAXON_METHOD Bool CPyModule_AddIntConstant(const CPyRef& mod, const Char* name, long value);

	/// import
	MAXON_METHOD CPyRef CPyImport_ImportModule(const Char* name);
	MAXON_METHOD CPyRef CPyImport_GetImporter(const CPyRef& path);

	//----------------------------------------------------------------------------------------
	/// Checks if the given object is a type. GIL must be held.
	/// 
	/// @param[in] o									A given object.
	/// @return												True if o is a type.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Bool CPyType_Check(const CPyRef& o);

	//----------------------------------------------------------------------------------------
	/// Checks if a type is really a subclass, __subclasscheck__() is not called. An object is not a subtype of its own class. Use CPyObject_IsSubtype instead. GIL must be held.
	/// 
	/// @param[in] a									Base type.
	/// @param[in] b									Subtype type.
	/// @return												Returns true if a is a subtype of b.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Bool CPyType_IsSubtype(const CPyTypeRef& a, const CPyTypeRef& b);

	//----------------------------------------------------------------------------------------
	/// Checks if a type has a certain feature.
	/// 
	/// @param[in] type								Type object.
	/// @param[in] f									Feature value.
	/// @return												True if the type supports this feature or false if not.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Bool CPyType_HasFeature(const CPyTypeRef& type, Int64 f) const;

	//----------------------------------------------------------------------------------------
	/// Performs a quick subtype check. 
	/// 
	/// @param[in] type								Type object.
	/// @param[in] f									Subtype value.
	/// @return												True if the type is of the given subtype or false if not.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Bool CPyType_FastSubclass(const CPyTypeRef& type, Int64 f) const;


	//----------------------------------------------------------------------------------------
	/// Returns the name of a given type.
	/// 
	/// @param[in] type								Type object.
	/// @return												Name of the type or error if the exception indicator got set.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<String> CPyType_GetName(const CPyTypeRef& type);

	//----------------------------------------------------------------------------------------
	/// Initializes a type.
	/// 
	/// @param[in] type								Type object to initialize. 
	/// @return												True on success.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Bool CPyType_Ready(CPyTypeRef& type);

	//----------------------------------------------------------------------------------------
	/// Release the global interpreter lock 
	/// 
	/// @return												Previous state object.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD NativePyThreadState* CPyEval_SaveThread();

	//----------------------------------------------------------------------------------------
	/// Restores a given thread state object.
	/// 
	/// @param[in] state							Thread state object.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD void CPyEval_RestoreThread(NativePyThreadState* state);

	//----------------------------------------------------------------------------------------
	/// Checks if multi-threading for Python is enabled.
	/// 
	/// @return												True if available.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Bool CPyEval_ThreadsInitialized();

	//-------------------------------------------------
	/// Private. Initializes multi-threading for the Python library. Must not be called on the pre-allocated Python instances!
	//-------------------------------------------------
	MAXON_METHOD void CPyEval_InitThreads();

	//-------------------------------------------------
	/// Acquires the GIL.
	//-------------------------------------------------
	MAXON_METHOD void CPyEval_AcquireLock();

	//-------------------------------------------------
	/// Releases the GIL.
	//-------------------------------------------------
	MAXON_METHOD void CPyEval_ReleaseLock();

	//----------------------------------------------------------------------------------------
	/// Acquires the GIL for a thread state object.
	/// 
	/// @param[in] state							Thread state object.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD void CPyEval_AcquireThread(NativePyThreadState* state);

	//----------------------------------------------------------------------------------------
	/// Releases the GIL for a thread state object.
	/// 
	/// @param[in] state							Thread state object.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD void CPyEval_ReleaseThread(NativePyThreadState* state);

	//-------------------------------------------------
	/// Private. Reinitializes the multi-threading. Must not be called on the pre-allocated Python instances!
	//-------------------------------------------------
	MAXON_METHOD void CPyEval_ReInitThreads();

	//----------------------------------------------------------------------------------------
	/// Returns the builtins of Python
	/// 
	/// @return												Builtins.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD CPyRef CPyEval_GetBuiltins() const;

	//----------------------------------------------------------------------------------------
	/// Executes a given code object in the given globals, and locals dictionary.
	/// 
	/// @param[in] code								Code object to execute.
	/// @param[in] globals						Global scope.
	/// @param[in] locals							Local scope.
	/// @return												Result object or empty object if the exception indicator got set.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD CPyRef CPyEval_EvalCode(const CPyCodeRef& code, const CPyRef& globals, const CPyRef& locals) const;

	//----------------------------------------------------------------------------------------
	/// Checks if the given object is a float. GIL must be held.
	/// 
	/// @param[in] o									A given object.
	/// @return												True if o is a float.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Bool CPyFloat_Check(const CPyRef& o);

	//----------------------------------------------------------------------------------------
	/// Creates a float object from a Float32.
	///
	/// @param[in] value							Float32 value.
	/// @return												bool object.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD CPyRef CPyFloat_FromFloat32(Float32 value);

	//----------------------------------------------------------------------------------------
	/// Creates a float object from a Float64.
	///
	/// @param[in] value							Float64 value.
	/// @return												bool object.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD CPyRef CPyFloat_FromFloat64(Float64 value);

	//----------------------------------------------------------------------------------------
	/// Converts a float object to Float64.
	/// 
	/// @param[in] o									Object to convert.
	/// @return												Result or -1 if the exception indicator got set.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Float64 CPyFloat_AsFloat64(const CPyRef& o);
	
	//----------------------------------------------------------------------------------------
	/// Converts an object to a floating type.
	/// 
	/// @tparam T											Floating type.
	/// @param[in] o									Object to convert.
	/// @return												Result value.
	//----------------------------------------------------------------------------------------
	template <typename T>
	MAXON_FUNCTION T CPyFloat_As(const CPyRef& o);
	
	//----------------------------------------------------------------------------------------
	/// Converts an object from a Float32 value.
	/// 
	/// @param[in] o									Float value.
	/// @return												Float object.
	//----------------------------------------------------------------------------------------
	template <typename T>
	MAXON_FUNCTION CPyRef CPyFloat_From(std::enable_if_t<std::is_same<T, Float32>::value, Float32> o);
	
	//----------------------------------------------------------------------------------------
	/// Converts an object from a Float64 value.
	/// 
	/// @param[in] o									Float value.
	/// @return												Float object.
	//----------------------------------------------------------------------------------------
	template <typename T>
	MAXON_FUNCTION CPyRef CPyFloat_From(std::enable_if_t<std::is_same<T, Float64>::value, Float64> o);

	//----------------------------------------------------------------------------------------
	/// Checks if the given object is an int or a subtype of PyInt_Type. GIL must be held.
	/// 
	/// @param[in] o									A given object.
	/// @return												True if o is a 
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Bool CPyInt_Check(const CPyRef& o);

	//----------------------------------------------------------------------------------------
	/// Creates a bool object from a Bool.
	///
	/// @param[in] value							Bool value.
	/// @return												bool object.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD CPyRef CPyBool_FromBool(Bool value);

	//----------------------------------------------------------------------------------------
	/// Creates an int object from a Int16 value.
	///
	/// @param[in] value							Int value.
	/// @return												Int object.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD CPyRef CPyInt_FromInt16(Int16 value);

	//----------------------------------------------------------------------------------------
	/// Creates an int object from a UInt16 value.
	///
	/// @param[in] value							Int value.
	/// @return												Int object.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD CPyRef CPyInt_FromUInt16(UInt16 value);
	//----------------------------------------------------------------------------------------
	/// Creates an int object from a Int32 value.
	///
	/// @param[in] value							Int value.
	/// @return												Int object.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD CPyRef CPyInt_FromInt32(Int32 value);
	//----------------------------------------------------------------------------------------
	/// Creates an int object from a UInt32 value.
	///
	/// @param[in] value							Int value.
	/// @return												Int object.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD CPyRef CPyInt_FromUInt32(UInt32 value);
	//----------------------------------------------------------------------------------------
	/// Creates an int object from a Int64 value.
	///
	/// @param[in] value							Int value.
	/// @return												Int object.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD CPyRef CPyInt_FromInt64(Int64 value);
	//----------------------------------------------------------------------------------------
	/// Creates an int object from a UInt64 value. GIL must be held.
	///
	/// @param[in] value							Int value.
	/// @return												Int object.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD CPyRef CPyInt_FromUInt64(UInt64 value);

	//----------------------------------------------------------------------------------------
	/// Converts an object to an Int16 value. GIL must be held.
	///
	/// @param[in] o									Object to convert.
	/// @return												Integer value, or -1 if the exception indicator got set.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Int16 CPyInt_AsInt16(const CPyRef& o);

	//----------------------------------------------------------------------------------------
	/// Converts an object to an UInt16 value. GIL must be held.
	///
	/// @param[in] o									Object to convert.
	/// @return												Integer value, or -1 if the exception indicator got set.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD UInt16 CPyInt_AsUInt16(const CPyRef& o);

	//----------------------------------------------------------------------------------------
	/// Converts an object to an Int32 value. GIL must be held.
	///
	/// @param[in] o									Object to convert.
	/// @return												Integer value, or -1 if the exception indicator got set.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Int32 CPyInt_AsInt32(const CPyRef& o);

	//----------------------------------------------------------------------------------------
	/// Converts an object to an UInt32 value. GIL must be held.
	///
	/// @param[in] o									Object to convert.
	/// @return												Integer value, or -1 if the exception indicator got set.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD UInt32 CPyInt_AsUInt32(const CPyRef& o);

	//----------------------------------------------------------------------------------------
	/// Converts an object to an Int64 value. GIL must be held.
	///
	/// @param[in] o									Object to convert.
	/// @return												Integer value, or -1 if the exception indicator got set.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Int64 CPyInt_AsInt64(const CPyRef& o);

	//----------------------------------------------------------------------------------------
	/// Converts an object to an UInt64 value. GIL must be held.
	///
	/// @param[in] o									Object to convert.
	/// @return												Integer value, or -1 if the exception indicator got set.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD UInt64 CPyInt_AsUInt64(const CPyRef& o);

	//----------------------------------------------------------------------------------------
	/// Converts an object to type T. GIL must be held.
	/// 
	/// @tparam T											Integral type.
	/// @param[in] o									Object to convert.
	/// @return												Result value.
	//----------------------------------------------------------------------------------------
	template <typename T>
	MAXON_FUNCTION T CPyInt_As(const CPyRef& o);

	//----------------------------------------------------------------------------------------
	/// Converts an object from an Int32 value. GIL must be held.
	/// 
	/// @param[in] o									Int value.
	/// @return												Int object.
	//----------------------------------------------------------------------------------------
	template <typename T>
	MAXON_FUNCTION CPyRef CPyInt_From(std::enable_if_t<std::is_same<T, Int32>::value, Int32> o);

	//----------------------------------------------------------------------------------------
	/// Converts an object from an Int64 value. GIL must be held.
	/// 
	/// @param[in] o									Int64 value.
	/// @return												Int object.
	//----------------------------------------------------------------------------------------
	template <typename T>
	MAXON_FUNCTION CPyRef CPyInt_From(std::enable_if_t<std::is_same<T, Int64>::value, Int64> o);

	//----------------------------------------------------------------------------------------
	/// Checks if the given object is a numeric object. GIL must be held.
	/// 
	/// @param[in] o									Object to check.
	/// @return												True if an object is a numeric value.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Bool CPyNumber_Check(const CPyRef& o);

	//----------------------------------------------------------------------------------------
	/// Creates a function capsule that encapsulates a reflection::Function pointer.
	/// 
	/// @param[in] func								Function pointer to encapsulate.
	/// @return												New function capsule or empty object if the exception indicator got set.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD MPyFunctionRef MPyFunction_New(const reflection::Function* func);

	//----------------------------------------------------------------------------------------
	/// Creates a member capsule that encapsulates a reflection::Member pointer.
	/// 
	/// @param[in] member							Member pointer to encapsulate.
	/// @return												New member capsule or empty object if the exception indicator got set.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD MPyMemberRef MPyMember_New(const reflection::Member* member);

	//----------------------------------------------------------------------------------------
	/// Creates a class capsule that encapsulates a reflection::Member pointer.
	/// 
	/// @param[in] cls								Class pointer to encapsulate.
	/// @return												New class capsule or empty object if the exception indicator got set.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD MPyClassRef MPyClass_New(const reflection::Class* cls);

		//----------------------------------------------------------------------------------------
		/// Returns a mutable pointer to a DebugFlag. Can be nullptr if the flag is not available in this Python version.
		///
		/// @return												DebugFlag flag
		//----------------------------------------------------------------------------------------
		MAXON_METHOD Int32* CPy_DebugFlag();

		//----------------------------------------------------------------------------------------
		/// Returns a mutable pointer to a VerboseFlag. Can be nullptr if the flag is not available in this Python version.
		///
		/// @return												VerboseFlag flag
		//----------------------------------------------------------------------------------------
		MAXON_METHOD Int32* CPy_VerboseFlag();

		//----------------------------------------------------------------------------------------
		/// Returns a mutable pointer to a InteractiveFlag. Can be nullptr if the flag is not available in this Python version.
		///
		/// @return												InteractiveFlag flag
		//----------------------------------------------------------------------------------------
		MAXON_METHOD Int32* CPy_InteractiveFlag();

		//----------------------------------------------------------------------------------------
		/// Returns a mutable pointer to a InspectFlag. Can be nullptr if the flag is not available in this Python version.
		///
		/// @return												InspectFlag flag
		//----------------------------------------------------------------------------------------
		MAXON_METHOD Int32* CPy_InspectFlag();

		//----------------------------------------------------------------------------------------
		/// Returns a mutable pointer to a OptimizeFlag. Can be nullptr if the flag is not available in this Python version.
		///
		/// @return												OptimizeFlag flag
		//----------------------------------------------------------------------------------------
		MAXON_METHOD Int32* CPy_OptimizeFlag();

		//----------------------------------------------------------------------------------------
		/// Returns a mutable pointer to a NoSiteFlag. Can be nullptr if the flag is not available in this Python version.
		///
		/// @return												NoSiteFlag flag
		//----------------------------------------------------------------------------------------
		MAXON_METHOD Int32* CPy_NoSiteFlag();

		//----------------------------------------------------------------------------------------
		/// Returns a mutable pointer to a BytesWarningFlag. Can be nullptr if the flag is not available in this Python version.
		///
		/// @return												BytesWarningFlag flag
		//----------------------------------------------------------------------------------------
		MAXON_METHOD Int32* CPy_BytesWarningFlag();

		//----------------------------------------------------------------------------------------
		/// Returns a mutable pointer to a UseClassExceptionsFlag. Can be nullptr if the flag is not available in this Python version.
		///
		/// @return												UseClassExceptionsFlag flag
		//----------------------------------------------------------------------------------------
		MAXON_METHOD Int32* CPy_UseClassExceptionsFlag();

		//----------------------------------------------------------------------------------------
		/// Returns a mutable pointer to a FrozenFlag. Can be nullptr if the flag is not available in this Python version.
		///
		/// @return												FrozenFlag flag
		//----------------------------------------------------------------------------------------
		MAXON_METHOD Int32* CPy_FrozenFlag();

		//----------------------------------------------------------------------------------------
		/// Returns a mutable pointer to a TabcheckFlag. Can be nullptr if the flag is not available in this Python version.
		///
		/// @return												TabcheckFlag flag
		//----------------------------------------------------------------------------------------
		MAXON_METHOD Int32* CPy_TabcheckFlag();

		//----------------------------------------------------------------------------------------
		/// Returns a mutable pointer to a UnicodeFlag. Can be nullptr if the flag is not available in this Python version.
		///
		/// @return												UnicodeFlag flag
		//----------------------------------------------------------------------------------------
		MAXON_METHOD Int32* CPy_UnicodeFlag();

		//----------------------------------------------------------------------------------------
		/// Returns a mutable pointer to a IgnoreEnvironmentFlag. Can be nullptr if the flag is not available in this Python version.
		///
		/// @return												IgnoreEnvironmentFlag flag
		//----------------------------------------------------------------------------------------
		MAXON_METHOD Int32* CPy_IgnoreEnvironmentFlag();

		//----------------------------------------------------------------------------------------
		/// Returns a mutable pointer to a DivisionWarningFlag. Can be nullptr if the flag is not available in this Python version.
		///
		/// @return												DivisionWarningFlag flag
		//----------------------------------------------------------------------------------------
		MAXON_METHOD Int32* CPy_DivisionWarningFlag();

		//----------------------------------------------------------------------------------------
		/// Returns a mutable pointer to a DontWriteBytecodeFlag. Can be nullptr if the flag is not available in this Python version.
		///
		/// @return												DontWriteBytecodeFlag flag
		//----------------------------------------------------------------------------------------
		MAXON_METHOD Int32* CPy_DontWriteBytecodeFlag();

		//----------------------------------------------------------------------------------------
		/// Returns a mutable pointer to a NoUserSiteDirectory. Can be nullptr if the flag is not available in this Python version.
		///
		/// @return												NoUserSiteDirectory flag
		//----------------------------------------------------------------------------------------
		MAXON_METHOD Int32* CPy_NoUserSiteDirectory();

		//----------------------------------------------------------------------------------------
		/// Returns a mutable pointer to a QnewFlag. Can be nullptr if the flag is not available in this Python version.
		///
		/// @return												QnewFlag flag
		//----------------------------------------------------------------------------------------
		MAXON_METHOD Int32* CPy_QnewFlag();

		//----------------------------------------------------------------------------------------
		/// Returns a mutable pointer to a Py3kWarningFlag. Can be nullptr if the flag is not available in this Python version.
		///
		/// @return												Py3kWarningFlag flag
		//----------------------------------------------------------------------------------------
		MAXON_METHOD Int32* CPy_Py3kWarningFlag();

		//----------------------------------------------------------------------------------------
		/// Returns a mutable pointer to a CheckInterval. Can be nullptr if the flag is not available in this Python version.
		///
		/// @return												CheckInterval flag
		//----------------------------------------------------------------------------------------
		MAXON_METHOD Int32* CPy_CheckInterval();

	//----------------------------------------------------------------------------------------
	/// Returns the BaseException.
	///
	/// @return												The BaseException exception.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD CPyConstRef CPyExc_BaseException();

	//----------------------------------------------------------------------------------------
	/// Returns the Exception.
	///
	/// @return												The Exception exception.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD CPyConstRef CPyExc_Exception();

	//----------------------------------------------------------------------------------------
	/// Returns the StopIteration.
	///
	/// @return												The StopIteration exception.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD CPyConstRef CPyExc_StopIteration();

	//----------------------------------------------------------------------------------------
	/// Returns the GeneratorExit.
	///
	/// @return												The GeneratorExit exception.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD CPyConstRef CPyExc_GeneratorExit();

	//----------------------------------------------------------------------------------------
	/// Returns the StandardError.
	///
	/// @return												The StandardError exception.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD CPyConstRef CPyExc_StandardError();

	//----------------------------------------------------------------------------------------
	/// Returns the ArithmeticError.
	///
	/// @return												The ArithmeticError exception.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD CPyConstRef CPyExc_ArithmeticError();

	//----------------------------------------------------------------------------------------
	/// Returns the LookupError.
	///
	/// @return												The LookupError exception.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD CPyConstRef CPyExc_LookupError();

	//----------------------------------------------------------------------------------------
	/// Returns the AssertionError.
	///
	/// @return												The AssertionError exception.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD CPyConstRef CPyExc_AssertionError();

	//----------------------------------------------------------------------------------------
	/// Returns the AttributeError.
	///
	/// @return												The AttributeError exception.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD CPyConstRef CPyExc_AttributeError();

	//----------------------------------------------------------------------------------------
	/// Returns the EOFError.
	///
	/// @return												The EOFError exception.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD CPyConstRef CPyExc_EOFError();

	//----------------------------------------------------------------------------------------
	/// Returns the FloatingPointError.
	///
	/// @return												The FloatingPointError exception.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD CPyConstRef CPyExc_FloatingPointError();
	
	//----------------------------------------------------------------------------------------
	/// Returns the EnvironmentError.
	///
	/// @return												The EnvironmentError exception.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD CPyConstRef CPyExc_EnvironmentError();

	//----------------------------------------------------------------------------------------
	/// Returns the IOError.
	///
	/// @return												The IOError exception.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD CPyConstRef CPyExc_IOError();

	//----------------------------------------------------------------------------------------
	/// Returns the OSError.
	///
	/// @return												The OSError exception.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD CPyConstRef CPyExc_OSError();

	//----------------------------------------------------------------------------------------
	/// Returns the ImportError.
	///
	/// @return												The ImportError exception.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD CPyConstRef CPyExc_ImportError();

	//----------------------------------------------------------------------------------------
	/// Returns the IndexError.
	///
	/// @return												The IndexError exception.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD CPyConstRef CPyExc_IndexError();

	//----------------------------------------------------------------------------------------
	/// Returns the KeyError.
	///
	/// @return												The KeyError exception.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD CPyConstRef CPyExc_KeyError();

	//----------------------------------------------------------------------------------------
	/// Returns the KeyboardInterrupt.
	///
	/// @return												The KeyboardInterrupt exception.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD CPyConstRef CPyExc_KeyboardInterrupt();

	//----------------------------------------------------------------------------------------
	/// Returns the MemoryError.
	///
	/// @return												The MemoryError exception.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD CPyConstRef CPyExc_MemoryError();

	//----------------------------------------------------------------------------------------
	/// Returns the NameError.
	///
	/// @return												The NameError exception.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD CPyConstRef CPyExc_NameError();

	//----------------------------------------------------------------------------------------
	/// Returns the OverflowError.
	///
	/// @return												The OverflowError exception.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD CPyConstRef CPyExc_OverflowError();

	//----------------------------------------------------------------------------------------
	/// Returns the RuntimeError.
	///
	/// @return												The RuntimeError exception.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD CPyConstRef CPyExc_RuntimeError();

	//----------------------------------------------------------------------------------------
	/// Returns the NotImplementedError.
	///
	/// @return												The NotImplementedError exception.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD CPyConstRef CPyExc_NotImplementedError();

	//----------------------------------------------------------------------------------------
	/// Returns the SyntaxError.
	///
	/// @return												The SyntaxError exception.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD CPyConstRef CPyExc_SyntaxError();

	//----------------------------------------------------------------------------------------
	/// Returns the IndentationError.
	///
	/// @return												The IndentationError exception.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD CPyConstRef CPyExc_IndentationError();

	//----------------------------------------------------------------------------------------
	/// Returns the TabError.
	///
	/// @return												The TabError exception.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD CPyConstRef CPyExc_TabError();

	//----------------------------------------------------------------------------------------
	/// Returns the ReferenceError.
	///
	/// @return												The ReferenceError exception.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD CPyConstRef CPyExc_ReferenceError();

	//----------------------------------------------------------------------------------------
	/// Returns the SystemError.
	///
	/// @return												The SystemError exception.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD CPyConstRef CPyExc_SystemError();

	//----------------------------------------------------------------------------------------
	/// Returns the SystemExit.
	///
	/// @return												The SystemExit exception.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD CPyConstRef CPyExc_SystemExit();

	//----------------------------------------------------------------------------------------
	/// Returns the TypeError.
	///
	/// @return												The TypeError exception.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD CPyConstRef CPyExc_TypeError();

	//----------------------------------------------------------------------------------------
	/// Returns the UnboundLocalError.
	///
	/// @return												The UnboundLocalError exception.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD CPyConstRef CPyExc_UnboundLocalError();
	
	//----------------------------------------------------------------------------------------
	/// Returns the UnicodeError.
	///
	/// @return												The UnicodeError exception.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD CPyConstRef CPyExc_UnicodeError();

	//----------------------------------------------------------------------------------------
	/// Returns the UnicodeEncodeError.
	///
	/// @return												The UnicodeEncodeError exception.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD CPyConstRef CPyExc_UnicodeEncodeError();
	
	//----------------------------------------------------------------------------------------
	/// Returns the UnicodeDecodeError.
	///
	/// @return												The UnicodeDecodeError exception.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD CPyConstRef CPyExc_UnicodeDecodeError();
	
	//----------------------------------------------------------------------------------------
	/// Returns the UnicodeTranslateError.
	///
	/// @return												The UnicodeTranslateError exception.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD CPyConstRef CPyExc_UnicodeTranslateError();

	//----------------------------------------------------------------------------------------
	/// Returns the ValueError.
	///
	/// @return												The ValueError exception.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD CPyConstRef CPyExc_ValueError();

	//----------------------------------------------------------------------------------------
	/// Returns the ZeroDivisionError.
	///
	/// @return												The ZeroDivisionError exception.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD CPyConstRef CPyExc_ZeroDivisionError();

	//----------------------------------------------------------------------------------------
	/// Returns the WindowsError.
	///
	/// @return												The WindowsError exception.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD CPyConstRef CPyExc_WindowsError();

	//----------------------------------------------------------------------------------------
	/// Returns the BufferError.
	///
	/// @return												The BufferError exception.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD CPyConstRef CPyExc_BufferError();

	//----------------------------------------------------------------------------------------
	/// Returns the MemoryErrorInst.
	///
	/// @return												The MemoryErrorInst exception.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD CPyConstRef CPyExc_MemoryErrorInst();

	//----------------------------------------------------------------------------------------
	/// Returns the RecursionErrorInst.
	///
	/// @return												The RecursionErrorInst exception.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD CPyConstRef CPyExc_RecursionErrorInst();

	//----------------------------------------------------------------------------------------
	/// Returns the Warning.
	///
	/// @return												The Warning exception.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD CPyConstRef CPyExc_Warning();

	//----------------------------------------------------------------------------------------
	/// Returns the UserWarning.
	///
	/// @return												The UserWarning exception.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD CPyConstRef CPyExc_UserWarning();

	//----------------------------------------------------------------------------------------
	/// Returns the DeprecationWarning.
	///
	/// @return												The DeprecationWarning exception.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD CPyConstRef CPyExc_DeprecationWarning();

	//----------------------------------------------------------------------------------------
	/// Returns the PendingDeprecationWarning.
	///
	/// @return												The PendingDeprecationWarning exception.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD CPyConstRef CPyExc_PendingDeprecationWarning();

	//----------------------------------------------------------------------------------------
	/// Returns the SyntaxWarning.
	///
	/// @return												The SyntaxWarning exception.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD CPyConstRef CPyExc_SyntaxWarning();

	//----------------------------------------------------------------------------------------
	/// Returns the RuntimeWarning.
	///
	/// @return												The RuntimeWarning exception.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD CPyConstRef CPyExc_RuntimeWarning();

	//----------------------------------------------------------------------------------------
	/// Returns the FutureWarning.
	///
	/// @return												The FutureWarning exception.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD CPyConstRef CPyExc_FutureWarning();

	//----------------------------------------------------------------------------------------
	/// Returns the ImportWarning.
	///
	/// @return												The ImportWarning exception.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD CPyConstRef CPyExc_ImportWarning();

	//----------------------------------------------------------------------------------------
	/// Returns the UnicodeWarning.
	///
	/// @return												The UnicodeWarning exception.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD CPyConstRef CPyExc_UnicodeWarning();

	//----------------------------------------------------------------------------------------
	/// Returns the BytesWarning.
	///
	/// @return												The BytesWarning exception.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD CPyConstRef CPyExc_BytesWarning();

	//----------------------------------------------------------------------------------------
	/// Returns the CPyNullItype of CPyNullImporter.
	/// @return												Type of CPyNullImporter.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD CPyTypeConstRef CPyNullImporter_Type();

	//----------------------------------------------------------------------------------------
	/// Returns the Ctype of CPySuper.
	/// @return												Type of CPySuper.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD CPyTypeConstRef CPySuper_Type();

	//----------------------------------------------------------------------------------------
	/// Returns the type of CPyBool.
	/// @return												Type of CPyBool.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD CPyTypeConstRef CPyBool_Type();

	//----------------------------------------------------------------------------------------
	/// Returns the CPtype of CPyObject.
	/// @return												Type of CPyObject.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD CPyTypeConstRef CPyObject_Type();

	//----------------------------------------------------------------------------------------
	/// Returns the CPtype of CPyModule.
	/// @return												Type of CPyModule.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD CPyTypeConstRef CPyModule_Type();

	//----------------------------------------------------------------------------------------
	/// Returns the CPtype of CPyString.
	/// @return												Type of CPyString.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD CPyTypeConstRef CPyString_Type();

	//----------------------------------------------------------------------------------------
	/// Returns the type of CPyInt.
	/// @return												Type of CPyInt.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD CPyTypeConstRef CPyInt_Type();

	//----------------------------------------------------------------------------------------
	/// Returns the type of CPyLong.
	/// @return												Type of CPyLong.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD CPyTypeConstRef CPyLong_Type();

	//----------------------------------------------------------------------------------------
	/// Returns the Ctype of CPyFloat.
	/// @return												Type of CPyFloat.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD CPyTypeConstRef CPyFloat_Type();

	//----------------------------------------------------------------------------------------
	/// Returns the Ctype of CPyTuple.
	/// @return												Type of CPyTuple.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD CPyTypeConstRef CPyTuple_Type();

	//----------------------------------------------------------------------------------------
	/// Returns the type of CPyList.
	/// @return												Type of CPyList.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD CPyTypeConstRef CPyList_Type();

	//----------------------------------------------------------------------------------------
	/// Returns the type of CPyDict.
	/// @return												Type of CPyDict.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD CPyTypeConstRef CPyDict_Type();

	//----------------------------------------------------------------------------------------
	/// Returns the Ctype of CPyClass.
	/// @return												Type of CPyClass.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD CPyTypeConstRef CPyClass_Type();

	//----------------------------------------------------------------------------------------
	/// Returns the CPyTrtype of CPyTraceBack.
	/// @return												Type of CPyTraceBack.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD CPyTypeConstRef CPyTraceBack_Type();

	//----------------------------------------------------------------------------------------
	/// Returns the Ctype of CPySlice.
	/// @return												Type of CPySlice.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD CPyTypeConstRef CPySlice_Type();

	//----------------------------------------------------------------------------------------
	/// Returns the type of CPyType.
	/// @return												Type of CPyType.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD CPyTypeConstRef CPyType_Type();

	//----------------------------------------------------------------------------------------
	/// Returns the CPyMemtype of CPyMemoryView.
	/// @return												Type of CPyMemoryView.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD CPyTypeConstRef CPyMemoryView_Type();

	//----------------------------------------------------------------------------------------
	/// Converts a string with a specific encoding and stores the content for the lifetime of the Python interpreters runtime.
	/// Some functions in Python need a string that stays alive for the duration of the Pythons interpreter.
	///
	/// @param[in] str								String to convert.
	/// @param[in] encoding						Encoding to use.
	/// @return												Pointer to the first array of the string sequence. Can be casted to the corresponding code unit type.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD const PyChar* ConvertAndCacheString(const String& str, const StringEncodingRef& encoding);

	//-------------------------------------------------
	/// Private.
	//-------------------------------------------------
	MAXON_METHOD Result<void> RegisterSpecificPythonClass(const Id& typeId, const CPyTypeRef& type);

	//----------------------------------------------------------------------------------------
	/// Registers a lambda for back- and forth conversions of certain DataTypes.
	/// 
	/// @param[in] dt									DataType the converters can handle.
	/// @param[in] f1									Lambda or function to convert a Python object to a Data object.
	/// @param[in] f2									Lambda or function which converts a Data object to a Python object.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> PrivateRegisterBuiltinConverter(const DataType& dt, const DelegatePyObject_AsData& f1, const DelegatePyObject_FromData<>& f2);

	template <typename T>
	MAXON_FUNCTION Result<void> RegisterBuiltinConverter(const DelegatePyObject_AsData& f1, const DelegatePyObject_FromData<T>& f2)
	{
		iferr_scope;

		static_assert(!std::is_same<T, Data>::value, "Data must not be registered");

		/// TODO: (Seb) Delegate<Foo<T>> can be cast to another Delegate<Foo<U>> only through a void pointer?
		const void* cast1 = &f1;
		const DelegatePyObject_AsData* cast2 = static_cast<const DelegatePyObject_AsData*>(cast1);

		const void* cast4 = &f2;
		const DelegatePyObject_FromData<>* cast3 = static_cast<const DelegatePyObject_FromData<>*>(cast4);

		CPythonLibraryInterface::PrivateRegisterBuiltinConverter(GetDataType<T>(), *cast2, *cast3) iferr_return;
		return OK;
	}

	/// static helper functions
	static MAXON_METHOD Result<void> GetUrl(DEFAULTRUNTIME pythonPath, Url& pythonLibrary, Url& pythonHome);

	MAXON_METHOD Url GetSpecialPath(SPECIALPATH);
	MAXON_METHOD void RegisterSpecialPath(SPECIALPATH, const Url& path);
	
	MAXON_METHOD CPyTypeConstRef MPyDataCapsule_Type();
	MAXON_METHOD CPyTypeConstRef CPyData_Type();
	MAXON_METHOD CPyTypeConstRef CPyCapsule_Type();

	//-------------------------------------------------
	/// Private.
	//-------------------------------------------------
	MAXON_METHOD CPyRef PrivateGetCurrentCallerContext();

	MAXON_METHOD CPyRef MPyDataType_ToMapperInstance(const CPyRef& capsule);
	MAXON_METHOD CPyRef MPyData_ToMapperInstance(const MPyDataRef& capsule);
	MAXON_METHOD CPyRef CPyObject_ToMapperInstance(const DataType& dt, const CPyRef& capsule);

	MAXON_METHOD Result<void> AssociateDataTypeWithPythonTypes(const DataType& dt, const CPyRef& type);
	MAXON_METHOD Result<CPyRef> GetAssociatedDataType(const DataType& dt);

	MAXON_METHOD DelegatePyObject_FromData<>* GetConverterPyObject_FromData(const DataType& dt);

	MAXON_METHOD MPyDataRef MPyData_New(Data& data);
	MAXON_METHOD MPyDataRef MPyData_New(const DataType& dt, Generic* data, Bool owner, const DataType& mapDt = DataType::NullValue());

	//----------------------------------------------------------------------------------------
	/// Creates a DataType capsule. GIL must be held.
	/// 
	/// @param dt         Pointer of DataType to capsule.
	/// @return           New DataType capsule or empty object if exception indicator is set.
	//-------------------------------------------------
	MAXON_METHOD MPyDataTypeRef MPyDataType_New(const DataType& dt);

	//----------------------------------------------------------------------------------------
	/// Checks if the given object is a DataType capsule. GIL must be held.
	/// 
	/// @param[in] o									A given object.
	/// @return												True if o is a DataType capsule.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Bool MPyDataType_CheckExact(const CPyRef& o) const;

	//----------------------------------------------------------------------------------------
	/// Returns the internal DataType pointer of a DataType capsule. GIL must be held.
	/// 
	/// @param[in] o									DataType capsule.
	/// @return												DataType pointer or nullptr.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD const DataType& MPyDataType_GetDataType(const MPyDataTypeRef& o) const;

	//----------------------------------------------------------------------------------------
	/// Checks if the given object is a Data capsule. GIL must be held.
	/// 
	/// @param[in] o									A given object.
	/// @return												True if o is a DataType capsule.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Bool MPyData_CheckExact(const CPyRef& o) const;

	MAXON_METHOD Result<Data*> CPyObject_AsData(Int stackDepth, const CPyRef& obj, const DataType& expected, BlockArray<Data>& k, BaseArray<reflection::Argument>* n = nullptr);

	using TYPE_CONVERSION_TUPLE = Tuple<DataType, DelegatePyObject_AsData, DelegatePyObject_FromData<>>;
	MAXON_METHOD Result<BaseArray<TYPE_CONVERSION_TUPLE>> GetRegisteredTypesWithConversions();

	template <typename T>
	MAXON_FUNCTION typename std::enable_if<std::is_same<T, DataType>::value, ResultPtr<DataType>>::type ParseArgument(const CPyRef& args, Int32 argIndex, Bool isOptional = false);

	template <typename T>
	MAXON_FUNCTION Result<T> ParseRef(const CPyRef& args, Int32 argIndex, Bool isOptional = false);

	template <typename T>
	MAXON_FUNCTION typename std::enable_if<std::is_reference<T>::value || std::is_pointer<T>::value, Result<T>>::type ParseArgument(const CPyRef& args, BlockArray<Data>& tempStack, Int32 argIndex, Bool isOptional = false);

	/// if T is not NativePyObject*
	template <typename T>
    MAXON_FUNCTION typename std::enable_if<!std::is_reference<T>::value && !std::is_pointer<T>::value, Result<T>>::type ParseArgument(const CPyRef& args, BlockArray<Data>& tempStack, Int32 argIndex, Bool isOptional = false);

	MAXON_METHOD Result<DataType> ParseDataType(const CPyRef& args, Int32 argIndex, Bool canBeNone = false);

	template <typename T>
	MAXON_FUNCTION Result<T> ParseGeneric(const CPythonLibraryRef& pylib, const CPyRef& args, Int32 argIndex, DataType& dt, Bool unpackData);

	MAXON_METHOD void SetError(const Error& err);
	MAXON_METHOD void SetError(const ErrorPtr& err);

	MAXON_METHOD CPyRef MaxonConvertAuto(const CPyRef& capsule);

	MAXON_METHOD CPyRef CPyObject_FromGeneric(const DataType& origDt, const Generic* object, OWNERSHIP ownership, const CPyTypeRef* expected = nullptr, Int* count = nullptr);

	//-------------------------------------------------
	/// Creates a scope dictionary which has all built-in modules preset.
	/// 
	/// @return          New dictionary object.
	//-------------------------------------------------
	MAXON_METHOD CPyRef CreateGlobalDictionary() const;

	MAXON_METHOD Result<BaseArray<SourceLocation>> GetCurrentTraceback();

	template <typename T>
	MAXON_FUNCTION CPyRef Enum_ToMapperInstance(T enumm);

	/// Same As CPyReference27 but preferred
	MAXON_METHOD Class<CPyRef> GetCPyRefClass() const;
	MAXON_METHOD Class<CPyTypeRef> GetCPyTypeRefClass() const;
	MAXON_METHOD Class<CPyFrameRef> GetCPyFrameRefClass() const;
	MAXON_METHOD Class<CPyTracebackRef> GetCPyTracebackRefClass() const;
	MAXON_METHOD Class<CPyCodeRef> GetCPyCodeRefClass() const;
	MAXON_METHOD Class<MPyClassRef> GetMPyClassRefClass() const;
	MAXON_METHOD Class<MPyMemberRef> GetMPyMemberRefClass() const;
	MAXON_METHOD Class<MPyFunctionRef> GetMPyFunctionRefClass() const;
	MAXON_METHOD Class<MPyDataTypeRef> GetMPyDataTypeRefClass() const;
	MAXON_METHOD Class<MPyDataRef> GetMPyDataRefClass() const;
	MAXON_METHOD Class<MPyCallerContextRef> GetMPyCallerContextRefClass() const;
};

MAXON_DATATYPE(NativePyObject, "net.maxon.python.datatype.nativepyobject");

namespace specialtype
{

struct Tuple
{
};

struct BaseArray
{
};

class Slice
{
public:
	Int _start = 0;
	Int _stop = 0;
	Int _step = 0;

	MAXON_OPERATOR_EQUALITY_HASHCODE(Slice, _start, _stop, _step);

	Bool operator ==(const Slice& b)
	{
		return _start == b._start && _stop == b._stop && _step == b._step;
	}

	Bool operator !=(const Slice& b)
	{
		return !(*this == b);
	}
};

MAXON_DATATYPE(Tuple, "net.maxon.python.datatype.tuple");
MAXON_DATATYPE(Slice, "net.maxon.python.datatype.slice");
MAXON_DATATYPE(BaseArray, "net.maxon.python.datatype.basearray");

} // namespace specialtype

} // namespace py


class PyModuleRef;

using NativePyCFunctionTable = Tuple<const Char*, py::NativePyCFunctionWithKeywords>;

class PyModuleInterface : MAXON_INTERFACE_BASES(LibraryInterface)
{
	MAXON_INTERFACE(PyModuleInterface, MAXON_REFERENCE_NORMAL, "net.maxon.python.interface.module");

public:
	MAXON_METHOD Result<void> GetFunctions27(BaseArray<NativePyCFunctionTable>& functions);
	MAXON_METHOD Result<void> GetConstants(BaseArray<Tuple<const Char*, Int32>>& constants);
};

#include "cpython1.hxx"

namespace py
{

template <typename T>
MAXON_FUNCTION CPyRef CPythonLibraryInterface::Enum_ToMapperInstance(T enumm)
{
	const DataType& dt = GetDataType<T>();
	auto pyIntOrLong = CPyObject_FromGeneric(dt->GetUnderlyingType()->GetUnderlyingType(), (Generic*)&enumm, OWNERSHIP::NORMAL);

	return CPyObject_ToMapperInstance(dt, pyIntOrLong);
}

template <typename T>
MAXON_FUNCTION T CPythonLibraryInterface::CPyFloat_As(const CPyRef& o)
{
	static_assert(std::is_floating_point<T>::value, "T must be a floating point type");
	auto res = CPyFloat_AsFloat64(o);
	if (res > LIMIT<T>::Max())
	{
		CPyErr_SetString(CPyExc_OverflowError(), "value is too large");
		return -1;
	}
	return static_cast<T>(res);
}

template <typename T>
MAXON_FUNCTION CPyRef CPythonLibraryInterface::CPyFloat_From(std::enable_if_t<std::is_same<T, Float32>::value, Float32> o)
{
	return CPyFloat_FromFloat32(o);
}

template <typename T>
MAXON_FUNCTION CPyRef CPythonLibraryInterface::CPyFloat_From(std::enable_if_t<std::is_same<T, Float64>::value, Float64> o)
{
	return CPyFloat_FromFloat64(o);
}

template <typename T>
MAXON_FUNCTION T CPythonLibraryInterface::CPyInt_As(const CPyRef& o)
{
	static_assert(std::is_integral<T>::value, "T must be an integral type");
	auto res = CPyInt_AsInt64(o);
	if (res > LIMIT<T>::MAX)
	{
		CPyErr_SetString(CPyExc_OverflowError(), "value is too large");
		return -1;
	}
	return res;
}

template <typename T>
MAXON_FUNCTION CPyRef CPythonLibraryInterface::CPyInt_From(std::enable_if_t<std::is_same<T, Int32>::value, Int32> o)
{
	return CPyInt_FromInt32(o);
}

template <typename T>
MAXON_FUNCTION CPyRef CPythonLibraryInterface::CPyInt_From(std::enable_if_t<std::is_same<T, Int64>::value, Int64> o)
{
	return CPyInt_FromInt64(o);
}

template <typename T>
MAXON_FUNCTION Result<T> CPythonLibraryInterface::ParseGeneric(const CPythonLibraryRef& pylib, const CPyRef& args, Int32 argIndex, DataType& dt, Bool unpackData)
{
	iferr_scope;

	auto arg0 = CPyTuple_GetItem(args, argIndex);
	if (unpackData)
	{
		arg0 = CPyObject_GetAttrString(arg0, "_data");
	}

	if (MPyData_CheckExact(arg0) == false)
	{
		CPyErr_SetString(CPyExc_TypeError(), "expected generic capsule");  // TODO: (Seb) add "but got @"
		return PythonError(MAXON_SOURCE_LOCATION);
	}

	auto dataRef = CPyCast<MPyDataRef>(arg0);
	dt = dataRef.GetType();

	T* ptr = reinterpret_cast<T*>(dataRef.PrivateGetPtr());

	while (dt->CheckValueKind(VALUEKIND::POINTER))
	{
		dt = dt.GetElementType();
		ptr = *(T**)ptr;
	}

	if (dt->CheckValueKind(VALUEKIND::STRONG_MASK))
	{
		ptr = (T*)((ObjectRef*)ptr)->GetPointer();
	}

	return reinterpret_cast<T>(ptr);
}

template <typename T>
MAXON_FUNCTION typename std::enable_if<!std::is_reference<T>::value && !std::is_pointer<T>::value, Result<T>>::type CPythonLibraryInterface::ParseArgument(const CPyRef& args, BlockArray<Data>& tempStack, Int32 argIndex, Bool isOptional)
{
  iferr_scope;
  
  auto item = CPyTuple_GetItem(args, argIndex);
  if (MAXON_LIKELY(item != nullptr))
  {
    const DataType& expected = GetDataType<T>();
    Data* res = CPyObject_AsData(0, item, expected, tempStack) iferr_return;
    DebugAssert(res);
    
    if (expected->CheckValueKind(VALUEKIND::DATA))
      return *reinterpret_cast<T*>(res);
    else
      return *reinterpret_cast<T*>(const_cast<Generic*>(res->PrivateGetPtr()));
  }
  
  if (MAXON_UNLIKELY(isOptional))
  {
    CPyErr_Clear();
    return NullValueTypeHelper<T>::Get();
  }
  
  CPyErr_SetString(CPyExc_TypeError(), FormatString("expected at least @ argument(s), got @", argIndex, CPyTuple_Size(args)));
  return PythonError(MAXON_SOURCE_LOCATION);
}
  
template <typename T>
MAXON_FUNCTION typename std::enable_if<std::is_same<T, DataType>::value, ResultPtr<DataType>>::type CPythonLibraryInterface::ParseArgument(const CPyRef& args, Int32 argIndex, Bool isOptional)
{
  iferr_scope;

  auto item = CPyTuple_GetItem(args, argIndex);
  if (item != nullptr)
  {
    DataType dt;

    if (CPyObject_TypeCheck(item, CPyType_Type()))
    {
      iferr (String res = CPyType_GetName(item.GetTypeRef()))
        return nullptr;

      iferr (BaseArray<Char> f = res.GetCString())
        return nullptr;

      ifnoerr (dt = DataType::Get(Id((Char*)f.GetFirst())))
        return dt;
    }
    else if (CPyString_Check(item))
    {
      BlockArray<Data> tempStack;
      iferr (Id res = CPythonLibraryInterface::ParseArgument<Id>(args, tempStack, argIndex))
        return nullptr;

      ifnoerr (dt = DataType::Get(res))
        return dt;
    }
  }

  if (isOptional)
  {
        CPythonLibraryInterface::CPyErr_Clear();
  }
  else
  {
        CPythonLibraryInterface::CPyErr_SetString(CPyExc_TypeError(), FormatString("expected at least @ argument(s), got @", argIndex, CPyTuple_Size(args)));
  }
  return {};
}

template<typename T>
MAXON_ATTRIBUTE_FORCE_INLINE Bool PassedRefCheck(const CPyRef& o)
{
	return true;
}


template<>
MAXON_ATTRIBUTE_FORCE_INLINE Bool PassedRefCheck<MPyDataRef>(const CPyRef& o)
{
	return o.GetLibrary()->MPyData_CheckExact(o);
}

template <typename T>
MAXON_FUNCTION Result<T> CPythonLibraryInterface::ParseRef(const CPyRef& args, Int32 argIndex, Bool isOptional)
{
	iferr_scope;

	auto item = CPyTuple_GetItem(args, argIndex);
	if (item != nullptr)
	{
		if (PassedRefCheck<T>(item) == false)
		{
			iferr (String name = CPyType_GetName(item.GetTypeRef()))
				return PythonError(MAXON_SOURCE_LOCATION);

			CPyErr_SetString(CPyExc_TypeError(), FormatString("expected MPyData, got @", name));
			return PythonError(MAXON_SOURCE_LOCATION);
		}
		return CPyCast<T>(item);
	}

	if (isOptional)
	{
		CPyErr_Clear();
		return {};
	}

	CPyErr_SetString(CPyExc_TypeError(), FormatString("expected at least @ argument(s), got @", argIndex, CPyTuple_Size(args)));
	return PythonError(MAXON_SOURCE_LOCATION);
}

template <typename T>
MAXON_ATTRIBUTE_FORCE_INLINE typename std::enable_if<std::is_pointer<T>::value, T>::type PrivateGetPtr(Data* data)
{
	return (typename std::remove_pointer<T>::type*)(*(Generic**)data->PrivateGetPtr());
}

template <typename T>
MAXON_ATTRIBUTE_FORCE_INLINE typename std::enable_if<std::is_reference<T>::value, T>::type PrivateGetPtr(Data* data)
{
	auto* res = data->PrivateGetPtr();
	return (T)(*(Generic**)res);
}

template <>
MAXON_ATTRIBUTE_FORCE_INLINE Data& PrivateGetPtr<Data&>(Data* data)
{
	return *data;
}

template <>
MAXON_ATTRIBUTE_FORCE_INLINE Data* PrivateGetPtr<Data*>(Data* data)
{
	return data;
}

template <typename T>
MAXON_FUNCTION typename std::enable_if<std::is_reference<T>::value || std::is_pointer<T>::value, Result<T>>::type CPythonLibraryInterface::ParseArgument(const CPyRef& args, BlockArray<Data>& tempStack, Int32 argIndex, Bool isOptional)
{
	iferr_scope;

	auto item = CPyTuple_GetItem(args, argIndex);
	if (MAXON_LIKELY(item != nullptr))
	{
		const DataType& expected = GetDataType<T>();
		Data* res = CPyObject_AsData(0, item, expected, tempStack) iferr_return;
		DebugAssert(res);

		// replace with if constexpr in C++17
		// if (std::is_same<T, Data&>::value || std::is_same<T, Data*>::value)
		return PrivateGetPtr<T>(res);
	}

	if (isOptional)
	{
		CPyErr_Clear();
		return (T)NullValueTypeHelper<const std::remove_reference_t<T>&>::Get();
	}

	CPyErr_SetString(CPyExc_TypeError(), FormatString("expected at least @ argument(s), got @", argIndex, CPyTuple_Size(args)));
	return PythonError(MAXON_SOURCE_LOCATION);
}

} // namespace py

MAXON_REGISTRY(Class<PyModuleRef>, PyModules, "net.maxon.python.registry.pymodules");


// dll pylib handler implementations behind a CPython VM
MAXON_REGISTRY(Class<LibraryRef>, CPythonLibs, "net.maxon.python.registry.cpythonlibs");
namespace CPythonLibs
{
	MAXON_DECLARATION(Class<LibraryRef>, Lib27, "net.maxon.python.cpythonlibs.cpy27");
}

#include "cpython2.hxx"

namespace py
{

//----------------------------------------------------------------------------------------
/// The CPythonGil class acquires the GIL lock upon creation and releases this upon destruction
/// (usually at the end of a code block).
/// This simplifies cases where your code contains many return statements where you'd otherwise
/// have to manually unlock the GIL before returning.
/// <B> Only use CPythonGil for a short block of your code. Do not use ScopedLock mindlessly
/// at the beginning of a function! This will block all other threads for the whole runtime
/// of the function to execute Python code, which is usually much longer than required. A few
/// Python functions unlock the GIL and lock it again before returning (e.g. several file operation
/// functions), but this is up to the function and you need to check their corresponding documentation
/// what their behavior is.</B>
///
/// THREADSAFE.
/// @see CPythonGil
//----------------------------------------------------------------------------------------
struct CPythonGil
{
	explicit CPythonGil(CPythonLibraryInterface* pylib)
	{
		_lib = pylib;
		_state = _lib->CPyGilState_Ensure();
	}
	
	explicit CPythonGil(CPythonLibraryInterface* pylib, Bool lock)
	{
		if (lock)
		{
			_lib = pylib;
			_state = _lib->CPyGilState_Ensure();
		}
	}

	~CPythonGil()
	{
		if (_lib)
		{
			_lib->CPyGilState_Release(_state);
		}
	}

	CPythonLibraryInterface* _lib = nullptr;
	PYGILSTATE _state = PYGILSTATE::UNLOCKED;
};

//-------------------------------------------------
/// Casts an object to a CPyTypeRef. Reference must be of this type, or the behavior is undefined.
/// 
/// @param[in] o 							    Object to cast.
/// @return                       Returns the object cast to CPyTypeRef.
//-------------------------------------------------
template <typename T>
typename std::enable_if<std::is_same<T, py::CPyTypeRef>::value, T>::type CPyCast(const CPyRef& o)
{
	auto* lib = o.GetLibrary();
	iferr (auto res = lib->GetCPyTypeRefClass().Create())
		return {};
	res.Init(lib, REFTYPE::BORROWED, o.Get<py::NativePyObject>());
	return res;
}


//----------------------------------------------------------------------------------------
/// Casts an object to CPyFrameRef. The object must be of the targets type.
///
/// @param[in] o									Object to cast.
/// @return												Casted object.
//----------------------------------------------------------------------------------------
template <typename T>
typename std::enable_if<std::is_same<T, py::CPyFrameRef>::value, T>::type CPyCast(const CPyRef& o)
{
	auto* lib = o.GetLibrary();
	iferr (auto res = lib->GetCPyFrameRefClass().Create())
		return {};
	res.Init(lib, REFTYPE::BORROWED, o.Get<py::NativePyObject>());
	return res;
}

//----------------------------------------------------------------------------------------
/// Casts an object to  CPyCPyTracebackRef. The object must be of the targets type.
///
/// @param[in] o									Object to cast.
/// @return												Casted object.
//----------------------------------------------------------------------------------------
template <typename T>
typename std::enable_if<std::is_same<T, py::CPyTracebackRef>::value, T>::type CPyCast(const CPyRef& o)
{
	auto* lib = o.GetLibrary();
	iferr (auto res = lib->GetCPyTracebackRefClass().Create())
		return {};
	res.Init(lib, REFTYPE::BORROWED, o.Get<py::NativePyObject>());
	return res;
}

//----------------------------------------------------------------------------------------
/// Casts an object to PyCodeRef. The object must be of the targets type.
///
/// @param[in] o									Object to cast.
/// @return												Casted object.
//----------------------------------------------------------------------------------------
template <typename T>
typename std::enable_if<std::is_same<T, py::CPyCodeRef>::value, T>::type CPyCast(const CPyRef& o)
{
	auto* lib = o.GetLibrary();
	iferr (auto res = lib->GetCPyCodeRefClass().Create())
		return {};
	res.Init(lib, REFTYPE::BORROWED, o.Get<py::NativePyObject>());
	return res;
}

//----------------------------------------------------------------------------------------
/// Casts an object to MPyClassRef. The object must be of the targets type.
///
/// @param[in] o									Object to cast.
/// @return												Casted object.
//----------------------------------------------------------------------------------------
template <typename T>
typename std::enable_if<std::is_same<T, py::MPyClassRef>::value, T>::type CPyCast(const CPyRef& o)
{
	auto* lib = o.GetLibrary();
	iferr (auto res = lib->GetMPyClassRefClass().Create())
		return {};
	res.Init(lib, REFTYPE::BORROWED, o.Get<py::NativePyObject>());
	return res;
}

//----------------------------------------------------------------------------------------
/// Casts an object to  MPyMemberRef. The object must be of the targets type.
///
/// @param[in] o									Object to cast.
/// @return												Casted object.
//----------------------------------------------------------------------------------------
template <typename T>
typename std::enable_if<std::is_same<T, py::MPyMemberRef>::value, T>::type CPyCast(const CPyRef& o)
{
	auto* lib = o.GetLibrary();
	iferr (auto res = lib->GetMPyMemberRefClass().Create())
		return {};
	res.Init(lib, REFTYPE::BORROWED, o.Get<py::NativePyObject>());
	return res;
}

//----------------------------------------------------------------------------------------
/// Casts an object to  MPMPyFunctionRef. The object must be of the targets type.
///
/// @param[in] o									Object to cast.
/// @return												Casted object.
//----------------------------------------------------------------------------------------
template <typename T>
typename std::enable_if<std::is_same<T, py::MPyFunctionRef>::value, T>::type CPyCast(const CPyRef& o)
{
	auto* lib = o.GetLibrary();
	iferr (auto res = lib->GetMPyFunctionRefClass().Create())
		return {};
	res.Init(lib, REFTYPE::BORROWED, o.Get<py::NativePyObject>());
	return res;
}

//----------------------------------------------------------------------------------------
/// Casts an object to  MPMPyDataTypeRef. The object must be of the targets type.
///
/// @param[in] o									Object to cast.
/// @return												Casted object.
//----------------------------------------------------------------------------------------
template <typename T>
typename std::enable_if<std::is_same<T, py::MPyDataTypeRef>::value, T>::type CPyCast(const CPyRef& o)
{
	auto* lib = o.GetLibrary();
	iferr (auto res = lib->GetMPyDataTypeRefClass().Create())
		return {};
	res.Init(lib, REFTYPE::BORROWED, o.Get<py::NativePyObject>());
	return res;
}

//----------------------------------------------------------------------------------------
/// Casts an object to PyDataRef. The object must be of the targets type.
///
/// @param[in] o									Object to cast.
/// @return												Casted object.
//----------------------------------------------------------------------------------------
template <typename T>
typename std::enable_if<std::is_same<T, py::MPyDataRef>::value, T>::type CPyCast(const CPyRef& o)
{
	auto* lib = o.GetLibrary();
	iferr (auto res = lib->GetMPyDataRefClass().Create())
		return {};
	res.Init(lib, REFTYPE::BORROWED, o.Get<py::NativePyObject>());
	return res;
}

//----------------------------------------------------------------------------------------
/// Casts an object to  MPyCallMPyCallerContextRef. The object must be of the targets type.
///
/// @param[in] o									Object to cast.
/// @return												Casted object.
//----------------------------------------------------------------------------------------
template <typename T>
typename std::enable_if<std::is_same<T, py::MPyCallerContextRef>::value, T>::type CPyCast(const CPyRef& o)
{
	auto* lib = o.GetLibrary();
	iferr (auto res = lib->GetMPyCallerContextRefClass().Create())
		return {};
	res.Init(lib, REFTYPE::BORROWED, o.Get<py::NativePyObject>());
	return res;
}

} // namespace py

// Private functions to extract the py::CPythonLibraryRef object from the self argument.
py::CPythonLibraryRef PrivateExtractCPythonLibrary27(py::NativePyObject* self);

// Internal functions for Python27Output
void _Python27Output(maxon::TARGETAUDIENCE audience, const Char* str, Int line, const Char* file, maxon::WRITEMETA meta = maxon::WRITEMETA::DEFAULT);
void _Python27Output(maxon::TARGETAUDIENCE audience, const maxon::String& str, Int line, const Char* file);
void _Python27Output(maxon::TARGETAUDIENCE audience, maxon::StringProxy* proxy, Int line, const Char* file);

/// Python27Output outputs text into the console under the Python 2.7 category.
/// The full @ref output syntax can be used for the format string.
/// Note that if you do not specify any additional parameters after the formatting string no formatting takes place - the raw string will stay unchanged.
/// THREADSAFE.
#define Python27Output(formatString, ...) do { FORMATTEMPLATECHECK(formatString, ##__VA_ARGS__); _Python27Output(maxon::TARGETAUDIENCE::ALL, maxon::FormatTemplateX<MAXON_VA_NARGS(__VA_ARGS__)>(formatString, ##__VA_ARGS__), __LINE__, __FILE__); } while(false)

maxon::Error PrivateRegisterCPythonFunc(const Char* name, py::NativePyCFunctionWithKeywords underlyingFunc27, BaseArray<NativePyCFunctionTable>& functions27);

void PrivateCPyRefDiagnosticOutput(MAXON_SOURCE_LOCATION_DECLARATION, const Char* refName, const py::CPyRef& ref);

} // namespace maxon


#define CPYREFDIAGNOSTICOUTPUT(ref) maxon::PrivateCPyRefDiagnosticOutput(MAXON_SOURCE_LOCATION, # ref, ref)

#define PRIVATE_MAXON_CPYTHON_FUNCTION(funcname, args) static CPyRef MAXON_CONCAT(CPythonFunction_, funcname)(const maxon::py::CPythonLibraryRef& pylib, const CPyRef& args)

#define PRIVATE_MAXON_CPYTHON_STACK() ifpyerr_scope; maxon::BlockArray<maxon::Data> tempStack

#define PRIVATE_MAXON_CPYTHON_FUNCTION_REGISTER(funcname, SUPERTYPE) static maxon::py::NativePyObject* MAXON_CONCAT(CPythonFunction27_, funcname) (maxon::py::NativePyObject* selfLib, maxon::py::NativePyObject* args, maxon::py::NativePyObject*) \
	{ \
		auto lib = PrivateExtractCPythonLibrary27(selfLib); \
		return MAXON_CONCAT(CPythonFunction_, funcname)(lib, maxon::py::CPyInterface::CreateTempRef(lib, args)).template GetAndIncref<>(); \
	} \
	maxon::Error MAXON_CONCAT(CPythonStoreResult27_, funcname) = maxon::PrivateRegisterCPythonFunc(MAXON_STRINGIFY(funcname), MAXON_CONCAT(CPythonFunction27_, funcname), SUPERTYPE _functions27);

#ifndef MAXON_COMPILER_GCC
	#define PRIVATE_MAXON_ifpyerr_scope() \
		maxon::ThreadReferencedError tmperr_0; \
		(void) tmperr_0; \
		using ErrorScopeHandler = maxon::ThreadReferencedError;
#else
	#define PRIVATE_MAXON_ifpyerr_scope() \
		maxon::ThreadReferencedError tmperr_0; \
		(void) tmperr_0; \
		using ErrorScopeHandler __attribute__((unused)) = maxon::ThreadReferencedError;
#endif

#define PRIVATE_MAXON_ifpyerr_return() \
	% tmperr_0; if (MAXON_UNLIKELY(tmperr_0.GetReferencedError() != nullptr)) { pylib.SetError(*tmperr_0.GetReferencedError()); return {}; } else do {} while(false)

#define NO_CONSTANTS \
		MAXON_METHOD Result<void> GetConstants(BaseArray<Tuple<const Char*, Int32>>& constants) \
		{ \
			return constants.CopyFrom(_intConstants); \
		}

#define PRIVATE_MAXON_COMPONENT_CPYTHON_MODULE(NO_CONSTANTS) \
	protected: \
		HashMap<const Char*, Int32> _intConstants; \
		BaseArray<NativePyCFunctionTable> _functions27; \
	public: \
		MAXON_METHOD Result<void> GetFunctions27(BaseArray<NativePyCFunctionTable>& functions)\
		{\
			return functions.CopyFrom(_functions27); \
		} \
		NO_CONSTANTS

//-------------------------------------------------
/// Required macro in the Python module scope to define if the module defines constants or not. Example:
/// @code
/// class PyExampleModule : public Component<PyExampleModule, PyModuleInterface>
/// {
///   MAXON_COMPONENT();
///   MAXON_COMPONENT_CPYTHON_MODULE(NO_CONSTANTS);
/// public:
/// 
///   MAXON_CPYTHON_FUNCTION(Foo, args)
///   {
///     MAXON_CPYTHON_STACK();
///     return pylib.CPy_None();
///   }
/// 
///   MAXON_CPYTHON_FUNCTION_REGISTER(Foo);
/// };
/// @endcode
//-------------------------------------------------
#define MAXON_COMPONENT_CPYTHON_MODULE(NO_CONSTANTS) PRIVATE_MAXON_COMPONENT_CPYTHON_MODULE(NO_CONSTANTS)

#define MAXON_PYTHON_RELEASE_GIL(pylib) auto* state = pylib.CPyEval_SaveThread(); DebugAssert(state != nullptr);
#define MAXON_PYTHON_ACQUIRE_GIL(pylib) pylib.CPyEval_RestoreThread(state);

/// Similar to iferr_scope, but used in combination with ifpyerr_return to automatically convert an exception and to set the exception indicator of Python.
#define ifpyerr_scope		 PRIVATE_MAXON_ifpyerr_scope()

//-------------------------------------------------
/// Similar to iferr_return, but used in combination with ifpyerr_scope to automatically convert an exception and to set the exception indicator of Python.
///
/// @code
/// Result<void> DoSomething();
///
/// CPyRef Convert(const CPythonLibraryRef& pylib)
/// {
///     ifpyerr_scope;
///     DoSomething() ifpyerr_return;
///     return pylib.CPy_None();
/// }
/// @endcode
//-------------------------------------------------
#define ifpyerr_return   PRIVATE_MAXON_ifpyerr_return()

//-------------------------------------------------
/// Defines a lambda in a Python C-module.
///
/// @code
/// class PyExampleModule : public Component<PyExampleModule, PyModuleInterface>
/// {
///   MAXON_COMPONENT();
///   MAXON_COMPONENT_CPYTHON_MODULE(NO_CONSTANTS);
/// public:
/// 
///   MAXON_CPYTHON_FUNCTION(Foo, args)
///   {
///     MAXON_CPYTHON_STACK();
///     return pylib.CPy_None();
///   }
/// 
///   MAXON_CPYTHON_FUNCTION_REGISTER(Foo);
/// };
/// @endcode
//-------------------------------------------------
#define MAXON_CPYTHON_FUNCTION(funcname, args) PRIVATE_MAXON_CPYTHON_FUNCTION(funcname, args)

//-------------------------------------------------
/// Makes the 'pylib' variable available and defines a stack which is used by several parsing functions to convert objects to the requested.
//-------------------------------------------------
#define MAXON_CPYTHON_STACK() PRIVATE_MAXON_CPYTHON_STACK()

//-------------------------------------------------
/// Macro to register a lambda in a Python C-module. Example:
///
/// @code
/// class PyExampleModule : public Component<PyExampleModule, PyModuleInterface>
/// {
///   MAXON_COMPONENT();
///   MAXON_COMPONENT_CPYTHON_MODULE(NO_CONSTANTS);
/// public:
/// 
///   MAXON_CPYTHON_FUNCTION(Foo, args)
///   {
///     MAXON_CPYTHON_STACK();
///     return pylib.CPy_None();
///   }
/// 
///   MAXON_CPYTHON_FUNCTION_REGISTER(Foo);
/// };
/// @endcode
//-------------------------------------------------
#define MAXON_CPYTHON_FUNCTION_REGISTER(funcname) PRIVATE_MAXON_CPYTHON_FUNCTION_REGISTER(funcname, )
#define MAXON_CPYTHON_FUNCTION_SUBTYPE_REGISTER(funcname, SUPERTYPE) PRIVATE_MAXON_CPYTHON_FUNCTION_REGISTER(funcname, SUPERTYPE::)


#endif // CPYTHON_H__
