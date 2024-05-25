#if 1
#ifdef CINEWARE_NAMESPACE_ENABLE
CINEWARE_NAMESPACE_BEGIN
#endif
#ifdef CINEWARE_NAMESPACE_ENABLE
CINEWARE_NAMESPACE_END
#endif
#ifdef CINEWARE_NAMESPACE_ENABLE
CINEWARE_NAMESPACE_BEGIN
#endif
namespace enum882
{
	enum class OPENDIALOGFLAGS
	{
		NONE = 0,
		IGNORELAYOUT = (1 << 0),				 ///< set to ignore to load layout informations from the layout file
		CLIENTCOORDINATES = (1 << 1),		 ///< defines to open the window position and size in window client coordinates, this means the given
																		 ///< position and size will be adjusted with the window borders
		ALIGNTOPLEFTATMOUSE = (1 << 2), ///< aligns the manager at the top/left position of the current mouse position.
	} ;
	static const maxon::UInt64 OPENDIALOGFLAGS_values[] = {maxon::UInt64(enum882::OPENDIALOGFLAGS::NONE), maxon::UInt64(enum882::OPENDIALOGFLAGS::IGNORELAYOUT), maxon::UInt64(enum882::OPENDIALOGFLAGS::CLIENTCOORDINATES), maxon::UInt64(enum882::OPENDIALOGFLAGS::ALIGNTOPLEFTATMOUSE)};
	static const maxon::EnumInfo OPENDIALOGFLAGS_info{"OPENDIALOGFLAGS", SIZEOF(OPENDIALOGFLAGS), true, "NONE\0IGNORELAYOUT\0CLIENTCOORDINATES\0ALIGNTOPLEFTATMOUSE\0", OPENDIALOGFLAGS_values, std::extent<decltype(OPENDIALOGFLAGS_values)>::value};
}
const maxon::EnumInfo& PrivateGetEnumInfo_OPENDIALOGFLAGS882(){ return enum882::OPENDIALOGFLAGS_info; }
namespace enum898
{
	enum class VIEWPORTSELECTFLAGS
	{
		NONE									= 0,			///< None.
		USE_HN								= 1,			///< Use HyperNURBS.
		USE_DEFORMERS					= 2,			///< Use deformers.
		REGION_SELECT					= 4,			///< A rectangle, polygon and lasso selection counts the number of vertices of a polygon within its area. Usually hidden vertices are not taken into account.\n This flag allows hidden vertices to be taken into account, otherwise it is not possible to select polygons if for example all points are hidden.
		IGNORE_HIDDEN_SEL			= 8,			///< Ignore hidden selection.
		USE_DISPLAY_MODE			= 16,			///< If this flag is set and the display mode is Wireframe or Isoparms only edges and vertices are written into the ViewportSelect buffer.\n The ViewportSelect mode must be @ref Mpolyedgepoint.
		FORCE_USE_DEFORMERS		= 32,			///< Use deformers even when the viewport DISPLAYEDITSTATE::DEFORM is disabled.
		ALLOW_ASYNC						= 64,			///< Allows for asynchronous initialization. While it initializes it will not return correct data.
		BUILD_ALL_FRAMENTS		= 128			///< Builds the selection buffer with all fragments sorted and visibility info stored.
	} ;
	static const maxon::UInt64 VIEWPORTSELECTFLAGS_values[] = {maxon::UInt64(enum898::VIEWPORTSELECTFLAGS::NONE), maxon::UInt64(enum898::VIEWPORTSELECTFLAGS::USE_HN), maxon::UInt64(enum898::VIEWPORTSELECTFLAGS::USE_DEFORMERS), maxon::UInt64(enum898::VIEWPORTSELECTFLAGS::REGION_SELECT), maxon::UInt64(enum898::VIEWPORTSELECTFLAGS::IGNORE_HIDDEN_SEL), maxon::UInt64(enum898::VIEWPORTSELECTFLAGS::USE_DISPLAY_MODE), maxon::UInt64(enum898::VIEWPORTSELECTFLAGS::FORCE_USE_DEFORMERS), maxon::UInt64(enum898::VIEWPORTSELECTFLAGS::ALLOW_ASYNC), maxon::UInt64(enum898::VIEWPORTSELECTFLAGS::BUILD_ALL_FRAMENTS)};
	static const maxon::EnumInfo VIEWPORTSELECTFLAGS_info{"VIEWPORTSELECTFLAGS", SIZEOF(VIEWPORTSELECTFLAGS), true, "NONE\0USE_HN\0USE_DEFORMERS\0REGION_SELECT\0IGNORE_HIDDEN_SEL\0USE_DISPLAY_MODE\0FORCE_USE_DEFORMERS\0ALLOW_ASYNC\0BUILD_ALL_FRAMENTS\0", VIEWPORTSELECTFLAGS_values, std::extent<decltype(VIEWPORTSELECTFLAGS_values)>::value};
}
const maxon::EnumInfo& PrivateGetEnumInfo_VIEWPORTSELECTFLAGS898(){ return enum898::VIEWPORTSELECTFLAGS_info; }
namespace enum911
{
	enum class SCRIPTMODE
	{
		NONE							= 0,	///< Normal multi-line text field.
		PYTHON						= 1,	///< @em %Python syntax highlighting.
		AM_ID							= 3,	///< Plain Attribute Manager ID (used for online help and new feature highlighting). @since R19
	} ;
	static const maxon::UInt64 SCRIPTMODE_values[] = {maxon::UInt64(enum911::SCRIPTMODE::NONE), maxon::UInt64(enum911::SCRIPTMODE::PYTHON), maxon::UInt64(enum911::SCRIPTMODE::AM_ID)};
	static const maxon::EnumInfo SCRIPTMODE_info{"SCRIPTMODE", SIZEOF(SCRIPTMODE), false, "NONE\0PYTHON\0AM_ID\0", SCRIPTMODE_values, std::extent<decltype(SCRIPTMODE_values)>::value};
}
const maxon::EnumInfo& PrivateGetEnumInfo_SCRIPTMODE911(){ return enum911::SCRIPTMODE_info; }
namespace enum925
{
	enum class BASEDRAW_HIGHLIGHT
	{
		BEFORE_TOOLS			= 0, ///< Use ::SCENEHOOKDRAW::HIGHLIGHT_PASS_BEFORE_TOOL as draw mode for the scene hooks.
		AFTER_TOOLS				= 1, ///< Use ::SCENEHOOKDRAW::HIGHLIGHT_PASS as draw mode for the scene hooks.
		INVERSE_Z					= 2, ///< Use ::SCENEHOOKDRAW::HIGHLIGHT_PASS_INV as draw mode for the scene hooks.
		DRAW_AFTER_CLEAR	= 3, ///< Use ::SCENEHOOKDRAW::DRAW_PASS_AFTER_CLEAR as draw mode for the scene hooks.
	} ;
	static const maxon::UInt64 BASEDRAW_HIGHLIGHT_values[] = {maxon::UInt64(enum925::BASEDRAW_HIGHLIGHT::BEFORE_TOOLS), maxon::UInt64(enum925::BASEDRAW_HIGHLIGHT::AFTER_TOOLS), maxon::UInt64(enum925::BASEDRAW_HIGHLIGHT::INVERSE_Z), maxon::UInt64(enum925::BASEDRAW_HIGHLIGHT::DRAW_AFTER_CLEAR)};
	static const maxon::EnumInfo BASEDRAW_HIGHLIGHT_info{"BASEDRAW_HIGHLIGHT", SIZEOF(BASEDRAW_HIGHLIGHT), false, "BEFORE_TOOLS\0AFTER_TOOLS\0INVERSE_Z\0DRAW_AFTER_CLEAR\0", BASEDRAW_HIGHLIGHT_values, std::extent<decltype(BASEDRAW_HIGHLIGHT_values)>::value};
}
const maxon::EnumInfo& PrivateGetEnumInfo_BASEDRAW_HIGHLIGHT925(){ return enum925::BASEDRAW_HIGHLIGHT_info; }
namespace enum940
{
	enum class FIELDLAYER_CHANNELFLAG
	{
		NONE					= 0,						///< None.
		ENABLE				= (1 << 0),			///< The layer is enabled and being sampled.
		VALUE					= (1 << 1),			///< Value sampling is enabled for this layer.
		COLOR					= (1 << 2),			///< Color sampling is enabled for this layer.
		DIRECTION			= (1 << 3),			///< Direction sampling is enabled for this layer.
		ROTATION			= (1 << 4)			///< Rotation sampling is enabled for this layer.
	} ;
	static const maxon::UInt64 FIELDLAYER_CHANNELFLAG_values[] = {maxon::UInt64(enum940::FIELDLAYER_CHANNELFLAG::NONE), maxon::UInt64(enum940::FIELDLAYER_CHANNELFLAG::ENABLE), maxon::UInt64(enum940::FIELDLAYER_CHANNELFLAG::VALUE), maxon::UInt64(enum940::FIELDLAYER_CHANNELFLAG::COLOR), maxon::UInt64(enum940::FIELDLAYER_CHANNELFLAG::DIRECTION), maxon::UInt64(enum940::FIELDLAYER_CHANNELFLAG::ROTATION)};
	static const maxon::EnumInfo FIELDLAYER_CHANNELFLAG_info{"FIELDLAYER_CHANNELFLAG", SIZEOF(FIELDLAYER_CHANNELFLAG), true, "NONE\0ENABLE\0VALUE\0COLOR\0DIRECTION\0ROTATION\0", FIELDLAYER_CHANNELFLAG_values, std::extent<decltype(FIELDLAYER_CHANNELFLAG_values)>::value};
}
const maxon::EnumInfo& PrivateGetEnumInfo_FIELDLAYER_CHANNELFLAG940(){ return enum940::FIELDLAYER_CHANNELFLAG_info; }
namespace enum954
{
	enum class POPUPEDITTEXTCALLBACK
	{
		TEXTCHANGED = 1,			///< Text was changed.
		CLOSED			= 2,			///< Window was closed.
		CANCELED		= 3,			///< Operation was canceled.
		CURSOR_UP		= 4,			///< %User exited by pressing the up key.
		CURSOR_DOWN = 5				///< %User exited by pressing the down key.
	} ;
	static const maxon::UInt64 POPUPEDITTEXTCALLBACK_values[] = {maxon::UInt64(enum954::POPUPEDITTEXTCALLBACK::TEXTCHANGED), maxon::UInt64(enum954::POPUPEDITTEXTCALLBACK::CLOSED), maxon::UInt64(enum954::POPUPEDITTEXTCALLBACK::CANCELED), maxon::UInt64(enum954::POPUPEDITTEXTCALLBACK::CURSOR_UP), maxon::UInt64(enum954::POPUPEDITTEXTCALLBACK::CURSOR_DOWN)};
	static const maxon::EnumInfo POPUPEDITTEXTCALLBACK_info{"POPUPEDITTEXTCALLBACK", SIZEOF(POPUPEDITTEXTCALLBACK), false, "TEXTCHANGED\0CLOSED\0CANCELED\0CURSOR_UP\0CURSOR_DOWN\0", POPUPEDITTEXTCALLBACK_values, std::extent<decltype(POPUPEDITTEXTCALLBACK_values)>::value};
}
const maxon::EnumInfo& PrivateGetEnumInfo_POPUPEDITTEXTCALLBACK954(){ return enum954::POPUPEDITTEXTCALLBACK_info; }
/// @cond IGNORE

#ifdef __API_INTERN__
#if MAXON_HAS_ATTRIBUTE_ALWAYS_CONST
#endif
#endif
#ifndef __API_INTERN__
#else
#if MAXON_HAS_ATTRIBUTE_ALWAYS_CONST
#endif
#if MAXON_HAS_ATTRIBUTE_ALWAYS_CONST
#else
#endif
#endif
/// @endcond

#ifdef CINEWARE_NAMESPACE_ENABLE
CINEWARE_NAMESPACE_END
#endif
#endif
