#ifndef CRASHHANDLER_H__
#define CRASHHANDLER_H__

#include "maxon/interface.h"
#include "maxon/basearray.h"
#include "maxon/cstdliballocator.h"
#include "maxon/observerobject.h"

#include <stdio.h>

namespace maxon
{

struct CrashReportState;

//----------------------------------------------------------------------------------------
/// Private custom crash handler.
//----------------------------------------------------------------------------------------
class CrashHandler
{
	MAXON_INTERFACE_NONVIRTUAL(CrashHandler, MAXON_REFERENCE_NONE, "net.maxon.interface.crashhandler");
public:
	using CallbackPtr = void (*)(const CrashReportState& crashState);

	//----------------------------------------------------------------------------------------
	/// Sets a callback that will be invoked when a thread has crashed. Usually the callback
	/// should dump the register and callstack information and whatever else it deems important
	/// to a file. After the callback returns the application will usually quit.
	/// @param[in] callback						Function to be invoked when a thread has crashed.
	/// @return												True if crash handler callback was set, false if crash handling is disabled.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Bool SetCallback(CallbackPtr callback);

	//----------------------------------------------------------------------------------------
	/// This callback is invoked after the primary crash callback and can be used to dump
	/// optional data, for example an OpenGL trace.
	/// @param[in] callback						Function to be invoked when a thread has crashed.
	/// @return												True if crash handler callback was set, false if crash handling is disabled.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Bool SetSecondaryCallback(CallbackPtr callback);

	//----------------------------------------------------------------------------------------
	/// Sets a directory which is used to store crash relevant data, for example OS specific
	/// dumps, log files or recovered documents.
	/// @param[in] dataDirectory			The path of a directory which will be used to store additional crash relevant data.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<void> SetCrashDataDirectory(const Url& dataDirectory);

	//----------------------------------------------------------------------------------------
	/// Displays a crash safe dialog with one button (OK).
	/// @param[in] title							Dialog title.
	/// @param[in] message						Dialog text (use \n to seperate lines).
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD void DisplayCrashDialog(const String& title, const String& message);

	//----------------------------------------------------------------------------------------
	/// Resolves the addresses in a bug report and saves a file containing symbol and file
	/// information to the same location as the bug report.
	/// The symbol archive files are expected to be stored in a three level hierarchy. On the
	/// first level the directories have the (arbitrary) name of the branch and on the second level
	/// the arbitrary name must contain the build number of each corresponding build. On the
	/// third level is a directory named "builds" which contains a zip with the symbol file archive.
	/// The symbol file archive conforms to the naming scheme buildId plus "_dsym.zip" or
	/// "_pdb64.zip", for example "MA93302_dsym.izp" or "RC79244_pdb64.zip".
	/// If symbolFileArchives is empty the value of the configuration variable g_symbolArchiveFolder
	/// is used and if temporaryDir is empty g_symbolTemporaryFolder is used.
	/// @param[in] report							The bug report file.
	/// @param[in] symbolFileArchives	The path of the symbolFileArchives.
	/// @param[in] temporaryDir				The path of a temporary directory to unpack the archives.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<void> ResolveBugReport(const Url& report, const Url& symbolFileArchives, const Url& temporaryDir);

	//----------------------------------------------------------------------------------------
	/// Invokes the observer(s) with the url of the crash data directory.
	//----------------------------------------------------------------------------------------
	MAXON_OBSERVABLE_STATIC(void, ObservableCrashDataDirectory, (const Url& dataDirectory), ObservableCombinerRunAllComponent);
};


/// Call stack entry (program counter, stack frame location and if possible symbol and module information).
struct CrashCallStackEntry
{
public:
	void* _programCounter;				// program counter
	void* _stackPointer;					// stack (frame) pointer
	const char* _symbolName;			//
	Int _symbolOffset;
	const char* _moduleName;
};

/// Register value with variable size and component count
struct GenericRegisterValue
{
	explicit GenericRegisterValue(UInt16 value)
	{
		memset(_value, 0, sizeof(_value));
		*(UInt16*) _value = value;
		_size = 2;
		_componentCnt = 1;
	}

	explicit GenericRegisterValue(UInt32 value)
	{
		memset(_value, 0, sizeof(_value));
		*(UInt32*) _value = value;
		_size = 4;
		_componentCnt = 1;
	}

