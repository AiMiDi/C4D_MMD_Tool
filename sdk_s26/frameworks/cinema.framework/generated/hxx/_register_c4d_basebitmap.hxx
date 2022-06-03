#if 1
#ifdef __API_INTERN__
#else
#endif
#ifdef CINEWARE_NAMESPACE_ENABLE
CINEWARE_NAMESPACE_BEGIN
#endif
namespace enum132
{
	enum class BITMAP_UPDATEREGION
	{
		X1				= 1,			///< ::Int32.
		Y1				= 2,			///< ::Int32.
		X2				= 3,			///< ::Int32.
		Y2				= 4,			///< ::Int32.
		TYPE			= 5,			///< ::Int32.
		COLOR			= 6,			///< ::Vector.
		PREPARE		= 7				///< ::Bool.
	} ;
	static const maxon::UInt64 BITMAP_UPDATEREGION_values[] = {maxon::UInt64(enum132::BITMAP_UPDATEREGION::X1), maxon::UInt64(enum132::BITMAP_UPDATEREGION::Y1), maxon::UInt64(enum132::BITMAP_UPDATEREGION::X2), maxon::UInt64(enum132::BITMAP_UPDATEREGION::Y2), maxon::UInt64(enum132::BITMAP_UPDATEREGION::TYPE), maxon::UInt64(enum132::BITMAP_UPDATEREGION::COLOR), maxon::UInt64(enum132::BITMAP_UPDATEREGION::PREPARE)};
	static const maxon::EnumInfo BITMAP_UPDATEREGION_info{"BITMAP_UPDATEREGION", SIZEOF(BITMAP_UPDATEREGION), false, "X1\0Y1\0X2\0Y2\0TYPE\0COLOR\0PREPARE\0", BITMAP_UPDATEREGION_values, std::extent<decltype(BITMAP_UPDATEREGION_values)>::value};
}
const maxon::EnumInfo& PrivateGetEnumInfo_BITMAP_UPDATEREGION132(){ return enum132::BITMAP_UPDATEREGION_info; }
#ifndef __API_INTERN__
#endif
#ifdef CINEWARE_NAMESPACE_ENABLE
CINEWARE_NAMESPACE_END
#endif
#endif
