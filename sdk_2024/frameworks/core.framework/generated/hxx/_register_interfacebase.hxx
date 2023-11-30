#if 1
namespace maxon
{
/// @cond INTERNAL

#ifndef MAXON_COMPILER_CLANG
#endif
	namespace enum56
	{
		enum class UNRESOLVED_RETURN_TYPE : UChar
		{
			VOID_ZERO,									///< void return type.
			VOID_ZERO_FREE_FUNCTION,		///< special case for a Free function.
			INTEGRAL_ZERO,							///< integral/enum/pointer type
			INTEGRAL2X_ZERO,						///< two Int-sized integral/enum/pointer types
			FLOAT_ZERO,									///< Float32
			DOUBLE_ZERO,								///< Float64
			STACK_ZERO,									///< an Int-sized type returned via stack
			POINTER_TO_ZERO,						///< a pointer which shall point to zero bytes (e.g. const Something&)
			RESULT_VOID,								///< Result<void>
			RESULT_INTEGRAL_ZERO,				///< Result<integral/enum/pointer type>
			RESULT_STACK_ZERO,					///< Result<T> where T is STACK_ZERO
			OTHER,											///< Any other type (JIT assembly unsupported).
		
			MEMBER_FUNCTION_FLAG = 128,	///< The function is a member function (it has a "this" parameter).
			TYPE_MASK = 127,						///< Mask to mask out the MEMBER_FUNCTION flag.
		} ;
		static const maxon::UInt64 UNRESOLVED_RETURN_TYPE_values[] = {maxon::UInt64(enum56::UNRESOLVED_RETURN_TYPE::VOID_ZERO), maxon::UInt64(enum56::UNRESOLVED_RETURN_TYPE::VOID_ZERO_FREE_FUNCTION), maxon::UInt64(enum56::UNRESOLVED_RETURN_TYPE::INTEGRAL_ZERO), maxon::UInt64(enum56::UNRESOLVED_RETURN_TYPE::INTEGRAL2X_ZERO), maxon::UInt64(enum56::UNRESOLVED_RETURN_TYPE::FLOAT_ZERO), maxon::UInt64(enum56::UNRESOLVED_RETURN_TYPE::DOUBLE_ZERO), maxon::UInt64(enum56::UNRESOLVED_RETURN_TYPE::STACK_ZERO), maxon::UInt64(enum56::UNRESOLVED_RETURN_TYPE::POINTER_TO_ZERO), maxon::UInt64(enum56::UNRESOLVED_RETURN_TYPE::RESULT_VOID), maxon::UInt64(enum56::UNRESOLVED_RETURN_TYPE::RESULT_INTEGRAL_ZERO), maxon::UInt64(enum56::UNRESOLVED_RETURN_TYPE::RESULT_STACK_ZERO), maxon::UInt64(enum56::UNRESOLVED_RETURN_TYPE::OTHER), maxon::UInt64(enum56::UNRESOLVED_RETURN_TYPE::MEMBER_FUNCTION_FLAG), maxon::UInt64(enum56::UNRESOLVED_RETURN_TYPE::TYPE_MASK)};
		static const maxon::EnumInfo UNRESOLVED_RETURN_TYPE_info{"UNRESOLVED_RETURN_TYPE", SIZEOF(UNRESOLVED_RETURN_TYPE), true, "VOID_ZERO\0VOID_ZERO_FREE_FUNCTION\0INTEGRAL_ZERO\0INTEGRAL2X_ZERO\0FLOAT_ZERO\0DOUBLE_ZERO\0STACK_ZERO\0POINTER_TO_ZERO\0RESULT_VOID\0RESULT_INTEGRAL_ZERO\0RESULT_STACK_ZERO\0OTHER\0MEMBER_FUNCTION_FLAG\0TYPE_MASK\0", UNRESOLVED_RETURN_TYPE_values, std::extent<decltype(UNRESOLVED_RETURN_TYPE_values)>::value};
	}
	const maxon::EnumInfo& PrivateGetEnumInfo_UNRESOLVED_RETURN_TYPE56(){ return enum56::UNRESOLVED_RETURN_TYPE_info; }
#ifndef _HAS_CPP20_COMPARISONS
#endif
#ifndef _HAS_CPP20_COMPARISONS
#endif
#ifndef _HAS_CPP20_COMPARISONS
#endif
#ifdef _HAS_CPP20_COMPARISONS
#endif
#ifndef MAXON_COMPILER_MSVC
#else
#endif
#ifndef MAXON_COMPILER_MSVC
#endif
#ifndef MAXON_COMPILER_MSVC
#endif
/// @endcond

#ifndef MAXON_TARGET_LINUX
#ifdef MAXON_TARGET_DEBUG
#else
#endif
#else
#endif
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

#ifndef PRIVATE_MAXON_MTABLE_PTMF
#ifdef MAXON_TARGET_ABI_SYSTEMV_AMD64
#elif defined(MAXON_TARGET_ABI_AARCH64)
#else
#endif
#else
#endif
/// @endcond

}
#endif
