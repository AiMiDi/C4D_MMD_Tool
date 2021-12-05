#ifndef STRING_H__
#define STRING_H__

#include "maxon/interfacebase.h"
#include "maxon/block.h"
#include "maxon/basearray.h"
#include <stdio.h>
#include <stdarg.h>

namespace maxon
{

/// @addtogroup SYSTEM
/// @{

class StringDecodingRef;
class StringEncodingRef;
class StreamConversionRef;
template<typename T> class NonConstArray;

//----------------------------------------------------------------------------------------
/// Returns the default decoder for UTF-8 encodings.
/// Note that you cannot check for equality to detect if an encoding is UTF-8 - as the
/// reference is different in every module or instantiation.
/// Use @c decoder.HasSameClass(GetUtf8DefaultDecoder()) instead.
/// @return												The decoder.
//----------------------------------------------------------------------------------------
const StringDecodingRef& GetUtf8DefaultDecoder();

//----------------------------------------------------------------------------------------
/// Returns the default encoder for UTF-8 encodings.
/// Note that you cannot check for equality to detect if an encoding is UTF-8 - as the
/// reference is different in every module or instantiation.
/// Use @c encoder.HasSameClass(GetUtf8DefaultEncoder()) instead.
/// @return												The encoder.
//----------------------------------------------------------------------------------------
const StringEncodingRef& GetUtf8DefaultEncoder();

//----------------------------------------------------------------------------------------
/// Flags for the string to value conversion.
//----------------------------------------------------------------------------------------
enum class STRINGCONVERSION
{
	NONE									= 0,
	ALLOW_MORE_CHARACTERS	= (1 << 0)	///< if the specified string is longer than the converted characters and you specify this flag no error will be returned
} MAXON_ENUM_FLAGS(STRINGCONVERSION);

//----------------------------------------------------------------------------------------
/// String Comparison Mode
//----------------------------------------------------------------------------------------
enum class STRINGCOMPARISON
{
	MEMORY									= 0,	///< default - fast comparison, memory block is directly compared. This does not result in a correct alphabetical order.
	UNICODE_LETTERS					= 1,	///< strings are compared using correct unicode decomposition
	UNICODE_NUMBERS					= 2,	///< strings are compared using correct unicode decomposition. Numbers in strings are identified, so "2" is smaller than "10"
	CASEINSENSITIVE					= 3,	///< strings are compared case-insensitive using correct unicode decomposition
	CASEINSENSITIVE_NUMBERS	= 4 	///< strings are compared case-insensitive using correct unicode decomposition. Numbers in strings are identified, so "2" is smaller than "10"
} MAXON_ENUM_LIST(STRINGCOMPARISON);

using Utf16CharBuffer = BufferedBaseArray<Utf16Char, 512>;
using Utf32CharBuffer = BufferedBaseArray<Utf32Char, 256>;

//----------------------------------------------------------------------------------------
/// Class to store the position in a string for a string operation.
/// StringPosition just consists of an integer value. If it is positive, it indicates the absolute position.
/// If it is negative it indicates the position from the end, e.g. -1 refers to the last character.
///
/// Here an example for GetPart. The first parameter of GetPart is the class StringPosition, the second StringCount.
/// @code
///
///	res = str.GetPart(4, 3); // copy from position 4 on 3 characters
///
///	res = str.GetPart(-4, 3); // copy from the position that is 4 characters from the end of the string on 3 characters
/// @endcode
//----------------------------------------------------------------------------------------
class StringPosition
{
	friend class StringCount;
public:
	//----------------------------------------------------------------------------------------
	/// Constructor.
	/// @param[in] pos								If pos is >= 0 it designates the absolute position. If pos is negative it relative to the end. E.g. -1 refers to the last character.
	//----------------------------------------------------------------------------------------
	MAXON_IMPLICIT StringPosition(Int pos)
	{
		_value = pos;

		// to allow an insertion position after the last character we have to move by one
		if (_value < 0)
			_value--;
	}

	//----------------------------------------------------------------------------------------
	/// Calculates the absolute position in a string based on the contents of this class and a given string length.
	/// @param[in] length							The length of the string.
	/// @return												The absolute position in the string.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE Int ResolvePosition(Int length) const
	{
		return (_value >= 0) ? _value : (length + _value + 1);
	}

protected:
	Int _value;
};

//----------------------------------------------------------------------------------------
/// Class to store the position after the last character at the end of a string.
///
/// Here an example for GetPart. The first parameter of GetPart is the class StringPosition, the second StringCount.
/// @code
///
///	res = str.GetPart(4, StringEnd()); // copy from position four on until the end of the string
///
///	res = str.GetPart(-4, StringEnd()); // copy from the position that is four characters from the end of the string until the end of the string
/// @endcode
//----------------------------------------------------------------------------------------
class StringEnd : public StringPosition
{
public:
	//----------------------------------------------------------------------------------------
	/// Constructor.
	//----------------------------------------------------------------------------------------
	StringEnd() : StringPosition(0)
	{
		_value = -1;
	}

	//----------------------------------------------------------------------------------------
	/// Constructor for a position from the end. Other than the class StringPosition StringEnd allows you to refer to the position after the last character.
	/// @param[in] value							The (negative) position from the end or 0 for the string end (the position after the last character).
	//----------------------------------------------------------------------------------------
	explicit StringEnd(Int value) : StringPosition(0)
	{
		DebugAssert(value <= 0);
		_value = -1 + value;
	}
};

//----------------------------------------------------------------------------------------
/// Class to store the character count for a string operation.
/// StringCount allows you to specify a character count for operations like Insert or GetPart.
/// However it also allows you to specify a StringPosition instead (implicitly defining the count).
///
/// Here an example for GetPart. The first parameter of GetPart is the class StringPosition, the second StringCount.
/// @code
///
///	res = str.GetPart(2, 3); // copy from position 2 on three characters
///
///	res = str.GetPart(2, StringPosition(3)); // copy from position 2 to position 3 (two characters)
/// @endcode
//----------------------------------------------------------------------------------------
class StringCount
{
public:
	//----------------------------------------------------------------------------------------
	/// Constructor.
	/// @param[in] count							The number of characters.
	//----------------------------------------------------------------------------------------
	MAXON_IMPLICIT StringCount(Int count)
	{
		if (MAXON_LIKELY(count >= 0))
		{
			if (MAXON_UNLIKELY(count > (LIMIT<Int>::MAX >> 1)))
				count = LIMIT<Int>::MAX >> 1;

			_value = (count << 1) | STRING_COUNT_BIT;
		}
		else
		{
			DebugStop("Negative count is not legal!");
			_value = STRING_COUNT_BIT;
		}
	}

	//----------------------------------------------------------------------------------------
	/// Constructor from a StringPosition.
	/// @param[in] pos								The string position from the beginning or the end.
	//----------------------------------------------------------------------------------------
	MAXON_UBSANITIZER_DISABLE("Requires two's complement") 
	MAXON_IMPLICIT StringCount(StringPosition pos) : _value(pos._value << 1)
	{
	}

	//----------------------------------------------------------------------------------------
	/// Calculates the end position of a range based on a given start position and a string length.
	/// @param[in] startPos						The starting position of the range.
	/// @param[in] length							The length of the string.
	/// @return												The end position of the range.
	//----------------------------------------------------------------------------------------
	MAXON_UBSANITIZER_DISABLE("Requires two's complement") 
	MAXON_ATTRIBUTE_FORCE_INLINE Int ResolvePosition(Int startPos, Int length) const
	{
		Int shifted = _value >> 1;
		if (_value & STRING_COUNT_BIT)
			return startPos + shifted;

		return (shifted >= 0) ? shifted : (length + shifted + 1);
	}

	//----------------------------------------------------------------------------------------
	/// Calculates the character count of a range based on a given start position and a string length.
	/// @param[in] startPos						The starting position of the range.
	/// @param[in] length							The length of the string.
	/// @return												The character count.
	//----------------------------------------------------------------------------------------
	MAXON_UBSANITIZER_DISABLE("Requires two's complement") 
	MAXON_ATTRIBUTE_FORCE_INLINE Int ResolveCount(Int startPos, Int length) const
	{
		Int shifted = _value >> 1;
		if (_value & STRING_COUNT_BIT)
			return shifted;

		return ((shifted >= 0) ? shifted : (length + shifted + 1)) - startPos;
	}

private:
	static const Int STRING_COUNT_BIT = 1;

