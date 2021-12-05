#if 1
namespace maxon
{
	namespace enum21
	{
		enum class BASEARRAYFLAGS
		{
			NONE								= 0,						///< Use constructor/destructor or move operator unless the type is trivially copyable using memcpy, memmove or realloc.
			MOVEANDCOPYOBJECTS	= (1 << 0)			///< Elements are PODs and can be copied using memcpy and moved using memmove/realloc (for Resize, Insert, Erase, Append etc.). Overrides the setting of std::is_trivially_copyable<T>
		} ;
		static const maxon::UInt64 BASEARRAYFLAGS_values[] = {maxon::UInt64(enum21::BASEARRAYFLAGS::NONE), maxon::UInt64(enum21::BASEARRAYFLAGS::MOVEANDCOPYOBJECTS)};
		static const maxon::EnumInfo BASEARRAYFLAGS_info{"BASEARRAYFLAGS", SIZEOF(BASEARRAYFLAGS), true, "NONE\0MOVEANDCOPYOBJECTS\0", BASEARRAYFLAGS_values, std::extent<decltype(BASEARRAYFLAGS_values)>::value};
	}
	const maxon::EnumInfo& PrivateGetEnumInfo_BASEARRAYFLAGS21(){ return enum21::BASEARRAYFLAGS_info; }
/// @cond INTERNAL

/// @endcond

}
#endif
