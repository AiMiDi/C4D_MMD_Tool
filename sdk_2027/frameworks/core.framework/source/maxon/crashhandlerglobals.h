#ifndef CRASHHANDLERGLOBALS_H__
#define CRASHHANDLERGLOBALS_H__

#include "maxon/apibase.h"

namespace maxon
{

extern Bool g_inCrashhandler;

class CrashHandlerGlobals
{
public:
	static inline Bool IsCrashed()	{ return g_inCrashhandler; }
};

} // namespace maxon

#endif // CRASHHANDLERGLOBALS_H__
