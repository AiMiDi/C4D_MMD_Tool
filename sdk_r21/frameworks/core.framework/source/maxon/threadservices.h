#ifndef THREADSERVICES_H__
#define THREADSERVICES_H__

#include "maxon/interface.h"
#include "maxon/threadservicespods.h"
#include "maxon/error.h"

namespace maxon
{

//----------------------------------------------------------------------------------------
/// Error of the category jobs, groups and threads.
//----------------------------------------------------------------------------------------
class JobErrorInterface : MAXON_INTERFACE_BASES(ErrorInterface)
{
	MAXON_INTERFACE(JobErrorInterface, MAXON_REFERENCE_COPY_ON_WRITE, "net.maxon.interface.joberror");
};

/// @cond INTERNAL

class CoreJob;
class CoreJobGroup;
class ThreadInterface;
class JobQueueInterface;
struct QueueProfileData;

/// The ThreadServices is a <B> private interface <B>. It is used by ThreadRef, JobRef, JobGroupRef an so on.
/// <B> Do not call the ThreadServices methods directly </B> because all the functionality is exposed by the already mentioned
/// much easier to use higher level interfaces at no performance penalty.
class ThreadServices
{
	friend class ThreadInterface;
	friend class JobStatusInterface;
	friend class JobInterface;
	friend class JobGroupInterface;
	template <typename> friend class StaticJobGroupInterface;
	template <typename> friend class StaticJobArray;
	friend class ParallelFor;
	friend class LazyInitThreaded;

	MAXON_INTERFACE_NONVIRTUAL(ThreadServices, MAXON_REFERENCE_NONE, "net.maxon.interface.threadservices");
private:
	//----------------------------------------------------------------------------------------
	/// Starts a thread to execute the committed job. Will fail and return an error if you try
	/// to start an already running thread.
	/// @param[in] pod								Job structure with jump table.
	/// @param[in] priority						Thread priority.
	/// @return												OK on success. Fails if the thread is already running or no more threads are available.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<void> Start(const JobInterfacePOD& pod, THREADPRIORITY priority);

	//----------------------------------------------------------------------------------------
	/// Enqueues a job (will add a reference and remove it when the object is no longer needed).
	/// THREADSAFE.
	/// @param[in] pod								Job structure with jump table.
	/// @param[in] queue							The queue, use JOBQUEUE_CURRENT for the current queue.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD void Enqueue(const JobInterfacePOD& pod, JobQueueInterface* queue);

	//----------------------------------------------------------------------------------------
	/// Waits until a job has been executed.
	/// As long as a job hasn't been started it is considered not to have finished yet. Once
	/// it has run this will return immediately until you restart the job or reset its state.
	///
	/// <B>Wait() might execute other jobs in the current queue until the one you are waiting
	/// for has finished or is timed out. Therefore you may never lock a shared resource
	/// another job might use as well and then wait. For one this could dead-lock and conceptually
	/// this would result in single-threaded performance.</B>
	///
	/// If you call Wait() from within an enqueued job <I>you must have enqueued what you are
	/// waiting for</I>. Otherwise Wait() will immediately return false because this would lead
	/// to a deadlock. The same applies if a job tries to wait for itself.
	///
	/// Instead of waiting for a job to start some action after it has finished
	/// you should call AddFinishedObserver(). This cannot dead-lock, is more
	/// efficient and can even be used to run the observer in a different queue. For example
	/// you can run a job and register an observer for it that will run on the main thread's
	/// queue and updates the UI.
	/// THREADSAFE.
	/// @param[in] pod								Job structure with jump table.
	/// @param[in] timeout						Maximum wait interval in seconds (or TIMEOUT_INFINITE for no time-out).
	/// @param[in] mode								WAITMODE::DEFAULT by default. WAITMODE::RETURN_ON_CANCEL means that Wait() will return if the caller has been cancelled even if the condition has not been set yet.
	/// @return												True if successful, false for time out or if you try to wait inside an enqueued job.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Bool Wait(const JobInterfacePOD& pod, Float64 timeout, WAITMODE mode);

