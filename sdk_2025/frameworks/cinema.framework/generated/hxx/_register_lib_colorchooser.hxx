#if 1
namespace cinema
{
	namespace enum33
	{
		enum class SWATCH_CATEGORY
		{
			GLOBAL = 0,
			DOCUMENT = 1
		} ;
		static const maxon::UInt64 SWATCH_CATEGORY_values[] = {maxon::UInt64(enum33::SWATCH_CATEGORY::GLOBAL), maxon::UInt64(enum33::SWATCH_CATEGORY::DOCUMENT)};
		static const maxon::EnumInfo SWATCH_CATEGORY_info{"SWATCH_CATEGORY", SIZEOF(SWATCH_CATEGORY), false, "GLOBAL\0DOCUMENT\0", SWATCH_CATEGORY_values, std::extent<decltype(SWATCH_CATEGORY_values)>::value};
	}
	const maxon::EnumInfo& PrivateGetEnumInfo_SWATCH_CATEGORY33(){ return enum33::SWATCH_CATEGORY_info; }
/// @cond IGNORE

/// @endcond

}
#endif
