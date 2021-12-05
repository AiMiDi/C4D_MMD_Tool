#ifndef HASHBITSET_H__
#define HASHBITSET_H__

#include "maxon/hashmap.h"
#include "maxon/fixedsizebitset.h"

namespace maxon
{

/// @addtogroup STRUCTURES
/// @{

template <typename BASE_SET = FixedSizeBitSet<8>, typename INT_TYPE = UInt> class HashBitSet
{
public:
	Result<void> Insert(INT_TYPE value, Bool& added)
	{
		iferr (typename Map::Entry* e = _baseSets.Insert(value >> BASE_SET::SIZE_EXPONENT, added))
			return err;

		e->GetValue().Add(value & (((INT_TYPE) 1 << BASE_SET::SIZE_EXPONENT) - 1), added);
		return true;
	}

	Bool Contains(INT_TYPE value) const
	{
		const typename Map::Entry* e = _baseSets.Find(value >> BASE_SET::SIZE_EXPONENT);
		return e && e->GetValue().Contains(value & (((INT_TYPE) 1 << BASE_SET::SIZE_EXPONENT) - 1));
	}

private:
	static UInt GetHashCode(INT_TYPE key)
	{
		return key;
	}

	static Bool IsEqual(INT_TYPE a, INT_TYPE b)
	{
		return a == b;
	}

	friend class HashMap<INT_TYPE, BASE_SET, HashBitSet>;
	using Map = HashMap<INT_TYPE, BASE_SET, HashBitSet>;
	Map _baseSets;
};

/// @}

} // namespace maxon

#endif // HASHBITSET_H__
