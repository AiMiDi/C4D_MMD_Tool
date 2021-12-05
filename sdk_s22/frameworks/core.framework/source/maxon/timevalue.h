#ifndef TIMEVALUE_H__
#define TIMEVALUE_H__

#include "maxon/apibase.h"
#include "maxon/datatype.h"

class DataSerializeInterface;

namespace maxon
{

/// @addtogroup MATH
/// @{

const Float64 FRAMERATE_DEFAULT   = 30.0;					///< Default frame rate of 30 fps.
const Float64 FRAMERATE_NTSC			= 30.0 / 1.001;	///< NTSC frame rate is approximately 29.97 fps.
const Float64 FRAMERATE_PAL				= 25.0;					///< PAL frame rate is 25 fps.
const Float64 FRAMERATE_FILM			= 24.0;					///< Movie frame rate is 24 fps.
const Float64 FRAMERATE_FILM_NTSC = 24.0 / 1.001;	///< Modified movie frame rate to avoid frame roll when transfering video to NTSC, approx. 23.976 fps.

/// format in which time values are displayed
enum class TIMEFORMAT
{
	SECONDS						= 0,	///< display time in seconds
	FRAMES						= 1,	///< display time as a frame number
	SMPTE							= 2,	///< display time as SMPTE time code
	SMPTE_DROPFRAMES	= 3		///< display clock time as SMPTE time code (see <a href="http://en.wikipedia.org/wiki/SMPTE_timecode">here</a> for information on drop frames)
} MAXON_ENUM_LIST(TIMEFORMAT);

//----------------------------------------------------------------------------------------
/// The TimeValue class encapsulates a timer value.
//----------------------------------------------------------------------------------------
class TimeValue
{
public:
	class CurrentTime { };

	static const CurrentTime NOW;

	//----------------------------------------------------------------------------------------
	/// Default constructor
	//----------------------------------------------------------------------------------------
	TimeValue() : _value(Float64(0.0))
	{
	}

	//----------------------------------------------------------------------------------------
	/// Initialize with the current time stamp.
	//----------------------------------------------------------------------------------------
	explicit TimeValue(CurrentTime);

	//----------------------------------------------------------------------------------------
	/// Don't initialize class (for better speed)
	//----------------------------------------------------------------------------------------
	explicit TimeValue(ENUM_DONT_INITIALIZE v)
	{
	}

	//----------------------------------------------------------------------------------------
	/// Default constructor
	//----------------------------------------------------------------------------------------
	TimeValue(const TimeValue& src) : _value(src._value)
	{
	}

	//----------------------------------------------------------------------------------------
	/// construct a time from an integer frame number and a frame rate.
	/// the frame rate doesn't need to be an integer and can e.g. be FRAMERATE_NTSC (29.97)
	//----------------------------------------------------------------------------------------
	explicit TimeValue(Int frame, Float64 frameRate) : _value(frameRate != 0.0 ? Float64(frame) / frameRate : 0.0)
	{
	}

	//----------------------------------------------------------------------------------------
	/// Assignment operator
	//----------------------------------------------------------------------------------------
	TimeValue& operator =(const TimeValue& src)
	{
		_value = src._value;																		// self assignment is no problem here, therefore no check if (this != &src)
		return *this;
	}

	//----------------------------------------------------------------------------------------
	/// Compares two TimeValues
	//----------------------------------------------------------------------------------------
	Bool operator ==(const TimeValue& b) const
	{
		return _value == b._value;
	}

	//----------------------------------------------------------------------------------------
	/// Compares two TimeValues
	//----------------------------------------------------------------------------------------
	Bool operator <(const TimeValue& b) const
	{
		return _value < b._value;
	}

	MAXON_OPERATOR_COMPARISON(TimeValue)

	//----------------------------------------------------------------------------------------
	/// Adds two TimeValues
	//----------------------------------------------------------------------------------------
	TimeValue operator +(const TimeValue& b) const
	{
		return TimeValue(_value + b._value);
	}

