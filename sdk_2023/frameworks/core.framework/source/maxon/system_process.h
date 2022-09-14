#ifndef SYSTEM_PROCESS_H__
#define SYSTEM_PROCESS_H__

#undef CreateProcess

#include "maxon/observerobject.h"
#include "maxon/interface.h"
#include "maxon/string.h"
#include "maxon/url.h"
#include "maxon/iostreams.h"


namespace maxon
{

class SystemProcessObjectRef;
class TimeValue;
class DllRef;

//----------------------------------------------------------------------------------------
/// @see SystemProcessInterface::StartProcess().
//----------------------------------------------------------------------------------------
enum class EXECUTEPROGRAMFLAGS
{
	NONE										= 0,
	CAPTURELOGFILE					= 1 << 1,		///< The standard output will be routed into a file.
	DONT_DELETE_LOGFILE			= 1 << 2,		///< The logfile will not be deleted at the end of the call.
	HIDE_APPLICATION				= 1 << 4,		///< Starts the application in hidden mode (e.g. suppresses the console window when running under windows).
} MAXON_ENUM_FLAGS(EXECUTEPROGRAMFLAGS);

//----------------------------------------------------------------------------------------
/// @see SystemProcessInterface::StartProcessAndWait().
//----------------------------------------------------------------------------------------
enum class EXECUTEPROGRAMCALLBACK
{
	STARTED,						///< Program started regular.

	RUNNING,						///< Program is running, this callback comes every second.
											///< return 0 to continue.
											///< return 'stop' to kill the running process.

	FINISHED,						///< Program finish.
	KILLED,							///< Program finish with signal kill.

	CLEANUP_OK,					///< Cleanup phase (succeeded case), here the logfile should be deleted!
	CLEANUP_FAILED,			///< Cleanup phase (failed case), here the logfile should be deleted!
} MAXON_ENUM_LIST(EXECUTEPROGRAMCALLBACK);

//----------------------------------------------------------------------------------------
/// Result of WaitForProcess
//----------------------------------------------------------------------------------------
enum class WAIT_PROCESS_RESULT
{
	FINISHED,						///< Process has finished.
	RUNNING							///< Process is still running.
} MAXON_ENUM_LIST(WAIT_PROCESS_RESULT);

//----------------------------------------------------------------------------------------
/// Callback for SystemProcessInterface::StartProcessAndWait return values:
/// return 0 to continue
//----------------------------------------------------------------------------------------
using ExecuteProgramCallback = Int32 (*)(SystemProcessObjectRef processRef, EXECUTEPROGRAMCALLBACK cmd, void* userdata, const Url& logfile);


//----------------------------------------------------------------------------------------
/// System Process has been killed by a signal. E.g. process crashed or killed by user.
//----------------------------------------------------------------------------------------
class SystemProcessKilledErrorInterface : MAXON_INTERFACE_BASES(ErrorInterface)
{
	MAXON_INTERFACE(SystemProcessKilledErrorInterface, MAXON_REFERENCE_COPY_ON_WRITE, "net.maxon.interface.systemprocesskillederror");
};


//----------------------------------------------------------------------------------------
/// System process operation failed.
//----------------------------------------------------------------------------------------
class SystemProcessOperationErrorInterface : MAXON_INTERFACE_BASES(ErrorInterface)
{
	MAXON_INTERFACE(SystemProcessOperationErrorInterface, MAXON_REFERENCE_COPY_ON_WRITE, "net.maxon.interface.systemprocessoperationerror");
};

//----------------------------------------------------------------------------------------
/// SystemProcessObjectInterface
//----------------------------------------------------------------------------------------
class SystemProcessObjectInterface : MAXON_INTERFACE_BASES(ObserverObjectInterface)
{
	MAXON_INTERFACE(SystemProcessObjectInterface, MAXON_REFERENCE_NORMAL, "net.maxon.interface.systemprocessobject");

public:
	//----------------------------------------------------------------------------------------
	/// Executes the prepared process. This only works once. To start the same executable again you need to allocate another instance with the same settings.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> StartProcess();

	//----------------------------------------------------------------------------------------
	/// Kills the process if it is still running. All child processes are also killed.
	/// @return												OK on success. If the process was not running SystemProcessOperationError is returned.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> KillProcess();

	//----------------------------------------------------------------------------------------
	/// Returns the exit code of the execution. This is possible as soon as the process finished.
	/// Note: The exit code under OS X only works for own child processes.
	/// Under Windows the exit code is available for all processes.
	/// @return												Returns the exit code of the process or (UInt)NOTOK if the process is still running.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Int GetExitCode() const;

	//----------------------------------------------------------------------------------------
	/// Returns whether the process is running or not.
	/// @return												True if the process is running.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Bool IsRunning() const;

	//----------------------------------------------------------------------------------------
	/// Returns the System Process Id.
	/// @return												The system process id (pid).
	//----------------------------------------------------------------------------------------
	MAXON_METHOD UInt GetProcessId() const;

	//----------------------------------------------------------------------------------------
	/// Returns the pointer to the windows process handle.
	/// @return												Windows: HANDLE of the windows process. OS X: pid of the process.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD void* GetProcessHandle() const;

