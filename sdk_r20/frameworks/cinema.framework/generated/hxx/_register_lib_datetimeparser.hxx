#if 1
#ifdef __API_INTERN__
#else
#endif
namespace enum31 { enum class DATETIMEPARSERMODE
{
	DATE,			///< Date.
	TIME				///< Time
} ; }
maxon::String PrivateToString_DATETIMEPARSERMODE31(std::underlying_type<enum31::DATETIMEPARSERMODE>::type x, const maxon::FormatStatement* fmt)
{
	const maxon::UInt64 values[] = {(maxon::UInt64) enum31::DATETIMEPARSERMODE::DATE, (maxon::UInt64) enum31::DATETIMEPARSERMODE::TIME};
	return maxon::StringInterface::PrivateEnumToString((maxon::UInt64) x, "DATETIMEPARSERMODE", SIZEOF(x), false, values, "DATE\0TIME\0", fmt);
}
/// @cond IGNORE

/// @endcond

#endif
