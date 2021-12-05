#include "maxon/apibase.h"
#include "maxon/configuration.h"
#include "maxon/crashhandler.h"

namespace maxon
{

const Char* CrashLogKey::LOADEDMODULES = "LoadedModules";
const Char* CrashLogKey::MODULENAME = "ModuleName";
const Char* CrashLogKey::THREADS = "Threads";
const Char* CrashLogKey::CALLSTACK = "Callstack";
const Char* CrashLogKey::ADDRESS = "Address";
const Char* CrashLogKey::PROPERTIES = "Properties";
const Char* CrashLogKey::THREADNAME = "ThreadName";
const Char* CrashLogKey::BASEADDRESS = "BaseAddress";
const Char* CrashLogKey::BUILD = "Build";
const Char* CrashLogKey::FUNCTIONNAME = "FunctionName";
const Char* CrashLogKey::SOURCEFILE = "SourceFileName";
const Char* CrashLogKey::LINE = "SourceLine";
const Char* CrashLogKey::THREADNUMBER = "ThreadNumber";
const Char* CrashLogKey::REGISTERS = "Registers";
const Char* CrashLogKey::DOCUMENTS = "Documents";
const Char* CrashLogKey::DOCUMENTNAME = "DocumentName";
const Char* CrashLogKey::DOCUMENTPATH = "DocumentPath";
const Char* CrashLogKey::COMPUTERINFO = "ComputerInfo";
const Char* CrashLogKey::APPLICATIONINFO = "ApplicationInfo";
const Char* CrashLogKey::EXCEPTION = "Exception";
const Char* CrashLogKey::CRITICALLOG = "CriticalLog";

MAXON_CONFIGURATION_BOOL(g_inCrashhandler, false, CONFIGURATION_CATEGORY::NONE, "");

} // namespace maxon
