#ifndef MAC_CFHELPERS_H__
#define MAC_CFHELPERS_H__

#include <CoreFoundation/CoreFoundation.h>
#include "maxon/baseref.h"
#include "maxon/block.h"

namespace maxon
{

inline Block<const Byte> ToBlock(CFDataRef ref)
{
	if (ref)
		return Block<const Byte>(CFDataGetBytePtr(ref), CFDataGetLength(ref));
	else
		return Block<const Byte>(nullptr, 0);
}

// for iOS and Mac OS
//----------------------------------------------------------------------------------------
/// Returns a custom CFAllocator which only supports dealloc via DeleteMem.
/// @return												Custom CFAllocator.
//----------------------------------------------------------------------------------------
CFAllocatorRef GetCustomCFAllocator();

class CoreFoundationCreatedPointerHandler
{
public:
	//----------------------------------------------------------------------------------------
	/// Sets the initial reference to a newly allocated object (slightly more efficient than AddReference).
	/// @param[in] o									Pointer to the referenced object, must not be nullptr.
	//----------------------------------------------------------------------------------------
	template <typename T> static void InitialReference(const T* o)
	{
		// Do not CFRetain() here because the CF type was created (and already implicitely retained).
	}

	//----------------------------------------------------------------------------------------
	/// Adds a reference to the referenced object.
	/// @param[in] o									Pointer to the referenced object, must not be nullptr.
	//----------------------------------------------------------------------------------------
	template <typename T> static void AddReference(T* o)
	{
		CFRetain(o);
	}

	//----------------------------------------------------------------------------------------
	/// Removes a reference to the referenced object.
	/// @param[in] o									Pointer to the referenced object, must not be nullptr.
	//----------------------------------------------------------------------------------------
	template <typename T> static void RemoveReference(T* o)
	{
		CFRelease(o);
	}

	//----------------------------------------------------------------------------------------
	/// Changes the target of the pointer.
	/// @param[in] o									Reference to the pointer to the old object.
	/// @param[in] newTarget					Pointer to the new target object.
	//----------------------------------------------------------------------------------------
	template <typename T> static void ChangeTarget(T*& o, T* newTarget)
	{
		T* old = o;

		if (newTarget)
			AddReference(newTarget);

		o = newTarget;

		if (old)
			RemoveReference(old);
	}

	//----------------------------------------------------------------------------------------
	/// Changes the target of the reference to a created object returned from an ObjC call.
	/// @param[in] o									Reference to the pointer to the old object.
	/// @param[in] newTarget					Pointer to an already retained target object.
	//----------------------------------------------------------------------------------------
	template <typename T> static void ChangeTarget(T*& o, ResultMemT<T*> newTarget)
	{
		T* old = o;

		// Nothing else to do here because newTarget was already retained by the ObjC runtime.
		o = newTarget.GetPointer();

		if (old)
			RemoveReference(old);
	}

	//----------------------------------------------------------------------------------------
	/// Moves a target from one pointer to another.
	/// @param[in] srcReference				Reference to the source object pointer.
	/// @param[in] dstReference				Reference to the destination object pointer.
	//----------------------------------------------------------------------------------------
	template <typename T> static void MoveTarget(T*& srcReference, T*& dstReference)
	{
		dstReference = srcReference;
		srcReference = nullptr;
	}

	template <typename R> static ResultRef<typename R::ReferencedType> MakeWritable(R& ref, Bool resetOnError) { return ref.GetPointer(); }

	static const VALUEKIND KIND = VALUEKIND::POINTER_FLAGS;
};

/// Reference for a CoreFoundation object which was created (and hence implicitely retained). The object will released when the CFStrongRef will be destructed.
template <typename REF> class CFStrongRef : public BaseRef<typename std::remove_pointer<REF>::type, CoreFoundationCreatedPointerHandler>
{
	using T = typename std::remove_pointer<REF>::type;
	using Super = BaseRef<T, CoreFoundationCreatedPointerHandler>;
public:
	CFStrongRef() = default;
	//----------------------------------------------------------------------------------------
	/// Assignment of an already retained object (returned by a create or copy method). 
	/// Objects which are returned by other methods have to be retained before assigning them to a CFStrongRef.
	/// See https://developer.apple.com/library/content/documentation/CoreFoundation/Conceptual/CFMemoryMgmt/Concepts/Ownership.html#//apple_ref/doc/uid/20001148-CJBEJBHH
	//----------------------------------------------------------------------------------------
	MAXON_IMPLICIT CFStrongRef(T* o) : Super(ResultPtr<T>(o), 0){ }
	CFStrongRef(const CFStrongRef& src) = default;
	CFStrongRef(CFStrongRef&& src) = default;

	//----------------------------------------------------------------------------------------
	/// Assignment of an already retained object (returned by a create or copy method). 
	/// Objects which are returned by other methods have to be retained before assigning them to a CFStrongRef.
	/// See https://developer.apple.com/library/content/documentation/CoreFoundation/Conceptual/CFMemoryMgmt/Concepts/Ownership.html#//apple_ref/doc/uid/20001148-CJBEJBHH
	//----------------------------------------------------------------------------------------
	CFStrongRef& operator =(T* src)
	{
		Super::PrivateSetTarget(ResultPtr<T>(src));
		return *this;
	}
	CFStrongRef& operator =(const CFStrongRef& src) = default;
	CFStrongRef& operator =(CFStrongRef&& src) = default;
	CFStrongRef& operator =(std::nullptr_t src)
	{
		Super::operator =(nullptr);
		return *this;
	}

	//----------------------------------------------------------------------------------------
	/// Returns the address of the REF. This is often used by CF methods which return the retained
	/// reference of a copy.
	/// @return												Address of REF (equivalent to this).
	//----------------------------------------------------------------------------------------
	REF* GetAddressOf()
	{
		return reinterpret_cast<REF*>(this);
	}
};

class NSCreatedPointerHandler
{
public:
	//----------------------------------------------------------------------------------------
	/// Sets the initial reference to a newly allocated object (slightly more efficient than AddReference).
	/// @param[in] o									Pointer to the referenced object, must not be nullptr.
	//----------------------------------------------------------------------------------------
	template <typename T> static void InitialReference(const T* o)
	{
		// Do not [o retain] here because the NS type was created (and already implicitely retained).
	}

