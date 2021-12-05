/////////////////////////////////////////////////////////////
// Cinema 4D SDK                                           //
/////////////////////////////////////////////////////////////
// (c) MAXON Computer GmbH, all rights reserved            //
/////////////////////////////////////////////////////////////

#ifndef GUI_H__
#define GUI_H__

#ifdef __API_INTERN__
abc def xyz
#endif

/// @addtogroup FONT
/// @ingroup group_enumeration
/// @{
enum
{
	FONT_DEFAULT		= 0,			///< Default font.
	FONT_STANDARD		= 1,			///< Standard font.
	FONT_BOLD				= 2,			///< Bold font.
	FONT_MONOSPACED	= 3,			///< Monospaced font.
	FONT_BIG				= 4,			///< Big font.
	FONT_BIG_BOLD		= 5				///< Big Bold font.
};
/// @}

/// @addtogroup QUALIFIERS
/// @ingroup group_enumeration
/// @{
enum
{
	QSHIFT	= 1,			///< Shift.
	QCTRL		= 2,			///< Control.
										///< @note On Mac this indicates either @em Ctrl or @em Cmd key.
	QALT		= 4,			///< Alt.
	QALT2		= 8,			///< Alt Gr.
	QQUAL_
};
/// @}

/// @addtogroup KEY
/// @ingroup group_enumeration
/// @{
enum
{
	KEY_MLEFT			= 0xF000,
	KEY_MRIGHT		= 0xF001,
	KEY_MMIDDLE		= 0xF002,
	KEY_MX1				= 0xF003,
	KEY_MX2				= 0xF004,

	// Modifier keys
	KEY_SHIFT			= 0xF010,
	KEY_CONTROL		= 0xF011,
	KEY_ALT				= 0xF012,
	KEY_CAPSLOCK	= 0xF013,
	KEY_MODIFIERS	= 0xF014,
	KEY_COMMAND		= 0xF015,

	KEY_BACKSPACE	= 0xF108,
	KEY_TAB				= 0xF109,
	KEY_ENTER			= 0xF10D,
	KEY_ESC				= 0xF11B,
	KEY_SPACE			= 0xF120,
	KEY_DELETE		= 0xF17F,

	KEY_UP				= 0xF180,
	KEY_DOWN			= 0xF181,
	KEY_LEFT			= 0xF182,
	KEY_RIGHT			= 0xF183,
	KEY_PGUP			= 0xF184,
	KEY_PGDOWN		= 0xF185,
	KEY_HOME			= 0xF186,
	KEY_END				= 0xF187,
	KEY_INSERT		= 0xF188,

	KEY_F1				= 0xF1A0,
	KEY_F2				= 0xF1A1,
	KEY_F3				= 0xF1A2,
	KEY_F4				= 0xF1A3,
	KEY_F5				= 0xF1A4,
	KEY_F6				= 0xF1A5,
	KEY_F7				= 0xF1A6,
	KEY_F8				= 0xF1A7,
	KEY_F9				= 0xF1A8,
	KEY_F10				= 0xF1A9,
	KEY_F11				= 0xF1AA,
	KEY_F12				= 0xF1AB,
	KEY_F13				= 0xF1AC,
	KEY_F14				= 0xF1AD,
	KEY_F15				= 0xF1AE,
	KEY_F16				= 0xF1AF,
	KEY_F17				= 0xF1B0,
	KEY_F18				= 0xF1B1,
	KEY_F19				= 0xF1B2,
	KEY_F20				= 0xF1B3,
	KEY_F21				= 0xF1B4,
	KEY_F22				= 0xF1B5,
	KEY_F23				= 0xF1B6,
	KEY_F24				= 0xF1B7,
	KEY_F25				= 0xF1B8,
	KEY_F26				= 0xF1B9,
	KEY_F27				= 0xF1BA,
	KEY_F28				= 0xF1BB,
	KEY_F29				= 0xF1BC,
	KEY_F30				= 0xF1BD,
	KEY_F31				= 0xF1BE,
	KEY_F32				= 0xF1BF
};
/// @}

/// @addtogroup BfCOLOR
/// @ingroup group_enumeration
/// @{
enum
{
	BfBLACK			= 0,
	BfWHITE			= 1,
	BfLTGRAY		= 2,
	BfLTRED			= 3,
	BfLTGREEN		= 4,
	BfLTBLUE		= 5,
	BfLTYELLOW	= 6,
	BfGRAY			= 7,
	BfRED				= 8,
	BfGREEN			= 9,
	BfBLUE			= 10,
	BfYELLOW		= 11,
	BfDGRAY			= 12,
	BfDRED			= 13,
	BfDGREEN		= 14,
	BfDBLUE			= 15,
	BfDYELLOW		= 16,
	BfDWHITE		= 17,
	BfORANGE		= 18,
	BfBROWN			= 19,
	BfPURPLE		= 20
};
/// @}

/// @addtogroup ARROW
/// @ingroup group_enumeration
/// @{
enum
{
	ARROW_LEFT				= 1,			///< Arrow pointing left.
	ARROW_RIGHT				= 2,			///< Arrow pointing right.
	ARROW_UP					= 3,			///< Arrow pointing up.
	ARROW_DOWN				= 4,			///< Arrow pointing down.

	ARROW_SMALL_LEFT	= 5,			///< Small arrow pointing left.
	ARROW_SMALL_RIGHT	= 6,			///< Small arrow pointing right.
	ARROW_SMALL_UP		= 7,			///< Small arrow pointing up.
	ARROW_SMALL_DOWN	= 8				///< Small arrow pointing down.
};
/// @}

/// @addtogroup BMP
/// @ingroup group_enumeration
/// @{
enum
{
	BMP_NORMAL							= 0,				///< Standard scaling by the operating system. Fast but low quality when using uneven scaling factors.
	BMP_NORMALSCALED				= 1,				///< Scaling with sampling for high quality. Slow.
	BMP_GRAYEDOUT						= 3,				///< Grays the bitmap out (like the grayed palette icons in @C4D), overlaying it with the current draw color set with GeUserArea::DrawSetPen() at 80% of opacity. If current draw color is unset, default COLOR_BG_PALETTE color will be used.
	BMP_TRANSPARENTALPHA    = 128,			///< The alpha background is not filled with the current pen.
	BMP_ALLOWALPHA					= 256,			///< Uses the alpha channel to blend with the current draw color set with GeUserArea::DrawSetPen().
	BMP_APPLY_COLORPROFILE	= 512,			///< Applies the color profile.
	BMP_DIMIMAGE						= 1024,			///< Darkens the bitmap (like the activated palette icons in @C4D).
	BMP_MIRROR_H						= 2048,			///< Mirrors the bitmap horizontally.
	BMP_MIRROR_H_FORBID			= 4096,			///< Does not mirror the bitmap horizontally.
	BMP_MIRROR_V						= 8192,			///< Mirrors the bitmap vertically.
	BMP_MIRROR_V_FORBID			= 16384,		///< Does not mirror the bitmap vertically.
	BMP_SCALE_NEARESTPIXEL  = 32768			///< scales with nearest pixel to prevent interpolations
};
/// @}

