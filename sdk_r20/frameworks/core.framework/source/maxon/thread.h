#ifndef THREAD_H__
#define THREAD_H__

#include "maxon/job.h"
#include "maxon/jobgroup.h"
#include "maxon/cpuyield.h"

namespace maxon
{

/// @addtogroup THREADING Threading
/// @{

//----------------------------------------------------------------------------------------
/// Basic thread template.
/// The ThreadInterface is derived from JobInterface but has its own private thread and therefore you
/// can immediately start it using Start() or Run().
///
/// One way to create a thread is to inherit from ThreadInterface/ThreadInterfaceTemplate and to implement
/// GetName() and operator (), for example
///
/// @code
/// class MyThread : public ThreadInterfaceTemplate<MyThread>
/// {
/// public:
/// 	const char* GetName()	const { return "MyThread"; }
/// 	Result<void> operator ()()
/// 	{
/// 		... your code goes here ...
/// 		... don't forget to check IsCancelled() and return OK or an error ...
/// 	}
/// };
/// @endcode
///
/// A thread is reference counted. If you all you want to do is start it, you can
/// create it with NewObj(), check the return value and call Start(). This will automatically
/// delete your thread object once it finished and is not referenced anymore.
/// If your thread performs potentially lengthy operations in a loop it must call
/// IsCancelled() periodically.
///
/// <B>Threads are reference-counted and you must not create an instance on the stack
/// or as member variable of a class.</B> You can create a thread using NewObj or via
/// ThreadRef::Run() or ThreadRef::Create().
//----------------------------------------------------------------------------------------
class ThreadInterface : public JobInterface
{
public:
	//----------------------------------------------------------------------------------------
	/// @param[in] jmpTable						Jump table of the implementation class.
	//----------------------------------------------------------------------------------------
	explicit ThreadInterface(const JobInterfaceJumpTablePOD& jmpTable) : JobInterface(jmpTable)
	{
	}

	ThreadInterface(ThreadInterface&& src) : JobInterface(std::move(src)) {}

	//----------------------------------------------------------------------------------------
	/// Checks whether this thread is currently running.
	/// <B> Use Wait() if you have to wait for a thread to finish. Repeatedly calling this
	/// method will be detected and result in a debug break. </B>
	/// THREADSAFE.
	/// @return												False if the thread wasn't running anymore.
	//----------------------------------------------------------------------------------------
	Bool IsRunning() const
	{
		return ThreadServices::IsRunning(*this);
	}

	//----------------------------------------------------------------------------------------
	/// Waits until this thread has been executed.
	/// As long as a thread hasn't been started it is considered not to have finished yet. Once
	/// it has run this will return immediately until you restart the thread.
	///
	/// <B>Wait() might execute other jobs in the current queue until the one you are waiting
	/// for has finished or is timed out. Therefore you may never lock a shared resource
	/// another job might use as well and then wait. For one this could dead-lock and conceptually
	/// this would result in single-threaded performance.</B>
	///
	/// If you call Wait() from within an enqueued job <I>you must have started what you are
	/// waiting for</I>. Otherwise Wait() will immediately return false because this would lead
	/// to a deadlock. The same applies if a thread tries to wait for itself.
	///
	/// Instead of waiting for a thread to start some action after it has finished you can
	/// subscribe to ObservableFinished(). This cannot dead-lock, is more efficient and can
	/// even be used to run the observer in a different queue. For example you can run a thread
	/// and register an observer for it that will run on the main thread's
	/// queue and updates the UI.
	/// THREADSAFE.
	/// @param[in] timeout						Maximum wait interval (or TIMEVALUE_INFINITE for no time-out).
	/// @param[in] mode								WAITMODE::DEFAULT by default. WAITMODE::RETURN_ON_CANCEL means that Wait() will return if the caller has been cancelled even if the condition has not been set yet.
	/// @return												True if successful, false if you try to wait inside an enqueued job.
	//----------------------------------------------------------------------------------------
	Bool Wait(TimeValue timeout = TIMEVALUE_INFINITE, WAITMODE mode = WAITMODE::DEFAULT) const
	{
		JobInterface* self = const_cast<ThreadInterface*>(this);
		return ThreadServices::Wait(*self, timeout.GetSeconds(), mode);
	}

