#ifndef LOCKED_RESOURCE_MAP_H__
#define LOCKED_RESOURCE_MAP_H__

#include "maxon/hashmap.h"
#include "maxon/conditionvariable.h"
#include "maxon/spinlock.h"

namespace maxon
{

/// @addtogroup THREADING Threading
/// @{


//----------------------------------------------------------------------------------------
/// Helper class for LockedResourceMap
/// THREADSAFE.
//----------------------------------------------------------------------------------------
template <typename ENTRY> class LockedResourceHelper : public ENTRY
{
	MAXON_DISALLOW_COPY_AND_ASSIGN(LockedResourceHelper);

public:
	template <typename... TYPES> explicit LockedResourceHelper(TYPES&&... args) : ENTRY(std::forward<TYPES>(args)...)
	{
	}

	LockedResourceHelper(LockedResourceHelper&& src) : ENTRY(std::move(src))
	{
	}

	MAXON_OPERATOR_MOVE_ASSIGNMENT(LockedResourceHelper);

	Result<void> CreateSignal()
	{
		iferr_scope;
		_signal = ConditionVariableRef::Create() iferr_return;
		return OK;
	}

	void DeleteSignal()
	{
		_signal = nullptr;
	}

	ConditionVariableRef& GetSignal()
	{
		return _signal;
	}

	void SetError(const Error& error)
	{
		_creationError = error;
	}

	Error GetError() const
	{
		return _creationError;
	}

private:
	ConditionVariableRef	_signal;
	Error									_creationError;
};


//----------------------------------------------------------------------------------------
/// LockedResourceMap simplifies the creation, calculation or load of cpu expensive resources from different threads.
/// E.g. If the program want to load images from different threads but want to keep it only once in memory
/// this class manages all locking and threading using ConditionVariables for ideal performance with minimum locking.
/// A callback must be provided in the CreateOrGetEntry function to load/calculate the value when the key is created the first time.
///
/// Example:
/// @code
/// LockedResourceMap<Url, ImageLayerRef> g_lockedResource;
/// Url url = ...;
///
/// ImageLayerRef image = g_lockedResource.CreateOrGetEntryCopy(url,
/// 	[](const Url& url, ImageLayerRef* createResource) -> Result<void>
/// 	{
///			iferr_scope;
///			ImageLayerRef img = ImageLayerClasses::RASTER().Create() iferr_return;
/// 		img.Load(url) iferr_return;
/// 		*createResource = std::move(img);
/// 		return OK;
/// 	}) iferr_return;
/// ... use 'image' for whatever ...
/// @endcode
///
/// THREADSAFE.
/// @tparam HASHTYPE							Hash key type of the class. Each entry is stored under this unique hash key.
/// @tparam ENTRY									Value to store under the key.
//----------------------------------------------------------------------------------------
template<typename HASHTYPE, typename ENTRY> class LockedResourceMap : public HashMap<HASHTYPE, LockedResourceHelper<ENTRY>>
{
private:
	MAXON_DISALLOW_COPY_AND_ASSIGN(LockedResourceMap);
public:
	LockedResourceMap() : HashMap<HASHTYPE, LockedResourceHelper<ENTRY>>() { }
	LockedResourceMap(LockedResourceMap&& src) : HashMap<HASHTYPE, LockedResourceHelper<ENTRY>>(std::move(src)) { }

	MAXON_OPERATOR_MOVE_ASSIGNMENT(LockedResourceMap);

	//----------------------------------------------------------------------------------------
	/// Creates the value if the key is not created yet or gets the value for the given hash key.
	/// @param[in] hashKey						Key under which a resource should be created and returned.
	/// @param[in] createdCallback		If the key is accessed the first time this callback will be called.
	/// 															The calculation/loading is lock free. All other threads that ask for the same resource
	/// 															in the meanwhile will put on hold using a ConditionVariable.
	/// @return												Returns the reference to the entry for the given hashKey. The map is still locked.
	/// 															You must call GetLock().Unlock() as soon as you don't need access to the element anymore.
	/// 															Keep the lock as short as possible. The best way is to copy the data you need and unlock it.
	/// 															In case of error the hash map lock is already released.
	//----------------------------------------------------------------------------------------
	Result<ENTRY&> CreateOrGetEntry(const HASHTYPE& hashKey, const Delegate<Result<void>(const HASHTYPE& hashKey, ENTRY* createResource)>& createdCallback)
	{
		Bool isLocked = false;
		iferr_scope_handler
		{
			// release the lock in all error cases
			if (isLocked)
				_hashLock.Unlock();
			return err;
		};

		_hashLock.Lock();
		isLocked = true;

		Bool created = false;
		LockedResourceHelper<ENTRY>& entry = this->InsertKey(hashKey, created) iferr_return;

		if (created)
		{
			// Create a signal, so that other can wait
			entry.CreateSignal() iferr_return;

			// do the callback in unlocked state
			_hashLock.Unlock();
			isLocked = false;

			Result<void> res = createdCallback(hashKey, &entry);

			// lock again
			_hashLock.Lock();
			isLocked = true;
			entry.GetSignal().Set();

			// free the signal because it's no longer needed once it's signaled
			entry.DeleteSignal();

			_changed = true;

			iferr (res)
			{
				entry.SetError(err);
				// don't unlock, iferr_scope unlocks.
				iferr_throw(err);
			}
		}
		else
		{
			// copy the signal ref, because the first job creates it and deletes the variable once it's done.
			// so if the signal is set it's within the calculation and we need to wait for it
			ConditionVariableRef signal = entry.GetSignal();

			// check if value is already calculated
			if (signal)
			{
				// if value is not valid yet, unlock and wait
				_hashLock.Unlock();
				isLocked = false;

				// wait for the signal
				if (!signal.Wait(TIMEVALUE_INFINITE, WAITMODE::RETURN_ON_CANCEL))
					iferr_throw(ThreadCancelledError(MAXON_SOURCE_LOCATION));

				// lock again
				_hashLock.Lock();
				isLocked = true;
			}

			// if the resource threw an error on creation, return this error also for all other gets
			Error error = entry.GetError();
			if (error)
				iferr_throw(error);
		}

		return entry;
	}

	//----------------------------------------------------------------------------------------
	/// Creates the value if the key is not created yet or gets a copy of the value for the given hash key.
	/// This function is ideal to use with reference counted objects (e.g. ImageLayerRef, ObjectRef).
	/// @param[in] hashKey						Key under which a resource should be created and returned.
	/// @param[in] createdCallback		If the key is accessed the first time this callback will be called.
	/// 															The calculation/loading is lock free. All other threads that ask for the same resource
	/// 															in the meanwhile will put on hold using a ConditionVariable.
	/// @return												Returns a copy of the entry for the given hashKey. The map is NOT locked after calling this function.
	//----------------------------------------------------------------------------------------
	Result<ENTRY> CreateOrGetEntryCopy(const HASHTYPE& hashKey, const Delegate<Result<void>(const HASHTYPE& hashKey, ENTRY* createResource)>& createdCallback)
	{
		// get the copy
		iferr (ENTRY res = CreateOrGetEntry(hashKey, createdCallback))
			return err;
		// unlock the structure
		_hashLock.Unlock();
		// return the copy
		return std::move(res);
	}

	Spinlock& GetLock() { return _hashLock; }

	Bool IsChanged() const { return _changed; }
	void SetChanged(Bool changed) { _changed = changed; }

private:
	Spinlock		_hashLock;
	Bool				_changed;
};

/// @}

} // namespace maxon

#ifdef MAXON_COMPILER_CLANG // Bug in Clang, LockedResouceHelper<MissingEntry> is reported to be copy-constructible in command_server_manager.cpp. This does not happen in a stripped-down version.
namespace std
{
template <typename E> struct is_copy_constructible<maxon::LockedResourceHelper<E>> : std::false_type
{
};
}
#endif

#endif // LOCKED_RESOURCE_MAP_H__
