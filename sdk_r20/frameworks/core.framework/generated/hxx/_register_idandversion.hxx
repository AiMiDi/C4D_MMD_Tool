#if 1
namespace maxon
{
	namespace enum25 { enum class ASSET_UPDATE_POLICY
	{
		NEVER = 0,			///< The asset is never updated, so the link always points to the exact version recorded in the link.
		EXPLICIT = 1,		///< The asset isn't updated implicitly, but the user is asked if the link shall point to the latest version if there is a newer version than the one recorded in the link.
		IMPLICIT = 2		///< The asset is updated implicitly whenever a newer version of the asset exists.
	} ; }
	maxon::String PrivateToString_ASSET_UPDATE_POLICY25(std::underlying_type<enum25::ASSET_UPDATE_POLICY>::type x, const maxon::FormatStatement* fmt)
	{
		const maxon::UInt64 values[] = {(maxon::UInt64) enum25::ASSET_UPDATE_POLICY::NEVER, (maxon::UInt64) enum25::ASSET_UPDATE_POLICY::EXPLICIT, (maxon::UInt64) enum25::ASSET_UPDATE_POLICY::IMPLICIT};
		return maxon::StringInterface::PrivateEnumToString((maxon::UInt64) x, "ASSET_UPDATE_POLICY", SIZEOF(x), false, values, "NEVER\0EXPLICIT\0IMPLICIT\0", fmt);
	}
	PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(DT_ASSET_UPDATE_POLICY, , "net.maxon.datatype.enum.asset_update_policy");
}
#endif