	//----------------------------------------------------------------------------------------
	/// Waits until this job has been executed and returns the result.
	/// THREADSAFE.
	/// @param[in] pod								Job structure with jump table (CoreJob pointer of the JobInterface might be null).
	/// @param[in] timeout						Maximum wait interval in seconds (or TIMEOUT_INFINITE for no time-out).
	/// @param[in] mode								WAITMODE::DEFAULT by default. WAITMODE::RETURN_ON_CANCEL means that Wait() will return if the caller has been cancelled even if the condition has not been set yet.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<void> GetResult(const JobInterfacePOD& pod, Float64 timeout, WAITMODE mode);

	//----------------------------------------------------------------------------------------
	/// Resets the state of a thread which has been running so that it can be restarted again.
	/// This is dangerous, should be avoided and only be used for legacy threads.
	/// @param[in] pod								Job structure with jump table.
	/// @return												OK on success. Fails if the thread is already running or no more threads are available.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<void> Reset(const JobInterfacePOD& pod);

	//----------------------------------------------------------------------------------------
	/// Asks the job to cancel execution. If the job is a part of a group the whole
	/// group will be cancelled. Cancellation of a job does not affect its finish observers.
	/// The call will not wait for the job to cancel.
	/// THREADSAFE.
	/// @param[in] pod								Job structure with jump table (CoreJob pointer of the JobInterface might be null).
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD void Cancel(const JobInterfacePOD& pod);

	//----------------------------------------------------------------------------------------
	/// Registers an observer job that will be called after a job has been executed.
	/// You can specify an optional queue that should be used to run the observer which can be
	/// handly if you for example want to update the UI from the main thread after some threaded
	/// work has been done. By default the observer is not queued and runs in the same context
	/// as the job.
	/// You can register observers after the job has been enqueued. It does not matter if the job
	/// has already finished by the time you register an observer - the observer will run in
	/// any case. Furthermore cancellation does not affect the observers; if a job has been
	/// cancelled and returns all its observers are executed because the job has finished.
	/// THREADSAFE.
	/// @param[in] pod								Job structure with jump table (CoreJob pointer of the JobInterface might be null).
	/// @param[in] observerPod				Observer job structure with jump table (CoreJob pointer of the JobInterface might be null).
	/// @param[in] observerQueue			Queue for execution of the observer job, by default the observer is run in the context of the job (JOBQUEUE_NONE)
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<void> AddFinishedObserver(const JobInterfacePOD& pod, const JobInterfacePOD& observerPod, JobQueueInterface* observerQueue);

	//----------------------------------------------------------------------------------------
	/// Registers an observer job that will be called when this job has been cancelled.
	/// You can specify an optional queue that should be used to run the observer, but the common
	/// case is to directly execute the observser on JOBQUEUE_NONE (e.g. to cancel other related operations).
	/// You can register observers after the job has been enqueued. It does not matter if the job
	/// has already finished by the time you register an observer - the observer will run in
	/// any case.
	/// Please take care to avoid potentially blocking operations in the observer as this might
	/// prevent the job from cancelling and cause a deadlock.
	/// THREADSAFE.
	/// @param[in] pod								Job structure with jump table (CoreJob pointer of the JobInterface might be null).
	/// @param[in] observerPod				Observer job structure with jump table (CoreJob pointer of the JobInterface might be null).
	/// @param[in] observerQueue			Queue for execution of the observer job, by default the observer is run in the context of the job (JOBQUEUE_NONE)
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<void> AddCancelledObserver(const JobInterfacePOD& pod, const JobInterfacePOD& observerPod, JobQueueInterface* observerQueue);

	//----------------------------------------------------------------------------------------
	/// Removes an observer job.
	/// THREADSAFE.
	/// @param[in] pod								Job structure with jump table (If the CoreJob pointer of the JobInterface is a nullptr and error will be returned).
	/// @param[in] observerPod				Observer job structure with jump table (CoreJob pointer of the JobInterface might be null).
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<void> RemoveCancelledObserver(const JobInterfacePOD& pod, const JobInterfacePOD& observerPod);

