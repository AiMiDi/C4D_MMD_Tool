#ifndef CONSTEXPR_LOWERCASE_H__
#define CONSTEXPR_LOWERCASE_H__

#include "maxon/apibase.h"

// Temporarily move the LowerCaseStringHelper in global namespace as MSVC 2017
// creates an internal compiler error.
//----------------------------------------------------------------------------------------
/// LowerCaseString has a static member value which is const Char string consisting of the characters given by STR,
/// but converted to lowercase. For example LowerCaseString<'A', 'b', 'C'>::value is "abc".
//----------------------------------------------------------------------------------------
template <maxon::Char... STR> struct LowerCaseString
{
	static constexpr const maxon::Char value[sizeof...(STR)+1] = { ((STR >= 'A' && STR <= 'Z') ? STR + ('a' - 'A') : STR)..., '\0' };
};

// Definition of member variable value.
template <maxon::Char... STR> constexpr const maxon::Char LowerCaseString<STR...>::value[sizeof...(STR)+1];


template <typename, typename> struct LowerCaseStringHelper;

template <typename STRING_WRAPPER, size_t... INDICES> struct LowerCaseStringHelper<STRING_WRAPPER, std::index_sequence<INDICES...>>
{
	using type = LowerCaseString<STRING_WRAPPER{}.value[INDICES]...>;
};


namespace maxon
{

namespace details
{

// Code based on https://texus.me/2015/07/28/string-to-lowercase-compile-time/
// => https://gist.github.com/texus/8d867996e7a073e1498e8c18d920086c

//----------------------------------------------------------------------------------------
/// MAXON_CONSTEXPR_TOLOWER returns the given string literal as a C string
/// where all characters have be converted to lower case. The construction of the converted
/// C string happens at compile time.
/// @param[in] stringLiteral			A C string literal.
/// @return												Pointer to a const Char array which contains the given stringLiteral converted to lower case.
//----------------------------------------------------------------------------------------
#define MAXON_CONSTEXPR_TOLOWER(stringLiteral)																																											\
	[] {																																																															\
		struct StringWrapper																																																						\
		{																																																																\
			const maxon::Char* value = stringLiteral;																																							\
		};																																																															\
		return LowerCaseStringHelper<StringWrapper, std::make_index_sequence<sizeof(stringLiteral) - 1>>::type::value;	\
	}()

}

}

#endif // CONSTEXPR_LOWERCASE_H__