/// @addtogroup BFV_GROUP
/// @ingroup group_enumeration
/// @{
/// @see GeDialog::GroupBegin
enum
{
	BFV_GRIDGROUP_EQUALCOLS					= 1,					///< Each column has the same width.
	BFV_GRIDGROUP_EQUALROWS					= 2,					///< Each row has the same height.
	BFV_CMD_EQUALCOLUMNS						= 2048,				///< Columns have equal width.
	BFV_BORDERGROUP_CHECKBOX				= 4096,				///< Checkbox in title of a border group.
	BFV_BORDERGROUP_FOLD						= 8192,				///< Fold symbol in title of a border group. @markDeprecated
	BFV_BORDERGROUP_FOLD_OPEN				= 16384,			///< Opened fold symbol.
	BFV_BORDERGROUP_FOLD2						= 32768,			///< Foldable group, but no switch gadget.
	BFV_GRIDGROUP_ALLOW_WEIGHTS			= 65536,			///< Allow the user to move the weights.
	BFV_GRIDGROUP_FORBID_MIRROR			= 131072,			///< Do not mirror the layout of this group.

	BFV_DIALOG_REMOVEABLE						= 4,					///< Dialog is removable.
	BFV_DIALOG_BAR_VERT							= 8,					///< Dialog has a vertical dialog bar.
	BFV_DIALOG_NOBUTTONS						= 16,					///< Dialog has no button bar.

	// BFV_GRIDGROUP_LAYOUTER				= 256,				/// Mark a layouter frame.
	BFV_LAYOUTGROUP_PALETTEOUTLINES	= 512,				///< Layout group has palette outlines.

	BFV_TABGROUP_RELOADDIALOG				= 2048,				///< @markPrivate
	BFV_LAYOUTGROUP_NODROP					= 4096,				///< Prevents drag and drop onto a tab. @markPrivate
	BFV_LAYOUTGROUP_NODROP2					= 8192,				///< Prevents drag and drop between layout groups. @markPrivate
	BFV_IGNORE_FOCUS								= 262144,		///< Group ignores focus.

	BFx_NOEQUAL											= 64,			///< Groups with @ref BFV_GRIDGROUP_EQUALCOLS or @ref BFV_GRIDGROUP_EQUALROWS flag can have their own maximum width.

	BFV_
};
/// @}

/// @addtogroup RESOURCE
/// @ingroup group_containerid
/// @{
/// @markPrivate
enum
{
	RESOURCE_MENU				= 'rmnu',
	RESOURCE_DIALOG			= 'rdlg',
	RESOURCE_CONTAINER	= 'rcnt'
};
/// @}

/// @addtogroup MENURESOURCE
/// @ingroup group_containerid
/// @{
enum
{
	MENURESOURCE_SUBMENU					= 1,			///< BaseContainer Sub-menu:
	MENURESOURCE_SEPERATOR				= 2,			///< @formatConstant{true} if it is a separator.
	MENURESOURCE_COMMAND					= 3,			///< Command, e.g. @em "IDM_NEU" or @em "PLUGIN_CMD_1000472".
	MENURESOURCE_SUBTITLE					= 4,			///< The title of the menu item or sub-menu. @note It is recommended to use the identifier string instead of the string value. @since R17 SP3
	MENURESOURCE_STRING						= 5,			///< BaseContainer Menu item.
	MENURESOURCE_MENURESOURCE			= 6,			///< BaseContainer Menu resource.
	MENURESOURCE_SUBTITLE_ICONID	= 7,			///< IconId for subtitle strings
};
/// @}

/// @addtogroup BORDER
/// @ingroup group_enumeration
/// @{
enum
{
	BORDER_NONE									= 0,			///< No border.
	BORDER_THIN_IN							= 1,			///< Thin border inward.
	BORDER_THIN_OUT							= 2,			///< Thin border outward.
	BORDER_IN										= 3,			///< Normal border inward.
	BORDER_OUT									= 4,			///< Normal border outward.
	BORDER_GROUP_IN							= 5,			///< Group border inside.
	BORDER_GROUP_OUT						= 6,			///< Group border outside.
	BORDER_OUT2									= 7,			///< Outward border 2.
	BORDER_OUT3									= 8,			///< Outward border 3.
	BORDER_BLACK								= 9,			///< Thin black line.
	BORDER_ACTIVE_1							= 10,			///< Active border 1.
	BORDER_ACTIVE_2							= 11,			///< Active border 2.
	BORDER_GROUP_TOP						= 12,			///< Border along the top.
	BORDER_ACTIVE_3							= 13,			///< Active border 3.
	BORDER_ACTIVE_4							= 14,			///< Active border 4.
	BORDER_ROUND								= 15,			///< Border with round corners.
	BORDER_SCHEME_EDIT					= 16,			///< Edit field border like the shortcut gadget for example.
	BORDER_SCHEME_EDIT_NUMERIC	= 17,			///< Edit field border that is open to the right like the link field for example.
	BORDER_OUT3l								= 18,			///< Outward border 3, open to the left.
	BORDER_OUT3r								= 19,			///< Outward border 3, open to the right.
	BORDER_THIN_INb							= 20,			///< Thin border inward, open to the botton.

	BORDER_MASK									= 0x1FFFFFFF,			///< Masks out border type.

	BORDER_TEXT_DOTTED					= 0x10000000,     ///< Only used with @ref GeDialog::AddStaticText(). Draws a dotted line at right of text, useful to visuallly connect the text with its parameter. @note Use the flag @ref BFH_FIT in order to have space to draw the dotted line.
																								///< @b Example:
																								///< @code
																								/// AddStaticText(1000, BFH_FIT, 0, 0, "My Parameter"_s, BORDER_TEXT_DOTTED | BORDER_WITH_TITLE_BOLD);
																								///< @endcode @since R21
	
	BORDER_WITH_TITLE_MONO			= 0x20000000,			///< Display group title with monospaced font.
	BORDER_WITH_TITLE_BOLD			= 0x40000000,			///< Display group title with bold font. Can be used with @ref GeDialog::AddStaticText() as well to show bold font.
	BORDER_WITH_TITLE						= 0x80000000			///< Display group title in the border.
};
/// @}

// The following symbols should not be defined in a 'mixed' anonymous enum.
// Doxygen does not generate the expected documentation for these symbols.
enum
{
	TAB_TABS			= 0,			///< Normal tabs.
	TAB_NOSELECT	= 1,			///< No tabs.
	TAB_CYCLE			= 2,			///< Popup buttons instead of tabs.
	TAB_RADIO			= 3,			///< Radio buttons instead of tabs.
	TAB_VLTABS		= 4,			///< Vertical tabs, left-sided.
	TAB_VRTABS		= 5,			///< Vertical tabs, right-sided.

	BFV_CENTER				= 0,			///< Centered vertically.
	BFV_TOP						= 1,			///< Aligned to the top. @c 1<<0
	BFV_BOTTOM				= 2,			///< Aligned to the bottom. @c 1<<1
	BFV_FIT						= 3,			///< Fit. @ref BFV_BOTTOM|@ref BFV_TOP
	BFV_SCALE					= 4,			///< Scale if there is more space. @c 1<<2
	BFV_SCALEFIT			= 7,			///< Scale fit. @ref BFV_SCALE|@ref BFV_FIT
	BFV_MASK					= 3,			///< Masks out flags.

	BFH_CENTER				= 0,			///< Centered horizontally.
	BFH_LEFT					= 8,			///< Aligned to the left. @c 1<<3
	BFH_RIGHT					= 16,			///< Aligned to the right. @c 1<<4
	BFH_FIT						= 24,			///< Fit. @ref BFH_LEFT|@ref BFH_RIGHT
	BFH_SCALE					= 32,			///< Scale if there is more space. @c 1<<5
	BFH_SCALEFIT			= 56,			///< Scale fit. @ref BFH_SCALE|@ref BFH_FIT
	BFH_MASK					= 24,			///< Masks out flags.

