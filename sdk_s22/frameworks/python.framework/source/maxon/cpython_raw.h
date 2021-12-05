#ifndef CPYTHON_RAW_H__
#define CPYTHON_RAW_H__

#include "maxon/apibase.h"
#include "maxon/url.h"
#include "maxon/blockarray.h"
#include "maxon/reflectionbase.h"
#include "maxon/dll.h"
#include "maxon/string.h"


#ifdef MAXON_TARGET_DEBUG
// For internal use only
// By default the debug version loads Python 2.7 which got compiled with VS2015.
// This is necessary so other devs don't need to install VS2008 because the debug
// redistributables are necessary. Just copying the msvcr90d.dll doesn't work because
// the internal manifest hell just got fixed with later versions. To change it to VS2008 in debug
// you have to:
// - Install VS2008
// - Update projcetdefinition.txt in the python module because it still statically links to the vs2015 version of python27.lib
// - Update pythonconfig.module (main.cpp) so it pre-loads python27.dll from python27.vs2008.framework
#define PRIVATE_MAXON_CPYTHON27_DEBUG_VS2013_ISLOADED
#endif

#if defined(MAXON_TARGET_LINUX)
	#ifdef MAXON_TARGET_64BIT
		#define LIBSDIRECTORY "linux64"
	#else
		#define LIBSDIRECTORY "linux32"
	#endif
#elif defined(_WINDOWS)
	#ifdef MAXON_TARGET_64BIT
		#define LIBSDIRECTORY "win64"
	#else
		#define LIBSDIRECTORY "win32"
	#endif
#elif defined(__APPLE__)
	#define LIBSDIRECTORY "osx"
#endif

// forward declarations of original CPython lib types
struct _object;
struct _ts;
struct _typeobject;

// forward declarations for std lib types
struct FILE_native { };

namespace maxon
{

const Int32 NATIVE_CO_MAXBLOCKS = 20; // Max static block nesting within a function

//-------------------------------------------------
// Extracts a symbol by it's name from a DLL and casts it into the requested type
// 
// @tparam F 				Declaration of the symbol to extract from the dll
// @param dll 			Dll object.
// @param symbol 		Name of the symbol in the library
// @return			 		Depending on T
//-------------------------------------------------
template <typename F>
static auto GetSymbol(const DllRef& dll, const CString& symbol)
{
	CriticalAssert(dll.GetPointer() != nullptr, "dll is not initialized");
	return dll.FindSymbol<F*>(symbol);
}

enum class Errno : int
{
	_EPERM = 1,							// Operation not permitted
	_ENOENT = 2,						// No such file or directory
	_ESRCH = 3,							// No such process
	_EINTR = 4,							// Interrupted system call
	_EIO = 5,								// I/O error
	_ENXIO = 6,							// No such device or address
	_E2BIG = 7,							// Argument list too long
	_ENOEXEC = 8,						// Exec format error
	_EBADF = 9,							// Bad file number
	_ECHILD = 10,						// No child processes
	_EAGAIN = 11,						// Try again
	_ENOMEM = 12,						// Out of memory
	_EACCES = 13,						// Permission denied
	_EFAULT = 14,						// Bad address
	_ENOTBLK = 15,					// Block device required
	_EBUSY = 16,						// Device or resource busy
	_EEXIST = 17,						// File exists
	_EXDEV = 18,						// Cross-device link
	_ENODEV = 19,						// No such device
	_ENOTDIR = 20,					// Not a directory
	_EISDIR = 21,						// Is a directory
	_EINVAL = 22,						// Invalid argument
	_ENFILE = 23,						// File table overflow
	_EMFILE = 24,						// Too many open files
	_ENOTTY = 25,						// Not a typewriter
	_ETXTBSY = 26,					// Text file busy
	_EFBIG = 27,						// File too large
	_ENOSPC = 28,						// No space left on device
	_ESPIPE = 29,						// Illegal seek
	_EROFS = 30,						// Read-only file system
	_EMLINK = 31,						// Too many links
	_EPIPE = 32,						// Broken pipe
	_EDOM = 33,							// Math argument out of domain of func
	_ERANGE = 34,						// Math result not representable
	_EDEADLK = 35,					// Resource deadlock would occur
	_ENAMETOOLONG = 36,			// File name too long
	_ENOLCK = 37,						// No record locks available
	_ENOSYS = 38,						// Function not implemented
	_ENOTEMPTY = 39,				// Directory not empty
	_ELOOP = 40,						// Too many symbolic links encountered
	_EWOULDBLOCK = _EAGAIN, // Operation would block
	_ENOMSG = 42,						// No message of desired type
	_EIDRM = 43,						// Identifier removed
	_ECHRNG = 44,						// Channel number out of range
	_EL2NSYNC = 45,					// Level 2 not synchronized
	_EL3HLT = 46,						// Level 3 halted
	_EL3RST = 47,						// Level 3 reset
	_ELNRNG = 48,						// Link number out of range
	_EUNATCH = 49,					// Protocol driver not attached
	_ENOCSI = 50,						// No CSI structure available
	_EL2HLT = 51,						// Level 2 halted
	_EBADE = 52,						// Invalid exchange
	_EBADR = 53,						// Invalid request descriptor
	_EXFULL = 54,						// Exchange full
	_ENOANO = 55,						// No anode
	_EBADRQC = 56,					// Invalid request code
	_EBADSLT = 57,					// Invalid slot

