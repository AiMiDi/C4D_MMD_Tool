// --------------------------------------------------------------------------------------------------------------------
// Contains tools to work with regular expressions in the Maxon API.
// 
// This is just a thin-wrapper around the C++ `std::regex` library to serve as maintainable entry point.
// --------------------------------------------------------------------------------------------------------------------

#ifndef LIB_STD_REGEX_H__
#define LIB_STD_REGEX_H__

#include "maxon/datatype.h"
#include "maxon/interfacebase.h"

namespace maxon
{

/// @brief Contains tools to work with regular expressions in the Maxon API.
namespace regex
{

// ------------------------------------------------------------------------------------------------------------------
/// @brief Expresses options when matching regular expressions.
/// @details The flags are of identical meaning as the `std::regex_constants::match_flag_type` flags, but do not
/// use the same integer values (i.e., you cannot cast between them). Other than for `std::regex`, there is a builtin
/// `MATCH_ALL` flag which enables matching all occurrences of a pattern when searching a string. For matching,
/// splitting, and replacing operations, the `MATCH_ALL` flag is without any effect.
// ------------------------------------------------------------------------------------------------------------------
enum class REGEX_MATCH_FLAGS
{
	DEFAULT = (1 << 1),							///< Marks the match as having no special flags.
	NOT_BOL = (1 << 2),							///< Marks the match as not constrained to the beginning of a line.
	NOT_EO = (1 << 3),							///< Marks the match as not constrained to the end of a line.
	NOT_BOW = (1 << 4),							///< Marks the match as not constrained to the beginning of a word.
	NOT_EOW = (1 << 5),							///< Marks the match as not constrained to the end of a word.
	ANY = (1 << 6),									///< Allows matching any character, including newlines.
	NOT_NULL = (1 << 7),						///< Prevents matching empty sequences.
	CONTINUOUS = (1 << 8),					///< Requires the match to be contiguous with the previous match.
	PREV_AVAIL = (1 << 9),					///< Indicates that the previous character is available for matching.
	FORMAT_DEFAULT = (1 << 10),			///< Specifies the default formatting behavior.
	FORMAT_SED = (1 << 11),					///< Enables sed-style formatting.
	FORMAT_NO_COPY = (1 << 12),			///< Prevents copying unmatched portions of the input.
	FORMAT_FIRST_ONLY = (1 << 13),	///< Only formats the first match in the input.
	MATCH_ALL = (1 << 0),						///< Matches all occurrences of the pattern in the input and not just the first one (only relevant for `RegexInterface::Search()`).
} MAXON_ENUM_FLAGS(REGEX_MATCH_FLAGS);


// ------------------------------------------------------------------------------------------------------------------
/// @brief Expresses options for how regular expressions strings are parsed.
/// @details These flags are of identical meaning as the `std::regex_constants::syntax_option_type` flags, but do not
/// use the same integer values (i.e., you cannot cast between them).
// ------------------------------------------------------------------------------------------------------------------
enum class REGEX_SYNTAX_FLAGS
{
	ICASE = (1 << 1),							///< Enables case-insensitive matching.
	NOSUBS = (1 << 2),						///< Prevents substitutions in the match.
	OPTIMIZE = (1 << 3),					///< Optimizes the regex for performance.
	COLLATE = (1 << 4),						///< Enables collation for matching.
	ECMAScript = (1 << 5),				///< Enables ECMAScript syntax.
	BASIC = (1 << 6),							///< Enables basic regex syntax.
	EXTENDED = (1 << 7),					///< Enables extended regex syntax.
	AWK = (1 << 8),								///< Enables AWK syntax.
	GREP = (1 << 9),							///< Enables GREP syntax.
	EGREP = (1 << 10),						///< Enables E-GREP syntax.
} MAXON_ENUM_FLAGS(REGEX_SYNTAX_FLAGS);


// --------------------------------------------------------------------------------------------------------------------
/// @brief Represents a result for matching a string against an expression.
/// @note Only relevant in the context of `maxon::RegexInterface::Match`, other regex functions use other means of 
/// conveying their output.
/// @details A `RegexMatch` does not encapsulate a list of matches (as for example done by `std::smatch` or Python's 
/// `re.Match`) but a singular match. But `Regex.Match` operates with a collection of `RegexMatch` objects to realize the 
/// 'sequence of matches' aspect; for example when an expression contains multiple groups. The `maxon::regex` 
/// implementation does not support named capture groups and matches have therefore no capture group name field.
// --------------------------------------------------------------------------------------------------------------------
class RegexMatch
{

public:
	const String string;	///< The (sub)string in the input string that matches the expression or a group in the expression.
	const Int index;			///< The index of a match within a match sequence, `0` for the full match of a sequence, `1` for 
												///< the first group, and so on. This value will be identical to the index of the element in the
												///< list of matches, when for example a `BaseArray<RegexMatch>` is used as the value receiver of
												///< the operation.

