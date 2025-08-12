#if 1
#ifdef __API_INTERN__
#endif
namespace cinema
{
	namespace enum28
	{
		enum class MTBODYPARTTRANSFERATTRIBUTEMODE : Int32
		{
			BYID = 0,								///< Transfer using the ID.
			BYNAME,									///< Transfer using the Name.
			BOTH										///< Transfer using both technique.
		} ;
		static const maxon::UInt64 MTBODYPARTTRANSFERATTRIBUTEMODE_values[] = {maxon::UInt64(enum28::MTBODYPARTTRANSFERATTRIBUTEMODE::BYID), maxon::UInt64(enum28::MTBODYPARTTRANSFERATTRIBUTEMODE::BYNAME), maxon::UInt64(enum28::MTBODYPARTTRANSFERATTRIBUTEMODE::BOTH)};
		static const maxon::EnumInfo MTBODYPARTTRANSFERATTRIBUTEMODE_info{"MTBODYPARTTRANSFERATTRIBUTEMODE", SIZEOF(MTBODYPARTTRANSFERATTRIBUTEMODE), false, "BYID\0BYNAME\0BOTH\0", MTBODYPARTTRANSFERATTRIBUTEMODE_values, std::extent<decltype(MTBODYPARTTRANSFERATTRIBUTEMODE_values)>::value};
	}
	const maxon::EnumInfo& PrivateGetEnumInfo_MTBODYPARTTRANSFERATTRIBUTEMODE28(){ return enum28::MTBODYPARTTRANSFERATTRIBUTEMODE_info; }
}
#endif
