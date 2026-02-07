#ifndef NUMTOSTRING_H__
#define NUMTOSTRING_H__

#include "maxon/entity.h"

namespace maxon
{

namespace details
{
template<UInt rem, UInt... digits>
struct Explode : Explode<rem / 10, rem % 10, digits...> {};

template<UInt... digits>
struct Explode<0, digits...> : maxon::FixedSizeArrayWrapperType<maxon::Char, ('0' + digits)..., 0> {};
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
struct NumToString<0> : maxon::FixedSizeArrayWrapperType<maxon::Char, '0', 0> {};

} // namespace maxon

#endif // NUMTOSTRING_H__
