#ifndef WIN_INCLUDE_H__
#define WIN_INCLUDE_H__

// this is the one and only central include file that loads windows.h with all the right macro definitions
#ifdef MAXON_TARGET_WINDOWS
	#if defined(__INTEL_COMPILER)
		#pragma warning(disable:47)		// incompatible redefinition of macro "D3D11_ERROR_DEFERRED_CONTEXT_MAP_WITHOUT_INITIAL_DISCARD" (declared at line 49845 of "C:\Program Files (x86)\Windows Kits\8.0\Include\shared\winerror.h")
		#pragma warning(disable:1885)	// #pragma region unclosed at end of file
	#else
		#pragma warning(disable:4005)	// incompatible redefinition of macro "D3D11_ERROR_DEFERRED_CONTEXT_MAP_WITHOUT_INITIAL_DISCARD" (declared at line 49845 of "C:\Program Files (x86)\Windows Kits\8.0\Include\shared\winerror.h")
	#endif

	#pragma push_macro("id")
	#undef id
//	#define _WIN32_DCOM	// define for for CoInitializeEx
//	#define _WIN32_WINNT 0x0501	// Windows Server 2003, Windows XP	0x0501, //http://msdn.microsoft.com/en-us/library/aa383745%28VS.85%29.aspx
	#pragma warning(disable:4264)
	#pragma warning(disable:4263)
	#include <windows.h>
	#include <windowsx.h>

	#pragma pop_macro("id")

#endif

#endif // WIN_INCLUDE_H__

// This is placed behind the header guard so that the clean-up always happens.
#include "maxon/utilities/undef_win_macros.h"
