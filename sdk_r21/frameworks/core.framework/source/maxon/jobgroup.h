#ifndef JOBGROUP_H__
#define JOBGROUP_H__

#include "maxon/job.h"
#include "maxon/basearray.h"
#include "maxon/nullallocator.h"

namespace maxon
{

/// @addtogroup THREADING Threading
/// @{

/// @cond INTERNAL
#define DISABLE_IF_JOB_OR_GROUP(TYPE, RET) typename std::enable_if<!(std::is_convertible<typename std::remove_reference<TYPE>::type, maxon::JobInterface*>::value || std::is_convertible<typename std::remove_reference<TYPE>::type, maxon::JobGroupInterface*>::value), RET>::type
/// @endcond


/// Flags for enqueue options of a JobGroup.
enum class JOBGROUPFLAGS
{
	DEFAULT = 0,																														///< Default case.
	ENQUEUEING_THREAD_WAITS = 2,																						///< The enqueuing thread waits until the group has finished and might be used to execute jobs.
	FINALIZE_ON_WAIT = 4,																										///< After Enqueue() further Add()s can be made which start the jobs ASAP. A following call to Wait() or GetResult() finalizes the group (no more jobs can be added). Can be useful if there is a lot of setup work before a job can be added.
	THREAD_AFFINITY = 8																											///< On Enqueue() each jobs is permanently assigned to a worker thread. This blocks load balancing and therefore slower and only useful for special cases.
} MAXON_ENUM_FLAGS(JOBGROUPFLAGS);

//----------------------------------------------------------------------------------------
/// Heterogenous job group. The jobs can be of different type and you can add them to the group
/// until you enqueue it (or while the group is running when you use AddSubJob).
/// A job group is free to remove the reference to its jobs or subgroups once they are executed.
/// Creating a job group and jobs is very fast and therefore there's no need to prebuild
/// and perhaps even cache them.
//----------------------------------------------------------------------------------------
class JobGroupInterface
{
	friend class StrongRefHandler;
	friend class CoreJobGroup;
	template <typename> friend struct ObservableFinishedBase;

public:
	//----------------------------------------------------------------------------------------
	/// Enqueues all jobs of the group including subgroups (will add a reference and remove
	/// it when the object is no longer needed). Please note that a group (like a job) can
	/// only be enqueued once.
	/// THREADSAFE.
	/// @param[in] queue							The queue, use JOBQUEUE_CURRENT for the current queue.
	/// @return												Always this (for concatenation).
	//----------------------------------------------------------------------------------------
	JobGroupInterface* Enqueue(JobQueueInterface* queue = JOBQUEUE_CURRENT)
	{
		ThreadServices::EnqueueGroup(GetCoreJobGroup(), queue);
		return this;
	}

	//----------------------------------------------------------------------------------------
	/// Enqueues all jobs of the group including subgroups and waits for them. This implicitely
	/// indicates to the system that the current job cannot continue until the group has finished.
	/// THREADSAFE.
	/// @param[in] queue							The queue, use JOBQUEUE_CURRENT for the current queue.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	Result<void> EnqueueAndWait(JobQueueInterface* queue = JOBQUEUE_CURRENT)
	{
		return ThreadServices::EnqueueGroupAndWait(GetCoreJobGroup(), queue);
	}

	//----------------------------------------------------------------------------------------
	/// Waits until all jobs of the group have been executed.
	///
	/// <B>Wait() might execute other jobs in the current queue until the group you are waiting
	/// for has finished or is timed out. Therefore you may never lock a shared resource
	/// another job might use as well and then wait. For one this could dead-lock and conceptually
	/// this would result in single-threaded performance.</B>
	///
	/// If you try to call Wait() from a job which did not enqueue the group it will
	/// immediately return false because this would lead to a deadlock.
	///
	/// Instead of waiting for some group to start some action after it has finished you can
	/// subscribe to ObservableFinished(). This cannot dead-lock, is more
	/// efficient and can even be used to run the observer in a different queue. For example
	/// you can run a job and register an observer for it that will run on the main thread's
	/// queue and updates the UI.
	/// THREADSAFE.
	/// @param[in] timeout						Maximum wait interval (or TIMEVALUE_INFINITE for no time-out).
	/// @param[in] mode								WAITMODE::DEFAULT by default. WAITMODE::RETURN_ON_CANCEL means that Wait() will return if the caller has been cancelled even if the condition has not been set yet.
	/// @return												True if successful, false if you try to wait inside an enqueued job.
	//----------------------------------------------------------------------------------------
	Bool Wait(TimeValue timeout = TIMEVALUE_INFINITE, WAITMODE mode = WAITMODE::DEFAULT) const
	{
		return ThreadServices::WaitGroup(GetCoreJobGroup(), timeout.GetSeconds(), mode);
	}

	//----------------------------------------------------------------------------------------
	/// Waits until the group has been executed and returns OK on success or any errors returned
	/// by its jobs. If there are errors this might return an AggregatedError.
	/// THREADSAFE.
	/// @param[in] timeout						Maximum wait interval (or TIMEVALUE_INFINITE for no time-out).
	/// @param[in] mode								WAITMODE::DEFAULT by default. WAITMODE::RETURN_ON_CANCEL means that Wait() will return if the caller has been cancelled even if the condition has not been set yet.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	Result<void> GetResult(TimeValue timeout = TIMEVALUE_INFINITE, WAITMODE mode = WAITMODE::DEFAULT) const
	{
		return ThreadServices::GroupGetResult(GetCoreJobGroup(), timeout.GetSeconds(), mode);
	}

