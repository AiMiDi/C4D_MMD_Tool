#if 1
class String;

template <> MAXON_ATTRIBUTE_FORCE_INLINE auto StringTemplate<StringInterface,String,Utf32Char>::GetLength() const -> Int;
template <> MAXON_ATTRIBUTE_FORCE_INLINE auto StringTemplate<StringInterface,String,Utf32Char>::Init(Int count, Utf32Char fillChar) -> Result<void>;
template <> MAXON_ATTRIBUTE_FORCE_INLINE auto StringTemplate<StringInterface,String,Utf32Char>::Shrink() -> Result<void>;
template <> MAXON_ATTRIBUTE_FORCE_INLINE auto StringTemplate<StringInterface,String,Utf32Char>::Append(const StringInterface* str) -> Result<void>;
template <> MAXON_ATTRIBUTE_FORCE_INLINE auto StringTemplate<StringInterface,String,Utf32Char>::Append(const Utf32Char* str, Int len) -> Result<void>;
template <> MAXON_ATTRIBUTE_FORCE_INLINE auto StringTemplate<StringInterface,String,Utf32Char>::FindIndex(const StringInterface* str, StringPosition start) const -> Int;
template <> MAXON_ATTRIBUTE_FORCE_INLINE auto StringTemplate<StringInterface,String,Utf32Char>::FindLastIndex(const StringInterface* str, StringPosition start) const -> Int;
template <> MAXON_ATTRIBUTE_FORCE_INLINE auto StringTemplate<StringInterface,String,Utf32Char>::FindIndex(Utf32Char ch, StringPosition start) const -> Int;
template <> MAXON_ATTRIBUTE_FORCE_INLINE auto StringTemplate<StringInterface,String,Utf32Char>::FindLastIndex(Utf32Char ch, StringPosition start) const -> Int;
template <> MAXON_ATTRIBUTE_FORCE_INLINE auto StringTemplate<StringInterface,String,Utf32Char>::FindUpperIndex(const StringInterface* str, StringPosition start) const -> Int;
template <> MAXON_ATTRIBUTE_FORCE_INLINE auto StringTemplate<StringInterface,String,Utf32Char>::FindLastUpperIndex(const StringInterface* str, StringPosition start) const -> Int;
template <> MAXON_ATTRIBUTE_FORCE_INLINE auto StringTemplate<StringInterface,String,Utf32Char>::Erase(StringPosition position, StringCount count) -> Result<void>;
template <> MAXON_ATTRIBUTE_FORCE_INLINE auto StringTemplate<StringInterface,String,Utf32Char>::Insert(StringPosition position, const StringInterface* str, StringPosition strStart, StringCount strCount) -> Result<void>;
template <> MAXON_ATTRIBUTE_FORCE_INLINE auto StringTemplate<StringInterface,String,Utf32Char>::Insert(StringPosition position, Utf32Char ch) -> Result<void>;
template <> MAXON_ATTRIBUTE_FORCE_INLINE auto StringTemplate<StringInterface,String,Utf32Char>::GetPart(StringPosition start, StringCount count) const -> StringInterface*;
template <> MAXON_ATTRIBUTE_FORCE_INLINE auto StringTemplate<StringInterface,String,Utf32Char>::ToUpper() const -> StringInterface*;
template <> MAXON_ATTRIBUTE_FORCE_INLINE auto StringTemplate<StringInterface,String,Utf32Char>::ToLower() const -> StringInterface*;
template <> MAXON_ATTRIBUTE_FORCE_INLINE auto StringTemplate<StringInterface,String,Utf32Char>::ComparePart(const StringInterface* str, STRINGCOMPARISON mode, StringPosition position, StringCount count) const -> COMPARERESULT;
template <> MAXON_ATTRIBUTE_FORCE_INLINE auto StringTemplate<StringInterface,String,Utf32Char>::GetHashCode() const -> UInt;
template <> MAXON_ATTRIBUTE_FORCE_INLINE auto StringTemplate<StringInterface,String,Utf32Char>::SetChar(Int pos, Utf32Char ch) -> void;
template <> MAXON_ATTRIBUTE_FORCE_INLINE auto StringTemplate<StringInterface,String,Utf32Char>::GetChar(Int pos) const -> Utf32Char;
template <> MAXON_ATTRIBUTE_FORCE_INLINE auto StringTemplate<StringInterface,String,Utf32Char>::GetUtf32(Utf32CharBuffer& stringData) const -> Result<void>;
template <> MAXON_ATTRIBUTE_FORCE_INLINE auto StringTemplate<StringInterface,String,Utf32Char>::TrimLeft() -> Result<void>;
template <> MAXON_ATTRIBUTE_FORCE_INLINE auto StringTemplate<StringInterface,String,Utf32Char>::TrimRight() -> Result<void>;
template <> MAXON_ATTRIBUTE_FORCE_INLINE auto StringTemplate<StringInterface,String,Utf32Char>::Split(const String& splitSymbol, Bool trim, const ValueReceiver<const String&>& parts) const -> Result<void>;
template <> MAXON_ATTRIBUTE_FORCE_INLINE auto StringTemplate<StringInterface,String,Utf32Char>::Replace(Utf32Char find, Utf32Char replace) -> Result<Int>;
template <> MAXON_ATTRIBUTE_FORCE_INLINE auto StringTemplate<StringInterface,String,Utf32Char>::Replace(const String& find, const String& replace) -> Result<Int>;
template <> MAXON_ATTRIBUTE_FORCE_INLINE auto StringTemplate<StringInterface,String,Utf32Char>::Replace(Utf32Char find, const String& replace) -> Result<Int>;
struct StringInterface::Hxx1
{
	class NonConstRef;
	using ReferenceClass = String;
	/// Intermediate helper class for StringInterface.
	template <typename S> class ConstReferenceFunctionsImpl DOXYGEN_SWITCH(: public S,)
	{
	public:
		ConstReferenceFunctionsImpl() = default;
		using PrivateBaseClass = S;
		using PrivateBaseClass::PrivateBaseClass;
/// Returns the length (number of elements) of the string, not the size of the block.
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type GetLength() const;
/// Searches for the first occurrence of 'str' within a string.
/// @param[in] str								The search string.
/// @param[in] start							Starting position within the current string to search from. If it is out of bounds the function will return InvalidArrayIndex.
/// @return												The index at which 'str' has been found or InvalidArrayIndex.
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type FindIndex(const StringInterface* str, StringPosition start = 0) const;
/// Searches for the last occurrence of 'str' within a string.
/// @param[in] str								The search string.
/// @param[in] start							Starting position within the current string to search from (backwards). The character at the given position will not be included in the search. If it is out of bounds the function will return InvalidArrayIndex.
/// @return												The index at which 'str' has been found or InvalidArrayIndex.
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type FindLastIndex(const StringInterface* str, StringPosition start = StringEnd()) const;
/// Searches for the first occurrence of character 'ch' within a string.
/// @param[in] ch									The search character.
/// @param[in] start							Starting position within the current string to search from. If it is out of bounds the function will return InvalidArrayIndex.
/// @return												The index at which 'ch' has been found or InvalidArrayIndex.
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type FindIndex(Utf32Char ch, StringPosition start = 0) const;
/// Searches for the last occurrence of character 'ch' within a string.
/// @param[in] ch									The search character.
/// @param[in] start							Starting position within the current string to search from (backwards). The character at the given position will not be included in the search. If it is out of bounds the function will return InvalidArrayIndex.
/// @return												The index at which 'ch' has been found or InvalidArrayIndex.
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type FindLastIndex(Utf32Char ch, StringPosition start = StringEnd()) const;
/// Uppercase search for the first occurrence of 'str' within a string (which doesn't need to contain uppercase characters).
/// @param[in] str								The search string, must be completely uppercase, otherwise no matches will be found.
/// @param[in] start							Starting position within the current string to search from. If it is out of bounds the function will return InvalidArrayIndex.
/// @return												The index at which 'str' has been found or InvalidArrayIndex.
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type FindUpperIndex(const StringInterface* str, StringPosition start = 0) const;
/// Uppercase search for the last occurrence of 'str' within a string (which doesn't need to contain uppercase characters).
/// @param[in] str								The search string, must be completely uppercase, otherwise no matches will be found.
/// @param[in] start							Starting position within the current string to search from (backwards). The character at the given position will not be included in the search. If it is out of bounds the function will return InvalidArrayIndex.
/// @return												The index at which 'str' has been found or InvalidArrayIndex.
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type FindLastUpperIndex(const StringInterface* str, StringPosition start = StringEnd()) const;
/// Creates a part of the current string.
/// @param[in] start							Position where the new partial string will start.
/// @param[in] count							Number of characters for the partial string. If it is larger than the number of available characters an empty string will be returned.
/// @return												The partial string, or empty string if 'start' was out of boundaries. Will be an empty reference if GetPart fails (apply iferr for error handling).
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<String>, String>::type GetPart(StringPosition start, StringCount count) const;
/// Returns the uppercase version of a string.
/// @return												Uppercase version of a string. Will be an empty reference if ToUpper fails (apply iferr for error handling).
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<String>, String>::type ToUpper() const;
/// Returns the lowercase version of a string.
/// @return												Lowercase version of a string. Will be an empty reference if ToLower fails (apply iferr for error handling).
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<String>, String>::type ToLower() const;
/// Compares a part of this against 'str' for exact match.
/// Example:
/// @code
/// "abcdefghijk"_s.ComparePart("bcd"_s,STRINGCOMPARISON::MEMORY,1,3);
/// @endcode
/// returns COMPARESTRING::EQUAL for matching "bcd"
/// @param[in] str								Comparison object.
/// @param[in] mode								Comparison mode.
/// @param[in] position						Starting position in the current string that 'str' will be compared against. The interval [position..count] will be clipped against valid boundaries.
/// @param[in] count							Number of characters in the current string that 'str' will be compared against. count can be longer than the string length and will be clipped accordingly.
/// @return												See COMPARERESULT.
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<COMPARERESULT>, COMPARERESULT>::type ComparePart(const StringInterface* str, STRINGCOMPARISON mode, StringPosition position, StringCount count) const;
/// Compares the object against 'str' for exact match.
/// @param[in] str								Comparison object.
/// @param[in] mode								Comparison mode.
/// @return												See COMPARERESULT.
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<COMPARERESULT>, COMPARERESULT>::type Compare(const StringInterface* str, STRINGCOMPARISON mode = STRINGCOMPARISON::UNICODE_NUMBERS) const;
/// Compare strings for equality.
/// @return												True if equal.
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type IsEqual(const StringInterface* str) const;
/// Converts a string to a 64-bit floating point value.
/// This routine does no formula parsing.
/// While leading whitespaces are allowed by default no trailing characters of any kind are allowed.
/// @param[in] flags							Optional flags for the conversion.
/// @return												Floating point value of the string.
		inline Result<Float64> ToFloat64(STRINGCONVERSION flags = STRINGCONVERSION::NONE) const;
/// Converts a string to a 32-bit floating point value.
/// This routine does no formula parsing.
/// While leading whitespaces are allowed by default no trailing characters of any kind are allowed.
/// @param[in] flags							Optional flags for the conversion.
/// @return												Floating point value of the string.
		inline Result<Float32> ToFloat32(STRINGCONVERSION flags = STRINGCONVERSION::NONE) const;
/// Converts a string to a floating point value.
/// This routine does no formula parsing.
/// While leading whitespaces are allowed by default no trailing characters of any kind are allowed.
/// @param[in] flags							Optional flags for the conversion.
/// @return												Floating point value of the string.
		inline Result<Float> ToFloat(STRINGCONVERSION flags = STRINGCONVERSION::NONE) const;
/// Converts a string to a 64 bit integer value.
/// This routine does no formula parsing and does not support any suffixes/prefixes except for 0x (hexadecimal numbers).
/// While leading whitespaces are allowed by default no trailing characters of any kind are allowed.
/// @param[in] flags							Optional flags for the conversion.
/// @return												Integer value of the string.
		inline Result<Int64> ToInt64(STRINGCONVERSION flags = STRINGCONVERSION::NONE) const;
/// Converts a string to a 32 bit integer value.
/// This routine does no formula parsing and does not support any suffixes/prefixes except for 0x (hexadecimal numbers).
/// While leading whitespaces are allowed by default no trailing characters of any kind are allowed.
/// @param[in] flags							Optional flags for the conversion.
/// @return												Integer value of the string.
		inline Result<Int32> ToInt32(STRINGCONVERSION flags = STRINGCONVERSION::NONE) const;
/// Converts a string to an integer value.
/// This routine does no formula parsing and does not support any suffixes/prefixes except for 0x (hexadecimal numbers).
/// While leading whitespaces are allowed by default no trailing characters of any kind are allowed.
/// @param[in] flags							Optional flags for the conversion.
/// @return												Integer value of the string.
		inline Result<Int> ToInt(STRINGCONVERSION flags = STRINGCONVERSION::NONE) const;
/// Converts a string to a 64 bit unsigned integer value.
/// This routine does no formula parsing and does not support any suffixes/prefixes except for 0x (hexadecimal numbers).
/// While leading whitespaces are allowed by default no trailing characters of any kind are allowed.
/// @param[in] flags							Optional flags for the conversion.
/// @return												Integer value of the string.
		inline Result<UInt64> ToUInt64(STRINGCONVERSION flags = STRINGCONVERSION::NONE) const;
/// Converts a string to a 32 bit unsigned integer value.
/// This routine does no formula parsing and does not support any suffixes/prefixes except for 0x (hexadecimal numbers).
/// While leading whitespaces are allowed by default no trailing characters of any kind are allowed.
/// @param[in] flags							Optional flags for the conversion.
/// @return												Integer value of the string.
		inline Result<UInt32> ToUInt32(STRINGCONVERSION flags = STRINGCONVERSION::NONE) const;
/// Converts a string to an unsigned integer value.
/// This routine does no formula parsing and does not support any suffixes/prefixes except for 0x (hexadecimal numbers).
/// While leading whitespaces are allowed by default no trailing characters of any kind are allowed.
/// @param[in] flags							Optional flags for the conversion.
/// @return												Integer value of the string.
		inline Result<UInt> ToUInt(STRINGCONVERSION flags = STRINGCONVERSION::NONE) const;
/// Converts a floating point value into formatted text.
/// @param[in] value							Floating point value to convert into text.
/// @param[in] charsBeforeComma		Characters before the decimal point. If STRING_DYNAMIC_DIGITS is passed or 'charsBeforeComma' is too low to represent 'value' it is automatically increased/adjusted. If 'charsBeforeComma' is positive and exponent is false fill characters will be added to the beginning. If STRING_MAXIMUM_PRECISION is passed, then the result will be an exact representation of the value (possibly using exponential notation).
/// @param[in] digitsAfterComma		Digits after the decimal point. If a negative number is passed the number of digits is automatically chosen and up to (-digitsAfterComma).
/// @param[in] exponent						Force exponential-style output (e.g. 1.0e+10).
/// @param[in] fillChar						Fill character for digits before the decimal point. E.g. if you specify 4 for charsBeforeComma, '*' for fillChar and your value is 1.5 you'll get ***1.5 as a result. This value has no impact if exponent is true.
/// @return												String object with the decimal text of the value.
		static inline String FloatToString(Float32 value, Int charsBeforeComma = STRING_DYNAMIC_DIGITS, Int digitsAfterComma = -3, Bool exponent = false, Utf32Char fillChar = ' ');
/// Converts a floating point value into formatted text.
/// @param[in] value							Floating point value to convert into text.
/// @param[in] charsBeforeComma		Characters before the decimal point. If STRING_DYNAMIC_DIGITS is passed or 'charsBeforeComma' is too low to represent 'value' it is automatically increased/adjusted. If 'charsBeforeComma' is positive and exponent is false fill characters will be added to the beginning. If STRING_MAXIMUM_PRECISION is passed, then the result will be an exact representation of the value (possibly using exponential notation).
/// @param[in] digitsAfterComma		Digits after the decimal point. If a negative number is passed the number of digits is automatically chosen and up to (-digitsAfterComma).
/// @param[in] exponent						Force exponential-style output (e.g. 1.0e+10).
/// @param[in] fillChar						Fill character for digits before the decimal point. E.g. if you specify 4 for charsBeforeComma, '*' for fillChar and your value is 1.5 you'll get ***1.5 as a result. This value has no impact if exponent is true.
/// @return												String object with the decimal text of the value.
		static inline String FloatToString(Float64 value, Int charsBeforeComma = STRING_DYNAMIC_DIGITS, Int digitsAfterComma = -3, Bool exponent = false, Utf32Char fillChar = ' ');
/// Formats a Int32 value as decimal text.
/// @param[in] v									Int32 value.
/// @return												String object with the decimal text of the value. Will be an empty reference on failure (apply iferr for error handling).
		static inline String IntToString(Int32 v);
/// Formats a UInt32 value as decimal text.
/// @param[in] v									UInt32 value.
/// @return												String object with the decimal text of the value. Will be an empty reference on failure (apply iferr for error handling).
		static inline String UIntToString(UInt32 v);
/// Formats a Int64 value as decimal text.
/// @param[in] v									Int64 value.
/// @return												String object with the decimal text of the value. Will be an empty reference on failure (apply iferr for error handling).
		static inline String IntToString(Int64 v);
/// Formats a UInt64 value as decimal text.
/// @param[in] v									Int64 value.
/// @return												String object with the decimal text of the value. Will be an empty reference on failure (apply iferr for error handling).
		static inline String UIntToString(UInt64 v);
/// Formats a Int64 value as a memory information.
/// @param[in] v									The size of bytes that should be formated as memory text.
/// @param[in] mebibytes					defines if a value of 1343443 is either output as "1.28 MiB" (mebibytes) or "1.34 MB" (megabytes).
/// @return												String object for the given mem value.
		static inline String MemorySizeToString(Int64 v, Bool mebibytes = true);
/// Formats a Int32 value as hexadecimal text.
/// @param[in] v									Int32 value.
/// @param[in] prefix0x						Start the string with 0x as prefix.
/// @return												String object with the hexadecimal text of the value.
		static inline String HexToString(UInt32 v, Bool prefix0x = true);
/// Formats a Int64 value as hexadecimal text.
/// @param[in] v									Int64 value.
/// @param[in] prefix0x						Start the string with 0x as prefix.
/// @return												String object with the hexadecimal text of the value.
		static inline String HexToString(UInt64 v, Bool prefix0x = true);
/// Formats a pointer as hexadecimal text. The pointer starts with 0x prefix.
/// @param[in] v									Pointer to convert.
/// @return												String object with the hexadecimal text of the value.
		static inline String PointerToString(const void* v);
/// Copies the string as UTF-32 encoded characters into the passed array.
/// The array will be resized and contain the non \0 - terminated data.
/// @param[out] stringData				The array to receive the data.
/// @return												OK on success.
		inline Result<void> GetUtf32(Utf32CharBuffer& stringData) const;
/// Splits the string into parts separated by the split symbol (e.g. a comma).
/// @param[in] splitSymbol				String containing the split symbol.
/// @param[in] trim								If true each separated part will be trimmed (see Trim).
/// @param[out] parts							Array to be filled with the separated strings.
/// @return												OK on success.
		inline Result<void> Split(const String& splitSymbol, Bool trim, const ValueReceiver<const String&>& parts) const;
/// Searches for the first occurrence of 'str' within a string.
/// @param[in] str								The search string.
/// @param[out] pos								Pointer to be filled with the position where 'str' was found. This parameter can be a nullptr. In case no occurence was found *pos is initialized with InvalidArrayIndex.
/// @param[in] start							Starting position within the current string to search from. If it is out of bounds the function will return false.
/// @return												True if 'str' has been found, in that case *pos contains the position where the first occurance was found.
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type Find(const String& str, Int* pos, StringPosition start = 0) const;
/// Searches for the last occurrence of 'str' within a string.
/// @param[in] str								The search string.
/// @param[out] pos								Pointer to be filled with the position where 'str' was found. This parameter can be a nullptr. In case no occurence was found *pos is initialized with InvalidArrayIndex.
/// @param[in] start							Starting position within the current string to search from (backwards). The character at the given position will not be included in the search. If it is out of bounds the function will return false.
/// @return												True if 'str' has been found, in that case *pos contains the position where the last occurance was found.
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type FindLast(const String& str, Int* pos, StringPosition start = StringEnd()) const;
/// Searches for the first occurrence of character 'ch' within a string.
/// @param[in] ch									The search character.
/// @param[out] pos								Pointer to be filled with the position where 'ch' was found. This parameter can be a nullptr. In case no occurence was found *pos is initialized with InvalidArrayIndex.
/// @param[in] start							Starting position within the current string to search from. If it is out of bounds the function will return false.
/// @return												True if 'ch' has been found, in that case *pos contains the position where the first occurance was found.
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type Find(Utf32Char ch, Int* pos, StringPosition start = 0) const;
/// Searches for the last occurrence of character 'ch' within a string.
/// @param[in] ch									The search character.
/// @param[out] pos								Pointer to be filled with the position where 'ch' was found. This parameter can be a nullptr. In case no occurence was found *pos is initialized with InvalidArrayIndex.
/// @param[in] start							Starting position within the current string to search from (backwards). The character at the given position will not be included in the search. If it is out of bounds the function will return false.
/// @return												True if 'ch' has been found, in that case *pos contains the position where the last occurance was found.
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type FindLast(Utf32Char ch, Int* pos, StringPosition start = StringEnd()) const;
/// Uppercase search for the first occurrence of 'str' within a string (which doesn't need to contain uppercase characters).
/// @param[in] str								The search string, must be completely uppercase, otherwise no matches will be found.
/// @param[out] pos								Pointer to be filled with the position where 'ch' was found. This parameter can be a nullptr. In case no occurence was found *pos is initialized with InvalidArrayIndex.
/// @param[in] start							Starting position within the current string to search from. If it is out of bounds the function will return false.
/// @return												True if 'str' has been found, in that case *pos contains the position where the first occurance was found.
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type FindUpper(const String& str, Int* pos, StringPosition start = 0) const;
/// Uppercase search for the last occurrence of 'str' within a string (which doesn't need to contain uppercase characters).
/// @param[in] str								The search string, must be completely uppercase, otherwise no matches will be found.
/// @param[out] pos								Pointer to be filled with the position where 'ch' was found. This parameter can be a nullptr. In case no occurence was found *pos is initialized with InvalidArrayIndex.
/// @param[in] start							Starting position within the current string to search from (backwards). The character at the given position will not be included in the search. If it is out of bounds the function will return false.
/// @return												True if 'str' has been found, in that case *pos contains the position where the last occurance was found.
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type FindLastUpper(const String& str, Int* pos, StringPosition start = StringEnd()) const;
/// Returns the string part left of the given position. The character at position will not be included.
/// @param[in] start							Partitioning position.
/// @return												The partial string, or empty string if 'start' was out of boundaries. Will be an empty reference on failure (apply iferr for error handling).
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<String>, String>::type GetLeftPart(StringPosition start) const;
/// Returns the string part right of the given position. The character at position will be included.
/// @param[in] start							Partitioning position.
/// @return												The partial string, or empty string if 'start' was out of boundaries. Will be an empty reference on failure (apply iferr for error handling).
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<String>, String>::type GetRightPart(StringPosition start) const;
/// Checks if the string starts with a certain character.
/// @param[in] ch									The character to be checked.
/// @return												True if the string starts with the given character.
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type StartsWith(Utf32Char ch) const;
/// Checks if the current string starts with a given string.
/// @param[in] str								The string part.
/// @return												True if the string starts with the string 'str'.
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type StartsWith(const String& str) const;
/// Checks if the string ends with a certain character.
/// @param[in] ch									The character to be checked.
/// @return												True if the string end with the given character.
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type EndsWith(Utf32Char ch) const;
/// Checks if the current string end with a given string.
/// @param[in] str								The string part.
/// @return												True if the string ends with the string 'str'.
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type EndsWith(const String& str) const;
/// Converts a unicode string to a 8-bit encoded character string and copies it into @p buffer.
/// The buffer size is taken into account.
/// @param[in,out] buffer					Block describing the buffer. A \0 byte will be appended to the string in any case.
/// @param[in] stringEncoding			Encoding for the string. By default UTF-8 is selected. If a nullptr is passed the data is truncated to Char and no conversion takes place.
/// @return												The length of the corresponding 8-bit string for the given encoding. The \0 byte is excluded.
		inline Result<Int> GetCStringBlock(const Block<Char>& buffer, const StringEncodingRef& stringEncoding = GetUtf8DefaultEncoder()) const;
/// Converts a unicode string to a 8-bit encoded character string and appends it to the given @p array.
/// @param[in,out] array					Array to be filled with the encoded string. The array is NOT terminated with a \0 byte.
/// @param[in] stringEncoding			Encoding for the string. By default UTF-8 is selected. If a nullptr is passed the data is truncated to Char and no conversion takes place.
/// @return												OK on success.
		inline Result<void> GetCStringAppendArray(const NonConstArray<Char>& array, const StringEncodingRef& stringEncoding = GetUtf8DefaultEncoder()) const;
/// Converts a unicode string to a 8-bit encoded character string and returns a new BaseArray<>.
/// @param[in] stringEncoding			Encoding for the string. By default UTF-8 is selected. If a nullptr is passed the data is truncated to Char and no conversion takes place.
/// @return												BaseArray<Char> with the encoded string. The string is \0 - terminated, but the array size is equal to the string length without the \0 character.
		inline Result<BaseArray<Char>> GetCString(const StringEncodingRef& stringEncoding = GetUtf8DefaultEncoder()) const;
/// Returns a copy of the string as a system-specific character array. The string will be \0 - terminated.
/// GetFirst() on that call always return a valid pointer, even if the string length is 0!
/// GetLength() returns the real string length without the trailing \0.
/// @code
/// SysCharArray converted = str.GetSystemEncoding() iferr_return;
/// @endcode
/// @return												A copy of the character string.
		inline Result<SysCharArray> GetSystemEncoding() const;
/// Copies the string as UTF-16 encoded characters into the passed array.
/// The array will be resized and contain the non \0 - terminated data.
/// @param[out] stringData				The array to receive the data.
/// @return												OK on success.
		inline Result<void> GetUtf16(Utf16CharBuffer& stringData) const;
/// @markInternal
/// Caches a static constant string and returns a maxon::String.
		static inline const String& GetAndCacheConstString(const wchar_t* chr, Int len);
/// @markInternal
/// Caches a static constant string and returns a maxon::String.
		static inline const String& GetAndCacheConstString(const Char* chr, Int len, Int isUtf8);
/// Returns the internal character array. Temporarily renamed.
/// @return												Block describing the internal character buffer. The data is read only! Please note that GetCount() will return the number of characters (and not bytes).
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<StridedBlock<const Generic>>, StridedBlock<const Generic>>::type GetVariableInternalData() const;
/// Retrieves the string's character width. The width determines the result of GetInternalDataX().
/// @return												1, 2 or 4 (bytes).
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type GetCharacterWidth() const;
/// Converts a string using a UTF32 -> UTF32 encoder or decoder (e.g. StringEncodings::Url32).
/// @param[in] converter					String encoder or decoder that should be applied to the conversion.
/// @return												The converted string.
		inline Result<String> ConvertString(const StreamConversionRef& converter) const;
	};
	/// Intermediate helper class for StringInterface.
	template <typename S> class ReferenceFunctionsImpl : public ConstReferenceFunctionsImpl<S>
	{
	public:
		ReferenceFunctionsImpl() = default;
		using PrivateBaseClass = ConstReferenceFunctionsImpl<S>;
		using PrivateBaseClass::PrivateBaseClass;
/// Initializes the string with a specific length and a default character.
/// @param[in] count							Number of characters of the new string.
/// @param[in] fillChar						Character to fill the string with.
/// @return												OK on success.
		inline Result<void> Init(Int count = 0, Utf32Char fillChar = 0) const;
/// Optimizes the memory usage. This can only be done if the string previously contained 16- or 32-bit Unicode characters that now have been removed or if the string was longer before.
/// @return												OK on success. Also returns OK if the string already is in its smallest state.
		inline Result<void> Shrink() const;
/// Concatenates 2 strings, use this operation instead of a = a + b as it is much faster.
/// @return												OK on success.
		inline Result<void> Append(const StringInterface* str) const;
/// Concatenates 2 strings of which the second is represented by len characters at
/// address str in memory.
/// @param[in] str								Character pointer.
/// @param[in] len								Number of characters.
/// @return												OK on success.
		inline Result<void> Append(const Utf32Char* str, Int len) const;
/// Appends a character to the current string.
/// @param[in] v									The character that will be added.
/// @return												OK on success.
		inline Result<void> AppendChar(Utf32Char v) const;
/// Erases a range of characters within a string.
/// @param[in] position						The starting position to delete 'count' characters. If the position is out of bounds an error will be returned.
/// @param[in] count							Number of characters to delete. If you want to delete all characters until the end pass StringEnd(). If the number is larger than what is available an error will be returned.
/// @return												OK on success.
		inline Result<void> Erase(StringPosition position, StringCount count) const;
/// Inserts a string at a specific position.
/// @param[in] position						Insert position in the current string. StringEnd() is a valid position. If the position is out of bounds an error is returned.
/// @param[in] str								String to be inserted.
/// @param[in] strStart						Starting position of the string to be inserted. If the position is out of bounds an error is returned.
/// @param[in] strCount						Number of characters to be inserted. If the number of characters is too large an error is returned.
/// @return												OK on success.
		inline Result<void> Insert(StringPosition position, const StringInterface* str, StringPosition strStart = 0, StringCount strCount = StringEnd()) const;
/// Inserts a single unicode character at a specific position.
/// @param[in] position						Insert position, needs to be within boundaries.
/// @param[in] ch									Unicode character to insert.
/// @return												OK on success.
		inline Result<void> Insert(StringPosition position, Utf32Char ch) const;
/// Appends a number to the current string.
/// @param[in] v									The number that will be added.
/// @return												The current string. Will be an empty reference if AppendInt fails (apply iferr for error handling).
		inline DOXYGEN_SWITCH(maxon::RefMemberType<S const>, S) AppendInt(Int32 v) const;
/// Appends a number to the current string.
/// @param[in] v									The number that will be added.
/// @return												The current string. Will be an empty reference if AppendUInt fails (apply iferr for error handling).
		inline DOXYGEN_SWITCH(maxon::RefMemberType<S const>, S) AppendUInt(UInt32 v) const;
/// Appends a number to the current string.
/// @param[in] v									The number that will be added.
/// @return												The current string. Will be an empty reference if AppendInt fails (apply iferr for error handling).
		inline DOXYGEN_SWITCH(maxon::RefMemberType<S const>, S) AppendInt(Int64 v) const;
/// Appends a number to the current string.
/// @param[in] v									The number that will be added.
/// @return												The current string. Will be an empty reference if AppendUInt fails (apply iferr for error handling).
		inline DOXYGEN_SWITCH(maxon::RefMemberType<S const>, S) AppendUInt(UInt64 v) const;
/// Removes all characters with value <= 0x20 (e.g. space, tab, line feed) at the beginning of the string.
/// @return												OK on success.
		inline Result<void> TrimLeft() const;
/// Removes all characters with value <= 0x20 (e.g. space, tab, line feed) at the end of the string.
/// @return												OK on success.
		inline Result<void> TrimRight() const;
/// Replaces all occurrences of the character 'find' in the current string with the given character 'replace'.
/// @param[in] find								Search character. Each occurrence will be replaced with 'replace'.
/// @param[in] replace						Replacement of 'find'.
/// @return												Number of replaced characters.
		inline Result<Int> Replace(Utf32Char find, Utf32Char replace) const;
/// Replaces all occurrences of string 'find' in the current string with the given string 'replace'.
/// @param[in] find								Search string. Each occurrence will be replaced with 'replace'.
/// @param[in] replace						Replacement of 'find'. Can be an empty string, in which case all 'find' strings will be removed.
/// @return												Number of replaced strings.
		inline Result<Int> Replace(const String& find, const String& replace) const;
/// Replaces all occurrences of the character 'find' in the current string with the given string 'replace'.
/// @param[in] find								Search character. Each occurrence will be replaced with 'replace'.
/// @param[in] replace						Replacement of 'find'. Can be an empty string, in which case all 'find' characters will be removed.
/// @return												Number of replaced strings.
		inline Result<Int> Replace(Utf32Char find, const String& replace) const;
/// Removes all characters with value <= 0x20 (e.g. space, tab, line feed) at the beginning and the end of the string.
/// @return												OK on success.
		inline Result<void> Trim() const;
/// Initializes the string with a given 8-bit Char string with the given encoding.
/// @param[out] buffer						Pointer to the 8-bit character string.
/// @param[in] count							Number of valid characters in the buffer, a value of -1 automatically detects the
/// 															string length by searching for the first \0 character, otherwise count is relevant and not \0.
/// @param[in] stringDecoding			DECODING for the string. By default UTF-8 is selected. If a nullptr is passed the data is copied 1:1.
/// @return												OK on success.
		inline Result<void> SetCString(const Char* buffer, Int count = -1, const StringDecodingRef& stringDecoding = GetUtf8DefaultDecoder()) const;
/// Initializes the string with a given 8-bit Char string with the given encoding.
/// @param[out] buffer						Block with an 8-bit character string.
/// @param[in] stringDecoding			DECODING for the string. By default UTF-8 is selected. If a nullptr is passed the data is copied 1:1.
/// @return												OK on success.
		inline Result<void> SetCString(const Block<const Char>& buffer, const StringDecodingRef& stringDecoding = GetUtf8DefaultDecoder()) const;
/// Initializes the String with the given system-specific character string.
/// @param[in] buffer							Pointer to the buffer with the string.
/// @param[in] count							Number of valid characters in the buffer.
/// 															A count of -1 calculates the string length automatically, terminating when \0 is found.
/// @return												OK on success.
		inline Result<void> SetSystemEncoding(const SysChar* buffer, Int count = -1) const;
/// Initializes the String with the given 32-bit unicode character string.
/// @param[in] buffer							Pointer to the buffer with the string.
/// @param[in] count							Number of valid characters in the buffer.
/// 															A count of -1 calculates the string length automatically, terminating when \0 is found.
/// @return												OK on success.
		inline Result<void> SetUtf32(const Utf32Char* buffer, Int count = -1) const;
/// Initializes the String with the given 16-bit unicode character string.
/// @param[in] buffer							Pointer to the buffer with the string.
/// @param[in] count							Number of valid characters in the buffer.
/// 															A count of -1 calculates the string length automatically, terminating when \0 is found.
/// @return												OK on success.
		inline Result<void> SetUtf16(const Utf16Char* buffer, Int count = -1) const;
	};
	/// Intermediate helper class for StringInterface.
	template <typename S> class COWReferenceFunctionsImpl : public ConstReferenceFunctionsImpl<S>
	{
	public:
		COWReferenceFunctionsImpl() = default;
		using PrivateBaseClass = ConstReferenceFunctionsImpl<S>;
		using PrivateBaseClass::PrivateBaseClass;
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongCOWRefHandler, String, false>::type&() const { return reinterpret_cast<const String&>(this->GetBaseRef()); }
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongCOWRefHandler, String, false>::type&() { return reinterpret_cast<const String&>(this->GetBaseRef()); }
/// Initializes the string with a specific length and a default character.
/// @param[in] count							Number of characters of the new string.
/// @param[in] fillChar						Character to fill the string with.
/// @return												OK on success.
		inline Result<void> Init(Int count = 0, Utf32Char fillChar = 0);
/// Optimizes the memory usage. This can only be done if the string previously contained 16- or 32-bit Unicode characters that now have been removed or if the string was longer before.
/// @return												OK on success. Also returns OK if the string already is in its smallest state.
		inline Result<void> Shrink();
/// Concatenates 2 strings, use this operation instead of a = a + b as it is much faster.
/// @return												OK on success.
		inline Result<void> Append(const StringInterface* str);
/// Concatenates 2 strings of which the second is represented by len characters at
/// address str in memory.
/// @param[in] str								Character pointer.
/// @param[in] len								Number of characters.
/// @return												OK on success.
		inline Result<void> Append(const Utf32Char* str, Int len);
/// Appends a character to the current string.
/// @param[in] v									The character that will be added.
/// @return												OK on success.
		inline Result<void> AppendChar(Utf32Char v);
/// Erases a range of characters within a string.
/// @param[in] position						The starting position to delete 'count' characters. If the position is out of bounds an error will be returned.
/// @param[in] count							Number of characters to delete. If you want to delete all characters until the end pass StringEnd(). If the number is larger than what is available an error will be returned.
/// @return												OK on success.
		inline Result<void> Erase(StringPosition position, StringCount count);
/// Inserts a string at a specific position.
/// @param[in] position						Insert position in the current string. StringEnd() is a valid position. If the position is out of bounds an error is returned.
/// @param[in] str								String to be inserted.
/// @param[in] strStart						Starting position of the string to be inserted. If the position is out of bounds an error is returned.
/// @param[in] strCount						Number of characters to be inserted. If the number of characters is too large an error is returned.
/// @return												OK on success.
		inline Result<void> Insert(StringPosition position, const StringInterface* str, StringPosition strStart = 0, StringCount strCount = StringEnd());
/// Inserts a single unicode character at a specific position.
/// @param[in] position						Insert position, needs to be within boundaries.
/// @param[in] ch									Unicode character to insert.
/// @return												OK on success.
		inline Result<void> Insert(StringPosition position, Utf32Char ch);
/// Appends a number to the current string.
/// @param[in] v									The number that will be added.
/// @return												The current string. Will be an empty reference if AppendInt fails (apply iferr for error handling).
		inline DOXYGEN_SWITCH(maxon::RefMemberType<S>, S) AppendInt(Int32 v);
/// Appends a number to the current string.
/// @param[in] v									The number that will be added.
/// @return												The current string. Will be an empty reference if AppendUInt fails (apply iferr for error handling).
		inline DOXYGEN_SWITCH(maxon::RefMemberType<S>, S) AppendUInt(UInt32 v);
/// Appends a number to the current string.
/// @param[in] v									The number that will be added.
/// @return												The current string. Will be an empty reference if AppendInt fails (apply iferr for error handling).
		inline DOXYGEN_SWITCH(maxon::RefMemberType<S>, S) AppendInt(Int64 v);
/// Appends a number to the current string.
/// @param[in] v									The number that will be added.
/// @return												The current string. Will be an empty reference if AppendUInt fails (apply iferr for error handling).
		inline DOXYGEN_SWITCH(maxon::RefMemberType<S>, S) AppendUInt(UInt64 v);
/// Removes all characters with value <= 0x20 (e.g. space, tab, line feed) at the beginning of the string.
/// @return												OK on success.
		inline Result<void> TrimLeft();
/// Removes all characters with value <= 0x20 (e.g. space, tab, line feed) at the end of the string.
/// @return												OK on success.
		inline Result<void> TrimRight();
/// Replaces all occurrences of the character 'find' in the current string with the given character 'replace'.
/// @param[in] find								Search character. Each occurrence will be replaced with 'replace'.
/// @param[in] replace						Replacement of 'find'.
/// @return												Number of replaced characters.
		inline Result<Int> Replace(Utf32Char find, Utf32Char replace);
/// Replaces all occurrences of string 'find' in the current string with the given string 'replace'.
/// @param[in] find								Search string. Each occurrence will be replaced with 'replace'.
/// @param[in] replace						Replacement of 'find'. Can be an empty string, in which case all 'find' strings will be removed.
/// @return												Number of replaced strings.
		inline Result<Int> Replace(const String& find, const String& replace);
/// Replaces all occurrences of the character 'find' in the current string with the given string 'replace'.
/// @param[in] find								Search character. Each occurrence will be replaced with 'replace'.
/// @param[in] replace						Replacement of 'find'. Can be an empty string, in which case all 'find' characters will be removed.
/// @return												Number of replaced strings.
		inline Result<Int> Replace(Utf32Char find, const String& replace);
/// Removes all characters with value <= 0x20 (e.g. space, tab, line feed) at the beginning and the end of the string.
/// @return												OK on success.
		inline Result<void> Trim();
/// Initializes the string with a given 8-bit Char string with the given encoding.
/// @param[out] buffer						Pointer to the 8-bit character string.
/// @param[in] count							Number of valid characters in the buffer, a value of -1 automatically detects the
/// 															string length by searching for the first \0 character, otherwise count is relevant and not \0.
/// @param[in] stringDecoding			DECODING for the string. By default UTF-8 is selected. If a nullptr is passed the data is copied 1:1.
/// @return												OK on success.
		inline Result<void> SetCString(const Char* buffer, Int count = -1, const StringDecodingRef& stringDecoding = GetUtf8DefaultDecoder());
/// Initializes the string with a given 8-bit Char string with the given encoding.
/// @param[out] buffer						Block with an 8-bit character string.
/// @param[in] stringDecoding			DECODING for the string. By default UTF-8 is selected. If a nullptr is passed the data is copied 1:1.
/// @return												OK on success.
		inline Result<void> SetCString(const Block<const Char>& buffer, const StringDecodingRef& stringDecoding = GetUtf8DefaultDecoder());
/// Initializes the String with the given system-specific character string.
/// @param[in] buffer							Pointer to the buffer with the string.
/// @param[in] count							Number of valid characters in the buffer.
/// 															A count of -1 calculates the string length automatically, terminating when \0 is found.
/// @return												OK on success.
		inline Result<void> SetSystemEncoding(const SysChar* buffer, Int count = -1);
/// Initializes the String with the given 32-bit unicode character string.
/// @param[in] buffer							Pointer to the buffer with the string.
/// @param[in] count							Number of valid characters in the buffer.
/// 															A count of -1 calculates the string length automatically, terminating when \0 is found.
/// @return												OK on success.
		inline Result<void> SetUtf32(const Utf32Char* buffer, Int count = -1);
/// Initializes the String with the given 16-bit unicode character string.
/// @param[in] buffer							Pointer to the buffer with the string.
/// @param[in] count							Number of valid characters in the buffer.
/// 															A count of -1 calculates the string length automatically, terminating when \0 is found.
/// @return												OK on success.
		inline Result<void> SetUtf16(const Utf16Char* buffer, Int count = -1);
	};
	template <typename ST> struct ReferenceFunctionsHelper : public std::conditional<maxon::Bool(ST::type::Handler::KIND & (maxon::VALUEKIND::COW_MASK | maxon::VALUEKIND::DEEP_CONSTNESS)), COWReferenceFunctionsImpl<typename ST::type>, typename std::conditional<std::is_const<typename ST::type::PrivateReferencedType>::value, ConstReferenceFunctionsImpl<typename ST::type>, ReferenceFunctionsImpl<typename ST::type>>::type> { };
};
class StringInterface::Reference :
#ifdef DOXYGEN
public COWReferenceFunctionsImplDoxy<String>
#else
public maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<const StringInterface, maxon::StrongCOWRefHandler, String>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(Reference, maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<const StringInterface, maxon::StrongCOWRefHandler, String>>>>);
	using NonConst = Hxx1::NonConstRef;
	static MAXON_ATTRIBUTE_FORCE_INLINE maxon::ResultMemT<String> Create();
};

