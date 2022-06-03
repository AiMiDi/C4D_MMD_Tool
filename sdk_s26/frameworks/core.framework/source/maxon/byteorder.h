#ifndef BYTEORDER_H__
#define BYTEORDER_H__


#include "maxon/apibase.h"


namespace maxon
{

//----------------------------------------------------------------------------------------
/// The byte order of data type which is longer than one byte.
/// You can use SYSTEM_BYTEORDER to determine the current system byte order.
//----------------------------------------------------------------------------------------
enum class BYTEORDER
{
	BIG			= 1,	///< Big Endian Format, used on Motorola and IBM Processors (e.g. PowerPC)
	LITTLE	= 2		///< Little Endian Format, used on Intel and ARM Processors
} MAXON_ENUM_LIST(BYTEORDER);

//----------------------------------------------------------------------------------------
/// Swaps the memory layout of a value from big to little endian or vice versa.
/// @param[in] data								Value that will be swapped.
/// @return												Swapped value.
//----------------------------------------------------------------------------------------
MAXON_ATTRIBUTE_FORCE_INLINE UInt16	SwapByteOrder(UInt16 data)
{
	return UInt16((data << 8) | (data >> 8));
}
//----------------------------------------------------------------------------------------
/// Swaps the memory layout of a value from big to little endian or vice versa.
/// @param[in] data								Value that will be swapped.
/// @return												Swapped value.
//----------------------------------------------------------------------------------------
MAXON_ATTRIBUTE_FORCE_INLINE Int16 SwapByteOrder(Int16 data)
{
	return (Int16)SwapByteOrder((UInt16)data);
}

//----------------------------------------------------------------------------------------
/// Swaps the memory layout of a value from big to little endian and vice versa.
/// @param[in] data								Value that will be swapped.
/// @return												Swapped value.
//----------------------------------------------------------------------------------------
MAXON_ATTRIBUTE_FORCE_INLINE UInt32	SwapByteOrder(UInt32 data)
{
#if defined(MAXON_COMPILER_CLANG) && defined(MAXON_TARGET_CPU_INTEL)
	return __builtin_bswap32(data);
#elif defined(MAXON_COMPILER_GCC) && defined(MAXON_TARGET_CPU_INTEL)
	__asm__("bswap   %0" : "+r" (data));
	return data;
#elif (MAXON_COMPILER_MSVC >= 1400)
	return _byteswap_ulong(data);
#elif defined(MAXON_COMPILER_INTEL)
	return (UInt32) _bswap((Int32)data);
#else	// fallback for other compilers or architectures
	return (UInt32)((((UInt32)(data) & 0xff000000) >> 24) |
									(((UInt32)(data) & 0x00ff0000) >> 8) |
									(((UInt32)(data) & 0x0000ff00) << 8) |
									(((UInt32)(data) & 0x000000ff) << 24));
#endif
}
//----------------------------------------------------------------------------------------
/// Swaps the memory layout of a value from big to little endian or vice versa.
/// @param[in] data								Value that will be swapped.
/// @return												Swapped value.
//----------------------------------------------------------------------------------------
MAXON_ATTRIBUTE_FORCE_INLINE Int32 SwapByteOrder(Int32 data)
{
	return (Int32)SwapByteOrder((UInt32)data);
}

//----------------------------------------------------------------------------------------
/// Swaps the memory layout of a value from big to little endian and vice versa.
/// @param[in] data								Value that will be swapped.
/// @return												Swapped value.
//----------------------------------------------------------------------------------------
MAXON_ATTRIBUTE_FORCE_INLINE UInt64 SwapByteOrder(UInt64 data)
{
#if defined(MAXON_COMPILER_CLANG) && defined(MAXON_TARGET_CPU_INTEL)
	return __builtin_bswap64(data);
#elif (MAXON_COMPILER_MSVC >= 1400)
	return _byteswap_uint64(data);
#elif defined(MAXON_COMPILER_INTEL)
	return (UInt64) _bswap64((Int64)data);
#else	// fallback for other compilers or architectures
	return (UInt64)((((UInt64)(data) & 0xff00000000000000ULL) >> 56) |
									(((UInt64)(data) & 0x00ff000000000000ULL) >> 40) |
									(((UInt64)(data) & 0x0000ff0000000000ULL) >> 24) |
									(((UInt64)(data) & 0x000000ff00000000ULL) >> 8) |
									(((UInt64)(data) & 0x00000000ff000000ULL) << 8) |
									(((UInt64)(data) & 0x0000000000ff0000ULL) << 24) |
									(((UInt64)(data) & 0x000000000000ff00ULL) << 40) |
									(((UInt64)(data) & 0x00000000000000ffULL) << 56));
#endif
}
//----------------------------------------------------------------------------------------
/// Swaps the memory layout of a value from big to little endian or vice versa.
/// @param[in] data								Value that will be swapped.
/// @return												Swapped value.
//----------------------------------------------------------------------------------------
MAXON_ATTRIBUTE_FORCE_INLINE Int64 SwapByteOrder(Int64 data)
{
	return (Int64)SwapByteOrder((UInt64)data);
}


//----------------------------------------------------------------------------------------
/// Swaps the memory layout of a value from big to little endian or vice versa.
/// @param[in] data								Value that will be swapped.
/// @return												Swapped value.
//----------------------------------------------------------------------------------------
MAXON_ATTRIBUTE_FORCE_INLINE UInt16	SwapUInt16(UInt16 data) { return SwapByteOrder(data); }
//----------------------------------------------------------------------------------------
/// Swaps the memory layout of a value from big to little endian or vice versa.
/// @param[in] data								Value that will be swapped.
/// @return												Swapped value.
//----------------------------------------------------------------------------------------
MAXON_ATTRIBUTE_FORCE_INLINE Int16 SwapInt16(Int16 data) { return SwapByteOrder(data); }
//----------------------------------------------------------------------------------------
/// Swaps the memory layout of a value from big to little endian or vice versa.
/// @param[in] data								Value that will be swapped.
/// @return												Swapped value.
//----------------------------------------------------------------------------------------
MAXON_ATTRIBUTE_FORCE_INLINE UInt32	SwapUInt32(UInt32 data) { return SwapByteOrder(data); }
//----------------------------------------------------------------------------------------
/// Swaps the memory layout of a value from big to little endian or vice versa.
/// @param[in] data								Value that will be swapped.
/// @return												Swapped value.
//----------------------------------------------------------------------------------------
MAXON_ATTRIBUTE_FORCE_INLINE Int32 SwapInt32(Int32 data) { return SwapByteOrder(data); }
//----------------------------------------------------------------------------------------
/// Swaps the memory layout of a value from big to little endian or vice versa.
/// @param[in] data								Value that will be swapped.
/// @return												Swapped value.
//----------------------------------------------------------------------------------------
MAXON_ATTRIBUTE_FORCE_INLINE UInt64	SwapUInt64(UInt64 data) { return SwapByteOrder(data); }
//----------------------------------------------------------------------------------------
/// Swaps the memory layout of a value from big to little endian or vice versa.
/// @param[in] data								Value that will be swapped.
/// @return												Swapped value.
//----------------------------------------------------------------------------------------
MAXON_ATTRIBUTE_FORCE_INLINE Int64 SwapInt64(Int64 data) { return SwapByteOrder(data); }


//----------------------------------------------------------------------------------------
/// Swaps the memory layout of multiple values from big to little endian and vice versa.
/// @param[in] addr								Pointer to elements that will be swapped.
/// @param[in] count							Number of elements that will be swapped.
//----------------------------------------------------------------------------------------
MAXON_ATTRIBUTE_FORCE_INLINE void SwapUInt16(UInt16* addr, Int count = 1)
{
	while (count-- > 0)
	{
		*addr = SwapUInt16(*addr);
		addr++;
	}
}

//----------------------------------------------------------------------------------------
/// Swaps the memory layout of multiple values from big to little endian and vice versa.
/// @param[in] addr								Pointer to elements that will be swapped.
/// @param[in] count							Number of elements that will be swapped.
//----------------------------------------------------------------------------------------
MAXON_ATTRIBUTE_FORCE_INLINE void SwapInt16(Int16* addr, Int count = 1)
{
	while (count-- > 0)
	{
		*addr = SwapInt16(*addr);
		addr++;
	}
}

//----------------------------------------------------------------------------------------
/// Swaps the memory layout of multiple values from big to little endian and vice versa.
/// @param[in] addr								Pointer to elements that will be swapped.
/// @param[in] count							Number of elements that will be swapped.
//----------------------------------------------------------------------------------------
MAXON_ATTRIBUTE_FORCE_INLINE void SwapUInt32(UInt32* addr, Int count = 1)
{
	while (count-- > 0)
	{
		*addr = SwapUInt32(*addr);
		addr++;
	}
}

//----------------------------------------------------------------------------------------
/// Swaps the memory layout of multiple values from big to little endian and vice versa.
/// @param[in] addr								Pointer to elements that will be swapped.
/// @param[in] count							Number of elements that will be swapped.
//----------------------------------------------------------------------------------------
MAXON_ATTRIBUTE_FORCE_INLINE void SwapInt32(Int32* addr, Int count = 1)
{
	while (count-- > 0)
	{
		*addr = SwapInt32(*addr);
		addr++;
	}
}

//----------------------------------------------------------------------------------------
/// Swaps the memory layout of multiple values from big to little endian and vice versa.
/// @param[in] addr								Pointer to elements that will be swapped.
/// @param[in] count							Number of elements that will be swapped.
//----------------------------------------------------------------------------------------
MAXON_ATTRIBUTE_FORCE_INLINE void SwapUInt64(UInt64* addr, Int count = 1)
{
	while (count-- > 0)
	{
		*addr = SwapUInt64(*addr);
		addr++;
	}
}

//----------------------------------------------------------------------------------------
/// Swaps the memory layout of multiple values from big to little endian and vice versa.
/// @param[in] addr								Pointer to elements that will be swapped.
/// @param[in] count							Number of elements that will be swapped.
//----------------------------------------------------------------------------------------
MAXON_ATTRIBUTE_FORCE_INLINE void SwapInt64(Int64* addr, Int count = 1)
{
	while (count-- > 0)
	{
		*addr = SwapInt64(*addr);
		addr++;
	}
}



#if defined(MAXON_TARGET_CPU_PPC) || (defined MAXON_TARGET_MACOS && defined __BIG_ENDIAN__)
	/// Indicates the active byte order on this system.
	const BYTEORDER SYSTEM_BYTEORDER = BYTEORDER::BIG;

