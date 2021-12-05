#if 1
#if 1
#endif
namespace maxon
{
	namespace enum19 { enum class ERROR_OK
	{
		VALUE = 1			///< The single value of this enum.
		// = 1: workaround for MSVC bug, otherwise MSVC allows X* = OK for arbitrary X
	} ; }
	maxon::String PrivateToString_ERROR_OK19(std::underlying_type<enum19::ERROR_OK>::type x, const maxon::FormatStatement* fmt)
	{
		const maxon::UInt64 values[] = {(maxon::UInt64) enum19::ERROR_OK::VALUE};
		return maxon::StringInterface::PrivateEnumToString((maxon::UInt64) x, "ERROR_OK", SIZEOF(x), false, values, "VALUE\0", fmt);
	}
	namespace enum50 { enum class ERROR_FAILED
	{
		VALUE = 1,			///< The single value of this enum.
		// = 1: workaround for MSVC bug, otherwise MSVC allows X* = OK for arbitrary X
	} ; }
	maxon::String PrivateToString_ERROR_FAILED50(std::underlying_type<enum50::ERROR_FAILED>::type x, const maxon::FormatStatement* fmt)
	{
		const maxon::UInt64 values[] = {(maxon::UInt64) enum50::ERROR_FAILED::VALUE};
		return maxon::StringInterface::PrivateEnumToString((maxon::UInt64) x, "ERROR_FAILED", SIZEOF(x), false, values, "VALUE\0", fmt);
	}
#ifdef MAXON_TARGET_WINDOWS
#if defined MAXON_COMPILER_MSVC && MAXON_COMPILER_MSVC < 1910
#endif
#endif
#ifdef MAXON_TARGET_WINDOWS
#if defined MAXON_COMPILER_MSVC && MAXON_COMPILER_MSVC < 1910
#endif
#endif
	namespace enum446 { enum class ERROR_TYPE
	{
		OUT_OF_MEMORY,		///< Create an OutOfMemoryError.
		NULLPTR,					///< Create a NullptrError.
		ILLEGAL_ARGUMENT,	///< Create an IllegalArgumentError.
		ILLEGAL_STATE,		///< Create an IllegalStateError.
		NOT_IMPLEMENTED,	///< Create a FunctionNotImplementedError.
		UNRESOLVED,				///< Create an UnresolvedError.
		UNKNOWN						///< Create an UnknownError.
	} ; }
	maxon::String PrivateToString_ERROR_TYPE446(std::underlying_type<enum446::ERROR_TYPE>::type x, const maxon::FormatStatement* fmt)
	{
		const maxon::UInt64 values[] = {(maxon::UInt64) enum446::ERROR_TYPE::OUT_OF_MEMORY, (maxon::UInt64) enum446::ERROR_TYPE::NULLPTR, (maxon::UInt64) enum446::ERROR_TYPE::ILLEGAL_ARGUMENT, (maxon::UInt64) enum446::ERROR_TYPE::ILLEGAL_STATE, (maxon::UInt64) enum446::ERROR_TYPE::NOT_IMPLEMENTED, (maxon::UInt64) enum446::ERROR_TYPE::UNRESOLVED, (maxon::UInt64) enum446::ERROR_TYPE::UNKNOWN};
		return maxon::StringInterface::PrivateEnumToString((maxon::UInt64) x, "ERROR_TYPE", SIZEOF(x), false, values, "OUT_OF_MEMORY\0NULLPTR\0ILLEGAL_ARGUMENT\0ILLEGAL_STATE\0NOT_IMPLEMENTED\0UNRESOLVED\0UNKNOWN\0", fmt);
	}
#ifndef MAXON_COMPILER_MSVC
#ifdef MAXON_COMPILER_INTEL
#else
#if !defined(MAXON_COMPILER_GCC) || (MAXON_COMPILER_GCC >= 490)
#else
#endif
#endif
#else
#endif
#if defined(MAXON_COMPILER_INTEL)
#elif defined(MAXON_COMPILER_MSVC)
#else
#endif
#if defined(MAXON_COMPILER_GCC)
#endif
#ifdef MAXON_COMPILER_GCC
#endif
#ifndef MAXON_COMPILER_GCC
#else
#ifdef __CDT_PARSER__
#else
#endif
#endif
}
#endif
