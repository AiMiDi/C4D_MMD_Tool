#include "maxon/stacktrace.h"

#ifdef MAXON_TARGET_WINDOWS

#include <windows.h>

namespace maxon
{

// Must implement this in a separate file because Windows headers pollute everything.
MAXON_ATTRIBUTE_NO_INLINE Int StackTrace::GetBacktrace(Int skip, const Block<void*>& functionPointers)
{
	Int capacity = functionPointers.GetCount();
	void** backtraceData = functionPointers.GetFirst();

	USHORT arrayCount = RtlCaptureStackBackTrace(DWORD(skip + 1), DWORD(capacity), backtraceData, nullptr);

	// Terminate the array.
	if (arrayCount < capacity)
		backtraceData[arrayCount] = nullptr;

	return arrayCount;
}

} // namespace maxon

#endif

#ifdef MAXON_TARGET_ANDROID

namespace maxon
{

Int StackTrace::GetBacktrace(Int skip, const Block<void*>& functionPointers)
{
	return 0;
}

} // namespace maxon

#endif
