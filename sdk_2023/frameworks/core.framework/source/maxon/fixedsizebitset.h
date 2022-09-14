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
	using IntType = UInt;
	static const Int INT_WIDTH_EXPONENT = (SIZEOF(IntType) == 8) ? 6 : 5;
	static const Int BIT_WIDTH = 1 << INT_WIDTH_EXPONENT;
	static const Bool SINGLE_INT = EXPONENT <= INT_WIDTH_EXPONENT;
	static const Int INT_COUNT = 1 << (SINGLE_INT ? 0 : EXPONENT - INT_WIDTH_EXPONENT);
	static const Int SIZE_EXPONENT = EXPONENT;
	static const Int SIZE = 1 << EXPONENT;

	FixedSizeBitSet()
	{
		for (IntType& b : _bits)
		{
			b = 0;
		}
	}

	explicit FixedSizeBitSet(UInt index) : FixedSizeBitSet()
	{
		Add(index);
	}

	explicit FixedSizeBitSet(ENUM_DONT_INITIALIZE)
	{
	}

	Bool Contains(UInt index) const
	{
		return (_bits[SINGLE_INT ? 0 : index >> INT_WIDTH_EXPONENT] & ((IntType) 1 << (index & (BIT_WIDTH - 1)))) != 0;
	}

	void Add(UInt index, Bool& added)
	{
		if (_bits[SINGLE_INT ? 0 : index >> INT_WIDTH_EXPONENT] & ((IntType) 1 << (index & (BIT_WIDTH - 1))))
		{
			added = false;
		}
		else
		{
			_bits[SINGLE_INT ? 0 : index >> INT_WIDTH_EXPONENT] |= ((IntType) 1 << (index & (BIT_WIDTH - 1)));
			added = true;
		}
	}

	void Add(UInt index)
	{
		_bits[SINGLE_INT ? 0 : index >> INT_WIDTH_EXPONENT] |= ((IntType) 1 << (index & (BIT_WIDTH - 1)));
	}

	void Remove(UInt index)
	{
		_bits[SINGLE_INT ? 0 : index >> INT_WIDTH_EXPONENT] &= ~((IntType) 1 << (index & (BIT_WIDTH - 1)));
	}

	void Add(const FixedSizeBitSet& b)
	{
		for (Int i = 0; i < INT_COUNT; ++i)
		{
			_bits[i] |= b._bits[i];
		}
	}

	void Remove(const FixedSizeBitSet& b)
	{
		for (Int i = 0; i < INT_COUNT; ++i)
		{
			_bits[i] &= ~b._bits[i];
		}
	}

	void Intersect(const FixedSizeBitSet& b)
	{
		for (Int i = 0; i < INT_COUNT; ++i)
		{
			_bits[i] &= b._bits[i];
		}
	}

	void Invert()
	{
		for (IntType& bitBlock : _bits)
		{
			bitBlock = ~bitBlock;
		}
	}

	FixedSizeBitSet& operator |=(const FixedSizeBitSet& other)
	{
		Add(other);
		return *this;
	}

	FixedSizeBitSet& operator &=(const FixedSizeBitSet& other)
	{
		Intersect(other);
		return *this;
	}

	FixedSizeBitSet operator |(const FixedSizeBitSet& other) const
	{
		FixedSizeBitSet result{DONT_INITIALIZE};
		for (Int i = 0; i < INT_COUNT; ++i)
		{
			result._bits[i] = _bits[i] | other._bits[i];
		}
		return result;
	}

	FixedSizeBitSet operator &(const FixedSizeBitSet& other) const
	{
		FixedSizeBitSet result{DONT_INITIALIZE};
		for (Int i = 0; i < INT_COUNT; ++i)
		{
			result._bits[i] = _bits[i] & other._bits[i];
		}
		return result;
	}

	FixedSizeBitSet operator ~() const
	{
		FixedSizeBitSet result{DONT_INITIALIZE};
		for (Int i = 0; i < INT_COUNT; ++i)
		{
			result._bits[i] = ~_bits[i];
		}
		return result;
	}

	Bool IsPopulated() const
	{
		for (const IntType b : _bits)
		{
			if (b)
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

	IntType GetBits(Int i) const
	{
		return _bits[i];
	}

	String ToString(const FormatStatement* fs = nullptr) const
	{
		String result = "{"_s;
		Int index = 0;
		for (IntType b : _bits)
		{
			for (Int i = BIT_WIDTH; i; --i)
			{
				if (b & 1)
				{
					if (result.GetLength() > 1)
					{
						result.AppendChar(',') iferr_ignore("");
					}
					result.AppendInt(index);
				}
				++index;
				b >>= 1;
			}
		}
		return result + "}"_s;
	}

private:
	IntType _bits[INT_COUNT];
};

/// @}

} // namespace maxon

#endif // FIXEDSIZEBITSET_H__
