#if 1
#ifdef __API_INTERN__
#else
#endif
namespace enum124 { enum class BITMAP_UPDATEREGION
{
	X1				= 1,			///< ::Int32.
	Y1				= 2,			///< ::Int32.
	X2				= 3,			///< ::Int32.
	Y2				= 4,			///< ::Int32.
	TYPE			= 5,			///< ::Int32.
	COLOR			= 6,			///< ::Vector.
	PREPARE		= 7				///< ::Bool.
} ; }
maxon::String PrivateToString_BITMAP_UPDATEREGION124(std::underlying_type<enum124::BITMAP_UPDATEREGION>::type x, const maxon::FormatStatement* fmt)
{
	const maxon::UInt64 values[] = {(maxon::UInt64) enum124::BITMAP_UPDATEREGION::X1, (maxon::UInt64) enum124::BITMAP_UPDATEREGION::Y1, (maxon::UInt64) enum124::BITMAP_UPDATEREGION::X2, (maxon::UInt64) enum124::BITMAP_UPDATEREGION::Y2, (maxon::UInt64) enum124::BITMAP_UPDATEREGION::TYPE, (maxon::UInt64) enum124::BITMAP_UPDATEREGION::COLOR, (maxon::UInt64) enum124::BITMAP_UPDATEREGION::PREPARE};
	return maxon::StringInterface::PrivateEnumToString((maxon::UInt64) x, "BITMAP_UPDATEREGION", SIZEOF(x), false, values, "X1\0Y1\0X2\0Y2\0TYPE\0COLOR\0PREPARE\0", fmt);
}
#ifndef __API_INTERN__
#endif
#endif
