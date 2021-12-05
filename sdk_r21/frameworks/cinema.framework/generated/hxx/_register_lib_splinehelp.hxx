#if 1
#ifndef __API_INTERN__
#endif
namespace enum37 { enum class SPLINEHELPFLAGS
{
	NONE								=	0,						///< None.
	USERDEFORMERS				=	(1 << 0),			///< Use deformed splines.
	GLOBALSPACE					=	(1 << 1),			///< Generate results in global rather than spline local space.
	TARGETRAIL					=	(1 << 2),			///< Target the rail spline (if passed).
	CONTINUECURVE				=	(1 << 3),			///< Continue the curvature of an existing spline at the end points.
	FORCEUPDATE					=	(1 << 4),			///< Force the SplineHelp to recalculate regardless of spline dirtiness.
	RETAINLINEOBJECT		=	(1 << 5)			///< Retain a copy of the line object for user usage via SplineHelp::GetLineObject().
} ; }
maxon::String PrivateToString_SPLINEHELPFLAGS37(std::underlying_type<enum37::SPLINEHELPFLAGS>::type x, const maxon::FormatStatement* fmt)
{
	const maxon::UInt64 values[] = {(maxon::UInt64) enum37::SPLINEHELPFLAGS::NONE, (maxon::UInt64) enum37::SPLINEHELPFLAGS::USERDEFORMERS, (maxon::UInt64) enum37::SPLINEHELPFLAGS::GLOBALSPACE, (maxon::UInt64) enum37::SPLINEHELPFLAGS::TARGETRAIL, (maxon::UInt64) enum37::SPLINEHELPFLAGS::CONTINUECURVE, (maxon::UInt64) enum37::SPLINEHELPFLAGS::FORCEUPDATE, (maxon::UInt64) enum37::SPLINEHELPFLAGS::RETAINLINEOBJECT};
	return maxon::StringInterface::PrivateEnumToString((maxon::UInt64) x, "SPLINEHELPFLAGS", SIZEOF(x), true, values, "NONE\0USERDEFORMERS\0GLOBALSPACE\0TARGETRAIL\0CONTINUECURVE\0FORCEUPDATE\0RETAINLINEOBJECT\0", fmt);
}
/// @cond IGNORE

#ifdef __API_INTERN__
#endif
/// @endcond

#endif
