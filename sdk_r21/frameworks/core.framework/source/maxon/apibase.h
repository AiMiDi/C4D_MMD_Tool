#include "maxon/utilities/detect_win_macros.h"

#ifndef APIBASE_H__
#define APIBASE_H__

/// @file
/// Main include file


//----------------------------------------------------------------------------------------
/// The ABI version (Application Binary Interface) of the MAXON API. Only modules compiled
/// with the same ABI version are binary-compatible and can be loaded together.
//----------------------------------------------------------------------------------------
#define MAXON_API_ABI_VERSION 21014

#undef _HAS_EXCEPTIONS
#define _HAS_EXCEPTIONS 0

#ifndef DOXYGEN
	#define DOXYGEN_SWITCH(CPP, DOX) CPP
#endif

#include <stddef.h>
#include <string.h>
#include <math.h>
#include <new>
#include <wchar.h>
#include <inttypes.h>

// can be replaced by a constexpr function invocation once this is supported by all compilers
#define MAXON_MAX_MACRO(a, b) ((a) > (b) ? (a) : (b))

#ifndef MAXON_API
//----------------------------------------------------------------------------------------
/// If this macro is undefined while including header files, no automatic dependencies will be set up
/// for the entities declared in the included header files. This should be used with caution.
/// If this mechanism is used, a <tt>\#undef</tt>-<tt>\#define</tt>-pair should surround the includes which shall
/// be ignored for the dependency analysis as in
/// @code
/// #undef MAXON_DEPENDENCY_ENABLE
/// #include "myheader.h" // there won't be any automatic dependencies of the current source file on the entities declared in myheader.h
/// #define MAXON_DEPENDENCY_ENABLE
/// @endcode
/// This pattern should only be used in cpp files, but not in header files.
//----------------------------------------------------------------------------------------
#define MAXON_DEPENDENCY_ENABLE
#endif

#define MAXON_DEPENDENCY_ENABLEtrue false


//----------------------------------------------------------------------------------------
/// Use MAXON_PREPROCESSOR_CONDITION(X) in a header file to tell the source processor that the corresponding includes
/// in register.cpp shall be enclosed by \#if X ... \#endif. You have to use this for system specific header files. Example:
/// @code
/// MAXON_PREPROCESSOR_CONDITION(defined(MAXON_TARGET_IOS) || defined(MAXON_TARGET_MACOS));
/// @endcode
//----------------------------------------------------------------------------------------
#define MAXON_PREPROCESSOR_CONDITION(X)


#include "maxon/utilities/compilerdetection.h"

//----------------------------------------------------------------------------------------
/// The maxon namespace contains all declarations of the MAXON API.
//----------------------------------------------------------------------------------------
namespace maxon
{

/// @defgroup DATATYPE Data Types
/// @{
/// @}
/// @defgroup STRUCTURES Data Structures
/// @{
/// @}
/// @defgroup MATH Math Library
/// @{
/// @}

/// @addtogroup DATATYPE
/// @{

/// Use MAXON_ATTRIBUTE_DLL_PUBLIC in the declaration of a variable or function to export symbols (project settings make them private by default), e.g.
/// MAXON_ATTRIBUTE_DLL_PUBLIC int variable;
/// extern "C" MAXON_ATTRIBUTE_DLL_PUBLIC void function();
#ifdef MAXON_TARGET_WINDOWS
	#define	MAXON_ATTRIBUTE_DLL_PUBLIC			__declspec(dllexport)
#else
	#define	MAXON_ATTRIBUTE_DLL_PUBLIC			__attribute__((visibility("default")))
#endif

/// Use MAXON_ATTRIBUTE_NO_INLINE to prevent the compiler from inlining a method, e.g.
/// static MAXON_ATTRIBUTE_NO_INLINE void FreeContainer(Container& c);
#ifdef MAXON_TARGET_WINDOWS
	#define	MAXON_ATTRIBUTE_NO_INLINE				__declspec(noinline)
#else
	#define	MAXON_ATTRIBUTE_NO_INLINE				__attribute__((noinline))
#endif

/// Use MAXON_ATTRIBUTE_FORCE_INLINE to force the compiler to explicitly inline a method, e.g.
/// MAXON_ATTRIBUTE_FORCE_INLINE Float32 Clamp01(Float32 a)
#ifdef MAXON_TARGET_WINDOWS
	#define MAXON_ATTRIBUTE_FORCE_INLINE		__forceinline
#else
	#define MAXON_ATTRIBUTE_FORCE_INLINE		inline __attribute__((always_inline))
#endif

/// use MAXON_ATTRIBUTE_USED to tell the linker it must not dead-strip a function or static variable (even if it determines that the rest of the program does not refer to the object)
#ifdef MAXON_TARGET_WINDOWS
	#define	MAXON_ATTRIBUTE_USED
#else
	#define	MAXON_ATTRIBUTE_USED						__attribute__((used))
#endif

#if defined(MAXON_COMPILER_MSVC)
	#define PRIVATE_MAXON_DEPRECATED_ENUMVALUE(name, value, reason) name = value __pragma(deprecated(name))
#elif defined(MAXON_COMPILER_CLANG) || defined(MAXON_COMPILER_GCC)
	#define PRIVATE_MAXON_DEPRECATED_ENUMVALUE(name, value, reason) name __attribute__((deprecated(reason))) = value
#else
	#define PRIVATE_MAXON_DEPRECATED_ENUMVALUE(name, value, reason) name = value
#endif

//----------------------------------------------------------------------------------------
/// Use MAXON_DEPRECATED_ENUMVALUE to mark an enum value being deprecated. This macro is processed by MSVC, Clang, GCC and Doxygen.
/// @note Don't use a comma after the macro!
///
/// Example:
/// @code
/// enum class COLORS
/// {
/// 	RED,
/// 	GREEN,
/// 	BLUE,
///
/// 	MAXON_DEPRECATED_ENUMVALUE(BROWN, 100, "Color for brown objects. Use red from now on")
/// 	MAXON_DEPRECATED_ENUMVALUE(YELLOW, 200, "Color for yellow objects. Use blue from now on")
/// };
/// @endcode
//----------------------------------------------------------------------------------------
#define MAXON_DEPRECATED_ENUMVALUE(name, value, reason) PRIVATE_MAXON_DEPRECATED_ENUMVALUE(name, value, reason)

#if (__LP64__ || _WIN64) && !defined(__64BIT)
	#define __64BIT
#endif
#if (__LP64__ || _WIN64) && !defined(MAXON_TARGET_64BIT)
	#define MAXON_TARGET_64BIT
#endif

//----------------------------------------------------------------------------------------
/// Use MAXON_IMPLICIT to mark a constructor which may be used for implicit conversions.
/// Example:
/// @code
/// class MyClass
/// {
/// public:
/// 	MAXON_IMPLICIT MyClass(Int x);
/// 	explicit MyClass(const Char* x);
/// };
///
/// void Func(const MyClass& x);
///
/// Func(42) // OK: the constructor is used for an implicit conversion of 42 to a temporary MyClass object
/// Func("Hello World"); // Error: the constructor is marked explicit
/// @endcode
/// Note that you have to mark a potential conversion constructor (i.e., one that takes a single argument)
/// with either MAXON_IMPLICIT or @c explicit, otherwise the source processor will complain.
//----------------------------------------------------------------------------------------
#define MAXON_IMPLICIT

using Int16 = int16_t;		///< 16 bit signed integer datatype.
using UInt16 = uint16_t;	///< 16 bit unsigned integer datatype.
using Int32 = int32_t;		///< 32 bit signed integer datatype.
using UInt32 = uint32_t;	///< 32 bit unsigned integer datatype.
using Int64 = int64_t;		///< 64 bit signed integer datatype.
using UInt64 = uint64_t;	///< 64 bit unsigned integer datatype.

using Bool = bool;									///< boolean type, possible values are only false/true, 8 bit
using Float32 = float;							///< 32 bit floating point value (float)
using Float64 = double;							///< 64 bit floating point value (double)
using Char = char;									///< signed 8 bit character
using UChar = unsigned char;				///< unsigned 8 bit character

#ifdef MAXON_TARGET_64BIT
	using Int = Int64;								///< signed 32/64 bit int, size depends on the platform
	using UInt = UInt64;							///< unsigned 32/64 bit int, size depends on the platform
#else
	using Int = Int32;								///< signed 32/64 bit int, size depends on the platform
	using UInt = UInt32;							///< unsigned 32/64 bit int, size depends on the platform
#endif

/// current floating point model.
/// right now it's adjusted to Float64==64 bit but maybe it's redefined to Float32 anytime
#if defined MAXON_TARGET_IOS
	using Float = Float32;
	#define MAXON_TARGET_SINGLEPRECISION
#else
	using Float = Float64;
#endif

enum class Byte : UChar; ///< A byte.

//----------------------------------------------------------------------------------------
/// User-defined literal to allow floating-point constants with the Float datatype of the MAXON API.
/// E.g. instead of writing 1.0 or 1.0f better write 1.0_f to use the Float type.
//----------------------------------------------------------------------------------------
MAXON_ATTRIBUTE_FORCE_INLINE constexpr Float operator "" _f(long double f)
{
	return Float(f);
}

//----------------------------------------------------------------------------------------
/// 32 bit unicode (UTF-32) character.
/// Utf32Char is the datatype for a single 32 bit unicode character.
//----------------------------------------------------------------------------------------
using Utf32Char = char32_t;

//----------------------------------------------------------------------------------------
/// 16 bit unicode character. Note that complex unicodes can be composed of two
/// individual 16 bit characters.
//----------------------------------------------------------------------------------------
using Utf16Char = char16_t;

//----------------------------------------------------------------------------------------
/// System-specific character. This is the character that will be fed to all system
/// functions.
/// Under windows this is a 16-bit wide value, all other platforms define it
/// as 8-bit (and encode strings as UTF-8).
//----------------------------------------------------------------------------------------
#ifdef MAXON_TARGET_WINDOWS
using SysChar = wchar_t;
#else
using SysChar = char;
#define MAXON_ATTRIBUTE_SYSCHAR_IS_CHAR	///< @markInternal
#endif


//----------------------------------------------------------------------------------------
/// This type trait has a type alias member @c type which points to the signed integral type consisting of @p BYTES bytes.
/// For example, <tt>IntType<4>::type</tt> is @c Int32.
/// @tparam BYTES									Number of bytes.
//----------------------------------------------------------------------------------------
template <Int BYTES> struct IntType;

template <> struct IntType<1> { using type = Char; };
template <> struct IntType<2> { using type = Int16; };
template <> struct IntType<4> { using type = Int32; };
template <> struct IntType<8> { using type = Int64; };

//----------------------------------------------------------------------------------------
/// This type trait has a type alias member @c type which points to the unsigned integral type consisting of @p BYTES bytes.
/// For example, <tt>UIntType<4>::type</tt> is @c UInt32.
/// @tparam BYTES									Number of bytes.
//----------------------------------------------------------------------------------------
template <Int BYTES> struct UIntType;

template <> struct UIntType<1> { using type = UChar; };
template <> struct UIntType<2> { using type = UInt16; };
template <> struct UIntType<4> { using type = UInt32; };
template <> struct UIntType<8> { using type = UInt64; };

//----------------------------------------------------------------------------------------
/// This type trait has a type alias member @c type which normally points the type T itself.
/// But for integral types (other than Bool, Utf16Char and Utf32Char) this points to the type of the MAXON API which matches T in size and signedness.
/// For example StandardType<long long>::type is Int64, although on some platforms long long
/// differs from Int64.
/// @tparam T											The type for which the standard type shall be obtained.
//----------------------------------------------------------------------------------------
template <typename T, Bool INTEGRAL = std::is_integral<T>::value> struct StandardType
{
	using type = T;
};

template <typename T> struct StandardType<T, true>
{
	using DT = typename std::decay<T>::type;
	static const Bool KEEP = std::is_same<DT, Bool>::value || std::is_same<DT, Utf16Char>::value || std::is_same<DT, Utf32Char>::value;
	using type = typename std::conditional<KEEP, T, typename std::conditional<std::is_signed<T>::value, typename IntType<sizeof(T)>::type, typename UIntType<sizeof(T)>::type>::type>::type;
};

/// Invalid array index (e.g. returned for an array index out of bounds).
static const Int InvalidArrayIndex = -1;

//----------------------------------------------------------------------------------------
/// Use this as the bound of an array which is the last member of a class and shall have a flexible array length.
/// Example:
/// @code
/// struct MyStruct
/// {
///   Int a;
///   Int b[MAXON_FLEXIBLE_ARRAY_LENGTH];
/// };
/// ...
/// MyStruct* s = MAXON_SAFE_PLACEMENT_NEW(NewMem(Char, SIZEOF(MyStruct) + SIZEOF(Int) * (cnt - MAXON_FLEXIBLE_ARRAY_LENGTH))) MyStruct();
/// @endcode
/// @warning This may only be used if the class has standard-layout. Also you have to implement
/// default constructor and copy operations properly. Keep in mind that the actual class instance may have
/// less elements than the compiler thinks.
//----------------------------------------------------------------------------------------
static const Int MAXON_FLEXIBLE_ARRAY_LENGTH = 123; // Don't use 1 as this would allow the compiler to replace the index access array[index] by array[0]

template <typename T, Bool STRIDED = false, Bool MOVE = false> class Block;
class String;
class CString;
class FormatStatement;
class ObjectInterface;
enum class GenericComponent : Char;
class ObjectRef;
class Data;
class InternedId;
class LiteralId;
class Id;
class DataType;
class Url;

template <typename T> class Result;
template <typename T> class ResultOk;

class Error;
class ErrorPtr;
class NoErrorPtr;
class ErrorInterface;

constexpr inline UInt UIntPow(UInt x, Int exp)
{
	// we don't use a simple recursion like 'return (exp == 0) ? 1 : UIntPow(x, exp - 1) * x;' here and in the following as this would lead to too deep recursions (the C++ spec recommends to support a depth of 512)
	return (exp == 0) ? 1 : (exp == 1) ? x : UIntPow(x, exp / 2) * UIntPow(x, exp - exp / 2);
}

constexpr inline UInt PrivateGetHashCode(const char* str, Int len)
{
	return (len == 0) ? 0 : (len == 1) ? (UChar) *str : PrivateGetHashCode(str, len / 2) * UIntPow(31, len - len / 2) + PrivateGetHashCode(str + len / 2, len - len / 2);
}

constexpr inline UInt PrivateGetHashCode(const Utf32Char* str, Int len)
{
	return (len == 0) ? 0 : (len == 1) ? (std::make_unsigned<Utf32Char>::type) *str : PrivateGetHashCode(str, len / 2) * UIntPow(31, len - len / 2) + PrivateGetHashCode(str + len / 2, len - len / 2);
}

//----------------------------------------------------------------------------------------
/// Forces a compile-time evaluation of the constexpr expression X of integral type T.
/// Sometimes this is needed to give the compiler a clue that the expression can be evaluated at run-time,
/// which then can enable further optimization.
/// @param T											Type of the expression (has to be an integral type).
/// @param X											The expression.
/// @return												Compile-time constant value of the expression.
//----------------------------------------------------------------------------------------
#define MAXON_CONSTEXPR_EVAL(T, X) std::integral_constant<T, X>::value

//----------------------------------------------------------------------------------------
/// @markInternal
/// Forwards to StringInterface::GetAndCacheConstString, this allows to use CONSTSTRING and the literal operator _s in uninstantiated template code without having to include string.h
//----------------------------------------------------------------------------------------
const String& StringInterface_GetAndCacheConstString(const wchar_t* str, Int len);

//----------------------------------------------------------------------------------------
/// @markInternal
/// Forwards to StringInterface::GetAndCacheConstString, this allows to use CONSTSTRING and the literal operator _s in uninstantiated template code without having to include string.h
//----------------------------------------------------------------------------------------
const String& StringInterface_GetAndCacheConstString(const Char* str, Int len, Int isUtf8);

constexpr inline Bool PrivateIsUtf8(const char* str, Int len)
{
	return (len == 0) ? false : ((len == 1) ? ((*str & 0x80) != 0) : (PrivateIsUtf8(str, len / 2) | PrivateIsUtf8(str + len / 2, len - len / 2)));
}

#define PRIVATE_MAXON_AS_UTF8(x)	u8##x

// Must use MAXON_CONSTEXPR_EVAL to force the compiler to compute the expression at compile time.
#define CONSTSTRING(x) (maxon::StringInterface_GetAndCacheConstString(PRIVATE_MAXON_AS_UTF8("") PRIVATE_MAXON_AS_UTF8(x), SIZEOF(PRIVATE_MAXON_AS_UTF8(x)) - 1, MAXON_CONSTEXPR_EVAL(maxon::Bool, maxon::PrivateIsUtf8(PRIVATE_MAXON_AS_UTF8(x), SIZEOF(PRIVATE_MAXON_AS_UTF8(x))))))

//----------------------------------------------------------------------------------------
/// Returns a String object of the characters passed in quotation marks.
/// If the same characters are used in another place the String will still only be created once in memory.
/// In the following example the second loop is far more efficient because the String is created only
/// once whereas in the first loop the characters are converted to unicode and a new String object is
/// created (and deleted) on each iteration.
/// @code
/// for (...)
/// {
///   if (s.FindIndex(String("A is created each time.")) == 0) ...
/// }
///
/// for (...)
/// {
///   if (s.FindIndex("B is created only once."_s) == 42) ...
/// }
/// @endcode
/// As MSVC does not properly resolve \u sequences for char* you need to use the wchar_t version below for any characters >=0x80.
//----------------------------------------------------------------------------------------
inline const String& operator "" _s(const char* str, std::size_t cnt)
{
	// -1: The StringInterface has to check once if the string contains utf8 because from this operator it can't be checked at compile time.
	return StringInterface_GetAndCacheConstString(str, cnt, -1);
}

//----------------------------------------------------------------------------------------
/// Returns a String object of the characters passed in quotation marks.
/// This version can be used for unicode characters, e.g. L"t\u00e8st"_s.
//----------------------------------------------------------------------------------------
inline const String& operator "" _s(const wchar_t* str, std::size_t cnt)
{
	return StringInterface_GetAndCacheConstString(str, cnt);
}

//----------------------------------------------------------------------------------------
/// Forwards to ToString function overloads. A call to GlobalToString can be used within a class
/// if the class itself declares a ToString member function (which is quite common):
/// Then this function hides the ToString functions of enclosing namespaces, and to call them
/// you either have to write maxon::ToString (but then you have to be sure that the function is
/// in the maxon namespace), or just GlobalToString (which utilizes argument-dependent lookup
/// and, thus, finds ToString functions in all related namespaces).
/// @param[in] object							Some object to be converted to a string.
/// @param[in] formatStatement		Nullptr or additional formatting instruction. See also @ref format_integer.
/// @param[in] checkDataType			Must be set to true (the default value), only for internal use.
/// @return												The converted result.
//----------------------------------------------------------------------------------------
template <typename T> inline String GlobalToString(const T& object, const FormatStatement* formatStatement, Bool checkDataType = true);


//----------------------------------------------------------------------------------------
/// An empty class without any members.
//----------------------------------------------------------------------------------------
class EmptyClass
{
};


//----------------------------------------------------------------------------------------
/// An empty class with a virtual destructor. This can be used for a template parameter
/// of a class template where the parameter sets the base class of the template. This ensures
/// that already the top-level base class has a virtual destructor, which (for usual compilers)
/// yields a simpler class layout than a class inheritance hierarchy where derived classes
/// introduce virtual functions at first. Example:
/// @code
/// template <typename S> class MyTemplate : public S { ... };
/// class MyClass : public MyTemplate<EmptyVirtualClass>
/// {
/// public:
///   virtual void MyFunction();
/// };
/// @endcode
//----------------------------------------------------------------------------------------
class EmptyVirtualClass
{
public:
	virtual ~EmptyVirtualClass() { }
};


//----------------------------------------------------------------------------------------
/// DummyParamType is an incomplete type which is used for parameter types of parameters
/// with default values which should never be given explicitly, or for parameter types
/// of functions which should never be invoked. The latter is typically needed for the
/// disabling of function templates.
//----------------------------------------------------------------------------------------
class DummyParamType;

//----------------------------------------------------------------------------------------
/// DummyReturnType is an incomplete type which is used for return types
/// of functions which should never be invoked. This is typically needed for the
/// disabling of function templates.
//----------------------------------------------------------------------------------------
class DummyReturnType;

//----------------------------------------------------------------------------------------
/// Generic is an incomplete type which is used for parameter types of some interface functions.
/// Generic* serves a similar purpose as void*, but is more type-safe as no implicit conversions
/// from other pointer types to Generic* are defined.
//----------------------------------------------------------------------------------------
class Generic;

//----------------------------------------------------------------------------------------
/// This helper class can be used for two purposes: It allows to disable function templates based on the template arguments,
/// and to defer the compiler's requirements for complete types to the template instantiation. An example of the first usage is:
/// @code
/// template <typename T> typename SFINAEHelper<Int, typename T::IsForEachIterator>::type MyFunction(const T& object);
/// @endcode
/// MyFunction will only be available for types T which have a member type IsForEachIterator, and its result type will be Int.
/// An example of the second usage is:
/// @code
/// class String;
/// template <typename T> typename SFINAEHelper<String, T>::type ToString(const T& object) { return object.ToString(); }
/// @endcode
/// Without the SFINAEHelper, the compiler would complain that String is an incomplete type and as such cannot be used for the
/// return type of a function definition, so you'd have to include the corresponding header file for String.
/// With the SFINAEHelper, only when the ToString template function is actually instantiated
/// String has to be a complete type, so it suffices to include the header file for String only where it is actually used.
/// @tparam T											Type used for the result.
/// @tparam CHECK									Some types which are used for SFINAE on overload resolution.
//----------------------------------------------------------------------------------------
template <typename T, typename... CHECK> class SFINAEHelper
{
public:
	using type = T; ///< The result type will always be T.
};


//----------------------------------------------------------------------------------------
/// Artificially makes the given expression value dependent on a template type parameter T.
/// This can be used in function templates when an expression contains an incomplete type at its
/// point of definition (so that compilers complain), but the type will be complete
/// when the template is instantiated later.
/// @tparam T											A template type parameter on which the expression shall be made dependent.
/// @param[in] value							The expression value.
/// @return												The forwarded expression value.
//----------------------------------------------------------------------------------------
template <typename T, typename E> inline E&& MakeDependentExpr(E&& value)
{
	return std::forward<E>(value);
}

}

