#ifndef DATETIME_H__
#define DATETIME_H__

#include "maxon/apibase.h"
#include "maxon/datatype.h"
#include "maxon/string.h"
#include "maxon/timevalue.h"

namespace maxon
{

//----------------------------------------------------------------------------------------
/// Day of Week.
//----------------------------------------------------------------------------------------
enum class DAYOFWEEK
{
	MONDAY = 0,						///< Monday
	TUESDAY = 1,					///< Tuesday
	WEDNESDAY = 2,				///< Wednesday
	THURSDAY = 3,					///< Thursday
	FRIDAY = 4,						///< Friday
	SATURDAY = 5,					///< Saturday
	SUNDAY = 6						///< Sunday
} MAXON_ENUM_LIST(DAYOFWEEK);

class UniversalDateTime;

namespace timezone
{
const TimeValue GMT = Hours(0);				// Greenwich  Mean Time
const TimeValue CET = Hours(+1);				// Central European Time
const TimeValue EET = Hours(+2);				// Eastern European Time
const TimeValue PST = Hours(-8);				// Pacific Standard Time
const TimeValue PNT = Hours(-7);				// Phoenix Standard Time
const TimeValue CAT = Hours(-1);				// Central African Time
const TimeValue AKST = Hours(-9);			// Alaska Standard Time
}

//----------------------------------------------------------------------------------------
/// Daylight Saving Time information.
//----------------------------------------------------------------------------------------
enum class DST : Int16
{
	AUTOMATIC = -1,     ///< When a date-time object gets converted the Daylight Saving Time is automatically detected and added.
	NOTSET = 0,					///< When a date-time object gets converted the Daylight Saving Time is not added to the target time.
	SET = 1							///< When a date-time object gets converted the Daylight Saving Time is added to the target time.
} MAXON_ENUM_LIST(DST);

//----------------------------------------------------------------------------------------
/// Variants of Julian Day
//----------------------------------------------------------------------------------------
enum class JULIANDATE
{
	STANDARD = 0,			///<	Standard variant with epoch of 	12h Jan 1, 4713 BC
	REDUCED,					///<	Reduced JD with epoch of 12h Nov 16, 1858
	MODIFIED,					///<	Modified variant with epoch of 0h Nov 17, 1858
	LEGACY,						///<	Legacy mode with Julian Day + 0.5
	TRUNCATED,				///<	Truncated variant with epoch of 0h May 24, 1968
	DUBLIN,						///<	Dublin variant with epoch of 12h Dec 31, 1899
	LILIAN,						///<	Lilian variant with epoch of Oct 15, 1582[9]
	RATEDIE,					///<	Rate Die variant with epoch of 	Jan 1, 1, proleptic Gregorian calendar
	UNIXTIME,					///<	Unix Time variant with epoch of 0h Jan 1, 1970
	MARSSOL,					///<	Mars Sol Date variant with epoch of 12h Dec 29, 1873
} MAXON_ENUM_LIST(JULIANDATE);

//----------------------------------------------------------------------------------------
/// At some point developers have to deal with times, dates and timezones. This topic can
/// promote headaches because it can be quite complex. In general you have to be aware of
/// differences in timezones, especially when your software runs on mobile devices are you
/// let the user share data across countries (or even within the same country).
///
/// In this header file you find some convenient helper functions and classes to reduce the amount
/// of effort you have to put into to handle this topic to a minimum. The implementation
/// and definition of the classes rely on the ISO 8601. Use the UniversalDateTime whenever
/// possible to store normalized time and date values and convert them to a LocalDateTime instance
/// as late as possible (e.g. for a local string output).
//----------------------------------------------------------------------------------------

//----------------------------------------------------------------------------------------
/// An object representing a local 'time and date' of the current system time. All members are public and are
/// allowed to be modified for custom needs. Keep in mind that you have to ensure that the values are correct and valid
/// when converting an object back to UniversalDateTime, otherwise the behavior is undefined.
//----------------------------------------------------------------------------------------
class LocalDateTime
{
public:
	Int32	 _year = 0;		///< Full year, e.g. 2014.
	UChar	 _month = 0;		///< 1..12
	UChar	 _day = 0;			///< 1..31
	UChar	 _hour = 0;		///< 0..23
	UChar	 _minute = 0;	///< 0..59
	UChar	 _second = 0;	///< 0..59

	DST _daylightSavingTime = DST::AUTOMATIC;

