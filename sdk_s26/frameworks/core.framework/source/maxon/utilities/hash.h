#ifndef HASH_H__
#define HASH_H__

#ifndef APIBASE_H__
	#error "Do not include this file directly"
#endif

namespace maxon
{

struct DefaultHash
{
	using ValueType = HashInt;

	static constexpr UInt32 Mix(UInt32 h)
	{
		h ^= (h >> 20) ^ (h >> 12);
		return h ^ (h >> 7) ^ (h >> 4);
	}

	static constexpr UInt64 Mix(UInt64 h)
	{
		h ^= h >> 32;
		h ^= (h >> 20) ^ (h >> 12);
		return h ^ (h >> 7) ^ (h >> 4);
	}

	static constexpr HashInt SplitMix(HashInt value)
	{
		// see https://nullprogram.com/blog/2018/07/31/
#ifdef MAXON_TARGET_64BIT
		// SplitMix64 algorithm
		value = (value ^ (value >> 30)) * UINT64_C(0xbf58476d1ce4e5b9);
		value = (value ^ (value >> 27)) * UINT64_C(0x94d049bb133111eb);
		return value ^ (value >> 31);
#else
		value = (value ^ (value >> 16)) * UINT32_C(0x7feb352d);
		value = (value ^ (value >> 15)) * UINT32_C(0x846ca68b);
		return value ^ (value >> 16);
#endif
	}

	// This shall be the hashcode of empty collections/cow objects.
	static constexpr HashInt EMPTY_HASH = 0;

	HashInt state;

	MAXON_IMPLICIT DefaultHash(HashInt start = EMPTY_HASH) : state(start)
	{
	}

	//----------------------------------------------------------------------------------------
	/// Combines the given value with the current state in an ordered way, which means that
	/// the effect of multiple calls to Combine does depend on the order of those calls.
	/// You can use this function to compute a hash value of a sequence of HashInts when the
	/// sequence order is important.
	/// @param[in] value							A hash value.
	//----------------------------------------------------------------------------------------
	void Combine(HashInt value)
	{
		// +1 so that sequences of zero hash codes don't end up in 0.
		state = UINT64_C(0xbf58476d1ce4e5b9) * state + value + 1;
	}

	//----------------------------------------------------------------------------------------
	/// Combines the given value with the current state in an unordered way, which means that
	/// the effect of multiple calls to CombineUnordered doesn't depend on the order of those calls.
	/// You can use this function to compute a hash value of a sequence of HashInts when the
	/// sequence order shall be irrelevant.
	/// @param[in] value							A hash value.
	//----------------------------------------------------------------------------------------
	void CombineUnordered(HashInt value)
	{
		// SplitMix defends against hash values which only use the lower bits (which are OK for hash tables but not OK when they are added for an order-independent set).
		// +1 prevents the issue that 0 is mapped to 0 by SplitMix.
		state += SplitMix(value) + 1;
	}

	operator HashInt() const
	{
		return state;
	}

	template <typename... R> static HashInt CombineHashes(HashInt first, R... rest)
	{
		DefaultHash hash{first};
		CombineHashesImpl(hash, rest...);
		return hash;
	}

private:
	static void CombineHashesImpl(DefaultHash& hash)
	{
	}

	template <typename... R> static void CombineHashesImpl(DefaultHash& hash, HashInt x, R... rest)
	{
		hash.Combine(x);
		CombineHashesImpl(hash, rest...);
	}
};


struct FNV1aHash
{
	using ValueType = HashInt;

#ifdef MAXON_TARGET_64BIT
	static constexpr HashInt PRIME = UINT64_C(1099511628211);
	static constexpr HashInt BASIS = UINT64_C(14695981039346656037);
#else
	static constexpr HashInt PRIME = UINT32_C(16777619);
	static constexpr HashInt BASIS = UINT32_C(2166136261);
#endif

	HashInt state = BASIS;

	void Combine(Char c)
	{
		state = (state ^ UChar(c)) * PRIME;
	}

	void Combine(UChar c)
	{
		state = (state ^ c) * PRIME;
	}

	void Combine(Utf16Char c)
	{
		state = (state ^ UInt16(c)) * PRIME;
	}

	void Combine(Utf32Char c)
	{
		state = (state ^ UInt32(c)) * PRIME;
	}

	operator HashInt() const
	{
		return DefaultHash::Mix(state);
	}
};

} // namespace maxon

#endif // HASH_H__
