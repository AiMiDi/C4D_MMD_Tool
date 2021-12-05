#ifndef NEWOBJ_H__
#define NEWOBJ_H__

#ifndef APIBASE_H__
	#error "Do not include this file directly"
#endif

namespace maxon
{

class DefaultAllocator;

namespace details
{

template <typename T> void PrivateFreeWithDestructor(const T* obj);
Bool PrivateClearAllWeakReferences(const void* obj);

template <Bool IS_DELETABLE> class ForwardFree
{
public:
	template <typename T> static void FreeWithDestructor(T* o) { DebugStop("T has a private destructor"); }
};

template <> class ForwardFree<true>
{
public:
	// Call System::FreeWithDestructor to destruct the object and release memory.
	template <typename T> static void FreeWithDestructor(T* o) { PrivateFreeWithDestructor(o); }
};

template <typename T> class NewDelete
{
public:
	static const Bool IS_ALLOC_TYPE = IsAllocType<T>::value;
	static const Int SIZE = SIZEOF(T);

	// Needed by NewObj and DeleteObj: Selects T if it is an alloc type, otherwise NewDelete.
	// NewObj will invoke the Alloc function on AllocType if T is an alloc type.
	// DeleteObj will invoke the Free method of AllocType if T is an alloc type, otherwise this Free method to invoke System::FreeWithDestructor (unless the destructor is private).
	using AllocType = typename std::conditional<IS_ALLOC_TYPE, T, NewDelete>::type;

	// Needed by NewObj and DeleteObj: Selects T if it is a type to be created by a constructor, otherwise NewDelete.
	// NewObj will invoke the constructor of T if T is created by constructor (not an alloc type).
	// DeleteObj will invoke the destructor if it is private (not an alloc type).
	using ConstructorType = typename std::conditional<IS_ALLOC_TYPE, NewDelete, T>::type;

	// Using a member type detector we could automatically support types which only work with a special allocator (GetAllocatorType<T>::type).
	using AllocatorType = DefaultAllocator;

	template <typename... ARGS> explicit NewDelete(ARGS&&...) { DebugStop(); }

	template <typename... ARGS> static T* Alloc(MAXON_SOURCE_LOCATION_DECLARATION, ARGS&&...) { DebugStop(); return nullptr; }

	static inline void Free(const T* o)
	{
		DebugAssert(IS_ALLOC_TYPE == false, "Not for alloc types");
		ForwardFree<std::is_destructible<ConstructorType>::value>::FreeWithDestructor((ConstructorType*)o);
	}

	static ResultPtr<T> Cast(ResultPtr<T>&& value)
	{
		return std::move(value);
	}

	static Result<T*> Cast(Result<T*>&& value)
	{
		return std::move(value);
	}

	template <typename T2> static ResultPtr<T> Cast(T2* value)
	{
		return static_cast<T*>(value);
	}
};

template <typename T, typename... ARGS> inline ResultPtr<T> NewObjWithLocation(MAXON_SOURCE_LOCATION_DECLARATION, ARGS&&... args)
{
	using Allocator = typename maxon::details::NewDelete<T>::AllocatorType;
	using AllocType = typename maxon::details::NewDelete<T>::AllocType;
	using ConstructorType = typename maxon::details::NewDelete<T>::ConstructorType;
	static const Bool IS_ALLOC_TYPE = maxon::details::NewDelete<T>::IS_ALLOC_TYPE;
#ifdef MAXON_TARGET_DEBUG
	const SourceLocation location(allocLocation.file, allocLocation.lineAndFlags, maxon::PrivateGetClassName<T>());
	return (IS_ALLOC_TYPE ? AllocType::Alloc(location, std::forward<ARGS>(args)...) :
													maxon::ResultPtr<T>((T*) MAXON_SAFE_PLACEMENT_NEW(Allocator::Alloc(maxon::details::NewDelete<T>::SIZE, location)) ConstructorType(std::forward<ARGS>(args)...)));
#else
	// In release PrivateGetClassName() does nothing. Pass the SourceLocation directly to the allocation to avoid unnecessary copies.
	// The caller is free to supply a name in the SourceLocation (which would be used with debug allocator enabled).
	return (IS_ALLOC_TYPE ? AllocType::Alloc(allocLocation, std::forward<ARGS>(args)...) :
													maxon::ResultPtr<T>((T*) MAXON_SAFE_PLACEMENT_NEW(Allocator::Alloc(maxon::details::NewDelete<T>::SIZE, allocLocation)) ConstructorType(std::forward<ARGS>(args)...)));
#endif
}

}

//----------------------------------------------------------------------------------------
/// Creates an object with constructor parameters (using new or T::Alloc, depending on the type). This does not throw any kind of
/// exception, it returns null if the allocation fails. NewObj does not clear the memory.
/// Usage: MyType* x = NewObj(MyType, optional constructor parameters);
/// @note Creating a template object will not compile if the template contains a comma, e.g. NewObj(MyType<1,2>). This is due to the nature of how the preprocessor works. To make it work either use NewObjT<>() or declare an alias using MyAllocType = MyType<1,2>; and then pass MyAllocType for the allocation itself.
/// @note NewObj does not support objects which might throw exceptions.
/// THREADSAFE.
/// @param[in] T									Type of object.
/// @param[in] ...								Additional constructor parameters.
/// @return												Pointer to object (null if allocation failed)
//----------------------------------------------------------------------------------------
#define NewObj(T, ...) (maxon::details::NewDelete<T>::IS_ALLOC_TYPE ? maxon::details::NewDelete<T>::Cast(maxon::details::NewDelete<T>::AllocType::Alloc(MAXON_SOURCE_LOCATION_NAME(T), ##__VA_ARGS__)) \
												:	maxon::ResultPtr<T>((T*) MAXON_SAFE_PLACEMENT_NEW(maxon::details::NewDelete<T>::AllocatorType::Alloc(maxon::details::NewDelete<T>::SIZE, MAXON_SOURCE_LOCATION_NAME(T))) PRIVATE_MAXON_ALLOC_TYPENAME maxon::details::NewDelete<T>::ConstructorType(__VA_ARGS__)))


