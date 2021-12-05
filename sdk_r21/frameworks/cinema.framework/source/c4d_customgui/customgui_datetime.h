/////////////////////////////////////////////////////////////
// Cinema 4D SDK                                           //
/////////////////////////////////////////////////////////////
// (c) MAXON Computer GmbH, all rights reserved            //
/////////////////////////////////////////////////////////////

#ifndef CUSTOMGUI_DATETIME_H__
#define CUSTOMGUI_DATETIME_H__

/// DateTime custom GUI ID.
#define DATETIME_GUI			1009383

/// DateTime custom data ID.
#define DATETIME_DATA			1009398

/// @addtogroup DATETIME_CUSTOMGUISETTINGS
/// @ingroup CUSTOMGUISETTINGS
/// @{
#define DATETIME_TIME_CONTROL			'dttc'			///< ::Bool @formatConstant{true}, if it is a clock.
#define DATETIME_DATE_CONTROL			'dtdc'			///< ::Bool @formatConstant{true}, if it is a calendar.
#define DATETIME_NOW_BUTTON				'dtnw'			///< ::Bool @formatConstant{true}, to add @em "Now" button.
#define DATETIME_NO_SECONDS				'dtns'			///< ::Bool @formatConstant{true}, to not show seconds.
#define DATETIME_SHOW_LABELS			'shlb'			///< ::Bool @formatConstant{true}, to show the @em "Date" and @em "Time" labels if the GUI is collapsed.

#include "customgui_base.h"
#include "c4d_basecontainer.h"
#include "c4d_gui.h"
#include "c4d_customdatatype.h"


//-------------------------------------------------------------------------------------------------
/// Represents a date and time.
//-------------------------------------------------------------------------------------------------
struct DateTime
{
	/// @name Constructors
	/// @{

	//-------------------------------------------------------------------------------------------------
	/// Default constructor. (Sets the time to @em 2000-01-01 @em 00:00:00.)
	//-------------------------------------------------------------------------------------------------
	DateTime() { year = 2000; month = day = 1; hour = minute = second = 0; }

	//----------------------------------------------------------------------------------------
	/// Creates a date and time with the given year/month/day and hour/minute/seconds.
	/// @param[in] t_year							Year.
	/// @param[in] t_month						Month.
	/// @param[in] t_day							Day in month.
	/// @param[in] t_hour							Hour.
	/// @param[in] t_minute						Minute.
	/// @param[in] t_second						Second.
	//----------------------------------------------------------------------------------------
	DateTime(Int32 t_year, Int32 t_month, Int32 t_day, Int32 t_hour, Int32 t_minute, Int32 t_second) : year(t_year), month(t_month), day(t_day), hour(t_hour), minute(t_minute), second(t_second)
	{ }

	/// @}

	Int32 year,				///< Year.
				month,			///< Month.
				day;				///< Day in month.

	Int32 hour,				///< Hour.
				minute,			///< Minute.
				second;			///< Second.

	/// @name Operators
	/// @{

	//----------------------------------------------------------------------------------------
	/// Equality operator. Checks if the date time is equal to another.
	/// @param[in] b									The right-operand date time.
	/// @return												The result of the comparison.
	//----------------------------------------------------------------------------------------
	Bool operator == (const DateTime &b) const;

	//----------------------------------------------------------------------------------------
	/// Inequality operator. Checks if the date time is not equal to another.
	/// @param[in] b									The right-operand date time.
	/// @return												The result of the comparison.
	//----------------------------------------------------------------------------------------
	Bool operator != (const DateTime &b) const;

	//----------------------------------------------------------------------------------------
	/// Less than or equal operator. Checks if the date time is less than or equal to another.
	/// @param[in] b									The right-operand date time.
	/// @return												The result of the comparison.
	//----------------------------------------------------------------------------------------
	Bool operator <= (const DateTime &b) const;

	//----------------------------------------------------------------------------------------
	/// Less than operator. Checks if the date time is less than another.
	/// @param[in] b									The right-operand date time.
	/// @return												The result of the comparison.
	//----------------------------------------------------------------------------------------
	Bool operator < (const DateTime &b) const;

	//----------------------------------------------------------------------------------------
	/// Greater than or equal operator. Checks if the date time is greater than or equal to another.
	/// @param[in] b									The right-operand date time.
	/// @return												The result of the comparison.
	//----------------------------------------------------------------------------------------
	Bool operator >= (const DateTime &b) const;

