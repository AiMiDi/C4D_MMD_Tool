#include "maxon/floatingpoint.h"
#include "maxon/ansi_type_conversions.h"
#include "maxon/stringencoding.h"

#ifdef MAXON_TARGET_WINDOWS
	#include "maxon/win_tools.h"
	#include "win_include.h"
#endif

namespace maxon
{
UniversalDateTime UniversalDateTime::g_nullValue;

Bool LocalDateTime::IsLeapYear() const
{
	return LocalDateTime::IsLeapYear(_year);
}

DAYOFWEEK LocalDateTime::GetDayOfWeek() const
{
	return LocalDateTime::GetDayOfWeek(_year, _month, _day);
}

UniversalDateTime LocalDateTime::ConvertToUniversalDateTime() const
{
	tm tt = ConvertLocalDateTimeToTM(*this);
	time_t time = mktime_r(&tt);
	if (time == -1)
		return UniversalDateTime();

	return UniversalDateTime::FromUnixTimestamp(time);
}

String LocalDateTime::FormatTime(const Char* formatString) const
{
	CString f("%Y-%m-%d %H:%M:%S");
	Char buffer[80];
	tm timeinfo = ConvertLocalDateTimeToTM(*this);
	strftime(buffer, sizeof(buffer), formatString ? formatString : (const Char*)f, &timeinfo);
	return String(buffer, StringDecodings::Bit8());
}

String LocalDateTime::ToString(const FormatStatement* formatStatement) const
{
	CString f("%Y-%m-%d %H:%M:%S");
	if (formatStatement)
	{
		CString ff = formatStatement->Get("Format");
		if (ff.IsPopulated())
			f = ff;
	}

	return FormatTime(f);
}

TimeValue LocalDateTime::GetTimezoneOffset(Bool* daylightSavingTime)
{
	time_t currentTime;
	time(&currentTime);

	tm ptm;
	gmtime_r(&currentTime, &ptm);
	Int h1 = (ptm.tm_hour + 24 * ptm.tm_yday) * 60 + ptm.tm_min;
	localtime_r(&currentTime, &ptm);

	DebugAssert(ptm.tm_isdst != -1, "value must be set");
	if (daylightSavingTime)
		*daylightSavingTime = ptm.tm_isdst == 1 ? true : false;

	Int h2 = (ptm.tm_hour + 24 * ptm.tm_yday) * 60 + ptm.tm_min;

	Int32 diff = static_cast<Int32>(h2 - h1);

	if (diff < -1200)
		diff = -1200;
	else if (diff > 1300)
		diff = 1300;

	return Minutes(diff);
}

Bool LocalDateTime::IsLeapYear(Int year)
{
	if (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0))
		return true;
	return false;
}

DAYOFWEEK LocalDateTime::GetDayOfWeek(Int year, Int month, Int day)
{
	month -= 1;
	if (month < 0 || month >= 12)
		return DAYOFWEEK::MONDAY;

	Int lMonthCode[] = { 6, 2, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4 };

	Int y = year % 100;
	y = y % 28;

	y += y / 4;
	y += lMonthCode[month];
	y += day;

	// Schaltjahr?
	if (IsLeapYear(year) && (month == 0 || month == 1))
		y--;

	if (year < 1700)
		return DAYOFWEEK::MONDAY;
	else if (year >= 1700 && year < 1799)
		y += 5;
	else if (year >= 1800 && year < 1899)
		y += 3;
	else if (year >= 1900 && year < 1999)
		y += 1;
	else if (year >= 2000 && year < 2099)
		y += 0;
	else if (year >= 2100 && year < 2199)
		y -= 2;
	else if (year >= 2200 && year < 2299)
		y -= 4;
	else
		return DAYOFWEEK::MONDAY;

	while (y < 0)
		y += 7;
	y = (y + 6) % 7;

	return (DAYOFWEEK)y;
}

LocalDateTime LocalDateTime::GetNow()
{
	return UniversalDateTime::GetNow().ConvertToLocalDateTime();
}

