#ifndef STRINGREGULAREXPRESSION_H__
#define STRINGREGULAREXPRESSION_H__

#include "maxon/string.h"
#include "maxon/interface.h"


namespace maxon
{

/// @addtogroup SYSTEM
/// @{

static const Int REGPARSE_CONCAT											= 1;
static const Int REGPARSE_ANYCHAR											= 2;
static const Int REGPARSE_ANYDIGIT										= 3;
static const Int REGPARSE_OPERATOR_OR									= 4;
static const Int REGPARSE_OPERATOR_STAR								= 5;
static const Int REGPARSE_OPERATOR_PARENTHESIS_LEFT		= 6;
static const Int REGPARSE_OPERATOR_PARENTHESIS_RIGHT	= 7;

//----------------------------------------------------------------------------------------
/// Regular expression parser find mode.
//----------------------------------------------------------------------------------------
enum class REGPARSEMODE
{
	MATCH = 1,	///< Searching for exact matches of the complete string.
	CONTAINS,		///< Searching for any match within the string.
	STARTS,			///< Searching for an match at the beginning of the text.
	ENDS				///< Searching for an match at the end of the text.
} MAXON_ENUM_LIST(REGPARSEMODE);

//----------------------------------------------------------------------------------------
/// Class to operate with regular expressions.
/// This class is not a complete regular expression parser. It supports only a subset of regular expressions.
/// Supported functions are:
//----------------------------------------------------------------------------------------
class RegularExpressionInterface
{
	MAXON_INTERFACE_NONVIRTUAL(RegularExpressionInterface, MAXON_REFERENCE_NORMAL, "net.maxon.interface.regularexpression");

public:
	//----------------------------------------------------------------------------------------
	/// @param[in] allocLocation			Source location.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD RegularExpressionInterface* Alloc(MAXON_SOURCE_LOCATION_DECLARATION);

	//----------------------------------------------------------------------------------------
	/// Initializes the regular expression parser with a complex expression.
	/// @param[in] regularExpression	A pattern string which allows the following placeholders:
	/// 															- * ... Zero or more of previous character.
	/// 															- + ... One or more of previous character.
	/// 															- . ... Any single character.
	/// 															- # ... Any single digit.
	/// 															- | ... Or condition.
	/// 															- [] ... One of the characters in the braces. E.g. [a-zA-Z] a-z or A-Z. [abc] a, b or c.
	/// 															- () ... A group of conditions. E.g. "(A|B)+" matches "ABAABB" but not "ACCCA".
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> InitExpression(const String& regularExpression);

	//----------------------------------------------------------------------------------------
	/// Initializes the regular expression parser with a simple expression.
	/// It can be used to find simple strings like: "net.maxon.unittest.*" to find all unit tests.
	/// @param[in] simpleExpression		A pattern string which allows the following placeholders:
	/// 															- * ... Zero or more of any character.
	/// 															- # ... One or more number characters (0...9). E.g. to check an ip4 address you can use the simple pattern "#.#.#.#" which matches "192.168.2.1".
	/// 															- ? ... Any single character.
	/// 															- | ... Or condition.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> InitSimpleExpression(const String& simpleExpression);

	//----------------------------------------------------------------------------------------
	/// Finds the first occurrence of the expression in the given text.
	/// @param[in] text								The text to search through.
	/// @param[in] mode								Search mode for the find operation. @see REGPARSEMODE.
	/// @param[in] onlyFirst					Set to true if the search should return after the first finding. This speeds up search because otherwise the call will collect all further patterns.
	/// @param[out] resPos						Returns the position of the matching pattern.
	/// @param[out] resPattern				Returns the string of the matching pattern.
	/// @return												True if the function call found any match.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<Bool> Find(const String& text, REGPARSEMODE mode, Bool onlyFirst, Int* resPos, String* resPattern);

	//----------------------------------------------------------------------------------------
	/// Finds the occurrence of the expression in the given text after calling Find.
	/// @param[in] text								The text to search through.
	/// @param[out] resPos						Returns the position of the matching pattern.
	/// @param[out] resPattern				Returns the string of the matching pattern.
	/// @return												True if the function call found another match.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<Bool> FindNext(const String& text, Int* resPos, String* resPattern);
};



#include "stringregularexpression1.hxx"

#include "stringregularexpression2.hxx"

/// @}

}


#endif // STRINGREGULAREXPRESSION_H__
