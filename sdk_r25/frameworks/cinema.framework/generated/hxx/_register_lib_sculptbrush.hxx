#if 1
#ifdef CINEWARE_NAMESPACE_ENABLE
CINEWARE_NAMESPACE_BEGIN
#endif
namespace enum63
{
	enum class SCULPTBRUSHID
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
	} ;
	static const maxon::UInt64 SCULPTBRUSHID_values[] = {maxon::UInt64(enum63::SCULPTBRUSHID::SMOOTH), maxon::UInt64(enum63::SCULPTBRUSHID::PULL), maxon::UInt64(enum63::SCULPTBRUSHID::FLATTEN), maxon::UInt64(enum63::SCULPTBRUSHID::PINCH), maxon::UInt64(enum63::SCULPTBRUSHID::ERASE), maxon::UInt64(enum63::SCULPTBRUSHID::GRAB), maxon::UInt64(enum63::SCULPTBRUSHID::MASK), maxon::UInt64(enum63::SCULPTBRUSHID::KNIFE), maxon::UInt64(enum63::SCULPTBRUSHID::WAX), maxon::UInt64(enum63::SCULPTBRUSHID::INFLATE), maxon::UInt64(enum63::SCULPTBRUSHID::FILL), maxon::UInt64(enum63::SCULPTBRUSHID::SCRAPE), maxon::UInt64(enum63::SCULPTBRUSHID::REPEAT), maxon::UInt64(enum63::SCULPTBRUSHID::AMPLIFY), maxon::UInt64(enum63::SCULPTBRUSHID::SELECT)};
	static const maxon::EnumInfo SCULPTBRUSHID_info{"SCULPTBRUSHID", SIZEOF(SCULPTBRUSHID), false, "SMOOTH\0PULL\0FLATTEN\0PINCH\0ERASE\0GRAB\0MASK\0KNIFE\0WAX\0INFLATE\0FILL\0SCRAPE\0REPEAT\0AMPLIFY\0SELECT\0", SCULPTBRUSHID_values, std::extent<decltype(SCULPTBRUSHID_values)>::value};
}
const maxon::EnumInfo& PrivateGetEnumInfo_SCULPTBRUSHID63(){ return enum63::SCULPTBRUSHID_info; }
namespace enum74
{
	enum class FIRSTHITPPOINTTYPE
	{
		SELECTED,			///< Use the exact hit location on the surface as the hit point.
		AVERAGE,				///< Use the average location of all the points that the brush dab touches.
	} ;
	static const maxon::UInt64 FIRSTHITPPOINTTYPE_values[] = {maxon::UInt64(enum74::FIRSTHITPPOINTTYPE::SELECTED), maxon::UInt64(enum74::FIRSTHITPPOINTTYPE::AVERAGE)};
	static const maxon::EnumInfo FIRSTHITPPOINTTYPE_info{"FIRSTHITPPOINTTYPE", SIZEOF(FIRSTHITPPOINTTYPE), false, "SELECTED\0AVERAGE\0", FIRSTHITPPOINTTYPE_values, std::extent<decltype(FIRSTHITPPOINTTYPE_values)>::value};
}
const maxon::EnumInfo& PrivateGetEnumInfo_FIRSTHITPPOINTTYPE74(){ return enum74::FIRSTHITPPOINTTYPE_info; }
namespace enum87
{
	enum class SCULPTBRUSHMODE
	{
		NORMAL,			///< Samples the surface as the user moves over it the SculptObject and returns a new hit point and normal each time.
		GRAB,				///< Calculates affected points, hit point and normal the first time the user clicks.\n
								///< These are the only points that are affected as the user moves the mouse.\n
								///< This mode is used by the Grab Tool which uses the BrushDabData::GetMousePos3D() method to get the mouse position in 3D space as the user moves it.
	} ;
	static const maxon::UInt64 SCULPTBRUSHMODE_values[] = {maxon::UInt64(enum87::SCULPTBRUSHMODE::NORMAL), maxon::UInt64(enum87::SCULPTBRUSHMODE::GRAB)};
	static const maxon::EnumInfo SCULPTBRUSHMODE_info{"SCULPTBRUSHMODE", SIZEOF(SCULPTBRUSHMODE), false, "NORMAL\0GRAB\0", SCULPTBRUSHMODE_values, std::extent<decltype(SCULPTBRUSHMODE_values)>::value};
}
const maxon::EnumInfo& PrivateGetEnumInfo_SCULPTBRUSHMODE87(){ return enum87::SCULPTBRUSHMODE_info; }
namespace enum101
{
	enum class SCULPTBRUSHDATATYPE
	{
		NONE				= 0,					///< None.
		POINT				= 1 << 0,			///< The points are changed.
		MASK				= 1 << 1,			///< The mask data is changed.
		COLOR				= 1 << 2,			///< @markInternal
		DIRTYPOINTS	= 1 << 3,			///< @markInternal Used by tiles to check if all its points have already been marked as dirty or not.
	} ;
	static const maxon::UInt64 SCULPTBRUSHDATATYPE_values[] = {maxon::UInt64(enum101::SCULPTBRUSHDATATYPE::NONE), maxon::UInt64(enum101::SCULPTBRUSHDATATYPE::POINT), maxon::UInt64(enum101::SCULPTBRUSHDATATYPE::MASK), maxon::UInt64(enum101::SCULPTBRUSHDATATYPE::COLOR), maxon::UInt64(enum101::SCULPTBRUSHDATATYPE::DIRTYPOINTS)};
	static const maxon::EnumInfo SCULPTBRUSHDATATYPE_info{"SCULPTBRUSHDATATYPE", SIZEOF(SCULPTBRUSHDATATYPE), true, "NONE\0POINT\0MASK\0COLOR\0DIRTYPOINTS\0", SCULPTBRUSHDATATYPE_values, std::extent<decltype(SCULPTBRUSHDATATYPE_values)>::value};
}
const maxon::EnumInfo& PrivateGetEnumInfo_SCULPTBRUSHDATATYPE101(){ return enum101::SCULPTBRUSHDATATYPE_info; }
namespace enum116
{
	enum class OVERRIDE
	{
		NONE = 0,
	
