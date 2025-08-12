#ifndef LEGACYHASH_H__
#define LEGACYHASH_H__

#include "maxon/apibase.h"

namespace maxon
{

#define PRIVATE_MAXON_HASHCODE1(m1) maxon::LegacyHash::GetHashCode(m1)
#define PRIVATE_MAXON_HASHCODE2(m1, m2) (PRIVATE_MAXON_HASHCODE1(m1) * 31 + maxon::LegacyHash::GetHashCode(m2))
#define PRIVATE_MAXON_HASHCODE3(m1, m2, m3) (PRIVATE_MAXON_HASHCODE2(m1, m2) * 31 + maxon::LegacyHash::GetHashCode(m3))
#define PRIVATE_MAXON_HASHCODE4(m1, m2, m3, m4) (PRIVATE_MAXON_HASHCODE3(m1, m2, m3) * 31 + maxon::LegacyHash::GetHashCode(m4))
#define PRIVATE_MAXON_HASHCODE5(m1, m2, m3, m4, m5) (PRIVATE_MAXON_HASHCODE4(m1, m2, m3, m4) * 31 + maxon::LegacyHash::GetHashCode(m5))
#define PRIVATE_MAXON_HASHCODE6(m1, m2, m3, m4, m5, m6) (PRIVATE_MAXON_HASHCODE5(m1, m2, m3, m4, m5) * 31 + maxon::LegacyHash::GetHashCode(m6))
#define PRIVATE_MAXON_HASHCODE7(m1, m2, m3, m4, m5, m6, m7) (PRIVATE_MAXON_HASHCODE6(m1, m2, m3, m4, m5, m6) * 31 + maxon::LegacyHash::GetHashCode(m7))
#define PRIVATE_MAXON_HASHCODE8(m1, m2, m3, m4, m5, m6, m7, m8) (PRIVATE_MAXON_HASHCODE7(m1, m2, m3, m4, m5, m6, m7) * 31 + maxon::LegacyHash::GetHashCode(m8))
#define PRIVATE_MAXON_HASHCODE9(m1, m2, m3, m4, m5, m6, m7, m8, m9) (PRIVATE_MAXON_HASHCODE8(m1, m2, m3, m4, m5, m6, m7, m8) * 31 + maxon::LegacyHash::GetHashCode(m9))
#define PRIVATE_MAXON_HASHCODE10(m1, m2, m3, m4, m5, m6, m7, m8, m9, m10) (PRIVATE_MAXON_HASHCODE9(m1, m2, m3, m4, m5, m6, m7, m8, m9) * 31 + maxon::LegacyHash::GetHashCode(m10))
#define PRIVATE_MAXON_HASHCODE11(m1, m2, m3, m4, m5, m6, m7, m8, m9, m10, m11) (PRIVATE_MAXON_HASHCODE10(m1, m2, m3, m4, m5, m6, m7, m8, m9, m10) * 31 + maxon::LegacyHash::GetHashCode(m11))
#define PRIVATE_MAXON_HASHCODE12(m1, m2, m3, m4, m5, m6, m7, m8, m9, m10, m11, m12) (PRIVATE_MAXON_HASHCODE11(m1, m2, m3, m4, m5, m6, m7, m8, m9, m10, m11) * 31 + maxon::LegacyHash::GetHashCode(m12))
#define PRIVATE_MAXON_HASHCODE13(m1, m2, m3, m4, m5, m6, m7, m8, m9, m10, m11, m12, m13) (PRIVATE_MAXON_HASHCODE12(m1, m2, m3, m4, m5, m6, m7, m8, m9, m10, m11, m12) * 31 + maxon::LegacyHash::GetHashCode(m13))
#define PRIVATE_MAXON_HASHCODE14(m1, m2, m3, m4, m5, m6, m7, m8, m9, m10, m11, m12, m13, m14) (PRIVATE_MAXON_HASHCODE13(m1, m2, m3, m4, m5, m6, m7, m8, m9, m10, m11, m12, m13) * 31 + maxon::LegacyHash::GetHashCode(m14))
#define PRIVATE_MAXON_HASHCODE15(m1, m2, m3, m4, m5, m6, m7, m8, m9, m10, m11, m12, m13, m14, m15) (PRIVATE_MAXON_HASHCODE14(m1, m2, m3, m4, m5, m6, m7, m8, m9, m10, m11, m12, m13, m14) * 31 + maxon::LegacyHash::GetHashCode(m15))
#define PRIVATE_MAXON_HASHCODE_C(count, ...) MAXON_EXPAND(PRIVATE_MAXON_HASHCODE##count(__VA_ARGS__))
#define PRIVATE_MAXON_HASHCODE_B(count, ...) PRIVATE_MAXON_HASHCODE_C(count, __VA_ARGS__)
#define PRIVATE_MAXON_HASHCODE_A(count, ...) PRIVATE_MAXON_HASHCODE_B(count, __VA_ARGS__)

#define MAXON_HASHCODE_LEGACY(...) PRIVATE_MAXON_HASHCODE_A(MAXON_VA_NARGS(__VA_ARGS__), __VA_ARGS__)

struct LegacyHash : public DefaultCompare
{
#ifdef MAXON_TARGET_64BIT
	static MAXON_ATTRIBUTE_FORCE_INLINE UInt GetHashCode(UInt32 i)
	{
		UInt h = i;
		h ^= (h >> 20) ^ (h >> 12);
		return h ^ (h >> 7) ^ (h >> 4);
	}