	DR_MULTILINE_MONOSPACED			= 1,				///< Monospaced font.
	DR_MULTILINE_SYNTAXCOLOR		= 2,				///< C.O.F.F.E.E. syntax highlighting.
	DR_MULTILINE_STATUSBAR			= 4,				///< Display a statusbar with the cursor position.
	DR_MULTILINE_HIGHLIGHTLINE	= 8,				///< Highlight lines.
	DR_MULTILINE_READONLY				= 16,				///< Read-only multi-line field.
	// DR_MULTILINE_RESERVED		= 32,
	// DR_MULTILINE_RESERVED		= 64,
	DR_MULTILINE_PYTHON					= 128,			///< Python syntax highlighting.
	DR_MULTILINE_WORDWRAP				= 256,			///< Word wrap multi-line field.
	DR_MULTILINE_SETLOGGER			= 512,
	DR_MULTILINE_SETPYTHONSCOPE = 1024,
	DR_COLORFIELD_NO_BRIGHTNESS						= 1,						///< Disables the brightness control.
	DR_COLORFIELD_NO_COLOR								= 2,						///< Disables the color control.
	DR_COLORFIELD_BODYPAINT								= 4,						///< Uses the @BP3D style. Deprecated since R17. Not needed anymore: now just one style.
	DR_COLORFIELD_ICC_BASEDOC							= 8,						///< Uses the color profile of the current BaseDocument.
	DR_COLORFIELD_ICC_BPTEX								= 16,						///< Uses the color profile of the current @BP3D texture.
	DR_COLORFIELD_NO_MODE_BUTTONS					= 32,						///< Hides the color mode buttons. @since R17.032
	DR_COLORFIELD_NO_COMPACT							= 33554432,			///< Hides the Compact Mode button. @since R18
	DR_COLORFIELD_NO_COLORWHEEL 					= 64,						///< Hides the Color Wheel mode button. @since R17.032
	DR_COLORFIELD_NO_SPECTRUM							= 128,					///< Hides the Color Spectrum mode button. @since R17.032
	DR_COLORFIELD_NO_PICTURE							= 256,					///< Hides the Color From Picture mode button. @since R17.032
	DR_COLORFIELD_NO_RGB									= 512,					///< Hides the RGB sliders mode button. @since R17.032
	DR_COLORFIELD_NO_HSV									= 1024,					///< Hides the HSV sliders mode button. @since R17.032
	DR_COLORFIELD_NO_KELVIN								= 2048,					///< Hides the Kelvin Color Temperature mode button. @since R17.032
	DR_COLORFIELD_NO_MIXER								= 4096,					///< Hides the Color Mixer mode button. @since R17.032
	DR_COLORFIELD_NO_SWATCHES							= 8192,					///< Hides the Swatches mode button. @since R17.032
	DR_COLORFIELD_NO_SCREENPICKER 				= 16384,				///< Hides the ScreenPicker mode button. @since R17.032
	DR_COLORFIELD_ENABLE_COMPACT					= 67108864,			///< Enables the Compact Mode. @since R18
	DR_COLORFIELD_ENABLE_COLORWHEEL 			= 32768,				///< Enables the Special Color Wheel mode (Special modes are exclusive each other: use only one at a time). @since R17.032
	DR_COLORFIELD_ENABLE_SPECTRUM					= 65536,				///< Enables the Special Color Spectrum mode (Special modes are exclusive each other: use only one at a time). @since R17.032
	DR_COLORFIELD_ENABLE_PICTURE					= 131072,				///< Enables the Special Color from Picture mode (Special modes are exclusive each other: use only one at a time). @since R17.032
	DR_COLORFIELD_ENABLE_RGB							= 262144,				///< Enables the RGB sliders mode. @since R17.032
	DR_COLORFIELD_ENABLE_HSV							= 524288,				///< Enables the HSV sliders mode. @since R17.032
	DR_COLORFIELD_ENABLE_KELVIN						= 1048576,			///< Enables the Kelvin Color Temperature mode. @since R17.032
	DR_COLORFIELD_ENABLE_MIXER						= 2097152,			///< Enables the Color Mixer mode. @since R17.032
	DR_COLORFIELD_ENABLE_SWATCHES					= 4194304,			///< Enables the Swatches mode. @since R17.032
	DR_COLORFIELD_RGB_HIDE_HEX						= 8388608,			///< Hides the Hexadecimal color field in the RGB Mode. @since R17.032
	DR_COLORFIELD_POPUP										= 16777216,			///< @markPrivate @since R17.032

	DROLDWIN_SDK	= 'sdk8',

	DIALOGRESOURCE_
};

/// @addtogroup CMD
/// @ingroup group_enumeration
/// @{
enum
{
	CMD_POPUP_RIGHT	= 1,
	CMD_POPUP_BELOW	= 2,
	CMD_PIC					= 4,
	CMD_TOGGLE			= 8,
	CMD_TEXT				= 16,
	CMD_SHORTCUT		= 32,
	CMD_ARROW				= 64,
	CMD_VERT				= 128,
	CMD_BUTTONLIKE	= 256,
	CMD_MENU				= 512,
	CMD_CYCLE				= 1024,
	CMD_EDITPALETTE	= 4096,
	CMD_SMALLICONS	= 8192,

	CMD_VALUE				= 0x3FFFFFFF,			///< Checked.
	CMD_ENABLED			= 0x40000000,			///< Enabled.

	CMD_
};
/// @}

/// @addtogroup POPUP
/// @ingroup group_enumeration
/// @{
enum
{
	POPUP_ABOVE						= 1,			///< Open above mouse.
	POPUP_BELOW						= 2,			///< Open below mouse.
	POPUP_CENTERVERT			= 3,			///< Open centered vertically around mouse.

	POPUP_LEFT						= 4,			///< Open to the left of the mouse.
	POPUP_RIGHT						= 8,			///< Open to the right of the mouse.
	POPUP_CENTERHORIZ			= 12,			///< Open centered horizontally around mouse.

	POPUP_ADJUSTWIDTH			= 16,			///< @markInternal
	POPUP_ADJUSTHEIGHT		= 32,			///< @markInternal

	POPUP_EXECUTECOMMANDS	= 64,			///< Execute commands immediately.

	POPUP_ALLOWUNDOCK			= 128,		///< Allow to undock popup menu.
	POPUP_ALLOWUNDOCK_REC	= 256,		///< Allow to undock popup menu for children.

	POPUP_ALLOW_FILTERING = 512,  // allow filtering of menu entries via keyboard typing

	POPUP_
};
/// @}

/// @addtogroup SCROLLGROUP
/// @ingroup group_enumeration
/// @{
enum
{
	SCROLLGROUP_VERT												= 4,				///< Allow the group to scroll vertically.
	SCROLLGROUP_HORIZ												= 8,				///< Allow the group to scroll horizontally.
	SCROLLGROUP_NOBLIT											= 16,				///< Always redraw the whole group, not just new areas, when scrolling.
	SCROLLGROUP_LEFT												= 32,				///< Create the vertical slider to the left.
	SCROLLGROUP_BORDERIN										= 64,				///< Display a small border around the scroll group.
	SCROLLGROUP_STATUSBAR										= 128,			///< Create a status bar for the scroll group.
	SCROLLGROUP_AUTOHORIZ										= 256,			///< Only show horizontal slider if needed.
	SCROLLGROUP_AUTOVERT										= 512,			///< Only show vertical slider if needed.
	SCROLLGROUP_NOSCROLLER									= 1024,			///< No scroller.
	SCROLLGROUP_NOVGAP											= 2048,			///< No vertical gap.
	SCROLLGROUP_STATUSBAR_EXT_GROUP					= 4096,			///< Create an extern group within the statusbar.\n
																											///< @b Example:
																											///< @code
																											/// ScrollGroupBegin(1000, BFH_SCALEFIT|BFV_SCALEFIT, SCROLLGROUP_VERT|SCROLLGROUP_HORIZ|SCROLLGROUP_STATUSBAR|SCROLLGROUP_STATUSBAR_EXT_GROUP|SCROLLGROUP_NOBLIT, 64, 64);
																											/// {
																											/// 	GroupBegin(0, BFH_SCALEFIT|BFV_SCALEFIT, 0, 0, "", 0);
																											/// 	{
																											/// 		AddButton(1001, BFH_LEFT, SizePix(256), SizePix(256), "Big Button");
																											/// 	}
																											/// 	GroupEnd();
																											/// }
																											/// GroupEnd();
																											///
																											/// LayoutFlushGroup(ID_SCROLLGROUP_STATUSBAR_EXTLEFT_GROUP);
																											/// GroupBorderSpace(2, 2, 2, 2);
																											/// AddStaticText(0, 0, 0, 0, "Value", 0);
																											/// AddEditNumberArrows(1002, BFH_LEFT|BFV_CENTER, 80, 10);
																											/// LayoutChanged(ID_SCROLLGROUP_STATUSBAR_EXTLEFT_GROUP);
																											/// @endcode
																											///< @image html statusbar_ext_group.png
	SCROLLGROUP_BORDERINb										= 16384,			///< Same as SCROLLGROUP_BORDERIN but open at bottom. @since R21

