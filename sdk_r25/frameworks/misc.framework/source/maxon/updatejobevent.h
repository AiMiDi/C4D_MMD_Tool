#ifndef UPDATEJOBEVENT_H__
#define UPDATEJOBEVENT_H__

#include "maxon/job.h"

namespace maxon
{

//----------------------------------------------------------------------------------------
/// Update Job Event class collects and combine multiple update calls into one call until executed.
/// This is useful when adding multiple update events for the same ui element but if you only want to
/// execute one redraw update. As soon as the update job starts all subsequent request calls will trigger a new update.
/// @code
/// UpdateJobEvent _updateEvent;
/// _updateEvent.Init(
///		[]()
///		{
///			// update call
///		}, JobQueueRef::GetMainThreadQueue());
/// _updateEvent.RequestUpdate() iferr_return;
/// _updateEvent.RequestUpdate() iferr_return;
/// _updateEvent.RequestUpdate() iferr_return;
/// _updateEvent.RequestUpdate() iferr_return;
/// @endcode
/// The update will be called only once if the main thread is blocked or too slow when calling the RequestUpdate functions.
//----------------------------------------------------------------------------------------
class UpdateJobEvent
{
public:
	~UpdateJobEvent();

	//----------------------------------------------------------------------------------------
	/// Initializes the callback function and queue.
	/// @param[in] updateDelegate			Code to execute in update call.
	/// @param[in] jobQueueRef				Job queue to execute the code.
	/// @return                       OK on success.
	//----------------------------------------------------------------------------------------
	Result<void> Init(const Delegate<void()>& updateDelegate, const JobQueueRef& jobQueueRef);

	//----------------------------------------------------------------------------------------
	/// Free Structure.
	//----------------------------------------------------------------------------------------
	void Free();

	//----------------------------------------------------------------------------------------
	/// Initializes the callback function and queue.
	/// @param[in] updateDelegate			Code to execute in update call.
	/// @param[in] jobQueueRef				Job queue to execute the code.
	//----------------------------------------------------------------------------------------
	void Init(Delegate<void()>&& updateDelegate, const JobQueueRef& jobQueueRef);

	//----------------------------------------------------------------------------------------
	/// RequestUpdate enqueues a new update job into the given queue.
	/// @param[in] cancelCurrentJob		If true (the default) and there's a currently running update job,
	/// 															the function cancels the job and waits for that.
	/// 															Make sure that this doesn't introduce dead locks.
	/// @return                       OK on success.
	//----------------------------------------------------------------------------------------
	Result<void> RequestUpdate(Bool cancelCurrentJob = true);

private:
	using JobWithConfirmedCancellation = ClosureJobWithConfirmedCancellation<Delegate<void()>, JOBCANCELLATION::AUTOMATIC, void>;

	AtomicBool			 _updateRequested;
	Delegate<void()> _updateDelegate;
	JobQueueRef			 _updateJobQueueRef;
	// The UpdateJobEvent might be destructed in the main thread and when it calls CancelAndWait() this will block because the queue cannot be processed (the main thread is not in queue mode at that point).
	// Hence use a special Job with dedicated support for confirmed cancellation.
	StrongRef<JobWithConfirmedCancellation> _lastUpdateJob;
};



} // namespace maxon

#endif // UPDATEJOBEVENT_H__
