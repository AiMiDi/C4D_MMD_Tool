#if 1
namespace maxon
{
	namespace enum46 { enum class STRINGCONVERSION
	{
		NONE									= 0,
		ALLOW_MORE_CHARACTERS	= (1 << 0)	///< if the specified string is longer than the converted characters and you specify this flag no error will be returned
	} ; }
	maxon::String PrivateToString_STRINGCONVERSION46(std::underlying_type<enum46::STRINGCONVERSION>::type x, const maxon::FormatStatement* fmt)
	{
		const maxon::UInt64 values[] = {(maxon::UInt64) enum46::STRINGCONVERSION::NONE, (maxon::UInt64) enum46::STRINGCONVERSION::ALLOW_MORE_CHARACTERS};
		return maxon::StringInterface::PrivateEnumToString((maxon::UInt64) x, "STRINGCONVERSION", SIZEOF(x), true, values, "NONE\0ALLOW_MORE_CHARACTERS\0", fmt);
	}
	namespace enum58 { enum class STRINGCOMPARISON
	{
		MEMORY									= 0,	///< default - fast comparison, memory block is directly compared. This does not result in a correct alphabetical order.
		UNICODE_LETTERS					= 1,	///< strings are compared using correct unicode decomposition
		UNICODE_NUMBERS					= 2,	///< strings are compared using correct unicode decomposition. Numbers in strings are identified, so "2" is smaller than "10"
		CASEINSENSITIVE					= 3,	///< strings are compared case-insensitive using correct unicode decomposition
		CASEINSENSITIVE_NUMBERS	= 4 	///< strings are compared case-insensitive using correct unicode decomposition. Numbers in strings are identified, so "2" is smaller than "10"
	} ; }
	maxon::String PrivateToString_STRINGCOMPARISON58(std::underlying_type<enum58::STRINGCOMPARISON>::type x, const maxon::FormatStatement* fmt)
	{
		const maxon::UInt64 values[] = {(maxon::UInt64) enum58::STRINGCOMPARISON::MEMORY, (maxon::UInt64) enum58::STRINGCOMPARISON::UNICODE_LETTERS, (maxon::UInt64) enum58::STRINGCOMPARISON::UNICODE_NUMBERS, (maxon::UInt64) enum58::STRINGCOMPARISON::CASEINSENSITIVE, (maxon::UInt64) enum58::STRINGCOMPARISON::CASEINSENSITIVE_NUMBERS};
		return maxon::StringInterface::PrivateEnumToString((maxon::UInt64) x, "STRINGCOMPARISON", SIZEOF(x), false, values, "MEMORY\0UNICODE_LETTERS\0UNICODE_NUMBERS\0CASEINSENSITIVE\0CASEINSENSITIVE_NUMBERS\0", fmt);
	}
	const maxon::Char* const StringInterface::MTable::_ids = 
		"Free@6b89c862671671d5\0" // void Free(const StringInterface* object)
		"GetLength@4386c86\0" // Int GetLength() const
		"Init@6843523afaef7f67\0" // Result<void> Init(Int count, Utf32Char fillChar)
		"Shrink@a54f4799cbe1a498\0" // Result<void> Shrink()
		"Append@ea775bd82f5116d7\0" // Result<void> Append(const StringInterface* str)
		"Append@b4033cadc2b31126\0" // Result<void> Append(const Utf32Char* str, Int len)
		"FindIndex@7b27f87b2f4552c7\0" // Int FindIndex(const StringInterface* str, StringPosition start) const
		"FindLastIndex@7b27f87b2f4552c7\0" // Int FindLastIndex(const StringInterface* str, StringPosition start) const
		"FindIndex@5b7a791ab47dcc3c\0" // Int FindIndex(Utf32Char ch, StringPosition start) const
		"FindLastIndex@5b7a791ab47dcc3c\0" // Int FindLastIndex(Utf32Char ch, StringPosition start) const
		"FindUpperIndex@7b27f87b2f4552c7\0" // Int FindUpperIndex(const StringInterface* str, StringPosition start) const
		"FindLastUpperIndex@7b27f87b2f4552c7\0" // Int FindLastUpperIndex(const StringInterface* str, StringPosition start) const
		"Erase@d2fb2ee68a77afc4\0" // Result<void> Erase(StringPosition position, StringCount count)
		"Insert@65a2a7002328fe9f\0" // Result<void> Insert(StringPosition position, const StringInterface* str, StringPosition strStart, StringCount strCount)
		"Insert@2760f7775d8f1882\0" // Result<void> Insert(StringPosition position, Utf32Char ch)
		"GetPart@aeb7a20fe28680ad\0" // INTERFACETYPE* GetPart(StringPosition start, StringCount count) const
		"ToUpper@bbdf675ff799dd19\0" // INTERFACETYPE* ToUpper() const
		"ToLower@bbdf675ff799dd19\0" // INTERFACETYPE* ToLower() const
		"ComparePart@bee2cb8967d47228\0" // COMPARERESULT ComparePart(const StringInterface* str, STRINGCOMPARISON mode, StringPosition position, StringCount count) const
		"GetHashCode@95445951\0" // UInt GetHashCode() const
		"SetChar@ee0d63d195187c50\0" // void SetChar(Int pos, Utf32Char ch)
		"GetChar@9bcb26f753eabfd2\0" // CHARTYPE GetChar(Int pos) const
		"GetUtf32@e029f3e59e414238\0" // Result<void> GetUtf32(Utf32CharBuffer& stringData) const
		"TrimLeft@a54f4799cbe1a498\0" // Result<void> TrimLeft()
		"TrimRight@a54f4799cbe1a498\0" // Result<void> TrimRight()
		"Split@671077607e84c5e9\0" // Result<void> Split(const String& splitSymbol, Bool trim, const ValueReceiver<const String&>& parts) const
		"Replace@1ec79617ed5795f7\0" // Result<Int> Replace(Utf32Char find, Utf32Char replace)
		"Replace@223fc49103ee996f\0" // Result<Int> Replace(const String& find, const String& replace)
		"Replace@3dc0af7818e7d833\0" // Result<Int> Replace(Utf32Char find, const String& replace)
		"Alloc@1751981016543732\0" // StringInterface* Alloc(const maxon::SourceLocation& allocLocation)
		"Alloc@3c3d07742898e9ad\0" // StringInterface* Alloc(const maxon::SourceLocation& allocLocation, const StringInterface& object)
		"GetCStringBlock@24f69868e8f09c59\0" // Result<Int> GetCStringBlock(const Block<Char>& buffer, const StringEncodingRef& stringEncoding) const
		"GetCStringAppendArray@63cd211d0c0d47e6\0" // Result<void> GetCStringAppendArray(const NonConstArray<Char>& array, const StringEncodingRef& stringEncoding) const
		"GetCString@401a7de2072eb5cc\0" // Result<BaseArray<Char>> GetCString(const StringEncodingRef& stringEncoding) const
		"SetCString@5c5e8978bfe2a356\0" // Result<void> SetCString(const Char* buffer, Int count, const StringDecodingRef& stringDecoding)
		"GetSystemEncoding@5c8c0bb74ac68b80\0" // Result<SysCharArray> GetSystemEncoding() const
		"SetSystemEncoding@151f188817d6b9bf\0" // Result<void> SetSystemEncoding(const SysChar* buffer, Int count)
		"SetUtf32@b4033cadc2b31126\0" // Result<void> SetUtf32(const Utf32Char* buffer, Int count)
		"GetUtf16@662a366f9491c8fe\0" // Result<void> GetUtf16(Utf16CharBuffer& stringData) const
		"SetUtf16@b3fdc9f86a0f7020\0" // Result<void> SetUtf16(const Utf16Char* buffer, Int count)
		"GetAndCacheConstString@0e1a463d73dbc150\0" // const String& GetAndCacheConstString(const wchar_t* chr, Int len)
		"GetAndCacheConstString@14bc444251b198d1\0" // const String& GetAndCacheConstString(const Char* chr, Int len, Int isUtf8)
		"PrivateEnumToString@755fa2dfc6de58ba\0" // String PrivateEnumToString(UInt64 value, const Char* enumName, Int size, Bool flags, const UInt64* enumValues, const Char* enumValueNames, const FormatStatement* formatStatement)
		"GetVariableInternalData@420755e4e4cdd6b5\0" // StridedBlock<const Generic> GetVariableInternalData() const
		"GetCharacterWidth@4386c86\0" // Int GetCharacterWidth() const
	"";
	MAXON_WARNING_PUSH
	MAXON_WARNING_DISABLE_DEPRECATED
	class StringInterface::Hxx2::Unresolved : public StringInterface
	{
	public:
		static const Unresolved* Get(const StringInterface* o) { return (const Unresolved*) o; }
		static Unresolved* Get(StringInterface* o) { return (Unresolved*) o; }
		static void Free(const StringInterface* object) { if (object && maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return StringInterface::Free(object); return maxon::PrivateLogNullptrError();}
		Int GetLength() const { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ((const StringInterface*) this)->GetLength(); return 0;}
		Result<void> Init(Int count, Utf32Char fillChar) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return ((StringInterface*) this)->Init(count, fillChar); return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::UNRESOLVED);}
		Result<void> Shrink() { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return ((StringInterface*) this)->Shrink(); return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::UNRESOLVED);}
		Result<void> Append(const StringInterface* str) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return ((StringInterface*) this)->Append(str); return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::UNRESOLVED);}
		Result<void> Append(const Utf32Char* str, Int len) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return ((StringInterface*) this)->Append(str, len); return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::UNRESOLVED);}
		Int FindIndex(const StringInterface* str, StringPosition start) const { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ((const StringInterface*) this)->FindIndex(str, std::forward<StringPosition>(start)); return InvalidArrayIndex;}
		Int FindLastIndex(const StringInterface* str, StringPosition start) const { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ((const StringInterface*) this)->FindLastIndex(str, std::forward<StringPosition>(start)); return InvalidArrayIndex;}
		Int FindIndex(Utf32Char ch, StringPosition start) const { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ((const StringInterface*) this)->FindIndex(ch, std::forward<StringPosition>(start)); return InvalidArrayIndex;}
		Int FindLastIndex(Utf32Char ch, StringPosition start) const { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ((const StringInterface*) this)->FindLastIndex(ch, std::forward<StringPosition>(start)); return InvalidArrayIndex;}
		Int FindUpperIndex(const StringInterface* str, StringPosition start) const { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ((const StringInterface*) this)->FindUpperIndex(str, std::forward<StringPosition>(start)); return InvalidArrayIndex;}
		Int FindLastUpperIndex(const StringInterface* str, StringPosition start) const { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ((const StringInterface*) this)->FindLastUpperIndex(str, std::forward<StringPosition>(start)); return InvalidArrayIndex;}
		Result<void> Erase(StringPosition position, StringCount count) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return ((StringInterface*) this)->Erase(std::forward<StringPosition>(position), std::forward<StringCount>(count)); return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::UNRESOLVED);}
		Result<void> Insert(StringPosition position, const StringInterface* str, StringPosition strStart, StringCount strCount) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return ((StringInterface*) this)->Insert(std::forward<StringPosition>(position), str, std::forward<StringPosition>(strStart), std::forward<StringCount>(strCount)); return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::UNRESOLVED);}
		Result<void> Insert(StringPosition position, Utf32Char ch) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return ((StringInterface*) this)->Insert(std::forward<StringPosition>(position), ch); return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::UNRESOLVED);}
		StringInterface* GetPart(StringPosition start, StringCount count) const { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ((const StringInterface*) this)->GetPart(std::forward<StringPosition>(start), std::forward<StringCount>(count)); return nullptr;}
		StringInterface* ToUpper() const { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ((const StringInterface*) this)->ToUpper(); return nullptr;}
		StringInterface* ToLower() const { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ((const StringInterface*) this)->ToLower(); return nullptr;}
		COMPARERESULT ComparePart(const StringInterface* str, STRINGCOMPARISON mode, StringPosition position, StringCount count) const { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ((const StringInterface*) this)->ComparePart(str, mode, std::forward<StringPosition>(position), std::forward<StringCount>(count)); return maxon::PrivateIncompleteNullReturnValue<COMPARERESULT>(maxon::NULL_RETURN_REASON::UNRESOLVED, OVERLOAD_MAX_RANK);}
		UInt GetHashCode() const { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ((const StringInterface*) this)->GetHashCode(); return 0;}
		void SetChar(Int pos, Utf32Char ch) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ((StringInterface*) this)->SetChar(pos, ch); return maxon::PrivateLogNullptrError();}
		Utf32Char GetChar(Int pos) const { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ((const StringInterface*) this)->GetChar(pos); return 0;}
		Result<void> GetUtf32(Utf32CharBuffer& stringData) const { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return ((const StringInterface*) this)->GetUtf32(stringData); return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::UNRESOLVED);}
		Result<void> TrimLeft() { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return ((StringInterface*) this)->TrimLeft(); return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::UNRESOLVED);}
		Result<void> TrimRight() { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return ((StringInterface*) this)->TrimRight(); return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::UNRESOLVED);}
		Result<void> Split(const String& splitSymbol, Bool trim, const ValueReceiver<const String&>& parts) const { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return ((const StringInterface*) this)->Split(splitSymbol, trim, parts); return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::UNRESOLVED);}
		Result<Int> Replace(Utf32Char find, Utf32Char replace) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return ((StringInterface*) this)->Replace(find, replace); return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::UNRESOLVED);}
		Result<Int> Replace(const String& find, const String& replace) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return ((StringInterface*) this)->Replace(find, replace); return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::UNRESOLVED);}
		Result<Int> Replace(Utf32Char find, const String& replace) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return ((StringInterface*) this)->Replace(find, replace); return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::UNRESOLVED);}
		static StringInterface* Alloc(const maxon::SourceLocation& allocLocation) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return StringInterface::Alloc(allocLocation); return nullptr;}
		static StringInterface* Alloc(const maxon::SourceLocation& allocLocation, const StringInterface& object) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return StringInterface::Alloc(allocLocation, object); return nullptr;}
		Result<Int> GetCStringBlock(const Block<Char>& buffer, const StringEncodingRef& stringEncoding) const { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return ((const StringInterface*) this)->GetCStringBlock(buffer, stringEncoding); return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::UNRESOLVED);}
		Result<void> GetCStringAppendArray(const NonConstArray<Char>& array, const StringEncodingRef& stringEncoding) const { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return ((const StringInterface*) this)->GetCStringAppendArray(array, stringEncoding); return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::UNRESOLVED);}
		Result<BaseArray<Char>> GetCString(const StringEncodingRef& stringEncoding) const { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return ((const StringInterface*) this)->GetCString(stringEncoding); return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::UNRESOLVED);}
		Result<void> SetCString(const Char* buffer, Int count, const StringDecodingRef& stringDecoding) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return ((StringInterface*) this)->SetCString(buffer, count, stringDecoding); return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::UNRESOLVED);}
		Result<SysCharArray> GetSystemEncoding() const { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return ((const StringInterface*) this)->GetSystemEncoding(); return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::UNRESOLVED);}
		Result<void> SetSystemEncoding(const SysChar* buffer, Int count) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return ((StringInterface*) this)->SetSystemEncoding(buffer, count); return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::UNRESOLVED);}
		Result<void> SetUtf32(const Utf32Char* buffer, Int count) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return ((StringInterface*) this)->SetUtf32(buffer, count); return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::UNRESOLVED);}
		Result<void> GetUtf16(Utf16CharBuffer& stringData) const { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return ((const StringInterface*) this)->GetUtf16(stringData); return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::UNRESOLVED);}
		Result<void> SetUtf16(const Utf16Char* buffer, Int count) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return ((StringInterface*) this)->SetUtf16(buffer, count); return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::UNRESOLVED);}
		static const String& GetAndCacheConstString(const wchar_t* chr, Int len) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return StringInterface::GetAndCacheConstString(chr, len); return maxon::PrivateIncompleteNullReturnValue<const String&>(maxon::NULL_RETURN_REASON::UNRESOLVED, OVERLOAD_MAX_RANK);}
		static const String& GetAndCacheConstString(const Char* chr, Int len, Int isUtf8) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return StringInterface::GetAndCacheConstString(chr, len, isUtf8); return maxon::PrivateIncompleteNullReturnValue<const String&>(maxon::NULL_RETURN_REASON::UNRESOLVED, OVERLOAD_MAX_RANK);}
		static String PrivateEnumToString(UInt64 value, const Char* enumName, Int size, Bool flags, const UInt64* enumValues, const Char* enumValueNames, const FormatStatement* formatStatement) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return StringInterface::PrivateEnumToString(value, enumName, size, flags, enumValues, enumValueNames, formatStatement); return maxon::PrivateIncompleteNullReturnValue<String>(maxon::NULL_RETURN_REASON::UNRESOLVED, OVERLOAD_MAX_RANK);}
		StridedBlock<const Generic> GetVariableInternalData() const { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ((const StringInterface*) this)->GetVariableInternalData(); return maxon::PrivateIncompleteNullReturnValue<StridedBlock<const Generic>>(maxon::NULL_RETURN_REASON::UNRESOLVED, OVERLOAD_MAX_RANK);}
		Int GetCharacterWidth() const { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ((const StringInterface*) this)->GetCharacterWidth(); return 0;}
	};
	MAXON_WARNING_POP