	_EDEADLOCK = _EDEADLK,

	_EBFONT = 59,					 // Bad font file format
	_ENOSTR = 60,					 // Device not a stream
	_ENODATA = 61,				 // No data available
	_ETIME = 62,					 // Timer expired
	_ENOSR = 63,					 // Out of streams resources
	_ENONET = 64,					 // Machine is not on the network
	_ENOPKG = 65,					 // Package not installed
	_EREMOTE = 66,				 // Object is remote
	_ENOLINK = 67,				 // Link has been severed
	_EADV = 68,						 // Advertise error
	_ESRMNT = 69,					 // Srmount error
	_ECOMM = 70,					 // Communication error on send
	_EPROTO = 71,					 // Protocol error
	_EMULTIHOP = 72,			 // Multihop attempted
	_EDOTDOT = 73,				 // RFS specific error
	_EBADMSG = 74,				 // Not a data message
	_EOVERFLOW = 75,			 // Value too large for defined data type
	_ENOTUNIQ = 76,				 // Name not unique on network
	_EBADFD = 77,					 // File descriptor in bad state
	_EREMCHG = 78,				 // Remote address changed
	_ELIBACC = 79,				 // Can not access a needed shared library
	_ELIBBAD = 80,				 // Accessing a corrupted shared library
	_ELIBSCN = 81,				 // .lib section in a.out corrupted
	_ELIBMAX = 82,				 // Attempting to link in too many shared libraries
	_ELIBEXEC = 83,				 // Cannot exec a shared library directly
	_EILSEQ = 84,					 // Illegal byte sequence
	_ERESTART = 85,				 // Interrupted system call should be restarted
	_ESTRPIPE = 86,				 // Streams pipe error
	_EUSERS = 87,					 // Too many users
	_ENOTSOCK = 88,				 // Socket operation on non-socket
	_EDESTADDRREQ = 89,		 // Destination address required
	_EMSGSIZE = 90,				 // Message too long
	_EPROTOTYPE = 91,			 // Protocol wrong type for socket
	_ENOPROTOOPT = 92,		 // Protocol not available
	_EPROTONOSUPPORT = 93, // Protocol not supported
	_ESOCKTNOSUPPORT = 94, // Socket type not supported
	_EOPNOTSUPP = 95,			 // Operation not supported on transport endpoint
	_EPFNOSUPPORT = 96,		 // Protocol family not supported
	_EAFNOSUPPORT = 97,		 // Address family not supported by protocol
	_EADDRINUSE = 98,			 // Address already in use
	_EADDRNOTAVAIL = 99,	 // Cannot assign requested address
	_ENETDOWN = 100,			 // Network is down
	_ENETUNREACH = 101,		 // Network is unreachable
	_ENETRESET = 102,			 // Network dropped connection because of reset
	_ECONNABORTED = 103,	 // Software caused connection abort
	_ECONNRESET = 104,		 // Connection reset by peer
	_ENOBUFS = 105,				 // No buffer space available
	_EISCONN = 106,				 // Transport endpoint is already connected
	_ENOTCONN = 107,			 // Transport endpoint is not connected
	_ESHUTDOWN = 108,			 // Cannot send after transport endpoint shutdown
	_ETOOMANYREFS = 109,	 // Too many references: cannot splice
	_ETIMEDOUT = 110,			 // Connection timed out
	_ECONNREFUSED = 111,	 // Connection refused
	_EHOSTDOWN = 112,			 // Host is down
	_EHOSTUNREACH = 113,	 // No route to host
	_EALREADY = 114,			 // Operation already in progress
	_EINPROGRESS = 115,		 // Operation now in progress
	_ESTALE = 116,				 // Stale NFS file handle
	_EUCLEAN = 117,				 // Structure needs cleaning
	_ENOTNAM = 118,				 // Not a XENIX named type file
	_ENAVAIL = 119,				 // No XENIX semaphores available
	_EISNAM = 120,				 // Is a named type file
	_EREMOTEIO = 121,			 // Remote I/O error
	_EDQUOT = 122,				 // Quota exceeded

