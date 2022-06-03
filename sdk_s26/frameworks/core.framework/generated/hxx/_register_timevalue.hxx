#if 1
namespace maxon
{
	namespace enum27
	{
		enum class TIMEFORMAT
		{
			SECONDS						= 0,	///< display time in seconds
			FRAMES						= 1,	///< display time as a frame number
			SMPTE							= 2,	///< display time as SMPTE time code
			SMPTE_DROPFRAMES	= 3		///< display clock time as SMPTE time code (see <a href="http://en.wikipedia.org/wiki/SMPTE_timecode">here</a> for information on drop frames)
		} ;
		static const maxon::UInt64 TIMEFORMAT_values[] = {maxon::UInt64(enum27::TIMEFORMAT::SECONDS), maxon::UInt64(enum27::TIMEFORMAT::FRAMES), maxon::UInt64(enum27::TIMEFORMAT::SMPTE), maxon::UInt64(enum27::TIMEFORMAT::SMPTE_DROPFRAMES)};
		static const maxon::EnumInfo TIMEFORMAT_info{"TIMEFORMAT", SIZEOF(TIMEFORMAT), false, "SECONDS\0FRAMES\0SMPTE\0SMPTE_DROPFRAMES\0", TIMEFORMAT_values, std::extent<decltype(TIMEFORMAT_values)>::value};
	}
	const maxon::EnumInfo& PrivateGetEnumInfo_TIMEFORMAT27(){ return enum27::TIMEFORMAT_info; }
	PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(DT_TimeValue,, "net.maxon.datatype.timevalue");
}
#endif