	//----------------------------------------------------------------------------------------
	/// Starts a thread to execute this job's worker method (will add a reference and remove
	/// it when the object is no longer needed). If you try to start an already running thread
	/// this will fail and return an error.
	/// @param[in] priority						THREADPRIORITY::NORMAL or THREADPRIORITY::BELOW for a background thread.
	/// @return												OK on success. Failse if the thread is already running or no more threads are available.
	//----------------------------------------------------------------------------------------
	Result<void> Start(THREADPRIORITY priority = THREADPRIORITY::NORMAL)
	{
		DebugAssert(GetReferenceCounter() != 0, "You don't have a reference to the thread.");
		return ThreadServices::Start(*this, priority);
	}

	//----------------------------------------------------------------------------------------
	/// Returns a pointer to the currently running thread.
	/// If you call this from a job or a thread you have created by using OS APIs a nullptr is returned.
	/// THREADSAFE.
	/// @return												This thread's ThreadInterface* or nullptr (worker, main or other OS thread)
	//----------------------------------------------------------------------------------------
	static const ThreadInterface* GetCurrentThread()
	{
		return ThreadServices::GetCurrentThread();
	}

	//----------------------------------------------------------------------------------------
	/// Checks if this thread is the main application thread.
	/// THREADSAFE.
	/// @return												True if this is the main application thread.
	//----------------------------------------------------------------------------------------
	static Bool IsMainThread()
	{
		return ThreadServices::GetCurrentThreadType() == THREADTYPE::MAIN;
	}

	//----------------------------------------------------------------------------------------
	/// Returns information about the current thread.
	/// THREADSAFE.
	/// @return												See THREADTYPE.
	//----------------------------------------------------------------------------------------
	static THREADTYPE GetCurrentThreadType()
	{
		return ThreadServices::GetCurrentThreadType();
	}

	//----------------------------------------------------------------------------------------
	/// Allocates internal resources for an alien thread (CoreThread, unique thread index and so on).
	/// THREADSAFE.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	static Result<void> AssimilateAlienThread()
	{
		return ThreadServices::AssimilateAlienThread();
	}

	//----------------------------------------------------------------------------------------
	/// Returns a readable string of the content.
	/// @param[in] formatStatement		Nullptr or additional formatting instruction. Currently no additional formatting instructions are supported.
	/// @return												The converted result.
	//----------------------------------------------------------------------------------------
	String ToString(const FormatStatement* formatStatement) const;

