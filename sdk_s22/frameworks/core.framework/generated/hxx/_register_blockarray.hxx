#if 1
namespace maxon
{
	namespace enum21 { enum class BLOCKARRAYFLAGS
	{
		NONE								= 0,				///< Use constructor/destructor or move operator unless the type is trivially copyable using memcpy, memmove or realloc.
		MOVEANDCOPYOBJECTS	= (1 << 0),	///< Elements are PODs and can be copied using memcpy and moved using memmove/realloc (for Resize, Insert, Erase, Append etc.). Overrides the setting of std::is_trivially_copyable<T>.
		NOINSERTERASE				= (1 << 1),	///< Do not support Insert() and Erase() (will make the subscript operator faster).
		GROW_SLOWLY					= (1 << 2)	///< The first block will increase its size gradually (and might move memory) until it reaches 1 << BLOCK_SIZE_EXPONENT.
	} ; }
	maxon::String PrivateToString_BLOCKARRAYFLAGS21(std::underlying_type<enum21::BLOCKARRAYFLAGS>::type x, const maxon::FormatStatement* fmt)
	{
		const maxon::UInt64 values[] = {(maxon::UInt64) enum21::BLOCKARRAYFLAGS::NONE, (maxon::UInt64) enum21::BLOCKARRAYFLAGS::MOVEANDCOPYOBJECTS, (maxon::UInt64) enum21::BLOCKARRAYFLAGS::NOINSERTERASE, (maxon::UInt64) enum21::BLOCKARRAYFLAGS::GROW_SLOWLY};
		return maxon::StringInterface::PrivateEnumToString((maxon::UInt64) x, "BLOCKARRAYFLAGS", SIZEOF(x), true, values, "NONE\0MOVEANDCOPYOBJECTS\0NOINSERTERASE\0GROW_SLOWLY\0", fmt);
	}
}
#endif
