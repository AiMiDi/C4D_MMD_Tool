#ifndef COMPILERDETECTION_H__
#define COMPILERDETECTION_H__


/// @file
/// Helper for Compiler specific definitions
/// @addtogroup SYSTEM
/// @{

#ifndef APIBASE_H__
	#error "Do not include this file directly"
#endif

// Target Detection, in case compiler settings are not properly adjusted
#if (__LP64__ || _WIN64) && !defined(MAXON_TARGET_64BIT)
	#define MAXON_TARGET_64BIT
#endif

#if (_WIN32 || _MSC_VER) && !defined(MAXON_TARGET_WINDOWS) && !defined MAXON_TARGET_ANDROID
	#define MAXON_TARGET_WINDOWS
#elif (__APPLE__)
	#include <TargetConditionals.h>
	#if defined(__has_feature)
		// TODO: (Seb) Add __has_feature for Ubsan. This does not exist yet.
		#if __has_feature(address_sanitizer) && !defined(MAXON_TARGET_SANITIZE)
			#define MAXON_TARGET_SANITIZE
		#endif
	#endif
	#if TARGET_OS_MAC && (TARGET_OS_IPHONE || TARGET_IPHONE_SIMULATOR) && !defined(MAXON_TARGET_IOS)
		#define MAXON_TARGET_IOS
	#elif TARGET_OS_MAC && !defined(MAXON_TARGET_MACOS) && !defined(MAXON_TARGET_IOS)
		#define MAXON_TARGET_MACOS
	#elif !defined(MAXON_TARGET_MACOS) && !defined(MAXON_TARGET_IOS)
		#error "Unsupported Target"
	#endif
	#if defined(MAXON_TARGET_MACOS) && !defined(MAXON_TARGET_OSX)
		#define MAXON_TARGET_OSX
	#endif
#elif defined(__GNUC__) && !defined(MAXON_TARGET_LINUX) && !defined MAXON_TARGET_ANDROID
	#define MAXON_TARGET_LINUX
#elif !defined(MAXON_TARGET_WINDOWS) && !defined(MAXON_TARGET_LINUX) && !defined MAXON_TARGET_ANDROID
	#error "Unsupported Target"
#endif

#if !defined(MAXON_TARGET_DEBUG) && !defined(MAXON_TARGET_RELEASE)
	#if !defined(NDEBUG) && (defined(_DEBUG) || (!defined(MAXON_TARGET_WINDOWS) && defined(DEBUG) && DEBUG == 1))
		#define MAXON_TARGET_DEBUG
	#else
		#define MAXON_TARGET_RELEASE
	#endif
#endif

#undef _HAS_STATIC_ASSERT

#if defined(__INTEL_COMPILER)
	#define MAXON_COMPILER_INTEL __INTEL_COMPILER
	#define _HAS_STATIC_ASSERT

	#define _HAS_NOEXCEPT

	//----------------------------------------------------------------------------------------
	/// Hints the compiler that a variable has a certain alignment.  Intel notes that a wrong hint might crash in their SSE code!
	//----------------------------------------------------------------------------------------
	#define MAXON_ASSUME_ALIGNED(val, alignment) DebugAssert((UInt(val) & ((alignment) - 1)) == 0); __assume_aligned(val, alignment)

	#ifdef MAXON_TARGET_LINUX
		#define override  // override specifier not yet supported by Intel compiler 13.0, use empty macro
	#endif

	#define _HAS_DEFAULT_TEMPLATE_FUNCTION_ARGUMENTS

	#define BUILTINEXPECTEDSUPPORTED

	#if MAXON_COMPILER_INTEL >= 1900 // Intel XE18 is completely unreliable, so try again with XE19...
		#define PRIVATE_MAXON_WARN_UNUSED_CLASS	[[nodiscard]]
		#define PRIVATE_MAXON_WARN_UNUSED [[nodiscard]]
		#define PRIVATE_MAXON_WARN_MUTE_UNUSED (void)
	#else
		#define PRIVATE_MAXON_WARN_UNUSED_CLASS
		#define PRIVATE_MAXON_WARN_UNUSED
		#define PRIVATE_MAXON_WARN_MUTE_UNUSED
	#endif

	#define MAXON_WARNING_PUSH														_Pragma("warning(push)")
	#define MAXON_WARNING_POP															_Pragma("warning(pop)")
	#define MAXON_WARNING_DISABLE_VARIABLE_SHADOWING			_Pragma("warning(disable : 1599)")
	#define MAXON_WARNING_DISABLE_UNUSED_VARIABLES				_Pragma("warning(disable : 177)")
	#define MAXON_WARNING_DISABLE_MISSING_PROTOTYPES
	#define MAXON_WARNING_DISABLE_DEPRECATED							_Pragma("warning(disable : 1478)") _Pragma("warning(disable : 1786)")
	#define MAXON_WARNING_DISABLE_REDUNDANT_MOVE
	#define MAXON_WARNING_DISABLE_UNUSED_LOCAL_TYPEDEF
	#define MAXON_WARNING_ENABLE_SWITCH_CHECKALLENUMS			// add compiler warning for unused case statement

	#define MAXON_WARNING(msg) __pragma(message(msg))

	/// Disables the undefined behaviour sanitizer for a certain reason.
	#define MAXON_UBSANITIZER_DISABLE(reason)

	#define _HAS_RANGE_BASED_FOR_DIFFERING_TYPES