namespace std
{
template <> struct is_constructible<maxon::Generic, const maxon::Generic&> : public std::false_type
{
};

// Redefinitions of small things from std for which including their original header files would increase compile times disproportionately.
// The maxon_std namespace is mapped to std by "using namespace maxon_std;", this avoids conflicts when the std header files are included.
namespace maxon_std
{

template <typename T> inline T* addressof(T& x)
{
	return (T*) &reinterpret_cast<const volatile char&>(x);
}

}

// stylecheck.using=false
using namespace maxon_std;
// stylecheck.using=true

}

// Helper macros for copy and move constructors, comparison operators and so on.
#include "maxon/utilities/classhelpers.h"

namespace maxon
{

// Templates to avoid unwanted enum usage/conversion
#include "maxon/utilities/enumflags.h"


//----------------------------------------------------------------------------------------
/// Marker type for constructors which don't initialize the class members at all.
/// E.g., vectors usally initialize all components with (0, 0, 0). Vector v(DONT_INITIALIZE); will create an uninitialized vector.
//----------------------------------------------------------------------------------------
enum class ENUM_DONT_INITIALIZE
{
	VALUE
} MAXON_ENUM_LIST(ENUM_DONT_INITIALIZE);

static const ENUM_DONT_INITIALIZE DONT_INITIALIZE = ENUM_DONT_INITIALIZE::VALUE;

//----------------------------------------------------------------------------------------
/// Marker type to resolve ambiguity for perfect-forwarded in-place constructors.
//----------------------------------------------------------------------------------------
enum class IN_PLACE_TYPE
{
	VALUE = 1
} MAXON_ENUM_LIST(IN_PLACE_TYPE);

static const IN_PLACE_TYPE IN_PLACE = IN_PLACE_TYPE::VALUE;


/// @}

}

// Type value ranges, math constants and trigonometric functions
#include "maxon/utilities/apibasemath.h"

