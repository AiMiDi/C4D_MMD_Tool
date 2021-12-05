#ifndef JOBQUEUE_H__
#define JOBQUEUE_H__

#include "maxon/interface.h"
#include "maxon/timevalue.h"

namespace maxon
{

/// @addtogroup THREADING Threading
/// @{

/// Type of job queue
enum class JOBQUEUETYPE
{
	MAINTHREAD				= 0,											///< Jobs are executed on the main thread whenever the event loop can spare some time: there is only one queue of this type: use GetMainThreadQueue() to access it.
	NONE							= 1,											///< Jobs are not enqueued but executed in the current context.
	LOWESTPRIORITY		= 2,											///< Use lowest priority threads (worker threads have lowest priority and will not idle when waiting for new jobs or waiting for a group to finish).
	LOWPRIORITY				= 3,											///< Use low priority threads.
	NORMALPRIORITY		= 4,											///< Use normal priority threads (You should rarely have to create a queue with normal priority. Most of the time low priority is sufficient: This makes sure that you don't interfere with really important tasks and if available you still get all cpu power).
	SERVICEIO					= 5,											///< Queue is used for IO and priority is adapted accordingly. Spinning on idle is not allowed.
	THREADLESS				= 6
} MAXON_ENUM_LIST(JOBQUEUETYPE);

/// Options for the job queue
enum class JOBQUEUEMODE
{
	DEFAULT					= 0,												///< Use default settings for the queue.
	SPIN_ON_IDLE		= 1,												///< When there are no jobs threads will be spinning for a short moment before they go to sleep (low latency and highest performance but might unnecessary steals cycles from other threads).
	SLEEP_ON_IDLE		= 2,												///< When there are no jobs threads will immediately go to sleep (results in higher latency).
	DETACH_THREADS	= 3,												///< When there are no jobs the threads will immediately go to sleep and make themselves available to other queues (results in higher latency but less memory/resource usage).
	PSEUDO_THREADS	= 4													///< The workers behave like ordinary threads (JOBQUEUE_CURRENT points to the default queue and the threads don't have a worker thread index).
} MAXON_ENUM_LIST(JOBQUEUEMODE);

static const Int JOBQUEUE_USEMAXIMUMTHREADS = 0;

class ServiceIOJobQueueInterface;

//----------------------------------------------------------------------------------------
/// A JobQueue is used to enqueue and execute jobs. You can specify the priority and the
/// number of its worker threads when calling Init().
///
/// Besides multithreading a nice application of the queues is to use them to serialize jobs,
/// e.g. if your multithreaded code has to write results to a non-threadsafe part of the
/// application you do this by creating a queue with just one thread that serializes the
/// write request (this is similar to what happens when you enqueue a job in the main event
/// queue). See the tutorials (filterwhirl.cpp) for an example usage of that technique.
///
/// Please note that you have to make sure that a queue has executed all jobs before releasing
/// it (the queue can not check that because right after such a check a running dequeued job
/// might enqueue something while the queue would try to delete itself). One way to ensure
/// this is to wait for a master job or group which enqueues all depending groups and jobs.
/// @MAXON_ANNOTATION{refclass=false}
//----------------------------------------------------------------------------------------
class JobQueueInterface
{
	MAXON_INTERFACE_NONVIRTUAL(JobQueueInterface, MAXON_REFERENCE_NORMAL, "net.maxon.interface.jobqueue");

public:
	//----------------------------------------------------------------------------------------
	/// Creates and initializes a job queue.
	/// Do not request more threads than CPU cores are available (use JOBQUEUE_USEMAXIMUMTHREADS
	/// to request the maximum thread count or Application::GetMachineInfo() to get that information).
	/// @param[in] allocLocation			Source location.
	/// @param[in] type								Queue type.
	/// @param[in] threadCnt					The number of threads used by the queue.
	/// @param[in] mode								Scheduling options for the queue. Most of the time there's no need to specify something else than JOBQUEUEMODE::DEFAULT.
	/// @param[in] name								The queue name.
	/// @param[out] ownerId						Used to return the optional owner id of the queue (can be used for CancelAndWait).
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<JobQueueInterface*> Alloc(MAXON_SOURCE_LOCATION_DECLARATION, JOBQUEUETYPE type, Int threadCnt, JOBQUEUEMODE mode, const Char* name, UInt* ownerId = nullptr);

