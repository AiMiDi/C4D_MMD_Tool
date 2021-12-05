#ifndef JOBBARRIER_H__
#define JOBBARRIER_H__

#include "maxon/job.h"

namespace maxon
{

/// @addtogroup THREADING Threading
/// @{

//----------------------------------------------------------------------------------------
/// A JobBarrier allows you to wait for all previously enqueued jobs.
/// It is slower than waiting for a job or a group nor does it allow to wait for sub-jobs
/// of previously running jobs/groups, but it can be useful for serialization or when
/// performance is negligible.
/// @note Only single-threaded queues are supported.
//----------------------------------------------------------------------------------------
class JobBarrierInterface : protected JobInterface
{
	friend class JobInterface;
public:
	explicit JobBarrierInterface(const JobInterfaceJumpTablePOD& jmpTable) : JobInterface(jmpTable)
	{
	}

	//----------------------------------------------------------------------------------------
	/// Enqueues the barrier.
	/// THREADSAFE.
	/// @param[in] queue							The queue for the barrier (for now only single-threaded queues are supported).
	/// @return												Always this pointer (for concatenation).
	//----------------------------------------------------------------------------------------
	JobBarrierInterface* Enqueue(JobQueueInterface* queue)
	{
		ThreadServices::EnqueueBarrier(*this, queue);
		return this;
	}

	//----------------------------------------------------------------------------------------
	/// Waits until the barrier has been executed.
	///
	/// <B>Wait() might execute other jobs in the current queue until all previously enqueued
	/// jobs have finished (or a time-out occurs). Therefore you may never lock a shared resource
	/// another job might use as well and then wait. For one this could dead-lock and conceptually
	/// this would result in single-threaded performance.</B>
	///
	/// If you call Wait() from within an enqueued job <I>you must have enqueued what you are
	/// waiting for</I>. Otherwise Wait() will immediately return false because this would lead
	/// to a deadlock.
	///
	/// THREADSAFE.
	/// @param[in] timeout						Maximum wait interval (or TIMEVALUE_INFINITE for no time-out).
	/// @param[in] mode								WAITMODE::DEFAULT by default. WAITMODE::RETURN_ON_CANCEL means that Wait() will return if the caller has been cancelled even if the condition has not been set yet.
	/// @return												True if successful, false if you try to wait inside an enqueued job.
	//----------------------------------------------------------------------------------------
	Bool Wait(TimeValue timeout = TIMEVALUE_INFINITE, WAITMODE mode = WAITMODE::DEFAULT) const
	{
		return JobInterface::Wait(timeout, mode);
	}

	//----------------------------------------------------------------------------------------
	/// ObservableFinished is an observable that is triggered after the barrier has been executed.
	/// THREADSAFE.
	/// @return												Custom observable.
	//----------------------------------------------------------------------------------------
	ObservableFinishedBase<JobBarrierInterface> ObservableFinished()
	{
		return ObservableFinishedBase<JobBarrierInterface>::GetObservable(this);
	}

/// @cond INTERNAL
	//----------------------------------------------------------------------------------------
	/// Allocates a JobBarrier.
	/// @return												JobBarrierInterface pointer or nullptr if allocation failed.
	//----------------------------------------------------------------------------------------
	static JobBarrierInterface* Alloc()
	{
		return ThreadServices::CreateBarrier();
	}

	void AddReference() const
	{
		JobInterface::AddReference();
	}

	void RemoveReference() const
	{
		JobInterface::RemoveReference();
	}

	void AddWeakReference(WeakRefBase& weakRef) const
	{
		JobInterface::AddWeakReference(weakRef);
	}
/// @endcond
};

template <typename IMPLEMENTATION> class JobBarrierInterfaceTemplate : public JobBarrierInterface
{
public:
	JobBarrierInterfaceTemplate() : JobBarrierInterface(GetJumpTable<IMPLEMENTATION>()) { }
	JobBarrierInterfaceTemplate(JobBarrierInterfaceTemplate&& src) : JobInterface(std::move(src)) {}
private:
	MAXON_DISALLOW_COPY_AND_ASSIGN(JobBarrierInterfaceTemplate);
};

//----------------------------------------------------------------------------------------
/// Reference to a barrier (see JobBarrierInterface).
/// Please note: Using a barrier is slower than waiting for individual jobs or groups.
/// @note Only single-threaded queues are supported.
//----------------------------------------------------------------------------------------
class JobBarrierRef : public StrongRef<JobBarrierInterface>
{
	using Ptr = StrongRef<JobBarrierInterface>;

public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(JobBarrierRef, Ptr);

