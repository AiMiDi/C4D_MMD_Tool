#if 1
namespace maxon
{
	namespace enum21
	{
		enum class BASESORTFLAGS
		{
			NONE							 = 0,	///< always use constructor/destructor or move operator, never memcpy, memmove or realloc
			MOVEANDCOPYOBJECTS = 1	///< elements are PODs and can be moved and copied using memcpy and moved using memmove
		} ;
		static const maxon::UInt64 BASESORTFLAGS_values[] = {maxon::UInt64(enum21::BASESORTFLAGS::NONE), maxon::UInt64(enum21::BASESORTFLAGS::MOVEANDCOPYOBJECTS)};
		static const maxon::EnumInfo BASESORTFLAGS_info{"BASESORTFLAGS", SIZEOF(BASESORTFLAGS), true, "NONE\0MOVEANDCOPYOBJECTS\0", BASESORTFLAGS_values, std::extent<decltype(BASESORTFLAGS_values)>::value};
	}
	const maxon::EnumInfo& PrivateGetEnumInfo_BASESORTFLAGS21(){ return enum21::BASESORTFLAGS_info; }
}
#endif
