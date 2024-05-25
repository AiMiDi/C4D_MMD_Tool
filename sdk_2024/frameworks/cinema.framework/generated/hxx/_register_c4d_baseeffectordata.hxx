#if 1
#ifdef __API_INTERN__
#endif
#ifdef CINEWARE_NAMESPACE_ENABLE
CINEWARE_NAMESPACE_BEGIN
#endif
namespace enum142
{
	enum class MDDIRTY
	{
		NONE				= 0,
		ALL					= ~0,
		ARRAYCOUNT	= (1 << 0),			///< Array count itself changed (number of different arrays rather than length of arrays).
		COUNT				= (1 << 1),			///< Length of the arrays changed.
		DATA				= (1 << 2)			///< Data in the arrays changed, must be manually set.
	} ;
	static const maxon::UInt64 MDDIRTY_values[] = {maxon::UInt64(enum142::MDDIRTY::NONE), maxon::UInt64(enum142::MDDIRTY::ALL), maxon::UInt64(enum142::MDDIRTY::ARRAYCOUNT), maxon::UInt64(enum142::MDDIRTY::COUNT), maxon::UInt64(enum142::MDDIRTY::DATA)};
	static const maxon::EnumInfo MDDIRTY_info{"MDDIRTY", SIZEOF(MDDIRTY), true, "NONE\0ALL\0ARRAYCOUNT\0COUNT\0DATA\0", MDDIRTY_values, std::extent<decltype(MDDIRTY_values)>::value};
}
const maxon::EnumInfo& PrivateGetEnumInfo_MDDIRTY142(){ return enum142::MDDIRTY_info; }
namespace enum164
{
	enum class MD_TYPE
	{
		MD_NONE		= DA_NIL,						///< None.
		MD_CHAR		= 40000000,					///< ::Char type.
		MD_UCHAR	= 40000001,					///< ::UChar type.
		MD_LONG		= DTYPE_LONG,				///< ::Int32 type.
		MD_ULONG	= 40000002,					///< ::UInt32 type.
		MD_LLONG	= DA_LLONG,					///< ::Int64 type.
		MD_MATRIX	= DA_MATRIX,				///< ::Matrix type.
		MD_COLOR	= DTYPE_COLOR,			///< Color type (::Vector).
		MD_VECTOR	= DTYPE_VECTOR,			///< ::Vector type.
		MD_NORMAL	= DTYPE_NORMAL,			///< Normal type (::Vector).
		MD_REAL		= DTYPE_REAL,				///< ::Float type.
		MD_BOOL		= DTYPE_BOOL				///< ::Bool type.
	} ;
	static const maxon::UInt64 MD_TYPE_values[] = {maxon::UInt64(enum164::MD_TYPE::MD_NONE), maxon::UInt64(enum164::MD_TYPE::MD_CHAR), maxon::UInt64(enum164::MD_TYPE::MD_UCHAR), maxon::UInt64(enum164::MD_TYPE::MD_LONG), maxon::UInt64(enum164::MD_TYPE::MD_ULONG), maxon::UInt64(enum164::MD_TYPE::MD_LLONG), maxon::UInt64(enum164::MD_TYPE::MD_MATRIX), maxon::UInt64(enum164::MD_TYPE::MD_COLOR), maxon::UInt64(enum164::MD_TYPE::MD_VECTOR), maxon::UInt64(enum164::MD_TYPE::MD_NORMAL), maxon::UInt64(enum164::MD_TYPE::MD_REAL), maxon::UInt64(enum164::MD_TYPE::MD_BOOL)};
	static const maxon::EnumInfo MD_TYPE_info{"MD_TYPE", SIZEOF(MD_TYPE), false, "MD_NONE\0MD_CHAR\0MD_UCHAR\0MD_LONG\0MD_ULONG\0MD_LLONG\0MD_MATRIX\0MD_COLOR\0MD_VECTOR\0MD_NORMAL\0MD_REAL\0MD_BOOL\0", MD_TYPE_values, std::extent<decltype(MD_TYPE_values)>::value};
}
const maxon::EnumInfo& PrivateGetEnumInfo_MD_TYPE164(){ return enum164::MD_TYPE_info; }
namespace enum1324
{
	enum class STRENGTHMASK
	{
		NONE = 0,
	
		POS_X = (1 << 0),
		POS_Y = (1 << 1),
		POS_Z = (1 << 2),
		POS = POS_X | POS_Y | POS_Z,
	