#ifdef PRIVATE_MAXON_ASSEMBLE_UNRESOLVED
	const maxon::NULL_RETURN_TYPE StringInterface::MTable::_returnTypes[] = 
	{
		maxon::NULL_RETURN_TYPE::VOID_ZERO_FREE_FUNCTION,
		maxon::details::NullReturnType<Int>::value,
		maxon::details::NullReturnType<Result<void>>::value,
		maxon::details::NullReturnType<Result<void>>::value,
		maxon::details::NullReturnType<Result<void>>::value,
		maxon::details::NullReturnType<Result<void>>::value,
		maxon::details::NullReturnType<Int>::value,
		maxon::details::NullReturnType<Int>::value,
		maxon::details::NullReturnType<Int>::value,
		maxon::details::NullReturnType<Int>::value,
		maxon::details::NullReturnType<Int>::value,
		maxon::details::NullReturnType<Int>::value,
		maxon::details::NullReturnType<Result<void>>::value,
		maxon::details::NullReturnType<Result<void>>::value,
		maxon::details::NullReturnType<Result<void>>::value,
		maxon::details::NullReturnType<StringInterface*>::value,
		maxon::details::NullReturnType<StringInterface*>::value,
		maxon::details::NullReturnType<StringInterface*>::value,
		maxon::details::NullReturnType<COMPARERESULT>::value,
		maxon::details::NullReturnType<UInt>::value,
		maxon::details::NullReturnType<void>::value,
		maxon::details::NullReturnType<Utf32Char>::value,
		maxon::details::NullReturnType<Result<void>>::value,
		maxon::details::NullReturnType<Result<void>>::value,
		maxon::details::NullReturnType<Result<void>>::value,
		maxon::details::NullReturnType<Result<void>>::value,
		maxon::details::NullReturnType<Result<Int>>::value,
		maxon::details::NullReturnType<Result<Int>>::value,
		maxon::details::NullReturnType<Result<Int>>::value,
		maxon::details::NullReturnType<StringInterface*>::value,
		maxon::details::NullReturnType<StringInterface*>::value,
		maxon::details::NullReturnType<Result<Int>>::value,
		maxon::details::NullReturnType<Result<void>>::value,
		maxon::details::NullReturnType<Result<BaseArray<Char>>>::value,
		maxon::details::NullReturnType<Result<void>>::value,
		maxon::details::NullReturnType<Result<SysCharArray>>::value,
		maxon::details::NullReturnType<Result<void>>::value,
		maxon::details::NullReturnType<Result<void>>::value,
		maxon::details::NullReturnType<Result<void>>::value,
		maxon::details::NullReturnType<Result<void>>::value,
		maxon::details::NullReturnType<const String&>::value,
		maxon::details::NullReturnType<const String&>::value,
		maxon::details::NullReturnType<String>::value,
		maxon::details::NullReturnType<StridedBlock<const Generic>>::value,
		maxon::details::NullReturnType<Int>::value,
		maxon::NULL_RETURN_TYPE::OTHER
	};
