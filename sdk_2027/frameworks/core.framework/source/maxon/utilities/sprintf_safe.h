#ifndef SPRINTF_SAFE_H__
#define SPRINTF_SAFE_H__

#include <stdarg.h>
#include <stdio.h>
#include "maxon/apibase.h"


inline int sprintf_safe(char* _DstBuf, int _MaxCount, const char* _Format, ...)
{
	if (_MaxCount <= 0)
		return 0;

	va_list arp;
	va_start(arp, _Format);
	int res = vsnprintf(_DstBuf, _MaxCount, _Format, arp);
	if (res < 0 || res >= _MaxCount)
	{
		if (res < 0)
			CriticalStop();
		_DstBuf[_MaxCount - 1] = 0;
		res = _MaxCount - 1;
	}
	va_end(arp);
	return res;
}

inline int vsprintf_safe(char* _DstBuf, int _MaxCount, const char* _Format, va_list _ArgList)
{
	if (_MaxCount <= 0)
		return 0;

	int res = vsnprintf(_DstBuf, _MaxCount, _Format, _ArgList);
	if (res < 0 || res >= _MaxCount)
	{
		if (res < 0)
			CriticalStop();
		_DstBuf[_MaxCount - 1] = 0;
		res = _MaxCount - 1;
	}
	return res;
}


#endif // SPRINTF_SAFE_H__
