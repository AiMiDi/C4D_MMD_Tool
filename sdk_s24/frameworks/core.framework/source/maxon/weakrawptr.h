#ifndef WEAKRAWPTR_H__
#define WEAKRAWPTR_H__

#include "maxon/weakref.h"
#include "maxon/weakrefservices.h"

namespace maxon
{

//----------------------------------------------------------------------------------------
/// WeakRawPtr allows to create weak references to all memory blocks and objects created with NewObj() or NewMem().
/// @note: in multithreaded use it might happen that the destructor of the object is already called but the memory block is still linked.
/// @code
/// Int* rawPtr = NewObj(Int) iferr_return;
/// WeakRawPtr<Int> link;
/// link.Set(rawPtr);
/// Int* get01 = link.Get();
/// DebugAssert(get01 != nullptr);
/// DeleteObj(rawPtr);
/// Int* get02 = link.Get();
/// DebugAssert(get02 == nullptr);
/// @endcode
//----------------------------------------------------------------------------------------
template <typename TYPE> class WeakRawPtr
{
public:
	//----------------------------------------------------------------------------------------
	/// Default constructor
	//----------------------------------------------------------------------------------------
	WeakRawPtr() = default;

	//----------------------------------------------------------------------------------------
	/// Explicit constructor to create the weak link with the connected target.
	//----------------------------------------------------------------------------------------
	MAXON_IMPLICIT WeakRawPtr(TYPE* target)
	{
		Set(target);
	}

	//----------------------------------------------------------------------------------------
	/// Copy constructor
	//----------------------------------------------------------------------------------------
	WeakRawPtr(const WeakRawPtr& c)
	{
		Set(c.Get());
	}

	//----------------------------------------------------------------------------------------
	/// Move constructor
	//----------------------------------------------------------------------------------------
	WeakRawPtr(WeakRawPtr&& src)
		: _weakRef(std::move(src._weakRef))
	{
	}

	MAXON_OPERATOR_MOVE_ASSIGNMENT(WeakRawPtr);
	MAXON_OPERATOR_COPY_ASSIGNMENT(WeakRawPtr);

	//----------------------------------------------------------------------------------------
	/// Returns the target that is linked to the weak link.
	/// @return                       Target pointer, otherwise nullptr if the object was freed in the meanwhile.
	//----------------------------------------------------------------------------------------
	TYPE* Get() const
	{
		if (!_weakRef.data)
			return nullptr;

		const void* target = _weakRef.data->Lock();
		finally
		{
			_weakRef.data->Unlock(target);
		};

		return (TYPE*)target;
	}

	//----------------------------------------------------------------------------------------
	/// Sets a new target to the weak link.
	/// @param[in] target							Object to be linked.
	//----------------------------------------------------------------------------------------
	void Set(TYPE* target)
	{
		if (_weakRef.data)
		{
			WeakRefServices::RemoveWeakReference(_weakRef);
		}

		if (target)
		{
			WeakRefServices::AddWeakReference(_weakRef, target);
		}
	}

private:
	WeakRefBase _weakRef;
};

}

#endif // WEAKRAWPTR_H__