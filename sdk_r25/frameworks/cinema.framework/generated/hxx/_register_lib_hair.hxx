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
namespace enum1504
{
	enum class HAIR_MSG_DATA_FLAG
	{
		TEXTURETAG	= (1 << 0),
	
		NONE = 0
	} ;
	static const maxon::UInt64 HAIR_MSG_DATA_FLAG_values[] = {maxon::UInt64(enum1504::HAIR_MSG_DATA_FLAG::TEXTURETAG), maxon::UInt64(enum1504::HAIR_MSG_DATA_FLAG::NONE)};
	static const maxon::EnumInfo HAIR_MSG_DATA_FLAG_info{"HAIR_MSG_DATA_FLAG", SIZEOF(HAIR_MSG_DATA_FLAG), true, "TEXTURETAG\0NONE\0", HAIR_MSG_DATA_FLAG_values, std::extent<decltype(HAIR_MSG_DATA_FLAG_values)>::value};
}
const maxon::EnumInfo& PrivateGetEnumInfo_HAIR_MSG_DATA_FLAG1504(){ return enum1504::HAIR_MSG_DATA_FLAG_info; }
namespace enum1520
{
	enum class HAIR_MSG_DATA_TYPE
	{
		GETMATERIAL		= 1,
		ADDOBJECT			= 2,
		INIT					= 3,
		INITRENDER		= 4,
		FREERENDER		= 5,
	
		NONE					= 0
	} ;
	static const maxon::UInt64 HAIR_MSG_DATA_TYPE_values[] = {maxon::UInt64(enum1520::HAIR_MSG_DATA_TYPE::GETMATERIAL), maxon::UInt64(enum1520::HAIR_MSG_DATA_TYPE::ADDOBJECT), maxon::UInt64(enum1520::HAIR_MSG_DATA_TYPE::INIT), maxon::UInt64(enum1520::HAIR_MSG_DATA_TYPE::INITRENDER), maxon::UInt64(enum1520::HAIR_MSG_DATA_TYPE::FREERENDER), maxon::UInt64(enum1520::HAIR_MSG_DATA_TYPE::NONE)};
	static const maxon::EnumInfo HAIR_MSG_DATA_TYPE_info{"HAIR_MSG_DATA_TYPE", SIZEOF(HAIR_MSG_DATA_TYPE), false, "GETMATERIAL\0ADDOBJECT\0INIT\0INITRENDER\0FREERENDER\0NONE\0", HAIR_MSG_DATA_TYPE_values, std::extent<decltype(HAIR_MSG_DATA_TYPE_values)>::value};
}
const maxon::EnumInfo& PrivateGetEnumInfo_HAIR_MSG_DATA_TYPE1520(){ return enum1520::HAIR_MSG_DATA_TYPE_info; }
/// @cond IGNORE

/// @endcond

#ifdef CINEWARE_NAMESPACE_ENABLE
CINEWARE_NAMESPACE_END
#endif
#endif