	//----------------------------------------------------------------------------------------
	/// Returns the file path to the executable.
	/// Notes: Under windows the full path is only returned for processes that the user owns. System processes are only given by name.
	/// Under OS X the name is limited to the first 10 characters at the moment.
	/// @return												File name of the executable.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Url GetProcessUrl() const;

	//----------------------------------------------------------------------------------------
	/// Returns the path of the captured logfile.
	/// @return												Return the log file path. If the process was not created using EXECUTEPROGRAMFLAGS::CAPTURELOGFILE an empty name is returned.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Url GetLogFile() const;

	//----------------------------------------------------------------------------------------
	/// Returns the user data connected to this process. See SystemProcessInterface::CreateProcess().
	/// @return												Return the pointer to the user data of this process.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD void* GetUserData() const;

	//----------------------------------------------------------------------------------------
	/// Gets an array of all loaded dlls for this process.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> GetLoadedDlls(const ValueReceiver<const DllRef&>& dlls) const;

	//----------------------------------------------------------------------------------------
	/// Signal that the process finished execution. Make sure that you add this notification before you
	/// start the process, otherwise it could be too late if the process already ended.
	/// @param[in] sender							Reference to the SystemProcessObjectRef which has been finished.
	/// @return												ObservableRef to operate on.
	//----------------------------------------------------------------------------------------
	MAXON_OBSERVABLE(void, ObservableProcessFinished, (const SystemProcessObjectRef& sender), ObservableCombinerRunAllComponent);
};

//----------------------------------------------------------------------------------------
/// This interface allows to access and create system processes.
//----------------------------------------------------------------------------------------
class SystemProcessInterface
{
	MAXON_INTERFACE_NONVIRTUAL(SystemProcessInterface, MAXON_REFERENCE_NONE, "net.maxon.interface.systemprocess");

public:
	//----------------------------------------------------------------------------------------
	/// Prepares an executable to be executed as a process. If EXECUTEPROGRAMFLAGS::CAPTURELOGFILE is set all pipe parameters will be ignored.
	/// @param[in] programPath				File path to the executable. It needs to be a valid path to a URLSCHEME_FILESYSTEM path. If an stdout and stderr pipe is used CAPTURELOGFILE will be ignored.
	/// @param[in] arguments					Array of parameters to start the executable with.
	/// @param[in] flags							See EXECUTEPROGRAMFLAGS flags.
	/// @param[in] userData						User data that can be attached to this process.
	/// @param[in] stdinPipe					Pipe where stdin is redirected to.
	/// @param[in] stdoutPipe					Pipe where stdout is redirected to.
	/// @param[in] stderrPipe					Pipe where stderr is redirected to.
	/// @return												Reference object to a system process.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<SystemProcessObjectRef> CreateProcess(const Url& programPath, const ArrayInterface<String>& arguments,
		EXECUTEPROGRAMFLAGS flags, void* userData, const InOutputStreamRef& stdinPipe = InOutputStreamRef(),
		const InOutputStreamRef& stdoutPipe = InOutputStreamRef(), const InOutputStreamRef& stderrPipe = InOutputStreamRef());

	//----------------------------------------------------------------------------------------
	/// Starts and waits for a process.
	/// @param[in] programPath				File path to the executable. It needs to be a valid path to a URLSCHEME_FILESYSTEM path.
	/// @param[in] arguments					Array of parameters to start the executable with.
	/// @param[in] flags							See EXECUTEPROGRAMFLAGS flags.
	/// @param[in] callback						Pointer to a Callback function called while the executable is running. See ExecuteProgramCallback.
	/// @param[in] userData						User data that can be attached to this process.
	/// @return												Reference object to a system process. Please note that the process is already done. You can use this handle
	///																to determine the log file or the exit code.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<SystemProcessObjectRef> StartProcessAndWait(const Url& programPath, const ArrayInterface<String>& arguments,
		EXECUTEPROGRAMFLAGS flags, ExecuteProgramCallback callback, void* userData);

	//----------------------------------------------------------------------------------------
	/// Enumerates all system processes and returns a list of them.
	/// @param[out] processes					The receiver for the system processes.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<void> GetSystemProcesses(const ValueReceiver<const SystemProcessObjectRef&>& processes);

	//----------------------------------------------------------------------------------------
	/// Gets the process ID of the current running process.
	/// @return												The current process ID.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD UInt GetCurrentProcessId();

	//----------------------------------------------------------------------------------------
	/// Creates a process object for the given process ID. The returned object will have only limited capabilities. E.g. you cannot get the logfile or user data.
	/// @param[in] id									ID of the process you want to create an object for.
	/// @return												Reference object to a system process.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<SystemProcessObjectRef> GetProcess(UInt id);

	//----------------------------------------------------------------------------------------
	/// Waits for the given process to finish.
	/// @param[in] processRef					Process object to wait for.
	/// @param[in] timeout						Timeout to wait for the process to finish.
	/// @return												Returns whether the process is still running or not.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<WAIT_PROCESS_RESULT> WaitForProcess(const SystemProcessObjectRef& processRef, const TimeValue& timeout);
};


#include "system_process1.hxx"

MAXON_DECLARATION(Class<SystemProcessObjectRef>, SystemProcessObjectClass, "net.maxon.class.systemprocessobject");

#include "system_process2.hxx"

}


#endif // SYSTEM_PROCESS_H__
