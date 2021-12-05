#if 1
namespace maxon
{
	namespace enum194 { enum class BURSTTRIE_SORT
	{
		NONE,						///< Bucket entries won't be sorted at all. If a correct ordering of the entries isn't needed, this is generally the fastest option.
		LINEAR_SEARCH,	///< Bucket entries will be sorted according to their keys. But for searching, they will be scanned in linear order nevertheless. Given small bucket sizes, this is typically faster than a binary search.
		BINARY_SEARCH,	///< Bucket entries will be sorted according to their keys, and lookup will be done with a binary search. This will be faster than a linear search only for large bucket sizes which in general are not recommended.
	} ; }
	maxon::String PrivateToString_BURSTTRIE_SORT194(std::underlying_type<enum194::BURSTTRIE_SORT>::type x, const maxon::FormatStatement* fmt)
	{
		const maxon::UInt64 values[] = {(maxon::UInt64) enum194::BURSTTRIE_SORT::NONE, (maxon::UInt64) enum194::BURSTTRIE_SORT::LINEAR_SEARCH, (maxon::UInt64) enum194::BURSTTRIE_SORT::BINARY_SEARCH};
		return maxon::StringInterface::PrivateEnumToString((maxon::UInt64) x, "BURSTTRIE_SORT", SIZEOF(x), false, values, "NONE\0LINEAR_SEARCH\0BINARY_SEARCH\0", fmt);
	}
}
#endif
