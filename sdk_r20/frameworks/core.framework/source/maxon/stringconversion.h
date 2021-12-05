#ifndef STRINGCONVERSION_H__
#define STRINGCONVERSION_H__

#include "maxon/string.h"

namespace maxon
{

//----------------------------------------------------------------------------------------
/// Class that controls string to value conversion.
/// There is no need to use this class directly, use String instead.
//----------------------------------------------------------------------------------------
class StringConversion
{
	MAXON_INTERFACE_NONVIRTUAL(StringConversion, MAXON_REFERENCE_NONE, "net.maxon.interface.stringconversion");

public:
	//----------------------------------------------------------------------------------------
	/// Converts a floating point value into formatted text.
	/// @param[in] value							Floating point value to convert into text.
	/// @param[in] charsBeforeComma		Characters before the decimal point. If -1 is passed or 'charsBeforeComma' is too low to represent 'value' it is automatically increased/adjusted. If 'charsBeforeComma' is positive and exponent is false fill characters will be added to the beginning.
	/// @param[in] digitsAfterComma		Digits after the decimal point. If a negative number is passed the number of digits is automatically chosen and up to (-digitsAfterComma).
	/// @param[in] exponent						Force exponential-style output (e.g. 1.0e+10).
	/// @param[in] fillChar						Fill character for digits before the decimal point. E.g. if you specify 4 for charsBeforeComma, '*' for fillChar and your value is 1.5 you'll get ***1.5 as a result. This value has no impact if exponent is true.
	/// @param[in] formatStatement		Nullptr or additional formatting instruction. See also @ref format_float.
	/// @return												String object with the decimal text of the value.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD String FloatToString(Float32 value, Int charsBeforeComma, Int digitsAfterComma, Bool exponent, Utf32Char fillChar, const FormatStatement* formatStatement);

	//----------------------------------------------------------------------------------------
	/// Converts a floating point value into formatted text.
	/// @param[in] value							Floating point value to convert into text.
	/// @param[in] charsBeforeComma		Characters before the decimal point. If -1 is passed or 'charsBeforeComma' is too low to represent 'value' it is automatically increased/adjusted. If 'charsBeforeComma' is positive and exponent is false fill characters will be added to the beginning.
	/// @param[in] digitsAfterComma		Digits after the decimal point. If a negative number is passed the number of digits is automatically chosen and up to (-digitsAfterComma).
	/// @param[in] exponent						Force exponential-style output (e.g. 1.0e+10).
	/// @param[in] fillChar						Fill character for digits before the decimal point. E.g. if you specify 4 for charsBeforeComma, '*' for fillChar and your value is 1.5 you'll get ***1.5 as a result. This value has no impact if exponent is true.
	/// @param[in] formatStatement		Nullptr or additional formatting instruction. See also @ref format_float.
	/// @return												String object with the decimal text of the value.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD String FloatToString(Float64 value, Int charsBeforeComma, Int digitsAfterComma, Bool exponent, Utf32Char fillChar, const FormatStatement* formatStatement);

	//----------------------------------------------------------------------------------------
	/// Appends an integer value to an existing string.
	/// @param[in] str								The existing string.
	/// @param[in] value							The value that will be appended as a string.
	/// @param[in] datatypeSize				Size in bytes of the passed value, as this routine can be used for Char, Int16, Int32 and Int64 values. This becomes only relevant if formatStatement forces hexadecimal output.
	/// @param[in] formatStatement		Nullptr or additional formatting instruction. See also @ref format_integer.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD void AppendInt(StringInterface* str, Int64 value, Int datatypeSize, const FormatStatement* formatStatement);

	//----------------------------------------------------------------------------------------
	/// Appends an unsigned integer value to an existing string.
	/// @param[in] str								The existing string.
	/// @param[in] value							The value that will be appended as a string.
	/// @param[in] datatypeSize				Size in bytes of the passed value, as this routine can be used for UChar, UInt16, UInt32 and UInt64 values. This becomes only relevant if formatStatement forces hexadecimal output.
	/// @param[in] formatStatement		Nullptr or additional formatting instruction. See also @ref format_integer.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD void AppendUInt(StringInterface* str, UInt64 value, Int datatypeSize, const FormatStatement* formatStatement);

