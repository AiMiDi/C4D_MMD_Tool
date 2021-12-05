#if 1
#ifdef __API_INTERN__
#endif
namespace enum131 { enum class OITMODE
{
	OFF			= 0,
	FIRST		= 1,
	MIDDLE	= 2,
	LAST		= 3
} ; }
maxon::String PrivateToString_OITMODE131(std::underlying_type<enum131::OITMODE>::type x, const maxon::FormatStatement* fmt)
{
	const maxon::UInt64 values[] = {(maxon::UInt64) enum131::OITMODE::OFF, (maxon::UInt64) enum131::OITMODE::FIRST, (maxon::UInt64) enum131::OITMODE::MIDDLE, (maxon::UInt64) enum131::OITMODE::LAST};
	return maxon::StringInterface::PrivateEnumToString((maxon::UInt64) x, "OITMODE", SIZEOF(x), false, values, "OFF\0FIRST\0MIDDLE\0LAST\0", fmt);
}
#endif
