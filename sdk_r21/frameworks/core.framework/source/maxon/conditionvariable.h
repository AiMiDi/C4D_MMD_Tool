#ifndef CONDITIONVARIABLE_H__
#define CONDITIONVARIABLE_H__

#include "maxon/interface.h"
#include "maxon/job.h"

namespace maxon
{

class JobInterface;

/// @addtogroup THREADING Threading
/// @{

//----------------------------------------------------------------------------------------
/// After the condition variable has been constructed its state will be cleared until Set()
/// is called. This state is sticky until someone calls Clear() unless the condition variable
/// has been created as auto-clear.
//----------------------------------------------------------------------------------------
class ConditionVariableInterface
{
	MAXON_INTERFACE_NONVIRTUAL(ConditionVariableInterface, MAXON_REFERENCE_NORMAL, "net.maxon.interface.conditionvariable");

public:
	//----------------------------------------------------------------------------------------
	/// @param[in] allocLocation			Source location.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD ConditionVariableInterface* Alloc(MAXON_SOURCE_LOCATION_DECLARATION);

	//----------------------------------------------------------------------------------------
	/// If at all times only one thread waits for a condition variable you can make it auto-clear.
	/// This means a Wait() call will automatically clear the condition variable upon return.
	/// @param[in] allocLocation			Source location.
	/// @param[in] isAutoClear				True: Wait() will automatically clear the condition variable. False: The state is sticky until Clear() is called.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD ConditionVariableInterface* Alloc(MAXON_SOURCE_LOCATION_DECLARATION, Bool isAutoClear);

	//----------------------------------------------------------------------------------------
	/// Clears the condition variable and sets the number of dependencies (the number of threads
	/// that have to call Set() before the condition is met). By default this is one.
	/// When Clear() is called after Wait() you must make sure that there are no more threads
	/// still waiting for the same condition. Only after the last thread has left Wait() you are
	/// allowed to call Clear(). Otherwise one of the threads may keep waiting because the
	/// condition was cleared before it was able to wake up.
	/// @param[in] dependencyCnt			The number of times Set() has to be called before the waiting threads will be woken up.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD void Clear(Int32 dependencyCnt = 1);

	//----------------------------------------------------------------------------------------
	/// Adds another dependency to the condition, e.g. another thread that has to call Set()
	/// before the state is considered set.
	/// <B> The condition state must not be set yet. This means you must call this from a
	/// thread which hasn't done its Set() call yet.</B>
	/// THREADSAFE.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD void AddDependency();

	//----------------------------------------------------------------------------------------
	/// Wakes up all threads waiting for this condition (if the dependency count reaches 0, see Clear()).
	/// THREADSAFE.
	/// @return												True if successful.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Bool Set();

	//----------------------------------------------------------------------------------------
	/// Waits until the condition has been set or a certain amount of time has passed.
	/// <B>Does not execute other jobs on the current queue while waiting. Therefore
	/// waiting for a condition variable in a job might result in a deadlock. It's recommended
	/// to call this from a thread only - other uses (e.g. from a job) might be unsafe and dead-lock.</B>
	/// THREADSAFE.
	/// @param[in] timeout						Maximum wait interval (or TIMEVALUE_INFINITE for no time-out).
	/// @param[in] mode								WAITMODE::DEFAULT by default. WAITMODE::RETURN_ON_CANCEL means that Wait() will return if the caller has been cancelled even if the condition has not been set yet.
	/// @return												True if the condition has been set, false for time out or error.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Bool Wait(const TimeValue& timeout = TIMEVALUE_INFINITE, WAITMODE mode = WAITMODE::DEFAULT) const;

	//----------------------------------------------------------------------------------------
	/// ObservableFinished is an observable that is triggered after the condition is set.
	/// Is not supported for auto-clear because it requires a sticky state.
	/// THREADSAFE.
	/// @return												Custom observable.
	//----------------------------------------------------------------------------------------
	MAXON_FUNCTION ObservableFinishedBase<ConditionVariableInterface> ObservableFinished()
	{
		return ObservableFinishedBase<ConditionVariableInterface>::GetObservable(this);
	}
	
private:
	MAXON_METHOD Result<void> PrivateAddFinishedObserver(const JobInterfacePOD& observerPod, JobQueueInterface* observerQueue);

	static MAXON_FUNCTION Result<void> AddFinishedObserver(ConditionVariableInterface* cond, JobInterface* observer, JobQueueInterface* queue = JOBQUEUE_NONE)
	{
		if (cond == nullptr || observer == nullptr)
			return NullptrError(MAXON_SOURCE_LOCATION);

		return cond->PrivateAddFinishedObserver(JobFunctor(observer).GetJobInterfacePOD(), queue);
	}

	template <typename T> static MAXON_FUNCTION typename std::enable_if<!std::is_convertible<typename std::remove_reference<T>::type, JobInterface*>::value, Result<void>>::type AddFinishedObserver(ConditionVariableInterface* cond, T&& src, JobQueueInterface* queue = JOBQUEUE_NONE)
	{
		using ObserverJob = ClosureJob<T, JOBCANCELLATION::ISOK, typename std::result_of<typename std::remove_reference<T>::type()>::type>;
		iferr (ObserverJob* observer = NewObj(ObserverJob, std::forward<T>(src)))
			return err;
		return AddFinishedObserver(cond, static_cast<JobInterface*>(observer), queue);
	}
	template <typename> friend struct ObservableFinishedBase;
};

#include "conditionvariable1.hxx"

#include "conditionvariable2.hxx"

/// @}

} // namespace maxon

#endif // CONDITIONVARIABLE_H__
