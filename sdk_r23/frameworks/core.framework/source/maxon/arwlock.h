#ifndef ARWLOCK_H__
#define ARWLOCK_H__

#include "maxon/lockservices.h"

namespace maxon
{

class ARWArray;
struct Spinlock;

//----------------------------------------------------------------------------------------
/// The ARWLock class implements an asymmetric read write lock. It's a mutex that allows
/// access of multiple readers or one exclusive writer. The readers are preferred and the
/// writes are slower. The read to write ratio should at least be 10 : 1, with more writes
/// its only marginally faster or even slower than a RWSpinlock.
///
/// In contrast to RWSpinlock this scales when multiple readers are locking and performance
/// does not degrade. This comes at the cost of a slightly higher overhead and more memory
/// (about 128 to 256 bytes are used for the ARWLock, depending on the number of threads).
///
/// THREADSAFE.
//----------------------------------------------------------------------------------------
class ARWLock
{
	// Locks cannot be moved or copied for safety reasons.
	MAXON_DISALLOW_COPY_AND_ASSIGN(ARWLock);

public:
	ARWLock()
	{
		LockServices::AllocRWLockSlot(this);
	}

	~ARWLock()
	{
		LockServices::FreeRWLockSlot(this);
	}

	//----------------------------------------------------------------------------------------
	/// Read locks a user level spin lock. Does not trash other thread's cache lines or force
	/// synchronization. If a write is pending an exponential backoff pause loop is used to wait.
	/// Creates a memory barrier.
	/// THREADSAFE.
	//----------------------------------------------------------------------------------------
	void ReadLock()
	{
		LockServices::ARWReadLock(this);
	}

	//----------------------------------------------------------------------------------------
	/// Balances a preceding ReadLock() when the reading thread has finished.
	/// Creates a memory barrier.
	/// THREADSAFE.
	//----------------------------------------------------------------------------------------
	void ReadUnlock()
	{
		LockServices::ARWReadUnlock(this);
	}

	//----------------------------------------------------------------------------------------
	/// Write locks a user level spin lock. As long as there are pending readers an exponential
	/// backoff pause loop is used to wait. Creates a memory barrier.
	/// THREADSAFE.
	//----------------------------------------------------------------------------------------
	void WriteLock()
	{
		LockServices::ARWWriteLock(this);
	}

	//----------------------------------------------------------------------------------------
	/// Balances a preceding WriteLock() when the writing thread has finished.
	/// Creates a memory barrier.
	/// THREADSAFE.
	//----------------------------------------------------------------------------------------
	void WriteUnlock()
	{
		LockServices::ARWWriteUnlock(this);
	}

	//----------------------------------------------------------------------------------------
	/// Tries to write lock. Creates a memory barrier if the lock can be taken.
	/// Immediately returns with false if there are pending reads or writes.
	/// @return												True if successful.
	/// THREADSAFE.
	//----------------------------------------------------------------------------------------
	MAXON_WARN_UNUSED Bool AttemptWriteLock()
	{
		return LockServices::ARWAttemptWriteLock(this);
	}

private:
	ARWArray* _reader;
	Int16 _readerIndex;
	Int16 _readerOffset;
	UChar	_readerSetMask;
	UChar	_readerClearMask;
	Int16 _dummy;
	Spinlock*	_writer;
};

//----------------------------------------------------------------------------------------
/// The ScopedARWReadLock class acquires a read lock to the specified mutex upon creation and
/// releases this upon destruction (usually at the end of a code block.
/// This simplifies cases where your code contains many return statements where you'd otherwise
/// have to manually unlock before returning.
/// <B> Only use ScopedARWReadLock for a short block of your code. Do not use ScopedARWReadLock mindlessly
/// at the beginning of a function! This will block all other threads for the whole runtime
/// of the function which usually is much longer that required. </B>
///
/// THREADSAFE.
//----------------------------------------------------------------------------------------
class ScopedARWReadLock
{
	MAXON_DISALLOW_COPY_AND_ASSIGN(ScopedARWReadLock);

public:
	explicit ScopedARWReadLock(ARWLock& lock)
	{
		_lock = &lock;
		_lock->ReadLock();
	}

	ScopedARWReadLock(ScopedARWReadLock&& src)
	{
		_lock = src._lock;
		src._lock = nullptr;
	}

	~ScopedARWReadLock()
	{
		if (_lock)
			_lock->ReadUnlock();
	}

private:
	ARWLock* _lock;
};

//----------------------------------------------------------------------------------------
/// The ScopedARWWriteLock class acquires a write lock to the specified mutex upon creation and
/// releases this upon destruction (usually at the end of a code block.
/// This simplifies cases where your code contains many return statements where you'd otherwise
/// have to manually unlock before returning.
/// <B> Only use ScopedARWWriteLock for a short block of your code. Do not use ScopedARWWriteLock mindlessly
/// at the beginning of a function! This will block all other threads for the whole runtime
/// of the function which usually is much longer that required. </B>
///
/// THREADSAFE.
//----------------------------------------------------------------------------------------
class ScopedARWWriteLock
{
	MAXON_DISALLOW_COPY_AND_ASSIGN(ScopedARWWriteLock);

public:
	explicit ScopedARWWriteLock(ARWLock& lock)
	{
		_lock = &lock;
		_lock->WriteLock();
	}

	ScopedARWWriteLock(ScopedARWWriteLock&& src)
	{
		_lock = src._lock;
		src._lock = nullptr;
	}

	~ScopedARWWriteLock()
	{
		if (_lock)
			_lock->WriteUnlock();
	}

private:
	ARWLock* _lock;
};

}

#endif // ARWLOCK_H__