	// ------------------------------------------------------------------------------------------------------------------
	/// @brief Constructs a match with the given match string and index.
	/// @param[in] string_					The matched (sub)string.
	/// @param[in] index_						The index of the match.
	// ------------------------------------------------------------------------------------------------------------------
	RegexMatch(const String& string_, Int index_): string(string_), index(index_) {}

	// ------------------------------------------------------------------------------------------------------------------
	/// @brief Checks if the match has the index `0`, i.e., if it is the full match of a match sequence.
	// ------------------------------------------------------------------------------------------------------------------
	Bool IsFullMatch() const
	{
		return index == 0;
	}

	// ------------------------------------------------------------------------------------------------------------------
	/// @brief Checks if the match is the empty string.
	// ------------------------------------------------------------------------------------------------------------------
	Bool IsEmptyMatch() const
	{
		return string.IsEmpty();
	}
};


class Regex;

// --------------------------------------------------------------------------------------------------------------------
/// @brief Realizes a regular expression object to carry out matching, searching, spliting, or replacement operations with.
/// @warning Just as `std::regex`, `maxon::regex::Regex` does not support named capturing groups. This regex feature is
/// simply not available, and one must use group indices instead to access the captured groups.
// --------------------------------------------------------------------------------------------------------------------
class RegexInterface : MAXON_INTERFACE_BASES(ObjectInterface)
{
	MAXON_INTERFACE(RegexInterface, MAXON_REFERENCE_COPY_ON_WRITE, "net.maxon.interface.regex");

public:

	// ------------------------------------------------------------------------------------------------------------------
	/// @brief Constructs an expression with the given string and syntax flags.
	/// 
	/// @param[in] string							The expression string.
	/// @param[in] flags							The syntax flags for the expression. Defaults to `REGEX_SYNTAX_FLAGS::ECMAScript`.
	// ------------------------------------------------------------------------------------------------------------------
	static MAXON_METHOD Result<Regex> Create(const String& string, REGEX_SYNTAX_FLAGS flags = REGEX_SYNTAX_FLAGS::ECMAScript);

	// ------------------------------------------------------------------------------------------------------------------
	/// @brief Returns the string of the expression.
	// ------------------------------------------------------------------------------------------------------------------
	MAXON_METHOD String GetString() const;

	// ------------------------------------------------------------------------------------------------------------------
	/// @brief Returns the syntax flags used by the expression.
	// ------------------------------------------------------------------------------------------------------------------
	MAXON_METHOD REGEX_SYNTAX_FLAGS GetFlags() const;

