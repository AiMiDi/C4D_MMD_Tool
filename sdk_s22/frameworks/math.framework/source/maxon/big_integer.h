#ifndef BIG_INTEGER_H__
#define BIG_INTEGER_H__

#include "maxon/error.h"
#include "maxon/string.h"
#include "maxon/secure_random.h"
#include "maxon/basearray.h"

namespace maxon
{

/// @addtogroup DATATYPE
/// @{

class BigInteger;

/// This is the interface for the BigInteger data type. The data is reference-counted and a copy will automatically be created if a non-const function is called.
///
/// @MAXON_ANNOTATION{refclass=false}
class BigIntegerInterface
{
	MAXON_INTERFACE_NONVIRTUAL(BigIntegerInterface, MAXON_REFERENCE_COPY_ON_WRITE, "net.maxon.interface.biginteger");

public:
	//----------------------------------------------------------------------------------------
	/// Returns a BigInteger value of zero.
	/// @return												A BigInteger value of zero.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD BigIntegerInterface* Zero();

	//----------------------------------------------------------------------------------------
	/// Returns a BigInteger value of one.
	/// @return												A BigInteger value of one.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD BigIntegerInterface* One();

	//----------------------------------------------------------------------------------------
	/// Returns a BigInteger value of minus one.
	/// @return												A BigInteger value of minus one.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD BigIntegerInterface* MinusOne();

	//----------------------------------------------------------------------------------------
	/// Sets the value of this BigInteger.
	/// @param[in] c									The new value.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> Set(Char c);

	//----------------------------------------------------------------------------------------
	/// Sets the value of this BigInteger.
	/// @param[in] c									The new value.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> Set(UChar c);

	//----------------------------------------------------------------------------------------
	/// Sets the value of this BigInteger.
	/// @param[in] i									The new value.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> Set(Int16 i);

	//----------------------------------------------------------------------------------------
	/// Sets the value of this BigInteger.
	/// @param[in] u									The new value.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> Set(UInt16 u);

	//----------------------------------------------------------------------------------------
	/// Sets the value of this BigInteger.
	/// @param[in] i									The new value.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> Set(Int32 i);

	//----------------------------------------------------------------------------------------
	/// Sets the value of this BigInteger.
	/// @param[in] u									The new value.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> Set(UInt32 u);

	//----------------------------------------------------------------------------------------
	/// Sets the value of this BigInteger.
	/// @param[in] i									The new value.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> Set(Int64 i);

	//----------------------------------------------------------------------------------------
	/// Sets the value of this BigInteger.
	/// @param[in] u									The new value.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> Set(UInt64 u);

	//----------------------------------------------------------------------------------------
	/// Assigns a random value to this BigInteger. The number is always positive.
	/// @param[in] bitCount						The number of bits to set. This value must be greater than 0.
	/// @param[in] provider						A secure random provider that can be used with SecureRandom. If nullptr is passed an unsecure default provider is chosen.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> SetRandom(Int bitCount, SecureRandomProvider provider = SecureRandomProvider());

	//----------------------------------------------------------------------------------------
	/// Assigns a random prime number value to this BigInteger. The number is always positive, odd and the (bitCount - 1) bit will be set.
	/// @param[in] bitCount						The number of bits to set. This value must be greater than 1.
	/// @param[in] certainty					The generated number is a prime number with a probability of 1-0.5**certainty. This parameter must be greater than 0. The execution time of this function raises with the certainty.
	/// @param[in] provider						A secure random provider that can be used with SecureRandom. If nullptr is passed an unsecure default provider is chosen.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> SetRandomPrime(Int bitCount, UInt certainty, SecureRandomProvider provider = SecureRandomProvider());

	//----------------------------------------------------------------------------------------
	/// Sets the value of this BigInteger.
	/// @param[in] mem								A memory block that contains the new value in the specified format.
	/// @param[in] littleEndian				If this value is true, the parameter is treated as little-endian ("Intel format"), otherwise big-endian ("Motorola format").
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> Set(const Block<const Byte>&mem, Bool littleEndian);

	//----------------------------------------------------------------------------------------
	/// Sets the value of this BigInteger.
	/// @param[in] str								The new value, represented as a decimal string. The string may only contain decimal digits.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> Set(const String& str);

	//----------------------------------------------------------------------------------------
	/// Sets the value of this BigInteger.
	/// @param[in] str								The new value, represented as a hexadecimal string. The string may only contain hexadecimal digits.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> SetHex(const String& str);

