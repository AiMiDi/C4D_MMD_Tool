#if 1
#ifdef __API_INTERN__
#else
namespace enum36 { enum class GE_CM_CLIPREGION
{
	EVENODD		= 1,			///< Enclosed regions of the path alternate between interior and exterior areas as traversed from the outside of the path towards a point inside the region.
	WINDING_	= 2				///< If a ray is drawn in any direction from a given point to infinity and the places where the path intersects the ray are examined:\n
											///< The point is inside of the path if and only if the number of times that the path crosses the ray from left to right does not equal the number of times that the path crosses the ray from right to left.
} ; }
maxon::String PrivateToString_GE_CM_CLIPREGION36(std::underlying_type<enum36::GE_CM_CLIPREGION>::type x, const maxon::FormatStatement* fmt)
{
	const maxon::UInt64 values[] = {(maxon::UInt64) enum36::GE_CM_CLIPREGION::EVENODD, (maxon::UInt64) enum36::GE_CM_CLIPREGION::WINDING_};
	return maxon::StringInterface::PrivateEnumToString((maxon::UInt64) x, "GE_CM_CLIPREGION", SIZEOF(x), false, values, "EVENODD\0WINDING_\0", fmt);
}
namespace enum48 { enum class GE_CM_DRAWMODE
{
	COPY			= 0,			///< New pixels overwrite old ones.
	BLEND			= 1,			///< New pixels blend with old ones, taking the alpha value of the new pixels in account as well as the blend factor specified by the parameter.\n
											///< The value specified by the parameter is the opacity of the source (bitmap). It ranges from @em 0 to @em 256, where @em 256 equals @em 1.0 and means opaque.
	MASK			= 2				///< New pixels overwrite the old ones at the bits where the mask specified by the parameter equals @em 1.
} ; }
maxon::String PrivateToString_GE_CM_DRAWMODE48(std::underlying_type<enum48::GE_CM_DRAWMODE>::type x, const maxon::FormatStatement* fmt)
{
	const maxon::UInt64 values[] = {(maxon::UInt64) enum48::GE_CM_DRAWMODE::COPY, (maxon::UInt64) enum48::GE_CM_DRAWMODE::BLEND, (maxon::UInt64) enum48::GE_CM_DRAWMODE::MASK};
	return maxon::StringInterface::PrivateEnumToString((maxon::UInt64) x, "GE_CM_DRAWMODE", SIZEOF(x), false, values, "COPY\0BLEND\0MASK\0", fmt);
}
#ifndef GE_CM_SRC_MAX_OPACITY
#endif
namespace enum63 { enum class GE_CM_BLIT
{
	COPY			= 0,			///< Source overwrites destination.
	COL			= 1,			///< Source overwrites destination everywhere where source does not equal the background color.
	FG				= 2				///< Sets pixels to the foreground color if the color is not the background color.
} ; }
maxon::String PrivateToString_GE_CM_BLIT63(std::underlying_type<enum63::GE_CM_BLIT>::type x, const maxon::FormatStatement* fmt)
{
	const maxon::UInt64 values[] = {(maxon::UInt64) enum63::GE_CM_BLIT::COPY, (maxon::UInt64) enum63::GE_CM_BLIT::COL, (maxon::UInt64) enum63::GE_CM_BLIT::FG};
	return maxon::StringInterface::PrivateEnumToString((maxon::UInt64) x, "GE_CM_BLIT", SIZEOF(x), false, values, "COPY\0COL\0FG\0", fmt);
}
namespace enum75 { enum class GE_CM_ARCSEGMENT
{
	RIGHTTOP			= 0,			///< (x1,y1) -> (x2,y1) -> (x2,y2)
	RIGHTBOTTOM	= 1,			///< (x2,y1) -> (x2,y2) -> (x1,y2)
	LEFTBOTTOM		= 2,			///< (x2,y2) -> (x1,y2) -> (x1,y1)
	LEFTTOP			= 3			///< (x1,y2) -> (x1,y1) -> (x2,y1)
} ; }
maxon::String PrivateToString_GE_CM_ARCSEGMENT75(std::underlying_type<enum75::GE_CM_ARCSEGMENT>::type x, const maxon::FormatStatement* fmt)
{
	const maxon::UInt64 values[] = {(maxon::UInt64) enum75::GE_CM_ARCSEGMENT::RIGHTTOP, (maxon::UInt64) enum75::GE_CM_ARCSEGMENT::RIGHTBOTTOM, (maxon::UInt64) enum75::GE_CM_ARCSEGMENT::LEFTBOTTOM, (maxon::UInt64) enum75::GE_CM_ARCSEGMENT::LEFTTOP};
	return maxon::StringInterface::PrivateEnumToString((maxon::UInt64) x, "GE_CM_ARCSEGMENT", SIZEOF(x), false, values, "RIGHTTOP\0RIGHTBOTTOM\0LEFTBOTTOM\0LEFTTOP\0", fmt);
}
namespace enum86 { enum class GE_CM_FONTSORT
{
	FLAT					= 0,			///< For each font family a BaseContainer is stored and will hold a description for each font of this family (one BaseContainer per font).\n
																				///< The font families are sorted alphabetically.
	HIERARCHICAL	= 1				///< One BaseContainer per font, no order guaranteed.
} ; }
maxon::String PrivateToString_GE_CM_FONTSORT86(std::underlying_type<enum86::GE_CM_FONTSORT>::type x, const maxon::FormatStatement* fmt)
{
	const maxon::UInt64 values[] = {(maxon::UInt64) enum86::GE_CM_FONTSORT::FLAT, (maxon::UInt64) enum86::GE_CM_FONTSORT::HIERARCHICAL};
	return maxon::StringInterface::PrivateEnumToString((maxon::UInt64) x, "GE_CM_FONTSORT", SIZEOF(x), false, values, "FLAT\0HIERARCHICAL\0", fmt);
}
#endif
/// @cond IGNORE

/// @endcond

#endif
