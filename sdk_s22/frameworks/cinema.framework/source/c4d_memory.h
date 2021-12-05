/////////////////////////////////////////////////////////////
// Cinema 4D SDK                                           //
/////////////////////////////////////////////////////////////
// (c) MAXON Computer GmbH, all rights reserved            //
/////////////////////////////////////////////////////////////

#ifndef C4D_MEMORY_H__
#define C4D_MEMORY_H__

#ifdef __API_INTERN__
	#include "ge_memory.h"
#else

#include <new>
#if defined MAXON_TARGET_LINUX
	#include <stddef.h>
#endif

#include <string.h>
#include <stdlib.h>
#include "c4d_plugin.h"
#include "operatingsystem.h"
#include "ge_autoptr.h"

//----------------------------------------------------------------------------------------
/// Gets estimated free physical memory.
/// @return												Estimated free physical memory.
//----------------------------------------------------------------------------------------
UInt GeMemGetFreePhysicalMemoryEstimate();

#include "maxon/defaultallocator.h"

#define __C4D_MEM_ALIGNMENT_MASK__ 15	///< Memory returned by NewMem() is guaranteed to be at least aligned to a @em 16 byte boundary.

#ifndef C4D_ALIGN
	#if defined MAXON_TARGET_WINDOWS
		#define C4D_ALIGN(_x_, _a_) __declspec(align(_a_)) _x_
	#else
		#define C4D_ALIGN(_x_, _a_) _x_ __attribute__((aligned(_a_)))
	#endif
#endif

//----------------------------------------------------------------------------------------
/// Clears a block of memory.
/// @param[in] d									Address of the memory block to clear. @callerOwnsPointed{memory}
/// @param[in] size								Size in bytes of the block of memory to clear.
/// @param[in] value							Value to clear the memory block with. Default to @em 0.
//----------------------------------------------------------------------------------------
inline void ClearMem(void* d, Int size, Int32 value = 0)
{
	memset(d, value & 0xFF, size);
}

//----------------------------------------------------------------------------------------
/// Copies a block of memory.
/// @warning Parameters order is the opposite of @c memcpy()
/// @see MemCopy()
/// @param[in] s									Address of the source block of memory. @callerOwnsPointed{memory}
/// @param[out] d									Address of the destination block of memory. @callerOwnsPointed{memory}
/// @param[in] size								Size in bytes of the block of memory to copy.
//----------------------------------------------------------------------------------------
inline void CopyMem(const void* s, void* d, Int size)
{
	if (s && d && size > 0)
		memcpy(d, s, size);
	else
		DebugStop();
}

//----------------------------------------------------------------------------------------
/// Copies a block of memory.
/// @param[out] d									Address of the destination block of memory. @callerOwnsPointed{memory}
/// @param[in] s									Address of the source block of memory. @callerOwnsPointed{memory}
/// @param[in] size								Size in bytes of the block of memory to copy.
//----------------------------------------------------------------------------------------
inline void MemCopy(void* d, const void* s, Int size)
{
	if (s && d && size > 0)
		memcpy(d, s, size);
	else
		DebugStop();
}

//----------------------------------------------------------------------------------------
/// @markInternal
//----------------------------------------------------------------------------------------
template <class T, class U> inline void FillMemTypeTemplate(T* data_ptr, Int size, const U* check_type, Int32 value)
{
#ifdef MAXON_TARGET_DEBUG
	if (check_type != data_ptr) // This will cause a compile time error if the types are different
		return;
#endif

	memset(data_ptr, value, size);
}

//----------------------------------------------------------------------------------------
/// Fills a block of memory of the specified type.
/// @param[in] t									Data type (e.g. Char, Float).
/// @param[out] d									Address of the block of memory to fill. @callerOwnsPointed{memory}
/// @param[in] x									Size of the memory block to fill.
/// @param[in] v									Value to fill the memory block with.
//----------------------------------------------------------------------------------------
#define FillMemType(t, d, x, v) FillMemTypeTemplate(d, sizeof(t) * (x), ((t*) d), v)

//----------------------------------------------------------------------------------------
/// Clears a block of memory.\n
/// THREADSAFE.
/// @param[out] data_ptr					Address of the block of memory to clear. @callerOwnsPointed{memory}
/// @param[in] cnt								Number of elements to be filled with pattern (> @em 1 e.g. for arrays), can be @em 0.
//----------------------------------------------------------------------------------------
template <typename T> inline void ClearMemType(T* data_ptr, Int cnt)
{
	memset(data_ptr, 0, size_t(cnt * sizeof(T)));
}

//----------------------------------------------------------------------------------------
/// Copies a block of memory to another of the same kind.\n
/// THREADSAFE
/// @warning Source and destination must not overlap.
/// @param[in] src_ptr						Address of the source block of memory to copy. @callerOwnsPointed{memory}
/// @param[out] dst_ptr						Address of the destination block of memory to copy to. @callerOwnsPointed{memory}
/// @param[in] cnt								Number of elements to be copied (> @em 1 e.g. for arrays), can be @em 0.
//----------------------------------------------------------------------------------------
template <typename T> inline void CopyMemType(const T* src_ptr, T* dst_ptr, Int cnt)
{
	memcpy(dst_ptr, src_ptr, size_t(cnt * sizeof(T)));
}

#endif

#endif // C4D_MEMORY_H__
