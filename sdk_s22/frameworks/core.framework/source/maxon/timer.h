#ifndef TIMER_H__
#define TIMER_H__

#include "maxon/interface.h"
#include "maxon/timevalue.h"
#include "maxon/system.h"
#include "maxon/job.h"
#include "maxon/thread.h"
#include "maxon/observable.h"

namespace maxon
{

/// @addtogroup TIMER Timer
/// @{



static const TimeValue MINSLEEPDURATION = Milliseconds(10.0);
class TimerRef;

//----------------------------------------------------------------------------------------
/// The timer interface consists of several methods for periodic events.
//----------------------------------------------------------------------------------------
class TimerInterface
{
	MAXON_INTERFACE_NONVIRTUAL(TimerInterface, MAXON_REFERENCE_NORMAL, "net.maxon.interface.timer");

public:
	//----------------------------------------------------------------------------------------
	/// Allocators for common use.
	/// @param[in] allocLocation			Source location.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD TimerInterface* Alloc(MAXON_SOURCE_LOCATION_DECLARATION);

	//----------------------------------------------------------------------------------------
	/// Schedules a job to be called periodically at the specified interval. If the interval
	/// is 0.0 the timer is fired once after the specified delay.
	/// After a job has been started you must call CancelAndWait() and restart it to change
	/// the interval or other parameters.
	/// <B> If you specify JOBQUEUE_NONE your job must execute very fast: It MUST NOT LOCK, MUST
	/// NOT take longer than a millisecond, preferrably it should be faster than a microsecond. </B>
	/// Specifying the main thread queue as destination is equivalent to creating a RunLoop/UI
	/// timer, but you can do this from any thread.
	/// @param[in] interval						Timer interval.
	/// @param[in] delay							Delay until the timer fires the first time.
	/// @param[in] tolerance					Maximum tolerance of execution (used for timer coalescing).
	/// @param[in] job								The job to be executed (periodically).
	/// @param[in] queue							The queue, use JOBQUEUE_CURRENT for the current queue or JOBQUEUE_NONE if the job should be executed immediately.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	MAXON_FUNCTION Result<void> Start(TimeValue interval, TimeValue delay, TimeValue tolerance, JobInterface* job, JobQueueInterface* queue)
	{
		if (job == nullptr)
			return NullptrError(MAXON_SOURCE_LOCATION);

		return Start(interval.GetSeconds(), delay.GetSeconds(), tolerance.GetSeconds(), *job, queue);
	}

	//----------------------------------------------------------------------------------------
	/// Schedules a job to be called periodically at the specified interval. If the interval
	/// is 0.0 the timer is fired once after the specified delay.
	/// After a job has been started you must call CancelAndWait() and restart it to change
	/// the interval or other parameters.
	/// <B> If you specify JOBQUEUE_NONE your job must execute very fast: It MUST NOT LOCK, MUST
	/// NOT take longer than a millisecond, preferably it should be faster than a microsecond. </B>
	/// Specifying the main thread queue as destination is equivalent to creating a RunLoop/UI
	/// timer, but you can do this from any thread.
	/// @param[in] interval						Timer interval.
	/// @param[in] delay							Delay until the timer fires the first time.
	/// @param[in] tolerance					Maximum tolerance of execution (used for timer coalescing).
	/// @param[in] src								A lambda to be executed (periodically).
	/// @param[in] queue							The queue, use JOBQUEUE_CURRENT for the current queue or JOBQUEUE_NONE if the job should be executed immediately.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	template <typename FN> MAXON_FUNCTION DISABLE_IF_JOBREF(FN, Result<void>) Start(TimeValue interval, TimeValue delay, TimeValue tolerance, FN&& src, JobQueueInterface* queue)
	{
		using TimerJob = ClosureJob<FN, JOBCANCELLATION::ISOK, void>;
		iferr (TimerJob* job = NewObj(TimerJob, std::forward<FN>(src)))
			return err;

		return Start(interval.GetSeconds(), delay.GetSeconds(), tolerance.GetSeconds(), *job, queue);
	}


	//----------------------------------------------------------------------------------------
	/// Adds a job to be called periodically at the specified interval. The timer will be
	/// removed when CancelAndWait() is called.
	/// The timer will fire for the first time after the specified interval and with a default
	///  tolerance. For more options you might have to create a TimerRef directly.
	/// Please note that on Windows - and only there - you usually won't get a smaller interval
	/// and granularity than 15 milliseconds. For all other operating systems one millisecond or
	/// below is no problem, but of course this will take a lot of CPU cycles.
	/// If you have specified a queue other than JOBQUEUE_NONE and for one reason or another your
	/// job has not finished in the specified interval (e.g. because there were so many other jobs
	/// in the queue) the next call will be dropped - you won't get a sudden accumulation of calls.
	/// <B> If you specify JOBQUEUE_NONE your job must execute very fast: It MUST NOT LOCK, MUST
	/// NOT take longer than a millisecond, preferrably it should be faster than a microsecond. </B>
	/// Specifying the main thread queue as destination is equivalent to creating a RunLoop/UI
	/// timer, but you can do this from any thread.
	/// @param[in] interval						Timer interval.
	/// @param[in] job								A JobInterface or lambda to be executed periodically.
	/// @param[in] queue							The queue, use JOBQUEUE_CURRENT for the current queue or JOBQUEUE_NONE if the job should be executed immediately.
	/// @tparam FN										Type of object/lambda, deduced by the compiler.
	/// @return												Timer reference.
	//----------------------------------------------------------------------------------------
	template <typename FN> static MAXON_FUNCTION Result<TimerRef> AddPeriodicTimer(TimeValue interval, FN&& job, JobQueueInterface* queue);

