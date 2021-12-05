#if 1
#ifndef __API_INTERN__
#endif
#ifdef CINEWARE_NAMESPACE_ENABLE
CINEWARE_NAMESPACE_BEGIN
#endif
namespace enum42 { enum class SPLINEHELPFLAGS
{
	NONE								=	0,						///< None.
	USERDEFORMERS				=	(1 << 0),			///< Use deformed splines.
	GLOBALSPACE					=	(1 << 1),			///< Generate results in global rather than spline local space.
	TARGETRAIL					=	(1 << 2),			///< Target the rail spline (if passed).
	CONTINUECURVE				=	(1 << 3),			///< Continue the curvature of an existing spline at the end points.
	FORCEUPDATE					=	(1 << 4),			///< Force the SplineHelp to recalculate regardless of spline dirtiness.
	RETAINLINEOBJECT		=	(1 << 5),			///< Retain a copy of the line object for user usage via SplineHelp::GetLineObject().
	RETAINSPLINECACHE		= (1 << 6)			///< Retain a copy of the spline object cache for user usage via SplineHelp::GetSplineObjectCache().
} ; }
maxon::String PrivateToString_SPLINEHELPFLAGS42(std::underlying_type<enum42::SPLINEHELPFLAGS>::type x, const maxon::FormatStatement* fmt)
{
	const maxon::UInt64 values[] = {(maxon::UInt64) enum42::SPLINEHELPFLAGS::NONE, (maxon::UInt64) enum42::SPLINEHELPFLAGS::USERDEFORMERS, (maxon::UInt64) enum42::SPLINEHELPFLAGS::GLOBALSPACE, (maxon::UInt64) enum42::SPLINEHELPFLAGS::TARGETRAIL, (maxon::UInt64) enum42::SPLINEHELPFLAGS::CONTINUECURVE, (maxon::UInt64) enum42::SPLINEHELPFLAGS::FORCEUPDATE, (maxon::UInt64) enum42::SPLINEHELPFLAGS::RETAINLINEOBJECT, (maxon::UInt64) enum42::SPLINEHELPFLAGS::RETAINSPLINECACHE};
	return maxon::StringInterface::PrivateEnumToString((maxon::UInt64) x, "SPLINEHELPFLAGS", SIZEOF(x), true, values, "NONE\0USERDEFORMERS\0GLOBALSPACE\0TARGETRAIL\0CONTINUECURVE\0FORCEUPDATE\0RETAINLINEOBJECT\0RETAINSPLINECACHE\0", fmt);
}
/// @cond IGNORE

#ifdef __API_INTERN__
#endif
/// @endcond

#ifdef CINEWARE_NAMESPACE_ENABLE
CINEWARE_NAMESPACE_END
#endif
#endif