	//----------------------------------------------------------------------------------------
	/// Checks whether a thread is currently running.
	/// @param[in] pod								Job structure with jump table (CoreJob pointer of the JobInterface might be null).
	/// @return												False if the thread is not running (anymore).
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Bool IsRunning(const JobInterfacePOD& pod);

	//----------------------------------------------------------------------------------------
	/// Checks if job should stop.
	/// THREADSAFE.
	/// @param[in] pod								Job structure with jump table (CoreJob pointer of the JobInterface might be null).
	/// @return												True if job has been asked to cancel.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Bool IsCancelled(const JobInterfacePOD& pod);

	//----------------------------------------------------------------------------------------
	/// Adds a reference to a job.
	/// THREADSAFE.
	/// @param[in] pod								Job structure with jump table (CoreJob pointer of the JobInterface is guaranteed to be valid).
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD void AddJobReference(const JobInterfacePOD& pod);

	//----------------------------------------------------------------------------------------
	/// Removes a reference to a job.
	/// THREADSAFE.
	/// @param[in] pod								Job structure with jump table (CoreJob pointer of the JobInterface is guaranteed to be valid).
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD void RemoveJobReference(const JobInterfacePOD& pod);

	//----------------------------------------------------------------------------------------
	/// Creates a strong reference to a job if possible.
	/// THREADSAFE.
	/// @param[in] pod								Job structure with jump table (CoreJob pointer of the JobInterface is guaranteed to be valid).
	/// @return												True if strong reference could be created, false if job is currently being released.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Bool CreateStrongJobReference(const JobInterfacePOD& pod);

	//----------------------------------------------------------------------------------------
	/// Adds a weak reference to a job.
	/// THREADSAFE.
	/// @param[in] pod								Job structure with jump table (CoreJob pointer of the JobInterface is guaranteed to be valid).
	/// @param[in] weakRef						Used to return a weak reference to the target.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD void AddWeakJobReference(const JobInterfacePOD& pod, WeakRefBase& weakRef);

	//----------------------------------------------------------------------------------------
	/// Returns the group a job belongs to.
	/// THREADSAFE.
	/// @param[in] pod								Job structure with jump table (CoreJob pointer of the JobInterface might be null).
	/// @return												Job group pointer this job belongs to or nullptr if it's not part of a group.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD CoreJobGroup*	GetGroup(const JobInterfacePOD& pod);

	//----------------------------------------------------------------------------------------
	/// Returns the current thread's running job.
	/// @return												JobInterface* or nullptr (if this is an alien thread).
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD const JobInterface* GetCurrentJob();

	//----------------------------------------------------------------------------------------
	/// Returns a pointer to the currently running thread.
	/// If you call this from a job or a thread you have created by using OS APIs a nullptr is returned.
	/// THREADSAFE.
	/// @return												This thread's ThreadInterface* or nullptr (worker, main or other OS thread)
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD const ThreadInterface* GetCurrentThread();

	//----------------------------------------------------------------------------------------
	/// Returns information about the current thread.
	/// THREADSAFE.
	/// @return												See THREADTYPE.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD THREADTYPE GetCurrentThreadType();

	//----------------------------------------------------------------------------------------
	/// Returns the number of CPU threads (physical plus virtual cores).
	/// THREADSAFE.
	/// @return												Number of CPU threads, guaranteed to be > 0.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Int GetCpuCount();

	//----------------------------------------------------------------------------------------
	/// Returns the stack end address of the current thread.
	/// THREADSAFE.
	/// @return												Stack end address of the current thread.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD void* GetStackEnd();

	//----------------------------------------------------------------------------------------
	/// Allocates a CoreJobGroup.
	/// THREADSAFE.
	/// @param[in] cnt								The maximum number of jobs for this group (0 for a resizable job group).
	/// @param[in] jobSize						Size of a job in bytes.
	/// @param[in] flags							Extra buffer size and flags in the lower five bits.
	/// @return												CoreJobGroup pointer or nullptr if allocation failed.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD CoreJobGroup* CreateGroup(Int cnt, Int jobSize, UInt flags);