	Int		_value;
};

static const Int STRING_MAXIMUM_PRECISION = -2; ///< Constant for FloatToString. If passed to FloatToString the returned string will have as many digits as it is necessary to store the exact value (that later can be converted back to the exactly same floating point value).
static const Int STRING_DYNAMIC_DIGITS		= -1; ///< Constant for FloatToString. If passed to FloatToString the digits in front of the comma will be dynamically adjusted.

//----------------------------------------------------------------------------------------
/// Base template for String and CString.
/// @tparam INTERFACETYPE					Either String or CString.
/// @tparam REFTYPE								Reference of the interface (String or CString).
/// @tparam CHARTYPE							Data type to store characters, either Utf32Char (String) or Char (CString).
//----------------------------------------------------------------------------------------
template <typename INTERFACETYPE, typename REFTYPE, typename CHARTYPE> class StringTemplate
{
public:
	using Super = StringTemplate;

	//----------------------------------------------------------------------------------------
	/// Returns the length (number of elements) of the string, not the size of the block.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Int GetLength() const;

	//----------------------------------------------------------------------------------------
	/// Initializes the string with a specific length and a default character.
	/// @param[in] count							Number of characters of the new string.
	/// @param[in] fillChar						Character to fill the string with.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> Init(Int count = 0, CHARTYPE fillChar = 0);

	//----------------------------------------------------------------------------------------
	/// Optimizes the memory usage. This can only be done if the string previously contained 16- or 32-bit Unicode characters that now have been removed or if the string was longer before.
	/// @return												OK on success. Also returns OK if the string already is in its smallest state.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> Shrink();

	//----------------------------------------------------------------------------------------
	/// Concatenates 2 strings, use this operation instead of a = a + b as it is much faster.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> Append(const INTERFACETYPE* str);

	//----------------------------------------------------------------------------------------
	/// Concatenates 2 strings of which the second is represented by len characters at
	/// address str in memory.
	/// @param[in] str								Character pointer.
	/// @param[in] len								Number of characters.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> Append(const CHARTYPE* str, Int len);

	//----------------------------------------------------------------------------------------
	/// Appends a character to the current string.
	/// @param[in] v									The character that will be added.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	MAXON_FUNCTION Result<void> AppendChar(CHARTYPE v)
	{
		if (Append(&v, 1) == FAILED)
			return CreateError(MAXON_SOURCE_LOCATION, ERROR_TYPE::OUT_OF_MEMORY);
		
		return OK;
	}

	//----------------------------------------------------------------------------------------
	/// Searches for the first occurrence of 'str' within a string.
	/// @param[in] str								The search string.
	/// @param[in] start							Starting position within the current string to search from. If it is out of bounds the function will return InvalidArrayIndex.
	/// @return												The index at which 'str' has been found or InvalidArrayIndex.
	/// @MAXON_ANNOTATION{default=InvalidArrayIndex}
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Int FindIndex(const INTERFACETYPE* str, StringPosition start = 0) const;

	//----------------------------------------------------------------------------------------
	/// Searches for the last occurrence of 'str' within a string.
	/// @param[in] str								The search string.
	/// @param[in] start							Starting position within the current string to search from (backwards). The character at the given position will not be included in the search. If it is out of bounds the function will return InvalidArrayIndex.
	/// @return												The index at which 'str' has been found or InvalidArrayIndex.
	/// @MAXON_ANNOTATION{default=InvalidArrayIndex}
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Int FindLastIndex(const INTERFACETYPE* str, StringPosition start = StringEnd()) const;

	//----------------------------------------------------------------------------------------
	/// Searches for the first occurrence of character 'ch' within a string.
	/// @param[in] ch									The search character.
	/// @param[in] start							Starting position within the current string to search from. If it is out of bounds the function will return InvalidArrayIndex.
	/// @return												The index at which 'ch' has been found or InvalidArrayIndex.
	/// @MAXON_ANNOTATION{default=InvalidArrayIndex}
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Int FindIndex(CHARTYPE ch, StringPosition start = 0) const;

	//----------------------------------------------------------------------------------------
	/// Searches for the last occurrence of character 'ch' within a string.
	/// @param[in] ch									The search character.
	/// @param[in] start							Starting position within the current string to search from (backwards). The character at the given position will not be included in the search. If it is out of bounds the function will return InvalidArrayIndex.
	/// @return												The index at which 'ch' has been found or InvalidArrayIndex.
	/// @MAXON_ANNOTATION{default=InvalidArrayIndex}
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Int FindLastIndex(CHARTYPE ch, StringPosition start = StringEnd()) const;

	//----------------------------------------------------------------------------------------
	/// Uppercase search for the first occurrence of 'str' within a string (which doesn't need to contain uppercase characters).
	/// @param[in] str								The search string, must be completely uppercase, otherwise no matches will be found.
	/// @param[in] start							Starting position within the current string to search from. If it is out of bounds the function will return InvalidArrayIndex.
	/// @return												The index at which 'str' has been found or InvalidArrayIndex.
	/// @MAXON_ANNOTATION{default=InvalidArrayIndex}
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Int FindUpperIndex(const INTERFACETYPE* str, StringPosition start = 0) const;

	//----------------------------------------------------------------------------------------
	/// Uppercase search for the last occurrence of 'str' within a string (which doesn't need to contain uppercase characters).
	/// @param[in] str								The search string, must be completely uppercase, otherwise no matches will be found.
	/// @param[in] start							Starting position within the current string to search from (backwards). The character at the given position will not be included in the search. If it is out of bounds the function will return InvalidArrayIndex.
	/// @return												The index at which 'str' has been found or InvalidArrayIndex.
	/// @MAXON_ANNOTATION{default=InvalidArrayIndex}
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Int FindLastUpperIndex(const INTERFACETYPE* str, StringPosition start = StringEnd()) const;

	//----------------------------------------------------------------------------------------
	/// Erases a range of characters within a string.
	/// @param[in] position						The starting position to delete 'count' characters. If the position is out of bounds an error will be returned.
	/// @param[in] count							Number of characters to delete. If you want to delete all characters until the end pass StringEnd(). If the number is larger than what is available an error will be returned.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> Erase(StringPosition position, StringCount count);

	//----------------------------------------------------------------------------------------
	/// Inserts a string at a specific position.
	/// @param[in] position						Insert position in the current string. StringEnd() is a valid position. If the position is out of bounds an error is returned.
	/// @param[in] str								String to be inserted.
	/// @param[in] strStart						Starting position of the string to be inserted. If the position is out of bounds an error is returned.
	/// @param[in] strCount						Number of characters to be inserted. If the number of characters is too large an error is returned.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> Insert(StringPosition position, const INTERFACETYPE* str, StringPosition strStart = 0, StringCount strCount = StringEnd());

	//----------------------------------------------------------------------------------------
	/// Inserts a single unicode character at a specific position.
	/// @param[in] position						Insert position, needs to be within boundaries.
	/// @param[in] ch									Unicode character to insert.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> Insert(StringPosition position, CHARTYPE ch);

	//----------------------------------------------------------------------------------------
	/// Creates a part of the current string.
	/// @param[in] start							Position where the new partial string will start.
	/// @param[in] count							Number of characters for the partial string. If it is larger than the number of available characters an empty string will be returned.
	/// @return												The partial string, or empty string if 'start' was out of boundaries. Will be an empty reference if GetPart fails (apply iferr for error handling).
	//----------------------------------------------------------------------------------------
	MAXON_METHOD INTERFACETYPE* GetPart(StringPosition start, StringCount count) const;

	//----------------------------------------------------------------------------------------
	/// Returns the uppercase version of a string.
	/// @return												Uppercase version of a string. Will be an empty reference if ToUpper fails (apply iferr for error handling).
	//----------------------------------------------------------------------------------------
	MAXON_METHOD INTERFACETYPE* ToUpper() const;

	//----------------------------------------------------------------------------------------
	/// Returns the lowercase version of a string.
	/// @return												Lowercase version of a string. Will be an empty reference if ToLower fails (apply iferr for error handling).
	//----------------------------------------------------------------------------------------
	MAXON_METHOD INTERFACETYPE* ToLower() const;

	//----------------------------------------------------------------------------------------
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
	//----------------------------------------------------------------------------------------
	MAXON_METHOD COMPARERESULT ComparePart(const INTERFACETYPE* str, STRINGCOMPARISON mode, StringPosition position, StringCount count) const;

	//----------------------------------------------------------------------------------------
	/// Compares the object against 'str' for exact match.
	/// @param[in] str								Comparison object.
	/// @param[in] mode								Comparison mode.
	/// @return												See COMPARERESULT.
	//----------------------------------------------------------------------------------------
	MAXON_FUNCTION COMPARERESULT Compare(const INTERFACETYPE* str, STRINGCOMPARISON mode = STRINGCOMPARISON::UNICODE_NUMBERS) const
	{
		return ComparePart(str, mode, 0, StringEnd());
	}

	//----------------------------------------------------------------------------------------
	/// Compare strings for equality.
	/// @return												True if equal.
	//----------------------------------------------------------------------------------------
	MAXON_FUNCTION Bool IsEqual(const INTERFACETYPE* str) const
	{
		return ComparePart(str, STRINGCOMPARISON::MEMORY, 0, StringEnd()) == COMPARERESULT::EQUAL;
	}

	MAXON_METHOD UInt GetHashCode() const;

	//----------------------------------------------------------------------------------------
	/// Changes the character at the given position (used internally by CharPtr).
	/// @param[in] pos								Character index. If it is negative the position is relative to end, e.g. -1 indicates the last character. The position must be within boundaries, however only a debug assert will happen otherwise.
	/// @param[in] ch									Character value.
	///
	/// @MAXON_ANNOTATION{refclass=false}
	//----------------------------------------------------------------------------------------
	MAXON_METHOD void SetChar(Int pos, CHARTYPE ch);

	//----------------------------------------------------------------------------------------
	/// Retrieves the character at a given position. If the position is out of bounds 0 will be returned.
	/// @param[in] pos								Character position. If it is negative the position is relative to end, e.g. -1 indicates the last character. The position must be within boundaries, however only a debug assert will happen otherwise.
	/// @return												The character.
	///
	/// @MAXON_ANNOTATION{refclass=false}
	//----------------------------------------------------------------------------------------
	MAXON_METHOD CHARTYPE GetChar(Int pos) const;

	//----------------------------------------------------------------------------------------
	/// Converts a string to a 64-bit floating point value.
	/// This routine does no formula parsing.
	/// While leading whitespaces are allowed by default no trailing characters of any kind are allowed.
	/// @param[in] flags							Optional flags for the conversion.
	/// @return												Floating point value of the string.
	//----------------------------------------------------------------------------------------
	MAXON_FUNCTION Result<Float64> ToFloat64(STRINGCONVERSION flags = STRINGCONVERSION::NONE) const;

	//----------------------------------------------------------------------------------------
	/// Converts a string to a 32-bit floating point value.
	/// This routine does no formula parsing.
	/// While leading whitespaces are allowed by default no trailing characters of any kind are allowed.
	/// @param[in] flags							Optional flags for the conversion.
	/// @return												Floating point value of the string.
	//----------------------------------------------------------------------------------------
	MAXON_FUNCTION Result<Float32> ToFloat32(STRINGCONVERSION flags = STRINGCONVERSION::NONE) const;

	//----------------------------------------------------------------------------------------
	/// Converts a string to a floating point value.
	/// This routine does no formula parsing.
	/// While leading whitespaces are allowed by default no trailing characters of any kind are allowed.
	/// @param[in] flags							Optional flags for the conversion.
	/// @return												Floating point value of the string.
	//----------------------------------------------------------------------------------------
	MAXON_FUNCTION Result<Float> ToFloat(STRINGCONVERSION flags = STRINGCONVERSION::NONE) const;

	//----------------------------------------------------------------------------------------
	/// Converts a string to a 64 bit integer value.
	/// This routine does no formula parsing and does not support any suffixes/prefixes except for 0x (hexadecimal numbers).
	/// While leading whitespaces are allowed by default no trailing characters of any kind are allowed.
	/// @param[in] flags							Optional flags for the conversion.
	/// @return												Integer value of the string.
	//----------------------------------------------------------------------------------------
	MAXON_FUNCTION Result<Int64> ToInt64(STRINGCONVERSION flags = STRINGCONVERSION::NONE) const;

	//----------------------------------------------------------------------------------------
	/// Converts a string to a 32 bit integer value.
	/// This routine does no formula parsing and does not support any suffixes/prefixes except for 0x (hexadecimal numbers).
	/// While leading whitespaces are allowed by default no trailing characters of any kind are allowed.
	/// @param[in] flags							Optional flags for the conversion.
	/// @return												Integer value of the string.
	//----------------------------------------------------------------------------------------
	MAXON_FUNCTION Result<Int32> ToInt32(STRINGCONVERSION flags = STRINGCONVERSION::NONE) const;

	//----------------------------------------------------------------------------------------
	/// Converts a string to an integer value.
	/// This routine does no formula parsing and does not support any suffixes/prefixes except for 0x (hexadecimal numbers).
	/// While leading whitespaces are allowed by default no trailing characters of any kind are allowed.
	/// @param[in] flags							Optional flags for the conversion.
	/// @return												Integer value of the string.
	//----------------------------------------------------------------------------------------
	MAXON_FUNCTION Result<Int> ToInt(STRINGCONVERSION flags = STRINGCONVERSION::NONE) const;

	//----------------------------------------------------------------------------------------
	/// Converts a string to a 64 bit unsigned integer value.
	/// This routine does no formula parsing and does not support any suffixes/prefixes except for 0x (hexadecimal numbers).
	/// While leading whitespaces are allowed by default no trailing characters of any kind are allowed.
	/// @param[in] flags							Optional flags for the conversion.
	/// @return												Integer value of the string.
	//----------------------------------------------------------------------------------------
	MAXON_FUNCTION Result<UInt64> ToUInt64(STRINGCONVERSION flags = STRINGCONVERSION::NONE) const;

	//----------------------------------------------------------------------------------------
	/// Converts a string to a 32 bit unsigned integer value.
	/// This routine does no formula parsing and does not support any suffixes/prefixes except for 0x (hexadecimal numbers).
	/// While leading whitespaces are allowed by default no trailing characters of any kind are allowed.
	/// @param[in] flags							Optional flags for the conversion.
	/// @return												Integer value of the string.
	//----------------------------------------------------------------------------------------
	MAXON_FUNCTION Result<UInt32> ToUInt32(STRINGCONVERSION flags = STRINGCONVERSION::NONE) const;

	//----------------------------------------------------------------------------------------
	/// Converts a string to an unsigned integer value.
	/// This routine does no formula parsing and does not support any suffixes/prefixes except for 0x (hexadecimal numbers).
	/// While leading whitespaces are allowed by default no trailing characters of any kind are allowed.
	/// @param[in] flags							Optional flags for the conversion.
	/// @return												Integer value of the string.
	//----------------------------------------------------------------------------------------
	MAXON_FUNCTION Result<UInt> ToUInt(STRINGCONVERSION flags = STRINGCONVERSION::NONE) const;

	//----------------------------------------------------------------------------------------
	/// Converts a floating point value into formatted text.
	/// @param[in] value							Floating point value to convert into text.
	/// @param[in] charsBeforeComma		Characters before the decimal point. If STRING_DYNAMIC_DIGITS is passed or 'charsBeforeComma' is too low to represent 'value' it is automatically increased/adjusted. If 'charsBeforeComma' is positive and exponent is false fill characters will be added to the beginning. If STRING_MAXIMUM_PRECISION is passed, then the result will be an exact representation of the value (possibly using exponential notation).
	/// @param[in] digitsAfterComma		Digits after the decimal point. If a negative number is passed the number of digits is automatically chosen and up to (-digitsAfterComma).
	/// @param[in] exponent						Force exponential-style output (e.g. 1.0e+10).
	/// @param[in] fillChar						Fill character for digits before the decimal point. E.g. if you specify 4 for charsBeforeComma, '*' for fillChar and your value is 1.5 you'll get ***1.5 as a result. This value has no impact if exponent is true.
	/// @return												String object with the decimal text of the value.
	//----------------------------------------------------------------------------------------
	static MAXON_FUNCTION REFTYPE FloatToString(Float32 value, Int charsBeforeComma = STRING_DYNAMIC_DIGITS, Int digitsAfterComma = -3, Bool exponent = false, CHARTYPE fillChar = ' ');

	//----------------------------------------------------------------------------------------
	/// Converts a floating point value into formatted text.
	/// @param[in] value							Floating point value to convert into text.
	/// @param[in] charsBeforeComma		Characters before the decimal point. If STRING_DYNAMIC_DIGITS is passed or 'charsBeforeComma' is too low to represent 'value' it is automatically increased/adjusted. If 'charsBeforeComma' is positive and exponent is false fill characters will be added to the beginning. If STRING_MAXIMUM_PRECISION is passed, then the result will be an exact representation of the value (possibly using exponential notation).
	/// @param[in] digitsAfterComma		Digits after the decimal point. If a negative number is passed the number of digits is automatically chosen and up to (-digitsAfterComma).
	/// @param[in] exponent						Force exponential-style output (e.g. 1.0e+10).
	/// @param[in] fillChar						Fill character for digits before the decimal point. E.g. if you specify 4 for charsBeforeComma, '*' for fillChar and your value is 1.5 you'll get ***1.5 as a result. This value has no impact if exponent is true.
	/// @return												String object with the decimal text of the value.
	//----------------------------------------------------------------------------------------
	static MAXON_FUNCTION REFTYPE FloatToString(Float64 value, Int charsBeforeComma = STRING_DYNAMIC_DIGITS, Int digitsAfterComma = -3, Bool exponent = false, CHARTYPE fillChar = ' ');

	//----------------------------------------------------------------------------------------
	/// Appends a number to the current string.
	/// @param[in] v									The number that will be added.
	/// @return												The current string. Will be an empty reference if AppendInt fails (apply iferr for error handling).
	/// @MAXON_ANNOTATION{returnsThis,noResult}
	//----------------------------------------------------------------------------------------
	MAXON_FUNCTION INTERFACETYPE* AppendInt(Int32 v)
	{
		return AppendInt((Int64) v);
	}

	//----------------------------------------------------------------------------------------
	/// Appends a number to the current string.
	/// @param[in] v									The number that will be added.
	/// @return												The current string. Will be an empty reference if AppendUInt fails (apply iferr for error handling).
	/// @MAXON_ANNOTATION{returnsThis,noResult}
	//----------------------------------------------------------------------------------------
	MAXON_FUNCTION INTERFACETYPE* AppendUInt(UInt32 v)
	{
		return AppendUInt((UInt64) v);
	}

	//----------------------------------------------------------------------------------------
	/// Appends a number to the current string.
	/// @param[in] v									The number that will be added.
	/// @return												The current string. Will be an empty reference if AppendInt fails (apply iferr for error handling).
	/// @MAXON_ANNOTATION{returnsThis,noResult}
	//----------------------------------------------------------------------------------------
	MAXON_FUNCTION INTERFACETYPE* AppendInt(Int64 v);

	//----------------------------------------------------------------------------------------
	/// Appends a number to the current string.
	/// @param[in] v									The number that will be added.
	/// @return												The current string. Will be an empty reference if AppendUInt fails (apply iferr for error handling).
	/// @MAXON_ANNOTATION{returnsThis,noResult}
	//----------------------------------------------------------------------------------------
	MAXON_FUNCTION INTERFACETYPE* AppendUInt(UInt64 v);

	//----------------------------------------------------------------------------------------
	/// Formats a Int32 value as decimal text.
	/// @param[in] v									Int32 value.
	/// @return												String object with the decimal text of the value. Will be an empty reference on failure (apply iferr for error handling).
	//----------------------------------------------------------------------------------------
	static MAXON_FUNCTION REFTYPE IntToString(Int32 v)
	{
		return REFTYPE().AppendInt(v);
	}

	//----------------------------------------------------------------------------------------
	/// Formats a UInt32 value as decimal text.
	/// @param[in] v									UInt32 value.
	/// @return												String object with the decimal text of the value. Will be an empty reference on failure (apply iferr for error handling).
	//----------------------------------------------------------------------------------------
	static MAXON_FUNCTION REFTYPE UIntToString(UInt32 v)
	{
		return REFTYPE().AppendUInt(v);
	}

	//----------------------------------------------------------------------------------------
	/// Formats a Int64 value as decimal text.
	/// @param[in] v									Int64 value.
	/// @return												String object with the decimal text of the value. Will be an empty reference on failure (apply iferr for error handling).
	//----------------------------------------------------------------------------------------
	static MAXON_FUNCTION REFTYPE IntToString(Int64 v)
	{
		return REFTYPE().AppendInt(v);
	}

	//----------------------------------------------------------------------------------------
	/// Formats a UInt64 value as decimal text.
	/// @param[in] v									Int64 value.
	/// @return												String object with the decimal text of the value. Will be an empty reference on failure (apply iferr for error handling).
	//----------------------------------------------------------------------------------------
	static MAXON_FUNCTION REFTYPE UIntToString(UInt64 v)
	{
		return REFTYPE().AppendUInt(v);
	}

	//----------------------------------------------------------------------------------------
	/// Formats a Int64 value as a memory information.
	/// @param[in] v									The size of bytes that should be formated as memory text.
	/// @param[in] mebibytes					defines if a value of 1343443 is either output as "1.28 MiB" (mebibytes) or "1.34 MB" (megabytes).
	/// @return												String object for the given mem value.
	//----------------------------------------------------------------------------------------
	static MAXON_FUNCTION REFTYPE MemorySizeToString(Int64 v, Bool mebibytes = true);

	//----------------------------------------------------------------------------------------
	/// Formats a Int32 value as hexadecimal text.
	/// @param[in] v									Int32 value.
	/// @param[in] prefix0x						Start the string with 0x as prefix.
	/// @return												String object with the hexadecimal text of the value.
	//----------------------------------------------------------------------------------------
	static MAXON_FUNCTION REFTYPE HexToString(UInt32 v, Bool prefix0x = true);

	//----------------------------------------------------------------------------------------
	/// Formats a Int64 value as hexadecimal text.
	/// @param[in] v									Int64 value.
	/// @param[in] prefix0x						Start the string with 0x as prefix.
	/// @return												String object with the hexadecimal text of the value.
	//----------------------------------------------------------------------------------------
	static MAXON_FUNCTION REFTYPE HexToString(UInt64 v, Bool prefix0x = true);

	//----------------------------------------------------------------------------------------
	/// Formats a pointer as hexadecimal text. The pointer starts with 0x prefix.
	/// @param[in] v									Pointer to convert.
	/// @return												String object with the hexadecimal text of the value.
	//----------------------------------------------------------------------------------------
	static MAXON_FUNCTION REFTYPE PointerToString(const void* v);

	//----------------------------------------------------------------------------------------
	/// Copies the string as UTF-32 encoded characters into the passed array.
	/// The array will be resized and contain the non \0 - terminated data.
	/// @param[out] stringData				The array to receive the data.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> GetUtf32(Utf32CharBuffer& stringData) const;

	//----------------------------------------------------------------------------------------
	/// Removes all characters with value <= 0x20 (e.g. space, tab, line feed) at the beginning of the string.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> TrimLeft();

	//----------------------------------------------------------------------------------------
	/// Removes all characters with value <= 0x20 (e.g. space, tab, line feed) at the end of the string.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> TrimRight();

	//----------------------------------------------------------------------------------------
	/// Splits the string into parts separated by the split symbol (e.g. a comma).
	/// @param[in] splitSymbol				String containing the split symbol.
	/// @param[in] trim								If true each separated part will be trimmed (see Trim).
	/// @param[out] parts							Array to be filled with the separated strings.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> Split(const REFTYPE& splitSymbol, Bool trim, const ValueReceiver<const REFTYPE&>& parts) const;

	//----------------------------------------------------------------------------------------
	/// Replaces all occurrences of the character 'find' in the current string with the given character 'replace'.
	/// @param[in] find								Search character. Each occurrence will be replaced with 'replace'.
	/// @param[in] replace						Replacement of 'find'.
	/// @return												Number of replaced characters.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<Int> Replace(CHARTYPE find, CHARTYPE replace);

	//----------------------------------------------------------------------------------------
	/// Replaces all occurrences of string 'find' in the current string with the given string 'replace'.
	/// @param[in] find								Search string. Each occurrence will be replaced with 'replace'.
	/// @param[in] replace						Replacement of 'find'. Can be an empty string, in which case all 'find' strings will be removed.
	/// @return												Number of replaced strings.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<Int> Replace(const REFTYPE& find, const REFTYPE& replace);

	//----------------------------------------------------------------------------------------
	/// Replaces all occurrences of the character 'find' in the current string with the given string 'replace'.
	/// @param[in] find								Search character. Each occurrence will be replaced with 'replace'.
	/// @param[in] replace						Replacement of 'find'. Can be an empty string, in which case all 'find' characters will be removed.
	/// @return												Number of replaced strings.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<Int> Replace(CHARTYPE find, const REFTYPE& replace);

	//----------------------------------------------------------------------------------------
	/// Searches for the first occurrence of 'str' within a string.
	/// @param[in] str								The search string.
	/// @param[out] pos								Pointer to be filled with the position where 'str' was found. This parameter can be a nullptr. In case no occurence was found *pos is initialized with InvalidArrayIndex.
	/// @param[in] start							Starting position within the current string to search from. If it is out of bounds the function will return false.
	/// @return												True if 'str' has been found, in that case *pos contains the position where the first occurance was found.
	//----------------------------------------------------------------------------------------
	MAXON_FUNCTION Bool Find(const REFTYPE& str, Int* pos, StringPosition start = 0) const;

	//----------------------------------------------------------------------------------------
	/// Searches for the last occurrence of 'str' within a string.
	/// @param[in] str								The search string.
	/// @param[out] pos								Pointer to be filled with the position where 'str' was found. This parameter can be a nullptr. In case no occurence was found *pos is initialized with InvalidArrayIndex.
	/// @param[in] start							Starting position within the current string to search from (backwards). The character at the given position will not be included in the search. If it is out of bounds the function will return false.
	/// @return												True if 'str' has been found, in that case *pos contains the position where the last occurance was found.
	//----------------------------------------------------------------------------------------
	MAXON_FUNCTION Bool FindLast(const REFTYPE& str, Int* pos, StringPosition start = StringEnd()) const;

	//----------------------------------------------------------------------------------------
	/// Searches for the first occurrence of character 'ch' within a string.
	/// @param[in] ch									The search character.
	/// @param[out] pos								Pointer to be filled with the position where 'ch' was found. This parameter can be a nullptr. In case no occurence was found *pos is initialized with InvalidArrayIndex.
	/// @param[in] start							Starting position within the current string to search from. If it is out of bounds the function will return false.
	/// @return												True if 'ch' has been found, in that case *pos contains the position where the first occurance was found.
	//----------------------------------------------------------------------------------------
	MAXON_FUNCTION Bool Find(CHARTYPE ch, Int* pos, StringPosition start = 0) const;

	//----------------------------------------------------------------------------------------
	/// Searches for the last occurrence of character 'ch' within a string.
	/// @param[in] ch									The search character.
	/// @param[out] pos								Pointer to be filled with the position where 'ch' was found. This parameter can be a nullptr. In case no occurence was found *pos is initialized with InvalidArrayIndex.
	/// @param[in] start							Starting position within the current string to search from (backwards). The character at the given position will not be included in the search. If it is out of bounds the function will return false.
	/// @return												True if 'ch' has been found, in that case *pos contains the position where the last occurance was found.
	//----------------------------------------------------------------------------------------
	MAXON_FUNCTION Bool FindLast(CHARTYPE ch, Int* pos, StringPosition start = StringEnd()) const;

	//----------------------------------------------------------------------------------------
	/// Uppercase search for the first occurrence of 'str' within a string (which doesn't need to contain uppercase characters).
	/// @param[in] str								The search string, must be completely uppercase, otherwise no matches will be found.
	/// @param[out] pos								Pointer to be filled with the position where 'ch' was found. This parameter can be a nullptr. In case no occurence was found *pos is initialized with InvalidArrayIndex.
	/// @param[in] start							Starting position within the current string to search from. If it is out of bounds the function will return false.
	/// @return												True if 'str' has been found, in that case *pos contains the position where the first occurance was found.
	//----------------------------------------------------------------------------------------
	MAXON_FUNCTION Bool FindUpper(const REFTYPE& str, Int* pos, StringPosition start = 0) const;

	//----------------------------------------------------------------------------------------
	/// Uppercase search for the last occurrence of 'str' within a string (which doesn't need to contain uppercase characters).
	/// @param[in] str								The search string, must be completely uppercase, otherwise no matches will be found.
	/// @param[out] pos								Pointer to be filled with the position where 'ch' was found. This parameter can be a nullptr. In case no occurence was found *pos is initialized with InvalidArrayIndex.
	/// @param[in] start							Starting position within the current string to search from (backwards). The character at the given position will not be included in the search. If it is out of bounds the function will return false.
	/// @return												True if 'str' has been found, in that case *pos contains the position where the last occurance was found.
	//----------------------------------------------------------------------------------------
	MAXON_FUNCTION Bool FindLastUpper(const REFTYPE& str, Int* pos, StringPosition start = StringEnd()) const;

	//----------------------------------------------------------------------------------------
	/// Returns the string part left of the given position. The character at position will not be included.
	/// @param[in] start							Partitioning position.
	/// @return												The partial string, or empty string if 'start' was out of boundaries. Will be an empty reference on failure (apply iferr for error handling).
	//----------------------------------------------------------------------------------------
	MAXON_FUNCTION INTERFACETYPE* GetLeftPart(StringPosition start) const
	{
		return GetPart(0, start);
	}

	//----------------------------------------------------------------------------------------
	/// Returns the string part right of the given position. The character at position will be included.
	/// @param[in] start							Partitioning position.
	/// @return												The partial string, or empty string if 'start' was out of boundaries. Will be an empty reference on failure (apply iferr for error handling).
	//----------------------------------------------------------------------------------------
	MAXON_FUNCTION INTERFACETYPE* GetRightPart(StringPosition start) const
	{
		return GetPart(start, StringEnd());
	}

	//----------------------------------------------------------------------------------------
	/// Checks if the string starts with a certain character.
	/// @param[in] ch									The character to be checked.
	/// @return												True if the string starts with the given character.
	//----------------------------------------------------------------------------------------
	MAXON_FUNCTION Bool StartsWith(CHARTYPE ch) const
	{
		return (GetLength() > 0) && GetChar(0) == ch;
	}

	//----------------------------------------------------------------------------------------
	/// Checks if the current string starts with a given string.
	/// @param[in] str								The string part.
	/// @return												True if the string starts with the string 'str'.
	//----------------------------------------------------------------------------------------
	MAXON_FUNCTION Bool StartsWith(const REFTYPE& str) const
	{
		return ComparePart(str, STRINGCOMPARISON::MEMORY, 0, str.GetLength()) == COMPARERESULT::EQUAL;
	}

	//----------------------------------------------------------------------------------------
	/// Checks if the string ends with a certain character.
	/// @param[in] ch									The character to be checked.
	/// @return												True if the string end with the given character.
	//----------------------------------------------------------------------------------------
	MAXON_FUNCTION Bool EndsWith(CHARTYPE ch) const
	{
		return (GetLength() > 0) && GetChar(-1) == ch;
	}

	//----------------------------------------------------------------------------------------
	/// Checks if the current string end with a given string.
	/// @param[in] str								The string part.
	/// @return												True if the string ends with the string 'str'.
	//----------------------------------------------------------------------------------------
	MAXON_FUNCTION Bool EndsWith(const REFTYPE& str) const
	{
		Int cmpLen = str.GetLength();
		return ComparePart(str, STRINGCOMPARISON::MEMORY, -cmpLen, cmpLen) == COMPARERESULT::EQUAL;
	}

	//----------------------------------------------------------------------------------------
	/// Removes all characters with value <= 0x20 (e.g. space, tab, line feed) at the beginning and the end of the string.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	MAXON_FUNCTION Result<void> Trim();

	//----------------------------------------------------------------------------------------
	/// Proxy class to access individual characters of the string.
	//----------------------------------------------------------------------------------------
	class CharPtr
	{
	public:
		CharPtr(const CharPtr& rhs) : _str(rhs._str), _pos(rhs._pos)
		{
		}

		//----------------------------------------------------------------------------------------
		/// Write pointer to a character.
		//----------------------------------------------------------------------------------------
		CharPtr& operator =(const CharPtr& rhs)
		{
			return operator =((CHARTYPE) rhs);
		}

		//----------------------------------------------------------------------------------------
		/// Write pointer to a character.
		//----------------------------------------------------------------------------------------
		CharPtr& operator =(CHARTYPE c)
		{
			StringTemplate* s = _str.MakeWritable().GetPointer();
			if (s)
			{
				s->SetChar(_pos, c);
			}
			return *this;
		}

		//----------------------------------------------------------------------------------------
		/// Read pointer to a character.
		//----------------------------------------------------------------------------------------
		operator CHARTYPE() const
		{
			if (!_str.GetPointer())
			{
	#ifndef USE_API_MAXON
				DebugStop();
	#endif
				return 0;
			}
			return _str.GetPointer()->GetChar(_pos);
		}

	private:
		CharPtr(REFTYPE& str, Int pos) : _str(str), _pos(pos)
		{
		}

		REFTYPE& _str;
		const Int _pos;

		friend class String;
		friend class CString;
	};
};

//----------------------------------------------------------------------------------------
/// SysCharArray is inherited from BaseArray<SysChar> and modifies only the GetFirst() function which returns always a pointer,
/// even if the count is 0.
//----------------------------------------------------------------------------------------
class SysCharArray : public BaseArray<SysChar>
{
public:
	SysCharArray() : BaseArray<SysChar>()
	{
	}

