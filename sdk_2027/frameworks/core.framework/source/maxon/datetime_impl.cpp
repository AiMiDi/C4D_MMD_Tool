#include "maxon/ansi_type_conversions.h"
#include "maxon/errortypes.h"
#include "maxon/floatingpoint.h"
#include "maxon/stringconversion.h"
#include "maxon/stringencoding.h"

#if defined MAXON_TARGET_MACOS || defined MAXON_TARGET_IOS
	#include <CoreFoundation/CoreFoundation.h>
#elif defined MAXON_TARGET_WINDOWS
	#include "maxon/win_tools.h"
	#include "win_include.h"
#elif defined MAXON_TARGET_LINUX
	#include <locale.h>
	#include <langinfo.h>
	#include <string>
#endif

namespace maxon
{
UniversalDateTime UniversalDateTime::g_defaultValue;

Bool LocalDateTime::IsLeapYear() const
{
	return LocalDateTime::IsLeapYear(_year);
}

DAYOFWEEK LocalDateTime::GetDayOfWeek() const
{
	return LocalDateTime::GetDayOfWeek(_year, _month, _day);
}

#if defined MAXON_TARGET_MACOS || defined MAXON_TARGET_IOS || defined MAXON_TARGET_LINUX
static const DAYOFWEEK DAY_OF_WEEK_MAP[] = { DAYOFWEEK::SUNDAY, DAYOFWEEK::MONDAY, DAYOFWEEK::TUESDAY, DAYOFWEEK::WEDNESDAY, DAYOFWEEK::THURSDAY, DAYOFWEEK::FRIDAY, DAYOFWEEK::SATURDAY };
#endif

static Bool IsValidWeekday(Int weekday)
{
	return UInt(weekday) < 7;
}

DAYOFWEEK LocalDateTime::GetFirstWeekday()
{
	DAYOFWEEK result = DAYOFWEEK::MONDAY;

#if defined MAXON_TARGET_MACOS || defined MAXON_TARGET_IOS
	// Get the current user's locale
	CFLocaleRef locale = CFLocaleCopyCurrent();

	// Create a calendar object for the user's locale
	CFCalendarRef calendar = CFCalendarCreateWithIdentifier(kCFAllocatorDefault, kCFGregorianCalendar);

	if (calendar)
	{
		// Set the locale for the calendar
		CFCalendarSetLocale(calendar, locale);

		// Retrieve the first day of the week
		CFIndex firstDayOfWeekCFIndex = CFCalendarGetFirstWeekday(calendar);

		// CFIndex value starts at 1 and represents the day in the Gregorian calendar (1 = Sunday, 2 = Monday, etc.)
		const Int firstDayOfWeek = Int(firstDayOfWeekCFIndex - 1);
		if (IsValidWeekday(firstDayOfWeek))
			result = DAY_OF_WEEK_MAP[firstDayOfWeek];

		// Release the calendar reference
		CFRelease(calendar);
	}

	// Release the locale reference
	CFRelease(locale);

#elif defined MAXON_TARGET_WINDOWS
	// Buffer to store the first day of the week
	WCHAR buffer[2]; // LOCALE_IFIRSTDAYOFWEEK returns a single digit (0-6), so 2 is sufficient

	// Get the locale-specific first day of the week
	int res = GetLocaleInfoEx(
							LOCALE_NAME_USER_DEFAULT, // Use the current user's locale settings
							LOCALE_IFIRSTDAYOFWEEK,		// Retrieve the first day of the week
							buffer,										// Buffer to store the result
							2													// Size of the buffer
							);

	if (res > 0)
	{
		// Convert the wide character to an integer
		const Int firstDayOfWeek = Int(buffer[0] - L'0'); // LOCALE_IFIRSTDAYOFWEEK returns 0 = Monday, 1 = Tuesday, ..., 6 = Sunday
		if (IsValidWeekday(firstDayOfWeek))
			result = DAYOFWEEK(firstDayOfWeek);
	}

#elif defined MAXON_TARGET_LINUX
	// Set the locale to the user's default locale
	setlocale(LC_TIME, "");

	// Get the first day of the week from the locale
	const Int firstDayOfWeek = Int(std::stoi(nl_langinfo(_NL_TIME_FIRST_WEEKDAY))) - 1; // Returned value starts at 1 and represents the day in the Gregorian calendar (1 = Sunday, 2 = Monday, etc.)
	if (IsValidWeekday(firstDayOfWeek))
		result = DAY_OF_WEEK_MAP[firstDayOfWeek];

#endif

	return result;
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
	const CString f("%Y-%m-%d %H:%M:%S");
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

Result<UChar> LocalDateTime::GetDaysInMonth(Int year, Int month)
{
	switch (month)
	{
		case 1:
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
		case 12:
			return 31;
		case 2:
			return IsLeapYear(year) ? 29 : 28;
		case 4:
		case 6:
		case 9:
		case 11:
			return 30;
		default:
			return IllegalArgumentError(MAXON_SOURCE_LOCATION, FormatString("Month value (@) out of valid range [1..12]!", month));
	}
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
	iferr_scope;

	if (month == 0 || month > 12)
		return IllegalArgumentError(MAXON_SOURCE_LOCATION, FormatString("Month (@) out of valid range [1..12]!", month));
	
	UChar daysInMonth = GetDaysInMonth(year, month) iferr_return;
	if (day == 0 || day > daysInMonth)
		return IllegalArgumentError(MAXON_SOURCE_LOCATION, FormatString("Day (@) out of valid range for month @ in year @!", day, month, year));

	if (hour >= 24)
		return IllegalArgumentError(MAXON_SOURCE_LOCATION, FormatString("Hour (@) out of valid range [0..23]!", hour));
	
	if (minute >= 60)
		return IllegalArgumentError(MAXON_SOURCE_LOCATION, FormatString("Minute (@) out of valid range [0..59]!", minute));
	
	// TODO: (Timm) This does not allow for leap seconds, which may eventually become a problem.
	if (second >= 60)
		return IllegalArgumentError(MAXON_SOURCE_LOCATION, FormatString("Second (@) out of valid range [0..59]!", second));
	
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
		return IllegalArgumentError(MAXON_SOURCE_LOCATION, FormatString("The year @ is outside of the representable time range!", year));

	LocalDateTime utcTmp = LocalDateTime::FromValues(year, month, day, hour, minute, second, DST::NOTSET) iferr_return;

	tm tt = ConvertLocalDateTimeToTM(utcTmp);
	time_t tm = timegm_r(&tt);
	if (tm == -1)
		return UnknownError(MAXON_SOURCE_LOCATION, FormatString("Could not create value from year=@, month=@, day=@, hour=@, minute=@, second=@!", year, month, day, hour, minute, second));

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
	Float64 c = 0.0;
	if (a < 2299161)
	{
		c = (Float64) (a + 1524);
	}
	else
	{
		Float64 b = (Float64) ((Int64) floor(((Float64)a - 1867216.25) / 36524.25));
		c = (Float64)a + b - floor(b / 4.0) + 1525.0;
	}
	
	Int64 d = (Int64) floor((c - 122.1) / 365.25);
	Int64 e = (Int64) floor(365.25 * (Float64)d);
	Int64 f = (Int64) floor((c - (Float64)e) / 30.6001);
	
	Float64 dday = c - (Float64)e - floor(30.6001 * (Float64)f) + ((jd + 0.5) - (Float64)a);
	
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

// This is a helper function to parse the hour, minute, or seconds element of the time with optional decimals.
// Parsed elements are removed. When decimals or decimalCount are not supplied, decimals will not be accepted.
static Result<void> ParseTimeElement(String& str, Int32& timeElement, Int32* decimals = nullptr, Int32* decimalCount = nullptr)
{
	iferr_scope;

	// This is important, because the calling function will use this to determine whether any decimals have been found.
	if (decimalCount)
		*decimalCount = 0;
	
	// The time element MUST be given as two digits.
	String timeElementStr = str.GetLength() >= 2 ? str.GetLeftPart(2) : ""_s;
	timeElement = timeElementStr.ToInt32() iferr_return;
	str = str.GetRightPart(2);

	// If the string is empty now, that was it. This can happen and is valid e.g. at the end of the
	// time zone offset or just after any time value when there is no time zone offset.
	if (str.IsEmpty())
		return OK;
	
	// The time element may have decimals. This will be indicated by a decimal indicator, which can
	// either be a comma or a period.
	if (str[0] == (Utf32Char)',' || str[0] == (Utf32Char)'.')
	{
		if (!decimals || !decimalCount)
			return IllegalArgumentError(MAXON_SOURCE_LOCATION, "Decimal character found where they are not accepted!"_s);

		str = str.GetRightPart(1);

		// There can be any number of decimals (is that so?). The end of the decimals will be indicated
		// by either the end of the string or a non numerical character.
		for (; *decimalCount < str.GetLength(); ++(*decimalCount))
			if (!IsNumeric(str[*decimalCount]))
				break;

		String decimalsStr = str.GetLeftPart(*decimalCount);
		*decimals = decimalsStr.ToInt32() iferr_return;

		str = str.GetRightPart(*decimalCount);
	}
	// If there is a colon, this indicates the extended time format and the next value is then the minutes.
	else if (str[0] == (Utf32Char)':')
	{
		str = str.GetRightPart(1);
	}

	return OK;
}

Result<UniversalDateTime> UniversalDateTime::FromIso8601(const String& str)
{
	iferr_scope;

	String tmpStr(str);
	tmpStr.Trim() iferr_return;

	// The first four characters MUST be digits and represent the year.
	String yearStr = tmpStr.GetLength() >= 4 ? tmpStr.GetLeftPart(4) : ""_s;
	Int32 year = yearStr.ToInt32() iferr_return;
	tmpStr = tmpStr.GetRightPart(4);

	// After the year a dash MAY occur. If it does, we discard it.
	Bool usesDashes = false;
	if (tmpStr[0] == (Utf32Char)'-')
	{
		tmpStr = tmpStr.GetRightPart(1);
		usesDashes = true;
	}

	// The next two characeters MUST be digits and represent the month.
	String monthStr = tmpStr.GetLeftPart(2);
	Int32 month = monthStr.ToInt32() iferr_return;
	tmpStr = tmpStr.GetRightPart(2);
	if (month <= 0 || month > 12)
		return IllegalArgumentError(MAXON_SOURCE_LOCATION);

	// If a dash occurs after the month and there was no dash used betweeen the year and the month,
	// that is an error.
	Bool expectDay = false;
	if (tmpStr.IsPopulated() && tmpStr[0] == (Utf32Char)'-')
	{
		if (!usesDashes)
			return IllegalArgumentError(MAXON_SOURCE_LOCATION);
		
		expectDay = true;
		tmpStr = tmpStr.GetRightPart(1);
	}

	// If the next two characters are digits, they represent the month.
	// This MUST be the case if expectDay is set to true.
	String dayStr = tmpStr.GetLength() >= 2 ? tmpStr.GetLeftPart(2) : ""_s;
	Int32 day = 0;
	iferr (day = dayStr.ToInt32())
	{
		if (expectDay)
			return IllegalArgumentError(MAXON_SOURCE_LOCATION);

		return UniversalDateTime::FromValues(year, UChar(month), 1, 0, 0, 0);
	}
	UChar daysInMonth = LocalDateTime::GetDaysInMonth(year, month) iferr_return;
	if (day <= 0 || day > daysInMonth)
		return IllegalArgumentError(MAXON_SOURCE_LOCATION, FormatString("Day value (@) out of valid range for month @ and year @ [1..@]!", day, month, year, daysInMonth));
	
	tmpStr = tmpStr.GetRightPart(2);

	// If there is nothing left to parse, the string only contained a date.
	if (tmpStr.IsEmpty())
		return UniversalDateTime::FromValues(year, UChar(month), UChar(day), 0, 0, 0);

	// If there is more to parse, it should start with a 'T' now to indicate we are transitioning to the time part.
	if (tmpStr[0] != (Utf32Char)'T')
		return IllegalArgumentError(MAXON_SOURCE_LOCATION);

	// Remove the 'T'.
	tmpStr = tmpStr.GetRightPart(1);

	// Start parsing the time section.
	Int32 hour = 0;
	Int32 minute = 0;
	Int32 second = 0;

	// Hours
	Int32 hourDecimals = 0, hourDecimalCount = 0;
	ParseTimeElement(tmpStr, hour, &hourDecimals, &hourDecimalCount) iferr_return;
	
	// If there are decimals to the hour, these will be used to define minutes and seconds and we do
	// not expect any more time elements except the optional time zone offset.
	if (hourDecimalCount > 0)
	{
		Float hourFraction = (Float)hourDecimals / Pow(10, (Float)hourDecimalCount);
		Float minuteFraction = hourFraction * 60;
		minute = (Int32)minuteFraction;
		minuteFraction -= (Float)minute;
		Float secondFraction = minuteFraction * 60;
		second = (Int32)secondFraction;
	}
	else
	{
		// Minutes are optional
		if (!tmpStr.IsEmpty() && tmpStr[0] != (Utf32Char)'Z' && tmpStr[0] != (Utf32Char)'+' && tmpStr[0] != (Utf32Char)'-')
		{
			// Minutes
			Int32 minuteDecimals = 0, minuteDecimalCount = 0;
			ParseTimeElement(tmpStr, minute, &minuteDecimals, &minuteDecimalCount) iferr_return;
			
			// If there are decimals to the minute, these will be used to define seconds and we do not expect
			// any more time elements except the optional time zone offset.
			if (minuteDecimalCount > 0)
			{
				Float minuteFraction = (Float)minuteDecimals / Pow(10, (Float)minuteDecimalCount);
				Float secondFraction = minuteFraction * 60;
				second = (Int32)secondFraction;
			}
			else
			{
				// Seconds are optional
				if (!tmpStr.IsEmpty() && tmpStr[0] != (Utf32Char)'Z' && tmpStr[0] != (Utf32Char)'+' && tmpStr[0] != (Utf32Char)'-')
				{
					// Seconds
					Int32 secondDecimals = 0, secondDecimalCount = 0;
					ParseTimeElement(tmpStr, second, &secondDecimals, &secondDecimalCount) iferr_return;
					
					// If there are decimals to the second, these will just be discarded because UniversalDateTime
					// cannot represent smaller units of time.
				}
			}
		}
	}

	// If there is nothing else in the string, the time should be considered local time. This does
	// introduce some blurriness about which time zone is used and is therefore discouraged, but the
	// ISO standard still allows for it. We use the LocalDateTime class here so it can then take care
	// of time zone translation automatically when converting into UniversalDateTime.
	if (tmpStr.IsEmpty())
	{
		LocalDateTime localTime = LocalDateTime::FromValues(year, UChar(month), UChar(day), UChar(hour), UChar(minute), UChar(second)) iferr_return;
		return localTime.ConvertToUniversalDateTime();
	}
	
	// If the timezone offset is 'Z' for zulu (UTC), we can just set the time and be done.
	UniversalDateTime tmpResult = UniversalDateTime::FromValues(year, UChar(month), UChar(day), UChar(hour), UChar(minute), UChar(second)) iferr_return;
	if (tmpStr.GetLength() == 1 && tmpStr == "Z"_s)
		return tmpResult;

	// If there is a time zone offset to parse, it should either start with a plus ('+') or minus
	// ('-') sign.
	// TODO: (Timm) The standard also allows the minus sign ('\u2212') and in case of a zero offset a plus/minus sign ('U+00B1') to be used.
	Int32 timezoneSign = 0;
	// Set the timezone sign to -1 for a positive and +1 for a negative time zone offset. It is
	// inverted because when we are in a +01:00 time zone, we actually need to subtract the time
	// offset (and vice versa) to get a UTC time.
	switch (tmpStr[0])
	{
		case (Utf32Char)'+':
			timezoneSign = -1;
			break;
		case (Utf32Char)'-':
			timezoneSign = 1;
			break;
		default:
			return IllegalArgumentError(MAXON_SOURCE_LOCATION, "Invalid time zone information!"_s);
	}

	// Remove the leading sign.
	tmpStr = tmpStr.GetRightPart(1);

	// Read timezone hours.
	Int32 timezoneHours = 0;
	ParseTimeElement(tmpStr, timezoneHours) iferr_return;
	
	if (timezoneHours < 0 || timezoneHours >= 24)
		return IllegalArgumentError(MAXON_SOURCE_LOCATION, FormatString("@ hours is not in the range of valid time zone offsets [0..23]!", timezoneHours));

	// Read timezone minutes if there is still something left.
	Int32 timezoneMinutes = 0;
	if (tmpStr.IsPopulated())
	{
		ParseTimeElement(tmpStr, timezoneMinutes) iferr_return;

		if (timezoneMinutes < 0 || timezoneMinutes >= 59)
			return IllegalArgumentError(MAXON_SOURCE_LOCATION, FormatString("@ minutes is not in the range of valid time zone offsets [0..59]!", timezoneMinutes));
	}

	// Correct the parsed time with the time zone offset.
	Int32 timezoneOffsetSeconds = (timezoneHours * 3600 + timezoneMinutes * 60) * timezoneSign;
	UInt64 timestamp = tmpResult.GetUnixTimestamp();
	timestamp += timezoneOffsetSeconds;
	return UniversalDateTime::FromUnixTimestamp(timestamp);
}

Result<void> UniversalDateTime::DescribeIO(const DataSerializeInterface& stream)
{
	iferr_scope;

	PrepareDescribe(stream, UniversalDateTime);

	Describe("timestamp", _timestamp, UInt64, DESCRIBEFLAGS::NONE) iferr_return;

	return OK;
}

void ScanParameter(UniversalDateTime& res, const Block<const Utf32Char>& str, Int& processed, const String& formatStatement, Bool& error)
{
	iferr_scope_handler
	{
		error = true;
		return;
	};
	error = false;

	processed = 0;

	Int year = 0, month = 0, day = 0;
	Int proccessedDigits;
	year = StringConversion::StringToInteger(str, 10, false, false, proccessedDigits) iferr_return;

	processed += proccessedDigits;

	str.CheckValidIndex(processed) iferr_return;
	if (str[processed] != '-')
	{
		error = true;
		return;
	}
	processed += 1;

	month = StringConversion::StringToInteger(str.Slice(processed), 10, false, false, proccessedDigits) iferr_return;

	processed += proccessedDigits;

	str.CheckValidIndex(processed) iferr_return;
	if (str[processed] != '-')
	{
		error = true;
		return;
	}
	processed += 1;

	day = StringConversion::StringToInteger(str.Slice(processed), 10, false, false, proccessedDigits) iferr_return;

	processed += proccessedDigits;

	iferr (res = UniversalDateTime::FromValues((Int32)year, (UChar)month, (UChar)day, 0, 0, 0))
	{
		error = true;
		return;
	}
}

} // namespace maxon