	//----------------------------------------------------------------------------------------
	/// Greater than operator. Checks if the date time is greater than another.
	/// @param[in] b									The right-operand date time.
	/// @return												The result of the comparison.
	//----------------------------------------------------------------------------------------
	Bool operator > (const DateTime &b) const;

	/// @}
};

//----------------------------------------------------------------------------------------
/// Compare date times @formatParam{a} and @formatParam{b}.
/// @param[in] a									The first date time.
/// @param[in] b									The second date time.
/// @return												Less than @em 0 if @formatParam{a} < @formatParam{b}, equal to @em 0 if @formatParam{a} == @formatParam{b} and greater than @em 0 if @formatParam{a} > @formatParam{b}.
//----------------------------------------------------------------------------------------
Int32 CompareDateTime(const DateTime &a, const DateTime &b);

//----------------------------------------------------------------------------------------
/// DateTime custom GUI (@ref DATETIME_GUI) for DateTimeData.\n
/// Here are the settings: @enumerateEnum{DATETIME_CUSTOMGUISETTINGS}
//----------------------------------------------------------------------------------------
class DateTimeControl : public BaseCustomGui<DATETIME_GUI>
{
private:
	DateTimeControl();
	~DateTimeControl();

public:
	//----------------------------------------------------------------------------------------
	/// Retrieves the date time.
	/// @return												The date time.
	//----------------------------------------------------------------------------------------
	DateTime GetDateTime() const;

	//----------------------------------------------------------------------------------------
	/// Sets the date time.
	/// @param[in] d									The date time to set.
	/// @param[in] bSetDate						If @formatConstant{false} the date part of @formatParam{d} is discarded. Default to @formatConstant{true}.
	/// @param[in] bSetTime						If @formatConstant{false} the time part of @formatParam{d} is discarded. Default to @formatConstant{true}.
	//----------------------------------------------------------------------------------------
	void SetDateTime(const DateTime &d, Bool bSetDate = true, Bool bSetTime = true);
};

//----------------------------------------------------------------------------------------
/// DateTime custom data (@ref DATETIME_DATA).
/// @addAllocFreeAutoAllocNote
//----------------------------------------------------------------------------------------
class DateTimeData : public CustomDataType
{
private:
	DateTimeData();
	~DateTimeData();

public:
	//----------------------------------------------------------------------------------------
	/// @allocatesA{DateTime data}
	/// @return												@allocReturn{DateTime data}
	//----------------------------------------------------------------------------------------
	static DateTimeData* Alloc();

	//----------------------------------------------------------------------------------------
	/// @destructsAlloc{DateTime data}
	/// @param[in,out] pData					@theToDestruct{DateTime data}
	//----------------------------------------------------------------------------------------
	static void Free(DateTimeData *&pData);

	//----------------------------------------------------------------------------------------
	/// Retrieves the date time.
	/// @return												The date time.
	//----------------------------------------------------------------------------------------
	DateTime GetDateTime() const;

	//----------------------------------------------------------------------------------------
	/// Sets the date time.
	/// @param[in] d									The date time to set.
	/// @param[in] bSetDate						If @formatConstant{false} the date part of @formatParam{d} is discarded. Default to @formatConstant{true}.
	/// @param[in] bSetTime						If @formatConstant{false} the time part of @formatParam{d} is discarded. Default to @formatConstant{true}.
	//----------------------------------------------------------------------------------------
	void SetDateTime(const DateTime &d, Bool bSetDate = true, Bool bSetTime = true);
};

/// @addtogroup DayOfWeek
/// @ingroup group_enumeration
/// @{
/// Week days.
enum class DAYOFWEEK
{
	MONDAY		= 0,
	TUESDAY		= 1,
	WEDNESDAY	= 2,
	THURSDAY	= 3,
	FRIDAY		= 4,
	SATURDAY	= 5,
	SUNDAY		= 6
} MAXON_ENUM_LIST(DAYOFWEEK);
/// @}

/// @addtogroup MonthOfYear
/// @ingroup group_enumeration
/// @{
/// Year months.
enum class MONTHOFYEAR
{
	JANUARY		= 1,
	FEBRUARY	= 2,
	MARCH			= 3,
	APRIL			= 4,
	MAY				= 5,
	JUNE			= 6,
	JULY			= 7,
	AUGUST		= 8,
	SEPTEMBER	= 9,
	OCTOBER		= 10,
	NOVEMBER	= 11,
	DECEMBER	= 12
} MAXON_ENUM_LIST(MONTHOFYEAR);
/// @}

