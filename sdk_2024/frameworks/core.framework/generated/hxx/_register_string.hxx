#if 1
namespace maxon
{
	namespace enum43
	{
		enum class STRINGCONVERSION
		{
			NONE									= 0,
			ALLOW_MORE_CHARACTERS	= (1 << 0)	///< if the specified string is longer than the converted characters and you specify this flag no error will be returned
		} ;
		static const maxon::UInt64 STRINGCONVERSION_values[] = {maxon::UInt64(enum43::STRINGCONVERSION::NONE), maxon::UInt64(enum43::STRINGCONVERSION::ALLOW_MORE_CHARACTERS)};
		static const maxon::EnumInfo STRINGCONVERSION_info{"STRINGCONVERSION", SIZEOF(STRINGCONVERSION), true, "NONE\0ALLOW_MORE_CHARACTERS\0", STRINGCONVERSION_values, std::extent<decltype(STRINGCONVERSION_values)>::value};
	}
	const maxon::EnumInfo& PrivateGetEnumInfo_STRINGCONVERSION43(){ return enum43::STRINGCONVERSION_info; }
	namespace enum55
	{
		enum class STRINGCOMPARISON
		{
			MEMORY									= 0,	///< default - fast comparison, memory block is directly compared. This does not result in a correct alphabetical order.
			UNICODE_LETTERS					= 1,	///< strings are compared using correct unicode decomposition
			UNICODE_NUMBERS					= 2,	///< strings are compared using correct unicode decomposition. Numbers in strings are identified, so "2" is smaller than "10"
			CASEINSENSITIVE					= 3,	///< strings are compared case-insensitive using correct unicode decomposition
			CASEINSENSITIVE_NUMBERS	= 4 	///< strings are compared case-insensitive using correct unicode decomposition. Numbers in strings are identified, so "2" is smaller than "10"
		} ;
		static const maxon::UInt64 STRINGCOMPARISON_values[] = {maxon::UInt64(enum55::STRINGCOMPARISON::MEMORY), maxon::UInt64(enum55::STRINGCOMPARISON::UNICODE_LETTERS), maxon::UInt64(enum55::STRINGCOMPARISON::UNICODE_NUMBERS), maxon::UInt64(enum55::STRINGCOMPARISON::CASEINSENSITIVE), maxon::UInt64(enum55::STRINGCOMPARISON::CASEINSENSITIVE_NUMBERS)};
		static const maxon::EnumInfo STRINGCOMPARISON_info{"STRINGCOMPARISON", SIZEOF(STRINGCOMPARISON), false, "MEMORY\0UNICODE_LETTERS\0UNICODE_NUMBERS\0CASEINSENSITIVE\0CASEINSENSITIVE_NUMBERS\0", STRINGCOMPARISON_values, std::extent<decltype(STRINGCOMPARISON_values)>::value};
	}
	const maxon::EnumInfo& PrivateGetEnumInfo_STRINGCOMPARISON55(){ return enum55::STRINGCOMPARISON_info; }
	const maxon::Char* const StringInterface::MTable::_ids = 
		"Free@fed1310e3f7c8050\0" // void Free(const StringInterface* object)
		"GetLength@7d0e6f3d29c239e7\0" // Int GetLength() const
		"Init@d5ea077af5859d7a\0" // Result<void> Init(Int count, Utf32Char fillChar)
		"Shrink@3008090429c5a175\0" // Result<void> Shrink()
		"Append@7c7b1ef58516dfa6\0" // Result<void> Append(const StringInterface* str)
		"Append@dfaf6774bbbf110f\0" // Result<void> Append(const Utf32Char* str, Int len)
		"FindIndex@4f316e99f5985864\0" // Int FindIndex(const StringInterface* str, StringPosition start) const
		"FindLastIndex@4f316e99f5985864\0" // Int FindLastIndex(const StringInterface* str, StringPosition start) const
		"FindIndex@9815dee0a2c23a0d\0" // Int FindIndex(Utf32Char ch, StringPosition start) const
		"FindLastIndex@9815dee0a2c23a0d\0" // Int FindLastIndex(Utf32Char ch, StringPosition start) const
		"FindUpperIndex@4f316e99f5985864\0" // Int FindUpperIndex(const StringInterface* str, StringPosition start) const
		"FindLastUpperIndex@4f316e99f5985864\0" // Int FindLastUpperIndex(const StringInterface* str, StringPosition start) const
		"Erase@68f553950fb89247\0" // Result<void> Erase(StringPosition position, StringCount count)
		"Insert@764f796028b21f70\0" // Result<void> Insert(StringPosition position, const StringInterface* str, StringPosition strStart, StringCount strCount)
		"Insert@fe049e65a4d0cb57\0" // Result<void> Insert(StringPosition position, Utf32Char ch)
		"GetPart@974cb098b4869bc\0" // INTERFACETYPE* GetPart(StringPosition start, StringCount count) const
		"ToUpper@2b0449fc6d5e71fe\0" // INTERFACETYPE* ToUpper() const
		"ToLower@2b0449fc6d5e71fe\0" // INTERFACETYPE* ToLower() const
		"ComparePart@57f47dddb43ccffb\0" // COMPARERESULT ComparePart(const StringInterface* str, STRINGCOMPARISON mode, StringPosition position, StringCount count) const
		"GetHashCode@b22918402154097b\0" // HashInt GetHashCode() const
		"GetUniqueHashCode@c78267ca5e388263\0" // UniqueHash GetUniqueHashCode() const
		"SetChar@12317744ff936105\0" // void SetChar(Int pos, Utf32Char ch)
		"GetChar@e7762d3b77e393dd\0" // CHARTYPE GetChar(Int pos) const
		"GetUtf32@63a358e963be05f1\0" // Result<void> GetUtf32(Utf32CharBuffer& stringData) const
		"TrimLeft@3008090429c5a175\0" // Result<void> TrimLeft()
		"TrimRight@3008090429c5a175\0" // Result<void> TrimRight()
		"Split@bc2e9d816d536f04\0" // Result<void> Split(const String& splitSymbol, Bool trim, const ValueReceiver<const String&>& parts) const
		"Replace@dac0721dcdab2dd2\0" // Result<Int> Replace(Utf32Char find, Utf32Char replace)
		"Replace@5a542e38824fe8b2\0" // Result<Int> Replace(const String& find, const String& replace)
		"Replace@c135e3b1992f82b4\0" // Result<Int> Replace(Utf32Char find, const String& replace)
		"Alloc@b8e3cc54c78e5ea5\0" // StringInterface* Alloc(const maxon::SourceLocation& allocLocation)
		"Alloc@bd960c5a87fe8b48\0" // StringInterface* Alloc(const maxon::SourceLocation& allocLocation, const StringInterface& object)
		"GetCStringBlock@b8530c57cbb6e4aa\0" // Result<Int> GetCStringBlock(const Block<Char>& buffer, const StringEncodingRef& stringEncoding) const
		"GetCStringAppendArray@bb0fd4ce1cc72397\0" // Result<void> GetCStringAppendArray(const NonConstArray<Char>& array, const StringEncodingRef& stringEncoding) const
		"GetCString@e7eb72ed4c6b3643\0" // Result<BaseArray<Char>> GetCString(const StringEncodingRef& stringEncoding) const
		"SetCString@64cb3d0723e855cd\0" // Result<void> SetCString(const Char* buffer, Int count, const StringDecodingRef& stringDecoding)
		"GetSystemEncoding@d4fcbabb4da1d79d\0" // Result<SysCharArray> GetSystemEncoding() const
		"SetSystemEncoding@b4e6eb1ad1a824c\0" // Result<void> SetSystemEncoding(const SysChar* buffer, Int count)
		"SetUtf32@dfaf6774bbbf110f\0" // Result<void> SetUtf32(const Utf32Char* buffer, Int count)
		"GetUtf16@a175feb0530551a3\0" // Result<void> GetUtf16(Utf16CharBuffer& stringData) const
		"SetUtf16@91ffa6e05270cb99\0" // Result<void> SetUtf16(const Utf16Char* buffer, Int count)
		"GetAndCacheConstString@75936a38ae43cd03\0" // const String& GetAndCacheConstString(const wchar_t* chr, Int len)
		"GetAndCacheConstString@3443f26ad094b648\0" // const String& GetAndCacheConstString(const Char* chr, Int len, Int isUtf8)
		"PrivateEnumToString@a2880b984ed09381\0" // String PrivateEnumToString(const EnumInfo& info, UInt64 value, const FormatStatement* formatStatement)
		"GetVariableInternalData@c2dc8124d45c6ef2\0" // StridedBlock<const Generic> GetVariableInternalData() const
		"GetCharacterWidth@7d0e6f3d29c239e7\0" // Int GetCharacterWidth() const
		"Prettify@56447d8a0cbb92c2\0" // Result<String> Prettify(Int indent, const String& indentStr, Int breakUpThreshold, Bool angularBrackets) const
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
		Result<void> Init(Int count, Utf32Char fillChar) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return ((StringInterface*) this)->Init(count, fillChar); return HXXRET1(UNRESOLVED);}
		Result<void> Shrink() { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return ((StringInterface*) this)->Shrink(); return HXXRET1(UNRESOLVED);}
		Result<void> Append(const StringInterface* str) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return ((StringInterface*) this)->Append(str); return HXXRET1(UNRESOLVED);}
		Result<void> Append(const Utf32Char* str, Int len) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return ((StringInterface*) this)->Append(str, len); return HXXRET1(UNRESOLVED);}
		Int FindIndex(const StringInterface* str, StringPosition start) const { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ((const StringInterface*) this)->FindIndex(str, std::forward<StringPosition>(start)); return InvalidArrayIndex;}
		Int FindLastIndex(const StringInterface* str, StringPosition start) const { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ((const StringInterface*) this)->FindLastIndex(str, std::forward<StringPosition>(start)); return InvalidArrayIndex;}
		Int FindIndex(Utf32Char ch, StringPosition start) const { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ((const StringInterface*) this)->FindIndex(ch, std::forward<StringPosition>(start)); return InvalidArrayIndex;}
		Int FindLastIndex(Utf32Char ch, StringPosition start) const { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ((const StringInterface*) this)->FindLastIndex(ch, std::forward<StringPosition>(start)); return InvalidArrayIndex;}
		Int FindUpperIndex(const StringInterface* str, StringPosition start) const { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ((const StringInterface*) this)->FindUpperIndex(str, std::forward<StringPosition>(start)); return InvalidArrayIndex;}
		Int FindLastUpperIndex(const StringInterface* str, StringPosition start) const { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ((const StringInterface*) this)->FindLastUpperIndex(str, std::forward<StringPosition>(start)); return InvalidArrayIndex;}
		Result<void> Erase(StringPosition position, StringCount count) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return ((StringInterface*) this)->Erase(std::forward<StringPosition>(position), std::forward<StringCount>(count)); return HXXRET1(UNRESOLVED);}
		Result<void> Insert(StringPosition position, const StringInterface* str, StringPosition strStart, StringCount strCount) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return ((StringInterface*) this)->Insert(std::forward<StringPosition>(position), str, std::forward<StringPosition>(strStart), std::forward<StringCount>(strCount)); return HXXRET1(UNRESOLVED);}
		Result<void> Insert(StringPosition position, Utf32Char ch) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return ((StringInterface*) this)->Insert(std::forward<StringPosition>(position), ch); return HXXRET1(UNRESOLVED);}
		StringInterface* GetPart(StringPosition start, StringCount count) const { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ((const StringInterface*) this)->GetPart(std::forward<StringPosition>(start), std::forward<StringCount>(count)); return nullptr;}
		StringInterface* ToUpper() const { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ((const StringInterface*) this)->ToUpper(); return nullptr;}
		StringInterface* ToLower() const { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ((const StringInterface*) this)->ToLower(); return nullptr;}
		COMPARERESULT ComparePart(const StringInterface* str, STRINGCOMPARISON mode, StringPosition position, StringCount count) const { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ((const StringInterface*) this)->ComparePart(str, mode, std::forward<StringPosition>(position), std::forward<StringCount>(count)); return HXXRET3(UNRESOLVED, COMPARERESULT);}
		HashInt GetHashCode() const { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ((const StringInterface*) this)->GetHashCode(); return HXXRET3(UNRESOLVED, HashInt);}
		UniqueHash GetUniqueHashCode() const { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ((const StringInterface*) this)->GetUniqueHashCode(); return HXXRET3(UNRESOLVED, UniqueHash);}
		void SetChar(Int pos, Utf32Char ch) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ((StringInterface*) this)->SetChar(pos, ch); return maxon::PrivateLogNullptrError();}
		Utf32Char GetChar(Int pos) const { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ((const StringInterface*) this)->GetChar(pos); return 0;}
		Result<void> GetUtf32(Utf32CharBuffer& stringData) const { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return ((const StringInterface*) this)->GetUtf32(stringData); return HXXRET1(UNRESOLVED);}
		Result<void> TrimLeft() { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return ((StringInterface*) this)->TrimLeft(); return HXXRET1(UNRESOLVED);}
		Result<void> TrimRight() { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return ((StringInterface*) this)->TrimRight(); return HXXRET1(UNRESOLVED);}
		Result<void> Split(const String& splitSymbol, Bool trim, const ValueReceiver<const String&>& parts) const { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return ((const StringInterface*) this)->Split(splitSymbol, trim, parts); return HXXRET1(UNRESOLVED);}
		Result<Int> Replace(Utf32Char find, Utf32Char replace) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return ((StringInterface*) this)->Replace(find, replace); return HXXRET1(UNRESOLVED);}
		Result<Int> Replace(const String& find, const String& replace) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return ((StringInterface*) this)->Replace(find, replace); return HXXRET1(UNRESOLVED);}
		Result<Int> Replace(Utf32Char find, const String& replace) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return ((StringInterface*) this)->Replace(find, replace); return HXXRET1(UNRESOLVED);}
		static StringInterface* Alloc(const maxon::SourceLocation& allocLocation) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return StringInterface::Alloc(allocLocation); return nullptr;}
		static StringInterface* Alloc(const maxon::SourceLocation& allocLocation, const StringInterface& object) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return StringInterface::Alloc(allocLocation, object); return nullptr;}
		Result<Int> GetCStringBlock(const Block<Char>& buffer, const StringEncodingRef& stringEncoding) const { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return ((const StringInterface*) this)->GetCStringBlock(buffer, stringEncoding); return HXXRET1(UNRESOLVED);}
		Result<void> GetCStringAppendArray(const NonConstArray<Char>& array, const StringEncodingRef& stringEncoding) const { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return ((const StringInterface*) this)->GetCStringAppendArray(array, stringEncoding); return HXXRET1(UNRESOLVED);}
		Result<BaseArray<Char>> GetCString(const StringEncodingRef& stringEncoding) const { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return ((const StringInterface*) this)->GetCString(stringEncoding); return HXXRET1(UNRESOLVED);}
		Result<void> SetCString(const Char* buffer, Int count, const StringDecodingRef& stringDecoding) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return ((StringInterface*) this)->SetCString(buffer, count, stringDecoding); return HXXRET1(UNRESOLVED);}
		Result<SysCharArray> GetSystemEncoding() const { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return ((const StringInterface*) this)->GetSystemEncoding(); return HXXRET1(UNRESOLVED);}
		Result<void> SetSystemEncoding(const SysChar* buffer, Int count) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return ((StringInterface*) this)->SetSystemEncoding(buffer, count); return HXXRET1(UNRESOLVED);}
		Result<void> SetUtf32(const Utf32Char* buffer, Int count) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return ((StringInterface*) this)->SetUtf32(buffer, count); return HXXRET1(UNRESOLVED);}
		Result<void> GetUtf16(Utf16CharBuffer& stringData) const { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return ((const StringInterface*) this)->GetUtf16(stringData); return HXXRET1(UNRESOLVED);}
		Result<void> SetUtf16(const Utf16Char* buffer, Int count) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return ((StringInterface*) this)->SetUtf16(buffer, count); return HXXRET1(UNRESOLVED);}
		static const String& GetAndCacheConstString(const wchar_t* chr, Int len) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return StringInterface::GetAndCacheConstString(chr, len); return HXXRET3(UNRESOLVED, const String&);}
		static const String& GetAndCacheConstString(const Char* chr, Int len, Int isUtf8) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return StringInterface::GetAndCacheConstString(chr, len, isUtf8); return HXXRET3(UNRESOLVED, const String&);}
		static String PrivateEnumToString(const EnumInfo& info, UInt64 value, const FormatStatement* formatStatement) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return StringInterface::PrivateEnumToString(info, value, formatStatement); return HXXRET3(UNRESOLVED, String);}
		StridedBlock<const Generic> GetVariableInternalData() const { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ((const StringInterface*) this)->GetVariableInternalData(); return HXXRET3(UNRESOLVED, StridedBlock<const Generic>);}
		Int GetCharacterWidth() const { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ((const StringInterface*) this)->GetCharacterWidth(); return 0;}
		Result<String> Prettify(Int indent, const String& indentStr, Int breakUpThreshold, Bool angularBrackets) const { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return ((const StringInterface*) this)->Prettify(indent, indentStr, breakUpThreshold, angularBrackets); return HXXRET1(UNRESOLVED);}
	};
	MAXON_WARNING_POP
