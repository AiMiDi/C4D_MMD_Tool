#if 1
namespace enum32 { enum class REGPARSEMODE
{
	MATCH = 1,			///< Full match.
	CONTAINS,				///< Partial match.
	STARTS,					///< Match starting at the beginning.
	ENDS						///< Match finishing at the end.
} ; }
maxon::String PrivateToString_REGPARSEMODE32(std::underlying_type<enum32::REGPARSEMODE>::type x, const maxon::FormatStatement* fmt)
{
	const maxon::UInt64 values[] = {(maxon::UInt64) enum32::REGPARSEMODE::MATCH, (maxon::UInt64) enum32::REGPARSEMODE::CONTAINS, (maxon::UInt64) enum32::REGPARSEMODE::STARTS, (maxon::UInt64) enum32::REGPARSEMODE::ENDS};
	return maxon::StringInterface::PrivateEnumToString((maxon::UInt64) x, "REGPARSEMODE", SIZEOF(x), false, values, "MATCH\0CONTAINS\0STARTS\0ENDS\0", fmt);
}
/// @cond IGNORE

/// @endcond

#endif
