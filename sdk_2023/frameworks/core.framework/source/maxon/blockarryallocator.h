#ifndef BLOCKARRAYALLOCATOR_H__
#define BLOCKARRAYALLOCATOR_H__

#include "maxon/blockarray.h"

// TODO: (Sven) rename file

namespace maxon
{

//----------------------------------------------------------------------------------------
/// Array allocator which only allocates and frees entries of SIZE bytes.
/// Depending on the type of array the allocation might relocate already existing items.
/// @tparam SIZE									The size of an entry in bytes.
/// @tparam ARRAY									Array to be used as allocator
//----------------------------------------------------------------------------------------
template <Int SIZE, typename ARRAY> class ArrayAllocator
{
	struct FreeEntry
	{
		FreeEntry* next = nullptr;
	};

public:
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
	
	ARRAY& GetArray()
	{
		return _buffer;
	}

	const ARRAY& GetArray() const
	{
		return _buffer;
	}

private:	
	Int _usedEntryCnt = 0;
	FreeEntry* _freeEntry = nullptr;
	
	ARRAY _buffer;
};

template <Int SIZE> struct ArrayAllocatorValueType
{
	Char data[SIZE];
};

//----------------------------------------------------------------------------------------
/// BlockArray allocator which only allocates and frees entries of SIZE bytes.
/// @note The entries are guaranteed to keep their address.
/// @tparam SIZE									The size of an entry in bytes.
/// @tparam EXPONENT							Exponent for the BlockArray.
//----------------------------------------------------------------------------------------
template <Int SIZE, Int EXPONENT = BLOCKARRAY_DEFAULT_SIZE_EXPONENT> class BlockArrayAllocator : public ArrayAllocator<SIZE, BlockArray<ArrayAllocatorValueType<SIZE>, EXPONENT, BLOCKARRAYFLAGS::NOINSERTERASE>>
{
public:
	using ValueType = ArrayAllocatorValueType<SIZE>;
};

//----------------------------------------------------------------------------------------
/// BaseArray allocator which only allocates and frees entries of SIZE bytes.
/// @note Allocation of a new element might reallocate the buffer and move all existing items to a different address. The caller must only address items by index!
/// @tparam SIZE									The size of an entry in bytes.
//----------------------------------------------------------------------------------------
template <Int SIZE> class BaseArrayAllocator : public ArrayAllocator<SIZE, BaseArray<ArrayAllocatorValueType<SIZE>>>
{
public:
	using ValueType = ArrayAllocatorValueType<SIZE>;
};

//----------------------------------------------------------------------------------------
/// BufferedBaseArray allocator which only allocates and frees entries of SIZE bytes.
/// @note Allocation of a new element might reallocate the buffer and move all existing items to a different address. The caller must only address items by index!
/// @tparam SIZE									The size of an entry in bytes.
/// @tparam CNT										The number of preallocated entries.
//----------------------------------------------------------------------------------------
template <Int SIZE, Int CNT> class BufferedBaseArrayAllocator : public ArrayAllocator<SIZE, BufferedBaseArray<ArrayAllocatorValueType<SIZE>, CNT>>
{
public:
	using ValueType = ArrayAllocatorValueType<SIZE>;
};

} // namespace maxon

#endif // BLOCKARRAYALLOCATOR_H__
