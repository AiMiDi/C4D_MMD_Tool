#ifndef HASHMAP_H__
#define HASHMAP_H__

#include "maxon/defaultallocator.h"
#include "maxon/collection.h"

namespace maxon
{

/// @addtogroup STRUCTURES
/// @{

enum class HASHMAP_ENTRY_LAYOUT
{
	KEY_VALUE,
	KEY_HASH_VALUE,
	VALUE_KEY,
	VALUE
} MAXON_ENUM_LIST(HASHMAP_ENTRY_LAYOUT);

struct DefaultHashMapEntryHandlerBase
{
	template <typename ENTRY, typename KEY, Bool COPY_KEY = TestForCopyFromMember<typename SFINAEHelper<typename ENTRY::KeyType, KEY>::type>::isSupported && std::is_reference<KEY>::value> struct KeyConstructor
	{
		static ResultOk<void> ConstructHashMapEntry(void* ptr, UInt hash, KEY&& key)
		{
			new (ptr) ENTRY(hash, std::forward<KEY>(key));
			return OK;
		}
		static Int GetHashMapEntrySize(const typename std::remove_reference<KEY>::type& key) { return SIZEOF(ENTRY); }
	};

	template <typename ENTRY, typename KEY> struct KeyConstructor<ENTRY, KEY&, true>
	{
		static Result<void> ConstructHashMapEntry(void* ptr, UInt hash, KEY& key)
		{
			ENTRY* e = new (ptr) ENTRY(hash);
			return const_cast<typename ENTRY::KeyType&>(e->GetKey()).CopyFrom(key);
		}
		static Int GetHashMapEntrySize(const typename std::remove_reference<KEY>::type& key) { return SIZEOF(ENTRY); }
	};


	template <typename ENTRY, typename KEY, typename VALUE, Bool COPY_KEY = TestForCopyFromMember<typename SFINAEHelper<typename ENTRY::KeyType, KEY>::type>::isSupported && std::is_reference<KEY>::value, Bool COPY_VALUE = TestForCopyFromMember<typename SFINAEHelper<typename ENTRY::ValueType, VALUE>::type>::isSupported && std::is_reference<VALUE>::value> struct KeyValueConstructor
	{
		ResultOk<void> ConstructHashMapEntry(void* ptr, UInt hash, KEY&& key)
		{
			new (ptr) ENTRY(hash, std::forward<KEY>(key), std::forward<VALUE>(*(typename std::remove_reference<VALUE>::type*) this));
			return OK;
		}
		static Int GetHashMapEntrySize(const typename std::remove_reference<KEY>::type& key) { return SIZEOF(ENTRY); }
	};

	template <typename ENTRY, typename KEY, typename VALUE> struct KeyValueConstructor<ENTRY, KEY&, VALUE, true, false>
	{
		Result<void> ConstructHashMapEntry(void* ptr, UInt hash, KEY& key)
		{
			ENTRY* e = new (ptr) ENTRY(hash, typename ENTRY::KeyType(), std::forward<VALUE>(*(typename std::remove_reference<VALUE>::type*) this));
			return const_cast<typename ENTRY::KeyType&>(e->GetKey()).CopyFrom(key);
		}
		static Int GetHashMapEntrySize(const typename std::remove_reference<KEY>::type& key) { return SIZEOF(ENTRY); }
	};

	template <typename ENTRY, typename KEY, typename VALUE> struct KeyValueConstructor<ENTRY, KEY, VALUE&, false, true>
	{
		Result<void> ConstructHashMapEntry(void* ptr, UInt hash, KEY&& key)
		{
			ENTRY* e = new (ptr) ENTRY(hash, std::forward<KEY>(key));
			return e->GetValue().CopyFrom(*(VALUE*) this);
		}
		static Int GetHashMapEntrySize(const typename std::remove_reference<KEY>::type& key) { return SIZEOF(ENTRY); }
	};

