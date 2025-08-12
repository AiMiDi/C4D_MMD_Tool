#ifndef DEBUGGLOBALS_H__
#define DEBUGGLOBALS_H__

#include "maxon/apibase.h"
#include <stdio.h>
#include <stdarg.h>

namespace maxon
{

class Debugger
{
public:
	static Bool	IsPresent();
};

// stylecheck.naming=false

inline Int sprintf_safe(Char *_DstBuf, Int _MaxCount, const Char * _Format, ...)
{
	if (_MaxCount <= 0)
		return 0;

	va_list arp;
	va_start(arp, _Format);

	Int res = vsnprintf(_DstBuf, (size_t)_MaxCount, _Format, arp);
	if (res < 0 || res >= _MaxCount)
	{
		if (res < 0)
			DebugStop();
		_DstBuf[_MaxCount - 1] = 0;
		res = _MaxCount - 1;
	}
	va_end(arp);
	return res;
}

} // namespace maxon

#endif // DEBUGGLOBALS_H__
