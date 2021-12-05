#if 1
#ifdef __API_INTERN__
#else
#endif
#ifdef CINEWARE_NAMESPACE_ENABLE
CINEWARE_NAMESPACE_BEGIN
#endif
namespace enum47 { enum class STEREOTYPE
{
	REGULAR	=	0,
	STREAM		= 1,
	COMBINED	= 2
} ; }
maxon::String PrivateToString_STEREOTYPE47(std::underlying_type<enum47::STEREOTYPE>::type x, const maxon::FormatStatement* fmt)
{
	const maxon::UInt64 values[] = {(maxon::UInt64) enum47::STEREOTYPE::REGULAR, (maxon::UInt64) enum47::STEREOTYPE::STREAM, (maxon::UInt64) enum47::STEREOTYPE::COMBINED};
	return maxon::StringInterface::PrivateEnumToString((maxon::UInt64) x, "STEREOTYPE", SIZEOF(x), false, values, "REGULAR\0STREAM\0COMBINED\0", fmt);
}
namespace enum54 { enum class PVFRAME_FINISH
{
	DESTROY_NODE						= 0,
	KEEP_NODE_AND_COPYBMP		= 1,
	KEEP_NODE_AND_USEBMP		= 2
} ; }
maxon::String PrivateToString_PVFRAME_FINISH54(std::underlying_type<enum54::PVFRAME_FINISH>::type x, const maxon::FormatStatement* fmt)
{
	const maxon::UInt64 values[] = {(maxon::UInt64) enum54::PVFRAME_FINISH::DESTROY_NODE, (maxon::UInt64) enum54::PVFRAME_FINISH::KEEP_NODE_AND_COPYBMP, (maxon::UInt64) enum54::PVFRAME_FINISH::KEEP_NODE_AND_USEBMP};
	return maxon::StringInterface::PrivateEnumToString((maxon::UInt64) x, "PVFRAME_FINISH", SIZEOF(x), false, values, "DESTROY_NODE\0KEEP_NODE_AND_COPYBMP\0KEEP_NODE_AND_USEBMP\0", fmt);
}
#ifdef CINEWARE_NAMESPACE_ENABLE
CINEWARE_NAMESPACE_END
#endif
#endif