#elif defined(__clang__)
	#define MAXON_COMPILER_CLANG ((__clang_major__ * 100) + (__clang_minor__ * 10) + __clang_patchlevel__)

	#if __has_feature(cxx_static_assert)
		#define _HAS_STATIC_ASSERT
	#endif
	#if __has_feature(cxx_default_function_template_args)
		#define _HAS_DEFAULT_TEMPLATE_FUNCTION_ARGUMENTS
	#endif
	#define _HAS_NOEXCEPT
	#define _HAS_REF_QUALIFIERS

	#define BUILTINEXPECTEDSUPPORTED

	#if __clang_major__ < 8
		#define MAXON_WORKAROUND_CLANG_DELETED_FUNCTION(X) { static_assert(maxon::AlwaysFalse<X>::value, "Invocation of deleted function."); }
	#endif

	//----------------------------------------------------------------------------------------
	/// Hints the compiler that a variable has a certain alignment.
	///
	/// Note that the implementation in GCC & Clang  slightly differs from ICC. Using the __builtin_assume_aligned() without
	/// the assignment to <val> would make GCC ignore the alignment hint - creating unoptimized code, while for ICC
	/// the __assume_aligned() macro is used without assignment just as a compiler hint. Intel notes that a wrong hint might
	/// crash in their SSE code though.
	/// __builtin_assume_aligned() allows the compiler to assume that the returned pointer is at least <alignment> bytes aligned.
	/// The compiler can use this knowledge to apply further optimizations to the pointed variable (e.g. using SSE, AVX, etc.)
	/// The passed argument must be of a type that can be assigned to itself, i.e. val = val must be a valid expression.
	//----------------------------------------------------------------------------------------
	#if __has_builtin(__builtin_assume_aligned)
		#define MAXON_ASSUME_ALIGNED(val, alignment) DebugAssert((UInt(val) & ((alignment) - 1)) == 0); val = (decltype(val))__builtin_assume_aligned(val, alignment)
	#elif __has_builtin(__builtin_unreachable)
		// Xcode 6.2 (for OS X 10.9.5) does not support __builtin_assume_aligned.
		#define MAXON_ASSUME_ALIGNED(val, alignment) DebugAssert((UInt(val) & ((alignment) - 1)) == 0); val = (decltype(val))(((uintptr_t(val) % (alignment)) == 0) ? (val) : (__builtin_unreachable(), (val)))
	#endif

	#define MAXON_ASSERT_STANDARD_LAYOUT(X) static_assert(std::is_standard_layout<X>::value, #X " must be a standard-layout class!")
	#define MAXON_ASSERT_LEGAL_LAYOUT(X) static_assert(!std::is_polymorphic<X>::value, #X " must not contain virtual members!")

	// Clang correctly warns about "Offset of on non-standard-layout type". If you nevertheless need offsetof, use the macro MAXON_OFFSETOF_NON_STANDARD_LAYOUT instead, but make sure that its usage is safe.
	#define MAXON_OFFSETOF_NON_STANDARD_LAYOUT(T, M) ((size_t)(&((T*) 0)->M))
	#define _HAS_DEFAULTED_FUNCTIONS

	#define PRIVATE_MAXON_WARN_UNUSED_CLASS [[gnu::warn_unused_result]]
	#define PRIVATE_MAXON_WARN_UNUSED [[gnu::warn_unused_result]]

	#define PRIVATE_MAXON_WARN_MUTE_UNUSED (void)

	#define MAXON_WARNING_PUSH														_Pragma("clang diagnostic push")
	#define MAXON_WARNING_POP															_Pragma("clang diagnostic pop")
	#define MAXON_WARNING_DISABLE_VARIABLE_SHADOWING			_Pragma("clang diagnostic ignored \"-Wshadow\"")
	#define MAXON_WARNING_DISABLE_UNUSED_VARIABLES				_Pragma("clang diagnostic ignored \"-Wunused-variable\"")
	#define MAXON_WARNING_DISABLE_MISSING_PROTOTYPES			_Pragma("clang diagnostic ignored \"-Wmissing-prototypes\"")
	#define MAXON_WARNING_DISABLE_DEPRECATED							_Pragma("clang diagnostic ignored \"-Wdeprecated-declarations\"")
	#ifdef MAXON_TARGET_WINDOWS
		#define MAXON_WARNING_DISABLE_REDUNDANT_MOVE				_Pragma("clang diagnostic ignored \"-Wredundant-move\"")
		#define MAXON_WARNING_DISABLE_UNUSED_LOCAL_TYPEDEF	_Pragma("clang diagnostic ignored \"-Wunused-local-typedef\"")
	#else
		#define MAXON_WARNING_DISABLE_REDUNDANT_MOVE
		#define MAXON_WARNING_DISABLE_UNUSED_LOCAL_TYPEDEF
	#endif
	#define MAXON_WARNING_ENABLE_SWITCH_CHECKALLENUMS			_Pragma("clang diagnostic error \"-Wswitch-enum\"")

	#define PRIVATE_MAXON_WARNING(msg) _Pragma(MAXON_STRINGIFY(msg))
	#define MAXON_WARNING(msg) PRIVATE_MAXON_WARNING(GCC warning msg)

	/// Disables the undefined behaviour sanitizer for a certain reason.
	#define MAXON_UBSANITIZER_DISABLE(reason)	__attribute__((no_sanitize("undefined")))

	#define _HAS_RANGE_BASED_FOR_DIFFERING_TYPES