	/// Define that indicates the active byte order on this system.
	#define MAXON_BYTEORDER_BIG_ENDIAN
#else
	/// Indicates the active byte order on this system.
	const BYTEORDER SYSTEM_BYTEORDER = BYTEORDER::LITTLE;

	/// Define that indicates the active byte order on this system.
	#define MAXON_BYTEORDER_LITTLE_ENDIAN
#endif

//----------------------------------------------------------------------------------------
/// Converts from a given byte order to the current system's byte order and vice versa.
/// If the byte order matches the system's byte order nothing will be done.
/// @tparam order									Byte order of the data.
/// @param[in] addr								Pointer to the data.
/// @param[in] count							Number of elements.
//----------------------------------------------------------------------------------------
template <BYTEORDER order> MAXON_ATTRIBUTE_FORCE_INLINE void ByteOrder_UInt16(UInt16* addr, Int count = 1)
{
	// check for != because otherwise the intel compiler will prompt warnings
	if (order != SYSTEM_BYTEORDER)
	{
		SwapUInt16(addr, count);
	}
}

//----------------------------------------------------------------------------------------
/// Converts from a given byte order to the current system's byte order and vice versa.
/// If the byte order matches the system's byte order nothing will be done.
/// @tparam order									Byte order of the data.
/// @param[in] addr								Pointer to the data.
/// @param[in] count							Number of elements.
//----------------------------------------------------------------------------------------
template <BYTEORDER order> MAXON_ATTRIBUTE_FORCE_INLINE void ByteOrder_Int16(Int16* addr, Int count = 1)
{
	// check for != because otherwise the intel compiler will prompt warnings
	if (order != SYSTEM_BYTEORDER)
	{
		SwapInt16(addr, count);
	}
}

//----------------------------------------------------------------------------------------
/// Converts from a given byte order to the current system's byte order and vice versa.
/// If the byte order matches the system's byte order nothing will be done.
/// @tparam order									Byte order of the data.
/// @param[in] addr								Pointer to the data.
/// @param[in] count							Number of elements.
//----------------------------------------------------------------------------------------
template <BYTEORDER order> MAXON_ATTRIBUTE_FORCE_INLINE void ByteOrder_UInt32(UInt32* addr, Int count = 1)
{
	// check for != because otherwise the intel compiler will prompt warnings
	if (order != SYSTEM_BYTEORDER)
	{
		SwapUInt32(addr, count);
	}
}

//----------------------------------------------------------------------------------------
/// Converts from a given byte order to the current system's byte order and vice versa.
/// If the byte order matches the system's byte order nothing will be done.
/// @tparam order									Byte order of the data.
/// @param[in] addr								Pointer to the data.
/// @param[in] count							Number of elements.
//----------------------------------------------------------------------------------------
template <BYTEORDER order> MAXON_ATTRIBUTE_FORCE_INLINE void ByteOrder_Int32(Int32* addr, Int count = 1)
{
	// check for != because otherwise the intel compiler will prompt warnings
	if (order != SYSTEM_BYTEORDER)
	{
		SwapInt32(addr, count);
	}
}

//----------------------------------------------------------------------------------------
/// Converts from a given byte order to the current system's byte order and vice versa.
/// If the byte order matches the system's byte order nothing will be done.
/// @tparam order									Byte order of the data.
/// @param[in] addr								Pointer to the data.
/// @param[in] count							Number of elements.
//----------------------------------------------------------------------------------------
template <BYTEORDER order> MAXON_ATTRIBUTE_FORCE_INLINE void ByteOrder_UInt64(UInt64* addr, Int count = 1)
{
	// check for != because otherwise the intel compiler will prompt warnings
	if (order != SYSTEM_BYTEORDER)
	{
		SwapUInt64(addr, count);
	}
}

//----------------------------------------------------------------------------------------
/// Converts from a given byte order to the current system's byte order and vice versa.
/// If the byte order matches the system's byte order nothing will be done.
/// @tparam order									Byte order of the data.
/// @param[in] addr								Pointer to the data.
/// @param[in] count							Number of elements.
//----------------------------------------------------------------------------------------
template <BYTEORDER order> MAXON_ATTRIBUTE_FORCE_INLINE void ByteOrder_Int64(Int64* addr, Int count = 1)
{
	// check for != because otherwise the intel compiler will prompt warnings
	if (order != SYSTEM_BYTEORDER)
	{
		SwapInt64(addr, count);
	}
}

} // namespace maxon

#endif // BYTEORDER_H__