	//----------------------------------------------------------------------------------------
	/// Appends an integer value to an existing string.
	/// @param[in] str								The existing string.
	/// @param[in] value							The value that will be appended as a string.
	/// @param[in] datatypeSize				Size in bytes of the passed value, as this routine can be used for Char, Int16, Int32 and Int64 values. This becomes only relevant if formatStatement forces hexadecimal output.
	/// @param[in] formatStatement		Nullptr or additional formatting instruction. See also @ref format_integer.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD void AppendInt(CStringInterface* str, Int64 value, Int datatypeSize, const FormatStatement* formatStatement);

	//----------------------------------------------------------------------------------------
	/// Appends an unsigned integer value to an existing string.
	/// @param[in] str								The existing string.
	/// @param[in] value							The value that will be appended as a string.
	/// @param[in] datatypeSize				Size in bytes of the passed value, as this routine can be used for UChar, UInt16, UInt32 and UInt64 values. This becomes only relevant if formatStatement forces hexadecimal output.
	/// @param[in] formatStatement		Nullptr or additional formatting instruction. See also @ref format_integer.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD void AppendUInt(CStringInterface* str, UInt64 value, Int datatypeSize, const FormatStatement* formatStatement);

	//----------------------------------------------------------------------------------------
	/// Creates a readable string from a memory size.
	/// @param[in] mem								The memory size.
	/// @param[in] mebibytes					defines if a value of 1343443 is either output as "1.28 MiB" (mebibytes) or "1.34 MB" (megabytes).
	/// @return												String that displays the memory size.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD String MemorySizeToString(Int64 mem, Bool mebibytes);

	//----------------------------------------------------------------------------------------
	/// Converts a value into a hexadecimal string.
	/// @param[in] value							The value.
	/// @param[in] prefix0x						If true, the output string will have a '0x' prefix.
	/// @param[in] leadingZeros				If false, the output string will have no leading zeros, so a value of 100 e.g. will be output as 64 (and not 00000064).
	/// @param[in] formatStatement		Nullptr or additional formatting instruction. See also @ref format_pointer.
	/// @return												The converted string.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD String HexToString(UInt32 value, Bool prefix0x, Bool leadingZeros, const FormatStatement* formatStatement);

	//----------------------------------------------------------------------------------------
	/// Converts a value into a hexadecimal string.
	/// @param[in] value							The value.
	/// @param[in] prefix0x						If true, the output string will have a '0x' prefix.
	/// @param[in] leadingZeros				If false, the output string will have no leading zeros, so a value of 100 e.g. will be output as 64 (and not 0000000000000064).
	/// @param[in] formatStatement		Nullptr or additional formatting instruction. See also @ref format_pointer.
	/// @return												The converted string.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD String HexToString(UInt64 value, Bool prefix0x, Bool leadingZeros, const FormatStatement* formatStatement);

	//----------------------------------------------------------------------------------------
	/// Converts a Utf32Char character sequence to a 32-bit floating point value.
	/// This routine does no formula parsing.
	/// While leading whitespaces are allowed by default no trailing characters of any kind are allowed.
	/// @param[in] str								The input string.
	/// @param[in] flags							Optional flags for the conversion.
	/// @return												Floating point value of string.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<Float32> ToFloat32(const Block<const Utf32Char>& str, STRINGCONVERSION flags);

	//----------------------------------------------------------------------------------------
	/// Converts a Utf32Char character sequence to a 64-bit floating point value.
	/// This routine does no formula parsing.
	/// While leading whitespaces are allowed by default no trailing characters of any kind are allowed.
	/// @param[in] str								The input string.
	/// @param[in] flags							Optional flags for the conversion.
	/// @return												Floating point value of string.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<Float64> ToFloat64(const Block<const Utf32Char>& str, STRINGCONVERSION flags);

	//----------------------------------------------------------------------------------------
	/// Converts a Utf32Char character sequence to a 64 bit integer value.
	/// This routine does no formula parsing and does not support any suffixes/prefixes except for 0x (hexadecimal numbers).
	/// While leading whitespaces are allowed by default no trailing characters of any kind are allowed.
	/// @param[in] str								The input string.
	/// @param[in] flags							Optional flags for the conversion.
	/// @return												Integer value of the string.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<Int64> ToInt64(const Block<const Utf32Char>& str, STRINGCONVERSION flags);

	//----------------------------------------------------------------------------------------
	/// Converts a Utf32Char character sequence to a 32 bit integer value.
	/// This routine does no formula parsing and does not support any suffixes/prefixes except for 0x (hexadecimal numbers).
	/// While leading whitespaces are allowed by default no trailing characters of any kind are allowed.
	/// @param[in] str								The input string.
	/// @param[in] flags							Optional flags for the conversion.
	/// @return												Integer value of the string.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<Int32> ToInt32(const Block<const Utf32Char>& str, STRINGCONVERSION flags);