	//----------------------------------------------------------------------------------------
	/// Adds a job to the group.
	/// The group takes <B>exclusive</B> ownership of the job. The job will be deleted after
	/// it has been executed, when the group will be deleted or when adding the job fails.
	/// The job must have been created using DefaultAllocator, e.g. with Create() or NewObj().
	/// If you had created a job on the stack or used a custom allocator this would lead to a crash.
	/// As long as the group is not enqueued you can add jobs from any thread. As soon as it
	/// is enqueued only jobs belonging to the group are allowed to add further jobs.
	/// THREADSAFE.
	/// @param[in] job								Job (nullptr will return error).
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	Result<void> Add(JobInterface* job)
	{
		if (job == nullptr)
			return NullptrError(MAXON_SOURCE_LOCATION);

		return ThreadServices::AddJob(GetCoreJobGroup(), *job);
	}

	//----------------------------------------------------------------------------------------
	/// Adds a job to the group.
	/// The group takes <B>exclusive</B> ownership of the job. The job will be deleted after
	/// it has been executed, when the group will be deleted or when adding the job fails.
	/// The job must have been created using DefaultAllocator, e.g. with Create() or NewObj().
	/// If you had created a job on the stack or used a custom allocator this would lead to a crash.
	/// As long as the group is not enqueued you can add jobs from any thread. As soon as it
	/// is enqueued only jobs belonging to the group are allowed to add further jobs.
	/// THREADSAFE.
	/// @param[in] job								Job (nullptr will return error).
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	Result<void> Add(JobRef& job)
	{
		// Remove ownership from the caller.
		JobInterface* unreferenced;
		new (&unreferenced) JobRef(std::move(job));
		if (unreferenced == nullptr)
			return OutOfMemoryError(MAXON_SOURCE_LOCATION);
		System::GetReferenceCounter(unreferenced).SetRelaxed(0);

		return ThreadServices::AddJob(GetCoreJobGroup(), *unreferenced);
	}

	//----------------------------------------------------------------------------------------
	/// Adds a job to the group.
	/// The group takes <B>exclusive</B> ownership of the job. The job will be deleted after
	/// it has been executed, when the group will be deleted or when adding the job fails.
	/// The job must have been created using DefaultAllocator, e.g. with Create() or NewObj().
	/// If you had created a job on the stack or used a custom allocator this would lead to a crash.
	/// As long as the group is not enqueued you can add jobs from any thread. As soon as it
	/// is enqueued only jobs belonging to the group are allowed to add further jobs.
	/// THREADSAFE.
	/// @param[in] job								Job (encapsulated in a ResultMemT directly returned from creation).
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	template <typename T> Result<void> Add(ResultMemT<T*> job)
	{
		JobInterface* ptr = job.GetPointer();
		if (ptr == nullptr)
			return OutOfMemoryError(MAXON_SOURCE_LOCATION);

		return ThreadServices::AddJob(GetCoreJobGroup(), *ptr);
	}

	//----------------------------------------------------------------------------------------
	/// Adds a job to the group.
	/// The group takes <B>exclusive</B> ownership of the job. The job will be deleted after
	/// it has been executed, when the group will be deleted or when adding the job fails.
	/// The job must have been created using DefaultAllocator, e.g. with Create() or NewObj().
	/// If you had created a job on the stack or used a custom allocator this would lead to a crash.
	/// As long as the group is not enqueued you can add jobs from any thread. As soon as it
	/// is enqueued only jobs belonging to the group are allowed to add further jobs.
	/// THREADSAFE.
	/// @param[in] job								Job (encapsulated in a ResultMemT directly returned from creation).
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	template <typename JOBREF> Result<void> Add(ResultMemT<JOBREF>&& job)
	{
		// Remove ownership from the caller because the group takes exclusive ownership.
		JobInterface* unreferenced;
		new (&unreferenced) JobRef(std::move(job.UncheckedGetValue()));
		if (unreferenced == nullptr)
			return OutOfMemoryError(MAXON_SOURCE_LOCATION);
		System::GetReferenceCounter(unreferenced).SetRelaxed(0);

		return ThreadServices::AddJob(GetCoreJobGroup(), *unreferenced);
	}

	//----------------------------------------------------------------------------------------
	/// Encapsulates a lambda or object with operator () in a JobInterface and adds this job to the group.
	/// As long as the group is not enqueued you can add jobs from any thread. As soon as it
	/// is enqueued only jobs belonging to the group are allowed to add further jobs.
	/// THREADSAFE.
	/// @param[in] src								Lambda or object with operator ().
	/// @tparam B											Behaviour for early job cancellation.
	/// @tparam FN										Type of function/lambda, deduced by the compiler.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	template <JOBCANCELLATION B = JOBCANCELLATION::ISOK, typename FN> DISABLE_IF_JOB_OR_GROUP(FN, Result<void>) Add(FN&& src)
	{
		using AddJob = ClosureJob<FN, B, decltype(src())>;
		iferr (AddJob* job = NewObj(AddJob, std::forward<FN>(src)))
			return err;
		return ThreadServices::AddJob(GetCoreJobGroup(), *job);
	}

