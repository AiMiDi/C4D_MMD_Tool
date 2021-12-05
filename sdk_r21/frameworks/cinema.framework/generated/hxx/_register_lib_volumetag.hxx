#if 1
#ifdef __API_INTERN__
#else
#endif
#ifdef __API_INTERN__
#endif
namespace enum40 { enum class VOLUMECHANNEL
{
	NONE = 0,
	ALBEDO = 1,
	DENSITY = 2,
	EMISSION = 3
} ; }
maxon::String PrivateToString_VOLUMECHANNEL40(std::underlying_type<enum40::VOLUMECHANNEL>::type x, const maxon::FormatStatement* fmt)
{
	const maxon::UInt64 values[] = {(maxon::UInt64) enum40::VOLUMECHANNEL::NONE, (maxon::UInt64) enum40::VOLUMECHANNEL::ALBEDO, (maxon::UInt64) enum40::VOLUMECHANNEL::DENSITY, (maxon::UInt64) enum40::VOLUMECHANNEL::EMISSION};
	return maxon::StringInterface::PrivateEnumToString((maxon::UInt64) x, "VOLUMECHANNEL", SIZEOF(x), false, values, "NONE\0ALBEDO\0DENSITY\0EMISSION\0", fmt);
}
/// @cond IGNORE

/// @endcond

#endif
