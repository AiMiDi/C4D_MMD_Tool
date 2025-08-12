#ifndef INTEGER_H__
#define INTEGER_H__

#include "maxon/apibase.h"

namespace maxon
{

/// @addtogroup MATH
/// @{

#ifdef MAXON_ASSEMBLY_GCC_TODO
	using UIntegerBase = UInt;
#else
	using UIntegerBase = UInt32;
#endif

template <Int N> class UInteger
{
	static_assert((N != 0) && !(N & (N - 1)), "N must be a power of two.");
	static_assert(N > SIZEOF(UIntegerBase) * 8, "N must be greater than the bit width of UIntegerBase.");
public:
	using Half = UInteger<N / 2>;

	UInteger() : _low(), _high() { }
	explicit UInteger(Half low) : _low(low), _high() { }
	UInteger(Half high, Half low) : _low(low), _high(high) { }

	UInteger<N * 2> operator *(const UInteger& other) const
	{
		UInteger<N * 2> result(_low * other._low, _high * other._high);
		result.AddMixed(_low * other._high);
		result.AddMixed(_high * other._low);
		return result;
	}

	Bool operator <(const UInteger& other) const { return (_high < other._high) || ((_high == other._high) && (_low < other._low)); }

	Bool operator ==(const UInteger& other) const { return (_low == other._low) && (_high == other._high); }

	MAXON_OPERATOR_COMPARISON(UInteger);

	void AddMixed(const Half& half)
	{
		if (_low.AddLowToHigh(half))
			++_high;
		_high.AddHigh(half);
	}

	Bool AddLowToHigh(const UInteger& value)
	{
		return _high.Add(value._low);
	}

	void AddHigh(const UInteger& value)
	{
		if (_low.Add(value._high))
			++_high;
	}

	Bool Add(const UInteger& value)
	{
		Bool overflow = _low.Add(value._low) && _high.Inc();
		return _high.Add(value._high) || overflow;
	}

	Bool Inc()
	{
		return _low.Inc() && _high.Inc();
	}

	UInteger& operator ++()
	{
		Inc();
		return *this;
	}

	UInteger& operator ++(int)
	{
		Inc();
		return *this;
	}

private:
	Half _low;
	Half _high;
};

template <> class UInteger<SIZEOF(UIntegerBase) * 8>
{
public:
	MAXON_IMPLICIT UInteger(UInt value = 0) : _value(value) { }

	using UInteger2 = UInteger<SIZEOF(UIntegerBase) * 16>;

	UInteger2 operator *(const UInteger& other) const
	{
#ifdef MAXON_ASSEMBLY_GCC_TODO
#else
		UInt64 r = UInt64(_value) * UInt64(other._value);
		return UInteger2(UIntegerBase(r), UIntegerBase(r >> 32));
#endif
	}

	Bool operator <(const UInteger& other) const { return _value < other._value; }

	Bool operator ==(const UInteger& other) const { return _value == other._value; }

	MAXON_OPERATOR_COMPARISON(UInteger);

	Bool Add(const UInteger& value)
	{
		UInt v = _value;
		_value += value._value;
		return _value < v;
	}

	Bool Inc()
	{
		return ++_value == 0;
	}

	UInteger& operator ++()
	{
		++_value;
		return *this;
	}

	UInteger& operator ++(int)
	{
		++_value;
		return *this;
	}

private:
	UInt _value;
};

using NativeUInteger = UInteger<SIZEOF(Int) * 8>;

//----------------------------------------------------------------------------------------
/// Returns true if <tt>a1*a2</tt> is less than <tt>b1*b2</tt>. The products and the
/// comparison are carried out with the double bit width of @c Int so that no overflow
/// occurs.
/// @param[in] a1									First factor of first comparison operand.
/// @param[in] a2									Second factor of first comparison operand.
/// @param[in] b1									First factor of second comparison operand.
/// @param[in] b2									Second factor of second comparison operand.
/// @return												True if <tt>a1*a2 < b1*b2</tt>.
//----------------------------------------------------------------------------------------
inline Bool LessThan(UInt a1, UInt a2, UInt b1, UInt b2)
{
	return NativeUInteger(a1) * NativeUInteger(a2) < NativeUInteger(b1) * NativeUInteger(b2);
}

/// @}

} // namespace maxon

#endif // INTEGER_H__