	//----------------------------------------------------------------------------------------
	/// Adds an array with multiple jobs of the same type to the group (faster than single Add()s).
	/// The group takes <B>exclusive</B> ownership of the jobs. The jobs and the memory for
	/// the array will be freed after they have been executed. If adding the jobs failed they
	/// and the memory will be deleted automatically.
	/// The array must use the DefaultAllocator for memory allocations. Do not use a custom
	/// allocator because this would lead to a crash.
	/// As long as the group is not enqueued you can add jobs from any thread. As soon as it
	/// is enqueued only jobs belonging to the group are allowed to add further jobs.
	/// THREADSAFE.
	/// @param[in] jobs								A BaseArray containing your jobs.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	template <typename T> Result<void> Add(BaseArray<T>& jobs)
	{
		// From now on the group will take ownership of the jobs.
		Block<T> jb = jobs.Disconnect();

		return ThreadServices::GroupBatchAdd(GetCoreJobGroup(), jb.GetFirst(), jb.GetFirst(), jb.GetCount(), SIZEOF(T));
	}

	//----------------------------------------------------------------------------------------
	/// Adds a subgroup to the group.
	/// This will add a reference to the group and remove it when the group is not accessed anymore.
	/// If adding a subgroup fails its reference will be removed and its jobs will be stopped.
	/// As long as the group is not enqueued you can add subgroups from any thread. As soon as it
	/// is enqueued only jobs belonging to the group are allowed to add further subgroups.
	/// THREADSAFE.
	/// @param[in] subGroup						Group object (nullptr will return error).
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	Result<void> Add(JobGroupInterface* subGroup)
	{
		return ThreadServices::AddGroup(GetCoreJobGroup(), &subGroup->GetCoreJobGroup());
	}

	//----------------------------------------------------------------------------------------
	/// ObservableFinished is an observable that is triggered after this group has been executed.
	/// THREADSAFE.
	/// @return												Custom observable.
	//----------------------------------------------------------------------------------------
	ObservableFinishedBase<JobGroupInterface> ObservableFinished()
	{
		return ObservableFinishedBase<JobGroupInterface>::GetObservable(this);
	}

	//----------------------------------------------------------------------------------------
	/// Asks the group to cancel execution of all jobs that are enqueued. Currently running jobs
	/// are not affected unless they call IsCancelled(). If this is a subgroup the parent group
	/// will be cancelled too.
	/// The call will not wait for the group to cancel and it can be called from any thread or job.
	/// THREADSAFE.
	//----------------------------------------------------------------------------------------
	void Cancel()
	{
		ThreadServices::GroupCancel(GetCoreJobGroup());
	}

	//----------------------------------------------------------------------------------------
	/// Asks the group to cancel execution and waits until it has finished.
	/// THREADSAFE.
	/// @param[in] mode								WAITMODE::DEFAULT by default.
	//----------------------------------------------------------------------------------------
	void CancelAndWait(WAITMODE mode = WAITMODE::DEFAULT)
	{
		Cancel();
		Wait(TIMEVALUE_INFINITE, mode);
	}

/// @cond INTERNAL
	//----------------------------------------------------------------------------------------
	/// Returns the internal CoreJobGroup pointer.
	/// @return												CoreJobGroup pointer or nullptr if allocation failed.
	//----------------------------------------------------------------------------------------
	CoreJobGroup& GetCoreJobGroup() const
	{
		return *(CoreJobGroup*) this;
	}

	//----------------------------------------------------------------------------------------
	/// Allocates a JobGroup.
	/// @param[in] flags							Can be used to create an auto-enqueue group.
	/// @return												JobGroupInterface pointer or nullptr if allocation failed.
	//----------------------------------------------------------------------------------------
	static ResultPtr<JobGroupInterface> Alloc(JOBGROUPFLAGS flags = JOBGROUPFLAGS::DEFAULT)
	{
		return (JobGroupInterface*) ThreadServices::CreateGroup(0, 0, UInt(flags));
	}

	//----------------------------------------------------------------------------------------
	/// Notifies the group that an operation has finished early (some of its jobs might not
	/// have been executed yet). Used internally by ParallelFor::Dynamic().
	/// Only a job belonging to the group is allowed to mark the group as finished and it
	/// must be called only once.
	/// @note Even though the group is marked as having finished early its observers may
	/// only be executed after its last job has finished. 
	//----------------------------------------------------------------------------------------
	void MarkAsFinished()
	{
		ThreadServices::GroupMarkAsFinished(GetCoreJobGroup());
	}

/// @endcond

	//----------------------------------------------------------------------------------------
	/// Returns a readable string of the content.
	/// @param[in] formatStatement		Nullptr or additional formatting instruction. Currently no additional formatting instructions are supported.
	/// @return												The converted result.
	//----------------------------------------------------------------------------------------
	String ToString(const FormatStatement* formatStatement) const;

protected:
/// @cond INTERNAL

