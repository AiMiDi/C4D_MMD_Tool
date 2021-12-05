#if 1
#ifdef __API_INTERN__
#endif
#ifdef CINEWARE_NAMESPACE_ENABLE
CINEWARE_NAMESPACE_BEGIN
#endif
namespace enum98 { enum class MDDIRTY
{
	NONE				= 0,
	ALL					= ~0,
	ARRAYCOUNT	= (1 << 0),			///< Array count itself changed (number of different arrays rather than length of arrays).
	COUNT				= (1 << 1),			///< Length of the arrays changed.
	DATA				= (1 << 2)			///< Data in the arrays changed, must be manually set.
} ; }
maxon::String PrivateToString_MDDIRTY98(std::underlying_type<enum98::MDDIRTY>::type x, const maxon::FormatStatement* fmt)
{
	const maxon::UInt64 values[] = {(maxon::UInt64) enum98::MDDIRTY::NONE, (maxon::UInt64) enum98::MDDIRTY::ALL, (maxon::UInt64) enum98::MDDIRTY::ARRAYCOUNT, (maxon::UInt64) enum98::MDDIRTY::COUNT, (maxon::UInt64) enum98::MDDIRTY::DATA};
	return maxon::StringInterface::PrivateEnumToString((maxon::UInt64) x, "MDDIRTY", SIZEOF(x), true, values, "NONE\0ALL\0ARRAYCOUNT\0COUNT\0DATA\0", fmt);
}
namespace enum120 { enum class MD_TYPE
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
} ; }
maxon::String PrivateToString_MD_TYPE120(std::underlying_type<enum120::MD_TYPE>::type x, const maxon::FormatStatement* fmt)
{
	const maxon::UInt64 values[] = {(maxon::UInt64) enum120::MD_TYPE::MD_NONE, (maxon::UInt64) enum120::MD_TYPE::MD_CHAR, (maxon::UInt64) enum120::MD_TYPE::MD_UCHAR, (maxon::UInt64) enum120::MD_TYPE::MD_LONG, (maxon::UInt64) enum120::MD_TYPE::MD_ULONG, (maxon::UInt64) enum120::MD_TYPE::MD_LLONG, (maxon::UInt64) enum120::MD_TYPE::MD_MATRIX, (maxon::UInt64) enum120::MD_TYPE::MD_COLOR, (maxon::UInt64) enum120::MD_TYPE::MD_VECTOR, (maxon::UInt64) enum120::MD_TYPE::MD_NORMAL, (maxon::UInt64) enum120::MD_TYPE::MD_REAL, (maxon::UInt64) enum120::MD_TYPE::MD_BOOL};
	return maxon::StringInterface::PrivateEnumToString((maxon::UInt64) x, "MD_TYPE", SIZEOF(x), false, values, "MD_NONE\0MD_CHAR\0MD_UCHAR\0MD_LONG\0MD_ULONG\0MD_LLONG\0MD_MATRIX\0MD_COLOR\0MD_VECTOR\0MD_NORMAL\0MD_REAL\0MD_BOOL\0", fmt);
}
#ifdef CINEWARE_NAMESPACE_ENABLE
CINEWARE_NAMESPACE_END
#endif
#endif
