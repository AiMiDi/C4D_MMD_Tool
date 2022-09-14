#include "maxon/spinlock.h"
#include "maxon/configuration.h"
#include "maxon/crashhandlerglobals.h"

namespace maxon
{

/// Enable g_trackSpinlocks to search for deadlocks or detect locks which are spinning longer than intended.
/// If you are only interested in your module you can locally assign true to g_trackSpinlocks instead of enabling
/// the configuration globally for the whole application.
/// You can tweak the detection with the configuration variables g_trackSpinlockAcquireThreshold and g_trackSpinBacktrace.
/// g_trackSpinlockAcquireThreshold will track locks which were acquired longer than the threshold (in ns) even if there was
/// no spinning (off by default). If there was spinning before acquire the lock will be tracked anyway.
/// g_trackSpinBacktrace is the number of backtrace entries that will be logged when something is spinning (15 by default).
MAXON_CONFIGURATION_BOOL(g_trackSpinlocks, false, CONFIGURATION_CATEGORY::DEVELOPMENT, "Track usage of Spinlocks (either for performance checks or deadlock detection)");

namespace details
{

//----------------------------------------------------------------------------------------
/// Notifies a profiler of an acquired lock.
//----------------------------------------------------------------------------------------
void BaseLock::PerformanceMonitorLockAcquired() const
{
	// g_CpuYieldDelegate is guaranteed to be valid.
	g_CpuYieldDelegate((CpuYieldState*) CpuYieldState::LOCK_ACQUIRE, this);
}

//----------------------------------------------------------------------------------------
/// Notifies a profiler of the unlock.
//----------------------------------------------------------------------------------------
void BaseLock::PerformanceMonitorLockReleased() const
{
	// g_CpuYieldDelegate is guaranteed to be valid.
	g_CpuYieldDelegate((CpuYieldState*) CpuYieldState::LOCK_RELEASE, this);
}

}

//----------------------------------------------------------------------------------------
/// Spins on a read using an exponential backoff pause loop until _state is zero
/// and CAS will be tried.
/// Optionally notifies the profiler that this thread begins spinning because there is contention.
//----------------------------------------------------------------------------------------
void Spinlock::SpinAndRetry()
{
	CoreSpinAndRetry();

	if (MAXON_UNLIKELY(g_trackSpinlocks))
		PerformanceMonitorLockAcquired();
}

//----------------------------------------------------------------------------------------
/// Spins on a volatile read using an exponential backoff pause loop until _state is zero
/// and CAS will be tried.
/// If the application has crashed and is in crash dump mode the state of the lock
/// will be ignored to avoid unwanted deadlocks in the crash log code.
//----------------------------------------------------------------------------------------
void Spinlock::CoreSpinAndRetry()
{
	CpuYield wait(this);

	// Assume single threaded mode if the application is crashed.
	if (CrashHandlerGlobals::IsCrashed())
		return;

	do
	{
		Int32 currentState;

		// spin on read because it consumes less resources
		while ((currentState = _state.LoadConsume()) != 0)
		{
			DebugAssert(currentState == 0 || currentState == 1 || currentState == -1, "Spinlock memory was corrupted");
			wait.Pause();
		}

		// set _state to -1 to to signalize that there was contention
	} while (_state.TryCompareAndSwap(-1, 0) == false);
}


using RWState = Int32;
static const RWState	WRITER = 1;
static const RWState	WRITER_PENDING = 2;
static const RWState	READERS = ~(WRITER | WRITER_PENDING);
static const RWState	ONE_READER = 4;
static const RWState	BUSY = WRITER | READERS;

// Bit 0 = writer is holding lock
// Bit 1 = request by a writer to acquire lock (hint to readers to wait)
// Bit 2..N = number of readers holding lock

Bool RWSpinlock::IsReadLocked() const
{
	return (_state.LoadConsume() & READERS) != 0;
}

Bool RWSpinlock::IsWriteLocked() const
{
	return (_state.LoadConsume() & WRITER) != 0;
}

void RWSpinlock::ReadLock()
{
	CpuYield wait(this);

	while (true)
	{
		RWState s = _state.LoadConsume();
		// no writer or write requests?
		if ((s & (WRITER | WRITER_PENDING)) == 0)
		{
			// successfully stored increased number of readers?
			if (_state.TryCompareAndSwap(s + ONE_READER, s))
				break;

			// we could be very close to complete op.
			wait.Reset();
		}
		wait.Pause();
	}

	if (MAXON_UNLIKELY(g_trackSpinlocks))
		PerformanceMonitorLockAcquired();
}

void RWSpinlock::ReadUnlock()
{
	DebugAssert(_state.LoadConsume() & READERS, "RWSpinlock was not read locked");
	_state.SwapAdd(-((Int32) ONE_READER));

	if (MAXON_UNLIKELY(g_trackSpinlocks))
		PerformanceMonitorLockReleased();
}

void RWSpinlock::WriteLock()
{
	CpuYield wait(this);

	while (true)
	{
		RWState s = _state.LoadConsume();

		// no readers, no writers?
		if ((s & BUSY) == 0)
		{
			// successfully stored writer flag?
			if (_state.TryCompareAndSwap(WRITER, s))
				break;

			// we could be very close to complete op.
			wait.Reset();
		}
		else if ((s & WRITER_PENDING) == 0) // no pending writers
		{
			_state.SwapOr(WRITER_PENDING);
		}
		wait.Pause();
	}

	if (MAXON_UNLIKELY(g_trackSpinlocks))
		PerformanceMonitorLockAcquired();
}

Bool RWSpinlock::AttemptWriteLock()
{
	RWState s = _state.LoadConsume();

	// has readers or writers?
	if (s & BUSY)
		return false;

	// return true if successfully stored writer flag
	Bool res = _state.TryCompareAndSwap(WRITER, s) != 0;

	if (MAXON_UNLIKELY(res && g_trackSpinlocks))
		PerformanceMonitorLockAcquired();

	return res;
}

void RWSpinlock::WriteUnlock()
{
	DebugAssert(_state.LoadConsume() & WRITER, "RWSpinlock was not write locked");

	// create a memory barrier and unlock
	_state.StoreRelease(0);

	if (MAXON_UNLIKELY(g_trackSpinlocks))
		PerformanceMonitorLockReleased();
}

} // namespace maxon
