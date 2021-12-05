/////////////////////////////////////////////////////////////
// Cinema 4D SDK                                           //
/////////////////////////////////////////////////////////////
// (c) MAXON Computer GmbH, all rights reserved            //
/////////////////////////////////////////////////////////////

#ifndef C4D_STRING_H__
#define C4D_STRING_H__

#ifdef __API_INTERN__
	#include "ge_string.h"
#else
	#include <new>

#include "maxon/string.h"
#include "operatingsystem.h"

using maxon::operator "" _s;
using maxon::operator "" _cs;


namespace maxon
{
class FormatStatement;
}

maxon::String ToString(const String& val, const maxon::FormatStatement* formatStatement, maxon::Bool checkDatatype = false);

const maxon::String& MaxonConvert(const String& val);
String MaxonConvert(const maxon::String& val);

//-------------------------------------------------------------------------------------------------
/// A String is a variable-length sequence of UTF-32 encoded Unicode characters. String provides methods and operators to simplify using character sequences.
/// @note @C4D strings are fully using UTF-32 Unicode characters. To avoid problems with Unicodes try to always use Utf32Char in your code unless you need to interface with the system or existing libraries.
//-------------------------------------------------------------------------------------------------
class String : public maxon::String
{
	#define StCall(fnc) (this->*C4DOS.St->fnc)

public:
	using maxon::String::operator maxon::Bool;
	using maxon::String::ReferencedType;
	using maxon::String::Handler;
	using maxon::String::DirectlyReferencedType;
	using maxon::String::ResultFunctions;

	/// @name Constructors/Destructors
	/// @{

	//-------------------------------------------------------------------------------------------------
	/// Default constructor.
	//-------------------------------------------------------------------------------------------------
	String() { }

	//----------------------------------------------------------------------------------------
	/// Copy constructor.
	/// @param[in] cs									This String's characters are used to construct the String.
	//----------------------------------------------------------------------------------------
	String(const String& cs) = default;

	String(String&& str) = default;

	//----------------------------------------------------------------------------------------
	/// Copy constructor.
	/// @param[in] cs									This String's characters are used to construct the String.
	//----------------------------------------------------------------------------------------
	String(const maxon::String& cs) : maxon::String(cs) { }

	//----------------------------------------------------------------------------------------
	/// Move constructor.
	/// @param[in] str								This String's characters are used to construct the String.
	//----------------------------------------------------------------------------------------
	String(maxon::String&& str) : maxon::String(std::move(str)) { }

	//----------------------------------------------------------------------------------------
	/// Constructs a string with the UTF-16 encoded Unicode characters in @formatParam{s}.
	/// @since R17.032
	/// @param[in] s									The Unicode character array to initialize the string from. The pointed array is copied.
	/// @param[in] count							The number of Utf16Char characters. If @em -1 is passed all characters will be copied until @c '\0' is found.\n
	///																Note that the string may have a different length than what you specify here as the UTF-16 encoding is transformed into a UTF-32 encoding.
	//----------------------------------------------------------------------------------------
	explicit String(const Utf16Char* s, Int count = -1) : maxon::String(s, count) { }

	//----------------------------------------------------------------------------------------
	/// Constructs a string with the UTF-32 encoded Unicode characters in @formatParam{s}.
	/// @since R17.032
	/// @param[in] s									The Unicode character array to initialize the string from. The pointed array is copied.
	/// @param[in] count							The number of Utf32Char characters. If @em -1 is passed all characters will be copied until @c '\0' is found. Otherwise the resulting string length will match the given count.
	//----------------------------------------------------------------------------------------
	explicit String(const Utf32Char* s, Int count = -1) : maxon::String(s, count) { }

	//----------------------------------------------------------------------------------------
	/// Constructs a String with the characters in @formatParam{cstr}.
	/// @note If you have static strings use "..."_s instead. 
	/// @param[in] cstr								The character array in UTF8 encoding.
	/// @param[in] stringDecoding			Encoding type.
	//----------------------------------------------------------------------------------------
	String(const Char* cstr, const maxon::StringDecodingRef& stringDecoding = maxon::GetUtf8DefaultDecoder()) : maxon::String(cstr, stringDecoding)
	{
	}

	//----------------------------------------------------------------------------------------
	/// Constructs a String with the characters in @formatParam{cstr}.
	/// @markDeprecated Use the constructor with StringDecodingRef.
	/// @param[in] cstr								The character array to initialize the string with. The passed data is decoded using @formatParam{type} to UTF-32 internally.
	/// @param[in] type								The string encoding used to interpret @formatParam{cstr}.
	//----------------------------------------------------------------------------------------
	String(const Char* cstr, STRINGENCODING type)
	{
#if MAXON_TARGET_DEBUG
		if (type == STRINGENCODING::XBIT)
		{
			for (Int i = 0; cstr[i] != 0; i++)
			{
				if (UChar(cstr[i]) > 127)
				{
					DebugStop("Undefined encoding. Use maxon::StringDecodings::Utf8()");
					break;
				}
			}
		}
#endif
		C4DOS.St->InitCString(this, cstr, -1, type);
	}

