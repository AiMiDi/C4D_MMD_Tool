#if 1
namespace enum28 { enum class INTERSECTTYPE
{
	BVH			///< BVH.
} ; }
maxon::String PrivateToString_INTERSECTTYPE28(std::underlying_type<enum28::INTERSECTTYPE>::type x, const maxon::FormatStatement* fmt)
{
	const maxon::UInt64 values[] = {(maxon::UInt64) enum28::INTERSECTTYPE::BVH};
	return maxon::StringInterface::PrivateEnumToString((maxon::UInt64) x, "INTERSECTTYPE", SIZEOF(x), false, values, "BVH\0", fmt);
}
/// @cond IGNORE

/// @endcond

#endif
