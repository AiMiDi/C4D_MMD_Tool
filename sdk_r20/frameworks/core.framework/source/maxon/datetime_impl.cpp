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

UniversalDateTime UniversalDateTime::FromJulianDay(Float64 j)
{
	const Int JGREG = 2299161;
	LocalDateTime gmt;

	Int ja = (Int)j;// + 0.5;
	Float64 hrs = j - ja;
	// the Julian date of the adoption of the Gregorian calendar
	if (j >= JGREG)
	{
		// cross-over to Gregorian Calendar produces this correction
		Int jalpha = (Int)(((Float64)(j - 1867216) - 0.25) / 36524.25);
		ja += 1 + jalpha - (Int)(0.25 * jalpha);
	}
	Int jb = ja + 1524;
	Int jc = (Int)(6680.0 + ((Float64)(jb - 2439870) - 122.1) / 365.25);
	Int jd = (Int)(365 * jc + (0.25 * jc));
	Int je = (Int)((jb - jd) / 30.6001);
	gmt._day = UChar(jb - jd - (Int)(30.6001 * je));
	gmt._month = UChar(je - 1);
	if (gmt._month > 12)
		gmt._month -= 12;
	gmt._year = Int32(jc - 4715);
	if (gmt._month > 2)
		gmt._year--;
	if (gmt._year <= 0)
		gmt._year--;

	hrs *= 24;
	gmt._hour = (UChar)hrs; hrs -= gmt._hour; hrs *= 60;
	gmt._minute = (UChar)hrs; hrs -= gmt._minute; hrs *= 60;
	gmt._second = UChar(hrs + .5);

	// because of calculation errors... (add 0.1 seconds and try again)
	if (gmt._second >= 60)
	{
		j += .1 * 1.0 / (3600.0 * 24.0);

		ja = (Int)j;
		hrs = j - ja;
		// the Julian date of the adoption of the Gregorian calendar
		if (j >= JGREG)
		{
			// cross-over to Gregorian Calendar produces this correction
			Int jalpha = (Int)(((Float64)(j - 1867216) - 0.25) / 36524.25);
			ja += 1 + jalpha - (Int)(0.25 * jalpha);
		}
		jb = ja + 1524;
		jc = (Int)(6680.0 + ((Float64)(jb - 2439870) - 122.1) / 365.25);
		jd = (Int)(365 * jc + (0.25 * jc));
		je = (Int)((jb - jd) / 30.6001);
		gmt._day = UChar(jb - jd - (Int)(30.6001 * je));
		gmt._month = UChar(je - 1);
		if (gmt._month > 12)
			gmt._month -= 12;
		gmt._year = Int32(jc - 4715);
		if (gmt._month > 2)
			gmt._year--;
		if (gmt._year <= 0)
			gmt._year--;

		hrs *= 24;
		gmt._hour = (UChar)hrs; hrs -= gmt._hour; hrs *= 60;
		gmt._minute = (UChar)hrs; hrs -= gmt._minute; hrs *= 60;
		gmt._second = Min(UChar(59), UChar(hrs + .5));
	}

	gmt._daylightSavingTime = DST::NOTSET;

	iferr (UniversalDateTime ret = UniversalDateTime::FromValues(gmt._year, gmt._month, gmt._day, gmt._hour, gmt._minute, gmt._second))
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

	if (variant == JULIANDATE::STANDARD)
	{
		return JD;
	}
	else if (variant == JULIANDATE::LEGACY)
	{
		return JD + 0.5;
	}
	else if (variant == JULIANDATE::REDUCED)
	{
		return JD - 2400000.0;
	}
	else if (variant == JULIANDATE::MODIFIED)
	{
		return JD - 2400000.5;
	}
	else if (variant == JULIANDATE::TRUNCATED)
	{
		return Floor(JD - 2400000.5);
	}
	else if (variant == JULIANDATE::DUBLIN)
	{
		return Floor(JD - 2415020);
	}
	else if (variant == JULIANDATE::LILIAN)
	{
		return Floor(JD - 2299159.5);
	}
	else if (variant == JULIANDATE::RATEDIE)
	{
		return Floor(JD - 1721424.5);
	}
	else if (variant == JULIANDATE::UNIXTIME)
	{
		return (JD - 2440587.5) * 86400;
	}
	else if (variant == JULIANDATE::MARSSOL)
	{
		return (JD - 2405522) / 1.02749;
	}
	else // unknown
	{
		CriticalOutput("unknown type");
		return -1.0;
	}
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