namespace maxon
{

/// @addtogroup SYSTEM
/// @{

#define MAXON_CACHE_LINE_SIZE 64

#define MAXON_HAS_TRUE_TYPE(E) (!std::is_same<decltype(E), std::false_type>::value)

class PrivateOverloadRank0 { };
class PrivateOverloadRank1 : public PrivateOverloadRank0 { };
class PrivateOverloadRank2 : public PrivateOverloadRank1 { };
class PrivateOverloadRank3 : public PrivateOverloadRank2 { };
class PrivateOverloadRank4 : public PrivateOverloadRank3 { };
class PrivateOverloadRank5 : public PrivateOverloadRank4 { };

//----------------------------------------------------------------------------------------
/// Use OverloadRank0 .. OverloadRank5 as parameter types for a set of overloaded functions
/// which have to be selected by means of SFINAE. OverloadRank0 has to be used for the least specific
/// function (the fallback), higher ranks for the more specific functions in the correct order. E.g:
/// @code
/// // this fallback will be chosen if T has neither a member type named Marker nor a member type named ExtraMarker:
/// template <typename T> void Func(const T& object, OverloadRank0);
/// // will be chosen if T has a member type named Marker, but no member type named ExtraMarker:
/// template <typename T> typename SFINAEHelper<void, typename T::Marker>::type Func(const T& object, OverloadRank1);
/// // will be chosen if T has a member type named ExtraMarker:
/// template <typename T> typename SFINAEHelper<void, typename T::ExtraMarker>::type Func(const T& object, OverloadRank2);
/// @endcode
/// The set of overloaded functions has to be invoked with OVERLOAD_MAX_RANK as argument for the overload selection parameter:
/// @code
/// Func(obj, OVERLOAD_MAX_RANK);
/// @endcode
//----------------------------------------------------------------------------------------
using OverloadRank0 = PrivateOverloadRank0*;

/// See OverloadRank0.
using OverloadRank1 = PrivateOverloadRank1*;

/// See OverloadRank0.
using OverloadRank2 = PrivateOverloadRank2*;

/// See OverloadRank0.
using OverloadRank3 = PrivateOverloadRank3*;

/// See OverloadRank0.
using OverloadRank4 = PrivateOverloadRank4*;

/// See OverloadRank0.
using OverloadRank5 = PrivateOverloadRank5*;

using OverloadRankMax = OverloadRank5;

/// Use this as argument for the overload selection parameter of a set of overloaded functions, see OverloadRank0.
#define OVERLOAD_MAX_RANK ((maxon::OverloadRankMax) nullptr)



template <typename... T> struct AlwaysFalse { static bool const value = false; };


//----------------------------------------------------------------------------------------
/// Use And to do a compile-time boolean and for a list of values. The result will be in the
/// static member @c value. Example:
/// @code
/// template <typename... ARGS> void Func(const ARG&... arg)
/// {
///   static_assert(And<SomeCheck<ARG>::value...>::value, "SomeCheck failed for at least one of ARG.");
/// }
/// @endcode
//----------------------------------------------------------------------------------------
template <Bool...> struct And;

template <Bool... REST> struct And<true, REST...> : public And<REST...> { };
template <Bool... REST> struct And<false, REST...> : public std::false_type { };
template <> struct And<> : public std::true_type { };

//----------------------------------------------------------------------------------------
/// Aligns @p value according to @p alignment. @p alignment has to be a power of two, then
/// the function returns the smallest value not less than @p value which is a multiple of @p alignment.
/// @param[in] value							Value to align.
/// @param[in] alignment					Required alignment, must be a power of two.
/// @return												Aligned value (multiple of @p alignment closest to and not less than @p value).
//----------------------------------------------------------------------------------------
MAXON_ATTRIBUTE_FORCE_INLINE constexpr Int Align(Int value, Int alignment)
{
	return (value + (alignment - 1)) & ~(alignment - 1);
}

//----------------------------------------------------------------------------------------
/// Aligns @p value according to @p alignment. @p alignment has to be a power of two, then
/// the function returns the smallest pointer value not pointing below @p value which is a multiple of @p alignment.
/// @param[in] value							Pointer value to align.
/// @param[in] alignment					Required alignment, must be a power of two.
/// @return												Aligned pointer value (multiple of @p alignment closest to and not less than @p value).
//----------------------------------------------------------------------------------------
template <typename T> MAXON_ATTRIBUTE_FORCE_INLINE T* Align(T* value, Int alignment)
{
	return (T*) Align((Int) value, alignment);
}

//----------------------------------------------------------------------------------------
/// This type alias stands for the type @c{T[N]}.
/// @tparam T											A type.
/// @tparam N											The bound of the array.
//----------------------------------------------------------------------------------------
template <typename T, Int N> using AddArrayT = T[N];

//----------------------------------------------------------------------------------------
/// This type alias stands for the type @c{T[]}.
/// @tparam T											A type.
//----------------------------------------------------------------------------------------
template <typename T> using AddArrayOfUnknownBoundT = T[];

//----------------------------------------------------------------------------------------
/// This template has SUPER as protected base class. You can use it for other template classes
/// which use a template parameter as public base class if you need to use protected inheritance
/// instead.
/// @tparam SUPER									Base class of this template class.
//----------------------------------------------------------------------------------------
template <typename SUPER> class Protected : protected SUPER
{
public:
	template <typename... ARGS> MAXON_ATTRIBUTE_FORCE_INLINE explicit Protected(ARGS&&... args) : SUPER(std::forward<ARGS>(args)...) { }
};


//----------------------------------------------------------------------------------------
/// This transformation type trait can be used to add a const qualifier to a type T only if a condition is fulfilled.
/// <tt>ConstIf<T, C>::type</tt> will be T if C is false, const T otherwise.
/// @tparam T											Type to which a const qualifier shall be added conditionally.
/// @tparam MAKECONST							Bool value to enable the addition of the const qualifier.
//----------------------------------------------------------------------------------------
template <typename T, Bool MAKECONST> class ConstIf
{
public:
	using type = T; ///< The result type, either T or const T.
};

template <typename T> class ConstIf<T, true>
{
public:
	using type = const T;
};


//----------------------------------------------------------------------------------------
/// This transformation type trait can be used to add a const qualifier to a type T only if another type INHERIT_FROM also has this qualifier.
/// <tt>InheritConst<T, S>::type</tt> will be T if S has no top-level const qualifier, const T otherwise.
/// @tparam T											Type to which a const qualifier shall be added conditionally.
/// @tparam INHERIT_FROM					Another type from which the const qualifier shall be inherited.
//----------------------------------------------------------------------------------------
template <typename T, typename INHERIT_FROM> class InheritConst
{
public:
	using type = T; ///< The result type, either T or const T.
};

template <typename T, typename INHERIT_FROM> class InheritConst<T, const INHERIT_FROM>
{
public:
	using type = const T;
};


//----------------------------------------------------------------------------------------
/// This transformation type trait can be used to substitute the underlying type of T by R.
/// U gets replaced by R, U& by R&, U&& by R&&, and the same with const U/const R.
/// @tparam T											Original type.
/// @tparam R											Type which shall be used for replacement.
//----------------------------------------------------------------------------------------
template <typename T, typename R> class Substitute : public InheritConst<R, T>
{
};

template <typename T, typename R> class Substitute<T&, R>
{
public:
	using type = typename InheritConst<R, T>::type&;
};

template <typename T, typename R> class Substitute<T&&, R>
{
public:
	using type = typename InheritConst<R, T>::type&&;
};



template <typename... T> struct ParameterPack;

namespace details
{

template <typename PACK, typename... X> struct ParameterPackContainsAll : public And<(PACK::template IndexOf<X>::found > 0)...>
{
};
	
template <typename PACK, typename... X> struct ParameterPackContainsAll<PACK, ParameterPack<X...>> : public And<(PACK::template IndexOf<X>::found > 0)...>
{
};
	
}


//----------------------------------------------------------------------------------------
/// Helper class to work with parameter packs. IndexOf supports finding the index of a type
/// in the argument list, At supports indexing into the list, ContainsAll implements a subset test:
/// @code
/// ParameterPack<Int, Float, String, String>::IndexOf<Float>::value == 1
/// ParameterPack<Int, Float, String, String>::At<2>::type == String
/// ParameterPack<Int, Float, String, String>::ContainsAll<String, Int>::value == true
/// @endcode
/// @tparam T											The types of the parameter pack.
//----------------------------------------------------------------------------------------
template <typename... T> struct ParameterPack
{
	static_assert(sizeof...(T) == 0, "Specialization should be used.");

	static const Int COUNT = 0;

	//----------------------------------------------------------------------------------------
	/// IndexOf finds the index of type X in the parameter pack T. The index
	/// can be found in the member #value of IndexOf. If there is no unique such index
	/// because X doesn't exist at all in T or exists more than once, a negative value is used.
	/// The member #found counts the number of occurrences.
	/// @code
	/// ParameterPack<Int, Float, String, String>::IndexOf<Float>::value == 1
	/// ParameterPack<Int, Float, String, String>::IndexOf<String>::value < 0 // Ambiguous.
	/// ParameterPack<Int, Float, String, String>::IndexOf<String>::found == 2
	/// ParameterPack<Int, Float, String, String>::IndexOf<Char>::value < 0 // Not found.
	/// @endcode
	/// @tparam X											Type to search for.
	//----------------------------------------------------------------------------------------
	template <typename X> struct IndexOf
	{
		static const Int value = LIMIT<Int>::MIN;
		static const Int found = 0;
	};

	//----------------------------------------------------------------------------------------
	/// At indexes into the parameter pack and contains the type at the given index in its
	/// member type alias of name #type.
	/// @code
	/// ParameterPack<Int, Float, String, String>::At<2>::type == String
	/// @endcode
	/// @tparam INDEX									Index within the parameter pack.
	//----------------------------------------------------------------------------------------
	template <Int INDEX> struct At;

	//----------------------------------------------------------------------------------------
	/// The first type of this parameter pack.
	//----------------------------------------------------------------------------------------
	using FirstType = void;

	using RestPack = void;

	//----------------------------------------------------------------------------------------
	/// ContainsAll checks if this parameter pack contains all types X.
	/// Besides a list of types X can also be a ParameterPack itself.
	/// @code
	/// ParameterPack<Int, Float, String, String>::ContainsAll<String, Int>::value == true
	/// ParameterPack<Int, Float, String, String>::ContainsAll<ParameterPack<String, Int>>::value == true
	/// ParameterPack<Int, Float, String, String>::ContainsAll<String, Int, Bool>::value == false
	/// @endcode
	/// @tparam X											Types to check. This can either be a list of types, or a single ParameterPack.
	//----------------------------------------------------------------------------------------
	template <typename... X> using ContainsAll = maxon::details::ParameterPackContainsAll<ParameterPack, X...>;

	template <template <typename...> class TEMPLATE, typename... X> using Apply = TEMPLATE<X..., T...>;
};

template <typename T, typename... REST> struct ParameterPack<T, REST...>
{
	static const Int COUNT = 1 + sizeof...(REST);

	using FirstType = T;
	using RestPack = ParameterPack<REST...>;

	template <typename X> struct IndexOf
	{
		using Rest = typename RestPack::template IndexOf<X>;
		static const Int found = Rest::found + std::is_same<T, X>::value;
		static const Int value = !std::is_same<T, X>::value ? Rest::value + 1 : Rest::found ? LIMIT<Int>::MIN : 0;
	};

	template <typename... X> using ContainsAll = maxon::details::ParameterPackContainsAll<ParameterPack, X...>;

	template <Int INDEX> using At = typename std::conditional<INDEX == 0, SFINAEHelper<T>, typename RestPack::template At<INDEX-1>>::type;

	template <template <typename...> class TEMPLATE, typename... X> using Apply = TEMPLATE<X..., T, REST...>;
};


template <typename FUNCTION> struct GetSignature;

template <typename RET, typename... ARGS> struct GetSignature<RET(ARGS...)>
{
	using ReturnType = RET;
	using Parameters = ParameterPack<ARGS...>;
};

template <typename RET, typename... ARGS> struct GetSignature<RET(*)(ARGS...)>
{
	using ReturnType = RET;
	using Parameters = ParameterPack<ARGS...>;
};


template <typename T, typename A, typename B> class CommonLValue
{
public:
	using Base = typename std::decay<T>::type;
	static const Bool BOTH_DERIVED = std::is_base_of<Base, typename std::decay<A>::type>::value && std::is_base_of<Base, typename std::decay<B>::type>::value;
	static const Bool BOTH_LVALUES = std::is_lvalue_reference<A>::value && std::is_lvalue_reference<B>::value;
	static const Bool CONST_LVALUE = std::is_const<typename std::remove_reference<A>::type>::value || std::is_const<typename std::remove_reference<B>::type>::value;
	using type = typename std::conditional<BOTH_DERIVED && BOTH_LVALUES, typename ConstIf<Base, CONST_LVALUE>::type&, Base>::type;
};


template <typename A, typename B> class CommonType
	: public CommonLValue<decltype(true ? std::declval<A>() : std::declval<B>()), A, B>
{
};


// Used internally for checks if a member function or variable exists.
template <typename U, U> struct MemberDetectorHelper;

#define MAXON_MEMBERFUNCTION_DETECTOR(Name) \
	template <typename DETECTORINPUTTYPE> struct Has##Name \
	{ \
		using DT = typename std::decay<DETECTORINPUTTYPE>::type; \
		struct Default { maxon::Int Name; }; \
		struct Derived : public std::conditional<std::is_class<DT>::value, DT, maxon::EmptyClass>::type, public Default { Derived() = delete; }; \
		template <typename D> static std::false_type Test(maxon::MemberDetectorHelper<maxon::Int Default::*, &D::Name>*); \
		template <typename D> static std::true_type Test(...); \
		using type = decltype(Test<Derived>(nullptr)); \
		static const maxon::Bool value = type::value; \
	};

//----------------------------------------------------------------------------------------
/// This helper class is a work-around for an MSVC bug in the type
/// std::enable_if<(A & B) != FLAGS::NONE, T>. If A & B is not zero, EnableIfFlag<T, FLAGS, A, B, true>
/// has a type alias member pointing to T, otherwise there is no such type alias member.
/// @tparam T											Type used for the result.
/// @tparam FLAGS									Type of the flags.
/// @tparam A											First flag value.
/// @tparam B											Second flag value.
//----------------------------------------------------------------------------------------
template <typename T, typename FLAGS, FLAGS A, FLAGS B> class EnableIfFlag : public std::enable_if<((Int)A & (Int)B) != 0, T>
{
};


// Internal use: detect if a type T is complete, from http://stackoverflow.com/questions/1625105/how-to-write-is-complete-template
template <typename T> typename std::enable_if<(sizeof(T) > 0), std::true_type>::type IsCompleteHelper(T*);
std::false_type IsCompleteHelper(...);

template <typename T, Int, Bool value> class IsCompleteBase : public std::integral_constant<Bool, value> { };
template <typename T, Int COUNTER> class IsComplete : public IsCompleteBase<T, COUNTER, decltype(IsCompleteHelper((T*) nullptr))::value> { };

//----------------------------------------------------------------------------------------
/// This macro defines a type trait class with the given Name having a single template type parameter. It checks if the type
/// argument T (after removing a possible reference suffix) has a member type named Member. If so, Name<T> will contain a type alias member named type for T::Member, otherwise
/// the type alias will point to Default. Also a static member constant #value of type Bool is defined which is true if T::Member exists and it
/// doesn't point to std::false_type. Example:
/// @code
/// MAXON_MEMBERTYPE_DETECTOR(GetReferencedType, ReferencedType, std::false_type);
/// MAXON_MEMBERTYPE_DETECTOR(GetValueType, ValueType, void);
/// @endcode
/// With those two usages of the macro, <tt>GetReferencedType<T>::value</tt> will be true if T contains a member type ReferencedType (unless
/// that is std::false_type), and <tt>GetValueType<T>::type</tt> will be the type T::ValueType if that exists, void otherwise.
///
/// You may override the default type by specifying a second template argument:
/// <tt>GetValueType<T, X>::type</tt> will be X instead of the default @c void if T::ValueType doesn't exist.
//----------------------------------------------------------------------------------------
#define MAXON_MEMBERTYPE_DETECTOR(Name, Member, Default) \
	template <typename T, typename DEF = Default, typename = void> struct Name \
	{ \
		using type = DEF; \
		static const maxon::Bool value = false; \
	}; \
	template <typename T, typename DEF> struct Name<T, DEF, typename maxon::SFINAEHelper<void, typename std::decay<T>::type::Member>::type> \
	{ \
		using type = typename std::decay<T>::type::Member; \
		static const maxon::Bool value = !std::is_same<type, std::false_type>::value; \
	};

//----------------------------------------------------------------------------------------
/// This type trait checks if @p T is a reference class. If so, its member @c value will be @c true and its member @c type will be a
/// type alias for the @c ReferencedType of the reference.
/// @tparam T											Type to check.
//----------------------------------------------------------------------------------------
MAXON_MEMBERTYPE_DETECTOR(GetReferencedType, ReferencedType, std::false_type);

//----------------------------------------------------------------------------------------
/// This type trait checks if @p T has a ConstReferencedType type member. If so, its member @c value will be @c true and its member @c type will be a
/// type alias for the @c ConstReferencedType of T.
/// @tparam T											Type to check.
//----------------------------------------------------------------------------------------
MAXON_MEMBERTYPE_DETECTOR(GetConstReferencedType, ConstReferencedType, std::false_type);

//----------------------------------------------------------------------------------------
/// This type trait checks if @p T is a direct reference class, i.e., a class which consists of exactly one pointer member which directly
/// points to the referenced object. If so, its member @c value will be @c true and its member @c type will be a
/// type alias for the @c DirectlyReferencedType of the reference.
/// @tparam T											Type to check.
//----------------------------------------------------------------------------------------
MAXON_MEMBERTYPE_DETECTOR(GetDirectlyReferencedType, DirectlyReferencedType, std::false_type);

//----------------------------------------------------------------------------------------
/// This type trait checks if @p T has a ErasedType type member. If so, its member @c value will be @c true and its member @c type will be a
/// type alias for the @c ErasedType of T.
/// @tparam T											Type to check.
//----------------------------------------------------------------------------------------
MAXON_MEMBERTYPE_DETECTOR(GetErasedType, ErasedType, T);

template <typename REF> struct GetDirectlyReferencedTypeCheckConstAndPtr
{
	using RefType = typename std::remove_reference<REF>::type;
	using Base = GetDirectlyReferencedType<RefType, typename std::remove_pointer<RefType>::type>;
	static const Bool value = Base::value || std::is_pointer<RefType>::value;
	using type = typename std::conditional<std::is_const<RefType>::value, GetConstReferencedType<RefType, typename Base::type>, Base>::type::type;
};

//----------------------------------------------------------------------------------------
/// This type trait checks if @p T is type to be allocated via an @c Alloc function (@p T has to have a member type @c IsAllocType then).
/// If so, <tt>IsAllocType<T>::value</tt> will be @c true and <tt>IsAllocType<T>::type</tt> will be different from <tt>std::false_type</tt>.
/// @tparam T											Type to check.
//----------------------------------------------------------------------------------------
MAXON_MEMBERTYPE_DETECTOR(IsAllocType, IsAllocType, std::false_type);

//----------------------------------------------------------------------------------------
/// This type trait checks if @p T is a non-virtual interface.
/// If so, <tt>IsNonvirtualInterfaceType<T>::value</tt> will be @c true and <tt>IsNonvirtualInterfaceType<T>::type</tt> will be different from <tt>std::false_type</tt>.
/// @tparam T											Type to check.
//----------------------------------------------------------------------------------------
MAXON_MEMBERTYPE_DETECTOR(IsNonvirtualInterfaceType, NonvirtualInterfaceMarker, std::false_type); // true for non-virtual or non-simple virtual interfaces

//----------------------------------------------------------------------------------------
/// This type trait checks if @p T is a (non-simple) virtual interface.
/// If so, <tt>IsVirtualInterfaceType<T>::value</tt> will be @c true.
/// @tparam T											Type to check.
//----------------------------------------------------------------------------------------
MAXON_MEMBERTYPE_DETECTOR(IsVirtualInterfaceType, InterfaceMarker, std::false_type);

//----------------------------------------------------------------------------------------
/// This type trait checks if @p T is an interface.
/// If so, <tt>IsInterfaceType<T>::value</tt> will be @c true.
/// @tparam T											Type to check.
//----------------------------------------------------------------------------------------
MAXON_MEMBERTYPE_DETECTOR(IsInterfaceType, MTable, std::false_type);

//----------------------------------------------------------------------------------------
/// This type trait gets the @c ValueType member type of @p T. If this exists,
/// <tt>GetValueType<T>::value</tt> will be @c true and <tt>GetValueType<T>::type</tt> will be a type alias to this member type. Otherwise,
/// the type alias will point to @c void.
/// @tparam T											Type to check.
//----------------------------------------------------------------------------------------
MAXON_MEMBERTYPE_DETECTOR(GetValueType, ValueType, void);

//----------------------------------------------------------------------------------------
/// This type trait gets the @c HasBase member type of @p T. If this exists,
/// <tt>CheckHasBase<T>::value</tt> will be @c true and <tt>CheckHasBase<T>::type</tt> will be a type alias to this member type.
/// @tparam T											Type to check.
//----------------------------------------------------------------------------------------
MAXON_MEMBERTYPE_DETECTOR(CheckHasBase, HasBase, std::false_type);

//----------------------------------------------------------------------------------------
/// This type trait gets the @c NonConst member type of @p T (or std::false_type if this doesn't exist).
/// @tparam T											Type to check.
//----------------------------------------------------------------------------------------
MAXON_MEMBERTYPE_DETECTOR(GetNonConst, NonConst, std::false_type);

//----------------------------------------------------------------------------------------
/// This type trait gets the @c Handler member type of @p T (or std::false_type if this doesn't exist).
/// @tparam T											Type to check.
//----------------------------------------------------------------------------------------
MAXON_MEMBERTYPE_DETECTOR(GetHandler, Handler, std::false_type);

//----------------------------------------------------------------------------------------
/// This type trait checks if @p T is a direct reference class of an interface. If so, its member @c type is different from <tt>std::false_type</tt>.
/// @tparam T											Type to check.
//----------------------------------------------------------------------------------------
template <typename T> class IsReferenceClass : public IsInterfaceType<typename GetDirectlyReferencedType<T>::type>
{
};

//----------------------------------------------------------------------------------------
/// This type trait checks if @p T is a direct reference class of a virtual interface. If so, its member @c type is different from <tt>std::false_type</tt>.
/// @tparam T											Type to check.
//----------------------------------------------------------------------------------------
template <typename T> class IsObjectReferenceClass : public IsVirtualInterfaceType<typename GetDirectlyReferencedType<T>::type>
{
};


//----------------------------------------------------------------------------------------
/// This type trait checks if @p T has a member type named PartiallyOrdered.
/// If so, <tt>IsPartiallyOrdered<T>::value</tt> will be @c true.
/// @tparam T											Type to check.
//----------------------------------------------------------------------------------------
MAXON_MEMBERTYPE_DETECTOR(IsPartiallyOrdered, PartiallyOrdered, std::false_type);


//----------------------------------------------------------------------------------------
/// This type trait determines if values of type @p T can be compared trivially for equality,
/// i.e., by comparing the raw bytes. By default, this holds only for non-floating-point scalar types.
/// You can specialize this template for your own types if they can can be compared
/// trivially. This helps to speed up some generic implementations such as
/// DataDictionary. Keep in mind that a class with padding bytes cannot be compared
/// trivially as the padding bytes have undetermined values.
/// @tparam T											Type to check.
//----------------------------------------------------------------------------------------
template <typename T> struct IsTriviallyEquatable
{
	static const Bool value = std::is_scalar<T>::value && !std::is_floating_point<T>::value;
};


//----------------------------------------------------------------------------------------
/// This type trait determines if the default constructor of type @p T initializes the value
/// with a sequence of 0-bytes (or at least if a value initialized with 0-bytes is equivalent
/// to a value initialized by the default constructor). By default, this holds only for scalar types.
/// You can specialize this template for your own types if they are zero-initialized.
/// This helps to save space in the binaries as
/// the NullValue function can use a shared block of 0-bytes for all zero-initialized types.
/// @tparam T											Type to check.
//----------------------------------------------------------------------------------------
template <typename T> struct IsZeroInitialized : public std::is_scalar<T>::type
{
};

template <> struct IsZeroInitialized<Generic> : public std::false_type { };


//----------------------------------------------------------------------------------------
/// Points to a 32-byte-aligned block of 1024 zero bytes. The memory will be write-protected if possible.
//----------------------------------------------------------------------------------------
extern const void* g_zeroMemory;


//----------------------------------------------------------------------------------------
/// Returns a C++ reference to an object of type const T whose memory consists of immutable zero bytes.
/// This size of T must not exceed 1024 bytes. This is not checked by the compiler to allow for incomplete types.
//----------------------------------------------------------------------------------------
template <typename T> inline const T& GetZeroRef()
{
	return *(const T*) g_zeroMemory;
}


//----------------------------------------------------------------------------------------
/// A global const void* value initialized to zero. Compilers will be able to do optimizations because they know the zero value.
//----------------------------------------------------------------------------------------
static const void* const g_zeroPtr = 0;


//----------------------------------------------------------------------------------------
/// Returns a C++ reference to an object of type const T whose memory consists of immutable zero bytes
/// The size of T must not exceed the size of a pointer. This is not checked by the compiler to allow for incomplete types.
//----------------------------------------------------------------------------------------
template <typename T> inline const T& GetPtrSizedZeroRef()
{
	return reinterpret_cast<const T&>(g_zeroPtr);
}


//----------------------------------------------------------------------------------------
/// This class represents the unit type from type theory, i.e., a type which allows only a single value.
/// Therefore, each UnitType object is equal to each other UnitType object,
/// and the comparison operators are defined correspondingly for UnitType.
//----------------------------------------------------------------------------------------
class UnitType
{
public:
	Bool operator ==(const UnitType& b) const { return true; }
	Bool operator <(const UnitType& b) const { return false; }
	MAXON_OPERATOR_COMPARISON(UnitType);
	UInt GetHashCode() const { return 0; }
};


#if defined(MAXON_COMPILER_INTEL) // they don't allow GenericArithmetic to be used in a union because it has a constructor, use a pointer type instead
using GenericArithmetic = DummyParamType***;
#else
//----------------------------------------------------------------------------------------
/// GenericArithmetic represents an abstract type to be used as base type of all arithmetic types.
/// It is not the base in the sense of C++ (as there is no base type of, e.g., int), but
/// in the sense of the DataType system.
//----------------------------------------------------------------------------------------
class GenericArithmetic
{
public:
	explicit GenericArithmetic(Int = 0) { } // this constructor is needed by Vec3<GenericArithmetic>
	Bool operator ==(const GenericArithmetic& other) const { return false; }
	Bool operator <(const GenericArithmetic& other) const { return false; }
	MAXON_OPERATOR_COMPARISON(GenericArithmetic);
	UInt GetHashCode() const { return 0; }
};
#endif

namespace details
{

template <typename D, typename B, Int HAS_BASE_OR_SAME> class HasBaseHelper : public std::is_base_of<B, D>
{
public:
	static B* Cast(D* ptr)
	{
		return ptr;
	}
};

template <typename D, typename B> class HasBaseHelper<D, B, 1> : public D::HasBase::template Check<B>
{
};

template <typename D, typename B> class HasBaseHelper<D, B, 2> : public std::true_type
{
public:
	static B* Cast(D* ptr)
	{
		return ptr;
	}
};

template <typename T> struct MakeLValueConst
{
	using type = T;
};

template <typename T> struct MakeLValueConst<T&>
{
	using type = const T&;
};

}

//----------------------------------------------------------------------------------------
/// This type trait checks if @p D has @p B as its base. This is the case if both are the same,
/// or if both are virtual interfaces and @p D is (directly or indirecty) derived from @p B,
/// or if @p D is derived from @p B as a C++ class.
///
/// If @p D has @p B as its base, the function `HasBase<D, B>::Cast` can be used to cast a pointer
/// of the derived type to a pointer of the base type. This has to be used instead of a reinterpret_cast
/// because the latter doesn't handle correctly cases with virtual classes or multiple inheritance
/// when there are offsets between derived and base pointers.
///
/// Internally, if @p D has a member type @c HasBase, the check is forwarded to <tt>D::HasBase::Check<B></tt>
/// which implements the case for virtual interfaces. Otherwise, the check is simply forwarded to
/// <tt>std::is_base_of<B, D></tt>.
/// @tparam D											Derived type to check (potential reference and const qualifiers are removed).
/// @tparam B											Base type to check (potential reference and const qualifiers are removed).
//----------------------------------------------------------------------------------------
template <typename D, typename B> struct HasBase
{
	using DT = typename std::decay<D>::type;
	using BT = typename std::decay<B>::type;
	using Helper = maxon::details::HasBaseHelper<DT, BT, std::is_same<DT, BT>::value ? 2 : Int(CheckHasBase<DT>::value)>;

	static const Bool value = Helper::value;

	static BT* Cast(DT* ptr)
	{
		return Helper::Cast(ptr);
	}

	static const BT* Cast(const DT* ptr)
	{
		return Helper::Cast(const_cast<DT*>(ptr));
	}
};


//----------------------------------------------------------------------------------------
/// IsDerived can be used to bind BASE to the second parameter of HasBase:
/// The nested template Check is a template with a single parameter which checks
/// if that parameter has BASE as its base.
/// @tparam BASE									Base type to check (potential reference and const qualifiers are removed).
//----------------------------------------------------------------------------------------
template <typename BASE> struct IsDerived
{
	template <typename DERIVED> struct Check : public HasBase<DERIVED, BASE>
	{
	};
};


template <typename D, typename B> struct HasErasedBase
{
	using DT = typename std::decay<D>::type;
	using BT = typename std::decay<B>::type;
	using EDT = typename GetErasedType<DT>::type;
	using EBT = typename GetErasedType<BT>::type;
	using Helper = maxon::details::HasBaseHelper<EDT, EBT, std::is_same<EDT, EBT>::value ? 2 : Int(CheckHasBase<EDT>::value)>;

	static const Bool value = Helper::value;

	static BT* Cast(DT* ptr)
	{
		return static_cast<BT*>(Helper::Cast(ptr));
	}

	static const BT* Cast(const DT* ptr)
	{
		return static_cast<const BT*>(Helper::Cast(const_cast<DT*>(ptr)));
	}
};


template <typename TO, typename FROM, Bool SAFE, typename = void> struct GenericCastMemberTrait
{
	static constexpr Bool value = std::is_same<TO, FROM>::value;
};

template <typename TO, typename FROM, Bool SAFE> struct GenericCastMemberTrait<const TO&, FROM, SAFE> : public GenericCastMemberTrait<TO, FROM, SAFE>
{
};

template <typename TO, typename FROM, Bool SAFE> struct GenericCastMemberTrait<const TO&, FROM&, SAFE>
{
	static constexpr Bool value = std::is_base_of<TO, FROM>::value || (!SAFE && std::is_base_of<FROM, TO>::value) || GenericCastMemberTrait<TO, typename std::remove_const<FROM>::type, SAFE>::value;
};

template <typename TO, typename FROM, Bool SAFE> struct GenericCastMemberTrait<TO&, FROM&, SAFE>
{
	static constexpr Bool value = !SAFE && (std::is_base_of<TO, FROM>::value || std::is_base_of<FROM, TO>::value || GenericCastMemberTrait<TO, typename std::remove_const<FROM>::type, SAFE>::value);
};

template <typename TO, typename FROM, Bool SAFE> struct GenericCastMemberTrait<const TO*, FROM*, SAFE>
{
	static constexpr Bool value = std::is_base_of<TO, FROM>::value || (!SAFE && std::is_base_of<FROM, TO>::value) || GenericCastMemberTrait<TO, typename std::remove_const<FROM>::type, SAFE>::value;
};

template <typename TO, typename FROM, Bool SAFE> struct GenericCastMemberTrait<TO*, FROM*, SAFE>
{
	static constexpr Bool value = !SAFE && (std::is_base_of<TO, FROM>::value || std::is_base_of<FROM, TO>::value || GenericCastMemberTrait<TO, typename std::remove_const<FROM>::type, SAFE>::value);
};

template <typename TO, typename FROM, Bool SAFE, typename = void> struct GenericCastTrait : public GenericCastMemberTrait<TO, FROM, SAFE>
{
	using CastType = TO&&;
	using ReturnType = TO;
};

template <typename TO, typename FROM, Bool SAFE> using GenericCastReturnType = std::enable_if<GenericCastTrait<TO, typename maxon::details::MakeLValueConst<FROM>::type, SAFE>::value, typename GenericCastTrait<TO, typename maxon::details::MakeLValueConst<FROM>::type, SAFE>::ReturnType>;

template <typename TO, typename FROM> inline typename GenericCastReturnType<TO, FROM, false>::type GenericReinterpretCast(FROM&& value)
{
	return reinterpret_cast<typename GenericCastTrait<TO, typename maxon::details::MakeLValueConst<FROM>::type, false>::CastType>(value);
}

template <typename TO, typename FROM> inline typename GenericCastReturnType<TO, FROM, true>::type GenericUpCast(FROM&& value)
{
	return reinterpret_cast<typename GenericCastTrait<TO, typename maxon::details::MakeLValueConst<FROM>::type, true>::CastType>(value);
}

//----------------------------------------------------------------------------------------
/// This type trait yields T as its result type if T is a scalar type or a C++ reference type, otherwise const T&.
/// It can be used for the declaration of parameters of template functions to avoid the inefficient use of const T& for scalar values.
/// For the following function
/// @code
/// template <typename T> void Func(typename ByValueParam<T>::type value);
/// @endcode
/// a scalar value such as an Int is passed by value to Func, while a class value such as a Vector is passed as a const-reference const Vector&.
//----------------------------------------------------------------------------------------
template <typename T> class ByValueParam
{
public:
	static const Bool value = std::is_scalar<T>::value || std::is_reference<T>::value || std::is_void<T>::value;
	using type = typename std::conditional<value, T, typename std::add_lvalue_reference<typename std::add_const<T>::type>::type>::type; ///< The result type.
};


//----------------------------------------------------------------------------------------
/// This type trait has the type of T1 * T2 as result type.
/// You can use it to deduce the result type of multiplicative template functions.
//----------------------------------------------------------------------------------------
template <typename T1, typename T2, Bool = true> class MultiplicativePromotion
{
public:
	using type = decltype(std::declval<T1>() * std::declval<T2>());
};

template <typename T1, typename T2> class MultiplicativePromotion<T1, T2, false>
{
};

template <typename T> class MultiplicativePromotion<GenericArithmetic, T, true>
{
public:
	using type = GenericArithmetic;
};

template <typename T> class MultiplicativePromotion<T, GenericArithmetic, true>
{
public:
	using type = GenericArithmetic;
};

template <> class MultiplicativePromotion<GenericArithmetic, GenericArithmetic, true>
{
public:
	using type = GenericArithmetic;
};

#define PRIVATE_MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(Cls, ...) \
	Cls(const Cls&) = default; \
	Cls& operator =(const Cls&) = default; \
	Cls(Cls&&) = default; \
	Cls& operator =(Cls&&) = default; \
private: \
	using Super = __VA_ARGS__; \
public: \
	using Super::Super; \
	using Super::operator =


#define MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(Cls, ...) \
	Cls() = default; \
	PRIVATE_MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(Cls, __VA_ARGS__)


#define MAXON_UNIQUE_REFERENCE_CONSTRUCTORS(Cls, ...) \
	Cls() = default; \
	Cls(const Cls&) = delete; \
	Cls& operator =(const Cls&) = delete; \
	Cls(Cls&&) = default; \
	Cls& operator =(Cls&&) = default; \
private: \
	using Super = __VA_ARGS__; \
public: \
	using Super::Super; \
	using Super::operator =


/// @cond IGNORE

template <typename T, Bool reference, Bool function> class DereferenceHelper;

template <typename T, Bool function> class DereferenceHelper<T, false, function>
{
public:
	using type = T;

	static const type* GetPointer(const T& ptr)
	{
		return &ptr;
	}

	static type* GetPointer(typename std::conditional<function || std::is_const<T>::value, DummyParamType&, T&>::type ptr)
	{
		return &ptr;
	}
};

template <typename T> class DereferenceHelper<T*, false, false>
{
public:
	using type = T;

	static const type* GetPointer(const T* ptr)
	{
		return ptr;
	}

	static type* GetPointer(typename std::conditional<std::is_const<T>::value, DummyParamType&, T*>::type ptr)
	{
		return ptr;
	}
};

template <> class DereferenceHelper<std::nullptr_t, false, false>
{
public:
	using type = void;

	static std::nullptr_t GetPointer(std::nullptr_t)
	{
		return nullptr;
	}
};

template <typename T> class DereferenceHelper<T*, false, true>
{
public:
	using type = T*;

	static const type* GetPointer(T* const& ptr)
	{
		return &ptr;
	}
};

template <typename T> class DereferenceHelper<T, true, false>
{
public:
	using type = typename T::ReferencedType;

	static const type* GetPointer(const T& ptr)
	{
		return ptr.GetPointer();
	}
};

/// @endcond IGNORE


//----------------------------------------------------------------------------------------
/// This class is used to get a pointer to the actual data represented by an object t of type T.
/// The pointer is obtained by Dereference<T>::GetPointer(t), and it is defined as follows:
/// - If t is a function pointer F*, &t is the pointer.
/// - If t is a pointer U*, t itself is the pointer.
/// - If t is a reference and ALSO_REFS is true, t.GetPointer() is the pointer.
/// - If t is a BaseRef, t.GetPointer() is the pointer.
/// - Otherwise, &t points to the actual data.
//----------------------------------------------------------------------------------------
template <typename T, Bool ALSO_REFS = true> class Dereference : public DereferenceHelper<T, ALSO_REFS && GetReferencedType<T>::value, std::is_function<typename std::remove_pointer<T>::type>::value>
{
};

template <typename T, typename HANDLER> class BaseRef;

template <typename T, typename HANDLER> class Dereference<BaseRef<T, HANDLER>, false> : public DereferenceHelper<BaseRef<T, HANDLER>, true, false>
{
};

template <typename T> inline T NullValue();

/// @}

}