	//----------------------------------------------------------------------------------------
	/// Constructs a string filled with the same character.
	/// @param[in] count							The number of characters.
	/// @param[in] fillch							The fill character.
	//----------------------------------------------------------------------------------------
	String(Int count, Utf32Char fillch) : maxon::String::String(count, fillch) { }

	/// @}

	/// @name Operators
	/// @{

	//----------------------------------------------------------------------------------------
	/// Assigns the characters from @formatParam{str}.
	/// @warning The assignment operators makes string copies.
	/// @param[in] str								The source string to assign.
	/// @return												The string that was set. Assigned to the left-hand operand.
	//----------------------------------------------------------------------------------------
	const String& operator =(const String& str)
	{
		maxon::String::operator = (str);
		return *this;
	}

	const String& operator =(String&& str)
	{
		maxon::String::operator = (std::move(str));
		return *this;
	}

	const String& operator =(const maxon::String& str)
	{
		maxon::String::operator = (str);
		return *this;
	}

	const String& operator =(maxon::String&& str)
	{
		maxon::String::operator = (std::move(str));
		return *this;
	}

#if 1
	//----------------------------------------------------------------------------------------
	/// Concatenates the strings and returns the resulting string.
	/// @param[in] str1								The left-hand operand string.
	/// @param[in] str2								The right-hand operand string.
	/// @return												The concatenated string.
	//----------------------------------------------------------------------------------------
	friend String operator +(const String& str1, const String& str2)
	{
		String s(str1);
		s += str2;
		return s;
	}
#endif

	friend String operator +(const String& str1, const Char* str2)
	{
		String s(str1);
		s += String(str2);
		return s;
	}

	friend String operator +(const Char* str1, const String& str2)
	{
		String s(str1);
		s += str2;
		return s;
	}

	//----------------------------------------------------------------------------------------
	/// Concatenates the strings and sets the left-hand operand to the result.
	/// @warning The assignment operators makes string copies.
	/// @param[in] str								The right-hand operand string.
	/// @return												The concatenated string. Assigned to the left-hand operand.
	//----------------------------------------------------------------------------------------
	const String& operator += (const String& str)
	{
		InsertDeprecated(GetLength(), str);
		return *this;
	}

	/// @}

	/// @name Comparison
	/// @{

	//----------------------------------------------------------------------------------------
	/// Compare the strings and returns their relationship.
	/// @markDeprecated This is equivalent to maxon::String::Compare(cs, maxon::STRINGCOMPARISON::MEMORY). 
	/// @note Comparison is case sensitive.
	/// @param[in] cs									The string to compare against.
	/// @return												@em 0 if the strings are identical, < @em 0 if the string is less than @formatParam{cs}, or > @em 0 if the string is greater than @formatParam{cs}.
	//----------------------------------------------------------------------------------------
	Int CompareDeprecated(const String& cs) const
	{
		return StCall(Compare) (cs);
	}

	//----------------------------------------------------------------------------------------
	/// Compares the String object with another string and returns their relationship.
	/// @markDeprecated This is equivalent to  maxon::String::Compare(cs, maxon::STRINGCOMPARISON::CASEINSENSITIVE).
	/// @param[in] cs									The string to compare against.
	/// @return												@em 0 if the strings are identical, < @em 0 if the string is less than @formatParam{cs}, or > @em 0 if the string is greater than @formatParam{cs}.
	//----------------------------------------------------------------------------------------
	Int LexCompare(const String& cs) const
	{
		return StCall(LexCompare) (cs);
	}

	//----------------------------------------------------------------------------------------
	/// Compares a part of the string, specified by the position @formatParam{pos} and the length @formatParam{cnt}, with @formatParam{str}.\n
	/// Equivalent to @link SubStr@endlink(@c pos, @c cnt).@link Compare@endlink(@c str).
	/// @markDeprecated This is equivalent to  maxon::String::ComparePart(str, maxon::STRINGCOMPARISON::MEMORY, pos, cnt).
	/// @param[in] str								The string to compare against.
	/// @param[in] cnt								The number of characters of the part.
	/// @param[in] pos								The position of the part.
	/// @return												@em 0 if the strings are identical, < @em 0 if the string is less than @formatParam{str}, or > @em 0 if the string is greater than @formatParam{str}.
	//----------------------------------------------------------------------------------------
	Int ComparePart(const String& str, Int cnt, Int pos) const
	{
		return StCall(ComparePart) (str, Int32(cnt), Int32(pos));
	}