	//----------------------------------------------------------------------------------------
	/// Returns the number of threads used for the queue.
	/// THREADSAFE.
	/// @return												Number of threads.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Int GetThreadCount() const;

	//----------------------------------------------------------------------------------------
	/// Returns the number of threads to be used.
	/// THREADSAFE.
	/// @param[in] queue							Queue interface pointer or JOBQUEUE_CURRENT, JOBQUEUE_NONE.
	/// @param[in] maxWaitSessionLevel	Private: Maximum number of nested Wait() calls.
	/// @return												Number of threads. Guaranteed to be >= 1 (even for JOBQUEUE_NONE).
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Int GetThreadCount(JobQueueInterface* queue, Int maxWaitSessionLevel = LIMIT<Int>::MAX);

	//----------------------------------------------------------------------------------------
	/// Cancels execution of all jobs in the queue (including jobs which are enqueued after
	/// this call). Usually the next step is to release the queue and free all its resources.
	/// Only the owner of a queue can cancel it (requires the id returned by Init()). As usual
	/// Cancel() will not wait and returns immediately after the cancel condition has been set.
	/// THREADSAFE.
	/// @param[in] ownerId						Owner id of the queue (only the owner is allowed to cancel a queue).
	//----------------------------------------------------------------------------------------
	MAXON_METHOD void Cancel(UInt ownerId);

	//----------------------------------------------------------------------------------------
	/// Cancels execution of all jobs in the queue (including jobs which are enqueued after
	/// this call). Waits until the currently running jobs have finished.
	/// Only the owner of a queue can cancel it (requires the id returned by Init()).
	/// THREADSAFE.
	/// @param[in] ownerId						Owner id of the queue (only the owner is allowed to cancel a queue).
	//----------------------------------------------------------------------------------------
	MAXON_METHOD void CancelAndWait(UInt ownerId);

	//----------------------------------------------------------------------------------------
	/// Returns the queue being used when you specify JOBQUEUE_CURRENT.
	/// Usually the destination queue is the same as the queue of the current thread, but there
	/// are exceptions: The main (UI) thread for example belongs to the main thread queue (returned
	/// by GetMainThreadQueue()), but it has the default queue as target if you specify JOBQUEUE_CURRENT.
	/// Furthermore there are rare cases (backward compatibility) where the destination queue
	/// has been modified using SetDestinationQueue().
	/// THREADSAFE.
	/// @return												Destination queue (guaranteed to be a valid pointer).
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD JobQueueInterface* GetDestinationQueue();

	//----------------------------------------------------------------------------------------
	/// Changes the queue that will be used when you enqueue a job/group from this thread and
	/// specify JOBQUEUE_CURRENT. All threads created by the caller from now on will inherit
	/// the queue.
	/// <B> You must own the thread to call this method. Since all child threads will own the
	/// the queue you must make sure it'll be referenced for the whole life time of these threads.
	/// Removing a reference before these child threads have finished can result in a crash
	/// because the threads will not own the queue or add a reference to it. </B>
	/// If you have made sure the queue is not used anymore you can call SetDestinationQueue()
	/// and switch back to the previous destination queue.
	/// <B> Calling this method from within a job or group will result in an error. </B>
	/// @param[in] queue							The queue to be used as JOBQUEUE_CURRENT.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<void> SetDestinationQueue(JobQueueInterface* queue);

	//----------------------------------------------------------------------------------------
	/// Returns the main thread job queue. If you want to run a job in the main thread's
	/// context you can enqueue it specifying this queue. Jobs in the main thread queue will
	/// be executed whenever the main thread checks for events. This means execution of a job
	/// might be delayed if somebody performs a long blocking polling loop.
	/// THREADSAFE.
	/// @return												Main thread job queue (guaranteed to be a valid pointer).
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD JobQueueInterface* GetMainThreadQueue();

