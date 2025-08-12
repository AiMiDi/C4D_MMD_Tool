#ifndef SIMPLE_OBSERVABLE_H__
#define SIMPLE_OBSERVABLE_H__

#include "maxon/arwlock.h"
#include "maxon/delegate.h"
#include "maxon/hashmap.h"
#include "maxon/synchronized.h"

namespace maxon
{

//----------------------------------------------------------------------------------------
/// NoOpLock is an implementation of the lock concept which does no locking at all.
/// It can be used for templates which allow to choose the lock implementation via a template parameter
/// when you don't need locking.
//----------------------------------------------------------------------------------------
struct NoOpLock
{
	void ReadLock() {}
	void ReadUnlock() {}
	void WriteLock() {}
	void WriteUnlock() {}
};

//----------------------------------------------------------------------------------------
/// A SubscriptionSet allows to add values to itself and to control their lifetime
/// within the set by a handle. For example this can be used to manage a set of listeners.
/// This class is completely thread-safe (when LOCK is a proper lock), so elements can be
/// inserted, removed and get in parallel.
///
/// You have to use the Create function to create a new SubscriptionSet.
///
/// @tparam T											Type of values.
/// @tparam WEAK_HANDLE						True if handles shall hold a weak reference to the set, false (the default) for a strong reference.
/// @tparam MAP										A map selector template to choose the underlying map implementation to use.
/// @tparam LOCK									The lock implementation to use, for example ARWLock, Spinlock, RWSpinlock or NoOpLock.
//----------------------------------------------------------------------------------------
template <typename T, Bool WEAK_HANDLE = false, typename MAP = HashMapSelector<>, typename LOCK = ARWLock> class SubscriptionSet
{
public:
	//----------------------------------------------------------------------------------------
	/// Creates a new empty SubscriptionSet.
	/// @return												A new subscription set.
	//----------------------------------------------------------------------------------------
	static Result<StrongRef<SubscriptionSet>> Create()
	{
		return NewObj(SubscriptionSet);
	}

	//----------------------------------------------------------------------------------------
	/// Inserts a new element into the set. The lifetime of the element within the set
	/// will be tied to the lifetime of the returned handle, i.e., you have to keep the returned
	/// handle alive as long as the element shall be in the set.
	/// @param[in] value							The value to insert as new element.
	/// @return												A handle to control the lifetime of the new element.
	//----------------------------------------------------------------------------------------
	template <typename A> Result<GenericData> Insert(A&& value)
	{
		iferr_scope;
		const UInt id = _lastId.SwapIncrement();
		GenericData gd;
		gd.Set(Remove(this, id)) iferr_return;
		_map.Write()->Insert(id, std::forward<A>(value)) iferr_return;
		return gd;
	}

	//----------------------------------------------------------------------------------------
	/// Adds all current elements of the set to the given array. Note that the order of elements
	/// may be unspecified, that depends on the chosen MAP.
	/// For example a HashMap leads to unspecified order, while a sorted ArrayMap guarantees insertion order.
	/// @param[in] array							The array to which all current elements of the set shall be added.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	template <typename ARRAY> Result<void> GetValues(ARRAY& array) const
	{
		iferr_scope;
		auto r = _map.Read();
		array.EnsureCapacity(array.GetCount() + r->GetCount()) iferr_return;
		for (const T& v : r->GetValues())
		{
			array.Append(v) iferr_return;
		}
		return OK;
	}

private:
	SubscriptionSet() = default;
	MAXON_DISALLOW_COPY_AND_ASSIGN(SubscriptionSet);

	struct Remove
	{
		Remove(SubscriptionSet* list, UInt id) : _list(list), _id(id)
		{
		}

		Remove(Remove&&) = default;

		~Remove()
		{
			const StrongRef<SubscriptionSet>& ref = _list;
			if (ref)
			{
				ref->_map.Write()->Erase(_id);
			}
		}

		typename std::conditional<WEAK_HANDLE, WeakRef<StrongRef<SubscriptionSet>>, StrongRef<SubscriptionSet>>::type _list;
		UInt _id;
	};

	using Map = typename MAP::template Type<UInt, T>;
	SynchronizedValue<Map, LOCK> _map;

	AtomicUInt _lastId;
};


class GenericSimpleObservable
{
protected:
	using Set = SubscriptionSet<StrongRef<DelegateBase>>;

	Result<void> Init()
	{
		iferr_scope;
		_listeners = Set::Create() iferr_return;
		return OK;
	}

	Result<GenericData> AddListener(DelegateBase&& listener) const
	{
		iferr_scope;
		CheckState(_listeners);
		StrongRef<DelegateBase> ref = NewObj(DelegateBase, std::move(listener)) iferr_return;
		return _listeners->Insert(std::move(ref));
	}

	Result<void> GetListeners(BaseArray<StrongRef<DelegateBase>>& listeners) const
	{
		iferr_scope;
		if (_listeners)
		{
			_listeners->GetValues(listeners) iferr_return;
		}
		return OK;
	}

private:
	StrongRef<Set> _listeners;
};


template <typename FUNC> class SimpleObservable;

template <typename RESULT, typename... ARGS> class SimpleObservable<RESULT(ARGS...)> : protected GenericSimpleObservable
{
public:
	using GenericSimpleObservable::Init;

	Result<GenericData> AddListener(Delegate<RESULT(ARGS...)>&& listener) const
	{
		return GenericSimpleObservable::AddListener(std::move(listener));
	}

	Result<void> Notify(ARGS... args) const
	{
		iferr_scope;
		BaseArray<StrongRef<DelegateBase>> listeners;
		GetListeners(listeners) iferr_return;
		for (const StrongRef<DelegateBase>& d : listeners)
		{
			static_cast<Delegate<RESULT(ARGS...)>&>(*d)(std::forward<ARGS>(args)...) iferr_return;
		}
		return OK;
	}

	static MAXON_ATTRIBUTE_FORCE_INLINE const SimpleObservable& DefaultValue()
	{
		return GetZeroRef<SimpleObservable>();
	}
};

template <typename... ARGS> class SimpleObservable<void(ARGS...)> : protected GenericSimpleObservable
{
public:
	using GenericSimpleObservable::Init;

	Result<GenericData> AddListener(Delegate<void(ARGS...)>&& listener) const
	{
		return GenericSimpleObservable::AddListener(std::move(listener));
	}

	Result<void> Notify(ARGS... args) const
	{
		iferr_scope;
		BaseArray<StrongRef<DelegateBase>> listeners;
		GetListeners(listeners) iferr_return;
		for (const StrongRef<DelegateBase>& d : listeners)
		{
			static_cast<Delegate<void(ARGS...)>&>(*d)(std::forward<ARGS>(args)...);
		}
		return OK;
	}

	static MAXON_ATTRIBUTE_FORCE_INLINE const SimpleObservable& DefaultValue()
	{
		return GetZeroRef<SimpleObservable>();
	}
};

}

#endif // SIMPLE_OBSERVABLE_H__
