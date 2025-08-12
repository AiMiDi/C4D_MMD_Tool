#if 1
namespace maxon
{
	namespace enum22
	{
		enum class DBVERSION
		{
			R22 = 1,
			R23_CONVERTLIMIT,		 ///< convert limit Bool to enum
			R23_CONVERTENUM,		 ///< convert .enum and .command. to #enum and #command#
			R23_CONVERTENUM2,		 ///< convert .enum and .command. fixes ITEM#328085 [RE] Strings Translation tool deletes already translated strings
			R23_DBVERSIONIDTYPE, ///< removes the old dbversion type
			CURRENT,
		} ;
		static const maxon::UInt64 DBVERSION_values[] = {maxon::UInt64(enum22::DBVERSION::R22), maxon::UInt64(enum22::DBVERSION::R23_CONVERTLIMIT), maxon::UInt64(enum22::DBVERSION::R23_CONVERTENUM), maxon::UInt64(enum22::DBVERSION::R23_CONVERTENUM2), maxon::UInt64(enum22::DBVERSION::R23_DBVERSIONIDTYPE), maxon::UInt64(enum22::DBVERSION::CURRENT)};
		static const maxon::EnumInfo DBVERSION_info{"DBVERSION", SIZEOF(DBVERSION), false, "R22\0R23_CONVERTLIMIT\0R23_CONVERTENUM\0R23_CONVERTENUM2\0R23_DBVERSIONIDTYPE\0CURRENT\0", DBVERSION_values, std::extent<decltype(DBVERSION_values)>::value};
	}
	const maxon::EnumInfo& PrivateGetEnumInfo_DBVERSION22(){ return enum22::DBVERSION_info; }
}
#endif
