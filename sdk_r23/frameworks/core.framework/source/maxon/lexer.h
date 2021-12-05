#ifndef LEXER_H__
#define LEXER_H__

#include "maxon/iostreams.h"
#include "maxon/url.h"

// this include is necessary for StringDecodingRef
#include "maxon/stringencoding.h"

namespace maxon
{

/// @addtogroup IO
/// @{

//----------------------------------------------------------------------------------------
/// Enumeration for special lexer symbols.
//----------------------------------------------------------------------------------------
enum class LEXERSYMBOL : UChar
{
	NONE,

	ILLEGAL,

	ENDOFFILE,						///< The end of file or stream was reached.

	IDENTIFIER,						///< An arbitrary symbol that is neither a string, nor a value. It may contain unicode characters.

	STRING,								///< A double-quoted string.
	STRINGCHR,						///< A single-quoted string.

	NUMBER,								///< A numerical value.

	NEWLINE,							///< '\\r', '\\n' or a combination of both.
	CURLYBRACKET_OPEN,		///< '{' symbol.
	CURLYBRACKET_CLOSE,		///< '}' symbol.
	PARENTHESE_OPEN,			///< '(' symbol.
	PARENTHESE_CLOSE,			///< ')' symbol.
	SQUAREBRACKET_OPEN,		///< '[' symbol.
	SQUAREBRACKET_CLOSE,	///< ']' symbol.
	SLASH,								///< '/' symbol.
	EQUAL,								///< '=' symbol.
	COMMA,								///< ',' symbol.
	SEMICOLON,						///< ';' symbol.
	COLON,								///< ':' symbol.
	PLUS,									///< '+' symbol.
	TILDE,								///< '~' symbol.
	PREPROCESSOR,					///< '#' symbol.
	MULTIPLY,							///< '*' symbol.
	PIPE,									///< '|' symbol.
	AMPERSAND,						///< '&' symbol.

	OPERATOR							///< One of the operator symbols added by LexerInterface::AddOperator.
} MAXON_ENUM_LIST(LEXERSYMBOL);

//----------------------------------------------------------------------------------------
/// Flags used for LexerInterface::ReadNextSymbol() and LexerInterface::ReadNextSymbolExpected()
//----------------------------------------------------------------------------------------
enum class LEXERSYMBOLFLAGS
{
	NONE						= 0,
	NO_NUMBER				= 1 << 0,	///< If set, numbers (and characters as '.' or '-') are not recognized as numbers. Instead either an LEXERSYMBOL::IDENTIFIER or LEXERSYMBOL::ILLEGAL will be generated (and GetIdent() returns the symbol).
	ALLOWSTRINGS		= 1 << 1,	///< If set, strings starting with \" or ' will be detected and LEXERSYMBOL::STRING is returned. GetIdent() returns the content of the string.
	MINUS_OPERATOR	= 1 << 2,	///< If set, the minus symbol in front of a number will be reported as own token.
} MAXON_ENUM_FLAGS(LEXERSYMBOLFLAGS);

//----------------------------------------------------------------------------------------
/// Flags used in LexerInterface::Init()
//----------------------------------------------------------------------------------------
enum class LEXERINITFLAGS
{
	NONE										= 0,
	NEED_EOL								= 1 << 0,		///< The lexer stops at each end of line and returns LEXERSYMBOL::OPERATOR_NEWLINE whenever a newline appears.
	REWIND_WHEN_DONE				= 1 << 1,		///< The lexer will rewind the stream to the last interpreted character when it is done. Only set this if you want to continue scanning the open stream. It will only work if the stream supports seeking. Also a string decoding that has an exact counterpart (e.g. StringEncodings::Utf8) needs to be passed to the lexer.
	ALLOW_DOLLAR_IDENT			= 1 << 2,		///< Allow $ as part of identifiers.
	ALLOW_AT_IDENT					= 1 << 3,		///< Allow @ as part of identifiers (but not as start).
	NON_ASCII_IS_IDENT			= 1 << 4,		///< If set, non-ASCII characters (code > 127) are considered to be part of identifiers.
	HASH_COMMENTS						= 1 << 5,		///< If set, comments are introduced by the hash character (instead of C++-like comments).
	ESCAPE_IN_SINGLE_QUOTED = 1 << 6,		///< If set, escape characters are also considered in single-quoted-strings.
	C_ESCAPE_SEQUENCES			= 1 << 7,		///< If set, a subset of C escape sequences is recognized in strings (\\n, \\t and \\r).
	SPACESCOMPATIBILITY			= 1 << 29,	///< If set, a newline character will be included in the result of LexerInterface::GetLeadingSpaces.
	C4DSTRCOMPATIBILITY			= 1 << 30,	///< If set, the lexer will handle the escape character in a special manner. Then the escape character works only for the following character if it matches \".
} MAXON_ENUM_FLAGS(LEXERINITFLAGS);


//----------------------------------------------------------------------------------------
/// Lexer class. This class provides functionality to scan text files.
/// the stream is tokenized for easy reading.
//----------------------------------------------------------------------------------------
class LexerInterface
{
	MAXON_INTERFACE_NONVIRTUAL(LexerInterface, MAXON_REFERENCE_NORMAL, "net.maxon.interface.lexer");

public:
	//----------------------------------------------------------------------------------------
	/// @param[in] allocLocation			Source location.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD LexerInterface* Alloc(MAXON_SOURCE_LOCATION_DECLARATION);

