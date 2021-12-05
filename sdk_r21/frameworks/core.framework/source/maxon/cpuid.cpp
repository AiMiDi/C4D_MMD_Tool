#define MAXON_DEPENDENCY_ENABLE // so that MAXON_INITIALIZATION can be used, and that this file takes part in the dependency analysis

#include "maxon/apibase.h"
#include "maxon/application.h"
#include "maxon/cpuid.h"
#include "maxon/machineinfo.h"

namespace maxon
{

#ifndef __USE_CPU_FEATURE_INTRINSICS
	Bool g_hasSSE2 = 0;
	Bool g_hasSSE3 = 0;
	Bool g_hasSSSE3 = 0;
	Bool g_hasSSE4_1 = 0;
	Bool g_hasSSE4_2 = 0;
	Bool g_hasAVX = 0;
	Bool g_hasFMA = 0;
	Bool g_hasAES = 0;
	Bool g_hasPCLMULQDQ = 0;
	Bool g_hasAVX2 = 0;
#endif

// In c4d the kernel sets the cpu feature flags the first time the module allocates something (happens in c4d_pmain.cpp)
static Result<void> InitializeCPUID()
{
	DataDictionary machineInfo = Application::GetMachineInfo();

#ifndef __USE_CPU_FEATURE_INTRINSICS
	g_hasSSE2 = machineInfo.Get(MACHINEINFO::SUPPORTSSE2, false);
	g_hasSSE3 = machineInfo.Get(MACHINEINFO::SUPPORTSSE3, false);
	g_hasSSSE3 = machineInfo.Get(MACHINEINFO::SUPPORTSSSE3, false);
	g_hasSSE4_1 = machineInfo.Get(MACHINEINFO::SUPPORTSSE41, false);
	g_hasSSE4_2 = machineInfo.Get(MACHINEINFO::SUPPORTSSE42, false);
	g_hasAVX = machineInfo.Get(MACHINEINFO::SUPPORTAVX, false);
	g_hasFMA = machineInfo.Get(MACHINEINFO::SUPPORTFMA, false);
	g_hasAES = machineInfo.Get(MACHINEINFO::SUPPORTAES, false);
	g_hasPCLMULQDQ = machineInfo.Get(MACHINEINFO::SUPPORTPCLMULQDQ, false);
	g_hasAVX2 = machineInfo.Get(MACHINEINFO::SUPPORTAVX2, false);
#endif

	return OK;
}

MAXON_INITIALIZATION(InitializeCPUID, nullptr);
MAXON_DEPENDENCY_REGISTER(cpuidinit)

} // namespace maxon
