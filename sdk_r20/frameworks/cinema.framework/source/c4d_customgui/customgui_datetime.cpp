#include "customgui_datetime.h"
#include "c4d_string.h"
#include "c4d_gui.h"


static DateTimechooserLib *lib_DateTime = nullptr;

static DateTimechooserLib *CheckDateTimechooserLib(Int32 offset)
{
	return (DateTimechooserLib*)CheckLib(DATETIME_GUI, offset, (C4DLibrary**)&lib_DateTime);
}

#define DateTimeCall(b) 			DateTimechooserLib *lib = CheckDateTimechooserLib(LIBOFFSET(DateTimechooserLib, b)); \
															if (!lib || !lib->b) return; \
															(((iDateTimeData*)this)->*lib->b)

#define DateTimeCallR(a, b) 		DateTimechooserLib *lib = CheckDateTimechooserLib(LIBOFFSET(DateTimechooserLib, b)); \
															if (!lib || !lib->b) return a; \
															return (((iDateTimeData*)this)->*lib->b)

#define DateTimeGuiCall(b) 		DateTimechooserLib *lib = CheckDateTimechooserLib(LIBOFFSET(DateTimechooserLib, b)); \
															if (!lib || !lib->b) return; \
															(((iDateTimeControl*)this)->*lib->b)

#define DateTimeGuiCallR(a, b) DateTimechooserLib *lib = CheckDateTimechooserLib(LIBOFFSET(DateTimechooserLib, b)); \
															if (!lib || !lib->b) return a; \
															return (((iDateTimeControl*)this)->*lib->b)

DateTime DateTimeControl::GetDateTime() const { DateTimeGuiCallR(DateTime(), GetDateTimeGUI)(); }
void DateTimeControl::SetDateTime(const DateTime &d, Bool bSetDate, Bool bSetTime) { DateTimeGuiCall(SetDateTimeGUI)(d, bSetDate, bSetTime); }

DateTime DateTimeData::GetDateTime() const { DateTimeCallR(DateTime(), GetDateTimeData)(); }
void DateTimeData::SetDateTime(const DateTime &d, Bool bSetDate, Bool bSetTime) { DateTimeCall(SetDateTimeData)(d, bSetDate, bSetTime); }

Float64 GetJulianDay(const DateTime &t)
{
	DateTimechooserLib *lib = CheckDateTimechooserLib(LIBOFFSET(DateTimechooserLib, GetJulianDay)); if (!lib || !lib->GetJulianDay) return -1;
	return lib->GetJulianDay(t);
}

DateTime FromJulianDay(Float64 j)
{
	DateTimechooserLib *lib = CheckDateTimechooserLib(LIBOFFSET(DateTimechooserLib, GetJulianDay)); if (!lib || !lib->FromJulianDay) return DateTime();
	return lib->FromJulianDay(j);
}

void GetDateTimeNow(DateTime& t)
{
	DateTimechooserLib *lib = CheckDateTimechooserLib(LIBOFFSET(DateTimechooserLib, GetDateTimeNow)); if (!lib || !lib->GetDateTimeNow) return;
	lib->GetDateTimeNow(t);
}

void GetDateTimeNowGM(DateTime& t)
{
	DateTime tt;
	GetDateTimeNow(tt);
	LocalToGMTime(tt, t);
}

Bool LocalToGMTime(const DateTime &tLocal, DateTime &tGMT)
{
	DateTimechooserLib *lib = CheckDateTimechooserLib(LIBOFFSET(DateTimechooserLib, LocalToGMTime)); if (!lib || !lib->LocalToGMTime) { tGMT = tLocal; return false; }
	return lib->LocalToGMTime(tLocal, tGMT);
}

Bool GMTimeToLocal(const DateTime &tGMT, DateTime &tLocal)
{
	DateTimechooserLib *lib = CheckDateTimechooserLib(LIBOFFSET(DateTimechooserLib, GMTimeToLocal)); if (!lib || !lib->GMTimeToLocal) { tLocal = tGMT; return false; }
	return lib->GMTimeToLocal(tGMT, tLocal);
}

DAYOFWEEK GetDayOfWeek(Int32 lYear, Int32 lMonth, Int32 lDay)
{
	DateTimechooserLib *lib = CheckDateTimechooserLib(LIBOFFSET(DateTimechooserLib, GetDayOfWeek)); if (!lib || !lib->GetDayOfWeek) return DAYOFWEEK::MONDAY;
	return lib->GetDayOfWeek(lYear, lMonth, lDay);
}

