#if 1
namespace maxon
{
	namespace enum22
	{
		enum class BLOCKARRAYFLAGS
		{
			NONE								= 0,				///< Use constructor/destructor or move operator unless the type is trivially copyable using memcpy, memmove or realloc.
			MOVEANDCOPYOBJECTS	= (1 << 0),	///< Elements are PODs and can be copied using memcpy and moved using memmove/realloc (for Resize, Insert, Erase, Append etc.). Overrides the setting of std::is_trivially_copyable<T>.
			NOINSERTERASE				= (1 << 1),	///< Do not support Insert() and Erase() (will make the subscript operator faster).
			GROW_SLOWLY					= (1 << 2),	///< The first block will increase its size gradually (and might move memory) until it reaches 1 << BLOCK_SIZE_EXPONENT.
			ZEROINITIALIZE			= (1 << 3)	///< Zero initializes before calling the constructor
		} ;
		static const maxon::UInt64 BLOCKARRAYFLAGS_values[] = {maxon::UInt64(enum22::BLOCKARRAYFLAGS::NONE), maxon::UInt64(enum22::BLOCKARRAYFLAGS::MOVEANDCOPYOBJECTS), maxon::UInt64(enum22::BLOCKARRAYFLAGS::NOINSERTERASE), maxon::UInt64(enum22::BLOCKARRAYFLAGS::GROW_SLOWLY), maxon::UInt64(enum22::BLOCKARRAYFLAGS::ZEROINITIALIZE)};
		static const maxon::EnumInfo BLOCKARRAYFLAGS_info{"BLOCKARRAYFLAGS", SIZEOF(BLOCKARRAYFLAGS), true, "NONE\0MOVEANDCOPYOBJECTS\0NOINSERTERASE\0GROW_SLOWLY\0ZEROINITIALIZE\0", BLOCKARRAYFLAGS_values, std::extent<decltype(BLOCKARRAYFLAGS_values)>::value};
	}
	const maxon::EnumInfo& PrivateGetEnumInfo_BLOCKARRAYFLAGS22(){ return enum22::BLOCKARRAYFLAGS_info; }
#ifdef MAXON_COMPILER_MSVC
#endif
#ifdef MAXON_COMPILER_MSVC
#endif
}
#endif
