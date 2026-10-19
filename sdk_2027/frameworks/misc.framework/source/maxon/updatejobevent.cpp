#include "maxon/updatejobevent.h"
#include "maxon/threadservices.h"

namespace maxon
{

//----------------------------------------------------------------------------------------
/// UpdateJobEvent implementation
//----------------------------------------------------------------------------------------
Result<void> UpdateJobEvent::Init(UPDATEJOBEVENTMODE mode, const Delegate<void()>& updateDelegate, const JobQueueRef& jobQueueRef)
{
	iferr_scope;
	_mode = mode;
	_updateDelegate.CopyFrom(updateDelegate) iferr_return;
	_updateJobQueueRef = jobQueueRef;
	return OK;
}

void UpdateJobEvent::Init(UPDATEJOBEVENTMODE mode, Delegate<void()>&& updateDelegate, const JobQueueRef& jobQueueRef)
{
	_mode = mode;
	_updateDelegate = std::move(updateDelegate);
	_updateJobQueueRef = jobQueueRef;
}

UpdateJobEvent::~UpdateJobEvent()
{
	Free();
}

Bool UpdateJobEvent::IsInitialized() const
{
	return _updateDelegate.IsPopulated();
}

void UpdateJobEvent::Free()
{
	if (_lastUpdateJob)
	{
		CriticalAssert(JobRef::GetCurrentJob() != reinterpret_cast<JobStatusInterface*>(_lastUpdateJob.GetPointer()));
		_lastUpdateJob.CancelAndWait(WAITMODE::EXTERNAL_ENQUEUE);
		_lastUpdateJob = nullptr;
	}
	_updateJobQueueRef = nullptr;
}

Result<void> UpdateJobEvent::RequestUpdate()
{
	iferr_scope;
	if (_updateRequested.TryCompareAndSwap(true, false))
	{
		// the first update will succeed, all others will be delayed
		if (_mode == UPDATEJOBEVENTMODE::CANCEL_FOR_NEW_REQUESTS && _lastUpdateJob)
		{
			_lastUpdateJob.CancelAndWait(WAITMODE::EXTERNAL_ENQUEUE);
			_lastUpdateJob = nullptr;
		}

		_lastUpdateJob = JobRef::Create([this]()
			{
				const UPDATEJOBEVENTMODE mode = _mode;
				while (true)
				{
					switch (mode)
					{
						case UPDATEJOBEVENTMODE::CANCEL_FOR_NEW_REQUESTS:
						{
							// reset to allow new jobs with cancellation
							_updateRequested.StoreRelease(false);
							break;
						}

						case UPDATEJOBEVENTMODE::FINISH_REQUEST_AND_REPEAT:
						{
							// reset to allow collect jobs without cancellation
							_delayedRequests.Set(0);
							break;
						}
					}

					if (_updateDelegate.IsPopulated())
					{
						_updateDelegate();
					}

					if (mode == UPDATEJOBEVENTMODE::CANCEL_FOR_NEW_REQUESTS)
					{
						break;
					}
					else if (mode == UPDATEJOBEVENTMODE::FINISH_REQUEST_AND_REPEAT)
					{
						if (_delayedRequests.Get() == 0)
						{
							// no more updates requested while running
							_updateRequested.StoreRelease(false);
							break;
						}
					}
				}
			}) iferr_return;

		_lastUpdateJob.Enqueue(_updateJobQueueRef);
	}
	else 
	{
		// an update is already requested, depending of it's mode we need to handle the additional request
		if (_mode == UPDATEJOBEVENTMODE::FINISH_REQUEST_AND_REPEAT)
		{
			_delayedRequests.SwapIncrement();
		}
	}

	return OK;
}

} // namespace maxon