	//----------------------------------------------------------------------------------------
	/// Check if the set year is a leap year.
	/// @return												True for a leap year, otherwise false.
	//----------------------------------------------------------------------------------------
	Bool IsLeapYear() const;

	//----------------------------------------------------------------------------------------
	/// Return the day of the set time.
	/// @return												See DAYOFWEEK
	//----------------------------------------------------------------------------------------
	DAYOFWEEK GetDayOfWeek() const;

	//----------------------------------------------------------------------------------------
	/// Converts the local time to the universal date-time
	/// @return												The normalized time.
	//----------------------------------------------------------------------------------------
	UniversalDateTime ConvertToUniversalDateTime() const;

	//----------------------------------------------------------------------------------------
	/// Compare operator ==. The objects must represent a date and time in the same timezone. The Daylight Saving Time is not compared.
	/// @return												True if both UniversalDateTime are identical.
	//----------------------------------------------------------------------------------------
	Bool operator ==(const LocalDateTime& x) const
	{
		return _year == x._year && _month == x._month && _day == x._day && _hour == x._hour && _minute == x._minute && _second == x._second;
	}

	Bool operator !=(const LocalDateTime& x) const
	{
		return !(*this == x);
	}

	//----------------------------------------------------------------------------------------
	/// Resets the date-time object and sets all members to 0.
	//----------------------------------------------------------------------------------------
	void Reset()
	{
		_year = _month = _day = _hour = _minute = _second = 0;
		_daylightSavingTime = DST::AUTOMATIC;
	}

	//----------------------------------------------------------------------------------------
	/// Formats the time into a specific format defined be the format string.
	/// @param[in] formatString				Optional. OS depending C lib format string (see strftime). "%Y-%m-%d %H:%M:%S" is used if formatString is nullptr.
	/// @return												Formated String of the date-time.
	//----------------------------------------------------------------------------------------
	String FormatTime(const Char* formatString) const;
	String ToString(const FormatStatement* formatStatement) const;

	//----------------------------------------------------------------------------------------
	/// Returns the hash value of this object. This value can be used for all HashSet<>/HashMap<> classes.
	//----------------------------------------------------------------------------------------
	UInt GetHashCode() const
	{
		return MAXON_HASHCODE(_year, _month, _day, _hour, _minute, _second, _daylightSavingTime);
	}

	//----------------------------------------------------------------------------------------
	/// Return the current timezone offset to the universal time coordinate (UTC).
	/// @param[out] daylightSavingTime	True if Daylight Saving Time effects the local time.
	/// @return												The timezone offset.
	//----------------------------------------------------------------------------------------
	static TimeValue GetTimezoneOffset(Bool* daylightSavingTime = nullptr);

	//----------------------------------------------------------------------------------------
	/// Check if the passed year is a leap year.
	/// @param[in] year								Year value.
	/// @return												True for a leap year, otherwise false.
	//----------------------------------------------------------------------------------------
	static Bool IsLeapYear(Int year);

	//----------------------------------------------------------------------------------------
	/// Return the day of the passed date.
	/// @param[in] lYear							Year value.
	/// @param[in] lMonth							Month value.
	/// @param[in] lDay								Day value.
	/// @return												See DAYOFWEEK
	//----------------------------------------------------------------------------------------
	static DAYOFWEEK GetDayOfWeek(Int lYear, Int lMonth, Int lDay);

	//----------------------------------------------------------------------------------------
	/// Return the current date-time object of the current time zone.
	/// @return												See LocalDateTime
	//----------------------------------------------------------------------------------------
	static LocalDateTime GetNow();

	//----------------------------------------------------------------------------------------
	/// Creates a date-time object by the passed string and its passed format string.
	/// An example:
	/// @code
	/// iferr_scope;
	/// LocalDateTime dt = LocalDateTime::FromString(str, "%a, %d %b %Y %H:%M:%S") iferr_return;
	/// @endcode
	/// @param[in] dateTimeStr				The time string.
	/// @param[in] formatString				The matching format string.
	/// @return												The date-time object or an error if the passed date-time string cannot be resolved by the format string.
	//----------------------------------------------------------------------------------------
	static Result<LocalDateTime> FromString(const String& dateTimeStr, const Char* formatString);

