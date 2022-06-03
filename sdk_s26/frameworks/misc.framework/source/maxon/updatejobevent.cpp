#include "maxon/updatejobevent.h"

namespace maxon
{

//----------------------------------------------------------------------------------------
/// UpdateJobEvent implementation
//----------------------------------------------------------------------------------------

Result<void> UpdateJobEvent::Init(const Delegate<void()>& updateDelegate, const JobQueueRef& jobQueueRef)
{
	iferr_scope;
	_updateDelegate.CopyFrom(updateDelegate) iferr_return;
	_updateJobQueueRef = jobQueueRef;
	return OK;
}

void UpdateJobEvent::Init(Delegate<void()>&& updateDelegate, const JobQueueRef& jobQueueRef)
{
	_updateDelegate = std::move(updateDelegate);
	_updateJobQueueRef = jobQueueRef;
}

UpdateJobEvent::~UpdateJobEvent()
{
	Free();
}

void UpdateJobEvent::Free()
{
	if (_lastUpdateJob)
	{
		_lastUpdateJob->CancelAndWait(WAITMODE::EXTERNAL_ENQUEUE);
		_lastUpdateJob = nullptr;
	}
	_updateJobQueueRef = nullptr;
}

Result<void> UpdateJobEvent::RequestUpdate(Bool cancelCurrentJob)
{
	iferr_scope;
	if (_updateRequested.TryCompareAndSwap(true, false))
	{
		if (cancelCurrentJob && _lastUpdateJob)
		{
			_lastUpdateJob->CancelAndWait(WAITMODE::EXTERNAL_ENQUEUE);
			_lastUpdateJob = nullptr;
		}
		_lastUpdateJob = NewObj(JobWithConfirmedCancellation,
			[this]()
			{
				_updateRequested.StoreRelease(false);
				if (_updateDelegate.IsPopulated())
				{
					_updateDelegate();
				}
			}) iferr_return;

		_lastUpdateJob->Enqueue(_updateJobQueueRef);
	}

	return OK;
}

} // namespace maxon
