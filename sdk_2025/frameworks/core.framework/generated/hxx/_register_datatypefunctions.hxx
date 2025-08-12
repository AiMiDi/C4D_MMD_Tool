#if 1
namespace maxon
{
#ifndef DOXYGEN
#endif
	namespace enum174
	{
		enum class DATATYPEMODE
		{
			SMALLISPOD,
			SMALL,
			BIG,
		} ;
		static const maxon::UInt64 DATATYPEMODE_values[] = {maxon::UInt64(enum174::DATATYPEMODE::SMALLISPOD), maxon::UInt64(enum174::DATATYPEMODE::SMALL), maxon::UInt64(enum174::DATATYPEMODE::BIG)};
		static const maxon::EnumInfo DATATYPEMODE_info{"DATATYPEMODE", SIZEOF(DATATYPEMODE), false, "SMALLISPOD\0SMALL\0BIG\0", DATATYPEMODE_values, std::extent<decltype(DATATYPEMODE_values)>::value};
	}
	const maxon::EnumInfo& PrivateGetEnumInfo_DATATYPEMODE174(){ return enum174::DATATYPEMODE_info; }
}
#endif