	//----------------------------------------------------------------------------------------
	/// Checks if the value is even.
	/// @return												True if the value is even, false otherwise.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Bool IsEven() const;

	//----------------------------------------------------------------------------------------
	/// Checks if the value is odd.
	/// @return												True if the value is odd, false otherwise.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Bool IsOdd() const;

	//----------------------------------------------------------------------------------------
	/// Checks if the value is one.
	/// @return												True if the value is one, false otherwise.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Bool IsOne() const;

	//----------------------------------------------------------------------------------------
	/// Checks if the value is zero.
	/// @return												True if the value is zero, false otherwise.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Bool IsZero() const;

	//----------------------------------------------------------------------------------------
	/// Checks if the value is negative.
	/// @return												True if the value is negative, false otherwise.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Bool IsNegative() const;

	//----------------------------------------------------------------------------------------
	/// Checks if the value is a power of 2.
	/// @return												True if the value is a power of 2, false otherwise.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Bool IsPowerOfTwo() const;

	//----------------------------------------------------------------------------------------
	/// Checks if the number is probably prime. The result will be false if the value of this BigInteger is smaller than one.
	/// @param[in] certainty					The certainty with which the number is checked for being a prime number. This parameter must be greater than 0.
	/// @return												True if number is greater than zero and prime with a probability of 1-0.5**certainty.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<Bool> IsProbablyPrime(UInt certainty) const;

	//----------------------------------------------------------------------------------------
	/// Gets the sign.
	/// @return												-1 if the number is negative, 0 if it is zero, 1 if it is positive.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Int Sign() const;

	//----------------------------------------------------------------------------------------
	/// Gets the highest bit position that is different than the sign bit. This is the position incremented by one for negative numbers.
	/// @return												The bit position. The return value is -1 if the number is 0.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Int GetHighestNonSignBit() const;

	//----------------------------------------------------------------------------------------
	/// Gets the lowest bit position that is zero.
	/// @return												The bit position. The return value is -1 if the number is 0.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Int GetLowestSetBit() const;

	//----------------------------------------------------------------------------------------
	/// Gets the lowest bit position that is zero.
	/// @return												The bit position. The return value is -1 if the number is -1.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Int GetLowestClearedBit() const;

	//----------------------------------------------------------------------------------------
	/// Checks if the bit at a certain position is set.
	/// @param[in] bit								The bit position to set.
	/// @return												True, if the bit is set, false otherwise.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Bool IsBitSet(Int bit) const;

	//----------------------------------------------------------------------------------------
	/// Get the lowest 8 bits.
	/// @return												The lowest 8 bits as an unsigned 8-bit integer.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD UChar GetLowestBits8U() const;

	//----------------------------------------------------------------------------------------
	/// Get the lowest 8 bits.
	/// @return												The lowest 8 bits as an signed 8-bit integer.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Char GetLowestBits8S() const;

	//----------------------------------------------------------------------------------------
	/// Get the lowest 16 bits.
	/// @return												The lowest 16 bits as an unsigned 16-bit integer.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD UInt16 GetLowestBits16U() const;

	//----------------------------------------------------------------------------------------
	/// Get the lowest 16 bits.
	/// @return												The lowest 16 bits as an signed 16-bit integer.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Int16 GetLowestBits16S() const;

	//----------------------------------------------------------------------------------------
	/// Get the lowest 32 bits.
	/// @return												The lowest 32 bits as an unsigned 32-bit integer.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD UInt32 GetLowestBits32U() const;

	//----------------------------------------------------------------------------------------
	/// Get the lowest 32 bits.
	/// @return												The lowest 32 bits as an signed 32-bit integer.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Int32 GetLowestBits32S() const;

	//----------------------------------------------------------------------------------------
	/// Get the lowest 64 bits.
	/// @return												The lowest 64 bits as an unsigned 64-bit integer.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD UInt64 GetLowestBits64U() const;

	//----------------------------------------------------------------------------------------
	/// Get the lowest 64 bits.
	/// @return												The lowest 64 bits as an signed 64-bit integer.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Int64 GetLowestBits64S() const;

	//----------------------------------------------------------------------------------------
	/// Gets a copy of the internal data.
	/// @param[in] littleEndian				If this value is true, the data is written in little-endian format, otherwise big-endian.
	/// @param[out] data							The BaseArray that will hold the data copy in the specified format.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> GetDataCopy(Bool littleEndian, BaseArray<UChar>& data) const;

