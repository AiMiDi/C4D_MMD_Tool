#if 1
#ifdef CINEWARE_NAMESPACE_ENABLE
CINEWARE_NAMESPACE_BEGIN
#endif
namespace enum42 { enum class HANDLECONSTRAINTTYPE
{
	INVALID		= -1,			///< Invalid handle constraint type, used to temporarily ignore handles (e.g. in the Camera Object with the Front/Back DOF handles).
	LINEAR		= 0,			///< Linear handle constraint.
	PLANAR		= 1,			///< Planar handle constraint.
	FREE			= 2,			///< No constraint.
	RADIAL		= 3,			///< Radial handle constraint.
	SPHERICAL	= 4				///< Spherical handle constraint.
} ; }
maxon::String PrivateToString_HANDLECONSTRAINTTYPE42(std::underlying_type<enum42::HANDLECONSTRAINTTYPE>::type x, const maxon::FormatStatement* fmt)
{
	const maxon::UInt64 values[] = {(maxon::UInt64) enum42::HANDLECONSTRAINTTYPE::INVALID, (maxon::UInt64) enum42::HANDLECONSTRAINTTYPE::LINEAR, (maxon::UInt64) enum42::HANDLECONSTRAINTTYPE::PLANAR, (maxon::UInt64) enum42::HANDLECONSTRAINTTYPE::FREE, (maxon::UInt64) enum42::HANDLECONSTRAINTTYPE::RADIAL, (maxon::UInt64) enum42::HANDLECONSTRAINTTYPE::SPHERICAL};
	return maxon::StringInterface::PrivateEnumToString((maxon::UInt64) x, "HANDLECONSTRAINTTYPE", SIZEOF(x), false, values, "INVALID\0LINEAR\0PLANAR\0FREE\0RADIAL\0SPHERICAL\0", fmt);
}
#ifdef CINEWARE_NAMESPACE_ENABLE
CINEWARE_NAMESPACE_END
#endif
#endif
