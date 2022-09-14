#include "maxon/profiler.h"
#include "maxon/configuration.h"
#include "maxon/branch.h"

namespace maxon
{
// constexpr bool g_enableInCodeProfilerDefaultValue = MAXON_AM_IN_BRANCH("dev_mesh") || MAXON_AM_IN_BRANCH("dev_animation");
	// TODO: (Alain/Philippe) Too much info in the shell at startup, and too many warnings causing polution on the build server at the execution of many steps.  To clean up before enabling for all devs in the modeling/animation teams.
constexpr bool g_enableInCodeProfilerDefaultValue = false;
MAXON_CONFIGURATION_BOOL(g_enableInCodeProfiler, g_enableInCodeProfilerDefaultValue, CONFIGURATION_CATEGORY::DEVELOPMENT, "Enable in-code profiler");
MAXON_CONFIGURATION_BOOL(g_enableProfilerDumpRegistry, false, CONFIGURATION_CATEGORY::DEVELOPMENT, "Enable profiler dump registry");
MAXON_CONFIGURATION_BOOL(g_enableProfilerDumpRegistryErrors, g_enableInCodeProfilerDefaultValue, CONFIGURATION_CATEGORY::DEVELOPMENT, "Enable profiler dump registry errors");
MAXON_CONFIGURATION_BOOL(g_enableProfilerGetMethodNameTrace, g_enableInCodeProfilerDefaultValue, CONFIGURATION_CATEGORY::DEVELOPMENT, "Enable profiler GetMethodName trace");
} // namespace maxon