	//----------------------------------------------------------------------------------------
	/// Performs the add operation.
	/// @param[in] b									The value to add to this.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> Add(const BigIntegerInterface* b);

	//----------------------------------------------------------------------------------------
	/// Performs the subtract operation.
	/// @param[in] b									The value to subtract to this.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> Sub(const BigIntegerInterface* b);

	//----------------------------------------------------------------------------------------
	/// Increments the value by one.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> Inc();

	//----------------------------------------------------------------------------------------
	/// Decrements the value by one.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> Dec();

	//----------------------------------------------------------------------------------------
	/// Performs the multiply operation.
	/// @param[in] b									The value to multiply to this.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> Mul(const BigIntegerInterface* b);

	//----------------------------------------------------------------------------------------
	/// Performs the divide operation.
	/// @param[in] b									The value with which is this to divide. The result is 0, if b is 0 or if its absolute value is bigger than the absolute value of this.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> Div(const BigIntegerInterface* b);

	//----------------------------------------------------------------------------------------
	/// Performs the modulo operation.
	/// @param[in] b									The modulus. The result is 0, if b is 0.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> Mod(const BigIntegerInterface* b);

	//----------------------------------------------------------------------------------------
	/// Performs the divide and modulo operation.
	/// @param[in] b									The value with which is this to divide. The result is 0, if b is 0 or if its absolute value is bigger than the absolute value of this.
	/// @param[out] r									The remainder of the division will be stored in r. The value of r is undefined if b is 0.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> DivMod(const BigIntegerInterface* b, BigInteger& r);

	//----------------------------------------------------------------------------------------
	/// Performs the power operation.
	/// @param[in] b									Raises this to the power of b. The result will be 0 if b is negative.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> Pow(const BigIntegerInterface* b);

	//----------------------------------------------------------------------------------------
	/// Performs the power operation and takes the result modulo mod.
	/// @param[in] b									Raises this to the power of b. The result will be 0 if b is negative.
	/// @param[in] mod								The modulo value.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> PowMod(const BigIntegerInterface* b, const BigIntegerInterface* mod);

	//----------------------------------------------------------------------------------------
	/// Calculates the greatest common divisor of this and b. Both values must be greater than zero, otherwise the value will remain unchanged.
	/// @param[in] b									Another BigInteger.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> GreatestCommonDivisor(const BigIntegerInterface* b);

	//----------------------------------------------------------------------------------------
	/// Calculates the multiplicative inverse of this modulo m. This must be smaller than m. The new result of this will be greater or equal to zero and smaller than m.
	/// @param[in] m									Another BigInteger. This value must be greater than zero.
	/// @return												True, if there is a multiplicative inverse, false otherwise. The value of this is unchanged if there is no multiplicative inverse.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<Bool> MultiplicativeInverse(const BigIntegerInterface* m);

	//----------------------------------------------------------------------------------------
	/// Performs the Left shift operation. If the number of bits to shift is less than 0 the bits are shifted right.
	/// @param[in] s									The number of bits to shift.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> LeftShift(Int s);

	//----------------------------------------------------------------------------------------
	/// Performs the Right shift operation. If the number of bits to shift is less than 0 the bits are shifted left.
	/// @param[in] s									The number of bits to shift.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> RightShift(Int s);

	//----------------------------------------------------------------------------------------
	/// Negates the value.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> Negate();

	//----------------------------------------------------------------------------------------
	/// Sets a bit in the integer.
	/// @param[in] bit								The position of the bit which is to set.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> SetBit(Int bit);

	//----------------------------------------------------------------------------------------
	/// Clears a bit in the integer.
	/// @param[in] bit								The position of the bit which is to clear.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> ClearBit(Int bit);

	//----------------------------------------------------------------------------------------
	/// Toggles a bit in the integer.
	/// @param[in] bit								The position of the bit which is to toggle.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> ToggleBit(Int bit);

	//----------------------------------------------------------------------------------------
	/// Compares this with another BigInteger value.
	/// @param[in] arg2								The other BigInteger value to compare with.
	/// @return												The comparison result.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD COMPARERESULT Compare(const BigIntegerInterface* arg2) const;

	//----------------------------------------------------------------------------------------
	/// Returns the hash code of the object.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD UInt GetHashCode() const;