	ID_SCROLLGROUP_STATUSBAR_EXTLEFT_GROUP	= 200000239,			///< ID of the extern left scroll group statusbar group. @see SCROLLGROUP_STATUSBAR_EXT_GROUP
	ID_SCROLLGROUP_STATUSBAR_EXTRIGHT_GROUP	= 200000240				///< ID of the extern right scroll group statusbar group. @see SCROLLGROUP_STATUSBAR_EXT_GROUP
};
/// @}

/// @addtogroup MOUSESELECT
/// @ingroup group_enumeration
/// @{
enum
{
	MOUSESELECT_NOCROSSCURSOR	= 0x40000000,			///< No cross cursor. Can be combined with @ref MOUSESELECT_RECTANGLE/@ref MOUSESELECT_POLYGON/@ref MOUSESELECT_FREE. @c 1<<30
	MOUSESELECT_NOFILL				= 0x20000000,			///< No fill. @c 1<<29

	MOUSESELECT_RECTANGLE			= 1,			///< Rectangle selection.
	MOUSESELECT_POLYGON				= 2,			///< Polygon selection.
	MOUSESELECT_FREE					= 3,			///< Free selection.

	MOUSESELECT_OUTLINE_RECT	= MOUSESELECT_NOFILL | MOUSESELECT_RECTANGLE,			///< Outline rectangle.
	MOUSESELECT_OUTLINE_POLY	= MOUSESELECT_NOFILL | MOUSESELECT_POLYGON,				///< Outline polygon.
	MOUSESELECT_OUTLINE_FREE	= MOUSESELECT_NOFILL | MOUSESELECT_FREE						///< Outline free.
};
/// @}

/// @addtogroup MANAGER
/// @ingroup group_enumeration
/// @{
/// @markPrivate
enum
{
	MANAGER_NONE,

	MANAGER_SCROLLER_HORIZ,
	MANAGER_SCROLLER_VERT,
	MANAGER_CLOSEBUTTON,
	MANAGER_SIZEABLE,
	MANAGER_TITLE,
	MANAGER_ID,
	MANAGER_MENUID,
	MANAGER_NOBLITBIT,
	MANAGER_WANTOWNSTATUSBAR,

	MANAGER_DUMMY
};
/// @}

/// @addtogroup FOCUS
/// @ingroup group_enumeration
/// @{
enum
{
	FOCUS_OFF					= 0,			///< No focus.
	FOCUS_ON					= 1,			///< Focused, window active.
	FOCUS_INACT				= 2,			///< Focused, window inactive.
	FOCUS_HIDDEN			= 3,			///< Focus is hidden through ENTER.
	FOCUS_INPROGRESS	= 4,			///< Busy.
	FOCUS_
};
/// @}

/// @addtogroup BFM
/// @ingroup group_containerid
/// @{
enum
{
	BFM_INIT										= 'bINI',			///< Sent after an element has been created.

	BFM_TIMER_MESSAGE						= 10020,			///< Timer message. Use @ref GeDialog::SetTimer/@ref GeUserArea::SetTimer to set the periodical time.

	BFM_CALCSIZE								= 'bCAS',			///< Called if the element has to calculate its own minimum X and Y dimensions.

	BFM_CHECKCLOSE							= 'chkc',			///< Check if a dialog is able to close. Return @formatConstant{false} it is OK to close, otherwise @formatConstant{true}.
	BFM_CHECKCLOSE_LAYOUTSWITCH	= 'ccll',			///< Check if a dialog is able to close when layouts are switched. Return @formatConstant{false} it is OK to close, otherwise @formatConstant{true}.
	BFM_ASKCLOSE								= 'askc',			///< Ask if a dialog is able to close. Return @formatConstant{false} it is OK to close, otherwise @formatConstant{true}.
	BFM_DESTROY									= 'dsty',			///< Sent just before the window is destroyed.

	BFM_CLOSEWINDOW							= 'clos',			///< Send this message to close a dialog. @markInternal

	BFM_ASK_TABSWITCH						= 'stab',			///< Ask for switching tabs. @markInternal

	BFM_VISIBLE_ON							= 'visT',			///< An element gets this message if it comes to front after tabbing invisible. @markInternal
	BFM_VISIBLE_OFF							= 'visF',			///< An element gets this message if it went back (another tab becomes visible). @markInternal

	BFM_PARENT_TITLECHNG				= 'pren',			///< Parent notify about title change. @markInternal
	BFM_RENAMEWINDOW						= 'wren',			///< Send this (parent) message to rename a window. @markInternal

	BFM_GETACTIVETABTITLE				= 'tact',			///< Ask for active tab title. @markPrivate

	BFM_GETCURSORINFO						= 'cinf',			///< Respond this message to display any help information in the bubble help or global statusbar.\n
																						///< @ref BFM_DRAG_SCREENX and @ref BFM_DRAG_SCREENY are the input IDs.

	RESULT_CURSOR									= 1,			///< ::Int32 Mouse cursor: @enumerateEnum{MOUSE}
	RESULT_BUBBLEHELP							= 2,			///< String Bubble help text.
	RESULT_SUPPRESSBUBBLE					= 3,			///< ::Bool Suppress bubble help.
	RESULT_CURSOR_FORCE_HIDE			= 4,			///< ::Bool Return value for @c GetCursorInfo.\n
																					///< Set this to @formatConstant{true} in the result container to hide the cursor but to keep the cursor type.
																					///< @note Used for the stereoscopic viewport so that OpenGL can draw the perspective mouse.
	RESULT_CURSOR_NO_STEREO_HIDE	= 5,			///< ::Bool Overwrites @ref RESULT_CURSOR_FORCE_HIDE.
	RESULT_HELP1									= 10,			///< String Help 1. @markInternal
	RESULT_HELP2									= 11,			///< String Help 2. @markInternal
	RESULT_HELP3									= 12,			///< String Help 3. @markInternal
	RESULT_HELP4									= 13,			///< String Help 4. @markInternal
	RESULT_BUBBLEHELP_TITLE				= 20,			///< String Bubble help text title. Printed in bold for the bubble help, not visible in the status bar.

	BFM_CURSORINFO_REMOVE					= 'cirm',			///< Sent when mouse cursor has left a user area. @see RemoveLastCursorInfo()
	BFM_SETCURSORINFO							= 'setc',			///< Same as @ref BFM_EDITFIELD_SETCURSORPOS.
	BFM_GETINFO										= 'bInf',			///< @markPrivate

