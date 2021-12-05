#ifndef LRUHASHMAP_H__
#define LRUHASHMAP_H__



#include "maxon/hashmap.h"
#include "maxon/baselist.h"



namespace maxon
{

//----------------------------------------------------------------------------------------
/// LRUHashMap is a specialized HashMap which is able to restrict the number of elements in the HashMap.
/// The map keeps the LRU (last recently used) elements and destroys the most unused values if a the
/// number of elements exceeds the limit (MAXENTRIES).
/// The class can be used to cache a limited number of elements.
/// @tparam K											KEY type of the hash map.
/// @tparam V											VALUE type of the hash map.
/// @tparam MAXENTRIES						Maximum number of elements to store.
//----------------------------------------------------------------------------------------
template <typename K, typename V, Int MAXENTRIES> class LRUHashMap
{
	// we use a BaseListNode<V> to connect all elements. each insert/find operation updates the list and
	// inserts the last recent used elements at the end of the list
	using ListNodeType = BaseListNode<V>;
	using LastNodeHead = BaseListHead<V, ListNodeType>;

	using HashMapType = HashMap<K, ListNodeType>;

public:
	~LRUHashMap()
	{
		Reset();
	}

	//----------------------------------------------------------------------------------------
	/// Finds the value associated with the given key, or creates a corresponding entry if it doesn't exist yet.
	/// The value of a new entry has to be initialized afterwards (but its default constructor has already been invoked).
	/// @param[in] key								Key of the value to find or create.
	/// @param[out] created						This will be set to true if a new entry has been created successfully, otherwise it will be set to false.
	/// @return												Pointer to value for the given key, or nullptr if an entry didn't exist and allocation of a new entry failed.
	//----------------------------------------------------------------------------------------
	template <typename KEY> ResultRef<V> InsertKey(KEY&& key, Bool& created = BoolLValue())
	{
		iferr_scope_handler
		{
			return nullptr;
		};

		typename HashMapType::Entry& entry = _hashMap.InsertEntry(std::forward<KEY>(key), created) iferr_return;
		if (created)
		{
			_lastUsed.InsertBefore(&entry.GetValue(), _lastUsed.End());

			if (_hashMap.GetCount() >= MAXENTRIES)
			{
				ListNodeType* oldest = _lastUsed.Begin();
				if (oldest)
				{
					oldest->Remove();
					typename HashMapType::Entry* oldestEntry = HashMapType::Entry::Get(oldest);
					_hashMap.Erase(oldestEntry);
					DebugAssert(_hashMap.GetCount() < MAXENTRIES);
				}
			}
		}
		else
		{
			UpdateEntry(&entry);
		}
		return *entry.GetValue()._GetData();
	}

	//----------------------------------------------------------------------------------------
	/// Finds the value associated with the given key in this map.
	/// @tparam KEY										Type of key.
	/// @param[in] key								Key to search for.
	/// @return												Pointer to value for the given key, or nullptr if no entry exists for the key.
	//----------------------------------------------------------------------------------------
	template <typename KEY> const V* FindValue(const KEY& key) const
	{
		typename HashMapType::Entry* entry = const_cast<typename HashMapType::Entry*>(_hashMap.Find(key));
		if (!entry)
			return nullptr;

		UpdateEntry(entry);

		return entry->GetValue()._GetData();
	}

	//----------------------------------------------------------------------------------------
	/// Finds the value associated with the given key in this map.
	/// @tparam KEY										Type of key.
	/// @param[in] key								Key to search for.
	/// @return												Pointer to value for the given key, or nullptr if no entry exists for the key.
	//----------------------------------------------------------------------------------------
	template <typename KEY> V* FindValue(const KEY& key)
	{
		return MAXON_NONCONST_COUNTERPART(FindValue(key));
	}

	//----------------------------------------------------------------------------------------
	/// Returns the number of entries in this map.
	/// @return												Number of entries.
	//----------------------------------------------------------------------------------------
	Int GetCount() const
	{
		return _hashMap.GetCount();
	}

	//----------------------------------------------------------------------------------------
	/// Resets the map. This destructs all entries and frees any memory held by the map, so the map
	/// will be in a state as if it had been newly constructed.
	/// @see Flush()
	//----------------------------------------------------------------------------------------
	void Reset()
	{
		for (auto* node = _lastUsed.Begin(); node != _lastUsed.End(); node = _lastUsed.Begin())
		{
			node->Remove();
		}
		_hashMap.Reset();
	}

	//----------------------------------------------------------------------------------------
	/// Removes an entry with the given key from this HashMap (if possible). In case of a multi-map,
	/// this only removes a single entry.
	/// The type KEY of the given key need not be the same as K, but then you have to provide
	/// an additional class KEYHASH to compute the hash code of the specified key (function KEYHASH::GetHashCode(const KEY&)),
	/// and to compare a key of type KEY with a key of type K for equality (function KEYHASH::IsEqual(const KEY&, const K&))
	/// unless the default HASH class is already able to do so.
	/// @tparam KEY										Type of key.
	/// @param[in] key								An entry having this key shall be removed.
	/// @return												Always true for a HashMap (even if key isn't contained in the map).
	/// 															For a general map, false indicates an out-of-memory condition on removal, but this cannot happen for a HashMap.
	//----------------------------------------------------------------------------------------
	template <typename KEY> ResultOk<void> Erase(const KEY& key)
	{
		typename HashMapType::Entry* entry = _hashMap.Find(key);
		if (!entry)
			return OK;
		entry->GetValue().Remove();
		return _hashMap.Erase(entry);
	}

private:
	// internal function to put the entry to the end of the LRU list.
	void UpdateEntry(typename HashMapType::Entry* entry) const
	{
		entry->GetValue().Remove();
		_lastUsed.InsertBefore(&entry->GetValue(), _lastUsed.End());
	}

private:
	HashMapType		_hashMap;
	LastNodeHead	_lastUsed;
};


}
#endif // LRUHASHMAP_H__