	//----------------------------------------------------------------------------------------
	/// Creates a JobBarrier.
	/// @return												JobBarrierRef on success.
	//----------------------------------------------------------------------------------------
	static ResultMemT<JobBarrierRef> Create()
	{
		return JobBarrierRef(JobBarrierInterface::Alloc());
	}

	//----------------------------------------------------------------------------------------
	/// Enqueues the barrier.
	/// THREADSAFE.
	/// @param[in] queue							The queue for the barrier (for now only single-threaded queues are supported).
	/// @return												Always reference to itself (for concatenation).
	//----------------------------------------------------------------------------------------
	JobBarrierRef& Enqueue(JobQueueInterface* queue)
	{
		JobBarrierInterface* barrier = GetPointer();
		if (barrier)
			barrier->Enqueue(queue);

		return *this;
	}

	//----------------------------------------------------------------------------------------
	/// Waits until jobs preceding the barrier have been executed.
	///
	/// <B>Wait() might execute other jobs in the current queue until all previously enqueued
	/// jobs have finished (or a time-out occurs). Therefore you may never lock a shared resource
	/// another job might use as well and then wait. For one this could dead-lock and conceptually
	/// this would result in single-threaded performance.</B>
	///
	/// If you call Wait() from within an enqueued job <I>you must have enqueued what you are
	/// waiting for</I>. Otherwise Wait() will immediately return false because this would lead
	/// to a deadlock.
	///
	/// THREADSAFE.
	/// @param[in] timeout						Maximum wait interval (or TIMEVALUE_INFINITE for no time-out).
	/// @param[in] mode								WAITMODE::DEFAULT by default. WAITMODE::RETURN_ON_CANCEL means that Wait() will return if the caller has been cancelled even if the condition has not been set yet.
	/// @return												True if successful, false if you try to wait inside an enqueued job.
	//----------------------------------------------------------------------------------------
	Bool Wait(TimeValue timeout = TIMEVALUE_INFINITE, WAITMODE mode = WAITMODE::DEFAULT) const
	{
		const JobBarrierInterface* barrier = GetPointer();
		return barrier ? barrier->Wait(timeout, mode) : false;
	}

	//----------------------------------------------------------------------------------------
	/// Waits until already enqueued jobs have been executed.
	///
	/// See Wait() for more details.
	/// @param[in] queue							The queue for the barrier (for now only single-threaded queues are supported).
	//----------------------------------------------------------------------------------------
	static void WaitForJobs(JobQueueInterface* queue)
	{
		JobBarrierRef barrier = JobBarrierInterface::Alloc();
		DebugAssert(barrier, "This is guaranteed to always succeed.");
		if (barrier)
		{
			barrier.Enqueue(queue);
			barrier.Wait();
		}
	}

	//----------------------------------------------------------------------------------------
	/// ObservableFinished is an observable that is triggered after this job has been executed.
	/// THREADSAFE.
	/// @return												Custom observable.
	//----------------------------------------------------------------------------------------
	ObservableFinishedBase<JobBarrierInterface>  ObservableFinished()
	{
		// No pointer check needed because self->ObservableFinished() is nothing but a cast.
		JobBarrierInterface* self = GetPointer();
		return self->ObservableFinished();
	}

	static const JobBarrierRef& NullValue()
	{
		return GetZeroRef<JobBarrierRef>();
	}

	//----------------------------------------------------------------------------------------
	/// Returns a readable string of the content.
	/// @param[in] formatStatement		Nullptr or additional formatting instruction. Currently no additional formatting instructions are supported.
	/// @return												The converted result.
	//----------------------------------------------------------------------------------------
	String ToString(const FormatStatement* formatStatement) const;
};


/// @}

} // namespace maxon

#endif // JOBBARRIER_H__
