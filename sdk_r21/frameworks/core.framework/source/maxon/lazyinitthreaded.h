#ifndef LAZYINITTHREADED_H__
#define LAZYINITTHREADED_H__


#include "maxon/atomictypes.h"
#include "maxon/cpuyield.h"
#include "maxon/job.h"
#include "maxon/threadsaferef.h"

namespace maxon
{

/// @addtogroup THREADING Threading
/// @{

//----------------------------------------------------------------------------------------
/// Helper class for multithreaded lazy initialization.
///
/// Typical usage case is a method which initializes data on first call, for example
///
/// @code
/// class Sample
/// {
/// public:
/// 	Result<MyObject*> GetObject()
/// 	{
///			iferr_scope;
///
/// 		_state.Init(
/// 			[this]() -> Result<void>
/// 			{
///					// Invoke complex multithreaded initialization code.
/// 				return ThreadedInitialization();
/// 			});
///
/// 		return _object;
/// 	}
/// private:
/// 	LazyInitThreaded _state;
/// 	MyObject* _object;
/// 	SomeMoreData _xyz;
/// };
/// @endcode
///
/// Performance note: Declaring a global LazyInitThreaded as a static member of a class will
/// degrade its performance because the compiler will guard its access with a slow and
/// unnecessary mutex. To avoid this move the global state outside of the class.
///
/// By default cancellation of the caller will be forwarded to the lambda passed to
/// Init() and after a ThreadCancelledError Init() will retry the initialization.
///
/// @note To use LazyInitThreaded you have to include "job.h" too.
///
/// THREADSAFE.
//----------------------------------------------------------------------------------------
class LazyInitThreaded
{
	static const Int UNINITIALIZED = 0;
	static const Int FAILED = 1;
	static const Int PENDING = 2;
	static const Int ENQUEUED = 3;
	static const Int CHECKING = 4;
	static const Int INITIALIZED = 8;
	static const Int STATE_MASK = 0xf;
	static const Int VALUE_MASK = ~STATE_MASK;

	static void Dummy()
	{
	}

public:
	enum class OPTIONS : Int
	{
		NONE = 0,
		FORWARD_CANCELLATION = 1,	 ///< Cancellation of the calling job will be forwarded.
		RETRY_ON_FAILURE = 2,			 ///< Retry initialization if it failed the first time.
		RETRY_ON_CANCELLATION = 4, ///< Retry initialization if it failed due to thread cancellation (ThreadCancelledError). This is a special
															 ///< case of RETRY_ON_FAILURE.
		DEFAULT = FORWARD_CANCELLATION | RETRY_ON_CANCELLATION ///< Default behaviour: Cancellation of the calling job will be forwarded,
																													 ///< initialization will be retried if it failed due to ThreadCancelledError.
	} MAXON_ENUM_FLAGS_CLASS(OPTIONS);

	~LazyInitThreaded()
	{
		Int value = _state.LoadAcquire();
		Int state = value & STATE_MASK;
		value &= VALUE_MASK;

		if (state == FAILED)
		{
			// Remove reference to the job.
			JobRef job = std::move(reinterpret_cast<JobRef&>(value));
			value = 0;
		}

		DebugAssert(value == 0, "There's an enqueued job which shouldn't be there.");
	}

