
#ifndef DOXYGEN

#if defined MAXON_COMPILER_GCC
	#pragma GCC diagnostic push
	#if MAXON_COMPILER_GCC >= 600
		#pragma GCC diagnostic ignored "-Wmisleading-indentation"
	#endif
#endif

#if 1
constexpr const maxon::Char* BigIntegerInterface::PrivateGetCppName() { return "maxon::BigInteger"; }

struct BigIntegerInterface::MTable
{
	static MTable _instance;
	static MTable _unresolvedInstance;
	static const maxon::Char* const _ids;
	static maxon::Bool InitUnresolved(maxon::NonvirtualInterfaceReference::UnresolvedAssembler assembler, MTable* tbl);
	static const maxon::NULL_RETURN_TYPE _returnTypes[];
	static const maxon::Bool HAS_NONSTATIC = true;
	void (*BigIntegerInterface_Free) (const BigIntegerInterface* object);
	BigIntegerInterface* (*BigIntegerInterface_Alloc) (const maxon::SourceLocation& allocLocation);
	BigIntegerInterface* (*BigIntegerInterface_Alloc_1) (const maxon::SourceLocation& allocLocation, const BigIntegerInterface& object);
	BigIntegerInterface* (*BigIntegerInterface_Zero) ();
	BigIntegerInterface* (*BigIntegerInterface_One) ();
	BigIntegerInterface* (*BigIntegerInterface_MinusOne) ();
	Result<void> (*BigIntegerInterface_Set) (BigIntegerInterface* this_, Char c);
	Result<void> (*BigIntegerInterface_Set_1) (BigIntegerInterface* this_, UChar c);
	Result<void> (*BigIntegerInterface_Set_2) (BigIntegerInterface* this_, Int16 i);
	Result<void> (*BigIntegerInterface_Set_3) (BigIntegerInterface* this_, UInt16 u);
	Result<void> (*BigIntegerInterface_Set_4) (BigIntegerInterface* this_, Int32 i);
	Result<void> (*BigIntegerInterface_Set_5) (BigIntegerInterface* this_, UInt32 u);
	Result<void> (*BigIntegerInterface_Set_6) (BigIntegerInterface* this_, Int64 i);
	Result<void> (*BigIntegerInterface_Set_7) (BigIntegerInterface* this_, UInt64 u);
	Result<void> (*BigIntegerInterface_SetRandom) (BigIntegerInterface* this_, Int bitCount, SecureRandomProvider provider);
	Result<void> (*BigIntegerInterface_SetRandomPrime) (BigIntegerInterface* this_, Int bitCount, UInt certainty, SecureRandomProvider provider);
	Result<void> (*BigIntegerInterface_Set_8) (BigIntegerInterface* this_, const Block<const Byte>& mem, Bool littleEndian);
	Result<void> (*BigIntegerInterface_Set_9) (BigIntegerInterface* this_, const String& str);
	Result<void> (*BigIntegerInterface_SetHex) (BigIntegerInterface* this_, const String& str);
	Bool (*BigIntegerInterface_IsEven) (const BigIntegerInterface* this_);
	Bool (*BigIntegerInterface_IsOdd) (const BigIntegerInterface* this_);
	Bool (*BigIntegerInterface_IsOne) (const BigIntegerInterface* this_);
	Bool (*BigIntegerInterface_IsZero) (const BigIntegerInterface* this_);
	Bool (*BigIntegerInterface_IsNegative) (const BigIntegerInterface* this_);
	Bool (*BigIntegerInterface_IsPowerOfTwo) (const BigIntegerInterface* this_);
	Result<Bool> (*BigIntegerInterface_IsProbablyPrime) (const BigIntegerInterface* this_, UInt certainty);
	Int (*BigIntegerInterface_Sign) (const BigIntegerInterface* this_);
	Int (*BigIntegerInterface_GetHighestNonSignBit) (const BigIntegerInterface* this_);
	Int (*BigIntegerInterface_GetLowestSetBit) (const BigIntegerInterface* this_);
	Int (*BigIntegerInterface_GetLowestClearedBit) (const BigIntegerInterface* this_);
	Bool (*BigIntegerInterface_IsBitSet) (const BigIntegerInterface* this_, Int bit);
	UChar (*BigIntegerInterface_GetLowestBits8U) (const BigIntegerInterface* this_);
	Char (*BigIntegerInterface_GetLowestBits8S) (const BigIntegerInterface* this_);
	UInt16 (*BigIntegerInterface_GetLowestBits16U) (const BigIntegerInterface* this_);
	Int16 (*BigIntegerInterface_GetLowestBits16S) (const BigIntegerInterface* this_);
	UInt32 (*BigIntegerInterface_GetLowestBits32U) (const BigIntegerInterface* this_);
	Int32 (*BigIntegerInterface_GetLowestBits32S) (const BigIntegerInterface* this_);
	UInt64 (*BigIntegerInterface_GetLowestBits64U) (const BigIntegerInterface* this_);
	Int64 (*BigIntegerInterface_GetLowestBits64S) (const BigIntegerInterface* this_);
	Result<void> (*BigIntegerInterface_GetDataCopy) (const BigIntegerInterface* this_, Bool littleEndian, BaseArray<UChar>& data);
	Result<void> (*BigIntegerInterface_Add) (BigIntegerInterface* this_, const BigIntegerInterface* b);
	Result<void> (*BigIntegerInterface_Sub) (BigIntegerInterface* this_, const BigIntegerInterface* b);
	Result<void> (*BigIntegerInterface_Inc) (BigIntegerInterface* this_);
	Result<void> (*BigIntegerInterface_Dec) (BigIntegerInterface* this_);
	Result<void> (*BigIntegerInterface_Mul) (BigIntegerInterface* this_, const BigIntegerInterface* b);
	Result<void> (*BigIntegerInterface_Div) (BigIntegerInterface* this_, const BigIntegerInterface* b);
	Result<void> (*BigIntegerInterface_Mod) (BigIntegerInterface* this_, const BigIntegerInterface* b);
	Result<void> (*BigIntegerInterface_DivMod) (BigIntegerInterface* this_, const BigIntegerInterface* b, BigInteger& r);
	Result<void> (*BigIntegerInterface_Pow) (BigIntegerInterface* this_, const BigIntegerInterface* b);
	Result<void> (*BigIntegerInterface_PowMod) (BigIntegerInterface* this_, const BigIntegerInterface* b, const BigIntegerInterface* mod);
	Result<void> (*BigIntegerInterface_GreatestCommonDivisor) (BigIntegerInterface* this_, const BigIntegerInterface* b);
	Result<Bool> (*BigIntegerInterface_MultiplicativeInverse) (BigIntegerInterface* this_, const BigIntegerInterface* m);
	Result<void> (*BigIntegerInterface_LeftShift) (BigIntegerInterface* this_, Int s);
	Result<void> (*BigIntegerInterface_RightShift) (BigIntegerInterface* this_, Int s);
	Result<void> (*BigIntegerInterface_Negate) (BigIntegerInterface* this_);
	Result<void> (*BigIntegerInterface_SetBit) (BigIntegerInterface* this_, Int bit);
	Result<void> (*BigIntegerInterface_ClearBit) (BigIntegerInterface* this_, Int bit);
	Result<void> (*BigIntegerInterface_ToggleBit) (BigIntegerInterface* this_, Int bit);
	COMPARERESULT (*BigIntegerInterface_Compare) (const BigIntegerInterface* this_, const BigIntegerInterface* arg2);
	HashInt (*BigIntegerInterface_GetHashCode) (const BigIntegerInterface* this_);
	String (*BigIntegerInterface_ToString) (const BigIntegerInterface* this_, const FormatStatement* formatStatement);
	Result<void> (*BigIntegerInterface_DescribeIO) (const DataSerializeInterface& stream);
	template <typename IMPL> void Init()
	{
		BigIntegerInterface_Free = &IMPL::BigIntegerInterface_Free;
		BigIntegerInterface_Alloc = &IMPL::BigIntegerInterface_Alloc;
		BigIntegerInterface_Alloc_1 = &IMPL::BigIntegerInterface_Alloc_1;
		BigIntegerInterface_Zero = &IMPL::BigIntegerInterface_Zero;
		BigIntegerInterface_One = &IMPL::BigIntegerInterface_One;
		BigIntegerInterface_MinusOne = &IMPL::BigIntegerInterface_MinusOne;
		BigIntegerInterface_Set = &IMPL::BigIntegerInterface_Set;
		BigIntegerInterface_Set_1 = &IMPL::BigIntegerInterface_Set_1;
		BigIntegerInterface_Set_2 = &IMPL::BigIntegerInterface_Set_2;
		BigIntegerInterface_Set_3 = &IMPL::BigIntegerInterface_Set_3;
		BigIntegerInterface_Set_4 = &IMPL::BigIntegerInterface_Set_4;
		BigIntegerInterface_Set_5 = &IMPL::BigIntegerInterface_Set_5;
		BigIntegerInterface_Set_6 = &IMPL::BigIntegerInterface_Set_6;
		BigIntegerInterface_Set_7 = &IMPL::BigIntegerInterface_Set_7;
		BigIntegerInterface_SetRandom = &IMPL::BigIntegerInterface_SetRandom;
		BigIntegerInterface_SetRandomPrime = &IMPL::BigIntegerInterface_SetRandomPrime;
		BigIntegerInterface_Set_8 = &IMPL::BigIntegerInterface_Set_8;
		BigIntegerInterface_Set_9 = &IMPL::BigIntegerInterface_Set_9;
		BigIntegerInterface_SetHex = &IMPL::BigIntegerInterface_SetHex;
		BigIntegerInterface_IsEven = &IMPL::BigIntegerInterface_IsEven;
		BigIntegerInterface_IsOdd = &IMPL::BigIntegerInterface_IsOdd;
		BigIntegerInterface_IsOne = &IMPL::BigIntegerInterface_IsOne;
		BigIntegerInterface_IsZero = &IMPL::BigIntegerInterface_IsZero;
		BigIntegerInterface_IsNegative = &IMPL::BigIntegerInterface_IsNegative;
		BigIntegerInterface_IsPowerOfTwo = &IMPL::BigIntegerInterface_IsPowerOfTwo;
		BigIntegerInterface_IsProbablyPrime = &IMPL::BigIntegerInterface_IsProbablyPrime;
		BigIntegerInterface_Sign = &IMPL::BigIntegerInterface_Sign;
		BigIntegerInterface_GetHighestNonSignBit = &IMPL::BigIntegerInterface_GetHighestNonSignBit;
		BigIntegerInterface_GetLowestSetBit = &IMPL::BigIntegerInterface_GetLowestSetBit;
		BigIntegerInterface_GetLowestClearedBit = &IMPL::BigIntegerInterface_GetLowestClearedBit;
		BigIntegerInterface_IsBitSet = &IMPL::BigIntegerInterface_IsBitSet;
		BigIntegerInterface_GetLowestBits8U = &IMPL::BigIntegerInterface_GetLowestBits8U;
		BigIntegerInterface_GetLowestBits8S = &IMPL::BigIntegerInterface_GetLowestBits8S;
		BigIntegerInterface_GetLowestBits16U = &IMPL::BigIntegerInterface_GetLowestBits16U;
		BigIntegerInterface_GetLowestBits16S = &IMPL::BigIntegerInterface_GetLowestBits16S;
		BigIntegerInterface_GetLowestBits32U = &IMPL::BigIntegerInterface_GetLowestBits32U;
		BigIntegerInterface_GetLowestBits32S = &IMPL::BigIntegerInterface_GetLowestBits32S;
		BigIntegerInterface_GetLowestBits64U = &IMPL::BigIntegerInterface_GetLowestBits64U;
		BigIntegerInterface_GetLowestBits64S = &IMPL::BigIntegerInterface_GetLowestBits64S;
		BigIntegerInterface_GetDataCopy = &IMPL::BigIntegerInterface_GetDataCopy;
		BigIntegerInterface_Add = &IMPL::BigIntegerInterface_Add;
		BigIntegerInterface_Sub = &IMPL::BigIntegerInterface_Sub;
		BigIntegerInterface_Inc = &IMPL::BigIntegerInterface_Inc;
		BigIntegerInterface_Dec = &IMPL::BigIntegerInterface_Dec;
		BigIntegerInterface_Mul = &IMPL::BigIntegerInterface_Mul;
		BigIntegerInterface_Div = &IMPL::BigIntegerInterface_Div;
		BigIntegerInterface_Mod = &IMPL::BigIntegerInterface_Mod;
		BigIntegerInterface_DivMod = &IMPL::BigIntegerInterface_DivMod;
		BigIntegerInterface_Pow = &IMPL::BigIntegerInterface_Pow;
		BigIntegerInterface_PowMod = &IMPL::BigIntegerInterface_PowMod;
		BigIntegerInterface_GreatestCommonDivisor = &IMPL::BigIntegerInterface_GreatestCommonDivisor;
		BigIntegerInterface_MultiplicativeInverse = &IMPL::BigIntegerInterface_MultiplicativeInverse;
		BigIntegerInterface_LeftShift = &IMPL::BigIntegerInterface_LeftShift;
		BigIntegerInterface_RightShift = &IMPL::BigIntegerInterface_RightShift;
		BigIntegerInterface_Negate = &IMPL::BigIntegerInterface_Negate;
		BigIntegerInterface_SetBit = &IMPL::BigIntegerInterface_SetBit;
		BigIntegerInterface_ClearBit = &IMPL::BigIntegerInterface_ClearBit;
		BigIntegerInterface_ToggleBit = &IMPL::BigIntegerInterface_ToggleBit;
		BigIntegerInterface_Compare = &IMPL::BigIntegerInterface_Compare;
		BigIntegerInterface_GetHashCode = &IMPL::BigIntegerInterface_GetHashCode;
		BigIntegerInterface_ToString = &IMPL::BigIntegerInterface_ToString;
		BigIntegerInterface_DescribeIO = &IMPL::BigIntegerInterface_DescribeIO;
	}
};

