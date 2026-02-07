#ifndef UNICODEUTILS_H__
#define UNICODEUTILS_H__


#include "maxon/interfacebase.h"
#include "maxon/basearray.h"
#include "maxon/string.h"

namespace maxon
{

/// @addtogroup SYSTEM
/// @{

enum class NORMALIZATION
{
	NFC = 1,          // Standard composition form
	NFD = 2,          // Standard decomposition form
	NKDC = 3,         // Not imeplemented yet
	NFKD = 4,         // Not imeplemented yet
	NFD_HFS = 5       // special for HFS+
} MAXON_ENUM_LIST(NORMALIZATION);

enum class CHARACTERTYPE : UChar
{
	UNKNOWN = 0,
	LU, // Letter, Uppercase
	LL, // Letter, Lowercase
	LT, // Letter, Titlecase
	LM, // Letter, Modifier
	LO, // Letter, Other
	MN, // Mark, Nonspacing
	MC, // Mark, Spacing Combining
	ME, // Mark, Enclosing
	ND, // Number, Decimal Digit
	NL, // Number, Letter
	NO, // Number, Other
	PC, // Punctuation, Connector
	PD, // Punctuation, Dash
	PS, // Punctuation, Open
	PE, // Punctuation, Close
	PI, // Punctuation, Initial quote(may behave like Ps or Pe depending on usage)
	PF, // Punctuation, Final quote(may behave like Ps or Pe depending on usage)
	PO, // Punctuation, Other
	SM, // Symbol, Math
	SC, // Symbol, Currency
	SK, // Symbol, Modifier
	SO, // Symbol, Other
	ZS, // Separator, Space
	ZL, // Separator, Line
	ZP, // Separator, Paragraph
	CC, // Other, Control
	CF, // Other, Format
	CS, // Other, Surrogate
	CO, // Other, Private Use
	CN, // Other, Not Assigned(no characters in the file have this property)
} MAXON_ENUM_LIST(CHARACTERTYPE);

enum class CHARACTERBIDITYPE : UChar
{
	UNKNOWN = 0,
	AL,	 // Right-to-Left Arabic: Arabic script characters.
	AN,	 // Arabic Number: Arabic-Indic digits.
	B,	 // Paragraph Separator: Indicates the end of a paragraph.
	BN,	 // Boundary Neutral: Characters that have no inherent directionality and don't affect surrounding characters.
	CS,	 // Common Separator: Characters that separate numbers but are common across scripts, like the comma.
	EN,	 // European Number: European digits (0-9).
	ES,	 // European Separator: Characters that separate numbers in European scripts, such as the comma or period.
	ET,	 // European Terminator: Characters that terminate numbers in European scripts, like currency symbols.
	FSI, // First Strong Isolate: Isolates a segment with an initial strong character that defines its directionality.
	L,	 // Left-to-Right: Characters that are written from left to right, like Latin, Cyrillic, and Greek scripts.
	LRE, // Left-to-Right Embedding: Embeds left-to-right text within bidirectional text.
	LRI, // Left-to-Right Isolate: Isolates a left-to-right text segment.
	LRO, // Left-to-Right Override: Forces characters to be treated as left-to-right.
	NSM, // Nonspacing Mark: Characters that are combining marks with no inherent directionality.
	ON,	 // Other Neutral: Punctuation and other characters that don't have strong directionality.
	PDF, // Pop Directional Format: Terminates the scope of the last LRE, RLE, LRO, or RLO.
	PDI, // Pop Directional Isolate: Terminates the scope of the last LRI, RLI, or FSI.
	R,	 // Right-to-Left: Characters that are written from right to left, such as Hebrew.
	RLE, // Right-to-Left Embedding: Embeds right-to-left text within bidirectional text.
	RLI, // Right-to-Left Isolate: Isolates a right-to-left text segment.
	RLO, // Right-to-Left Override: Forces characters to be treated as right-to-left.
	S,	 // Segment Separator: Used to separate segments within text. Example: Line Separator.
	WS,	 // Whitespace: Space characters, tabs, and other whitespace.
	WW,	 //  
} MAXON_ENUM_LIST(CHARACTERBIDITYPE);

//----------------------------------------------------------------------------------------
/// This class handles unicode decompositions and correct string comparison using decomposition informations.
//----------------------------------------------------------------------------------------
class UnicodeUtils
{
	MAXON_INTERFACE_NONVIRTUAL(UnicodeUtils, MAXON_REFERENCE_STATIC, "net.maxon.interface.unicodeutils", MAXON_IMPLEMENTATION_MODULE("net.maxon.kernel"));

public:
	//----------------------------------------------------------------------------------------
	/// Decomposed representation of a unicode character.
	//----------------------------------------------------------------------------------------
	using DecompositionArray = BaseArray<Utf32Char, 1, BASEARRAYFLAGS::MOVEANDCOPYOBJECTS, FixedBufferAllocator<Utf32Char, 8, DefaultAllocator>>;
	using DecompositionHfsArray = BaseArray<Utf16Char, 1, BASEARRAYFLAGS::MOVEANDCOPYOBJECTS, FixedBufferAllocator<Utf16Char, 8, DefaultAllocator>>;

