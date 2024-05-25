#if 1
#ifdef __API_INTERN__
#else
#endif
#ifdef CINEWARE_NAMESPACE_ENABLE
CINEWARE_NAMESPACE_BEGIN
#endif
namespace enum35
{
	enum class DATETIMEPARSERMODE
	{
		DATE,			///< Date.
		TIME				///< Time
	} ;
	static const maxon::UInt64 DATETIMEPARSERMODE_values[] = {maxon::UInt64(enum35::DATETIMEPARSERMODE::DATE), maxon::UInt64(enum35::DATETIMEPARSERMODE::TIME)};
	static const maxon::EnumInfo DATETIMEPARSERMODE_info{"DATETIMEPARSERMODE", SIZEOF(DATETIMEPARSERMODE), false, "DATE\0TIME\0", DATETIMEPARSERMODE_values, std::extent<decltype(DATETIMEPARSERMODE_values)>::value};
}
const maxon::EnumInfo& PrivateGetEnumInfo_DATETIMEPARSERMODE35(){ return enum35::DATETIMEPARSERMODE_info; }
/// @cond IGNORE

/// @endcond

#ifdef CINEWARE_NAMESPACE_ENABLE
CINEWARE_NAMESPACE_END
#endif
#endif
