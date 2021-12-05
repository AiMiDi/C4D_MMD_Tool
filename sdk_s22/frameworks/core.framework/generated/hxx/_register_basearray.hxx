#if 1
namespace maxon
{
	namespace enum21 { enum class BASEARRAYFLAGS
	{
		NONE								= 0,						///< Use constructor/destructor or move operator unless the type is trivially copyable using memcpy, memmove or realloc.
		MOVEANDCOPYOBJECTS	= (1 << 0)			///< Elements are PODs and can be copied using memcpy and moved using memmove/realloc (for Resize, Insert, Erase, Append etc.). Overrides the setting of std::is_trivially_copyable<T>
	} ; }
	maxon::String PrivateToString_BASEARRAYFLAGS21(std::underlying_type<enum21::BASEARRAYFLAGS>::type x, const maxon::FormatStatement* fmt)
	{
		const maxon::UInt64 values[] = {(maxon::UInt64) enum21::BASEARRAYFLAGS::NONE, (maxon::UInt64) enum21::BASEARRAYFLAGS::MOVEANDCOPYOBJECTS};
		return maxon::StringInterface::PrivateEnumToString((maxon::UInt64) x, "BASEARRAYFLAGS", SIZEOF(x), true, values, "NONE\0MOVEANDCOPYOBJECTS\0", fmt);
	}
/// @cond INTERNAL

/// @endcond

}
#endif