	//----------------------------------------------------------------------------------------
	/// Adds a reference to a group.
	/// THREADSAFE.
	/// @param[in] group							Job group.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD void AddGroupReference(CoreJobGroup& group);

	//----------------------------------------------------------------------------------------
	/// Removes a reference to a group.
	/// THREADSAFE.
	/// @param[in] group							Job group.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD void RemoveGroupReference(CoreJobGroup& group);

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
	/// Instead of waiting for some group to start some action after it has finished
	/// you should call AddFinishedObserver(). This cannot dead-lock, is more
	/// efficient and can even be used to run the observer in a different queue. For example
	/// you can run a job and register an observer for it that will run on the main thread's
	/// queue and updates the UI.
	/// THREADSAFE.
	/// @param[in] group							Job group.
	/// @param[in] timeout						Maximum wait interval in seconds (or TIMEOUT_INFINITE for no time-out).
	/// @param[in] mode								WAITMODE::DEFAULT by default. WAITMODE::RETURN_ON_CANCEL means that Wait() will return if the caller has been cancelled even if the condition has not been set yet.
	/// @return												True if successful, false if you try to wait inside an enqueued job.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Bool WaitGroup(CoreJobGroup& group, Float64 timeout, WAITMODE mode);

	//----------------------------------------------------------------------------------------
	/// Waits until all jobs of the group have been executed and returns any errors that were
	/// returned by its jobs.
	/// THREADSAFE.
	/// @param[in] group							Job group.
	/// @param[in] timeout						Maximum wait interval in seconds (or TIMEOUT_INFINITE for no time-out).
	/// @param[in] mode								WAITMODE::DEFAULT by default. WAITMODE::RETURN_ON_CANCEL means that Wait() will return if the caller has been cancelled even if the condition has not been set yet.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<void> GroupGetResult(CoreJobGroup& group, Float64 timeout, WAITMODE mode);

	//----------------------------------------------------------------------------------------
	/// Adds a job to the group.
	/// The group takes <B>exclusive</B> ownership of the job. The job will be deleted after
	/// it has been executed, when the group will be deleted or when adding the job fails.
	/// The job must have been created using NewObj() or the DefaultAllocator. If you had
	/// created a job on the stack or used a custom allocator this would lead to a crash.
	/// As long as the group is not enqueued you can add jobs from any thread. As soon as it
	/// is enqueued only jobs belonging to the group are allowed to add further jobs.
	/// THREADSAFE.
	/// @param[in] group							Job group.
	/// @param[in] pod								Job structure with jump table (self pointer or CoreJob pointer of the JobInterface must be null - otherwise the job would have already been added).
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<void> AddJob(CoreJobGroup& group, const JobInterfacePOD& pod);

	//----------------------------------------------------------------------------------------
	/// Adds a subgroup to the group.
	/// This will add a reference to the group and remove it when the group is not accessed anymore.
	/// If adding a subgroup fails its reference will be removed and its jobs will be stopped.
	/// As long as the group is not enqueued you can add subgroups from any thread. As soon as it
	/// is enqueued only jobs belonging to the group are allowed to add further subgroups.
	/// THREADSAFE.
	/// @param[in] group							Job group.
	/// @param[in] subGroup						Job subgroup (nullptr will return error).
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<void> AddGroup(CoreJobGroup& group, CoreJobGroup* subGroup);

	//----------------------------------------------------------------------------------------
	/// Enqueues all jobs of the group including subgroups (will add a reference and remove
	/// it when the object is no longer needed). Please note that a group (like a job) can
	/// only be enqueued once.
	/// THREADSAFE.
	/// @param[in] group							Job group.
	/// @param[in] queue							The queue, use JOBQUEUE_CURRENT for the current queue.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD void EnqueueGroup(CoreJobGroup& group, JobQueueInterface* queue);

