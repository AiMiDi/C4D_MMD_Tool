
#ifndef DOXYGEN

#ifdef MAXON_COMPILER_GCC
	#pragma GCC diagnostic push
	#pragma GCC diagnostic ignored "-Wmisleading-indentation"
#endif

#if 1

struct StringInterface::MTable
{
	static MTable _instance;
	static MTable _unresolvedInstance;
	static const maxon::Char* const _ids;
	static maxon::Bool InitUnresolved(maxon::NonvirtualInterfaceReference::UnresolvedAssembler assembler, MTable* tbl);
	static const maxon::NULL_RETURN_TYPE _returnTypes[];
	static const maxon::Bool HAS_NONSTATIC = true;
	void (*_StringInterface_Free) (const StringInterface* object);
	Int (*_StringInterface_GetLength) (const StringInterface* this_);
	Result<void> (*_StringInterface_Init) (StringInterface* this_, Int count, Utf32Char fillChar);
	Result<void> (*_StringInterface_Shrink) (StringInterface* this_);
	StringInterface* (*_StringInterface_Append) (StringInterface* this_, const StringInterface* str);
	StringInterface* (*_StringInterface_Append_1) (StringInterface* this_, const Utf32Char* str, Int len);
	Int (*_StringInterface_FindIndex) (const StringInterface* this_, const StringInterface* str, StringPosition start);
	Int (*_StringInterface_FindLastIndex) (const StringInterface* this_, const StringInterface* str, StringPosition start);
	Int (*_StringInterface_FindIndex_1) (const StringInterface* this_, Utf32Char ch, StringPosition start);
	Int (*_StringInterface_FindLastIndex_1) (const StringInterface* this_, Utf32Char ch, StringPosition start);
	Int (*_StringInterface_FindUpperIndex) (const StringInterface* this_, const StringInterface* str, StringPosition start);
	Int (*_StringInterface_FindLastUpperIndex) (const StringInterface* this_, const StringInterface* str, StringPosition start);
	Result<void> (*_StringInterface_Erase) (StringInterface* this_, StringPosition position, StringCount count);
	Result<void> (*_StringInterface_Insert) (StringInterface* this_, StringPosition position, const StringInterface* str, StringPosition strStart, StringCount strCount);
	Result<void> (*_StringInterface_Insert_1) (StringInterface* this_, StringPosition position, Utf32Char ch);
	StringInterface* (*_StringInterface_GetPart) (const StringInterface* this_, StringPosition start, StringCount count);
	StringInterface* (*_StringInterface_ToUpper) (const StringInterface* this_);
	StringInterface* (*_StringInterface_ToLower) (const StringInterface* this_);
	COMPARERESULT (*_StringInterface_ComparePart) (const StringInterface* this_, const StringInterface* str, STRINGCOMPARISON mode, StringPosition position, StringCount count);
	UInt (*_StringInterface_GetHashCode) (const StringInterface* this_);
	void (*_StringInterface_SetChar) (StringInterface* this_, Int pos, Utf32Char ch);
	Utf32Char (*_StringInterface_GetChar) (const StringInterface* this_, Int pos);
	Result<void> (*_StringInterface_GetUtf32) (const StringInterface* this_, Utf32CharBuffer& stringData);
	Result<void> (*_StringInterface_TrimLeft) (StringInterface* this_);
	Result<void> (*_StringInterface_TrimRight) (StringInterface* this_);
	Result<void> (*_StringInterface_Split) (const StringInterface* this_, const String& splitSymbol, Bool trim, BaseArray<String>& parts);
	Result<Int> (*_StringInterface_Replace) (StringInterface* this_, Utf32Char find, Utf32Char replace);
	Result<Int> (*_StringInterface_Replace_1) (StringInterface* this_, const String& find, const String& replace);
	Result<Int> (*_StringInterface_Replace_2) (StringInterface* this_, Utf32Char find, const String& replace);
	StringInterface* (*_StringInterface_Alloc) (const maxon::SourceLocation& allocLocation);
	StringInterface* (*_StringInterface_Alloc_1) (const maxon::SourceLocation& allocLocation, const StringInterface& object);
	Result<Int> (*_StringInterface_GetCStringBlock) (const StringInterface* this_, const Block<Char>& buffer, const StringEncodingRef& stringEncoding);
	Result<void> (*_StringInterface_GetCStringAppendArray) (const StringInterface* this_, const NonConstArray<Char>& array, const StringEncodingRef& stringEncoding);
	Result<BaseArray<Char>> (*_StringInterface_GetCString) (const StringInterface* this_, const StringEncodingRef& stringEncoding);
	Result<void> (*_StringInterface_SetCString) (StringInterface* this_, const Char* buffer, Int count, const StringDecodingRef& stringDecoding);
	Result<SysCharArray> (*_StringInterface_GetSystemEncoding) (const StringInterface* this_);
	Result<void> (*_StringInterface_SetSystemEncoding) (StringInterface* this_, const SysChar* buffer, Int count);
	Result<void> (*_StringInterface_SetUtf32) (StringInterface* this_, const Utf32Char* buffer, Int count);
	Result<void> (*_StringInterface_GetUtf16) (const StringInterface* this_, Utf16CharBuffer& stringData);
	Result<void> (*_StringInterface_SetUtf16) (StringInterface* this_, const Utf16Char* buffer, Int count);
	const String& (*_StringInterface_GetAndCacheConstString) (const wchar_t* chr, Int len);
	const String& (*_StringInterface_GetAndCacheConstString_1) (const Char* chr, Int len, Int isUtf8);
	String (*_StringInterface_PrivateEnumToString) (UInt64 value, const Char* enumName, Int size, Bool flags, const UInt64* enumValues, const Char* enumValueNames, const FormatStatement* formatStatement);
	StridedBlock<const Generic> (*_StringInterface_GetVariableInternalData) (const StringInterface* this_);
	Int (*_StringInterface_GetCharacterWidth) (const StringInterface* this_);
	template <typename IMPL> static void Init(MTable* tbl)
	{
		tbl->_StringInterface_Free = &IMPL::_StringInterface_Free;
		tbl->_StringInterface_GetLength = &IMPL::_StringInterface_GetLength;
		tbl->_StringInterface_Init = &IMPL::_StringInterface_Init;
		tbl->_StringInterface_Shrink = &IMPL::_StringInterface_Shrink;
		tbl->_StringInterface_Append = &IMPL::_StringInterface_Append;
		tbl->_StringInterface_Append_1 = &IMPL::_StringInterface_Append_1;
		tbl->_StringInterface_FindIndex = &IMPL::_StringInterface_FindIndex;
		tbl->_StringInterface_FindLastIndex = &IMPL::_StringInterface_FindLastIndex;
		tbl->_StringInterface_FindIndex_1 = &IMPL::_StringInterface_FindIndex_1;
		tbl->_StringInterface_FindLastIndex_1 = &IMPL::_StringInterface_FindLastIndex_1;
		tbl->_StringInterface_FindUpperIndex = &IMPL::_StringInterface_FindUpperIndex;
		tbl->_StringInterface_FindLastUpperIndex = &IMPL::_StringInterface_FindLastUpperIndex;
		tbl->_StringInterface_Erase = &IMPL::_StringInterface_Erase;
		tbl->_StringInterface_Insert = &IMPL::_StringInterface_Insert;
		tbl->_StringInterface_Insert_1 = &IMPL::_StringInterface_Insert_1;
		tbl->_StringInterface_GetPart = &IMPL::_StringInterface_GetPart;
		tbl->_StringInterface_ToUpper = &IMPL::_StringInterface_ToUpper;
		tbl->_StringInterface_ToLower = &IMPL::_StringInterface_ToLower;
		tbl->_StringInterface_ComparePart = &IMPL::_StringInterface_ComparePart;
		tbl->_StringInterface_GetHashCode = &IMPL::_StringInterface_GetHashCode;
		tbl->_StringInterface_SetChar = &IMPL::_StringInterface_SetChar;
		tbl->_StringInterface_GetChar = &IMPL::_StringInterface_GetChar;
		tbl->_StringInterface_GetUtf32 = &IMPL::_StringInterface_GetUtf32;
		tbl->_StringInterface_TrimLeft = &IMPL::_StringInterface_TrimLeft;
		tbl->_StringInterface_TrimRight = &IMPL::_StringInterface_TrimRight;
		tbl->_StringInterface_Split = &IMPL::_StringInterface_Split;
		tbl->_StringInterface_Replace = &IMPL::_StringInterface_Replace;
		tbl->_StringInterface_Replace_1 = &IMPL::_StringInterface_Replace_1;
		tbl->_StringInterface_Replace_2 = &IMPL::_StringInterface_Replace_2;
		tbl->_StringInterface_Alloc = &IMPL::_StringInterface_Alloc;
		tbl->_StringInterface_Alloc_1 = &IMPL::_StringInterface_Alloc_1;
		tbl->_StringInterface_GetCStringBlock = &IMPL::_StringInterface_GetCStringBlock;
		tbl->_StringInterface_GetCStringAppendArray = &IMPL::_StringInterface_GetCStringAppendArray;
		tbl->_StringInterface_GetCString = &IMPL::_StringInterface_GetCString;
		tbl->_StringInterface_SetCString = &IMPL::_StringInterface_SetCString;
		tbl->_StringInterface_GetSystemEncoding = &IMPL::_StringInterface_GetSystemEncoding;
		tbl->_StringInterface_SetSystemEncoding = &IMPL::_StringInterface_SetSystemEncoding;
		tbl->_StringInterface_SetUtf32 = &IMPL::_StringInterface_SetUtf32;
		tbl->_StringInterface_GetUtf16 = &IMPL::_StringInterface_GetUtf16;
		tbl->_StringInterface_SetUtf16 = &IMPL::_StringInterface_SetUtf16;
		tbl->_StringInterface_GetAndCacheConstString = &IMPL::_StringInterface_GetAndCacheConstString;
		tbl->_StringInterface_GetAndCacheConstString_1 = &IMPL::_StringInterface_GetAndCacheConstString_1;
		tbl->_StringInterface_PrivateEnumToString = &IMPL::_StringInterface_PrivateEnumToString;
		tbl->_StringInterface_GetVariableInternalData = &IMPL::_StringInterface_GetVariableInternalData;
		tbl->_StringInterface_GetCharacterWidth = &IMPL::_StringInterface_GetCharacterWidth;
	}
};

template <typename C> class StringInterface::Wrapper
{
public:
	static void _StringInterface_Free(const StringInterface* object) { return C::Free(object); }
	static Int _StringInterface_GetLength(const StringInterface* this_) { return ((const C*) this_)->GetLength(); }
	static Result<void> _StringInterface_Init(StringInterface* this_, Int count, Utf32Char fillChar) { return ((C*) this_)->Init(count, fillChar); }
	static Result<void> _StringInterface_Shrink(StringInterface* this_) { return ((C*) this_)->Shrink(); }
	static StringInterface* _StringInterface_Append(StringInterface* this_, const StringInterface* str) { return ((C*) this_)->Append(str); }
	static StringInterface* _StringInterface_Append_1(StringInterface* this_, const Utf32Char* str, Int len) { return ((C*) this_)->Append(str, len); }
	static Int _StringInterface_FindIndex(const StringInterface* this_, const StringInterface* str, StringPosition start) { return ((const C*) this_)->FindIndex(str, std::forward<StringPosition>(start)); }
	static Int _StringInterface_FindLastIndex(const StringInterface* this_, const StringInterface* str, StringPosition start) { return ((const C*) this_)->FindLastIndex(str, std::forward<StringPosition>(start)); }
	static Int _StringInterface_FindIndex_1(const StringInterface* this_, Utf32Char ch, StringPosition start) { return ((const C*) this_)->FindIndex(ch, std::forward<StringPosition>(start)); }
	static Int _StringInterface_FindLastIndex_1(const StringInterface* this_, Utf32Char ch, StringPosition start) { return ((const C*) this_)->FindLastIndex(ch, std::forward<StringPosition>(start)); }
	static Int _StringInterface_FindUpperIndex(const StringInterface* this_, const StringInterface* str, StringPosition start) { return ((const C*) this_)->FindUpperIndex(str, std::forward<StringPosition>(start)); }
	static Int _StringInterface_FindLastUpperIndex(const StringInterface* this_, const StringInterface* str, StringPosition start) { return ((const C*) this_)->FindLastUpperIndex(str, std::forward<StringPosition>(start)); }
	static Result<void> _StringInterface_Erase(StringInterface* this_, StringPosition position, StringCount count) { return ((C*) this_)->Erase(std::forward<StringPosition>(position), std::forward<StringCount>(count)); }
	static Result<void> _StringInterface_Insert(StringInterface* this_, StringPosition position, const StringInterface* str, StringPosition strStart, StringCount strCount) { return ((C*) this_)->Insert(std::forward<StringPosition>(position), str, std::forward<StringPosition>(strStart), std::forward<StringCount>(strCount)); }
	static Result<void> _StringInterface_Insert_1(StringInterface* this_, StringPosition position, Utf32Char ch) { return ((C*) this_)->Insert(std::forward<StringPosition>(position), ch); }
	static StringInterface* _StringInterface_GetPart(const StringInterface* this_, StringPosition start, StringCount count) { return ((const C*) this_)->GetPart(std::forward<StringPosition>(start), std::forward<StringCount>(count)); }
	static StringInterface* _StringInterface_ToUpper(const StringInterface* this_) { return ((const C*) this_)->ToUpper(); }
	static StringInterface* _StringInterface_ToLower(const StringInterface* this_) { return ((const C*) this_)->ToLower(); }
	static COMPARERESULT _StringInterface_ComparePart(const StringInterface* this_, const StringInterface* str, STRINGCOMPARISON mode, StringPosition position, StringCount count) { return ((const C*) this_)->ComparePart(str, mode, std::forward<StringPosition>(position), std::forward<StringCount>(count)); }
	static UInt _StringInterface_GetHashCode(const StringInterface* this_) { return ((const C*) this_)->GetHashCode(); }
	static void _StringInterface_SetChar(StringInterface* this_, Int pos, Utf32Char ch) { return ((C*) this_)->SetChar(pos, ch); }
	static Utf32Char _StringInterface_GetChar(const StringInterface* this_, Int pos) { return ((const C*) this_)->GetChar(pos); }
	static Result<void> _StringInterface_GetUtf32(const StringInterface* this_, Utf32CharBuffer& stringData) { return ((const C*) this_)->GetUtf32(stringData); }
	static Result<void> _StringInterface_TrimLeft(StringInterface* this_) { return ((C*) this_)->TrimLeft(); }
	static Result<void> _StringInterface_TrimRight(StringInterface* this_) { return ((C*) this_)->TrimRight(); }
	static Result<void> _StringInterface_Split(const StringInterface* this_, const String& splitSymbol, Bool trim, BaseArray<String>& parts) { return ((const C*) this_)->Split(splitSymbol, trim, parts); }
	static Result<Int> _StringInterface_Replace(StringInterface* this_, Utf32Char find, Utf32Char replace) { return ((C*) this_)->Replace(find, replace); }
	static Result<Int> _StringInterface_Replace_1(StringInterface* this_, const String& find, const String& replace) { return ((C*) this_)->Replace(find, replace); }
	static Result<Int> _StringInterface_Replace_2(StringInterface* this_, Utf32Char find, const String& replace) { return ((C*) this_)->Replace(find, replace); }
	static StringInterface* _StringInterface_Alloc(const maxon::SourceLocation& allocLocation) { return C::Alloc(allocLocation); }
	static StringInterface* _StringInterface_Alloc_1(const maxon::SourceLocation& allocLocation, const StringInterface& object) { return C::Alloc(allocLocation, ((const C&) object)); }
	static Result<Int> _StringInterface_GetCStringBlock(const StringInterface* this_, const Block<Char>& buffer, const StringEncodingRef& stringEncoding) { return ((const C*) this_)->GetCStringBlock(buffer, stringEncoding); }
	static Result<void> _StringInterface_GetCStringAppendArray(const StringInterface* this_, const NonConstArray<Char>& array, const StringEncodingRef& stringEncoding) { return ((const C*) this_)->GetCStringAppendArray(array, stringEncoding); }
	static Result<BaseArray<Char>> _StringInterface_GetCString(const StringInterface* this_, const StringEncodingRef& stringEncoding) { return ((const C*) this_)->GetCString(stringEncoding); }
	static Result<void> _StringInterface_SetCString(StringInterface* this_, const Char* buffer, Int count, const StringDecodingRef& stringDecoding) { return ((C*) this_)->SetCString(buffer, count, stringDecoding); }
	static Result<SysCharArray> _StringInterface_GetSystemEncoding(const StringInterface* this_) { return ((const C*) this_)->GetSystemEncoding(); }
	static Result<void> _StringInterface_SetSystemEncoding(StringInterface* this_, const SysChar* buffer, Int count) { return ((C*) this_)->SetSystemEncoding(buffer, count); }
	static Result<void> _StringInterface_SetUtf32(StringInterface* this_, const Utf32Char* buffer, Int count) { return ((C*) this_)->SetUtf32(buffer, count); }
	static Result<void> _StringInterface_GetUtf16(const StringInterface* this_, Utf16CharBuffer& stringData) { return ((const C*) this_)->GetUtf16(stringData); }
	static Result<void> _StringInterface_SetUtf16(StringInterface* this_, const Utf16Char* buffer, Int count) { return ((C*) this_)->SetUtf16(buffer, count); }
	static const String& _StringInterface_GetAndCacheConstString(const wchar_t* chr, Int len) { return C::GetAndCacheConstString(chr, len); }
	static const String& _StringInterface_GetAndCacheConstString_1(const Char* chr, Int len, Int isUtf8) { return C::GetAndCacheConstString(chr, len, isUtf8); }
	static String _StringInterface_PrivateEnumToString(UInt64 value, const Char* enumName, Int size, Bool flags, const UInt64* enumValues, const Char* enumValueNames, const FormatStatement* formatStatement) { return C::PrivateEnumToString(value, enumName, size, flags, enumValues, enumValueNames, formatStatement); }
	static StridedBlock<const Generic> _StringInterface_GetVariableInternalData(const StringInterface* this_) { return ((const C*) this_)->GetVariableInternalData(); }
	static Int _StringInterface_GetCharacterWidth(const StringInterface* this_) { return ((const C*) this_)->GetCharacterWidth(); }
};

