#ifdef MAXON_TARGET_WINDOWS

#include "maxon/win_version.h"

namespace maxon
{

#define NT_SUCCESS(Status) (((NTSTATUS)(Status)) >= 0)
using RtlGetVersion_t = NTSTATUS(NTAPI*)(OSVERSIONINFOEXW *info);

// Replacement for GetVersionEx() which MS has intentionally broken in Windows 8.1 and 10. 
// Unless you prepare a special manifest, it will always return Win 8, build 9200.
// We use the kernel version info which exists since Win 2000, is internally also used for device drivers (and for returning
// the correct version when you set a special manifest). This one MS can't break without installing false device drivers.
Bool GetWindowsVersionEx(::OSVERSIONINFOEXW *info)
{
	HANDLE ntdllHandle = GetModuleHandle(TEXT("ntdll.dll"));

	if (ntdllHandle == nullptr)
		return false;

	RtlGetVersion_t RtlGetVersion = (RtlGetVersion_t)GetProcAddress((HMODULE)ntdllHandle, "RtlGetVersion");

	if (RtlGetVersion == nullptr)
		return false;

	return NT_SUCCESS(RtlGetVersion(info));
}

} // namespace maxon

#endif
