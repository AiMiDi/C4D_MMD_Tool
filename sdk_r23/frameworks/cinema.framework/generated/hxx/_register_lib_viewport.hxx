#if 1
#ifdef CINEWARE_NAMESPACE_ENABLE
CINEWARE_NAMESPACE_BEGIN
#endif
namespace enum153 { enum class VIEWHUD_FLAG
{
	NOUPDATE = (1 << 20),	// private
	////////////////////////////////////////////////////////////
	NONE = 0
} ; }
maxon::String PrivateToString_VIEWHUD_FLAG153(std::underlying_type<enum153::VIEWHUD_FLAG>::type x, const maxon::FormatStatement* fmt)
{
	const maxon::UInt64 values[] = {(maxon::UInt64) enum153::VIEWHUD_FLAG::NOUPDATE, (maxon::UInt64) enum153::VIEWHUD_FLAG::NONE};
	return maxon::StringInterface::PrivateEnumToString((maxon::UInt64) x, "VIEWHUD_FLAG", SIZEOF(x), true, values, "NOUPDATE\0NONE\0", fmt);
}
#ifdef CINEWARE_NAMESPACE_ENABLE
CINEWARE_NAMESPACE_END
#endif
#endif