//----------------------------------------------------------------------------------------
/// Gets the Modified Julian Date (http://tycho.usno.navy.mil/mjd.html) from @formatParam{t}.
/// @param[in] t									A date time.
/// @return												The Modified Julian Date. To get the correct Julian day, take the integer of the value and subtract @em 0.5
//----------------------------------------------------------------------------------------
Float64 GetJulianDay(const DateTime &t);

//----------------------------------------------------------------------------------------
/// Gets a date time from the Modified Julian Date (http://tycho.usno.navy.mil/mjd.html) @formatParam{j}.
/// @param[in] j									A Modified Julian Date.
/// @return												The date time.
//----------------------------------------------------------------------------------------
DateTime FromJulianDay(Float64 j);

//----------------------------------------------------------------------------------------
/// Retrieves the current system date time.
/// @param[out] t									Filled with the current system time.
//----------------------------------------------------------------------------------------
void GetDateTimeNow(DateTime& t);

//----------------------------------------------------------------------------------------
/// Retrieves the current system date time in @em GMT.
/// @param[out] t									Filled with the current system @em GMT time.
//----------------------------------------------------------------------------------------
void GetDateTimeNowGM(DateTime& t);

//----------------------------------------------------------------------------------------
/// Converts local time to @em GMT depending on the OS time zone settings.
/// @warning The function will fail if the local date is before Jan 1, 1970 2.01 am or after Jan 18, 2038 7 pm.
/// @param[in] tLocal							The local time.
/// @param[out] tGMT							Filled with the calculated @em GMT time, or @formatParam{tLocal} if an error occurred.
/// @return												@trueIfOtherwiseFalse{successful}
//----------------------------------------------------------------------------------------
Bool LocalToGMTime(const DateTime &tLocal, DateTime &tGMT);

//----------------------------------------------------------------------------------------
/// Converts @em GMT time to local depending on the OS time zone settings.
/// @param[in] tGMT								The @em GMT time.
/// @param[out] tLocal						Filled with the calculated local time, or @formatParam{tGMT} if an error occurred.
/// @return												@trueIfOtherwiseFalse{successful}
//----------------------------------------------------------------------------------------
Bool GMTimeToLocal(const DateTime &tGMT, DateTime &tLocal);

//----------------------------------------------------------------------------------------
/// Gets the day of the week of the date @formatParam{lYear}-@formatParam{lMonth}-@formatParam{lDay}.
/// @param[in] lYear							The year.
/// @param[in] lMonth							The month number. (@em 1 means January.)
/// @param[in] lDay								The day in the month.
/// @return												The day of the week: @enumerateEnum{DayOfWeek}
//----------------------------------------------------------------------------------------
DAYOFWEEK GetDayOfWeek(Int32 lYear, Int32 lMonth, Int32 lDay);

//----------------------------------------------------------------------------------------
/// Formats the given date time @formatParam{t} and output it as a string.
/// @param[in] pszFormat					The format options (same as @em strftime() format).
/// @param[in] t									The date time to format.
/// @return												The formatted string for the date time.
//----------------------------------------------------------------------------------------
String FormatTime(const char* pszFormat, const DateTime &t);

//----------------------------------------------------------------------------------------
/// Parses a time string (e.g. @em "12:34:56").
/// @param[in] timestr						The time string to parse. The format is @em "hour:minute:second".
/// @param[out] hour							Assigned the parsed hour.
/// @param[out] minute						Assigned the parsed minute.
/// @param[out] second						Assigned the parsed second.
/// @return												@trueIfOtherwiseFalse{successful}
//----------------------------------------------------------------------------------------
Bool ParseTimeString(String timestr, Int32 &hour, Int32 &minute, Int32 &second);

//----------------------------------------------------------------------------------------
/// Parses a date string (e.g. @em "1/4/2010").
/// @param[in] datestr						The date string to parse. The format is @em "day/month/year".
/// @param[out] year							Assigned the parsed year.
/// @param[out] month							Assigned the parsed month.
/// @param[out] day								Assigned the parsed day.
/// @return												@trueIfOtherwiseFalse{successful}
//----------------------------------------------------------------------------------------
Bool ParseDateString(String datestr, Int32 &year, Int32 &month, Int32 &day);