#elif (defined MAXON_TARGET_WINDOWS)
	#define MAXON_COMPILER_MSVC _MSC_VER

	#define _HAS_STATIC_ASSERT
	#pragma warning(disable:4344)	// disable warning: A call to a function using explicit template arguments calls a different function than it would if explicit arguments had not been specified

	#define _HAS_NOEXCEPT
	#define _HAS_DEFAULT_TEMPLATE_FUNCTION_ARGUMENTS
	#pragma warning(disable:5025) // cannot be added to MSVCBase.props as long as we haven't completely switched to MSVC 2015 as MSVC 2013 does not like it
	#pragma warning(disable:5026)
	#pragma warning(disable:5027)
	#pragma warning(disable:4456) // declaration of xxx hides previous local declaration - temporarily disabled because of iferr
	#pragma warning(disable:4512)	// disable false warning 'assignment operator could not be generated'
	#pragma warning(error:4263) // member function does not override any base class virtual member function
	#pragma warning(error:4264) // no override available for virtual member function from base 'class'; function is hidden

	// due to an internal crash this needs to be used instead of offsetof
	#define MAXON_OFFSETOF_NON_STANDARD_LAYOUT(T, M) ((size_t)(&((T*) 0)->M))

	#undef BUILTINEXPECTEDSUPPORTED

	// There is no __assume_aligned support in MSVC

	#if MAXON_COMPILER_MSVC >= 1910
		#define PRIVATE_MAXON_WARN_UNUSED_CLASS	[[nodiscard]]
		#define PRIVATE_MAXON_WARN_UNUSED [[nodiscard]]
		#define PRIVATE_MAXON_WARN_MUTE_UNUSED (void)
	#else
		#define PRIVATE_MAXON_WARN_UNUSED_CLASS	// msvc doesn't support "class [[gnu::warn_unused_result]] ClassName"
		#define PRIVATE_MAXON_WARN_UNUSED
		#define PRIVATE_MAXON_WARN_MUTE_UNUSED
	#endif

	#define MAXON_WARNING_PUSH													__pragma(warning(push))
	#define MAXON_WARNING_POP														__pragma(warning(pop))
	#define MAXON_WARNING_DISABLE_VARIABLE_SHADOWING		__pragma(warning(disable : 4457))
	#define MAXON_WARNING_DISABLE_UNUSED_VARIABLES			__pragma(warning(disable : 4101))
	#define MAXON_WARNING_DISABLE_MISSING_PROTOTYPES
	#define MAXON_WARNING_DISABLE_DEPRECATED						__pragma(warning(disable : 4996))
	#define MAXON_WARNING_DISABLE_REDUNDANT_MOVE
	#define MAXON_WARNING_DISABLE_UNUSED_LOCAL_TYPEDEF
	#define MAXON_WARNING_ENABLE_SWITCH_CHECKALLENUMS		__pragma(warning(error:4061)) __pragma(warning(error:4062))

	#define MAXON_WARNING(msg) __pragma(message(msg))

	/// Disables the undefined behaviour sanitizer for a certain reason.
	#define MAXON_UBSANITIZER_DISABLE(reason)

	#define _HAS_RANGE_BASED_FOR_DIFFERING_TYPES

