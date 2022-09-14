
#ifndef DOXYGEN

#if defined MAXON_COMPILER_GCC
	#pragma GCC diagnostic push
	#if MAXON_COMPILER_GCC >= 600
		#pragma GCC diagnostic ignored "-Wmisleading-indentation"
	#endif
#endif

#if 1
constexpr const maxon::Char* StringInterface::PrivateGetCppName() { return "maxon::String"; }

struct StringInterface::MTable
{
	static MTable _instance;
	static MTable _unresolvedInstance;
	static const maxon::Char* const _ids;
	static maxon::Bool InitUnresolved(maxon::NonvirtualInterfaceReference::UnresolvedAssembler assembler, MTable* tbl);
	static const maxon::NULL_RETURN_TYPE _returnTypes[];
	static const maxon::Bool HAS_NONSTATIC = true;
	PRIVATE_MAXON_SF_POINTER(StringInterface_Free, Free, MAXON_EXPAND_VA_ARGS, (void), const StringInterface* object);
	PRIVATE_MAXON_MF_POINTER(StringInterface_GetLength, GetLength, false, StringInterface, const, (Int));
	PRIVATE_MAXON_MF_POINTER(StringInterface_Init, Init, false, StringInterface,, (Result<void>), Int count, Utf32Char fillChar);
	PRIVATE_MAXON_MF_POINTER(StringInterface_Shrink, Shrink, false, StringInterface,, (Result<void>));
	PRIVATE_MAXON_MF_POINTER(StringInterface_Append, Append, false, StringInterface,, (Result<void>), const StringInterface* str);
	PRIVATE_MAXON_MF_POINTER(StringInterface_Append_1, Append, false, StringInterface,, (Result<void>), const Utf32Char* str, Int len);
	PRIVATE_MAXON_MF_POINTER(StringInterface_FindIndex, FindIndex, false, StringInterface, const, (Int), const StringInterface* str, StringPosition start);
	PRIVATE_MAXON_MF_POINTER(StringInterface_FindLastIndex, FindLastIndex, false, StringInterface, const, (Int), const StringInterface* str, StringPosition start);
	PRIVATE_MAXON_MF_POINTER(StringInterface_FindIndex_1, FindIndex, false, StringInterface, const, (Int), Utf32Char ch, StringPosition start);
	PRIVATE_MAXON_MF_POINTER(StringInterface_FindLastIndex_1, FindLastIndex, false, StringInterface, const, (Int), Utf32Char ch, StringPosition start);
	PRIVATE_MAXON_MF_POINTER(StringInterface_FindUpperIndex, FindUpperIndex, false, StringInterface, const, (Int), const StringInterface* str, StringPosition start);
	PRIVATE_MAXON_MF_POINTER(StringInterface_FindLastUpperIndex, FindLastUpperIndex, false, StringInterface, const, (Int), const StringInterface* str, StringPosition start);
	PRIVATE_MAXON_MF_POINTER(StringInterface_Erase, Erase, false, StringInterface,, (Result<void>), StringPosition position, StringCount count);
	PRIVATE_MAXON_MF_POINTER(StringInterface_Insert, Insert, false, StringInterface,, (Result<void>), StringPosition position, const StringInterface* str, StringPosition strStart, StringCount strCount);
	PRIVATE_MAXON_MF_POINTER(StringInterface_Insert_1, Insert, false, StringInterface,, (Result<void>), StringPosition position, Utf32Char ch);
	PRIVATE_MAXON_MF_POINTER(StringInterface_GetPart, GetPart, false, StringInterface, const, (StringInterface*), StringPosition start, StringCount count);
	PRIVATE_MAXON_MF_POINTER(StringInterface_ToUpper, ToUpper, false, StringInterface, const, (StringInterface*));
	PRIVATE_MAXON_MF_POINTER(StringInterface_ToLower, ToLower, false, StringInterface, const, (StringInterface*));
	PRIVATE_MAXON_MF_POINTER(StringInterface_ComparePart, ComparePart, false, StringInterface, const, (COMPARERESULT), const StringInterface* str, STRINGCOMPARISON mode, StringPosition position, StringCount count);
	PRIVATE_MAXON_MF_POINTER(StringInterface_GetHashCode, GetHashCode, false, StringInterface, const, (HashInt));
	PRIVATE_MAXON_MF_POINTER(StringInterface_GetUniqueHashCode, GetUniqueHashCode, false, StringInterface, const, (UniqueHash));
	PRIVATE_MAXON_MF_POINTER(StringInterface_SetChar, SetChar, false, StringInterface,, (void), Int pos, Utf32Char ch);
	PRIVATE_MAXON_MF_POINTER(StringInterface_GetChar, GetChar, false, StringInterface, const, (Utf32Char), Int pos);
	PRIVATE_MAXON_MF_POINTER(StringInterface_GetUtf32, GetUtf32, false, StringInterface, const, (Result<void>), Utf32CharBuffer& stringData);
	PRIVATE_MAXON_MF_POINTER(StringInterface_TrimLeft, TrimLeft, false, StringInterface,, (Result<void>));
	PRIVATE_MAXON_MF_POINTER(StringInterface_TrimRight, TrimRight, false, StringInterface,, (Result<void>));
	PRIVATE_MAXON_MF_POINTER(StringInterface_Split, Split, false, StringInterface, const, (Result<void>), const String& splitSymbol, Bool trim, const ValueReceiver<const String&>& parts);
	PRIVATE_MAXON_MF_POINTER(StringInterface_Replace, Replace, false, StringInterface,, (Result<Int>), Utf32Char find, Utf32Char replace);
	PRIVATE_MAXON_MF_POINTER(StringInterface_Replace_1, Replace, false, StringInterface,, (Result<Int>), const String& find, const String& replace);
	PRIVATE_MAXON_MF_POINTER(StringInterface_Replace_2, Replace, false, StringInterface,, (Result<Int>), Utf32Char find, const String& replace);
	PRIVATE_MAXON_SF_POINTER(StringInterface_Alloc, Alloc, MAXON_IGNORE_VA_ARGS, (StringInterface*), const maxon::SourceLocation& allocLocation);
	PRIVATE_MAXON_SF_POINTER(StringInterface_Alloc_1, Alloc, MAXON_IGNORE_VA_ARGS, (StringInterface*), const maxon::SourceLocation& allocLocation, const StringInterface& object);
	PRIVATE_MAXON_MF_POINTER(StringInterface_GetCStringBlock, GetCStringBlock, false, StringInterface, const, (Result<Int>), const Block<Char>& buffer, const StringEncodingRef& stringEncoding);
	PRIVATE_MAXON_MF_POINTER(StringInterface_GetCStringAppendArray, GetCStringAppendArray, false, StringInterface, const, (Result<void>), const NonConstArray<Char>& array, const StringEncodingRef& stringEncoding);
	PRIVATE_MAXON_MF_POINTER(StringInterface_GetCString, GetCString, false, StringInterface, const, (Result<BaseArray<Char>>), const StringEncodingRef& stringEncoding);
	PRIVATE_MAXON_MF_POINTER(StringInterface_SetCString, SetCString, false, StringInterface,, (Result<void>), const Char* buffer, Int count, const StringDecodingRef& stringDecoding);
	PRIVATE_MAXON_MF_POINTER(StringInterface_GetSystemEncoding, GetSystemEncoding, false, StringInterface, const, (Result<SysCharArray>));
	PRIVATE_MAXON_MF_POINTER(StringInterface_SetSystemEncoding, SetSystemEncoding, false, StringInterface,, (Result<void>), const SysChar* buffer, Int count);
	PRIVATE_MAXON_MF_POINTER(StringInterface_SetUtf32, SetUtf32, false, StringInterface,, (Result<void>), const Utf32Char* buffer, Int count);
	PRIVATE_MAXON_MF_POINTER(StringInterface_GetUtf16, GetUtf16, false, StringInterface, const, (Result<void>), Utf16CharBuffer& stringData);
	PRIVATE_MAXON_MF_POINTER(StringInterface_SetUtf16, SetUtf16, false, StringInterface,, (Result<void>), const Utf16Char* buffer, Int count);
	PRIVATE_MAXON_SF_POINTER(StringInterface_GetAndCacheConstString, GetAndCacheConstString, MAXON_EXPAND_VA_ARGS, (const String&), const wchar_t* chr, Int len);
	PRIVATE_MAXON_SF_POINTER(StringInterface_GetAndCacheConstString_1, GetAndCacheConstString, MAXON_EXPAND_VA_ARGS, (const String&), const Char* chr, Int len, Int isUtf8);
	PRIVATE_MAXON_SF_POINTER(StringInterface_PrivateEnumToString, PrivateEnumToString, MAXON_EXPAND_VA_ARGS, (String), const EnumInfo& info, UInt64 value, const FormatStatement* formatStatement);
	PRIVATE_MAXON_MF_POINTER(StringInterface_GetVariableInternalData, GetVariableInternalData, false, StringInterface, const, (StridedBlock<const Generic>));
	PRIVATE_MAXON_MF_POINTER(StringInterface_GetCharacterWidth, GetCharacterWidth, false, StringInterface, const, (Int));
	PRIVATE_MAXON_MF_POINTER(StringInterface_Prettify, Prettify, false, StringInterface, const, (Result<String>), Int indent, const String& indentStr, Int breakUpThreshold, Bool angularBrackets);
	template <typename IMPL> void Init()
	{
		StringInterface_Free = StringInterface_Free_GetPtr<IMPL>(true);
		StringInterface_GetLength = StringInterface_GetLength_GetPtr<IMPL>(0, true).first;
		StringInterface_Init = StringInterface_Init_GetPtr<IMPL>(0, true).first;
		StringInterface_Shrink = StringInterface_Shrink_GetPtr<IMPL>(0, true).first;
		StringInterface_Append = StringInterface_Append_GetPtr<IMPL>(0, true).first;
		StringInterface_Append_1 = StringInterface_Append_1_GetPtr<IMPL>(0, true).first;
		StringInterface_FindIndex = StringInterface_FindIndex_GetPtr<IMPL>(0, true).first;
		StringInterface_FindLastIndex = StringInterface_FindLastIndex_GetPtr<IMPL>(0, true).first;
		StringInterface_FindIndex_1 = StringInterface_FindIndex_1_GetPtr<IMPL>(0, true).first;
		StringInterface_FindLastIndex_1 = StringInterface_FindLastIndex_1_GetPtr<IMPL>(0, true).first;
		StringInterface_FindUpperIndex = StringInterface_FindUpperIndex_GetPtr<IMPL>(0, true).first;
		StringInterface_FindLastUpperIndex = StringInterface_FindLastUpperIndex_GetPtr<IMPL>(0, true).first;
		StringInterface_Erase = StringInterface_Erase_GetPtr<IMPL>(0, true).first;
		StringInterface_Insert = StringInterface_Insert_GetPtr<IMPL>(0, true).first;
		StringInterface_Insert_1 = StringInterface_Insert_1_GetPtr<IMPL>(0, true).first;
		StringInterface_GetPart = StringInterface_GetPart_GetPtr<IMPL>(0, true).first;
		StringInterface_ToUpper = StringInterface_ToUpper_GetPtr<IMPL>(0, true).first;
		StringInterface_ToLower = StringInterface_ToLower_GetPtr<IMPL>(0, true).first;
		StringInterface_ComparePart = StringInterface_ComparePart_GetPtr<IMPL>(0, true).first;
		StringInterface_GetHashCode = StringInterface_GetHashCode_GetPtr<IMPL>(0, true).first;
		StringInterface_GetUniqueHashCode = StringInterface_GetUniqueHashCode_GetPtr<IMPL>(0, true).first;
		StringInterface_SetChar = StringInterface_SetChar_GetPtr<IMPL>(0, true).first;
		StringInterface_GetChar = StringInterface_GetChar_GetPtr<IMPL>(0, true).first;
		StringInterface_GetUtf32 = StringInterface_GetUtf32_GetPtr<IMPL>(0, true).first;
		StringInterface_TrimLeft = StringInterface_TrimLeft_GetPtr<IMPL>(0, true).first;
		StringInterface_TrimRight = StringInterface_TrimRight_GetPtr<IMPL>(0, true).first;
		StringInterface_Split = StringInterface_Split_GetPtr<IMPL>(0, true).first;
		StringInterface_Replace = StringInterface_Replace_GetPtr<IMPL>(0, true).first;
		StringInterface_Replace_1 = StringInterface_Replace_1_GetPtr<IMPL>(0, true).first;
		StringInterface_Replace_2 = StringInterface_Replace_2_GetPtr<IMPL>(0, true).first;
		StringInterface_Alloc = StringInterface_Alloc_GetPtr<IMPL>(true);
		StringInterface_Alloc_1 = StringInterface_Alloc_1_GetPtr<IMPL>(true);
		StringInterface_GetCStringBlock = StringInterface_GetCStringBlock_GetPtr<IMPL>(0, true).first;
		StringInterface_GetCStringAppendArray = StringInterface_GetCStringAppendArray_GetPtr<IMPL>(0, true).first;
		StringInterface_GetCString = StringInterface_GetCString_GetPtr<IMPL>(0, true).first;
		StringInterface_SetCString = StringInterface_SetCString_GetPtr<IMPL>(0, true).first;
		StringInterface_GetSystemEncoding = StringInterface_GetSystemEncoding_GetPtr<IMPL>(0, true).first;
		StringInterface_SetSystemEncoding = StringInterface_SetSystemEncoding_GetPtr<IMPL>(0, true).first;
		StringInterface_SetUtf32 = StringInterface_SetUtf32_GetPtr<IMPL>(0, true).first;
		StringInterface_GetUtf16 = StringInterface_GetUtf16_GetPtr<IMPL>(0, true).first;
		StringInterface_SetUtf16 = StringInterface_SetUtf16_GetPtr<IMPL>(0, true).first;
		StringInterface_GetAndCacheConstString = StringInterface_GetAndCacheConstString_GetPtr<IMPL>(true);
		StringInterface_GetAndCacheConstString_1 = StringInterface_GetAndCacheConstString_1_GetPtr<IMPL>(true);
		StringInterface_PrivateEnumToString = StringInterface_PrivateEnumToString_GetPtr<IMPL>(true);
		StringInterface_GetVariableInternalData = StringInterface_GetVariableInternalData_GetPtr<IMPL>(0, true).first;
		StringInterface_GetCharacterWidth = StringInterface_GetCharacterWidth_GetPtr<IMPL>(0, true).first;
		StringInterface_Prettify = StringInterface_Prettify_GetPtr<IMPL>(0, true).first;
	}
};