	explicit GenericRegisterValue(UInt64 value)
	{
		memset(_value, 0, sizeof(_value));
		*(UInt64*) _value = value;
		_size = 8;
		_componentCnt = 1;
	}

	/// Constructs a vector register with two values of 8 bytes
	GenericRegisterValue(UInt64 valueA, UInt64 valueB)
	{
		memset(_value, 0, sizeof(_value));
		*(UInt64*) &_value[0] = valueA;
		*(UInt64*) &_value[8] = valueB;
		_size = 16;
		_componentCnt = 2;
	}

	/// Constructs a vector register with four values of 8 bytes
	GenericRegisterValue(UInt64 valueA, UInt64 valueB, UInt64 valueC, UInt64 valueD)
	{
		memset(_value, 0, sizeof(_value));
		*(UInt64*) &_value[0] = valueA;
		*(UInt64*) &_value[8] = valueB;
		*(UInt64*) &_value[16] = valueC;
		*(UInt64*) &_value[25] = valueD;
		_size = 32;
		_componentCnt = 4;
	}

	GenericRegisterValue(GenericRegisterValue&& src) : _size(src._size)
	{
		memcpy(_value, src._value, sizeof(_value));
	}

	MAXON_OPERATOR_MOVE_ASSIGNMENT(GenericRegisterValue);

	void PrintValue(FILE* file) const
	{
		switch (_size)
		{
			case 2:
			{
				fprintf(file, "%04x", (unsigned int) *(UInt16*)&_value[0]);
				break;
			}
			case 4:
			{
				fprintf(file, "%08x", *(unsigned int*) &_value[0]);
				break;
			}
			case 8:
			{
				fprintf(file, "%016llx", *(unsigned long long*) &_value[0]);
				break;
			}
			case 16:
			{
				fprintf(file, "%016llx%016llx", *(unsigned long long*) &_value[0], *(unsigned long long*) &_value[8]);
				break;
			}
			case 32:
			{
				fprintf(file, "%016llx%016llx%016llx%016llx", *(unsigned long long*) &_value[0], *(unsigned long long*) &_value[8], *(unsigned long long*) &_value[16], *(unsigned long long*) &_value[24]);
				break;
			}
			default: break;
		}
	}

	Int16 _size;
	Int16 _componentCnt;
	UChar _value[32];
};

/// Register value description (name and value).
struct CrashRegisterValue
{
	CrashRegisterValue(const char* name, UInt value) : _name(name), _value(value) {}
	CrashRegisterValue(const char* name, UInt64 valueA, UInt64 valueB) : _name(name), _value(GenericRegisterValue(valueA, valueB)) {}
	CrashRegisterValue(const char* name, UInt64 valueA, UInt64 valueB, UInt64 valueC, UInt64 valueD) : _name(name), _value(GenericRegisterValue(valueA, valueB, valueC, valueD)) {}
	CrashRegisterValue(CrashRegisterValue&& src) : MAXON_MOVE_MEMBERS(_name, _value) {}
	MAXON_OPERATOR_MOVE_ASSIGNMENT(CrashRegisterValue);

public:
	const char* _name;						// register name
	GenericRegisterValue _value;								// register value
};

/// Thread state including registers, stack backtrace and name.
struct CrashThreadState
{
	explicit CrashThreadState(const char* name = nullptr, void* osThread = nullptr) : _name(name), _osThread(osThread) {}
	CrashThreadState(CrashThreadState&& src) : MAXON_MOVE_MEMBERS(_name, _osThread, _registers, _stack) {}
	MAXON_OPERATOR_MOVE_ASSIGNMENT(CrashThreadState);

public:
	const char* _name;						// thread name
	void* _osThread;							// OS specific identifier of the crashed thread (Windows: thread id, pthread_t for everything else)
	UChar _stackDump[256];				// 128 bytes before and 128 after the current stack location
	UChar _codeDump[256];					// 128 bytes before and 128 after the current program counter
	BaseArray<CrashRegisterValue, BASEARRAY_DEFAULT_CHUNK_SIZE, BASEARRAYFLAGS::NONE, CStdLibAllocator> _registers;
	BaseArray<CrashCallStackEntry, BASEARRAY_DEFAULT_CHUNK_SIZE, BASEARRAYFLAGS::NONE, CStdLibAllocator> _stack;
};

/// Module description with file name, address and size.
struct CrashModuleEntry
{
	CrashModuleEntry(const char* fileName, void* moduleStart, Int size) : _fileName(fileName), _moduleStart(moduleStart), _size(size) {}
	CrashModuleEntry(CrashModuleEntry&& src) : _fileName(src._fileName), _moduleStart(src._moduleStart), _size(src._size) {}
	MAXON_OPERATOR_MOVE_ASSIGNMENT(CrashModuleEntry);

public:
	const char* _fileName;				// module file name
	void* _moduleStart;						// start address of the module
	Int _size;										// size of the module
};

/// Crash state consisting of exception type and a list of modules and threads.
struct CrashReportState
{
	CrashReportState() : _exceptionCode(0), _exceptionName(nullptr), _programCounter(nullptr), _osThread(nullptr), _exception(nullptr) {}

public:
	Int _exceptionCode;						// OS specific exception code
	const char* _exceptionName;		// name of the exception
	void* _programCounter;				// program counter of the crash location
	void* _osThread;							// OS specific identifier of the crashed thread (Windows: thread id, pthread_t for everything else)
	const void* _exception;				// OS specific exception data