#elif defined(__GNUC__) && !defined(MAXON_COMPILER_CLANG)
	#define MAXON_COMPILER_GCC ((__GNUC__ * 100) + (__GNUC_MINOR__ * 10) + __GNUC_PATCHLEVEL__)

	#if (MAXON_COMPILER_GCC <= 470)
		#define override // GCC doesn't support override yet
	#endif
	#if (MAXON_COMPILER_GCC >= 460)
		// GCC >= 4.6 case (will be relevant for Linux)
		#define _HAS_DEFAULT_TEMPLATE_FUNCTION_ARGUMENTS
		#define _HAS_STATIC_ASSERT
		#define _HAS_NOEXCEPT
	#endif
	#if (MAXON_COMPILER_GCC < 480)
		#define alignas(_a_)	__attribute__((aligned(_a_)))
	#endif
	#if (MAXON_COMPILER_GCC < 490)
		#define MAXON_COMPILER_BUG_CONST_TYPE_ALIAS
	#endif

	#if (MAXON_COMPILER_GCC >= 470)
		#define MAXON_ASSUME_ALIGNED(val, alignment) DebugAssert((UInt(val) & ((alignment) - 1)) == 0); val = (decltype(val))__builtin_assume_aligned(val, alignment)
	#endif

	#define BUILTINEXPECTEDSUPPORTED

	#define MAXON_ASSERT_STANDARD_LAYOUT(X) static_assert(std::is_standard_layout<X>::value, #X " must be a standard-layout class!")
	#define MAXON_ASSERT_LEGAL_LAYOUT(X) static_assert(!std::is_polymorphic<X>::value, #X " must not contain virtual members!")

	#define _HAS_REF_QUALIFIERS

	#define PRIVATE_MAXON_WARN_UNUSED_CLASS	// gcc doesn't support "class [[gnu::warn_unused_result]] ClassName"
	#define PRIVATE_MAXON_WARN_UNUSED [[gnu::warn_unused_result]]

	#define PRIVATE_MAXON_WARN_MUTE_UNUSED (maxon::PrivateMuteUnusedHelper)

	#define MAXON_WARNING_PUSH														_Pragma("GCC diagnostic push")
	#define MAXON_WARNING_POP															_Pragma("GCC diagnostic pop")
	#define MAXON_WARNING_DISABLE_VARIABLE_SHADOWING			_Pragma("GCC diagnostic ignored \"-Wshadow\"")	// requires at least gcc 4.9.0 to work correctly
	#define MAXON_WARNING_DISABLE_UNUSED_VARIABLES				_Pragma("GCC diagnostic ignored \"-Wunused-variable\"")
	#define MAXON_WARNING_DISABLE_MISSING_PROTOTYPES			_Pragma("GCC diagnostic ignored \"-Wmissing-prototypes\"")
	#define MAXON_WARNING_DISABLE_DEPRECATED							_Pragma("GCC diagnostic ignored \"-Wdeprecated-declarations\"")
	#define MAXON_WARNING_DISABLE_REDUNDANT_MOVE
	#define MAXON_WARNING_DISABLE_UNUSED_LOCAL_TYPEDEF		_Pragma("GCC diagnostic ignored \"-Wunused-local-typedefs\"")
	#define MAXON_WARNING_ENABLE_SWITCH_CHECKALLENUMS			// add compiler warning for unused case statement

	#define PRIVATE_MAXON_WARNING(msg) _Pragma(MAXON_STRINGIFY(msg))
	#define MAXON_WARNING(msg) PRIVATE_MAXON_WARNING(GCC warning msg)

	/// Disables the undefined behaviour sanitizer for a certain reason.
	#define MAXON_UBSANITIZER_DISABLE(reason)

