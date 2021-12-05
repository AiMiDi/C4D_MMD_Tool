#ifndef SPINLOCK_H__
#define SPINLOCK_H__

#include "maxon/atomictypes.h"
#include "maxon/cpuyield.h"

namespace maxon
{

/// @addtogroup THREADING Threading
/// @{

extern Bool g_trackSpinlocks;

namespace details
{

struct BaseLock
{
	BaseLock()
	{
		DebugAssert((UInt(&_state) & 3) == 0, "_state must be on a native boundary");
	}

	~BaseLock()
	{
		CriticalAssert(_state.LoadRelaxed() == 0, "The CoreLock is still set while being destructed.");
	}

protected:
	//----------------------------------------------------------------------------------------
	/// Notifies a profiler of a spin loop.
	//----------------------------------------------------------------------------------------
	void PerformanceMonitorSpin() const;

	//----------------------------------------------------------------------------------------
	/// Notifies a profiler of an acquired lock.
	//----------------------------------------------------------------------------------------
	void PerformanceMonitorLockAcquired() const;

	//----------------------------------------------------------------------------------------
	/// Notifies a profiler of the unlock.
	//----------------------------------------------------------------------------------------
	void PerformanceMonitorLockReleased() const;

protected:
	AtomicInt32 _state;
};

}

//----------------------------------------------------------------------------------------
/// The Spinlock class implements a mutex that will loop on a pause/idle instruction when it
/// is already locked. This means you should only use a Spinlock for cases with almost no
/// contention - otherwise you waste a lot of CPU power with idling and steal that from
/// other tasks (and your battery).
/// If your problem produces a lot of contention (check scaling with more than 8 threads or
/// profile with VTune/Instruments) it's most likely worth to rethink your approach and
/// algorithm.
///
/// THREADSAFE.
//----------------------------------------------------------------------------------------
struct Spinlock : protected maxon::details::BaseLock
{
	//----------------------------------------------------------------------------------------
	/// Tries to lock. Creates a memory barrier if the lock can be taken.
	/// If the application has crashed and is in crash dump mode you may never be able to
	/// acquire a lock when it was already locked when the crash occurred.
	/// <B> Do not spin on AttemptLock(), always use Lock() because it consumes less resources
	/// and is much faster! </B>
	/// THREADSAFE.
	/// @return												True if successful.
	//----------------------------------------------------------------------------------------
	inline Bool AttemptLock()
	{
		Bool isLocked = CoreAttemptLock();
		
		if (MAXON_UNLIKELY(g_trackSpinlocks && isLocked))
			PerformanceMonitorLockAcquired();
		
		return isLocked;
	}

	//----------------------------------------------------------------------------------------
	/// Locks a user level spin lock. As long as the lock cannot be taken an exponential
	/// backoff pause loop is used to wait. Creates a memory barrier.
	/// If the application has crashed and is in crash dump mode the state of the lock
	/// will be ignored to avoid unwanted deadlocks in the crash log code.
	/// THREADSAFE.
	//----------------------------------------------------------------------------------------
	inline void Lock()
	{
		// SpinAndRetry() will notify the profiler if there is contention and AttemptLock() has failed
		if (MAXON_UNLIKELY(AttemptLock() == false))
			SpinAndRetry();
	}

	//----------------------------------------------------------------------------------------
	/// Unlocks a user level spin lock. Creates a memory barrier.
	/// THREADSAFE.
	//----------------------------------------------------------------------------------------
	inline void Unlock()
	{
		// Notify the profiler of the unlock if there was contention.
		if (MAXON_UNLIKELY(g_trackSpinlocks))
			PerformanceMonitorLockReleased();

		CoreUnlock();
	}

