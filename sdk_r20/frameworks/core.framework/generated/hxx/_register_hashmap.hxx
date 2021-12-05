#if 1
namespace maxon
{
	namespace enum18 { enum class HASHMAP_ENTRY_LAYOUT
	{
		KEY_VALUE,
		VALUE_KEY,
		VALUE
	} ; }
	maxon::String PrivateToString_HASHMAP_ENTRY_LAYOUT18(std::underlying_type<enum18::HASHMAP_ENTRY_LAYOUT>::type x, const maxon::FormatStatement* fmt)
	{
		const maxon::UInt64 values[] = {(maxon::UInt64) enum18::HASHMAP_ENTRY_LAYOUT::KEY_VALUE, (maxon::UInt64) enum18::HASHMAP_ENTRY_LAYOUT::VALUE_KEY, (maxon::UInt64) enum18::HASHMAP_ENTRY_LAYOUT::VALUE};
		return maxon::StringInterface::PrivateEnumToString((maxon::UInt64) x, "HASHMAP_ENTRY_LAYOUT", SIZEOF(x), false, values, "KEY_VALUE\0VALUE_KEY\0VALUE\0", fmt);
	}
}
#endif
