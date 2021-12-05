#if 1
namespace maxon
{
	const maxon::Char* const BigIntegerInterface::MTable::_ids = 
		"Free@43a2d720376161a8\0" // void Free(const BigIntegerInterface* object)
		"Alloc@ab8edf309b47f23f\0" // BigIntegerInterface* Alloc(const maxon::SourceLocation& allocLocation)
		"Alloc@2cc5f1a6edb45453\0" // BigIntegerInterface* Alloc(const maxon::SourceLocation& allocLocation, const BigIntegerInterface& object)
		"Zero@42963f988a9cbd8f\0" // BigIntegerInterface* Zero()
		"One@42963f988a9cbd8f\0" // BigIntegerInterface* One()
		"MinusOne@42963f988a9cbd8f\0" // BigIntegerInterface* MinusOne()
		"Set@56cb0c2802eda00e\0" // Result<void> Set(Char c)
		"Set@829678d85bb34fb3\0" // Result<void> Set(UChar c)
		"Set@829678d85b1de89c\0" // Result<void> Set(Int16 i)
		"Set@d038a2331b0e2d97\0" // Result<void> Set(UInt16 u)
		"Set@829678d85b1de8d6\0" // Result<void> Set(Int32 i)
		"Set@d038a2331b0e2dd1\0" // Result<void> Set(UInt32 u)
		"Set@829678d85b1de935\0" // Result<void> Set(Int64 i)
		"Set@d038a2331b0e2e30\0" // Result<void> Set(UInt64 u)
		"SetRandom@951726b3d02011a0\0" // Result<void> SetRandom(Int bitCount, SecureRandomProvider provider)
		"SetRandomPrime@f1784ade492c3d28\0" // Result<void> SetRandomPrime(Int bitCount, UInt certainty, SecureRandomProvider provider)
		"Set@d9714db557e5be45\0" // Result<void> Set(const Block<const Byte>& mem, Bool littleEndian)
		"Set@84c7b902e2c48cc0\0" // Result<void> Set(const String& str)
		"SetHex@84c7b902e2c48cc0\0" // Result<void> SetHex(const String& str)
		"IsEven@76f01901\0" // Bool IsEven() const
		"IsOdd@76f01901\0" // Bool IsOdd() const
		"IsOne@76f01901\0" // Bool IsOne() const
		"IsZero@76f01901\0" // Bool IsZero() const
		"IsNegative@76f01901\0" // Bool IsNegative() const
		"IsPowerOfTwo@76f01901\0" // Bool IsPowerOfTwo() const
		"IsProbablyPrime@81ff126cd5e5d452\0" // Result<Bool> IsProbablyPrime(UInt certainty) const
		"Sign@4386c86\0" // Int Sign() const
		"GetHighestNonSignBit@4386c86\0" // Int GetHighestNonSignBit() const
		"GetLowestSetBit@4386c86\0" // Int GetLowestSetBit() const
		"GetLowestClearedBit@4386c86\0" // Int GetLowestClearedBit() const
		"IsBitSet@3610ee763824\0" // Bool IsBitSet(Int bit) const
		"GetLowestBits8U@1208adb302\0" // UChar GetLowestBits8U() const
		"GetLowestBits8S@783c066d\0" // Char GetLowestBits8S() const
		"GetLowestBits16U@23055999bb6\0" // UInt16 GetLowestBits16U() const
		"GetLowestBits16S@fd7d5b5ab\0" // Int16 GetLowestBits16S() const
		"GetLowestBits32U@230559a7570\0" // UInt32 GetLowestBits32U() const
		"GetLowestBits32S@fd7d68f65\0" // Int32 GetLowestBits32S() const
		"GetLowestBits64U@230559bda0f\0" // UInt64 GetLowestBits64U() const
		"GetLowestBits64S@fd7d7f404\0" // Int64 GetLowestBits64S() const
		"GetDataCopy@9498957db560d205\0" // Result<void> GetDataCopy(Bool littleEndian, BaseArray<UChar>& data) const
		"Add@3de43d4d37acd424\0" // Result<void> Add(const BigIntegerInterface* b)
		"Sub@3de43d4d37acd424\0" // Result<void> Sub(const BigIntegerInterface* b)
		"Inc@a54f4799cbe1a498\0" // Result<void> Inc()
		"Dec@a54f4799cbe1a498\0" // Result<void> Dec()
		"Mul@3de43d4d37acd424\0" // Result<void> Mul(const BigIntegerInterface* b)
		"Div@3de43d4d37acd424\0" // Result<void> Div(const BigIntegerInterface* b)
		"Mod@3de43d4d37acd424\0" // Result<void> Mod(const BigIntegerInterface* b)
		"DivMod@1531d324d6775a20\0" // Result<void> DivMod(const BigIntegerInterface* b, BigInteger& r)
		"Pow@3de43d4d37acd424\0" // Result<void> Pow(const BigIntegerInterface* b)
		"PowMod@d92ff02baa70d414\0" // Result<void> PowMod(const BigIntegerInterface* b, const BigIntegerInterface* mod)
		"GreatestCommonDivisor@3de43d4d37acd424\0" // Result<void> GreatestCommonDivisor(const BigIntegerInterface* b)
		"MultiplicativeInverse@dc3fbb18dc6b049a\0" // Result<Bool> MultiplicativeInverse(const BigIntegerInterface* m)
		"LeftShift@44dd4274e7521437\0" // Result<void> LeftShift(Int s)
		"RightShift@44dd4274e7521437\0" // Result<void> RightShift(Int s)
		"Negate@a54f4799cbe1a498\0" // Result<void> Negate()
		"SetBit@44dd4274e7521437\0" // Result<void> SetBit(Int bit)
		"ClearBit@44dd4274e7521437\0" // Result<void> ClearBit(Int bit)
		"ToggleBit@44dd4274e7521437\0" // Result<void> ToggleBit(Int bit)
		"Compare@876b7e9fd1756c4d\0" // COMPARERESULT Compare(const BigIntegerInterface* arg2) const
		"GetHashCode@95445951\0" // UInt GetHashCode() const
		"ToString@7de9f6f51c89c899\0" // String ToString(const FormatStatement* formatStatement) const
		"DescribeIO@0c0a05550eef0455\0" // Result<void> DescribeIO(const DataSerializeInterface& stream)
	"";
	MAXON_WARNING_PUSH
	MAXON_WARNING_DISABLE_DEPRECATED
	class BigIntegerInterface::Hxx2::Unresolved : public BigIntegerInterface
	{
	public:
		static const Unresolved* Get(const BigIntegerInterface* o) { return (const Unresolved*) o; }
		static Unresolved* Get(BigIntegerInterface* o) { return (Unresolved*) o; }
		static void Free(const BigIntegerInterface* object) { if (object && maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return BigIntegerInterface::Free(object); return maxon::PrivateLogNullptrError();}
		static BigIntegerInterface* Alloc(const maxon::SourceLocation& allocLocation) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return BigIntegerInterface::Alloc(allocLocation); return nullptr;}
		static BigIntegerInterface* Alloc(const maxon::SourceLocation& allocLocation, const BigIntegerInterface& object) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return BigIntegerInterface::Alloc(allocLocation, object); return nullptr;}
		static BigIntegerInterface* Zero() { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return BigIntegerInterface::Zero(); return nullptr;}
		static BigIntegerInterface* One() { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return BigIntegerInterface::One(); return nullptr;}
		static BigIntegerInterface* MinusOne() { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return BigIntegerInterface::MinusOne(); return nullptr;}
		Result<void> Set(Char c) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return ((BigIntegerInterface*) this)->Set(c); return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::UNRESOLVED);}
		Result<void> Set(UChar c) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return ((BigIntegerInterface*) this)->Set(c); return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::UNRESOLVED);}
		Result<void> Set(Int16 i) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return ((BigIntegerInterface*) this)->Set(i); return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::UNRESOLVED);}
		Result<void> Set(UInt16 u) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return ((BigIntegerInterface*) this)->Set(u); return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::UNRESOLVED);}
		Result<void> Set(Int32 i) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return ((BigIntegerInterface*) this)->Set(i); return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::UNRESOLVED);}
		Result<void> Set(UInt32 u) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return ((BigIntegerInterface*) this)->Set(u); return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::UNRESOLVED);}
		Result<void> Set(Int64 i) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return ((BigIntegerInterface*) this)->Set(i); return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::UNRESOLVED);}
		Result<void> Set(UInt64 u) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return ((BigIntegerInterface*) this)->Set(u); return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::UNRESOLVED);}
		Result<void> SetRandom(Int bitCount, SecureRandomProvider provider) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return ((BigIntegerInterface*) this)->SetRandom(bitCount, std::forward<SecureRandomProvider>(provider)); return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::UNRESOLVED);}
		Result<void> SetRandomPrime(Int bitCount, UInt certainty, SecureRandomProvider provider) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return ((BigIntegerInterface*) this)->SetRandomPrime(bitCount, certainty, std::forward<SecureRandomProvider>(provider)); return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::UNRESOLVED);}
		Result<void> Set(const Block<const Byte>& mem, Bool littleEndian) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return ((BigIntegerInterface*) this)->Set(mem, littleEndian); return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::UNRESOLVED);}
		Result<void> Set(const String& str) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return ((BigIntegerInterface*) this)->Set(str); return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::UNRESOLVED);}
		Result<void> SetHex(const String& str) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return ((BigIntegerInterface*) this)->SetHex(str); return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::UNRESOLVED);}
		Bool IsEven() const { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ((const BigIntegerInterface*) this)->IsEven(); return maxon::PrivateLogNullptrError(false);}
		Bool IsOdd() const { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ((const BigIntegerInterface*) this)->IsOdd(); return maxon::PrivateLogNullptrError(false);}
		Bool IsOne() const { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ((const BigIntegerInterface*) this)->IsOne(); return maxon::PrivateLogNullptrError(false);}
		Bool IsZero() const { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ((const BigIntegerInterface*) this)->IsZero(); return maxon::PrivateLogNullptrError(false);}
		Bool IsNegative() const { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ((const BigIntegerInterface*) this)->IsNegative(); return maxon::PrivateLogNullptrError(false);}
		Bool IsPowerOfTwo() const { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ((const BigIntegerInterface*) this)->IsPowerOfTwo(); return maxon::PrivateLogNullptrError(false);}
		Result<Bool> IsProbablyPrime(UInt certainty) const { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return ((const BigIntegerInterface*) this)->IsProbablyPrime(certainty); return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::UNRESOLVED);}
		Int Sign() const { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ((const BigIntegerInterface*) this)->Sign(); return 0;}
		Int GetHighestNonSignBit() const { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ((const BigIntegerInterface*) this)->GetHighestNonSignBit(); return 0;}
		Int GetLowestSetBit() const { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ((const BigIntegerInterface*) this)->GetLowestSetBit(); return 0;}
		Int GetLowestClearedBit() const { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ((const BigIntegerInterface*) this)->GetLowestClearedBit(); return 0;}
		Bool IsBitSet(Int bit) const { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ((const BigIntegerInterface*) this)->IsBitSet(bit); return maxon::PrivateLogNullptrError(false);}
		UChar GetLowestBits8U() const { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ((const BigIntegerInterface*) this)->GetLowestBits8U(); return 0;}
		Char GetLowestBits8S() const { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ((const BigIntegerInterface*) this)->GetLowestBits8S(); return 0;}
		UInt16 GetLowestBits16U() const { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ((const BigIntegerInterface*) this)->GetLowestBits16U(); return 0;}
		Int16 GetLowestBits16S() const { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ((const BigIntegerInterface*) this)->GetLowestBits16S(); return 0;}
		UInt32 GetLowestBits32U() const { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ((const BigIntegerInterface*) this)->GetLowestBits32U(); return 0;}
		Int32 GetLowestBits32S() const { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ((const BigIntegerInterface*) this)->GetLowestBits32S(); return 0;}
		UInt64 GetLowestBits64U() const { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ((const BigIntegerInterface*) this)->GetLowestBits64U(); return 0;}
		Int64 GetLowestBits64S() const { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ((const BigIntegerInterface*) this)->GetLowestBits64S(); return 0;}
		Result<void> GetDataCopy(Bool littleEndian, BaseArray<UChar>& data) const { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return ((const BigIntegerInterface*) this)->GetDataCopy(littleEndian, data); return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::UNRESOLVED);}
		Result<void> Add(const BigIntegerInterface* b) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return ((BigIntegerInterface*) this)->Add(b); return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::UNRESOLVED);}
		Result<void> Sub(const BigIntegerInterface* b) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return ((BigIntegerInterface*) this)->Sub(b); return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::UNRESOLVED);}
		Result<void> Inc() { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return ((BigIntegerInterface*) this)->Inc(); return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::UNRESOLVED);}
		Result<void> Dec() { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return ((BigIntegerInterface*) this)->Dec(); return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::UNRESOLVED);}
		Result<void> Mul(const BigIntegerInterface* b) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return ((BigIntegerInterface*) this)->Mul(b); return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::UNRESOLVED);}
		Result<void> Div(const BigIntegerInterface* b) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return ((BigIntegerInterface*) this)->Div(b); return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::UNRESOLVED);}
		Result<void> Mod(const BigIntegerInterface* b) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return ((BigIntegerInterface*) this)->Mod(b); return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::UNRESOLVED);}
		Result<void> DivMod(const BigIntegerInterface* b, BigInteger& r) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return ((BigIntegerInterface*) this)->DivMod(b, r); return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::UNRESOLVED);}
		Result<void> Pow(const BigIntegerInterface* b) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return ((BigIntegerInterface*) this)->Pow(b); return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::UNRESOLVED);}
		Result<void> PowMod(const BigIntegerInterface* b, const BigIntegerInterface* mod) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return ((BigIntegerInterface*) this)->PowMod(b, mod); return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::UNRESOLVED);}
		Result<void> GreatestCommonDivisor(const BigIntegerInterface* b) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return ((BigIntegerInterface*) this)->GreatestCommonDivisor(b); return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::UNRESOLVED);}
		Result<Bool> MultiplicativeInverse(const BigIntegerInterface* m) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return ((BigIntegerInterface*) this)->MultiplicativeInverse(m); return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::UNRESOLVED);}
		Result<void> LeftShift(Int s) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return ((BigIntegerInterface*) this)->LeftShift(s); return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::UNRESOLVED);}
		Result<void> RightShift(Int s) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return ((BigIntegerInterface*) this)->RightShift(s); return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::UNRESOLVED);}
		Result<void> Negate() { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return ((BigIntegerInterface*) this)->Negate(); return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::UNRESOLVED);}
		Result<void> SetBit(Int bit) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return ((BigIntegerInterface*) this)->SetBit(bit); return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::UNRESOLVED);}
		Result<void> ClearBit(Int bit) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return ((BigIntegerInterface*) this)->ClearBit(bit); return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::UNRESOLVED);}
		Result<void> ToggleBit(Int bit) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return ((BigIntegerInterface*) this)->ToggleBit(bit); return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::UNRESOLVED);}
		COMPARERESULT Compare(const BigIntegerInterface* arg2) const { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ((const BigIntegerInterface*) this)->Compare(arg2); return maxon::PrivateIncompleteNullReturnValue<COMPARERESULT>(maxon::NULL_RETURN_REASON::UNRESOLVED, OVERLOAD_MAX_RANK);}
		UInt GetHashCode() const { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ((const BigIntegerInterface*) this)->GetHashCode(); return 0;}
		String ToString(const FormatStatement* formatStatement) const { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ((const BigIntegerInterface*) this)->ToString(formatStatement); return maxon::PrivateIncompleteNullReturnValue<String>(maxon::NULL_RETURN_REASON::UNRESOLVED, OVERLOAD_MAX_RANK);}
		static Result<void> DescribeIO(const DataSerializeInterface& stream) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return BigIntegerInterface::DescribeIO(stream); return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::UNRESOLVED);}
	};
	MAXON_WARNING_POP
