#if 1
#ifdef CINEWARE_NAMESPACE_ENABLE
CINEWARE_NAMESPACE_BEGIN
#endif
namespace enum53
{
	enum class VIDEOPOSTCALL
	{
		FRAMESEQUENCE	= 1,	///< Called when the renderer prepares to render a sequence of images.
		FRAME					= 2,	///< Called when the renderer prepares to render a frame.
		SUBFRAME			= 3,	///< Called when the renderer prepares to render a subframe.
		RENDER				= 4,	///< Called before the rendering process starts and before shaders are initialized.
		INNER					= 5,	///< Called immediately before rendering starts.
		TILE					= 6		///< Called immediately before rendering a bucket. @since R16
	} ;
	static const maxon::UInt64 VIDEOPOSTCALL_values[] = {maxon::UInt64(enum53::VIDEOPOSTCALL::FRAMESEQUENCE), maxon::UInt64(enum53::VIDEOPOSTCALL::FRAME), maxon::UInt64(enum53::VIDEOPOSTCALL::SUBFRAME), maxon::UInt64(enum53::VIDEOPOSTCALL::RENDER), maxon::UInt64(enum53::VIDEOPOSTCALL::INNER), maxon::UInt64(enum53::VIDEOPOSTCALL::TILE)};
	static const maxon::EnumInfo VIDEOPOSTCALL_info{"VIDEOPOSTCALL", SIZEOF(VIDEOPOSTCALL), false, "FRAMESEQUENCE\0FRAME\0SUBFRAME\0RENDER\0INNER\0TILE\0", VIDEOPOSTCALL_values, std::extent<decltype(VIDEOPOSTCALL_values)>::value};
}
const maxon::EnumInfo& PrivateGetEnumInfo_VIDEOPOSTCALL53(){ return enum53::VIDEOPOSTCALL_info; }
#ifdef __API_INTERN__
#else
#endif
#ifdef CINEWARE_NAMESPACE_ENABLE
CINEWARE_NAMESPACE_END
#endif
#endif