/// Deprecated.
#define NewObjPtr(T, ...) ((T*) MAXON_SAFE_PLACEMENT_NEW(maxon::details::NewDelete<T>::AllocatorType::Alloc(maxon::details::NewDelete<T>::SIZE, MAXON_SOURCE_LOCATION_NAME(T))) PRIVATE_MAXON_ALLOC_TYPENAME maxon::details::NewDelete<T>::ConstructorType(__VA_ARGS__))

//----------------------------------------------------------------------------------------
/// Creates an object with constructor parameters (using new or T::Alloc, depending on the type). This does not throw any kind of
/// exception, it returns null if the allocation fails. NewObj does not clear the memory.
/// Usage: MyType* x = NewObj(MyType, optional constructor parameters);
/// @note Creating a template object will not compile if the template contains a comma, e.g. NewObj(MyType<1,2>). This is due to the nature of how the preprocessor works. To make it work either use NewObjT<>() or declare an alias using MyAllocType = MyType<1,2>; and then pass MyAllocType for the allocation itself.
/// @note NewObjT does not support objects which might throw exceptions.
/// THREADSAFE.
/// @param[in] args								Additional constructor parameters.
/// @tparam T											Type of object.
/// @tparam ARGS									Additional constructor parameter types.
/// @return												Pointer to object (null if allocation failed)
//----------------------------------------------------------------------------------------
template <typename T, typename... ARGS> inline ResultPtr<T> NewObjT(ARGS&&... args)
{
	return NewObj(T, std::forward<ARGS>(args)...);
}

