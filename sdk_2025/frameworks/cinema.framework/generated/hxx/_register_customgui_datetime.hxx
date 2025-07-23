#if 1
namespace cinema
{
	namespace enum202
	{
		enum class DAYOFWEEK
		{
			MONDAY		= 0,
			TUESDAY		= 1,
			WEDNESDAY	= 2,
			THURSDAY	= 3,
			FRIDAY		= 4,
			SATURDAY	= 5,
			SUNDAY		= 6
		} ;
		static const maxon::UInt64 DAYOFWEEK_values[] = {maxon::UInt64(enum202::DAYOFWEEK::MONDAY), maxon::UInt64(enum202::DAYOFWEEK::TUESDAY), maxon::UInt64(enum202::DAYOFWEEK::WEDNESDAY), maxon::UInt64(enum202::DAYOFWEEK::THURSDAY), maxon::UInt64(enum202::DAYOFWEEK::FRIDAY), maxon::UInt64(enum202::DAYOFWEEK::SATURDAY), maxon::UInt64(enum202::DAYOFWEEK::SUNDAY)};
		static const maxon::EnumInfo DAYOFWEEK_info{"DAYOFWEEK", SIZEOF(DAYOFWEEK), false, "MONDAY\0TUESDAY\0WEDNESDAY\0THURSDAY\0FRIDAY\0SATURDAY\0SUNDAY\0", DAYOFWEEK_values, std::extent<decltype(DAYOFWEEK_values)>::value};
	}
	const maxon::EnumInfo& PrivateGetEnumInfo_DAYOFWEEK202(){ return enum202::DAYOFWEEK_info; }
	namespace enum223
	{
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
		} ;
		static const maxon::UInt64 MONTHOFYEAR_values[] = {maxon::UInt64(enum223::MONTHOFYEAR::JANUARY), maxon::UInt64(enum223::MONTHOFYEAR::FEBRUARY), maxon::UInt64(enum223::MONTHOFYEAR::MARCH), maxon::UInt64(enum223::MONTHOFYEAR::APRIL), maxon::UInt64(enum223::MONTHOFYEAR::MAY), maxon::UInt64(enum223::MONTHOFYEAR::JUNE), maxon::UInt64(enum223::MONTHOFYEAR::JULY), maxon::UInt64(enum223::MONTHOFYEAR::AUGUST), maxon::UInt64(enum223::MONTHOFYEAR::SEPTEMBER), maxon::UInt64(enum223::MONTHOFYEAR::OCTOBER), maxon::UInt64(enum223::MONTHOFYEAR::NOVEMBER), maxon::UInt64(enum223::MONTHOFYEAR::DECEMBER)};
		static const maxon::EnumInfo MONTHOFYEAR_info{"MONTHOFYEAR", SIZEOF(MONTHOFYEAR), false, "JANUARY\0FEBRUARY\0MARCH\0APRIL\0MAY\0JUNE\0JULY\0AUGUST\0SEPTEMBER\0OCTOBER\0NOVEMBER\0DECEMBER\0", MONTHOFYEAR_values, std::extent<decltype(MONTHOFYEAR_values)>::value};
	}
	const maxon::EnumInfo& PrivateGetEnumInfo_MONTHOFYEAR223(){ return enum223::MONTHOFYEAR_info; }
/// @cond IGNORE

#ifndef _DATETIMECONTROL_INTERNAL_DEF_
#else
#endif
/// @endcond

}
#endif
