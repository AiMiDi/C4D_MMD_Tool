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

/// Reference for a CoreFoundation object which was created (and hence implicitely retained). The object will released when the CFAutoReference will be destructed.
template <typename REF> class CFAutoReference : public BaseRef<typename std::remove_pointer<REF>::type, CoreFoundationCreatedPointerHandler>
{
	using T = typename std::remove_pointer<REF>::type;
	using Super = BaseRef<T, CoreFoundationCreatedPointerHandler>;
public:
	CFAutoReference() = default;
	//----------------------------------------------------------------------------------------
	/// Assignment of an already retained object (returned by a create or copy method). 
	/// Objects which are returned by other methods have to be retained before assigning them to a CFAutoReference.
	/// See https://developer.apple.com/library/content/documentation/CoreFoundation/Conceptual/CFMemoryMgmt/Concepts/Ownership.html#//apple_ref/doc/uid/20001148-CJBEJBHH
	//----------------------------------------------------------------------------------------
	MAXON_IMPLICIT CFAutoReference(T* o) : Super(ResultPtr<T>(o), 0){ }
	CFAutoReference(const CFAutoReference& src) = default;
	CFAutoReference(CFAutoReference&& src) = default;

	//----------------------------------------------------------------------------------------
	/// Assignment of an already retained object (returned by a create or copy method). 
	/// Objects which are returned by other methods have to be retained before assigning them to a CFAutoReference.
	/// See https://developer.apple.com/library/content/documentation/CoreFoundation/Conceptual/CFMemoryMgmt/Concepts/Ownership.html#//apple_ref/doc/uid/20001148-CJBEJBHH
	//----------------------------------------------------------------------------------------
	CFAutoReference& operator =(T* src)
	{
		Super::PrivateSetTarget(ResultPtr<T>(src));
		return *this;
	}
	CFAutoReference& operator =(const CFAutoReference& src) = default;
	CFAutoReference& operator =(CFAutoReference&& src) = default;
	CFAutoReference& operator =(std::nullptr_t src)
	{
		Super::operator =(nullptr);
		return *this;
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

/// Reference for a ObjC object which was created (and hence implicitely retained). The object will released when the NSAutoReference will be destructed.
template <typename T> class NSAutoReference : public BaseRef<T, NSCreatedPointerHandler>
{
	using Super = BaseRef<T, NSCreatedPointerHandler>;
public:
	NSAutoReference() = default;
	//----------------------------------------------------------------------------------------
	/// Assignment of an already retained object (returned by a alloc, new or copy method). 
	/// Objects which are returned by other methods have to be retained before assigning them to a NSAutoReference.
	/// See https://developer.apple.com/library/content/documentation/Cocoa/Conceptual/MemoryMgmt/Articles/mmRules.html#//apple_ref/doc/uid/20000994-BAJHFBGH.
	//----------------------------------------------------------------------------------------
	MAXON_IMPLICIT NSAutoReference(T* o) : Super(ResultPtr<T>(o), 0) { }
	NSAutoReference(const NSAutoReference& src) = default;
	NSAutoReference(NSAutoReference&& src) = default;

	//----------------------------------------------------------------------------------------
	/// Assignment of an already retained object (returned by a alloc, new or copy method). 
	/// Objects which are returned by other methods have to be retained before assigning them to a NSAutoReference.
	/// See https://developer.apple.com/library/content/documentation/Cocoa/Conceptual/MemoryMgmt/Articles/mmRules.html#//apple_ref/doc/uid/20000994-BAJHFBGH.
	//----------------------------------------------------------------------------------------
	NSAutoReference& operator =(T* src)
	{
		Super::PrivateSetTarget(ResultPtr<T>(src));
		return *this;
	}
	NSAutoReference& operator =(const NSAutoReference& src) = default;
	NSAutoReference& operator =(NSAutoReference&& src) = default;
	NSAutoReference& operator =(std::nullptr_t src)
	{
		Super::operator =(nullptr);
		return *this;
	}
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

} // namespace maxon


#endif // MAC_CFHELPERS_H__