	//----------------------------------------------------------------------------------------
	/// Creates a local date-time object by the passed date values.
	/// \warning The passed values are not checked for their validity!
	/// @param[in] year								Year value [e.g. 2015]
	/// @param[in] month							Month value value [1-12]
	/// @param[in] day								Day value [1-31]
	/// @param[in] hour								Hour value [0-23]
	/// @param[in] minute							Minute value [0-59]
	/// @param[in] second							Second value [0-59]
	/// @param[in] daylightSavingTime	Optional Daylight Saving Time information. See DST.
	/// @return												date-time object.
	//----------------------------------------------------------------------------------------
	static Result<LocalDateTime> FromValues(Int32 year, UChar month, UChar day, UChar hour, UChar minute, UChar second, DST daylightSavingTime = DST::AUTOMATIC);

	//----------------------------------------------------------------------------------------
	/// Create a local date-time object by passing a Unix time stamp.
	/// @param[in] timestamp					The local Unix time stamp where 0 represents the 01/01/1970-00:00 in the current timezone.
	/// @return												The local date-time object.
	//----------------------------------------------------------------------------------------
	static LocalDateTime FromUnixTimestamp(UInt64 timestamp);
};

using RemoteDateTime = LocalDateTime;

//----------------------------------------------------------------------------------------
/// Class that represents the Universal date-time (UTC+0000). This class should be used whenever you store date and time data and should be converted
/// to the LocalDateTime for a local output as late as possible. The internal representation is an unsigned 64-Bit integer and contains the standard
/// Unix date-time starting with 01/01/1970-00:00 UTC+0000. The resolution of this date-time class is 1-second.
//----------------------------------------------------------------------------------------
class UniversalDateTime
{
public:
	//----------------------------------------------------------------------------------------
	/// Reset all values to zero.
	//----------------------------------------------------------------------------------------
	void Reset()
	{
		_timestamp = 0;
	}

	//----------------------------------------------------------------------------------------
	/// Return the Julian day unit of the universal date-time object.
	/// @param[in] variant						Julian Date Variant.
	/// @return												The Julian day unit.
	//----------------------------------------------------------------------------------------
	Float64 GetJulianDay(JULIANDATE variant) const;

	//----------------------------------------------------------------------------------------
	/// Converts the universal date-time to a local date-time object in the current timezone.
	/// @return												The local date-time.
	//----------------------------------------------------------------------------------------
	LocalDateTime ConvertToLocalDateTime() const;

	//----------------------------------------------------------------------------------------
	/// Converts the universal date-time to a remote date-time.
	/// @param[in] utcOffset					Timezone offset which will be added to the UTC value.
	/// @param[in] dst								If set, Daylight Saving Time will be added.
	/// @return												The remote date-time.
	//----------------------------------------------------------------------------------------
	RemoteDateTime ConvertToLocalDateTime(const TimeValue& utcOffset, DST dst) const;

	//----------------------------------------------------------------------------------------
	/// Return the Unix time stamp.
	/// @return												The Unix time stamp where the value 0 represents the 01/01/1970-00:00 UTC.
	//----------------------------------------------------------------------------------------
	UInt64 GetUnixTimestamp() const
	{
		return _timestamp;
	}

	//----------------------------------------------------------------------------------------
	/// Compare operator ==.
	/// @return												True if both UniversalDateTime are identical.
	//----------------------------------------------------------------------------------------
	Bool operator ==(const UniversalDateTime& x) const
	{
		return _timestamp == x._timestamp;
	}

	//----------------------------------------------------------------------------------------
	/// Compare for less.
	/// @return												True if both this is less than x.
	//----------------------------------------------------------------------------------------
	Bool operator <(const UniversalDateTime& x) const
	{
		return _timestamp < x._timestamp;
	}

	UniversalDateTime& operator += (const TimeValue& t)
	{
		_timestamp += (UInt)t.GetSeconds();
		return *this;
	}

	UniversalDateTime& operator -= (const TimeValue& t)
	{
		_timestamp -= (UInt)t.GetSeconds();
		return *this;
	}

	UniversalDateTime operator +(const TimeValue& t) const
	{
		UniversalDateTime tmp(*this);
		tmp += t;
		return tmp;
	}

	UniversalDateTime operator -(const TimeValue& t) const
	{
		UniversalDateTime tmp(*this);
		tmp -= t;
		return tmp;
	}

	MAXON_OPERATOR_COMPARISON(UniversalDateTime);

	//----------------------------------------------------------------------------------------
	/// Check if the UniversalDateTime has a timestamp greater than 0. Even 0 is a valid timestamp this function can be used
	/// to determine if the time object has a proper value.
	/// @return												True if some date or time is set in the structure.
	//----------------------------------------------------------------------------------------
	Bool IsValid() const
	{
		return _timestamp != 0;
	}