	SysCharArray(SysCharArray&& src) : BaseArray<SysChar>(std::move(src))
	{
	}

	MAXON_OPERATOR_MOVE_ASSIGNMENT(SysCharArray);

	//----------------------------------------------------------------------------------------
	/// Returns the first element of the array.
	/// @return												Pointer to the first element (nullptr if the array is empty).
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE const SysChar* GetFirst() const
	{
		return _ptr;
	}

	//----------------------------------------------------------------------------------------
	/// Returns the first element of the array.
	/// @return												Pointer to the first element (nullptr if the array is empty).
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE SysChar* GetFirst()
	{
		return _ptr;
	}
};

//----------------------------------------------------------------------------------------
/// Class to store unicode strings.
/// String stores 16bit unicode characters. Any characters are legal, including 0C (strings
/// are not null-terminated).
/// Strings are reference-counted objects. This means that as long as you copy and do not
/// modify strings they are just referenced. The first modification breaks the link and it
/// becomes a unique new object.
///
/// @MAXON_ANNOTATION{refclass=false}
//----------------------------------------------------------------------------------------
class StringInterface : public StringTemplate<StringInterface, String, Utf32Char>
{
	MAXON_INTERFACE_NONVIRTUAL(StringInterface, MAXON_REFERENCE_COPY_ON_WRITE, "net.maxon.interface.string");

public:
	//----------------------------------------------------------------------------------------
	/// Converts a unicode string to a 8-bit encoded character string and copies it into @p buffer.
	/// The buffer size is taken into account.
	/// @param[in,out] buffer					Block describing the buffer. A \0 byte will be appended to the string in any case.
	/// @param[in] stringEncoding			Encoding for the string. By default UTF-8 is selected. If a nullptr is passed the data is truncated to Char and no conversion takes place.
	/// @return												The length of the corresponding 8-bit string for the given encoding. The \0 byte is excluded.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<Int> GetCStringBlock(const Block<Char>& buffer, const StringEncodingRef& stringEncoding = GetUtf8DefaultEncoder()) const;

