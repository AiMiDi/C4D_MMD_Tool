#if 1
namespace enum86 { enum class DESCPROP
{
	NONE							= 0,
	SEQUENCE					= (1 << 0),			///< Has a sequence on the current frame.
	KEY								= (1 << 1),			///< Has a key on the current frame.
	AUTOKEY_ACTIVE		= (1 << 2),			///< Autokey active icon.
	AUTOKEY_INACTIVE	= (1 << 3),			///< Autokey inactive icon.
	NOANIM						= (1 << 4),			///< No animation.
	ENABLED						= (1 << 5),			///< Enabled.
	ANIM_NOT_ALLOWED	= (1 << 6),			///< Animation not allowed.
	GLOBAL_PARAMETER	= (1 << 7),			///< Global parameter.
	KEY_CHANGED				= (1 << 9),			///< Has a key on the current frame but the value changed.
	HIDDEN						= (1 << 10),		///< Hidden description property.
	LOCKED						= (1 << 11),		///< Locked description property.
	KEY_MUTED					= (1 << 12),		///< Current key frame is muted.
	PORTIN						= (1 << 13),		///< Port used by XPresso as inport.
	PORTIN_CONNECTED	= (1 << 14),		///< Port used by XPresso as connected inport.
	PORTOUT						= (1 << 15),		///< Port used by XPresso as outport.
	PORTOUT_CONNECTED	= (1 << 16),		///< Port used by XPresso as connected outport.
	CHANGED						= (1 << 17),		///< The value changed.
	NOTOVERRIDE				= (1 << 18),		///< Parameter is not overridden. @since R17.032
	AUTOTAKE					= (1 << 19),		///< Description is enabled for Auto Take. @since R17.032
	INVERTENABLING		= (1 << 20),		///< Description enabling defined by override from Take has to be inverted. @since R17.032
	NODE							= (1 << 21)			///< Private - node parameter.
} ; }
maxon::String PrivateToString_DESCPROP86(std::underlying_type<enum86::DESCPROP>::type x, const maxon::FormatStatement* fmt)
{
	const maxon::UInt64 values[] = {(maxon::UInt64) enum86::DESCPROP::NONE, (maxon::UInt64) enum86::DESCPROP::SEQUENCE, (maxon::UInt64) enum86::DESCPROP::KEY, (maxon::UInt64) enum86::DESCPROP::AUTOKEY_ACTIVE, (maxon::UInt64) enum86::DESCPROP::AUTOKEY_INACTIVE, (maxon::UInt64) enum86::DESCPROP::NOANIM, (maxon::UInt64) enum86::DESCPROP::ENABLED, (maxon::UInt64) enum86::DESCPROP::ANIM_NOT_ALLOWED, (maxon::UInt64) enum86::DESCPROP::GLOBAL_PARAMETER, (maxon::UInt64) enum86::DESCPROP::KEY_CHANGED, (maxon::UInt64) enum86::DESCPROP::HIDDEN, (maxon::UInt64) enum86::DESCPROP::LOCKED, (maxon::UInt64) enum86::DESCPROP::KEY_MUTED, (maxon::UInt64) enum86::DESCPROP::PORTIN, (maxon::UInt64) enum86::DESCPROP::PORTIN_CONNECTED, (maxon::UInt64) enum86::DESCPROP::PORTOUT, (maxon::UInt64) enum86::DESCPROP::PORTOUT_CONNECTED, (maxon::UInt64) enum86::DESCPROP::CHANGED, (maxon::UInt64) enum86::DESCPROP::NOTOVERRIDE, (maxon::UInt64) enum86::DESCPROP::AUTOTAKE, (maxon::UInt64) enum86::DESCPROP::INVERTENABLING, (maxon::UInt64) enum86::DESCPROP::NODE};
	return maxon::StringInterface::PrivateEnumToString((maxon::UInt64) x, "DESCPROP", SIZEOF(x), true, values, "NONE\0SEQUENCE\0KEY\0AUTOKEY_ACTIVE\0AUTOKEY_INACTIVE\0NOANIM\0ENABLED\0ANIM_NOT_ALLOWED\0GLOBAL_PARAMETER\0KEY_CHANGED\0HIDDEN\0LOCKED\0KEY_MUTED\0PORTIN\0PORTIN_CONNECTED\0PORTOUT\0PORTOUT_CONNECTED\0CHANGED\0NOTOVERRIDE\0AUTOTAKE\0INVERTENABLING\0NODE\0", fmt);
}
/// @cond IGNORE

#ifndef _INTERNAL_DEF_
#else
#endif
/// @endcond

#endif
