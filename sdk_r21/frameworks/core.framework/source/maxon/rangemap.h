#ifndef RANGEMAP_H__
#define RANGEMAP_H__

#include "maxon/bursttriemap.h"
#include "maxon/range.h"
#include "maxon/dataserialize.h"

namespace maxon
{

/// @addtogroup STRUCTURES
/// @{

// pair to use for a RangeSet (value doesn't matter)
template <typename K> struct RangeSetPair
{
	union
	{
		K first;
		UnitType second;
	};

	typename SFINAEHelper<String, K>::type ToString(const FormatStatement* fmt) const
	{
		return GlobalToString(first, fmt);
	}

	Bool operator ==(const RangeSetPair& other) const
	{
		return first == other.first && second == other.second;
	}

	UInt GetHashCode() const
	{
		CriticalStop();
		return 0;
	}

	static Result<void> DescribeIO(const DataSerializeInterface& stream)
	{
		iferr_scope;
		PrepareDescribe(stream, RangeSetPair);
		Describe("pair", first, K, maxon::DESCRIBEFLAGS::NONE) iferr_return;
		return OK;
	}
};


//----------------------------------------------------------------------------------------
/// Unlike a normal map, a RangeMap maps whole ranges (of integral values) to values.
/// For each contiguous range having the same value, only a single entry is needed, so a RangeMap
/// will perform much better than a normal map if it is likely that consecutive keys are mapped
/// to the same value.
/// @code
/// RangeMap<UInt, String> map;
/// if (!map.Insert(Range<UInt>(10, 40), "Alice"_s))
///   return false;
/// if (!map.Insert(Range<UInt>(30, 50), "Carol"_s))
///   return false;
/// if (!map.Erase(Range<UInt>(15, 25)))
///   return false;
/// @endcode
/// The above example results in a map with three entries: The range 10 ... 14 is mapped to "Alice"
/// as well as the range 26 ... 29, while the range 30 ... 50 is mapped to "Carol".
///
/// RangeMap ensures that its ranges don't overlap, and that directly adjacent ranges (with no gap
/// between them) which are mapped to the same value are merged to a single range.
///
/// RangeMap supports the usual iterators. They iterate through the map per range.
///
/// @tparam K											Type of keys. This must be an integral type.
/// @tparam V											Type of values.
/// @tparam MAP										A map selector template to choose the underlying map implementation to use. This has to be an ordered map.
/// 															Note that the default is the BurstTrieMap which only allows unsigned integral types.
//----------------------------------------------------------------------------------------
template <typename K, typename V, typename MAP = BurstTrieMapSelector<>> class RangeMap
{
public:
	using MapType = typename MAP::template Type<K, typename std::conditional<std::is_same<V, UnitType>::value, RangeSetPair<K>, Pair<K, V>>::type>;
	using Range = maxon::Range<K>;
	using ValueType = typename MapType::ValueType;
	using MapValue = typename MapType::ValueType;

	RangeMap() { }
	RangeMap(RangeMap&& src) : MAXON_MOVE_MEMBERS(_map) { }
	MAXON_OPERATOR_MOVE_ASSIGNMENT(RangeMap);

	//----------------------------------------------------------------------------------------
	/// Makes this map a copy of src.
	/// @param[in] src								Source from which the entries are taken.
	/// @return												True if copying succeeded.
	//----------------------------------------------------------------------------------------
	Result<void> CopyFrom(const RangeMap& src)
	{
		return _map.CopyFrom(src._map);
	}

	//----------------------------------------------------------------------------------------
	/// Flushes the map. This removes all entries. Depending on the underlying map, memory may
	/// still be held for later re-use.
	/// @see Reset()
	//----------------------------------------------------------------------------------------
	void Flush()
	{
		_map.Flush();
	}

	//----------------------------------------------------------------------------------------
	/// Resets the map. This removes all entries and frees any memory held by the map, so the map
	/// will be in a state as if it had been newly constructed.
	/// @see Flush()
	//----------------------------------------------------------------------------------------
	void Reset()
	{
		_map.Reset();
	}

	//----------------------------------------------------------------------------------------
	/// Returns the number of entries in this map. Each contiguous key range where the keys
	/// are mapped to the same value requires a single entry.
	/// @return												Number of entries.
	//----------------------------------------------------------------------------------------
	Int GetCount() const
	{
		return _map.GetCount();
	}

	//----------------------------------------------------------------------------------------
	/// Checks if the RangeMap is empty. This is the same as <tt>GetCount() == 0</tt>
	/// @return												True if this RangeMap does not contain any elements.
	//----------------------------------------------------------------------------------------
	Bool IsEmpty() const
	{
		return _map.IsEmpty();
	}

	//----------------------------------------------------------------------------------------
	/// Checks if the RangeMap is populated. This is the same as <tt>GetCount() != 0</tt>
	/// @return												True if this RangeMap contains any elements.
	//----------------------------------------------------------------------------------------
	Bool IsPopulated() const
	{
		return _map.IsPopulated();
	}

	//----------------------------------------------------------------------------------------
	/// Calculates the memory usage for this map.
	/// Keys and Values must have a public member GetMemorySize that return the element size.
	/// @return												Memory size in bytes.
	//----------------------------------------------------------------------------------------
	Int GetMemorySize() const
	{
		return _map.GetMemorySize();
	}

	//----------------------------------------------------------------------------------------
	/// Maps the range @p rMinValue ... @p rMaxValue to @p value.
	/// Existing overlapping mappings are truncated, split or removed as necessary, or they are
	/// merged with the new mapping if their values are equal.
	/// If the range is empty (@p rMaxValue is less than @p rMinValue), nothing happens.
	/// @param[in] rMinValue					Lower boundary of the range.
	/// @param[in] rMaxValue					Upper boundary of the range.
	/// @param[in] value							Value to which the range shall be mapped.
	/// @return												False if a memory allocation failed.
	//----------------------------------------------------------------------------------------
	ResultMem Insert(K rMinValue, K rMaxValue, const V& value)
	{
		if (rMinValue > rMaxValue)
			return OK;
		typename MapType::Iterator it = _map.FindFloor(rMinValue);
		typename MapType::Iterator begin;
		Bool changeFollowingKey = false;
		Int cnt = 0;
		if (it)
		{
			DebugAssert(it.GetKey() <= rMinValue);
			// there is an entry <= r.min
			if (it.GetValue().second == value)
			{
				// the entry maps to the same value
				if (it.GetValue().first + 1 < rMinValue)
				{
					// both ranges are isolated
					++it;
					goto addRange;
				}
				else
				{
					// merge both ranges
					if (rMaxValue <= it.GetValue().first)
					{
						// r already contained in existing range
						return OK;
					}
					else
					{
						// extend existing range
						goto extendRange;
					}
				}
			}
			else if (it.GetKey() < rMinValue)
			{
				if (rMaxValue < it.GetValue().first)
				{
					// r contained in range of it, isolated from its boundaries
					// the existing range of it has to be split
					MapValue itValue = it.GetValue();
					it.GetValue().first = rMinValue - 1;
					Bool created = false;
					MapValue* v = _map.InsertKey(rMinValue, created).GetPointer();
					if (!v)
						return FAILED;
					DebugAssert(created);
					v->first = rMaxValue;
					v->second = value;
					v = _map.InsertKey(rMaxValue + 1, created).GetPointer();
					if (!v)
						return FAILED;
					DebugAssert(created);
					*v = std::move(itValue);
					return OK;
				}
				else
				{
					// the found range has to be cut
					SetMin(it.GetValue().first, rMinValue - 1);
					++it;
					goto addRange;
				}
			}
			else
			{
				// r and it have the same minimum value
				// check if the range before it has to be merged with r
				if (it != _map.Begin())
				{
					begin = it;
					--begin;
					if ((begin.GetValue().first + 1 == rMinValue) && (begin.GetValue().second == value))
					{
						it = begin;
						goto extendRange;
					}
				}
				if (rMaxValue < it.GetValue().first)
				{
					// r is contained in it and ends before it
					MapValue itValue = std::move(it.GetValue());
					it.GetValue().first = rMaxValue;
					it.GetValue().second = value;
					Bool created = false;
					MapValue* v = _map.InsertKey(rMaxValue + 1, created).GetPointer();
					if (!v)
						return FAILED;
					DebugAssert(created);
					*v = std::move(itValue);
					return OK;
				}
				else
				{
					// r contains range of it
					it.GetValue().second = value;
					goto extendRange;
				}
			}

		extendRange:
			K& rangeMax = it.GetValue().first;
			rangeMax = rMaxValue;
			++it;
			begin = it;
			MapValue* last = nullptr;
			while (it && (it.GetKey() <= rMaxValue))
			{
				last = &it.GetValue();
				++it;
				++cnt;
			}
			if (last)
			{
				// r overlaps with existing ranges
				if (last->first <= rMaxValue)
				{
					// last overlapping range is completely contained in r
					if (it && (it.GetKey() == rMaxValue + 1) && (it.GetValue().second == value))
					{
						// merge with range of it
						rangeMax = it.GetValue().first;
						++cnt;
					}
				}
				else if (last->second == value)
				{
					// last overlapping range goes beyond r, but has same value
					// merge with last range
					rangeMax = last->first;
				}
				else
				{
					// last overlapping range goes beyond r and has different value
					changeFollowingKey = true;
					--cnt;
				}
			}
			else
			{
				// r doesn't overlap with existing ranges
				if (it && (it.GetKey() == rMaxValue + 1) && (it.GetValue().second == value))
				{
					// merge with range of it
					rangeMax = it.GetValue().first;
					DebugAssert(cnt == 0);
					cnt = 1;
				}
			}
			goto remove;
		}
		else
		{
			// r.min is less than minimum key of _map
			it = _map.Begin();
		}

	addRange:
		{
			DebugAssert(!it || (it.GetKey() > rMinValue));
			// it points to the first entry which is strictly above r.min, and the range before it doesn't overlap with r
			begin = it;
			MapValue* last = nullptr;
			while (it && (it.GetKey() <= rMaxValue))
			{
				last = &it.GetValue();
				++it;
				++cnt;
			}
			if (last)
			{
				// r overlaps with existing ranges
				if (last->first <= rMaxValue)
				{
					// last overlapping range is completely contained in r
					if (it && (it.GetKey() == rMaxValue + 1) && (it.GetValue().second == value))
					{
						// merge with range of it
						begin.GetValue().first = it.GetValue().first;
						++cnt;
					}
					else
					{
						begin.GetValue().first = rMaxValue;
					}
					begin.GetValue().second = value;
				}
				else if (last->second == value)
				{
					// last overlapping range goes beyond r, but has same value
					// merge with last range
					begin.GetValue() = std::move(*last);
				}
				else
				{
					// last overlapping range goes beyond r and has different value
					--cnt;
					if (cnt == 0)
					{
						Bool created = false;
						auto e = _map.InsertEntry(rMinValue, created);
						if (e == FAILED)
							return FAILED;
						begin = e.GetValue();
						DebugAssert(created);
					}
					begin.GetValue().first = rMaxValue;
					begin.GetValue().second = value;
					changeFollowingKey = true;
				}
			}
			else
			{
				// r doesn't overlap with existing ranges
				if (it && (it.GetKey() == rMaxValue + 1) && (it.GetValue().second == value))
				{
					// r can be merged with existing range
				}
				else
				{
					// create isolated range
					Bool created = false;
					MapValue* v = _map.InsertKey(rMinValue, created).GetPointer();
					if (!v)
						return FAILED;
					DebugAssert(created);
					v->first = rMaxValue;
					v->second = value;
					return OK;
				}
			}
			if (begin.ChangeKey(_map, rMinValue) == FAILED)
				return FAILED;
			++begin;
			--cnt;
		}

	remove:
		if (begin.Erase(_map, cnt) == FAILED)
			return FAILED;
		if (changeFollowingKey && (begin.ChangeKey(_map, rMaxValue + 1) == FAILED))
			return FAILED;
		return OK;
	}

	//----------------------------------------------------------------------------------------
	/// Maps the single value @p key (i.e., the range @p key ... @p key consisting of a single element) to @p value.
	/// Existing mappings which overlap @p key are truncated, split or removed as necessary, or they may
	/// be extended to include @p key if their values are equal.
	/// @param[in] key								A single key which shall be mapped.
	/// @param[in] value							Value to which the range shall be mapped.
	/// @return												False if a memory allocation failed.
	//----------------------------------------------------------------------------------------
	ResultMem Insert(K key, const V& value)
	{
		return Insert(key, key, value);
	}

	//----------------------------------------------------------------------------------------
	/// Maps the given @p range to @p value.
	/// Existing overlapping mappings are truncated, split or removed as necessary, or they are
	/// merged with the new mapping if their values are equal.
	/// If the range is empty, nothing happens.
	/// @param[in] range							Range which shall be mapped.
	/// @param[in] value							Value to which the range shall be mapped.
	/// @return												False if a memory allocation failed.
	//----------------------------------------------------------------------------------------
	ResultMem Insert(const Range& range, const V& value)
	{
		return Insert(range._minValue, range._maxValue, value);
	}

	//----------------------------------------------------------------------------------------
	/// Finds the value associated with the given @p key in this map. If there is a mapping for a range
	/// which contains @p key, the value of this mapping is returned, otherwise nullptr.
	/// @param[in] key								Key to search for.
	/// @return												Pointer to value for the given key, or nullptr if no entry exists for the key.
	//----------------------------------------------------------------------------------------
	const V* FindValue(K key) const
	{
		typename MapType::ConstIterator it = _map.FindFloor(key);
		if (!it)
			return nullptr;
		DebugAssert(it.GetKey() <= key);
		return (key <= it.GetValue().first) ? &it.GetValue().second : nullptr;
	}

	//----------------------------------------------------------------------------------------
	/// Finds the value associated with the given @p key in this map. If there is a mapping for a range
	/// which contains @p key, @p rangeOut is set to the range, and the value of the mapping is returned, otherwise nullptr.
	/// @param[in] key								Key to search for.
	/// @param[out] rangeOut					If a mapping is found, @p rangeOut is set to its range.
	/// @return												Pointer to value for the given key, or nullptr if no entry exists for the key.
	//----------------------------------------------------------------------------------------
	const V* FindRange(K key, Range& rangeOut) const
	{
		typename MapType::ConstIterator it = _map.FindFloor(key);
		if (!it)
			return nullptr;
		DebugAssert(it.GetKey() <= key);
		if (key > it.GetValue().first)
			return nullptr;
		rangeOut.Set(it.GetKey(), it.GetValue().first);
		return &it.GetValue().second;
	}

	//----------------------------------------------------------------------------------------
	/// Removes any mappings of values within the range @p rMinValue ... @p rMaxValue.
	/// Existing overlapping mappings are truncated, split or removed as necessary.
	/// @param[in] rMinValue					Lower boundary of the range.
	/// @param[in] rMaxValue					Upper boundary of the range.
	/// @return												False if a memory allocation failed.
	//----------------------------------------------------------------------------------------
	ResultMem Erase(K rMinValue, K rMaxValue)
	{
		if (rMinValue > rMaxValue)
			return OK;
		typename MapType::Iterator it = _map.FindFloor(rMinValue);
		typename MapType::Iterator begin;
		Bool changeFollowingKey = false;
		Int cnt = 0;
		if (it)
		{
			DebugAssert(it.GetKey() <= rMinValue);
			// there is an entry <= r.min
			if (it.GetKey() < rMinValue)
			{
				if (rMaxValue < it.GetValue().first)
				{
					// r contained in range of it, isolated from its boundaries
					// the existing range of it has to be split
					MapValue itValue = it.GetValue();
					it.GetValue().first = rMinValue - 1;
					Bool created = false;
					MapValue* v = _map.InsertKey(rMaxValue + 1, created).GetPointer();
					if (!v)
						return FAILED;
					DebugAssert(created);
					*v = std::move(itValue);
					return OK;
				}
				else
				{
					// the found range has to be cut
					SetMin(it.GetValue().first, rMinValue - 1);
					++it;
				}
			}
			else if (rMaxValue <= it.GetValue().first)
			{
				// r is contained in it
				if (rMaxValue < it.GetValue().first)
				{
					// r ends before the range of it
					return it.ChangeKey(_map, rMaxValue + 1);
				}
				else
				{
					// r is exactly the range of it
					return ResultMem(it.Erase(_map, 1) == OK);
				}
			}
			else
			{
				// r contains range of it
			}
		}
		else
		{
			// r.min is less than minimum key of _map
			it = _map.Begin();
		}

		begin = it;
		MapValue* last = nullptr;
		while (it && (it.GetKey() <= rMaxValue))
		{
			last = &it.GetValue();
			++it;
			++cnt;
		}
		if (last)
		{
			// r overlaps with existing ranges
			if (last->first <= rMaxValue)
			{
				// last overlapping range is completely contained in r
			}
			else
			{
				// last overlapping range goes beyond r and has different value
				changeFollowingKey = true;
				--cnt;
			}
			if (begin.Erase(_map, cnt) == FAILED)
				return FAILED;
			if (changeFollowingKey && (begin.ChangeKey(_map, rMaxValue + 1) == FAILED))
				return FAILED;
		}
		return OK;
	}

	//----------------------------------------------------------------------------------------
	/// Removes a mapping for the given @p key, if any.
	/// Existing overlapping mappings are truncated, split or removed as necessary.
	/// @param[in] key								Key which shall be unmapped.
	/// @return												False if a memory allocation failed.
	//----------------------------------------------------------------------------------------
	ResultMem Erase(K key)
	{
		return Erase(key, key);
	}

	//----------------------------------------------------------------------------------------
	/// Removes any mappings of values within the given @p range.
	/// Existing overlapping mappings are truncated, split or removed as necessary.
	/// @param[in] range							Range for which all mappings shall be removed.
	/// @return												False if a memory allocation failed.
	//----------------------------------------------------------------------------------------
	ResultMem Erase(const Range& range)
	{
		return Erase(range._minValue, range._maxValue);
	}

	typename SFINAEHelper<String, K>::type ToString(const FormatStatement* fmt) const
	{
		return _map.ToString(fmt);
	}

	template <Bool CONSTITERATOR> class EntryIteratorBase : public MapType::template EntryIteratorBase<CONSTITERATOR>
	{
	public:
		using CollectionType = typename ConstIf<RangeMap, CONSTITERATOR>::type;
		using Type = Pair<Range, const V&>;
		using Super = typename MapType::template EntryIteratorBase<CONSTITERATOR>;

		EntryIteratorBase() { }
		EntryIteratorBase(CollectionType& m, Int s) : Super(m._map, s) { }
		EntryIteratorBase(const EntryIteratorBase& src) : Super(src) { }

		Range GetKey() const
		{
			return Range(Super::GetKey(), Super::GetValue().first);
		}

		const V& GetValue() const
		{
			return Super::GetValue().second;
		}

		Type operator *() const
		{
			const auto& v = Super::GetValue();
			return Type(Range(Super::GetKey(), v.first), v.second);
		}
	};

	template <Bool CONSTITERATOR> class KeyIteratorBase : public MapType::template EntryIteratorBase<CONSTITERATOR>
	{
	public:
		using CollectionType = typename ConstIf<RangeMap, CONSTITERATOR>::type;
		using Super = typename MapType::template EntryIteratorBase<CONSTITERATOR>;

		KeyIteratorBase() { }
		KeyIteratorBase(CollectionType& m, Int s) : Super(m._map, s) { }
		KeyIteratorBase(const KeyIteratorBase& src) : Super(src) { }

		Range operator *() const
		{
			return Range(Super::GetKey(), Super::GetValue().first);
		}
	};

	template <Bool CONSTITERATOR> class ValueIteratorBase : public MapType::template EntryIteratorBase<CONSTITERATOR>
	{
	public:
		using CollectionType = typename ConstIf<RangeMap, CONSTITERATOR>::type;
		using Super = typename MapType::template EntryIteratorBase<CONSTITERATOR>;

		ValueIteratorBase() { }
		ValueIteratorBase(CollectionType& m, Int s) : Super(m._map, s) { }
		ValueIteratorBase(const ValueIteratorBase& src) : Super(src) { }

		const V& operator *() const
		{
			return Super::GetValue().second;
		}

		const V* operator ->() const
		{
			return &Super::GetValue().second;
		}
	};


	using Iterator = typename MapType::template IteratorTemplate<false, EntryIteratorBase>;
	using ConstIterator = typename MapType::template IteratorTemplate<true, EntryIteratorBase>;

	using KeyIterator = typename MapType::template IteratorTemplate<false, KeyIteratorBase>;
	using ConstKeyIterator = typename MapType::template IteratorTemplate<true, KeyIteratorBase>;

	using ValueIterator = typename MapType::template IteratorTemplate<false, ValueIteratorBase>;
	using ConstValueIterator = typename MapType::template IteratorTemplate<true, ValueIteratorBase>;

	//----------------------------------------------------------------------------------------
	/// Returns an iterator pointing to the first entry of this map.
	/// The iteration order corresponds to the order of the ranges.
	/// @return												Iterator for this map pointing to the first element.
	//----------------------------------------------------------------------------------------
	Iterator Begin()
	{
		return Iterator(*this);
	}

	//----------------------------------------------------------------------------------------
	/// Returns an iterator pointing just behind the last entry of this map.
	/// The iteration order corresponds to the order of the ranges.
	/// @return												Iterator for this map pointing behind the last element.
	//----------------------------------------------------------------------------------------
	Iterator End()
	{
		return Iterator(*this, -1);
	}

	//----------------------------------------------------------------------------------------
	/// Returns an iterator pointing to the first entry of this map.
	/// The iteration order corresponds to the order of the ranges.
	/// @return												Iterator for this map pointing to the first element.
	//----------------------------------------------------------------------------------------
	ConstIterator Begin() const
	{
		return ConstIterator(*this);
	}

	//----------------------------------------------------------------------------------------
	/// Returns an iterator pointing just behind the last entry of this map.
	/// The iteration order corresponds to the order of the ranges.
	/// @return												Iterator for this map pointing behind the last element.
	//----------------------------------------------------------------------------------------
	ConstIterator End() const
	{
		return ConstIterator(*this, -1);
	}

	//----------------------------------------------------------------------------------------
	/// Returns a foreach iterator to iterate over all keys (i.e., ranges) of this map.
	/// This will yield all ranges in ascending order.
	/// @return												Foreach iterator over all keys (i.e., ranges).
	//----------------------------------------------------------------------------------------
	KeyIterator GetKeys()
	{
		return KeyIterator(*this);
	}

	//----------------------------------------------------------------------------------------
	/// Returns a foreach iterator to iterate over all keys (i.e., ranges) of this map.
	/// This will yield all ranges in ascending order.
	/// @return												Foreach iterator over all keys (i.e., ranges).
	//----------------------------------------------------------------------------------------
	ConstKeyIterator GetKeys() const
	{
		return ConstKeyIterator(*this);
	}

	//----------------------------------------------------------------------------------------
	/// Returns a foreach iterator to iterate over all values of this map.
	/// This will yield all values in ascending order of the corresponding ranges.
	/// @return												Foreach iterator over all values.
	//----------------------------------------------------------------------------------------
	ValueIterator GetValues()
	{
		return ValueIterator(*this);
	}

	//----------------------------------------------------------------------------------------
	/// Returns a foreach iterator to iterate over all values of this map.
	/// This will yield all values in ascending order of the corresponding ranges.
	/// @return												Foreach iterator over all values.
	//----------------------------------------------------------------------------------------
	ConstValueIterator GetValues() const
	{
		return ConstValueIterator(*this);
	}

	const MapType& GetMap() const
	{
		return _map;
	}

	UInt GetHashCode() const
	{
		return _map.GetHashCode();
	}

	Bool operator ==(const RangeMap& other) const
	{
		return _map == other._map;
	}

	Bool operator !=(const RangeMap& other) const
	{
		return !this->operator ==(other);
	}

	const MapType& GetUnderlyingMap() const
	{
		return _map;
	}

	static Result<void> DescribeIO(const DataSerializeInterface& stream)
	{
		iferr_scope;
		PrepareDescribe(stream, RangeMap);
		Describe("_map", _map, MAXON_MACROARG_TYPE(Pair<typename MapType::KeyType, typename MapType::ValueType>), maxon::DESCRIBEFLAGS::TYPE_MAP) iferr_return;
		return OK;
	}

private:
	MAXON_DISALLOW_COPY_AND_ASSIGN(RangeMap);
	MapType _map; ///< The underlying map which maps each start of a range to a pair consisting of the end of the range and the mapped value.
};


//----------------------------------------------------------------------------------------
/// A RangeSet allows to add or remove a whole range of values to the set by a single operation
/// (and a single entry in the set). Therefore, it is very useful for, e.g., selection sets
/// where it is likely that contiguous ranges of indices are selected.
///
/// RangeSet is based on RangeMap, see there for more details.
///
/// RangeSet supports the usual iterators. They iterate through the map per range (not per each value of a range).
///
/// @tparam T											Type of keys. This must be an integral type.
/// @tparam MAP										A map selector template to choose the underlying map implementation to use. This has to be an ordered map.
/// 															Note that the default is the BurstTrieMap which only allows unsigned integral types.
//----------------------------------------------------------------------------------------
template <typename T, typename MAP = BurstTrieMapSelector<>> class RangeSet : private RangeMap<T, UnitType, MAP>
{
public:
	using Super = RangeMap<T, UnitType, MAP>;
	using Super::Reset;
	using Super::Flush;
	using Super::IsEmpty;
	using Super::IsPopulated;
	using Super::GetCount;
	using Super::GetMemorySize;
	using Super::ToString;
	using Super::GetHashCode;
	using Super::DescribeIO;

	Bool operator ==(const RangeSet& other) const { return Super::operator ==(other); }

	Bool operator !=(const RangeSet& other) const { return Super::operator !=(other); }

	RangeSet() { }
	RangeSet(RangeSet&& src) : Super(std::move(src)) { }
	MAXON_OPERATOR_MOVE_ASSIGNMENT(RangeSet);

	Result<void> CopyFrom(const RangeSet& src)
	{
		return Super::CopyFrom(src);
	}

	const Super& GetMap() const
	{
		return *this;
	}

	//----------------------------------------------------------------------------------------
	/// Adds the given @p value to this set.
	/// @param[in] value							Value to add.
	/// @return												False if a memory allocation failed.
	//----------------------------------------------------------------------------------------
	ResultMem Insert(T value)
	{
		return Super::Insert(value, value, UnitType());
	}

	//----------------------------------------------------------------------------------------
	/// Adds the range @p minValue ... @p maxValue to this set, i.e., all values within that
	/// range will be contained in this set afterwards. If @p minValue is greater
	/// than @p maxValue, nothing happens.
	/// @param[in] minValue						Lower boundary of the range to add.
	/// @param[in] maxValue						Upper boundary of the range to add.
	/// @return												False if a memory allocation failed.
	//----------------------------------------------------------------------------------------
	ResultMem Insert(T minValue, T maxValue)
	{
		return Super::Insert(minValue, maxValue, UnitType());
	}

	//----------------------------------------------------------------------------------------
	/// Adds the given @p range to this set, i.e., all values within that
	/// range will be contained in this set afterwards. If the range is empty, nothing happens.
	/// @param[in] range							The range to add.
	/// @return												False if a memory allocation failed.
	//----------------------------------------------------------------------------------------
	ResultMem Insert(const typename Super::Range& range)
	{
		return Super::Insert(range._minValue, range._maxValue, UnitType());
	}

	//----------------------------------------------------------------------------------------
	/// Removes a single value from this set.
	/// @param[in] value							Value to remove.
	/// @return												False if a memory allocation failed.
	//----------------------------------------------------------------------------------------
	ResultMem Erase(T value)
	{
		return Super::Erase(value, value);
	}

	//----------------------------------------------------------------------------------------
	/// Removes the range @p minValue ... @p maxValue from this set, i.e., all values within that
	/// range won't be contained in this set afterwards. If @p minValue is greater
	/// than @p maxValue, nothing happens.
	/// @param[in] minValue						Lower boundary of the range to remove.
	/// @param[in] maxValue						Upper boundary of the range to remove.
	/// @return												False if a memory allocation failed.
	//----------------------------------------------------------------------------------------
	ResultMem Erase(T minValue, T maxValue)
	{
		return Super::Erase(minValue, maxValue);
	}

	//----------------------------------------------------------------------------------------
	/// Removes the given @p range from this set, i.e., all values within that
	/// range won't be contained in this set afterwards. If the range is empty, nothing happens.
	/// @param[in] range							The range to remove.
	/// @return												False if a memory allocation failed.
	//----------------------------------------------------------------------------------------
	ResultMem Erase(const typename Super::Range& range)
	{
		return Super::Erase(range._minValue, range._maxValue);
	}

	//----------------------------------------------------------------------------------------
	/// Checks if this set contains @p value.
	/// @param[in] value							The value to check.
	/// @return												True if this set contains @p value.
	//----------------------------------------------------------------------------------------
	Bool Contains(T value) const
	{
		return Super::FindValue(value) != nullptr;
	}

	//----------------------------------------------------------------------------------------
	/// Checks if this set contains all values of the range @p minValue ... @p maxValue.
	/// @param[in] minValue						Lower boundary of the range to remove.
	/// @param[in] maxValue						Upper boundary of the range to remove.
	/// @return												True if this set contains all values of @p minValue ... @p maxValue.
	//----------------------------------------------------------------------------------------
	Bool Contains(T minValue, T maxValue)
	{
		typename Super::Range r;
		return Super::FindRange(minValue, r) && (maxValue <= r._maxValue);
	}

	//----------------------------------------------------------------------------------------
	/// Checks if this set contains all values of the given @p range, i.e., if @p range
	/// is a subset of this set.
	/// @param[in] range							The range to check.
	/// @return												True if this set contains all values of @p range.
	//----------------------------------------------------------------------------------------
	Bool Contains(const typename Super::Range& range)
	{
		typename Super::Range r;
		return Super::FindRange(range._minValue, r) && (range._maxValue <= r._maxValue);
	}

	//----------------------------------------------------------------------------------------
	/// Finds the contiguous range of values of this set which contains @p value.
	/// If such a range exists, @p rangeOut is set to the range and @c true is returned,
	/// otherwise @c false is returned.
	/// @param[in] value							The value to check.
	/// @param[out] rangeOut					If a range containing @p value is found, @p rangeOut is set to this range.
	/// @return												True if a range could be found.
	//----------------------------------------------------------------------------------------
	Bool FindRange(T value, typename Super::Range& rangeOut) const
	{
		return Super::FindRange(value, rangeOut) != nullptr;
	}

	using Iterator = typename Super::KeyIterator;
	using ConstIterator = typename Super::ConstKeyIterator;

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

private:
	MAXON_DISALLOW_COPY_AND_ASSIGN(RangeSet);
};

/// @}

} // namespace maxon

#endif // RANGEMAP_H__
