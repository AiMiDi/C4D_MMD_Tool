#ifndef WIN_TYPE_CONVERSIONS_H__
#define WIN_TYPE_CONVERSIONS_H__

#include "maxon/win_include.h"
#include "maxon/datetime.h"
#include "maxon/systemerror.h"



namespace maxon
{

inline UniversalDateTime ConvertSystemTimeToUniversalDateTime(const SYSTEMTIME& st)
{
	Int16 daysSinceBeginningOfYear[] = { 0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334 };

	Int32 leapYearsSince1970 = ((st.wYear - 1) - 1968) / 4 - ((st.wYear - 1) - 1900) / 100 + ((st.wYear - 1) - 1600) / 400;
	Int32 daysSince1970 = (st.wYear - 1970) * 365 + leapYearsSince1970 + daysSinceBeginningOfYear[st.wMonth - 1] + st.wDay - 1;

	if ((st.wMonth > 2) && (st.wYear % 4 == 0 && (st.wYear % 100 != 0 || st.wYear % 400 == 0)))
		daysSince1970 += 1;

	return UniversalDateTime::FromUnixTimestamp(st.wSecond + 60 * (st.wMinute + 60 * (st.wHour + 24 * daysSince1970)));
}

//----------------------------------------------------------------------------------------
/// Converts a FILETIME object to an unsigned integer which can be used when a unix timestamp is needed.
///
/// Do not cast a pointer to a FILETIME structure to either a ULARGE_INTEGER* or __int64*
/// value because it can cause alignment faults on 64-bit Windows.
/// See: https://msdn.microsoft.com/en-us/library/ms724284(VS.85).aspx
//----------------------------------------------------------------------------------------
inline UInt64 FiletimeToUnixTimestamp(const FILETIME& ft)
{
	const UInt64 windowsTick = 10000000; // the windows ticks are in 100 nanoseconds
	const UInt64 secToUnixEpoch = 11644473600LL; // the difference to the UNIX timestamp in seconds since the windows epoch starts 1601-01-01T00:00:00Z

	UInt64 windowsTicks = static_cast<UInt64>(ft.dwHighDateTime) << 32 | ft.dwLowDateTime;
	return windowsTicks / windowsTick - secToUnixEpoch;
}

//----------------------------------------------------------------------------------------
/// Converts a FILETIME object to an UniversaleDateTime object. A FILETIME object can be in UTC or local.
/// https://msdn.microsoft.com/en-us/library/windows/desktop/ms724290(v=vs.85).aspx
/// @param[in] fd									The object to convert.
//----------------------------------------------------------------------------------------
static inline Result<UniversalDateTime> ConvertFileTimeToUniversalDateTime(const FILETIME& fd, Bool filetimeIsUtc)
{
	if (!fd.dwLowDateTime && !fd.dwHighDateTime)
		return IllegalArgumentError(MAXON_SOURCE_LOCATION, "members dwLowDateTime and dwHighDateTime are not set"_s);

	if (filetimeIsUtc)
	{
		return UniversalDateTime::FromUnixTimestamp(FiletimeToUnixTimestamp(fd));
	}
	else
	{
		FILETIME sysFiletime;
		if (!LocalFileTimeToFileTime(&fd, &sysFiletime))
			return SystemError(MAXON_SOURCE_LOCATION, GetLastError());

		return UniversalDateTime::FromUnixTimestamp(FiletimeToUnixTimestamp(fd));
	}
}

inline SYSTEMTIME ConvertUniversalDateTimeToSystemTime(const UniversalDateTime& dateTime)
{
	SYSTEMTIME systemTime;
	LARGE_INTEGER jan1970FT = { };
	jan1970FT.QuadPart = 116444736000000000I64; // January 1st 1970

	LARGE_INTEGER utcFT = { };
	utcFT.QuadPart = ((unsigned __int64)dateTime.GetUnixTimestamp()) * 10000000 + jan1970FT.QuadPart;

	FileTimeToSystemTime((FILETIME*)&utcFT, &systemTime);
	return systemTime;
}

inline FILETIME ConvertUniversalDateTimeToFileTime(const UniversalDateTime& dateTime)
{
	LARGE_INTEGER jan1970FT = { };
	jan1970FT.QuadPart = 116444736000000000I64; // January 1st 1970

	LARGE_INTEGER utcFT = { };
	utcFT.QuadPart = ((unsigned __int64)dateTime.GetUnixTimestamp()) * 10000000 + jan1970FT.QuadPart;

	FILETIME* tmp = (FILETIME*)&utcFT;
	return *tmp;
}

}

#endif // WIN_TYPE_CONVERSIONS_H__
