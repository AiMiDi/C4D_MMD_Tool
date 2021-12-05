#if 1
#ifdef CINEWARE_NAMESPACE_ENABLE
CINEWARE_NAMESPACE_BEGIN
#endif
namespace enum24 { enum class VERTEXCOLOR_DISPLAYMODE
{
	NONE = 0,
	COLOR,
	ALPHA
} ; }
maxon::String PrivateToString_VERTEXCOLOR_DISPLAYMODE24(std::underlying_type<enum24::VERTEXCOLOR_DISPLAYMODE>::type x, const maxon::FormatStatement* fmt)
{
	const maxon::UInt64 values[] = {(maxon::UInt64) enum24::VERTEXCOLOR_DISPLAYMODE::NONE, (maxon::UInt64) enum24::VERTEXCOLOR_DISPLAYMODE::COLOR, (maxon::UInt64) enum24::VERTEXCOLOR_DISPLAYMODE::ALPHA};
	return maxon::StringInterface::PrivateEnumToString((maxon::UInt64) x, "VERTEXCOLOR_DISPLAYMODE", SIZEOF(x), true, values, "NONE\0COLOR\0ALPHA\0", fmt);
}
#ifdef CINEWARE_NAMESPACE_ENABLE
CINEWARE_NAMESPACE_END
#endif
#endif
