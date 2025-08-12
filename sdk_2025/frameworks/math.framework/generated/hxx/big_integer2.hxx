
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
	static const maxon::UNRESOLVED_RETURN_TYPE _returnTypes[];
	static const maxon::Bool HAS_NONSTATIC = true;
	PRIVATE_MAXON_SF_POINTER(BigIntegerInterface_Free, Free, MAXON_EXPAND_VA_ARGS, (void), const BigIntegerInterface* object);
	PRIVATE_MAXON_SF_POINTER(BigIntegerInterface_Alloc, Alloc, MAXON_IGNORE_VA_ARGS, (BigIntegerInterface*), const maxon::SourceLocation& allocLocation);
	PRIVATE_MAXON_SF_POINTER(BigIntegerInterface_Alloc_1, Alloc, MAXON_IGNORE_VA_ARGS, (BigIntegerInterface*), const maxon::SourceLocation& allocLocation, const BigIntegerInterface& object);
	PRIVATE_MAXON_SF_POINTER(BigIntegerInterface_Zero, Zero, MAXON_EXPAND_VA_ARGS, (BigIntegerInterface*));
	PRIVATE_MAXON_SF_POINTER(BigIntegerInterface_One, One, MAXON_EXPAND_VA_ARGS, (BigIntegerInterface*));
	PRIVATE_MAXON_SF_POINTER(BigIntegerInterface_MinusOne, MinusOne, MAXON_EXPAND_VA_ARGS, (BigIntegerInterface*));
	PRIVATE_MAXON_MF_POINTER(BigIntegerInterface_Set, Set, false, BigIntegerInterface,, (Result<void>), Char c);
	PRIVATE_MAXON_MF_POINTER(BigIntegerInterface_Set_1, Set, false, BigIntegerInterface,, (Result<void>), UChar c);
	PRIVATE_MAXON_MF_POINTER(BigIntegerInterface_Set_2, Set, false, BigIntegerInterface,, (Result<void>), Int16 i);
	PRIVATE_MAXON_MF_POINTER(BigIntegerInterface_Set_3, Set, false, BigIntegerInterface,, (Result<void>), UInt16 u);
	PRIVATE_MAXON_MF_POINTER(BigIntegerInterface_Set_4, Set, false, BigIntegerInterface,, (Result<void>), Int32 i);
	PRIVATE_MAXON_MF_POINTER(BigIntegerInterface_Set_5, Set, false, BigIntegerInterface,, (Result<void>), UInt32 u);
	PRIVATE_MAXON_MF_POINTER(BigIntegerInterface_Set_6, Set, false, BigIntegerInterface,, (Result<void>), Int64 i);
	PRIVATE_MAXON_MF_POINTER(BigIntegerInterface_Set_7, Set, false, BigIntegerInterface,, (Result<void>), UInt64 u);
	PRIVATE_MAXON_MF_POINTER(BigIntegerInterface_SetRandom, SetRandom, false, BigIntegerInterface,, (Result<void>), Int bitCount, SecureRandomProvider provider);
	PRIVATE_MAXON_MF_POINTER(BigIntegerInterface_SetRandomPrime, SetRandomPrime, false, BigIntegerInterface,, (Result<void>), Int bitCount, UInt certainty, SecureRandomProvider provider);
	PRIVATE_MAXON_MF_POINTER(BigIntegerInterface_Set_8, Set, false, BigIntegerInterface,, (Result<void>), const Block<const Byte>& mem, Bool littleEndian);
	PRIVATE_MAXON_MF_POINTER(BigIntegerInterface_Set_9, Set, false, BigIntegerInterface,, (Result<void>), const String& str);
	PRIVATE_MAXON_MF_POINTER(BigIntegerInterface_SetHex, SetHex, false, BigIntegerInterface,, (Result<void>), const String& str);
	PRIVATE_MAXON_MF_POINTER(BigIntegerInterface_IsEven, IsEven, false, BigIntegerInterface, const, (Bool));
	PRIVATE_MAXON_MF_POINTER(BigIntegerInterface_IsOdd, IsOdd, false, BigIntegerInterface, const, (Bool));
	PRIVATE_MAXON_MF_POINTER(BigIntegerInterface_IsOne, IsOne, false, BigIntegerInterface, const, (Bool));
	PRIVATE_MAXON_MF_POINTER(BigIntegerInterface_IsZero, IsZero, false, BigIntegerInterface, const, (Bool));
	PRIVATE_MAXON_MF_POINTER(BigIntegerInterface_IsNegative, IsNegative, false, BigIntegerInterface, const, (Bool));
	PRIVATE_MAXON_MF_POINTER(BigIntegerInterface_IsPowerOfTwo, IsPowerOfTwo, false, BigIntegerInterface, const, (Bool));
	PRIVATE_MAXON_MF_POINTER(BigIntegerInterface_IsProbablyPrime, IsProbablyPrime, false, BigIntegerInterface, const, (Result<Bool>), UInt certainty);
	PRIVATE_MAXON_MF_POINTER(BigIntegerInterface_Sign, Sign, false, BigIntegerInterface, const, (Int));
	PRIVATE_MAXON_MF_POINTER(BigIntegerInterface_GetHighestNonSignBit, GetHighestNonSignBit, false, BigIntegerInterface, const, (Int));
	PRIVATE_MAXON_MF_POINTER(BigIntegerInterface_GetLowestSetBit, GetLowestSetBit, false, BigIntegerInterface, const, (Int));
	PRIVATE_MAXON_MF_POINTER(BigIntegerInterface_GetLowestClearedBit, GetLowestClearedBit, false, BigIntegerInterface, const, (Int));
	PRIVATE_MAXON_MF_POINTER(BigIntegerInterface_IsBitSet, IsBitSet, false, BigIntegerInterface, const, (Bool), Int bit);
	PRIVATE_MAXON_MF_POINTER(BigIntegerInterface_GetLowestBits8U, GetLowestBits8U, false, BigIntegerInterface, const, (UChar));
	PRIVATE_MAXON_MF_POINTER(BigIntegerInterface_GetLowestBits8S, GetLowestBits8S, false, BigIntegerInterface, const, (Char));
	PRIVATE_MAXON_MF_POINTER(BigIntegerInterface_GetLowestBits16U, GetLowestBits16U, false, BigIntegerInterface, const, (UInt16));
	PRIVATE_MAXON_MF_POINTER(BigIntegerInterface_GetLowestBits16S, GetLowestBits16S, false, BigIntegerInterface, const, (Int16));
	PRIVATE_MAXON_MF_POINTER(BigIntegerInterface_GetLowestBits32U, GetLowestBits32U, false, BigIntegerInterface, const, (UInt32));
	PRIVATE_MAXON_MF_POINTER(BigIntegerInterface_GetLowestBits32S, GetLowestBits32S, false, BigIntegerInterface, const, (Int32));
	PRIVATE_MAXON_MF_POINTER(BigIntegerInterface_GetLowestBits64U, GetLowestBits64U, false, BigIntegerInterface, const, (UInt64));
	PRIVATE_MAXON_MF_POINTER(BigIntegerInterface_GetLowestBits64S, GetLowestBits64S, false, BigIntegerInterface, const, (Int64));
	PRIVATE_MAXON_MF_POINTER(BigIntegerInterface_GetDataCopy, GetDataCopy, false, BigIntegerInterface, const, (Result<void>), Bool littleEndian, BaseArray<UChar>& data);
	PRIVATE_MAXON_MF_POINTER(BigIntegerInterface_Add, Add, false, BigIntegerInterface,, (Result<void>), const BigIntegerInterface* b);
	PRIVATE_MAXON_MF_POINTER(BigIntegerInterface_Sub, Sub, false, BigIntegerInterface,, (Result<void>), const BigIntegerInterface* b);
	PRIVATE_MAXON_MF_POINTER(BigIntegerInterface_Inc, Inc, false, BigIntegerInterface,, (Result<void>));
	PRIVATE_MAXON_MF_POINTER(BigIntegerInterface_Dec, Dec, false, BigIntegerInterface,, (Result<void>));
	PRIVATE_MAXON_MF_POINTER(BigIntegerInterface_Mul, Mul, false, BigIntegerInterface,, (Result<void>), const BigIntegerInterface* b);
	PRIVATE_MAXON_MF_POINTER(BigIntegerInterface_Div, Div, false, BigIntegerInterface,, (Result<void>), const BigIntegerInterface* b);
	PRIVATE_MAXON_MF_POINTER(BigIntegerInterface_Mod, Mod, false, BigIntegerInterface,, (Result<void>), const BigIntegerInterface* b);
	PRIVATE_MAXON_MF_POINTER(BigIntegerInterface_DivMod, DivMod, false, BigIntegerInterface,, (Result<void>), const BigIntegerInterface* b, BigInteger& r);
	PRIVATE_MAXON_MF_POINTER(BigIntegerInterface_Pow, Pow, false, BigIntegerInterface,, (Result<void>), const BigIntegerInterface* b);
	PRIVATE_MAXON_MF_POINTER(BigIntegerInterface_PowMod, PowMod, false, BigIntegerInterface,, (Result<void>), const BigIntegerInterface* b, const BigIntegerInterface* mod);
	PRIVATE_MAXON_MF_POINTER(BigIntegerInterface_GreatestCommonDivisor, GreatestCommonDivisor, false, BigIntegerInterface,, (Result<void>), const BigIntegerInterface* b);
	PRIVATE_MAXON_MF_POINTER(BigIntegerInterface_MultiplicativeInverse, MultiplicativeInverse, false, BigIntegerInterface,, (Result<Bool>), const BigIntegerInterface* m);
	PRIVATE_MAXON_MF_POINTER(BigIntegerInterface_LeftShift, LeftShift, false, BigIntegerInterface,, (Result<void>), Int s);
	PRIVATE_MAXON_MF_POINTER(BigIntegerInterface_RightShift, RightShift, false, BigIntegerInterface,, (Result<void>), Int s);
	PRIVATE_MAXON_MF_POINTER(BigIntegerInterface_Negate, Negate, false, BigIntegerInterface,, (Result<void>));
	PRIVATE_MAXON_MF_POINTER(BigIntegerInterface_SetBit, SetBit, false, BigIntegerInterface,, (Result<void>), Int bit);
	PRIVATE_MAXON_MF_POINTER(BigIntegerInterface_ClearBit, ClearBit, false, BigIntegerInterface,, (Result<void>), Int bit);
	PRIVATE_MAXON_MF_POINTER(BigIntegerInterface_ToggleBit, ToggleBit, false, BigIntegerInterface,, (Result<void>), Int bit);
	PRIVATE_MAXON_MF_POINTER(BigIntegerInterface_Compare, Compare, false, BigIntegerInterface, const, (COMPARERESULT), const BigIntegerInterface* arg2);
	PRIVATE_MAXON_MF_POINTER(BigIntegerInterface_GetHashCode, GetHashCode, false, BigIntegerInterface, const, (HashInt));
	PRIVATE_MAXON_MF_POINTER(BigIntegerInterface_GetUniqueHashCode, GetUniqueHashCode, false, BigIntegerInterface, const, (UniqueHash));
	PRIVATE_MAXON_MF_POINTER(BigIntegerInterface_ToString, ToString, false, BigIntegerInterface, const, (String), const FormatStatement* formatStatement);
	PRIVATE_MAXON_SF_POINTER(BigIntegerInterface_DescribeIO, DescribeIO, MAXON_EXPAND_VA_ARGS, (Result<void>), const DataSerializeInterface& stream);
	template <typename IMPL> void Init()
	{
		BigIntegerInterface_Free = BigIntegerInterface_Free_GetPtr<IMPL>(true);
		BigIntegerInterface_Alloc = BigIntegerInterface_Alloc_GetPtr<IMPL>(true);
		BigIntegerInterface_Alloc_1 = BigIntegerInterface_Alloc_1_GetPtr<IMPL>(true);
		BigIntegerInterface_Zero = BigIntegerInterface_Zero_GetPtr<IMPL>(true);
		BigIntegerInterface_One = BigIntegerInterface_One_GetPtr<IMPL>(true);
		BigIntegerInterface_MinusOne = BigIntegerInterface_MinusOne_GetPtr<IMPL>(true);
		BigIntegerInterface_Set = BigIntegerInterface_Set_GetPtr<IMPL>(0, true).first;
		BigIntegerInterface_Set_1 = BigIntegerInterface_Set_1_GetPtr<IMPL>(0, true).first;
		BigIntegerInterface_Set_2 = BigIntegerInterface_Set_2_GetPtr<IMPL>(0, true).first;
		BigIntegerInterface_Set_3 = BigIntegerInterface_Set_3_GetPtr<IMPL>(0, true).first;
		BigIntegerInterface_Set_4 = BigIntegerInterface_Set_4_GetPtr<IMPL>(0, true).first;
		BigIntegerInterface_Set_5 = BigIntegerInterface_Set_5_GetPtr<IMPL>(0, true).first;
		BigIntegerInterface_Set_6 = BigIntegerInterface_Set_6_GetPtr<IMPL>(0, true).first;
		BigIntegerInterface_Set_7 = BigIntegerInterface_Set_7_GetPtr<IMPL>(0, true).first;
		BigIntegerInterface_SetRandom = BigIntegerInterface_SetRandom_GetPtr<IMPL>(0, true).first;
		BigIntegerInterface_SetRandomPrime = BigIntegerInterface_SetRandomPrime_GetPtr<IMPL>(0, true).first;
		BigIntegerInterface_Set_8 = BigIntegerInterface_Set_8_GetPtr<IMPL>(0, true).first;
		BigIntegerInterface_Set_9 = BigIntegerInterface_Set_9_GetPtr<IMPL>(0, true).first;
		BigIntegerInterface_SetHex = BigIntegerInterface_SetHex_GetPtr<IMPL>(0, true).first;
		BigIntegerInterface_IsEven = BigIntegerInterface_IsEven_GetPtr<IMPL>(0, true).first;
		BigIntegerInterface_IsOdd = BigIntegerInterface_IsOdd_GetPtr<IMPL>(0, true).first;
		BigIntegerInterface_IsOne = BigIntegerInterface_IsOne_GetPtr<IMPL>(0, true).first;
		BigIntegerInterface_IsZero = BigIntegerInterface_IsZero_GetPtr<IMPL>(0, true).first;
		BigIntegerInterface_IsNegative = BigIntegerInterface_IsNegative_GetPtr<IMPL>(0, true).first;
		BigIntegerInterface_IsPowerOfTwo = BigIntegerInterface_IsPowerOfTwo_GetPtr<IMPL>(0, true).first;
		BigIntegerInterface_IsProbablyPrime = BigIntegerInterface_IsProbablyPrime_GetPtr<IMPL>(0, true).first;
		BigIntegerInterface_Sign = BigIntegerInterface_Sign_GetPtr<IMPL>(0, true).first;
		BigIntegerInterface_GetHighestNonSignBit = BigIntegerInterface_GetHighestNonSignBit_GetPtr<IMPL>(0, true).first;
		BigIntegerInterface_GetLowestSetBit = BigIntegerInterface_GetLowestSetBit_GetPtr<IMPL>(0, true).first;
		BigIntegerInterface_GetLowestClearedBit = BigIntegerInterface_GetLowestClearedBit_GetPtr<IMPL>(0, true).first;
		BigIntegerInterface_IsBitSet = BigIntegerInterface_IsBitSet_GetPtr<IMPL>(0, true).first;
		BigIntegerInterface_GetLowestBits8U = BigIntegerInterface_GetLowestBits8U_GetPtr<IMPL>(0, true).first;
		BigIntegerInterface_GetLowestBits8S = BigIntegerInterface_GetLowestBits8S_GetPtr<IMPL>(0, true).first;
		BigIntegerInterface_GetLowestBits16U = BigIntegerInterface_GetLowestBits16U_GetPtr<IMPL>(0, true).first;
		BigIntegerInterface_GetLowestBits16S = BigIntegerInterface_GetLowestBits16S_GetPtr<IMPL>(0, true).first;
		BigIntegerInterface_GetLowestBits32U = BigIntegerInterface_GetLowestBits32U_GetPtr<IMPL>(0, true).first;
		BigIntegerInterface_GetLowestBits32S = BigIntegerInterface_GetLowestBits32S_GetPtr<IMPL>(0, true).first;
		BigIntegerInterface_GetLowestBits64U = BigIntegerInterface_GetLowestBits64U_GetPtr<IMPL>(0, true).first;
		BigIntegerInterface_GetLowestBits64S = BigIntegerInterface_GetLowestBits64S_GetPtr<IMPL>(0, true).first;
		BigIntegerInterface_GetDataCopy = BigIntegerInterface_GetDataCopy_GetPtr<IMPL>(0, true).first;
		BigIntegerInterface_Add = BigIntegerInterface_Add_GetPtr<IMPL>(0, true).first;
		BigIntegerInterface_Sub = BigIntegerInterface_Sub_GetPtr<IMPL>(0, true).first;
		BigIntegerInterface_Inc = BigIntegerInterface_Inc_GetPtr<IMPL>(0, true).first;
		BigIntegerInterface_Dec = BigIntegerInterface_Dec_GetPtr<IMPL>(0, true).first;
		BigIntegerInterface_Mul = BigIntegerInterface_Mul_GetPtr<IMPL>(0, true).first;
		BigIntegerInterface_Div = BigIntegerInterface_Div_GetPtr<IMPL>(0, true).first;
		BigIntegerInterface_Mod = BigIntegerInterface_Mod_GetPtr<IMPL>(0, true).first;
		BigIntegerInterface_DivMod = BigIntegerInterface_DivMod_GetPtr<IMPL>(0, true).first;
		BigIntegerInterface_Pow = BigIntegerInterface_Pow_GetPtr<IMPL>(0, true).first;
		BigIntegerInterface_PowMod = BigIntegerInterface_PowMod_GetPtr<IMPL>(0, true).first;
		BigIntegerInterface_GreatestCommonDivisor = BigIntegerInterface_GreatestCommonDivisor_GetPtr<IMPL>(0, true).first;
		BigIntegerInterface_MultiplicativeInverse = BigIntegerInterface_MultiplicativeInverse_GetPtr<IMPL>(0, true).first;
		BigIntegerInterface_LeftShift = BigIntegerInterface_LeftShift_GetPtr<IMPL>(0, true).first;
		BigIntegerInterface_RightShift = BigIntegerInterface_RightShift_GetPtr<IMPL>(0, true).first;
		BigIntegerInterface_Negate = BigIntegerInterface_Negate_GetPtr<IMPL>(0, true).first;
		BigIntegerInterface_SetBit = BigIntegerInterface_SetBit_GetPtr<IMPL>(0, true).first;
		BigIntegerInterface_ClearBit = BigIntegerInterface_ClearBit_GetPtr<IMPL>(0, true).first;
		BigIntegerInterface_ToggleBit = BigIntegerInterface_ToggleBit_GetPtr<IMPL>(0, true).first;
		BigIntegerInterface_Compare = BigIntegerInterface_Compare_GetPtr<IMPL>(0, true).first;
		BigIntegerInterface_GetHashCode = BigIntegerInterface_GetHashCode_GetPtr<IMPL>(0, true).first;
		BigIntegerInterface_GetUniqueHashCode = BigIntegerInterface_GetUniqueHashCode_GetPtr<IMPL>(0, true).first;
		BigIntegerInterface_ToString = BigIntegerInterface_ToString_GetPtr<IMPL>(0, true).first;
		BigIntegerInterface_DescribeIO = BigIntegerInterface_DescribeIO_GetPtr<IMPL>(true);
	}
};