	//----------------------------------------------------------------------------------------
	/// Adds two TimeValues
	//----------------------------------------------------------------------------------------
	TimeValue& operator +=(const TimeValue& b)
	{
		_value += b._value;
		return *this;
	}

	//----------------------------------------------------------------------------------------
	/// Subtracts two TimeValues
	//----------------------------------------------------------------------------------------
	TimeValue operator -(const TimeValue& b) const
	{
		return TimeValue(_value - b._value);
	}

	//----------------------------------------------------------------------------------------
	/// Subtracts two TimeValues
	//----------------------------------------------------------------------------------------
	const TimeValue& operator -=(const TimeValue& b)
	{
		_value -= b._value;
		return *this;
	}

	//----------------------------------------------------------------------------------------
	/// Multiplies a TimeValue with a factor.
	/// @param[in] b									The second factor.
	/// @return												The result of this * b.
	//----------------------------------------------------------------------------------------
	TimeValue& operator *=(const Float64 b)
	{
		_value *= b;
		return *this;
	}

	//----------------------------------------------------------------------------------------
	/// Multiplies a TimeValue with a factor.
	/// @param[in] a									The first factor.
	/// @param[in] b									The second factor.
	/// @return												The result of a * b.
	//----------------------------------------------------------------------------------------
	inline friend TimeValue operator *(const TimeValue& a, const Float64& b)
	{
		return TimeValue(a._value * b);
	}

	//----------------------------------------------------------------------------------------
	/// Divides two TimeValues and returns the quotient.
	/// @param[in] a									The dividend.
	/// @param[in] b									The divisor. If the divisor is 0, the result will be undefined (floating point exception).
	/// @return												The result of a / b, the quotient has unit therefore it is returned as Float64.
	//----------------------------------------------------------------------------------------
	inline friend Float64 operator /(const TimeValue& a, const TimeValue& b)
	{
		if (b._value == 0.0)
			return 0.0;
		return a._value / b._value;
	}

	//----------------------------------------------------------------------------------------
	/// Divides a TimeValues by a scalar and returns the quotient.
	/// @param[in] a									The dividend.
	/// @param[in] b									The divisor. If the divisor is 0, the result will be undefined (floating point exception).
	/// @return												The result of a / b.
	//----------------------------------------------------------------------------------------
	inline friend TimeValue operator /(const TimeValue& a, const Float64 b)
	{
		if (b == 0.0)
			return TimeValue(0.0);
		return TimeValue(a._value / b);
	}

	//----------------------------------------------------------------------------------------
	/// Get the TimerValue
	/// @return												Time value in hours.
	//----------------------------------------------------------------------------------------
	Float64 GetHours() const
	{
		return _value * Float64(1.0 / (60.0 * 60.0));
	}

	//----------------------------------------------------------------------------------------
	/// Set the TimeValue
	/// @param[in] hours							Time value in hours.
	//----------------------------------------------------------------------------------------
	void SetHours(Float64 hours)
	{
		_value = hours * Float64(60.0 * 60.0);
	}

	//----------------------------------------------------------------------------------------
	/// Get the TimeValue
	/// @return												Time value in minutes.
	//----------------------------------------------------------------------------------------
	Float64 GetMinutes() const
	{
		return _value * Float64(1.0 / 60.0);
	}

	//----------------------------------------------------------------------------------------
	/// Set the TimeValue
	/// @param[in] minutes						Time value in minutes.
	//----------------------------------------------------------------------------------------
	void SetMinutes(Float64 minutes)
	{
		_value = minutes * Float64(60.0);
	}

	//----------------------------------------------------------------------------------------
	/// Get the TimeValue
	/// @return												Time value in seconds.
	//----------------------------------------------------------------------------------------
	Float64 GetSeconds() const
	{
		return _value;
	}