#ifdef PRIVATE_MAXON_ASSEMBLE_UNRESOLVED
	const maxon::NULL_RETURN_TYPE BigIntegerInterface::MTable::_returnTypes[] = 
	{
		maxon::NULL_RETURN_TYPE::VOID_ZERO_FREE_FUNCTION,
		maxon::details::NullReturnType<BigIntegerInterface*>::value,
		maxon::details::NullReturnType<BigIntegerInterface*>::value,
		maxon::details::NullReturnType<BigIntegerInterface*>::value,
		maxon::details::NullReturnType<BigIntegerInterface*>::value,
		maxon::details::NullReturnType<BigIntegerInterface*>::value,
		maxon::details::NullReturnType<Result<void>>::value,
		maxon::details::NullReturnType<Result<void>>::value,
		maxon::details::NullReturnType<Result<void>>::value,
		maxon::details::NullReturnType<Result<void>>::value,
		maxon::details::NullReturnType<Result<void>>::value,
		maxon::details::NullReturnType<Result<void>>::value,
		maxon::details::NullReturnType<Result<void>>::value,
		maxon::details::NullReturnType<Result<void>>::value,
		maxon::details::NullReturnType<Result<void>>::value,
		maxon::details::NullReturnType<Result<void>>::value,
		maxon::details::NullReturnType<Result<void>>::value,
		maxon::details::NullReturnType<Result<void>>::value,
		maxon::details::NullReturnType<Result<void>>::value,
		maxon::details::NullReturnType<Bool>::value,
		maxon::details::NullReturnType<Bool>::value,
		maxon::details::NullReturnType<Bool>::value,
		maxon::details::NullReturnType<Bool>::value,
		maxon::details::NullReturnType<Bool>::value,
		maxon::details::NullReturnType<Bool>::value,
		maxon::details::NullReturnType<Result<Bool>>::value,
		maxon::details::NullReturnType<Int>::value,
		maxon::details::NullReturnType<Int>::value,
		maxon::details::NullReturnType<Int>::value,
		maxon::details::NullReturnType<Int>::value,
		maxon::details::NullReturnType<Bool>::value,
		maxon::details::NullReturnType<UChar>::value,
		maxon::details::NullReturnType<Char>::value,
		maxon::details::NullReturnType<UInt16>::value,
		maxon::details::NullReturnType<Int16>::value,
		maxon::details::NullReturnType<UInt32>::value,
		maxon::details::NullReturnType<Int32>::value,
		maxon::details::NullReturnType<UInt64>::value,
		maxon::details::NullReturnType<Int64>::value,
		maxon::details::NullReturnType<Result<void>>::value,
		maxon::details::NullReturnType<Result<void>>::value,
		maxon::details::NullReturnType<Result<void>>::value,
		maxon::details::NullReturnType<Result<void>>::value,
		maxon::details::NullReturnType<Result<void>>::value,
		maxon::details::NullReturnType<Result<void>>::value,
		maxon::details::NullReturnType<Result<void>>::value,
		maxon::details::NullReturnType<Result<void>>::value,
		maxon::details::NullReturnType<Result<void>>::value,
		maxon::details::NullReturnType<Result<void>>::value,
		maxon::details::NullReturnType<Result<void>>::value,
		maxon::details::NullReturnType<Result<void>>::value,
		maxon::details::NullReturnType<Result<Bool>>::value,
		maxon::details::NullReturnType<Result<void>>::value,
		maxon::details::NullReturnType<Result<void>>::value,
		maxon::details::NullReturnType<Result<void>>::value,
		maxon::details::NullReturnType<Result<void>>::value,
		maxon::details::NullReturnType<Result<void>>::value,
		maxon::details::NullReturnType<Result<void>>::value,
		maxon::details::NullReturnType<COMPARERESULT>::value,
		maxon::details::NullReturnType<UInt>::value,
		maxon::details::NullReturnType<String>::value,
		maxon::details::NullReturnType<Result<void>>::value,
		maxon::NULL_RETURN_TYPE::OTHER
	};