	// Array of loaded modules.
	BaseArray<CrashModuleEntry, BASEARRAY_DEFAULT_CHUNK_SIZE, BASEARRAYFLAGS::NONE, CStdLibAllocator> _modules;

	// Array with threads. The first entry is the crashed thread.
	BaseArray<CrashThreadState, BASEARRAY_DEFAULT_CHUNK_SIZE, BASEARRAYFLAGS::NONE, CStdLibAllocator> _threads;
};


//----------------------------------------------------------------------------------------
/// Keys for the dictionary created by ResolveBugReport. Each key is stored as String and
/// the value type is specified in the comment.
///
/// The basic hierarchy is as follows (entries denoted with [] contain an array of the specified type):
/// THREADS [DataDictionary]
/// 	THREADNUMBER
/// 	PROPERTIES
/// 		THREADNAME
/// 	REGISTERS
/// 	CALLSTACK [DataDictionary]
/// 		ADDRESS
/// 		FUCTIONNAME
/// 		SOURCEFILE
/// 		LINE
/// 		MODULENAME
/// LOADEDMODULES [DataDictionary]
/// 	MODULENAME
/// 	BASEADDRES
/// DOCUMENTS [DataDictionary]
/// 	DOCUMENTNAME
/// 	DOCUMENTPATH
/// EXCEPTION
/// APPLICATIONINFO
/// COMPUTERINFO
/// CRITICALLOG [String]
//----------------------------------------------------------------------------------------
class CrashLogKey
{
public:
	static const Char* LOADEDMODULES;	// BaseArray<DataDictionary>
	static const Char* MODULENAME;	// String
	static const Char* BASEADDRESS;	// UInt64

	static const Char* THREADS;	// BaseArray<DataDictionary>

	static const Char* CALLSTACK;	// BaseArray<DataDictionary>
	static const Char* ADDRESS;		// UInt64
	static const Char* BUILD;	// String
	static const Char* FUNCTIONNAME;		// String
	static const Char* SOURCEFILE;	// String
	static const Char* LINE;		// Int

	static const Char* PROPERTIES;	// DataDictionary
	static const Char* THREADNAME;	// String
	static const Char* THREADNUMBER;	// UInt64

	static const Char* REGISTERS;	// DataDictionary

	static const Char* DOCUMENTS;	// BaseArray<DataDictionary>
	static const Char* DOCUMENTNAME;	// String
	static const Char* DOCUMENTPATH;	// String

	static const Char* COMPUTERINFO;	// DataDictionary
	static const Char* APPLICATIONINFO;	// DataDictionary
	static const Char* EXCEPTION;	// DataDictionary

	static const Char* CRITICALLOG;	// BaseArray<String>
};



// include autogenerated headerfile here
#include "crashhandler1.hxx"
// include autogenerated headerfile here
#include "crashhandler2.hxx"

} // namespace maxon

#endif // CRASHHANDLER_H__