	BFM_DRAW											= 'bDRA',			///< Redraw message for user areas:
	BFM_DRAW_LEFT			= 1,			///< ::Int32 Left clipping.
	BFM_DRAW_TOP			= 2,			///< ::Int32 Top clipping.
	BFM_DRAW_RIGHT		= 3,			///< ::Int32 Right clipping.
	BFM_DRAW_BOTTOM		= 4,			///< ::Int32 Bottom clipping.
	BFM_DRAW_HASRECT	= 5,			///< ::Bool Flag for an existing redraw rectangle. @markInternal
	BFM_DRAW_OGL			= 6,			///< ::Bool OpenGL flag. @markInternal
	BFM_DRAW_REASON		= 7,			///< BaseContainer Message which started the redraw.

	BFM_SHOW_AREA											= 'sare',			///< Scrolls the visible rectangle defined with [@ref BFM_DRAW_LEFT, @ref BFM_DRAW_TOP, @ref BFM_DRAW_RIGHT, @ref BFM_DRAW_BOTTOM]. @markInternal

	BFM_SCROLLGROUP_SCROLLED					= 'scrs',
	///< Scroll group scrolled.\n
	///< Use this together with a scroll group header user area with ID @ref SCROLLGROUP_HEADER to get information about when the group has scrolled:
	/// @code
	/// ...
	/// GroupBegin(0, BFH_SCALEFIT | BFV_SCALEFIT, 1, 0, String(),0);
	/// 	GroupSpace(0, 0);
	/// 	ScrollGroupBegin(IDC_SCROLL_GROUP, BFH_SCALEFIT | BFV_SCALEFIT,
	/// 	(m_bBorder ? SCROLLGROUP_BORDERIN : 0) | SCROLLGROUP_HORIZ | SCROLLGROUP_VERT | SCROLLGROUP_AUTOHORIZ | SCROLLGROUP_AUTOVERT);
	/// 	m_pHeaderArea = AddUserArea(SCROLLGROUP_HEADER, BFH_SCALEFIT | BFV_TOP);
	/// 	m_pUserArea   = AddUserArea(IDC_USER_AREA, BFH_SCALEFIT | BFV_SCALEFIT);
	/// 	GroupEnd();
	/// GroupEnd();
	/// AttachUserArea(m_wndHeaderArea, m_pHeaderArea);
	/// ...
	///
	/// Int32 MyDialog::Message(const BaseContainer& msg, BaseContainer& result)
	/// {
	/// 	switch (msg.GetId())
	/// 	{
	/// 	case BFM_SCROLLGROUP_SCROLLED:
	/// 		if (m_bHasHeader)
	/// 		{
	/// 			Int32 chgh = msg.GetInt32(0);
	/// 			Int32 chgv = msg.GetInt32(1);
	/// 			Int32 xoff = msg.GetInt32(2);
	/// 			Int32 yoff = msg.GetInt32(3);
	/// 			if (chgh)
	/// 				m_wndHeaderArea.Redraw();
	/// 		}
	/// 		break;
	/// 	}
	///
	/// 	return SUPER::Message(msg, result);
	/// }
	/// @endcode

	SCROLLGROUP_HEADER	= 0xdeadbeee,			///< Scroll group header ID.

	BFM_TITLECHNG											= 'bTIC',			///< Notify about title change. @markPrivate

	BFM_ENABLE												= 'bEna',			///< Enables the element. @markInternal
	BFM_DISABLE												= 'bDis',			///< Disables the element. @markInternal

	BFM_MINCHNG												= 'bMIC',			///< @markPrivate
	BFM_MAXCHNG												= 'bMAC',			///< @markPrivate

	BFM_VALUECHNG											= 'bVAC',			///< Value changed. @markPrivate

	BFM_IDCHNG												= 'bIDC',			///< @markPrivate

	BFM_GOTFOCUS											= 'bGFC',			///< Item got the focus.
	BFM_LOSTFOCUS											= 'bLFC',			///< Item lost the focus.

	BFM_SETFOCUS											= 'bSFC',			///< @markInternal
	BFM_SETFIRSTFOCUS									= 'bSFF',			///< @markInternal

	BFM_MOVEFOCUSNEXT									= 'bFNX',			///< @markPrivate
	BFM_MOVEFOCUSPREV									= 'bFPR',			///< @markPrivate

	BFM_SETLASTFOCUS									= 'bSLF',			///< @markPrivate

	BFM_GETFOCUSBEFOREUPDATE					= 'bGFU',			///< A custom GUI receives this message before the layout is updated. This is used to avoid losing the focus over a specific gadget after the layout is updated.
																									///< @see BFM_SETFOCUSAFTERUPDATE
																									///< @note These messages are only sent if the customgui is used inside the Attribute Manager and not when it is used in any other GeDialog.
																									/// @code
																									/// Int32 MyCustomGui::Message(const BaseContainer &msg, BaseContainer &result)
																									/// {
																									/// 	...
																									///
																									/// 	switch (msg.GetId())
																									/// 	{
																									/// 		case BFM_GETFOCUSBEFOREUPDATE: // Layout is about to update and active gadget could lose focus: store it
																									///			{
																									///				Int32 activeGadgetId = NOTOK;
																									///				if (IsActive(MY_BUTTON_ID)) activeGadgetId = MY_BUTTON_ID;
																									///				else if (IsActive(MY_USERAREA_ID)) activeGadgetId = MY_USERAREA_ID;
																									///				if (IsActive(MY_COLORFIELD_ID)) activeGadgetId = MY_COLORFIELD_ID;
																									///				result.SetInt32(0, activeGadgetId); // activeGadgetId is a usual gadget id, e.g. AddButton(MY_BUTTON_ID, BFH_LEFT, 0, 0 "My Button");
																									/// 			return true;
																									/// 			break;
																									///			}
																									///
																									/// 		case BFM_SETFOCUSAFTERUPDATE: // Layout has been updated (focus is in first gadget now): reactivate '_activeGadgetId'
																									///			{
																									///				Int32 activeGadgetId = msg.GetInt32(0);
																									///				if (activeGadgetId != NOTOK)
																									///					Activate(activeGadgetId);
																									/// 			return true;
																									/// 			break;
																									///			}
																									///
																									/// 		...
																									/// 	}
																									///
																									/// 	return SUPER::Message(msg, result);
																									/// }
																									/// @endcode
																									/// @since R18

	BFM_SETFOCUSAFTERUPDATE						= 'bSFU',			///< A custom GUI description receives this message after the layout is updated to reactivate previously focused gadget.
																									///< @see BFM_GETFOCUSBEFOREUPDATE
																									///< @since R18

	BFM_SHOW_FRAME										= 'sFrm',			///< Brings the frame to front. Return @formatConstant{true} if found. @markInternal
	BFM_SHOW_ID			= 1,			///< ::Int32 Frame ID. @markInternal
	BFM_MANAGER_ID	= 2,			///< ::Int32 Manager ID. @markInternal

	BFM_CHILD_REMOVED									= 'bRem',			///< @markPrivate
	BFM_CHILD_ID	= 1,			///< ::Int32 @markPrivate

	BFM_ACTIVATE_WINDOW								= 'wact',			///< @markPrivate

