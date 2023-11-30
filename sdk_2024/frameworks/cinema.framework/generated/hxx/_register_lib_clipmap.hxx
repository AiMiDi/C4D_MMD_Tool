#if 1
#ifdef __API_INTERN__
#else
#ifdef CINEWARE_NAMESPACE_ENABLE
CINEWARE_NAMESPACE_BEGIN
#endif
namespace enum40
{
	enum class GE_CM_CLIPREGION
	{
		EVENODD		= 1,			///< Enclosed regions of the path alternate between interior and exterior areas as traversed from the outside of the path towards a point inside the region.
		WINDING_	= 2				///< If a ray is drawn in any direction from a given point to infinity and the places where the path intersects the ray are examined:\n
												///< The point is inside of the path if and only if the number of times that the path crosses the ray from left to right does not equal the number of times that the path crosses the ray from right to left.
	} ;
	static const maxon::UInt64 GE_CM_CLIPREGION_values[] = {maxon::UInt64(enum40::GE_CM_CLIPREGION::EVENODD), maxon::UInt64(enum40::GE_CM_CLIPREGION::WINDING_)};
	static const maxon::EnumInfo GE_CM_CLIPREGION_info{"GE_CM_CLIPREGION", SIZEOF(GE_CM_CLIPREGION), false, "EVENODD\0WINDING_\0", GE_CM_CLIPREGION_values, std::extent<decltype(GE_CM_CLIPREGION_values)>::value};
}
const maxon::EnumInfo& PrivateGetEnumInfo_GE_CM_CLIPREGION40(){ return enum40::GE_CM_CLIPREGION_info; }
namespace enum52
{
	enum class GE_CM_DRAWMODE
	{
		COPY			= 0,			///< New pixels overwrite old ones.
		BLEND			= 1,			///< New pixels blend with old ones, taking the alpha value of the new pixels in account as well as the blend factor specified by the parameter.\n
												///< The value specified by the parameter is the opacity of the source (bitmap). It ranges from @em 0 to @em 256, where @em 256 equals @em 1.0 and means opaque.
		MASK			= 2				///< New pixels overwrite the old ones at the bits where the mask specified by the parameter equals @em 1.
	} ;
	static const maxon::UInt64 GE_CM_DRAWMODE_values[] = {maxon::UInt64(enum52::GE_CM_DRAWMODE::COPY), maxon::UInt64(enum52::GE_CM_DRAWMODE::BLEND), maxon::UInt64(enum52::GE_CM_DRAWMODE::MASK)};
	static const maxon::EnumInfo GE_CM_DRAWMODE_info{"GE_CM_DRAWMODE", SIZEOF(GE_CM_DRAWMODE), false, "COPY\0BLEND\0MASK\0", GE_CM_DRAWMODE_values, std::extent<decltype(GE_CM_DRAWMODE_values)>::value};
}
const maxon::EnumInfo& PrivateGetEnumInfo_GE_CM_DRAWMODE52(){ return enum52::GE_CM_DRAWMODE_info; }
#ifndef GE_CM_SRC_MAX_OPACITY
#endif
namespace enum67
{
	enum class GE_CM_BLIT
	{
		COPY			= 0,			///< Source overwrites destination.
		COL			= 1,			///< Source overwrites destination everywhere where source does not equal the background color.
		FG				= 2				///< Sets pixels to the foreground color if the color is not the background color.
	} ;
	static const maxon::UInt64 GE_CM_BLIT_values[] = {maxon::UInt64(enum67::GE_CM_BLIT::COPY), maxon::UInt64(enum67::GE_CM_BLIT::COL), maxon::UInt64(enum67::GE_CM_BLIT::FG)};
	static const maxon::EnumInfo GE_CM_BLIT_info{"GE_CM_BLIT", SIZEOF(GE_CM_BLIT), false, "COPY\0COL\0FG\0", GE_CM_BLIT_values, std::extent<decltype(GE_CM_BLIT_values)>::value};
}
const maxon::EnumInfo& PrivateGetEnumInfo_GE_CM_BLIT67(){ return enum67::GE_CM_BLIT_info; }
namespace enum79
{
	enum class GE_CM_ARCSEGMENT
	{
		RIGHTTOP			= 0,			///< (x1,y1) -> (x2,y1) -> (x2,y2)
		RIGHTBOTTOM	= 1,			///< (x2,y1) -> (x2,y2) -> (x1,y2)
		LEFTBOTTOM		= 2,			///< (x2,y2) -> (x1,y2) -> (x1,y1)
		LEFTTOP			= 3			///< (x1,y2) -> (x1,y1) -> (x2,y1)
	} ;
	static const maxon::UInt64 GE_CM_ARCSEGMENT_values[] = {maxon::UInt64(enum79::GE_CM_ARCSEGMENT::RIGHTTOP), maxon::UInt64(enum79::GE_CM_ARCSEGMENT::RIGHTBOTTOM), maxon::UInt64(enum79::GE_CM_ARCSEGMENT::LEFTBOTTOM), maxon::UInt64(enum79::GE_CM_ARCSEGMENT::LEFTTOP)};
	static const maxon::EnumInfo GE_CM_ARCSEGMENT_info{"GE_CM_ARCSEGMENT", SIZEOF(GE_CM_ARCSEGMENT), false, "RIGHTTOP\0RIGHTBOTTOM\0LEFTBOTTOM\0LEFTTOP\0", GE_CM_ARCSEGMENT_values, std::extent<decltype(GE_CM_ARCSEGMENT_values)>::value};
}
const maxon::EnumInfo& PrivateGetEnumInfo_GE_CM_ARCSEGMENT79(){ return enum79::GE_CM_ARCSEGMENT_info; }
namespace enum90
{
	enum class GE_CM_FONTSORT
	{
		FLAT					= 0,	///< One BaseContainer per font, no order guaranteed.
		HIERARCHICAL	= 1		///< For each font family a BaseContainer is stored and will hold a description for each font of this family (one BaseContainer per font).\n
													///< The font families are sorted alphabetically.
	} ;
	static const maxon::UInt64 GE_CM_FONTSORT_values[] = {maxon::UInt64(enum90::GE_CM_FONTSORT::FLAT), maxon::UInt64(enum90::GE_CM_FONTSORT::HIERARCHICAL)};
	static const maxon::EnumInfo GE_CM_FONTSORT_info{"GE_CM_FONTSORT", SIZEOF(GE_CM_FONTSORT), false, "FLAT\0HIERARCHICAL\0", GE_CM_FONTSORT_values, std::extent<decltype(GE_CM_FONTSORT_values)>::value};
}
const maxon::EnumInfo& PrivateGetEnumInfo_GE_CM_FONTSORT90(){ return enum90::GE_CM_FONTSORT_info; }
#endif
/// @cond IGNORE

/// @endcond

#ifdef CINEWARE_NAMESPACE_ENABLE
CINEWARE_NAMESPACE_END
#endif
#endif
