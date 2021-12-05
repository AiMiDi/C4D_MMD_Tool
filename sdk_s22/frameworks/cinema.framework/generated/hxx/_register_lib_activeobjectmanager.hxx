#if 1
namespace enum51 { enum class ACTIVEOBJECTMODE
{
	NONE,						///< None.

	OBJECT,					///< Object mode.
	TAG,						///< Tag mode.
	MATERIAL,				///< %Material mode.
	SHADER,					///< Shader mode.
	NODE,						///< Node mode.
	TIMELINE,				///< Timeline mode.
	FCURVE,					///< F-curve mode.
	BITMAPINFO,			///< @BP3D bitmap info mode
	TOOL,						///< Tool mode.
	VIEW,						///< View mode.
	INFOTAB,				///< Info tab.
	CAMERA,					///< Editor camera mode.
	RENDERDATA,			///< %Render data mode.
	DOCUMENT,				///< Document settings mode.
	MODELING,				///< %Modeling mode.
	LAYER,					///< Layer mode. @since R17.032
	UV,             ///< UV Options

	DUMMY
} ; }
maxon::String PrivateToString_ACTIVEOBJECTMODE51(std::underlying_type<enum51::ACTIVEOBJECTMODE>::type x, const maxon::FormatStatement* fmt)
{
	const maxon::UInt64 values[] = {(maxon::UInt64) enum51::ACTIVEOBJECTMODE::NONE, (maxon::UInt64) enum51::ACTIVEOBJECTMODE::OBJECT, (maxon::UInt64) enum51::ACTIVEOBJECTMODE::TAG, (maxon::UInt64) enum51::ACTIVEOBJECTMODE::MATERIAL, (maxon::UInt64) enum51::ACTIVEOBJECTMODE::SHADER, (maxon::UInt64) enum51::ACTIVEOBJECTMODE::NODE, (maxon::UInt64) enum51::ACTIVEOBJECTMODE::TIMELINE, (maxon::UInt64) enum51::ACTIVEOBJECTMODE::FCURVE, (maxon::UInt64) enum51::ACTIVEOBJECTMODE::BITMAPINFO, (maxon::UInt64) enum51::ACTIVEOBJECTMODE::TOOL, (maxon::UInt64) enum51::ACTIVEOBJECTMODE::VIEW, (maxon::UInt64) enum51::ACTIVEOBJECTMODE::INFOTAB, (maxon::UInt64) enum51::ACTIVEOBJECTMODE::CAMERA, (maxon::UInt64) enum51::ACTIVEOBJECTMODE::RENDERDATA, (maxon::UInt64) enum51::ACTIVEOBJECTMODE::DOCUMENT, (maxon::UInt64) enum51::ACTIVEOBJECTMODE::MODELING, (maxon::UInt64) enum51::ACTIVEOBJECTMODE::LAYER, (maxon::UInt64) enum51::ACTIVEOBJECTMODE::UV, (maxon::UInt64) enum51::ACTIVEOBJECTMODE::DUMMY};
	return maxon::StringInterface::PrivateEnumToString((maxon::UInt64) x, "ACTIVEOBJECTMODE", SIZEOF(x), false, values, "NONE\0OBJECT\0TAG\0MATERIAL\0SHADER\0NODE\0TIMELINE\0FCURVE\0BITMAPINFO\0TOOL\0VIEW\0INFOTAB\0CAMERA\0RENDERDATA\0DOCUMENT\0MODELING\0LAYER\0UV\0DUMMY\0", fmt);
}
/// @cond IGNORE

/// @endcond

#endif
