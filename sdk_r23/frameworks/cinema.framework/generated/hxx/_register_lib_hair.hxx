#if 1
#ifdef __API_INTERN__
#else
#endif
#ifdef CINEWARE_NAMESPACE_ENABLE
CINEWARE_NAMESPACE_BEGIN
#endif
#ifndef __API_INTERN__
#else
#endif
#ifndef __API_INTERN__
#else
#endif
#ifndef __API_INTERN__
#else
#endif
#ifndef __API_INTERN__
#else
#endif
#ifndef __API_INTERN__
#else
#endif
namespace enum1504 { enum class HAIR_MSG_DATA_FLAG
{
	TEXTURETAG	= (1 << 0),

	NONE = 0
} ; }
maxon::String PrivateToString_HAIR_MSG_DATA_FLAG1504(std::underlying_type<enum1504::HAIR_MSG_DATA_FLAG>::type x, const maxon::FormatStatement* fmt)
{
	const maxon::UInt64 values[] = {(maxon::UInt64) enum1504::HAIR_MSG_DATA_FLAG::TEXTURETAG, (maxon::UInt64) enum1504::HAIR_MSG_DATA_FLAG::NONE};
	return maxon::StringInterface::PrivateEnumToString((maxon::UInt64) x, "HAIR_MSG_DATA_FLAG", SIZEOF(x), true, values, "TEXTURETAG\0NONE\0", fmt);
}
namespace enum1520 { enum class HAIR_MSG_DATA_TYPE
{
	GETMATERIAL		= 1,
	ADDOBJECT			= 2,
	INIT					= 3,
	INITRENDER		= 4,
	FREERENDER		= 5,

	NONE					= 0
} ; }
maxon::String PrivateToString_HAIR_MSG_DATA_TYPE1520(std::underlying_type<enum1520::HAIR_MSG_DATA_TYPE>::type x, const maxon::FormatStatement* fmt)
{
	const maxon::UInt64 values[] = {(maxon::UInt64) enum1520::HAIR_MSG_DATA_TYPE::GETMATERIAL, (maxon::UInt64) enum1520::HAIR_MSG_DATA_TYPE::ADDOBJECT, (maxon::UInt64) enum1520::HAIR_MSG_DATA_TYPE::INIT, (maxon::UInt64) enum1520::HAIR_MSG_DATA_TYPE::INITRENDER, (maxon::UInt64) enum1520::HAIR_MSG_DATA_TYPE::FREERENDER, (maxon::UInt64) enum1520::HAIR_MSG_DATA_TYPE::NONE};
	return maxon::StringInterface::PrivateEnumToString((maxon::UInt64) x, "HAIR_MSG_DATA_TYPE", SIZEOF(x), false, values, "GETMATERIAL\0ADDOBJECT\0INIT\0INITRENDER\0FREERENDER\0NONE\0", fmt);
}
/// @cond IGNORE

/// @endcond

#ifdef CINEWARE_NAMESPACE_ENABLE
CINEWARE_NAMESPACE_END
#endif
#endif