	//----------------------------------------------------------------------------------------
	/// Returns true if locked or false if unlocked (<b>for diagnostics only</b>).
	/// THREADSAFE.
	/// @return												True if locked, false if unlocked.
	//----------------------------------------------------------------------------------------
	inline Bool	IsLocked() const
	{
		return _state.LoadAcquire() != 0;
	}

protected:
	//----------------------------------------------------------------------------------------
	/// Tries to lock. Creates a memory barrier if the lock can be taken.
	/// If the application has crashed and is in crash dump mode you may never be able to
	/// acquire a lock when it was already locked when the crash occurred.
	/// THREADSAFE.
	/// @return												True if successful.
	//----------------------------------------------------------------------------------------
	inline Bool CoreAttemptLock()
	{
		return MAXON_LIKELY(_state.TryCompareAndSwap(1, 0));
	}

	//----------------------------------------------------------------------------------------
	/// Locks a user level spin lock. As long as the lock cannot be taken an exponential
	/// backoff pause loop is used to wait. Creates a memory barrier.
	/// THREADSAFE.
	//----------------------------------------------------------------------------------------
	inline void CoreLock()
	{
		if (MAXON_UNLIKELY(CoreAttemptLock() == false))
			CoreSpinAndRetry();
	}

	//----------------------------------------------------------------------------------------
	/// Unlocks a user level spin lock. Creates a memory barrier.
	/// THREADSAFE.
	//----------------------------------------------------------------------------------------
	inline void CoreUnlock()
	{
		// Create a memory barrier and unlock.
		_state.StoreRelease(0);
	}

	//----------------------------------------------------------------------------------------
	/// Spins on a volatile read using an exponential backoff pause loop until _state is zero
	/// and CAS will be tried.
	/// If the application has crashed and is in crash dump mode the state of the lock
	/// will be ignored to avoid unwanted deadlocks in the crash log code.
	//----------------------------------------------------------------------------------------
	void CoreSpinAndRetry();

private:
	//----------------------------------------------------------------------------------------
	/// Spins on a volatile read using an exponential backoff pause loop until _state is zero
	/// and CAS will be tried.
	/// If the application has crashed and is in crash dump mode the state of the lock
	/// will be ignored to avoid unwanted deadlocks in the crash log code.
	/// Optionally notifies the profiler that this thread begins spinning because there is contention.
	//----------------------------------------------------------------------------------------
	void SpinAndRetry();
};

//----------------------------------------------------------------------------------------
/// The RWSpinlock class implements a mutex that allows access of multiple readers or one
/// exclusive writer. It will loop on a pause/idle instruction when it is already locked.
/// This means you should only use a RWSpinlock for cases with almost no contention -
/// otherwise you waste a lot of CPU power with idling and steal that from other tasks
/// (and your battery).
/// Having many concurrent readers may also noticably degrade performance because the lock
/// is a shared resource and each read lock from a different thread will cause a write
/// access to the RWSpinlock and requires synchronization of the CPU cores.
/// If your problem produces a lot of contention (check scaling with more than 8 threads or
/// profile with VTune/Instruments) it's most likely worth to rethink your approach and
/// algorithm.
/// Use ARWLock for high read to write ratios.
///
/// THREADSAFE.
//----------------------------------------------------------------------------------------
struct RWSpinlock : protected maxon::details::BaseLock
{
	//----------------------------------------------------------------------------------------
	/// Read locks a user level spin lock. Will force synchronization when multiple readers
	/// are pending: Does not scale! Creates a memory barrier.
	/// If a write is pending an exponential backoff pause loop is used to wait.
	/// THREADSAFE.
	//----------------------------------------------------------------------------------------
	void ReadLock();

	//----------------------------------------------------------------------------------------
	/// Balances a preceding ReadLock() when the reading thread has finished.
	/// THREADSAFE.
	//----------------------------------------------------------------------------------------
	void ReadUnlock();

	//----------------------------------------------------------------------------------------
	/// Write locks a user level spin lock. As long as there are pending readers an exponential
	/// backoff pause loop is used to wait. Creates a memory barrier.
	/// THREADSAFE.
	//----------------------------------------------------------------------------------------
	void WriteLock();