#ifdef USE_API_MAXON
//----------------------------------------------------------------------------------------
/// Creates an object with constructor parameters (using new or T::Alloc, depending on the type). This does not throw any kind of
/// exception, it returns null if the allocation fails.
/// If the object is no Interface all of its memory will be cleared with 0.
/// DEPRECATED in current API, only available in Cinema 4D!
/// Usage: MyType* x = NewObjClear(MyType, optional constructor parameters);
/// THREADSAFE.
/// @note DO NOT USE this for new code.
/// @param[in] T									Type of object.
/// @param[in] ...								Additional constructor parameters.
/// @return												Pointer to object (null if allocation failed)
//----------------------------------------------------------------------------------------
#define NewObjClear(T, ...) (maxon::details::NewDelete<T>::IS_ALLOC_TYPE ? maxon::details::NewDelete<T>::Cast(maxon::details::NewDelete<T>::AllocType::Alloc(MAXON_SOURCE_LOCATION_NAME(T), ##__VA_ARGS__)).GetValue() \
												:	(T*) MAXON_SAFE_PLACEMENT_NEW(maxon::details::NewDelete<T>::AllocatorType::AllocClear(maxon::details::NewDelete<T>::SIZE, MAXON_SOURCE_LOCATION_NAME(T))) PRIVATE_MAXON_ALLOC_TYPENAME maxon::details::NewDelete<T>::ConstructorType(__VA_ARGS__))
#endif

//----------------------------------------------------------------------------------------
/// Deletes an object. This expects a pointer as argument, the object is deleted using the destructor or T::Free,
/// depending on the type of the object.
/// If the destructor is private System::FreeWithDestructor() cannot be called; the
/// destructor is called inline (after clearing weak references) and then the memory is released.
/// @note DeleteObj does not support objects which might throw exceptions.
/// THREADSAFE.
/// @param[in,out] obj						Object pointer (can be nullptr, will be nullptr after return)
//----------------------------------------------------------------------------------------
// originally we used auto*& objectToDelete, but that doesn't work as the Intel Compiler has a bug that shows lots of warnings and MSVC has a bug where it doesn't link anymore
#define DeleteObj(obj) \
	do { \
		PRIVATE_MAXON_ALLOC_TYPENAME std::remove_reference<decltype(obj)>::type* objectToDelete = &(obj); \
		if (*objectToDelete) \
		{ \
			using NewDeleteType = maxon::details::NewDelete<PRIVATE_MAXON_ALLOC_TYPENAME std::remove_pointer<PRIVATE_MAXON_ALLOC_TYPENAME std::remove_pointer<decltype(objectToDelete)>::type>::type>; \
			using CtorType = PRIVATE_MAXON_ALLOC_TYPENAME NewDeleteType::ConstructorType; \
			if (std::is_destructible<CtorType>::value) \
			{ \
				NewDeleteType::AllocType::Free(*objectToDelete); \
			} \
			else \
			{ \
				if (maxon::details::PrivateClearAllWeakReferences(*objectToDelete)) \
				{ \
					((CtorType*) (*objectToDelete))->~CtorType(); \
					NewDeleteType::AllocatorType::Free(*objectToDelete); \
				} \
			} \
			*objectToDelete = nullptr; \
		} \
	} while (false) // while ensures that the user needs to set a semicolon after DeleteObj

//----------------------------------------------------------------------------------------
/// Deletes an object. This calls the destructor and frees memory afterwards.
/// Normally you should use DeleteObj(). This variant should be used only in the rare case
/// when the object pointer is a constant so that it can't be set to nullptr.
/// @note DeleteConstPtrObj does not support objects which might throw exceptions.
/// THREADSAFE.
/// @param[in] o									Object pointer (can be nullptr)
//----------------------------------------------------------------------------------------
template <typename T> MAXON_ATTRIBUTE_FORCE_INLINE void DeleteConstPtrObj(T* o)
{
	DeleteObj(o);
}


} // namespace maxon

#endif // NEWOBJ_H__
