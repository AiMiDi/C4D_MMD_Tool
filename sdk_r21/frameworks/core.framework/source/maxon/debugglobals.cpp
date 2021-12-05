#if defined(MAXON_TARGET_MACOS) || defined(MAXON_TARGET_IOS)
	#include <assert.h>
	#include <unistd.h>
	#include <sys/sysctl.h>
#elif defined(MAXON_TARGET_WINDOWS)
	#include "maxon/win_include.h"
#elif defined MAXON_TARGET_LINUX
	#include <unistd.h>
	#include <sys/ptrace.h>
	#include <sys/types.h>
	#include <sys/wait.h>
	#include <errno.h>
	#include <limits.h>
#elif defined MAXON_TARGET_ANDROID
	#include <android/log.h>
#endif

#include "maxon/debugglobals.h"
#include "maxon/configuration.h"
#include "maxon/timer.h"
#include "maxon/stringconversion.h"
#include "maxon/cstdliballocator.h"
#include "maxon/logger.h"

namespace maxon
{

StringProxy* Format(const String& formatString, Int argsCnt, const void** args, TOSTR* argFuncs)
{
	return StringConversion::FormatXArgs(formatString, argsCnt, args, argFuncs);
}

StringProxy* Format(const Char* formatString, Int argsCnt, const void** args, TOSTR* argFuncs)
{
	return StringConversion::FormatXArgs(String(formatString), argsCnt, args, argFuncs);
}

String ToString(const void* val, const FormatStatement* formatStatement, Bool dummy)
{
	FormatStatement tmp;
	if (formatStatement && formatStatement->Get("int").IsPopulated())
		tmp.Set("int", formatStatement->Get("int")) iferr_ignore("Ignore errors for ToString");
	else
		tmp.Set("int", "x"_cs) iferr_ignore("Ignore errors for ToString"); // force hexadecimal output unless manually overwritten

	String str;
	StringConversion::AppendUInt(str.MakeWritable().GetPointer(), (UInt)val, SIZEOF(val), &tmp);
	return str;
}

static const Char g_warning[] = "WARNING: ";
static const Char g_critical[] = "CRITICAL: ";

// check whether the System interface is already initialized and if necessary use printf() to enable console output during startup
static void _PrivateConsoleOutput(const Char* s, const SourceLocation& loc)
{
#ifdef MAXON_TARGET_ANDROID
	int type = ANDROID_LOG_INFO;
	if (strstr(s, g_warning) == s)
		type = ANDROID_LOG_WARN;
	else if (strstr(s, g_critical) == s)
		type = ANDROID_LOG_ERROR;
	__android_log_print(type, "Maxon Android App", "%s", s);
#else

	if (LoggerInterface::_interface.IsInitialized() && System::_interface.IsInitialized() && ThreadServices::_interface.IsInitialized())
	{
		System::_ConsoleOutput(s, loc);
	}
	else
	{
		printf("%s", s);

#ifdef MAXON_TARGET_WINDOWS
		OutputDebugStringA(s);
#endif
	}
#endif
}

static OUTPUT g_enabledOutput = OUTPUT::DIAGNOSTIC | OUTPUT::WARNING | OUTPUT::CRITICAL | OUTPUT::NOLINEBREAK;

static void InitializeAndSetConsoleOutput()
{
	static Bool	hasCheckedDebugger = false;
	if (hasCheckedDebugger == false)
	{
		g_isDebuggerPresent = Debugger::IsPresent();
		g_enabledOutput = OUTPUT::DIAGNOSTIC | OUTPUT::WARNING | OUTPUT::CRITICAL | OUTPUT::NOLINEBREAK;
		hasCheckedDebugger = true;
	}

	if ((g_enabledOutput & OUTPUT::NOLINEBREAK) && System::_interface.IsInitialized())	// detect first use
		g_enabledOutput = System::GetConsoleOutputType();
}

void _ConsoleOutput(OUTPUT flags, const Char* str, Int line, const Char* file)
{
	InitializeAndSetConsoleOutput();

	if (!(g_enabledOutput & flags & (OUTPUT::DIAGNOSTIC | OUTPUT::WARNING | OUTPUT::CRITICAL)))
		return;

	// use CStdLibAllocator as fallback as console output happens before the system is up or after the system has been shut down
	BaseArray<Char, 16, BASEARRAYFLAGS::NONE, FixedBufferAllocator<Char, 2048, CStdLibAllocator>> result;

	// merge file and line number into a single C string
	const Int bufMax = 1024;
	Char buf[bufMax];

	buf[0] = 0;
	if (flags & OUTPUT::HEADER)
	{
		if (MAXON_UNLIKELY(g_isDebuggerPresent))
		{
			sprintf_safe(buf, bufMax - 1, "%s(%d): ", file, line);
		}
		else
		{
			const Char* f = strrchr(file, '/');
			if (f)
			{
				f++;
			}
			else
			{
				f = strrchr(file, '\\');
				if (f)
					f++;
				else
					f = file;
			}
			sprintf_safe(buf, bufMax - 1, " [%s(%d)]", f, line);
		}
	}

	// calculate total C string length
	Int bufLen = (Int) strlen(buf), strLen = (Int) strlen(str);
	Int length = bufLen + strLen;

	if (flags & OUTPUT::WARNING)
		length += strlen(g_warning);
	else if (flags & OUTPUT::CRITICAL)
		length += strlen(g_critical);

	if (!(flags & OUTPUT::NOLINEBREAK))
		length++;

	// one additional character for terminating 0C
	if (result.Resize(length + 1) == FAILED)
		return;

	Char* dst = result.GetFirst();

	if (g_isDebuggerPresent && (flags & OUTPUT::HEADER))
	{
		MemCopy(dst, buf, bufLen);
		dst += bufLen;
	}

	if (flags & OUTPUT::WARNING)
	{
		MemCopy(dst, g_warning, (Int) strlen(g_warning));
		dst += strlen(g_warning);
	}
	else if (flags & OUTPUT::CRITICAL)
	{
		MemCopy(dst, g_critical, (Int) strlen(g_critical));
		dst += strlen(g_critical);
	}

	MemCopy(dst, str, strLen);
	dst += strLen;

	if (!g_isDebuggerPresent && (flags & OUTPUT::HEADER))
	{
		MemCopy(dst, buf, bufLen);
		dst += bufLen;
	}

	if (!(flags & OUTPUT::NOLINEBREAK))
		*dst++ = '\n';

	*dst++ = 0;

	DebugAssert(dst - result.GetFirst() == result.GetCount());

	_PrivateConsoleOutput(result.GetFirst(), SourceLocation(file, line));
}

void _ConsoleOutput(OUTPUT flags, const String& str, Int line, const Char* file)
{
	// use CStdLibAllocator as fallback as console output happens before the system is up or after the system has been shut down
	BaseArray<Char, 16, BASEARRAYFLAGS::NONE, FixedBufferAllocator<Char, 2048, CStdLibAllocator>> buf;

	iferr (str.GetCStringAppendArray(buf, GetUtf8DefaultEncoder()))
	{
		DebugStop();
		return;
	}
	iferr (buf.Append(0))
	{
		DebugStop();
		return;
	}
	_ConsoleOutput(flags, buf.GetFirst(), line, file);
}

void _ConsoleOutput(OUTPUT flags, StringProxy* proxy, Int line, const Char* file)
{
	if (proxy)
	{
		_ConsoleOutput(flags, proxy->str, line, file);
		DeleteObj(proxy);
	}
	else
	{
		_ConsoleOutput(OUTPUT::CRITICAL | OUTPUT::HEADER, "Console output failed", line, file);
	}
}

void _ApplicationOutput(maxon::TARGETAUDIENCE t, maxon::WRITEMETA lvl, const maxon::String& str, Int line, const Char* file)
{
	maxon::Loggers::Default().Write(t, str, SourceLocation(file, line), lvl) iferr_ignore("Not being able to write to the log file is ignored");
}

void _ApplicationOutput(maxon::TARGETAUDIENCE t, maxon::WRITEMETA lvl, const Char* str, Int line, const Char* file)
{
	maxon::Loggers::Default().Write(t, maxon::String(str), SourceLocation(file, line), lvl) iferr_ignore("Not being able to write to the log file is ignored");
}

void _ApplicationOutput(maxon::TARGETAUDIENCE t, maxon::WRITEMETA lvl, const maxon::StringProxy* proxy, Int line, const Char* file)
{
	if (proxy)
	{
		_ApplicationOutput(t, lvl, proxy->str, line, file);
		DeleteObj(proxy);
	}
	else
	{
		_PrivateConsoleOutput("Console output failed", SourceLocation(file, line));
	}
}

#if defined(MAXON_TARGET_MACOS) || defined(MAXON_TARGET_IOS)
// Returns true if the current process is being debugged (either
// running under the debugger or has a debugger attached post facto).
Bool Debugger::IsPresent()
{
	int	junk;
	int	mib[4];
	struct kinfo_proc info;
	size_t size;

	// Initialize the flags so that, if sysctl fails for some bizarre
	// reason, we get a predictable result.

	info.kp_proc.p_flag = 0;

	// Initialize mib, which tells sysctl the info we want, in this case
	// we're looking for information about a specific process ID.

	mib[0] = CTL_KERN;
	mib[1] = KERN_PROC;
	mib[2] = KERN_PROC_PID;
	mib[3] = getpid();

	// Call sysctl.

	size = SIZEOF(info);
	junk = sysctl(mib, SIZEOF(mib) / SIZEOF(*mib), &info, &size, nullptr, 0);
	assert(junk == 0);

	// We're being debugged if the P_TRACED flag is set.

	return (info.kp_proc.p_flag & P_TRACED) != 0;
}

#elif defined(MAXON_TARGET_WINDOWS)

Bool Debugger::IsPresent()
{
	return IsDebuggerPresent() != 0;
}

#elif defined(MAXON_TARGET_ANDROID)
Bool Debugger::IsPresent()
{
	return false;
}

#elif defined(MAXON_TARGET_LINUX)

// http://stackoverflow.com/questions/3596781/detect-if-gdb-is-running (does not work)
// The idea is to read /proc/<pid>/stat to check if any parent process is the gdb. If there is any error, the functions returns false.
Bool Debugger::IsPresent()
{
	int	 pid = getppid();
	int	 currPid;
	char tcomm[PATH_MAX + 1];
	char state;

	FILE* file;
	while (pid)
	{
		char fname[100];

		// get the executable name
		sprintf(fname, "/proc/%d/comm", pid);
		file = fopen(fname, "r");
		if (!file)
			break;
		if (fscanf(file, "%s ", tcomm) != 1)
		{
			fclose(file);
			break;
		}
		fclose(file);
		if (strcmp(tcomm, "gdb") == 0)
			return true;

		// gdb was not found, try the parent process
		sprintf(fname, "/proc/%d/stat", pid);
		file = fopen(fname, "r");
		if (file)
		{
			if (fscanf(file, "%d ", &currPid) == 1 &&
					fscanf(file, "%s ", tcomm) == 1 &&
					fscanf(file, "%c ", &state) == 1 &&
					fscanf(file, "%d ", &pid) == 1)
			{
				// found enough information to get the id of the parent process. Nothing to do here.
			}
			else
			{
				pid = 0;	// something went wrong
			}
			fclose(file);
		}
		else	// process does not exist
		{
			pid = 0;
		}
	}

	return false;
}

#endif

Bool g_isDebuggerPresent = Debugger::IsPresent();

MAXON_CONFIGURATION_BOOL(g_enableDebugBreak, true, CONFIGURATION_CATEGORY::DEVELOPMENT, "enable debug breaks (when debugger is attached)");
MAXON_CONFIGURATION_BOOL(g_enableParallelFor, true, CONFIGURATION_CATEGORY::DEVELOPMENT, "enable parallel execution of all ParallelFor loops");

} // namespace maxon
