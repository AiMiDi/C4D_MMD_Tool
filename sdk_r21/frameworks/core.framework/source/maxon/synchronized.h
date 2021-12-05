#ifndef SYNCHRONIZED_H__
#define SYNCHRONIZED_H__

#include "maxon/apibase.h"
#include "maxon/spinlock.h"

namespace maxon
{

//----------------------------------------------------------------------------------------
/// Provides a generalized interface to lock operations.
/// LockTraits can be specialized for any lock implementation to add support for synchronized().
//----------------------------------------------------------------------------------------
template <typename LOCKTYPE>
struct LockTraits
{
	static void AcquireReadLock(LOCKTYPE& lock)		{ lock.ReadLock(); }

	static void ReleaseReadLock(LOCKTYPE& lock)		{ lock.ReadUnlock(); }

	static void AcquireWriteLock(LOCKTYPE& lock)	{ lock.WriteLock(); }

	static void ReleaseWriteLock(LOCKTYPE& lock)	{ lock.WriteUnlock(); }
};

template <>
struct LockTraits<Spinlock>
{
	static void AcquireReadLock(Spinlock& lock)		{ lock.Lock(); }
	static void ReleaseReadLock(Spinlock& lock)		{ lock.Unlock(); }
	static void AcquireWriteLock(Spinlock& lock)	{ lock.Lock(); }
	static void ReleaseWriteLock(Spinlock& lock)	{ lock.Unlock(); }
};


//----------------------------------------------------------------------------------------
/// A SynchronizedValue<T, LOCKTYPE> stores a value of type T, protected by a lock of type LOCKTYPE.
/// Aliases exist for the common lock types, so SynchronizedValue should not be used directly.
/// Instead, use Synchronized<T> (Spinlock), RWSynchronized<T> (ARWLock).
/// 
/// Access to the value is enabled through the Read() and Write() functions.
/// If possible, prefer using Synchronized over manually pairing locks with values, because there's less room for mistakes.
/// 
/// @tparam T											Type of the contained value.
/// @tparam LOCKTYPE							Type of the lock value.
//----------------------------------------------------------------------------------------
template <typename T, typename LOCKTYPE>
class SynchronizedValue
{
private:
	template <typename U>
	SynchronizedValue(const SynchronizedValue& src, U&&) : _value(src._value) { }

	template <typename U>
	SynchronizedValue(SynchronizedValue&& src, U&&) : _value(std::move(src._value)) { }

public:
	using ValueType = T;
	using LockType  = LOCKTYPE;

	class LockedWritePtr;
	class LockedReadPtr;

	//----------------------------------------------------------------------------------------
	/// Default constructor. Creates an Synchronized with a default constructed value.
	//----------------------------------------------------------------------------------------
	SynchronizedValue() = default;

	//----------------------------------------------------------------------------------------
	/// Copy-from-value constructor.
	/// Initializes the contained value with a copy of v.
	//----------------------------------------------------------------------------------------
	explicit SynchronizedValue(const T& v) : _value(v) { }

	//----------------------------------------------------------------------------------------
	/// Move-from-value constructor.
	/// Initializes the contained value by moving from v.
	//----------------------------------------------------------------------------------------
	explicit SynchronizedValue(T&& v) : _value(std::move(v)) { }

	//----------------------------------------------------------------------------------------
	/// Emplace constructor.
	/// Constructs the contained value in-place with given arguments, i.e. T thisValue(std::forward<ARGS>(args) ...).
	/// For complex types that cannot be moved or copied.
	//----------------------------------------------------------------------------------------
	template <typename ... ARGS> explicit SynchronizedValue(IN_PLACE_TYPE, ARGS&& ... args) : _value(std::forward<ARGS>(args) ...) { }

	//----------------------------------------------------------------------------------------
	/// Copy constructor.
	/// Initializes the contained value with a copy of the value of src. src is locked for reading during the operation.
	//----------------------------------------------------------------------------------------
	SynchronizedValue(const typename std::conditional<TestForCopyFromMember<T>::isSupported, DummyParamType, SynchronizedValue>::type& src) : SynchronizedValue(src, LockedReadPtr(src)) { }

	//----------------------------------------------------------------------------------------
	/// Move constructor.
	/// Initializes the contained value by moving from the value of src. src is locked for writing during the operation.
	//----------------------------------------------------------------------------------------
	SynchronizedValue(SynchronizedValue&& src) : SynchronizedValue(std::move(src), LockedWritePtr(src)) { }

	//----------------------------------------------------------------------------------------
	/// Copy assignment.
	/// Assigns the contained value to a copy of the value of src. During this operation, this is locked for writing and src is locked for reading.
	//----------------------------------------------------------------------------------------
	SynchronizedValue& operator =(const typename std::conditional<TestForCopyFromMember<T>::isSupported, DummyParamType, SynchronizedValue>::type& src)
	{
		if (this == &src)
		{
			// Do nothing
		}
		else if (this < &src)
		{
			LockedWritePtr	sc1(*this);
			LockedReadPtr		sc2(src);
			_value = src._value;
		}
		else
		{
			LockedReadPtr		sc2(src);
			LockedWritePtr	sc1(*this);
			_value = src._value;
		}
		return *this;
	}

