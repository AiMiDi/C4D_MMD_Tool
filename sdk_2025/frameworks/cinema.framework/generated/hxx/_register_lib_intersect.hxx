#if 1
namespace cinema
{
	namespace enum31
	{
		enum class INTERSECTTYPE
		{
			BVH			///< BVH.
		} ;
		static const maxon::UInt64 INTERSECTTYPE_values[] = {maxon::UInt64(enum31::INTERSECTTYPE::BVH)};
		static const maxon::EnumInfo INTERSECTTYPE_info{"INTERSECTTYPE", SIZEOF(INTERSECTTYPE), false, "BVH\0", INTERSECTTYPE_values, std::extent<decltype(INTERSECTTYPE_values)>::value};
	}
	const maxon::EnumInfo& PrivateGetEnumInfo_INTERSECTTYPE31(){ return enum31::INTERSECTTYPE_info; }
/// @cond IGNORE

/// @endcond

}
#endif
