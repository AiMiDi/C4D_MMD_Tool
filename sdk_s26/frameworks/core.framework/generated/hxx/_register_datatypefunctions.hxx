#if 1
namespace maxon
{
#ifndef DOXYGEN
#endif
	namespace enum137
	{
		enum class DATATYPEMODE
		{
			SMALLISPOD,
			SMALL,
			BIG,
		} ;
		static const maxon::UInt64 DATATYPEMODE_values[] = {maxon::UInt64(enum137::DATATYPEMODE::SMALLISPOD), maxon::UInt64(enum137::DATATYPEMODE::SMALL), maxon::UInt64(enum137::DATATYPEMODE::BIG)};
		static const maxon::EnumInfo DATATYPEMODE_info{"DATATYPEMODE", SIZEOF(DATATYPEMODE), false, "SMALLISPOD\0SMALL\0BIG\0", DATATYPEMODE_values, std::extent<decltype(DATATYPEMODE_values)>::value};
	}
	const maxon::EnumInfo& PrivateGetEnumInfo_DATATYPEMODE137(){ return enum137::DATATYPEMODE_info; }
}
#endif