struct StringInterface::Hxx2
{
	class Unresolved;
	template <typename C> class Wrapper
	{
	public:
		using Implementation = C;
		static void StringInterface_Free(const StringInterface* object) { return C::Free(object); }
		PRIVATE_MAXON_MF_WRAPPER(StringInterface_GetLength, StringInterface, const, (Int)) { return C::Get(PRIVATE_MAXON_MF_THIS(const StringInterface))->GetLength(); }
		PRIVATE_MAXON_MF_WRAPPER(StringInterface_Init, StringInterface,, (Result<void>), Int count, Utf32Char fillChar) { return C::Get(PRIVATE_MAXON_MF_THIS(StringInterface))->Init(count, fillChar); }
		PRIVATE_MAXON_MF_WRAPPER(StringInterface_Shrink, StringInterface,, (Result<void>)) { return C::Get(PRIVATE_MAXON_MF_THIS(StringInterface))->Shrink(); }
		PRIVATE_MAXON_MF_WRAPPER(StringInterface_Append, StringInterface,, (Result<void>), const StringInterface* str) { return C::Get(PRIVATE_MAXON_MF_THIS(StringInterface))->Append(str); }
		PRIVATE_MAXON_MF_WRAPPER(StringInterface_Append_1, StringInterface,, (Result<void>), const Utf32Char* str, Int len) { return C::Get(PRIVATE_MAXON_MF_THIS(StringInterface))->Append(str, len); }
		PRIVATE_MAXON_MF_WRAPPER(StringInterface_FindIndex, StringInterface, const, (Int), const StringInterface* str, StringPosition start) { return C::Get(PRIVATE_MAXON_MF_THIS(const StringInterface))->FindIndex(str, std::forward<StringPosition>(start)); }
		PRIVATE_MAXON_MF_WRAPPER(StringInterface_FindLastIndex, StringInterface, const, (Int), const StringInterface* str, StringPosition start) { return C::Get(PRIVATE_MAXON_MF_THIS(const StringInterface))->FindLastIndex(str, std::forward<StringPosition>(start)); }
		PRIVATE_MAXON_MF_WRAPPER(StringInterface_FindIndex_1, StringInterface, const, (Int), Utf32Char ch, StringPosition start) { return C::Get(PRIVATE_MAXON_MF_THIS(const StringInterface))->FindIndex(ch, std::forward<StringPosition>(start)); }
		PRIVATE_MAXON_MF_WRAPPER(StringInterface_FindLastIndex_1, StringInterface, const, (Int), Utf32Char ch, StringPosition start) { return C::Get(PRIVATE_MAXON_MF_THIS(const StringInterface))->FindLastIndex(ch, std::forward<StringPosition>(start)); }
		PRIVATE_MAXON_MF_WRAPPER(StringInterface_FindUpperIndex, StringInterface, const, (Int), const StringInterface* str, StringPosition start) { return C::Get(PRIVATE_MAXON_MF_THIS(const StringInterface))->FindUpperIndex(str, std::forward<StringPosition>(start)); }
		PRIVATE_MAXON_MF_WRAPPER(StringInterface_FindLastUpperIndex, StringInterface, const, (Int), const StringInterface* str, StringPosition start) { return C::Get(PRIVATE_MAXON_MF_THIS(const StringInterface))->FindLastUpperIndex(str, std::forward<StringPosition>(start)); }
		PRIVATE_MAXON_MF_WRAPPER(StringInterface_Erase, StringInterface,, (Result<void>), StringPosition position, StringCount count) { return C::Get(PRIVATE_MAXON_MF_THIS(StringInterface))->Erase(std::forward<StringPosition>(position), std::forward<StringCount>(count)); }
		PRIVATE_MAXON_MF_WRAPPER(StringInterface_Insert, StringInterface,, (Result<void>), StringPosition position, const StringInterface* str, StringPosition strStart, StringCount strCount) { return C::Get(PRIVATE_MAXON_MF_THIS(StringInterface))->Insert(std::forward<StringPosition>(position), str, std::forward<StringPosition>(strStart), std::forward<StringCount>(strCount)); }
		PRIVATE_MAXON_MF_WRAPPER(StringInterface_Insert_1, StringInterface,, (Result<void>), StringPosition position, Utf32Char ch) { return C::Get(PRIVATE_MAXON_MF_THIS(StringInterface))->Insert(std::forward<StringPosition>(position), ch); }
		PRIVATE_MAXON_MF_WRAPPER(StringInterface_GetPart, StringInterface, const, (StringInterface*), StringPosition start, StringCount count) { return C::Get(PRIVATE_MAXON_MF_THIS(const StringInterface))->GetPart(std::forward<StringPosition>(start), std::forward<StringCount>(count)); }
		PRIVATE_MAXON_MF_WRAPPER(StringInterface_ToUpper, StringInterface, const, (StringInterface*)) { return C::Get(PRIVATE_MAXON_MF_THIS(const StringInterface))->ToUpper(); }
		PRIVATE_MAXON_MF_WRAPPER(StringInterface_ToLower, StringInterface, const, (StringInterface*)) { return C::Get(PRIVATE_MAXON_MF_THIS(const StringInterface))->ToLower(); }
		PRIVATE_MAXON_MF_WRAPPER(StringInterface_ComparePart, StringInterface, const, (COMPARERESULT), const StringInterface* str, STRINGCOMPARISON mode, StringPosition position, StringCount count) { return C::Get(PRIVATE_MAXON_MF_THIS(const StringInterface))->ComparePart(str, mode, std::forward<StringPosition>(position), std::forward<StringCount>(count)); }
		PRIVATE_MAXON_MF_WRAPPER(StringInterface_GetHashCode, StringInterface, const, (HashInt)) { return C::Get(PRIVATE_MAXON_MF_THIS(const StringInterface))->GetHashCode(); }
		PRIVATE_MAXON_MF_WRAPPER(StringInterface_GetUniqueHashCode, StringInterface, const, (UniqueHash)) { return C::Get(PRIVATE_MAXON_MF_THIS(const StringInterface))->GetUniqueHashCode(); }
		PRIVATE_MAXON_MF_WRAPPER(StringInterface_SetChar, StringInterface,, (void), Int pos, Utf32Char ch) { return C::Get(PRIVATE_MAXON_MF_THIS(StringInterface))->SetChar(pos, ch); }
		PRIVATE_MAXON_MF_WRAPPER(StringInterface_GetChar, StringInterface, const, (Utf32Char), Int pos) { return C::Get(PRIVATE_MAXON_MF_THIS(const StringInterface))->GetChar(pos); }
		PRIVATE_MAXON_MF_WRAPPER(StringInterface_GetUtf32, StringInterface, const, (Result<void>), Utf32CharBuffer& stringData) { return C::Get(PRIVATE_MAXON_MF_THIS(const StringInterface))->GetUtf32(stringData); }
		PRIVATE_MAXON_MF_WRAPPER(StringInterface_TrimLeft, StringInterface,, (Result<void>)) { return C::Get(PRIVATE_MAXON_MF_THIS(StringInterface))->TrimLeft(); }
		PRIVATE_MAXON_MF_WRAPPER(StringInterface_TrimRight, StringInterface,, (Result<void>)) { return C::Get(PRIVATE_MAXON_MF_THIS(StringInterface))->TrimRight(); }
		PRIVATE_MAXON_MF_WRAPPER(StringInterface_Split, StringInterface, const, (Result<void>), const String& splitSymbol, Bool trim, const ValueReceiver<const String&>& parts) { return C::Get(PRIVATE_MAXON_MF_THIS(const StringInterface))->Split(splitSymbol, trim, parts); }
		PRIVATE_MAXON_MF_WRAPPER(StringInterface_Replace, StringInterface,, (Result<Int>), Utf32Char find, Utf32Char replace) { return C::Get(PRIVATE_MAXON_MF_THIS(StringInterface))->Replace(find, replace); }
		PRIVATE_MAXON_MF_WRAPPER(StringInterface_Replace_1, StringInterface,, (Result<Int>), const String& find, const String& replace) { return C::Get(PRIVATE_MAXON_MF_THIS(StringInterface))->Replace(find, replace); }
		PRIVATE_MAXON_MF_WRAPPER(StringInterface_Replace_2, StringInterface,, (Result<Int>), Utf32Char find, const String& replace) { return C::Get(PRIVATE_MAXON_MF_THIS(StringInterface))->Replace(find, replace); }
		static StringInterface* StringInterface_Alloc(const maxon::SourceLocation& allocLocation) { return C::Alloc(allocLocation); }
		static StringInterface* StringInterface_Alloc_1(const maxon::SourceLocation& allocLocation, const StringInterface& object) { return C::Alloc(allocLocation, ((const C&) object)); }
		PRIVATE_MAXON_MF_WRAPPER(StringInterface_GetCStringBlock, StringInterface, const, (Result<Int>), const Block<Char>& buffer, const StringEncodingRef& stringEncoding) { return C::Get(PRIVATE_MAXON_MF_THIS(const StringInterface))->GetCStringBlock(buffer, stringEncoding); }
		PRIVATE_MAXON_MF_WRAPPER(StringInterface_GetCStringAppendArray, StringInterface, const, (Result<void>), const NonConstArray<Char>& array, const StringEncodingRef& stringEncoding) { return C::Get(PRIVATE_MAXON_MF_THIS(const StringInterface))->GetCStringAppendArray(array, stringEncoding); }
		PRIVATE_MAXON_MF_WRAPPER(StringInterface_GetCString, StringInterface, const, (Result<BaseArray<Char>>), const StringEncodingRef& stringEncoding) { return C::Get(PRIVATE_MAXON_MF_THIS(const StringInterface))->GetCString(stringEncoding); }
		PRIVATE_MAXON_MF_WRAPPER(StringInterface_SetCString, StringInterface,, (Result<void>), const Char* buffer, Int count, const StringDecodingRef& stringDecoding) { return C::Get(PRIVATE_MAXON_MF_THIS(StringInterface))->SetCString(buffer, count, stringDecoding); }
		PRIVATE_MAXON_MF_WRAPPER(StringInterface_GetSystemEncoding, StringInterface, const, (Result<SysCharArray>)) { return C::Get(PRIVATE_MAXON_MF_THIS(const StringInterface))->GetSystemEncoding(); }
		PRIVATE_MAXON_MF_WRAPPER(StringInterface_SetSystemEncoding, StringInterface,, (Result<void>), const SysChar* buffer, Int count) { return C::Get(PRIVATE_MAXON_MF_THIS(StringInterface))->SetSystemEncoding(buffer, count); }
		PRIVATE_MAXON_MF_WRAPPER(StringInterface_SetUtf32, StringInterface,, (Result<void>), const Utf32Char* buffer, Int count) { return C::Get(PRIVATE_MAXON_MF_THIS(StringInterface))->SetUtf32(buffer, count); }
		PRIVATE_MAXON_MF_WRAPPER(StringInterface_GetUtf16, StringInterface, const, (Result<void>), Utf16CharBuffer& stringData) { return C::Get(PRIVATE_MAXON_MF_THIS(const StringInterface))->GetUtf16(stringData); }
		PRIVATE_MAXON_MF_WRAPPER(StringInterface_SetUtf16, StringInterface,, (Result<void>), const Utf16Char* buffer, Int count) { return C::Get(PRIVATE_MAXON_MF_THIS(StringInterface))->SetUtf16(buffer, count); }
		static const String& StringInterface_GetAndCacheConstString(const wchar_t* chr, Int len) { return C::GetAndCacheConstString(chr, len); }
		static const String& StringInterface_GetAndCacheConstString_1(const Char* chr, Int len, Int isUtf8) { return C::GetAndCacheConstString(chr, len, isUtf8); }
		static String StringInterface_PrivateEnumToString(const EnumInfo& info, UInt64 value, const FormatStatement* formatStatement) { return C::PrivateEnumToString(info, value, formatStatement); }
		PRIVATE_MAXON_MF_WRAPPER(StringInterface_GetVariableInternalData, StringInterface, const, (StridedBlock<const Generic>)) { return C::Get(PRIVATE_MAXON_MF_THIS(const StringInterface))->GetVariableInternalData(); }
		PRIVATE_MAXON_MF_WRAPPER(StringInterface_GetCharacterWidth, StringInterface, const, (Int)) { return C::Get(PRIVATE_MAXON_MF_THIS(const StringInterface))->GetCharacterWidth(); }
		PRIVATE_MAXON_MF_WRAPPER(StringInterface_Prettify, StringInterface, const, (Result<String>), Int indent, const String& indentStr, Int breakUpThreshold, Bool angularBrackets) { return C::Get(PRIVATE_MAXON_MF_THIS(const StringInterface))->Prettify(indent, indentStr, breakUpThreshold, angularBrackets); }
	};

};
MAXON_ATTRIBUTE_FORCE_INLINE auto StringInterface::Free(const StringInterface* object) -> void
{
	return MTable::_instance.StringInterface_Free(object);
}
template <> MAXON_ATTRIBUTE_FORCE_INLINE auto StringTemplate<StringInterface,String,Utf32Char>::GetLength() const -> Int
{
	return PRIVATE_MAXON_MF_INVOKE((static_cast<const StringInterface*>(this)), StringInterface::MTable::_instance.StringInterface_GetLength);
}
template <> MAXON_ATTRIBUTE_FORCE_INLINE auto StringTemplate<StringInterface,String,Utf32Char>::Init(Int count, Utf32Char fillChar) -> Result<void>
{
	return PRIVATE_MAXON_MF_INVOKE((static_cast<StringInterface*>(this)), StringInterface::MTable::_instance.StringInterface_Init, count, fillChar);
}
template <> MAXON_ATTRIBUTE_FORCE_INLINE auto StringTemplate<StringInterface,String,Utf32Char>::Shrink() -> Result<void>
{
	return PRIVATE_MAXON_MF_INVOKE((static_cast<StringInterface*>(this)), StringInterface::MTable::_instance.StringInterface_Shrink);
}
template <> MAXON_ATTRIBUTE_FORCE_INLINE auto StringTemplate<StringInterface,String,Utf32Char>::Append(const StringInterface* str) -> Result<void>
{
	return PRIVATE_MAXON_MF_INVOKE((static_cast<StringInterface*>(this)), StringInterface::MTable::_instance.StringInterface_Append, str);
}
template <> MAXON_ATTRIBUTE_FORCE_INLINE auto StringTemplate<StringInterface,String,Utf32Char>::Append(const Utf32Char* str, Int len) -> Result<void>
{
	return PRIVATE_MAXON_MF_INVOKE((static_cast<StringInterface*>(this)), StringInterface::MTable::_instance.StringInterface_Append_1, str, len);
}
template <> MAXON_ATTRIBUTE_FORCE_INLINE auto StringTemplate<StringInterface,String,Utf32Char>::FindIndex(const StringInterface* str, StringPosition start) const -> Int
{
	return PRIVATE_MAXON_MF_INVOKE((static_cast<const StringInterface*>(this)), StringInterface::MTable::_instance.StringInterface_FindIndex, str, std::forward<StringPosition>(start));
}
template <> MAXON_ATTRIBUTE_FORCE_INLINE auto StringTemplate<StringInterface,String,Utf32Char>::FindLastIndex(const StringInterface* str, StringPosition start) const -> Int
{
	return PRIVATE_MAXON_MF_INVOKE((static_cast<const StringInterface*>(this)), StringInterface::MTable::_instance.StringInterface_FindLastIndex, str, std::forward<StringPosition>(start));
}
template <> MAXON_ATTRIBUTE_FORCE_INLINE auto StringTemplate<StringInterface,String,Utf32Char>::FindIndex(Utf32Char ch, StringPosition start) const -> Int
{
	return PRIVATE_MAXON_MF_INVOKE((static_cast<const StringInterface*>(this)), StringInterface::MTable::_instance.StringInterface_FindIndex_1, ch, std::forward<StringPosition>(start));
}
template <> MAXON_ATTRIBUTE_FORCE_INLINE auto StringTemplate<StringInterface,String,Utf32Char>::FindLastIndex(Utf32Char ch, StringPosition start) const -> Int
{
	return PRIVATE_MAXON_MF_INVOKE((static_cast<const StringInterface*>(this)), StringInterface::MTable::_instance.StringInterface_FindLastIndex_1, ch, std::forward<StringPosition>(start));
}
template <> MAXON_ATTRIBUTE_FORCE_INLINE auto StringTemplate<StringInterface,String,Utf32Char>::FindUpperIndex(const StringInterface* str, StringPosition start) const -> Int
{
	return PRIVATE_MAXON_MF_INVOKE((static_cast<const StringInterface*>(this)), StringInterface::MTable::_instance.StringInterface_FindUpperIndex, str, std::forward<StringPosition>(start));
}
template <> MAXON_ATTRIBUTE_FORCE_INLINE auto StringTemplate<StringInterface,String,Utf32Char>::FindLastUpperIndex(const StringInterface* str, StringPosition start) const -> Int
{
	return PRIVATE_MAXON_MF_INVOKE((static_cast<const StringInterface*>(this)), StringInterface::MTable::_instance.StringInterface_FindLastUpperIndex, str, std::forward<StringPosition>(start));
}
template <> MAXON_ATTRIBUTE_FORCE_INLINE auto StringTemplate<StringInterface,String,Utf32Char>::Erase(StringPosition position, StringCount count) -> Result<void>
{
	return PRIVATE_MAXON_MF_INVOKE((static_cast<StringInterface*>(this)), StringInterface::MTable::_instance.StringInterface_Erase, std::forward<StringPosition>(position), std::forward<StringCount>(count));
}
template <> MAXON_ATTRIBUTE_FORCE_INLINE auto StringTemplate<StringInterface,String,Utf32Char>::Insert(StringPosition position, const StringInterface* str, StringPosition strStart, StringCount strCount) -> Result<void>
{
	return PRIVATE_MAXON_MF_INVOKE((static_cast<StringInterface*>(this)), StringInterface::MTable::_instance.StringInterface_Insert, std::forward<StringPosition>(position), str, std::forward<StringPosition>(strStart), std::forward<StringCount>(strCount));
}
template <> MAXON_ATTRIBUTE_FORCE_INLINE auto StringTemplate<StringInterface,String,Utf32Char>::Insert(StringPosition position, Utf32Char ch) -> Result<void>
{
	return PRIVATE_MAXON_MF_INVOKE((static_cast<StringInterface*>(this)), StringInterface::MTable::_instance.StringInterface_Insert_1, std::forward<StringPosition>(position), ch);
}
template <> MAXON_ATTRIBUTE_FORCE_INLINE auto StringTemplate<StringInterface,String,Utf32Char>::GetPart(StringPosition start, StringCount count) const -> StringInterface*
{
	return PRIVATE_MAXON_MF_INVOKE((static_cast<const StringInterface*>(this)), StringInterface::MTable::_instance.StringInterface_GetPart, std::forward<StringPosition>(start), std::forward<StringCount>(count));
}
template <> MAXON_ATTRIBUTE_FORCE_INLINE auto StringTemplate<StringInterface,String,Utf32Char>::ToUpper() const -> StringInterface*
{
	return PRIVATE_MAXON_MF_INVOKE((static_cast<const StringInterface*>(this)), StringInterface::MTable::_instance.StringInterface_ToUpper);
}
template <> MAXON_ATTRIBUTE_FORCE_INLINE auto StringTemplate<StringInterface,String,Utf32Char>::ToLower() const -> StringInterface*
{
	return PRIVATE_MAXON_MF_INVOKE((static_cast<const StringInterface*>(this)), StringInterface::MTable::_instance.StringInterface_ToLower);
}
template <> MAXON_ATTRIBUTE_FORCE_INLINE auto StringTemplate<StringInterface,String,Utf32Char>::ComparePart(const StringInterface* str, STRINGCOMPARISON mode, StringPosition position, StringCount count) const -> COMPARERESULT
{
	return PRIVATE_MAXON_MF_INVOKE((static_cast<const StringInterface*>(this)), StringInterface::MTable::_instance.StringInterface_ComparePart, str, mode, std::forward<StringPosition>(position), std::forward<StringCount>(count));
}
template <> MAXON_ATTRIBUTE_FORCE_INLINE auto StringTemplate<StringInterface,String,Utf32Char>::GetHashCode() const -> HashInt
{
	return PRIVATE_MAXON_MF_INVOKE((static_cast<const StringInterface*>(this)), StringInterface::MTable::_instance.StringInterface_GetHashCode);
}
template <> MAXON_ATTRIBUTE_FORCE_INLINE auto StringTemplate<StringInterface,String,Utf32Char>::GetUniqueHashCode() const -> UniqueHash
{
	return PRIVATE_MAXON_MF_INVOKE((static_cast<const StringInterface*>(this)), StringInterface::MTable::_instance.StringInterface_GetUniqueHashCode);
}
template <> MAXON_ATTRIBUTE_FORCE_INLINE auto StringTemplate<StringInterface,String,Utf32Char>::SetChar(Int pos, Utf32Char ch) -> void
{
	return PRIVATE_MAXON_MF_INVOKE((static_cast<StringInterface*>(this)), StringInterface::MTable::_instance.StringInterface_SetChar, pos, ch);
}
template <> MAXON_ATTRIBUTE_FORCE_INLINE auto StringTemplate<StringInterface,String,Utf32Char>::GetChar(Int pos) const -> Utf32Char
{
	return PRIVATE_MAXON_MF_INVOKE((static_cast<const StringInterface*>(this)), StringInterface::MTable::_instance.StringInterface_GetChar, pos);
}
template <> MAXON_ATTRIBUTE_FORCE_INLINE auto StringTemplate<StringInterface,String,Utf32Char>::GetUtf32(Utf32CharBuffer& stringData) const -> Result<void>
{
	return PRIVATE_MAXON_MF_INVOKE((static_cast<const StringInterface*>(this)), StringInterface::MTable::_instance.StringInterface_GetUtf32, stringData);
}
template <> MAXON_ATTRIBUTE_FORCE_INLINE auto StringTemplate<StringInterface,String,Utf32Char>::TrimLeft() -> Result<void>
{
	return PRIVATE_MAXON_MF_INVOKE((static_cast<StringInterface*>(this)), StringInterface::MTable::_instance.StringInterface_TrimLeft);
}
template <> MAXON_ATTRIBUTE_FORCE_INLINE auto StringTemplate<StringInterface,String,Utf32Char>::TrimRight() -> Result<void>
{
	return PRIVATE_MAXON_MF_INVOKE((static_cast<StringInterface*>(this)), StringInterface::MTable::_instance.StringInterface_TrimRight);
}
template <> MAXON_ATTRIBUTE_FORCE_INLINE auto StringTemplate<StringInterface,String,Utf32Char>::Split(const String& splitSymbol, Bool trim, const ValueReceiver<const String&>& parts) const -> Result<void>
{
	return PRIVATE_MAXON_MF_INVOKE((static_cast<const StringInterface*>(this)), StringInterface::MTable::_instance.StringInterface_Split, splitSymbol, trim, parts);
}
template <> MAXON_ATTRIBUTE_FORCE_INLINE auto StringTemplate<StringInterface,String,Utf32Char>::Replace(Utf32Char find, Utf32Char replace) -> Result<Int>
{
	return PRIVATE_MAXON_MF_INVOKE((static_cast<StringInterface*>(this)), StringInterface::MTable::_instance.StringInterface_Replace, find, replace);
}
template <> MAXON_ATTRIBUTE_FORCE_INLINE auto StringTemplate<StringInterface,String,Utf32Char>::Replace(const String& find, const String& replace) -> Result<Int>
{
	return PRIVATE_MAXON_MF_INVOKE((static_cast<StringInterface*>(this)), StringInterface::MTable::_instance.StringInterface_Replace_1, find, replace);
}
template <> MAXON_ATTRIBUTE_FORCE_INLINE auto StringTemplate<StringInterface,String,Utf32Char>::Replace(Utf32Char find, const String& replace) -> Result<Int>
{
	return PRIVATE_MAXON_MF_INVOKE((static_cast<StringInterface*>(this)), StringInterface::MTable::_instance.StringInterface_Replace_2, find, replace);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto StringInterface::Alloc(const maxon::SourceLocation& allocLocation) -> StringInterface*
{
	return MTable::_instance.StringInterface_Alloc(allocLocation);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto StringInterface::Alloc(const maxon::SourceLocation& allocLocation, const StringInterface& object) -> StringInterface*
{
	return MTable::_instance.StringInterface_Alloc_1(allocLocation, object);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto StringInterface::GetCStringBlock(const Block<Char>& buffer, const StringEncodingRef& stringEncoding) const -> Result<Int>
{
	return PRIVATE_MAXON_MF_INVOKE((this), MTable::_instance.StringInterface_GetCStringBlock, buffer, stringEncoding);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto StringInterface::GetCStringAppendArray(const NonConstArray<Char>& array, const StringEncodingRef& stringEncoding) const -> Result<void>
{
	return PRIVATE_MAXON_MF_INVOKE((this), MTable::_instance.StringInterface_GetCStringAppendArray, array, stringEncoding);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto StringInterface::GetCString(const StringEncodingRef& stringEncoding) const -> Result<BaseArray<Char>>
{
	return PRIVATE_MAXON_MF_INVOKE((this), MTable::_instance.StringInterface_GetCString, stringEncoding);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto StringInterface::SetCString(const Char* buffer, Int count, const StringDecodingRef& stringDecoding) -> Result<void>
{
	return PRIVATE_MAXON_MF_INVOKE((this), MTable::_instance.StringInterface_SetCString, buffer, count, stringDecoding);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto StringInterface::GetSystemEncoding() const -> Result<SysCharArray>
{
	return PRIVATE_MAXON_MF_INVOKE((this), MTable::_instance.StringInterface_GetSystemEncoding);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto StringInterface::SetSystemEncoding(const SysChar* buffer, Int count) -> Result<void>
{
	return PRIVATE_MAXON_MF_INVOKE((this), MTable::_instance.StringInterface_SetSystemEncoding, buffer, count);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto StringInterface::SetUtf32(const Utf32Char* buffer, Int count) -> Result<void>
{
	return PRIVATE_MAXON_MF_INVOKE((this), MTable::_instance.StringInterface_SetUtf32, buffer, count);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto StringInterface::GetUtf16(Utf16CharBuffer& stringData) const -> Result<void>
{
	return PRIVATE_MAXON_MF_INVOKE((this), MTable::_instance.StringInterface_GetUtf16, stringData);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto StringInterface::SetUtf16(const Utf16Char* buffer, Int count) -> Result<void>
{
	return PRIVATE_MAXON_MF_INVOKE((this), MTable::_instance.StringInterface_SetUtf16, buffer, count);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto StringInterface::GetAndCacheConstString(const wchar_t* chr, Int len) -> const String&
{
	return MTable::_instance.StringInterface_GetAndCacheConstString(chr, len);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto StringInterface::GetAndCacheConstString(const Char* chr, Int len, Int isUtf8) -> const String&
{
	return MTable::_instance.StringInterface_GetAndCacheConstString_1(chr, len, isUtf8);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto StringInterface::PrivateEnumToString(const EnumInfo& info, UInt64 value, const FormatStatement* formatStatement) -> String
{
	return MTable::_instance.StringInterface_PrivateEnumToString(info, value, formatStatement);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto StringInterface::GetVariableInternalData() const -> StridedBlock<const Generic>
{
	return PRIVATE_MAXON_MF_INVOKE((this), MTable::_instance.StringInterface_GetVariableInternalData);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto StringInterface::GetCharacterWidth() const -> Int
{
	return PRIVATE_MAXON_MF_INVOKE((this), MTable::_instance.StringInterface_GetCharacterWidth);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto StringInterface::Prettify(Int indent, const String& indentStr, Int breakUpThreshold, Bool angularBrackets) const -> Result<String>
{
	return PRIVATE_MAXON_MF_INVOKE((this), MTable::_instance.StringInterface_Prettify, indent, indentStr, breakUpThreshold, angularBrackets);
}

template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto StringInterface::Hxx1::ConstFn<S>::GetLength() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const StringInterface* o_ = (const StringInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = StringInterface::NullValuePtr(); if (!o_) return 0; } 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.StringInterface_GetLength));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto StringInterface::Hxx1::Fn<S>::Init(Int count, Utf32Char fillChar) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); StringInterface* o_ = (StringInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.StringInterface_Init, count, fillChar));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto StringInterface::Hxx1::COWFn<S>::Init(Int count, Utf32Char fillChar) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); StringInterface* o_ = (StringInterface*) this->MakeWritable(true).GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.StringInterface_Init, count, fillChar));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto StringInterface::Hxx1::Fn<S>::Shrink() const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); StringInterface* o_ = (StringInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.StringInterface_Shrink));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto StringInterface::Hxx1::COWFn<S>::Shrink() -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); StringInterface* o_ = (StringInterface*) this->MakeWritable(true).GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.StringInterface_Shrink));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto StringInterface::Hxx1::Fn<S>::Append(const StringInterface* str) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); StringInterface* o_ = (StringInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.StringInterface_Append, str));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto StringInterface::Hxx1::COWFn<S>::Append(const StringInterface* str) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); StringInterface* o_ = (StringInterface*) this->MakeWritable(true).GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.StringInterface_Append, str));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto StringInterface::Hxx1::Fn<S>::Append(const String& str) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); StringInterface* o_ = (StringInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (o_->Append(str));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto StringInterface::Hxx1::COWFn<S>::Append(const String& str) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); StringInterface* o_ = (StringInterface*) this->MakeWritable(true).GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } 
	return (o_->Append(str));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto StringInterface::Hxx1::Fn<S>::Append(const Utf32Char* str, Int len) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); StringInterface* o_ = (StringInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.StringInterface_Append_1, str, len));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto StringInterface::Hxx1::COWFn<S>::Append(const Utf32Char* str, Int len) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); StringInterface* o_ = (StringInterface*) this->MakeWritable(true).GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.StringInterface_Append_1, str, len));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto StringInterface::Hxx1::Fn<S>::Append(const Block<const Utf32Char>& block) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); StringInterface* o_ = (StringInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (o_->Append(block));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto StringInterface::Hxx1::COWFn<S>::Append(const Block<const Utf32Char>& block) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); StringInterface* o_ = (StringInterface*) this->MakeWritable(true).GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } 
	return (o_->Append(block));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto StringInterface::Hxx1::Fn<S>::AppendChar(Utf32Char v) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); StringInterface* o_ = (StringInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (o_->AppendChar(v));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto StringInterface::Hxx1::COWFn<S>::AppendChar(Utf32Char v) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); StringInterface* o_ = (StringInterface*) this->MakeWritable(true).GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } 
	return (o_->AppendChar(v));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto StringInterface::Hxx1::ConstFn<S>::FindIndex(const StringInterface* str, StringPosition start) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const StringInterface* o_ = (const StringInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = StringInterface::NullValuePtr(); if (!o_) return InvalidArrayIndex; } 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.StringInterface_FindIndex, str, std::forward<StringPosition>(start)));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto StringInterface::Hxx1::ConstFn<S>::FindLastIndex(const StringInterface* str, StringPosition start) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const StringInterface* o_ = (const StringInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = StringInterface::NullValuePtr(); if (!o_) return InvalidArrayIndex; } 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.StringInterface_FindLastIndex, str, std::forward<StringPosition>(start)));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto StringInterface::Hxx1::ConstFn<S>::FindIndex(Utf32Char ch, StringPosition start) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const StringInterface* o_ = (const StringInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = StringInterface::NullValuePtr(); if (!o_) return InvalidArrayIndex; } 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.StringInterface_FindIndex_1, ch, std::forward<StringPosition>(start)));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto StringInterface::Hxx1::ConstFn<S>::FindLastIndex(Utf32Char ch, StringPosition start) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const StringInterface* o_ = (const StringInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = StringInterface::NullValuePtr(); if (!o_) return InvalidArrayIndex; } 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.StringInterface_FindLastIndex_1, ch, std::forward<StringPosition>(start)));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto StringInterface::Hxx1::ConstFn<S>::FindUpperIndex(const StringInterface* str, StringPosition start) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const StringInterface* o_ = (const StringInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = StringInterface::NullValuePtr(); if (!o_) return InvalidArrayIndex; } 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.StringInterface_FindUpperIndex, str, std::forward<StringPosition>(start)));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto StringInterface::Hxx1::ConstFn<S>::FindLastUpperIndex(const StringInterface* str, StringPosition start) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const StringInterface* o_ = (const StringInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = StringInterface::NullValuePtr(); if (!o_) return InvalidArrayIndex; } 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.StringInterface_FindLastUpperIndex, str, std::forward<StringPosition>(start)));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto StringInterface::Hxx1::Fn<S>::Erase(StringPosition position, StringCount count) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); StringInterface* o_ = (StringInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.StringInterface_Erase, std::forward<StringPosition>(position), std::forward<StringCount>(count)));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto StringInterface::Hxx1::COWFn<S>::Erase(StringPosition position, StringCount count) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); StringInterface* o_ = (StringInterface*) this->MakeWritable(true).GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.StringInterface_Erase, std::forward<StringPosition>(position), std::forward<StringCount>(count)));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto StringInterface::Hxx1::Fn<S>::Insert(StringPosition position, const StringInterface* str, StringPosition strStart, StringCount strCount) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); StringInterface* o_ = (StringInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.StringInterface_Insert, std::forward<StringPosition>(position), str, std::forward<StringPosition>(strStart), std::forward<StringCount>(strCount)));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto StringInterface::Hxx1::COWFn<S>::Insert(StringPosition position, const StringInterface* str, StringPosition strStart, StringCount strCount) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); StringInterface* o_ = (StringInterface*) this->MakeWritable(true).GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.StringInterface_Insert, std::forward<StringPosition>(position), str, std::forward<StringPosition>(strStart), std::forward<StringCount>(strCount)));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto StringInterface::Hxx1::Fn<S>::Insert(StringPosition position, Utf32Char ch) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); StringInterface* o_ = (StringInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.StringInterface_Insert_1, std::forward<StringPosition>(position), ch));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto StringInterface::Hxx1::COWFn<S>::Insert(StringPosition position, Utf32Char ch) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); StringInterface* o_ = (StringInterface*) this->MakeWritable(true).GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.StringInterface_Insert_1, std::forward<StringPosition>(position), ch));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto StringInterface::Hxx1::ConstFn<S>::GetPart(StringPosition start, StringCount count) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<String>, String>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<String>, String>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const StringInterface* o_ = (const StringInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = StringInterface::NullValuePtr(); if (!o_) return String::NullValue(); } 
	return String(PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.StringInterface_GetPart, std::forward<StringPosition>(start), std::forward<StringCount>(count)));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto StringInterface::Hxx1::ConstFn<S>::ToUpper() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<String>, String>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<String>, String>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const StringInterface* o_ = (const StringInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = StringInterface::NullValuePtr(); if (!o_) return String::NullValue(); } 
	return String(PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.StringInterface_ToUpper));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto StringInterface::Hxx1::ConstFn<S>::ToLower() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<String>, String>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<String>, String>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const StringInterface* o_ = (const StringInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = StringInterface::NullValuePtr(); if (!o_) return String::NullValue(); } 
	return String(PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.StringInterface_ToLower));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto StringInterface::Hxx1::ConstFn<S>::ComparePart(const StringInterface* str, STRINGCOMPARISON mode, StringPosition position, StringCount count) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<COMPARERESULT>, COMPARERESULT>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<COMPARERESULT>, COMPARERESULT>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const StringInterface* o_ = (const StringInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = StringInterface::NullValuePtr(); if (!o_) return maxon::PrivateIncompleteNullReturnValue<COMPARERESULT>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.StringInterface_ComparePart, str, mode, std::forward<StringPosition>(position), std::forward<StringCount>(count)));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto StringInterface::Hxx1::ConstFn<S>::Compare(const StringInterface* str, STRINGCOMPARISON mode) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<COMPARERESULT>, COMPARERESULT>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<COMPARERESULT>, COMPARERESULT>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const StringInterface* o_ = (const StringInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = StringInterface::NullValuePtr(); if (!o_) return maxon::PrivateIncompleteNullReturnValue<COMPARERESULT>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } 
	return (o_->Compare(str, mode));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto StringInterface::Hxx1::ConstFn<S>::IsEqual(const StringInterface* str) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const StringInterface* o_ = (const StringInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = StringInterface::NullValuePtr(); if (!o_) return maxon::PrivateLogNullptrError(false); } 
	return (o_->IsEqual(str));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto StringInterface::Hxx1::ConstFn<S>::ToFloat64(STRINGCONVERSION flags) const -> Result<Float64>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<Float64>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const StringInterface* o_ = (const StringInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = StringInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (o_->ToFloat64(flags));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto StringInterface::Hxx1::ConstFn<S>::ToFloat32(STRINGCONVERSION flags) const -> Result<Float32>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<Float32>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const StringInterface* o_ = (const StringInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = StringInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (o_->ToFloat32(flags));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto StringInterface::Hxx1::ConstFn<S>::ToFloat(STRINGCONVERSION flags) const -> Result<Float>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<Float>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const StringInterface* o_ = (const StringInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = StringInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (o_->ToFloat(flags));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto StringInterface::Hxx1::ConstFn<S>::ToInt64(STRINGCONVERSION flags) const -> Result<Int64>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<Int64>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const StringInterface* o_ = (const StringInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = StringInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (o_->ToInt64(flags));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto StringInterface::Hxx1::ConstFn<S>::ToInt32(STRINGCONVERSION flags) const -> Result<Int32>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<Int32>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const StringInterface* o_ = (const StringInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = StringInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (o_->ToInt32(flags));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto StringInterface::Hxx1::ConstFn<S>::ToInt(STRINGCONVERSION flags) const -> Result<Int>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<Int>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const StringInterface* o_ = (const StringInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = StringInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (o_->ToInt(flags));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto StringInterface::Hxx1::ConstFn<S>::ToUInt64(STRINGCONVERSION flags) const -> Result<UInt64>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<UInt64>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const StringInterface* o_ = (const StringInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = StringInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (o_->ToUInt64(flags));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto StringInterface::Hxx1::ConstFn<S>::ToUInt32(STRINGCONVERSION flags) const -> Result<UInt32>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<UInt32>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const StringInterface* o_ = (const StringInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = StringInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (o_->ToUInt32(flags));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto StringInterface::Hxx1::ConstFn<S>::ToUInt(STRINGCONVERSION flags) const -> Result<UInt>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<UInt>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const StringInterface* o_ = (const StringInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = StringInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (o_->ToUInt(flags));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto StringInterface::Hxx1::ConstFn<S>::FloatToString(Float32 value, Int charsBeforeComma, Int digitsAfterComma, Bool exponent, Utf32Char fillChar) -> String
{
	return (StringInterface::FloatToString(value, charsBeforeComma, digitsAfterComma, exponent, fillChar));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto StringInterface::Hxx1::ConstFn<S>::FloatToString(Float64 value, Int charsBeforeComma, Int digitsAfterComma, Bool exponent, Utf32Char fillChar) -> String
{
	return (StringInterface::FloatToString(value, charsBeforeComma, digitsAfterComma, exponent, fillChar));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto StringInterface::Hxx1::Fn<S>::AppendInt(Int32 v) const -> DOXYGEN_SWITCH(maxon::RefMemberType<S const>, S)
{
	static_assert(!S::HAS_ERROR, "StringInterface::AppendInt can't be used on a Result object because it does not return a Result object itself."); StringInterface* o_ = (StringInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return this->PrivateGetRefMember(); } 
	if (o_->AppendInt(v) == nullptr) this->ResetReference();
	return this->PrivateGetRefMember();
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto StringInterface::Hxx1::COWFn<S>::AppendInt(Int32 v) -> DOXYGEN_SWITCH(maxon::RefMemberType<S>, S)
{
	static_assert(!S::HAS_ERROR, "StringInterface::AppendInt can't be used on a Result object because it does not return a Result object itself."); StringInterface* o_ = (StringInterface*) this->MakeWritable(true).GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return this->PrivateGetRefMember(); } 
	if (o_->AppendInt(v) == nullptr) this->ResetReference();
	return this->PrivateGetRefMember();
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto StringInterface::Hxx1::Fn<S>::AppendUInt(UInt32 v) const -> DOXYGEN_SWITCH(maxon::RefMemberType<S const>, S)
{
	static_assert(!S::HAS_ERROR, "StringInterface::AppendUInt can't be used on a Result object because it does not return a Result object itself."); StringInterface* o_ = (StringInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return this->PrivateGetRefMember(); } 
	if (o_->AppendUInt(v) == nullptr) this->ResetReference();
	return this->PrivateGetRefMember();
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto StringInterface::Hxx1::COWFn<S>::AppendUInt(UInt32 v) -> DOXYGEN_SWITCH(maxon::RefMemberType<S>, S)
{
	static_assert(!S::HAS_ERROR, "StringInterface::AppendUInt can't be used on a Result object because it does not return a Result object itself."); StringInterface* o_ = (StringInterface*) this->MakeWritable(true).GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return this->PrivateGetRefMember(); } 
	if (o_->AppendUInt(v) == nullptr) this->ResetReference();
	return this->PrivateGetRefMember();
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto StringInterface::Hxx1::Fn<S>::AppendInt(Int64 v) const -> DOXYGEN_SWITCH(maxon::RefMemberType<S const>, S)
{
	static_assert(!S::HAS_ERROR, "StringInterface::AppendInt can't be used on a Result object because it does not return a Result object itself."); StringInterface* o_ = (StringInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return this->PrivateGetRefMember(); } 
	if (o_->AppendInt(v) == nullptr) this->ResetReference();
	return this->PrivateGetRefMember();
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto StringInterface::Hxx1::COWFn<S>::AppendInt(Int64 v) -> DOXYGEN_SWITCH(maxon::RefMemberType<S>, S)
{
	static_assert(!S::HAS_ERROR, "StringInterface::AppendInt can't be used on a Result object because it does not return a Result object itself."); StringInterface* o_ = (StringInterface*) this->MakeWritable(true).GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return this->PrivateGetRefMember(); } 
	if (o_->AppendInt(v) == nullptr) this->ResetReference();
	return this->PrivateGetRefMember();
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto StringInterface::Hxx1::Fn<S>::AppendUInt(UInt64 v) const -> DOXYGEN_SWITCH(maxon::RefMemberType<S const>, S)
{
	static_assert(!S::HAS_ERROR, "StringInterface::AppendUInt can't be used on a Result object because it does not return a Result object itself."); StringInterface* o_ = (StringInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return this->PrivateGetRefMember(); } 
	if (o_->AppendUInt(v) == nullptr) this->ResetReference();
	return this->PrivateGetRefMember();
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto StringInterface::Hxx1::COWFn<S>::AppendUInt(UInt64 v) -> DOXYGEN_SWITCH(maxon::RefMemberType<S>, S)
{
	static_assert(!S::HAS_ERROR, "StringInterface::AppendUInt can't be used on a Result object because it does not return a Result object itself."); StringInterface* o_ = (StringInterface*) this->MakeWritable(true).GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return this->PrivateGetRefMember(); } 
	if (o_->AppendUInt(v) == nullptr) this->ResetReference();
	return this->PrivateGetRefMember();
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto StringInterface::Hxx1::ConstFn<S>::IntToString(Int32 v) -> String
{
	return (StringInterface::IntToString(v));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto StringInterface::Hxx1::ConstFn<S>::UIntToString(UInt32 v) -> String
{
	return (StringInterface::UIntToString(v));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto StringInterface::Hxx1::ConstFn<S>::IntToString(Int64 v) -> String
{
	return (StringInterface::IntToString(v));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto StringInterface::Hxx1::ConstFn<S>::UIntToString(UInt64 v) -> String
{
	return (StringInterface::UIntToString(v));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto StringInterface::Hxx1::ConstFn<S>::MemorySizeToString(Int64 v, Bool mebibytes) -> String
{
	return (StringInterface::MemorySizeToString(v, mebibytes));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto StringInterface::Hxx1::ConstFn<S>::HexToString(UInt32 v, Bool prefix0x) -> String
{
	return (StringInterface::HexToString(v, prefix0x));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto StringInterface::Hxx1::ConstFn<S>::HexToString(UInt64 v, Bool prefix0x) -> String
{
	return (StringInterface::HexToString(v, prefix0x));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto StringInterface::Hxx1::ConstFn<S>::PointerToString(const void* v) -> String
{
	return (StringInterface::PointerToString(v));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto StringInterface::Hxx1::ConstFn<S>::GetUtf32(Utf32CharBuffer& stringData) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const StringInterface* o_ = (const StringInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = StringInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.StringInterface_GetUtf32, stringData));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto StringInterface::Hxx1::Fn<S>::TrimLeft() const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); StringInterface* o_ = (StringInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.StringInterface_TrimLeft));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto StringInterface::Hxx1::COWFn<S>::TrimLeft() -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); StringInterface* o_ = (StringInterface*) this->MakeWritable(true).GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.StringInterface_TrimLeft));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto StringInterface::Hxx1::Fn<S>::TrimRight() const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); StringInterface* o_ = (StringInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.StringInterface_TrimRight));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto StringInterface::Hxx1::COWFn<S>::TrimRight() -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); StringInterface* o_ = (StringInterface*) this->MakeWritable(true).GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.StringInterface_TrimRight));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto StringInterface::Hxx1::ConstFn<S>::Split(const String& splitSymbol, Bool trim, const ValueReceiver<const String&>& parts) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const StringInterface* o_ = (const StringInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = StringInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.StringInterface_Split, splitSymbol, trim, parts));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto StringInterface::Hxx1::Fn<S>::Replace(Utf32Char find, Utf32Char replace) const -> Result<Int>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<Int>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); StringInterface* o_ = (StringInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.StringInterface_Replace, find, replace));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto StringInterface::Hxx1::COWFn<S>::Replace(Utf32Char find, Utf32Char replace) -> Result<Int>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<Int>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); StringInterface* o_ = (StringInterface*) this->MakeWritable(true).GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.StringInterface_Replace, find, replace));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto StringInterface::Hxx1::Fn<S>::Replace(const String& find, const String& replace) const -> Result<Int>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<Int>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); StringInterface* o_ = (StringInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.StringInterface_Replace_1, find, replace));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto StringInterface::Hxx1::COWFn<S>::Replace(const String& find, const String& replace) -> Result<Int>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<Int>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); StringInterface* o_ = (StringInterface*) this->MakeWritable(true).GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.StringInterface_Replace_1, find, replace));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto StringInterface::Hxx1::Fn<S>::Replace(Utf32Char find, const String& replace) const -> Result<Int>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<Int>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); StringInterface* o_ = (StringInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.StringInterface_Replace_2, find, replace));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto StringInterface::Hxx1::COWFn<S>::Replace(Utf32Char find, const String& replace) -> Result<Int>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<Int>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); StringInterface* o_ = (StringInterface*) this->MakeWritable(true).GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.StringInterface_Replace_2, find, replace));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto StringInterface::Hxx1::ConstFn<S>::Find(const String& str, Int* pos, StringPosition start) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const StringInterface* o_ = (const StringInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = StringInterface::NullValuePtr(); if (!o_) return maxon::PrivateLogNullptrError(false); } 
	return (o_->Find(str, pos, std::forward<StringPosition>(start)));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto StringInterface::Hxx1::ConstFn<S>::FindLast(const String& str, Int* pos, StringPosition start) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const StringInterface* o_ = (const StringInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = StringInterface::NullValuePtr(); if (!o_) return maxon::PrivateLogNullptrError(false); } 
	return (o_->FindLast(str, pos, std::forward<StringPosition>(start)));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto StringInterface::Hxx1::ConstFn<S>::Find(Utf32Char ch, Int* pos, StringPosition start) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const StringInterface* o_ = (const StringInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = StringInterface::NullValuePtr(); if (!o_) return maxon::PrivateLogNullptrError(false); } 
	return (o_->Find(ch, pos, std::forward<StringPosition>(start)));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto StringInterface::Hxx1::ConstFn<S>::FindLast(Utf32Char ch, Int* pos, StringPosition start) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const StringInterface* o_ = (const StringInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = StringInterface::NullValuePtr(); if (!o_) return maxon::PrivateLogNullptrError(false); } 
	return (o_->FindLast(ch, pos, std::forward<StringPosition>(start)));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto StringInterface::Hxx1::ConstFn<S>::FindUpper(const String& str, Int* pos, StringPosition start) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const StringInterface* o_ = (const StringInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = StringInterface::NullValuePtr(); if (!o_) return maxon::PrivateLogNullptrError(false); } 
	return (o_->FindUpper(str, pos, std::forward<StringPosition>(start)));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto StringInterface::Hxx1::ConstFn<S>::FindLastUpper(const String& str, Int* pos, StringPosition start) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const StringInterface* o_ = (const StringInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = StringInterface::NullValuePtr(); if (!o_) return maxon::PrivateLogNullptrError(false); } 
	return (o_->FindLastUpper(str, pos, std::forward<StringPosition>(start)));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto StringInterface::Hxx1::ConstFn<S>::GetLeftPart(StringPosition start) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<String>, String>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<String>, String>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const StringInterface* o_ = (const StringInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = StringInterface::NullValuePtr(); if (!o_) return String::NullValue(); } 
	return String(o_->GetLeftPart(std::forward<StringPosition>(start)));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto StringInterface::Hxx1::ConstFn<S>::GetRightPart(StringPosition start) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<String>, String>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<String>, String>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const StringInterface* o_ = (const StringInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = StringInterface::NullValuePtr(); if (!o_) return String::NullValue(); } 
	return String(o_->GetRightPart(std::forward<StringPosition>(start)));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto StringInterface::Hxx1::ConstFn<S>::StartsWith(Utf32Char ch) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const StringInterface* o_ = (const StringInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = StringInterface::NullValuePtr(); if (!o_) return maxon::PrivateLogNullptrError(false); } 
	return (o_->StartsWith(ch));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto StringInterface::Hxx1::ConstFn<S>::StartsWith(const String& str) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const StringInterface* o_ = (const StringInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = StringInterface::NullValuePtr(); if (!o_) return maxon::PrivateLogNullptrError(false); } 
	return (o_->StartsWith(str));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto StringInterface::Hxx1::ConstFn<S>::EndsWith(Utf32Char ch) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const StringInterface* o_ = (const StringInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = StringInterface::NullValuePtr(); if (!o_) return maxon::PrivateLogNullptrError(false); } 
	return (o_->EndsWith(ch));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto StringInterface::Hxx1::ConstFn<S>::EndsWith(const String& str) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const StringInterface* o_ = (const StringInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = StringInterface::NullValuePtr(); if (!o_) return maxon::PrivateLogNullptrError(false); } 
	return (o_->EndsWith(str));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto StringInterface::Hxx1::Fn<S>::Trim() const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); StringInterface* o_ = (StringInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (o_->Trim());
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto StringInterface::Hxx1::COWFn<S>::Trim() -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); StringInterface* o_ = (StringInterface*) this->MakeWritable(true).GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } 
	return (o_->Trim());
}
auto StringInterface::Reference::Create() -> maxon::ResultMemT<String>
{
	StringInterface* res_ = StringInterface::Alloc(MAXON_SOURCE_LOCATION);
	return String(maxon::ForwardResultPtr<StringInterface>(res_));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto StringInterface::Hxx1::ConstFn<S>::GetCStringBlock(const Block<Char>& buffer, const StringEncodingRef& stringEncoding) const -> Result<Int>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<Int>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const StringInterface* o_ = (const StringInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = StringInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.StringInterface_GetCStringBlock, buffer, stringEncoding));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto StringInterface::Hxx1::ConstFn<S>::GetCStringAppendArray(const NonConstArray<Char>& array, const StringEncodingRef& stringEncoding) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const StringInterface* o_ = (const StringInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = StringInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.StringInterface_GetCStringAppendArray, array, stringEncoding));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto StringInterface::Hxx1::ConstFn<S>::GetCString(const StringEncodingRef& stringEncoding) const -> Result<BaseArray<Char>>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<BaseArray<Char>>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const StringInterface* o_ = (const StringInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = StringInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.StringInterface_GetCString, stringEncoding));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto StringInterface::Hxx1::Fn<S>::SetCString(const Char* buffer, Int count, const StringDecodingRef& stringDecoding) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); StringInterface* o_ = (StringInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.StringInterface_SetCString, buffer, count, stringDecoding));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto StringInterface::Hxx1::COWFn<S>::SetCString(const Char* buffer, Int count, const StringDecodingRef& stringDecoding) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); StringInterface* o_ = (StringInterface*) this->MakeWritable(true).GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.StringInterface_SetCString, buffer, count, stringDecoding));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto StringInterface::Hxx1::Fn<S>::SetCString(const Block<const Char>& buffer, const StringDecodingRef& stringDecoding) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); StringInterface* o_ = (StringInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (o_->SetCString(buffer, stringDecoding));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto StringInterface::Hxx1::COWFn<S>::SetCString(const Block<const Char>& buffer, const StringDecodingRef& stringDecoding) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); StringInterface* o_ = (StringInterface*) this->MakeWritable(true).GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } 
	return (o_->SetCString(buffer, stringDecoding));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto StringInterface::Hxx1::ConstFn<S>::GetSystemEncoding() const -> Result<SysCharArray>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<SysCharArray>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const StringInterface* o_ = (const StringInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = StringInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.StringInterface_GetSystemEncoding));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto StringInterface::Hxx1::Fn<S>::SetSystemEncoding(const SysChar* buffer, Int count) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); StringInterface* o_ = (StringInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.StringInterface_SetSystemEncoding, buffer, count));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto StringInterface::Hxx1::COWFn<S>::SetSystemEncoding(const SysChar* buffer, Int count) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); StringInterface* o_ = (StringInterface*) this->MakeWritable(true).GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.StringInterface_SetSystemEncoding, buffer, count));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto StringInterface::Hxx1::Fn<S>::SetUtf32(const Utf32Char* buffer, Int count) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); StringInterface* o_ = (StringInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.StringInterface_SetUtf32, buffer, count));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto StringInterface::Hxx1::COWFn<S>::SetUtf32(const Utf32Char* buffer, Int count) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); StringInterface* o_ = (StringInterface*) this->MakeWritable(true).GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.StringInterface_SetUtf32, buffer, count));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto StringInterface::Hxx1::ConstFn<S>::GetUtf16(Utf16CharBuffer& stringData) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const StringInterface* o_ = (const StringInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = StringInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.StringInterface_GetUtf16, stringData));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto StringInterface::Hxx1::Fn<S>::SetUtf16(const Utf16Char* buffer, Int count) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); StringInterface* o_ = (StringInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.StringInterface_SetUtf16, buffer, count));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto StringInterface::Hxx1::COWFn<S>::SetUtf16(const Utf16Char* buffer, Int count) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); StringInterface* o_ = (StringInterface*) this->MakeWritable(true).GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.StringInterface_SetUtf16, buffer, count));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto StringInterface::Hxx1::ConstFn<S>::GetAndCacheConstString(const wchar_t* chr, Int len) -> const String&
{
	return (MTable::_instance.StringInterface_GetAndCacheConstString(chr, len));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto StringInterface::Hxx1::ConstFn<S>::GetAndCacheConstString(const Char* chr, Int len, Int isUtf8) -> const String&
{
	return (MTable::_instance.StringInterface_GetAndCacheConstString_1(chr, len, isUtf8));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto StringInterface::Hxx1::ConstFn<S>::GetVariableInternalData() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<StridedBlock<const Generic>>, StridedBlock<const Generic>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<StridedBlock<const Generic>>, StridedBlock<const Generic>>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const StringInterface* o_ = (const StringInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = StringInterface::NullValuePtr(); if (!o_) return maxon::PrivateIncompleteNullReturnValue<StridedBlock<const Generic>>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.StringInterface_GetVariableInternalData));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto StringInterface::Hxx1::ConstFn<S>::GetCharacterWidth() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const StringInterface* o_ = (const StringInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = StringInterface::NullValuePtr(); if (!o_) return 0; } 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.StringInterface_GetCharacterWidth));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto StringInterface::Hxx1::ConstFn<S>::ConvertString(const StreamConversionRef& converter) const -> Result<String>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<String>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const StringInterface* o_ = (const StringInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = StringInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (o_->ConvertString(converter));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto StringInterface::Hxx1::ConstFn<S>::Prettify(Int indent, const String& indentStr, Int breakUpThreshold, Bool angularBrackets) const -> Result<String>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<String>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const StringInterface* o_ = (const StringInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = StringInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.StringInterface_Prettify, indent, indentStr, breakUpThreshold, angularBrackets));
}
#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT) && !defined(MAXON_DEPENDENCY_DISABLE_string)
#ifdef MAXON_USE_REGISTER_FUNCTION
MAXON_STATIC_STORAGE(maxon::EntityUse, s_ui_maxon_StringInterface); \
MAXON_ATTRIBUTE_CONSTRUCTOR static void Register_s_ui_maxon_StringInterface() { new (s_ui_maxon_StringInterface) maxon::EntityUse(StringInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/string.h", false); }
#else // !MAXON_USE_REGISTER_FUNCTION
static maxon::EntityUse s_ui_maxon_StringInterface(StringInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/string.h", false);
#endif // MAXON_USE_REGISTER_FUNCTION
#endif
constexpr const maxon::Char* CStringInterface::PrivateGetCppName() { return "maxon::CString"; }

struct CStringInterface::MTable
{
	static MTable _instance;
	static MTable _unresolvedInstance;
	static const maxon::Char* const _ids;
	static maxon::Bool InitUnresolved(maxon::NonvirtualInterfaceReference::UnresolvedAssembler assembler, MTable* tbl);
	static const maxon::NULL_RETURN_TYPE _returnTypes[];
	static const maxon::Bool HAS_NONSTATIC = true;
	PRIVATE_MAXON_SF_POINTER(CStringInterface_Free, Free, MAXON_EXPAND_VA_ARGS, (void), const CStringInterface* object);
	PRIVATE_MAXON_MF_POINTER(CStringInterface_GetLength, GetLength, false, CStringInterface, const, (Int));
	PRIVATE_MAXON_MF_POINTER(CStringInterface_Init, Init, false, CStringInterface,, (Result<void>), Int count, Char fillChar);
	PRIVATE_MAXON_MF_POINTER(CStringInterface_Shrink, Shrink, false, CStringInterface,, (Result<void>));
	PRIVATE_MAXON_MF_POINTER(CStringInterface_Append, Append, false, CStringInterface,, (Result<void>), const CStringInterface* str);
	PRIVATE_MAXON_MF_POINTER(CStringInterface_Append_1, Append, false, CStringInterface,, (Result<void>), const Char* str, Int len);
	PRIVATE_MAXON_MF_POINTER(CStringInterface_FindIndex, FindIndex, false, CStringInterface, const, (Int), const CStringInterface* str, StringPosition start);
	PRIVATE_MAXON_MF_POINTER(CStringInterface_FindLastIndex, FindLastIndex, false, CStringInterface, const, (Int), const CStringInterface* str, StringPosition start);
	PRIVATE_MAXON_MF_POINTER(CStringInterface_FindIndex_1, FindIndex, false, CStringInterface, const, (Int), Char ch, StringPosition start);
	PRIVATE_MAXON_MF_POINTER(CStringInterface_FindLastIndex_1, FindLastIndex, false, CStringInterface, const, (Int), Char ch, StringPosition start);
	PRIVATE_MAXON_MF_POINTER(CStringInterface_FindUpperIndex, FindUpperIndex, false, CStringInterface, const, (Int), const CStringInterface* str, StringPosition start);
	PRIVATE_MAXON_MF_POINTER(CStringInterface_FindLastUpperIndex, FindLastUpperIndex, false, CStringInterface, const, (Int), const CStringInterface* str, StringPosition start);
	PRIVATE_MAXON_MF_POINTER(CStringInterface_Erase, Erase, false, CStringInterface,, (Result<void>), StringPosition position, StringCount count);
	PRIVATE_MAXON_MF_POINTER(CStringInterface_Insert, Insert, false, CStringInterface,, (Result<void>), StringPosition position, const CStringInterface* str, StringPosition strStart, StringCount strCount);
	PRIVATE_MAXON_MF_POINTER(CStringInterface_Insert_1, Insert, false, CStringInterface,, (Result<void>), StringPosition position, Char ch);
	PRIVATE_MAXON_MF_POINTER(CStringInterface_GetPart, GetPart, false, CStringInterface, const, (CStringInterface*), StringPosition start, StringCount count);
	PRIVATE_MAXON_MF_POINTER(CStringInterface_ToUpper, ToUpper, false, CStringInterface, const, (CStringInterface*));
	PRIVATE_MAXON_MF_POINTER(CStringInterface_ToLower, ToLower, false, CStringInterface, const, (CStringInterface*));
	PRIVATE_MAXON_MF_POINTER(CStringInterface_ComparePart, ComparePart, false, CStringInterface, const, (COMPARERESULT), const CStringInterface* str, STRINGCOMPARISON mode, StringPosition position, StringCount count);
	PRIVATE_MAXON_MF_POINTER(CStringInterface_GetHashCode, GetHashCode, false, CStringInterface, const, (HashInt));
	PRIVATE_MAXON_MF_POINTER(CStringInterface_GetUniqueHashCode, GetUniqueHashCode, false, CStringInterface, const, (UniqueHash));
	PRIVATE_MAXON_MF_POINTER(CStringInterface_SetChar, SetChar, false, CStringInterface,, (void), Int pos, Char ch);
	PRIVATE_MAXON_MF_POINTER(CStringInterface_GetChar, GetChar, false, CStringInterface, const, (Char), Int pos);
	PRIVATE_MAXON_MF_POINTER(CStringInterface_GetUtf32, GetUtf32, false, CStringInterface, const, (Result<void>), Utf32CharBuffer& stringData);
	PRIVATE_MAXON_MF_POINTER(CStringInterface_TrimLeft, TrimLeft, false, CStringInterface,, (Result<void>));
	PRIVATE_MAXON_MF_POINTER(CStringInterface_TrimRight, TrimRight, false, CStringInterface,, (Result<void>));
	PRIVATE_MAXON_MF_POINTER(CStringInterface_Split, Split, false, CStringInterface, const, (Result<void>), const CString& splitSymbol, Bool trim, const ValueReceiver<const CString&>& parts);
	PRIVATE_MAXON_MF_POINTER(CStringInterface_Replace, Replace, false, CStringInterface,, (Result<Int>), Char find, Char replace);
	PRIVATE_MAXON_MF_POINTER(CStringInterface_Replace_1, Replace, false, CStringInterface,, (Result<Int>), const CString& find, const CString& replace);
	PRIVATE_MAXON_MF_POINTER(CStringInterface_Replace_2, Replace, false, CStringInterface,, (Result<Int>), Char find, const CString& replace);
	PRIVATE_MAXON_SF_POINTER(CStringInterface_Alloc, Alloc, MAXON_IGNORE_VA_ARGS, (CStringInterface*), const maxon::SourceLocation& allocLocation);
	PRIVATE_MAXON_SF_POINTER(CStringInterface_Alloc_1, Alloc, MAXON_IGNORE_VA_ARGS, (CStringInterface*), const maxon::SourceLocation& allocLocation, const CStringInterface& object);
	PRIVATE_MAXON_MF_POINTER(CStringInterface_GetCStringBlock, GetCStringBlock, false, CStringInterface, const, (Result<Int>), const Block<Char>& buffer);
	PRIVATE_MAXON_MF_POINTER(CStringInterface_GetCStringAppendArray, GetCStringAppendArray, false, CStringInterface, const, (Result<void>), const NonConstArray<Char>& array);
	PRIVATE_MAXON_MF_POINTER(CStringInterface_Disconnect, Disconnect, false, CStringInterface,, (Result<Block<Char>>));
	PRIVATE_MAXON_MF_POINTER(CStringInterface_SetCString, SetCString, false, CStringInterface,, (Result<void>), const Char* buffer, Int count);
	PRIVATE_MAXON_MF_POINTER(CStringInterface_GetCString, GetCString, false, CStringInterface, const, (Result<BaseArray<Char>>));
	PRIVATE_MAXON_MF_POINTER(CStringInterface_GetInternalData, GetInternalData, false, CStringInterface, const, (Block<const Char>));
	PRIVATE_MAXON_SF_POINTER(CStringInterface_GetAndCacheConstString, GetAndCacheConstString, MAXON_EXPAND_VA_ARGS, (const CString&), const Char* chr, Int len);
	template <typename IMPL> void Init()
	{
		CStringInterface_Free = CStringInterface_Free_GetPtr<IMPL>(true);
		CStringInterface_GetLength = CStringInterface_GetLength_GetPtr<IMPL>(0, true).first;
		CStringInterface_Init = CStringInterface_Init_GetPtr<IMPL>(0, true).first;
		CStringInterface_Shrink = CStringInterface_Shrink_GetPtr<IMPL>(0, true).first;
		CStringInterface_Append = CStringInterface_Append_GetPtr<IMPL>(0, true).first;
		CStringInterface_Append_1 = CStringInterface_Append_1_GetPtr<IMPL>(0, true).first;
		CStringInterface_FindIndex = CStringInterface_FindIndex_GetPtr<IMPL>(0, true).first;
		CStringInterface_FindLastIndex = CStringInterface_FindLastIndex_GetPtr<IMPL>(0, true).first;
		CStringInterface_FindIndex_1 = CStringInterface_FindIndex_1_GetPtr<IMPL>(0, true).first;
		CStringInterface_FindLastIndex_1 = CStringInterface_FindLastIndex_1_GetPtr<IMPL>(0, true).first;
		CStringInterface_FindUpperIndex = CStringInterface_FindUpperIndex_GetPtr<IMPL>(0, true).first;
		CStringInterface_FindLastUpperIndex = CStringInterface_FindLastUpperIndex_GetPtr<IMPL>(0, true).first;
		CStringInterface_Erase = CStringInterface_Erase_GetPtr<IMPL>(0, true).first;
		CStringInterface_Insert = CStringInterface_Insert_GetPtr<IMPL>(0, true).first;
		CStringInterface_Insert_1 = CStringInterface_Insert_1_GetPtr<IMPL>(0, true).first;
		CStringInterface_GetPart = CStringInterface_GetPart_GetPtr<IMPL>(0, true).first;
		CStringInterface_ToUpper = CStringInterface_ToUpper_GetPtr<IMPL>(0, true).first;
		CStringInterface_ToLower = CStringInterface_ToLower_GetPtr<IMPL>(0, true).first;
		CStringInterface_ComparePart = CStringInterface_ComparePart_GetPtr<IMPL>(0, true).first;
		CStringInterface_GetHashCode = CStringInterface_GetHashCode_GetPtr<IMPL>(0, true).first;
		CStringInterface_GetUniqueHashCode = CStringInterface_GetUniqueHashCode_GetPtr<IMPL>(0, true).first;
		CStringInterface_SetChar = CStringInterface_SetChar_GetPtr<IMPL>(0, true).first;
		CStringInterface_GetChar = CStringInterface_GetChar_GetPtr<IMPL>(0, true).first;
		CStringInterface_GetUtf32 = CStringInterface_GetUtf32_GetPtr<IMPL>(0, true).first;
		CStringInterface_TrimLeft = CStringInterface_TrimLeft_GetPtr<IMPL>(0, true).first;
		CStringInterface_TrimRight = CStringInterface_TrimRight_GetPtr<IMPL>(0, true).first;
		CStringInterface_Split = CStringInterface_Split_GetPtr<IMPL>(0, true).first;
		CStringInterface_Replace = CStringInterface_Replace_GetPtr<IMPL>(0, true).first;
		CStringInterface_Replace_1 = CStringInterface_Replace_1_GetPtr<IMPL>(0, true).first;
		CStringInterface_Replace_2 = CStringInterface_Replace_2_GetPtr<IMPL>(0, true).first;
		CStringInterface_Alloc = CStringInterface_Alloc_GetPtr<IMPL>(true);
		CStringInterface_Alloc_1 = CStringInterface_Alloc_1_GetPtr<IMPL>(true);
		CStringInterface_GetCStringBlock = CStringInterface_GetCStringBlock_GetPtr<IMPL>(0, true).first;
		CStringInterface_GetCStringAppendArray = CStringInterface_GetCStringAppendArray_GetPtr<IMPL>(0, true).first;
		CStringInterface_Disconnect = CStringInterface_Disconnect_GetPtr<IMPL>(0, true).first;
		CStringInterface_SetCString = CStringInterface_SetCString_GetPtr<IMPL>(0, true).first;
		CStringInterface_GetCString = CStringInterface_GetCString_GetPtr<IMPL>(0, true).first;
		CStringInterface_GetInternalData = CStringInterface_GetInternalData_GetPtr<IMPL>(0, true).first;
		CStringInterface_GetAndCacheConstString = CStringInterface_GetAndCacheConstString_GetPtr<IMPL>(true);
	}
};

struct CStringInterface::Hxx2
{
	class Unresolved;
	template <typename C> class Wrapper
	{
	public:
		using Implementation = C;
		static void CStringInterface_Free(const CStringInterface* object) { return C::Free(object); }
		PRIVATE_MAXON_MF_WRAPPER(CStringInterface_GetLength, CStringInterface, const, (Int)) { return C::Get(PRIVATE_MAXON_MF_THIS(const CStringInterface))->GetLength(); }
		PRIVATE_MAXON_MF_WRAPPER(CStringInterface_Init, CStringInterface,, (Result<void>), Int count, Char fillChar) { return C::Get(PRIVATE_MAXON_MF_THIS(CStringInterface))->Init(count, fillChar); }
		PRIVATE_MAXON_MF_WRAPPER(CStringInterface_Shrink, CStringInterface,, (Result<void>)) { return C::Get(PRIVATE_MAXON_MF_THIS(CStringInterface))->Shrink(); }
		PRIVATE_MAXON_MF_WRAPPER(CStringInterface_Append, CStringInterface,, (Result<void>), const CStringInterface* str) { return C::Get(PRIVATE_MAXON_MF_THIS(CStringInterface))->Append(str); }
		PRIVATE_MAXON_MF_WRAPPER(CStringInterface_Append_1, CStringInterface,, (Result<void>), const Char* str, Int len) { return C::Get(PRIVATE_MAXON_MF_THIS(CStringInterface))->Append(str, len); }
		PRIVATE_MAXON_MF_WRAPPER(CStringInterface_FindIndex, CStringInterface, const, (Int), const CStringInterface* str, StringPosition start) { return C::Get(PRIVATE_MAXON_MF_THIS(const CStringInterface))->FindIndex(str, std::forward<StringPosition>(start)); }
		PRIVATE_MAXON_MF_WRAPPER(CStringInterface_FindLastIndex, CStringInterface, const, (Int), const CStringInterface* str, StringPosition start) { return C::Get(PRIVATE_MAXON_MF_THIS(const CStringInterface))->FindLastIndex(str, std::forward<StringPosition>(start)); }
		PRIVATE_MAXON_MF_WRAPPER(CStringInterface_FindIndex_1, CStringInterface, const, (Int), Char ch, StringPosition start) { return C::Get(PRIVATE_MAXON_MF_THIS(const CStringInterface))->FindIndex(ch, std::forward<StringPosition>(start)); }
		PRIVATE_MAXON_MF_WRAPPER(CStringInterface_FindLastIndex_1, CStringInterface, const, (Int), Char ch, StringPosition start) { return C::Get(PRIVATE_MAXON_MF_THIS(const CStringInterface))->FindLastIndex(ch, std::forward<StringPosition>(start)); }
		PRIVATE_MAXON_MF_WRAPPER(CStringInterface_FindUpperIndex, CStringInterface, const, (Int), const CStringInterface* str, StringPosition start) { return C::Get(PRIVATE_MAXON_MF_THIS(const CStringInterface))->FindUpperIndex(str, std::forward<StringPosition>(start)); }
		PRIVATE_MAXON_MF_WRAPPER(CStringInterface_FindLastUpperIndex, CStringInterface, const, (Int), const CStringInterface* str, StringPosition start) { return C::Get(PRIVATE_MAXON_MF_THIS(const CStringInterface))->FindLastUpperIndex(str, std::forward<StringPosition>(start)); }
		PRIVATE_MAXON_MF_WRAPPER(CStringInterface_Erase, CStringInterface,, (Result<void>), StringPosition position, StringCount count) { return C::Get(PRIVATE_MAXON_MF_THIS(CStringInterface))->Erase(std::forward<StringPosition>(position), std::forward<StringCount>(count)); }
		PRIVATE_MAXON_MF_WRAPPER(CStringInterface_Insert, CStringInterface,, (Result<void>), StringPosition position, const CStringInterface* str, StringPosition strStart, StringCount strCount) { return C::Get(PRIVATE_MAXON_MF_THIS(CStringInterface))->Insert(std::forward<StringPosition>(position), str, std::forward<StringPosition>(strStart), std::forward<StringCount>(strCount)); }
		PRIVATE_MAXON_MF_WRAPPER(CStringInterface_Insert_1, CStringInterface,, (Result<void>), StringPosition position, Char ch) { return C::Get(PRIVATE_MAXON_MF_THIS(CStringInterface))->Insert(std::forward<StringPosition>(position), ch); }
		PRIVATE_MAXON_MF_WRAPPER(CStringInterface_GetPart, CStringInterface, const, (CStringInterface*), StringPosition start, StringCount count) { return C::Get(PRIVATE_MAXON_MF_THIS(const CStringInterface))->GetPart(std::forward<StringPosition>(start), std::forward<StringCount>(count)); }
		PRIVATE_MAXON_MF_WRAPPER(CStringInterface_ToUpper, CStringInterface, const, (CStringInterface*)) { return C::Get(PRIVATE_MAXON_MF_THIS(const CStringInterface))->ToUpper(); }
		PRIVATE_MAXON_MF_WRAPPER(CStringInterface_ToLower, CStringInterface, const, (CStringInterface*)) { return C::Get(PRIVATE_MAXON_MF_THIS(const CStringInterface))->ToLower(); }
		PRIVATE_MAXON_MF_WRAPPER(CStringInterface_ComparePart, CStringInterface, const, (COMPARERESULT), const CStringInterface* str, STRINGCOMPARISON mode, StringPosition position, StringCount count) { return C::Get(PRIVATE_MAXON_MF_THIS(const CStringInterface))->ComparePart(str, mode, std::forward<StringPosition>(position), std::forward<StringCount>(count)); }
		PRIVATE_MAXON_MF_WRAPPER(CStringInterface_GetHashCode, CStringInterface, const, (HashInt)) { return C::Get(PRIVATE_MAXON_MF_THIS(const CStringInterface))->GetHashCode(); }
		PRIVATE_MAXON_MF_WRAPPER(CStringInterface_GetUniqueHashCode, CStringInterface, const, (UniqueHash)) { return C::Get(PRIVATE_MAXON_MF_THIS(const CStringInterface))->GetUniqueHashCode(); }
		PRIVATE_MAXON_MF_WRAPPER(CStringInterface_SetChar, CStringInterface,, (void), Int pos, Char ch) { return C::Get(PRIVATE_MAXON_MF_THIS(CStringInterface))->SetChar(pos, ch); }
		PRIVATE_MAXON_MF_WRAPPER(CStringInterface_GetChar, CStringInterface, const, (Char), Int pos) { return C::Get(PRIVATE_MAXON_MF_THIS(const CStringInterface))->GetChar(pos); }
		PRIVATE_MAXON_MF_WRAPPER(CStringInterface_GetUtf32, CStringInterface, const, (Result<void>), Utf32CharBuffer& stringData) { return C::Get(PRIVATE_MAXON_MF_THIS(const CStringInterface))->GetUtf32(stringData); }
		PRIVATE_MAXON_MF_WRAPPER(CStringInterface_TrimLeft, CStringInterface,, (Result<void>)) { return C::Get(PRIVATE_MAXON_MF_THIS(CStringInterface))->TrimLeft(); }
		PRIVATE_MAXON_MF_WRAPPER(CStringInterface_TrimRight, CStringInterface,, (Result<void>)) { return C::Get(PRIVATE_MAXON_MF_THIS(CStringInterface))->TrimRight(); }
		PRIVATE_MAXON_MF_WRAPPER(CStringInterface_Split, CStringInterface, const, (Result<void>), const CString& splitSymbol, Bool trim, const ValueReceiver<const CString&>& parts) { return C::Get(PRIVATE_MAXON_MF_THIS(const CStringInterface))->Split(splitSymbol, trim, parts); }
		PRIVATE_MAXON_MF_WRAPPER(CStringInterface_Replace, CStringInterface,, (Result<Int>), Char find, Char replace) { return C::Get(PRIVATE_MAXON_MF_THIS(CStringInterface))->Replace(find, replace); }
		PRIVATE_MAXON_MF_WRAPPER(CStringInterface_Replace_1, CStringInterface,, (Result<Int>), const CString& find, const CString& replace) { return C::Get(PRIVATE_MAXON_MF_THIS(CStringInterface))->Replace(find, replace); }
		PRIVATE_MAXON_MF_WRAPPER(CStringInterface_Replace_2, CStringInterface,, (Result<Int>), Char find, const CString& replace) { return C::Get(PRIVATE_MAXON_MF_THIS(CStringInterface))->Replace(find, replace); }
		static CStringInterface* CStringInterface_Alloc(const maxon::SourceLocation& allocLocation) { return C::Alloc(allocLocation); }
		static CStringInterface* CStringInterface_Alloc_1(const maxon::SourceLocation& allocLocation, const CStringInterface& object) { return C::Alloc(allocLocation, ((const C&) object)); }
		PRIVATE_MAXON_MF_WRAPPER(CStringInterface_GetCStringBlock, CStringInterface, const, (Result<Int>), const Block<Char>& buffer) { return C::Get(PRIVATE_MAXON_MF_THIS(const CStringInterface))->GetCStringBlock(buffer); }
		PRIVATE_MAXON_MF_WRAPPER(CStringInterface_GetCStringAppendArray, CStringInterface, const, (Result<void>), const NonConstArray<Char>& array) { return C::Get(PRIVATE_MAXON_MF_THIS(const CStringInterface))->GetCStringAppendArray(array); }
		PRIVATE_MAXON_MF_WRAPPER(CStringInterface_Disconnect, CStringInterface,, (Result<Block<Char>>)) { return C::Get(PRIVATE_MAXON_MF_THIS(CStringInterface))->Disconnect(); }
		PRIVATE_MAXON_MF_WRAPPER(CStringInterface_SetCString, CStringInterface,, (Result<void>), const Char* buffer, Int count) { return C::Get(PRIVATE_MAXON_MF_THIS(CStringInterface))->SetCString(buffer, count); }
		PRIVATE_MAXON_MF_WRAPPER(CStringInterface_GetCString, CStringInterface, const, (Result<BaseArray<Char>>)) { return C::Get(PRIVATE_MAXON_MF_THIS(const CStringInterface))->GetCString(); }
		PRIVATE_MAXON_MF_WRAPPER(CStringInterface_GetInternalData, CStringInterface, const, (Block<const Char>)) { return C::Get(PRIVATE_MAXON_MF_THIS(const CStringInterface))->GetInternalData(); }
		static const CString& CStringInterface_GetAndCacheConstString(const Char* chr, Int len) { return C::GetAndCacheConstString(chr, len); }
	};

};
MAXON_ATTRIBUTE_FORCE_INLINE auto CStringInterface::Free(const CStringInterface* object) -> void
{
	return MTable::_instance.CStringInterface_Free(object);
}
template <> MAXON_ATTRIBUTE_FORCE_INLINE auto StringTemplate<CStringInterface,CString,Char>::GetLength() const -> Int
{
	return PRIVATE_MAXON_MF_INVOKE((static_cast<const CStringInterface*>(this)), CStringInterface::MTable::_instance.CStringInterface_GetLength);
}
template <> MAXON_ATTRIBUTE_FORCE_INLINE auto StringTemplate<CStringInterface,CString,Char>::Init(Int count, Char fillChar) -> Result<void>
{
	return PRIVATE_MAXON_MF_INVOKE((static_cast<CStringInterface*>(this)), CStringInterface::MTable::_instance.CStringInterface_Init, count, fillChar);
}
template <> MAXON_ATTRIBUTE_FORCE_INLINE auto StringTemplate<CStringInterface,CString,Char>::Shrink() -> Result<void>
{
	return PRIVATE_MAXON_MF_INVOKE((static_cast<CStringInterface*>(this)), CStringInterface::MTable::_instance.CStringInterface_Shrink);
}
template <> MAXON_ATTRIBUTE_FORCE_INLINE auto StringTemplate<CStringInterface,CString,Char>::Append(const CStringInterface* str) -> Result<void>
{
	return PRIVATE_MAXON_MF_INVOKE((static_cast<CStringInterface*>(this)), CStringInterface::MTable::_instance.CStringInterface_Append, str);
}
template <> MAXON_ATTRIBUTE_FORCE_INLINE auto StringTemplate<CStringInterface,CString,Char>::Append(const Char* str, Int len) -> Result<void>
{
	return PRIVATE_MAXON_MF_INVOKE((static_cast<CStringInterface*>(this)), CStringInterface::MTable::_instance.CStringInterface_Append_1, str, len);
}
template <> MAXON_ATTRIBUTE_FORCE_INLINE auto StringTemplate<CStringInterface,CString,Char>::FindIndex(const CStringInterface* str, StringPosition start) const -> Int
{
	return PRIVATE_MAXON_MF_INVOKE((static_cast<const CStringInterface*>(this)), CStringInterface::MTable::_instance.CStringInterface_FindIndex, str, std::forward<StringPosition>(start));
}
template <> MAXON_ATTRIBUTE_FORCE_INLINE auto StringTemplate<CStringInterface,CString,Char>::FindLastIndex(const CStringInterface* str, StringPosition start) const -> Int
{
	return PRIVATE_MAXON_MF_INVOKE((static_cast<const CStringInterface*>(this)), CStringInterface::MTable::_instance.CStringInterface_FindLastIndex, str, std::forward<StringPosition>(start));
}
template <> MAXON_ATTRIBUTE_FORCE_INLINE auto StringTemplate<CStringInterface,CString,Char>::FindIndex(Char ch, StringPosition start) const -> Int
{
	return PRIVATE_MAXON_MF_INVOKE((static_cast<const CStringInterface*>(this)), CStringInterface::MTable::_instance.CStringInterface_FindIndex_1, ch, std::forward<StringPosition>(start));
}
template <> MAXON_ATTRIBUTE_FORCE_INLINE auto StringTemplate<CStringInterface,CString,Char>::FindLastIndex(Char ch, StringPosition start) const -> Int
{
	return PRIVATE_MAXON_MF_INVOKE((static_cast<const CStringInterface*>(this)), CStringInterface::MTable::_instance.CStringInterface_FindLastIndex_1, ch, std::forward<StringPosition>(start));
}
template <> MAXON_ATTRIBUTE_FORCE_INLINE auto StringTemplate<CStringInterface,CString,Char>::FindUpperIndex(const CStringInterface* str, StringPosition start) const -> Int
{
	return PRIVATE_MAXON_MF_INVOKE((static_cast<const CStringInterface*>(this)), CStringInterface::MTable::_instance.CStringInterface_FindUpperIndex, str, std::forward<StringPosition>(start));
}
template <> MAXON_ATTRIBUTE_FORCE_INLINE auto StringTemplate<CStringInterface,CString,Char>::FindLastUpperIndex(const CStringInterface* str, StringPosition start) const -> Int
{
	return PRIVATE_MAXON_MF_INVOKE((static_cast<const CStringInterface*>(this)), CStringInterface::MTable::_instance.CStringInterface_FindLastUpperIndex, str, std::forward<StringPosition>(start));
}
template <> MAXON_ATTRIBUTE_FORCE_INLINE auto StringTemplate<CStringInterface,CString,Char>::Erase(StringPosition position, StringCount count) -> Result<void>
{
	return PRIVATE_MAXON_MF_INVOKE((static_cast<CStringInterface*>(this)), CStringInterface::MTable::_instance.CStringInterface_Erase, std::forward<StringPosition>(position), std::forward<StringCount>(count));
}
template <> MAXON_ATTRIBUTE_FORCE_INLINE auto StringTemplate<CStringInterface,CString,Char>::Insert(StringPosition position, const CStringInterface* str, StringPosition strStart, StringCount strCount) -> Result<void>
{
	return PRIVATE_MAXON_MF_INVOKE((static_cast<CStringInterface*>(this)), CStringInterface::MTable::_instance.CStringInterface_Insert, std::forward<StringPosition>(position), str, std::forward<StringPosition>(strStart), std::forward<StringCount>(strCount));
}
template <> MAXON_ATTRIBUTE_FORCE_INLINE auto StringTemplate<CStringInterface,CString,Char>::Insert(StringPosition position, Char ch) -> Result<void>
{
	return PRIVATE_MAXON_MF_INVOKE((static_cast<CStringInterface*>(this)), CStringInterface::MTable::_instance.CStringInterface_Insert_1, std::forward<StringPosition>(position), ch);
}
template <> MAXON_ATTRIBUTE_FORCE_INLINE auto StringTemplate<CStringInterface,CString,Char>::GetPart(StringPosition start, StringCount count) const -> CStringInterface*
{
	return PRIVATE_MAXON_MF_INVOKE((static_cast<const CStringInterface*>(this)), CStringInterface::MTable::_instance.CStringInterface_GetPart, std::forward<StringPosition>(start), std::forward<StringCount>(count));
}
template <> MAXON_ATTRIBUTE_FORCE_INLINE auto StringTemplate<CStringInterface,CString,Char>::ToUpper() const -> CStringInterface*
{
	return PRIVATE_MAXON_MF_INVOKE((static_cast<const CStringInterface*>(this)), CStringInterface::MTable::_instance.CStringInterface_ToUpper);
}
template <> MAXON_ATTRIBUTE_FORCE_INLINE auto StringTemplate<CStringInterface,CString,Char>::ToLower() const -> CStringInterface*
{
	return PRIVATE_MAXON_MF_INVOKE((static_cast<const CStringInterface*>(this)), CStringInterface::MTable::_instance.CStringInterface_ToLower);
}
template <> MAXON_ATTRIBUTE_FORCE_INLINE auto StringTemplate<CStringInterface,CString,Char>::ComparePart(const CStringInterface* str, STRINGCOMPARISON mode, StringPosition position, StringCount count) const -> COMPARERESULT
{
	return PRIVATE_MAXON_MF_INVOKE((static_cast<const CStringInterface*>(this)), CStringInterface::MTable::_instance.CStringInterface_ComparePart, str, mode, std::forward<StringPosition>(position), std::forward<StringCount>(count));
}
template <> MAXON_ATTRIBUTE_FORCE_INLINE auto StringTemplate<CStringInterface,CString,Char>::GetHashCode() const -> HashInt
{
	return PRIVATE_MAXON_MF_INVOKE((static_cast<const CStringInterface*>(this)), CStringInterface::MTable::_instance.CStringInterface_GetHashCode);
}
template <> MAXON_ATTRIBUTE_FORCE_INLINE auto StringTemplate<CStringInterface,CString,Char>::GetUniqueHashCode() const -> UniqueHash
{
	return PRIVATE_MAXON_MF_INVOKE((static_cast<const CStringInterface*>(this)), CStringInterface::MTable::_instance.CStringInterface_GetUniqueHashCode);
}
template <> MAXON_ATTRIBUTE_FORCE_INLINE auto StringTemplate<CStringInterface,CString,Char>::SetChar(Int pos, Char ch) -> void
{
	return PRIVATE_MAXON_MF_INVOKE((static_cast<CStringInterface*>(this)), CStringInterface::MTable::_instance.CStringInterface_SetChar, pos, ch);
}
template <> MAXON_ATTRIBUTE_FORCE_INLINE auto StringTemplate<CStringInterface,CString,Char>::GetChar(Int pos) const -> Char
{
	return PRIVATE_MAXON_MF_INVOKE((static_cast<const CStringInterface*>(this)), CStringInterface::MTable::_instance.CStringInterface_GetChar, pos);
}
template <> MAXON_ATTRIBUTE_FORCE_INLINE auto StringTemplate<CStringInterface,CString,Char>::GetUtf32(Utf32CharBuffer& stringData) const -> Result<void>
{
	return PRIVATE_MAXON_MF_INVOKE((static_cast<const CStringInterface*>(this)), CStringInterface::MTable::_instance.CStringInterface_GetUtf32, stringData);
}
template <> MAXON_ATTRIBUTE_FORCE_INLINE auto StringTemplate<CStringInterface,CString,Char>::TrimLeft() -> Result<void>
{
	return PRIVATE_MAXON_MF_INVOKE((static_cast<CStringInterface*>(this)), CStringInterface::MTable::_instance.CStringInterface_TrimLeft);
}
template <> MAXON_ATTRIBUTE_FORCE_INLINE auto StringTemplate<CStringInterface,CString,Char>::TrimRight() -> Result<void>
{
	return PRIVATE_MAXON_MF_INVOKE((static_cast<CStringInterface*>(this)), CStringInterface::MTable::_instance.CStringInterface_TrimRight);
}
template <> MAXON_ATTRIBUTE_FORCE_INLINE auto StringTemplate<CStringInterface,CString,Char>::Split(const CString& splitSymbol, Bool trim, const ValueReceiver<const CString&>& parts) const -> Result<void>
{
	return PRIVATE_MAXON_MF_INVOKE((static_cast<const CStringInterface*>(this)), CStringInterface::MTable::_instance.CStringInterface_Split, splitSymbol, trim, parts);
}
template <> MAXON_ATTRIBUTE_FORCE_INLINE auto StringTemplate<CStringInterface,CString,Char>::Replace(Char find, Char replace) -> Result<Int>
{
	return PRIVATE_MAXON_MF_INVOKE((static_cast<CStringInterface*>(this)), CStringInterface::MTable::_instance.CStringInterface_Replace, find, replace);
}
template <> MAXON_ATTRIBUTE_FORCE_INLINE auto StringTemplate<CStringInterface,CString,Char>::Replace(const CString& find, const CString& replace) -> Result<Int>
{
	return PRIVATE_MAXON_MF_INVOKE((static_cast<CStringInterface*>(this)), CStringInterface::MTable::_instance.CStringInterface_Replace_1, find, replace);
}
template <> MAXON_ATTRIBUTE_FORCE_INLINE auto StringTemplate<CStringInterface,CString,Char>::Replace(Char find, const CString& replace) -> Result<Int>
{
	return PRIVATE_MAXON_MF_INVOKE((static_cast<CStringInterface*>(this)), CStringInterface::MTable::_instance.CStringInterface_Replace_2, find, replace);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto CStringInterface::Alloc(const maxon::SourceLocation& allocLocation) -> CStringInterface*
{
	return MTable::_instance.CStringInterface_Alloc(allocLocation);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto CStringInterface::Alloc(const maxon::SourceLocation& allocLocation, const CStringInterface& object) -> CStringInterface*
{
	return MTable::_instance.CStringInterface_Alloc_1(allocLocation, object);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto CStringInterface::GetCStringBlock(const Block<Char>& buffer) const -> Result<Int>
{
	return PRIVATE_MAXON_MF_INVOKE((this), MTable::_instance.CStringInterface_GetCStringBlock, buffer);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto CStringInterface::GetCStringAppendArray(const NonConstArray<Char>& array) const -> Result<void>
{
	return PRIVATE_MAXON_MF_INVOKE((this), MTable::_instance.CStringInterface_GetCStringAppendArray, array);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto CStringInterface::Disconnect() -> Result<Block<Char>>
{
	return PRIVATE_MAXON_MF_INVOKE((this), MTable::_instance.CStringInterface_Disconnect);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto CStringInterface::SetCString(const Char* buffer, Int count) -> Result<void>
{
	return PRIVATE_MAXON_MF_INVOKE((this), MTable::_instance.CStringInterface_SetCString, buffer, count);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto CStringInterface::GetCString() const -> Result<BaseArray<Char>>
{
	return PRIVATE_MAXON_MF_INVOKE((this), MTable::_instance.CStringInterface_GetCString);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto CStringInterface::GetInternalData() const -> Block<const Char>
{
	return PRIVATE_MAXON_MF_INVOKE((this), MTable::_instance.CStringInterface_GetInternalData);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto CStringInterface::GetAndCacheConstString(const Char* chr, Int len) -> const CString&
{
	return MTable::_instance.CStringInterface_GetAndCacheConstString(chr, len);
}

template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CStringInterface::Hxx1::ConstFn<S>::GetLength() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const CStringInterface* o_ = (const CStringInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = CStringInterface::NullValuePtr(); if (!o_) return 0; } 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.CStringInterface_GetLength));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CStringInterface::Hxx1::Fn<S>::Init(Int count, Char fillChar) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); CStringInterface* o_ = (CStringInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.CStringInterface_Init, count, fillChar));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CStringInterface::Hxx1::COWFn<S>::Init(Int count, Char fillChar) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); CStringInterface* o_ = (CStringInterface*) this->MakeWritable(true).GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.CStringInterface_Init, count, fillChar));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CStringInterface::Hxx1::Fn<S>::Shrink() const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); CStringInterface* o_ = (CStringInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.CStringInterface_Shrink));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CStringInterface::Hxx1::COWFn<S>::Shrink() -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); CStringInterface* o_ = (CStringInterface*) this->MakeWritable(true).GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.CStringInterface_Shrink));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CStringInterface::Hxx1::Fn<S>::Append(const CStringInterface* str) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); CStringInterface* o_ = (CStringInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.CStringInterface_Append, str));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CStringInterface::Hxx1::COWFn<S>::Append(const CStringInterface* str) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); CStringInterface* o_ = (CStringInterface*) this->MakeWritable(true).GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.CStringInterface_Append, str));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CStringInterface::Hxx1::Fn<S>::Append(const CString& str) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); CStringInterface* o_ = (CStringInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (o_->Append(str));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CStringInterface::Hxx1::COWFn<S>::Append(const CString& str) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); CStringInterface* o_ = (CStringInterface*) this->MakeWritable(true).GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } 
	return (o_->Append(str));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CStringInterface::Hxx1::Fn<S>::Append(const Char* str, Int len) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); CStringInterface* o_ = (CStringInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.CStringInterface_Append_1, str, len));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CStringInterface::Hxx1::COWFn<S>::Append(const Char* str, Int len) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); CStringInterface* o_ = (CStringInterface*) this->MakeWritable(true).GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.CStringInterface_Append_1, str, len));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CStringInterface::Hxx1::Fn<S>::Append(const Block<const Char>& block) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); CStringInterface* o_ = (CStringInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (o_->Append(block));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CStringInterface::Hxx1::COWFn<S>::Append(const Block<const Char>& block) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); CStringInterface* o_ = (CStringInterface*) this->MakeWritable(true).GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } 
	return (o_->Append(block));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CStringInterface::Hxx1::Fn<S>::AppendChar(Char v) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); CStringInterface* o_ = (CStringInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (o_->AppendChar(v));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CStringInterface::Hxx1::COWFn<S>::AppendChar(Char v) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); CStringInterface* o_ = (CStringInterface*) this->MakeWritable(true).GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } 
	return (o_->AppendChar(v));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CStringInterface::Hxx1::ConstFn<S>::FindIndex(const CStringInterface* str, StringPosition start) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const CStringInterface* o_ = (const CStringInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = CStringInterface::NullValuePtr(); if (!o_) return InvalidArrayIndex; } 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.CStringInterface_FindIndex, str, std::forward<StringPosition>(start)));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CStringInterface::Hxx1::ConstFn<S>::FindLastIndex(const CStringInterface* str, StringPosition start) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const CStringInterface* o_ = (const CStringInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = CStringInterface::NullValuePtr(); if (!o_) return InvalidArrayIndex; } 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.CStringInterface_FindLastIndex, str, std::forward<StringPosition>(start)));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CStringInterface::Hxx1::ConstFn<S>::FindIndex(Char ch, StringPosition start) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const CStringInterface* o_ = (const CStringInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = CStringInterface::NullValuePtr(); if (!o_) return InvalidArrayIndex; } 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.CStringInterface_FindIndex_1, ch, std::forward<StringPosition>(start)));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CStringInterface::Hxx1::ConstFn<S>::FindLastIndex(Char ch, StringPosition start) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const CStringInterface* o_ = (const CStringInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = CStringInterface::NullValuePtr(); if (!o_) return InvalidArrayIndex; } 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.CStringInterface_FindLastIndex_1, ch, std::forward<StringPosition>(start)));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CStringInterface::Hxx1::ConstFn<S>::FindUpperIndex(const CStringInterface* str, StringPosition start) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const CStringInterface* o_ = (const CStringInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = CStringInterface::NullValuePtr(); if (!o_) return InvalidArrayIndex; } 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.CStringInterface_FindUpperIndex, str, std::forward<StringPosition>(start)));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CStringInterface::Hxx1::ConstFn<S>::FindLastUpperIndex(const CStringInterface* str, StringPosition start) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const CStringInterface* o_ = (const CStringInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = CStringInterface::NullValuePtr(); if (!o_) return InvalidArrayIndex; } 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.CStringInterface_FindLastUpperIndex, str, std::forward<StringPosition>(start)));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CStringInterface::Hxx1::Fn<S>::Erase(StringPosition position, StringCount count) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); CStringInterface* o_ = (CStringInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.CStringInterface_Erase, std::forward<StringPosition>(position), std::forward<StringCount>(count)));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CStringInterface::Hxx1::COWFn<S>::Erase(StringPosition position, StringCount count) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); CStringInterface* o_ = (CStringInterface*) this->MakeWritable(true).GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.CStringInterface_Erase, std::forward<StringPosition>(position), std::forward<StringCount>(count)));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CStringInterface::Hxx1::Fn<S>::Insert(StringPosition position, const CStringInterface* str, StringPosition strStart, StringCount strCount) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); CStringInterface* o_ = (CStringInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.CStringInterface_Insert, std::forward<StringPosition>(position), str, std::forward<StringPosition>(strStart), std::forward<StringCount>(strCount)));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CStringInterface::Hxx1::COWFn<S>::Insert(StringPosition position, const CStringInterface* str, StringPosition strStart, StringCount strCount) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); CStringInterface* o_ = (CStringInterface*) this->MakeWritable(true).GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.CStringInterface_Insert, std::forward<StringPosition>(position), str, std::forward<StringPosition>(strStart), std::forward<StringCount>(strCount)));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CStringInterface::Hxx1::Fn<S>::Insert(StringPosition position, Char ch) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); CStringInterface* o_ = (CStringInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.CStringInterface_Insert_1, std::forward<StringPosition>(position), ch));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CStringInterface::Hxx1::COWFn<S>::Insert(StringPosition position, Char ch) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); CStringInterface* o_ = (CStringInterface*) this->MakeWritable(true).GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.CStringInterface_Insert_1, std::forward<StringPosition>(position), ch));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CStringInterface::Hxx1::ConstFn<S>::GetPart(StringPosition start, StringCount count) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<CString>, CString>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<CString>, CString>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const CStringInterface* o_ = (const CStringInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = CStringInterface::NullValuePtr(); if (!o_) return CString::NullValue(); } 
	return CString(PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.CStringInterface_GetPart, std::forward<StringPosition>(start), std::forward<StringCount>(count)));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CStringInterface::Hxx1::ConstFn<S>::ToUpper() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<CString>, CString>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<CString>, CString>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const CStringInterface* o_ = (const CStringInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = CStringInterface::NullValuePtr(); if (!o_) return CString::NullValue(); } 
	return CString(PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.CStringInterface_ToUpper));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CStringInterface::Hxx1::ConstFn<S>::ToLower() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<CString>, CString>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<CString>, CString>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const CStringInterface* o_ = (const CStringInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = CStringInterface::NullValuePtr(); if (!o_) return CString::NullValue(); } 
	return CString(PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.CStringInterface_ToLower));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CStringInterface::Hxx1::ConstFn<S>::ComparePart(const CStringInterface* str, STRINGCOMPARISON mode, StringPosition position, StringCount count) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<COMPARERESULT>, COMPARERESULT>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<COMPARERESULT>, COMPARERESULT>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const CStringInterface* o_ = (const CStringInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = CStringInterface::NullValuePtr(); if (!o_) return maxon::PrivateIncompleteNullReturnValue<COMPARERESULT>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.CStringInterface_ComparePart, str, mode, std::forward<StringPosition>(position), std::forward<StringCount>(count)));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CStringInterface::Hxx1::ConstFn<S>::Compare(const CStringInterface* str, STRINGCOMPARISON mode) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<COMPARERESULT>, COMPARERESULT>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<COMPARERESULT>, COMPARERESULT>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const CStringInterface* o_ = (const CStringInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = CStringInterface::NullValuePtr(); if (!o_) return maxon::PrivateIncompleteNullReturnValue<COMPARERESULT>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } 
	return (o_->Compare(str, mode));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CStringInterface::Hxx1::ConstFn<S>::IsEqual(const CStringInterface* str) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const CStringInterface* o_ = (const CStringInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = CStringInterface::NullValuePtr(); if (!o_) return maxon::PrivateLogNullptrError(false); } 
	return (o_->IsEqual(str));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CStringInterface::Hxx1::ConstFn<S>::ToFloat64(STRINGCONVERSION flags) const -> Result<Float64>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<Float64>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const CStringInterface* o_ = (const CStringInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = CStringInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (o_->ToFloat64(flags));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CStringInterface::Hxx1::ConstFn<S>::ToFloat32(STRINGCONVERSION flags) const -> Result<Float32>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<Float32>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const CStringInterface* o_ = (const CStringInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = CStringInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (o_->ToFloat32(flags));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CStringInterface::Hxx1::ConstFn<S>::ToFloat(STRINGCONVERSION flags) const -> Result<Float>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<Float>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const CStringInterface* o_ = (const CStringInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = CStringInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (o_->ToFloat(flags));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CStringInterface::Hxx1::ConstFn<S>::ToInt64(STRINGCONVERSION flags) const -> Result<Int64>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<Int64>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const CStringInterface* o_ = (const CStringInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = CStringInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (o_->ToInt64(flags));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CStringInterface::Hxx1::ConstFn<S>::ToInt32(STRINGCONVERSION flags) const -> Result<Int32>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<Int32>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const CStringInterface* o_ = (const CStringInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = CStringInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (o_->ToInt32(flags));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CStringInterface::Hxx1::ConstFn<S>::ToInt(STRINGCONVERSION flags) const -> Result<Int>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<Int>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const CStringInterface* o_ = (const CStringInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = CStringInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (o_->ToInt(flags));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CStringInterface::Hxx1::ConstFn<S>::ToUInt64(STRINGCONVERSION flags) const -> Result<UInt64>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<UInt64>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const CStringInterface* o_ = (const CStringInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = CStringInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (o_->ToUInt64(flags));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CStringInterface::Hxx1::ConstFn<S>::ToUInt32(STRINGCONVERSION flags) const -> Result<UInt32>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<UInt32>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const CStringInterface* o_ = (const CStringInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = CStringInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (o_->ToUInt32(flags));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CStringInterface::Hxx1::ConstFn<S>::ToUInt(STRINGCONVERSION flags) const -> Result<UInt>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<UInt>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const CStringInterface* o_ = (const CStringInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = CStringInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (o_->ToUInt(flags));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CStringInterface::Hxx1::ConstFn<S>::FloatToString(Float32 value, Int charsBeforeComma, Int digitsAfterComma, Bool exponent, Char fillChar) -> CString
{
	return (CStringInterface::FloatToString(value, charsBeforeComma, digitsAfterComma, exponent, fillChar));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CStringInterface::Hxx1::ConstFn<S>::FloatToString(Float64 value, Int charsBeforeComma, Int digitsAfterComma, Bool exponent, Char fillChar) -> CString
{
	return (CStringInterface::FloatToString(value, charsBeforeComma, digitsAfterComma, exponent, fillChar));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CStringInterface::Hxx1::Fn<S>::AppendInt(Int32 v) const -> DOXYGEN_SWITCH(maxon::RefMemberType<S const>, S)
{
	static_assert(!S::HAS_ERROR, "CStringInterface::AppendInt can't be used on a Result object because it does not return a Result object itself."); CStringInterface* o_ = (CStringInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return this->PrivateGetRefMember(); } 
	if (o_->AppendInt(v) == nullptr) this->ResetReference();
	return this->PrivateGetRefMember();
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CStringInterface::Hxx1::COWFn<S>::AppendInt(Int32 v) -> DOXYGEN_SWITCH(maxon::RefMemberType<S>, S)
{
	static_assert(!S::HAS_ERROR, "CStringInterface::AppendInt can't be used on a Result object because it does not return a Result object itself."); CStringInterface* o_ = (CStringInterface*) this->MakeWritable(true).GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return this->PrivateGetRefMember(); } 
	if (o_->AppendInt(v) == nullptr) this->ResetReference();
	return this->PrivateGetRefMember();
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CStringInterface::Hxx1::Fn<S>::AppendUInt(UInt32 v) const -> DOXYGEN_SWITCH(maxon::RefMemberType<S const>, S)
{
	static_assert(!S::HAS_ERROR, "CStringInterface::AppendUInt can't be used on a Result object because it does not return a Result object itself."); CStringInterface* o_ = (CStringInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return this->PrivateGetRefMember(); } 
	if (o_->AppendUInt(v) == nullptr) this->ResetReference();
	return this->PrivateGetRefMember();
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CStringInterface::Hxx1::COWFn<S>::AppendUInt(UInt32 v) -> DOXYGEN_SWITCH(maxon::RefMemberType<S>, S)
{
	static_assert(!S::HAS_ERROR, "CStringInterface::AppendUInt can't be used on a Result object because it does not return a Result object itself."); CStringInterface* o_ = (CStringInterface*) this->MakeWritable(true).GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return this->PrivateGetRefMember(); } 
	if (o_->AppendUInt(v) == nullptr) this->ResetReference();
	return this->PrivateGetRefMember();
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CStringInterface::Hxx1::Fn<S>::AppendInt(Int64 v) const -> DOXYGEN_SWITCH(maxon::RefMemberType<S const>, S)
{
	static_assert(!S::HAS_ERROR, "CStringInterface::AppendInt can't be used on a Result object because it does not return a Result object itself."); CStringInterface* o_ = (CStringInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return this->PrivateGetRefMember(); } 
	if (o_->AppendInt(v) == nullptr) this->ResetReference();
	return this->PrivateGetRefMember();
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CStringInterface::Hxx1::COWFn<S>::AppendInt(Int64 v) -> DOXYGEN_SWITCH(maxon::RefMemberType<S>, S)
{
	static_assert(!S::HAS_ERROR, "CStringInterface::AppendInt can't be used on a Result object because it does not return a Result object itself."); CStringInterface* o_ = (CStringInterface*) this->MakeWritable(true).GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return this->PrivateGetRefMember(); } 
	if (o_->AppendInt(v) == nullptr) this->ResetReference();
	return this->PrivateGetRefMember();
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CStringInterface::Hxx1::Fn<S>::AppendUInt(UInt64 v) const -> DOXYGEN_SWITCH(maxon::RefMemberType<S const>, S)
{
	static_assert(!S::HAS_ERROR, "CStringInterface::AppendUInt can't be used on a Result object because it does not return a Result object itself."); CStringInterface* o_ = (CStringInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return this->PrivateGetRefMember(); } 
	if (o_->AppendUInt(v) == nullptr) this->ResetReference();
	return this->PrivateGetRefMember();
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CStringInterface::Hxx1::COWFn<S>::AppendUInt(UInt64 v) -> DOXYGEN_SWITCH(maxon::RefMemberType<S>, S)
{
	static_assert(!S::HAS_ERROR, "CStringInterface::AppendUInt can't be used on a Result object because it does not return a Result object itself."); CStringInterface* o_ = (CStringInterface*) this->MakeWritable(true).GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return this->PrivateGetRefMember(); } 
	if (o_->AppendUInt(v) == nullptr) this->ResetReference();
	return this->PrivateGetRefMember();
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CStringInterface::Hxx1::ConstFn<S>::IntToString(Int32 v) -> CString
{
	return (CStringInterface::IntToString(v));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CStringInterface::Hxx1::ConstFn<S>::UIntToString(UInt32 v) -> CString
{
	return (CStringInterface::UIntToString(v));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CStringInterface::Hxx1::ConstFn<S>::IntToString(Int64 v) -> CString
{
	return (CStringInterface::IntToString(v));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CStringInterface::Hxx1::ConstFn<S>::UIntToString(UInt64 v) -> CString
{
	return (CStringInterface::UIntToString(v));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CStringInterface::Hxx1::ConstFn<S>::MemorySizeToString(Int64 v, Bool mebibytes) -> CString
{
	return (CStringInterface::MemorySizeToString(v, mebibytes));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CStringInterface::Hxx1::ConstFn<S>::HexToString(UInt32 v, Bool prefix0x) -> CString
{
	return (CStringInterface::HexToString(v, prefix0x));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CStringInterface::Hxx1::ConstFn<S>::HexToString(UInt64 v, Bool prefix0x) -> CString
{
	return (CStringInterface::HexToString(v, prefix0x));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CStringInterface::Hxx1::ConstFn<S>::PointerToString(const void* v) -> CString
{
	return (CStringInterface::PointerToString(v));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CStringInterface::Hxx1::ConstFn<S>::GetUtf32(Utf32CharBuffer& stringData) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const CStringInterface* o_ = (const CStringInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = CStringInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.CStringInterface_GetUtf32, stringData));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CStringInterface::Hxx1::Fn<S>::TrimLeft() const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); CStringInterface* o_ = (CStringInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.CStringInterface_TrimLeft));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CStringInterface::Hxx1::COWFn<S>::TrimLeft() -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); CStringInterface* o_ = (CStringInterface*) this->MakeWritable(true).GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.CStringInterface_TrimLeft));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CStringInterface::Hxx1::Fn<S>::TrimRight() const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); CStringInterface* o_ = (CStringInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.CStringInterface_TrimRight));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CStringInterface::Hxx1::COWFn<S>::TrimRight() -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); CStringInterface* o_ = (CStringInterface*) this->MakeWritable(true).GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.CStringInterface_TrimRight));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CStringInterface::Hxx1::ConstFn<S>::Split(const CString& splitSymbol, Bool trim, const ValueReceiver<const CString&>& parts) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const CStringInterface* o_ = (const CStringInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = CStringInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.CStringInterface_Split, splitSymbol, trim, parts));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CStringInterface::Hxx1::Fn<S>::Replace(Char find, Char replace) const -> Result<Int>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<Int>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); CStringInterface* o_ = (CStringInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.CStringInterface_Replace, find, replace));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CStringInterface::Hxx1::COWFn<S>::Replace(Char find, Char replace) -> Result<Int>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<Int>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); CStringInterface* o_ = (CStringInterface*) this->MakeWritable(true).GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.CStringInterface_Replace, find, replace));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CStringInterface::Hxx1::Fn<S>::Replace(const CString& find, const CString& replace) const -> Result<Int>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<Int>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); CStringInterface* o_ = (CStringInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.CStringInterface_Replace_1, find, replace));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CStringInterface::Hxx1::COWFn<S>::Replace(const CString& find, const CString& replace) -> Result<Int>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<Int>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); CStringInterface* o_ = (CStringInterface*) this->MakeWritable(true).GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.CStringInterface_Replace_1, find, replace));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CStringInterface::Hxx1::Fn<S>::Replace(Char find, const CString& replace) const -> Result<Int>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<Int>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); CStringInterface* o_ = (CStringInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.CStringInterface_Replace_2, find, replace));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CStringInterface::Hxx1::COWFn<S>::Replace(Char find, const CString& replace) -> Result<Int>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<Int>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); CStringInterface* o_ = (CStringInterface*) this->MakeWritable(true).GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.CStringInterface_Replace_2, find, replace));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CStringInterface::Hxx1::ConstFn<S>::Find(const CString& str, Int* pos, StringPosition start) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const CStringInterface* o_ = (const CStringInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = CStringInterface::NullValuePtr(); if (!o_) return maxon::PrivateLogNullptrError(false); } 
	return (o_->Find(str, pos, std::forward<StringPosition>(start)));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CStringInterface::Hxx1::ConstFn<S>::FindLast(const CString& str, Int* pos, StringPosition start) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const CStringInterface* o_ = (const CStringInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = CStringInterface::NullValuePtr(); if (!o_) return maxon::PrivateLogNullptrError(false); } 
	return (o_->FindLast(str, pos, std::forward<StringPosition>(start)));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CStringInterface::Hxx1::ConstFn<S>::Find(Char ch, Int* pos, StringPosition start) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const CStringInterface* o_ = (const CStringInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = CStringInterface::NullValuePtr(); if (!o_) return maxon::PrivateLogNullptrError(false); } 
	return (o_->Find(ch, pos, std::forward<StringPosition>(start)));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CStringInterface::Hxx1::ConstFn<S>::FindLast(Char ch, Int* pos, StringPosition start) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const CStringInterface* o_ = (const CStringInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = CStringInterface::NullValuePtr(); if (!o_) return maxon::PrivateLogNullptrError(false); } 
	return (o_->FindLast(ch, pos, std::forward<StringPosition>(start)));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CStringInterface::Hxx1::ConstFn<S>::FindUpper(const CString& str, Int* pos, StringPosition start) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const CStringInterface* o_ = (const CStringInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = CStringInterface::NullValuePtr(); if (!o_) return maxon::PrivateLogNullptrError(false); } 
	return (o_->FindUpper(str, pos, std::forward<StringPosition>(start)));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CStringInterface::Hxx1::ConstFn<S>::FindLastUpper(const CString& str, Int* pos, StringPosition start) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const CStringInterface* o_ = (const CStringInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = CStringInterface::NullValuePtr(); if (!o_) return maxon::PrivateLogNullptrError(false); } 
	return (o_->FindLastUpper(str, pos, std::forward<StringPosition>(start)));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CStringInterface::Hxx1::ConstFn<S>::GetLeftPart(StringPosition start) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<CString>, CString>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<CString>, CString>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const CStringInterface* o_ = (const CStringInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = CStringInterface::NullValuePtr(); if (!o_) return CString::NullValue(); } 
	return CString(o_->GetLeftPart(std::forward<StringPosition>(start)));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CStringInterface::Hxx1::ConstFn<S>::GetRightPart(StringPosition start) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<CString>, CString>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<CString>, CString>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const CStringInterface* o_ = (const CStringInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = CStringInterface::NullValuePtr(); if (!o_) return CString::NullValue(); } 
	return CString(o_->GetRightPart(std::forward<StringPosition>(start)));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CStringInterface::Hxx1::ConstFn<S>::StartsWith(Char ch) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const CStringInterface* o_ = (const CStringInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = CStringInterface::NullValuePtr(); if (!o_) return maxon::PrivateLogNullptrError(false); } 
	return (o_->StartsWith(ch));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CStringInterface::Hxx1::ConstFn<S>::StartsWith(const CString& str) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const CStringInterface* o_ = (const CStringInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = CStringInterface::NullValuePtr(); if (!o_) return maxon::PrivateLogNullptrError(false); } 
	return (o_->StartsWith(str));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CStringInterface::Hxx1::ConstFn<S>::EndsWith(Char ch) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const CStringInterface* o_ = (const CStringInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = CStringInterface::NullValuePtr(); if (!o_) return maxon::PrivateLogNullptrError(false); } 
	return (o_->EndsWith(ch));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CStringInterface::Hxx1::ConstFn<S>::EndsWith(const CString& str) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const CStringInterface* o_ = (const CStringInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = CStringInterface::NullValuePtr(); if (!o_) return maxon::PrivateLogNullptrError(false); } 
	return (o_->EndsWith(str));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CStringInterface::Hxx1::Fn<S>::Trim() const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); CStringInterface* o_ = (CStringInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (o_->Trim());
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CStringInterface::Hxx1::COWFn<S>::Trim() -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); CStringInterface* o_ = (CStringInterface*) this->MakeWritable(true).GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } 
	return (o_->Trim());
}
auto CStringInterface::Reference::Create() -> maxon::ResultMemT<CString>
{
	CStringInterface* res_ = CStringInterface::Alloc(MAXON_SOURCE_LOCATION);
	return CString(maxon::ForwardResultPtr<CStringInterface>(res_));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CStringInterface::Hxx1::ConstFn<S>::GetCStringBlock(const Block<Char>& buffer) const -> Result<Int>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<Int>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const CStringInterface* o_ = (const CStringInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = CStringInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.CStringInterface_GetCStringBlock, buffer));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CStringInterface::Hxx1::ConstFn<S>::GetCStringAppendArray(const NonConstArray<Char>& array) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const CStringInterface* o_ = (const CStringInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = CStringInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.CStringInterface_GetCStringAppendArray, array));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CStringInterface::Hxx1::Fn<S>::Disconnect() const -> Result<Block<Char>>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<Block<Char>>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); CStringInterface* o_ = (CStringInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.CStringInterface_Disconnect));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CStringInterface::Hxx1::COWFn<S>::Disconnect() -> Result<Block<Char>>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<Block<Char>>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); CStringInterface* o_ = (CStringInterface*) this->MakeWritable(true).GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.CStringInterface_Disconnect));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CStringInterface::Hxx1::Fn<S>::SetCString(const Char* buffer, Int count) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); CStringInterface* o_ = (CStringInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.CStringInterface_SetCString, buffer, count));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CStringInterface::Hxx1::COWFn<S>::SetCString(const Char* buffer, Int count) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); CStringInterface* o_ = (CStringInterface*) this->MakeWritable(true).GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.CStringInterface_SetCString, buffer, count));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CStringInterface::Hxx1::Fn<S>::SetCString(const Block<const Char>& buffer) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); CStringInterface* o_ = (CStringInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (o_->SetCString(buffer));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CStringInterface::Hxx1::COWFn<S>::SetCString(const Block<const Char>& buffer) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); CStringInterface* o_ = (CStringInterface*) this->MakeWritable(true).GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } 
	return (o_->SetCString(buffer));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CStringInterface::Hxx1::ConstFn<S>::GetCString() const -> Result<BaseArray<Char>>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<BaseArray<Char>>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const CStringInterface* o_ = (const CStringInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = CStringInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.CStringInterface_GetCString));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CStringInterface::Hxx1::ConstFn<S>::GetInternalData() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Block<const Char>>, Block<const Char>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Block<const Char>>, Block<const Char>>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const CStringInterface* o_ = (const CStringInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = CStringInterface::NullValuePtr(); if (!o_) return maxon::PrivateIncompleteNullReturnValue<Block<const Char>>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.CStringInterface_GetInternalData));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CStringInterface::Hxx1::ConstFn<S>::GetAndCacheConstString(const Char* chr, Int len) -> const CString&
{
	return (MTable::_instance.CStringInterface_GetAndCacheConstString(chr, len));
}
#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT) && !defined(MAXON_DEPENDENCY_DISABLE_string)
#ifdef MAXON_USE_REGISTER_FUNCTION
MAXON_STATIC_STORAGE(maxon::EntityUse, s_ui_maxon_CStringInterface); \
MAXON_ATTRIBUTE_CONSTRUCTOR static void Register_s_ui_maxon_CStringInterface() { new (s_ui_maxon_CStringInterface) maxon::EntityUse(CStringInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/string.h", false); }
#else // !MAXON_USE_REGISTER_FUNCTION
static maxon::EntityUse s_ui_maxon_CStringInterface(CStringInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/string.h", false);
#endif // MAXON_USE_REGISTER_FUNCTION
#endif
#ifdef _HAS_CHAR8_T
#endif
#endif

#ifdef MAXON_COMPILER_GCC
	#pragma GCC diagnostic pop
#endif

#endif

