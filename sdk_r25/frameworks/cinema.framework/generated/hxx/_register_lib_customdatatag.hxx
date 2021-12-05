#if 1
#ifdef __API_INTERN__
#else
#endif
#ifdef CINEWARE_NAMESPACE_ENABLE
CINEWARE_NAMESPACE_BEGIN
#endif
namespace enum38
{
	enum class CUSTOMDATATAG_MODE
	{
		VERTEX = 0,
		POLYVERTEX,
	} ;
	static const maxon::UInt64 CUSTOMDATATAG_MODE_values[] = {maxon::UInt64(enum38::CUSTOMDATATAG_MODE::VERTEX), maxon::UInt64(enum38::CUSTOMDATATAG_MODE::POLYVERTEX)};
	static const maxon::EnumInfo CUSTOMDATATAG_MODE_info{"CUSTOMDATATAG_MODE", SIZEOF(CUSTOMDATATAG_MODE), false, "VERTEX\0POLYVERTEX\0", CUSTOMDATATAG_MODE_values, std::extent<decltype(CUSTOMDATATAG_MODE_values)>::value};
}
const maxon::EnumInfo& PrivateGetEnumInfo_CUSTOMDATATAG_MODE38(){ return enum38::CUSTOMDATATAG_MODE_info; }
/// @cond IGNORE

/// @endcond

#ifdef CINEWARE_NAMESPACE_ENABLE
CINEWARE_NAMESPACE_END
#endif
#endif