String FormatTime(const char* pszFormat, const DateTime &t)
{
	DateTimechooserLib *lib = CheckDateTimechooserLib(LIBOFFSET(DateTimechooserLib, FormatTime)); if (!lib || !lib->FormatTime) return String();
	return lib->FormatTime(pszFormat, t);
}

DateTimeData* DateTimeData::Alloc()
{
	DateTimechooserLib *lib = CheckDateTimechooserLib(LIBOFFSET(DateTimechooserLib, DateTimeData_Alloc)); if (!lib || !lib->DateTimeData_Alloc) return nullptr;
	return lib->DateTimeData_Alloc();
}

void DateTimeData::Free(DateTimeData *&pData)
{
	DateTimechooserLib *lib = CheckDateTimechooserLib(LIBOFFSET(DateTimechooserLib, DateTimeData_Free)); if (!lib || !lib->DateTimeData_Free) return;
	lib->DateTimeData_Free(pData);
}

Bool ParseTimeString(String timestr, Int32 &hour, Int32 &minute, Int32 &second)
{
	DateTimechooserLib *lib = CheckDateTimechooserLib(LIBOFFSET(DateTimechooserLib, ParseTimeString)); if (!lib || !lib->ParseTimeString) return false;
	return lib->ParseTimeString(timestr, hour, minute, second);
}

Bool ParseDateString(String datestr, Int32 &year, Int32 &month, Int32 &day)
{
	DateTimechooserLib *lib = CheckDateTimechooserLib(LIBOFFSET(DateTimechooserLib, ParseDateString)); if (!lib || !lib->ParseDateString) return false;
	return lib->ParseDateString(datestr, year, month, day);
}

String TimeToString(const DateTime &d, const Bool bShowSeconds)
{
	DateTimechooserLib *lib = CheckDateTimechooserLib(LIBOFFSET(DateTimechooserLib, TimeToString)); if (!lib || !lib->TimeToString) return String();
	return lib->TimeToString(d, bShowSeconds);
}

String DateToString(const DateTime &d)
{
	DateTimechooserLib *lib = CheckDateTimechooserLib(LIBOFFSET(DateTimechooserLib, DateToString)); if (!lib || !lib->DateToString) return String();
	return lib->DateToString(d);
}

String GetMonthName(Int month)
{
	DateTimechooserLib *lib = CheckDateTimechooserLib(LIBOFFSET(DateTimechooserLib, GetMonthName)); if (!lib || !lib->GetMonthName) return String();
	return lib->GetMonthName(month);
}

void ValidateDate(Int32 &year, Int32 &month, Int32 &day)
{
	DateTimechooserLib *lib = CheckDateTimechooserLib(LIBOFFSET(DateTimechooserLib, ValidateDate)); if (!lib || !lib->ValidateDate) return;
	lib->ValidateDate(year, month, day);
}

void ValidateTime(Int32 &hour, Int32 &minute, Int32 &second)
{
	DateTimechooserLib *lib = CheckDateTimechooserLib(LIBOFFSET(DateTimechooserLib, ValidateTime)); if (!lib || !lib->ValidateTime) return;
	lib->ValidateTime(hour, minute, second);
}

Int32 CompareDateTime(const DateTime &a, const DateTime &b)
{
	Int32 c;
	c = a.year - b.year;
	if (c != 0) return c;
	c = a.month - b.month;
	if (c != 0) return c;
	c = a.day - b.day;
	if (c != 0) return c;
	c = a.hour - b.hour;
	if (c != 0) return c;
	c = a.minute - b.minute;
	if (c != 0) return c;
	c = a.second - b.second;
	return c;
}

Bool DateTime::operator == (const DateTime& b) const
{
	return CompareDateTime(*this, b) == 0;
}

Bool DateTime::operator != (const DateTime& b) const
{
	return CompareDateTime(*this, b) != 0;
}

Bool DateTime::operator <= (const DateTime &b) const
{
	return CompareDateTime(*this, b) <= 0;
}

Bool DateTime::operator < (const DateTime &b) const
{
	return CompareDateTime(*this, b) < 0;
}

Bool DateTime::operator >= (const DateTime &b) const
{
	return CompareDateTime(*this, b) >= 0;
}

Bool DateTime::operator > (const DateTime &b) const
{
	return CompareDateTime(*this, b) > 0;
}