	//----------------------------------------------------------------------------------------
	/// Enqueues all jobs of the group including subgroups and waits for them. This implicitely
	/// indicates to the system that the current job cannot continue until the group has finished.
	/// THREADSAFE.
	/// @param[in] group							Job group.
	/// @param[in] queue							The queue, use JOBQUEUE_CURRENT for the current queue.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<void> EnqueueGroupAndWait(CoreJobGroup& group, JobQueueInterface* queue);

	//----------------------------------------------------------------------------------------
	/// Returns a buffer to store JobInterface-based objects of a static group.
	/// @param[in] group							Job group.
	/// @param[out] capacity					Used to return the number of jobs the group can hold.
	/// @return												Pointer to the job buffer.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD void* GetStaticJobBuffer(const CoreJobGroup& group, Int* capacity);

	//----------------------------------------------------------------------------------------
	/// Adds an array with multiple jobs of the same type to the group (faster than single Add()s).
	/// @param[in] group							Job group.
	/// @param[in] first							Job structure of the first job.
	/// @param[in] memory							Address of the first job, might be different than first due to the vtable.
	/// @param[in] cnt								The number of jobs.
	/// @param[in] size								Size of a job (an object inheriting from JobInterface).
	/// @return												OK on success. Can only fail and return false if the number of jobs is wrong (and memory has been overwritten).
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<void> GroupBatchAdd(CoreJobGroup& group, const JobInterfacePOD* first, void* memory, Int cnt, Int size);

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
	/// @param[in] group							Job group.
	/// @param[in] observerPod				Observer job structure with jump table (CoreJob pointer of the JobInterface might be null).
	/// @param[in] observerQueue			Queue for execution of the observer job, by default the observer is run in the context of the job (JOBQUEUE_NONE)
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<void> AddGroupFinishedObserver(CoreJobGroup& group, const JobInterfacePOD& observerPod, JobQueueInterface* observerQueue);

	//----------------------------------------------------------------------------------------
	/// Asks the group to cancel execution of all jobs that are enqueued. Currently running jobs
	/// are not affected unless they call IsCancelled(). If this is a subgroup the parent group
	/// will be cancelled too.
	/// The call will not wait for the group to cancel and it can be called from any thread or job.
	/// THREADSAFE.
	/// @param[in] group							Job group.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD void GroupCancel(CoreJobGroup& group);

	//----------------------------------------------------------------------------------------
	/// Notifies the group that an operation has finished early (some of its jobs might not
	/// have been executed yet). Used internally by ParallelFor::Dynamic().
	/// Only a job belonging to the group is allowed to mark the group as finished and it
	/// must be called only once.
	/// @param[in] group							Job group.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD void GroupMarkAsFinished(CoreJobGroup& group);

	//----------------------------------------------------------------------------------------
	/// Returns the index of the internal worker thread which is running this job.
	/// If the job is not running as part of a worker thread 0 is returned to make sure you can
	/// safely use this as index to an array with thread local data.
	///
	/// @return												Index between 0 and the number of threads used for the queue - 1.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Int GetCurrentWorkerThreadIndex();

	//----------------------------------------------------------------------------------------
	/// Checks if the currently running job (or thread) should stop.
	/// THREADSAFE.
	/// @return												True if job has been asked to cancel.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Bool IsCurrentJobCancelled();

	//----------------------------------------------------------------------------------------
	/// Allocates internal resources for an alien thread (CoreThread, unique thread index and so on).
	/// THREADSAFE.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<void> AssimilateAlienThread();

	//----------------------------------------------------------------------------------------
	/// Notifies the job system of acquiring or releasing an exclusive resource in which threaded code is executed.
	/// @param[in] selector						internal.
	/// @param[in] resourcePtr				Either a new resource (acquiring a resource) or the resource to be restored (releasing a resource).
	/// @return												Previous resource if a new resource is acquired, to be ignored otherwise.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD const void* ThreadedExclusiveResource(Int selector, const void* resourcePtr);
};
/// @endcond

// include autogenerated headerfile here
#include "threadservices1.hxx"
// include autogenerated headerfile here
#include "threadservices2.hxx"

} // namespace maxon

#endif // THREADSERVICES_H__