	//----------------------------------------------------------------------------------------
	/// Set the TimeValue
	/// @param[in] seconds						time value in seconds
	//----------------------------------------------------------------------------------------
	void SetSeconds(Float64 seconds)
	{
		_value = seconds;
	}

	//----------------------------------------------------------------------------------------
	/// Get the TimeValue
	/// @return												time value in milliseconds
	//----------------------------------------------------------------------------------------
	Float64 GetMilliseconds() const
	{
		static const Float64 MAX_MILLISECONDS = MAXVALUE_FLOAT64 * Float64(0.001);
		if (MAXON_UNLIKELY(_value >= MAX_MILLISECONDS))
		{
			// TIMEVALUE_INFINITE is always returned as MAXVALUE_FLOAT64 whereas values below it will be clipped.
			if (_value == MAXVALUE_FLOAT64)
				return MAXVALUE_FLOAT64;
			DebugStop("TimeValue must be clipped.");
			return MAXVALUE_FLOAT64 * 0.5;
		}
		return _value * Float64(1000.0);
	}

	//----------------------------------------------------------------------------------------
	/// Set the TimeValue
	/// @param[in] milliseconds				time value in milliseconds
	//----------------------------------------------------------------------------------------
	void SetMilliseconds(Float64 milliseconds)
	{
		_value = milliseconds * Float64(0.001);
	}

	//----------------------------------------------------------------------------------------
	/// Get the TimeValue
	/// @return												time value in microseconds
	//----------------------------------------------------------------------------------------
	Float64 GetMicroseconds() const
	{
		static const Float64 MAX_MICROSECONDS = MAXVALUE_FLOAT64 * Float64(0.000001);
		if (MAXON_UNLIKELY(_value >= MAX_MICROSECONDS))
		{
			// TIMEVALUE_INFINITE is always returned as MAXVALUE_FLOAT64 whereas values below it will be clipped.
			if (_value == MAXVALUE_FLOAT64)
				return MAXVALUE_FLOAT64;
			DebugStop("TimeValue must be clipped.");
			return MAXVALUE_FLOAT64 * 0.5;
		}
		return _value * Float64(1000000.0);
	}

	//----------------------------------------------------------------------------------------
	/// Set the TimeValue
	/// @param[in] microseconds				time value in microseconds
	//----------------------------------------------------------------------------------------
	void SetMicroseconds(Float64 microseconds)
	{
		_value = microseconds * Float64(0.000001);
	}

	//----------------------------------------------------------------------------------------
	/// Get the TimeValue
	/// @return												time value in nanoseconds
	//----------------------------------------------------------------------------------------
	Float64 GetNanoseconds() const
	{
		static const Float64 MAX_NANOSECONDS = MAXVALUE_FLOAT64 * Float64(0.000000001);
		if (MAXON_UNLIKELY(_value >= MAX_NANOSECONDS))
		{
			// TIMEVALUE_INFINITE is always returned as MAXVALUE_FLOAT64 whereas values below it will be clipped.
			if (_value == MAXVALUE_FLOAT64)
				return MAXVALUE_FLOAT64;
			DebugStop("TimeValue must be clipped.");
			return MAXVALUE_FLOAT64 * 0.5;
		}
		return _value * Float64(1000000000.0);
	}

	//----------------------------------------------------------------------------------------
	/// Set the TimeValue
	/// @param[in] nanoseconds				time value in nanoseconds
	//----------------------------------------------------------------------------------------
	void SetNanoseconds(Float64 nanoseconds)
	{
		_value = nanoseconds * Float64(0.000000001);
	}

	//----------------------------------------------------------------------------------------
	/// Returns the current time stamp. You can use this value for benchmarking/profiling.
	/// The resolution is much higher than milliseconds.
	/// @return												Current time stamp.
	//----------------------------------------------------------------------------------------
	static TimeValue GetTime();

