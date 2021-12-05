#ifndef WEAKREFSERVICES_H__
#define WEAKREFSERVICES_H__

#include "maxon/interfacebase.h"

namespace maxon
{

/// @addtogroup STRUCTURES
/// @{

/// The observer might return several flags, if it just observes the destruction it should simply return DEFAULT.
enum class MEMORY_OBSERVER_FLAGS : Int
{
	DEFAULT = 0,												///< Default behaviour: Continue with destruction, observer will be removed.
	CLAIM_SHARED_OWNERSHIP = 1,					///< The observer claims shared ownership of the target, do not destruct the object.
	CLAIM_EXCLUSIVE_OWNERSHIP = 2,			///< The first observer/creator claims exclusive ownership of the target, do not destruct the object.
	KEEP_OBSERVER = 4,									///< Do not delete the observer (usually only makes sense if ownership is claimed).
	INVOKE_WITH_UNLOCKED_TARGET = 8			///< Ask to invoke the observer again without the target being locked (if you need to destruct associated objects).
} MAXON_ENUM_FLAGS(MEMORY_OBSERVER_FLAGS);

/// The observer gets information about the target via the state parameter.
enum class MEMORY_OBSERVER_STATE : Int
{
	DEFAULT = 0,
	TARGET_IS_LOCKED = 1,								///< The target is locked and you must not directly or indireclty modify itself or any related objects.
	TARGET_HAS_EXCLUSIVE_OWNERSHIP = 2	///< The target is exclusively owned and you cannot claim shared ownership.
} MAXON_ENUM_FLAGS(MEMORY_OBSERVER_STATE);

struct WeakRefBase;
struct WeakRefTargetBase;
using MemoryObserverCallback = MEMORY_OBSERVER_FLAGS (*)(void* callbackData, const void* target, MEMORY_OBSERVER_STATE state);
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
	/// Returns true if there currently are weak references to the target. This does not take other metadata into account, just the weak references.
	/// @param[in] target							Pointer to strongly referenced target object, guaranteed to be valid and not nullptr.
	/// @return												True if there are weak references to the target.
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
	/// The observer can claim (shared) ownership of the target by returning CLAIM_OWNERSHIP. In
	/// this case it should add a reference to it and destruct it at a later point in time. While
	/// the observer is called the internal metadata structure of the target is locked. You can
	/// request to be invoked after the target has been unlocked.
	/// @note You must not create or delete weak references or metadata which refer to the target
	/// inside the observer when the target is locked!
	/// @note Since the observer is also performance critical it should be as short as possible
	/// and should only call code with known implications.
	/// @param[in] target							Pointer to strongly referenced target object, guaranteed to be valid and not nullptr.
	/// @param[in] callback						Pointer to the callback.
	/// @param[in] callbackData				Data private to the callback.
	/// @return												True on success, false if reference could not be created (due to out of memory).
	/// @MAXON_ANNOTATION{methodId="AddObserver@a3d20b51c4446a71"->"AddObserver@1cad72fa82c5db6e"}
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Bool AddObserver(const void* target, MemoryObserverCallback callback, void* callbackData);

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

	static MAXON_METHOD Result<Bool> BrowseAllWeakReferences(const void* oldTarget, const ValueReceiver<WeakRefBase*>& receiver);
};

#ifdef WEAKREF_H__