	//----------------------------------------------------------------------------------------
	/// Converts a unicode string to a 8-bit encoded character string and appends it to the given @p array.
	/// @param[in,out] array					Array to be filled with the encoded string. The array is NOT terminated with a \0 byte.
	/// @param[in] stringEncoding			Encoding for the string. By default UTF-8 is selected. If a nullptr is passed the data is truncated to Char and no conversion takes place.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> GetCStringAppendArray(const NonConstArray<Char>& array, const StringEncodingRef& stringEncoding = GetUtf8DefaultEncoder()) const;

	//----------------------------------------------------------------------------------------
	/// Converts a unicode string to a 8-bit encoded character string and returns a new BaseArray<>.
	/// @param[in] stringEncoding			Encoding for the string. By default UTF-8 is selected. If a nullptr is passed the data is truncated to Char and no conversion takes place.
	/// @return												BaseArray<Char> with the encoded string. The string is \0 - terminated, but the array size is equal to the string length without the \0 character.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<BaseArray<Char>> GetCString(const StringEncodingRef& stringEncoding = GetUtf8DefaultEncoder()) const;

	//----------------------------------------------------------------------------------------
	/// Initializes the string with a given 8-bit Char string with the given encoding.
	/// @param[out] buffer						Pointer to the 8-bit character string.
	/// @param[in] count							Number of valid characters in the buffer, a value of -1 automatically detects the
	/// 															string length by searching for the first \0 character, otherwise count is relevant and not \0.
	/// @param[in] stringDecoding			DECODING for the string. By default UTF-8 is selected. If a nullptr is passed the data is copied 1:1.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> SetCString(const Char* buffer, Int count = -1, const StringDecodingRef& stringDecoding = GetUtf8DefaultDecoder());

	//----------------------------------------------------------------------------------------
	/// Initializes the string with a given 8-bit Char string with the given encoding.
	/// @param[out] buffer						Block with an 8-bit character string.
	/// @param[in] stringDecoding			DECODING for the string. By default UTF-8 is selected. If a nullptr is passed the data is copied 1:1.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	MAXON_FUNCTION Result<void> SetCString(const Block<const Char>& buffer, const StringDecodingRef& stringDecoding = GetUtf8DefaultDecoder())
	{
		return SetCString(buffer.GetFirst(), buffer.GetCount(), stringDecoding);
	}

	//----------------------------------------------------------------------------------------
	/// Returns a copy of the string as a system-specific character array. The string will be \0 - terminated.
	/// GetFirst() on that call always return a valid pointer, even if the string length is 0!
	/// GetLength() returns the real string length without the trailing \0.
	/// @code
	/// SysCharArray converted = str.GetSystemEncoding() iferr_return;
	/// @endcode
	/// @return												A copy of the character string.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<SysCharArray> GetSystemEncoding() const;

	//----------------------------------------------------------------------------------------
	/// Initializes the String with the given system-specific character string.
	/// @param[in] buffer							Pointer to the buffer with the string.
	/// @param[in] count							Number of valid characters in the buffer.
	/// 															A count of -1 calculates the string length automatically, terminating when \0 is found.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> SetSystemEncoding(const SysChar* buffer, Int count = -1);

	//----------------------------------------------------------------------------------------
	/// Initializes the String with the given 32-bit unicode character string.
	/// @param[in] buffer							Pointer to the buffer with the string.
	/// @param[in] count							Number of valid characters in the buffer.
	/// 															A count of -1 calculates the string length automatically, terminating when \0 is found.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> SetUtf32(const Utf32Char* buffer, Int count = -1);

	//----------------------------------------------------------------------------------------
	/// Copies the string as UTF-16 encoded characters into the passed array.
	/// The array will be resized and contain the non \0 - terminated data.
	/// @param[out] stringData				The array to receive the data.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> GetUtf16(Utf16CharBuffer& stringData) const;

	//----------------------------------------------------------------------------------------
	/// Initializes the String with the given 16-bit unicode character string.
	/// @param[in] buffer							Pointer to the buffer with the string.
	/// @param[in] count							Number of valid characters in the buffer.
	/// 															A count of -1 calculates the string length automatically, terminating when \0 is found.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> SetUtf16(const Utf16Char* buffer, Int count = -1);

	//----------------------------------------------------------------------------------------
	/// Returns a readable string of the content.
	/// @param[in] formatStatement		Nullptr or additional formatting instruction. Currently no additional formatting instructions are supported.
	/// @return												The converted result.
	//----------------------------------------------------------------------------------------
	inline String ToString(const FormatStatement* formatStatement) const;

	//----------------------------------------------------------------------------------------
	/// @markInternal
	/// Caches a static constant string and returns a maxon::String.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD const String& GetAndCacheConstString(const wchar_t* chr, Int len);

	//----------------------------------------------------------------------------------------
	/// @markInternal
	/// Caches a static constant string and returns a maxon::String.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD const String& GetAndCacheConstString(const Char* chr, Int len, Int isUtf8);

	//----------------------------------------------------------------------------------------
	/// @markInternal
	/// Converts the given enum value to a string.
	/// @param[in] value							The enum value, converted to UInt64.
	/// @param[in] enumName						The C++ name of the enum.
	/// @param[in] size								The size of the enum type.
	/// @param[in] flags							True for an enum declared as MAXON_ENUM_FLAGS, false otherwise.
	/// @param[in] enumValues					Pointer to an array of the enumerator values of the enum.
	/// @param[in] enumValueNames			Pointer to a memory block which contains the enumerator names of the enum one after another (each null-terminated), and a final null terminator.
	/// @param[in] formatStatement		Nullptr or additional formatting instruction. Currently no additional formatting instructions are supported.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD String PrivateEnumToString(UInt64 value, const Char* enumName, Int size, Bool flags, const UInt64* enumValues, const Char* enumValueNames, const FormatStatement* formatStatement);