	//----------------------------------------------------------------------------------------
	/// Returns a readable string of the content.
	/// @param[in] formatStatement		Nullptr or additional formatting instruction. Currently no additional formatting instructions are supported.
	/// @return												The converted result.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD String ToString(const FormatStatement* formatStatement) const;

	//----------------------------------------------------------------------------------------
	/// Describe all elements of this class for I/O operations.
	/// @param[in] stream							The stream that is used to register the class members.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<void> DescribeIO(const DataSerializeInterface& stream);
};


// include autogenerated headerfile here
#include "big_integer1.hxx"


/// Reference counted class of BigIntegerInterface
class BigInteger : public BigIntegerInterface::Reference
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(BigInteger, Reference);

	//----------------------------------------------------------------------------------------
	/// Adds two BigIntegers.
	/// @param[in] a									The fist summand.
	/// @param[in] b									The second summand.
	/// @return												The result of a + b.
	//----------------------------------------------------------------------------------------
	inline friend BigInteger operator +(const BigInteger& a, const BigInteger&b)
	{
		BigInteger r(a);
		r.Add(b) iferr_ignore("operator cannot return an error");
		return r;
	}

	//----------------------------------------------------------------------------------------
	/// Adds another integer to the first operand.
	/// @param[in] b									The second summand.
	/// @return												The result of this + b.
	//----------------------------------------------------------------------------------------
	inline BigInteger& operator +=(const BigInteger&b)
	{
		Add(b) iferr_ignore("operator cannot return an error");
		return *this;
	}

	//----------------------------------------------------------------------------------------
	/// Subtracts two BigIntegers.
	/// @param[in] a									The minuend.
	/// @param[in] b									The subtrahend.
	/// @return												The result of a - b.
	//----------------------------------------------------------------------------------------
	inline friend BigInteger operator -(const BigInteger& a, const BigInteger&b)
	{
		BigInteger r(a);
		r.Sub(b) iferr_ignore("operator cannot return an error");
		return r;
	}

	//----------------------------------------------------------------------------------------
	/// Subtracts a value from this BigIntegers.
	/// @param[in] b									The subtrahend.
	/// @return												The result of this - b.
	//----------------------------------------------------------------------------------------
	inline BigInteger& operator -=(const BigInteger&b)
	{
		Sub(b) iferr_ignore("operator cannot return an error");
		return *this;
	}

	//----------------------------------------------------------------------------------------
	/// Subtracts two BigIntegers.
	/// @param[in] b									The subtrahend.
	/// @return												The result of this - b.
	//----------------------------------------------------------------------------------------
	inline friend BigInteger operator -(const BigInteger& b)
	{
		BigInteger r(b);
		r.Negate() iferr_ignore("operator cannot return an error");
		return r;
	}

	//----------------------------------------------------------------------------------------
	/// The prefix operator to increment this BigInteger.
	/// @return												The result of this + 1.
	//----------------------------------------------------------------------------------------
	inline BigInteger& operator ++() // prefix operator
	{
		Inc() iferr_ignore("operator cannot return an error");
		return *this;
	}

	//----------------------------------------------------------------------------------------
	/// The postfix operator to increment this BigInteger.
	/// @return												The result of this + 1.
	//----------------------------------------------------------------------------------------
	inline BigInteger operator ++(int) // postfix operator
	{
		BigInteger r(*this);
		Inc() iferr_ignore("operator cannot return an error");
		return r;
	}

	//----------------------------------------------------------------------------------------
	/// The prefix operator to decrement this BigInteger.
	/// @return												The result of this - 1.
	//----------------------------------------------------------------------------------------
	inline BigInteger& operator --() // prefix operator
	{
		Dec() iferr_ignore("operator cannot return an error");
		return *this;
	}

	//----------------------------------------------------------------------------------------
	/// The postfix operator to decrement this BigInteger.
	/// @return												The result of this - 1.
	//----------------------------------------------------------------------------------------
	inline BigInteger operator --(int) // postfix operator
	{
		BigInteger r(*this);
		Dec() iferr_ignore("operator cannot return an error");
		return r;
	}

	//----------------------------------------------------------------------------------------
	/// Multiplies two BigIntegers.
	/// @param[in] a									The fist factor.
	/// @param[in] b									The second factor.
	/// @return												The result of a * b.
	//----------------------------------------------------------------------------------------
	inline friend BigInteger operator *(const BigInteger& a, const BigInteger&b)
	{
		BigInteger r(a);
		r.Mul(b) iferr_ignore("operator cannot return an error");
		return r;
	}