	//----------------------------------------------------------------------------------------
	/// Returns a queue for asynchronous I/O and service jobs.
	/// THREADSAFE.
	/// @return												Service I/O queue (guaranteed to be a valid pointer).
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD ServiceIOJobQueueInterface* GetServiceIOQueue();

	/// @cond IGNORE

	// private methods
	//----------------------------------------------------------------------------------------
	/// Private: Executes the jobs in the main thread queue. Returns when the queue is empty or
	/// the time-out duration has been exceeded.
	/// @param[in] timeout						Maximum execution interval (or TIMEVALUE_INFINITE for no time-out).
	//----------------------------------------------------------------------------------------
	MAXON_METHOD void ExecuteJobs(TimeValue timeout = TIMEVALUE_INFINITE);

	class Current
	{
	public:
		Current() {}
		inline operator JobQueueInterface*() const
		{
			return (JobQueueInterface*) Int(-1);
		}
	};

	class None
	{
	public:
		None() {}
		inline operator JobQueueInterface*() const
		{
			return nullptr;
		}
	};

	/// @endcond
};

class ServiceIOJobQueueInterface : public JobQueueInterface
{
public:
	MAXON_IMPLICIT ServiceIOJobQueueInterface(MAXON_SOURCE_LOCATION_DECLARATION) = delete;
};

class SerialJobQueueInterface : public JobQueueInterface
{
public:
	MAXON_IMPLICIT SerialJobQueueInterface(MAXON_SOURCE_LOCATION_DECLARATION) = delete;
};

// include auto generated header file here
#include "jobqueue1.hxx"

//----------------------------------------------------------------------------------------
/// Generic job queue reference.
//----------------------------------------------------------------------------------------
class JobQueueRef : public JobQueueInterface::Reference
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(JobQueueRef, Reference);

	MAXON_IMPLICIT JobQueueRef(const JobQueueInterface::Current&) : Reference(JobQueueInterface::GetDestinationQueue())
	{
	}

	MAXON_IMPLICIT JobQueueRef(const JobQueueInterface::None&) : Reference()
	{
	}

	JobQueueRef& operator =(const JobQueueInterface::Current&)
	{
		this->Reference::operator =(JobQueueInterface::GetDestinationQueue());
		return *this;
	}

	JobQueueRef& operator =(const JobQueueInterface::None&)
	{
		this->Reference::operator =(nullptr);
		return *this;
	}
};


//----------------------------------------------------------------------------------------
/// Reference to a queue for IO purposes.
/// <B>Serial execution does not guarantee the order of execution. The queue may reorder
/// jobs if necessary.</B>
//----------------------------------------------------------------------------------------
class ServiceIOJobQueueRef : public JobQueueRef
{
	using Super = JobQueueRef;
public:
	ServiceIOJobQueueRef() : Super()
	{
	}

	explicit ServiceIOJobQueueRef(ServiceIOJobQueueInterface* q) : Super(q)
	{
	}

	//----------------------------------------------------------------------------------------
	/// Creates a local queue for asynchronous I/O and service jobs. Usually GetServiceIOQueue()
	/// is all you need but sometimes you might have to guarantee that all requests are handled
	/// by one thread (e.g. when dealing with some OS functions). In this case you can create
	/// a local IO queue with just one thread.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	static Result<ServiceIOJobQueueRef> Create()
	{
		return Create(1);
	}

