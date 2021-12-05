#if 1
namespace enum49 { enum class VIDEOPOSTCALL
{
	FRAMESEQUENCE	= 1,	///< Called when the renderer prepares to render a sequence of images.
	FRAME					= 2,	///< Called when the renderer prepares to render a frame.
	SUBFRAME			= 3,	///< Called when the renderer prepares to render a subframe.
	RENDER				= 4,	///< Called before the rendering process starts and before shaders are initialized.
	INNER					= 5,	///< Called immediately before rendering starts.
	TILE					= 6		///< Called immediately before rendering a bucket. @since R16
} ; }
maxon::String PrivateToString_VIDEOPOSTCALL49(std::underlying_type<enum49::VIDEOPOSTCALL>::type x, const maxon::FormatStatement* fmt)
{
	const maxon::UInt64 values[] = {(maxon::UInt64) enum49::VIDEOPOSTCALL::FRAMESEQUENCE, (maxon::UInt64) enum49::VIDEOPOSTCALL::FRAME, (maxon::UInt64) enum49::VIDEOPOSTCALL::SUBFRAME, (maxon::UInt64) enum49::VIDEOPOSTCALL::RENDER, (maxon::UInt64) enum49::VIDEOPOSTCALL::INNER, (maxon::UInt64) enum49::VIDEOPOSTCALL::TILE};
	return maxon::StringInterface::PrivateEnumToString((maxon::UInt64) x, "VIDEOPOSTCALL", SIZEOF(x), false, values, "FRAMESEQUENCE\0FRAME\0SUBFRAME\0RENDER\0INNER\0TILE\0", fmt);
}
#ifdef __API_INTERN__
#else
#endif
namespace enum294 { enum class VIDEOPOST_GLINFO : UInt32
{
	NONE															= 0x00000000,
	CUSTOM_MOUSE											= 0x00000001,
	ALLOC_UVW_BUFFER									= 0x00000002,
	ALLOC_UVW_BUFFER_FLOAT32					= 0x00100002,
	ALLOC_DU_BUFFER										= 0x00000004,
	ALLOC_DV_BUFFER										= 0x00000008,
	ALLOC_NORMAL_BUFFER								= 0x00000010,
	ALLOC_MATERIAL_ID									= 0x00000020,
	ALLOC_NORMAL_BUFFER_FLOAT16				= 0x00100010,
	ALLOC_NORMAL_BUFFER_FLOAT32				= 0x00200010,
	ALLOC_WORLCOORD_BUFFER						= 0x00000040,
	ALLOC_OBJECTID_BUFFER							= 0x00000080,
	PREPASS														= 0x01000000,
	DRAW															= 0x02000000,
	STEREO3D													= 0x04000000,
	ALLOC_UVW_MATID_BUFFER_FLOAT32		= 0x00000100,
	ALLOC_TEXEL_SELECTION_BUFFER_R8I	= 0x00000200,				///< @since R19
	DISABLED													= 0x80000000
} ; }
maxon::String PrivateToString_VIDEOPOST_GLINFO294(std::underlying_type<enum294::VIDEOPOST_GLINFO>::type x, const maxon::FormatStatement* fmt)
{
	const maxon::UInt64 values[] = {(maxon::UInt64) enum294::VIDEOPOST_GLINFO::NONE, (maxon::UInt64) enum294::VIDEOPOST_GLINFO::CUSTOM_MOUSE, (maxon::UInt64) enum294::VIDEOPOST_GLINFO::ALLOC_UVW_BUFFER, (maxon::UInt64) enum294::VIDEOPOST_GLINFO::ALLOC_UVW_BUFFER_FLOAT32, (maxon::UInt64) enum294::VIDEOPOST_GLINFO::ALLOC_DU_BUFFER, (maxon::UInt64) enum294::VIDEOPOST_GLINFO::ALLOC_DV_BUFFER, (maxon::UInt64) enum294::VIDEOPOST_GLINFO::ALLOC_NORMAL_BUFFER, (maxon::UInt64) enum294::VIDEOPOST_GLINFO::ALLOC_MATERIAL_ID, (maxon::UInt64) enum294::VIDEOPOST_GLINFO::ALLOC_NORMAL_BUFFER_FLOAT16, (maxon::UInt64) enum294::VIDEOPOST_GLINFO::ALLOC_NORMAL_BUFFER_FLOAT32, (maxon::UInt64) enum294::VIDEOPOST_GLINFO::ALLOC_WORLCOORD_BUFFER, (maxon::UInt64) enum294::VIDEOPOST_GLINFO::ALLOC_OBJECTID_BUFFER, (maxon::UInt64) enum294::VIDEOPOST_GLINFO::PREPASS, (maxon::UInt64) enum294::VIDEOPOST_GLINFO::DRAW, (maxon::UInt64) enum294::VIDEOPOST_GLINFO::STEREO3D, (maxon::UInt64) enum294::VIDEOPOST_GLINFO::ALLOC_UVW_MATID_BUFFER_FLOAT32, (maxon::UInt64) enum294::VIDEOPOST_GLINFO::ALLOC_TEXEL_SELECTION_BUFFER_R8I, (maxon::UInt64) enum294::VIDEOPOST_GLINFO::DISABLED};
	return maxon::StringInterface::PrivateEnumToString((maxon::UInt64) x, "VIDEOPOST_GLINFO", SIZEOF(x), true, values, "NONE\0CUSTOM_MOUSE\0ALLOC_UVW_BUFFER\0ALLOC_UVW_BUFFER_FLOAT32\0ALLOC_DU_BUFFER\0ALLOC_DV_BUFFER\0ALLOC_NORMAL_BUFFER\0ALLOC_MATERIAL_ID\0ALLOC_NORMAL_BUFFER_FLOAT16\0ALLOC_NORMAL_BUFFER_FLOAT32\0ALLOC_WORLCOORD_BUFFER\0ALLOC_OBJECTID_BUFFER\0PREPASS\0DRAW\0STEREO3D\0ALLOC_UVW_MATID_BUFFER_FLOAT32\0ALLOC_TEXEL_SELECTION_BUFFER_R8I\0DISABLED\0", fmt);
}
namespace enum308 { enum class VIDEOPOST_GLDRAW
{
	NONE								= 0,
	CUSTOM_MOUSE_INIT		= (1 << 0),
	CUSTOM_MOUSE_DRAW		= (1 << 1),
	PREPASS							= (1 << 2),
	DRAW								= (1 << 3)
} ; }
maxon::String PrivateToString_VIDEOPOST_GLDRAW308(std::underlying_type<enum308::VIDEOPOST_GLDRAW>::type x, const maxon::FormatStatement* fmt)
{
	const maxon::UInt64 values[] = {(maxon::UInt64) enum308::VIDEOPOST_GLDRAW::NONE, (maxon::UInt64) enum308::VIDEOPOST_GLDRAW::CUSTOM_MOUSE_INIT, (maxon::UInt64) enum308::VIDEOPOST_GLDRAW::CUSTOM_MOUSE_DRAW, (maxon::UInt64) enum308::VIDEOPOST_GLDRAW::PREPASS, (maxon::UInt64) enum308::VIDEOPOST_GLDRAW::DRAW};
	return maxon::StringInterface::PrivateEnumToString((maxon::UInt64) x, "VIDEOPOST_GLDRAW", SIZEOF(x), true, values, "NONE\0CUSTOM_MOUSE_INIT\0CUSTOM_MOUSE_DRAW\0PREPASS\0DRAW\0", fmt);
}
#endif