	//----------------------------------------------------------------------------------------
	/// Gets the current time and subtracts it from the value stored in the TimeValue.
	/// @code
	/// TimeValue t1 = TimeValue::GetTime();
	/// ... do anything ...
	/// t1.Stop();
	/// DiagnosticOutput("Duration: @", t1);
	/// @endcode
	/// @return												Returns the timer difference.
	//----------------------------------------------------------------------------------------
	const TimeValue& Stop();

	//----------------------------------------------------------------------------------------
	/// Converts the value into a string.
	/// @param[in] formatStatement		Nullptr or an additional formatting instruction. See also @ref format_timer.
	/// @return												The converted result.
	//----------------------------------------------------------------------------------------
	String ToString(const FormatStatement* formatStatement) const;

	//----------------------------------------------------------------------------------------
	/// Returns the hash code of this object.
	//----------------------------------------------------------------------------------------
	UInt GetHashCode() const
	{
		return DefaultCompare::GetHashCode(_value);
	}

	//----------------------------------------------------------------------------------------
	/// retrieve frame number for a given frame rate.
	/// note that frame numbers are integer and therefore quantized
	//----------------------------------------------------------------------------------------
	Int GetFrame(Float64 frameRate) const;

	//----------------------------------------------------------------------------------------
	/// quantize the time for a given frame rate, so that its frame value is a multiple of the specified frame rate
	//----------------------------------------------------------------------------------------
	void Quantize(Float64 frameRate);

	//----------------------------------------------------------------------------------------
	/// Convert TimeValue into String.
	/// @param[in] timeFormat					Specifies the display format.
	/// 															In case of TIMEFORMAT::SECONDS	the string will contain a floating point number with two digits after the comma.<BR>
	/// 															In case of TIMEFORMAT::FRAMES the string will contain an integer frame number or -if the time does not fall on frame boundaries- a floating point number with two digits after the comma.<BR>
	/// 															In case of TIMEFORMAT::SMPTE the return will have the format HH:MM:SS:FF. Frames are always integer values.<BR>
	/// 															In case of TIMEFORMAT::SMPTE_DROPFRAMES the return will have the format HH;MM;SS;FF. Note the semicolons instead of the colons. Read more about <a href="http://en.wikipedia.org/wiki/SMPTE_timecode">drop frames here</a>. A TimeValue(3600.0) equals a drop frame time code of 01:00:03:18 (3600 * 30 frames take roughly 1 hour and 3.6 seconds to play back at NTSC frame rate). If the passed frame rate does not match FRAMERATE_NTSC or FRAMERATE_FILM_NTSC the result will be as if TIMEFORMAT::SMPTE was passed.
	/// @param[in] frameRate					The used frame rate, does not need to be provided if TIMEFORMAT::SECONDS is set.
	/// @return												The time as a readable string.
	//----------------------------------------------------------------------------------------
	String TimeToString(TIMEFORMAT timeFormat = TIMEFORMAT::SECONDS, Float64 frameRate = 1) const;

	//----------------------------------------------------------------------------------------
	/// Convert String into TimeValue.
	/// @param[in] str								The string to be converted.
	/// @param[in] timeFormat					Specifies the format of the passed string. See also TimeValue::ToString. In case of a SMPTE format drop frame or non-drop frame style is determined by this value and both colons or semicolons are allowed.
	/// @param[in] frameRate					The used frame rate, does not need to be provided if TIMEFORMAT::SECONDS is set.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	Result<void> TimeFromString(const String& str, TIMEFORMAT timeFormat, Float64 frameRate);