	//----------------------------------------------------------------------------------------
	/// Formats the time into a specific format defined be the format string.
	/// @param[in] formatString				Optional. OS depending C lib format string (see strftime). "%Y-%m-%d %H:%M:%S" is used if formatString is nullptr.
	/// @return												Formated String of the date-time.
	//----------------------------------------------------------------------------------------
	String FormatTime(const Char* formatString) const;

	//----------------------------------------------------------------------------------------
	/// Returns a readable string of the content.
	/// @param[in] formatStatement		Nullptr or additional formatting instruction. See also @ref format_float.
	/// @return												The converted result.
	//----------------------------------------------------------------------------------------
	String ToString(const FormatStatement* formatStatement) const;

	//----------------------------------------------------------------------------------------
	/// Returns the hash value of this object. This value can be used for all HashSet<>/HashMap<> classes.
	//----------------------------------------------------------------------------------------
	UInt GetHashCode() const
	{
		return MAXON_HASHCODE(_timestamp);
	}

	//----------------------------------------------------------------------------------------
	/// Return the current date-time object of the current time zone.
	/// @return												The current date-time.
	//----------------------------------------------------------------------------------------
	static UniversalDateTime GetNow();

	//----------------------------------------------------------------------------------------
	/// Creates a universal date-time object by the passed date values.
	/// \warning The year is the only checked parameter for validity!
	/// @param[in] year								Year value [1970-3000]
	/// @param[in] month							Month value value [1-12]
	/// @param[in] day								Day value [1-31]
	/// @param[in] hour								Hour value [0-23]
	/// @param[in] minute							Minute value [0-59]
	/// @param[in] second							Second value [0-59]
	/// @return												date-time object.
	//----------------------------------------------------------------------------------------
	static Result<UniversalDateTime> FromValues(Int32 year, UChar month, UChar day, UChar hour, UChar minute, UChar second);

	//----------------------------------------------------------------------------------------
	/// Creates a date-time object by the passed Julian day.
	/// @param[in] variant						Julian Date Variant.
	/// @param[in] j									The Julian day value.
	/// @return												See LocalDateTime
	//----------------------------------------------------------------------------------------
	static UniversalDateTime FromJulianDay(JULIANDATE variant, Float64 j);

	//----------------------------------------------------------------------------------------
	/// Creates a Julian date value from single date components. Prefer using this function when you need to convert date-components to julian date,
	/// because UniversalDateTime cannot cover years older than 1970 so UniversalDateTime::GetJulianDay would fail.
	/// @param[in] variant						Julian Date Variant.
	/// @param[in] year								Year value [1970-3000]
	/// @param[in] month							Month value value [1-12]
	/// @param[in] day								Day value [1-31]
	/// @param[in] hour								Hour value [0-23]
	/// @param[in] minute							Minute value [0-59]
	/// @param[in] second							Second value [0-59]
	/// @return												The Julian date.
	//----------------------------------------------------------------------------------------
	static Float64 ToJulianDay(JULIANDATE variant, Int32 year, UChar month, UChar day, UChar hour, UChar minute, UChar second);

	//----------------------------------------------------------------------------------------
	/// Create a universal date-time object by passing a Unix time stamp.
	/// @param[in] timestamp					The Unix time stamp where value 0 represents the 01/01/1970-00:00 UTC.
	/// @return												The universal date-time object.
	//----------------------------------------------------------------------------------------
	static UniversalDateTime FromUnixTimestamp(UInt64 timestamp);

	//----------------------------------------------------------------------------------------
	/// Describe all elements of this class for I/O operations.
	/// @param[in] stream							The stream that is used to register the class members.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	static Result<void> DescribeIO(const DataSerializeInterface& stream);

	static UniversalDateTime g_nullValue;

	//----------------------------------------------------------------------------------------
	/// Returns a null value of the UniversalDateTime (see nullvalue.h for more details).
	/// @return												A null value of the UniversalDateTime.
	//----------------------------------------------------------------------------------------
	static const UniversalDateTime& NullValue() { return g_nullValue; }

private:
	UInt64 _timestamp = 0;
};

MAXON_DATATYPE(UniversalDateTime, "net.maxon.datatype.universaldatetime");
MAXON_DATATYPE(LocalDateTime, "net.maxon.datatype.localdatetime");

}

#endif // DATETIME_H__
