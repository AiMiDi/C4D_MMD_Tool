#if 1
namespace cinema
{
	namespace enum152
	{
		enum class VIEWHUD_FLAG
		{
			NOUPDATE = (1 << 20),	// private
			////////////////////////////////////////////////////////////
			NONE = 0
		} ;
		static const maxon::UInt64 VIEWHUD_FLAG_values[] = {maxon::UInt64(enum152::VIEWHUD_FLAG::NOUPDATE), maxon::UInt64(enum152::VIEWHUD_FLAG::NONE)};
		static const maxon::EnumInfo VIEWHUD_FLAG_info{"VIEWHUD_FLAG", SIZEOF(VIEWHUD_FLAG), true, "NOUPDATE\0NONE\0", VIEWHUD_FLAG_values, std::extent<decltype(VIEWHUD_FLAG_values)>::value};
	}
	const maxon::EnumInfo& PrivateGetEnumInfo_VIEWHUD_FLAG152(){ return enum152::VIEWHUD_FLAG_info; }
}
#endif
