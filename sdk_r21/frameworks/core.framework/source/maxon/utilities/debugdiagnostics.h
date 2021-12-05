#ifndef DEBUGDIAGNOSTICS_H__
#define DEBUGDIAGNOSTICS_H__

#ifndef APIBASE_H__
	#error "Do not include this file directly"
#endif

#if defined(MAXON_TARGET_MACOS)
	#define __debugbreak()	__asm__("int $3\n" : :);
#elif defined MAXON_TARGET_LINUX || defined MAXON_TARGET_ANDROID
	#include <signal.h> // for raise(SIGTRAP)
	#define __debugbreak()	raise(SIGTRAP);
#elif defined(MAXON_TARGET_IOS)
	#if defined(MAXON_TARGET_CPU_INTEL)
		#define __debugbreak()	__asm__("int $3\n" : :);
	#elif defined MAXON_TARGET_64BIT
		#define __debugbreak()	__asm("svc 0");
	#else
		#define __debugbreak()	__asm("trap");
	#endif
#elif !defined(MAXON_TARGET_WINDOWS)
	#define __debugbreak()	{}
#endif

/// @file
/// Debugging section

namespace maxon
{

/// @addtogroup SYSTEM
/// @{

enum class TARGETAUDIENCE
{
	DEBUGGER = 1 << 1,
	DEVELOPERS = 1 << 2,
	USERS = 1 << 3,
	ALL = DEBUGGER | DEVELOPERS | USERS,
} MAXON_ENUM_FLAGS(TARGETAUDIENCE, "net.maxon.datatype.enum.targetaudience", EARLY);

enum class WRITEMETA
{
	DEFAULT = 1 << 0,							// Default output.
	WARNING = 1 << 1,							// Warning output.
	CRITICAL = 1 << 2,						// Critical output.

	NONEWLINE = 1 << 3,						// No \n add the end of the string

	UI_SYNC_DRAW = 1 << 12				// Make a synchronous UI redraw
} MAXON_ENUM_FLAGS(WRITEMETA, "net.maxon.datatype.enum.writemeta", EARLY);

/// output flags for console output
enum class OUTPUT
{
	DIAGNOSTIC		= (1 << 0),	 ///< diagnostic output, shows up if this group of output is activated. This is also the default
	WARNING				= (1 << 1),	 ///< warning output, shows up if this group of output is activated
	CRITICAL			= (1 << 2),	 ///< critical output, shows up if this group of output is activated

