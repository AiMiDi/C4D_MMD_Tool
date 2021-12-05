#if 1
namespace enum25 { enum class ICONFLAG
{
	NONE				= 0,						///< None.
	COPY				= (1 << 0),			///< Copies the bitmap instead of storing a pointer.
	OVERWRITE		= (1 << 1),			///< If this is specified and an icon is already present in the library under this ID it will be overwritten, otherwise the existing one will stay.
	DOUBLESIZE	= (1 << 2)			///< Doubles icon size.
} ; }
maxon::String PrivateToString_ICONFLAG25(std::underlying_type<enum25::ICONFLAG>::type x, const maxon::FormatStatement* fmt)
{
	const maxon::UInt64 values[] = {(maxon::UInt64) enum25::ICONFLAG::NONE, (maxon::UInt64) enum25::ICONFLAG::COPY, (maxon::UInt64) enum25::ICONFLAG::OVERWRITE, (maxon::UInt64) enum25::ICONFLAG::DOUBLESIZE};
	return maxon::StringInterface::PrivateEnumToString((maxon::UInt64) x, "ICONFLAG", SIZEOF(x), true, values, "NONE\0COPY\0OVERWRITE\0DOUBLESIZE\0", fmt);
}
/// @cond IGNORE

/// @endcond

#endif