	Result<void> CopyFrom(const typename std::conditional<TestForCopyFromMember<T>::isSupported, SynchronizedValue, DummyParamType>::type& src)
	{
		if (this == &src)
		{
			// Do nothing
			return OK;
		}
		else if (this < &src)
		{
			LockedWritePtr	sc1(*this);
			LockedReadPtr		sc2(src);
			return _value.CopyFrom(src._value);
		}
		else
		{
			LockedReadPtr		sc2(src);
			LockedWritePtr	sc1(*this);
			return _value.CopyFrom(src._value);
		}
	}

	//----------------------------------------------------------------------------------------
	/// Move assignment.
	/// Assigns the contained value by moving from the value of src. During this operation, this and src are locked for writing.
	//----------------------------------------------------------------------------------------
	SynchronizedValue& operator =(SynchronizedValue&& src)
	{
		if (this == &src)
		{
			// Do nothing
		}
		else if (this < &src)
		{
			LockedWritePtr	sc1(*this);
			LockedWritePtr	sc2(src);
			_value = std::move(src._value);
		}
		else
		{
			LockedWritePtr	sc2(src);
			LockedWritePtr	sc1(*this);
			_value = std::move(src._value);
		}
		return *this;
	}

	//----------------------------------------------------------------------------------------
	/// Returns a locked write pointer to the synchronized value.
	/// On creation, the respective lock is acquired. This may involve waiting, if the lock is already taken.
	/// During the lifetime of the pointer, the lock remains taken. The synchronized value can be accessed through the pointer.
	/// On destruction, the lock is released.
	///
	/// Example:
	/// @code
	/// Synchronized<String> v;
	/// // ...
	/// *v.Write() = "Hello"_s;
	/// DiagnosticOutput("@", *v);
	/// v.Write()->Flush();
	/// @endcode
	///
	/// Note that for each temporary pointer, the lock is acquired and released again.
	/// You may also store the locked pointer to chain multiple operations:
	/// @code
	/// Synchronized<BaseArray<Int>> v;
	/// // ...
	/// MAXON_SCOPE
	/// {
	///		auto p = v.Write();
	///		p->Append(1) iferr_return;
	///		p->Append(2) iferr_return;
	/// }
	/// @endcode
	/// This is equivalent to using @c ScopedLock.
	//----------------------------------------------------------------------------------------
	LockedWritePtr Write()
	{
		return LockedWritePtr(*this);
	}

	//----------------------------------------------------------------------------------------
	/// Executes a given function that can safely modify the inner value.
	/// It 1. acquires the lock, 2. calls the function and passes a reference to the value as argument, 3. releases the lock.
	/// The function should have a signature equivalent to
	/// @code
	/// Result<void> func(T&);
	/// @endcode
	///
	/// Example:
	/// @code
	/// Synchronized<BaseArray<Int>> v;
	/// // ...
	/// v.Write([] (auto& t)
	///		{
	///			iferr_scope;
	///			t.Append(1) iferr_return;
	///			t.Append(2) iferr_return;
	///			return OK;
	///		}) iferr_return;
	/// }
	/// @endcode
	///
	/// @param[in] func								Function that gets write access to the contained value.
	//----------------------------------------------------------------------------------------
	template <typename F>
	Result<void> Write(F&& func)
	{
		LockedWritePtr t(*this);
		return func(*t);
	}

	//----------------------------------------------------------------------------------------
	/// A variant of Write that takes a second synchronized value.
	/// It 1. acquires both locks in order of their addresses, 2. calls the function and passes reference to both values as arguments, 3. releases the locks.
	/// This ensures no deadlocks can occur when trying to acquire two locks manually in different orders.
	/// The function should have a signature equivalent to
	/// @code
	/// Result<void> func(T&, U&);
	/// @endcode
	///
	/// Example:
	/// @code
	/// Synchronized<Int> v1;
	/// Synchronized<Int> v2;
	/// // ...
	/// v1.Write([] (v2, auto& t1, auto& t2)
	///		{
	///			t1 = 1;
	///			t2 = 2;
	///			return OK;
	///		}) iferr_return;
	/// }
	/// @endcode
	///
	/// @param[in] other							Another synchronized value.
	/// @param[in] func								Function that gets write access to the contained value.
	//----------------------------------------------------------------------------------------
	template <typename U, typename F>
	Result<void> Write(U& other, F&& func)
	{
		LockedWritePtr a(*this, true);
		LockedWritePtr b(other, true);

		AcquireLockPair(a, b);

		return func(*a, *b);
	}

	//----------------------------------------------------------------------------------------
	/// Similar to @c Write, but only provides read-access to the contained value.
	/// In other words, the value the locked pointer can access is of type @code const T* @endcode.
	//----------------------------------------------------------------------------------------
	LockedReadPtr Read() const
	{
		return LockedReadPtr(*this);
	}