	//----------------------------------------------------------------------------------------
	/// Compares a part of the string, specified by the position @formatParam{pos} and the length @formatParam{cnt}, with @formatParam{str} and returns their relationship.\n
	/// Equivalent to @link SubStr@endlink(@c pos, @c cnt).@link LexCompare@endlink(@c str).
	/// @markDeprecated This is equivalent to  maxon::String::ComparePart(str, maxon::STRINGCOMPARISON::CASEINSENSITIVE, pos, cnt).
	/// @param[in] str								The string to compare against.
	/// @param[in] cnt								The number of characters of the part.
	/// @param[in] pos								The position of the part.
	/// @return												@em 0 if the strings are identical, < @em 0 if the string is less than @formatParam{str}, or > @em 0 if the string is greater than @formatParam{str}.
	//----------------------------------------------------------------------------------------
	Int LexComparePart(const String& str, Int cnt, Int pos) const
	{
		return StCall(LexComparePart) (str, Int32(cnt), Int32(pos));
	}

	/// @}

	/// @name Find
	/// @{

	//----------------------------------------------------------------------------------------
	/// Searches the string for the first match of the substring.
	/// @markDeprecated This is equivalent to  maxon::String::Find(cs, pos, start).
	/// @param[in] cs									Substring to search for.
	/// @param[out] pos								A pointer to an ::Int32 to receive the found position in the string. @callerOwnsPointed{integer}
	/// @param[in] start							The starting position in the string for the search: @em 0 <= @formatParam{start} < GetLength().
	/// @return												@trueIfOtherwiseFalse{the substring was found}
	//----------------------------------------------------------------------------------------
	Bool FindFirst(const String& cs, Int32* pos, Int start = 0) const
	{
		return StCall(FindFirst) (cs, pos, Int32(start));
	}

	//----------------------------------------------------------------------------------------
	/// Searches the string for the last match of the substring.
	/// @markDeprecated This is equivalent to  maxon::String::FindLast(cs, pos, start == -1 ? maxon::StringEnd() : maxon::StringPosition(start + 1)).
	/// @param[in] cs									The substring to search for.
	/// @param[out] pos								A pointer to an ::Int32 to receive the found position in the string. @callerOwnsPointed{integer}
	/// @param[in] start							The position to start from when searching backwards: @em 0 <= @formatParam{start} < GetLength() or @em -1 for the end.
	/// @return												@trueIfOtherwiseFalse{the substring was found}
	//----------------------------------------------------------------------------------------
	Bool FindLast(const String& cs, Int32* pos, Int start = -1) const
	{
		return StCall(FindLast) (cs, pos, Int32(start));
	}

	//----------------------------------------------------------------------------------------
	/// Searches the string for the first match of character @formatParam{ch}.
	/// @markDeprecated This is equivalent to  maxon::String::FindFirst(ch, pos, start).
	/// @param[in] ch									The character to find.
	/// @param[out] pos								A pointer to an ::Int32 to receive the found position in the string. @callerOwnsPointed{integer}
	/// @param[in] start							The starting position in the string for the search: @em 0 <= @formatParam{start} < GetLength().
	/// @return												@trueIfOtherwiseFalse{the character was found}
	//----------------------------------------------------------------------------------------
	Bool FindFirst(Utf32Char ch, Int32* pos, Int start = 0) const
	{
		return StCall(FindFirstCh) (ch, pos, Int32(start));
	}

	//----------------------------------------------------------------------------------------
	/// Searches the string for the last match of character @formatParam{ch}.
	/// @markDeprecated This is equivalent to  maxon::String::FindLast(ch, pos, start == -1 ? maxon::StringEnd() : maxon::StringPosition(start + 1)).
	/// @param[in] ch									The character to find.
	/// @param[out] pos								A pointer to an ::Int32 to receive the found position in the string. @callerOwnsPointed{integer}
	/// @param[in] start							The position to start from when searching backwards: @em 0 <= @formatParam{start} < GetLength() or @em -1 for the end.
	/// @return												@trueIfOtherwiseFalse{the character was found}
	//----------------------------------------------------------------------------------------
	Bool FindLast(Utf32Char ch, Int32* pos, Int start = -1) const
	{
		return StCall(FindLastCh) (ch, pos, Int32(start));
	}

	//----------------------------------------------------------------------------------------
	/// Searches the string for the first match of the upper-case substring.
	/// @markDeprecated This is equivalent to  maxon::String::FindUpper(findupper, pos, start).
	/// @warning @formatParam{findupper} has to be uppercase.
	/// @param[in] findupper					The upper-case substring to search for.
	/// @param[out] pos								A pointer to an ::Int32 to receive the found position in the string. @callerOwnsPointed{integer}
	/// @param[in] start							The starting position in the string for the search: @em 0 <= @formatParam{start} < GetLength().
	/// @return												@trueIfOtherwiseFalse{the upper-case substring was found}
	//----------------------------------------------------------------------------------------
	Bool FindFirstUpper(const String& findupper, Int32* pos, Int start) const
	{
		return StCall(FindFirstUpper) (findupper, pos, Int32(start));
	}

