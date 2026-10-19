#ifndef ARRAYALLOCATOR_H__
#define ARRAYALLOCATOR_H__

#include "maxon/blockarray.h"

namespace maxon
{

template <Int SIZE> struct ArrayAllocatorValueType
{
	Char data[SIZE];
};

//----------------------------------------------------------------------------------------
/// Array allocator which only allocates and frees entries of SIZE bytes.
/// Depending on the type of array the allocation might relocate already existing items.
/// @tparam SIZE									The size of an entry in bytes.
/// @tparam ARRAYSELECTOR					Selector for array type to be used as allocator.
/// @tparam FLUSH									Use true if Flush() shall be called on the array instead of Reset() when all entries have been freed.
/// @tparam NO_FREE								Use true if the Free() function won't be called (then all allocations have to be freed at once by DeleteAll()).
/// 															This enables certain optimizations, for example a HashMap can iterate over the allocated entries in memory order
/// 															because it's known that all entries are still in use.
/// @tparam SUPPORT_ITERATOR			Use true if the allocator shall support iterators over the entries in use (in memory order). This requires a tiny bit
/// 															of memory overhead (1 additional Int per entry), and similar to NO_FREE it's useful in conjunction with HashMaps
/// 															as it allows them to iterate over entries in memory order.
//----------------------------------------------------------------------------------------
template <Int SIZE, typename ARRAYSELECTOR, Bool FLUSH = false, Bool NO_FREE = false, Bool SUPPORT_ITERATOR = false> class ArrayAllocator
{
	struct FreeEntry
	{
		FreeEntry* next = nullptr;
	};

public:
	using ValueType = ArrayAllocatorValueType<SIZE>;
	using ArrayType = typename ARRAYSELECTOR::template Type<ValueType>;

	using IsArrayAllocator = std::true_type;

	/// This indicates if the ArrayAllocator always allows to iterate over all entries which are currently in use.
	static constexpr Bool SUPPORTS_ITERATOR = NO_FREE || SUPPORT_ITERATOR;

	//----------------------------------------------------------------------------------------
	/// Default Constructor.
	//----------------------------------------------------------------------------------------
	ArrayAllocator()
	{
		static_assert(SIZE >= SIZEOF(FreeEntry), "SIZE must at least be big enough to hold a pointer");
	}

	/// Move constructor
	ArrayAllocator(ArrayAllocator&& src) : _usedEntryCnt(src._usedEntryCnt), _freeEntry(src._freeEntry), _buffer(std::move(src._buffer)) 
	{
		src._usedEntryCnt = 0;
		src._freeEntry = nullptr;
	}

	//----------------------------------------------------------------------------------------
	/// Computes the new size for a growing array
	/// THREADSAFE.
	/// @param[in] currentSize				Current number of elements.
	/// @param[in] increment					Number of elements to be added (>= 1)
	/// @param[in] minChunkSize				The minimum number of elements upon array creation.
	/// @return												New number of elements.
	//----------------------------------------------------------------------------------------
	Int ComputeArraySize(Int currentSize, Int increment, Int minChunkSize)
	{
		return DefaultAllocator::ComputeArraySize(currentSize, increment, minChunkSize);
	}

	//----------------------------------------------------------------------------------------
	/// Allocates a memory block.
	/// The memory is not cleared, it may contain a certain byte pattern in debug mode.
	/// @param[in] s									Block size in bytes (values < 0 will return nullptr)
	/// @param[in] allocLocation			Pass MAXON_SOURCE_LOCATION(_NAME) to add the current source line and file.
	/// @return												Memory block address or nullptr.
	//----------------------------------------------------------------------------------------
	void* Alloc(Int64 s, MAXON_SOURCE_LOCATION_DECLARATION)
	{
		DebugAssert(s == SIZE);
		if (s != SIZE)
			return nullptr;
		
		FreeEntry* entry = _freeEntry;
		if (!NO_FREE && entry)
		{
			_freeEntry = entry->next;
#ifdef MAXON_TARGET_DEBUG
			ClearMem(entry, SIZE, 0x6d);
#endif
		}
		else
		{
			entry = reinterpret_cast<FreeEntry*>(_buffer.Append().GetPointer());
		}
		_usedEntryCnt++;

		return entry;
	}

	//----------------------------------------------------------------------------------------
	/// Not supported for this allocator.
	/// @return												Nullptr.
	//----------------------------------------------------------------------------------------
	void* Realloc(void*, Int64, MAXON_SOURCE_LOCATION_DECLARATION)
	{
		return nullptr;
	}

	//----------------------------------------------------------------------------------------
	/// Frees a memory block.
	/// @param[in,out] p							Memory block address (can be nullptr, will be nullptr after return)
	//----------------------------------------------------------------------------------------
	template <typename T> void Free(T*& p)
	{
		static_assert(!NO_FREE, "This allocator doesn't support Free() for individual allocations, only DeleteAll() can be used.");
		FreeEntry* entry = const_cast<FreeEntry*>(reinterpret_cast<const FreeEntry*>(p));
		if (entry)
		{
			_usedEntryCnt--;
			p = nullptr;
#ifdef MAXON_TARGET_DEBUG
			ClearMem(entry, SIZE, 0x6d);
#endif
			entry->next = _freeEntry;
			_freeEntry = entry;

			// Reset the array if no more entries are used
			if (MAXON_UNLIKELY(_usedEntryCnt == 0))
			{
				if constexpr (FLUSH)
					_buffer.Flush();
				else
					_buffer.Reset();
				_freeEntry = nullptr;
			}
		}
	}

	//----------------------------------------------------------------------------------------
	/// Returns if a memory block allocated via this allocator can be reallocated or freed by the DefaultAllocator.
	/// @param[in] p									Memory block address.
	/// @return												True if the memory block can be reallocated or freed by the DefaultAllocator.
	//----------------------------------------------------------------------------------------
	Bool IsCompatibleWithDefaultAllocator(void* p) const
	{
		return false;
	}
	
	ArrayType& GetArray()
	{
		return _buffer;
	}

	const ArrayType& GetArray() const
	{
		return _buffer;
	}

	Bool HasFreedEntries() const
	{
		return !NO_FREE && (_freeEntry != nullptr);
	}

	template <typename T> Bool DeleteAll()
	{
		static_assert(SIZEOF(T) == SIZE);
		if constexpr (!std::is_trivially_destructible<T>::value)
		{
			if (!NO_FREE && _freeEntry)
			{
				// We can't iterate over all entries and destruct them because we don't know which are free and which aren't.
				// Return false, then the caller has to do proper clean-up.
				return false;
			}
			// No unused entry, so we can iterate over all blocks and destruct the elements.
			for (auto& e: _buffer)
			{
				reinterpret_cast<T&>(e).~T();
			}
		}
		_usedEntryCnt = 0;
		_freeEntry = nullptr;
		if constexpr (FLUSH)
			_buffer.Flush();
		else
			_buffer.Reset();
		return true;
	}

	using Iterator = typename ArrayType::Iterator;
	using ConstIterator = typename ArrayType::ConstIterator;

	Iterator Begin()
	{
		static_assert(NO_FREE);
		return _buffer.Begin();
	}

	ConstIterator Begin() const
	{
		static_assert(NO_FREE);
		return _buffer.Begin();
	}

	Iterator End()
	{
		static_assert(NO_FREE);
		return _buffer.End();
	}

	ConstIterator End() const
	{
		static_assert(NO_FREE);
		return _buffer.End();
	}

private:
	Int _usedEntryCnt = 0;
	FreeEntry* _freeEntry = nullptr;
	
	ArrayType _buffer;
};

// Specialization for the SUPPORT_ITERATOR case. We have to maintain a list of those entries which are still in use.
// See documentation of Free function for the internal structure.
template <Int SIZE, typename ARRAYSELECTOR, Bool FLUSH> class ArrayAllocator<SIZE, ARRAYSELECTOR, FLUSH, false, true>
{
public:
	using IsArrayAllocator = std::true_type;

	static constexpr Bool SUPPORTS_ITERATOR = true;

	Int ComputeArraySize(Int currentSize, Int increment, Int minChunkSize)
	{
		return DefaultAllocator::ComputeArraySize(currentSize, increment, minChunkSize);
	}

	void* Alloc(Int64 s, MAXON_SOURCE_LOCATION_DECLARATION)
	{
		DebugAssert(s == SIZE);
		if (s != SIZE)
			return nullptr;

		const Int free = _firstFree;
		if (free < 0)
		{
			// No free element, allocate a new one.
			const Int index = _buffer.GetCount();
			Entry* const newEntry = _buffer.Append().GetPointer();
			if (newEntry)
			{
				newEntry->index = index;
				return &newEntry->value;
			}
			else
			{
				return nullptr;
			}
		}
		else
		{
			// See documentation of Free() about the internal structure.
			FreeEntry& e = _buffer[free].ToFreeEntry();
			Entry* reusedEntry;
			if (e.otherEnd != free)
			{
				// The free region ending at #free has more than one entry. Re-use its first entry.
				DebugAssert(e.otherEnd < free);
				reusedEntry = &_buffer[e.otherEnd];
				reusedEntry->index = e.otherEnd;
				reinterpret_cast<FreeEntry&>(_buffer[++e.otherEnd]).otherEnd = free;
			}
			else
			{
				// This is the only entry of the free region. Re-use it and also remove the region from the chain of free regions.
				const Int nextFree = e.next;
				DebugAssert(nextFree != free);
				reusedEntry = reinterpret_cast<Entry*>(&e);
				reusedEntry->index = free;
				_firstFree = nextFree;
				if (nextFree >= 0)
				{
					DebugAssert(_buffer[nextFree].ToFreeEntry().prev == free);
					_buffer[nextFree].ToFreeEntry().prev = -1;
				}
			}
#ifdef MAXON_TARGET_DEBUG
			ClearMem(&reusedEntry->value, SIZE, 0x6d);
#endif
			return &reusedEntry->value;
		}
	}

	void* Realloc(void*, Int64, MAXON_SOURCE_LOCATION_DECLARATION)
	{
		return nullptr;
	}

	template <typename T> void Free(T*& p)
	{
		// The ArrayAllocator maintains a doubly linked list of free regions (ranges of unused entries in the array buffer).
		// To free the entry at p, we have to either extend an adjacent region to include p, or if there's no adjacent region, to create a new region.
		//
		// Example state of array buffer: XXX = used entry, (N/P/O): free entry with members next, prev, otherEnd (* = don't care)
		// Regions of free entries are represented and linked via their last entry (marked by #), ArrayAllocator::_firstFree points to first free region.
		// For each region, the two entries at its start and end are linked to each other via otherEnd (O).
		//
		// _firstFree:2 -------------.
		//                           |
		//                           V
		//
		// Index         0     1     2     3     4     5     6     7     8     9     10    11    12
		// Free regions      [=======#=]       [=#=]       [=============#=]             [=#=]
		// N/P links                 |<--------->|<--------------------->|<--------------->|
		//                    N:*   N:4         N:8         N:*   N:*   N:11              N:-1
		//              XXX   P:*   P:-1  XXX   P:2   XXX   P:*   P:*   P:4   XXX   XXX   P:8   XXX
		//                    O:2   O:1         O:4         O:8   O:*   O:6               O:11
		// O links             |<--->|           |           |<--------->|                 |
		//
		// In the example, the regions are linked in index order, but usually that's not the case (e.g., _firstFree could point to 11,
		// which could point to 4 etc.).
		Entry* const entry = const_cast<Entry*>(reinterpret_cast<const Entry*>(reinterpret_cast<const Byte*>(p) - offsetof(Entry, value)));
		p = nullptr;
		const Int freeIdx = entry->index;
		entry->index = -1;
#ifdef MAXON_TARGET_DEBUG
		ClearMem(&entry->value, SIZE, 0x6d);
#endif
		DebugAssert(&_buffer[freeIdx] == entry);
		FreeEntry& free = entry->ToFreeEntry();
		const Int cnt = _buffer.GetCount();
		const Int nextIdx = freeIdx + 1;
		const Int prevIdx = freeIdx - 1;
		if (nextIdx < cnt)
		{
			Entry& next = _buffer[nextIdx];
			if (next.IsFree(nextIdx))
			{
				// The entry behind free is the start of a free region (e.g. when freeing entry 0 or 5 in the example).
				const Int endIdx = next.ToFreeEntry().otherEnd;
				FreeEntry& end = _buffer[endIdx].ToFreeEntry();
				DebugAssert(end.otherEnd == nextIdx);
				// Check if the entry before free is the end of a free region (e.g. when freeing entry 5 in the example).
				if (prevIdx >= 0)
				{
					Entry& prev = _buffer[prevIdx];
					if (prev.IsFree(prevIdx))
					{
						// Yes, there's a free region before as well. Merge the two regions.
						const FreeEntry& oldEnd = prev.ToFreeEntry();
						// update O link
						end.otherEnd = oldEnd.otherEnd;
						DebugAssert(_buffer[end.otherEnd].ToFreeEntry().otherEnd == prevIdx);
						_buffer[end.otherEnd].ToFreeEntry().otherEnd = endIdx;
						// remove region of oldEnd from N/P chain
						if (oldEnd.next >= 0)
						{
							DebugAssert(_buffer[oldEnd.next].ToFreeEntry().prev == prevIdx);
							_buffer[oldEnd.next].ToFreeEntry().prev = oldEnd.prev;
						}
						if (oldEnd.prev >= 0)
						{
							DebugAssert(_buffer[oldEnd.prev].ToFreeEntry().next == prevIdx);
							_buffer[oldEnd.prev].ToFreeEntry().next = oldEnd.next;
						}
						else
						{
							_firstFree = oldEnd.next;
						}
						if ((end.otherEnd == 0) && (endIdx == _buffer.GetCount() - 1))
						{
							FlushBuffer();
						}
						return;
					}
				}
				// No adjacent region to the left, simply update the O link to extend the region behind free (e.g. when freeing entry 0 in the example).
				free.otherEnd = endIdx;
				end.otherEnd = freeIdx;
				if ((freeIdx == 0) && (endIdx == _buffer.GetCount() - 1))
				{
					FlushBuffer();
				}
				return;
			}
		}

		// There's no free entry immediately behind free.
		if (prevIdx >= 0)
		{
			Entry& prev = _buffer[prevIdx];
			if (prev.IsFree(prevIdx))
			{
				// The entry before free is the end of a free region (e.g. when freeing entry 9 in the example). Make the current entry the new end of the region.
				free = prev.ToFreeEntry();
				_buffer[free.otherEnd].ToFreeEntry().otherEnd = freeIdx;
				if (free.next >= 0)
				{
					DebugAssert(_buffer[free.next].ToFreeEntry().prev == prevIdx);
					_buffer[free.next].ToFreeEntry().prev = freeIdx;
				}
				if (free.prev >= 0)
				{
					DebugAssert(_buffer[free.prev].ToFreeEntry().next == prevIdx);
					_buffer[free.prev].ToFreeEntry().next = freeIdx;
				}
				else
				{
					_firstFree = freeIdx;
				}
				if ((free.otherEnd == 0) && (freeIdx == _buffer.GetCount() - 1))
				{
					FlushBuffer();
				}
				return;
			}
		}

		// There's no free entry adjacent to free at all. Create a new region.
		if (_firstFree >= 0)
		{
			DebugAssert(_buffer[_firstFree].ToFreeEntry().prev == -1);
			_buffer[_firstFree].ToFreeEntry().prev = freeIdx;
		}
		free.next = _firstFree;
		free.prev = -1;
		free.otherEnd = freeIdx;
		_firstFree = freeIdx;
		if (_buffer.GetCount() == 1)
		{
			FlushBuffer();
		}
	}

	Bool IsCompatibleWithDefaultAllocator(void* p) const
	{
		return false;
	}

	template <typename T> Bool DeleteAll()
	{
		static_assert(SIZEOF(T) == SIZE);
		if constexpr (!std::is_trivially_destructible<T>::value)
		{
			for (ValueType& e : *this)
			{
				reinterpret_cast<T&>(e).~T();
			}
		}
		_firstFree = -1;
		if constexpr (FLUSH)
			_buffer.Flush();
		else
			_buffer.Reset();
		return true;
	}

private:
	using ValueType = ArrayAllocatorValueType<SIZE>;

	// content of freed entries, see documentation of Free() for details
	struct FreeEntry
	{
		// for last entry of a free region: index of last entry of next free region
		Int next;
		// for last entry of a free region: index of last entry of previous free region
		Int prev;
		// for first and last entry of a free region: index of the other end of that region
		Int otherEnd;
	};

	// content of used entries
	struct Entry
	{
		// index of the entry in _buffer
		// If index doesn't match the entry's index, then the entry is a free entry (because then Entry::index is in fact FreeEntry::next
		// which will never be the index of the entry itself, this is used in the iterator to detect if an entry is used or free).
		Int index;
		ValueType value;

		// Check if this entry is free. idx is the index of the entry in _buffer.
		Bool IsFree(Int idx) const
		{
			return index != idx;
		}

		FreeEntry& ToFreeEntry()
		{
			static_assert(SIZEOF(FreeEntry) <= SIZEOF(Entry));
			return *reinterpret_cast<FreeEntry*>(this);
		}

		const FreeEntry& ToFreeEntry() const
		{
			return *reinterpret_cast<const FreeEntry*>(this);
		}
	};

	using ArrayType = typename ARRAYSELECTOR::template Type<Entry>;

public:
	template <Bool CONSTITERATOR> class IteratorTemplate
	{
	public:
		using ValueType = typename ConstIf<ArrayAllocator::ValueType, CONSTITERATOR>::type;
		using ArrayType = typename ConstIf<ArrayAllocator::ArrayType, CONSTITERATOR>::type;
		using EntryType = typename ConstIf<Entry, CONSTITERATOR>::type;
		using ArrayIterator = std::conditional_t<CONSTITERATOR, typename ArrayType::ConstIterator, typename ArrayType::Iterator>;

		IteratorTemplate() = default;

		IteratorTemplate(ArrayType* array, Int index) : _array(array), _index(index)
		{
			Block<EntryType> block;
			const Int blockStart = array->GetBlock(index, block);
			if (block.IsPopulated())
			{
				_ptr = &block[index - blockStart];
				_end = block.End().GetPtr();
				Validate();
			}
		}

		ValueType& operator *() const
		{
			DebugAssert(_ptr->index == _index);
			return _ptr->value;
		}

		ValueType* operator ->() const
		{
			if (MAXON_LIKELY(_ptr))
			{
				DebugAssert(_ptr->index == _index);
				return &_ptr->value;
			}
			else
			{
				return nullptr;
			}
		}

		Bool operator ==(const IteratorTemplate& other) const
		{
			return _index == other._index;
		}

		Bool operator !=(const IteratorTemplate& other) const
		{
			return _index != other._index;
		}

		IteratorTemplate& operator ++()
		{
			++_index;
			++_ptr;
			if (MAXON_UNLIKELY(_ptr == _end))
			{
				Block<EntryType> block;
				const Int blockStart = _array->GetBlock(_index, block);
				if (block.IsEmpty())
				{
					DebugAssert(_index == _array->GetCount());
#ifdef MAXON_TARGET_DEBUG
					_ptr = nullptr;
					_end = nullptr;
#endif
					return *this;
				}
				_ptr = &block[_index - blockStart];
				_end = block.End().GetPtr();
			}
			Validate();
			return *this;
		}

	private:
		void Validate()
		{
			DebugAssert(_ptr < _end);
			const Entry& e = *_ptr;
			if (MAXON_LIKELY(!e.IsFree(_index)))
			{
				return;
			}
			// The entry e has been freed, so this is the start of a region of freed entries.
			// Skip whole region by going one entry behind its end.
			const Int newIndex = e.ToFreeEntry().otherEnd + 1;
			DebugAssert(newIndex > _index);
			_ptr += (newIndex - _index);
			_index = newIndex;
			if (MAXON_LIKELY(_ptr < _end))
			{
				// Still in same block.
				DebugAssert(_ptr->index == newIndex);
				return;
			}
			Block<EntryType> block;
			const Int blockStart = _array->GetBlock(newIndex, block);
			if (MAXON_LIKELY(block.IsPopulated()))
			{
				_ptr = &block[newIndex - blockStart];
				_end = block.End().GetPtr();
				DebugAssert(_ptr->index == newIndex);
			}
			else
			{
#ifdef MAXON_TARGET_DEBUG
				_ptr = nullptr;
				_end = nullptr;
#endif
				DebugAssert(newIndex == _array->GetCount());
			}
		}

		ArrayType* _array;
		Int _index = 0;
		EntryType* _ptr = nullptr;
		EntryType* _end = nullptr;
	};

	using Iterator = IteratorTemplate<false>;
	using ConstIterator = IteratorTemplate<true>;

	Iterator Begin()
	{
		return Iterator{&_buffer, 0};
	}

	ConstIterator Begin() const
	{
		return ConstIterator{&_buffer, 0};
	}

	Iterator End()
	{
		return Iterator{&_buffer, _buffer.GetCount()};
	}

	ConstIterator End() const
	{
		return ConstIterator{&_buffer, _buffer.GetCount()};
	}

private:
	void FlushBuffer()
	{
		// Flush the array if no more entries are used
#ifdef MAXON_TARGET_DEBUG
		DebugAssert(_firstFree == _buffer.GetCount() - 1);
		const FreeEntry& e = _buffer[_firstFree].ToFreeEntry();
		DebugAssert((e.next == -1) && (e.prev == -1) && (e.otherEnd == 0));
#endif
		_firstFree = -1;
		if constexpr (FLUSH)
			_buffer.Flush();
		else
			_buffer.Reset();
	}

	// see documentation of Free()
	ArrayType _buffer;
	Int _firstFree = -1;
};

//----------------------------------------------------------------------------------------
/// BlockArray allocator which only allocates and frees entries of SIZE bytes.
/// @note The entries are guaranteed to keep their address.
/// @tparam SIZE									The size of an entry in bytes.
/// @tparam EXPONENT							Exponent for the BlockArray.
//----------------------------------------------------------------------------------------
template <Int SIZE, Int EXPONENT = BLOCKARRAY_DEFAULT_SIZE_EXPONENT, Bool NO_FREE = false, Bool SUPPORT_ITERATOR = false> class BlockArrayAllocator : public ArrayAllocator<SIZE, BlockArraySelector<EXPONENT, BLOCKARRAYFLAGS::NOINSERTERASE>, false, NO_FREE, SUPPORT_ITERATOR>
{
};

//----------------------------------------------------------------------------------------
/// BaseArray allocator which only allocates and frees entries of SIZE bytes.
/// @note Allocation of a new element might reallocate the buffer and move all existing items to a different address. The caller must only address items by index!
/// @tparam SIZE									The size of an entry in bytes.
//----------------------------------------------------------------------------------------
template <Int SIZE> class BaseArrayAllocator : public ArrayAllocator<SIZE, BaseArraySelector<>>
{
};

//----------------------------------------------------------------------------------------
/// BufferedBaseArray allocator which only allocates and frees entries of SIZE bytes.
/// @note Allocation of a new element might reallocate the buffer and move all existing items to a different address. The caller must only address items by index!
/// @tparam SIZE									The size of an entry in bytes.
/// @tparam CNT										The number of preallocated entries.
//----------------------------------------------------------------------------------------
template <Int SIZE, Int CNT> class BufferedBaseArrayAllocator : public ArrayAllocator<SIZE, BufferedBaseArraySelector<CNT>>
{
};

} // namespace maxon

#endif // ARRAYALLOCATOR_H__