	BFM_INPUT													= 'bIPN',			///< A dialog/user area receives this message if any mouse or keyboard input is received. See @link page_input_events Input Events@endlink for more information.
	BFM_INPUT_QUALIFIER								= 'ipqa',			///< ::Int32 A bit mask with the qualifiers at the time when the event occurred: @enumerateEnum{QUALIFIER}
	BFM_INPUT_MODIFIERS								= 'ipmo',			///< ::Int32 Same as @ref BFM_INPUT_QUALIFIER but also contains bits > @em 0xf. @markPrivate
	BFM_INPUT_DEVICE									= 'ipdv',			///< ::Int32 Device:
	BFM_INPUT_MOUSE										= 'mous',			///< Mouse.
	BFM_INPUT_KEYBOARD								= 'keyb',			///< Keyboard.
	BFM_INPUT_ASC											= 'kasc',			///< String Contains the Unicode input from keyboard

	BFM_INPUT_CHANNEL									= 'ipca',			///< ::Int32 Contains the key or mouse button. See also @ref KEY.
	BFM_INPUT_MOUSELEFT		= 1,				///< Left mouse button.
	BFM_INPUT_MOUSERIGHT	= 2,				///< Right mouse button.
	BFM_INPUT_MOUSEMIDDLE	= 3,				///< Middle mouse button.
	BFM_INPUT_MOUSEX1			= 5,				///< Fourth mouse button.
	BFM_INPUT_MOUSEX2			= 6,				///< Five mouse button.
	BFM_INPUT_MOUSEWHEEL	= 100,			///< Mouse wheel or panning on touch pad or touch screen. Values in BFM_INPUT_HSCROLL, BFM_INPUT_VSCROLL.
	BFM_INPUT_MOUSEMOVE		= 101,			///< Mouse move.
	BFM_INPUT_MAGNIFY			= 102,			///< Zoom guesture on touch pad or touch screen (or mouse scroll with ctrl to indicate zoom). Value in BFM_INPUT_VALUE_REAL.

	BFM_INPUT_VALUE										= 'ipva',			///< ::Int32 Value of the input channel (@formatConstant{true}/@formatConstant{false} or a ::Int32 value, e.g. for scroll wheel data). @see BFM_INPUT_VALUE_REAL
	BFM_INPUT_VALUE_REAL							= 'ipvA',			///< ::Float Channel value (e.g. pen pressure).
	BFM_INPUT_X												= 'ipvx',			///< ::Float X value.
	BFM_INPUT_Y												= 'ipvy',			///< ::Float Y value.
	BFM_INPUT_Z												= 'ipvz',			///< ::Float Z value.
	BFM_INPUT_TILT										= 'itlt',			///< ::Float Pen tilt.
	BFM_INPUT_ORIENTATION							= 'irot',			///< ::Float Pen rotation.
	BFM_INPUT_FINGERWHEEL							= 'ifng',			///< ::Float Finger wheel (tangential pen pressure).
	BFM_INPUT_P_ROTATION							= 'prot',			///< ::Float Pen rotation around its own axis.
	BFM_INPUT_HSCROLL									= 'ihsc',			///< ::Float amount of horizontal scrolling (touch pad, mouse ball)
	BFM_INPUT_VSCROLL									= 'ivsc',			///< ::Float amount of vertical scrolling (touch pad, mouse wheel/ball)
	BFM_INPUT_MULTITOUCHSCROLL				= 'imsc',			///< ::Bool True for scroll events on a multitouch device (which also supports magnify), false for scroll-only mice.
	BFM_INPUT_TIMESTAMP								= 'itms',			///< ::Float Time stamp of the event or 0.0 (unavailable).

	BFM_INPUT_DOUBLECLICK							= 'ipdb',			///< ::Bool Double click.
	INPUT_DBLCLK											= 0x8000,			///< Mouse qualifier flag for double click. @markInternal

	BFM_SIZED													= 'bISI',			///< Element has been sized.

	BFM_ACTION												= 'bACT',			///< One of the child elements made any action:
	BFM_ACTION_ID			= 'meid',			///< ::Int32 ID of the dialog element that triggered the action.
	BFM_ACTION_VALUE	= 'meva',			///< ::GeData Action value.
	BFM_ACTION_INDRAG	= 'medr',			///< ::Bool Slider in dragging mode (not finished).
	BFM_ACTION_STRCHG	= 'mest',			///< ::Bool String in text field changed.
	BFM_ACTION_VALCHG	= 'vchg',			///< ::Bool Edit/slider changed.
	BFM_ACTION_ESC		= 'aesc',			///< ::Bool Action escaped. @markInternal
	BFM_ACTION_RESET	= 'ares',			///< ::Bool Reset to default value on right-click of input field arrows.
	BFM_ACTION_UPDATE	= 'updt',			///< ::Bool Update without verify. @markInternal

	BFM_COLORCHOOSER_PARENTMESSAGE		= 'colP',			///< Color chooser parent message.
	BFM_COLORCHOOSER									= 'colC',			///< Color chooser settings:
	BFM_COLORCHOOSER_RGB_RANGE			= 2,			///< ::Int32 RGB range: @enumerateEnum{COLORSYSTEM_RANGE}
	BFM_COLORCHOOSER_SYSTEMMESSAGE	= 5,			///< ::Bool Sends a parent message @ref BFM_COLORCHOOSER_PARENTMESSAGE if the settings change.

	BFM_GET_FOCUS_RECTANGLE		= 'gfRc',			///< Returns the coordinates of the input field with the current focus.\n
																					///< Tells OS X the input cursor position to get the input popup on Japanese systems. @markInternal
	BFM_GET_FOCUS_RECTANGLE_X	= 0,			///< ::Int32 Input field X coordinate.
	BFM_GET_FOCUS_RECTANGLE_Y	= 1,			///< ::Int32 Input field Y coordinate.
	BFM_GET_FOCUS_RECTANGLE_W	= 2,			///< ::Int32 Input field width.
	BFM_GET_FOCUS_RECTANGLE_H	= 3,			///< ::Int32 Input field height.

	BFM_ACTIVE_CHG										= 'bACG',			///< @markPrivate
	BFM_ACTIVE												= 'actv',			///< ::Bool @markPrivate

	BFM_DRAGSTART											= 10001,			///< Sent before drag and drop. @markInternal
	BFM_DRAGRECEIVE										= 10003,			///< Drag receive. (See DragAndDrop.)
	BFM_DRAGEND												= 10004,			///< Sent after drag and drop. @markInternal
	BFM_DRAGAUTOSCROLL								= 10005,			///< Sent to the gadget under the mouse cursor to ask for auto-scrolling during drag and drop. @link AUTOSCROLL_UP  AUTOSCROLL@endlink @markInternal

	DRAGTYPE_FILES										= 1,			///< Files. The data is a string with the Filename.
	DRAGTYPE_ICON											= 4,			///< Icon.
	DRAGTYPE_MANAGER									= 5,			///< Destination drag for C.O.F.F.E.E. manager.
	DRAGTYPE_COMMAND									= 6,			///< Destination drag for command.
	DRAGTYPE_CMDPALETTE								= 7,			///< Command palette.

	DRAGTYPE_DESCID										= 113,			///< Description ID. The data is of type DescPropertyDragData.

	DRAGTYPE_ATOMARRAY								= 201,			///< AtomArray.
	DRAGTYPE_FILENAME_IMAGE						= 202,			///< Texture filename.
	DRAGTYPE_RGB											= 203,			///< RGB color.
	DRAGTYPE_FILENAME_SCENE						= 204,			///< Scene filename.
	DRAGTYPE_FILENAME_OTHER						= 205,			///< Other filename.
	DRAGTYPE_RGB_ARRAY								= 206, 			///< Color array. Data received is @ref maxon::BaseArray<@ref Vector>*. @since R17.032
	DRAGTYPE_RGBA_ARRAY								= 207, 			///< Color with alpha array. Data received is @ref maxon::BaseArray<@ref maxon::ColorA>*. @since R20