	//----------------------------------------------------------------------------------------
	/// Balances a preceding WriteLock() when the writing thread has finished.
	/// Creates a memory barrier.
	/// THREADSAFE.
	//----------------------------------------------------------------------------------------
	void WriteUnlock();

	//----------------------------------------------------------------------------------------
	/// Tries to write lock. Creates a memory barrier if the lock can be taken.
	/// Immediately returns with false if there are pending reads or writes.
	/// @return												True if successful.
	/// THREADSAFE.
	//----------------------------------------------------------------------------------------
	Bool AttemptWriteLock();

	//----------------------------------------------------------------------------------------
	/// Returns true if read-locked or false if unlocked (<b>for diagnostics only</b>).
	/// THREADSAFE.
	/// @return												True if locked, false if unlocked.
	//----------------------------------------------------------------------------------------
	Bool IsReadLocked() const;

	//----------------------------------------------------------------------------------------
	/// Returns true if write-locked or false if unlocked (<b>for diagnostics only</b>).
	/// THREADSAFE.
	/// @return												True if locked, false if unlocked.
	//----------------------------------------------------------------------------------------
	Bool IsWriteLocked() const;
};

static_assert(sizeof(Spinlock) == 4, "wrong Spinlock size");
static_assert(sizeof(RWSpinlock) == 4, "wrong RWSpinlock size");


//----------------------------------------------------------------------------------------
/// The ScopedLock class acquires a lock to the specified mutex upon creation and releases
/// this upon destruction (usually at the end of a code block).
/// This simplifies cases where your code contains many return statements where you'd otherwise
/// have to manually unlock before returning.
/// <B> Only use ScopedLock for a short block of your code. Do not use ScopedLock mindlessly
/// at the beginning of a function! This will block all other threads for the whole runtime
/// of the function which usually is much longer that required. </B>
///
/// THREADSAFE.
/// @see SpinLock
//----------------------------------------------------------------------------------------
class ScopedLock
{
	MAXON_DISALLOW_COPY_AND_ASSIGN(ScopedLock);

public:
	//----------------------------------------------------------------------------------------
	/// Acquires the specified lock (and releases it upon destruction).
	/// @param[in] lock								The lock to be acquired.
	//----------------------------------------------------------------------------------------
	explicit ScopedLock(Spinlock& lock)
	{
		_lock = &lock;
		_lock->Lock();
	}

	//----------------------------------------------------------------------------------------
	/// Move constructor.
	//----------------------------------------------------------------------------------------
	ScopedLock(ScopedLock&& src)
	{
		_lock = src._lock;
		src._lock = nullptr;
	}

	//----------------------------------------------------------------------------------------
	/// Releases the lock on destruction.
	//----------------------------------------------------------------------------------------
	~ScopedLock()
	{
		if (_lock)
			_lock->Unlock();
	}

private:
	Spinlock*	_lock;
};


//----------------------------------------------------------------------------------------
/// A ScopedLockPair acquires locks to two specified mutexes upon creation and releases
/// them upon destruction (usually at the end of a code block). You should use this
/// instead of two ScopedLock objects to avoid deadlocks: With two separate ScopedLock
/// objects one thread could lock A and then try to lock B, while another thread could
/// lock B and then try to lock A, resulting in a deadlock. ScopedLockPair avoids this
/// by always locking the mutex with lower memory address at first.
///
/// @see SpinLock
/// @see ScopedLock
//----------------------------------------------------------------------------------------
class ScopedLockPair
{
	MAXON_DISALLOW_COPY_AND_ASSIGN(ScopedLockPair);

public:
	ScopedLockPair(Spinlock& lock1, Spinlock& lock2)
	{
		if (&lock1 < &lock2)
		{
			_lock1 = &lock1;
			_lock2 = &lock2;
		}
		else
		{
			_lock1 = &lock2;
			_lock2 = (&lock1 == &lock2) ? nullptr : &lock1;
		}
		// TODO: (Anybody) Use AttemptLock loop. This is prone to deadlocks!!!
		_lock1->Lock();
		if (_lock2)
			_lock2->Lock();
	}