#else
	#error Unsupported Compiler
#endif

/// This macro is used to create a compile error under XCode and GCC if a function's return value is not examined.
/// It should always be used in combination with the Result<> error handling, but is not limited to it.
/// Write this macro at the beginning of your function declaration - before 'static' and the Result<T> return value.
/// MAXON_WARN_UNUSED does not need to be written in declarations of virtual or non-virtual interfaces
/// when the keyword MAXON_METHOD was used.
/// Here an example:
/// @code
/// template <typename T> static Result<void> Function(T val)
/// {
///   ...
/// }
/// @endcode
#define MAXON_WARN_UNUSED PRIVATE_MAXON_WARN_UNUSED
#define MAXON_WARN_UNUSED_CLASS PRIVATE_MAXON_WARN_UNUSED_CLASS

/// The MAXON_WARN_MUTE_UNUSED macro is deprecated. Please use iferr_ignore or iferr_cannot_fail and specify the reason why error handling isn't necessary.
#define MAXON_WARN_MUTE_UNUSED PRIVATE_MAXON_WARN_MUTE_UNUSED

#ifdef MAXON_TARGET_WINDOWS
	#define MAXON_TARGET_CPU_INTEL
	#ifdef MAXON_TARGET_64BIT
		#define MAXON_TARGET_ABI_WIN_X64
	#else
		#define MAXON_TARGET_ABI_WIN_X86
	#endif
#elif defined(MAXON_TARGET_MACOS) || defined(MAXON_TARGET_LINUX) || defined(MAXON_TARGET_IOS) || defined(MAXON_TARGET_ANDROID)
	#if defined(__i386__) || defined(__x86_64__)
		#define MAXON_TARGET_CPU_INTEL
		#ifdef MAXON_TARGET_64BIT
			#define MAXON_TARGET_ABI_SYSTEMV_AMD64
		#endif
	#elif defined(__ppc__) || defined(__ppc64__)
		#define MAXON_TARGET_CPU_PPC
	#else
		#define MAXON_TARGET_CPU_ARM
	#endif
#endif

#if defined(MAXON_COMPILER_INTEL) || defined(MAXON_COMPILER_GCC) || defined(MAXON_COMPILER_CLANG)
	#define MAXON_ASSEMBLY_GCC
#endif

#define PRIVATE_MAXON_DEFAULT_CTOR = default

#ifndef MAXON_OFFSETOF_NON_STANDARD_LAYOUT
	#define MAXON_OFFSETOF_NON_STANDARD_LAYOUT offsetof
#endif

#ifndef PRIVATE_MAXON_ALLOC_TYPENAME
	#define PRIVATE_MAXON_ALLOC_TYPENAME typename
#endif

#ifndef PRIVATE_MAXON_TEMPLATE_PREFIX
	#define PRIVATE_MAXON_TEMPLATE_PREFIX template
#endif

#ifndef MAXON_WORKAROUND_CLANG_DELETED_FUNCTION
	#define MAXON_WORKAROUND_CLANG_DELETED_FUNCTION(X) = delete
#endif