	BFM_DRAG_DATA_										= 2,			///< ANY Drag data. @markInternal
	BFM_DRAG_SCREENX									= 3,			///< ::Int32 Screen X.
	BFM_DRAG_SCREENY									= 4,			///< ::Int32 Screen Y.
	BFM_DRAG_FINISHED									= 5,			///< ::Bool Drag finished.
	BFM_DRAG_PRIVATE									= 6,			///< ::Bool Private drag.
	BFM_DRAG_LOST											= 7,			///< ::Bool Drag lost.
	BFM_DRAG_TYPE_NEW									= 8,			///< ::Int32 Drag type: @link DRAGTYPE_FILES DRAGTYPE@endlink
	BFM_DRAG_DATA_NEW									= 9,			///< ANY Internal drag data.
	BFM_DRAG_ESC											= 10,			///< ::Bool Drag escaped.

	AUTOSCROLL_UP											= 1,			///< Scroll up.
	AUTOSCROLL_DOWN										= 2,			///< Scroll down.
	AUTOSCROLL_LEFT										= 3,			///< Scroll left.
	AUTOSCROLL_RIGHT									= 4,			///< Scroll right.
	AUTOSCROLL_LEFT_UP								= 7,			///< Scroll left up.
	AUTOSCROLL_LEFT_DOWN							= 8,			///< Scroll left down.
	AUTOSCROLL_RIGHT_UP								= 9,			///< Scroll right up.
	AUTOSCROLL_RIGHT_DOWN							= 10,			///< Scroll right down.

	HANDLEMOUSEDRAG_PRIVATEFRAME			= 1,			///< @markPrivate
	HANDLEMOUSEDRAG_PRIVATEAUTOSCROLL	= 2,			///< @markPrivate

	BFM_GETVALUE					= 'gVAL',			///< @markPrivate

	BFM_VALUEADD					= 'bVAD',			///< @markPrivate
	BFM_VALUESUB					= 'bVSB',			///< @markPrivate

	BFM_INITVALUES				= 'bVIN',			///< Sent after the layout is done.
																			///< @see GeDialog::InitValues GeUserArea::InitValues ProgressDialog::InitValues

	BFM_ADJUSTSIZE				= 'fADJ',			///< @markPrivate

	BFM_ADJUSTSIZE_LEFT		= 1,			///< ::Int32
	BFM_ADJUSTSIZE_TOP		= 2,			///< ::Int32
	BFM_ADJUSTSIZE_WIDTH	= 3,			///< ::Int32
	BFM_ADJUSTSIZE_HEIGHT	= 4,			///< ::Int32

	//	BFM_GETDISABLED			= 'bDIS',	// ask parents, if they are disables

	BFM_LAYOUT_CHANGED							= 'fLAY',			///< Sent to parent about layout changes. Forces recalculation of the layout. @markInternal

	BFM_FULLSCREENMODE_ON						= 'ful1',			///< Dialog went to fullscreen mode. @markInternal
	BFM_FULLSCREENMODE_OFF					= 'ful0',			///< Dialog left fullscreen mode. @markInternal

	BFM_ISACTIVE										= 'iact',			///< @markPrivate

	BFM_SETSTATUSBAR								= 'stat',			///< To set a statusbar (e.g. inside a SCROLLGROUP (dialog element)):

	BFM_STATUSBAR_PROGRESSON				= 1,			///< ::Bool Statusbar active.
	BFM_STATUSBAR_TXT								= 2,			///< String First text.
	BFM_STATUSBAR_PROGRESS					= 3,			///< ::Float Between @em 0.0 and @em 1.0.
	BFM_STATUSBAR_PROGRESSSPIN			= 4,			///< ::Bool Spinning bar.
	BFM_STATUSBAR_HELP							= 5,			///< String Second text. (Help.)
	BFM_STATUSBAR_PROGRESSFULLSIZE	= 6,			///< ::Bool Use full-sized progress bar. @markInternal
	BFM_STATUSBAR_TINT_COLOR				= 7,			///< ::Int32 Color ID for the status bar, or as RGB value (Vector).
	BFM_STATUSBAR_NETTINT_COLOR			= 8,			///< ::Int32 Color ID for the NET status bar, or as RGB value (Vector). @markInternal
	BFM_STATUSBAR_NETPROGRESSON			= 9,			///< ::Bool NET statusbar active. @markInternal
	BFM_STATUSBAR_NETTXT						= 10,			///< String NET first text. @markInternal
	BFM_STATUSBAR_NETPROGRESS				= 11,			///< ::Float Between @em 0.0 and @em 1.0. @markInternal
	BFM_STATUSBAR_NETPROGRESSSPIN		= 12,			///< ::Bool NET spinning bar. @markInternal

	BFM_MARKFOCUS											= 'bMFC',			///< @markPrivate Revert focus message. For internal use only.

	BFM_CLEARFOCUS										= 'bCFC',			///< @markPrivate Clear focus of all children.

	BFM_SETACTIVE											= 'bSAC',			///< @markPrivate

	BFM_SETACTIVE_DATA	= 'bSAC',			///< @markPrivate

	BFM_REMOVE_DIALOG									= 'bREM',			///< Removes the dialog from the current group. @markInternal

	BFM_DESTINATION_GROUP	= 'gdst',			///< Destination dialog group, @formatConstant{nullptr} for an own window. @markInternal

	BFM_SCROLLAREA										= 10010,			///< To scroll a scroll area: @markInternal

	BFM_SCROLLX	= 1,			///< ::Int32 X direction. @markInternal
	BFM_SCROLLY	= 2,			///< ::Int32 Y direction. @markInternal

	BFM_GETVISIBLE_XOFF								= 10011,			///< @markPrivate
	BFM_GETVISIBLE_YOFF								= 10012,			///< @markPrivate
	BFM_GETVISIBLE_WIDTH							= 10013,			///< @markPrivate
	BFM_GETVISIBLE_HEIGHT							= 10014,			///< @markPrivate

	SCR_VISIBLEOBJS										= 'sVIS',			///< @markPrivate Visible scroll elements.

	BFM_SETVIEWPORTORIGIN							= 'cORG',			///< Set the scroll area origin: @markInternal

	BFM_SETVIEWPORTORIGIN_X	= 1,			///< ::Int32 X coordinate. @markInternal
	BFM_SETVIEWPORTORIGIN_Y	= 2,			///< ::Int32 Y coordinate. @markInternal

	BFM_SETVIEWPORTSIZE								= 'cSIZ',			///< @markPrivate

	BFM_MENU_SET											= 10000,			///< ::Int32 @markPrivate :

	BFM_MENU_ON				= 1,	///< @markInternal
	BFM_MENU_OFF			= 2,	///< @markInternal
	BFM_MENU_CHECK		= 4,	///< @markInternal
	BFM_MENU_UNCHECK	= 8,	///< @markInternal

	BFM_DRAWUSERITEM									= 'usrd',			///< @markPrivate

	BFM_DRAWUSERITEM_ID	= 1, ///< @markInternal

	BFM_SYNC_MESSAGE									= 'sync',			///< Sync message.
	BFM_CORE_MESSAGE									= 'MciM',			///< Core message: (See @link page_core_messages Core Messages@endlink.)

	BFM_CORE_ID							= 'MciI',			///< ::Int32 Core message ID.
	BFM_CORE_UNIQUEID				= 'Muid',			///< ::Int32 Time stamp.
	BFM_CORE_PAR1						= 'Mci1',			///< ANY Parameter 1.
	BFM_CORE_PAR2						= 'Mci2',			///< ANY Parameter 2.
	BFM_CORE_SPECIALCOREID	= 'scid',			///< ::Int32 Special manager ID for sync message.

