#ifndef FIXEDSIZEBITSET_H__
#define FIXEDSIZEBITSET_H__

#include "maxon/apibase.h"

namespace maxon
{

/// @addtogroup STRUCTURES
/// @{

template <Int EXPONENT> class FixedSizeBitSet
{
public:
	static const Int SIZE_EXPONENT = EXPONENT;

	FixedSizeBitSet()
	{
		for (Int i = 0; i < (1 << (EXPONENT - INT_WIDTH_EXPONENT)); ++i)
		{
			_bits[i] = 0;
		}
	}

	Bool Contains(UInt index) const
	{
		return (_bits[index >> INT_WIDTH_EXPONENT] & ((IntType) 1 << (index & ((1 << INT_WIDTH_EXPONENT) - 1)))) != 0;
	}

	void Add(UInt index, Bool& added)
	{
		if (_bits[index >> INT_WIDTH_EXPONENT] & ((IntType) 1 << (index & ((1 << INT_WIDTH_EXPONENT) - 1))))
		{
			added = false;
		}
		else
		{
			_bits[index >> INT_WIDTH_EXPONENT] |= ((IntType) 1 << (index & ((1 << INT_WIDTH_EXPONENT) - 1)));
			added = true;
		}
	}

	void Add(UInt index)
	{
		_bits[index >> INT_WIDTH_EXPONENT] |= ((IntType) 1 << (index & ((1 << INT_WIDTH_EXPONENT) - 1)));
	}

	void Intersect(const FixedSizeBitSet& b)
	{
		for (Int i = 0; i < (1 << (EXPONENT - INT_WIDTH_EXPONENT)); ++i)
		{
			_bits[i] &= b._bits[i];
		}
	}

private:
	using IntType = UInt;
	static const Int INT_WIDTH_EXPONENT = (SIZEOF(IntType) == 8) ? 6 : 5;
	IntType _bits[1 << (EXPONENT - INT_WIDTH_EXPONENT)];
};

/// @}

} // namespace maxon

#endif // FIXEDSIZEBITSET_H__
