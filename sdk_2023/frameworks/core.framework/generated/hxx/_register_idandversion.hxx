#if 1
namespace maxon
{
	namespace enum24
	{
		enum class ASSET_UPDATE_POLICY
		{
			NEVER = 0,			///< The asset is never updated, so the link always points to the exact version recorded in the link.
			EXPLICIT = 1,		///< The asset isn't updated implicitly, but the user is asked if the link shall point to the latest version if there is a newer version than the one recorded in the link.
			IMPLICIT = 2		///< The asset is updated implicitly whenever a newer version of the asset exists.
		} ;
		static const maxon::UInt64 ASSET_UPDATE_POLICY_values[] = {maxon::UInt64(enum24::ASSET_UPDATE_POLICY::NEVER), maxon::UInt64(enum24::ASSET_UPDATE_POLICY::EXPLICIT), maxon::UInt64(enum24::ASSET_UPDATE_POLICY::IMPLICIT)};
		static const maxon::EnumInfo ASSET_UPDATE_POLICY_info{"ASSET_UPDATE_POLICY", SIZEOF(ASSET_UPDATE_POLICY), false, "NEVER\0EXPLICIT\0IMPLICIT\0", ASSET_UPDATE_POLICY_values, std::extent<decltype(ASSET_UPDATE_POLICY_values)>::value};
	}
	const maxon::EnumInfo& PrivateGetEnumInfo_ASSET_UPDATE_POLICY24(){ return enum24::ASSET_UPDATE_POLICY_info; }
	PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(DT_ASSET_UPDATE_POLICY, , "net.maxon.datatype.enum.asset_update_policy");
}
#endif
