#ifndef DEFAULTALLOCATOR_H__
#define DEFAULTALLOCATOR_H__

#include <string.h>
#include "maxon/apibase.h"
#include "maxon/system.h"

/// @file

namespace maxon
{

//----------------------------------------------------------------------------------------
/// Default implementation of an allocator.
/// An allocator is used by arrays, lists and other data structurs to allocate and release
/// memory. By default this implementation of an allocator is used.
///
/// The DefaultAllocator guarantees that allocations of at least 64 bytes will have a 64
/// byte alignment (cache line). Smaller allocations of at least 32 bytes have an AVX-safe
/// alignment. Everything smaller has at least an SSE-safe 16 byte alignment.
///
/// There might be rare cases when you need a special memory alignment, a different resize
/// strategy or have to use a special memory area (stack, shared memory, ...). This can be
/// done by writing a custom allocator and specifying it as parameter upon array construction.
/// A custom allocator must implement the ComputeArraySize(), Alloc(), AllocClear(), Realloc()
/// and Free() methods, but it doesn't (and usually shouldn't) inherit from DefaultAllocator.
/// The allocator methods don't have to be static if your allocator requires member
/// variables, but the DefaultAllocator doesn't and therefore uses static methods for
/// better performance.
///
/// Please note that an allocator is copied upon array construction - it would be
/// a bad idea if your custom allocator object would consist of more than a few variables.
///
/// THREADSAFE.
//----------------------------------------------------------------------------------------
class DefaultAllocator
{
public:
	// For allocations of at least 64 bytes a 64 byte aligment (cache line size) is guaranteed.
	// For smaller allocation allocations of at least 32 bytes a 32 byte aligment (compatible with AVX) is guaranteed.
	// For very small allocations (< ALIGNMENT) at least 16 byte alignment is guaranteed.
	static const UInt ALIGNMENT = 64;
	static const UInt ALIGNMENT_MASK = 63;
	static const UInt MIN_ALIGNMENT_MASK = 15;

	//----------------------------------------------------------------------------------------
	/// Computes the new capacity for a growing array.
	/// THREADSAFE.
	/// @param[in] currentSize				Current number of elements.
	/// @param[in] increment					Number of elements to be added (>= 1)
	/// @param[in] minChunkSize				The minimum number of elements upon array creation.
	/// @return												New capacity (maximum number of elements).
	//----------------------------------------------------------------------------------------
	static Int ComputeArraySize(Int currentSize, Int increment, Int minChunkSize)
	{
		// Increase required size by 50 % for future allocations if the array was not empty yet
		Int newSize = currentSize ? (currentSize + increment) * 3 / 2 : increment;
		Int remainder = newSize % minChunkSize;
		if (remainder || newSize == 0)
			newSize += minChunkSize - remainder;

		return newSize;
	}

	//----------------------------------------------------------------------------------------
	/// Allocates a memory block.
	/// THREADSAFE.
	/// The memory is not cleared, it may contain a certain byte pattern in debug mode.
	/// @param[in] s									Block size in bytes (values < 0 will return nullptr)
	/// @param[in] allocLocation			Pass MAXON_SOURCE_LOCATION(_NAME) to add the current source line and file.
	/// @return												Memory block address or nullptr.
	//----------------------------------------------------------------------------------------
	static MAXON_ATTRIBUTE_FORCE_INLINE void* Alloc(Int32 s, MAXON_SOURCE_LOCATION_DECLARATION)
	{
		return System::Alloc(s, MAXON_SOURCE_LOCATION_FORWARD);
	}

	//----------------------------------------------------------------------------------------
	/// Allocates a memory block.
	/// THREADSAFE.
	/// The memory is not cleared, it may contain a certain byte pattern in debug mode.
	/// @param[in] s									Block size in bytes (values < 0 will return nullptr)
	/// @param[in] allocLocation			Pass MAXON_SOURCE_LOCATION(_NAME) to add the current source line and file.
	/// @return												Memory block address or nullptr.
	//----------------------------------------------------------------------------------------
	static MAXON_ATTRIBUTE_FORCE_INLINE void* Alloc(Int64 s, MAXON_SOURCE_LOCATION_DECLARATION)
	{
		if (s != Int(s))
		{
			DebugStop();
			return nullptr;
		}
		return System::Alloc(Int(s), MAXON_SOURCE_LOCATION_FORWARD);
	}

