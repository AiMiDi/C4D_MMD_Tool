#if 1
#ifndef APIBASE_H__
#endif
namespace maxon
{
	namespace enum19
	{
		enum class ERROR_OK
		{
			VALUE = 1			///< The single value of this enum.
			// = 1: workaround for MSVC bug, otherwise MSVC allows X* = OK for arbitrary X
		} ;
		static const maxon::UInt64 ERROR_OK_values[] = {maxon::UInt64(enum19::ERROR_OK::VALUE)};
		static const maxon::EnumInfo ERROR_OK_info{"ERROR_OK", SIZEOF(ERROR_OK), false, "VALUE\0", ERROR_OK_values, std::extent<decltype(ERROR_OK_values)>::value};
	}
	const maxon::EnumInfo& PrivateGetEnumInfo_ERROR_OK19(){ return enum19::ERROR_OK_info; }
	namespace enum50
	{
		enum class ERROR_FAILED
		{
			VALUE = 1,			///< The single value of this enum.
			// = 1: workaround for MSVC bug, otherwise MSVC allows X* = OK for arbitrary X
		} ;
		static const maxon::UInt64 ERROR_FAILED_values[] = {maxon::UInt64(enum50::ERROR_FAILED::VALUE)};
		static const maxon::EnumInfo ERROR_FAILED_info{"ERROR_FAILED", SIZEOF(ERROR_FAILED), false, "VALUE\0", ERROR_FAILED_values, std::extent<decltype(ERROR_FAILED_values)>::value};
	}
	const maxon::EnumInfo& PrivateGetEnumInfo_ERROR_FAILED50(){ return enum50::ERROR_FAILED_info; }
	namespace details
	{
#ifdef _HAS_RANGE_BASED_FOR_DIFFERING_TYPES
#else
#endif
	}
	namespace enum435
	{
		enum class ERROR_TYPE
		{
			OUT_OF_MEMORY,		///< Create an OutOfMemoryError.
			NULLPTR,					///< Create a NullptrError.
			ILLEGAL_ARGUMENT,	///< Create an IllegalArgumentError.
			ILLEGAL_STATE,		///< Create an IllegalStateError.
			NOT_IMPLEMENTED,	///< Create a FunctionNotImplementedError.
			UNRESOLVED,				///< Create an UnresolvedError.
			UNKNOWN						///< Create an UnknownError.
		} ;
		static const maxon::UInt64 ERROR_TYPE_values[] = {maxon::UInt64(enum435::ERROR_TYPE::OUT_OF_MEMORY), maxon::UInt64(enum435::ERROR_TYPE::NULLPTR), maxon::UInt64(enum435::ERROR_TYPE::ILLEGAL_ARGUMENT), maxon::UInt64(enum435::ERROR_TYPE::ILLEGAL_STATE), maxon::UInt64(enum435::ERROR_TYPE::NOT_IMPLEMENTED), maxon::UInt64(enum435::ERROR_TYPE::UNRESOLVED), maxon::UInt64(enum435::ERROR_TYPE::UNKNOWN)};
		static const maxon::EnumInfo ERROR_TYPE_info{"ERROR_TYPE", SIZEOF(ERROR_TYPE), false, "OUT_OF_MEMORY\0NULLPTR\0ILLEGAL_ARGUMENT\0ILLEGAL_STATE\0NOT_IMPLEMENTED\0UNRESOLVED\0UNKNOWN\0", ERROR_TYPE_values, std::extent<decltype(ERROR_TYPE_values)>::value};
	}
	const maxon::EnumInfo& PrivateGetEnumInfo_ERROR_TYPE435(){ return enum435::ERROR_TYPE_info; }
#ifdef MAXON_COMPILER_MSVC
#elif (defined MAXON_COMPILER_INTEL)
#else
#if !defined(MAXON_COMPILER_GCC) || (MAXON_COMPILER_GCC >= 490)
#else
#endif
#endif
#if defined(MAXON_COMPILER_INTEL)
#else
#endif
#if defined(MAXON_COMPILER_GCC)
#endif
#if defined(MAXON_COMPILER_MSVC) || defined(MAXON_COMPILER_INTEL)
#else
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