#include "maxon/utilities/debugdiagnostics.h"

#include "maxon/utilities/memoryallocationbase.h"

#include "maxon/utilities/compare.h"

#include "maxon/utilities/finally.h"

#include "maxon/utilities/apibaseid.h"

namespace maxon
{

/// @addtogroup DATATYPE
/// @{

template <typename T> class Result;
template <typename T> class ResultOk;

//----------------------------------------------------------------------------------------
/// ThreadReferencedError holds a pointer to an Error object which is referenced by the current thread
/// (or referenced globally such that its lifetime is sufficiently long).
/// It is used at some places of the API when an Error shall be passed in return values of functions:
/// If Error was used instead, this would introduce overhead because of its reference counting and
/// because it can't be passed in registers.
/// @see System::SetCurrentError
//----------------------------------------------------------------------------------------
class ThreadReferencedError
{
public:
	//----------------------------------------------------------------------------------------
	/// Constructs a ThreadReferencedError from an error object which is referenced by the current thread
	/// (or referenced globally such that its lifetime is sufficiently long).
	/// @param[in] referencedError		Pointer to an error object, must not be nullptr or a pointer to a null reference.
	/// @return												ThreadReferencedError holding the pointer.
	//----------------------------------------------------------------------------------------
	static ThreadReferencedError CreateFromReferencedError(const Error* referencedError)
	{
		DebugAssert(referencedError && *(void**) referencedError);
		MAXON_ASSERT_STANDARD_LAYOUT(ThreadReferencedError);
		// There's no constructor declared to be able to store this in a register on Windows.
		return *(ThreadReferencedError*) &referencedError;
	}

