
#ifndef DOXYGEN

#ifdef MAXON_COMPILER_GCC
	#pragma GCC diagnostic push
	#pragma GCC diagnostic ignored "-Wmisleading-indentation"
#endif

#if 1

struct BigIntegerInterface::MTable
{
	static MTable _instance;
	static MTable _unresolvedInstance;
	static const maxon::Char* const _ids;
	static maxon::Bool InitUnresolved(maxon::NonvirtualInterfaceReference::UnresolvedAssembler assembler, MTable* tbl);
	static const maxon::NULL_RETURN_TYPE _returnTypes[];
	static const maxon::Bool HAS_NONSTATIC = true;
	void (*_BigIntegerInterface_Free) (const BigIntegerInterface* object);
	BigIntegerInterface* (*_BigIntegerInterface_Alloc) (const maxon::SourceLocation& allocLocation);
	BigIntegerInterface* (*_BigIntegerInterface_Alloc_1) (const maxon::SourceLocation& allocLocation, const BigIntegerInterface& object);
	BigIntegerInterface* (*_BigIntegerInterface_Zero) ();
	BigIntegerInterface* (*_BigIntegerInterface_One) ();
	BigIntegerInterface* (*_BigIntegerInterface_MinusOne) ();
	Result<void> (*_BigIntegerInterface_Set) (BigIntegerInterface* this_, Char c);
	Result<void> (*_BigIntegerInterface_Set_1) (BigIntegerInterface* this_, UChar c);
	Result<void> (*_BigIntegerInterface_Set_2) (BigIntegerInterface* this_, Int16 i);
	Result<void> (*_BigIntegerInterface_Set_3) (BigIntegerInterface* this_, UInt16 u);
	Result<void> (*_BigIntegerInterface_Set_4) (BigIntegerInterface* this_, Int32 i);
	Result<void> (*_BigIntegerInterface_Set_5) (BigIntegerInterface* this_, UInt32 u);
	Result<void> (*_BigIntegerInterface_Set_6) (BigIntegerInterface* this_, Int64 i);
	Result<void> (*_BigIntegerInterface_Set_7) (BigIntegerInterface* this_, UInt64 u);
	Result<void> (*_BigIntegerInterface_SetRandom) (BigIntegerInterface* this_, Int bitCount, SecureRandomProvider provider);
	Result<void> (*_BigIntegerInterface_SetRandomPrime) (BigIntegerInterface* this_, Int bitCount, UInt certainty, SecureRandomProvider provider);
	Result<void> (*_BigIntegerInterface_Set_8) (BigIntegerInterface* this_, const Block<const Byte>& mem, Bool littleEndian);
	Result<void> (*_BigIntegerInterface_Set_9) (BigIntegerInterface* this_, const String& str);
	Result<void> (*_BigIntegerInterface_SetHex) (BigIntegerInterface* this_, const String& str);
	Bool (*_BigIntegerInterface_IsEven) (const BigIntegerInterface* this_);
	Bool (*_BigIntegerInterface_IsOdd) (const BigIntegerInterface* this_);
	Bool (*_BigIntegerInterface_IsOne) (const BigIntegerInterface* this_);
	Bool (*_BigIntegerInterface_IsZero) (const BigIntegerInterface* this_);
	Bool (*_BigIntegerInterface_IsNegative) (const BigIntegerInterface* this_);
	Bool (*_BigIntegerInterface_IsPowerOfTwo) (const BigIntegerInterface* this_);
	Result<Bool> (*_BigIntegerInterface_IsProbablyPrime) (const BigIntegerInterface* this_, UInt certainty);
	Int (*_BigIntegerInterface_Sign) (const BigIntegerInterface* this_);
	Int (*_BigIntegerInterface_GetHighestNonSignBit) (const BigIntegerInterface* this_);
	Int (*_BigIntegerInterface_GetLowestSetBit) (const BigIntegerInterface* this_);
	Int (*_BigIntegerInterface_GetLowestClearedBit) (const BigIntegerInterface* this_);
	Bool (*_BigIntegerInterface_IsBitSet) (const BigIntegerInterface* this_, Int bit);
	UChar (*_BigIntegerInterface_GetLowestBits8U) (const BigIntegerInterface* this_);
	Char (*_BigIntegerInterface_GetLowestBits8S) (const BigIntegerInterface* this_);
	UInt16 (*_BigIntegerInterface_GetLowestBits16U) (const BigIntegerInterface* this_);
	Int16 (*_BigIntegerInterface_GetLowestBits16S) (const BigIntegerInterface* this_);
	UInt32 (*_BigIntegerInterface_GetLowestBits32U) (const BigIntegerInterface* this_);
	Int32 (*_BigIntegerInterface_GetLowestBits32S) (const BigIntegerInterface* this_);
	UInt64 (*_BigIntegerInterface_GetLowestBits64U) (const BigIntegerInterface* this_);
	Int64 (*_BigIntegerInterface_GetLowestBits64S) (const BigIntegerInterface* this_);
	Result<void> (*_BigIntegerInterface_GetDataCopy) (const BigIntegerInterface* this_, Bool littleEndian, BaseArray<UChar>& data);
	Result<void> (*_BigIntegerInterface_Add) (BigIntegerInterface* this_, const BigIntegerInterface* b);
	Result<void> (*_BigIntegerInterface_Sub) (BigIntegerInterface* this_, const BigIntegerInterface* b);
	Result<void> (*_BigIntegerInterface_Inc) (BigIntegerInterface* this_);
	Result<void> (*_BigIntegerInterface_Dec) (BigIntegerInterface* this_);
	Result<void> (*_BigIntegerInterface_Mul) (BigIntegerInterface* this_, const BigIntegerInterface* b);
	Result<void> (*_BigIntegerInterface_Div) (BigIntegerInterface* this_, const BigIntegerInterface* b);
	Result<void> (*_BigIntegerInterface_Mod) (BigIntegerInterface* this_, const BigIntegerInterface* b);
	Result<void> (*_BigIntegerInterface_DivMod) (BigIntegerInterface* this_, const BigIntegerInterface* b, BigInteger& r);
	Result<void> (*_BigIntegerInterface_Pow) (BigIntegerInterface* this_, const BigIntegerInterface* b);
	Result<void> (*_BigIntegerInterface_PowMod) (BigIntegerInterface* this_, const BigIntegerInterface* b, const BigIntegerInterface* mod);
	Result<void> (*_BigIntegerInterface_GreatestCommonDivisor) (BigIntegerInterface* this_, const BigIntegerInterface* b);
	Result<Bool> (*_BigIntegerInterface_MultiplicativeInverse) (BigIntegerInterface* this_, const BigIntegerInterface* m);
	Result<void> (*_BigIntegerInterface_LeftShift) (BigIntegerInterface* this_, Int s);
	Result<void> (*_BigIntegerInterface_RightShift) (BigIntegerInterface* this_, Int s);
	Result<void> (*_BigIntegerInterface_Negate) (BigIntegerInterface* this_);
	Result<void> (*_BigIntegerInterface_SetBit) (BigIntegerInterface* this_, Int bit);
	Result<void> (*_BigIntegerInterface_ClearBit) (BigIntegerInterface* this_, Int bit);
	Result<void> (*_BigIntegerInterface_ToggleBit) (BigIntegerInterface* this_, Int bit);
	COMPARERESULT (*_BigIntegerInterface_Compare) (const BigIntegerInterface* this_, const BigIntegerInterface* arg2);
	UInt (*_BigIntegerInterface_GetHashCode) (const BigIntegerInterface* this_);
	String (*_BigIntegerInterface_ToString) (const BigIntegerInterface* this_, const FormatStatement* formatStatement);
	Result<void> (*_BigIntegerInterface_DescribeIO) (const DataSerializeInterface& stream);
	template <typename IMPL> static void Init(MTable* tbl)
	{
		tbl->_BigIntegerInterface_Free = &IMPL::_BigIntegerInterface_Free;
		tbl->_BigIntegerInterface_Alloc = &IMPL::_BigIntegerInterface_Alloc;
		tbl->_BigIntegerInterface_Alloc_1 = &IMPL::_BigIntegerInterface_Alloc_1;
		tbl->_BigIntegerInterface_Zero = &IMPL::_BigIntegerInterface_Zero;
		tbl->_BigIntegerInterface_One = &IMPL::_BigIntegerInterface_One;
		tbl->_BigIntegerInterface_MinusOne = &IMPL::_BigIntegerInterface_MinusOne;
		tbl->_BigIntegerInterface_Set = &IMPL::_BigIntegerInterface_Set;
		tbl->_BigIntegerInterface_Set_1 = &IMPL::_BigIntegerInterface_Set_1;
		tbl->_BigIntegerInterface_Set_2 = &IMPL::_BigIntegerInterface_Set_2;
		tbl->_BigIntegerInterface_Set_3 = &IMPL::_BigIntegerInterface_Set_3;
		tbl->_BigIntegerInterface_Set_4 = &IMPL::_BigIntegerInterface_Set_4;
		tbl->_BigIntegerInterface_Set_5 = &IMPL::_BigIntegerInterface_Set_5;
		tbl->_BigIntegerInterface_Set_6 = &IMPL::_BigIntegerInterface_Set_6;
		tbl->_BigIntegerInterface_Set_7 = &IMPL::_BigIntegerInterface_Set_7;
		tbl->_BigIntegerInterface_SetRandom = &IMPL::_BigIntegerInterface_SetRandom;
		tbl->_BigIntegerInterface_SetRandomPrime = &IMPL::_BigIntegerInterface_SetRandomPrime;
		tbl->_BigIntegerInterface_Set_8 = &IMPL::_BigIntegerInterface_Set_8;
		tbl->_BigIntegerInterface_Set_9 = &IMPL::_BigIntegerInterface_Set_9;
		tbl->_BigIntegerInterface_SetHex = &IMPL::_BigIntegerInterface_SetHex;
		tbl->_BigIntegerInterface_IsEven = &IMPL::_BigIntegerInterface_IsEven;
		tbl->_BigIntegerInterface_IsOdd = &IMPL::_BigIntegerInterface_IsOdd;
		tbl->_BigIntegerInterface_IsOne = &IMPL::_BigIntegerInterface_IsOne;
		tbl->_BigIntegerInterface_IsZero = &IMPL::_BigIntegerInterface_IsZero;
		tbl->_BigIntegerInterface_IsNegative = &IMPL::_BigIntegerInterface_IsNegative;
		tbl->_BigIntegerInterface_IsPowerOfTwo = &IMPL::_BigIntegerInterface_IsPowerOfTwo;
		tbl->_BigIntegerInterface_IsProbablyPrime = &IMPL::_BigIntegerInterface_IsProbablyPrime;
		tbl->_BigIntegerInterface_Sign = &IMPL::_BigIntegerInterface_Sign;
		tbl->_BigIntegerInterface_GetHighestNonSignBit = &IMPL::_BigIntegerInterface_GetHighestNonSignBit;
		tbl->_BigIntegerInterface_GetLowestSetBit = &IMPL::_BigIntegerInterface_GetLowestSetBit;
		tbl->_BigIntegerInterface_GetLowestClearedBit = &IMPL::_BigIntegerInterface_GetLowestClearedBit;
		tbl->_BigIntegerInterface_IsBitSet = &IMPL::_BigIntegerInterface_IsBitSet;
		tbl->_BigIntegerInterface_GetLowestBits8U = &IMPL::_BigIntegerInterface_GetLowestBits8U;
		tbl->_BigIntegerInterface_GetLowestBits8S = &IMPL::_BigIntegerInterface_GetLowestBits8S;
		tbl->_BigIntegerInterface_GetLowestBits16U = &IMPL::_BigIntegerInterface_GetLowestBits16U;
		tbl->_BigIntegerInterface_GetLowestBits16S = &IMPL::_BigIntegerInterface_GetLowestBits16S;
		tbl->_BigIntegerInterface_GetLowestBits32U = &IMPL::_BigIntegerInterface_GetLowestBits32U;
		tbl->_BigIntegerInterface_GetLowestBits32S = &IMPL::_BigIntegerInterface_GetLowestBits32S;
		tbl->_BigIntegerInterface_GetLowestBits64U = &IMPL::_BigIntegerInterface_GetLowestBits64U;
		tbl->_BigIntegerInterface_GetLowestBits64S = &IMPL::_BigIntegerInterface_GetLowestBits64S;
		tbl->_BigIntegerInterface_GetDataCopy = &IMPL::_BigIntegerInterface_GetDataCopy;
		tbl->_BigIntegerInterface_Add = &IMPL::_BigIntegerInterface_Add;
		tbl->_BigIntegerInterface_Sub = &IMPL::_BigIntegerInterface_Sub;
		tbl->_BigIntegerInterface_Inc = &IMPL::_BigIntegerInterface_Inc;
		tbl->_BigIntegerInterface_Dec = &IMPL::_BigIntegerInterface_Dec;
		tbl->_BigIntegerInterface_Mul = &IMPL::_BigIntegerInterface_Mul;
		tbl->_BigIntegerInterface_Div = &IMPL::_BigIntegerInterface_Div;
		tbl->_BigIntegerInterface_Mod = &IMPL::_BigIntegerInterface_Mod;
		tbl->_BigIntegerInterface_DivMod = &IMPL::_BigIntegerInterface_DivMod;
		tbl->_BigIntegerInterface_Pow = &IMPL::_BigIntegerInterface_Pow;
		tbl->_BigIntegerInterface_PowMod = &IMPL::_BigIntegerInterface_PowMod;
		tbl->_BigIntegerInterface_GreatestCommonDivisor = &IMPL::_BigIntegerInterface_GreatestCommonDivisor;
		tbl->_BigIntegerInterface_MultiplicativeInverse = &IMPL::_BigIntegerInterface_MultiplicativeInverse;
		tbl->_BigIntegerInterface_LeftShift = &IMPL::_BigIntegerInterface_LeftShift;
		tbl->_BigIntegerInterface_RightShift = &IMPL::_BigIntegerInterface_RightShift;
		tbl->_BigIntegerInterface_Negate = &IMPL::_BigIntegerInterface_Negate;
		tbl->_BigIntegerInterface_SetBit = &IMPL::_BigIntegerInterface_SetBit;
		tbl->_BigIntegerInterface_ClearBit = &IMPL::_BigIntegerInterface_ClearBit;
		tbl->_BigIntegerInterface_ToggleBit = &IMPL::_BigIntegerInterface_ToggleBit;
		tbl->_BigIntegerInterface_Compare = &IMPL::_BigIntegerInterface_Compare;
		tbl->_BigIntegerInterface_GetHashCode = &IMPL::_BigIntegerInterface_GetHashCode;
		tbl->_BigIntegerInterface_ToString = &IMPL::_BigIntegerInterface_ToString;
		tbl->_BigIntegerInterface_DescribeIO = &IMPL::_BigIntegerInterface_DescribeIO;
	}
};

