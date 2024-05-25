#ifndef NUMTOSTRING_H__
#define NUMTOSTRING_H__

#include "maxon/apibase.h"

namespace maxon
{

namespace details
{
template<UInt... digits>
struct ToChars { static const Char value[sizeof...(digits) + 1]; };

template<UInt... digits>
const Char ToChars<digits...>::value[sizeof...(digits) + 1] = {('0' + digits)..., 0};

template<UInt rem, UInt... digits>
struct Explode : Explode<rem / 10, rem % 10, digits...> {};

template<UInt... digits>
struct Explode<0, digits...> : ToChars<digits...> {};
}

//----------------------------------------------------------------------------------------
/// Converts an unsigned integer value to a character string.
/// The character string can be found as an array of characters in the static member
/// @c value of NumToString.
/// For instance, the following will yield an Id with a value of "228".
/// @code
/// #define MCOMMAND_DISCONNECT 228
/// maxon::Id id = maxon::Id(maxon::NumToString<MCOMMAND_DISCONNECT>::value);
/// @endcode
//----------------------------------------------------------------------------------------
template<UInt num>
struct NumToString : maxon::details::Explode<num> {};

template<>
struct NumToString<0> : maxon::details::ToChars<0> {};

} // namespace maxon

#endif	// NUMTOSTRING_H__