	// ------------------------------------------------------------------------------------------------------------------
	/// @brief Evaluates if the given `string` matches the regex in its entirety.
	/// @details As always in regular expressions, matching requires the full string to match the expression. The 0th 
	/// element in the `receiver` for a valid match will always be the full match, and following elements are sub-matches 
	/// for potentially present groups in the `regex`. Optional groups will evaluate to the empty string when not present
	/// in the input `string`, due to the full match nature of `Match()`. E.g., matching the string `"hello world"_s` 
	/// against the expression `"(hello)\\s*(world)?(!)?"_s` would return four matches and not three, even though there is no 
	/// exclamation mark at the end of the string. The matches would be: `("hello world", "hello", "world", "")`. Analogously, 
	/// matching the string `"hello"_s` with that expression would return `("hello", "hello", "", "")`.
	/// 
	/// @param[in] string						The string to match.
	/// @param[out] receiver				The receiver to store the matches for `regex` in `string` in.
	/// @param[in] flags						The flags for the match operation.
	/// @return										  `true` if `string` fully matches `expression`, `false` otherwise.
	// -------------------------------------------------------------------------------------------------------------------
	MAXON_METHOD Result<Bool> Match(const String& string, const ValueReceiver<const RegexMatch&>& receiver, REGEX_MATCH_FLAGS flags = REGEX_MATCH_FLAGS::DEFAULT) const;

	// ------------------------------------------------------------------------------------------------------------------
	/// @brief Finds all occurrences of the regex in the given `string`.
	/// @details Other than `Match()`, `Search()` does not require the full string to match the expression, and will return all the
	/// partial matches in the given string. But while `Match()` does support capture groups in its expressions, it will not decompose them in its
	/// output, i.e., it only yields the full match and not the capture groups for each partial match in the string.
	/// 
	/// @param[in] string						The string to search.
	/// @param[out] receiver				The receiver to store the matches for `regex` in `string` in.
	/// @param[in] flags						The flags for the search operation.
	/// @return										  `true` if `regex` matches in `string`, `false` otherwise.
	// -------------------------------------------------------------------------------------------------------------------
	MAXON_METHOD Result<Bool> Search(const String& string, const ValueReceiver<const String&>& receiver, REGEX_MATCH_FLAGS flags = REGEX_MATCH_FLAGS::DEFAULT|REGEX_MATCH_FLAGS::MATCH_ALL) const;

	// ------------------------------------------------------------------------------------------------------------------
	/// @brief Splits the given `string` into parts using the regex as a separator.
	/// @details The `regex` is not included in the result. The `string` is split at the positions where the `regex` matches.
	/// 
	/// @param[in] string						The string to split.
	/// @param[out] receiver				The receiver to store the parts of the split string in.
	/// @param[in] flags						The flags for the split operation.
	/// @return										  `true` if `string` was split, `false` otherwise.
	// -------------------------------------------------------------------------------------------------------------------
	MAXON_METHOD Result<Bool> Split(const String& string, const ValueReceiver<const String&>& receiver, REGEX_MATCH_FLAGS flags = REGEX_MATCH_FLAGS::DEFAULT) const;

	// ------------------------------------------------------------------------------------------------------------------
	/// @brief Replaces all occurrences of the regex in the given `string` with the given `replacement`.
	/// @details Supports replacement format strings based on the chosen regex syntax. Commonly supported symbols are `$&` 
	/// for the full match and `$1`, `$2`, ... for the first, second, ... capture group in the regex.
	/// 
	/// @param[in] string						The string to replace content in.
	/// @param[in] replacement			The regex formating syntax replacement string to use.
	/// @param[in] flags						The flags for the replace operation.
	/// @return										  The string with the replacements or the original string if no matches were found.
	// ------------------------------------------------------------------------------------------------------------------
	MAXON_METHOD Result<String> Replace(const String& string, const String& replacement, REGEX_MATCH_FLAGS flags = REGEX_MATCH_FLAGS::DEFAULT) const;
};

} // namespace regex

#include "lib_std_regex1.hxx"
#include "lib_std_regex2.hxx"

} // namespace maxon


#endif // LIB_STD_REGEX_H__

