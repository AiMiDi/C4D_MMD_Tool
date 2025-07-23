#if 1
namespace cinema
{
	namespace enum35
	{
		enum class REGPARSEMODE
		{
			MATCH = 1,			///< Full match.
			CONTAINS,				///< Partial match.
			STARTS,					///< Match starting at the beginning.
			ENDS						///< Match finishing at the end.
		} ;
		static const maxon::UInt64 REGPARSEMODE_values[] = {maxon::UInt64(enum35::REGPARSEMODE::MATCH), maxon::UInt64(enum35::REGPARSEMODE::CONTAINS), maxon::UInt64(enum35::REGPARSEMODE::STARTS), maxon::UInt64(enum35::REGPARSEMODE::ENDS)};
		static const maxon::EnumInfo REGPARSEMODE_info{"REGPARSEMODE", SIZEOF(REGPARSEMODE), false, "MATCH\0CONTAINS\0STARTS\0ENDS\0", REGPARSEMODE_values, std::extent<decltype(REGPARSEMODE_values)>::value};
	}
	const maxon::EnumInfo& PrivateGetEnumInfo_REGPARSEMODE35(){ return enum35::REGPARSEMODE_info; }
/// @cond IGNORE

/// @endcond

}
#endif