#endif
	maxon::Bool StringInterface::MTable::InitUnresolved(maxon::NonvirtualInterfaceReference::UnresolvedAssembler assembler, MTable* tbl)
	{
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->_StringInterface_Free = &Hxx2::Wrapper<Hxx2::Unresolved>::_StringInterface_Free;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->_StringInterface_GetLength = &Hxx2::Wrapper<Hxx2::Unresolved>::_StringInterface_GetLength;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<void>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_StringInterface_Init = &Hxx2::Wrapper<Hxx2::Unresolved>::_StringInterface_Init;
		#else
		tbl->_StringInterface_Init = &Hxx2::Wrapper<Hxx2::Unresolved>::_StringInterface_Init;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<void>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_StringInterface_Shrink = &Hxx2::Wrapper<Hxx2::Unresolved>::_StringInterface_Shrink;
		#else
		tbl->_StringInterface_Shrink = &Hxx2::Wrapper<Hxx2::Unresolved>::_StringInterface_Shrink;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<void>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_StringInterface_Append = &Hxx2::Wrapper<Hxx2::Unresolved>::_StringInterface_Append;
		#else
		tbl->_StringInterface_Append = &Hxx2::Wrapper<Hxx2::Unresolved>::_StringInterface_Append;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<void>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_StringInterface_Append_1 = &Hxx2::Wrapper<Hxx2::Unresolved>::_StringInterface_Append_1;
		#else
		tbl->_StringInterface_Append_1 = &Hxx2::Wrapper<Hxx2::Unresolved>::_StringInterface_Append_1;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->_StringInterface_FindIndex = &Hxx2::Wrapper<Hxx2::Unresolved>::_StringInterface_FindIndex;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->_StringInterface_FindLastIndex = &Hxx2::Wrapper<Hxx2::Unresolved>::_StringInterface_FindLastIndex;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->_StringInterface_FindIndex_1 = &Hxx2::Wrapper<Hxx2::Unresolved>::_StringInterface_FindIndex_1;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->_StringInterface_FindLastIndex_1 = &Hxx2::Wrapper<Hxx2::Unresolved>::_StringInterface_FindLastIndex_1;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->_StringInterface_FindUpperIndex = &Hxx2::Wrapper<Hxx2::Unresolved>::_StringInterface_FindUpperIndex;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->_StringInterface_FindLastUpperIndex = &Hxx2::Wrapper<Hxx2::Unresolved>::_StringInterface_FindLastUpperIndex;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<void>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_StringInterface_Erase = &Hxx2::Wrapper<Hxx2::Unresolved>::_StringInterface_Erase;
		#else
		tbl->_StringInterface_Erase = &Hxx2::Wrapper<Hxx2::Unresolved>::_StringInterface_Erase;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<void>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_StringInterface_Insert = &Hxx2::Wrapper<Hxx2::Unresolved>::_StringInterface_Insert;
		#else
		tbl->_StringInterface_Insert = &Hxx2::Wrapper<Hxx2::Unresolved>::_StringInterface_Insert;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<void>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_StringInterface_Insert_1 = &Hxx2::Wrapper<Hxx2::Unresolved>::_StringInterface_Insert_1;
		#else
		tbl->_StringInterface_Insert_1 = &Hxx2::Wrapper<Hxx2::Unresolved>::_StringInterface_Insert_1;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->_StringInterface_GetPart = &Hxx2::Wrapper<Hxx2::Unresolved>::_StringInterface_GetPart;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->_StringInterface_ToUpper = &Hxx2::Wrapper<Hxx2::Unresolved>::_StringInterface_ToUpper;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->_StringInterface_ToLower = &Hxx2::Wrapper<Hxx2::Unresolved>::_StringInterface_ToLower;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<COMPARERESULT>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_StringInterface_ComparePart = &Hxx2::Wrapper<Hxx2::Unresolved>::_StringInterface_ComparePart;
		#else
		tbl->_StringInterface_ComparePart = &Hxx2::Wrapper<Hxx2::Unresolved>::_StringInterface_ComparePart;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->_StringInterface_GetHashCode = &Hxx2::Wrapper<Hxx2::Unresolved>::_StringInterface_GetHashCode;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->_StringInterface_SetChar = &Hxx2::Wrapper<Hxx2::Unresolved>::_StringInterface_SetChar;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->_StringInterface_GetChar = &Hxx2::Wrapper<Hxx2::Unresolved>::_StringInterface_GetChar;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<void>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_StringInterface_GetUtf32 = &Hxx2::Wrapper<Hxx2::Unresolved>::_StringInterface_GetUtf32;
		#else
		tbl->_StringInterface_GetUtf32 = &Hxx2::Wrapper<Hxx2::Unresolved>::_StringInterface_GetUtf32;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<void>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_StringInterface_TrimLeft = &Hxx2::Wrapper<Hxx2::Unresolved>::_StringInterface_TrimLeft;
		#else
		tbl->_StringInterface_TrimLeft = &Hxx2::Wrapper<Hxx2::Unresolved>::_StringInterface_TrimLeft;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<void>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_StringInterface_TrimRight = &Hxx2::Wrapper<Hxx2::Unresolved>::_StringInterface_TrimRight;
		#else
		tbl->_StringInterface_TrimRight = &Hxx2::Wrapper<Hxx2::Unresolved>::_StringInterface_TrimRight;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<void>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_StringInterface_Split = &Hxx2::Wrapper<Hxx2::Unresolved>::_StringInterface_Split;
		#else
		tbl->_StringInterface_Split = &Hxx2::Wrapper<Hxx2::Unresolved>::_StringInterface_Split;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<Int>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_StringInterface_Replace = &Hxx2::Wrapper<Hxx2::Unresolved>::_StringInterface_Replace;
		#else
		tbl->_StringInterface_Replace = &Hxx2::Wrapper<Hxx2::Unresolved>::_StringInterface_Replace;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<Int>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_StringInterface_Replace_1 = &Hxx2::Wrapper<Hxx2::Unresolved>::_StringInterface_Replace_1;
		#else
		tbl->_StringInterface_Replace_1 = &Hxx2::Wrapper<Hxx2::Unresolved>::_StringInterface_Replace_1;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<Int>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_StringInterface_Replace_2 = &Hxx2::Wrapper<Hxx2::Unresolved>::_StringInterface_Replace_2;
		#else
		tbl->_StringInterface_Replace_2 = &Hxx2::Wrapper<Hxx2::Unresolved>::_StringInterface_Replace_2;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->_StringInterface_Alloc = &Hxx2::Wrapper<Hxx2::Unresolved>::_StringInterface_Alloc;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->_StringInterface_Alloc_1 = &Hxx2::Wrapper<Hxx2::Unresolved>::_StringInterface_Alloc_1;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<Int>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_StringInterface_GetCStringBlock = &Hxx2::Wrapper<Hxx2::Unresolved>::_StringInterface_GetCStringBlock;
		#else
		tbl->_StringInterface_GetCStringBlock = &Hxx2::Wrapper<Hxx2::Unresolved>::_StringInterface_GetCStringBlock;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<void>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_StringInterface_GetCStringAppendArray = &Hxx2::Wrapper<Hxx2::Unresolved>::_StringInterface_GetCStringAppendArray;
		#else
		tbl->_StringInterface_GetCStringAppendArray = &Hxx2::Wrapper<Hxx2::Unresolved>::_StringInterface_GetCStringAppendArray;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<BaseArray<Char>>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_StringInterface_GetCString = &Hxx2::Wrapper<Hxx2::Unresolved>::_StringInterface_GetCString;
		#else
		tbl->_StringInterface_GetCString = &Hxx2::Wrapper<Hxx2::Unresolved>::_StringInterface_GetCString;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<void>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_StringInterface_SetCString = &Hxx2::Wrapper<Hxx2::Unresolved>::_StringInterface_SetCString;
		#else
		tbl->_StringInterface_SetCString = &Hxx2::Wrapper<Hxx2::Unresolved>::_StringInterface_SetCString;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<SysCharArray>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_StringInterface_GetSystemEncoding = &Hxx2::Wrapper<Hxx2::Unresolved>::_StringInterface_GetSystemEncoding;
		#else
		tbl->_StringInterface_GetSystemEncoding = &Hxx2::Wrapper<Hxx2::Unresolved>::_StringInterface_GetSystemEncoding;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<void>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_StringInterface_SetSystemEncoding = &Hxx2::Wrapper<Hxx2::Unresolved>::_StringInterface_SetSystemEncoding;
		#else
		tbl->_StringInterface_SetSystemEncoding = &Hxx2::Wrapper<Hxx2::Unresolved>::_StringInterface_SetSystemEncoding;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<void>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_StringInterface_SetUtf32 = &Hxx2::Wrapper<Hxx2::Unresolved>::_StringInterface_SetUtf32;
		#else
		tbl->_StringInterface_SetUtf32 = &Hxx2::Wrapper<Hxx2::Unresolved>::_StringInterface_SetUtf32;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<void>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_StringInterface_GetUtf16 = &Hxx2::Wrapper<Hxx2::Unresolved>::_StringInterface_GetUtf16;
		#else
		tbl->_StringInterface_GetUtf16 = &Hxx2::Wrapper<Hxx2::Unresolved>::_StringInterface_GetUtf16;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<void>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_StringInterface_SetUtf16 = &Hxx2::Wrapper<Hxx2::Unresolved>::_StringInterface_SetUtf16;
		#else
		tbl->_StringInterface_SetUtf16 = &Hxx2::Wrapper<Hxx2::Unresolved>::_StringInterface_SetUtf16;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<const String&>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_StringInterface_GetAndCacheConstString = &Hxx2::Wrapper<Hxx2::Unresolved>::_StringInterface_GetAndCacheConstString;
		#else
		tbl->_StringInterface_GetAndCacheConstString = &Hxx2::Wrapper<Hxx2::Unresolved>::_StringInterface_GetAndCacheConstString;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<const String&>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_StringInterface_GetAndCacheConstString_1 = &Hxx2::Wrapper<Hxx2::Unresolved>::_StringInterface_GetAndCacheConstString_1;
		#else
		tbl->_StringInterface_GetAndCacheConstString_1 = &Hxx2::Wrapper<Hxx2::Unresolved>::_StringInterface_GetAndCacheConstString_1;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<String>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_StringInterface_PrivateEnumToString = &Hxx2::Wrapper<Hxx2::Unresolved>::_StringInterface_PrivateEnumToString;
		#else
		tbl->_StringInterface_PrivateEnumToString = &Hxx2::Wrapper<Hxx2::Unresolved>::_StringInterface_PrivateEnumToString;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<StridedBlock<const Generic>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_StringInterface_GetVariableInternalData = &Hxx2::Wrapper<Hxx2::Unresolved>::_StringInterface_GetVariableInternalData;
		#else
		tbl->_StringInterface_GetVariableInternalData = &Hxx2::Wrapper<Hxx2::Unresolved>::_StringInterface_GetVariableInternalData;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->_StringInterface_GetCharacterWidth = &Hxx2::Wrapper<Hxx2::Unresolved>::_StringInterface_GetCharacterWidth;
		#endif
	#ifdef PRIVATE_MAXON_ASSEMBLE_UNRESOLVED
		return assembler(&_interface, (maxon::Char*) tbl, _returnTypes, SIZEOF(MTable) / SIZEOF(void*));
	#else
		return true;
	#endif
	}
	MAXON_INTERFACE_REGISTER(StringInterface, "net.maxon.interface.string", nullptr);
	template <typename DUMMY> maxon::Int StringInterface::PrivateInstantiateNullValueHelper()
	{
		return 0
		| maxon::details::InstantiateNullReturnValue<COMPARERESULT>(OVERLOAD_MAX_RANK)
		| maxon::details::InstantiateNullReturnValue<StridedBlock<const Generic>>(OVERLOAD_MAX_RANK)
		| maxon::details::InstantiateNullReturnValue<String>(OVERLOAD_MAX_RANK)
		| maxon::details::InstantiateNullReturnValue<const String&>(OVERLOAD_MAX_RANK)
		;
	}
	const maxon::Char* const CStringInterface::MTable::_ids = 
		"Free@070b12f769a3a54a\0" // void Free(const CStringInterface* object)
		"GetLength@4386c86\0" // Int GetLength() const
		"Init@a498e1935d4107cb\0" // Result<void> Init(Int count, Char fillChar)
		"Shrink@a54f4799cbe1a498\0" // Result<void> Shrink()
		"Append@647f5767f40aec50\0" // Result<void> Append(const CStringInterface* str)
		"Append@71bd771ba9388182\0" // Result<void> Append(const Char* str, Int len)
		"FindIndex@dc9558d1ea72e888\0" // Int FindIndex(const CStringInterface* str, StringPosition start) const
		"FindLastIndex@dc9558d1ea72e888\0" // Int FindLastIndex(const CStringInterface* str, StringPosition start) const
		"FindIndex@5e63357cbdb0bcfe\0" // Int FindIndex(Char ch, StringPosition start) const
		"FindLastIndex@5e63357cbdb0bcfe\0" // Int FindLastIndex(Char ch, StringPosition start) const
		"FindUpperIndex@dc9558d1ea72e888\0" // Int FindUpperIndex(const CStringInterface* str, StringPosition start) const
		"FindLastUpperIndex@dc9558d1ea72e888\0" // Int FindLastUpperIndex(const CStringInterface* str, StringPosition start) const
		"Erase@d2fb2ee68a77afc4\0" // Result<void> Erase(StringPosition position, StringCount count)
		"Insert@94bd6371b50e624a\0" // Result<void> Insert(StringPosition position, const CStringInterface* str, StringPosition strStart, StringCount strCount)
		"Insert@011a5b250d86e9d0\0" // Result<void> Insert(StringPosition position, Char ch)
		"GetPart@3def6d7d5a996870\0" // INTERFACETYPE* GetPart(StringPosition start, StringCount count) const
		"ToUpper@ea2b972fcb31729c\0" // INTERFACETYPE* ToUpper() const
		"ToLower@ea2b972fcb31729c\0" // INTERFACETYPE* ToLower() const
		"ComparePart@f3216a82df22d2c1\0" // COMPARERESULT ComparePart(const CStringInterface* str, STRINGCOMPARISON mode, StringPosition position, StringCount count) const
		"GetHashCode@95445951\0" // UInt GetHashCode() const
		"SetChar@323b480d2ce5dd42\0" // void SetChar(Int pos, Char ch)
		"GetChar@36a7d1384338\0" // CHARTYPE GetChar(Int pos) const
		"GetUtf32@e029f3e59e414238\0" // Result<void> GetUtf32(Utf32CharBuffer& stringData) const
		"TrimLeft@a54f4799cbe1a498\0" // Result<void> TrimLeft()
		"TrimRight@a54f4799cbe1a498\0" // Result<void> TrimRight()
		"Split@007fffbca7380a0d\0" // Result<void> Split(const CString& splitSymbol, Bool trim, const ValueReceiver<const CString&>& parts) const
		"Replace@0c55a0f09b69d017\0" // Result<Int> Replace(Char find, Char replace)
		"Replace@637c76fc49b1fbf7\0" // Result<Int> Replace(const CString& find, const CString& replace)
		"Replace@17043b8f74fd73f0\0" // Result<Int> Replace(Char find, const CString& replace)
		"Alloc@b7c43dffd54c3a35\0" // CStringInterface* Alloc(const maxon::SourceLocation& allocLocation)
		"Alloc@61a6f1c14ce020fd\0" // CStringInterface* Alloc(const maxon::SourceLocation& allocLocation, const CStringInterface& object)
		"GetCStringBlock@719f3b9d595e9a7b\0" // Result<Int> GetCStringBlock(const Block<Char>& buffer) const
		"GetCStringAppendArray@f922e335a68d524e\0" // Result<void> GetCStringAppendArray(const NonConstArray<Char>& array) const
		"SetCString@71bd771ba9388182\0" // Result<void> SetCString(const Char* buffer, Int count)
		"GetCString@d4a21abc0ae635e0\0" // Result<BaseArray<Char>> GetCString() const
		"GetInternalData@c0d4f1cbab9b3d33\0" // Block<const Char> GetInternalData() const
		"GetAndCacheConstString@7bdde785d9c7a3bd\0" // const CString& GetAndCacheConstString(const Char* chr, Int len)
	"";
	MAXON_WARNING_PUSH
	MAXON_WARNING_DISABLE_DEPRECATED
	class CStringInterface::Hxx2::Unresolved : public CStringInterface
	{
	public:
		static const Unresolved* Get(const CStringInterface* o) { return (const Unresolved*) o; }
		static Unresolved* Get(CStringInterface* o) { return (Unresolved*) o; }
		static void Free(const CStringInterface* object) { if (object && maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return CStringInterface::Free(object); return maxon::PrivateLogNullptrError();}
		Int GetLength() const { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ((const CStringInterface*) this)->GetLength(); return 0;}
		Result<void> Init(Int count, Char fillChar) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return ((CStringInterface*) this)->Init(count, fillChar); return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::UNRESOLVED);}
		Result<void> Shrink() { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return ((CStringInterface*) this)->Shrink(); return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::UNRESOLVED);}
		Result<void> Append(const CStringInterface* str) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return ((CStringInterface*) this)->Append(str); return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::UNRESOLVED);}
		Result<void> Append(const Char* str, Int len) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return ((CStringInterface*) this)->Append(str, len); return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::UNRESOLVED);}
		Int FindIndex(const CStringInterface* str, StringPosition start) const { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ((const CStringInterface*) this)->FindIndex(str, std::forward<StringPosition>(start)); return InvalidArrayIndex;}
		Int FindLastIndex(const CStringInterface* str, StringPosition start) const { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ((const CStringInterface*) this)->FindLastIndex(str, std::forward<StringPosition>(start)); return InvalidArrayIndex;}
		Int FindIndex(Char ch, StringPosition start) const { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ((const CStringInterface*) this)->FindIndex(ch, std::forward<StringPosition>(start)); return InvalidArrayIndex;}
		Int FindLastIndex(Char ch, StringPosition start) const { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ((const CStringInterface*) this)->FindLastIndex(ch, std::forward<StringPosition>(start)); return InvalidArrayIndex;}
		Int FindUpperIndex(const CStringInterface* str, StringPosition start) const { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ((const CStringInterface*) this)->FindUpperIndex(str, std::forward<StringPosition>(start)); return InvalidArrayIndex;}
		Int FindLastUpperIndex(const CStringInterface* str, StringPosition start) const { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ((const CStringInterface*) this)->FindLastUpperIndex(str, std::forward<StringPosition>(start)); return InvalidArrayIndex;}
		Result<void> Erase(StringPosition position, StringCount count) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return ((CStringInterface*) this)->Erase(std::forward<StringPosition>(position), std::forward<StringCount>(count)); return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::UNRESOLVED);}
		Result<void> Insert(StringPosition position, const CStringInterface* str, StringPosition strStart, StringCount strCount) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return ((CStringInterface*) this)->Insert(std::forward<StringPosition>(position), str, std::forward<StringPosition>(strStart), std::forward<StringCount>(strCount)); return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::UNRESOLVED);}
		Result<void> Insert(StringPosition position, Char ch) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return ((CStringInterface*) this)->Insert(std::forward<StringPosition>(position), ch); return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::UNRESOLVED);}
		CStringInterface* GetPart(StringPosition start, StringCount count) const { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ((const CStringInterface*) this)->GetPart(std::forward<StringPosition>(start), std::forward<StringCount>(count)); return nullptr;}
		CStringInterface* ToUpper() const { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ((const CStringInterface*) this)->ToUpper(); return nullptr;}
		CStringInterface* ToLower() const { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ((const CStringInterface*) this)->ToLower(); return nullptr;}
		COMPARERESULT ComparePart(const CStringInterface* str, STRINGCOMPARISON mode, StringPosition position, StringCount count) const { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ((const CStringInterface*) this)->ComparePart(str, mode, std::forward<StringPosition>(position), std::forward<StringCount>(count)); return maxon::PrivateIncompleteNullReturnValue<COMPARERESULT>(maxon::NULL_RETURN_REASON::UNRESOLVED, OVERLOAD_MAX_RANK);}
		UInt GetHashCode() const { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ((const CStringInterface*) this)->GetHashCode(); return 0;}
		void SetChar(Int pos, Char ch) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ((CStringInterface*) this)->SetChar(pos, ch); return maxon::PrivateLogNullptrError();}
		Char GetChar(Int pos) const { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ((const CStringInterface*) this)->GetChar(pos); return 0;}
		Result<void> GetUtf32(Utf32CharBuffer& stringData) const { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return ((const CStringInterface*) this)->GetUtf32(stringData); return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::UNRESOLVED);}
		Result<void> TrimLeft() { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return ((CStringInterface*) this)->TrimLeft(); return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::UNRESOLVED);}
		Result<void> TrimRight() { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return ((CStringInterface*) this)->TrimRight(); return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::UNRESOLVED);}
		Result<void> Split(const CString& splitSymbol, Bool trim, const ValueReceiver<const CString&>& parts) const { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return ((const CStringInterface*) this)->Split(splitSymbol, trim, parts); return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::UNRESOLVED);}
		Result<Int> Replace(Char find, Char replace) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return ((CStringInterface*) this)->Replace(find, replace); return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::UNRESOLVED);}
		Result<Int> Replace(const CString& find, const CString& replace) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return ((CStringInterface*) this)->Replace(find, replace); return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::UNRESOLVED);}
		Result<Int> Replace(Char find, const CString& replace) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return ((CStringInterface*) this)->Replace(find, replace); return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::UNRESOLVED);}
		static CStringInterface* Alloc(const maxon::SourceLocation& allocLocation) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return CStringInterface::Alloc(allocLocation); return nullptr;}
		static CStringInterface* Alloc(const maxon::SourceLocation& allocLocation, const CStringInterface& object) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return CStringInterface::Alloc(allocLocation, object); return nullptr;}
		Result<Int> GetCStringBlock(const Block<Char>& buffer) const { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return ((const CStringInterface*) this)->GetCStringBlock(buffer); return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::UNRESOLVED);}
		Result<void> GetCStringAppendArray(const NonConstArray<Char>& array) const { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return ((const CStringInterface*) this)->GetCStringAppendArray(array); return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::UNRESOLVED);}
		Result<void> SetCString(const Char* buffer, Int count) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return ((CStringInterface*) this)->SetCString(buffer, count); return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::UNRESOLVED);}
		Result<BaseArray<Char>> GetCString() const { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return ((const CStringInterface*) this)->GetCString(); return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::UNRESOLVED);}
		Block<const Char> GetInternalData() const { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ((const CStringInterface*) this)->GetInternalData(); return maxon::PrivateIncompleteNullReturnValue<Block<const Char>>(maxon::NULL_RETURN_REASON::UNRESOLVED, OVERLOAD_MAX_RANK);}
		static const CString& GetAndCacheConstString(const Char* chr, Int len) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return CStringInterface::GetAndCacheConstString(chr, len); return maxon::PrivateIncompleteNullReturnValue<const CString&>(maxon::NULL_RETURN_REASON::UNRESOLVED, OVERLOAD_MAX_RANK);}
	};
	MAXON_WARNING_POP