	//----------------------------------------------------------------------------------------
	/// Returns the internal character array. Temporarily renamed.
	/// @return												Block describing the internal character buffer. The data is read only! Please note that GetCount() will return the number of characters (and not bytes).
	//----------------------------------------------------------------------------------------
	MAXON_METHOD StridedBlock<const Generic> GetVariableInternalData() const;

	//----------------------------------------------------------------------------------------
	/// Retrieves the string's character width. The width determines the result of GetInternalDataX().
	/// @return												1, 2 or 4 (bytes).
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Int GetCharacterWidth() const;

	//----------------------------------------------------------------------------------------
	/// Converts a string using a UTF32 -> UTF32 encoder or decoder (e.g. StringEncodings::Url32).
	/// @param[in] converter					String encoder or decoder that should be applied to the conversion.
	/// @return												The converted string.
	//----------------------------------------------------------------------------------------
	MAXON_FUNCTION Result<String> ConvertString(const StreamConversionRef& converter) const;
};

//----------------------------------------------------------------------------------------
/// Class to store ASCII strings.
/// CString stores 8 bit characters. Any characters are legal, including 0C (strings
/// are not null-terminated).
/// CStrings are reference-counted objects. This means that as long as you copy and do not
/// modify strings they are just referenced. The first modification breaks the link and it
/// becomes a unique new object.
///
/// @MAXON_ANNOTATION{refclass=false}
//----------------------------------------------------------------------------------------
class CStringInterface : public StringTemplate<CStringInterface, CString, Char>
{
	MAXON_INTERFACE_NONVIRTUAL(CStringInterface, MAXON_REFERENCE_COPY_ON_WRITE, "net.maxon.interface.cstring");

public:
	//----------------------------------------------------------------------------------------
	/// Copies the string into 'buffer'.
	/// @param[in,out] buffer					Block describing the buffer. A \0 byte will be appended to the string in any case.
	/// @return												The length of the corresponding 8-bit string for the given encoding. the \0 byte is not counted.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<Int> GetCStringBlock(const Block<Char>& buffer) const;

	//----------------------------------------------------------------------------------------
	/// Appends the string to the given @p array.
	/// @param[in,out] array					Array to be filled with the string. The string is NOT terminated with a \0 byte.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> GetCStringAppendArray(const NonConstArray<Char>& array) const;

	//----------------------------------------------------------------------------------------
	/// Initializes the string with a given 8-bit Char string (the CString will contain an exact copy of
	/// the buffer, there's no encoding to a different character set).
	/// @param[out] buffer						Pointer to the 8-bit character string.
	/// @param[in] count							Number of valid characters in the buffer, a value of -1 automatically detects the
	/// 															string length by searching for the first \0 character, otherwise count is relevant and not \0.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> SetCString(const Char* buffer, Int count = -1);

	//----------------------------------------------------------------------------------------
	/// Initializes the string with a given 8-bit Char string with the given encoding.
	/// @param[out] buffer						Block with an 8-bit character string.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	MAXON_FUNCTION Result<void> SetCString(const Block<const Char>& buffer)
	{
		return SetCString(buffer.GetFirst(), buffer.GetCount());
	}

	//----------------------------------------------------------------------------------------
	/// Returns a copy of the C string in a new memory block. If a string is empty this function returns a string with a terminating null character.
	/// @return												BaseArray<Char> with the encoded string. The string is \0 - terminated, so the last character in the array is \0.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<BaseArray<Char>> GetCString() const;

	//----------------------------------------------------------------------------------------
	/// Returns a readable string of the content.
	/// @param[in] formatStatement		Nullptr or additional formatting instruction. Currently no additional formatting instructions are supported.
	/// @return												The converted result.
	//----------------------------------------------------------------------------------------
	String ToString(const FormatStatement* formatStatement) const;

	//----------------------------------------------------------------------------------------
	/// Returns the internal character array.
	/// @return												Block describing the internal character buffer. The data is read only!
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Block<const Char> GetInternalData() const;

	//----------------------------------------------------------------------------------------
	/// @markInternal
	/// Caches a static constant string and returns a maxon::CString.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD const CString& GetAndCacheConstString(const Char* chr, Int len);
};


// include auto generated header file here
#include "string1.hxx"

// redefine slightly faster version directly calling maxon::StringInterface
#undef CONSTSTRING
#define CONSTSTRING(x) (maxon::StringInterface::GetAndCacheConstString(PRIVATE_MAXON_AS_UTF8("") PRIVATE_MAXON_AS_UTF8(x), SIZEOF(PRIVATE_MAXON_AS_UTF8(x)) - 1, MAXON_CONSTEXPR_EVAL(maxon::Bool, maxon::PrivateIsUtf8(PRIVATE_MAXON_AS_UTF8(x), SIZEOF(PRIVATE_MAXON_AS_UTF8(x))))))
#define CONSTCSTRING(x) (maxon::CStringInterface::GetAndCacheConstString("" x, SIZEOF(x) / SIZEOF(x[0]) - 1))

//----------------------------------------------------------------------------------------
/// Creates a (constant) C-string.
//----------------------------------------------------------------------------------------
inline const CString& operator "" _cs(const char* str, std::size_t cnt)
{
	return maxon::CStringInterface::GetAndCacheConstString(str, cnt);
}

//----------------------------------------------------------------------------------------
/// Class to store unicode strings.
/// String stores unicode characters. Any unicode characters are legal, including 0C (strings
/// are not null-terminated).
/// Strings are reference-counted objects. This means that as long as you copy and do not
/// modify strings they are just referenced. The first modification breaks the link and it
/// becomes a unique new object.
///
/// Error handling for String
/// For convenience the String class has a relaxed out of memory handling, for example String("Example", 7) might fail,
/// but since it's a constructor there's no Result returned. The same goes for String a += b;
/// In most cases this is no problem at all: If for example you want to concatenate a file url and this fails then loading
/// the file will fail anyway.
/// Nonetheless there cases where you must ensure that a string operation has succeeded. To enable this for methods, operators
/// or constructor which are not returning a Result but modify the String (are non-const) the internal reference will be
/// set to a nullptr on allocation failure. And this can be checked using iferr, iferr_return (or even GetPointer() would work).
/// For example:
/// @code
/// String x = String(cstr, strlen(cstr)) iferr_return;
/// String y = "example"_s iferr_return;
/// x.Append(y) iferr_return;
/// (x += y) iferr_return;
/// x = (x + y) iferr_return;
/// String z = x.GetPart(0, 1) iferr_return;
/// @endcode
/// @note For + or += you have to enclose the expression in brackets, otherwise iferr_return will check the wrong term.
/// @note Error detection does not work for concatenated operations, e.g. for x.Append(y).Append(z) you cannot detect
/// an error, the same goes for x = x + y + z;
//----------------------------------------------------------------------------------------
class String : public StringInterface::Reference
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(String, Reference);

	//----------------------------------------------------------------------------------------
	/// Constructor from Char array.
	/// If you have static strings use "..."_s instead.
	/// @param[in] str								C string block.
	/// @param[in] count							Number of characters, -1 to auto detect the length of the string (search for the first 0).
	/// @param[in] stringDecoding			Encoding type.
	//----------------------------------------------------------------------------------------
	explicit String(const Char* str, Int count, const StringDecodingRef& stringDecoding = GetUtf8DefaultDecoder())
	{
		if (SetCString(str, count, stringDecoding) == FAILED)
			*this = nullptr;
	}

	//----------------------------------------------------------------------------------------
	/// Constructor from Char array.
	/// If you have static strings use "..."_s instead.
	/// @param[in] str								C string block.
	/// @param[in] stringDecoding			Encoding type.
	//----------------------------------------------------------------------------------------
	explicit String(const Char* str, const StringDecodingRef& stringDecoding = GetUtf8DefaultDecoder())
	{
		if (SetCString(str, -1, stringDecoding) == FAILED)
			*this = nullptr;
	}
	
	//----------------------------------------------------------------------------------------
	/// Constructor from a Char Block.
	/// If you have static strings use "..."_s instead.
	/// @param[in] str								Char block, for example a BaseArray<Char>.
	/// @param[in] stringDecoding			Encoding type.
	//----------------------------------------------------------------------------------------
	explicit String(const Block<const Char>& str, const StringDecodingRef& stringDecoding = GetUtf8DefaultDecoder())
	{
		if (SetCString(str, stringDecoding) == FAILED)
			*this = nullptr;
	}

	//----------------------------------------------------------------------------------------
	/// Constructor from CString.
	/// @param[in] str								CString.
	/// @param[in] stringDecoding			Encoding type.
	//----------------------------------------------------------------------------------------
	explicit String(const CString& str, const StringDecodingRef& stringDecoding = GetUtf8DefaultDecoder());

	//----------------------------------------------------------------------------------------
	/// Constructor from UTF-32 Utf32Char array.
	/// If you have static character strings use "..."_s instead.
	/// @param[in] str								UTF-32 character block.
	/// @param[in] count							Number of characters, -1 to auto detect the length of the string (search for the first 0).
	//----------------------------------------------------------------------------------------
	explicit String(const Utf32Char* str, Int count)
	{
		if (SetUtf32(str, count) == FAILED)
			*this = nullptr;
	}

	//----------------------------------------------------------------------------------------
	/// Constructor from UTF-32 Utf32Char Block.
	/// @param[in] str								UTF-32 character block.
	//----------------------------------------------------------------------------------------
	explicit String(const Block<const Utf32Char>& str)
	{
		if (SetUtf32(str.GetFirst(), str.GetCount()) == FAILED)
			*this = nullptr;
	}

	//----------------------------------------------------------------------------------------
	/// Constructor from UTF-16 Utf16Char array.
	/// @param[in] str								UTF-16 character block.
	/// @param[in] count							Number of characters, -1 to auto detect the length of the string (search for the first 0).
	//----------------------------------------------------------------------------------------
	explicit String(const Utf16Char* str, Int count)
	{
		if (SetUtf16(str, count) == FAILED)
			*this = nullptr;
	}

	//----------------------------------------------------------------------------------------
	/// Constructor to create a string with a specific length and a default character.
	/// @param[in] count							Number of characters of the new string.
	/// @param[in] fillChar						Character to fill the string with.
	//----------------------------------------------------------------------------------------
	explicit String(Int count, Utf32Char fillChar)
	{
		if (Init(count, fillChar) == FAILED)
			*this = nullptr;
	}

	//----------------------------------------------------------------------------------------
	/// Constructs a string consisting of #prefix followed by an \@ sign and the hex-formatted #ptr.
	/// @param[in] prefix							The prefix for the string.
	/// @param[in] ptr								A pointer.
	//----------------------------------------------------------------------------------------
	String(const Id& prefix, const void* ptr);

	//----------------------------------------------------------------------------------------
	/// Constructor to create a string from a prefix and pointer address as hexadecimal text.
	/// @param[in] prefix							The prefix string.
	/// @param[in] ptr								The pointer that will be added as hexadecimal text.
	/// @param[in] prefix0x						If true the pointer will start with '0x'.
	//----------------------------------------------------------------------------------------
	String(const String& prefix, const void* ptr, Bool prefix0x = true);

	//----------------------------------------------------------------------------------------
	/// Index operator to access single characters of the string.
	/// @param[in] pos								Position within the string the first character starts with an index of 0. If the position is out of boundaries 0 will be returned.
	/// @return												Utf32Char for read (right of =), Utf32Char& for write (left of =).
	//----------------------------------------------------------------------------------------
	Utf32Char operator [](Int pos) const
	{
		if (!GetPointer())
		{
#ifndef USE_API_MAXON
			DebugStop();
#endif
			return 0;
		}
		return GetPointer()->GetChar(pos);
	}

	//----------------------------------------------------------------------------------------
	/// Index operator to access single characters of the string.
	/// @param[in] position						Position within the string the first character starts with an index of 0. if the position is out of boundaries no changes will be made.
	/// @return												Utf32Char for read (right of =), Utf32Char& for write (left of =).
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE StringInterface::CharPtr operator [](Int position)
	{
		return StringInterface::CharPtr(*this, position);
	}

	using ValueType = Utf32Char;

