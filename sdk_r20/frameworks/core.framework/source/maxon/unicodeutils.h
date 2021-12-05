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

//----------------------------------------------------------------------------------------
/// This class handles unicode decompositions and correct string comparison using decomposition informations.
//----------------------------------------------------------------------------------------
class UnicodeUtils
{
	MAXON_INTERFACE_NONVIRTUAL(UnicodeUtils, MAXON_REFERENCE_NONE, "net.maxon.interface.unicodeutils");

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
};

// include auto generated header file here
#include "unicodeutils1.hxx"
// include auto generated header file here
#include "unicodeutils2.hxx"

/// @}

} // namespace maxon


#endif // UNICODEUTILS_H__
