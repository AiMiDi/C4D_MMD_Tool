#include "maxon/system.h"
#include "c4d_memory.h"

// try to estimate how much physical memory is still unused
UInt GeMemGetFreePhysicalMemoryEstimate()
{
	Int estimate;
	maxon::System::MemoryDiagnostics(maxon::System::MEMORYDIAGNOSTICSMODE::ESTIMATEONLY, nullptr, &estimate);
	return UInt(estimate);
}