	//----------------------------------------------------------------------------------------
	/// Initializes an object by calling the specified method (and does nothing if the object
	/// has already been initialized).
	/// The method #fnwill be executed by a job and is free to execute long running multithreaded
	/// code for initialization. Waiting threads will either participate in the initialization or
	/// go to sleep. They will not idle unnecessarily.
	/// If the initialization failed once and #retryOnFailure was false (the default) all following
	/// Init() calls will return the initial error.
	/// THREADSAFE.
	/// @param[in] fn									Method (usually a lambda) to initialize something, must return Result<void>.
	/// @param[in] options						OPTIONS::FORWARD_CANCELLATION by default.
	/// @return												True/OK if initialization was successful or object has already been initialized, otherwise result of
	/// failed initialization.
	//----------------------------------------------------------------------------------------
	template <typename FN> MAXON_ATTRIBUTE_FORCE_INLINE auto Init(FN&& fn, OPTIONS options = OPTIONS::DEFAULT) -> decltype(fn())
	{
		Result<void> result = OK;
		Int					 value = _state.LoadAcquire();
		Int					 state = value & STATE_MASK;

		if (MAXON_UNLIKELY(state != INITIALIZED))
		{
			CpuYield wait;
			JobRef	 job;

			while (state == UNINITIALIZED || state == PENDING)
			{
				// Change state to pending if it is currently uninitialized.
				if ((state == UNINITIALIZED) && _state.TryCompareAndSwap(PENDING, UNINITIALIZED))
				{
					JobInterface* callerJob = reinterpret_cast<JobInterface*>(JobRef::GetCurrentJob());

					// Using & for capture is fine because the job will be executed on JOBQUEUE_NONE.
					auto umbrella = [&fn, &job, callerJob, options, this]() -> decltype(fn()) {
						StrongRef<CancellationForwarder> cancellationObserver;

						// Add an observable to the caller job which forwards cancellation and enables WAITMODE::RETURN_ON_CANCEL for calls inside the
						// lambda.
						if (options & OPTIONS::FORWARD_CANCELLATION)
						{
							cancellationObserver = NewObj(CancellationForwarder, job) iferr_ignore("Nullptr is checked");
							if (callerJob)
								callerJob->ObservableCancelled().AddObserver(cancellationObserver) iferr_ignore(
									"If adding the observer failed this just means cancellation is not supported, but the job is still running.");
						}

						const void* previousResource = ThreadServices::ThreadedExclusiveResource(1, this);
						auto				fnResult = fn();
						ThreadServices::ThreadedExclusiveResource(-1, previousResource);

						// Delete reference from the cancellation forwarder.
						if (cancellationObserver)
							cancellationObserver->DestinationHasFinishedNotification();

						return fnResult;
					};

					// Create a job for the lazy initialization.
					job = JobRef::Create(umbrella) iferr_ignore("Nullptr is checked");
					break;
				}

				// Idle.
				wait.Pause(this);

				// Refetch state.
				value = _state.LoadAcquire();
				state = value & STATE_MASK;
			}

			JobInterface* ptr = job.GetPointer();
			if (ptr)
			{
				// Store the job reference and update the state.
				value = Int(ptr) | ENQUEUED;
				_state.StoreRelease(value);

				// Enqueue it after storing the reference. Use JOBQUEUE_NONE to ensure that the lambda won't execute jobs depending on the caller.
				job.Enqueue(JOBQUEUE_NONE);

				// Wait for the lazy initialization.
				ptr = nullptr;
				result = job.GetResult();
				iferr (std::move(result))
				{
					if ((options & OPTIONS::RETRY_ON_FAILURE) ||
							(options & OPTIONS::RETRY_ON_CANCELLATION && IsErrorOfType<ThreadCancelledError>(err)))
					{
						// Set the state back to uninitialized (the reference to the job will be removed automatically) if the initialization should be
						// retried the next time.
						state = UNINITIALIZED;
					}
					else
					{
						// Indicate that the initialization failed (the reference to the job is kept to get the error).
						new (&ptr) JobRef(std::move(job));
						state = FAILED;
					}
				}
				else
				{
					// Set the state back to initialized (the reference to the job will be removed automatically).
					state = INITIALIZED;
				}

				// Update the state.
				while (1)
				{
					Int newValue = Int(ptr) | state;

					// Refetch state.
					value = _state.LoadAcquire();

					// Update the state unless another thread is currently accessing the reference.
					if (((value & CHECKING) == false) && _state.TryCompareAndSwap(newValue, value))
						break;

					// Idle.
					wait.Pause(this);

					// Refetch state.
					value = _state.LoadAcquire();
				}
			}
			else
			{
				// Check the result and if necessary wait until the job has finished.
				do
				{
					if ((value & CHECKING) == false)
					{
						// Lock the state for safely adding a reference to the job.
						if (_state.TryCompareAndSwap(value | CHECKING, value))
						{
							job = (JobInterface*)(value & VALUE_MASK);
							_state.Swap(value);

							const void* previousResource = ThreadServices::ThreadedExclusiveResource(1, this);

							// Access the job reference outside of the locked section.
							// If the initialization is currently pending the job will return the result.
							// If there's no job reference at this point the initialization failed with out of memory.
							// If the initialization failed and neither RETRY_ON_FAILURE nor RETRY_ON_CANCELLATION were specified the job will return the
							// error.
							result = job.GetResult(TIMEVALUE_INFINITE, WAITMODE::EXTERNAL_ENQUEUE);

							ThreadServices::ThreadedExclusiveResource(-1, previousResource);
							break;
						}
					}

					// Idle.
					wait.Pause(this);

					// Refetch state.
					value = _state.LoadAcquire();
					state = value & STATE_MASK;
				} while (state != INITIALIZED);
			}
		}
		return result;
	}

