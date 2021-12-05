#if 1
#ifdef CINEWARE_NAMESPACE_ENABLE
CINEWARE_NAMESPACE_BEGIN
#endif
namespace enum32
{
	enum class INTERSECTTYPE
	{
		BVH			///< BVH.
	} ;
	static const maxon::UInt64 INTERSECTTYPE_values[] = {maxon::UInt64(enum32::INTERSECTTYPE::BVH)};
	static const maxon::EnumInfo INTERSECTTYPE_info{"INTERSECTTYPE", SIZEOF(INTERSECTTYPE), false, "BVH\0", INTERSECTTYPE_values, std::extent<decltype(INTERSECTTYPE_values)>::value};
}
const maxon::EnumInfo& PrivateGetEnumInfo_INTERSECTTYPE32(){ return enum32::INTERSECTTYPE_info; }
/// @cond IGNORE

/// @endcond

#ifdef CINEWARE_NAMESPACE_ENABLE
CINEWARE_NAMESPACE_END
#endif
#endif
