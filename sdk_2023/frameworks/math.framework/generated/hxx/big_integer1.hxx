#if 1
class BigInteger;

struct BigIntegerInterface::Hxx1
{
	class NonConstRef;
	using ReferenceClass = BigInteger;
	/// Intermediate helper class for BigIntegerInterface.
	template <typename S> class ConstFn DOXYGEN_SWITCH_REVERSED(, : public S)
	{
	public:
		ConstFn() = default;
		using PrivateBaseClass = S;
		using PrivateBaseClass::PrivateBaseClass;
		using PrivateBaseClass::PrivateLookupFn;
		static ConstFn PrivateLookupFn(BigIntegerInterface**);
/// Returns a BigInteger value of zero.
/// @return												A BigInteger value of zero.
		static inline BigInteger Zero();
/// Returns a BigInteger value of one.
/// @return												A BigInteger value of one.
		static inline BigInteger One();
/// Returns a BigInteger value of minus one.
/// @return												A BigInteger value of minus one.
		static inline BigInteger MinusOne();
/// Checks if the value is even.
/// @return												True if the value is even, false otherwise.
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type IsEven() const;
/// Checks if the value is odd.
/// @return												True if the value is odd, false otherwise.
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type IsOdd() const;
/// Checks if the value is one.
/// @return												True if the value is one, false otherwise.
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type IsOne() const;
/// Checks if the value is zero.
/// @return												True if the value is zero, false otherwise.
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type IsZero() const;
/// Checks if the value is negative.
/// @return												True if the value is negative, false otherwise.
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type IsNegative() const;
/// Checks if the value is a power of 2.
/// @return												True if the value is a power of 2, false otherwise.
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type IsPowerOfTwo() const;
/// Checks if the number is probably prime. The result will be false if the value of this BigInteger is smaller than one.
/// @param[in] certainty					The certainty with which the number is checked for being a prime number. This parameter must be greater than 0.
/// @return												True if number is greater than zero and prime with a probability of 1-0.5**certainty.
		inline Result<Bool> IsProbablyPrime(UInt certainty) const;
/// Gets the sign.
/// @return												-1 if the number is negative, 0 if it is zero, 1 if it is positive.
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type Sign() const;
/// Gets the highest bit position that is different than the sign bit. This is the position incremented by one for negative numbers.
/// @return												The bit position. The return value is -1 if the number is 0.
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type GetHighestNonSignBit() const;
/// Gets the lowest bit position that is zero.
/// @return												The bit position. The return value is -1 if the number is 0.
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type GetLowestSetBit() const;
/// Gets the lowest bit position that is zero.
/// @return												The bit position. The return value is -1 if the number is -1.
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type GetLowestClearedBit() const;
/// Checks if the bit at a certain position is set.
/// @param[in] bit								The bit position to set.
/// @return												True, if the bit is set, false otherwise.
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type IsBitSet(Int bit) const;
/// Get the lowest 8 bits.
/// @return												The lowest 8 bits as an unsigned 8-bit integer.
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<UChar>, UChar>::type GetLowestBits8U() const;
/// Get the lowest 8 bits.
/// @return												The lowest 8 bits as an signed 8-bit integer.
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<Char>, Char>::type GetLowestBits8S() const;
/// Get the lowest 16 bits.
/// @return												The lowest 16 bits as an unsigned 16-bit integer.
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<UInt16>, UInt16>::type GetLowestBits16U() const;
/// Get the lowest 16 bits.
/// @return												The lowest 16 bits as an signed 16-bit integer.
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<Int16>, Int16>::type GetLowestBits16S() const;
/// Get the lowest 32 bits.
/// @return												The lowest 32 bits as an unsigned 32-bit integer.
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<UInt32>, UInt32>::type GetLowestBits32U() const;
/// Get the lowest 32 bits.
/// @return												The lowest 32 bits as an signed 32-bit integer.
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<Int32>, Int32>::type GetLowestBits32S() const;
/// Get the lowest 64 bits.
/// @return												The lowest 64 bits as an unsigned 64-bit integer.
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<UInt64>, UInt64>::type GetLowestBits64U() const;
/// Get the lowest 64 bits.
/// @return												The lowest 64 bits as an signed 64-bit integer.
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<Int64>, Int64>::type GetLowestBits64S() const;
/// Gets a copy of the internal data.
/// @param[in] littleEndian				If this value is true, the data is written in little-endian format, otherwise big-endian.
/// @param[out] data							The BaseArray that will hold the data copy in the specified format.
/// @return												OK on success.
		inline Result<void> GetDataCopy(Bool littleEndian, BaseArray<UChar>& data) const;
/// Compares this with another BigInteger value.
/// @param[in] arg2								The other BigInteger value to compare with.
/// @return												The comparison result.
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<COMPARERESULT>, COMPARERESULT>::type Compare(const BigIntegerInterface* arg2) const;
/// Returns a readable string of the content.
/// @param[in] formatStatement		Nullptr or additional formatting instruction. Currently no additional formatting instructions are supported.
/// @return												The converted result.
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<String>, String>::type ToString(const FormatStatement* formatStatement = nullptr) const;
/// Describe all elements of this class for I/O operations.
/// @param[in] stream							The stream that is used to register the class members.
/// @return												OK on success.
		static inline Result<void> DescribeIO(const DataSerializeInterface& stream);
	};
	/// Intermediate helper class for BigIntegerInterface.
	template <typename S> class Fn : public ConstFn<S>
	{
	public:
		Fn() = default;
		using PrivateBaseClass = ConstFn<S>;
		using PrivateBaseClass::PrivateBaseClass;
		using PrivateBaseClass::PrivateLookupFn;
		static Fn PrivateLookupFn(BigIntegerInterface**);
/// Sets the value of this BigInteger.
/// @param[in] c									The new value.
/// @return												OK on success.
		inline Result<void> Set(Char c) const;
/// Sets the value of this BigInteger.
/// @param[in] c									The new value.
/// @return												OK on success.
		inline Result<void> Set(UChar c) const;
/// Sets the value of this BigInteger.
/// @param[in] i									The new value.
/// @return												OK on success.
		inline Result<void> Set(Int16 i) const;
/// Sets the value of this BigInteger.
/// @param[in] u									The new value.
/// @return												OK on success.
		inline Result<void> Set(UInt16 u) const;
/// Sets the value of this BigInteger.
/// @param[in] i									The new value.
/// @return												OK on success.
		inline Result<void> Set(Int32 i) const;
/// Sets the value of this BigInteger.
/// @param[in] u									The new value.
/// @return												OK on success.
		inline Result<void> Set(UInt32 u) const;
/// Sets the value of this BigInteger.
/// @param[in] i									The new value.
/// @return												OK on success.
		inline Result<void> Set(Int64 i) const;
/// Sets the value of this BigInteger.
/// @param[in] u									The new value.
/// @return												OK on success.
		inline Result<void> Set(UInt64 u) const;
/// Assigns a random value to this BigInteger. The number is always positive.
/// @param[in] bitCount						The number of bits to set. This value must be greater than 0.
/// @param[in] provider						A secure random provider that can be used with SecureRandom. If nullptr is passed an unsecure default provider is chosen.
/// @return												OK on success.
		inline Result<void> SetRandom(Int bitCount, SecureRandomProvider provider = SecureRandomProvider()) const;
/// Assigns a random prime number value to this BigInteger. The number is always positive, odd and the (bitCount - 1) bit will be set.
/// @param[in] bitCount						The number of bits to set. This value must be greater than 1.
/// @param[in] certainty					The generated number is a prime number with a probability of 1-0.5**certainty. This parameter must be greater than 0. The execution time of this function raises with the certainty.
/// @param[in] provider						A secure random provider that can be used with SecureRandom. If nullptr is passed an unsecure default provider is chosen.
/// @return												OK on success.
		inline Result<void> SetRandomPrime(Int bitCount, UInt certainty, SecureRandomProvider provider = SecureRandomProvider()) const;
/// Sets the value of this BigInteger.
/// @param[in] mem								A memory block that contains the new value in the specified format.
/// @param[in] littleEndian				If this value is true, the parameter is treated as little-endian ("Intel format"), otherwise big-endian ("Motorola format").
/// @return												OK on success.
		inline Result<void> Set(const Block<const Byte>& mem, Bool littleEndian) const;
/// Sets the value of this BigInteger.
/// @param[in] str								The new value, represented as a decimal string. The string may only contain decimal digits.
/// @return												OK on success.
		inline Result<void> Set(const String& str) const;
/// Sets the value of this BigInteger.
/// @param[in] str								The new value, represented as a hexadecimal string. The string may only contain hexadecimal digits.
/// @return												OK on success.
		inline Result<void> SetHex(const String& str) const;
/// Performs the add operation.
/// @param[in] b									The value to add to this.
		inline Result<void> Add(const BigIntegerInterface* b) const;
/// Performs the subtract operation.
/// @param[in] b									The value to subtract to this.
		inline Result<void> Sub(const BigIntegerInterface* b) const;
/// Increments the value by one.
		inline Result<void> Inc() const;
/// Decrements the value by one.
		inline Result<void> Dec() const;
/// Performs the multiply operation.
/// @param[in] b									The value to multiply to this.
		inline Result<void> Mul(const BigIntegerInterface* b) const;
/// Performs the divide operation.
/// @param[in] b									The value with which is this to divide. The result is 0, if b is 0 or if its absolute value is bigger than the absolute value of this.
		inline Result<void> Div(const BigIntegerInterface* b) const;
/// Performs the modulo operation.
/// @param[in] b									The modulus. The result is 0, if b is 0.
		inline Result<void> Mod(const BigIntegerInterface* b) const;
/// Performs the divide and modulo operation.
/// @param[in] b									The value with which is this to divide. The result is 0, if b is 0 or if its absolute value is bigger than the absolute value of this.
/// @param[out] r									The remainder of the division will be stored in r. The value of r is undefined if b is 0.
		inline Result<void> DivMod(const BigIntegerInterface* b, BigInteger& r) const;
/// Performs the power operation.
/// @param[in] b									Raises this to the power of b. The result will be 0 if b is negative.
		inline Result<void> Pow(const BigIntegerInterface* b) const;
/// Performs the power operation and takes the result modulo mod.
/// @param[in] b									Raises this to the power of b. The result will be 0 if b is negative.
/// @param[in] mod								The modulo value.
		inline Result<void> PowMod(const BigIntegerInterface* b, const BigIntegerInterface* mod) const;
/// Calculates the greatest common divisor of this and b. Both values must be greater than zero, otherwise the value will remain unchanged.
/// @param[in] b									Another BigInteger.
		inline Result<void> GreatestCommonDivisor(const BigIntegerInterface* b) const;
/// Calculates the multiplicative inverse of this modulo m. This must be smaller than m. The new result of this will be greater or equal to zero and smaller than m.
/// @param[in] m									Another BigInteger. This value must be greater than zero.
/// @return												True, if there is a multiplicative inverse, false otherwise. The value of this is unchanged if there is no multiplicative inverse.
		inline Result<Bool> MultiplicativeInverse(const BigIntegerInterface* m) const;
/// Performs the Left shift operation. If the number of bits to shift is less than 0 the bits are shifted right.
/// @param[in] s									The number of bits to shift.
		inline Result<void> LeftShift(Int s) const;
/// Performs the Right shift operation. If the number of bits to shift is less than 0 the bits are shifted left.
/// @param[in] s									The number of bits to shift.
		inline Result<void> RightShift(Int s) const;
/// Negates the value.
		inline Result<void> Negate() const;
/// Sets a bit in the integer.
/// @param[in] bit								The position of the bit which is to set.
		inline Result<void> SetBit(Int bit) const;
/// Clears a bit in the integer.
/// @param[in] bit								The position of the bit which is to clear.
		inline Result<void> ClearBit(Int bit) const;
/// Toggles a bit in the integer.
/// @param[in] bit								The position of the bit which is to toggle.
		inline Result<void> ToggleBit(Int bit) const;
	};
	/// Intermediate helper class for BigIntegerInterface.
	template <typename S> class COWFn : public ConstFn<S>
	{
	public:
		COWFn() = default;
		using PrivateBaseClass = ConstFn<S>;
		using PrivateBaseClass::PrivateBaseClass;
		using PrivateBaseClass::PrivateLookupFn;
		static COWFn PrivateLookupFn(BigIntegerInterface**);
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongCOWRefHandler, BigInteger, false>::type&() const { return reinterpret_cast<const BigInteger&>(this->GetBaseRef()); }
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongCOWRefHandler, BigInteger, false>::type&() { return reinterpret_cast<const BigInteger&>(this->GetBaseRef()); }
/// Sets the value of this BigInteger.
/// @param[in] c									The new value.
/// @return												OK on success.
		inline Result<void> Set(Char c);
/// Sets the value of this BigInteger.
/// @param[in] c									The new value.
/// @return												OK on success.
		inline Result<void> Set(UChar c);
/// Sets the value of this BigInteger.
/// @param[in] i									The new value.
/// @return												OK on success.
		inline Result<void> Set(Int16 i);
/// Sets the value of this BigInteger.
/// @param[in] u									The new value.
/// @return												OK on success.
		inline Result<void> Set(UInt16 u);
/// Sets the value of this BigInteger.
/// @param[in] i									The new value.
/// @return												OK on success.
		inline Result<void> Set(Int32 i);
/// Sets the value of this BigInteger.
/// @param[in] u									The new value.
/// @return												OK on success.
		inline Result<void> Set(UInt32 u);
/// Sets the value of this BigInteger.
/// @param[in] i									The new value.
/// @return												OK on success.
		inline Result<void> Set(Int64 i);
/// Sets the value of this BigInteger.
/// @param[in] u									The new value.
/// @return												OK on success.
		inline Result<void> Set(UInt64 u);
/// Assigns a random value to this BigInteger. The number is always positive.
/// @param[in] bitCount						The number of bits to set. This value must be greater than 0.
/// @param[in] provider						A secure random provider that can be used with SecureRandom. If nullptr is passed an unsecure default provider is chosen.
/// @return												OK on success.
		inline Result<void> SetRandom(Int bitCount, SecureRandomProvider provider = SecureRandomProvider());
/// Assigns a random prime number value to this BigInteger. The number is always positive, odd and the (bitCount - 1) bit will be set.
/// @param[in] bitCount						The number of bits to set. This value must be greater than 1.
/// @param[in] certainty					The generated number is a prime number with a probability of 1-0.5**certainty. This parameter must be greater than 0. The execution time of this function raises with the certainty.
/// @param[in] provider						A secure random provider that can be used with SecureRandom. If nullptr is passed an unsecure default provider is chosen.
/// @return												OK on success.
		inline Result<void> SetRandomPrime(Int bitCount, UInt certainty, SecureRandomProvider provider = SecureRandomProvider());
/// Sets the value of this BigInteger.
/// @param[in] mem								A memory block that contains the new value in the specified format.
/// @param[in] littleEndian				If this value is true, the parameter is treated as little-endian ("Intel format"), otherwise big-endian ("Motorola format").
/// @return												OK on success.
		inline Result<void> Set(const Block<const Byte>& mem, Bool littleEndian);
/// Sets the value of this BigInteger.
/// @param[in] str								The new value, represented as a decimal string. The string may only contain decimal digits.
/// @return												OK on success.
		inline Result<void> Set(const String& str);
/// Sets the value of this BigInteger.
/// @param[in] str								The new value, represented as a hexadecimal string. The string may only contain hexadecimal digits.
/// @return												OK on success.
		inline Result<void> SetHex(const String& str);
/// Performs the add operation.
/// @param[in] b									The value to add to this.
		inline Result<void> Add(const BigIntegerInterface* b);
/// Performs the subtract operation.
/// @param[in] b									The value to subtract to this.
		inline Result<void> Sub(const BigIntegerInterface* b);
/// Increments the value by one.
		inline Result<void> Inc();
/// Decrements the value by one.
		inline Result<void> Dec();
/// Performs the multiply operation.
/// @param[in] b									The value to multiply to this.
		inline Result<void> Mul(const BigIntegerInterface* b);
/// Performs the divide operation.
/// @param[in] b									The value with which is this to divide. The result is 0, if b is 0 or if its absolute value is bigger than the absolute value of this.
		inline Result<void> Div(const BigIntegerInterface* b);
/// Performs the modulo operation.
/// @param[in] b									The modulus. The result is 0, if b is 0.
		inline Result<void> Mod(const BigIntegerInterface* b);
/// Performs the divide and modulo operation.
/// @param[in] b									The value with which is this to divide. The result is 0, if b is 0 or if its absolute value is bigger than the absolute value of this.
/// @param[out] r									The remainder of the division will be stored in r. The value of r is undefined if b is 0.
		inline Result<void> DivMod(const BigIntegerInterface* b, BigInteger& r);
/// Performs the power operation.
/// @param[in] b									Raises this to the power of b. The result will be 0 if b is negative.
		inline Result<void> Pow(const BigIntegerInterface* b);
/// Performs the power operation and takes the result modulo mod.
/// @param[in] b									Raises this to the power of b. The result will be 0 if b is negative.
/// @param[in] mod								The modulo value.
		inline Result<void> PowMod(const BigIntegerInterface* b, const BigIntegerInterface* mod);
/// Calculates the greatest common divisor of this and b. Both values must be greater than zero, otherwise the value will remain unchanged.
/// @param[in] b									Another BigInteger.
		inline Result<void> GreatestCommonDivisor(const BigIntegerInterface* b);
/// Calculates the multiplicative inverse of this modulo m. This must be smaller than m. The new result of this will be greater or equal to zero and smaller than m.
/// @param[in] m									Another BigInteger. This value must be greater than zero.
/// @return												True, if there is a multiplicative inverse, false otherwise. The value of this is unchanged if there is no multiplicative inverse.
		inline Result<Bool> MultiplicativeInverse(const BigIntegerInterface* m);
/// Performs the Left shift operation. If the number of bits to shift is less than 0 the bits are shifted right.
/// @param[in] s									The number of bits to shift.
		inline Result<void> LeftShift(Int s);
/// Performs the Right shift operation. If the number of bits to shift is less than 0 the bits are shifted left.
/// @param[in] s									The number of bits to shift.
		inline Result<void> RightShift(Int s);
/// Negates the value.
		inline Result<void> Negate();
/// Sets a bit in the integer.
/// @param[in] bit								The position of the bit which is to set.
		inline Result<void> SetBit(Int bit);
/// Clears a bit in the integer.
/// @param[in] bit								The position of the bit which is to clear.
		inline Result<void> ClearBit(Int bit);
/// Toggles a bit in the integer.
/// @param[in] bit								The position of the bit which is to toggle.
		inline Result<void> ToggleBit(Int bit);
	};
	template <typename ST> struct FnHelper : public std::conditional<
	maxon::Bool(ST::type::Handler::KIND & (maxon::VALUEKIND::COW_MASK | maxon::VALUEKIND::DEEP_CONSTNESS)),
	COWFn<typename ST::type>,
	typename std::conditional<std::is_const<typename ST::type::PrivateReferencedType>::value, ConstFn<typename ST::type>, Fn<typename ST::type>>::type
	> { };
};
class BigIntegerInterface::Reference :
#ifdef DOXYGEN
public COWFnDoxy<BigInteger>
#else
public maxon::RefBase<Hxx1::FnHelper<maxon::RefBaseFn<maxon::DirectRef<const BigIntegerInterface, maxon::StrongCOWRefHandler, BigInteger>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(Reference, maxon::RefBase<Hxx1::FnHelper<maxon::RefBaseFn<maxon::DirectRef<const BigIntegerInterface, maxon::StrongCOWRefHandler, BigInteger>>>>);
	using NonConst = Hxx1::NonConstRef;
	static MAXON_ATTRIBUTE_FORCE_INLINE maxon::ResultMemT<BigInteger> Create();
};

class BigIntegerInterface::Hxx1::NonConstRef :
#ifdef DOXYGEN
public FnDoxy<NonConstRef>
#else
public maxon::RefBase<Hxx1::FnHelper<maxon::RefBaseFn<maxon::DirectRef<BigIntegerInterface, maxon::StrongRefHandler, NonConstRef>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(NonConstRef, maxon::RefBase<Hxx1::FnHelper<maxon::RefBaseFn<maxon::DirectRef<BigIntegerInterface, maxon::StrongRefHandler, NonConstRef>>>>);
};

#endif
