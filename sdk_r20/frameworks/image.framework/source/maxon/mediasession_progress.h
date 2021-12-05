#ifndef MEDIASESSION_PROGRESS_H__
#define MEDIASESSION_PROGRESS_H__

#include "maxon/observerobject.h"
#include "maxon/timevalue.h"



namespace maxon
{

class MediaSessionProgressRef;

//----------------------------------------------------------------------------------------
/// This class simplifies the progress tracking of operations.
/// Once created a operation can simply put the current progress into the object by calling SetProgressAndCheckBreak().
/// On the other end the ObservableProgressNotification can be hooked up to get notifications (e.g. for the ui).
//----------------------------------------------------------------------------------------
class MediaSessionProgressInterface : MAXON_INTERFACE_BASES(ObserverObjectInterface)
{
	MAXON_INTERFACE(MediaSessionProgressInterface, MAXON_REFERENCE_NORMAL, "net.maxon.image.interface.mediasessionprogress");

public:
	//----------------------------------------------------------------------------------------
	/// @param[in] delayFirstProgress	Time to delay the first progress notification.
	/// @param[in] minProgressUpdate	Minimum time difference to call the progress callback.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> InitProgress(const TimeValue& delayFirstProgress, const TimeValue& minProgressUpdate);

	//----------------------------------------------------------------------------------------
	/// @param[in] jobWeight					Add the weight for this job. All the weights are summed up and is taken into account for the overall percentage.
	/// @return												Index of the job.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<Int> AddProgressJob(const Float jobWeight, const String& jobName);

	//----------------------------------------------------------------------------------------
	/// Sets the progress of the current operation.
	/// @param[in] jobIndex						Job index returned by AddProgressJob or -1 if no jobs are added
	/// @param[in] percent						Percentage between 0.0 and 1.0 of the done work.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> SetProgressAndCheckBreak(Int jobIndex, Float percent);

	//----------------------------------------------------------------------------------------
	/// Observable will be called as soon as the progress changes.
	/// @param[in] progress						Reference to this object.
	/// @param[in] percent						Percentage between 0.0 and 1.0 of the done work.
	/// @param[in] duration						Duration of the current operation.
	/// @param[in] expectedTotalTime	Expected total time of the current operation. TIMEVALUE_INFINITE will be set for infinite time.
	/// @param[in] userData						User data passed from the caller.
	//----------------------------------------------------------------------------------------
	MAXON_OBSERVABLE(void, ObservableProgressNotification,
		(const MediaSessionProgressRef& progress, Float percent, const TimeValue& duration, const TimeValue& expectedTotalTime),
		ObservableCombinerRunAllComponent);
};

#include "mediasession_progress1.hxx"

MAXON_DECLARATION(Class<MediaSessionProgressRef>, MediaSessionProgressObject, "net.maxon.image.class.mediasessionprogressobject");

#include "mediasession_progress2.hxx"

}


#endif // MEDIASESSION_PROGRESS_H__
