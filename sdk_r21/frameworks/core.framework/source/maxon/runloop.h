#ifndef RUNLOOP_H__
#define RUNLOOP_H__

#include "maxon/apibase.h"
#include "maxon/observerobject.h"
#include "maxon/timevalue.h"

namespace maxon
{

//----------------------------------------------------------------------------------------
/// Run loop interface.
/// Use this interface to implement an application UI event run loop. Usually there already
/// is a default implementation, but there might be cases where different UI toolkits are
/// available for a system. Depending on the project's requirements the adequate one can
/// be selected (via command line or project option). Only one run loop will be active
/// for the run time of an application.
//----------------------------------------------------------------------------------------
class RunLoop
{
	MAXON_INTERFACE_NONVIRTUAL(RunLoop, MAXON_REFERENCE_NONE, "net.maxon.interface.runloop");

public:
	using TimerCallback = void (*)(void* self);
	class Timer;

	//----------------------------------------------------------------------------------------
	/// Enters the main thread run loop.
	/// Returns IllegalArgumentError if there's no run loop. Errors returned by subscribers
	/// to ObservableExitLoop() will be returned as AggregatedError.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<void> EnterLoop();

	//----------------------------------------------------------------------------------------
	/// Asks the main thread run loop to exit.
	/// THREADSAFE.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD void ExitLoop();

	//----------------------------------------------------------------------------------------
	/// Notifies the main thread event loop that it should execute jobs.
	/// THREADSAFE.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD void TriggerMainThreadQueue();

	//----------------------------------------------------------------------------------------
	/// Schedules a job to be called periodically at the specified interval on the main thread.
	/// If the interval is 0.0 the timer is fired once after the specified delay.
	/// For each AddTimer() call you must call RemoveTimer() to remove it. Otherwise the timer
	/// runs forever or (for a one-shot timer) at least its memory will leak.
	/// If the run loop does not support timers a nullptr is returned (this is not an error).
	/// In this case the timer implementation has to enqueue jobs on the main thread (which is
	/// less efficient but works).
	/// @param[in] interval						Timer interval.
	/// @param[in] delay							Delay until the timer fires the first time.
	/// @param[in] tolerance					Maximum tolerance of execution (used for timer coalescing).
	/// @param[in] callback						To be called by the timer (periodically).
	/// @param[in] self								Pointer to callback data.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<Timer*> AddTimer(TimeValue interval, TimeValue delay, TimeValue tolerance, TimerCallback callback, void* self);

	//----------------------------------------------------------------------------------------
	/// Removes a timer created with AddTimer.
	/// @param[in] timer							Timer interval.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD void RemoveTimer(Timer* timer);

	//----------------------------------------------------------------------------------------
	/// Returns the default display for the Linux runloop.
	/// @param[out] display						A reference which will hold the display pointer. The pointer can be cast to Display.
	/// @param[out] screen						The screen.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD void GetLinuxDefaultDisplayAndScreen(void*& display, int& screen);

	//----------------------------------------------------------------------------------------
	/// Notifies the observers that the run loop will exit.
	//----------------------------------------------------------------------------------------
	MAXON_OBSERVABLE_STATIC(Result<void>, ObservableExitLoop, (), ObservableCombinerRunAllAggregateErrorsComponent);

	//----------------------------------------------------------------------------------------
	/// Notifies the observers that the application changes from active to inactive.
	//----------------------------------------------------------------------------------------
	MAXON_OBSERVABLE_STATIC(Result<void>, ObservableActivationChange, (Bool becomesActive), ObservableCombinerRunAllAggregateErrorsComponent);

	//----------------------------------------------------------------------------------------
	/// Invokes the observer(s) with a pointer to the current event. The observer might return
	/// true if it already handled the event and it should be discarded.
	/// @note This observable is OS-specific and may only be used to work around bugs or
	/// shortcomings in UI toolkits/window managers. I must not be used for regular event
	/// handling or forwarding. Linux & Windows only.
	/// @MAXON_ANNOTATION{methodId="ObservableRunLoopMessage@9ba6ca3be948710f"->"ObservableFilterSystemMessage@480253946227dfeb"}
	//----------------------------------------------------------------------------------------
	MAXON_OBSERVABLE_STATIC(Bool, ObservableRunLoopMessage, (const void* message), ObservableCombinerRunAllBoolUntilTrue);

	// for legacy c4d, Windows only
	static MAXON_METHOD void** PrivateGetMainThreadQueueTrigger();
	static MAXON_METHOD void PrivateSetWaitInterval(TimeValue waitInterval);
	// for legacy C4D, Linux only
	static MAXON_METHOD void PrivateSetDefaultDisplayAndScreen(void* display, int screen);
};

// include autogenerated headerfile here
#include "runloop1.hxx"
// include autogenerated headerfile here
#include "runloop2.hxx"

}

#endif // RUNLOOP_H__