#ifdef PRIVATE_MAXON_ASSEMBLE_UNRESOLVED
	const maxon::NULL_RETURN_TYPE CStringInterface::MTable::_returnTypes[] = 
	{
		maxon::NULL_RETURN_TYPE::VOID_ZERO_FREE_FUNCTION,
		maxon::details::NullReturnType<Int>::value,
		maxon::details::NullReturnType<Result<void>>::value,
		maxon::details::NullReturnType<Result<void>>::value,
		maxon::details::NullReturnType<Result<void>>::value,
		maxon::details::NullReturnType<Result<void>>::value,
		maxon::details::NullReturnType<Int>::value,
		maxon::details::NullReturnType<Int>::value,
		maxon::details::NullReturnType<Int>::value,
		maxon::details::NullReturnType<Int>::value,
		maxon::details::NullReturnType<Int>::value,
		maxon::details::NullReturnType<Int>::value,
		maxon::details::NullReturnType<Result<void>>::value,
		maxon::details::NullReturnType<Result<void>>::value,
		maxon::details::NullReturnType<Result<void>>::value,
		maxon::details::NullReturnType<CStringInterface*>::value,
		maxon::details::NullReturnType<CStringInterface*>::value,
		maxon::details::NullReturnType<CStringInterface*>::value,
		maxon::details::NullReturnType<COMPARERESULT>::value,
		maxon::details::NullReturnType<UInt>::value,
		maxon::details::NullReturnType<void>::value,
		maxon::details::NullReturnType<Char>::value,
		maxon::details::NullReturnType<Result<void>>::value,
		maxon::details::NullReturnType<Result<void>>::value,
		maxon::details::NullReturnType<Result<void>>::value,
		maxon::details::NullReturnType<Result<void>>::value,
		maxon::details::NullReturnType<Result<Int>>::value,
		maxon::details::NullReturnType<Result<Int>>::value,
		maxon::details::NullReturnType<Result<Int>>::value,
		maxon::details::NullReturnType<CStringInterface*>::value,
		maxon::details::NullReturnType<CStringInterface*>::value,
		maxon::details::NullReturnType<Result<Int>>::value,
		maxon::details::NullReturnType<Result<void>>::value,
		maxon::details::NullReturnType<Result<void>>::value,
		maxon::details::NullReturnType<Result<BaseArray<Char>>>::value,
		maxon::details::NullReturnType<Block<const Char>>::value,
		maxon::details::NullReturnType<const CString&>::value,
		maxon::NULL_RETURN_TYPE::OTHER
	};
