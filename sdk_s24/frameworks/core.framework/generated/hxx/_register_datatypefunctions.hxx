#if 1
namespace maxon
{
#ifndef DOXYGEN
#endif
	namespace enum134
	{
		enum class DATATYPEMODE
		{
			SMALLISPOD,
			SMALL,
			BIG,
		} ;
		static const maxon::UInt64 DATATYPEMODE_values[] = {maxon::UInt64(enum134::DATATYPEMODE::SMALLISPOD), maxon::UInt64(enum134::DATATYPEMODE::SMALL), maxon::UInt64(enum134::DATATYPEMODE::BIG)};
		static const maxon::EnumInfo DATATYPEMODE_info{"DATATYPEMODE", SIZEOF(DATATYPEMODE), false, "SMALLISPOD\0SMALL\0BIG\0", DATATYPEMODE_values, std::extent<decltype(DATATYPEMODE_values)>::value};
	}
	const maxon::EnumInfo& PrivateGetEnumInfo_DATATYPEMODE134(){ return enum134::DATATYPEMODE_info; }
}
#endif