	//----------------------------------------------------------------------------------------
	/// Registers an observer job that will be called after all jobs of a group (including sub
	/// groups) have been executed. You can use this notification to organize tasks that have
	/// dependencies on other tasks (e.g. a group with all its jobs could represent a task).
	/// You can specify an optional queue that should be used to run the observer which can be
	/// handly if you for example want to update the UI from the main thread after some threaded
	/// work has been done. By default the observer is not queued and runs in the same context
	/// as the last job.
	/// You can register observers after the group has been enqueued. It does not matter if the
	/// group has already finished by the time you register an observer - the observer will run
	/// in any case. Furthermore cancellation does not affect the observers; if a group has been
	/// cancelled and its jobs return all its observers are executed because the jobs have finished.
	/// THREADSAFE.
	/// @param[in] observer						Job object (nullptr will return error).
	/// @param[in] queue							Queue for execution of the observer job, by default the observer is run in the context of the last job (JOBQUEUE_NONE)
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	static Result<void> AddFinishedObserver(JobGroupInterface* group, JobInterface* observer, JobQueueInterface* queue = JOBQUEUE_NONE)
	{
		if (group == nullptr || observer == nullptr)
			return NullptrError(MAXON_SOURCE_LOCATION);

		return ThreadServices::AddGroupFinishedObserver(group->GetCoreJobGroup(), *observer, queue);
	}

	//----------------------------------------------------------------------------------------
	/// Registers an observer job that will be called after all jobs of a group have been executed.
	/// You can specify an optional queue that should be used to run the observer which can be
	/// handly if you for example want to update the UI from the main thread after some threaded
	/// work has been done. By default the observer is not queued and runs in the same context
	/// as the last job.
	/// You can register observers after the group has been enqueued. It does not matter if the
	/// group has already finished by the time you register an observer - the observer will run
	/// in any case. Furthermore cancellation does not affect the observers; if a group has been
	/// cancelled and its jobs return all its observers are executed because the jobs have finished.
	/// THREADSAFE.
	/// @param[in] src								Lambda or object with operator ().
	/// @param[in] queue							Queue for execution of the observer job, by default the observer is run in the context of the last job (JOBQUEUE_NONE)
	/// @tparam FN										Type of function/lambda, deduced by the compiler.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	template <typename FN> static DISABLE_IF_JOBREF(FN, Result<void>) AddFinishedObserver(JobGroupInterface* group, FN&& src, JobQueueInterface* queue = JOBQUEUE_NONE)
	{
		using ObserverJob = ClosureJob<FN, JOBCANCELLATION::ISOK, decltype(src())>;
		iferr (ObserverJob* observer = NewObj(ObserverJob, std::forward<FN>(src)))
			return err;
		return AddFinishedObserver(group, observer, queue);
	}

	void InitialReference() const
	{
		System::GetReferenceCounter(this).SetRelaxed(1);
	}

	void AddReference() const
	{
		ThreadServices::AddGroupReference(GetCoreJobGroup());
	}

	void RemoveReference() const
	{
		ThreadServices::RemoveGroupReference(GetCoreJobGroup());
	}
/// @endcond

private:
	JobGroupInterface();
	~JobGroupInterface();
};

//----------------------------------------------------------------------------------------
/// Reference to a group (JobGroupInterface).
//----------------------------------------------------------------------------------------
class JobGroupRef : public StrongRef<JobGroupInterface>
{
	using Ptr = StrongRef<JobGroupInterface>;

public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(JobGroupRef, Ptr);

	//----------------------------------------------------------------------------------------
	/// Creates a JobGroup.
	/// @param[in] flags							Can be used to create an auto-enqueue group.
	/// @return												JobGroupRef on success, OutOfMemoryerror on failure.
	//----------------------------------------------------------------------------------------
	static ResultMemT<JobGroupRef> Create(JOBGROUPFLAGS flags = JOBGROUPFLAGS::DEFAULT)
	{
		return JobGroupRef(JobGroupInterface::Alloc(flags), 0);
	}

	//----------------------------------------------------------------------------------------
	/// Enqueues all jobs of the group including subgroups (will add a reference and remove
	/// it when the object is no longer needed). Please note that a group (like a job) can
	/// only be enqueued once.
	/// THREADSAFE.
	/// @param[in] queue							The queue, use JOBQUEUE_CURRENT for the current queue.
	/// @return												Always reference to itself (for concatenation).
	//----------------------------------------------------------------------------------------
	JobGroupRef& Enqueue(JobQueueInterface* queue = JOBQUEUE_CURRENT)
	{
		JobGroupInterface* group = GetPointer();
		if (group)
			group->Enqueue(queue);

		return *this;
	}

	//----------------------------------------------------------------------------------------
	/// Enqueues all jobs of the group including subgroups and waits for them. This implicitely
	/// indicates to the system that the current job cannot continue until the group has finished.
	/// THREADSAFE.
	/// @param[in] queue							The queue, use JOBQUEUE_CURRENT for the current queue.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	Result<void> EnqueueAndWait(JobQueueInterface* queue = JOBQUEUE_CURRENT)
	{
		JobGroupInterface* group = GetPointer();

		if (MAXON_UNLIKELY(group == nullptr))
			return NullptrError(MAXON_SOURCE_LOCATION);

		return group->EnqueueAndWait(queue);
	}