#ifdef PRIVATE_MAXON_ASSEMBLE_UNRESOLVED
	const maxon::UNRESOLVED_RETURN_TYPE StringInterface::MTable::_returnTypes[] = 
	{
		maxon::UNRESOLVED_RETURN_TYPE::VOID_ZERO_FREE_FUNCTION,
		maxon::details::UnresolvedReturnType<Int>::value | maxon::UNRESOLVED_RETURN_TYPE::MEMBER_FUNCTION_FLAG,
		maxon::details::UnresolvedReturnType<Result<void>>::value | maxon::UNRESOLVED_RETURN_TYPE::MEMBER_FUNCTION_FLAG,
		maxon::details::UnresolvedReturnType<Result<void>>::value | maxon::UNRESOLVED_RETURN_TYPE::MEMBER_FUNCTION_FLAG,
		maxon::details::UnresolvedReturnType<Result<void>>::value | maxon::UNRESOLVED_RETURN_TYPE::MEMBER_FUNCTION_FLAG,
		maxon::details::UnresolvedReturnType<Result<void>>::value | maxon::UNRESOLVED_RETURN_TYPE::MEMBER_FUNCTION_FLAG,
		maxon::details::UnresolvedReturnType<Int>::value | maxon::UNRESOLVED_RETURN_TYPE::MEMBER_FUNCTION_FLAG,
		maxon::details::UnresolvedReturnType<Int>::value | maxon::UNRESOLVED_RETURN_TYPE::MEMBER_FUNCTION_FLAG,
		maxon::details::UnresolvedReturnType<Int>::value | maxon::UNRESOLVED_RETURN_TYPE::MEMBER_FUNCTION_FLAG,
		maxon::details::UnresolvedReturnType<Int>::value | maxon::UNRESOLVED_RETURN_TYPE::MEMBER_FUNCTION_FLAG,
		maxon::details::UnresolvedReturnType<Int>::value | maxon::UNRESOLVED_RETURN_TYPE::MEMBER_FUNCTION_FLAG,
		maxon::details::UnresolvedReturnType<Int>::value | maxon::UNRESOLVED_RETURN_TYPE::MEMBER_FUNCTION_FLAG,
		maxon::details::UnresolvedReturnType<Result<void>>::value | maxon::UNRESOLVED_RETURN_TYPE::MEMBER_FUNCTION_FLAG,
		maxon::details::UnresolvedReturnType<Result<void>>::value | maxon::UNRESOLVED_RETURN_TYPE::MEMBER_FUNCTION_FLAG,
		maxon::details::UnresolvedReturnType<Result<void>>::value | maxon::UNRESOLVED_RETURN_TYPE::MEMBER_FUNCTION_FLAG,
		maxon::details::UnresolvedReturnType<StringInterface*>::value | maxon::UNRESOLVED_RETURN_TYPE::MEMBER_FUNCTION_FLAG,
		maxon::details::UnresolvedReturnType<StringInterface*>::value | maxon::UNRESOLVED_RETURN_TYPE::MEMBER_FUNCTION_FLAG,
		maxon::details::UnresolvedReturnType<StringInterface*>::value | maxon::UNRESOLVED_RETURN_TYPE::MEMBER_FUNCTION_FLAG,
		maxon::details::UnresolvedReturnType<COMPARERESULT>::value | maxon::UNRESOLVED_RETURN_TYPE::MEMBER_FUNCTION_FLAG,
		maxon::details::UnresolvedReturnType<HashInt>::value | maxon::UNRESOLVED_RETURN_TYPE::MEMBER_FUNCTION_FLAG,
		maxon::details::UnresolvedReturnType<UniqueHash>::value | maxon::UNRESOLVED_RETURN_TYPE::MEMBER_FUNCTION_FLAG,
		maxon::details::UnresolvedReturnType<void>::value | maxon::UNRESOLVED_RETURN_TYPE::MEMBER_FUNCTION_FLAG,
		maxon::details::UnresolvedReturnType<Utf32Char>::value | maxon::UNRESOLVED_RETURN_TYPE::MEMBER_FUNCTION_FLAG,
		maxon::details::UnresolvedReturnType<Result<void>>::value | maxon::UNRESOLVED_RETURN_TYPE::MEMBER_FUNCTION_FLAG,
		maxon::details::UnresolvedReturnType<Result<void>>::value | maxon::UNRESOLVED_RETURN_TYPE::MEMBER_FUNCTION_FLAG,
		maxon::details::UnresolvedReturnType<Result<void>>::value | maxon::UNRESOLVED_RETURN_TYPE::MEMBER_FUNCTION_FLAG,
		maxon::details::UnresolvedReturnType<Result<void>>::value | maxon::UNRESOLVED_RETURN_TYPE::MEMBER_FUNCTION_FLAG,
		maxon::details::UnresolvedReturnType<Result<Int>>::value | maxon::UNRESOLVED_RETURN_TYPE::MEMBER_FUNCTION_FLAG,
		maxon::details::UnresolvedReturnType<Result<Int>>::value | maxon::UNRESOLVED_RETURN_TYPE::MEMBER_FUNCTION_FLAG,
		maxon::details::UnresolvedReturnType<Result<Int>>::value | maxon::UNRESOLVED_RETURN_TYPE::MEMBER_FUNCTION_FLAG,
		maxon::details::UnresolvedReturnType<StringInterface*>::value,
		maxon::details::UnresolvedReturnType<StringInterface*>::value,
		maxon::details::UnresolvedReturnType<Result<Int>>::value | maxon::UNRESOLVED_RETURN_TYPE::MEMBER_FUNCTION_FLAG,
		maxon::details::UnresolvedReturnType<Result<void>>::value | maxon::UNRESOLVED_RETURN_TYPE::MEMBER_FUNCTION_FLAG,
		maxon::details::UnresolvedReturnType<Result<BaseArray<Char>>>::value | maxon::UNRESOLVED_RETURN_TYPE::MEMBER_FUNCTION_FLAG,
		maxon::details::UnresolvedReturnType<Result<void>>::value | maxon::UNRESOLVED_RETURN_TYPE::MEMBER_FUNCTION_FLAG,
		maxon::details::UnresolvedReturnType<Result<SysCharArray>>::value | maxon::UNRESOLVED_RETURN_TYPE::MEMBER_FUNCTION_FLAG,
		maxon::details::UnresolvedReturnType<Result<void>>::value | maxon::UNRESOLVED_RETURN_TYPE::MEMBER_FUNCTION_FLAG,
		maxon::details::UnresolvedReturnType<Result<void>>::value | maxon::UNRESOLVED_RETURN_TYPE::MEMBER_FUNCTION_FLAG,
		maxon::details::UnresolvedReturnType<Result<void>>::value | maxon::UNRESOLVED_RETURN_TYPE::MEMBER_FUNCTION_FLAG,
		maxon::details::UnresolvedReturnType<Result<void>>::value | maxon::UNRESOLVED_RETURN_TYPE::MEMBER_FUNCTION_FLAG,
		maxon::details::UnresolvedReturnType<const String&>::value,
		maxon::details::UnresolvedReturnType<const String&>::value,
		maxon::details::UnresolvedReturnType<String>::value,
		maxon::details::UnresolvedReturnType<StridedBlock<const Generic>>::value | maxon::UNRESOLVED_RETURN_TYPE::MEMBER_FUNCTION_FLAG,
		maxon::details::UnresolvedReturnType<Int>::value | maxon::UNRESOLVED_RETURN_TYPE::MEMBER_FUNCTION_FLAG,
		maxon::details::UnresolvedReturnType<Result<String>>::value | maxon::UNRESOLVED_RETURN_TYPE::MEMBER_FUNCTION_FLAG,
		maxon::UNRESOLVED_RETURN_TYPE::OTHER
	};
