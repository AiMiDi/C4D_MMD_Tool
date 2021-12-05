#ifndef REFCOUNT_HASHMAP_H__
#define REFCOUNT_HASHMAP_H__

#include "maxon/hashmap.h"
#include "maxon/string.h"

namespace maxon
{

/// @addtogroup STRUCTURES
/// @{

class RefCountHashMapDefaultHandler
{
public:
	template <typename ENTRY> static void EntryInserted(const ENTRY& entry)
	{
	}

	template <typename ENTRY> static void EntryErased(const ENTRY& entry)
	{
	}
};

//----------------------------------------------------------------------------------------
/// Use a RefCountHashMap for cache-like use cases where a map entry shall be automatically
/// removed when it isn't used any longer.
///
/// To add an entry to a RefCountHashMap, you have to use and store an EntryRef as in
/// @code
/// EntryRef ref;
/// Bool created;
/// V* value = ref.Set(map, key, created) iferr_return;
/// @endcode
/// This will add an entry for @c key, and this entry will stay in the map as long as there
/// are EntryRefs pointing to it. The map keeps track of those entries by means of reference counting.
//----------------------------------------------------------------------------------------
template <typename K, typename V, typename HASH = DefaultCompare, typename HANDLER = RefCountHashMapDefaultHandler> class RefCountHashMap
{
public:
	class Entry;
	class EntryRef;

	using Map = HashMap<K, Entry, HASH>;

	class Entry
	{
	public:
		Entry() : _refCount(0), _map(nullptr)
		{
		}

		void AddReference() const
		{
			++_refCount;
		}

		void RemoveReference() const
		{
			if (--_refCount == 0)
			{
				HANDLER::EntryErased(*const_cast<Entry*>(this));
				_map->_map.Erase(&GetBaseEntry());
			}
		}

		const typename Map::Entry& GetBaseEntry() const
		{
			return *Map::Entry::Get(this);
		}

		V& GetValue()
		{
			return _value;
		}

		const V& GetValue() const
		{
			return _value;
		}

		const RefCountHashMap& GetMap() const
		{
			return *_map;
		}

		String ToString(const FormatStatement* fmt) const
		{
			return GlobalToString(_value, fmt) + " x"_s + String::UIntToString(_refCount);
		}

	private:
		mutable UInt _refCount;
		RefCountHashMap* _map;
		V _value;

		friend class EntryRef;
	};

	class EntryRef
	{
	public:
		MAXON_OPERATOR_EQUALITY_HASHCODE(EntryRef, _ref);

		ResultRef<V> Set(RefCountHashMap& map, const K& key, Bool& created = BoolLValue(), EntryRef* prev = nullptr)
		{
			if (_ref && (_ref->_map == &map) && (_ref->GetBaseEntry().GetKey() == key))
			{
				created = false;
				return &_ref->_value;
			}
			if (prev)
				prev->_ref = std::move(_ref);
			else
				_ref = nullptr;
			Entry* e = map._map.InsertKey(key, created).GetPointer();
			if (!e)
				return nullptr;
			if (created)
			{
				e->_map = &map;
				HANDLER::EntryInserted(*e);
			}
			_ref = e;
			return &e->_value;
		}

		ResultRef<V> Set(RefCountHashMap& map, K&& key, Bool& created = BoolLValue(), EntryRef* prev = nullptr)
		{
			if (_ref && (_ref->_map == &map) && (_ref->GetBaseEntry().GetKey() == key))
			{
				created = false;
				return &_ref->_value;
			}
			if (prev)
				prev->_ref = std::move(_ref);
			else
				_ref = nullptr;
			Entry* e = map._map.InsertKey(std::move(key), created).GetPointer();
			if (!e)
				return nullptr;
			if (created)
			{
				e->_map = &map;
				HANDLER::EntryInserted(*e);
			}
			_ref = e;
			return &e->_value;
		}

		void Reset()
		{
			_ref = nullptr;
		}

		const K* GetKey() const
		{
			return _ref ? &_ref.GetPointer()->GetBaseEntry().GetKey() : nullptr;
		}

		const V* GetValue() const
		{
			return _ref ? &_ref.GetPointer()->_value : nullptr;
		}

		explicit operator Bool() const
		{
			return Bool(_ref);
		}

		String ToString(const FormatStatement* fs) const
		{
			if (std::is_empty<V>::value)
			{
				return _ref ? GlobalToString(GetKey(), fs) : "nullptr"_s;
			}
			else
			{
				return _ref ? GlobalToString(GetKey(), fs) + "->"_s + GlobalToString(GetValue(), fs) : "nullptr"_s;
			}
		}

	private:
		StrongRef<Entry> _ref;
	};

	~RefCountHashMap()
	{
		DebugAssert(_map.IsEmpty(), "All references to entries have to be cleared before RefCountHashMap is destructed.");
	}

	String ToString(const FormatStatement* fmt) const
	{
		return _map.ToString(fmt);
	}

	Map& GetMap()
	{
		return _map;
	}

	const Map& GetMap() const
	{
		return _map;
	}

private:
	Map _map;
};

/// @}

} // namespace maxon

#endif // REFCOUNT_HASHMAP_H__
