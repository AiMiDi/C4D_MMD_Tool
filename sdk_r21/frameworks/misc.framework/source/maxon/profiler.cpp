#include "maxon/profiler.h"
#include "maxon/configuration.h"
#include "maxon/branch.h"

namespace maxon
{
MAXON_CONFIGURATION_BOOL(g_enableInCodeProfiler, false,	CONFIGURATION_CATEGORY::DEVELOPMENT, "Enable in-code profiler");
} // namespace maxon
