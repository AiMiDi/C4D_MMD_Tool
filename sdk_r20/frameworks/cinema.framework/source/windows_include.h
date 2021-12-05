#ifndef WINDOWS_INCLUDE_H__
#define WINDOWS_INCLUDE_H__

// Rename Windows LONG/ULONG type as it collides with CINEMA 4D API's new definition
#define LONG	WinLONG
#define ULONG	WinULONG

// Prevent include of Windows dialog definitions that will collide with CINEMA 4D API's types
#define	WIN32_LEAN_AND_MEAN

#include <windows.h>

#undef LONG
#undef ULONG
#undef OPTIONAL // sometimes used in enums
//#undef OUT
#undef INTERFACE // sometimes used as template parameter name\

#undef LoadString
#undef GetMessage
#undef AddJob
#undef SetJob
#undef GetJob
#undef EnumJobs
#undef GetFirstChild
#undef StartDoc
#undef GetObject
#undef EnumPorts
#undef AddPort
#undef ConfigurePort
#undef DeletePort
#undef LoadString
#undef SetPort
#undef StartDoc
#undef AddFontResource
#undef CreateProcess
#undef GetMessage
#undef PASSTHROUGH
#undef CreateWindow
#undef GetClassInfo

#endif // WINDOWS_INCLUDE_H__