	NOLINEBREAK		= (1 << 29), ///< if set, no line break is added
	HEADER				= (1 << 30)  ///< if set, header with line number and file name is added
} MAXON_ENUM_FLAGS(OUTPUT, "net.maxon.datatype.enum.output", EARLY);

/// determines, whether a debugging environment is present. Note that this value will be false if the debugger was attached to a process
extern maxon::Bool	g_isDebuggerPresent;

/// determines, whether debug breaks will be executed. Note that g_isDebuggerPresent needs to be true, too in order to have an effect.
extern maxon::Bool	g_enableDebugBreak;

class FormatStatement;
class StringProxy;

// _ConsoleOutput version without additional parameters prints argument to str as is (no special treatment of % or @)
void _ConsoleOutput(OUTPUT flags, const Char* str, Int line, const Char* file);
void _ConsoleOutput(OUTPUT flags, const String& str, Int line, const Char* file);
void _ConsoleOutput(OUTPUT flags, StringProxy* str, Int line, const Char* file);

// _ApplicationOutput version without additional parameters prints argument to str as is (no special treatment of % or @)
void _ApplicationOutput(maxon::TARGETAUDIENCE t, maxon::WRITEMETA lvl, const maxon::String& str, Int line, const Char* file);
void _ApplicationOutput(maxon::TARGETAUDIENCE t, maxon::WRITEMETA lvl, const Char* str, Int line, const Char* file);
void _ApplicationOutput(maxon::TARGETAUDIENCE t, maxon::WRITEMETA lvl, const maxon::StringProxy* proxy, Int line, const Char* file);

// If you get a compiler error about "Use of undeclared identifier 'ToString'" as result of calling
// DiagnosticOutput() you must #include "maxon/string.h" in that source file to fix it.
template <typename T> inline void ToStrHlp(String& result, const T* x, const FormatStatement* formatStatement) { result = ToString(*x, formatStatement); }
using TOSTR = void (*)(String& result, const void* ptr, const FormatStatement* formatStatement);
template <typename T> inline TOSTR GetToStrHlp()
{
	// Clang and GCC need the second cast
	return (TOSTR) (void (*) (String&, const T*, const FormatStatement*)) &ToStrHlp<T>;
}

StringProxy* Format(const String& formatString, Int argsCnt, const void** args, TOSTR* argFuncs);
StringProxy* Format(const Char* formatString, Int argsCnt, const void** args, TOSTR* argFuncs);

template <Int ARGCNT, typename FORMATSTR, typename... ARGS>
inline StringProxy* FormatTemplateX(FORMATSTR formatString, const ARGS&... args)
{
	static_assert(sizeof...(ARGS) == ARGCNT, "Number of arguments mismatch.");
	const void* argPtr[] = { (const void*)&args..., nullptr };
	TOSTR argFuncs[] = { GetToStrHlp<ARGS>()..., nullptr };
	return Format(formatString, ARGCNT, argPtr, argFuncs);
}

// if only one argument is specified no formatting takes place - the string stays 'as is'
template <Int ARGCNT, typename FORMATSTR> inline FORMATSTR FormatTemplateX(FORMATSTR formatString) { static_assert(ARGCNT == 0, "Number of arguments mismatch."); return formatString; }

/// cosntexpr which returns the number of '@' parameters in a Format string.
constexpr inline Int GetArgCnt(const Char* const formatStr)
{
	return formatStr[0] == 0 ? 0 : (formatStr[0] == '@' ? (formatStr[1] == '@' ? GetArgCnt(formatStr + 2) : GetArgCnt(formatStr + 1) + 1) : GetArgCnt(formatStr + 1));
}

// this helper class allows to differentiate between const Char[] arguments
// and all other types (e.g. String, CString, const Char*)
template <Int ARGCNT, typename FORMATSTR> class FormatTemplateHelper
{
public:
	static Bool FormatTemplateCheck(const FORMATSTR& formatString)
	{
		return true;
	}
};

// specialization for Char[]
template <Int ARGCNT, Int N> class FormatTemplateHelper<ARGCNT, const Char(&)[N]>
{
public:
	static constexpr Bool FormatTemplateCheck(const Char* const formatStr)
	{
		return GetArgCnt(formatStr) == ARGCNT;
	}
};

// FORMATTEMPLATECHECK trick is used to detect if 0 parameters, if 0 parameters are given
// no check is performed, if argCnt is > 0 a check if the argument count matches is performed.
#define FORMATTEMPLATECHECK0(formatString, ...)
#define FORMATTEMPLATECHECK1(formatString, ...) static_assert(!std::is_same<std::remove_extent<std::remove_reference<decltype(formatString)>::type>::type, const maxon::Char>::value || maxon::FormatTemplateHelper<MAXON_VA_NARGS(__VA_ARGS__), decltype(formatString)>::FormatTemplateCheck(formatString), "Number of arguments mismatch.");

// FORMATTEMPLATECHECK_A/B/C trick to allow MAXON_EXPAND to expand to FORMATTEMPLATECHECK0 or FORMATTEMPLATECHECK1
#define FORMATTEMPLATECHECK_C(count, formatString, ...) MAXON_EXPAND(FORMATTEMPLATECHECK##count(formatString, __VA_ARGS__))
#define FORMATTEMPLATECHECK_B(count, formatString, ...) FORMATTEMPLATECHECK_C(count, formatString, __VA_ARGS__)
#define FORMATTEMPLATECHECK_A(count, formatString, ...) FORMATTEMPLATECHECK_B(count, formatString, __VA_ARGS__)

#define FORMATTEMPLATECHECK(formatString, ...) FORMATTEMPLATECHECK_A(MAXON_VA_ARGS_POPULATED(__VA_ARGS__), formatString, __VA_ARGS__)


// All routines that start with Debug (DebugOutput, DebugStop, DebugAssert) result in empty (non-speed critical) code in a release build

/// DebugOutput outputs text into the console.
/// It only has any effect in debug builds and does not cost any time in release builds.
/// It should be used for temporary output that must not be visible to a customer or external developer.
/// The full @ref outputsyntax can be used for the format string.
/// Note that if you do not specify any additional parameters after the formatting string no formatting takes place - the raw string will stay unchanged.
/// The flags are of type OUTPUT.
/// THREADSAFE.
#ifdef MAXON_TARGET_DEBUG
	#define DebugOutput(flags, formatString, ...) do { FORMATTEMPLATECHECK(formatString, ##__VA_ARGS__); maxon::_ConsoleOutput(flags, maxon::FormatTemplateX<MAXON_VA_NARGS(__VA_ARGS__)>(formatString, ##__VA_ARGS__), __LINE__, __FILE__); } while(false)
#else
	#define DebugOutput(flags, formatString, ...) do { FORMATTEMPLATECHECK(formatString, ##__VA_ARGS__); } while(false)
#endif

/// DiagnosticOutput outputs text into the console.
/// The output is visible in debug builds or in a release build when the debug console with diagnostic output is activated.
/// The full @ref outputsyntax can be used for the format string.
/// Note that if you do not specify any additional parameters after the formatting string no formatting takes place - the raw string will stay unchanged.
/// THREADSAFE.
#define DiagnosticOutput(formatString, ...) do { FORMATTEMPLATECHECK(formatString, ##__VA_ARGS__); maxon::_ConsoleOutput(maxon::OUTPUT::DIAGNOSTIC, maxon::FormatTemplateX<MAXON_VA_NARGS(__VA_ARGS__)>(formatString, ##__VA_ARGS__), __LINE__, __FILE__); } while(false)

/// DiagnosticVarOutput outputs the values of variables into the console. It shows the variable names as well as their values.
/// E.g. write @c{DiagnosticVarOutput(x, _y, v.z);} to get an output like @c{"x: 42, _y: 99, v.z: 0"}.
/// The output is visible in debug builds or in a release build when the debug console with diagnostic output is activated.
/// THREADSAFE.
#define DiagnosticVarOutput(...) DiagnosticOutput(MAXON_MAKE_LIST(PRIVATE_MAXON_DiagnosticVarOutput, , ", ", , __VA_ARGS__), __VA_ARGS__)
#define PRIVATE_MAXON_DiagnosticVarOutput(x, i, a) #x ": @"

/// OutputWithFlags outputs text into the console.
/// The output is visible in debug builds or in a release build when the debug console with diagnostic output is activated.
/// The full @ref outputsyntax can be used for the format string.
/// Note that if you do not specify any additional parameters after the formatting string no formatting takes place - the raw string will stay unchanged.
/// THREADSAFE.
#define OutputWithFlags(flags, formatString, ...) do { FORMATTEMPLATECHECK(formatString, ##__VA_ARGS__); maxon::_ConsoleOutput(flags, maxon::FormatTemplateX<MAXON_VA_NARGS(__VA_ARGS__)>(formatString, ##__VA_ARGS__), __LINE__, __FILE__); } while(false)

/// WarningOutput outputs text into the console.
/// The output is visible in debug builds or in a release build when the debug console with warning output is activated.
/// It should only be used to output unexpected, non-critical conditions.
/// It automatically shows header information and adds a line break.
/// The full @ref outputsyntax can be used for the format string.
/// Note that if you do not specify any additional parameters after the formatting string no formatting takes place - the raw string will stay unchanged.
/// THREADSAFE.
#define WarningOutput(formatString, ...) do { FORMATTEMPLATECHECK(formatString, ##__VA_ARGS__); maxon::_ConsoleOutput(maxon::OUTPUT::WARNING | maxon::OUTPUT::HEADER, maxon::FormatTemplateX<MAXON_VA_NARGS(__VA_ARGS__)>(formatString, ##__VA_ARGS__), __LINE__, __FILE__); } while(false)

/// CriticalOutput outputs text into the console.
/// The output is visible in debug builds or in a release build when the debug console with critical output is activated.
/// It should only be used to output unexpected, critical conditions that would most likely result in instability, e.g. an illegal array access or corrupt object structure.
/// It can also be used for unexpected events, e.g. if a necessary module cannot be initialized.
/// It automatically shows header information and adds a line break.
/// It automatically stops the debugger if present.
/// The full @ref outputsyntax can be used for the format string.
/// Note that if you do not specify any additional parameters after the formatting string no formatting takes place - the raw string will stay unchanged.
/// THREADSAFE.
#define CriticalOutput(formatString, ...) do { FORMATTEMPLATECHECK(formatString, ##__VA_ARGS__); maxon::_ConsoleOutput(maxon::OUTPUT::CRITICAL | maxon::OUTPUT::HEADER, maxon::FormatTemplateX<MAXON_VA_NARGS(__VA_ARGS__)>(formatString, ##__VA_ARGS__), __LINE__, __FILE__); if (MAXON_UNLIKELY(maxon::g_isDebuggerPresent && maxon::g_enableDebugBreak)) __debugbreak(); } while(false)

/// ApplicationOutput outputs text to the application console.
/// The output is visible in the GUI version of the application.
/// The full @ref outputsyntax can be used for the format string.
/// Note that if you do not specify any additional parameters after the formatting string no formatting takes place - the raw string will stay unchanged.
/// THREADSAFE.
#define ApplicationOutput(formatString, ...) do { FORMATTEMPLATECHECK(formatString, ##__VA_ARGS__); maxon::_ApplicationOutput(maxon::TARGETAUDIENCE::ALL, maxon::WRITEMETA::DEFAULT, maxon::FormatTemplateX<MAXON_VA_NARGS(__VA_ARGS__)>(formatString, ##__VA_ARGS__), __LINE__, __FILE__); } while(false)

// OUTPUTCHECK1 trick is used to detect if 0 or more parameters are given.
// if 0 parameters are given A is returned, otherwise B
#define OUTPUTCHECK0(A, B) A
#define OUTPUTCHECK1(A, B) B

// FORMATTEMPLATECHECK_A/B/C trick to allow MAXON_EXPAND to expand to FORMATTEMPLATECHECK0 or FORMATTEMPLATECHECK1
#define OUTPUTCHECK_C(count, A, B) MAXON_EXPAND(OUTPUTCHECK##count(A, B))
#define OUTPUTCHECK_B(count, A, B) OUTPUTCHECK_C(count, A, B)
#define OUTPUTCHECK_A(count, A, B) OUTPUTCHECK_B(count, A, B)

#define OUTPUTCHECK(A, B, ...) OUTPUTCHECK_A(MAXON_VA_ARGS_POPULATED(__VA_ARGS__), A, B)


/// DebugStop stops the execution of the application if it is a debug build and a debugger is present. In case of a debug build the file and line number are output (critical output category).
/// A C string can be passed as argument that will be output as well.
/// THREADSAFE.
#ifdef MAXON_TARGET_DEBUG
	#define DebugStop(...)	do { MAXON_EXPAND(DebugOutput(maxon::OUTPUT::CRITICAL | maxon::OUTPUT::HEADER, OUTPUTCHECK("Debug Stop", "Debug Stop: ", ##__VA_ARGS__) __VA_ARGS__)); if (MAXON_UNLIKELY(maxon::g_isDebuggerPresent && maxon::g_enableDebugBreak)) __debugbreak(); } while (false)
#else
	#define DebugStop(...)	do { } while(false)
#endif

/// CriticalStop stops the execution of the application if a debugger is present. The file and line number are output (critical output category).
/// A C string can be passed as argument that will be output as well.
/// THREADSAFE.
#define CriticalStop(...) do { MAXON_EXPAND(CriticalOutput(OUTPUTCHECK("Stop", "Stop: ", ##__VA_ARGS__) __VA_ARGS__)); } while (false)

#ifdef MAXON_TARGET_MACOS
#define	__DEBUGGING__																				// avoid conflicts with DebugAssert() definition for the Mac
#endif

/// DebugAssert is a conditional DebugStop. It does the same as DebugStop() if 'condition' is false. A C string can be passed as optional argument for output.
/// THREADSAFE.
#if defined MAXON_TARGET_DEBUG
	#define DebugAssert(condition, ...) do { if (!(condition)) { MAXON_EXPAND(DebugOutput(maxon::OUTPUT::CRITICAL |maxon::OUTPUT::HEADER, OUTPUTCHECK("Debug Assertion failed: " #condition, "Debug Assertion failed: ", ##__VA_ARGS__) __VA_ARGS__)); if (MAXON_UNLIKELY(maxon::g_isDebuggerPresent && maxon::g_enableDebugBreak)) __debugbreak(); } } while(false)
#else
	#define DebugAssert(condition, ...) do { } while(false)
#endif

/// CriticalAssert is a conditional CriticalStop. It does the same as CriticalStop() if 'condition' is false. A C string can be passed as optional argument for output.
/// THREADSAFE.
#define CriticalAssert(condition, ...) do { if (!(condition)) { MAXON_EXPAND(CriticalOutput(OUTPUTCHECK("Assertion failed: " #condition, "Assertion failed: ", ##__VA_ARGS__) __VA_ARGS__)); } } while(false)

/// SizeAssert is a static assert verified at compile-time. It checks if the passed type is of size 's'.
/// On failure an exception of negative STATICASSERT_CONDITION_FALSE is raised.
/// THREADSAFE.
#define SizeAssert(type,s) static_assert(sizeof(type)==s,"type is not of passed size")

/// @}

} // namespace maxon

#endif // DEBUGDIAGNOSTICS_H__