#endif
	maxon::Bool StringInterface::MTable::InitUnresolved(maxon::NonvirtualInterfaceReference::UnresolvedAssembler assembler, MTable* tbl)
	{
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->StringInterface_Free = PRIVATE_MAXON_MF_CAST(decltype(StringInterface_Free), &Hxx2::Wrapper<Hxx2::Unresolved>::StringInterface_Free);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->StringInterface_GetLength = PRIVATE_MAXON_MF_CAST(decltype(StringInterface_GetLength), &Hxx2::Wrapper<Hxx2::Unresolved>::StringInterface_GetLength);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if constexpr (maxon::details::UnresolvedReturnType<Result<void>>::value == maxon::UNRESOLVED_RETURN_TYPE::OTHER) tbl->StringInterface_Init = PRIVATE_MAXON_MF_CAST(decltype(StringInterface_Init), &Hxx2::Wrapper<Hxx2::Unresolved>::StringInterface_Init);
		#else
		tbl->StringInterface_Init = PRIVATE_MAXON_MF_CAST(decltype(StringInterface_Init), &Hxx2::Wrapper<Hxx2::Unresolved>::StringInterface_Init);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if constexpr (maxon::details::UnresolvedReturnType<Result<void>>::value == maxon::UNRESOLVED_RETURN_TYPE::OTHER) tbl->StringInterface_Shrink = PRIVATE_MAXON_MF_CAST(decltype(StringInterface_Shrink), &Hxx2::Wrapper<Hxx2::Unresolved>::StringInterface_Shrink);
		#else
		tbl->StringInterface_Shrink = PRIVATE_MAXON_MF_CAST(decltype(StringInterface_Shrink), &Hxx2::Wrapper<Hxx2::Unresolved>::StringInterface_Shrink);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if constexpr (maxon::details::UnresolvedReturnType<Result<void>>::value == maxon::UNRESOLVED_RETURN_TYPE::OTHER) tbl->StringInterface_Append = PRIVATE_MAXON_MF_CAST(decltype(StringInterface_Append), &Hxx2::Wrapper<Hxx2::Unresolved>::StringInterface_Append);
		#else
		tbl->StringInterface_Append = PRIVATE_MAXON_MF_CAST(decltype(StringInterface_Append), &Hxx2::Wrapper<Hxx2::Unresolved>::StringInterface_Append);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if constexpr (maxon::details::UnresolvedReturnType<Result<void>>::value == maxon::UNRESOLVED_RETURN_TYPE::OTHER) tbl->StringInterface_Append_1 = PRIVATE_MAXON_MF_CAST(decltype(StringInterface_Append_1), &Hxx2::Wrapper<Hxx2::Unresolved>::StringInterface_Append_1);
		#else
		tbl->StringInterface_Append_1 = PRIVATE_MAXON_MF_CAST(decltype(StringInterface_Append_1), &Hxx2::Wrapper<Hxx2::Unresolved>::StringInterface_Append_1);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->StringInterface_FindIndex = PRIVATE_MAXON_MF_CAST(decltype(StringInterface_FindIndex), &Hxx2::Wrapper<Hxx2::Unresolved>::StringInterface_FindIndex);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->StringInterface_FindLastIndex = PRIVATE_MAXON_MF_CAST(decltype(StringInterface_FindLastIndex), &Hxx2::Wrapper<Hxx2::Unresolved>::StringInterface_FindLastIndex);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->StringInterface_FindIndex_1 = PRIVATE_MAXON_MF_CAST(decltype(StringInterface_FindIndex_1), &Hxx2::Wrapper<Hxx2::Unresolved>::StringInterface_FindIndex_1);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->StringInterface_FindLastIndex_1 = PRIVATE_MAXON_MF_CAST(decltype(StringInterface_FindLastIndex_1), &Hxx2::Wrapper<Hxx2::Unresolved>::StringInterface_FindLastIndex_1);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->StringInterface_FindUpperIndex = PRIVATE_MAXON_MF_CAST(decltype(StringInterface_FindUpperIndex), &Hxx2::Wrapper<Hxx2::Unresolved>::StringInterface_FindUpperIndex);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->StringInterface_FindLastUpperIndex = PRIVATE_MAXON_MF_CAST(decltype(StringInterface_FindLastUpperIndex), &Hxx2::Wrapper<Hxx2::Unresolved>::StringInterface_FindLastUpperIndex);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if constexpr (maxon::details::UnresolvedReturnType<Result<void>>::value == maxon::UNRESOLVED_RETURN_TYPE::OTHER) tbl->StringInterface_Erase = PRIVATE_MAXON_MF_CAST(decltype(StringInterface_Erase), &Hxx2::Wrapper<Hxx2::Unresolved>::StringInterface_Erase);
		#else
		tbl->StringInterface_Erase = PRIVATE_MAXON_MF_CAST(decltype(StringInterface_Erase), &Hxx2::Wrapper<Hxx2::Unresolved>::StringInterface_Erase);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if constexpr (maxon::details::UnresolvedReturnType<Result<void>>::value == maxon::UNRESOLVED_RETURN_TYPE::OTHER) tbl->StringInterface_Insert = PRIVATE_MAXON_MF_CAST(decltype(StringInterface_Insert), &Hxx2::Wrapper<Hxx2::Unresolved>::StringInterface_Insert);
		#else
		tbl->StringInterface_Insert = PRIVATE_MAXON_MF_CAST(decltype(StringInterface_Insert), &Hxx2::Wrapper<Hxx2::Unresolved>::StringInterface_Insert);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if constexpr (maxon::details::UnresolvedReturnType<Result<void>>::value == maxon::UNRESOLVED_RETURN_TYPE::OTHER) tbl->StringInterface_Insert_1 = PRIVATE_MAXON_MF_CAST(decltype(StringInterface_Insert_1), &Hxx2::Wrapper<Hxx2::Unresolved>::StringInterface_Insert_1);
		#else
		tbl->StringInterface_Insert_1 = PRIVATE_MAXON_MF_CAST(decltype(StringInterface_Insert_1), &Hxx2::Wrapper<Hxx2::Unresolved>::StringInterface_Insert_1);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->StringInterface_GetPart = PRIVATE_MAXON_MF_CAST(decltype(StringInterface_GetPart), &Hxx2::Wrapper<Hxx2::Unresolved>::StringInterface_GetPart);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->StringInterface_ToUpper = PRIVATE_MAXON_MF_CAST(decltype(StringInterface_ToUpper), &Hxx2::Wrapper<Hxx2::Unresolved>::StringInterface_ToUpper);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->StringInterface_ToLower = PRIVATE_MAXON_MF_CAST(decltype(StringInterface_ToLower), &Hxx2::Wrapper<Hxx2::Unresolved>::StringInterface_ToLower);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if constexpr (maxon::details::UnresolvedReturnType<COMPARERESULT>::value == maxon::UNRESOLVED_RETURN_TYPE::OTHER) tbl->StringInterface_ComparePart = PRIVATE_MAXON_MF_CAST(decltype(StringInterface_ComparePart), &Hxx2::Wrapper<Hxx2::Unresolved>::StringInterface_ComparePart);
		#else
		tbl->StringInterface_ComparePart = PRIVATE_MAXON_MF_CAST(decltype(StringInterface_ComparePart), &Hxx2::Wrapper<Hxx2::Unresolved>::StringInterface_ComparePart);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if constexpr (maxon::details::UnresolvedReturnType<HashInt>::value == maxon::UNRESOLVED_RETURN_TYPE::OTHER) tbl->StringInterface_GetHashCode = PRIVATE_MAXON_MF_CAST(decltype(StringInterface_GetHashCode), &Hxx2::Wrapper<Hxx2::Unresolved>::StringInterface_GetHashCode);
		#else
		tbl->StringInterface_GetHashCode = PRIVATE_MAXON_MF_CAST(decltype(StringInterface_GetHashCode), &Hxx2::Wrapper<Hxx2::Unresolved>::StringInterface_GetHashCode);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if constexpr (maxon::details::UnresolvedReturnType<UniqueHash>::value == maxon::UNRESOLVED_RETURN_TYPE::OTHER) tbl->StringInterface_GetUniqueHashCode = PRIVATE_MAXON_MF_CAST(decltype(StringInterface_GetUniqueHashCode), &Hxx2::Wrapper<Hxx2::Unresolved>::StringInterface_GetUniqueHashCode);
		#else
		tbl->StringInterface_GetUniqueHashCode = PRIVATE_MAXON_MF_CAST(decltype(StringInterface_GetUniqueHashCode), &Hxx2::Wrapper<Hxx2::Unresolved>::StringInterface_GetUniqueHashCode);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->StringInterface_SetChar = PRIVATE_MAXON_MF_CAST(decltype(StringInterface_SetChar), &Hxx2::Wrapper<Hxx2::Unresolved>::StringInterface_SetChar);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->StringInterface_GetChar = PRIVATE_MAXON_MF_CAST(decltype(StringInterface_GetChar), &Hxx2::Wrapper<Hxx2::Unresolved>::StringInterface_GetChar);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if constexpr (maxon::details::UnresolvedReturnType<Result<void>>::value == maxon::UNRESOLVED_RETURN_TYPE::OTHER) tbl->StringInterface_GetUtf32 = PRIVATE_MAXON_MF_CAST(decltype(StringInterface_GetUtf32), &Hxx2::Wrapper<Hxx2::Unresolved>::StringInterface_GetUtf32);
		#else
		tbl->StringInterface_GetUtf32 = PRIVATE_MAXON_MF_CAST(decltype(StringInterface_GetUtf32), &Hxx2::Wrapper<Hxx2::Unresolved>::StringInterface_GetUtf32);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if constexpr (maxon::details::UnresolvedReturnType<Result<void>>::value == maxon::UNRESOLVED_RETURN_TYPE::OTHER) tbl->StringInterface_TrimLeft = PRIVATE_MAXON_MF_CAST(decltype(StringInterface_TrimLeft), &Hxx2::Wrapper<Hxx2::Unresolved>::StringInterface_TrimLeft);
		#else
		tbl->StringInterface_TrimLeft = PRIVATE_MAXON_MF_CAST(decltype(StringInterface_TrimLeft), &Hxx2::Wrapper<Hxx2::Unresolved>::StringInterface_TrimLeft);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if constexpr (maxon::details::UnresolvedReturnType<Result<void>>::value == maxon::UNRESOLVED_RETURN_TYPE::OTHER) tbl->StringInterface_TrimRight = PRIVATE_MAXON_MF_CAST(decltype(StringInterface_TrimRight), &Hxx2::Wrapper<Hxx2::Unresolved>::StringInterface_TrimRight);
		#else
		tbl->StringInterface_TrimRight = PRIVATE_MAXON_MF_CAST(decltype(StringInterface_TrimRight), &Hxx2::Wrapper<Hxx2::Unresolved>::StringInterface_TrimRight);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if constexpr (maxon::details::UnresolvedReturnType<Result<void>>::value == maxon::UNRESOLVED_RETURN_TYPE::OTHER) tbl->StringInterface_Split = PRIVATE_MAXON_MF_CAST(decltype(StringInterface_Split), &Hxx2::Wrapper<Hxx2::Unresolved>::StringInterface_Split);
		#else
		tbl->StringInterface_Split = PRIVATE_MAXON_MF_CAST(decltype(StringInterface_Split), &Hxx2::Wrapper<Hxx2::Unresolved>::StringInterface_Split);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if constexpr (maxon::details::UnresolvedReturnType<Result<Int>>::value == maxon::UNRESOLVED_RETURN_TYPE::OTHER) tbl->StringInterface_Replace = PRIVATE_MAXON_MF_CAST(decltype(StringInterface_Replace), &Hxx2::Wrapper<Hxx2::Unresolved>::StringInterface_Replace);
		#else
		tbl->StringInterface_Replace = PRIVATE_MAXON_MF_CAST(decltype(StringInterface_Replace), &Hxx2::Wrapper<Hxx2::Unresolved>::StringInterface_Replace);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if constexpr (maxon::details::UnresolvedReturnType<Result<Int>>::value == maxon::UNRESOLVED_RETURN_TYPE::OTHER) tbl->StringInterface_Replace_1 = PRIVATE_MAXON_MF_CAST(decltype(StringInterface_Replace_1), &Hxx2::Wrapper<Hxx2::Unresolved>::StringInterface_Replace_1);
		#else
		tbl->StringInterface_Replace_1 = PRIVATE_MAXON_MF_CAST(decltype(StringInterface_Replace_1), &Hxx2::Wrapper<Hxx2::Unresolved>::StringInterface_Replace_1);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if constexpr (maxon::details::UnresolvedReturnType<Result<Int>>::value == maxon::UNRESOLVED_RETURN_TYPE::OTHER) tbl->StringInterface_Replace_2 = PRIVATE_MAXON_MF_CAST(decltype(StringInterface_Replace_2), &Hxx2::Wrapper<Hxx2::Unresolved>::StringInterface_Replace_2);
		#else
		tbl->StringInterface_Replace_2 = PRIVATE_MAXON_MF_CAST(decltype(StringInterface_Replace_2), &Hxx2::Wrapper<Hxx2::Unresolved>::StringInterface_Replace_2);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->StringInterface_Alloc = PRIVATE_MAXON_MF_CAST(decltype(StringInterface_Alloc), &Hxx2::Wrapper<Hxx2::Unresolved>::StringInterface_Alloc);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->StringInterface_Alloc_1 = PRIVATE_MAXON_MF_CAST(decltype(StringInterface_Alloc_1), &Hxx2::Wrapper<Hxx2::Unresolved>::StringInterface_Alloc_1);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if constexpr (maxon::details::UnresolvedReturnType<Result<Int>>::value == maxon::UNRESOLVED_RETURN_TYPE::OTHER) tbl->StringInterface_GetCStringBlock = PRIVATE_MAXON_MF_CAST(decltype(StringInterface_GetCStringBlock), &Hxx2::Wrapper<Hxx2::Unresolved>::StringInterface_GetCStringBlock);
		#else
		tbl->StringInterface_GetCStringBlock = PRIVATE_MAXON_MF_CAST(decltype(StringInterface_GetCStringBlock), &Hxx2::Wrapper<Hxx2::Unresolved>::StringInterface_GetCStringBlock);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if constexpr (maxon::details::UnresolvedReturnType<Result<void>>::value == maxon::UNRESOLVED_RETURN_TYPE::OTHER) tbl->StringInterface_GetCStringAppendArray = PRIVATE_MAXON_MF_CAST(decltype(StringInterface_GetCStringAppendArray), &Hxx2::Wrapper<Hxx2::Unresolved>::StringInterface_GetCStringAppendArray);
		#else
		tbl->StringInterface_GetCStringAppendArray = PRIVATE_MAXON_MF_CAST(decltype(StringInterface_GetCStringAppendArray), &Hxx2::Wrapper<Hxx2::Unresolved>::StringInterface_GetCStringAppendArray);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if constexpr (maxon::details::UnresolvedReturnType<Result<BaseArray<Char>>>::value == maxon::UNRESOLVED_RETURN_TYPE::OTHER) tbl->StringInterface_GetCString = PRIVATE_MAXON_MF_CAST(decltype(StringInterface_GetCString), &Hxx2::Wrapper<Hxx2::Unresolved>::StringInterface_GetCString);
		#else
		tbl->StringInterface_GetCString = PRIVATE_MAXON_MF_CAST(decltype(StringInterface_GetCString), &Hxx2::Wrapper<Hxx2::Unresolved>::StringInterface_GetCString);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if constexpr (maxon::details::UnresolvedReturnType<Result<void>>::value == maxon::UNRESOLVED_RETURN_TYPE::OTHER) tbl->StringInterface_SetCString = PRIVATE_MAXON_MF_CAST(decltype(StringInterface_SetCString), &Hxx2::Wrapper<Hxx2::Unresolved>::StringInterface_SetCString);
		#else
		tbl->StringInterface_SetCString = PRIVATE_MAXON_MF_CAST(decltype(StringInterface_SetCString), &Hxx2::Wrapper<Hxx2::Unresolved>::StringInterface_SetCString);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if constexpr (maxon::details::UnresolvedReturnType<Result<SysCharArray>>::value == maxon::UNRESOLVED_RETURN_TYPE::OTHER) tbl->StringInterface_GetSystemEncoding = PRIVATE_MAXON_MF_CAST(decltype(StringInterface_GetSystemEncoding), &Hxx2::Wrapper<Hxx2::Unresolved>::StringInterface_GetSystemEncoding);
		#else
		tbl->StringInterface_GetSystemEncoding = PRIVATE_MAXON_MF_CAST(decltype(StringInterface_GetSystemEncoding), &Hxx2::Wrapper<Hxx2::Unresolved>::StringInterface_GetSystemEncoding);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if constexpr (maxon::details::UnresolvedReturnType<Result<void>>::value == maxon::UNRESOLVED_RETURN_TYPE::OTHER) tbl->StringInterface_SetSystemEncoding = PRIVATE_MAXON_MF_CAST(decltype(StringInterface_SetSystemEncoding), &Hxx2::Wrapper<Hxx2::Unresolved>::StringInterface_SetSystemEncoding);
		#else
		tbl->StringInterface_SetSystemEncoding = PRIVATE_MAXON_MF_CAST(decltype(StringInterface_SetSystemEncoding), &Hxx2::Wrapper<Hxx2::Unresolved>::StringInterface_SetSystemEncoding);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if constexpr (maxon::details::UnresolvedReturnType<Result<void>>::value == maxon::UNRESOLVED_RETURN_TYPE::OTHER) tbl->StringInterface_SetUtf32 = PRIVATE_MAXON_MF_CAST(decltype(StringInterface_SetUtf32), &Hxx2::Wrapper<Hxx2::Unresolved>::StringInterface_SetUtf32);
		#else
		tbl->StringInterface_SetUtf32 = PRIVATE_MAXON_MF_CAST(decltype(StringInterface_SetUtf32), &Hxx2::Wrapper<Hxx2::Unresolved>::StringInterface_SetUtf32);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if constexpr (maxon::details::UnresolvedReturnType<Result<void>>::value == maxon::UNRESOLVED_RETURN_TYPE::OTHER) tbl->StringInterface_GetUtf16 = PRIVATE_MAXON_MF_CAST(decltype(StringInterface_GetUtf16), &Hxx2::Wrapper<Hxx2::Unresolved>::StringInterface_GetUtf16);
		#else
		tbl->StringInterface_GetUtf16 = PRIVATE_MAXON_MF_CAST(decltype(StringInterface_GetUtf16), &Hxx2::Wrapper<Hxx2::Unresolved>::StringInterface_GetUtf16);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if constexpr (maxon::details::UnresolvedReturnType<Result<void>>::value == maxon::UNRESOLVED_RETURN_TYPE::OTHER) tbl->StringInterface_SetUtf16 = PRIVATE_MAXON_MF_CAST(decltype(StringInterface_SetUtf16), &Hxx2::Wrapper<Hxx2::Unresolved>::StringInterface_SetUtf16);
		#else
		tbl->StringInterface_SetUtf16 = PRIVATE_MAXON_MF_CAST(decltype(StringInterface_SetUtf16), &Hxx2::Wrapper<Hxx2::Unresolved>::StringInterface_SetUtf16);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if constexpr (maxon::details::UnresolvedReturnType<const String&>::value == maxon::UNRESOLVED_RETURN_TYPE::OTHER) tbl->StringInterface_GetAndCacheConstString = PRIVATE_MAXON_MF_CAST(decltype(StringInterface_GetAndCacheConstString), &Hxx2::Wrapper<Hxx2::Unresolved>::StringInterface_GetAndCacheConstString);
		#else
		tbl->StringInterface_GetAndCacheConstString = PRIVATE_MAXON_MF_CAST(decltype(StringInterface_GetAndCacheConstString), &Hxx2::Wrapper<Hxx2::Unresolved>::StringInterface_GetAndCacheConstString);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if constexpr (maxon::details::UnresolvedReturnType<const String&>::value == maxon::UNRESOLVED_RETURN_TYPE::OTHER) tbl->StringInterface_GetAndCacheConstString_1 = PRIVATE_MAXON_MF_CAST(decltype(StringInterface_GetAndCacheConstString_1), &Hxx2::Wrapper<Hxx2::Unresolved>::StringInterface_GetAndCacheConstString_1);
		#else
		tbl->StringInterface_GetAndCacheConstString_1 = PRIVATE_MAXON_MF_CAST(decltype(StringInterface_GetAndCacheConstString_1), &Hxx2::Wrapper<Hxx2::Unresolved>::StringInterface_GetAndCacheConstString_1);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if constexpr (maxon::details::UnresolvedReturnType<String>::value == maxon::UNRESOLVED_RETURN_TYPE::OTHER) tbl->StringInterface_PrivateEnumToString = PRIVATE_MAXON_MF_CAST(decltype(StringInterface_PrivateEnumToString), &Hxx2::Wrapper<Hxx2::Unresolved>::StringInterface_PrivateEnumToString);
		#else
		tbl->StringInterface_PrivateEnumToString = PRIVATE_MAXON_MF_CAST(decltype(StringInterface_PrivateEnumToString), &Hxx2::Wrapper<Hxx2::Unresolved>::StringInterface_PrivateEnumToString);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if constexpr (maxon::details::UnresolvedReturnType<StridedBlock<const Generic>>::value == maxon::UNRESOLVED_RETURN_TYPE::OTHER) tbl->StringInterface_GetVariableInternalData = PRIVATE_MAXON_MF_CAST(decltype(StringInterface_GetVariableInternalData), &Hxx2::Wrapper<Hxx2::Unresolved>::StringInterface_GetVariableInternalData);
		#else
		tbl->StringInterface_GetVariableInternalData = PRIVATE_MAXON_MF_CAST(decltype(StringInterface_GetVariableInternalData), &Hxx2::Wrapper<Hxx2::Unresolved>::StringInterface_GetVariableInternalData);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->StringInterface_GetCharacterWidth = PRIVATE_MAXON_MF_CAST(decltype(StringInterface_GetCharacterWidth), &Hxx2::Wrapper<Hxx2::Unresolved>::StringInterface_GetCharacterWidth);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if constexpr (maxon::details::UnresolvedReturnType<Result<String>>::value == maxon::UNRESOLVED_RETURN_TYPE::OTHER) tbl->StringInterface_Prettify = PRIVATE_MAXON_MF_CAST(decltype(StringInterface_Prettify), &Hxx2::Wrapper<Hxx2::Unresolved>::StringInterface_Prettify);
		#else
		tbl->StringInterface_Prettify = PRIVATE_MAXON_MF_CAST(decltype(StringInterface_Prettify), &Hxx2::Wrapper<Hxx2::Unresolved>::StringInterface_Prettify);
		#endif
	#ifdef PRIVATE_MAXON_ASSEMBLE_UNRESOLVED
		return assembler(&_interface, (const void**) tbl, _returnTypes, SIZEOF(MTable) / SIZEOF(void*));
	#else
		return true;
	#endif
	}
	MAXON_INTERFACE_REGISTER(StringInterface, "net.maxon.interface.string", nullptr, maxon::EntityBase::FLAGS::NONE);
	template <typename DUMMY> maxon::Int StringInterface::PrivateInstantiateDefaultValueHelper()
	{
		return 0
		| maxon::details::InstantiateDefaultReturnValue<COMPARERESULT>(OVERLOAD_MAX_RANK)
		| maxon::details::InstantiateDefaultReturnValue<HashInt>(OVERLOAD_MAX_RANK)
		| maxon::details::InstantiateDefaultReturnValue<StridedBlock<const Generic>>(OVERLOAD_MAX_RANK)
		| maxon::details::InstantiateDefaultReturnValue<String>(OVERLOAD_MAX_RANK)
		| maxon::details::InstantiateDefaultReturnValue<UniqueHash>(OVERLOAD_MAX_RANK)
		| maxon::details::InstantiateDefaultReturnValue<const String&>(OVERLOAD_MAX_RANK)
		;
	}
	const maxon::Char* const CStringInterface::MTable::_ids = 
		"Free@5a84dd2e7cac25d9\0" // void Free(const CStringInterface* object)
		"GetLength@7d0e6f3d29c239e7\0" // Int GetLength() const
		"Init@10c0effb86660a\0" // Result<void> Init(Int count, Char fillChar)
		"Shrink@3008090429c5a175\0" // Result<void> Shrink()
		"Append@e41160450751013b\0" // Result<void> Append(const CStringInterface* str)
		"Append@8f8f0a471e97998f\0" // Result<void> Append(const Char* str, Int len)
		"FindIndex@b8ef4f842e701735\0" // Int FindIndex(const CStringInterface* str, StringPosition start) const
		"FindLastIndex@b8ef4f842e701735\0" // Int FindLastIndex(const CStringInterface* str, StringPosition start) const
		"FindIndex@14efd9a10bdfcbf7\0" // Int FindIndex(Char ch, StringPosition start) const
		"FindLastIndex@14efd9a10bdfcbf7\0" // Int FindLastIndex(Char ch, StringPosition start) const
		"FindUpperIndex@b8ef4f842e701735\0" // Int FindUpperIndex(const CStringInterface* str, StringPosition start) const
		"FindLastUpperIndex@b8ef4f842e701735\0" // Int FindLastUpperIndex(const CStringInterface* str, StringPosition start) const
		"Erase@68f553950fb89247\0" // Result<void> Erase(StringPosition position, StringCount count)
		"Insert@62f04ea1ea045287\0" // Result<void> Insert(StringPosition position, const CStringInterface* str, StringPosition strStart, StringCount strCount)
		"Insert@fe5200546f4fd70d\0" // Result<void> Insert(StringPosition position, Char ch)
		"GetPart@d5c1875ff6e8c6b\0" // INTERFACETYPE* GetPart(StringPosition start, StringCount count) const
		"ToUpper@4918d497368f34b9\0" // INTERFACETYPE* ToUpper() const
		"ToLower@4918d497368f34b9\0" // INTERFACETYPE* ToLower() const
		"ComparePart@819d254ba4126c02\0" // COMPARERESULT ComparePart(const CStringInterface* str, STRINGCOMPARISON mode, StringPosition position, StringCount count) const
		"GetHashCode@b22918402154097b\0" // HashInt GetHashCode() const
		"GetUniqueHashCode@c78267ca5e388263\0" // UniqueHash GetUniqueHashCode() const
		"SetChar@f18ddde32757b5bb\0" // void SetChar(Int pos, Char ch)
		"GetChar@7f11aacb091cce3b\0" // CHARTYPE GetChar(Int pos) const
		"GetUtf32@63a358e963be05f1\0" // Result<void> GetUtf32(Utf32CharBuffer& stringData) const
		"TrimLeft@3008090429c5a175\0" // Result<void> TrimLeft()
		"TrimRight@3008090429c5a175\0" // Result<void> TrimRight()
		"Split@aaa1a482f71df9e6\0" // Result<void> Split(const CString& splitSymbol, Bool trim, const ValueReceiver<const CString&>& parts) const
		"Replace@97979b611ded742\0" // Result<Int> Replace(Char find, Char replace)
		"Replace@3bb8e5a536791ba0\0" // Result<Int> Replace(const CString& find, const CString& replace)
		"Replace@40079b80a6b63309\0" // Result<Int> Replace(Char find, const CString& replace)
		"Alloc@df809f4bbe63f71a\0" // CStringInterface* Alloc(const maxon::SourceLocation& allocLocation)
		"Alloc@57a43f2cbaf9912e\0" // CStringInterface* Alloc(const maxon::SourceLocation& allocLocation, const CStringInterface& object)
		"GetCStringBlock@f922ec66666b3f56\0" // Result<Int> GetCStringBlock(const Block<Char>& buffer) const
		"GetCStringAppendArray@8b2df6dbd8e399f5\0" // Result<void> GetCStringAppendArray(const NonConstArray<Char>& array) const
		"Disconnect@949a29ccc36b3cf4\0" // Result<Block<Char>> Disconnect()
		"SetCString@8f8f0a471e97998f\0" // Result<void> SetCString(const Char* buffer, Int count)
		"GetCString@4d69fd8e19e6996f\0" // Result<BaseArray<Char>> GetCString() const
		"GetInternalData@760f6b0f3d05169a\0" // Block<const Char> GetInternalData() const
		"GetAndCacheConstString@c9e7738138e97bb6\0" // const CString& GetAndCacheConstString(const Char* chr, Int len)
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
		Result<void> Init(Int count, Char fillChar) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return ((CStringInterface*) this)->Init(count, fillChar); return HXXRET1(UNRESOLVED);}
		Result<void> Shrink() { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return ((CStringInterface*) this)->Shrink(); return HXXRET1(UNRESOLVED);}
		Result<void> Append(const CStringInterface* str) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return ((CStringInterface*) this)->Append(str); return HXXRET1(UNRESOLVED);}
		Result<void> Append(const Char* str, Int len) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return ((CStringInterface*) this)->Append(str, len); return HXXRET1(UNRESOLVED);}
		Int FindIndex(const CStringInterface* str, StringPosition start) const { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ((const CStringInterface*) this)->FindIndex(str, std::forward<StringPosition>(start)); return InvalidArrayIndex;}
		Int FindLastIndex(const CStringInterface* str, StringPosition start) const { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ((const CStringInterface*) this)->FindLastIndex(str, std::forward<StringPosition>(start)); return InvalidArrayIndex;}
		Int FindIndex(Char ch, StringPosition start) const { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ((const CStringInterface*) this)->FindIndex(ch, std::forward<StringPosition>(start)); return InvalidArrayIndex;}
		Int FindLastIndex(Char ch, StringPosition start) const { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ((const CStringInterface*) this)->FindLastIndex(ch, std::forward<StringPosition>(start)); return InvalidArrayIndex;}
		Int FindUpperIndex(const CStringInterface* str, StringPosition start) const { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ((const CStringInterface*) this)->FindUpperIndex(str, std::forward<StringPosition>(start)); return InvalidArrayIndex;}
		Int FindLastUpperIndex(const CStringInterface* str, StringPosition start) const { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ((const CStringInterface*) this)->FindLastUpperIndex(str, std::forward<StringPosition>(start)); return InvalidArrayIndex;}
		Result<void> Erase(StringPosition position, StringCount count) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return ((CStringInterface*) this)->Erase(std::forward<StringPosition>(position), std::forward<StringCount>(count)); return HXXRET1(UNRESOLVED);}
		Result<void> Insert(StringPosition position, const CStringInterface* str, StringPosition strStart, StringCount strCount) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return ((CStringInterface*) this)->Insert(std::forward<StringPosition>(position), str, std::forward<StringPosition>(strStart), std::forward<StringCount>(strCount)); return HXXRET1(UNRESOLVED);}
		Result<void> Insert(StringPosition position, Char ch) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return ((CStringInterface*) this)->Insert(std::forward<StringPosition>(position), ch); return HXXRET1(UNRESOLVED);}
		CStringInterface* GetPart(StringPosition start, StringCount count) const { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ((const CStringInterface*) this)->GetPart(std::forward<StringPosition>(start), std::forward<StringCount>(count)); return nullptr;}
		CStringInterface* ToUpper() const { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ((const CStringInterface*) this)->ToUpper(); return nullptr;}
		CStringInterface* ToLower() const { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ((const CStringInterface*) this)->ToLower(); return nullptr;}
		COMPARERESULT ComparePart(const CStringInterface* str, STRINGCOMPARISON mode, StringPosition position, StringCount count) const { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ((const CStringInterface*) this)->ComparePart(str, mode, std::forward<StringPosition>(position), std::forward<StringCount>(count)); return HXXRET3(UNRESOLVED, COMPARERESULT);}
		HashInt GetHashCode() const { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ((const CStringInterface*) this)->GetHashCode(); return HXXRET3(UNRESOLVED, HashInt);}
		UniqueHash GetUniqueHashCode() const { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ((const CStringInterface*) this)->GetUniqueHashCode(); return HXXRET3(UNRESOLVED, UniqueHash);}
		void SetChar(Int pos, Char ch) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ((CStringInterface*) this)->SetChar(pos, ch); return maxon::PrivateLogNullptrError();}
		Char GetChar(Int pos) const { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ((const CStringInterface*) this)->GetChar(pos); return 0;}
		Result<void> GetUtf32(Utf32CharBuffer& stringData) const { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return ((const CStringInterface*) this)->GetUtf32(stringData); return HXXRET1(UNRESOLVED);}
		Result<void> TrimLeft() { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return ((CStringInterface*) this)->TrimLeft(); return HXXRET1(UNRESOLVED);}
		Result<void> TrimRight() { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return ((CStringInterface*) this)->TrimRight(); return HXXRET1(UNRESOLVED);}
		Result<void> Split(const CString& splitSymbol, Bool trim, const ValueReceiver<const CString&>& parts) const { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return ((const CStringInterface*) this)->Split(splitSymbol, trim, parts); return HXXRET1(UNRESOLVED);}
		Result<Int> Replace(Char find, Char replace) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return ((CStringInterface*) this)->Replace(find, replace); return HXXRET1(UNRESOLVED);}
		Result<Int> Replace(const CString& find, const CString& replace) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return ((CStringInterface*) this)->Replace(find, replace); return HXXRET1(UNRESOLVED);}
		Result<Int> Replace(Char find, const CString& replace) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return ((CStringInterface*) this)->Replace(find, replace); return HXXRET1(UNRESOLVED);}
		static CStringInterface* Alloc(const maxon::SourceLocation& allocLocation) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return CStringInterface::Alloc(allocLocation); return nullptr;}
		static CStringInterface* Alloc(const maxon::SourceLocation& allocLocation, const CStringInterface& object) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return CStringInterface::Alloc(allocLocation, object); return nullptr;}
		Result<Int> GetCStringBlock(const Block<Char>& buffer) const { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return ((const CStringInterface*) this)->GetCStringBlock(buffer); return HXXRET1(UNRESOLVED);}
		Result<void> GetCStringAppendArray(const NonConstArray<Char>& array) const { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return ((const CStringInterface*) this)->GetCStringAppendArray(array); return HXXRET1(UNRESOLVED);}
		Result<Block<Char>> Disconnect() { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return ((CStringInterface*) this)->Disconnect(); return HXXRET1(UNRESOLVED);}
		Result<void> SetCString(const Char* buffer, Int count) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return ((CStringInterface*) this)->SetCString(buffer, count); return HXXRET1(UNRESOLVED);}
		Result<BaseArray<Char>> GetCString() const { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return ((const CStringInterface*) this)->GetCString(); return HXXRET1(UNRESOLVED);}
		Block<const Char> GetInternalData() const { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ((const CStringInterface*) this)->GetInternalData(); return HXXRET3(UNRESOLVED, Block<const Char>);}
		static const CString& GetAndCacheConstString(const Char* chr, Int len) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return CStringInterface::GetAndCacheConstString(chr, len); return HXXRET3(UNRESOLVED, const CString&);}
	};
	MAXON_WARNING_POP
