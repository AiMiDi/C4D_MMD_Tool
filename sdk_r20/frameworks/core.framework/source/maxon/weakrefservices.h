#ifndef WEAKREFSERVICES_H__
#define WEAKREFSERVICES_H__

#include "maxon/interfacebase.h"

namespace maxon
{

/// @addtogroup STRUCTURES
/// @{

struct WeakRefBase;
struct WeakRefTargetBase;
using StrongRefObserverCallback = Bool (*)(void* callbackData, const void* target);
using MemoryMetadataDestructor = void (*)(void* metadata);


/// Proxy object to access memory metadata.
/// While the proxy object exists the metadata for the target is locked and cannot be accessed or modified
/// by other threads (in fact all metadata for the target including weak references is locked). Therefore
/// best practice is to destroy the proxy object as soon as possible.
struct MemoryMetadataProxy
{
	MAXON_DISALLOW_COPY_AND_ASSIGN(MemoryMetadataProxy);

public:
	MemoryMetadataProxy() = default;
	MemoryMetadataProxy(MemoryMetadataProxy&&) = default;
	explicit MemoryMetadataProxy(WeakRefTargetBase* weakRefTarget, void* metadata) : _weakRefTarget(weakRefTarget), _metadata(metadata) { }

	MAXON_OPERATOR_MOVE_ASSIGNMENT(MemoryMetadataProxy);
	
	//----------------------------------------------------------------------------------------
	/// Destructs the proxy object and unlocks access to the metadata.
	//----------------------------------------------------------------------------------------
	~MemoryMetadataProxy();

	explicit operator Bool() const
	{
		return _weakRefTarget != nullptr;
	}

	//----------------------------------------------------------------------------------------
	/// Returns the memory metadata (or an error if there wasn't any).
	/// @return												Memory metadata on success.
	//----------------------------------------------------------------------------------------
	Result<void*> Get() const
	{
		if (MAXON_UNLIKELY(_weakRefTarget == nullptr))
			return CreateError(MAXON_SOURCE_LOCATION, ERROR_TYPE::ILLEGAL_ARGUMENT);
		return _metadata;
	}

private:
	WeakRefTargetBase* _weakRefTarget = nullptr;
	void* _metadata = nullptr;
};

class WeakRefServices
{
	MAXON_INTERFACE_NONVIRTUAL(WeakRefServices, MAXON_REFERENCE_NONE, "net.maxon.interface.weakrefservices");

public:
	//----------------------------------------------------------------------------------------
	/// @param[in] target							Pointer to strongly referenced target object, guaranteed to be valid and not nullptr.
	/// @return												True if there are weak references.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Bool HasWeakReferences(const void* target);

	//----------------------------------------------------------------------------------------
	/// Adds a weak reference to a strongly referenced object.
	/// @note The caller must hold a strong reference to the target object.
	/// @param[in] weakRef						Weak reference.
	/// @param[in] target							Pointer to strongly referenced target object, guaranteed to be valid and not nullptr.
	/// @return												True on success, false if reference could not be created (due to out of memory).
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Bool AddWeakReference(WeakRefBase& weakRef, const void* target);

	//----------------------------------------------------------------------------------------
	/// Removes a weak reference.
	/// @param[in] weakRef						Weak reference to be destructed.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD void RemoveWeakReference(WeakRefBase& weakRef);

	//----------------------------------------------------------------------------------------
	/// Moves a weak reference.
	/// @param[in] dst								Destination
	/// @param[in] src								Source
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD void MoveWeakReference(WeakRefBase& dst, WeakRefBase& src);

	//----------------------------------------------------------------------------------------
	/// Copies a weak reference.
	/// @param[in] dst								Destination
	/// @param[in] src								Source
	/// @return												True on success, false if copying failed (due to out of memory).
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Bool CopyWeakReference(WeakRefBase& dst, const WeakRefBase& src);

	//----------------------------------------------------------------------------------------
	/// Removes all weak references to a strongly referenced object (which is going to be destructed).
	/// @param[in] target							Pointer to strongly referenced target object, guaranteed to be not nullptr.
	/// @return												True if the target can be destructed, false if the ownership has been transferred and the target must not be destructed.
	//----------------------------------------------------------------------------------------
	MAXON_WARN_UNUSED static MAXON_METHOD Bool ClearAllWeakReferences(const void* target);

	//----------------------------------------------------------------------------------------
	/// All weak references to oldTarget will be updated and point to newTarget.
	/// The caller holds a strong reference to the old target.
	/// @param[in] oldTarget					Pointer to old target object (must be valid).
	/// @param[in] newTarget					Pointer to new target object (might be nullptr).
	/// @return												True on success, false if copying failed (due to out of memory).
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Bool TransferAllWeakReferences(const void* oldTarget, const void* newTarget);

	//----------------------------------------------------------------------------------------
	/// Adds an observer which will be invoked before a strongly referenced object is destructed.
	/// The observer can claim (shared) ownership of the target by returning true. In this case it should add a reference to it and destruct it at a later point in time.
	/// @param[in] target							Pointer to strongly referenced target object, guaranteed to be valid and not nullptr.
	/// @param[in] callback						Pointer to the callback.
	/// @param[in] callbackData				Data private to the callback.
	/// @return												True on success, false if reference could not be created (due to out of memory).
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Bool AddObserver(const void* target, StrongRefObserverCallback callback, void* callbackData);

	//----------------------------------------------------------------------------------------
	/// Adds metadata to a target object.
	/// @param[in] target							Pointer to strongly referenced target object, guaranteed to be valid and not nullptr.
	/// @param[in] uniqueId						Unique pointer to an id (either an InternedId or a private static Id).
	/// @param[in] metadata						Pointer to metadata (or the metadata itself).
	/// @param[in] destruct						Optional destructor for the metadata (to be called when the referenced object is destructed).
	/// @return												True on success, false if metadata could not be added (due to out of memory).
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Bool AddMetadata(const void* target, const Id* uniqueId, void* metadata, MemoryMetadataDestructor destruct = nullptr);

	//----------------------------------------------------------------------------------------
	/// Removes metadata from a target object.
	/// @param[in] target							Pointer to strongly referenced target object, guaranteed to be valid and not nullptr.
	/// @param[in] uniqueId						Unique pointer to an id (either an InternedId or a private static Id).
	/// @return												True on success, false if no metadata existed.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Bool EraseMetadata(const void* target, const Id* uniqueId);

	//----------------------------------------------------------------------------------------
	/// Returns a proxy object which allows safe access to the metadata.
	/// @param[in] target							Pointer to strongly referenced target object, guaranteed to be valid and not nullptr.
	/// @param[in] uniqueId						Unique pointer to an id (either an InternedId or a private static Id).
	/// @return												Proxy object for metadata.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD MemoryMetadataProxy GetMetadata(const void* target, const Id* uniqueId);
};

#include "weakrefservices1.hxx"
#include "weakrefservices2.hxx"

/// @}

} // namespace maxon

#endif // WEAKREFSERVICES_H__
