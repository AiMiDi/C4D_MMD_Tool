#if 1
namespace maxon
{
	namespace enum22
	{
		enum class HASHMAP_ENTRY_LAYOUT
		{
			HASH_KEY_VALUE,
			KEY_HASH_VALUE,
			HASH_VALUE_KEY,
			HASH_VALUE,
			KEY_VALUE,
			VALUE
		} ;
		static const maxon::UInt64 HASHMAP_ENTRY_LAYOUT_values[] = {maxon::UInt64(enum22::HASHMAP_ENTRY_LAYOUT::HASH_KEY_VALUE), maxon::UInt64(enum22::HASHMAP_ENTRY_LAYOUT::KEY_HASH_VALUE), maxon::UInt64(enum22::HASHMAP_ENTRY_LAYOUT::HASH_VALUE_KEY), maxon::UInt64(enum22::HASHMAP_ENTRY_LAYOUT::HASH_VALUE), maxon::UInt64(enum22::HASHMAP_ENTRY_LAYOUT::KEY_VALUE), maxon::UInt64(enum22::HASHMAP_ENTRY_LAYOUT::VALUE)};
		static const maxon::EnumInfo HASHMAP_ENTRY_LAYOUT_info{"HASHMAP_ENTRY_LAYOUT", SIZEOF(HASHMAP_ENTRY_LAYOUT), false, "HASH_KEY_VALUE\0KEY_HASH_VALUE\0HASH_VALUE_KEY\0HASH_VALUE\0KEY_VALUE\0VALUE\0", HASHMAP_ENTRY_LAYOUT_values, std::extent<decltype(HASHMAP_ENTRY_LAYOUT_values)>::value};
	}
	const maxon::EnumInfo& PrivateGetEnumInfo_HASHMAP_ENTRY_LAYOUT22(){ return enum22::HASHMAP_ENTRY_LAYOUT_info; }
	namespace enum1005
	{
		enum class HASHMAP_MODE
		{
			DEFAULT,										///< The default mode.
			SYNCHRONIZED,								///< Use atomic access to implement a lock-free hash map.
			NO_NONEMPTY_BUCKET_TABLE		///< Don't maintain a table of non-empty buckets. This reduces memory consumption, but makes iterations slower.
		} ;
		static const maxon::UInt64 HASHMAP_MODE_values[] = {maxon::UInt64(enum1005::HASHMAP_MODE::DEFAULT), maxon::UInt64(enum1005::HASHMAP_MODE::SYNCHRONIZED), maxon::UInt64(enum1005::HASHMAP_MODE::NO_NONEMPTY_BUCKET_TABLE)};
		static const maxon::EnumInfo HASHMAP_MODE_info{"HASHMAP_MODE", SIZEOF(HASHMAP_MODE), false, "DEFAULT\0SYNCHRONIZED\0NO_NONEMPTY_BUCKET_TABLE\0", HASHMAP_MODE_values, std::extent<decltype(HASHMAP_MODE_values)>::value};
	}
	const maxon::EnumInfo& PrivateGetEnumInfo_HASHMAP_MODE1005(){ return enum1005::HASHMAP_MODE_info; }
}
#endif