#ifdef PRIVATE_MAXON_ASSEMBLE_UNRESOLVED
	const maxon::UNRESOLVED_RETURN_TYPE CStringInterface::MTable::_returnTypes[] = 
	{
		maxon::UNRESOLVED_RETURN_TYPE::VOID_ZERO_FREE_FUNCTION,
		maxon::details::UnresolvedReturnType<Int>::value | maxon::UNRESOLVED_RETURN_TYPE::MEMBER_FUNCTION_FLAG,
		maxon::details::UnresolvedReturnType<Result<void>>::value | maxon::UNRESOLVED_RETURN_TYPE::MEMBER_FUNCTION_FLAG,
		maxon::details::UnresolvedReturnType<Result<void>>::value | maxon::UNRESOLVED_RETURN_TYPE::MEMBER_FUNCTION_FLAG,
		maxon::details::UnresolvedReturnType<Result<void>>::value | maxon::UNRESOLVED_RETURN_TYPE::MEMBER_FUNCTION_FLAG,
		maxon::details::UnresolvedReturnType<Result<void>>::value | maxon::UNRESOLVED_RETURN_TYPE::MEMBER_FUNCTION_FLAG,
		maxon::details::UnresolvedReturnType<Int>::value | maxon::UNRESOLVED_RETURN_TYPE::MEMBER_FUNCTION_FLAG,
		maxon::details::UnresolvedReturnType<Int>::value | maxon::UNRESOLVED_RETURN_TYPE::MEMBER_FUNCTION_FLAG,
		maxon::details::UnresolvedReturnType<Int>::value | maxon::UNRESOLVED_RETURN_TYPE::MEMBER_FUNCTION_FLAG,
		maxon::details::UnresolvedReturnType<Int>::value | maxon::UNRESOLVED_RETURN_TYPE::MEMBER_FUNCTION_FLAG,
		maxon::details::UnresolvedReturnType<Int>::value | maxon::UNRESOLVED_RETURN_TYPE::MEMBER_FUNCTION_FLAG,
		maxon::details::UnresolvedReturnType<Int>::value | maxon::UNRESOLVED_RETURN_TYPE::MEMBER_FUNCTION_FLAG,
		maxon::details::UnresolvedReturnType<Result<void>>::value | maxon::UNRESOLVED_RETURN_TYPE::MEMBER_FUNCTION_FLAG,
		maxon::details::UnresolvedReturnType<Result<void>>::value | maxon::UNRESOLVED_RETURN_TYPE::MEMBER_FUNCTION_FLAG,
		maxon::details::UnresolvedReturnType<Result<void>>::value | maxon::UNRESOLVED_RETURN_TYPE::MEMBER_FUNCTION_FLAG,
		maxon::details::UnresolvedReturnType<CStringInterface*>::value | maxon::UNRESOLVED_RETURN_TYPE::MEMBER_FUNCTION_FLAG,
		maxon::details::UnresolvedReturnType<CStringInterface*>::value | maxon::UNRESOLVED_RETURN_TYPE::MEMBER_FUNCTION_FLAG,
		maxon::details::UnresolvedReturnType<CStringInterface*>::value | maxon::UNRESOLVED_RETURN_TYPE::MEMBER_FUNCTION_FLAG,
		maxon::details::UnresolvedReturnType<COMPARERESULT>::value | maxon::UNRESOLVED_RETURN_TYPE::MEMBER_FUNCTION_FLAG,
		maxon::details::UnresolvedReturnType<HashInt>::value | maxon::UNRESOLVED_RETURN_TYPE::MEMBER_FUNCTION_FLAG,
		maxon::details::UnresolvedReturnType<UniqueHash>::value | maxon::UNRESOLVED_RETURN_TYPE::MEMBER_FUNCTION_FLAG,
		maxon::details::UnresolvedReturnType<void>::value | maxon::UNRESOLVED_RETURN_TYPE::MEMBER_FUNCTION_FLAG,
		maxon::details::UnresolvedReturnType<Char>::value | maxon::UNRESOLVED_RETURN_TYPE::MEMBER_FUNCTION_FLAG,
		maxon::details::UnresolvedReturnType<Result<void>>::value | maxon::UNRESOLVED_RETURN_TYPE::MEMBER_FUNCTION_FLAG,
		maxon::details::UnresolvedReturnType<Result<void>>::value | maxon::UNRESOLVED_RETURN_TYPE::MEMBER_FUNCTION_FLAG,
		maxon::details::UnresolvedReturnType<Result<void>>::value | maxon::UNRESOLVED_RETURN_TYPE::MEMBER_FUNCTION_FLAG,
		maxon::details::UnresolvedReturnType<Result<void>>::value | maxon::UNRESOLVED_RETURN_TYPE::MEMBER_FUNCTION_FLAG,
		maxon::details::UnresolvedReturnType<Result<Int>>::value | maxon::UNRESOLVED_RETURN_TYPE::MEMBER_FUNCTION_FLAG,
		maxon::details::UnresolvedReturnType<Result<Int>>::value | maxon::UNRESOLVED_RETURN_TYPE::MEMBER_FUNCTION_FLAG,
		maxon::details::UnresolvedReturnType<Result<Int>>::value | maxon::UNRESOLVED_RETURN_TYPE::MEMBER_FUNCTION_FLAG,
		maxon::details::UnresolvedReturnType<CStringInterface*>::value,
		maxon::details::UnresolvedReturnType<CStringInterface*>::value,
		maxon::details::UnresolvedReturnType<Result<Int>>::value | maxon::UNRESOLVED_RETURN_TYPE::MEMBER_FUNCTION_FLAG,
		maxon::details::UnresolvedReturnType<Result<void>>::value | maxon::UNRESOLVED_RETURN_TYPE::MEMBER_FUNCTION_FLAG,
		maxon::details::UnresolvedReturnType<Result<Block<Char>>>::value | maxon::UNRESOLVED_RETURN_TYPE::MEMBER_FUNCTION_FLAG,
		maxon::details::UnresolvedReturnType<Result<void>>::value | maxon::UNRESOLVED_RETURN_TYPE::MEMBER_FUNCTION_FLAG,
		maxon::details::UnresolvedReturnType<Result<BaseArray<Char>>>::value | maxon::UNRESOLVED_RETURN_TYPE::MEMBER_FUNCTION_FLAG,
		maxon::details::UnresolvedReturnType<Block<const Char>>::value | maxon::UNRESOLVED_RETURN_TYPE::MEMBER_FUNCTION_FLAG,
		maxon::details::UnresolvedReturnType<const CString&>::value,
		maxon::UNRESOLVED_RETURN_TYPE::OTHER
	};
