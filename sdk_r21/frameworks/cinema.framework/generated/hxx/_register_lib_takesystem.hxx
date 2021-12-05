#if 1
#ifdef __API_INTERN__
#else
#endif
namespace enum45 { enum class TAKE_MODE
{
	MANUAL	= 0,			///< Manual override: the user has to explicitly override every single parameter.
	AUTO							///< Auto override: the system overrides any edited parameter (similar to Auto Key).
} ; }
maxon::String PrivateToString_TAKE_MODE45(std::underlying_type<enum45::TAKE_MODE>::type x, const maxon::FormatStatement* fmt)
{
	const maxon::UInt64 values[] = {(maxon::UInt64) enum45::TAKE_MODE::MANUAL, (maxon::UInt64) enum45::TAKE_MODE::AUTO};
	return maxon::StringInterface::PrivateEnumToString((maxon::UInt64) x, "TAKE_MODE", SIZEOF(x), false, values, "MANUAL\0AUTO\0", fmt);
}
namespace enum67 { enum class OVERRIDEENABLING
{
	NONE											= 0,							///< None.
	OBJECT									= (1 << 0),				///< Object override enabled.
	TAG										= (1 << 1),				///< Tag override enabled.
	MATERIAL								= (1 << 2),				///< Material override enabled.
	SHADER									= (1 << 3),				///< Shader override enabled.
	LAYER									= (1 << 4),				///< Layer override enabled.
	OTHER									= (1 << 5),				///< Other types override enabled.
	GLOBAL									= (1 << 6),				///< Main switch types override enabled.

	ENABLING								= (1 << 7),				///< Object enabling and visibility override enabled.
	TRANSFOM								= (1 << 8),				///< Transformation override enabled.
	CAMERA									= (1 << 9),				///< Active camera override enabled.
	RS											= (1 << 10),			///< Active render settings override enabled.
	PARAM									= (1 << 11)				///< Generic parameter override enabled.
} ; }
maxon::String PrivateToString_OVERRIDEENABLING67(std::underlying_type<enum67::OVERRIDEENABLING>::type x, const maxon::FormatStatement* fmt)
{
	const maxon::UInt64 values[] = {(maxon::UInt64) enum67::OVERRIDEENABLING::NONE, (maxon::UInt64) enum67::OVERRIDEENABLING::OBJECT, (maxon::UInt64) enum67::OVERRIDEENABLING::TAG, (maxon::UInt64) enum67::OVERRIDEENABLING::MATERIAL, (maxon::UInt64) enum67::OVERRIDEENABLING::SHADER, (maxon::UInt64) enum67::OVERRIDEENABLING::LAYER, (maxon::UInt64) enum67::OVERRIDEENABLING::OTHER, (maxon::UInt64) enum67::OVERRIDEENABLING::GLOBAL, (maxon::UInt64) enum67::OVERRIDEENABLING::ENABLING, (maxon::UInt64) enum67::OVERRIDEENABLING::TRANSFOM, (maxon::UInt64) enum67::OVERRIDEENABLING::CAMERA, (maxon::UInt64) enum67::OVERRIDEENABLING::RS, (maxon::UInt64) enum67::OVERRIDEENABLING::PARAM};
	return maxon::StringInterface::PrivateEnumToString((maxon::UInt64) x, "OVERRIDEENABLING", SIZEOF(x), true, values, "NONE\0OBJECT\0TAG\0MATERIAL\0SHADER\0LAYER\0OTHER\0GLOBAL\0ENABLING\0TRANSFOM\0CAMERA\0RS\0PARAM\0", fmt);
}
#ifndef __API_INTERN__
#endif
#ifndef __API_INTERN__
#endif
#ifndef __API_INTERN__
#endif
#ifndef __API_INTERN__
#endif
/// @cond IGNORE

/// @endcond

#endif
