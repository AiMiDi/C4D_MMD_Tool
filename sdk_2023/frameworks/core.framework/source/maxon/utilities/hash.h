#ifndef HASH_H__
#define HASH_H__

#ifndef APIBASE_H__
	#error "Do not include this file directly"
#endif

namespace maxon
{

class DefaultHasher
{
public:
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

	MAXON_IMPLICIT DefaultHasher(HashInt start = EMPTY_HASH) : _state(start)
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
		_state = UINT64_C(0xbf58476d1ce4e5b9) * _state + value + 1;
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
		_state += SplitMix(value) + 1;
	}

	HashInt Finalize() const
	{
		return _state;
	}

	operator HashInt() const
	{
		return _state;
	}

	template <typename... R> static HashInt CombineHashes(HashInt first, R... rest)
	{
		DefaultHasher hash{first};
		CombineHashesImpl(hash, rest...);
		return hash;
	}

private:
	static void CombineHashesImpl(DefaultHasher& hash)
	{
	}

	template <typename... R> static void CombineHashesImpl(DefaultHasher& hash, HashInt x, R... rest)
	{
		hash.Combine(x);
		CombineHashesImpl(hash, rest...);
	}

	HashInt _state;
};


class FNV1aHasher
{
public:
	using ValueType = HashInt;

#ifdef MAXON_TARGET_64BIT
	static constexpr HashInt PRIME = UINT64_C(1099511628211);
	static constexpr HashInt BASIS = UINT64_C(14695981039346656037);
#else
	static constexpr HashInt PRIME = UINT32_C(16777619);
	static constexpr HashInt BASIS = UINT32_C(2166136261);
#endif

	void Combine(Char c)
	{
		_state = (_state ^ UChar(c)) * PRIME;
	}

	void Combine(UChar c)
	{
		_state = (_state ^ c) * PRIME;
	}

	void Combine(Utf16Char c)
	{
		_state = (_state ^ UInt16(c)) * PRIME;
	}

	void Combine(Utf32Char c)
	{
		_state = (_state ^ UInt32(c)) * PRIME;
	}

	HashInt Finalize() const
	{
		return _state;
	}

	operator HashInt() const
	{
		return DefaultHasher::Mix(_state);
	}

	void AddHash(HashInt hash)
	{
		_state += hash;
	}

private:
	HashInt _state = BASIS;
};


//----------------------------------------------------------------------------------------
/// UniqueHash is used as return type of GetUniqueHashCode functions. It has a size of 128 bits.
/// For reasonable hash code functions it's a practically safe assumption that there are no hash collisions,
/// so one can consider such a hash to be unique.
//----------------------------------------------------------------------------------------
struct UniqueHash
{
	/// The lower 64 bits of the UniqueHash.
	UInt64 low = 0;

	/// The higher 64 bits of the UniqueHash.
	UInt64 high = 0;

	static constexpr Bool TriviallyHashable() { return true; }

	UniqueHash() = default;
	constexpr UniqueHash(UInt64 l, UInt64 h) : low(l), high(h) { }

	Bool operator ==(const UniqueHash& other) const
	{
		return low == other.low && high == other.high;
	}

	Bool operator !=(const UniqueHash& other) const
	{
		return !this->operator ==(other);
	}

	Bool operator <(const UniqueHash& other) const
	{
		return high < other.high || (high == other.high && low < other.low);
	}

	MAXON_OPERATOR_INEQUALITY(UniqueHash);

	HashInt GetHashCode() const
	{
		static_assert(std::is_same<UInt64, HashInt>::value);
		return DefaultHasher::CombineHashes(low, high);
	}

	const UniqueHash& GetUniqueHashCode() const
	{
		return *this;
	}

	//----------------------------------------------------------------------------------------
	/// Returns the bitwise and of the low bits of this UniqueHash and the given mask.
	/// @param[in] mask								A bit mask.
	/// @return												Bitwise and of low bits and mask.
	//----------------------------------------------------------------------------------------
	constexpr UInt operator &(UInt mask) const
	{
		return UInt(low) & mask;
	}

