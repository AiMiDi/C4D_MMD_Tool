#ifndef CONTIGUOUSRANGEMAP_H__
#define CONTIGUOUSRANGEMAP_H__

#include "maxon/bursttriemap.h"
#include "maxon/range.h"

namespace maxon
{

/// @addtogroup STRUCTURES
/// @{


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
template <typename K, typename V, typename MAP = BurstTrieMapSelector<>> class ContiguousRangeMap
{
public:
	using MapType = typename MAP::template Type<K, V>;
	using Range = maxon::Range<K>;
	using ValueType = typename MapType::ValueType;
	using MapValue = typename MapType::ValueType;

	ContiguousRangeMap() { }
	ContiguousRangeMap(ContiguousRangeMap&& src) : MAXON_MOVE_MEMBERS(_map) { }
	MAXON_OPERATOR_MOVE_ASSIGNMENT(ContiguousRangeMap);

	//----------------------------------------------------------------------------------------
	/// Initializes the map. This has to be done before any of the other functions of this map are called.
	//----------------------------------------------------------------------------------------
	Result<void> Init(const V& value)
	{
		_map.Flush();
		return _map.Insert(LIMIT<K>::Min(), value);
	}

	//----------------------------------------------------------------------------------------
	/// Initializes the map. This has to be done before any of the other functions of this map are called.
	//----------------------------------------------------------------------------------------
	Result<void> Init(V&& value)
	{
		_map.Flush();
		return _map.Insert(LIMIT<K>::Min(), std::move(value));
	}

	//----------------------------------------------------------------------------------------
	/// Makes this map a copy of src.
	/// @param[in] src								Source from which the entries are taken.
	/// @return												True if copying succeeded.
	//----------------------------------------------------------------------------------------
	Result<void> CopyFrom(const ContiguousRangeMap& src)
	{
		return _map.CopyFrom(src._map);
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
	//----------------------------------------------------------------------------------------
	Result<void> Insert(K rMinValue, K rMaxValue, V&& value)
	{
		iferr_scope;
		if (rMinValue > rMaxValue)
			return OK;
		if (_map.IsEmpty())
		{
			Init(V()) iferr_return;
		}
		typename MapType::Iterator it = _map.FindFloor(rMinValue);
		DebugAssert(it);
		DebugAssert(it.GetKey() <= rMinValue);
		typename MapType::Iterator next = it;
		++next;
		typename MapType::Iterator begin;
		Bool changeFollowingKey = false;
		Int cnt = 0;
		MAXON_SCOPE
		{
			if (it.GetValue() == value)
			{
				// the entry maps to the same value
				// merge both ranges
				if (!next || (rMaxValue < next.GetKey()))
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
			else if (it.GetKey() < rMinValue)
			{
				if (rMaxValue < (next ? next.GetKey() - 1 : LIMIT<K>::MAX))
				{
					// r contained in range of it, isolated from its boundaries
					// the existing range of it has to be split
					MapValue itValue;
					AssignCopy(itValue, it.GetValue()) iferr_return;
					Bool created = false;
					_map.Insert(rMinValue, std::move(value), created) iferr_return;
					DebugAssert(created);
					_map.Insert(rMaxValue + 1, std::move(itValue), created) iferr_return;
					DebugAssert(created);
					return OK;
				}
				else
				{
					// the found range has to be cut
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
					if (begin.GetValue() == value)
					{
						it = begin;
						goto extendRange;
					}
				}
				if (rMaxValue < (next ? next.GetKey() - 1 : LIMIT<K>::MAX))
				{
					// r is contained in it and ends before it
					MapValue itValue = std::move(it.GetValue());
					it.GetValue() = std::move(value);
					Bool created = false;
					_map.Insert(rMaxValue + 1, std::move(itValue), created) iferr_return;
					DebugAssert(created);
					return OK;
				}
				else
				{
					// r contains range of it
					it.GetValue() = std::move(value);
					goto extendRange;
				}
			}

		extendRange:
			const V& val = it.GetValue(); // the value of the parameter #value might already have been moved into the map
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
				if (rMaxValue == (it ? it.GetKey() - 1 : LIMIT<K>::MAX))
				{
					// last overlapping range is completely contained in r
					if (it && (it.GetValue() == val))
					{
						// merge with range of it
						++cnt;
					}
				}
				else if (*last == val)
				{
					// last overlapping range goes beyond r, but has same value
					// merge with last range
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
				DebugAssert(!it || (it.GetKey() == rMaxValue + 1));
				if (it && (it.GetValue() == val))
				{
					// merge with range of it
					DebugAssert(cnt == 0);
					cnt = 1;
				}
			}
			goto remove;
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
				if (rMaxValue == (it ? it.GetKey() - 1 : LIMIT<K>::MAX))
				{
					// last overlapping range is completely contained in r
					if (it && (it.GetValue() == value))
					{
						// merge with range of it
						++cnt;
					}
					begin.GetValue() = std::move(value);
				}
				else if (*last == value)
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
							return ResultMem(false);
						begin = e.GetValue();
						DebugAssert(created);
					}
					begin.GetValue() = std::move(value);
					changeFollowingKey = true;
				}
			}
			else
			{
				DebugAssert(!it || (it.GetKey() == rMaxValue + 1));
				if (it && (it.GetValue() == value))
				{
					// r can be merged with existing range
				}
				else
				{
					// create isolated range
					Bool created = false;
					_map.Insert(rMinValue, std::move(value), created) iferr_return;
					DebugAssert(created);
					return OK;
				}
			}
			begin.ChangeKey(_map, rMinValue) iferr_return;
			++begin;
			--cnt;
		}

	remove:
		begin.Erase(_map, cnt) iferr_return;
		if (changeFollowingKey)
		{
			begin.ChangeKey(_map, rMaxValue + 1) iferr_return;
		}
		return OK;
	}

