#if 1
namespace enum30 { enum class SWATCH_CATEGORY
{
	GLOBAL = 0,
	DOCUMENT = 1
} ; }
maxon::String PrivateToString_SWATCH_CATEGORY30(std::underlying_type<enum30::SWATCH_CATEGORY>::type x, const maxon::FormatStatement* fmt)
{
	const maxon::UInt64 values[] = {(maxon::UInt64) enum30::SWATCH_CATEGORY::GLOBAL, (maxon::UInt64) enum30::SWATCH_CATEGORY::DOCUMENT};
	return maxon::StringInterface::PrivateEnumToString((maxon::UInt64) x, "SWATCH_CATEGORY", SIZEOF(x), false, values, "GLOBAL\0DOCUMENT\0", fmt);
}
/// @cond IGNORE

/// @endcond

#endif
