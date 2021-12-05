#include "maxon/cpuyield.h"

namespace maxon
{

extern "C"
{
	MAXON_ATTRIBUTE_DLL_PUBLIC CpuYieldState::SwitchDelegate g_CpuYieldDelegate = nullptr;
}

} // namespace maxon