#endif
	maxon::Bool BigIntegerInterface::MTable::InitUnresolved(maxon::NonvirtualInterfaceReference::UnresolvedAssembler assembler, MTable* tbl)
	{
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->_BigIntegerInterface_Free = &Hxx2::Wrapper<Hxx2::Unresolved>::_BigIntegerInterface_Free;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->_BigIntegerInterface_Alloc = &Hxx2::Wrapper<Hxx2::Unresolved>::_BigIntegerInterface_Alloc;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->_BigIntegerInterface_Alloc_1 = &Hxx2::Wrapper<Hxx2::Unresolved>::_BigIntegerInterface_Alloc_1;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->_BigIntegerInterface_Zero = &Hxx2::Wrapper<Hxx2::Unresolved>::_BigIntegerInterface_Zero;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->_BigIntegerInterface_One = &Hxx2::Wrapper<Hxx2::Unresolved>::_BigIntegerInterface_One;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->_BigIntegerInterface_MinusOne = &Hxx2::Wrapper<Hxx2::Unresolved>::_BigIntegerInterface_MinusOne;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<void>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_BigIntegerInterface_Set = &Hxx2::Wrapper<Hxx2::Unresolved>::_BigIntegerInterface_Set;
		#else
		tbl->_BigIntegerInterface_Set = &Hxx2::Wrapper<Hxx2::Unresolved>::_BigIntegerInterface_Set;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<void>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_BigIntegerInterface_Set_1 = &Hxx2::Wrapper<Hxx2::Unresolved>::_BigIntegerInterface_Set_1;
		#else
		tbl->_BigIntegerInterface_Set_1 = &Hxx2::Wrapper<Hxx2::Unresolved>::_BigIntegerInterface_Set_1;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<void>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_BigIntegerInterface_Set_2 = &Hxx2::Wrapper<Hxx2::Unresolved>::_BigIntegerInterface_Set_2;
		#else
		tbl->_BigIntegerInterface_Set_2 = &Hxx2::Wrapper<Hxx2::Unresolved>::_BigIntegerInterface_Set_2;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<void>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_BigIntegerInterface_Set_3 = &Hxx2::Wrapper<Hxx2::Unresolved>::_BigIntegerInterface_Set_3;
		#else
		tbl->_BigIntegerInterface_Set_3 = &Hxx2::Wrapper<Hxx2::Unresolved>::_BigIntegerInterface_Set_3;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<void>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_BigIntegerInterface_Set_4 = &Hxx2::Wrapper<Hxx2::Unresolved>::_BigIntegerInterface_Set_4;
		#else
		tbl->_BigIntegerInterface_Set_4 = &Hxx2::Wrapper<Hxx2::Unresolved>::_BigIntegerInterface_Set_4;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<void>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_BigIntegerInterface_Set_5 = &Hxx2::Wrapper<Hxx2::Unresolved>::_BigIntegerInterface_Set_5;
		#else
		tbl->_BigIntegerInterface_Set_5 = &Hxx2::Wrapper<Hxx2::Unresolved>::_BigIntegerInterface_Set_5;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<void>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_BigIntegerInterface_Set_6 = &Hxx2::Wrapper<Hxx2::Unresolved>::_BigIntegerInterface_Set_6;
		#else
		tbl->_BigIntegerInterface_Set_6 = &Hxx2::Wrapper<Hxx2::Unresolved>::_BigIntegerInterface_Set_6;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<void>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_BigIntegerInterface_Set_7 = &Hxx2::Wrapper<Hxx2::Unresolved>::_BigIntegerInterface_Set_7;
		#else
		tbl->_BigIntegerInterface_Set_7 = &Hxx2::Wrapper<Hxx2::Unresolved>::_BigIntegerInterface_Set_7;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<void>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_BigIntegerInterface_SetRandom = &Hxx2::Wrapper<Hxx2::Unresolved>::_BigIntegerInterface_SetRandom;
		#else
		tbl->_BigIntegerInterface_SetRandom = &Hxx2::Wrapper<Hxx2::Unresolved>::_BigIntegerInterface_SetRandom;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<void>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_BigIntegerInterface_SetRandomPrime = &Hxx2::Wrapper<Hxx2::Unresolved>::_BigIntegerInterface_SetRandomPrime;
		#else
		tbl->_BigIntegerInterface_SetRandomPrime = &Hxx2::Wrapper<Hxx2::Unresolved>::_BigIntegerInterface_SetRandomPrime;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<void>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_BigIntegerInterface_Set_8 = &Hxx2::Wrapper<Hxx2::Unresolved>::_BigIntegerInterface_Set_8;
		#else
		tbl->_BigIntegerInterface_Set_8 = &Hxx2::Wrapper<Hxx2::Unresolved>::_BigIntegerInterface_Set_8;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<void>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_BigIntegerInterface_Set_9 = &Hxx2::Wrapper<Hxx2::Unresolved>::_BigIntegerInterface_Set_9;
		#else
		tbl->_BigIntegerInterface_Set_9 = &Hxx2::Wrapper<Hxx2::Unresolved>::_BigIntegerInterface_Set_9;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<void>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_BigIntegerInterface_SetHex = &Hxx2::Wrapper<Hxx2::Unresolved>::_BigIntegerInterface_SetHex;
		#else
		tbl->_BigIntegerInterface_SetHex = &Hxx2::Wrapper<Hxx2::Unresolved>::_BigIntegerInterface_SetHex;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->_BigIntegerInterface_IsEven = &Hxx2::Wrapper<Hxx2::Unresolved>::_BigIntegerInterface_IsEven;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->_BigIntegerInterface_IsOdd = &Hxx2::Wrapper<Hxx2::Unresolved>::_BigIntegerInterface_IsOdd;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->_BigIntegerInterface_IsOne = &Hxx2::Wrapper<Hxx2::Unresolved>::_BigIntegerInterface_IsOne;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->_BigIntegerInterface_IsZero = &Hxx2::Wrapper<Hxx2::Unresolved>::_BigIntegerInterface_IsZero;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->_BigIntegerInterface_IsNegative = &Hxx2::Wrapper<Hxx2::Unresolved>::_BigIntegerInterface_IsNegative;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->_BigIntegerInterface_IsPowerOfTwo = &Hxx2::Wrapper<Hxx2::Unresolved>::_BigIntegerInterface_IsPowerOfTwo;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<Bool>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_BigIntegerInterface_IsProbablyPrime = &Hxx2::Wrapper<Hxx2::Unresolved>::_BigIntegerInterface_IsProbablyPrime;
		#else
		tbl->_BigIntegerInterface_IsProbablyPrime = &Hxx2::Wrapper<Hxx2::Unresolved>::_BigIntegerInterface_IsProbablyPrime;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->_BigIntegerInterface_Sign = &Hxx2::Wrapper<Hxx2::Unresolved>::_BigIntegerInterface_Sign;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->_BigIntegerInterface_GetHighestNonSignBit = &Hxx2::Wrapper<Hxx2::Unresolved>::_BigIntegerInterface_GetHighestNonSignBit;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->_BigIntegerInterface_GetLowestSetBit = &Hxx2::Wrapper<Hxx2::Unresolved>::_BigIntegerInterface_GetLowestSetBit;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->_BigIntegerInterface_GetLowestClearedBit = &Hxx2::Wrapper<Hxx2::Unresolved>::_BigIntegerInterface_GetLowestClearedBit;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->_BigIntegerInterface_IsBitSet = &Hxx2::Wrapper<Hxx2::Unresolved>::_BigIntegerInterface_IsBitSet;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->_BigIntegerInterface_GetLowestBits8U = &Hxx2::Wrapper<Hxx2::Unresolved>::_BigIntegerInterface_GetLowestBits8U;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->_BigIntegerInterface_GetLowestBits8S = &Hxx2::Wrapper<Hxx2::Unresolved>::_BigIntegerInterface_GetLowestBits8S;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->_BigIntegerInterface_GetLowestBits16U = &Hxx2::Wrapper<Hxx2::Unresolved>::_BigIntegerInterface_GetLowestBits16U;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->_BigIntegerInterface_GetLowestBits16S = &Hxx2::Wrapper<Hxx2::Unresolved>::_BigIntegerInterface_GetLowestBits16S;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->_BigIntegerInterface_GetLowestBits32U = &Hxx2::Wrapper<Hxx2::Unresolved>::_BigIntegerInterface_GetLowestBits32U;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->_BigIntegerInterface_GetLowestBits32S = &Hxx2::Wrapper<Hxx2::Unresolved>::_BigIntegerInterface_GetLowestBits32S;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->_BigIntegerInterface_GetLowestBits64U = &Hxx2::Wrapper<Hxx2::Unresolved>::_BigIntegerInterface_GetLowestBits64U;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->_BigIntegerInterface_GetLowestBits64S = &Hxx2::Wrapper<Hxx2::Unresolved>::_BigIntegerInterface_GetLowestBits64S;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<void>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_BigIntegerInterface_GetDataCopy = &Hxx2::Wrapper<Hxx2::Unresolved>::_BigIntegerInterface_GetDataCopy;
		#else
		tbl->_BigIntegerInterface_GetDataCopy = &Hxx2::Wrapper<Hxx2::Unresolved>::_BigIntegerInterface_GetDataCopy;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<void>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_BigIntegerInterface_Add = &Hxx2::Wrapper<Hxx2::Unresolved>::_BigIntegerInterface_Add;
		#else
		tbl->_BigIntegerInterface_Add = &Hxx2::Wrapper<Hxx2::Unresolved>::_BigIntegerInterface_Add;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<void>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_BigIntegerInterface_Sub = &Hxx2::Wrapper<Hxx2::Unresolved>::_BigIntegerInterface_Sub;
		#else
		tbl->_BigIntegerInterface_Sub = &Hxx2::Wrapper<Hxx2::Unresolved>::_BigIntegerInterface_Sub;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<void>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_BigIntegerInterface_Inc = &Hxx2::Wrapper<Hxx2::Unresolved>::_BigIntegerInterface_Inc;
		#else
		tbl->_BigIntegerInterface_Inc = &Hxx2::Wrapper<Hxx2::Unresolved>::_BigIntegerInterface_Inc;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<void>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_BigIntegerInterface_Dec = &Hxx2::Wrapper<Hxx2::Unresolved>::_BigIntegerInterface_Dec;
		#else
		tbl->_BigIntegerInterface_Dec = &Hxx2::Wrapper<Hxx2::Unresolved>::_BigIntegerInterface_Dec;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<void>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_BigIntegerInterface_Mul = &Hxx2::Wrapper<Hxx2::Unresolved>::_BigIntegerInterface_Mul;
		#else
		tbl->_BigIntegerInterface_Mul = &Hxx2::Wrapper<Hxx2::Unresolved>::_BigIntegerInterface_Mul;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<void>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_BigIntegerInterface_Div = &Hxx2::Wrapper<Hxx2::Unresolved>::_BigIntegerInterface_Div;
		#else
		tbl->_BigIntegerInterface_Div = &Hxx2::Wrapper<Hxx2::Unresolved>::_BigIntegerInterface_Div;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<void>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_BigIntegerInterface_Mod = &Hxx2::Wrapper<Hxx2::Unresolved>::_BigIntegerInterface_Mod;
		#else
		tbl->_BigIntegerInterface_Mod = &Hxx2::Wrapper<Hxx2::Unresolved>::_BigIntegerInterface_Mod;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<void>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_BigIntegerInterface_DivMod = &Hxx2::Wrapper<Hxx2::Unresolved>::_BigIntegerInterface_DivMod;
		#else
		tbl->_BigIntegerInterface_DivMod = &Hxx2::Wrapper<Hxx2::Unresolved>::_BigIntegerInterface_DivMod;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<void>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_BigIntegerInterface_Pow = &Hxx2::Wrapper<Hxx2::Unresolved>::_BigIntegerInterface_Pow;
		#else
		tbl->_BigIntegerInterface_Pow = &Hxx2::Wrapper<Hxx2::Unresolved>::_BigIntegerInterface_Pow;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<void>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_BigIntegerInterface_PowMod = &Hxx2::Wrapper<Hxx2::Unresolved>::_BigIntegerInterface_PowMod;
		#else
		tbl->_BigIntegerInterface_PowMod = &Hxx2::Wrapper<Hxx2::Unresolved>::_BigIntegerInterface_PowMod;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<void>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_BigIntegerInterface_GreatestCommonDivisor = &Hxx2::Wrapper<Hxx2::Unresolved>::_BigIntegerInterface_GreatestCommonDivisor;
		#else
		tbl->_BigIntegerInterface_GreatestCommonDivisor = &Hxx2::Wrapper<Hxx2::Unresolved>::_BigIntegerInterface_GreatestCommonDivisor;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<Bool>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_BigIntegerInterface_MultiplicativeInverse = &Hxx2::Wrapper<Hxx2::Unresolved>::_BigIntegerInterface_MultiplicativeInverse;
		#else
		tbl->_BigIntegerInterface_MultiplicativeInverse = &Hxx2::Wrapper<Hxx2::Unresolved>::_BigIntegerInterface_MultiplicativeInverse;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<void>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_BigIntegerInterface_LeftShift = &Hxx2::Wrapper<Hxx2::Unresolved>::_BigIntegerInterface_LeftShift;
		#else
		tbl->_BigIntegerInterface_LeftShift = &Hxx2::Wrapper<Hxx2::Unresolved>::_BigIntegerInterface_LeftShift;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<void>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_BigIntegerInterface_RightShift = &Hxx2::Wrapper<Hxx2::Unresolved>::_BigIntegerInterface_RightShift;
		#else
		tbl->_BigIntegerInterface_RightShift = &Hxx2::Wrapper<Hxx2::Unresolved>::_BigIntegerInterface_RightShift;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<void>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_BigIntegerInterface_Negate = &Hxx2::Wrapper<Hxx2::Unresolved>::_BigIntegerInterface_Negate;
		#else
		tbl->_BigIntegerInterface_Negate = &Hxx2::Wrapper<Hxx2::Unresolved>::_BigIntegerInterface_Negate;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<void>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_BigIntegerInterface_SetBit = &Hxx2::Wrapper<Hxx2::Unresolved>::_BigIntegerInterface_SetBit;
		#else
		tbl->_BigIntegerInterface_SetBit = &Hxx2::Wrapper<Hxx2::Unresolved>::_BigIntegerInterface_SetBit;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<void>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_BigIntegerInterface_ClearBit = &Hxx2::Wrapper<Hxx2::Unresolved>::_BigIntegerInterface_ClearBit;
		#else
		tbl->_BigIntegerInterface_ClearBit = &Hxx2::Wrapper<Hxx2::Unresolved>::_BigIntegerInterface_ClearBit;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<void>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_BigIntegerInterface_ToggleBit = &Hxx2::Wrapper<Hxx2::Unresolved>::_BigIntegerInterface_ToggleBit;
		#else
		tbl->_BigIntegerInterface_ToggleBit = &Hxx2::Wrapper<Hxx2::Unresolved>::_BigIntegerInterface_ToggleBit;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<COMPARERESULT>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_BigIntegerInterface_Compare = &Hxx2::Wrapper<Hxx2::Unresolved>::_BigIntegerInterface_Compare;
		#else
		tbl->_BigIntegerInterface_Compare = &Hxx2::Wrapper<Hxx2::Unresolved>::_BigIntegerInterface_Compare;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->_BigIntegerInterface_GetHashCode = &Hxx2::Wrapper<Hxx2::Unresolved>::_BigIntegerInterface_GetHashCode;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<String>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_BigIntegerInterface_ToString = &Hxx2::Wrapper<Hxx2::Unresolved>::_BigIntegerInterface_ToString;
		#else
		tbl->_BigIntegerInterface_ToString = &Hxx2::Wrapper<Hxx2::Unresolved>::_BigIntegerInterface_ToString;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<void>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_BigIntegerInterface_DescribeIO = &Hxx2::Wrapper<Hxx2::Unresolved>::_BigIntegerInterface_DescribeIO;
		#else
		tbl->_BigIntegerInterface_DescribeIO = &Hxx2::Wrapper<Hxx2::Unresolved>::_BigIntegerInterface_DescribeIO;
		#endif
	#ifdef PRIVATE_MAXON_ASSEMBLE_UNRESOLVED
		return assembler(&_interface, (maxon::Char*) tbl, _returnTypes, SIZEOF(MTable) / SIZEOF(void*));
	#else
		return true;
	#endif
	}
	MAXON_INTERFACE_REGISTER(BigIntegerInterface, "net.maxon.interface.biginteger", nullptr);
	template <typename DUMMY> maxon::Int BigIntegerInterface::PrivateInstantiateNullValueHelper()
	{
		return 0
		| maxon::details::InstantiateNullReturnValue<COMPARERESULT>(OVERLOAD_MAX_RANK)
		| maxon::details::InstantiateNullReturnValue<String>(OVERLOAD_MAX_RANK)
		;
	}
}
#endif
static maxon::details::ForceEvaluation s_forceEval_big_integer(0
	| maxon::BigIntegerInterface::PrivateInstantiateNullValueHelper<maxon::Int>()
);