	void operator =(const Error* error)
	{
		_error = error;
	}

	void operator =(const ErrorPtr& error)
	{
		_error = reinterpret_cast<const ThreadReferencedError&>(error)._error;
	}

	//----------------------------------------------------------------------------------------
	/// Returns a pointer to the wrapped Error object. This may be nullptr. If a non-null pointer
	/// is returned, then the Error itself is guaranteed to be a non-null reference.
	/// @return												The wrapped error object.
	//----------------------------------------------------------------------------------------
	const Error* GetReferencedError() const
	{
		return _error;
	}

	operator ErrorPtr&()
	{
		return *reinterpret_cast<ErrorPtr*>(this);
	}

	operator NoErrorPtr&()
	{
		return *reinterpret_cast<NoErrorPtr*>(this);
	}

private:
	const Error* _error;

	template <typename> friend class ResultBase;
	template <typename> friend class Result;
};

class TranslationUnit;

/// @cond INTERNAL

//----------------------------------------------------------------------------------------
/// EntityBase is used for EntityReference, EntityDefinition and TranslationUnit objects to name an entity.
/// Such objects are created implicitly by several macros as global objects. They are used to tell
/// what is contained in a source file, to establish dependencies between source files, and finally to
/// properly initialize and shutdown the program entities.
///
/// Each entity has a (normally unique) identifier, and there are several types of entities:
///  - Interfaces are declared by MAXON_INTERFACE_NONVIRTUAL and defined by MAXON_IMPLEMENTATION.
///  - Virtual interfaces are declared by MAXON_INTERFACE. They cannot be defined by user-code (there exists
///    only an internal definition), but through components defined by MAXON_COMPONENT one can have several implementations of
///    a virtual interface.
///  - Published objects are declared by MAXON_DECLARATION and defined by MAXON_DECLARATION_REGISTER.
///    MAXON_DECLARATION_REGISTER also defines objects.
///    The pair MAXON_DATATYPE / MAXON_DATATYPE_REGISTER makes use of published objects, too.
///  - Component descriptors are defined by MAXON_COMPONENT_ONLY_REGISTER.
///  - A translation unit is automatically defined for each cpp source file. The identifier is given by the source filename, so it is not necessarily unique.
///  - A module is defined automatically, the identifier is set by the project manager.
///  - A pair of initialization/shutdown functions is defined by MAXON_INITIALIZATION. No identifier is specified as this is only local to a single source file.
///  - A dependency target is defined by MAXON_DEPENDENCY_REGISTER. References to this target
///    are specified by MAXON_DEPENDENCY, they establish additional dependencies between translation units.
//----------------------------------------------------------------------------------------
class EntityBase
{
public:
	/// TYPE defines the set of entity types.
	enum class TYPE
	{
		INVALID_0,									///< An invalid type (underlying value is 0).
		INTERFACE,									///< A virtual interface declared by MAXON_INTERFACE.
		INTERFACE_NVMTABLE,					///< The nonvirtual method table of an interface with single implementation.
		NONVIRTUAL_INTERFACE,				///< A non-virtual interface declared by MAXON_INTERFACE_NONVIRTUAL, this has a single implementation.
		DECLARATION,								///< A published object with a single definition, declared by MAXON_DECLARATION.
		COMPONENT,									///< A component descriptor, declared by MAXON_COMPONENT_ONLY_REGISTER.
		CLASS,											///< An object of type Class<T>.
		TRANSLATION_UNIT,						///< A translation unit (i.e., a single source file together with its included files).
		MODULE,											///< A whole module, defined by the automatic registration.
		INITIALIZATION,							///< A pair of initialization/shutdown functions defined by MAXON_INITIALIZATION.
		DEPENDENCY,									///< An explicitly given dependency established by MAXON_DEPENDENCY and MAXON_DEPENDENCY_REGISTER.
		REGISTRY,										///< A registry.
		REGISTRY_MODULE,						///< A registry module. This is only used for registries with dependencies.
		GLOBAL,											///< A Global object.
		COUNT
	} MAXON_ENUM_LIST_CLASS(TYPE);

	/// Flags for the entity object. Some flags represent state, others describe constant properties of the object.
	enum class FLAGS : UInt32
	{
		NONE = 0,

		/// State flag set when the object has been constructed (as part of the C++ initialization of non-local variables). This does not mean that the object has already been initialized.
		CONSTRUCTED = 0x0001,

		/// This flag is set for entity definitions by the configuration database if the entity is disabled.
		DISABLED = 0x0002,

		/// State flag to indicate that the object has been initialized successfully.
		INITIALIZED = 0x0004,

		/// State flag to indicate that the object is currently being initialized.
		INITIALIZING = 0x0008,

		/// State flag set when the initialization fails.
		INITIALIZATION_FAILED = 0x0010,

		/// This is set for interface references if the null implementation shall be used when no actual implementation can be found.
		NULL_AS_DEFAULT = 0x0020,

		/// State flag set for entity definitions when they are referenced by either an EntityUse or an EntityReference,
		/// and for entity references when they are referenced by an EntityUse.
		USED = 0x0040,

		/// This flag is set for entity definitions which shall not be accessible by their ids (so their ids needn't be unique).
		HIDDEN = 0x0080,

		/// Set for the translation unit of register.cpp.
		REGISTRATION_UNIT = 0x0100,

		/// Tells whether this entity base object is an EntityReference or an entity definition (EntityDefinition or TranslationUnit).
		DEFINITION = 0x0200,

		/// Tells for a virtual interface reference if _basesPtr points to a single base or to a null-terminated list of bases.
		SINGLE_BASE = 0x0400,

		/// Tells for a non-virtual interface implementation that it shall only be used when it is explicitly selected by the configuration.
		EXPLICIT = 0x0800,

		/// This flag is set for a framework module.
		FRAMEWORK = 0x1000,

		/// This flag is set for the core module.
		CORE = 0x2000,

		/// This flag is set for all proxy components.
		PROXY = 0x4000,

		/// This flag is set for all class proxy components.
		CLASS_PROXY = 0x8000,

		/// This flag is set for a final component.
		FINAL = 0x10000,

		/// This flag is set for virtual interface references and definitions if only a single implementation of the interface exists.
		SINGLE_IMPLEMENTATION = 0x20000,

		/// This flag is set for a virtual interface definition when it is the main version of the interface.
		MAIN_DEFINITION = 0x40000,

		/// This flag is set for a virtual interface definition whose methods can be called. This is either the main version or a version which can be adapted from the main version.
		CALLABLE = 0x80000,

		/// This flag is set for a virtual interface definition which can be implemented. This is either the main version or a version which can be adapted to the main version.
		/// The flag is also set for a proxy component whose interface has this flag set.
		IMPLEMENTABLE = 0x100000,

		/// This flag is set for adapter components and for translation units which contain adapters.
		ADAPTER = 0x200000,