// To be removed once all compilers are C++11 compliant.
#ifdef _HAS_DEFAULTED_FUNCTIONS
	#define PRIVATE_MAXON_PTR_COPY_CONSTRUCTOR = default;
	#define PRIVATE_MAXON_PTR_COPY_ASSIGNMENT = default;
#else
	#define PRIVATE_MAXON_PTR_COPY_CONSTRUCTOR { this->SetPointer(const_cast<ReferencedType*>(value.GetPointer())); }
	#define PRIVATE_MAXON_PTR_COPY_ASSIGNMENT { this->SetPointer(const_cast<ReferencedType*>(value.GetPointer())); return *this; }
#endif

#ifndef _HAS_STATIC_ASSERT
	#define static_assert(cond, str)													// dummy for old compiler
#endif

#ifndef _HAS_NOEXCEPT
	#define noexcept throw()																	// compiler doesn't know noexcept yet
#endif

#include <utility>																					// std::move defined here
#include <type_traits>

#if (defined(MAXON_COMPILER_GCC) && (MAXON_COMPILER_GCC < 500))
	namespace std
	{
	template <typename T> struct is_trivially_copyable : public std::is_pod<T> {};
	}
#endif

#ifndef MAXON_ASSERT_STANDARD_LAYOUT
	// MSVC & Intel bug or clang with old libstdc++
	#define MAXON_ASSERT_STANDARD_LAYOUT(T)
	#define MAXON_ASSERT_LEGAL_LAYOUT(T)
#endif

#if defined(MAXON_TARGET_ABI_WIN_X64) || defined(MAXON_TARGET_ABI_SYSTEMV_AMD64)
	#define PRIVATE_MAXON_ASSEMBLE_UNRESOLVED
#endif

//----------------------------------------------------------------------------------------
/// This macro enables a error or warning if a switch statement wont implement an enumeration.
/// usage:
/// @code
/// enum class X { A, B };
/// MAXON_SWITCH_CHECKALLENUMS_BEGIN;
/// switch (enumvar)
/// {
///		case A:
/// }
/// MAXON_SWITCH_CHECKALLENUMS_END;
/// @endcode
/// The compiler will print "error C4062: enumerator 'maxon::X::B' in switch of enum 'maxon::X' is not handled"
//----------------------------------------------------------------------------------------
#define MAXON_SWITCH_CHECKALLENUMS_BEGIN							MAXON_WARNING_PUSH MAXON_WARNING_ENABLE_SWITCH_CHECKALLENUMS
#define MAXON_SWITCH_CHECKALLENUMS_END								MAXON_WARNING_POP

/// @private
namespace std
{
// replace the following by std::aligned_union when this is supported by all platforms
template <size_t size, typename T1> struct aligned_union1 : public aligned_storage<MAXON_MAX_MACRO(size, sizeof(T1)), alignof(T1)>
{
};

template <size_t size, typename T1, typename T2> struct aligned_union2 : public aligned_storage<MAXON_MAX_MACRO(size, MAXON_MAX_MACRO(sizeof(T1), sizeof(T2))), MAXON_MAX_MACRO(alignof(T1), alignof(T2))>
{
};

template <size_t size, typename T1, typename T2, typename T3> struct aligned_union3 : public aligned_storage<MAXON_MAX_MACRO(size, MAXON_MAX_MACRO(sizeof(T1), MAXON_MAX_MACRO(sizeof(T2), sizeof(T3)))), MAXON_MAX_MACRO(alignof(T1), MAXON_MAX_MACRO(alignof(T2), alignof(T3)))>
{
};

template <size_t size, typename T1, typename T2, typename T3, typename T4> struct aligned_union4 : public aligned_storage<MAXON_MAX_MACRO(size, MAXON_MAX_MACRO(sizeof(T1), MAXON_MAX_MACRO(sizeof(T2), MAXON_MAX_MACRO(sizeof(T3), sizeof(T4))))), MAXON_MAX_MACRO(alignof(T1), MAXON_MAX_MACRO(alignof(T2), MAXON_MAX_MACRO(alignof(T3), alignof(T4))))>
{
};

}

#ifndef MAXON_ASSUME_ALIGNED
	#define MAXON_ASSUME_ALIGNED(val, alignment) DebugAssert((UInt(val) & ((alignment) - 1)) == 0); // Do basic check for compilers that don't implement it and warn if the memory allocator's alignment doesn't fit
