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

template <typename T> class NewObjHelper
{
public:
	static const Bool IS_ALLOC_TYPE = IsAllocType<T>::value;
	static const Int SIZE = SIZEOF(T);

	// Needed by NewObj: Selects T if it is an alloc type, otherwise NewObjHelper.
	// NewObj will invoke the Alloc function on AllocType if T is an alloc type.
	using AllocType = typename std::conditional<IS_ALLOC_TYPE, T, NewObjHelper>::type;

	// Needed by NewObj: Selects T if it is a type to be created by a constructor, otherwise NewObjHelper.
	// NewObj will invoke the constructor of T if T is created by constructor.
	using ConstructorType = typename std::conditional<IS_ALLOC_TYPE, NewObjHelper, T>::type;

	// Using a member type detector we could automatically support types which only work with a special allocator (GetAllocatorType<T>::type).
	using AllocatorType = DefaultAllocator;

	template <typename... ARGS> explicit NewObjHelper(ARGS&&...) { DebugStop(); }

	template <typename... ARGS> static T* Alloc(MAXON_SOURCE_LOCATION_DECLARATION, ARGS&&...) { DebugStop(); return nullptr; }

	static void Free(const T* o) { DebugStop(); }
};

template <typename T, typename... ARGS> inline ResultPtr<T> NewObjWithLocation(MAXON_SOURCE_LOCATION_DECLARATION, ARGS&&... args)
{
#ifdef MAXON_TARGET_DEBUG
	const SourceLocation location(allocLocation.file, allocLocation.lineAndFlags, maxon::PrivateGetClassName<T>());
	return (maxon::details::NewObjHelper<T>::IS_ALLOC_TYPE ? maxon::details::NewObjHelper<T>::AllocType::Alloc(location, std::forward<ARGS>(args)...) :
																									maxon::ResultPtr<T>((T*) MAXON_SAFE_PLACEMENT_NEW(maxon::details::NewObjHelper<T>::AllocatorType::Alloc(maxon::details::NewObjHelper<T>::SIZE, location)) PRIVATE_MAXON_ALLOC_TYPENAME maxon::details::NewObjHelper<T>::ConstructorType(std::forward<ARGS>(args)...)));
#else
	// In release PrivateGetClassName() does nothing. Pass the SourceLocation directly to the allocation to avoid unnecessary copies.
	// The caller is free to supply a name in the SourceLocation (which would be used with debug allocator enabled).
	return (maxon::details::NewObjHelper<T>::IS_ALLOC_TYPE ? maxon::details::NewObjHelper<T>::AllocType::Alloc(allocLocation, std::forward<ARGS>(args)...) :
																									maxon::ResultPtr<T>((T*) MAXON_SAFE_PLACEMENT_NEW(maxon::details::NewObjHelper<T>::AllocatorType::Alloc(maxon::details::NewObjHelper<T>::SIZE, allocLocation)) PRIVATE_MAXON_ALLOC_TYPENAME maxon::details::NewObjHelper<T>::ConstructorType(std::forward<ARGS>(args)...)));
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
#define NewObj(T, ...) (maxon::details::NewObjHelper<T>::IS_ALLOC_TYPE ? maxon::details::NewObjHelper<T>::AllocType::Alloc(MAXON_SOURCE_LOCATION_NAME(T), ##__VA_ARGS__) \
												:	maxon::ResultPtr<T>((T*) MAXON_SAFE_PLACEMENT_NEW(maxon::details::NewObjHelper<T>::AllocatorType::Alloc(maxon::details::NewObjHelper<T>::SIZE, MAXON_SOURCE_LOCATION_NAME(T))) PRIVATE_MAXON_ALLOC_TYPENAME maxon::details::NewObjHelper<T>::ConstructorType(__VA_ARGS__)))


/// Deprecated.
#define NewObjPtr(T, ...) ((T*) MAXON_SAFE_PLACEMENT_NEW(maxon::details::NewObjHelper<T>::AllocatorType::Alloc(maxon::details::NewObjHelper<T>::SIZE, MAXON_SOURCE_LOCATION_NAME(T))) PRIVATE_MAXON_ALLOC_TYPENAME maxon::details::NewObjHelper<T>::ConstructorType(__VA_ARGS__))

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
#define NewObjClear(T, ...) (maxon::details::NewObjHelper<T>::IS_ALLOC_TYPE ? maxon::details::NewObjHelper<T>::AllocType::Alloc(MAXON_SOURCE_LOCATION_NAME(T), ##__VA_ARGS__) \
												:	(T*) MAXON_SAFE_PLACEMENT_NEW(maxon::details::NewObjHelper<T>::AllocatorType::AllocClear(maxon::details::NewObjHelper<T>::SIZE, MAXON_SOURCE_LOCATION_NAME(T))) PRIVATE_MAXON_ALLOC_TYPENAME maxon::details::NewObjHelper<T>::ConstructorType(__VA_ARGS__))
#endif

//----------------------------------------------------------------------------------------
/// Deletes an object. This expects a pointer as argument, the object is deleted using the destructor or T::Free,
/// depending on the type of the object.
/// @note DeleteObj does not support objects which might throw exceptions.
/// THREADSAFE.
/// @param[in,out] obj						Object pointer (can be nullptr, will be nullptr after return)
//----------------------------------------------------------------------------------------
// originally we used auto*& objectToDelete, but that doesn't work as the Intel Compiler has a bug that shows lots of warnings and MSVC has a bug where it doesn't link anymore
#define DeleteObj(obj) \
	do { \
		PRIVATE_MAXON_ALLOC_TYPENAME std::remove_reference<decltype(obj)>::type* objectToDelete = &(obj); \
		if (*objectToDelete) { \
			using NewObjHelperType = maxon::details::NewObjHelper<PRIVATE_MAXON_ALLOC_TYPENAME std::remove_pointer<PRIVATE_MAXON_ALLOC_TYPENAME std::remove_pointer<decltype(objectToDelete)>::type>::type>; \
			if (NewObjHelperType::IS_ALLOC_TYPE) \
			{ \
				NewObjHelperType::AllocType::Free(*objectToDelete); \
			} \
			else \
			{ \
				using CtorType = PRIVATE_MAXON_ALLOC_TYPENAME NewObjHelperType::ConstructorType; \
				((CtorType*) (*objectToDelete))->~CtorType(); \
				NewObjHelperType::AllocatorType::Free(*objectToDelete); \
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
