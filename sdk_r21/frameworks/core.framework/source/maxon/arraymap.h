#ifndef ARRAYMAP_H__
#define ARRAYMAP_H__

#include "maxon/basearray.h"
#include "maxon/sortedarray.h"
#include "maxon/bitmanipulation.h"

namespace maxon
{

/// @addtogroup STRUCTURES
/// @{

// the sorted array to use for the sorted case (ARRAY is an array selector template)
template <typename ARRAY, typename ENTRY, typename COMPARE> class ArrayMapSortedArray : public SortedArray<ArrayMapSortedArray<ARRAY, ENTRY, COMPARE>, typename ARRAY::template Type<ENTRY>>
{
public:
	using Super = SortedArray<ArrayMapSortedArray, typename ARRAY::template Type<ENTRY>>;
	ArrayMapSortedArray() { }
	ArrayMapSortedArray(ArrayMapSortedArray&& src) : Super(std::move(src)) { }
	MAXON_OPERATOR_MOVE_ASSIGNMENT(ArrayMapSortedArray);

	static Bool LessThan(const ENTRY& a, const ENTRY& b) { return COMPARE::LessThan(a.first, b.first); }
	static Bool IsEqual(const ENTRY& a, const ENTRY& b) { return COMPARE::IsEqual(a.first, b.first); }

	template <typename KEY> static Bool LessThan(const KEY& a, const ENTRY& b) { return COMPARE::LessThan(a, b.first); }
	template <typename KEY> static Bool IsEqual(const KEY& a, const ENTRY& b) { return COMPARE::IsEqual(a, b.first); }

	template <typename KEY> static Bool LessThan(const ENTRY& a, const KEY& b) { return COMPARE::LessThan(a.first, b); }

	using Super::GetHashCode;
	static UInt GetHashCode(const ENTRY& a) { return COMPARE::GetHashCode(a); }
};


// helper class for ArrayMap for the unsorted case
template <typename K, typename V, Bool SORTED, typename COMPARE, typename ARRAY> class ArrayMapHelper
{
public:
	using Entry = Pair<K, V>;

	using Array = typename ARRAY::template Type<Entry>; // use an unsorted array

	static ResultRef<Entry> Insert(Array& array, const K& key, Bool& created, Int& index)
	{
		created = false;
		Int i = 0;
		for (Entry& e : array)
		{
			if (COMPARE::IsEqual(e.GetKey(), key))
			{
				index = i;
				return &e;
			}
			++i;
		}
		ResultRef<Entry> v = array.Append();
		if (v == OK)
		{
			created = true;
			index = i;
		}
		return v;
	}

	static const Entry* Find(const Array& array, const K& key)
	{
		for (const Entry& v : array)
		{
			if (COMPARE::IsEqual(v.GetKey(), key))
			{
				return &v;
			}
		}
		return nullptr;
	}

	static Int FindIndex(const Array& array, const K& key)
	{
		for (Int i = 0, n = array.GetCount(); i < n; ++i)
		{
			if (COMPARE::IsEqual(array[i].GetKey(), key))
				return i;
		}
		return -1;
	}

	static Bool Erase(Array& array, const K& key)
	{
		for (auto it = Iterable::EraseIterator(array); it; ++it)
		{
			if (COMPARE::IsEqual(it->GetKey(), key))
			{
				it.Erase();
				return true;
			}
		}
		return false;
	}
};


// helper class for ArrayMap for the sorted case (where a SortedArray is used internally)
template <typename K, typename V, typename COMPARE, typename ARRAY> class ArrayMapHelper<K, V, true, COMPARE, ARRAY>
{
	using Entry = Pair<K, V>;
public:
	using Array = ArrayMapSortedArray<ARRAY, Entry, COMPARE>; // use a sorted array
	using IsSorted = std::true_type;

	static ResultRef<Entry> Insert(Array& array, const K& key, Bool& created, Int& index)
	{
		return array.InsertValue(key, created, &index).GetPointer();
	}

	template <typename KEY> static const Entry* Find(const Array& array, const KEY& key)
	{
		return array.FindValue(key);
	}

	static Int FindIndex(const Array& array, const K& key)
	{
		return array.FindIndex(key);
	}

	static Bool Erase(Array& array, const K& key)
	{
		return array.EraseKey(key);
	}
};

//----------------------------------------------------------------------------------------
/// An ArrayMap maps keys to values using an underlying array whose elements are key-value-pairs.
/// It may be either sorted or unsorted. For very small maps, unsorted array maps are generally faster.
/// For large maps (exceeding about 100 entries), you should consider using another implementation
/// such as HashMap or BurstTrieMap because especially insertion and erasure become slow with array maps:
/// For a sorted ArrayMap, those operations have a time cost of O(N), while searching has a time cost of O(log N).
///
/// Of all maps, the ArrayMap is the most efficient with respect to memory usage as it really only stores the key-value-pairs.
///
/// See HashMap for more examples on how to use maps in general.
///
/// @tparam K											Type of keys.
/// @tparam V											Type of values.
/// @tparam SORTED								Use true for a sorted array.
/// @tparam COMPARE								Class to be used to compare the keys.
/// @tparam ARRAY									An array selector template to choose the array implementation to use.
/// @see @$ref maps
//----------------------------------------------------------------------------------------
template <typename K, typename V, Bool SORTED = true, typename COMPARE = DefaultCompare, typename ARRAY = BaseArraySelector<>> class ArrayMap : public MapBase<ArrayMap<K, V, SORTED, COMPARE, ARRAY>, K, V, typename ArrayMapHelper<K, V, SORTED, COMPARE, ARRAY>::Array, COMPARE>
{
public:
	using IsArrayMap = std::true_type;
	using ArrayType = typename ArrayMapHelper<K, V, SORTED, COMPARE, ARRAY>::Array;
	using Super = MapBase<ArrayMap<K, V, SORTED, COMPARE, ARRAY>, K, V, ArrayType, COMPARE>;
	using Entry = Pair<K, V>;

	//----------------------------------------------------------------------------------------
	/// Iterator implementation for ArrayMap. Besides the usual iterator operations,
	/// ArrayMap iterators support the foreach protocol and Erase and ChangeKey functions.
	/// For a sorted ArrayMap, the iterator will point to the map entries in ascending order of the keys
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
			Super::operator ++();
			return *this;
		}

