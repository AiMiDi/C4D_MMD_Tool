#if 1
#ifndef __API_INTERN__
#endif
#ifndef __API_INTERN__
namespace enum2774 { enum class BAKE_STATE
{
	NONE					= 0,					///< None.
	PREPARE				= 10000,			///< Prepare.
	GI_PREPASS		= 10001,			///< GI prepass.
	FILL_IMAGE		= 10002,			///< Fill image.
	COMPLETE			= 10003,			///< Complete.
	INITIALIZE		= 10004,			///< Initialize.

	RESIZENOTIFY = 19999				///< Resize notify. See BakeTextureResizeNotify.
} ; }
maxon::String PrivateToString_BAKE_STATE2774(std::underlying_type<enum2774::BAKE_STATE>::type x, const maxon::FormatStatement* fmt)
{
	const maxon::UInt64 values[] = {(maxon::UInt64) enum2774::BAKE_STATE::NONE, (maxon::UInt64) enum2774::BAKE_STATE::PREPARE, (maxon::UInt64) enum2774::BAKE_STATE::GI_PREPASS, (maxon::UInt64) enum2774::BAKE_STATE::FILL_IMAGE, (maxon::UInt64) enum2774::BAKE_STATE::COMPLETE, (maxon::UInt64) enum2774::BAKE_STATE::INITIALIZE, (maxon::UInt64) enum2774::BAKE_STATE::RESIZENOTIFY};
	return maxon::StringInterface::PrivateEnumToString((maxon::UInt64) x, "BAKE_STATE", SIZEOF(x), false, values, "NONE\0PREPARE\0GI_PREPASS\0FILL_IMAGE\0COMPLETE\0INITIALIZE\0RESIZENOTIFY\0", fmt);
}
#endif
#endif
