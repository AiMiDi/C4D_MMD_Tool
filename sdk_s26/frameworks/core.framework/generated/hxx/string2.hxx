
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
	void (*StringInterface_Free) (const StringInterface* object);
	Int (*StringInterface_GetLength) (const StringInterface* this_);
	Result<void> (*StringInterface_Init) (StringInterface* this_, Int count, Utf32Char fillChar);
	Result<void> (*StringInterface_Shrink) (StringInterface* this_);
	Result<void> (*StringInterface_Append) (StringInterface* this_, const StringInterface* str);
	Result<void> (*StringInterface_Append_1) (StringInterface* this_, const Utf32Char* str, Int len);
	Int (*StringInterface_FindIndex) (const StringInterface* this_, const StringInterface* str, StringPosition start);
	Int (*StringInterface_FindLastIndex) (const StringInterface* this_, const StringInterface* str, StringPosition start);
	Int (*StringInterface_FindIndex_1) (const StringInterface* this_, Utf32Char ch, StringPosition start);
	Int (*StringInterface_FindLastIndex_1) (const StringInterface* this_, Utf32Char ch, StringPosition start);
	Int (*StringInterface_FindUpperIndex) (const StringInterface* this_, const StringInterface* str, StringPosition start);
	Int (*StringInterface_FindLastUpperIndex) (const StringInterface* this_, const StringInterface* str, StringPosition start);
	Result<void> (*StringInterface_Erase) (StringInterface* this_, StringPosition position, StringCount count);
	Result<void> (*StringInterface_Insert) (StringInterface* this_, StringPosition position, const StringInterface* str, StringPosition strStart, StringCount strCount);
	Result<void> (*StringInterface_Insert_1) (StringInterface* this_, StringPosition position, Utf32Char ch);
	StringInterface* (*StringInterface_GetPart) (const StringInterface* this_, StringPosition start, StringCount count);
	StringInterface* (*StringInterface_ToUpper) (const StringInterface* this_);
	StringInterface* (*StringInterface_ToLower) (const StringInterface* this_);
	COMPARERESULT (*StringInterface_ComparePart) (const StringInterface* this_, const StringInterface* str, STRINGCOMPARISON mode, StringPosition position, StringCount count);
	HashInt (*StringInterface_GetHashCode) (const StringInterface* this_);
	void (*StringInterface_SetChar) (StringInterface* this_, Int pos, Utf32Char ch);
	Utf32Char (*StringInterface_GetChar) (const StringInterface* this_, Int pos);
	Result<void> (*StringInterface_GetUtf32) (const StringInterface* this_, Utf32CharBuffer& stringData);
	Result<void> (*StringInterface_TrimLeft) (StringInterface* this_);
	Result<void> (*StringInterface_TrimRight) (StringInterface* this_);
	Result<void> (*StringInterface_Split) (const StringInterface* this_, const String& splitSymbol, Bool trim, const ValueReceiver<const String&>& parts);
	Result<Int> (*StringInterface_Replace) (StringInterface* this_, Utf32Char find, Utf32Char replace);
	Result<Int> (*StringInterface_Replace_1) (StringInterface* this_, const String& find, const String& replace);
	Result<Int> (*StringInterface_Replace_2) (StringInterface* this_, Utf32Char find, const String& replace);
	StringInterface* (*StringInterface_Alloc) (const maxon::SourceLocation& allocLocation);
	StringInterface* (*StringInterface_Alloc_1) (const maxon::SourceLocation& allocLocation, const StringInterface& object);
	Result<Int> (*StringInterface_GetCStringBlock) (const StringInterface* this_, const Block<Char>& buffer, const StringEncodingRef& stringEncoding);
	Result<void> (*StringInterface_GetCStringAppendArray) (const StringInterface* this_, const NonConstArray<Char>& array, const StringEncodingRef& stringEncoding);
	Result<BaseArray<Char>> (*StringInterface_GetCString) (const StringInterface* this_, const StringEncodingRef& stringEncoding);
	Result<void> (*StringInterface_SetCString) (StringInterface* this_, const Char* buffer, Int count, const StringDecodingRef& stringDecoding);
	Result<SysCharArray> (*StringInterface_GetSystemEncoding) (const StringInterface* this_);
	Result<void> (*StringInterface_SetSystemEncoding) (StringInterface* this_, const SysChar* buffer, Int count);
	Result<void> (*StringInterface_SetUtf32) (StringInterface* this_, const Utf32Char* buffer, Int count);
	Result<void> (*StringInterface_GetUtf16) (const StringInterface* this_, Utf16CharBuffer& stringData);
	Result<void> (*StringInterface_SetUtf16) (StringInterface* this_, const Utf16Char* buffer, Int count);
	const String& (*StringInterface_GetAndCacheConstString) (const wchar_t* chr, Int len);
	const String& (*StringInterface_GetAndCacheConstString_1) (const Char* chr, Int len, Int isUtf8);
	String (*StringInterface_PrivateEnumToString) (const EnumInfo& info, UInt64 value, const FormatStatement* formatStatement);
	StridedBlock<const Generic> (*StringInterface_GetVariableInternalData) (const StringInterface* this_);
	Int (*StringInterface_GetCharacterWidth) (const StringInterface* this_);
	Result<String> (*StringInterface_Prettify) (const StringInterface* this_, Int indent, const String& indentStr, Int breakUpThreshold, Bool angularBrackets);
	template <typename IMPL> void Init()
	{
		StringInterface_Free = &IMPL::StringInterface_Free;
		StringInterface_GetLength = &IMPL::StringInterface_GetLength;
		StringInterface_Init = &IMPL::StringInterface_Init;
		StringInterface_Shrink = &IMPL::StringInterface_Shrink;
		StringInterface_Append = &IMPL::StringInterface_Append;
		StringInterface_Append_1 = &IMPL::StringInterface_Append_1;
		StringInterface_FindIndex = &IMPL::StringInterface_FindIndex;
		StringInterface_FindLastIndex = &IMPL::StringInterface_FindLastIndex;
		StringInterface_FindIndex_1 = &IMPL::StringInterface_FindIndex_1;
		StringInterface_FindLastIndex_1 = &IMPL::StringInterface_FindLastIndex_1;
		StringInterface_FindUpperIndex = &IMPL::StringInterface_FindUpperIndex;
		StringInterface_FindLastUpperIndex = &IMPL::StringInterface_FindLastUpperIndex;
		StringInterface_Erase = &IMPL::StringInterface_Erase;
		StringInterface_Insert = &IMPL::StringInterface_Insert;
		StringInterface_Insert_1 = &IMPL::StringInterface_Insert_1;
		StringInterface_GetPart = &IMPL::StringInterface_GetPart;
		StringInterface_ToUpper = &IMPL::StringInterface_ToUpper;
		StringInterface_ToLower = &IMPL::StringInterface_ToLower;
		StringInterface_ComparePart = &IMPL::StringInterface_ComparePart;
		StringInterface_GetHashCode = &IMPL::StringInterface_GetHashCode;
		StringInterface_SetChar = &IMPL::StringInterface_SetChar;
		StringInterface_GetChar = &IMPL::StringInterface_GetChar;
		StringInterface_GetUtf32 = &IMPL::StringInterface_GetUtf32;
		StringInterface_TrimLeft = &IMPL::StringInterface_TrimLeft;
		StringInterface_TrimRight = &IMPL::StringInterface_TrimRight;
		StringInterface_Split = &IMPL::StringInterface_Split;
		StringInterface_Replace = &IMPL::StringInterface_Replace;
		StringInterface_Replace_1 = &IMPL::StringInterface_Replace_1;
		StringInterface_Replace_2 = &IMPL::StringInterface_Replace_2;
		StringInterface_Alloc = &IMPL::StringInterface_Alloc;
		StringInterface_Alloc_1 = &IMPL::StringInterface_Alloc_1;
		StringInterface_GetCStringBlock = &IMPL::StringInterface_GetCStringBlock;
		StringInterface_GetCStringAppendArray = &IMPL::StringInterface_GetCStringAppendArray;
		StringInterface_GetCString = &IMPL::StringInterface_GetCString;
		StringInterface_SetCString = &IMPL::StringInterface_SetCString;
		StringInterface_GetSystemEncoding = &IMPL::StringInterface_GetSystemEncoding;
		StringInterface_SetSystemEncoding = &IMPL::StringInterface_SetSystemEncoding;
		StringInterface_SetUtf32 = &IMPL::StringInterface_SetUtf32;
		StringInterface_GetUtf16 = &IMPL::StringInterface_GetUtf16;
		StringInterface_SetUtf16 = &IMPL::StringInterface_SetUtf16;
		StringInterface_GetAndCacheConstString = &IMPL::StringInterface_GetAndCacheConstString;
		StringInterface_GetAndCacheConstString_1 = &IMPL::StringInterface_GetAndCacheConstString_1;
		StringInterface_PrivateEnumToString = &IMPL::StringInterface_PrivateEnumToString;
		StringInterface_GetVariableInternalData = &IMPL::StringInterface_GetVariableInternalData;
		StringInterface_GetCharacterWidth = &IMPL::StringInterface_GetCharacterWidth;
		StringInterface_Prettify = &IMPL::StringInterface_Prettify;
	}
};