	//----------------------------------------------------------------------------------------
	/// Multiplies another integer to the first operand.
	/// @param[in] b									The second factor.
	/// @return												The result of this * b.
	//----------------------------------------------------------------------------------------
	inline BigInteger& operator *=(const BigInteger&b)
	{
		Mul(b) iferr_ignore("operator cannot return an error");
		return *this;
	}

	//----------------------------------------------------------------------------------------
	/// Divides two BigIntegers.
	/// @param[in] a									The dividend.
	/// @param[in] b									The divisor. If the divisor is 0, the result will be 0.
	/// @return												The result of a / b.
	//----------------------------------------------------------------------------------------
	inline friend BigInteger operator /(const BigInteger& a, const BigInteger&b)
	{
		BigInteger r(a);
		r.Div(b) iferr_ignore("operator cannot return an error");
		return r;
	}

	//----------------------------------------------------------------------------------------
	/// Divides this by another BigInteger.
	/// @param[in] b									The divisor. If the divisor is 0, the result will be 0.
	/// @return												The result of a / b.
	//----------------------------------------------------------------------------------------
	inline BigInteger& operator /=(const BigInteger&b)
	{
		Div(b) iferr_ignore("operator cannot return an error");
		return *this;
	}

	//----------------------------------------------------------------------------------------
	/// Calculates the modulus of two BigInteger values.
	/// @param[in] a									The dividend.
	/// @param[in] b									The divisor. If the divisor is 0, the result will be 0.
	/// @return												The result of a % b.
	//----------------------------------------------------------------------------------------
	inline friend BigInteger operator %(const BigInteger& a, const BigInteger&b)
	{
		BigInteger r(a), m;
		r.DivMod(b, m) iferr_ignore("operator cannot return an error");
		return m;
	}

	//----------------------------------------------------------------------------------------
	/// Calculates the modulus of two BigInteger values.
	/// @param[in] b									The divisor. If the divisor is 0, the result will be 0.
	/// @return												The result of this % b.
	//----------------------------------------------------------------------------------------
	inline BigInteger& operator %=(const BigInteger&b)
	{
		BigInteger m;
		DivMod(b, m) iferr_ignore("operator cannot return an error");
		*this = m;
		return *this;
	}

	//----------------------------------------------------------------------------------------
	/// Shifts a BigInteger left by the specified number of bits.
	/// @param[in] a									The source operand.
	/// @param[in] s									The number of bits to left-shift the value. If this is negative, the value is shifted right.
	/// @return												The result of a << s.
	//----------------------------------------------------------------------------------------
	inline friend BigInteger operator <<(const BigInteger& a, Int s)
	{
		BigInteger r(a);
		r.LeftShift(s) iferr_ignore("operator cannot return an error");
		return r;
	}

	//----------------------------------------------------------------------------------------
	/// Shifts this BigInteger left by the specified number of bits.
	/// @param[in] s									The number of bits to left-shift the value. If this is negative, the value is shifted right.
	/// @return												The result of this << s.
	//----------------------------------------------------------------------------------------
	inline BigInteger& operator <<=(Int s)
	{
		LeftShift(s) iferr_ignore("operator cannot return an error");
		return *this;
	}

	//----------------------------------------------------------------------------------------
	/// Shifts a BigInteger right by the specified number of bits.
	/// @param[in] a									The source operand.
	/// @param[in] s									The number of bits to right-shift the value. If this is negative, the value is shifted left.
	/// @return												The result of a >> s.
	//----------------------------------------------------------------------------------------
	inline friend BigInteger operator >>(const BigInteger& a, Int s)
	{
		BigInteger r(a);
		r.RightShift(s) iferr_ignore("operator cannot return an error");
		return r;
	}

	//----------------------------------------------------------------------------------------
	/// Shifts this BigInteger right by the specified number of bits.
	/// @param[in] s									The number of bits to right-shift the value. If this is negative, the value is shifted left.
	/// @return												The result of this >> s.
	//----------------------------------------------------------------------------------------
	inline BigInteger& operator >>=(Int s)
	{
		RightShift(s) iferr_ignore("operator cannot return an error");
		return *this;
	}
};

// include autogenerated headerfile here
#include "big_integer2.hxx"

/// @}

} // namespace maxon

#endif // BIG_INTEGER_H__
