#if 1
namespace cinema
{
	namespace enum23
	{
		enum class VERTEXCOLOR_DISPLAYMODE
		{
			NONE = 0,
			COLOR,
			ALPHA
		} ;
		static const maxon::UInt64 VERTEXCOLOR_DISPLAYMODE_values[] = {maxon::UInt64(enum23::VERTEXCOLOR_DISPLAYMODE::NONE), maxon::UInt64(enum23::VERTEXCOLOR_DISPLAYMODE::COLOR), maxon::UInt64(enum23::VERTEXCOLOR_DISPLAYMODE::ALPHA)};
		static const maxon::EnumInfo VERTEXCOLOR_DISPLAYMODE_info{"VERTEXCOLOR_DISPLAYMODE", SIZEOF(VERTEXCOLOR_DISPLAYMODE), true, "NONE\0COLOR\0ALPHA\0", VERTEXCOLOR_DISPLAYMODE_values, std::extent<decltype(VERTEXCOLOR_DISPLAYMODE_values)>::value};
	}
	const maxon::EnumInfo& PrivateGetEnumInfo_VERTEXCOLOR_DISPLAYMODE23(){ return enum23::VERTEXCOLOR_DISPLAYMODE_info; }
}
#endif