//----------------------------------------------------------------------------------------
/// A FatWeakRef is like a WeakRef but larger. It requires less memory allocations and less indirections on access.
//----------------------------------------------------------------------------------------
template <typename REFERENCE> class FatWeakRef : public WeakRef<REFERENCE>
{
public:
	FatWeakRef()  : WeakRef<REFERENCE>(&_proxyWeakRefTarget) { }

	~FatWeakRef() { }

	MAXON_IMPLICIT FatWeakRef(const REFERENCE& strongReference) : WeakRef<REFERENCE>(&_proxyWeakRefTarget)
	{
		auto& ptr = GetBaseRef(strongReference);
		if (ptr)
			std::remove_reference<decltype(ptr)>::type::Handler::AddWeakReference(ptr.GetPointer(), *this);
	}

	//----------------------------------------------------------------------------------------
	/// Copy constructs a weak reference.
	/// @param[in] src								Source weak reference.
	//----------------------------------------------------------------------------------------
	MAXON_IMPLICIT FatWeakRef(const FatWeakRef& src) : WeakRef<REFERENCE>(&_proxyWeakRefTarget)
	{
		if (WeakRefServices::CopyWeakReference(*this, src) == false)
			DebugStop();
	}

	//----------------------------------------------------------------------------------------
	/// Copy constructs a weak reference.
	/// @param[in] src								Source weak reference.
	//----------------------------------------------------------------------------------------
	MAXON_IMPLICIT FatWeakRef(const WeakRef<REFERENCE>& src) : WeakRef<REFERENCE>(&_proxyWeakRefTarget)
	{
		if (WeakRefServices::CopyWeakReference(*this, src) == false)
			DebugStop();
	}

	//----------------------------------------------------------------------------------------
	/// Copy constructs a weak reference.
	/// @param[in] src								Source weak reference.
	//----------------------------------------------------------------------------------------
	MAXON_IMPLICIT FatWeakRef(WeakRef<REFERENCE>&& src) : WeakRef<REFERENCE>(&_proxyWeakRefTarget)
	{
		WeakRefServices::MoveWeakReference(*this, src);
	}

	//----------------------------------------------------------------------------------------
	/// Move constructs a weak reference.
	/// @param[in] src								Source weak reference.
	//----------------------------------------------------------------------------------------
	MAXON_IMPLICIT  FatWeakRef(FatWeakRef&& src) : WeakRef<REFERENCE>(&_proxyWeakRefTarget)
	{
		WeakRefServices::MoveWeakReference(*this, src);
	}

	//----------------------------------------------------------------------------------------
	/// Moves a weak reference.
	/// @param[in] src								Source weak reference.
	/// @return												*this.
	//----------------------------------------------------------------------------------------
	MAXON_OPERATOR_MOVE_ASSIGNMENT(FatWeakRef);

	//----------------------------------------------------------------------------------------
	/// Adds a strong reference.
	/// @param[in] strongReference		BaseRef with strong reference to an object.
	/// @return												*this.
	//----------------------------------------------------------------------------------------
	FatWeakRef& operator =(const REFERENCE& strongReference)
	{
		// Remove the old weak reference if any.
		if (_weakRefTarget != nullptr)
			this->~WeakRef();

		auto& ptr = GetBaseRef(strongReference);
		if (ptr)
			std::remove_reference<decltype(ptr)>::type::Handler::AddWeakReference(ptr.GetPointer(), *this);

		return *this;
	}

	//----------------------------------------------------------------------------------------
	// Removes the weak reference.
	//----------------------------------------------------------------------------------------
	FatWeakRef& operator =(std::nullptr_t t)
	{
		if (_weakRefTarget != nullptr)
		{
			this->~FatWeakRef();
			new (this) FatWeakRef();
		}
		return *this;
	}

	//----------------------------------------------------------------------------------------
	/// Returns a strong reference. If the weak referenced object was already released a
	/// null reference will be returned.
	/// @return												Strong reference to the target or null.
	//----------------------------------------------------------------------------------------
	operator REFERENCE() const
	{
		// Read directly from the proxy target instead of using the indirection via WeakRefBase::data.
		const void* target = _proxyWeakRefTarget.Lock();
		REFERENCE strongReference;

		if (target)
		{
			auto ptr = GetBaseRef(strongReference);

			if (decltype(ptr)::Handler::CreateStrongReference((typename REFERENCE::ReferencedType*) target))
				*(typename REFERENCE::ReferencedType**) &strongReference = (typename REFERENCE::ReferencedType*) target;
		}

		_proxyWeakRefTarget.Unlock(target);
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

	WeakRefTargetBase& GetProxyWeakRefTarget() const
	{
		return _proxyWeakRefTarget;
	}

	Bool HasWeakRefTarget() const
	{
		return _weakRefTarget != nullptr;
	}

private:
	template <typename REFERENCETYPE> static typename REFERENCETYPE::BaseRefType& GetBaseRef(const REFERENCETYPE& strongReference)
	{
		return const_cast<typename REFERENCETYPE::BaseRefType&>(strongReference.GetBaseRef());
	}

	template <typename T, typename HANDLER> static BaseRef<T, HANDLER>& GetBaseRef(const BaseRef<T, HANDLER>& strongReference)
	{
		return const_cast<BaseRef<T, HANDLER>&>(strongReference);
	}

private:
	mutable WeakRefTargetBase _proxyWeakRefTarget;
	mutable void* _weakRefTarget = nullptr;
	void* _private[3];
};

#ifdef MAXON_TARGET_64BIT
	static_assert(sizeof(FatWeakRef<StrongRef<Char>>) == 48, "FatWeakRef should have the same size as WeakRefBase plus WeakRefProxy.");
#else
	static_assert(sizeof(FatWeakRef<StrongRef<Char>>) == 24, "FatWeakRef should have the same size as WeakRefBase plus WeakRefProxy.");
#endif

#endif

#include "weakrefservices1.hxx"
#include "weakrefservices2.hxx"

/// @}

} // namespace maxon

#endif // WEAKREFSERVICES_H__