	//----------------------------------------------------------------------------------------
	/// Maps the range @p rMinValue ... @p rMaxValue to @p value.
	/// Existing overlapping mappings are truncated, split or removed as necessary, or they are
	/// merged with the new mapping if their values are equal.
	/// If the range is empty (@p rMaxValue is less than @p rMinValue), nothing happens.
	/// @param[in] rMinValue					Lower boundary of the range.
	/// @param[in] rMaxValue					Upper boundary of the range.
	/// @param[in] value							Value to which the range shall be mapped.
	//----------------------------------------------------------------------------------------
	Result<void> Insert(K rMinValue, K rMaxValue, const V& value)
	{
		V v(value);
		return Insert(rMinValue, rMaxValue, std::move(v));
	}

	//----------------------------------------------------------------------------------------
	/// Maps the single value @p key (i.e., the range @p key ... @p key consisting of a single element) to @p value.
	/// Existing mappings which overlap @p key are truncated, split or removed as necessary, or they may
	/// be extended to include @p key if their values are equal.
	/// @param[in] key								A single key which shall be mapped.
	/// @param[in] value							Value to which the range shall be mapped.
	//----------------------------------------------------------------------------------------
	Result<void> Insert(K key, const V& value)
	{
		return Insert(key, key, V(value));
	}

	//----------------------------------------------------------------------------------------
	/// Maps the given @p range to @p value.
	/// Existing overlapping mappings are truncated, split or removed as necessary, or they are
	/// merged with the new mapping if their values are equal.
	/// If the range is empty, nothing happens.
	/// @param[in] range							Range which shall be mapped.
	/// @param[in] value							Value to which the range shall be mapped.
	//----------------------------------------------------------------------------------------
	Result<void> Insert(const Range& range, const V& value)
	{
		return Insert(range._minValue, range._maxValue, V(value));
	}

	//----------------------------------------------------------------------------------------
	/// Finds the value associated with the given @p key in this map.
	/// There always exists such a value, so this function never returns nullptr.
	/// @param[in] key								Key to search for.
	/// @return												Pointer to value for the given key, never nullptr.
	//----------------------------------------------------------------------------------------
	const V* FindValue(K key) const
	{
		typename MapType::ConstIterator it = _map.FindFloor(key);
		if (!it)
			return &NullValue<const V&>();
		DebugAssert(it.GetKey() <= key);
		return &it.GetValue();
	}

