#ifndef WIN_VERSION_H__
#define WIN_VERSION_H__

#ifdef MAXON_TARGET_WINDOWS

#include "maxon/win_include.h"
#include "maxon/apibase.h"

namespace maxon
{

Bool GetWindowsVersionEx(::OSVERSIONINFOEXW* info);

} // namespace maxon

#endif

#endif // WIN_VERSION_H__
