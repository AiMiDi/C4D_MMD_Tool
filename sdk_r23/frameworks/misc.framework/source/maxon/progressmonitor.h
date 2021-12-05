#ifndef PROGRESSMONITOR_H__
#define PROGRESSMONITOR_H__

#include "maxon/apibase.h"
#include "maxon/object.h"
#include "maxon/array.h"

namespace maxon
{

//----------------------------------------------------------------------------------------
/// Allows to be informed during time-intensive source control operations such as
/// file sync. The monitor is called frequently during the operation.
//----------------------------------------------------------------------------------------
class ProgressMonitorInterface : MAXON_INTERFACE_BASES(ObjectInterface)
{
	MAXON_INTERFACE(ProgressMonitorInterface, MAXON_REFERENCE_NORMAL, "net.maxon.misc.interface.progressmonitor");

public:

	//----------------------------------------------------------------------------------------
	/// Called before the source control operation.
	/// @param[in] command						The command string of the operation.
	/// @param[in] arguments					The set of arguments used with the command.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> Initialize(const String& command, const ArrayInterface<String>& arguments);

	//----------------------------------------------------------------------------------------
	/// Called once for the command. Note that this function might not be executed at all, or is executed
	/// after the operation is already progressing, such as a a download being partially complete, which
	/// is indicated by a call to FinishedBytesToProcess() before calling TotalBytesToProcess().
	/// @param[in] bytes							The total number of bytes for the operation.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> TotalBytesToProcess(UInt bytes);

	//----------------------------------------------------------------------------------------
	/// Called frequently, multiple times during the operation. Note that this function might not be executed at all.
	/// The sum of all reported finished bytes equals the total amount of bytes for a successful operation.
	/// @param[in] bytes							The number of progress in bytes since the last call to TotalBytesToProcess().
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> FinishedBytesToProcess(UInt bytes);

	//----------------------------------------------------------------------------------------
	/// This method is called after the source control operation terminated successfully.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> Finalize();
};

#include "progressmonitor1.hxx"
#include "progressmonitor2.hxx"

} // namespace maxon

#endif // PROGRESSMONITOR_H__
