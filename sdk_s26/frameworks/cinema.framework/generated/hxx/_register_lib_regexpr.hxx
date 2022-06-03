#if 1
#ifdef CINEWARE_NAMESPACE_ENABLE
CINEWARE_NAMESPACE_BEGIN
#endif
namespace enum36
{
	enum class REGPARSEMODE
	{
		MATCH = 1,			///< Full match.
		CONTAINS,				///< Partial match.
		STARTS,					///< Match starting at the beginning.
		ENDS						///< Match finishing at the end.
	} ;
	static const maxon::UInt64 REGPARSEMODE_values[] = {maxon::UInt64(enum36::REGPARSEMODE::MATCH), maxon::UInt64(enum36::REGPARSEMODE::CONTAINS), maxon::UInt64(enum36::REGPARSEMODE::STARTS), maxon::UInt64(enum36::REGPARSEMODE::ENDS)};
	static const maxon::EnumInfo REGPARSEMODE_info{"REGPARSEMODE", SIZEOF(REGPARSEMODE), false, "MATCH\0CONTAINS\0STARTS\0ENDS\0", REGPARSEMODE_values, std::extent<decltype(REGPARSEMODE_values)>::value};
}
const maxon::EnumInfo& PrivateGetEnumInfo_REGPARSEMODE36(){ return enum36::REGPARSEMODE_info; }
/// @cond IGNORE

/// @endcond

#ifdef CINEWARE_NAMESPACE_ENABLE
CINEWARE_NAMESPACE_END
#endif
#endif