	//----------------------------------------------------------------------------------------
	/// Waits until all jobs of the group have been executed.
	///
	/// <B>Wait() might execute other jobs in the current queue until the group you are waiting
	/// for has finished or is timed out. Therefore you may never lock a shared resource
	/// another job might use as well and then wait. For one this could dead-lock and conceptually
	/// this would result in single-threaded performance.</B>
	///
	/// If you try to call Wait() from a job which did not enqueue the group it will
	/// immediately return false because this would lead to a deadlock.
	///
	/// Instead of waiting for some group to start some action after it has finished you can
	/// subscribe to ObservableFinished(). This cannot dead-lock, is more
	/// efficient and can even be used to run the observer in a different queue. For example
	/// you can run a job and register an observer for it that will run on the main thread's
	/// queue and updates the UI.
	/// THREADSAFE.
	/// @param[in] timeout						Maximum wait interval (or TIMEVALUE_INFINITE for no time-out).
	/// @param[in] mode								WAITMODE::DEFAULT by default. WAITMODE::RETURN_ON_CANCEL means that Wait() will return if the caller has been cancelled even if the condition has not been set yet.
	/// @return												True if successful, false if you try to wait inside an enqueued job.
	//----------------------------------------------------------------------------------------
	Bool Wait(TimeValue timeout = TIMEVALUE_INFINITE, WAITMODE mode = WAITMODE::DEFAULT) const
	{
		const JobGroupInterface* group = GetPointer();
		return group ? group->Wait(timeout, mode) : false;
	}

	//----------------------------------------------------------------------------------------
	/// Waits until the group has been executed and returns OK on success or any errors returned
	/// by its jobs. If there are errors this might return an AggregatedError.
	/// THREADSAFE.
	/// @param[in] timeout						Maximum wait interval (or TIMEVALUE_INFINITE for no time-out).
	/// @param[in] mode								WAITMODE::DEFAULT by default. WAITMODE::RETURN_ON_CANCEL means that Wait() will return if the caller has been cancelled even if the condition has not been set yet.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	Result<void> GetResult(TimeValue timeout = TIMEVALUE_INFINITE, WAITMODE mode = WAITMODE::DEFAULT) const
	{
		const JobGroupInterface* group = GetPointer();

		if (MAXON_UNLIKELY(group == nullptr))
			return NullptrError(MAXON_SOURCE_LOCATION);

		return group->GetResult(timeout, mode);
	}

	//----------------------------------------------------------------------------------------
	/// Adds a job, a lambda, a BaseArray of jobs or a whole subgroup.
	/// The group takes <B>exclusive</B> ownership of whatever is added.
	///
	/// If you add a job it will be deleted after it has been executed, when the group will
	/// be deleted or when adding the job fails. The job must have been created using the
	/// DefaultAllocator, e.g. with Create() or NewObj(). If you had created a job on the stack
	/// or used a custom allocator this would lead to a crash.
	///
	/// If you add a BaseArray with multiple jobs of the same type to the group (this is faster
	/// than single Add()s) the jobs and the memory for the array will be freed after they
	/// have been executed. If adding the jobs failed they and the memory will be deleted
	/// automatically. The array must use the DefaultAllocator for memory allocations. Do
	/// not use a custom allocator because this would lead to a crash.
	///
	/// If you add a subgroup this will add a reference to the group and remove it when the
	/// group is not accessed anymore. If adding a subgroup fails its reference will be removed
	/// and its jobs will be stopped.
	///
	/// As long as the group is not enqueued you can add jobs from any thread. As soon as it
	/// is enqueued only jobs belonging to the group are allowed to add further jobs.
	/// THREADSAFE.
	/// @param[in] obj								A job, lambda, BaseArray of jobs or a subgroup.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	template <typename T> Result<void> Add(T&& obj)
	{
		JobGroupInterface* group = GetPointer();

		if (MAXON_LIKELY(group != nullptr))
			return group->Add(std::forward<T>(obj));

		return NullptrError(MAXON_SOURCE_LOCATION);
	}

	/// The same as above but with the ability to specify the behaviour on early cancellation.
	template <JOBCANCELLATION B, typename T> Result<void> Add(T&& obj)
	{
		JobGroupInterface* group = GetPointer();

		if (MAXON_LIKELY(group != nullptr))
			return group->Add<B>(std::forward<T>(obj));

		return NullptrError(MAXON_SOURCE_LOCATION);
	}

	//----------------------------------------------------------------------------------------
	/// ObservableFinished is an observable that is triggered after this job has been executed.
	/// THREADSAFE.
	/// @return												Custom observable.
	//----------------------------------------------------------------------------------------
	ObservableFinishedBase<JobGroupInterface> ObservableFinished()
	{
		// No pointer check needed because self->ObservableFinished() is nothing but a cast.
		JobGroupInterface* self = GetPointer();
		return self->ObservableFinished();
	}

	//----------------------------------------------------------------------------------------
	/// Asks the group to cancel execution of all jobs that are enqueued. Currently running jobs
	/// are not affected unless they call IsCancelled(). If this is a subgroup the parent group
	/// will be cancelled too.
	/// The call will not wait for the group to cancel and it can be called from any thread or job.
	/// THREADSAFE.
	//----------------------------------------------------------------------------------------
	void Cancel()
	{
		JobGroupInterface* group = GetPointer();
		if (group)
			group->Cancel();
	}

	//----------------------------------------------------------------------------------------
	/// Asks the group to cancel execution and waits until it has finished.
	/// THREADSAFE.
	/// @param[in] mode								WAITMODE::DEFAULT by default.
	//----------------------------------------------------------------------------------------
	void CancelAndWait(WAITMODE mode = WAITMODE::DEFAULT)
	{
		JobGroupInterface* group = GetPointer();
		if (group)
			group->CancelAndWait(mode);
	}

