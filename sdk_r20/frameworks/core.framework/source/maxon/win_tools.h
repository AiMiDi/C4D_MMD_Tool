#ifndef WIN_TOOLS_H__
#define WIN_TOOLS_H__

#include "maxon/apibase.h"
#include "maxon/objectbase.h"
#include "maxon/iobrowse.h"

MAXON_PREPROCESSOR_CONDITION(defined(MAXON_TARGET_WINDOWS));

// windows misses this function, so we implemented it in win_strptime.cpp
char *strptime(const char *buf, const char *fmt, tm *tm);

#endif // WIN_TOOLS_H__
