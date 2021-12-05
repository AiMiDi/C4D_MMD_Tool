#ifndef HYBRIDMAP_H__
#define HYBRIDMAP_H__

#include "maxon/collection.h"

namespace maxon
{

template <typename C> class HybridMapGetIteratorHelper
{
public:
	static typename C::Iterator&& Get(const C&, typename C::Iterator&& it)
	{
		return std::move(it);
	}

	static ResultMemT<typename C::Iterator>&& Get(const C&, ResultMemT<typename C::Iterator>&& it)
	{
		return std::move(it);
	}

	template <typename ENTRY> static typename C::Iterator Get(C& map, ENTRY* entry)
	{
		return typename C::Iterator(map, -1, entry);
	}

	template <typename ENTRY> static ResultMemT<typename C::Iterator> Get(C& map, ResultRef<ENTRY>&& entry)
	{
		return typename C::Iterator(map, -1, entry.GetPointer());
	}
};

/// @addtogroup STRUCTURES
/// @{


//----------------------------------------------------------------------------------------
/// A HybridMap allows to take advantage of two different map implementations.
/// For example, in a typical setting an ArrayMap may perform better with a low number of
/// entries, while a BurstTrieMap gets better when the number of entries increases. If
/// you cannot predict that the number of entries will always be small (to use an ArrayMap)
/// or large (to use a BurstTrieMap), you can use the HybridMap which automatically switches
/// between two implementations based on the number of entries:
/// @code
/// HybridMap<UInt, String, ArrayMapSelector<>, BurstTrieMapSelector<>, 64, 16> map;
/// @endcode
///
/// See HashMap for more examples on how to use maps in general.
///
/// @tparam K											Type of keys.
/// @tparam V											Type of values.
/// @tparam SMALL									A map selector template to choose the map implementation to use for a small number of entries.
/// @tparam LARGE									A map selector template to choose the map implementation to use for a large number of entries.
/// @tparam THRESHOLD							When the number of entries reaches THRESHOLD, HybridMap switches to the LARGE implementation.
/// @tparam REVERSE_THRESHOLD			When the number of entries falls below REVERSE_THRESHOLD, HybridMap switches back to the SMALL implementation. If this is negative, this will never happen.
/// @see @$ref maps
//----------------------------------------------------------------------------------------
template <typename K, typename V, typename SMALL, typename LARGE, Int THRESHOLD, Int REVERSE_THRESHOLD> class HybridMap
	: public MapBase<HybridMap<K, V, SMALL, LARGE, THRESHOLD, REVERSE_THRESHOLD>, K, V, EmptyClass, DefaultCompare>
{
public:
	static_assert(THRESHOLD >= REVERSE_THRESHOLD, "THRESHOLD must not be less than REVERSE_THRESHOLD");

	using SmallType = typename SMALL::template Type<K, V>;
	using LargeType = typename LARGE::template Type<K, V>;
	using IsHybridMap = std::true_type;

	//----------------------------------------------------------------------------------------
	/// Iterator implementation for HybridMap. Besides the usual iterator operations,
	/// ArrayMap iterators support the foreach protocol and (depending on the underlying implementations) Erase and ChangeKey functions.
	//----------------------------------------------------------------------------------------
	template <Bool CONSTITERATOR, template <Bool> class SUPER> class IteratorTemplate : public ForEachIterator<IteratorTemplate<CONSTITERATOR, SUPER>, SUPER<CONSTITERATOR>>
	{
	public:
		using Super = ForEachIterator<IteratorTemplate<CONSTITERATOR, SUPER>, SUPER<CONSTITERATOR>>;

		IteratorTemplate() : Super() { }
		MAXON_IMPLICIT IteratorTemplate(const typename Super::SmallIterator& src) : Super(src) { }
		MAXON_IMPLICIT IteratorTemplate(const typename Super::LargeIterator& src) : Super(src) { }
		IteratorTemplate(const IteratorTemplate& src) : Super(src) { }
		explicit IteratorTemplate(typename Super::CollectionType& m, Int s = 0) : Super(m, s) { }
		IteratorTemplate(const typename Super::SmallIterator& src, const SmallType& m) : Super(src) { }
		IteratorTemplate(const typename Super::LargeIterator& src, const LargeType& m) : Super(src) { }
		template <typename ENTRY> explicit IteratorTemplate(ENTRY* src, typename ConstIf<SmallType, CONSTITERATOR>::type& m) : Super(m.GetIterator(src)) { }
		template <typename ENTRY> explicit IteratorTemplate(ENTRY* src, typename ConstIf<LargeType, CONSTITERATOR>::type& m) : Super(m.GetIterator(src)) { }

		MAXON_OPERATOR_COPY_ASSIGNMENT(IteratorTemplate);

		template <Bool C, template <Bool> class S, typename = typename std::enable_if<!CONSTITERATOR || C>::type> operator IteratorTemplate<C, S>&()
		{
			MAXON_ASSERT_STANDARD_LAYOUT(typename Super::SmallIterator);
			MAXON_ASSERT_STANDARD_LAYOUT(typename Super::LargeIterator);
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
			Super::operator --();
			return *this;
		}
	};

	template <Bool CONSTITERATOR> class IteratorBase
	{
	public:
		using SmallIterator = typename std::conditional<CONSTITERATOR, typename SmallType::ConstIterator, typename SmallType::Iterator>::type;
		using LargeIterator = typename std::conditional<CONSTITERATOR, typename LargeType::ConstIterator, typename LargeType::Iterator>::type;
		using CollectionType = typename ConstIf<HybridMap, CONSTITERATOR>::type;

		IteratorBase() : _small(true) { new (_union) SmallIterator(); }
		explicit IteratorBase(const SmallIterator& src) : _small(true) { new (_union) SmallIterator(src); }
		explicit IteratorBase(const LargeIterator& src) : _small(false) { new (_union) LargeIterator(src); }
		IteratorBase(const IteratorBase& src) : _small(src._small)
		{
			if (src._small)
				new (_union) SmallIterator(src.GetSmall());
			else
				new (_union) LargeIterator(src.GetLarge());
		}
		IteratorBase(CollectionType& m, Int s) : _small(m._small)
		{
			if (m._small)
				new (_union) SmallIterator(m.GetSmall(), s);
			else
				new (_union) LargeIterator(m.GetLarge(), s);
		}

		~IteratorBase()
		{
			if (_small)
				GetSmall().~SmallIterator();
			else
				GetLarge().~LargeIterator();
		}

		void operator ++()
		{
			if (_small)
				GetSmall().operator ++();
			else
				GetLarge().operator ++();
		}

		void operator --()
		{
			if (_small)
				GetSmall().operator --();
			else
				GetLarge().operator --();
		}

		explicit operator Bool() const
		{
			return _small ? Bool(GetSmall()) : Bool(GetLarge());
		}

		//----------------------------------------------------------------------------------------
		/// Returns the key of the current key-value-pair of this iterator.
		/// @return												Current key of this iterator.
		//----------------------------------------------------------------------------------------
		const K& GetKey() const
		{
			return _small ? GetSmall().GetKey() : GetLarge().GetKey();
		}

		//----------------------------------------------------------------------------------------
		/// Returns the value of the current key-value-pair of this iterator.
		/// @return												Current value of this iterator.
		//----------------------------------------------------------------------------------------
		typename ConstIf<V, CONSTITERATOR>::type& GetValue() const
		{
			return _small ? GetSmall().GetValue() : GetLarge().GetValue();
		}

		Bool operator ==(const IteratorBase& b) const
		{
			return (_small == b._small) && (_small ? (GetSmall() == b.GetSmall()) : (GetLarge() == b.GetLarge()));
		}

		Bool operator !=(const IteratorBase& b) const
		{
			return !this->operator ==(b);
		}

	protected:
		SmallIterator& GetSmall()
		{
			DebugAssert(_small);
			return *(SmallIterator*) _union;
		}

		LargeIterator& GetLarge()
		{
			DebugAssert(!_small);
			return *(LargeIterator*) _union;
		}

		const SmallIterator& GetSmall() const
		{
			DebugAssert(_small);
			return *(const SmallIterator*) _union;
		}

		const LargeIterator& GetLarge() const
		{
			DebugAssert(!_small);
			return *(const LargeIterator*) _union;
		}

		friend class HybridMap;

		Bool _small;
		typename std::aligned_union2<0, SmallIterator, LargeIterator>::type _union[1];
	};

	class NonConstIteratorBase : public IteratorBase<false>
	{
		using Super = IteratorBase<false>;
	public:
		using SmallIterator = typename SmallType::Iterator;
		using LargeIterator = typename LargeType::Iterator;

		NonConstIteratorBase() { }
		explicit NonConstIteratorBase(const SmallIterator& src) : Super(src) { }
		explicit NonConstIteratorBase(const LargeIterator& src) : Super(src) { }
		NonConstIteratorBase(const NonConstIteratorBase& src) : Super(src) { }
		NonConstIteratorBase(HybridMap& m, Int s) : Super(m, s) { }

		//----------------------------------------------------------------------------------------
		/// Removes @p eraseCnt elements from the map starting at the position given by this iterator.
		/// Afterwards, this iterator will point to the element behind the last removed element.
		/// @param[in] map								Map of this iterator.
		/// @param[in] eraseCnt						Number of elements to remove.
		/// @return												OK on success.
		//----------------------------------------------------------------------------------------
		Result<void> Erase(HybridMap& map, Int eraseCnt = 1)
		{
			iferr_scope;
			if (this->_small)
			{
				return this->GetSmall().Erase(map.GetSmall(), eraseCnt);
			}
			else
			{
				this->GetLarge().Erase(map.GetLarge(), eraseCnt) iferr_return;
				if (map.GetLarge().GetCount() < REVERSE_THRESHOLD)
				{
					if (this->GetLarge())
					{
						K key = this->GetLarge().GetKey();
						map.UseSmallMap() iferr_return;
						this->GetLarge().~LargeIterator();
						this->_small = true;
						new (this->_union) SmallIterator(map.GetSmall().FindFloor(key));
					}
					else
					{
						map.UseSmallMap() iferr_return;
						this->GetLarge().~LargeIterator();
						this->_small = true;
						new (this->_union) SmallIterator();
					}
				}
				return OK;
			}
		}

		//----------------------------------------------------------------------------------------
		/// Modifies the key of the map entry pointed to by this iterator.
		/// This operation is only supported if both underlying implementations support it. The new key must be in a range
		/// such that this operation doesn't change the order, i.e., it must be above the
		/// key of the previous entry and below the key of the next entry.
		/// @param[in] map								Map of this iterator.
		/// @param[in] newKey							New value for the key of the current map entry.
		/// @return												False if some allocation failed.
		//----------------------------------------------------------------------------------------
		ResultMem ChangeKey(HybridMap& map, const K& newKey)
		{
			return this->_small ? this->GetSmall().ChangeKey(map.GetSmall(), newKey) : this->GetLarge().ChangeKey(map.GetLarge(), newKey);
		}
	};

	template <Bool CONSTITERATOR> class EntryIteratorBase : public std::conditional<CONSTITERATOR, IteratorBase<true>, NonConstIteratorBase>::type
	{
	public:
		using Super = typename std::conditional<CONSTITERATOR, IteratorBase<true>, NonConstIteratorBase>::type;
		using CollectionType = typename ConstIf<HybridMap, CONSTITERATOR>::type;
		using KeyType = K;
		using MappedType = typename ConstIf<V, CONSTITERATOR>::type;

		using Small = decltype(*std::declval<typename Super::SmallIterator>());
		using Large = decltype(*std::declval<typename Super::LargeIterator>());

		static const Bool SAME_TYPE = std::is_same<typename std::decay<Small>::type, typename std::decay<Large>::type>::value;
		using ValueType = typename std::conditional<SAME_TYPE, typename CommonLValue<Small, Small, Large>::type, Pair<K, V>>::type;

		EntryIteratorBase() { }
		explicit EntryIteratorBase(const typename Super::SmallIterator& src) : Super(src) { }
		explicit EntryIteratorBase(const typename Super::LargeIterator& src) : Super(src) { }
		EntryIteratorBase(const EntryIteratorBase& src) : Super(src) { }
		explicit EntryIteratorBase(CollectionType& m, Int s = 0) : Super(m, s) { }

		ValueType operator *() const
		{
			if (this->_small)
				return *this->GetSmall();
			else
				return *this->GetLarge();
		}

	protected:
		void operator ->();
	};

	template <Bool CONSTITERATOR> class KeyIteratorBase : public EntryIteratorBase<CONSTITERATOR>
	{
	public:
		using ValueType = const K&;
		using Super = EntryIteratorBase<CONSTITERATOR>;

		KeyIteratorBase() { }
		explicit KeyIteratorBase(const typename Super::SmallIterator& src) : Super(src) { }
		explicit KeyIteratorBase(const typename Super::LargeIterator& src) : Super(src) { }
		KeyIteratorBase(const KeyIteratorBase& src) : Super(src) { }
		explicit KeyIteratorBase(typename Super::CollectionType& m, Int s = 0) : Super(m, s) { }

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
		explicit ValueIteratorBase(const typename Super::SmallIterator& src) : Super(src) { }
		explicit ValueIteratorBase(const typename Super::LargeIterator& src) : Super(src) { }
		ValueIteratorBase(const ValueIteratorBase& src) : Super(src) { }
		explicit ValueIteratorBase(typename Super::CollectionType& m, Int s = 0) : Super(m, s) { }

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
	/// @return												Iterator for this map pointing to the first element.
	//----------------------------------------------------------------------------------------
	Iterator Begin()
	{
		if (_small)
			return GetSmall().Begin();
		else
			return GetLarge().Begin();
	}

	//----------------------------------------------------------------------------------------
	/// Returns an iterator pointing just behind the last entry of this map.
	/// @return												Iterator for this map pointing behind the last element.
	//----------------------------------------------------------------------------------------
	Iterator End()
	{
		if (_small)
			return GetSmall().End();
		else
			return GetLarge().End();
	}

	//----------------------------------------------------------------------------------------
	/// Returns an iterator pointing to the first entry of this map.
	/// @return												Iterator for this map pointing to the first element.
	//----------------------------------------------------------------------------------------
	ConstIterator Begin() const
	{
		if (_small)
			return GetSmall().Begin();
		else
			return GetLarge().Begin();
	}

	//----------------------------------------------------------------------------------------
	/// Returns an iterator pointing just behind the last entry of this map.
	/// @return												Iterator for this map pointing behind the last element.
	//----------------------------------------------------------------------------------------
	ConstIterator End() const
	{
		if (_small)
			return GetSmall().End();
		else
			return GetLarge().End();
	}

	//----------------------------------------------------------------------------------------
	/// Returns a foreach iterator to iterate over all keys of this map.
	/// @return												Foreach iterator over all keys.
	//----------------------------------------------------------------------------------------
	KeyIterator GetKeys()
	{
		if (_small)
			return GetSmall().Begin();
		else
			return GetLarge().Begin();
	}

	//----------------------------------------------------------------------------------------
	/// Returns a foreach iterator to iterate over all keys of this map.
	/// @return												Foreach iterator over all keys.
	//----------------------------------------------------------------------------------------
	ConstKeyIterator GetKeys() const
	{
		if (_small)
			return GetSmall().Begin();
		else
			return GetLarge().Begin();
	}

	//----------------------------------------------------------------------------------------
	/// Returns a foreach iterator to iterate over all values of this map.
	/// @return												Foreach iterator over all values.
	//----------------------------------------------------------------------------------------
	ValueIterator GetValues()
	{
		if (_small)
			return GetSmall().Begin();
		else
			return GetLarge().Begin();
	}

	//----------------------------------------------------------------------------------------
	/// Returns a foreach iterator to iterate over all values of this map.
	/// @return												Foreach iterator over all values.
	//----------------------------------------------------------------------------------------
	ConstValueIterator GetValues() const
	{
		if (_small)
			return GetSmall().Begin();
		else
			return GetLarge().Begin();
	}

	HybridMap() : _small(true)
	{
		new (_union) SmallType();
	}

	~HybridMap()
	{
		if (_small)
			GetSmall().~SmallType();
		else
			GetLarge().~LargeType();
	}

	HybridMap(HybridMap&& src) : _small(src._small)
	{
		if (src._small)
			new (_union) SmallType(std::move(src.GetSmall()));
		else
			new (_union) LargeType(std::move(src.GetLarge()));
	}

	MAXON_OPERATOR_MOVE_ASSIGNMENT(HybridMap);

	template <typename MAP> Result<void> CopyFromImpl(MAP&& src, COLLECTION_RESIZE_FLAGS resizeFlags, OverloadRank0)
	{
		Flush();
		Int cnt = maxon::GetCount(src);
		if (cnt >= THRESHOLD)
		{
			Result<void> r = UseLargeMap();
			if (r == FAILED)
				return r;
			return GetLarge().CopyFrom(std::forward<MAP>(src), resizeFlags);
		}
		else
		{
			Result<void> r = UseSmallMap();
			if (r == FAILED)
				return r;
			return GetSmall().CopyFrom(std::forward<MAP>(src), resizeFlags);
		}
	}

	template <typename MAP> typename SFINAEHelper<Result<void>, typename std::remove_reference<MAP>::type::IsHybridMap>::type CopyFromImpl(MAP&& src, COLLECTION_RESIZE_FLAGS resizeFlags, OverloadRank1)
	{
		if (src._small)
		{
			if (!_small)
			{
				GetLarge().~LargeType();
				new (_union) SmallType();
				_small = true;
			}
			return GetSmall().CopyFrom(src.GetSmall(), resizeFlags);
		}
		else
		{
			if (_small)
			{
				GetSmall().~SmallType();
				new (_union) LargeType();
				_small = false;
			}
			return GetLarge().CopyFrom(src.GetLarge(), resizeFlags);
		}
	}

	//----------------------------------------------------------------------------------------
	/// Flushes the map so that it is empty afterwards. Depending on the underlying implementations,
	/// memory may still be held for re-use.
	/// If @p REVERSE_THRESHOLD is non-negative, Flush() will also switch back to the @p SMALL implementation.
	//----------------------------------------------------------------------------------------
	void Flush()
	{
		if (_small)
		{
			GetSmall().Flush();
		}
		else if (REVERSE_THRESHOLD >= 0)
		{
			GetLarge().~LargeType();
			new (_union) SmallType();
			_small = true;
		}
		else
		{
			GetLarge().Flush();
		}
	}

	//----------------------------------------------------------------------------------------
	/// Resets the map. This destructs all entries and frees any memory held by the map.
	/// The map will also switch to the @p SMALL implementation if necessary, so it
	/// will be in a state as if it had been newly constructed.
	//----------------------------------------------------------------------------------------
	void Reset()
	{
		if (_small)
		{
			GetSmall().Reset();
		}
		else
		{
			GetLarge().~LargeType();
			new (_union) SmallType();
			_small = true;
		}
	}

	//----------------------------------------------------------------------------------------
	/// Returns the number of entries in this map.
	/// @return												Number of entries.
	//----------------------------------------------------------------------------------------
	Int GetCount() const
	{
		return _small ? GetSmall().GetCount() : GetLarge().GetCount();
	}

	//----------------------------------------------------------------------------------------
	/// Returns an estimate of the number of operations needed to locate a given key in this map.
	/// This is used when two collections are compared: The iteration goes over the collection which would require
	/// more operations for search, and each entry is searched in the other collection.
	/// @return												Estimate for the number of operations.
	//----------------------------------------------------------------------------------------
	Int GetOperationCountForSearch() const
	{
		return _small ? GetSmall().GetOperationCountForSearch() : GetLarge().GetOperationCountForSearch();
	}

	//----------------------------------------------------------------------------------------
	/// Returns the memory usage of this map.
	/// @return												Memory size in bytes.
	//----------------------------------------------------------------------------------------
	Int GetMemorySize() const
	{
		return _small ? (GetSmall().GetMemorySize() + (SIZEOF(HybridMap) - SIZEOF(SmallType))) : (GetLarge().GetMemorySize() + (SIZEOF(HybridMap) - SIZEOF(LargeType)));
	}

	//----------------------------------------------------------------------------------------
	/// Increases the internal capacity of the map so that it is prepared to hold at least
	/// the given number of elements. This is forwarded to the currently used underlying map implementation.
	/// @param[in] capacity						The desired capacity.
	/// @param[in] resizeFlags				If ON_GROW_FIT_TO_SIZE is set, the collection will use only as much memory as needed to hold the data.
	/// @return												False if allocation failed.
	//----------------------------------------------------------------------------------------
	ResultMem SetCapacityHint(Int capacity, COLLECTION_RESIZE_FLAGS resizeFlags = COLLECTION_RESIZE_FLAGS::ON_GROW_RESERVE_CAPACITY)
	{
		return _small ? GetSmall().SetCapacityHint(capacity, resizeFlags) : GetLarge().SetCapacityHint(capacity, resizeFlags);
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
		if (_small)
		{
			iferr_scope_handler
			{
				return FAILED;
			};
			typename SmallType::Iterator i = HybridMapGetIteratorHelper<SmallType>::Get(GetSmall(), GetSmall().InsertEntry(key, created)) iferr_return;
			if (!created || (GetSmall().GetCount() < THRESHOLD))
				return i.GetValue();
			UseLargeMap() iferr_return;
			typename LargeType::Iterator li = HybridMapGetIteratorHelper<LargeType>::Get(GetLarge(), GetLarge().Find(key));
			DebugAssert(li);
			return li.GetValue();
		}
		else
		{
			return GetLarge().InsertKey(key, created);
		}
	}

	//----------------------------------------------------------------------------------------
	/// Finds the value associated with the given key, or creates a corresponding entry if it doesn't exist yet.
	/// The value of a new entry has to be initialized afterwards (but its default constructor has already been invoked).
	/// @param[in] key								Key of the value to find or create. If a new entry is created, its key will be constructed by move-semantics if possible.
	/// @param[out] created						This will be set to true if a new entry has been created successfully, otherwise it will be set to false.
	/// @return												Pointer to value for the given key, or nullptr if an entry didn't exist and allocation of a new entry failed.
	//----------------------------------------------------------------------------------------
	ResultRef<V> InsertKey(K&& key, Bool& created = BoolLValue())
	{
		if (_small)
		{
			iferr_scope_handler
			{
				return FAILED;
			};
			typename SmallType::Iterator i = HybridMapGetIteratorHelper<SmallType>::Get(GetSmall(), GetSmall().InsertEntry(std::move(key), created)) iferr_return;
			if (!created || (GetSmall().GetCount() < THRESHOLD))
				return i.GetValue();
			// We have to copy the key from i.GetKey(): #key has already been moved into the small map, and #i will be invalid after UseLargeMap().
			K keyCopy;
			AssignCopy(keyCopy, i.GetKey()) iferr_return;
			UseLargeMap() iferr_return;
			typename LargeType::Iterator li = HybridMapGetIteratorHelper<LargeType>::Get(GetLarge(), GetLarge().Find(keyCopy));
			DebugAssert(li);
			return li.GetValue();
		}
		else
		{
			return GetLarge().InsertKey(std::move(key), created);
		}
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
		if (_small)
		{
			iferr_scope_handler
			{
				return FAILED;
			};
			typename SmallType::Iterator i = HybridMapGetIteratorHelper<SmallType>::Get(GetSmall(), GetSmall().InsertEntry(key, created)) iferr_return;
			if (!created || (GetSmall().GetCount() < THRESHOLD))
				return Iterator(std::move(i));
			UseLargeMap() iferr_return;
			typename LargeType::Iterator li = HybridMapGetIteratorHelper<LargeType>::Get(GetLarge(), GetLarge().Find(key));
			DebugAssert(li);
			return Iterator(std::move(li));
		}
		else
		{
			return HybridMapGetIteratorHelper<LargeType>::Get(GetLarge(), GetLarge().InsertEntry(key, created));
		}
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
		if (_small)
		{
			iferr_scope_handler
			{
				return FAILED;
			};
			typename SmallType::Iterator i = HybridMapGetIteratorHelper<SmallType>::Get(GetSmall(), GetSmall().InsertEntry(std::move(key), created)) iferr_return;
			if (!created || (GetSmall().GetCount() < THRESHOLD))
				return Iterator(std::move(i));
			// We have to copy the key from i.GetKey(): #key has already been moved into the small map, and #i will be invalid after UseLargeMap().
			K keyCopy;
			AssignCopy(keyCopy, i.GetKey()) iferr_return;
			UseLargeMap() iferr_return;
			typename LargeType::Iterator li = HybridMapGetIteratorHelper<LargeType>::Get(GetLarge(), GetLarge().Find(keyCopy));
			DebugAssert(li);
			return Iterator(std::move(li));
		}
		else
		{
			return HybridMapGetIteratorHelper<LargeType>::Get(GetLarge(), GetLarge().InsertEntry(std::move(key), created));
		}
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
		if (_small)
		{
			iferr_scope_handler
			{
				return FAILED;
			};
			typename SmallType::Iterator i = HybridMapGetIteratorHelper<SmallType>::Get(GetSmall(), GetSmall().Insert(key, value, created)) iferr_return;
			if (!created || (GetSmall().GetCount() < THRESHOLD))
				return Iterator(std::move(i));
			UseLargeMap() iferr_return;
			typename LargeType::Iterator li = HybridMapGetIteratorHelper<LargeType>::Get(GetLarge(), GetLarge().Find(key));
			DebugAssert(li);
			return Iterator(std::move(li));
		}
		else
		{
			return HybridMapGetIteratorHelper<LargeType>::Get(GetLarge(), GetLarge().Insert(key, value, created));
		}
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
		if (_small)
		{
			iferr_scope_handler
			{
				return FAILED;
			};
			typename SmallType::Iterator i = HybridMapGetIteratorHelper<SmallType>::Get(GetSmall(), GetSmall().Insert(std::move(key), value, created)) iferr_return;
			if (!created || (GetSmall().GetCount() < THRESHOLD))
				return Iterator(std::move(i));
			// We have to copy the key from i.GetKey(): #key has already been moved into the small map, and #i will be invalid after UseLargeMap().
			K keyCopy;
			AssignCopy(keyCopy, i.GetKey()) iferr_return;
			UseLargeMap() iferr_return;
			typename LargeType::Iterator li = HybridMapGetIteratorHelper<LargeType>::Get(GetLarge(), GetLarge().Find(keyCopy));
			DebugAssert(li);
			return Iterator(std::move(li));
		}
		else
		{
			return HybridMapGetIteratorHelper<LargeType>::Get(GetLarge(), GetLarge().Insert(std::move(key), value, created));
		}
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
		if (_small)
		{
			iferr_scope_handler
			{
				return FAILED;
			};
			typename SmallType::Iterator i = HybridMapGetIteratorHelper<SmallType>::Get(GetSmall(), GetSmall().Insert(key, std::move(value), created)) iferr_return;
			if (!created || (GetSmall().GetCount() < THRESHOLD))
				return Iterator(std::move(i));
			UseLargeMap() iferr_return;
			typename LargeType::Iterator li = HybridMapGetIteratorHelper<LargeType>::Get(GetLarge(), GetLarge().Find(key));
			DebugAssert(li);
			return Iterator(std::move(li));
		}
		else
		{
			return HybridMapGetIteratorHelper<LargeType>::Get(GetLarge(), GetLarge().Insert(key, std::move(value), created));
		}
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
		if (_small)
		{
			iferr_scope_handler
			{
				return FAILED;
			};
			typename SmallType::Iterator i = HybridMapGetIteratorHelper<SmallType>::Get(GetSmall(), GetSmall().Insert(std::move(key), std::move(value), created)) iferr_return;
			if (!created || (GetSmall().GetCount() < THRESHOLD))
				return Iterator(std::move(i));
			// We have to copy the key from i.GetKey(): #key has already been moved into the small map, and #i will be invalid after UseLargeMap().
			K keyCopy;
			AssignCopy(keyCopy, i.GetKey()) iferr_return;
			UseLargeMap() iferr_return;
			typename LargeType::Iterator li = HybridMapGetIteratorHelper<LargeType>::Get(GetLarge(), GetLarge().Find(keyCopy));
			DebugAssert(li);
			return Iterator(std::move(li));
		}
		else
		{
			return HybridMapGetIteratorHelper<LargeType>::Get(GetLarge(), GetLarge().Insert(std::move(key), std::move(value), created));
		}
	}

	//----------------------------------------------------------------------------------------
	/// Finds the value associated with the given key in this map.
	/// @param[in] key								Key to search for.
	/// @return												Pointer to value for the given key, or nullptr if no entry exists for the key.
	//----------------------------------------------------------------------------------------
	const V* FindValue(const K& key) const
	{
		return _small ? GetSmall().FindValue(key) : GetLarge().FindValue(key);
	}

	//----------------------------------------------------------------------------------------
	/// Finds the value associated with the given key in this map.
	/// @param[in] key								Key to search for.
	/// @return												Pointer to value for the given key, or nullptr if no entry exists for the key.
	//----------------------------------------------------------------------------------------
	V* FindValue(const K& key)
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
		if (_small)
			return Iterator(GetSmall().Find(key), GetSmall());
		else
			return Iterator(GetLarge().Find(key), GetLarge());
	}

	//----------------------------------------------------------------------------------------
	/// Finds the entry for the given key in this map.
	/// @param[in] key								Key to search for.
	/// @return												Iterator pointing to the entry with the given @p key,
	/// 															or an invalid iterator if this doesn't exist.
	//----------------------------------------------------------------------------------------
	ConstIterator Find(const K& key) const
	{
		if (_small)
			return ConstIterator(GetSmall().Find(key), GetSmall());
		else
			return ConstIterator(GetLarge().Find(key), GetLarge());
	}

	//----------------------------------------------------------------------------------------
	/// Finds the entry with the greatest key less than or equal to the given @p key.
	/// If no such entry exists, the returned iterator will be invalid (its <tt>operator Bool</tt> will return false).
	/// This function is only supported if both underlying implementations support it.
	/// @param[in] key								Key to search for.
	/// @return												Iterator pointing to the entry with greatest key less than or equal to the given @p key,
	/// 															or an invalid iterator if this doesn't exist.
	//----------------------------------------------------------------------------------------
	Iterator FindFloor(const K& key)
	{
		if (_small)
			return GetSmall().FindFloor(key);
		else
			return GetLarge().FindFloor(key);
	}

	//----------------------------------------------------------------------------------------
	/// Finds the entry with the greatest key less than or equal to the given @p key.
	/// If no such entry exists, the returned iterator will be invalid (its <tt>operator Bool</tt> will return false).
	/// This function is only supported if both underlying implementations support it.
	/// @param[in] key								Key to search for.
	/// @return												Iterator pointing to the entry with greatest key less than or equal to the given @p key,
	/// 															or an invalid iterator if this doesn't exist.
	//----------------------------------------------------------------------------------------
	ConstIterator FindFloor(const K& key) const
	{
		if (_small)
			return GetSmall().FindFloor(key);
		else
			return GetLarge().FindFloor(key);
	}

	//----------------------------------------------------------------------------------------
	/// Removes an entry with the given key from this map (if possible).
	/// @param[in] key								Key of the map entry to be be removed.
	/// @return												True if an entry was found and removed for #key, otherwise false or an error if a memory allocation failed.
	//----------------------------------------------------------------------------------------
	Result<Bool> Erase(const K& key)
	{
		iferr_scope;
		if (_small)
		{
			return GetSmall().Erase(key);
		}
		else
		{
			Bool removed = GetLarge().Erase(key) iferr_return;
			if (GetLarge().GetCount() < REVERSE_THRESHOLD)
			{
				UseSmallMap() iferr_return;
			}
			return removed;
		}
	}

	//----------------------------------------------------------------------------------------
	/// Removes the element at @p position from this map.
	/// The returned iterator will point to the element behind the last removed element.
	/// @param[in] position						Iterator pointing to the element to be removed.
	/// @return												Iterator pointing to the element behind the removed element.
	//----------------------------------------------------------------------------------------
	template <template <Bool> class SUPER> IteratorTemplate<false, SUPER> Erase(const IteratorTemplate<false, SUPER>& position)
	{
		if (_small)
		{
			return GetSmall().Erase(position.GetSmall());
		}
		else
		{
			return GetLarge().Erase(position.GetLarge());
		}
	}

	//----------------------------------------------------------------------------------------
	/// Switches to the @p LARGE implementation.
	/// @return												False if some memory allocation failed. In this case the map content may be invalid.
	//----------------------------------------------------------------------------------------
	Result<void> UseLargeMap()
	{
		if (!_small)
			return OK;
		LargeType map;
		Result<void> r = map.SetCapacityHint(GetSmall().GetCount());
		if (r == FAILED)
			return r;
		Bool created = false;
		for (typename SmallType::Iterator i = GetSmall().Begin(), end = GetSmall().End(); i != end; ++i)
		{
			ResultRef<V> v = map.InsertKey(i.GetKey(), created);
			if (v == FAILED)
				return CreateError(MAXON_SOURCE_LOCATION, ERROR_TYPE::OUT_OF_MEMORY);
			DebugAssert(created);
			v.GetValue() = std::move(i.GetValue());
		}
		GetSmall().~SmallType();
		_small = false;
		new (_union) LargeType(std::move(map));
		return OK;
	}

	//----------------------------------------------------------------------------------------
	/// Switches to the @p SMALL implementation.
	/// @return												False if some memory allocation failed. In this case the map content may be invalid.
	//----------------------------------------------------------------------------------------
	Result<void> UseSmallMap()
	{
		if (_small)
			return OK;
		SmallType map;
		Result<void> r = map.SetCapacityHint(GetLarge().GetCount());
		if (r == FAILED)
			return r;
		Bool created = false;
		for (typename LargeType::Iterator i = GetLarge().Begin(), end = GetLarge().End(); i != end; ++i)
		{
			ResultRef<V> v = map.InsertKey(i.GetKey(), created);
			if (v == FAILED)
				return CreateError(MAXON_SOURCE_LOCATION, ERROR_TYPE::OUT_OF_MEMORY);
			DebugAssert(created);
			v.GetValue() = std::move(i.GetValue());
		}
		GetLarge().~LargeType();
		_small = true;
		new (_union) SmallType(std::move(map));
		return OK;
	}

protected:
	SmallType& GetSmall()
	{
		DebugAssert(_small);
		return *(SmallType*) _union;
	}

	LargeType& GetLarge()
	{
		DebugAssert(!_small);
		return *(LargeType*) _union;
	}

	const SmallType& GetSmall() const
	{
		DebugAssert(_small);
		return *(const SmallType*) _union;
	}

	const LargeType& GetLarge() const
	{
		DebugAssert(!_small);
		return *(const LargeType*) _union;
	}

	Bool _small;
	typename std::aligned_union2<0, SmallType, LargeType>::type _union[1];

private:
	MAXON_DISALLOW_COPY_AND_ASSIGN(HybridMap);
};


//----------------------------------------------------------------------------------------
/// This selector class is used for template parameters which select the map implementation
/// to use. It will then instruct the template to use the HybridMap implementation.
/// For example, RangeSet uses an underlying BurstTrieMap by default. If you want to use
/// a HybridMap instead, you'd write
/// @code
/// RangeSet<UInt, HybridMapSelector<ArrayMapSelector<>, BurstTrieMapSelector<>, 64, 16>> set;
/// @endcode
///
/// @tparam SMALL									A map selector template to choose the map implementation to use for a small number of entries.
/// @tparam LARGE									A map selector template to choose the map implementation to use for a large number of entries.
/// @tparam THRESHOLD							When the number of entries reaches THRESHOLD, HybridMap switches to the LARGE implementation.
/// @tparam REVERSE_THRESHOLD			When the number of entries falls below REVERSE_THRESHOLD, HybridMap switches back to the SMALL implementation. If this is negative, this will never happen.
//----------------------------------------------------------------------------------------
template <typename SMALL, typename LARGE, Int THRESHOLD, Int REVERSE_THRESHOLD> class HybridMapSelector
{
public:
	template <typename K, typename V> using Type = HybridMap<K, V, SMALL, LARGE, THRESHOLD, REVERSE_THRESHOLD>;
};


//----------------------------------------------------------------------------------------
/// A HybridSet is an implementation of a set using an underlying HybridMap.
///
/// See HashSet for more examples on how to use sets in general.
///
/// @tparam T											Type of elements of the set.
/// @tparam SMALL									A map selector template to choose the map implementation to use for a small number of entries.
/// @tparam LARGE									A map selector template to choose the map implementation to use for a large number of entries.
/// @tparam THRESHOLD							When the number of entries reaches THRESHOLD, HybridMap switches to the LARGE implementation.
/// @tparam REVERSE_THRESHOLD			When the number of entries falls below REVERSE_THRESHOLD, HybridMap switches back to the SMALL implementation. If this is negative, this will never happen.
/// @see HybridMap
/// @see @$ref sets
//----------------------------------------------------------------------------------------
template <typename T, typename SMALL, typename LARGE, Int THRESHOLD, Int REVERSE_THRESHOLD> class HybridSet
	: public SetBase<HybridSet<T, SMALL, LARGE, THRESHOLD, REVERSE_THRESHOLD>, T, Protected<HybridMap<T, UnitType, SMALL, LARGE, THRESHOLD, REVERSE_THRESHOLD>>, DefaultCompare>
{
public:
	using MapType = HybridMap<T, UnitType, SMALL, LARGE, THRESHOLD, REVERSE_THRESHOLD>;
	using Super = SetBase<HybridSet<T, SMALL, LARGE, THRESHOLD, REVERSE_THRESHOLD>, T, Protected<MapType>, DefaultCompare>;
private:
	MAXON_DISALLOW_COPY_AND_ASSIGN(HybridSet);

public:
	using MapType::Find;
	using MapType::GetCount;
	using MapType::GetOperationCountForSearch;
	using MapType::SetCapacityHint;
	using MapType::Reset;
	using MapType::Flush;
	using MapType::GetMemorySize;

	using IsHybridMap = std::true_type;
	using IsHybridSet = std::true_type;

	friend MapType;

	HybridSet() : Super()
	{
	}

	HybridSet(HybridSet&& src) : Super(std::move(src))
	{
	}

	MAXON_OPERATOR_MOVE_ASSIGNMENT(HybridSet);

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

	void Insert() const;

	//----------------------------------------------------------------------------------------
	/// Adds @p value to this set. If @p value is already contained in this set, nothing happens,
	/// and @p added is set to @c false.
	/// @param[in] value							Value to add to this set.
	/// @param[out] added							This will be set to true if the element didn't exist before in the set and it could be added successfully, otherwise it will be set to false.
	/// @return												Iterator to the entry for the given key or OutOfMemoryError if the allocation failed.
	//----------------------------------------------------------------------------------------
	ResultMemT<Iterator> Insert(const T& value, Bool& added = BoolLValue())
	{
		return std::move(static_cast<Iterator&>(Super::InsertEntry(value, added).GetValue()));
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
		return std::move(static_cast<Iterator&>(Super::InsertEntry(std::move(value), added).GetValue()));
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
		typename Super::Iterator it = std::move(Super::InsertEntry(value, added).GetValue());
		return it ? &it.GetKey() : nullptr;
	}

	//----------------------------------------------------------------------------------------
	/// Remove @p value from this set. If @p value isn't contained in this set, nothing happens.
	/// @param[in] value							Value to remove from this set.
	/// @return												True if an entry was found and removed for #value, otherwise false or an error if a memory allocation failed.
	//----------------------------------------------------------------------------------------
	Result<Bool> Erase(const T& value)
	{
		return Super::Erase(value);
	}

	ConstIterator Begin() const
	{
		if (this->_small)
			return this->GetSmall().Begin();
		else
			return this->GetLarge().Begin();
	}

	ConstIterator End() const
	{
		if (this->_small)
			return this->GetSmall().End();
		else
			return this->GetLarge().End();
	}

	Iterator Begin()
	{
		if (this->_small)
			return this->GetSmall().Begin();
		else
			return this->GetLarge().Begin();
	}

	Iterator End()
	{
		if (this->_small)
			return this->GetSmall().End();
		else
			return this->GetLarge().End();
	}

	Iterator Erase(const Iterator& it)
	{
		return Super::Erase(it);
	}
};


/// @}

} // namespace maxon

#endif // HYBRIDMAP_H__
