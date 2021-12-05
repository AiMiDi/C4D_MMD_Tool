#if 1
#ifdef __API_INTERN__
#else
#endif
#ifdef CINEWARE_NAMESPACE_ENABLE
CINEWARE_NAMESPACE_BEGIN
#endif
namespace enum35 { enum class DATETIMEPARSERMODE
{
	DATE,			///< Date.
	TIME				///< Time
} ; }
maxon::String PrivateToString_DATETIMEPARSERMODE35(std::underlying_type<enum35::DATETIMEPARSERMODE>::type x, const maxon::FormatStatement* fmt)
{
	const maxon::UInt64 values[] = {(maxon::UInt64) enum35::DATETIMEPARSERMODE::DATE, (maxon::UInt64) enum35::DATETIMEPARSERMODE::TIME};
	return maxon::StringInterface::PrivateEnumToString((maxon::UInt64) x, "DATETIMEPARSERMODE", SIZEOF(x), false, values, "DATE\0TIME\0", fmt);
}
/// @cond IGNORE

/// @endcond

#ifdef CINEWARE_NAMESPACE_ENABLE
CINEWARE_NAMESPACE_END
#endif
#endif
