#if 1
namespace enum59 { enum class SCULPTBRUSHID
{
	SMOOTH		= 1024170,			///< Smooth brush ID.
	PULL			= 1024168,			///< Pull brush ID.
	FLATTEN		= 1024169,			///< Flatten brush ID.
	PINCH			= 1024171,			///< Pinch brush ID.
	ERASE			= 1024189,			///< Erase brush ID.
	GRAB			= 1024197,			///< Grab brush ID.
	MASK			= 1024506,			///< Mask brush ID.
	KNIFE			= 1026519,			///< Knife brush ID.
	WAX				= 1026518,			///< Wax brush ID.
	INFLATE		= 1026708,			///< Inflate brush ID.
	FILL			= 1026710,			///< Fill brush ID.
	SCRAPE		= 1026715,			///< Scrape brush ID.
	REPEAT		= 1027556,			///< Repeat brush ID.
	AMPLIFY		= 1029169,			///< Amplify brush ID.
	SELECT		= 1031429				///< Select brush ID.
} ; }
maxon::String PrivateToString_SCULPTBRUSHID59(std::underlying_type<enum59::SCULPTBRUSHID>::type x, const maxon::FormatStatement* fmt)
{
	const maxon::UInt64 values[] = {(maxon::UInt64) enum59::SCULPTBRUSHID::SMOOTH, (maxon::UInt64) enum59::SCULPTBRUSHID::PULL, (maxon::UInt64) enum59::SCULPTBRUSHID::FLATTEN, (maxon::UInt64) enum59::SCULPTBRUSHID::PINCH, (maxon::UInt64) enum59::SCULPTBRUSHID::ERASE, (maxon::UInt64) enum59::SCULPTBRUSHID::GRAB, (maxon::UInt64) enum59::SCULPTBRUSHID::MASK, (maxon::UInt64) enum59::SCULPTBRUSHID::KNIFE, (maxon::UInt64) enum59::SCULPTBRUSHID::WAX, (maxon::UInt64) enum59::SCULPTBRUSHID::INFLATE, (maxon::UInt64) enum59::SCULPTBRUSHID::FILL, (maxon::UInt64) enum59::SCULPTBRUSHID::SCRAPE, (maxon::UInt64) enum59::SCULPTBRUSHID::REPEAT, (maxon::UInt64) enum59::SCULPTBRUSHID::AMPLIFY, (maxon::UInt64) enum59::SCULPTBRUSHID::SELECT};
	return maxon::StringInterface::PrivateEnumToString((maxon::UInt64) x, "SCULPTBRUSHID", SIZEOF(x), false, values, "SMOOTH\0PULL\0FLATTEN\0PINCH\0ERASE\0GRAB\0MASK\0KNIFE\0WAX\0INFLATE\0FILL\0SCRAPE\0REPEAT\0AMPLIFY\0SELECT\0", fmt);
}
namespace enum70 { enum class FIRSTHITPPOINTTYPE
{
	SELECTED,			///< Use the exact hit location on the surface as the hit point.
	AVERAGE,				///< Use the average location of all the points that the brush dab touches.
} ; }
maxon::String PrivateToString_FIRSTHITPPOINTTYPE70(std::underlying_type<enum70::FIRSTHITPPOINTTYPE>::type x, const maxon::FormatStatement* fmt)
{
	const maxon::UInt64 values[] = {(maxon::UInt64) enum70::FIRSTHITPPOINTTYPE::SELECTED, (maxon::UInt64) enum70::FIRSTHITPPOINTTYPE::AVERAGE};
	return maxon::StringInterface::PrivateEnumToString((maxon::UInt64) x, "FIRSTHITPPOINTTYPE", SIZEOF(x), false, values, "SELECTED\0AVERAGE\0", fmt);
}
namespace enum83 { enum class SCULPTBRUSHMODE
{
	NORMAL,			///< Samples the surface as the user moves over it the SculptObject and returns a new hit point and normal each time.
	GRAB,				///< Calculates affected points, hit point and normal the first time the user clicks.\n
							///< These are the only points that are affected as the user moves the mouse.\n
							///< This mode is used by the Grab Tool which uses the BrushDabData::GetMousePos3D() method to get the mouse position in 3D space as the user moves it.
} ; }
maxon::String PrivateToString_SCULPTBRUSHMODE83(std::underlying_type<enum83::SCULPTBRUSHMODE>::type x, const maxon::FormatStatement* fmt)
{
	const maxon::UInt64 values[] = {(maxon::UInt64) enum83::SCULPTBRUSHMODE::NORMAL, (maxon::UInt64) enum83::SCULPTBRUSHMODE::GRAB};
	return maxon::StringInterface::PrivateEnumToString((maxon::UInt64) x, "SCULPTBRUSHMODE", SIZEOF(x), false, values, "NORMAL\0GRAB\0", fmt);
}
namespace enum97 { enum class SCULPTBRUSHDATATYPE
{
	NONE				= 0,					///< None.
	POINT				= 1 << 0,			///< The points are changed.
	MASK				= 1 << 1,			///< The mask data is changed.
	COLOR				= 1 << 2,			///< @markInternal
	DIRTYPOINTS	= 1 << 3,			///< @markInternal Used by tiles to check if all its points have already been marked as dirty or not.
} ; }
maxon::String PrivateToString_SCULPTBRUSHDATATYPE97(std::underlying_type<enum97::SCULPTBRUSHDATATYPE>::type x, const maxon::FormatStatement* fmt)
{
	const maxon::UInt64 values[] = {(maxon::UInt64) enum97::SCULPTBRUSHDATATYPE::NONE, (maxon::UInt64) enum97::SCULPTBRUSHDATATYPE::POINT, (maxon::UInt64) enum97::SCULPTBRUSHDATATYPE::MASK, (maxon::UInt64) enum97::SCULPTBRUSHDATATYPE::COLOR, (maxon::UInt64) enum97::SCULPTBRUSHDATATYPE::DIRTYPOINTS};
	return maxon::StringInterface::PrivateEnumToString((maxon::UInt64) x, "SCULPTBRUSHDATATYPE", SIZEOF(x), true, values, "NONE\0POINT\0MASK\0COLOR\0DIRTYPOINTS\0", fmt);
}
namespace enum112 { enum class OVERRIDE
{
	NONE = 0,