	//----------------------------------------------------------------------------------------
	/// Searches the string for the last match of the upper-case substring.
	/// @markDeprecated This is equivalent to  maxon::String::FindLastUpper(findupper, pos, start == -1 ? maxon::StringEnd() : maxon::StringPosition(start + 1))
	/// @warning @formatParam{findupper} has to be uppercase.
	/// @param[in] findupper					The upper-case substring to search for.
	/// @param[out] pos								A pointer to an ::Int32 to receive the found position in the string. @callerOwnsPointed{integer}
	/// @param[in] start							The position to start from when searching backwards: @em 0 <= @formatParam{start} < GetLength() or @em -1 for the end.
	/// @return												@trueIfOtherwiseFalse{the upper-case substring was found}
	//----------------------------------------------------------------------------------------
	Bool FindLastUpper(const String& findupper, Int32* pos, Int start) const
	{
		return StCall(FindLastUpper) (findupper, pos, Int32(start));
	}

	/// @}

	/// @name Delete/Insert/SubStr
	/// @{

	//----------------------------------------------------------------------------------------
	/// Removes a section from the string.
	/// @markDeprecated This is equivalent to  maxon::String::Erase(pos, count).
	/// @param[in] pos								The starting position to remove: @em 0 <= @formatParam{pos} < GetLength().
	/// @param[in] count							The number of characters to remove: @em 0 <= @formatParam{count} < GetLength()-@formatParam{pos}.
	//----------------------------------------------------------------------------------------
	void Delete(Int pos, Int count)
	{
		StCall(Delete) (pos, count);
	}

	//----------------------------------------------------------------------------------------
	/// Inserts a character into the string.
	/// @markDeprecated This is equivalent to  maxon::String::Insert(pos, ch).
	/// @param[in] pos								The position to insert the character: @em 0 <= @formatParam{pos} < GetLength().
	/// @param[in] ch									The character to insert.
	//----------------------------------------------------------------------------------------
	void InsertDeprecated(Int pos, Utf32Char ch)
	{
		String tmp = String(1, ch);
		StCall(Insert)(Int32(pos), tmp, -1, -1);
	}

	//----------------------------------------------------------------------------------------
	/// Inserts another string into the string.
	/// @markDeprecated This is equivalent to  maxon::String::Insert(pos, cs, start == -1 ? 0 : start, end == -1 ? maxon::StringEnd() : maxon::StringPosition(end)).
	/// @param[in] pos								The position to insert the string: @em 0 <= @formatParam{pos} < GetLength().
	/// @param[in] cs									The string to insert.
	/// @param[in] start							The start position within the inserted string to only insert parts of the string.
	/// @param[in] end								End position within the inserted string to only insert parts of the string.
	//----------------------------------------------------------------------------------------
	void InsertDeprecated(Int pos, const String& cs, Int start = -1, Int end = -1)
	{
		StCall(Insert) (Int32(pos), cs, Int32(start), Int32(end));
	}

	//----------------------------------------------------------------------------------------
	/// Extracts a substring from the string.
	/// @markDeprecated This is equivalent to maxon::String::GetPart(a, b).
	/// @param[in] start							The position to extract the substring from. Must be @em 0 <= @formatParam{pos} < GetLength().
	/// @param[in] count							The number of characters of the substring: @em 0 <= @formatParam{count} < GetLength()-@formatParam{start}
	/// @return												The substring.
	//----------------------------------------------------------------------------------------
	String SubStr(Int start, Int count) const
	{
		return StCall(SubStr)(start, count);
	}

	//----------------------------------------------------------------------------------------
	/// Extracts a substring from the left of the string.
	/// @markDeprecated This is equivalent to maxon::String::GetPart(-count, maxon::StringEnd()).
	/// @param[in] count							The number of characters of the substring: @em 0 <= @formatParam{count} < GetLength()
	/// @return												The substring.
	//----------------------------------------------------------------------------------------
	String Left(Int count) const
	{
		return SubStr(0, count);
	}

	//----------------------------------------------------------------------------------------
	/// Extracts a substring from the right of the string.
	/// @markDeprecated This is equivalent to maxon::String::GetPart(-count, maxon::StringEnd()).
	/// @param[in] count							The number of characters of the substring: @em 0 <= @formatParam{count} < GetLength()
	/// @return												The substring.
	//----------------------------------------------------------------------------------------
	String Right(Int count) const
	{
		return SubStr(GetLength() - count, count);
	}

	/// @}

	/// @name Parse to Number
	/// @{

	//----------------------------------------------------------------------------------------
	/// Converts the string into a ::Float value.
	/// @param[in] error							A pointer to an ::Int32 to report any errors of conversion. @callerOwnsPointed{variable}\n
	///																The function succeeded if @formatParam{error}==@formatConstant{0}.
	/// @param[in] unit								The unit type: @enumerateEnum{UNIT}
	/// @param[in] angletype					The angle type: @enumerateEnum{ANGLE}
	/// @param[in] base								The base of the number system used in the string.
	/// @return												The ::Float value represented by the string.
	//----------------------------------------------------------------------------------------
	Float ParseToFloat(Int32* error = nullptr, Int unit = 0, Int angletype = 0, Int base = 10) const
	{
		return StCall(ParseToFloat) (error, Int32(unit), Int32(angletype), Int32(base));
	}

