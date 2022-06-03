#if 1
namespace maxon
{
	const maxon::Char* const BigIntegerInterface::MTable::_ids = 
		"Free@72e6e626ca6183b\0" // void Free(const BigIntegerInterface* object)
		"Alloc@a8df920f7b45f4d0\0" // BigIntegerInterface* Alloc(const maxon::SourceLocation& allocLocation)
		"Alloc@6c39196ace35be58\0" // BigIntegerInterface* Alloc(const maxon::SourceLocation& allocLocation, const BigIntegerInterface& object)
		"Zero@53da7073e03a7ba8\0" // BigIntegerInterface* Zero()
		"One@53da7073e03a7ba8\0" // BigIntegerInterface* One()
		"MinusOne@53da7073e03a7ba8\0" // BigIntegerInterface* MinusOne()
		"Set@d57df0392380510d\0" // Result<void> Set(Char c)
		"Set@5bb77b2ec8ec1cbc\0" // Result<void> Set(UChar c)
		"Set@706734b257ff9061\0" // Result<void> Set(Int16 i)
		"Set@b1a1e82c008937a2\0" // Result<void> Set(UInt16 u)
		"Set@706534abcbfa36cf\0" // Result<void> Set(Int32 i)
		"Set@b1a3e832848e849c\0" // Result<void> Set(UInt32 u)
		"Set@7060349c53ee40f4\0" // Result<void> Set(Int64 i)
		"Set@b1a8e842009a80c3\0" // Result<void> Set(UInt64 u)
		"SetRandom@27d7b5fec8144109\0" // Result<void> SetRandom(Int bitCount, SecureRandomProvider provider)
		"SetRandomPrime@b4ad3ce3e7eab91d\0" // Result<void> SetRandomPrime(Int bitCount, UInt certainty, SecureRandomProvider provider)
		"Set@aeb15b29395f9f60\0" // Result<void> Set(const Block<const Byte>& mem, Bool littleEndian)
		"Set@d85d74e087a2f051\0" // Result<void> Set(const String& str)
		"SetHex@d85d74e087a2f051\0" // Result<void> SetHex(const String& str)
		"IsEven@12e73654e6d65520\0" // Bool IsEven() const
		"IsOdd@12e73654e6d65520\0" // Bool IsOdd() const
		"IsOne@12e73654e6d65520\0" // Bool IsOne() const
		"IsZero@12e73654e6d65520\0" // Bool IsZero() const
		"IsNegative@12e73654e6d65520\0" // Bool IsNegative() const
		"IsPowerOfTwo@12e73654e6d65520\0" // Bool IsPowerOfTwo() const
		"IsProbablyPrime@abb3e344f8386833\0" // Result<Bool> IsProbablyPrime(UInt certainty) const
		"Sign@7d0e6f3d29c239e7\0" // Int Sign() const
		"GetHighestNonSignBit@7d0e6f3d29c239e7\0" // Int GetHighestNonSignBit() const
		"GetLowestSetBit@7d0e6f3d29c239e7\0" // Int GetLowestSetBit() const
		"GetLowestClearedBit@7d0e6f3d29c239e7\0" // Int GetLowestClearedBit() const
		"IsBitSet@cfb3f584867c4a1b\0" // Bool IsBitSet(Int bit) const
		"GetLowestBits8U@826b0a995fdd4325\0" // UChar GetLowestBits8U() const
		"GetLowestBits8S@410976fdadfbaf00\0" // Char GetLowestBits8S() const
		"GetLowestBits16U@6f3d9f642246af3b\0" // UInt16 GetLowestBits16U() const
		"GetLowestBits16S@1bb4d64c6cf881c4\0" // Int16 GetLowestBits16S() const
		"GetLowestBits32U@34c6756cf1200a25\0" // UInt32 GetLowestBits32U() const
		"GetLowestBits32S@30a3c592bf87830a\0" // Int32 GetLowestBits32S() const
		"GetLowestBits64U@55e89195f712e11e\0" // UInt64 GetLowestBits64U() const
		"GetLowestBits64S@22a5c7f065ce5f0d\0" // Int64 GetLowestBits64S() const
		"GetDataCopy@fc9fc6657218f812\0" // Result<void> GetDataCopy(Bool littleEndian, BaseArray<UChar>& data) const
		"Add@3d9683ec07247467\0" // Result<void> Add(const BigIntegerInterface* b)
		"Sub@3d9683ec07247467\0" // Result<void> Sub(const BigIntegerInterface* b)
		"Inc@3008090429c5a175\0" // Result<void> Inc()
		"Dec@3008090429c5a175\0" // Result<void> Dec()
		"Mul@3d9683ec07247467\0" // Result<void> Mul(const BigIntegerInterface* b)
		"Div@3d9683ec07247467\0" // Result<void> Div(const BigIntegerInterface* b)
		"Mod@3d9683ec07247467\0" // Result<void> Mod(const BigIntegerInterface* b)
		"DivMod@b89bd48efc527959\0" // Result<void> DivMod(const BigIntegerInterface* b, BigInteger& r)
		"Pow@3d9683ec07247467\0" // Result<void> Pow(const BigIntegerInterface* b)
		"PowMod@e9095697366d02e3\0" // Result<void> PowMod(const BigIntegerInterface* b, const BigIntegerInterface* mod)
		"GreatestCommonDivisor@3d9683ec07247467\0" // Result<void> GreatestCommonDivisor(const BigIntegerInterface* b)
		"MultiplicativeInverse@e78c121a176c4045\0" // Result<Bool> MultiplicativeInverse(const BigIntegerInterface* m)
		"LeftShift@c49f7df11faba36e\0" // Result<void> LeftShift(Int s)
		"RightShift@c49f7df11faba36e\0" // Result<void> RightShift(Int s)
		"Negate@3008090429c5a175\0" // Result<void> Negate()
		"SetBit@c49f7df11faba36e\0" // Result<void> SetBit(Int bit)
		"ClearBit@c49f7df11faba36e\0" // Result<void> ClearBit(Int bit)
		"ToggleBit@c49f7df11faba36e\0" // Result<void> ToggleBit(Int bit)
		"Compare@cffd5210bbf889fe\0" // COMPARERESULT Compare(const BigIntegerInterface* arg2) const
		"GetHashCode@b22918402154097b\0" // HashInt GetHashCode() const
		"ToString@a73a45c584c879d4\0" // String ToString(const FormatStatement* formatStatement) const
		"DescribeIO@fe3f1bd5a495cc32\0" // Result<void> DescribeIO(const DataSerializeInterface& stream)
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
		HashInt GetHashCode() const { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ((const BigIntegerInterface*) this)->GetHashCode(); return maxon::PrivateIncompleteNullReturnValue<HashInt>(maxon::NULL_RETURN_REASON::UNRESOLVED, OVERLOAD_MAX_RANK);}
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
		maxon::details::NullReturnType<HashInt>::value,
		maxon::details::NullReturnType<String>::value,
		maxon::details::NullReturnType<Result<void>>::value,
		maxon::NULL_RETURN_TYPE::OTHER
	};
