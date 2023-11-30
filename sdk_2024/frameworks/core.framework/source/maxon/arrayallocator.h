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
/// @tparam ARRAYSELECTOR					Selector for array type to be used as allocator
/// @tparam FLUSH									Use true if Flush() shall be called on the array instead of Reset() when all entries have been freed.
//----------------------------------------------------------------------------------------
template <Int SIZE, typename ARRAYSELECTOR, Bool FLUSH = false> class ArrayAllocator
{
	struct FreeEntry
	{
		FreeEntry* next = nullptr;
	};

public:
	using ValueType = ArrayAllocatorValueType<SIZE>;
	using ArrayType = typename ARRAYSELECTOR::template Type<ValueType>;

	using IsArrayAllocator = std::true_type;

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
		if (s != SIZE)
			return nullptr;
		
		FreeEntry* entry = _freeEntry;
		if (entry)
		{
			_freeEntry = entry->next;
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
	/// @return												nullptr
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
		FreeEntry* entry = const_cast<FreeEntry*>(reinterpret_cast<const FreeEntry*>(p));
		if (entry)
		{
			_usedEntryCnt--;
			p = nullptr;
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

	template <typename T> Bool DeleteAll()
	{
		static_assert(SIZEOF(T) == SIZE);
		if (!std::is_trivially_destructible<T>::value)
		{
			if (_freeEntry)
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

private:	
	Int _usedEntryCnt = 0;
	FreeEntry* _freeEntry = nullptr;
	
	ArrayType _buffer;
};

//----------------------------------------------------------------------------------------
/// BlockArray allocator which only allocates and frees entries of SIZE bytes.
/// @note The entries are guaranteed to keep their address.
/// @tparam SIZE									The size of an entry in bytes.
/// @tparam EXPONENT							Exponent for the BlockArray.
//----------------------------------------------------------------------------------------
template <Int SIZE, Int EXPONENT = BLOCKARRAY_DEFAULT_SIZE_EXPONENT> class BlockArrayAllocator : public ArrayAllocator<SIZE, BlockArraySelector<EXPONENT, BLOCKARRAYFLAGS::NOINSERTERASE>>
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

#endif // BLOCKARRAYALLOCATOR_H__
