#if 1
#ifndef __API_INTERN__
#endif
#ifdef CINEWARE_NAMESPACE_ENABLE
CINEWARE_NAMESPACE_BEGIN
#endif
#ifndef __API_INTERN__
namespace enum2785
{
	enum class BAKE_STATE
	{
		NONE					= 0,					///< None.
		PREPARE				= 10000,			///< Prepare.
		GI_PREPASS		= 10001,			///< GI prepass.
		FILL_IMAGE		= 10002,			///< Fill image.
		COMPLETE			= 10003,			///< Complete.
		INITIALIZE		= 10004,			///< Initialize.
	
		RESIZENOTIFY = 19999				///< Resize notify. See BakeTextureResizeNotify.
	} ;
	static const maxon::UInt64 BAKE_STATE_values[] = {maxon::UInt64(enum2785::BAKE_STATE::NONE), maxon::UInt64(enum2785::BAKE_STATE::PREPARE), maxon::UInt64(enum2785::BAKE_STATE::GI_PREPASS), maxon::UInt64(enum2785::BAKE_STATE::FILL_IMAGE), maxon::UInt64(enum2785::BAKE_STATE::COMPLETE), maxon::UInt64(enum2785::BAKE_STATE::INITIALIZE), maxon::UInt64(enum2785::BAKE_STATE::RESIZENOTIFY)};
	static const maxon::EnumInfo BAKE_STATE_info{"BAKE_STATE", SIZEOF(BAKE_STATE), false, "NONE\0PREPARE\0GI_PREPASS\0FILL_IMAGE\0COMPLETE\0INITIALIZE\0RESIZENOTIFY\0", BAKE_STATE_values, std::extent<decltype(BAKE_STATE_values)>::value};
}
const maxon::EnumInfo& PrivateGetEnumInfo_BAKE_STATE2785(){ return enum2785::BAKE_STATE_info; }
#endif
#ifdef CINEWARE_NAMESPACE_ENABLE
CINEWARE_NAMESPACE_END
#endif
#endif