	BFM_TESTONLY													= 'test',			///< @markPrivate
	BFM_SPECIALGETSTRING									= 'gtst',			///< @markPrivate
	BFM_SPECIALSETRANGE										= 'srng',			///< @markPrivate
	BFM_SPECIALMODE												= 'srnm',			///< Set the multi-line edit field to the right language mode.\n
																											///< Internal code:
																											/// @code
																											/// case BFM_SPECIALMODE:
																											/// {
																											/// 	SCRIPTMODE mode = (SCRIPTMODE)msg.GetInt32(1, SCRIPTMODE::PYTHON);
																											/// 	if (textfile)
																											/// 		textfile->python = mode==SCRIPTMODE::PYTHON;
																											/// 	break;
																											/// }
																											/// @endcode
	BFM_SETSPECIALMULTI										= 'SSSS',			///< @markPrivate
	BFM_SETSPECIALMULTID									= 'SSSD',			///< @markPrivate

	BFM_POPUPNOTIFY										= 'popn',			///< Notification of popup before the menu opens.

	BFM_INTERACTSTART									= 'inta',			///< Sent when user interaction starts. Dialogs should capture this message and stop threads that work on the scene data.\n
																									///< The GeDialog class already overloads this message to ensure that user interactions stop redraws etc.:
																									/// @code
																									/// Int32 GeDialog::Message(const BaseContainer &msg,BaseContainer &result)
																									/// {
																									/// 	...
																									///
																									/// 	switch (msg.GetId())
																									/// 	{
																									/// 		case BFM_INTERACTSTART: // Interact stop
																									/// 			StopAllThreads();
																									/// 			break;
																									///
																									/// 		...
																									/// 	}
																									///
																									/// 	return false;
																									/// }
																									/// @endcode
	BFM_INTERACTEND										= 'inte',			///< Sent when user interaction ends.

	BFM_CORE_UPDATECOMMANDS						= 'updc',			///< Update all command buttons. @markInternal

	BF_INSERT_LAST										= 2147483647,	///< @markPrivate

	BFM_MENUFINDER										= 'find',			///< @markPrivate
	BFM_SET_MSG_BITMASK								= 'bitm',			///< @markPrivate

	BITMASK_CORE_MESSAGE	= 1,
	BITMASK_SYNC_MESSAGE	= 2,

	BFM_SETMAINTITLE									= 'mtit',			///< @markPrivate

	BFM_GETVIEWPANELDATA							= 'vpdt',			///< @markPrivate

	BFM_GETVIEWPANEL_PRIVATEDATA			= 'vppd',			///< @markPrivate
	BFM_SETVIEWPANELLAYOUT						= 'vpsl',			///< @markPrivate

	BFM_VPD_PANELID			= 'vpid',	///< @markPrivate
	BFM_VPD_LAYOUTTYPE	= 'vplt',	///< @markPrivate
	BFM_VPD_MAXIMIZED		= 'vpmx',	///< @markPrivate
	BFM_VPD_PRIVATEDATA	= 'vpdt',	///< @markPrivate

	BFM_STORE_WEIGHTS									= 'stwg',			///< @markPrivate
	BFM_MARKFORCELAYOUT								= 'mkfl',			///< @markPrivate

	BFM_REDRAW_EDITMODE								= 'dwed',			///< @markPrivate
	BFM_RELOAD_MENUS									= 'ldmn',			///< @markPrivate
	BFM_OPTIMIZE											= 'opti',			///< @markPrivate
	BFM_CORE_UPDATEACTIVECOMMANDS			= 'upda',			///< @markPrivate

	BFM_UPDATE_REGION									= 'uprg',			///< @markPrivate
	BFM_GUIPREFSCHANGED								= 'gpch',			///< @markPrivate
	BFM_COMMANDSCHANGED								= 'cmch',			///< @markPrivate Internal message that is sent around if some commands changed their status:
																									/// @code
																									/// SendCoreMessage(COREMSG_CINEMA,BaseContainer(COREMSG_UPDATECOMMANDSMESSAGE));
																									/// @endcode

	BFM_LAYOUT_GETDATA								= 'layg',			///< Sent when saving the layout. Return a container to store with the layout for this dialog.\n
																									///< Used for example by the Attribute Manager to store its mask settings.
	BFM_LAYOUT_SETDATA								= 'lays',			///< Receive the container saved with @ref BFM_LAYOUT_GETDATA when loading a layout.

	BFM_GETCUSTOMGUILAYOUTDATA				= 'layG',			///< @markPrivate

	BFM_WEIGHTS_CHANGED								= 'wChg',			///< Group weights changed. The group ID is returned.

	BFM_GETPARENT_MANAGER_ID					= 'gpid',			///< @markPrivate

	BFM_EDITFIELD_GETCURSORPOS				= 'getc',			///< ::Int32 Return the cursor position in an edit field.
	BFM_EDITFIELD_GETBLOCKSTART				= 'getb',			///< ::Int32 Returns the block start position in an edit field.
	BFM_EDITFIELD_SETCURSORPOS				= 'setc',			///< ::Int32 Set the cursor position in an edit field.\n
																									///< Internal code:
																									/// @code
																									/// case BFM_EDITFIELD_SETCURSORPOS:
																									/// {
																									/// 	Int32 pos=m.GetInt32(1), redraw;
																									/// 	redraw=SetCursorPos(pos);
																									/// 	redraw+=SetBlockStartPos(pos);
																									/// 	if(redraw) Redraw();
																									/// 	return SUPER::CbMessage(m);
																									/// }
																									/// @endcode

	BFM_FADE													= 'fade',			///< Sent to blend GUI color with ease in a GeUserArea.\n
																									///< The example below blends the background of the icon button from ::COLOR_BG to ::COLOR_BG_HIGHLIGHT:
																									/// @code
																									/// Int32 BitmapButton::Message(const BaseContainer &msg,BaseContainer &result)
																									/// {
																									/// 	switch (msg.GetId())
																									/// 	{
																									/// 		case BFM_FADE:
																									/// 			AdjustColor(COLOR_BG,COLOR_BG_HIGHLIGHT,msg.GetFloat(BFM_FADE));
																									/// 			Redraw();
																									/// 			break;
																									/// 	}
																									/// }
																									/// @endcode
	BFM_FADE_REMOVEALL								= 'FADE',			///< @markPrivate

	BFM_EDITFIELD_STOREUNDO						= 'stru',			///< Stores the undo container for a multi-line edit text.
	BFM_EDITFIELD_RESTOREUNDO					= 'rstu',			///< Restore the undo container for a multi-line edit text.
	BFM_EDITFIELD_FLUSHUNDO						= 'flun',			///< Flushes the undo stack for a multi-line edit text
	BFM_EDITFIELD_GETUNDOSTATS				= 'unst',			///< Get the undo statistics for a multi-line edit text. @markInternal

	BFM_EDITFIELD_UNDOSTAT_COUNT			= 1,			///< ::Int32 The undo stack size.
	BFM_EDITFIELD_UNDOSTAT_UNDOLEVEL	= 2,			///< ::Int32 The current undo level.

	BFM_REQUIRESRESULT								= 'reqr',			///< Set to @formatConstant{true} in the passed container for GeDialog::SendMessage to return a value from the message.

	BFM_SCROLLGROUP_SCALE							= 'scsc',			///< @markprivate

	BFM_DUMMY													= 0
};
/// @}

/// @addtogroup GUI_DIALOG
/// @ingroup group_enumeration
/// @{
/// @markPrivate
enum
{
	GUI_DIALOG_MINIMIZE	= 1000,
	GUI_DIALOG_RELEASE	= 1001,
	GUI_DIALOG_CLOSE		= 1002
};
/// @}

#endif // GUI_H__