	//----------------------------------------------------------------------------------------
	/// Normalize a string to HFS+ decomposition
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<String> DecomposeStringHfs(const String& str);

	//----------------------------------------------------------------------------------------
	/// Normalize a string to HFS+ decomposition
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<String> DecomposeString(const String& str);

	//----------------------------------------------------------------------------------------
	/// Returns the version of Unicode database used internally.
	/// @return												The version, e.g: String("8.0.0")
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD String GetUnicodeVersion();

	//----------------------------------------------------------------------------------------
	/// Normalize a string
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<String> NormalizeString(NORMALIZATION form, const String& str);

	//----------------------------------------------------------------------------------------
	/// Breaks a unicode character into the decomposited properties.
	/// This is e.g. useful for sorting algorithms.
	/// A german 'A' umlaut will be decomposed to 'A' and '..'
	/// @param[in] chr								Unicode character to be decomposited.
	/// @param[out] res_decomp				Array with the decomposited character elements.
	/// @return												True if the operation was successful.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Bool UniCharDecomposition(Utf32Char chr, DecompositionArray& res_decomp);

	//----------------------------------------------------------------------------------------
	/// Breaks a unicode character into the decomposited properties.
	/// This is e.g. useful for sorting algorithms.
	/// A german 'A' umlaut will be decomposed to 'A' and '..'
	/// @param[in] chr								Unicode character to be decomposited.
	/// @param[out] res_decomp				Array with the decomposited character elements.
	/// @return												True if the operation was successful.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Bool UniCharHfsDecomposition(Utf16Char chr, DecompositionHfsArray& res_decomp);

	//----------------------------------------------------------------------------------------
	/// Compares two unicode characters.
	/// this function uses the decomposition properties to do advanced unicode sorting.
	/// @see UniCharDecomposition().
	/// @param[in] a									First character to compare.
	/// @param[in] b									Second character to compare.
	/// @return												COMPARERESULT of the operation.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD COMPARERESULT UniCodeCompare(Utf32Char a, Utf32Char b);

	//----------------------------------------------------------------------------------------
	/// Returns the type of a given unicode char. This can be used to determine if a character is a letter, number or symbol.
	/// @param[in] chr								Character to find.
	/// @return												CHARACTERTYPE of the character.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD CHARACTERTYPE GetCharacterType(Utf32Char chr);	

	//----------------------------------------------------------------------------------------
	/// Returns the uppercase of a given unicode char.
	/// @param[in] chr								Character to convert to uppercase.
	/// @return												Uppercase character of chr.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Utf32Char UpperCase(Utf32Char chr);

	//----------------------------------------------------------------------------------------
	/// Returns the titlecase version of a given unicode char.
	/// @param[in] chr								Character to convert to titlecase.
	/// @return												Titlecase character of chr.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Utf32Char TitleCase(Utf32Char chr);

	//----------------------------------------------------------------------------------------
	/// Returns the lowercase version of a given unicode char.
	/// @param[in] chr								Character to convert to lowercase.
	/// @return												Lowercase character of chr.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Utf32Char LowerCase(Utf32Char chr);

	//----------------------------------------------------------------------------------------
	/// Returns the bidirectional type of a given unicode char.
	/// It can be used to determine the direction of a character in a bidirectional text (right-to-left).
	/// @param[in] chr								Character to find.
	/// @return												CHARACTERBIDITYPE of the character.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD CHARACTERBIDITYPE GetCharacterBiDiType(Utf32Char chr);

	//----------------------------------------------------------------------------------------
	/// Returns true if the string contains right-to-left characters (e.g. Arabic text). Only the first 50 characters of the string are checked.
	/// @param[in] str								String to check.
	/// @return												@trueOtherwiseFalse{if string is right-to-left}
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Bool IsRightToLeftString(const String& str);
};

// include auto generated header file here
#include "unicodeutils1.hxx"
// include auto generated header file here
#include "unicodeutils2.hxx"

//----------------------------------------------------------------------------------------
/// Checks if the passed character is a unicode letter.
//----------------------------------------------------------------------------------------
template <typename TYPE> MAXON_ATTRIBUTE_FORCE_INLINE Bool IsUnicodeLetter(TYPE chr)
{
	CHARACTERTYPE u = UnicodeUtils::GetCharacterType(chr);
	switch (u)
	{
		case CHARACTERTYPE::LU: // Letter, Uppercase
		case CHARACTERTYPE::LL: // Letter, Lowercase
		case CHARACTERTYPE::LT: // Letter, Titlecase
		case CHARACTERTYPE::LM: // Letter, Modifier
		case CHARACTERTYPE::LO: // Letter, Other
			return true;
		default: break;
	}
	return false;
}

/// @}

} // namespace maxon


#endif // UNICODEUTILS_H__