#endif
	maxon::Bool BigIntegerInterface::MTable::InitUnresolved(maxon::NonvirtualInterfaceReference::UnresolvedAssembler assembler, MTable* tbl)
	{
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->BigIntegerInterface_Free = &Hxx2::Wrapper<Hxx2::Unresolved>::BigIntegerInterface_Free;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->BigIntegerInterface_Alloc = &Hxx2::Wrapper<Hxx2::Unresolved>::BigIntegerInterface_Alloc;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->BigIntegerInterface_Alloc_1 = &Hxx2::Wrapper<Hxx2::Unresolved>::BigIntegerInterface_Alloc_1;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->BigIntegerInterface_Zero = &Hxx2::Wrapper<Hxx2::Unresolved>::BigIntegerInterface_Zero;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->BigIntegerInterface_One = &Hxx2::Wrapper<Hxx2::Unresolved>::BigIntegerInterface_One;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->BigIntegerInterface_MinusOne = &Hxx2::Wrapper<Hxx2::Unresolved>::BigIntegerInterface_MinusOne;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<void>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->BigIntegerInterface_Set = &Hxx2::Wrapper<Hxx2::Unresolved>::BigIntegerInterface_Set;
		#else
		tbl->BigIntegerInterface_Set = &Hxx2::Wrapper<Hxx2::Unresolved>::BigIntegerInterface_Set;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<void>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->BigIntegerInterface_Set_1 = &Hxx2::Wrapper<Hxx2::Unresolved>::BigIntegerInterface_Set_1;
		#else
		tbl->BigIntegerInterface_Set_1 = &Hxx2::Wrapper<Hxx2::Unresolved>::BigIntegerInterface_Set_1;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<void>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->BigIntegerInterface_Set_2 = &Hxx2::Wrapper<Hxx2::Unresolved>::BigIntegerInterface_Set_2;
		#else
		tbl->BigIntegerInterface_Set_2 = &Hxx2::Wrapper<Hxx2::Unresolved>::BigIntegerInterface_Set_2;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<void>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->BigIntegerInterface_Set_3 = &Hxx2::Wrapper<Hxx2::Unresolved>::BigIntegerInterface_Set_3;
		#else
		tbl->BigIntegerInterface_Set_3 = &Hxx2::Wrapper<Hxx2::Unresolved>::BigIntegerInterface_Set_3;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<void>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->BigIntegerInterface_Set_4 = &Hxx2::Wrapper<Hxx2::Unresolved>::BigIntegerInterface_Set_4;
		#else
		tbl->BigIntegerInterface_Set_4 = &Hxx2::Wrapper<Hxx2::Unresolved>::BigIntegerInterface_Set_4;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<void>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->BigIntegerInterface_Set_5 = &Hxx2::Wrapper<Hxx2::Unresolved>::BigIntegerInterface_Set_5;
		#else
		tbl->BigIntegerInterface_Set_5 = &Hxx2::Wrapper<Hxx2::Unresolved>::BigIntegerInterface_Set_5;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<void>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->BigIntegerInterface_Set_6 = &Hxx2::Wrapper<Hxx2::Unresolved>::BigIntegerInterface_Set_6;
		#else
		tbl->BigIntegerInterface_Set_6 = &Hxx2::Wrapper<Hxx2::Unresolved>::BigIntegerInterface_Set_6;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<void>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->BigIntegerInterface_Set_7 = &Hxx2::Wrapper<Hxx2::Unresolved>::BigIntegerInterface_Set_7;
		#else
		tbl->BigIntegerInterface_Set_7 = &Hxx2::Wrapper<Hxx2::Unresolved>::BigIntegerInterface_Set_7;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<void>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->BigIntegerInterface_SetRandom = &Hxx2::Wrapper<Hxx2::Unresolved>::BigIntegerInterface_SetRandom;
		#else
		tbl->BigIntegerInterface_SetRandom = &Hxx2::Wrapper<Hxx2::Unresolved>::BigIntegerInterface_SetRandom;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<void>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->BigIntegerInterface_SetRandomPrime = &Hxx2::Wrapper<Hxx2::Unresolved>::BigIntegerInterface_SetRandomPrime;
		#else
		tbl->BigIntegerInterface_SetRandomPrime = &Hxx2::Wrapper<Hxx2::Unresolved>::BigIntegerInterface_SetRandomPrime;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<void>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->BigIntegerInterface_Set_8 = &Hxx2::Wrapper<Hxx2::Unresolved>::BigIntegerInterface_Set_8;
		#else
		tbl->BigIntegerInterface_Set_8 = &Hxx2::Wrapper<Hxx2::Unresolved>::BigIntegerInterface_Set_8;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<void>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->BigIntegerInterface_Set_9 = &Hxx2::Wrapper<Hxx2::Unresolved>::BigIntegerInterface_Set_9;
		#else
		tbl->BigIntegerInterface_Set_9 = &Hxx2::Wrapper<Hxx2::Unresolved>::BigIntegerInterface_Set_9;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<void>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->BigIntegerInterface_SetHex = &Hxx2::Wrapper<Hxx2::Unresolved>::BigIntegerInterface_SetHex;
		#else
		tbl->BigIntegerInterface_SetHex = &Hxx2::Wrapper<Hxx2::Unresolved>::BigIntegerInterface_SetHex;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->BigIntegerInterface_IsEven = &Hxx2::Wrapper<Hxx2::Unresolved>::BigIntegerInterface_IsEven;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->BigIntegerInterface_IsOdd = &Hxx2::Wrapper<Hxx2::Unresolved>::BigIntegerInterface_IsOdd;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->BigIntegerInterface_IsOne = &Hxx2::Wrapper<Hxx2::Unresolved>::BigIntegerInterface_IsOne;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->BigIntegerInterface_IsZero = &Hxx2::Wrapper<Hxx2::Unresolved>::BigIntegerInterface_IsZero;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->BigIntegerInterface_IsNegative = &Hxx2::Wrapper<Hxx2::Unresolved>::BigIntegerInterface_IsNegative;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->BigIntegerInterface_IsPowerOfTwo = &Hxx2::Wrapper<Hxx2::Unresolved>::BigIntegerInterface_IsPowerOfTwo;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<Bool>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->BigIntegerInterface_IsProbablyPrime = &Hxx2::Wrapper<Hxx2::Unresolved>::BigIntegerInterface_IsProbablyPrime;
		#else
		tbl->BigIntegerInterface_IsProbablyPrime = &Hxx2::Wrapper<Hxx2::Unresolved>::BigIntegerInterface_IsProbablyPrime;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->BigIntegerInterface_Sign = &Hxx2::Wrapper<Hxx2::Unresolved>::BigIntegerInterface_Sign;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->BigIntegerInterface_GetHighestNonSignBit = &Hxx2::Wrapper<Hxx2::Unresolved>::BigIntegerInterface_GetHighestNonSignBit;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->BigIntegerInterface_GetLowestSetBit = &Hxx2::Wrapper<Hxx2::Unresolved>::BigIntegerInterface_GetLowestSetBit;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->BigIntegerInterface_GetLowestClearedBit = &Hxx2::Wrapper<Hxx2::Unresolved>::BigIntegerInterface_GetLowestClearedBit;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->BigIntegerInterface_IsBitSet = &Hxx2::Wrapper<Hxx2::Unresolved>::BigIntegerInterface_IsBitSet;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->BigIntegerInterface_GetLowestBits8U = &Hxx2::Wrapper<Hxx2::Unresolved>::BigIntegerInterface_GetLowestBits8U;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->BigIntegerInterface_GetLowestBits8S = &Hxx2::Wrapper<Hxx2::Unresolved>::BigIntegerInterface_GetLowestBits8S;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->BigIntegerInterface_GetLowestBits16U = &Hxx2::Wrapper<Hxx2::Unresolved>::BigIntegerInterface_GetLowestBits16U;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->BigIntegerInterface_GetLowestBits16S = &Hxx2::Wrapper<Hxx2::Unresolved>::BigIntegerInterface_GetLowestBits16S;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->BigIntegerInterface_GetLowestBits32U = &Hxx2::Wrapper<Hxx2::Unresolved>::BigIntegerInterface_GetLowestBits32U;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->BigIntegerInterface_GetLowestBits32S = &Hxx2::Wrapper<Hxx2::Unresolved>::BigIntegerInterface_GetLowestBits32S;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->BigIntegerInterface_GetLowestBits64U = &Hxx2::Wrapper<Hxx2::Unresolved>::BigIntegerInterface_GetLowestBits64U;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->BigIntegerInterface_GetLowestBits64S = &Hxx2::Wrapper<Hxx2::Unresolved>::BigIntegerInterface_GetLowestBits64S;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<void>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->BigIntegerInterface_GetDataCopy = &Hxx2::Wrapper<Hxx2::Unresolved>::BigIntegerInterface_GetDataCopy;
		#else
		tbl->BigIntegerInterface_GetDataCopy = &Hxx2::Wrapper<Hxx2::Unresolved>::BigIntegerInterface_GetDataCopy;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<void>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->BigIntegerInterface_Add = &Hxx2::Wrapper<Hxx2::Unresolved>::BigIntegerInterface_Add;
		#else
		tbl->BigIntegerInterface_Add = &Hxx2::Wrapper<Hxx2::Unresolved>::BigIntegerInterface_Add;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<void>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->BigIntegerInterface_Sub = &Hxx2::Wrapper<Hxx2::Unresolved>::BigIntegerInterface_Sub;
		#else
		tbl->BigIntegerInterface_Sub = &Hxx2::Wrapper<Hxx2::Unresolved>::BigIntegerInterface_Sub;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<void>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->BigIntegerInterface_Inc = &Hxx2::Wrapper<Hxx2::Unresolved>::BigIntegerInterface_Inc;
		#else
		tbl->BigIntegerInterface_Inc = &Hxx2::Wrapper<Hxx2::Unresolved>::BigIntegerInterface_Inc;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<void>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->BigIntegerInterface_Dec = &Hxx2::Wrapper<Hxx2::Unresolved>::BigIntegerInterface_Dec;
		#else
		tbl->BigIntegerInterface_Dec = &Hxx2::Wrapper<Hxx2::Unresolved>::BigIntegerInterface_Dec;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<void>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->BigIntegerInterface_Mul = &Hxx2::Wrapper<Hxx2::Unresolved>::BigIntegerInterface_Mul;
		#else
		tbl->BigIntegerInterface_Mul = &Hxx2::Wrapper<Hxx2::Unresolved>::BigIntegerInterface_Mul;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<void>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->BigIntegerInterface_Div = &Hxx2::Wrapper<Hxx2::Unresolved>::BigIntegerInterface_Div;
		#else
		tbl->BigIntegerInterface_Div = &Hxx2::Wrapper<Hxx2::Unresolved>::BigIntegerInterface_Div;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<void>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->BigIntegerInterface_Mod = &Hxx2::Wrapper<Hxx2::Unresolved>::BigIntegerInterface_Mod;
		#else
		tbl->BigIntegerInterface_Mod = &Hxx2::Wrapper<Hxx2::Unresolved>::BigIntegerInterface_Mod;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<void>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->BigIntegerInterface_DivMod = &Hxx2::Wrapper<Hxx2::Unresolved>::BigIntegerInterface_DivMod;
		#else
		tbl->BigIntegerInterface_DivMod = &Hxx2::Wrapper<Hxx2::Unresolved>::BigIntegerInterface_DivMod;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<void>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->BigIntegerInterface_Pow = &Hxx2::Wrapper<Hxx2::Unresolved>::BigIntegerInterface_Pow;
		#else
		tbl->BigIntegerInterface_Pow = &Hxx2::Wrapper<Hxx2::Unresolved>::BigIntegerInterface_Pow;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<void>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->BigIntegerInterface_PowMod = &Hxx2::Wrapper<Hxx2::Unresolved>::BigIntegerInterface_PowMod;
		#else
		tbl->BigIntegerInterface_PowMod = &Hxx2::Wrapper<Hxx2::Unresolved>::BigIntegerInterface_PowMod;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<void>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->BigIntegerInterface_GreatestCommonDivisor = &Hxx2::Wrapper<Hxx2::Unresolved>::BigIntegerInterface_GreatestCommonDivisor;
		#else
		tbl->BigIntegerInterface_GreatestCommonDivisor = &Hxx2::Wrapper<Hxx2::Unresolved>::BigIntegerInterface_GreatestCommonDivisor;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<Bool>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->BigIntegerInterface_MultiplicativeInverse = &Hxx2::Wrapper<Hxx2::Unresolved>::BigIntegerInterface_MultiplicativeInverse;
		#else
		tbl->BigIntegerInterface_MultiplicativeInverse = &Hxx2::Wrapper<Hxx2::Unresolved>::BigIntegerInterface_MultiplicativeInverse;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<void>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->BigIntegerInterface_LeftShift = &Hxx2::Wrapper<Hxx2::Unresolved>::BigIntegerInterface_LeftShift;
		#else
		tbl->BigIntegerInterface_LeftShift = &Hxx2::Wrapper<Hxx2::Unresolved>::BigIntegerInterface_LeftShift;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<void>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->BigIntegerInterface_RightShift = &Hxx2::Wrapper<Hxx2::Unresolved>::BigIntegerInterface_RightShift;
		#else
		tbl->BigIntegerInterface_RightShift = &Hxx2::Wrapper<Hxx2::Unresolved>::BigIntegerInterface_RightShift;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<void>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->BigIntegerInterface_Negate = &Hxx2::Wrapper<Hxx2::Unresolved>::BigIntegerInterface_Negate;
		#else
		tbl->BigIntegerInterface_Negate = &Hxx2::Wrapper<Hxx2::Unresolved>::BigIntegerInterface_Negate;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<void>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->BigIntegerInterface_SetBit = &Hxx2::Wrapper<Hxx2::Unresolved>::BigIntegerInterface_SetBit;
		#else
		tbl->BigIntegerInterface_SetBit = &Hxx2::Wrapper<Hxx2::Unresolved>::BigIntegerInterface_SetBit;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<void>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->BigIntegerInterface_ClearBit = &Hxx2::Wrapper<Hxx2::Unresolved>::BigIntegerInterface_ClearBit;
		#else
		tbl->BigIntegerInterface_ClearBit = &Hxx2::Wrapper<Hxx2::Unresolved>::BigIntegerInterface_ClearBit;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<void>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->BigIntegerInterface_ToggleBit = &Hxx2::Wrapper<Hxx2::Unresolved>::BigIntegerInterface_ToggleBit;
		#else
		tbl->BigIntegerInterface_ToggleBit = &Hxx2::Wrapper<Hxx2::Unresolved>::BigIntegerInterface_ToggleBit;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<COMPARERESULT>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->BigIntegerInterface_Compare = &Hxx2::Wrapper<Hxx2::Unresolved>::BigIntegerInterface_Compare;
		#else
		tbl->BigIntegerInterface_Compare = &Hxx2::Wrapper<Hxx2::Unresolved>::BigIntegerInterface_Compare;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<HashInt>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->BigIntegerInterface_GetHashCode = &Hxx2::Wrapper<Hxx2::Unresolved>::BigIntegerInterface_GetHashCode;
		#else
		tbl->BigIntegerInterface_GetHashCode = &Hxx2::Wrapper<Hxx2::Unresolved>::BigIntegerInterface_GetHashCode;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<String>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->BigIntegerInterface_ToString = &Hxx2::Wrapper<Hxx2::Unresolved>::BigIntegerInterface_ToString;
		#else
		tbl->BigIntegerInterface_ToString = &Hxx2::Wrapper<Hxx2::Unresolved>::BigIntegerInterface_ToString;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<void>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->BigIntegerInterface_DescribeIO = &Hxx2::Wrapper<Hxx2::Unresolved>::BigIntegerInterface_DescribeIO;
		#else
		tbl->BigIntegerInterface_DescribeIO = &Hxx2::Wrapper<Hxx2::Unresolved>::BigIntegerInterface_DescribeIO;
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
		| maxon::details::InstantiateNullReturnValue<HashInt>(OVERLOAD_MAX_RANK)
		| maxon::details::InstantiateNullReturnValue<String>(OVERLOAD_MAX_RANK)
		;
	}
}
#endif
static maxon::details::ForceEvaluation s_forceEval_big_integer(0
	| maxon::BigIntegerInterface::PrivateInstantiateNullValueHelper<maxon::Int>()
);