	//----------------------------------------------------------------------------------------
	/// Finds the value associated with the given @p key in this map.
	/// There always exists such a value, so this function never returns nullptr.
	/// @p rangeOut is set to the range.
	/// @param[in] key								Key to search for.
	/// @param[out] rangeOut					@p rangeOut is set to the found range.
	/// @return												Pointer to value for the given key, never nullptr.
	//----------------------------------------------------------------------------------------
	const V* FindRange(K key, Range& rangeOut) const
	{
		typename MapType::ConstIterator it = _map.FindFloor(key);
		if (!it)
		{
			rangeOut.Set(LIMIT<K>::Min(), LIMIT<K>::Max());
			return &NullValue<const V&>();
		}
		DebugAssert(it.GetKey() <= key);
		K min = it.GetKey();
		const V* result = &it.GetValue();
		++it;
		rangeOut.Set(min, it ? it.GetKey() - 1 : LIMIT<K>::MAX);
		return result;
	}

	typename SFINAEHelper<String, K>::type ToString(const FormatStatement* fmt) const
	{
		return _map.ToString(fmt);
	}

	template <Bool CONSTITERATOR> class EntryIteratorBase : public MapType::template EntryIteratorBase<true>
	{
	public:
		static_assert(CONSTITERATOR, "Wrong instantiation.");
		using CollectionType = const ContiguousRangeMap;
		using Type = Pair<Range, const V&>;
		using Super = typename MapType::template EntryIteratorBase<true>;

		EntryIteratorBase() { }
		EntryIteratorBase(CollectionType& m, Int s) : Super(m._map, s) { }
		EntryIteratorBase(const EntryIteratorBase& src) : Super(src) { }

		Range GetKey() const
		{
			ConstIterator next = *static_cast<const ConstIterator*>(this);
			++next;
			return Range(Super::GetKey(), next ? static_cast<const Super&>(next).GetKey() - 1 : LIMIT<K>::MAX);
		}

		Type operator *() const
		{
			ConstIterator next = *static_cast<const ConstIterator*>(this);
			++next;
			return Type(Range(Super::GetKey(), next ? static_cast<const Super&>(next).GetKey() - 1 : LIMIT<K>::MAX), Super::GetValue());
		}
	};

	template <Bool CONSTITERATOR> class KeyIteratorBase : public MapType::template EntryIteratorBase<true>
	{
	public:
		static_assert(CONSTITERATOR, "Wrong instantiation.");
		using CollectionType = const ContiguousRangeMap;
		using Super = typename MapType::template EntryIteratorBase<true>;

		KeyIteratorBase() { }
		KeyIteratorBase(CollectionType& m, Int s) : Super(m._map, s) { }
		KeyIteratorBase(const KeyIteratorBase& src) : Super(src) { }

		Range operator *() const
		{
			ConstKeyIterator next = *static_cast<const ConstKeyIterator*>(this);
			++next;
			return Range(Super::GetKey(), next ? static_cast<const Super&>(next).GetKey() - 1 : LIMIT<K>::MAX);
		}
	};

	template <Bool CONSTITERATOR> class ValueIteratorBase : public MapType::template EntryIteratorBase<true>
	{
	public:
		static_assert(CONSTITERATOR, "Wrong instantiation.");
		using CollectionType = const ContiguousRangeMap;
		using Super = typename MapType::template EntryIteratorBase<true>;

		ValueIteratorBase() { }
		ValueIteratorBase(CollectionType& m, Int s) : Super(m._map, s) { }
		ValueIteratorBase(const ValueIteratorBase& src) : Super(src) { }

		const V& operator *() const
		{
			return this->GetValue();
		}

		const V* operator ->() const
		{
			return &this->GetValue();
		}
	};


	using ConstIterator = typename MapType::template IteratorTemplate<true, EntryIteratorBase>;
	using Iterator = ConstIterator;

	using ConstKeyIterator = typename MapType::template IteratorTemplate<true, KeyIteratorBase>;

	using ConstValueIterator = typename MapType::template IteratorTemplate<true, ValueIteratorBase>;

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
	ConstKeyIterator GetKeys() const
	{
		return ConstKeyIterator(*this);
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

	Bool operator ==(const ContiguousRangeMap& other) const
	{
		return _map == other._map;
	}

	Bool operator !=(const ContiguousRangeMap& other) const
	{
		return !this->operator ==(other);
	}

	const MapType& GetUnderlyingMap() const
	{
		return _map;
	}

	MapType& GetUnderlyingMap()
	{
		return _map;
	}

private:
	MAXON_DISALLOW_COPY_AND_ASSIGN(ContiguousRangeMap);
	MapType _map; ///< The underlying map which maps each start of a range to the mapped value. The range ends one before the start of the next range.
};


/// @}

} // namespace maxon

#endif // CONTIGUOUSRANGEMAP_H__
