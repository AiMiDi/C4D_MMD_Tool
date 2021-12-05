#ifndef WINDOWS_INCLUDE_H__
#define WINDOWS_INCLUDE_H__

// Rename Windows LONG/ULONG type as it collides with Cinema 4D API's new definition
#define LONG	WinLONG
#define ULONG	WinULONG

// Prevent include of Windows dialog definitions that will collide with Cinema 4D API's types
#define	WIN32_LEAN_AND_MEAN

#include <windows.h>

#include "maxon/utilities/undef_win_macros.h"

#undef LONG
#undef ULONG
#undef OPTIONAL // sometimes used in enums
//#undef OUT

#undef GetMessage
#undef SetJob
#undef GetJob
#undef EnumJobs
#undef StartDoc
#undef EnumPorts
#undef AddPort
#undef ConfigurePort
#undef DeletePort
#undef LoadString
#undef StartDoc
#undef AddFontResource
#undef CreateProcess

#endif // WINDOWS_INCLUDE_H__