template <typename C> class BigIntegerInterface::Wrapper
{
public:
	static void _BigIntegerInterface_Free(const BigIntegerInterface* object) { return C::Free(object); }
	static BigIntegerInterface* _BigIntegerInterface_Alloc(const maxon::SourceLocation& allocLocation) { return C::Alloc(allocLocation); }
	static BigIntegerInterface* _BigIntegerInterface_Alloc_1(const maxon::SourceLocation& allocLocation, const BigIntegerInterface& object) { return C::Alloc(allocLocation, ((const C&) object)); }
	static BigIntegerInterface* _BigIntegerInterface_Zero() { return C::Zero(); }
	static BigIntegerInterface* _BigIntegerInterface_One() { return C::One(); }
	static BigIntegerInterface* _BigIntegerInterface_MinusOne() { return C::MinusOne(); }
	static Result<void> _BigIntegerInterface_Set(BigIntegerInterface* this_, Char c) { return ((C*) this_)->Set(c); }
	static Result<void> _BigIntegerInterface_Set_1(BigIntegerInterface* this_, UChar c) { return ((C*) this_)->Set(c); }
	static Result<void> _BigIntegerInterface_Set_2(BigIntegerInterface* this_, Int16 i) { return ((C*) this_)->Set(i); }
	static Result<void> _BigIntegerInterface_Set_3(BigIntegerInterface* this_, UInt16 u) { return ((C*) this_)->Set(u); }
	static Result<void> _BigIntegerInterface_Set_4(BigIntegerInterface* this_, Int32 i) { return ((C*) this_)->Set(i); }
	static Result<void> _BigIntegerInterface_Set_5(BigIntegerInterface* this_, UInt32 u) { return ((C*) this_)->Set(u); }
	static Result<void> _BigIntegerInterface_Set_6(BigIntegerInterface* this_, Int64 i) { return ((C*) this_)->Set(i); }
	static Result<void> _BigIntegerInterface_Set_7(BigIntegerInterface* this_, UInt64 u) { return ((C*) this_)->Set(u); }
	static Result<void> _BigIntegerInterface_SetRandom(BigIntegerInterface* this_, Int bitCount, SecureRandomProvider provider) { return ((C*) this_)->SetRandom(bitCount, std::forward<SecureRandomProvider>(provider)); }
	static Result<void> _BigIntegerInterface_SetRandomPrime(BigIntegerInterface* this_, Int bitCount, UInt certainty, SecureRandomProvider provider) { return ((C*) this_)->SetRandomPrime(bitCount, certainty, std::forward<SecureRandomProvider>(provider)); }
	static Result<void> _BigIntegerInterface_Set_8(BigIntegerInterface* this_, const Block<const Byte>& mem, Bool littleEndian) { return ((C*) this_)->Set(mem, littleEndian); }
	static Result<void> _BigIntegerInterface_Set_9(BigIntegerInterface* this_, const String& str) { return ((C*) this_)->Set(str); }
	static Result<void> _BigIntegerInterface_SetHex(BigIntegerInterface* this_, const String& str) { return ((C*) this_)->SetHex(str); }
	static Bool _BigIntegerInterface_IsEven(const BigIntegerInterface* this_) { return ((const C*) this_)->IsEven(); }
	static Bool _BigIntegerInterface_IsOdd(const BigIntegerInterface* this_) { return ((const C*) this_)->IsOdd(); }
	static Bool _BigIntegerInterface_IsOne(const BigIntegerInterface* this_) { return ((const C*) this_)->IsOne(); }
	static Bool _BigIntegerInterface_IsZero(const BigIntegerInterface* this_) { return ((const C*) this_)->IsZero(); }
	static Bool _BigIntegerInterface_IsNegative(const BigIntegerInterface* this_) { return ((const C*) this_)->IsNegative(); }
	static Bool _BigIntegerInterface_IsPowerOfTwo(const BigIntegerInterface* this_) { return ((const C*) this_)->IsPowerOfTwo(); }
	static Result<Bool> _BigIntegerInterface_IsProbablyPrime(const BigIntegerInterface* this_, UInt certainty) { return ((const C*) this_)->IsProbablyPrime(certainty); }
	static Int _BigIntegerInterface_Sign(const BigIntegerInterface* this_) { return ((const C*) this_)->Sign(); }
	static Int _BigIntegerInterface_GetHighestNonSignBit(const BigIntegerInterface* this_) { return ((const C*) this_)->GetHighestNonSignBit(); }
	static Int _BigIntegerInterface_GetLowestSetBit(const BigIntegerInterface* this_) { return ((const C*) this_)->GetLowestSetBit(); }
	static Int _BigIntegerInterface_GetLowestClearedBit(const BigIntegerInterface* this_) { return ((const C*) this_)->GetLowestClearedBit(); }
	static Bool _BigIntegerInterface_IsBitSet(const BigIntegerInterface* this_, Int bit) { return ((const C*) this_)->IsBitSet(bit); }
	static UChar _BigIntegerInterface_GetLowestBits8U(const BigIntegerInterface* this_) { return ((const C*) this_)->GetLowestBits8U(); }
	static Char _BigIntegerInterface_GetLowestBits8S(const BigIntegerInterface* this_) { return ((const C*) this_)->GetLowestBits8S(); }
	static UInt16 _BigIntegerInterface_GetLowestBits16U(const BigIntegerInterface* this_) { return ((const C*) this_)->GetLowestBits16U(); }
	static Int16 _BigIntegerInterface_GetLowestBits16S(const BigIntegerInterface* this_) { return ((const C*) this_)->GetLowestBits16S(); }
	static UInt32 _BigIntegerInterface_GetLowestBits32U(const BigIntegerInterface* this_) { return ((const C*) this_)->GetLowestBits32U(); }
	static Int32 _BigIntegerInterface_GetLowestBits32S(const BigIntegerInterface* this_) { return ((const C*) this_)->GetLowestBits32S(); }
	static UInt64 _BigIntegerInterface_GetLowestBits64U(const BigIntegerInterface* this_) { return ((const C*) this_)->GetLowestBits64U(); }
	static Int64 _BigIntegerInterface_GetLowestBits64S(const BigIntegerInterface* this_) { return ((const C*) this_)->GetLowestBits64S(); }
	static Result<void> _BigIntegerInterface_GetDataCopy(const BigIntegerInterface* this_, Bool littleEndian, BaseArray<UChar>& data) { return ((const C*) this_)->GetDataCopy(littleEndian, data); }
	static Result<void> _BigIntegerInterface_Add(BigIntegerInterface* this_, const BigIntegerInterface* b) { return ((C*) this_)->Add(b); }
	static Result<void> _BigIntegerInterface_Sub(BigIntegerInterface* this_, const BigIntegerInterface* b) { return ((C*) this_)->Sub(b); }
	static Result<void> _BigIntegerInterface_Inc(BigIntegerInterface* this_) { return ((C*) this_)->Inc(); }
	static Result<void> _BigIntegerInterface_Dec(BigIntegerInterface* this_) { return ((C*) this_)->Dec(); }
	static Result<void> _BigIntegerInterface_Mul(BigIntegerInterface* this_, const BigIntegerInterface* b) { return ((C*) this_)->Mul(b); }
	static Result<void> _BigIntegerInterface_Div(BigIntegerInterface* this_, const BigIntegerInterface* b) { return ((C*) this_)->Div(b); }
	static Result<void> _BigIntegerInterface_Mod(BigIntegerInterface* this_, const BigIntegerInterface* b) { return ((C*) this_)->Mod(b); }
	static Result<void> _BigIntegerInterface_DivMod(BigIntegerInterface* this_, const BigIntegerInterface* b, BigInteger& r) { return ((C*) this_)->DivMod(b, r); }
	static Result<void> _BigIntegerInterface_Pow(BigIntegerInterface* this_, const BigIntegerInterface* b) { return ((C*) this_)->Pow(b); }
	static Result<void> _BigIntegerInterface_PowMod(BigIntegerInterface* this_, const BigIntegerInterface* b, const BigIntegerInterface* mod) { return ((C*) this_)->PowMod(b, mod); }
	static Result<void> _BigIntegerInterface_GreatestCommonDivisor(BigIntegerInterface* this_, const BigIntegerInterface* b) { return ((C*) this_)->GreatestCommonDivisor(b); }
	static Result<Bool> _BigIntegerInterface_MultiplicativeInverse(BigIntegerInterface* this_, const BigIntegerInterface* m) { return ((C*) this_)->MultiplicativeInverse(m); }
	static Result<void> _BigIntegerInterface_LeftShift(BigIntegerInterface* this_, Int s) { return ((C*) this_)->LeftShift(s); }
	static Result<void> _BigIntegerInterface_RightShift(BigIntegerInterface* this_, Int s) { return ((C*) this_)->RightShift(s); }
	static Result<void> _BigIntegerInterface_Negate(BigIntegerInterface* this_) { return ((C*) this_)->Negate(); }
	static Result<void> _BigIntegerInterface_SetBit(BigIntegerInterface* this_, Int bit) { return ((C*) this_)->SetBit(bit); }
	static Result<void> _BigIntegerInterface_ClearBit(BigIntegerInterface* this_, Int bit) { return ((C*) this_)->ClearBit(bit); }
	static Result<void> _BigIntegerInterface_ToggleBit(BigIntegerInterface* this_, Int bit) { return ((C*) this_)->ToggleBit(bit); }
	static COMPARERESULT _BigIntegerInterface_Compare(const BigIntegerInterface* this_, const BigIntegerInterface* arg2) { return ((const C*) this_)->Compare(arg2); }
	static UInt _BigIntegerInterface_GetHashCode(const BigIntegerInterface* this_) { return ((const C*) this_)->GetHashCode(); }
	static String _BigIntegerInterface_ToString(const BigIntegerInterface* this_, const FormatStatement* formatStatement) { return ((const C*) this_)->ToString(formatStatement); }
	static Result<void> _BigIntegerInterface_DescribeIO(const DataSerializeInterface& stream) { return C::DescribeIO(stream); }
};