class StringInterface::Hxx1::NonConstRef :
#ifdef DOXYGEN
public ReferenceFunctionsImplDoxy<NonConstRef>
#else
public maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<StringInterface, maxon::StrongRefHandler, NonConstRef>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(NonConstRef, maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<StringInterface, maxon::StrongRefHandler, NonConstRef>>>>);
};

class CString;

template <> MAXON_ATTRIBUTE_FORCE_INLINE auto StringTemplate<CStringInterface,CString,Char>::GetLength() const -> Int;
template <> MAXON_ATTRIBUTE_FORCE_INLINE auto StringTemplate<CStringInterface,CString,Char>::Init(Int count, Char fillChar) -> Result<void>;
template <> MAXON_ATTRIBUTE_FORCE_INLINE auto StringTemplate<CStringInterface,CString,Char>::Shrink() -> Result<void>;
template <> MAXON_ATTRIBUTE_FORCE_INLINE auto StringTemplate<CStringInterface,CString,Char>::Append(const CStringInterface* str) -> Result<void>;
template <> MAXON_ATTRIBUTE_FORCE_INLINE auto StringTemplate<CStringInterface,CString,Char>::Append(const Char* str, Int len) -> Result<void>;
template <> MAXON_ATTRIBUTE_FORCE_INLINE auto StringTemplate<CStringInterface,CString,Char>::FindIndex(const CStringInterface* str, StringPosition start) const -> Int;
template <> MAXON_ATTRIBUTE_FORCE_INLINE auto StringTemplate<CStringInterface,CString,Char>::FindLastIndex(const CStringInterface* str, StringPosition start) const -> Int;
template <> MAXON_ATTRIBUTE_FORCE_INLINE auto StringTemplate<CStringInterface,CString,Char>::FindIndex(Char ch, StringPosition start) const -> Int;
template <> MAXON_ATTRIBUTE_FORCE_INLINE auto StringTemplate<CStringInterface,CString,Char>::FindLastIndex(Char ch, StringPosition start) const -> Int;
template <> MAXON_ATTRIBUTE_FORCE_INLINE auto StringTemplate<CStringInterface,CString,Char>::FindUpperIndex(const CStringInterface* str, StringPosition start) const -> Int;
template <> MAXON_ATTRIBUTE_FORCE_INLINE auto StringTemplate<CStringInterface,CString,Char>::FindLastUpperIndex(const CStringInterface* str, StringPosition start) const -> Int;
template <> MAXON_ATTRIBUTE_FORCE_INLINE auto StringTemplate<CStringInterface,CString,Char>::Erase(StringPosition position, StringCount count) -> Result<void>;
template <> MAXON_ATTRIBUTE_FORCE_INLINE auto StringTemplate<CStringInterface,CString,Char>::Insert(StringPosition position, const CStringInterface* str, StringPosition strStart, StringCount strCount) -> Result<void>;
template <> MAXON_ATTRIBUTE_FORCE_INLINE auto StringTemplate<CStringInterface,CString,Char>::Insert(StringPosition position, Char ch) -> Result<void>;
template <> MAXON_ATTRIBUTE_FORCE_INLINE auto StringTemplate<CStringInterface,CString,Char>::GetPart(StringPosition start, StringCount count) const -> CStringInterface*;
template <> MAXON_ATTRIBUTE_FORCE_INLINE auto StringTemplate<CStringInterface,CString,Char>::ToUpper() const -> CStringInterface*;
template <> MAXON_ATTRIBUTE_FORCE_INLINE auto StringTemplate<CStringInterface,CString,Char>::ToLower() const -> CStringInterface*;
template <> MAXON_ATTRIBUTE_FORCE_INLINE auto StringTemplate<CStringInterface,CString,Char>::ComparePart(const CStringInterface* str, STRINGCOMPARISON mode, StringPosition position, StringCount count) const -> COMPARERESULT;
template <> MAXON_ATTRIBUTE_FORCE_INLINE auto StringTemplate<CStringInterface,CString,Char>::GetHashCode() const -> UInt;
template <> MAXON_ATTRIBUTE_FORCE_INLINE auto StringTemplate<CStringInterface,CString,Char>::SetChar(Int pos, Char ch) -> void;
template <> MAXON_ATTRIBUTE_FORCE_INLINE auto StringTemplate<CStringInterface,CString,Char>::GetChar(Int pos) const -> Char;
template <> MAXON_ATTRIBUTE_FORCE_INLINE auto StringTemplate<CStringInterface,CString,Char>::GetUtf32(Utf32CharBuffer& stringData) const -> Result<void>;
template <> MAXON_ATTRIBUTE_FORCE_INLINE auto StringTemplate<CStringInterface,CString,Char>::TrimLeft() -> Result<void>;
template <> MAXON_ATTRIBUTE_FORCE_INLINE auto StringTemplate<CStringInterface,CString,Char>::TrimRight() -> Result<void>;
template <> MAXON_ATTRIBUTE_FORCE_INLINE auto StringTemplate<CStringInterface,CString,Char>::Split(const CString& splitSymbol, Bool trim, const ValueReceiver<const CString&>& parts) const -> Result<void>;
template <> MAXON_ATTRIBUTE_FORCE_INLINE auto StringTemplate<CStringInterface,CString,Char>::Replace(Char find, Char replace) -> Result<Int>;
template <> MAXON_ATTRIBUTE_FORCE_INLINE auto StringTemplate<CStringInterface,CString,Char>::Replace(const CString& find, const CString& replace) -> Result<Int>;
template <> MAXON_ATTRIBUTE_FORCE_INLINE auto StringTemplate<CStringInterface,CString,Char>::Replace(Char find, const CString& replace) -> Result<Int>;
struct CStringInterface::Hxx1
{
	class NonConstRef;
	using ReferenceClass = CString;
	/// Intermediate helper class for CStringInterface.
	template <typename S> class ConstReferenceFunctionsImpl DOXYGEN_SWITCH(: public S,)
	{
	public:
		ConstReferenceFunctionsImpl() = default;
		using PrivateBaseClass = S;
		using PrivateBaseClass::PrivateBaseClass;
/// Returns the length (number of elements) of the string, not the size of the block.
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type GetLength() const;
/// Searches for the first occurrence of 'str' within a string.
/// @param[in] str								The search string.
/// @param[in] start							Starting position within the current string to search from. If it is out of bounds the function will return InvalidArrayIndex.
/// @return												The index at which 'str' has been found or InvalidArrayIndex.
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type FindIndex(const CStringInterface* str, StringPosition start = 0) const;
/// Searches for the last occurrence of 'str' within a string.
/// @param[in] str								The search string.
/// @param[in] start							Starting position within the current string to search from (backwards). The character at the given position will not be included in the search. If it is out of bounds the function will return InvalidArrayIndex.
/// @return												The index at which 'str' has been found or InvalidArrayIndex.
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type FindLastIndex(const CStringInterface* str, StringPosition start = StringEnd()) const;
/// Searches for the first occurrence of character 'ch' within a string.
/// @param[in] ch									The search character.
/// @param[in] start							Starting position within the current string to search from. If it is out of bounds the function will return InvalidArrayIndex.
/// @return												The index at which 'ch' has been found or InvalidArrayIndex.
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type FindIndex(Char ch, StringPosition start = 0) const;
/// Searches for the last occurrence of character 'ch' within a string.
/// @param[in] ch									The search character.
/// @param[in] start							Starting position within the current string to search from (backwards). The character at the given position will not be included in the search. If it is out of bounds the function will return InvalidArrayIndex.
/// @return												The index at which 'ch' has been found or InvalidArrayIndex.
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type FindLastIndex(Char ch, StringPosition start = StringEnd()) const;
/// Uppercase search for the first occurrence of 'str' within a string (which doesn't need to contain uppercase characters).
/// @param[in] str								The search string, must be completely uppercase, otherwise no matches will be found.
/// @param[in] start							Starting position within the current string to search from. If it is out of bounds the function will return InvalidArrayIndex.
/// @return												The index at which 'str' has been found or InvalidArrayIndex.
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type FindUpperIndex(const CStringInterface* str, StringPosition start = 0) const;
/// Uppercase search for the last occurrence of 'str' within a string (which doesn't need to contain uppercase characters).
/// @param[in] str								The search string, must be completely uppercase, otherwise no matches will be found.
/// @param[in] start							Starting position within the current string to search from (backwards). The character at the given position will not be included in the search. If it is out of bounds the function will return InvalidArrayIndex.
/// @return												The index at which 'str' has been found or InvalidArrayIndex.
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type FindLastUpperIndex(const CStringInterface* str, StringPosition start = StringEnd()) const;
/// Creates a part of the current string.
/// @param[in] start							Position where the new partial string will start.
/// @param[in] count							Number of characters for the partial string. If it is larger than the number of available characters an empty string will be returned.
/// @return												The partial string, or empty string if 'start' was out of boundaries. Will be an empty reference if GetPart fails (apply iferr for error handling).
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<CString>, CString>::type GetPart(StringPosition start, StringCount count) const;
/// Returns the uppercase version of a string.
/// @return												Uppercase version of a string. Will be an empty reference if ToUpper fails (apply iferr for error handling).
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<CString>, CString>::type ToUpper() const;
/// Returns the lowercase version of a string.
/// @return												Lowercase version of a string. Will be an empty reference if ToLower fails (apply iferr for error handling).
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<CString>, CString>::type ToLower() const;
/// Compares a part of this against 'str' for exact match.
/// Example:
/// @code
/// "abcdefghijk"_s.ComparePart("bcd"_s,STRINGCOMPARISON::MEMORY,1,3);
/// @endcode
/// returns COMPARESTRING::EQUAL for matching "bcd"
/// @param[in] str								Comparison object.
/// @param[in] mode								Comparison mode.
/// @param[in] position						Starting position in the current string that 'str' will be compared against. The interval [position..count] will be clipped against valid boundaries.
/// @param[in] count							Number of characters in the current string that 'str' will be compared against. count can be longer than the string length and will be clipped accordingly.
/// @return												See COMPARERESULT.
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<COMPARERESULT>, COMPARERESULT>::type ComparePart(const CStringInterface* str, STRINGCOMPARISON mode, StringPosition position, StringCount count) const;
/// Compares the object against 'str' for exact match.
/// @param[in] str								Comparison object.
/// @param[in] mode								Comparison mode.
/// @return												See COMPARERESULT.
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<COMPARERESULT>, COMPARERESULT>::type Compare(const CStringInterface* str, STRINGCOMPARISON mode = STRINGCOMPARISON::UNICODE_NUMBERS) const;
/// Compare strings for equality.
/// @return												True if equal.
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type IsEqual(const CStringInterface* str) const;
/// Converts a string to a 64-bit floating point value.
/// This routine does no formula parsing.
/// While leading whitespaces are allowed by default no trailing characters of any kind are allowed.
/// @param[in] flags							Optional flags for the conversion.
/// @return												Floating point value of the string.
		inline Result<Float64> ToFloat64(STRINGCONVERSION flags = STRINGCONVERSION::NONE) const;
/// Converts a string to a 32-bit floating point value.
/// This routine does no formula parsing.
/// While leading whitespaces are allowed by default no trailing characters of any kind are allowed.
/// @param[in] flags							Optional flags for the conversion.
/// @return												Floating point value of the string.
		inline Result<Float32> ToFloat32(STRINGCONVERSION flags = STRINGCONVERSION::NONE) const;
/// Converts a string to a floating point value.
/// This routine does no formula parsing.
/// While leading whitespaces are allowed by default no trailing characters of any kind are allowed.
/// @param[in] flags							Optional flags for the conversion.
/// @return												Floating point value of the string.
		inline Result<Float> ToFloat(STRINGCONVERSION flags = STRINGCONVERSION::NONE) const;
/// Converts a string to a 64 bit integer value.
/// This routine does no formula parsing and does not support any suffixes/prefixes except for 0x (hexadecimal numbers).
/// While leading whitespaces are allowed by default no trailing characters of any kind are allowed.
/// @param[in] flags							Optional flags for the conversion.
/// @return												Integer value of the string.
		inline Result<Int64> ToInt64(STRINGCONVERSION flags = STRINGCONVERSION::NONE) const;
/// Converts a string to a 32 bit integer value.
/// This routine does no formula parsing and does not support any suffixes/prefixes except for 0x (hexadecimal numbers).
/// While leading whitespaces are allowed by default no trailing characters of any kind are allowed.
/// @param[in] flags							Optional flags for the conversion.
/// @return												Integer value of the string.
		inline Result<Int32> ToInt32(STRINGCONVERSION flags = STRINGCONVERSION::NONE) const;
/// Converts a string to an integer value.
/// This routine does no formula parsing and does not support any suffixes/prefixes except for 0x (hexadecimal numbers).
/// While leading whitespaces are allowed by default no trailing characters of any kind are allowed.
/// @param[in] flags							Optional flags for the conversion.
/// @return												Integer value of the string.
		inline Result<Int> ToInt(STRINGCONVERSION flags = STRINGCONVERSION::NONE) const;
/// Converts a string to a 64 bit unsigned integer value.
/// This routine does no formula parsing and does not support any suffixes/prefixes except for 0x (hexadecimal numbers).
/// While leading whitespaces are allowed by default no trailing characters of any kind are allowed.
/// @param[in] flags							Optional flags for the conversion.
/// @return												Integer value of the string.
		inline Result<UInt64> ToUInt64(STRINGCONVERSION flags = STRINGCONVERSION::NONE) const;
/// Converts a string to a 32 bit unsigned integer value.
/// This routine does no formula parsing and does not support any suffixes/prefixes except for 0x (hexadecimal numbers).
/// While leading whitespaces are allowed by default no trailing characters of any kind are allowed.
/// @param[in] flags							Optional flags for the conversion.
/// @return												Integer value of the string.
		inline Result<UInt32> ToUInt32(STRINGCONVERSION flags = STRINGCONVERSION::NONE) const;
/// Converts a string to an unsigned integer value.
/// This routine does no formula parsing and does not support any suffixes/prefixes except for 0x (hexadecimal numbers).
/// While leading whitespaces are allowed by default no trailing characters of any kind are allowed.
/// @param[in] flags							Optional flags for the conversion.
/// @return												Integer value of the string.
		inline Result<UInt> ToUInt(STRINGCONVERSION flags = STRINGCONVERSION::NONE) const;
/// Converts a floating point value into formatted text.
/// @param[in] value							Floating point value to convert into text.
/// @param[in] charsBeforeComma		Characters before the decimal point. If STRING_DYNAMIC_DIGITS is passed or 'charsBeforeComma' is too low to represent 'value' it is automatically increased/adjusted. If 'charsBeforeComma' is positive and exponent is false fill characters will be added to the beginning. If STRING_MAXIMUM_PRECISION is passed, then the result will be an exact representation of the value (possibly using exponential notation).
/// @param[in] digitsAfterComma		Digits after the decimal point. If a negative number is passed the number of digits is automatically chosen and up to (-digitsAfterComma).
/// @param[in] exponent						Force exponential-style output (e.g. 1.0e+10).
/// @param[in] fillChar						Fill character for digits before the decimal point. E.g. if you specify 4 for charsBeforeComma, '*' for fillChar and your value is 1.5 you'll get ***1.5 as a result. This value has no impact if exponent is true.
/// @return												String object with the decimal text of the value.
		static inline CString FloatToString(Float32 value, Int charsBeforeComma = STRING_DYNAMIC_DIGITS, Int digitsAfterComma = -3, Bool exponent = false, Char fillChar = ' ');
/// Converts a floating point value into formatted text.
/// @param[in] value							Floating point value to convert into text.
/// @param[in] charsBeforeComma		Characters before the decimal point. If STRING_DYNAMIC_DIGITS is passed or 'charsBeforeComma' is too low to represent 'value' it is automatically increased/adjusted. If 'charsBeforeComma' is positive and exponent is false fill characters will be added to the beginning. If STRING_MAXIMUM_PRECISION is passed, then the result will be an exact representation of the value (possibly using exponential notation).
/// @param[in] digitsAfterComma		Digits after the decimal point. If a negative number is passed the number of digits is automatically chosen and up to (-digitsAfterComma).
/// @param[in] exponent						Force exponential-style output (e.g. 1.0e+10).
/// @param[in] fillChar						Fill character for digits before the decimal point. E.g. if you specify 4 for charsBeforeComma, '*' for fillChar and your value is 1.5 you'll get ***1.5 as a result. This value has no impact if exponent is true.
/// @return												String object with the decimal text of the value.
		static inline CString FloatToString(Float64 value, Int charsBeforeComma = STRING_DYNAMIC_DIGITS, Int digitsAfterComma = -3, Bool exponent = false, Char fillChar = ' ');
/// Formats a Int32 value as decimal text.
/// @param[in] v									Int32 value.
/// @return												String object with the decimal text of the value. Will be an empty reference on failure (apply iferr for error handling).
		static inline CString IntToString(Int32 v);
/// Formats a UInt32 value as decimal text.
/// @param[in] v									UInt32 value.
/// @return												String object with the decimal text of the value. Will be an empty reference on failure (apply iferr for error handling).
		static inline CString UIntToString(UInt32 v);
/// Formats a Int64 value as decimal text.
/// @param[in] v									Int64 value.
/// @return												String object with the decimal text of the value. Will be an empty reference on failure (apply iferr for error handling).
		static inline CString IntToString(Int64 v);
/// Formats a UInt64 value as decimal text.
/// @param[in] v									Int64 value.
/// @return												String object with the decimal text of the value. Will be an empty reference on failure (apply iferr for error handling).
		static inline CString UIntToString(UInt64 v);
/// Formats a Int64 value as a memory information.
/// @param[in] v									The size of bytes that should be formated as memory text.
/// @param[in] mebibytes					defines if a value of 1343443 is either output as "1.28 MiB" (mebibytes) or "1.34 MB" (megabytes).
/// @return												String object for the given mem value.
		static inline CString MemorySizeToString(Int64 v, Bool mebibytes = true);
/// Formats a Int32 value as hexadecimal text.
/// @param[in] v									Int32 value.
/// @param[in] prefix0x						Start the string with 0x as prefix.
/// @return												String object with the hexadecimal text of the value.
		static inline CString HexToString(UInt32 v, Bool prefix0x = true);
/// Formats a Int64 value as hexadecimal text.
/// @param[in] v									Int64 value.
/// @param[in] prefix0x						Start the string with 0x as prefix.
/// @return												String object with the hexadecimal text of the value.
		static inline CString HexToString(UInt64 v, Bool prefix0x = true);
/// Formats a pointer as hexadecimal text. The pointer starts with 0x prefix.
/// @param[in] v									Pointer to convert.
/// @return												String object with the hexadecimal text of the value.
		static inline CString PointerToString(const void* v);
/// Copies the string as UTF-32 encoded characters into the passed array.
/// The array will be resized and contain the non \0 - terminated data.
/// @param[out] stringData				The array to receive the data.
/// @return												OK on success.
		inline Result<void> GetUtf32(Utf32CharBuffer& stringData) const;
/// Splits the string into parts separated by the split symbol (e.g. a comma).
/// @param[in] splitSymbol				String containing the split symbol.
/// @param[in] trim								If true each separated part will be trimmed (see Trim).
/// @param[out] parts							Array to be filled with the separated strings.
/// @return												OK on success.
		inline Result<void> Split(const CString& splitSymbol, Bool trim, const ValueReceiver<const CString&>& parts) const;
/// Searches for the first occurrence of 'str' within a string.
/// @param[in] str								The search string.
/// @param[out] pos								Pointer to be filled with the position where 'str' was found. This parameter can be a nullptr. In case no occurence was found *pos is initialized with InvalidArrayIndex.
/// @param[in] start							Starting position within the current string to search from. If it is out of bounds the function will return false.
/// @return												True if 'str' has been found, in that case *pos contains the position where the first occurance was found.
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type Find(const CString& str, Int* pos, StringPosition start = 0) const;
/// Searches for the last occurrence of 'str' within a string.
/// @param[in] str								The search string.
/// @param[out] pos								Pointer to be filled with the position where 'str' was found. This parameter can be a nullptr. In case no occurence was found *pos is initialized with InvalidArrayIndex.
/// @param[in] start							Starting position within the current string to search from (backwards). The character at the given position will not be included in the search. If it is out of bounds the function will return false.
/// @return												True if 'str' has been found, in that case *pos contains the position where the last occurance was found.
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type FindLast(const CString& str, Int* pos, StringPosition start = StringEnd()) const;
/// Searches for the first occurrence of character 'ch' within a string.
/// @param[in] ch									The search character.
/// @param[out] pos								Pointer to be filled with the position where 'ch' was found. This parameter can be a nullptr. In case no occurence was found *pos is initialized with InvalidArrayIndex.
/// @param[in] start							Starting position within the current string to search from. If it is out of bounds the function will return false.
/// @return												True if 'ch' has been found, in that case *pos contains the position where the first occurance was found.
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type Find(Char ch, Int* pos, StringPosition start = 0) const;
/// Searches for the last occurrence of character 'ch' within a string.
/// @param[in] ch									The search character.
/// @param[out] pos								Pointer to be filled with the position where 'ch' was found. This parameter can be a nullptr. In case no occurence was found *pos is initialized with InvalidArrayIndex.
/// @param[in] start							Starting position within the current string to search from (backwards). The character at the given position will not be included in the search. If it is out of bounds the function will return false.
/// @return												True if 'ch' has been found, in that case *pos contains the position where the last occurance was found.
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type FindLast(Char ch, Int* pos, StringPosition start = StringEnd()) const;
/// Uppercase search for the first occurrence of 'str' within a string (which doesn't need to contain uppercase characters).
/// @param[in] str								The search string, must be completely uppercase, otherwise no matches will be found.
/// @param[out] pos								Pointer to be filled with the position where 'ch' was found. This parameter can be a nullptr. In case no occurence was found *pos is initialized with InvalidArrayIndex.
/// @param[in] start							Starting position within the current string to search from. If it is out of bounds the function will return false.
/// @return												True if 'str' has been found, in that case *pos contains the position where the first occurance was found.
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type FindUpper(const CString& str, Int* pos, StringPosition start = 0) const;
/// Uppercase search for the last occurrence of 'str' within a string (which doesn't need to contain uppercase characters).
/// @param[in] str								The search string, must be completely uppercase, otherwise no matches will be found.
/// @param[out] pos								Pointer to be filled with the position where 'ch' was found. This parameter can be a nullptr. In case no occurence was found *pos is initialized with InvalidArrayIndex.
/// @param[in] start							Starting position within the current string to search from (backwards). The character at the given position will not be included in the search. If it is out of bounds the function will return false.
/// @return												True if 'str' has been found, in that case *pos contains the position where the last occurance was found.
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type FindLastUpper(const CString& str, Int* pos, StringPosition start = StringEnd()) const;
/// Returns the string part left of the given position. The character at position will not be included.
/// @param[in] start							Partitioning position.
/// @return												The partial string, or empty string if 'start' was out of boundaries. Will be an empty reference on failure (apply iferr for error handling).
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<CString>, CString>::type GetLeftPart(StringPosition start) const;
/// Returns the string part right of the given position. The character at position will be included.
/// @param[in] start							Partitioning position.
/// @return												The partial string, or empty string if 'start' was out of boundaries. Will be an empty reference on failure (apply iferr for error handling).
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<CString>, CString>::type GetRightPart(StringPosition start) const;
/// Checks if the string starts with a certain character.
/// @param[in] ch									The character to be checked.
/// @return												True if the string starts with the given character.
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type StartsWith(Char ch) const;
/// Checks if the current string starts with a given string.
/// @param[in] str								The string part.
/// @return												True if the string starts with the string 'str'.
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type StartsWith(const CString& str) const;
/// Checks if the string ends with a certain character.
/// @param[in] ch									The character to be checked.
/// @return												True if the string end with the given character.
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type EndsWith(Char ch) const;
/// Checks if the current string end with a given string.
/// @param[in] str								The string part.
/// @return												True if the string ends with the string 'str'.
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type EndsWith(const CString& str) const;
/// Copies the string into 'buffer'.
/// @param[in,out] buffer					Block describing the buffer. A \0 byte will be appended to the string in any case.
/// @return												The length of the corresponding 8-bit string for the given encoding. the \0 byte is not counted.
		inline Result<Int> GetCStringBlock(const Block<Char>& buffer) const;
/// Appends the string to the given @p array.
/// @param[in,out] array					Array to be filled with the string. The string is NOT terminated with a \0 byte.
/// @return												OK on success.
		inline Result<void> GetCStringAppendArray(const NonConstArray<Char>& array) const;
/// Returns a copy of the C string in a new memory block. If a string is empty this function returns a string with a terminating null character.
/// @return												BaseArray<Char> with the encoded string. The string is \0 - terminated, so the last character in the array is \0.
		inline Result<BaseArray<Char>> GetCString() const;
/// Returns the internal character array.
/// @return												Block describing the internal character buffer. The data is read only!
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<Block<const Char>>, Block<const Char>>::type GetInternalData() const;
/// @markInternal
/// Caches a static constant string and returns a maxon::CString.
		static inline const CString& GetAndCacheConstString(const Char* chr, Int len);
	};
	/// Intermediate helper class for CStringInterface.
	template <typename S> class ReferenceFunctionsImpl : public ConstReferenceFunctionsImpl<S>
	{
	public:
		ReferenceFunctionsImpl() = default;
		using PrivateBaseClass = ConstReferenceFunctionsImpl<S>;
		using PrivateBaseClass::PrivateBaseClass;
/// Initializes the string with a specific length and a default character.
/// @param[in] count							Number of characters of the new string.
/// @param[in] fillChar						Character to fill the string with.
/// @return												OK on success.
		inline Result<void> Init(Int count = 0, Char fillChar = 0) const;
/// Optimizes the memory usage. This can only be done if the string previously contained 16- or 32-bit Unicode characters that now have been removed or if the string was longer before.
/// @return												OK on success. Also returns OK if the string already is in its smallest state.
		inline Result<void> Shrink() const;
/// Concatenates 2 strings, use this operation instead of a = a + b as it is much faster.
/// @return												OK on success.
		inline Result<void> Append(const CStringInterface* str) const;
/// Concatenates 2 strings of which the second is represented by len characters at
/// address str in memory.
/// @param[in] str								Character pointer.
/// @param[in] len								Number of characters.
/// @return												OK on success.
		inline Result<void> Append(const Char* str, Int len) const;
/// Appends a character to the current string.
/// @param[in] v									The character that will be added.
/// @return												OK on success.
		inline Result<void> AppendChar(Char v) const;
/// Erases a range of characters within a string.
/// @param[in] position						The starting position to delete 'count' characters. If the position is out of bounds an error will be returned.
/// @param[in] count							Number of characters to delete. If you want to delete all characters until the end pass StringEnd(). If the number is larger than what is available an error will be returned.
/// @return												OK on success.
		inline Result<void> Erase(StringPosition position, StringCount count) const;
/// Inserts a string at a specific position.
/// @param[in] position						Insert position in the current string. StringEnd() is a valid position. If the position is out of bounds an error is returned.
/// @param[in] str								String to be inserted.
/// @param[in] strStart						Starting position of the string to be inserted. If the position is out of bounds an error is returned.
/// @param[in] strCount						Number of characters to be inserted. If the number of characters is too large an error is returned.
/// @return												OK on success.
		inline Result<void> Insert(StringPosition position, const CStringInterface* str, StringPosition strStart = 0, StringCount strCount = StringEnd()) const;
/// Inserts a single unicode character at a specific position.
/// @param[in] position						Insert position, needs to be within boundaries.
/// @param[in] ch									Unicode character to insert.
/// @return												OK on success.
		inline Result<void> Insert(StringPosition position, Char ch) const;
/// Appends a number to the current string.
/// @param[in] v									The number that will be added.
/// @return												The current string. Will be an empty reference if AppendInt fails (apply iferr for error handling).
		inline DOXYGEN_SWITCH(maxon::RefMemberType<S const>, S) AppendInt(Int32 v) const;
/// Appends a number to the current string.
/// @param[in] v									The number that will be added.
/// @return												The current string. Will be an empty reference if AppendUInt fails (apply iferr for error handling).
		inline DOXYGEN_SWITCH(maxon::RefMemberType<S const>, S) AppendUInt(UInt32 v) const;
/// Appends a number to the current string.
/// @param[in] v									The number that will be added.
/// @return												The current string. Will be an empty reference if AppendInt fails (apply iferr for error handling).
		inline DOXYGEN_SWITCH(maxon::RefMemberType<S const>, S) AppendInt(Int64 v) const;
/// Appends a number to the current string.
/// @param[in] v									The number that will be added.
/// @return												The current string. Will be an empty reference if AppendUInt fails (apply iferr for error handling).
		inline DOXYGEN_SWITCH(maxon::RefMemberType<S const>, S) AppendUInt(UInt64 v) const;
/// Removes all characters with value <= 0x20 (e.g. space, tab, line feed) at the beginning of the string.
/// @return												OK on success.
		inline Result<void> TrimLeft() const;
/// Removes all characters with value <= 0x20 (e.g. space, tab, line feed) at the end of the string.
/// @return												OK on success.
		inline Result<void> TrimRight() const;
/// Replaces all occurrences of the character 'find' in the current string with the given character 'replace'.
/// @param[in] find								Search character. Each occurrence will be replaced with 'replace'.
/// @param[in] replace						Replacement of 'find'.
/// @return												Number of replaced characters.
		inline Result<Int> Replace(Char find, Char replace) const;
/// Replaces all occurrences of string 'find' in the current string with the given string 'replace'.
/// @param[in] find								Search string. Each occurrence will be replaced with 'replace'.
/// @param[in] replace						Replacement of 'find'. Can be an empty string, in which case all 'find' strings will be removed.
/// @return												Number of replaced strings.
		inline Result<Int> Replace(const CString& find, const CString& replace) const;
/// Replaces all occurrences of the character 'find' in the current string with the given string 'replace'.
/// @param[in] find								Search character. Each occurrence will be replaced with 'replace'.
/// @param[in] replace						Replacement of 'find'. Can be an empty string, in which case all 'find' characters will be removed.
/// @return												Number of replaced strings.
		inline Result<Int> Replace(Char find, const CString& replace) const;
/// Removes all characters with value <= 0x20 (e.g. space, tab, line feed) at the beginning and the end of the string.
/// @return												OK on success.
		inline Result<void> Trim() const;
/// Initializes the string with a given 8-bit Char string (the CString will contain an exact copy of
/// the buffer, there's no encoding to a different character set).
/// @param[out] buffer						Pointer to the 8-bit character string.
/// @param[in] count							Number of valid characters in the buffer, a value of -1 automatically detects the
/// 															string length by searching for the first \0 character, otherwise count is relevant and not \0.
/// @return												OK on success.
		inline Result<void> SetCString(const Char* buffer, Int count = -1) const;
/// Initializes the string with a given 8-bit Char string with the given encoding.
/// @param[out] buffer						Block with an 8-bit character string.
/// @return												OK on success.
		inline Result<void> SetCString(const Block<const Char>& buffer) const;
	};
	/// Intermediate helper class for CStringInterface.
	template <typename S> class COWReferenceFunctionsImpl : public ConstReferenceFunctionsImpl<S>
	{
	public:
		COWReferenceFunctionsImpl() = default;
		using PrivateBaseClass = ConstReferenceFunctionsImpl<S>;
		using PrivateBaseClass::PrivateBaseClass;
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongCOWRefHandler, CString, false>::type&() const { return reinterpret_cast<const CString&>(this->GetBaseRef()); }
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongCOWRefHandler, CString, false>::type&() { return reinterpret_cast<const CString&>(this->GetBaseRef()); }
/// Initializes the string with a specific length and a default character.
/// @param[in] count							Number of characters of the new string.
/// @param[in] fillChar						Character to fill the string with.
/// @return												OK on success.
		inline Result<void> Init(Int count = 0, Char fillChar = 0);
/// Optimizes the memory usage. This can only be done if the string previously contained 16- or 32-bit Unicode characters that now have been removed or if the string was longer before.
/// @return												OK on success. Also returns OK if the string already is in its smallest state.
		inline Result<void> Shrink();
/// Concatenates 2 strings, use this operation instead of a = a + b as it is much faster.
/// @return												OK on success.
		inline Result<void> Append(const CStringInterface* str);
/// Concatenates 2 strings of which the second is represented by len characters at
/// address str in memory.
/// @param[in] str								Character pointer.
/// @param[in] len								Number of characters.
/// @return												OK on success.
		inline Result<void> Append(const Char* str, Int len);
/// Appends a character to the current string.
/// @param[in] v									The character that will be added.
/// @return												OK on success.
		inline Result<void> AppendChar(Char v);
/// Erases a range of characters within a string.
/// @param[in] position						The starting position to delete 'count' characters. If the position is out of bounds an error will be returned.
/// @param[in] count							Number of characters to delete. If you want to delete all characters until the end pass StringEnd(). If the number is larger than what is available an error will be returned.
/// @return												OK on success.
		inline Result<void> Erase(StringPosition position, StringCount count);
/// Inserts a string at a specific position.
/// @param[in] position						Insert position in the current string. StringEnd() is a valid position. If the position is out of bounds an error is returned.
/// @param[in] str								String to be inserted.
/// @param[in] strStart						Starting position of the string to be inserted. If the position is out of bounds an error is returned.
/// @param[in] strCount						Number of characters to be inserted. If the number of characters is too large an error is returned.
/// @return												OK on success.
		inline Result<void> Insert(StringPosition position, const CStringInterface* str, StringPosition strStart = 0, StringCount strCount = StringEnd());
/// Inserts a single unicode character at a specific position.
/// @param[in] position						Insert position, needs to be within boundaries.
/// @param[in] ch									Unicode character to insert.
/// @return												OK on success.
		inline Result<void> Insert(StringPosition position, Char ch);
/// Appends a number to the current string.
/// @param[in] v									The number that will be added.
/// @return												The current string. Will be an empty reference if AppendInt fails (apply iferr for error handling).
		inline DOXYGEN_SWITCH(maxon::RefMemberType<S>, S) AppendInt(Int32 v);
/// Appends a number to the current string.
/// @param[in] v									The number that will be added.
/// @return												The current string. Will be an empty reference if AppendUInt fails (apply iferr for error handling).
		inline DOXYGEN_SWITCH(maxon::RefMemberType<S>, S) AppendUInt(UInt32 v);
/// Appends a number to the current string.
/// @param[in] v									The number that will be added.
/// @return												The current string. Will be an empty reference if AppendInt fails (apply iferr for error handling).
		inline DOXYGEN_SWITCH(maxon::RefMemberType<S>, S) AppendInt(Int64 v);
/// Appends a number to the current string.
/// @param[in] v									The number that will be added.
/// @return												The current string. Will be an empty reference if AppendUInt fails (apply iferr for error handling).
		inline DOXYGEN_SWITCH(maxon::RefMemberType<S>, S) AppendUInt(UInt64 v);
/// Removes all characters with value <= 0x20 (e.g. space, tab, line feed) at the beginning of the string.
/// @return												OK on success.
		inline Result<void> TrimLeft();
/// Removes all characters with value <= 0x20 (e.g. space, tab, line feed) at the end of the string.
/// @return												OK on success.
		inline Result<void> TrimRight();
/// Replaces all occurrences of the character 'find' in the current string with the given character 'replace'.
/// @param[in] find								Search character. Each occurrence will be replaced with 'replace'.
/// @param[in] replace						Replacement of 'find'.
/// @return												Number of replaced characters.
		inline Result<Int> Replace(Char find, Char replace);
/// Replaces all occurrences of string 'find' in the current string with the given string 'replace'.
/// @param[in] find								Search string. Each occurrence will be replaced with 'replace'.
/// @param[in] replace						Replacement of 'find'. Can be an empty string, in which case all 'find' strings will be removed.
/// @return												Number of replaced strings.
		inline Result<Int> Replace(const CString& find, const CString& replace);
/// Replaces all occurrences of the character 'find' in the current string with the given string 'replace'.
/// @param[in] find								Search character. Each occurrence will be replaced with 'replace'.
/// @param[in] replace						Replacement of 'find'. Can be an empty string, in which case all 'find' characters will be removed.
/// @return												Number of replaced strings.
		inline Result<Int> Replace(Char find, const CString& replace);
/// Removes all characters with value <= 0x20 (e.g. space, tab, line feed) at the beginning and the end of the string.
/// @return												OK on success.
		inline Result<void> Trim();
/// Initializes the string with a given 8-bit Char string (the CString will contain an exact copy of
/// the buffer, there's no encoding to a different character set).
/// @param[out] buffer						Pointer to the 8-bit character string.
/// @param[in] count							Number of valid characters in the buffer, a value of -1 automatically detects the
/// 															string length by searching for the first \0 character, otherwise count is relevant and not \0.
/// @return												OK on success.
		inline Result<void> SetCString(const Char* buffer, Int count = -1);
/// Initializes the string with a given 8-bit Char string with the given encoding.
/// @param[out] buffer						Block with an 8-bit character string.
/// @return												OK on success.
		inline Result<void> SetCString(const Block<const Char>& buffer);
	};
	template <typename ST> struct ReferenceFunctionsHelper : public std::conditional<maxon::Bool(ST::type::Handler::KIND & (maxon::VALUEKIND::COW_MASK | maxon::VALUEKIND::DEEP_CONSTNESS)), COWReferenceFunctionsImpl<typename ST::type>, typename std::conditional<std::is_const<typename ST::type::PrivateReferencedType>::value, ConstReferenceFunctionsImpl<typename ST::type>, ReferenceFunctionsImpl<typename ST::type>>::type> { };
};
class CStringInterface::Reference :
#ifdef DOXYGEN
public COWReferenceFunctionsImplDoxy<CString>
#else
public maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<const CStringInterface, maxon::StrongCOWRefHandler, CString>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(Reference, maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<const CStringInterface, maxon::StrongCOWRefHandler, CString>>>>);
	using NonConst = Hxx1::NonConstRef;
	static MAXON_ATTRIBUTE_FORCE_INLINE maxon::ResultMemT<CString> Create();
};

class CStringInterface::Hxx1::NonConstRef :
#ifdef DOXYGEN
public ReferenceFunctionsImplDoxy<NonConstRef>
#else
public maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<CStringInterface, maxon::StrongRefHandler, NonConstRef>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(NonConstRef, maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<CStringInterface, maxon::StrongRefHandler, NonConstRef>>>>);
};

#endif
