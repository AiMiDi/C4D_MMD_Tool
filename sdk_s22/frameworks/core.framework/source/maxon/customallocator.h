#ifndef CUSTOMALLOCATOR_H__
#define CUSTOMALLOCATOR_H__

#include "maxon/interface.h"

namespace maxon
{

/// Custom allocator/memory pool interface
class CustomAllocatorInterface
{
	MAXON_INTERFACE_NONVIRTUAL(CustomAllocatorInterface, MAXON_REFERENCE_NORMAL, "net.maxon.interface.customallocator");

public:
	//----------------------------------------------------------------------------------------
	/// @param[in] allocLocation			Source location.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD CustomAllocatorInterface* Alloc(MAXON_SOURCE_LOCATION_DECLARATION);

	//----------------------------------------------------------------------------------------
	/// Computes the new capacity for a growing array.
	/// THREADSAFE.
	/// @param[in] currentSize				Current number of elements.
	/// @param[in] increment					Number of elements to be added (>= 1)
	/// @param[in] minChunkSize				The minimum number of elements upon array creation.
	/// @return												New capacity (maximum number of elements).
	//----------------------------------------------------------------------------------------
	MAXON_ADD_TO_REFERENCE_CLASS(Int ComputeArraySize(Int currentSize, Int increment, Int minChunkSize) { return DefaultAllocator::ComputeArraySize(currentSize, increment, minChunkSize); });

	//----------------------------------------------------------------------------------------
	/// Allocates a memory block.
	/// THREADSAFE.
	/// The memory is not cleared, it may contain a certain byte pattern in debug mode.
	/// @param[in] s									Block size in bytes (values < 0 will return nullptr)
	/// @param[in] allocLocation			Pass MAXON_SOURCE_LOCATION(_NAME) to add the current source line and file.
	/// @return												Memory block address or nullptr.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD void* Alloc(Int s, MAXON_SOURCE_LOCATION_DECLARATION);

	//----------------------------------------------------------------------------------------
	/// Allocates a memory block and clears it.
	/// THREADSAFE.
	/// @param[in] s									Block size in bytes (values < 0 will return nullptr)
	/// @param[in] allocLocation			Pass MAXON_SOURCE_LOCATION(_NAME) to add the current source line and file.
	/// @return												Memory block address or nullptr.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD void* AllocClear(Int s, MAXON_SOURCE_LOCATION_DECLARATION);

	//----------------------------------------------------------------------------------------
	/// Resizes an allocated memory block. If allocation of a new block fails the old one won't be freed.
	/// @param[in] data								Data location, can be nullptr.
	/// @param[in] size								Minimum new data size (values < 0 will return nullptr).
	/// @param[in] allocLocation			Structure with caller data like source file and source line.
	/// @return												Data pointer or nullptr.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD void*	Realloc(void* data, Int size, MAXON_SOURCE_LOCATION_DECLARATION);

	MAXON_ADD_TO_REFERENCE_CLASS(
	//----------------------------------------------------------------------------------------
	/// Frees a memory block.
	/// THREADSAFE.
	/// @param[in,out] p							Memory block address (can be nullptr, will be nullptr after return)
	//----------------------------------------------------------------------------------------
	template <typename T> void Free(T*& p)
	{
		if (this->GetPointer())
			this->GetPointer()->PrivateFree((void*) p);
		p = nullptr;
	}
	);

	//----------------------------------------------------------------------------------------
	/// Returns if a memory block allocated via this allocator can be reallocated or freed by the DefaultAllocator.
	/// @return												True if the memory block can be reallocated or freed by the DefaultAllocator.
	//----------------------------------------------------------------------------------------
	MAXON_ADD_TO_REFERENCE_CLASS(Bool IsCompatibleWithDefaultAllocator(void*) const { return false; });



	//----------------------------------------------------------------------------------------
	/// Allocates a block of memory.
	/// @param[in] size								Minimum data size (values < 0 will return nullptr).
	/// @param[in] clear							If the data should be cleared this must be true.
	/// @param[in] allocLocation			Structure with caller data like source file and source line.
	/// @return												Data pointer or nullptr.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD void*	PrivateAlloc(Int size, Bool clear, MAXON_SOURCE_LOCATION_DECLARATION);

	//----------------------------------------------------------------------------------------
	/// Frees a memory block (might have been allocated by a different local Allocator of the same type).
	/// @param[in] data								Pointer as returned by Alloc, guaranteed to be valid and not nullptr.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD void PrivateFree(void* data);

	//----------------------------------------------------------------------------------------
	/// Returns the maximum size of an allocated block (might be bigger than what was acutally allocated).
	/// @param[in] data								Pointer as returned by Alloc, guaranteed to be valid and != nullptr.
	/// @return												Block size in bytes (>=allocated size) or 0.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Int PrivateGetDataSize(void* data);

};

// include auto generated header file here
#include "customallocator1.hxx"

// include auto generated header file here
#include "customallocator2.hxx"

} // namespace maxon

#endif // CUSTOMALLOCATOR_H__
