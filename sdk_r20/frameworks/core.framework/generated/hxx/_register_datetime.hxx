#if 1
namespace maxon
{
	namespace enum24 { enum class DAYOFWEEK
	{
		MONDAY = 0,						///< Monday
		TUESDAY = 1,					///< Tuesday
		WEDNESDAY = 2,				///< Wednesday
		THURSDAY = 3,					///< Thursday
		FRIDAY = 4,						///< Friday
		SATURDAY = 5,					///< Saturday
		SUNDAY = 6						///< Sunday
	} ; }
	maxon::String PrivateToString_DAYOFWEEK24(std::underlying_type<enum24::DAYOFWEEK>::type x, const maxon::FormatStatement* fmt)
	{
		const maxon::UInt64 values[] = {(maxon::UInt64) enum24::DAYOFWEEK::MONDAY, (maxon::UInt64) enum24::DAYOFWEEK::TUESDAY, (maxon::UInt64) enum24::DAYOFWEEK::WEDNESDAY, (maxon::UInt64) enum24::DAYOFWEEK::THURSDAY, (maxon::UInt64) enum24::DAYOFWEEK::FRIDAY, (maxon::UInt64) enum24::DAYOFWEEK::SATURDAY, (maxon::UInt64) enum24::DAYOFWEEK::SUNDAY};
		return maxon::StringInterface::PrivateEnumToString((maxon::UInt64) x, "DAYOFWEEK", SIZEOF(x), false, values, "MONDAY\0TUESDAY\0WEDNESDAY\0THURSDAY\0FRIDAY\0SATURDAY\0SUNDAY\0", fmt);
	}
	namespace enum47 { enum class DST : Int16
	{
		AUTOMATIC = -1,     ///< When a date-time object gets converted the Daylight Saving Time is automatically detected and added.
		NOTSET = 0,					///< When a date-time object gets converted the Daylight Saving Time is not added to the target time.
		SET = 1							///< When a date-time object gets converted the Daylight Saving Time is added to the target time.
	} ; }
	maxon::String PrivateToString_DST47(std::underlying_type<enum47::DST>::type x, const maxon::FormatStatement* fmt)
	{
		const maxon::UInt64 values[] = {(maxon::UInt64) enum47::DST::AUTOMATIC, (maxon::UInt64) enum47::DST::NOTSET, (maxon::UInt64) enum47::DST::SET};
		return maxon::StringInterface::PrivateEnumToString((maxon::UInt64) x, "DST", SIZEOF(x), false, values, "AUTOMATIC\0NOTSET\0SET\0", fmt);
	}
	namespace enum64 { enum class JULIANDATE
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
	} ; }
	maxon::String PrivateToString_JULIANDATE64(std::underlying_type<enum64::JULIANDATE>::type x, const maxon::FormatStatement* fmt)
	{
		const maxon::UInt64 values[] = {(maxon::UInt64) enum64::JULIANDATE::STANDARD, (maxon::UInt64) enum64::JULIANDATE::REDUCED, (maxon::UInt64) enum64::JULIANDATE::MODIFIED, (maxon::UInt64) enum64::JULIANDATE::LEGACY, (maxon::UInt64) enum64::JULIANDATE::TRUNCATED, (maxon::UInt64) enum64::JULIANDATE::DUBLIN, (maxon::UInt64) enum64::JULIANDATE::LILIAN, (maxon::UInt64) enum64::JULIANDATE::RATEDIE, (maxon::UInt64) enum64::JULIANDATE::UNIXTIME, (maxon::UInt64) enum64::JULIANDATE::MARSSOL};
		return maxon::StringInterface::PrivateEnumToString((maxon::UInt64) x, "JULIANDATE", SIZEOF(x), false, values, "STANDARD\0REDUCED\0MODIFIED\0LEGACY\0TRUNCATED\0DUBLIN\0LILIAN\0RATEDIE\0UNIXTIME\0MARSSOL\0", fmt);
	}
	PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(DT_UniversalDateTime,, "net.maxon.datatype.universaldatetime");
	PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(DT_LocalDateTime,, "net.maxon.datatype.localdatetime");
}
#endif
