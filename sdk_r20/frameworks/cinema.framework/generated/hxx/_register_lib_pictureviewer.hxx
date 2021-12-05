#if 1
#ifdef __API_INTERN__
#else
#endif
namespace enum50 { enum class STEREOTYPE
{
	REGULAR	=	0,
	STREAM		= 1,
	COMBINED	= 2
} ; }
maxon::String PrivateToString_STEREOTYPE50(std::underlying_type<enum50::STEREOTYPE>::type x, const maxon::FormatStatement* fmt)
{
	const maxon::UInt64 values[] = {(maxon::UInt64) enum50::STEREOTYPE::REGULAR, (maxon::UInt64) enum50::STEREOTYPE::STREAM, (maxon::UInt64) enum50::STEREOTYPE::COMBINED};
	return maxon::StringInterface::PrivateEnumToString((maxon::UInt64) x, "STEREOTYPE", SIZEOF(x), false, values, "REGULAR\0STREAM\0COMBINED\0", fmt);
}
namespace enum57 { enum class PVFRAME_FINISH
{
	DESTROY_NODE						= 0,
	KEEP_NODE_AND_COPYBMP		= 1,
	KEEP_NODE_AND_USEBMP		= 2
} ; }
maxon::String PrivateToString_PVFRAME_FINISH57(std::underlying_type<enum57::PVFRAME_FINISH>::type x, const maxon::FormatStatement* fmt)
{
	const maxon::UInt64 values[] = {(maxon::UInt64) enum57::PVFRAME_FINISH::DESTROY_NODE, (maxon::UInt64) enum57::PVFRAME_FINISH::KEEP_NODE_AND_COPYBMP, (maxon::UInt64) enum57::PVFRAME_FINISH::KEEP_NODE_AND_USEBMP};
	return maxon::StringInterface::PrivateEnumToString((maxon::UInt64) x, "PVFRAME_FINISH", SIZEOF(x), false, values, "DESTROY_NODE\0KEEP_NODE_AND_COPYBMP\0KEEP_NODE_AND_USEBMP\0", fmt);
}
#endif
