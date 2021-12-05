#if 1
namespace maxon
{
/// @cond INTERNAL

#ifndef MAXON_COMPILER_CLANG
#endif
	namespace enum46 { enum class NULL_RETURN_TYPE : UChar
	{
		VOID_ZERO,
		VOID_ZERO_FREE_FUNCTION,
		INTEGRAL_ZERO,
		FLOAT_ZERO,
		DOUBLE_ZERO,
		POINTER_TO_ZERO,
		OTHER
	} ; }
	maxon::String PrivateToString_NULL_RETURN_TYPE46(std::underlying_type<enum46::NULL_RETURN_TYPE>::type x, const maxon::FormatStatement* fmt)
	{
		const maxon::UInt64 values[] = {(maxon::UInt64) enum46::NULL_RETURN_TYPE::VOID_ZERO, (maxon::UInt64) enum46::NULL_RETURN_TYPE::VOID_ZERO_FREE_FUNCTION, (maxon::UInt64) enum46::NULL_RETURN_TYPE::INTEGRAL_ZERO, (maxon::UInt64) enum46::NULL_RETURN_TYPE::FLOAT_ZERO, (maxon::UInt64) enum46::NULL_RETURN_TYPE::DOUBLE_ZERO, (maxon::UInt64) enum46::NULL_RETURN_TYPE::POINTER_TO_ZERO, (maxon::UInt64) enum46::NULL_RETURN_TYPE::OTHER};
		return maxon::StringInterface::PrivateEnumToString((maxon::UInt64) x, "NULL_RETURN_TYPE", SIZEOF(x), false, values, "VOID_ZERO\0VOID_ZERO_FREE_FUNCTION\0INTEGRAL_ZERO\0FLOAT_ZERO\0DOUBLE_ZERO\0POINTER_TO_ZERO\0OTHER\0", fmt);
	}
#ifndef MAXON_COMPILER_MSVC
#else
#endif
#ifndef MAXON_COMPILER_MSVC
#endif
#ifndef MAXON_COMPILER_MSVC
#endif
/// @endcond

#ifdef MAXON_COMPILER_MSVC
#else
#endif
#if defined(MAXON_COMPILER_MSVC) && MAXON_COMPILER_MSVC >= 1914
#endif
#ifdef CPP_853_HACK
#endif
#ifdef MAXON_COMPILER_INTEL
#else
#endif
/// @cond INTERNAL

/// @endcond

}
#endif