struct StringInterface::Hxx2
{
	class Unresolved;
	template <typename C> class Wrapper
	{
	public:
		static void StringInterface_Free(const StringInterface* object) { return C::Free(object); }
		static Int StringInterface_GetLength(const StringInterface* this_) { return C::Get(this_)->GetLength(); }
		static Result<void> StringInterface_Init(StringInterface* this_, Int count, Utf32Char fillChar) { return C::Get(this_)->Init(count, fillChar); }
		static Result<void> StringInterface_Shrink(StringInterface* this_) { return C::Get(this_)->Shrink(); }
		static Result<void> StringInterface_Append(StringInterface* this_, const StringInterface* str) { return C::Get(this_)->Append(str); }
		static Result<void> StringInterface_Append_1(StringInterface* this_, const Utf32Char* str, Int len) { return C::Get(this_)->Append(str, len); }
		static Int StringInterface_FindIndex(const StringInterface* this_, const StringInterface* str, StringPosition start) { return C::Get(this_)->FindIndex(str, std::forward<StringPosition>(start)); }
		static Int StringInterface_FindLastIndex(const StringInterface* this_, const StringInterface* str, StringPosition start) { return C::Get(this_)->FindLastIndex(str, std::forward<StringPosition>(start)); }
		static Int StringInterface_FindIndex_1(const StringInterface* this_, Utf32Char ch, StringPosition start) { return C::Get(this_)->FindIndex(ch, std::forward<StringPosition>(start)); }
		static Int StringInterface_FindLastIndex_1(const StringInterface* this_, Utf32Char ch, StringPosition start) { return C::Get(this_)->FindLastIndex(ch, std::forward<StringPosition>(start)); }
		static Int StringInterface_FindUpperIndex(const StringInterface* this_, const StringInterface* str, StringPosition start) { return C::Get(this_)->FindUpperIndex(str, std::forward<StringPosition>(start)); }
		static Int StringInterface_FindLastUpperIndex(const StringInterface* this_, const StringInterface* str, StringPosition start) { return C::Get(this_)->FindLastUpperIndex(str, std::forward<StringPosition>(start)); }
		static Result<void> StringInterface_Erase(StringInterface* this_, StringPosition position, StringCount count) { return C::Get(this_)->Erase(std::forward<StringPosition>(position), std::forward<StringCount>(count)); }
		static Result<void> StringInterface_Insert(StringInterface* this_, StringPosition position, const StringInterface* str, StringPosition strStart, StringCount strCount) { return C::Get(this_)->Insert(std::forward<StringPosition>(position), str, std::forward<StringPosition>(strStart), std::forward<StringCount>(strCount)); }
		static Result<void> StringInterface_Insert_1(StringInterface* this_, StringPosition position, Utf32Char ch) { return C::Get(this_)->Insert(std::forward<StringPosition>(position), ch); }
		static StringInterface* StringInterface_GetPart(const StringInterface* this_, StringPosition start, StringCount count) { return C::Get(this_)->GetPart(std::forward<StringPosition>(start), std::forward<StringCount>(count)); }
		static StringInterface* StringInterface_ToUpper(const StringInterface* this_) { return C::Get(this_)->ToUpper(); }
		static StringInterface* StringInterface_ToLower(const StringInterface* this_) { return C::Get(this_)->ToLower(); }
		static COMPARERESULT StringInterface_ComparePart(const StringInterface* this_, const StringInterface* str, STRINGCOMPARISON mode, StringPosition position, StringCount count) { return C::Get(this_)->ComparePart(str, mode, std::forward<StringPosition>(position), std::forward<StringCount>(count)); }
		static HashInt StringInterface_GetHashCode(const StringInterface* this_) { return C::Get(this_)->GetHashCode(); }
		static void StringInterface_SetChar(StringInterface* this_, Int pos, Utf32Char ch) { return C::Get(this_)->SetChar(pos, ch); }
		static Utf32Char StringInterface_GetChar(const StringInterface* this_, Int pos) { return C::Get(this_)->GetChar(pos); }
		static Result<void> StringInterface_GetUtf32(const StringInterface* this_, Utf32CharBuffer& stringData) { return C::Get(this_)->GetUtf32(stringData); }
		static Result<void> StringInterface_TrimLeft(StringInterface* this_) { return C::Get(this_)->TrimLeft(); }
		static Result<void> StringInterface_TrimRight(StringInterface* this_) { return C::Get(this_)->TrimRight(); }
		static Result<void> StringInterface_Split(const StringInterface* this_, const String& splitSymbol, Bool trim, const ValueReceiver<const String&>& parts) { return C::Get(this_)->Split(splitSymbol, trim, parts); }
		static Result<Int> StringInterface_Replace(StringInterface* this_, Utf32Char find, Utf32Char replace) { return C::Get(this_)->Replace(find, replace); }
		static Result<Int> StringInterface_Replace_1(StringInterface* this_, const String& find, const String& replace) { return C::Get(this_)->Replace(find, replace); }
		static Result<Int> StringInterface_Replace_2(StringInterface* this_, Utf32Char find, const String& replace) { return C::Get(this_)->Replace(find, replace); }
		static StringInterface* StringInterface_Alloc(const maxon::SourceLocation& allocLocation) { return C::Alloc(allocLocation); }
		static StringInterface* StringInterface_Alloc_1(const maxon::SourceLocation& allocLocation, const StringInterface& object) { return C::Alloc(allocLocation, ((const C&) object)); }
		static Result<Int> StringInterface_GetCStringBlock(const StringInterface* this_, const Block<Char>& buffer, const StringEncodingRef& stringEncoding) { return C::Get(this_)->GetCStringBlock(buffer, stringEncoding); }
		static Result<void> StringInterface_GetCStringAppendArray(const StringInterface* this_, const NonConstArray<Char>& array, const StringEncodingRef& stringEncoding) { return C::Get(this_)->GetCStringAppendArray(array, stringEncoding); }
		static Result<BaseArray<Char>> StringInterface_GetCString(const StringInterface* this_, const StringEncodingRef& stringEncoding) { return C::Get(this_)->GetCString(stringEncoding); }
		static Result<void> StringInterface_SetCString(StringInterface* this_, const Char* buffer, Int count, const StringDecodingRef& stringDecoding) { return C::Get(this_)->SetCString(buffer, count, stringDecoding); }
		static Result<SysCharArray> StringInterface_GetSystemEncoding(const StringInterface* this_) { return C::Get(this_)->GetSystemEncoding(); }
		static Result<void> StringInterface_SetSystemEncoding(StringInterface* this_, const SysChar* buffer, Int count) { return C::Get(this_)->SetSystemEncoding(buffer, count); }
		static Result<void> StringInterface_SetUtf32(StringInterface* this_, const Utf32Char* buffer, Int count) { return C::Get(this_)->SetUtf32(buffer, count); }
		static Result<void> StringInterface_GetUtf16(const StringInterface* this_, Utf16CharBuffer& stringData) { return C::Get(this_)->GetUtf16(stringData); }
		static Result<void> StringInterface_SetUtf16(StringInterface* this_, const Utf16Char* buffer, Int count) { return C::Get(this_)->SetUtf16(buffer, count); }
		static const String& StringInterface_GetAndCacheConstString(const wchar_t* chr, Int len) { return C::GetAndCacheConstString(chr, len); }
		static const String& StringInterface_GetAndCacheConstString_1(const Char* chr, Int len, Int isUtf8) { return C::GetAndCacheConstString(chr, len, isUtf8); }
		static String StringInterface_PrivateEnumToString(const EnumInfo& info, UInt64 value, const FormatStatement* formatStatement) { return C::PrivateEnumToString(info, value, formatStatement); }
		static StridedBlock<const Generic> StringInterface_GetVariableInternalData(const StringInterface* this_) { return C::Get(this_)->GetVariableInternalData(); }
		static Int StringInterface_GetCharacterWidth(const StringInterface* this_) { return C::Get(this_)->GetCharacterWidth(); }
		static Result<String> StringInterface_Prettify(const StringInterface* this_, Int indent, const String& indentStr, Int breakUpThreshold, Bool angularBrackets) { return C::Get(this_)->Prettify(indent, indentStr, breakUpThreshold, angularBrackets); }
	};

};
MAXON_ATTRIBUTE_FORCE_INLINE auto StringInterface::Free(const StringInterface* object) -> void
{
	return MTable::_instance.StringInterface_Free(object);
}
template <> MAXON_ATTRIBUTE_FORCE_INLINE auto StringTemplate<StringInterface,String,Utf32Char>::GetLength() const -> Int
{
	return StringInterface::MTable::_instance.StringInterface_GetLength(static_cast<const StringInterface*>(this));
}
template <> MAXON_ATTRIBUTE_FORCE_INLINE auto StringTemplate<StringInterface,String,Utf32Char>::Init(Int count, Utf32Char fillChar) -> Result<void>
{
	return StringInterface::MTable::_instance.StringInterface_Init(static_cast<StringInterface*>(this), count, fillChar);
}
template <> MAXON_ATTRIBUTE_FORCE_INLINE auto StringTemplate<StringInterface,String,Utf32Char>::Shrink() -> Result<void>
{
	return StringInterface::MTable::_instance.StringInterface_Shrink(static_cast<StringInterface*>(this));
}
template <> MAXON_ATTRIBUTE_FORCE_INLINE auto StringTemplate<StringInterface,String,Utf32Char>::Append(const StringInterface* str) -> Result<void>
{
	return StringInterface::MTable::_instance.StringInterface_Append(static_cast<StringInterface*>(this), str);
}
template <> MAXON_ATTRIBUTE_FORCE_INLINE auto StringTemplate<StringInterface,String,Utf32Char>::Append(const Utf32Char* str, Int len) -> Result<void>
{
	return StringInterface::MTable::_instance.StringInterface_Append_1(static_cast<StringInterface*>(this), str, len);
}
template <> MAXON_ATTRIBUTE_FORCE_INLINE auto StringTemplate<StringInterface,String,Utf32Char>::FindIndex(const StringInterface* str, StringPosition start) const -> Int
{
	return StringInterface::MTable::_instance.StringInterface_FindIndex(static_cast<const StringInterface*>(this), str, std::forward<StringPosition>(start));
}
template <> MAXON_ATTRIBUTE_FORCE_INLINE auto StringTemplate<StringInterface,String,Utf32Char>::FindLastIndex(const StringInterface* str, StringPosition start) const -> Int
{
	return StringInterface::MTable::_instance.StringInterface_FindLastIndex(static_cast<const StringInterface*>(this), str, std::forward<StringPosition>(start));
}
template <> MAXON_ATTRIBUTE_FORCE_INLINE auto StringTemplate<StringInterface,String,Utf32Char>::FindIndex(Utf32Char ch, StringPosition start) const -> Int
{
	return StringInterface::MTable::_instance.StringInterface_FindIndex_1(static_cast<const StringInterface*>(this), ch, std::forward<StringPosition>(start));
}
template <> MAXON_ATTRIBUTE_FORCE_INLINE auto StringTemplate<StringInterface,String,Utf32Char>::FindLastIndex(Utf32Char ch, StringPosition start) const -> Int
{
	return StringInterface::MTable::_instance.StringInterface_FindLastIndex_1(static_cast<const StringInterface*>(this), ch, std::forward<StringPosition>(start));
}
template <> MAXON_ATTRIBUTE_FORCE_INLINE auto StringTemplate<StringInterface,String,Utf32Char>::FindUpperIndex(const StringInterface* str, StringPosition start) const -> Int
{
	return StringInterface::MTable::_instance.StringInterface_FindUpperIndex(static_cast<const StringInterface*>(this), str, std::forward<StringPosition>(start));
}
template <> MAXON_ATTRIBUTE_FORCE_INLINE auto StringTemplate<StringInterface,String,Utf32Char>::FindLastUpperIndex(const StringInterface* str, StringPosition start) const -> Int
{
	return StringInterface::MTable::_instance.StringInterface_FindLastUpperIndex(static_cast<const StringInterface*>(this), str, std::forward<StringPosition>(start));
}
template <> MAXON_ATTRIBUTE_FORCE_INLINE auto StringTemplate<StringInterface,String,Utf32Char>::Erase(StringPosition position, StringCount count) -> Result<void>
{
	return StringInterface::MTable::_instance.StringInterface_Erase(static_cast<StringInterface*>(this), std::forward<StringPosition>(position), std::forward<StringCount>(count));
}
template <> MAXON_ATTRIBUTE_FORCE_INLINE auto StringTemplate<StringInterface,String,Utf32Char>::Insert(StringPosition position, const StringInterface* str, StringPosition strStart, StringCount strCount) -> Result<void>
{
	return StringInterface::MTable::_instance.StringInterface_Insert(static_cast<StringInterface*>(this), std::forward<StringPosition>(position), str, std::forward<StringPosition>(strStart), std::forward<StringCount>(strCount));
}
template <> MAXON_ATTRIBUTE_FORCE_INLINE auto StringTemplate<StringInterface,String,Utf32Char>::Insert(StringPosition position, Utf32Char ch) -> Result<void>
{
	return StringInterface::MTable::_instance.StringInterface_Insert_1(static_cast<StringInterface*>(this), std::forward<StringPosition>(position), ch);
}
template <> MAXON_ATTRIBUTE_FORCE_INLINE auto StringTemplate<StringInterface,String,Utf32Char>::GetPart(StringPosition start, StringCount count) const -> StringInterface*
{
	return StringInterface::MTable::_instance.StringInterface_GetPart(static_cast<const StringInterface*>(this), std::forward<StringPosition>(start), std::forward<StringCount>(count));
}
template <> MAXON_ATTRIBUTE_FORCE_INLINE auto StringTemplate<StringInterface,String,Utf32Char>::ToUpper() const -> StringInterface*
{
	return StringInterface::MTable::_instance.StringInterface_ToUpper(static_cast<const StringInterface*>(this));
}
template <> MAXON_ATTRIBUTE_FORCE_INLINE auto StringTemplate<StringInterface,String,Utf32Char>::ToLower() const -> StringInterface*
{
	return StringInterface::MTable::_instance.StringInterface_ToLower(static_cast<const StringInterface*>(this));
}
template <> MAXON_ATTRIBUTE_FORCE_INLINE auto StringTemplate<StringInterface,String,Utf32Char>::ComparePart(const StringInterface* str, STRINGCOMPARISON mode, StringPosition position, StringCount count) const -> COMPARERESULT
{
	return StringInterface::MTable::_instance.StringInterface_ComparePart(static_cast<const StringInterface*>(this), str, mode, std::forward<StringPosition>(position), std::forward<StringCount>(count));
}
template <> MAXON_ATTRIBUTE_FORCE_INLINE auto StringTemplate<StringInterface,String,Utf32Char>::GetHashCode() const -> HashInt
{
	return StringInterface::MTable::_instance.StringInterface_GetHashCode(static_cast<const StringInterface*>(this));
}
template <> MAXON_ATTRIBUTE_FORCE_INLINE auto StringTemplate<StringInterface,String,Utf32Char>::SetChar(Int pos, Utf32Char ch) -> void
{
	return StringInterface::MTable::_instance.StringInterface_SetChar(static_cast<StringInterface*>(this), pos, ch);
}
template <> MAXON_ATTRIBUTE_FORCE_INLINE auto StringTemplate<StringInterface,String,Utf32Char>::GetChar(Int pos) const -> Utf32Char
{
	return StringInterface::MTable::_instance.StringInterface_GetChar(static_cast<const StringInterface*>(this), pos);
}
template <> MAXON_ATTRIBUTE_FORCE_INLINE auto StringTemplate<StringInterface,String,Utf32Char>::GetUtf32(Utf32CharBuffer& stringData) const -> Result<void>
{
	return StringInterface::MTable::_instance.StringInterface_GetUtf32(static_cast<const StringInterface*>(this), stringData);
}
template <> MAXON_ATTRIBUTE_FORCE_INLINE auto StringTemplate<StringInterface,String,Utf32Char>::TrimLeft() -> Result<void>
{
	return StringInterface::MTable::_instance.StringInterface_TrimLeft(static_cast<StringInterface*>(this));
}
template <> MAXON_ATTRIBUTE_FORCE_INLINE auto StringTemplate<StringInterface,String,Utf32Char>::TrimRight() -> Result<void>
{
	return StringInterface::MTable::_instance.StringInterface_TrimRight(static_cast<StringInterface*>(this));
}
template <> MAXON_ATTRIBUTE_FORCE_INLINE auto StringTemplate<StringInterface,String,Utf32Char>::Split(const String& splitSymbol, Bool trim, const ValueReceiver<const String&>& parts) const -> Result<void>
{
	return StringInterface::MTable::_instance.StringInterface_Split(static_cast<const StringInterface*>(this), splitSymbol, trim, parts);
}
template <> MAXON_ATTRIBUTE_FORCE_INLINE auto StringTemplate<StringInterface,String,Utf32Char>::Replace(Utf32Char find, Utf32Char replace) -> Result<Int>
{
	return StringInterface::MTable::_instance.StringInterface_Replace(static_cast<StringInterface*>(this), find, replace);
}
template <> MAXON_ATTRIBUTE_FORCE_INLINE auto StringTemplate<StringInterface,String,Utf32Char>::Replace(const String& find, const String& replace) -> Result<Int>
{
	return StringInterface::MTable::_instance.StringInterface_Replace_1(static_cast<StringInterface*>(this), find, replace);
}
template <> MAXON_ATTRIBUTE_FORCE_INLINE auto StringTemplate<StringInterface,String,Utf32Char>::Replace(Utf32Char find, const String& replace) -> Result<Int>
{
	return StringInterface::MTable::_instance.StringInterface_Replace_2(static_cast<StringInterface*>(this), find, replace);
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
	return MTable::_instance.StringInterface_GetCStringBlock(this, buffer, stringEncoding);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto StringInterface::GetCStringAppendArray(const NonConstArray<Char>& array, const StringEncodingRef& stringEncoding) const -> Result<void>
{
	return MTable::_instance.StringInterface_GetCStringAppendArray(this, array, stringEncoding);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto StringInterface::GetCString(const StringEncodingRef& stringEncoding) const -> Result<BaseArray<Char>>
{
	return MTable::_instance.StringInterface_GetCString(this, stringEncoding);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto StringInterface::SetCString(const Char* buffer, Int count, const StringDecodingRef& stringDecoding) -> Result<void>
{
	return MTable::_instance.StringInterface_SetCString(this, buffer, count, stringDecoding);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto StringInterface::GetSystemEncoding() const -> Result<SysCharArray>
{
	return MTable::_instance.StringInterface_GetSystemEncoding(this);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto StringInterface::SetSystemEncoding(const SysChar* buffer, Int count) -> Result<void>
{
	return MTable::_instance.StringInterface_SetSystemEncoding(this, buffer, count);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto StringInterface::SetUtf32(const Utf32Char* buffer, Int count) -> Result<void>
{
	return MTable::_instance.StringInterface_SetUtf32(this, buffer, count);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto StringInterface::GetUtf16(Utf16CharBuffer& stringData) const -> Result<void>
{
	return MTable::_instance.StringInterface_GetUtf16(this, stringData);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto StringInterface::SetUtf16(const Utf16Char* buffer, Int count) -> Result<void>
{
	return MTable::_instance.StringInterface_SetUtf16(this, buffer, count);
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
	return MTable::_instance.StringInterface_GetVariableInternalData(this);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto StringInterface::GetCharacterWidth() const -> Int
{
	return MTable::_instance.StringInterface_GetCharacterWidth(this);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto StringInterface::Prettify(Int indent, const String& indentStr, Int breakUpThreshold, Bool angularBrackets) const -> Result<String>
{
	return MTable::_instance.StringInterface_Prettify(this, indent, indentStr, breakUpThreshold, angularBrackets);
}

template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto StringInterface::Hxx1::ConstFn<S>::GetLength() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const StringInterface* o_ = (const StringInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = StringInterface::NullValuePtr(); if (!o_) return 0; } 
	return (MTable::_instance.StringInterface_GetLength(o_));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto StringInterface::Hxx1::Fn<S>::Init(Int count, Utf32Char fillChar) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); StringInterface* o_ = (StringInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (MTable::_instance.StringInterface_Init(o_, count, fillChar));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto StringInterface::Hxx1::COWFn<S>::Init(Int count, Utf32Char fillChar) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); StringInterface* o_ = (StringInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } 
	return (MTable::_instance.StringInterface_Init(o_, count, fillChar));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto StringInterface::Hxx1::Fn<S>::Shrink() const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); StringInterface* o_ = (StringInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (MTable::_instance.StringInterface_Shrink(o_));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto StringInterface::Hxx1::COWFn<S>::Shrink() -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); StringInterface* o_ = (StringInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } 
	return (MTable::_instance.StringInterface_Shrink(o_));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto StringInterface::Hxx1::Fn<S>::Append(const StringInterface* str) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); StringInterface* o_ = (StringInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (MTable::_instance.StringInterface_Append(o_, str));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto StringInterface::Hxx1::COWFn<S>::Append(const StringInterface* str) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); StringInterface* o_ = (StringInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } 
	return (MTable::_instance.StringInterface_Append(o_, str));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto StringInterface::Hxx1::Fn<S>::Append(const String& str) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); StringInterface* o_ = (StringInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (o_->Append(str));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto StringInterface::Hxx1::COWFn<S>::Append(const String& str) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); StringInterface* o_ = (StringInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } 
	return (o_->Append(str));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto StringInterface::Hxx1::Fn<S>::Append(const Utf32Char* str, Int len) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); StringInterface* o_ = (StringInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (MTable::_instance.StringInterface_Append_1(o_, str, len));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto StringInterface::Hxx1::COWFn<S>::Append(const Utf32Char* str, Int len) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); StringInterface* o_ = (StringInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } 
	return (MTable::_instance.StringInterface_Append_1(o_, str, len));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto StringInterface::Hxx1::Fn<S>::Append(const Block<const Utf32Char>& block) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); StringInterface* o_ = (StringInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (o_->Append(block));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto StringInterface::Hxx1::COWFn<S>::Append(const Block<const Utf32Char>& block) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); StringInterface* o_ = (StringInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } 
	return (o_->Append(block));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto StringInterface::Hxx1::Fn<S>::AppendChar(Utf32Char v) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); StringInterface* o_ = (StringInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (o_->AppendChar(v));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto StringInterface::Hxx1::COWFn<S>::AppendChar(Utf32Char v) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); StringInterface* o_ = (StringInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } 
	return (o_->AppendChar(v));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto StringInterface::Hxx1::ConstFn<S>::FindIndex(const StringInterface* str, StringPosition start) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const StringInterface* o_ = (const StringInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = StringInterface::NullValuePtr(); if (!o_) return InvalidArrayIndex; } 
	return (MTable::_instance.StringInterface_FindIndex(o_, str, std::forward<StringPosition>(start)));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto StringInterface::Hxx1::ConstFn<S>::FindLastIndex(const StringInterface* str, StringPosition start) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const StringInterface* o_ = (const StringInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = StringInterface::NullValuePtr(); if (!o_) return InvalidArrayIndex; } 
	return (MTable::_instance.StringInterface_FindLastIndex(o_, str, std::forward<StringPosition>(start)));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto StringInterface::Hxx1::ConstFn<S>::FindIndex(Utf32Char ch, StringPosition start) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const StringInterface* o_ = (const StringInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = StringInterface::NullValuePtr(); if (!o_) return InvalidArrayIndex; } 
	return (MTable::_instance.StringInterface_FindIndex_1(o_, ch, std::forward<StringPosition>(start)));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto StringInterface::Hxx1::ConstFn<S>::FindLastIndex(Utf32Char ch, StringPosition start) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const StringInterface* o_ = (const StringInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = StringInterface::NullValuePtr(); if (!o_) return InvalidArrayIndex; } 
	return (MTable::_instance.StringInterface_FindLastIndex_1(o_, ch, std::forward<StringPosition>(start)));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto StringInterface::Hxx1::ConstFn<S>::FindUpperIndex(const StringInterface* str, StringPosition start) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const StringInterface* o_ = (const StringInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = StringInterface::NullValuePtr(); if (!o_) return InvalidArrayIndex; } 
	return (MTable::_instance.StringInterface_FindUpperIndex(o_, str, std::forward<StringPosition>(start)));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto StringInterface::Hxx1::ConstFn<S>::FindLastUpperIndex(const StringInterface* str, StringPosition start) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const StringInterface* o_ = (const StringInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = StringInterface::NullValuePtr(); if (!o_) return InvalidArrayIndex; } 
	return (MTable::_instance.StringInterface_FindLastUpperIndex(o_, str, std::forward<StringPosition>(start)));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto StringInterface::Hxx1::Fn<S>::Erase(StringPosition position, StringCount count) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); StringInterface* o_ = (StringInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (MTable::_instance.StringInterface_Erase(o_, std::forward<StringPosition>(position), std::forward<StringCount>(count)));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto StringInterface::Hxx1::COWFn<S>::Erase(StringPosition position, StringCount count) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); StringInterface* o_ = (StringInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } 
	return (MTable::_instance.StringInterface_Erase(o_, std::forward<StringPosition>(position), std::forward<StringCount>(count)));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto StringInterface::Hxx1::Fn<S>::Insert(StringPosition position, const StringInterface* str, StringPosition strStart, StringCount strCount) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); StringInterface* o_ = (StringInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (MTable::_instance.StringInterface_Insert(o_, std::forward<StringPosition>(position), str, std::forward<StringPosition>(strStart), std::forward<StringCount>(strCount)));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto StringInterface::Hxx1::COWFn<S>::Insert(StringPosition position, const StringInterface* str, StringPosition strStart, StringCount strCount) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); StringInterface* o_ = (StringInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } 
	return (MTable::_instance.StringInterface_Insert(o_, std::forward<StringPosition>(position), str, std::forward<StringPosition>(strStart), std::forward<StringCount>(strCount)));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto StringInterface::Hxx1::Fn<S>::Insert(StringPosition position, Utf32Char ch) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); StringInterface* o_ = (StringInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (MTable::_instance.StringInterface_Insert_1(o_, std::forward<StringPosition>(position), ch));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto StringInterface::Hxx1::COWFn<S>::Insert(StringPosition position, Utf32Char ch) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); StringInterface* o_ = (StringInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } 
	return (MTable::_instance.StringInterface_Insert_1(o_, std::forward<StringPosition>(position), ch));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto StringInterface::Hxx1::ConstFn<S>::GetPart(StringPosition start, StringCount count) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<String>, String>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<String>, String>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const StringInterface* o_ = (const StringInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = StringInterface::NullValuePtr(); if (!o_) return String::NullValue(); } 
	return String(MTable::_instance.StringInterface_GetPart(o_, std::forward<StringPosition>(start), std::forward<StringCount>(count)));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto StringInterface::Hxx1::ConstFn<S>::ToUpper() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<String>, String>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<String>, String>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const StringInterface* o_ = (const StringInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = StringInterface::NullValuePtr(); if (!o_) return String::NullValue(); } 
	return String(MTable::_instance.StringInterface_ToUpper(o_));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto StringInterface::Hxx1::ConstFn<S>::ToLower() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<String>, String>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<String>, String>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const StringInterface* o_ = (const StringInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = StringInterface::NullValuePtr(); if (!o_) return String::NullValue(); } 
	return String(MTable::_instance.StringInterface_ToLower(o_));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto StringInterface::Hxx1::ConstFn<S>::ComparePart(const StringInterface* str, STRINGCOMPARISON mode, StringPosition position, StringCount count) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<COMPARERESULT>, COMPARERESULT>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<COMPARERESULT>, COMPARERESULT>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const StringInterface* o_ = (const StringInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = StringInterface::NullValuePtr(); if (!o_) return maxon::PrivateIncompleteNullReturnValue<COMPARERESULT>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } 
	return (MTable::_instance.StringInterface_ComparePart(o_, str, mode, std::forward<StringPosition>(position), std::forward<StringCount>(count)));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto StringInterface::Hxx1::ConstFn<S>::Compare(const StringInterface* str, STRINGCOMPARISON mode) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<COMPARERESULT>, COMPARERESULT>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<COMPARERESULT>, COMPARERESULT>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const StringInterface* o_ = (const StringInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = StringInterface::NullValuePtr(); if (!o_) return maxon::PrivateIncompleteNullReturnValue<COMPARERESULT>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } 
	return (o_->Compare(str, mode));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto StringInterface::Hxx1::ConstFn<S>::IsEqual(const StringInterface* str) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const StringInterface* o_ = (const StringInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = StringInterface::NullValuePtr(); if (!o_) return maxon::PrivateLogNullptrError(false); } 
	return (o_->IsEqual(str));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto StringInterface::Hxx1::ConstFn<S>::ToFloat64(STRINGCONVERSION flags) const -> Result<Float64>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<Float64>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const StringInterface* o_ = (const StringInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = StringInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (o_->ToFloat64(flags));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto StringInterface::Hxx1::ConstFn<S>::ToFloat32(STRINGCONVERSION flags) const -> Result<Float32>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<Float32>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const StringInterface* o_ = (const StringInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = StringInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (o_->ToFloat32(flags));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto StringInterface::Hxx1::ConstFn<S>::ToFloat(STRINGCONVERSION flags) const -> Result<Float>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<Float>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const StringInterface* o_ = (const StringInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = StringInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (o_->ToFloat(flags));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto StringInterface::Hxx1::ConstFn<S>::ToInt64(STRINGCONVERSION flags) const -> Result<Int64>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<Int64>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const StringInterface* o_ = (const StringInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = StringInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (o_->ToInt64(flags));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto StringInterface::Hxx1::ConstFn<S>::ToInt32(STRINGCONVERSION flags) const -> Result<Int32>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<Int32>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const StringInterface* o_ = (const StringInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = StringInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (o_->ToInt32(flags));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto StringInterface::Hxx1::ConstFn<S>::ToInt(STRINGCONVERSION flags) const -> Result<Int>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<Int>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const StringInterface* o_ = (const StringInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = StringInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (o_->ToInt(flags));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto StringInterface::Hxx1::ConstFn<S>::ToUInt64(STRINGCONVERSION flags) const -> Result<UInt64>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<UInt64>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const StringInterface* o_ = (const StringInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = StringInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (o_->ToUInt64(flags));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto StringInterface::Hxx1::ConstFn<S>::ToUInt32(STRINGCONVERSION flags) const -> Result<UInt32>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<UInt32>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const StringInterface* o_ = (const StringInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = StringInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (o_->ToUInt32(flags));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto StringInterface::Hxx1::ConstFn<S>::ToUInt(STRINGCONVERSION flags) const -> Result<UInt>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<UInt>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const StringInterface* o_ = (const StringInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = StringInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
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
	static_assert(!S::HAS_ERROR, "StringInterface::AppendInt can't be used on a Result object because it does not return a Result object itself."); StringInterface* o_ = (StringInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return this->PrivateGetRefMember(); } 
	if (o_->AppendInt(v) == nullptr) this->ResetReference();
	return this->PrivateGetRefMember();
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto StringInterface::Hxx1::COWFn<S>::AppendInt(Int32 v) -> DOXYGEN_SWITCH(maxon::RefMemberType<S>, S)
{
	static_assert(!S::HAS_ERROR, "StringInterface::AppendInt can't be used on a Result object because it does not return a Result object itself."); StringInterface* o_ = (StringInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return this->PrivateGetRefMember(); } 
	if (o_->AppendInt(v) == nullptr) this->ResetReference();
	return this->PrivateGetRefMember();
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto StringInterface::Hxx1::Fn<S>::AppendUInt(UInt32 v) const -> DOXYGEN_SWITCH(maxon::RefMemberType<S const>, S)
{
	static_assert(!S::HAS_ERROR, "StringInterface::AppendUInt can't be used on a Result object because it does not return a Result object itself."); StringInterface* o_ = (StringInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return this->PrivateGetRefMember(); } 
	if (o_->AppendUInt(v) == nullptr) this->ResetReference();
	return this->PrivateGetRefMember();
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto StringInterface::Hxx1::COWFn<S>::AppendUInt(UInt32 v) -> DOXYGEN_SWITCH(maxon::RefMemberType<S>, S)
{
	static_assert(!S::HAS_ERROR, "StringInterface::AppendUInt can't be used on a Result object because it does not return a Result object itself."); StringInterface* o_ = (StringInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return this->PrivateGetRefMember(); } 
	if (o_->AppendUInt(v) == nullptr) this->ResetReference();
	return this->PrivateGetRefMember();
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto StringInterface::Hxx1::Fn<S>::AppendInt(Int64 v) const -> DOXYGEN_SWITCH(maxon::RefMemberType<S const>, S)
{
	static_assert(!S::HAS_ERROR, "StringInterface::AppendInt can't be used on a Result object because it does not return a Result object itself."); StringInterface* o_ = (StringInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return this->PrivateGetRefMember(); } 
	if (o_->AppendInt(v) == nullptr) this->ResetReference();
	return this->PrivateGetRefMember();
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto StringInterface::Hxx1::COWFn<S>::AppendInt(Int64 v) -> DOXYGEN_SWITCH(maxon::RefMemberType<S>, S)
{
	static_assert(!S::HAS_ERROR, "StringInterface::AppendInt can't be used on a Result object because it does not return a Result object itself."); StringInterface* o_ = (StringInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return this->PrivateGetRefMember(); } 
	if (o_->AppendInt(v) == nullptr) this->ResetReference();
	return this->PrivateGetRefMember();
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto StringInterface::Hxx1::Fn<S>::AppendUInt(UInt64 v) const -> DOXYGEN_SWITCH(maxon::RefMemberType<S const>, S)
{
	static_assert(!S::HAS_ERROR, "StringInterface::AppendUInt can't be used on a Result object because it does not return a Result object itself."); StringInterface* o_ = (StringInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return this->PrivateGetRefMember(); } 
	if (o_->AppendUInt(v) == nullptr) this->ResetReference();
	return this->PrivateGetRefMember();
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto StringInterface::Hxx1::COWFn<S>::AppendUInt(UInt64 v) -> DOXYGEN_SWITCH(maxon::RefMemberType<S>, S)
{
	static_assert(!S::HAS_ERROR, "StringInterface::AppendUInt can't be used on a Result object because it does not return a Result object itself."); StringInterface* o_ = (StringInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return this->PrivateGetRefMember(); } 
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
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const StringInterface* o_ = (const StringInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = StringInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (MTable::_instance.StringInterface_GetUtf32(o_, stringData));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto StringInterface::Hxx1::Fn<S>::TrimLeft() const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); StringInterface* o_ = (StringInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (MTable::_instance.StringInterface_TrimLeft(o_));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto StringInterface::Hxx1::COWFn<S>::TrimLeft() -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); StringInterface* o_ = (StringInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } 
	return (MTable::_instance.StringInterface_TrimLeft(o_));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto StringInterface::Hxx1::Fn<S>::TrimRight() const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); StringInterface* o_ = (StringInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (MTable::_instance.StringInterface_TrimRight(o_));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto StringInterface::Hxx1::COWFn<S>::TrimRight() -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); StringInterface* o_ = (StringInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } 
	return (MTable::_instance.StringInterface_TrimRight(o_));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto StringInterface::Hxx1::ConstFn<S>::Split(const String& splitSymbol, Bool trim, const ValueReceiver<const String&>& parts) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const StringInterface* o_ = (const StringInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = StringInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (MTable::_instance.StringInterface_Split(o_, splitSymbol, trim, parts));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto StringInterface::Hxx1::Fn<S>::Replace(Utf32Char find, Utf32Char replace) const -> Result<Int>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<Int>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); StringInterface* o_ = (StringInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (MTable::_instance.StringInterface_Replace(o_, find, replace));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto StringInterface::Hxx1::COWFn<S>::Replace(Utf32Char find, Utf32Char replace) -> Result<Int>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<Int>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); StringInterface* o_ = (StringInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } 
	return (MTable::_instance.StringInterface_Replace(o_, find, replace));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto StringInterface::Hxx1::Fn<S>::Replace(const String& find, const String& replace) const -> Result<Int>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<Int>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); StringInterface* o_ = (StringInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (MTable::_instance.StringInterface_Replace_1(o_, find, replace));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto StringInterface::Hxx1::COWFn<S>::Replace(const String& find, const String& replace) -> Result<Int>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<Int>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); StringInterface* o_ = (StringInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } 
	return (MTable::_instance.StringInterface_Replace_1(o_, find, replace));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto StringInterface::Hxx1::Fn<S>::Replace(Utf32Char find, const String& replace) const -> Result<Int>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<Int>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); StringInterface* o_ = (StringInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (MTable::_instance.StringInterface_Replace_2(o_, find, replace));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto StringInterface::Hxx1::COWFn<S>::Replace(Utf32Char find, const String& replace) -> Result<Int>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<Int>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); StringInterface* o_ = (StringInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } 
	return (MTable::_instance.StringInterface_Replace_2(o_, find, replace));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto StringInterface::Hxx1::ConstFn<S>::Find(const String& str, Int* pos, StringPosition start) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const StringInterface* o_ = (const StringInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = StringInterface::NullValuePtr(); if (!o_) return maxon::PrivateLogNullptrError(false); } 
	return (o_->Find(str, pos, std::forward<StringPosition>(start)));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto StringInterface::Hxx1::ConstFn<S>::FindLast(const String& str, Int* pos, StringPosition start) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const StringInterface* o_ = (const StringInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = StringInterface::NullValuePtr(); if (!o_) return maxon::PrivateLogNullptrError(false); } 
	return (o_->FindLast(str, pos, std::forward<StringPosition>(start)));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto StringInterface::Hxx1::ConstFn<S>::Find(Utf32Char ch, Int* pos, StringPosition start) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const StringInterface* o_ = (const StringInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = StringInterface::NullValuePtr(); if (!o_) return maxon::PrivateLogNullptrError(false); } 
	return (o_->Find(ch, pos, std::forward<StringPosition>(start)));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto StringInterface::Hxx1::ConstFn<S>::FindLast(Utf32Char ch, Int* pos, StringPosition start) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const StringInterface* o_ = (const StringInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = StringInterface::NullValuePtr(); if (!o_) return maxon::PrivateLogNullptrError(false); } 
	return (o_->FindLast(ch, pos, std::forward<StringPosition>(start)));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto StringInterface::Hxx1::ConstFn<S>::FindUpper(const String& str, Int* pos, StringPosition start) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const StringInterface* o_ = (const StringInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = StringInterface::NullValuePtr(); if (!o_) return maxon::PrivateLogNullptrError(false); } 
	return (o_->FindUpper(str, pos, std::forward<StringPosition>(start)));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto StringInterface::Hxx1::ConstFn<S>::FindLastUpper(const String& str, Int* pos, StringPosition start) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const StringInterface* o_ = (const StringInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = StringInterface::NullValuePtr(); if (!o_) return maxon::PrivateLogNullptrError(false); } 
	return (o_->FindLastUpper(str, pos, std::forward<StringPosition>(start)));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto StringInterface::Hxx1::ConstFn<S>::GetLeftPart(StringPosition start) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<String>, String>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<String>, String>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const StringInterface* o_ = (const StringInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = StringInterface::NullValuePtr(); if (!o_) return String::NullValue(); } 
	return String(o_->GetLeftPart(std::forward<StringPosition>(start)));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto StringInterface::Hxx1::ConstFn<S>::GetRightPart(StringPosition start) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<String>, String>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<String>, String>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const StringInterface* o_ = (const StringInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = StringInterface::NullValuePtr(); if (!o_) return String::NullValue(); } 
	return String(o_->GetRightPart(std::forward<StringPosition>(start)));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto StringInterface::Hxx1::ConstFn<S>::StartsWith(Utf32Char ch) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const StringInterface* o_ = (const StringInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = StringInterface::NullValuePtr(); if (!o_) return maxon::PrivateLogNullptrError(false); } 
	return (o_->StartsWith(ch));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto StringInterface::Hxx1::ConstFn<S>::StartsWith(const String& str) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const StringInterface* o_ = (const StringInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = StringInterface::NullValuePtr(); if (!o_) return maxon::PrivateLogNullptrError(false); } 
	return (o_->StartsWith(str));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto StringInterface::Hxx1::ConstFn<S>::EndsWith(Utf32Char ch) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const StringInterface* o_ = (const StringInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = StringInterface::NullValuePtr(); if (!o_) return maxon::PrivateLogNullptrError(false); } 
	return (o_->EndsWith(ch));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto StringInterface::Hxx1::ConstFn<S>::EndsWith(const String& str) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const StringInterface* o_ = (const StringInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = StringInterface::NullValuePtr(); if (!o_) return maxon::PrivateLogNullptrError(false); } 
	return (o_->EndsWith(str));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto StringInterface::Hxx1::Fn<S>::Trim() const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); StringInterface* o_ = (StringInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (o_->Trim());
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto StringInterface::Hxx1::COWFn<S>::Trim() -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); StringInterface* o_ = (StringInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } 
	return (o_->Trim());
}
auto StringInterface::Reference::Create() -> maxon::ResultMemT<String>
{
	StringInterface* res_ = StringInterface::Alloc(MAXON_SOURCE_LOCATION);
	return String(maxon::ForwardResultPtr<StringInterface>(res_));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto StringInterface::Hxx1::ConstFn<S>::GetCStringBlock(const Block<Char>& buffer, const StringEncodingRef& stringEncoding) const -> Result<Int>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<Int>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const StringInterface* o_ = (const StringInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = StringInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (MTable::_instance.StringInterface_GetCStringBlock(o_, buffer, stringEncoding));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto StringInterface::Hxx1::ConstFn<S>::GetCStringAppendArray(const NonConstArray<Char>& array, const StringEncodingRef& stringEncoding) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const StringInterface* o_ = (const StringInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = StringInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (MTable::_instance.StringInterface_GetCStringAppendArray(o_, array, stringEncoding));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto StringInterface::Hxx1::ConstFn<S>::GetCString(const StringEncodingRef& stringEncoding) const -> Result<BaseArray<Char>>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<BaseArray<Char>>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const StringInterface* o_ = (const StringInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = StringInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (MTable::_instance.StringInterface_GetCString(o_, stringEncoding));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto StringInterface::Hxx1::Fn<S>::SetCString(const Char* buffer, Int count, const StringDecodingRef& stringDecoding) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); StringInterface* o_ = (StringInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (MTable::_instance.StringInterface_SetCString(o_, buffer, count, stringDecoding));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto StringInterface::Hxx1::COWFn<S>::SetCString(const Char* buffer, Int count, const StringDecodingRef& stringDecoding) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); StringInterface* o_ = (StringInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } 
	return (MTable::_instance.StringInterface_SetCString(o_, buffer, count, stringDecoding));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto StringInterface::Hxx1::Fn<S>::SetCString(const Block<const Char>& buffer, const StringDecodingRef& stringDecoding) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); StringInterface* o_ = (StringInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (o_->SetCString(buffer, stringDecoding));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto StringInterface::Hxx1::COWFn<S>::SetCString(const Block<const Char>& buffer, const StringDecodingRef& stringDecoding) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); StringInterface* o_ = (StringInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } 
	return (o_->SetCString(buffer, stringDecoding));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto StringInterface::Hxx1::ConstFn<S>::GetSystemEncoding() const -> Result<SysCharArray>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<SysCharArray>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const StringInterface* o_ = (const StringInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = StringInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (MTable::_instance.StringInterface_GetSystemEncoding(o_));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto StringInterface::Hxx1::Fn<S>::SetSystemEncoding(const SysChar* buffer, Int count) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); StringInterface* o_ = (StringInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (MTable::_instance.StringInterface_SetSystemEncoding(o_, buffer, count));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto StringInterface::Hxx1::COWFn<S>::SetSystemEncoding(const SysChar* buffer, Int count) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); StringInterface* o_ = (StringInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } 
	return (MTable::_instance.StringInterface_SetSystemEncoding(o_, buffer, count));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto StringInterface::Hxx1::Fn<S>::SetUtf32(const Utf32Char* buffer, Int count) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); StringInterface* o_ = (StringInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (MTable::_instance.StringInterface_SetUtf32(o_, buffer, count));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto StringInterface::Hxx1::COWFn<S>::SetUtf32(const Utf32Char* buffer, Int count) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); StringInterface* o_ = (StringInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } 
	return (MTable::_instance.StringInterface_SetUtf32(o_, buffer, count));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto StringInterface::Hxx1::ConstFn<S>::GetUtf16(Utf16CharBuffer& stringData) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const StringInterface* o_ = (const StringInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = StringInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (MTable::_instance.StringInterface_GetUtf16(o_, stringData));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto StringInterface::Hxx1::Fn<S>::SetUtf16(const Utf16Char* buffer, Int count) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); StringInterface* o_ = (StringInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (MTable::_instance.StringInterface_SetUtf16(o_, buffer, count));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto StringInterface::Hxx1::COWFn<S>::SetUtf16(const Utf16Char* buffer, Int count) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); StringInterface* o_ = (StringInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } 
	return (MTable::_instance.StringInterface_SetUtf16(o_, buffer, count));
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
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<StridedBlock<const Generic>>, StridedBlock<const Generic>>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const StringInterface* o_ = (const StringInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = StringInterface::NullValuePtr(); if (!o_) return maxon::PrivateIncompleteNullReturnValue<StridedBlock<const Generic>>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } 
	return (MTable::_instance.StringInterface_GetVariableInternalData(o_));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto StringInterface::Hxx1::ConstFn<S>::GetCharacterWidth() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const StringInterface* o_ = (const StringInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = StringInterface::NullValuePtr(); if (!o_) return 0; } 
	return (MTable::_instance.StringInterface_GetCharacterWidth(o_));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto StringInterface::Hxx1::ConstFn<S>::ConvertString(const StreamConversionRef& converter) const -> Result<String>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<String>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const StringInterface* o_ = (const StringInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = StringInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (o_->ConvertString(converter));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto StringInterface::Hxx1::ConstFn<S>::Prettify(Int indent, const String& indentStr, Int breakUpThreshold, Bool angularBrackets) const -> Result<String>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<String>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const StringInterface* o_ = (const StringInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = StringInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (MTable::_instance.StringInterface_Prettify(o_, indent, indentStr, breakUpThreshold, angularBrackets));
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
	void (*CStringInterface_Free) (const CStringInterface* object);
	Int (*CStringInterface_GetLength) (const CStringInterface* this_);
	Result<void> (*CStringInterface_Init) (CStringInterface* this_, Int count, Char fillChar);
	Result<void> (*CStringInterface_Shrink) (CStringInterface* this_);
	Result<void> (*CStringInterface_Append) (CStringInterface* this_, const CStringInterface* str);
	Result<void> (*CStringInterface_Append_1) (CStringInterface* this_, const Char* str, Int len);
	Int (*CStringInterface_FindIndex) (const CStringInterface* this_, const CStringInterface* str, StringPosition start);
	Int (*CStringInterface_FindLastIndex) (const CStringInterface* this_, const CStringInterface* str, StringPosition start);
	Int (*CStringInterface_FindIndex_1) (const CStringInterface* this_, Char ch, StringPosition start);
	Int (*CStringInterface_FindLastIndex_1) (const CStringInterface* this_, Char ch, StringPosition start);
	Int (*CStringInterface_FindUpperIndex) (const CStringInterface* this_, const CStringInterface* str, StringPosition start);
	Int (*CStringInterface_FindLastUpperIndex) (const CStringInterface* this_, const CStringInterface* str, StringPosition start);
	Result<void> (*CStringInterface_Erase) (CStringInterface* this_, StringPosition position, StringCount count);
	Result<void> (*CStringInterface_Insert) (CStringInterface* this_, StringPosition position, const CStringInterface* str, StringPosition strStart, StringCount strCount);
	Result<void> (*CStringInterface_Insert_1) (CStringInterface* this_, StringPosition position, Char ch);
	CStringInterface* (*CStringInterface_GetPart) (const CStringInterface* this_, StringPosition start, StringCount count);
	CStringInterface* (*CStringInterface_ToUpper) (const CStringInterface* this_);
	CStringInterface* (*CStringInterface_ToLower) (const CStringInterface* this_);
	COMPARERESULT (*CStringInterface_ComparePart) (const CStringInterface* this_, const CStringInterface* str, STRINGCOMPARISON mode, StringPosition position, StringCount count);
	HashInt (*CStringInterface_GetHashCode) (const CStringInterface* this_);
	void (*CStringInterface_SetChar) (CStringInterface* this_, Int pos, Char ch);
	Char (*CStringInterface_GetChar) (const CStringInterface* this_, Int pos);
	Result<void> (*CStringInterface_GetUtf32) (const CStringInterface* this_, Utf32CharBuffer& stringData);
	Result<void> (*CStringInterface_TrimLeft) (CStringInterface* this_);
	Result<void> (*CStringInterface_TrimRight) (CStringInterface* this_);
	Result<void> (*CStringInterface_Split) (const CStringInterface* this_, const CString& splitSymbol, Bool trim, const ValueReceiver<const CString&>& parts);
	Result<Int> (*CStringInterface_Replace) (CStringInterface* this_, Char find, Char replace);
	Result<Int> (*CStringInterface_Replace_1) (CStringInterface* this_, const CString& find, const CString& replace);
	Result<Int> (*CStringInterface_Replace_2) (CStringInterface* this_, Char find, const CString& replace);
	CStringInterface* (*CStringInterface_Alloc) (const maxon::SourceLocation& allocLocation);
	CStringInterface* (*CStringInterface_Alloc_1) (const maxon::SourceLocation& allocLocation, const CStringInterface& object);
	Result<Int> (*CStringInterface_GetCStringBlock) (const CStringInterface* this_, const Block<Char>& buffer);
	Result<void> (*CStringInterface_GetCStringAppendArray) (const CStringInterface* this_, const NonConstArray<Char>& array);
	Result<void> (*CStringInterface_SetCString) (CStringInterface* this_, const Char* buffer, Int count);
	Result<BaseArray<Char>> (*CStringInterface_GetCString) (const CStringInterface* this_);
	Block<const Char> (*CStringInterface_GetInternalData) (const CStringInterface* this_);
	const CString& (*CStringInterface_GetAndCacheConstString) (const Char* chr, Int len);
	template <typename IMPL> void Init()
	{
		CStringInterface_Free = &IMPL::CStringInterface_Free;
		CStringInterface_GetLength = &IMPL::CStringInterface_GetLength;
		CStringInterface_Init = &IMPL::CStringInterface_Init;
		CStringInterface_Shrink = &IMPL::CStringInterface_Shrink;
		CStringInterface_Append = &IMPL::CStringInterface_Append;
		CStringInterface_Append_1 = &IMPL::CStringInterface_Append_1;
		CStringInterface_FindIndex = &IMPL::CStringInterface_FindIndex;
		CStringInterface_FindLastIndex = &IMPL::CStringInterface_FindLastIndex;
		CStringInterface_FindIndex_1 = &IMPL::CStringInterface_FindIndex_1;
		CStringInterface_FindLastIndex_1 = &IMPL::CStringInterface_FindLastIndex_1;
		CStringInterface_FindUpperIndex = &IMPL::CStringInterface_FindUpperIndex;
		CStringInterface_FindLastUpperIndex = &IMPL::CStringInterface_FindLastUpperIndex;
		CStringInterface_Erase = &IMPL::CStringInterface_Erase;
		CStringInterface_Insert = &IMPL::CStringInterface_Insert;
		CStringInterface_Insert_1 = &IMPL::CStringInterface_Insert_1;
		CStringInterface_GetPart = &IMPL::CStringInterface_GetPart;
		CStringInterface_ToUpper = &IMPL::CStringInterface_ToUpper;
		CStringInterface_ToLower = &IMPL::CStringInterface_ToLower;
		CStringInterface_ComparePart = &IMPL::CStringInterface_ComparePart;
		CStringInterface_GetHashCode = &IMPL::CStringInterface_GetHashCode;
		CStringInterface_SetChar = &IMPL::CStringInterface_SetChar;
		CStringInterface_GetChar = &IMPL::CStringInterface_GetChar;
		CStringInterface_GetUtf32 = &IMPL::CStringInterface_GetUtf32;
		CStringInterface_TrimLeft = &IMPL::CStringInterface_TrimLeft;
		CStringInterface_TrimRight = &IMPL::CStringInterface_TrimRight;
		CStringInterface_Split = &IMPL::CStringInterface_Split;
		CStringInterface_Replace = &IMPL::CStringInterface_Replace;
		CStringInterface_Replace_1 = &IMPL::CStringInterface_Replace_1;
		CStringInterface_Replace_2 = &IMPL::CStringInterface_Replace_2;
		CStringInterface_Alloc = &IMPL::CStringInterface_Alloc;
		CStringInterface_Alloc_1 = &IMPL::CStringInterface_Alloc_1;
		CStringInterface_GetCStringBlock = &IMPL::CStringInterface_GetCStringBlock;
		CStringInterface_GetCStringAppendArray = &IMPL::CStringInterface_GetCStringAppendArray;
		CStringInterface_SetCString = &IMPL::CStringInterface_SetCString;
		CStringInterface_GetCString = &IMPL::CStringInterface_GetCString;
		CStringInterface_GetInternalData = &IMPL::CStringInterface_GetInternalData;
		CStringInterface_GetAndCacheConstString = &IMPL::CStringInterface_GetAndCacheConstString;
	}
};

struct CStringInterface::Hxx2
{
	class Unresolved;
	template <typename C> class Wrapper
	{
	public:
		static void CStringInterface_Free(const CStringInterface* object) { return C::Free(object); }
		static Int CStringInterface_GetLength(const CStringInterface* this_) { return C::Get(this_)->GetLength(); }
		static Result<void> CStringInterface_Init(CStringInterface* this_, Int count, Char fillChar) { return C::Get(this_)->Init(count, fillChar); }
		static Result<void> CStringInterface_Shrink(CStringInterface* this_) { return C::Get(this_)->Shrink(); }
		static Result<void> CStringInterface_Append(CStringInterface* this_, const CStringInterface* str) { return C::Get(this_)->Append(str); }
		static Result<void> CStringInterface_Append_1(CStringInterface* this_, const Char* str, Int len) { return C::Get(this_)->Append(str, len); }
		static Int CStringInterface_FindIndex(const CStringInterface* this_, const CStringInterface* str, StringPosition start) { return C::Get(this_)->FindIndex(str, std::forward<StringPosition>(start)); }
		static Int CStringInterface_FindLastIndex(const CStringInterface* this_, const CStringInterface* str, StringPosition start) { return C::Get(this_)->FindLastIndex(str, std::forward<StringPosition>(start)); }
		static Int CStringInterface_FindIndex_1(const CStringInterface* this_, Char ch, StringPosition start) { return C::Get(this_)->FindIndex(ch, std::forward<StringPosition>(start)); }
		static Int CStringInterface_FindLastIndex_1(const CStringInterface* this_, Char ch, StringPosition start) { return C::Get(this_)->FindLastIndex(ch, std::forward<StringPosition>(start)); }
		static Int CStringInterface_FindUpperIndex(const CStringInterface* this_, const CStringInterface* str, StringPosition start) { return C::Get(this_)->FindUpperIndex(str, std::forward<StringPosition>(start)); }
		static Int CStringInterface_FindLastUpperIndex(const CStringInterface* this_, const CStringInterface* str, StringPosition start) { return C::Get(this_)->FindLastUpperIndex(str, std::forward<StringPosition>(start)); }
		static Result<void> CStringInterface_Erase(CStringInterface* this_, StringPosition position, StringCount count) { return C::Get(this_)->Erase(std::forward<StringPosition>(position), std::forward<StringCount>(count)); }
		static Result<void> CStringInterface_Insert(CStringInterface* this_, StringPosition position, const CStringInterface* str, StringPosition strStart, StringCount strCount) { return C::Get(this_)->Insert(std::forward<StringPosition>(position), str, std::forward<StringPosition>(strStart), std::forward<StringCount>(strCount)); }
		static Result<void> CStringInterface_Insert_1(CStringInterface* this_, StringPosition position, Char ch) { return C::Get(this_)->Insert(std::forward<StringPosition>(position), ch); }
		static CStringInterface* CStringInterface_GetPart(const CStringInterface* this_, StringPosition start, StringCount count) { return C::Get(this_)->GetPart(std::forward<StringPosition>(start), std::forward<StringCount>(count)); }
		static CStringInterface* CStringInterface_ToUpper(const CStringInterface* this_) { return C::Get(this_)->ToUpper(); }
		static CStringInterface* CStringInterface_ToLower(const CStringInterface* this_) { return C::Get(this_)->ToLower(); }
		static COMPARERESULT CStringInterface_ComparePart(const CStringInterface* this_, const CStringInterface* str, STRINGCOMPARISON mode, StringPosition position, StringCount count) { return C::Get(this_)->ComparePart(str, mode, std::forward<StringPosition>(position), std::forward<StringCount>(count)); }
		static HashInt CStringInterface_GetHashCode(const CStringInterface* this_) { return C::Get(this_)->GetHashCode(); }
		static void CStringInterface_SetChar(CStringInterface* this_, Int pos, Char ch) { return C::Get(this_)->SetChar(pos, ch); }
		static Char CStringInterface_GetChar(const CStringInterface* this_, Int pos) { return C::Get(this_)->GetChar(pos); }
		static Result<void> CStringInterface_GetUtf32(const CStringInterface* this_, Utf32CharBuffer& stringData) { return C::Get(this_)->GetUtf32(stringData); }
		static Result<void> CStringInterface_TrimLeft(CStringInterface* this_) { return C::Get(this_)->TrimLeft(); }
		static Result<void> CStringInterface_TrimRight(CStringInterface* this_) { return C::Get(this_)->TrimRight(); }
		static Result<void> CStringInterface_Split(const CStringInterface* this_, const CString& splitSymbol, Bool trim, const ValueReceiver<const CString&>& parts) { return C::Get(this_)->Split(splitSymbol, trim, parts); }
		static Result<Int> CStringInterface_Replace(CStringInterface* this_, Char find, Char replace) { return C::Get(this_)->Replace(find, replace); }
		static Result<Int> CStringInterface_Replace_1(CStringInterface* this_, const CString& find, const CString& replace) { return C::Get(this_)->Replace(find, replace); }
		static Result<Int> CStringInterface_Replace_2(CStringInterface* this_, Char find, const CString& replace) { return C::Get(this_)->Replace(find, replace); }
		static CStringInterface* CStringInterface_Alloc(const maxon::SourceLocation& allocLocation) { return C::Alloc(allocLocation); }
		static CStringInterface* CStringInterface_Alloc_1(const maxon::SourceLocation& allocLocation, const CStringInterface& object) { return C::Alloc(allocLocation, ((const C&) object)); }
		static Result<Int> CStringInterface_GetCStringBlock(const CStringInterface* this_, const Block<Char>& buffer) { return C::Get(this_)->GetCStringBlock(buffer); }
		static Result<void> CStringInterface_GetCStringAppendArray(const CStringInterface* this_, const NonConstArray<Char>& array) { return C::Get(this_)->GetCStringAppendArray(array); }
		static Result<void> CStringInterface_SetCString(CStringInterface* this_, const Char* buffer, Int count) { return C::Get(this_)->SetCString(buffer, count); }
		static Result<BaseArray<Char>> CStringInterface_GetCString(const CStringInterface* this_) { return C::Get(this_)->GetCString(); }
		static Block<const Char> CStringInterface_GetInternalData(const CStringInterface* this_) { return C::Get(this_)->GetInternalData(); }
		static const CString& CStringInterface_GetAndCacheConstString(const Char* chr, Int len) { return C::GetAndCacheConstString(chr, len); }
	};

};
MAXON_ATTRIBUTE_FORCE_INLINE auto CStringInterface::Free(const CStringInterface* object) -> void
{
	return MTable::_instance.CStringInterface_Free(object);
}
template <> MAXON_ATTRIBUTE_FORCE_INLINE auto StringTemplate<CStringInterface,CString,Char>::GetLength() const -> Int
{
	return CStringInterface::MTable::_instance.CStringInterface_GetLength(static_cast<const CStringInterface*>(this));
}
template <> MAXON_ATTRIBUTE_FORCE_INLINE auto StringTemplate<CStringInterface,CString,Char>::Init(Int count, Char fillChar) -> Result<void>
{
	return CStringInterface::MTable::_instance.CStringInterface_Init(static_cast<CStringInterface*>(this), count, fillChar);
}
template <> MAXON_ATTRIBUTE_FORCE_INLINE auto StringTemplate<CStringInterface,CString,Char>::Shrink() -> Result<void>
{
	return CStringInterface::MTable::_instance.CStringInterface_Shrink(static_cast<CStringInterface*>(this));
}
template <> MAXON_ATTRIBUTE_FORCE_INLINE auto StringTemplate<CStringInterface,CString,Char>::Append(const CStringInterface* str) -> Result<void>
{
	return CStringInterface::MTable::_instance.CStringInterface_Append(static_cast<CStringInterface*>(this), str);
}
template <> MAXON_ATTRIBUTE_FORCE_INLINE auto StringTemplate<CStringInterface,CString,Char>::Append(const Char* str, Int len) -> Result<void>
{
	return CStringInterface::MTable::_instance.CStringInterface_Append_1(static_cast<CStringInterface*>(this), str, len);
}
template <> MAXON_ATTRIBUTE_FORCE_INLINE auto StringTemplate<CStringInterface,CString,Char>::FindIndex(const CStringInterface* str, StringPosition start) const -> Int
{
	return CStringInterface::MTable::_instance.CStringInterface_FindIndex(static_cast<const CStringInterface*>(this), str, std::forward<StringPosition>(start));
}
template <> MAXON_ATTRIBUTE_FORCE_INLINE auto StringTemplate<CStringInterface,CString,Char>::FindLastIndex(const CStringInterface* str, StringPosition start) const -> Int
{
	return CStringInterface::MTable::_instance.CStringInterface_FindLastIndex(static_cast<const CStringInterface*>(this), str, std::forward<StringPosition>(start));
}
template <> MAXON_ATTRIBUTE_FORCE_INLINE auto StringTemplate<CStringInterface,CString,Char>::FindIndex(Char ch, StringPosition start) const -> Int
{
	return CStringInterface::MTable::_instance.CStringInterface_FindIndex_1(static_cast<const CStringInterface*>(this), ch, std::forward<StringPosition>(start));
}
template <> MAXON_ATTRIBUTE_FORCE_INLINE auto StringTemplate<CStringInterface,CString,Char>::FindLastIndex(Char ch, StringPosition start) const -> Int
{
	return CStringInterface::MTable::_instance.CStringInterface_FindLastIndex_1(static_cast<const CStringInterface*>(this), ch, std::forward<StringPosition>(start));
}
template <> MAXON_ATTRIBUTE_FORCE_INLINE auto StringTemplate<CStringInterface,CString,Char>::FindUpperIndex(const CStringInterface* str, StringPosition start) const -> Int
{
	return CStringInterface::MTable::_instance.CStringInterface_FindUpperIndex(static_cast<const CStringInterface*>(this), str, std::forward<StringPosition>(start));
}
template <> MAXON_ATTRIBUTE_FORCE_INLINE auto StringTemplate<CStringInterface,CString,Char>::FindLastUpperIndex(const CStringInterface* str, StringPosition start) const -> Int
{
	return CStringInterface::MTable::_instance.CStringInterface_FindLastUpperIndex(static_cast<const CStringInterface*>(this), str, std::forward<StringPosition>(start));
}
template <> MAXON_ATTRIBUTE_FORCE_INLINE auto StringTemplate<CStringInterface,CString,Char>::Erase(StringPosition position, StringCount count) -> Result<void>
{
	return CStringInterface::MTable::_instance.CStringInterface_Erase(static_cast<CStringInterface*>(this), std::forward<StringPosition>(position), std::forward<StringCount>(count));
}
template <> MAXON_ATTRIBUTE_FORCE_INLINE auto StringTemplate<CStringInterface,CString,Char>::Insert(StringPosition position, const CStringInterface* str, StringPosition strStart, StringCount strCount) -> Result<void>
{
	return CStringInterface::MTable::_instance.CStringInterface_Insert(static_cast<CStringInterface*>(this), std::forward<StringPosition>(position), str, std::forward<StringPosition>(strStart), std::forward<StringCount>(strCount));
}
template <> MAXON_ATTRIBUTE_FORCE_INLINE auto StringTemplate<CStringInterface,CString,Char>::Insert(StringPosition position, Char ch) -> Result<void>
{
	return CStringInterface::MTable::_instance.CStringInterface_Insert_1(static_cast<CStringInterface*>(this), std::forward<StringPosition>(position), ch);
}
template <> MAXON_ATTRIBUTE_FORCE_INLINE auto StringTemplate<CStringInterface,CString,Char>::GetPart(StringPosition start, StringCount count) const -> CStringInterface*
{
	return CStringInterface::MTable::_instance.CStringInterface_GetPart(static_cast<const CStringInterface*>(this), std::forward<StringPosition>(start), std::forward<StringCount>(count));
}
template <> MAXON_ATTRIBUTE_FORCE_INLINE auto StringTemplate<CStringInterface,CString,Char>::ToUpper() const -> CStringInterface*
{
	return CStringInterface::MTable::_instance.CStringInterface_ToUpper(static_cast<const CStringInterface*>(this));
}
template <> MAXON_ATTRIBUTE_FORCE_INLINE auto StringTemplate<CStringInterface,CString,Char>::ToLower() const -> CStringInterface*
{
	return CStringInterface::MTable::_instance.CStringInterface_ToLower(static_cast<const CStringInterface*>(this));
}
template <> MAXON_ATTRIBUTE_FORCE_INLINE auto StringTemplate<CStringInterface,CString,Char>::ComparePart(const CStringInterface* str, STRINGCOMPARISON mode, StringPosition position, StringCount count) const -> COMPARERESULT
{
	return CStringInterface::MTable::_instance.CStringInterface_ComparePart(static_cast<const CStringInterface*>(this), str, mode, std::forward<StringPosition>(position), std::forward<StringCount>(count));
}
template <> MAXON_ATTRIBUTE_FORCE_INLINE auto StringTemplate<CStringInterface,CString,Char>::GetHashCode() const -> HashInt
{
	return CStringInterface::MTable::_instance.CStringInterface_GetHashCode(static_cast<const CStringInterface*>(this));
}
template <> MAXON_ATTRIBUTE_FORCE_INLINE auto StringTemplate<CStringInterface,CString,Char>::SetChar(Int pos, Char ch) -> void
{
	return CStringInterface::MTable::_instance.CStringInterface_SetChar(static_cast<CStringInterface*>(this), pos, ch);
}
template <> MAXON_ATTRIBUTE_FORCE_INLINE auto StringTemplate<CStringInterface,CString,Char>::GetChar(Int pos) const -> Char
{
	return CStringInterface::MTable::_instance.CStringInterface_GetChar(static_cast<const CStringInterface*>(this), pos);
}
template <> MAXON_ATTRIBUTE_FORCE_INLINE auto StringTemplate<CStringInterface,CString,Char>::GetUtf32(Utf32CharBuffer& stringData) const -> Result<void>
{
	return CStringInterface::MTable::_instance.CStringInterface_GetUtf32(static_cast<const CStringInterface*>(this), stringData);
}
template <> MAXON_ATTRIBUTE_FORCE_INLINE auto StringTemplate<CStringInterface,CString,Char>::TrimLeft() -> Result<void>
{
	return CStringInterface::MTable::_instance.CStringInterface_TrimLeft(static_cast<CStringInterface*>(this));
}
template <> MAXON_ATTRIBUTE_FORCE_INLINE auto StringTemplate<CStringInterface,CString,Char>::TrimRight() -> Result<void>
{
	return CStringInterface::MTable::_instance.CStringInterface_TrimRight(static_cast<CStringInterface*>(this));
}
template <> MAXON_ATTRIBUTE_FORCE_INLINE auto StringTemplate<CStringInterface,CString,Char>::Split(const CString& splitSymbol, Bool trim, const ValueReceiver<const CString&>& parts) const -> Result<void>
{
	return CStringInterface::MTable::_instance.CStringInterface_Split(static_cast<const CStringInterface*>(this), splitSymbol, trim, parts);
}
template <> MAXON_ATTRIBUTE_FORCE_INLINE auto StringTemplate<CStringInterface,CString,Char>::Replace(Char find, Char replace) -> Result<Int>
{
	return CStringInterface::MTable::_instance.CStringInterface_Replace(static_cast<CStringInterface*>(this), find, replace);
}
template <> MAXON_ATTRIBUTE_FORCE_INLINE auto StringTemplate<CStringInterface,CString,Char>::Replace(const CString& find, const CString& replace) -> Result<Int>
{
	return CStringInterface::MTable::_instance.CStringInterface_Replace_1(static_cast<CStringInterface*>(this), find, replace);
}
template <> MAXON_ATTRIBUTE_FORCE_INLINE auto StringTemplate<CStringInterface,CString,Char>::Replace(Char find, const CString& replace) -> Result<Int>
{
	return CStringInterface::MTable::_instance.CStringInterface_Replace_2(static_cast<CStringInterface*>(this), find, replace);
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
	return MTable::_instance.CStringInterface_GetCStringBlock(this, buffer);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto CStringInterface::GetCStringAppendArray(const NonConstArray<Char>& array) const -> Result<void>
{
	return MTable::_instance.CStringInterface_GetCStringAppendArray(this, array);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto CStringInterface::SetCString(const Char* buffer, Int count) -> Result<void>
{
	return MTable::_instance.CStringInterface_SetCString(this, buffer, count);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto CStringInterface::GetCString() const -> Result<BaseArray<Char>>
{
	return MTable::_instance.CStringInterface_GetCString(this);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto CStringInterface::GetInternalData() const -> Block<const Char>
{
	return MTable::_instance.CStringInterface_GetInternalData(this);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto CStringInterface::GetAndCacheConstString(const Char* chr, Int len) -> const CString&
{
	return MTable::_instance.CStringInterface_GetAndCacheConstString(chr, len);
}

template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CStringInterface::Hxx1::ConstFn<S>::GetLength() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const CStringInterface* o_ = (const CStringInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = CStringInterface::NullValuePtr(); if (!o_) return 0; } 
	return (MTable::_instance.CStringInterface_GetLength(o_));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CStringInterface::Hxx1::Fn<S>::Init(Int count, Char fillChar) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); CStringInterface* o_ = (CStringInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (MTable::_instance.CStringInterface_Init(o_, count, fillChar));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CStringInterface::Hxx1::COWFn<S>::Init(Int count, Char fillChar) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); CStringInterface* o_ = (CStringInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } 
	return (MTable::_instance.CStringInterface_Init(o_, count, fillChar));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CStringInterface::Hxx1::Fn<S>::Shrink() const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); CStringInterface* o_ = (CStringInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (MTable::_instance.CStringInterface_Shrink(o_));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CStringInterface::Hxx1::COWFn<S>::Shrink() -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); CStringInterface* o_ = (CStringInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } 
	return (MTable::_instance.CStringInterface_Shrink(o_));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CStringInterface::Hxx1::Fn<S>::Append(const CStringInterface* str) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); CStringInterface* o_ = (CStringInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (MTable::_instance.CStringInterface_Append(o_, str));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CStringInterface::Hxx1::COWFn<S>::Append(const CStringInterface* str) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); CStringInterface* o_ = (CStringInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } 
	return (MTable::_instance.CStringInterface_Append(o_, str));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CStringInterface::Hxx1::Fn<S>::Append(const CString& str) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); CStringInterface* o_ = (CStringInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (o_->Append(str));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CStringInterface::Hxx1::COWFn<S>::Append(const CString& str) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); CStringInterface* o_ = (CStringInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } 
	return (o_->Append(str));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CStringInterface::Hxx1::Fn<S>::Append(const Char* str, Int len) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); CStringInterface* o_ = (CStringInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (MTable::_instance.CStringInterface_Append_1(o_, str, len));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CStringInterface::Hxx1::COWFn<S>::Append(const Char* str, Int len) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); CStringInterface* o_ = (CStringInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } 
	return (MTable::_instance.CStringInterface_Append_1(o_, str, len));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CStringInterface::Hxx1::Fn<S>::Append(const Block<const Char>& block) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); CStringInterface* o_ = (CStringInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (o_->Append(block));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CStringInterface::Hxx1::COWFn<S>::Append(const Block<const Char>& block) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); CStringInterface* o_ = (CStringInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } 
	return (o_->Append(block));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CStringInterface::Hxx1::Fn<S>::AppendChar(Char v) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); CStringInterface* o_ = (CStringInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (o_->AppendChar(v));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CStringInterface::Hxx1::COWFn<S>::AppendChar(Char v) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); CStringInterface* o_ = (CStringInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } 
	return (o_->AppendChar(v));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CStringInterface::Hxx1::ConstFn<S>::FindIndex(const CStringInterface* str, StringPosition start) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const CStringInterface* o_ = (const CStringInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = CStringInterface::NullValuePtr(); if (!o_) return InvalidArrayIndex; } 
	return (MTable::_instance.CStringInterface_FindIndex(o_, str, std::forward<StringPosition>(start)));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CStringInterface::Hxx1::ConstFn<S>::FindLastIndex(const CStringInterface* str, StringPosition start) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const CStringInterface* o_ = (const CStringInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = CStringInterface::NullValuePtr(); if (!o_) return InvalidArrayIndex; } 
	return (MTable::_instance.CStringInterface_FindLastIndex(o_, str, std::forward<StringPosition>(start)));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CStringInterface::Hxx1::ConstFn<S>::FindIndex(Char ch, StringPosition start) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const CStringInterface* o_ = (const CStringInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = CStringInterface::NullValuePtr(); if (!o_) return InvalidArrayIndex; } 
	return (MTable::_instance.CStringInterface_FindIndex_1(o_, ch, std::forward<StringPosition>(start)));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CStringInterface::Hxx1::ConstFn<S>::FindLastIndex(Char ch, StringPosition start) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const CStringInterface* o_ = (const CStringInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = CStringInterface::NullValuePtr(); if (!o_) return InvalidArrayIndex; } 
	return (MTable::_instance.CStringInterface_FindLastIndex_1(o_, ch, std::forward<StringPosition>(start)));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CStringInterface::Hxx1::ConstFn<S>::FindUpperIndex(const CStringInterface* str, StringPosition start) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const CStringInterface* o_ = (const CStringInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = CStringInterface::NullValuePtr(); if (!o_) return InvalidArrayIndex; } 
	return (MTable::_instance.CStringInterface_FindUpperIndex(o_, str, std::forward<StringPosition>(start)));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CStringInterface::Hxx1::ConstFn<S>::FindLastUpperIndex(const CStringInterface* str, StringPosition start) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const CStringInterface* o_ = (const CStringInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = CStringInterface::NullValuePtr(); if (!o_) return InvalidArrayIndex; } 
	return (MTable::_instance.CStringInterface_FindLastUpperIndex(o_, str, std::forward<StringPosition>(start)));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CStringInterface::Hxx1::Fn<S>::Erase(StringPosition position, StringCount count) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); CStringInterface* o_ = (CStringInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (MTable::_instance.CStringInterface_Erase(o_, std::forward<StringPosition>(position), std::forward<StringCount>(count)));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CStringInterface::Hxx1::COWFn<S>::Erase(StringPosition position, StringCount count) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); CStringInterface* o_ = (CStringInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } 
	return (MTable::_instance.CStringInterface_Erase(o_, std::forward<StringPosition>(position), std::forward<StringCount>(count)));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CStringInterface::Hxx1::Fn<S>::Insert(StringPosition position, const CStringInterface* str, StringPosition strStart, StringCount strCount) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); CStringInterface* o_ = (CStringInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (MTable::_instance.CStringInterface_Insert(o_, std::forward<StringPosition>(position), str, std::forward<StringPosition>(strStart), std::forward<StringCount>(strCount)));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CStringInterface::Hxx1::COWFn<S>::Insert(StringPosition position, const CStringInterface* str, StringPosition strStart, StringCount strCount) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); CStringInterface* o_ = (CStringInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } 
	return (MTable::_instance.CStringInterface_Insert(o_, std::forward<StringPosition>(position), str, std::forward<StringPosition>(strStart), std::forward<StringCount>(strCount)));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CStringInterface::Hxx1::Fn<S>::Insert(StringPosition position, Char ch) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); CStringInterface* o_ = (CStringInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (MTable::_instance.CStringInterface_Insert_1(o_, std::forward<StringPosition>(position), ch));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CStringInterface::Hxx1::COWFn<S>::Insert(StringPosition position, Char ch) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); CStringInterface* o_ = (CStringInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } 
	return (MTable::_instance.CStringInterface_Insert_1(o_, std::forward<StringPosition>(position), ch));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CStringInterface::Hxx1::ConstFn<S>::GetPart(StringPosition start, StringCount count) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<CString>, CString>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<CString>, CString>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const CStringInterface* o_ = (const CStringInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = CStringInterface::NullValuePtr(); if (!o_) return CString::NullValue(); } 
	return CString(MTable::_instance.CStringInterface_GetPart(o_, std::forward<StringPosition>(start), std::forward<StringCount>(count)));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CStringInterface::Hxx1::ConstFn<S>::ToUpper() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<CString>, CString>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<CString>, CString>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const CStringInterface* o_ = (const CStringInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = CStringInterface::NullValuePtr(); if (!o_) return CString::NullValue(); } 
	return CString(MTable::_instance.CStringInterface_ToUpper(o_));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CStringInterface::Hxx1::ConstFn<S>::ToLower() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<CString>, CString>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<CString>, CString>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const CStringInterface* o_ = (const CStringInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = CStringInterface::NullValuePtr(); if (!o_) return CString::NullValue(); } 
	return CString(MTable::_instance.CStringInterface_ToLower(o_));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CStringInterface::Hxx1::ConstFn<S>::ComparePart(const CStringInterface* str, STRINGCOMPARISON mode, StringPosition position, StringCount count) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<COMPARERESULT>, COMPARERESULT>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<COMPARERESULT>, COMPARERESULT>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const CStringInterface* o_ = (const CStringInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = CStringInterface::NullValuePtr(); if (!o_) return maxon::PrivateIncompleteNullReturnValue<COMPARERESULT>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } 
	return (MTable::_instance.CStringInterface_ComparePart(o_, str, mode, std::forward<StringPosition>(position), std::forward<StringCount>(count)));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CStringInterface::Hxx1::ConstFn<S>::Compare(const CStringInterface* str, STRINGCOMPARISON mode) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<COMPARERESULT>, COMPARERESULT>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<COMPARERESULT>, COMPARERESULT>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const CStringInterface* o_ = (const CStringInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = CStringInterface::NullValuePtr(); if (!o_) return maxon::PrivateIncompleteNullReturnValue<COMPARERESULT>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } 
	return (o_->Compare(str, mode));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CStringInterface::Hxx1::ConstFn<S>::IsEqual(const CStringInterface* str) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const CStringInterface* o_ = (const CStringInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = CStringInterface::NullValuePtr(); if (!o_) return maxon::PrivateLogNullptrError(false); } 
	return (o_->IsEqual(str));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CStringInterface::Hxx1::ConstFn<S>::ToFloat64(STRINGCONVERSION flags) const -> Result<Float64>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<Float64>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const CStringInterface* o_ = (const CStringInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = CStringInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (o_->ToFloat64(flags));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CStringInterface::Hxx1::ConstFn<S>::ToFloat32(STRINGCONVERSION flags) const -> Result<Float32>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<Float32>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const CStringInterface* o_ = (const CStringInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = CStringInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (o_->ToFloat32(flags));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CStringInterface::Hxx1::ConstFn<S>::ToFloat(STRINGCONVERSION flags) const -> Result<Float>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<Float>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const CStringInterface* o_ = (const CStringInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = CStringInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (o_->ToFloat(flags));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CStringInterface::Hxx1::ConstFn<S>::ToInt64(STRINGCONVERSION flags) const -> Result<Int64>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<Int64>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const CStringInterface* o_ = (const CStringInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = CStringInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (o_->ToInt64(flags));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CStringInterface::Hxx1::ConstFn<S>::ToInt32(STRINGCONVERSION flags) const -> Result<Int32>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<Int32>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const CStringInterface* o_ = (const CStringInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = CStringInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (o_->ToInt32(flags));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CStringInterface::Hxx1::ConstFn<S>::ToInt(STRINGCONVERSION flags) const -> Result<Int>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<Int>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const CStringInterface* o_ = (const CStringInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = CStringInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (o_->ToInt(flags));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CStringInterface::Hxx1::ConstFn<S>::ToUInt64(STRINGCONVERSION flags) const -> Result<UInt64>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<UInt64>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const CStringInterface* o_ = (const CStringInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = CStringInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (o_->ToUInt64(flags));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CStringInterface::Hxx1::ConstFn<S>::ToUInt32(STRINGCONVERSION flags) const -> Result<UInt32>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<UInt32>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const CStringInterface* o_ = (const CStringInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = CStringInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (o_->ToUInt32(flags));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CStringInterface::Hxx1::ConstFn<S>::ToUInt(STRINGCONVERSION flags) const -> Result<UInt>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<UInt>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const CStringInterface* o_ = (const CStringInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = CStringInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
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
	static_assert(!S::HAS_ERROR, "CStringInterface::AppendInt can't be used on a Result object because it does not return a Result object itself."); CStringInterface* o_ = (CStringInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return this->PrivateGetRefMember(); } 
	if (o_->AppendInt(v) == nullptr) this->ResetReference();
	return this->PrivateGetRefMember();
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CStringInterface::Hxx1::COWFn<S>::AppendInt(Int32 v) -> DOXYGEN_SWITCH(maxon::RefMemberType<S>, S)
{
	static_assert(!S::HAS_ERROR, "CStringInterface::AppendInt can't be used on a Result object because it does not return a Result object itself."); CStringInterface* o_ = (CStringInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return this->PrivateGetRefMember(); } 
	if (o_->AppendInt(v) == nullptr) this->ResetReference();
	return this->PrivateGetRefMember();
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CStringInterface::Hxx1::Fn<S>::AppendUInt(UInt32 v) const -> DOXYGEN_SWITCH(maxon::RefMemberType<S const>, S)
{
	static_assert(!S::HAS_ERROR, "CStringInterface::AppendUInt can't be used on a Result object because it does not return a Result object itself."); CStringInterface* o_ = (CStringInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return this->PrivateGetRefMember(); } 
	if (o_->AppendUInt(v) == nullptr) this->ResetReference();
	return this->PrivateGetRefMember();
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CStringInterface::Hxx1::COWFn<S>::AppendUInt(UInt32 v) -> DOXYGEN_SWITCH(maxon::RefMemberType<S>, S)
{
	static_assert(!S::HAS_ERROR, "CStringInterface::AppendUInt can't be used on a Result object because it does not return a Result object itself."); CStringInterface* o_ = (CStringInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return this->PrivateGetRefMember(); } 
	if (o_->AppendUInt(v) == nullptr) this->ResetReference();
	return this->PrivateGetRefMember();
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CStringInterface::Hxx1::Fn<S>::AppendInt(Int64 v) const -> DOXYGEN_SWITCH(maxon::RefMemberType<S const>, S)
{
	static_assert(!S::HAS_ERROR, "CStringInterface::AppendInt can't be used on a Result object because it does not return a Result object itself."); CStringInterface* o_ = (CStringInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return this->PrivateGetRefMember(); } 
	if (o_->AppendInt(v) == nullptr) this->ResetReference();
	return this->PrivateGetRefMember();
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CStringInterface::Hxx1::COWFn<S>::AppendInt(Int64 v) -> DOXYGEN_SWITCH(maxon::RefMemberType<S>, S)
{
	static_assert(!S::HAS_ERROR, "CStringInterface::AppendInt can't be used on a Result object because it does not return a Result object itself."); CStringInterface* o_ = (CStringInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return this->PrivateGetRefMember(); } 
	if (o_->AppendInt(v) == nullptr) this->ResetReference();
	return this->PrivateGetRefMember();
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CStringInterface::Hxx1::Fn<S>::AppendUInt(UInt64 v) const -> DOXYGEN_SWITCH(maxon::RefMemberType<S const>, S)
{
	static_assert(!S::HAS_ERROR, "CStringInterface::AppendUInt can't be used on a Result object because it does not return a Result object itself."); CStringInterface* o_ = (CStringInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return this->PrivateGetRefMember(); } 
	if (o_->AppendUInt(v) == nullptr) this->ResetReference();
	return this->PrivateGetRefMember();
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CStringInterface::Hxx1::COWFn<S>::AppendUInt(UInt64 v) -> DOXYGEN_SWITCH(maxon::RefMemberType<S>, S)
{
	static_assert(!S::HAS_ERROR, "CStringInterface::AppendUInt can't be used on a Result object because it does not return a Result object itself."); CStringInterface* o_ = (CStringInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return this->PrivateGetRefMember(); } 
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
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const CStringInterface* o_ = (const CStringInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = CStringInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (MTable::_instance.CStringInterface_GetUtf32(o_, stringData));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CStringInterface::Hxx1::Fn<S>::TrimLeft() const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); CStringInterface* o_ = (CStringInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (MTable::_instance.CStringInterface_TrimLeft(o_));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CStringInterface::Hxx1::COWFn<S>::TrimLeft() -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); CStringInterface* o_ = (CStringInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } 
	return (MTable::_instance.CStringInterface_TrimLeft(o_));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CStringInterface::Hxx1::Fn<S>::TrimRight() const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); CStringInterface* o_ = (CStringInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (MTable::_instance.CStringInterface_TrimRight(o_));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CStringInterface::Hxx1::COWFn<S>::TrimRight() -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); CStringInterface* o_ = (CStringInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } 
	return (MTable::_instance.CStringInterface_TrimRight(o_));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CStringInterface::Hxx1::ConstFn<S>::Split(const CString& splitSymbol, Bool trim, const ValueReceiver<const CString&>& parts) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const CStringInterface* o_ = (const CStringInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = CStringInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (MTable::_instance.CStringInterface_Split(o_, splitSymbol, trim, parts));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CStringInterface::Hxx1::Fn<S>::Replace(Char find, Char replace) const -> Result<Int>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<Int>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); CStringInterface* o_ = (CStringInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (MTable::_instance.CStringInterface_Replace(o_, find, replace));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CStringInterface::Hxx1::COWFn<S>::Replace(Char find, Char replace) -> Result<Int>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<Int>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); CStringInterface* o_ = (CStringInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } 
	return (MTable::_instance.CStringInterface_Replace(o_, find, replace));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CStringInterface::Hxx1::Fn<S>::Replace(const CString& find, const CString& replace) const -> Result<Int>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<Int>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); CStringInterface* o_ = (CStringInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (MTable::_instance.CStringInterface_Replace_1(o_, find, replace));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CStringInterface::Hxx1::COWFn<S>::Replace(const CString& find, const CString& replace) -> Result<Int>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<Int>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); CStringInterface* o_ = (CStringInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } 
	return (MTable::_instance.CStringInterface_Replace_1(o_, find, replace));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CStringInterface::Hxx1::Fn<S>::Replace(Char find, const CString& replace) const -> Result<Int>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<Int>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); CStringInterface* o_ = (CStringInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (MTable::_instance.CStringInterface_Replace_2(o_, find, replace));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CStringInterface::Hxx1::COWFn<S>::Replace(Char find, const CString& replace) -> Result<Int>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<Int>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); CStringInterface* o_ = (CStringInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } 
	return (MTable::_instance.CStringInterface_Replace_2(o_, find, replace));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CStringInterface::Hxx1::ConstFn<S>::Find(const CString& str, Int* pos, StringPosition start) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const CStringInterface* o_ = (const CStringInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = CStringInterface::NullValuePtr(); if (!o_) return maxon::PrivateLogNullptrError(false); } 
	return (o_->Find(str, pos, std::forward<StringPosition>(start)));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CStringInterface::Hxx1::ConstFn<S>::FindLast(const CString& str, Int* pos, StringPosition start) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const CStringInterface* o_ = (const CStringInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = CStringInterface::NullValuePtr(); if (!o_) return maxon::PrivateLogNullptrError(false); } 
	return (o_->FindLast(str, pos, std::forward<StringPosition>(start)));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CStringInterface::Hxx1::ConstFn<S>::Find(Char ch, Int* pos, StringPosition start) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const CStringInterface* o_ = (const CStringInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = CStringInterface::NullValuePtr(); if (!o_) return maxon::PrivateLogNullptrError(false); } 
	return (o_->Find(ch, pos, std::forward<StringPosition>(start)));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CStringInterface::Hxx1::ConstFn<S>::FindLast(Char ch, Int* pos, StringPosition start) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const CStringInterface* o_ = (const CStringInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = CStringInterface::NullValuePtr(); if (!o_) return maxon::PrivateLogNullptrError(false); } 
	return (o_->FindLast(ch, pos, std::forward<StringPosition>(start)));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CStringInterface::Hxx1::ConstFn<S>::FindUpper(const CString& str, Int* pos, StringPosition start) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const CStringInterface* o_ = (const CStringInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = CStringInterface::NullValuePtr(); if (!o_) return maxon::PrivateLogNullptrError(false); } 
	return (o_->FindUpper(str, pos, std::forward<StringPosition>(start)));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CStringInterface::Hxx1::ConstFn<S>::FindLastUpper(const CString& str, Int* pos, StringPosition start) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const CStringInterface* o_ = (const CStringInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = CStringInterface::NullValuePtr(); if (!o_) return maxon::PrivateLogNullptrError(false); } 
	return (o_->FindLastUpper(str, pos, std::forward<StringPosition>(start)));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CStringInterface::Hxx1::ConstFn<S>::GetLeftPart(StringPosition start) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<CString>, CString>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<CString>, CString>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const CStringInterface* o_ = (const CStringInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = CStringInterface::NullValuePtr(); if (!o_) return CString::NullValue(); } 
	return CString(o_->GetLeftPart(std::forward<StringPosition>(start)));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CStringInterface::Hxx1::ConstFn<S>::GetRightPart(StringPosition start) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<CString>, CString>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<CString>, CString>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const CStringInterface* o_ = (const CStringInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = CStringInterface::NullValuePtr(); if (!o_) return CString::NullValue(); } 
	return CString(o_->GetRightPart(std::forward<StringPosition>(start)));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CStringInterface::Hxx1::ConstFn<S>::StartsWith(Char ch) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const CStringInterface* o_ = (const CStringInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = CStringInterface::NullValuePtr(); if (!o_) return maxon::PrivateLogNullptrError(false); } 
	return (o_->StartsWith(ch));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CStringInterface::Hxx1::ConstFn<S>::StartsWith(const CString& str) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const CStringInterface* o_ = (const CStringInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = CStringInterface::NullValuePtr(); if (!o_) return maxon::PrivateLogNullptrError(false); } 
	return (o_->StartsWith(str));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CStringInterface::Hxx1::ConstFn<S>::EndsWith(Char ch) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const CStringInterface* o_ = (const CStringInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = CStringInterface::NullValuePtr(); if (!o_) return maxon::PrivateLogNullptrError(false); } 
	return (o_->EndsWith(ch));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CStringInterface::Hxx1::ConstFn<S>::EndsWith(const CString& str) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const CStringInterface* o_ = (const CStringInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = CStringInterface::NullValuePtr(); if (!o_) return maxon::PrivateLogNullptrError(false); } 
	return (o_->EndsWith(str));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CStringInterface::Hxx1::Fn<S>::Trim() const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); CStringInterface* o_ = (CStringInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (o_->Trim());
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CStringInterface::Hxx1::COWFn<S>::Trim() -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); CStringInterface* o_ = (CStringInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } 
	return (o_->Trim());
}
auto CStringInterface::Reference::Create() -> maxon::ResultMemT<CString>
{
	CStringInterface* res_ = CStringInterface::Alloc(MAXON_SOURCE_LOCATION);
	return CString(maxon::ForwardResultPtr<CStringInterface>(res_));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CStringInterface::Hxx1::ConstFn<S>::GetCStringBlock(const Block<Char>& buffer) const -> Result<Int>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<Int>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const CStringInterface* o_ = (const CStringInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = CStringInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (MTable::_instance.CStringInterface_GetCStringBlock(o_, buffer));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CStringInterface::Hxx1::ConstFn<S>::GetCStringAppendArray(const NonConstArray<Char>& array) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const CStringInterface* o_ = (const CStringInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = CStringInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (MTable::_instance.CStringInterface_GetCStringAppendArray(o_, array));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CStringInterface::Hxx1::Fn<S>::SetCString(const Char* buffer, Int count) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); CStringInterface* o_ = (CStringInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (MTable::_instance.CStringInterface_SetCString(o_, buffer, count));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CStringInterface::Hxx1::COWFn<S>::SetCString(const Char* buffer, Int count) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); CStringInterface* o_ = (CStringInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } 
	return (MTable::_instance.CStringInterface_SetCString(o_, buffer, count));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CStringInterface::Hxx1::Fn<S>::SetCString(const Block<const Char>& buffer) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); CStringInterface* o_ = (CStringInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (o_->SetCString(buffer));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CStringInterface::Hxx1::COWFn<S>::SetCString(const Block<const Char>& buffer) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); CStringInterface* o_ = (CStringInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } 
	return (o_->SetCString(buffer));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CStringInterface::Hxx1::ConstFn<S>::GetCString() const -> Result<BaseArray<Char>>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<BaseArray<Char>>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const CStringInterface* o_ = (const CStringInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = CStringInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (MTable::_instance.CStringInterface_GetCString(o_));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CStringInterface::Hxx1::ConstFn<S>::GetInternalData() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Block<const Char>>, Block<const Char>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Block<const Char>>, Block<const Char>>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const CStringInterface* o_ = (const CStringInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = CStringInterface::NullValuePtr(); if (!o_) return maxon::PrivateIncompleteNullReturnValue<Block<const Char>>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } 
	return (MTable::_instance.CStringInterface_GetInternalData(o_));
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

