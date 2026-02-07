#ifndef UPDATEJOBEVENT_H__
#define UPDATEJOBEVENT_H__

#include "maxon/job.h"

namespace maxon
{

enum class UPDATEJOBEVENTMODE
{
	CANCEL_FOR_NEW_REQUESTS,	///< if a new request occurs after an update is running, CancelAndWait will stop the current update and a new update is triggered
	FINISH_REQUEST_AND_REPEAT,///< if a new request occurs after an update is running, The update will finish and if more requests arrived while executing the delegate another update is performed
} MAXON_ENUM_LIST(UPDATEJOBEVENTMODE);

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
	/// @parem[in] mode								see UPDATEJOBEVENTMODE.
	/// @param[in] updateDelegate			Code to execute in update call.
	/// @param[in] jobQueueRef				Job queue to execute the code.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	Result<void> Init(UPDATEJOBEVENTMODE mode, const Delegate<void()>& updateDelegate, const JobQueueRef& jobQueueRef);

	//----------------------------------------------------------------------------------------
	/// Free Structure.
	//----------------------------------------------------------------------------------------
	void Free();

	//----------------------------------------------------------------------------------------
	/// Initializes the callback function and queue.
	/// @parem[in] mode								see UPDATEJOBEVENTMODE.
	/// @param[in] updateDelegate			Code to execute in update call.
	/// @param[in] jobQueueRef				Job queue to execute the code.
	//----------------------------------------------------------------------------------------
	void Init(UPDATEJOBEVENTMODE mode, Delegate<void()>&& updateDelegate, const JobQueueRef& jobQueueRef);

	//----------------------------------------------------------------------------------------
	/// IsInitialized returns true if initialized.
	//----------------------------------------------------------------------------------------
	Bool IsInitialized() const;

	//----------------------------------------------------------------------------------------
	/// RequestUpdate enqueues a new update job into the given queue.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	Result<void> RequestUpdate();

private:
	UPDATEJOBEVENTMODE	_mode = UPDATEJOBEVENTMODE::CANCEL_FOR_NEW_REQUESTS;
	AtomicBool					_updateRequested;
	AtomicInt						_delayedRequests;
	Delegate<void()>		_updateDelegate;
	JobQueueRef					_updateJobQueueRef;
	JobRef							_lastUpdateJob;
};



} // namespace maxon

#endif // UPDATEJOBEVENT_H__