		INVERT			= 1 << 0,			///< If the user holds down the @em Ctrl key then the brush should Invert its functionality.
		SMOOTH			= 1 << 1,			///< The user is holding down the @em Shift key and a smooth operation should be done.\n
															///< Brushes can choose to specify their own operation for smooth, like the Mask Tool which does a blur.
		SMOOTHTOOL	= 1 << 2			///< @markInternal Used to specify that the smooth is tool specific.
	} ;
	static const maxon::UInt64 OVERRIDE_values[] = {maxon::UInt64(enum116::OVERRIDE::NONE), maxon::UInt64(enum116::OVERRIDE::INVERT), maxon::UInt64(enum116::OVERRIDE::SMOOTH), maxon::UInt64(enum116::OVERRIDE::SMOOTHTOOL)};
	static const maxon::EnumInfo OVERRIDE_info{"OVERRIDE", SIZEOF(OVERRIDE), true, "NONE\0INVERT\0SMOOTH\0SMOOTHTOOL\0", OVERRIDE_values, std::extent<decltype(OVERRIDE_values)>::value};
}
const maxon::EnumInfo& PrivateGetEnumInfo_OVERRIDE116(){ return enum116::OVERRIDE_info; }
namespace enum126
{
	enum class SAMPLEMODE
	{
		TAKEONEPIXEL	= 1 << 0,			///< Takes the exact pixel at the intersection point.
	} ;
	static const maxon::UInt64 SAMPLEMODE_values[] = {maxon::UInt64(enum126::SAMPLEMODE::TAKEONEPIXEL)};
	static const maxon::EnumInfo SAMPLEMODE_info{"SAMPLEMODE", SIZEOF(SAMPLEMODE), true, "TAKEONEPIXEL\0", SAMPLEMODE_values, std::extent<decltype(SAMPLEMODE_values)>::value};
}
const maxon::EnumInfo& PrivateGetEnumInfo_SAMPLEMODE126(){ return enum126::SAMPLEMODE_info; }
namespace enum138
{
	enum class SCULPTOFFSETFLAGS
	{
		NONE						= 0,					///< None.
		RESPECTSTRENGTH	= 1 << 0,			///< Respect the Strength of the current layer.
		IGNOREMASK			= 1 << 1,			///< Ignore the Mask setting for the current layer.
	} ;
	static const maxon::UInt64 SCULPTOFFSETFLAGS_values[] = {maxon::UInt64(enum138::SCULPTOFFSETFLAGS::NONE), maxon::UInt64(enum138::SCULPTOFFSETFLAGS::RESPECTSTRENGTH), maxon::UInt64(enum138::SCULPTOFFSETFLAGS::IGNOREMASK)};
	static const maxon::EnumInfo SCULPTOFFSETFLAGS_info{"SCULPTOFFSETFLAGS", SIZEOF(SCULPTOFFSETFLAGS), true, "NONE\0RESPECTSTRENGTH\0IGNOREMASK\0", SCULPTOFFSETFLAGS_values, std::extent<decltype(SCULPTOFFSETFLAGS_values)>::value};
}
const maxon::EnumInfo& PrivateGetEnumInfo_SCULPTOFFSETFLAGS138(){ return enum138::SCULPTOFFSETFLAGS_info; }
/// @cond IGNORE

/// @endcond

#ifdef CINEWARE_NAMESPACE_ENABLE
CINEWARE_NAMESPACE_END
#endif
#endif