struct BigIntegerInterface::Hxx2
{
	class Unresolved;
	template <typename S> class Wrapper
	{
	public:
		using Implementation = S;
		static void BigIntegerInterface_Free(const BigIntegerInterface* object) { return S::Free(object); }
		static BigIntegerInterface* BigIntegerInterface_Alloc(const maxon::SourceLocation& allocLocation) { return S::Alloc(allocLocation); }
		static BigIntegerInterface* BigIntegerInterface_Alloc_1(const maxon::SourceLocation& allocLocation, const BigIntegerInterface& object) { return S::Alloc(allocLocation, ((const S&) object)); }
		static BigIntegerInterface* BigIntegerInterface_Zero() { return S::Zero(); }
		static BigIntegerInterface* BigIntegerInterface_One() { return S::One(); }
		static BigIntegerInterface* BigIntegerInterface_MinusOne() { return S::MinusOne(); }
		PRIVATE_MAXON_MF_WRAPPER(BigIntegerInterface_Set, BigIntegerInterface,, (Result<void>), Char c) { return S::Get(PRIVATE_MAXON_MF_THIS(BigIntegerInterface))->Set(c); }
		PRIVATE_MAXON_MF_WRAPPER(BigIntegerInterface_Set_1, BigIntegerInterface,, (Result<void>), UChar c) { return S::Get(PRIVATE_MAXON_MF_THIS(BigIntegerInterface))->Set(c); }
		PRIVATE_MAXON_MF_WRAPPER(BigIntegerInterface_Set_2, BigIntegerInterface,, (Result<void>), Int16 i) { return S::Get(PRIVATE_MAXON_MF_THIS(BigIntegerInterface))->Set(i); }
		PRIVATE_MAXON_MF_WRAPPER(BigIntegerInterface_Set_3, BigIntegerInterface,, (Result<void>), UInt16 u) { return S::Get(PRIVATE_MAXON_MF_THIS(BigIntegerInterface))->Set(u); }
		PRIVATE_MAXON_MF_WRAPPER(BigIntegerInterface_Set_4, BigIntegerInterface,, (Result<void>), Int32 i) { return S::Get(PRIVATE_MAXON_MF_THIS(BigIntegerInterface))->Set(i); }
		PRIVATE_MAXON_MF_WRAPPER(BigIntegerInterface_Set_5, BigIntegerInterface,, (Result<void>), UInt32 u) { return S::Get(PRIVATE_MAXON_MF_THIS(BigIntegerInterface))->Set(u); }
		PRIVATE_MAXON_MF_WRAPPER(BigIntegerInterface_Set_6, BigIntegerInterface,, (Result<void>), Int64 i) { return S::Get(PRIVATE_MAXON_MF_THIS(BigIntegerInterface))->Set(i); }
		PRIVATE_MAXON_MF_WRAPPER(BigIntegerInterface_Set_7, BigIntegerInterface,, (Result<void>), UInt64 u) { return S::Get(PRIVATE_MAXON_MF_THIS(BigIntegerInterface))->Set(u); }
		PRIVATE_MAXON_MF_WRAPPER(BigIntegerInterface_SetRandom, BigIntegerInterface,, (Result<void>), Int bitCount, SecureRandomProvider provider) { return S::Get(PRIVATE_MAXON_MF_THIS(BigIntegerInterface))->SetRandom(bitCount, std::forward<SecureRandomProvider>(provider)); }
		PRIVATE_MAXON_MF_WRAPPER(BigIntegerInterface_SetRandomPrime, BigIntegerInterface,, (Result<void>), Int bitCount, UInt certainty, SecureRandomProvider provider) { return S::Get(PRIVATE_MAXON_MF_THIS(BigIntegerInterface))->SetRandomPrime(bitCount, certainty, std::forward<SecureRandomProvider>(provider)); }
		PRIVATE_MAXON_MF_WRAPPER(BigIntegerInterface_Set_8, BigIntegerInterface,, (Result<void>), const Block<const Byte>& mem, Bool littleEndian) { return S::Get(PRIVATE_MAXON_MF_THIS(BigIntegerInterface))->Set(mem, littleEndian); }
		PRIVATE_MAXON_MF_WRAPPER(BigIntegerInterface_Set_9, BigIntegerInterface,, (Result<void>), const String& str) { return S::Get(PRIVATE_MAXON_MF_THIS(BigIntegerInterface))->Set(str); }
		PRIVATE_MAXON_MF_WRAPPER(BigIntegerInterface_SetHex, BigIntegerInterface,, (Result<void>), const String& str) { return S::Get(PRIVATE_MAXON_MF_THIS(BigIntegerInterface))->SetHex(str); }
		PRIVATE_MAXON_MF_WRAPPER(BigIntegerInterface_IsEven, BigIntegerInterface, const, (Bool)) { return S::Get(PRIVATE_MAXON_MF_THIS(const BigIntegerInterface))->IsEven(); }
		PRIVATE_MAXON_MF_WRAPPER(BigIntegerInterface_IsOdd, BigIntegerInterface, const, (Bool)) { return S::Get(PRIVATE_MAXON_MF_THIS(const BigIntegerInterface))->IsOdd(); }
		PRIVATE_MAXON_MF_WRAPPER(BigIntegerInterface_IsOne, BigIntegerInterface, const, (Bool)) { return S::Get(PRIVATE_MAXON_MF_THIS(const BigIntegerInterface))->IsOne(); }
		PRIVATE_MAXON_MF_WRAPPER(BigIntegerInterface_IsZero, BigIntegerInterface, const, (Bool)) { return S::Get(PRIVATE_MAXON_MF_THIS(const BigIntegerInterface))->IsZero(); }
		PRIVATE_MAXON_MF_WRAPPER(BigIntegerInterface_IsNegative, BigIntegerInterface, const, (Bool)) { return S::Get(PRIVATE_MAXON_MF_THIS(const BigIntegerInterface))->IsNegative(); }
		PRIVATE_MAXON_MF_WRAPPER(BigIntegerInterface_IsPowerOfTwo, BigIntegerInterface, const, (Bool)) { return S::Get(PRIVATE_MAXON_MF_THIS(const BigIntegerInterface))->IsPowerOfTwo(); }
		PRIVATE_MAXON_MF_WRAPPER(BigIntegerInterface_IsProbablyPrime, BigIntegerInterface, const, (Result<Bool>), UInt certainty) { return S::Get(PRIVATE_MAXON_MF_THIS(const BigIntegerInterface))->IsProbablyPrime(certainty); }
		PRIVATE_MAXON_MF_WRAPPER(BigIntegerInterface_Sign, BigIntegerInterface, const, (Int)) { return S::Get(PRIVATE_MAXON_MF_THIS(const BigIntegerInterface))->Sign(); }
		PRIVATE_MAXON_MF_WRAPPER(BigIntegerInterface_GetHighestNonSignBit, BigIntegerInterface, const, (Int)) { return S::Get(PRIVATE_MAXON_MF_THIS(const BigIntegerInterface))->GetHighestNonSignBit(); }
		PRIVATE_MAXON_MF_WRAPPER(BigIntegerInterface_GetLowestSetBit, BigIntegerInterface, const, (Int)) { return S::Get(PRIVATE_MAXON_MF_THIS(const BigIntegerInterface))->GetLowestSetBit(); }
		PRIVATE_MAXON_MF_WRAPPER(BigIntegerInterface_GetLowestClearedBit, BigIntegerInterface, const, (Int)) { return S::Get(PRIVATE_MAXON_MF_THIS(const BigIntegerInterface))->GetLowestClearedBit(); }
		PRIVATE_MAXON_MF_WRAPPER(BigIntegerInterface_IsBitSet, BigIntegerInterface, const, (Bool), Int bit) { return S::Get(PRIVATE_MAXON_MF_THIS(const BigIntegerInterface))->IsBitSet(bit); }
		PRIVATE_MAXON_MF_WRAPPER(BigIntegerInterface_GetLowestBits8U, BigIntegerInterface, const, (UChar)) { return S::Get(PRIVATE_MAXON_MF_THIS(const BigIntegerInterface))->GetLowestBits8U(); }
		PRIVATE_MAXON_MF_WRAPPER(BigIntegerInterface_GetLowestBits8S, BigIntegerInterface, const, (Char)) { return S::Get(PRIVATE_MAXON_MF_THIS(const BigIntegerInterface))->GetLowestBits8S(); }
		PRIVATE_MAXON_MF_WRAPPER(BigIntegerInterface_GetLowestBits16U, BigIntegerInterface, const, (UInt16)) { return S::Get(PRIVATE_MAXON_MF_THIS(const BigIntegerInterface))->GetLowestBits16U(); }
		PRIVATE_MAXON_MF_WRAPPER(BigIntegerInterface_GetLowestBits16S, BigIntegerInterface, const, (Int16)) { return S::Get(PRIVATE_MAXON_MF_THIS(const BigIntegerInterface))->GetLowestBits16S(); }
		PRIVATE_MAXON_MF_WRAPPER(BigIntegerInterface_GetLowestBits32U, BigIntegerInterface, const, (UInt32)) { return S::Get(PRIVATE_MAXON_MF_THIS(const BigIntegerInterface))->GetLowestBits32U(); }
		PRIVATE_MAXON_MF_WRAPPER(BigIntegerInterface_GetLowestBits32S, BigIntegerInterface, const, (Int32)) { return S::Get(PRIVATE_MAXON_MF_THIS(const BigIntegerInterface))->GetLowestBits32S(); }
		PRIVATE_MAXON_MF_WRAPPER(BigIntegerInterface_GetLowestBits64U, BigIntegerInterface, const, (UInt64)) { return S::Get(PRIVATE_MAXON_MF_THIS(const BigIntegerInterface))->GetLowestBits64U(); }
		PRIVATE_MAXON_MF_WRAPPER(BigIntegerInterface_GetLowestBits64S, BigIntegerInterface, const, (Int64)) { return S::Get(PRIVATE_MAXON_MF_THIS(const BigIntegerInterface))->GetLowestBits64S(); }
		PRIVATE_MAXON_MF_WRAPPER(BigIntegerInterface_GetDataCopy, BigIntegerInterface, const, (Result<void>), Bool littleEndian, BaseArray<UChar>& data) { return S::Get(PRIVATE_MAXON_MF_THIS(const BigIntegerInterface))->GetDataCopy(littleEndian, data); }
		PRIVATE_MAXON_MF_WRAPPER(BigIntegerInterface_Add, BigIntegerInterface,, (Result<void>), const BigIntegerInterface* b) { return S::Get(PRIVATE_MAXON_MF_THIS(BigIntegerInterface))->Add(b); }
		PRIVATE_MAXON_MF_WRAPPER(BigIntegerInterface_Sub, BigIntegerInterface,, (Result<void>), const BigIntegerInterface* b) { return S::Get(PRIVATE_MAXON_MF_THIS(BigIntegerInterface))->Sub(b); }
		PRIVATE_MAXON_MF_WRAPPER(BigIntegerInterface_Inc, BigIntegerInterface,, (Result<void>)) { return S::Get(PRIVATE_MAXON_MF_THIS(BigIntegerInterface))->Inc(); }
		PRIVATE_MAXON_MF_WRAPPER(BigIntegerInterface_Dec, BigIntegerInterface,, (Result<void>)) { return S::Get(PRIVATE_MAXON_MF_THIS(BigIntegerInterface))->Dec(); }
		PRIVATE_MAXON_MF_WRAPPER(BigIntegerInterface_Mul, BigIntegerInterface,, (Result<void>), const BigIntegerInterface* b) { return S::Get(PRIVATE_MAXON_MF_THIS(BigIntegerInterface))->Mul(b); }
		PRIVATE_MAXON_MF_WRAPPER(BigIntegerInterface_Div, BigIntegerInterface,, (Result<void>), const BigIntegerInterface* b) { return S::Get(PRIVATE_MAXON_MF_THIS(BigIntegerInterface))->Div(b); }
		PRIVATE_MAXON_MF_WRAPPER(BigIntegerInterface_Mod, BigIntegerInterface,, (Result<void>), const BigIntegerInterface* b) { return S::Get(PRIVATE_MAXON_MF_THIS(BigIntegerInterface))->Mod(b); }
		PRIVATE_MAXON_MF_WRAPPER(BigIntegerInterface_DivMod, BigIntegerInterface,, (Result<void>), const BigIntegerInterface* b, BigInteger& r) { return S::Get(PRIVATE_MAXON_MF_THIS(BigIntegerInterface))->DivMod(b, r); }
		PRIVATE_MAXON_MF_WRAPPER(BigIntegerInterface_Pow, BigIntegerInterface,, (Result<void>), const BigIntegerInterface* b) { return S::Get(PRIVATE_MAXON_MF_THIS(BigIntegerInterface))->Pow(b); }
		PRIVATE_MAXON_MF_WRAPPER(BigIntegerInterface_PowMod, BigIntegerInterface,, (Result<void>), const BigIntegerInterface* b, const BigIntegerInterface* mod) { return S::Get(PRIVATE_MAXON_MF_THIS(BigIntegerInterface))->PowMod(b, mod); }
		PRIVATE_MAXON_MF_WRAPPER(BigIntegerInterface_GreatestCommonDivisor, BigIntegerInterface,, (Result<void>), const BigIntegerInterface* b) { return S::Get(PRIVATE_MAXON_MF_THIS(BigIntegerInterface))->GreatestCommonDivisor(b); }
		PRIVATE_MAXON_MF_WRAPPER(BigIntegerInterface_MultiplicativeInverse, BigIntegerInterface,, (Result<Bool>), const BigIntegerInterface* m) { return S::Get(PRIVATE_MAXON_MF_THIS(BigIntegerInterface))->MultiplicativeInverse(m); }
		PRIVATE_MAXON_MF_WRAPPER(BigIntegerInterface_LeftShift, BigIntegerInterface,, (Result<void>), Int s) { return S::Get(PRIVATE_MAXON_MF_THIS(BigIntegerInterface))->LeftShift(s); }
		PRIVATE_MAXON_MF_WRAPPER(BigIntegerInterface_RightShift, BigIntegerInterface,, (Result<void>), Int s) { return S::Get(PRIVATE_MAXON_MF_THIS(BigIntegerInterface))->RightShift(s); }
		PRIVATE_MAXON_MF_WRAPPER(BigIntegerInterface_Negate, BigIntegerInterface,, (Result<void>)) { return S::Get(PRIVATE_MAXON_MF_THIS(BigIntegerInterface))->Negate(); }
		PRIVATE_MAXON_MF_WRAPPER(BigIntegerInterface_SetBit, BigIntegerInterface,, (Result<void>), Int bit) { return S::Get(PRIVATE_MAXON_MF_THIS(BigIntegerInterface))->SetBit(bit); }
		PRIVATE_MAXON_MF_WRAPPER(BigIntegerInterface_ClearBit, BigIntegerInterface,, (Result<void>), Int bit) { return S::Get(PRIVATE_MAXON_MF_THIS(BigIntegerInterface))->ClearBit(bit); }
		PRIVATE_MAXON_MF_WRAPPER(BigIntegerInterface_ToggleBit, BigIntegerInterface,, (Result<void>), Int bit) { return S::Get(PRIVATE_MAXON_MF_THIS(BigIntegerInterface))->ToggleBit(bit); }
		PRIVATE_MAXON_MF_WRAPPER(BigIntegerInterface_Compare, BigIntegerInterface, const, (COMPARERESULT), const BigIntegerInterface* arg2) { return S::Get(PRIVATE_MAXON_MF_THIS(const BigIntegerInterface))->Compare(arg2); }
		PRIVATE_MAXON_MF_WRAPPER(BigIntegerInterface_GetHashCode, BigIntegerInterface, const, (HashInt)) { return S::Get(PRIVATE_MAXON_MF_THIS(const BigIntegerInterface))->GetHashCode(); }
		PRIVATE_MAXON_MF_WRAPPER(BigIntegerInterface_GetUniqueHashCode, BigIntegerInterface, const, (UniqueHash)) { return S::Get(PRIVATE_MAXON_MF_THIS(const BigIntegerInterface))->GetUniqueHashCode(); }
		PRIVATE_MAXON_MF_WRAPPER(BigIntegerInterface_ToString, BigIntegerInterface, const, (String), const FormatStatement* formatStatement) { return S::Get(PRIVATE_MAXON_MF_THIS(const BigIntegerInterface))->ToString(formatStatement); }
		static Result<void> BigIntegerInterface_DescribeIO(const DataSerializeInterface& stream) { return S::DescribeIO(stream); }
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
	return PRIVATE_MAXON_MF_INVOKE((this), MTable::_instance.BigIntegerInterface_Set, c);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto BigIntegerInterface::Set(UChar c) -> Result<void>
{
	return PRIVATE_MAXON_MF_INVOKE((this), MTable::_instance.BigIntegerInterface_Set_1, c);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto BigIntegerInterface::Set(Int16 i) -> Result<void>
{
	return PRIVATE_MAXON_MF_INVOKE((this), MTable::_instance.BigIntegerInterface_Set_2, i);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto BigIntegerInterface::Set(UInt16 u) -> Result<void>
{
	return PRIVATE_MAXON_MF_INVOKE((this), MTable::_instance.BigIntegerInterface_Set_3, u);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto BigIntegerInterface::Set(Int32 i) -> Result<void>
{
	return PRIVATE_MAXON_MF_INVOKE((this), MTable::_instance.BigIntegerInterface_Set_4, i);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto BigIntegerInterface::Set(UInt32 u) -> Result<void>
{
	return PRIVATE_MAXON_MF_INVOKE((this), MTable::_instance.BigIntegerInterface_Set_5, u);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto BigIntegerInterface::Set(Int64 i) -> Result<void>
{
	return PRIVATE_MAXON_MF_INVOKE((this), MTable::_instance.BigIntegerInterface_Set_6, i);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto BigIntegerInterface::Set(UInt64 u) -> Result<void>
{
	return PRIVATE_MAXON_MF_INVOKE((this), MTable::_instance.BigIntegerInterface_Set_7, u);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto BigIntegerInterface::SetRandom(Int bitCount, SecureRandomProvider provider) -> Result<void>
{
	return PRIVATE_MAXON_MF_INVOKE((this), MTable::_instance.BigIntegerInterface_SetRandom, bitCount, std::forward<SecureRandomProvider>(provider));
}
MAXON_ATTRIBUTE_FORCE_INLINE auto BigIntegerInterface::SetRandomPrime(Int bitCount, UInt certainty, SecureRandomProvider provider) -> Result<void>
{
	return PRIVATE_MAXON_MF_INVOKE((this), MTable::_instance.BigIntegerInterface_SetRandomPrime, bitCount, certainty, std::forward<SecureRandomProvider>(provider));
}
MAXON_ATTRIBUTE_FORCE_INLINE auto BigIntegerInterface::Set(const Block<const Byte>& mem, Bool littleEndian) -> Result<void>
{
	return PRIVATE_MAXON_MF_INVOKE((this), MTable::_instance.BigIntegerInterface_Set_8, mem, littleEndian);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto BigIntegerInterface::Set(const String& str) -> Result<void>
{
	return PRIVATE_MAXON_MF_INVOKE((this), MTable::_instance.BigIntegerInterface_Set_9, str);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto BigIntegerInterface::SetHex(const String& str) -> Result<void>
{
	return PRIVATE_MAXON_MF_INVOKE((this), MTable::_instance.BigIntegerInterface_SetHex, str);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto BigIntegerInterface::IsEven() const -> Bool
{
	return PRIVATE_MAXON_MF_INVOKE((this), MTable::_instance.BigIntegerInterface_IsEven);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto BigIntegerInterface::IsOdd() const -> Bool
{
	return PRIVATE_MAXON_MF_INVOKE((this), MTable::_instance.BigIntegerInterface_IsOdd);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto BigIntegerInterface::IsOne() const -> Bool
{
	return PRIVATE_MAXON_MF_INVOKE((this), MTable::_instance.BigIntegerInterface_IsOne);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto BigIntegerInterface::IsZero() const -> Bool
{
	return PRIVATE_MAXON_MF_INVOKE((this), MTable::_instance.BigIntegerInterface_IsZero);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto BigIntegerInterface::IsNegative() const -> Bool
{
	return PRIVATE_MAXON_MF_INVOKE((this), MTable::_instance.BigIntegerInterface_IsNegative);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto BigIntegerInterface::IsPowerOfTwo() const -> Bool
{
	return PRIVATE_MAXON_MF_INVOKE((this), MTable::_instance.BigIntegerInterface_IsPowerOfTwo);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto BigIntegerInterface::IsProbablyPrime(UInt certainty) const -> Result<Bool>
{
	return PRIVATE_MAXON_MF_INVOKE((this), MTable::_instance.BigIntegerInterface_IsProbablyPrime, certainty);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto BigIntegerInterface::Sign() const -> Int
{
	return PRIVATE_MAXON_MF_INVOKE((this), MTable::_instance.BigIntegerInterface_Sign);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto BigIntegerInterface::GetHighestNonSignBit() const -> Int
{
	return PRIVATE_MAXON_MF_INVOKE((this), MTable::_instance.BigIntegerInterface_GetHighestNonSignBit);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto BigIntegerInterface::GetLowestSetBit() const -> Int
{
	return PRIVATE_MAXON_MF_INVOKE((this), MTable::_instance.BigIntegerInterface_GetLowestSetBit);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto BigIntegerInterface::GetLowestClearedBit() const -> Int
{
	return PRIVATE_MAXON_MF_INVOKE((this), MTable::_instance.BigIntegerInterface_GetLowestClearedBit);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto BigIntegerInterface::IsBitSet(Int bit) const -> Bool
{
	return PRIVATE_MAXON_MF_INVOKE((this), MTable::_instance.BigIntegerInterface_IsBitSet, bit);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto BigIntegerInterface::GetLowestBits8U() const -> UChar
{
	return PRIVATE_MAXON_MF_INVOKE((this), MTable::_instance.BigIntegerInterface_GetLowestBits8U);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto BigIntegerInterface::GetLowestBits8S() const -> Char
{
	return PRIVATE_MAXON_MF_INVOKE((this), MTable::_instance.BigIntegerInterface_GetLowestBits8S);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto BigIntegerInterface::GetLowestBits16U() const -> UInt16
{
	return PRIVATE_MAXON_MF_INVOKE((this), MTable::_instance.BigIntegerInterface_GetLowestBits16U);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto BigIntegerInterface::GetLowestBits16S() const -> Int16
{
	return PRIVATE_MAXON_MF_INVOKE((this), MTable::_instance.BigIntegerInterface_GetLowestBits16S);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto BigIntegerInterface::GetLowestBits32U() const -> UInt32
{
	return PRIVATE_MAXON_MF_INVOKE((this), MTable::_instance.BigIntegerInterface_GetLowestBits32U);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto BigIntegerInterface::GetLowestBits32S() const -> Int32
{
	return PRIVATE_MAXON_MF_INVOKE((this), MTable::_instance.BigIntegerInterface_GetLowestBits32S);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto BigIntegerInterface::GetLowestBits64U() const -> UInt64
{
	return PRIVATE_MAXON_MF_INVOKE((this), MTable::_instance.BigIntegerInterface_GetLowestBits64U);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto BigIntegerInterface::GetLowestBits64S() const -> Int64
{
	return PRIVATE_MAXON_MF_INVOKE((this), MTable::_instance.BigIntegerInterface_GetLowestBits64S);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto BigIntegerInterface::GetDataCopy(Bool littleEndian, BaseArray<UChar>& data) const -> Result<void>
{
	return PRIVATE_MAXON_MF_INVOKE((this), MTable::_instance.BigIntegerInterface_GetDataCopy, littleEndian, data);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto BigIntegerInterface::Add(const BigIntegerInterface* b) -> Result<void>
{
	return PRIVATE_MAXON_MF_INVOKE((this), MTable::_instance.BigIntegerInterface_Add, b);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto BigIntegerInterface::Sub(const BigIntegerInterface* b) -> Result<void>
{
	return PRIVATE_MAXON_MF_INVOKE((this), MTable::_instance.BigIntegerInterface_Sub, b);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto BigIntegerInterface::Inc() -> Result<void>
{
	return PRIVATE_MAXON_MF_INVOKE((this), MTable::_instance.BigIntegerInterface_Inc);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto BigIntegerInterface::Dec() -> Result<void>
{
	return PRIVATE_MAXON_MF_INVOKE((this), MTable::_instance.BigIntegerInterface_Dec);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto BigIntegerInterface::Mul(const BigIntegerInterface* b) -> Result<void>
{
	return PRIVATE_MAXON_MF_INVOKE((this), MTable::_instance.BigIntegerInterface_Mul, b);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto BigIntegerInterface::Div(const BigIntegerInterface* b) -> Result<void>
{
	return PRIVATE_MAXON_MF_INVOKE((this), MTable::_instance.BigIntegerInterface_Div, b);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto BigIntegerInterface::Mod(const BigIntegerInterface* b) -> Result<void>
{
	return PRIVATE_MAXON_MF_INVOKE((this), MTable::_instance.BigIntegerInterface_Mod, b);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto BigIntegerInterface::DivMod(const BigIntegerInterface* b, BigInteger& r) -> Result<void>
{
	return PRIVATE_MAXON_MF_INVOKE((this), MTable::_instance.BigIntegerInterface_DivMod, b, r);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto BigIntegerInterface::Pow(const BigIntegerInterface* b) -> Result<void>
{
	return PRIVATE_MAXON_MF_INVOKE((this), MTable::_instance.BigIntegerInterface_Pow, b);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto BigIntegerInterface::PowMod(const BigIntegerInterface* b, const BigIntegerInterface* mod) -> Result<void>
{
	return PRIVATE_MAXON_MF_INVOKE((this), MTable::_instance.BigIntegerInterface_PowMod, b, mod);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto BigIntegerInterface::GreatestCommonDivisor(const BigIntegerInterface* b) -> Result<void>
{
	return PRIVATE_MAXON_MF_INVOKE((this), MTable::_instance.BigIntegerInterface_GreatestCommonDivisor, b);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto BigIntegerInterface::MultiplicativeInverse(const BigIntegerInterface* m) -> Result<Bool>
{
	return PRIVATE_MAXON_MF_INVOKE((this), MTable::_instance.BigIntegerInterface_MultiplicativeInverse, m);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto BigIntegerInterface::LeftShift(Int s) -> Result<void>
{
	return PRIVATE_MAXON_MF_INVOKE((this), MTable::_instance.BigIntegerInterface_LeftShift, s);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto BigIntegerInterface::RightShift(Int s) -> Result<void>
{
	return PRIVATE_MAXON_MF_INVOKE((this), MTable::_instance.BigIntegerInterface_RightShift, s);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto BigIntegerInterface::Negate() -> Result<void>
{
	return PRIVATE_MAXON_MF_INVOKE((this), MTable::_instance.BigIntegerInterface_Negate);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto BigIntegerInterface::SetBit(Int bit) -> Result<void>
{
	return PRIVATE_MAXON_MF_INVOKE((this), MTable::_instance.BigIntegerInterface_SetBit, bit);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto BigIntegerInterface::ClearBit(Int bit) -> Result<void>
{
	return PRIVATE_MAXON_MF_INVOKE((this), MTable::_instance.BigIntegerInterface_ClearBit, bit);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto BigIntegerInterface::ToggleBit(Int bit) -> Result<void>
{
	return PRIVATE_MAXON_MF_INVOKE((this), MTable::_instance.BigIntegerInterface_ToggleBit, bit);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto BigIntegerInterface::Compare(const BigIntegerInterface* arg2) const -> COMPARERESULT
{
	return PRIVATE_MAXON_MF_INVOKE((this), MTable::_instance.BigIntegerInterface_Compare, arg2);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto BigIntegerInterface::GetHashCode() const -> HashInt
{
	return PRIVATE_MAXON_MF_INVOKE((this), MTable::_instance.BigIntegerInterface_GetHashCode);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto BigIntegerInterface::GetUniqueHashCode() const -> UniqueHash
{
	return PRIVATE_MAXON_MF_INVOKE((this), MTable::_instance.BigIntegerInterface_GetUniqueHashCode);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto BigIntegerInterface::ToString(const FormatStatement* formatStatement) const -> String
{
	return PRIVATE_MAXON_MF_INVOKE((this), MTable::_instance.BigIntegerInterface_ToString, formatStatement);
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
	HXXRETURN0(Result<void>); HXXRES; HXXNONCONST(, , false, HXXRET1(NULLPTR)) 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.BigIntegerInterface_Set, c));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto BigIntegerInterface::Hxx1::COWFn<S>::Set(Char c) -> Result<void>
{
	HXXRETURN0(Result<void>); HXXRES; HXXNONCONST(, MakeWritable(true)., true, HXXRET2a(HXXRET1(MAKE_WRITABLE_FAILED))) 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.BigIntegerInterface_Set, c));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto BigIntegerInterface::Hxx1::Fn<S>::Set(UChar c) const -> Result<void>
{
	HXXRETURN0(Result<void>); HXXRES; HXXNONCONST(, , false, HXXRET1(NULLPTR)) 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.BigIntegerInterface_Set_1, c));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto BigIntegerInterface::Hxx1::COWFn<S>::Set(UChar c) -> Result<void>
{
	HXXRETURN0(Result<void>); HXXRES; HXXNONCONST(, MakeWritable(true)., true, HXXRET2a(HXXRET1(MAKE_WRITABLE_FAILED))) 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.BigIntegerInterface_Set_1, c));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto BigIntegerInterface::Hxx1::Fn<S>::Set(Int16 i) const -> Result<void>
{
	HXXRETURN0(Result<void>); HXXRES; HXXNONCONST(, , false, HXXRET1(NULLPTR)) 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.BigIntegerInterface_Set_2, i));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto BigIntegerInterface::Hxx1::COWFn<S>::Set(Int16 i) -> Result<void>
{
	HXXRETURN0(Result<void>); HXXRES; HXXNONCONST(, MakeWritable(true)., true, HXXRET2a(HXXRET1(MAKE_WRITABLE_FAILED))) 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.BigIntegerInterface_Set_2, i));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto BigIntegerInterface::Hxx1::Fn<S>::Set(UInt16 u) const -> Result<void>
{
	HXXRETURN0(Result<void>); HXXRES; HXXNONCONST(, , false, HXXRET1(NULLPTR)) 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.BigIntegerInterface_Set_3, u));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto BigIntegerInterface::Hxx1::COWFn<S>::Set(UInt16 u) -> Result<void>
{
	HXXRETURN0(Result<void>); HXXRES; HXXNONCONST(, MakeWritable(true)., true, HXXRET2a(HXXRET1(MAKE_WRITABLE_FAILED))) 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.BigIntegerInterface_Set_3, u));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto BigIntegerInterface::Hxx1::Fn<S>::Set(Int32 i) const -> Result<void>
{
	HXXRETURN0(Result<void>); HXXRES; HXXNONCONST(, , false, HXXRET1(NULLPTR)) 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.BigIntegerInterface_Set_4, i));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto BigIntegerInterface::Hxx1::COWFn<S>::Set(Int32 i) -> Result<void>
{
	HXXRETURN0(Result<void>); HXXRES; HXXNONCONST(, MakeWritable(true)., true, HXXRET2a(HXXRET1(MAKE_WRITABLE_FAILED))) 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.BigIntegerInterface_Set_4, i));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto BigIntegerInterface::Hxx1::Fn<S>::Set(UInt32 u) const -> Result<void>
{
	HXXRETURN0(Result<void>); HXXRES; HXXNONCONST(, , false, HXXRET1(NULLPTR)) 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.BigIntegerInterface_Set_5, u));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto BigIntegerInterface::Hxx1::COWFn<S>::Set(UInt32 u) -> Result<void>
{
	HXXRETURN0(Result<void>); HXXRES; HXXNONCONST(, MakeWritable(true)., true, HXXRET2a(HXXRET1(MAKE_WRITABLE_FAILED))) 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.BigIntegerInterface_Set_5, u));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto BigIntegerInterface::Hxx1::Fn<S>::Set(Int64 i) const -> Result<void>
{
	HXXRETURN0(Result<void>); HXXRES; HXXNONCONST(, , false, HXXRET1(NULLPTR)) 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.BigIntegerInterface_Set_6, i));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto BigIntegerInterface::Hxx1::COWFn<S>::Set(Int64 i) -> Result<void>
{
	HXXRETURN0(Result<void>); HXXRES; HXXNONCONST(, MakeWritable(true)., true, HXXRET2a(HXXRET1(MAKE_WRITABLE_FAILED))) 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.BigIntegerInterface_Set_6, i));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto BigIntegerInterface::Hxx1::Fn<S>::Set(UInt64 u) const -> Result<void>
{
	HXXRETURN0(Result<void>); HXXRES; HXXNONCONST(, , false, HXXRET1(NULLPTR)) 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.BigIntegerInterface_Set_7, u));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto BigIntegerInterface::Hxx1::COWFn<S>::Set(UInt64 u) -> Result<void>
{
	HXXRETURN0(Result<void>); HXXRES; HXXNONCONST(, MakeWritable(true)., true, HXXRET2a(HXXRET1(MAKE_WRITABLE_FAILED))) 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.BigIntegerInterface_Set_7, u));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto BigIntegerInterface::Hxx1::Fn<S>::SetRandom(Int bitCount, SecureRandomProvider provider) const -> Result<void>
{
	HXXRETURN0(Result<void>); HXXRES; HXXNONCONST(, , false, HXXRET1(NULLPTR)) 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.BigIntegerInterface_SetRandom, bitCount, std::forward<SecureRandomProvider>(provider)));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto BigIntegerInterface::Hxx1::COWFn<S>::SetRandom(Int bitCount, SecureRandomProvider provider) -> Result<void>
{
	HXXRETURN0(Result<void>); HXXRES; HXXNONCONST(, MakeWritable(true)., true, HXXRET2a(HXXRET1(MAKE_WRITABLE_FAILED))) 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.BigIntegerInterface_SetRandom, bitCount, std::forward<SecureRandomProvider>(provider)));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto BigIntegerInterface::Hxx1::Fn<S>::SetRandomPrime(Int bitCount, UInt certainty, SecureRandomProvider provider) const -> Result<void>
{
	HXXRETURN0(Result<void>); HXXRES; HXXNONCONST(, , false, HXXRET1(NULLPTR)) 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.BigIntegerInterface_SetRandomPrime, bitCount, certainty, std::forward<SecureRandomProvider>(provider)));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto BigIntegerInterface::Hxx1::COWFn<S>::SetRandomPrime(Int bitCount, UInt certainty, SecureRandomProvider provider) -> Result<void>
{
	HXXRETURN0(Result<void>); HXXRES; HXXNONCONST(, MakeWritable(true)., true, HXXRET2a(HXXRET1(MAKE_WRITABLE_FAILED))) 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.BigIntegerInterface_SetRandomPrime, bitCount, certainty, std::forward<SecureRandomProvider>(provider)));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto BigIntegerInterface::Hxx1::Fn<S>::Set(const Block<const Byte>& mem, Bool littleEndian) const -> Result<void>
{
	HXXRETURN0(Result<void>); HXXRES; HXXNONCONST(, , false, HXXRET1(NULLPTR)) 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.BigIntegerInterface_Set_8, mem, littleEndian));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto BigIntegerInterface::Hxx1::COWFn<S>::Set(const Block<const Byte>& mem, Bool littleEndian) -> Result<void>
{
	HXXRETURN0(Result<void>); HXXRES; HXXNONCONST(, MakeWritable(true)., true, HXXRET2a(HXXRET1(MAKE_WRITABLE_FAILED))) 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.BigIntegerInterface_Set_8, mem, littleEndian));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto BigIntegerInterface::Hxx1::Fn<S>::Set(const String& str) const -> Result<void>
{
	HXXRETURN0(Result<void>); HXXRES; HXXNONCONST(, , false, HXXRET1(NULLPTR)) 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.BigIntegerInterface_Set_9, str));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto BigIntegerInterface::Hxx1::COWFn<S>::Set(const String& str) -> Result<void>
{
	HXXRETURN0(Result<void>); HXXRES; HXXNONCONST(, MakeWritable(true)., true, HXXRET2a(HXXRET1(MAKE_WRITABLE_FAILED))) 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.BigIntegerInterface_Set_9, str));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto BigIntegerInterface::Hxx1::Fn<S>::SetHex(const String& str) const -> Result<void>
{
	HXXRETURN0(Result<void>); HXXRES; HXXNONCONST(, , false, HXXRET1(NULLPTR)) 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.BigIntegerInterface_SetHex, str));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto BigIntegerInterface::Hxx1::COWFn<S>::SetHex(const String& str) -> Result<void>
{
	HXXRETURN0(Result<void>); HXXRES; HXXNONCONST(, MakeWritable(true)., true, HXXRET2a(HXXRET1(MAKE_WRITABLE_FAILED))) 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.BigIntegerInterface_SetHex, str));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto BigIntegerInterface::Hxx1::ConstFn<S>::IsEven() const -> HXXADDRET2(Bool)
{
	HXXRETURN0(HXXADDRET2(Bool)); HXXRES; HXXCONST(maxon::PrivateLogNullptrError(false)) 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.BigIntegerInterface_IsEven));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto BigIntegerInterface::Hxx1::ConstFn<S>::IsOdd() const -> HXXADDRET2(Bool)
{
	HXXRETURN0(HXXADDRET2(Bool)); HXXRES; HXXCONST(maxon::PrivateLogNullptrError(false)) 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.BigIntegerInterface_IsOdd));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto BigIntegerInterface::Hxx1::ConstFn<S>::IsOne() const -> HXXADDRET2(Bool)
{
	HXXRETURN0(HXXADDRET2(Bool)); HXXRES; HXXCONST(maxon::PrivateLogNullptrError(false)) 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.BigIntegerInterface_IsOne));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto BigIntegerInterface::Hxx1::ConstFn<S>::IsZero() const -> HXXADDRET2(Bool)
{
	HXXRETURN0(HXXADDRET2(Bool)); HXXRES; HXXCONST(maxon::PrivateLogNullptrError(false)) 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.BigIntegerInterface_IsZero));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto BigIntegerInterface::Hxx1::ConstFn<S>::IsNegative() const -> HXXADDRET2(Bool)
{
	HXXRETURN0(HXXADDRET2(Bool)); HXXRES; HXXCONST(maxon::PrivateLogNullptrError(false)) 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.BigIntegerInterface_IsNegative));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto BigIntegerInterface::Hxx1::ConstFn<S>::IsPowerOfTwo() const -> HXXADDRET2(Bool)
{
	HXXRETURN0(HXXADDRET2(Bool)); HXXRES; HXXCONST(maxon::PrivateLogNullptrError(false)) 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.BigIntegerInterface_IsPowerOfTwo));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto BigIntegerInterface::Hxx1::ConstFn<S>::IsProbablyPrime(UInt certainty) const -> Result<Bool>
{
	HXXRETURN0(Result<Bool>); HXXRES; HXXCONST(HXXRET1(NULLPTR)) 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.BigIntegerInterface_IsProbablyPrime, certainty));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto BigIntegerInterface::Hxx1::ConstFn<S>::Sign() const -> HXXADDRET2(Int)
{
	HXXRETURN0(HXXADDRET2(Int)); HXXRES; HXXCONST(0) 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.BigIntegerInterface_Sign));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto BigIntegerInterface::Hxx1::ConstFn<S>::GetHighestNonSignBit() const -> HXXADDRET2(Int)
{
	HXXRETURN0(HXXADDRET2(Int)); HXXRES; HXXCONST(0) 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.BigIntegerInterface_GetHighestNonSignBit));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto BigIntegerInterface::Hxx1::ConstFn<S>::GetLowestSetBit() const -> HXXADDRET2(Int)
{
	HXXRETURN0(HXXADDRET2(Int)); HXXRES; HXXCONST(0) 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.BigIntegerInterface_GetLowestSetBit));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto BigIntegerInterface::Hxx1::ConstFn<S>::GetLowestClearedBit() const -> HXXADDRET2(Int)
{
	HXXRETURN0(HXXADDRET2(Int)); HXXRES; HXXCONST(0) 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.BigIntegerInterface_GetLowestClearedBit));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto BigIntegerInterface::Hxx1::ConstFn<S>::IsBitSet(Int bit) const -> HXXADDRET2(Bool)
{
	HXXRETURN0(HXXADDRET2(Bool)); HXXRES; HXXCONST(maxon::PrivateLogNullptrError(false)) 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.BigIntegerInterface_IsBitSet, bit));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto BigIntegerInterface::Hxx1::ConstFn<S>::GetLowestBits8U() const -> HXXADDRET2(UChar)
{
	HXXRETURN0(HXXADDRET2(UChar)); HXXRES; HXXCONST(0) 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.BigIntegerInterface_GetLowestBits8U));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto BigIntegerInterface::Hxx1::ConstFn<S>::GetLowestBits8S() const -> HXXADDRET2(Char)
{
	HXXRETURN0(HXXADDRET2(Char)); HXXRES; HXXCONST(0) 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.BigIntegerInterface_GetLowestBits8S));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto BigIntegerInterface::Hxx1::ConstFn<S>::GetLowestBits16U() const -> HXXADDRET2(UInt16)
{
	HXXRETURN0(HXXADDRET2(UInt16)); HXXRES; HXXCONST(0) 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.BigIntegerInterface_GetLowestBits16U));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto BigIntegerInterface::Hxx1::ConstFn<S>::GetLowestBits16S() const -> HXXADDRET2(Int16)
{
	HXXRETURN0(HXXADDRET2(Int16)); HXXRES; HXXCONST(0) 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.BigIntegerInterface_GetLowestBits16S));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto BigIntegerInterface::Hxx1::ConstFn<S>::GetLowestBits32U() const -> HXXADDRET2(UInt32)
{
	HXXRETURN0(HXXADDRET2(UInt32)); HXXRES; HXXCONST(0) 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.BigIntegerInterface_GetLowestBits32U));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto BigIntegerInterface::Hxx1::ConstFn<S>::GetLowestBits32S() const -> HXXADDRET2(Int32)
{
	HXXRETURN0(HXXADDRET2(Int32)); HXXRES; HXXCONST(0) 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.BigIntegerInterface_GetLowestBits32S));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto BigIntegerInterface::Hxx1::ConstFn<S>::GetLowestBits64U() const -> HXXADDRET2(UInt64)
{
	HXXRETURN0(HXXADDRET2(UInt64)); HXXRES; HXXCONST(0) 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.BigIntegerInterface_GetLowestBits64U));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto BigIntegerInterface::Hxx1::ConstFn<S>::GetLowestBits64S() const -> HXXADDRET2(Int64)
{
	HXXRETURN0(HXXADDRET2(Int64)); HXXRES; HXXCONST(0) 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.BigIntegerInterface_GetLowestBits64S));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto BigIntegerInterface::Hxx1::ConstFn<S>::GetDataCopy(Bool littleEndian, BaseArray<UChar>& data) const -> Result<void>
{
	HXXRETURN0(Result<void>); HXXRES; HXXCONST(HXXRET1(NULLPTR)) 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.BigIntegerInterface_GetDataCopy, littleEndian, data));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto BigIntegerInterface::Hxx1::Fn<S>::Add(const BigIntegerInterface* b) const -> Result<void>
{
	HXXRETURN0(Result<void>); HXXRES; HXXNONCONST(, , false, HXXRET1(NULLPTR)) 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.BigIntegerInterface_Add, b));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto BigIntegerInterface::Hxx1::COWFn<S>::Add(const BigIntegerInterface* b) -> Result<void>
{
	HXXRETURN0(Result<void>); HXXRES; HXXNONCONST(, MakeWritable(true)., true, HXXRET2a(HXXRET1(MAKE_WRITABLE_FAILED))) 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.BigIntegerInterface_Add, b));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto BigIntegerInterface::Hxx1::Fn<S>::Sub(const BigIntegerInterface* b) const -> Result<void>
{
	HXXRETURN0(Result<void>); HXXRES; HXXNONCONST(, , false, HXXRET1(NULLPTR)) 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.BigIntegerInterface_Sub, b));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto BigIntegerInterface::Hxx1::COWFn<S>::Sub(const BigIntegerInterface* b) -> Result<void>
{
	HXXRETURN0(Result<void>); HXXRES; HXXNONCONST(, MakeWritable(true)., true, HXXRET2a(HXXRET1(MAKE_WRITABLE_FAILED))) 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.BigIntegerInterface_Sub, b));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto BigIntegerInterface::Hxx1::Fn<S>::Inc() const -> Result<void>
{
	HXXRETURN0(Result<void>); HXXRES; HXXNONCONST(, , false, HXXRET1(NULLPTR)) 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.BigIntegerInterface_Inc));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto BigIntegerInterface::Hxx1::COWFn<S>::Inc() -> Result<void>
{
	HXXRETURN0(Result<void>); HXXRES; HXXNONCONST(, MakeWritable(true)., true, HXXRET2a(HXXRET1(MAKE_WRITABLE_FAILED))) 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.BigIntegerInterface_Inc));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto BigIntegerInterface::Hxx1::Fn<S>::Dec() const -> Result<void>
{
	HXXRETURN0(Result<void>); HXXRES; HXXNONCONST(, , false, HXXRET1(NULLPTR)) 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.BigIntegerInterface_Dec));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto BigIntegerInterface::Hxx1::COWFn<S>::Dec() -> Result<void>
{
	HXXRETURN0(Result<void>); HXXRES; HXXNONCONST(, MakeWritable(true)., true, HXXRET2a(HXXRET1(MAKE_WRITABLE_FAILED))) 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.BigIntegerInterface_Dec));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto BigIntegerInterface::Hxx1::Fn<S>::Mul(const BigIntegerInterface* b) const -> Result<void>
{
	HXXRETURN0(Result<void>); HXXRES; HXXNONCONST(, , false, HXXRET1(NULLPTR)) 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.BigIntegerInterface_Mul, b));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto BigIntegerInterface::Hxx1::COWFn<S>::Mul(const BigIntegerInterface* b) -> Result<void>
{
	HXXRETURN0(Result<void>); HXXRES; HXXNONCONST(, MakeWritable(true)., true, HXXRET2a(HXXRET1(MAKE_WRITABLE_FAILED))) 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.BigIntegerInterface_Mul, b));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto BigIntegerInterface::Hxx1::Fn<S>::Div(const BigIntegerInterface* b) const -> Result<void>
{
	HXXRETURN0(Result<void>); HXXRES; HXXNONCONST(, , false, HXXRET1(NULLPTR)) 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.BigIntegerInterface_Div, b));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto BigIntegerInterface::Hxx1::COWFn<S>::Div(const BigIntegerInterface* b) -> Result<void>
{
	HXXRETURN0(Result<void>); HXXRES; HXXNONCONST(, MakeWritable(true)., true, HXXRET2a(HXXRET1(MAKE_WRITABLE_FAILED))) 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.BigIntegerInterface_Div, b));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto BigIntegerInterface::Hxx1::Fn<S>::Mod(const BigIntegerInterface* b) const -> Result<void>
{
	HXXRETURN0(Result<void>); HXXRES; HXXNONCONST(, , false, HXXRET1(NULLPTR)) 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.BigIntegerInterface_Mod, b));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto BigIntegerInterface::Hxx1::COWFn<S>::Mod(const BigIntegerInterface* b) -> Result<void>
{
	HXXRETURN0(Result<void>); HXXRES; HXXNONCONST(, MakeWritable(true)., true, HXXRET2a(HXXRET1(MAKE_WRITABLE_FAILED))) 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.BigIntegerInterface_Mod, b));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto BigIntegerInterface::Hxx1::Fn<S>::DivMod(const BigIntegerInterface* b, BigInteger& r) const -> Result<void>
{
	HXXRETURN0(Result<void>); HXXRES; HXXNONCONST(, , false, HXXRET1(NULLPTR)) 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.BigIntegerInterface_DivMod, b, r));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto BigIntegerInterface::Hxx1::COWFn<S>::DivMod(const BigIntegerInterface* b, BigInteger& r) -> Result<void>
{
	HXXRETURN0(Result<void>); HXXRES; HXXNONCONST(, MakeWritable(true)., true, HXXRET2a(HXXRET1(MAKE_WRITABLE_FAILED))) 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.BigIntegerInterface_DivMod, b, r));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto BigIntegerInterface::Hxx1::Fn<S>::Pow(const BigIntegerInterface* b) const -> Result<void>
{
	HXXRETURN0(Result<void>); HXXRES; HXXNONCONST(, , false, HXXRET1(NULLPTR)) 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.BigIntegerInterface_Pow, b));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto BigIntegerInterface::Hxx1::COWFn<S>::Pow(const BigIntegerInterface* b) -> Result<void>
{
	HXXRETURN0(Result<void>); HXXRES; HXXNONCONST(, MakeWritable(true)., true, HXXRET2a(HXXRET1(MAKE_WRITABLE_FAILED))) 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.BigIntegerInterface_Pow, b));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto BigIntegerInterface::Hxx1::Fn<S>::PowMod(const BigIntegerInterface* b, const BigIntegerInterface* mod) const -> Result<void>
{
	HXXRETURN0(Result<void>); HXXRES; HXXNONCONST(, , false, HXXRET1(NULLPTR)) 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.BigIntegerInterface_PowMod, b, mod));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto BigIntegerInterface::Hxx1::COWFn<S>::PowMod(const BigIntegerInterface* b, const BigIntegerInterface* mod) -> Result<void>
{
	HXXRETURN0(Result<void>); HXXRES; HXXNONCONST(, MakeWritable(true)., true, HXXRET2a(HXXRET1(MAKE_WRITABLE_FAILED))) 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.BigIntegerInterface_PowMod, b, mod));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto BigIntegerInterface::Hxx1::Fn<S>::GreatestCommonDivisor(const BigIntegerInterface* b) const -> Result<void>
{
	HXXRETURN0(Result<void>); HXXRES; HXXNONCONST(, , false, HXXRET1(NULLPTR)) 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.BigIntegerInterface_GreatestCommonDivisor, b));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto BigIntegerInterface::Hxx1::COWFn<S>::GreatestCommonDivisor(const BigIntegerInterface* b) -> Result<void>
{
	HXXRETURN0(Result<void>); HXXRES; HXXNONCONST(, MakeWritable(true)., true, HXXRET2a(HXXRET1(MAKE_WRITABLE_FAILED))) 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.BigIntegerInterface_GreatestCommonDivisor, b));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto BigIntegerInterface::Hxx1::Fn<S>::MultiplicativeInverse(const BigIntegerInterface* m) const -> Result<Bool>
{
	HXXRETURN0(Result<Bool>); HXXRES; HXXNONCONST(, , false, HXXRET1(NULLPTR)) 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.BigIntegerInterface_MultiplicativeInverse, m));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto BigIntegerInterface::Hxx1::COWFn<S>::MultiplicativeInverse(const BigIntegerInterface* m) -> Result<Bool>
{
	HXXRETURN0(Result<Bool>); HXXRES; HXXNONCONST(, MakeWritable(true)., true, HXXRET2a(HXXRET1(MAKE_WRITABLE_FAILED))) 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.BigIntegerInterface_MultiplicativeInverse, m));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto BigIntegerInterface::Hxx1::Fn<S>::LeftShift(Int s) const -> Result<void>
{
	HXXRETURN0(Result<void>); HXXRES; HXXNONCONST(, , false, HXXRET1(NULLPTR)) 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.BigIntegerInterface_LeftShift, s));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto BigIntegerInterface::Hxx1::COWFn<S>::LeftShift(Int s) -> Result<void>
{
	HXXRETURN0(Result<void>); HXXRES; HXXNONCONST(, MakeWritable(true)., true, HXXRET2a(HXXRET1(MAKE_WRITABLE_FAILED))) 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.BigIntegerInterface_LeftShift, s));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto BigIntegerInterface::Hxx1::Fn<S>::RightShift(Int s) const -> Result<void>
{
	HXXRETURN0(Result<void>); HXXRES; HXXNONCONST(, , false, HXXRET1(NULLPTR)) 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.BigIntegerInterface_RightShift, s));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto BigIntegerInterface::Hxx1::COWFn<S>::RightShift(Int s) -> Result<void>
{
	HXXRETURN0(Result<void>); HXXRES; HXXNONCONST(, MakeWritable(true)., true, HXXRET2a(HXXRET1(MAKE_WRITABLE_FAILED))) 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.BigIntegerInterface_RightShift, s));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto BigIntegerInterface::Hxx1::Fn<S>::Negate() const -> Result<void>
{
	HXXRETURN0(Result<void>); HXXRES; HXXNONCONST(, , false, HXXRET1(NULLPTR)) 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.BigIntegerInterface_Negate));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto BigIntegerInterface::Hxx1::COWFn<S>::Negate() -> Result<void>
{
	HXXRETURN0(Result<void>); HXXRES; HXXNONCONST(, MakeWritable(true)., true, HXXRET2a(HXXRET1(MAKE_WRITABLE_FAILED))) 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.BigIntegerInterface_Negate));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto BigIntegerInterface::Hxx1::Fn<S>::SetBit(Int bit) const -> Result<void>
{
	HXXRETURN0(Result<void>); HXXRES; HXXNONCONST(, , false, HXXRET1(NULLPTR)) 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.BigIntegerInterface_SetBit, bit));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto BigIntegerInterface::Hxx1::COWFn<S>::SetBit(Int bit) -> Result<void>
{
	HXXRETURN0(Result<void>); HXXRES; HXXNONCONST(, MakeWritable(true)., true, HXXRET2a(HXXRET1(MAKE_WRITABLE_FAILED))) 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.BigIntegerInterface_SetBit, bit));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto BigIntegerInterface::Hxx1::Fn<S>::ClearBit(Int bit) const -> Result<void>
{
	HXXRETURN0(Result<void>); HXXRES; HXXNONCONST(, , false, HXXRET1(NULLPTR)) 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.BigIntegerInterface_ClearBit, bit));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto BigIntegerInterface::Hxx1::COWFn<S>::ClearBit(Int bit) -> Result<void>
{
	HXXRETURN0(Result<void>); HXXRES; HXXNONCONST(, MakeWritable(true)., true, HXXRET2a(HXXRET1(MAKE_WRITABLE_FAILED))) 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.BigIntegerInterface_ClearBit, bit));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto BigIntegerInterface::Hxx1::Fn<S>::ToggleBit(Int bit) const -> Result<void>
{
	HXXRETURN0(Result<void>); HXXRES; HXXNONCONST(, , false, HXXRET1(NULLPTR)) 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.BigIntegerInterface_ToggleBit, bit));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto BigIntegerInterface::Hxx1::COWFn<S>::ToggleBit(Int bit) -> Result<void>
{
	HXXRETURN0(Result<void>); HXXRES; HXXNONCONST(, MakeWritable(true)., true, HXXRET2a(HXXRET1(MAKE_WRITABLE_FAILED))) 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.BigIntegerInterface_ToggleBit, bit));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto BigIntegerInterface::Hxx1::ConstFn<S>::Compare(const BigIntegerInterface* arg2) const -> HXXADDRET2(COMPARERESULT)
{
	HXXRETURN0(HXXADDRET2(COMPARERESULT)); HXXRES; HXXCONST(HXXRET3(NULLPTR, COMPARERESULT)) 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.BigIntegerInterface_Compare, arg2));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto BigIntegerInterface::Hxx1::ConstFn<S>::ToString(const FormatStatement* formatStatement) const -> HXXADDRET2(String)
{
	HXXRETURN0(HXXADDRET2(String)); HXXRES; HXXCONST(HXXRET3(NULLPTR, String)) 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.BigIntegerInterface_ToString, formatStatement));
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

