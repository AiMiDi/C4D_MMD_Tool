#include "maxon/system.h"
#include "c4d_memory.h"

#ifdef CINEWARE_NAMESPACE_ENABLE
	CINEWARE_NAMESPACE_BEGIN
#endif

// try to estimate how much physical memory is still unused
UInt GeMemGetFreePhysicalMemoryEstimate()
{
	Int estimate;
	maxon::System::MemoryDiagnostics(maxon::System::MEMORYDIAGNOSTICSMODE::ESTIMATEONLY, nullptr, &estimate);
	return UInt(estimate);
}

#ifdef CINEWARE_NAMESPACE_ENABLE
	CINEWARE_NAMESPACE_END
#endif
