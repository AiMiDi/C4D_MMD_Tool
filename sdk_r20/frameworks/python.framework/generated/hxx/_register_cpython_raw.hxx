#if 1
#ifdef MAXON_TARGET_DEBUG
#endif
#if defined(MAXON_TARGET_LINUX)
#ifdef MAXON_TARGET_64BIT
#else
#endif
#elif defined(_WINDOWS)
#ifdef MAXON_TARGET_64BIT
#else
#endif
#elif defined(__APPLE__)
#endif
namespace maxon
{
	namespace enum207 { enum class Errno : int
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
	} ; }
	maxon::String PrivateToString_Errno207(std::underlying_type<enum207::Errno>::type x, const maxon::FormatStatement* fmt)
	{
		const maxon::UInt64 values[] = {(maxon::UInt64) enum207::Errno::_EPERM, (maxon::UInt64) enum207::Errno::_ENOENT, (maxon::UInt64) enum207::Errno::_ESRCH, (maxon::UInt64) enum207::Errno::_EINTR, (maxon::UInt64) enum207::Errno::_EIO, (maxon::UInt64) enum207::Errno::_ENXIO, (maxon::UInt64) enum207::Errno::_E2BIG, (maxon::UInt64) enum207::Errno::_ENOEXEC, (maxon::UInt64) enum207::Errno::_EBADF, (maxon::UInt64) enum207::Errno::_ECHILD, (maxon::UInt64) enum207::Errno::_EAGAIN, (maxon::UInt64) enum207::Errno::_ENOMEM, (maxon::UInt64) enum207::Errno::_EACCES, (maxon::UInt64) enum207::Errno::_EFAULT, (maxon::UInt64) enum207::Errno::_ENOTBLK, (maxon::UInt64) enum207::Errno::_EBUSY, (maxon::UInt64) enum207::Errno::_EEXIST, (maxon::UInt64) enum207::Errno::_EXDEV, (maxon::UInt64) enum207::Errno::_ENODEV, (maxon::UInt64) enum207::Errno::_ENOTDIR, (maxon::UInt64) enum207::Errno::_EISDIR, (maxon::UInt64) enum207::Errno::_EINVAL, (maxon::UInt64) enum207::Errno::_ENFILE, (maxon::UInt64) enum207::Errno::_EMFILE, (maxon::UInt64) enum207::Errno::_ENOTTY, (maxon::UInt64) enum207::Errno::_ETXTBSY, (maxon::UInt64) enum207::Errno::_EFBIG, (maxon::UInt64) enum207::Errno::_ENOSPC, (maxon::UInt64) enum207::Errno::_ESPIPE, (maxon::UInt64) enum207::Errno::_EROFS, (maxon::UInt64) enum207::Errno::_EMLINK, (maxon::UInt64) enum207::Errno::_EPIPE, (maxon::UInt64) enum207::Errno::_EDOM, (maxon::UInt64) enum207::Errno::_ERANGE, (maxon::UInt64) enum207::Errno::_EDEADLK, (maxon::UInt64) enum207::Errno::_ENAMETOOLONG, (maxon::UInt64) enum207::Errno::_ENOLCK, (maxon::UInt64) enum207::Errno::_ENOSYS, (maxon::UInt64) enum207::Errno::_ENOTEMPTY, (maxon::UInt64) enum207::Errno::_ELOOP, (maxon::UInt64) enum207::Errno::_EWOULDBLOCK, (maxon::UInt64) enum207::Errno::_ENOMSG, (maxon::UInt64) enum207::Errno::_EIDRM, (maxon::UInt64) enum207::Errno::_ECHRNG, (maxon::UInt64) enum207::Errno::_EL2NSYNC, (maxon::UInt64) enum207::Errno::_EL3HLT, (maxon::UInt64) enum207::Errno::_EL3RST, (maxon::UInt64) enum207::Errno::_ELNRNG, (maxon::UInt64) enum207::Errno::_EUNATCH, (maxon::UInt64) enum207::Errno::_ENOCSI, (maxon::UInt64) enum207::Errno::_EL2HLT, (maxon::UInt64) enum207::Errno::_EBADE, (maxon::UInt64) enum207::Errno::_EBADR, (maxon::UInt64) enum207::Errno::_EXFULL, (maxon::UInt64) enum207::Errno::_ENOANO, (maxon::UInt64) enum207::Errno::_EBADRQC, (maxon::UInt64) enum207::Errno::_EBADSLT, (maxon::UInt64) enum207::Errno::_EDEADLOCK, (maxon::UInt64) enum207::Errno::_EBFONT, (maxon::UInt64) enum207::Errno::_ENOSTR, (maxon::UInt64) enum207::Errno::_ENODATA, (maxon::UInt64) enum207::Errno::_ETIME, (maxon::UInt64) enum207::Errno::_ENOSR, (maxon::UInt64) enum207::Errno::_ENONET, (maxon::UInt64) enum207::Errno::_ENOPKG, (maxon::UInt64) enum207::Errno::_EREMOTE, (maxon::UInt64) enum207::Errno::_ENOLINK, (maxon::UInt64) enum207::Errno::_EADV, (maxon::UInt64) enum207::Errno::_ESRMNT, (maxon::UInt64) enum207::Errno::_ECOMM, (maxon::UInt64) enum207::Errno::_EPROTO, (maxon::UInt64) enum207::Errno::_EMULTIHOP, (maxon::UInt64) enum207::Errno::_EDOTDOT, (maxon::UInt64) enum207::Errno::_EBADMSG, (maxon::UInt64) enum207::Errno::_EOVERFLOW, (maxon::UInt64) enum207::Errno::_ENOTUNIQ, (maxon::UInt64) enum207::Errno::_EBADFD, (maxon::UInt64) enum207::Errno::_EREMCHG, (maxon::UInt64) enum207::Errno::_ELIBACC, (maxon::UInt64) enum207::Errno::_ELIBBAD, (maxon::UInt64) enum207::Errno::_ELIBSCN, (maxon::UInt64) enum207::Errno::_ELIBMAX, (maxon::UInt64) enum207::Errno::_ELIBEXEC, (maxon::UInt64) enum207::Errno::_EILSEQ, (maxon::UInt64) enum207::Errno::_ERESTART, (maxon::UInt64) enum207::Errno::_ESTRPIPE, (maxon::UInt64) enum207::Errno::_EUSERS, (maxon::UInt64) enum207::Errno::_ENOTSOCK, (maxon::UInt64) enum207::Errno::_EDESTADDRREQ, (maxon::UInt64) enum207::Errno::_EMSGSIZE, (maxon::UInt64) enum207::Errno::_EPROTOTYPE, (maxon::UInt64) enum207::Errno::_ENOPROTOOPT, (maxon::UInt64) enum207::Errno::_EPROTONOSUPPORT, (maxon::UInt64) enum207::Errno::_ESOCKTNOSUPPORT, (maxon::UInt64) enum207::Errno::_EOPNOTSUPP, (maxon::UInt64) enum207::Errno::_EPFNOSUPPORT, (maxon::UInt64) enum207::Errno::_EAFNOSUPPORT, (maxon::UInt64) enum207::Errno::_EADDRINUSE, (maxon::UInt64) enum207::Errno::_EADDRNOTAVAIL, (maxon::UInt64) enum207::Errno::_ENETDOWN, (maxon::UInt64) enum207::Errno::_ENETUNREACH, (maxon::UInt64) enum207::Errno::_ENETRESET, (maxon::UInt64) enum207::Errno::_ECONNABORTED, (maxon::UInt64) enum207::Errno::_ECONNRESET, (maxon::UInt64) enum207::Errno::_ENOBUFS, (maxon::UInt64) enum207::Errno::_EISCONN, (maxon::UInt64) enum207::Errno::_ENOTCONN, (maxon::UInt64) enum207::Errno::_ESHUTDOWN, (maxon::UInt64) enum207::Errno::_ETOOMANYREFS, (maxon::UInt64) enum207::Errno::_ETIMEDOUT, (maxon::UInt64) enum207::Errno::_ECONNREFUSED, (maxon::UInt64) enum207::Errno::_EHOSTDOWN, (maxon::UInt64) enum207::Errno::_EHOSTUNREACH, (maxon::UInt64) enum207::Errno::_EALREADY, (maxon::UInt64) enum207::Errno::_EINPROGRESS, (maxon::UInt64) enum207::Errno::_ESTALE, (maxon::UInt64) enum207::Errno::_EUCLEAN, (maxon::UInt64) enum207::Errno::_ENOTNAM, (maxon::UInt64) enum207::Errno::_ENAVAIL, (maxon::UInt64) enum207::Errno::_EISNAM, (maxon::UInt64) enum207::Errno::_EREMOTEIO, (maxon::UInt64) enum207::Errno::_EDQUOT, (maxon::UInt64) enum207::Errno::_ENOMEDIUM, (maxon::UInt64) enum207::Errno::_EMEDIUMTYPE, (maxon::UInt64) enum207::Errno::_ECANCELED, (maxon::UInt64) enum207::Errno::_ENOKEY, (maxon::UInt64) enum207::Errno::_EKEYEXPIRED, (maxon::UInt64) enum207::Errno::_EKEYREVOKED, (maxon::UInt64) enum207::Errno::_EKEYREJECTED, (maxon::UInt64) enum207::Errno::_EOWNERDEAD, (maxon::UInt64) enum207::Errno::_ENOTRECOVERABLE};
		return maxon::StringInterface::PrivateEnumToString((maxon::UInt64) x, "Errno", SIZEOF(x), false, values, "_EPERM\0_ENOENT\0_ESRCH\0_EINTR\0_EIO\0_ENXIO\0_E2BIG\0_ENOEXEC\0_EBADF\0_ECHILD\0_EAGAIN\0_ENOMEM\0_EACCES\0_EFAULT\0_ENOTBLK\0_EBUSY\0_EEXIST\0_EXDEV\0_ENODEV\0_ENOTDIR\0_EISDIR\0_EINVAL\0_ENFILE\0_EMFILE\0_ENOTTY\0_ETXTBSY\0_EFBIG\0_ENOSPC\0_ESPIPE\0_EROFS\0_EMLINK\0_EPIPE\0_EDOM\0_ERANGE\0_EDEADLK\0_ENAMETOOLONG\0_ENOLCK\0_ENOSYS\0_ENOTEMPTY\0_ELOOP\0_EWOULDBLOCK\0_ENOMSG\0_EIDRM\0_ECHRNG\0_EL2NSYNC\0_EL3HLT\0_EL3RST\0_ELNRNG\0_EUNATCH\0_ENOCSI\0_EL2HLT\0_EBADE\0_EBADR\0_EXFULL\0_ENOANO\0_EBADRQC\0_EBADSLT\0_EDEADLOCK\0_EBFONT\0_ENOSTR\0_ENODATA\0_ETIME\0_ENOSR\0_ENONET\0_ENOPKG\0_EREMOTE\0_ENOLINK\0_EADV\0_ESRMNT\0_ECOMM\0_EPROTO\0_EMULTIHOP\0_EDOTDOT\0_EBADMSG\0_EOVERFLOW\0_ENOTUNIQ\0_EBADFD\0_EREMCHG\0_ELIBACC\0_ELIBBAD\0_ELIBSCN\0_ELIBMAX\0_ELIBEXEC\0_EILSEQ\0_ERESTART\0_ESTRPIPE\0_EUSERS\0_ENOTSOCK\0_EDESTADDRREQ\0_EMSGSIZE\0_EPROTOTYPE\0_ENOPROTOOPT\0_EPROTONOSUPPORT\0_ESOCKTNOSUPPORT\0_EOPNOTSUPP\0_EPFNOSUPPORT\0_EAFNOSUPPORT\0_EADDRINUSE\0_EADDRNOTAVAIL\0_ENETDOWN\0_ENETUNREACH\0_ENETRESET\0_ECONNABORTED\0_ECONNRESET\0_ENOBUFS\0_EISCONN\0_ENOTCONN\0_ESHUTDOWN\0_ETOOMANYREFS\0_ETIMEDOUT\0_ECONNREFUSED\0_EHOSTDOWN\0_EHOSTUNREACH\0_EALREADY\0_EINPROGRESS\0_ESTALE\0_EUCLEAN\0_ENOTNAM\0_ENAVAIL\0_EISNAM\0_EREMOTEIO\0_EDQUOT\0_ENOMEDIUM\0_EMEDIUMTYPE\0_ECANCELED\0_ENOKEY\0_EKEYEXPIRED\0_EKEYREVOKED\0_EKEYREJECTED\0_EOWNERDEAD\0_ENOTRECOVERABLE\0", fmt);
	}
	namespace enum218 { enum class CONTAINS : int
	{
		_FOUND = 1,
		_NOTFOUND = 0,
		_ERROR = -1
	} ; }
	maxon::String PrivateToString_CONTAINS218(std::underlying_type<enum218::CONTAINS>::type x, const maxon::FormatStatement* fmt)
	{
		const maxon::UInt64 values[] = {(maxon::UInt64) enum218::CONTAINS::_FOUND, (maxon::UInt64) enum218::CONTAINS::_NOTFOUND, (maxon::UInt64) enum218::CONTAINS::_ERROR};
		return maxon::StringInterface::PrivateEnumToString((maxon::UInt64) x, "CONTAINS", SIZEOF(x), false, values, "_FOUND\0_NOTFOUND\0_ERROR\0", fmt);
	}
	namespace py
	{
		namespace enum261 { enum class PYTHONFLAG
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
		} ; }
		maxon::String PrivateToString_PYTHONFLAG261(std::underlying_type<enum261::PYTHONFLAG>::type x, const maxon::FormatStatement* fmt)
		{
			const maxon::UInt64 values[] = {(maxon::UInt64) enum261::PYTHONFLAG::NONE, (maxon::UInt64) enum261::PYTHONFLAG::DEBUG, (maxon::UInt64) enum261::PYTHONFLAG::VERBOSE, (maxon::UInt64) enum261::PYTHONFLAG::INTERACTIVE, (maxon::UInt64) enum261::PYTHONFLAG::INSPECT, (maxon::UInt64) enum261::PYTHONFLAG::OPTIMIZE, (maxon::UInt64) enum261::PYTHONFLAG::NOSITE, (maxon::UInt64) enum261::PYTHONFLAG::BYTESWARNING, (maxon::UInt64) enum261::PYTHONFLAG::USECLASSEXCEPTIONS, (maxon::UInt64) enum261::PYTHONFLAG::FROZEN, (maxon::UInt64) enum261::PYTHONFLAG::TABCHECK, (maxon::UInt64) enum261::PYTHONFLAG::UNICODE_, (maxon::UInt64) enum261::PYTHONFLAG::IGNOREENVIRONMENT, (maxon::UInt64) enum261::PYTHONFLAG::DIVISIONWARNING, (maxon::UInt64) enum261::PYTHONFLAG::DONTWRITEBYTECODE, (maxon::UInt64) enum261::PYTHONFLAG::NOUSERSITEDIRECTORY, (maxon::UInt64) enum261::PYTHONFLAG::QNEW, (maxon::UInt64) enum261::PYTHONFLAG::PY3KWARNING, (maxon::UInt64) enum261::PYTHONFLAG::SET_CONTEXT_COMMANDLINEARGS, (maxon::UInt64) enum261::PYTHONFLAG::SET_ALL_COMMANDLINEARGS, (maxon::UInt64) enum261::PYTHONFLAG::PROCESS_COMMANDLINEARGS, (maxon::UInt64) enum261::PYTHONFLAG::ERRORS_IN_RESULT};
			return maxon::StringInterface::PrivateEnumToString((maxon::UInt64) x, "PYTHONFLAG", SIZEOF(x), true, values, "NONE\0DEBUG\0VERBOSE\0INTERACTIVE\0INSPECT\0OPTIMIZE\0NOSITE\0BYTESWARNING\0USECLASSEXCEPTIONS\0FROZEN\0TABCHECK\0UNICODE_\0IGNOREENVIRONMENT\0DIVISIONWARNING\0DONTWRITEBYTECODE\0NOUSERSITEDIRECTORY\0QNEW\0PY3KWARNING\0SET_CONTEXT_COMMANDLINEARGS\0SET_ALL_COMMANDLINEARGS\0PROCESS_COMMANDLINEARGS\0ERRORS_IN_RESULT\0", fmt);
		}
	}
}
#endif
