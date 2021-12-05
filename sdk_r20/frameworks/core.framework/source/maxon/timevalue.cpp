#include "maxon/timevalue.h"
#include "maxon/unicodeutils.h"
#include "maxon/dataserialize.h"

namespace maxon
{

String TimeValue::ToString(const FormatStatement* formatStatement) const
{
	CString format;
	if (formatStatement)
		format = formatStatement->Get("timer");

	if (*this == TIMEVALUE_INFINITE)
	{
		return "<<infinite>>"_s;
	}
	else
	{
		Float value, value2 = 0.0;
		Bool value2Used = false;
		value = GetMilliseconds();
		String unit = "ms"_s;
		if (Abs(value) < 1.0)
		{
			value = GetMicroseconds();
			unit = "us"_s;
			if (Abs(value) < 1.0)
			{
				value = GetNanoseconds();
				unit = "ns"_s;
			}
		}

		Int len = format.GetLength();
		if (len >= 3 && UnicodeUtils::LowerCase(UChar(format[0])) == UChar('m') && UnicodeUtils::LowerCase(UChar(format[1])) == UChar('i') && UnicodeUtils::LowerCase(UChar(format[2])) == UChar('n'))
		{
			value = GetMinutes();
			unit = "min"_s;
			format.Erase(0, 3) iferr_cannot_fail("Length was checked");
		}
		else if (len >= 3 && UnicodeUtils::LowerCase(UChar(format[0])) == UChar('m') && UnicodeUtils::LowerCase(UChar(format[1])) == UChar('_') && UnicodeUtils::LowerCase(UChar(format[2])) == UChar('s'))
		{
			value = GetMinutes();
			value2 = value;
			value = Floor(value);
			value2 = (value2 - value) * 60.0;
			value2Used = true;
			unit = "min"_s;
			format.Erase(0, 3) iferr_cannot_fail("Length was checked");
		}
		else if (len >= 1 && UnicodeUtils::LowerCase(UChar(format[0])) == UChar('s'))
		{
			value = GetSeconds();
			unit = "s"_s;
			format.Erase(0, 1) iferr_cannot_fail("Length was checked");
		}
		else if (len >= 2 && UnicodeUtils::LowerCase(UChar(format[0])) == UChar('n') && UnicodeUtils::LowerCase(UChar(format[1])) == UChar('s'))
		{
			value = GetNanoseconds();
			unit = "ns"_s;
			format.Erase(0, 2) iferr_cannot_fail("Length was checked");
		}
		else if (len >= 2 && UnicodeUtils::LowerCase(UChar(format[0])) == UChar('u') && UnicodeUtils::LowerCase(UChar(format[1])) == UChar('s'))
		{
			value = GetMicroseconds();
			unit = "us"_s;
			format.Erase(0, 2) iferr_cannot_fail("Length was checked");
		}
		else if (len >= 2 && UnicodeUtils::LowerCase(UChar(format[0])) == UChar('m') && UnicodeUtils::LowerCase(UChar(format[1])) == UChar('s'))
		{
			value = GetMilliseconds();
			unit = "ms"_s;
			format.Erase(0, 2) iferr_cannot_fail("Length was checked");
		}
		else if (len >= 2 && UnicodeUtils::LowerCase(UChar(format[0])) == UChar('p') && UnicodeUtils::LowerCase(UChar(format[1])) == UChar('s'))
		{
			value = Inverse(GetSeconds());
			unit = "per second"_s;
			format.Erase(0, 2) iferr_cannot_fail("Length was checked");
		}

		if (format.IsEmpty())
			format = ".1"_cs;

		if (value2Used)
		{
			FormatStatement floatStatement;
			FormatStatement floatStatement2;
			floatStatement.Set(nullptr, ".0"_cs) iferr_ignore("Ignore ToString errors");
			floatStatement2.Set(nullptr, "2'0'.0"_cs) iferr_ignore("Ignore ToString errors");

			return maxon::ToString(value, &floatStatement) + ":"_s + maxon::ToString(value2, &floatStatement2) + " "_s + unit;
		}

		FormatStatement floatStatement;
		floatStatement.Set(nullptr, format) iferr_ignore("Ignore ToString errors");

		return maxon::ToString(value, &floatStatement) + " "_s + unit;
	}
}

Int TimeValue::GetFrame(Float64 frameRate) const
{
	Float64 value = GetSeconds();
	if (value >= 0.0)
		return Int(value * frameRate + 0.001);
	else
		return Int(value * frameRate - 0.001);
}

void TimeValue::Quantize(Float64 frameRate)
{
	*this = TimeValue(GetFrame(frameRate), frameRate);
}

String TimeValue::TimeToString(TIMEFORMAT format, Float64 frameRate) const
{
	// the only drop frame formats are 29.970 and 23.976
	if (format == TIMEFORMAT::SMPTE_DROPFRAMES && frameRate != FRAMERATE_NTSC && frameRate != FRAMERATE_FILM_NTSC)
		format = TIMEFORMAT::SMPTE;

	switch (format)
	{
		default:
		case TIMEFORMAT::SECONDS:
			return String::FloatToString(GetSeconds());

		case TIMEFORMAT::FRAMES:
		{
			Float64 val = GetSeconds();
			if (val >= 0.0)
				val = val * frameRate + 0.001;
			else
				val = val * frameRate - 0.001;

			if (val * 100.0 == Int64(val * 100.0))	// if frame is not a fraction
				return String::IntToString((Int64) val);

			return String::FloatToString(val, STRING_DYNAMIC_DIGITS, 2);		// else show with two digits after the comma
		}

		case TIMEFORMAT::SMPTE_DROPFRAMES:
		{
			if (frameRate < 1.0)
				goto smtpMode;

			Float64 val = GetSeconds();
			String	str;

			if (val < 0.0)
			{
				str = "-"_s;
				val = -val;
			}

			Int intFrameRate = Int(frameRate + 0.1);
			Int frameNumber	 = Int(val * frameRate + 0.001);

			Int dropFrames         = 2;                                 // should 59.94 be supported this needs to be doubled for that case
			Int framesPerMinute    = intFrameRate * 60 - dropFrames;    // 2 drop frames per minute
			Int framesPer10Minutes = 10 * framesPerMinute + dropFrames; // no drop frames every 10 minutes
			Int framesPerHour      = 6 * framesPer10Minutes;

			Int hour     = frameNumber / framesPerHour;
			frameNumber -= hour * framesPerHour;

			Int segment  = frameNumber / framesPer10Minutes;
			frameNumber -= segment * framesPer10Minutes;
			Int minute   = segment * 10;

			segment      = (frameNumber - dropFrames) / framesPerMinute;
			minute      += segment;

			if (segment > 0)
				frameNumber -= segment * framesPerMinute;

			Int second = frameNumber / intFrameRate;
			Int frame	 = frameNumber % intFrameRate;

			str += String::FloatToString((Float64)hour  , 2, 0, false, '0') + ";"_s;
			str += String::FloatToString((Float64)minute, 2, 0, false, '0') + ";"_s;
			str += String::FloatToString((Float64)second, 2, 0, false, '0') + ";"_s;
			str += String::FloatToString((Float64)frame , 2, 0, false, '0');

			return str;
		}

		case TIMEFORMAT::SMPTE:
		{
		smtpMode:
			Float64 val = GetSeconds();
			String	str;

			if (val < 0.0)
			{
				str = "-"_s;
				val = -val;
			}

			Int seconds	= (Int)(GetSeconds() + 0.000001);
			Int hour = seconds / 3600;
			Int minute = (seconds / 60) % 60;
			Int second = seconds % 60;

			str += String::FloatToString((Float64)hour, 2, 0, false, '0') + ":"_s;
			str += String::FloatToString((Float64)minute, 2, 0, false, '0') + ":"_s;
			str += String::FloatToString((Float64)second, 2, 0, false, '0') + ":"_s;

			Int frame = 0;
			if (frameRate >= 1.0)
				frame = Int((val - seconds) * frameRate + 0.000001);

			str += String::FloatToString((Float64)frame, 2, 0, false, '0');

			return str;
		}
	}
}

// CorrectTime transforms the passed time value into a dropframe SMPTE value. All input values must be positive and within valid ranges.
static Float TimeToDropFrame(Int& hours, Int& minutes, Int& seconds, Float& frames, Float frameRate)
{
	Int intFrameRate       = Int(frameRate + 0.1);
	Int dropFrames         = 2;                                 // should 59.94 be supported this needs to be doubled for that case
	Int framesPerMinute    = intFrameRate * 60 - dropFrames;    // 2 drop frames per minute
	Int framesPer10Minutes = 10 * framesPerMinute + dropFrames; // no drop frames every 10 minutes
	Int framesPerHour      = 6 * framesPer10Minutes;

	return (Float(hours * framesPerHour + (minutes / 10) * framesPer10Minutes + (minutes % 10) * framesPerMinute) + seconds * intFrameRate + frames) / frameRate;
}

Result<void> TimeValue::TimeFromString(const String& str, TIMEFORMAT format, Float64 frameRate)
{
	iferr_scope;

	SetSeconds(0.0);	// always initialize with a guaranteed value

	CheckArgument(frameRate >= 1.0, "Framerate too low."); // frame rate must be at least 1

	// the only drop frame formats are 29.970 and 23.976
	if (format == TIMEFORMAT::SMPTE_DROPFRAMES && frameRate != FRAMERATE_NTSC && frameRate != FRAMERATE_FILM_NTSC)
		format = TIMEFORMAT::SMPTE;

	Float64 t;
	switch (format)
	{
		default:
		case TIMEFORMAT::SECONDS:
			t = str.ToFloat() iferr_return;
			SetSeconds(t);
			return OK;

		case TIMEFORMAT::FRAMES:
		{
			t = str.ToFloat() iferr_return;
			t /= frameRate;
			SetSeconds(t);
			return OK;
		}

		case TIMEFORMAT::SMPTE_DROPFRAMES:
		case TIMEFORMAT::SMPTE:
		{
			Int		separator[3], start = 0;
			Int		hours = 0, minutes = 0, seconds = 0, i;
			Float frames;
			Bool	neg = false;

			separator[0] = separator[1] = separator[2] = NOTOK;

			for (i = 0; i < str.GetLength(); i++)
			{
				Utf32Char ch = str[i];
				if (ch == '-' && start == 0)	// first occurence of '-'
				{
					neg = true;
					start = i + 1;
				}
				else if (ch == ':' || ch == ';')
				{
					if (separator[0] == NOTOK)
					{
						separator[0] = i;
					}
					else if (separator[1] == NOTOK)
					{
						separator[1] = i;
					}
					else if (separator[2] == NOTOK)
					{
						separator[2] = i;
					}
					else
					{
						return IllegalArgumentError(MAXON_SOURCE_LOCATION, "Too many separators."_s);
					}
				}
			}

			if (separator[0] == NOTOK)	// if no ':' or ';' is present, handle string as a frame value
			{
				t = str.ToFloat() iferr_return;
				t /= frameRate;
				SetSeconds(t);
				return OK;
			}

			if (separator[1] == NOTOK)	// string has format 00:00
			{
				seconds = str.GetPart(start, StringPosition(separator[0])).ToInt() iferr_return;
				frames = str.GetRightPart(separator[0] + 1).ToFloat() iferr_return;
			}
			else if (separator[2] == NOTOK)	// string has format 00:00:00
			{
				minutes = str.GetPart(start, StringPosition(separator[0])).ToInt() iferr_return;
				seconds = str.GetPart(separator[0] + 1, StringPosition(separator[1])).ToInt() iferr_return;
				frames = str.GetRightPart(separator[1] + 1).ToFloat() iferr_return;
			}
			else	// string has format 00:00:00:00
			{
				hours = str.GetPart(start, StringPosition(separator[0])).ToInt() iferr_return;
				minutes = str.GetPart(separator[0] + 1, StringPosition(separator[1])).ToInt() iferr_return;
				seconds = str.GetPart(separator[1] + 1, StringPosition(separator[2])).ToInt() iferr_return;
				frames = str.GetRightPart(separator[2] + 1).ToFloat() iferr_return;
			}

			if (hours < 0)
				return IllegalArgumentError(MAXON_SOURCE_LOCATION, "Illegal time (hours out of range)."_s);
			if (minutes < 0 || minutes >= 60)
				return IllegalArgumentError(MAXON_SOURCE_LOCATION, "Illegal time (minutes out of range)."_s);
			if (seconds < 0 || seconds >= 60)
				return IllegalArgumentError(MAXON_SOURCE_LOCATION, "Illegal time (seconds out of range)."_s);
			if (frames < 0.0 || frames >= frameRate)
				return IllegalArgumentError(MAXON_SOURCE_LOCATION, "Illegal time (frames out of range)."_s);

			if (format == TIMEFORMAT::SMPTE_DROPFRAMES)
				t = TimeToDropFrame(hours, minutes, seconds, frames, frameRate);
			else
				t = Float(hours * 3600 + minutes * 60 + seconds) + frames / frameRate;

			if (neg)
				t = -t;

			SetSeconds(t);
			return OK;
		}
	}
}

Result<void> TimeValue::DescribeIO(const DataSerializeInterface& stream)
{
	iferr_scope;

	PrepareDescribe(stream, TimeValue);

	Describe("_value", _value, Float64, DESCRIBEFLAGS::NONE) iferr_return;

	return OK;
}

} // namespace maxon
