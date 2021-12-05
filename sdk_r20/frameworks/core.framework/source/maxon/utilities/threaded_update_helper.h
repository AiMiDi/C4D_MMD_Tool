#ifndef THREADED_UPDATE_HELPER_H__
#define THREADED_UPDATE_HELPER_H__

#include "maxon/timer.h"
#include "maxon/spinlock.h"
#include "maxon/runloop.h"



namespace maxon
{

class ThreadedUIUpdateBase
{
public:
	// make virtual to destruct it correctly
	virtual ~ThreadedUIUpdateBase()
	{
	}

	virtual Bool IsRunning() = 0;
	virtual Bool Cancel() = 0;
	virtual void Wait() = 0;
};

template <typename CLASSDATA> class ThreadedUIUpdate : public ThreadedUIUpdateBase
{
public:
	virtual ~ThreadedUIUpdate();

	//----------------------------------------------------------------------------------------
	/// Starts a threaded UI update with a given delay and timer update.
	/// The function starts the threaded execution immediately, after timerDelay a timer is started to update the ui with a progress update.
	///
	/// @param[in] threadFn						Callback with the code which needs to be executed parallel. This is running in a new thread.
	/// @param[in] timerDelay					The timer delay after which startWaitFn is triggered.
	/// @param[in] waitFirstDelay			True if the function should wait until the first timerDelay is reached. This leads to a wait time in this function.
	/// 															False to do it completely async. A one-shot timer will be used to trigger the first timerDelay. This is the most efficient way.
	/// @param[in] startWaitFn				Callback which will be triggered if the threadFn takes longer than timerDelay. This is running in the UI Queue.
	/// @param[in] timerInterval			The timer interval that triggers an UI timer update while the thread is running.
	/// @param[in] timerWaitFn				Timer callback to update the UI with progress informations. This is running in the UI Queue.
	/// @param[in] finalUpdateFunc		Finalize callback to update the UI after all is done. This is running in the UI Queue.
	///
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	Result<void> Start(Delegate<Result<void>(CLASSDATA* self)>&& threadFn, const TimeValue& timerDelay, Bool waitFirstDelay, Delegate<Result<void>(CLASSDATA* self)>&& startWaitFn, const TimeValue& timerInterval, Delegate<void(CLASSDATA* self)>&& timerWaitFn, Delegate<Result<void>(CLASSDATA* self, Error threadError)>&& finalUpdateFunc);

	//----------------------------------------------------------------------------------------
	/// Cancel the job.
	///
	/// @return												True if it is still running, in this case a new object needs to be created!
	/// 															False if the thread is unused.
	//----------------------------------------------------------------------------------------
	virtual Bool Cancel();

	virtual void Wait();

	virtual Bool IsRunning();

private:
	Bool CancelI();

private:
	JobRef			_scanThread;
	JobRef			_updateJob;
	TimerRef		_spinningTimer;
	Bool				_isDone = false;
};

//----------------------------------------------------------------------------------------
/// Helper class to create threaded UI updates with a single call.
///
/// @code
/// 	struct TexGuiThreadUpdate : public maxon::ThreadedUIUpdate<TexGuiThreadUpdate>
///		{
///		};
///		maxon::ThreadedUIUpdateRef<TexGuiThreadUpdate> _texGuiThreadedPtr;
///
///		_texGuiThreadedPtr.Start(
///			[](TexGuiThreadUpdate* self) -> maxon::Result<void>
///			{
///				// worker thread, non-UI thread!!!
///				iferr_scope;
///				//...
///				return OK;
///			},
///			maxon::Milliseconds(100.0), false,
///			[this](TexGuiThreadUpdate* self) -> maxon::Result<void>
///			{
///				// first delay, UI thread!!!
///				return maxon::OK;
///			},
///			maxon::Milliseconds(50.0),
///			[this](TexGuiThreadUpdate* self) -> void
///			{
///				// progress timer, UI thread!!!
///			},
///			[this](TexGuiThreadUpdate* self, maxon::Error threadError) -> maxon::Result<void>
///			{
///				// progress timer, UI thread!!!
///				if (threadError)
///				{
///				}
///				else
///				{
///				}
///				return maxon::OK;
///			}
///			) iferr_return;
///	@endcode
///
/// @tparam T											type that needs to be declared like: struct TexGuiThreadUpdate : public maxon::ThreadedUIUpdate<TexGuiThreadUpdate> {};
//----------------------------------------------------------------------------------------
template <typename T> class ThreadedUIUpdateRef
{
public:

	Result<void> Start(Delegate<Result<void>(T* self)>&& threadFn, const TimeValue& timerDelay, Bool waitFirstDelay, Delegate<Result<void>(T* self)>&& startWaitFn, const TimeValue& timerInterval, Delegate<void(T* self)>&& timerWaitFn, Delegate<Result<void>(T* self, Error threadError)>&& finalUpdateFunc)
	{
		iferr_scope;

		if (!_ref || _ref->Cancel())
		{
			_ref = NewObj(T) iferr_return;
		}

		_ref->Start(std::move(threadFn), timerDelay, waitFirstDelay, std::move(startWaitFn), timerInterval, std::move(timerWaitFn), std::move(finalUpdateFunc)) iferr_return;

		return OK;
	}

	void Free()
	{
		if (_ref && !_ref->Cancel())
			_ref = nullptr;
	}

	StrongRef<T> GetRef() { return _ref; }

private:
	StrongRef<T>	_ref;
};

using ThreadedUIUpdateBaseRef = StrongRef<ThreadedUIUpdateBase>;
static HashSet<ThreadedUIUpdateBaseRef>	g_freeThreadedStuff;
static Spinlock g_freeThreadedStuffLock;
static FunctionBaseRef g_exitObservable;
static Bool g_inShutDown;

static void FreeThreadedStuff()
{
	ScopedLock lock(g_freeThreadedStuffLock);
	g_inShutDown = true;
	for (ThreadedUIUpdateBaseRef t : g_freeThreadedStuff)
	{
		t->Wait();
	}
	g_freeThreadedStuff.Reset();
}

template <typename CLASSDATA>
ThreadedUIUpdate<CLASSDATA>::~ThreadedUIUpdate()
{
	// ITEM#190869 Crash while loading an image which has a size greater than 100 MB
	CancelI();
}

template <typename CLASSDATA>
Result<void> ThreadedUIUpdate<CLASSDATA>::Start(Delegate<Result<void>(CLASSDATA* self)>&& threadFn, const TimeValue& timerDelay,
	Bool waitFirstDelay, Delegate<Result<void>(CLASSDATA* self)>&& startWaitFn, const TimeValue& timerInterval,
	Delegate<void(CLASSDATA* self)>&& timerWaitFn, Delegate<Result<void>(CLASSDATA* self, Error threadError)>&& finalUpdateFunc)
{
	DebugAssert(ThreadRef::IsMainThread());

	iferr_scope;

	/// add proper exit code before the modules will be unloaded
	if (!g_exitObservable)
	{
		g_exitObservable = RunLoop::ObservableExitLoop().AddObserver(
			[]() -> Result<void>
			{
				FreeThreadedStuff();

				if (g_exitObservable)
				{
					// remove from the list, otherwise it crashes because c4d plugins are unloaded earlier.
					iferr (RunLoop::ObservableExitLoop().RemoveObserver(g_exitObservable))
					{
						DiagnosticOutput("@", err);
						DebugStop();
					}
					g_exitObservable = nullptr;
				}

				return OK;
			}) iferr_return;
	}

	// cancel the previous action
	Bool isRunning = Cancel();

	// must not happen because Cancel needs to be called outside
	DebugAssert(isRunning == false);
	UseVariable(isRunning);

	// Copy finalUpdateFunc before moving it into the lambda because it might be required later on (with waitfirstDelay).
	Delegate<Result<void>(CLASSDATA* self, Error threadError)> finalUpdateFuncCopy;
	finalUpdateFuncCopy.CopyFrom(finalUpdateFunc) iferr_return;
	
	// let's wrap the worker thread into a lambda to catch the error and trigger the UI update around
	auto threadfunc =
		[this, threadFn = std::move(threadFn), finalUpdateFunc = std::move(finalUpdateFuncCopy)](CLASSDATA* self) mutable -> Result<void>
		{
			iferr_scope;

			finally
			{
				_scanThread = nullptr;
				if (!g_inShutDown)
				{
					ScopedLock lock(g_freeThreadedStuffLock);
					g_freeThreadedStuff.Erase(this);
				}
			};

			// run the worker thread
			auto res = threadFn(self);

			if (!ThreadRef::IsCurrentThreadCancelled())
			{
				Error error = res.GetError();

				// final UI update
				// enqueue the UI update

				self->_updateJob = JobRef::Enqueue(
					[this, error, finalUpdateFuncI = std::move(finalUpdateFunc)]() mutable -> Result<void>
					{
						_isDone = true;
						_spinningTimer.CancelAndWait();
						_spinningTimer = TimerRef();
						return finalUpdateFuncI((CLASSDATA*)this, error);
					}, JobQueueRef::GetMainThreadQueue()) iferr_return;
			}

			return res;
		};

	// run the worker thread
	JobRef thread = JobRef::Enqueue(std::move(threadfunc), JobQueueRef::GetServiceIOQueue(), (CLASSDATA*)this) iferr_return;

	// use this local ref to get the result later, otherwise it results in a nullptr ref.
	_scanThread = thread;

	auto callback =
		[this, timerInterval, startWaitFn = std::move(startWaitFn), timerWaitFn = std::move(timerWaitFn)]() mutable -> Result<void>
		{
			iferr_scope;

			if (!_isDone)
			{
				// if timerDelay is delayed notify the UI callback
				startWaitFn((CLASSDATA*)this) iferr_return;

				// start a periodic timer for the UI updates
				_spinningTimer = TimerRef::AddPeriodicTimer(timerInterval,
					[this, timerWaitFn = std::move(timerWaitFn)]()
					{
						timerWaitFn((CLASSDATA*)this);
					}, JobQueueRef::GetMainThreadQueue()) iferr_return;
			}
			return OK;
		};

	if (waitFirstDelay)
	{
		if (!_scanThread.Wait(timerDelay, WAITMODE::RETURN_ON_CANCEL))
		{
			callback() iferr_return;
		}
		else
		{
			finalUpdateFunc((CLASSDATA*)this, thread.GetResult().GetError()) iferr_return;
		}
	}
	else
	{
		// wait some milliseconds to load the directory, if not done disable ui
		_spinningTimer = TimerRef::AddOneShotTimer(timerDelay,
			[callback = std::move(callback)]() mutable
			{
				// TODO: (Anybody) The Timer cannot return a result from the lambda. There's no GetResult and no place where a Timer result would be checked.
				iferr (callback())
					err.CritStop();
			},
			JobQueueRef::GetMainThreadQueue()) iferr_return;
	}

	return OK;
}

template <typename CLASSDATA> Bool ThreadedUIUpdate<CLASSDATA>::IsRunning()
{
	return _scanThread && !_scanThread.Wait(Seconds(0));
}

template <typename CLASSDATA> Bool ThreadedUIUpdate<CLASSDATA>::CancelI()
{
	Bool isRunning = _scanThread && !_scanThread.Wait(Seconds(0));

	_scanThread.Cancel();
	_spinningTimer.CancelAndWait();
	_spinningTimer = nullptr;
	_updateJob.Cancel();

	// if the thread is still running we need to keep it in the list.
	if (isRunning)
	{
		ScopedLock lock(g_freeThreadedStuffLock);
		iferr (g_freeThreadedStuff.Append(this))
		{
			// TODO: (Anybody) errro handling
			DebugStop();
		}
	}
	else
	{
		_isDone = false;
	}

	return isRunning;
}

template <typename CLASSDATA> Bool ThreadedUIUpdate<CLASSDATA>::Cancel()
{
	DebugAssert(ThreadRef::IsMainThread());
	return CancelI();
}

template <typename CLASSDATA> void ThreadedUIUpdate<CLASSDATA>::Wait()
{
	_scanThread.CancelAndWait();
}

}

#endif // THREADED_UPDATE_HELPER_H__