	//----------------------------------------------------------------------------------------
	/// Allocates a memory block and clears it.
	/// THREADSAFE.
	/// @param[in] s									Block size in bytes (values < 0 will return nullptr)
	/// @param[in] allocLocation			Pass MAXON_SOURCE_LOCATION(_NAME) to add the current source line and file.
	/// @return												Memory block address or nullptr.
	//----------------------------------------------------------------------------------------
	static MAXON_ATTRIBUTE_FORCE_INLINE void* AllocClear(Int32 s, MAXON_SOURCE_LOCATION_DECLARATION)
	{
		return System::AllocClear(s, MAXON_SOURCE_LOCATION_FORWARD);
	}

	//----------------------------------------------------------------------------------------
	/// Allocates a memory block and clears it.
	/// THREADSAFE.
	/// @param[in] s									Block size in bytes (values < 0 will return nullptr)
	/// @param[in] allocLocation			Pass MAXON_SOURCE_LOCATION(_NAME) to add the current source line and file.
	/// @return												Memory block address or nullptr.
	//----------------------------------------------------------------------------------------
	static MAXON_ATTRIBUTE_FORCE_INLINE void* AllocClear(Int64 s, MAXON_SOURCE_LOCATION_DECLARATION)
	{
		if (s != Int(s))
		{
			DebugStop();
			return nullptr;
		}
		return System::AllocClear(Int(s), MAXON_SOURCE_LOCATION_FORWARD);
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
	static MAXON_ATTRIBUTE_FORCE_INLINE void* Realloc(void* p, Int32 n, MAXON_SOURCE_LOCATION_DECLARATION)
	{
		return System::Realloc(p, n, MAXON_SOURCE_LOCATION_FORWARD);
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
	static MAXON_ATTRIBUTE_FORCE_INLINE void* Realloc(void* p, Int64 n, MAXON_SOURCE_LOCATION_DECLARATION)
	{
		if (n != Int(n))
		{
			DebugStop();
			return nullptr;
		}
		return System::Realloc(p, Int(n), MAXON_SOURCE_LOCATION_FORWARD);
	}

	//----------------------------------------------------------------------------------------
	/// Frees a memory block.
	/// THREADSAFE.
	/// @param[in,out] p							Memory block address (can be nullptr, will be nullptr after return)
	//----------------------------------------------------------------------------------------
	template <typename T> static MAXON_ATTRIBUTE_FORCE_INLINE void Free(T*& p)
	{
		System::Free((void*) p);
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

//----------------------------------------------------------------------------------------
/// Allocates raw memory: no constructors are called!
/// A valid memory address will be returned if cnt is 0 (unless there was not enough memory).
/// @note This behaviour was different in Cinema 4D where nullptr was returned.
/// THREADSAFE.
/// @param[in] T									Type of item (e.g. Char, Float)
/// @param[in] cnt								Number of items.
/// @return												Pointer to memory block or nullptr.
//----------------------------------------------------------------------------------------
#define NewMem(T, cnt) maxon::ResultPtr<T>((T*) maxon::DefaultAllocator::Alloc(maxon::Int64(SIZEOF(T)) * maxon::Int64((cnt)), MAXON_SOURCE_LOCATION_NAME(T)))

//----------------------------------------------------------------------------------------
/// Allocates raw memory and clears it: no constructors are called!
/// THREADSAFE.
/// @param[in] T									Type of item (e.g. Char, Float)
/// @param[in] cnt								Number of items.
/// @return												Pointer to memory block or nullptr.
//----------------------------------------------------------------------------------------
#define NewMemClear(T, cnt) maxon::ResultPtr<T>((T*) maxon::DefaultAllocator::AllocClear(maxon::Int64(SIZEOF(T)) * maxon::Int64((cnt)), MAXON_SOURCE_LOCATION_NAME(T)))

//----------------------------------------------------------------------------------------
/// Resizes a raw memory block : no constructors are called!
/// The content of the memory block is preserved up to the lesser of the new and old sizes, even if the block is moved to a new location.
/// The additional memory is not cleared, it may contain a certain byte pattern in debug mode.
/// In case that p is a nullptr the function behaves like NewMem.
/// If the function fails to allocate the requested block of memory a nullptr is returned and the memory block
/// pointed to by argument p is not deallocated (it is still valid with its contents unchanged).
/// THREADSAFE.
/// @param[in] p									Current memory block (can be nullptr)
/// @param[in] cnt								New number of items (size of the memory block is n * sizeof(T))
/// @param[in] allocLocation			Pass MAXON_SOURCE_LOCATION(_NAME) to add the current source line and file.
/// @return												Memory block address or nullptr if resize is not possible (p is still valid in this case)
//----------------------------------------------------------------------------------------
template <typename T> MAXON_ATTRIBUTE_FORCE_INLINE ResultPtr<T> _ReallocMem(T* p, Int cnt, MAXON_SOURCE_LOCATION_DECLARATION)
{
	Int64	size = SIZEOF(T) * Int64(cnt);

#ifndef MAXON_TARGET_64BIT
	if (size > LIMIT<Int32>::MAX)	// overflow?
	{
		DebugStop();
		return nullptr;
	}
#endif

	return (T*) DefaultAllocator::Realloc(p, Int(size), MAXON_SOURCE_LOCATION_FORWARD);
}

//----------------------------------------------------------------------------------------
/// Resizes a raw memory block : no constructors are called!
/// The content of the memory block is preserved up to the lesser of the new and old sizes, even if the block is moved to a new location.
/// The additional memory is not cleared, it may contain a certain byte pattern in debug mode.
/// In case that p is a nullptr the function behaves like NewMem.
/// If the function fails to allocate the requested block of memory a nullptr is returned and the memory block
/// pointed to by argument p is not deallocated (it is still valid with its contents unchanged).
/// THREADSAFE.
/// @param[in] p									Current memory block (can be nullptr)
/// @param[in] cnt								New number of items (size of the memory block is n * sizeof(T))
/// @return												Memory block address or nullptr if resize is not possible (p is still valid in this case)
//----------------------------------------------------------------------------------------
#define ReallocMem(p, cnt) _ReallocMem(p, cnt, MAXON_SOURCE_LOCATION_NAME(decltype(p)))

//----------------------------------------------------------------------------------------
/// Frees a raw memory block: no destructors are called!
/// THREADSAFE.
/// @param[in] p									Memory block (can be nullptr, will be nullptr after return)
//----------------------------------------------------------------------------------------
#ifdef USE_API_MAXON
// For c4d modules we must use a define because otherwise DeleteMem calls from inside and outside the maxon namespace result in compile errors.
#define DeleteMem(p) (maxon::DefaultAllocator::Free(p))
#else
template <typename T> inline void DeleteMem(T*& p)
{
	DefaultAllocator::Free(p);
}
#endif

//----------------------------------------------------------------------------------------
/// Frees a raw memory block: no destructors are called!
/// Normally you should use DeleteMemj(). This variant should be used only in the rare case
/// when the object pointer is a constant so that it can't be set to nullptr.
/// THREADSAFE.
/// @param[in] p									Memory block (can be nullptr).
//----------------------------------------------------------------------------------------
inline void DeleteConstPtrMem(const void* p)
{
	DefaultAllocator::Free(p);
}


//----------------------------------------------------------------------------------------
/// Copies raw memory if size >0; source and destination pointers are tested against nullptr
/// source and destination memory must not overlap
/// THREADSAFE.
/// @param[out] dst								Memory destination.
/// @param[in] src								Memory source.
/// @param[in] size								Number of bytes to be copied.
//----------------------------------------------------------------------------------------
MAXON_ATTRIBUTE_FORCE_INLINE void MemCopy(void* dst, const void* src, Int size)
{
	if (!dst || !src || size <= 0)
		return;
	memcpy(dst, src, (size_t) size);
}

//----------------------------------------------------------------------------------------
/// Moves raw memory if size >0; source and destination pointers are tested against nullptr
/// source and destination memory may overlap
/// THREADSAFE.
/// @param[out] dst								Memory destination.
/// @param[in] src								Memory source.
/// @param[in] size								Number of bytes to be moved.
//----------------------------------------------------------------------------------------
MAXON_ATTRIBUTE_FORCE_INLINE void MemMove(void* dst, const void* src, Int size)
{
	if (!dst || !src || size <= 0)
		return;
	memmove(dst, src, (size_t) size);
}

//----------------------------------------------------------------------------------------
/// Copies the content of a datatype to another of the same kind
/// source and destination memory must not overlap
/// THREADSAFE.
/// @param[out] dst								Destination address of datatype.
/// @param[in] src								Source address of datatype.
/// @param[in] cnt								Number of elements to be copied (>1 e.g. for arrays), can be 0.
//----------------------------------------------------------------------------------------
template <typename T> MAXON_ATTRIBUTE_FORCE_INLINE void MemCopyType(T* dst, const T* src, Int cnt)
{
	::memcpy(dst, src, size_t(cnt * SIZEOF(T)));
}

//----------------------------------------------------------------------------------------
/// Moves the content of a datatype to another of the same kind
/// source and destination memory may overlap
/// THREADSAFE.
/// @param[out] dst								Destination address of datatype.
/// @param[in] src								Source address of datatype.
/// @param[in] cnt								Number of elements to be copied (>1 e.g. for arrays), can be 0.
//----------------------------------------------------------------------------------------
template <typename T> MAXON_ATTRIBUTE_FORCE_INLINE void MemMoveType(T* dst, const T* src, Int cnt)
{
	::memmove(dst, src, size_t(cnt * SIZEOF(T)));
}

//----------------------------------------------------------------------------------------
/// Clears memory with pattern, if size >0.
/// THREADSAFE.
/// @param[out] mem								Memory.
/// @param[in] size								Number of bytes to be filled with pattern, must be greater or equal to 0.
/// @param[in] value							Optional, 1-byte value defining the pattern (default: 0)
//----------------------------------------------------------------------------------------
MAXON_ATTRIBUTE_FORCE_INLINE void ClearMem(void* mem, Int size, UChar value = 0)
{
	memset(mem, (int) value, (size_t) size);
}

//----------------------------------------------------------------------------------------
/// Clears memory with pattern, if size >0. The compiler might remove calls to ClearMem during optimization when the memory is not read from afterwards.
/// To securely clear the memory block use SecureClearMem.
/// THREADSAFE.
/// @param[out] mem								Memory.
/// @param[in] size								Number of bytes to be filled with pattern, must be greater or equal to 0.
/// @param[in] value							Optional, 1-byte value defining the pattern (default: 0)
//----------------------------------------------------------------------------------------
MAXON_ATTRIBUTE_FORCE_INLINE void SecureClearMem(volatile void* mem, Int size, UChar value = 0)
{
	volatile UChar* p = (volatile UChar*)mem;
	while (size--)
		*p++ = value;
}

//----------------------------------------------------------------------------------------
/// Compares two memory blocks
/// THREADSAFE.
/// @param[in] block1							Address of first memory block.
/// @param[in] block2							Address of second memory block.
/// @param[in] size								Number of bytes to compare, must be greater or equal to 0.
/// @return												Zero, if the memory blocks match, or a value different from zero representing which is greater if they do not.
//----------------------------------------------------------------------------------------
MAXON_ATTRIBUTE_FORCE_INLINE Int CompareMem(const void* block1, const void* block2, Int size)
{
	return memcmp(block1, block2, (size_t) size);
}

//----------------------------------------------------------------------------------------
/// Clears memory of a datatype with pattern, if size >0.
/// THREADSAFE.
/// @param[out] data_ptr					Address of the datatype.
/// @param[in] cnt								Number of elements t be filled with pattern (>1 e.g. for arrays), can be 0.
/// @param[in] value							(optional) fill value.
//----------------------------------------------------------------------------------------
template <typename T> MAXON_ATTRIBUTE_FORCE_INLINE void ClearMemType(T* data_ptr, Int cnt, UChar value = 0)
{
	::memset(data_ptr, value, size_t(cnt) * sizeof(T));
}

// Late implementation for UniqueRefHandler because it requires DeleteObj.
template <typename T> void UniqueRefHandler::RemoveReference(const T* o) { DeleteObj(o); }

// Specialization for RawMem which doesn't invoke the destructor of T.
template <typename T, typename H> ResultMemT<BaseRef<RawMem<T>, H>> BaseRef<RawMem<T>, H>::Create(Int cnt)
{
	return BaseRef<RawMem<T>, H>(NewMem(T, cnt).GetPointer());
}


// This function has been moved to defaultallocator.h so that delegate.h doesn't have to include defaultallocator.h
template <typename T> inline Int DelegateBase::UtilityStub(DelegateBase* dst, const DelegateBase* src, CALLBACKMODE mode)
{
	switch (mode)
	{
		case CALLBACKMODE::ALLOC:
		{
			if (SIZEOF(T) > SIZEOF(_storage))
			{
				dst->_objectPtr = (T*) DefaultAllocator::Alloc(SIZEOF(T), MAXON_SOURCE_LOCATION);
				if (dst->_objectPtr == nullptr)
					return 0;
			}
			else
			{
				// This shouldn't happen as the internal storage is sufficient.
				DebugStop("Wrong CALLBACKMODE.");
			}

			break;
		}
		case CALLBACKMODE::DESTRUCT_AND_RELEASE:
		{
			// Destruct the object.
			if (SIZEOF(T) > SIZEOF(_storage))
			{
				T* objectPtr = reinterpret_cast<T*>(dst->_objectPtr);
				objectPtr->~T();
				DeleteMem(objectPtr);
			}
			else
			{
				reinterpret_cast<T&>(dst->_storage[0]).~T();
			}

			break;
		}
		case CALLBACKMODE::COPY:
		{
			if (SIZEOF(T) > SIZEOF(_storage))
			{
				T* objectPtr = (T*) DefaultAllocator::Alloc(SIZEOF(T), MAXON_SOURCE_LOCATION);
				if (objectPtr == nullptr)
					return 0;

				dst->_objectPtr = objectPtr;
				const T& srcObject = *static_cast<T*>(src->_objectPtr);
				if (NewCopy(*objectPtr, srcObject) == FAILED)
				{
					// Free allocated memory.
					DeleteMem(dst->_objectPtr);

					return 0;
				}
			}
			else
			{
				dst->_objectPtr = &dst->_storage[0];
				if (NewCopy(reinterpret_cast<T&>(dst->_storage[0]), reinterpret_cast<const T&>(src->_storage[0])) == FAILED)
				{
					return 0;
				}
			}

			break;
		}
		case CALLBACKMODE::MOVE_AND_DESTRUCT:
		{
			if (SIZEOF(T) <= SIZEOF(_storage))
			{
				T& srcObject = const_cast<T&>(reinterpret_cast<const T&>(src->_storage[0]));
				dst->_objectPtr = &dst->_storage[0];
				new (dst->_objectPtr) T(std::move(srcObject));
				srcObject.~T();
			}

			break;
		}
	}

	return SIZEOF(T);
}

template <> struct IsZeroInitialized<DefaultAllocator> : public std::true_type { };

} // namespace maxon

#endif // DEFAULTALLOCATOR_H__
