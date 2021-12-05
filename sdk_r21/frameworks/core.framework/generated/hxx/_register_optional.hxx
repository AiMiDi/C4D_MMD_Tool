#if 1
namespace maxon
{
	namespace enum15 { enum class NO_VALUE_TYPE
	{
		VALUE = 1
	} ; }
	maxon::String PrivateToString_NO_VALUE_TYPE15(std::underlying_type<enum15::NO_VALUE_TYPE>::type x, const maxon::FormatStatement* fmt)
	{
		const maxon::UInt64 values[] = {(maxon::UInt64) enum15::NO_VALUE_TYPE::VALUE};
		return maxon::StringInterface::PrivateEnumToString((maxon::UInt64) x, "NO_VALUE_TYPE", SIZEOF(x), false, values, "VALUE\0", fmt);
	}
#ifdef MAXON_COMPILER_MSVC
#endif
}
#endif