Result<LocalDateTime> LocalDateTime::FromString(const String& dateTimeStr, const Char* formatString)
{
	iferr_scope;

	tm result;

	BaseArray<Char> dateTimeChar = dateTimeStr.GetCString() iferr_return;

	char* firstUnparsed = strptime(dateTimeChar.GetFirst(), formatString, &result);
	if (!firstUnparsed)
		return IllegalArgumentError(MAXON_SOURCE_LOCATION, "Could not parse date time string."_s);

	return ConvertTMToLocalDateTime(result);
}

Result<LocalDateTime> LocalDateTime::FromValues(Int32 year, UChar month, UChar day, UChar hour, UChar minute, UChar second, DST daylightSavingTime)
{
	LocalDateTime ldt;
	ldt._year = year;
	ldt._month = month;
	ldt._day = day;
	ldt._hour = hour;
	ldt._minute = minute;
	ldt._second = second;
	ldt._daylightSavingTime = daylightSavingTime;
	return ldt;
}

LocalDateTime LocalDateTime::FromUnixTimestamp(UInt64 timestamp)
{
	time_t time = (time_t)timestamp;
	tm tt;
	localtime_r(&time, &tt);
	return ConvertTMToLocalDateTime(tt);
}

Float64 UniversalDateTime::GetJulianDay(JULIANDATE variant) const
{
	LocalDateTime tmpGmt = ConvertToLocalDateTime(maxon::timezone::GMT, DST::NOTSET);
	return UniversalDateTime::ToJulianDay(variant, tmpGmt._year, tmpGmt._month, tmpGmt._day, tmpGmt._hour, tmpGmt._minute, tmpGmt._second);
}

LocalDateTime UniversalDateTime::ConvertToLocalDateTime() const
{
	time_t time = (time_t)_timestamp;
	tm tt;
	localtime_r(&time, &tt);
	DebugAssert(tt.tm_isdst != -1, "value must be set");
	return ConvertTMToLocalDateTime(tt);
}

RemoteDateTime UniversalDateTime::ConvertToLocalDateTime(const TimeValue& utcOffset, DST dst) const
{
	time_t time = (time_t)_timestamp;
	time += (UInt64)utcOffset.GetSeconds();

	tm tt;
	gmtime_r(&time, &tt);
	tt.tm_isdst = static_cast<int>(dst);

	return ConvertTMToLocalDateTime(tt);
}

String UniversalDateTime::FormatTime(const Char* formatString) const
{
	CString f("%Y-%m-%d %H:%M:%S");
	time_t timestamp = static_cast<time_t>(_timestamp);

	Char buffer[80];
	tm timeinfo;
	gmtime_r(&timestamp, &timeinfo);
	strftime(buffer, sizeof(buffer), formatString ? formatString : (const Char*)f, &timeinfo);
	return String(buffer, StringDecodings::Bit8());
}

String UniversalDateTime::ToString(const FormatStatement* formatStatement) const
{
	CString f("%Y-%m-%d %H:%M:%S");
	if (formatStatement)
	{
		CString ff = formatStatement->Get("Format");
		if (ff.IsPopulated())
			f = ff;
	}

	return FormatTime(f);
}

UniversalDateTime UniversalDateTime::GetNow()
{
	return UniversalDateTime::FromUnixTimestamp(time(nullptr));
}

Result<UniversalDateTime> UniversalDateTime::FromValues(Int32 year, UChar month, UChar day, UChar hour, UChar minute, UChar second)
{
	iferr_scope;

	if (year < 1970)
		return IllegalArgumentError(MAXON_SOURCE_LOCATION, FormatString("@ is an invalid year", year));

	LocalDateTime utcTmp = LocalDateTime::FromValues(year, month, day, hour, minute, second, DST::NOTSET) iferr_return;

	tm tt = ConvertLocalDateTimeToTM(utcTmp);
	time_t tm = timegm_r(&tt);
	if (tm == -1)
		return UnknownError(MAXON_SOURCE_LOCATION, FormatString("could not create value from year=@, month=@, day=@, hour=@, minute=@, second=@", year, month, day, hour, minute, second));

	return UniversalDateTime::FromUnixTimestamp(tm);
}
	
