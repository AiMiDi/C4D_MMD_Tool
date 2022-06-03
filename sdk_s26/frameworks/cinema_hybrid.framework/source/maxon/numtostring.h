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
struct explode : explode<rem / 10, rem % 10, digits...> {};

template<UInt... digits>
struct explode<0, digits...> : ToChars<digits...> {};
}

template<UInt num>
struct NumToString : details::explode<num> {};

template<>
struct NumToString<0> : details::ToChars<0> {};
} // namespace maxon

#endif	// NUMTOSTRING_H__