		/// This flag is set for virtual interface definitions which aren't explicity registered.
		SYNTHETIC = 0x400000,

		/// This flag is set for virtual interface definitions as soon as there exists an object whose class implements the interface.
		LIVE = 0x800000,

		// This flag is only needed within tests. It is set for entities whose initialization is expected to fail so that an error is created
		// when the initialization succeeds.
		EXPECT_FAILURE = 0x1000000,

		/// Set for the translation units of framework registrations.
		FRAMEWORK_REGISTRATION = 0x2000000,

		/// Set for an object definition which belongs to a registry with dependencies.
		AT_REGISTRY_WITH_DEPENDENCIES = 0x4000000,

		/// Set for a public framework.
		PUBLIC = 0x8000000,

		/// This is set for interfaces which use MAXON_REFERENCE_NONE or MAXON_REFERENCE_STATIC.
		REFERENCE_NONE = 0x00000000,

		/// This is set for interfaces which use MAXON_REFERENCE_POINTER.
		REFERENCE_POINTER = 0x10000000,

		/// This is set for interfaces which use MAXON_REFERENCE_CONST_POINTER.
		REFERENCE_CONST_POINTER = 0x20000000,

		/// This is set for interfaces which use MAXON_REFERENCE_NORMAL.
		REFERENCE_NORMAL = 0x30000000,

		/// This is set for interfaces which use MAXON_REFERENCE_CONST.
		REFERENCE_CONST = 0x40000000,

		/// This is set for interfaces which use MAXON_REFERENCE_COPY_ON_WRITE.
		REFERENCE_COPY_ON_WRITE = 0x50000000,

		/// This is set for interfaces which use MAXON_REFERENCE_ALWAYS_COPY_ON_WRITE.
		REFERENCE_ALWAYS_COPY_ON_WRITE = 0x60000000,

		/// Masks the bits for the reference type of the interface.
		REFERENCE_MASK = 0xf0000000,

		ON_CONSTRUCTION_MASK = CONSTRUCTED | NULL_AS_DEFAULT | HIDDEN | REGISTRATION_UNIT | DEFINITION | SINGLE_BASE | EXPLICIT | FRAMEWORK | CORE
			| PROXY | CLASS_PROXY | FINAL | SINGLE_IMPLEMENTATION | MAIN_DEFINITION | ADAPTER | SYNTHETIC | EXPECT_FAILURE | FRAMEWORK_REGISTRATION | AT_REGISTRY_WITH_DEPENDENCIES | PUBLIC | REFERENCE_MASK
	} MAXON_ENUM_FLAGS_CLASS(FLAGS);

	//----------------------------------------------------------------------------------------
	/// Constructs the entity base object.
	/// @param[in] type								Entity type.
	/// @param[in] idValue						Entity identifier.
	/// @param[in] unit								The translation unit containing the implementation.
	/// @param[in] flags							Initial flags for the object.
	//----------------------------------------------------------------------------------------
	EntityBase(TYPE type, LiteralId&& idValue, TranslationUnit* unit, FLAGS flags);

	//----------------------------------------------------------------------------------------
	/// Returns the unique identifier of the entity.
	/// @return												Identifier of the entity.
	//----------------------------------------------------------------------------------------
	const Id& GetId() const
	{
		return _id.Get();
	}

	//----------------------------------------------------------------------------------------
	/// Returns the flags of the entity. State flags may change during the lifetime of the entity,
	/// while flags describing entity properties are set on construction or by the configuration data base.
	/// @return												Current entity flags.
	//----------------------------------------------------------------------------------------
	FLAGS GetFlags() const
	{
		return _flags;
	}

	//----------------------------------------------------------------------------------------
	/// Returns the type of the entity.
	/// @return												Entity type.
	//----------------------------------------------------------------------------------------
	TYPE GetType() const
	{
		return _type;
	}

	//----------------------------------------------------------------------------------------
	/// Initializes the entity object. This is invoked by the object system after all other
	/// entity objects on which this object depends have been initialized. If the object has been initialized already,
	/// or if such a previous attempt failed, no further initialization is done. If this object is an entity definition,
	/// all references to the definition will be initialized, too.
	/// @param[in] cause							Identifier of another entity which caused the initialization of this entity object. This is only for informative purpose.
	/// @return												Success of initialization.
	//----------------------------------------------------------------------------------------
	Result<void> Initialize(const Id& cause) const;

	//----------------------------------------------------------------------------------------
	/// Returns the translation unit which contains this object. A translation unit corresponds to a C++ source file together with its
	/// included files, and the TranslationUnit object contains all EntityReference and EntityDefinition objects which are defined in the translation unit.
	/// @return												Translation unit which contains this object.
	//----------------------------------------------------------------------------------------
	const TranslationUnit* GetTranslationUnit() const
	{
		return _unit;
	}

	//----------------------------------------------------------------------------------------
	/// Resets the entity object to its initial state. The initial state is the state right after the C++ initialization
	/// of non-local variables has completed. This function is invoked on shutdown of a module or the whole application
	/// to allow for a later re-initialization.
	//----------------------------------------------------------------------------------------
	void Reset()
	{
		_nextInitialized = nullptr;
		_flags &= FLAGS::ON_CONSTRUCTION_MASK;
	}

private:
	EntityBase() = default;

	EntityBase(const EntityBase& src) = delete;
	EntityBase& operator =(const EntityBase& src) = default;

	// EntityBase has to be a standard-layout class, keep in mind when declaring members
	TYPE _type; ///< Entity type.
	LiteralId _id; ///< Entity identifier.
	TranslationUnit* _unit; ///< The translation unit containing the implementation.
	EntityBase* _nextInitialized; ///< Used internally for a linked list of successfully initialized entities of a translation unit.
	FLAGS _flags; ///< Flags for the entity.

	friend class EntityDefinition;
	friend class ObjectModel;
	friend class ClassImpl;
	friend class EntityUse;
	friend class TranslationUnit;
};

class EntityDefinition;
class EntityReference;
class EntityUse;
class ModuleInfo;
class Binary;

namespace details
{

template <UInt64 MODULE_ID_HASH = PrivateGetHashCode(MAXON_MODULE_ID, SIZEOF(MAXON_MODULE_ID)-1)> struct ModuleInfoWrapper
{
	static ModuleInfo info;
};

#ifndef PRIVATE_MAXON_DEFINE_MODULE_INFO
extern template struct ModuleInfoWrapper<>;
#endif

#define PRIVATE_MAXON_MODULE maxon::details::ModuleInfoWrapper<>::info

}

// Internal temporary data for Tarjan's algorithm to find strongly connected coomponents.
class SCCData
{
public:
	void Reset()
	{
		_index0OnStack = -2;
		_index1 = -1;
	}

	Int GetIndex0() const
	{
		return _index0OnStack >> 1;
	}

	void SetIndex0(Int value)
	{
		_index0OnStack = (value << 1) + (_index0OnStack & 1);
	}

	Bool IsOnStack() const
	{
		return (_index0OnStack & 1) != 0;
	}

	void SetOnStack()
	{
		_index0OnStack |= 1;
	}

	void ClearOnStack()
	{
		_index0OnStack &= ~Int(1);
	}

	Int& GetIndex1()
	{
		return _index1;
	}

	void SetIndex1(Int value)
	{
		_index1 = value;
	}

private:
	Int _index0OnStack; // lowest bit used as "onStack" flag to save space, the actual index value is shifted by one
	Int _index1;
};


class OptionalUse;

//----------------------------------------------------------------------------------------
/// For each cpp source file, a static TranslationUnit object is defined which contains information about
/// that source file, namely the module to which it belongs as well as lists of all entity definitions
/// and entity uses it contains. Based on the latter, the object system determines dependencies between
/// translation units and initializes the entities of a translation unit in an order which repects
/// the dependencies. Entities of a single translation unit are initialized in their order within the translation unit.
//----------------------------------------------------------------------------------------
class TranslationUnit
{
public:
	TranslationUnit() = default;

	TranslationUnit(const ModuleInfo* module, const Char* file, EntityBase::FLAGS flags);

	//----------------------------------------------------------------------------------------
	/// Returns the name of the cpp source file. For compilers without __BASE_FILE__ macro, this might return "??.cpp"
	/// if the object system cannot determine the name by other means.
	/// @return												Name of the source file.
	//----------------------------------------------------------------------------------------
	const Char* GetName() const
	{
		return _super.GetId().GetCString();
	}

	//----------------------------------------------------------------------------------------
	/// Returns the identifier of the module which contains this translation unit.
	/// @return												Module id.
	//----------------------------------------------------------------------------------------
	const Id& GetModuleId() const;

	//----------------------------------------------------------------------------------------
	/// Returns the ModuleInfo for the module which contains this translation unit.
	/// @return												ModuleInfo of containing module.
	//----------------------------------------------------------------------------------------
	const ModuleInfo* GetModule() const
	{
		return _module;
	}

	//----------------------------------------------------------------------------------------
	/// Returns the base object which stores general information about this translation unit as an entity definition.
	/// Ideally, this would be done by having EntityBase as superclass, but then TranslationUnit wouldn't be a standard-layout class.
	/// @return												Base object of this translation unit.
	//----------------------------------------------------------------------------------------
	const EntityBase& GetBase() const
	{
		return _super;
	}

	//----------------------------------------------------------------------------------------
	/// Returns the head of a singly linked list of all entity definitions contained in this translation unit.
	/// @return												List of entity definitions of this unit.
	//----------------------------------------------------------------------------------------
	const EntityDefinition* GetDefinitions() const
	{
		return _definitions;
	}

	//----------------------------------------------------------------------------------------
	/// Returns the next translation unit in the singly linked list of all translation units of a module.
	/// @return												Next translation unit of the module.
	//----------------------------------------------------------------------------------------
	const TranslationUnit* GetNextOfModule() const
	{
		return _nextOfModule;
	}

	//----------------------------------------------------------------------------------------
	/// Resets the translation unit object to its initial state. The initial state is the state right after the C++ initialization
	/// of non-local variables has completed. This function is invoked on shutdown of a module or the whole application
	/// to allow for a later re-initialization.
	//----------------------------------------------------------------------------------------
	void Reset()
	{
		_super.Reset();
		_initializedEntities = nullptr;
		_nextOfGroup = nullptr;
		_groupIndex = -1;
		_sccData.Reset();
	}

	TranslationUnit* PrivateInitModule(const ModuleInfo* module)
	{
		_module = module;
		return this;
	}

private:
	TranslationUnit(const TranslationUnit& src) = delete;
	TranslationUnit& operator =(const TranslationUnit& src) = default;

	void InitCopy(const TranslationUnit& src, ModuleInfo& mod);

	void AddUse(EntityUse* use);

	void AddDefinition(EntityDefinition* def);

	inline void AddOptionalUse(OptionalUse* use);

	EntityBase _super; ///< Base object with general entity information.
	TranslationUnit* _nextOfModule; ///< Next in singly linked list of translation units of module.
	const ModuleInfo* _module; ///< The info of the module which contains this unit.
	EntityDefinition* _definitions; ///< Head of singly linked list of entity definitions contained in this unit.
	EntityDefinition* _lastDefinition; ///< Tail of singly linked list of entity definitions contained in this unit.
	EntityUse* _uses; ///< Head of singly linked list of entity uses contained in this unit.
	EntityBase* _initializedEntities; ///< Head of singly linked list of initialized entity objects of this unit.
	const OptionalUse* _optionalUses; ///< Head of singly linked list of optional uses contained in this unit.

	// The next members are used only temporarily for the dependency analysis of the object system.
	mutable const TranslationUnit* _nextOfGroup;
	mutable Int _groupIndex;
	mutable SCCData _sccData;