static Float64 ConvertJulianDate(JULIANDATE variant, Float64 j)
{
	if (variant == JULIANDATE::STANDARD)
	{
		// fallthrough
	}
	else if (variant == JULIANDATE::LEGACY)
	{
		j = j + 0.5;
	}
	else if (variant == JULIANDATE::REDUCED)
	{
		j -= 2400000.0;
	}
	else if (variant == JULIANDATE::MODIFIED)
	{
		j -= 2400000.5;
	}
	else if (variant == JULIANDATE::TRUNCATED)
	{
		j -= 2400000.5;
	}
	else if (variant == JULIANDATE::DUBLIN)
	{
		j -= 2415020;
	}
	else if (variant == JULIANDATE::LILIAN)
	{
		j -= 2299159.5;
	}
	else if (variant == JULIANDATE::RATEDIE)
	{
		j = Floor(j - 1721424.5);
	}
	else if (variant == JULIANDATE::UNIXTIME)
	{
		j = (j - 2440587.5) * 86400;
	}
	else if (variant == JULIANDATE::MARSSOL)
	{
		j = (j - 2405522) / 1.02749;
	}
	else // unknown
	{
		CriticalOutput("unknown variant type");
		j = -1.0;
	}
	
	return j;
}

UniversalDateTime UniversalDateTime::FromJulianDay(JULIANDATE variant, Float64 jd)
{
	jd -= ConvertJulianDate(variant, 0.0);
	
	Int64 a = (Int64) floor(jd);
	Float64 c;
	if (a < 2299161)
	{
		c = (Float64) (a + 1524);
	}
	else
	{
		Float64 b = (Float64) ((Int64) floor((a - 1867216.25) / 36524.25));
		c = a + b - (Int64) floor(b / 4) + 1525;
	}
	
	Int64 d = (Int64) floor((c - 122.1) / 365.25);
	Int64 e = (Int64) floor(365.25 * d);
	Int64 f = (Int64) floor((c - e) / 30.6001);
	
	Float64 dday = c - e - (Int64) floor(30.6001 * f) + ((jd + 0.5) - a);
	
	UChar month = (UChar) (f - 1 - 12 * (Int64) (f / 14));
	Int32 year = (Int32) (d - 4715 - (Int64) ((7.0 + month) / 10.0));
	UChar day = (UChar) dday;
	
	Float64 dhour = (dday - day) * 24;
	UChar hour = (UChar) dhour;
	
	Float64 dminute = (dhour - hour) * 60;
	UChar minute = (UChar) dminute;
	
	Float64 dsecond = (dminute - minute) * 60;
	UChar second = (UChar) round(dsecond);

	iferr (UniversalDateTime ret = UniversalDateTime::FromValues(year, month, day, hour, minute, second))
		return UniversalDateTime();

	return ret;
}

Float64 UniversalDateTime::ToJulianDay(JULIANDATE variant, Int32 year, UChar month, UChar day, UChar hour, UChar minute, UChar second)
{
	// Check for month = Januar or Februar;
	if (month < 3)
	{
		year--;
		month += 12;
	}

	int a = year / 100;
	int b = 0;

	if (year > 1582 || (year == 1582 && (month > 10 || (month == 10 && day >= 4))))
	{
		// Gregorian calendar
		b = 2 - a + (a / 4);
	}
	else
	{
		// Julian calendar
		b = 0;
	}

	// add a fraction of hours, minutes and secs to days
	Float64 days = day + (Float64)(hour / 24.0) + (Float64)(minute / 1440.0) + (Float64)(second / 86400.0);

	// now get the JD
	Float64 JD = (Int32)(365.25 * (year + 4716)) + (Int32)(30.6001 * (month + 1)) + days + b - 1524.5;

	return ConvertJulianDate(variant, JD);
}

UniversalDateTime UniversalDateTime::FromUnixTimestamp(UInt64 timestamp)
{
	UniversalDateTime udt;
	udt._timestamp = timestamp;
	return udt;
}

Result<void> UniversalDateTime::DescribeIO(const DataSerializeInterface& stream)
{
	iferr_scope;

	PrepareDescribe(stream, UniversalDateTime);

	Describe("timestamp", _timestamp, UInt64, DESCRIBEFLAGS::NONE) iferr_return;

	return OK;
}

} // namespace maxon
