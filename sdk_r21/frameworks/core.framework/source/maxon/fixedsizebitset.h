#ifndef FIXEDSIZEBITSET_H__
#define FIXEDSIZEBITSET_H__

#include "maxon/apibase.h"

namespace maxon
{

/// @addtogroup STRUCTURES
/// @{

template <Int EXPONENT> class FixedSizeBitSet
{
	using IntType = UInt;
	static const Int INT_WIDTH_EXPONENT = (SIZEOF(IntType) == 8) ? 6 : 5;
	static const Bool SINGLE_INT = EXPONENT <= INT_WIDTH_EXPONENT;
	static const Int INT_COUNT = 1 << (SINGLE_INT ? 0 : EXPONENT - INT_WIDTH_EXPONENT);

	IntType _bits[INT_COUNT];

public:
	static const Int SIZE_EXPONENT = EXPONENT;

	FixedSizeBitSet()
	{
		for (Int i = 0; i < INT_COUNT; ++i)
		{
			_bits[i] = 0;
		}
	}

	Bool Contains(UInt index) const
	{
		return (_bits[SINGLE_INT ? 0 : index >> INT_WIDTH_EXPONENT] & ((IntType) 1 << (index & ((1 << INT_WIDTH_EXPONENT) - 1)))) != 0;
	}

	void Add(UInt index, Bool& added)
	{
		if (_bits[SINGLE_INT ? 0 : index >> INT_WIDTH_EXPONENT] & ((IntType) 1 << (index & ((1 << INT_WIDTH_EXPONENT) - 1))))
		{
			added = false;
		}
		else
		{
			_bits[SINGLE_INT ? 0 : index >> INT_WIDTH_EXPONENT] |= ((IntType) 1 << (index & ((1 << INT_WIDTH_EXPONENT) - 1)));
			added = true;
		}
	}

	void Add(UInt index)
	{
		_bits[SINGLE_INT ? 0 : index >> INT_WIDTH_EXPONENT] |= ((IntType) 1 << (index & ((1 << INT_WIDTH_EXPONENT) - 1)));
	}

	void Remove(UInt index)
	{
		_bits[SINGLE_INT ? 0 : index >> INT_WIDTH_EXPONENT] &= ~((IntType) 1 << (index & ((1 << INT_WIDTH_EXPONENT) - 1)));
	}

	void Intersect(const FixedSizeBitSet& b)
	{
		for (Int i = 0; i < INT_COUNT; ++i)
		{
			_bits[i] &= b._bits[i];
		}
	}

	Bool IsPopulated() const
	{
		for (Int i = 0; i < INT_COUNT; ++i)
		{
			if (_bits[i])
				return true;
		}
		return false;
	}

	Bool IsEmpty() const
	{
		return !IsPopulated();
	}

	void Reset()
	{
		ClearMemType(_bits, INT_COUNT);
	}
};

/// @}

} // namespace maxon

#endif // FIXEDSIZEBITSET_H__