	friend class ObjectModel;
	friend class EntityDefinition;
	friend class EntityUse;
	friend class OptionalUse;
	template <typename, typename, typename, typename, typename> friend class StronglyConnectedComponents;
};

/// @endcond

#ifndef PRIVATE_MAXON_TRANSLATIONUNIT_FLAGS
	#ifdef PRIVATE_MAXON_REGISTRATION_FRAMEWORK
		#define PRIVATE_MAXON_TRANSLATIONUNIT_FLAGS EntityBase::FLAGS::FRAMEWORK_REGISTRATION
	#else
		#define PRIVATE_MAXON_TRANSLATIONUNIT_FLAGS EntityBase::FLAGS::NONE
	#endif
#endif

// We put g_translationUnit in an anonymous namespace: Otherwise we had to use static, but then some compilers
// don't allow to use g_translationUnit as template argument.
namespace
{
#ifdef PRIVATE_MAXON_REGISTRATION_UNIT
TranslationUnit g_translationUnit{&PRIVATE_MAXON_MODULE, "register.cpp", EntityBase::FLAGS::REGISTRATION_UNIT};
#elif defined(__BASE_FILE__)
TranslationUnit g_translationUnit{&PRIVATE_MAXON_MODULE, __BASE_FILE__, PRIVATE_MAXON_TRANSLATIONUNIT_FLAGS};
#else
TranslationUnit g_translationUnit{&PRIVATE_MAXON_MODULE, "??.cpp", PRIVATE_MAXON_TRANSLATIONUNIT_FLAGS};
#endif

#ifndef MAXON_TARGET_64BIT
constexpr inline UInt64 UInt64Pow(UInt64 x, Int exp)
{
	// we don't use a simple recursion like 'return (exp == 0) ? 1 : UInt64Pow(x, exp - 1) * x;' here and in the following as this would lead to too deep recursions (the C++ spec recommends to support a depth of 512)
	return (exp == 0) ? 1 : (exp == 1) ? x : UInt64Pow(x, exp / 2) * UInt64Pow(x, exp - exp / 2);
}

constexpr inline UInt64 PrivateGetHashCode64(const char* str, Int len)
{
	return (len == 0) ? 0 : (len == 1) ? (UChar)*str : PrivateGetHashCode64(str, len / 2) * UInt64Pow(31, len - len / 2) + PrivateGetHashCode64(str + len / 2, len - len / 2);
}

static constexpr UInt64 g_translationUnitHash = PrivateGetHashCode64(__BASE_FILE__, sizeof(__BASE_FILE__) - 1);
#else
static constexpr UInt64 g_translationUnitHash = 0;
#endif
}

/// initSystemTable/InitMTable is not allowed to call thread specific methods as the thread model is not up at the point of calling
using InitMTable = void (*)();
Bool MaxonStart(int argc, char** argv, InitMTable initSystemTable);
Bool MaxonEnd();

#define PRIVATE_MAXON_DETECT_MEMBER_HELPER1(x, i, a) , x p##i
#define PRIVATE_MAXON_DETECT_MEMBER_HELPER2(x, i, a) p##i
#define PRIVATE_MAXON_DETECT_MEMBER_HELPER3(x, i, a) , p##i

//----------------------------------------------------------------------------------------
/// Example usage of this macro is MAXON_DETECT_MEMBER_HELPER(WriteTo, const char*);
/// this allows automatic detection of the WriteTo as a member or static function:
/// struct X { Bool WriteTo(const char* str) const { } };
/// or
/// struct Y {}; static Bool WriteTo(const Y& y, const char* str) { }
///
/// You can add a fallback by using overload rank 0, or further specializations with ranks starting at 3, e.g.,
/// @code
/// template <typename T> typename SFINAEHelper<Bool, ... some T-based check...>::type WriteToHelper(OverloadRank3, T& obj, const char* str);
/// @endcode
//----------------------------------------------------------------------------------------
#define MAXON_DETECT_MEMBER_HELPER(NAME, ...) \
	template <typename T> MAXON_ATTRIBUTE_FORCE_INLINE auto MAXON_CONCAT(NAME, Helper)(OverloadRank2, T& obj MAXON_MAKE_LIST(PRIVATE_MAXON_DETECT_MEMBER_HELPER1,,,, ##__VA_ARGS__)) -> decltype(obj.NAME(MAXON_MAKE_COMMA_LIST(PRIVATE_MAXON_DETECT_MEMBER_HELPER2,,, ##__VA_ARGS__))) { return obj.NAME(MAXON_MAKE_COMMA_LIST(PRIVATE_MAXON_DETECT_MEMBER_HELPER2,,, ##__VA_ARGS__)); } \
	template <typename T> MAXON_ATTRIBUTE_FORCE_INLINE auto MAXON_CONCAT(NAME, Helper)(OverloadRank1, T& obj MAXON_MAKE_LIST(PRIVATE_MAXON_DETECT_MEMBER_HELPER1,,,, ##__VA_ARGS__)) -> decltype(NAME(obj MAXON_MAKE_LIST(PRIVATE_MAXON_DETECT_MEMBER_HELPER3,,,, ##__VA_ARGS__))) { return NAME(obj MAXON_MAKE_LIST(PRIVATE_MAXON_DETECT_MEMBER_HELPER3,,,, ##__VA_ARGS__)); } \
	template <typename T> MAXON_ATTRIBUTE_FORCE_INLINE auto MAXON_CONCAT(NAME, Helper)(T& obj MAXON_MAKE_LIST(PRIVATE_MAXON_DETECT_MEMBER_HELPER1,,,, ##__VA_ARGS__)) -> decltype(MAXON_CONCAT(NAME, Helper)(OVERLOAD_MAX_RANK, obj MAXON_MAKE_LIST(PRIVATE_MAXON_DETECT_MEMBER_HELPER3,,,, ##__VA_ARGS__))) { return MAXON_CONCAT(NAME, Helper)(OVERLOAD_MAX_RANK, obj MAXON_MAKE_LIST(PRIVATE_MAXON_DETECT_MEMBER_HELPER3,,,, ##__VA_ARGS__)); }

#if defined(MAXON_COMPILER_INTEL) || defined(MAXON_COMPILER_GCC) || defined(MAXON_COMPILER_CLANG)
	template <typename T> MAXON_ATTRIBUTE_FORCE_INLINE auto GetMemorySizeHelper(OverloadRank2, T& obj) -> decltype(obj.GetMemorySize()) { return obj.GetMemorySize(); }
// TODO: (Ole) Intel and GCC compilers doesn't work with the following line (SFINAE for expressions not well supported), check newer compiler versions
//	template <typename T> MAXON_ATTRIBUTE_FORCE_INLINE auto GetMemorySizeHelper(OverloadRank1, T& obj) -> decltype(GetMemorySize(obj)) { return GetMemorySize(obj); }
	template <typename T> MAXON_ATTRIBUTE_FORCE_INLINE auto GetMemorySizeHelper(T& obj) -> Int { return GetMemorySizeHelper(OVERLOAD_MAX_RANK, obj); }
#else
	MAXON_DETECT_MEMBER_HELPER(GetMemorySize);
#endif

template <typename T> MAXON_ATTRIBUTE_FORCE_INLINE Int GetMemorySizeHelper(OverloadRank0, T&)
{
	return SIZEOF(T);
}

//----------------------------------------------------------------------------------------
/// UseVariable creates a little bit of code that makes sure that you won't get a warning for an unused variable.
/// or the unused return value of an expression. You can also use this macro to make sure a speed test is not
/// removed by the compiler, otherwise the example would be completely removed by the compiler's optimizer.
/// <B> Please note that UseVariable will create a little bit of extra code, therefore do not use it in speed critical code. </B>
/// @code
/// Float sum = 0.0;
/// for (Int64 i = 0; i < 10000000; i++)
/// {
/// 	sum += Sin((Float)i);
/// }
/// UseVariable(sum);
/// @endcode
//----------------------------------------------------------------------------------------
template <typename X> MAXON_ATTRIBUTE_FORCE_INLINE void UseVariable(X&& var)
{
	if (MAXON_UNLIKELY((Int)&var == 8))
		__debugbreak();
}

#ifdef USE_API_MAXON
	// make sure that we don't need the namespace
	#define UseVariable	maxon::UseVariable
#endif


/// @}

} // namespace maxon

// The NullValue template is a useful helper to return a null value of a generic type
#include "maxon/nullvalue.h"

namespace maxon
{


//----------------------------------------------------------------------------------------
/// This enum is used for DataType as a classification of the kind of values
/// which the DataType represents. Actual values are composed of several flags.
//----------------------------------------------------------------------------------------
enum class VALUEKIND : UInt64
{
	NONE										= 0,

	VOID_TYPE								= 1LL << 0,		///< The data type represents the void type.
	GENERIC									= 1LL << 1,		///< The data type represents the Generic type.
	GENERIC_ARITHMETIC			= 1LL << 2,		///< The data type is the abstract base type of all arithmetic types.
	SCALAR									= 1LL << 3,		///< The type is a scalar type.
	INTEGRAL								= 1LL << 4,		///< The type is an integral type (that doesn't include enumeration types).
	FLOATING_POINT					= 1LL << 5,		///< The type is a floating point type.
	ENUM										= 1LL << 6,		///< The data type is an unnamed enum type created by DataTypeLib::GetEnumType().
	ENUM_LIST								= 1LL << 7,		///< The data type is an enum registered with one of the MAXON_ENUM_LIST macros.
	ENUM_FLAGS							= 1LL << 8,		///< The data type is an enum registered with one of the MAXON_ENUM_FLAGS macros.
	DATA										= 1LL << 9,		///< The data type is Data.
	DATAPTR									= 1LL << 10,	///< The data type is one of ConstDataPtr, DataPtr, MoveDataPtr or ForwardingDataPtr.
	NONVIRTUAL_INTERFACE		= 1LL << 11,	///< The data type is a non-virtual interface.
	VIRTUAL_INTERFACE				= 1LL << 12,	///< The data type consists of a set of virtual interfaces.

	REF_OR_POINTER					= 1LL << 13,	///< This flag is set for a BaseRef-like reference or a pointer.
	POINTER									= 1LL << 14,	///< The data type is an ordinary C++ pointer, or a BaseRef with raw pointer semantics, or a C++ reference (then one of LV_REFERENCE or RV_REFERENCE is also set).
	STRONG_REFERENCE				= 1LL << 15,	///< The data type is a BaseRef with non-copy-on-write reference-counting semantics.
	COW_REFERENCE						= 1LL << 16,	///< The data type is a BaseRef with copy-on-write semantics.
	UNIQUE_REFERENCE				= 1LL << 17,	///< The data type is a BaseRef with unique ownership, i.e., the referenced object will be freed on destruction of the BaseRef.
	ACOW_REFERENCE					= 1LL << 18,	///< The data type is a BaseRef with always-copy-on-write semantics.

	LV_REFERENCE						= 1LL << 19,	///< The type is an l-value reference type. This flag can only be set in conjunction with POINTER, i.e., C++ references are treated as special pointers.
	RV_REFERENCE						= 1LL << 20,	///< The type is an r-value reference type. This flag can only be set in conjunction with POINTER, i.e., C++ references are treated as special pointers.

	TUPLE										= 1LL << 21,	///< The data type is a TupleDataType with unnamed members created by ParametricTypes::Tuple.
	NAMED_TUPLE							= 1LL << 22,	///< The data type is a TupleDataType with named members created by ParametricTypes::Tuple.
	STRUCT									= 1LL << 23,	///< The data type has an underlying TupleDataType with named members.

	SIMD										= 1LL << 24,	///< The data type is a SimdElementType. Such a type has a special memory layout where consecutive elements overlap in memory.

	BLOCK										= 1LL << 25,	///< The data type is a Block.
	STRIDED_BLOCK						= 1LL << 26,	///< The data type is a strided Block.

	ARRAY										= 1LL << 27,	///< The data type is an ArrayInterface type obtained by DataType::GetArrayType().
	BASEARRAY								= 1LL << 28,	///< The data type is a BaseArray type.
	BLOCKARRAY							= 1LL << 29,	///< The data type is a BlockArray type.

	RESULT									= 1LL << 30,	///< The data type is a Result.

	DELEGATE								= 1LL << 31,	///< The type is a DelegateDataType.
	FUNCTION								= 1LL << 32,	///< The type is a FunctionDataType (i.e., a GenericFunction bound to input and output types).

	CONST_QUALIFIED					= 1LL << 33,	///< The type is const-qualified.
	OPAQUE_QUALIFIED				= 1LL << 34,	///< The type is opaque-qualified.

	SOURCE_LEVEL						= 1LL << 35,	///< The data type is a type at sourcecode level which is represented by a different architecture- and version-dependent type at runtime.

	DEEP_CONSTNESS					= 1LL << 36,	///< The data type obeys deep constness.
	INT_SIZE_OR_LESS				= 1LL << 37,	///< Values of the data type fit into an Int.
	ZERO_INITIALIZED				= 1LL << 38,	///< Values of the data type are initialized with zeroes by their default constructor, also set for scalar types.
	ORDERED									= 1LL << 39,	///< Values of the data type are ordered (DataType::Compare can be used and implements a total order).
	TRIVIALLY_CONSTRUCTIBLE	= 1LL << 40,	///< Values of the data type are trivially constructible.
	TRIVIALLY_DESTRUCTIBLE	= 1LL << 41,	///< Values of the data type are trivially destructible.
	TRIVIALLY_COPYABLE			= 1LL << 42,	///< Values of the data type are trivially copyable.
	TRIVIALLY_EQUATABLE			= 1LL << 43,	///< Values of the data type are trivially equatable (see IsTriviallyEquatable).
	OBJECT_REF							= 1LL << 44,	///< This flag is set for a reference or pointer to a virtual object.
	VALUE										= 1LL << 45,	///< This flag is set if the type is a value type (such as a scalar, a COW reference or a tuple or array of value types).
	ELEMENT_TYPE_AS_ARG			= 1LL << 46,	///< This flag is set for a parametric type which uses the element type to store the type arguments of the instantiation.
	NEVER_NULLPTR						= 1LL << 47,	///< This flag is set for pointer or reference types which never hold a nullptr value.
	SIGNED									= 1LL << 48,	///< This flag is set for floating point and signed integer types.

	CONTAINER								= 1LL << 54,	///< The data type is a ContainerDataType.
	STATIC_ARRAY_CONTAINER	= 1LL << 55,	///< The data type is a StaticArrayContainerDataType.
	ARRAY_CONTAINER					= 1LL << 56,	///< The data type is an ArrayContainerDataType.
	CONTAINER_REF						= 1LL << 57,	///< The data type is a reference type of a container type.
	GENERIC_CONTAINER				= 1LL << 58,	///< This flag may be set for container types to indicate generic members.

	COW_MASK = COW_REFERENCE | ACOW_REFERENCE, ///< Test mask to check for copy-on-write reference semantics.
	STRONG_MASK = STRONG_REFERENCE | COW_MASK, ///< Test mask to check for reference counting semantics.
	PTR_MASK = POINTER | UNIQUE_REFERENCE | STRONG_MASK, ///< Test mask any kind of pointer/reference.
	ARRAY_CONTAINER_MASK = STATIC_ARRAY_CONTAINER | ARRAY_CONTAINER,
	DERIVED_CONTAINER_MASK = ARRAY_CONTAINER_MASK,
	CONTAINER_MASK = CONTAINER | DERIVED_CONTAINER_MASK,

	CONTAINER_OR_REF = CONTAINER_MASK | CONTAINER_REF,
	REFERENCE_MASK = LV_REFERENCE | RV_REFERENCE,

	ARITHMETIC_MASK				= INTEGRAL | FLOATING_POINT, ///< Test mask for concrete arithmetic types.
	TUPLE_MASK						= TUPLE | NAMED_TUPLE,

	TUPLE_INHERIT_MASK = ZERO_INITIALIZED | TRIVIALLY_CONSTRUCTIBLE | TRIVIALLY_DESTRUCTIBLE | TRIVIALLY_COPYABLE | TRIVIALLY_EQUATABLE | ORDERED | VALUE,

	POINTER_FLAGS = POINTER | SCALAR | ZERO_INITIALIZED | TRIVIALLY_DESTRUCTIBLE | TRIVIALLY_COPYABLE | TRIVIALLY_EQUATABLE | INT_SIZE_OR_LESS | REF_OR_POINTER, ///< The VALUEKIND of a pointer.
	QUALIFIER_MASK = CONST_QUALIFIED | OPAQUE_QUALIFIED

} MAXON_ENUM_FLAGS(VALUEKIND, "net.maxon.datatype.enum.valuekind", EARLY);

#define MAXON_IS_COW_KIND(kind) ((maxon::UInt64(kind) & maxon::UInt64(maxon::VALUEKIND::COW_MASK)) != 0) // int cast needed as workaround for MSVC bug when used in SFINAE contexts

template <typename T, Bool REF> struct ValueKindHelper
{
	static const VALUEKIND KIND = ConditionalFlag(std::is_trivially_copyable<T>::value, VALUEKIND::TRIVIALLY_COPYABLE)
#ifndef MAXON_COMPILER_GCC
		| ConditionalFlag(std::is_trivially_constructible<T>::value, VALUEKIND::TRIVIALLY_CONSTRUCTIBLE)
#endif
		| ConditionalFlag(std::is_trivially_destructible<T>::value, VALUEKIND::TRIVIALLY_DESTRUCTIBLE)
		| ConditionalFlag(std::is_scalar<T>::value, VALUEKIND::SCALAR)
		| ConditionalFlag(std::is_integral<T>::value, VALUEKIND::INTEGRAL | VALUEKIND::VALUE)
		| ConditionalFlag(std::is_signed<T>::value, VALUEKIND::SIGNED)
		| ConditionalFlag(std::is_floating_point<T>::value, VALUEKIND::FLOATING_POINT | VALUEKIND::VALUE)
		| ConditionalFlag(IsTriviallyEquatable<T>::value, VALUEKIND::TRIVIALLY_EQUATABLE)
		| ConditionalFlag(IsZeroInitialized<T>::value, VALUEKIND::ZERO_INITIALIZED)
		| ConditionalFlag(SIZEOF(T) <= SIZEOF(Int), VALUEKIND::INT_SIZE_OR_LESS);
};

template <typename T, Bool REF> struct ValueKindHelper<T*, REF>
{
	static const VALUEKIND KIND = VALUEKIND::POINTER_FLAGS;
};

template <typename T> struct ValueKindHelper<T, true>
{
	static const VALUEKIND KIND = T::Handler::KIND;
};

template <> struct ValueKindHelper<ObjectInterface, false>
{
	static const VALUEKIND KIND = VALUEKIND::VIRTUAL_INTERFACE;
};


//----------------------------------------------------------------------------------------
/// Possible kinds of a collection.
/// @see GetCollectionKind
//----------------------------------------------------------------------------------------
enum class COLLECTION_KIND
{
	NONE,		///< Not a collection.
	ARRAY,	///< The collection is an array.
	SET,		///< The collection is a set.
	MAP			///< The collection is a map.
} MAXON_ENUM_LIST(COLLECTION_KIND);

//----------------------------------------------------------------------------------------
/// This type trait determines the type of collection. If @p COLLECTION is an array, map or set,
/// the static member @c value will be the corresponding COLLECTION_KIND value, otherwise
/// it will be COLLECTION_KIND::NONE.
/// E.g., <tt>%GetCollectionKind<BaseArray<Int>>::%value == %COLLECTION_KIND::%ARRAY</tt> is true.
//----------------------------------------------------------------------------------------
template <typename COLLECTION, typename ENABLE = void> class GetCollectionKind
{
public:
	static const COLLECTION_KIND value = COLLECTION_KIND::NONE;
};

}

// Result class and helpers.
#include "maxon/utilities/resultbase.h"

#include "maxon/utilities/newobj.h"

namespace maxon
{

/// @addtogroup DATATYPE
/// @{


template <typename T> decltype(std::declval<T>().CopyFrom(std::declval<const T&>())) TestForCopyFromFunction(OverloadRank1);	// template argument can only be deduced if T contains a CopyFrom() method
template <typename T> std::false_type TestForCopyFromFunction(OverloadRank0);		// default case for classes without CopyFrom()

//----------------------------------------------------------------------------------------
/// Automatic detection of CopyFrom() method using SFINAE.
/// If a class implements CopyFrom(T& src) the constant TestForCopyFromMember<T>::isSupported
/// will be true.
//----------------------------------------------------------------------------------------
template <typename T> struct TestForCopyFromMember
{
	static const bool isSupported = MAXON_HAS_TRUE_TYPE(TestForCopyFromFunction<typename std::decay<T>::type>(OVERLOAD_MAX_RANK));
	static_assert(!(isSupported && std::is_copy_constructible<T>::value), "Class T has both a CopyFrom function and a copy constructor.");
};

#if defined(MAXON_COMPILER_INTEL) || defined(MAXON_COMPILER_MSVC) // Compilers don't handle correctly the deleted CopyFrom-function of Block
template <typename T, Bool STRIDED, Bool MOVE> struct TestForCopyFromMember<Block<T, STRIDED, MOVE>>
{
	static const bool isSupported = false;
};
#endif

// for classes with complex copy constructor (implements CopyFrom() and move constructor)
template <typename T, Bool hasCopyFrom> class ObjectConstructor
{
public:
	//----------------------------------------------------------------------------------------
	/// Constructs an object using CopyFrom() (like new (dst) T(src) but with error check)
	/// If copy construction fails the object will be automatically destructed, dst will
	/// point to uninitialized memory like before the call.
	/// @param[out] dst								Copied object will be placed here.
	/// @param[in] src								Object to be copied.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	static Result<void> Copy(T& dst, const T& src)
	{
		// Default initialize T.
		new (&dst) T();

		Result<void> res = dst.CopyFrom(src);
		if (res == FAILED)
		{
			// Copy failed: destruct.
			dst.~T();
			return res;
		}

		return OK;
	}

	//----------------------------------------------------------------------------------------
	/// Copy assignment using CopyFrom()
	/// @param[out] dst								Copy will be placed here (dst must have already been constructed)
	/// @param[in] src								Object to be moved.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	template <typename U> static MAXON_ATTRIBUTE_FORCE_INLINE Result<void> AssignCopy(T& dst, const U& src)
	{
		return dst.CopyFrom(src);
	}

	// needed for MAXON_IMPLEMENTATION
	static MAXON_ATTRIBUTE_FORCE_INLINE T* Alloc(void* mem, const T& src)
	{
		if (!mem)
			return nullptr;
		T* dst = new (mem) T();
		if (dst->CopyFrom(src) == FAILED)
		{
			dst->~T();
			return nullptr;
		}
		return dst;
	}

	// needed for MAXON_IMPLEMENTATION
	template <typename SRC> static MAXON_ATTRIBUTE_FORCE_INLINE T* Alloc(void* mem, SRC&& src)
	{
		return new (mem) T(std::forward<SRC>(src));
	}
};

// for classes with copy constructor that cannot fail (may or may not support move semantics)
template <typename T> class ObjectConstructor<T, false>
{
public:
	//----------------------------------------------------------------------------------------
	/// Constructs an object using new (dst) T(src), cannot fail.
	/// @param[out] dst								Copied object will be placed here.
	/// @param[in] src								Object to be copied.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	static MAXON_ATTRIBUTE_FORCE_INLINE ResultOk<void> Copy(T& dst, const T& src)
	{
		new (&dst) T(src);
		return OK;
	}

	//----------------------------------------------------------------------------------------
	/// Copy assignment, cannot fail.
	/// @param[out] dst								Copy will be placed here (dst must have already been constructed)
	/// @param[in] src								Object to be copied.
	/// @return												Always true.
	//----------------------------------------------------------------------------------------
	template <typename U> static MAXON_ATTRIBUTE_FORCE_INLINE ResultOk<void> AssignCopy(T& dst, const U& src)
	{
		dst = src;
		return OK;
	}

	//----------------------------------------------------------------------------------------
	/// needed for MAXON_IMPLEMENTATION
	/// @param[out] mem								Object will be constructed here (can be nullptr).
	/// @param[in] src								Object to be moved or copied.
	//----------------------------------------------------------------------------------------
	template <typename SRC> static MAXON_ATTRIBUTE_FORCE_INLINE T* Alloc(void* mem, SRC&& src)
	{
		if (MAXON_UNLIKELY(mem == nullptr))
			return nullptr;
		return new (mem) T(std::forward<SRC>(src));
	}
};


//----------------------------------------------------------------------------------------
/// Calls new (&dst) T(src) or dst.CopyFrom(src) for non-trivial objector copy constructor.
//----------------------------------------------------------------------------------------
template <typename T> MAXON_ATTRIBUTE_FORCE_INLINE Result<void> NewCopy(T& dst, const T& src)
{
	return ObjectConstructor<T, TestForCopyFromMember<T>::isSupported>::Copy(dst, src);
}

template <typename T> MAXON_ATTRIBUTE_FORCE_INLINE ResultOk<void> NewCopy(T& dst, T&& src)
{
	new (&dst) T(std::move(src));
	return OK;
}

template <typename T> MAXON_ATTRIBUTE_FORCE_INLINE Result<T> NewCopy(const T& src)
{
	T dst;
	if (ObjectConstructor<T, TestForCopyFromMember<T>::isSupported>::Copy(dst, src) == FAILED)
		return CreateError(MAXON_SOURCE_LOCATION, ERROR_TYPE::OUT_OF_MEMORY);
	return std::move(dst);
}

template <typename T> MAXON_ATTRIBUTE_FORCE_INLINE ResultOk<T> NewCopy(T&& src)
{
	return T(std::move(src));
}

//----------------------------------------------------------------------------------------
/// Copy assignment
//----------------------------------------------------------------------------------------
template <typename T> MAXON_ATTRIBUTE_FORCE_INLINE typename std::conditional<TestForCopyFromMember<T>::isSupported, Result<void>, ResultOk<void>>::type AssignCopy(T& dst, const T& src)
{
	return ObjectConstructor<T, TestForCopyFromMember<T>::isSupported>::AssignCopy(dst, src);
}

template <typename T> MAXON_ATTRIBUTE_FORCE_INLINE ResultOk<void> AssignCopy(T& dst, T&& src)
{
	dst = std::move(src);
	return OK;
}

//----------------------------------------------------------------------------------------
/// Converting copy assignment
//----------------------------------------------------------------------------------------
template <typename T, typename U> MAXON_ATTRIBUTE_FORCE_INLINE Result<void> AssignCopyConvert(T& dst, const U& src)
{
	return ObjectConstructor<T, TestForCopyFromMember<T>::isSupported>::AssignCopy(dst, src);
}

template <typename T, typename U> MAXON_ATTRIBUTE_FORCE_INLINE ResultOk<void> AssignCopyConvert(T& dst, U&& src)
{
	dst = std::move(src);
	return OK;
}

//----------------------------------------------------------------------------------------
/// Destructs the object.
/// @tparam T											Type of object.
/// @param[out] object						The object to destruct.
//----------------------------------------------------------------------------------------
template <typename T> inline void Destruct(T* object)
{
	object->~T();
}

//----------------------------------------------------------------------------------------
/// Resets the object to the state of a default-constructed T.
/// This function destructs obj and then default-constructs a new T in place.
/// @tparam T											Type of object.
/// @param[out] object						The object to reset.
//----------------------------------------------------------------------------------------
template <typename T> inline void Reset(T& object)
{
	static_assert(!std::is_polymorphic<T>::value, "Reset is not supported for polymorphic types.");
	object.T::~T();
	new (&object) T();
}


//----------------------------------------------------------------------------------------
/// AlignedStorage<SIZE, ALIGN> is a trivial standard-layout class which has the given size and alignment.
/// It is a replacement for std::aligned_storage<SIZE, ALIGN>::type with the benefit that
/// the usual implementation of std::aligned_storage makes some compilers produce extra stack protector
/// code which often if superfluous. AlignedStorage avoids this, so you should prefer AlignedStorage
/// if you are sure that no invalid memory access can happen.
//----------------------------------------------------------------------------------------
template <Int SIZE, Int ALIGN> struct AlignedStorage
{
	// We use EmptyClass instead of char (which is typically used by std::aligned_storage)
	// because by default only char triggers the creation of stack protector code.
	static_assert(SIZEOF(EmptyClass) == 1, "Wrong size of EmptyClass");
	alignas(ALIGN) EmptyClass _data[SIZE];
};


//----------------------------------------------------------------------------------------
/// Use this class when you need a default argument for parameters of type Bool&.
/// As an example, consider a function which adds elements to some set:
/// @code
/// Result<void> Add(Element* e, Bool& added = BoolLValue());
/// @endcode
/// @c e could already exist before in the set, so @c added is set to indicate if @c e was really added.
/// If you as a caller are not interested in this, the default argument helps to provide
/// a valid temporary lvalue object.
//----------------------------------------------------------------------------------------
class BoolLValue
{
public:
	operator Bool&() { return _value; }

private:
	Bool _value;
};

//----------------------------------------------------------------------------------------
/// Marks a block of code that is scoped for a certain reason.
/// @code
/// MAXON_SCOPE // do whatever you want
/// {
///   ScopedLock lock(lock);
///   ... more code ...
/// }
/// @endcode
//----------------------------------------------------------------------------------------
#define MAXON_SCOPE


//----------------------------------------------------------------------------------------
/// Marks a function so that the source processor doesn't issue a warning if the function
/// length exceeds the line count limit. This should really only be used where it doesn't
/// make sense to split up the function into smaller pieces, such as the initialization of
/// tables.
/// @code
/// MAXON_WARN_MUTE_FUNCTION_LENGTH Result<void> InitTranslationTable()
/// {
///   ... really long function ...
/// }
/// @endcode
//----------------------------------------------------------------------------------------
#define MAXON_WARN_MUTE_FUNCTION_LENGTH


//----------------------------------------------------------------------------------------
/// Marks a declaration so that the source processor doesn't issue a warning if the declaration
/// violates the naming conventions of the style guide.
/// @code
/// MAXON_WARN_MUTE_NAMING TIFFErrorHandler _TIFFwarningHandler = nullptr;
/// @endcode
//----------------------------------------------------------------------------------------
#define MAXON_WARN_MUTE_NAMING

/// @}

#ifndef MAXON_TARGET_UNITY_MODE
	#define MAXON_TARGET_UNITY_MODE 0
#endif

#ifdef MAXON_API
	#define PRIVATE_MAXON_REGISTER_CHECK(NAME) static_assert(false, NAME " must not be used in frameworks.");
#else
	#define PRIVATE_MAXON_REGISTER_CHECK(NAME) static_assert(MAXON_TARGET_UNITY_MODE == 0, NAME " must not happen in unity builds. make sure you exclude the cpp file from the unity build.");
#endif


} // namespace maxon

// All literals must be also accessible outside of the maxon namespace.
using maxon::operator "" _s;

// _f has to be redefined due to a bug in XCode.
constexpr inline maxon::Float operator "" _f(long double f)
{
	return maxon::Float(f);
}


#endif // APIBASE_H__
