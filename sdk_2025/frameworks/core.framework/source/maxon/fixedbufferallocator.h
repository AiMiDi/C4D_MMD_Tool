#ifndef FIXEDBUFFERALLOCATOR_H__
#define FIXEDBUFFERALLOCATOR_H__

#include "maxon/apibase.h"

namespace maxon
{

template <Int SIZE, typename PARENT_ALLOCATOR, Bool CHECK_ALLOCATION> struct FixedBufferMemory : public PARENT_ALLOCATOR
{
	explicit FixedBufferMemory(Bool used = false) : memoryUsed(used)
	{
	}

	explicit FixedBufferMemory(const PARENT_ALLOCATOR& a) : memoryUsed(false), PARENT_ALLOCATOR(a)
	{
	}

	void SetMemoryUsed(Bool used)
	{
		DebugAssert(memoryUsed != used);
		memoryUsed = used;
	}
	Bool IsMemoryUsed() const { return memoryUsed; }

	Char buffer[SIZE];
private:
	Bool memoryUsed;
};

template <Int SIZE, typename PARENT_ALLOCATOR> struct FixedBufferMemory<SIZE, PARENT_ALLOCATOR, false> : public PARENT_ALLOCATOR
{
	explicit FixedBufferMemory(Bool used = false)
	{
	}

	explicit FixedBufferMemory(const PARENT_ALLOCATOR& a) : PARENT_ALLOCATOR(a)
	{
	}

	void SetMemoryUsed(Bool used) {}
	Bool IsMemoryUsed() const { return false; }

	Char buffer[SIZE];
};


class FixedBufferAllocatorBase
{
};

//----------------------------------------------------------------------------------------
/// Fixed allocator.
/// A fixed allocator contains 'SIZEOF(T) * COUNT' bytes memory on stack. The first memory request (and any Resize calls) that
/// are smaller than this size will return this static memory. All other requests will be routed to the PARENT_ALLOCATOR.
/// The fixed allocator is not thread-safe!
///
/// Here an example for the use of a fixed allocator:
/// @code
/// BaseArray<Char, 16, BASEARRAYFLAGS::NONE, FixedBufferAllocator<Char, 1024, DefaultAllocator>> buf;
/// @endcode
/// In the example a BaseArray will use the guaranteed 1024 bytes from the stack / fixed allocator first.
/// Only when the BaseArray grows bigger than 1024 characters more memory from the DefaultAllocator will be fetched.
/// This is a convenient way to allow routines be flexible without (length) limits, but avoiding constant unnecessary
/// memory allocations.
///
/// @tparam T											A type for the size computation.
/// @tparam COUNT									Number of T-typed elements to reserve on the stack.
/// @tparam PARENT_ALLOCATOR			The allocator that shall be used when a request cannot be satisfied using the static memory.
/// @tparam SINGLE_ALLOCATION			False by default. True is used by the BaseArray as optimization.
///
//----------------------------------------------------------------------------------------
template <typename T, Int COUNT, typename PARENT_ALLOCATOR, Bool SINGLE_ALLOCATION = false> class FixedBufferAllocator : public FixedBufferAllocatorBase
{
	static const Int SIZE = SIZEOF(T) * COUNT;

public:
	/// Default constructor
	explicit FixedBufferAllocator(Bool used = false) : _memory(used)
	{
	}

	/// Copy constructor
	explicit FixedBufferAllocator(const PARENT_ALLOCATOR& parent) : _memory(parent)
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
	static Int ComputeArraySize(Int currentSize, Int increment, Int minChunkSize)
	{
		// Return at least the buffer capacity.
		if (currentSize + increment <= COUNT)
			return COUNT;
		return PARENT_ALLOCATOR::ComputeArraySize(currentSize, increment, minChunkSize);
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

		if (s <= SIZE)
		{
			if (_memory.IsMemoryUsed() == false)
			{
				_memory.SetMemoryUsed(true);
				return _memory.buffer;
			}
		}
		return _memory.Alloc(s, MAXON_SOURCE_LOCATION_FORWARD);
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
		else if (p == _memory.buffer)
		{
			if (n <= SIZE)
			{
				// Keep using the buffer.
				return p;
			}
			else
			{
				void* mem = _memory.Alloc(n, MAXON_SOURCE_LOCATION_FORWARD);
				if (mem)
				{
					// Copy data from existing buffer.
					MemCopy(mem, p, SIZE);

					// Buffer is free.
					_memory.SetMemoryUsed(false);
				}
				return mem;
			}
		}
		else
		{
			return _memory.Realloc(p, n, MAXON_SOURCE_LOCATION_FORWARD);
		}
	}

	//----------------------------------------------------------------------------------------
	/// Frees a memory block.
	/// @param[in,out] p							Memory block address (can be nullptr, will be nullptr after return)
	//----------------------------------------------------------------------------------------
	template <typename PTRTYPE> void Free(PTRTYPE*& p)
	{
		if ((void*) p == (void*) _memory.buffer)
		{
			_memory.SetMemoryUsed(false);
			p = nullptr;
		}
		else
		{
			_memory.Free(p);
		}
	}

	//----------------------------------------------------------------------------------------
	/// Returns if a memory block allocated via this allocator can be reallocated or freed by the DefaultAllocator.
	/// @param[in] p									Memory block address.
	/// @return												True if the memory block can be reallocated or freed by the DefaultAllocator.
	//----------------------------------------------------------------------------------------
	Bool IsCompatibleWithDefaultAllocator(void* p) const
	{
		if (p == (void*) _memory.buffer)
			return false;
		else
			return _memory.IsCompatibleWithDefaultAllocator(p);
	}

private:
	MAXON_DISALLOW_COPY_AND_ASSIGN(FixedBufferAllocator);

	FixedBufferMemory<SIZE, PARENT_ALLOCATOR, SINGLE_ALLOCATION == false> _memory;
};

} // namespace maxon

#endif // FIXEDBUFFERALLOCATOR_H__
