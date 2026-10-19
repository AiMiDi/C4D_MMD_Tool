#ifndef BLOCKHASHMAP_H__
#define BLOCKHASHMAP_H__

#include "maxon/hashmap.h"
#include "maxon/arrayallocator.h"

namespace maxon
{

template <Int EXPONENT = BLOCKARRAY_DEFAULT_SIZE_EXPONENT, Bool NO_ERASE = false, typename HASH = DefaultCompare, typename ENTRY_HANDLER = HashMapKeyValuePair, Int INITIAL_CAPACITY = 16, Int LOAD_FACTOR = 10> class BlockHashMapSelector
{
public:
	template <typename K, typename V> using Type = HashMap<K, V, HASH, ENTRY_HANDLER, DefaultAllocator, HASHMAP_MODE::DEFAULT, INITIAL_CAPACITY, LOAD_FACTOR, BlockArrayAllocator<SIZEOF(typename HashMap<K, V, HASH, ENTRY_HANDLER>::Entry), EXPONENT, NO_ERASE, true>>;
};

//----------------------------------------------------------------------------------------
/// The BlockHashMap type alias simplifies the setup of a HashMap which shall use the BlockArrayAllocator for its entries.
/// The BlockArrayAllocator allocates 2^BLOCK_SIZE_EXPONENT entries in one go in a single memory block, this reduces the memory footprint for larger maps
/// and may also speed up execution as HashMap entries are more compact in memory. In particular, iteration over all entries will happen in memory order.
///
/// You should not use the BlockHashMap for small maps because it will at least allocate memory for 2^BLOCK_SIZE_EXPONENT entries,
/// even if you insert just a single entry. Also note that the BlockArrayAllocator never frees its memory unless all entries have been erased from the map,
/// so if you insert and erase a lot of entries but never make the map completely empty, the BlockHashMap might also be the wrong choice.
///
/// @tparam K											Type of keys.
/// @tparam V											Type of values.
/// @tparam EXPONENT							Size of an array block: 2^BLOCK_SIZE_EXPONENT.
/// @tparam NO_ERASE							Use true if you won't erase individual entries at all (but you can still call Flush() or Reset() to free all at once). This slightly reduces memory consumption.
/// @tparam HASH									Class to be used to compute the hash code of keys, and to compare keys for equality (DefaultCompare by default)
/// @tparam ENTRY_HANDLER					Use this class if the keys shall be extracted from values, rather than being stored separately.
/// 															With the default argument HashMapKeyValuePair, keys and values are stored separately in the entries as key-value-pairs.
/// @tparam INITIAL_CAPACITY			The initial capacity of the HashMap, this is used when the first entry is added.
/// @tparam LOAD_FACTOR						The load factor of the HashMap in 1/16.
/// @see HashMap, BlockArrayAllocator
//----------------------------------------------------------------------------------------
template <typename K, typename V, Int EXPONENT = BLOCKARRAY_DEFAULT_SIZE_EXPONENT, Bool NO_ERASE = false, typename HASH = DefaultCompare, typename ENTRY_HANDLER = HashMapKeyValuePair, Int INITIAL_CAPACITY = 16, Int LOAD_FACTOR = 10>
using BlockHashMap = typename BlockHashMapSelector<EXPONENT, NO_ERASE, HASH, ENTRY_HANDLER, INITIAL_CAPACITY, LOAD_FACTOR>::template Type<K, V>;


template <Int EXPONENT = BLOCKARRAY_DEFAULT_SIZE_EXPONENT, Bool NO_ERASE = false, typename HASH = DefaultCompare, typename ENTRY_HANDLER = HashMapKeyValuePair, Int INITIAL_CAPACITY = 16, Int LOAD_FACTOR = 10> class BlockHashSetSelector
{
public:
	template <typename T> using Type = HashSet<T, HASH, ENTRY_HANDLER, DefaultAllocator, HASHMAP_MODE::DEFAULT, INITIAL_CAPACITY, LOAD_FACTOR, BlockArrayAllocator<SIZEOF(typename HashSet<T, HASH, ENTRY_HANDLER>::Entry), EXPONENT, NO_ERASE, true>>;
};

//----------------------------------------------------------------------------------------
/// The BlockHashSet type alias simplifies the setup of a HashSet which shall use the BlockArrayAllocator for its entries, see BlockHashMap for more details.
///
/// @tparam T											Type of elements of the set.
/// @tparam EXPONENT							Size of an array block: 2^BLOCK_SIZE_EXPONENT.
/// @tparam NO_ERASE							Use true if you won't erase individual entries at all (but you can still call Flush() or Reset() to free all at once). This slightly reduces memory consumption.
/// @tparam HASH									Class to be used to compute the hash code of keys, and to compare keys for equality (DefaultCompare by default)
/// @tparam ENTRY_HANDLER					Use this class if the keys shall be extracted from values, rather than being stored separately.
/// 															With the default argument HashMapKeyValuePair, keys and values are stored separately in the entries as key-value-pairs.
/// @tparam INITIAL_CAPACITY			The initial capacity of the HashSet, this is used when the first entry is added.
/// @tparam LOAD_FACTOR						The load factor of the HashSet in 1/16.
/// @see HashSet, BlockArrayAllocator, BlockHashMap
//----------------------------------------------------------------------------------------
template <typename T, Int EXPONENT = BLOCKARRAY_DEFAULT_SIZE_EXPONENT, Bool NO_ERASE = false, typename HASH = DefaultCompare, typename ENTRY_HANDLER = HashMapKeyValuePair, Int INITIAL_CAPACITY = 16, Int LOAD_FACTOR = 10>
using BlockHashSet = typename BlockHashSetSelector<EXPONENT, NO_ERASE, HASH, ENTRY_HANDLER, INITIAL_CAPACITY, LOAD_FACTOR>::template Type<T>;

}

#endif