	class StringIterator : public BaseIterator<const StridedBlock<const Generic>, true>
	{
	public:
		explicit StringIterator() : BaseIterator(nullptr, 0, 1) {}
		explicit StringIterator(const StridedBlock<const Generic>& buffer, Int start = 0) : BaseIterator(buffer, start) {}
		Utf32Char operator *() const
		{
			Int cs = this->_stride;

			if (cs < 2)
				return *(UChar*)this->_data;
			else if (cs == 2)
				return *(Utf16Char*)this->_data;
			else
				return *(Utf32Char*)this->_data;
		}
	private:
		Generic* operator ->() const;
	};


	using ConstIterator = StringIterator;
	using Iterator = ConstIterator;

	//----------------------------------------------------------------------------------------
	/// Returns and iterator pointing to the first character of this string.
	/// @return												Iterator for first character.
	//----------------------------------------------------------------------------------------
	ConstIterator Begin() const
	{
		if (MAXON_UNLIKELY(GetPointer() == nullptr))
			return ConstIterator();

		return ConstIterator(GetPointer()->GetVariableInternalData());
	}

	//----------------------------------------------------------------------------------------
	/// Returns and iterator pointing to the end of this string (one behind last character).
	/// @return												Iterator for the end.
	//----------------------------------------------------------------------------------------
	ConstIterator End() const
	{
		if (MAXON_UNLIKELY(GetPointer() == nullptr))
			return ConstIterator();

		StridedBlock<const Generic> genericBlock = GetPointer()->GetVariableInternalData();
		return ConstIterator(genericBlock, genericBlock.GetCount());
	}

	//----------------------------------------------------------------------------------------
	/// Returns if the string length is zero.
	/// @return												True if the string doesn't contain any character, or if it is a nullptr.
	//----------------------------------------------------------------------------------------
	Bool IsEmpty() const
	{
		return !GetPointer() || !GetPointer()->GetLength();
	}

	//----------------------------------------------------------------------------------------
	/// Returns if the string contains any characters.
	/// @return												True if the string contains any character.
	//----------------------------------------------------------------------------------------
	Bool IsPopulated() const
	{
		return !IsEmpty();
	}

	//----------------------------------------------------------------------------------------
	/// Appends #str at the end of this string.
	/// @param[in] str								Another string to append.
	/// @return												Reference to this string.
	//----------------------------------------------------------------------------------------
	String& operator +=(const String& str)
	{
		if (Append(str) == FAILED)
		{
			*this = String();	// ###STRINGPTRCHECK
		}

		return *this;
	}

	//----------------------------------------------------------------------------------------
	/// Returns a string with the platform specific line ending.
	/// @return												String containing the line ending ("\r\n" or "\r").
	//----------------------------------------------------------------------------------------
	static const String& GetLineEnd();

private:
	void operator ->() const;
};


//----------------------------------------------------------------------------------------
/// Class to store 8 bit strings.
/// The CString stores 8 bit characters. Any characters are legal, including 0C (for example
/// CString("\0\0\0\0", 4) will result in a CString with length 4).
/// CStrings are reference-counted objects. This means that as long as you copy and do not
/// modify strings they are just referenced. The first modification breaks the link and it
/// becomes a unique new object.
/// For error handling see String.
//----------------------------------------------------------------------------------------
class CString : public CStringInterface::Reference
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(CString, Reference);

	//----------------------------------------------------------------------------------------
	/// Constructor for Char array.
	/// If you have static Char strings use "..."_cs instead.
	/// @param[in] str								C string block.
	/// @param[in] count							Number of characters, -1 to auto detect the length of the string (search for the first 0).
	//----------------------------------------------------------------------------------------
	explicit CString(const Char* str, Int count = -1)
	{
		if (SetCString(str, count) == FAILED)
			*this = nullptr;
	}

	//----------------------------------------------------------------------------------------
	/// Constructor to create a string with a specific length and a default character.
	/// @param[in] count							Number of characters of the new string.
	/// @param[in] fillChar						Character to fill the string with.
	//----------------------------------------------------------------------------------------
	explicit CString(Int count, Char fillChar)
	{
		if (Init(count, fillChar) == FAILED)
			*this = nullptr;
	}
	
	//----------------------------------------------------------------------------------------
	/// Constructor from a Char Block.
	/// If you have static strings use "..."_cs instead.
	/// @param[in] str								Char block, for example a BaseArray<Char>.
	//----------------------------------------------------------------------------------------
	explicit CString(const Block<const Char>& str)
	{
		if (SetCString(str) == FAILED)
			*this = nullptr;
	}

	//----------------------------------------------------------------------------------------
	/// Constructor to create a CString from a String. The lower byte of each character will be copied,
	/// whereas the upper byte will be discarded.
	/// @param[in] str								Unicode string.
	/// @param[in] stringEncoding			Encoding for the string. By default utf8 is selected. If a nullptr is passed the data is truncated to Char and no conversion takes place.
	//----------------------------------------------------------------------------------------
	explicit CString(const String& str, const StringEncodingRef& stringEncoding = GetUtf8DefaultEncoder());

	//----------------------------------------------------------------------------------------
	/// Index operator to access single characters of the string.
	/// @param[in] pos								Position within the string the first character starts with an index of 0. If the position is out of boundaries 0 will be returned.
	/// @return												Utf32Char for read (right of =), Utf32Char& for write (left of =).
	//----------------------------------------------------------------------------------------
	Char operator [](Int pos) const
	{
		if (!GetPointer())
		{
#ifndef USE_API_MAXON
			DebugStop();
#endif
			return 0;
		}
		return GetPointer()->GetChar(pos);
	}

	//----------------------------------------------------------------------------------------
	/// Index operator to access single characters of the string.
	/// @param[in] position						Position within the string the first character starts with an index of 0. if the position is out of boundaries no changes will be made.
	/// @return												Utf32Char for read (right of =), Utf32Char& for write (left of =).
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE CStringInterface::CharPtr operator [](Int position)
	{
		return CStringInterface::CharPtr(*this, position);
	}

	using ConstIterator = BaseIterator<const CString, false>;
	using Iterator = ConstIterator;
	using ValueType = Char;

	ConstIterator Begin() const
	{
		if (!GetPointer())
			return ConstIterator();
		Block<const Char> b = GetPointer()->GetInternalData();
		return ConstIterator(b.GetFirst());
	}

	ConstIterator End() const
	{
		if (!GetPointer())
			return ConstIterator();
		Block<const Char> b = GetPointer()->GetInternalData();
		return ConstIterator(b.GetFirst() + b.GetCount());
	}

	//----------------------------------------------------------------------------------------
	/// Returns if the string length is zero.
	/// @return												True if the string doesn't contain any character, or if it is a nullptr.
	//----------------------------------------------------------------------------------------
	Bool IsEmpty() const
	{
		return !GetPointer() || !GetPointer()->GetLength();
	}

	//----------------------------------------------------------------------------------------
	/// Returns if the string contains any characters.
	/// @return												True if the string contains any character.
	//----------------------------------------------------------------------------------------
	Bool IsPopulated() const
	{
		return GetPointer() && (GetPointer()->GetLength() > 0);
	}

	CString& operator +=(const CString& str)
	{
		if (Append(str) == FAILED)
			DebugStop();
		return *this;
	}

	//----------------------------------------------------------------------------------------
	/// Conversion to const Char*, returns the pointer to a null-terminated C string.
	/// @return												Pointer to null terminated C string (can never be a nullptr).
	//----------------------------------------------------------------------------------------
	operator const Char*() const
	{
		const CStringInterface* itf = GetPointer();
		return itf ? itf->GetInternalData().GetFirst() : "";
	}

	//----------------------------------------------------------------------------------------
	/// Converts this CString to a block of characters. The null-terminator isn't part of the block.
	/// @return												Block of characters of this CString.
	//----------------------------------------------------------------------------------------
	operator Block<const Char>() const
	{
		return GetInternalData();
	}

	//----------------------------------------------------------------------------------------
	/// Returns a string with the platform specific line ending.
	/// @return												String containing the line ending ("\r\n" or "\r").
	//----------------------------------------------------------------------------------------
	static const CString& GetLineEnd();

private:
	void operator ->() const;
};

class DataSerializeInterface;

inline Result<void> DescribeIO(const CStringInterface& s, const DataSerializeInterface& dsi) { return OK; }
inline Result<void> DescribeIO(const StringInterface& s, const DataSerializeInterface& dsi) { return OK; }

//----------------------------------------------------------------------------------------
/// Concatenates two strings, please don't use a = a + b since this is several times slower than a += b.
//----------------------------------------------------------------------------------------
inline String operator +(const String& a, const String& b)
{
	String s(a);
	s += b;
	return s;
}

inline String&& operator +(String&& a, const String& b)
{
	return std::move(a += b);
}

inline String&& operator +(String&& a, String&& b)
{
	return std::move(a += b);
}

inline String&& operator +(const String& a, String&& b)
{
	if (b.Insert(0, a) == FAILED)
		b = nullptr;

	return std::move(b);
}

//----------------------------------------------------------------------------------------
/// Concatenates two strings, please don't use a = a + b since this is several times slower than a += b.
//----------------------------------------------------------------------------------------
inline CString operator +(const CString& a, const CString& b)
{
	CString s(a);
	s += b;
	return s;
}

inline CString&& operator +(CString&& a, const CString& b)
{
	return std::move(a += b);
}

inline CString&& operator +(CString&& a, CString&& b)
{
	return std::move(a += b);
}

inline CString&& operator +(const CString& a, CString&& b)
{
	if (b.Insert(0, a) == FAILED)
		b = nullptr;

	return std::move(b);
}


String& operator +=(String& s, const CString& b);

inline String operator +(const String& a, const CString& b)
{
	String s(a);
	s += b;
	return s;
}

inline String&& operator +(String&& a, const CString& b)
{
	return std::move(a += b);
}


String operator +(const String& a, const Char* b);

String&& operator +(String&& a, const Char* b);


inline CString operator +(const CString& a, const Char* b)
{
	CString s(a);
	s += CString(b);
	return s;
}

inline CString&& operator +(CString&& a, const Char* b)
{
	return std::move(a += CString(b));
}


// overloads so that an empty String/CString does not output "nullptr"
inline String ToString(const String& str, const FormatStatement* formatStatement, Bool = false) { return str; }
inline String ToString(const CString& str, const FormatStatement* formatStatement, Bool = false) { return String(str); }

String StringInterface::ToString(const FormatStatement* formatStatement) const
{
	return String(const_cast<StringInterface*>(this));
}


template <typename T, Bool INTERFACETYPE> class ToStringHelper2;

template <typename T> class ToStringHelper2<T, false>
{
public:
	static inline String ToString(const T* object, const FormatStatement* formatStatement, Bool checkDataType); // defined in datatype.h
};

template <typename T> class ToStringHelper2<T, true>
{
public:
	static String ToString(const T* object, const FormatStatement* formatStatement, Bool)
	{
		return String(T::_interface.GetId(), object);
	}
};

template <typename T> inline decltype(std::declval<T>().ToString(nullptr)) ToStringHelper(const T* object, const FormatStatement* formatStatement, Int*)
{
	return object ? object->ToString(formatStatement) : "nullptr"_s;
}

template <typename T> inline String ToStringHelper(const T* object, const FormatStatement* formatStatement, const Int* checkDataType)
{
	return object ? ToStringHelper2<T, IsNonvirtualInterfaceType<T>::value>::ToString(object, formatStatement, checkDataType != nullptr) : "nullptr"_s;
}

template <typename T> inline typename std::enable_if<!std::is_enum<T>::value, String>::type ToString(const T& object, const FormatStatement* formatStatement, Bool checkDataType = true)
{
	return ToStringHelper(Dereference<T>::GetPointer(object), formatStatement, (Int*) checkDataType);
}

template <typename T> inline typename std::enable_if<!std::is_function<T>::value, String>::type ToString(const T* object, const FormatStatement* formatStatement)
{
	return ToStringHelper(object, formatStatement, (Int*) 1);
}

template <typename T> inline String GlobalToString(const T& object, const FormatStatement* formatStatement, Bool checkDataType) { return ToString(object, formatStatement, checkDataType); }


inline const String& ToString(Bool val, const FormatStatement* formatStatement, Bool = false) { return val ? "true"_s : "false"_s; }

//----------------------------------------------------------------------------------------
/// Converts a variable into a readable string.
/// @param[in] val								The value that will be converted.
/// @param[in] formatStatement		Nullptr or additional formatting instruction. See also @ref format_integer.
/// @param[in] checkDataType			Must be set to false, only for internal use.
/// @return												The converted result.
//----------------------------------------------------------------------------------------
String ToString(Char val, const FormatStatement* formatStatement, Bool checkDataType = false);