#endif
	maxon::Bool CStringInterface::MTable::InitUnresolved(maxon::NonvirtualInterfaceReference::UnresolvedAssembler assembler, MTable* tbl)
	{
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->_CStringInterface_Free = &Hxx2::Wrapper<Hxx2::Unresolved>::_CStringInterface_Free;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->_CStringInterface_GetLength = &Hxx2::Wrapper<Hxx2::Unresolved>::_CStringInterface_GetLength;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<void>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_CStringInterface_Init = &Hxx2::Wrapper<Hxx2::Unresolved>::_CStringInterface_Init;
		#else
		tbl->_CStringInterface_Init = &Hxx2::Wrapper<Hxx2::Unresolved>::_CStringInterface_Init;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<void>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_CStringInterface_Shrink = &Hxx2::Wrapper<Hxx2::Unresolved>::_CStringInterface_Shrink;
		#else
		tbl->_CStringInterface_Shrink = &Hxx2::Wrapper<Hxx2::Unresolved>::_CStringInterface_Shrink;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<void>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_CStringInterface_Append = &Hxx2::Wrapper<Hxx2::Unresolved>::_CStringInterface_Append;
		#else
		tbl->_CStringInterface_Append = &Hxx2::Wrapper<Hxx2::Unresolved>::_CStringInterface_Append;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<void>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_CStringInterface_Append_1 = &Hxx2::Wrapper<Hxx2::Unresolved>::_CStringInterface_Append_1;
		#else
		tbl->_CStringInterface_Append_1 = &Hxx2::Wrapper<Hxx2::Unresolved>::_CStringInterface_Append_1;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->_CStringInterface_FindIndex = &Hxx2::Wrapper<Hxx2::Unresolved>::_CStringInterface_FindIndex;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->_CStringInterface_FindLastIndex = &Hxx2::Wrapper<Hxx2::Unresolved>::_CStringInterface_FindLastIndex;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->_CStringInterface_FindIndex_1 = &Hxx2::Wrapper<Hxx2::Unresolved>::_CStringInterface_FindIndex_1;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->_CStringInterface_FindLastIndex_1 = &Hxx2::Wrapper<Hxx2::Unresolved>::_CStringInterface_FindLastIndex_1;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->_CStringInterface_FindUpperIndex = &Hxx2::Wrapper<Hxx2::Unresolved>::_CStringInterface_FindUpperIndex;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->_CStringInterface_FindLastUpperIndex = &Hxx2::Wrapper<Hxx2::Unresolved>::_CStringInterface_FindLastUpperIndex;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<void>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_CStringInterface_Erase = &Hxx2::Wrapper<Hxx2::Unresolved>::_CStringInterface_Erase;
		#else
		tbl->_CStringInterface_Erase = &Hxx2::Wrapper<Hxx2::Unresolved>::_CStringInterface_Erase;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<void>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_CStringInterface_Insert = &Hxx2::Wrapper<Hxx2::Unresolved>::_CStringInterface_Insert;
		#else
		tbl->_CStringInterface_Insert = &Hxx2::Wrapper<Hxx2::Unresolved>::_CStringInterface_Insert;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<void>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_CStringInterface_Insert_1 = &Hxx2::Wrapper<Hxx2::Unresolved>::_CStringInterface_Insert_1;
		#else
		tbl->_CStringInterface_Insert_1 = &Hxx2::Wrapper<Hxx2::Unresolved>::_CStringInterface_Insert_1;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->_CStringInterface_GetPart = &Hxx2::Wrapper<Hxx2::Unresolved>::_CStringInterface_GetPart;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->_CStringInterface_ToUpper = &Hxx2::Wrapper<Hxx2::Unresolved>::_CStringInterface_ToUpper;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->_CStringInterface_ToLower = &Hxx2::Wrapper<Hxx2::Unresolved>::_CStringInterface_ToLower;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<COMPARERESULT>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_CStringInterface_ComparePart = &Hxx2::Wrapper<Hxx2::Unresolved>::_CStringInterface_ComparePart;
		#else
		tbl->_CStringInterface_ComparePart = &Hxx2::Wrapper<Hxx2::Unresolved>::_CStringInterface_ComparePart;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->_CStringInterface_GetHashCode = &Hxx2::Wrapper<Hxx2::Unresolved>::_CStringInterface_GetHashCode;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->_CStringInterface_SetChar = &Hxx2::Wrapper<Hxx2::Unresolved>::_CStringInterface_SetChar;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->_CStringInterface_GetChar = &Hxx2::Wrapper<Hxx2::Unresolved>::_CStringInterface_GetChar;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<void>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_CStringInterface_GetUtf32 = &Hxx2::Wrapper<Hxx2::Unresolved>::_CStringInterface_GetUtf32;
		#else
		tbl->_CStringInterface_GetUtf32 = &Hxx2::Wrapper<Hxx2::Unresolved>::_CStringInterface_GetUtf32;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<void>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_CStringInterface_TrimLeft = &Hxx2::Wrapper<Hxx2::Unresolved>::_CStringInterface_TrimLeft;
		#else
		tbl->_CStringInterface_TrimLeft = &Hxx2::Wrapper<Hxx2::Unresolved>::_CStringInterface_TrimLeft;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<void>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_CStringInterface_TrimRight = &Hxx2::Wrapper<Hxx2::Unresolved>::_CStringInterface_TrimRight;
		#else
		tbl->_CStringInterface_TrimRight = &Hxx2::Wrapper<Hxx2::Unresolved>::_CStringInterface_TrimRight;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<void>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_CStringInterface_Split = &Hxx2::Wrapper<Hxx2::Unresolved>::_CStringInterface_Split;
		#else
		tbl->_CStringInterface_Split = &Hxx2::Wrapper<Hxx2::Unresolved>::_CStringInterface_Split;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<Int>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_CStringInterface_Replace = &Hxx2::Wrapper<Hxx2::Unresolved>::_CStringInterface_Replace;
		#else
		tbl->_CStringInterface_Replace = &Hxx2::Wrapper<Hxx2::Unresolved>::_CStringInterface_Replace;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<Int>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_CStringInterface_Replace_1 = &Hxx2::Wrapper<Hxx2::Unresolved>::_CStringInterface_Replace_1;
		#else
		tbl->_CStringInterface_Replace_1 = &Hxx2::Wrapper<Hxx2::Unresolved>::_CStringInterface_Replace_1;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<Int>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_CStringInterface_Replace_2 = &Hxx2::Wrapper<Hxx2::Unresolved>::_CStringInterface_Replace_2;
		#else
		tbl->_CStringInterface_Replace_2 = &Hxx2::Wrapper<Hxx2::Unresolved>::_CStringInterface_Replace_2;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->_CStringInterface_Alloc = &Hxx2::Wrapper<Hxx2::Unresolved>::_CStringInterface_Alloc;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->_CStringInterface_Alloc_1 = &Hxx2::Wrapper<Hxx2::Unresolved>::_CStringInterface_Alloc_1;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<Int>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_CStringInterface_GetCStringBlock = &Hxx2::Wrapper<Hxx2::Unresolved>::_CStringInterface_GetCStringBlock;
		#else
		tbl->_CStringInterface_GetCStringBlock = &Hxx2::Wrapper<Hxx2::Unresolved>::_CStringInterface_GetCStringBlock;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<void>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_CStringInterface_GetCStringAppendArray = &Hxx2::Wrapper<Hxx2::Unresolved>::_CStringInterface_GetCStringAppendArray;
		#else
		tbl->_CStringInterface_GetCStringAppendArray = &Hxx2::Wrapper<Hxx2::Unresolved>::_CStringInterface_GetCStringAppendArray;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<void>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_CStringInterface_SetCString = &Hxx2::Wrapper<Hxx2::Unresolved>::_CStringInterface_SetCString;
		#else
		tbl->_CStringInterface_SetCString = &Hxx2::Wrapper<Hxx2::Unresolved>::_CStringInterface_SetCString;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<BaseArray<Char>>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_CStringInterface_GetCString = &Hxx2::Wrapper<Hxx2::Unresolved>::_CStringInterface_GetCString;
		#else
		tbl->_CStringInterface_GetCString = &Hxx2::Wrapper<Hxx2::Unresolved>::_CStringInterface_GetCString;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Block<const Char>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_CStringInterface_GetInternalData = &Hxx2::Wrapper<Hxx2::Unresolved>::_CStringInterface_GetInternalData;
		#else
		tbl->_CStringInterface_GetInternalData = &Hxx2::Wrapper<Hxx2::Unresolved>::_CStringInterface_GetInternalData;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<const CString&>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_CStringInterface_GetAndCacheConstString = &Hxx2::Wrapper<Hxx2::Unresolved>::_CStringInterface_GetAndCacheConstString;
		#else
		tbl->_CStringInterface_GetAndCacheConstString = &Hxx2::Wrapper<Hxx2::Unresolved>::_CStringInterface_GetAndCacheConstString;
		#endif
	#ifdef PRIVATE_MAXON_ASSEMBLE_UNRESOLVED
		return assembler(&_interface, (maxon::Char*) tbl, _returnTypes, SIZEOF(MTable) / SIZEOF(void*));
	#else
		return true;
	#endif
	}
	MAXON_INTERFACE_REGISTER(CStringInterface, "net.maxon.interface.cstring", nullptr);
	template <typename DUMMY> maxon::Int CStringInterface::PrivateInstantiateNullValueHelper()
	{
		return 0
		| maxon::details::InstantiateNullReturnValue<Block<const Char>>(OVERLOAD_MAX_RANK)
		| maxon::details::InstantiateNullReturnValue<COMPARERESULT>(OVERLOAD_MAX_RANK)
		| maxon::details::InstantiateNullReturnValue<CString>(OVERLOAD_MAX_RANK)
		| maxon::details::InstantiateNullReturnValue<const CString&>(OVERLOAD_MAX_RANK)
		;
	}
}
#endif
static maxon::details::ForceEvaluation s_forceEval_string(0
	| maxon::StringInterface::PrivateInstantiateNullValueHelper<maxon::Int>()
	| maxon::CStringInterface::PrivateInstantiateNullValueHelper<maxon::Int>()
);
