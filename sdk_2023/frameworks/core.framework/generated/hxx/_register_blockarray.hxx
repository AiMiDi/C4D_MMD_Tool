#if 1
namespace maxon
{
	namespace enum21
	{
		enum class BLOCKARRAYFLAGS
		{
			NONE								= 0,				///< Use constructor/destructor or move operator unless the type is trivially copyable using memcpy, memmove or realloc.
			MOVEANDCOPYOBJECTS	= (1 << 0),	///< Elements are PODs and can be copied using memcpy and moved using memmove/realloc (for Resize, Insert, Erase, Append etc.). Overrides the setting of std::is_trivially_copyable<T>.
			NOINSERTERASE				= (1 << 1),	///< Do not support Insert() and Erase() (will make the subscript operator faster).
			GROW_SLOWLY					= (1 << 2)	///< The first block will increase its size gradually (and might move memory) until it reaches 1 << BLOCK_SIZE_EXPONENT.
		} ;
		static const maxon::UInt64 BLOCKARRAYFLAGS_values[] = {maxon::UInt64(enum21::BLOCKARRAYFLAGS::NONE), maxon::UInt64(enum21::BLOCKARRAYFLAGS::MOVEANDCOPYOBJECTS), maxon::UInt64(enum21::BLOCKARRAYFLAGS::NOINSERTERASE), maxon::UInt64(enum21::BLOCKARRAYFLAGS::GROW_SLOWLY)};
		static const maxon::EnumInfo BLOCKARRAYFLAGS_info{"BLOCKARRAYFLAGS", SIZEOF(BLOCKARRAYFLAGS), true, "NONE\0MOVEANDCOPYOBJECTS\0NOINSERTERASE\0GROW_SLOWLY\0", BLOCKARRAYFLAGS_values, std::extent<decltype(BLOCKARRAYFLAGS_values)>::value};
	}
	const maxon::EnumInfo& PrivateGetEnumInfo_BLOCKARRAYFLAGS21(){ return enum21::BLOCKARRAYFLAGS_info; }
#ifdef MAXON_COMPILER_MSVC
#endif
#ifdef MAXON_COMPILER_MSVC
#endif
#if 0
#else
#endif
#if 0
#else
#endif
}
#endif