	template <typename ENTRY, typename KEY, typename VALUE> struct KeyValueConstructor<ENTRY, KEY&, VALUE&, true, true>
	{
		Result<void> ConstructHashMapEntry(void* ptr, UInt hash, KEY& key)
		{
			ENTRY* e = new (ptr) ENTRY(hash);
			Result<void> r = const_cast<typename ENTRY::KeyType&>(e->GetKey()).CopyFrom(key);
			if (r == FAILED)
			{
				return r;
			}
			return e->GetValue().CopyFrom(*(VALUE*) this);
		}
		static Int GetHashMapEntrySize(const typename std::remove_reference<KEY>::type& key) { return SIZEOF(ENTRY); }
	};
};

/// Marker class to be used as template argument for HashMap for the usual case when the values don't contain the keys (so the HashMap has to store key-value-pairs).
struct HashMapKeyValuePair : public DefaultHashMapEntryHandlerBase
{
	static const HASHMAP_ENTRY_LAYOUT LAYOUT = HASHMAP_ENTRY_LAYOUT::KEY_VALUE;
};

/// Marker class similar to HashMapKeyValuePair, but with a HashMap entry layout where the key will be the last data member of the entry. This can be used if keys have a variable size.
/// If this is not needed, HashMapKeyValuePair should have a better performance as the key is directly stored behind the hash code (better locality).
struct HashMapValueKeyPair : public DefaultHashMapEntryHandlerBase
{
	static const HASHMAP_ENTRY_LAYOUT LAYOUT = HASHMAP_ENTRY_LAYOUT::VALUE_KEY;
};

/// Marker class similar to HashMapKeyValuePair, but with a HashMap entry layout where the key will be the very first member entry (afterwards internal HashMap
/// information is stored, finally the value). This can be used to access the reference counter of the entry via the key.
struct HashMapKeyHashValuePair : public DefaultHashMapEntryHandlerBase
{
	static const HASHMAP_ENTRY_LAYOUT LAYOUT = HASHMAP_ENTRY_LAYOUT::KEY_HASH_VALUE;
};

/// Base class for HashMap::Entry.
template <typename K, typename V, typename ENTRY, typename ENTRY_HANDLER, HASHMAP_ENTRY_LAYOUT LAYOUT = ENTRY_HANDLER::LAYOUT> class HashMapEntryBase
{
public:
	using EntryHandler = ENTRY_HANDLER;

	//----------------------------------------------------------------------------------------
	/// Returns this entry's key.
	/// @return												Key of this entry.
	//----------------------------------------------------------------------------------------
	decltype(ENTRY_HANDLER::GetKey(*(V*) nullptr)) GetKey() const
	{
		return ENTRY_HANDLER::GetKey(_value);
	}

	//----------------------------------------------------------------------------------------
	/// Returns this entry's value.
	/// @return												Value of this entry.
	//----------------------------------------------------------------------------------------
	V& GetValue()
	{
		return _value;
	}

	//----------------------------------------------------------------------------------------
	/// Returns this entry's value.
	/// @return												Value of this entry.
	//----------------------------------------------------------------------------------------
	const V& GetValue() const
	{
		return _value;
	}

	//----------------------------------------------------------------------------------------
	/// Returns this entry's key.
	/// @return												Key of this entry.
	//----------------------------------------------------------------------------------------
	decltype(ENTRY_HANDLER::GetKey(*(V*) nullptr)) GetFirst() const
	{
		return ENTRY_HANDLER::GetKey(_value);
	}

	//----------------------------------------------------------------------------------------
	/// Returns this entry's value.
	/// @return												Value of this entry.
	//----------------------------------------------------------------------------------------
	V& GetSecond()
	{
		return _value;
	}

	//----------------------------------------------------------------------------------------
	/// Returns this entry's value.
	/// @return												Value of this entry.
	//----------------------------------------------------------------------------------------
	const V& GetSecond() const
	{
		return _value;
	}

	//----------------------------------------------------------------------------------------
	/// Sets the value of this entry by copy assignment.
	/// @param[in] value							New value.
	//----------------------------------------------------------------------------------------
	void SetValue(const V& value)
	{
		_value = value;
	}

	//----------------------------------------------------------------------------------------
	/// Sets the value of this entry by move assignment.
	/// @param[in] value							New value.
	//----------------------------------------------------------------------------------------
	void SetValue(V&& value)
	{
		_value = std::move(value);
	}

	void ResetValue()
	{
		ENTRY_HANDLER::ResetValue(_value);
	}

	UInt GetHashCode() const
	{
		return _hashCode;
	}

	Int GetMemorySize() const
	{
		return SIZEOF(HashMapEntryBase) - SIZEOF(V) + maxon::GetMemorySizeHelper(_value);
	}

	explicit HashMapEntryBase(UInt hash) : _hashCode(hash), _value()
	{
	}

	template <typename KEY> HashMapEntryBase(UInt hash, const KEY&) : _hashCode(hash), _value()
	{
	}

	template <typename KEY, typename A> HashMapEntryBase(UInt hash, const KEY&, A&& value) : _hashCode(hash), _value(std::forward<A>(value))
	{
	}

protected:
	MAXON_DISALLOW_COPY_AND_ASSIGN(HashMapEntryBase);
	ENTRY* _next = nullptr;
	UInt _hashCode;
	V _value;
};

template <typename K, typename V, typename ENTRY, typename ENTRY_HANDLER> class HashMapEntryBase<K, V, ENTRY, ENTRY_HANDLER, HASHMAP_ENTRY_LAYOUT::KEY_VALUE>
{
public:
	using EntryHandler = ENTRY_HANDLER;

	const K& GetKey() const
	{
		return _key;
	}

	V& GetValue()
	{
		return _value;
	}

	const V& GetValue() const
	{
		return _value;
	}

	const K& GetFirst() const
	{
		return _key;
	}

	V& GetSecond()
	{
		return _value;
	}

	const V& GetSecond() const
	{
		return _value;
	}

	void SetValue(const V& value)
	{
		_value = value;
	}

	void SetValue(V&& value)
	{
		_value = std::move(value);
	}

	void ResetValue()
	{
		_value.~V();
		new (&_value) V();
	}

	UInt GetHashCode() const
	{
		return _hashCode;
	}

	Int GetMemorySize() const
	{
		return SIZEOF(HashMapEntryBase) - SIZEOF(K) - SIZEOF(V) + maxon::GetMemorySizeHelper(_key) + maxon::GetMemorySizeHelper(_value);
	}

	explicit HashMapEntryBase(UInt hash) : _hashCode(hash), _value()
	{
	}

	HashMapEntryBase(UInt hash, const K& key) : _hashCode(hash), _key(key), _value()
	{
	}

	HashMapEntryBase(UInt hash, K&& key) : _hashCode(hash), _key(std::move(key)), _value()
	{
	}

	template <typename A> HashMapEntryBase(UInt hash, const K& key, A&& value) : _hashCode(hash), _key(key), _value(std::forward<A>(value))
	{
	}

	template <typename A> HashMapEntryBase(UInt hash, K&& key, A&& value) : _hashCode(hash), _key(std::move(key)), _value(std::forward<A>(value))
	{
	}

protected:
	MAXON_DISALLOW_COPY_AND_ASSIGN(HashMapEntryBase);
	ENTRY* _next = nullptr;
	UInt _hashCode;
	K _key;
	V _value;
};

template <typename K, typename V, typename ENTRY, typename ENTRY_HANDLER> class HashMapEntryBase<K, V, ENTRY, ENTRY_HANDLER, HASHMAP_ENTRY_LAYOUT::KEY_HASH_VALUE>
{
public:
	using EntryHandler = ENTRY_HANDLER;

	const K& GetKey() const
	{
		return _key;
	}

	V& GetValue()
	{
		return _value;
	}

	const V& GetValue() const
	{
		return _value;
	}

	const K& GetFirst() const
	{
		return _key;
	}

	V& GetSecond()
	{
		return _value;
	}

	const V& GetSecond() const
	{
		return _value;
	}

	void SetValue(const V& value)
	{
		_value = value;
	}

	void SetValue(V&& value)
	{
		_value = std::move(value);
	}

	void ResetValue()
	{
		_value.~V();
		new (&_value) V();
	}

	UInt GetHashCode() const
	{
		return _hashCode;
	}

	Int GetMemorySize() const
	{
		return SIZEOF(HashMapEntryBase) - SIZEOF(K) - SIZEOF(V) + maxon::GetMemorySizeHelper(_key) + maxon::GetMemorySizeHelper(_value);
	}

	explicit HashMapEntryBase(UInt hash) : _hashCode(hash), _value()
	{
	}

	HashMapEntryBase(UInt hash, const K& key) : _key(key), _hashCode(hash), _value()
	{
	}

	HashMapEntryBase(UInt hash, K&& key) : _key(std::move(key)), _hashCode(hash), _value()
	{
	}

	template <typename A> HashMapEntryBase(UInt hash, const K& key, A&& value) : _key(key), _hashCode(hash), _value(std::forward<A>(value))
	{
	}

	template <typename A> HashMapEntryBase(UInt hash, K&& key, A&& value) : _key(std::move(key)), _hashCode(hash), _value(std::forward<A>(value))
	{
	}

protected:
	MAXON_DISALLOW_COPY_AND_ASSIGN(HashMapEntryBase);
	K _key;
	ENTRY* _next = nullptr;
	UInt _hashCode;
	V _value;
};

template <typename K, typename V, typename ENTRY, typename ENTRY_HANDLER> class HashMapEntryBase<K, V, ENTRY, ENTRY_HANDLER, HASHMAP_ENTRY_LAYOUT::VALUE_KEY>
{
public:
	using EntryHandler = ENTRY_HANDLER;

	const K& GetKey() const
	{
		return _key;
	}

	V& GetValue()
	{
		return _value;
	}

	const V& GetValue() const
	{
		return _value;
	}

	const K& GetFirst() const
	{
		return _key;
	}

	V& GetSecond()
	{
		return _value;
	}

	const V& GetSecond() const
	{
		return _value;
	}

	void SetValue(const V& value)
	{
		_value = value;
	}

	void SetValue(V&& value)
	{
		_value = std::move(value);
	}

	void ResetValue()
	{
		_value.~V();
		new (&_value) V();
	}

	UInt GetHashCode() const
	{
		return _hashCode;
	}

	Int GetMemorySize() const
	{
		return SIZEOF(HashMapEntryBase) - SIZEOF(K) - SIZEOF(V) + maxon::GetMemorySizeHelper(_key) + maxon::GetMemorySizeHelper(_value);
	}

	explicit HashMapEntryBase(UInt hash) : _hashCode(hash), _value()
	{
	}

	HashMapEntryBase(UInt hash, const K& key) : _hashCode(hash), _value(), _key(key)
	{
	}

	HashMapEntryBase(UInt hash, K&& key) : _hashCode(hash), _value(), _key(std::move(key))
	{
	}

	template <typename A> HashMapEntryBase(UInt hash, const K& key, A&& value) : _hashCode(hash), _value(std::forward<A>(value)), _key(key)
	{
	}

	template <typename A> HashMapEntryBase(UInt hash, K&& key, A&& value) : _hashCode(hash), _value(std::forward<A>(value)), _key(std::move(key))
	{
	}

protected:
	MAXON_DISALLOW_COPY_AND_ASSIGN(HashMapEntryBase);
	ENTRY* _next = nullptr;
	UInt _hashCode;
	V _value;
	K _key;
};

template <typename K, typename ENTRY, typename ENTRY_HANDLER> class HashMapEntryBase<K, UnitType, ENTRY, ENTRY_HANDLER, HASHMAP_ENTRY_LAYOUT::KEY_VALUE>
{
public:
	using EntryHandler = ENTRY_HANDLER;

	const K& GetKey() const
	{
		return _key;
	}

	UnitType& GetValue()
	{
		return *(UnitType*) this;
	}

	const UnitType& GetValue() const
	{
		return *(const UnitType*) this;
	}

	const K& GetFirst() const
	{
		return _key;
	}

	UnitType& GetSecond()
	{
		return *(UnitType*) this;
	}

	const UnitType& GetSecond() const
	{
		return *(const UnitType*) this;
	}

	void SetValue(const UnitType&)
	{
	}

	void ResetValue()
	{
	}

	UInt GetHashCode() const
	{
		return _hashCode;
	}

	Int GetMemorySize() const
	{
		return SIZEOF(HashMapEntryBase) - SIZEOF(K) + maxon::GetMemorySizeHelper(_key);
	}

	explicit HashMapEntryBase(UInt hash) : _hashCode(hash)
	{
	}

	HashMapEntryBase(UInt hash, const K& key) : _hashCode(hash), _key(key)
	{
	}

	HashMapEntryBase(UInt hash, K&& key) : _hashCode(hash), _key(std::move(key))
	{
	}

	template <typename A> HashMapEntryBase(UInt hash, const K& key, A&& value) : _hashCode(hash), _key(key)
	{
	}

	template <typename A> HashMapEntryBase(UInt hash, K&& key, A&& value) : _hashCode(hash), _key(std::move(key))
	{
	}

protected:
	MAXON_DISALLOW_COPY_AND_ASSIGN(HashMapEntryBase);
	ENTRY* _next = nullptr;
	UInt _hashCode;
	K _key;
};

template <typename K, typename ENTRY, typename ENTRY_HANDLER> class HashMapEntryBase<K, UnitType, ENTRY, ENTRY_HANDLER, HASHMAP_ENTRY_LAYOUT::KEY_HASH_VALUE>
{
public:
	using EntryHandler = ENTRY_HANDLER;

	const K& GetKey() const
	{
		return _key;
	}

	UnitType& GetValue()
	{
		return *(UnitType*) this;
	}

	const UnitType& GetValue() const
	{
		return *(const UnitType*) this;
	}

	const K& GetFirst() const
	{
		return _key;
	}

	UnitType& GetSecond()
	{
		return *(UnitType*) this;
	}

	const UnitType& GetSecond() const
	{
		return *(const UnitType*) this;
	}

	void SetValue(const UnitType&)
	{
	}

	void ResetValue()
	{
	}

	UInt GetHashCode() const
	{
		return _hashCode;
	}

	Int GetMemorySize() const
	{
		return SIZEOF(HashMapEntryBase) - SIZEOF(K) + maxon::GetMemorySizeHelper(_key);
	}

	explicit HashMapEntryBase(UInt hash) : _hashCode(hash)
	{
	}

	HashMapEntryBase(UInt hash, const K& key) : _key(key), _hashCode(hash)
	{
	}

	HashMapEntryBase(UInt hash, K&& key) : _key(std::move(key)), _hashCode(hash)
	{
	}

	template <typename A> HashMapEntryBase(UInt hash, const K& key, A&& value) : _key(key), _hashCode(hash)
	{
	}

	template <typename A> HashMapEntryBase(UInt hash, K&& key, A&& value) : _key(std::move(key)), _hashCode(hash)
	{
	}

protected:
	MAXON_DISALLOW_COPY_AND_ASSIGN(HashMapEntryBase);
	K _key;
	ENTRY* _next = nullptr;
	UInt _hashCode;
};

template <typename K, typename ENTRY, typename ENTRY_HANDLER> class HashMapEntryBase<K, UnitType, ENTRY, ENTRY_HANDLER, HASHMAP_ENTRY_LAYOUT::VALUE_KEY>
{
public:
	using EntryHandler = ENTRY_HANDLER;

	const K& GetKey() const
	{
		return _key;
	}

	UnitType& GetValue()
	{
		return *(UnitType*) this;
	}

	const UnitType& GetValue() const
	{
		return *(const UnitType*) this;
	}

	const K& GetFirst() const
	{
		return _key;
	}

	UnitType& GetSecond()
	{
		return *(UnitType*) this;
	}

	const UnitType& GetSecond() const
	{
		return *(const UnitType*) this;
	}

	void SetValue(const UnitType&)
	{
	}

	void ResetValue()
	{
	}

	UInt GetHashCode() const
	{
		return _hashCode;
	}

	Int GetMemorySize() const
	{
		return SIZEOF(HashMapEntryBase) - SIZEOF(K) + maxon::GetMemorySizeHelper(_key);
	}

	explicit HashMapEntryBase(UInt hash) : _hashCode(hash)
	{
	}

	HashMapEntryBase(UInt hash, const K& key) : _hashCode(hash), _key(key)
	{
	}

	HashMapEntryBase(UInt hash, K&& key) : _hashCode(hash), _key(std::move(key))
	{
	}

	template <typename A> HashMapEntryBase(UInt hash, const K& key, A&& value) : _hashCode(hash), _key(key)
	{
	}

	template <typename A> HashMapEntryBase(UInt hash, K&& key, A&& value) : _hashCode(hash), _key(std::move(key))
	{
	}

protected:
	MAXON_DISALLOW_COPY_AND_ASSIGN(HashMapEntryBase);
	ENTRY* _next = nullptr;
	UInt _hashCode;
	K _key;
};

//----------------------------------------------------------------------------------------
/// A HashMap maps keys to values with the help of hash codes for the keys.
/// It expects a function static UInt HASH::GetHashCode(const K&) in the class HASH (given as template argument) to compute a hash code for a key,
/// and then it uses the lower bits of the hash code as an index into a table of buckets.
/// Each bucket contains a singly linked list of entries (key-value-pairs) having the same lower bits,
/// and the function static Bool HASH::IsEqual(const K&, const K&) is used to find the entry with matching key, if any.
/// By default, DefaultCompare is used for HASH, this handles keys of integral type, pointers and objects which have a GetHashCode member function
/// themselves as well as the == operator. For other keys, you have to define your own class for HASH, see CStringCompare as an example.
///
/// This example uses a HashMap to store String values addressed by Int keys:
/// @code
/// using IntStringMap = HashMap<Int, String>;
/// IntStringMap map;
/// ...
/// // now store "Hello World" at key 42
/// Bool created = false;
/// String& s = map.InsertKey(42, created) iferr_return;
/// if (created) // if created is false, there already exists an entry for 42 in the map
/// {
///   // initialize the new value
///   s = "Hello World"_s;
/// }
/// ...
/// // now check if there is an entry at key 42
/// String* s = map.FindValue(42);
/// if (s)
/// {
///   DiagnosticOutput("Found value @", *s);
/// }
/// @endcode
///
/// Instead of InsertKey(), you can also use Insert() if you don't need to differentiate between the cases whether the entry existed
/// before or not:
/// @code
/// IntStringMap::Entry& e = map.Insert(42, "Hello World"_s) iferr_return;
/// @endcode
///
/// A HashMap can also be used as a multi-map, which means that there can be more than one value per key. You have to use
/// InsertMultiEntry() to add entries for a key, this function won't overwrite or remove existing entries for that key. To get all entries
/// for a key, you have to iterate over them in the following way:
/// @code
/// for (IntStringMap::Entry* e = map.Find(42); e; e = e->GetNextWithSameKey())
/// {
///   ...
/// }
/// @endcode
/// You can also use the foreach iterator returned by FindAll():
/// @code
/// for (const IntStringMap::Entry& e : map.FindAll(42))
/// {
///   ...
/// }
/// @endcode
///
/// The larger the table of buckets, the less is the chance of several entries within a single bucket.
/// The HashMap uses a load factor to automatically double the size of the table if the number of entries exceeds
/// the table size multiplied by the load factor (re-hashing). So with a load factor of 0.5 there are at most half as many entries
/// as there are buckets, and then with evenly distributed hash codes there is only a negligible number
/// of buckets with more than one entry. The default load factor is 0.65. If you use a load factor <= 0, the
/// automatic increase of table size is switched off, thus the HashMap will keep the initial size of the table.
///
///
/// Performance characteristics:
/// A HashMap performs the map operations in constant time if the hash function computes evenly distributed
/// hash codes for the keys. All operations (insertion, erasure, lookup) are typically performed in constant
/// time O(1) (i.e., independent of the total number of entries).
///
/// There are applications of the HashMap where the values already contain the keys (e.g., think of a map
/// from names to objects, and the objects know their names). Then it might be wasteful to store the keys
/// again in the HashMap entries. In such a case, you have to specify a class as argument for the template
/// parameter ENTRY_HANDLER which contains the function static const K& ENTRY_HANDLER::GetKey(const V&). This function
/// will be used to extract keys from values. You also have to make sure that each HashMap entry has a valid
/// value. I.e., when you have added a new entry with Insert(), then you have to initialize it with
/// a value whose key is the same key as the one used for Insert().
///
/// If you want to iterate over the entries of a HashMap, you can either use Iterator, ConstIterator
/// or a ranged-based for loop, or you can use GetNonEmptyBucketCount() and GetNonEmptyBucket() to loop over the non-empty buckets,
/// and then HashMap::Entry::GetNextInBucket() to run through the entries of a bucket.
/// @code
/// for (IntStringMap::ConstIterator i = map.Begin(); i != map.End(); ++i)
/// {
///   DiagnosticOutput("@ -> @", i->GetKey(), i->GetValue());
/// }
/// for (const IntStringMap::Entry& entry : map)
/// {
///   DiagnosticOutput("@ -> @", entry.GetKey(), entry.GetValue());
/// }
/// @endcode
///
/// When the template parameter @p SYNCHRONIZED is set to @c true, the HashMap (partially) behaves as a thread-safe,
/// lock-free map. But note that this only holds if the only modification is the addition of new entries. You must
/// not erase entries unless you make sure that this only happens when no other thread accesses the HashMap, and
/// that a proper synchronization happens afterwards.
/// Also you have to set the load factor to zero to disable re-hashing and set a sufficiently large capacity at the beginning
/// using SetCapacityHint().
/// Iterators are generally less efficient when @p SYNCHRONIZED is @p true
/// as they have to loop over all buckets and not just over the non-empty buckets.
///
/// @tparam K											Type of keys.
/// @tparam V											Type of values.
/// @tparam HASH									Class to be used to compute the hash code of keys, and to compare keys for equality (DefaultCompare by default)
/// @tparam ENTRY_HANDLER					Use this class if the keys shall be extracted from values, rather than being stored separately.
/// 															With the default argument HashMapKeyValuePair, keys and values are stored separately in the entries as key-value-pairs.
/// @tparam ALLOCATOR							Class for memory allocation.
/// @tparam SYNCHRONIZED					Use atomic access to implement a lock-free hash map.
/// @see @$ref maps
//----------------------------------------------------------------------------------------
template <typename K, typename V, typename HASH = DefaultCompare, typename ENTRY_HANDLER = HashMapKeyValuePair, typename ALLOCATOR = DefaultAllocator, Bool SYNCHRONIZED = false> class HashMap
	: public MapBase<HashMap<K, V, HASH, ENTRY_HANDLER, ALLOCATOR, SYNCHRONIZED>, K, V, EmptyClass, HASH>
{
public:
	using Super = MapBase<HashMap, K, V, EmptyClass, HASH>;
	using HashType = HASH;
	class Entry;
	using IsHashMap = std::true_type;

	//----------------------------------------------------------------------------------------
	/// Constructs a new HashMap with an optional load factor.
	/// This will not allocate any memory. Memory allocation can be done explicitly by SetCapacityHint(), or it will be done implicitly when needed.
	/// @param[in] loadFactor					The load factor of the HashMap.
	//----------------------------------------------------------------------------------------
	explicit HashMap(Float loadFactor = Float(SYNCHRONIZED ? 0 : 0.65)) : _table(nullptr), _tableLengthM1(-1), _nonemptyBuckets(nullptr), _nonemptyBucketCount(0), _size(0), _resizeThreshold(0), _loadFactor(loadFactor)
	{
		DebugAssert(!SYNCHRONIZED || (loadFactor <= 0));
	}

	//----------------------------------------------------------------------------------------
	/// Initializes the underlying allocator and constructs a new HashMap with an optional load factor.
	/// This will not allocate any memory. Memory allocation can be done explicitly by SetCapacityHint(), or it will be done implicitly when needed.
	/// @param[in] alloc							Used to initialize the underlying allocator by its copy constructor.
	/// @param[in] loadFactor					The load factor of the HashMap.
	//----------------------------------------------------------------------------------------
	explicit HashMap(const ALLOCATOR& alloc, Float loadFactor = Float(SYNCHRONIZED ? 0 : 0.65)) : _allocator(alloc), _table(nullptr), _tableLengthM1(-1), _nonemptyBuckets(nullptr), _nonemptyBucketCount(0),
		_size(0), _resizeThreshold(0), _loadFactor(loadFactor)
	{
		DebugAssert(!SYNCHRONIZED || (loadFactor <= 0));
	}

	/// Destructs all entries and frees any allocated memory
	~HashMap()
	{
		Reset();
	}

	HashMap(HashMap&& src) : MAXON_MOVE_MEMBERS(_allocator, _table, _tableLengthM1, _nonemptyBuckets, _nonemptyBucketCount, _size, _resizeThreshold, _loadFactor)
	{
		src._table = nullptr;
		src._tableLengthM1 = -1;
		src._nonemptyBuckets = nullptr;
		src._nonemptyBucketCount = 0;
		src._size = 0;
		src._resizeThreshold = 0;
	}

	MAXON_OPERATOR_MOVE_ASSIGNMENT(HashMap);

	//----------------------------------------------------------------------------------------
	/// Ensures that the bucket table is large enough to hold at least capacity entries, taking into account the load factor
	/// (see explanation of the class HashMap itself).
	/// @param[in] capacity						The number of entries which can be stored without the need for re-hashing.
	/// @param[in] resizeFlags				Not used by HashMap.
	/// @return												True if memory allocations succeeded.
	//----------------------------------------------------------------------------------------
	ResultMem SetCapacityHint(Int capacity, COLLECTION_RESIZE_FLAGS resizeFlags = COLLECTION_RESIZE_FLAGS::ON_GROW_RESERVE_CAPACITY)
	{
		if (_loadFactor > 0)
		{
			capacity = (Int) ((capacity + 1) / _loadFactor) + 2;
		}
		Int c = 1;
		while (c < capacity)
		{
			c <<= 1;
		}
		return ResultMem((c <= _tableLengthM1 + 1) || ResizeTableImpl(c));
	}

	//----------------------------------------------------------------------------------------
	/// Resizes the bucket table of the HashMap. Usually, with a positive load factor, this is
	/// done automatically when needed. You can force a resize if you know that a large number
	/// of entries will be added, this will eliminate some intermediate resizings. For a
	/// non-positive load factor, you have to manually resize the table if advisable. This function
	/// can also be used to reduce the table size (it gets never reduced automatically).
	/// @param[in] capacity						The number of entries which can be stored without the need for re-hashing.
	/// @return												True if memory allocations succeeded. If not, the HashMap will still be in a valid state,
	/// 															but still with the previous table size.
	//----------------------------------------------------------------------------------------
	ResultMem ResizeTable(Int capacity)
	{
		if (_loadFactor > 0)
		{
			capacity = (Int) ((capacity + 1) / _loadFactor) + 2;
		}
		Int c = 1;
		while (c < capacity)
		{
			c <<= 1;
		}
		return ResizeTableImpl(c);
	}

	//----------------------------------------------------------------------------------------
	/// Resets the map. This destructs all entries and frees any memory held by the map, so the map
	/// will be in a state as if it had been newly constructed.
	/// @see Flush()
	//----------------------------------------------------------------------------------------
	void Reset()
	{
		if (SYNCHRONIZED && _size > 0)
		{
			System::PrivateShowSynchronizedHashMapDiagnostics(_size, _tableLengthM1, GetSignature((typename std::conditional<SYNCHRONIZED, Char, void>::type*) nullptr));
		}
		Flush();
		_allocator.Free(_table);
		_table = nullptr;
		_tableLengthM1 = -1;
		_allocator.Free(_nonemptyBuckets);
		_nonemptyBuckets = nullptr;
		_resizeThreshold = 0;
	}

	//----------------------------------------------------------------------------------------
	/// Flushes the map. This destructs and frees all entries, but does not free the bucket table.
	/// @see Reset()
	//----------------------------------------------------------------------------------------
	void Flush()
	{
		if (!_table)
		{
			return;
		}
		Int n = SYNCHRONIZED ? _tableLengthM1 + 1 : _nonemptyBucketCount;
		for (Int b = 0; b < n; ++b)
		{
			Entry*& head = (Entry*&) (SYNCHRONIZED ? _table + b : _nonemptyBuckets[b])->list;
			Entry* e;
			while ((e = head) != nullptr)
			{
				head = e->_next;
				--_size;
				DeleteEntry(e);
			}
		}
		ClearMemType(_table, (Int) _tableLengthM1 + 1);
		DebugAssert(_size == 0);
		_size = 0;
		_nonemptyBucketCount = 0;
	}

	//----------------------------------------------------------------------------------------
	/// Returns the number of entries in this map.
	/// @return												Number of entries.
	//----------------------------------------------------------------------------------------
	Int GetCount() const
	{
		return _size;
	}

	//----------------------------------------------------------------------------------------
	/// Returns the current size of the bucket table.
	/// @return												Size of bucket table.
	//----------------------------------------------------------------------------------------
	Int GetTableSize() const
	{
		return _tableLengthM1 + 1;
	}

	//----------------------------------------------------------------------------------------
	/// Calculates the memory usage for this map.
	/// Keys and Values must have a public member GetMemorySize that return the element size.
	/// @return												Memory size in bytes.
	//----------------------------------------------------------------------------------------
	Int GetMemorySize() const
	{
		static_assert(!SYNCHRONIZED, "GetMemorySize not supported for a synchronized HashMap.");
		Int sz = SIZEOF(HashMap) + (_tableLengthM1 + 1) * (SIZEOF(Bucket) + SIZEOF(Bucket*));
		for (Int i = 0; i < _nonemptyBucketCount; ++i)
		{
			for (const Entry* e = _nonemptyBuckets[i]->list; e; e = e->GetNextInBucket())
			{
				sz += e->GetMemorySize();
			}
		}
		return sz;
	}

	//----------------------------------------------------------------------------------------
	/// Returns the number of non-empty buckets in this map.
	/// This can be used together with GetNonEmptyBucket() to iterate over non-empty buckets.
	/// @return												Number of non-empty buckets.
	//----------------------------------------------------------------------------------------
	Int GetNonEmptyBucketCount() const
	{
		DebugAssert(!SYNCHRONIZED, "GetNonEmptyBucketCount not supported for a synchronized HashMap.");
		return _nonemptyBucketCount;
	}

	//----------------------------------------------------------------------------------------
	/// Returns the i-th non-empty bucket of this map.
	/// @param[in] i									Index into the list of non-empty buckets (from 0 to GetNonEmptyBucketCount() - 1)
	/// @return												I-th non-empty bucket.
	//----------------------------------------------------------------------------------------
	Entry* GetNonEmptyBucket(Int i)
	{
		DebugAssert(!SYNCHRONIZED, "GetNonEmptyBucket not supported for a synchronized HashMap.");
		DebugAssert((UInt) i < (UInt) _nonemptyBucketCount);
		return LoadRelaxed(_nonemptyBuckets[i]->list);
	}

	//----------------------------------------------------------------------------------------
	/// Returns the i-th non-empty bucket of this map.
	/// @param[in] i									Index into the list of non-empty buckets (from 0 to GetNonEmptyBucketCount() - 1)
	/// @return												I-th non-empty bucket.
	//----------------------------------------------------------------------------------------
	const Entry* GetNonEmptyBucket(Int i) const
	{
		DebugAssert(!SYNCHRONIZED, "GetNonEmptyBucket not supported for a synchronized HashMap.");
		DebugAssert((UInt) i < (UInt) _nonemptyBucketCount);
		return LoadRelaxed(_nonemptyBuckets[i]->list);
	}

	//----------------------------------------------------------------------------------------
	/// Returns an estimate of the number of operations needed to locate a given key in this map.
	/// This is used when two collections are compared: The iteration goes over the collection which would require
	/// more operations for search, and each entry is searched in the other collection.
	/// @return												Estimate for the number of operations.
	//----------------------------------------------------------------------------------------
	Int GetOperationCountForSearch() const
	{
		// Constant search time.
		return 1;
	}

	using Super::IsEqualImpl;

	template <typename MAP, typename COMPARE> typename SFINAEHelper<Bool, typename MAP::IsHashMap>::type IsEqualImpl(const MAP& other, COMPARE&& cmp, OverloadRank1) const
	{
		return HashMap::Hash<COMPARE>::IsEqual(*this, other, std::forward<COMPARE>(cmp));
	}

	//----------------------------------------------------------------------------------------
	/// Finds the entry with the given key in this map.
	/// The type KEY of the given key need not be the same as K, but then you have to provide
	/// an additional class KEYHASH to compute the hash code of the specified key (function KEYHASH::GetHashCode(const KEY&)),
	/// and to compare a key of type KEY with a key of type K for equality (function KEYHASH::IsEqual(const KEY&, const K&))
	/// unless the default HASH class is already able to do so.
	/// @tparam KEYHASH								Hash class to compute the hash code of key, and to compare key with the map's keys. Default is HASH.
	/// @tparam KEY										Type of key.
	/// @param[in] key								Key to search for.
	/// @return												Entry having the given key, or nullptr if no such entry exists in this map.
	//----------------------------------------------------------------------------------------
	template <typename KEYHASH = HASH, typename KEY> Entry* Find(const KEY& key)
	{
		return FindEntryImpl<KEY, KEYHASH>(KEYHASH::GetHashCode(key), key);
	}

	//----------------------------------------------------------------------------------------
	/// Finds the entry with the given key in this map.
	/// The type KEY of the given key need not be the same as K, but then you have to provide
	/// an additional class KEYHASH to compute the hash code of the specified key (function KEYHASH::GetHashCode(const KEY&)),
	/// and to compare a key of type KEY with a key of type K for equality (function KEYHASH::IsEqual(const KEY&, const K&))
	/// unless the default HASH class is already able to do so.
	/// @tparam KEYHASH								Hash class to compute the hash code of key, and to compare key with the map's keys. Default is HASH.
	/// @tparam KEY										Type of key.
	/// @param[in] key								Key to search for.
	/// @return												Entry having the given key, or nullptr if no such entry exists in this map.
	//----------------------------------------------------------------------------------------
	template <typename KEYHASH = HASH, typename KEY> const Entry* Find(const KEY& key) const
	{
		return FindEntryImpl<KEY, KEYHASH>(KEYHASH::GetHashCode(key), key);
	}

	//----------------------------------------------------------------------------------------
	/// Finds the value associated with the given key in this map.
	/// The type KEY of the given key need not be the same as K, but then you have to provide
	/// an additional class KEYHASH to compute the hash code of the specified key (function KEYHASH::GetHashCode(const KEY&)),
	/// and to compare a key of type KEY with a key of type K for equality (function KEYHASH::IsEqual(const KEY&, const K&))
	/// unless the default HASH class is already able to do so.
	/// @tparam KEYHASH								Hash class to compute the hash code of key, and to compare key with the map's keys. Default is HASH.
	/// @tparam KEY										Type of key.
	/// @param[in] key								Key to search for.
	/// @return												Pointer to value for the given key, or nullptr if no entry exists for the key.
	//----------------------------------------------------------------------------------------
	template <typename KEYHASH = HASH, typename KEY> V* FindValue(const KEY& key)
	{
		Entry* e = FindEntryImpl<KEY, KEYHASH>(KEYHASH::GetHashCode(key), key);
		return e ? &e->GetValue() : nullptr;
	}

	//----------------------------------------------------------------------------------------
	/// Finds the value associated with the given key in this map.
	/// The type KEY of the given key need not be the same as K, but then you have to provide
	/// an additional class KEYHASH to compute the hash code of the specified key (function KEYHASH::GetHashCode(const KEY&)),
	/// and to compare a key of type KEY with a key of type K for equality (function KEYHASH::IsEqual(const KEY&, const K&))
	/// unless the default HASH class is already able to do so.
	/// @tparam KEYHASH								Hash class to compute the hash code of key, and to compare key with the map's keys. Default is HASH.
	/// @tparam KEY										Type of key.
	/// @param[in] key								Key to search for.
	/// @return												Pointer to value for the given key, or nullptr if no entry exists for the key.
	//----------------------------------------------------------------------------------------
	template <typename KEYHASH = HASH, typename KEY> const V* FindValue(const KEY& key) const
	{
		const Entry* e = FindEntryImpl<KEY, KEYHASH>(KEYHASH::GetHashCode(key), key);
		return e ? &e->GetValue() : nullptr;
	}

	//----------------------------------------------------------------------------------------
	/// Finds the entry with the given key, or creates such an entry if it doesn't exist yet.
	/// If a new entry has to be created, it is constructed with the help of the object passed to the constructor
	/// parameter: Its class C has to provide a function <tt>Int C::GetHashMapEntrySize(const K& key)</tt> to compute
	/// the size of a new entry for key and a function <tt>Result<void> C::ConstructHashMapEntry(void* ptr, UInt hash, const K& key)</tt> which uses
	/// the memory in ptr to construct a new entry for the key.
	/// If the constructor does not initialize the value of the new entry, this has to be done afterwards.
	///
	/// The type KEY of the given key need not be the same as K, but then you have to provide
	/// an additional class KEYHASH to compute the hash code of the specified key (function KEYHASH::GetHashCode(const KEY&)),
	/// and to compare a key of type KEY with a key of type K for equality (function KEYHASH::IsEqual(const KEY&, const K&))
	/// unless the default HASH class is already able to do so.
	/// @tparam KEYHASH								Hash class to compute the hash code of key, and to compare key with the map's keys. Default is HASH.
	/// @tparam KEY										Type of key.
	/// @tparam C											Type of the constructor argument.
	/// @param[in] key								Key of the entry to find or create.
	/// @param[in] constructor				The functions constructor.GetHashMapEntrySize(ptr, hash, key) and constructor.ConstructHashMapEntry(ptr, hash, key) will be used to construct a new entry from the memory in ptr.
	/// @param[out] created						This will be set to true if a new entry has been created successfully, otherwise it will be set to false.
	/// @return												Entry for the given key, or nullptr if the entry didn't exist and allocation of a new entry failed.
	//----------------------------------------------------------------------------------------
	template <typename KEYHASH = HASH, typename KEY, typename C> Result<Entry*> InsertCtor(KEY&& key, C&& constructor, Bool& created = BoolLValue())
	{
		if (_table == nullptr)
		{
			DebugAssert(!SYNCHRONIZED, "For a synchronized HashMap, you have to call SetCapacityHint at the beginning.");
			if (SetCapacityHint(20) == FAILED)
			{
				created = false;
				return CreateError(MAXON_SOURCE_LOCATION, ERROR_TYPE::OUT_OF_MEMORY);
			}
		}
		UInt hash = KEYHASH::GetHashCode(key);
		Entry* prev = LoadAcquire(_table[hash & (UInt) _tableLengthM1].list);
		Entry* e = prev;
		for (; e; e = e->_next)
		{
			if ((hash == e->GetHashCode()) && KEYHASH::IsEqual(key, e->GetKey()))
			{
				created = false;
				return e;
			}
		}
		Int sz = constructor.GetHashMapEntrySize(key);
		DebugAssert(std::is_standard_layout<Entry>::value || (sz == SIZEOF(Entry)));
		e = (Entry*) _allocator.Alloc(sz, MAXON_SOURCE_LOCATION_NAME(Entry));
		if (!e)
		{
			created = false;
			return CreateError(MAXON_SOURCE_LOCATION, ERROR_TYPE::OUT_OF_MEMORY);
		}
		Result<void> res = constructor.ConstructHashMapEntry(e, hash, std::forward<KEY>(key));
		if (res == FAILED)
		{
			e->~Entry();
			_allocator.Free(e);
			created = false;
			return res.GetErrorStorage();
		}
		return AddEntryImpl(e, prev, created, false, (typename std::conditional<SYNCHRONIZED, Char, void>::type*) nullptr);
	}


	/// @markInternal
	template <typename KEY, typename LAMBDA, Bool COPY_KEY = TestForCopyFromMember<typename SFINAEHelper<K, KEY>::type>::isSupported && std::is_reference<KEY>::value> struct LambdaEntryConstructor
	{
		Result<void> ConstructHashMapEntry(void* ptr, UInt hash, KEY&& key)
		{
			Entry* e = new (ptr) Entry(hash, std::forward<KEY>(key));
			return (*(typename std::remove_reference<LAMBDA>::type*) this)(*e);
		}
		static Int GetHashMapEntrySize(const typename std::remove_reference<KEY>::type& key) { return SIZEOF(Entry); }
	};

	template <typename KEY, typename LAMBDA> struct LambdaEntryConstructor<KEY&, LAMBDA, true>
	{
		Result<void> ConstructHashMapEntry(void* ptr, UInt hash, KEY& key)
		{
			Entry* e = new (ptr) Entry(hash);
			Result<void> r = const_cast<K&>(e->GetKey()).CopyFrom(key);
			if (r == FAILED)
			{
				return r;
			}
			return (*(typename std::remove_reference<LAMBDA>::type*) this)(*e);
		}
		static Int GetHashMapEntrySize(const typename std::remove_reference<KEY>::type& key) { return SIZEOF(Entry); }
	};


	//----------------------------------------------------------------------------------------
	/// Finds the entry with the given key, or creates such an entry if it doesn't exist yet.
	/// The value of a new entry has to be initialized afterwards (but its default constructor has already been invoked).
	/// @param[in] key								Key of the entry to find or create.
	/// @param[out] created						This will be set to true if a new entry has been created successfully, otherwise it will be set to false.
	/// @return												Entry for the given key, or nullptr if the entry didn't exist and allocation of a new entry failed.
	//----------------------------------------------------------------------------------------
	ResultRef<Entry> InsertEntry(const K& key, Bool& created = BoolLValue())
	{
		return InsertCtor(key, typename ENTRY_HANDLER::template KeyConstructor<Entry, const K&>(), created).UncheckedGetValue();
	}

	//----------------------------------------------------------------------------------------
	/// Finds the entry with the given key, or creates such an entry if it doesn't exist yet.
	/// The value of a new entry has to be initialized afterwards (but its default constructor has already been invoked).
	/// @param[in] key								Key of the entry to find or create. If a new entry is created, its key will be constructed by move-semantics if possible.
	/// @param[out] created						This will be set to true if a new entry has been created successfully, otherwise it will be set to false.
	/// @return												Entry for the given key, or nullptr if the entry didn't exist and allocation of a new entry failed.
	//----------------------------------------------------------------------------------------
	ResultRef<Entry> InsertEntry(K&& key, Bool& created = BoolLValue())
	{
		return InsertCtor(std::move(key), typename ENTRY_HANDLER::template KeyConstructor<Entry, K>(), created).UncheckedGetValue();
	}

	//----------------------------------------------------------------------------------------
	/// Finds the entry with the given key, or creates such an entry if it doesn't exist yet.
	/// The value of a new entry has to be initialized afterwards (but its default constructor has already been invoked).
	/// The type KEY of the given key need not be the same as K, but then you have to provide
	/// an additional class KEYHASH to compute the hash code of the specified key (function KEYHASH::GetHashCode(const KEY&)),
	/// and to compare a key of type KEY with a key of type K for equality (function KEYHASH::IsEqual(const KEY&, const K&))
	/// unless the default HASH class is already able to do so.
	/// @tparam KEYHASH								Hash class to compute the hash code of key, and to compare key with the map's keys. Default is HASH.
	/// @tparam KEY										Type of key.
	/// @param[in] key								Key of the entry to find or create.
	/// @param[out] created						This will be set to true if a new entry has been created successfully, otherwise it will be set to false.
	/// @return												Entry for the given key, or nullptr if the entry didn't exist and allocation of a new entry failed.
	//----------------------------------------------------------------------------------------
	template <typename KEYHASH = HASH, typename KEY> ResultRef<Entry> InsertEntry(KEY&& key, Bool& created = BoolLValue())
	{
		return InsertCtor<KEYHASH, KEY>(std::forward<KEY>(key), typename ENTRY_HANDLER::template KeyConstructor<Entry, KEY>(), created).UncheckedGetValue();
	}

	//----------------------------------------------------------------------------------------
	/// Finds the value associated with the given key, or creates a corresponding entry if it doesn't exist yet.
	/// The value of a new entry has to be initialized afterwards (but its default constructor has already been invoked).
	/// @param[in] key								Key of the value to find or create.
	/// @param[out] created						This will be set to true if a new entry has been created successfully, otherwise it will be set to false.
	/// @return												Pointer to value for the given key, or nullptr if an entry didn't exist and allocation of a new entry failed.
	//----------------------------------------------------------------------------------------
	ResultRef<V> InsertKey(const K& key, Bool& created = BoolLValue())
	{
		Entry* e = InsertCtor(key, typename ENTRY_HANDLER::template KeyConstructor<Entry, const K&>(), created).UncheckedGetValue();
		return e ? &e->GetValue() : nullptr;
	}

	//----------------------------------------------------------------------------------------
	/// Finds the value associated with the given key, or creates a corresponding entry if it doesn't exist yet.
	/// The value of a new entry has to be initialized afterwards (but its default constructor has already been invoked).
	/// @param[in] key								Key of the entry to find or create. If a new entry is created, its key will be constructed by move-semantics if possible.
	/// @param[out] created						This will be set to true if a new entry has been created successfully, otherwise it will be set to false.
	/// @return												Pointer to value for the given key, or nullptr if an entry didn't exist and allocation of a new entry failed.
	//----------------------------------------------------------------------------------------
	ResultRef<V> InsertKey(K&& key, Bool& created = BoolLValue())
	{
		Entry* e = InsertCtor(std::move(key), typename ENTRY_HANDLER::template KeyConstructor<Entry, K>(), created).UncheckedGetValue();
		return e ? &e->GetValue() : nullptr;
	}

	//----------------------------------------------------------------------------------------
	/// Finds the value associated with the given key, or creates a corresponding entry if it doesn't exist yet.
	/// The value of a new entry has to be initialized afterwards (but its default constructor has already been invoked).
	/// The type KEY of the given key need not be the same as K, but then you have to provide
	/// an additional class KEYHASH to compute the hash code of the specified key (function KEYHASH::GetHashCode(const KEY&)),
	/// and to compare a key of type KEY with a key of type K for equality (function KEYHASH::IsEqual(const KEY&, const K&))
	/// unless the default HASH class is already able to do so.
	/// @tparam KEYHASH								Hash class to compute the hash code of key, and to compare key with the map's keys. Default is HASH.
	/// @tparam KEY										Type of key.
	/// @param[in] key								Key of the value to find or create.
	/// @param[out] created						This will be set to true if a new entry has been created successfully, otherwise it will be set to false.
	/// @return												Pointer to value for the given key, or nullptr if an entry didn't exist and allocation of a new entry failed.
	//----------------------------------------------------------------------------------------
	template <typename KEYHASH = HASH, typename KEY> ResultRef<V> InsertKey(KEY&& key, Bool& created = BoolLValue())
	{
		Entry* e = InsertCtor<KEYHASH, KEY>(std::forward<KEY>(key), typename ENTRY_HANDLER::template KeyConstructor<Entry, KEY>(), created).UncheckedGetValue();
		return e ? &e->GetValue() : nullptr;
	}

	//----------------------------------------------------------------------------------------
	/// Finds the entry with the given key, or creates such an entry if it doesn't exist yet.
	/// If a new entry has to be created, the passed @p lambda function is invoked with the newly created entry as <tt>Entry&</tt>
	/// argument in order to initialize the value of the entry. The lambda function has to return <tt>Result<void></tt>, for example
	/// <tt>[](MyMap::Entry& e) -> Result<void> { e.SetValue(42); return OK; }</tt>.
	///
	/// The type KEY of the given key need not be the same as K, but then you have to provide
	/// an additional class KEYHASH to compute the hash code of the specified key (function KEYHASH::GetHashCode(const KEY&)),
	/// and to compare a key of type KEY with a key of type K for equality (function KEYHASH::IsEqual(const KEY&, const K&))
	/// unless the default HASH class is already able to do so.
	/// @tparam KEYHASH								Hash class to compute the hash code of key, and to compare key with the map's keys. Default is HASH.
	/// @tparam KEY										Type of key.
	/// @tparam LAMBDA								Type of the function.
	/// @param[in] key								Key of the entry to find or create.
	/// @param[in] lambda							The function which will be invoked as <tt>return lambda(entry);</tt> to initialize the value of a newly created entry.
	/// @return												Entry for the given key, or nullptr if the entry didn't exist and allocation of a new entry failed.
	//----------------------------------------------------------------------------------------
	template <typename KEYHASH = HASH, typename KEY, typename LAMBDA> Result<Entry*> InsertLambda(KEY&& key, LAMBDA&& lambda)
	{
		Bool created;
		return InsertCtor<KEYHASH, KEY>(std::forward<KEY>(key), *(LambdaEntryConstructor<KEY, LAMBDA>*) &lambda, created);
	}

	//----------------------------------------------------------------------------------------
	/// Associates the given value with the given key. This adds a new entry for key if necessary,
	/// and then sets its value to the given value, whether the entry existed before or not.
	/// The type KEY of the given key need not be the same as K, but then you have to provide
	/// an additional class KEYHASH to compute the hash code of the specified key (function KEYHASH::GetHashCode(const KEY&)),
	/// and to compare a key of type KEY with a key of type K for equality (function KEYHASH::IsEqual(const KEY&, const K&))
	/// unless the default HASH class is already able to do so.
	/// @tparam KEYHASH								Hash class to compute the hash code of key, and to compare key with the map's keys. Default is HASH.
	/// @tparam KEY										Type of key.
	/// @param[in] key								Key which shall map to the value.
	/// @param[in] value							Value to which the key shall map.
	/// @param[out] created						This will be set to true if a new entry has been created, otherwise it will be set to false.
	/// @return												Entry for the key-value-association, or nullptr if such an entry didn't exist before and allocation of a new entry failed.
	//----------------------------------------------------------------------------------------
	template <typename KEYHASH = HASH, typename KEY> ResultRef<Entry> Insert(KEY&& key, const V& value, Bool& created = BoolLValue())
	{
		Entry* e = InsertCtor<KEYHASH, KEY>(std::forward<KEY>(key), *(typename ENTRY_HANDLER::template KeyValueConstructor<Entry, KEY, const V&>*) &value, created).UncheckedGetValue();
		if (e && !created && !SYNCHRONIZED)
		{
			if (AssignCopy<V>(e->GetValue(), value) == FAILED)
				return nullptr;
		}
		return e;
	}

	//----------------------------------------------------------------------------------------
	/// Associates the given value with the given key. This adds a new entry for key if necessary,
	/// and then sets its value to the given value, whether the entry existed before or not.
	/// The type KEY of the given key need not be the same as K, but then you have to provide
	/// an additional class KEYHASH to compute the hash code of the specified key (function KEYHASH::GetHashCode(const KEY&)),
	/// and to compare a key of type KEY with a key of type K for equality (function KEYHASH::IsEqual(const KEY&, const K&))
	/// unless the default HASH class is already able to do so.
	/// @tparam KEYHASH								Hash class to compute the hash code of key, and to compare key with the map's keys. Default is HASH.
	/// @tparam KEY										Type of key.
	/// @param[in] key								Key which shall map to the value.
	/// @param[in] value							Value to which the key shall map. It will be moved into the HashMap.
	/// @param[out] created						This will be set to true if a new entry has been created, otherwise it will be set to false.
	/// @return												Entry for the key-value-association, or nullptr if such an entry didn't exist before and allocation of a new entry failed.
	//----------------------------------------------------------------------------------------
	template <typename KEYHASH = HASH, typename KEY> ResultRef<Entry> Insert(KEY&& key, V&& value, Bool& created = BoolLValue())
	{
		Entry* e = InsertCtor<KEYHASH, KEY>(std::forward<KEY>(key), *(typename ENTRY_HANDLER::template KeyValueConstructor<Entry, KEY, V>*) &value, created).UncheckedGetValue();
		if (e && !created && !SYNCHRONIZED)
		{
			e->SetValue(std::move(value));
		}
		return e;
	}

	//----------------------------------------------------------------------------------------
	/// Adds an entry for the given key, even if an entry for the key already exists.
	/// In the latter case, the HashMap becomes a multi-map with more than one value per key.
	/// To iterate over all entries for a key, use FindAll() or Entry::GetNextWithSameKey().
	/// The type KEY of the given key need not be the same as K, but then you have to provide
	/// an additional class KEYHASH to compute the hash code of the specified key (function KEYHASH::GetHashCode(const KEY&))
	/// unless the default HASH class is already able to do so.
	/// @tparam KEYHASH								Hash class to compute the hash code of key. Default is HASH.
	/// @tparam KEY										Type of key.
	/// @param[in] key								Key of the entry to add.
	/// @return												Added entry for the given key, or nullptr if the allocation failed.
	//----------------------------------------------------------------------------------------
	template <typename KEYHASH = HASH, typename KEY> ResultRef<Entry> InsertMultiEntry(KEY&& key)
	{
		if (MAXON_UNLIKELY(_table == nullptr))
		{
			DebugAssert(!SYNCHRONIZED, "For a synchronized HashMap, you have to call SetCapacityHint at the beginning.");
			if (SetCapacityHint(20) == FAILED)
			{
				return nullptr;
			}
		}
		UInt hash = KEYHASH::GetHashCode(key);
		Entry* e = (Entry*) _allocator.Alloc(SIZEOF(Entry), MAXON_SOURCE_LOCATION_NAME(Entry));
		if (!e)
		{
			return nullptr;
		}
		e = new (e) Entry(hash, std::forward<KEY>(key));
		Bool created;
		Entry* prev = LoadAcquire(_table[hash & (UInt) _tableLengthM1].list);
		return AddEntryImpl(e, prev, created, true, (typename std::conditional<SYNCHRONIZED, Char, void>::type*) nullptr);
	}

	//----------------------------------------------------------------------------------------
	/// Adds an entry for the given key, even if an entry for the key already exists.
	/// In the latter case, the HashMap becomes a multi-map with more than one value per key.
	/// To iterate over all entries for a key, use FindAll() or Entry::GetNextWithSameKey().
	/// The type KEY of the given key need not be the same as K, but then you have to provide
	/// an additional class KEYHASH to compute the hash code of the specified key (function KEYHASH::GetHashCode(const KEY&))
	/// unless the default HASH class is already able to do so.
	/// @param[in] e									Entry to add.
	/// @param[in] hash								Hash value of the key.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	ResultMem InsertMultiEntry(Entry* e, UInt hash)
	{
		if (MAXON_UNLIKELY(_table == nullptr))
		{
			DebugAssert(!SYNCHRONIZED, "For a synchronized HashMap, you have to call SetCapacityHint at the beginning.");
			if (SetCapacityHint(20) == FAILED)
			{
				return ResultMem(false);
			}
		}

		Bool created;
		Entry* prev = LoadAcquire(_table[hash & (UInt) _tableLengthM1].list);
		if (AddEntryImpl(e, prev, created, true, (typename std::conditional<SYNCHRONIZED, Char, void>::type*) nullptr) == nullptr)
			return ResultMem(false);

		return OK;
	}

	//----------------------------------------------------------------------------------------
	/// Removes the given entry from this HashMap.
	/// @param[in] entry							The entry to remove.
	/// @param[in] deleteEntry				If true (the default), the entry is also deleted, i.e., destructed and freed. If false, it won't be deleted, and you have to do this afterwards using DeleteEntry().
	/// @return												OK
	//----------------------------------------------------------------------------------------
	ResultOk<void> Erase(const Entry* entry, Bool deleteEntry = true)
	{
		if (!entry || !_table)
		{
			return OK;
		}
		UInt h = entry->GetHashCode() & (UInt) _tableLengthM1;
		Entry* prev = nullptr;
		for (Entry* e = LoadRelaxed(_table[h].list); e; e = e->_next)
		{
			if (e == entry)
			{
				--_size;
				if (prev)
				{
					prev->_next = e->_next;
				}
				else
				{
					StoreRelaxed(_table[h].list, e->_next);
					if (!SYNCHRONIZED && (e->_next == nullptr))
					{
						Int i = _table[h].nonemptyBucketsIndex;
						if (i < --_nonemptyBucketCount)
						{
							(_nonemptyBuckets[i] = _nonemptyBuckets[_nonemptyBucketCount])->nonemptyBucketsIndex = i;
						}
					}
				}
				if (deleteEntry)
					DeleteEntry(e);
				return OK;
			}
			prev = e;
		}
		return OK;
	}

	// without this overload the Erase template would be chosen instead of the Erase function if the parameter is a non-const entry
	ResultOk<void> Erase(Entry* entry, Bool deleteEntry = true)
	{
		return Erase(static_cast<const Entry*>(entry), deleteEntry);
	}

	//----------------------------------------------------------------------------------------
	/// Removes the given entry from this HashMap.
	/// @param[in] entry							The entry to remove.
	/// @param[in] deleteEntry				If true (the default), the entry is also deleted, i.e., destructed and freed. If false, it won't be deleted, and you have to do this afterwards using DeleteEntry().
	/// @return												OK
	//----------------------------------------------------------------------------------------
	ResultOk<void> Erase(const Entry& entry, Bool deleteEntry = true)
	{
		return Erase(&entry, deleteEntry);
	}

	// without this overload the Erase template would be chosen instead of the Erase function if the parameter is a non-const entry
	ResultOk<void> Erase(Entry& entry, Bool deleteEntry = true)
	{
		return Erase(static_cast<const Entry*>(&entry), deleteEntry);
	}

	//----------------------------------------------------------------------------------------
	/// Deletes an entry which has been removed from this HashMap previously. You don't
	/// have to invoke this function yourself unless you removed an entry using Erase()
	/// with a value of false for the deleteEntry parameter.
	/// @param[in] e									An entry which has been removed from this HashMap previously, but not yet deleted.
	//----------------------------------------------------------------------------------------
	void DeleteEntry(const Entry* e)
	{
		e->~Entry();
		_allocator.Free(e);
	}

	//----------------------------------------------------------------------------------------
	/// Removes an entry with the given key from this HashMap (if possible). In case of a multi-map,
	/// this only removes a single entry.
	/// The type KEY of the given key need not be the same as K, but then you have to provide
	/// an additional class KEYHASH to compute the hash code of the specified key (function KEYHASH::GetHashCode(const KEY&)),
	/// and to compare a key of type KEY with a key of type K for equality (function KEYHASH::IsEqual(const KEY&, const K&))
	/// unless the default HASH class is already able to do so.
	/// @tparam KEYHASH								Hash class to compute the hash code of key, and to compare key with the map's keys. Default is HASH.
	/// @tparam KEY										Type of key.
	/// @param[in] key								An entry having this key shall be removed.
	/// @return												True if an entry was found and removed for #key, otherwise false.
	//----------------------------------------------------------------------------------------
	template <typename KEYHASH = HASH, typename KEY> ResultOk<Bool> Erase(const KEY& key)
	{
		if (!_table)
		{
			return false;
		}
		UInt hash = KEYHASH::GetHashCode(key);
		UInt h = hash & (UInt) _tableLengthM1;
		Entry* prev = nullptr;
		for (Entry* e = LoadRelaxed(_table[h].list); e; e = e->_next)
		{
			if ((hash == e->GetHashCode()) && KEYHASH::IsEqual(key, e->GetKey()))
			{
				_size--;
				if (prev)
				{
					prev->_next = e->_next;
				}
				else
				{
					StoreRelaxed(_table[h].list, e->_next);
					if (!SYNCHRONIZED && (e->_next == nullptr))
					{
						Int i = _table[h].nonemptyBucketsIndex;
						if (i < --_nonemptyBucketCount)
						{
							(_nonemptyBuckets[i] = _nonemptyBuckets[_nonemptyBucketCount])->nonemptyBucketsIndex = i;
						}
					}
				}
				DeleteEntry(e);
				return true;
			}
			prev = e;
		}
		return false;
	}

	//----------------------------------------------------------------------------------------
	/// Removes all entries from this map whose keys are not contained in set.
	/// A @c key is in @p set if <tt>set.Contains(key)</tt> returns true, or if that is not a valid expression,
	/// if <tt>set(key)</tt> returns true. I.e., you can use a lambda expression as @p set.
	/// @param[in] set								A set with which this map gets intersected. Can be a lambda expression.
	/// @tparam SET										Type of @p set.
	//----------------------------------------------------------------------------------------
	template <typename SET> Result<void> IntersectImpl(SET&& set, OverloadRank0)
	{
		static_assert(!SYNCHRONIZED, "Intersect not supported for a synchronized HashMap.");
		for (Int i = 0; i < _nonemptyBucketCount; ++i)
		{
			Entry* next = nullptr;
			Entry* prev = nullptr;
			for (Entry* e = _nonemptyBuckets[i]->list; e; e = next)
			{
				next = e->_next;
				if (!maxon::Contains(std::forward<SET>(set), e->GetKey()))
				{
					--_size;
					if (prev)
					{
						prev->_next = next;
					}
					else
					{
						_nonemptyBuckets[i]->list = next;
						if (!next)
						{
							DebugAssert(i == _nonemptyBuckets[i]->nonemptyBucketsIndex);
							if (i < --_nonemptyBucketCount)
							{
								(_nonemptyBuckets[i] = _nonemptyBuckets[_nonemptyBucketCount])->nonemptyBucketsIndex = i;
							}
							--i;
						}
					}
					DeleteEntry(e);
				}
				else
				{
					prev = e;
				}
			}
		}
		return OK;
	}

	using Super::AppendAllImpl;

	template <typename S> typename SFINAEHelper<Result<void>, typename std::remove_reference<S>::type::MapType>::type AppendAllImpl(S&& src, COLLECTION_RESIZE_FLAGS resizeFlags, Bool overwrite, OverloadRank1)
	{
		DebugAssert(!(SYNCHRONIZED && overwrite));
		for (const auto& i : src)
		{
			Bool created = false;
			const typename std::decay<S>::type::ValueType* val = &i.GetValue();
			Entry* e = InsertCtor(i.GetKey(), *(typename ENTRY_HANDLER::template KeyValueConstructor<Entry, const K&, const typename std::decay<S>::type::ValueType&>*) val, created).UncheckedGetValue();
			if (!e)
			{
				return CreateError(MAXON_SOURCE_LOCATION, ERROR_TYPE::OUT_OF_MEMORY);
			}
			if (!created && overwrite)
			{
				if (ENTRY_HANDLER::LAYOUT != HASHMAP_ENTRY_LAYOUT::VALUE)
				{
					Result<void> r = AssignCopy<K>(const_cast<K&>(e->GetKey()), i.GetKey());
					if (r == FAILED)
						return r;
				}
				Result<void> r2 = AssignCopy<V>(e->GetValue(), i.GetValue());
				if (r2 == FAILED)
					return r2;
			}
		}
		return OK;
	}

	/// Class used for entries of the HashMap.
	/// The entries of a bucket are stored as a singly linked list, you can loop over this list via GetNextInBucket().
	class Entry : public HashMapEntryBase<K, V, Entry, ENTRY_HANDLER>
	{
	private:
		using Super = HashMapEntryBase<K, V, Entry, ENTRY_HANDLER>;

	public:
		using KeyType = K;
		using ValueType = V;

#ifdef MAXON_COMPILER_INTEL
		explicit Entry(UInt hash) : Super(hash)
		{
		}

		template <typename KEY> Entry(UInt hash, const KEY& key) : Super(hash, key)
		{
		}

		Entry(UInt hash, K&& key) : Super(hash, std::move(key))
		{
		}

		template <typename A> Entry(UInt hash, const K& key, A&& valueInit) : Super(hash, key, std::forward<A>(valueInit))
		{
		}

		template <typename A> Entry(UInt hash, K&& key, A&& valueInit) : Super(hash, std::move(key), std::forward<A>(valueInit))
		{
		}
#else
		using Super::Super;
#endif

		operator Pair<K, V>() const
		{
			return Pair<K, V>(this->GetKey(), this->GetValue());
		}

		//----------------------------------------------------------------------------------------
		/// Returns the next entry with the same key. This is needed for multi-maps to iterate
		/// over all entries for a key, see InsertMultiEntry().
		/// @return												Next entry with the same key, or nullptr if there is no further entry with the same key.
		//----------------------------------------------------------------------------------------
		const Entry* GetNextWithSameKey() const
		{
			return const_cast<Entry*>(this)->GetNextWithSameKey();
		}

		//----------------------------------------------------------------------------------------
		/// Returns the next entry with the same key. This is needed for multi-maps to iterate
		/// over all entries for a key, see InsertMultiEntry().
		/// @return												Next entry with the same key, or nullptr if there is no further entry with the same key.
		//----------------------------------------------------------------------------------------
		Entry* GetNextWithSameKey()
		{
			for (Entry* e = this->_next; e; e = e->_next)
			{
				if ((e->GetHashCode() == this->GetHashCode()) && HASH::IsEqual(e->GetKey(), this->GetKey()))
				{
					return e;
				}
			}
			return nullptr;
		}

		//----------------------------------------------------------------------------------------
		/// Returns the next entry in the same bucket.
		/// @return												Next entry in bucket, or nullptr if this is the last entry.
		//----------------------------------------------------------------------------------------
		const Entry* GetNextInBucket() const
		{
			return this->_next;
		}

		//----------------------------------------------------------------------------------------
		/// Returns the next entry in the same bucket.
		/// @return												Next entry in bucket, or nullptr if this is the last entry.
		//----------------------------------------------------------------------------------------
		Entry* GetNextInBucket()
		{
			return this->_next;
		}

		void PrivateInitNextInBucket(Entry* next)
		{
			DebugAssert(!this->_next);
			this->_next = next;
		}

		typename SFINAEHelper<String, V>::type ToString(const FormatStatement* format) const
		{
			return GlobalToString(this->GetKey(), format) + "->"_s + GlobalToString(this->GetValue(), format);
		}

		Int GetMemorySize() const
		{
			return SIZEOF(Entry) - SIZEOF(Super) + Super::GetMemorySize();
		}

		//----------------------------------------------------------------------------------------
		/// Returns the pointer to the entry to which #value belongs. You must not use this function
		/// if you cannot guarantee that value is a part of an entry.
		/// @param[in] value							A pointer to a value which is known to belong to an entry.
		/// @return												The entry of which #value is a part.
		//----------------------------------------------------------------------------------------
		static const Entry* Get(const V* value)
		{
			return reinterpret_cast<const Entry*>(reinterpret_cast<const Char*>(value) - MAXON_OFFSETOF_NON_STANDARD_LAYOUT(Entry, _value));
		}

		//----------------------------------------------------------------------------------------
		/// Returns the pointer to the entry to which #value belongs. You must not use this function
		/// if you cannot guarantee that value is a part of an entry.
		/// @param[in] value							A pointer to a value which is known to belong to an entry.
		/// @return												The entry of which #value is a part.
		//----------------------------------------------------------------------------------------
		static Entry* Get(typename std::remove_const<V>::type* value)
		{
			return reinterpret_cast<Entry*>(reinterpret_cast<Char*>(value) - MAXON_OFFSETOF_NON_STANDARD_LAYOUT(Entry, _value));
		}

	private:
		MAXON_DISALLOW_COPY_AND_ASSIGN(Entry);
		friend class HashMap;
	};


	template <Bool CONSTITERATOR> class MultiEntryIterator : public ForEachIterator<MultiEntryIterator<CONSTITERATOR>>
	{
	public:
		static_assert(!SYNCHRONIZED, "MultiEntryIterator not supported for a synchronized HashMap.");

		using EntryType = typename ConstIf<Entry, CONSTITERATOR>::type;

		explicit MultiEntryIterator(EntryType* e) : _entry(e) { }
		MultiEntryIterator(MultiEntryIterator&& src) : _entry(src._entry) { }

		void operator ++()
		{
			_entry = _entry->GetNextWithSameKey();
		}

		explicit operator Bool() const
		{
			return Bool(_entry != nullptr);
		}

		EntryType& operator *() const
		{
			return *_entry;
		}

		EntryType* operator ->() const
		{
			return _entry;
		}

		EntryType& GetEntry() const
		{
			return *_entry;
		}

		const K& GetKey() const
		{
			return _entry->GetKey();
		}

		typename ConstIf<V, CONSTITERATOR>::type& GetValue() const
		{
			return _entry->GetValue();
		}

	private:
		EntryType* _entry;
	};

	//----------------------------------------------------------------------------------------
	/// Returns a foreach iterator to iterate over all entries having the given key. This is only needed for a multi-map.
	/// @param[in] key								Key to search for.
	/// @return												Iterator which yields all entries having the given key.
	//----------------------------------------------------------------------------------------
	MultiEntryIterator<false> FindAll(const K& key)
	{
		return MultiEntryIterator<false>(Find(key));
	}

	//----------------------------------------------------------------------------------------
	/// Returns a foreach iterator to iterate over all entries having the given key. This is only needed for a multi-map.
	/// @param[in] key								Key to search for.
	/// @return												Iterator which yields all entries having the given key.
	//----------------------------------------------------------------------------------------
	MultiEntryIterator<true> FindAll(const K& key) const
	{
		return MultiEntryIterator<true>(Find(key));
	}

	template <Bool CONSTITERATOR> class EntryIteratorBase
	{
	public:
		// For a const iterator, both the HashMap and its entries have to be const within the iterator, otherwise they are non-const.
		// This type alias has to be used throughout the iterator code instead of just HashMap.
		using CollectionType = typename ConstIf<HashMap, CONSTITERATOR>::type;
		using EntryType = typename ConstIf<Entry, CONSTITERATOR>::type;

		explicit operator Bool() const
		{
			return Bool(_entry != nullptr);
		}

		EntryType& GetEntry() const
		{
			return *_entry;
		}

		const K& GetKey() const
		{
			return _entry->GetKey();
		}

		typename ConstIf<V, CONSTITERATOR>::type& GetValue() const
		{
			return _entry->GetValue();
		}

		EntryType& operator *() const
		{
			return *_entry;
		}

		EntryType* operator ->() const
		{
			return _entry;
		}

		Bool operator ==(const EntryIteratorBase& b) const
		{
			return _entry == b._entry;
		}

		Bool operator !=(const EntryIteratorBase& b) const
		{
			return _entry != b._entry;
		}

	protected:
		void MoveToNonEmptyBucket()
		{
			_entry = nullptr;
			while ((_bucket <= _map->_tableLengthM1) && ((_entry = LoadAcquire(_map->_table[_bucket].list)) == nullptr))
			{
				++_bucket;
			}
		}

		void ValidateBucket()
		{
			if (_bucket < 0)
			{
				if (_entry)
				{
					UInt h = _entry->GetHashCode() & (UInt) _map->_tableLengthM1;
					_bucket = _map->_table[h].nonemptyBucketsIndex;
					DebugAssert(UInt(_bucket) < UInt(_map->_nonemptyBucketCount));
				}
				else
				{
					_bucket = 0;
				}
			}
		}

		void ValidatePrev()
		{
			EntryType* p = nullptr;
			EntryType* e = LoadAcquire(_map->_table[_bucket].list);
			while (e != _entry)
			{
				DebugAssert(e);
				p = e;
				e = e->GetNextInBucket();
			}
			_prevEntry = p;
		}

		EntryType* _entry;
		CollectionType* _map;
		Int _bucket;
		EntryType* _prevEntry; // only used for non-const iterators
	};

	template <Bool CONSTITERATOR> class KeyIteratorBase : public EntryIteratorBase<CONSTITERATOR>
	{
	public:
		const K& operator *() const
		{
			return this->_entry->GetKey();
		}

		const K* operator ->() const
		{
			return &this->_entry->GetKey();
		}
	};

	template <Bool CONSTITERATOR> class ValueIteratorBase : public EntryIteratorBase<CONSTITERATOR>
	{
	public:
		using Type = typename ConstIf<V, CONSTITERATOR>::type;

		Type& operator *() const
		{
			return this->_entry->GetValue();
		}

		Type* operator ->() const
		{
			return &this->_entry->GetValue();
		}
	};

	/// Iterator template class, used as base for Iterator and ConstIterator.
	template <typename ITERATOR, Bool CONSTITERATOR, template <Bool> class SUPER> class IteratorTemplateBase : public ForEachIterator<ITERATOR, SUPER<CONSTITERATOR>>
	{
	public:
		explicit IteratorTemplateBase(typename SUPER<CONSTITERATOR>::CollectionType& m)
		{
			this->_map = &m;
			this->_bucket = 0;
			this->_prevEntry = nullptr;
			if (SYNCHRONIZED)
			{
				this->MoveToNonEmptyBucket();
			}
			else
			{
				this->_entry = m.GetNonEmptyBucketCount() ? m.GetNonEmptyBucket(0) : nullptr;
			}
		}

		explicit IteratorTemplateBase(typename SUPER<CONSTITERATOR>::CollectionType& m, Int b, typename SUPER<CONSTITERATOR>::EntryType* e)
		{
			this->_entry = e;
			this->_map = &m;
			this->_bucket = b;
			this->_prevEntry = nullptr;
		}

		IteratorTemplateBase()
		{
			this->_entry = nullptr;
			this->_map = nullptr;
			this->_bucket = 0;
			this->_prevEntry = nullptr;
		}

		const ITERATOR operator ++(int)	// postfix operator++ (fetch and increment)
		{
			const ITERATOR tmp(*this);
			++(*static_cast<ITERATOR*>(this));
			return tmp;
		}

	protected:
		friend class HashMap;
	};

	/// Iterator class for const HashMap.
	template <template <Bool> class SUPER> class ConstIteratorTemplate : public IteratorTemplateBase<ConstIteratorTemplate<SUPER>, true, SUPER>
	{
	private:
		using Base = IteratorTemplateBase<ConstIteratorTemplate<SUPER>, true, SUPER>;

	public:
		explicit ConstIteratorTemplate(typename Base::CollectionType& m) : Base(m)
		{
		}

		ConstIteratorTemplate(typename Base::CollectionType& m, Int b, typename Base::EntryType* e) : Base(m, b, e)
		{
		}

		ConstIteratorTemplate()
		{
		}

		ConstIteratorTemplate& operator ++()	// prefix operator++ (increment and fetch)
		{
			this->ValidateBucket();
			this->_entry = this->_entry->GetNextInBucket();
			if (!this->_entry)
			{
				++this->_bucket;
				if (SYNCHRONIZED)
				{
					this->MoveToNonEmptyBucket();
				}
				else if (this->_bucket < this->_map->GetNonEmptyBucketCount())
				{
					this->_entry = this->_map->GetNonEmptyBucket(this->_bucket);
				}
			}
			return *this;
		}
	};

	/// Iterator class for HashMap.
	template <template <Bool> class SUPER> class IteratorTemplate : public IteratorTemplateBase<IteratorTemplate<SUPER>, false, SUPER>
	{
	private:
		using Base = IteratorTemplateBase<IteratorTemplate<SUPER>, false, SUPER>;

	public:
		explicit IteratorTemplate(typename Base::CollectionType& m) : Base(m) { }

		IteratorTemplate(typename Base::CollectionType& m, Int b, typename Base::EntryType* e) : Base(m, b, e) { }

		IteratorTemplate() { }

		operator ConstIteratorTemplate<SUPER>&()
		{
			return *(ConstIteratorTemplate<SUPER>*) static_cast<Base*>(this);
		}

		IteratorTemplate& operator ++()	// prefix operator++ (increment and fetch)
		{
			this->ValidateBucket();
			this->_prevEntry = this->_entry;
			this->_entry = this->_entry->GetNextInBucket();
			if (!this->_entry)
			{
				this->_prevEntry = nullptr;
				++this->_bucket;
				if (SYNCHRONIZED)
				{
					this->MoveToNonEmptyBucket();
				}
				else if (this->_bucket < this->_map->GetNonEmptyBucketCount())
				{
					this->_entry = this->_map->GetNonEmptyBucket(this->_bucket);
				}
			}
			return *this;
		}

	private:
		IteratorTemplate(typename Base::CollectionType& m, Int b, typename Base::EntryType* e, typename Base::EntryType* p) : Base(m, b, e)
		{
			this->_prevEntry = p;
		}

		friend class HashMap;
	};

	using Iterator = IteratorTemplate<EntryIteratorBase>;
	using ConstIterator = ConstIteratorTemplate<EntryIteratorBase>;

	using KeyIterator = IteratorTemplate<KeyIteratorBase>;
	using ConstKeyIterator = ConstIteratorTemplate<KeyIteratorBase>;

	using ValueIterator = IteratorTemplate<ValueIteratorBase>;
	using ConstValueIterator = ConstIteratorTemplate<ValueIteratorBase>;

	//----------------------------------------------------------------------------------------
	/// Returns a foreach iterator to iterate over all keys of this map.
	/// @return												Foreach iterator over all keys.
	//----------------------------------------------------------------------------------------
	KeyIterator GetKeys()
	{
		return KeyIterator(*this);
	}

	//----------------------------------------------------------------------------------------
	/// Returns a foreach iterator to iterate over all keys of this map.
	/// @return												Foreach iterator over all keys.
	//----------------------------------------------------------------------------------------
	ConstKeyIterator GetKeys() const
	{
		return ConstKeyIterator(*this);
	}

	//----------------------------------------------------------------------------------------
	/// Returns a foreach iterator to iterate over all values of this map.
	/// @return												Foreach iterator over all values.
	//----------------------------------------------------------------------------------------
	ValueIterator GetValues()
	{
		return ValueIterator(*this);
	}

	//----------------------------------------------------------------------------------------
	/// Returns a foreach iterator to iterate over all values of this map.
	/// @return												Foreach iterator over all values.
	//----------------------------------------------------------------------------------------
	ConstValueIterator GetValues() const
	{
		return ConstValueIterator(*this);
	}

	Iterator Begin()
	{
		return Iterator(*this);
	}

	Iterator End()
	{
		return Iterator(*this, 0, nullptr);
	}

	ConstIterator Begin() const
	{
		return ConstIterator(*this);
	}

	ConstIterator End() const
	{
		return ConstIterator(*this, 0, nullptr);
	}

	template <template <Bool> class SUPER> IteratorTemplate<SUPER> Erase(const IteratorTemplate<SUPER>& it, Bool deleteEntry = true)
	{
		static_assert(!SYNCHRONIZED, "Iterator erase not supported for a synchronized HashMap.");
		Entry* e = it._entry;
		Int bucket = it._bucket;
		Entry* prev = it._prevEntry;
		if (bucket < 0)
		{
			IteratorTemplate<SUPER> tmp = it;
			tmp.ValidateBucket();
			tmp.ValidatePrev();
			bucket = tmp._bucket;
			prev = tmp._prevEntry;
		}
		Entry* next = nullptr;
		if (e)
		{
			next = e->_next;
			if (prev)
			{
				prev->_next = next;
				if (!next)
				{
					++bucket;
					if (bucket < _nonemptyBucketCount)
					{
						next = _nonemptyBuckets[bucket]->list;
					}
					prev = nullptr;
				}
			}
			else
			{
				_table[e->GetHashCode() & UInt(_tableLengthM1)].list = next;
				if (!next)
				{
					if (bucket < --_nonemptyBucketCount)
					{
						(_nonemptyBuckets[bucket] = _nonemptyBuckets[_nonemptyBucketCount])->nonemptyBucketsIndex = bucket;
						next = _nonemptyBuckets[bucket]->list;
					}
				}
			}
			if (deleteEntry)
				DeleteEntry(e);
			_size--;
		}
		return IteratorTemplate<SUPER>(*this, bucket, next, prev);
	}


	Iterator GetIterator(const Entry* e)
	{
		if (!e)
			return Iterator(*this, 0, nullptr);
		UInt h = e->GetHashCode() & (UInt) _tableLengthM1;
		return Iterator(*this, SYNCHRONIZED ? h : _table[h].nonemptyBucketsIndex, const_cast<Entry*>(e));
	}


	ConstIterator GetIterator(const Entry* e) const
	{
		if (!e)
			return ConstIterator(*this, 0, nullptr);
		UInt h = e->GetHashCode() & (UInt) _tableLengthM1;
		return ConstIterator(*this, SYNCHRONIZED ? h : _table[h].nonemptyBucketsIndex, e);
	}


	//----------------------------------------------------------------------------------------
	/// Class to compute the hash value of a HashMap. You have to use this as HASH class if you want to
	/// use HashMaps in HashSets or as keys in other HashMaps.
	/// @tparam VALUEHASH							Hash class used for HashMap values.
	//----------------------------------------------------------------------------------------
	template <typename VALUEHASH> class Hash
	{
	public:
		static Bool IsEqual(const HashMap& a, const HashMap& b, VALUEHASH&& hash = VALUEHASH())
		{
			if (a.GetCount() != b.GetCount())
			{
				return false;
			}
			Int n = SYNCHRONIZED ? a._tableLengthM1 + 1 : a._nonemptyBucketCount;
			for (Int i = 0; i < n; ++i)
			{
				for (const Entry* e = LoadAcquire((SYNCHRONIZED ? a._table + i : a._nonemptyBuckets[i])->list); e; e = e->GetNextInBucket())
				{
					const Entry* eb = b.FindEntryImpl<K, HASH>(e->GetHashCode(), e->GetKey());
					if (!eb || !hash.IsEqual(e->GetValue(), eb->GetValue()))
					{
						return false;
					}
				}
			}
			return true;
		}

		static UInt GetHashCode(const HashMap& m)
		{
			static_assert(!SYNCHRONIZED, "GetHashCode not supported for a synchronized HashMap.");
			UInt hash = 0;
			for (Int i = 0; i < m._nonemptyBucketCount; ++i)
			{
				for (const Entry* e = m._nonemptyBuckets[i]->list; e; e = e->GetNextInBucket())
				{
					hash += 31 * e->GetHashCode() + VALUEHASH::GetHashCode(e->GetValue());
				}
			}
			return hash;
		}
	};

	typename SFINAEHelper<String, V>::type ToString(const FormatStatement* formatStatement) const
	{
		return BaseCollection<HashMap, EmptyClass>::ToString(formatStatement);
	}

	template <typename KEY, typename KEYHASH> const Entry* FindEntryImpl(UInt hash, const KEY& key) const
	{
		if (!_table)
		{
			return nullptr;
		}
		for (const Entry* e = LoadAcquire(_table[hash & (UInt) _tableLengthM1].list); e; e = e->_next)
		{
			if ((hash == e->GetHashCode()) && KEYHASH::IsEqual(key, e->GetKey()))
			{
				return e;
			}
		}
		return nullptr;
	}

	template <typename KEY, typename KEYHASH> Entry* FindEntryImpl(UInt hash, const KEY& key)
	{
		return MAXON_NONCONST_COUNTERPART(template FindEntryImpl<KEY, KEYHASH>(hash, key));
	}

protected:
	struct Bucket
	{
		// TODO: (Ole) when all compilers support a union here, use this for the SYNCHRONIZED case which doesn't need nonemptyBucketsIndex
		typename std::conditional<SYNCHRONIZED, AtomicPtr<Entry>, Entry*>::type list;
		Int nonemptyBucketsIndex;
	};

	Bool ResizeTableImpl(Int length)
	{
		Bucket* t = (Bucket*) _allocator.Alloc(SIZEOF(Bucket) * length, MAXON_SOURCE_LOCATION_NAME(Bucket));
		if (!t)
		{
			return false;
		}
		Bucket** neb = nullptr;
		if (!SYNCHRONIZED)
		{
			neb = (Bucket**) _allocator.Alloc(SIZEOF(Bucket*) * length, MAXON_SOURCE_LOCATION_NAME(Bucket*));
			if (!neb)
			{
				_allocator.Free(t);
				return false;
			}
			_allocator.Free(_nonemptyBuckets);
			_nonemptyBuckets = neb;
			_nonemptyBucketCount = 0;
		}
		ClearMemType(t, length);
		Int tlM1 = length - 1;
		for (Int j = 0; j <= _tableLengthM1; j++)
		{
			Entry* entry = LoadRelaxed(_table[j].list);
			while (entry)
			{
				Entry* n = entry->_next;
				UInt h = entry->GetHashCode() & (UInt) tlM1;
				entry->_next = LoadRelaxed(t[h].list);
				if (!SYNCHRONIZED && (entry->_next == nullptr))
				{
					t[h].nonemptyBucketsIndex = _nonemptyBucketCount;
					neb[_nonemptyBucketCount++] = t + h;
				}
				StoreRelaxed(t[h].list, entry);
				entry = n;
			}
		}

		_allocator.Free(_table);
		_table = t;
		_tableLengthM1 = tlM1;
		_resizeThreshold = (_loadFactor > 0) ? (Int) (length * _loadFactor) : LIMIT<Int>::MAX;
		return true;
	}

	Entry* AddEntryImpl(Entry* e, Entry* prev, Bool& created, Bool multi, void*)
	{
		static_assert(!SYNCHRONIZED, "Wrong invocation of AddEntryImpl.");
		UInt h = e->GetHashCode() & (UInt) _tableLengthM1;
		e->_next = prev;
		StoreRelaxed(_table[h].list, e);
		++_size;
		if (e->_next == nullptr)
		{
			_table[h].nonemptyBucketsIndex = _nonemptyBucketCount;
			_nonemptyBuckets[_nonemptyBucketCount++] = _table + h;
		}
		if (_size > _resizeThreshold)
		{
			ResizeTableImpl((_tableLengthM1 + 1) << 1);
		}
		created = true;
		return e;
	}

	Entry* AddEntryImpl(Entry* e, Entry* prev, Bool& created, Bool multi, Char*)
	{
		static_assert(SYNCHRONIZED, "Wrong invocation of AddEntryImpl.");
		UInt h = e->GetHashCode() & (UInt) _tableLengthM1;
		while (true)
		{
			e->_next = prev;
			if (TryCompareAndSwap(_table[h].list, e, prev))
			{
				AtomicInt::SwapIncrement(&_size);
				created = true;
				return e;
			}
			Entry* p = LoadAcquire(_table[h].list);
			if (!multi)
			{
				for (Entry* x = p; x != prev; x = x->_next)
				{
					if ((e->GetHashCode() == x->GetHashCode()) && HASH::IsEqual(e->GetKey(), x->GetKey()))
					{
						DeleteEntry(e);
						created = false;
						return x;
					}
				}
			}
			prev = p;
		}
	}

	MAXON_DISALLOW_COPY_AND_ASSIGN(HashMap);

	static Entry* LoadRelaxed(AtomicPtr<Entry>& e)
	{
		return e.LoadRelaxed();
	}

	static Entry* LoadAcquire(AtomicPtr<Entry>& e)
	{
		return e.LoadAcquire();
	}

	static void StoreRelaxed(AtomicPtr<Entry>& e, Entry* newValue)
	{
		e.StoreRelaxed(newValue);
	}

	static Bool TryCompareAndSwap(AtomicPtr<Entry>& e, Entry* newValue, Entry* compare)
	{
		return e.TryCompareAndSwap(newValue, compare);
	}

	static Entry* LoadRelaxed(Entry* e)
	{
		return e;
	}

	static Entry* LoadAcquire(Entry* e)
	{
		return e;
	}

	static void StoreRelaxed(Entry*& e, Entry* newValue)
	{
		e = newValue;
	}

	static Bool TryCompareAndSwap(Entry*& e, Entry* newValue, Entry* compare)
	{
		e = newValue;
		return true;
	}

	const Char* GetSignature(void*) const
	{
		return nullptr;
	}

	const Char* GetSignature(Char*) const
	{
#ifdef MAXON_TARGET_WINDOWS
		return __FUNCSIG__;
#else
		return __PRETTY_FUNCTION__;
#endif
	}

	ALLOCATOR		_allocator; ///< The allocator to use.
	Bucket*			_table; ///< Pointer to the bucket table.
	Int					_tableLengthM1; ///< Length - 1 of the bucket table.
	Bucket**		_nonemptyBuckets; ///< Pointer to the array of pointers to non-empty buckets.
	Int					_nonemptyBucketCount; ///< Number of non-empty buckets.
	Int					_size; ///< Number of entries in this HashMap.
	Int					_resizeThreshold; ///< When _size exceeds this threshold, a re-hashing has to be done to satisfy the load factor setting.
	const Float _loadFactor; ///< Load factor: At most tableLength * loadFactor entries may be in this HashMap, otherwise a re-hashing is done. If non-positive, no automatic re-hashing happens.
};


template <typename HASH = DefaultCompare, typename ENTRY_HANDLER = HashMapKeyValuePair, typename ALLOCATOR = DefaultAllocator, Bool SYNCHRONIZED = false> class HashMapSelector
{
public:
	template <typename K, typename V> using Type = HashMap<K, V, HASH, ENTRY_HANDLER, ALLOCATOR, SYNCHRONIZED>;
};

template <typename K_TO, typename V_TO, typename K_FROM, typename V_FROM, Bool SAFE> struct GenericCastMemberTrait<HashMap<K_TO, V_TO>, HashMap<K_FROM, V_FROM>, SAFE>
{
	static constexpr Bool value = GenericCastMemberTrait<K_TO, K_FROM, SAFE>::value && GenericCastMemberTrait<V_TO, V_FROM, SAFE>::value;
};

//----------------------------------------------------------------------------------------
/// A HashSet is an implementation of a set based on hash codes for the elements. Internally, it is just a HashMap with no values.
/// See HashMap for the details of hash code computation, load factors, performance etc.
///
/// This example shows the basic usage of HashSet:
/// @code
/// HashSet<String> names;
/// if (!names.Insert("Alice"_s))
///   ... allocation failed ...;
///
/// Bool added = false;
/// if (!names.Insert("Bob"_s, added))
///   ... allocation failed ...;
/// if (added)
///   ... "Bob" didn't exist before in names ...;
///
/// if (names.Contains("Cindy"_s))
///   ... "Cindy" is in the set ...;
///
/// names.Erase("Bob"_s);
/// @endcode
///
/// To iterate over the entries of a HashSet, use Iterator, ConstIterator or a ranged-based for loop:
/// @code
/// for (HashSet<String>::ConstIterator i = names.Begin(); i != names.End(); ++i)
/// {
///   DiagnosticOutput("Names contains @ ", *i);
/// }
/// for (const String& n : names)
/// {
///   DiagnosticOutput("Names contains @ ", n);
/// }
/// @endcode
///
/// @tparam T											Type of elements of the set.
/// @tparam HASH									Class to be used to compute the hash code of elements, and to compare elements for equality (DefaultCompare by default)
/// @tparam ENTRY_HANDLER					Use this class to select the memory layout of entries (either the default HashMapKeyValuePair or HashMapKeyHashValuePair).
/// @tparam ALLOCATOR							Class for memory allocation.
/// @see HashMap
/// @see @$ref sets
//----------------------------------------------------------------------------------------
template <typename T, typename HASH = DefaultCompare, typename ENTRY_HANDLER = HashMapKeyValuePair, typename ALLOCATOR = DefaultAllocator, Bool SYNCHRONIZED = false> class HashSet
	: public SetBase<HashSet<T, HASH, ENTRY_HANDLER, ALLOCATOR, SYNCHRONIZED>, T, Protected<HashMap<T, UnitType, HASH, ENTRY_HANDLER, ALLOCATOR, SYNCHRONIZED>>, HASH>
{
public:
	using MapType = HashMap<T, UnitType, HASH, ENTRY_HANDLER, ALLOCATOR, SYNCHRONIZED>;
	using Super = SetBase<HashSet, T, Protected<MapType>, HASH>;
private:

	MAXON_DISALLOW_COPY_AND_ASSIGN(HashSet);

	using Super::_nonemptyBucketCount;
	using Super::_nonemptyBuckets;

	template <typename KEY, typename LAMBDA> struct LambdaEntryConstructor
	{
		Result<void> ConstructHashMapEntry(void* ptr, UInt hash, KEY&& key)
		{
			Entry* e = new (ptr) Entry(hash);
			return (*(typename std::remove_reference<LAMBDA>::type*) this)(std::forward<KEY>(key), const_cast<T&>(e->GetKey()));
		}
		static Int GetHashMapEntrySize(const typename std::remove_reference<KEY>::type& key) { return SIZEOF(Entry); }
	};

public:
	using MapType::Find;
	using MapType::InsertEntry;
	using MapType::InsertCtor;
	using MapType::GetCount;
	using MapType::GetOperationCountForSearch;
	using MapType::SetCapacityHint;
	using MapType::ResizeTable;
	using MapType::Reset;
	using MapType::Flush;
	using MapType::IntersectImpl;
	using MapType::GetMemorySize;
	using typename MapType::Entry;

	using IsHashMap = std::true_type;
	using IsHashSet = std::true_type;

	friend MapType;

	//----------------------------------------------------------------------------------------
	/// Initializes the underlying allocator and constructs a new HashSet with an optional load factor.
	/// This will not allocate any memory. Memory allocation can be done explicitly by SetCapacityHint(), or it will be done implicitly when needed.
	/// @param[in] alloc							Used to initialize the underlying allocator by its copy constructor.
	/// @param[in] loadFactor					The load factor of the HashSet.
	//----------------------------------------------------------------------------------------
	explicit HashSet(const ALLOCATOR& alloc, Float loadFactor = Float(SYNCHRONIZED ? 0 : 0.65)) : Super(alloc, loadFactor)
	{
	}

	//----------------------------------------------------------------------------------------
	/// Constructs a new HashSet with an optional load factor.
	/// This will not allocate any memory. Memory allocation can be done explicitly by SetCapacityHint(), or it will be done implicitly when needed.
	/// @param[in] loadFactor					The load factor of the HashSet.
	//----------------------------------------------------------------------------------------
	explicit HashSet(Float loadFactor = Float(SYNCHRONIZED ? 0 : 0.65)) : Super(loadFactor)
	{
	}

	HashSet(HashSet&& src) : Super(std::move(src))
	{
	}

	MAXON_OPERATOR_MOVE_ASSIGNMENT(HashSet);

	UInt GetHashCode() const
	{
		static_assert(!SYNCHRONIZED, "GetHashCode not supported for a synchronized HashSet.");
		UInt hash = 0;
		for (Int i = 0; i < _nonemptyBucketCount; ++i)
		{
			for (const typename Super::Entry* e = _nonemptyBuckets[i]->list; e; e = e->GetNextInBucket())
			{
				hash += e->GetHashCode();
			}
		}
		return hash;
	}

	MapType& GetMap() { return *this; }
	const MapType& GetMap() const { return *this; }

	//----------------------------------------------------------------------------------------
	/// Checks if this set contains @p value.
	/// @param[in] value							The value to check.
	/// @return												True if this set contains @p value.
	//----------------------------------------------------------------------------------------
	Bool Contains(typename ByValueParam<T>::type value) const
	{
		return Find(value) != nullptr;
	}

	//----------------------------------------------------------------------------------------
	/// Checks if this set contains @p key.
	/// The type KEY of the given @p key need not be the same as V, but then you have to provide
	/// an additional class KEYHASH to compute the hash code of the specified key (function KEYHASH::GetHashCode(const KEY&)),
	/// and to compare a key of type KEY with a key of type V for equality (function KEYHASH::IsEqual(const KEY&, const V&))
	/// unless the default HASH class is already able to do so.
	/// @tparam KEYHASH								Hash class to compute the hash code of key, and to compare key with the map's keys. Default is HASH.
	/// @tparam KEY										Type of key.
	/// @param[in] key								The value to check.
	/// @return												True if this set contains @p value.
	//----------------------------------------------------------------------------------------
	template <typename KEY, typename KEYHASH> Bool Contains(const KEY& key) const
	{
		return Super::template Find<KEY, KEYHASH>(key) != nullptr;
	}

	void Insert() const;

	//----------------------------------------------------------------------------------------
	/// Adds @p value to this set. If @p value is already contained in this set, nothing happens,
	/// and @p added is set to @c false.
	/// @param[in] value							Value to add to this set.
	/// @param[out] added							This will be set to true if the element didn't exist before in the set and it could be added successfully, otherwise it will be set to false.
	/// @return												Element reference or OutOfMemoryError if the allocation failed.
	//----------------------------------------------------------------------------------------
	ResultRef<typename Super::Entry> Insert(const T& value, Bool& added = BoolLValue())
	{
		return Super::InsertEntry(value, added);
	}

	//----------------------------------------------------------------------------------------
	/// Adds @p value to this set. If @p value is already contained in this set, nothing happens,
	/// and @p added is set to @c false.
	/// @param[in] value							Value to add to this set. When a new element has to be added, @p value will be moved into the new element.
	/// @param[out] added							This will be set to true if the element didn't exist before in the set and it could be added successfully, otherwise it will be set to false.
	/// @return												Element reference or OutOfMemoryError if the allocation failed.
	//----------------------------------------------------------------------------------------
	ResultRef<typename Super::Entry> Insert(T&& value, Bool& added = BoolLValue())
	{
		return Super::InsertEntry(std::move(value), added);
	}

	//----------------------------------------------------------------------------------------
	/// Adds @p value to this set. If @p value is already contained in this set, nothing happens,
	/// and @p added is set to @c false.
	/// @param[in] value							Value to add to this set.
	/// @param[out] added							This will be set to true if the element didn't exist before in the set and it could be added successfully, otherwise it will be set to false.
	/// @return												Pointer to the value in the set, or nullptr if the element had to be added, but the allocation failed.
	//----------------------------------------------------------------------------------------
	ResultRef<const T> InsertKey(const T& value, Bool& added = BoolLValue())
	{
		ResultRef<typename Super::Entry> e = Super::InsertEntry(value, added);
		return e.GetPointer() ? &e.GetValue().GetKey() : nullptr;
	}

	//----------------------------------------------------------------------------------------
	/// Adds @p value to this set. If @p value is already contained in this set, nothing happens,
	/// and @p added is set to @c false.
	/// @param[in] value							Value to add to this set. When a new element has to be added, @p value will be moved into the new element.
	/// @param[out] added							This will be set to true if the element didn't exist before in the set and it could be added successfully, otherwise it will be set to false.
	/// @return												Pointer to the value in the set, or nullptr if the element had to be added, but the allocation failed.
	//----------------------------------------------------------------------------------------
	ResultRef<const T> InsertKey(T&& value, Bool& added = BoolLValue())
	{
		ResultRef<typename Super::Entry> e = Super::InsertEntry(std::move(value), added);
		return e.GetPointer() ? &e.GetValue().GetKey() : nullptr;
	}

	//----------------------------------------------------------------------------------------
	/// Adds an entry corresponding to the given key if such an entry doesn't exist yet.
	/// If a new entry has to be created, the passed @p lambda function is invoked with the @p key as first argument
	/// and the value (of type T&) of the newly created entry as second argument. The @p lambda then has to initialize
	/// the value correctly. The lambda function has to return <tt>Result<void></tt>.
	///
	/// The type KEY of the given key need not be the same as T, but then you have to provide
	/// an additional class KEYHASH to compute the hash code of the specified key (function KEYHASH::GetHashCode(const KEY&)),
	/// and to compare a key of type KEY with a key of type T for equality (function KEYHASH::IsEqual(const KEY&, const T&))
	/// unless the default HASH class is already able to do so.
	/// @tparam KEYHASH								Hash class to compute the hash code of key, and to compare key with the map's keys. Default is HASH.
	/// @tparam KEY										Type of key.
	/// @tparam LAMBDA								Type of the function.
	/// @param[in] key								Key of the entry to find or create.
	/// @param[in] lambda							The function which will be invoked as <tt>return lambda(key, value);</tt> to initialize the value of a newly created entry.
	/// @return												Entry for the given key, or nullptr if the entry didn't exist and allocation of a new entry failed.
	//----------------------------------------------------------------------------------------
	template <typename KEYHASH = HASH, typename KEY, typename LAMBDA> Result<Entry*> InsertLambda(KEY&& key, LAMBDA&& lambda)
	{
		Bool created;
		return this->template InsertCtor<KEYHASH, KEY>(std::forward<KEY>(key), *(LambdaEntryConstructor<KEY, LAMBDA>*) &lambda, created);
	}

	//----------------------------------------------------------------------------------------
	/// Remove @p value from this set. If @p value isn't contained in this set, nothing happens.
	/// @param[in] value							Value to remove from this set.
	/// @return												True if an entry was found and removed for #value, otherwise false.
	//----------------------------------------------------------------------------------------
	ResultOk<Bool> Erase(const T& value)
	{
		return Super::Erase(value);
	}

	ResultOk<void> Erase(const Entry* entry)
	{
		return Super::Erase(entry);
	}

	using Iterator = typename Super::KeyIterator;
	using ConstIterator = typename Super::ConstKeyIterator;

	ConstIterator Begin() const
	{
		return ConstIterator(*this);
	}

	ConstIterator End() const
	{
		return ConstIterator(*this, 0, nullptr);
	}

	Iterator Begin()
	{
		return Iterator(*this);
	}

	Iterator End()
	{
		return Iterator(*this, 0, nullptr);
	}

	Iterator Erase(const Iterator& it)
	{
		return Super::Erase(it);
	}
};

template <typename TO, typename FROM, Bool SAFE> struct GenericCastMemberTrait<HashSet<TO>, HashSet<FROM>, SAFE> : public GenericCastMemberTrait<TO, FROM, SAFE>
{
};

/// @}

} // namespace maxon

#endif // HASHMAP_H__