MAXON_ATTRIBUTE_FORCE_INLINE auto BigIntegerInterface::Free(const BigIntegerInterface* object) -> void
{
	return MTable::_instance._BigIntegerInterface_Free(object);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto BigIntegerInterface::Alloc(const maxon::SourceLocation& allocLocation) -> BigIntegerInterface*
{
	return MTable::_instance._BigIntegerInterface_Alloc(allocLocation);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto BigIntegerInterface::Alloc(const maxon::SourceLocation& allocLocation, const BigIntegerInterface& object) -> BigIntegerInterface*
{
	return MTable::_instance._BigIntegerInterface_Alloc_1(allocLocation, object);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto BigIntegerInterface::Zero() -> BigIntegerInterface*
{
	return MTable::_instance._BigIntegerInterface_Zero();
}
MAXON_ATTRIBUTE_FORCE_INLINE auto BigIntegerInterface::One() -> BigIntegerInterface*
{
	return MTable::_instance._BigIntegerInterface_One();
}
MAXON_ATTRIBUTE_FORCE_INLINE auto BigIntegerInterface::MinusOne() -> BigIntegerInterface*
{
	return MTable::_instance._BigIntegerInterface_MinusOne();
}
MAXON_ATTRIBUTE_FORCE_INLINE auto BigIntegerInterface::Set(Char c) -> Result<void>
{
	return MTable::_instance._BigIntegerInterface_Set(this, c);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto BigIntegerInterface::Set(UChar c) -> Result<void>
{
	return MTable::_instance._BigIntegerInterface_Set_1(this, c);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto BigIntegerInterface::Set(Int16 i) -> Result<void>
{
	return MTable::_instance._BigIntegerInterface_Set_2(this, i);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto BigIntegerInterface::Set(UInt16 u) -> Result<void>
{
	return MTable::_instance._BigIntegerInterface_Set_3(this, u);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto BigIntegerInterface::Set(Int32 i) -> Result<void>
{
	return MTable::_instance._BigIntegerInterface_Set_4(this, i);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto BigIntegerInterface::Set(UInt32 u) -> Result<void>
{
	return MTable::_instance._BigIntegerInterface_Set_5(this, u);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto BigIntegerInterface::Set(Int64 i) -> Result<void>
{
	return MTable::_instance._BigIntegerInterface_Set_6(this, i);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto BigIntegerInterface::Set(UInt64 u) -> Result<void>
{
	return MTable::_instance._BigIntegerInterface_Set_7(this, u);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto BigIntegerInterface::SetRandom(Int bitCount, SecureRandomProvider provider) -> Result<void>
{
	return MTable::_instance._BigIntegerInterface_SetRandom(this, bitCount, std::forward<SecureRandomProvider>(provider));
}
MAXON_ATTRIBUTE_FORCE_INLINE auto BigIntegerInterface::SetRandomPrime(Int bitCount, UInt certainty, SecureRandomProvider provider) -> Result<void>
{
	return MTable::_instance._BigIntegerInterface_SetRandomPrime(this, bitCount, certainty, std::forward<SecureRandomProvider>(provider));
}
MAXON_ATTRIBUTE_FORCE_INLINE auto BigIntegerInterface::Set(const Block<const Byte>& mem, Bool littleEndian) -> Result<void>
{
	return MTable::_instance._BigIntegerInterface_Set_8(this, mem, littleEndian);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto BigIntegerInterface::Set(const String& str) -> Result<void>
{
	return MTable::_instance._BigIntegerInterface_Set_9(this, str);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto BigIntegerInterface::SetHex(const String& str) -> Result<void>
{
	return MTable::_instance._BigIntegerInterface_SetHex(this, str);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto BigIntegerInterface::IsEven() const -> Bool
{
	return MTable::_instance._BigIntegerInterface_IsEven(this);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto BigIntegerInterface::IsOdd() const -> Bool
{
	return MTable::_instance._BigIntegerInterface_IsOdd(this);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto BigIntegerInterface::IsOne() const -> Bool
{
	return MTable::_instance._BigIntegerInterface_IsOne(this);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto BigIntegerInterface::IsZero() const -> Bool
{
	return MTable::_instance._BigIntegerInterface_IsZero(this);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto BigIntegerInterface::IsNegative() const -> Bool
{
	return MTable::_instance._BigIntegerInterface_IsNegative(this);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto BigIntegerInterface::IsPowerOfTwo() const -> Bool
{
	return MTable::_instance._BigIntegerInterface_IsPowerOfTwo(this);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto BigIntegerInterface::IsProbablyPrime(UInt certainty) const -> Result<Bool>
{
	return MTable::_instance._BigIntegerInterface_IsProbablyPrime(this, certainty);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto BigIntegerInterface::Sign() const -> Int
{
	return MTable::_instance._BigIntegerInterface_Sign(this);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto BigIntegerInterface::GetHighestNonSignBit() const -> Int
{
	return MTable::_instance._BigIntegerInterface_GetHighestNonSignBit(this);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto BigIntegerInterface::GetLowestSetBit() const -> Int
{
	return MTable::_instance._BigIntegerInterface_GetLowestSetBit(this);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto BigIntegerInterface::GetLowestClearedBit() const -> Int
{
	return MTable::_instance._BigIntegerInterface_GetLowestClearedBit(this);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto BigIntegerInterface::IsBitSet(Int bit) const -> Bool
{
	return MTable::_instance._BigIntegerInterface_IsBitSet(this, bit);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto BigIntegerInterface::GetLowestBits8U() const -> UChar
{
	return MTable::_instance._BigIntegerInterface_GetLowestBits8U(this);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto BigIntegerInterface::GetLowestBits8S() const -> Char
{
	return MTable::_instance._BigIntegerInterface_GetLowestBits8S(this);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto BigIntegerInterface::GetLowestBits16U() const -> UInt16
{
	return MTable::_instance._BigIntegerInterface_GetLowestBits16U(this);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto BigIntegerInterface::GetLowestBits16S() const -> Int16
{
	return MTable::_instance._BigIntegerInterface_GetLowestBits16S(this);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto BigIntegerInterface::GetLowestBits32U() const -> UInt32
{
	return MTable::_instance._BigIntegerInterface_GetLowestBits32U(this);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto BigIntegerInterface::GetLowestBits32S() const -> Int32
{
	return MTable::_instance._BigIntegerInterface_GetLowestBits32S(this);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto BigIntegerInterface::GetLowestBits64U() const -> UInt64
{
	return MTable::_instance._BigIntegerInterface_GetLowestBits64U(this);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto BigIntegerInterface::GetLowestBits64S() const -> Int64
{
	return MTable::_instance._BigIntegerInterface_GetLowestBits64S(this);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto BigIntegerInterface::GetDataCopy(Bool littleEndian, BaseArray<UChar>& data) const -> Result<void>
{
	return MTable::_instance._BigIntegerInterface_GetDataCopy(this, littleEndian, data);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto BigIntegerInterface::Add(const BigIntegerInterface* b) -> Result<void>
{
	return MTable::_instance._BigIntegerInterface_Add(this, b);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto BigIntegerInterface::Sub(const BigIntegerInterface* b) -> Result<void>
{
	return MTable::_instance._BigIntegerInterface_Sub(this, b);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto BigIntegerInterface::Inc() -> Result<void>
{
	return MTable::_instance._BigIntegerInterface_Inc(this);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto BigIntegerInterface::Dec() -> Result<void>
{
	return MTable::_instance._BigIntegerInterface_Dec(this);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto BigIntegerInterface::Mul(const BigIntegerInterface* b) -> Result<void>
{
	return MTable::_instance._BigIntegerInterface_Mul(this, b);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto BigIntegerInterface::Div(const BigIntegerInterface* b) -> Result<void>
{
	return MTable::_instance._BigIntegerInterface_Div(this, b);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto BigIntegerInterface::Mod(const BigIntegerInterface* b) -> Result<void>
{
	return MTable::_instance._BigIntegerInterface_Mod(this, b);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto BigIntegerInterface::DivMod(const BigIntegerInterface* b, BigInteger& r) -> Result<void>
{
	return MTable::_instance._BigIntegerInterface_DivMod(this, b, r);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto BigIntegerInterface::Pow(const BigIntegerInterface* b) -> Result<void>
{
	return MTable::_instance._BigIntegerInterface_Pow(this, b);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto BigIntegerInterface::PowMod(const BigIntegerInterface* b, const BigIntegerInterface* mod) -> Result<void>
{
	return MTable::_instance._BigIntegerInterface_PowMod(this, b, mod);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto BigIntegerInterface::GreatestCommonDivisor(const BigIntegerInterface* b) -> Result<void>
{
	return MTable::_instance._BigIntegerInterface_GreatestCommonDivisor(this, b);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto BigIntegerInterface::MultiplicativeInverse(const BigIntegerInterface* m) -> Result<Bool>
{
	return MTable::_instance._BigIntegerInterface_MultiplicativeInverse(this, m);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto BigIntegerInterface::LeftShift(Int s) -> Result<void>
{
	return MTable::_instance._BigIntegerInterface_LeftShift(this, s);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto BigIntegerInterface::RightShift(Int s) -> Result<void>
{
	return MTable::_instance._BigIntegerInterface_RightShift(this, s);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto BigIntegerInterface::Negate() -> Result<void>
{
	return MTable::_instance._BigIntegerInterface_Negate(this);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto BigIntegerInterface::SetBit(Int bit) -> Result<void>
{
	return MTable::_instance._BigIntegerInterface_SetBit(this, bit);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto BigIntegerInterface::ClearBit(Int bit) -> Result<void>
{
	return MTable::_instance._BigIntegerInterface_ClearBit(this, bit);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto BigIntegerInterface::ToggleBit(Int bit) -> Result<void>
{
	return MTable::_instance._BigIntegerInterface_ToggleBit(this, bit);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto BigIntegerInterface::Compare(const BigIntegerInterface* arg2) const -> COMPARERESULT
{
	return MTable::_instance._BigIntegerInterface_Compare(this, arg2);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto BigIntegerInterface::GetHashCode() const -> UInt
{
	return MTable::_instance._BigIntegerInterface_GetHashCode(this);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto BigIntegerInterface::ToString(const FormatStatement* formatStatement) const -> String
{
	return MTable::_instance._BigIntegerInterface_ToString(this, formatStatement);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto BigIntegerInterface::DescribeIO(const DataSerializeInterface& stream) -> Result<void>
{
	return MTable::_instance._BigIntegerInterface_DescribeIO(stream);
}

auto BigIntegerInterface::Reference::Create() -> maxon::ResultMemT<BigInteger>
{
	BigIntegerInterface* res_ = BigIntegerInterface::Alloc(MAXON_SOURCE_LOCATION);
	return BigInteger(maxon::ForwardResultPtr<BigIntegerInterface>(res_));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto BigIntegerInterface::ConstReferenceFunctionsImpl<S>::Zero() -> BigInteger { return BigInteger(MTable::_instance._BigIntegerInterface_Zero()); }
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto BigIntegerInterface::ConstReferenceFunctionsImpl<S>::One() -> BigInteger { return BigInteger(MTable::_instance._BigIntegerInterface_One()); }
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto BigIntegerInterface::ConstReferenceFunctionsImpl<S>::MinusOne() -> BigInteger { return BigInteger(MTable::_instance._BigIntegerInterface_MinusOne()); }
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto BigIntegerInterface::ReferenceFunctionsImpl<S>::Set(Char c) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); BigIntegerInterface* o_ = (BigIntegerInterface*) this->GetPointer(); if (MAXON_UNLIKELY(!o_)) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); 
	return (MTable::_instance._BigIntegerInterface_Set(o_, c));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto BigIntegerInterface::COWReferenceFunctionsImpl<S>::Set(Char c) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); BigIntegerInterface* o_ = (BigIntegerInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS) && MAXON_UNLIKELY(!o_)) return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); 
	return (MTable::_instance._BigIntegerInterface_Set(o_, c));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto BigIntegerInterface::ReferenceFunctionsImpl<S>::Set(UChar c) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); BigIntegerInterface* o_ = (BigIntegerInterface*) this->GetPointer(); if (MAXON_UNLIKELY(!o_)) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); 
	return (MTable::_instance._BigIntegerInterface_Set_1(o_, c));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto BigIntegerInterface::COWReferenceFunctionsImpl<S>::Set(UChar c) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); BigIntegerInterface* o_ = (BigIntegerInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS) && MAXON_UNLIKELY(!o_)) return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); 
	return (MTable::_instance._BigIntegerInterface_Set_1(o_, c));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto BigIntegerInterface::ReferenceFunctionsImpl<S>::Set(Int16 i) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); BigIntegerInterface* o_ = (BigIntegerInterface*) this->GetPointer(); if (MAXON_UNLIKELY(!o_)) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); 
	return (MTable::_instance._BigIntegerInterface_Set_2(o_, i));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto BigIntegerInterface::COWReferenceFunctionsImpl<S>::Set(Int16 i) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); BigIntegerInterface* o_ = (BigIntegerInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS) && MAXON_UNLIKELY(!o_)) return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); 
	return (MTable::_instance._BigIntegerInterface_Set_2(o_, i));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto BigIntegerInterface::ReferenceFunctionsImpl<S>::Set(UInt16 u) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); BigIntegerInterface* o_ = (BigIntegerInterface*) this->GetPointer(); if (MAXON_UNLIKELY(!o_)) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); 
	return (MTable::_instance._BigIntegerInterface_Set_3(o_, u));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto BigIntegerInterface::COWReferenceFunctionsImpl<S>::Set(UInt16 u) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); BigIntegerInterface* o_ = (BigIntegerInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS) && MAXON_UNLIKELY(!o_)) return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); 
	return (MTable::_instance._BigIntegerInterface_Set_3(o_, u));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto BigIntegerInterface::ReferenceFunctionsImpl<S>::Set(Int32 i) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); BigIntegerInterface* o_ = (BigIntegerInterface*) this->GetPointer(); if (MAXON_UNLIKELY(!o_)) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); 
	return (MTable::_instance._BigIntegerInterface_Set_4(o_, i));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto BigIntegerInterface::COWReferenceFunctionsImpl<S>::Set(Int32 i) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); BigIntegerInterface* o_ = (BigIntegerInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS) && MAXON_UNLIKELY(!o_)) return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); 
	return (MTable::_instance._BigIntegerInterface_Set_4(o_, i));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto BigIntegerInterface::ReferenceFunctionsImpl<S>::Set(UInt32 u) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); BigIntegerInterface* o_ = (BigIntegerInterface*) this->GetPointer(); if (MAXON_UNLIKELY(!o_)) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); 
	return (MTable::_instance._BigIntegerInterface_Set_5(o_, u));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto BigIntegerInterface::COWReferenceFunctionsImpl<S>::Set(UInt32 u) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); BigIntegerInterface* o_ = (BigIntegerInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS) && MAXON_UNLIKELY(!o_)) return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); 
	return (MTable::_instance._BigIntegerInterface_Set_5(o_, u));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto BigIntegerInterface::ReferenceFunctionsImpl<S>::Set(Int64 i) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); BigIntegerInterface* o_ = (BigIntegerInterface*) this->GetPointer(); if (MAXON_UNLIKELY(!o_)) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); 
	return (MTable::_instance._BigIntegerInterface_Set_6(o_, i));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto BigIntegerInterface::COWReferenceFunctionsImpl<S>::Set(Int64 i) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); BigIntegerInterface* o_ = (BigIntegerInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS) && MAXON_UNLIKELY(!o_)) return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); 
	return (MTable::_instance._BigIntegerInterface_Set_6(o_, i));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto BigIntegerInterface::ReferenceFunctionsImpl<S>::Set(UInt64 u) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); BigIntegerInterface* o_ = (BigIntegerInterface*) this->GetPointer(); if (MAXON_UNLIKELY(!o_)) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); 
	return (MTable::_instance._BigIntegerInterface_Set_7(o_, u));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto BigIntegerInterface::COWReferenceFunctionsImpl<S>::Set(UInt64 u) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); BigIntegerInterface* o_ = (BigIntegerInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS) && MAXON_UNLIKELY(!o_)) return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); 
	return (MTable::_instance._BigIntegerInterface_Set_7(o_, u));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto BigIntegerInterface::ReferenceFunctionsImpl<S>::SetRandom(Int bitCount, SecureRandomProvider provider) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); BigIntegerInterface* o_ = (BigIntegerInterface*) this->GetPointer(); if (MAXON_UNLIKELY(!o_)) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); 
	return (MTable::_instance._BigIntegerInterface_SetRandom(o_, bitCount, std::forward<SecureRandomProvider>(provider)));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto BigIntegerInterface::COWReferenceFunctionsImpl<S>::SetRandom(Int bitCount, SecureRandomProvider provider) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); BigIntegerInterface* o_ = (BigIntegerInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS) && MAXON_UNLIKELY(!o_)) return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); 
	return (MTable::_instance._BigIntegerInterface_SetRandom(o_, bitCount, std::forward<SecureRandomProvider>(provider)));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto BigIntegerInterface::ReferenceFunctionsImpl<S>::SetRandomPrime(Int bitCount, UInt certainty, SecureRandomProvider provider) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); BigIntegerInterface* o_ = (BigIntegerInterface*) this->GetPointer(); if (MAXON_UNLIKELY(!o_)) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); 
	return (MTable::_instance._BigIntegerInterface_SetRandomPrime(o_, bitCount, certainty, std::forward<SecureRandomProvider>(provider)));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto BigIntegerInterface::COWReferenceFunctionsImpl<S>::SetRandomPrime(Int bitCount, UInt certainty, SecureRandomProvider provider) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); BigIntegerInterface* o_ = (BigIntegerInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS) && MAXON_UNLIKELY(!o_)) return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); 
	return (MTable::_instance._BigIntegerInterface_SetRandomPrime(o_, bitCount, certainty, std::forward<SecureRandomProvider>(provider)));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto BigIntegerInterface::ReferenceFunctionsImpl<S>::Set(const Block<const Byte>& mem, Bool littleEndian) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); BigIntegerInterface* o_ = (BigIntegerInterface*) this->GetPointer(); if (MAXON_UNLIKELY(!o_)) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); 
	return (MTable::_instance._BigIntegerInterface_Set_8(o_, mem, littleEndian));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto BigIntegerInterface::COWReferenceFunctionsImpl<S>::Set(const Block<const Byte>& mem, Bool littleEndian) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); BigIntegerInterface* o_ = (BigIntegerInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS) && MAXON_UNLIKELY(!o_)) return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); 
	return (MTable::_instance._BigIntegerInterface_Set_8(o_, mem, littleEndian));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto BigIntegerInterface::ReferenceFunctionsImpl<S>::Set(const String& str) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); BigIntegerInterface* o_ = (BigIntegerInterface*) this->GetPointer(); if (MAXON_UNLIKELY(!o_)) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); 
	return (MTable::_instance._BigIntegerInterface_Set_9(o_, str));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto BigIntegerInterface::COWReferenceFunctionsImpl<S>::Set(const String& str) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); BigIntegerInterface* o_ = (BigIntegerInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS) && MAXON_UNLIKELY(!o_)) return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); 
	return (MTable::_instance._BigIntegerInterface_Set_9(o_, str));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto BigIntegerInterface::ReferenceFunctionsImpl<S>::SetHex(const String& str) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); BigIntegerInterface* o_ = (BigIntegerInterface*) this->GetPointer(); if (MAXON_UNLIKELY(!o_)) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); 
	return (MTable::_instance._BigIntegerInterface_SetHex(o_, str));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto BigIntegerInterface::COWReferenceFunctionsImpl<S>::SetHex(const String& str) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); BigIntegerInterface* o_ = (BigIntegerInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS) && MAXON_UNLIKELY(!o_)) return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); 
	return (MTable::_instance._BigIntegerInterface_SetHex(o_, str));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto BigIntegerInterface::ConstReferenceFunctionsImpl<S>::IsEven() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, false, typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const BigIntegerInterface* o_ = (const BigIntegerInterface*) this->GetPointer(); if (!(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS) && MAXON_UNLIKELY(!o_)) { o_ = BigIntegerInterface::NullValuePtr(); if (!o_) return maxon::PrivateLogNullptrError(false); } 
	return (MTable::_instance._BigIntegerInterface_IsEven(o_));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto BigIntegerInterface::ConstReferenceFunctionsImpl<S>::IsOdd() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, false, typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const BigIntegerInterface* o_ = (const BigIntegerInterface*) this->GetPointer(); if (!(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS) && MAXON_UNLIKELY(!o_)) { o_ = BigIntegerInterface::NullValuePtr(); if (!o_) return maxon::PrivateLogNullptrError(false); } 
	return (MTable::_instance._BigIntegerInterface_IsOdd(o_));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto BigIntegerInterface::ConstReferenceFunctionsImpl<S>::IsOne() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, false, typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const BigIntegerInterface* o_ = (const BigIntegerInterface*) this->GetPointer(); if (!(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS) && MAXON_UNLIKELY(!o_)) { o_ = BigIntegerInterface::NullValuePtr(); if (!o_) return maxon::PrivateLogNullptrError(false); } 
	return (MTable::_instance._BigIntegerInterface_IsOne(o_));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto BigIntegerInterface::ConstReferenceFunctionsImpl<S>::IsZero() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, false, typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const BigIntegerInterface* o_ = (const BigIntegerInterface*) this->GetPointer(); if (!(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS) && MAXON_UNLIKELY(!o_)) { o_ = BigIntegerInterface::NullValuePtr(); if (!o_) return maxon::PrivateLogNullptrError(false); } 
	return (MTable::_instance._BigIntegerInterface_IsZero(o_));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto BigIntegerInterface::ConstReferenceFunctionsImpl<S>::IsNegative() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, false, typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const BigIntegerInterface* o_ = (const BigIntegerInterface*) this->GetPointer(); if (!(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS) && MAXON_UNLIKELY(!o_)) { o_ = BigIntegerInterface::NullValuePtr(); if (!o_) return maxon::PrivateLogNullptrError(false); } 
	return (MTable::_instance._BigIntegerInterface_IsNegative(o_));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto BigIntegerInterface::ConstReferenceFunctionsImpl<S>::IsPowerOfTwo() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, false, typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const BigIntegerInterface* o_ = (const BigIntegerInterface*) this->GetPointer(); if (!(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS) && MAXON_UNLIKELY(!o_)) { o_ = BigIntegerInterface::NullValuePtr(); if (!o_) return maxon::PrivateLogNullptrError(false); } 
	return (MTable::_instance._BigIntegerInterface_IsPowerOfTwo(o_));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto BigIntegerInterface::ConstReferenceFunctionsImpl<S>::IsProbablyPrime(UInt certainty) const -> Result<Bool>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, false, Result<Bool>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const BigIntegerInterface* o_ = (const BigIntegerInterface*) this->GetPointer(); if (!(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS) && MAXON_UNLIKELY(!o_)) { o_ = BigIntegerInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (MTable::_instance._BigIntegerInterface_IsProbablyPrime(o_, certainty));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto BigIntegerInterface::ConstReferenceFunctionsImpl<S>::Sign() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, false, typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const BigIntegerInterface* o_ = (const BigIntegerInterface*) this->GetPointer(); if (!(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS) && MAXON_UNLIKELY(!o_)) { o_ = BigIntegerInterface::NullValuePtr(); if (!o_) return 0; } 
	return (MTable::_instance._BigIntegerInterface_Sign(o_));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto BigIntegerInterface::ConstReferenceFunctionsImpl<S>::GetHighestNonSignBit() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, false, typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const BigIntegerInterface* o_ = (const BigIntegerInterface*) this->GetPointer(); if (!(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS) && MAXON_UNLIKELY(!o_)) { o_ = BigIntegerInterface::NullValuePtr(); if (!o_) return 0; } 
	return (MTable::_instance._BigIntegerInterface_GetHighestNonSignBit(o_));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto BigIntegerInterface::ConstReferenceFunctionsImpl<S>::GetLowestSetBit() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, false, typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const BigIntegerInterface* o_ = (const BigIntegerInterface*) this->GetPointer(); if (!(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS) && MAXON_UNLIKELY(!o_)) { o_ = BigIntegerInterface::NullValuePtr(); if (!o_) return 0; } 
	return (MTable::_instance._BigIntegerInterface_GetLowestSetBit(o_));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto BigIntegerInterface::ConstReferenceFunctionsImpl<S>::GetLowestClearedBit() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, false, typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const BigIntegerInterface* o_ = (const BigIntegerInterface*) this->GetPointer(); if (!(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS) && MAXON_UNLIKELY(!o_)) { o_ = BigIntegerInterface::NullValuePtr(); if (!o_) return 0; } 
	return (MTable::_instance._BigIntegerInterface_GetLowestClearedBit(o_));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto BigIntegerInterface::ConstReferenceFunctionsImpl<S>::IsBitSet(Int bit) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, false, typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const BigIntegerInterface* o_ = (const BigIntegerInterface*) this->GetPointer(); if (!(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS) && MAXON_UNLIKELY(!o_)) { o_ = BigIntegerInterface::NullValuePtr(); if (!o_) return maxon::PrivateLogNullptrError(false); } 
	return (MTable::_instance._BigIntegerInterface_IsBitSet(o_, bit));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto BigIntegerInterface::ConstReferenceFunctionsImpl<S>::GetLowestBits8U() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<UChar>, UChar>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, false, typename std::conditional<S::HAS_ERROR, maxon::Result<UChar>, UChar>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const BigIntegerInterface* o_ = (const BigIntegerInterface*) this->GetPointer(); if (!(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS) && MAXON_UNLIKELY(!o_)) { o_ = BigIntegerInterface::NullValuePtr(); if (!o_) return 0; } 
	return (MTable::_instance._BigIntegerInterface_GetLowestBits8U(o_));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto BigIntegerInterface::ConstReferenceFunctionsImpl<S>::GetLowestBits8S() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Char>, Char>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, false, typename std::conditional<S::HAS_ERROR, maxon::Result<Char>, Char>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const BigIntegerInterface* o_ = (const BigIntegerInterface*) this->GetPointer(); if (!(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS) && MAXON_UNLIKELY(!o_)) { o_ = BigIntegerInterface::NullValuePtr(); if (!o_) return 0; } 
	return (MTable::_instance._BigIntegerInterface_GetLowestBits8S(o_));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto BigIntegerInterface::ConstReferenceFunctionsImpl<S>::GetLowestBits16U() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<UInt16>, UInt16>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, false, typename std::conditional<S::HAS_ERROR, maxon::Result<UInt16>, UInt16>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const BigIntegerInterface* o_ = (const BigIntegerInterface*) this->GetPointer(); if (!(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS) && MAXON_UNLIKELY(!o_)) { o_ = BigIntegerInterface::NullValuePtr(); if (!o_) return 0; } 
	return (MTable::_instance._BigIntegerInterface_GetLowestBits16U(o_));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto BigIntegerInterface::ConstReferenceFunctionsImpl<S>::GetLowestBits16S() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Int16>, Int16>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, false, typename std::conditional<S::HAS_ERROR, maxon::Result<Int16>, Int16>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const BigIntegerInterface* o_ = (const BigIntegerInterface*) this->GetPointer(); if (!(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS) && MAXON_UNLIKELY(!o_)) { o_ = BigIntegerInterface::NullValuePtr(); if (!o_) return 0; } 
	return (MTable::_instance._BigIntegerInterface_GetLowestBits16S(o_));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto BigIntegerInterface::ConstReferenceFunctionsImpl<S>::GetLowestBits32U() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<UInt32>, UInt32>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, false, typename std::conditional<S::HAS_ERROR, maxon::Result<UInt32>, UInt32>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const BigIntegerInterface* o_ = (const BigIntegerInterface*) this->GetPointer(); if (!(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS) && MAXON_UNLIKELY(!o_)) { o_ = BigIntegerInterface::NullValuePtr(); if (!o_) return 0; } 
	return (MTable::_instance._BigIntegerInterface_GetLowestBits32U(o_));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto BigIntegerInterface::ConstReferenceFunctionsImpl<S>::GetLowestBits32S() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Int32>, Int32>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, false, typename std::conditional<S::HAS_ERROR, maxon::Result<Int32>, Int32>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const BigIntegerInterface* o_ = (const BigIntegerInterface*) this->GetPointer(); if (!(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS) && MAXON_UNLIKELY(!o_)) { o_ = BigIntegerInterface::NullValuePtr(); if (!o_) return 0; } 
	return (MTable::_instance._BigIntegerInterface_GetLowestBits32S(o_));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto BigIntegerInterface::ConstReferenceFunctionsImpl<S>::GetLowestBits64U() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<UInt64>, UInt64>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, false, typename std::conditional<S::HAS_ERROR, maxon::Result<UInt64>, UInt64>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const BigIntegerInterface* o_ = (const BigIntegerInterface*) this->GetPointer(); if (!(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS) && MAXON_UNLIKELY(!o_)) { o_ = BigIntegerInterface::NullValuePtr(); if (!o_) return 0; } 
	return (MTable::_instance._BigIntegerInterface_GetLowestBits64U(o_));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto BigIntegerInterface::ConstReferenceFunctionsImpl<S>::GetLowestBits64S() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Int64>, Int64>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, false, typename std::conditional<S::HAS_ERROR, maxon::Result<Int64>, Int64>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const BigIntegerInterface* o_ = (const BigIntegerInterface*) this->GetPointer(); if (!(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS) && MAXON_UNLIKELY(!o_)) { o_ = BigIntegerInterface::NullValuePtr(); if (!o_) return 0; } 
	return (MTable::_instance._BigIntegerInterface_GetLowestBits64S(o_));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto BigIntegerInterface::ConstReferenceFunctionsImpl<S>::GetDataCopy(Bool littleEndian, BaseArray<UChar>& data) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const BigIntegerInterface* o_ = (const BigIntegerInterface*) this->GetPointer(); if (!(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS) && MAXON_UNLIKELY(!o_)) { o_ = BigIntegerInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (MTable::_instance._BigIntegerInterface_GetDataCopy(o_, littleEndian, data));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto BigIntegerInterface::ReferenceFunctionsImpl<S>::Add(const BigIntegerInterface* b) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); BigIntegerInterface* o_ = (BigIntegerInterface*) this->GetPointer(); if (MAXON_UNLIKELY(!o_)) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); 
	return (MTable::_instance._BigIntegerInterface_Add(o_, b));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto BigIntegerInterface::COWReferenceFunctionsImpl<S>::Add(const BigIntegerInterface* b) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); BigIntegerInterface* o_ = (BigIntegerInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS) && MAXON_UNLIKELY(!o_)) return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); 
	return (MTable::_instance._BigIntegerInterface_Add(o_, b));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto BigIntegerInterface::ReferenceFunctionsImpl<S>::Sub(const BigIntegerInterface* b) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); BigIntegerInterface* o_ = (BigIntegerInterface*) this->GetPointer(); if (MAXON_UNLIKELY(!o_)) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); 
	return (MTable::_instance._BigIntegerInterface_Sub(o_, b));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto BigIntegerInterface::COWReferenceFunctionsImpl<S>::Sub(const BigIntegerInterface* b) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); BigIntegerInterface* o_ = (BigIntegerInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS) && MAXON_UNLIKELY(!o_)) return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); 
	return (MTable::_instance._BigIntegerInterface_Sub(o_, b));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto BigIntegerInterface::ReferenceFunctionsImpl<S>::Inc() const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); BigIntegerInterface* o_ = (BigIntegerInterface*) this->GetPointer(); if (MAXON_UNLIKELY(!o_)) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); 
	return (MTable::_instance._BigIntegerInterface_Inc(o_));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto BigIntegerInterface::COWReferenceFunctionsImpl<S>::Inc() -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); BigIntegerInterface* o_ = (BigIntegerInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS) && MAXON_UNLIKELY(!o_)) return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); 
	return (MTable::_instance._BigIntegerInterface_Inc(o_));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto BigIntegerInterface::ReferenceFunctionsImpl<S>::Dec() const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); BigIntegerInterface* o_ = (BigIntegerInterface*) this->GetPointer(); if (MAXON_UNLIKELY(!o_)) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); 
	return (MTable::_instance._BigIntegerInterface_Dec(o_));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto BigIntegerInterface::COWReferenceFunctionsImpl<S>::Dec() -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); BigIntegerInterface* o_ = (BigIntegerInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS) && MAXON_UNLIKELY(!o_)) return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); 
	return (MTable::_instance._BigIntegerInterface_Dec(o_));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto BigIntegerInterface::ReferenceFunctionsImpl<S>::Mul(const BigIntegerInterface* b) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); BigIntegerInterface* o_ = (BigIntegerInterface*) this->GetPointer(); if (MAXON_UNLIKELY(!o_)) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); 
	return (MTable::_instance._BigIntegerInterface_Mul(o_, b));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto BigIntegerInterface::COWReferenceFunctionsImpl<S>::Mul(const BigIntegerInterface* b) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); BigIntegerInterface* o_ = (BigIntegerInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS) && MAXON_UNLIKELY(!o_)) return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); 
	return (MTable::_instance._BigIntegerInterface_Mul(o_, b));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto BigIntegerInterface::ReferenceFunctionsImpl<S>::Div(const BigIntegerInterface* b) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); BigIntegerInterface* o_ = (BigIntegerInterface*) this->GetPointer(); if (MAXON_UNLIKELY(!o_)) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); 
	return (MTable::_instance._BigIntegerInterface_Div(o_, b));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto BigIntegerInterface::COWReferenceFunctionsImpl<S>::Div(const BigIntegerInterface* b) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); BigIntegerInterface* o_ = (BigIntegerInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS) && MAXON_UNLIKELY(!o_)) return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); 
	return (MTable::_instance._BigIntegerInterface_Div(o_, b));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto BigIntegerInterface::ReferenceFunctionsImpl<S>::Mod(const BigIntegerInterface* b) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); BigIntegerInterface* o_ = (BigIntegerInterface*) this->GetPointer(); if (MAXON_UNLIKELY(!o_)) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); 
	return (MTable::_instance._BigIntegerInterface_Mod(o_, b));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto BigIntegerInterface::COWReferenceFunctionsImpl<S>::Mod(const BigIntegerInterface* b) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); BigIntegerInterface* o_ = (BigIntegerInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS) && MAXON_UNLIKELY(!o_)) return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); 
	return (MTable::_instance._BigIntegerInterface_Mod(o_, b));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto BigIntegerInterface::ReferenceFunctionsImpl<S>::DivMod(const BigIntegerInterface* b, BigInteger& r) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); BigIntegerInterface* o_ = (BigIntegerInterface*) this->GetPointer(); if (MAXON_UNLIKELY(!o_)) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); 
	return (MTable::_instance._BigIntegerInterface_DivMod(o_, b, r));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto BigIntegerInterface::COWReferenceFunctionsImpl<S>::DivMod(const BigIntegerInterface* b, BigInteger& r) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); BigIntegerInterface* o_ = (BigIntegerInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS) && MAXON_UNLIKELY(!o_)) return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); 
	return (MTable::_instance._BigIntegerInterface_DivMod(o_, b, r));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto BigIntegerInterface::ReferenceFunctionsImpl<S>::Pow(const BigIntegerInterface* b) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); BigIntegerInterface* o_ = (BigIntegerInterface*) this->GetPointer(); if (MAXON_UNLIKELY(!o_)) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); 
	return (MTable::_instance._BigIntegerInterface_Pow(o_, b));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto BigIntegerInterface::COWReferenceFunctionsImpl<S>::Pow(const BigIntegerInterface* b) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); BigIntegerInterface* o_ = (BigIntegerInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS) && MAXON_UNLIKELY(!o_)) return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); 
	return (MTable::_instance._BigIntegerInterface_Pow(o_, b));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto BigIntegerInterface::ReferenceFunctionsImpl<S>::PowMod(const BigIntegerInterface* b, const BigIntegerInterface* mod) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); BigIntegerInterface* o_ = (BigIntegerInterface*) this->GetPointer(); if (MAXON_UNLIKELY(!o_)) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); 
	return (MTable::_instance._BigIntegerInterface_PowMod(o_, b, mod));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto BigIntegerInterface::COWReferenceFunctionsImpl<S>::PowMod(const BigIntegerInterface* b, const BigIntegerInterface* mod) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); BigIntegerInterface* o_ = (BigIntegerInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS) && MAXON_UNLIKELY(!o_)) return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); 
	return (MTable::_instance._BigIntegerInterface_PowMod(o_, b, mod));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto BigIntegerInterface::ReferenceFunctionsImpl<S>::GreatestCommonDivisor(const BigIntegerInterface* b) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); BigIntegerInterface* o_ = (BigIntegerInterface*) this->GetPointer(); if (MAXON_UNLIKELY(!o_)) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); 
	return (MTable::_instance._BigIntegerInterface_GreatestCommonDivisor(o_, b));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto BigIntegerInterface::COWReferenceFunctionsImpl<S>::GreatestCommonDivisor(const BigIntegerInterface* b) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); BigIntegerInterface* o_ = (BigIntegerInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS) && MAXON_UNLIKELY(!o_)) return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); 
	return (MTable::_instance._BigIntegerInterface_GreatestCommonDivisor(o_, b));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto BigIntegerInterface::ReferenceFunctionsImpl<S>::MultiplicativeInverse(const BigIntegerInterface* m) const -> Result<Bool>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, false, Result<Bool>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); BigIntegerInterface* o_ = (BigIntegerInterface*) this->GetPointer(); if (MAXON_UNLIKELY(!o_)) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); 
	return (MTable::_instance._BigIntegerInterface_MultiplicativeInverse(o_, m));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto BigIntegerInterface::COWReferenceFunctionsImpl<S>::MultiplicativeInverse(const BigIntegerInterface* m) -> Result<Bool>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, false, Result<Bool>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); BigIntegerInterface* o_ = (BigIntegerInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS) && MAXON_UNLIKELY(!o_)) return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); 
	return (MTable::_instance._BigIntegerInterface_MultiplicativeInverse(o_, m));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto BigIntegerInterface::ReferenceFunctionsImpl<S>::LeftShift(Int s) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); BigIntegerInterface* o_ = (BigIntegerInterface*) this->GetPointer(); if (MAXON_UNLIKELY(!o_)) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); 
	return (MTable::_instance._BigIntegerInterface_LeftShift(o_, s));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto BigIntegerInterface::COWReferenceFunctionsImpl<S>::LeftShift(Int s) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); BigIntegerInterface* o_ = (BigIntegerInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS) && MAXON_UNLIKELY(!o_)) return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); 
	return (MTable::_instance._BigIntegerInterface_LeftShift(o_, s));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto BigIntegerInterface::ReferenceFunctionsImpl<S>::RightShift(Int s) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); BigIntegerInterface* o_ = (BigIntegerInterface*) this->GetPointer(); if (MAXON_UNLIKELY(!o_)) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); 
	return (MTable::_instance._BigIntegerInterface_RightShift(o_, s));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto BigIntegerInterface::COWReferenceFunctionsImpl<S>::RightShift(Int s) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); BigIntegerInterface* o_ = (BigIntegerInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS) && MAXON_UNLIKELY(!o_)) return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); 
	return (MTable::_instance._BigIntegerInterface_RightShift(o_, s));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto BigIntegerInterface::ReferenceFunctionsImpl<S>::Negate() const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); BigIntegerInterface* o_ = (BigIntegerInterface*) this->GetPointer(); if (MAXON_UNLIKELY(!o_)) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); 
	return (MTable::_instance._BigIntegerInterface_Negate(o_));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto BigIntegerInterface::COWReferenceFunctionsImpl<S>::Negate() -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); BigIntegerInterface* o_ = (BigIntegerInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS) && MAXON_UNLIKELY(!o_)) return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); 
	return (MTable::_instance._BigIntegerInterface_Negate(o_));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto BigIntegerInterface::ReferenceFunctionsImpl<S>::SetBit(Int bit) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); BigIntegerInterface* o_ = (BigIntegerInterface*) this->GetPointer(); if (MAXON_UNLIKELY(!o_)) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); 
	return (MTable::_instance._BigIntegerInterface_SetBit(o_, bit));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto BigIntegerInterface::COWReferenceFunctionsImpl<S>::SetBit(Int bit) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); BigIntegerInterface* o_ = (BigIntegerInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS) && MAXON_UNLIKELY(!o_)) return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); 
	return (MTable::_instance._BigIntegerInterface_SetBit(o_, bit));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto BigIntegerInterface::ReferenceFunctionsImpl<S>::ClearBit(Int bit) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); BigIntegerInterface* o_ = (BigIntegerInterface*) this->GetPointer(); if (MAXON_UNLIKELY(!o_)) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); 
	return (MTable::_instance._BigIntegerInterface_ClearBit(o_, bit));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto BigIntegerInterface::COWReferenceFunctionsImpl<S>::ClearBit(Int bit) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); BigIntegerInterface* o_ = (BigIntegerInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS) && MAXON_UNLIKELY(!o_)) return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); 
	return (MTable::_instance._BigIntegerInterface_ClearBit(o_, bit));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto BigIntegerInterface::ReferenceFunctionsImpl<S>::ToggleBit(Int bit) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); BigIntegerInterface* o_ = (BigIntegerInterface*) this->GetPointer(); if (MAXON_UNLIKELY(!o_)) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); 
	return (MTable::_instance._BigIntegerInterface_ToggleBit(o_, bit));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto BigIntegerInterface::COWReferenceFunctionsImpl<S>::ToggleBit(Int bit) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); BigIntegerInterface* o_ = (BigIntegerInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS) && MAXON_UNLIKELY(!o_)) return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); 
	return (MTable::_instance._BigIntegerInterface_ToggleBit(o_, bit));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto BigIntegerInterface::ConstReferenceFunctionsImpl<S>::Compare(const BigIntegerInterface* arg2) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<COMPARERESULT>, COMPARERESULT>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, false, typename std::conditional<S::HAS_ERROR, maxon::Result<COMPARERESULT>, COMPARERESULT>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const BigIntegerInterface* o_ = (const BigIntegerInterface*) this->GetPointer(); if (!(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS) && MAXON_UNLIKELY(!o_)) { o_ = BigIntegerInterface::NullValuePtr(); if (!o_) return maxon::PrivateIncompleteNullReturnValue<COMPARERESULT>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } 
	return (MTable::_instance._BigIntegerInterface_Compare(o_, arg2));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto BigIntegerInterface::ConstReferenceFunctionsImpl<S>::ToString(const FormatStatement* formatStatement) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<String>, String>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, false, typename std::conditional<S::HAS_ERROR, maxon::Result<String>, String>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const BigIntegerInterface* o_ = (const BigIntegerInterface*) this->GetPointer(); if (!(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS) && MAXON_UNLIKELY(!o_)) { o_ = BigIntegerInterface::NullValuePtr(); if (!o_) return maxon::PrivateIncompleteNullReturnValue<String>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } 
	return (MTable::_instance._BigIntegerInterface_ToString(o_, formatStatement));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto BigIntegerInterface::ConstReferenceFunctionsImpl<S>::DescribeIO(const DataSerializeInterface& stream) -> Result<void> { return (MTable::_instance._BigIntegerInterface_DescribeIO(stream)); }
#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT)
static maxon::EntityUse s_ui_maxon_BigIntegerInterface(BigIntegerInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/big_integer.h", false);
#endif
#endif

#ifdef MAXON_COMPILER_GCC
	#pragma GCC diagnostic pop
#endif

#endif