	//----------------------------------------------------------------------------------------
	/// Returns a null value of the JobGroupRef (see nullvalue.h for more details).
	/// @return												A null value of the JobGroupRef.
	//----------------------------------------------------------------------------------------
	static const JobGroupRef& NullValue()
	{
		return GetZeroRef<JobGroupRef>();
	}

	//----------------------------------------------------------------------------------------
	/// Returns a readable string of the content.
	/// @param[in] formatStatement		Nullptr or additional formatting instruction. Currently no additional formatting instructions are supported.
	/// @return												The converted result.
	//----------------------------------------------------------------------------------------
	String ToString(const FormatStatement* formatStatement) const;
};



template <typename T> class StaticJobArray;

/// Flags describing the ownership of a StaticJobGroup. You don't have to bother using anything other than DEFAULT.
enum class STATICJOBGROUPFLAGS
{
	DEFAULT = 0,																																///< Safe default case.
	ENQUEUEING_THREAD_WAITS = 2,																								///< The enqueuing thread waits until the group has finished and might be used to execute jobs.
	THREAD_AFFINITY = 8																													///< On Enqueue() each jobs is permanently assigned to a worker thread. This blocks load balancing and therefore slower and only useful for special cases.
} MAXON_ENUM_FLAGS(STATICJOBGROUPFLAGS);

//----------------------------------------------------------------------------------------
/// This is a template for homogenous static job group (all job of the same type and the
/// number of jobs is known at creation). Once you have allocated a StaticJobGroup you cannot
/// add more than the number of jobs specified and you cannot add jobs of a different type
/// than specified in the template. Nonetheless you can add as many subgroups as you want.
//----------------------------------------------------------------------------------------
template <typename T> class StaticJobGroupInterface : public JobGroupInterface
{
public:
	//----------------------------------------------------------------------------------------
	/// Adds an array with multiple jobs of the same type to the group (faster than single Add()s).
	/// @param[in] jobs								A StaticJobArray that was initialized with this group.
	//----------------------------------------------------------------------------------------
	void Add(StaticJobArray<T>& jobs)
	{
		// From now on the group will take ownership of the jobs.
		Block<T> jb = jobs.Disconnect();

		iferr (ThreadServices::GroupBatchAdd(GetCoreJobGroup(), jb.GetFirst(), jb.GetFirst(), jb.GetCount(), SIZEOF(T)))
			DebugStop("This cannot happen if StaticJobArray is used. It could only fail if GroupBatchAdd() would be called directly with a buffer (or somebody has killed StaticJobArray).");
	}
	
	using JobGroupInterface::Add;
	
	//----------------------------------------------------------------------------------------
	/// Allocates a StaticJobGroup.
	/// @param[in] jobCnt							The maximum number of jobs for this group.
	/// @param[in] flags							STATICJOBGROUPFLAGS::DEFAULT by default, the other custom modes are for ParallelFor only.
	/// @param[in] extraBufferSize		By default 0. Size of a private buffer that can be allocated together with the group.
	/// @return												StaticJobGroupInterface pointer or nullptr if allocation failed.
	//----------------------------------------------------------------------------------------
	static ResultPtr<StaticJobGroupInterface> Alloc(Int jobCnt, STATICJOBGROUPFLAGS flags = STATICJOBGROUPFLAGS::DEFAULT, Int extraBufferSize = 0)
	{
		return (StaticJobGroupInterface*) ThreadServices::CreateGroup(jobCnt, SIZEOF(T), UInt((extraBufferSize + 31) & ~Int(31)) | UInt(flags));
	}

	//----------------------------------------------------------------------------------------
	/// Returns a readable string of the content.
	/// @param[in] formatStatement		Nullptr or additional formatting instruction. Currently no additional formatting instructions are supported.
	/// @return												The converted result.
	//----------------------------------------------------------------------------------------
	String ToString(const FormatStatement* formatStatement) const
	{
		return JobGroupInterface::ToString(formatStatement);
	}

private:
	~StaticJobGroupInterface();
};

//----------------------------------------------------------------------------------------
/// Reference to a group with static maximum job count (StaticJobGroupInterface).
//----------------------------------------------------------------------------------------
template <typename T> class StaticJobGroupRef : public StrongRef<StaticJobGroupInterface<T>>
{
	using Ptr = StrongRef<StaticJobGroupInterface<T>>;

public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(StaticJobGroupRef, Ptr);

	using ReferencedType = StaticJobGroupInterface<T>;

	//----------------------------------------------------------------------------------------
	/// Creates a StaticJobGroup.
	/// @param[in] jobCnt							The maximum number of jobs for this group.
	/// @param[in] flags							STATICJOBGROUPFLAGS::DEFAULT by default, the other custom modes are for ParallelFor only.
	/// @param[in] extraBufferSize		By default 0. Size of a private buffer that can be allocated together with the group.
	/// @return												StaticJobGroupRef on success, OutOfMemoryerror on failure.
	//----------------------------------------------------------------------------------------
	static ResultMemT<StaticJobGroupRef> Create(Int jobCnt, STATICJOBGROUPFLAGS flags = STATICJOBGROUPFLAGS::DEFAULT, Int extraBufferSize = 0)
	{
		return StaticJobGroupRef(StaticJobGroupInterface<T>::Alloc(jobCnt, flags, extraBufferSize), 0);
	}

	//----------------------------------------------------------------------------------------
	/// Adds an array with multiple jobs of the same type to the group (faster than single Add()s).
	/// @param[in] jobs								A StaticJobArray that was initialized with this group.
	//----------------------------------------------------------------------------------------
	void Add(StaticJobArray<T>& jobs)
	{
		StaticJobGroupInterface<T>* group = this->GetPointer();
		if (group)
			group->Add(jobs);
	}

	//----------------------------------------------------------------------------------------
	/// Enqueues all jobs of the group including subgroups (will add a reference and remove
	/// it when the object is no longer needed).
	/// THREADSAFE.
	/// @param[in] queue							The queue, use JOBQUEUE_CURRENT for the current queue.
	/// @return												Always reference to itself (for concatenation).
	//----------------------------------------------------------------------------------------
	StaticJobGroupRef<T>& Enqueue(JobQueueInterface* queue = JOBQUEUE_CURRENT)
	{
		StaticJobGroupInterface<T>* group = *this;
		if (group)
			group->Enqueue(queue);

		return *this;
	}

	//----------------------------------------------------------------------------------------
	/// Enqueues all jobs of the group including subgroups and waits for them. This implicitely
	/// indicates to the system that the current job cannot continue until the group has finished.
	/// THREADSAFE.
	/// @param[in] queue							The queue, use JOBQUEUE_CURRENT for the current queue.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	Result<void> EnqueueAndWait(JobQueueInterface* queue = JOBQUEUE_CURRENT)
	{
		StaticJobGroupInterface<T>* group = *this;

		if (MAXON_UNLIKELY(group == nullptr))
			return NullptrError(MAXON_SOURCE_LOCATION);

		return group->EnqueueAndWait(queue);
	}

	//----------------------------------------------------------------------------------------
	/// Waits until all jobs of the group have been executed.
	///
	/// <B>Wait() might execute other jobs in the current queue until the group you are waiting
	/// for has finished or is timed out. Therefore you may never lock a shared resource
	/// another job might use as well and then wait. For one this could dead-lock and conceptually
	/// this would result in single-threaded performance.</B>
	///
	/// If you try to call Wait() from a job which did not enqueue the group it will
	/// immediately return false because this would lead to a deadlock.
	///
	/// Instead of waiting for some group to start some action after it has finished you can
	/// subscribe to ObservableFinished(). This cannot dead-lock, is more
	/// efficient and can even be used to run the observer in a different queue. For example
	/// you can run a job and register an observer for it that will run on the main thread's
	/// queue and updates the UI.
	/// THREADSAFE.
	/// @param[in] timeout						Maximum wait interval (or TIMEVALUE_INFINITE for no time-out).
	/// @param[in] mode								WAITMODE::DEFAULT by default. WAITMODE::RETURN_ON_CANCEL means that Wait() will return if the caller has been cancelled even if the condition has not been set yet.
	/// @return												True if successful, false if you try to wait inside an enqueued job.
	//----------------------------------------------------------------------------------------
	Bool Wait(TimeValue timeout = TIMEVALUE_INFINITE, WAITMODE mode = WAITMODE::DEFAULT) const
	{
		const StaticJobGroupInterface<T>* group = this->GetPointer();
		return group ? group->Wait(timeout, mode) : false;
	}

	//----------------------------------------------------------------------------------------
	/// Waits until the group has been executed and returns OK on success or any errors returned
	/// by its jobs. If there are errors this might return an AggregatedError.
	/// THREADSAFE.
	/// @param[in] timeout						Maximum wait interval (or TIMEVALUE_INFINITE for no time-out).
	/// @param[in] mode								WAITMODE::DEFAULT by default. WAITMODE::RETURN_ON_CANCEL means that Wait() will return if the caller has been cancelled even if the condition has not been set yet.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	Result<void> GetResult(TimeValue timeout = TIMEVALUE_INFINITE, WAITMODE mode = WAITMODE::DEFAULT) const
	{
		const StaticJobGroupInterface<T>* group = this->GetPointer();

		if (MAXON_UNLIKELY(group == nullptr))
			return NullptrError(MAXON_SOURCE_LOCATION);

		return group->GetResult(timeout, mode);
	}

	//----------------------------------------------------------------------------------------
	/// ObservableFinished is an observable that is triggered after this job has been executed.
	/// THREADSAFE.
	/// @return												Custom observable.
	//----------------------------------------------------------------------------------------
	ObservableFinishedBase<JobGroupInterface> ObservableFinished()
	{
		// No pointer check needed because self->ObservableFinished() is nothing but a cast.
		StaticJobGroupInterface<T>* self = this->GetPointer();
		return self->ObservableFinished();
	}

	//----------------------------------------------------------------------------------------
	/// Asks the group to cancel execution of all jobs that are enqueued. Currently running jobs
	/// are not affected unless they call IsCancelled(). If this is a subgroup the parent group
	/// will be cancelled too.
	/// The call will not wait for the group to cancel and it can be called from any thread or job.
	/// THREADSAFE.
	//----------------------------------------------------------------------------------------
	void Cancel()
	{
		StaticJobGroupInterface<T>* group = this->GetPointer();
		if (group)
			group->Cancel();
	}

	//----------------------------------------------------------------------------------------
	/// Asks the group to cancel execution and waits until it has finished.
	/// THREADSAFE.
	/// @param[in] mode								WAITMODE::DEFAULT by default.
	//----------------------------------------------------------------------------------------
	void CancelAndWait(WAITMODE mode = WAITMODE::DEFAULT)
	{
		StaticJobGroupInterface<T>* group = this->GetPointer();
		if (group)
			group->CancelAndWait(mode);
	}

	//----------------------------------------------------------------------------------------
	/// Returns a more generic JobGroupRef.
	/// THREADSAFE.
	/// @return												Cast to JobGroupRef.
	//----------------------------------------------------------------------------------------
	operator JobGroupRef&()
	{
		return *reinterpret_cast<JobGroupRef*>(this);
	}

	//----------------------------------------------------------------------------------------
	/// Returns a null value of the StaticJobGroupRef (see nullvalue.h for more details).
	/// @return												A null value of the StaticJobGroupRef.
	//----------------------------------------------------------------------------------------
	static const StaticJobGroupRef& NullValue()
	{
		return GetZeroRef<StaticJobGroupRef>();
	}

	//----------------------------------------------------------------------------------------
	/// Returns a readable string of the content.
	/// @param[in] formatStatement		Nullptr or additional formatting instruction. Currently no additional formatting instructions are supported.
	/// @return												The converted result.
	//----------------------------------------------------------------------------------------
	String ToString(const FormatStatement* formatStatement) const
	{
		const StaticJobGroupInterface<T>* self = this->GetPointer();
		return self ? self->ToString(formatStatement) : String();
	}
};

/// Initialization options for the StaticJobArray.
enum class STATICJOBARRAYFLAGS
{
	DEFAULT = 0,					///< Default behaviour: Array is empty.
	INITIALIZE_LATER = 1	///< Array consists of as many uninitialized elements as it has capacity. The caller will construct them later on (before it is added to the group).
} MAXON_ENUM_FLAGS(STATICJOBARRAYFLAGS);

// This array can't be resized, it only has the fixed size buffer from the StaticJobGroup.
// Therefore Append() can be called without the necessity to copy or move jobs.
template <typename T> class StaticJobArray : public BaseArray<T, 1, BASEARRAYFLAGS::MOVEANDCOPYOBJECTS, NullAllocator>
{
public:
	StaticJobArray()
	{
	}

	//----------------------------------------------------------------------------------------
	/// Creates a wrapper array around the static buffer of a StaticJobGroup. By default the
	/// array is empty. If you specify STATICJOBARRAYFLAGS::INITIALIZE_LATER the array will
	/// consists of as many uninitialized elements as it has capacity.
	/// at StaticJobGroupInterface::Alloc().
	/// @param[in] group							Job group (nullptr will use buffer as array).
	/// @param[in] flags							STATICJOBARRAYFLAGS::DEFAULT by default.
	/// @param[in] buffer							An optional buffer with sizeof(T) that can be used if group allocation failed (see ParallelFor). It must be big enough to be aligned to a cache line (see PrivateGetExtraBuffer).
	//----------------------------------------------------------------------------------------
	explicit StaticJobArray(StaticJobGroupInterface<T>* group, STATICJOBARRAYFLAGS flags = STATICJOBARRAYFLAGS::DEFAULT, void* buffer = nullptr)
	{
		if (group)
		{
			this->_ptr = (T*) ThreadServices::GetStaticJobBuffer(group->GetCoreJobGroup(), &this->_capacity);
		}
		else
		{
			DebugAssert(buffer != nullptr, "If there is no group the buffer pointer must be valid.");

			// StaticJobGroupRef::Add() will use this buffer to handle out of memory and the single threaded ParallelFor case
			this->_ptr = (T*) buffer;
			this->_capacity = 1;
		}

		if (flags == STATICJOBARRAYFLAGS::INITIALIZE_LATER)
			this->_cnt = this->_capacity;
	}

	/// move constructor
	StaticJobArray(StaticJobArray&& src) : BaseArray<T, 1, BASEARRAYFLAGS::MOVEANDCOPYOBJECTS, NullAllocator>(std::move(src))
	{
	}

	/// move assignment operator
	MAXON_OPERATOR_MOVE_ASSIGNMENT(StaticJobArray);

	~StaticJobArray()
	{
		// If Add() wasn't called for some reason we have to destruct the jobs.
		for (Int i = this->_cnt - 1; i >= 0; i--)
			this->_ptr[i].~T();

		// The array must be disconnected because it is owned by the group.
		this->Disconnect();
	}

	//----------------------------------------------------------------------------------------
	/// @cond IGNORE
	/// Pointer will be aligned to MAXON_CACHE_LINE_SIZE.
	/// @return												Pointer to an internal buffer. Will never be nullptr (points either to memory allocated with the static group or to the buffer specified in the constructor).
	//----------------------------------------------------------------------------------------
	void* PrivateGetExtraBuffer() const
	{
		return (void*) ((UInt(this->_ptr + this->_capacity) + MAXON_CACHE_LINE_SIZE - 1) & ~(MAXON_CACHE_LINE_SIZE -1));
	}
/// @endcond
};


/// @}

} // namespace maxon

#endif // JOBGROUP_H__
