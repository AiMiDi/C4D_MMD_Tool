#if 1
namespace maxon
{
#ifndef DOXYGEN
#endif
	namespace enum134 { enum class DATATYPEMODE
	{
		SMALLISPOD,
		SMALL,
		BIG,
	} ; }
	maxon::String PrivateToString_DATATYPEMODE134(std::underlying_type<enum134::DATATYPEMODE>::type x, const maxon::FormatStatement* fmt)
	{
		const maxon::UInt64 values[] = {(maxon::UInt64) enum134::DATATYPEMODE::SMALLISPOD, (maxon::UInt64) enum134::DATATYPEMODE::SMALL, (maxon::UInt64) enum134::DATATYPEMODE::BIG};
		return maxon::StringInterface::PrivateEnumToString((maxon::UInt64) x, "DATATYPEMODE", SIZEOF(x), false, values, "SMALLISPOD\0SMALL\0BIG\0", fmt);
	}
}
#endif
