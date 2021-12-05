#ifndef THREADSAFEREF_H__
#define THREADSAFEREF_H__

#include "maxon/apibase.h"
#include "maxon/atomictypes.h"
#include "maxon/cpuyield.h"
#include "maxon/spinlock.h"

namespace maxon
{

/// @addtogroup STRUCTURES
/// @{


template <typename POINTER> class ThreadSafePtr
{
public:
	MAXON_IMPLICIT ThreadSafePtr(POINTER src = nullptr) : _ptr(UInt(src))
	{
		static_assert(sizeof(ThreadSafePtr) == sizeof(POINTER), "ThreadSafePtr must have same size as POINTER");
	}

	//----------------------------------------------------------------------------------------
	/// THREADSAFE.
	//----------------------------------------------------------------------------------------
	~ThreadSafePtr()
	{
		DebugAssert(_ptr.LoadRelaxed() == 0, "ThreadSafePtr must be reset before destruction");
	}

	POINTER AcquirePtr() const
	{
		CpuYield wait;
		UInt value = _ptr.LoadRelaxed();

		// Loop while _ptr is acquired or if CAS fails.
		while ((value & 1) || (_ptr.TryCompareAndSwap(value | 1, value) == false))
		{
			wait.Pause(this);
			value = _ptr.LoadRelaxed();
		}

		return POINTER(value);
	}

	void ReleasePtr(POINTER ptr) const
	{
		_ptr.StoreRelease(UInt(ptr));
	}

	POINTER ChangePtr(POINTER ptr) const
	{
		CpuYield wait;
		UInt value = _ptr.LoadRelaxed();

		// Loop while _ptr is acquired or if CAS fails.
		while ((value & 1) || (_ptr.TryCompareAndSwap(UInt(ptr), value) == false))
		{
			wait.Pause(this);
			value = _ptr.LoadRelaxed();
		}

		return POINTER(value);
	}

	Bool TryCompareAndSwapPtr(POINTER ptr, POINTER compare) const
	{
		CpuYield wait;
		UInt value = _ptr.LoadRelaxed();

		// Loop while _ptr is acquired or if CAS fails.
		while ((value & 1) || (_ptr.TryCompareAndSwap(UInt(ptr), UInt(compare)) == false))
		{
			if ((value & ~UInt(1)) != UInt(compare))
				return false;
			wait.Pause(this);
			value = _ptr.LoadRelaxed();
		}

		return true;
	}

	POINTER AttemptAcquirePtr() const
	{
		CpuYield wait;
		UInt value = _ptr.LoadRelaxed();
		
		if (value)
		{
			// Loop while _ptr is acquired or if CAS fails.
			if ((value & 1) || (_ptr.TryCompareAndSwap(value | 1, value) == false))
				value = 0;
		}

		return POINTER(value);
	}

protected:
	mutable AtomicUInt	_ptr;
};


//----------------------------------------------------------------------------------------
/// Template for safe access to BaseRef from multiple threads. This comes at the cost
/// of extra atomic operations and will cause high contention if used thoughtless.
///
/// @code
/// ThreadSafeRef<SampleClassRef> g_global;
///
/// // consumer thread
/// SampleClassRef now = g_global;
///
/// // producer thread
/// SampleClassRef newObject = CreateSomething();
/// g_global = newObject;
/// @endcode
///
/// @note If there is high contention a queue will perform much better (no matter if you use
/// a job queue or a MPMC queue to store the objects only).
///
/// @tparam REFERENCE							Type of the reference that will be stored thread-safe.
//----------------------------------------------------------------------------------------
template <typename REFERENCE> class ThreadSafeRef : protected ThreadSafePtr<typename REFERENCE::ReferencedType*>
{
	using DereferencedPtr = typename REFERENCE::ReferencedType*;

public:
	ThreadSafeRef()
	{
	}

	//----------------------------------------------------------------------------------------
	/// @param[in] strongReference		BaseRef with strong reference to an object.
	//----------------------------------------------------------------------------------------
	explicit ThreadSafeRef(const REFERENCE& strongReference)
	{
		DereferencedPtr newPtr = const_cast<DereferencedPtr>(strongReference.GetPointer());
		if (newPtr)
			REFERENCE::Handler::AddReference(newPtr);

		this->ChangePtr(newPtr);
	}

	//----------------------------------------------------------------------------------------
	/// Copy constructs a thread safe pointer.
	/// THREADSAFE.
	/// @param[in] src								Source thread safe pointer.
	//----------------------------------------------------------------------------------------
	ThreadSafeRef(const ThreadSafeRef& src)
	{
		DereferencedPtr newPtr = src.AcquirePtr();
		if (newPtr)
			REFERENCE::Handler::AddReference(newPtr);
		src.ReleasePtr(newPtr);

		this->ChangePtr(newPtr);
	}

	//----------------------------------------------------------------------------------------
	/// Moves a thread safe pointer.
	/// THREADSAFE.
	/// @param[in] src								Source thread safe pointer.
	//----------------------------------------------------------------------------------------
	ThreadSafeRef(ThreadSafeRef&& src)
	{
		DereferencedPtr newPtr = src.ChangePtr(nullptr);
		this->ChangePtr(newPtr);
	}

	//----------------------------------------------------------------------------------------
	/// THREADSAFE.
	//----------------------------------------------------------------------------------------
	~ThreadSafeRef()
	{
		DereferencedPtr oldPtr = this->ChangePtr(nullptr);
		if (oldPtr)
			REFERENCE::Handler::RemoveReference(oldPtr);
	}

	//----------------------------------------------------------------------------------------
	/// Adds a strong reference.
	/// THREADSAFE.
	/// @param[in] strongReference		BaseRef with strong reference to an object.
	/// @return												*this.
	//----------------------------------------------------------------------------------------
	ThreadSafeRef& operator =(const REFERENCE& strongReference)
	{
		DereferencedPtr newPtr = const_cast<DereferencedPtr>(strongReference.GetPointer());
		if (newPtr)
			REFERENCE::Handler::AddReference(newPtr);

		DereferencedPtr oldPtr = this->ChangePtr(newPtr);
		if (oldPtr)
			REFERENCE::Handler::RemoveReference(oldPtr);

		return *this;
	}

	//----------------------------------------------------------------------------------------
	/// Atomic compare and swap of the reference.
	/// THREADSAFE.
	/// @param[in] strongReference		BaseRef with strong reference to an object.
	/// @param[in] compare						Old BaseRef to compare with current value.
	/// @return												True if the reference was exchanged.
	//----------------------------------------------------------------------------------------
	Bool TryCompareAndSwap(const REFERENCE& strongReference, const REFERENCE& compare)
	{
		DereferencedPtr newPtr = const_cast<DereferencedPtr>(strongReference.GetPointer());
		if (newPtr)
			REFERENCE::Handler::AddReference(newPtr);

		DereferencedPtr oldPtr = const_cast<DereferencedPtr>(compare.GetPointer());

		if (this->TryCompareAndSwapPtr(newPtr, oldPtr))
		{
			if (oldPtr)
				REFERENCE::Handler::RemoveReference(oldPtr);
			return true;
		}
		else
		{
			if (newPtr)
				REFERENCE::Handler::RemoveReference(newPtr);
			return false;
		}
	}

	//----------------------------------------------------------------------------------------
	/// Copies a thread safe pointer.
	/// @param[in] src								Source thread safe pointer.
	/// @return												*this.
	//----------------------------------------------------------------------------------------
	ThreadSafeRef& operator =(const ThreadSafeRef& src)
	{
		if (&src != this)
		{
			DereferencedPtr newPtr = src.AcquirePtr();
			if (newPtr)
				REFERENCE::Handler::AddReference(newPtr);
			src.ReleasePtr(newPtr);

			DereferencedPtr oldPtr = this->ChangePtr(newPtr);
			if (oldPtr)
				REFERENCE::Handler::RemoveReference(oldPtr);
		}
		return *this;
	}

	//----------------------------------------------------------------------------------------
	/// Resets the thread safe pointer.
	/// @return												*this.
	//----------------------------------------------------------------------------------------
	ThreadSafeRef& operator =(std::nullptr_t)
	{
		DereferencedPtr oldPtr = this->ChangePtr(nullptr);
		if (oldPtr)
			REFERENCE::Handler::RemoveReference(oldPtr);
		return *this;
	}

	//----------------------------------------------------------------------------------------
	/// Moves a thread safe pointer.
	/// @param[in] src								Source thread safe pointer.
	/// @return												*this.
	//----------------------------------------------------------------------------------------
	ThreadSafeRef& operator =(ThreadSafeRef&& src)
	{
		if (&src != this)
		{
			DereferencedPtr newPtr = src.ChangePtr(nullptr);
			DereferencedPtr oldPtr = this->ChangePtr(newPtr);
			if (oldPtr)
				REFERENCE::Handler::RemoveReference(oldPtr);
		}
		return *this;
	}

	//----------------------------------------------------------------------------------------
	/// Constructs a new BaseRef with a strong reference.
	/// THREADSAFE.
	/// @return												BaseRef with a strong reference.
	//----------------------------------------------------------------------------------------
	REFERENCE Get() const
	{
		DereferencedPtr ptr = this->AcquirePtr();
		REFERENCE strongReference = ptr;
		this->ReleasePtr(ptr);

		return strongReference;
	}

	//----------------------------------------------------------------------------------------
	/// Constructs a new BaseRef with a strong reference.
	/// THREADSAFE.
	/// @return												BaseRef with a strong reference.
	//----------------------------------------------------------------------------------------
	operator REFERENCE() const
	{
		return Get();
	}
};

/// @}

} // namespace maxon

#endif // THREADSAFEREF_H__
