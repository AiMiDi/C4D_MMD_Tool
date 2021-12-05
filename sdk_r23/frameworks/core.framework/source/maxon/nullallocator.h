#ifndef NULLALLOCATOR_H__
#define NULLALLOCATOR_H__

#include "maxon/apibase.h"
#include "maxon/defaultallocator.h"

namespace maxon
{

//----------------------------------------------------------------------------------------
/// The Null allocator is an allocator that returns no memory, no matter what memory size was requested.
/// It can be used, e.g. in combination with the class FixedBufferAllocator.
/// THREADSAFE.
//----------------------------------------------------------------------------------------
class NullAllocator
{
public:
	//----------------------------------------------------------------------------------------
	/// Computes the new size for a growing array, same as in DefaultAllocator
	/// THREADSAFE.
	//----------------------------------------------------------------------------------------
	static Int ComputeArraySize(Int currentSize, Int increment, Int MINCHUNKSIZE)
	{
		return DefaultAllocator::ComputeArraySize(currentSize, increment, MINCHUNKSIZE);
	}

	//----------------------------------------------------------------------------------------
	/// 'Fakes' allocate memory
	/// THREADSAFE.
	/// @param[in] s									Block size in bytes.
	/// @param[in] allocLocation			Pass MAXON_SOURCE_LOCATION(_NAME) to add the current source line and file.
	/// @return												Nullptr.
	//----------------------------------------------------------------------------------------
	static MAXON_ATTRIBUTE_FORCE_INLINE void* Alloc(Int32 s, MAXON_SOURCE_LOCATION_DECLARATION)
	{
		return nullptr;
	}

	//----------------------------------------------------------------------------------------
	/// 'Fakes' allocate memory
	/// THREADSAFE.
	/// @param[in] s									Block size in bytes.
	/// @param[in] allocLocation			Pass MAXON_SOURCE_LOCATION(_NAME) to add the current source line and file.
	/// @return												Nullptr.
	//----------------------------------------------------------------------------------------
	static MAXON_ATTRIBUTE_FORCE_INLINE void* Alloc(Int64 s, MAXON_SOURCE_LOCATION_DECLARATION)
	{
		return nullptr;
	}

	//----------------------------------------------------------------------------------------
	/// 'Fakes' resize memory
	/// THREADSAFE.
	/// @param[in] p									Current memory block (can be nullptr)
	/// @param[in] n									New block size in bytes (values < 0 will return nullptr)
	/// @param[in] allocLocation			Pass MAXON_SOURCE_LOCATION(_NAME) to add the current source line and file.
	/// @return												Nullptr.
	//----------------------------------------------------------------------------------------
	static MAXON_ATTRIBUTE_FORCE_INLINE void* Realloc(void* p, Int32 n, MAXON_SOURCE_LOCATION_DECLARATION)
	{
		return nullptr;
	}

	//----------------------------------------------------------------------------------------
	/// 'Fakes' resize memory
	/// THREADSAFE.
	/// @param[in] p									Current memory block (can be nullptr)
	/// @param[in] n									New block size in bytes (values < 0 will return nullptr)
	/// @param[in] allocLocation			Pass MAXON_SOURCE_LOCATION(_NAME) to add the current source line and file.
	/// @return												Nullptr.
	//----------------------------------------------------------------------------------------
	static MAXON_ATTRIBUTE_FORCE_INLINE void* Realloc(void* p, Int64 n, MAXON_SOURCE_LOCATION_DECLARATION)
	{
		return nullptr;
	}

	//----------------------------------------------------------------------------------------
	/// 'Fakes' free a memory block
	/// THREADSAFE.
	/// @param[in,out] p							Memory block address (can be nullptr, will be nullptr after return)
	//----------------------------------------------------------------------------------------
	template <typename T> static MAXON_ATTRIBUTE_FORCE_INLINE void Free(T*& p)
	{
		p = nullptr;
	}

	//----------------------------------------------------------------------------------------
	/// Returns if a memory block allocated via this allocator can be reallocated or freed by the DefaultAllocator.
	/// @return												Always true.
	//----------------------------------------------------------------------------------------
	static MAXON_ATTRIBUTE_FORCE_INLINE Bool IsCompatibleWithDefaultAllocator(void*)
	{
		return true;
	}
};

} // namespace maxon

#endif // NULLALLOCATOR_H__