MAXON_ATTRIBUTE_FORCE_INLINE auto StringInterface::Free(const StringInterface* object) -> void
{
	return MTable::_instance._StringInterface_Free(object);
}
template <> MAXON_ATTRIBUTE_FORCE_INLINE auto StringTemplate<StringInterface,String,Utf32Char>::GetLength() const -> Int
{
	return StringInterface::MTable::_instance._StringInterface_GetLength(static_cast<const StringInterface*>(this));
}
template <> MAXON_ATTRIBUTE_FORCE_INLINE auto StringTemplate<StringInterface,String,Utf32Char>::Init(Int count, Utf32Char fillChar) -> Result<void>
{
	return StringInterface::MTable::_instance._StringInterface_Init(static_cast<StringInterface*>(this), count, fillChar);
}
template <> MAXON_ATTRIBUTE_FORCE_INLINE auto StringTemplate<StringInterface,String,Utf32Char>::Shrink() -> Result<void>
{
	return StringInterface::MTable::_instance._StringInterface_Shrink(static_cast<StringInterface*>(this));
}
template <> MAXON_ATTRIBUTE_FORCE_INLINE auto StringTemplate<StringInterface,String,Utf32Char>::Append(const StringInterface* str) -> StringInterface*
{
	return StringInterface::MTable::_instance._StringInterface_Append(static_cast<StringInterface*>(this), str);
}
template <> MAXON_ATTRIBUTE_FORCE_INLINE auto StringTemplate<StringInterface,String,Utf32Char>::Append(const Utf32Char* str, Int len) -> StringInterface*
{
	return StringInterface::MTable::_instance._StringInterface_Append_1(static_cast<StringInterface*>(this), str, len);
}
template <> MAXON_ATTRIBUTE_FORCE_INLINE auto StringTemplate<StringInterface,String,Utf32Char>::FindIndex(const StringInterface* str, StringPosition start) const -> Int
{
	return StringInterface::MTable::_instance._StringInterface_FindIndex(static_cast<const StringInterface*>(this), str, std::forward<StringPosition>(start));
}
template <> MAXON_ATTRIBUTE_FORCE_INLINE auto StringTemplate<StringInterface,String,Utf32Char>::FindLastIndex(const StringInterface* str, StringPosition start) const -> Int
{
	return StringInterface::MTable::_instance._StringInterface_FindLastIndex(static_cast<const StringInterface*>(this), str, std::forward<StringPosition>(start));
}
template <> MAXON_ATTRIBUTE_FORCE_INLINE auto StringTemplate<StringInterface,String,Utf32Char>::FindIndex(Utf32Char ch, StringPosition start) const -> Int
{
	return StringInterface::MTable::_instance._StringInterface_FindIndex_1(static_cast<const StringInterface*>(this), ch, std::forward<StringPosition>(start));
}
template <> MAXON_ATTRIBUTE_FORCE_INLINE auto StringTemplate<StringInterface,String,Utf32Char>::FindLastIndex(Utf32Char ch, StringPosition start) const -> Int
{
	return StringInterface::MTable::_instance._StringInterface_FindLastIndex_1(static_cast<const StringInterface*>(this), ch, std::forward<StringPosition>(start));
}
template <> MAXON_ATTRIBUTE_FORCE_INLINE auto StringTemplate<StringInterface,String,Utf32Char>::FindUpperIndex(const StringInterface* str, StringPosition start) const -> Int
{
	return StringInterface::MTable::_instance._StringInterface_FindUpperIndex(static_cast<const StringInterface*>(this), str, std::forward<StringPosition>(start));
}
template <> MAXON_ATTRIBUTE_FORCE_INLINE auto StringTemplate<StringInterface,String,Utf32Char>::FindLastUpperIndex(const StringInterface* str, StringPosition start) const -> Int
{
	return StringInterface::MTable::_instance._StringInterface_FindLastUpperIndex(static_cast<const StringInterface*>(this), str, std::forward<StringPosition>(start));
}
template <> MAXON_ATTRIBUTE_FORCE_INLINE auto StringTemplate<StringInterface,String,Utf32Char>::Erase(StringPosition position, StringCount count) -> Result<void>
{
	return StringInterface::MTable::_instance._StringInterface_Erase(static_cast<StringInterface*>(this), std::forward<StringPosition>(position), std::forward<StringCount>(count));
}
template <> MAXON_ATTRIBUTE_FORCE_INLINE auto StringTemplate<StringInterface,String,Utf32Char>::Insert(StringPosition position, const StringInterface* str, StringPosition strStart, StringCount strCount) -> Result<void>
{
	return StringInterface::MTable::_instance._StringInterface_Insert(static_cast<StringInterface*>(this), std::forward<StringPosition>(position), str, std::forward<StringPosition>(strStart), std::forward<StringCount>(strCount));
}
template <> MAXON_ATTRIBUTE_FORCE_INLINE auto StringTemplate<StringInterface,String,Utf32Char>::Insert(StringPosition position, Utf32Char ch) -> Result<void>
{
	return StringInterface::MTable::_instance._StringInterface_Insert_1(static_cast<StringInterface*>(this), std::forward<StringPosition>(position), ch);
}
template <> MAXON_ATTRIBUTE_FORCE_INLINE auto StringTemplate<StringInterface,String,Utf32Char>::GetPart(StringPosition start, StringCount count) const -> StringInterface*
{
	return StringInterface::MTable::_instance._StringInterface_GetPart(static_cast<const StringInterface*>(this), std::forward<StringPosition>(start), std::forward<StringCount>(count));
}
template <> MAXON_ATTRIBUTE_FORCE_INLINE auto StringTemplate<StringInterface,String,Utf32Char>::ToUpper() const -> StringInterface*
{
	return StringInterface::MTable::_instance._StringInterface_ToUpper(static_cast<const StringInterface*>(this));
}
template <> MAXON_ATTRIBUTE_FORCE_INLINE auto StringTemplate<StringInterface,String,Utf32Char>::ToLower() const -> StringInterface*
{
	return StringInterface::MTable::_instance._StringInterface_ToLower(static_cast<const StringInterface*>(this));
}
template <> MAXON_ATTRIBUTE_FORCE_INLINE auto StringTemplate<StringInterface,String,Utf32Char>::ComparePart(const StringInterface* str, STRINGCOMPARISON mode, StringPosition position, StringCount count) const -> COMPARERESULT
{
	return StringInterface::MTable::_instance._StringInterface_ComparePart(static_cast<const StringInterface*>(this), str, mode, std::forward<StringPosition>(position), std::forward<StringCount>(count));
}
template <> MAXON_ATTRIBUTE_FORCE_INLINE auto StringTemplate<StringInterface,String,Utf32Char>::GetHashCode() const -> UInt
{
	return StringInterface::MTable::_instance._StringInterface_GetHashCode(static_cast<const StringInterface*>(this));
}
template <> MAXON_ATTRIBUTE_FORCE_INLINE auto StringTemplate<StringInterface,String,Utf32Char>::SetChar(Int pos, Utf32Char ch) -> void
{
	return StringInterface::MTable::_instance._StringInterface_SetChar(static_cast<StringInterface*>(this), pos, ch);
}
template <> MAXON_ATTRIBUTE_FORCE_INLINE auto StringTemplate<StringInterface,String,Utf32Char>::GetChar(Int pos) const -> Utf32Char
{
	return StringInterface::MTable::_instance._StringInterface_GetChar(static_cast<const StringInterface*>(this), pos);
}
template <> MAXON_ATTRIBUTE_FORCE_INLINE auto StringTemplate<StringInterface,String,Utf32Char>::GetUtf32(Utf32CharBuffer& stringData) const -> Result<void>
{
	return StringInterface::MTable::_instance._StringInterface_GetUtf32(static_cast<const StringInterface*>(this), stringData);
}
template <> MAXON_ATTRIBUTE_FORCE_INLINE auto StringTemplate<StringInterface,String,Utf32Char>::TrimLeft() -> Result<void>
{
	return StringInterface::MTable::_instance._StringInterface_TrimLeft(static_cast<StringInterface*>(this));
}
template <> MAXON_ATTRIBUTE_FORCE_INLINE auto StringTemplate<StringInterface,String,Utf32Char>::TrimRight() -> Result<void>
{
	return StringInterface::MTable::_instance._StringInterface_TrimRight(static_cast<StringInterface*>(this));
}
template <> MAXON_ATTRIBUTE_FORCE_INLINE auto StringTemplate<StringInterface,String,Utf32Char>::Split(const String& splitSymbol, Bool trim, BaseArray<String>& parts) const -> Result<void>
{
	return StringInterface::MTable::_instance._StringInterface_Split(static_cast<const StringInterface*>(this), splitSymbol, trim, parts);
}
template <> MAXON_ATTRIBUTE_FORCE_INLINE auto StringTemplate<StringInterface,String,Utf32Char>::Replace(Utf32Char find, Utf32Char replace) -> Result<Int>
{
	return StringInterface::MTable::_instance._StringInterface_Replace(static_cast<StringInterface*>(this), find, replace);
}
template <> MAXON_ATTRIBUTE_FORCE_INLINE auto StringTemplate<StringInterface,String,Utf32Char>::Replace(const String& find, const String& replace) -> Result<Int>
{
	return StringInterface::MTable::_instance._StringInterface_Replace_1(static_cast<StringInterface*>(this), find, replace);
}
template <> MAXON_ATTRIBUTE_FORCE_INLINE auto StringTemplate<StringInterface,String,Utf32Char>::Replace(Utf32Char find, const String& replace) -> Result<Int>
{
	return StringInterface::MTable::_instance._StringInterface_Replace_2(static_cast<StringInterface*>(this), find, replace);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto StringInterface::Alloc(const maxon::SourceLocation& allocLocation) -> StringInterface*
{
	return MTable::_instance._StringInterface_Alloc(allocLocation);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto StringInterface::Alloc(const maxon::SourceLocation& allocLocation, const StringInterface& object) -> StringInterface*
{
	return MTable::_instance._StringInterface_Alloc_1(allocLocation, object);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto StringInterface::GetCStringBlock(const Block<Char>& buffer, const StringEncodingRef& stringEncoding) const -> Result<Int>
{
	return MTable::_instance._StringInterface_GetCStringBlock(this, buffer, stringEncoding);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto StringInterface::GetCStringAppendArray(const NonConstArray<Char>& array, const StringEncodingRef& stringEncoding) const -> Result<void>
{
	return MTable::_instance._StringInterface_GetCStringAppendArray(this, array, stringEncoding);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto StringInterface::GetCString(const StringEncodingRef& stringEncoding) const -> Result<BaseArray<Char>>
{
	return MTable::_instance._StringInterface_GetCString(this, stringEncoding);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto StringInterface::SetCString(const Char* buffer, Int count, const StringDecodingRef& stringDecoding) -> Result<void>
{
	return MTable::_instance._StringInterface_SetCString(this, buffer, count, stringDecoding);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto StringInterface::GetSystemEncoding() const -> Result<SysCharArray>
{
	return MTable::_instance._StringInterface_GetSystemEncoding(this);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto StringInterface::SetSystemEncoding(const SysChar* buffer, Int count) -> Result<void>
{
	return MTable::_instance._StringInterface_SetSystemEncoding(this, buffer, count);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto StringInterface::SetUtf32(const Utf32Char* buffer, Int count) -> Result<void>
{
	return MTable::_instance._StringInterface_SetUtf32(this, buffer, count);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto StringInterface::GetUtf16(Utf16CharBuffer& stringData) const -> Result<void>
{
	return MTable::_instance._StringInterface_GetUtf16(this, stringData);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto StringInterface::SetUtf16(const Utf16Char* buffer, Int count) -> Result<void>
{
	return MTable::_instance._StringInterface_SetUtf16(this, buffer, count);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto StringInterface::GetAndCacheConstString(const wchar_t* chr, Int len) -> const String&
{
	return MTable::_instance._StringInterface_GetAndCacheConstString(chr, len);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto StringInterface::GetAndCacheConstString(const Char* chr, Int len, Int isUtf8) -> const String&
{
	return MTable::_instance._StringInterface_GetAndCacheConstString_1(chr, len, isUtf8);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto StringInterface::PrivateEnumToString(UInt64 value, const Char* enumName, Int size, Bool flags, const UInt64* enumValues, const Char* enumValueNames, const FormatStatement* formatStatement) -> String
{
	return MTable::_instance._StringInterface_PrivateEnumToString(value, enumName, size, flags, enumValues, enumValueNames, formatStatement);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto StringInterface::GetVariableInternalData() const -> StridedBlock<const Generic>
{
	return MTable::_instance._StringInterface_GetVariableInternalData(this);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto StringInterface::GetCharacterWidth() const -> Int
{
	return MTable::_instance._StringInterface_GetCharacterWidth(this);
}

template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto StringInterface::ConstReferenceFunctionsImpl<S>::GetLength() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, false, typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const StringInterface* o_ = (const StringInterface*) this->GetPointer(); if (!(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS) && MAXON_UNLIKELY(!o_)) { o_ = StringInterface::NullValuePtr(); if (!o_) return 0; } 
	return (MTable::_instance._StringInterface_GetLength(o_));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto StringInterface::ReferenceFunctionsImpl<S>::Init(Int count, Utf32Char fillChar) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); StringInterface* o_ = (StringInterface*) this->GetPointer(); if (MAXON_UNLIKELY(!o_)) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); 
	return (MTable::_instance._StringInterface_Init(o_, count, fillChar));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto StringInterface::COWReferenceFunctionsImpl<S>::Init(Int count, Utf32Char fillChar) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); StringInterface* o_ = (StringInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS) && MAXON_UNLIKELY(!o_)) return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); 
	return (MTable::_instance._StringInterface_Init(o_, count, fillChar));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto StringInterface::ReferenceFunctionsImpl<S>::Shrink() const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); StringInterface* o_ = (StringInterface*) this->GetPointer(); if (MAXON_UNLIKELY(!o_)) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); 
	return (MTable::_instance._StringInterface_Shrink(o_));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto StringInterface::COWReferenceFunctionsImpl<S>::Shrink() -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); StringInterface* o_ = (StringInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS) && MAXON_UNLIKELY(!o_)) return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); 
	return (MTable::_instance._StringInterface_Shrink(o_));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto StringInterface::ReferenceFunctionsImpl<S>::Append(const StringInterface* str) const -> DOXYGEN_SWITCH(maxon::RefMemberType<S const>, S)
{
	static_assert(!S::HAS_ERROR, "StringInterface::Append can't be used on a Result object because it does not return a Result object itself."); StringInterface* o_ = (StringInterface*) this->GetPointer(); if (MAXON_UNLIKELY(!o_)) return this->PrivateGetRefMember(); 
	if (MTable::_instance._StringInterface_Append(o_, str) == nullptr) this->ResetPointer();
	return this->PrivateGetRefMember();
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto StringInterface::COWReferenceFunctionsImpl<S>::Append(const StringInterface* str) -> DOXYGEN_SWITCH(maxon::RefMemberType<S>, S)
{
	static_assert(!S::HAS_ERROR, "StringInterface::Append can't be used on a Result object because it does not return a Result object itself."); StringInterface* o_ = (StringInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS) && MAXON_UNLIKELY(!o_)) return this->PrivateGetRefMember(); 
	if (MTable::_instance._StringInterface_Append(o_, str) == nullptr) this->ResetPointer();
	return this->PrivateGetRefMember();
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto StringInterface::ReferenceFunctionsImpl<S>::Append(const Utf32Char* str, Int len) const -> DOXYGEN_SWITCH(maxon::RefMemberType<S const>, S)
{
	static_assert(!S::HAS_ERROR, "StringInterface::Append can't be used on a Result object because it does not return a Result object itself."); StringInterface* o_ = (StringInterface*) this->GetPointer(); if (MAXON_UNLIKELY(!o_)) return this->PrivateGetRefMember(); 
	if (MTable::_instance._StringInterface_Append_1(o_, str, len) == nullptr) this->ResetPointer();
	return this->PrivateGetRefMember();
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto StringInterface::COWReferenceFunctionsImpl<S>::Append(const Utf32Char* str, Int len) -> DOXYGEN_SWITCH(maxon::RefMemberType<S>, S)
{
	static_assert(!S::HAS_ERROR, "StringInterface::Append can't be used on a Result object because it does not return a Result object itself."); StringInterface* o_ = (StringInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS) && MAXON_UNLIKELY(!o_)) return this->PrivateGetRefMember(); 
	if (MTable::_instance._StringInterface_Append_1(o_, str, len) == nullptr) this->ResetPointer();
	return this->PrivateGetRefMember();
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto StringInterface::ReferenceFunctionsImpl<S>::AppendChar(Utf32Char v) const -> DOXYGEN_SWITCH(maxon::RefMemberType<S const>, S)
{
	static_assert(!S::HAS_ERROR, "StringInterface::AppendChar can't be used on a Result object because it does not return a Result object itself."); StringInterface* o_ = (StringInterface*) this->GetPointer(); if (MAXON_UNLIKELY(!o_)) return this->PrivateGetRefMember(); 
	if (o_->AppendChar(v) == nullptr) this->ResetPointer();
	return this->PrivateGetRefMember();
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto StringInterface::COWReferenceFunctionsImpl<S>::AppendChar(Utf32Char v) -> DOXYGEN_SWITCH(maxon::RefMemberType<S>, S)
{
	static_assert(!S::HAS_ERROR, "StringInterface::AppendChar can't be used on a Result object because it does not return a Result object itself."); StringInterface* o_ = (StringInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS) && MAXON_UNLIKELY(!o_)) return this->PrivateGetRefMember(); 
	if (o_->AppendChar(v) == nullptr) this->ResetPointer();
	return this->PrivateGetRefMember();
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto StringInterface::ConstReferenceFunctionsImpl<S>::FindIndex(const StringInterface* str, StringPosition start) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, false, typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const StringInterface* o_ = (const StringInterface*) this->GetPointer(); if (!(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS) && MAXON_UNLIKELY(!o_)) { o_ = StringInterface::NullValuePtr(); if (!o_) return InvalidArrayIndex; } 
	return (MTable::_instance._StringInterface_FindIndex(o_, str, std::forward<StringPosition>(start)));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto StringInterface::ConstReferenceFunctionsImpl<S>::FindLastIndex(const StringInterface* str, StringPosition start) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, false, typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const StringInterface* o_ = (const StringInterface*) this->GetPointer(); if (!(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS) && MAXON_UNLIKELY(!o_)) { o_ = StringInterface::NullValuePtr(); if (!o_) return InvalidArrayIndex; } 
	return (MTable::_instance._StringInterface_FindLastIndex(o_, str, std::forward<StringPosition>(start)));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto StringInterface::ConstReferenceFunctionsImpl<S>::FindIndex(Utf32Char ch, StringPosition start) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, false, typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const StringInterface* o_ = (const StringInterface*) this->GetPointer(); if (!(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS) && MAXON_UNLIKELY(!o_)) { o_ = StringInterface::NullValuePtr(); if (!o_) return InvalidArrayIndex; } 
	return (MTable::_instance._StringInterface_FindIndex_1(o_, ch, std::forward<StringPosition>(start)));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto StringInterface::ConstReferenceFunctionsImpl<S>::FindLastIndex(Utf32Char ch, StringPosition start) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, false, typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const StringInterface* o_ = (const StringInterface*) this->GetPointer(); if (!(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS) && MAXON_UNLIKELY(!o_)) { o_ = StringInterface::NullValuePtr(); if (!o_) return InvalidArrayIndex; } 
	return (MTable::_instance._StringInterface_FindLastIndex_1(o_, ch, std::forward<StringPosition>(start)));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto StringInterface::ConstReferenceFunctionsImpl<S>::FindUpperIndex(const StringInterface* str, StringPosition start) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, false, typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const StringInterface* o_ = (const StringInterface*) this->GetPointer(); if (!(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS) && MAXON_UNLIKELY(!o_)) { o_ = StringInterface::NullValuePtr(); if (!o_) return InvalidArrayIndex; } 
	return (MTable::_instance._StringInterface_FindUpperIndex(o_, str, std::forward<StringPosition>(start)));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto StringInterface::ConstReferenceFunctionsImpl<S>::FindLastUpperIndex(const StringInterface* str, StringPosition start) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, false, typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const StringInterface* o_ = (const StringInterface*) this->GetPointer(); if (!(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS) && MAXON_UNLIKELY(!o_)) { o_ = StringInterface::NullValuePtr(); if (!o_) return InvalidArrayIndex; } 
	return (MTable::_instance._StringInterface_FindLastUpperIndex(o_, str, std::forward<StringPosition>(start)));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto StringInterface::ReferenceFunctionsImpl<S>::Erase(StringPosition position, StringCount count) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); StringInterface* o_ = (StringInterface*) this->GetPointer(); if (MAXON_UNLIKELY(!o_)) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); 
	return (MTable::_instance._StringInterface_Erase(o_, std::forward<StringPosition>(position), std::forward<StringCount>(count)));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto StringInterface::COWReferenceFunctionsImpl<S>::Erase(StringPosition position, StringCount count) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); StringInterface* o_ = (StringInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS) && MAXON_UNLIKELY(!o_)) return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); 
	return (MTable::_instance._StringInterface_Erase(o_, std::forward<StringPosition>(position), std::forward<StringCount>(count)));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto StringInterface::ReferenceFunctionsImpl<S>::Insert(StringPosition position, const StringInterface* str, StringPosition strStart, StringCount strCount) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); StringInterface* o_ = (StringInterface*) this->GetPointer(); if (MAXON_UNLIKELY(!o_)) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); 
	return (MTable::_instance._StringInterface_Insert(o_, std::forward<StringPosition>(position), str, std::forward<StringPosition>(strStart), std::forward<StringCount>(strCount)));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto StringInterface::COWReferenceFunctionsImpl<S>::Insert(StringPosition position, const StringInterface* str, StringPosition strStart, StringCount strCount) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); StringInterface* o_ = (StringInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS) && MAXON_UNLIKELY(!o_)) return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); 
	return (MTable::_instance._StringInterface_Insert(o_, std::forward<StringPosition>(position), str, std::forward<StringPosition>(strStart), std::forward<StringCount>(strCount)));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto StringInterface::ReferenceFunctionsImpl<S>::Insert(StringPosition position, Utf32Char ch) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); StringInterface* o_ = (StringInterface*) this->GetPointer(); if (MAXON_UNLIKELY(!o_)) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); 
	return (MTable::_instance._StringInterface_Insert_1(o_, std::forward<StringPosition>(position), ch));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto StringInterface::COWReferenceFunctionsImpl<S>::Insert(StringPosition position, Utf32Char ch) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); StringInterface* o_ = (StringInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS) && MAXON_UNLIKELY(!o_)) return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); 
	return (MTable::_instance._StringInterface_Insert_1(o_, std::forward<StringPosition>(position), ch));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto StringInterface::ConstReferenceFunctionsImpl<S>::GetPart(StringPosition start, StringCount count) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<String>, String>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, false, typename std::conditional<S::HAS_ERROR, maxon::Result<String>, String>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const StringInterface* o_ = (const StringInterface*) this->GetPointer(); if (!(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS) && MAXON_UNLIKELY(!o_)) { o_ = StringInterface::NullValuePtr(); if (!o_) return String::NullValue(); } 
	return String(MTable::_instance._StringInterface_GetPart(o_, std::forward<StringPosition>(start), std::forward<StringCount>(count)));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto StringInterface::ConstReferenceFunctionsImpl<S>::ToUpper() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<String>, String>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, false, typename std::conditional<S::HAS_ERROR, maxon::Result<String>, String>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const StringInterface* o_ = (const StringInterface*) this->GetPointer(); if (!(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS) && MAXON_UNLIKELY(!o_)) { o_ = StringInterface::NullValuePtr(); if (!o_) return String::NullValue(); } 
	return String(MTable::_instance._StringInterface_ToUpper(o_));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto StringInterface::ConstReferenceFunctionsImpl<S>::ToLower() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<String>, String>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, false, typename std::conditional<S::HAS_ERROR, maxon::Result<String>, String>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const StringInterface* o_ = (const StringInterface*) this->GetPointer(); if (!(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS) && MAXON_UNLIKELY(!o_)) { o_ = StringInterface::NullValuePtr(); if (!o_) return String::NullValue(); } 
	return String(MTable::_instance._StringInterface_ToLower(o_));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto StringInterface::ConstReferenceFunctionsImpl<S>::ComparePart(const StringInterface* str, STRINGCOMPARISON mode, StringPosition position, StringCount count) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<COMPARERESULT>, COMPARERESULT>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, false, typename std::conditional<S::HAS_ERROR, maxon::Result<COMPARERESULT>, COMPARERESULT>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const StringInterface* o_ = (const StringInterface*) this->GetPointer(); if (!(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS) && MAXON_UNLIKELY(!o_)) { o_ = StringInterface::NullValuePtr(); if (!o_) return maxon::PrivateIncompleteNullReturnValue<COMPARERESULT>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } 
	return (MTable::_instance._StringInterface_ComparePart(o_, str, mode, std::forward<StringPosition>(position), std::forward<StringCount>(count)));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto StringInterface::ConstReferenceFunctionsImpl<S>::Compare(const StringInterface* str, STRINGCOMPARISON mode) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<COMPARERESULT>, COMPARERESULT>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, false, typename std::conditional<S::HAS_ERROR, maxon::Result<COMPARERESULT>, COMPARERESULT>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const StringInterface* o_ = (const StringInterface*) this->GetPointer(); if (!(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS) && MAXON_UNLIKELY(!o_)) { o_ = StringInterface::NullValuePtr(); if (!o_) return maxon::PrivateIncompleteNullReturnValue<COMPARERESULT>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } 
	return (o_->Compare(str, mode));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto StringInterface::ConstReferenceFunctionsImpl<S>::IsEqual(const StringInterface* str) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, false, typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const StringInterface* o_ = (const StringInterface*) this->GetPointer(); if (!(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS) && MAXON_UNLIKELY(!o_)) { o_ = StringInterface::NullValuePtr(); if (!o_) return maxon::PrivateLogNullptrError(false); } 
	return (o_->IsEqual(str));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto StringInterface::ConstReferenceFunctionsImpl<S>::ToFloat64(STRINGCONVERSION flags) const -> Result<Float64>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, false, Result<Float64>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const StringInterface* o_ = (const StringInterface*) this->GetPointer(); if (!(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS) && MAXON_UNLIKELY(!o_)) { o_ = StringInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (o_->ToFloat64(flags));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto StringInterface::ConstReferenceFunctionsImpl<S>::ToFloat32(STRINGCONVERSION flags) const -> Result<Float32>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, false, Result<Float32>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const StringInterface* o_ = (const StringInterface*) this->GetPointer(); if (!(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS) && MAXON_UNLIKELY(!o_)) { o_ = StringInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (o_->ToFloat32(flags));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto StringInterface::ConstReferenceFunctionsImpl<S>::ToFloat(STRINGCONVERSION flags) const -> Result<Float>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, false, Result<Float>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const StringInterface* o_ = (const StringInterface*) this->GetPointer(); if (!(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS) && MAXON_UNLIKELY(!o_)) { o_ = StringInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (o_->ToFloat(flags));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto StringInterface::ConstReferenceFunctionsImpl<S>::ToInt64(STRINGCONVERSION flags) const -> Result<Int64>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, false, Result<Int64>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const StringInterface* o_ = (const StringInterface*) this->GetPointer(); if (!(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS) && MAXON_UNLIKELY(!o_)) { o_ = StringInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (o_->ToInt64(flags));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto StringInterface::ConstReferenceFunctionsImpl<S>::ToInt32(STRINGCONVERSION flags) const -> Result<Int32>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, false, Result<Int32>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const StringInterface* o_ = (const StringInterface*) this->GetPointer(); if (!(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS) && MAXON_UNLIKELY(!o_)) { o_ = StringInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (o_->ToInt32(flags));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto StringInterface::ConstReferenceFunctionsImpl<S>::ToInt(STRINGCONVERSION flags) const -> Result<Int>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, false, Result<Int>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const StringInterface* o_ = (const StringInterface*) this->GetPointer(); if (!(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS) && MAXON_UNLIKELY(!o_)) { o_ = StringInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (o_->ToInt(flags));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto StringInterface::ConstReferenceFunctionsImpl<S>::ToUInt64(STRINGCONVERSION flags) const -> Result<UInt64>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, false, Result<UInt64>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const StringInterface* o_ = (const StringInterface*) this->GetPointer(); if (!(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS) && MAXON_UNLIKELY(!o_)) { o_ = StringInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (o_->ToUInt64(flags));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto StringInterface::ConstReferenceFunctionsImpl<S>::ToUInt32(STRINGCONVERSION flags) const -> Result<UInt32>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, false, Result<UInt32>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const StringInterface* o_ = (const StringInterface*) this->GetPointer(); if (!(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS) && MAXON_UNLIKELY(!o_)) { o_ = StringInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (o_->ToUInt32(flags));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto StringInterface::ConstReferenceFunctionsImpl<S>::ToUInt(STRINGCONVERSION flags) const -> Result<UInt>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, false, Result<UInt>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const StringInterface* o_ = (const StringInterface*) this->GetPointer(); if (!(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS) && MAXON_UNLIKELY(!o_)) { o_ = StringInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (o_->ToUInt(flags));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto StringInterface::ConstReferenceFunctionsImpl<S>::FloatToString(Float32 value, Int charsBeforeComma, Int digitsAfterComma, Bool exponent, Utf32Char fillChar) -> String { return (StringInterface::FloatToString(value, charsBeforeComma, digitsAfterComma, exponent, fillChar)); }
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto StringInterface::ConstReferenceFunctionsImpl<S>::FloatToString(Float64 value, Int charsBeforeComma, Int digitsAfterComma, Bool exponent, Utf32Char fillChar) -> String { return (StringInterface::FloatToString(value, charsBeforeComma, digitsAfterComma, exponent, fillChar)); }
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto StringInterface::ReferenceFunctionsImpl<S>::AppendInt(Int32 v) const -> DOXYGEN_SWITCH(maxon::RefMemberType<S const>, S)
{
	static_assert(!S::HAS_ERROR, "StringInterface::AppendInt can't be used on a Result object because it does not return a Result object itself."); StringInterface* o_ = (StringInterface*) this->GetPointer(); if (MAXON_UNLIKELY(!o_)) return this->PrivateGetRefMember(); 
	if (o_->AppendInt(v) == nullptr) this->ResetPointer();
	return this->PrivateGetRefMember();
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto StringInterface::COWReferenceFunctionsImpl<S>::AppendInt(Int32 v) -> DOXYGEN_SWITCH(maxon::RefMemberType<S>, S)
{
	static_assert(!S::HAS_ERROR, "StringInterface::AppendInt can't be used on a Result object because it does not return a Result object itself."); StringInterface* o_ = (StringInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS) && MAXON_UNLIKELY(!o_)) return this->PrivateGetRefMember(); 
	if (o_->AppendInt(v) == nullptr) this->ResetPointer();
	return this->PrivateGetRefMember();
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto StringInterface::ReferenceFunctionsImpl<S>::AppendUInt(UInt32 v) const -> DOXYGEN_SWITCH(maxon::RefMemberType<S const>, S)
{
	static_assert(!S::HAS_ERROR, "StringInterface::AppendUInt can't be used on a Result object because it does not return a Result object itself."); StringInterface* o_ = (StringInterface*) this->GetPointer(); if (MAXON_UNLIKELY(!o_)) return this->PrivateGetRefMember(); 
	if (o_->AppendUInt(v) == nullptr) this->ResetPointer();
	return this->PrivateGetRefMember();
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto StringInterface::COWReferenceFunctionsImpl<S>::AppendUInt(UInt32 v) -> DOXYGEN_SWITCH(maxon::RefMemberType<S>, S)
{
	static_assert(!S::HAS_ERROR, "StringInterface::AppendUInt can't be used on a Result object because it does not return a Result object itself."); StringInterface* o_ = (StringInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS) && MAXON_UNLIKELY(!o_)) return this->PrivateGetRefMember(); 
	if (o_->AppendUInt(v) == nullptr) this->ResetPointer();
	return this->PrivateGetRefMember();
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto StringInterface::ReferenceFunctionsImpl<S>::AppendInt(Int64 v) const -> DOXYGEN_SWITCH(maxon::RefMemberType<S const>, S)
{
	static_assert(!S::HAS_ERROR, "StringInterface::AppendInt can't be used on a Result object because it does not return a Result object itself."); StringInterface* o_ = (StringInterface*) this->GetPointer(); if (MAXON_UNLIKELY(!o_)) return this->PrivateGetRefMember(); 
	if (o_->AppendInt(v) == nullptr) this->ResetPointer();
	return this->PrivateGetRefMember();
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto StringInterface::COWReferenceFunctionsImpl<S>::AppendInt(Int64 v) -> DOXYGEN_SWITCH(maxon::RefMemberType<S>, S)
{
	static_assert(!S::HAS_ERROR, "StringInterface::AppendInt can't be used on a Result object because it does not return a Result object itself."); StringInterface* o_ = (StringInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS) && MAXON_UNLIKELY(!o_)) return this->PrivateGetRefMember(); 
	if (o_->AppendInt(v) == nullptr) this->ResetPointer();
	return this->PrivateGetRefMember();
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto StringInterface::ReferenceFunctionsImpl<S>::AppendUInt(UInt64 v) const -> DOXYGEN_SWITCH(maxon::RefMemberType<S const>, S)
{
	static_assert(!S::HAS_ERROR, "StringInterface::AppendUInt can't be used on a Result object because it does not return a Result object itself."); StringInterface* o_ = (StringInterface*) this->GetPointer(); if (MAXON_UNLIKELY(!o_)) return this->PrivateGetRefMember(); 
	if (o_->AppendUInt(v) == nullptr) this->ResetPointer();
	return this->PrivateGetRefMember();
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto StringInterface::COWReferenceFunctionsImpl<S>::AppendUInt(UInt64 v) -> DOXYGEN_SWITCH(maxon::RefMemberType<S>, S)
{
	static_assert(!S::HAS_ERROR, "StringInterface::AppendUInt can't be used on a Result object because it does not return a Result object itself."); StringInterface* o_ = (StringInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS) && MAXON_UNLIKELY(!o_)) return this->PrivateGetRefMember(); 
	if (o_->AppendUInt(v) == nullptr) this->ResetPointer();
	return this->PrivateGetRefMember();
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto StringInterface::ConstReferenceFunctionsImpl<S>::IntToString(Int32 v) -> String { return (StringInterface::IntToString(v)); }
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto StringInterface::ConstReferenceFunctionsImpl<S>::UIntToString(UInt32 v) -> String { return (StringInterface::UIntToString(v)); }
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto StringInterface::ConstReferenceFunctionsImpl<S>::IntToString(Int64 v) -> String { return (StringInterface::IntToString(v)); }
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto StringInterface::ConstReferenceFunctionsImpl<S>::UIntToString(UInt64 v) -> String { return (StringInterface::UIntToString(v)); }
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto StringInterface::ConstReferenceFunctionsImpl<S>::MemorySizeToString(Int64 v, Bool mebibytes) -> String { return (StringInterface::MemorySizeToString(v, mebibytes)); }
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto StringInterface::ConstReferenceFunctionsImpl<S>::HexToString(UInt32 v, Bool prefix0x) -> String { return (StringInterface::HexToString(v, prefix0x)); }
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto StringInterface::ConstReferenceFunctionsImpl<S>::HexToString(UInt64 v, Bool prefix0x) -> String { return (StringInterface::HexToString(v, prefix0x)); }
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto StringInterface::ConstReferenceFunctionsImpl<S>::PointerToString(const void* v) -> String { return (StringInterface::PointerToString(v)); }
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto StringInterface::ConstReferenceFunctionsImpl<S>::GetUtf32(Utf32CharBuffer& stringData) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const StringInterface* o_ = (const StringInterface*) this->GetPointer(); if (!(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS) && MAXON_UNLIKELY(!o_)) { o_ = StringInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (MTable::_instance._StringInterface_GetUtf32(o_, stringData));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto StringInterface::ReferenceFunctionsImpl<S>::TrimLeft() const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); StringInterface* o_ = (StringInterface*) this->GetPointer(); if (MAXON_UNLIKELY(!o_)) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); 
	return (MTable::_instance._StringInterface_TrimLeft(o_));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto StringInterface::COWReferenceFunctionsImpl<S>::TrimLeft() -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); StringInterface* o_ = (StringInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS) && MAXON_UNLIKELY(!o_)) return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); 
	return (MTable::_instance._StringInterface_TrimLeft(o_));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto StringInterface::ReferenceFunctionsImpl<S>::TrimRight() const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); StringInterface* o_ = (StringInterface*) this->GetPointer(); if (MAXON_UNLIKELY(!o_)) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); 
	return (MTable::_instance._StringInterface_TrimRight(o_));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto StringInterface::COWReferenceFunctionsImpl<S>::TrimRight() -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); StringInterface* o_ = (StringInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS) && MAXON_UNLIKELY(!o_)) return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); 
	return (MTable::_instance._StringInterface_TrimRight(o_));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto StringInterface::ConstReferenceFunctionsImpl<S>::Split(const String& splitSymbol, Bool trim, BaseArray<String>& parts) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const StringInterface* o_ = (const StringInterface*) this->GetPointer(); if (!(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS) && MAXON_UNLIKELY(!o_)) { o_ = StringInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (MTable::_instance._StringInterface_Split(o_, splitSymbol, trim, parts));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto StringInterface::ReferenceFunctionsImpl<S>::Replace(Utf32Char find, Utf32Char replace) const -> Result<Int>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, false, Result<Int>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); StringInterface* o_ = (StringInterface*) this->GetPointer(); if (MAXON_UNLIKELY(!o_)) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); 
	return (MTable::_instance._StringInterface_Replace(o_, find, replace));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto StringInterface::COWReferenceFunctionsImpl<S>::Replace(Utf32Char find, Utf32Char replace) -> Result<Int>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, false, Result<Int>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); StringInterface* o_ = (StringInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS) && MAXON_UNLIKELY(!o_)) return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); 
	return (MTable::_instance._StringInterface_Replace(o_, find, replace));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto StringInterface::ReferenceFunctionsImpl<S>::Replace(const String& find, const String& replace) const -> Result<Int>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, false, Result<Int>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); StringInterface* o_ = (StringInterface*) this->GetPointer(); if (MAXON_UNLIKELY(!o_)) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); 
	return (MTable::_instance._StringInterface_Replace_1(o_, find, replace));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto StringInterface::COWReferenceFunctionsImpl<S>::Replace(const String& find, const String& replace) -> Result<Int>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, false, Result<Int>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); StringInterface* o_ = (StringInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS) && MAXON_UNLIKELY(!o_)) return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); 
	return (MTable::_instance._StringInterface_Replace_1(o_, find, replace));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto StringInterface::ReferenceFunctionsImpl<S>::Replace(Utf32Char find, const String& replace) const -> Result<Int>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, false, Result<Int>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); StringInterface* o_ = (StringInterface*) this->GetPointer(); if (MAXON_UNLIKELY(!o_)) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); 
	return (MTable::_instance._StringInterface_Replace_2(o_, find, replace));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto StringInterface::COWReferenceFunctionsImpl<S>::Replace(Utf32Char find, const String& replace) -> Result<Int>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, false, Result<Int>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); StringInterface* o_ = (StringInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS) && MAXON_UNLIKELY(!o_)) return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); 
	return (MTable::_instance._StringInterface_Replace_2(o_, find, replace));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto StringInterface::ConstReferenceFunctionsImpl<S>::Find(const String& str, Int* pos, StringPosition start) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, false, typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const StringInterface* o_ = (const StringInterface*) this->GetPointer(); if (!(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS) && MAXON_UNLIKELY(!o_)) { o_ = StringInterface::NullValuePtr(); if (!o_) return maxon::PrivateLogNullptrError(false); } 
	return (o_->Find(str, pos, std::forward<StringPosition>(start)));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto StringInterface::ConstReferenceFunctionsImpl<S>::FindLast(const String& str, Int* pos, StringPosition start) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, false, typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const StringInterface* o_ = (const StringInterface*) this->GetPointer(); if (!(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS) && MAXON_UNLIKELY(!o_)) { o_ = StringInterface::NullValuePtr(); if (!o_) return maxon::PrivateLogNullptrError(false); } 
	return (o_->FindLast(str, pos, std::forward<StringPosition>(start)));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto StringInterface::ConstReferenceFunctionsImpl<S>::Find(Utf32Char ch, Int* pos, StringPosition start) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, false, typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const StringInterface* o_ = (const StringInterface*) this->GetPointer(); if (!(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS) && MAXON_UNLIKELY(!o_)) { o_ = StringInterface::NullValuePtr(); if (!o_) return maxon::PrivateLogNullptrError(false); } 
	return (o_->Find(ch, pos, std::forward<StringPosition>(start)));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto StringInterface::ConstReferenceFunctionsImpl<S>::FindLast(Utf32Char ch, Int* pos, StringPosition start) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, false, typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const StringInterface* o_ = (const StringInterface*) this->GetPointer(); if (!(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS) && MAXON_UNLIKELY(!o_)) { o_ = StringInterface::NullValuePtr(); if (!o_) return maxon::PrivateLogNullptrError(false); } 
	return (o_->FindLast(ch, pos, std::forward<StringPosition>(start)));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto StringInterface::ConstReferenceFunctionsImpl<S>::FindUpper(const String& str, Int* pos, StringPosition start) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, false, typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const StringInterface* o_ = (const StringInterface*) this->GetPointer(); if (!(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS) && MAXON_UNLIKELY(!o_)) { o_ = StringInterface::NullValuePtr(); if (!o_) return maxon::PrivateLogNullptrError(false); } 
	return (o_->FindUpper(str, pos, std::forward<StringPosition>(start)));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto StringInterface::ConstReferenceFunctionsImpl<S>::FindLastUpper(const String& str, Int* pos, StringPosition start) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, false, typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const StringInterface* o_ = (const StringInterface*) this->GetPointer(); if (!(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS) && MAXON_UNLIKELY(!o_)) { o_ = StringInterface::NullValuePtr(); if (!o_) return maxon::PrivateLogNullptrError(false); } 
	return (o_->FindLastUpper(str, pos, std::forward<StringPosition>(start)));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto StringInterface::ConstReferenceFunctionsImpl<S>::GetLeftPart(StringPosition start) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<String>, String>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, false, typename std::conditional<S::HAS_ERROR, maxon::Result<String>, String>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const StringInterface* o_ = (const StringInterface*) this->GetPointer(); if (!(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS) && MAXON_UNLIKELY(!o_)) { o_ = StringInterface::NullValuePtr(); if (!o_) return String::NullValue(); } 
	return String(o_->GetLeftPart(std::forward<StringPosition>(start)));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto StringInterface::ConstReferenceFunctionsImpl<S>::GetRightPart(StringPosition start) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<String>, String>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, false, typename std::conditional<S::HAS_ERROR, maxon::Result<String>, String>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const StringInterface* o_ = (const StringInterface*) this->GetPointer(); if (!(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS) && MAXON_UNLIKELY(!o_)) { o_ = StringInterface::NullValuePtr(); if (!o_) return String::NullValue(); } 
	return String(o_->GetRightPart(std::forward<StringPosition>(start)));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto StringInterface::ConstReferenceFunctionsImpl<S>::StartsWith(Utf32Char ch) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, false, typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const StringInterface* o_ = (const StringInterface*) this->GetPointer(); if (!(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS) && MAXON_UNLIKELY(!o_)) { o_ = StringInterface::NullValuePtr(); if (!o_) return maxon::PrivateLogNullptrError(false); } 
	return (o_->StartsWith(ch));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto StringInterface::ConstReferenceFunctionsImpl<S>::StartsWith(const String& str) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, false, typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const StringInterface* o_ = (const StringInterface*) this->GetPointer(); if (!(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS) && MAXON_UNLIKELY(!o_)) { o_ = StringInterface::NullValuePtr(); if (!o_) return maxon::PrivateLogNullptrError(false); } 
	return (o_->StartsWith(str));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto StringInterface::ConstReferenceFunctionsImpl<S>::EndsWith(Utf32Char ch) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, false, typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const StringInterface* o_ = (const StringInterface*) this->GetPointer(); if (!(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS) && MAXON_UNLIKELY(!o_)) { o_ = StringInterface::NullValuePtr(); if (!o_) return maxon::PrivateLogNullptrError(false); } 
	return (o_->EndsWith(ch));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto StringInterface::ConstReferenceFunctionsImpl<S>::EndsWith(const String& str) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, false, typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const StringInterface* o_ = (const StringInterface*) this->GetPointer(); if (!(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS) && MAXON_UNLIKELY(!o_)) { o_ = StringInterface::NullValuePtr(); if (!o_) return maxon::PrivateLogNullptrError(false); } 
	return (o_->EndsWith(str));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto StringInterface::ReferenceFunctionsImpl<S>::Trim() const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); StringInterface* o_ = (StringInterface*) this->GetPointer(); if (MAXON_UNLIKELY(!o_)) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); 
	return (o_->Trim());
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto StringInterface::COWReferenceFunctionsImpl<S>::Trim() -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); StringInterface* o_ = (StringInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS) && MAXON_UNLIKELY(!o_)) return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); 
	return (o_->Trim());
}
auto StringInterface::Reference::Create() -> maxon::ResultMemT<String>
{
	StringInterface* res_ = StringInterface::Alloc(MAXON_SOURCE_LOCATION);
	return String(maxon::ForwardResultPtr<StringInterface>(res_));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto StringInterface::ConstReferenceFunctionsImpl<S>::GetCStringBlock(const Block<Char>& buffer, const StringEncodingRef& stringEncoding) const -> Result<Int>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, false, Result<Int>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const StringInterface* o_ = (const StringInterface*) this->GetPointer(); if (!(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS) && MAXON_UNLIKELY(!o_)) { o_ = StringInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (MTable::_instance._StringInterface_GetCStringBlock(o_, buffer, stringEncoding));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto StringInterface::ConstReferenceFunctionsImpl<S>::GetCStringAppendArray(const NonConstArray<Char>& array, const StringEncodingRef& stringEncoding) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const StringInterface* o_ = (const StringInterface*) this->GetPointer(); if (!(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS) && MAXON_UNLIKELY(!o_)) { o_ = StringInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (MTable::_instance._StringInterface_GetCStringAppendArray(o_, array, stringEncoding));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto StringInterface::ConstReferenceFunctionsImpl<S>::GetCString(const StringEncodingRef& stringEncoding) const -> Result<BaseArray<Char>>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, false, Result<BaseArray<Char>>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const StringInterface* o_ = (const StringInterface*) this->GetPointer(); if (!(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS) && MAXON_UNLIKELY(!o_)) { o_ = StringInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (MTable::_instance._StringInterface_GetCString(o_, stringEncoding));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto StringInterface::ReferenceFunctionsImpl<S>::SetCString(const Char* buffer, Int count, const StringDecodingRef& stringDecoding) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); StringInterface* o_ = (StringInterface*) this->GetPointer(); if (MAXON_UNLIKELY(!o_)) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); 
	return (MTable::_instance._StringInterface_SetCString(o_, buffer, count, stringDecoding));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto StringInterface::COWReferenceFunctionsImpl<S>::SetCString(const Char* buffer, Int count, const StringDecodingRef& stringDecoding) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); StringInterface* o_ = (StringInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS) && MAXON_UNLIKELY(!o_)) return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); 
	return (MTable::_instance._StringInterface_SetCString(o_, buffer, count, stringDecoding));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto StringInterface::ReferenceFunctionsImpl<S>::SetCString(const Block<const Char>& buffer, const StringDecodingRef& stringDecoding) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); StringInterface* o_ = (StringInterface*) this->GetPointer(); if (MAXON_UNLIKELY(!o_)) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); 
	return (o_->SetCString(buffer, stringDecoding));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto StringInterface::COWReferenceFunctionsImpl<S>::SetCString(const Block<const Char>& buffer, const StringDecodingRef& stringDecoding) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); StringInterface* o_ = (StringInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS) && MAXON_UNLIKELY(!o_)) return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); 
	return (o_->SetCString(buffer, stringDecoding));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto StringInterface::ConstReferenceFunctionsImpl<S>::GetSystemEncoding() const -> Result<SysCharArray>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, false, Result<SysCharArray>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const StringInterface* o_ = (const StringInterface*) this->GetPointer(); if (!(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS) && MAXON_UNLIKELY(!o_)) { o_ = StringInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (MTable::_instance._StringInterface_GetSystemEncoding(o_));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto StringInterface::ReferenceFunctionsImpl<S>::SetSystemEncoding(const SysChar* buffer, Int count) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); StringInterface* o_ = (StringInterface*) this->GetPointer(); if (MAXON_UNLIKELY(!o_)) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); 
	return (MTable::_instance._StringInterface_SetSystemEncoding(o_, buffer, count));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto StringInterface::COWReferenceFunctionsImpl<S>::SetSystemEncoding(const SysChar* buffer, Int count) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); StringInterface* o_ = (StringInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS) && MAXON_UNLIKELY(!o_)) return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); 
	return (MTable::_instance._StringInterface_SetSystemEncoding(o_, buffer, count));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto StringInterface::ReferenceFunctionsImpl<S>::SetUtf32(const Utf32Char* buffer, Int count) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); StringInterface* o_ = (StringInterface*) this->GetPointer(); if (MAXON_UNLIKELY(!o_)) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); 
	return (MTable::_instance._StringInterface_SetUtf32(o_, buffer, count));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto StringInterface::COWReferenceFunctionsImpl<S>::SetUtf32(const Utf32Char* buffer, Int count) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); StringInterface* o_ = (StringInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS) && MAXON_UNLIKELY(!o_)) return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); 
	return (MTable::_instance._StringInterface_SetUtf32(o_, buffer, count));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto StringInterface::ConstReferenceFunctionsImpl<S>::GetUtf16(Utf16CharBuffer& stringData) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const StringInterface* o_ = (const StringInterface*) this->GetPointer(); if (!(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS) && MAXON_UNLIKELY(!o_)) { o_ = StringInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (MTable::_instance._StringInterface_GetUtf16(o_, stringData));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto StringInterface::ReferenceFunctionsImpl<S>::SetUtf16(const Utf16Char* buffer, Int count) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); StringInterface* o_ = (StringInterface*) this->GetPointer(); if (MAXON_UNLIKELY(!o_)) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); 
	return (MTable::_instance._StringInterface_SetUtf16(o_, buffer, count));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto StringInterface::COWReferenceFunctionsImpl<S>::SetUtf16(const Utf16Char* buffer, Int count) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); StringInterface* o_ = (StringInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS) && MAXON_UNLIKELY(!o_)) return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); 
	return (MTable::_instance._StringInterface_SetUtf16(o_, buffer, count));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto StringInterface::ConstReferenceFunctionsImpl<S>::GetAndCacheConstString(const wchar_t* chr, Int len) -> const String& { return (MTable::_instance._StringInterface_GetAndCacheConstString(chr, len)); }
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto StringInterface::ConstReferenceFunctionsImpl<S>::GetAndCacheConstString(const Char* chr, Int len, Int isUtf8) -> const String& { return (MTable::_instance._StringInterface_GetAndCacheConstString_1(chr, len, isUtf8)); }
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto StringInterface::ConstReferenceFunctionsImpl<S>::GetVariableInternalData() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<StridedBlock<const Generic>>, StridedBlock<const Generic>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, false, typename std::conditional<S::HAS_ERROR, maxon::Result<StridedBlock<const Generic>>, StridedBlock<const Generic>>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const StringInterface* o_ = (const StringInterface*) this->GetPointer(); if (!(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS) && MAXON_UNLIKELY(!o_)) { o_ = StringInterface::NullValuePtr(); if (!o_) return maxon::PrivateIncompleteNullReturnValue<StridedBlock<const Generic>>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } 
	return (MTable::_instance._StringInterface_GetVariableInternalData(o_));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto StringInterface::ConstReferenceFunctionsImpl<S>::GetCharacterWidth() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, false, typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const StringInterface* o_ = (const StringInterface*) this->GetPointer(); if (!(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS) && MAXON_UNLIKELY(!o_)) { o_ = StringInterface::NullValuePtr(); if (!o_) return 0; } 
	return (MTable::_instance._StringInterface_GetCharacterWidth(o_));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto StringInterface::ConstReferenceFunctionsImpl<S>::ConvertString(const StreamConversionRef& converter) const -> Result<String>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, false, Result<String>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const StringInterface* o_ = (const StringInterface*) this->GetPointer(); if (!(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS) && MAXON_UNLIKELY(!o_)) { o_ = StringInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (o_->ConvertString(converter));
}
#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT)
static maxon::EntityUse s_ui_maxon_StringInterface(StringInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/string.h", false);
#endif

struct CStringInterface::MTable
{
	static MTable _instance;
	static MTable _unresolvedInstance;
	static const maxon::Char* const _ids;
	static maxon::Bool InitUnresolved(maxon::NonvirtualInterfaceReference::UnresolvedAssembler assembler, MTable* tbl);
	static const maxon::NULL_RETURN_TYPE _returnTypes[];
	static const maxon::Bool HAS_NONSTATIC = true;
	void (*_CStringInterface_Free) (const CStringInterface* object);
	Int (*_CStringInterface_GetLength) (const CStringInterface* this_);
	Result<void> (*_CStringInterface_Init) (CStringInterface* this_, Int count, Char fillChar);
	Result<void> (*_CStringInterface_Shrink) (CStringInterface* this_);
	CStringInterface* (*_CStringInterface_Append) (CStringInterface* this_, const CStringInterface* str);
	CStringInterface* (*_CStringInterface_Append_1) (CStringInterface* this_, const Char* str, Int len);
	Int (*_CStringInterface_FindIndex) (const CStringInterface* this_, const CStringInterface* str, StringPosition start);
	Int (*_CStringInterface_FindLastIndex) (const CStringInterface* this_, const CStringInterface* str, StringPosition start);
	Int (*_CStringInterface_FindIndex_1) (const CStringInterface* this_, Char ch, StringPosition start);
	Int (*_CStringInterface_FindLastIndex_1) (const CStringInterface* this_, Char ch, StringPosition start);
	Int (*_CStringInterface_FindUpperIndex) (const CStringInterface* this_, const CStringInterface* str, StringPosition start);
	Int (*_CStringInterface_FindLastUpperIndex) (const CStringInterface* this_, const CStringInterface* str, StringPosition start);
	Result<void> (*_CStringInterface_Erase) (CStringInterface* this_, StringPosition position, StringCount count);
	Result<void> (*_CStringInterface_Insert) (CStringInterface* this_, StringPosition position, const CStringInterface* str, StringPosition strStart, StringCount strCount);
	Result<void> (*_CStringInterface_Insert_1) (CStringInterface* this_, StringPosition position, Char ch);
	CStringInterface* (*_CStringInterface_GetPart) (const CStringInterface* this_, StringPosition start, StringCount count);
	CStringInterface* (*_CStringInterface_ToUpper) (const CStringInterface* this_);
	CStringInterface* (*_CStringInterface_ToLower) (const CStringInterface* this_);
	COMPARERESULT (*_CStringInterface_ComparePart) (const CStringInterface* this_, const CStringInterface* str, STRINGCOMPARISON mode, StringPosition position, StringCount count);
	UInt (*_CStringInterface_GetHashCode) (const CStringInterface* this_);
	void (*_CStringInterface_SetChar) (CStringInterface* this_, Int pos, Char ch);
	Char (*_CStringInterface_GetChar) (const CStringInterface* this_, Int pos);
	Result<void> (*_CStringInterface_GetUtf32) (const CStringInterface* this_, Utf32CharBuffer& stringData);
	Result<void> (*_CStringInterface_TrimLeft) (CStringInterface* this_);
	Result<void> (*_CStringInterface_TrimRight) (CStringInterface* this_);
	Result<void> (*_CStringInterface_Split) (const CStringInterface* this_, const CString& splitSymbol, Bool trim, BaseArray<CString>& parts);
	Result<Int> (*_CStringInterface_Replace) (CStringInterface* this_, Char find, Char replace);
	Result<Int> (*_CStringInterface_Replace_1) (CStringInterface* this_, const CString& find, const CString& replace);
	Result<Int> (*_CStringInterface_Replace_2) (CStringInterface* this_, Char find, const CString& replace);
	CStringInterface* (*_CStringInterface_Alloc) (const maxon::SourceLocation& allocLocation);
	CStringInterface* (*_CStringInterface_Alloc_1) (const maxon::SourceLocation& allocLocation, const CStringInterface& object);
	Result<Int> (*_CStringInterface_GetCStringBlock) (const CStringInterface* this_, const Block<Char>& buffer);
	Result<void> (*_CStringInterface_GetCStringAppendArray) (const CStringInterface* this_, const NonConstArray<Char>& array);
	Result<void> (*_CStringInterface_SetCString) (CStringInterface* this_, const Char* buffer, Int count);
	Result<BaseArray<Char>> (*_CStringInterface_GetCString) (const CStringInterface* this_);
	Block<const Char> (*_CStringInterface_GetInternalData) (const CStringInterface* this_);
	const CString& (*_CStringInterface_GetAndCacheConstString) (const Char* chr, Int len);
	template <typename IMPL> static void Init(MTable* tbl)
	{
		tbl->_CStringInterface_Free = &IMPL::_CStringInterface_Free;
		tbl->_CStringInterface_GetLength = &IMPL::_CStringInterface_GetLength;
		tbl->_CStringInterface_Init = &IMPL::_CStringInterface_Init;
		tbl->_CStringInterface_Shrink = &IMPL::_CStringInterface_Shrink;
		tbl->_CStringInterface_Append = &IMPL::_CStringInterface_Append;
		tbl->_CStringInterface_Append_1 = &IMPL::_CStringInterface_Append_1;
		tbl->_CStringInterface_FindIndex = &IMPL::_CStringInterface_FindIndex;
		tbl->_CStringInterface_FindLastIndex = &IMPL::_CStringInterface_FindLastIndex;
		tbl->_CStringInterface_FindIndex_1 = &IMPL::_CStringInterface_FindIndex_1;
		tbl->_CStringInterface_FindLastIndex_1 = &IMPL::_CStringInterface_FindLastIndex_1;
		tbl->_CStringInterface_FindUpperIndex = &IMPL::_CStringInterface_FindUpperIndex;
		tbl->_CStringInterface_FindLastUpperIndex = &IMPL::_CStringInterface_FindLastUpperIndex;
		tbl->_CStringInterface_Erase = &IMPL::_CStringInterface_Erase;
		tbl->_CStringInterface_Insert = &IMPL::_CStringInterface_Insert;
		tbl->_CStringInterface_Insert_1 = &IMPL::_CStringInterface_Insert_1;
		tbl->_CStringInterface_GetPart = &IMPL::_CStringInterface_GetPart;
		tbl->_CStringInterface_ToUpper = &IMPL::_CStringInterface_ToUpper;
		tbl->_CStringInterface_ToLower = &IMPL::_CStringInterface_ToLower;
		tbl->_CStringInterface_ComparePart = &IMPL::_CStringInterface_ComparePart;
		tbl->_CStringInterface_GetHashCode = &IMPL::_CStringInterface_GetHashCode;
		tbl->_CStringInterface_SetChar = &IMPL::_CStringInterface_SetChar;
		tbl->_CStringInterface_GetChar = &IMPL::_CStringInterface_GetChar;
		tbl->_CStringInterface_GetUtf32 = &IMPL::_CStringInterface_GetUtf32;
		tbl->_CStringInterface_TrimLeft = &IMPL::_CStringInterface_TrimLeft;
		tbl->_CStringInterface_TrimRight = &IMPL::_CStringInterface_TrimRight;
		tbl->_CStringInterface_Split = &IMPL::_CStringInterface_Split;
		tbl->_CStringInterface_Replace = &IMPL::_CStringInterface_Replace;
		tbl->_CStringInterface_Replace_1 = &IMPL::_CStringInterface_Replace_1;
		tbl->_CStringInterface_Replace_2 = &IMPL::_CStringInterface_Replace_2;
		tbl->_CStringInterface_Alloc = &IMPL::_CStringInterface_Alloc;
		tbl->_CStringInterface_Alloc_1 = &IMPL::_CStringInterface_Alloc_1;
		tbl->_CStringInterface_GetCStringBlock = &IMPL::_CStringInterface_GetCStringBlock;
		tbl->_CStringInterface_GetCStringAppendArray = &IMPL::_CStringInterface_GetCStringAppendArray;
		tbl->_CStringInterface_SetCString = &IMPL::_CStringInterface_SetCString;
		tbl->_CStringInterface_GetCString = &IMPL::_CStringInterface_GetCString;
		tbl->_CStringInterface_GetInternalData = &IMPL::_CStringInterface_GetInternalData;
		tbl->_CStringInterface_GetAndCacheConstString = &IMPL::_CStringInterface_GetAndCacheConstString;
	}
};

template <typename C> class CStringInterface::Wrapper
{
public:
	static void _CStringInterface_Free(const CStringInterface* object) { return C::Free(object); }
	static Int _CStringInterface_GetLength(const CStringInterface* this_) { return ((const C*) this_)->GetLength(); }
	static Result<void> _CStringInterface_Init(CStringInterface* this_, Int count, Char fillChar) { return ((C*) this_)->Init(count, fillChar); }
	static Result<void> _CStringInterface_Shrink(CStringInterface* this_) { return ((C*) this_)->Shrink(); }
	static CStringInterface* _CStringInterface_Append(CStringInterface* this_, const CStringInterface* str) { return ((C*) this_)->Append(str); }
	static CStringInterface* _CStringInterface_Append_1(CStringInterface* this_, const Char* str, Int len) { return ((C*) this_)->Append(str, len); }
	static Int _CStringInterface_FindIndex(const CStringInterface* this_, const CStringInterface* str, StringPosition start) { return ((const C*) this_)->FindIndex(str, std::forward<StringPosition>(start)); }
	static Int _CStringInterface_FindLastIndex(const CStringInterface* this_, const CStringInterface* str, StringPosition start) { return ((const C*) this_)->FindLastIndex(str, std::forward<StringPosition>(start)); }
	static Int _CStringInterface_FindIndex_1(const CStringInterface* this_, Char ch, StringPosition start) { return ((const C*) this_)->FindIndex(ch, std::forward<StringPosition>(start)); }
	static Int _CStringInterface_FindLastIndex_1(const CStringInterface* this_, Char ch, StringPosition start) { return ((const C*) this_)->FindLastIndex(ch, std::forward<StringPosition>(start)); }
	static Int _CStringInterface_FindUpperIndex(const CStringInterface* this_, const CStringInterface* str, StringPosition start) { return ((const C*) this_)->FindUpperIndex(str, std::forward<StringPosition>(start)); }
	static Int _CStringInterface_FindLastUpperIndex(const CStringInterface* this_, const CStringInterface* str, StringPosition start) { return ((const C*) this_)->FindLastUpperIndex(str, std::forward<StringPosition>(start)); }
	static Result<void> _CStringInterface_Erase(CStringInterface* this_, StringPosition position, StringCount count) { return ((C*) this_)->Erase(std::forward<StringPosition>(position), std::forward<StringCount>(count)); }
	static Result<void> _CStringInterface_Insert(CStringInterface* this_, StringPosition position, const CStringInterface* str, StringPosition strStart, StringCount strCount) { return ((C*) this_)->Insert(std::forward<StringPosition>(position), str, std::forward<StringPosition>(strStart), std::forward<StringCount>(strCount)); }
	static Result<void> _CStringInterface_Insert_1(CStringInterface* this_, StringPosition position, Char ch) { return ((C*) this_)->Insert(std::forward<StringPosition>(position), ch); }
	static CStringInterface* _CStringInterface_GetPart(const CStringInterface* this_, StringPosition start, StringCount count) { return ((const C*) this_)->GetPart(std::forward<StringPosition>(start), std::forward<StringCount>(count)); }
	static CStringInterface* _CStringInterface_ToUpper(const CStringInterface* this_) { return ((const C*) this_)->ToUpper(); }
	static CStringInterface* _CStringInterface_ToLower(const CStringInterface* this_) { return ((const C*) this_)->ToLower(); }
	static COMPARERESULT _CStringInterface_ComparePart(const CStringInterface* this_, const CStringInterface* str, STRINGCOMPARISON mode, StringPosition position, StringCount count) { return ((const C*) this_)->ComparePart(str, mode, std::forward<StringPosition>(position), std::forward<StringCount>(count)); }
	static UInt _CStringInterface_GetHashCode(const CStringInterface* this_) { return ((const C*) this_)->GetHashCode(); }
	static void _CStringInterface_SetChar(CStringInterface* this_, Int pos, Char ch) { return ((C*) this_)->SetChar(pos, ch); }
	static Char _CStringInterface_GetChar(const CStringInterface* this_, Int pos) { return ((const C*) this_)->GetChar(pos); }
	static Result<void> _CStringInterface_GetUtf32(const CStringInterface* this_, Utf32CharBuffer& stringData) { return ((const C*) this_)->GetUtf32(stringData); }
	static Result<void> _CStringInterface_TrimLeft(CStringInterface* this_) { return ((C*) this_)->TrimLeft(); }
	static Result<void> _CStringInterface_TrimRight(CStringInterface* this_) { return ((C*) this_)->TrimRight(); }
	static Result<void> _CStringInterface_Split(const CStringInterface* this_, const CString& splitSymbol, Bool trim, BaseArray<CString>& parts) { return ((const C*) this_)->Split(splitSymbol, trim, parts); }
	static Result<Int> _CStringInterface_Replace(CStringInterface* this_, Char find, Char replace) { return ((C*) this_)->Replace(find, replace); }
	static Result<Int> _CStringInterface_Replace_1(CStringInterface* this_, const CString& find, const CString& replace) { return ((C*) this_)->Replace(find, replace); }
	static Result<Int> _CStringInterface_Replace_2(CStringInterface* this_, Char find, const CString& replace) { return ((C*) this_)->Replace(find, replace); }
	static CStringInterface* _CStringInterface_Alloc(const maxon::SourceLocation& allocLocation) { return C::Alloc(allocLocation); }
	static CStringInterface* _CStringInterface_Alloc_1(const maxon::SourceLocation& allocLocation, const CStringInterface& object) { return C::Alloc(allocLocation, ((const C&) object)); }
	static Result<Int> _CStringInterface_GetCStringBlock(const CStringInterface* this_, const Block<Char>& buffer) { return ((const C*) this_)->GetCStringBlock(buffer); }
	static Result<void> _CStringInterface_GetCStringAppendArray(const CStringInterface* this_, const NonConstArray<Char>& array) { return ((const C*) this_)->GetCStringAppendArray(array); }
	static Result<void> _CStringInterface_SetCString(CStringInterface* this_, const Char* buffer, Int count) { return ((C*) this_)->SetCString(buffer, count); }
	static Result<BaseArray<Char>> _CStringInterface_GetCString(const CStringInterface* this_) { return ((const C*) this_)->GetCString(); }
	static Block<const Char> _CStringInterface_GetInternalData(const CStringInterface* this_) { return ((const C*) this_)->GetInternalData(); }
	static const CString& _CStringInterface_GetAndCacheConstString(const Char* chr, Int len) { return C::GetAndCacheConstString(chr, len); }
};

MAXON_ATTRIBUTE_FORCE_INLINE auto CStringInterface::Free(const CStringInterface* object) -> void
{
	return MTable::_instance._CStringInterface_Free(object);
}
template <> MAXON_ATTRIBUTE_FORCE_INLINE auto StringTemplate<CStringInterface,CString,Char>::GetLength() const -> Int
{
	return CStringInterface::MTable::_instance._CStringInterface_GetLength(static_cast<const CStringInterface*>(this));
}
template <> MAXON_ATTRIBUTE_FORCE_INLINE auto StringTemplate<CStringInterface,CString,Char>::Init(Int count, Char fillChar) -> Result<void>
{
	return CStringInterface::MTable::_instance._CStringInterface_Init(static_cast<CStringInterface*>(this), count, fillChar);
}
template <> MAXON_ATTRIBUTE_FORCE_INLINE auto StringTemplate<CStringInterface,CString,Char>::Shrink() -> Result<void>
{
	return CStringInterface::MTable::_instance._CStringInterface_Shrink(static_cast<CStringInterface*>(this));
}
template <> MAXON_ATTRIBUTE_FORCE_INLINE auto StringTemplate<CStringInterface,CString,Char>::Append(const CStringInterface* str) -> CStringInterface*
{
	return CStringInterface::MTable::_instance._CStringInterface_Append(static_cast<CStringInterface*>(this), str);
}
template <> MAXON_ATTRIBUTE_FORCE_INLINE auto StringTemplate<CStringInterface,CString,Char>::Append(const Char* str, Int len) -> CStringInterface*
{
	return CStringInterface::MTable::_instance._CStringInterface_Append_1(static_cast<CStringInterface*>(this), str, len);
}
template <> MAXON_ATTRIBUTE_FORCE_INLINE auto StringTemplate<CStringInterface,CString,Char>::FindIndex(const CStringInterface* str, StringPosition start) const -> Int
{
	return CStringInterface::MTable::_instance._CStringInterface_FindIndex(static_cast<const CStringInterface*>(this), str, std::forward<StringPosition>(start));
}
template <> MAXON_ATTRIBUTE_FORCE_INLINE auto StringTemplate<CStringInterface,CString,Char>::FindLastIndex(const CStringInterface* str, StringPosition start) const -> Int
{
	return CStringInterface::MTable::_instance._CStringInterface_FindLastIndex(static_cast<const CStringInterface*>(this), str, std::forward<StringPosition>(start));
}
template <> MAXON_ATTRIBUTE_FORCE_INLINE auto StringTemplate<CStringInterface,CString,Char>::FindIndex(Char ch, StringPosition start) const -> Int
{
	return CStringInterface::MTable::_instance._CStringInterface_FindIndex_1(static_cast<const CStringInterface*>(this), ch, std::forward<StringPosition>(start));
}
template <> MAXON_ATTRIBUTE_FORCE_INLINE auto StringTemplate<CStringInterface,CString,Char>::FindLastIndex(Char ch, StringPosition start) const -> Int
{
	return CStringInterface::MTable::_instance._CStringInterface_FindLastIndex_1(static_cast<const CStringInterface*>(this), ch, std::forward<StringPosition>(start));
}
template <> MAXON_ATTRIBUTE_FORCE_INLINE auto StringTemplate<CStringInterface,CString,Char>::FindUpperIndex(const CStringInterface* str, StringPosition start) const -> Int
{
	return CStringInterface::MTable::_instance._CStringInterface_FindUpperIndex(static_cast<const CStringInterface*>(this), str, std::forward<StringPosition>(start));
}
template <> MAXON_ATTRIBUTE_FORCE_INLINE auto StringTemplate<CStringInterface,CString,Char>::FindLastUpperIndex(const CStringInterface* str, StringPosition start) const -> Int
{
	return CStringInterface::MTable::_instance._CStringInterface_FindLastUpperIndex(static_cast<const CStringInterface*>(this), str, std::forward<StringPosition>(start));
}
template <> MAXON_ATTRIBUTE_FORCE_INLINE auto StringTemplate<CStringInterface,CString,Char>::Erase(StringPosition position, StringCount count) -> Result<void>
{
	return CStringInterface::MTable::_instance._CStringInterface_Erase(static_cast<CStringInterface*>(this), std::forward<StringPosition>(position), std::forward<StringCount>(count));
}
template <> MAXON_ATTRIBUTE_FORCE_INLINE auto StringTemplate<CStringInterface,CString,Char>::Insert(StringPosition position, const CStringInterface* str, StringPosition strStart, StringCount strCount) -> Result<void>
{
	return CStringInterface::MTable::_instance._CStringInterface_Insert(static_cast<CStringInterface*>(this), std::forward<StringPosition>(position), str, std::forward<StringPosition>(strStart), std::forward<StringCount>(strCount));
}
template <> MAXON_ATTRIBUTE_FORCE_INLINE auto StringTemplate<CStringInterface,CString,Char>::Insert(StringPosition position, Char ch) -> Result<void>
{
	return CStringInterface::MTable::_instance._CStringInterface_Insert_1(static_cast<CStringInterface*>(this), std::forward<StringPosition>(position), ch);
}
template <> MAXON_ATTRIBUTE_FORCE_INLINE auto StringTemplate<CStringInterface,CString,Char>::GetPart(StringPosition start, StringCount count) const -> CStringInterface*
{
	return CStringInterface::MTable::_instance._CStringInterface_GetPart(static_cast<const CStringInterface*>(this), std::forward<StringPosition>(start), std::forward<StringCount>(count));
}
template <> MAXON_ATTRIBUTE_FORCE_INLINE auto StringTemplate<CStringInterface,CString,Char>::ToUpper() const -> CStringInterface*
{
	return CStringInterface::MTable::_instance._CStringInterface_ToUpper(static_cast<const CStringInterface*>(this));
}
template <> MAXON_ATTRIBUTE_FORCE_INLINE auto StringTemplate<CStringInterface,CString,Char>::ToLower() const -> CStringInterface*
{
	return CStringInterface::MTable::_instance._CStringInterface_ToLower(static_cast<const CStringInterface*>(this));
}
template <> MAXON_ATTRIBUTE_FORCE_INLINE auto StringTemplate<CStringInterface,CString,Char>::ComparePart(const CStringInterface* str, STRINGCOMPARISON mode, StringPosition position, StringCount count) const -> COMPARERESULT
{
	return CStringInterface::MTable::_instance._CStringInterface_ComparePart(static_cast<const CStringInterface*>(this), str, mode, std::forward<StringPosition>(position), std::forward<StringCount>(count));
}
template <> MAXON_ATTRIBUTE_FORCE_INLINE auto StringTemplate<CStringInterface,CString,Char>::GetHashCode() const -> UInt
{
	return CStringInterface::MTable::_instance._CStringInterface_GetHashCode(static_cast<const CStringInterface*>(this));
}
template <> MAXON_ATTRIBUTE_FORCE_INLINE auto StringTemplate<CStringInterface,CString,Char>::SetChar(Int pos, Char ch) -> void
{
	return CStringInterface::MTable::_instance._CStringInterface_SetChar(static_cast<CStringInterface*>(this), pos, ch);
}
template <> MAXON_ATTRIBUTE_FORCE_INLINE auto StringTemplate<CStringInterface,CString,Char>::GetChar(Int pos) const -> Char
{
	return CStringInterface::MTable::_instance._CStringInterface_GetChar(static_cast<const CStringInterface*>(this), pos);
}
template <> MAXON_ATTRIBUTE_FORCE_INLINE auto StringTemplate<CStringInterface,CString,Char>::GetUtf32(Utf32CharBuffer& stringData) const -> Result<void>
{
	return CStringInterface::MTable::_instance._CStringInterface_GetUtf32(static_cast<const CStringInterface*>(this), stringData);
}
template <> MAXON_ATTRIBUTE_FORCE_INLINE auto StringTemplate<CStringInterface,CString,Char>::TrimLeft() -> Result<void>
{
	return CStringInterface::MTable::_instance._CStringInterface_TrimLeft(static_cast<CStringInterface*>(this));
}
template <> MAXON_ATTRIBUTE_FORCE_INLINE auto StringTemplate<CStringInterface,CString,Char>::TrimRight() -> Result<void>
{
	return CStringInterface::MTable::_instance._CStringInterface_TrimRight(static_cast<CStringInterface*>(this));
}
template <> MAXON_ATTRIBUTE_FORCE_INLINE auto StringTemplate<CStringInterface,CString,Char>::Split(const CString& splitSymbol, Bool trim, BaseArray<CString>& parts) const -> Result<void>
{
	return CStringInterface::MTable::_instance._CStringInterface_Split(static_cast<const CStringInterface*>(this), splitSymbol, trim, parts);
}
template <> MAXON_ATTRIBUTE_FORCE_INLINE auto StringTemplate<CStringInterface,CString,Char>::Replace(Char find, Char replace) -> Result<Int>
{
	return CStringInterface::MTable::_instance._CStringInterface_Replace(static_cast<CStringInterface*>(this), find, replace);
}
template <> MAXON_ATTRIBUTE_FORCE_INLINE auto StringTemplate<CStringInterface,CString,Char>::Replace(const CString& find, const CString& replace) -> Result<Int>
{
	return CStringInterface::MTable::_instance._CStringInterface_Replace_1(static_cast<CStringInterface*>(this), find, replace);
}
template <> MAXON_ATTRIBUTE_FORCE_INLINE auto StringTemplate<CStringInterface,CString,Char>::Replace(Char find, const CString& replace) -> Result<Int>
{
	return CStringInterface::MTable::_instance._CStringInterface_Replace_2(static_cast<CStringInterface*>(this), find, replace);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto CStringInterface::Alloc(const maxon::SourceLocation& allocLocation) -> CStringInterface*
{
	return MTable::_instance._CStringInterface_Alloc(allocLocation);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto CStringInterface::Alloc(const maxon::SourceLocation& allocLocation, const CStringInterface& object) -> CStringInterface*
{
	return MTable::_instance._CStringInterface_Alloc_1(allocLocation, object);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto CStringInterface::GetCStringBlock(const Block<Char>& buffer) const -> Result<Int>
{
	return MTable::_instance._CStringInterface_GetCStringBlock(this, buffer);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto CStringInterface::GetCStringAppendArray(const NonConstArray<Char>& array) const -> Result<void>
{
	return MTable::_instance._CStringInterface_GetCStringAppendArray(this, array);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto CStringInterface::SetCString(const Char* buffer, Int count) -> Result<void>
{
	return MTable::_instance._CStringInterface_SetCString(this, buffer, count);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto CStringInterface::GetCString() const -> Result<BaseArray<Char>>
{
	return MTable::_instance._CStringInterface_GetCString(this);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto CStringInterface::GetInternalData() const -> Block<const Char>
{
	return MTable::_instance._CStringInterface_GetInternalData(this);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto CStringInterface::GetAndCacheConstString(const Char* chr, Int len) -> const CString&
{
	return MTable::_instance._CStringInterface_GetAndCacheConstString(chr, len);
}

template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CStringInterface::ConstReferenceFunctionsImpl<S>::GetLength() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, false, typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const CStringInterface* o_ = (const CStringInterface*) this->GetPointer(); if (!(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS) && MAXON_UNLIKELY(!o_)) { o_ = CStringInterface::NullValuePtr(); if (!o_) return 0; } 
	return (MTable::_instance._CStringInterface_GetLength(o_));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CStringInterface::ReferenceFunctionsImpl<S>::Init(Int count, Char fillChar) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); CStringInterface* o_ = (CStringInterface*) this->GetPointer(); if (MAXON_UNLIKELY(!o_)) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); 
	return (MTable::_instance._CStringInterface_Init(o_, count, fillChar));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CStringInterface::COWReferenceFunctionsImpl<S>::Init(Int count, Char fillChar) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); CStringInterface* o_ = (CStringInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS) && MAXON_UNLIKELY(!o_)) return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); 
	return (MTable::_instance._CStringInterface_Init(o_, count, fillChar));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CStringInterface::ReferenceFunctionsImpl<S>::Shrink() const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); CStringInterface* o_ = (CStringInterface*) this->GetPointer(); if (MAXON_UNLIKELY(!o_)) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); 
	return (MTable::_instance._CStringInterface_Shrink(o_));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CStringInterface::COWReferenceFunctionsImpl<S>::Shrink() -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); CStringInterface* o_ = (CStringInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS) && MAXON_UNLIKELY(!o_)) return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); 
	return (MTable::_instance._CStringInterface_Shrink(o_));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CStringInterface::ReferenceFunctionsImpl<S>::Append(const CStringInterface* str) const -> DOXYGEN_SWITCH(maxon::RefMemberType<S const>, S)
{
	static_assert(!S::HAS_ERROR, "CStringInterface::Append can't be used on a Result object because it does not return a Result object itself."); CStringInterface* o_ = (CStringInterface*) this->GetPointer(); if (MAXON_UNLIKELY(!o_)) return this->PrivateGetRefMember(); 
	if (MTable::_instance._CStringInterface_Append(o_, str) == nullptr) this->ResetPointer();
	return this->PrivateGetRefMember();
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CStringInterface::COWReferenceFunctionsImpl<S>::Append(const CStringInterface* str) -> DOXYGEN_SWITCH(maxon::RefMemberType<S>, S)
{
	static_assert(!S::HAS_ERROR, "CStringInterface::Append can't be used on a Result object because it does not return a Result object itself."); CStringInterface* o_ = (CStringInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS) && MAXON_UNLIKELY(!o_)) return this->PrivateGetRefMember(); 
	if (MTable::_instance._CStringInterface_Append(o_, str) == nullptr) this->ResetPointer();
	return this->PrivateGetRefMember();
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CStringInterface::ReferenceFunctionsImpl<S>::Append(const Char* str, Int len) const -> DOXYGEN_SWITCH(maxon::RefMemberType<S const>, S)
{
	static_assert(!S::HAS_ERROR, "CStringInterface::Append can't be used on a Result object because it does not return a Result object itself."); CStringInterface* o_ = (CStringInterface*) this->GetPointer(); if (MAXON_UNLIKELY(!o_)) return this->PrivateGetRefMember(); 
	if (MTable::_instance._CStringInterface_Append_1(o_, str, len) == nullptr) this->ResetPointer();
	return this->PrivateGetRefMember();
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CStringInterface::COWReferenceFunctionsImpl<S>::Append(const Char* str, Int len) -> DOXYGEN_SWITCH(maxon::RefMemberType<S>, S)
{
	static_assert(!S::HAS_ERROR, "CStringInterface::Append can't be used on a Result object because it does not return a Result object itself."); CStringInterface* o_ = (CStringInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS) && MAXON_UNLIKELY(!o_)) return this->PrivateGetRefMember(); 
	if (MTable::_instance._CStringInterface_Append_1(o_, str, len) == nullptr) this->ResetPointer();
	return this->PrivateGetRefMember();
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CStringInterface::ReferenceFunctionsImpl<S>::AppendChar(Char v) const -> DOXYGEN_SWITCH(maxon::RefMemberType<S const>, S)
{
	static_assert(!S::HAS_ERROR, "CStringInterface::AppendChar can't be used on a Result object because it does not return a Result object itself."); CStringInterface* o_ = (CStringInterface*) this->GetPointer(); if (MAXON_UNLIKELY(!o_)) return this->PrivateGetRefMember(); 
	if (o_->AppendChar(v) == nullptr) this->ResetPointer();
	return this->PrivateGetRefMember();
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CStringInterface::COWReferenceFunctionsImpl<S>::AppendChar(Char v) -> DOXYGEN_SWITCH(maxon::RefMemberType<S>, S)
{
	static_assert(!S::HAS_ERROR, "CStringInterface::AppendChar can't be used on a Result object because it does not return a Result object itself."); CStringInterface* o_ = (CStringInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS) && MAXON_UNLIKELY(!o_)) return this->PrivateGetRefMember(); 
	if (o_->AppendChar(v) == nullptr) this->ResetPointer();
	return this->PrivateGetRefMember();
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CStringInterface::ConstReferenceFunctionsImpl<S>::FindIndex(const CStringInterface* str, StringPosition start) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, false, typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const CStringInterface* o_ = (const CStringInterface*) this->GetPointer(); if (!(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS) && MAXON_UNLIKELY(!o_)) { o_ = CStringInterface::NullValuePtr(); if (!o_) return InvalidArrayIndex; } 
	return (MTable::_instance._CStringInterface_FindIndex(o_, str, std::forward<StringPosition>(start)));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CStringInterface::ConstReferenceFunctionsImpl<S>::FindLastIndex(const CStringInterface* str, StringPosition start) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, false, typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const CStringInterface* o_ = (const CStringInterface*) this->GetPointer(); if (!(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS) && MAXON_UNLIKELY(!o_)) { o_ = CStringInterface::NullValuePtr(); if (!o_) return InvalidArrayIndex; } 
	return (MTable::_instance._CStringInterface_FindLastIndex(o_, str, std::forward<StringPosition>(start)));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CStringInterface::ConstReferenceFunctionsImpl<S>::FindIndex(Char ch, StringPosition start) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, false, typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const CStringInterface* o_ = (const CStringInterface*) this->GetPointer(); if (!(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS) && MAXON_UNLIKELY(!o_)) { o_ = CStringInterface::NullValuePtr(); if (!o_) return InvalidArrayIndex; } 
	return (MTable::_instance._CStringInterface_FindIndex_1(o_, ch, std::forward<StringPosition>(start)));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CStringInterface::ConstReferenceFunctionsImpl<S>::FindLastIndex(Char ch, StringPosition start) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, false, typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const CStringInterface* o_ = (const CStringInterface*) this->GetPointer(); if (!(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS) && MAXON_UNLIKELY(!o_)) { o_ = CStringInterface::NullValuePtr(); if (!o_) return InvalidArrayIndex; } 
	return (MTable::_instance._CStringInterface_FindLastIndex_1(o_, ch, std::forward<StringPosition>(start)));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CStringInterface::ConstReferenceFunctionsImpl<S>::FindUpperIndex(const CStringInterface* str, StringPosition start) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, false, typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const CStringInterface* o_ = (const CStringInterface*) this->GetPointer(); if (!(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS) && MAXON_UNLIKELY(!o_)) { o_ = CStringInterface::NullValuePtr(); if (!o_) return InvalidArrayIndex; } 
	return (MTable::_instance._CStringInterface_FindUpperIndex(o_, str, std::forward<StringPosition>(start)));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CStringInterface::ConstReferenceFunctionsImpl<S>::FindLastUpperIndex(const CStringInterface* str, StringPosition start) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, false, typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const CStringInterface* o_ = (const CStringInterface*) this->GetPointer(); if (!(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS) && MAXON_UNLIKELY(!o_)) { o_ = CStringInterface::NullValuePtr(); if (!o_) return InvalidArrayIndex; } 
	return (MTable::_instance._CStringInterface_FindLastUpperIndex(o_, str, std::forward<StringPosition>(start)));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CStringInterface::ReferenceFunctionsImpl<S>::Erase(StringPosition position, StringCount count) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); CStringInterface* o_ = (CStringInterface*) this->GetPointer(); if (MAXON_UNLIKELY(!o_)) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); 
	return (MTable::_instance._CStringInterface_Erase(o_, std::forward<StringPosition>(position), std::forward<StringCount>(count)));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CStringInterface::COWReferenceFunctionsImpl<S>::Erase(StringPosition position, StringCount count) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); CStringInterface* o_ = (CStringInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS) && MAXON_UNLIKELY(!o_)) return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); 
	return (MTable::_instance._CStringInterface_Erase(o_, std::forward<StringPosition>(position), std::forward<StringCount>(count)));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CStringInterface::ReferenceFunctionsImpl<S>::Insert(StringPosition position, const CStringInterface* str, StringPosition strStart, StringCount strCount) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); CStringInterface* o_ = (CStringInterface*) this->GetPointer(); if (MAXON_UNLIKELY(!o_)) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); 
	return (MTable::_instance._CStringInterface_Insert(o_, std::forward<StringPosition>(position), str, std::forward<StringPosition>(strStart), std::forward<StringCount>(strCount)));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CStringInterface::COWReferenceFunctionsImpl<S>::Insert(StringPosition position, const CStringInterface* str, StringPosition strStart, StringCount strCount) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); CStringInterface* o_ = (CStringInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS) && MAXON_UNLIKELY(!o_)) return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); 
	return (MTable::_instance._CStringInterface_Insert(o_, std::forward<StringPosition>(position), str, std::forward<StringPosition>(strStart), std::forward<StringCount>(strCount)));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CStringInterface::ReferenceFunctionsImpl<S>::Insert(StringPosition position, Char ch) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); CStringInterface* o_ = (CStringInterface*) this->GetPointer(); if (MAXON_UNLIKELY(!o_)) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); 
	return (MTable::_instance._CStringInterface_Insert_1(o_, std::forward<StringPosition>(position), ch));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CStringInterface::COWReferenceFunctionsImpl<S>::Insert(StringPosition position, Char ch) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); CStringInterface* o_ = (CStringInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS) && MAXON_UNLIKELY(!o_)) return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); 
	return (MTable::_instance._CStringInterface_Insert_1(o_, std::forward<StringPosition>(position), ch));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CStringInterface::ConstReferenceFunctionsImpl<S>::GetPart(StringPosition start, StringCount count) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<CString>, CString>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, false, typename std::conditional<S::HAS_ERROR, maxon::Result<CString>, CString>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const CStringInterface* o_ = (const CStringInterface*) this->GetPointer(); if (!(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS) && MAXON_UNLIKELY(!o_)) { o_ = CStringInterface::NullValuePtr(); if (!o_) return CString::NullValue(); } 
	return CString(MTable::_instance._CStringInterface_GetPart(o_, std::forward<StringPosition>(start), std::forward<StringCount>(count)));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CStringInterface::ConstReferenceFunctionsImpl<S>::ToUpper() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<CString>, CString>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, false, typename std::conditional<S::HAS_ERROR, maxon::Result<CString>, CString>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const CStringInterface* o_ = (const CStringInterface*) this->GetPointer(); if (!(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS) && MAXON_UNLIKELY(!o_)) { o_ = CStringInterface::NullValuePtr(); if (!o_) return CString::NullValue(); } 
	return CString(MTable::_instance._CStringInterface_ToUpper(o_));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CStringInterface::ConstReferenceFunctionsImpl<S>::ToLower() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<CString>, CString>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, false, typename std::conditional<S::HAS_ERROR, maxon::Result<CString>, CString>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const CStringInterface* o_ = (const CStringInterface*) this->GetPointer(); if (!(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS) && MAXON_UNLIKELY(!o_)) { o_ = CStringInterface::NullValuePtr(); if (!o_) return CString::NullValue(); } 
	return CString(MTable::_instance._CStringInterface_ToLower(o_));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CStringInterface::ConstReferenceFunctionsImpl<S>::ComparePart(const CStringInterface* str, STRINGCOMPARISON mode, StringPosition position, StringCount count) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<COMPARERESULT>, COMPARERESULT>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, false, typename std::conditional<S::HAS_ERROR, maxon::Result<COMPARERESULT>, COMPARERESULT>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const CStringInterface* o_ = (const CStringInterface*) this->GetPointer(); if (!(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS) && MAXON_UNLIKELY(!o_)) { o_ = CStringInterface::NullValuePtr(); if (!o_) return maxon::PrivateIncompleteNullReturnValue<COMPARERESULT>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } 
	return (MTable::_instance._CStringInterface_ComparePart(o_, str, mode, std::forward<StringPosition>(position), std::forward<StringCount>(count)));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CStringInterface::ConstReferenceFunctionsImpl<S>::Compare(const CStringInterface* str, STRINGCOMPARISON mode) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<COMPARERESULT>, COMPARERESULT>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, false, typename std::conditional<S::HAS_ERROR, maxon::Result<COMPARERESULT>, COMPARERESULT>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const CStringInterface* o_ = (const CStringInterface*) this->GetPointer(); if (!(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS) && MAXON_UNLIKELY(!o_)) { o_ = CStringInterface::NullValuePtr(); if (!o_) return maxon::PrivateIncompleteNullReturnValue<COMPARERESULT>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } 
	return (o_->Compare(str, mode));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CStringInterface::ConstReferenceFunctionsImpl<S>::IsEqual(const CStringInterface* str) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, false, typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const CStringInterface* o_ = (const CStringInterface*) this->GetPointer(); if (!(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS) && MAXON_UNLIKELY(!o_)) { o_ = CStringInterface::NullValuePtr(); if (!o_) return maxon::PrivateLogNullptrError(false); } 
	return (o_->IsEqual(str));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CStringInterface::ConstReferenceFunctionsImpl<S>::ToFloat64(STRINGCONVERSION flags) const -> Result<Float64>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, false, Result<Float64>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const CStringInterface* o_ = (const CStringInterface*) this->GetPointer(); if (!(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS) && MAXON_UNLIKELY(!o_)) { o_ = CStringInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (o_->ToFloat64(flags));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CStringInterface::ConstReferenceFunctionsImpl<S>::ToFloat32(STRINGCONVERSION flags) const -> Result<Float32>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, false, Result<Float32>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const CStringInterface* o_ = (const CStringInterface*) this->GetPointer(); if (!(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS) && MAXON_UNLIKELY(!o_)) { o_ = CStringInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (o_->ToFloat32(flags));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CStringInterface::ConstReferenceFunctionsImpl<S>::ToFloat(STRINGCONVERSION flags) const -> Result<Float>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, false, Result<Float>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const CStringInterface* o_ = (const CStringInterface*) this->GetPointer(); if (!(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS) && MAXON_UNLIKELY(!o_)) { o_ = CStringInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (o_->ToFloat(flags));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CStringInterface::ConstReferenceFunctionsImpl<S>::ToInt64(STRINGCONVERSION flags) const -> Result<Int64>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, false, Result<Int64>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const CStringInterface* o_ = (const CStringInterface*) this->GetPointer(); if (!(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS) && MAXON_UNLIKELY(!o_)) { o_ = CStringInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (o_->ToInt64(flags));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CStringInterface::ConstReferenceFunctionsImpl<S>::ToInt32(STRINGCONVERSION flags) const -> Result<Int32>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, false, Result<Int32>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const CStringInterface* o_ = (const CStringInterface*) this->GetPointer(); if (!(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS) && MAXON_UNLIKELY(!o_)) { o_ = CStringInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (o_->ToInt32(flags));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CStringInterface::ConstReferenceFunctionsImpl<S>::ToInt(STRINGCONVERSION flags) const -> Result<Int>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, false, Result<Int>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const CStringInterface* o_ = (const CStringInterface*) this->GetPointer(); if (!(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS) && MAXON_UNLIKELY(!o_)) { o_ = CStringInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (o_->ToInt(flags));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CStringInterface::ConstReferenceFunctionsImpl<S>::ToUInt64(STRINGCONVERSION flags) const -> Result<UInt64>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, false, Result<UInt64>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const CStringInterface* o_ = (const CStringInterface*) this->GetPointer(); if (!(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS) && MAXON_UNLIKELY(!o_)) { o_ = CStringInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (o_->ToUInt64(flags));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CStringInterface::ConstReferenceFunctionsImpl<S>::ToUInt32(STRINGCONVERSION flags) const -> Result<UInt32>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, false, Result<UInt32>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const CStringInterface* o_ = (const CStringInterface*) this->GetPointer(); if (!(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS) && MAXON_UNLIKELY(!o_)) { o_ = CStringInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (o_->ToUInt32(flags));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CStringInterface::ConstReferenceFunctionsImpl<S>::ToUInt(STRINGCONVERSION flags) const -> Result<UInt>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, false, Result<UInt>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const CStringInterface* o_ = (const CStringInterface*) this->GetPointer(); if (!(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS) && MAXON_UNLIKELY(!o_)) { o_ = CStringInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (o_->ToUInt(flags));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CStringInterface::ConstReferenceFunctionsImpl<S>::FloatToString(Float32 value, Int charsBeforeComma, Int digitsAfterComma, Bool exponent, Char fillChar) -> CString { return (CStringInterface::FloatToString(value, charsBeforeComma, digitsAfterComma, exponent, fillChar)); }
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CStringInterface::ConstReferenceFunctionsImpl<S>::FloatToString(Float64 value, Int charsBeforeComma, Int digitsAfterComma, Bool exponent, Char fillChar) -> CString { return (CStringInterface::FloatToString(value, charsBeforeComma, digitsAfterComma, exponent, fillChar)); }
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CStringInterface::ReferenceFunctionsImpl<S>::AppendInt(Int32 v) const -> DOXYGEN_SWITCH(maxon::RefMemberType<S const>, S)
{
	static_assert(!S::HAS_ERROR, "CStringInterface::AppendInt can't be used on a Result object because it does not return a Result object itself."); CStringInterface* o_ = (CStringInterface*) this->GetPointer(); if (MAXON_UNLIKELY(!o_)) return this->PrivateGetRefMember(); 
	if (o_->AppendInt(v) == nullptr) this->ResetPointer();
	return this->PrivateGetRefMember();
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CStringInterface::COWReferenceFunctionsImpl<S>::AppendInt(Int32 v) -> DOXYGEN_SWITCH(maxon::RefMemberType<S>, S)
{
	static_assert(!S::HAS_ERROR, "CStringInterface::AppendInt can't be used on a Result object because it does not return a Result object itself."); CStringInterface* o_ = (CStringInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS) && MAXON_UNLIKELY(!o_)) return this->PrivateGetRefMember(); 
	if (o_->AppendInt(v) == nullptr) this->ResetPointer();
	return this->PrivateGetRefMember();
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CStringInterface::ReferenceFunctionsImpl<S>::AppendUInt(UInt32 v) const -> DOXYGEN_SWITCH(maxon::RefMemberType<S const>, S)
{
	static_assert(!S::HAS_ERROR, "CStringInterface::AppendUInt can't be used on a Result object because it does not return a Result object itself."); CStringInterface* o_ = (CStringInterface*) this->GetPointer(); if (MAXON_UNLIKELY(!o_)) return this->PrivateGetRefMember(); 
	if (o_->AppendUInt(v) == nullptr) this->ResetPointer();
	return this->PrivateGetRefMember();
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CStringInterface::COWReferenceFunctionsImpl<S>::AppendUInt(UInt32 v) -> DOXYGEN_SWITCH(maxon::RefMemberType<S>, S)
{
	static_assert(!S::HAS_ERROR, "CStringInterface::AppendUInt can't be used on a Result object because it does not return a Result object itself."); CStringInterface* o_ = (CStringInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS) && MAXON_UNLIKELY(!o_)) return this->PrivateGetRefMember(); 
	if (o_->AppendUInt(v) == nullptr) this->ResetPointer();
	return this->PrivateGetRefMember();
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CStringInterface::ReferenceFunctionsImpl<S>::AppendInt(Int64 v) const -> DOXYGEN_SWITCH(maxon::RefMemberType<S const>, S)
{
	static_assert(!S::HAS_ERROR, "CStringInterface::AppendInt can't be used on a Result object because it does not return a Result object itself."); CStringInterface* o_ = (CStringInterface*) this->GetPointer(); if (MAXON_UNLIKELY(!o_)) return this->PrivateGetRefMember(); 
	if (o_->AppendInt(v) == nullptr) this->ResetPointer();
	return this->PrivateGetRefMember();
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CStringInterface::COWReferenceFunctionsImpl<S>::AppendInt(Int64 v) -> DOXYGEN_SWITCH(maxon::RefMemberType<S>, S)
{
	static_assert(!S::HAS_ERROR, "CStringInterface::AppendInt can't be used on a Result object because it does not return a Result object itself."); CStringInterface* o_ = (CStringInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS) && MAXON_UNLIKELY(!o_)) return this->PrivateGetRefMember(); 
	if (o_->AppendInt(v) == nullptr) this->ResetPointer();
	return this->PrivateGetRefMember();
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CStringInterface::ReferenceFunctionsImpl<S>::AppendUInt(UInt64 v) const -> DOXYGEN_SWITCH(maxon::RefMemberType<S const>, S)
{
	static_assert(!S::HAS_ERROR, "CStringInterface::AppendUInt can't be used on a Result object because it does not return a Result object itself."); CStringInterface* o_ = (CStringInterface*) this->GetPointer(); if (MAXON_UNLIKELY(!o_)) return this->PrivateGetRefMember(); 
	if (o_->AppendUInt(v) == nullptr) this->ResetPointer();
	return this->PrivateGetRefMember();
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CStringInterface::COWReferenceFunctionsImpl<S>::AppendUInt(UInt64 v) -> DOXYGEN_SWITCH(maxon::RefMemberType<S>, S)
{
	static_assert(!S::HAS_ERROR, "CStringInterface::AppendUInt can't be used on a Result object because it does not return a Result object itself."); CStringInterface* o_ = (CStringInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS) && MAXON_UNLIKELY(!o_)) return this->PrivateGetRefMember(); 
	if (o_->AppendUInt(v) == nullptr) this->ResetPointer();
	return this->PrivateGetRefMember();
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CStringInterface::ConstReferenceFunctionsImpl<S>::IntToString(Int32 v) -> CString { return (CStringInterface::IntToString(v)); }
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CStringInterface::ConstReferenceFunctionsImpl<S>::UIntToString(UInt32 v) -> CString { return (CStringInterface::UIntToString(v)); }
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CStringInterface::ConstReferenceFunctionsImpl<S>::IntToString(Int64 v) -> CString { return (CStringInterface::IntToString(v)); }
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CStringInterface::ConstReferenceFunctionsImpl<S>::UIntToString(UInt64 v) -> CString { return (CStringInterface::UIntToString(v)); }
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CStringInterface::ConstReferenceFunctionsImpl<S>::MemorySizeToString(Int64 v, Bool mebibytes) -> CString { return (CStringInterface::MemorySizeToString(v, mebibytes)); }
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CStringInterface::ConstReferenceFunctionsImpl<S>::HexToString(UInt32 v, Bool prefix0x) -> CString { return (CStringInterface::HexToString(v, prefix0x)); }
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CStringInterface::ConstReferenceFunctionsImpl<S>::HexToString(UInt64 v, Bool prefix0x) -> CString { return (CStringInterface::HexToString(v, prefix0x)); }
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CStringInterface::ConstReferenceFunctionsImpl<S>::PointerToString(const void* v) -> CString { return (CStringInterface::PointerToString(v)); }
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CStringInterface::ConstReferenceFunctionsImpl<S>::GetUtf32(Utf32CharBuffer& stringData) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const CStringInterface* o_ = (const CStringInterface*) this->GetPointer(); if (!(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS) && MAXON_UNLIKELY(!o_)) { o_ = CStringInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (MTable::_instance._CStringInterface_GetUtf32(o_, stringData));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CStringInterface::ReferenceFunctionsImpl<S>::TrimLeft() const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); CStringInterface* o_ = (CStringInterface*) this->GetPointer(); if (MAXON_UNLIKELY(!o_)) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); 
	return (MTable::_instance._CStringInterface_TrimLeft(o_));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CStringInterface::COWReferenceFunctionsImpl<S>::TrimLeft() -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); CStringInterface* o_ = (CStringInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS) && MAXON_UNLIKELY(!o_)) return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); 
	return (MTable::_instance._CStringInterface_TrimLeft(o_));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CStringInterface::ReferenceFunctionsImpl<S>::TrimRight() const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); CStringInterface* o_ = (CStringInterface*) this->GetPointer(); if (MAXON_UNLIKELY(!o_)) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); 
	return (MTable::_instance._CStringInterface_TrimRight(o_));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CStringInterface::COWReferenceFunctionsImpl<S>::TrimRight() -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); CStringInterface* o_ = (CStringInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS) && MAXON_UNLIKELY(!o_)) return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); 
	return (MTable::_instance._CStringInterface_TrimRight(o_));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CStringInterface::ConstReferenceFunctionsImpl<S>::Split(const CString& splitSymbol, Bool trim, BaseArray<CString>& parts) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const CStringInterface* o_ = (const CStringInterface*) this->GetPointer(); if (!(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS) && MAXON_UNLIKELY(!o_)) { o_ = CStringInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (MTable::_instance._CStringInterface_Split(o_, splitSymbol, trim, parts));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CStringInterface::ReferenceFunctionsImpl<S>::Replace(Char find, Char replace) const -> Result<Int>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, false, Result<Int>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); CStringInterface* o_ = (CStringInterface*) this->GetPointer(); if (MAXON_UNLIKELY(!o_)) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); 
	return (MTable::_instance._CStringInterface_Replace(o_, find, replace));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CStringInterface::COWReferenceFunctionsImpl<S>::Replace(Char find, Char replace) -> Result<Int>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, false, Result<Int>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); CStringInterface* o_ = (CStringInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS) && MAXON_UNLIKELY(!o_)) return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); 
	return (MTable::_instance._CStringInterface_Replace(o_, find, replace));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CStringInterface::ReferenceFunctionsImpl<S>::Replace(const CString& find, const CString& replace) const -> Result<Int>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, false, Result<Int>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); CStringInterface* o_ = (CStringInterface*) this->GetPointer(); if (MAXON_UNLIKELY(!o_)) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); 
	return (MTable::_instance._CStringInterface_Replace_1(o_, find, replace));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CStringInterface::COWReferenceFunctionsImpl<S>::Replace(const CString& find, const CString& replace) -> Result<Int>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, false, Result<Int>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); CStringInterface* o_ = (CStringInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS) && MAXON_UNLIKELY(!o_)) return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); 
	return (MTable::_instance._CStringInterface_Replace_1(o_, find, replace));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CStringInterface::ReferenceFunctionsImpl<S>::Replace(Char find, const CString& replace) const -> Result<Int>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, false, Result<Int>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); CStringInterface* o_ = (CStringInterface*) this->GetPointer(); if (MAXON_UNLIKELY(!o_)) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); 
	return (MTable::_instance._CStringInterface_Replace_2(o_, find, replace));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CStringInterface::COWReferenceFunctionsImpl<S>::Replace(Char find, const CString& replace) -> Result<Int>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, false, Result<Int>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); CStringInterface* o_ = (CStringInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS) && MAXON_UNLIKELY(!o_)) return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); 
	return (MTable::_instance._CStringInterface_Replace_2(o_, find, replace));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CStringInterface::ConstReferenceFunctionsImpl<S>::Find(const CString& str, Int* pos, StringPosition start) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, false, typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const CStringInterface* o_ = (const CStringInterface*) this->GetPointer(); if (!(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS) && MAXON_UNLIKELY(!o_)) { o_ = CStringInterface::NullValuePtr(); if (!o_) return maxon::PrivateLogNullptrError(false); } 
	return (o_->Find(str, pos, std::forward<StringPosition>(start)));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CStringInterface::ConstReferenceFunctionsImpl<S>::FindLast(const CString& str, Int* pos, StringPosition start) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, false, typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const CStringInterface* o_ = (const CStringInterface*) this->GetPointer(); if (!(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS) && MAXON_UNLIKELY(!o_)) { o_ = CStringInterface::NullValuePtr(); if (!o_) return maxon::PrivateLogNullptrError(false); } 
	return (o_->FindLast(str, pos, std::forward<StringPosition>(start)));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CStringInterface::ConstReferenceFunctionsImpl<S>::Find(Char ch, Int* pos, StringPosition start) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, false, typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const CStringInterface* o_ = (const CStringInterface*) this->GetPointer(); if (!(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS) && MAXON_UNLIKELY(!o_)) { o_ = CStringInterface::NullValuePtr(); if (!o_) return maxon::PrivateLogNullptrError(false); } 
	return (o_->Find(ch, pos, std::forward<StringPosition>(start)));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CStringInterface::ConstReferenceFunctionsImpl<S>::FindLast(Char ch, Int* pos, StringPosition start) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, false, typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const CStringInterface* o_ = (const CStringInterface*) this->GetPointer(); if (!(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS) && MAXON_UNLIKELY(!o_)) { o_ = CStringInterface::NullValuePtr(); if (!o_) return maxon::PrivateLogNullptrError(false); } 
	return (o_->FindLast(ch, pos, std::forward<StringPosition>(start)));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CStringInterface::ConstReferenceFunctionsImpl<S>::FindUpper(const CString& str, Int* pos, StringPosition start) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, false, typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const CStringInterface* o_ = (const CStringInterface*) this->GetPointer(); if (!(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS) && MAXON_UNLIKELY(!o_)) { o_ = CStringInterface::NullValuePtr(); if (!o_) return maxon::PrivateLogNullptrError(false); } 
	return (o_->FindUpper(str, pos, std::forward<StringPosition>(start)));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CStringInterface::ConstReferenceFunctionsImpl<S>::FindLastUpper(const CString& str, Int* pos, StringPosition start) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, false, typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const CStringInterface* o_ = (const CStringInterface*) this->GetPointer(); if (!(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS) && MAXON_UNLIKELY(!o_)) { o_ = CStringInterface::NullValuePtr(); if (!o_) return maxon::PrivateLogNullptrError(false); } 
	return (o_->FindLastUpper(str, pos, std::forward<StringPosition>(start)));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CStringInterface::ConstReferenceFunctionsImpl<S>::GetLeftPart(StringPosition start) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<CString>, CString>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, false, typename std::conditional<S::HAS_ERROR, maxon::Result<CString>, CString>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const CStringInterface* o_ = (const CStringInterface*) this->GetPointer(); if (!(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS) && MAXON_UNLIKELY(!o_)) { o_ = CStringInterface::NullValuePtr(); if (!o_) return CString::NullValue(); } 
	return CString(o_->GetLeftPart(std::forward<StringPosition>(start)));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CStringInterface::ConstReferenceFunctionsImpl<S>::GetRightPart(StringPosition start) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<CString>, CString>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, false, typename std::conditional<S::HAS_ERROR, maxon::Result<CString>, CString>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const CStringInterface* o_ = (const CStringInterface*) this->GetPointer(); if (!(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS) && MAXON_UNLIKELY(!o_)) { o_ = CStringInterface::NullValuePtr(); if (!o_) return CString::NullValue(); } 
	return CString(o_->GetRightPart(std::forward<StringPosition>(start)));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CStringInterface::ConstReferenceFunctionsImpl<S>::StartsWith(Char ch) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, false, typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const CStringInterface* o_ = (const CStringInterface*) this->GetPointer(); if (!(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS) && MAXON_UNLIKELY(!o_)) { o_ = CStringInterface::NullValuePtr(); if (!o_) return maxon::PrivateLogNullptrError(false); } 
	return (o_->StartsWith(ch));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CStringInterface::ConstReferenceFunctionsImpl<S>::StartsWith(const CString& str) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, false, typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const CStringInterface* o_ = (const CStringInterface*) this->GetPointer(); if (!(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS) && MAXON_UNLIKELY(!o_)) { o_ = CStringInterface::NullValuePtr(); if (!o_) return maxon::PrivateLogNullptrError(false); } 
	return (o_->StartsWith(str));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CStringInterface::ConstReferenceFunctionsImpl<S>::EndsWith(Char ch) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, false, typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const CStringInterface* o_ = (const CStringInterface*) this->GetPointer(); if (!(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS) && MAXON_UNLIKELY(!o_)) { o_ = CStringInterface::NullValuePtr(); if (!o_) return maxon::PrivateLogNullptrError(false); } 
	return (o_->EndsWith(ch));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CStringInterface::ConstReferenceFunctionsImpl<S>::EndsWith(const CString& str) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, false, typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const CStringInterface* o_ = (const CStringInterface*) this->GetPointer(); if (!(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS) && MAXON_UNLIKELY(!o_)) { o_ = CStringInterface::NullValuePtr(); if (!o_) return maxon::PrivateLogNullptrError(false); } 
	return (o_->EndsWith(str));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CStringInterface::ReferenceFunctionsImpl<S>::Trim() const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); CStringInterface* o_ = (CStringInterface*) this->GetPointer(); if (MAXON_UNLIKELY(!o_)) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); 
	return (o_->Trim());
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CStringInterface::COWReferenceFunctionsImpl<S>::Trim() -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); CStringInterface* o_ = (CStringInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS) && MAXON_UNLIKELY(!o_)) return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); 
	return (o_->Trim());
}
auto CStringInterface::Reference::Create() -> maxon::ResultMemT<CString>
{
	CStringInterface* res_ = CStringInterface::Alloc(MAXON_SOURCE_LOCATION);
	return CString(maxon::ForwardResultPtr<CStringInterface>(res_));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CStringInterface::ConstReferenceFunctionsImpl<S>::GetCStringBlock(const Block<Char>& buffer) const -> Result<Int>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, false, Result<Int>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const CStringInterface* o_ = (const CStringInterface*) this->GetPointer(); if (!(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS) && MAXON_UNLIKELY(!o_)) { o_ = CStringInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (MTable::_instance._CStringInterface_GetCStringBlock(o_, buffer));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CStringInterface::ConstReferenceFunctionsImpl<S>::GetCStringAppendArray(const NonConstArray<Char>& array) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const CStringInterface* o_ = (const CStringInterface*) this->GetPointer(); if (!(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS) && MAXON_UNLIKELY(!o_)) { o_ = CStringInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (MTable::_instance._CStringInterface_GetCStringAppendArray(o_, array));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CStringInterface::ReferenceFunctionsImpl<S>::SetCString(const Char* buffer, Int count) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); CStringInterface* o_ = (CStringInterface*) this->GetPointer(); if (MAXON_UNLIKELY(!o_)) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); 
	return (MTable::_instance._CStringInterface_SetCString(o_, buffer, count));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CStringInterface::COWReferenceFunctionsImpl<S>::SetCString(const Char* buffer, Int count) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); CStringInterface* o_ = (CStringInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS) && MAXON_UNLIKELY(!o_)) return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); 
	return (MTable::_instance._CStringInterface_SetCString(o_, buffer, count));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CStringInterface::ReferenceFunctionsImpl<S>::SetCString(const Block<const Char>& buffer) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); CStringInterface* o_ = (CStringInterface*) this->GetPointer(); if (MAXON_UNLIKELY(!o_)) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); 
	return (o_->SetCString(buffer));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CStringInterface::COWReferenceFunctionsImpl<S>::SetCString(const Block<const Char>& buffer) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); CStringInterface* o_ = (CStringInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS) && MAXON_UNLIKELY(!o_)) return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); 
	return (o_->SetCString(buffer));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CStringInterface::ConstReferenceFunctionsImpl<S>::GetCString() const -> Result<BaseArray<Char>>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, false, Result<BaseArray<Char>>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const CStringInterface* o_ = (const CStringInterface*) this->GetPointer(); if (!(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS) && MAXON_UNLIKELY(!o_)) { o_ = CStringInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (MTable::_instance._CStringInterface_GetCString(o_));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CStringInterface::ConstReferenceFunctionsImpl<S>::GetInternalData() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Block<const Char>>, Block<const Char>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, false, typename std::conditional<S::HAS_ERROR, maxon::Result<Block<const Char>>, Block<const Char>>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const CStringInterface* o_ = (const CStringInterface*) this->GetPointer(); if (!(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS) && MAXON_UNLIKELY(!o_)) { o_ = CStringInterface::NullValuePtr(); if (!o_) return maxon::PrivateIncompleteNullReturnValue<Block<const Char>>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } 
	return (MTable::_instance._CStringInterface_GetInternalData(o_));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CStringInterface::ConstReferenceFunctionsImpl<S>::GetAndCacheConstString(const Char* chr, Int len) -> const CString& { return (MTable::_instance._CStringInterface_GetAndCacheConstString(chr, len)); }
#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT)
static maxon::EntityUse s_ui_maxon_CStringInterface(CStringInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/string.h", false);
#endif
#if !(defined MAXON_COMPILER_INTEL)
#else
#endif
#endif

#ifdef MAXON_COMPILER_GCC
	#pragma GCC diagnostic pop
#endif

#endif

