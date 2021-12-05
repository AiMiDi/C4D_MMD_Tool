#if 1
namespace maxon
{
	namespace enum15
	{
		enum class NURBSCURVE_CONTINUITY
		{
			OPEN     = 0, ///< Open spline with No continuity between first and last point.
			CLOSED   = 1, ///< Closed spline with position continuity (sharp cusp) between first and last point. Replaces any previous knot vector with a clamped uniform knot vector.
			PERIODIC = 2  ///< Closed spline with C2 continuity between first and last point. Replaces any previous knot vector with an unclamped uniform knot vector.
		} ;
		static const maxon::UInt64 NURBSCURVE_CONTINUITY_values[] = {maxon::UInt64(enum15::NURBSCURVE_CONTINUITY::OPEN), maxon::UInt64(enum15::NURBSCURVE_CONTINUITY::CLOSED), maxon::UInt64(enum15::NURBSCURVE_CONTINUITY::PERIODIC)};
		static const maxon::EnumInfo NURBSCURVE_CONTINUITY_info{"NURBSCURVE_CONTINUITY", SIZEOF(NURBSCURVE_CONTINUITY), false, "OPEN\0CLOSED\0PERIODIC\0", NURBSCURVE_CONTINUITY_values, std::extent<decltype(NURBSCURVE_CONTINUITY_values)>::value};
	}
	const maxon::EnumInfo& PrivateGetEnumInfo_NURBSCURVE_CONTINUITY15(){ return enum15::NURBSCURVE_CONTINUITY_info; }
#if 0
#endif
}
#endif