	//----------------------------------------------------------------------------------------
	/// Converts a Utf32Char character sequence to a 64 bit unsigned integer value.
	/// This routine does no formula parsing and does not support any suffixes/prefixes except for 0x (hexadecimal numbers).
	/// While leading whitespaces are allowed by default no trailing characters of any kind are allowed.
	/// @param[in] str								The input string.
	/// @param[in] flags							Optional flags for the conversion.
	/// @return												Integer value of the string.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<UInt64> ToUInt64(const Block<const Utf32Char>& str, STRINGCONVERSION flags);

	//----------------------------------------------------------------------------------------
	/// Converts a Utf32Char character sequence to a 32 bit unsigned integer value.
	/// This routine does no formula parsing and does not support any suffixes/prefixes except for 0x (hexadecimal numbers).
	/// While leading whitespaces are allowed by default no trailing characters of any kind are allowed.
	/// @param[in] str								The input string.
	/// @param[in] flags							Optional flags for the conversion.
	/// @return												Integer value of the string.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<UInt32> ToUInt32(const Block<const Utf32Char>& str, STRINGCONVERSION flags);

	//----------------------------------------------------------------------------------------
	/// Converts a Utf32Char character sequence to a floating point value.
	/// This routine does no formula parsing.
	/// No leading whitespaces or characters that do not belong to the floating point value are allowed.
	/// @param[in] str								The character sequence.
	/// @param[out] processedChars		The actual number of characters that were read. This can be shorter than maxChars. The algorithm stops as soon as it finds a character that does not belong to the floating point value.
	/// @return												Floating point value of string.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<Float64> StringToFloat(const Block<const Utf32Char>& str, Int& processedChars);

	//----------------------------------------------------------------------------------------
	/// Converts a Utf32Char character sequence to an integer value.
	/// This routine does no formula parsing.
	/// No leading whitespaces or characters that do not belong to the integer value are allowed.
	/// @param[in] str								The character sequence.
	/// @param[in] base								Numerical base that is in the range of [2..36]. For regular decimal conversion pass 10, for hexadecimal conversion 16. NOTOK is valid.
	/// @param[in] autodetect0x				If true the string is scanned for a '0x' prefix. If that is detected the base is automatically set to 16.
	/// @param[in] signedMode					If false, negative numbers will result in an error. In signedMode numbers need to be within Int64 limits, otherwise UInt64.
	/// @param[out] processedChars		The actual number of characters that were read. This can be shorter than maxChars. The algorithm stops as soon as it finds a character that does not belong to the integer value.
	/// @return												Integer value of string. In signed mode the result must be cast to Int64.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<UInt64> StringToInteger(const Block<const Utf32Char>& str, Int base, Bool autodetect0x, Bool signedMode, Int& processedChars);

	//----------------------------------------------------------------------------------------
	/// Returns a string with the platform specific line ending.
	/// @return												String containing the line ending ("\r\n" or "\r").
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD const String& GetLineEnd();

	//----------------------------------------------------------------------------------------
	/// Returns a string with the platform specific line ending.
	/// @return												CString containing the line ending ("\r\n" or "\r").
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD const CString& GetLineEndC();

	// Formatting helper function that returns an allocated StringProxy class. It was moved here to reduce the code size of the API. The returned class needs to be freed with DeleteObj.
	static MAXON_METHOD StringProxy* FormatXArgs(const String& formatString, Int argsCnt, const void** args, TOSTR* argFuncs);

	// Scanning helper function that scans for up to 10 arguments. It was moved here to reduce the code size of the API.
	static MAXON_METHOD Bool ScanStringXArgs(const String& str, const String& format, Int* parsedCharacters, Int argsCnt, void** args, FROMSTR* argFuncs);

	// Scanning helper function that was moved here to reduce the code size of the API.
	static MAXON_METHOD Int64 ScanParameterBasic(const Block<const Utf32Char>& str, Bool signedMode, Int& processed, const String& formatStatement, Bool& error);
};

// include auto generated header file here
#include "stringconversion1.hxx"
// include auto generated header file here
#include "stringconversion2.hxx"

} // namespace maxon

#endif // STRINGCONVERSION_H__
