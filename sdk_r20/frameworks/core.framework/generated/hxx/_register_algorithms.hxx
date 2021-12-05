#if 1
namespace maxon
{
	namespace enum430 { enum class MOVE_MODE
	{
		KEEP_SOURCE,
		DESTRUCT_SOURCE
	} ; }
	maxon::String PrivateToString_MOVE_MODE430(std::underlying_type<enum430::MOVE_MODE>::type x, const maxon::FormatStatement* fmt)
	{
		const maxon::UInt64 values[] = {(maxon::UInt64) enum430::MOVE_MODE::KEEP_SOURCE, (maxon::UInt64) enum430::MOVE_MODE::DESTRUCT_SOURCE};
		return maxon::StringInterface::PrivateEnumToString((maxon::UInt64) x, "MOVE_MODE", SIZEOF(x), false, values, "KEEP_SOURCE\0DESTRUCT_SOURCE\0", fmt);
	}
	namespace enum1997 { enum class NO_MATCH_TYPE
	{
		VALUE = 1
	} ; }
	maxon::String PrivateToString_NO_MATCH_TYPE1997(std::underlying_type<enum1997::NO_MATCH_TYPE>::type x, const maxon::FormatStatement* fmt)
	{
		const maxon::UInt64 values[] = {(maxon::UInt64) enum1997::NO_MATCH_TYPE::VALUE};
		return maxon::StringInterface::PrivateEnumToString((maxon::UInt64) x, "NO_MATCH_TYPE", SIZEOF(x), false, values, "VALUE\0", fmt);
	}
}
#endif
