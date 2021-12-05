#ifndef ABITYPE_H__
#define ABITYPE_H__

#include "maxon/apibase.h"

namespace maxon
{

//----------------------------------------------------------------------------------------
/// <tt>ABIParamType<T>::type</tt> is an erased type which is compatible with T with respect to the calling
/// convention of the ABI when used for a function parameter.
/// For example, ABIParamType maps all integral, enumeration, pointer and reference types to
/// the signed integral type of the same size (reference types are treated like pointer types).
/// The typical use is to reduce the number of instantiations of stub function templates,
/// because those stubs will work correctly even if only the erased types are used.
///
/// @tparam T											Type for which the erased, ABI-compatible param type shall be determined.
//----------------------------------------------------------------------------------------
template <typename T, typename CHECK = void> struct ABIParamType
{
	using type = T;
};


template <typename T> struct ABIParamType<T, typename std::enable_if<std::is_enum<T>::value || std::is_integral<T>::value>::type>
{
	using type = typename std::conditional<sizeof(T) == 1, Char, typename std::conditional<sizeof(T) == 2, Int16, typename std::conditional<sizeof(T) == 4, Int32, Int64>::type>::type>::type;
};

template <typename T, Bool STRIDED, Bool MOVE> struct ABIParamType<Block<T, STRIDED, MOVE>>
{
	using type = Block<Int, STRIDED>;
};

template <typename T> struct ABIParamType<T, typename std::enable_if<std::is_pointer<T>::value>::type>
{
	using type = ABIParamType<size_t>::type;
};

template <typename T> struct ABIParamType<T, typename std::enable_if<std::is_reference<T>::value>::type>
{
	using type = ABIParamType<void*>::type;
};

//----------------------------------------------------------------------------------------
/// <tt>ABIReturnType<T>::type</tt> is an erased type which is compatible with T with respect to the calling
/// convention of the ABI when used for a return value.
///
/// @see ABIParamType
///
/// @tparam T											Type for which the erased, ABI-compatible return type shall be determined.
//----------------------------------------------------------------------------------------
template <typename T> using ABIReturnType = ABIParamType<T>;

}

#endif // ABITYPE_H__