	//----------------------------------------------------------------------------------------
	/// Adds a reference to the referenced object.
	/// @param[in] o									Pointer to the referenced object, must not be nullptr.
	//----------------------------------------------------------------------------------------
	template <typename T> static void AddReference(T* o);

	//----------------------------------------------------------------------------------------
	/// Removes a reference to the referenced object.
	/// @param[in] o									Pointer to the referenced object, must not be nullptr.
	//----------------------------------------------------------------------------------------
	template <typename T> static void RemoveReference(T* o);

	//----------------------------------------------------------------------------------------
	/// Changes the target of the pointer.
	/// @param[in] o									Reference to the pointer to the old object.
	/// @param[in] newTarget					Pointer to the new target object.
	//----------------------------------------------------------------------------------------
	template <typename T> static void ChangeTarget(T*& o, T* newTarget)
	{
		T* old = o;

		if (newTarget)
			AddReference(newTarget);

		o = newTarget;

		if (old)
			RemoveReference(old);
	}

	//----------------------------------------------------------------------------------------
	/// Changes the target of the reference to a created object returned from an ObjC call.
	/// @param[in] o									Reference to the pointer to the old object.
	/// @param[in] newTarget					Pointer to an already retained target object.
	//----------------------------------------------------------------------------------------
	template <typename T> static void ChangeTarget(T*& o, ResultPtr<T> newTarget)
	{
		T* old = o;

		// Nothing else to do here because newTarget was already retained by the ObjC runtime.
		o = newTarget.GetPointer();

		if (old)
			RemoveReference(old);
	}

	//----------------------------------------------------------------------------------------
	/// Moves a target from one BaseRef to another.
	/// This is being called when a BaseRef is moved to another BaseRef using operator =(&&).
	/// @param[in] srcReference				Reference to the source object pointer.
	/// @param[in] dstReference				Reference to the destination object pointer.
	//----------------------------------------------------------------------------------------
	template <typename T> static void MoveTarget(T*& srcReference, T*& dstReference)
	{
		T* target = srcReference;
		T* oldTarget = dstReference;

		srcReference = nullptr;
		dstReference = target;

		// Remove reference to the old target of the destination.
		if (oldTarget)
			RemoveReference(oldTarget);
	}

	template <typename R> static ResultRef<typename R::ReferencedType> MakeWritable(R& ref, Bool resetOnError) { return ref.GetPointer(); }

