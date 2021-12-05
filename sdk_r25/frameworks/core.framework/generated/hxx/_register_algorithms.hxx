#if 1
namespace maxon
{
	namespace enum430
	{
		enum class MOVE_MODE
		{
			KEEP_SOURCE,
			DESTRUCT_SOURCE
		} ;
		static const maxon::UInt64 MOVE_MODE_values[] = {maxon::UInt64(enum430::MOVE_MODE::KEEP_SOURCE), maxon::UInt64(enum430::MOVE_MODE::DESTRUCT_SOURCE)};
		static const maxon::EnumInfo MOVE_MODE_info{"MOVE_MODE", SIZEOF(MOVE_MODE), false, "KEEP_SOURCE\0DESTRUCT_SOURCE\0", MOVE_MODE_values, std::extent<decltype(MOVE_MODE_values)>::value};
	}
	const maxon::EnumInfo& PrivateGetEnumInfo_MOVE_MODE430(){ return enum430::MOVE_MODE_info; }
	namespace enum1904
	{
		enum class NO_MATCH_TYPE
		{
			VALUE = 1
		} ;
		static const maxon::UInt64 NO_MATCH_TYPE_values[] = {maxon::UInt64(enum1904::NO_MATCH_TYPE::VALUE)};
		static const maxon::EnumInfo NO_MATCH_TYPE_info{"NO_MATCH_TYPE", SIZEOF(NO_MATCH_TYPE), false, "VALUE\0", NO_MATCH_TYPE_values, std::extent<decltype(NO_MATCH_TYPE_values)>::value};
	}
	const maxon::EnumInfo& PrivateGetEnumInfo_NO_MATCH_TYPE1904(){ return enum1904::NO_MATCH_TYPE_info; }
}
#endif
