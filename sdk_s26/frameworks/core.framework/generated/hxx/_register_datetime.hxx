#if 1
namespace maxon
{
	namespace enum23
	{
		enum class DAYOFWEEK
		{
			MONDAY = 0,						///< Monday
			TUESDAY = 1,					///< Tuesday
			WEDNESDAY = 2,				///< Wednesday
			THURSDAY = 3,					///< Thursday
			FRIDAY = 4,						///< Friday
			SATURDAY = 5,					///< Saturday
			SUNDAY = 6						///< Sunday
		} ;
		static const maxon::UInt64 DAYOFWEEK_values[] = {maxon::UInt64(enum23::DAYOFWEEK::MONDAY), maxon::UInt64(enum23::DAYOFWEEK::TUESDAY), maxon::UInt64(enum23::DAYOFWEEK::WEDNESDAY), maxon::UInt64(enum23::DAYOFWEEK::THURSDAY), maxon::UInt64(enum23::DAYOFWEEK::FRIDAY), maxon::UInt64(enum23::DAYOFWEEK::SATURDAY), maxon::UInt64(enum23::DAYOFWEEK::SUNDAY)};
		static const maxon::EnumInfo DAYOFWEEK_info{"DAYOFWEEK", SIZEOF(DAYOFWEEK), false, "MONDAY\0TUESDAY\0WEDNESDAY\0THURSDAY\0FRIDAY\0SATURDAY\0SUNDAY\0", DAYOFWEEK_values, std::extent<decltype(DAYOFWEEK_values)>::value};
	}
	const maxon::EnumInfo& PrivateGetEnumInfo_DAYOFWEEK23(){ return enum23::DAYOFWEEK_info; }
	namespace enum46
	{
		enum class DST : Int16
		{
			AUTOMATIC = -1,     ///< When a date-time object gets converted the Daylight Saving Time is automatically detected and added.
			NOTSET = 0,					///< When a date-time object gets converted the Daylight Saving Time is not added to the target time.
			SET = 1							///< When a date-time object gets converted the Daylight Saving Time is added to the target time.
		} ;
		static const maxon::UInt64 DST_values[] = {maxon::UInt64(enum46::DST::AUTOMATIC), maxon::UInt64(enum46::DST::NOTSET), maxon::UInt64(enum46::DST::SET)};
		static const maxon::EnumInfo DST_info{"DST", SIZEOF(DST), false, "AUTOMATIC\0NOTSET\0SET\0", DST_values, std::extent<decltype(DST_values)>::value};
	}
	const maxon::EnumInfo& PrivateGetEnumInfo_DST46(){ return enum46::DST_info; }
	namespace enum63
	{
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
		} ;
		static const maxon::UInt64 JULIANDATE_values[] = {maxon::UInt64(enum63::JULIANDATE::STANDARD), maxon::UInt64(enum63::JULIANDATE::REDUCED), maxon::UInt64(enum63::JULIANDATE::MODIFIED), maxon::UInt64(enum63::JULIANDATE::LEGACY), maxon::UInt64(enum63::JULIANDATE::TRUNCATED), maxon::UInt64(enum63::JULIANDATE::DUBLIN), maxon::UInt64(enum63::JULIANDATE::LILIAN), maxon::UInt64(enum63::JULIANDATE::RATEDIE), maxon::UInt64(enum63::JULIANDATE::UNIXTIME), maxon::UInt64(enum63::JULIANDATE::MARSSOL)};
		static const maxon::EnumInfo JULIANDATE_info{"JULIANDATE", SIZEOF(JULIANDATE), false, "STANDARD\0REDUCED\0MODIFIED\0LEGACY\0TRUNCATED\0DUBLIN\0LILIAN\0RATEDIE\0UNIXTIME\0MARSSOL\0", JULIANDATE_values, std::extent<decltype(JULIANDATE_values)>::value};
	}
	const maxon::EnumInfo& PrivateGetEnumInfo_JULIANDATE63(){ return enum63::JULIANDATE_info; }
	PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(DT_UniversalDateTime,, "net.maxon.datatype.universaldatetime");
	PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(DT_LocalDateTime,, "net.maxon.datatype.localdatetime");
}
#endif
