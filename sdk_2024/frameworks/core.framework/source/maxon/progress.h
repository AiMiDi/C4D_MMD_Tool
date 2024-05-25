#ifndef PROGRESS_H__
#define PROGRESS_H__

#include "maxon/observerobject.h"
#include "maxon/timevalue.h"



namespace maxon
{

class ProgressRef;

/// Delegate used in the ProgressInterface to react on the request to cancel the job.
using JobCancelDelegate = Delegate<Result<void>(const ProgressRef& progressRef)>;

/// predefined value if the progress has an unknown time (in that case the progress shows a spinning status).
static const Float UNKNOWNPROGRESS = MAXVALUE_FLOAT64;

//----------------------------------------------------------------------------------------
/// This class simplifies the progress tracking of operations.
/// Once created a operation can simply put the current progress into the object by calling SetProgressAndCheckBreak().
/// On the other end the ObservableProgressNotification can be hooked up to get notifications (e.g. for the ui).
/// The implementation can handle 2 modes.
/// 1.) simple mode: without calling AddProgressJob() there is one default job available with a weight of 1.0. you can use this mode to call all functions with idx == 0 to set or get the progress.
/// 2.) multi mode: after calling AddProgressJob() the first time you need to provide the idx for the job you want to set or get. the implementation calculates the total progress depending on the weights of the individual sub jobs.
//----------------------------------------------------------------------------------------
class ProgressInterface : MAXON_INTERFACE_BASES(ObserverObjectInterface)
{
	MAXON_INTERFACE(ProgressInterface, MAXON_REFERENCE_NORMAL, "net.maxon.interface.progress");

public:
	//----------------------------------------------------------------------------------------
	/// @param[in] delayFirstProgress	Time to delay the first progress notification.
	/// @param[in] minProgressUpdate	Minimum time difference to call the progress callback.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> InitProgress(const TimeValue& delayFirstProgress, const TimeValue& minProgressUpdate);

	//----------------------------------------------------------------------------------------
	/// The first call of AddProgressJob() switches from simple mode to multi job mode.
	/// @param[in] jobWeight					Add the weight for this job. All the weights are summed up and is taken into account for the overall percentage.
	/// @return												Index of the newly created job.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<Int> AddProgressJob(Float jobWeight, const String& jobName);

	//----------------------------------------------------------------------------------------
	/// Sets the progress of the current operation.
	/// @param[in] jobIndex						Job index returned by AddProgressJob() or 0 when running in simple mode.
	/// @param[in] percent						Percentage between 0.0 and 1.0 of the done work. use UNKNOWNPROGRESS to set spinning mode
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> SetProgressAndCheckBreak(Int jobIndex, Float percent);

	//----------------------------------------------------------------------------------------
	/// Returns the progress of the current operation.
	/// @param[in] jobIndex						Job index returned by AddProgressJob or 0 when running in simple mode or -1 to get the total progress.
	/// @return												Progress between 0 and 1 or UNKNOWNPROGRESS for unknown duration (ui should show a spinner in that case.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<Float> GetProgress(Int jobIndex);

	//----------------------------------------------------------------------------------------
	/// GetTotalWeight returns the total weight of all jobs.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Float GetTotalWeight() const;
	//----------------------------------------------------------------------------------------
	/// Observable will be called as soon as the progress changes.
	/// @param[in] progress						Reference to this object.
	/// @param[in] percent						Percentage between 0.0 and 1.0 of the done work.
	/// @param[in] duration						Duration of the current operation.
	/// @param[in] expectedTotalTime	Expected total time of the current operation. TIMEVALUE_INFINITE will be set for infinite time.
	/// @param[in] userData						User data passed from the caller.
	//----------------------------------------------------------------------------------------
	MAXON_OBSERVABLE(void, ObservableProgressNotification, (const ProgressRef& progress, Float percent, const TimeValue& duration, const TimeValue& expectedTotalTime), ObservableCombinerRunAllComponent);

	//====================== 
	// new in R26. put at the end to keep interface compatibility.
	//====================== 

	//----------------------------------------------------------------------------------------
	/// GetTime returns a tuple with the "running time" and "expected total time" of the progress.
	/// Expected time might be TIMEVALUE_INFINITE if the time is unknown.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<Tuple<TimeValue, TimeValue>> GetTime() const;

	//----------------------------------------------------------------------------------------
	/// Returns the details of the progress.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD String GetDetailsText() const;

	//----------------------------------------------------------------------------------------
	/// Sets the details of the progress.
	/// @param[in] details						New details to be set.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD void SetDetailsText(const String& details);

	//----------------------------------------------------------------------------------------
	/// SupportsCancelJob returns true if the progress object supports job cancellation.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Bool SupportsCancelJob() const;

	//----------------------------------------------------------------------------------------
	/// SetCancelJobDelegate allows to set a job cancellation delegate.
	/// @param[in] cancelJobDelegate	Delegate which is called to cancel the job
	/// @return                       OK on success.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> SetCancelJobDelegate(JobCancelDelegate&& cancelJobDelegate);

	//----------------------------------------------------------------------------------------
	/// CancelJob cancels the job by calling the job cancel delegate (see SetCancelJobDelegate).
	/// @return                       OK on success.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> CancelJob();

	//----------------------------------------------------------------------------------------
	/// IsCancelled returns true if the job is cancelled.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Bool IsCancelled();
};

#include "progress1.hxx"

MAXON_DECLARATION(Class<ProgressRef>, ProgressObject, "net.maxon.image.class.mediasessionprogressobject");

#include "progress2.hxx"

}


#endif // PROGRESS_H__
