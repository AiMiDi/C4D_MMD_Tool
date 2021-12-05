#if 1
#ifdef CINEWARE_NAMESPACE_ENABLE
CINEWARE_NAMESPACE_BEGIN
#endif
namespace enum203 { enum class DAYOFWEEK
{
	MONDAY		= 0,
	TUESDAY		= 1,
	WEDNESDAY	= 2,
	THURSDAY	= 3,
	FRIDAY		= 4,
	SATURDAY	= 5,
	SUNDAY		= 6
} ; }
maxon::String PrivateToString_DAYOFWEEK203(std::underlying_type<enum203::DAYOFWEEK>::type x, const maxon::FormatStatement* fmt)
{
	const maxon::UInt64 values[] = {(maxon::UInt64) enum203::DAYOFWEEK::MONDAY, (maxon::UInt64) enum203::DAYOFWEEK::TUESDAY, (maxon::UInt64) enum203::DAYOFWEEK::WEDNESDAY, (maxon::UInt64) enum203::DAYOFWEEK::THURSDAY, (maxon::UInt64) enum203::DAYOFWEEK::FRIDAY, (maxon::UInt64) enum203::DAYOFWEEK::SATURDAY, (maxon::UInt64) enum203::DAYOFWEEK::SUNDAY};
	return maxon::StringInterface::PrivateEnumToString((maxon::UInt64) x, "DAYOFWEEK", SIZEOF(x), false, values, "MONDAY\0TUESDAY\0WEDNESDAY\0THURSDAY\0FRIDAY\0SATURDAY\0SUNDAY\0", fmt);
}
namespace enum224 { enum class MONTHOFYEAR
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
maxon::String PrivateToString_MONTHOFYEAR224(std::underlying_type<enum224::MONTHOFYEAR>::type x, const maxon::FormatStatement* fmt)
{
	const maxon::UInt64 values[] = {(maxon::UInt64) enum224::MONTHOFYEAR::JANUARY, (maxon::UInt64) enum224::MONTHOFYEAR::FEBRUARY, (maxon::UInt64) enum224::MONTHOFYEAR::MARCH, (maxon::UInt64) enum224::MONTHOFYEAR::APRIL, (maxon::UInt64) enum224::MONTHOFYEAR::MAY, (maxon::UInt64) enum224::MONTHOFYEAR::JUNE, (maxon::UInt64) enum224::MONTHOFYEAR::JULY, (maxon::UInt64) enum224::MONTHOFYEAR::AUGUST, (maxon::UInt64) enum224::MONTHOFYEAR::SEPTEMBER, (maxon::UInt64) enum224::MONTHOFYEAR::OCTOBER, (maxon::UInt64) enum224::MONTHOFYEAR::NOVEMBER, (maxon::UInt64) enum224::MONTHOFYEAR::DECEMBER};
	return maxon::StringInterface::PrivateEnumToString((maxon::UInt64) x, "MONTHOFYEAR", SIZEOF(x), false, values, "JANUARY\0FEBRUARY\0MARCH\0APRIL\0MAY\0JUNE\0JULY\0AUGUST\0SEPTEMBER\0OCTOBER\0NOVEMBER\0DECEMBER\0", fmt);
}
/// @cond IGNORE

#ifndef _DATETIMECONTROL_INTERNAL_DEF_
#else
#endif
/// @endcond

#ifdef CINEWARE_NAMESPACE_ENABLE
CINEWARE_NAMESPACE_END
#endif
#endif
