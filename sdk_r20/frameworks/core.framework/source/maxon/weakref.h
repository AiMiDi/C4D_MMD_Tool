#ifndef WEAKREF_H__
#define WEAKREF_H__

#include "maxon/apibase.h"
#include "maxon/atomictypes.h"
#include "maxon/cpuyield.h"

namespace maxon
{

/// @addtogroup STRUCTURES
/// @{

struct WeakRefTargetBase;

struct WeakRefBase
{
	WeakRefBase()
	{
	}

	//----------------------------------------------------------------------------------------
	/// Removes a weak reference.
	//----------------------------------------------------------------------------------------
	~WeakRefBase();

	//----------------------------------------------------------------------------------------
	/// Copy constructs a weak reference.
	/// @param[in] src								Source weak reference.
	//----------------------------------------------------------------------------------------
	WeakRefBase(const WeakRefBase& src);

	//----------------------------------------------------------------------------------------
	/// Move constructs a weak reference.
	/// @param[in] src								Source weak reference.
	//----------------------------------------------------------------------------------------
	WeakRefBase(WeakRefBase&& src);

	//----------------------------------------------------------------------------------------
	/// Copies a weak reference.
	/// @param[in] src								Source weak reference.
	/// @return												*this.
	//----------------------------------------------------------------------------------------
	WeakRefBase& operator =(const WeakRefBase& src)
	{
		if (&src != this)
		{
			this->~WeakRefBase();
			new (this) WeakRefBase(src);
		}
		return *this;
	}

	//----------------------------------------------------------------------------------------
	/// Moves a weak reference.
	/// @param[in] src								Source weak reference.
	/// @return												*this.
	//----------------------------------------------------------------------------------------
	MAXON_OPERATOR_MOVE_ASSIGNMENT(WeakRefBase);

public:
	mutable WeakRefTargetBase* data = nullptr;
};

MAXON_ASSERT_STANDARD_LAYOUT(WeakRefBase);

struct WeakRefTargetBase
{
	//----------------------------------------------------------------------------------------
	/// Locks the WeakRefTarget.
	/// @return												Pointer to the current target.
	//----------------------------------------------------------------------------------------
	const void* Lock() const
	{
		CpuYield	wait;
		UInt value = _target.LoadRelaxed();

		while ((value & 1) || _target.TryCompareAndSwap(value | 1, value) == false)
		{
			wait.Pause(this);
			value = _target.LoadRelaxed();
		}
		return (void*) value;

	}

	//----------------------------------------------------------------------------------------
	/// Unlocks the WeakRefTarget.
	/// @param[in] target							Pointer to the (new) target to be stored.
	//----------------------------------------------------------------------------------------
	void Unlock(const void* target) const
	{
		_target.StoreRelease(UInt(target));
	}

	//----------------------------------------------------------------------------------------
	/// Checks if there currently is a target.
	/// @return												True if there currently is a target, otherwise false.
	//----------------------------------------------------------------------------------------
	explicit operator Bool() const
	{
		return (_target.LoadRelaxed() & ~UInt(1)) != 0;
	}

protected:
	friend struct MemoryMetadataProxy;

