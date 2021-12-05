#ifndef REUSE_RESOURCE_CACHE_H__
#define REUSE_RESOURCE_CACHE_H__

#include "maxon/job.h"
#include "maxon/timer.h"
#include "maxon/spinlock.h"
#include "maxon/threadsaferef.h"


namespace maxon
{

template <typename DATA> struct ReuseData
{
	String								_name;
	TimeValue						_insertTime;
	TimeValue						_timeOut;
	DATA									_resource;

	ReuseData()
	{
	}

	ReuseData(const String& serverName, DATA&& resource, const TimeValue& timeOut) :
		_name(serverName), _resource(std::move(resource))
	{
		_insertTime = TimeValue::GetTime();
		_timeOut = _insertTime + timeOut;
	}
};

template <typename KEY, typename DATA> class ReuseResourceTemplate
{
public:
	using RESTYPE = HashMap<KEY, BaseArray<ReuseData<DATA>>>;

	ReuseResourceTemplate() : _inShutdown(false)
	{
	}

	Result<void> AddToReuseList(const KEY& hashKey, ReuseData<DATA>&& reuseData)
	{
		iferr_scope;

		ScopedLock lock(_lock);

		if (_inShutdown)
			return OK;

		BaseArray<ReuseData<DATA>>& connections = _resources.InsertKey(hashKey) iferr_return;

		connections.Append(std::move(reuseData)) iferr_return;

		// create the timer and the job the first time
		if (!_timerQueue)
		{
			_timerQueue = JobQueueRef::Create(JOBQUEUETYPE::LOWPRIORITY, 1, JOBQUEUEMODE::DETACH_THREADS, "Reuse Resource Queue") iferr_return;
		}

		TimerRef keepAliveTimer = _timer;
		if (!keepAliveTimer)
		{
			_timer = TimerRef::AddPeriodicTimer(Seconds(1.0),
				[this]()
				{
					TimeValue currentTime = TimeValue::GetTime();
					ScopedLock lockI(_lock);
					for (auto e = Iterable::EraseIterator(_resources); e; ++e)
					{
						BaseArray<ReuseData<DATA>>& array = e->GetValue();
						for (auto c = Iterable::EraseIterator(array); c; ++c)
						{
							if (currentTime > c->_timeOut)
							{
								// DiagnosticOutput("Keep Alive Connection removed: @ after: @ given timeout: @", c->_name, currentTime - c->_insertTime, c->_timeOut - c->_insertTime);
								c.Erase();
							}
						}
						if (array.GetCount() == 0)
						{
							e.Erase();
						}
					}
					// no more connections, kill the timer and the queue
					if (_resources.IsEmpty())
					{
						TimerRef keepAliveTimerI = _timer;
						keepAliveTimerI.Cancel();
						_timer = TimerRef();
					}
				}, _timerQueue) iferr_return;
		}
		return OK;
	}

	Bool Find(const KEY& key, DATA& resource)
	{
		ScopedLock lock(_lock);

		BaseArray<ReuseData<DATA>>* reuseData = _resources.FindValue(key);

		if (!reuseData)
			return false;

		ReuseData<DATA> reuseResource;
		if (!reuseData->Pop(&reuseResource))
			return false;

		resource = std::move(reuseResource._resource);

		// DiagnosticOutput("Reused resource for: @", reuseResource._name);
		return true;
	}

	void Free(const Delegate<void(RESTYPE& resources)>& freeCallback)
	{
		MAXON_SCOPE
		{
			ScopedLock lock(_lock);
			_inShutdown = true;

			if (freeCallback)
			{
				freeCallback(_resources);
			}
			else
			{
				_resources.Reset();
			}
		}

		// needs to be outside the lock! otherwise we end up in a dead-lock in the timer.
		TimerRef keepAliveTimer = _timer;
		if (keepAliveTimer)
			keepAliveTimer.CancelAndWait();
		_timer = TimerRef();

		_timerQueue = nullptr;
	}

private:
	Spinlock								_lock;
	RESTYPE									_resources;
	JobQueueRef							_timerQueue;
	ThreadSafeRef<TimerRef>	_timer;
	Bool										_inShutdown;
};

}

#endif // REUSE_RESOURCE_CACHE_H__