	//----------------------------------------------------------------------------------------
	/// Converts the string into an ::Int32 value.
	/// @markDeprecated This is equivalent to maxon::String::ToInt32().
	/// @param[in] error							A pointer to an ::Int32 to report any errors of conversion. @callerOwnsPointed{variable}\n
	///																The function succeeded if @formatParam{error}==@formatConstant{0}.
	/// @return												The ::Int32 value represented by the string.
	//----------------------------------------------------------------------------------------
	Int32 ParseToInt32(Int32* error = nullptr) const
	{
		return StCall(ParseToInt32) (error);
	}

	/// @}

	/// @name Conversion from Number
	/// @{

	//----------------------------------------------------------------------------------------
	/// Converts a ::Int64 into a memory size formated (B,KB,MB) string.
	/// @markDeprecated This is equivalent to maxon::String::MemorySizeToString(v, true).
	/// @param[in] mem								The ::Int64 memory value to convert.
	/// @return												The ::Int64 memory as a string.
	//----------------------------------------------------------------------------------------
	static String MemoryToString(Int64 mem) { return C4DOS.St->MemoryToString(mem); }

	//----------------------------------------------------------------------------------------
	/// Converts a ::UInt32 hexadecimal value into a string (usually used with pointers).
	/// @markDeprecated This is equivalent to maxon::String::HexToString(v, prefix0x).
	/// @param[in] v									The hexadecimal value to convert.
	/// @param[in] prefix0x						Set to @formatConstant{false} to disable @em '0x' prefix in the returned string.
	/// @return												The hexadecimal value as a string.
	//----------------------------------------------------------------------------------------
	static String HexToString(UInt32 v, Bool prefix0x = true)  { return MaxonConvert(maxon::String::HexToString(v, prefix0x)); }

	//----------------------------------------------------------------------------------------
	/// Converts a ::UInt64 hexadecimal value into a string (usually used with pointers).
	/// @markDeprecated This is equivalent to maxon::String::HexToString(v, prefix0x).
	/// @param[in] v									The hexadecimal value to convert.
	/// @param[in] prefix0x						Set to @formatConstant{false} to disable @em '0x' prefix in the returned string.
	/// @return												The hexadecimal value as a string.
	//----------------------------------------------------------------------------------------
	static String HexToString(UInt64 v, Bool prefix0x = true) { return MaxonConvert(maxon::String::HexToString(v, prefix0x)); }

	//----------------------------------------------------------------------------------------
	/// Converts an ::Int32 to a String.
	/// @markDeprecated This is equivalent to maxon::String::IntToString(v).
	/// @param[in] v									::Int32 value.
	/// @return												String object with the decimal text of the value. Will be an empty reference on failure (apply iferr for error handling).
	//----------------------------------------------------------------------------------------
	static String IntToString(Int32 v) { return MaxonConvert(maxon::String::IntToString(v)); }

	//----------------------------------------------------------------------------------------
	/// Converts an ::Int64 to a String.
	/// @markDeprecated This is equivalent to maxon::String::IntToString(v).
	/// @param[in] v									::Int64 value.
	/// @return												String object with the decimal text of the value. Will be an empty reference on failure (apply iferr for error handling).
	//----------------------------------------------------------------------------------------
	static String IntToString(Int64 v) { return MaxonConvert(maxon::String::IntToString(v)); }

	//----------------------------------------------------------------------------------------
	/// Converts an ::UInt32 to a String.
	/// @markDeprecated This is equivalent to maxon::String::UIntToString(v).
	/// @param[in] v									::UInt32 value.
	/// @return												String object with the decimal text of the value. Will be an empty reference on failure (apply iferr for error handling).
	//----------------------------------------------------------------------------------------
	static String UIntToString(UInt32 v) { return MaxonConvert(maxon::String::UIntToString(v)); }

	//----------------------------------------------------------------------------------------
	/// Converts an ::UInt64 to a String.
	/// @markDeprecated This is equivalent to maxon::String::UIntToString(v).
	/// @param[in] v									::UInt64 value.
	/// @return												String object with the decimal text of the value. Will be an empty reference on failure (apply iferr for error handling).
	//----------------------------------------------------------------------------------------
	static String UIntToString(UInt64 v) { return MaxonConvert(maxon::String::UIntToString(v)); }

	//----------------------------------------------------------------------------------------
	/// Converts a ::Float32 into a String.
	/// @markDeprecated This is equivalent to maxon::String::FloatToString(v, ...).
	/// @param[in] v									The ::Float32 value to convert.
	/// @param[in] vvk								The number of digits in front of the comma.
	/// @param[in] nnk								The number of digits after the comma.
	/// @return												The ::Float32 as a string.
	//----------------------------------------------------------------------------------------
	static String FloatToString(Float32 v, Int32 vvk = -1, Int32 nnk = -3) { return MaxonConvert(maxon::String::FloatToString(v, vvk, nnk)); }