//----------------------------------------------------------------------------------------
/// Converts a variable into a readable string.
/// @param[in] val								The value that will be converted.
/// @param[in] formatStatement		Nullptr or additional formatting instruction. See also @ref format_integer.
/// @param[in] checkDataType			Must be set to false, only for internal use.
/// @return												The converted result.
//----------------------------------------------------------------------------------------
String ToString(UChar val, const FormatStatement* formatStatement, Bool checkDataType = false);

//----------------------------------------------------------------------------------------
/// Converts a variable into a readable string.
/// @param[in] val								The value that will be converted.
/// @param[in] formatStatement		Nullptr or additional formatting instruction. See also @ref format_integer.
/// @param[in] checkDataType			Must be set to false, only for internal use.
/// @return												The converted result.
//----------------------------------------------------------------------------------------
String ToString(Int16 val, const FormatStatement* formatStatement, Bool checkDataType = false);

//----------------------------------------------------------------------------------------
/// Converts a variable into a readable string.
/// @param[in] val								The value that will be converted.
/// @param[in] formatStatement		Nullptr or additional formatting instruction. See also @ref format_integer.
/// @param[in] checkDataType			Must be set to false, only for internal use.
/// @return												The converted result.
//----------------------------------------------------------------------------------------
String ToString(Int32 val, const FormatStatement* formatStatement, Bool checkDataType = false);

//----------------------------------------------------------------------------------------
/// Converts a variable into a readable string.
/// @param[in] val								The value that will be converted.
/// @param[in] formatStatement		Nullptr or additional formatting instruction. See also @ref format_integer.
/// @param[in] checkDataType			Must be set to false, only for internal use.
/// @return												The converted result.
//----------------------------------------------------------------------------------------
String ToString(Int64 val, const FormatStatement* formatStatement, Bool checkDataType = false);

//----------------------------------------------------------------------------------------
/// Converts a variable into a readable string.
/// @param[in] val								The value that will be converted.
/// @param[in] formatStatement		Nullptr or additional formatting instruction. See also @ref format_integer.
/// @param[in] checkDataType			Must be set to false, only for internal use.
/// @return												The converted result.
//----------------------------------------------------------------------------------------
String ToString(UInt16 val, const FormatStatement* formatStatement, Bool checkDataType = false);

//----------------------------------------------------------------------------------------
/// Converts a variable into a readable string.
/// @param[in] val								The value that will be converted.
/// @param[in] formatStatement		Nullptr or additional formatting instruction. See also @ref format_integer.
/// @param[in] checkDataType			Must be set to false, only for internal use.
/// @return												The converted result.
//----------------------------------------------------------------------------------------
String ToString(UInt32 val, const FormatStatement* formatStatement, Bool checkDataType = false);

//----------------------------------------------------------------------------------------
/// Converts a variable into a readable string.
/// @param[in] val								The value that will be converted.
/// @param[in] formatStatement		Nullptr or additional formatting instruction. See also @ref format_integer.
/// @param[in] checkDataType			Must be set to false, only for internal use.
/// @return												The converted result.
//----------------------------------------------------------------------------------------
String ToString(UInt64 val, const FormatStatement* formatStatement, Bool checkDataType = false);

//----------------------------------------------------------------------------------------
/// Converts a variable into a readable string.
/// @param[in] val								The value that will be converted.
/// @param[in] formatStatement		Nullptr or additional formatting instruction. See also @ref format_float.
/// @param[in] checkDataType			Must be set to false, only for internal use.
/// @return												The converted result.
//----------------------------------------------------------------------------------------
String ToString(Float64 val, const FormatStatement* formatStatement, Bool checkDataType = false);

//----------------------------------------------------------------------------------------
/// Converts a variable into a readable string.
/// @param[in] val								The value that will be converted.
/// @param[in] formatStatement		Nullptr or additional formatting instruction. See also @ref format_float.
/// @param[in] checkDataType			Must be set to false, only for internal use.
/// @return												The converted result.
//----------------------------------------------------------------------------------------
String ToString(Float32 val, const FormatStatement* formatStatement, Bool checkDataType = false);

//----------------------------------------------------------------------------------------
/// Converts a variable into a readable string.
/// @param[in] val								The value that will be converted.
/// @param[in] formatStatement		Nullptr or additional formatting instruction. See also @ref format_integer.
/// @param[in] checkDataType			Must be set to false, only for internal use.
/// @return												The converted result.
//----------------------------------------------------------------------------------------
String ToString(Utf16Char val, const FormatStatement* formatStatement, Bool checkDataType = false);

//----------------------------------------------------------------------------------------
/// Converts a variable into a readable string.
/// @param[in] val								The value that will be converted.
/// @param[in] formatStatement		Nullptr or additional formatting instruction. See also @ref format_integer.
/// @param[in] checkDataType			Must be set to false, only for internal use.
/// @return												The converted result.
//----------------------------------------------------------------------------------------
String ToString(Utf32Char val, const FormatStatement* formatStatement, Bool checkDataType = false);

// both versions must exist for Char* and const Char* , otherwise the "const T& object" version is picked by the compiler

//----------------------------------------------------------------------------------------
/// Converts a C-string into a readable string.
/// @param[in] val								The value that will be converted.
/// @param[in] formatStatement		Nullptr or additional formatting instruction. No formatting instructions are currently supported.
/// @param[in] checkDataType			Must be set to false, only for internal use.
/// @return												The converted result.
//----------------------------------------------------------------------------------------
String ToString(Char* val, const FormatStatement* formatStatement, Bool checkDataType = false);

//----------------------------------------------------------------------------------------
/// Converts a C-string into a readable string.
/// @param[in] val								The value that will be converted.
/// @param[in] formatStatement		Nullptr or additional formatting instruction. No formatting instructions are currently supported.
/// @param[in] checkDataType			Must be set to false, only for internal use.
/// @return												The converted result.
//----------------------------------------------------------------------------------------
String ToString(const Char* val, const FormatStatement* formatStatement, Bool checkDataType = false);

// both versions must exist for void* and const void* , otherwise the "const T& object" version is picked by the compiler

//----------------------------------------------------------------------------------------
/// Converts a pointer into a readable string.
/// @param[in] val								The value that will be converted.
/// @param[in] formatStatement		Nullptr or additional formatting instruction. See also @ref format_pointer.
/// @param[in] checkDataType			Must be set to false, only for internal use.
/// @return												The converted result.
//----------------------------------------------------------------------------------------
String ToString(const void* val, const FormatStatement* formatStatement, Bool checkDataType = false);

//----------------------------------------------------------------------------------------
/// Converts a pointer into a readable string.
/// @param[in] val								The value that will be converted.
/// @param[in] formatStatement		Nullptr or additional formatting instruction. See also @ref format_pointer.
/// @param[in] checkDataType			Must be set to false, only for internal use.
/// @return												The converted result.
//----------------------------------------------------------------------------------------
inline String ToString(void* val, const FormatStatement* formatStatement, Bool checkDataType = false) { return ToString(static_cast<const void*>(val), formatStatement, checkDataType); }

// both versions must exist for Generic* and const Generic* , otherwise the "const T& object" version is picked by the compiler

//----------------------------------------------------------------------------------------
/// Converts a pointer into a readable string.
/// @param[in] val								The value that will be converted.
/// @param[in] formatStatement		Nullptr or additional formatting instruction. See also @ref format_pointer.
/// @param[in] checkDataType			Must be set to false, only for internal use.
/// @return												The converted result.
//----------------------------------------------------------------------------------------
inline String ToString(const Generic* val, const FormatStatement* formatStatement, Bool checkDataType = false) { return ToString(static_cast<const void*>(val), formatStatement, checkDataType); }

//----------------------------------------------------------------------------------------
/// Converts a pointer into a readable string.
/// @param[in] val								The value that will be converted.
/// @param[in] formatStatement		Nullptr or additional formatting instruction. See also @ref format_pointer.
/// @param[in] checkDataType			Must be set to false, only for internal use.
/// @return												The converted result.
//----------------------------------------------------------------------------------------
inline String ToString(Generic* val, const FormatStatement* formatStatement, Bool checkDataType = false) { return ToString(static_cast<const void*>(val), formatStatement, checkDataType); }

String ToString(const DataType& type, const FormatStatement* formatStatement, Bool checkDataType = false);

class StringProxy
{
public:
	String str;
};

template <typename COLLECTION, typename SUPER> String BaseCollection<COLLECTION, SUPER>::ToString(const FormatStatement* formatStatement) const
{
	String result = "{"_s;
	Bool first = true;
	for (AutoIterator<const COLLECTION> i(*static_cast<const COLLECTION*>(this)); i; ++i)
	{
		if (first)
		{
			first = false;
		}
		else
		{
			if (result.Append(","_s) == FAILED)
				DebugStop();
		}

		if (result.Append(GlobalToString(*i, formatStatement)) == FAILED)
			DebugStop();
	}
	if (result.Append("}"_s) == FAILED)
		DebugStop();
	
	return result;
}

template <typename ITERATOR, typename SUPER> String ForEachIterator<ITERATOR, SUPER>::ToString(const FormatStatement* formatStatement)
{
	String result = "{"_s;
	Bool first = true;
	while (*static_cast<ITERATOR*>(this))
	{
		if (first)
		{
			first = false;
		}
		else
		{
			if (result.Append(","_s) == FAILED)
				DebugStop();
		}
		if (result.Append(GlobalToString(static_cast<ITERATOR*>(this)->operator *(), formatStatement)) == FAILED)
			DebugStop();
		static_cast<ITERATOR*>(this)->operator ++();
	}
	if (result.Append("}"_s) == FAILED)
		DebugStop();
	return result;
}

// include auto generated header file here
#include "string2.hxx"

//----------------------------------------------------------------------------------------
/// Class to store formatting statements.
//----------------------------------------------------------------------------------------
class FormatStatement
{
public:
	FormatStatement();
	FormatStatement(const FormatStatement& str);
	~FormatStatement();

	//----------------------------------------------------------------------------------------
	/// Returns the data stored under an identifier.
	/// @param[in] identifier					The name of the identifier.
	/// @return												The stored value that belongs to the identifier.
	//----------------------------------------------------------------------------------------
	const CString Get(const Char* identifier) const;

	//----------------------------------------------------------------------------------------
	/// Stores data under an identifier.
	/// @param[in] identifier					The name of the identifier.
	/// @param[in] str								The value to be stored.
	//----------------------------------------------------------------------------------------
	Result<void> Set(const Char* identifier, const CString& str);

	//----------------------------------------------------------------------------------------
	const FormatStatement& operator = (const FormatStatement& str);

private:
	void* _priv;
};

String ExtractString(StringProxy* proxy);
inline const String& ExtractString(const String& str) { return str; }
inline const Char* ExtractString(const Char* str) { return str; }

void ScanParameter(Float64& result, const Block<const Utf32Char>& str, Int& processed, const String& formatStatement, Bool& error);
void ScanParameter(Float32& result, const Block<const Utf32Char>& str, Int& processed, const String& formatStatement, Bool& error);
void ScanParameter(Int64& result, const Block<const Utf32Char>& str, Int& processed, const String& formatStatement, Bool& error);
void ScanParameter(Int32& result, const Block<const Utf32Char>& str, Int& processed, const String& formatStatement, Bool& error);
void ScanParameter(Int16& result, const Block<const Utf32Char>& str, Int& processed, const String& formatStatement, Bool& error);
void ScanParameter(Char& result, const Block<const Utf32Char>& str, Int& processed, const String& formatStatement, Bool& error);
void ScanParameter(UInt64& result, const Block<const Utf32Char>& str, Int& processed, const String& formatStatement, Bool& error);
void ScanParameter(UInt32& result, const Block<const Utf32Char>& str, Int& processed, const String& formatStatement, Bool& error);
void ScanParameter(UInt16& result, const Block<const Utf32Char>& str, Int& processed, const String& formatStatement, Bool& error);
void ScanParameter(UChar& result, const Block<const Utf32Char>& str, Int& processed, const String& formatStatement, Bool& error);
// version for any type of pointers
template <typename T> inline void ScanParameter(T*& result, const Block<const Utf32Char>& str, Int& processed, const String& formatStatement, Bool& error)
{
	ScanParameter((UInt&)result, str, processed, "x"_s, error);
}

