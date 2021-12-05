#if 1
namespace enum38 { enum class HANDLECONSTRAINTTYPE
{
	INVALID		= -1,			///< Invalid handle constraint type, used to temporarily ignore handles (e.g. in the Camera Object with the Front/Back DOF handles).
	LINEAR		= 0,			///< Linear handle constraint.
	PLANAR		= 1,			///< Planar handle constraint.
	FREE			= 2,			///< No constraint.
	RADIAL		= 3,			///< Radial handle constraint.
	SPHERICAL	= 4				///< Spherical handle constraint.
} ; }
maxon::String PrivateToString_HANDLECONSTRAINTTYPE38(std::underlying_type<enum38::HANDLECONSTRAINTTYPE>::type x, const maxon::FormatStatement* fmt)
{
	const maxon::UInt64 values[] = {(maxon::UInt64) enum38::HANDLECONSTRAINTTYPE::INVALID, (maxon::UInt64) enum38::HANDLECONSTRAINTTYPE::LINEAR, (maxon::UInt64) enum38::HANDLECONSTRAINTTYPE::PLANAR, (maxon::UInt64) enum38::HANDLECONSTRAINTTYPE::FREE, (maxon::UInt64) enum38::HANDLECONSTRAINTTYPE::RADIAL, (maxon::UInt64) enum38::HANDLECONSTRAINTTYPE::SPHERICAL};
	return maxon::StringInterface::PrivateEnumToString((maxon::UInt64) x, "HANDLECONSTRAINTTYPE", SIZEOF(x), false, values, "INVALID\0LINEAR\0PLANAR\0FREE\0RADIAL\0SPHERICAL\0", fmt);
}
#endif