#endif

#ifdef BUILTINEXPECTEDSUPPORTED
	//----------------------------------------------------------------------------------------
	/// Tells the compiler which way to choose for branch prediction.
	///
	/// For example if you are checking for an index range in time critical routines and only in the unlikely case of the index being out of scope you want the compiler to handle this specifically
	/// @code
	/// Bool CheckASCIIRange(Int index)
	/// {
	///   if (MAXON_LIKELY(index > 31 && index < 127)) return true;
	///
	/// 	return false;
	/// }
	/// @endcode
	/// @param[in] X									Condition to check.
	//----------------------------------------------------------------------------------------
	#define MAXON_LIKELY(X) __builtin_expect((bool)(X), true)

	//----------------------------------------------------------------------------------------
	/// Tells the compiler which way to choose for branch prediction.
	///
	/// For example if you are running a time critical loop and only in the unlikely case of a rare event you want the compiler to handle this specifically
	/// @code
	/// void CheckArray(BaseArray<Char>& array)
	/// {
	/// 	for (Char& c : array)
	/// 	{
	/// 		if (MAXON_UNLIKELY(!c))
	/// 			c = '_';
	/// 	}
	/// }
	/// @endcode
	/// @param[in] X									Condition to check.
	//----------------------------------------------------------------------------------------
	#define MAXON_UNLIKELY(X) __builtin_expect((bool)(X), false)
#else
	#define MAXON_LIKELY(X) (X)
	#define MAXON_UNLIKELY(X) (X)
#endif


#if defined MAXON_COMPILER_CLANG && defined MAXON_TARGET_WINDOWS
	/// @private
	#define cdecl
#endif

#if (defined MAXON_COMPILER_CLANG && (defined(MAXON_TARGET_WINDOWS) || (__apple_build_version__ >= 7000000))) || (defined MAXON_COMPILER_MSVC && MAXON_COMPILER_MSVC >= 1910)
	class PlacementNewHelper {};
	inline void* operator new(size_t size, PlacementNewHelper x, void *ptr) noexcept { return ptr; }
	// Placement new needs a matching deletion function, otherwise warning C4291 is triggered.
	inline void operator delete(void*, PlacementNewHelper x, void* ptr) noexcept { }
	//----------------------------------------------------------------------------------------
	/// Clang 3.7 introduced a new optimization where a placement new wont check the given ptr for nullptr.
	/// for places where the pointer is already checked outside this is a great optimization.
	/// but places that allocate memory and pass this without a check to the placement new would crash the app.
	/// example:
	/// @code
	/// return MAXON_SAFE_PLACEMENT_NEW(NewMem(Int, 1)) Int(5);
	/// @endcode
	/// http://www.open-std.org/jtc1/sc22/wg21/docs/cwg_defects.html#1748
	/// http://llvm.org/viewvc/llvm-project?view=revision&revision=229213
	//----------------------------------------------------------------------------------------
	#define MAXON_SAFE_PLACEMENT_NEW(PTR)		new (PlacementNewHelper(), PTR)
#else
	//----------------------------------------------------------------------------------------
	/// Clang 3.7 introduced a new optimization where a placement new wont check the given ptr for nullptr.
	/// for places where the pointer is already checked outside this is a great optimization.
	/// but places that allocate memory and pass this without a check to the placement new would crash the app.
	/// example:
	/// @code
	/// return MAXON_SAFE_PLACEMENT_NEW(NewMem(Int, 1)) Int(5);
	/// @endcode
	/// http://www.open-std.org/jtc1/sc22/wg21/docs/cwg_defects.html#1748
	/// http://llvm.org/viewvc/llvm-project?view=revision&revision=229213
	//----------------------------------------------------------------------------------------
	#define MAXON_SAFE_PLACEMENT_NEW(PTR)		new (PTR)
#endif

/// @}

// Suppressing false positives for PVS-Studio located within macro statements. These warnings can be ignored:
// http://www.viva64.com/en/d/0110/
// http://www.viva64.com/en/d/0319/
//-V:iferr:685, 521
//-V:ifnoerr:685, 521

#endif // COMPILERDETECTION_H__
