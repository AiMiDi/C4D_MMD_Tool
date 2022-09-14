#ifndef TYPENAME_H__
#define TYPENAME_H__

#include "maxon/apibase.h"

namespace maxon
{

namespace details
{
template <typename... T> MAXON_ATTRIBUTE_FORCE_INLINE const Char* TypeNameHelper()
{
	return MAXON_FUNCTION_SIGNATURE;
}

template <typename T> MAXON_ATTRIBUTE_FORCE_INLINE const Char* GetTypeNameHelper()
{
	return maxon::details::TypeNameHelper<int, T, int>();
}

const Char* SkipTypeNamePrefix(const Char* name);

Id SkipTypeNameSuffix(const Char* name);
}

//----------------------------------------------------------------------------------------
/// Returns a compiler-generated name for type T. This is based on
/// the compiler-specific macros __FUNCSIG__ or __PRETTY_FUNCTION__ (see MAXON_FUNCTION_SIGNATURE).
/// @tparam T											A type.
/// @return												Compiled-generated name for T.
//----------------------------------------------------------------------------------------
template <typename T> MAXON_ATTRIBUTE_FORCE_INLINE Id GetTypeName()
{
	return maxon::details::SkipTypeNameSuffix(maxon::details::SkipTypeNamePrefix(maxon::details::GetTypeNameHelper<T>()));
}

}

#endif // TYPENAME_H__
