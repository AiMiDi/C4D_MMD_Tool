#if 1
namespace maxon
{
	namespace enum22 { enum class DBVERSION
	{
		R22 = 1,
		R23_CONVERTLIMIT,		 ///< convert limit Bool to enum
		R23_CONVERTENUM,		 ///< convert .enum and .command. to #enum and #command#
		R23_CONVERTENUM2,		 ///< convert .enum and .command. fixes ITEM#328085 [RE] Strings Translation tool deletes already translated strings
		R23_DBVERSIONIDTYPE, ///< removes the old dbversion type
		CURRENT,
	} ; }
	maxon::String PrivateToString_DBVERSION22(std::underlying_type<enum22::DBVERSION>::type x, const maxon::FormatStatement* fmt)
	{
		const maxon::UInt64 values[] = {(maxon::UInt64) enum22::DBVERSION::R22, (maxon::UInt64) enum22::DBVERSION::R23_CONVERTLIMIT, (maxon::UInt64) enum22::DBVERSION::R23_CONVERTENUM, (maxon::UInt64) enum22::DBVERSION::R23_CONVERTENUM2, (maxon::UInt64) enum22::DBVERSION::R23_DBVERSIONIDTYPE, (maxon::UInt64) enum22::DBVERSION::CURRENT};
		return maxon::StringInterface::PrivateEnumToString((maxon::UInt64) x, "DBVERSION", SIZEOF(x), false, values, "R22\0R23_CONVERTLIMIT\0R23_CONVERTENUM\0R23_CONVERTENUM2\0R23_DBVERSIONIDTYPE\0CURRENT\0", fmt);
	}
}
#endif
