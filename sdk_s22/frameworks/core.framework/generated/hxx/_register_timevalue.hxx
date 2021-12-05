#if 1
namespace maxon
{
	namespace enum28 { enum class TIMEFORMAT
	{
		SECONDS						= 0,	///< display time in seconds
		FRAMES						= 1,	///< display time as a frame number
		SMPTE							= 2,	///< display time as SMPTE time code
		SMPTE_DROPFRAMES	= 3		///< display clock time as SMPTE time code (see <a href="http://en.wikipedia.org/wiki/SMPTE_timecode">here</a> for information on drop frames)
	} ; }
	maxon::String PrivateToString_TIMEFORMAT28(std::underlying_type<enum28::TIMEFORMAT>::type x, const maxon::FormatStatement* fmt)
	{
		const maxon::UInt64 values[] = {(maxon::UInt64) enum28::TIMEFORMAT::SECONDS, (maxon::UInt64) enum28::TIMEFORMAT::FRAMES, (maxon::UInt64) enum28::TIMEFORMAT::SMPTE, (maxon::UInt64) enum28::TIMEFORMAT::SMPTE_DROPFRAMES};
		return maxon::StringInterface::PrivateEnumToString((maxon::UInt64) x, "TIMEFORMAT", SIZEOF(x), false, values, "SECONDS\0FRAMES\0SMPTE\0SMPTE_DROPFRAMES\0", fmt);
	}
	PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(DT_TimeValue,, "net.maxon.datatype.timevalue");
}
#endif
