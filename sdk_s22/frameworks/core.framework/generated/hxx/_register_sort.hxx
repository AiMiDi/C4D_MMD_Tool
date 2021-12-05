#if 1
namespace maxon
{
	namespace enum21 { enum class BASESORTFLAGS
	{
		NONE							 = 0,	///< always use constructor/destructor or move operator, never memcpy, memmove or realloc
		MOVEANDCOPYOBJECTS = 1	///< elements are PODs and can be moved and copied using memcpy and moved using memmove
	} ; }
	maxon::String PrivateToString_BASESORTFLAGS21(std::underlying_type<enum21::BASESORTFLAGS>::type x, const maxon::FormatStatement* fmt)
	{
		const maxon::UInt64 values[] = {(maxon::UInt64) enum21::BASESORTFLAGS::NONE, (maxon::UInt64) enum21::BASESORTFLAGS::MOVEANDCOPYOBJECTS};
		return maxon::StringInterface::PrivateEnumToString((maxon::UInt64) x, "BASESORTFLAGS", SIZEOF(x), true, values, "NONE\0MOVEANDCOPYOBJECTS\0", fmt);
	}
}
#endif