	ScopedLockPair(ScopedLockPair&& src) : MAXON_MOVE_MEMBERS(_lock1, _lock2)
	{
		src._lock1 = nullptr;
		src._lock2 = nullptr;
	}

	~ScopedLockPair()
	{
		if (_lock1)
			_lock1->Unlock();
		if (_lock2)
			_lock2->Unlock();
	}

private:
	Spinlock*	_lock1;
	Spinlock*	_lock2;
};

//----------------------------------------------------------------------------------------
/// The ScopedReadLock class acquires a read lock to the specified mutex upon creation and
/// releases this upon destruction (usually at the end of a code block.
/// This simplifies cases where your code contains many return statements where you'd otherwise
/// have to manually unlock before returning.
/// <B> Only use ScopedReadLock for a short block of your code. </B>
///
/// THREADSAFE.
//----------------------------------------------------------------------------------------
class ScopedReadLock
{
	MAXON_DISALLOW_COPY_AND_ASSIGN(ScopedReadLock);

public:
	//----------------------------------------------------------------------------------------
	/// Acquires read access to the specified lock (and releases it upon destruction).
	/// @param[in] lock								The lock to be acquired.
	//----------------------------------------------------------------------------------------
	explicit ScopedReadLock(RWSpinlock& lock)
	{
		_lock = &lock;
		_lock->ReadLock();
	}

	//----------------------------------------------------------------------------------------
	/// Move constructor.
	//----------------------------------------------------------------------------------------
	ScopedReadLock(ScopedReadLock&& src)
	{
		_lock = src._lock;
		src._lock = nullptr;
	}

	//----------------------------------------------------------------------------------------
	/// Releases the lock on destruction.
	//----------------------------------------------------------------------------------------
	~ScopedReadLock()
	{
		if (_lock)
			_lock->ReadUnlock();
	}

private:
	RWSpinlock*	_lock;
};

//----------------------------------------------------------------------------------------
/// The ScopedWriteLock class acquires a write lock to the specified mutex upon creation and
/// releases this upon destruction (usually at the end of a code block.
/// This simplifies cases where your code contains many return statements where you'd otherwise
/// have to manually unlock before returning.
/// <B> Only use ScopedWriteLock for a short block of your code. Do not use ScopedWriteLock mindlessly
/// at the beginning of a function! This will block all other threads for the whole runtime
/// of the function which usually is much longer that required. </B>
///
/// THREADSAFE.
//----------------------------------------------------------------------------------------
class ScopedWriteLock
{
	MAXON_DISALLOW_COPY_AND_ASSIGN(ScopedWriteLock);

public:
	//----------------------------------------------------------------------------------------
	/// Acquires write access to the specified lock (and releases it upon destruction).
	/// @param[in] lock								The lock to be acquired.
	//----------------------------------------------------------------------------------------
	explicit ScopedWriteLock(RWSpinlock& lock)
	{
		_lock = &lock;
		_lock->WriteLock();
	}

	//----------------------------------------------------------------------------------------
	/// Move constructor.
	//----------------------------------------------------------------------------------------
	ScopedWriteLock(ScopedWriteLock&& src)
	{
		_lock = src._lock;
		src._lock = nullptr;
	}

	//----------------------------------------------------------------------------------------
	/// Releases the lock on destruction.
	//----------------------------------------------------------------------------------------
	~ScopedWriteLock()
	{
		if (_lock)
			_lock->WriteUnlock();
	}

private:
	RWSpinlock*	_lock;
};

/// @}

} // namespace maxon

#endif // SPINLOCK_H__
