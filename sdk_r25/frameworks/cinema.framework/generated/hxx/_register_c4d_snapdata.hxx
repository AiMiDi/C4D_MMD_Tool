#if 1
#ifdef CINEWARE_NAMESPACE_ENABLE
CINEWARE_NAMESPACE_BEGIN
#endif
namespace enum100
{
	enum class SNAPPRIORITY
	{
		NONE		= 0,				///< The lowest priority
		PLANE		= 1000,			///< Planar snapping e.g. to the workplane or a polygon surface.
		GUIDE		= 2000,			///< Guide snapping lower then edge to allow correct drawing for dynamic guides.
		EDGE		= 3000,			///< Edge snapping is a slightly higher priority and will override planar snapping.
		POINT		= 4000			///< Point snapping is the highest (default) snapping priority.
	} ;
	static const maxon::UInt64 SNAPPRIORITY_values[] = {maxon::UInt64(enum100::SNAPPRIORITY::NONE), maxon::UInt64(enum100::SNAPPRIORITY::PLANE), maxon::UInt64(enum100::SNAPPRIORITY::GUIDE), maxon::UInt64(enum100::SNAPPRIORITY::EDGE), maxon::UInt64(enum100::SNAPPRIORITY::POINT)};
	static const maxon::EnumInfo SNAPPRIORITY_info{"SNAPPRIORITY", SIZEOF(SNAPPRIORITY), false, "NONE\0PLANE\0GUIDE\0EDGE\0POINT\0", SNAPPRIORITY_values, std::extent<decltype(SNAPPRIORITY_values)>::value};
}
const maxon::EnumInfo& PrivateGetEnumInfo_SNAPPRIORITY100(){ return enum100::SNAPPRIORITY_info; }
namespace enum114
{
	enum class SNAPFLAGS
	{
		NONE						= 0,						///< No flags.
		IGNORE_SELECTED	= (1 << 0),			///< Do not snap to the selected objects or components.
		IGNORE_AXIS			= (1 << 1),			///< Do not snap to the active axis.
		POINTSONLY			= (1 << 2),			///< Ignore modes with lower priority than points.
		SURFACEONLY			= (1 << 3)			///< Ignore modes with higher priority than planes.
	} ;
	static const maxon::UInt64 SNAPFLAGS_values[] = {maxon::UInt64(enum114::SNAPFLAGS::NONE), maxon::UInt64(enum114::SNAPFLAGS::IGNORE_SELECTED), maxon::UInt64(enum114::SNAPFLAGS::IGNORE_AXIS), maxon::UInt64(enum114::SNAPFLAGS::POINTSONLY), maxon::UInt64(enum114::SNAPFLAGS::SURFACEONLY)};
	static const maxon::EnumInfo SNAPFLAGS_info{"SNAPFLAGS", SIZEOF(SNAPFLAGS), true, "NONE\0IGNORE_SELECTED\0IGNORE_AXIS\0POINTSONLY\0SURFACEONLY\0", SNAPFLAGS_values, std::extent<decltype(SNAPFLAGS_values)>::value};
}
const maxon::EnumInfo& PrivateGetEnumInfo_SNAPFLAGS114(){ return enum114::SNAPFLAGS_info; }
namespace enum126
{
	enum class INFERREDGUIDETYPE
	{
		POINT	= 0,			///< An inferred point or "axis", create guides along all perpendicular lines to the point in @em x, @em y and @em z.
		LINE	= 1,			///< Inferred guide line, act just like a normal guide line, e.g. along an edge.
		PLANE	= 2				///< Inferred plane, act just like a normal guide plane.
	} ;
	static const maxon::UInt64 INFERREDGUIDETYPE_values[] = {maxon::UInt64(enum126::INFERREDGUIDETYPE::POINT), maxon::UInt64(enum126::INFERREDGUIDETYPE::LINE), maxon::UInt64(enum126::INFERREDGUIDETYPE::PLANE)};
	static const maxon::EnumInfo INFERREDGUIDETYPE_info{"INFERREDGUIDETYPE", SIZEOF(INFERREDGUIDETYPE), false, "POINT\0LINE\0PLANE\0", INFERREDGUIDETYPE_values, std::extent<decltype(INFERREDGUIDETYPE_values)>::value};
}
const maxon::EnumInfo& PrivateGetEnumInfo_INFERREDGUIDETYPE126(){ return enum126::INFERREDGUIDETYPE_info; }
#ifdef CINEWARE_NAMESPACE_ENABLE
CINEWARE_NAMESPACE_END
#endif
#endif
