#if 1
namespace maxon
{
	namespace enum14 { enum class NURBSCURVE_CONTINUITY
	{
		OPEN     = 0, ///< Open spline with No continuity between first and last point.
		CLOSED   = 1, ///< Closed spline with position continuity (sharp cusp) between first and last point. Replaces any previous knot vector with a clamped uniform knot vector.
		PERIODIC = 2  ///< Closed spline with C2 continuity between first and last point. Replaces any previous knot vector with an unclamped uniform knot vector.
	} ; }
	maxon::String PrivateToString_NURBSCURVE_CONTINUITY14(std::underlying_type<enum14::NURBSCURVE_CONTINUITY>::type x, const maxon::FormatStatement* fmt)
	{
		const maxon::UInt64 values[] = {(maxon::UInt64) enum14::NURBSCURVE_CONTINUITY::OPEN, (maxon::UInt64) enum14::NURBSCURVE_CONTINUITY::CLOSED, (maxon::UInt64) enum14::NURBSCURVE_CONTINUITY::PERIODIC};
		return maxon::StringInterface::PrivateEnumToString((maxon::UInt64) x, "NURBSCURVE_CONTINUITY", SIZEOF(x), false, values, "OPEN\0CLOSED\0PERIODIC\0", fmt);
	}
}
#endif
