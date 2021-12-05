#if 1
namespace maxon
{
	namespace enum19 { enum class HASHMAP_ENTRY_LAYOUT
	{
		KEY_VALUE,
		KEY_HASH_VALUE,
		VALUE_KEY,
		VALUE
	} ; }
	maxon::String PrivateToString_HASHMAP_ENTRY_LAYOUT19(std::underlying_type<enum19::HASHMAP_ENTRY_LAYOUT>::type x, const maxon::FormatStatement* fmt)
	{
		const maxon::UInt64 values[] = {(maxon::UInt64) enum19::HASHMAP_ENTRY_LAYOUT::KEY_VALUE, (maxon::UInt64) enum19::HASHMAP_ENTRY_LAYOUT::KEY_HASH_VALUE, (maxon::UInt64) enum19::HASHMAP_ENTRY_LAYOUT::VALUE_KEY, (maxon::UInt64) enum19::HASHMAP_ENTRY_LAYOUT::VALUE};
		return maxon::StringInterface::PrivateEnumToString((maxon::UInt64) x, "HASHMAP_ENTRY_LAYOUT", SIZEOF(x), false, values, "KEY_VALUE\0KEY_HASH_VALUE\0VALUE_KEY\0VALUE\0", fmt);
	}
	namespace enum737 { enum class HASHMAP_MODE
	{
		DEFAULT,										///< The default mode.
		SYNCHRONIZED,								///< Use atomic access to implement a lock-free hash map.
		NO_NONEMPTY_BUCKET_TABLE		///< Don't maintain a table of non-empty buckets. This reduces memory consumption, but makes iterations slower.
	} ; }
	maxon::String PrivateToString_HASHMAP_MODE737(std::underlying_type<enum737::HASHMAP_MODE>::type x, const maxon::FormatStatement* fmt)
	{
		const maxon::UInt64 values[] = {(maxon::UInt64) enum737::HASHMAP_MODE::DEFAULT, (maxon::UInt64) enum737::HASHMAP_MODE::SYNCHRONIZED, (maxon::UInt64) enum737::HASHMAP_MODE::NO_NONEMPTY_BUCKET_TABLE};
		return maxon::StringInterface::PrivateEnumToString((maxon::UInt64) x, "HASHMAP_MODE", SIZEOF(x), false, values, "DEFAULT\0SYNCHRONIZED\0NO_NONEMPTY_BUCKET_TABLE\0", fmt);
	}
}
#endif
