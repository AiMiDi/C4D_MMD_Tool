#if 1
#ifdef USE_API_MAXON
#else
#endif
#ifdef CINEWARE_NAMESPACE_ENABLE
CINEWARE_NAMESPACE_BEGIN
#endif
namespace enum50
{
	enum class FIELDLIST_FLAGS
	{
		NONE											= 0,					///< No flags
		CLAMPOUTPUT								= (1 << 0),		///< Clamp the output values from the FieldList
		ENABLEDIRECTIONBYDEFAULT	= (1 << 4),		///< Have direction enabled by default on new layers
		ENABLECOLORBYDEFAULT			= (1 << 5),		///< Have color enabled by default on new layers
		DISABLEVALUEBYDEFAULT			= (1 << 6),		///< Disable the value channel by default on new layers
		SIMPLEGUI									= (1 << 7),		///< Use a simplified GUI, this is only possible if there is only a single standard fieldlayer in the datatype
		ENABLEROTATIONBYDEFAULT		= (1 << 8)		///< Have direction enabled by default on new layers
	} ;
	static const maxon::UInt64 FIELDLIST_FLAGS_values[] = {maxon::UInt64(enum50::FIELDLIST_FLAGS::NONE), maxon::UInt64(enum50::FIELDLIST_FLAGS::CLAMPOUTPUT), maxon::UInt64(enum50::FIELDLIST_FLAGS::ENABLEDIRECTIONBYDEFAULT), maxon::UInt64(enum50::FIELDLIST_FLAGS::ENABLECOLORBYDEFAULT), maxon::UInt64(enum50::FIELDLIST_FLAGS::DISABLEVALUEBYDEFAULT), maxon::UInt64(enum50::FIELDLIST_FLAGS::SIMPLEGUI), maxon::UInt64(enum50::FIELDLIST_FLAGS::ENABLEROTATIONBYDEFAULT)};
	static const maxon::EnumInfo FIELDLIST_FLAGS_info{"FIELDLIST_FLAGS", SIZEOF(FIELDLIST_FLAGS), true, "NONE\0CLAMPOUTPUT\0ENABLEDIRECTIONBYDEFAULT\0ENABLECOLORBYDEFAULT\0DISABLEVALUEBYDEFAULT\0SIMPLEGUI\0ENABLEROTATIONBYDEFAULT\0", FIELDLIST_FLAGS_values, std::extent<decltype(FIELDLIST_FLAGS_values)>::value};
}
const maxon::EnumInfo& PrivateGetEnumInfo_FIELDLIST_FLAGS50(){ return enum50::FIELDLIST_FLAGS_info; }
/// @cond IGNORE

#ifndef INT_CUSTOMDATATYPE_FIELD_H__
#else
#endif
/// @endcond

#ifdef CINEWARE_NAMESPACE_ENABLE
CINEWARE_NAMESPACE_END
#endif
#endif