	//----------------------------------------------------------------------------------------
	/// Initializes the lexer class. This functions opens the stream.
	/// @param[in] fileName						Url or Input Stream.
	/// @param[in] flags							Control flags for the lexer. See LEXERINITFLAGS for description.
	/// @param[in] stringEscapeCharacters	Defines characters that allow to escape \" ' and the escape character itself within strings. By Default this is '\'.
	/// @param[in] stringDecoding			String encoding for this file. If a nullptr is passed (recommended) then StreamConversions::UtfTextDecoder will be used to auto-detect the file encoding.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> Init(UrlOrInputStream&& fileName, LEXERINITFLAGS flags, const String& stringEscapeCharacters, const StringDecodingRef& stringDecoding);

	//----------------------------------------------------------------------------------------
	/// Adds an operator symbol to the lexer. This is a symbol which consists of several non-letter characters
	/// such as && or +=. The lexer will then return such a character sequence as a single symbol of type LEXERSYMBOL::OPERATOR.
	/// @param[in] chars							The symbol to add.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> AddOperator(const String& chars);

	//----------------------------------------------------------------------------------------
	/// Closes the stream
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> Close();

	//----------------------------------------------------------------------------------------
	/// Reads the next character out of the stream.
	/// @return												Returns the character that has been read. This function returns 0 if the end of the file has been reached.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<Utf32Char> ReadNextChar();

	//----------------------------------------------------------------------------------------
	/// Skips the spaces from the current position.
	/// @return												True if the function was successful. False if the end of the file has been reached.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<Bool> SkipSpaces();

	//----------------------------------------------------------------------------------------
	/// Skips line to the end.
	/// If the lexer is in NEED_EOL mode the method stops at line end. Otherwise it will advance
	/// to the next line and stops when non-whitespace is found.
	/// @param[in] collectSkipped			If true then the skipped bytes are returned with the next GetIdent() call.
	/// @return												True if the function was successful. False if the end of the file has been reached. Otherwise an error.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<Bool> SkipLineToEnd(Bool collectSkipped = false);

	//----------------------------------------------------------------------------------------
	/// Reads the next symbol in the stream. GetIdent() returns the name of the symbol/ident/number/operator.
	/// @param[in] flags							See LEXERSYMBOLFLAGS for details.
	/// @return												Next detected symbol. LEXERSYMBOL::ENDOFFILE if the end of file has been reached.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<LEXERSYMBOL> ReadNextSymbol(LEXERSYMBOLFLAGS flags = LEXERSYMBOLFLAGS::NONE);

	//----------------------------------------------------------------------------------------
	/// Reads the next symbol in the stream and checks if it's identical to requiredSymbols. GetIdent() returns the name of the symbol/ident/number/operator.
	/// @param[in] expectedSymbols		Symbol that is required.
	/// @param[in] flags							See LEXERSYMBOLFLAGS for details.
	/// @return												Next detected symbol. LEXERSYMBOL::ENDOFFILE if the end of file has been reached.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> ReadNextSymbolExpected(LEXERSYMBOL expectedSymbols, LEXERSYMBOLFLAGS flags = LEXERSYMBOLFLAGS::NONE);

	//----------------------------------------------------------------------------------------
	/// Rewinds the current symbol so that the next ReadNextSymbol returns exactly the same as before.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD void RewindSymbol();

	//----------------------------------------------------------------------------------------
	/// Returns the current symbol
	//----------------------------------------------------------------------------------------
	MAXON_METHOD LEXERSYMBOL GetSymbol() const;

	//----------------------------------------------------------------------------------------
	/// Returns the number of leading spaces of the symbol. Tabs count as up to 8 spaces.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Int GetLeadingSpace() const;

	//----------------------------------------------------------------------------------------
	/// Returns the current String ident.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD String GetIdent() const;

	//----------------------------------------------------------------------------------------
	/// In case of LEXERSYMBOL::NUMBER this function returns the floating point value of this number.
	/// @param[out] val								Reference to the value.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> GetFloat(Float32& val) const;

	//----------------------------------------------------------------------------------------
	/// In case of LEXERSYMBOL::NUMBER this function returns the floating point value of this number.
	/// @param[in] val								Reference to the value.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> GetFloat(Float64& val) const;

	//----------------------------------------------------------------------------------------
	/// In case of LEXERSYMBOL::NUMBER this function returns the integer value of this number.
	/// @param[in] val								Reference to the value.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> GetInt(Int32& val) const;

	//----------------------------------------------------------------------------------------
	/// In case of LEXERSYMBOL::NUMBER this function returns the integer value of this number.
	/// @param[in] val								Reference to the value.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> GetInt(Int64& val) const;

	//----------------------------------------------------------------------------------------
	/// In case of LEXERSYMBOL::NUMBER this function returns the integer value of this number.
	/// @param[in] val								Reference to the value.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> GetUInt(UInt32& val) const;

	//----------------------------------------------------------------------------------------
	/// In case of LEXERSYMBOL::NUMBER this function returns the integer value of this number.
	/// @param[in] val								Reference to the value.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> GetUInt(UInt64& val) const;

	//----------------------------------------------------------------------------------------
	/// Returns the current reading position
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<Int64> GetCurrentReadPosition() const;

	//----------------------------------------------------------------------------------------
	/// Returns the position of the current symbol.
	/// @return												The position of the current symbol.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<Int64> GetSymbolPosition() const;

	//----------------------------------------------------------------------------------------
	/// Checks against the current identifier.
	/// @param[in] cmp								C-style string to compare with.
	/// @return												Returns true if identical.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Bool CheckIdent(const Char* cmp) const;

	//----------------------------------------------------------------------------------------
	/// Checks against the current identifier.
	/// @param[in] cmp								String to compare with.
	/// @return												Returns true if identical.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Bool CheckIdent(const String& cmp) const;

	//----------------------------------------------------------------------------------------
	/// Returns the current line number within the file.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Int GetLine() const;
};

#include "lexer1.hxx"

#include "lexer2.hxx"

/// @}

} // namespace maxon

#endif // LEXER_H__