		IteratorTemplate& operator --()
		{
			--Super::GetIterator();
			return *this;
		}

		void operator ++(int)
		{
			Super::operator ++();
		}

		void operator --(int)
		{
			--Super::GetIterator();
		}
	};

	using IteratorBase = AutoIterator<const ArrayType>;

	class NonConstIteratorBase : public AutoIterator<ArrayType>
	{
	public:
		using Super = AutoIterator<ArrayType>;
		NonConstIteratorBase() { }
		NonConstIteratorBase(ArrayMap& m, Int s) : Super(m, s) { }
		NonConstIteratorBase(const NonConstIteratorBase& src) : Super(src) { }

		//----------------------------------------------------------------------------------------
		/// Removes @p eraseCnt elements from the map starting at the position given by this iterator.
		/// Afterwards, this iterator will point to the element behind the last removed element.
		/// @param[in] map								Map of this iterator.
		/// @param[in] eraseCnt						Number of elements to remove.
		/// @return												False if some allocation failed (for an ArrayMap, this is impossible, so this function will always return true).
		//----------------------------------------------------------------------------------------
		ResultOk<void> Erase(ArrayMap& map, Int eraseCnt = 1)
		{
			if (eraseCnt > 0)
			{
				this->_it = map.ArrayType::Erase(this->_it, eraseCnt);
				this->_end = map.ArrayType::End();
			}
			return OK;
		}

		//----------------------------------------------------------------------------------------
		/// Modifies the key of the map entry pointed to by this iterator.
		/// This operation is only supported by sorted array maps. The new key must be in a range
		/// such that this operation doesn't change the order, i.e., it must be above the
		/// key of the previous entry and below the key of the next entry.
		/// @param[in] map								Map of this iterator.
		/// @param[in] newKey							New value for the key of the current map entry.
		/// @return												False if some allocation failed (for an ArrayMap, this is impossible, so this function will always return true).
		//----------------------------------------------------------------------------------------
		ResultOk<void> ChangeKey(ArrayMap& map, const K& newKey)
		{
			static_assert(SORTED, "ChangeKey requires a sorted array map.");
			DebugAssert((this->GetIterator() == map.ArrayType::Begin()) || ArrayType::LessThan(*(this->GetIterator() - 1), newKey));
			DebugAssert((this->GetIterator() + 1 == map.ArrayType::End()) || ArrayType::LessThan(newKey, *(this->GetIterator() + 1)));
			K& k = (this->operator ->())->GetFirst();
			if (k != newKey)
			{
				k = newKey;
			}
			return OK;
		}
	};

	template <Bool CONSTITERATOR> class EntryIteratorBase : public std::conditional<CONSTITERATOR, IteratorBase, NonConstIteratorBase>::type
	{
	public:
		using Super = typename std::conditional<CONSTITERATOR, IteratorBase, NonConstIteratorBase>::type;
		using CollectionType = typename ConstIf<ArrayMap, CONSTITERATOR>::type;
		using KeyType = K;
		using MappedType = typename ConstIf<V, CONSTITERATOR>::type;

		EntryIteratorBase() { }
		EntryIteratorBase(CollectionType& m, Int s) : Super(m, (s < 0) ? m.GetCount() : s) { }
		EntryIteratorBase(const EntryIteratorBase& src) : Super(src) { }

		//----------------------------------------------------------------------------------------
		/// Returns the key of the current key-value-pair of this iterator.
		/// @return												Current key of this iterator.
		//----------------------------------------------------------------------------------------
		const K& GetKey() const
		{
			return (this->operator ->())->GetKey();
		}

		//----------------------------------------------------------------------------------------
		/// Returns the value of the current key-value-pair of this iterator.
		/// @return												Current value of this iterator.
		//----------------------------------------------------------------------------------------
		MappedType& GetValue() const
		{
			return (this->operator ->())->GetValue();
		}
	};

	template <Bool CONSTITERATOR> class KeyIteratorBase : public EntryIteratorBase<CONSTITERATOR>
	{
	public:
		using Super = EntryIteratorBase<CONSTITERATOR>;

		KeyIteratorBase() { }
		KeyIteratorBase(typename Super::CollectionType& m, Int s) : Super(m, s) { }
		KeyIteratorBase(const KeyIteratorBase& src) : Super(src) { }

		const K* operator ->() const
		{
			return &this->GetKey();
		}

		const K& operator *() const
		{
			return this->GetKey();
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

		Type* operator ->() const
		{
			return &this->GetValue();
		}

		Type& operator *() const
		{
			return this->GetValue();
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
	/// For a sorted map, the iteration order corresponds to the order of the keys.
	/// @return												Iterator for this map pointing to the first element.
	//----------------------------------------------------------------------------------------
	Iterator Begin()
	{
		return Iterator(*this);
	}

	//----------------------------------------------------------------------------------------
	/// Returns an iterator pointing just behind the last entry of this map.
	/// For a sorted map, the iteration order corresponds to the order of the keys.
	/// @return												Iterator for this map pointing behind the last element.
	//----------------------------------------------------------------------------------------
	Iterator End()
	{
		return Iterator(*this, ArrayType::GetCount());
	}

	//----------------------------------------------------------------------------------------
	/// Returns an iterator pointing to the first entry of this map.
	/// For a sorted map, the iteration order corresponds to the order of the keys.
	/// @return												Iterator for this map pointing to the first element.
	//----------------------------------------------------------------------------------------
	ConstIterator Begin() const
	{
		return ConstIterator(*this);
	}

	//----------------------------------------------------------------------------------------
	/// Returns an iterator pointing just behind the last entry of this map.
	/// For a sorted map, the iteration order corresponds to the order of the keys.
	/// @return												Iterator for this map pointing behind the last element.
	//----------------------------------------------------------------------------------------
	ConstIterator End() const
	{
		return ConstIterator(*this, ArrayType::GetCount());
	}

	//----------------------------------------------------------------------------------------
	/// Returns a foreach iterator to iterate over all keys of this map.
	/// For a sorted map, this will yield all keys in ascending order.
	/// @return												Foreach iterator over all keys.
	//----------------------------------------------------------------------------------------
	KeyIterator GetKeys()
	{
		return KeyIterator(*this);
	}

	//----------------------------------------------------------------------------------------
	/// Returns a foreach iterator to iterate over all keys of this map.
	/// For a sorted map, this will yield all keys in ascending order.
	/// @return												Foreach iterator over all keys.
	//----------------------------------------------------------------------------------------
	ConstKeyIterator GetKeys() const
	{
		return ConstKeyIterator(*this);
	}

	//----------------------------------------------------------------------------------------
	/// Returns a foreach iterator to iterate over all values of this map.
	/// For a sorted map, this will yield all values in ascending order of the corresponding keys.
	/// @return												Foreach iterator over all values.
	//----------------------------------------------------------------------------------------
	ValueIterator GetValues()
	{
		return ValueIterator(*this);
	}

	//----------------------------------------------------------------------------------------
	/// Returns a foreach iterator to iterate over all values of this map.
	/// For a sorted map, this will yield all values in ascending order of the corresponding keys.
	/// @return												Foreach iterator over all values.
	//----------------------------------------------------------------------------------------
	ConstValueIterator GetValues() const
	{
		return ConstValueIterator(*this);
	}

	ArrayMap() : Super() { }
	ArrayMap(ArrayMap&& src) : Super(std::move(src)) { }
	MAXON_OPERATOR_MOVE_ASSIGNMENT(ArrayMap);

	using Super::IsEqualImpl;

	template <typename MAP, typename CMP> typename SFINAEHelper<Bool, typename MAP::IsArrayMap, typename MAP::IsSorted, typename std::enable_if<std::is_same<typename std::decay<CMP>::type, DefaultCompare>::value>::type>::type IsEqualImpl(const MAP& b, CMP&& cmp, OverloadRank1) const
	{
		Int n = this->GetCount();
		if (n != b.GetCount())
		{
			return false;
		}
		for (Int i = 0; i < n; ++i)
		{
			if (this->operator [](i) != b.operator [](i))
				return false;
		}
		return true;
	}

	//----------------------------------------------------------------------------------------
	/// Returns an estimate of the number of operations needed to locate a given key in this map.
	/// This is used when two collections are compared: The iteration goes over the collection which would require
	/// more operations for search, and each entry is searched in the other collection.
	/// @return												Estimate for the number of operations.
	//----------------------------------------------------------------------------------------
	Int GetOperationCountForSearch() const
	{
		// O(log N) in the sorted case, otherwise O(N).
		Int cnt = this->GetCount();
		return SORTED ? (SIZEOF(Int) * 8 - Clz<Int>(cnt)) : cnt;
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
		Int index;
		ResultRef<Entry> v = ArrayMapHelper<K, V, SORTED, COMPARE, ARRAY>::Insert(*this, key, created, index);
		if (v == FAILED)
			return nullptr;
		if (created)
		{
			if (AssignCopy(v.GetValue().first, key) == FAILED)
				return nullptr;
		}
		return &std::move(v.GetValue()).GetValue();
	}

	//----------------------------------------------------------------------------------------
	/// Finds the value associated with the given key, or creates a corresponding entry if it doesn't exist yet.
	/// The value of a new entry has to be initialized afterwards (but its default constructor has already been invoked).
	/// @param[in] key								Key of the value to find or create.
	/// @param[out] created						This will be set to true if a new entry has been created successfully, otherwise it will be set to false.
	/// @return												Pointer to value for the given key, or nullptr if an entry didn't exist and allocation of a new entry failed.
	//----------------------------------------------------------------------------------------
	ResultRef<V> InsertKey(K&& key, Bool& created = BoolLValue())
	{
		Int index;
		ResultRef<Entry> v = ArrayMapHelper<K, V, SORTED, COMPARE, ARRAY>::Insert(*this, key, created, index);
		if (v == FAILED)
			return nullptr;
		if (created)
		{
			v.GetValue().first = std::move(key);
		}
		return &std::move(v.GetValue()).GetValue();
	}

	//----------------------------------------------------------------------------------------
	/// Finds the entry with the given key, or creates such an entry if it doesn't exist yet,
	/// and returns an iterator pointing to the entry.
	/// The value of a new entry has to be initialized afterwards (but its default constructor has already been invoked).
	/// @param[in] key								Key of the entry to find or create.
	/// @param[out] created						This will be set to true if a new entry has been created successfully, otherwise it will be set to false.
	/// @return												Iterator to the entry for the given key or OutOfMemoryError if the allocation failed.
	//----------------------------------------------------------------------------------------
	ResultMemT<Iterator> InsertEntry(const K& key, Bool& created = BoolLValue())
	{
		Int index;
		ResultRef<Entry> v = ArrayMapHelper<K, V, SORTED, COMPARE, ARRAY>::Insert(*this, key, created, index);
		if (v == FAILED)
			return FAILED;
		if (created)
		{
			if (AssignCopy(v.GetValue().first, key) == FAILED)
				return FAILED;
		}
		return Iterator(*this, index);
	}

	//----------------------------------------------------------------------------------------
	/// Finds the entry with the given key, or creates such an entry if it doesn't exist yet,
	/// and returns an iterator pointing to the entry.
	/// The value of a new entry has to be initialized afterwards (but its default constructor has already been invoked).
	/// @param[in] key								Key of the entry to find or create. If a new entry is created, its key will be constructed by move-semantics if possible.
	/// @param[out] created						This will be set to true if a new entry has been created successfully, otherwise it will be set to false.
	/// @return												Iterator to the entry for the given key or OutOfMemoryError if the allocation failed.
	//----------------------------------------------------------------------------------------
	ResultMemT<Iterator> InsertEntry(K&& key, Bool& created = BoolLValue())
	{
		Int index;
		ResultRef<Entry> v = ArrayMapHelper<K, V, SORTED, COMPARE, ARRAY>::Insert(*this, key, created, index);
		if (v == FAILED)
			return FAILED;
		if (created)
		{
			v.GetValue().first = std::move(key);
		}
		return Iterator(*this, index);
	}

	//----------------------------------------------------------------------------------------
	/// Finds the entry with the given key, or creates such an entry if it doesn't exist yet,
	/// and returns an iterator pointing to the entry.
	/// The value of the entry will be set to @p value in any case.
	/// @param[in] key								Key of the entry to find or create.
	/// @param[in] value							This will be copied to the value of the entry.
	/// @param[out] created						This will be set to true if a new entry has been created successfully, otherwise it will be set to false.
	/// @return												Iterator to the entry for the given key or OutOfMemoryError if the allocation failed.
	//----------------------------------------------------------------------------------------
	ResultMemT<Iterator> Insert(const K& key, const V& value, Bool& created = BoolLValue())
	{
		Int index;
		ResultRef<Entry> v = ArrayMapHelper<K, V, SORTED, COMPARE, ARRAY>::Insert(*this, key, created, index);
		if (v == FAILED)
			return FAILED;
		if (created)
		{
			if (AssignCopy(v.GetValue().first, key) == FAILED)
				return FAILED;
		}
		if (AssignCopy(v.GetValue().second, value) == FAILED)
			return FAILED;
		return Iterator(*this, index);
	}

	//----------------------------------------------------------------------------------------
	/// Finds the entry with the given key, or creates such an entry if it doesn't exist yet,
	/// and returns an iterator pointing to the entry.
	/// The value of the entry will be set to @p value in any case.
	/// @param[in] key								Key of the entry to find or create. If a new entry is created, its key will be constructed by move-semantics if possible.
	/// @param[in] value							This will be copied to the value of the entry.
	/// @param[out] created						This will be set to true if a new entry has been created successfully, otherwise it will be set to false.
	/// @return												Iterator to the entry for the given key or OutOfMemoryError if the allocation failed.
	//----------------------------------------------------------------------------------------
	ResultMemT<Iterator> Insert(K&& key, const V& value, Bool& created = BoolLValue())
	{
		Int index;
		ResultRef<Entry> v = ArrayMapHelper<K, V, SORTED, COMPARE, ARRAY>::Insert(*this, key, created, index);
		if (v == FAILED)
			return FAILED;
		if (created)
			v.GetValue().first = std::move(key);
		if (AssignCopy(v.GetValue().second, value) == FAILED)
			return FAILED;
		return Iterator(*this, index);
	}

	//----------------------------------------------------------------------------------------
	/// Finds the entry with the given key, or creates such an entry if it doesn't exist yet,
	/// and returns an iterator pointing to the entry.
	/// The value of the entry will be set to @p value in any case.
	/// @param[in] key								Key of the entry to find or create.
	/// @param[in] value							This will be moved to the value of the entry.
	/// @param[out] created						This will be set to true if a new entry has been created successfully, otherwise it will be set to false.
	/// @return												Iterator to the entry for the given key or OutOfMemoryError if the allocation failed.
	//----------------------------------------------------------------------------------------
	ResultMemT<Iterator> Insert(const K& key, V&& value, Bool& created = BoolLValue())
	{
		Int index;
		ResultRef<Entry> v = ArrayMapHelper<K, V, SORTED, COMPARE, ARRAY>::Insert(*this, key, created, index);
		if (v == FAILED)
			return FAILED;
		if (created)
		{
			if (AssignCopy(v.GetValue().first, key) == FAILED)
				return FAILED;
		}
		v.GetValue().second = std::move(value);
		return Iterator(*this, index);
	}

	//----------------------------------------------------------------------------------------
	/// Finds the entry with the given key, or creates such an entry if it doesn't exist yet,
	/// and returns an iterator pointing to the entry.
	/// The value of the entry will be set to @p value in any case.
	/// @param[in] key								Key of the entry to find or create. If a new entry is created, its key will be constructed by move-semantics if possible.
	/// @param[in] value							This will be moved to the value of the entry.
	/// @param[out] created						This will be set to true if a new entry has been created successfully, otherwise it will be set to false.
	/// @return												Iterator to the entry for the given key or OutOfMemoryError if the allocation failed.
	//----------------------------------------------------------------------------------------
	ResultMemT<Iterator> Insert(K&& key, V&& value, Bool& created = BoolLValue())
	{
		Int index;
		ResultRef<Entry> v = ArrayMapHelper<K, V, SORTED, COMPARE, ARRAY>::Insert(*this, key, created, index);
		if (v == FAILED)
			return FAILED;
		if (created)
			v.GetValue().first = std::move(key);
		v.GetValue().second = std::move(value);
		return Iterator(*this, index);
	}

	//----------------------------------------------------------------------------------------
	/// Finds the value associated with the given key in this map.
	/// @param[in] key								Key to search for.
	/// @return												Pointer to value for the given key, or nullptr if no entry exists for the key.
	//----------------------------------------------------------------------------------------
	template <typename KEYCOMPARE = COMPARE, typename KEY> const V* FindValue(const KEY& key) const
	{
		const Entry* v = ArrayMapHelper<K, V, SORTED, KEYCOMPARE, ARRAY>::Find(*this, key);
		return v ? &v->GetValue() : nullptr;
	}

	//----------------------------------------------------------------------------------------
	/// Finds the value associated with the given key in this map.
	/// @param[in] key								Key to search for.
	/// @return												Pointer to value for the given key, or nullptr if no entry exists for the key.
	//----------------------------------------------------------------------------------------
	template <typename KEYCOMPARE = COMPARE, typename KEY> V* FindValue(const KEY& key)
	{
		return MAXON_NONCONST_COUNTERPART(FindValue(key));
	}

	//----------------------------------------------------------------------------------------
	/// Finds the entry for the given key in this map.
	/// @param[in] key								Key to search for.
	/// @return												Iterator pointing to the entry with the given @p key,
	/// 															or an invalid iterator if this doesn't exist.
	//----------------------------------------------------------------------------------------
	Iterator Find(const K& key)
	{
		Int index = ArrayMapHelper<K, V, SORTED, COMPARE, ARRAY>::FindIndex(*this, key);
		return (index < 0) ? Iterator() : Iterator(*this, index);
	}

	//----------------------------------------------------------------------------------------
	/// Finds the entry for the given key in this map.
	/// @param[in] key								Key to search for.
	/// @return												Iterator pointing to the entry with the given @p key,
	/// 															or an invalid iterator if this doesn't exist.
	//----------------------------------------------------------------------------------------
	ConstIterator Find(const K& key) const
	{
		Int index = ArrayMapHelper<K, V, SORTED, COMPARE, ARRAY>::FindIndex(*this, key);
		return (index < 0) ? ConstIterator() : ConstIterator(*this, index);
	}

	//----------------------------------------------------------------------------------------
	/// Finds the entry with the greatest key less than or equal to the given @p key.
	/// If no such entry exists, the returned iterator will be invalid (its <tt>operator Bool</tt> will return false).
	/// This function is only supported by sorted array maps.
	/// @param[in] key								Key to search for.
	/// @return												Iterator pointing to the entry with greatest key less than or equal to the given @p key,
	/// 															or an invalid iterator if this doesn't exist.
	//----------------------------------------------------------------------------------------
	Iterator FindFloor(const K& key)
	{
		static_assert(SORTED, "FindFloor requires a sorted array map.");
		Int index = ArrayMapHelper<K, V, SORTED, COMPARE, ARRAY>::FindIndex(*this, key);
		return (index == -1) ? Iterator() : Iterator(*this, (index < 0) ? -2 - index : index);
	}

	//----------------------------------------------------------------------------------------
	/// Finds the entry with the greatest key less than or equal to the given @p key.
	/// If no such entry exists, the returned iterator will be invalid (its <tt>operator Bool</tt> will return false).
	/// This function is only supported by sorted array maps.
	/// @param[in] key								Key to search for.
	/// @return												Iterator pointing to the entry with greatest key less than or equal to the given @p key,
	/// 															or an invalid iterator if this doesn't exist.
	//----------------------------------------------------------------------------------------
	ConstIterator FindFloor(const K& key) const
	{
		static_assert(SORTED, "FindFloor requires a sorted array map.");
		Int index = ArrayMapHelper<K, V, SORTED, COMPARE, ARRAY>::FindIndex(*this, key);
		return (index == -1) ? ConstIterator() : ConstIterator(*this, (index < 0) ? -2 - index : index);
	}

	//----------------------------------------------------------------------------------------
	/// Finds the entry with the smallest key greater than or equal to the given @p key.
	/// If no such entry exists, the returned iterator will be invalid (its <tt>operator Bool</tt> will return false).
	/// This function is only supported by sorted array maps.
	/// @param[in] key								Key to search for.
	/// @return												Iterator pointing to the entry with smallest key greater than or equal to the given @p key,
	/// 															or an invalid iterator if this doesn't exist.
	//----------------------------------------------------------------------------------------
	Iterator FindCeiling(const K& key)
	{
		static_assert(SORTED, "FindCeiling requires a sorted array map.");
		Int index = ArrayMapHelper<K, V, SORTED, COMPARE, ARRAY>::FindIndex(*this, key);
		return (index == this->GetCount()) ? Iterator() : Iterator(*this, (index < 0) ? ~index : index);
	}

	//----------------------------------------------------------------------------------------
	/// Finds the entry with the smallest key greater than or equal to the given @p key.
	/// If no such entry exists, the returned iterator will be invalid (its <tt>operator Bool</tt> will return false).
	/// This function is only supported by sorted array maps.
	/// @param[in] key								Key to search for.
	/// @return												Iterator pointing to the entry with smallest key greater than or equal to the given @p key,
	/// 															or an invalid iterator if this doesn't exist.
	//----------------------------------------------------------------------------------------
	ConstIterator FindCeiling(const K& key) const
	{
		static_assert(SORTED, "FindCeiling requires a sorted array map.");
		Int index = ArrayMapHelper<K, V, SORTED, COMPARE, ARRAY>::FindIndex(*this, key);
		return (index == this->GetCount()) ? ConstIterator() : ConstIterator(*this, (index < 0) ? ~index : index);
	}

	//----------------------------------------------------------------------------------------
	/// Removes an entry with the given key from this map (if possible).
	/// @param[in] key								Key of the map entry to be be removed.
	/// @return												True if an entry was found and removed for #key, otherwise false.
	//----------------------------------------------------------------------------------------
	ResultOk<Bool> Erase(const K& key)
	{
		return ArrayMapHelper<K, V, SORTED, COMPARE, ARRAY>::Erase(*this, key);
	}

	//----------------------------------------------------------------------------------------
	/// Removes @p eraseCnt elements from this map starting at the position given by @p position.
	/// The returned iterator will point to the element behind the last removed element.
	/// @param[in] position						Iterator pointing to the first element to be removed.
	/// @param[in] eraseCnt						Number of elements to remove.
	/// @return												Iterator pointing to the element behind the last removed element.
	//----------------------------------------------------------------------------------------
	template <template <Bool> class SUPER> IteratorTemplate<false, SUPER> Erase(const IteratorTemplate<false, SUPER>& position, Int eraseCnt = 1)
	{
		IteratorTemplate<false, SUPER> it = position;
		it.Erase(*this, eraseCnt);
		return it;
	}

	const ArrayType& GetUnderlyingArray() const
	{
		return *this;
	}

	ArrayType& GetUnderlyingArray()
	{
		return *this;
	}
};


//----------------------------------------------------------------------------------------
/// This selector class is used for template parameters which select the map implementation
/// to use. It will then instruct the template to use the ArrayMap implementation.
/// For example, RangeSet uses an underlying BurstTrieMap by default. If you want to use
/// an ArrayMap instead, you'd write
/// @code
/// RangeSet<Int, ArrayMapSelector<>> set;
/// @endcode
///
/// @tparam SORTED								Shall a sorted array map be selected?
/// @tparam COMPARE								Class to be used to compare the keys.
/// @tparam ARRAY									Selector for the array implementation that this map shall use.
//----------------------------------------------------------------------------------------
template <Bool SORTED = true, typename COMPARE = DefaultCompare, typename ARRAY = BaseArraySelector<>> class ArrayMapSelector
{
public:
	template <typename K, typename V> using Type = ArrayMap<K, V, SORTED, COMPARE, ARRAY>;
};


//----------------------------------------------------------------------------------------
/// An ArraySet is an implementation of a set using an underlying array. An element is in
/// the set if it is in the array. ArraySet is based on ArrayMap and takes care of not inserting an element twice
/// in the array. Like ArrayMap, ArraySet may be either sorted or unsorted. For very small sets, unsorted array sets are generally faster.
/// For large sets (exceeding about 100 entries), you should consider using another implementation
/// such as HashSet or BurstTrieSet because especially insertion and erasure become slow with array sets:
/// For a sorted ArraySet, those operations have a time cost of O(N), while searching has a time cost of O(log N).
///
/// Of all sets, the ArraySet is the most efficient with respect to memory usage as it really only stores the contained values.
///
/// See HashSet for more examples on how to use sets in general.
///
/// @tparam T											Type of elements of the set.
/// @tparam SORTED								Use true for a sorted array.
/// @tparam COMPARE								Class to be used to compare the values.
/// @tparam ARRAY									An array selector template to choose the array implementation to use.
/// @see ArrayMap
/// @see @$ref sets
//----------------------------------------------------------------------------------------
template <typename T, Bool SORTED = true, typename COMPARE = DefaultCompare, typename ARRAY = BaseArraySelector<>> class ArraySet
	: public SetBase<ArraySet<T, SORTED, COMPARE, ARRAY>, T, Protected<ArrayMap<T, UnitType, SORTED, COMPARE, ARRAY>>, COMPARE>
{
public:
	using MapType = ArrayMap<T, UnitType, SORTED, COMPARE, ARRAY>;
private:
	using Super = SetBase<ArraySet<T, SORTED, COMPARE, ARRAY>, T, Protected<MapType>, COMPARE>;

	MAXON_DISALLOW_COPY_AND_ASSIGN(ArraySet);

public:
	using MapType::Find;
	using MapType::FindFloor;
	using MapType::FindCeiling;
	using MapType::GetCount;
	using MapType::GetOperationCountForSearch;
	using MapType::SetCapacityHint;
	using MapType::Reset;
	using MapType::Flush;
	using MapType::GetMemorySize;

	using IsArrayMap = std::true_type;
	using IsArraySet = std::true_type;


	ArraySet() : Super()
	{
	}

	ArraySet(ArraySet&& src) : Super(std::move(src))
	{
	}

	MAXON_OPERATOR_MOVE_ASSIGNMENT(ArraySet);

	MapType& GetMap() { return *this; }
	const MapType& GetMap() const { return *this; }

	using Iterator = typename Super::KeyIterator;
	using ConstIterator = typename Super::ConstKeyIterator;

	//----------------------------------------------------------------------------------------
	/// Checks if this set contains @p value.
	/// @param[in] value							The value to check.
	/// @return												True if this set contains @p value.
	//----------------------------------------------------------------------------------------
	Bool Contains(typename ByValueParam<T>::type value) const
	{
		return Super::FindValue(value) != nullptr;
	}

	//----------------------------------------------------------------------------------------
	/// Adds @p value to this set. If @p value is already contained in this set, nothing happens,
	/// and @p added is set to @c false.
	/// @param[in] value							Value to add to this set.
	/// @param[out] added							This will be set to true if the element didn't exist before in the set and it could be added successfully, otherwise it will be set to false.
	/// @return												Iterator to the entry for the given key or OutOfMemoryError if the allocation failed.
	//----------------------------------------------------------------------------------------
	ResultMemT<Iterator> Insert(const T& value, Bool& added = BoolLValue())
	{
		return std::move(static_cast<Iterator&>(std::move(Super::InsertEntry(value, added).GetValue())));
	}

	//----------------------------------------------------------------------------------------
	/// Adds @p value to this set. If @p value is already contained in this set, nothing happens,
	/// and @p added is set to @c false.
	/// @param[in] value							Value to add to this set. When a new element has to be added, @p value will be moved into the new element.
	/// @param[out] added							This will be set to true if the element didn't exist before in the set and it could be added successfully, otherwise it will be set to false.
	/// @return												Iterator to the entry for the given key or OutOfMemoryError if the allocation failed.
	//----------------------------------------------------------------------------------------
	ResultMemT<Iterator> Insert(T&& value, Bool& added = BoolLValue())
	{
		return std::move(static_cast<Iterator&>(std::move(Super::InsertEntry(std::move(value), added).GetValue())));
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
		typename Super::Iterator it = std::move(Super::InsertEntry(value, added).GetValue());
		return it ? &it.GetKey() : nullptr;
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
		typename Super::Iterator it = std::move(Super::InsertEntry(std::move(value), added).GetValue());
		return it ? &it.GetKey() : nullptr;
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

	ConstIterator Begin() const
	{
		return ConstIterator(*this);
	}

	ConstIterator End() const
	{
		return ConstIterator(*this, this->GetCount());
	}

	Iterator Begin()
	{
		return Iterator(*this);
	}

	Iterator End()
	{
		return Iterator(*this, this->GetCount());
	}

	Iterator Erase(const Iterator& it)
	{
		return Super::Erase(it);
	}

	const typename ARRAY::template Type<T>& GetUnderlyingArray() const
	{
		return reinterpret_cast<const typename ARRAY::template Type<T>&>(MapType::GetUnderlyingArray());
	}

	typename ARRAY::template Type<T>& GetUnderlyingArray()
	{
		return reinterpret_cast<typename ARRAY::template Type<T>&>(MapType::GetUnderlyingArray());
	}
};

/// @}

} // namespace maxon

#endif // ARRAYMAP_H__
