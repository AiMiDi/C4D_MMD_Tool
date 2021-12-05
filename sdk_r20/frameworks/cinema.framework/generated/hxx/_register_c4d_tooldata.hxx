#if 1
namespace enum31 { enum class VERTEXCOLOR_DISPLAYMODE
{
	NONE = 0,
	COLOR,
	ALPHA
} ; }
maxon::String PrivateToString_VERTEXCOLOR_DISPLAYMODE31(std::underlying_type<enum31::VERTEXCOLOR_DISPLAYMODE>::type x, const maxon::FormatStatement* fmt)
{
	const maxon::UInt64 values[] = {(maxon::UInt64) enum31::VERTEXCOLOR_DISPLAYMODE::NONE, (maxon::UInt64) enum31::VERTEXCOLOR_DISPLAYMODE::COLOR, (maxon::UInt64) enum31::VERTEXCOLOR_DISPLAYMODE::ALPHA};
	return maxon::StringInterface::PrivateEnumToString((maxon::UInt64) x, "VERTEXCOLOR_DISPLAYMODE", SIZEOF(x), true, values, "NONE\0COLOR\0ALPHA\0", fmt);
}
#endif
