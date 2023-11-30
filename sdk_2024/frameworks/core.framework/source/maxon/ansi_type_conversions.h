#ifndef ANSI_TYPE_CONVERSIONS_H__
#define ANSI_TYPE_CONVERSIONS_H__

#include "maxon/datetime.h"
#include <time.h>


namespace maxon
{

static const UInt32 g_privateDays[2][12] =
{
	{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
	{31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};

MAXON_ATTRIBUTE_FORCE_INLINE tm ConvertLocalDateTimeToTM(const LocalDateTime& dateTime)
{
	tm st = {};
	st.tm_year = (int)dateTime._year - 1900;
	st.tm_mon = (int)dateTime._month - 1;
	st.tm_mday = (int)dateTime._day;
	st.tm_hour = (int)dateTime._hour;
	st.tm_min = (int)dateTime._minute;
	st.tm_sec = (int)dateTime._second;
	st.tm_isdst = (Int16)dateTime._daylightSavingTime;

	st.tm_wday = ((int)dateTime.GetDayOfWeek() + 1) % 6;	// tm_wday expects days since Sunday [0-6], not Monday

	int yearDays = (int)dateTime._day;
	int fullMonths = st.tm_mon < 11 ? st.tm_mon : 0;			// prevent possible out of bounds array access for faulty input data
	for (int i = 0; i < fullMonths; i++)
		yearDays += g_privateDays[dateTime.IsLeapYear(dateTime._year)][i];
	st.tm_yday = yearDays - 1;

	return st;
}

MAXON_ATTRIBUTE_FORCE_INLINE LocalDateTime ConvertTMToLocalDateTime(const tm& st)
{
	LocalDateTime dateTime;
	dateTime._year = (Int32)(st.tm_year + 1900);
	dateTime._month = (UChar)st.tm_mon + 1;
	dateTime._day = (UChar)st.tm_mday;
	dateTime._hour = (UChar)st.tm_hour;
	dateTime._minute = (UChar)st.tm_min;
	dateTime._second = (UChar)st.tm_sec;
	dateTime._daylightSavingTime = static_cast<DST>(st.tm_isdst);
	return dateTime;
}

#ifdef MAXON_TARGET_WINDOWS

	// stylecheck.naming=false

	#define gmtime_r(r, s) gmtime_s(s, r)
	#define localtime_r(r, s) localtime_s(s, r)
	MAXON_ATTRIBUTE_FORCE_INLINE time_t mktime_r(struct tm* tm)
	{
		return mktime(tm);
	}
	MAXON_ATTRIBUTE_FORCE_INLINE time_t timegm_r(struct tm* tm)
	{
		time_t res = 0;
		Int32 i;

		auto privateIsLeapYear = [](Int year) -> Bool
		{
			return ((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0);
		};

		// start with 70 for 1970
		for (i = 70; i < tm->tm_year; ++i)
		{
			res += privateIsLeapYear(i + 1900) ? 366 : 365;
		}

		for (i = 0; i < tm->tm_mon; ++i)
		{
			res += g_privateDays[privateIsLeapYear(tm->tm_year + 1900)][i];
		}

		res += tm->tm_mday - 1;
		res *= 24;
		res += tm->tm_hour;
		res *= 60;
		res += tm->tm_min;
		res *= 60;
		res += tm->tm_sec;
		return res;
	}
#else
	MAXON_ATTRIBUTE_FORCE_INLINE time_t mktime_r(struct tm* tm)
	{
		return mktime(tm);
	}

#if defined MAXON_TARGET_ANDROID && __ANDROID_API__ < 12
	// timegm was introduced with API 12 (Android 3.1).
	// http://stackoverflow.com/questions/16647819/timegm-cross-platform
	static time_t timegm(struct tm * a_tm)
	{
		time_t ltime = mktime(a_tm);
		struct tm tm_val;
		gmtime_r(&ltime, &tm_val);
		int offset = (tm_val.tm_hour - a_tm->tm_hour);
		if (offset > 12)
		{
				offset = 24 - offset;
		}
		time_t utc = mktime(a_tm) - offset * 3600;
		return utc;
	}
#endif

	MAXON_ATTRIBUTE_FORCE_INLINE time_t timegm_r(struct tm *tm)
	{
		return timegm(tm);
	}
#endif

// The following functions should be avoided. On Windows and OSX these functions are thread-safe, but not on Windows.
#define localtime FORBIDDEN_CALL_USE_localtime_r
#define gmtime		FORBIDDEN_CALL_USE_gmtime_r
#define timegm		FORBIDDEN_CALL_USE_timegm_r
#define mktime		FORBIDDENI_CALL_USE_mktime_r

}

#endif // ANSI_TYPE_CONVERSIONS_H__