	Result<void> PrivateResetState()
	{
		return ThreadServices::Reset(*this);
	}
};

template <typename RESULT> class ThreadResultRef;

template <typename IMPLEMENTATION> class ThreadInterfaceTemplate : public ThreadInterface
{
public:
	ThreadInterfaceTemplate() : ThreadInterface(GetJumpTable<IMPLEMENTATION>()) {}
	ThreadInterfaceTemplate(ThreadInterfaceTemplate&& src) : ThreadInterface(std::move(src)) {}

	//----------------------------------------------------------------------------------------
	/// Creates the thread.
	/// @param[in] args								Arguments for the construcor.
	/// @tparam ARGS									Parameter types.
	/// @return												ThreadRef on success, OutOfMemoryerror on failure.
	//----------------------------------------------------------------------------------------
	template <typename... ARGS> static ResultMemT<StrongRef<IMPLEMENTATION>> Create(ARGS&&... args)
	{
		return StrongRef<IMPLEMENTATION>(maxon::details::NewObjWithLocation<IMPLEMENTATION>(MAXON_SOURCE_LOCATION, std::forward<ARGS>(args)...).GetPointer());
	}
private:
	MAXON_DISALLOW_COPY_AND_ASSIGN(ThreadInterfaceTemplate);
};

//----------------------------------------------------------------------------------------
/// Reference to a thread (ThreadInterface).
/// @tparam INTERFACE							Interface class for the ThreadRef (inherits from ThreadInterface).
//----------------------------------------------------------------------------------------
template <typename INTERFACE> class ThreadRefTemplate : public StrongRef<INTERFACE>
{
	using Ptr = StrongRef<INTERFACE>;

public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(ThreadRefTemplate, Ptr);
	
	// Copy/move constructors aren't inherited by "using", therefore we have to write them down here.
	MAXON_IMPLICIT ThreadRefTemplate(const Ptr& src) : Ptr(src) { }
	MAXON_IMPLICIT ThreadRefTemplate(Ptr&& src) : Ptr(std::move(src)) { }
	
	//----------------------------------------------------------------------------------------
	/// Creates a reference to a thread with n arguments.
	/// @param[in] src								Lambda or object with operator ().
	/// @param[in] args								Arguments for the function.
	/// @tparam B											Behaviour for early thread cancellation.
	/// @tparam FN										Type of function/lambda, deduced by the compiler.
	/// @tparam ARGS									Parameter types.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	template <THREADCANCELLATION B = THREADCANCELLATION::AUTOMATIC, typename FN, typename... ARGS> static auto Create(FN&& src, ARGS&&... args) -> ResultMemT<ThreadResultRef<decltype(src(std::forward<ARGS>(args)...))>>
	{
		return ThreadResultRef<decltype(src(std::forward<ARGS>(args)...))>(CreateThread<B>(std::forward<FN>(src), std::forward<ARGS>(args)...));
	};

	//----------------------------------------------------------------------------------------
	/// Checks whether this thread is currently running.
	/// Will return false for a null reference.
	/// THREADSAFE.
	/// @return												False if the thread wasn't running anymore.
	//----------------------------------------------------------------------------------------
	Bool IsRunning() const
	{
		const INTERFACE* self = this->GetPointer();
		return self ? self->IsRunning() : false;
	}

	//----------------------------------------------------------------------------------------
	/// Waits until the referenced thread has been executed.
	/// As long as a thread hasn't been started it is considered not to have finished yet. Once
	/// it has run this will return immediately until you restart the thread.
	///
	/// <B>Wait() might execute other jobs in the current queue until the one you are waiting
	/// for has finished or is timed out. Therefore you may never lock a shared resource
	/// another job might use as well and then wait. For one this could dead-lock and conceptually
	/// this would result in single-threaded performance.</B>
	///
	/// If you call Wait() from within an enqueued job <I>you must have started what you are
	/// waiting for</I>. Otherwise Wait() will immediately return false because this would lead
	/// to a deadlock. The same applies if a thread tries to wait for itself.
	///
	/// Instead of waiting for a thread to start some action after it has finished you can
	/// subscribe to ObservableFinished(). This cannot dead-lock, is more efficient and can
	/// even be used to run the observer in a different queue. For example you can run a thread
	/// and register an observer for it that will run on the main thread's
	/// queue and updates the UI.
	/// THREADSAFE.
	/// @param[in] timeout						Maximum wait interval (or TIMEVALUE_INFINITE for no time-out).
	/// @param[in] mode								WAITMODE::DEFAULT by default. WAITMODE::RETURN_ON_CANCEL means that Wait() will return if the caller has been cancelled even if the condition has not been set yet.
	/// @return												True if successful, false if you try to wait inside an enqueued job or there is no job at all.
	//----------------------------------------------------------------------------------------
	Bool Wait(TimeValue timeout = TIMEVALUE_INFINITE, WAITMODE mode = WAITMODE::DEFAULT) const
	{
		const INTERFACE* self = this->GetPointer();
		return self ? self->Wait(timeout, mode) : false;
	}

	//----------------------------------------------------------------------------------------
	/// Waits until this thread has been executed and returns the result.
	/// THREADSAFE.
	/// @param[in] timeout						Maximum wait interval (or TIMEVALUE_INFINITE for no time-out).
	/// @param[in] mode								WAITMODE::DEFAULT by default. WAITMODE::RETURN_ON_CANCEL means that Wait() will return if the caller has been cancelled even if the condition has not been set yet.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	Result<void> GetResult(TimeValue timeout = TIMEVALUE_INFINITE, WAITMODE mode = WAITMODE::DEFAULT) const
	{
		const INTERFACE* self = this->GetPointer();

		if (MAXON_UNLIKELY(self == nullptr))
			return NullptrError(MAXON_SOURCE_LOCATION);

		return self->GetResult(timeout, mode);
	}

	//----------------------------------------------------------------------------------------
	/// Asks the thread to cancel execution.
	/// The call will not wait for the thread to cancel.
	/// THREADSAFE.
	//----------------------------------------------------------------------------------------
	void Cancel()
	{
		INTERFACE* self = this->GetPointer();
		if (self)
			self->Cancel();
	}

	//----------------------------------------------------------------------------------------
	/// Checks if the thread should stop.
	/// Will return true for a null reference.
	/// THREADSAFE.
	/// @return												True if the thread has been asked to cancel.
	//----------------------------------------------------------------------------------------
	Bool IsCancelled() const
	{
		const INTERFACE* self = this->GetPointer();
		return self ? self->IsCancelled() : true;
	}

	//----------------------------------------------------------------------------------------
	/// Asks the thread to cancel execution and waits until it has finished.
	/// THREADSAFE.
	/// @param[in] mode								WAITMODE::DEFAULT by default.
	//----------------------------------------------------------------------------------------
	void CancelAndWait(WAITMODE mode = WAITMODE::DEFAULT)
	{
		INTERFACE* self = this->GetPointer();
		if (self)
			self->CancelAndWait(mode);
	}

	//----------------------------------------------------------------------------------------
	/// Starts a thread to execute this job's worker method (will add a reference and remove
	/// it when the object is no longer needed). If you try to start an already running thread
	/// this will fail and return an error.
	/// @param[in] priority						THREADPRIORITY::NORMAL or THREADPRIORITY::BELOW for a background thread.
	/// @return												OK on success. Fails if the thread is already running or no more threads are available.
	//----------------------------------------------------------------------------------------
	Result<void> Start(THREADPRIORITY priority = THREADPRIORITY::NORMAL)
	{
		INTERFACE* self = this->GetPointer();

		if (self)
			return self->Start(priority);

		return NullptrError(MAXON_SOURCE_LOCATION);
	}

	//----------------------------------------------------------------------------------------
	/// ObservableFinished is an observable that is triggered after this job has been executed.
	/// THREADSAFE.
	/// @return												Custom observable.
	//----------------------------------------------------------------------------------------
	ObservableFinishedBase<INTERFACE> ObservableFinished()
	{
		return ObservableFinishedBase<INTERFACE>::GetObservable((INTERFACE*) Ptr::GetPointer());
	}

	//----------------------------------------------------------------------------------------
	/// Returns a pointer to the currently running thread.
	/// If you call this from a job or a thread you have created by using OS APIs a nullptr is returned.
	/// THREADSAFE.
	/// @return												This thread's ThreadInterface* or nullptr (worker, main or other OS thread)
	//----------------------------------------------------------------------------------------
	static StrongRef<const INTERFACE> GetCurrentThread()
	{
		return INTERFACE::GetCurrentThread();
	}

	//----------------------------------------------------------------------------------------
	/// Returns the number of worker threads for the current job context. This might be different
	/// from the actual CPU core or thread count.
	/// THREADSAFE.
	/// @return												Number of worker threads, guaranteed to be > 0.
	//----------------------------------------------------------------------------------------
	static Int GetCurrentThreadCount()
	{
		return INTERFACE::GetCurrentThreadCount();
	}

	//----------------------------------------------------------------------------------------
	/// Checks if this thread is the main application thread.
	/// THREADSAFE.
	/// @return												True if this is the main application thread.
	//----------------------------------------------------------------------------------------
	static Bool IsMainThread()
	{
		return INTERFACE::IsMainThread();
	}

	//----------------------------------------------------------------------------------------
	/// Returns information about the current thread.
	/// THREADSAFE.
	/// @return												See THREADTYPE.
	//----------------------------------------------------------------------------------------
	static THREADTYPE GetCurrentThreadType()
	{
		return INTERFACE::GetCurrentThreadType();
	}

	//----------------------------------------------------------------------------------------
	/// Allocates internal resources for an alien thread (CoreThread, unique thread index and so on).
	/// THREADSAFE.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	static Result<void> AssimilateAlienThread()
	{
		return INTERFACE::AssimilateAlienThread();
	}

	//----------------------------------------------------------------------------------------
	/// Checks if the currently running thread (or job) should stop.
	/// Works for jobs and threads.
	/// THREADSAFE.
	/// @param[in] optionalThread			Optional thread which should also be checked for cancellation.
	/// @return												True if the thread has been asked to cancel.
	//----------------------------------------------------------------------------------------
	static Bool IsCurrentThreadCancelled(const ThreadInterface* optionalThread = nullptr)
	{
		return INTERFACE::IsCurrentJobCancelled(optionalThread);
	}

	static Bool IsCurrentThreadCancelled(const ThreadRefTemplate<INTERFACE>& optionalThread)
	{
		return INTERFACE::IsCurrentJobCancelled(optionalThread);
	}

	//----------------------------------------------------------------------------------------
	/// Runs a lambda or object with operator () and n arguments in a thread.
	/// THREADSAFE.
	/// @param[in] src								Lambda or object with operator ().
	/// @param[in] priority						THREADPRIORITY::NORMAL or THREADPRIORITY::BELOW for a background thread.
	/// @tparam B											Behaviour for early thread cancellation.
	/// @tparam FN										Type of function/lambda, deduced by the compiler.
	/// @return												The ThreadInterface encapsulating the closure, might be nullptr if starting the thread failed.
	//----------------------------------------------------------------------------------------
	template <THREADCANCELLATION B = THREADCANCELLATION::AUTOMATIC, typename FN> MAXON_WARN_UNUSED static auto Run(FN&& src, THREADPRIORITY priority = THREADPRIORITY::NORMAL) -> ResultMemT<ThreadResultRef<decltype(src())>>
	{
		ThreadRefTemplate thread = CreateThread<B>(std::forward<FN>(src));
		return ThreadResultRef<decltype(src())>(thread.GCCWorkaroundRun(priority));
	};

	//----------------------------------------------------------------------------------------
	/// Runs a lambda or object with operator () and n arguments in a thread.
	/// THREADSAFE.
	/// @param[in] src								Lambda or object with operator ().
	/// @param[in] priority						THREADPRIORITY::NORMAL or THREADPRIORITY::BELOW for a background thread.
	/// @param[in] args								Arguments for the function.
	/// @tparam B											Behaviour for early thread cancellation.
	/// @tparam FN										Type of function/lambda, deduced by the compiler.
	/// @tparam ARGS									Parameter types.
	/// @return												The ThreadInterface encapsulating the closure, might be nullptr if starting the thread failed.
	//----------------------------------------------------------------------------------------
	template <THREADCANCELLATION B = THREADCANCELLATION::AUTOMATIC, typename FN, typename... ARGS> static auto Run(FN&& src, THREADPRIORITY priority, ARGS&&... args) -> ResultMemT<ThreadResultRef<decltype(src(std::forward<ARGS>(args)...))>>
	{
		ThreadRefTemplate thread = CreateThread<B>(std::forward<FN>(src), std::forward<ARGS>(args)...);
		return ThreadResultRef<decltype(src(std::forward<ARGS>(args)...))>(thread.GCCWorkaroundRun(priority));
	};

	//----------------------------------------------------------------------------------------
	/// Returns a readable string of the content.
	/// @param[in] formatStatement		Nullptr or additional formatting instruction. Currently no additional formatting instructions are supported.
	/// @return												The converted result.
	//----------------------------------------------------------------------------------------
	String ToString(const FormatStatement* formatStatement) const;

	Bool operator ==(const ThreadRefTemplate& other) const
	{
		return this->GetPointer() == other.GetPointer();
	}

	Bool operator !=(const ThreadRefTemplate& other) const
	{
		return this->GetPointer() != other.GetPointer();
	}

	static const ThreadRefTemplate& NullValue()
	{
		return GetZeroRef<ThreadRefTemplate>();
	}

private:
	//----------------------------------------------------------------------------------------
	/// Workaround for buggy gcc 4.7. It mixes up the member method Run(priority) and the static method Run(fn, priority).
	/// THREADSAFE.
	/// @param[in] priority						THREADPRIORITY::NORMAL or THREADPRIORITY::BELOW for a background thread.
	/// @return												The ThreadInterface encapsulating the closure, might be nullptr if memory allocation or thread start failed.
	//----------------------------------------------------------------------------------------
	INTERFACE* GCCWorkaroundRun(THREADPRIORITY priority)
	{
		INTERFACE* self = this->GetPointer();
		if (self)
		{
			if (self->Start(priority) == FAILED)
				self = nullptr;
		}

		return self;
	}

	template <JOBCANCELLATION B, typename FN, typename... ARGS> static INTERFACE* CreateThread(FN&& src, ARGS&&... args)
	{
		using Job = ClosureJob<FN, B, decltype(src(std::forward<ARGS>(args)...)), ARGS...>;
		ResultPtr<Job> thread = NewObj(Job, std::forward<FN>(src), std::forward<ARGS>(args)...);
		return (INTERFACE*) thread.GetPointer();
	};

};

//----------------------------------------------------------------------------------------
/// Reference to a thread (ThreadInterface).
//----------------------------------------------------------------------------------------
using ThreadRef = ThreadRefTemplate<ThreadInterface>;
MAXON_DATATYPE(ThreadRef, "net.maxon.datatype.threadref");

//----------------------------------------------------------------------------------------
/// Reference to a thread that returns more than void/Result\<void\>.
//----------------------------------------------------------------------------------------
template <typename RESULTVALUETYPE> class ThreadResultRef : public ThreadRef
{
public:
	explicit ThreadResultRef(const ThreadRef& src) : ThreadRef(src) {}
	explicit ThreadResultRef(ThreadRef&& src) : ThreadRef(std::move(src)) {}

	//----------------------------------------------------------------------------------------
	/// Waits until this thread has been executed and returns the result.
	/// THREADSAFE.
	/// @param[in] timeout						Maximum wait interval (or TIMEVALUE_INFINITE for no time-out).
	/// @param[in] mode								WAITMODE::DEFAULT by default. WAITMODE::RETURN_ON_CANCEL means that Wait() will return if the caller has been cancelled even if the condition has not been set yet.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	Result<RESULTVALUETYPE> GetResult(TimeValue timeout = TIMEVALUE_INFINITE, WAITMODE mode = WAITMODE::DEFAULT) const
	{
		JobResultInterface<RESULTVALUETYPE>* self = (JobResultInterface<RESULTVALUETYPE>*)this->GetPointer();

		if (MAXON_UNLIKELY(self == nullptr))
			return NullptrError(MAXON_SOURCE_LOCATION);

		return self->GetResult(timeout, mode);
	}
};

template <typename RESULTVALUETYPE> class ThreadResultRef<Result<RESULTVALUETYPE>> : public ThreadRef
{
public:
	explicit ThreadResultRef(const ThreadRef& src) : ThreadRef(src) {}
	explicit ThreadResultRef(ThreadRef&& src) : ThreadRef(std::move(src)) {}

	//----------------------------------------------------------------------------------------
	/// Waits until this job has been executed and returns the result.
	/// THREADSAFE.
	/// @param[in] timeout						Maximum wait interval (or TIMEVALUE_INFINITE for no time-out).
	/// @param[in] mode								WAITMODE::DEFAULT by default. WAITMODE::RETURN_ON_CANCEL means that Wait() will return if the caller has been cancelled even if the condition has not been set yet.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	Result<RESULTVALUETYPE> GetResult(TimeValue timeout = TIMEVALUE_INFINITE, WAITMODE mode = WAITMODE::DEFAULT) const
	{
		JobResultInterface<Result<RESULTVALUETYPE>>* self = (JobResultInterface<Result<RESULTVALUETYPE>>*) GetPointer();

		if (MAXON_UNLIKELY(self == nullptr))
			return NullptrError(MAXON_SOURCE_LOCATION);

		return self->GetResult(timeout, mode);
	}
};

#define StackHasEnoughSpace(size)	((size < 8192) && (UInt(GetStackPointer()) + 16384 > UInt(ThreadServices::GetStackEnd())))
#define StackAlloc(onStack, cnt, TYPE) StackHasEnoughSpace(cnt * sizeof(TYPE)) ? (onStack = true, (TYPE*) alloca(cnt * sizeof(TYPE))) : (onStack = false, NewMem(TYPE, cnt))
#define StackFree(ptr, onStack)	if (onStack == false) DeleteMem(ptr)

/// @}

/// Helper template for ExecuteOnMainThread()'s return value.
template <typename RESULTVALUETYPE> class ExecuteOnMainThreadResult
{
public:
	static RESULTVALUETYPE GetResult(Result<RESULTVALUETYPE>&& result)
	{
		return result.GetValue();
	}
};

template <typename RESULTVALUETYPE> class ExecuteOnMainThreadResult<Result<RESULTVALUETYPE>>
{
public:
	static Result<RESULTVALUETYPE> GetResult(Result<RESULTVALUETYPE>&& result)
	{
		return std::forward<Result<RESULTVALUETYPE>&&>(result);
	}
};

template <> class ExecuteOnMainThreadResult<void>
{
public:
	static void GetResult(Result<void>&& result)
	{
	}
};

//----------------------------------------------------------------------------------------
/// Executes a lambda on the main thread and returns its result (if any). If the current
/// thread is the main thread the lambda is executed directly. Otherwise a job will be
/// enqueued and the function waits until it has finished. If the job does not return any
/// values and can be executed asynchronously you might specify false as wait parameter.
/// The job is always guaranteed to be executed and this method will only return an error
/// if the lambda does.
/// @param[in] fn									Lambda object with the code to be executed.
/// @param[in] wait								True if the caller should wait until the lambda has been executed. False is only permitted for lambdas without return values.
/// @return												Return value of the lambda.
//----------------------------------------------------------------------------------------
template <typename FN> inline auto ExecuteOnMainThread(FN&& fn, Bool wait) -> decltype(fn())
{
	if (ThreadInterface::IsMainThread())
	{
		return fn();
	}
	else
	{
		auto job = JobRef::Enqueue(std::forward<FN>(fn), JobQueueInterface::GetMainThreadQueue()).UncheckedGetValue();
		if (job == nullptr)
		{
			// Create a static job on the stack and wait for it.
			struct alignas(MAXON_CACHE_LINE_SIZE) StaticJob
			{
				StaticJob(FN&& f) : _job(std::forward<FN>(f)) {}
				UChar dummy[MAXON_CACHE_LINE_SIZE - SIZEOF(StrongReferenceCounter)];
				StrongReferenceCounter _referenceCount;
				ClosureJob<FN, JOBCANCELLATION::AUTOMATIC, typename std::result_of<typename std::remove_reference<FN()>::type>::type> _job;
			} staticJob(std::forward<FN>(fn));

			CpuYield yield;

			// Fake a reference to make sure the job system does not try to deallocate the static memory.
			staticJob._referenceCount.SetRelaxed(1);

			staticJob._job.Enqueue();
			staticJob._job.Wait();

			// Wait until all others threads have removed their reference and the static job can be safely reclaimed.
			while (staticJob._referenceCount != 1)
				yield.Pause(&staticJob);

			staticJob._referenceCount.SetRelaxed(0);
			return ExecuteOnMainThreadResult<typename std::result_of<typename std::remove_reference<FN()>::type>::type>::GetResult(staticJob._job.GetResult());
		}
		else if (wait)
		{
			return ExecuteOnMainThreadResult<typename std::result_of<typename std::remove_reference<FN()>::type>::type>::GetResult(job.GetResult());
		}
	}

	// Return void if the lambda returns no value and wait is false.
	return decltype(fn())();
}

} // namespace maxon

#ifdef USE_API_MAXON
class BaseThread;
BaseThread* MaxonConvert(const maxon::ThreadRef& thread);
BaseThread* MaxonConvert(const maxon::ThreadInterface* thread);
maxon::ThreadRef MaxonConvert(BaseThread* thread);
#endif

#endif // THREAD_H__
