#if 1
#ifdef CINEWARE_NAMESPACE_ENABLE
CINEWARE_NAMESPACE_BEGIN
#endif
namespace enum29
{
	enum class ICONFLAG
	{
		NONE				= 0,						///< None.
		COPY				= (1 << 0),			///< Copies the bitmap instead of storing a pointer.
		OVERWRITE		= (1 << 1),			///< If this is specified and an icon is already present in the library under this ID it will be overwritten, otherwise the existing one will stay.
		DOUBLESIZE	= (1 << 2)			///< Doubles icon size.
	} ;
	static const maxon::UInt64 ICONFLAG_values[] = {maxon::UInt64(enum29::ICONFLAG::NONE), maxon::UInt64(enum29::ICONFLAG::COPY), maxon::UInt64(enum29::ICONFLAG::OVERWRITE), maxon::UInt64(enum29::ICONFLAG::DOUBLESIZE)};
	static const maxon::EnumInfo ICONFLAG_info{"ICONFLAG", SIZEOF(ICONFLAG), true, "NONE\0COPY\0OVERWRITE\0DOUBLESIZE\0", ICONFLAG_values, std::extent<decltype(ICONFLAG_values)>::value};
}
const maxon::EnumInfo& PrivateGetEnumInfo_ICONFLAG29(){ return enum29::ICONFLAG_info; }
/// @cond IGNORE

/// @endcond

#ifdef CINEWARE_NAMESPACE_ENABLE
CINEWARE_NAMESPACE_END
#endif
#endif