//----------------------------------------------------------------------------------------
/// Converts a time as a formatted string (e.g. @em "12:34:56").
/// @param[in] d									The date time.
/// @param[in] bShowSeconds				@formatConstant{true} to include seconds into the time string. Default to @formatConstant{true}.
/// @return												The time string.  The format is @em "hour:minute:second".
//----------------------------------------------------------------------------------------
String TimeToString(const DateTime &d, const Bool bShowSeconds = true);

//----------------------------------------------------------------------------------------
/// Converts a date as a formatted string.
/// @note The format of the returned string depends on the current OS date and time settings.
/// @param[in] d									The date time.
/// @return												The date string.
//----------------------------------------------------------------------------------------
String DateToString(const DateTime &d);

//----------------------------------------------------------------------------------------
/// Retrieves the name of a month in the current @C4D interface language.
/// @param[in] month							The month: @enumerateEnum{MonthOfYear}
/// @return												The month's name in the current @C4D interface language.
//----------------------------------------------------------------------------------------
String GetMonthName(Int month);

//----------------------------------------------------------------------------------------
/// Tries to correct invalid date values, e.g. keeping the values within valid limits.
/// @param[out] year							Assigned the corrected year.
/// @param[out] month							Assigned the corrected month.
/// @param[out] day								Assigned the corrected day.
//----------------------------------------------------------------------------------------
void ValidateDate(Int32 &year, Int32 &month, Int32 &day);

//----------------------------------------------------------------------------------------
/// Tries to correct invalid time values, e.g. keeping the values within valid limits.
/// @param[out] hour							Assigned the corrected hour.
/// @param[out] minute						Assigned the corrected minute.
/// @param[out] second						Assigned the corrected second.
//----------------------------------------------------------------------------------------
void ValidateTime(Int32 &hour, Int32 &minute, Int32 &second);

/// @cond IGNORE

// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF

#ifndef _DATETIMECONTROL_INTERNAL_DEF_
	class iDateTimeControl : public iBaseCustomGui
	{
		iDateTimeControl(const BaseContainer &settings, CUSTOMGUIPLUGIN *plugin) : iBaseCustomGui(settings, plugin) { }
	};
	class iDateTimeData
	{
	};
#else
	class iDateTimeControl;
	class iDateTimeData;
#endif

struct DateTimechooserLib : public BaseCustomGuiLib
{
	DateTime					(iDateTimeControl::*GetDateTimeGUI)() const;
	void							(iDateTimeControl::*SetDateTimeGUI)(const DateTime &d, Bool bSetDate, Bool bSetTime);

	DateTime					(iDateTimeData::*GetDateTimeData)() const;
	void							(iDateTimeData::*SetDateTimeData)(const DateTime &d, Bool bSetDate, Bool bSetTime);

	Float64						(*GetJulianDay)(const DateTime &t);
	DateTime					(*FromJulianDay)(Float64 j);
	void							(*GetDateTimeNow)(DateTime& t);
	Bool							(*LocalToGMTime)(const DateTime &tLocal, DateTime &tGMT);
	Bool							(*GMTimeToLocal)(const DateTime &tGMT, DateTime &tLocal);
	DAYOFWEEK					(*GetDayOfWeek)(Int32 lYear, Int32 lMonth, Int32 lDay);

	DateTimeData*			(*DateTimeData_Alloc)();
	void							(*DateTimeData_Free)(DateTimeData *&pData);
	String						(*FormatTime)(const char* pszFormat, const DateTime &t);

	Bool							(*ParseTimeString)(String timestr, Int32 &hour, Int32 &minute, Int32 &second);
	Bool							(*ParseDateString)(String datestr, Int32 &year, Int32 &month, Int32 &day);
	String						(*TimeToString)(const DateTime &d, const Bool bShowSeconds);
	String						(*DateToString)(const DateTime &d);
	String						(*GetMonthName)(Int month);
	void							(*ValidateDate)(Int32 &year, Int32 &month, Int32 &day);
	void							(*ValidateTime)(Int32 &hour, Int32 &minute, Int32 &second);
};

// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF

/// @endcond

#endif // CUSTOMGUI_DATETIME_H__
