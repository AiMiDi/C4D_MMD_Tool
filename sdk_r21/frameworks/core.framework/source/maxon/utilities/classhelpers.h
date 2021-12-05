#ifndef CLASSHELPERS_H__
#define CLASSHELPERS_H__

#ifndef APIBASE_H__
	#error "Do not include this file directly"
#endif

/// @file
/// Class helper macros and templates

namespace maxon
{

/// @addtogroup SYSTEM
/// @{
/// @cond IGNORE

#ifdef MAXON_TARGET_DEBUG
	//----------------------------------------------------------------------------------------
	/// This macro can be used to insert different code for debug/release configurations:
	/// In debug configuration (MAXON_TARGET_DEBUG is set) the macro gets replaced by DEBUG, otherwise by RELEASE.
	/// Unlike the usual approach with `\#ifdef`, this macro allows conditional code in a single line. The
	/// following example uses this to avoid a warning about an unused variable in release configuration.
	/// @code
	/// MAXON_IF_TARGET_DEBUG(Int bs =, ) array->GetBlock(m, 0, block);
	/// DebugAssert(bs == 0);
	/// @endcode
	/// @param[in] DEBUG							Code to be inserted in debug configuration.
	/// @param[in] RELEASE						Code to be inserted in release configuration.
	/// @return												The code to be inserted, depending on the build configuration.
	//----------------------------------------------------------------------------------------
	#define MAXON_IF_TARGET_DEBUG(DEBUG, RELEASE) DEBUG
#else
	#define MAXON_IF_TARGET_DEBUG(DEBUG, RELEASE) RELEASE
#endif

#define MAXON_IF_SOURCEPROCESSOR(SRC, ...) __VA_ARGS__

#define MAXON_IF_SNIPPET(SNIPPET, ...) __VA_ARGS__

//----------------------------------------------------------------------------------------
/// This macro converts the given expression into a string
/// e.g. MAXON_STRINGIFY(5) => "5"
//----------------------------------------------------------------------------------------
#define MAXON_STRINGIFY(s) PRIVATE_MAXON_STRINGIFY(s)
#define PRIVATE_MAXON_STRINGIFY(s) #s

//----------------------------------------------------------------------------------------
/// This macro concats x and y into a single preprocessor token. You can use this instead of x##y if x or y
/// are macros themselves. E.g., with
/// @code
/// #define TMPNAME tmp##__LINE__
/// @endcode
/// the macro TMPNAME gets expanded into tmp__LINE__, while
/// @code
/// #define TMPNAME MAXON_CONCAT(tmp, __LINE__)
/// @endcode
/// expands into a token such as tmp42.
/// @param[in] x									First argument for the concatenation.
/// @param[in] y									Second argument for the concatenation.
/// @return												Concatenated token.
//----------------------------------------------------------------------------------------
#define MAXON_CONCAT(x, y) PRIVATE_MAXON_CONCAT(x, y)
#define PRIVATE_MAXON_CONCAT(x, y) x##y


//----------------------------------------------------------------------------------------
/// This macro removes its first argument and passes the remaining ones. You have to enclose it within MAXON_EXPAND
/// as in <tt>MAXON_EXPAND(MAXON_ALLBUTFIRST(__VA_ARGS__))</tt>,
/// otherwise it won't work for the preprocessor of MSVC.
/// @param[in] X									First argument which will be discarded.
/// @param[in] ...								Remaining arguments which will be returned.
/// @return												All arguments but the first.
//----------------------------------------------------------------------------------------
#define MAXON_ALLBUTFIRST(X, ...) __VA_ARGS__

//----------------------------------------------------------------------------------------
/// This macro removes all arguments but the first.
/// @param[in] ...								__VA_ARGS__ input from where the first arg will be returned.
/// @return												The first argument.
//----------------------------------------------------------------------------------------
#define MAXON_FIRSTARG(...) MAXON_EXPAND(MAXON_FIRSTARG_A(__VA_ARGS__))
#define MAXON_FIRSTARG_A(first, ...) first

//----------------------------------------------------------------------------------------
/// This macro expands to its second argument.
/// @param[in] ...								__VA_ARGS__ input from where the second arg will be returned.
/// @return												The second argument.
//----------------------------------------------------------------------------------------
#define MAXON_SECONDARG(...) MAXON_EXPAND(MAXON_SECONDARG_A(__VA_ARGS__))
#define MAXON_SECONDARG_A(first, second, ...) second

//----------------------------------------------------------------------------------------
/// This macro expands to its third argument.
/// @param[in] ...								__VA_ARGS__ input from where the third arg will be returned.
/// @return												The third argument.
//----------------------------------------------------------------------------------------
#define MAXON_THIRDARG(...) MAXON_EXPAND(MAXON_THIRDARG_A(__VA_ARGS__))
#define MAXON_THIRDARG_A(first, second, third, ...) third

//----------------------------------------------------------------------------------------
/// This macro expands to its fourth argument.
/// @param[in] ...								__VA_ARGS__ input from where the fourth arg will be returned.
/// @return												The fourth argument.
//----------------------------------------------------------------------------------------
#define MAXON_FOURTHARG(...) MAXON_EXPAND(MAXON_FOURTHARG_A(__VA_ARGS__))
#define MAXON_FOURTHARG_A(first, second, third, fourth, ...) fourth

//----------------------------------------------------------------------------------------
/// Sometimes needed when MSVC wouldn't expand __VA_ARGS__ properly otherwise.
/// E.g., in MAXON_ALLBUTFIRST(__VA_ARGS__) MSVC uses the complete content of __VA_ARGS__ for the first X-parameter of
/// MAXON_ALLBUTFIRST, instead of just the first argument of __VA_ARGS__.
/// MAXON_EXPAND(MAXON_ALLBUTFIRST(__VA_ARGS__)) solves this problem.
//----------------------------------------------------------------------------------------
#define MAXON_EXPAND(X) X

/// Returns the 16th argument.
#define MAXON_ARG16(_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, ...) _16

/// Returns the 32th argument.
#define MAXON_ARG32(_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, ...) _32

/// Returns the 48th argument.
#define MAXON_ARG48(_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, ...) _48


//----------------------------------------------------------------------------------------
/// Variadic macro which returns the number of arguments.
/// @param[in] ...								Arguments to be counted, this also supports an empty list which will return 0.
/// @return												Number of arguments in the list.
//----------------------------------------------------------------------------------------
#if defined MAXON_COMPILER_MSVC || defined MAXON_COMPILER_INTEL
	#define MAXON_VA_NARGS(...) PRIVATE_MAXON_VA_NARGS((PRIVATE_MAXON_VA_NARGS_PREFIX_##__VA_ARGS__##PRIVATE_MAXON_VA_NARGS_POSTFIX, 47, 46, 45, 44, 43, 42, 41, 40, 39, 38, 37, 36, 35, 34, 33, 32, 31, 30, 29, 28, 27, 26, 25, 24, 23, 22, 21, 20, 19, 18, 17, 16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0))
	#define PRIVATE_MAXON_VA_NARGS(X) MAXON_ARG48 X
	#define PRIVATE_MAXON_VA_NARGS_PREFIX_PRIVATE_MAXON_VA_NARGS_POSTFIX ,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,, 0
#else
	#define MAXON_VA_NARGS(...) MAXON_EXPAND(MAXON_ARG48(, ##__VA_ARGS__, 46, 45, 44, 43, 42, 41, 40, 39, 38, 37, 36, 35, 34, 33, 32, 31, 30, 29, 28, 27, 26, 25, 24, 23, 22, 21, 20, 19, 18, 17, 16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0))
#endif

//----------------------------------------------------------------------------------------
/// Variadic macro which returns if the macro has 0 or at least one argument.
/// @param[in] ...								Arguments to be counted, this also supports an empty list which will return 0. otherwise 1.
/// @return												0 or 1.
//----------------------------------------------------------------------------------------
#if defined MAXON_COMPILER_MSVC || defined MAXON_COMPILER_INTEL
	#define MAXON_VA_ARGS_POPULATED(...) PRIVATE_MAXON_VA_NARGS((PRIVATE_MAXON_VA_NARGS_PREFIX_##__VA_ARGS__##PRIVATE_MAXON_VA_NARGS_POSTFIX, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0))
#else
	#define MAXON_VA_ARGS_POPULATED(...) MAXON_EXPAND(MAXON_ARG48(, ##__VA_ARGS__, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0))
#endif

//----------------------------------------------------------------------------------------
/// This macro gets replaced by a comma. You can use it when a macro argument shall contain a comma, because
/// in this case the preprocessor would treat the comma as an argument delimiter.
//----------------------------------------------------------------------------------------
#define MAXON_COMMA ,


// needed for MAXON_MACROARG_TYPE
template <typename T> struct MacroArgTypeHelper;

template <typename T> struct MacroArgTypeHelper<void(T)>
{
	using type = T;
};

template <typename T> using MacroArgType = typename MacroArgTypeHelper<T>::type;

//----------------------------------------------------------------------------------------
/// Use this macro if you have to use a type containing commas (such as BlockArray<Int, 10>)
/// in a macro argument:
/// @code
/// MYMACRO(MAXON_MACROARG_TYPE(BlockArray<Int, 10>))
/// @endcode
/// Without MAXON_MACROARG_TYPE, the preprocessor would see two arguments for MYMACRO,
/// namely <tt>BlockArray<Int</tt> and <tt>10></tt>.
//----------------------------------------------------------------------------------------
#define MAXON_MACROARG_TYPE(...) maxon::MacroArgType<void(__VA_ARGS__)>


#define PRIVATE_MAXON_MAKE_LIST0(F, ARG, SEP, EMPTY, ...) EMPTY
#define PRIVATE_MAXON_MAKE_LIST1(F, ARG, SEP, EMPTY, X0) F(X0, 0, ARG)
#define PRIVATE_MAXON_MAKE_LIST2(F, ARG, SEP, EMPTY, X0, X1) F(X0, 0, ARG) SEP F(X1, 1, ARG)
#define PRIVATE_MAXON_MAKE_LIST3(F, ARG, SEP, EMPTY, X0, X1, X2) F(X0, 0, ARG) SEP F(X1, 1, ARG) SEP F(X2, 2, ARG)
#define PRIVATE_MAXON_MAKE_LIST4(F, ARG, SEP, EMPTY, X0, X1, X2, X3) F(X0, 0, ARG) SEP F(X1, 1, ARG) SEP F(X2, 2, ARG) SEP F(X3, 3, ARG)
#define PRIVATE_MAXON_MAKE_LIST5(F, ARG, SEP, EMPTY, X0, X1, X2, X3, X4) F(X0, 0, ARG) SEP F(X1, 1, ARG) SEP F(X2, 2, ARG) SEP F(X3, 3, ARG) SEP F(X4, 4, ARG)
#define PRIVATE_MAXON_MAKE_LIST6(F, ARG, SEP, EMPTY, X0, X1, X2, X3, X4, X5) F(X0, 0, ARG) SEP F(X1, 1, ARG) SEP F(X2, 2, ARG) SEP F(X3, 3, ARG) SEP F(X4, 4, ARG) SEP F(X5, 5, ARG)
#define PRIVATE_MAXON_MAKE_LIST7(F, ARG, SEP, EMPTY, X0, X1, X2, X3, X4, X5, X6) F(X0, 0, ARG) SEP F(X1, 1, ARG) SEP F(X2, 2, ARG) SEP F(X3, 3, ARG) SEP F(X4, 4, ARG) SEP F(X5, 5, ARG) SEP F(X6, 6, ARG)
#define PRIVATE_MAXON_MAKE_LIST8(F, ARG, SEP, EMPTY, X0, X1, X2, X3, X4, X5, X6, X7) F(X0, 0, ARG) SEP F(X1, 1, ARG) SEP F(X2, 2, ARG) SEP F(X3, 3, ARG) SEP F(X4, 4, ARG) SEP F(X5, 5, ARG) SEP F(X6, 6, ARG) SEP F(X7, 7, ARG)
#define PRIVATE_MAXON_MAKE_LIST9(F, ARG, SEP, EMPTY, X0, X1, X2, X3, X4, X5, X6, X7, X8) F(X0, 0, ARG) SEP F(X1, 1, ARG) SEP F(X2, 2, ARG) SEP F(X3, 3, ARG) SEP F(X4, 4, ARG) SEP F(X5, 5, ARG) SEP F(X6, 6, ARG) SEP F(X7, 7, ARG) SEP F(X8, 8, ARG)
#define PRIVATE_MAXON_MAKE_LIST10(F, ARG, SEP, EMPTY, X0, X1, X2, X3, X4, X5, X6, X7, X8, X9) F(X0, 0, ARG) SEP F(X1, 1, ARG) SEP F(X2, 2, ARG) SEP F(X3, 3, ARG) SEP F(X4, 4, ARG) SEP F(X5, 5, ARG) SEP F(X6, 6, ARG) SEP F(X7, 7, ARG) SEP F(X8, 8, ARG) SEP F(X9, 9, ARG)
#define PRIVATE_MAXON_MAKE_LIST11(F, ARG, SEP, EMPTY, X0, X1, X2, X3, X4, X5, X6, X7, X8, X9, X10) F(X0, 0, ARG) SEP F(X1, 1, ARG) SEP F(X2, 2, ARG) SEP F(X3, 3, ARG) SEP F(X4, 4, ARG) SEP F(X5, 5, ARG) SEP F(X6, 6, ARG) SEP F(X7, 7, ARG) SEP F(X8, 8, ARG) SEP F(X9, 9, ARG) SEP F(X10, 10, ARG)
#define PRIVATE_MAXON_MAKE_LIST12(F, ARG, SEP, EMPTY, X0, X1, X2, X3, X4, X5, X6, X7, X8, X9, X10, X11) F(X0, 0, ARG) SEP F(X1, 1, ARG) SEP F(X2, 2, ARG) SEP F(X3, 3, ARG) SEP F(X4, 4, ARG) SEP F(X5, 5, ARG) SEP F(X6, 6, ARG) SEP F(X7, 7, ARG) SEP F(X8, 8, ARG) SEP F(X9, 9, ARG) SEP F(X10, 10, ARG) SEP F(X11, 11, ARG)
#define PRIVATE_MAXON_MAKE_LIST13(F, ARG, SEP, EMPTY, X0, X1, X2, X3, X4, X5, X6, X7, X8, X9, X10, X11, X12) F(X0, 0, ARG) SEP F(X1, 1, ARG) SEP F(X2, 2, ARG) SEP F(X3, 3, ARG) SEP F(X4, 4, ARG) SEP F(X5, 5, ARG) SEP F(X6, 6, ARG) SEP F(X7, 7, ARG) SEP F(X8, 8, ARG) SEP F(X9, 9, ARG) SEP F(X10, 10, ARG) SEP F(X11, 11, ARG) SEP F(X12, 12, ARG)
#define PRIVATE_MAXON_MAKE_LIST14(F, ARG, SEP, EMPTY, X0, X1, X2, X3, X4, X5, X6, X7, X8, X9, X10, X11, X12, X13) F(X0, 0, ARG) SEP F(X1, 1, ARG) SEP F(X2, 2, ARG) SEP F(X3, 3, ARG) SEP F(X4, 4, ARG) SEP F(X5, 5, ARG) SEP F(X6, 6, ARG) SEP F(X7, 7, ARG) SEP F(X8, 8, ARG) SEP F(X9, 9, ARG) SEP F(X10, 10, ARG) SEP F(X11, 11, ARG) SEP F(X12, 12, ARG) SEP F(X13, 13, ARG)
#define PRIVATE_MAXON_MAKE_LIST15(F, ARG, SEP, EMPTY, X0, X1, X2, X3, X4, X5, X6, X7, X8, X9, X10, X11, X12, X13, X14) F(X0, 0, ARG) SEP F(X1, 1, ARG) SEP F(X2, 2, ARG) SEP F(X3, 3, ARG) SEP F(X4, 4, ARG) SEP F(X5, 5, ARG) SEP F(X6, 6, ARG) SEP F(X7, 7, ARG) SEP F(X8, 8, ARG) SEP F(X9, 9, ARG) SEP F(X10, 10, ARG) SEP F(X11, 11, ARG) SEP F(X12, 12, ARG) SEP F(X13, 13, ARG) SEP F(X14, 14, ARG)
#define PRIVATE_MAXON_MAKE_LIST16(F, ARG, SEP, EMPTY, X0, X1, X2, X3, X4, X5, X6, X7, X8, X9, X10, X11, X12, X13, X14, X15) F(X0, 0, ARG) SEP F(X1, 1, ARG) SEP F(X2, 2, ARG) SEP F(X3, 3, ARG) SEP F(X4, 4, ARG) SEP F(X5, 5, ARG) SEP F(X6, 6, ARG) SEP F(X7, 7, ARG) SEP F(X8, 8, ARG) SEP F(X9, 9, ARG) SEP F(X10, 10, ARG) SEP F(X11, 11, ARG) SEP F(X12, 12, ARG) SEP F(X13, 13, ARG) SEP F(X14, 14, ARG) SEP F(X15, 15, ARG)
#define PRIVATE_MAXON_MAKE_LIST17(F, ARG, SEP, EMPTY, X0, X1, X2, X3, X4, X5, X6, X7, X8, X9, X10, X11, X12, X13, X14, X15, X16) F(X0, 0, ARG) SEP F(X1, 1, ARG) SEP F(X2, 2, ARG) SEP F(X3, 3, ARG) SEP F(X4, 4, ARG) SEP F(X5, 5, ARG) SEP F(X6, 6, ARG) SEP F(X7, 7, ARG) SEP F(X8, 8, ARG) SEP F(X9, 9, ARG) SEP F(X10, 10, ARG) SEP F(X11, 11, ARG) SEP F(X12, 12, ARG) SEP F(X13, 13, ARG) SEP F(X14, 14, ARG) SEP F(X15, 15, ARG) SEP F(X16, 16, ARG)
#define PRIVATE_MAXON_MAKE_LIST18(F, ARG, SEP, EMPTY, X0, X1, X2, X3, X4, X5, X6, X7, X8, X9, X10, X11, X12, X13, X14, X15, X16, X17) F(X0, 0, ARG) SEP F(X1, 1, ARG) SEP F(X2, 2, ARG) SEP F(X3, 3, ARG) SEP F(X4, 4, ARG) SEP F(X5, 5, ARG) SEP F(X6, 6, ARG) SEP F(X7, 7, ARG) SEP F(X8, 8, ARG) SEP F(X9, 9, ARG) SEP F(X10, 10, ARG) SEP F(X11, 11, ARG) SEP F(X12, 12, ARG) SEP F(X13, 13, ARG) SEP F(X14, 14, ARG) SEP F(X15, 15, ARG) SEP F(X16, 16, ARG) SEP F(X17, 17, ARG)
#define PRIVATE_MAXON_MAKE_LIST19(F, ARG, SEP, EMPTY, X0, X1, X2, X3, X4, X5, X6, X7, X8, X9, X10, X11, X12, X13, X14, X15, X16, X17, X18) F(X0, 0, ARG) SEP F(X1, 1, ARG) SEP F(X2, 2, ARG) SEP F(X3, 3, ARG) SEP F(X4, 4, ARG) SEP F(X5, 5, ARG) SEP F(X6, 6, ARG) SEP F(X7, 7, ARG) SEP F(X8, 8, ARG) SEP F(X9, 9, ARG) SEP F(X10, 10, ARG) SEP F(X11, 11, ARG) SEP F(X12, 12, ARG) SEP F(X13, 13, ARG) SEP F(X14, 14, ARG) SEP F(X15, 15, ARG) SEP F(X16, 16, ARG) SEP F(X17, 17, ARG) SEP F(X18, 18, ARG)
#define PRIVATE_MAXON_MAKE_LIST20(F, ARG, SEP, EMPTY, X0, X1, X2, X3, X4, X5, X6, X7, X8, X9, X10, X11, X12, X13, X14, X15, X16, X17, X18, X19) F(X0, 0, ARG) SEP F(X1, 1, ARG) SEP F(X2, 2, ARG) SEP F(X3, 3, ARG) SEP F(X4, 4, ARG) SEP F(X5, 5, ARG) SEP F(X6, 6, ARG) SEP F(X7, 7, ARG) SEP F(X8, 8, ARG) SEP F(X9, 9, ARG) SEP F(X10, 10, ARG) SEP F(X11, 11, ARG) SEP F(X12, 12, ARG) SEP F(X13, 13, ARG) SEP F(X14, 14, ARG) SEP F(X15, 15, ARG) SEP F(X16, 16, ARG) SEP F(X17, 17, ARG) SEP F(X18, 18, ARG) SEP F(X19, 19, ARG)
#define PRIVATE_MAXON_MAKE_LIST21(F, ARG, SEP, EMPTY, X0, X1, X2, X3, X4, X5, X6, X7, X8, X9, X10, X11, X12, X13, X14, X15, X16, X17, X18, X19, X20) F(X0, 0, ARG) SEP F(X1, 1, ARG) SEP F(X2, 2, ARG) SEP F(X3, 3, ARG) SEP F(X4, 4, ARG) SEP F(X5, 5, ARG) SEP F(X6, 6, ARG) SEP F(X7, 7, ARG) SEP F(X8, 8, ARG) SEP F(X9, 9, ARG) SEP F(X10, 10, ARG) SEP F(X11, 11, ARG) SEP F(X12, 12, ARG) SEP F(X13, 13, ARG) SEP F(X14, 14, ARG) SEP F(X15, 15, ARG) SEP F(X16, 16, ARG) SEP F(X17, 17, ARG) SEP F(X18, 18, ARG) SEP F(X19, 19, ARG) SEP F(X20, 20, ARG)
#define PRIVATE_MAXON_MAKE_LIST22(F, ARG, SEP, EMPTY, X0, X1, X2, X3, X4, X5, X6, X7, X8, X9, X10, X11, X12, X13, X14, X15, X16, X17, X18, X19, X20, X21) F(X0, 0, ARG) SEP F(X1, 1, ARG) SEP F(X2, 2, ARG) SEP F(X3, 3, ARG) SEP F(X4, 4, ARG) SEP F(X5, 5, ARG) SEP F(X6, 6, ARG) SEP F(X7, 7, ARG) SEP F(X8, 8, ARG) SEP F(X9, 9, ARG) SEP F(X10, 10, ARG) SEP F(X11, 11, ARG) SEP F(X12, 12, ARG) SEP F(X13, 13, ARG) SEP F(X14, 14, ARG) SEP F(X15, 15, ARG) SEP F(X16, 16, ARG) SEP F(X17, 17, ARG) SEP F(X18, 18, ARG) SEP F(X19, 19, ARG) SEP F(X20, 20, ARG) SEP F(X21, 21, ARG)
#define PRIVATE_MAXON_MAKE_LIST23(F, ARG, SEP, EMPTY, X0, X1, X2, X3, X4, X5, X6, X7, X8, X9, X10, X11, X12, X13, X14, X15, X16, X17, X18, X19, X20, X21, X22) F(X0, 0, ARG) SEP F(X1, 1, ARG) SEP F(X2, 2, ARG) SEP F(X3, 3, ARG) SEP F(X4, 4, ARG) SEP F(X5, 5, ARG) SEP F(X6, 6, ARG) SEP F(X7, 7, ARG) SEP F(X8, 8, ARG) SEP F(X9, 9, ARG) SEP F(X10, 10, ARG) SEP F(X11, 11, ARG) SEP F(X12, 12, ARG) SEP F(X13, 13, ARG) SEP F(X14, 14, ARG) SEP F(X15, 15, ARG) SEP F(X16, 16, ARG) SEP F(X17, 17, ARG) SEP F(X18, 18, ARG) SEP F(X19, 19, ARG) SEP F(X20, 20, ARG) SEP F(X21, 21, ARG) SEP F(X22, 22, ARG)
#define PRIVATE_MAXON_MAKE_LIST24(F, ARG, SEP, EMPTY, X0, X1, X2, X3, X4, X5, X6, X7, X8, X9, X10, X11, X12, X13, X14, X15, X16, X17, X18, X19, X20, X21, X22, X23) F(X0, 0, ARG) SEP F(X1, 1, ARG) SEP F(X2, 2, ARG) SEP F(X3, 3, ARG) SEP F(X4, 4, ARG) SEP F(X5, 5, ARG) SEP F(X6, 6, ARG) SEP F(X7, 7, ARG) SEP F(X8, 8, ARG) SEP F(X9, 9, ARG) SEP F(X10, 10, ARG) SEP F(X11, 11, ARG) SEP F(X12, 12, ARG) SEP F(X13, 13, ARG) SEP F(X14, 14, ARG) SEP F(X15, 15, ARG) SEP F(X16, 16, ARG) SEP F(X17, 17, ARG) SEP F(X18, 18, ARG) SEP F(X19, 19, ARG) SEP F(X20, 20, ARG) SEP F(X21, 21, ARG) SEP F(X22, 22, ARG) SEP F(X23, 23, ARG)

#define PRIVATE_MAXON_MAKE_LIST_C(count, F, ARG, SEP, EMPTY, ...) MAXON_EXPAND(PRIVATE_MAXON_MAKE_LIST##count(F, ARG, SEP, EMPTY, __VA_ARGS__))
#define PRIVATE_MAXON_MAKE_LIST_B(count, F, ARG, SEP, EMPTY, ...) PRIVATE_MAXON_MAKE_LIST_C(count, F, ARG, SEP, EMPTY, __VA_ARGS__)
#define PRIVATE_MAXON_MAKE_LIST_A(count, F, ARG, SEP, EMPTY, ...) PRIVATE_MAXON_MAKE_LIST_B(count, F, ARG, SEP, EMPTY, __VA_ARGS__)

//----------------------------------------------------------------------------------------
/// The macro MAXON_MAKE_LIST expands to a list which is the SEP-separated concatenation of
/// the result of applying the macro given by F to the pair (x, i, ARG) for each x of the
/// variadic parameter, where i is the index (starting with 0). For example, if we have
/// @code
/// #define EQUAL_HELPER(x, i, a) (x == other.x)
/// #define EQUAL(...) MAXON_MAKE_LIST(EQUAL_HELPER, , &&, , __VA_ARGS__)
/// @endcode
/// then <tt>EQUAL(a, b, c)</tt> expands to
/// @code
/// (a == other.a) && (b == other.b) && (c == other.c)
/// @endcode
/// If you need a comma as separator, you have to use MAXON_MAKE_COMMA_LIST.
/// @param[in] F									A macro which takes three arguments. The first argument receives a value from the list, the second the 0-based index and the third ARG.
/// @param[in] ARG								Some value to pass as third argument to F. Leave empty if you don't need this.
/// @param[in] SEP								The separator to use between list elements. For a comma, use the macro MAXON_MAKE_COMMA_LIST.
/// @param[in] EMPTY							The result which shall be used when the list is empty. Just leave empty if this is what you want in the empty case.
/// @param[in] ...								List of values to process. The macro supports an empty list.
//----------------------------------------------------------------------------------------
#define MAXON_MAKE_LIST(F, ARG, SEP, EMPTY, ...) PRIVATE_MAXON_MAKE_LIST_A(MAXON_VA_NARGS(__VA_ARGS__), F, ARG, SEP, EMPTY, __VA_ARGS__)


#define PRIVATE_MAXON_MAKE_COMMA_LIST_C(count, F, ARG, EMPTY, ...) MAXON_EXPAND(PRIVATE_MAXON_MAKE_LIST##count(F, ARG, MAXON_COMMA, EMPTY, __VA_ARGS__))
#define PRIVATE_MAXON_MAKE_COMMA_LIST_B(count, F, ARG, EMPTY, ...) PRIVATE_MAXON_MAKE_COMMA_LIST_C(count, F, ARG, EMPTY, __VA_ARGS__)
#define PRIVATE_MAXON_MAKE_COMMA_LIST_A(count, F, ARG, EMPTY, ...) PRIVATE_MAXON_MAKE_COMMA_LIST_B(count, F, ARG, EMPTY, __VA_ARGS__)

//----------------------------------------------------------------------------------------
/// The macro MAXON_MAKE_COMMA_LIST expands to a list which is the comma-separated concatenation of
/// the result of applying the macro given by F to the pair (x, i, ARG) for each x of the
/// variadic parameter, where i is the index (starting with 0). For example, if we have
/// @code
/// #define MOVE_HELPER(x, i, a) x(std::move(src.x))
/// #define MOVE(...) MAXON_MAKE_COMMA_LIST(MOVE_HELPER, , , __VA_ARGS__)
/// @endcode
/// then <tt>MOVE(a, b, c)</tt> expands to
/// @code
/// a(std::move(src.a)) , b(std::move(src.b)) , c(std::move(src.c))
/// @endcode
/// If you need a separator different from a comma, you have to use MAXON_MAKE_LIST.
/// @param[in] F									A macro which takes three arguments. The first argument receives a value from the list, the second the 0-based index and the third ARG.
/// @param[in] ARG								Some value to pass as third argument to F. Leave empty if you don't need this.
/// @param[in] EMPTY							The result which shall be used when the list is empty. Just leave empty if this is what you want in the empty case.
/// @param[in] ...								List of values to process. The macro supports an empty list.
//----------------------------------------------------------------------------------------
#define MAXON_MAKE_COMMA_LIST(F, ARG, EMPTY, ...) PRIVATE_MAXON_MAKE_COMMA_LIST_A(MAXON_VA_NARGS(__VA_ARGS__), F, ARG, EMPTY, __VA_ARGS__)

/// @endcond IGNORE

//----------------------------------------------------------------------------------------
/// This statement needs to be used for any case in a switch the contains code, but does not call break.
/// An example:
/// @code
/// switch(condition)
/// {
///   case 0:
///     ...do something...
///     MAXON_SWITCH_FALLTHROUGH;
///
///   case 1:
///     ...do something...
/// 	  break;
///  }
/// @endcode
//----------------------------------------------------------------------------------------
#if defined(MAXON_COMPILER_CLANG) && defined(MAXON_TARGET_WINDOWS)
	// clang supports -Wimplicit-fallthrough and gives a warning
	#define MAXON_SWITCH_FALLTHROUGH [[clang::fallthrough]]
#else
	#define MAXON_SWITCH_FALLTHROUGH
#endif

#ifndef MAXON_DISALLOW_COPY_AND_ASSIGN
//----------------------------------------------------------------------------------------
/// This statement needs to be used at the beginning of any class that cannot be copied
/// An example:
/// @code
/// class MyClass
/// {
///   MAXON_DISALLOW_COPY_AND_ASSIGN(MyClass);
///   ...
/// };
/// @endcode
//----------------------------------------------------------------------------------------
	#define MAXON_DISALLOW_COPY_AND_ASSIGN(TypeName) \
		TypeName(const TypeName&) = delete; \
		void operator =(const TypeName&) = delete;
#endif

//----------------------------------------------------------------------------------------
/// This statement automatically creates a move assignment operator from an existing move constructor.
/// The access control (private, protected or public) of the operator is inherited from the context,
/// so you have to put the macro in the public section if you want to make the assignment operator public.
/// An example:
/// @code
/// class MyClass
/// {
///   MAXON_DISALLOW_COPY_AND_ASSIGN(MyClass);
/// public:
///   MyClass(MyClass&& src);
///   MAXON_OPERATOR_MOVE_ASSIGNMENT(MyClass);
///   ...
/// };
/// @endcode
/// @note This macro can't be used for classes with virtual functions for the sake of safety.
/// Because the created move assignment operator would invoke the constructor, the vtable pointer of the
/// object would be changed if one accidentally used the assignment operator of a base class for an object
/// of a derived class.
/// @note This macro must not be used for classes which support concurrent move assignment calls from
/// multiple threads to the same object because the sequence of destructor and move constructor is not
/// thread-safe.
/// @see MAXON_OPERATOR_COPY_ASSIGNMENT
//----------------------------------------------------------------------------------------
#define MAXON_OPERATOR_MOVE_ASSIGNMENT(TypeName) \
	MAXON_ATTRIBUTE_FORCE_INLINE TypeName& operator =(TypeName&& src) \
	{ \
		static_assert(!std::is_polymorphic<TypeName>::value, "MAXON_OPERATOR_MOVE_ASSIGNMENT can't be used for classes with virtual functions."); \
		if (this != std::addressof(src)) \
		{ \
			this->~TypeName(); \
			new (this) TypeName(std::move(src)); \
		} \
		return *this; \
	}

//----------------------------------------------------------------------------------------
/// This statement automatically creates a copy assignment operator from an existing copy constructor.
/// The access control (private, protected or public) of the operator is inherited from the context,
/// so you have to put the macro in the public section if you want to make the assignment operator public.
/// An example:
/// @code
/// class MyClass
/// {
/// public:
///   MyClass(const MyClass& src);
///   MAXON_OPERATOR_COPY_ASSIGNMENT(MyClass);
///   ...
/// };
/// @endcode
/// @note This macro can't be used for classes with virtual functions for the sake of safety.
/// Because the created copy assignment operator would invoke the constructor, the vtable pointer of the
/// object would be changed if one accidentally used the assignment operator of a base class for an object
/// of a derived class.
/// @note This macro must not be used for classes which support concurrent copy assignment calls from
/// multiple threads to the same object because the sequence of destructor and copy constructor is not
/// thread-safe.
/// @see MAXON_OPERATOR_MOVE_ASSIGNMENT
//----------------------------------------------------------------------------------------
#define MAXON_OPERATOR_COPY_ASSIGNMENT(TypeName) \
	MAXON_ATTRIBUTE_FORCE_INLINE TypeName& operator =(const TypeName& src) \
	{ \
		static_assert(!std::is_polymorphic<TypeName>::value, "MAXON_OPERATOR_COPY_ASSIGNMENT can't be used for classes with virtual functions."); \
		if (this != std::addressof(src)) \
		{ \
			this->~TypeName(); \
			new (this) TypeName(src); \
		} \
		return *this; \
	}

//----------------------------------------------------------------------------------------
/// This macro defines member operators >, <= and >= based on the member operator <.
/// An example:
/// @code
/// class MyClass
/// {
/// public:
///   Bool operator <(const MyClass& other) const { return ...; }
///   MAXON_OPERATOR_INEQUALITY(MyClass);
///   ...
/// };
/// @endcode
//----------------------------------------------------------------------------------------
#define MAXON_OPERATOR_INEQUALITY(TypeName) \
	MAXON_ATTRIBUTE_FORCE_INLINE Bool operator >(const TypeName& b) const { return b.operator <(*this); } \
	MAXON_ATTRIBUTE_FORCE_INLINE Bool operator <=(const TypeName& b) const { return !b.operator <(*this); } \
	MAXON_ATTRIBUTE_FORCE_INLINE Bool operator >=(const TypeName& b) const { return !this->operator <(b); }

//----------------------------------------------------------------------------------------
/// This macro defines member operators !=, >, <= and >= based on the member operators == and <.
/// An example:
/// @code
/// class MyClass
/// {
/// public:
///   Bool operator ==(const MyClass& other) const { return ...; }
///   Bool operator <(const MyClass& other) const { return ...; }
///   MAXON_OPERATOR_COMPARISON(MyClass);
///   ...
/// };
/// @endcode
//----------------------------------------------------------------------------------------
#define MAXON_OPERATOR_COMPARISON(TypeName) \
	MAXON_ATTRIBUTE_FORCE_INLINE Bool operator !=(const TypeName& b) const { return !this->operator ==(b); } \
	MAXON_OPERATOR_INEQUALITY(TypeName)


#define PRIVATE_MAXON_MOVE_MEMBERS(x, i, a) x(std::move(src.x))

//----------------------------------------------------------------------------------------
/// MAXON_MOVE_MEMBERS simplifies the definition of a move constructor. Add all members which shall be moved from the source object
/// to the new object to the argument list of MAXON_MOVE_MEMBERS as in
/// @code
/// class Example
/// {
/// public:
/// 	Example(Example&& src) : MAXON_MOVE_MEMBERS(_a, _b) {}
/// private:
/// 	Int _a;
/// 	BaseArray<String> _b;
/// };
/// @endcode
/// You have to use src as name of the constructor parameter.
//----------------------------------------------------------------------------------------
#define MAXON_MOVE_MEMBERS(...) MAXON_MAKE_COMMA_LIST(PRIVATE_MAXON_MOVE_MEMBERS, , , __VA_ARGS__)

#define PRIVATE_MAXON_COPY_MEMBERS(x, i, a) x(src.x)

//----------------------------------------------------------------------------------------
/// MAXON_COPY_MEMBERS simplifies the definition of a copy constructor. Add all members which shall be copied from the source object
/// to the new object to the argument list of MAXON_COPY_MEMBERS as in
/// @code
/// class Example
/// {
/// public:
/// 	Example(const Example& src) : MAXON_COPY_MEMBERS(_a, _b) {}
/// private:
/// 	Int _a;
/// 	String _b;
/// };
/// @endcode
/// You have to use src as name of the constructor parameter.
//----------------------------------------------------------------------------------------
#define MAXON_COPY_MEMBERS(...) MAXON_MAKE_COMMA_LIST(PRIVATE_MAXON_COPY_MEMBERS, , , __VA_ARGS__)

#define PRIVATE_MAXON_COPYFROM_MEMBERS(x, i, a) maxon::AssignCopy(x, src.x) iferr_return
#define MAXON_COPYFROM_MEMBERS(...) MAXON_MAKE_LIST(PRIVATE_MAXON_COPYFROM_MEMBERS, ,; , , __VA_ARGS__)
#define MAXON_OPERATOR_COPYFROM(T, ...) maxon::Result<void> CopyFrom(const T& src) { iferr_scope; MAXON_COPYFROM_MEMBERS(__VA_ARGS__); return maxon::OK; }


#define PRIVATE_MAXON_HASHCODE1(m1) maxon::DefaultCompare::GetHashCode(m1)
#define PRIVATE_MAXON_HASHCODE2(m1, m2) (PRIVATE_MAXON_HASHCODE1(m1) * 31 + maxon::DefaultCompare::GetHashCode(m2))
#define PRIVATE_MAXON_HASHCODE3(m1, m2, m3) (PRIVATE_MAXON_HASHCODE2(m1, m2) * 31 + maxon::DefaultCompare::GetHashCode(m3))
#define PRIVATE_MAXON_HASHCODE4(m1, m2, m3, m4) (PRIVATE_MAXON_HASHCODE3(m1, m2, m3) * 31 + maxon::DefaultCompare::GetHashCode(m4))
#define PRIVATE_MAXON_HASHCODE5(m1, m2, m3, m4, m5) (PRIVATE_MAXON_HASHCODE4(m1, m2, m3, m4) * 31 + maxon::DefaultCompare::GetHashCode(m5))
#define PRIVATE_MAXON_HASHCODE6(m1, m2, m3, m4, m5, m6) (PRIVATE_MAXON_HASHCODE5(m1, m2, m3, m4, m5) * 31 + maxon::DefaultCompare::GetHashCode(m6))
#define PRIVATE_MAXON_HASHCODE7(m1, m2, m3, m4, m5, m6, m7) (PRIVATE_MAXON_HASHCODE6(m1, m2, m3, m4, m5, m6) * 31 + maxon::DefaultCompare::GetHashCode(m7))
#define PRIVATE_MAXON_HASHCODE8(m1, m2, m3, m4, m5, m6, m7, m8) (PRIVATE_MAXON_HASHCODE7(m1, m2, m3, m4, m5, m6, m7) * 31 + maxon::DefaultCompare::GetHashCode(m8))
#define PRIVATE_MAXON_HASHCODE9(m1, m2, m3, m4, m5, m6, m7, m8, m9) (PRIVATE_MAXON_HASHCODE8(m1, m2, m3, m4, m5, m6, m7, m8) * 31 + maxon::DefaultCompare::GetHashCode(m9))
#define PRIVATE_MAXON_HASHCODE10(m1, m2, m3, m4, m5, m6, m7, m8, m9, m10) (PRIVATE_MAXON_HASHCODE9(m1, m2, m3, m4, m5, m6, m7, m8, m9) * 31 + maxon::DefaultCompare::GetHashCode(m10))
#define PRIVATE_MAXON_HASHCODE_C(count, ...) MAXON_EXPAND(PRIVATE_MAXON_HASHCODE##count(__VA_ARGS__))
#define PRIVATE_MAXON_HASHCODE_B(count, ...) PRIVATE_MAXON_HASHCODE_C(count, __VA_ARGS__)
#define PRIVATE_MAXON_HASHCODE_A(count, ...) PRIVATE_MAXON_HASHCODE_B(count, __VA_ARGS__)

//----------------------------------------------------------------------------------------
/// MAXON_HASHCODE computes the hash code of the arguments based on DefaultCompare::GetHashCode.
/// The hash codes h_i of the arguments a_i are combined using the formula
/// ( ... ((h_1 * 31 + h_2) * 31 + h_3) ... ) * 31 + h_n.
//----------------------------------------------------------------------------------------
#define MAXON_HASHCODE(...) PRIVATE_MAXON_HASHCODE_A(MAXON_VA_NARGS(__VA_ARGS__), __VA_ARGS__)

#define PRIVATE_MAXON_EQUALITY_OPERATORS(x, i, a) (x == other.x)

//----------------------------------------------------------------------------------------
/// MAXON_OPERATOR_EQUALITY defines operator == and operator != for a class based on the equality operators for the class members. You have
/// to list all members as in
/// @code
/// class Quaternion
/// {
/// public:
/// 	MAXON_OPERATOR_EQUALITY(Quaternion, _w, _v);
/// private:
/// 	Float64 _w;
/// 	Vector64 _v;
/// };
/// @endcode
/// This will define the equality of two quaternions a, b by <tt>(a._w == b._w) && (a._v == b._v)</tt>.
/// @param[in] T									The enclosing class type for which the equality operators shall be defined.
/// @param[in] ...								List of class members. Equality operators must be available for the types of all members.
/// @see MAXON_OPERATOR_EQUALITY_HASHCODE
//----------------------------------------------------------------------------------------
#define MAXON_OPERATOR_EQUALITY(T, ...) maxon::Bool operator ==(const T& other) const { return (this == &other) || (MAXON_MAKE_LIST(PRIVATE_MAXON_EQUALITY_OPERATORS, , &&, , __VA_ARGS__)); } \
	maxon::Bool operator !=(const T& other) const { return !this->operator ==(other); }

//----------------------------------------------------------------------------------------
/// MAXON_OPERATOR_EQUALITY_HASHCODE defines operator == and operator != for a class based on the equality operators for the class members,
/// and it defines the GetHashCode function using DefaultCompare::GetHashCode for the class members.
/// You have to list all members as in
/// @code
/// class Quaternion
/// {
/// public:
/// 	MAXON_OPERATOR_EQUALITY_HASHCODE(Quaternion, _w, _v);
/// private:
/// 	Float64 _w;
/// 	Vector64 _v;
/// };
/// @endcode
/// This will define the equality of two quaternions a, b by <tt>(a._w == b._w) && (a._v == b._v)</tt>,
/// and the hash code by <tt>DefaultCompare::GetHashCode(_w) * 31 + DefaultCompare::GetHashCode(_v)</tt>.
/// @param[in] T									The enclosing class type for which the equality operators and the hash code shall be defined.
/// @param[in] ...								List of class members. Equality operators must be available for the types of all members,
/// 															likewise DefaultCompare::GetHashCode.
/// @see MAXON_OPERATOR_EQUALITY
//----------------------------------------------------------------------------------------
#define MAXON_OPERATOR_EQUALITY_HASHCODE(T, ...) maxon::Bool operator ==(const T& other) const { return (this == &other) || (MAXON_MAKE_LIST(PRIVATE_MAXON_EQUALITY_OPERATORS, , &&, , __VA_ARGS__)); } \
	maxon::Bool operator !=(const T& other) const { return !this->operator ==(other); } \
	maxon::UInt GetHashCode() const { return PRIVATE_MAXON_HASHCODE_A(MAXON_VA_NARGS(__VA_ARGS__), __VA_ARGS__); }


#define PRIVATE_MAXON_STRUCT_MEMBER_TOSTRING(x, i, a) maxon::GlobalToString(x, fs)
#define PRIVATE_MAXON_STRUCT_MEMBER_TYPE(x, i, a) decltype(x)
#define PRIVATE_MAXON_STRUCT_MEMBER_COPY(x, i, a) maxon::AssignCopy(x, reinterpret_cast<const a&>(src).x) iferr_return;

#define MAXON_OPERATOR_STRUCT(T, ...) \
	MAXON_OPERATOR_EQUALITY_HASHCODE(T, __VA_ARGS__); \
	maxon::String ToString(const maxon::FormatStatement* fs) const \
	{ \
		return "("_s + MAXON_MAKE_LIST(PRIVATE_MAXON_STRUCT_MEMBER_TOSTRING, ,+ ","_s +, , __VA_ARGS__) + ")"_s; \
	} \
	static constexpr maxon::Bool COPY_ASSIGNABLE = std::is_copy_assignable<maxon::Tuple<MAXON_MAKE_COMMA_LIST(PRIVATE_MAXON_STRUCT_MEMBER_TYPE,,, __VA_ARGS__)>>::value; \
	maxon::Result<void> CopyFrom(const typename std::conditional<COPY_ASSIGNABLE, DummyParamType, T>::type& src) \
	{ \
		iferr_scope; \
		MAXON_MAKE_LIST(PRIVATE_MAXON_STRUCT_MEMBER_COPY, T,,, __VA_ARGS__); \
		return maxon::OK; \
	}


#define MAXON_STRUCT_TUPLE(T, ...) \
	MAXON_OPERATOR_STRUCT(T, __VA_ARGS__) \
	using StructTupleType = maxon::Tuple<MAXON_MAKE_COMMA_LIST(PRIVATE_MAXON_STRUCT_MEMBER_TYPE,,, __VA_ARGS__)>; \
	const StructTupleType& ToTuple() const { static_assert(SIZEOF(T) == SIZEOF(StructTupleType), "Layout of Tuple and " #T " differ."); MAXON_ASSERT_STANDARD_LAYOUT(T); return *reinterpret_cast<const StructTupleType*>(this); } \
	StructTupleType& ToTuple() { return *reinterpret_cast<StructTupleType*>(this); } \
	operator const StructTupleType&() const { return *reinterpret_cast<const StructTupleType*>(this); } \
	operator StructTupleType&() { return *reinterpret_cast<StructTupleType*>(this); } \
	T(typename std::conditional<COPY_ASSIGNABLE, const StructTupleType&, DummyParamType&&>::type src) : T(reinterpret_cast<typename std::conditional<COPY_ASSIGNABLE, const T&, T&&>::type>(src)) { } \
	T& operator =(typename std::conditional<COPY_ASSIGNABLE, const StructTupleType&, DummyParamType&&>::type src) { *this = reinterpret_cast<typename std::conditional<COPY_ASSIGNABLE, const T&, T&&>::type>(src); return *this; } \
	T(StructTupleType&& src) : T(std::move(reinterpret_cast<T&>(src))) { } \
	T& operator =(StructTupleType&& src) { *this = std::move(reinterpret_cast<T&>(src)); return *this; } \
	static const T& FromTuple(const StructTupleType& src) { return reinterpret_cast<const T&>(src); } \
	static T& FromTuple(StructTupleType& src) { return reinterpret_cast<T&>(src); } \
	T() = default


//----------------------------------------------------------------------------------------
/// MAXON_NONCONST_COUNTERPART simplifies the implementation of a non-const counterpart of
/// a const member function where the non-const function shall do exactly the same as the
/// const function, but return a non-const value:
/// @code
///	const V* FindValue(const K& key) const
///	{
///		...
///	}
///
///	V* FindValue(const K& key)
///	{
///		return MAXON_NONCONST_COUNTERPART(FindValue(key));
///	}
/// @endcode
/// If the implementation code is a simple one-liner, you may find it easier to just copy the code
/// from the const function to the non-const function, but for more complex functions this
/// code duplication should be avoided by just calling the const function in the non-const function
/// (and adding the necessary casts). This is exactly what MAXON_NONCONST_COUNTERPART does.
///
/// The return type of the called const function has to be either a pointer or a reference to a const value,
/// and the non-const function needs to have the corresponding non-const return type.
/// @param[in] ...								The call to the const function, see example. You have to forward all function parameters.
//----------------------------------------------------------------------------------------
#define MAXON_NONCONST_COUNTERPART(...) const_cast<decltype(this->__VA_ARGS__)>(static_cast<const typename std::remove_pointer<decltype(this)>::type*>(this)->__VA_ARGS__)


#define PRIVATE_MAXON_MEMBER_ACCESSORS_PARAMS(x, i, a) x arg##i
#define PRIVATE_MAXON_MEMBER_ACCESSORS_ARGS(x, i, a) arg##i


//----------------------------------------------------------------------------------------
/// MAXON_MEMBER_ACCESSORS simplifies the implementation of all four variants of member accessor functions
/// which return the member by reference. You only have to implement the const l-value variant,
/// and the macro adds the remaining three (non-const l-value, const r-value, non-const r-value).
/// In general one should have all four variants like in this example:
/// @code
///	class Test
///	{
///	public:
///		const Vector& GetValue() const & { return _v; }
///		Vector& GetValue() & { return _v; }
///		Vector GetValue() && { return std::move(_v); }
///		Vector GetValue() const && { return _v; }
///	private:
///		Vector _value;
///	};
/// @endcode
/// This is to prevent code which returns references to temporaries, for example the following
/// code compiles but crashes at run-time if @c Test didn't have ref-qualified accessor functions:
/// @code
/// Test Func();
///
///	const Vector& Func2()
///	{
///		return Func().GetValue();
///	}
/// @endcode
/// With ref-qualified accessor functions the code doesn't compile. To simplify the implementation
/// the macro defines the latter three functions in terms of the const l-value accessor function:
/// @code
///	class Test
///	{
///	public:
///		const Vector& GetValue() const & { return _v; }
///		MAXON_MEMBER_ACCESSORS(Vector, GetValue);
///	private:
///		Vector _value;
///	};
/// @endcode
///
/// @param[in] T									The return type of the accessor functions (without any qualifier).
/// @param[in] M									The name of the accessor function.
/// @param[in] ...								List of parameter types of the accessor function (empty if the function has no parameters).
//----------------------------------------------------------------------------------------
#define MAXON_MEMBER_ACCESSORS(T, M, ...) \
	T& M(MAXON_MAKE_COMMA_LIST(PRIVATE_MAXON_MEMBER_ACCESSORS_PARAMS, , , __VA_ARGS__)) & { return const_cast<T&>((*static_cast<const typename std::remove_pointer<decltype(this)>::type*>(this)).M(MAXON_MAKE_COMMA_LIST(PRIVATE_MAXON_MEMBER_ACCESSORS_ARGS, , , __VA_ARGS__))); } \
	T M(MAXON_MAKE_COMMA_LIST(PRIVATE_MAXON_MEMBER_ACCESSORS_PARAMS, , , __VA_ARGS__)) && { return std::move(const_cast<T&>((*static_cast<const typename std::remove_pointer<decltype(this)>::type*>(this)).M(MAXON_MAKE_COMMA_LIST(PRIVATE_MAXON_MEMBER_ACCESSORS_ARGS, , , __VA_ARGS__)))); } \
	T M(MAXON_MAKE_COMMA_LIST(PRIVATE_MAXON_MEMBER_ACCESSORS_PARAMS, , , __VA_ARGS__)) const && { return (*this).M(MAXON_MAKE_COMMA_LIST(PRIVATE_MAXON_MEMBER_ACCESSORS_ARGS, , , __VA_ARGS__)); }


namespace details
{

template <typename B1, typename B2> class NonEmptyDerived : public B1, public B2
{
public:
	using type = NonEmptyDerived;
};

template <typename B1> class NonEmptyDerived<B1, EmptyClass>
{
public:
	using type = B1;
};

template <typename B2> class NonEmptyDerived<EmptyClass, B2>
{
public:
	using type = B2;
};

template <> class NonEmptyDerived<EmptyClass, EmptyClass>
{
public:
	using type = EmptyClass;
};

template <typename... BASES> struct NonEmptyBasesHelper;

template <typename T1, typename... REST> struct NonEmptyBasesHelper<T1, REST...>
{
	using type = typename NonEmptyDerived<T1, typename NonEmptyBasesHelper<REST...>::type>::type;
};

template <> struct NonEmptyBasesHelper<>
{
	using type = EmptyClass;
};

}

#if defined (MAXON_COMPILER_MSVC) && MAXON_COMPILER_MSVC >= 1910
template <typename B> struct TypeOrEmptyClass { using TYPE = typename std::conditional<std::is_empty<B>::value, EmptyClass, B>::type; };
template <typename... BASES> using NonEmptyBases = typename maxon::details::NonEmptyBasesHelper<typename TypeOrEmptyClass<BASES>::TYPE...>::type;
#else

//----------------------------------------------------------------------------------------
/// NonEmptyBases is a type which has all of the classes given in BASES as (possibly indirect) base classes,
/// except those which are empty. It can be used to avoid padding bytes which some compilers add for
/// empty base classes. If all classes in BASES are empty, then NonEmptyBases is just a type alias for EmptyClass.
/// @tparam BASES									List of base classes.
//----------------------------------------------------------------------------------------
template <typename... BASES> using NonEmptyBases = typename maxon::details::NonEmptyBasesHelper<typename std::conditional<std::is_empty<BASES>::value, EmptyClass, BASES>::type...>::type;
#endif

//----------------------------------------------------------------------------------------
/// This macro exists to improve the readability of defining a conditionally enabled copy constructor.
/// The regular approach of using std::enable_if as a template argument should be used, because if templated versions exist,
/// the compiler may default-generate an implicit the copy constructor and prefer that.
/// The alternative approach is to conditionally define the type of the argument: 
/// If the given condition is matched, the substituted type is that of an actual copy/move constructor.
/// Otherwise, DummyParamType is used, so the function is not a copy constructor.
/// Analogous variants exist for move constructor and copy/move assignment operators.
/// @param[in] T									Type of the enclosing class.
/// @param[in] cond								The condition under which the copy constructor is enabled. Must be dependent on T.
//----------------------------------------------------------------------------------------
#define MAXON_DECLARE_CONDITIONAL_COPY_CONSTRUCTOR(cls, cond) \
	cls(const typename std::conditional<cond, DummyParamType, cls>::type& src) = delete; \
	cls(const typename std::conditional<cond, cls, DummyParamType>::type& src)

//----------------------------------------------------------------------------------------
/// @see MAXON_DECLARE_CONDITIONAL_COPY_CONSTRUCTOR
//----------------------------------------------------------------------------------------
#define MAXON_DECLARE_CONDITIONAL_MOVE_CONSTRUCTOR(cls, cond) \
	cls(typename std::conditional<cond, DummyParamType, cls>::type&& src) = delete; \
	cls(typename std::conditional<cond, cls, DummyParamType>::type&& src)

//----------------------------------------------------------------------------------------
/// @see MAXON_DECLARE_CONDITIONAL_COPY_CONSTRUCTOR
//----------------------------------------------------------------------------------------
#define MAXON_DECLARE_CONDITIONAL_COPY_ASSIGNMENT(cls, cond) \
	cls& operator =(const typename std::conditional<cond, DummyParamType, cls>::type& src) = delete; \
	cls& operator =(const typename std::conditional<cond, cls, DummyParamType>::type& src)

//----------------------------------------------------------------------------------------
/// @see MAXON_DECLARE_CONDITIONAL_COPY_CONSTRUCTOR
//----------------------------------------------------------------------------------------
#define MAXON_DECLARE_CONDITIONAL_MOVE_ASSIGNMENT(cls, cond) \
	cls& operator =(typename std::conditional<cond, DummyParamType, cls>::type&& src) = delete; \
	cls& operator =(typename std::conditional<cond, cls, DummyParamType>::type&& src)


template <template <typename...> class TEMPLATE, typename... ARGS> struct TemplateInstantiation
{
	template <typename... T> using Rebind = TEMPLATE<T...>;

	template <template <typename> class MAP> using Map = TEMPLATE<typename MAP<ARGS>::type...>;
};

template <typename T, template <typename> class MAP, typename = void> struct SubstituteType
{
	using type = T;
};

template <typename T, template <typename> class MAP> struct SubstituteType<T&, MAP, void>
{
	using type = typename MAP<T>::type&;
};

template <typename T, template <typename> class MAP> struct SubstituteType<T*, MAP, void>
{
	using type = typename MAP<T>::type*;
};

template <typename T, template <typename> class MAP> struct SubstituteType<const T, MAP, void>
{
	using type = const typename MAP<T>::type;
};

template <typename T, template <typename> class MAP> struct SubstituteType<T, MAP, typename SFINAEHelper<void, typename T::Instantiation>::type>
{
	using type = typename T::Instantiation::template Map<MAP>;
};

/// @}

} // namespace maxon

#endif // CLASSHELPERS_H__
