#define MAXON_DEPENDENCY_ENABLE // so that MAXON_INITIALIZATION can be used, and that this file takes part in the dependency analysis

#include "maxon/application.h"
#include "maxon/cpuid.h"
#include "maxon/machineinfo.h"

namespace maxon
{

// 	constexpr Bool g_hasSSE2 = true;
// 	constexpr Bool g_hasSSE3 = true;
// 	constexpr Bool g_hasSSSE3 = true;
// 	constexpr Bool g_hasSSE4_1 = true;
// 	constexpr Bool g_hasSSE4_2 = true;
Bool g_hasAVX = 0;
Bool g_hasFMA = 0;
Bool g_hasAES = 0;
Bool g_hasPCLMULQDQ = 0;
Bool g_hasAVX2 = 0;

// In c4d the kernel sets the cpu feature flags the first time the module allocates something (happens in c4d_pmain.cpp)
static Result<void> InitializeCPUID()
{
	DataDictionary machineInfo = Application::GetMachineInfo();

// 	g_hasSSE2 = machineInfo.Get(MACHINEINFO::SUPPORTSSE2, false);
// 	g_hasSSE3 = machineInfo.Get(MACHINEINFO::SUPPORTSSE3, false);
// 	g_hasSSSE3 = machineInfo.Get(MACHINEINFO::SUPPORTSSSE3, false);
// 	g_hasSSE4_1 = machineInfo.Get(MACHINEINFO::SUPPORTSSE41, false);
// 	g_hasSSE4_2 = machineInfo.Get(MACHINEINFO::SUPPORTSSE42, false);
	g_hasAVX = machineInfo.Get(MACHINEINFO::SUPPORTAVX, false);
	g_hasFMA = machineInfo.Get(MACHINEINFO::SUPPORTFMA, false);
	g_hasAES = machineInfo.Get(MACHINEINFO::SUPPORTAES, false);
	g_hasPCLMULQDQ = machineInfo.Get(MACHINEINFO::SUPPORTPCLMULQDQ, false);
	g_hasAVX2 = machineInfo.Get(MACHINEINFO::SUPPORTAVX2, false);

	return OK;
}

MAXON_INITIALIZATION(InitializeCPUID, nullptr);
MAXON_DEPENDENCY_REGISTER(cpuidinit)

} // namespace maxon
