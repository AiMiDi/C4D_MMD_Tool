#include "maxon/cpuyield.h"
#include "maxon/configuration.h"
#include <stdio.h>

namespace maxon
{

MAXON_CONFIGURATION_BOOL(g_trackCpuYield, false, CONFIGURATION_CATEGORY::DEVELOPMENT, "Track usage of Spinlocks (either for performance checks or deadlock detection)");

extern "C"
{
	static void DummySwitchDelegate(CpuYieldState*, const void*)
	{
	}
	MAXON_ATTRIBUTE_DLL_PUBLIC CpuYieldState::SwitchDelegate g_CpuYieldDelegate = &DummySwitchDelegate;
}

void CpuYield::Pause()
{
	if (MAXON_LIKELY(_count <= LOOPS_BEFORE_YIELD))
	{
		// Log the beginning of a spin loop if g_trackCpuYield is enabled.
		if (MAXON_UNLIKELY(_count == 0 && g_trackCpuYield))
			g_CpuYieldDelegate(this, _resource);
	
		_count += _loopSize;

		Wait(_loopSize >> 3);

		_loopSize *= 2;

		// Restart again with smaller pause if the maximum granularity has been reached.
		if (_loopSize > LOOPS_MAX_GRANULARITY)
			_loopSize = LOOPS_START_COUNT;
	}
	else
	{
		// Jump into the kernel for more complex handling, e.g. ask the OS to switch to a different thread to decrease contention. g_CpuYieldDelegate is guaranteed to be valid.
		g_CpuYieldDelegate(this, _resource);
	}
}

} // namespace maxon