	//----------------------------------------------------------------------------------------
	/// Combines the other UniqueHash with this UniqueHash in an unordered way, which means that
	/// the effect of multiple calls to CombineUnordered doesn't depend on the order of those calls.
	/// You can use this function to compute a UniqueHash of a sequence of UniqueHashes when the
	/// sequence order shall be irrelevant.
	/// @param[in] other							Another UniqueHash.
	//----------------------------------------------------------------------------------------
	void CombineUnordered(const UniqueHash& other)
	{
		low += other.low + UINT64_C(0xd6e8feb86659fd93);
		high += other.high + UINT64_C(0x133111eb94d049bb);
	}

	//----------------------------------------------------------------------------------------
	/// Returns a 128-bit hash value of the given block of bytes.
	/// @param[in] ptr								Pointer to the first byte.
	/// @param[in] count							Number of bytes.
	/// @return												A hash value for the block of bytes.
	//----------------------------------------------------------------------------------------
	static inline UniqueHash GetUniqueHashCode(const Byte* ptr, Int count);

	//----------------------------------------------------------------------------------------
	/// Returns a 128-bit hash value of the given block of bytes.
	/// @param[in] bytes							Byte block.
	/// @return												A hash value for the block of bytes.
	//----------------------------------------------------------------------------------------
	static inline UniqueHash GetUniqueHashCode(const Block<const Byte>& bytes);

	//----------------------------------------------------------------------------------------
	/// Computes a UniqueHash from a sequence of hash values.
	/// @param[in] hashes							A sequence of @ref UniqueHash "hash values".
	/// @return												A single hash value for the sequence of hash values.
	//----------------------------------------------------------------------------------------
	template <typename... H> static UniqueHash CombineHashes(const H&... hashes)
	{
		// SFINAEHelper is needed because Block is incomplete at this point.
		return typename SFINAEHelper<Block<const UniqueHash>, H...>::type({hashes...}).GetUniqueHashCode();
	}
};


class DefaultCompare;

//----------------------------------------------------------------------------------------
/// UniqueHasher allows to compute a 128-bit UniqueHash from a sequence of values.
/// The values are passed to the hasher using a series of calls to Combine() functions.
/// At the end, the Finalize() function returns the final hash value.
///
/// Computing the hash value through a series of calls is slower than a one-shot computation
/// of a single byte block using UniqueHash::GetUniqueHashCode(). For better performance,
/// you should prefer the one-shot computation if possible.
//----------------------------------------------------------------------------------------
class alignas(64) UniqueHasher
{
public:
	using ValueType = UniqueHash;

	inline UniqueHasher();

	//----------------------------------------------------------------------------------------
	/// Mixes the contents of the given byte block into the hasher state.
	/// @param[in] bytes							A hash value.
	//----------------------------------------------------------------------------------------
	inline void Combine(const Block<const Byte>& bytes);

	//----------------------------------------------------------------------------------------
	/// Mixes the contents of the given byte block into the hasher state.
	/// @param[in] ptr								Pointer to the first byte.
	/// @param[in] count							Number of bytes.
	//----------------------------------------------------------------------------------------
	inline void Combine(const Byte* ptr, Int count);

	//----------------------------------------------------------------------------------------
	/// Mixes the given UniqueHash into the hasher state.
	/// @param[in] value							A hash value.
	//----------------------------------------------------------------------------------------
	inline void Combine(const UniqueHash& value);

	//----------------------------------------------------------------------------------------
	/// Mixes a hash value of the given value into the hasher state.
	/// If value's type T is @ref IsTriviallyHashable "trivially hashable",
	/// the raw bytes of value are used for mixing. Otherwise the hash value returned by
	/// @c{HASH::GetUniqueHashCode(value)} is used.
	/// @param[in] value							A hash value.
	//----------------------------------------------------------------------------------------
	template <typename HASH = DefaultCompare, typename T> void CombineHash(const T& value)
	{
		if (IsTriviallyHashable<T>::value)
		{
			Combine(reinterpret_cast<const Byte*>(&value), SIZEOF(T));
		}
		else
		{
			Combine(HASH::GetUniqueHashCode(value));
		}
	}

	//----------------------------------------------------------------------------------------
	/// Computes a UniqueHash from the current state of this hasher. The hasher can
	/// still be used to hash further bytes afterwards, and Finalize() can be called
	/// multiple times.
	/// @return												A hash value for the current state.
	//----------------------------------------------------------------------------------------
	inline UniqueHash Finalize() const;

	inline operator UniqueHash() const;

private:
	UInt64 _state[72];
};


} // namespace maxon

#endif // HASH_H__
