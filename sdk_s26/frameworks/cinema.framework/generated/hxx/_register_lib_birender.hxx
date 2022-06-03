#if 1
#ifdef __API_INTERN__
#else
#endif
#ifdef CINEWARE_NAMESPACE_ENABLE
CINEWARE_NAMESPACE_BEGIN
#endif
namespace birender
{
	namespace enum46
	{
		enum class FLAG_STATE
		{
			NONE	= 0,
			ADD		= 1,
			DEL		= 2,
			SET		= 3,
		} ;
		static const maxon::UInt64 FLAG_STATE_values[] = {maxon::UInt64(enum46::FLAG_STATE::NONE), maxon::UInt64(enum46::FLAG_STATE::ADD), maxon::UInt64(enum46::FLAG_STATE::DEL), maxon::UInt64(enum46::FLAG_STATE::SET)};
		static const maxon::EnumInfo FLAG_STATE_info{"FLAG_STATE", SIZEOF(FLAG_STATE), false, "NONE\0ADD\0DEL\0SET\0", FLAG_STATE_values, std::extent<decltype(FLAG_STATE_values)>::value};
	}
	const maxon::EnumInfo& PrivateGetEnumInfo_FLAG_STATE46(){ return enum46::FLAG_STATE_info; }
	namespace enum56
	{
		enum class SHADING_CALLBACK_FLAG
		{
			NONE = 0,
			INIT = (1 << 0),
			EXIT = (1 << 1),
			SHADER = (1 << 2),
			THICKNESS = (1 << 3),
			SHADOWS = (1 << 4)
		} ;
		static const maxon::UInt64 SHADING_CALLBACK_FLAG_values[] = {maxon::UInt64(enum56::SHADING_CALLBACK_FLAG::NONE), maxon::UInt64(enum56::SHADING_CALLBACK_FLAG::INIT), maxon::UInt64(enum56::SHADING_CALLBACK_FLAG::EXIT), maxon::UInt64(enum56::SHADING_CALLBACK_FLAG::SHADER), maxon::UInt64(enum56::SHADING_CALLBACK_FLAG::THICKNESS), maxon::UInt64(enum56::SHADING_CALLBACK_FLAG::SHADOWS)};
		static const maxon::EnumInfo SHADING_CALLBACK_FLAG_info{"SHADING_CALLBACK_FLAG", SIZEOF(SHADING_CALLBACK_FLAG), true, "NONE\0INIT\0EXIT\0SHADER\0THICKNESS\0SHADOWS\0", SHADING_CALLBACK_FLAG_values, std::extent<decltype(SHADING_CALLBACK_FLAG_values)>::value};
	}
	const maxon::EnumInfo& PrivateGetEnumInfo_SHADING_CALLBACK_FLAG56(){ return enum56::SHADING_CALLBACK_FLAG_info; }
	namespace enum65
	{
		enum class RENDER_CALLBACK_FLAG
		{
			NONE = 0,
			DRAW = (1 << 0),
			FIRST = (1 << 1),
			CALCVOL = (1 << 2),
			CALCVOL_EXIT = (1 << 3)
		} ;
		static const maxon::UInt64 RENDER_CALLBACK_FLAG_values[] = {maxon::UInt64(enum65::RENDER_CALLBACK_FLAG::NONE), maxon::UInt64(enum65::RENDER_CALLBACK_FLAG::DRAW), maxon::UInt64(enum65::RENDER_CALLBACK_FLAG::FIRST), maxon::UInt64(enum65::RENDER_CALLBACK_FLAG::CALCVOL), maxon::UInt64(enum65::RENDER_CALLBACK_FLAG::CALCVOL_EXIT)};
		static const maxon::EnumInfo RENDER_CALLBACK_FLAG_info{"RENDER_CALLBACK_FLAG", SIZEOF(RENDER_CALLBACK_FLAG), true, "NONE\0DRAW\0FIRST\0CALCVOL\0CALCVOL_EXIT\0", RENDER_CALLBACK_FLAG_values, std::extent<decltype(RENDER_CALLBACK_FLAG_values)>::value};
	}
	const maxon::EnumInfo& PrivateGetEnumInfo_RENDER_CALLBACK_FLAG65(){ return enum65::RENDER_CALLBACK_FLAG_info; }
	namespace enum74
	{
		enum class RENDER_CALLBACK_RETURN_FLAG
		{
			NONE = 0,
			EXIT = (1 << 0),
			SKIP_Z = (1 << 1),
			SKIP_SET = (1 << 2),
			SAMPLED = (1 << 3),
		} ;
		static const maxon::UInt64 RENDER_CALLBACK_RETURN_FLAG_values[] = {maxon::UInt64(enum74::RENDER_CALLBACK_RETURN_FLAG::NONE), maxon::UInt64(enum74::RENDER_CALLBACK_RETURN_FLAG::EXIT), maxon::UInt64(enum74::RENDER_CALLBACK_RETURN_FLAG::SKIP_Z), maxon::UInt64(enum74::RENDER_CALLBACK_RETURN_FLAG::SKIP_SET), maxon::UInt64(enum74::RENDER_CALLBACK_RETURN_FLAG::SAMPLED)};
		static const maxon::EnumInfo RENDER_CALLBACK_RETURN_FLAG_info{"RENDER_CALLBACK_RETURN_FLAG", SIZEOF(RENDER_CALLBACK_RETURN_FLAG), true, "NONE\0EXIT\0SKIP_Z\0SKIP_SET\0SAMPLED\0", RENDER_CALLBACK_RETURN_FLAG_values, std::extent<decltype(RENDER_CALLBACK_RETURN_FLAG_values)>::value};
	}
	const maxon::EnumInfo& PrivateGetEnumInfo_RENDER_CALLBACK_RETURN_FLAG74(){ return enum74::RENDER_CALLBACK_RETURN_FLAG_info; }
	namespace enum95
	{
		enum class OBJECT_FLAG
		{
			NONE = 0,
			NORMALS = (1 << 0),
			WORLD_THICKNESS = (1 << 1),
			CUSTOM_THICKNESS = (1 << 2),
			CUSTOM_WORLD_THICKNESS = (1 << 3),
			NO_SHADOWS = (1 << 4),
			NO_REFRACTION = (1 << 5),
			NO_REFLECTION = (1 << 6),
			NO_PRECULL = (1 << 7),
			REQUEST_SCREEN = (1 << 8),
			REQUEST_WORLD = (1 << 9),
			REQUEST_CAMERA = (1 << 10),
			REQUEST_TANGENTS = (1 << 11),
			VERTEX_COL_SAMPLING = (1 << 12),
			SAMPLING_AA = (1 << 13),
			RAYTRACED = (1 << 14),
			MP_NO_DEPTH = (1 << 15)
		} ;
		static const maxon::UInt64 OBJECT_FLAG_values[] = {maxon::UInt64(enum95::OBJECT_FLAG::NONE), maxon::UInt64(enum95::OBJECT_FLAG::NORMALS), maxon::UInt64(enum95::OBJECT_FLAG::WORLD_THICKNESS), maxon::UInt64(enum95::OBJECT_FLAG::CUSTOM_THICKNESS), maxon::UInt64(enum95::OBJECT_FLAG::CUSTOM_WORLD_THICKNESS), maxon::UInt64(enum95::OBJECT_FLAG::NO_SHADOWS), maxon::UInt64(enum95::OBJECT_FLAG::NO_REFRACTION), maxon::UInt64(enum95::OBJECT_FLAG::NO_REFLECTION), maxon::UInt64(enum95::OBJECT_FLAG::NO_PRECULL), maxon::UInt64(enum95::OBJECT_FLAG::REQUEST_SCREEN), maxon::UInt64(enum95::OBJECT_FLAG::REQUEST_WORLD), maxon::UInt64(enum95::OBJECT_FLAG::REQUEST_CAMERA), maxon::UInt64(enum95::OBJECT_FLAG::REQUEST_TANGENTS), maxon::UInt64(enum95::OBJECT_FLAG::VERTEX_COL_SAMPLING), maxon::UInt64(enum95::OBJECT_FLAG::SAMPLING_AA), maxon::UInt64(enum95::OBJECT_FLAG::RAYTRACED), maxon::UInt64(enum95::OBJECT_FLAG::MP_NO_DEPTH)};
		static const maxon::EnumInfo OBJECT_FLAG_info{"OBJECT_FLAG", SIZEOF(OBJECT_FLAG), true, "NONE\0NORMALS\0WORLD_THICKNESS\0CUSTOM_THICKNESS\0CUSTOM_WORLD_THICKNESS\0NO_SHADOWS\0NO_REFRACTION\0NO_REFLECTION\0NO_PRECULL\0REQUEST_SCREEN\0REQUEST_WORLD\0REQUEST_CAMERA\0REQUEST_TANGENTS\0VERTEX_COL_SAMPLING\0SAMPLING_AA\0RAYTRACED\0MP_NO_DEPTH\0", OBJECT_FLAG_values, std::extent<decltype(OBJECT_FLAG_values)>::value};
	}
	const maxon::EnumInfo& PrivateGetEnumInfo_OBJECT_FLAG95(){ return enum95::OBJECT_FLAG_info; }
	namespace enum105
	{
		enum class COORD_SPACE
		{
			NONE = 0,
			LOCAL = 1,
			WORLD,
			CAMERA,
			SCREEN,
			CUSTOM
		} ;
		static const maxon::UInt64 COORD_SPACE_values[] = {maxon::UInt64(enum105::COORD_SPACE::NONE), maxon::UInt64(enum105::COORD_SPACE::LOCAL), maxon::UInt64(enum105::COORD_SPACE::WORLD), maxon::UInt64(enum105::COORD_SPACE::CAMERA), maxon::UInt64(enum105::COORD_SPACE::SCREEN), maxon::UInt64(enum105::COORD_SPACE::CUSTOM)};
		static const maxon::EnumInfo COORD_SPACE_info{"COORD_SPACE", SIZEOF(COORD_SPACE), false, "NONE\0LOCAL\0WORLD\0CAMERA\0SCREEN\0CUSTOM\0", COORD_SPACE_values, std::extent<decltype(COORD_SPACE_values)>::value};
	}
	const maxon::EnumInfo& PrivateGetEnumInfo_COORD_SPACE105(){ return enum105::COORD_SPACE_info; }
	namespace enum113
	{
		enum class JOINT_TYPE
		{
			NONE = 0,
			BEVEL = 1,
			ROUND,
			MITER
		} ;
		static const maxon::UInt64 JOINT_TYPE_values[] = {maxon::UInt64(enum113::JOINT_TYPE::NONE), maxon::UInt64(enum113::JOINT_TYPE::BEVEL), maxon::UInt64(enum113::JOINT_TYPE::ROUND), maxon::UInt64(enum113::JOINT_TYPE::MITER)};
		static const maxon::EnumInfo JOINT_TYPE_info{"JOINT_TYPE", SIZEOF(JOINT_TYPE), false, "NONE\0BEVEL\0ROUND\0MITER\0", JOINT_TYPE_values, std::extent<decltype(JOINT_TYPE_values)>::value};
	}
	const maxon::EnumInfo& PrivateGetEnumInfo_JOINT_TYPE113(){ return enum113::JOINT_TYPE_info; }
	namespace enum119
	{
		enum class INTERPOLATION_TYPE
		{
			NONE = 0,
			LINEAR = 1
		} ;
		static const maxon::UInt64 INTERPOLATION_TYPE_values[] = {maxon::UInt64(enum119::INTERPOLATION_TYPE::NONE), maxon::UInt64(enum119::INTERPOLATION_TYPE::LINEAR)};
		static const maxon::EnumInfo INTERPOLATION_TYPE_info{"INTERPOLATION_TYPE", SIZEOF(INTERPOLATION_TYPE), false, "NONE\0LINEAR\0", INTERPOLATION_TYPE_values, std::extent<decltype(INTERPOLATION_TYPE_values)>::value};
	}
	const maxon::EnumInfo& PrivateGetEnumInfo_INTERPOLATION_TYPE119(){ return enum119::INTERPOLATION_TYPE_info; }
	namespace enum130
	{
		enum class CAP_TYPE
		{
			NONE = 0,
			ROUND = 1,
			FLAT,
			SQUARE,
			LINEAR,
			ARROW,
			CUSTOM
		} ;
		static const maxon::UInt64 CAP_TYPE_values[] = {maxon::UInt64(enum130::CAP_TYPE::NONE), maxon::UInt64(enum130::CAP_TYPE::ROUND), maxon::UInt64(enum130::CAP_TYPE::FLAT), maxon::UInt64(enum130::CAP_TYPE::SQUARE), maxon::UInt64(enum130::CAP_TYPE::LINEAR), maxon::UInt64(enum130::CAP_TYPE::ARROW), maxon::UInt64(enum130::CAP_TYPE::CUSTOM)};
		static const maxon::EnumInfo CAP_TYPE_info{"CAP_TYPE", SIZEOF(CAP_TYPE), false, "NONE\0ROUND\0FLAT\0SQUARE\0LINEAR\0ARROW\0CUSTOM\0", CAP_TYPE_values, std::extent<decltype(CAP_TYPE_values)>::value};
	}
	const maxon::EnumInfo& PrivateGetEnumInfo_CAP_TYPE130(){ return enum130::CAP_TYPE_info; }
	namespace enum140
	{
		enum class RENDER_TYPE
		{
			NONE = 0,
			RASTER = 1,
			CONE,
			RAY,
			RASTER_TILES,
			RASTER_NO_MP,
		} ;
		static const maxon::UInt64 RENDER_TYPE_values[] = {maxon::UInt64(enum140::RENDER_TYPE::NONE), maxon::UInt64(enum140::RENDER_TYPE::RASTER), maxon::UInt64(enum140::RENDER_TYPE::CONE), maxon::UInt64(enum140::RENDER_TYPE::RAY), maxon::UInt64(enum140::RENDER_TYPE::RASTER_TILES), maxon::UInt64(enum140::RENDER_TYPE::RASTER_NO_MP)};
		static const maxon::EnumInfo RENDER_TYPE_info{"RENDER_TYPE", SIZEOF(RENDER_TYPE), false, "NONE\0RASTER\0CONE\0RAY\0RASTER_TILES\0RASTER_NO_MP\0", RENDER_TYPE_values, std::extent<decltype(RENDER_TYPE_values)>::value};
	}
	const maxon::EnumInfo& PrivateGetEnumInfo_RENDER_TYPE140(){ return enum140::RENDER_TYPE_info; }
	namespace enum148
	{
		enum class SHADOW_TYPE
		{
			NONE = 0,
			AUTO = 1,
			SOFT,
			HARD,
		} ;
		static const maxon::UInt64 SHADOW_TYPE_values[] = {maxon::UInt64(enum148::SHADOW_TYPE::NONE), maxon::UInt64(enum148::SHADOW_TYPE::AUTO), maxon::UInt64(enum148::SHADOW_TYPE::SOFT), maxon::UInt64(enum148::SHADOW_TYPE::HARD)};
		static const maxon::EnumInfo SHADOW_TYPE_info{"SHADOW_TYPE", SIZEOF(SHADOW_TYPE), false, "NONE\0AUTO\0SOFT\0HARD\0", SHADOW_TYPE_values, std::extent<decltype(SHADOW_TYPE_values)>::value};
	}
	const maxon::EnumInfo& PrivateGetEnumInfo_SHADOW_TYPE148(){ return enum148::SHADOW_TYPE_info; }
	namespace enum164
	{
		enum class RENDER_FLAG
		{
			NONE = 0,
			RENDER_CALLBACK = (1 << 0),
			RENDER_ALPHA_ONLY = (1 << 1),
			RENDER_NO_TRACER = (1 << 2),
			RENDER_BLENDING = (1 << 3),
			RENDER_SHADOWS = (1 << 4),
			RENDER_ERROR = (1 << 5),
			RENDER_UNINIT = (1 << 6),
			RENDER_REFRACTION = (1 << 7),
			RENDER_REFLECTION = (1 << 8),
			RENDER_BUCKETS = (1 << 9),
			RENDER_READY = (1 << 10)
		} ;
		static const maxon::UInt64 RENDER_FLAG_values[] = {maxon::UInt64(enum164::RENDER_FLAG::NONE), maxon::UInt64(enum164::RENDER_FLAG::RENDER_CALLBACK), maxon::UInt64(enum164::RENDER_FLAG::RENDER_ALPHA_ONLY), maxon::UInt64(enum164::RENDER_FLAG::RENDER_NO_TRACER), maxon::UInt64(enum164::RENDER_FLAG::RENDER_BLENDING), maxon::UInt64(enum164::RENDER_FLAG::RENDER_SHADOWS), maxon::UInt64(enum164::RENDER_FLAG::RENDER_ERROR), maxon::UInt64(enum164::RENDER_FLAG::RENDER_UNINIT), maxon::UInt64(enum164::RENDER_FLAG::RENDER_REFRACTION), maxon::UInt64(enum164::RENDER_FLAG::RENDER_REFLECTION), maxon::UInt64(enum164::RENDER_FLAG::RENDER_BUCKETS), maxon::UInt64(enum164::RENDER_FLAG::RENDER_READY)};
		static const maxon::EnumInfo RENDER_FLAG_info{"RENDER_FLAG", SIZEOF(RENDER_FLAG), true, "NONE\0RENDER_CALLBACK\0RENDER_ALPHA_ONLY\0RENDER_NO_TRACER\0RENDER_BLENDING\0RENDER_SHADOWS\0RENDER_ERROR\0RENDER_UNINIT\0RENDER_REFRACTION\0RENDER_REFLECTION\0RENDER_BUCKETS\0RENDER_READY\0", RENDER_FLAG_values, std::extent<decltype(RENDER_FLAG_values)>::value};
	}
	const maxon::EnumInfo& PrivateGetEnumInfo_RENDER_FLAG164(){ return enum164::RENDER_FLAG_info; }
	namespace enum199
	{
		enum class BLEND_MODE
		{
			NONE = 0,
			AVERAGE = 1,
			NORMAL,
			MULTIPLY,
			SCREEN,
			DARKEN,
			LIGHT,
			DIFFERENCE,
			NEGATIVE,
			EXCLUSION,
			OVERLAY,
			HARDLIGHT,
			SOFTLIGHT,
			DODGE,
			BURN,
			REFLECT,
			GLOW,
			FREEZE,
			HEAT,
			ADD,
			SUB,
			STAMP,
			XOR,
			HUE,
			SATURATION,
			LUMINANCE,
			RED,
			GREEN,
			BLUE,
			OVERWRITE,
			LEVR,
		} ;
		static const maxon::UInt64 BLEND_MODE_values[] = {maxon::UInt64(enum199::BLEND_MODE::NONE), maxon::UInt64(enum199::BLEND_MODE::AVERAGE), maxon::UInt64(enum199::BLEND_MODE::NORMAL), maxon::UInt64(enum199::BLEND_MODE::MULTIPLY), maxon::UInt64(enum199::BLEND_MODE::SCREEN), maxon::UInt64(enum199::BLEND_MODE::DARKEN), maxon::UInt64(enum199::BLEND_MODE::LIGHT), maxon::UInt64(enum199::BLEND_MODE::DIFFERENCE), maxon::UInt64(enum199::BLEND_MODE::NEGATIVE), maxon::UInt64(enum199::BLEND_MODE::EXCLUSION), maxon::UInt64(enum199::BLEND_MODE::OVERLAY), maxon::UInt64(enum199::BLEND_MODE::HARDLIGHT), maxon::UInt64(enum199::BLEND_MODE::SOFTLIGHT), maxon::UInt64(enum199::BLEND_MODE::DODGE), maxon::UInt64(enum199::BLEND_MODE::BURN), maxon::UInt64(enum199::BLEND_MODE::REFLECT), maxon::UInt64(enum199::BLEND_MODE::GLOW), maxon::UInt64(enum199::BLEND_MODE::FREEZE), maxon::UInt64(enum199::BLEND_MODE::HEAT), maxon::UInt64(enum199::BLEND_MODE::ADD), maxon::UInt64(enum199::BLEND_MODE::SUB), maxon::UInt64(enum199::BLEND_MODE::STAMP), maxon::UInt64(enum199::BLEND_MODE::XOR), maxon::UInt64(enum199::BLEND_MODE::HUE), maxon::UInt64(enum199::BLEND_MODE::SATURATION), maxon::UInt64(enum199::BLEND_MODE::LUMINANCE), maxon::UInt64(enum199::BLEND_MODE::RED), maxon::UInt64(enum199::BLEND_MODE::GREEN), maxon::UInt64(enum199::BLEND_MODE::BLUE), maxon::UInt64(enum199::BLEND_MODE::OVERWRITE), maxon::UInt64(enum199::BLEND_MODE::LEVR)};
		static const maxon::EnumInfo BLEND_MODE_info{"BLEND_MODE", SIZEOF(BLEND_MODE), false, "NONE\0AVERAGE\0NORMAL\0MULTIPLY\0SCREEN\0DARKEN\0LIGHT\0DIFFERENCE\0NEGATIVE\0EXCLUSION\0OVERLAY\0HARDLIGHT\0SOFTLIGHT\0DODGE\0BURN\0REFLECT\0GLOW\0FREEZE\0HEAT\0ADD\0SUB\0STAMP\0XOR\0HUE\0SATURATION\0LUMINANCE\0RED\0GREEN\0BLUE\0OVERWRITE\0LEVR\0", BLEND_MODE_values, std::extent<decltype(BLEND_MODE_values)>::value};
	}
	const maxon::EnumInfo& PrivateGetEnumInfo_BLEND_MODE199(){ return enum199::BLEND_MODE_info; }
	namespace enum211
	{
		enum class RENDERDATA_FLAG
		{
			NONE = 0,
			SCREEN = (1 << 0),
			WORLD = (1 << 1),
			CAMERA = (1 << 2),
			LINE = (1 << 3),
			TRACING = (1 << 4),
			REDUCED = (1 << 5),
			TANGENT = (1 << 6),
		} ;
		static const maxon::UInt64 RENDERDATA_FLAG_values[] = {maxon::UInt64(enum211::RENDERDATA_FLAG::NONE), maxon::UInt64(enum211::RENDERDATA_FLAG::SCREEN), maxon::UInt64(enum211::RENDERDATA_FLAG::WORLD), maxon::UInt64(enum211::RENDERDATA_FLAG::CAMERA), maxon::UInt64(enum211::RENDERDATA_FLAG::LINE), maxon::UInt64(enum211::RENDERDATA_FLAG::TRACING), maxon::UInt64(enum211::RENDERDATA_FLAG::REDUCED), maxon::UInt64(enum211::RENDERDATA_FLAG::TANGENT)};
		static const maxon::EnumInfo RENDERDATA_FLAG_info{"RENDERDATA_FLAG", SIZEOF(RENDERDATA_FLAG), true, "NONE\0SCREEN\0WORLD\0CAMERA\0LINE\0TRACING\0REDUCED\0TANGENT\0", RENDERDATA_FLAG_values, std::extent<decltype(RENDERDATA_FLAG_values)>::value};
	}
	const maxon::EnumInfo& PrivateGetEnumInfo_RENDERDATA_FLAG211(){ return enum211::RENDERDATA_FLAG_info; }
	namespace enum218
	{
		enum class SETCURVE_FLAGS
		{
			NONE = 0,
			CLONE = (1 << 0),
			OWN = (1 << 1)
		} ;
		static const maxon::UInt64 SETCURVE_FLAGS_values[] = {maxon::UInt64(enum218::SETCURVE_FLAGS::NONE), maxon::UInt64(enum218::SETCURVE_FLAGS::CLONE), maxon::UInt64(enum218::SETCURVE_FLAGS::OWN)};
		static const maxon::EnumInfo SETCURVE_FLAGS_info{"SETCURVE_FLAGS", SIZEOF(SETCURVE_FLAGS), true, "NONE\0CLONE\0OWN\0", SETCURVE_FLAGS_values, std::extent<decltype(SETCURVE_FLAGS_values)>::value};
	}
	const maxon::EnumInfo& PrivateGetEnumInfo_SETCURVE_FLAGS218(){ return enum218::SETCURVE_FLAGS_info; }
	namespace enum227
	{
		enum class MPBUFFER_FLAGS
		{
			NONE = 0,
			MUL = (1 << 0),
			DEPTH = (1 << 1),
			ALPHA = (1 << 2),
			INVERT = (1 << 3),
		} ;
		static const maxon::UInt64 MPBUFFER_FLAGS_values[] = {maxon::UInt64(enum227::MPBUFFER_FLAGS::NONE), maxon::UInt64(enum227::MPBUFFER_FLAGS::MUL), maxon::UInt64(enum227::MPBUFFER_FLAGS::DEPTH), maxon::UInt64(enum227::MPBUFFER_FLAGS::ALPHA), maxon::UInt64(enum227::MPBUFFER_FLAGS::INVERT)};
		static const maxon::EnumInfo MPBUFFER_FLAGS_info{"MPBUFFER_FLAGS", SIZEOF(MPBUFFER_FLAGS), true, "NONE\0MUL\0DEPTH\0ALPHA\0INVERT\0", MPBUFFER_FLAGS_values, std::extent<decltype(MPBUFFER_FLAGS_values)>::value};
	}
	const maxon::EnumInfo& PrivateGetEnumInfo_MPBUFFER_FLAGS227(){ return enum227::MPBUFFER_FLAGS_info; }
}
#ifndef __API_INTERN__
#else
#endif
#ifdef CINEWARE_NAMESPACE_ENABLE
CINEWARE_NAMESPACE_END
#endif
#endif
