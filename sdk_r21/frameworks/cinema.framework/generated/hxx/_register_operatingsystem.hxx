#if 1
namespace enum792 { enum class VIEWPORTSELECTFLAGS
{
	NONE									= 0,			///< None.
	USE_HN								= 1,			///< Use HyperNURBS.
	USE_DEFORMERS					= 2,			///< Use deformers.
	REGION_SELECT					= 4,			///< A rectangle, polygon and lasso selection counts the number of vertices of a polygon within its area. Usually hidden vertices are not taken into account.\n This flag allows hidden vertices to be taken into account, otherwise it is not possible to select polygons if for example all points are hidden.
	IGNORE_HIDDEN_SEL			= 8,			///< Ignore hidden selection.
	USE_DISPLAY_MODE			= 16,			///< If this flag is set and the display mode is Wireframe or Isoparms only edges and vertices are written into the ViewportSelect buffer.\n The ViewportSelect mode must be @ref Mpolyedgepoint.
	FORCE_USE_DEFORMERS		= 32,			///< Use deformers even when the viewport DISPLAYEDITSTATE::DEFORM is disabled.
} ; }
maxon::String PrivateToString_VIEWPORTSELECTFLAGS792(std::underlying_type<enum792::VIEWPORTSELECTFLAGS>::type x, const maxon::FormatStatement* fmt)
{
	const maxon::UInt64 values[] = {(maxon::UInt64) enum792::VIEWPORTSELECTFLAGS::NONE, (maxon::UInt64) enum792::VIEWPORTSELECTFLAGS::USE_HN, (maxon::UInt64) enum792::VIEWPORTSELECTFLAGS::USE_DEFORMERS, (maxon::UInt64) enum792::VIEWPORTSELECTFLAGS::REGION_SELECT, (maxon::UInt64) enum792::VIEWPORTSELECTFLAGS::IGNORE_HIDDEN_SEL, (maxon::UInt64) enum792::VIEWPORTSELECTFLAGS::USE_DISPLAY_MODE, (maxon::UInt64) enum792::VIEWPORTSELECTFLAGS::FORCE_USE_DEFORMERS};
	return maxon::StringInterface::PrivateEnumToString((maxon::UInt64) x, "VIEWPORTSELECTFLAGS", SIZEOF(x), true, values, "NONE\0USE_HN\0USE_DEFORMERS\0REGION_SELECT\0IGNORE_HIDDEN_SEL\0USE_DISPLAY_MODE\0FORCE_USE_DEFORMERS\0", fmt);
}
namespace enum805 { enum class SCRIPTMODE
{
	NONE							= 0,	///< Normal multi-line text field.
	PYTHON						= 1,	///< @em %Python syntax highlighting.
	AM_ID							= 3,	///< Plain Attribute Manager ID (used for online help and new feature highlighting). @since R19
} ; }
maxon::String PrivateToString_SCRIPTMODE805(std::underlying_type<enum805::SCRIPTMODE>::type x, const maxon::FormatStatement* fmt)
{
	const maxon::UInt64 values[] = {(maxon::UInt64) enum805::SCRIPTMODE::NONE, (maxon::UInt64) enum805::SCRIPTMODE::PYTHON, (maxon::UInt64) enum805::SCRIPTMODE::AM_ID};
	return maxon::StringInterface::PrivateEnumToString((maxon::UInt64) x, "SCRIPTMODE", SIZEOF(x), false, values, "NONE\0PYTHON\0AM_ID\0", fmt);
}
namespace enum819 { enum class BASEDRAW_HIGHLIGHT
{
	BEFORE_TOOLS			= 0, ///< Use ::SCENEHOOKDRAW::HIGHLIGHT_PASS_BEFORE_TOOL as draw mode for the scene hooks.
	AFTER_TOOLS				= 1, ///< Use ::SCENEHOOKDRAW::HIGHLIGHT_PASS as draw mode for the scene hooks.
	INVERSE_Z					= 2, ///< Use ::SCENEHOOKDRAW::HIGHLIGHT_PASS_INV as draw mode for the scene hooks.
	DRAW_AFTER_CLEAR	= 3, ///< Use ::SCENEHOOKDRAW::DRAW_PASS_AFTER_CLEAR as draw mode for the scene hooks.
} ; }
maxon::String PrivateToString_BASEDRAW_HIGHLIGHT819(std::underlying_type<enum819::BASEDRAW_HIGHLIGHT>::type x, const maxon::FormatStatement* fmt)
{
	const maxon::UInt64 values[] = {(maxon::UInt64) enum819::BASEDRAW_HIGHLIGHT::BEFORE_TOOLS, (maxon::UInt64) enum819::BASEDRAW_HIGHLIGHT::AFTER_TOOLS, (maxon::UInt64) enum819::BASEDRAW_HIGHLIGHT::INVERSE_Z, (maxon::UInt64) enum819::BASEDRAW_HIGHLIGHT::DRAW_AFTER_CLEAR};
	return maxon::StringInterface::PrivateEnumToString((maxon::UInt64) x, "BASEDRAW_HIGHLIGHT", SIZEOF(x), false, values, "BEFORE_TOOLS\0AFTER_TOOLS\0INVERSE_Z\0DRAW_AFTER_CLEAR\0", fmt);
}
namespace enum834 { enum class FIELDLAYER_CHANNELFLAG
{
	NONE					= 0,						///< None.
	ENABLE				= (1 << 0),			///< The layer is enabled and being sampled.
	VALUE					= (1 << 1),			///< Value sampling is enabled for this layer.
	COLOR					= (1 << 2),			///< Color sampling is enabled for this layer.
	DIRECTION			= (1 << 3),			///< Direction sampling is enabled for this layer.
	ROTATION			= (1 << 4)			///< Rotation sampling is enabled for this layer.
} ; }
maxon::String PrivateToString_FIELDLAYER_CHANNELFLAG834(std::underlying_type<enum834::FIELDLAYER_CHANNELFLAG>::type x, const maxon::FormatStatement* fmt)
{
	const maxon::UInt64 values[] = {(maxon::UInt64) enum834::FIELDLAYER_CHANNELFLAG::NONE, (maxon::UInt64) enum834::FIELDLAYER_CHANNELFLAG::ENABLE, (maxon::UInt64) enum834::FIELDLAYER_CHANNELFLAG::VALUE, (maxon::UInt64) enum834::FIELDLAYER_CHANNELFLAG::COLOR, (maxon::UInt64) enum834::FIELDLAYER_CHANNELFLAG::DIRECTION, (maxon::UInt64) enum834::FIELDLAYER_CHANNELFLAG::ROTATION};
	return maxon::StringInterface::PrivateEnumToString((maxon::UInt64) x, "FIELDLAYER_CHANNELFLAG", SIZEOF(x), true, values, "NONE\0ENABLE\0VALUE\0COLOR\0DIRECTION\0ROTATION\0", fmt);
}
namespace enum848 { enum class POPUPEDITTEXTCALLBACK
{
	TEXTCHANGED = 1,			///< Text was changed.
	CLOSED			= 2,			///< Window was closed.
	CANCELED		= 3,			///< Operation was canceled.
	CURSOR_UP		= 4,			///< %User exited by pressing the up key.
	CURSOR_DOWN = 5				///< %User exited by pressing the down key.
} ; }
maxon::String PrivateToString_POPUPEDITTEXTCALLBACK848(std::underlying_type<enum848::POPUPEDITTEXTCALLBACK>::type x, const maxon::FormatStatement* fmt)
{
	const maxon::UInt64 values[] = {(maxon::UInt64) enum848::POPUPEDITTEXTCALLBACK::TEXTCHANGED, (maxon::UInt64) enum848::POPUPEDITTEXTCALLBACK::CLOSED, (maxon::UInt64) enum848::POPUPEDITTEXTCALLBACK::CANCELED, (maxon::UInt64) enum848::POPUPEDITTEXTCALLBACK::CURSOR_UP, (maxon::UInt64) enum848::POPUPEDITTEXTCALLBACK::CURSOR_DOWN};
	return maxon::StringInterface::PrivateEnumToString((maxon::UInt64) x, "POPUPEDITTEXTCALLBACK", SIZEOF(x), false, values, "TEXTCHANGED\0CLOSED\0CANCELED\0CURSOR_UP\0CURSOR_DOWN\0", fmt);
}
/// @cond IGNORE

#ifndef __API_INTERN__
#endif
/// @endcond

#endif
