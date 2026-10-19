#ifndef ALLOCATORREF_H__
#define ALLOCATORREF_H__

#include "maxon/defaultallocator.h"

namespace maxon
{

//----------------------------------------------------------------------------------------
/// An AllocatorRef extends a BaseRef by forwarding all allocator calls (Alloc, Free, ...) to the referenced object.
/// This can be used if a single allocator shall be shared by multiple objects such as arrays or maps,
/// for example AllocatorRef<BlockArrayAllocator<123>> which is a BlockArrayAllocator held by a strong reference.
///
/// AllocatorRef inherits from BaseRef, so all of BaseRef's functions are available in addition to the allocator functions.
///
/// @tparam ALLOCATOR							Type of the referenced allocator.
/// @tparam HANDLER								Reference handler class for BaseRef, StrongRefHandler by default. This implements the specific behaviour whenever the reference is changed to point to another allocator, see BaseRef.
/// @see BaseRef
//----------------------------------------------------------------------------------------
template <typename ALLOCATOR, typename HANDLER = StrongRefHandler> class AllocatorRef : public BaseRef<ALLOCATOR, HANDLER>
{
public:
	using Super = BaseRef<ALLOCATOR, HANDLER>;
	using Super::Super;

	MAXON_ATTRIBUTE_FORCE_INLINE void* Alloc(Int s, MAXON_SOURCE_LOCATION_DECLARATION) const
	{
		ALLOCATOR* a = this->GetPointer();
		return MAXON_LIKELY(a) ? a->Alloc(s, MAXON_SOURCE_LOCATION_FORWARD) : nullptr;
	}

	MAXON_ATTRIBUTE_FORCE_INLINE void* AllocClear(Int s, MAXON_SOURCE_LOCATION_DECLARATION) const
	{
		ALLOCATOR* a = this->GetPointer();
		return MAXON_LIKELY(a) ? a->AllocClear(s, MAXON_SOURCE_LOCATION_FORWARD) : nullptr;
	}
	
	MAXON_ATTRIBUTE_FORCE_INLINE void* Realloc(void* p, Int s, MAXON_SOURCE_LOCATION_DECLARATION) const
	{
		ALLOCATOR* a = this->GetPointer();
		return MAXON_LIKELY(a) ? a->Realloc(p, s, MAXON_SOURCE_LOCATION_FORWARD) : nullptr;
	}

	MAXON_ATTRIBUTE_FORCE_INLINE Int ComputeArraySize(Int currentSize, Int increment, Int minChunkSize) const
	{
		ALLOCATOR* a = this->GetPointer();
		return MAXON_LIKELY(a) ? a->ComputeArraySize(currentSize, increment, minChunkSize) : DefaultAllocator::ComputeArraySize(currentSize, increment, minChunkSize);
	}

	MAXON_ATTRIBUTE_FORCE_INLINE Bool IsCompatibleWithDefaultAllocator(void* p) const
	{
		ALLOCATOR* a = this->GetPointer();
		return a && a->IsCompatibleWithDefaultAllocator(p);
	}

	template <typename T> MAXON_ATTRIBUTE_FORCE_INLINE void Free(T*& p) const
	{
		ALLOCATOR* a = this->GetPointer();
		if (MAXON_LIKELY(a))
		{
			a->Free(p);
		}
	}
};

}

#endif