	INVERT			= 1 << 0,			///< If the user holds down the @em Ctrl key then the brush should Invert its functionality.
	SMOOTH			= 1 << 1,			///< The user is holding down the @em Shift key and a smooth operation should be done.\n
														///< Brushes can choose to specify their own operation for smooth, like the Mask Tool which does a blur.
	SMOOTHTOOL	= 1 << 2			///< @markInternal Used to specify that the smooth is tool specific.
} ; }
maxon::String PrivateToString_OVERRIDE112(std::underlying_type<enum112::OVERRIDE>::type x, const maxon::FormatStatement* fmt)
{
	const maxon::UInt64 values[] = {(maxon::UInt64) enum112::OVERRIDE::NONE, (maxon::UInt64) enum112::OVERRIDE::INVERT, (maxon::UInt64) enum112::OVERRIDE::SMOOTH, (maxon::UInt64) enum112::OVERRIDE::SMOOTHTOOL};
	return maxon::StringInterface::PrivateEnumToString((maxon::UInt64) x, "OVERRIDE", SIZEOF(x), true, values, "NONE\0INVERT\0SMOOTH\0SMOOTHTOOL\0", fmt);
}
namespace enum122 { enum class SAMPLEMODE
{
	TAKEONEPIXEL	= 1 << 0,			///< Takes the exact pixel at the intersection point.
} ; }
maxon::String PrivateToString_SAMPLEMODE122(std::underlying_type<enum122::SAMPLEMODE>::type x, const maxon::FormatStatement* fmt)
{
	const maxon::UInt64 values[] = {(maxon::UInt64) enum122::SAMPLEMODE::TAKEONEPIXEL};
	return maxon::StringInterface::PrivateEnumToString((maxon::UInt64) x, "SAMPLEMODE", SIZEOF(x), true, values, "TAKEONEPIXEL\0", fmt);
}
namespace enum134 { enum class SCULPTOFFSETFLAGS
{
	NONE						= 0,					///< None.
	RESPECTSTRENGTH	= 1 << 0,			///< Respect the Strength of the current layer.
	IGNOREMASK			= 1 << 1,			///< Ignore the Mask setting for the current layer.
} ; }
maxon::String PrivateToString_SCULPTOFFSETFLAGS134(std::underlying_type<enum134::SCULPTOFFSETFLAGS>::type x, const maxon::FormatStatement* fmt)
{
	const maxon::UInt64 values[] = {(maxon::UInt64) enum134::SCULPTOFFSETFLAGS::NONE, (maxon::UInt64) enum134::SCULPTOFFSETFLAGS::RESPECTSTRENGTH, (maxon::UInt64) enum134::SCULPTOFFSETFLAGS::IGNOREMASK};
	return maxon::StringInterface::PrivateEnumToString((maxon::UInt64) x, "SCULPTOFFSETFLAGS", SIZEOF(x), true, values, "NONE\0RESPECTSTRENGTH\0IGNOREMASK\0", fmt);
}
/// @cond IGNORE

/// @endcond

#endif