	//----------------------------------------------------------------------------------------
	/// Converts a ::Float64 into a String.
	/// @markDeprecated This is equivalent to maxon::String::FloatToString(v, ...).
	/// @param[in] v									The ::Float64 value to convert.
	/// @param[in] vvk								The number of digits in front of the comma.
	/// @param[in] nnk								The number of digits after the comma.
	/// @return												The ::Float64 as a string.
	//----------------------------------------------------------------------------------------
	static String FloatToString(Float64 v, Int32 vvk = -1, Int32 nnk = -3) { return MaxonConvert(maxon::String::FloatToString(v, vvk, nnk)); }

	//----------------------------------------------------------------------------------------
	/// Converts a ::Float32 into a String.
	/// @markDeprecated This is equivalent to maxon::String::FloatToString(v, ...).
	/// @param[in] v									The ::Float32 value to convert.
	/// @param[in] vvk								The number of digits in front of the comma. (-1)
	/// @param[in] nnk								The number of digits after the comma.
	/// @param[in] e									Set to @formatConstant{true} to use exponential writing.
	/// @param[in] xchar							The leading chars will be filled with this character. e.g. the value @em 100 with @formatParam{vvk}==@em 5 will looks like this: @em 00100.
	/// @return												The ::Float32 as a string.
	//----------------------------------------------------------------------------------------
	static String FloatToStringDeprecated(Float32 v, Int32 vvk, Int32 nnk = -1, Bool e = false, Utf32Char xchar = '0') { return C4DOS.St->FloatToString32(v, vvk, nnk, e, xchar); }

	//----------------------------------------------------------------------------------------
	/// Converts a ::Float64 into a String.
	/// @markDeprecated This is equivalent to maxon::String::FloatToString(v, ...).
	/// @param[in] v									The ::Float64 value to convert.
	/// @param[in] vvk								The number of digits in front of the comma (-1).
	/// @param[in] nnk								The number of digits after the comma.
	/// @param[in] e									Set to @formatConstant{true} to use exponential writing.
	/// @param[in] xchar							The leading chars will be filled with this character. e.g. the value @em 100 with @formatParam{vvk}==@em 5 will looks like this: @em 00100.
	/// @return												The ::Float64 as a string.
	//----------------------------------------------------------------------------------------
	static String FloatToStringDeprecated(Float64 v, Int32 vvk, Int32 nnk = -1, Bool e = false, Utf32Char xchar = '0') { return C4DOS.St->FloatToString64(v, vvk, nnk, e, xchar); }

	//----------------------------------------------------------------------------------------
	/// Converts a ::Vector32 into a String.
	/// @param[in] v									The ::Vector32 value to convert.
	/// @param[in] nnk								The number of digits after the comma.
	/// @return												The ::Vector32 as a string.
	//----------------------------------------------------------------------------------------
	static String VectorToString(const Vector32& v, Int32 nnk = -1)
	{
		return MaxonConvert("("_s + maxon::String::FloatToString((Float32)v.x, -1, nnk) + ";"_s + maxon::String::FloatToString((Float32)v.y, -1, nnk) + ";"_s + maxon::String::FloatToString((Float32)v.z, -1, nnk) + ")"_s);
	}

	//----------------------------------------------------------------------------------------
	/// Converts a ::Vector64 into a String.
	/// @param[in] v									The ::Vector64 value to convert.
	/// @param[in] nnk								The number of digits after the comma.
	/// @return												The ::Vector64 as a string.
	//----------------------------------------------------------------------------------------
	static String VectorToString(const Vector64& v, Int32 nnk = -1)
	{
		return MaxonConvert("("_s + maxon::String::FloatToString((Float64)v.x, -1, nnk) + ";"_s + maxon::String::FloatToString((Float64)v.y, -1, nnk) + ";"_s + maxon::String::FloatToString((Float64)v.z, -1, nnk) + ")"_s);
	}

	/// @}

	/// @name Conversion to Number
	/// @{

	//----------------------------------------------------------------------------------------
	/// Converts the string to an ::Int32.
	/// @markDeprecated This is equivalent to maxon::String::ToInt32().
	/// @param[out] error							Assigned @formatConstant{true} if an error occurred, otherwise @formatConstant{false}.
	/// @return												The string as an ::Int32.
	//----------------------------------------------------------------------------------------
	Int32 ToInt32(Bool* error) const { return StCall(ToInt32) (error); }

	//----------------------------------------------------------------------------------------
	/// Converts the string to an ::Int64.
	/// @markDeprecated This is equivalent to maxon::String::ToInt64().
	/// @param[out] error							Assigned @formatConstant{true} if an error occurred, otherwise @formatConstant{false}.
	/// @return												The string as an ::Int64.
	//----------------------------------------------------------------------------------------
	Int64 ToInt64(Bool* error) const { return StCall(ToInt64) (error); }

