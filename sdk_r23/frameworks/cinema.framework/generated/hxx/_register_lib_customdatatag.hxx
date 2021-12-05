#if 1
#ifdef __API_INTERN__
#else
#endif
#ifdef CINEWARE_NAMESPACE_ENABLE
CINEWARE_NAMESPACE_BEGIN
#endif
namespace enum38 { enum class CUSTOMDATATAG_MODE
{
	VERTEX = 0,
	POLYVERTEX,
} ; }
maxon::String PrivateToString_CUSTOMDATATAG_MODE38(std::underlying_type<enum38::CUSTOMDATATAG_MODE>::type x, const maxon::FormatStatement* fmt)
{
	const maxon::UInt64 values[] = {(maxon::UInt64) enum38::CUSTOMDATATAG_MODE::VERTEX, (maxon::UInt64) enum38::CUSTOMDATATAG_MODE::POLYVERTEX};
	return maxon::StringInterface::PrivateEnumToString((maxon::UInt64) x, "CUSTOMDATATAG_MODE", SIZEOF(x), false, values, "VERTEX\0POLYVERTEX\0", fmt);
}
/// @cond IGNORE

/// @endcond

#ifdef CINEWARE_NAMESPACE_ENABLE
CINEWARE_NAMESPACE_END
#endif
#endif