	static MAXON_ATTRIBUTE_FORCE_INLINE UInt GetHashCode(UInt64 h)
	{
		h ^= h >> 32;
		h ^= (h >> 20) ^ (h >> 12);
		return h ^ (h >> 7) ^ (h >> 4);
	}
#else
	static MAXON_ATTRIBUTE_FORCE_INLINE UInt GetHashCode(UInt32 h)
	{
		h ^= (h >> 20) ^ (h >> 12);
		return h ^ (h >> 7) ^ (h >> 4);
	}

	static MAXON_ATTRIBUTE_FORCE_INLINE UInt GetHashCode(UInt64 h)
	{
		return GetHashCode((UInt32) (h ^ (h >> 32)));
	}
#endif
	static MAXON_ATTRIBUTE_FORCE_INLINE UInt GetHashCode(Bool i)
	{
		return GetHashCode((UInt32) i);
	}

	static MAXON_ATTRIBUTE_FORCE_INLINE UInt GetHashCode(Char i)
	{
		return GetHashCode((UInt32) i);
	}

	static MAXON_ATTRIBUTE_FORCE_INLINE UInt GetHashCode(UChar i)
	{
		return GetHashCode((UInt32) i);
	}

	static MAXON_ATTRIBUTE_FORCE_INLINE UInt GetHashCode(Int16 i)
	{
		return GetHashCode((UInt32) i);
	}

	static MAXON_ATTRIBUTE_FORCE_INLINE UInt GetHashCode(UInt16 i)
	{
		return GetHashCode((UInt32) i);
	}

	static MAXON_ATTRIBUTE_FORCE_INLINE UInt GetHashCode(Int32 h)
	{
		return GetHashCode((UInt32) h);
	}

	static UInt GetHashCode(Utf16Char i)
	{
		return GetHashCode((UInt16)i);
	}

	static UInt GetHashCode(Utf32Char i)
	{
		return GetHashCode((UInt32)i);
	}

	static MAXON_ATTRIBUTE_FORCE_INLINE UInt GetHashCode(Int64 h)
	{
		return GetHashCode((UInt64) h);
	}

	static MAXON_ATTRIBUTE_FORCE_INLINE UInt GetHashCode(Float32 h)
	{
		return GetHashCode(*(UInt32*) &h);
	}

	static MAXON_ATTRIBUTE_FORCE_INLINE UInt GetHashCode(Float64 h)
	{
		return GetHashCode(*(UInt64*) &h);
	}

	template <typename T> static MAXON_ATTRIBUTE_FORCE_INLINE UInt GetHashCode(const T* key)
	{
		return GetHashCode((UInt) key);
	}

	template <typename T> static MAXON_ATTRIBUTE_FORCE_INLINE UInt GetHashCode(T* key)
	{
		return GetHashCode((UInt) key);
	}

	static MAXON_ATTRIBUTE_FORCE_INLINE UInt GetHashCode(std::nullptr_t)
	{
		return GetHashCode(static_cast<void*>(nullptr));
	}

	static MAXON_ATTRIBUTE_FORCE_INLINE UInt GetHashCode(const Tuple<Int, Int>& tuple)
	{
		return MAXON_HASHCODE_LEGACY(tuple.first, tuple.second);
	}
};

}

#endif
