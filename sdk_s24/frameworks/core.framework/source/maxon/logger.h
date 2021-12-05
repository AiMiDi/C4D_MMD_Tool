#ifndef LOGGER_H__
#define LOGGER_H__

#include "maxon/string.h"
#include "maxon/url.h"
#include "maxon/objectbase.h"
#include "maxon/datadictionaryobject.h"
#include "maxon/delegate.h"
#include "maxon/observable.h"
#include "maxon/observerobject.h"

namespace maxon
{

Result<void> PrivateConsoleOutput(const String& str, const SourceLocation& loc, WRITEMETA level);

/// @addtogroup SYSTEM
/// @{

//----------------------------------------------------------------------------------------
/// The logger system is an abstract way to control, where which output will be sent or written to.
/// The logger system can be seen as a small node system. A string enters the node system and is sent from
/// one node to another. The insertion points are represented by a logger entity (LoggerInterface). The nodes which
/// actively write the string (e.g. to a file or a console) are called logger types (LoggerTypeInterface).
/// Each logger can contain a various number of logger types. Each logger type belongs to one ore more logger.
/// One or more loggers can share the same logger type.
/// Only loggers are used after they are initialized. Logger types are normally not called directly unless necessary.
///
///
///         Logger           |      Logger Types
// ------------------------   -----------------------------------------
///
///                                 +-------+
///                           +---->|Process|
///      ++==========++       |     +-------+
///      || Logger 1 ||-------+
///      ++==========++       |
///                           +---->+--------+
///                                 |  File  |--+
///                             +-->+--------+  |    +--------+
///      ++==========++         |               +--->|  File  |
///      || Logger 2 ||-------+-+                      +--------+
///      ++==========++       |    +-------------+
///                           +--->| Application |--+
///                                +-------------+  |
///                                                 |  +-------+
///                                                 +->|Process|
///                                                    +-------+
//----------------------------------------------------------------------------------------


//----------------------------------------------------------------------------------------
/// Each object of LoggerLine represents an entry in the logger with several meta information. See documentation of members for more information.
//----------------------------------------------------------------------------------------
struct LoggerLine
{
	WRITEMETA _level = WRITEMETA::DEFAULT;				// Meta information of the entity
	String _str;																	// String of the line
	String _time;																	// Time of the line in a string format. Only available when g_debugLogger or LOGGERTYPEFLAGS::DEBUG are true 
	Int _threadId = 0;														// Id of the thread which wrote the string. Only available when g_debugLogger or LOGGERTYPEFLAGS::DEBUG are true 
	SourceLocation _loc;													// Source location where the string was printed.
	DataDictionary _tmpValues;										// Used to store custom data by the drawing engine to store custom values

	LoggerLine() = default;
	LoggerLine(WRITEMETA level, const String& str, const String& time, const SourceLocation& loc, Int threadId) : _level(level), _str(str), _time(time), _threadId(threadId), _loc(loc) { }
};

namespace LOGGERTYPEFLAGS
{
	MAXON_ATTRIBUTE(Bool, DEBUG, "net.maxon.core.loggertypeflags.debug");										///< True to make logger record debug information

	MAXON_ATTRIBUTE(Bool, REUSESTREAM, "net.maxon.core.loggertypeflags.reusestream");				///< True to make logger record debug information (only for FileLoggerType)
	MAXON_ATTRIBUTE(Bool, ENQUEUEWRITE, "net.maxon.core.loggertypeflags.enqueuewrite");			///< True to enqueue write operation or false to directly flush write operation disk. If false, ensure that write operations are done by only one thread at a time.
	MAXON_ATTRIBUTE(Bool, ALWAYSFLUSH, "net.maxon.core.loggertypeflags.alwaysflush");				///< Set to true to write output directly to output stream (only for FileLoggerType)
	
	MAXON_ATTRIBUTE(Int32, MAXLINEBUFFER, "net.maxon.core.loggertypeflags.maxlinebuffer");	///< Number of lines until the next file will be written (only for MultiFileLoggerType)
	MAXON_ATTRIBUTE(Int32, MAXFILEBUFFER, "net.maxon.core.loggertypeflags.maxfilebuffer");	///< Number of lines until the next file will be written (only for MultiFileLoggerType)
}

//----------------------------------------------------------------------------------------
/// Each object of LoggerLine represents an entry in the logger with several meta information. See documentation of members for more information.
//----------------------------------------------------------------------------------------
class LoggerTypeInterface : MAXON_INTERFACE_BASES(ObserverObjectInterface, DataDictionaryObjectInterface)
{
	MAXON_INTERFACE(LoggerTypeInterface, MAXON_REFERENCE_NORMAL, "net.maxon.interface.loggertype");

public:
	//----------------------------------------------------------------------------------------
	/// Implement function to consume string and write to a specified destination.
	/// @param[in] str								The string to print. Might not contain \n if level is WRITEMETA::NONEWLINE
	/// @param[in] loc								Source location where the string entered the logger system.
	/// @param[in] level							Meta flags
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> Write(const String& str, const SourceLocation& loc, WRITEMETA level = WRITEMETA::DEFAULT);