#endif
	maxon::Bool CStringInterface::MTable::InitUnresolved(maxon::NonvirtualInterfaceReference::UnresolvedAssembler assembler, MTable* tbl)
	{
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->CStringInterface_Free = PRIVATE_MAXON_MF_CAST(decltype(CStringInterface_Free), &Hxx2::Wrapper<Hxx2::Unresolved>::CStringInterface_Free);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->CStringInterface_GetLength = PRIVATE_MAXON_MF_CAST(decltype(CStringInterface_GetLength), &Hxx2::Wrapper<Hxx2::Unresolved>::CStringInterface_GetLength);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if constexpr (maxon::details::UnresolvedReturnType<Result<void>>::value == maxon::UNRESOLVED_RETURN_TYPE::OTHER) tbl->CStringInterface_Init = PRIVATE_MAXON_MF_CAST(decltype(CStringInterface_Init), &Hxx2::Wrapper<Hxx2::Unresolved>::CStringInterface_Init);
		#else
		tbl->CStringInterface_Init = PRIVATE_MAXON_MF_CAST(decltype(CStringInterface_Init), &Hxx2::Wrapper<Hxx2::Unresolved>::CStringInterface_Init);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if constexpr (maxon::details::UnresolvedReturnType<Result<void>>::value == maxon::UNRESOLVED_RETURN_TYPE::OTHER) tbl->CStringInterface_Shrink = PRIVATE_MAXON_MF_CAST(decltype(CStringInterface_Shrink), &Hxx2::Wrapper<Hxx2::Unresolved>::CStringInterface_Shrink);
		#else
		tbl->CStringInterface_Shrink = PRIVATE_MAXON_MF_CAST(decltype(CStringInterface_Shrink), &Hxx2::Wrapper<Hxx2::Unresolved>::CStringInterface_Shrink);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if constexpr (maxon::details::UnresolvedReturnType<Result<void>>::value == maxon::UNRESOLVED_RETURN_TYPE::OTHER) tbl->CStringInterface_Append = PRIVATE_MAXON_MF_CAST(decltype(CStringInterface_Append), &Hxx2::Wrapper<Hxx2::Unresolved>::CStringInterface_Append);
		#else
		tbl->CStringInterface_Append = PRIVATE_MAXON_MF_CAST(decltype(CStringInterface_Append), &Hxx2::Wrapper<Hxx2::Unresolved>::CStringInterface_Append);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if constexpr (maxon::details::UnresolvedReturnType<Result<void>>::value == maxon::UNRESOLVED_RETURN_TYPE::OTHER) tbl->CStringInterface_Append_1 = PRIVATE_MAXON_MF_CAST(decltype(CStringInterface_Append_1), &Hxx2::Wrapper<Hxx2::Unresolved>::CStringInterface_Append_1);
		#else
		tbl->CStringInterface_Append_1 = PRIVATE_MAXON_MF_CAST(decltype(CStringInterface_Append_1), &Hxx2::Wrapper<Hxx2::Unresolved>::CStringInterface_Append_1);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->CStringInterface_FindIndex = PRIVATE_MAXON_MF_CAST(decltype(CStringInterface_FindIndex), &Hxx2::Wrapper<Hxx2::Unresolved>::CStringInterface_FindIndex);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->CStringInterface_FindLastIndex = PRIVATE_MAXON_MF_CAST(decltype(CStringInterface_FindLastIndex), &Hxx2::Wrapper<Hxx2::Unresolved>::CStringInterface_FindLastIndex);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->CStringInterface_FindIndex_1 = PRIVATE_MAXON_MF_CAST(decltype(CStringInterface_FindIndex_1), &Hxx2::Wrapper<Hxx2::Unresolved>::CStringInterface_FindIndex_1);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->CStringInterface_FindLastIndex_1 = PRIVATE_MAXON_MF_CAST(decltype(CStringInterface_FindLastIndex_1), &Hxx2::Wrapper<Hxx2::Unresolved>::CStringInterface_FindLastIndex_1);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->CStringInterface_FindUpperIndex = PRIVATE_MAXON_MF_CAST(decltype(CStringInterface_FindUpperIndex), &Hxx2::Wrapper<Hxx2::Unresolved>::CStringInterface_FindUpperIndex);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->CStringInterface_FindLastUpperIndex = PRIVATE_MAXON_MF_CAST(decltype(CStringInterface_FindLastUpperIndex), &Hxx2::Wrapper<Hxx2::Unresolved>::CStringInterface_FindLastUpperIndex);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if constexpr (maxon::details::UnresolvedReturnType<Result<void>>::value == maxon::UNRESOLVED_RETURN_TYPE::OTHER) tbl->CStringInterface_Erase = PRIVATE_MAXON_MF_CAST(decltype(CStringInterface_Erase), &Hxx2::Wrapper<Hxx2::Unresolved>::CStringInterface_Erase);
		#else
		tbl->CStringInterface_Erase = PRIVATE_MAXON_MF_CAST(decltype(CStringInterface_Erase), &Hxx2::Wrapper<Hxx2::Unresolved>::CStringInterface_Erase);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if constexpr (maxon::details::UnresolvedReturnType<Result<void>>::value == maxon::UNRESOLVED_RETURN_TYPE::OTHER) tbl->CStringInterface_Insert = PRIVATE_MAXON_MF_CAST(decltype(CStringInterface_Insert), &Hxx2::Wrapper<Hxx2::Unresolved>::CStringInterface_Insert);
		#else
		tbl->CStringInterface_Insert = PRIVATE_MAXON_MF_CAST(decltype(CStringInterface_Insert), &Hxx2::Wrapper<Hxx2::Unresolved>::CStringInterface_Insert);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if constexpr (maxon::details::UnresolvedReturnType<Result<void>>::value == maxon::UNRESOLVED_RETURN_TYPE::OTHER) tbl->CStringInterface_Insert_1 = PRIVATE_MAXON_MF_CAST(decltype(CStringInterface_Insert_1), &Hxx2::Wrapper<Hxx2::Unresolved>::CStringInterface_Insert_1);
		#else
		tbl->CStringInterface_Insert_1 = PRIVATE_MAXON_MF_CAST(decltype(CStringInterface_Insert_1), &Hxx2::Wrapper<Hxx2::Unresolved>::CStringInterface_Insert_1);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->CStringInterface_GetPart = PRIVATE_MAXON_MF_CAST(decltype(CStringInterface_GetPart), &Hxx2::Wrapper<Hxx2::Unresolved>::CStringInterface_GetPart);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->CStringInterface_ToUpper = PRIVATE_MAXON_MF_CAST(decltype(CStringInterface_ToUpper), &Hxx2::Wrapper<Hxx2::Unresolved>::CStringInterface_ToUpper);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->CStringInterface_ToLower = PRIVATE_MAXON_MF_CAST(decltype(CStringInterface_ToLower), &Hxx2::Wrapper<Hxx2::Unresolved>::CStringInterface_ToLower);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if constexpr (maxon::details::UnresolvedReturnType<COMPARERESULT>::value == maxon::UNRESOLVED_RETURN_TYPE::OTHER) tbl->CStringInterface_ComparePart = PRIVATE_MAXON_MF_CAST(decltype(CStringInterface_ComparePart), &Hxx2::Wrapper<Hxx2::Unresolved>::CStringInterface_ComparePart);
		#else
		tbl->CStringInterface_ComparePart = PRIVATE_MAXON_MF_CAST(decltype(CStringInterface_ComparePart), &Hxx2::Wrapper<Hxx2::Unresolved>::CStringInterface_ComparePart);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if constexpr (maxon::details::UnresolvedReturnType<HashInt>::value == maxon::UNRESOLVED_RETURN_TYPE::OTHER) tbl->CStringInterface_GetHashCode = PRIVATE_MAXON_MF_CAST(decltype(CStringInterface_GetHashCode), &Hxx2::Wrapper<Hxx2::Unresolved>::CStringInterface_GetHashCode);
		#else
		tbl->CStringInterface_GetHashCode = PRIVATE_MAXON_MF_CAST(decltype(CStringInterface_GetHashCode), &Hxx2::Wrapper<Hxx2::Unresolved>::CStringInterface_GetHashCode);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if constexpr (maxon::details::UnresolvedReturnType<UniqueHash>::value == maxon::UNRESOLVED_RETURN_TYPE::OTHER) tbl->CStringInterface_GetUniqueHashCode = PRIVATE_MAXON_MF_CAST(decltype(CStringInterface_GetUniqueHashCode), &Hxx2::Wrapper<Hxx2::Unresolved>::CStringInterface_GetUniqueHashCode);
		#else
		tbl->CStringInterface_GetUniqueHashCode = PRIVATE_MAXON_MF_CAST(decltype(CStringInterface_GetUniqueHashCode), &Hxx2::Wrapper<Hxx2::Unresolved>::CStringInterface_GetUniqueHashCode);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->CStringInterface_SetChar = PRIVATE_MAXON_MF_CAST(decltype(CStringInterface_SetChar), &Hxx2::Wrapper<Hxx2::Unresolved>::CStringInterface_SetChar);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->CStringInterface_GetChar = PRIVATE_MAXON_MF_CAST(decltype(CStringInterface_GetChar), &Hxx2::Wrapper<Hxx2::Unresolved>::CStringInterface_GetChar);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if constexpr (maxon::details::UnresolvedReturnType<Result<void>>::value == maxon::UNRESOLVED_RETURN_TYPE::OTHER) tbl->CStringInterface_GetUtf32 = PRIVATE_MAXON_MF_CAST(decltype(CStringInterface_GetUtf32), &Hxx2::Wrapper<Hxx2::Unresolved>::CStringInterface_GetUtf32);
		#else
		tbl->CStringInterface_GetUtf32 = PRIVATE_MAXON_MF_CAST(decltype(CStringInterface_GetUtf32), &Hxx2::Wrapper<Hxx2::Unresolved>::CStringInterface_GetUtf32);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if constexpr (maxon::details::UnresolvedReturnType<Result<void>>::value == maxon::UNRESOLVED_RETURN_TYPE::OTHER) tbl->CStringInterface_TrimLeft = PRIVATE_MAXON_MF_CAST(decltype(CStringInterface_TrimLeft), &Hxx2::Wrapper<Hxx2::Unresolved>::CStringInterface_TrimLeft);
		#else
		tbl->CStringInterface_TrimLeft = PRIVATE_MAXON_MF_CAST(decltype(CStringInterface_TrimLeft), &Hxx2::Wrapper<Hxx2::Unresolved>::CStringInterface_TrimLeft);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if constexpr (maxon::details::UnresolvedReturnType<Result<void>>::value == maxon::UNRESOLVED_RETURN_TYPE::OTHER) tbl->CStringInterface_TrimRight = PRIVATE_MAXON_MF_CAST(decltype(CStringInterface_TrimRight), &Hxx2::Wrapper<Hxx2::Unresolved>::CStringInterface_TrimRight);
		#else
		tbl->CStringInterface_TrimRight = PRIVATE_MAXON_MF_CAST(decltype(CStringInterface_TrimRight), &Hxx2::Wrapper<Hxx2::Unresolved>::CStringInterface_TrimRight);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if constexpr (maxon::details::UnresolvedReturnType<Result<void>>::value == maxon::UNRESOLVED_RETURN_TYPE::OTHER) tbl->CStringInterface_Split = PRIVATE_MAXON_MF_CAST(decltype(CStringInterface_Split), &Hxx2::Wrapper<Hxx2::Unresolved>::CStringInterface_Split);
		#else
		tbl->CStringInterface_Split = PRIVATE_MAXON_MF_CAST(decltype(CStringInterface_Split), &Hxx2::Wrapper<Hxx2::Unresolved>::CStringInterface_Split);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if constexpr (maxon::details::UnresolvedReturnType<Result<Int>>::value == maxon::UNRESOLVED_RETURN_TYPE::OTHER) tbl->CStringInterface_Replace = PRIVATE_MAXON_MF_CAST(decltype(CStringInterface_Replace), &Hxx2::Wrapper<Hxx2::Unresolved>::CStringInterface_Replace);
		#else
		tbl->CStringInterface_Replace = PRIVATE_MAXON_MF_CAST(decltype(CStringInterface_Replace), &Hxx2::Wrapper<Hxx2::Unresolved>::CStringInterface_Replace);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if constexpr (maxon::details::UnresolvedReturnType<Result<Int>>::value == maxon::UNRESOLVED_RETURN_TYPE::OTHER) tbl->CStringInterface_Replace_1 = PRIVATE_MAXON_MF_CAST(decltype(CStringInterface_Replace_1), &Hxx2::Wrapper<Hxx2::Unresolved>::CStringInterface_Replace_1);
		#else
		tbl->CStringInterface_Replace_1 = PRIVATE_MAXON_MF_CAST(decltype(CStringInterface_Replace_1), &Hxx2::Wrapper<Hxx2::Unresolved>::CStringInterface_Replace_1);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if constexpr (maxon::details::UnresolvedReturnType<Result<Int>>::value == maxon::UNRESOLVED_RETURN_TYPE::OTHER) tbl->CStringInterface_Replace_2 = PRIVATE_MAXON_MF_CAST(decltype(CStringInterface_Replace_2), &Hxx2::Wrapper<Hxx2::Unresolved>::CStringInterface_Replace_2);
		#else
		tbl->CStringInterface_Replace_2 = PRIVATE_MAXON_MF_CAST(decltype(CStringInterface_Replace_2), &Hxx2::Wrapper<Hxx2::Unresolved>::CStringInterface_Replace_2);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->CStringInterface_Alloc = PRIVATE_MAXON_MF_CAST(decltype(CStringInterface_Alloc), &Hxx2::Wrapper<Hxx2::Unresolved>::CStringInterface_Alloc);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->CStringInterface_Alloc_1 = PRIVATE_MAXON_MF_CAST(decltype(CStringInterface_Alloc_1), &Hxx2::Wrapper<Hxx2::Unresolved>::CStringInterface_Alloc_1);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if constexpr (maxon::details::UnresolvedReturnType<Result<Int>>::value == maxon::UNRESOLVED_RETURN_TYPE::OTHER) tbl->CStringInterface_GetCStringBlock = PRIVATE_MAXON_MF_CAST(decltype(CStringInterface_GetCStringBlock), &Hxx2::Wrapper<Hxx2::Unresolved>::CStringInterface_GetCStringBlock);
		#else
		tbl->CStringInterface_GetCStringBlock = PRIVATE_MAXON_MF_CAST(decltype(CStringInterface_GetCStringBlock), &Hxx2::Wrapper<Hxx2::Unresolved>::CStringInterface_GetCStringBlock);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if constexpr (maxon::details::UnresolvedReturnType<Result<void>>::value == maxon::UNRESOLVED_RETURN_TYPE::OTHER) tbl->CStringInterface_GetCStringAppendArray = PRIVATE_MAXON_MF_CAST(decltype(CStringInterface_GetCStringAppendArray), &Hxx2::Wrapper<Hxx2::Unresolved>::CStringInterface_GetCStringAppendArray);
		#else
		tbl->CStringInterface_GetCStringAppendArray = PRIVATE_MAXON_MF_CAST(decltype(CStringInterface_GetCStringAppendArray), &Hxx2::Wrapper<Hxx2::Unresolved>::CStringInterface_GetCStringAppendArray);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if constexpr (maxon::details::UnresolvedReturnType<Result<Block<Char>>>::value == maxon::UNRESOLVED_RETURN_TYPE::OTHER) tbl->CStringInterface_Disconnect = PRIVATE_MAXON_MF_CAST(decltype(CStringInterface_Disconnect), &Hxx2::Wrapper<Hxx2::Unresolved>::CStringInterface_Disconnect);
		#else
		tbl->CStringInterface_Disconnect = PRIVATE_MAXON_MF_CAST(decltype(CStringInterface_Disconnect), &Hxx2::Wrapper<Hxx2::Unresolved>::CStringInterface_Disconnect);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if constexpr (maxon::details::UnresolvedReturnType<Result<void>>::value == maxon::UNRESOLVED_RETURN_TYPE::OTHER) tbl->CStringInterface_SetCString = PRIVATE_MAXON_MF_CAST(decltype(CStringInterface_SetCString), &Hxx2::Wrapper<Hxx2::Unresolved>::CStringInterface_SetCString);
		#else
		tbl->CStringInterface_SetCString = PRIVATE_MAXON_MF_CAST(decltype(CStringInterface_SetCString), &Hxx2::Wrapper<Hxx2::Unresolved>::CStringInterface_SetCString);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if constexpr (maxon::details::UnresolvedReturnType<Result<BaseArray<Char>>>::value == maxon::UNRESOLVED_RETURN_TYPE::OTHER) tbl->CStringInterface_GetCString = PRIVATE_MAXON_MF_CAST(decltype(CStringInterface_GetCString), &Hxx2::Wrapper<Hxx2::Unresolved>::CStringInterface_GetCString);
		#else
		tbl->CStringInterface_GetCString = PRIVATE_MAXON_MF_CAST(decltype(CStringInterface_GetCString), &Hxx2::Wrapper<Hxx2::Unresolved>::CStringInterface_GetCString);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if constexpr (maxon::details::UnresolvedReturnType<Block<const Char>>::value == maxon::UNRESOLVED_RETURN_TYPE::OTHER) tbl->CStringInterface_GetInternalData = PRIVATE_MAXON_MF_CAST(decltype(CStringInterface_GetInternalData), &Hxx2::Wrapper<Hxx2::Unresolved>::CStringInterface_GetInternalData);
		#else
		tbl->CStringInterface_GetInternalData = PRIVATE_MAXON_MF_CAST(decltype(CStringInterface_GetInternalData), &Hxx2::Wrapper<Hxx2::Unresolved>::CStringInterface_GetInternalData);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if constexpr (maxon::details::UnresolvedReturnType<const CString&>::value == maxon::UNRESOLVED_RETURN_TYPE::OTHER) tbl->CStringInterface_GetAndCacheConstString = PRIVATE_MAXON_MF_CAST(decltype(CStringInterface_GetAndCacheConstString), &Hxx2::Wrapper<Hxx2::Unresolved>::CStringInterface_GetAndCacheConstString);
		#else
		tbl->CStringInterface_GetAndCacheConstString = PRIVATE_MAXON_MF_CAST(decltype(CStringInterface_GetAndCacheConstString), &Hxx2::Wrapper<Hxx2::Unresolved>::CStringInterface_GetAndCacheConstString);
		#endif
	#ifdef PRIVATE_MAXON_ASSEMBLE_UNRESOLVED
		return assembler(&_interface, (const void**) tbl, _returnTypes, SIZEOF(MTable) / SIZEOF(void*));
	#else
		return true;
	#endif
	}
	MAXON_INTERFACE_REGISTER(CStringInterface, "net.maxon.interface.cstring", nullptr, maxon::EntityBase::FLAGS::NONE);
	template <typename DUMMY> maxon::Int CStringInterface::PrivateInstantiateDefaultValueHelper()
	{
		return 0
		| maxon::details::InstantiateDefaultReturnValue<Block<const Char>>(OVERLOAD_MAX_RANK)
		| maxon::details::InstantiateDefaultReturnValue<COMPARERESULT>(OVERLOAD_MAX_RANK)
		| maxon::details::InstantiateDefaultReturnValue<CString>(OVERLOAD_MAX_RANK)
		| maxon::details::InstantiateDefaultReturnValue<HashInt>(OVERLOAD_MAX_RANK)
		| maxon::details::InstantiateDefaultReturnValue<UniqueHash>(OVERLOAD_MAX_RANK)
		| maxon::details::InstantiateDefaultReturnValue<const CString&>(OVERLOAD_MAX_RANK)
		;
	}
#ifdef _HAS_CHAR8_T
#endif
}
#endif
static maxon::details::ForceEvaluation s_forceEval_string(0
	| maxon::StringInterface::PrivateInstantiateDefaultValueHelper<maxon::Int>()
	| maxon::CStringInterface::PrivateInstantiateDefaultValueHelper<maxon::Int>()
);
