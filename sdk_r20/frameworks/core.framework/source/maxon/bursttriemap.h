#ifndef BURSTTRIEMAP_H__
#define BURSTTRIEMAP_H__

#include "maxon/blockarray.h"
#include "maxon/bitmanipulation.h"

namespace maxon
{

/// @addtogroup STRUCTURES
/// @{

template <typename NODE, typename BUCKET> class PointerBurstTriePool
{
public:
	using Index = void*;

	static void* AllocNode(Index& index)
	{
		void* n = DefaultAllocator::Alloc(SIZEOF(NODE), MAXON_SOURCE_LOCATION);
		index = n;
		return n;
	}

	static void* AllocBucket(Index& index)
	{
		void* n = DefaultAllocator::Alloc(SIZEOF(BUCKET), MAXON_SOURCE_LOCATION);
		index = (Char*) n + 1;
		return n;
	}

	static void FreeNode(Index i)
	{
		DefaultAllocator::Free(i);
	}

	static void FreeBucket(Index i)
	{
		DebugAssert((((Int) i) & (SIZEOF(Index) - 1)) == 1);
		Char* ptr = (Char*) i - 1;
		DefaultAllocator::Free(ptr);
	}

	static Bool IsNode(Index i)
	{
		return ((Int) i & (Int) 1) == 0;
	}

	static NODE* GetNode(Index i)
	{
		return (NODE*) i;
	}

	static BUCKET* GetBucket(Index i)
	{
		DebugAssert((((Int) i) & (SIZEOF(Index) - 1)) == 1);
		return (BUCKET*) ((Char*) i - 1);
	}
};


template <typename T, typename INDEX> class ElementPool
{
public:
	ElementPool() { }
	ElementPool(ElementPool&& src) : MAXON_MOVE_MEMBERS(_elements, _freeElements) { }

	MAXON_WARN_UNUSED void* Alloc(INDEX& index)
	{
		if (_freeElements.Pop(&index))
			return &_elements[index];
		index = INDEX(_elements.GetCount());
		return _elements.Append().GetPointer();
	}

	Result<void> Free(INDEX idx)
	{
		return _freeElements.Append(idx);
	}

	T* GetElement(INDEX i)
	{
		return (T*) &_elements[i];
	}

	const T* GetElement(INDEX i) const
	{
		return (T*) &_elements[i];
	}

private:
	BlockArray<AlignedStorage<SIZEOF(T), alignof(T)>, 5, BLOCKARRAYFLAGS::NOINSERTERASE> _elements;
	BaseArray<INDEX> _freeElements;
};


template <typename NODE, typename BUCKET> class ArrayBurstTriePool
{
public:
	using Index = Int;

	ArrayBurstTriePool()
	{
	}

	ArrayBurstTriePool(ArrayBurstTriePool&& src) : MAXON_MOVE_MEMBERS(_nodePool, _bucketPool) {  }

	MAXON_WARN_UNUSED void* AllocNode(Index& index)
	{
		void* ptr = _nodePool.Alloc(index);
		index = (index + 1) << 1;
		return ptr;
	}

	MAXON_WARN_UNUSED void* AllocBucket(Index& index)
	{
		void* ptr = _bucketPool.Alloc(index);
		index = (index << 1) + 1;
		return ptr;
	}

	void FreeNode(Index i)
	{
		DebugAssert((i & 1) == 0);
		if (_nodePool.Free((i >> 1) - 1) == FAILED)
			DebugStop();
	}

	void FreeBucket(Index i)
	{
		DebugAssert((i & 1) == 1);
		if (_bucketPool.Free(i >> 1) == FAILED)
			DebugStop();
	}

	static Bool IsNode(Index i)
	{
		return (i & 1) == 0;
	}

	NODE* GetNode(Index i)
	{
		DebugAssert((i & 1) == 0);
		return _nodePool.GetElement((i >> 1) - 1);
	}

	const NODE* GetNode(Index i) const
	{
		DebugAssert((i & 1) == 0);
		return _nodePool.GetElement((i >> 1) - 1);
	}

	BUCKET* GetBucket(Index i)
	{
		DebugAssert((i & 1) == 1);
		return _bucketPool.GetElement(i >> 1);
	}

	const BUCKET* GetBucket(Index i) const
	{
		DebugAssert((i & 1) == 1);
		return _bucketPool.GetElement(i >> 1);
	}

private:
	ElementPool<NODE, Index> _nodePool;
	ElementPool<BUCKET, Index> _bucketPool;
};


// class for inner nodes of the burst trie
template <Int GROUP_BITS, typename INDEX> struct BurstTrieNode
{
	BurstTrieNode()
	{
		for (Int i = 0; i < (1 << GROUP_BITS); ++i)
		{
			children[i] = 0;
		}
	}

	INDEX children[1 << GROUP_BITS]; // pointers to the children, indexed by the corresponding bits of the key
};


//----------------------------------------------------------------------------------------
/// This enum defines the sorting modes for the buckets of a BurstTrieMap.
//----------------------------------------------------------------------------------------
enum class BURSTTRIE_SORT
{
	NONE,						///< Bucket entries won't be sorted at all. If a correct ordering of the entries isn't needed, this is generally the fastest option.
	LINEAR_SEARCH,	///< Bucket entries will be sorted according to their keys. But for searching, they will be scanned in linear order nevertheless. Given small bucket sizes, this is typically faster than a binary search.
	BINARY_SEARCH,	///< Bucket entries will be sorted according to their keys, and lookup will be done with a binary search. This will be faster than a linear search only for large bucket sizes which in general are not recommended.
} MAXON_ENUM_LIST(BURSTTRIE_SORT);


// class for leaf nodes of the burst trie, they contain a simple ArrayMap-like map from keys to values
template <typename K, typename V, Int SIZE> struct BurstTrieBucket
{
	Int GetCount() const
	{
		UInt c = (UInt) (keys[SIZE - 1] - K(LIMIT<K>::MAX - SIZE + 1));
		// if the bucket isn't full yet, c is the true count. Otherwise, the subtraction caused an overflow, and the true count is SIZE
		return (Int) Min<UInt>(c, SIZE);
	}

	// result will be set to the index where key was found, or if it wasn't found to the index where key has to be inserted
	template <BURSTTRIE_SORT SORT> Bool Find(K key, Int cnt, Int& result) const
	{
		if (SORT == BURSTTRIE_SORT::BINARY_SEARCH)
		{
			Int start = 0, end = cnt;
			while (start < end)
			{
				Int mid = (start + end) >> 1;
				K k = keys[mid];
				if (k < key)
				{
					start = mid + 1;
				}
				else if (k > key)
				{
					end = mid;
				}
				else
				{
					result = mid;
					return true;
				}
			}
			result = start;
			return false;
		}
		else if (SORT == BURSTTRIE_SORT::LINEAR_SEARCH)
		{
			for (Int j = 0; j < cnt; ++j)
			{
				K k = keys[j];
				if (MAXON_UNLIKELY(k >= key))
				{
					result = j;
					return k == key;
				}
			}
			result = cnt;
			return false;
		}
		else
		{
			for (Int j = 0; j < cnt; ++j)
			{
				if (MAXON_UNLIKELY(keys[j] == key))
				{
					result = j;
					return true;
				}
			}
			result = cnt;
			return false;
		}
	}

	// removes removeCnt elements starting at index. end has to be the current count of this bucket
	void Remove(Int index, Int end, Int removeCnt)
	{
		while (index + removeCnt < end)
		{
			keys[index] = keys[index + removeCnt];
			((V*) values)[index] = std::move(((V*) values)[index + removeCnt]);
			++index;
		}
		while (--removeCnt >= 0)
		{
			((V*) values)[index + removeCnt].~V();
		}
	}

	// inserts a new element at index. end has to be the current count of this bucket
	void Insert(Int index, Int end)
	{
		V* next = (V*) values + end;
		while (index < end)
		{
#if defined(MAXON_COMPILER_GCC) // GCC (4.8.3)produces an invalid warning, so the warning is switched off
MAXON_WARNING_PUSH // depending on the optimisation level different warnings are produced
#pragma GCC diagnostic ignored "-Warray-bounds"
#endif
			keys[end] = keys[end - 1];
#if defined(MAXON_COMPILER_GCC)
MAXON_WARNING_POP
#endif
			new (next) V(std::move(next[-1]));
			--next;
			next->~V();
			--end;
		}
		new (next) V();
	}

	V& GetValue(Int index)
	{
		return ((V*) values)[index];
	}

	const V& GetValue(Int index) const
	{
		return ((const V*) values)[index];
	}

	Int GetMemorySize() const
	{
		Int sz = SIZEOF(BurstTrieBucket);
		for (Int i = 0, n = GetCount(); i < n; ++i)
		{
			sz += maxon::GetMemorySizeHelper(GetValue(i)) - SIZEOF(V);
		}
		return sz;
	}

	K keys[SIZE]; // keys of the bucket. The last one is set to LIMIT<K>::MAX - SIZE + 1 + count if count is less than SIZE.
	AlignedStorage<SIZEOF(V), alignof(V)> values[SIZE]; // values of the bucket
};


// specialization for the case of a BurstTrieSet (we don't need values)
template <typename K, Int SIZE> struct BurstTrieBucket<K, UnitType, SIZE>
{
	Int GetCount() const
	{
		UInt c = (UInt) (keys[SIZE - 1] - K(LIMIT<K>::MAX - SIZE + 1));
		return (Int) Min<UInt>(c, SIZE);
	}

	template <BURSTTRIE_SORT SORT> Bool Find(K key, Int cnt, Int& result) const
	{
		if (SORT == BURSTTRIE_SORT::BINARY_SEARCH)
		{
			Int start = 0, end = cnt;
			while (start < end)
			{
				Int mid = (start + end) >> 1;
				K k = keys[mid];
				if (k < key)
				{
					start = mid + 1;
				}
				else if (k > key)
				{
					end = mid;
				}
				else
				{
					result = mid;
					return true;
				}
			}
			result = start;
			return false;
		}
		else if (SORT == BURSTTRIE_SORT::LINEAR_SEARCH)
		{
			for (Int j = 0; j < cnt; ++j)
			{
				K k = keys[j];
				if (MAXON_UNLIKELY(k >= key))
				{
					result = j;
					return k == key;
				}
			}
			result = cnt;
			return false;
		}
		else
		{
			for (Int j = 0; j < cnt; ++j)
			{
				if (MAXON_UNLIKELY(keys[j] == key))
				{
					result = j;
					return true;
				}
			}
			result = cnt;
			return false;
		}
	}

	void Remove(Int index, Int end, Int removeCnt)
	{
		while (index + removeCnt < end)
		{
			keys[index] = keys[index + removeCnt];
			++index;
		}
	}

	void Insert(Int index, Int end)
	{
		while (index < end)
		{
			keys[end] = keys[end - 1];
			--end;
		}
	}

	UnitType& GetValue(Int index)
	{
		return *(UnitType*) keys;
	}

	const UnitType& GetValue(Int index) const
	{
		return *(const UnitType*) keys;
	}

	Int GetMemorySize() const
	{
		return SIZEOF(BurstTrieBucket);
	}

	K keys[SIZE];
};


//----------------------------------------------------------------------------------------
/// A BurstTrieMap maps unsigned integral keys to values using three levels:
///  - At first, keys are divided based on their number of leading zero bits.
///  - Then, a tree is traversed using groups of GROUP_BITS bits as indices into child nodes.
///  - Finally, a leaf node contains a small array-map-like map of at most BUCKET_SIZE entries.
/// When a full leaf node (BUCKET_SIZE entries) needs to get a further entry, it is split into
/// an inner node with children. Likewise, if after erasure an inner node has less than two-thirds of BUCKET_SIZE
/// key-value-pairs in its descendants, those pairs will be combined to a single leaf node
/// which then replaces the inner node and its descendants.
///
/// Performance characteristics:
/// Like an ArrayMap, a BurstTrieMap allows an iteration in the order of the keys.
/// But it performs much better than an ArrayMap when the number of entries gets large
/// (say, more than 100): The number of inner nodes to visit is bounded by the maximum bit
/// length of a key, so operations like insertion, erasure or searching are bounded
/// by a constant time cost, too: O(1).
///
/// See HashMap for more examples on how to use maps in general.
///
/// @tparam K											Type of keys. This must be an unsigned integral type.
/// @tparam V											Type of values.
/// @tparam GROUP_BITS						Number of bits which shall be grouped to form an index into the children array of an inner node. This shouldn't exceed 4.
/// @tparam BUCKET_SIZE						Maximum size of a bucket of a leaf node. Reasonable values are between 4 and 40.
/// @tparam SORT									Mode for sorting of the buckets.
/// @tparam POOL									Memory pool for the nodes.
/// @see @$ref maps
//----------------------------------------------------------------------------------------
template <typename K, typename V, Int GROUP_BITS = 4, Int BUCKET_SIZE = 16, BURSTTRIE_SORT SORT = BURSTTRIE_SORT::LINEAR_SEARCH, template <typename, typename> class POOL = PointerBurstTriePool> class BurstTrieMap
	: public MapBase<BurstTrieMap<K, V, GROUP_BITS, BUCKET_SIZE, SORT, POOL>, K, V, POOL<BurstTrieNode<GROUP_BITS, typename POOL<Int, Int>::Index>, BurstTrieBucket<K, V, BUCKET_SIZE>>, DefaultCompare>
{
public:
	static_assert(std::is_unsigned<K>::value, "Only unsigned integral types may be used as keys for BurstTrieMap.");
	using IsBurstTrieMap = std::true_type;
	using Bucket = BurstTrieBucket<K, V, BUCKET_SIZE>;
	using Node = BurstTrieNode<GROUP_BITS, typename POOL<Int, Int>::Index>;
	using Pool = POOL<Node, Bucket>;
	using Index = typename Pool::Index;
	using Super = MapBase<BurstTrieMap<K, V, GROUP_BITS, BUCKET_SIZE, SORT, POOL>, K, V, Pool, DefaultCompare>;
	static const Int GROUP_SIZE = 1 << GROUP_BITS;
	static const Int GROUP_MASK = GROUP_SIZE - 1;
	static const Int MAX_LEN = (SIZEOF(K) * 8 + GROUP_BITS - 1) / GROUP_BITS;

	BurstTrieMap() : Super(), _size(0) { ClearRoots(); }
	explicit BurstTrieMap(Pool&& a) : Super(std::move(a)), _size(0) { ClearRoots(); }
	explicit BurstTrieMap(const Pool& a) : Super(a), _size(0) { ClearRoots(); }

	BurstTrieMap(BurstTrieMap&& src) : Super(std::move(src)), _size(src._size)
	{
		MemCopyType(_roots, src._roots, MAX_LEN + 1);
		ClearMemType(src._roots, MAX_LEN + 1);
		src._size = 0;
	}

	MAXON_OPERATOR_MOVE_ASSIGNMENT(BurstTrieMap);

	~BurstTrieMap()
	{
		Reset();
	}

	using Super::CopyFromImpl;

	template <typename MAP> typename SFINAEHelper<Result<void>, typename std::remove_reference<MAP>::type::IsBurstTrieMap>::type CopyFromImpl(MAP&& src, COLLECTION_RESIZE_FLAGS resizeFlags, OverloadRank1)
	{
		Flush();
		Index* dest = _roots;
		for (const Index& x : src._roots)
		{
			if (x)
			{
				Result<void> r = CopyNodes(*dest, src, x);
				if (r == FAILED)
				{
					Flush();
					return r;
				}
			}
			++dest;
		}
		_size = src._size;
		return OK;
	}

	//----------------------------------------------------------------------------------------
	/// Resets the map. This destructs all entries and frees any memory held by the map, so the map
	/// will be in a state as if it had been newly constructed.
	//----------------------------------------------------------------------------------------
	void Reset()
	{
		for (Index& x : _roots)
		{
			if (x)
			{
				DestructNodes(x);
				x = 0;
			}
		}
		_size = 0;
	}

	//----------------------------------------------------------------------------------------
	/// Flushes the map. For a BurstTrieMap, this does the same as Reset(), namely
	/// it destructs all entries and frees any memory held by the map.
	//----------------------------------------------------------------------------------------
	void Flush()
	{
		Reset();
	}

	//----------------------------------------------------------------------------------------
	/// Does nothing for a BurstTrieMap.
	/// @return												Always @c true.
	//----------------------------------------------------------------------------------------
	ResultMem SetCapacityHint(Int, COLLECTION_RESIZE_FLAGS resizeFlags = COLLECTION_RESIZE_FLAGS::ON_GROW_RESERVE_CAPACITY)
	{
		return OK;
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

	//----------------------------------------------------------------------------------------
	/// Returns the maximum depth of this trie.
	/// @return												Maximum trie depth.
	//----------------------------------------------------------------------------------------
	Int GetDepth() const
	{
		Int depth = 0;
		for (Index x : _roots)
		{
			if (x)
			{
				SetMax(depth, GetDepthImpl(x));
			}
		}
		return depth;
	}

	//----------------------------------------------------------------------------------------
	/// Returns the memory usage of this map.
	/// @return												Memory size in bytes.
	//----------------------------------------------------------------------------------------
	Int GetMemorySize() const
	{
		Int sz = SIZEOF(BurstTrieMap);
		for (Index x : _roots)
		{
			if (x)
			{
				sz += GetMemorySizeImpl(x);
			}
		}
		return sz;
	}

	class IteratorBase
	{
	public:
		IteratorBase() : _map(nullptr), _rootIndex(-1), _bucketIndex(0), _top(-1), _bucket(nullptr)
		{
		}

		IteratorBase(const BurstTrieMap* m, Int s) : _map(const_cast<BurstTrieMap*>(m)), _rootIndex(-1), _top(-1)
		{
			if (s >= 0)
			{
				MoveToNext(true);
			}
			else
			{
				_bucketIndex = 0;
				_bucket = nullptr;
			}
		}

		IteratorBase(const IteratorBase& src) : _map(src._map), _rootIndex(src._rootIndex), _bucketIndex(src._bucketIndex), _top(src._top), _bucket(src._bucket)
		{
			for (Int i = 0; i <= src._top; ++i)
			{
				_path[i] = src._path[i];
				_index[i] = src._index[i];
			}
		}

		explicit operator Bool() const
		{
			return Bool(_bucket != nullptr);
		}

		//----------------------------------------------------------------------------------------
		/// Returns the key of the current key-value-pair of this iterator.
		/// @return												Current key of this iterator.
		//----------------------------------------------------------------------------------------
		const K& GetKey() const
		{
			return _bucket->keys[_bucketIndex];
		}

		//----------------------------------------------------------------------------------------
		/// Returns the value of the current key-value-pair of this iterator.
		/// @return												Current value of this iterator.
		//----------------------------------------------------------------------------------------
		const V& GetValue() const
		{
			return _bucket->GetValue(_bucketIndex);
		}

		Bool operator ==(const IteratorBase& b) const
		{
#ifdef MAXON_TARGET_DEBUG
			if ((_bucket != b._bucket) || (_bucketIndex != b._bucketIndex))
				return false;
			if (_bucket)
			{
				DebugAssert((_rootIndex == b._rootIndex) && (_top == b._top));
				for (Int i = 0; i <= _top; ++i)
				{
					DebugAssert((_path[i] == b._path[i]) && (_index[i] == b._index[i]));
				}
			}
			return true;
#else
			return (_bucket == b._bucket) && (_bucketIndex == b._bucketIndex);
#endif
		}

		Bool operator <(const IteratorBase& b) const
		{
			if (_bucket == b._bucket)
				return _bucketIndex < b._bucketIndex;
			if (!b._bucket)
				return true;
			if (!_bucket)
				return false;
			return _bucket->keys[_bucketIndex] < b._bucket->keys[b._bucketIndex];
		}

		MAXON_OPERATOR_COMPARISON(IteratorBase);

	protected:
		void MoveToNext(Bool init)
		{
			Index idx;
			Int32* childIndex;
			if (init)
				goto upwards;
			++_bucketIndex;
		findEntry:
			if (_bucketIndex == _bucket->GetCount())
			{
			upwards:
				if (_top < 0)
				{
					while (++_rootIndex <= MAX_LEN)
					{
						idx = _map->_roots[_rootIndex];
						if (idx)
							goto loadNode;
					}
					_bucket = nullptr;
					_bucketIndex = 0;
				}
				else
				{
					childIndex = &_index[_top];
					++*childIndex;
				findChild:
					while (*childIndex < GROUP_SIZE)
					{
						idx = _path[_top]->children[*childIndex];
						if (idx)
							goto loadNode;
						++*childIndex;
					}
					--_top;
					goto upwards;
				}
			}
			return;

		loadNode:
			if (_map->IsNode(idx))
			{
				Node* n = const_cast<BurstTrieMap*>(_map)->GetNode(idx);
				_path[++_top] = n;
				childIndex = &_index[_top];
				*childIndex = 0;
				goto findChild;
			}
			else
			{
				_bucket = const_cast<BurstTrieMap*>(_map)->GetBucket(idx);
				_bucketIndex = 0;
				goto findEntry;
			}
		}

		void MoveToPrev()
		{
			Index idx;
			Int32* childIndex;
			if (_bucket == nullptr)
			{
				// iterator points behind last entry, move to last entry
				_rootIndex = MAX_LEN + 1;
				goto upwards;
			}
			--_bucketIndex;
		findEntry:
			if (_bucketIndex < 0)
			{
			upwards:
				if (_top < 0)
				{
					while (--_rootIndex >= 0)
					{
						idx = _map->_roots[_rootIndex];
						if (idx)
							goto loadNode;
					}
					_bucket = nullptr;
					_bucketIndex = 0;
				}
				else
				{
					childIndex = &_index[_top];
					--*childIndex;
				findChild:
					while (*childIndex >= 0)
					{
						idx = _path[_top]->children[*childIndex];
						if (idx)
							goto loadNode;
						--*childIndex;
					}
					--_top;
					goto upwards;
				}
			}
			return;

		loadNode:
			if (_map->IsNode(idx))
			{
				Node* n = const_cast<BurstTrieMap*>(_map)->GetNode(idx);
				_path[++_top] = n;
				childIndex = &_index[_top];
				*childIndex = GROUP_SIZE - 1;
				goto findChild;
			}
			else
			{
				_bucket = const_cast<BurstTrieMap*>(_map)->GetBucket(idx);
				_bucketIndex = _bucket->GetCount() - 1;
				goto findEntry;
			}
		}

		friend class BurstTrieMap;

		BurstTrieMap* _map; ///< Map of this iterator.
		Int _rootIndex; ///< Current index in the map's _roots array.
		Int _bucketIndex; ///< Current index in the bucket.
		Int _top; ///< Last valid index into the _path/_index-arrays.
		Bucket* _bucket; ///< Current bucket.
		Node* _path[MAX_LEN]; ///< Current path from the root to _bucket.
		Int32 _index[MAX_LEN]; ///< Used child indices along the path.
	};

	class NonConstIteratorBase : public IteratorBase
	{
	public:
		NonConstIteratorBase() { }
		NonConstIteratorBase(BurstTrieMap* m, Int s) : IteratorBase(m, s) { }
		NonConstIteratorBase(const NonConstIteratorBase& src) : IteratorBase(src) { }

		//----------------------------------------------------------------------------------------
		/// Returns the value of the current key-value-pair of this iterator.
		/// @return												Current value of this iterator.
		//----------------------------------------------------------------------------------------
		V& GetValue() const
		{
			return this->_bucket->GetValue(this->_bucketIndex);
		}

		//----------------------------------------------------------------------------------------
		/// Removes @p eraseCnt elements from the map starting at the position given by this iterator.
		/// Afterwards, this iterator will point to the element behind the last removed element.
		/// @param[in] map								Map of this iterator.
		/// @param[in] eraseCnt						Number of elements to remove.
		/// @return												False if some allocation failed (for a BurstTrieMap, this is impossible, so this function will always return true).
		//----------------------------------------------------------------------------------------
		ResultOk<void> Erase(BurstTrieMap& map, Int eraseCnt = 1)
		{
			DebugAssert(&map == this->_map);
			while (eraseCnt > 0)
			{
				if (!this->_bucket)
					return OK;
				Int cnt = this->_bucket->GetCount();
				Int rc = Min(cnt - this->_bucketIndex, eraseCnt);
				DebugAssert(rc > 0);
				eraseCnt -= rc;
				this->_bucket->Remove(this->_bucketIndex, cnt, rc);
				cnt -= rc;
				map._size -= rc;
				if (cnt == 0)
				{
					Index& i = (this->_top < 0) ? map._roots[this->_rootIndex] : this->_path[this->_top]->children[this->_index[this->_top]];
					DebugAssert(map.GetBucket(i) == this->_bucket);
					map.FreeBucket(i);
					this->_bucket = nullptr;
					i = 0;
				}
				else
				{
					this->_bucket->keys[BUCKET_SIZE - 1] = K(LIMIT<K>::MAX - BUCKET_SIZE + 1) + K(cnt);
				}
				while (this->_top >= 0)
				{
					Node* n = this->_path[this->_top];
					Int entries = 0;
					for (Index c : n->children)
					{
						if (c)
						{
							if (Pool::IsNode(c))
								goto makeValid;
							else
								entries += map.GetBucket(c)->GetCount();
						}
					}
					if (entries >= BUCKET_SIZE * 2 / 3)
						goto makeValid;
					Bucket* b = nullptr;
					Index i = 0;
					cnt = 0;
					Int ci = 0;
					for (Index c : n->children)
					{
						if (this->_index[this->_top] == ci)
						{
							this->_bucketIndex += cnt;
						}
						++ci;
						if (c)
						{
							Bucket* bc = map.GetBucket(c);
							if (!b)
							{
								b = bc;
								i = c;
								cnt = b->GetCount();
							}
							else
							{
								Int ccnt = bc->GetCount();
								for (Int j = 0; j < ccnt; ++j, ++cnt)
								{
									b->keys[cnt] = bc->keys[j];
									if (!std::is_empty<V>::value)
									{
										new (&b->GetValue(cnt)) V(std::move(bc->GetValue(j)));
										bc->GetValue(j).~V();
									}
								}
								map.FreeBucket(c);
							}
						}
					}
					--this->_top;
					DebugAssert(cnt == entries);
					if (b && (cnt != BUCKET_SIZE))
					{
						b->keys[BUCKET_SIZE - 1] = K(LIMIT<K>::MAX - BUCKET_SIZE + 1) + K(cnt);
					}
					this->_bucket = b;
					Index& parentLink = (this->_top < 0) ? map._roots[this->_rootIndex] : this->_path[this->_top]->children[this->_index[this->_top]];
					DebugAssert(map.IsNode(parentLink) && (map.GetNode(parentLink) == this->_path[this->_top + 1]));
					map.FreeNode(parentLink);
					parentLink = i;
				}
			makeValid:
				if (!this->_bucket || (this->_bucketIndex >= this->_bucket->GetCount()))
				{
					DebugAssert(!this->_bucket || (this->_bucketIndex == this->_bucket->GetCount()));
					this->MoveToNext(true);
				}
			}
			return OK;
		}

		//----------------------------------------------------------------------------------------
		/// Modifies the key of the map entry pointed to by this iterator. The new key must be in a range
		/// such that this operation doesn't change the order, i.e., it must be above the
		/// key of the previous entry and below the key of the next entry.
		///
		/// This function is not supported when the sorting mode is BURSTTRIE_SORT::NONE.
		/// @param[in] map								Map of this iterator.
		/// @param[in] newKey							New value for the key of the current map entry.
		/// @return												False if some allocation failed.
		//----------------------------------------------------------------------------------------
		ResultMem ChangeKey(BurstTrieMap& map, K newKey)
		{
			static_assert(SORT != BURSTTRIE_SORT::NONE, "ChangeKey requires a sorted BurstTrieMap.");
			DebugAssert(&map == this->_map);
			if (this->GetKey() == newKey)
				return OK;
			Int pos = (UInt(SIZEOF(K) * 8 + GROUP_BITS - 1) - UInt(Clz(newKey))) / UInt(GROUP_BITS);
			if ((pos == this->_rootIndex) && (((this->GetKey() ^ newKey) >> (pos - (this->_top + 1)) * GROUP_BITS) == 0))
			{
				Int index;
				Int cnt = this->_bucket->GetCount();
				if (!this->_bucket->template Find<SORT>(newKey, cnt, index))
				{
					if ((SORT == BURSTTRIE_SORT::NONE) || (index == this->_bucketIndex) || (index == this->_bucketIndex + 1))
					{
						this->_bucket->keys[this->_bucketIndex] = newKey;
					}
					else if (std::is_empty<V>::value)
					{
						this->_bucket->Remove(this->_bucketIndex, cnt, 1);
						if (index > this->_bucketIndex)
							--index;
						this->_bucketIndex = index;
						this->_bucket->Insert(index, cnt - 1);
						this->_bucket->keys[index] = newKey;
					}
					else
					{
						V value(std::move(GetValue()));
						this->_bucket->Remove(this->_bucketIndex, cnt, 1);
						if (index > this->_bucketIndex)
							--index;
						this->_bucketIndex = index;
						this->_bucket->Insert(index, cnt - 1);
						this->_bucket->keys[index] = newKey;
						GetValue() = std::move(value);
					}
					return OK;
				}
			}
			if (std::is_empty<V>::value)
			{
				Erase(map, 1);
				Bool created;
				auto e = map.InsertEntry(newKey, created);
				if (e == FAILED)
					return FAILED;
				*this = e.GetValue();
			}
			else
			{
				V value(std::move(GetValue()));
				Erase(map, 1);
				Bool created;
				auto e = map.InsertEntry(newKey, created);
				if (e == FAILED)
					return FAILED;
				*this = e.GetValue();
				GetValue() = std::move(value);
			}
			return OK;
		}
	};


	//----------------------------------------------------------------------------------------
	/// Iterator implementation for BurstTrieMap. Besides the usual iterator operations,
	/// BurstTrieMap iterators support the foreach protocol and Erase and ChangeKey functions.
	/// Unless the sorting mode is BURSTTRIE_SORT::NONE, the iterator will point to the map entries in ascending order of the keys
	/// if you use ++ on the iterator.
	//----------------------------------------------------------------------------------------
	template <Bool CONSTITERATOR, template <Bool> class SUPER> class IteratorTemplate : public ForEachIterator<IteratorTemplate<CONSTITERATOR, SUPER>, SUPER<CONSTITERATOR>>
	{
	public:
		using Super = ForEachIterator<IteratorTemplate<CONSTITERATOR, SUPER>, SUPER<CONSTITERATOR>>;

		IteratorTemplate() { }
		explicit IteratorTemplate(typename Super::CollectionType& m, Int s = 0) : Super(m, s) { }
		IteratorTemplate(const IteratorTemplate& src) : Super(src) { }

		MAXON_OPERATOR_COPY_ASSIGNMENT(IteratorTemplate);

		template <Bool C, template <Bool> class S, typename = typename std::enable_if<!CONSTITERATOR || C>::type> operator IteratorTemplate<C, S>&()
		{
			MAXON_ASSERT_STANDARD_LAYOUT(IteratorTemplate);
			using ICS = IteratorTemplate<C, S>;
			MAXON_ASSERT_STANDARD_LAYOUT(ICS);
			static_assert(SIZEOF(IteratorTemplate) == SIZEOF(ICS), "Iterators have different size.");
			return *reinterpret_cast<ICS*>(this);
		}

		using Super::operator Bool;

		IteratorTemplate& operator ++()
		{
			this->MoveToNext(false);
			return *this;
		}

		IteratorTemplate operator ++(int)
		{
			IteratorTemplate tmp(*this);
			this->MoveToNext(false);
			return tmp;
		}

		IteratorTemplate& operator --()
		{
			this->MoveToPrev();
			return *this;
		}

		IteratorTemplate operator --(int)
		{
			IteratorTemplate tmp(*this);
			this->MoveToPrev();
			return tmp;
		}
	};

	template <Bool CONSTITERATOR> class EntryIteratorBase : public std::conditional<CONSTITERATOR, IteratorBase, NonConstIteratorBase>::type
	{
	public:
		using Super = typename std::conditional<CONSTITERATOR, IteratorBase, NonConstIteratorBase>::type;
		using CollectionType = typename ConstIf<BurstTrieMap, CONSTITERATOR>::type;
		using KeyType = K;
		using MappedType = typename ConstIf<V, CONSTITERATOR>::type;
		using Type = Pair<K, typename std::conditional<std::is_empty<MappedType>::value, MappedType, MappedType&>::type>;

		EntryIteratorBase() { }
		EntryIteratorBase(CollectionType& m, Int s) : Super(&m, s) { DebugAssert(s <= 0); }
		EntryIteratorBase(const EntryIteratorBase& src) : Super(src) { }

		Type operator *() const
		{
			return Type(this->_bucket->keys[this->_bucketIndex], this->_bucket->GetValue(this->_bucketIndex));
		}

	protected:
		void operator ->();
	};

	template <Bool CONSTITERATOR> class KeyIteratorBase : public EntryIteratorBase<CONSTITERATOR>
	{
	public:
		using Super = EntryIteratorBase<CONSTITERATOR>;

		KeyIteratorBase() { }
		KeyIteratorBase(typename Super::CollectionType& m, Int s) : Super(m, s) { }
		KeyIteratorBase(const KeyIteratorBase& src) : Super(src) { }

		const K& operator *() const
		{
			return this->GetKey();
		}

		const K* operator ->() const
		{
			return &this->GetKey();
		}
	};

	template <Bool CONSTITERATOR> class ValueIteratorBase : public EntryIteratorBase<CONSTITERATOR>
	{
	public:
		using Type = typename ConstIf<V, CONSTITERATOR>::type;
		using Super = EntryIteratorBase<CONSTITERATOR>;

		ValueIteratorBase() { }
		ValueIteratorBase(typename Super::CollectionType& m, Int s) : Super(m, s) { }
		ValueIteratorBase(const ValueIteratorBase& src) : Super(src) { }

		Type& operator *() const
		{
			return this->GetValue();
		}

		Type* operator ->() const
		{
			return &this->GetValue();
		}
	};

	using Iterator = IteratorTemplate<false, EntryIteratorBase>;
	using ConstIterator = IteratorTemplate<true, EntryIteratorBase>;

	using KeyIterator = IteratorTemplate<false, KeyIteratorBase>;
	using ConstKeyIterator = IteratorTemplate<true, KeyIteratorBase>;

	using ValueIterator = IteratorTemplate<false, ValueIteratorBase>;
	using ConstValueIterator = IteratorTemplate<true, ValueIteratorBase>;

	//----------------------------------------------------------------------------------------
	/// Returns an iterator pointing to the first entry of this map.
	/// Unless the sorting mode is BURSTTRIE_SORT::NONE, the iteration order corresponds to the order of the keys.
	/// @return												Iterator for this map pointing to the first element.
	//----------------------------------------------------------------------------------------
	Iterator Begin()
	{
		return Iterator(*this);
	}

	//----------------------------------------------------------------------------------------
	/// Returns an iterator pointing just behind the last entry of this map.
	/// Unless the sorting mode is BURSTTRIE_SORT::NONE, the iteration order corresponds to the order of the keys.
	/// @return												Iterator for this map pointing behind the last element.
	//----------------------------------------------------------------------------------------
	Iterator End()
	{
		return Iterator(*this, -1);
	}

	//----------------------------------------------------------------------------------------
	/// Returns an iterator pointing to the first entry of this map.
	/// Unless the sorting mode is BURSTTRIE_SORT::NONE, the iteration order corresponds to the order of the keys.
	/// @return												Iterator for this map pointing to the first element.
	//----------------------------------------------------------------------------------------
	ConstIterator Begin() const
	{
		return ConstIterator(*this);
	}

	//----------------------------------------------------------------------------------------
	/// Returns an iterator pointing just behind the last entry of this map.
	/// Unless the sorting mode is BURSTTRIE_SORT::NONE, the iteration order corresponds to the order of the keys.
	/// @return												Iterator for this map pointing behind the last element.
	//----------------------------------------------------------------------------------------
	ConstIterator End() const
	{
		return ConstIterator(*this, -1);
	}

	//----------------------------------------------------------------------------------------
	/// Returns a foreach iterator to iterate over all keys of this map.
	/// Unless the sorting mode is BURSTTRIE_SORT::NONE, this will yield all keys in ascending order.
	/// @return												Foreach iterator over all keys.
	//----------------------------------------------------------------------------------------
	KeyIterator GetKeys()
	{
		return KeyIterator(*this);
	}

	//----------------------------------------------------------------------------------------
	/// Returns a foreach iterator to iterate over all keys of this map.
	/// Unless the sorting mode is BURSTTRIE_SORT::NONE, this will yield all keys in ascending order.
	/// @return												Foreach iterator over all keys.
	//----------------------------------------------------------------------------------------
	ConstKeyIterator GetKeys() const
	{
		return ConstKeyIterator(*this);
	}

	//----------------------------------------------------------------------------------------
	/// Returns a foreach iterator to iterate over all values of this map.
	/// Unless the sorting mode is BURSTTRIE_SORT::NONE, this will yield all values in ascending order of the corresponding keys.
	/// @return												Foreach iterator over all values.
	//----------------------------------------------------------------------------------------
	ValueIterator GetValues()
	{
		return ValueIterator(*this);
	}

	//----------------------------------------------------------------------------------------
	/// Returns a foreach iterator to iterate over all values of this map.
	/// Unless the sorting mode is BURSTTRIE_SORT::NONE, this will yield all values in ascending order of the corresponding keys.
	/// @return												Foreach iterator over all values.
	//----------------------------------------------------------------------------------------
	ConstValueIterator GetValues() const
	{
		return ConstValueIterator(*this);
	}

	//----------------------------------------------------------------------------------------
	/// Finds the entry with the given key, or creates such an entry if it doesn't exist yet,
	/// and returns an iterator pointing to the entry.
	/// The value of a new entry has to be initialized afterwards (but its default constructor has already been invoked).
	/// @param[in] key								Key of the entry to find or create.
	/// @param[out] created						This will be set to true if a new entry has been created successfully, otherwise it will be set to false.
	/// @return												Iterator to the entry for the given key or OutOfMemoryError if the allocation failed.
	//----------------------------------------------------------------------------------------
	ResultMemT<Iterator> InsertEntry(K key, Bool& created = BoolLValue())
	{
		created = false;
		Int pos = (UInt(SIZEOF(K) * 8 + GROUP_BITS - 1) - UInt(Clz(key))) / GROUP_BITS;
		Iterator it;
		it._map = this;
		it._rootIndex = pos;
		it._top = -1;
		Index* i = &_roots[pos];
		pos *= GROUP_BITS;
		while (true)
		{
			if (!*i)
			{
				it._bucket = (Bucket*) Pool::AllocBucket(*i);
				if (!it._bucket)
					return FAILED;
				created = true;
				++_size;
				it._bucket->keys[BUCKET_SIZE - 1] = LIMIT<K>::MAX - BUCKET_SIZE + 2;
				it._bucket->keys[0] = key;
				it._bucketIndex = 0;
				if (!std::is_empty<V>::value)
					new (&it._bucket->GetValue(0)) V();
				return it;
			}
			if (Pool::IsNode(*i))
			{
				Node* n = Pool::GetNode(*i);
				pos -= GROUP_BITS;
				DebugAssert(pos >= 0);
				it._path[++it._top] = n;
				i = &n->children[it._index[it._top] = (key >> pos) & GROUP_MASK];
			}
			else
			{
				it._bucket = Pool::GetBucket(*i);
				Int cnt = it._bucket->GetCount();
				if (it._bucket->template Find<SORT>(key, cnt, it._bucketIndex))
				{
					return it;
				}
				if (cnt < BUCKET_SIZE)
				{
					created = true;
					++_size;
					++it._bucket->keys[BUCKET_SIZE - 1];
					if (it._bucketIndex == cnt)
					{
						it._bucket->keys[cnt] = key;
						if (!std::is_empty<V>::value)
							new (&it._bucket->GetValue(cnt)) V();
					}
					else
					{
						it._bucket->Insert(it._bucketIndex, cnt);
						it._bucket->keys[it._bucketIndex] = key;
					}
					return it;
				}
				else
				{
					Index nIndex;
					Node* n = (Node*) Pool::AllocNode(nIndex);
					if (!n)
						return FAILED;
					new (n) Node();
					DebugAssert(cnt == BUCKET_SIZE);
					pos -= GROUP_BITS;
					DebugAssert(pos >= 0);
					it._path[++it._top] = n;
					Int firstChildIndex = (it._bucket->keys[0] >> pos) & GROUP_MASK;
					for (Int j = 1; j < cnt; ++j)
					{
						Int childIndex = (it._bucket->keys[j] >> pos) & GROUP_MASK;
						if (childIndex != firstChildIndex)
						{
							Bucket* bc;
							Int arrayIndex;
							Index& child = n->children[childIndex];
							if (!child)
							{
								bc = (Bucket*) Pool::AllocBucket(child);
								if (!bc)
									return Iterator();
								arrayIndex = 0;
								bc->keys[BUCKET_SIZE - 1] = LIMIT<K>::MAX - BUCKET_SIZE + 2;
							}
							else
							{
								bc = Pool::GetBucket(child);
								arrayIndex = (Int)(bc->keys[BUCKET_SIZE - 1] - K(LIMIT<K>::MAX - BUCKET_SIZE + 1));
								++bc->keys[BUCKET_SIZE - 1];
							}
							bc->keys[arrayIndex] = it._bucket->keys[j];
							if (!std::is_empty<V>::value)
								new (&bc->GetValue(arrayIndex)) V(std::move(it._bucket->GetValue(j)));
							it._bucket->Remove(j, cnt, 1);
							--cnt;
							--j;
						}
					}
					DebugAssert(cnt > 0);
					if (cnt != BUCKET_SIZE)
					{
						it._bucket->keys[BUCKET_SIZE - 1] = K(LIMIT<K>::MAX - BUCKET_SIZE + 1) + K(cnt);
					}
					n->children[firstChildIndex] = *i;
					*i = nIndex;
					i = &n->children[it._index[it._top] = (key >> pos) & GROUP_MASK];
				}
			}
		}
	}

	//----------------------------------------------------------------------------------------
	/// Finds the entry with the given key, or creates such an entry if it doesn't exist yet,
	/// Then the value of the entry is set to the given value, whether the entry existed before or not.
	/// @param[in] key								Key of the value to find or create.
	/// @param[in] value							Value to which the key shall map.
	/// @param[out] created						This will be set to true if a new entry has been created successfully, otherwise it will be set to false.
	/// @return												Iterator to the entry for the given key or OutOfMemoryError if the allocation failed.
	//----------------------------------------------------------------------------------------
	ResultMemT<Iterator> Insert(K key, const V& value, Bool& created = BoolLValue())
	{
		Iterator i = InsertEntry(key, created).GetValue();
		if (i)
		{
			if (AssignCopy<V>(i.GetValue(), value) == FAILED)
				return FAILED;
		}
		return i; // using std::move would prevent copy elision [-Wpessimizing-move]
	}

	//----------------------------------------------------------------------------------------
	/// Finds the entry with the given key, or creates such an entry if it doesn't exist yet,
	/// Then the value of the entry is set to the given value, whether the entry existed before or not.
	/// @param[in] key								Key of the value to find or create.
	/// @param[in] value							Value to which the key shall map. It will be moved into the map.
	/// @param[out] created						This will be set to true if a new entry has been created successfully, otherwise it will be set to false.
	/// @return												Iterator to the entry for the given key or OutOfMemoryError if the allocation failed.
	//----------------------------------------------------------------------------------------
	ResultMemT<Iterator> Insert(K key, V&& value, Bool& created = BoolLValue())
	{
		ResultMemT<Iterator> i = InsertEntry(key, created).GetValue();
		if (i == OK)
		{
			i.GetValue().GetValue() = std::move(value);
		}
		return i;
	}

	//----------------------------------------------------------------------------------------
	/// Finds the value associated with the given key, or creates a corresponding entry if it doesn't exist yet.
	/// The value of a new entry has to be initialized afterwards (but its default constructor has already been invoked).
	/// @param[in] key								Key of the value to find or create.
	/// @param[out] created						This will be set to true if a new entry has been created successfully, otherwise it will be set to false.
	/// @return												Pointer to value for the given key, or nullptr if an entry didn't exist and allocation of a new entry failed.
	//----------------------------------------------------------------------------------------
	ResultRef<V> InsertKey(K key, Bool& created = BoolLValue())
	{
		ResultMemT<Iterator> i = InsertEntry(key, created).GetValue();
		return (i == OK) ? &i.GetValue().GetValue() : nullptr;
	}

	//----------------------------------------------------------------------------------------
	/// Finds the value associated with the given key in this map.
	/// @param[in] key								Key to search for.
	/// @return												Pointer to value for the given key, or nullptr if no entry exists for the key.
	//----------------------------------------------------------------------------------------
	const V* FindValue(K key) const
	{
		Int pos = (UInt(SIZEOF(K) * 8 + GROUP_BITS - 1) - UInt(Clz(key))) / GROUP_BITS;
		Index i = _roots[pos];
		if (!i)
			return nullptr;
		pos *= GROUP_BITS;
		while (true)
		{
			if (Pool::IsNode(i))
			{
				const Node* n = Pool::GetNode(i);
				pos -= GROUP_BITS;
				DebugAssert(pos >= 0);
				i = n->children[(key >> pos) & GROUP_MASK];
				if (!i)
					return nullptr;
			}
			else
			{
				const Bucket* b = Pool::GetBucket(i);
				Int cnt = b->GetCount();
				Int index;
				if (b->template Find<SORT>(key, cnt, index))
				{
					return &b->GetValue(index);
				}
				return nullptr;
			}
		}
	}

	//----------------------------------------------------------------------------------------
	/// Finds the value associated with the given key in this map.
	/// @param[in] key								Key to search for.
	/// @return												Pointer to value for the given key, or nullptr if no entry exists for the key.
	//----------------------------------------------------------------------------------------
	V* FindValue(K key)
	{
		return MAXON_NONCONST_COUNTERPART(FindValue(key));
	}

	//----------------------------------------------------------------------------------------
	/// Finds the entry for the given key in this map.
	/// @param[in] key								Key to search for.
	/// @return												Iterator pointing to the entry with the given @p key,
	/// 															or an invalid iterator if this doesn't exist.
	//----------------------------------------------------------------------------------------
	Iterator Find(K key)
	{
		Int pos = (UInt(SIZEOF(K) * 8 + GROUP_BITS - 1) - UInt(Clz(key))) / GROUP_BITS;
		Index i = _roots[pos];
		if (!i)
			return Iterator();
		Iterator it;
		it._map = this;
		it._rootIndex = pos;
		it._top = -1;
		pos *= GROUP_BITS;
		while (true)
		{
			if (Pool::IsNode(i))
			{
				Node* n = Pool::GetNode(i);
				pos -= GROUP_BITS;
				DebugAssert(pos >= 0);
				it._path[++it._top] = n;
				i = n->children[it._index[it._top] = (key >> pos) & GROUP_MASK];
				if (!i)
					return Iterator();
			}
			else
			{
				it._bucket = Pool::GetBucket(i);
				Int cnt = it._bucket->GetCount();
				if (it._bucket->template Find<SORT>(key, cnt, it._bucketIndex))
				{
					return it;
				}
				return Iterator();
			}
		}
	}

	//----------------------------------------------------------------------------------------
	/// Finds the entry for the given key in this map.
	/// @param[in] key								Key to search for.
	/// @return												Iterator pointing to the entry with the given @p key,
	/// 															or an invalid iterator if this doesn't exist.
	//----------------------------------------------------------------------------------------
	ConstIterator Find(K key) const
	{
		return const_cast<BurstTrieMap*>(this)->Find(key);
	}

	//----------------------------------------------------------------------------------------
	/// Finds the entry with the greatest key less than or equal to the given @p key.
	/// If no such entry exists, the returned iterator will be invalid (its <tt>operator Bool</tt> will return false).
	/// This function is not supported when the sorting mode is BURSTTRIE_SORT::NONE.
	/// @param[in] key								Key to search for.
	/// @return												Iterator pointing to the entry with greatest key less than or equal to the given @p key,
	/// 															or an invalid iterator if this doesn't exist.
	//----------------------------------------------------------------------------------------
	Iterator FindFloor(K key)
	{
		static_assert(SORT != BURSTTRIE_SORT::NONE, "FindFloor requires a sorted BurstTrieMap.");
		Int pos = (UInt(SIZEOF(K) * 8 + GROUP_BITS - 1) - UInt(Clz(key))) / GROUP_BITS;
		Iterator it;
		it._map = this;
		it._rootIndex = pos;
		it._top = -1;
		pos *= GROUP_BITS;

		Index c = 0;
		Bool match = true;
		Int32* childIndex = nullptr;

	topLevel:
		while (true)
		{
			if (it._rootIndex < 0)
				return Iterator();
			c = _roots[it._rootIndex];
			if (c)
			{
				goto push;
			}
			match = false;
			--it._rootIndex;
		}

	node:
		while (true)
		{
			if (*childIndex < 0)
			{
				pos += GROUP_BITS;
				if (--it._top < 0)
				{
					--it._rootIndex;
					goto topLevel;
				}
				else
				{
					childIndex = &it._index[it._top];
					--*childIndex;
					goto node;
				}
			}
			c = it._path[it._top]->children[*childIndex];
			if (c)
			{
				goto push;
			}
			match = false;
			--*childIndex;
		}

	push:
		if (Pool::IsNode(c))
		{
			Node* n = Pool::GetNode(c);
			pos -= GROUP_BITS;
			DebugAssert(pos >= 0);
			DebugAssert(it._top + 1 < MAX_LEN);
			it._path[++it._top] = n;
			childIndex = &it._index[it._top];
			*childIndex = match ? ((key >> pos) & GROUP_MASK) : GROUP_SIZE - 1;
			goto node;
		}
		else
		{
			it._bucket = Pool::GetBucket(c);
			Int cnt = it._bucket->GetCount();
			DebugAssert(cnt > 0);
			if (!match)
			{
				it._bucketIndex = cnt - 1;
				return it;
			}
			if (it._bucket->template Find<SORT>(key, cnt, it._bucketIndex))
			{
				return it;
			}
			if (--it._bucketIndex >= 0)
			{
				return it;
			}
			match = false;
			if (it._top < 0)
			{
				--it._rootIndex;
				goto topLevel;
			}
			else
			{
				--*childIndex;
				goto node;
			}
		}
	}

	//----------------------------------------------------------------------------------------
	/// Finds the entry with the greatest key less than or equal to the given @p key.
	/// If no such entry exists, the returned iterator will be invalid (its <tt>operator Bool</tt> will return false).
	/// This function is not supported when the sorting mode is BURSTTRIE_SORT::NONE.
	/// @param[in] key								Key to search for.
	/// @return												Iterator pointing to the entry with greatest key less than or equal to the given @p key,
	/// 															or an invalid iterator if this doesn't exist.
	//----------------------------------------------------------------------------------------
	ConstIterator FindFloor(K key) const
	{
		return const_cast<BurstTrieMap*>(this)->FindFloor(key);
	}

	//----------------------------------------------------------------------------------------
	/// Removes an entry with the given key from this map (if possible).
	/// @param[in] key								Key of the map entry to be be removed.
	/// @return												True if an entry was found and removed for #key, otherwise false.
	//----------------------------------------------------------------------------------------
	ResultOk<Bool> Erase(K key)
	{
#if 1
		Int rootPos = (UInt(SIZEOF(K) * 8 + GROUP_BITS - 1) - UInt(Clz(key))) / GROUP_BITS;
		Int pos = rootPos;
		Index i = _roots[pos];
		if (!i)
			return false;
		pos *= GROUP_BITS;
		Int depth = 0;
		Node* path[MAX_LEN];
		while (true)
		{
			if (Pool::IsNode(i))
			{
				Node* n = Pool::GetNode(i);
				DebugAssert(depth < MAX_LEN);
				path[depth++] = n;
				pos -= GROUP_BITS;
				DebugAssert(pos >= 0);
				i = n->children[(key >> pos) & GROUP_MASK];
				if (!i)
					return false;
			}
			else
			{
				Bucket* b = Pool::GetBucket(i);
				Int cnt = b->GetCount();
				Int index;
				if (!b->template Find<SORT>(key, cnt, index))
					return false;
				b->Remove(index, cnt, 1);
				--cnt;
				--_size;
				if (cnt == 0)
				{
					Pool::FreeBucket(i);
					if (depth == 0)
						_roots[rootPos] = 0;
					else
						path[depth - 1]->children[(key >> pos) & GROUP_MASK] = 0;
				}
				else
				{
					b->keys[BUCKET_SIZE - 1] = K(LIMIT<K>::MAX - BUCKET_SIZE + 1) + K(cnt);
				}
				while (--depth >= 0)
				{
					pos += GROUP_BITS;
					Node* n = path[depth];
					Int entries = 0;
					for (Index c : n->children)
					{
						if (c)
						{
							if (Pool::IsNode(c))
								return true;
							else
								entries += Pool::GetBucket(c)->GetCount();
						}
					}
					if (entries >= BUCKET_SIZE * 2 / 3)
						return true;
					b = nullptr;
					i = 0;
					for (Index c : n->children)
					{
						if (c)
						{
							Bucket* bc = Pool::GetBucket(c);
							if (!b)
							{
								b = bc;
								i = c;
								cnt = b->GetCount();
							}
							else
							{
								Int ccnt = bc->GetCount();
								for (Int j = 0; j < ccnt; ++j, ++cnt)
								{
									b->keys[cnt] = bc->keys[j];
									if (!std::is_empty<V>::value)
									{
										new (&b->GetValue(cnt)) V(std::move(bc->GetValue(j)));
										bc->GetValue(j).~V();
									}
								}
								Pool::FreeBucket(c);
							}
						}
					}
					DebugAssert(cnt == entries);
					if (b && (cnt != BUCKET_SIZE))
					{
						b->keys[BUCKET_SIZE - 1] = K(LIMIT<K>::MAX - BUCKET_SIZE + 1) + K(cnt);
					}
					Index& parentLink = (depth == 0) ? _roots[rootPos] : path[depth - 1]->children[(key >> pos) & GROUP_MASK];
					DebugAssert(Pool::IsNode(parentLink) && (Pool::GetNode(parentLink) == path[depth]));
					Pool::FreeNode(parentLink);
					parentLink = i;
				}
				return true;
			}
		}
#else
		Iterator it = Find(key);
		if (!it.IsValid())
			return true;
		it.Remove(1);
		return true;
#endif
	}

	//----------------------------------------------------------------------------------------
	/// Removes @p eraseCnt elements from this map starting at the position given by @p position.
	/// The returned iterator will point to the element behind the last removed element.
	/// @param[in] position						Iterator pointing to the first element to be removed.
	/// @param[in] eraseCnt						Number of elements to remove.
	/// @return												Iterator pointing to the element behind the last removed element.
	//----------------------------------------------------------------------------------------
	template <template <Bool> class SUPER> MAXON_WARN_UNUSED IteratorTemplate<false, SUPER> Erase(const IteratorTemplate<false, SUPER>& position, Int eraseCnt = 1)
	{
		IteratorTemplate<false, SUPER> it = position;
		it.Erase(*this, eraseCnt);
		return it;
	}

private:
	MAXON_DISALLOW_COPY_AND_ASSIGN(BurstTrieMap);

	friend Pool;

	void ClearRoots()
	{
		for (Index& r : _roots)
			r = 0;
	}

	Int GetDepthImpl(Index idx) const
	{
		if (Pool::IsNode(idx))
		{
			Int depth = 0;
			const Node* n = Pool::GetNode(idx);
			for (Index x : n->children)
			{
				if (x)
				{
					SetMax(depth, GetDepthImpl(x));
				}
			}
			return depth + 1;
		}
		else
		{
			return 0;
		}
	}

	Int GetMemorySizeImpl(Index idx) const
	{
		if (Pool::IsNode(idx))
		{
			Int sz = SIZEOF(Node);
			const Node* n = Pool::GetNode(idx);
			for (Index x : n->children)
			{
				if (x)
				{
					sz += GetMemorySizeImpl(x);
				}
			}
			return sz;
		}
		else
		{
			return Pool::GetBucket(idx)->GetMemorySize();
		}
	}

	void DestructNodes(Index idx)
	{
		if (Pool::IsNode(idx))
		{
			Node* n = Pool::GetNode(idx);
			for (Index x : n->children)
			{
				if (x)
				{
					DestructNodes(x);
				}
			}
			Pool::FreeNode(idx);
		}
		else
		{
			if (!std::is_empty<V>::value)
			{
				Bucket* b = Pool::GetBucket(idx);
				Int cnt = b->GetCount();
				for (Int i = 0; i < cnt; ++i)
				{
					b->GetValue(i).~V();
				}
			}
			Pool::FreeBucket(idx);
		}
	}

	Result<void> CopyNodes(Index& dest, const BurstTrieMap& srcMap, Index src)
	{
		if (srcMap.Pool::IsNode(src))
		{
			const Node* n = srcMap.Pool::GetNode(src);
			Node* d = MAXON_SAFE_PLACEMENT_NEW(Pool::AllocNode(dest)) Node();
			Index* di = d->children;
			for (Index x : n->children)
			{
				if (x)
				{
					Result<void> r = CopyNodes(*di, srcMap, x);
					if (r == FAILED)
						return r;
				}
				++di;
			}
		}
		else
		{
			const Bucket* b = srcMap.Pool::GetBucket(src);
			Bucket* d = (Bucket*) Pool::AllocBucket(dest);
			if (!d)
				return CreateError(MAXON_SOURCE_LOCATION, ERROR_TYPE::OUT_OF_MEMORY);
			for (Int i = 0; i < BUCKET_SIZE; ++i)
			{
				d->keys[i] = b->keys[i];
			}
			if (!std::is_empty<V>::value)
			{
				Int cnt = b->GetCount();
				for (Int i = 0; i < cnt; ++i)
				{
					new (&d->GetValue(i)) V();
				}
				for (Int i = 0; i < cnt; ++i)
				{
					Result<void> r = AssignCopy<V>(d->GetValue(i), b->GetValue(i));
					if (r == FAILED)
						return r;
				}
			}
		}
		return OK;
	}

	Index _roots[MAX_LEN + 1]; ///< Trie roots, indexed by the position of the highest non-zero group of the key.
	Int _size; ///< Total number of key-value entries.

	friend class BurstTrieMapUtils;
};


//----------------------------------------------------------------------------------------
/// This selector class is used for template parameters which select the map implementation
/// to use. It will then instruct the template to use the BurstTrieMap implementation.
/// For example, RangeSet by default uses an underlying BurstTrieMap with default settings. If you want to use
/// different settings, you'd write something like
/// @code
/// RangeSet<UInt, BurstTrieMapSelector<2, 4>> set;
/// @endcode
///
/// @tparam GROUP_BITS						Number of bits which shall be grouped to form an index into the children array of an inner node. This shouldn't exceed 4.
/// @tparam BUCKET_SIZE						Maximum size of a bucket of a leaf node. Reasonable values are between 4 and 40.
/// @tparam SORT									Mode for sorting of the buckets.
/// @tparam POOL									Memory pool for the nodes.
//----------------------------------------------------------------------------------------
template <Int GROUP_BITS = 4, Int BUCKET_SIZE = 16, BURSTTRIE_SORT SORT = BURSTTRIE_SORT::LINEAR_SEARCH, template <typename, typename> class POOL = PointerBurstTriePool> class BurstTrieMapSelector
{
public:
	template <typename K, typename V> using Type = BurstTrieMap<K, V, GROUP_BITS, BUCKET_SIZE, SORT, POOL>;
};


//----------------------------------------------------------------------------------------
/// A BurstTrieSet is an implementation of a set using an underlying BurstTrieMap. Like BurstTrieMap,
/// it only supports unsigned integral values. See BurstTrieMap for details about the internal structure and performance.
///
/// See HashSet for more examples on how to use sets in general.
///
/// @tparam T											Type of elements of the set.
/// @tparam GROUP_BITS						Number of bits which shall be grouped to form an index into the children array of an inner node. This shouldn't exceed 4.
/// @tparam BUCKET_SIZE						Maximum size of a bucket of a leaf node. Reasonable values are between 4 and 40.
/// @tparam SORT									Mode for sorting of the buckets.
/// @tparam POOL									Memory pool for the nodes.
/// @see BurstTrieMap
/// @see @$ref sets
//----------------------------------------------------------------------------------------
template <typename T, Int GROUP_BITS = 4, Int BUCKET_SIZE = 16, BURSTTRIE_SORT SORT = BURSTTRIE_SORT::LINEAR_SEARCH, template <typename, typename> class POOL = PointerBurstTriePool> class BurstTrieSet
	: public SetBase<BurstTrieSet<T, GROUP_BITS, BUCKET_SIZE, SORT, POOL>, T, Protected<BurstTrieMap<T, UnitType, GROUP_BITS, BUCKET_SIZE, SORT, POOL>>, DefaultCompare>
{
public:
	using MapType = BurstTrieMap<T, UnitType, GROUP_BITS, BUCKET_SIZE, SORT, POOL>;
	friend MapType;
private:
	using Super = SetBase<BurstTrieSet<T, GROUP_BITS, BUCKET_SIZE, SORT, POOL>, T, Protected<MapType>, DefaultCompare>;

	MAXON_DISALLOW_COPY_AND_ASSIGN(BurstTrieSet);

public:
	using MapType::Find;
	using MapType::GetCount;
	using MapType::GetOperationCountForSearch;
	using MapType::SetCapacityHint;
	using MapType::Reset;
	using MapType::Flush;
	using MapType::GetMemorySize;

	using IsBurstTrieMap = std::true_type;
	using IsBurstTrieSet = std::true_type;

	BurstTrieSet() : Super()
	{
	}

	BurstTrieSet(BurstTrieSet&& src) : Super(std::move(src))
	{
	}

	MAXON_OPERATOR_MOVE_ASSIGNMENT(BurstTrieSet);

	MapType& GetMap() { return *this; }
	const MapType& GetMap() const { return *this; }

	using Iterator = typename Super::KeyIterator;
	using ConstIterator = typename Super::ConstKeyIterator;

	//----------------------------------------------------------------------------------------
	/// Checks if this set contains @p value.
	/// @param[in] value							The value to check.
	/// @return												True if this set contains @p value.
	//----------------------------------------------------------------------------------------
	Bool Contains(T value) const
	{
		return Super::FindValue(value) != nullptr;
	}

	void Insert() const;

	//----------------------------------------------------------------------------------------
	/// Adds @p value to this set. If @p value is already contained in this set, nothing happens,
	/// and @p added is set to @c false.
	/// @param[in] value							Value to add to this set.
	/// @param[out] added							This will be set to true if the element didn't exist before in the set and it could be added successfully, otherwise it will be set to false.
	/// @return												Iterator to the entry for the given key or OutOfMemoryError if the allocation failed.
	//----------------------------------------------------------------------------------------
	ResultMemT<Iterator> Insert(T value, Bool& added = BoolLValue())
	{
		return std::move(static_cast<Iterator&>(Super::InsertEntry(value, added).GetValue()));
	}

	//----------------------------------------------------------------------------------------
	/// Adds @p value to this set. If @p value is already contained in this set, nothing happens,
	/// and @p added is set to @c false.
	/// @param[in] value							Value to add to this set.
	/// @param[out] added							This will be set to true if the element didn't exist before in the set and it could be added successfully, otherwise it will be set to false.
	/// @return												Pointer to the value in the set, or nullptr if the element had to be added, but the allocation failed.
	//----------------------------------------------------------------------------------------
	ResultRef<const T> InsertKey(T value, Bool& added = BoolLValue())
	{
		typename Super::Iterator it = Super::InsertEntry(value, added).GetValue();
		return it ? &it.GetKey() : nullptr;
	}

	//----------------------------------------------------------------------------------------
	/// Remove @p value from this set. If @p value isn't contained in this set, nothing happens.
	/// @param[in] value							Value to remove from this set.
	/// @return												Always true for a BurstTrieSet (even if key isn't contained in the set).
	/// @return												True if an entry was found and removed for #value, otherwise false.
	//----------------------------------------------------------------------------------------
	ResultOk<Bool> Erase(T value)
	{
		return Super::Erase(value);
	}

	ConstIterator Begin() const
	{
		return ConstIterator(*this);
	}

	ConstIterator End() const
	{
		return ConstIterator(*this, -1);
	}

	Iterator Begin()
	{
		return Iterator(*this);
	}

	Iterator End()
	{
		return Iterator(*this, -1);
	}

	Iterator Erase(const Iterator& it)
	{
		return Super::Erase(it);
	}
};


/// @}

} // namespace maxon

#endif // BURSTTRIEMAP_H__