	//----------------------------------------------------------------------------------------
	/// Adds a job to be called once after the specified delay. The timer will be removed
	/// after it has fired once or when CancelAndWait() is called.
	/// Please note that on Windows - and only there - you usually will have a granularity of
	/// about 15 milliseconds. For all other operating systems the granularity is usually one
	/// millisecond or lower (high CPU load might lead to deferred timers nonetheless).
	/// If you have specified a queue other than JOBQUEUE_NONE and for one reason or another your
	/// job has not finished in the specified interval (e.g. because there were so many other jobs
	/// in the queue) the next call will be dropped - you won't get a sudden accumulation of calls.
	/// <B> If you specify JOBQUEUE_NONE your job must execute very fast: It MUST NOT LOCK, MUST
	/// NOT take longer than a millisecond, preferrably it should be faster than a microsecond. </B>
	/// Specifying the main thread queue as destination is equivalent to creating a RunLoop/UI
	/// timer, but you can do this from any thread.
	/// @param[in] delay							Delay until job will be enqueued.
	/// @param[in] queue							The queue, use JOBQUEUE_CURRENT for the current queue or JOBQUEUE_NONE if the job should be executed immediately.
	/// @param[in] job								A JobInterface or lambda to be executed once after the specified delay.
	/// @tparam FN										Type of object/lambda, deduced by the compiler.
	/// @return												Timer reference.
	//----------------------------------------------------------------------------------------
	template <typename FN> static MAXON_FUNCTION Result<TimerRef> AddOneShotTimer(TimeValue delay, FN&& job, JobQueueInterface* queue);

	//----------------------------------------------------------------------------------------
	/// Cancels a timer and if necessary waits until a currently pending timer job has finished.
	/// Does nothing if no timer was started.
	/// Don't call CancelAndWait() from inside a timer job because it cant't wait - use Cancel().
	//----------------------------------------------------------------------------------------
	MAXON_METHOD void CancelAndWait();

	//----------------------------------------------------------------------------------------
	/// Cancels a timer. Might have to wait for a currently pending timer job.
	/// Can be called from within the timer job.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD void Cancel();

	//----------------------------------------------------------------------------------------
	/// Notifies the observers that the timer has started.
	//----------------------------------------------------------------------------------------
	MAXON_OBSERVABLE(void, ObservableTimerStarted, (), ObservableCombinerRunAllComponent);

	//----------------------------------------------------------------------------------------
	/// Notifies the observers that the timer has finished.
	//----------------------------------------------------------------------------------------
	MAXON_OBSERVABLE(void, ObservableTimerFinished, (), ObservableCombinerRunAllComponent);

	//----------------------------------------------------------------------------------------
	/// Notifies the observers that the timer job took longer than the specified interval.
	/// param[in] duration						The duration spend in the observable.
	/// param[in] maxDuration				Maximum time that was suggested.
	//----------------------------------------------------------------------------------------
	MAXON_OBSERVABLE(void, ObservableTimerOverload, (const TimeValue& duration, const TimeValue& maxDuration), ObservableCombinerRunAllComponent);

	/// @cond IGNORE

	// private methods
	static MAXON_METHOD void PrivateDisableAllTimers();

protected:
	MAXON_METHOD Result<void> Start(Float64 interval, Float64 startOffset, Float64 tolerance, const JobInterfacePOD& pod, JobQueueInterface* queue);
	/// @endcond
};


/// @}

// include autogenerated headerfile here
#include "timer1.hxx"

// include autogenerated headerfile here
#include "timer2.hxx"


template <typename FN> Result<TimerRef> TimerInterface::AddPeriodicTimer(TimeValue interval, FN&& job, JobQueueInterface* queue)
{
	iferr_scope;

	TimerRef timer = TimerRef::Create() iferr_return;
	TimeValue tolerance = interval * 0.1;
	if (tolerance < MINSLEEPDURATION)
		tolerance = MINSLEEPDURATION;
	timer.Start(interval, interval, tolerance, std::forward<FN>(job), queue) iferr_return;

	return timer;
}

template <typename FN> Result<TimerRef> TimerInterface::AddOneShotTimer(TimeValue delay, FN&& job, JobQueueInterface* queue)
{
	iferr_scope;

	TimerRef timer = TimerRef::Create() iferr_return;
	TimeValue tolerance = delay * 0.1;
	if (tolerance < MINSLEEPDURATION)
		tolerance = MINSLEEPDURATION;
	timer.Start(Seconds(0), delay, tolerance, std::forward<FN>(job), queue) iferr_return;

	return timer;
}

} // namespace maxon

#endif // TIMER_H__
