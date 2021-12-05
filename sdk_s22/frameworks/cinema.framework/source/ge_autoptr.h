/////////////////////////////////////////////////////////////
// Cinema 4D SDK                                           //
/////////////////////////////////////////////////////////////
// (c) MAXON Computer GmbH, all rights reserved            //
/////////////////////////////////////////////////////////////

#ifndef GE_AUTOPTR_H__
#define GE_AUTOPTR_H__

#include "c4d_memory.h"
#include "maxon/errorbase.h"

//----------------------------------------------------------------------------------------
/// This class handles automatic allocation and freeing of objects with static @c Alloc() and @c %Free() functions. Most classes in the API with private constructors uses this scheme.\n
/// Through AutoAlloc it is possible to use these classes with a scope-based life time.\n
/// They are allocated when AutoAlloc is created and freed when the scope is exited and AutoAlloc is destroyed:
/// @code
/// {
/// 	AutoAlloc<BaseBitmap> bitmap;
/// 	if (!bitmap) return;
/// 	// ...
/// }
/// @endcode
/// Note that the @em bitmap variable still needs to be checked. If the allocation fails then @em bitmap == @formatConstant{nullptr}. Otherwise the @em bitmap variable can be used just like any pointer.\n
/// It is possible to pass parameters to the @c Alloc() function via AutoAlloc's constructor:
/// @code
/// AutoAlloc<VariableTag> hermite(Thermite2d, 100);
/// @endcode
/// @warning If it is ever needed to give away the allocated object to any other function AutoAlloc cannot be used. It will not release the ownership, the object will still be deleted when the scope is exited.
/// @see AutoNew AutoPtr
//----------------------------------------------------------------------------------------
template <class TYPE> class AutoAlloc
{
	TYPE* ptr;

private:
	const AutoAlloc<TYPE>& operator = (const AutoAlloc<TYPE>& p);
	AutoAlloc(const AutoAlloc<TYPE>& p);

public:
	//----------------------------------------------------------------------------------------
	/// Calls @c TYPE::Alloc() and stores the returned pointer internally.
	//----------------------------------------------------------------------------------------
	AutoAlloc() { ptr = TYPE::Alloc(); }

	//----------------------------------------------------------------------------------------
	/// Calls @c TYPE::Alloc(id) and stores the returned pointer internally.
	/// @param[in] id									The parameter.
	//----------------------------------------------------------------------------------------
	explicit AutoAlloc(Int32 id) { ptr = TYPE::Alloc(id); }

	//----------------------------------------------------------------------------------------
	/// Calls @c TYPE::Alloc(p1, p2) and stores the returned pointer internally.
	/// @param[in] p1									The first parameter.
	/// @param[in] p2									The second parameter.
	//----------------------------------------------------------------------------------------
	AutoAlloc(Int32 p1, Int32 p2) { ptr = TYPE::Alloc(p1, p2); }

	//----------------------------------------------------------------------------------------
	/// Stores the returned pointer internally without calling @c TYPE::Alloc().
	/// @param[in] initptr						A pointer to an already allocated object. The AutoAlloc instance takes over the ownership of the pointed object.
	//----------------------------------------------------------------------------------------
	explicit AutoAlloc(TYPE* initptr) { ptr = initptr; }

	//----------------------------------------------------------------------------------------
	/// Moves the returned pointer internally without calling @c TYPE::Alloc().
	/// @param[in] other							A pointer to an already allocated object. The AutoAlloc instance takes over the ownership of the pointed object.
	//----------------------------------------------------------------------------------------
	AutoAlloc(AutoAlloc&& other) : ptr(other.ptr)
	{
		other.ptr = nullptr;
	}

	MAXON_OPERATOR_MOVE_ASSIGNMENT(AutoAlloc);

	//----------------------------------------------------------------------------------------
	/// Calls @c TYPE::Free(ptr), where @c ptr is the internally stored pointer.
	//----------------------------------------------------------------------------------------
	~AutoAlloc() { TYPE::Free(ptr); ptr = nullptr; }

	//----------------------------------------------------------------------------------------
	/// Conversion to a raw pointer to @c TYPE. Makes it possible to pass the object directly to functions like @c Function(TYPE* t).
	/// @return												The internal pointer. The AutoAlloc instance owns the pointed object.
	//----------------------------------------------------------------------------------------
	operator const TYPE*() const { return ptr; }
	operator TYPE*() { return ptr; }

	//----------------------------------------------------------------------------------------
	/// Conversion to a reference to @c TYPE. Makes it possible to pass the object directly to functions like @c Function(TYPE& t).
	/// @note This dereferences the internal pointer. Hence, it must not be @formatConstant{nullptr}.
	/// @return												A reference to the pointed object.
	//----------------------------------------------------------------------------------------
	operator const TYPE&() const { return *ptr; }
	operator TYPE&() { return *ptr; }

	//----------------------------------------------------------------------------------------
	/// Used for calls like @c myauto->Function().
	/// @note This dereferences the internal pointer. Hence, it must not be @formatConstant{nullptr}.
	/// @return												The internal pointer. The AutoAlloc instance owns the pointed object.
	//----------------------------------------------------------------------------------------
	const TYPE* operator -> () const { return ptr; }
	TYPE* operator -> () { return ptr; }

	//----------------------------------------------------------------------------------------
	/// Used for expressions like @c &myauto. Extracts a pointer to the internal pointer.
	/// @note This means that it is impossible to get the address of the actual AutoAlloc instance.
	/// @return												A pointer to the internal pointer. The AutoAlloc instance owns the pointed object.
	//----------------------------------------------------------------------------------------
	const TYPE* const* operator & () const { return &ptr; }
	TYPE* const* operator & () { return &ptr; }

	//----------------------------------------------------------------------------------------
	/// Retrieves the internal pointer and then sets it to @formatConstant{nullptr}. Thus the ownership is transfered to the caller.
	/// @return												The internal pointer. The caller takes over the ownership of the pointed object.
	//----------------------------------------------------------------------------------------
	TYPE* Release() { TYPE* tmp = ptr; ptr = nullptr; return tmp; }

	//----------------------------------------------------------------------------------------
	/// Calls @c TYPE::Free(ptr) with the internal pointer and sets it to @formatConstant{nullptr}.
	//----------------------------------------------------------------------------------------
	void Free() { TYPE::Free(ptr); ptr = nullptr; }

	//----------------------------------------------------------------------------------------
	/// Assigns @formatParam{p} as the internal pointer.
	/// @param[in] p									A pointer to an object allocated with @c TYPE::Alloc(). The AutoAlloc instance takes over the ownership of the pointed object.
	//----------------------------------------------------------------------------------------
	void Assign(TYPE* p) { ptr = p; }

	MAXON_ATTRIBUTE_FORCE_INLINE friend void operator %(const AutoAlloc<TYPE>& alloc, maxon::ThreadReferencedError& err)
	{
		if (alloc.ptr != nullptr)
		{
			err = nullptr;
		}
		else
		{
			maxon::OutOfMemoryError e(MAXON_SOURCE_LOCATION);
			err = maxon::System::SetCurrentError(reinterpret_cast<maxon::Error&&>(e));
		}
	}
};

