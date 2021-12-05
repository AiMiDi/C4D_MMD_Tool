#if 1
#ifdef CINEWARE_NAMESPACE_ENABLE
CINEWARE_NAMESPACE_BEGIN
#endif
namespace enum32 { enum class INTERSECTTYPE
{
	BVH			///< BVH.
} ; }
maxon::String PrivateToString_INTERSECTTYPE32(std::underlying_type<enum32::INTERSECTTYPE>::type x, const maxon::FormatStatement* fmt)
{
	const maxon::UInt64 values[] = {(maxon::UInt64) enum32::INTERSECTTYPE::BVH};
	return maxon::StringInterface::PrivateEnumToString((maxon::UInt64) x, "INTERSECTTYPE", SIZEOF(x), false, values, "BVH\0", fmt);
}
/// @cond IGNORE

/// @endcond

#ifdef CINEWARE_NAMESPACE_ENABLE
CINEWARE_NAMESPACE_END
#endif
#endif
