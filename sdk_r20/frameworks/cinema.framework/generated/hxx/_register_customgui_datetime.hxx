#if 1
namespace enum199 { enum class DAYOFWEEK
{
	MONDAY		= 0,
	TUESDAY		= 1,
	WEDNESDAY	= 2,
	THURSDAY	= 3,
	FRIDAY		= 4,
	SATURDAY	= 5,
	SUNDAY		= 6
} ; }
maxon::String PrivateToString_DAYOFWEEK199(std::underlying_type<enum199::DAYOFWEEK>::type x, const maxon::FormatStatement* fmt)
{
	const maxon::UInt64 values[] = {(maxon::UInt64) enum199::DAYOFWEEK::MONDAY, (maxon::UInt64) enum199::DAYOFWEEK::TUESDAY, (maxon::UInt64) enum199::DAYOFWEEK::WEDNESDAY, (maxon::UInt64) enum199::DAYOFWEEK::THURSDAY, (maxon::UInt64) enum199::DAYOFWEEK::FRIDAY, (maxon::UInt64) enum199::DAYOFWEEK::SATURDAY, (maxon::UInt64) enum199::DAYOFWEEK::SUNDAY};
	return maxon::StringInterface::PrivateEnumToString((maxon::UInt64) x, "DAYOFWEEK", SIZEOF(x), false, values, "MONDAY\0TUESDAY\0WEDNESDAY\0THURSDAY\0FRIDAY\0SATURDAY\0SUNDAY\0", fmt);
}
namespace enum220 { enum class MONTHOFYEAR
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
} ; }
maxon::String PrivateToString_MONTHOFYEAR220(std::underlying_type<enum220::MONTHOFYEAR>::type x, const maxon::FormatStatement* fmt)
{
	const maxon::UInt64 values[] = {(maxon::UInt64) enum220::MONTHOFYEAR::JANUARY, (maxon::UInt64) enum220::MONTHOFYEAR::FEBRUARY, (maxon::UInt64) enum220::MONTHOFYEAR::MARCH, (maxon::UInt64) enum220::MONTHOFYEAR::APRIL, (maxon::UInt64) enum220::MONTHOFYEAR::MAY, (maxon::UInt64) enum220::MONTHOFYEAR::JUNE, (maxon::UInt64) enum220::MONTHOFYEAR::JULY, (maxon::UInt64) enum220::MONTHOFYEAR::AUGUST, (maxon::UInt64) enum220::MONTHOFYEAR::SEPTEMBER, (maxon::UInt64) enum220::MONTHOFYEAR::OCTOBER, (maxon::UInt64) enum220::MONTHOFYEAR::NOVEMBER, (maxon::UInt64) enum220::MONTHOFYEAR::DECEMBER};
	return maxon::StringInterface::PrivateEnumToString((maxon::UInt64) x, "MONTHOFYEAR", SIZEOF(x), false, values, "JANUARY\0FEBRUARY\0MARCH\0APRIL\0MAY\0JUNE\0JULY\0AUGUST\0SEPTEMBER\0OCTOBER\0NOVEMBER\0DECEMBER\0", fmt);
}
/// @cond IGNORE

#ifndef _DATETIMECONTROL_INTERNAL_DEF_
#else
#endif
/// @endcond

#endif
