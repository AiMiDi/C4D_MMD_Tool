#ifndef OSX_INCLUDE_H__
#define OSX_INCLUDE_H__

// Avoid a conflict between UInt (in OSTypes.h) and in ge_sys_math.h
#define UInt OSXUInt

#include <Carbon/Carbon.h>

#undef UInt

#endif // OSX_INCLUDE_H__