	void UnlockCurrent() const
	{
		UInt target = _target.LoadRelaxed() & ~UInt(1);
		_target.StoreRelease(target);
	}

protected:
	mutable AtomicUInt _target;
};

MAXON_ASSERT_STANDARD_LAYOUT(WeakRefTargetBase);


//----------------------------------------------------------------------------------------
/// A WeakRef points to a target object as long as there are strong references which
/// also point to it. When an object has no more strong references it will be destructed
/// and all weak references to it will return a null reference from then on.
//----------------------------------------------------------------------------------------
template <typename REFERENCE> class WeakRef : public WeakRefBase
{
public:
	WeakRef()
	{
	}

	//----------------------------------------------------------------------------------------
	/// Adds a weak reference. If memory allocation fails the weak reference will be nullptr.
	/// @param[in] strongReference		BaseRef with strong reference to an object.
	//----------------------------------------------------------------------------------------
	MAXON_IMPLICIT WeakRef(const REFERENCE& strongReference)
	{
		auto& ptr = GetBaseRef(strongReference);
		if (ptr)
			std::remove_reference<decltype(ptr)>::type::Handler::AddWeakReference(ptr.GetPointer(), *this);
	}

	//----------------------------------------------------------------------------------------
	/// Copy constructs a weak reference.
	/// @param[in] src								Source weak reference.
	//----------------------------------------------------------------------------------------
	WeakRef(const WeakRef& src) : WeakRefBase(src)
	{
	}

	//----------------------------------------------------------------------------------------
	/// Removes a weak reference.
	//----------------------------------------------------------------------------------------
	~WeakRef()
	{
	}

	//----------------------------------------------------------------------------------------
	/// Moves a weak reference.
	/// @param[in] src								Source weak reference, will be nulled.
	//----------------------------------------------------------------------------------------
	WeakRef(WeakRef&& src) : WeakRefBase(std::move(src))
	{
	}

	//----------------------------------------------------------------------------------------
	/// Adds a strong reference.
	/// @param[in] strongReference		BaseRef with strong reference to an object.
	/// @return												*this.
	//----------------------------------------------------------------------------------------
	WeakRef& operator =(const REFERENCE& strongReference)
	{
		// Remove the old weak reference if any.
		if (data)
			this->~WeakRef();

		// Add a weak reference to the new target.
		new (this) WeakRef(strongReference);

		return *this;
	}

	//----------------------------------------------------------------------------------------
	/// Copies a weak reference.
	/// @param[in] src								Source weak reference.
	/// @return												*this.
	//----------------------------------------------------------------------------------------
	WeakRef& operator =(const WeakRef& src)
	{
		if (&src != this)
		{
			this->~WeakRef();
			new (this) WeakRef(src);
		}
		return *this;
	}

	//----------------------------------------------------------------------------------------
	/// Moves a weak reference.
	/// @param[in] src								Source weak reference.
	/// @return												*this.
	//----------------------------------------------------------------------------------------
	MAXON_OPERATOR_MOVE_ASSIGNMENT(WeakRef);


	//----------------------------------------------------------------------------------------
	// Removes the weak reference.
	//----------------------------------------------------------------------------------------
	WeakRef& operator =(std::nullptr_t t)
	{
		this->~WeakRef();
		new (this) WeakRef();
		return *this;
	}

	//----------------------------------------------------------------------------------------
	/// Returns a strong reference. If the weak referenced object was already released a
	/// null reference will be returned.
	/// @return												Strong reference to the target or null.
	//----------------------------------------------------------------------------------------
	operator REFERENCE() const
	{
		const void* target = Lock();
		REFERENCE strongReference;

		if (target)
		{
			auto ptr = GetBaseRef(strongReference);

			if (decltype(ptr)::Handler::CreateStrongReference((typename REFERENCE::ReferencedType*) target))
				*(typename REFERENCE::ReferencedType**) &strongReference = (typename REFERENCE::ReferencedType*) target;
		}

		Unlock(target);
		return strongReference;
	}

	//----------------------------------------------------------------------------------------
	/// Returns a strong reference. If the weak referenced object was already released a
	/// null reference will be returned.
	/// @return												Strong reference to the target or null.
	//----------------------------------------------------------------------------------------
	REFERENCE GetReference() const
	{
		REFERENCE strongReference = *this;
		return strongReference;
	}

	//----------------------------------------------------------------------------------------
	/// Compares WeakRefs for equality.
	/// @param[in] other							The other comparand.
	/// @return												True if equal.
	//----------------------------------------------------------------------------------------
	Bool operator ==(const WeakRef& other) const
	{
		Bool isEqual = true;

		// Two WeakRefs pointing to the same target share the same WeakRefTargetBase.
		if (this != &other)
		{
			isEqual = data == other.data;
		}
		return isEqual;
	}

	//----------------------------------------------------------------------------------------
	/// Compares WeakRefs for inequality.
	/// @param[in] other							The other comparand.
	/// @return												True if not equal.
	//----------------------------------------------------------------------------------------
	Bool operator !=(const WeakRef& other) const
	{
		return !this->operator ==(other);
	}

	//----------------------------------------------------------------------------------------
	/// Checks if the weak reference points to a strong reference (non-blocking check).
	/// @return												True if there currently is a strong reference, otherwise false.
	//----------------------------------------------------------------------------------------
	explicit operator Bool() const
	{
		if (data)
			return data->operator Bool();

		return false;
	}
	
	//----------------------------------------------------------------------------------------
	/// Checks if the weak reference is empty.
	/// @return												True if the weak reference is empty.
	//----------------------------------------------------------------------------------------
	Bool IsEmpty() const
	{
		return !this->operator Bool();
	}

	//----------------------------------------------------------------------------------------
	/// Checks if this weak reference contains anything.
	/// @return												True if the weak reference points to an object.
	//----------------------------------------------------------------------------------------
	Bool IsPopulated() const
	{
		return this->operator Bool();
	}
	
	UInt GetHashCode() const
	{
		// Compute hash code based on the targeted object. WeakRefs pointing to the same target will have the same hash code.
		const void* target = Lock();
		Unlock(target);

		return DefaultCompare::GetHashCode(target);
	}

private:

	/// Locks the WeakRefTarget.
	const void* Lock() const
	{
		return data ? data->Lock() : nullptr;
	}

	/// Unlocks the WeakRefTarget.
	void Unlock(const void* target) const
	{
		if (data)
			data->Unlock(target);
	}


	template <typename REFERENCETYPE> static typename REFERENCETYPE::BaseRefType& GetBaseRef(const REFERENCETYPE& strongReference)
	{
		return const_cast<typename REFERENCETYPE::BaseRefType&>(strongReference.GetBaseRef());
	}

	template <typename T, typename HANDLER> static BaseRef<T, HANDLER>& GetBaseRef(const BaseRef<T, HANDLER>& strongReference)
	{
		return const_cast<BaseRef<T, HANDLER>&>(strongReference);
	}
};



/// @}

} // namespace maxon

#endif // WEAKREF_H__
