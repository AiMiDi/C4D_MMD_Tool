#if 1
namespace enum96 { enum class SNAPPRIORITY
{
	NONE		= 0,				///< The lowest priority
	PLANE		= 1000,			///< Planar snapping e.g. to the workplane or a polygon surface.
	GUIDE		= 2000,			///< Guide snapping lower then edge to allow correct drawing for dynamic guides.
	EDGE		= 3000,			///< Edge snapping is a slightly higher priority and will override planar snapping.
	POINT		= 4000			///< Point snapping is the highest (default) snapping priority.
} ; }
maxon::String PrivateToString_SNAPPRIORITY96(std::underlying_type<enum96::SNAPPRIORITY>::type x, const maxon::FormatStatement* fmt)
{
	const maxon::UInt64 values[] = {(maxon::UInt64) enum96::SNAPPRIORITY::NONE, (maxon::UInt64) enum96::SNAPPRIORITY::PLANE, (maxon::UInt64) enum96::SNAPPRIORITY::GUIDE, (maxon::UInt64) enum96::SNAPPRIORITY::EDGE, (maxon::UInt64) enum96::SNAPPRIORITY::POINT};
	return maxon::StringInterface::PrivateEnumToString((maxon::UInt64) x, "SNAPPRIORITY", SIZEOF(x), false, values, "NONE\0PLANE\0GUIDE\0EDGE\0POINT\0", fmt);
}
namespace enum110 { enum class SNAPFLAGS
{
	NONE						= 0,						///< No flags.
	IGNORE_SELECTED	= (1 << 0),			///< Do not snap to the selected objects or components.
	IGNORE_AXIS			= (1 << 1),			///< Do not snap to the active axis.
	POINTSONLY			= (1 << 2),			///< Ignore modes with lower priority than points.
	SURFACEONLY			= (1 << 3)			///< Ignore modes with higher priority than planes.
} ; }
maxon::String PrivateToString_SNAPFLAGS110(std::underlying_type<enum110::SNAPFLAGS>::type x, const maxon::FormatStatement* fmt)
{
	const maxon::UInt64 values[] = {(maxon::UInt64) enum110::SNAPFLAGS::NONE, (maxon::UInt64) enum110::SNAPFLAGS::IGNORE_SELECTED, (maxon::UInt64) enum110::SNAPFLAGS::IGNORE_AXIS, (maxon::UInt64) enum110::SNAPFLAGS::POINTSONLY, (maxon::UInt64) enum110::SNAPFLAGS::SURFACEONLY};
	return maxon::StringInterface::PrivateEnumToString((maxon::UInt64) x, "SNAPFLAGS", SIZEOF(x), true, values, "NONE\0IGNORE_SELECTED\0IGNORE_AXIS\0POINTSONLY\0SURFACEONLY\0", fmt);
}
namespace enum122 { enum class INFERREDGUIDETYPE
{
	POINT	= 0,			///< An inferred point or "axis", create guides along all perpendicular lines to the point in @em x, @em y and @em z.
	LINE	= 1,			///< Inferred guide line, act just like a normal guide line, e.g. along an edge.
	PLANE	= 2				///< Inferred plane, act just like a normal guide plane.
} ; }
maxon::String PrivateToString_INFERREDGUIDETYPE122(std::underlying_type<enum122::INFERREDGUIDETYPE>::type x, const maxon::FormatStatement* fmt)
{
	const maxon::UInt64 values[] = {(maxon::UInt64) enum122::INFERREDGUIDETYPE::POINT, (maxon::UInt64) enum122::INFERREDGUIDETYPE::LINE, (maxon::UInt64) enum122::INFERREDGUIDETYPE::PLANE};
	return maxon::StringInterface::PrivateEnumToString((maxon::UInt64) x, "INFERREDGUIDETYPE", SIZEOF(x), false, values, "POINT\0LINE\0PLANE\0", fmt);
}
#endif