//----------------------------------------------------------------------------------------
/// This class handles automatic deallocation of objects with @c TYPE::Free(). It is similar in function to AutoAlloc, but the object has to have been previously allocated.
/// @see AutoAlloc
//----------------------------------------------------------------------------------------
template <class TYPE> class AutoFree
{
	TYPE* ptr;

private:
	const AutoFree<TYPE>& operator = (const AutoFree<TYPE>& p);
	AutoFree(const AutoFree<TYPE>& p);

public:
	//----------------------------------------------------------------------------------------
	/// Default constructor.
	//----------------------------------------------------------------------------------------
	AutoFree() { ptr = nullptr; }
	AutoFree(AutoFree&& src) : ptr(src.ptr) { src.ptr = nullptr; }

	//----------------------------------------------------------------------------------------
	/// Stores the pointer @formatParam{p} internally.
	/// @param[in] p									A pointer to an object to be freed with @c TYPE::Free(p). The AutoFree instance takes over the ownership of the pointed object.
	//----------------------------------------------------------------------------------------
	explicit AutoFree(TYPE* p) { ptr = p; }

	//----------------------------------------------------------------------------------------
	/// Calls @c TYPE::Free(ptr), where @c ptr is the internally stored pointer.
	//----------------------------------------------------------------------------------------
	~AutoFree() { TYPE::Free(ptr); ptr = nullptr; }

	//----------------------------------------------------------------------------------------
	/// Sets @formatParam{p} as the internal pointer.
	/// @param[in] p									A pointer to an object to be freed with @c TYPE::Free(p). The AutoFree instance takes over the ownership of the pointed object.
	//----------------------------------------------------------------------------------------
	void Set(TYPE* p) { ptr = p; }

	//----------------------------------------------------------------------------------------
	/// Conversion to a raw pointer to @c TYPE. Makes it possible to pass the object directly to functions like @c Function(TYPE* t).
	/// @return												The internal pointer. The AutoFree instance owns the pointed object.
	//----------------------------------------------------------------------------------------
	operator TYPE*() const { return ptr; }

	//----------------------------------------------------------------------------------------
	/// Conversion to a reference to @c TYPE. Makes it possible to pass the object directly to functions like @c Function(TYPE& t).
	/// @note This dereferences the internal pointer. Hence, it must not be @formatConstant{nullptr}.
	/// @return												A reference to the pointed object.
	//----------------------------------------------------------------------------------------
	operator TYPE&() const { return *ptr; }

	//----------------------------------------------------------------------------------------
	/// Used for calls like @c myauto->Function().
	/// @note This dereferences the internal pointer. Hence, it must not be @formatConstant{nullptr}.
	/// @return												The internal pointer. The AutoFree instance owns the pointed object.
	//----------------------------------------------------------------------------------------
	TYPE* operator -> () const { return ptr; }

	//----------------------------------------------------------------------------------------
	/// Used for expressions like @c &myauto. Extracts a pointer to the internal pointer.
	/// @note This means that it is impossible to get the address of the actual AutoFree instance.
	/// @return												A pointer to the internal pointer. The AutoFree instance owns the pointed object.
	//----------------------------------------------------------------------------------------
	TYPE* const* operator & () const { return &ptr; }

	//----------------------------------------------------------------------------------------
	/// Retrieves the internal pointer and then sets it to @formatConstant{nullptr}. Thus the ownership is transfered to the caller.
	/// @return												The internal pointer. The caller takes over the ownership of the pointed object.
	//----------------------------------------------------------------------------------------
	TYPE* Release() { TYPE* tmp = ptr; ptr = nullptr; return tmp; }

	//----------------------------------------------------------------------------------------
	/// Calls @c TYPE::Free(ptr) with the internal pointer and sets it to @formatConstant{nullptr}.
	//----------------------------------------------------------------------------------------
	void Free() { TYPE::Free(ptr); ptr = nullptr; }

	//----------------------------------------------------------------------------------------
	/// Assigns @formatParam{p} as the internal pointer.
	/// @param[in] p									A pointer to an object to be freed with @c TYPE::Free(p). The AutoFree instance takes over the ownership of the pointed object.
	//----------------------------------------------------------------------------------------
	void Assign(TYPE* p) { ptr = p; }

	MAXON_ATTRIBUTE_FORCE_INLINE friend void operator %(const AutoFree<TYPE>& alloc, maxon::ThreadReferencedError& err)
	{
		if (alloc.ptr != nullptr)
		{
			err = nullptr;
		}
		else
		{
			maxon::OutOfMemoryError e(MAXON_SOURCE_LOCATION);
			err = maxon::System::SetCurrentError(reinterpret_cast<maxon::Error&&>(e));
		}
	}
};

#endif // GE_AUTOPTR_H__