	static const VALUEKIND KIND = VALUEKIND::POINTER_FLAGS;
};

#ifdef __OBJC__
template <typename T> struct NSRawPointerOf
{
	static NSRawPointerOf* Convert(T* r)
	{
		return (NSRawPointerOf*) ((__bridge void*)r);
	}
	T* GetPointer() __attribute__((ns_returns_autoreleased))
	{
		return (__bridge T*)((void*) this);
	}
};
#endif

#if __has_feature(objc_arc)

/// Reference for a ObjC object which was created (and hence implicitely retained). The object will released when the NSStrongRef will be destructed.
template <typename T> class NSStrongRef
{
public:
	NSStrongRef() = default;
	//----------------------------------------------------------------------------------------
	/// Assignment of an already retained object (returned by a alloc, new or copy method). 
	/// Objects which are returned by other methods have to be retained before assigning them to a NSStrongRef.
	/// See https://developer.apple.com/library/content/documentation/Cocoa/Conceptual/MemoryMgmt/Articles/mmRules.html#//apple_ref/doc/uid/20000994-BAJHFBGH.
	//----------------------------------------------------------------------------------------
	MAXON_IMPLICIT NSStrongRef(T* o) : _object(o) { }
	NSStrongRef(const NSStrongRef& src) = default;
	NSStrongRef(NSStrongRef&& src) = default;

	//----------------------------------------------------------------------------------------
	/// Assignment of an already retained object (returned by a alloc, new or copy method). 
	/// Objects which are returned by other methods have to be retained before assigning them to a NSStrongRef.
	/// See https://developer.apple.com/library/content/documentation/Cocoa/Conceptual/MemoryMgmt/Articles/mmRules.html#//apple_ref/doc/uid/20000994-BAJHFBGH.
	//----------------------------------------------------------------------------------------
	NSStrongRef& operator =(T* src)
	{
		_object = src;
		return *this;
	}
	NSStrongRef& operator =(const NSStrongRef& src) = default;
	NSStrongRef& operator =(NSStrongRef&& src) = default;
	NSStrongRef& operator =(std::nullptr_t src)
	{
		_object = nullptr;
		return *this;
	}

	operator T*() { return _object; }
	T* operator ->() { return _object; }
	T& operator *() { return *_object; }

	operator const T*() const { return _object; }
	const T* operator ->() const { return _object; }
	const T& operator *() const { return *_object; }

	T* GetPointer() const
	{
		return _object;
	}

	void SetAndRetain(__unsafe_unretained T* src)
	{
		_object = src;
	}

	HashInt GetHashCode() const { return DefaultCompare::GetHashCode(_object); }

public:
	__strong T* _object = nullptr;
};

#else

/// Reference for a ObjC object which was created (and hence implicitely retained). The object will released when the NSStrongRef will be destructed.
template <typename T> class NSStrongRef : public BaseRef<T, NSCreatedPointerHandler>
{
	using Super = BaseRef<T, NSCreatedPointerHandler>;
public:
	NSStrongRef() = default;
	//----------------------------------------------------------------------------------------
	/// Assignment of an already retained object (returned by a alloc, new or copy method). 
	/// Objects which are returned by other methods have to be retained before assigning them to a NSStrongRef.
	/// See https://developer.apple.com/library/content/documentation/Cocoa/Conceptual/MemoryMgmt/Articles/mmRules.html#//apple_ref/doc/uid/20000994-BAJHFBGH.
	//----------------------------------------------------------------------------------------
	MAXON_IMPLICIT NSStrongRef(T* o) : Super(ResultPtr<T>(o), 0) { }
	NSStrongRef(const NSStrongRef& src) = default;
	NSStrongRef(NSStrongRef&& src) = default;

	//----------------------------------------------------------------------------------------
	/// Assignment of an already retained object (returned by a alloc, new or copy method). 
	/// Objects which are returned by other methods have to be retained before assigning them to a NSStrongRef.
	/// See https://developer.apple.com/library/content/documentation/Cocoa/Conceptual/MemoryMgmt/Articles/mmRules.html#//apple_ref/doc/uid/20000994-BAJHFBGH.
	//----------------------------------------------------------------------------------------
	NSStrongRef& operator =(T* src)
	{
		Super::PrivateSetTarget(ResultPtr<T>(src));
		return *this;
	}
	NSStrongRef& operator =(const NSStrongRef& src) = default;
	NSStrongRef& operator =(NSStrongRef&& src) = default;
	NSStrongRef& operator =(std::nullptr_t src)
	{
		Super::operator =(nullptr);
		return *this;
	}

#ifdef __OBJC__
	void SetAndRetain(T* src)
	{
	#if __has_feature(objc_arc)
		// TODO: (Sven) ARC
	#else
		[src retain];
	#endif
		this->operator =(src);
	}
#endif

};

#ifdef __OBJC__

template <typename T> void NSCreatedPointerHandler::AddReference(T* o)
{
	[o retain];
}

template <typename T> void NSCreatedPointerHandler::RemoveReference(T* o)
{
	[o release];
}

#endif
#endif

template <typename REF> struct NSStrongId : public NSStrongRef<typename std::remove_pointer<REF>::type>
{
	NSStrongId() = default;
	template <typename T> MAXON_IMPLICIT NSStrongId(T* o) : NSStrongRef<typename std::remove_pointer<REF>::type>(o) { }
	NSStrongId(const NSStrongId& src) = default;
	NSStrongId(NSStrongId&& src) = default;

	NSStrongId& operator =(const NSStrongId& src) = default;
	NSStrongId& operator =(NSStrongId&& src) = default;

	NSStrongId& operator =(std::nullptr_t src)
	{
		NSStrongRef<typename std::remove_pointer<REF>::type>::operator =(nullptr);
		return *this;
	}
};

/// compatibility: Use CFStrongRef
template <typename T> using CFAutoReference = CFStrongRef<T>;
/// compatibility: Use NSStrongRef
template <typename T> using NSAutoReference = NSStrongRef<T>;

} // namespace maxon


#endif // MAC_CFHELPERS_H__
