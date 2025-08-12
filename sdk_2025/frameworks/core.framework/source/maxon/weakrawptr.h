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
	/// Proxy object: Locks the target object until the scope is left and ensures that the target is not released while you access it.
	/// @note Concurrent access to the target is still possible, the proxy just ensures that the memory block is stil allocated.
	struct WeakRawPtrProxy
	{
		WeakRawPtrProxy() : _data(nullptr), _target(nullptr) { }
		WeakRawPtrProxy(const WeakRefTargetBase& data, const void* t) : _data(&data), _target(static_cast<TYPE*>(MAXON_REMOVE_CONST(t))) { }
		~WeakRawPtrProxy()
		{
			if (_data)
				_data->Unlock(_target);
		}
		
		TYPE* operator ->() { return _target; }
		explicit operator Bool() const { return _target != nullptr; }

		const WeakRefTargetBase* _data;
		TYPE* _target;
	};

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

		return (TYPE*)_weakRef.data->GetCurrent();
	}

	//----------------------------------------------------------------------------------------
	/// Returns the target that is linked to the weak link.
	/// @return                       Proxy for the target pointer, otherwise nullptr if the object was freed in the meanwhile.
	//----------------------------------------------------------------------------------------
	WeakRawPtrProxy GetProxy() const
	{
		if (!_weakRef.data)
			return WeakRawPtrProxy();

		const void* target = _weakRef.data->Lock();

		return WeakRawPtrProxy(*_weakRef.data, target);
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
