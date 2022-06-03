#if 1
#ifdef __API_INTERN__
#else
#endif
#ifdef CINEWARE_NAMESPACE_ENABLE
CINEWARE_NAMESPACE_BEGIN
#endif
namespace enum49
{
	enum class TAKE_MODE
	{
		MANUAL	= 0,			///< Manual override: the user has to explicitly override every single parameter.
		AUTO							///< Auto override: the system overrides any edited parameter (similar to Auto Key).
	} ;
	static const maxon::UInt64 TAKE_MODE_values[] = {maxon::UInt64(enum49::TAKE_MODE::MANUAL), maxon::UInt64(enum49::TAKE_MODE::AUTO)};
	static const maxon::EnumInfo TAKE_MODE_info{"TAKE_MODE", SIZEOF(TAKE_MODE), false, "MANUAL\0AUTO\0", TAKE_MODE_values, std::extent<decltype(TAKE_MODE_values)>::value};
}
const maxon::EnumInfo& PrivateGetEnumInfo_TAKE_MODE49(){ return enum49::TAKE_MODE_info; }
namespace enum71
{
	enum class OVERRIDEENABLING
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
	} ;
	static const maxon::UInt64 OVERRIDEENABLING_values[] = {maxon::UInt64(enum71::OVERRIDEENABLING::NONE), maxon::UInt64(enum71::OVERRIDEENABLING::OBJECT), maxon::UInt64(enum71::OVERRIDEENABLING::TAG), maxon::UInt64(enum71::OVERRIDEENABLING::MATERIAL), maxon::UInt64(enum71::OVERRIDEENABLING::SHADER), maxon::UInt64(enum71::OVERRIDEENABLING::LAYER), maxon::UInt64(enum71::OVERRIDEENABLING::OTHER), maxon::UInt64(enum71::OVERRIDEENABLING::GLOBAL), maxon::UInt64(enum71::OVERRIDEENABLING::ENABLING), maxon::UInt64(enum71::OVERRIDEENABLING::TRANSFOM), maxon::UInt64(enum71::OVERRIDEENABLING::CAMERA), maxon::UInt64(enum71::OVERRIDEENABLING::RS), maxon::UInt64(enum71::OVERRIDEENABLING::PARAM)};
	static const maxon::EnumInfo OVERRIDEENABLING_info{"OVERRIDEENABLING", SIZEOF(OVERRIDEENABLING), true, "NONE\0OBJECT\0TAG\0MATERIAL\0SHADER\0LAYER\0OTHER\0GLOBAL\0ENABLING\0TRANSFOM\0CAMERA\0RS\0PARAM\0", OVERRIDEENABLING_values, std::extent<decltype(OVERRIDEENABLING_values)>::value};
}
const maxon::EnumInfo& PrivateGetEnumInfo_OVERRIDEENABLING71(){ return enum71::OVERRIDEENABLING_info; }
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

#ifdef CINEWARE_NAMESPACE_ENABLE
CINEWARE_NAMESPACE_END
#endif
#endif