struct BigIntegerInterface::Hxx2
{
	class Unresolved;
	template <typename C> class Wrapper
	{
	public:
		static void BigIntegerInterface_Free(const BigIntegerInterface* object) { return C::Free(object); }
		static BigIntegerInterface* BigIntegerInterface_Alloc(const maxon::SourceLocation& allocLocation) { return C::Alloc(allocLocation); }
		static BigIntegerInterface* BigIntegerInterface_Alloc_1(const maxon::SourceLocation& allocLocation, const BigIntegerInterface& object) { return C::Alloc(allocLocation, ((const C&) object)); }
		static BigIntegerInterface* BigIntegerInterface_Zero() { return C::Zero(); }
		static BigIntegerInterface* BigIntegerInterface_One() { return C::One(); }
		static BigIntegerInterface* BigIntegerInterface_MinusOne() { return C::MinusOne(); }
		static Result<void> BigIntegerInterface_Set(BigIntegerInterface* this_, Char c) { return C::Get(this_)->Set(c); }
		static Result<void> BigIntegerInterface_Set_1(BigIntegerInterface* this_, UChar c) { return C::Get(this_)->Set(c); }
		static Result<void> BigIntegerInterface_Set_2(BigIntegerInterface* this_, Int16 i) { return C::Get(this_)->Set(i); }
		static Result<void> BigIntegerInterface_Set_3(BigIntegerInterface* this_, UInt16 u) { return C::Get(this_)->Set(u); }
		static Result<void> BigIntegerInterface_Set_4(BigIntegerInterface* this_, Int32 i) { return C::Get(this_)->Set(i); }
		static Result<void> BigIntegerInterface_Set_5(BigIntegerInterface* this_, UInt32 u) { return C::Get(this_)->Set(u); }
		static Result<void> BigIntegerInterface_Set_6(BigIntegerInterface* this_, Int64 i) { return C::Get(this_)->Set(i); }
		static Result<void> BigIntegerInterface_Set_7(BigIntegerInterface* this_, UInt64 u) { return C::Get(this_)->Set(u); }
		static Result<void> BigIntegerInterface_SetRandom(BigIntegerInterface* this_, Int bitCount, SecureRandomProvider provider) { return C::Get(this_)->SetRandom(bitCount, std::forward<SecureRandomProvider>(provider)); }
		static Result<void> BigIntegerInterface_SetRandomPrime(BigIntegerInterface* this_, Int bitCount, UInt certainty, SecureRandomProvider provider) { return C::Get(this_)->SetRandomPrime(bitCount, certainty, std::forward<SecureRandomProvider>(provider)); }
		static Result<void> BigIntegerInterface_Set_8(BigIntegerInterface* this_, const Block<const Byte>& mem, Bool littleEndian) { return C::Get(this_)->Set(mem, littleEndian); }
		static Result<void> BigIntegerInterface_Set_9(BigIntegerInterface* this_, const String& str) { return C::Get(this_)->Set(str); }
		static Result<void> BigIntegerInterface_SetHex(BigIntegerInterface* this_, const String& str) { return C::Get(this_)->SetHex(str); }
		static Bool BigIntegerInterface_IsEven(const BigIntegerInterface* this_) { return C::Get(this_)->IsEven(); }
		static Bool BigIntegerInterface_IsOdd(const BigIntegerInterface* this_) { return C::Get(this_)->IsOdd(); }
		static Bool BigIntegerInterface_IsOne(const BigIntegerInterface* this_) { return C::Get(this_)->IsOne(); }
		static Bool BigIntegerInterface_IsZero(const BigIntegerInterface* this_) { return C::Get(this_)->IsZero(); }
		static Bool BigIntegerInterface_IsNegative(const BigIntegerInterface* this_) { return C::Get(this_)->IsNegative(); }
		static Bool BigIntegerInterface_IsPowerOfTwo(const BigIntegerInterface* this_) { return C::Get(this_)->IsPowerOfTwo(); }
		static Result<Bool> BigIntegerInterface_IsProbablyPrime(const BigIntegerInterface* this_, UInt certainty) { return C::Get(this_)->IsProbablyPrime(certainty); }
		static Int BigIntegerInterface_Sign(const BigIntegerInterface* this_) { return C::Get(this_)->Sign(); }
		static Int BigIntegerInterface_GetHighestNonSignBit(const BigIntegerInterface* this_) { return C::Get(this_)->GetHighestNonSignBit(); }
		static Int BigIntegerInterface_GetLowestSetBit(const BigIntegerInterface* this_) { return C::Get(this_)->GetLowestSetBit(); }
		static Int BigIntegerInterface_GetLowestClearedBit(const BigIntegerInterface* this_) { return C::Get(this_)->GetLowestClearedBit(); }
		static Bool BigIntegerInterface_IsBitSet(const BigIntegerInterface* this_, Int bit) { return C::Get(this_)->IsBitSet(bit); }
		static UChar BigIntegerInterface_GetLowestBits8U(const BigIntegerInterface* this_) { return C::Get(this_)->GetLowestBits8U(); }
		static Char BigIntegerInterface_GetLowestBits8S(const BigIntegerInterface* this_) { return C::Get(this_)->GetLowestBits8S(); }
		static UInt16 BigIntegerInterface_GetLowestBits16U(const BigIntegerInterface* this_) { return C::Get(this_)->GetLowestBits16U(); }
		static Int16 BigIntegerInterface_GetLowestBits16S(const BigIntegerInterface* this_) { return C::Get(this_)->GetLowestBits16S(); }
		static UInt32 BigIntegerInterface_GetLowestBits32U(const BigIntegerInterface* this_) { return C::Get(this_)->GetLowestBits32U(); }
		static Int32 BigIntegerInterface_GetLowestBits32S(const BigIntegerInterface* this_) { return C::Get(this_)->GetLowestBits32S(); }
		static UInt64 BigIntegerInterface_GetLowestBits64U(const BigIntegerInterface* this_) { return C::Get(this_)->GetLowestBits64U(); }
		static Int64 BigIntegerInterface_GetLowestBits64S(const BigIntegerInterface* this_) { return C::Get(this_)->GetLowestBits64S(); }
		static Result<void> BigIntegerInterface_GetDataCopy(const BigIntegerInterface* this_, Bool littleEndian, BaseArray<UChar>& data) { return C::Get(this_)->GetDataCopy(littleEndian, data); }
		static Result<void> BigIntegerInterface_Add(BigIntegerInterface* this_, const BigIntegerInterface* b) { return C::Get(this_)->Add(b); }
		static Result<void> BigIntegerInterface_Sub(BigIntegerInterface* this_, const BigIntegerInterface* b) { return C::Get(this_)->Sub(b); }
		static Result<void> BigIntegerInterface_Inc(BigIntegerInterface* this_) { return C::Get(this_)->Inc(); }
		static Result<void> BigIntegerInterface_Dec(BigIntegerInterface* this_) { return C::Get(this_)->Dec(); }
		static Result<void> BigIntegerInterface_Mul(BigIntegerInterface* this_, const BigIntegerInterface* b) { return C::Get(this_)->Mul(b); }
		static Result<void> BigIntegerInterface_Div(BigIntegerInterface* this_, const BigIntegerInterface* b) { return C::Get(this_)->Div(b); }
		static Result<void> BigIntegerInterface_Mod(BigIntegerInterface* this_, const BigIntegerInterface* b) { return C::Get(this_)->Mod(b); }
		static Result<void> BigIntegerInterface_DivMod(BigIntegerInterface* this_, const BigIntegerInterface* b, BigInteger& r) { return C::Get(this_)->DivMod(b, r); }
		static Result<void> BigIntegerInterface_Pow(BigIntegerInterface* this_, const BigIntegerInterface* b) { return C::Get(this_)->Pow(b); }
		static Result<void> BigIntegerInterface_PowMod(BigIntegerInterface* this_, const BigIntegerInterface* b, const BigIntegerInterface* mod) { return C::Get(this_)->PowMod(b, mod); }
		static Result<void> BigIntegerInterface_GreatestCommonDivisor(BigIntegerInterface* this_, const BigIntegerInterface* b) { return C::Get(this_)->GreatestCommonDivisor(b); }
		static Result<Bool> BigIntegerInterface_MultiplicativeInverse(BigIntegerInterface* this_, const BigIntegerInterface* m) { return C::Get(this_)->MultiplicativeInverse(m); }
		static Result<void> BigIntegerInterface_LeftShift(BigIntegerInterface* this_, Int s) { return C::Get(this_)->LeftShift(s); }
		static Result<void> BigIntegerInterface_RightShift(BigIntegerInterface* this_, Int s) { return C::Get(this_)->RightShift(s); }
		static Result<void> BigIntegerInterface_Negate(BigIntegerInterface* this_) { return C::Get(this_)->Negate(); }
		static Result<void> BigIntegerInterface_SetBit(BigIntegerInterface* this_, Int bit) { return C::Get(this_)->SetBit(bit); }
		static Result<void> BigIntegerInterface_ClearBit(BigIntegerInterface* this_, Int bit) { return C::Get(this_)->ClearBit(bit); }
		static Result<void> BigIntegerInterface_ToggleBit(BigIntegerInterface* this_, Int bit) { return C::Get(this_)->ToggleBit(bit); }
		static COMPARERESULT BigIntegerInterface_Compare(const BigIntegerInterface* this_, const BigIntegerInterface* arg2) { return C::Get(this_)->Compare(arg2); }
		static HashInt BigIntegerInterface_GetHashCode(const BigIntegerInterface* this_) { return C::Get(this_)->GetHashCode(); }
		static String BigIntegerInterface_ToString(const BigIntegerInterface* this_, const FormatStatement* formatStatement) { return C::Get(this_)->ToString(formatStatement); }
		static Result<void> BigIntegerInterface_DescribeIO(const DataSerializeInterface& stream) { return C::DescribeIO(stream); }
	};

};
MAXON_ATTRIBUTE_FORCE_INLINE auto BigIntegerInterface::Free(const BigIntegerInterface* object) -> void
{
	return MTable::_instance.BigIntegerInterface_Free(object);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto BigIntegerInterface::Alloc(const maxon::SourceLocation& allocLocation) -> BigIntegerInterface*
{
	return MTable::_instance.BigIntegerInterface_Alloc(allocLocation);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto BigIntegerInterface::Alloc(const maxon::SourceLocation& allocLocation, const BigIntegerInterface& object) -> BigIntegerInterface*
{
	return MTable::_instance.BigIntegerInterface_Alloc_1(allocLocation, object);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto BigIntegerInterface::Zero() -> BigIntegerInterface*
{
	return MTable::_instance.BigIntegerInterface_Zero();
}
MAXON_ATTRIBUTE_FORCE_INLINE auto BigIntegerInterface::One() -> BigIntegerInterface*
{
	return MTable::_instance.BigIntegerInterface_One();
}
MAXON_ATTRIBUTE_FORCE_INLINE auto BigIntegerInterface::MinusOne() -> BigIntegerInterface*
{
	return MTable::_instance.BigIntegerInterface_MinusOne();
}
MAXON_ATTRIBUTE_FORCE_INLINE auto BigIntegerInterface::Set(Char c) -> Result<void>
{
	return MTable::_instance.BigIntegerInterface_Set(this, c);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto BigIntegerInterface::Set(UChar c) -> Result<void>
{
	return MTable::_instance.BigIntegerInterface_Set_1(this, c);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto BigIntegerInterface::Set(Int16 i) -> Result<void>
{
	return MTable::_instance.BigIntegerInterface_Set_2(this, i);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto BigIntegerInterface::Set(UInt16 u) -> Result<void>
{
	return MTable::_instance.BigIntegerInterface_Set_3(this, u);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto BigIntegerInterface::Set(Int32 i) -> Result<void>
{
	return MTable::_instance.BigIntegerInterface_Set_4(this, i);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto BigIntegerInterface::Set(UInt32 u) -> Result<void>
{
	return MTable::_instance.BigIntegerInterface_Set_5(this, u);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto BigIntegerInterface::Set(Int64 i) -> Result<void>
{
	return MTable::_instance.BigIntegerInterface_Set_6(this, i);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto BigIntegerInterface::Set(UInt64 u) -> Result<void>
{
	return MTable::_instance.BigIntegerInterface_Set_7(this, u);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto BigIntegerInterface::SetRandom(Int bitCount, SecureRandomProvider provider) -> Result<void>
{
	return MTable::_instance.BigIntegerInterface_SetRandom(this, bitCount, std::forward<SecureRandomProvider>(provider));
}
MAXON_ATTRIBUTE_FORCE_INLINE auto BigIntegerInterface::SetRandomPrime(Int bitCount, UInt certainty, SecureRandomProvider provider) -> Result<void>
{
	return MTable::_instance.BigIntegerInterface_SetRandomPrime(this, bitCount, certainty, std::forward<SecureRandomProvider>(provider));
}
MAXON_ATTRIBUTE_FORCE_INLINE auto BigIntegerInterface::Set(const Block<const Byte>& mem, Bool littleEndian) -> Result<void>
{
	return MTable::_instance.BigIntegerInterface_Set_8(this, mem, littleEndian);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto BigIntegerInterface::Set(const String& str) -> Result<void>
{
	return MTable::_instance.BigIntegerInterface_Set_9(this, str);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto BigIntegerInterface::SetHex(const String& str) -> Result<void>
{
	return MTable::_instance.BigIntegerInterface_SetHex(this, str);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto BigIntegerInterface::IsEven() const -> Bool
{
	return MTable::_instance.BigIntegerInterface_IsEven(this);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto BigIntegerInterface::IsOdd() const -> Bool
{
	return MTable::_instance.BigIntegerInterface_IsOdd(this);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto BigIntegerInterface::IsOne() const -> Bool
{
	return MTable::_instance.BigIntegerInterface_IsOne(this);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto BigIntegerInterface::IsZero() const -> Bool
{
	return MTable::_instance.BigIntegerInterface_IsZero(this);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto BigIntegerInterface::IsNegative() const -> Bool
{
	return MTable::_instance.BigIntegerInterface_IsNegative(this);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto BigIntegerInterface::IsPowerOfTwo() const -> Bool
{
	return MTable::_instance.BigIntegerInterface_IsPowerOfTwo(this);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto BigIntegerInterface::IsProbablyPrime(UInt certainty) const -> Result<Bool>
{
	return MTable::_instance.BigIntegerInterface_IsProbablyPrime(this, certainty);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto BigIntegerInterface::Sign() const -> Int
{
	return MTable::_instance.BigIntegerInterface_Sign(this);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto BigIntegerInterface::GetHighestNonSignBit() const -> Int
{
	return MTable::_instance.BigIntegerInterface_GetHighestNonSignBit(this);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto BigIntegerInterface::GetLowestSetBit() const -> Int
{
	return MTable::_instance.BigIntegerInterface_GetLowestSetBit(this);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto BigIntegerInterface::GetLowestClearedBit() const -> Int
{
	return MTable::_instance.BigIntegerInterface_GetLowestClearedBit(this);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto BigIntegerInterface::IsBitSet(Int bit) const -> Bool
{
	return MTable::_instance.BigIntegerInterface_IsBitSet(this, bit);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto BigIntegerInterface::GetLowestBits8U() const -> UChar
{
	return MTable::_instance.BigIntegerInterface_GetLowestBits8U(this);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto BigIntegerInterface::GetLowestBits8S() const -> Char
{
	return MTable::_instance.BigIntegerInterface_GetLowestBits8S(this);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto BigIntegerInterface::GetLowestBits16U() const -> UInt16
{
	return MTable::_instance.BigIntegerInterface_GetLowestBits16U(this);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto BigIntegerInterface::GetLowestBits16S() const -> Int16
{
	return MTable::_instance.BigIntegerInterface_GetLowestBits16S(this);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto BigIntegerInterface::GetLowestBits32U() const -> UInt32
{
	return MTable::_instance.BigIntegerInterface_GetLowestBits32U(this);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto BigIntegerInterface::GetLowestBits32S() const -> Int32
{
	return MTable::_instance.BigIntegerInterface_GetLowestBits32S(this);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto BigIntegerInterface::GetLowestBits64U() const -> UInt64
{
	return MTable::_instance.BigIntegerInterface_GetLowestBits64U(this);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto BigIntegerInterface::GetLowestBits64S() const -> Int64
{
	return MTable::_instance.BigIntegerInterface_GetLowestBits64S(this);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto BigIntegerInterface::GetDataCopy(Bool littleEndian, BaseArray<UChar>& data) const -> Result<void>
{
	return MTable::_instance.BigIntegerInterface_GetDataCopy(this, littleEndian, data);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto BigIntegerInterface::Add(const BigIntegerInterface* b) -> Result<void>
{
	return MTable::_instance.BigIntegerInterface_Add(this, b);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto BigIntegerInterface::Sub(const BigIntegerInterface* b) -> Result<void>
{
	return MTable::_instance.BigIntegerInterface_Sub(this, b);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto BigIntegerInterface::Inc() -> Result<void>
{
	return MTable::_instance.BigIntegerInterface_Inc(this);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto BigIntegerInterface::Dec() -> Result<void>
{
	return MTable::_instance.BigIntegerInterface_Dec(this);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto BigIntegerInterface::Mul(const BigIntegerInterface* b) -> Result<void>
{
	return MTable::_instance.BigIntegerInterface_Mul(this, b);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto BigIntegerInterface::Div(const BigIntegerInterface* b) -> Result<void>
{
	return MTable::_instance.BigIntegerInterface_Div(this, b);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto BigIntegerInterface::Mod(const BigIntegerInterface* b) -> Result<void>
{
	return MTable::_instance.BigIntegerInterface_Mod(this, b);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto BigIntegerInterface::DivMod(const BigIntegerInterface* b, BigInteger& r) -> Result<void>
{
	return MTable::_instance.BigIntegerInterface_DivMod(this, b, r);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto BigIntegerInterface::Pow(const BigIntegerInterface* b) -> Result<void>
{
	return MTable::_instance.BigIntegerInterface_Pow(this, b);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto BigIntegerInterface::PowMod(const BigIntegerInterface* b, const BigIntegerInterface* mod) -> Result<void>
{
	return MTable::_instance.BigIntegerInterface_PowMod(this, b, mod);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto BigIntegerInterface::GreatestCommonDivisor(const BigIntegerInterface* b) -> Result<void>
{
	return MTable::_instance.BigIntegerInterface_GreatestCommonDivisor(this, b);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto BigIntegerInterface::MultiplicativeInverse(const BigIntegerInterface* m) -> Result<Bool>
{
	return MTable::_instance.BigIntegerInterface_MultiplicativeInverse(this, m);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto BigIntegerInterface::LeftShift(Int s) -> Result<void>
{
	return MTable::_instance.BigIntegerInterface_LeftShift(this, s);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto BigIntegerInterface::RightShift(Int s) -> Result<void>
{
	return MTable::_instance.BigIntegerInterface_RightShift(this, s);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto BigIntegerInterface::Negate() -> Result<void>
{
	return MTable::_instance.BigIntegerInterface_Negate(this);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto BigIntegerInterface::SetBit(Int bit) -> Result<void>
{
	return MTable::_instance.BigIntegerInterface_SetBit(this, bit);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto BigIntegerInterface::ClearBit(Int bit) -> Result<void>
{
	return MTable::_instance.BigIntegerInterface_ClearBit(this, bit);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto BigIntegerInterface::ToggleBit(Int bit) -> Result<void>
{
	return MTable::_instance.BigIntegerInterface_ToggleBit(this, bit);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto BigIntegerInterface::Compare(const BigIntegerInterface* arg2) const -> COMPARERESULT
{
	return MTable::_instance.BigIntegerInterface_Compare(this, arg2);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto BigIntegerInterface::GetHashCode() const -> HashInt
{
	return MTable::_instance.BigIntegerInterface_GetHashCode(this);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto BigIntegerInterface::ToString(const FormatStatement* formatStatement) const -> String
{
	return MTable::_instance.BigIntegerInterface_ToString(this, formatStatement);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto BigIntegerInterface::DescribeIO(const DataSerializeInterface& stream) -> Result<void>
{
	return MTable::_instance.BigIntegerInterface_DescribeIO(stream);
}

auto BigIntegerInterface::Reference::Create() -> maxon::ResultMemT<BigInteger>
{
	BigIntegerInterface* res_ = BigIntegerInterface::Alloc(MAXON_SOURCE_LOCATION);
	return BigInteger(maxon::ForwardResultPtr<BigIntegerInterface>(res_));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto BigIntegerInterface::Hxx1::ConstFn<S>::Zero() -> BigInteger
{
	return BigInteger(MTable::_instance.BigIntegerInterface_Zero());
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto BigIntegerInterface::Hxx1::ConstFn<S>::One() -> BigInteger
{
	return BigInteger(MTable::_instance.BigIntegerInterface_One());
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto BigIntegerInterface::Hxx1::ConstFn<S>::MinusOne() -> BigInteger
{
	return BigInteger(MTable::_instance.BigIntegerInterface_MinusOne());
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto BigIntegerInterface::Hxx1::Fn<S>::Set(Char c) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); BigIntegerInterface* o_ = (BigIntegerInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (MTable::_instance.BigIntegerInterface_Set(o_, c));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto BigIntegerInterface::Hxx1::COWFn<S>::Set(Char c) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); BigIntegerInterface* o_ = (BigIntegerInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } 
	return (MTable::_instance.BigIntegerInterface_Set(o_, c));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto BigIntegerInterface::Hxx1::Fn<S>::Set(UChar c) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); BigIntegerInterface* o_ = (BigIntegerInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (MTable::_instance.BigIntegerInterface_Set_1(o_, c));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto BigIntegerInterface::Hxx1::COWFn<S>::Set(UChar c) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); BigIntegerInterface* o_ = (BigIntegerInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } 
	return (MTable::_instance.BigIntegerInterface_Set_1(o_, c));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto BigIntegerInterface::Hxx1::Fn<S>::Set(Int16 i) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); BigIntegerInterface* o_ = (BigIntegerInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (MTable::_instance.BigIntegerInterface_Set_2(o_, i));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto BigIntegerInterface::Hxx1::COWFn<S>::Set(Int16 i) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); BigIntegerInterface* o_ = (BigIntegerInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } 
	return (MTable::_instance.BigIntegerInterface_Set_2(o_, i));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto BigIntegerInterface::Hxx1::Fn<S>::Set(UInt16 u) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); BigIntegerInterface* o_ = (BigIntegerInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (MTable::_instance.BigIntegerInterface_Set_3(o_, u));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto BigIntegerInterface::Hxx1::COWFn<S>::Set(UInt16 u) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); BigIntegerInterface* o_ = (BigIntegerInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } 
	return (MTable::_instance.BigIntegerInterface_Set_3(o_, u));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto BigIntegerInterface::Hxx1::Fn<S>::Set(Int32 i) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); BigIntegerInterface* o_ = (BigIntegerInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (MTable::_instance.BigIntegerInterface_Set_4(o_, i));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto BigIntegerInterface::Hxx1::COWFn<S>::Set(Int32 i) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); BigIntegerInterface* o_ = (BigIntegerInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } 
	return (MTable::_instance.BigIntegerInterface_Set_4(o_, i));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto BigIntegerInterface::Hxx1::Fn<S>::Set(UInt32 u) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); BigIntegerInterface* o_ = (BigIntegerInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (MTable::_instance.BigIntegerInterface_Set_5(o_, u));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto BigIntegerInterface::Hxx1::COWFn<S>::Set(UInt32 u) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); BigIntegerInterface* o_ = (BigIntegerInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } 
	return (MTable::_instance.BigIntegerInterface_Set_5(o_, u));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto BigIntegerInterface::Hxx1::Fn<S>::Set(Int64 i) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); BigIntegerInterface* o_ = (BigIntegerInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (MTable::_instance.BigIntegerInterface_Set_6(o_, i));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto BigIntegerInterface::Hxx1::COWFn<S>::Set(Int64 i) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); BigIntegerInterface* o_ = (BigIntegerInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } 
	return (MTable::_instance.BigIntegerInterface_Set_6(o_, i));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto BigIntegerInterface::Hxx1::Fn<S>::Set(UInt64 u) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); BigIntegerInterface* o_ = (BigIntegerInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (MTable::_instance.BigIntegerInterface_Set_7(o_, u));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto BigIntegerInterface::Hxx1::COWFn<S>::Set(UInt64 u) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); BigIntegerInterface* o_ = (BigIntegerInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } 
	return (MTable::_instance.BigIntegerInterface_Set_7(o_, u));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto BigIntegerInterface::Hxx1::Fn<S>::SetRandom(Int bitCount, SecureRandomProvider provider) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); BigIntegerInterface* o_ = (BigIntegerInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (MTable::_instance.BigIntegerInterface_SetRandom(o_, bitCount, std::forward<SecureRandomProvider>(provider)));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto BigIntegerInterface::Hxx1::COWFn<S>::SetRandom(Int bitCount, SecureRandomProvider provider) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); BigIntegerInterface* o_ = (BigIntegerInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } 
	return (MTable::_instance.BigIntegerInterface_SetRandom(o_, bitCount, std::forward<SecureRandomProvider>(provider)));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto BigIntegerInterface::Hxx1::Fn<S>::SetRandomPrime(Int bitCount, UInt certainty, SecureRandomProvider provider) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); BigIntegerInterface* o_ = (BigIntegerInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (MTable::_instance.BigIntegerInterface_SetRandomPrime(o_, bitCount, certainty, std::forward<SecureRandomProvider>(provider)));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto BigIntegerInterface::Hxx1::COWFn<S>::SetRandomPrime(Int bitCount, UInt certainty, SecureRandomProvider provider) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); BigIntegerInterface* o_ = (BigIntegerInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } 
	return (MTable::_instance.BigIntegerInterface_SetRandomPrime(o_, bitCount, certainty, std::forward<SecureRandomProvider>(provider)));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto BigIntegerInterface::Hxx1::Fn<S>::Set(const Block<const Byte>& mem, Bool littleEndian) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); BigIntegerInterface* o_ = (BigIntegerInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (MTable::_instance.BigIntegerInterface_Set_8(o_, mem, littleEndian));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto BigIntegerInterface::Hxx1::COWFn<S>::Set(const Block<const Byte>& mem, Bool littleEndian) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); BigIntegerInterface* o_ = (BigIntegerInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } 
	return (MTable::_instance.BigIntegerInterface_Set_8(o_, mem, littleEndian));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto BigIntegerInterface::Hxx1::Fn<S>::Set(const String& str) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); BigIntegerInterface* o_ = (BigIntegerInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (MTable::_instance.BigIntegerInterface_Set_9(o_, str));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto BigIntegerInterface::Hxx1::COWFn<S>::Set(const String& str) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); BigIntegerInterface* o_ = (BigIntegerInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } 
	return (MTable::_instance.BigIntegerInterface_Set_9(o_, str));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto BigIntegerInterface::Hxx1::Fn<S>::SetHex(const String& str) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); BigIntegerInterface* o_ = (BigIntegerInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (MTable::_instance.BigIntegerInterface_SetHex(o_, str));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto BigIntegerInterface::Hxx1::COWFn<S>::SetHex(const String& str) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); BigIntegerInterface* o_ = (BigIntegerInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } 
	return (MTable::_instance.BigIntegerInterface_SetHex(o_, str));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto BigIntegerInterface::Hxx1::ConstFn<S>::IsEven() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const BigIntegerInterface* o_ = (const BigIntegerInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = BigIntegerInterface::NullValuePtr(); if (!o_) return maxon::PrivateLogNullptrError(false); } 
	return (MTable::_instance.BigIntegerInterface_IsEven(o_));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto BigIntegerInterface::Hxx1::ConstFn<S>::IsOdd() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const BigIntegerInterface* o_ = (const BigIntegerInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = BigIntegerInterface::NullValuePtr(); if (!o_) return maxon::PrivateLogNullptrError(false); } 
	return (MTable::_instance.BigIntegerInterface_IsOdd(o_));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto BigIntegerInterface::Hxx1::ConstFn<S>::IsOne() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const BigIntegerInterface* o_ = (const BigIntegerInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = BigIntegerInterface::NullValuePtr(); if (!o_) return maxon::PrivateLogNullptrError(false); } 
	return (MTable::_instance.BigIntegerInterface_IsOne(o_));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto BigIntegerInterface::Hxx1::ConstFn<S>::IsZero() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const BigIntegerInterface* o_ = (const BigIntegerInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = BigIntegerInterface::NullValuePtr(); if (!o_) return maxon::PrivateLogNullptrError(false); } 
	return (MTable::_instance.BigIntegerInterface_IsZero(o_));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto BigIntegerInterface::Hxx1::ConstFn<S>::IsNegative() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const BigIntegerInterface* o_ = (const BigIntegerInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = BigIntegerInterface::NullValuePtr(); if (!o_) return maxon::PrivateLogNullptrError(false); } 
	return (MTable::_instance.BigIntegerInterface_IsNegative(o_));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto BigIntegerInterface::Hxx1::ConstFn<S>::IsPowerOfTwo() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const BigIntegerInterface* o_ = (const BigIntegerInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = BigIntegerInterface::NullValuePtr(); if (!o_) return maxon::PrivateLogNullptrError(false); } 
	return (MTable::_instance.BigIntegerInterface_IsPowerOfTwo(o_));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto BigIntegerInterface::Hxx1::ConstFn<S>::IsProbablyPrime(UInt certainty) const -> Result<Bool>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<Bool>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const BigIntegerInterface* o_ = (const BigIntegerInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = BigIntegerInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (MTable::_instance.BigIntegerInterface_IsProbablyPrime(o_, certainty));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto BigIntegerInterface::Hxx1::ConstFn<S>::Sign() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const BigIntegerInterface* o_ = (const BigIntegerInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = BigIntegerInterface::NullValuePtr(); if (!o_) return 0; } 
	return (MTable::_instance.BigIntegerInterface_Sign(o_));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto BigIntegerInterface::Hxx1::ConstFn<S>::GetHighestNonSignBit() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const BigIntegerInterface* o_ = (const BigIntegerInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = BigIntegerInterface::NullValuePtr(); if (!o_) return 0; } 
	return (MTable::_instance.BigIntegerInterface_GetHighestNonSignBit(o_));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto BigIntegerInterface::Hxx1::ConstFn<S>::GetLowestSetBit() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const BigIntegerInterface* o_ = (const BigIntegerInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = BigIntegerInterface::NullValuePtr(); if (!o_) return 0; } 
	return (MTable::_instance.BigIntegerInterface_GetLowestSetBit(o_));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto BigIntegerInterface::Hxx1::ConstFn<S>::GetLowestClearedBit() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const BigIntegerInterface* o_ = (const BigIntegerInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = BigIntegerInterface::NullValuePtr(); if (!o_) return 0; } 
	return (MTable::_instance.BigIntegerInterface_GetLowestClearedBit(o_));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto BigIntegerInterface::Hxx1::ConstFn<S>::IsBitSet(Int bit) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const BigIntegerInterface* o_ = (const BigIntegerInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = BigIntegerInterface::NullValuePtr(); if (!o_) return maxon::PrivateLogNullptrError(false); } 
	return (MTable::_instance.BigIntegerInterface_IsBitSet(o_, bit));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto BigIntegerInterface::Hxx1::ConstFn<S>::GetLowestBits8U() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<UChar>, UChar>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<UChar>, UChar>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const BigIntegerInterface* o_ = (const BigIntegerInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = BigIntegerInterface::NullValuePtr(); if (!o_) return 0; } 
	return (MTable::_instance.BigIntegerInterface_GetLowestBits8U(o_));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto BigIntegerInterface::Hxx1::ConstFn<S>::GetLowestBits8S() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Char>, Char>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Char>, Char>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const BigIntegerInterface* o_ = (const BigIntegerInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = BigIntegerInterface::NullValuePtr(); if (!o_) return 0; } 
	return (MTable::_instance.BigIntegerInterface_GetLowestBits8S(o_));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto BigIntegerInterface::Hxx1::ConstFn<S>::GetLowestBits16U() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<UInt16>, UInt16>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<UInt16>, UInt16>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const BigIntegerInterface* o_ = (const BigIntegerInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = BigIntegerInterface::NullValuePtr(); if (!o_) return 0; } 
	return (MTable::_instance.BigIntegerInterface_GetLowestBits16U(o_));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto BigIntegerInterface::Hxx1::ConstFn<S>::GetLowestBits16S() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Int16>, Int16>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Int16>, Int16>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const BigIntegerInterface* o_ = (const BigIntegerInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = BigIntegerInterface::NullValuePtr(); if (!o_) return 0; } 
	return (MTable::_instance.BigIntegerInterface_GetLowestBits16S(o_));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto BigIntegerInterface::Hxx1::ConstFn<S>::GetLowestBits32U() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<UInt32>, UInt32>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<UInt32>, UInt32>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const BigIntegerInterface* o_ = (const BigIntegerInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = BigIntegerInterface::NullValuePtr(); if (!o_) return 0; } 
	return (MTable::_instance.BigIntegerInterface_GetLowestBits32U(o_));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto BigIntegerInterface::Hxx1::ConstFn<S>::GetLowestBits32S() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Int32>, Int32>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Int32>, Int32>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const BigIntegerInterface* o_ = (const BigIntegerInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = BigIntegerInterface::NullValuePtr(); if (!o_) return 0; } 
	return (MTable::_instance.BigIntegerInterface_GetLowestBits32S(o_));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto BigIntegerInterface::Hxx1::ConstFn<S>::GetLowestBits64U() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<UInt64>, UInt64>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<UInt64>, UInt64>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const BigIntegerInterface* o_ = (const BigIntegerInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = BigIntegerInterface::NullValuePtr(); if (!o_) return 0; } 
	return (MTable::_instance.BigIntegerInterface_GetLowestBits64U(o_));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto BigIntegerInterface::Hxx1::ConstFn<S>::GetLowestBits64S() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Int64>, Int64>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Int64>, Int64>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const BigIntegerInterface* o_ = (const BigIntegerInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = BigIntegerInterface::NullValuePtr(); if (!o_) return 0; } 
	return (MTable::_instance.BigIntegerInterface_GetLowestBits64S(o_));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto BigIntegerInterface::Hxx1::ConstFn<S>::GetDataCopy(Bool littleEndian, BaseArray<UChar>& data) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const BigIntegerInterface* o_ = (const BigIntegerInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = BigIntegerInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (MTable::_instance.BigIntegerInterface_GetDataCopy(o_, littleEndian, data));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto BigIntegerInterface::Hxx1::Fn<S>::Add(const BigIntegerInterface* b) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); BigIntegerInterface* o_ = (BigIntegerInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (MTable::_instance.BigIntegerInterface_Add(o_, b));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto BigIntegerInterface::Hxx1::COWFn<S>::Add(const BigIntegerInterface* b) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); BigIntegerInterface* o_ = (BigIntegerInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } 
	return (MTable::_instance.BigIntegerInterface_Add(o_, b));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto BigIntegerInterface::Hxx1::Fn<S>::Sub(const BigIntegerInterface* b) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); BigIntegerInterface* o_ = (BigIntegerInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (MTable::_instance.BigIntegerInterface_Sub(o_, b));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto BigIntegerInterface::Hxx1::COWFn<S>::Sub(const BigIntegerInterface* b) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); BigIntegerInterface* o_ = (BigIntegerInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } 
	return (MTable::_instance.BigIntegerInterface_Sub(o_, b));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto BigIntegerInterface::Hxx1::Fn<S>::Inc() const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); BigIntegerInterface* o_ = (BigIntegerInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (MTable::_instance.BigIntegerInterface_Inc(o_));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto BigIntegerInterface::Hxx1::COWFn<S>::Inc() -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); BigIntegerInterface* o_ = (BigIntegerInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } 
	return (MTable::_instance.BigIntegerInterface_Inc(o_));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto BigIntegerInterface::Hxx1::Fn<S>::Dec() const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); BigIntegerInterface* o_ = (BigIntegerInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (MTable::_instance.BigIntegerInterface_Dec(o_));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto BigIntegerInterface::Hxx1::COWFn<S>::Dec() -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); BigIntegerInterface* o_ = (BigIntegerInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } 
	return (MTable::_instance.BigIntegerInterface_Dec(o_));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto BigIntegerInterface::Hxx1::Fn<S>::Mul(const BigIntegerInterface* b) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); BigIntegerInterface* o_ = (BigIntegerInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (MTable::_instance.BigIntegerInterface_Mul(o_, b));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto BigIntegerInterface::Hxx1::COWFn<S>::Mul(const BigIntegerInterface* b) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); BigIntegerInterface* o_ = (BigIntegerInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } 
	return (MTable::_instance.BigIntegerInterface_Mul(o_, b));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto BigIntegerInterface::Hxx1::Fn<S>::Div(const BigIntegerInterface* b) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); BigIntegerInterface* o_ = (BigIntegerInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (MTable::_instance.BigIntegerInterface_Div(o_, b));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto BigIntegerInterface::Hxx1::COWFn<S>::Div(const BigIntegerInterface* b) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); BigIntegerInterface* o_ = (BigIntegerInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } 
	return (MTable::_instance.BigIntegerInterface_Div(o_, b));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto BigIntegerInterface::Hxx1::Fn<S>::Mod(const BigIntegerInterface* b) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); BigIntegerInterface* o_ = (BigIntegerInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (MTable::_instance.BigIntegerInterface_Mod(o_, b));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto BigIntegerInterface::Hxx1::COWFn<S>::Mod(const BigIntegerInterface* b) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); BigIntegerInterface* o_ = (BigIntegerInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } 
	return (MTable::_instance.BigIntegerInterface_Mod(o_, b));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto BigIntegerInterface::Hxx1::Fn<S>::DivMod(const BigIntegerInterface* b, BigInteger& r) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); BigIntegerInterface* o_ = (BigIntegerInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (MTable::_instance.BigIntegerInterface_DivMod(o_, b, r));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto BigIntegerInterface::Hxx1::COWFn<S>::DivMod(const BigIntegerInterface* b, BigInteger& r) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); BigIntegerInterface* o_ = (BigIntegerInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } 
	return (MTable::_instance.BigIntegerInterface_DivMod(o_, b, r));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto BigIntegerInterface::Hxx1::Fn<S>::Pow(const BigIntegerInterface* b) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); BigIntegerInterface* o_ = (BigIntegerInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (MTable::_instance.BigIntegerInterface_Pow(o_, b));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto BigIntegerInterface::Hxx1::COWFn<S>::Pow(const BigIntegerInterface* b) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); BigIntegerInterface* o_ = (BigIntegerInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } 
	return (MTable::_instance.BigIntegerInterface_Pow(o_, b));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto BigIntegerInterface::Hxx1::Fn<S>::PowMod(const BigIntegerInterface* b, const BigIntegerInterface* mod) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); BigIntegerInterface* o_ = (BigIntegerInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (MTable::_instance.BigIntegerInterface_PowMod(o_, b, mod));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto BigIntegerInterface::Hxx1::COWFn<S>::PowMod(const BigIntegerInterface* b, const BigIntegerInterface* mod) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); BigIntegerInterface* o_ = (BigIntegerInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } 
	return (MTable::_instance.BigIntegerInterface_PowMod(o_, b, mod));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto BigIntegerInterface::Hxx1::Fn<S>::GreatestCommonDivisor(const BigIntegerInterface* b) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); BigIntegerInterface* o_ = (BigIntegerInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (MTable::_instance.BigIntegerInterface_GreatestCommonDivisor(o_, b));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto BigIntegerInterface::Hxx1::COWFn<S>::GreatestCommonDivisor(const BigIntegerInterface* b) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); BigIntegerInterface* o_ = (BigIntegerInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } 
	return (MTable::_instance.BigIntegerInterface_GreatestCommonDivisor(o_, b));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto BigIntegerInterface::Hxx1::Fn<S>::MultiplicativeInverse(const BigIntegerInterface* m) const -> Result<Bool>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<Bool>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); BigIntegerInterface* o_ = (BigIntegerInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (MTable::_instance.BigIntegerInterface_MultiplicativeInverse(o_, m));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto BigIntegerInterface::Hxx1::COWFn<S>::MultiplicativeInverse(const BigIntegerInterface* m) -> Result<Bool>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<Bool>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); BigIntegerInterface* o_ = (BigIntegerInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } 
	return (MTable::_instance.BigIntegerInterface_MultiplicativeInverse(o_, m));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto BigIntegerInterface::Hxx1::Fn<S>::LeftShift(Int s) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); BigIntegerInterface* o_ = (BigIntegerInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (MTable::_instance.BigIntegerInterface_LeftShift(o_, s));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto BigIntegerInterface::Hxx1::COWFn<S>::LeftShift(Int s) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); BigIntegerInterface* o_ = (BigIntegerInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } 
	return (MTable::_instance.BigIntegerInterface_LeftShift(o_, s));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto BigIntegerInterface::Hxx1::Fn<S>::RightShift(Int s) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); BigIntegerInterface* o_ = (BigIntegerInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (MTable::_instance.BigIntegerInterface_RightShift(o_, s));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto BigIntegerInterface::Hxx1::COWFn<S>::RightShift(Int s) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); BigIntegerInterface* o_ = (BigIntegerInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } 
	return (MTable::_instance.BigIntegerInterface_RightShift(o_, s));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto BigIntegerInterface::Hxx1::Fn<S>::Negate() const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); BigIntegerInterface* o_ = (BigIntegerInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (MTable::_instance.BigIntegerInterface_Negate(o_));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto BigIntegerInterface::Hxx1::COWFn<S>::Negate() -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); BigIntegerInterface* o_ = (BigIntegerInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } 
	return (MTable::_instance.BigIntegerInterface_Negate(o_));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto BigIntegerInterface::Hxx1::Fn<S>::SetBit(Int bit) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); BigIntegerInterface* o_ = (BigIntegerInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (MTable::_instance.BigIntegerInterface_SetBit(o_, bit));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto BigIntegerInterface::Hxx1::COWFn<S>::SetBit(Int bit) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); BigIntegerInterface* o_ = (BigIntegerInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } 
	return (MTable::_instance.BigIntegerInterface_SetBit(o_, bit));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto BigIntegerInterface::Hxx1::Fn<S>::ClearBit(Int bit) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); BigIntegerInterface* o_ = (BigIntegerInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (MTable::_instance.BigIntegerInterface_ClearBit(o_, bit));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto BigIntegerInterface::Hxx1::COWFn<S>::ClearBit(Int bit) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); BigIntegerInterface* o_ = (BigIntegerInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } 
	return (MTable::_instance.BigIntegerInterface_ClearBit(o_, bit));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto BigIntegerInterface::Hxx1::Fn<S>::ToggleBit(Int bit) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); BigIntegerInterface* o_ = (BigIntegerInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (MTable::_instance.BigIntegerInterface_ToggleBit(o_, bit));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto BigIntegerInterface::Hxx1::COWFn<S>::ToggleBit(Int bit) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); BigIntegerInterface* o_ = (BigIntegerInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } 
	return (MTable::_instance.BigIntegerInterface_ToggleBit(o_, bit));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto BigIntegerInterface::Hxx1::ConstFn<S>::Compare(const BigIntegerInterface* arg2) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<COMPARERESULT>, COMPARERESULT>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<COMPARERESULT>, COMPARERESULT>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const BigIntegerInterface* o_ = (const BigIntegerInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = BigIntegerInterface::NullValuePtr(); if (!o_) return maxon::PrivateIncompleteNullReturnValue<COMPARERESULT>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } 
	return (MTable::_instance.BigIntegerInterface_Compare(o_, arg2));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto BigIntegerInterface::Hxx1::ConstFn<S>::ToString(const FormatStatement* formatStatement) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<String>, String>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<String>, String>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const BigIntegerInterface* o_ = (const BigIntegerInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = BigIntegerInterface::NullValuePtr(); if (!o_) return maxon::PrivateIncompleteNullReturnValue<String>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } 
	return (MTable::_instance.BigIntegerInterface_ToString(o_, formatStatement));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto BigIntegerInterface::Hxx1::ConstFn<S>::DescribeIO(const DataSerializeInterface& stream) -> Result<void>
{
	return (MTable::_instance.BigIntegerInterface_DescribeIO(stream));
}
#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT) && !defined(MAXON_DEPENDENCY_DISABLE_big_integer)
#ifdef MAXON_USE_REGISTER_FUNCTION
MAXON_STATIC_STORAGE(maxon::EntityUse, s_ui_maxon_BigIntegerInterface); \
MAXON_ATTRIBUTE_CONSTRUCTOR static void Register_s_ui_maxon_BigIntegerInterface() { new (s_ui_maxon_BigIntegerInterface) maxon::EntityUse(BigIntegerInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/big_integer.h", false); }
#else // !MAXON_USE_REGISTER_FUNCTION
static maxon::EntityUse s_ui_maxon_BigIntegerInterface(BigIntegerInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/big_integer.h", false);
#endif // MAXON_USE_REGISTER_FUNCTION
#endif
#endif

#ifdef MAXON_COMPILER_GCC
	#pragma GCC diagnostic pop
#endif

#endif

