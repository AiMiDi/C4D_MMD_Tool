/////////////////////////////////////////////////////////////
// Cinema 4D SDK                                           //
/////////////////////////////////////////////////////////////
// (c) MAXON Computer GmbH, all rights reserved            //
/////////////////////////////////////////////////////////////

#ifndef LIB_REGEXPR_H__
#define LIB_REGEXPR_H__

/// @addtogroup group_regexprlibrary Regular Expression
/// @ingroup group_library
/// @{

/// Regular expression library ID.
#define REG_EXP_PARSER		1011197

#define OPERATOR_CONCAT		1
#define ANY_CHAR					2			///< Any character = ASCII @em 2.
#define ANY_DIGIT					3			///< Any digit = ASCII @em 3.

/// @addtogroup REGPARSEMODE
/// @ingroup group_enumeration
/// @{
enum class REGPARSEMODE
{
	MATCH = 1,			///< Full match.
	CONTAINS,				///< Partial match.
	STARTS,					///< Match starting at the beginning.
	ENDS						///< Match finishing at the end.
} MAXON_ENUM_LIST(REGPARSEMODE);
/// @}

//----------------------------------------------------------------------------------------
/// A simple regular expression parser that supports '(', ')', '*', '|', @ref ANY_CHAR and @ref ANY_DIGIT characters.
/// @addAllocFreeAutoAllocNote
//----------------------------------------------------------------------------------------
class RegularExprParser
{
private:
	RegularExprParser() { }
public:

	/// @name Alloc/Free
	/// @{

	//----------------------------------------------------------------------------------------
	/// @allocatesA{regular expression parser}
	/// @return												@allocReturn{regular expression parser}
	//----------------------------------------------------------------------------------------
	static RegularExprParser* Alloc();

	//----------------------------------------------------------------------------------------
	/// @destructsAlloc{regular expression parsers}
	/// @param[in,out] p							@theToDestruct{regular expression parser}
	//----------------------------------------------------------------------------------------
	static void Free(RegularExprParser* p);

	/// @}

	/// @name Expression
	/// @{

	//----------------------------------------------------------------------------------------
	/// Initializes the parser with the regular expression @formatParam{strExprssion}.
	/// @param[in] strExprssion				The regular expression.
	/// @return												@trueIfOtherwiseFalse{successful}
	//----------------------------------------------------------------------------------------
	Bool Init(const String &strExprssion);

	//----------------------------------------------------------------------------------------
	/// Performs a search using the regular expression passed to Init() in the string @formatParam{strText}, returning the first match in @formatParam{lPos} and @formatParam{strPattern}.\n
	/// Use FindNext() to access further matches.
	/// @param[in] strText						The text to search.
	/// @param[in] mode								The search mode: @enumerateEnum{REGPARSEMODE}
	/// @param[in] bOnlyFirst					If @formatConstant{true} then only one match is found, so further matches will not be returned by FindNext().
	/// @param[out] lPos							Assigned the position of the first match.
	/// @param[out] strPattern				Assigned the text of the first match.
	/// @return												@trueIfOtherwiseFalse{a match was found}
	//----------------------------------------------------------------------------------------
	Bool FindFirst(const String &strText, REGPARSEMODE mode, Bool bOnlyFirst, Int32 &lPos, String &strPattern);

	//----------------------------------------------------------------------------------------
	/// Retrieves further matches after the one returned by FindFirst().
	/// @param[out] lPos							Assigned the position of the match.
	/// @param[out] strPattern				Assigned the text of the match.
	/// @return												@trueIfOtherwiseFalse{another match was returned}
	//----------------------------------------------------------------------------------------
	Bool FindNext(Int32 &lPos, String &strPattern);

	//----------------------------------------------------------------------------------------
	/// Cleans up the memory allocated by Init().
	//----------------------------------------------------------------------------------------
	void CleanUp();

	/// @}
};

/// @}

/// @cond IGNORE

// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF

class RegExpParser;
struct RegExprLib : public C4DLibrary
{
	RegExpParser*	(*RegExprLib_Alloc)();
	void					(*RegExprLib_Free)(RegExpParser *&p);
	Bool					(RegExpParser::*Init)(const String &strExprssion);
	Bool					(RegExpParser::*FindFirst)(const String &strText, REGPARSEMODE mode, Bool bOnlyFirst, Int32 &lPos, String &strPattern);
	Bool					(RegExpParser::*FindNext)(Int32 &lPos, String &strPattern);
	void					(RegExpParser::*CleanUp)();
};

// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF

/// @endcond

#endif // LIB_REGEXPR_H__