	//----------------------------------------------------------------------------------------
	/// Resets an object by calling the specified method. Does nothing if the object has already
	/// been reset. If the initialization failed the optional reset method won't be invoked.
	/// THREADSAFE.
	/// @param[in] fn									Optional method (usually a lambda) to reset something.
	//----------------------------------------------------------------------------------------
	template <typename FN = decltype(Dummy)> void Reset(FN&& fn = Dummy)
	{
		Int value = _state.LoadAcquire();
		Int state = value & STATE_MASK;

		if (state != UNINITIALIZED)
		{
			CpuYield wait;

			do
			{
				// Change state to pending if is currently initialized (or failed).
				if (state == INITIALIZED || state == FAILED)
				{
					if (_state.TryCompareAndSwap(PENDING, value))
					{
						if (state == FAILED)
						{
							// Remove reference to the job.
							value &= VALUE_MASK;
							JobRef job = std::move(reinterpret_cast<JobRef&>(value));
						}
						else
						{
							// Call optional reset method
							fn();
						}
						_state.StoreRelease(UNINITIALIZED);
						break;
					}
				}

				// idle
				wait.Pause(this);

				// Refetch state.
				value = _state.LoadAcquire();
				state = value & STATE_MASK;
			} while (state != UNINITIALIZED);
		}
	}

	//----------------------------------------------------------------------------------------
	/// Returns if the object already has been initialized.
	/// THREADSAFE.
	/// @return												True if initialization was successful.
	//----------------------------------------------------------------------------------------
	Bool IsInitialized() const
	{
		return (_state.LoadAcquire() & STATE_MASK) == INITIALIZED;
	}

	Bool HasFailed() const
	{
		return (_state.LoadAcquire() & STATE_MASK) == FAILED;
	}

	//----------------------------------------------------------------------------------------
	/// Returns if the object already has been initialized.
	/// THREADSAFE.
	/// @return												True if initialization was successful.
	//----------------------------------------------------------------------------------------
	explicit operator Bool() const
	{
		return IsInitialized();
	}

private:
	class CancellationForwarder : public JobInterfaceTemplate<CancellationForwarder>
	{
	public:
		explicit CancellationForwarder(const JobRef& job) : _destinationJob(job)
		{
		}
		Result<void> operator()()
		{
			// Forward the cancellation to the destination job and removed its reference.
			JobRef job = _destinationJob;
			_destinationJob = nullptr;
			job.Cancel();

			return OK;
		}

		void DestinationHasFinishedNotification()
		{
			_destinationJob = nullptr;
		}

	private:
		ThreadSafeRef<JobRef> _destinationJob;
	};

private:
	AtomicInt _state;
};

/// @}

} // namespace maxon

#endif // LAZYINITTHREADED_H__