	//----------------------------------------------------------------------------------------
	/// Converts the string to a ::UInt32.
	/// @markDeprecated This is equivalent to maxon::String::ToUInt32().
	/// @param[out] error							Assigned @formatConstant{true} if an error occurred, otherwise @formatConstant{false}.
	/// @return												The string as a ::UInt32.
	//----------------------------------------------------------------------------------------
	UInt32 ToUInt32(Bool* error) const { return StCall(ToUInt32) (error); }

	//----------------------------------------------------------------------------------------
	/// Converts the string to a ::UInt64.
	/// @markDeprecated This is equivalent to maxon::String::ToUInt64().
	/// @param[out] error							Assigned @formatConstant{true} if an error occurred, otherwise @formatConstant{false}.
	/// @return												The string as a ::UInt64.
	//----------------------------------------------------------------------------------------
	UInt64 ToUInt64(Bool* error) const { return StCall(ToUInt64) (error); }

	//----------------------------------------------------------------------------------------
	/// Converts the string to a ::Float.
	/// @markDeprecated This is equivalent to maxon::String::ToFloat().
	/// @param[out] error							Assigned @formatConstant{true} if an error occurred, otherwise @formatConstant{false}.
	/// @return												The string as a ::Float.
	//----------------------------------------------------------------------------------------
	Float ToFloat(Bool* error) const { return StCall(ToFloat) (error); }

	//----------------------------------------------------------------------------------------
	/// Converts the string to an ::Int.
	/// @markDeprecated This is equivalent to maxon::String::ToInt().
	/// @param[out] error							Assigned @formatConstant{true} if an error occurred, otherwise @formatConstant{false}.
	/// @return												The string as an ::Int.
	//----------------------------------------------------------------------------------------
	Int ToInt(Bool* error) const
	{
		return ToInt64(error);
	}

	//----------------------------------------------------------------------------------------
	/// Converts the string to a ::UInt.
	/// @markDeprecated This is equivalent to maxon::String::ToUInt().
	/// @param[out] error							Assigned @formatConstant{true} if an error occurred, otherwise @formatConstant{false}.
	/// @return												The string as a ::UInt.
	//----------------------------------------------------------------------------------------
	UInt ToUInt(Bool* error) const
	{
		return ToUInt64(error);
	}

	/// @}

	/// @name Conversion to Upper/Lower Case
	/// @{

	//----------------------------------------------------------------------------------------
	/// Converts the characters of the string to uppercase.
	/// @markDeprecated This is equivalent to maxon::String::ToUpper().
	/// @warning This only works with ANSI characters less than character code @em 128, all other characters remain unchanged.
	/// @return												The converted uppercase string. Returns a copy of the string.
	//----------------------------------------------------------------------------------------
	String ToUpper() const
	{
		return StCall(ToUpper) ();
	}

	//----------------------------------------------------------------------------------------
	/// Converts the characters of the string to lowercase.
	/// @markDeprecated This is equivalent to maxon::String::ToLower().
	/// @warning This only works with ANSI characters less than character code @em 128, all other characters remain unchanged.
	/// @return												The converted lowercase string. Returns a copy of the string.
	//----------------------------------------------------------------------------------------
	String ToLower() const
	{
		return StCall(ToLower) ();
	}

	/// @}

	/// @name C and Unicode String Conversion
	/// @{

	//----------------------------------------------------------------------------------------
	/// Gets the expected length of the string after encoding.
	/// @markDeprecated Use maxon::String::GetCString/GetCStringAppendArray()
	/// @param[in] type								The type of string encoding.
	/// @return												The length of the encoded string.
	//----------------------------------------------------------------------------------------
	Int32 GetCStringLen(STRINGENCODING type = STRINGENCODING::XBIT) const
	{
		return StCall(GetCStringLen) (type);
	}

	//----------------------------------------------------------------------------------------
	/// Gets the string after encoding. This routine can be used to convert @C4D Unicode strings into standard @em C strings.
	/// @markDeprecated Use maxon::String::GetCStringBlock()
	/// @param[out] scstr							The buffer for the encoded string. The size of the buffer must be at least @formatParam{max}. @callerOwnsPointed{buffer}. It is guaranteed that the character sequence will be '\0'-terminated.
	/// @param[in] max								The maximum number of characters for the buffer @formatParam{scstr}. Should be GetCStringLen() + @em 1, otherwise the string will be truncated.
	/// @param[in] type								The type of string encoding.
	/// @return												The length of the encoded string.
	//----------------------------------------------------------------------------------------
	Int32 GetCString(Char* scstr, Int max, STRINGENCODING type = STRINGENCODING::XBIT) const
	{
		Int32 cnt = StCall(GetCString) (scstr, Int32(max), type);
#if MAXON_TARGET_DEBUG
		if (type == STRINGENCODING::XBIT && scstr)
		{
			for (Int32 i = 0; i < cnt; i++)
			{
				if (UChar(scstr[i]) > 127)
				{
					DebugStop("Undefined encoding. Use maxon::StringDecodings::Utf8()");
					break;
				}
			}
		}
#endif
		return cnt;
	}

