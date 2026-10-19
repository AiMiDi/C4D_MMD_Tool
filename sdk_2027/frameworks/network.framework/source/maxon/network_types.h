#ifndef NETWORK_TYPES_H__
#define NETWORK_TYPES_H__

#include "maxon/apibase.h"

// Basic types shared by different parts of the networking API.

namespace maxon
{
#ifdef MAXON_TARGET_WINDOWS
	typedef UInt SOCKET;

	typedef SysChar NETWORKCHAR;
	typedef SOCKET SocketT;
#else
	typedef int SOCKET;

	typedef Char NETWORKCHAR;
	typedef int SocketT;
#endif
}

#endif // NETWORK_TYPES_H__
