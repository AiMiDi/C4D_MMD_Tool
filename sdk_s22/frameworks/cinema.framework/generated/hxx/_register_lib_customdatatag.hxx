#if 1
#ifdef __API_INTERN__
#else
#endif
namespace enum34 { enum class CUSTOMDATATAG_MODE
{
	VERTEX = 0,
	POLYVERTEX,
} ; }
maxon::String PrivateToString_CUSTOMDATATAG_MODE34(std::underlying_type<enum34::CUSTOMDATATAG_MODE>::type x, const maxon::FormatStatement* fmt)
{
	const maxon::UInt64 values[] = {(maxon::UInt64) enum34::CUSTOMDATATAG_MODE::VERTEX, (maxon::UInt64) enum34::CUSTOMDATATAG_MODE::POLYVERTEX};
	return maxon::StringInterface::PrivateEnumToString((maxon::UInt64) x, "CUSTOMDATATAG_MODE", SIZEOF(x), false, values, "VERTEX\0POLYVERTEX\0", fmt);
}
/// @cond IGNORE

/// @endcond

#endif