		SCALE_X = (1 << 3),
		SCALE_Y = (1 << 4),
		SCALE_Z = (1 << 5),
		SCALE = SCALE_X | SCALE_Y | SCALE_Z,
	
		ROT_X = (1 << 6),
		ROT_Y = (1 << 7),
		ROT_Z = (1 << 8),
		ROT = ROT_X | ROT_Y | ROT_Z,
	
		COL_X = (1 << 9),
		COL_Y = (1 << 10),
		COL_Z = (1 << 11),
		COL = COL_X | COL_Y | COL_Z,
	
		OTHER_X = (1 << 12),
		OTHER_Y = (1 << 13),
		OTHER_Z = (1 << 14),
		OTHER = OTHER_X | OTHER_Y | OTHER_Z,
	
		OTHER2_X = (1 << 15),
		OTHER2_Y = (1 << 16),
		OTHER2_Z = (1 << 17),
		OTHER2 = OTHER2_X | OTHER2_Y | OTHER2_Z,
	
		OTHER3_X = (1 << 18),
		OTHER3_Y = (1 << 19),
		OTHER3_Z = (1 << 20),
		OTHER3 = OTHER3_X | OTHER3_Y | OTHER3_Z,
	} ;
	static const maxon::UInt64 STRENGTHMASK_values[] = {maxon::UInt64(enum1324::STRENGTHMASK::NONE), maxon::UInt64(enum1324::STRENGTHMASK::POS_X), maxon::UInt64(enum1324::STRENGTHMASK::POS_Y), maxon::UInt64(enum1324::STRENGTHMASK::POS_Z), maxon::UInt64(enum1324::STRENGTHMASK::POS), maxon::UInt64(enum1324::STRENGTHMASK::SCALE_X), maxon::UInt64(enum1324::STRENGTHMASK::SCALE_Y), maxon::UInt64(enum1324::STRENGTHMASK::SCALE_Z), maxon::UInt64(enum1324::STRENGTHMASK::SCALE), maxon::UInt64(enum1324::STRENGTHMASK::ROT_X), maxon::UInt64(enum1324::STRENGTHMASK::ROT_Y), maxon::UInt64(enum1324::STRENGTHMASK::ROT_Z), maxon::UInt64(enum1324::STRENGTHMASK::ROT), maxon::UInt64(enum1324::STRENGTHMASK::COL_X), maxon::UInt64(enum1324::STRENGTHMASK::COL_Y), maxon::UInt64(enum1324::STRENGTHMASK::COL_Z), maxon::UInt64(enum1324::STRENGTHMASK::COL), maxon::UInt64(enum1324::STRENGTHMASK::OTHER_X), maxon::UInt64(enum1324::STRENGTHMASK::OTHER_Y), maxon::UInt64(enum1324::STRENGTHMASK::OTHER_Z), maxon::UInt64(enum1324::STRENGTHMASK::OTHER), maxon::UInt64(enum1324::STRENGTHMASK::OTHER2_X), maxon::UInt64(enum1324::STRENGTHMASK::OTHER2_Y), maxon::UInt64(enum1324::STRENGTHMASK::OTHER2_Z), maxon::UInt64(enum1324::STRENGTHMASK::OTHER2), maxon::UInt64(enum1324::STRENGTHMASK::OTHER3_X), maxon::UInt64(enum1324::STRENGTHMASK::OTHER3_Y), maxon::UInt64(enum1324::STRENGTHMASK::OTHER3_Z), maxon::UInt64(enum1324::STRENGTHMASK::OTHER3)};
	static const maxon::EnumInfo STRENGTHMASK_info{"STRENGTHMASK", SIZEOF(STRENGTHMASK), true, "NONE\0POS_X\0POS_Y\0POS_Z\0POS\0SCALE_X\0SCALE_Y\0SCALE_Z\0SCALE\0ROT_X\0ROT_Y\0ROT_Z\0ROT\0COL_X\0COL_Y\0COL_Z\0COL\0OTHER_X\0OTHER_Y\0OTHER_Z\0OTHER\0OTHER2_X\0OTHER2_Y\0OTHER2_Z\0OTHER2\0OTHER3_X\0OTHER3_Y\0OTHER3_Z\0OTHER3\0", STRENGTHMASK_values, std::extent<decltype(STRENGTHMASK_values)>::value};
}
const maxon::EnumInfo& PrivateGetEnumInfo_STRENGTHMASK1324(){ return enum1324::STRENGTHMASK_info; }
#ifdef CINEWARE_NAMESPACE_ENABLE
CINEWARE_NAMESPACE_END
#endif
#endif