	//----------------------------------------------------------------------------------------
	/// Implement function to flush output.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> Flush();

	//----------------------------------------------------------------------------------------
	/// Add observer to get notified once logger type receives a string.
	/// @param[in] str								The string to print. Might not contain \n if level is WRITEMETA::NONEWLINE.
	/// @param[in] loc								Source location where the string entered the logger system.
	/// @param[in] ta									For which audience is the string intended.
	//----------------------------------------------------------------------------------------
	MAXON_OBSERVABLE(void, ObservableLoggerNotify, (const String& str, WRITEMETA level, TARGETAUDIENCE ta), ObservableCombinerRunAllComponent);
};

//----------------------------------------------------------------------------------------
/// Interface of a file logger type.
//----------------------------------------------------------------------------------------
class FileLoggerTypeInterface : MAXON_INTERFACE_BASES(LoggerTypeInterface)
{
	MAXON_INTERFACE(FileLoggerTypeInterface, MAXON_REFERENCE_NORMAL, "net.maxon.interface.fileloggertype");

public:

	//----------------------------------------------------------------------------------------
	/// Initialize the file logger type with a destination where it writes the output to.
	/// @param[in] url								Destination path.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> Init(const Url& url);

	//----------------------------------------------------------------------------------------
	/// Gets the path where the output is written to.
	/// @return												The destination path.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Url GetUrl() const;
};

//----------------------------------------------------------------------------------------
/// Interface of a logger type which prints to the application console. Caches all strings until it gets resetted.
//----------------------------------------------------------------------------------------
class UserLoggerTypeInterface : MAXON_INTERFACE_BASES(LoggerTypeInterface)
{
	MAXON_INTERFACE(UserLoggerTypeInterface, MAXON_REFERENCE_NORMAL, "net.maxon.interface.userloggertype");

public:
	//----------------------------------------------------------------------------------------
	/// Iterates over all caches lines since it got initialized or resetted.
	/// @param[in] callback						Delegate which is called for each line.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> Iterate(const Delegate<Result<void>(LoggerLine&)>& callback);

	//----------------------------------------------------------------------------------------
	/// Gets the count of entries.
	/// @return												Line count.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Int GetCount();

	//----------------------------------------------------------------------------------------
	/// Clears the cache of this logger type.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD void Reset();
};

class LoggerRef;
class LoggerTypeRef;

class LoggerInterface
{
	MAXON_INTERFACE_NONVIRTUAL(LoggerInterface, MAXON_REFERENCE_NORMAL, "net.maxon.interface.logger");

public:
	using LOGGERTYPEINITCALLBACK = Delegate<Result<void>(LoggerTypeRef& logger)>;

	//----------------------------------------------------------------------------------------
	/// Allocates a logger.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD LoggerInterface* Alloc(MAXON_SOURCE_LOCATION_DECLARATION);

	//----------------------------------------------------------------------------------------
	/// Adds a logger type to the logger.
	/// @param[in] ta									Set the audience. The logger type will get the string if the target audience matches when LoggerInterface::Write is used.
	/// @param[in] loggerTypeCls			Class object of logger type ref (e.g. maxon::LoggerTypes::Application())
	/// @param[in] cb									Optional callback that is executed to initialize a logger type after added to the logger. E.g. the file logger needs to be initialized with a destination path.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> AddLoggerType(TARGETAUDIENCE ta, const Class<LoggerTypeRef>& loggerTypeCls, const LOGGERTYPEINITCALLBACK& cb = DefaultLoggerTypeInit);
	
	//----------------------------------------------------------------------------------------
	/// Removes a logger type from a logger. Also succeeds if the logger type was not part of the logger.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> RemoveLoggerType(LoggerTypeRef& loggerType);

	//----------------------------------------------------------------------------------------
	/// Removes all logger types of the passed type.
	/// @param[in] loggerTypeCls			All logger types with the passed class type will be removed.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> RemoveLoggerTypes(const Class<LoggerTypeRef>& loggerTypeCls);

