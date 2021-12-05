#ifndef BLOCKBUFFERALLOCATOR_H__
#define BLOCKBUFFERALLOCATOR_H__

#include "maxon/apibase.h"
#include "maxon/defaultallocator.h"

namespace maxon
{

//----------------------------------------------------------------------------------------
/// Block buffer allocator.
/// A fixed allocator which contains the size of the initialized memoryblock/size. The first memory request (and any Resize calls)
/// that are smaller than this size will return this static memory. All other requests will be routed to the PARENT_ALLOCATOR.
/// The BlockBufferAllocator is not thread-safe!
///
/// Here an example for the use of a BlockBufferAllocator:
/// @code
/// StringEncodingRef utf8encoder = StringEncodings::Get(Id("utf8"));
/// BaseArray<Char, 16, BASEARRAYFLAGS::NONE, BlockBufferAllocator<NullAllocator>> dstArray(BlockBufferAllocator<NullAllocator>(block.GetFirst(), block.GetCount()));
/// dstArray.EnsureCapacity(block.GetCount(), true);
/// iferr (utf8encoder.EncodeString(_txt, dstArray))
/// {
/// }
/// @endcode
/// In the example a BaseArray will use the guaranteed 1024 bytes from the stack / fixed allocator first.
/// Only when the BaseArray grows bigger than 1024 characters more memory from the DefaultAllocator will be fetched.
/// This is a convenient way to allow routines be flexible without (length) limits, but avoiding constant unnecessary
/// memory allocations.
///
/// @tparam PARENT_ALLOCATOR			The allocator that shall be used when a request cannot be satisfied using the static memory.
///
//----------------------------------------------------------------------------------------
template <typename PARENT_ALLOCATOR> class BlockBufferAllocator
{
	/// Default constructor, disabled because the pointer and size is needed
	BlockBufferAllocator() : _memoryBuffer(nullptr), _memBlockSize(0), _memoryUsed(false)
	{
	}

public:
	//----------------------------------------------------------------------------------------
	/// Constructor, with the given memory block.
	/// @param[in] memoryBuffer				Pointer to memory that is mapped to the allocator.
	/// @param[in] memBlockSize				Size of the memory block.
	//----------------------------------------------------------------------------------------
	BlockBufferAllocator(void* memoryBuffer, Int memBlockSize) : _memoryBuffer(memoryBuffer), _memBlockSize(memBlockSize), _memoryUsed(false)
	{
	}

	/// Copy constructor
	explicit BlockBufferAllocator(const BlockBufferAllocator& parent) : _memoryBuffer(parent._memoryBuffer), _memBlockSize(parent._memBlockSize), _memoryUsed(false), _allocator(parent._allocator)
	{
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
		Int defaultSize = PARENT_ALLOCATOR::ComputeArraySize(currentSize, increment, minChunkSize);

		if (currentSize + increment <= _memBlockSize && defaultSize > _memBlockSize)
			defaultSize = _memBlockSize;

		return defaultSize;
	}

	//----------------------------------------------------------------------------------------
	/// Allocates a memory block.
	/// The memory is not cleared, it may contain a certain byte pattern in debug mode.
	/// @param[in] s									Block size in bytes (values < 0 will return nullptr)
	/// @param[in] allocLocation			Pass MAXON_SOURCE_LOCATION(_NAME) to add the current source line and file.
	/// @return												Memory block address or nullptr.
	//----------------------------------------------------------------------------------------
	void* Alloc(Int32 s, MAXON_SOURCE_LOCATION_DECLARATION)
	{
		return Alloc(Int64(s), MAXON_SOURCE_LOCATION_FORWARD);
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
		// Check for overflow in 32 bit versions.
		if (s != Int(s))
			return nullptr;

		if (!_memoryUsed && (s <= _memBlockSize))
		{
			_memoryUsed = true;
			return _memoryBuffer;
		}
		return _allocator.Alloc(s, MAXON_SOURCE_LOCATION_FORWARD);
	}

	//----------------------------------------------------------------------------------------
	/// Resizes a memory block.
	/// The content of the memory block is preserved up to the lesser of the new and old sizes, even if the block is moved to a new location.
	/// The additional memory is not cleared, it may contain a certain byte pattern in debug mode.
	/// In case that p is a nullptr the function behaves like Alloc.
	/// If the function fails to allocate the requested block of memory a nullptr is returned and the memory block
	/// pointed to by argument p is not deallocated (it is still valid with its contents unchanged).
	/// THREADSAFE.
	/// @param[in] p									Current memory block (can be nullptr)
	/// @param[in] n									New block size in bytes (values < 0 will return nullptr)
	/// @param[in] allocLocation			Pass MAXON_SOURCE_LOCATION(_NAME) to add the current source line and file.
	/// @return												Memory block address or nullptr if resize is not possible (p is still valid in this case)
	//----------------------------------------------------------------------------------------
	void* Realloc(void* p, Int32 n, MAXON_SOURCE_LOCATION_DECLARATION)
	{
		return Realloc(p, Int64(n), MAXON_SOURCE_LOCATION_FORWARD);
	}

	//----------------------------------------------------------------------------------------
	/// Resizes a memory block.
	/// The content of the memory block is preserved up to the lesser of the new and old sizes, even if the block is moved to a new location.
	/// The additional memory is not cleared, it may contain a certain byte pattern in debug mode.
	/// In case that p is a nullptr the function behaves like Alloc.
	/// If the function fails to allocate the requested block of memory a nullptr is returned and the memory block
	/// pointed to by argument p is not deallocated (it is still valid with its contents unchanged).
	/// THREADSAFE.
	/// @param[in] p									Current memory block (can be nullptr)
	/// @param[in] n									New block size in bytes (values < 0 will return nullptr)
	/// @param[in] allocLocation			Pass MAXON_SOURCE_LOCATION(_NAME) to add the current source line and file.
	/// @return												Memory block address or nullptr if resize is not possible (p is still valid in this case)
	//----------------------------------------------------------------------------------------
	void* Realloc(void* p, Int64 n, MAXON_SOURCE_LOCATION_DECLARATION)
	{
		// Check for overflow in 32 bit versions.
		if (n != Int(n))
			return nullptr;

		if (p == nullptr)
		{
			return Alloc(n, MAXON_SOURCE_LOCATION_FORWARD);
		}
		else if (p == _memoryBuffer)
		{
			DebugAssert(_memoryUsed);

			if (n <= _memBlockSize)
			{
				return p;
			}
			else
			{
				void* mem = Alloc(n, MAXON_SOURCE_LOCATION_FORWARD);
				if (mem)
				{
					// Copy data from existing buffer.
					MemCopy(mem, p, _memBlockSize);

					// Buffer is free.
					_memoryUsed = false;
				}
				return mem;
			}
		}
		else
		{
			return _allocator.Realloc(p, n, MAXON_SOURCE_LOCATION_FORWARD);
		}
	}

	//----------------------------------------------------------------------------------------
	/// Frees a memory block.
	/// @param[in,out] p							Memory block address (can be nullptr, will be nullptr after return)
	//----------------------------------------------------------------------------------------
	template <typename T> void Free(T*& p)
	{
		if (p == _memoryBuffer)
		{
			DebugAssert(_memoryUsed || p != nullptr);
			_memoryUsed = false;
			p = nullptr;
		}
		else
		{
			_allocator.Free(p);
		}
	}

	//----------------------------------------------------------------------------------------
	/// Returns if a memory block allocated via this allocator can be reallocated or freed by the DefaultAllocator.
	/// @param[in] p									Memory block address.
	/// @return												True if the memory block can be reallocated or freed by the DefaultAllocator.
	//----------------------------------------------------------------------------------------
	Bool IsCompatibleWithDefaultAllocator(void* p) const
	{
		if (p == (void*) _memoryBuffer)
			return false;
		else
			return _allocator.IsCompatibleWithDefaultAllocator(p);
	}

private:
	void*							_memoryBuffer;
	Int								_memBlockSize;
	Bool							_memoryUsed;
	PARENT_ALLOCATOR	_allocator;
};

} // namespace maxon

#endif // BLOCKBUFFERALLOCATOR_H__