	//----------------------------------------------------------------------------------------
	/// Similar to @c Write, but only provides read-access to the contained value.
	/// The function should have a signature equivalent to
	/// @code
	/// Result<void> func(const T&);
	/// @endcode
	//----------------------------------------------------------------------------------------
	template <typename F>
	Result<void> Read(F&& func) const
	{
		LockedReadPtr t(*this);
		return func(*t);
	}

	//----------------------------------------------------------------------------------------
	/// Similar to @c Write, but only provides read-access to the contained values.
	/// The function should have a signature equivalent to
	/// @code
	/// Result<void> func(const T&, const U&);
	/// @endcode
	//----------------------------------------------------------------------------------------
	template <typename U, typename F>
	Result<void> Read(U& other, F&& func)
	{
		LockedReadPtr a(*this, true);
		LockedReadPtr b(other, true);

		AcquireLockPair(a, b);

		return func(*a, *b);
	}

	// A scoped pointer that acquires the internal lock for writing on construction and releases it on destruction.
	class LockedWritePtr
	{
	public:
		LockedWritePtr() = delete;

		explicit LockedWritePtr(SynchronizedValue& synced) : _synced(&synced)
		{
			Acquire();
		}

		LockedWritePtr(SynchronizedValue& synced, Bool dontLock) : _synced(&synced)
		{
			/* Lock manually */
		}

		LockedWritePtr(LockedWritePtr&& src) : _synced(src._synced)
		{
			src._synced = nullptr;
		}

		LockedWritePtr& operator =(LockedWritePtr&& src)
		{
			_synced = src._synced;
			return *this;
		}

		LockedWritePtr(const LockedWritePtr&) = delete;

		LockedWritePtr& operator =(const LockedWritePtr&) = delete;

		~LockedWritePtr()
		{
			if (_synced)
				Release();
		}

		T* operator ->() { return &GetValue(); }

		T& operator *() { return GetValue(); }

	private:
		T& GetValue() { return _synced->_value; }

		void Acquire() { LockTraits<LOCKTYPE>::AcquireWriteLock(_synced->_lock); }

		void Release() { LockTraits<LOCKTYPE>::ReleaseWriteLock(_synced->_lock); }

		SynchronizedValue* _synced;

		template <typename, typename>
		friend class SynchronizedValue;
	};

	// A scoped pointer that acquires the internal lock for reading on construction and releases it on destruction.
	class LockedReadPtr
	{
	public:
		LockedReadPtr() = delete;

		explicit LockedReadPtr(const SynchronizedValue& synced) : _synced(&synced)
		{
			Acquire();
		}

		LockedReadPtr(SynchronizedValue& synced, Bool dontLock) : _synced(&synced)
		{
			/* Lock manually */
		}

		LockedReadPtr(LockedReadPtr&& src) : _synced(src._synced)
		{
			src._synced = nullptr;
		}
		
		LockedReadPtr& operator =(LockedReadPtr&& src)
		{
			_synced = src._synced;
			return *this;
		}

		LockedReadPtr(const LockedReadPtr&) = delete;

		LockedReadPtr& operator =(const LockedReadPtr&) = delete;

		~LockedReadPtr()
		{
			if (_synced)
				Release();
		}

		const T* operator ->() { return &GetValue(); }

		const T& operator *() { return GetValue(); }

	private:
		const T& GetValue() const { return _synced->_value; }

		void Acquire() const { LockTraits<LOCKTYPE>::AcquireReadLock(_synced->_lock); }

		void Release() const { LockTraits<LOCKTYPE>::ReleaseReadLock(_synced->_lock); }

		const SynchronizedValue* _synced;

		template <typename, typename>
		friend class SynchronizedValue;
	};

private:
	// Acquire two locks for writing in order of their addresses to prevent deadlocks.
	template <typename L1, typename L2>
	static void AcquireLockPair(L1& sg1, L2& sg2)
	{
		if (&*sg1 < &*sg2)
		{
			sg1.Acquire();
			sg2.Acquire();
		}
		else
		{
			sg2.Acquire();
			sg1.Acquire();
		}
	}

private:
	T	_value;
	mutable LOCKTYPE	_lock;
};

//----------------------------------------------------------------------------------------
/// Synchronized<T> is an alias for SynchronizedValue<T, Spinlock>.
/// 
/// @tparam T											Type of the contained value.
//----------------------------------------------------------------------------------------
template <typename T>
using Synchronized = SynchronizedValue<T, Spinlock>;

class ARWLock;

//----------------------------------------------------------------------------------------
/// RWSynchronized<T> is an alias for SynchronizedValue<T, ARWLock>.
/// 
/// @tparam T											Type of the contained value.
//----------------------------------------------------------------------------------------
template <typename T>
using RWSynchronized = SynchronizedValue<T, ARWLock>;

}

#endif // SYNCHRONIZED_H__