	//----------------------------------------------------------------------------------------
	/// Sends a string to all added logger types.
	/// @param[in] ta									All logger types which match the target audience will receive the string.
	/// @param[in] str								String to print.
	/// @param[in] loc								Source location where the string was printed from.
	/// @param[in] level							Meta information for the current write operation.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> Write(TARGETAUDIENCE ta, const String& str, const maxon::SourceLocation& loc, WRITEMETA level = WRITEMETA::DEFAULT);

	//----------------------------------------------------------------------------------------
	/// Returns the name of the logger.
	/// @return												The name.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD String GetName() const;

	//----------------------------------------------------------------------------------------
	/// Sets the name of the logger.
	/// @param[in] name								The name.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD void SetName(const String& name);

	//----------------------------------------------------------------------------------------
	/// Enable or disable the logger. If disabled, the logger still consumes strings but discards them.
	/// @param[in] enable							True or false to enable or disable the logger.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD void Enable(Bool enable);

	//----------------------------------------------------------------------------------------
	/// Returns if the logger is enabled.
	/// @return												True or false.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Bool IsEnabled();

	//----------------------------------------------------------------------------------------
	/// Returns all logger types including their audience.
	/// @return												An array of pairs with logger types and the audience.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD BaseArray<Pair<LoggerTypeRef, TARGETAUDIENCE>> GetLoggerTypes() const;

	//----------------------------------------------------------------------------------------
	/// Add observer to get notified once a new logger got added.
	/// @param[in] logger							The new logger
	//----------------------------------------------------------------------------------------
	MAXON_OBSERVABLE_STATIC(void, ObservableLoggerNew, (const LoggerRef& logger), ObservableCombinerRunAllComponent);

	//----------------------------------------------------------------------------------------
	/// Add a new logger to the system. Does the same as Loggers::Insert, but also triggers the observers
	/// @param[in] module							The module which initiates the call. When the module is freed, the logger will be freed too.
	/// @return												An array of pairs with logger types and the audience.
	//----------------------------------------------------------------------------------------
	static MAXON_ATTRIBUTE_FORCE_INLINE MAXON_METHOD Result<void> AddNewLogger(const Id& id, const LoggerRef& logger, const maxon::ModuleInfo* module = &PRIVATE_MAXON_MODULE);

private:
	static Result<void> DefaultLoggerTypeInit(LoggerTypeRef&)
	{
		return OK;
	}
};

#include "logger1.hxx"

MAXON_DECLARATION(Class<LoggerTypeRef>, LoggerTypeBaseClass, "net.maxon.class.loggertypebase");

MAXON_REGISTRY(Class<LoggerTypeRef>, LoggerTypes, "net.maxon.core.registry.loggertypes");

namespace LoggerTypes
{
	//----------------------------------------------------------------------------------------
	/// Logger type which writes output to a file in a ring buffer mode. Especially used for long-term processes
	//----------------------------------------------------------------------------------------
	MAXON_DECLARATION(Class<FileLoggerTypeRef>, MultiFile, "net.maxon.core.loggertype.multifile");

	//----------------------------------------------------------------------------------------
	/// Logger type which writes output to a file.
	//----------------------------------------------------------------------------------------
	MAXON_DECLARATION(Class<FileLoggerTypeRef>, File, "net.maxon.core.loggertype.file");

	//----------------------------------------------------------------------------------------
	/// Logger type which writes output to the built-in UI console of the host application.
	//----------------------------------------------------------------------------------------
	MAXON_DECLARATION(Class<UserLoggerTypeRef>, Application, "net.maxon.core.loggertype.applicationconsole");

	//----------------------------------------------------------------------------------------
	/// Logger type which writes output to the process console (and on Windows to the debugger console).
	//----------------------------------------------------------------------------------------
	MAXON_DECLARATION(Class<LoggerTypeRef>, Process, "net.maxon.core.loggertype.process");
}

MAXON_REGISTRY(LoggerRef, Loggers, "net.maxon.core.registry.loggers");

namespace Loggers
{
	//----------------------------------------------------------------------------------------
	/// Implementation of the default logger.
	//----------------------------------------------------------------------------------------
	MAXON_DECLARATION(LoggerRef, Default, "net.maxon.core.logger.default");

	//----------------------------------------------------------------------------------------
	/// Implementation of the process logger. Sends output to the process console (and on Windows to the debugger console).
	//----------------------------------------------------------------------------------------
	MAXON_DECLARATION(LoggerRef, Process, "net.maxon.core.logger.process");
}

#include "logger2.hxx"

/// @}

} // namespace maxon

#endif // LOGGER_H__
