#ifndef CSTDLIBALLOCATOR_H__
#define CSTDLIBALLOCATOR_H__

#include <stdlib.h>
#include "maxon/defaultallocator.h"

/// @file

namespace maxon
{

//----------------------------------------------------------------------------------------
/// C stdlib memory allocator.
/// This allocator forwards all requests to malloc(), realloc() and free(). It is much
/// slower than the DefaultAllocator and should only be used, if your code requires memory
/// directly from the C stdlib.
///
/// THREADSAFE.
//----------------------------------------------------------------------------------------
class CStdLibAllocator
{
public:
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
		return DefaultAllocator::ComputeArraySize(currentSize, increment, minChunkSize);
	}

	//----------------------------------------------------------------------------------------
	/// Allocates a memory block.
	/// The memory is not cleared, it may contain a certain byte pattern in debug mode
	/// THREADSAFE.
	/// @param[in] s									Block size in bytes (values < 0 will return nullptr)
	/// @param[in] allocLocation			Pass MAXON_SOURCE_LOCATION(_NAME) to add the current source line and file.
	/// @return												Memory block address or nullptr.
	//----------------------------------------------------------------------------------------
	static void* Alloc(Int32 s, MAXON_SOURCE_LOCATION_DECLARATION)
	{
		return malloc(size_t(s));
	}

	//----------------------------------------------------------------------------------------
	/// Allocates a memory block.
	/// The memory is not cleared, it may contain a certain byte pattern in debug mode
	/// THREADSAFE.
	/// @param[in] s									Block size in bytes (values < 0 will return nullptr)
	/// @param[in] allocLocation			Pass MAXON_SOURCE_LOCATION(_NAME) to add the current source line and file.
	/// @return												Memory block address or nullptr.
	//----------------------------------------------------------------------------------------
	static void* Alloc(Int64 s, MAXON_SOURCE_LOCATION_DECLARATION)
	{
		if (s != Int(s))
		{
			DebugStop();
			return nullptr;
		}
		return malloc(size_t(s));
	}

	//----------------------------------------------------------------------------------------
	/// Allocates a memory block and clears it
	/// THREADSAFE.
	/// @param[in] s									Block size in bytes (values < 0 will return nullptr)
	/// @param[in] allocLocation			Pass MAXON_SOURCE_LOCATION(_NAME) to add the current source line and file.
	/// @return												Memory block address or nullptr.
	//----------------------------------------------------------------------------------------
	static inline void* AllocClear(Int32 s, MAXON_SOURCE_LOCATION_DECLARATION)
	{
		return calloc(1, (size_t) s);
	}

	//----------------------------------------------------------------------------------------
	/// Allocates a memory block and clears it
	/// THREADSAFE.
	/// @param[in] s									Block size in bytes (values < 0 will return nullptr)
	/// @param[in] allocLocation			Pass MAXON_SOURCE_LOCATION(_NAME) to add the current source line and file.
	/// @return												Memory block address or nullptr.
	//----------------------------------------------------------------------------------------
	static inline void* AllocClear(Int64 s, MAXON_SOURCE_LOCATION_DECLARATION)
	{
		if (s != Int(s))
		{
			DebugStop();
			return nullptr;
		}
		return calloc(1, (size_t) s);
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
	static void* Realloc(void* p, Int32 n, MAXON_SOURCE_LOCATION_DECLARATION)
	{
		return realloc(p, size_t(n));
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
	static void* Realloc(void* p, Int64 n, MAXON_SOURCE_LOCATION_DECLARATION)
	{
		if (n != Int(n))
		{
			DebugStop();
			return nullptr;
		}
		return realloc(p, size_t(n));
	}

	//----------------------------------------------------------------------------------------
	/// Frees a memory block.
	/// THREADSAFE.
	/// @param[in,out] p							Memory block address (can be nullptr, will be nullptr after return)
	//----------------------------------------------------------------------------------------
	template <typename T> static inline void  Free(T*& p)
	{
		if (p)
		{
			free((void*) p); // we need a cast here if T is const
			p = nullptr;
		}
	}

	//----------------------------------------------------------------------------------------
	/// Returns if a memory block allocated via this allocator can be reallocated or freed by the DefaultAllocator.
	/// @return												Always false.
	//----------------------------------------------------------------------------------------
	static Bool IsCompatibleWithDefaultAllocator(void*)
	{
		return false;
	}
};

} // namespace maxon

#endif // CSTDLIBALLOCATOR_H__
