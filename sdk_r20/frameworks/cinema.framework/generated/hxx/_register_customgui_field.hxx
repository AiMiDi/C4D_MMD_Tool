#if 1
#ifdef USE_API_MAXON
#else
#endif
namespace enum43 { enum class FIELDLIST_FLAGS
{
	NONE											= 0,					///< No flags
	CLAMPOUTPUT								= (1 << 0),		///< Clamp the output values from the FieldList
	ENABLEDIRECTIONBYDEFAULT	= (1 << 4),		///< Have direction enabled by default on new layers
	ENABLECOLORBYDEFAULT			= (1 << 5),		///< Have color enabled by default on new layers
	DISABLEVALUEBYDEFAULT			= (1 << 6),		///< Disable the value channel by default on new layers
	SIMPLEGUI									= (1 << 7),		///< Use a simplified GUI, this is only possible if there is only a single standard fieldlayer in the datatype
	ENABLEROTATIONBYDEFAULT		= (1 << 8)		///< Have direction enabled by default on new layers
} ; }
maxon::String PrivateToString_FIELDLIST_FLAGS43(std::underlying_type<enum43::FIELDLIST_FLAGS>::type x, const maxon::FormatStatement* fmt)
{
	const maxon::UInt64 values[] = {(maxon::UInt64) enum43::FIELDLIST_FLAGS::NONE, (maxon::UInt64) enum43::FIELDLIST_FLAGS::CLAMPOUTPUT, (maxon::UInt64) enum43::FIELDLIST_FLAGS::ENABLEDIRECTIONBYDEFAULT, (maxon::UInt64) enum43::FIELDLIST_FLAGS::ENABLECOLORBYDEFAULT, (maxon::UInt64) enum43::FIELDLIST_FLAGS::DISABLEVALUEBYDEFAULT, (maxon::UInt64) enum43::FIELDLIST_FLAGS::SIMPLEGUI, (maxon::UInt64) enum43::FIELDLIST_FLAGS::ENABLEROTATIONBYDEFAULT};
	return maxon::StringInterface::PrivateEnumToString((maxon::UInt64) x, "FIELDLIST_FLAGS", SIZEOF(x), true, values, "NONE\0CLAMPOUTPUT\0ENABLEDIRECTIONBYDEFAULT\0ENABLECOLORBYDEFAULT\0DISABLEVALUEBYDEFAULT\0SIMPLEGUI\0ENABLEROTATIONBYDEFAULT\0", fmt);
}
/// @cond IGNORE

#if 1
#else
#endif
/// @endcond

#endif