	//----------------------------------------------------------------------------------------
	/// Creates a local queue for asynchronous I/O and service jobs. Usually GetServiceIOQueue()
	/// is all you need but sometimes you might have to guarantee that all requests are handled
	/// by one thread (e.g. when dealing with some OS functions). In this case you can create
	/// a local IO queue with just one thread.
	/// @param[in] threadCnt					The number of threads used by the queue, 1 by default.
	/// @param[in] mode								Scheduling options for the queue. Most of the time there's no need to specify something else than JOBQUEUEMODE::DEFAULT.
	/// @param[in] name								The queue name, by default "Local Service IO Job Queue".
	/// @param[out] ownerId						Owner id of the queue (can be used for CancelAndWait).
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	static Result<ServiceIOJobQueueRef> Create(Int threadCnt, JOBQUEUEMODE mode = JOBQUEUEMODE::SLEEP_ON_IDLE, const Char* name = "Local Service IO Job Queue", UInt* ownerId = nullptr)
	{
		iferr_scope;
		JobQueueRef tmp = Super::Create(JOBQUEUETYPE::SERVICEIO, threadCnt, mode, name, ownerId) iferr_return;
		ServiceIOJobQueueRef r;
		return r;
	}

	ServiceIOJobQueueRef& operator =(ServiceIOJobQueueInterface* q)
	{
		this->Super::operator =(q);
		return *this;
	}

	ServiceIOJobQueueRef& operator =(const JobQueueInterface::None& none)
	{
		this->Super::operator =(none);
		return *this;
	}

	// Implicitly handled by Create.
	Result<UInt> Init(JOBQUEUETYPE type, Int threadCnt, JOBQUEUEMODE mode, const Char* name) = delete;
};

//----------------------------------------------------------------------------------------
/// Reference to a serial queue which guarantees serialized execution of the enqueued jobs.
/// <B>Serial execution does not guarantee the order of execution. The queue may reorder
/// jobs if necessary.</B>
//----------------------------------------------------------------------------------------
class SerialJobQueueRef : public JobQueueRef
{
	using Super = JobQueueRef;
public:
	SerialJobQueueRef() : Super()
	{
	}

	//----------------------------------------------------------------------------------------
	/// Creates and initializes a serial job queue.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	static Result<SerialJobQueueRef> Create()
	{
		return Create(JOBQUEUETYPE::LOWPRIORITY);
	}

	//----------------------------------------------------------------------------------------
	/// Creates and initializes a serial job queue.
	/// @param[in] type								Queue type, by default JOBQUEUETYPE::LOWPRIORITY.
	/// @param[in] mode								Scheduling options for the queue, the default is JOBQUEUEMODE::DEFAULT.
	/// @param[in] name								The queue name, by default "Serial Job Queue".
	/// @param[out] ownerId						Owner id of the queue (can be used for CancelAndWait).
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	static Result<SerialJobQueueRef> Create(JOBQUEUETYPE type, JOBQUEUEMODE mode = JOBQUEUEMODE::DEFAULT, const Char* name = "Serial Job Queue", UInt* ownerId = nullptr)
	{
		iferr_scope;
		CheckArgument(type != JOBQUEUETYPE::MAINTHREAD && type != JOBQUEUETYPE::NONE);
		JobQueueRef tmp = Super::Create(type, 1, mode, name, ownerId) iferr_return;
		SerialJobQueueRef r;
		r.Super::operator =(std::move(tmp));
		return r;
	}

	SerialJobQueueRef& operator =(const JobQueueInterface::None& none)
	{
		this->Super::operator =(none);
		return *this;
	}

	SerialJobQueueRef& operator =(std::nullptr_t t)
	{
		this->Super::operator =(JobQueueRef());
		return *this;
	}

	// Implicitly handled by Create.
	Result<UInt> Init(JOBQUEUETYPE type, Int threadCnt, JOBQUEUEMODE mode, const Char* name) = delete;
};


static const JobQueueInterface::Current JOBQUEUE_CURRENT; ///< Equivalent to calling GetDestinationQueue(), you just save a function call.
static const JobQueueInterface::None JOBQUEUE_NONE;				///< For notifications and timer jobs: Executes them immediately on the current thread.

// include auto generated header file here
#include "jobqueue2.hxx"

/// @}

} // namespace maxon

#endif // JOBQUEUE_H__