	_ENOMEDIUM = 123,			// No medium found
	_EMEDIUMTYPE = 124,		// Wrong medium type
	_ECANCELED = 125,			// Operation Canceled
	_ENOKEY = 126,				// Required key not available
	_EKEYEXPIRED = 127,		// Key has expired
	_EKEYREVOKED = 128,		// Key has been revoked
	_EKEYREJECTED = 129,	// Key was rejected by service

	// for robust mutexes
	_EOWNERDEAD = 130,			// Owner died
	_ENOTRECOVERABLE = 131, // State not recoverable
} MAXON_ENUM_LIST(Errno);

//-------------------------------------------------
// Enum for Python comparisions. Values match the 
// comparision operations of Python.
//-------------------------------------------------
enum class CONTAINS : int
{
	_FOUND = 1,
	_NOTFOUND = 0,
	_ERROR = -1
} MAXON_ENUM_LIST(CONTAINS);

using PyChar = Char;

namespace py
{

class TpFlags
{
	Int64 _reserved = 0;
};

struct CPyCompilerFlags
{
	int cf_flags = 0; // bitmask of CO_xxx flags relevant to future 
};

enum class PYTHONFLAG
{
	NONE = 1 << 0,
	DEBUG = 1 << 1,
	VERBOSE = 1 << 2,
	INTERACTIVE = 1 << 3,
	INSPECT = 1 << 4,
	OPTIMIZE = 1 << 5,
	NOSITE = 1 << 6,
	BYTESWARNING = 1 << 7,
	USECLASSEXCEPTIONS = 1 << 8,
	FROZEN = 1 << 9,
	TABCHECK = 1 << 10,
	UNICODE_ = 1 << 11,
	IGNOREENVIRONMENT = 1 << 12,
	DIVISIONWARNING = 1 << 13,
	DONTWRITEBYTECODE = 1 << 14,
	NOUSERSITEDIRECTORY = 1 << 15,
	QNEW = 1 << 16,
	PY3KWARNING = 1 << 17,

	// --
	SET_CONTEXT_COMMANDLINEARGS = 1 << 28,
	SET_ALL_COMMANDLINEARGS = 1 << 29,
	PROCESS_COMMANDLINEARGS = 1 << 30,
	ERRORS_IN_RESULT = 1 << 31
} MAXON_ENUM_FLAGS(PYTHONFLAG);

struct NativePyThreadState { };

//-------------------------------------------------
// This is the base type of all objects in Python. Can be safely cast to PyObject.
//-------------------------------------------------
struct NativePyObject
{
	//-------------------------------------------------
	// Cast operation to _object type
	//-------------------------------------------------
	_object * Get()
	{
		return reinterpret_cast<_object*>(this);
	}

	//-------------------------------------------------
	// Cast operation to _object type
	//-------------------------------------------------
	const _object* Get() const
	{
		return reinterpret_cast<const _object*>(this);
	}
};

struct NativePyTypeObject : public NativePyObject { };
struct NativePyIntObject : public NativePyObject { };
struct NativePyCapsule : public NativePyObject { };

using destruct = void(NativePyObject*);
using reprfunc = NativePyObject * (NativePyObject*);
using newfunc = NativePyObject * (NativePyTypeObject* type, NativePyObject* args, NativePyObject* kwds);
using allocfunc = NativePyObject * (NativePyTypeObject* type, Int nitems);

using NativePyCFunctionWithKeywords = NativePyObject * (*)(NativePyObject*, NativePyObject*, NativePyObject*);

//-------------------------------------------------
// Structure used to describe a method of an extension type.
//-------------------------------------------------
struct NativePyMethodDef
{
	const Char*												ml_name = nullptr;  // The name of the built-in function/method
	NativePyCFunctionWithKeywords			ml_meth = nullptr;	// The function that implements it
	Int32															ml_flags = 0;				// flag bits indicating how the call should be constructed
	const Char*												ml_doc = nullptr;		// The __doc__ attribute, or nullptr

	NativePyMethodDef() = default;
	NativePyMethodDef(const Char* name, NativePyCFunctionWithKeywords meth, Int32 flags, const Char* doc) : ml_name(name), ml_meth(meth), ml_flags(flags), ml_doc(doc) { }
};

struct NativePyModuleDefBase : public NativePyObject
{
};

struct NativePyModuleDef : public NativePyModuleDefBase
{
};

} // namespace py

} // namespace maxon

#endif // CPYTHON_RAW_H__