template <typename T> inline void FromStrHlp(T* result, const Block<const Utf32Char>& str, Int& processed, const String& formatStatement, Bool& error)
{
	ScanParameter(*result, str, processed, formatStatement, error);
}
using FROMSTR = void (*)(void* p, const Block<const Utf32Char>& str, Int& processed, const String& formatStatement, Bool& error);
template <typename T> inline FROMSTR GetFromStrHlp()
{
	// Clang and GCC need the second cast
	return (FROMSTR) (void (*) (T*, const Block<const Utf32Char>& str, Int& processed, const String&, Bool& error)) &FromStrHlp<T>;
}

Bool ScanStringTemplate(const String& str, const String& format, Int* parsedCharacters, Int argsCnt, void** args, FROMSTR* argFuncs);

CString ExtractCString(StringProxy* proxy);

template <Bool ISOKAY, typename T> MAXON_ATTRIBUTE_FORCE_INLINE T ForwardString(T&& str)
{
	static_assert(ISOKAY, "Argument mismatch.");
	return std::forward<T>(str);
}

/// Format a string with additional parameters. The @ref outputsyntax is documented here.
/// The processed String is returned, e.g. String str = FormatString("@ cubes are @", 5, "green"_s);
#define FormatString(...)                                                                                                                  \
	maxon::ExtractString(                                                                                                                    \
		maxon::ForwardString<!std::is_same<std::remove_extent<std::remove_reference<decltype(MAXON_FIRSTARG(__VA_ARGS__))>::type>::type,       \
													 const maxon::Char>::value ||                                                                                    \
												 maxon::FormatTemplateHelper<MAXON_VA_NARGS(__VA_ARGS__) - 1,                                                      \
													 decltype(MAXON_FIRSTARG(__VA_ARGS__))>::FormatTemplateCheck(MAXON_FIRSTARG(__VA_ARGS__))>(                      \
			maxon::FormatTemplateX<MAXON_VA_NARGS(__VA_ARGS__) - 1>(__VA_ARGS__)))

/// Format a string with additional parameters. The @ref outputsyntax is documented here.
/// The processed CString is returned, e.g. CString str = FormatString("@ cubes are @", 5, "green"_s);
#define FormatCString(...)                                                                                                                 \
	maxon::ExtractCString(                                                                                                                   \
		maxon::ForwardString<!std::is_same<std::remove_extent<std::remove_reference<decltype(MAXON_FIRSTARG(__VA_ARGS__))>::type>::type,       \
													 const maxon::Char>::value ||                                                                                    \
												 maxon::FormatTemplateHelper<MAXON_VA_NARGS(__VA_ARGS__) - 1,                                                      \
													 decltype(MAXON_FIRSTARG(__VA_ARGS__))>::FormatTemplateCheck(MAXON_FIRSTARG(__VA_ARGS__))>(                      \
			maxon::FormatTemplateX<MAXON_VA_NARGS(__VA_ARGS__) - 1>(__VA_ARGS__)))

// this version doesn't work with llvm:
// #define FormatString(formatString, ...) maxon::ExtractString(maxon::FormatTemplateX<MAXON_VA_NARGS(__VA_ARGS__)>(formatString, ##__VA_ARGS__))






//----------------------------------------------------------------------------------------
/// Scans a string 'inputStr' for parameters and stores them according to parameter format 'formatStr' into the locations given by the additional arguments.
/// The basic syntax is the same as for DiagnosticOutput @ref outputsyntax. <br>
/// However only {x} and {c} are supported as formatting statements. It is not necessary to set {x} if you pass a pointer as parameter, only for regular Int/UInt's.<br>
/// Here an example:
/// @code
/// Float64 val1;
/// Int64 val2, val3;
/// void* val4;
/// Bool success = ScanString("@_7.345maef5.8=ab__", "@@_@m@{x}.@{c}=@", val1, val2, val3, val4);
/// @endcode
/// The operation succeeds with 7.345 for val1, 0xaef5 for val2, 56 for val3 and 0xab for val4.
///
/// @param[in] inputStr						The input string containing the data that will be extracted.
/// @param[in] formatStr					The string containing the parameter format.
/// @param[out] args							Values that will be extracted.
/// @return												True if successful. Errors can happen if the parameter count does not match the format string,
/// 															if the input string does not match the format string or the extracted data exceeds the limits of a datatype.
//----------------------------------------------------------------------------------------
template <typename STR, typename STR2, typename... ARGS>
inline Bool ScanString(STR inputStr, STR2 formatStr, ARGS&... args)
{
	void* argPtr[] = { (void*)&args..., nullptr };
	FROMSTR argFuncs[] = { GetFromStrHlp<ARGS>()..., nullptr };
	return ScanStringTemplate(String(inputStr), String(formatStr), nullptr, sizeof...(ARGS), argPtr, argFuncs);
}

//----------------------------------------------------------------------------------------
/// Scans a string 'inputStr' for parameters and stores them according to parameter format 'formatStr' into the locations given by the additional arguments.
/// The basic syntax is the same as for DiagnosticOutput @ref outputsyntax. <br>
/// However only {x} and {c} are supported as formatting statements. It is not necessary to set {x} if you pass a pointer as parameter, only for regular Int/UInt's.<br>
/// Here an example:
/// @code
/// Float64 val1;
/// Int64 val2, val3;
/// void* val4;
/// Int parsedCharacters;
/// Bool success = ScanString("@_7.345maef5.8=ab__", parsedCharacters, "@@_@m@{x}.@{c}=@", val1, val2, val3, val4);
/// @endcode
/// The operation succeeds with 7.345 for val1, 0xaef5 for val2, 56 for val3 and 0xab for val4.
///
/// @param[in] inputStr						The input string containing the data that will be extracted.
/// @param[out] parsedInputCharacters	The number of characters that were parsed to match formatStr.
/// @param[in] formatStr					The string containing the parameter format.
/// @param[out] args							Values that will be extracted.
/// @return												True if successful. Errors can happen if the parameter count does not match the format string,
/// 															if the input string does not match the format string or the extracted data exceeds the limits of a datatype.
//----------------------------------------------------------------------------------------
template <typename STR, typename STR2, typename... ARGS>
inline Bool ScanString(STR inputStr, Int& parsedInputCharacters, STR2 formatStr, ARGS&... args)
{
	void* argPtr[] = { (void*)&args..., nullptr };
	FROMSTR argFuncs[] = { GetFromStrHlp<ARGS>()..., nullptr };
	return ScanStringTemplate(String(inputStr), String(formatStr), &parsedInputCharacters, sizeof...(ARGS), argPtr, argFuncs);
}

String _LoadResourceString(const Id& scope, const InternedId& keyValue);

//----------------------------------------------------------------------------------------
/// Loads the string 'identifier' from the resource and format with the passed parameters.
//----------------------------------------------------------------------------------------
template <typename STRID, typename... ARGUMENTS> inline String LoadResourceString(const STRID& identifier, const ARGUMENTS&... args)
{
	return ExtractString(maxon::FormatTemplateX<sizeof...(args)>(maxon::_LoadResourceString(identifier.GetDatabaseScope(), identifier.Get()), args...));
}

//----------------------------------------------------------------------------------------
/// Calculates the length of a null-terminated string of type SysChar.
//----------------------------------------------------------------------------------------
static inline Int StrLen(const SysChar* chr)
{
	Int len = 0;
	while (*chr++)
		len++;
	return len;
}

//----------------------------------------------------------------------------------------
/// Calculates the length of a null-terminated string of type Utf32Char.
//----------------------------------------------------------------------------------------
static inline Int StrLen(const Utf32Char* chr)
{
	Int len = 0;
	while (*chr++)
		len++;
	return len;
}

//----------------------------------------------------------------------------------------
/// Calculates the length of a null-terminated string of type Utf16Char.
//----------------------------------------------------------------------------------------
static inline Int StrLen(const Utf16Char* chr)
{
	Int len = 0;
	while (*chr++)
		len++;
	return len;
}

//----------------------------------------------------------------------------------------
/// Checks if the passed character is a space
//----------------------------------------------------------------------------------------
template <typename TYPE> MAXON_ATTRIBUTE_FORCE_INLINE Bool IsSpace(TYPE chr)
{
	return chr == ' ';
}

//----------------------------------------------------------------------------------------
/// Checks if the passed character is a tab.
//----------------------------------------------------------------------------------------
template <typename TYPE> MAXON_ATTRIBUTE_FORCE_INLINE Bool IsTab(TYPE chr)
{
	return chr == '\t';
}

//----------------------------------------------------------------------------------------
/// Checks if the passed character is a space or tab.
//----------------------------------------------------------------------------------------
template <typename TYPE> MAXON_ATTRIBUTE_FORCE_INLINE Bool IsSpaceOrTab(TYPE chr)
{
	return chr == ' ' || chr == '\t';
}

//----------------------------------------------------------------------------------------
/// Checks if the passed character is a line end.
//----------------------------------------------------------------------------------------
template <typename TYPE> MAXON_ATTRIBUTE_FORCE_INLINE Bool IsLineEnd(TYPE chr)
{
	return chr == '\r' || chr == '\n';
}

//----------------------------------------------------------------------------------------
/// Checks if the passed character is a digit.
//----------------------------------------------------------------------------------------
template <typename TYPE> MAXON_ATTRIBUTE_FORCE_INLINE Bool IsNumeric(TYPE chr)
{
	return chr >= '0' && chr <= '9';
}

//----------------------------------------------------------------------------------------
/// Checks if the passed character is a latin character ('A' to 'Z' and 'a' to 'z').
//----------------------------------------------------------------------------------------
template <typename TYPE> MAXON_ATTRIBUTE_FORCE_INLINE Bool IsAlphabetic(TYPE chr)
{
	return (chr >= 'a' && chr <= 'z') || (chr >= 'A' && chr <= 'Z');
}

//----------------------------------------------------------------------------------------
/// Checks if the passed character is alphabetic or numeric.
//----------------------------------------------------------------------------------------
template <typename TYPE> MAXON_ATTRIBUTE_FORCE_INLINE Bool IsAlphanumeric(TYPE chr)
{
	return (chr >= 'a' && chr <= 'z') || (chr >= 'A' && chr <= 'Z') || (chr >= '0' && chr <= '9');
}

//----------------------------------------------------------------------------------------
/// Checks if the passed character is alphabetic or numeric.
//----------------------------------------------------------------------------------------
template <typename TYPE> MAXON_ATTRIBUTE_FORCE_INLINE Bool IsHexadecimal(TYPE chr)
{
	return (chr >= 'a' && chr <= 'f') || (chr >= 'A' && chr <= 'F') || (chr >= '0' && chr <= '9');
}

//----------------------------------------------------------------------------------------
/// Calculates the value from a hexadecimal character.
/// For a valid return value IsHexadecimal must fulfilled.
//----------------------------------------------------------------------------------------
template <typename TYPE> MAXON_ATTRIBUTE_FORCE_INLINE Int GetHexadecimalValue(TYPE chr)
{
	if (chr >= '0' && chr <= '9')
		return Int(chr - '0');
	else if (chr >= 'a' && chr <= 'f')
		return Int(chr - 'a') + 10;
	else if (chr >= 'A' && chr <= 'F')
		return Int(chr - 'A') + 10;

	DebugStop();
	return 0;
}

//----------------------------------------------------------------------------------------
/// Concatenates multiple elements to create a string.
/// Here an example:
/// @code
/// BaseArray<String> arr;
/// arr.Append("a"_s) iferr_return;
/// arr.Append("b"_s) iferr_return;
/// String res = JoinElements(arr, ", ");
/// @endcode
/// The result will be "a, b"
///
/// @param[in] iterable						The elements to concatenate, can be any iterable data type. The elements must have a valid implementation of ToString.
/// @param[in] delimiter					The delimiter that will be placed inbetween two elements. Must be a String or CString. It can be empty.
/// @param[in] formatStr					The string containing the parameter format.
/// @return												The return string.
//----------------------------------------------------------------------------------------
template <typename ITERATABLETYPE, typename REFTYPE> MAXON_WARN_UNUSED static REFTYPE JoinElements(ITERATABLETYPE&& iterable, const REFTYPE& delimiter, const FormatStatement* formatStr = nullptr)
{
	REFTYPE result;
	Bool first = true;
	for (const auto& c : std::forward<ITERATABLETYPE>(iterable))
	{
		if (first)
			first = false;
		else
			result += delimiter;

		result += (REFTYPE) GlobalToString(c, formatStr);
	}
	return result;
}

/// @}

} // namespace maxon

// All literals must be also accessible outside of the maxon namespace.
using maxon::operator "" _cs;

#endif // STRING_H__
