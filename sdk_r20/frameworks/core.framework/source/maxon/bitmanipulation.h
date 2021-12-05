#ifndef BITMANIPULATION_H__
#define BITMANIPULATION_H__

#include "maxon/apibase.h"

#ifdef MAXON_TARGET_WINDOWS
#include <intrin.h>
#endif

namespace maxon
{

/// @addtogroup MATH
/// @{

#if defined(MAXON_COMPILER_CLANG) || defined(MAXON_COMPILER_GCC)

inline Int Clz32(Int32 x)
{
	return x ? __builtin_clz((unsigned int) x) : 32;
}

inline Int Clz64(Int64 x)
{
	return x ? __builtin_clzll((unsigned long long) x) : 64;
}

inline Int Ctz32(Int32 x)
{
	return x ? __builtin_ctz((unsigned int) x) : 0;
}

inline Int Ctz64(Int64 x)
{
	return x ? __builtin_ctzll((unsigned long long) x) : 0;
}

inline Int PopCount(Int32 x)
{
	return __builtin_popcount(x);
}

inline Int PopCount(Int64 x)
{
	return __builtin_popcountll(x);
}

inline Int PopCount(UInt32 x)
{
	return __builtin_popcount(x);
}

inline Int PopCount(UInt64 x)
{
	return __builtin_popcountll(x);
}

#else

inline Int Ctz32(Int32 x)
{
	unsigned long result;
	return _BitScanForward(&result, x) ? result : 0;
}

inline Int Ctz64(Int64 x)
{
	unsigned long result;
	return _BitScanForward64(&result, x) ? result : 0;
}

inline Int Clz32(Int32 x)
{
	unsigned long result;
	return _BitScanReverse(&result, x) ? 31 - result : 32;
}

inline Int Clz64(Int64 x)
{
	unsigned long result;
#ifdef MAXON_TARGET_64BIT
	return _BitScanReverse64(&result, x) ? 63 - result : 64;
#else
	return (x & 0xffffffff00000000LL) ? (_BitScanReverse(&result, (Int32) (x >> 32)), 31 - result) : _BitScanReverse(&result, (Int32) x) ? 63 - result : 64;
#endif
}

/*
	Clz64 implementation in case we need this for some architecture
	if (x == 0)
		return 64;
	Int64 n = 0;
	if ((x & 0xffffffff00000000LL) == 0)
	{
		n += 32;
		x <<= 32;
	}
	if ((x & 0xffff000000000000LL) == 0)
	{
		n += 16;
		x <<= 16;
	}
	if ((x & 0xff00000000000000LL) == 0)
	{
		n += 8;
		x <<= 8;
	}
	if ((x & 0xf000000000000000LL) == 0)
	{
		n += 4;
		x <<= 4;
	}
	if ((x & 0xc000000000000000LL) == 0)
	{
		n += 2;
		x <<= 2;
	}
	if ((x & 0x8000000000000000LL) == 0)
	{
		n += 1;
	}
	return n;
*/

#endif

//----------------------------------------------------------------------------------------
/// Counts the number of leading zero bits of @p x. If @p x is zero, the bit width of @p T is returned.
/// Note that the result depends on the bit width, i.e., Clz((Int16) 0xff) will return 8,
/// while Clz((Int32) 0xff) will return 24.
/// @param[in] x									Value of which leading zero bits shall be counted.
/// @tparam T											Type of @p x, this has to be an integral type.
/// @return												Number of leading zero bits of @p x.
//----------------------------------------------------------------------------------------
template <typename T> inline Int Clz(T x)
{
	static_assert(std::is_integral<T>::value, "Clz can only be used for integral values.");
	return (SIZEOF(T) <= SIZEOF(Int32)) ? Clz32((Int32) (UInt32) (typename std::make_unsigned<T>::type) x) - (SIZEOF(Int32) - SIZEOF(T)) * 8 : Clz64((Int64) x);
}

//----------------------------------------------------------------------------------------
/// Counts the number of trailing zero bits of @p x. If @p x is zero, the 0 is returned.
/// @param[in] x									Value of which trailing zero bits shall be counted.
/// @tparam T											Type of @p x, this has to be an integral type.
/// @return												Number of trailing zero bits of @p x.
//----------------------------------------------------------------------------------------
template <typename T> inline Int Ctz(T x)
{
	static_assert(std::is_integral<T>::value, "Ctz can only be used for integral values.");
	return (SIZEOF(T) <= SIZEOF(Int32)) ? Ctz32((Int32) (UInt32) (typename std::make_unsigned<T>::type) x) : Ctz64((Int64) x);
}

/// @}

} // namespace maxon

#endif // BITMANIPULATION_H__
