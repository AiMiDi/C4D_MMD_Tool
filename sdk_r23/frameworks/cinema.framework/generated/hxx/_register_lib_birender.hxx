#if 1
#ifdef __API_INTERN__
#else
#endif
#ifdef CINEWARE_NAMESPACE_ENABLE
CINEWARE_NAMESPACE_BEGIN
#endif
namespace birender
{
	namespace enum46 { enum class FLAG_STATE
	{
		NONE	= 0,
		ADD		= 1,
		DEL		= 2,
		SET		= 3,
	} ; }
	maxon::String PrivateToString_FLAG_STATE46(std::underlying_type<enum46::FLAG_STATE>::type x, const maxon::FormatStatement* fmt)
	{
		const maxon::UInt64 values[] = {(maxon::UInt64) enum46::FLAG_STATE::NONE, (maxon::UInt64) enum46::FLAG_STATE::ADD, (maxon::UInt64) enum46::FLAG_STATE::DEL, (maxon::UInt64) enum46::FLAG_STATE::SET};
		return maxon::StringInterface::PrivateEnumToString((maxon::UInt64) x, "FLAG_STATE", SIZEOF(x), false, values, "NONE\0ADD\0DEL\0SET\0", fmt);
	}
	namespace enum56 { enum class SHADING_CALLBACK_FLAG
	{
		NONE = 0,
		INIT = (1 << 0),
		EXIT = (1 << 1),
		SHADER = (1 << 2),
		THICKNESS = (1 << 3),
		SHADOWS = (1 << 4)
	} ; }
	maxon::String PrivateToString_SHADING_CALLBACK_FLAG56(std::underlying_type<enum56::SHADING_CALLBACK_FLAG>::type x, const maxon::FormatStatement* fmt)
	{
		const maxon::UInt64 values[] = {(maxon::UInt64) enum56::SHADING_CALLBACK_FLAG::NONE, (maxon::UInt64) enum56::SHADING_CALLBACK_FLAG::INIT, (maxon::UInt64) enum56::SHADING_CALLBACK_FLAG::EXIT, (maxon::UInt64) enum56::SHADING_CALLBACK_FLAG::SHADER, (maxon::UInt64) enum56::SHADING_CALLBACK_FLAG::THICKNESS, (maxon::UInt64) enum56::SHADING_CALLBACK_FLAG::SHADOWS};
		return maxon::StringInterface::PrivateEnumToString((maxon::UInt64) x, "SHADING_CALLBACK_FLAG", SIZEOF(x), true, values, "NONE\0INIT\0EXIT\0SHADER\0THICKNESS\0SHADOWS\0", fmt);
	}
	namespace enum65 { enum class RENDER_CALLBACK_FLAG
	{
		NONE = 0,
		DRAW = (1 << 0),
		FIRST = (1 << 1),
		CALCVOL = (1 << 2),
		CALCVOL_EXIT = (1 << 3)
	} ; }
	maxon::String PrivateToString_RENDER_CALLBACK_FLAG65(std::underlying_type<enum65::RENDER_CALLBACK_FLAG>::type x, const maxon::FormatStatement* fmt)
	{
		const maxon::UInt64 values[] = {(maxon::UInt64) enum65::RENDER_CALLBACK_FLAG::NONE, (maxon::UInt64) enum65::RENDER_CALLBACK_FLAG::DRAW, (maxon::UInt64) enum65::RENDER_CALLBACK_FLAG::FIRST, (maxon::UInt64) enum65::RENDER_CALLBACK_FLAG::CALCVOL, (maxon::UInt64) enum65::RENDER_CALLBACK_FLAG::CALCVOL_EXIT};
		return maxon::StringInterface::PrivateEnumToString((maxon::UInt64) x, "RENDER_CALLBACK_FLAG", SIZEOF(x), true, values, "NONE\0DRAW\0FIRST\0CALCVOL\0CALCVOL_EXIT\0", fmt);
	}
	namespace enum74 { enum class RENDER_CALLBACK_RETURN_FLAG
	{
		NONE = 0,
		EXIT = (1 << 0),
		SKIP_Z = (1 << 1),
		SKIP_SET = (1 << 2),
		SAMPLED = (1 << 3),
	} ; }
	maxon::String PrivateToString_RENDER_CALLBACK_RETURN_FLAG74(std::underlying_type<enum74::RENDER_CALLBACK_RETURN_FLAG>::type x, const maxon::FormatStatement* fmt)
	{
		const maxon::UInt64 values[] = {(maxon::UInt64) enum74::RENDER_CALLBACK_RETURN_FLAG::NONE, (maxon::UInt64) enum74::RENDER_CALLBACK_RETURN_FLAG::EXIT, (maxon::UInt64) enum74::RENDER_CALLBACK_RETURN_FLAG::SKIP_Z, (maxon::UInt64) enum74::RENDER_CALLBACK_RETURN_FLAG::SKIP_SET, (maxon::UInt64) enum74::RENDER_CALLBACK_RETURN_FLAG::SAMPLED};
		return maxon::StringInterface::PrivateEnumToString((maxon::UInt64) x, "RENDER_CALLBACK_RETURN_FLAG", SIZEOF(x), true, values, "NONE\0EXIT\0SKIP_Z\0SKIP_SET\0SAMPLED\0", fmt);
	}
	namespace enum95 { enum class OBJECT_FLAG
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
	} ; }
	maxon::String PrivateToString_OBJECT_FLAG95(std::underlying_type<enum95::OBJECT_FLAG>::type x, const maxon::FormatStatement* fmt)
	{
		const maxon::UInt64 values[] = {(maxon::UInt64) enum95::OBJECT_FLAG::NONE, (maxon::UInt64) enum95::OBJECT_FLAG::NORMALS, (maxon::UInt64) enum95::OBJECT_FLAG::WORLD_THICKNESS, (maxon::UInt64) enum95::OBJECT_FLAG::CUSTOM_THICKNESS, (maxon::UInt64) enum95::OBJECT_FLAG::CUSTOM_WORLD_THICKNESS, (maxon::UInt64) enum95::OBJECT_FLAG::NO_SHADOWS, (maxon::UInt64) enum95::OBJECT_FLAG::NO_REFRACTION, (maxon::UInt64) enum95::OBJECT_FLAG::NO_REFLECTION, (maxon::UInt64) enum95::OBJECT_FLAG::NO_PRECULL, (maxon::UInt64) enum95::OBJECT_FLAG::REQUEST_SCREEN, (maxon::UInt64) enum95::OBJECT_FLAG::REQUEST_WORLD, (maxon::UInt64) enum95::OBJECT_FLAG::REQUEST_CAMERA, (maxon::UInt64) enum95::OBJECT_FLAG::REQUEST_TANGENTS, (maxon::UInt64) enum95::OBJECT_FLAG::VERTEX_COL_SAMPLING, (maxon::UInt64) enum95::OBJECT_FLAG::SAMPLING_AA, (maxon::UInt64) enum95::OBJECT_FLAG::RAYTRACED, (maxon::UInt64) enum95::OBJECT_FLAG::MP_NO_DEPTH};
		return maxon::StringInterface::PrivateEnumToString((maxon::UInt64) x, "OBJECT_FLAG", SIZEOF(x), true, values, "NONE\0NORMALS\0WORLD_THICKNESS\0CUSTOM_THICKNESS\0CUSTOM_WORLD_THICKNESS\0NO_SHADOWS\0NO_REFRACTION\0NO_REFLECTION\0NO_PRECULL\0REQUEST_SCREEN\0REQUEST_WORLD\0REQUEST_CAMERA\0REQUEST_TANGENTS\0VERTEX_COL_SAMPLING\0SAMPLING_AA\0RAYTRACED\0MP_NO_DEPTH\0", fmt);
	}
	namespace enum105 { enum class COORD_SPACE
	{
		NONE = 0,
		LOCAL = 1,
		WORLD,
		CAMERA,
		SCREEN,
		CUSTOM
	} ; }
	maxon::String PrivateToString_COORD_SPACE105(std::underlying_type<enum105::COORD_SPACE>::type x, const maxon::FormatStatement* fmt)
	{
		const maxon::UInt64 values[] = {(maxon::UInt64) enum105::COORD_SPACE::NONE, (maxon::UInt64) enum105::COORD_SPACE::LOCAL, (maxon::UInt64) enum105::COORD_SPACE::WORLD, (maxon::UInt64) enum105::COORD_SPACE::CAMERA, (maxon::UInt64) enum105::COORD_SPACE::SCREEN, (maxon::UInt64) enum105::COORD_SPACE::CUSTOM};
		return maxon::StringInterface::PrivateEnumToString((maxon::UInt64) x, "COORD_SPACE", SIZEOF(x), false, values, "NONE\0LOCAL\0WORLD\0CAMERA\0SCREEN\0CUSTOM\0", fmt);
	}
	namespace enum113 { enum class JOINT_TYPE
	{
		NONE = 0,
		BEVEL = 1,
		ROUND,
		MITER
	} ; }
	maxon::String PrivateToString_JOINT_TYPE113(std::underlying_type<enum113::JOINT_TYPE>::type x, const maxon::FormatStatement* fmt)
	{
		const maxon::UInt64 values[] = {(maxon::UInt64) enum113::JOINT_TYPE::NONE, (maxon::UInt64) enum113::JOINT_TYPE::BEVEL, (maxon::UInt64) enum113::JOINT_TYPE::ROUND, (maxon::UInt64) enum113::JOINT_TYPE::MITER};
		return maxon::StringInterface::PrivateEnumToString((maxon::UInt64) x, "JOINT_TYPE", SIZEOF(x), false, values, "NONE\0BEVEL\0ROUND\0MITER\0", fmt);
	}
	namespace enum119 { enum class INTERPOLATION_TYPE
	{
		NONE = 0,
		LINEAR = 1
	} ; }
	maxon::String PrivateToString_INTERPOLATION_TYPE119(std::underlying_type<enum119::INTERPOLATION_TYPE>::type x, const maxon::FormatStatement* fmt)
	{
		const maxon::UInt64 values[] = {(maxon::UInt64) enum119::INTERPOLATION_TYPE::NONE, (maxon::UInt64) enum119::INTERPOLATION_TYPE::LINEAR};
		return maxon::StringInterface::PrivateEnumToString((maxon::UInt64) x, "INTERPOLATION_TYPE", SIZEOF(x), false, values, "NONE\0LINEAR\0", fmt);
	}
	namespace enum130 { enum class CAP_TYPE
	{
		NONE = 0,
		ROUND = 1,
		FLAT,
		SQUARE,
		LINEAR,
		ARROW,
		CUSTOM
	} ; }
	maxon::String PrivateToString_CAP_TYPE130(std::underlying_type<enum130::CAP_TYPE>::type x, const maxon::FormatStatement* fmt)
	{
		const maxon::UInt64 values[] = {(maxon::UInt64) enum130::CAP_TYPE::NONE, (maxon::UInt64) enum130::CAP_TYPE::ROUND, (maxon::UInt64) enum130::CAP_TYPE::FLAT, (maxon::UInt64) enum130::CAP_TYPE::SQUARE, (maxon::UInt64) enum130::CAP_TYPE::LINEAR, (maxon::UInt64) enum130::CAP_TYPE::ARROW, (maxon::UInt64) enum130::CAP_TYPE::CUSTOM};
		return maxon::StringInterface::PrivateEnumToString((maxon::UInt64) x, "CAP_TYPE", SIZEOF(x), false, values, "NONE\0ROUND\0FLAT\0SQUARE\0LINEAR\0ARROW\0CUSTOM\0", fmt);
	}
	namespace enum140 { enum class RENDER_TYPE
	{
		NONE = 0,
		RASTER = 1,
		CONE,
		RAY,
		RASTER_TILES,
		RASTER_NO_MP,
	} ; }
	maxon::String PrivateToString_RENDER_TYPE140(std::underlying_type<enum140::RENDER_TYPE>::type x, const maxon::FormatStatement* fmt)
	{
		const maxon::UInt64 values[] = {(maxon::UInt64) enum140::RENDER_TYPE::NONE, (maxon::UInt64) enum140::RENDER_TYPE::RASTER, (maxon::UInt64) enum140::RENDER_TYPE::CONE, (maxon::UInt64) enum140::RENDER_TYPE::RAY, (maxon::UInt64) enum140::RENDER_TYPE::RASTER_TILES, (maxon::UInt64) enum140::RENDER_TYPE::RASTER_NO_MP};
		return maxon::StringInterface::PrivateEnumToString((maxon::UInt64) x, "RENDER_TYPE", SIZEOF(x), false, values, "NONE\0RASTER\0CONE\0RAY\0RASTER_TILES\0RASTER_NO_MP\0", fmt);
	}
	namespace enum148 { enum class SHADOW_TYPE
	{
		NONE = 0,
		AUTO = 1,
		SOFT,
		HARD,
	} ; }
	maxon::String PrivateToString_SHADOW_TYPE148(std::underlying_type<enum148::SHADOW_TYPE>::type x, const maxon::FormatStatement* fmt)
	{
		const maxon::UInt64 values[] = {(maxon::UInt64) enum148::SHADOW_TYPE::NONE, (maxon::UInt64) enum148::SHADOW_TYPE::AUTO, (maxon::UInt64) enum148::SHADOW_TYPE::SOFT, (maxon::UInt64) enum148::SHADOW_TYPE::HARD};
		return maxon::StringInterface::PrivateEnumToString((maxon::UInt64) x, "SHADOW_TYPE", SIZEOF(x), false, values, "NONE\0AUTO\0SOFT\0HARD\0", fmt);
	}
	namespace enum164 { enum class RENDER_FLAG
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
	} ; }
	maxon::String PrivateToString_RENDER_FLAG164(std::underlying_type<enum164::RENDER_FLAG>::type x, const maxon::FormatStatement* fmt)
	{
		const maxon::UInt64 values[] = {(maxon::UInt64) enum164::RENDER_FLAG::NONE, (maxon::UInt64) enum164::RENDER_FLAG::RENDER_CALLBACK, (maxon::UInt64) enum164::RENDER_FLAG::RENDER_ALPHA_ONLY, (maxon::UInt64) enum164::RENDER_FLAG::RENDER_NO_TRACER, (maxon::UInt64) enum164::RENDER_FLAG::RENDER_BLENDING, (maxon::UInt64) enum164::RENDER_FLAG::RENDER_SHADOWS, (maxon::UInt64) enum164::RENDER_FLAG::RENDER_ERROR, (maxon::UInt64) enum164::RENDER_FLAG::RENDER_UNINIT, (maxon::UInt64) enum164::RENDER_FLAG::RENDER_REFRACTION, (maxon::UInt64) enum164::RENDER_FLAG::RENDER_REFLECTION, (maxon::UInt64) enum164::RENDER_FLAG::RENDER_BUCKETS, (maxon::UInt64) enum164::RENDER_FLAG::RENDER_READY};
		return maxon::StringInterface::PrivateEnumToString((maxon::UInt64) x, "RENDER_FLAG", SIZEOF(x), true, values, "NONE\0RENDER_CALLBACK\0RENDER_ALPHA_ONLY\0RENDER_NO_TRACER\0RENDER_BLENDING\0RENDER_SHADOWS\0RENDER_ERROR\0RENDER_UNINIT\0RENDER_REFRACTION\0RENDER_REFLECTION\0RENDER_BUCKETS\0RENDER_READY\0", fmt);
	}
	namespace enum199 { enum class BLEND_MODE
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
	} ; }
	maxon::String PrivateToString_BLEND_MODE199(std::underlying_type<enum199::BLEND_MODE>::type x, const maxon::FormatStatement* fmt)
	{
		const maxon::UInt64 values[] = {(maxon::UInt64) enum199::BLEND_MODE::NONE, (maxon::UInt64) enum199::BLEND_MODE::AVERAGE, (maxon::UInt64) enum199::BLEND_MODE::NORMAL, (maxon::UInt64) enum199::BLEND_MODE::MULTIPLY, (maxon::UInt64) enum199::BLEND_MODE::SCREEN, (maxon::UInt64) enum199::BLEND_MODE::DARKEN, (maxon::UInt64) enum199::BLEND_MODE::LIGHT, (maxon::UInt64) enum199::BLEND_MODE::DIFFERENCE, (maxon::UInt64) enum199::BLEND_MODE::NEGATIVE, (maxon::UInt64) enum199::BLEND_MODE::EXCLUSION, (maxon::UInt64) enum199::BLEND_MODE::OVERLAY, (maxon::UInt64) enum199::BLEND_MODE::HARDLIGHT, (maxon::UInt64) enum199::BLEND_MODE::SOFTLIGHT, (maxon::UInt64) enum199::BLEND_MODE::DODGE, (maxon::UInt64) enum199::BLEND_MODE::BURN, (maxon::UInt64) enum199::BLEND_MODE::REFLECT, (maxon::UInt64) enum199::BLEND_MODE::GLOW, (maxon::UInt64) enum199::BLEND_MODE::FREEZE, (maxon::UInt64) enum199::BLEND_MODE::HEAT, (maxon::UInt64) enum199::BLEND_MODE::ADD, (maxon::UInt64) enum199::BLEND_MODE::SUB, (maxon::UInt64) enum199::BLEND_MODE::STAMP, (maxon::UInt64) enum199::BLEND_MODE::XOR, (maxon::UInt64) enum199::BLEND_MODE::HUE, (maxon::UInt64) enum199::BLEND_MODE::SATURATION, (maxon::UInt64) enum199::BLEND_MODE::LUMINANCE, (maxon::UInt64) enum199::BLEND_MODE::RED, (maxon::UInt64) enum199::BLEND_MODE::GREEN, (maxon::UInt64) enum199::BLEND_MODE::BLUE, (maxon::UInt64) enum199::BLEND_MODE::OVERWRITE, (maxon::UInt64) enum199::BLEND_MODE::LEVR};
		return maxon::StringInterface::PrivateEnumToString((maxon::UInt64) x, "BLEND_MODE", SIZEOF(x), false, values, "NONE\0AVERAGE\0NORMAL\0MULTIPLY\0SCREEN\0DARKEN\0LIGHT\0DIFFERENCE\0NEGATIVE\0EXCLUSION\0OVERLAY\0HARDLIGHT\0SOFTLIGHT\0DODGE\0BURN\0REFLECT\0GLOW\0FREEZE\0HEAT\0ADD\0SUB\0STAMP\0XOR\0HUE\0SATURATION\0LUMINANCE\0RED\0GREEN\0BLUE\0OVERWRITE\0LEVR\0", fmt);
	}
	namespace enum211 { enum class RENDERDATA_FLAG
	{
		NONE = 0,
		SCREEN = (1 << 0),
		WORLD = (1 << 1),
		CAMERA = (1 << 2),
		LINE = (1 << 3),
		TRACING = (1 << 4),
		REDUCED = (1 << 5),
		TANGENT = (1 << 6),
	} ; }
	maxon::String PrivateToString_RENDERDATA_FLAG211(std::underlying_type<enum211::RENDERDATA_FLAG>::type x, const maxon::FormatStatement* fmt)
	{
		const maxon::UInt64 values[] = {(maxon::UInt64) enum211::RENDERDATA_FLAG::NONE, (maxon::UInt64) enum211::RENDERDATA_FLAG::SCREEN, (maxon::UInt64) enum211::RENDERDATA_FLAG::WORLD, (maxon::UInt64) enum211::RENDERDATA_FLAG::CAMERA, (maxon::UInt64) enum211::RENDERDATA_FLAG::LINE, (maxon::UInt64) enum211::RENDERDATA_FLAG::TRACING, (maxon::UInt64) enum211::RENDERDATA_FLAG::REDUCED, (maxon::UInt64) enum211::RENDERDATA_FLAG::TANGENT};
		return maxon::StringInterface::PrivateEnumToString((maxon::UInt64) x, "RENDERDATA_FLAG", SIZEOF(x), true, values, "NONE\0SCREEN\0WORLD\0CAMERA\0LINE\0TRACING\0REDUCED\0TANGENT\0", fmt);
	}
	namespace enum218 { enum class SETCURVE_FLAGS
	{
		NONE = 0,
		CLONE = (1 << 0),
		OWN = (1 << 1)
	} ; }
	maxon::String PrivateToString_SETCURVE_FLAGS218(std::underlying_type<enum218::SETCURVE_FLAGS>::type x, const maxon::FormatStatement* fmt)
	{
		const maxon::UInt64 values[] = {(maxon::UInt64) enum218::SETCURVE_FLAGS::NONE, (maxon::UInt64) enum218::SETCURVE_FLAGS::CLONE, (maxon::UInt64) enum218::SETCURVE_FLAGS::OWN};
		return maxon::StringInterface::PrivateEnumToString((maxon::UInt64) x, "SETCURVE_FLAGS", SIZEOF(x), true, values, "NONE\0CLONE\0OWN\0", fmt);
	}
	namespace enum227 { enum class MPBUFFER_FLAGS
	{
		NONE = 0,
		MUL = (1 << 0),
		DEPTH = (1 << 1),
		ALPHA = (1 << 2),
		INVERT = (1 << 3),
	} ; }
	maxon::String PrivateToString_MPBUFFER_FLAGS227(std::underlying_type<enum227::MPBUFFER_FLAGS>::type x, const maxon::FormatStatement* fmt)
	{
		const maxon::UInt64 values[] = {(maxon::UInt64) enum227::MPBUFFER_FLAGS::NONE, (maxon::UInt64) enum227::MPBUFFER_FLAGS::MUL, (maxon::UInt64) enum227::MPBUFFER_FLAGS::DEPTH, (maxon::UInt64) enum227::MPBUFFER_FLAGS::ALPHA, (maxon::UInt64) enum227::MPBUFFER_FLAGS::INVERT};
		return maxon::StringInterface::PrivateEnumToString((maxon::UInt64) x, "MPBUFFER_FLAGS", SIZEOF(x), true, values, "NONE\0MUL\0DEPTH\0ALPHA\0INVERT\0", fmt);
	}
}
#ifndef __API_INTERN__
#else
#endif
#ifdef CINEWARE_NAMESPACE_ENABLE
CINEWARE_NAMESPACE_END
#endif
#endif