	//----------------------------------------------------------------------------------------
	/// Gets the encoded string as a copy. This routine can be used to convert @C4D Unicode strings into standard @em C strings. Other than GetCString() no length precalculation needs to be done.
	/// @markDeprecated Use maxon::String::GetCString()
	/// @param[in] type								The type of string encoding.
	/// @return												The @em C string copy of the string. @callerOwnsPointed{string}\n
	/// @warning											The returned character buffer has to be freed after usage with @c DeleteMem().
	//----------------------------------------------------------------------------------------
	Char* GetCStringCopy(STRINGENCODING type = STRINGENCODING::XBIT) const;

	//----------------------------------------------------------------------------------------
	/// Sets a string. This routine will convert a standard @em C string using the given decoding into a @C4D UTF-32 Unicode string.
	/// @markDeprecated Use maxon::String::SetCString()
	/// @param[in] cstr								The buffer containing the encoded string. @callerOwnsPointed{buffer}
	/// @param[in] count							The number of characters in the encoded string. If @em -1 is passed all characters will be copied until @c '\0' is found.\n
	///																Note that the resulting string may have a different length than what you specify here it is transformed into a UTF-32 encoding.
	/// @param[in] type								The type of string encoding.
	//----------------------------------------------------------------------------------------
	void SetCString(const Char* cstr, Int count = -1, STRINGENCODING type = STRINGENCODING::XBIT)
	{
#if MAXON_TARGET_DEBUG
		if (type == STRINGENCODING::XBIT)
		{
			for (Int i = 0; count >= 0 ? i < count : cstr[i] != 0; i++)
			{
				if (UChar(cstr[i]) > 127)
				{
					DebugStop("Undefined encoding. Use maxon::StringDecodings::Utf8()");
					break;
				}
			}
		}
#endif
		
		C4DOS.St->InitCString(this, cstr, Int32(count), type);
	}

	/// @}
};

//----------------------------------------------------------------------------------------
/// Checks if the strings are equal.
/// @markDeprecated Use maxon::String::Compare(...).
/// @note The comparison is done alphanumerically and case-sensitive.
/// @param[in] left								The left-hand operand string.
/// @param[in] right							The right-hand operand string.
/// @return												@trueIfOtherwiseFalse{the strings are equal}
//----------------------------------------------------------------------------------------
static inline Bool operator ==(const String& left, const Char* right) 
{
	return left.CompareDeprecated(String(right)) == 0;
}

//----------------------------------------------------------------------------------------
/// Checks if the strings are equal.
/// @markDeprecated Use maxon::String::Compare(...).
/// @note The comparison is done alphanumerically and case-sensitive.
/// @param[in] left								The left-hand operand string.
/// @param[in] right							The right-hand operand string.
/// @return												@trueIfOtherwiseFalse{the strings are equal}
//----------------------------------------------------------------------------------------
static inline Bool operator ==(const String& left, const String& right) 
{
	return left.CompareDeprecated(right) == 0;
}

//----------------------------------------------------------------------------------------
/// Checks if two strings are different.
/// @markDeprecated Use maxon::String::Compare(...).
/// @note The comparison is done alphanumerically and case-sensitive.
/// @param[in] left								The left-hand operand string.
/// @param[in] right							The right-hand operand string.
/// @return												@trueIfOtherwiseFalse{the two strings are different}
//----------------------------------------------------------------------------------------
static inline Bool operator !=(const String& left, const String& right)
{
	return left.CompareDeprecated(right) != 0;
}

//----------------------------------------------------------------------------------------
/// Checks if two strings are different.
/// @markDeprecated Use maxon::String::Compare(...).
/// @note The comparison is done alphanumerically and case-sensitive.
/// @param[in] left								The left-hand operand string.
/// @param[in] right							The right-hand operand string.
/// @return												@trueIfOtherwiseFalse{the two strings are different}
//----------------------------------------------------------------------------------------
static inline Bool operator !=(const String& left, const Char* right)
{
	return left.CompareDeprecated(String(right)) != 0;
}

//----------------------------------------------------------------------------------------
/// Compares the strings to see if the the left-hand string is less than the right-hand string.
/// @markDeprecated Use maxon::String::Compare(...).
/// @note The comparison is done alphanumerically and case-sensitive.
/// @param[in] left								The left-hand operand string.
/// @param[in] right							The right-hand operand string.
/// @return												The result of the comparison.
//----------------------------------------------------------------------------------------
static inline Bool operator <(const String& left, const String& right) 
{
	return left.CompareDeprecated(right) < 0;
}

#if (defined MAXON_TARGET_DEBUG) && (defined MAXON_TARGET_WINDOWS)
	Char* cstr(String& str);
	Char* cstr(const String& str);
#endif

#endif

#endif // C4D_STRING_H__
