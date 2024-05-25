#if 1
#ifdef __API_INTERN__
#else
#endif
#ifdef CINEWARE_NAMESPACE_ENABLE
CINEWARE_NAMESPACE_BEGIN
#endif
namespace enum47
{
	enum class STEREOTYPE
	{
		REGULAR	=	0,
		STREAM		= 1,
		COMBINED	= 2
	} ;
	static const maxon::UInt64 STEREOTYPE_values[] = {maxon::UInt64(enum47::STEREOTYPE::REGULAR), maxon::UInt64(enum47::STEREOTYPE::STREAM), maxon::UInt64(enum47::STEREOTYPE::COMBINED)};
	static const maxon::EnumInfo STEREOTYPE_info{"STEREOTYPE", SIZEOF(STEREOTYPE), false, "REGULAR\0STREAM\0COMBINED\0", STEREOTYPE_values, std::extent<decltype(STEREOTYPE_values)>::value};
}
const maxon::EnumInfo& PrivateGetEnumInfo_STEREOTYPE47(){ return enum47::STEREOTYPE_info; }
namespace enum54
{
	enum class PVFRAME_FINISH
	{
		DESTROY_NODE						= 0,
		KEEP_NODE_AND_COPYBMP		= 1,
		KEEP_NODE_AND_USEBMP		= 2
	} ;
	static const maxon::UInt64 PVFRAME_FINISH_values[] = {maxon::UInt64(enum54::PVFRAME_FINISH::DESTROY_NODE), maxon::UInt64(enum54::PVFRAME_FINISH::KEEP_NODE_AND_COPYBMP), maxon::UInt64(enum54::PVFRAME_FINISH::KEEP_NODE_AND_USEBMP)};
	static const maxon::EnumInfo PVFRAME_FINISH_info{"PVFRAME_FINISH", SIZEOF(PVFRAME_FINISH), false, "DESTROY_NODE\0KEEP_NODE_AND_COPYBMP\0KEEP_NODE_AND_USEBMP\0", PVFRAME_FINISH_values, std::extent<decltype(PVFRAME_FINISH_values)>::value};
}
const maxon::EnumInfo& PrivateGetEnumInfo_PVFRAME_FINISH54(){ return enum54::PVFRAME_FINISH_info; }
#ifdef CINEWARE_NAMESPACE_ENABLE
CINEWARE_NAMESPACE_END
#endif
#endif