	//----------------------------------------------------------------------------------------
	/// Describe all elements of this class for I/O operations.
	/// @param[in] stream							The stream that is used to register the class members.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	static Result<void> DescribeIO(const DataSerializeInterface& stream);

protected:
	explicit TimeValue(Float64 seconds) : _value(seconds)
	{
	}

private:
	Float64 _value = 0.0;
};

//----------------------------------------------------------------------------------------
/// Timer value in hours.
//----------------------------------------------------------------------------------------
class Hours : public TimeValue
{
public:
	explicit Hours(Float64 hours) : TimeValue(hours * Float64(60.0 * 60.0))
	{
	}
};

//----------------------------------------------------------------------------------------
/// Timer value in minutes.
//----------------------------------------------------------------------------------------
class Minutes : public TimeValue
{
public:
	explicit Minutes(Float64 minutes) : TimeValue(minutes * Float64(60.0))
	{
	}
};

//----------------------------------------------------------------------------------------
/// Timer value in seconds.
//----------------------------------------------------------------------------------------
class Seconds : public TimeValue
{
public:
	explicit Seconds(Float64 seconds) : TimeValue(seconds)
	{
	}
};

//----------------------------------------------------------------------------------------
/// Timer value in milliseconds.
//----------------------------------------------------------------------------------------
class Milliseconds : public TimeValue
{
public:
	explicit Milliseconds(Float64 milliseconds) : TimeValue(milliseconds * Float64(0.001))
	{
	}
	MAXON_IMPLICIT Milliseconds(const TimeValue& src) : TimeValue(src)
	{
	}
};

//----------------------------------------------------------------------------------------
/// Timer value in microseconds.
//----------------------------------------------------------------------------------------
class Microseconds : public TimeValue
{
public:
	explicit Microseconds(Float64 microseconds) : TimeValue(microseconds * Float64(0.000001))
	{
	}
	MAXON_IMPLICIT Microseconds(const TimeValue& src) : TimeValue(src)
	{
	}
};

//----------------------------------------------------------------------------------------
/// Timer value in nanoseconds.
//----------------------------------------------------------------------------------------
class Nanoseconds : public TimeValue
{
public:
	explicit Nanoseconds(Float64 nanoseconds) : TimeValue(nanoseconds * Float64(0.000000001))
	{
	}
	MAXON_IMPLICIT Nanoseconds(const TimeValue& src) : TimeValue(src)
	{
	}
};

static const TimeValue TIMEVALUE_INFINITE = Seconds(MAXVALUE_FLOAT64);
static const TimeValue TIMEVALUE_INVALID  = Seconds(MINVALUE_FLOAT64);


//----------------------------------------------------------------------------------------
/// Literal to allow definition of hours
//----------------------------------------------------------------------------------------
inline const TimeValue operator "" _h(long double value)
{
	return Hours(Float64(value));
}

//----------------------------------------------------------------------------------------
/// Literal to allow definition of minutes
//----------------------------------------------------------------------------------------
inline const TimeValue operator "" _min(long double value)
{
	return Minutes(Float64(value));
}

//----------------------------------------------------------------------------------------
/// Literal to allow definition of seconds
//----------------------------------------------------------------------------------------
inline const TimeValue operator "" _sec(long double value)
{
	return Seconds(Float64(value));
}

//----------------------------------------------------------------------------------------
/// Literal to allow definition of milliseconds
//----------------------------------------------------------------------------------------
inline const TimeValue operator "" _ms(long double value)
{
	return Milliseconds(Float64(value));
}

//----------------------------------------------------------------------------------------
/// Literal to allow definition of microseconds
//----------------------------------------------------------------------------------------
inline const TimeValue operator "" _us(long double value)
{
	return Microseconds(Float64(value));
}

//----------------------------------------------------------------------------------------
/// Literal to allow definition of nanoseconds
//----------------------------------------------------------------------------------------
inline const TimeValue operator "" _ns(long double value)
{
	return Nanoseconds(Float64(value));
}

/// @}

MAXON_DATATYPE(TimeValue, "net.maxon.datatype.timevalue");

template <> struct IsZeroInitialized<TimeValue> : public std::true_type { };

} // namespace maxon

#endif // TIMEVALUE_H__
