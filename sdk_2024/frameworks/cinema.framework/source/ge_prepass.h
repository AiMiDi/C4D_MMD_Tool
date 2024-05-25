/////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////
// Cinema 4D SDK                                           //
/////////////////////////////////////////////////////////////
// (c) MAXON Computer GmbH, all rights reserved            //
/////////////////////////////////////////////////////////////

/// @defgroup group_enumeration Enumeration

/// @defgroup group_containerid Container ID

/// @defgroup group_macro Macro

/// @defgroup group_library Library

/// @defgroup group_function Function

#ifndef GE_PREPASS_H__
#define GE_PREPASS_H__

#include "ge_math.h"

#ifdef CINEWARE_NAMESPACE_ENABLE
	CINEWARE_NAMESPACE_BEGIN
#endif

/// @addtogroup MACFILE
/// @ingroup group_enumeration
/// @{
#define MACTYPE_CINEMA		'C4DC'		///< Standard Mac type code for @C4D.
#define MACCREATOR_CINEMA	'C4D1'		///< Standard Mac creator code for @C4D.
/// @}

/// Maximum image resolution. @note If changed, also change @c MAXMIPANZ.
#define MAX_IMAGE_RESOLUTION 128000

/// Segment of a bezier path. A Bezier path is a cubic parametric curve defined by a start point and a set of segments defining a smooth continuous curve.
/// For each segment the curve runs from the previous segment's end point towards the first control point (c1), then bends to the second control point (c2) and ends up at the end point (p).
/// The two control points (c1, c2) determine the direction of the curve at its end.
struct BezierPoint
{
	BezierPoint() {}
	BezierPoint(const Vector2d& ic1, const Vector2d& ic2, const Vector2d& ip2) : c1(ic1), c2(ic2), p(ip2) { }
	BezierPoint(Vector2d&& ic1, Vector2d&& ic2, Vector2d&& ip2) : c1(std::move(ic1)), c2(std::move(ic2)), p(std::move(ip2)) { }

	Vector2d c1;	///< control point 1.
	Vector2d c2;	///< control point 2.
	Vector2d p;  	///< end point.
};

enum class LINESTYLE
{
	NORMAL,
	DOTTED,
	DASHED,
	DASHED_INV,
	DASHED_BIG,
} MAXON_ENUM_LIST(LINESTYLE);

/// @addtogroup SERVERMESSAGE
/// @ingroup group_enumeration
/// @{
enum class SERVERMESSAGE
{
	NONE		= 0,				///< None.

	WARNING	= 1000,			///< Warning.
	ERROR_	= 1001,			///< Error.
	INFO		= 1002			///< Info.
} MAXON_ENUM_LIST(SERVERMESSAGE);
/// @}

/// @addtogroup RENDERJOBLIST
/// @ingroup group_enumeration
/// @{
enum class RENDERJOBLIST
{
	INACTIVE	= 1 << 1,			///< Inactive.
	ACTIVE		= 1 << 2,			///< Active.
	LOAD			= 1 << 3,			///< Load.
	ALL				= 14					///< All: @ref RENDERJOBLIST::INACTIVE | @ref RENDERJOBLIST::ACTIVE | @ref RENDERJOBLIST::LOAD.
} MAXON_ENUM_FLAGS(RENDERJOBLIST);
/// @}

/// @addtogroup MESSAGERESULT
/// @ingroup group_enumeration
/// @{
enum class MESSAGERESULT
{
	OK = 1000,					///< Ok.
	NETWORKERROR,				///< Network error.
	UNKNOWNERROR,				///< Unknown error.
	MEMORYERROR					///< Memory error.
} MAXON_ENUM_LIST(MESSAGERESULT);
/// @}

/// @addtogroup MACHINELIST
/// @ingroup group_enumeration
/// @{
enum class MACHINELIST
{
	ONLINE	= 1 << 1,			///< Online.
	OFFLINE	= 1 << 0,			///< Offline.
	ALL			= 7,					///< All: @ref MACHINELIST::ONLINE | @ref MACHINELIST::OFFLINE.
} MAXON_ENUM_FLAGS(MACHINELIST);
/// @}

/// @addtogroup VERIFICATIONBIT
/// @ingroup group_enumeration
/// @{
enum class VERIFICATIONBIT
{
	NONE				= 0,					///< None.
	ONLINE			= 1 << 0,			///< Online.
	VERIFIED		= 1 << 1,			///< Verified.
	VERIFIEDME	= 1 << 2,			///< Certified client (set on client for server).
	SHARED			= 1 << 3,			///< Shared.
	VERIFYING		= 1 << 4,			///< Verifying.

	// Error bits
	// If an enum is added, also add it to netrender/source/common.cpp#GetErrorVerificationBits
	FAILURE								= 1 << 5,					///< Unknown.
	SECURITYTOKENCHANGED	= 1 << 7,					///< Security token changed.
	WRONGBUILDID					= 1 << 8,					///< Wrong build ID.
	WRONGARCHITECTURE			= 1 << 9,					///< Wrong architecture.
	NOTREACHABLE					= 1 << 10,				///< Remote not reachable.
	NOANSWER							= 1 << 11,				///< This not reachable.
	WRONGSECURITYTOKEN		= 1 << 12,				///< Wrong security token.
	DEMONOTACTIVATED			= 1 << 13,				///< Demo not activated.
	REMOVING							= 1 << 14,				///< Removing.
	NORENDERSUPPORT				= 1 << 15,				///< No render support.

	INITIALIZING						= 1 << 16,			///< GUI flag only to show a please wait indicator on startup.
	VERIFICATIONESTABLISHED = 1 << 17,			///< Set soon after the persistent connection has been registered. Can be set without @ref VERIFICATIONBIT::VERIFIED on first connect and host adds itself on the server.
} MAXON_ENUM_FLAGS(VERIFICATIONBIT);
/// @}

/// @addtogroup RENDERJOBCREATOR
/// @ingroup group_enumeration
/// @{
enum class RENDERJOBCREATOR
{
	BATCHRENDER						= (1 << 0),
	PICTUREVIEWER					= (1 << 1),
	USER									= (1 << 2),
	WATCHDIRECTORY				= (1 << 3),
	WATCHDIRECTORYSTARTUP	= (1 << 4),
	OTHER									= (1 << 5)
} MAXON_ENUM_FLAGS(RENDERJOBCREATOR);
/// @}

enum class DETAILSELECTOR
{
	NONE									= 0,
	SELECTED							= (1 << 0),
	NONSELECTED						= (1 << 1)
} MAXON_ENUM_FLAGS(DETAILSELECTOR);

/// @addtogroup STATUSNETSTATE
/// @ingroup group_enumeration
/// @{
enum class STATUSNETSTATE
{
	NONE = 0,					///< None.
	DISABLE,						///< Disable.
	IDLE,							///< Idle.
	BUSY,							///< Busy.
	BUSY2,							///< Busy 2.
	CRITICAL						///< Critical.
} MAXON_ENUM_FLAGS(STATUSNETSTATE);
/// @}

enum class HOTKEYFLAGS
{
	NONE = 0,
	MOUSE = 1 << 0,
	KEYBOARD = 1 << 1,
} MAXON_ENUM_FLAGS(HOTKEYFLAGS);

#define C4DUUID_SIZE 16							///< Size of the C4DUuid object.

/// @addtogroup FILTER
/// @ingroup group_enumeration
/// @{
/// Bitmap file formats.
#define FILTER_TIF								1100				///< TIFF
#define FILTER_TGA								1101				///< TGA
#define FILTER_BMP								1102				///< BMP
#define FILTER_IFF								1103				///< IFF
#define FILTER_JPG								1104				///< JPEG
#define FILTER_PICT								1105				///< PICT
#define FILTER_PSD								1106				///< PSD
#define FILTER_RLA								1107				///< RLA
#define FILTER_RPF								1108				///< RPF
#define FILTER_B3D								1109				///< @BP3D
#define FILTER_TIF_B3D						1110				///< TIFF @BP3D
#define FILTER_PSB								1111				///< PSB
#define FILTER_AVI								1122				///< AVI Movie
#define FILTER_MOVIE							1125				///< QuickTime Movie
#define FILTER_HDR								1001379			///< HDR
#define FILTER_EXR_LOAD						1016605			///< EXR (Load)
#define FILTER_EXR								1016606			///< EXR
#define FILTER_PNG								1023671			///< PNG
#define FILTER_IES								1024463			///< IES
#define FILTER_B3DNET							1099				///< @BP3D NET @markPrivate
#define FILTER_DPX								1023737			///< DPX
#define FILTER_DDS								1073775603	///< DDS @since R19
/// @}

/// @addtogroup AVISAVER
/// @ingroup group_containerid
/// @{
/// Container IDs for the AVI movie saver.\n
/// Undocumented. Refer to the AVI format documentation.
#define AVISAVER_FCCTYPE		10000
#define AVISAVER_FCCHANDLER	10001
#define AVISAVER_LKEY				10002
#define AVISAVER_LDATARATE	10003
#define AVISAVER_LQ					10004
/// @}

/// @addtogroup QTSAVER
/// @ingroup group_containerid
/// @{
/// Container IDs for the QT movie saver.\n
/// Undocumented. Refer to the QuickTime format documentation.
#define QTSAVER_COMPRESSOR			10010
#define QTSAVER_QUALITY					10011
#define QTSAVER_TEMPQUAL				10012
#define QTSAVER_FRAMERATE				10013
#define QTSAVER_KEYFRAMES				10014
#define QTSAVER_PLANES					10015
#define QTSAVER_DATARATE				10016
#define QTSAVER_FRAMEDURATION		10017
#define QTSAVER_MINQUALITY			10018
#define QTSAVER_MINTEMPQUAL			10019
#define QTSAVER_FIXEDFRAMERATE	10020
/// @}

/// @addtogroup MISCSAVER
/// @ingroup group_containerid
/// @{
/// Container IDs for image savers.
#define JPGSAVER_QUALITY	10021			///< Quality of JPEG images. A value between @em 0 (lowest) and @em 100 (highest).
#define PNG_INTERLACED		11000			///< If @formatConstant{true}, @ref FILTER_PNG will save an interlaced @em PNG.
#define RLA_OPTIONS				10024			///< RLA options: @enumerateEnum{RLAFLAGS}
#define DPX_PLANAR				11000			///< If @formatConstant{true}, @ref FILTER_DPX will save the color channels out in blocks; i.e. all red parts of the pixels, then all green parts of the pixels, then all blue.
/// @}

/// @addtogroup ASSETDATA_FLAG
/// @ingroup group_enumeration
/// @{
enum class ASSETDATA_FLAG
{
	NONE								 = 0,					///< None.
	CURRENTFRAMEONLY		 = (1 << 0),	///< Only return current frame assets.
	TEXTURESONLY				 = (1 << 1),	///< Only return texture assets. @since R17.048 (was @c ASSETDATA_FLAG_TEXTURES)
	NET									 = (1 << 2),	///< Set if NET is collecting assets to distribute them to the clients.
	CURRENTTAKEONLY			 = (1 << 3),	///< Only return current take assets. @since R17
	WITHCACHES					 = (1 << 4),	///< Also return caches. (Global Illumination / Ambient Occlusion) @since R17.048
	NOSUBSTANCES				 = (1 << 5),	///< Normally Substance Assets are included on ::ASSETDATA_FLAG::TEXTURESONLY but with this flag they are not. @since R18
	MULTIPLEUSE					 = (1 << 6),	///< Adds the same asset again for every usage. @since R20
	NOMISSING						 = (1 << 7),	///< Only existing assets will be included. @since R22
	NODOCUMENT					 = (1 << 8),	///< Exclude the document itself from the asset list. @ since R21
	COLLECT_NODES_ASSETS = (1 << 9),	///< Set to collect node asset infos as well.
	DONOTRESOLVE				 = (1 << 10),	///< Set to get the original name, not resolved to the folder.
	WITHFONTS						 = (1 << 11),	///< Also return fonts. @since 2024
} MAXON_ENUM_FLAGS(ASSETDATA_FLAG);
/// @}

/// @addtogroup SAVEBIT
/// @ingroup group_enumeration
/// @{
/// Flags for the opening/saving of @link BaseBitmap bitmaps@endlink.
enum class SAVEBIT
{
	NONE							= 0,						///< None.
	ALPHA							= (1 << 0),			///< Save the alpha channel(s) in the file. (For filter plugins, do not save an alpha channel if this is not set.)
	MULTILAYER				= (1 << 1),			///< Save multiple layers.
	USESELECTEDLAYERS	= (1 << 2),			///< Use selected layers.
	USE16BITCHANNELS	= (1 << 3),			///< Use <i>16</i>-bit channels.
	GREYSCALE					= (1 << 4),			///< Save in grayscale mode.
	INTERNALNET				= (1 << 5),			///< @markPrivate
	DONTMERGE					= (1 << 7),			///< Avoid merging of layers in @BP3D files.
	USE32BITCHANNELS	= (1 << 8),			///< Use <i>32</i>-bit channels.
	SAVERENDERRESULT	= (1 << 9),			///< @markPrivate
	FIRSTALPHA_ONLY		= (1 << 10),		///< @markPrivate
	KEEP_COLOR_MODE		= (1 << 11)			///< @markPrivate
} MAXON_ENUM_FLAGS(SAVEBIT);
/// @}

/// @addtogroup SCENEFILTER
/// @ingroup group_enumeration
/// @{
/// Scene filter flags for the loading, saving and merging of documents.
/// @see LoadDocument() SaveDocument() MergeDocument()
enum class SCENEFILTER
{
	NONE							= 0,																	///< None.
	OBJECTS						= (1 << 0),														///< Load/save objects.
	MATERIALS					= (1 << 1),														///< Load/save materials.
	DIALOGSALLOWED		= (1 << 3),														///< Flag to inform a plugin that a dialog can be displayed. If this flag is not set then no dialogs must be opened.
	PROGRESSALLOWED		= (1 << 4),														///< Flag to inform a plugin that a progress bar can be displayed. The progress bar can be set by calling StatusSetBar().
	MERGESCENE				= (1 << 5),														///< Flag to inform a plugin that this is a merge operation, i.e. the document that is inserted to is an existing scene.
	NONEWMARKERS			= (1 << 6),														///< Objects loaded from disk will keep their markers (GeMarker).
	SAVECACHES				= (1 << 7),														///< For @em Cineware export only. Caches of objects will also be written (only supported by @C4D format). This is the same as the global option <i>"Save Polygon Objects for Melange Exchange"</i>.
	NOUNDO						= (1 << 8),														///< Use together with @ref SCENEFILTER::MERGESCENE to avoid that undos are created for the merge operation.
	SAVE_BINARYCACHE	= (1 << 10),													///< Save the binary compiled shaders with the scene (only for @C4D format).
	IDENTIFY_ONLY			= (1 << 11),													///< Do not load the whole document, identify it only.
	ONLY_RENDERDATA		= (1 << 12),													///< Only load render settings. If this flag is set, @ref SCENEFILTER::OBJECTS, @ref SCENEFILTER::MATERIALS, @ref SCENEFILTER::PREVIEWONLY and @ref SCENEFILTER::DOCUMENTPREFSONLY are ignored.
	IGNOREMISSINGPLUGINSINNONACTIVERENDERDATA = (1 << 13),	///< Ignore all missing plugins which are part of a non-active render data.
	IGNOREXREFS							= (1 << 14),										///< Avoid that included X-Refs will be loaded. @since R16.038
	DONTCORRECTOUTPUTFORMAT	= (1 << 15),										///< Do not change unknown output formats in render settings.
	SKIPOLDERTHANV13				= (1 << 16),										///< @markPrivate (used in Cineware SDK only).
	PREVIEWONLY							= (1 << 17),										///< Only load the document preview image. If this flag is set, @ref SCENEFILTER::OBJECTS, @ref SCENEFILTER::MATERIALS and @ref SCENEFILTER::DOCUMENTPREFSONLY are ignored. Does not work with @ref SCENEFILTER::ONLY_RENDERDATA.
	DOCUMENTPREFSONLY = (1 << 18),													///< Only load document preferences. If this flag is set, @ref SCENEFILTER::OBJECTS and @ref SCENEFILTER::MATERIALS are ignored. Does not work with @ref SCENEFILTER::PREVIEWONLY nor @ref SCENEFILTER::ONLY_RENDERDATA.
	DOCUMENTINFOGUIALLOWED = (1 << 19),											///< Custom dialogs can be displayed while reacting to DocumentInfo Messages.
	SUPPRESSOPTIONSDIALOG = (1 << 31),											///< Suppress the options dialog (if DIALOGSALLOWED was specified), so that errors would show up
} MAXON_ENUM_FLAGS(SCENEFILTER);
/// @}

/// @addtogroup OVERVIEW
/// @ingroup group_enumeration
/// @{
/// @markInternal
enum class OVERVIEW
{
	DEFAULT		= 0,
	AKTU			= 1,
	SCENE			= 2,
	COMPLETE	= 3,
	SELECTED	= 4
} MAXON_ENUM_FLAGS(OVERVIEW);
/// @}

/// @addtogroup GEMB
/// @ingroup group_enumeration
/// @{
/// Flags for GeOutString().
enum class GEMB
{
	OK								= 0x0000,			///< OK.
	OKCANCEL					= 0x0001,			///< OK and Cancel.
	ABORTRETRYIGNORE	= 0x0002,			///< Abort, Retry and Ignore.
	YESNOCANCEL				= 0x0003,			///< Yes, No and Cancel.
	YESNO							= 0x0004,			///< Yes and No.
	RETRYCANCEL				= 0x0005,			///< Retry and Cancel.
	FORCEDIALOG				= 0x8000,			///< Forces the dialog.
	ICONSTOP					= 0x0010,			///< Stop icon.
	ICONQUESTION			= 0x0020,			///< Question icon.
	ICONEXCLAMATION		= 0x0030,			///< Exclamation icon.
	ICONASTERISK			= 0x0040,			///< Asterisk icon.
	DEFBUTTON1				= 0x0000,			///< Default button set to first button.
	DEFBUTTON2				= 0x0100,			///< Default button set to second button.
	DEFBUTTON3				= 0x0200,			///< Default button set to third button.
	DEFBUTTON4				= 0x0300,			///< Default button set to fourth button.
	MULTILINE					= 0x0080			///< If the message is more than @em 255 characters and @em 4 lines then this bit should be set for Mac compatibility.\n
																	///< The dialog is then restricted to only an OK button with limited keyboard support.
} MAXON_ENUM_FLAGS(GEMB);
/// @}

/// @addtogroup GEMB_R
/// @ingroup group_enumeration
/// @{
/// Return values for GeOutString().
enum class GEMB_R
{
	// V_ unfortunately has to be repeated here due to conflicts with MAC OS
	V_UNDEFINED		= 0,			///< Undefined.
	V_OK					= 1,			///< OK button.
	V_CANCEL			= 2,			///< Cancel button.
	V_ABORT				= 3,			///< Abort button.
	V_RETRY				= 4,			///< Retry button.
	V_IGNORE			= 5,			///< Ignore button.
	V_YES					= 6,			///< Yes button.
	V_NO					= 7				///< No button.
} MAXON_ENUM_LIST(GEMB_R);
/// @}

/// @addtogroup MOUSEDRAGRESULT
/// @ingroup group_enumeration
/// @{
/// Result codes for EditorWindow::MouseDrag.
enum class MOUSEDRAGRESULT
{
	ESCAPE		= 1,			///< Drag aborted.
	FINISHED	= 2,			///< Drag finished.
	CONTINUE	= 3				///< Drag still in progress.
} MAXON_ENUM_LIST(MOUSEDRAGRESULT);
/// @}

/// @addtogroup MOUSEDRAGFLAGS
/// @ingroup group_enumeration
/// @{
/// @see EditorWindow::MouseDragStart() EditorWindow::MouseDrag() GeUserArea::MouseDragStart() GeUserArea::MouseDrag()
enum class MOUSEDRAGFLAGS
{
	NONE										= 0,						///< None.
	DONTHIDEMOUSE						= (1 << 0),			///< Show mouse pointer during drag.
	NOMOVE									= (1 << 1),			///< @c MouseDrag() returns @ref MOUSEDRAGRESULT::CONTINUE even if mouse is not moved. Otherwise @c MouseDrag() only returns if mouse is moved.
	EVERYPACKET							= (1 << 2),			///< Receive every packet of the queue, otherwise only data of the last packet.
	COMPENSATEVIEWPORTORG		= (1 << 3),			///< Compensates the viewport origin during drag.
	AIRBRUSH								= (1 << 4)			///< Airbrush mode.
} MAXON_ENUM_FLAGS(MOUSEDRAGFLAGS);
/// @}

/// @addtogroup INITRENDERRESULT
/// @ingroup group_enumeration
/// @{
/// Result codes for @c InitRender() calls in the rendering API.
enum class INITRENDERRESULT
{
	OK						= 0,				///< Everything is OK, there was no error.
	OUTOFMEMORY		= -100,			///< Not enough memory.
	ASSETMISSING	= -101,			///< Assets (textures etc.) are missing.
	UNKNOWNERROR	= -102,			///< Unknown error.
	USERBREAK			= -103			///< Thread has been canceled. @since R17.032 Was @c INITRENDERRESULT_THREADEDLOCK.
} MAXON_ENUM_LIST(INITRENDERRESULT);
/// @}

/// @addtogroup RENDERRESULT
/// @ingroup group_enumeration
/// @{
/// Result codes for the <tt>Render()</tt> calls in the rendering API.
enum class RENDERRESULT
{
	OK									= 0,				///< Function was successful.
	OUTOFMEMORY					= 1,				///< Not enough memory.
	ASSETMISSING				= 2,				///< Assets (textures etc.) are missing.
	SAVINGFAILED				= 5,				///< Failed to save.
	USERBREAK						= 6,				///< %User stopped the processing.
	GICACHEMISSING			= 7,				///< GI cache is missing.
	NOMACHINE						= 9,				///< %Machine was not found. Can only happen during Team Rendering.
	UNAVAILABLE					= 10,				///< The rendering could not be started, e.g. if a rendering with higher priority is already running.
	FAILED							= 11,				///< Generic error if a rendering has failed due to missing license or similar.

	PROJECTNOTFOUND			= 1000,			///< Project was not found. Can only be returned by @C4D during command line rendering.
	ERRORLOADINGPROJECT	= 1001,			///< There was an error while loading the project. Can only be returned by @C4D during command line rendering.
	NOOUTPUTSPECIFIED		= 1002			///< Output was not specified. Can only be returned by @C4D during command line rendering.
} MAXON_ENUM_LIST(RENDERRESULT);
/// @}

/// @addtogroup BITDEPTH
/// @ingroup group_enumeration
/// @{
#define BITDEPTH_SHIFT		4			/// Number of color info bits.
#define BITDEPTH_MAXMODES	3			/// Number of color modes.

#define BITDEPTH_UCHAR	0			/// ::UChar (<i>8</i>-bit).
#define BITDEPTH_UWORD	1			/// ::UInt16 (<i>16</i>-bit).
#define BITDEPTH_FLOAT	2			/// ::Float (<i>32</i>-bit).
/// @}

/// @addtogroup COLORMODE
/// @ingroup group_enumeration
/// @{
/// The color mode for @link BaseBitmap bitmaps@endlink.\n
/// The most common values are @ref COLORMODE::RGB for <i>24</i>-bit RGB @link BaseBitmap bitmaps@endlink and @ref COLORMODE::GRAY for <i>8</i>-bit grayscale @link BaseBitmap bitmaps@endlink.
enum class COLORMODE
{
	// <i>8</i>-bit modes

	ILLEGAL	= 0,			///< Illegal <i>8</i>-bit mode.

	ALPHA		= 1,			///< Only <i>8</i>-bit alpha channel.
	GRAY		= 2,			///< <i>8</i>-bit grayscale channel.
	AGRAY		= 3,			///< <i>8</i>-bit grayscale channel with <i>8</i>-bit alpha.
	RGB			= 4,			///< <i>8</i>-bit RGB channels.
	ARGB		= 5,			///< <i>8</i>-bit RGB channels with <i>8</i>-bit alpha.
	CMYK		= 6,			///< <i>8</i>-bit CMYK channel.
	ACMYK		= 7,			///< <i>8</i>-bit CMYK channel with <i>8</i>-bit alpha.
	MASK		= 8,			///< <i>8</i>-bit grayscale map as mask.
	AMASK		= 9,			///< <i>8</i>-bit grayscale map as mask with <i>8</i>-bit alpha.

	// <i>16</i>-bit modes

	ILLEGALw	= (BITDEPTH_UWORD << BITDEPTH_SHIFT),													///< Illegal <i>16</i>-bit mode.

	GRAYw			= (COLORMODE::GRAY | (BITDEPTH_UWORD << BITDEPTH_SHIFT)),			///< <i>16</i>-bit grayscale channel.
	AGRAYw		= (COLORMODE::AGRAY | (BITDEPTH_UWORD << BITDEPTH_SHIFT)),			///< <i>16</i>-bit grayscale channel with <i>16</i>-bit alpha.
	RGBw			= (COLORMODE::RGB | (BITDEPTH_UWORD << BITDEPTH_SHIFT)),				///< <i>16</i>-bit RGB channels.
	ARGBw			= (COLORMODE::ARGB | (BITDEPTH_UWORD << BITDEPTH_SHIFT)),			///< <i>16</i>-bit RGB channels with <i>16</i>-bit alpha.
	MASKw			= (COLORMODE::MASK | (BITDEPTH_UWORD << BITDEPTH_SHIFT)),			///< <i>16</i>-bit grayscale map as mask.

	// <i>32</i>-bit modes

	ILLEGALf	= (BITDEPTH_FLOAT << BITDEPTH_SHIFT),													///< Illegal <i>32</i>-bit mode.

	GRAYf			= (COLORMODE::GRAY | (BITDEPTH_FLOAT << BITDEPTH_SHIFT)),			///< <i>32</i>-bit floating point grayscale channel.
	AGRAYf		= (COLORMODE::AGRAY | (BITDEPTH_FLOAT << BITDEPTH_SHIFT)),			///< <i>32</i>-bit floating point grayscale channel with floating point alpha.
	RGBf			= (COLORMODE::RGB | (BITDEPTH_FLOAT << BITDEPTH_SHIFT)),				///< <i>32</i>-bit floating point RGB channels.
	ARGBf			= (COLORMODE::ARGB | (BITDEPTH_FLOAT << BITDEPTH_SHIFT)),			///< <i>32</i>-bit floating point RGB channels with floating point alpha.
	MASKf			= (COLORMODE::MASK | (BITDEPTH_FLOAT << BITDEPTH_SHIFT))				///< <i>32</i>-bit floating point grayscale map as mask.
} MAXON_ENUM_FLAGS(COLORMODE);
/// @}

/// @addtogroup COLORSPACETRANSFORMATION
/// @ingroup group_enumeration
/// @{
/// Color space transformations.
enum class COLORSPACETRANSFORMATION
{
	NONE						= 0,			///< None.
	LINEAR_TO_SRGB	= 1,			///< Linear to sRGB color space transformation.
	SRGB_TO_LINEAR	= 2,			///< sRGB to linear color space transformation.

	LINEAR_TO_VIEW	= 10,			///< Linear to display color space transformation.
	SRGB_TO_VIEW		= 11,			///< sRGB to display color space transformation.

	OCIO_INPUT_LOW_TO_RENDERING		= SRGB_TO_LINEAR,		///< No operation. Input low and rendering are the same.
	OCIO_RENDERING_TO_INPUT_LOW		= LINEAR_TO_SRGB,		///< No operation. Input low and rendering are the same.
	OCIO_RENDERING_TO_VIEW 				= LINEAR_TO_VIEW,		///< Rendering to view color space transformation.
	OCIO_INPUT_LOW_TO_VIEW 				= SRGB_TO_VIEW,			///< Input low (same as Rendering) to view color space transformation.
	OCIO_VIEW_TO_RENDERING				= 22,								///< View to rendering color space transformation.
	OCIO_VIEW_TO_INPUT_LOW				= 23,								///< View to input low (same as rendering) color space transformation.
	OCIO_INPUT_HIGH_TO_RENDERING	= 24,								///< No operation. Input high and rendering are the same.
	OCIO_RENDERING_TO_DISPLAY			= 25,								///< Rendering to display color space transformation.
	OCIO_DISPLAY_TO_RENDERING			= 26,								///< Display to rendering color space transformation.
	OCIO_SRGB_TO_RENDERING				= 27,								///< sRGB to Rendering color space transformation.
	OCIO_RENDERING_TO_SRGB				= 28,								///< Rendering to sRGB color space transformation.
	OCIO_LINEAR_TO_RENDERING			= 29,								///< Linear to rendering color space transformation.
	OCIO_RENDERING_TO_LINEAR			= 30,								///< Rendering to linear color space transformation.
} MAXON_ENUM_LIST(COLORSPACETRANSFORMATION);
/// @}

/// @addtogroup COLORSPACETRANSFORMATION
/// @ingroup group_enumeration
/// @{
/// View / texture window color space.
enum class VIEW_WINDOW_COLOR_SPACE : Int32
{
	UNDEFINED	= 0,			///< Undefined, e.g. if there is no ViewWindow for the BaseDraw.
	LINEAR		= 1,			///< Linear.
	SRGB			= 2,			///< sRGB.
} MAXON_ENUM_LIST(VIEW_WINDOW_COLOR_SPACE);
/// @}

/// @addtogroup PIXELCNT
/// @ingroup group_enumeration
/// @{
/// Flags for @ref BaseBitmap::GetPixelCnt/@ref BaseBitmap::SetPixelCnt
enum class PIXELCNT
{
	NONE									= 0,							///< None.
	DITHERING							= (1 << 0),				///< Allow dithering.
	B3DLAYERS							= (1 << 1),				///< Merge @BP3D layers (MultipassBitmap).
	APPLYALPHA						= (1 << 2),				///< Apply alpha layers to the result (PaintLayer).
	INTERNAL_SETLINE			= (1 << 29),			///< Internal SetLine indicator. @markPrivate
	INTERNAL_ALPHAVALUE		= (1 << 30)				///< Get also the alpha value (RGBA <i>32</i>-bit). @markPrivate
} MAXON_ENUM_FLAGS(PIXELCNT);
/// @}

/// @addtogroup INITBITMAPFLAGS
/// @ingroup group_enumeration
/// @{
/// Flags for the initialization of @link BaseBitmap bitmaps@endlink.
/// @see BaseBitmap::Init(Int32 x, Int32 y, Int32 depth = 24, INITBITMAPFLAGS flags = INITBITMAPFLAGS::NONE)
enum class INITBITMAPFLAGS
{
	NONE			= 0,						///< None.
	GRAYSCALE	= (1 << 0),			///< Initialize as grayscale bitmap.
	SYSTEM		= (1 << 1),			///< @markPrivate
	DPNULL		= (1 << 2)			///< @markPrivate
} MAXON_ENUM_FLAGS(INITBITMAPFLAGS);
/// @}

/// @addtogroup MPB_GETLAYERS
/// @ingroup group_enumeration
/// @{
/// Flags for MultipassBitmap::GetLayers.
enum class MPB_GETLAYERS
{
	NONE	= 0,						///< None.
	ALPHA	= (1 << 1),			///< Get alpha layers.
	IMAGE	= (1 << 2)			///< Get image layers.
} MAXON_ENUM_FLAGS(MPB_GETLAYERS);
/// @}

/// @addtogroup MPBTYPE
/// @ingroup group_containerid
/// @{
/// Container IDs for @ref MultipassBitmap::GetParameter/@ref MultipassBitmap::SetParameter.
enum class MPBTYPE
{
	SHOW				= 1000,			///< ::Bool Get/Set. Determines if the layer will be shown in the external render window. (The @C4D renderer modifies this value itself.)
	SAVE				= 1001,			///< ::Bool Get/Set. Determines if the layer is saved with the image or not if @ref SAVEBIT::USESELECTEDLAYERS is used.
	PERCENT			= 1002,			///< ::Float Get/Set. The blend parameter, between @em 0.0 and @em 1.0.
	BLENDMODE		= 1003,			///< ::Int32 Get/Set. The blend mode (LAYER_NORMAL, LAYER_DISSOLVE etc. from @em bplayer.h).
	COLORMODE		= 1004,			///< ::Int32 Get/Set. The color mode: @enumerateEnum{COLORMODE}
	BITMAPTYPE	= 1005,			///< ::Int32 Get. The bitmap type (cannot be set with MultipassBitmap::SetParameter).
	NAME				= 1006,			///< String Get/Set. The layer name. @warning Only a PaintLayerBmp or PaintLayerFolder can have a name.
	DPI					= 1007,			///< ::Int32 Get/Set. The resolution in DPI. @markPrivate
	USERID			= 1008,			///< ::Int32 Get/Set. The user ID for the layer. In the renderer this is @em VPBUFFER_XXX.
	USERSUBID		= 1009,			///< ::Int32 Get/Set. The user sub-ID for the layer. In the renderer this is used for blend channels for instance.
	FORCEBLEND	= 1010			///< ::Int32 Get/Set. The special mode used to force blend layers.
} MAXON_ENUM_LIST(MPBTYPE);
/// @}

/// @addtogroup LENGTHUNIT
/// @ingroup group_enumeration
/// @{
/// @see StringToNumber
enum class LENGTHUNIT
{
	PIXEL		= 0,			///< Pixel.
	KM			= 1,			///< Kilometer.
	M				= 2,			///< Meter.
	CM			= 3,			///< Centimeter.
	MM			= 4,			///< Millimeter.
	UM			= 5,			///< Micrometer.
	NM			= 6,			///< Nanometer.
	MILE		= 7,			///< Mile.
	YARD		= 8,			///< Yard.
	FEET		= 9,			///< Feet.
	INCH		= 10			///< Inch.
} MAXON_ENUM_LIST(LENGTHUNIT);
/// @}

/// @addtogroup SPLINETYPE
/// @ingroup group_enumeration
/// @{
/// Spline types.
/// @see SplineObject::Alloc SplineObject::GetInterpolationType
enum class SPLINETYPE
{
	LINEAR								= 0,		///< Linear.
	CUBIC									= 1,		///< Cubic.
	AKIMA									= 2,		///< Akima.
	BSPLINE								= 3,		///< B-Spline.
	BEZIER								= 4,		///< Bezier.
	RESERVEDSPLINETYPE1		= 5,		///< @markInternal @since R17.032
	RESERVEDSPLINETYPE2		= 6			///< @markInternal @since R17.032
} MAXON_ENUM_LIST(SPLINETYPE);
/// @}

/// @addtogroup BREAKTANGENTS
/// @ingroup group_enumeration
/// @{
/// @since R17.032
enum class BREAKTANGENTS
{
	// V_ unfortunately has to be used here due to conflicts with MAC OS
	V_FALSE	=	0,			///< Do not break any tangents.
	V_TRUE	=	1,			///< Break the tangents.
	V_AUTO	= 2				///< Only break the tangents if the tangents are already broken.
} MAXON_ENUM_LIST(BREAKTANGENTS);
/// @}

/// @addtogroup TANGENTSIDE
/// @ingroup group_enumeration
/// @{
/// @since R17.032
enum class TANGENTSIDE
{
	NONE	=	-1,			///< No tangent handles being modified.
	LEFT	= 0,			///< Modify the left tangent handle.
	RIGHT	= 1,			///< Modify the right tangent handle.
} MAXON_ENUM_LIST(TANGENTSIDE);
/// @}

/// @addtogroup TANGENTTRANSFORMFLAG
/// @ingroup group_enumeration
/// @{
/// @since R17.032
enum class TANGENTTRANSFORMFLAG
{
	NONE					=	0,																					///< No transform flag.
	LOCK_LENGTH		=	(1 << 0),																		///< Fix the length of the tangents, only change the rotation.
	LOCK_ANGLE		=	(1 << 1),																		///< Fix the angle of the tangents, only change the length.
	BREAK_SCALE		=	(1 << 2),																		///< Only scale one handle (but rotate both).
	BREAK					=	TANGENTTRANSFORMFLAG::BREAK_SCALE|(1 << 3)		///< Only modify one handle.
} MAXON_ENUM_FLAGS(TANGENTTRANSFORMFLAG);
/// @}

/// @addtogroup SPLINEBOOL_AXIS
/// @ingroup group_enumeration
/// @{
/// @since R17.032
enum class SPLINEBOOL_AXIS
{
	NONE			= 0,			///< No axis.
	SCREEN		=	1,			///< Project into the current screen.
	ZY				=	2,			///< Project on the ZY (X axis) plane.
	XZ				= 3,			///< Project on the XZ (Y axis) plane.
	XY				= 4				///< Project on the XY (Z axis) plane.
} MAXON_ENUM_LIST(SPLINEBOOL_AXIS);
/// @}

/// @addtogroup SPLINEBOOL_MODE
/// @ingroup group_enumeration
/// @{
/// @since R17.032
enum class SPLINEBOOL_MODE
{
	AMINUSB				=	0,			///< Subtract B from A.
	BMINUSA				=	1,			///< Subtract A from B.
	UNION					=	2,			///< Union of both A and B.
	AND						=	3,			///< And intersection (overlap) of region of A and B.
	OR						=	4,			///< Or intersection (outside of overlap) of region of A and B.
	INTERSECTION	=	5,			///< Intersection (all segments inside and out) of region of A and B.
} MAXON_ENUM_LIST(SPLINEBOOL_MODE);
/// @}

/// @addtogroup PARTICLEFLAGS
/// @ingroup group_enumeration
/// @{
/// @see Particle
enum class PARTICLEFLAGS
{
	NONE		= 0,						///< None.
	VISIBLE	= (1 << 0),			///< %Particle is visible.
	ALIVE		= (1 << 1)			///< %Particle is alive.
} MAXON_ENUM_FLAGS(PARTICLEFLAGS);
/// @}

/// @addtogroup NBIT
/// @ingroup group_enumeration
/// @{
/// GeListNode bits.
/// @see GeListNode::GetNBit() GeListNode::ChangeNBit()
enum class NBIT
{
	NONE										= 0,			///< None.

	TL1_FOLD								= 1,			///< Folding bit for Timeline 1.
	TL2_FOLD								= 2,			///< Folding bit for Timeline 2.
	TL3_FOLD								= 3,			///< Folding bit for Timeline 3.
	TL4_FOLD								= 4,			///< Folding bit for Timeline 4.

	TL1_SELECT							= 5,			///< Selection bit for Timeline 1.
	TL2_SELECT							= 6,			///< Selection bit for Timeline 2.
	TL3_SELECT							= 7,			///< Selection bit for Timeline 3.
	TL4_SELECT							= 8,			///< Selection bit for Timeline 4.

	TL1_TDRAW								= 9,			///< @markPrivate
	TL2_TDRAW								= 10,			///< @markPrivate
	TL3_TDRAW								= 11,			///< @markPrivate
	TL4_TDRAW								= 12,			///< @markPrivate

	CKEY_ACTIVE							= 13,			///< Active point of animation path in editor.

	OM1_FOLD								= 14,			///< Folding bit for Object Manager 1.
	OM2_FOLD								= 15,			///< Folding bit for Object Manager 2.
	OM3_FOLD								= 16,			///< Folding bit for Object Manager 3.
	OM4_FOLD								= 17,			///< Folding bit for Object Manager 4.

	TL1_FOLDTR							= 18,			///< Track folding for Timeline 1.
	TL2_FOLDTR							= 19,			///< Track folding for Timeline 2.
	TL3_FOLDTR							= 20,			///< Track folding for Timeline 3.
	TL4_FOLDTR							= 21,			///< Track folding for Timeline 4.

	TL1_FOLDFC							= 22,			///< F-Curve folding for Timeline 1.
	TL2_FOLDFC							= 23,			///< F-Curve folding for Timeline 2.
	TL3_FOLDFC							= 24,			///< F-Curve folding for Timeline 3.
	TL4_FOLDFC							= 25,			///< F-Curve folding for Timeline 4.

	SOURCEOPEN							= 26,			///< Source open in motion clip hierarchy tree.

	TL1_HIDE								= 27,			///< Hide in Timeline 1.
	TL2_HIDE								= 28,			///< Hide in Timeline 2.
	TL3_HIDE								= 29,			///< Hide in Timeline 3.
	TL4_HIDE								= 30,			///< Hide in Timeline 4.

	SOLO_ANIM								= 31,			///< Solo animation.
	SOLO_LAYER							= 32,			///< Solo layer.

	TL1_SELECT2							= 33,			///< @markPrivate
	TL2_SELECT2							= 34,			///< @markPrivate
	TL3_SELECT2							= 35,			///< @markPrivate
	TL4_SELECT2							= 36,			///< @markPrivate

	SOLO_MOTION							= 37,			///< Solo motion.

	CKEY_LOCK_T							= 38,			///< Lock key time.
	CKEY_LOCK_V							= 39,			///< Lock key value.
	CKEY_MUTE								= 40,			///< Mute key.
	CKEY_CLAMP							= 41,			///< Clamp key tangents.

	CKEY_BREAK							= 42,			///< Break key tangents.
	CKEY_KEEPVISUALANGLE		= 43,			///< Keep visual angle.

	CKEY_LOCK_O							= 44,			///< Lock key tangents angles.
	CKEY_LOCK_L							= 45,			///< Lock key tangents length.
	CKEY_AUTO								= 46,			///< Key auto tangents.
	CKEY_ZERO_O_OLD					= 48,			///< @markDeprecated
	CKEY_ZERO_L_OLD					= 49,			///< @markDeprecated

	// This is a legacy mode use TL(1-2-3-4)_SELECT2 instead.
	TL1_FCSELECT						= 50,			///< F-Curve selection bit for Timeline 1.
	TL2_FCSELECT						= 51,			///< F-Curve selection bit for Timeline 2.
	TL3_FCSELECT						= 52,			///< F-Curve selection bit for Timeline 3.
	TL4_FCSELECT						= 53,			///< F-Curve selection bit for Timeline 4.

	CKEY_BREAKDOWN					= 54,			///< @markPrivate

	TL1_FOLDMOTION					= 55,			///< Motion clip folding for Timeline 1.
	TL2_FOLDMOTION					= 56,			///< Motion clip folding for Timeline 2.
	TL3_FOLDMOTION					= 57,			///< Motion clip folding for Timeline 3.
	TL4_FOLDMOTION					= 58,			///< Motion clip folding for Timeline 4.

	TL1_SELECTMOTION				= 59,			///< Motion clip selection for Timeline 1.
	TL2_SELECTMOTION				= 60,			///< Motion clip selection for Timeline 2.
	TL3_SELECTMOTION				= 61,			///< Motion clip selection for Timeline 3.
	TL4_SELECTMOTION				= 62,			///< Motion clip selection for Timeline 4.

	OHIDE										= 63,				///< Hide object/tag in Object Manager or material in %Material Manager. @note OHIDE should not be used to store BaseList2Ds that do not interact with the user, as they clutter the manager and thus decrease its performance. Instead a special branch should be used to store these BaseList2Ds.
	TL_TBAKE								= 64,			///< @markPrivate

	TL1_FOLDSM							= 66,			///< @markPrivate
	TL2_FOLDSM							= 67,			///< @markPrivate
	TL3_FOLDSM							= 68,			///< @markPrivate
	TL4_FOLDSM							= 69,			///< @markPrivate

	SUBOBJECT								= 70,			///< @markPrivate
	LINK_ACTIVE							= 71,			///< @markPrivate
	THIDE										= 72,			///< Hide object in Timeline.
	SUBOBJECT_AM						= 74,			///< @markPrivate
	PROTECTION							= 75,			///< PSR protection.
	NOANIM									= 76,			///< No animation.
	NOSELECT								= 77,			///< No selection.
	EHIDE										= 78,			///< Hide in viewport.
	REF											= 79,			///< XRef.
	REF_NO_DD								= 80,			///< XRef object no drag and drop. @markPrivate
	REF_OHIDE								= 81,			///< XRef object hide. @markPrivate
	NO_DD										= 82,			///< No drag and drop duplication.
	HIDEEXCEPTVIEWSELECT		= 83,			///< Hide in viewport except to viewport select.
	CKEY_WEIGHTEDTANGENT		= 84,			///< Weighted tangent. @since R17.032
	CKEY_REMOVEOVERSHOOT		= 85,			///< Gradual clamp of tangent to avoid over shooting. @since R17.032
	CKEY_AUTOWEIGHT					= 86,			///< Weight still adjusted even if angle is user defined. @since R17.032
	TAKE_LOCK								= 87,			///< A node in an override group cannot be changed. @since R17.032
	TAKE_OBJINGROUP					= 88,			///< The object is overridden by an override group. @since R17.032
	TAKE_EGROUPOVERIDDEN		= 89,			///< The object editor visibility is overridden by an override group. @since R17.032
	TAKE_RGROUPOVERIDDEN		= 90,			///< The object render visibility is overridden by an override group. @since R17.032
	CKEY_BREAKDOWNCOLOR			= 91,			///< The key is a golden pose. @since R18
	NO_DELETE								= 92,			///< No delete in Object Manager. @since R18
	LOD_HIDE								= 93,			///< Used by LOD object to hide itself outside the view. @since R19
	LOD_PRIVATECACHE				= 94,			///< @markPrivate @since R19
	AHIDE_FOR_HOST					= 95,			///< Hide Tag data in Attribute Manager when host object selected (tabs otherwise automatically added) @since R20
	NODE_TEMP								= 96,			///< @markPrivate @since R23
	FORBID_COLOR_CONVERSION	= 97,			///< Don't do OCIO color conversion. @since 2023.100
	TAG_ADDEDTOCACHE				= 98,			///< Tag was added to cache objects. @since 2023.100
	MAX											= 98,			///< Maximum @ref NBIT.
} MAXON_ENUM_LIST(NBIT);
/// @}

static const Int32 PRIVATE_NBITMASK_INDEX1		= 0;			///< @markPrivate
static const Int32 PRIVATE_NBITMASK_INDEX2		= 1;			///< @markPrivate
static const Int32 PRIVATE_NBITMASK_INDEX3		= 2;			///< @markPrivate
static const Int32 PRIVATE_NBITMASK_INDEX4		= 3;			///< @markPrivate

/// @addtogroup CREATEJOBRESULT
/// @ingroup group_enumeration
/// @{
enum class CREATEJOBRESULT
{
	OK							= 0,			///< Ok.
	OUTOFMEMORY			= 1,			///< Out of memory.
	ASSETMISSING		= 2,			///< Asset missing.
	SAVINGFAILED		= 3,			///< Saving failed.
	REPOSITORYERROR	= 4				///< Repository error.
} MAXON_ENUM_FLAGS(CREATEJOBRESULT);
/// @}

/// @addtogroup NBITCONTROL
/// @ingroup group_enumeration
/// @{
/// @see GeListNode::ChangeNBit
enum class NBITCONTROL
{
	SET							= 1,				///< Set bit.
	CLEAR						= 2,				///< Clear bit.
	TOGGLE					= 3,				///< Toggle bit.
	PRIVATE_NODIRTY	= 0xf0			///< @markPrivate
} MAXON_ENUM_FLAGS(NBITCONTROL);
/// @}

/// @addtogroup BIT
/// @ingroup group_enumeration
/// @{
/// BaseList2D bits.
/// @see	BaseList2D::SetBit BaseList2D::GetBit BaseList2D::DelBit BaseList2D::ToggleBit\n
///				BaseList2D::GetAllBits BaseList2D::SetAllBits
/// @name Active bits
/// @{
#define BIT_ACTIVE	(1 << 1)			///< Active.
#define BIT_ACTIVE2	(1 << 29)			///< @markPrivate
#define BIT_ACTIVE3	(1 << 30)			///< @markPrivate @since R17.032
/// @}
/// @name Material Bits
/// @{
#define BIT_MATMARK				(1 << 2)			///< Marked material.
#define BIT_ENABLEPAINT		(1 << 3)			///< Enable painting.
#define BIT_RECALCPREVIEW	(1 << 5)			///< Recalculate preview.
#define BIT_MFOLD					(1 << 6)			///< Folded in material manager.
#define BIT_BP_FOLDLAYERS	(1 << 9)			///< Fold layers in material manager.
/// @}
/// @name Object Bits
/// @{
#define BIT_IGNOREDRAW											(1 << 2)			///< Ignore object during draw.
#define BIT_OFOLD														(1 << 6)			///< Folded in a Treeview (e.g. the Layer Manager, for the Object Manager, see @enumerateEnum{NBIT}.
#define BIT_CONTROLOBJECT										(1 << 9)			///< Internal bit set by generators.
#define BIT_RECMARK													(1 << 11)			///< Help bit for recursive operations. @markPrivate
#define BIT_IGNOREDRAWBOX										(1 << 12)			///< Ignore object drawing box.
#define BIT_EDITOBJECT											(1 << 13)			///< Edit object from SDS. @markPrivate
#define BIT_ACTIVESELECTIONDRAW							(1 << 15)			///< Draw active selection.
#define BIT_TEMPDRAW_VISIBLE_CACHECHILD			(1 << 16)			///< Temp bit for faster redraw. @markPrivate
#define BIT_TEMPDRAW_VISIBLE_DEFCACHECHILD	(1 << 17)			///< Temp bit for faster redraw. @markPrivate
#define BIT_TEMPDRAW_VISIBLE_CHILD					(1 << 18)			///< Temp bit for faster redraw. @markPrivate
#define BIT_HIGHLIGHT												(1 << 20)			///< Object highlighted in viewport. @markPrivate
#define BIT_FORCE_UNOPTIMIZED								(1 << 21)			///< Do not optimize the points of a polygon object during OpenGL redraw. @markPrivate
#define BIT_OVERRIDEDEFORMEDIT							(1 << 22)			///< Draws the object in deformed state, even if deform editing is deactivated.
#define BIT_FINALCACHESTATE									(1 << 23)			///< Marks an cache object to be final to improve performance. This object will not be skipped for further evaluation.
/// @}
/// @name Track Bits
/// @{
#define BIT_TRACKPROCESSED				(1 << 16)			///< Track has been processed, avoid recursions.
#define BIT_ANIM_OFF							(1 << 17)			///< Inactive sequence.
#define BIT_ANIM_SOLO							(1 << 18)			///< Solo track.
#define BIT_ANIM_CONSTANTVELOCITY	(1 << 19)			///< Constant velocity.
/// @}
/// @name Videopost Bits
/// @{
#define BIT_VPDISABLED (1 << 2)			///< Videopost is disabled.
/// @}
/// @name Document Bits
/// @{
#define BIT_DOCUMENT_CHECKREWIND (1 << 2)			///< Document needs to check for a rewind.
/// @}
/// @name RenderData Bits
/// @{
#define BIT_ACTIVERENDERDATA (1 << 28)			///< Active render data.
/// @}
/// @}

/// @addtogroup OBJECT
/// @ingroup group_enumeration
/// @{
/// Object plugin flags.
/// @see RegisterObjectPlugin() RegisterEffectorPlugin() RegisterFieldPlugin()
#define OBJECT_MODIFIER						(1 << 0)			///< Modifier object. Deforms the surrounding object. (e.g. bend)
#define OBJECT_HIERARCHYMODIFIER	(1 << 1)			///< Hierarchical modifier. Deforms the surrounding objects together with other instances in a hierarchy chain.\n
																								///< Only the top-most instance of the plugin in a chain is called. (e.g. bones)
#define OBJECT_GENERATOR					(1 << 2)			///< Generator object. Produces a polygonal or spline representation on its own. (e.g. primitive cube)
#define OBJECT_INPUT							(1 << 3)			///< Used in combination with @ref OBJECT_GENERATOR.\n
																								///< Specifies that the generator builds a polygon or spline using its sub-objects as input. (e.g. Sweep NURBS, Boolean)
#define OBJECT_PARTICLEMODIFIER		(1 << 5)			///< %Particle modifier.
#define OBJECT_NOCACHESUB					(1 << 6)			///< @markPrivate
#define OBJECT_ISSPLINE						(1 << 7)			///< Spline object.
#define OBJECT_UNIQUEENUMERATION	(1 << 8)			///< Unique enumeration. See @ref BaseObject::GetUniqueIP.
#define OBJECT_CAMERADEPENDENT		(1 << 9)			///< Camera dependent.
#define OBJECT_USECACHECOLOR			(1 << 10)			///< If this flag is specified, the generator object itself controls the objects' colors (the ones that determine the wireframe/shaded color).\n
																								///< Normally these are automatically overwritten by the generator objects settings.\n
																								///< e.g. If an instance object is set to green, automatically all of its cache objects get the green color. By setting this flag an instance object could individually color objects.
#define OBJECT_POINTOBJECT				(1 << 11)			///< Point object.
#define OBJECT_POLYGONOBJECT			(1 << 12)			///< Polygon object.
#define OBJECT_NO_PLA							(1 << 13)			///< Objects derived from PointObject will not use auto-keyframing (e.g. Joints can contain points and PLA auto-keyframing is not useful for them).
#define OBJECT_DONTFREECACHE			(1 << 14)			///< Objects' (generators) caches will not be be deleted - users must maintain caches themselves.
#define OBJECT_CALL_ADDEXECUTION	(1 << 15)			///< Must be set to call ObjectData::Execute() in the priority pipeline specified by ObjectData::AddToExecution.

#define OBJECT_NOCHILDEXPRESSIONS	(1 << 16)			///< Don't execute expression tags on the children of the object.

#define OBJECT_FIELDOBJECT				(1 << 17)			///< Field object.

#define OBJECT_HASDEFORMMODE			(1 << 18)			///< Object has a deform mode even if it is not one of the standard types with a deform mode.

#define OBJECT_ICONCHOOSER_PARENT_IGNORE (1 << 19) ///< ex TAG_ICONCHOOSER_PARENT_IGNORE

/// @}


/// @addtogroup FIELDLAYER
/// @ingroup group_enumeration
/// @{
/// Field Layer plugin flags.
/// @see RegisterFieldLayerPlugin()

#define FIELDLAYER_DIRECT								(1 << 0)			///< The FieldLayer will have access to directly manipulate the 'result' data in ModifyValues rather than purely overwrite it
#define FIELDLAYER_CHILDREN							(1 << 1)			///< The FieldLayer accepts child layers (which it then must evaluate itself in it's Sample function).
#define FIELDLAYER_NOVALUEOUT						(1 << 2)			///< The FieldLayer doesn't calculate values
#define FIELDLAYER_NOCOLOROUT						(1 << 3)			///< The FieldLayer doesn't calculate colors
#define FIELDLAYER_NODIRECTIONOUT				(1 << 4)			///< The FieldLayer doesn't calculate directions
#define FIELDLAYER_AGGREGATE						(1 << 5)			///< The FieldLayer will invoke it's Aggregate function to collect the final output after the layers have been calculated for this block/thread and do any internal cleanup at the end of a blocks execution
#define FIELDLAYER_HASREMAP							(1 << 6)			///< The FieldLayer will show and use a Remapping tab like the Field Objects.
#define FIELDLAYER_PREMULTIPLIED				(1 << 7)			///< The FieldLayer will receive FieldOutputBlock data premultiplied by alpha values.
#define FIELDLAYER_NOROTATIONOUT				(1 << 8)			///< The FieldLayer doesn't calculate rotational velocities

/// @}

/// @addtogroup Tlistelements
/// @ingroup group_enumeration
/// @{
#define Tbaselist2d		110050			///< 2D list.
#define Tbasedocument	110059			///< Document.
#define Tpluginlayer	110064			///< Plugin layer.
#define Tundoablelist	110068			///< Undoable list node (an intermediate class that is not in the SDK).
#define Tgelistnode		110069			///< Node list.
#define Tbasedraw			110305			///< BaseDraw.
/// @}

/// @addtogroup MaterialTypes Material Types
/// @ingroup group_enumeration
/// @{
#define Mbase				5702					///< Base material.
#define Mmaterial		5703					///< Standard material.
#define Mplugin			5705					///< Material plugin. Pass the plugin ID.
#define Mfog				8803					///< Fog.
#define Mterrain		8808					///< Terrain.
#define Mdanel			1011117				///< Danel.
#define Mbanji			1011118				///< Banji.
#define Mbanzi			1011119				///< Banzi.
#define Mcheen			1011120				///< Cheen.
#define Mmabel			1011121				///< Mabel.
#define Mnukei			1011122				///< Nukei.
#define MCgFX				450000237			///< @markPrivate
#define Marchigrass	1028461				///< Architectural Grass material.
#define Mshadowcatcher 1036101 		///< Shadow Catcher. @since R18
static const Int Mnimbus = 300001076;

// SDK-Team exposed symbols. Please remove the @PublicExposure tag when you intend to make
// one of the symbols 'official' be replacing all locally defined symbols with the one exposed in
// this file.
#define Mpyroobject				1001005 ///< Material plugin 'PyroCluster'. @PublicExposure
#define Mpyrovolume				1001006 ///< Material plugin 'PyroCluster - VolumeTracer'. @PublicExposure
#define Mrsgraph					1036224 ///< Material plugin 'Redshift Shader Graph' (XPresso). @PublicExposure
#define Msketch						1011014 ///< Material plugin 'Sketch'. @PublicExposure
#define Moutline					1012041 ///< Material plugin 'TUOUTLINER'. @PublicExposure
/// @}

/// @addtogroup VideoPostBase
/// @ingroup group_enumeration
/// @{
#define VPbase 5709			///< Video post base.
/// @}

/// @addtogroup ObjectTypes Object Types
/// @ingroup group_enumeration
/// @{
#define Opolygon					5100				///< Polygon - PolygonObject.
#define Ospline						5101				///< Spline - SplineObject.
#define Olight						5102				///< Light.
#define Orslight					1036751			///< Redshift light.
#define Ocamera						5103				///< Camera - CameraObject.
#define Orscamera					1057516			///< New Camera Object (Redshift)
#define Ofloor						5104				///< Floor.
#define Osky							5105				///< Sky.
#define Oenvironment			5106				///< Environment.
#define Oloft							5107				///< Loft NURBS.
#define Offd							5108				///< FFD.
#define Oparticle					5109				///< %Particle emitter - ParticleObject.
#define Odeflector				5110				///< %Particle deflector.
#define Ogravitation			5111				///< %Particle gravitation.
#define Orotation					5112				///< %Particle rotation.
#define Owind							5113				///< %Particle wind.
#define Ofriction					5114				///< %Particle friction.
#define Oturbulence				5115				///< %Particle turbulence.
#define Oextrude					5116				///< Extrude NURBS.
#define Olathe						5117				///< Lathe NURBS.
#define Osweep						5118				///< Sweep NURBS.
#define Oattractor				5119				///< %Particle attractor.
#define Obezier						5120				///< Bezier NURBS.
#define Oforeground				5121				///< Foreground.
#define Obackground				5122				///< Background.
#define Odestructor				5124				///< %Particle destructor.
#define Ometaball					5125				///< Metaball.
#define Oinstance					5126				///< Instance.
#define Obend							5128				///< Bend deformer.
#define Obulge						5129				///< Bulge deformer.
#define Oshear						5131				///< Shear deformer.
#define Otaper						5133				///< Taper deformer.
#define Otwist						5134				///< Twist deformer.
#define Owave							5135				///< Wave deformer.
#define Ostage						5136				///< Stage.
#define Oline							5137				///< Line.
#define Onull							5140				///< Null.
#define Osymmetry					5142				///< Symmetry.
#define Owrap							5143				///< Wrap deformer.
#define Oboole						1010865			///< Boolean.
#define Oexplosion				5145				///< Explosion deformer.
#define Oformula					5146				///< Formula deformer.
#define Omelt							5147				///< Melt deformer.
#define Oshatter					5148				///< Shatter deformer.
#define Owinddeform				5149				///< Wind deformer.
#define Oarray						5150				///< Array.
#define Oworkplane				5153				///< Workplane.
#define Oplugin						5154				///< Object plugin. Pass the plugin ID.
#define Obase							5155				///< Base object - BaseObject.
#define Opoint						5156				///< Point - PointObject.
#define Obasedeform				5157				///< Base deformer. For @c instanceof parameters in the API.
#define Oparticlemodifier	5158				///< %Particle modifier.
#define Opolyreduction		1001253			///< @markDeprecated Legacy polygon reduction.
#define Opolyreduxgenerator	465002101	///< Polygon reduction generator. @since R19
#define Oshowdisplacement	1001196			///< Show displacement.
#define Ojoint						1019362			///< Joint.
#define Oskin							1019363			///< Skin deformer.
#define Oweighteffector		1019677			///< Weight effector.
#define Ocharacter				1021433			///< Character.
#define Ocmotion					1021824			///< CMotion.
#define Oxref							1025766			///< XRef.
#define Omotiontracker		1028393			///< Motion tracker. @since R18
#define Oobjecttracker		1036100			///< Object tracker.
#define Ofieldforce				1041451			///< %Particle field force
#define Oscatterobject		1055907			///< Scatter. @since R24
#define Osymmetrygenerator 1060011    ///< Symmetry Generator. @since 2023.200
#define Osolidifygenerator 1060179    ///< Solidify Generator. @since 2023.200
#define Obooleangenerator 1060679			///< Boolean Generator.
#define Tbooleantag				1060823			///< Boolean Tag.
/// @addtogroup PrimitiveTypes Primitive Types
/// @ingroup group_enumeration
/// @{
#define Ocube							5159				///< Cube.
#define Osphere						5160				///< Sphere.
#define Oplatonic					5161				///< Platonic.
#define Ocone							5162				///< Cone.
#define Otorus						5163				///< Torus.
#define Odisc							5164				///< Disc.
#define Otube							5165				///< Tube.
#define Ofigure						5166				///< Figure.
#define Opyramid					5167				///< Pyramid.
#define Oplane						5168				///< Plane.
#define Ofractal					5169				///< Fractal.
#define Ocylinder					5170				///< Cylinder.
#define Ocapsule					5171				///< Capsule.
#define Ooiltank					5172				///< Oil-tank.
#define Orelief						5173				///< Relief.
#define Osinglepoly				5174				///< Single polygon.
/// @}
#define Opluginpolygon 1001091				///< Polygon plugin.
/// @addtogroup SplinePrimitiveTypes Spline Primitive Types
/// @ingroup group_enumeration
/// @{
#define Osplineprimitive	5152				///< Spline primitive.
#define Osplineprofile		5175				///< Profile spline.
#define Osplineflower			5176				///< Flower spline.
#define Osplineformula		5177				///< Formula spline.
#define Osplinetext				5178				///< Text spline.
#define Osplinenside			5179				///< N-sided spline.
#define Ospline4side			5180				///< 4-sided spline.
#define Osplinecircle			5181				///< Circle spline.
#define Osplinearc				5182				///< Arc spline.
#define Osplinecissoid		5183				///< Cissoid spline.
#define Osplinecycloid		5184				///< Cycloid spline.
#define Osplinehelix			5185				///< Helix spline.
#define Osplinerectangle	5186				///< Rectangle spline.
#define Osplinestar				5187				///< Star spline.
#define Osplinecogwheel		5188				///< Cogwheel spline.
#define Osplinecontour		5189				///< Contour spline.
/// @}
#define Oselection				5190				///< Selection object.
#define Osds							1007455			///< SDS (HyperNURBS) - SDSObject.
#define Osplinedeformer		1008982			///< Spline deformer.
#define Osplinerail				1008796			///< Spline rail.
#define Oatomarray				1001002			///< Atom array.
#define Ospherify					1001003			///< Spherify.
#define Opointprojector		1060422			///< Point projector.
#define Oexplosionfx			1002603			///< Explosion FX.
#define Oconnector				1011010			///< Connector.
#define Oalembicgenerator 1028083			///< Alembic generator.
#define Ofalloff					440000229		///< Falloff object. @since R18
#define Ofield						440000200		///< Field object
#define Fieldremapper			440000289		///< Field object
#define Ovoronoipointgenerator	1036448	///< Voronoi Fracture internal Point generator. @since R19
#define Olod							431000174		///< LOD object.
#define Ovolume						1039858			///< Volume Object. @since R20
#define Ovolumeset				1039867			///< Volume Group. @since R20
#define Ovolumebuilder		1039859			///< Volume Builder. @since R20
#define Ovolumeloader			1039866			///< Volume Loader. @since R20
#define Ovolumemesher			1039861			///< Volume Mesher. @since R20
#define Ovolumefilter			1039862			///< Volume Filter. @since R20
#define Opyro							1059580			///< Pyro Object. @since 2023.100

#define SKY_OBJECT				1011146				///< Sky object ID.

// SDK-Team exposed symbols. Please remove the @PublicExposure tag when you intend to make
// one of the symbols 'official' be replacing all locally defined symbols with the one exposed in
// this file.
#define Obevel							 431000028 ///< Object plugin 'Bevel Deformer'. @PublicExposure
#define Obodycapture				 1053360	 ///< Object plugin 'Body Capture'. @PublicExposure
#define Ovolumecachelayer		 1050456	 ///< Object plugin 'Volume Cache Layer'. @PublicExposure
#define Ocacameraspacedeform 1024476	 ///< Object plugin 'Camera Deformer'. @PublicExposure
#define Omgcloner						 1018544	 ///< Object plugin 'Cloner'. @PublicExposure
#define Ocloth							 100004007 ///< Object plugin 'Cloth Surface'. @PublicExposure
#define Ocacluster					 1021283	 ///< Object plugin 'Cluster'. @PublicExposure
#define Omgcoffee						 440000051 ///< Object plugin 'COFFEE'. @PublicExposure
#define Ocacollision				 1024544	 ///< Object plugin 'Collision Deformer'. @PublicExposure
#define Ocacomponent				 1022292	 ///< Object plugin 'Component'. @PublicExposure
#define Oconnectorconstraint 180000011 ///< Object plugin 'Connector'. @PublicExposure
#define Ocacorrection				 1024542	 ///< Object plugin 'Correction Deformer'. @PublicExposure
#define Odatacapture				 1056362	 ///< Object plugin 'Data Capture'. @PublicExposure
#define Omgdelay						 1019234	 ///< Object plugin 'Delay Effector'. @PublicExposure
#define Odisplacer					 1018685	 ///< Object plugin 'Displacer Modifier'. @PublicExposure
#define Odoodle							 1022242	 ///< Object plugin 'Doodle Object'. @PublicExposure
#define Ofacecapture				 1040464	 ///< Object plugin 'Face Capture'. @PublicExposure
#define Ofeathers						 1018396	 ///< Object plugin 'Feathers'. @PublicExposure
#define Oforce							 180000103 ///< Object plugin 'Force'. @PublicExposure
#define Omgformula					 1018883	 ///< Object plugin 'Formula Effector'. @PublicExposure
#define Omgfracture					 1018791	 ///< Object plugin 'Fracture'. @PublicExposure
#define Ofur								 1018958	 ///< Object plugin 'Fur'. @PublicExposure
#define Omgroup							 1019351	 ///< Object plugin 'Group'. @PublicExposure
#define Oguide							 1027657	 ///< Object plugin 'Guide'. @PublicExposure
#define Omginheritance			 1018775	 ///< Object plugin 'Inheritance Effector'. @PublicExposure
#define Ocajiggle						 1021284	 ///< Object plugin 'Jiggle Deformer'. @PublicExposure
#define Omgmatrix						 1018545	 ///< Object plugin 'Matrix'. @PublicExposure
#define Ocamesh							 1024543	 ///< Object plugin 'Mesh'. @PublicExposure
#define Omgextrude					 1019358	 ///< Object plugin 'MoExtrude'. @PublicExposure
#define Omginstance					 1018957	 ///< Object plugin 'MoInstance'. @PublicExposure
#define Ocamorph						 1019768	 ///< Object plugin 'Morph Deformer'. @PublicExposure
#define Omgspline						 1018774	 ///< Object plugin 'Mograph Spline'. @PublicExposure
#define Omotor							 180000012 ///< Object plugin 'Motor'. @PublicExposure
#define Ocaskin							 1026352	 ///< Object plugin 'MSkin'. @PublicExposure
#define Ocamuscle						 1026224	 ///< Object plugin 'Muscle'. @PublicExposure
#define Opivot							 100004839 ///< Object plugin 'Pivot'. @PublicExposure
#define Opivotmanipulator		 431000170 ///< Object plugin 'Pivot Manipulator'. @PublicExposure
#define Omgplain						 1021337	 ///< Object plugin 'Plain Effector'. @PublicExposure
#define Oplanemanipulator		 431000167 ///< Object plugin 'Plane Manipulator'. @PublicExposure
#define Opatternmanipulator	 1060906	 ///< Object plugin 'Pattern Selection Manipulator'. @PublicExposure
#define Ocapointcache				 1021318	 ///< Object plugin 'Point Cache'. @PublicExposure
#define Omgpolyfx						 1019222	 ///< Object plugin 'PolyFX'. @PublicExposure
#define Omgpushapart				 440000219 ///< Object plugin 'Push Apart Effector'. @PublicExposure
#define Omgpython						 1025800	 ///< Object plugin 'Python Efector'. @PublicExposure
#define Omgrandom						 1018643	 ///< Object plugin 'Random Effector'. @PublicExposure
#define Orsbakeset					 1040211	 ///< Object plugin 'Redshift BakeSet'. @PublicExposure
#define Orsenvironment			 1036757	 ///< Object plugin 'Redshift Environment'. @PublicExposure
#define Orsproxy						 1038649	 ///< Object plugin 'Redshift Proxy'. @PublicExposure
#define Orssky							 1036754	 ///< Object plugin 'Redshift Sky'. @PublicExposure
#define Orsvolume						 1038655	 ///< Object plugin 'Redshift Volume'. @PublicExposure
#define Omgreeffector				 440000234 ///< Object plugin 'ReEffector Efector'. @PublicExposure
#define Oremesh							 1054750	 ///< Object plugin 'Remesh'. @PublicExposure
#define Omgshader						 1018561	 ///< Object plugin 'Shader Efector'. @PublicExposure
#define Oshrinkwrap					 1019774	 ///< Object plugin 'Shrink Wrap Deformer'. @PublicExposure
#define Oxrefsimple					 200000118 ///< Object plugin 'Simple XRef'. @PublicExposure
#define Osimulationscene		 1057221	 ///< Object plugin 'Simulation Scene'. @PublicExposure
#define Ocasmooth						 1024529	 ///< Object plugin 'Smoothing Deformer'. @PublicExposure
#define Omgsound						 440000255 ///< Object plugin 'Sound Effector'. @PublicExposure
#define Omgsplinemask				 1019396	 ///< Object plugin 'Spline Mask'. @PublicExposure
#define Omgsplinewrap				 1019221	 ///< Object plugin 'Spline Wrap Deformer'. @PublicExposure
#define Ospring							 180000010 ///< Object plugin 'Spring'. @PublicExposure
#define Ocasquash						 1021280	 ///< Object plugin 'Squash & Stretch Deformer'. @PublicExposure
#define Omgstep							 1018881	 ///< Object plugin 'Step Effector'. @PublicExposure
#define Ocastep							 1026918	 ///< Object plugin 'Step'. @PublicExposure
#define Ocasurface					 1024552	 ///< Object plugin 'Surface Deformer'. @PublicExposure
#define Omgeffectortarget		 1018889	 ///< Object plugin 'Target Effector'. @PublicExposure
#define Omgtext							 1019268	 ///< Object plugin 'Text'. @PublicExposure
#define Omgtime							 1018935	 ///< Object plugin 'Time Effector'. @PublicExposure
#define Omgtracer						 1018655	 ///< Object plugin 'Tracer'. @PublicExposure
#define Ovectorimport				 1057899	 ///< Object plugin 'Vector Import'. @PublicExposure
#define Omgvolume						 1021287	 ///< Object plugin 'Volume'. @PublicExposure
#define Omgvoronoifracture	 1036557	 ///< Object plugin 'Voronoi Fracture'. @PublicExposure
#define Omotionclip					 465003002 ///< Object plugin 'Motion Clip'. @PublicExposure

/// @}

/// @addtogroup Yplugin
/// @ingroup group_enumeration
/// @{
/// Small list node plugin.
#define Yplugin 110061
/// @}

/// @addtogroup Zplugin
/// @ingroup group_enumeration
/// @{
/// Big list node plugin.
#define Zplugin 110062
/// @}

/// @addtogroup Zplugin
/// @ingroup group_enumeration
/// @{
/// @markPrivate
#define Olayer 100004801
/// @}

/// @addtogroup Fbase
/// @ingroup group_enumeration
/// @{
/// Virtual filter base.
#define Fbase 1001024
/// @}

/// @addtogroup Zmultipass
/// @ingroup group_enumeration
/// @{
/// Multipass render settings element.
#define Zmultipass 300001048
/// @}

/// @addtogroup SHplugin
/// @ingroup group_enumeration
/// @{
#define SHplugin 110065			///< Shader plugin.
/// @}

/// @addtogroup VPplugin
/// @ingroup group_enumeration
/// @{
#define VPplugin 110066			///< Videopost plugin.
/// @}

#define ID_LISTHEAD		110063			///< GeListHead ID.
#define ID_LISTHEADCB 440000341		///< GeListHead with CallBack ID.

/// @addtogroup Rbase
/// @ingroup group_enumeration
/// @{
#define Rbase 110304			///< %Render data ID.
/// @}

/// @addtogroup ShaderTypes Shader Types
/// @ingroup group_enumeration
/// @{
#define Xbase							5707				///< Shader base.
#define Xcolor						5832				///< Color.
#define Xbitmap						5833				///< Bitmap.
#define Xbrick						5804				///< Brick.
#define Xcheckerboard			5800				///< Checkerboard.
#define Xcloud						5802				///< Cloud.
#define Xcolorstripes			5822				///< Color stripes.
#define Xcyclone					5821				///< Cyclone.
#define Xearth						5825				///< Earth.
#define Xfire							5803				///< Fire.
#define Xflame						5817				///< Flame.
#define Xgalaxy						5813				///< Galaxy.
#define Xmetal						5827				///< Metal.
#define Xsimplenoise			5807				///< Simple noise.
#define Xrust							5828				///< Rust.
#define Xstar							5816				///< Star.
#define Xstarfield				5808				///< Star field.
#define Xsunburst					5820				///< Sun burst.
#define Xsimpleturbulence	5806				///< Simple turbulence.
#define Xvenus						5826				///< Venus.
#define Xwater						5818				///< Water.
#define Xwood							5823				///< Wood.
#define Xplanet						5829				///< Planet.
#define Xmarble						5830				///< Marble.
#define Xspectral					5831				///< Spectral.
#define Xgradient					1011100			///< %Gradient.
#define Xfalloff					1011101			///< Falloff.
#define Xtiles						1011102			///< Tiles.
#define Xfresnel					1011103			///< Fresnel.
#define Xlumas						1011105			///< Lumas.
#define Xproximal					1011106			///< Proximal.
#define Xnormaldirection	1011107			///< Normal direction.
#define Xtranslucency			1011108			///< Translucency.
#define Xfusion						1011109			///< Fusion.
#define Xposterizer				1011111			///< Posterizer.
#define Xcolorizer				1011112			///< Colorizer.
#define Xdistorter				1011114			///< Distorter.
#define Xprojector				1011115			///< Projector.
#define Xnoise						1011116			///< Noise.
#define Xlayer						1011123			///< Layer.
#define Xspline						1011124			///< Spline.
#define Xfilter						1011128			///< Filter.
#define Xripple						1011199			///< Ripple.
#define Xvertexmap				1011137			///< Vertex map.
#define Xsss							1001197			///< SSS.
#define Xambientocclusion	1001191			///< Ambient occlusion.
#define Xchanlum					1007539			///< Chanlum.
#define Xmosaic						1022119			///< Pixelate.
#define Xxmbsubsurface		1025614			///< Subsurface scattering.
#define Xrainsampler			1026576			///< Rain sampler.
#define Xnormalizer				1026588			///< Normalizer.
#define Xterrainmask			1026277			///< Terrain mask.
#define Xobjectcolor			1033961			///< Object color.
#define Xformula					1031433			///< Formula. @since R17.032
#define Xvariation				1033825 		///< Variation. @since R17.032
#define Xthinfilm					1035731			///< Thinfilm. @since R18
static const Int Xnbm = 300001079;
static const Int Xnodeviewport = 1050994;
static const Int XstandardSpaceActivity = 1051374;

// SDK-Team exposed symbols. Please remove the @PublicExposure tag when you intend to make
// one of the symbols 'official' be replacing all locally defined symbols with the one exposed in
// this file.
#define Xart						1012161		///< Shader plugin 'Art'. @PublicExposure
#define Xmgbeat					1018654		///< Shader plugin 'Beat Shader'. @PublicExposure
#define Xmgcamera				440000050 ///< Shader plugin 'Camera Shader'. @PublicExposure
#define Xcel						1012158		///< Shader plugin 'Cel'. @PublicExposure
#define Xmgcolor				1018767		///< Shader plugin 'Color Shader'. @PublicExposure
#define Xhatch					1012166		///< Shader plugin 'Hatch'. @PublicExposure
#define Xlensdistortion 1031708		///< Shader plugin 'Lens Distortion'. @PublicExposure
#define Xmovesface			1040942		///< Shader plugin 'Moves Face Shader'. @PublicExposure
#define Xmgmultishader	1019397		///< Shader plugin 'Multi Shader'. @PublicExposure
#define Xpavement				1024945		///< Shader plugin 'Pavement'. @PublicExposure
#define Xpolygonhair		1017667		///< Shader plugin 'Polygon Hair'. @PublicExposure
#define Xspots					1012160		///< Shader plugin 'Spots'. @PublicExposure

/// @}

/// @defgroup SelectionTagTypes SelectionTag Types
/// @ingroup group_enumeration

/// @defgroup VariableTagTypes VariableTag Types
/// @ingroup group_enumeration

/// @addtogroup TagTypes Tag Types
/// @ingroup group_enumeration
/// @{
#define Tpoint						5600					///< Point - PointTag. @ingroup VariableTagTypes
#define Tphong						5612					///< Phong.
#define Tdisplay					5613					///< Display.
#define Ttexture					5616					///< Texture - TextureTag.
#define Ttangent					5617					///< Tangent data- TangentTag. @ingroup VariableTagTypes
#define Tprotection				5629					///< Protection.
#define Tparticle					5630					///< %Particle data - ParticleTag. @ingroup VariableTagTypes
#define Tmotionblur				5636					///< Motion blur.
#define Tcompositing			5637					///< Compositing/render.
#define Tannotation				1030659				///< Annotation.
#define Tsavetemp					5650					///< @markInternal
#define Tpolygon					5604					///< Polygon data - PolygonTag. @ingroup VariableTagTypes
#define Tuvw							5671					///< UVW data - UVWTag. @ingroup VariableTagTypes
#define Tsegment					5672					///< Segment data - SegmentTag. @ingroup VariableTagTypes
#define Tpolygonselection	5673					///< Polygon selection - SelectionTag. @ingroup SelectionTagTypes
#define Tpointselection		5674					///< Point selection - SelectionTag. @ingroup SelectionTagTypes
#define Ttargetexpression	5676					///< Target expression.
#define Tsunexpression		5678					///< Sun expression.
#define Tline							5680					///< Line data. @ingroup VariableTagTypes
#define Tvertexmap				5682					///< Vertex map data. @ingroup VariableTagTypes
#define Trestriction			5683					///< Restriction.
#define Tmetaball					5684					///< Metaball.
#define Tbakeparticle			5685					///< Bake particle.
#define Tmorph						5689					///< Morph. @markDeprecated
#define Tsticktexture			5690					///< Pin Material - StickTextureTag. @ingroup VariableTagTypes
#define Tplugin						5691					///< Plugin tag - pass the plugin ID.
#define Tstop							5693					///< Stop.
#define Tbase							5694					///< Base tag - BaseTag.
#define Tvariable					5695					///< Variable tag - VariableTag.
#define Tvibrate					5698					///< Vibration.
#define Taligntospline		5699					///< Align to spline.
#define Taligntopath			5700					///< Align to path.
#define Tedgeselection		5701					///< Edge selection - SelectionTag. The edges are encodes like this: <tt>(4*poly)+edge</tt>, where @c edge goes from @em 0-@em 3. @ingroup SelectionTagTypes
#define Tnormal						5711					///< Normal - NormalTag. Contains 12 ::Int16 per polygon, enumerated like the following: <tt>ax,ay,az,bx,by,bz,cx,cy,cz,dx,dy,dz</tt>.\n
																				///< The value is the Float value of the normal vector component multiplied by @em 32000.0.
																				///< @ingroup VariableTagTypes
#define Tcorner						5712					///< Corner. (Phong break.)
#define Tsds							1007579				///< SDS.
#define Tlookatcamera			1001001				///< Look at camera.
#define Texpresso					1001149				///< XPresso.
#define Tsoftselection		1016641				///< Soft selection.
#define Tbaketexture			1011198				///< Bake texture.
#define Tsdsdata					1018016				///< SDS data.
#define Tweights					1019365				///< Weights.
#define Tposemorph				1024237				///< Pose morph.
#define Tpython						1022749				///< Python expression.
#define Tsculpt						1023800				///< Sculpt.
#define Tmotioncam				1027742				///< Motion camera.
#define Tmorphcam					1027743				///< Morph camera.
#define Tcrane						1028270				///< Camera crane.
#define Tarchigrass				1028463				///< Architectural grass.
#define Tsculptnormals		1027660				///< Sculpt normals. @b Private for Sculpting.
#define Tsplinenormal			440000173			///< Spline normals.
#define Tinteraction			440000164			///< Interaction.
#define Tgrouppriority		200000299			///< Group Priority. @since R18
#define Tvertexcolor			431000045			///< Vertex color. @since R18
#define Talembicmorphtag	1037184				///< Alembic Morph. @since R19
#define Tmeshattribute 		431000188			///< CustomDataTag. @since R20
#define Tuserdata					1041349				///< User Data Tag. @since R21
#define Tgeneric					431000047			///< Generic vertex tag. @markPrivate @since 2023.100

#define Tcacheproxytag		1050449				///< Cache proxy tag. @b Since R21; private for generators.
#define Tcacheproxytagpolyselection		1051630		///< Cache proxy tag for polygon selection. @b Since R21; private for generators.
#define Tcacheproxytagpointselection	1051631		///< Cache proxy tag for point selection. @b Since R21; private for generators.
#define Tcacheproxytagedgeselection		1051632		///< Cache proxy tag for edge selection. @b Since R21; private for generators.

#define Tchardefinition			1054858		///< Character Definition Tag. @b Since R24
#define Tcharmotiontransfer 1055068		///< Character Motion Transfer Tag. @b Since R24
#define Ttrackmodifier			1056836
#define Tcineware						465000402 ///< Cineware tag to mark objects for external usage. Previously known as external compositing tag.

#define Tpyro								1059387		///< Pyro Tag. @since 2023.100

// SDK-Team exposed symbols. Please remove the @PublicExposure tag when you intend to make
// one of the symbols 'official' be replacing all locally defined symbols with the one exposed in
// this file.
#define Tcameracalibrator		1026818		///< Tag plugin 'Camera Calibrator'. @PublicExposure
#define Tcameraorrientation 1029911		///< Tag plugin 'Camera Orientation Constraint'. @PublicExposure
#define Tcacomponent				1022113		///< Tag plugin 'Character Component'. @PublicExposure
#define Tcloth							100004020 ///< Tag plugin 'Cloth'. @PublicExposure
#define Tclothbelt					100004022 ///< Tag plugin 'Cloth Belt'. @PublicExposure
#define Tcollider						100004021 ///< Tag plugin 'Collider'. @PublicExposure
#define Tconnector					1058895		///< Tag plugin 'Connector'. @PublicExposure
#define Tcaconstraint				1019364		///< Tag plugin 'Constraint'. @PublicExposure
#define Tdoodleimage				1022211		///< Tag plugin 'Doodle Image'. @PublicExposure
#define Tdriver							1019744		///< Tag plugin 'Driver'. @PublicExposure
#define Tdynamicsbody				180000102 ///< Tag plugin 'Dynamics Body'. @PublicExposure
#define Tcaik								1019561		///< Tag plugin 'IK'. @PublicExposure
#define Tcaikspline					1019862		///< Tag plugin 'IK-Spline'. @PublicExposure
#define Tmaskconstraint			1029912		///< Tag plugin 'Mask Constraint'. @PublicExposure
#define Tmgcolor						1018768		///< Tag plugin 'Motion Graphics Color Tag'. @PublicExposure
#define Tmgdependence				1019352		///< Tag plugin 'Motion Graphics Dependance Tag'. @PublicExposure
#define Tmgtracer						1019326		///< Tag plugin 'Motion Graphics Tracer Tag'. @PublicExposure
#define Tmoveseye						1040866		///< Tag plugin 'Moves Eye Tag'. @PublicExposure
#define Tmovesposemorph			1040839		///< Tag plugin 'Moves Pose Morph Helper'. @PublicExposure
#define Tplanarconstraint		1029910		///< Tag plugin 'Planar Constraint'. @PublicExposure
#define Tcapointcache				1021302		///< Tag plugin 'Point Cache'. @PublicExposure
#define Tpositionconstraint 1029908		///< Tag plugin 'Position Constraint'. @PublicExposure
#define Trscamera						1036760		///< Tag plugin 'Redshift Camera'. @PublicExposure
#define Trsobject						1036222		///< Tag plugin 'Redshift Object'. @PublicExposure
#define Trender							1018385		///< Tag plugin 'Render'. @PublicExposure
#define Tretarget						100001735 ///< Tag plugin 'Retarget'. @PublicExposure
#define Trigidbody					1059981		///< Tag plugin 'Rigid Body'. @PublicExposure
#define Trope								1018068		///< Tag plugin 'Rope'. @PublicExposure
#define Tropebelt						1018074		///< Tag plugin 'Rope Belt'. @PublicExposure
#define Tscenenodes					180420300 ///< Tag plugin 'Scene Nodes Tag'. @PublicExposure
#define Tsketchrender				1011961		///< Tag plugin 'Sketch Render'. @PublicExposure
#define Tsketchstyle				1011012		///< Tag plugin 'Sketch Style'. @PublicExposure
#define Tcatension					1018327		///< Tag plugin 'Tension'. @PublicExposure
#define Ttodo								465001537 ///< Tag plugin 'To Do'. @PublicExposure
#define Tvectorconstraint		1029909		///< Tag plugin 'Vector Constraint'. @PublicExposure
#define Tcavisualselector		1026275		///< Tag plugin 'Visual Selector'. @PublicExposure
#define Tmotionsystem				465003000 ///< Tag plugin 'Motion System'. @PublicExposure
/// @}

/// @addtogroup NLAbase
/// @ingroup group_enumeration
/// @{
#define NLAbase	5349			///< NLA base.
/// @}

/// @addtogroup CAnim
/// @ingroup group_enumeration
/// @{
#define CTbase	5350			///< Base track ID.
#define CSbase	5351			///< Base curve ID.
#define CKbase	5352			///< Base key ID.
/// @}

/// @addtogroup TrackTypes
/// @ingroup group_enumeration
/// @{
#define CTpla		100004812			///< PLA.
#define CTsound	100004813			///< Sound.
#define CTmorph	100004822			///< Morph.
#define CTtime	-1						///< Time.

// SDK-Team exposed symbols. Please remove the @PublicExposure tag when you intend to make
// one of the symbols 'official' be replacing all locally defined symbols with the one exposed in
// this file.
#define CT2d		 1029916 ///< Ctrack plugin '2D Tracks'. @PublicExposure
#define CTdoodle 1022213 ///< Ctrack plugin 'Doodle Track'. @PublicExposure
#define CTMask	 1029915 ///< Ctrack plugin 'Mask Track'. @PublicExposure
/// @}

/// @addtogroup TakeTypes
/// @ingroup group_enumeration
/// @{
/// @since R17.032
#define OverrideBase	431000051			///< Override Node.
#define OverrideGroup	431000075			///< Override Group Node.
#define TakeBase			431000054			///< Take Nodes.
/// @}

/// @addtogroup TL_MARKEROBJ
/// @ingroup group_enumeration
/// @{
/// Timeline marker ID.
#define TL_MARKEROBJ 465001514
/// @}

/// @addtogroup ID_MACHINE
/// @ingroup group_enumeration
/// @{
#define ID_MACHINE			300002140			///< Machine.
#define ID_MACHINEGROUP	300002142			///< Machine group.
/// @}

/// @addtogroup GVbase
/// @ingroup group_enumeration
/// @{
#define GVbase 1001101			///< Graphview base.
/// @}

/// @addtogroup ID_BS_HOOK
/// @ingroup group_enumeration
/// @{
#define ID_BS_HOOK 100004808			///< BaseSceneHook ID.
/// @}

static const Int XnodeEmulation = 300001078;				/// @markPrivate

static const Int32 ID_SHOWSUBCHANNELS = 300001080;	/// @markPrivate

/// @addtogroup MCOMMAND
/// @ingroup group_enumeration
/// @{
/// %Modeling command IDs.
/// @see	SendModelingCommand()
///				@ref MDATA for the container IDs that can be set as options for a command.
#define MCOMMAND_SPLINE_HARDINTERPOLATION	100			///< Hard interpolation.
#define MCOMMAND_SPLINE_SOFTINTERPOLATION	101			///< Soft interpolation.
#define MCOMMAND_SPLINE_REORDER						102			///< Reorder.
#define MCOMMAND_SPLINE_REVERSE						103			///< Reverse sequence.
#define MCOMMAND_SPLINE_MOVEDOWN					104			///< Move down sequence.
#define MCOMMAND_SPLINE_MOVEUP						105			///< Move up sequence.
#define MCOMMAND_SPLINE_JOINSEGMENT				109			///< Join segment.
#define MCOMMAND_SPLINE_BREAKSEGMENT			110			///< Break segment.
#define MCOMMAND_SPLINE_EQUALLENGTH				111			///< Equal tangent length.
#define MCOMMAND_SPLINE_EQUALDIRECTION		112			///< Equal tangent direction.
#define MCOMMAND_SPLINE_LINEUP						113			///< Line up.
#define MCOMMAND_SPLINE_CREATEOUTLINE			114			///< Create outline: @enumerateEnum{MDATA_SPLINE}
#define MCOMMAND_SPLINE_PROJECT						115			///< Project: @enumerateEnum{MDATA_SPLINE_PROJECTMODE}
#define MCOMMAND_SPLINE_ADDPOINT					116			///< Add point: @enumerateEnum{MDATA_SPLINE_ADDPOINTSEGMENT} @enumerateEnum{MDATA_SPLINE_ADDPOINTPOSITION}
#define MCOMMAND_SELECTALL								200			///< Select all.
#define MCOMMAND_DESELECTALL							201			///< Deselect all.
#define MCOMMAND_SELECTINVERSE						202			///< Invert selection.
#define MCOMMAND_SELECTCONNECTED					203			///< Select connected.
#define MCOMMAND_SELECTGROW								204			///< Grow selection.
#define MCOMMAND_SELECTSHRINK							205			///< Shrink selection.
#define MCOMMAND_SELECTPOINTTOPOLY				206			///< Polygon selection from points.
#define MCOMMAND_SELECTPOLYTOPOINT				207			///< Point selection from polygons.
#define MCOMMAND_SELECTADJACENT						208			///< Select adjacent.
#define MCOMMAND_GENERATESELECTION				209			///< Generate selection.
#define MCOMMAND_HIDESELECTED							211			///< Hide selected.
#define MCOMMAND_HIDEUNSELECTED						212			///< Hide unselected
#define MCOMMAND_HIDEINVERT								213			///< Hide invert.
#define MCOMMAND_UNHIDE										214			///< Unhide.
#define MCOMMAND_REVERSENORMALS						217			///< Reverse normals: @enumerateEnum{MDATA_REVERSENORMALS}
#define MCOMMAND_ALIGNNORMALS							218			///< Align normals: @enumerateEnum{MDATA_ALIGNNORMALS}
#define MCOMMAND_SPLIT										220			///< Split.
#define MCOMMAND_TRIANGULATE							221			///< Triangulate.
#define MCOMMAND_UNTRIANGULATE						222			///< Untriangulate: @enumerateEnum{MDATA_UNTRIANGULATE}
#define MCOMMAND_DELETE										224			///< Delete.
#define MCOMMAND_OPTIMIZE									227			///< Optimize: @enumerateEnum{MDATA_OPTIMIZE}
#define MCOMMAND_DISCONNECT								228			///< Disconnect: @enumerateEnum{MDATA_DISCONNECT_PRESERVEGROUPS}
#define MCOMMAND_MAKEEDITABLE							230			///< Make editable (returns object).
#define MCOMMAND_MIRROR										237			///< Mirror: @enumerateEnum{MDATA_MIRROR}
#define MCOMMAND_MATRIXEXTRUDE						238			///< Matrix extrude
#define MCOMMAND_SUBDIVIDE								242			///< Subdivide: @enumerateEnum{MDATA_SUBDIVIDE}
#define MCOMMAND_EXPLODESEGMENTS					243			///< Explode segments.
#define MCOMMAND_KNIFE										244			///< Knife: @enumerateEnum{MDATA_KNIFE}
#define MCOMMAND_CURRENTSTATETOOBJECT			245			///< Current state to object (returns object): @enumerateEnum{MDATA_CURRENTSTATETOOBJECT}

#define MCOMMAND_JOIN											246			///< Join (returns object): @enumerateEnum{MDATA_JOIN_MERGE_SELTAGS}
																									///< @note	The objects to join must be children of a parent object. Example:
																									///< @code
																									/// BaseObject* nullobject = BaseObject::Alloc(Onull);
																									///
																									/// objectA->InsertUnder(nullobject);
																									/// objectB->InsertUnder(nullobject);
																									///
																									/// ModelingCommandData cd;
																									/// cd.op = nullobject;
																									/// cd.doc = doc;
																									///
																									/// SendModelingCommand(MCOMMAND_JOIN, cd);
																									/// @endcode

#define MCOMMAND_CONVERTSELECTION					247			///< Convert selection: @enumerateEnum{MDATA_CONVERTSELECTION}
#define MCOMMAND_EDGE_TO_SPLINE						251			///< Edge to spline.
#define MCOMMAND_BREAKPHONG								255			///< Break phong.
#define MCOMMAND_UNBREAKPHONG							256			///< Unbreak phong.
#define MCOMMAND_PHONGTOSELECTION					257			///< Phong to selection.
#define MCOMMAND_MELT											264			///< Melt.
#define MCOMMAND_RESETSYSTEM							265			///< Reset System: @enumerateEnum{MDATA_RESETSYSTEM}

#define MCOMMAND_MIRRORSELECTION					266			///< Mirror Selection: @enumerateEnum{MDATA_MIRRORSELECTION}
#define MCOMMAND_UVUNWRAP									267			///< UV Unwrap: @enumerateEnum{MDATA_UVUNWRAP}
#define MCOMMAND_UVWELDRELAX							268			///< UV Weld and Relax: @enumerateEnum{MDATA_UVWELDRELAX}
#define MCOMMAND_AUTOMATICUV							1053624	///< Automatic UV unwrap and pack: @enumerateEnum{MDATA_AUTOMATICUV}
#define MCOMMAND_PACKUVRASTERIZED					1053659	///< Pack UV rasterized: @enumerateEnum{MDATA_AUTOMATICUV}
/// @}

/// @addtogroup MDATA
/// @ingroup group_containerid
/// @{
/// @addtogroup MDATA_SPLINE
/// @ingroup group_containerid
/// @{
#define MDATA_SPLINE_FREEHANDTOLERANCE						2020			///< ::Float Freehand tolerance.
#define MDATA_SPLINE_OUTLINE											2021			///< ::Float Spline outline distance.
#define MDATA_SPLINE_PROJECTMODE									2022			///< ::Int32 Project mode (see dialog).
#define MDATA_SPLINE_ADDPOINTSEGMENT							2023			///< ::Int32 %Segment.
#define MDATA_SPLINE_ADDPOINTPOSITION							2024			///< ::Float Position.
#define MDATA_SPLINE_ADDPOINTSELECT								2025			///< ::Bool Select added point.
#define MDATA_SPLINE_ADDPOINTRESULTINDEX					2026			///< ::Int32 Returned index of the new point (check after invoking command).
#define MDATA_SPLINE_OUTLINESEPARATE							2080			///< ::Bool Outline separate. Creates new object.
/// @}
#define MDATA_DISCONNECT_PRESERVEGROUPS						2028			///< ::Bool Preserve groups.
/// @addtogroup MDATA_MIRROR
/// @ingroup group_containerid
/// @{
#define MDATA_MIRROR_SNAPPOINTS										2069			///< ::Bool Snap to points.
#define MDATA_MIRROR_DUPLICATE										2070			///< ::Bool Duplicate points.
#define MDATA_MIRROR_WELD													2071			///< ::Bool Mirror points.
#define MDATA_MIRROR_TOLERANCE										2072			///< ::Float Mirror tolerance.
#define MDATA_MIRROR_SYSTEM												2067			///< ::Int32 Coordinate system (see dialog).
#define MDATA_MIRROR_PLANE												2068			///< ::Int32 Mirror plane (see dialog).
#define MDATA_MIRROR_VALUE												2073			///< ::Float Mirror value.
#define MDATA_MIRROR_POINT												2074			///< ::Vector Mirror point.
#define MDATA_MIRROR_VECTOR												2075			///< ::Vector Mirror vector.
#define MDATA_MIRROR_SELECTIONS										2120			///< ::Bool Mirror selections
#define MDATA_MIRROR_ONPLANE											2122			///< ::Bool Mirror on plane.
/// @}
/// @addtogroup MDATA_OPTIMIZE
/// @ingroup group_containerid
/// @{
#define MDATA_OPTIMIZE_TOLERANCE									2076			///< ::Float Optimize tolerance.
#define MDATA_OPTIMIZE_POINTS											2077			///< ::Bool Optimize points.
#define MDATA_OPTIMIZE_POLYGONS										2078			///< ::Bool Optimize polygons.
#define MDATA_OPTIMIZE_UNUSEDPOINTS								2079			///< ::Bool Optimize unused points.
/// @}
#define MDATA_CROSSSECTION_ANGLE									2082			///< ::Float Maximum angle.
/// @addtogroup MDATA_SUBDIVIDE
/// @ingroup group_containerid
/// @{
#define MDATA_SUBDIVIDE_HYPER											2098			///< ::Bool Subdivide Hyper NURBS.
#define MDATA_SUBDIVIDE_ANGLE											2099			///< ::Float Subdivide maximum angle.
#define MDATA_SUBDIVIDE_SPLINESUB									2100			///< ::Int32 Subdivisions (spline).
#define MDATA_SUBDIVIDE_SUB												2101			///< ::Int32 Subdivisions (polygon).
#define MDATA_SUBDIVIDE_SIMPLESUB									2102			///< ::Int32 Non Iterative Subdivisions used for standard subdivision (polygon).
#define MDATA_SUBDIVIDE_PATTERN										2103			///< ::Int32 Used Subdivision Pattern.
#define MDATA_SUBDIVIDE_PATTERN_CATMULL_CLARK			0
#define MDATA_SUBDIVIDE_PATTERN_LOOP							1
#define MDATA_SUBDIVIDE_PATTERN_OPPOSITE					2
/// @}
/// @addtogroup MDATA_KNIFE
/// @ingroup group_containerid
/// @{
#define MDATA_KNIFE_P1														2110			///< ::Vector Knife first point.
#define MDATA_KNIFE_V1														2111			///< ::Vector Knife first vector.
#define MDATA_KNIFE_P2														2112			///< ::Vector Knife second point.
#define MDATA_KNIFE_V2														2113			///< ::Vector Knife second vector.
#define MDATA_KNIFE_ANGLE													2115			///< ::Float Knife angle.
/// @}
/// @addtogroup MDATA_CONVERTSELECTION
/// @ingroup group_containerid
/// @{
#define MDATA_CONVERTSELECTION_LEFT								2126			///< ::Int32 Left selection (see dialog).
#define MDATA_CONVERTSELECTION_RIGHT							2127			///< ::Int32 Right selection (see dialog).
#define MDATA_CONVERTSELECTION_TOLERANT						2128			///< ::Bool Tolerant conversion.
/// @}
/// @addtogroup MDATA_CURRENTSTATETOOBJECT
/// @ingroup group_containerid
/// @{
#define MDATA_CURRENTSTATETOOBJECT_INHERITANCE		2140			///< ::Bool Use inheritance.
#define MDATA_CURRENTSTATETOOBJECT_KEEPANIMATION	2141			///< ::Bool Keep animation.
#define MDATA_CURRENTSTATETOOBJECT_NOGENERATE			2162			///< ::Bool No generate.
#define MDATA_CURRENTSTATETOOBJECT_LOD						2163			///< ::Float The LOD level to generate with.
#define MDATA_CURRENTSTATETOOBJECT_BUILDFLAGS			2164			///< ::Int32 Override for the buildflags: @enumerateEnum{BUILDFLAGS}. Default is BUILDFLAGS::EXTERNALRENDERER | BUILDFLAGS::ISOPARM.
/// @}
#define MDATA_ROTATECAMERA												2142			///< ::Bool Tools/Camera Rotation
/// @addtogroup MDATA_RING
/// @ingroup group_containerid
/// @{
#define MDATA_RING_EDGE														2154			///< ::Int32 Ring edge.
#define MDATA_RING_SELECTION											2155			///< ::Int32 Ring selection: @enumerateEnum{SELECTION}
#define MDATA_RING_SKIP														2156			///< ::Int32 Ring skip.
/// @}
/// @addtogroup MDATA_FILLSEL
/// @ingroup group_containerid
/// @{
#define MDATA_FILLSEL_START_POLY									2157			///< ::Int32 Fill selection start polygon.
#define MDATA_FILLSEL_SELECTION										2158			///< ::Int32 Fill selection: @enumerateEnum{SELECTION}
/// @}
/// @addtogroup MDATA_OUTLINESEL
/// @ingroup group_containerid
/// @{
#define MDATA_OUTLINESEL_START_POLY								2159			///< ::Int32 Outline selection start polygon.
#define MDATA_OUTLINESEL_SELECTION								2160			///< ::Int32 Outline selection: @enumerateEnum{SELECTION}
/// @}
/// @addtogroup MDATA_UNTRIANGULATE
/// @ingroup group_containerid
/// @{
#define MDATA_UNTRIANGULATE_ANGLE									2121			///< ::Bool Evaluate angle.
#define MDATA_UNTRIANGULATE_NGONS									2143			///< ::Bool Create N-gons.
#define MDATA_UNTRIANGULATE_ANGLE_RAD							2161			///< ::Float Angle radius.
/// @}
/// @addtogroup MDATA_RESETSYSTEM
/// @ingroup group_containerid
/// @{
#define MDATA_RESETSYSTEM_COMPENSATE							2165			///< ::Bool Compensate.
#define MDATA_RESETSYSTEM_RECURSIVE								2166			///< ::Bool Recursive.
/// @}
#define MDATA_JOIN_MERGE_SELTAGS									2167			///< ::Bool Merge selection tags.
#define MDATA_JOIN_RESPECT_VISIBILITY							1050529		///< ::Bool Respect the render visibility mode for joining (red/off will not be merged)
/// @addtogroup MDATA_SETVERTEX
/// @ingroup group_containerid
/// @{
#define MDATA_SETVERTEX_VALUE											4000			///< ::Float Set vertex value.
#define MDATA_SETVERTEX_MODE											4001			///< ::Int32 Set vertex mode (see dialog).
/// @}
/// @addtogroup MDATA_REVERSENORMALS
/// @ingroup group_containerid
/// @{
/// @since R19
#define MDATA_REVERSENORMALS_USERNORMALS					2200			///< ::Bool Reverse user normals.
/// @}
/// @addtogroup MDATA_ALIGNNORMALS
/// @ingroup group_containerid
/// @{
/// @since R19
#define MDATA_ALIGNNORMALS_USERNORMALS						2210			///< ::Bool Align user normals.
/// @}
/// @addtogroup MDATA_GROWSELECTION
/// @ingroup group_containerid
/// @{
/// @since R21
#define MDATA_GROWSELECTION_USEEDGE								2211			///< ::Bool Grow selection using edge only.
/// @}
/// @addtogroup MDATA_VOLUMEREMESH
/// @ingroup group_containerid
/// @{
/// @since R20
#define MDATA_VOLUMEREMESH_SIZE										2220			///< ::Float Resulting voxel size that defines the resulting mesh size.
#define MDATA_VOLUMEREMESH_PRESUBDIVIDE						2221			///< ::Bool Pre-subdivide the input mesh.
#define MDATA_VOLUMEREMESH_SMOOTH_STRENGTH				2222			///< ::Float Smooth strength.
#define MDATA_VOLUMEREMESH_CREATESETUP						2223			///< ::Bool Create a Volume Remeshing setting from the settings.
/// @}
/// @addtogroup MDATA_MIRRORSELECTION
/// @ingroup group_containerid
/// @{
/// @since R22
#define MDATA_MIRRORSELECTION_TOLERANCE						2230			///< ::Float Tolerance.
#define MDATA_MIRRORSELECTION_MODE								2231			///< ::Int32 Selection mode (New, Add, Sub).
#define MDATA_MIRRORSELECTION_SPACE								2232			///< ::Int32 Space (see dialog).
#define MDATA_MIRRORSELECTION_PLANE								2233			///< ::Int32 Mirror plane (see dialog).
/// @}
/// @addtogroup MDATA_AUTOMATICUV
/// @ingroup group_containerid
/// @{
/// @since R22
#define MDATA_AUTOMATICUV_TAGINDEX								2240			///< ::Int32 Index of the uv tag that should be the target of the new uv data.
#define MDATA_AUTOMATICUV_OVERLAPIDENTICAL				2241			///< ::Bool Activates the overlap of identical uv islands.
#define MDATA_AUTOMATICUV_OVERLAPMIRRORED					2242			///< ::Bool Activates the overlap of mirrored uv islands.
#define MDATA_AUTOMATICUV_SPACING									2243			///< ::Float Distance for gaps between islands.
#define MDATA_AUTOMATICUV_USENORMALS							2244			///< ::Bool Activates the use of shading normals to help with uv borders.
#define MDATA_AUTOMATICUV_SPACINGASPECT						2245			///< ::Float Spacing aspect ratio.
#define MDATA_AUTOMATICUV_FORCESEAMS							2246			///< ::Bool Forces a seam at hard edges of the mesh.
#define MDATA_AUTOMATICUV_ALLOWSTRETCH						2247			///< ::Float [0.0 .. 0.5] Controls how much stretching is allowed to happen to improve packing.
#define MDATA_AUTOMATICUV_MERGEMULTIOBJECT				2248			///< ::Bool If true and multiple objects are passed they will be packed in one unified UV space.
/// @}
/// @addtogroup MDATA_UVUNWRAP
/// @ingroup group_containerid
/// @{
/// @since R22
#define MDATA_UVUNWRAP_POLYGON										2250			///< ::Bool Restrict to polygon selection.
#define MDATA_UVUNWRAP_PIN												2251			///< ::Bool Pin from point selection.
#define MDATA_UVUNWRAP_REALIGN										2252			///< ::Bool Auto realign.
/// @}
/// @addtogroup MDATA_UVWELDRELAX
/// @ingroup group_containerid
/// @{
/// @since R22
#define MDATA_UVWELDRELAX_PIN											2260			///< ::Bool Pin from point selection.
#define MDATA_UVWELDRELAX_REALIGN									2261			///< ::Bool Auto realign.
#define MDATA_UVWELDRELAX_POLYGON									2262			///< ::Bool Restrict the realgin to the polygon selection.
/// @}
/// @addtogroup MDATA_UVSTRAIGHTEN
/// @ingroup group_containerid
/// @{
/// @since R23
#define MDATA_UVSTRAIGHTEN_ALIGN									2270			///< ::Bool Auto align.
#define MDATA_UVSTRAIGHTEN_KEEP_LENGTH						2271			///< ::Bool Keep length of path segments intact.
#define MDATA_UVSTRAIGHTEN_EQUIDISTANT						2272			///< ::Bool Path segments have identical length.
/// @}
/// @addtogroup MDATA_UVRECTANGULARIZE
/// @ingroup group_containerid
/// @{
/// @since R23
#define MDATA_UVRECTANGULARIZE_ALIGN							2280			///< ::Bool Auto align.
#define MDATA_UVRECTANGULARIZE_EQUIDISTANT				2281			///< ::Bool Path segments have identical length.
/// @}

#define MDATA_LEGACY															2300			///< ::BOOL @markPrivate @since R22
/// @}

/// @addtogroup VOLUME
/// @ingroup group_enumeration
/// @{
/// %Volume command IDs.
/// @see	SendVolumeCommand()
///				@ref VOLUMEDATA for the container IDs that can be set as options for a command.
enum class VOLUMECOMMANDTYPE
{
	NONE = 0,
	VOLUMETOMESH = 1,								///< Convert a VolumeObject into a PolygonObject.
	MESHTOVOLUME = 2,								///< Convert a PolygonObject into a SDF VolumeObject.
	VOLUMEBOOLE = 3,								///< Boolean operation on SDF VolumeObjects.
	PARTICLESTOVOLUME = 4,					///< Convert Particle Objects and TP groups to a SDF VolumeObject.
	SPLINETOVOLUME = 5,							///< Convert Spline Objects to a SDF VolumeObject.
	FILTER = 6,											///< Filter a float grid VolumeObject.
	SDFFILTER = 7,									///< Filter a float grid SDF VolumeObject.
	SDFTOFOG = 8,										///< Convert a SDF Volume to a Fog Volume.
	FOGTOSDF = 9, 									///< Convert a Fog Volume to a SDF Volume.
	RESAMPLE = 10,									///< Resample a Volume to a new gridsize.
	MIX = 11,												///< Mix operation on Fog VolumeObjects.
	FIELDTOVOLUME = 12,							///< Convert a Field to a Fog Volume.
	CREATESPHEREVOLUME = 13,				///< Creates a sphere volume.
	CREATEPLATONICVOLUME = 14,			///< Creates a platonic volume.
} MAXON_ENUM_LIST(VOLUMECOMMANDTYPE);

/// %Volume Types.
enum class GRIDTYPE
{
	NONE = 0,
	FLOAT = 1,
	DOUBLE = 2,
	INT32 = 3,
	INT64 = 4,
	INTVECTOR32 = 5,
	VECTOR32 = 6,
	VECTOR64 = 7,
	STRING = 8,
	BOOLEAN = 9
} MAXON_ENUM_LIST(GRIDTYPE);

/// %Volume Classes.
enum class GRIDCLASS
{
	NONE = 0,
	SDF = 1,
	FOG = 2,
	STAGGERED = 3,
	UNKNOWN = 4
} MAXON_ENUM_LIST(GRIDCLASS);

/// %Vector Volume Types.
enum class VECTORGRIDTYPE
{
	INVARIANT = 0,							// Does not transform (e.g., tuple, uvw, color)
	COVARIANT = 1,							// Apply inverse-transpose transformation: w = 0, ignores translation (e.g., gradient/normal)
	COVARIANT_NORMALIZE = 2,		// Apply inverse-transpose transformation: w = 0, ignores translation, vectors are renormalized (e.g., unit normal)
	CONTRAVARIANT_RELATIVE = 3, // Apply "regular" transformation: w = 0, ignores translation (e.g., displacement, velocity, acceleration)
	CONTRAVARIANT_ABSOLUTE = 4	// Apply "regular" transformation: w = 1, vector translates (e.g., position)
} MAXON_ENUM_LIST(VECTORGRIDTYPE);
/// @}

/// @addtogroup VOLUMEDATA
/// @ingroup group_containerid
/// @{
/// @addtogroup VOLUMEDATA_VOLUMETOMESH
/// @ingroup group_containerid
/// @{
/// Settings for the volume to mesh command VOLUMETOMESH. @ref VOLUMECOMMANDTYPE
enum class VOLUMETOMESHSETTINGS
{
	NONE = 0,
	ISO = 1,				///< ::Float Iso value to extract the mesh at.
	ADAPTIVE = 2		///< ::Float Adaptivity value for curvature based mesh reduction.
} MAXON_ENUM_LIST(VOLUMETOMESHSETTINGS);
/// @}

/// @addtogroup VOLUMEDATA_MESHTOVOLUME
/// @ingroup group_containerid
/// @{
/// Settings for the mesh to volume command MESHTOVOLUME. @ref VOLUMECOMMANDTYPE
enum class MESHTOVOLUMESETTINGS
{
	NONE = 0,
	GRIDSIZE = 1,							///< ::Float Grid voxel cube size.
	BANDWIDTH_INTERIOR = 2,		///< ::Int32 Voxel Bandwidth amount around the mesh interior.
	BANDWIDTH_EXTERIOR = 3,		///< ::Int32 Voxel Bandwidth amount around the mesh exterior.
	USE_POINTS = 4,						///< ::Bool Use the vertices of the Mesh as particles for SDF construction.
	RADIUS = 5,								///< ::Float Radius for particle SDF construction if USE_POINTS is true.
	UNSIGNED_DISTANCE_FIELD = 6	///< ::Bool If true an unsigned distance field is created instead of a signed distance field.
} MAXON_ENUM_LIST(MESHTOVOLUMESETTINGS);
/// @}

/// @addtogroup VOLUMEDATA_PARTICLESTOVOLUME
/// @ingroup group_containerid
/// @{
/// Settings for the particle to volume command PARTICLESTOVOLUME. @ref VOLUMECOMMANDTYPE
enum class PARTICLESTOVOLUMESETTINGS
{
	NONE = 0,
	GRIDSIZE = 1,				///< ::Float Grid voxel cube size.
	BANDWIDTH = 2,			///< ::Int32 Voxel Bandwidth amount around a particle.
	RADIUS = 3,					///< ::Float Radius of the SDF around a particle.
	VELOCITY_SCALE = 4,	///< ::Float Velocity expansion scale.
	USE_PARTICLE_SIZE = 5, 	///< ::Bool If true it overrides the radius with the particle size.
	PARTICLEOFFSET = 6 ///< ::Matrix Extra transform for the particles applied before conversion.
} MAXON_ENUM_LIST(PARTICLESTOVOLUMESETTINGS);
/// @}

/// @addtogroup VOLUMEDATA_SPLINETOVOLUME
/// @ingroup group_containerid
/// @{
/// Settings for the spline to volume command SPLINETOVOLUME. @ref VOLUMECOMMANDTYPE
enum class SPLINETOVOLUMESETTINGS
{
	NONE = 0,
	GRIDSIZE = 1,				///< ::Float Grid voxel cube size.
	BANDWIDTH = 2,			///< ::Int32 Voxel Bandwidth amount around a Spline.
	RADIUS = 3,					///< ::Float Radius of the SDF around a Spline.
	DENSITY = 4,				///< ::Float Sampling density on the Spline.
	SCALESEGMENT = 5		///< ::Bool If true each spline segment will be scaled individually by the scalespline.
} MAXON_ENUM_LIST(SPLINETOVOLUMESETTINGS);
/// @}

/// @addtogroup VOLUMEDATA_FILTER
/// @ingroup group_containerid
/// @{
/// Settings for filter command FILTER. @ref VOLUMECOMMANDTYPE
enum class FILTERSETTINGS
{
	NONE = 0,
	FILTERTYPE = 1,			///< ::Int32 The used filter type.
	ITERATIONS = 2,			///< ::Int32 Amount of iterations that the filter is applied.
	RADIUS = 3,					///< ::Int32 Radius of the filter mask.
	OFFSET = 4,					///< ::Float Offset value for the offset filter.
	FALLOFF = 5,				///< ::Void Pointer to a falloff object BaseArray.
	REMAP_OLD_MIN = 6,	///< ::Float Old minimum value for linear value remapping.
	REMAP_OLD_MAX = 7,	///< ::Float Old maximum value for linear value remapping.
	REMAP_NEW_MIN = 8,	///< ::Float New minimum value for linear value remapping.
	REMAP_NEW_MAX = 9,	///< ::Float New maximum value for linear value remapping.
	STRENGTH = 10,			///< ::Float The strength of the filter.
	SPLINE = 11,				///< ::SplineData* Pointer to the spline for spline remapping.
	INVERTPOINT = 12		///< ::Float The value around wich the invert filter mirrors.
} MAXON_ENUM_LIST(FILTERSETTINGS);
/// @}

/// @addtogroup VOLUMEDATA_SDFFILTER
/// @ingroup group_containerid
/// @{
/// Settings for filter command SDFFILTER. @ref VOLUMECOMMANDTYPE
enum class SDFFILTERSETTINGS
{
	NONE = 0,
	FILTERTYPE = 1,				///< ::Int32 The used filter type.
	ITERATIONS = 2,				///< ::Int32 Amount of iterations that the filter is applied.
	STENCILWIDTH = 3,			///< ::Int32 Voxel distance of the filter stencil.
	FILTERACCURACY = 4,		///< ::Int32 Filter accuracy type.
	OFFSET = 5,						///< ::Float Offset value for the dilate, erode and offset filter.
	HALFWIDTH = 6,				///< ::Int32 Target halfwidth of the resize filter.
	FALLOFF = 7,					///< ::Void Pointer to a falloff object BaseArray.
	STRENGTH = 8					///< ::Float The Strength of the filter.
} MAXON_ENUM_LIST(SDFFILTERSETTINGS);
/// @}

/// @addtogroup VOLUMEDATA_VOLUMEBOOLE
/// @ingroup group_containerid
/// @{
/// Settings for boole command VOLUMEBOOLE. @ref VOLUMECOMMANDTYPE
enum class BOOLESETTINGS
{
	NONE = 0,
	BOOLETYPE = 1,				///< ::Int32 The Boole type (union, difference, intersection).
	SMOOTHRADIUS = 2			///< ::Float The radius for the boolean.
} MAXON_ENUM_LIST(BOOLESETTINGS);
/// @}

/// @addtogroup VOLUMEDATA_BOOLTYPE
/// @ingroup group_containerid
/// @{
/// Bool type for boole setting BOOLETYPE. @ref BOOLESETTINGS
enum class BOOLTYPE
{
	NONE = 0,
	UNION = 1,
	DIFF = 2,
	INTERSECT = 3,
} MAXON_ENUM_LIST(BOOLTYPE);
/// @}

/// @addtogroup VOLUMEDATA_VOLUMEBOOLE
/// @ingroup group_containerid
/// @{
/// Settings for mix command VOLUMEMIX. @ref VOLUMECOMMANDTYPE
enum class MIXSETTINGS
{
	NONE = 0,
	MIXTYPE = 1				///< ::Int32 The Mix type (Normal, Max, Mix, Add, Subtract, Multiply, Divide).
} MAXON_ENUM_LIST(MIXSETTINGS);
/// @}

/// @addtogroup VOLUMEDATA_MIXTYPE
/// @ingroup group_containerid
/// @{
/// Mix type for mix setting MIXTYPE. @ref MIXSETTINGS
enum class MIXTYPE
{
	NONE = 0,
	NORMAL = 1,
	MAX = 2,
	MIN = 3,
	ADD = 4,
	SUBTRACT = 5,
	MULTIPLY = 6,
	DIVIDE = 7
} MAXON_ENUM_LIST(MIXTYPE);
/// @}

/// @addtogroup VOLUMEDATA_SDFTOFOG
/// @ingroup group_containerid
/// @{
/// Settings for SDF to Fog convert command SDFTOFOG. @ref VOLUMECOMMANDTYPE
enum class SDFTOFOGSETTINGS
{
	NONE = 0,
	FALLOFFCUTOFF = 1				///< ::Float Distance for the falloff from the surface.
} MAXON_ENUM_LIST(SDFTOFOGSETTINGS);
/// @}

/// @addtogroup VOLUMEDATA_FOGTOSDF
/// @ingroup group_containerid
/// @{
/// Settings for Fog to SDF convert command SDFTOFOG. @ref VOLUMECOMMANDTYPE
enum class FOGTOSDFSETTINGS
{
	NONE = 0,
	ISO = 1				///< ::Float Iso value to extract the SDF at.
} MAXON_ENUM_LIST(FOGTOSDFSETTINGS);
/// @}

/// @addtogroup VOLUMEDATA_RESAMPLE
/// @ingroup group_containerid
/// @{
/// Settings for volume resample command RESAMPLE. @ref VOLUMECOMMANDTYPE
enum class RESAMPLESETTINGS
{
	NONE = 0,
	GRIDSIZE = 1,						///< ::Float New grid voxel cube size.
	INTERPOLATIONTYPE = 2		///< ::Int32 The Interpolation type (nearest, linear, quadratic).
} MAXON_ENUM_LIST(RESAMPLESETTINGS);
/// @}

/// @addtogroup VOLUMEDATA_RESAMPLE
/// @ingroup group_containerid
/// @{
/// Resample interpolation type for volume resample command setting INTERPOLATIONTYPE. @ref RESAMPLESETTINGS
enum class RESAMPLEINTERPOLATIONTYPE
{
	NONE = 0,
	NEAREST = 1,
	LINEAR = 2,
	QUADRATIC = 3
} MAXON_ENUM_LIST(RESAMPLEINTERPOLATIONTYPE);
/// @}

/// @addtogroup VOLUMEDATA_FIELDTOVOLUME
/// @ingroup group_containerid
/// @{
/// Settings for field conversion command FIELDTOVOLUME. @ref VOLUMECOMMANDTYPE
enum class FIELDTOVOLUMESETTINGS
{
	NONE = 0,
	BOUNDINGBOXMIN = 1,	///< ::Vector The lower left point of the boundingbox.
	BOUNDINGBOXMAX = 2,	///< ::Vector The upper right point of the boundingbox.
	GRIDSIZE = 3,				///< ::Float Grid voxel cube size.
} MAXON_ENUM_LIST(FIELDTOVOLUMESETTINGS);
/// @}

/// @addtogroup VOLUMEDATA_CREATESPHEREVOLUME
/// @ingroup group_containerid
/// @{
/// Settings for sphere volume creation command CREATESPHEREVOLUME. @ref VOLUMECOMMANDTYPE
enum class CREATESPHEREVOLUMESETTINGS
{
	NONE = 0,
	RADIUS = 1,					///< ::Float The radius of the sphere.
	POSITION = 2,				///< ::Vector The world position of the sphere.
	BANDWIDTH = 3,			///< ::Int32 Voxel Bandwidth amount around a sphere.
	GRIDSIZE = 4,				///< ::Float Grid voxel cube size.
} MAXON_ENUM_LIST(CREATESPHEREVOLUMESETTINGS);
/// @}

/// @addtogroup VOLUMEDATA_CREATEPLATONICVOLUME
/// @ingroup group_containerid
/// @{
/// Settings for platonic volume creation command CREATEPLATONICVOLUME. @ref VOLUMECOMMANDTYPE
enum class CREATEPLATONICVOLUMESETTINGS
{
	NONE = 0,
	FACES = 1,					///< ::Int32 The amount of faces of the platonic i.e. Tetrahedron = 4, Cube = 6, Octahedron = 8.
	SIZE = 2,						///< ::Float The size of the platonic.
	POSITION = 3,				///< ::Vector The world position of the platonic.
	BANDWIDTH = 4,			///< ::Int32 Voxel Bandwidth amount around the platonic.
	GRIDSIZE = 5,				///< ::Float Grid voxel cube size.
} MAXON_ENUM_LIST(CREATEPLATONICVOLUMESETTINGS);
/// @}

/// @}
/// @addtogroup MDATA_DELETECOMPONENTS
/// @ingroup group_containerid
/// @{
/// @since R20
#define MDATA_DELETECOMPONENTS_ALTERNATE_BEHAVIOR	2220			///< ::Bool Invert disconnected point preserve/delete preference behavior.
/// @}
/// @}

/// @addtogroup WPREF
/// @ingroup group_containerid
/// @{
/// World preferences.
#define WPREF_UNITS_BASIC				10000			///< ::Int32 Basic units.
#define WPREF_UNITS_TIME				10001			///< ::Int32 Time units.
#define WPREF_UNITS_AUTOCONVERT	10002			///< ::Bool Auto Convert Units.
#define WPREF_UNITS_USEUNITS		10003			///< ::Bool Use units.
#define WPREF_RATIO							10005			///< ::Float Monitor aspect ratio.
#define WPREF_CENTER						1002			///< ::Bool Create new objects in view center.
#define WPREF_TABLET						1005			///< ::Bool Private and to be deprecated.
#define WPREF_LINK_SELECTION		1009			///< ::Bool
#define WPREF_FULLANIMREDRAW		1010			///< ::Bool Full animation redraw.
#define WPREF_SAVE_LAYOUT				1014			///< ::Bool
#define WPREF_INSERTAT					1016			///< ::Int32 Insert object at.
#define WPREF_PASTEAT						1017			///< ::Int32 Paste object at.
#define WPREF_MAX_UNDOS					1018			///< ::Int32
#define WPREF_MAX_LAST					1019			///< ::Int32
#define WPREF_CAMERAROTATION		1020			///< ::Int32 Camera rotation mode: @enumerateEnum{WPREF_CAMERAROTATION}

/// @addtogroup WPREF_CAMERAROTATION
/// @ingroup group_enumeration
/// @{
#define WPREF_CAMERAROTATION_CENTER	1			///< Center.
#define WPREF_CAMERAROTATION_OBJECT	2			///< Object.
#define WPREF_CAMERAROTATION_CURSOR	3			///< Cursor.
#define WPREF_CAMERAROTATION_CAMERA	4			///< Camera.
#define WPREF_CAMERAROTATION_CUSTOM	5			///< Custom.
#define WPREF_CAMERAROTATION_CAMERA_2D	6		///< 2D Navigation (Image Plane)
/// @}

#define WPREF_DOLLYTOCURSOR	1021													// Int32
																	///< - <i>1</i> = Off.
																	///< - <i>2</i> = Orthographic views.
																	///< - <i>3</i> = All views.
#define WPREF_SYNCVIEWPORTS	1022													// BOOL 440000085 // BOOL
#define WPREF_SCRIPTWORDWRAP				1023	// Bool
#define WPREF_SAVEDLOGGER		1058544	///< ::String of the active Logger
#define WPREF_CONSOLE_WIDTH		1059398	///< ::BaseContainer from GeDialog::GroupWeightsSave for the Console width.

#define WPREF_OPENGL_PERSPECT						1024			///< ::Bool
#define WPREF_OPENGL_TEXTURE_FILTERING	1025			///< ::Int32 OpenGL texture filtering: @enumerateEnum{WPREF_OPENGL_TEXTURE_FILTERING}
/// @addtogroup WPREF_OPENGL_TEXTURE_FILTERING
/// @ingroup group_enumeration
/// @{
#define WPREF_OPENGL_TEXTURE_FILTERING_NEAREST				0			///< Nearest texture interpolation.
#define WPREF_OPENGL_TEXTURE_FILTERING_LINEAR					1			///< Linear texture interpolation.
#define WPREF_OPENGL_TEXTURE_FILTERING_LINEAR_MIPMAP	2			///< Linear mipmap texture interpolation.
/// @}
#define WPREF_USE_TEXTURES	1026			///< ::Bool
#define WPREF_NAV_POI_MODE	1027			///< ::Int32 Point of Interest (POI) mode: @enumerateEnum{WPREF_NAV_POI}
/// @addtogroup WPREF_NAV_POI
/// @ingroup group_enumeration
/// @{
#define WPREF_NAV_POI_CENTER	1
#define WPREF_NAV_POI_OBJECT	2
#define WPREF_NAV_POI_CAMERA	3
#define WPREF_NAV_POI_CAMERA_2D	4 // Camera2dNavMode
/// @}

#define WPREF_NAV_CURSOR_MODE				1028			///< ::Int32 Cursor Placement mode: @enumerateEnum{WPREF_NAV_CURSOR}
#define WPREF_NEWFEATUREHIGHLIGHT_FADE				1029		///< ::Bool Enable fading of highlighted color when command is used. @since R19
/// @addtogroup WPREF_NAV_CURSOR
/// @ingroup group_enumeration
/// @{
#define WPREF_NAV_CURSOR_OFF				1			///< Off.
#define WPREF_NAV_CURSOR_SELECTION	2			///< Selected.
#define WPREF_NAV_CURSOR_CHILDREN		3			///< Selected children.
#define WPREF_NAV_CURSOR_ALL				4			///< All.
/// @}

#define WPREF_TABLET_HIRES										1030			///< ::Bool
#define WPREF_REVERSE_ORBIT										1031			///< ::Bool Reverse orbit.
#define WPREF_NAV_CURSOR_DEEP									1032			///< ::Bool Deep cursor placement.
#define WPREF_NAV_LOCK_POI										1033			///< ::Bool Lock POI for dolly.
#define WPREF_NAV_TRACKBALL										1036			///< ::Bool: Trackball camera rotation.
#define WPREF_OPENGL_HIGHENDSHADING						1038			///< ::Bool
#define WPREF_NAV_VIEW_TRANSITION							1039			///< ::Bool Enable the smooth view transition in the viewport.
#define WPREF_REALTIMEMANAGER									1042			///< ::Bool
#define WPREF_MAX_BACKUP											1043			///< ::Int32
#define WPREF_CENTERAXIS											1044			///< ::Bool
#define WPREF_MATPREVIEW_DEFAULTSIZE					1048			///< ::Int32
#define WPREF_DESCRIPTIONLIMIT								1049			///< ::Int32
#define WPREF_MATPREVIEW_DEFAULTOBJECT_MAT		1050			///< ::Int32
#define WPREF_MATPREVIEW_DEFAULTUSERSCENE_MAT	1051			///< String
#define WPREF_MATPREVIEW_DEFAULTOBJECT_SHD		1052			///< ::Int32
#define WPREF_MATPREVIEW_DEFAULTUSERSCENE_SHD	1053			///< String
#define WPREF_MATPREVIEW_AUTO_UPDATE					1054			///< ::Bool
#define WPREF_MATPREVIEW_REDRAW_TIME					1055			///< ::Int32: Maximum redraw time in milliseconds.
#define WPREF_MATPREVIEW_FPS									1056			///< ::Int32
#define WPREF_MATPREVIEW_LENGTH								1057			///< ::Float
#define WPREF_MATPREVIEW_MAX_MEM							1058			///< ::Int32
#define WPREF_DESCRIPTIONLIMIT_NODES					1059			///< ::Int32
#define WPREF_SUBPIXELLIMIT										1062			///< ::Int32
#define WPREF_OPENGL_DUALPLANES_HIGHLIGHT			1066			///< ::Bool: Allow dual plane highlighting in OpenGL mode (GL extension).
#define WPREF_ALLOWBUGREPORTS									1068			///< ::Bool Allow bug reports.
#define WPREF_OPENGL_MAX_TRANS_DEPTH					1071			///< ::Int32
#define WPREF_OPENGL_MAX_LIGHTS								1072			///< ::Int32
#define WPREF_OPENGL_MAX_SHADOWS							1073			///< ::Int32
#define WPREF_OPENGL_ANTIALIAS								1084			///< ::Int32 OpenGL anti-aliasing quality.
#define WPREF_OPENGL_USE_SHADER_CACHE					1089			///< ::Bool Use shader cache.
#define WPREF_VIEW_DISLAYCOLORPROFILE					1086			///< ColorProfile Display Color Profile.
#define WPREF_OPENGL_VIEWPORT_DITHERING				1091			///< ::Bool Enable Dithering in Viewport. @since R17.032
#define WPREF_MATMANAGER_DEFAULT_MATERIAL			1093			///< ::Int32 The default material created with "New Default Material" command or double click or Ctrl+N in Material Manager. @since R21
	#define WPREF_MATMANAGER_DEFAULT_MATERIAL_AUTO		1059942		///< Automatic default material based on active renderer. @since 2023.100
#define WPREF_OPENGL_UVEDITOR_ANTIALIAS				1094			///< ::Bool Enable anti-aliasing in texture viewport.
#define WPREF_VIEWPORT_ENABLE_HDR							1095			///< ::Bool Enable HDR output of the viewport. @since R25
#define WPREF_OPENGL_PREVIEWSIZE			        1096			///< ::Int32 The default texture size of materials in the viewport. This can be overridden in the "Viewport" tab of every material individually. @since R26
#define WPREF_MATMANAGER_ALWAYS_OPEN_NODE_EDITOR		1097			///< ::Bool Always open node-based materials (e.g. on double-click) on Node Editor instead of on Material Editor. @since R26
#define WPREF_OPENGL_SKY_PREVIEWSIZE			    1098			///< ::Int32 The default texture size of the viewport sky. Usually, this should be higher-res than for other materials.

#define WPREF_MOVEACCELERATION		1081			///< ::Float
#define WPREF_SCALEACCELERATION		1082			///< ::Float
#define WPREF_ROTATEACCELERATION	1083			///< ::Float

#define WPREF_COLOR_RGBRANGE	1102			///< ::Int32 RGB color range: @enumerateEnum{COLORSYSTEM_RANGE}

#define WPREF_COLOR_MODE_COMPACT								1124		///< ::Int32 Compact Mode. @since R18
#define WPREF_COLOR_MODE_RGB										1110		///< ::Bool RGB Sliders Mode. @since R17
#define WPREF_COLOR_MODE_HEX										1111		///< ::Bool Hexadecimal Color Field. @since R17.032
#define WPREF_COLOR_MODE_RGB_OLD_SLIDERS 				1112  	///< ::Bool Use Old-Style RGB Sliders. @since R17.032
#define WPREF_COLOR_MODE_HSV										1113		///< ::Bool HSV sliders Mode. @since R17.032
#define WPREF_COLOR_MODE_KELVIN									1114		///< ::Bool Kelvin Color Temperature Mode. @since R17.032
#define WPREF_COLOR_MODE_MIXER									1115		///< ::Bool Color Mixer Mode. @since R17.032
#define WPREF_COLOR_MODE_SWATCHES								1116		///< ::Bool Color Swatches Mode. @since R17.032
#define WPREF_COLOR_MODE_SWATCHES_SHOWNAMES 		1117		///< ::Bool Show Swatches Group Names. @since R17.032
#define WPREF_COLOR_MODE_SWATCHES_SWATCH_SIZE 	1118		///< ::Int32 Swatches Size Mode. See @ref COLORSYSTEM_SIZE. @since R17
#define WPREF_COLOR_MODE_SPECIAL								1119		///< ::Int32 Special Color Mode (these are exclusive each other). @since R17
#define COLORSYSTEM_MODE_SPECIAL_DISABLED				0				///< Special Mode Disabled. @since R17
#define COLORSYSTEM_MODE_SPECIAL_COLORWHEEL			1				///< Color Wheel Mode. @since R17
#define COLORSYSTEM_MODE_SPECIAL_SPECTRUM				2				///< Color Spectrum Mode. @since R17
#define COLORSYSTEM_MODE_SPECIAL_PICTURE				3				///< Color from Picture Mode. @since R17
#define WPREF_COLOR_MODE_WHEEL_SIZE							1120		///< ::Int32 Color Wheel Size. See @ref COLORSYSTEM_SIZE. @since R17
#define WPREF_COLOR_MODE_WHEEL_SWATCH_SIZE			1121		///< ::Int32 Color Wheel Preview Swatches Size. See @ref COLORSYSTEM_SIZE. @since R17
#define WPREF_COLOR_MODE_SPECTRUM_SIZE					1122		///< ::Int32 Spectrum Size. See @ref COLORSYSTEM_SIZE. @since R17
#define WPREF_COLOR_MODE_PICTURE_SWATCH_SIZE		1123		///< ::Int32 Picture Mode Swatches Size. See @ref COLORSYSTEM_SIZE. @since R17
#define WPREF_COLOR_MODE_SWATCHES_GLOBAL_DATA				1127		///< BaseContainer Global swatches data. @markPrivate @since R18
#define WPREF_COLOR_MODE_SWATCHES_REMEMBER_GLOBAL		1128		///< @markDeprecated
#define WPREF_COLOR_REMEMBER_LAST_LAYOUT						1129		///< ::Bool If @formatConstant{true} @C4D remembers the last layout for new color choosers, but it will keep the manually adjusted layouts for old color choosers. @since R18
#define WPREF_GRADIENT_SIZE													1130		///< ::Int32 Gradient size. See @ref WPREF_GRADIENT_SIZE. @since R20
#define WPREF_DISCONNECTED_POINTS_ON_DELETE					1131		///< ::Int32 Remove disconnected points on delete if 0, or keep them if 1
#define WPREF_GRADIENT_SELECTION_HANDLES						1132		///< ::Bool Use Range Selection Handles. @since R20
#define WPREF_COLOR_MODE_ALPHA											1133		///< ::Bool Alpha slider Color Mode. @since R20
#define WPREF_ALPHA_GRID_COLOR											1134		///< ::Int32 Alpha checkerboard pattern color mode. See @ref WPREF_ALPHA_GRID_COLOR. @since R20
#define WPREF_MATPREVIEW_NODEPREVIEW								1135		///< ::Bool Show Preview in Nodes. @since R20
#define WPREF_MATPREVIEW_PREVIEWNAME								1136		///< ::Bool Show the preview name. @since R20
#define WPREF_MATPREVIEW_NODE_DEFAULTSIZE						1137		///< ::Int32
#define WPREF_MATPREVIEW_NODE_DEFAULTOBJECT_MAT			1138		///< ::Int32
#define WPREF_COLOR_MODE_LINEAR											1139		///< ::Bool Linear Numeric Values for color choosers. @since R20

#define WPREF_HIDEFIELDGRAPH												440000331		///< ::Bool hide the field remapper graph @since R20
#define WPREF_SIMPLEFIELDGUI												440000332		///< ::Bool use the simple field gui by default @since R20

/// @addtogroup WPREF_HIDEFIELDGRAPH
/// @ingroup group_enumeration
/// @{
#define WPREF_HIDEFIELDGRAPH_OFF										0				///< Field Remapping Graphs Disabled @since R20
#define WPREF_HIDEFIELDGRAPH_ON											1				///< Field Remapping Graphs Enabled @since R20
#define WPREF_HIDEFIELDGRAPH_INFIELDS								2				///< Field Remapping Graphs Disabled when shown within a FieldList UI @since R20
/// @}

#define WPREF_SHOWFULLMATERIALUI										310006007 ///< @markPrivate
#define WPREF_SUPPRESSPREVIEWS											310006008 ///< @markPrivate

/// @addtogroup COLORSYSTEM_RANGE
/// @ingroup group_enumeration
/// @{
#define COLORSYSTEM_RANGE_PERCENT	0			///< @em 0\%-@em 100\%
#define COLORSYSTEM_RANGE_255			1			///< @em 0-@em 255
#define COLORSYSTEM_RANGE_65535		2			///< @em 0-@em 65535
#define COLORSYSTEM_RANGE_1				3			///< @em 0-@em 1 @since R26
/// @}

/// @addtogroup COLORSYSTEM_SIZE
/// @ingroup group_enumeration
/// @{
/// @since R17.032
#define COLORSYSTEM_SIZE_SMALL		0			///< Small.
#define COLORSYSTEM_SIZE_MEDIUM		1			///< Medium.
#define COLORSYSTEM_SIZE_LARGE		2			///< Large.
/// @}

/// @addtogroup WPREF_GRADIENT_SIZE
/// @ingroup group_enumeration
/// @{
/// @since R20
#define WPREF_GRADIENT_SIZE_SMALL 		0
#define WPREF_GRADIENT_SIZE_MEDIUM		1
#define WPREF_GRADIENT_SIZE_LARGE			2
/// @}

/// @addtogroup WPREF_ALPHA_GRID_COLOR
/// @ingroup group_enumeration
/// @{
/// @since R20
#define WPREF_ALPHA_GRID_COLOR_LIGHT		0
#define WPREF_ALPHA_GRID_COLOR_MEDIUM		1
#define WPREF_ALPHA_GRID_COLOR_DARK			2
/// @}

#define WPREF_AUTOSAVE_ENABLE						1400			///< ::Bool
#define WPREF_AUTOSAVE_MIN							1401			///< ::Int32
#define WPREF_AUTOSAVE_LIMIT_TO					1402			///< ::Bool
#define WPREF_AUTOSAVE_LIMIT_NUM				1403			///< ::Int32
#define WPREF_AUTOSAVE_DEST							1405			///< ::Int32
/// @addtogroup WPREF_AUTOSAVE_DEST
/// @ingroup group_enumeration
/// @{
#define WPREF_AUTOSAVE_DEST_BACKUPDIR		0
#define WPREF_AUTOSAVE_DEST_USERDIR			1
#define WPREF_AUTOSAVE_DEST_STARTUPDIR	2
/// @}
#define WPREF_AUTOSAVE_DEST_PATH				1406			///< Filename
#define WPREF_COMMANDER_AT_CURSOR				1407			///< ::Bool
#define WPREF_REALTIMEMATERIALS					1408			///< ::Bool @since R19
#define WPREF_WATCHFOLDER_AUTOMOUNT_SEARCHPATHS 1410 ///< ::Bool True if search paths should be mounted automatically as watch folders
#define WPREF_WATCHFOLDER_AUTOMOUNT_DOCUMENTS		1411 ///< ::Bool True if project relative watch folder paths should be mounted automatically as watch folders

#define WPREF_PLUGINS											30006			///< BaseContainer
#define WPREF_CPUCOUNT										30010			///< ::Int32 Number of CPUs.
#define WPREF_LOGFILE											30011			///< ::Bool Create render log file.
#define WPREF_CONSOLEGI										30013			///< ::Bool Show Global Illumination information in Console.
#define WPREF_CPUCUSTOM										30014			///< ::Bool Custom number of render threads.
#define WPREF_RENDERQUEUELOG							30015			///< ::Bool %Render queue log.
#define WPREF_RENDERQUEUE_AUTORENAME			30016			///< ::Bool Auto rename files in Render Queue. @since R21

#define WPREF_BUBBLEHELP2									21002			///< ::Bool
#define WPREF_THREADPRIORITY							21003			///< ::Bool
#define WPREF_MENUICON										21004			///< ::Bool
#define WPREF_MENUSHORTCUT								21005			///< ::Bool
#define WPREF_INACTIVEBORDER							21006			///< ::Bool
#define WPREF_ACTIVEBORDER								21007			///< ::Bool
#define WPREF_FONT_STANDARD								21050			///< BaseContainer
#define WPREF_FONT_MONO										21051			///< BaseContainer
#define WPREF_MAC_CTRLCLICK_EMULATES_RMB	21062			///< ::Bool CTRL click emulates right mouse button. OS X only.
#define WPREF_MAC_MENUBAR									21063			///< ::Bool
#define WPREF_UV_RELAX_DATA								21065			///< BaseContainer
#define WPREF_UV_OPTIMAL_MAPPING_DATA			21066			///< BaseContainer
#define WPREF_UV_PROJECTION_DATA					21067			///< BaseContainer
#define WPREF_UV_TAB_SEL									21068			///< BaseContainer
#define WPREF_UV_TRANSFORM_DATA						21069			///< BaseContainer
#define WPREF_LINUX_BROWSERPATH						21070			///< Filename
#define WPREF_MOUSEOVER_SHORTCUT					21072			///< ::Bool
#define WPREF_ONLINEHELP_PATH							21075			///< Filename
#define WPREF_ONLINEHELP_URL							21076			///< String
#define WPREF_LINUX_IMAGEEDITPATH					21077			///< Filename
#define WPREF_LOCKINTERFACE								21078			///< ::Bool Lock the interface layout.
#define WPREF_TOOLCURSOR_BASIC						21079			///< ::Bool Cursor icon for basic tools.
#define WPREF_TOOLCURSOR_ADV							21080			///< ::Bool Cursor icon for advanced tools.
#define WPREF_LOWERPROCESSPRIORITY				21081			///< ::Bool
#define WPREF_HIGHLIGHTNEWFEATURES				21082			///< ::Int
#define WPREF_FONT_BIG										21083			///< BaseContainer @markPrivate @since R20
#define DEPRECATED_WPREF_MOUSE_TOUCHDEVICES	21084			///< ::Bool @since R20
#define WPREF_FILE_ASSETS_LINK						21085			///< ::Int32 Defines the action when assets (e.g. textures) added: @enumerateEnum{WPREF_FILE_ASSETS_LINK} @since R21
#define WPREF_IMEXPORT_SHOW_IMPORT_DLG		21086			///< ::Bool @since R21
#define WPREF_IMEXPORT_SHOW_EXPORT_DLG		21087			///< ::Bool @since R21
#define WPREF_IMEXPORT_MERGE_ON_DD				21088			///< ::Bool @since R21
#define WPREF_UV_PACKING_DATA							21089			///< BaseContainer
#define WPREF_MOUSE_TOUCHSUPPORT					21090			///< ::Int32 @since R22
	#define WPREF_MOUSE_TS_AUTOMATIC							0		///< Automatic Detection
	#define WPREF_MOUSE_TS_TOUCH									1		///< Touch Devices
	#define WPREF_MOUSE_TS_WHEEL									2		///< Wheel Mouse
#define WPREF_SHOWUNDOBUTTONS							21091			///< ::Bool
#define WPREF_IMEXPORT_NODESPACE					21092			///< Int32 @since 2024

#define WPREF_MODELING_MANAGER_TABS				22000			///< BaseContainer @markPrivate @since R21
#define WPREF_MIGRATION_DIALOG_DATA				22010			///< BaseContainer @markPrivate @since R21
#define WPREF_MIGRATION_DIALOG_COMMANDS				1000	///< Bool @markPrivate @since R21
#define WPREF_MIGRATION_DIALOG_PRIMITIVES			1001	///< Bool @markPrivate @since R21
#define WPREF_MIGRATION_DIALOG_DEBUG					1002	///< Bool @markPrivate @since R21
#define WPREF_MIGRATION_DIALOG_DEBUG_SYNC			1003	///< Bool @markPrivate @since R21
#define WPREF_MIGRATION_DIALOG_DEBUG_MESHMAPS	1004	///< Bool @markPrivate @since R21
#define WPREF_MIGRATION_DIALOG_DEBUG_MOPO			1005	///< Bool @markPrivate @since R21
#define WPREF_PROFILER_DIALOG_DATA				22020			///< BaseContainer @markPrivate @since R21
#define WPREF_PROFILER_ENABLE									1000	///< Bool @markPrivate @since R21
#define WPREF_PROFILER_DEBUG_OUTPUT						1001	///< Bool @markPrivate @since R21
#define WPREF_PROFILER_CAPTURE_MODE						1002	///< Bool @markPrivate @since R21
#define WPREF_PROFILER_CAPTURE_MODE_ALL						1	///< Bool @markPrivate @since R21
#define WPREF_PROFILER_CAPTURE_MODE_METHODS_ONLY	2	///< Bool @markPrivate @since R21
#define WPREF_PROFILER_TIME_FILTER						1003	///< Bool @markPrivate @since R21
#define WPREF_UNITTESTS_DIALOG_DATA				22030			///< BaseContainer @markPrivate @since R21
#define WPREF_ONLINEHELP									23000			///< Bool @markPrivate @since R21
#define WPREF_EXTERNALHELP								23001			///< Bool @markPrivate @since R21

/// @addtogroup WPREF_FILE_ASSETS_LINK
/// @ingroup group_enumeration
/// @{
#define WPREF_FILE_ASSETS_LINK_RELATIVE				0			///< Copy Assets to Project Location.
#define WPREF_FILE_ASSETS_LINK_ABSOLUTE				1			///< Create Absolute Path.
#define WPREF_FILE_ASSETS_LINK_ASK						2			///< Always Ask.
/// @}

#define WPREF_PV_RENDER_VIEW	430000690			///< ::Int32 The index id of the Picture Viewer dialog that receives render output.
#define WPREF_PV_RECENT				465001804			///< For recent files in Picture Viewer.

#define WPREF_COMMUNICATION_LIVELINK_ENABLED	465001648				///< ::Bool If the Livelink to AE should be enabled or disabled when Cinema is started. @since R17.048
#define WPREF_COMMUNICATION_LIVELINK_PORT			465001649				///< ::Int32 The port used by the Livelink connection. @since R17.048

#define WPREF_COMMUNICATION_QUICKSTART_DIALOG	465001650		///< ::Bool Toggles the Quick Start Dialog's auto-open behaviour
#define WPREF_QUICKSTART_PREV_FEATURE_HIGHLIGHTING 465002000 ///< ::Int32 Stores the previous feature highlight setting. @markPrivate @since R24
#define WPREF_QUICKSTART_LAST_UPDATE_VERSION 465003000 ///< ::Int32 Stores the last update version number seen by the quickstartdialog. @markPrivate @since R24

#define WPREF_OUTDATED_GPU_WARNING_DATA	1054753 ///< ::BaseContainer @markPrivate @since R22

#define WPREF_NODE_EDITOR_GRID					1055258	///< ::Bool Shows node editor grid. @since R23
#define WPREF_NODE_EDITOR_NAVIGATOR			1055259	///< ::Bool Shows node editor navigator. @since R23
// #define WPREF_NODE_EDITOR_ERRORS				1055261	///< ::Bool Shows errors in the node editor. @since R23
#define WPREF_NODE_EDITOR_SNAP_GRID			1055262	///< ::Bool Snaps to node editor grid. @since R23
#define WPREF_NODE_EDITOR_INFO    			1055263	///< ::Bool Shows node editor info area. @since R24
#define WPREF_NODE_EDITOR_IDS      			1055264	///< ::Bool Shows node ids in info area. @since R26.1
#define WPREF_NODE_EDITOR_HEATMAP_FLAGS		1055265	///< ::Int32 Node editor heat map flags. @since 2023.2
#define WPREF_NODE_EDITOR_HEATMAP_GRADIENT	1055266	///< ::Gradient Gradient Node editor gradient. @since 2023.2
#define WPREF_NODE_EDITOR_HEATMAP_NOVALUE_COLOR 1055267 ///< ::Color Gradient Node editor gradient no value color. @since 2023.2

#define WPREF_BROWSER_SHOW_UNAVAILABLE	1056517 ///< ::Bool Shows unavailable assets in Asset Manager. @since R24

#define WPREF_COMMANDER_SETTINGS				1060373 ///< ::BaseContainer Contains auto-saved commander settings like zoom level @markPrivate @since R2023.2

/// @}

/// @addtogroup PREFSDIALOG_ID
/// @ingroup group_enumeration
/// @{
#define		PVPREFSDIALOG_ID			465001700			///< Picture Viewer preferences dialog ID.
#define		SCULPTPREFSDIALOG_ID	1027830				///< Sculpt preferences dialog ID.
#define		TLPREFSDIALOG_ID			465001501			///< Timeline preferences dialog ID.
#define		PHPREFSDIALOG_ID			1031908				///< Phoenix preferences dialog ID.
#define		GPURPREFSDIALOG_ID		1038912				///< GPU Renderer preferences dialog ID. @since R19
/// @}

/// @addtogroup WPREFS_TLKEY
/// @ingroup group_enumeration
/// @{
/// Timeline/keyframe preferences IDs
/// @todo Add information for undocumented IDs.
enum
{
	WPREFS_HIGHLIGHT = 1000,
	WPREFS_HIGHLIGHTCURVE,
	WPREFS_CURSORINDICATOR,
	WPREFS_MINIMUM_OLD,
	WPREFS_MINIMUMWIDTH,
	WPREFS_SHOWLAYERCOL,
	WPREFS_TRACKCOLOR,
	WPREFS_TRACKCOLNO,
	WPREFS_TRACKCOLPRS,
	WPREFS_TRACKCOLORG,
	WPREFS_SHOWTRACKSTARTEND,
	WPREFS_SUMMARY,
	WPREFS_HLEAUTOVALUE,
	WPREFS_INTERACTIVEUPDATE,
	WPREFS_CLIPTRANSITIONIME,
	WPREFS_KEYSDOPESHEET,
	WPREFS_KEYSYMBOLS,
	WPREFS_SHOWBRANCHES,
	WPREFS_SHOWVECTRACK,
	WPREFS_KEYFRAMEDOTS,								///< ::Bool Legacy keyframe dots.
	WPREFS_DOTSKILLTRACKS,							///< ::Bool Keyframe dots kill tracks with no keyframes on them.
	WPREFS_LINKKEYFCSELECTION,					///< ::Bool Link Keyframe and FCurve selection together. @since R17.032
	WPREFS_LINKOMSELECTONLY,						///< ::Bool Only display the actual selected object and not the tags etc. when Link Timeline/Object Manager is selected. @since R17.032
	//WPREFS_GLOBALSELECTION,						// Bool One global Timeline selection.
	WPREFS_LINKOMSELECTONLYBUTTAGS,			///< ::Bool Only display the linked objects but also the tags. @since R17.032
	WPREFS_FCLISTVIEW,									///< ::Bool FCurve mode only: list view instead of normal hierarchy. @since R17.032
	WPREFS_FCLISTVIEW_HIERARCHICAL,			///< ::Bool FCurve mode only: hierarchical list view instead of normal hierarchy. @since R17.032
};
/// @}


/// @addtogroup WPREFS_PV
/// @ingroup group_enumeration
/// @{
/// Picture Viewer preferences IDs.
enum
{
	WPREFS_PVMEMORY = 1000,			///< Memory (MB).
	WPREFS_PVDRAWBUCKETS,				///< Draw buckets.
	WPREFS_PVHDMEM,							///< Hard disk memory (MB).
	WPREFS_PVHDFOLDER,					///< Cache Path.
	WPREFS_PVHDUNLIMIT,					///< Unlimited.
};
/// @}

/// @addtogroup WPREFS_SCULPT
/// @ingroup group_enumeration
/// @{
/// Sculpt preferences IDs.
enum
{
	WPREFS_SCULPTMEMORY = 1000,			///< Maximum amount of memory (MB) that a sculpt object should use.
};
/// @}

/// @addtogroup WPREFS_PH
/// @ingroup group_enumeration
/// @{
/// Phoenix preferences IDs
enum
{
	WPREFS_PHMAXCACHEMEM = 1000,
	WPREFS_PHSYSRESERVEMEM,
};
/// @}

/// @addtogroup WPREF_NET
/// @ingroup group_enumeration
/// @{
/// Team Render/NET preferences IDs.
enum
{
	WPREF_NET_NAME = 1000,
	WPREF_NET_SHARE,
	WPREF_NET_THREADCUSTOM,
	WPREF_NET_RENDERTHREADS,
	WPREF_NET_SECURITYTOKEN, // String (saved in the external TR prefs file)
	WPREF_NET_ALLOWRESTARTOFC4D,
	WPREF_NET_SERVICEPORTNUMBER, // Int32 (saved in the external TR prefs file)
	WPREF_NET_SERVICEREPOSITORYPATH,
	WPREF_NET_USEBONJOUR,
	WPREF_NET_USEENCRYPTION,
	WPREF_NET_HANDLEWARNINGASERROR,
	WPREF_NET_ABORTRENDERINGONCLIENTERROR,
	WPREF_NET_PEERTOPEERASSETDISTRIBUTION,
	WPREF_NET_REQUESTONDEMAND,
	WPREF_NET_EXCLUDECLIENTONLOADINGERROR,
	WPREF_NET_RENDERINGTIMEOUT,
	WPREF_NET_ENABLETEAMRENDER,
	WPREF_NET_WEBSERVERPORT,

	// Stored in preferences but not visible
	WPREF_NET_SHOWBUCKETMACHINECOLOR,
	WPREF_NET_SHOWNAME,
	WPREF_NET_SHOWICON,
	WPREF_NET_SHOWINFO,
	WPREF_NET_SHOWCHECKBOX,
	WPREF_NET_SHOWADDRESS,
	WPREF_NET_MACHINEICONSIZE,

	WPREF_NET_ENABLERENDERINGTIMEOUT,
	WPREF_NET_FETCHASSETSALWAYSFROMSERVER,

	WPREF_NET_ASSETCHUNKSIZE,
	WPREF_NET_WAKEONLANFOROFFLINEMACHINES,
	WPREF_NET_KEEPB3DFILESAFTERASSEMBLING,
	WPREF_NET_USERMANAGEMENTENABLED,												///< @since R17.032
	WPREF_NET_DOWNLOADASSETINPARTS,													///< @since R17.032
	WPREF_NET_STOPJOBONSWAPPINGENABLED,											///< @since R17.048
	WPREF_NET_STOPJOBONSWAPPINGAUTO,												///< @since R17.048
	WPREF_NET_STOPJOBONSWAPPINGVALUE,												///< @since R17.048
	WPREF_NET_RESTARTJOBSAFTERUNEXPECTEDSERVERTERMINATION,	///< @since R18
	WPREF_NET_USEDISCOVERY																	///< @since R19
};
/// @}

/// @addtogroup WPREF_TAKE Take System Preferences IDs
/// @ingroup group_containerid
/// @{
/// @since R17.032
enum
{
	WPREF_TAKE_BASIC_GROUP = 1000,
	WPREF_TAKE_MAIN_AUTOTAKE,
	WPREF_TAKE_MANAGER_SHOWFILTER,
	WPREF_TAKE_MANAGER_SHOWSHOWSEARCH,
	WPREF_TAKE_MANAGER_TREEMODE,
	WPREF_TAKE_DEFAULT_FILETR_OBJ,
	WPREF_TAKE_DEFAULT_FILETR_TAG,
	WPREF_TAKE_DEFAULT_FILETR_MAT,
	WPREF_TAKE_DEFAULT_FILETR_SHD,
	WPREF_TAKE_DEFAULT_FILETR_LAY,
	WPREF_TAKE_DEFAULT_FILETR_OTH,
	WPREF_TAKE_DEFAULT_FILETR_VIS,
	WPREF_TAKE_DEFAULT_FILETR_TRN,
	WPREF_TAKE_DEFAULT_FILETR_PRM,
	WPREF_TAKE_DEFAULT_FILETR_CAM,
	WPREF_TAKE_DEFAULT_FILETR_RS,
};
/// @}

/// @addtogroup MOUSE
/// @ingroup group_enumeration
/// @{
/// Mouse cursors.
static const Int32 MOUSE_HIDE = 0;								///< Hide cursor.
static const Int32 MOUSE_SHOW = 1;								///< Show cursor.
static const Int32 MOUSE_NORMAL = 2;							///< Normal cursor.
static const Int32 MOUSE_BUSY = 3;								///< Busy cursor.
static const Int32 MOUSE_CROSS = 4;								///< Cross cursor.
static const Int32 MOUSE_QUESTION = 5;						///< Question cursor.
static const Int32 MOUSE_ZOOM_IN = 6;							///< Zoom in cursor.
static const Int32 MOUSE_ZOOM_OUT = 7;						///< Zoom out cursor.
static const Int32 MOUSE_FORBIDDEN = 8;						///< Forbidden cursor.
static const Int32 MOUSE_DELETE = 9;							///< Delete cursor.
static const Int32 MOUSE_COPY = 10;								///< Copy cursor.
static const Int32 MOUSE_INSERTCOPY = 11;					///< Insert copy cursor.
static const Int32 MOUSE_INSERTCOPYDOWN = 12;			///< Insert copy down cursor.
static const Int32 MOUSE_MOVE = 13;								///< Move cursor.
static const Int32 MOUSE_INSERTMOVE = 14;					///< Insert move cursor.
static const Int32 MOUSE_INSERTMOVEDOWN = 15;			///< Insert move down cursor.
static const Int32 MOUSE_ARROW_H = 16;						///< Horizontal arrow cursor.
static const Int32 MOUSE_ARROW_V = 17;						///< Vertical arrow cursor.
static const Int32 MOUSE_ARROW_HV = 18;						///< Horizontal and vertical arrow cursor.
static const Int32 MOUSE_POINT_HAND = 19;					///< Point hand cursor.
static const Int32 MOUSE_MOVE_HAND = 20;					///< Move hand cursor.
static const Int32 MOUSE_IBEAM = 21;							///< I-beam cursor.
static const Int32 MOUSE_SELECT_LIVE = 22;				///< Live selection cursor.
static const Int32 MOUSE_SELECT_FREE = 23;				///< Free selection cursor.
static const Int32 MOUSE_SELECT_RECT = 24;				///< Rectangle selection cursor.
static const Int32 MOUSE_SELECT_POLY = 25;				///< Polygon selection cursor.
static const Int32 MOUSE_SPLINETOOLS = 26;				///< Spline tools cursor.
static const Int32 MOUSE_EXTRUDE = 27;						///< Extrude cursor.
static const Int32 MOUSE_NORMALMOVE = 28;					///< Normal move cursor.
static const Int32 MOUSE_ADDPOINTS = 29;					///< Add points cursor.
static const Int32 MOUSE_ADDPOLYGONS = 30;				///< Add polygons cursor.
static const Int32 MOUSE_BRIDGE = 31;							///< Bridge cursor.
static const Int32 MOUSE_MIRROR = 32;							///< Mirror cursor.
static const Int32 MOUSE_PAINTMOVE = 33;					///< Paint move cursor.
static const Int32 MOUSE_PAINTSELECTRECT = 34;		///< Paint select rectangle cursor.
static const Int32 MOUSE_PAINTSELECTCIRCLE = 35;	///< Paint select circle cursor.
static const Int32 MOUSE_PAINTSELECTPOLY = 36;		///< Paint select polygon cursor.
static const Int32 MOUSE_PAINTSELECTFREE = 37;		///< Paint select free cursor.
static const Int32 MOUSE_PAINTMAGICWAND = 38;			///< Paint magic wand cursor.
static const Int32 MOUSE_PAINTCOLORRANGE = 39;		///< Paint color range cursor.
static const Int32 MOUSE_PAINTFILL = 40;					///< Paint fill cursor.
static const Int32 MOUSE_PAINTPICK = 41;					///< Paint pick cursor.
static const Int32 MOUSE_PAINTBRUSH = 42;					///< Paint brush cursor.
static const Int32 MOUSE_PAINTCLONE = 43;					///< Paint clone cursor.
static const Int32 MOUSE_PAINTTEXT = 44;					///< Paint text cursor.
static const Int32 MOUSE_PAINTCROP = 45;					///< Paint crop cursor.
static const Int32 MOUSE_PAINTLINE = 46;					///< Paint line cursor.
static const Int32 MOUSE_PAINTPOLYSHAPE = 47;			///< Paint polygon shape cursor.
/// @}

/// @addtogroup EVMSG
/// @ingroup group_enumeration
/// @{
/// Global events
#define EVMSG_CHANGE								604										///< Sent by EventAdd().
#define EVMSG_DOCUMENTRECALCULATED	'drcl'								///< Sent while drawing after the animation, expressions and cache building have been done.\n
																													///< Allows that certain managers (e.g. Attribute Manager) update their values to the changes done by the expressions etc.
																													///< @warning Any reactions on this message should be fast.\n
																													///< No modifying stuff must be done here as the draw thread is running at the same time and accesses the same data!
#define EVMSG_TOOLCHANGED						Int32(0xfff36465)			///< A tool setting has changed (local event).
#define EVMSG_GRAPHVIEWCHANGED			400008000							///< Something in XPresso has been changed (local event).
#define EVMSG_AUTKEYMODECHANGED			200000009							///< The autokey mode was changed.
#define EVMSG_UPDATEHIGHLIGHT				200000073							///< Sent by in the case that only the highlighting changes.
																													///< @note This happens for example when the mouse is moved over the viewport. Plugins usually do not need to care about this.
#define EVMSG_UPDATEBASEDRAW				200000099							///< Sent by in the case that the view should be redrawn. @since R19

#define EVMSG_SHOWIN_SB		-200000074			///< Show in Scene Browser.
#define EVMSG_SHOWIN_TL		-200000075			///< Show in Timeline.
#define EVMSG_SHOWIN_FC		-200000076			///< Show in Function Curve editor.
#define EVMSG_SHOWIN_LM		-200000077			///< Show in Layer Manager.

#define EVMSG_TLOM_MERGE	-465001000			///< @markPrivate
#define EVMSG_SETMODE   	1055256			    ///< @markPrivate

#define EVMSG_SHOWIN_MT	-200000078			///< Show in Motion editor.
#define EVMSG_TL_FCURVE_POS		-200000079	///< Show and frame fcurve position tracks.
#define EVMSG_TL_FCURVE_ROT		-200000080	///< Show and frame fcurve rotation tracks.
#define EVMSG_TL_FCURVE_SCALE		-200000081	///< Show and frame fcurve scale tracks.

#define EVMSG_TIMELINESELECTION	-1001			///< A timeline selection has been changed (local event).
#define EVMSG_BROWSERCHANGE			-1002			///< Something in the browser has been changed (local event).
#define EVMSG_MATERIALSELECTION	-1009			///< A material selection has been changed (local event).
#define EVMSG_FCURVECHANGE			-1010			///< Something in the F-Curve manager has been changed (local event).

#define EVMSG_RAYTRACER_FINISHED		-1003					///< @markPrivate
#define EVMSG_MATERIALPREVIEW				-1008					///< @markPrivate
#define EVMSG_ACTIVEVIEWCHANGED			'acvw'				///< @markPrivate
#define EVMSG_ASYNCEDITORMOVE				'edmv'				///< The user moved something in the editor window. Managers should update things like position fields.
#define EVMSG_TAKECHANGED						431000159			///< Sent by the Take System when the current Take ID changed to let all managers react to the new status. @since R17.032
#define EVMSG_2DTRACKCHANGED		1039956	///< Sent by MotionTracker when 2D Track data is changed, to let e.g. Track View react.

#define MOVE_START		0			///< Move started.
#define MOVE_CONTINUE	1			///< Move continued.
#define MOVE_END			2			///< Move ended. @c par2 == @em ESC
#define EVMSG_TIMECHANGED						'tchg'				///< @markPrivate
#define EVMSG_VIEWWINDOW_OUTPUT			-1011					///< @markPrivate
#define EVMSG_VIEWWINDOW_3DPAINTUPD	-1012					///< @markPrivate
#define EVMSG_UPDATESCHEME					200000010			///< Scheme has been updated.
#define DEPRECATED_SCHEME_LIGHT	0	///< Light. @markDeprecated
#define SCHEME_DARK		1						///< Dark.
#define SCHEME_OTHER	2						///< Other.
/// @}

/// @addtogroup EVENT
/// @ingroup group_enumeration
/// @{
enum class EVENT
{
	NONE											= 0,						///< None.
	FORCEREDRAW								= (1 << 0),			///< Force a complete redraw.
	ANIMATE										= (1 << 1),			///< Animate document.
	NOEXPRESSION							= (1 << 2),			///< Do not execute expressions.
	GLHACK										= (1 << 3),			///< @markPrivate
	CAMERAEXPRESSION					= (1 << 4),			///< If set (and not @ref EVENT::NOEXPRESSION), the event will only update camera dependent expressions (for faster speed).
	ENQUEUE_REDRAW						= (1 << 5),			///< Do not stop the current redraw if @ref DrawViews() is running at the moment. In that case enqueue the redraw after the current draw is done. @since R17.032
	DONT_OVERWRITE_RENDERING	= (1 << 6)			///< If this flag is set, renderings will not be overwritten.
} MAXON_ENUM_FLAGS(EVENT);
/// @}

/// @addtogroup DRAWFLAGS
/// @ingroup group_enumeration
/// @{
enum class DRAWFLAGS
{
	NONE													= 0,							///< None.
	NO_THREAD											= (1 << 1),				///< Synchronous call.
	NO_ANIMATION									= (1 << 8),				///< Ignore all animation.
	ONLY_ACTIVE_VIEW							= (1 << 10),			///< Only redraw the active view.
	NO_EXPRESSIONS								= (1 << 12),			///< Ignore expressions.
	INDRAG												= (1 << 13),			///< In drag.
	NO_HIGHLIGHT_PLANE						= (1 << 14),			///< The entire view is drawn, not just the highlight plane.
	FORCEFULLREDRAW								= (1 << 15),			///< Force full redraw.
	ONLY_CAMERAEXPRESSION					= (1 << 16),			///< Camera expression.
	INMOVE												= (1 << 17),			///< In move.
	ONLY_BASEDRAW									= (1 << 22),			///< Draw specific base draw only.
	ONLY_HIGHLIGHT								= (1 << 18),			///< Only highlights.
	STATICBREAK										= (1 << 19),			///< If the display is done in the main thread (@C4D only does this during animation playback) this allows that a special thread is used to poll the escape key.
	NO_PRESENT										= (1 << 23),			///< Prevents the drawport from swapping buffers.
																									///< @note Use only in combination with @ref DRAWFLAGS::NO_THREAD.
	PRIVATE_NO_WAIT_GL_FINISHED		= (1 << 3),				///< @markPrivate
	PRIVATE_ONLYBACKGROUND				= (1 << 4),				///< @markPrivate
	PRIVATE_NOBLIT								= (1 << 9),				///< @markPrivate
	PRIVATE_OPENGLHACK						= (1 << 11),			///< @markPrivate
	PRIVATE_ONLY_PREPARE					= (1 << 21),			///< @markPrivate
	PRIVATE_NO_3DCLIPPING					= (1 << 24),			///< @markPrivate
	DONT_OVERWRITE_RENDERING			= (1 << 25),			///< @markPrivate
	SKIP_IF_THREADED_DRAW_ACTIVE	= (1 << 26),			///< Return instantly if threaded draw is still running.
	DRAW_WITH_BLOCKED_INTERACTION = (1 << 27),			///< Execute the draw even if interaction is blocked (modal windows on top)
	SELECTION_ONLY								= (1 << 28),			///< @markPrivate
	BUILD_AS_EXTERNALRENDERER			= (1 << 29)				///< Builds the scene as External Renderer
} MAXON_ENUM_FLAGS(DRAWFLAGS);
/// @}

/// @addtogroup ANIMATEFLAGS
/// @ingroup group_enumeration
/// @{
enum class ANIMATEFLAGS
{
	NONE					= 0,						///< None.
	NO_PARTICLES	= (1 << 2),			///< Ignore particles.
	NO_CHILDREN		= (1 << 6),			///< Do not animate children.
	INRENDER			= (1 << 7),			///< Prepare to render scene.
	NO_MINMAX			= (1 << 8),			///< @markPrivate
	NO_NLA				= (1 << 9),			///< @markPrivate
	NLA_SUM				= (1 << 10)			///< @markPrivate
} MAXON_ENUM_FLAGS(ANIMATEFLAGS);
/// @}

/// @addtogroup SAVEDOCUMENTFLAGS
/// @ingroup group_enumeration
/// @{
/// Flags for saving documents.
/// @see SaveDocument()
enum class SAVEDOCUMENTFLAGS
{
	NONE								= 0,						///< None.
	DIALOGSALLOWED			= (1 << 0),			///< Flag to inform that a dialog can be displayed. If this flag not set then no dialogs must be opened.
	SAVEAS							= (1 << 1),			///< Forces a "Save As" and opens the file dialog.
	DONTADDTORECENTLIST	= (1 << 2),			///< Do not add the saved document to the recent file list.
	AUTOSAVE						= (1 << 3),			///< Sets the Auto Save mode. Files are not added to the recent file list and the document change star will not be reset.
	SAVECACHES					= (1 << 4),			///< For @em Cineware export only. Caches of objects will also be written (only supported by @C4D file format).
	EXPORTDIALOG				= (1 << 5),			///< Opens the Export dialog.
	CRASHSITUATION			= (1 << 6),			///< This flag is passed to @C4D if a crash occurred.
	NO_SHADERCACHE			= (1 << 7)			///< Disables the @ref SCENEFILTER::SAVE_BINARYCACHE flag.
} MAXON_ENUM_FLAGS(SAVEDOCUMENTFLAGS);
/// @}


/// @addtogroup COPYFLAGS
/// @ingroup group_enumeration
/// @{
/// Flags for the copy of @C4D objects.
enum class COPYFLAGS
{
	NONE															= 0,							///< None.
	NO_HIERARCHY											= (1 << 2),				///< Copy without children.
	NO_ANIMATION											= (1 << 3),				///< Copy without tracks, sequences or keys.
	NO_BITS														= (1 << 4),				///< Do not copy BaseList2D bits.
	NO_MATERIALPREVIEW								= (1 << 5),				///< Do not create a new material preview.
	NO_BRANCHES												= (1 << 7),				///< Do not copy branches, for example tags on an object. Automatically implies @ref COPYFLAGS::NO_ANIMATION, as animation is a branch.
	DOCUMENT													= (1 << 10),			///< This is a read-only flag that is set when a complete document is copied.
	NO_NGONS													= (1 << 11),			///< Do not copy N-gons.
	CACHE_BUILD												= (1 << 13),			///< This is a read-only flag that is set when a cache is built.
	RECURSIONCHECK										= (1 << 14),			///< Checks and avoids instances to cause recursions.

	PRIVATE_IDENTMARKER								= (1 << 0),				///< @markPrivate
	PRIVATE_NO_INTERNALS							= (1 << 8),				///< @markPrivate
	PRIVATE_NO_PLUGINLAYER						= (1 << 9),				///< @markPrivate
	PRIVATE_UNDO											= (1 << 12),			///< @markPrivate
	PRIVATE_CONTAINER_COPY_DIRTY			= (1 << 15),			///< @markPrivate
	PRIVATE_CONTAINER_COPY_IDENTICAL	= (1 << 16),			///< @markPrivate
	PRIVATE_NO_TAGS										= (1 << 17),			///< @markPrivate
	PRIVATE_DELETE										= (1 << 18),			///< @markPrivate
	PRIVATE_CLIPBOARD_COPY						= (1 << 19),			///< @markPrivate
	PRIVATE_NO_ASSETS									= (1 << 20),			///< @markPrivate
	PRIVATE_NO_RESULTASSETS						= (1 << 21),			///< @markPrivate
	PRIVATE_NO_LOGS										= (1 << 22),			///< @markPrivate @since R17.048
	PRIVATE_RENDER										= (1 << 23),			///< @markPrivate
	PRIVATE_MOGRAPH_CLONE							= (1 << 24),			///< @markPrivate
	PRIVATE_FASTCOPYFROMPARENT				= (1 << 28),			///< @markPrivate
	PRIVATE_BODYPAINT_NODATA					= (1 << 29),			///< @markPrivate
	PRIVATE_BODYPAINT_CONVERTLAYER		= (1 << 30),			///< @markPrivate
	WITH_MODIFIED_MATRIX							= (1 << 31)				///< Activates to copy the modified matrix of an object.
} MAXON_ENUM_FLAGS(COPYFLAGS);
/// @}

/// @addtogroup UNDOTYPE
/// @ingroup group_enumeration
/// @{
/// Type list for document undos.
/// @see	BaseDocument::AddUndo() BaseDocument::FindUndoPtr()
enum class UNDOTYPE
{
	NONE						= 0,				///< None.

	CHANGE						= 40,				///< Any change to an object, including hierarchy modifications, modification in positioning, substructures, etc. Must be called before the change.
	CHANGE_NOCHILDREN			= 41,				///< Same as @ref UNDOTYPE::CHANGE but without child modifications. Must be called before the change.
	CHANGE_SMALL				= 42,				///< Change to the local data of the node as its data container. Does not apply for changes on substructures as tags or child-nodes. Must be called before the change.
	CHANGE_SELECTION			= 43,				///< Change to the point, polygon, or edge selection of the node. Must be called before the change.

	NEWOBJ						= 44,				///< A new object, material, tag, or other classic API node instance has been inserted into the document. Must be called after the action.
	DELETEOBJ					= 45,				///< An object, node, tag, or other classic API node instance is about to be deleted. Must to be called before action.

	ACTIVATE					= 46,				///< Automatically managed by BaseDocument::SetActiveObject(), BaseDocument::SetActiveTag(), BaseDocument::SetActiveMaterial() etc. No need to be used manually.
	DEACTIVATE					= 47,				///< Automatically managed by BaseDocument::SetActiveObject(), BaseDocument::SetActiveTag(), BaseDocument::SetActiveMaterial() etc. No need to be used manually.

	BITS						= 48,				///< Change to object bits. Needs to be called before the change.
	HIERARCHY_PSR				= 49,				///< Change in hierarchical placement and PSR values. Needs to be called before the change.

	PRIVATE_STRING				= 9996,			///< @markPrivate
	PRIVATE_MULTISELECTIONAXIS	= 9997,			///< @markPrivate
	START						= 9998,			///< @markPrivate
	END							= 9999			///< @markPrivate
} MAXON_ENUM_LIST(UNDOTYPE);
/// @}

/// @addtogroup DRAWHANDLE
/// @ingroup group_enumeration
/// @{
/// Draw handle types.
/// @see BaseDraw::DrawHandle2D BaseDraw::DrawHandle
enum class DRAWHANDLE
{
	MINI					= 0,			///< Tiny point.
	SMALL					= 1,			///< Small point.
	MIDDLE				= 2,			///< Medium point.
	BIG						= 3,			///< Handle used by object generators and deformers.
	CUSTOM				= 4,			///< Custom handle.
	POINTSIZE			= 5,			///< Use the point size to draw the handle.
	SELPOINTSIZE	= 6				///< Use the size of selected points to draw the handle.
} MAXON_ENUM_LIST(DRAWHANDLE);
/// @}

/// @addtogroup DRAW_ALPHA
/// @ingroup group_enumeration
/// @{
enum class DRAW_ALPHA
{
	NONE								= 10,			///< No alpha.
	INVERTED						= 11,			///< Generates inverted alpha.
	NORMAL							= 12,			///< Generates alpha channel from the image's alpha channel. If no alpha channel exists, the alpha value is set to @em 100%.
	FROM_IMAGE					= 13,			///< Generates the alpha channel from the RGB image information.
	NORMAL_FROM_IMAGE		= 14			///< Generates alpha channel from the image's alpha channel. If no alpha channel exists, the alpha value is generated from the RGB image.
} MAXON_ENUM_LIST(DRAW_ALPHA);
/// @}

/// @addtogroup DRAW_TEXTUREFLAGS
/// @ingroup group_enumeration
/// @{
enum class DRAW_TEXTUREFLAGS
{
	NONE												= 0x0,						///< None.

	COLOR_IMAGE_TO_LINEAR				= 0x00000001,			///< Converts the embedded color profile to linear color space.
	COLOR_SRGB_TO_LINEAR				= 0x00000002,			///< Converts from sRGB color space to linear color space.
	COLOR_IMAGE_TO_SRGB					= 0x00000003,			///< Converts the embedded color profile to sRGB color space.
	COLOR_LINEAR_TO_SRGB				= 0x00000004,			///< Converts from linear color space to sRGB color space.
	COLOR_CORRECTION_MASK				= 0x0000000f,			///< Color correction mask.

	USE_PROFILE_COLOR						= 0x00000010,			///< Use color profile color.
	ALLOW_FLOATINGPOINT					= 0x00000020,			///< Allow floating point textures (if supported).
	TILE												= 0x00000040,			///< Allow tiling with BaseDraw::DrawTexture (overridden in BaseDraw::SetTexture).

	TEMPORARY										= 0x00000100,			///< Texture is a temporary object.

	INTERPOLATION_NEAREST				= 0x00100000,			///< Nearest texture interpolation.
	INTERPOLATION_LINEAR				= 0x00200000,			///< Linear texture interpolation.
	INTERPOLATION_LINEAR_MIPMAP	= 0x00400000,			///< MIP map texture interpolation.
	INTERPOLATION_MASK					= 0x00f00000			///< Texture interpolation mask.

} MAXON_ENUM_FLAGS(DRAW_TEXTUREFLAGS);
/// @}

/// @addtogroup TOOLDRAW
/// @ingroup group_enumeration
/// @{
enum class TOOLDRAW
{
	NONE				= 0,						///< None.
	HANDLES			= (1 << 0),			///< The active objects handles will be drawn.
	AXIS				= (1 << 1),			///< The active objects axes will be drawn.
	HIGHLIGHTS	= (1 << 2)			///< The highlights will be drawn.
} MAXON_ENUM_FLAGS(TOOLDRAW);
/// @}

/// @addtogroup TOOLDRAWFLAGS
/// @ingroup group_enumeration
/// @{
enum class TOOLDRAWFLAGS
{
	NONE			= 0,						///< None.
	INVERSE_Z	= (1 << 0),			///< Inverse Z-buffer mode. If set, the drawing engine of @C4D will only draw elements if they are further away from the camera than other objects.\n
														///< This is mostly used for help lines (such as the semi-transparent axis inside of objects).
														/// @note This mode only works when all objects are drawn so it should be passed last.
	HIGHLIGHT	= (1 << 1)			///< Highlight mode.
} MAXON_ENUM_FLAGS(TOOLDRAWFLAGS);
/// @}

/// @addtogroup VIEWCOLOR
/// @ingroup group_enumeration
/// @{
// Viewport colors.
#define VIEWCOLOR_C4DBACKGROUND															0
#define VIEWCOLOR_FILMFORMAT																1
#define VIEWCOLOR_HORIZON																		2
#define VIEWCOLOR_GRID_MAJOR																3
#define VIEWCOLOR_GRID_MINOR																4
#define VIEWCOLOR_SPLINESTART																5
#define VIEWCOLOR_SPLINEEND																	6
#define VIEWCOLOR_CAMERA																		7
#define VIEWCOLOR_PARTICLE																	8
#define VIEWCOLOR_PMODIFIER																	9
#define DELME_VIEWCOLOR_BONE																10
#define VIEWCOLOR_MODIFIER																	11
#define VIEWCOLOR_ACTIVEPOINT																12
#define VIEWCOLOR_INACTIVEPOINT															13
#define VIEWCOLOR_TANGENT																		14
#define VIEWCOLOR_ACTIVEPOLYGON															15
#define VIEWCOLOR_INACTIVEPOLYGON														16
#define VIEWCOLOR_TEXTURE																		17
#define VIEWCOLOR_TEXTUREAXIS																18
#define VIEWCOLOR_ACTIVEBOX																	19
#define VIEWCOLOR_ANIMPATH																	20
#define VIEWCOLOR_XAXIS																			21
#define VIEWCOLOR_YAXIS																			22
#define VIEWCOLOR_ZAXIS																			23
#define VIEWCOLOR_WXAXIS																		24
#define VIEWCOLOR_WYAXIS																		25
#define VIEWCOLOR_WZAXIS																		26
#define VIEWCOLOR_SELECT_AXIS																27
#define VIEWCOLOR_LAYER0																		28
#define VIEWCOLOR_LAYER1																		29
#define VIEWCOLOR_LAYER2																		30
#define VIEWCOLOR_LAYER3																		31
#define VIEWCOLOR_LAYER4																		32
#define VIEWCOLOR_LAYER5																		33
#define VIEWCOLOR_LAYER6																		34
#define VIEWCOLOR_LAYER7																		35
#define VIEWCOLOR_VERTEXSTART																36
#define VIEWCOLOR_VERTEXEND																	37
#define VIEWCOLOR_UVMESH_GREYED															38
#define VIEWCOLOR_UVMESH_APOLY															39
#define VIEWCOLOR_UVMESH_IAPOLY															40
#define VIEWCOLOR_UVMESH_APOINT															41
#define VIEWCOLOR_UVMESH_IAPOINT														42
#define VIEWCOLOR_NORMAL																		43
#define VIEWCOLOR_ACTIVECHILDBOX														44
#define VIEWCOLOR_ACTIVEPOLYBOX															45
#define VIEWCOLOR_ACTIVEPOLYCHILDBOX												46
#define VIEWCOLOR_SELECTION_PREVIEW													47
#define VIEWCOLOR_MEASURETOOL																48
// #define VIEWCOLOR_AXIS_BAND															49
#define VIEWCOLOR_SHADEDWIRE																50
#define VIEWCOLOR_NGONLINE																	51
#define VIEWCOLOR_FRONTFACING																52
#define VIEWCOLOR_BACKFACING																53
#define VIEWCOLOR_MINSOFTSELECT															54
#define VIEWCOLOR_MAXSOFTSELECT															55
#define VIEWCOLOR_MINHNWEIGHT																56
#define VIEWCOLOR_ZEROHNWEIGHT															57
#define VIEWCOLOR_MAXHNWEIGHT																58
#define VIEWCOLOR_IRR																				59
#define VIEWCOLOR_OBJECTHIGHLIGHT														60
#define VIEWCOLOR_OBJECTSELECT															61
#define VIEWCOLOR_C4DBACKGROUND_GRAD1												62
#define VIEWCOLOR_C4DBACKGROUND_GRAD2												63
#define VIEWCOLOR_BRUSHPREVIEW															64
#define VIEWCOLOR_SPLINEHULL																65
#define VIEWCOLOR_TOOLHANDLE																66
#define VIEWCOLOR_ACTIVETOOLHANDLE													67
#define VIEWCOLOR_TOOLHANDLEHIGHLIGHT												68
#define VIEWCOLOR_TOOLHANDLE2																69
#define VIEWCOLOR_TOOLHANDLEHIGHLIGHT2											70
#define VIEWCOLOR_ACTIVETOOLHANDLE2													71
#define VIEWCOLOR_TOOLSELECTION															72
#define VIEWCOLOR_BASEGRID																	73
#define VIEWCOLOR_VERTEX_NORMAL															74	///< @since R18
#define VIEWCOLOR_MOSELECTEDFG															75	///< @since R18
#define VIEWCOLOR_MOSELECTEDBG															76	///< @since R18
#define VIEWCOLOR_MODESELECTEDFG														77	///< @since R18
#define VIEWCOLOR_MODESELECTEDBG														78	///< @since R18
#define VIEWCOLOR_TESSELLATIONWIRE													79	///< @since R18
#define VIEWCOLOR_FIELDGIZMO_COLOR1													80	///< @since R20
#define VIEWCOLOR_FIELDGIZMO_COLOR2													81	///< @since R20
#define VIEWCOLOR_FIELDGIZMO_FALLOFF1												82	///< @since R20
#define VIEWCOLOR_FIELDGIZMO_FALLOFF2												83	///< @since R20
#define VIEWCOLOR_UVGIZMO_NORMAL														84	///< @since R21
#define VIEWCOLOR_UVGIZMO_CANDIDATE													85	///< @since R21
#define VIEWCOLOR_UVGIZMO_IN_MOTION													86	///< @since R21
#define VIEWCOLOR_UVGIZMO_ANCHOR_SNAPPED										87	///< @since R21
#define VIEWCOLOR_UV_AXIS_U																	88	///< @since R21
#define VIEWCOLOR_UV_AXIS_V																	89	///< @since R21
#define VIEWCOLOR_JOINT																			90	///< @since R21
#define VIEWCOLOR_HANDLES																		91	///< @since R21
#define VIEWCOLOR_UV_BACKGROUND															92	///< @since R22
#define VIEWCOLOR_UV_OVERLAPS																93	///< @since R22
#define VIEWCOLOR_UV_SOFTSELECTION_MIN        							94  ///< @since R22
#define VIEWCOLOR_UV_SOFTSELECTION_MAX        							95  ///< @since R22
#define VIEWCOLOR_BRUSH_PREVIEW															96	///< @since R22
#define VIEWCOLOR_UV_STRETCH_MAP_STRETCHED									97  ///< @since R22
#define VIEWCOLOR_UV_STRETCH_MAP_COMPRESSED									98  ///< @since R22
#define VIEWCOLOR_UV_WORLD_AXIS_U														99	///< @since R22
#define VIEWCOLOR_UV_WORLD_AXIS_V														100	///< @since R22
#define VIEWCOLOR_UV_SEAMS																	101	///< @since R22
#define VIEWCOLOR_UVMESH_IAFILLEDPOLY												102	///< @since R22
#define VIEWCOLOR_UVMESH_BACKFACEPOLY												103	///< @since R22
#define VIEWCOLOR_UV_PINS																		104	///< @since R22
#define VIEWCOLOR_UV_REFERENCE_CANVAS												105	///< @since R22
#define VIEWCOLOR_UV_GRID_MAJOR															106	///< @since R23
#define VIEWCOLOR_UV_GRID_MINOR															107	///< @since R23
#define VIEWCOLOR_INACTIVE_MODIFIER													108	///< @since R23
#define VIEWCOLOR_SHADOW_HINTING														109	///< @since R24
#define VIEWCOLOR_SPLINE_NULL																110	///< @since R25
#define VIEWCOLOR_OFFSCREEN_SELECTION_INDICATOR							111	///< @since R25
#define VIEWCOLOR_OFFSCREEN_SELECTION_INDICATOR_HIGHLIGHT		112	///< @since R25
#define VIEWCOLOR_SYMMETRY_SELECTION_HIGHLIGHT							113 ///< @since 2023.000
#define VIEWCOLOR_SYMMETRY_TOPOLOGY_LOOP_HIGHLIGHT					114 ///< @since 2023.000
#define VIEWCOLOR_SYMMETRY_PLANE_X													115 ///< @since 2023.000
#define VIEWCOLOR_SYMMETRY_PLANE_Y													116 ///< @since 2023.000
#define VIEWCOLOR_SYMMETRY_PLANE_Z													117 ///< @since 2023.000
#define VIEWCOLOR_PATTERN_SELECTION_HIGHLIGHT								118 ///< @since 2024.000
#define VIEWCOLOR_PATTERN_SELECTION_DIRECTIONS							119 ///< @since 2024.000
#define VIEWCOLOR_MAXCOLORS																	120
/// @}

/// @addtogroup DIRTYFLAGS
/// @ingroup group_enumeration
/// @{
/// Objects dirty flags.
/// @see	C4DAtom::GetDirty C4DAtom::SetDirty\n
///				BaseObject::IsDirty BaseObject::SetDirty
enum class DIRTYFLAGS
{
	NONE					= 0,						///< None.
	MATRIX				= (1 << 1),			///< Matrix changed.
	DATA					= (1 << 2),			///< Container changed.
	SELECT				= (1 << 3),			///< Check all valid selections of the object, e.g. points, edge, polys.
	CACHE					= (1 << 4),			///< Check if the cache of an object has been changed (rebuilt).
	CHILDREN			= (1 << 5),			///< Check if the children are dirty.
	DESCRIPTION		= (1 << 6),			///< Description changed.

	SELECTION_OBJECTS		= (1 << 20),			///< For BaseDocument, object selections have changed.
	SELECTION_TAGS			= (1 << 21),			///< For BaseDocument, tag selections have changed.
	SELECTION_MATERIALS	= (1 << 22),			///< For BaseDocument, material selections have changed.

	ALL	= -1			///< Check all dirty flags.
} MAXON_ENUM_FLAGS(DIRTYFLAGS);
/// @}

/// @addtogroup HDIRTY_ID
/// @ingroup group_enumeration
/// @{
/// @markInternal
enum class HDIRTY_ID
{
	ANIMATION					= 0,
	OBJECT						= 1,
	OBJECT_MATRIX			= 2,
	OBJECT_HIERARCHY	= 3,
	TAG								= 4,
	MATERIAL					= 5,
	SHADER						= 6,
	RENDERSETTINGS		= 7,
	VP								= 8,
	FILTER						= 9,
	NBITS							= 10,
	MAX
} MAXON_ENUM_LIST(HDIRTY_ID);
/// @}

/// @addtogroup HDIRTYFLAGS
/// @ingroup group_enumeration
/// @{
/// @see C4DAtom::GetHDirty C4DAtom::SetHDirty
enum class HDIRTYFLAGS
{
	NONE							= 0,																							///< None.
	ANIMATION					= (1 << (UInt32)HDIRTY_ID::ANIMATION),							///< Animation mask.
	OBJECT						= (1 << (UInt32)HDIRTY_ID::OBJECT),								///< Object data mask.
	OBJECT_MATRIX			= (1 << (UInt32)HDIRTY_ID::OBJECT_MATRIX),					///< Object matrix mask.
	OBJECT_HIERARCHY	= (1 << (UInt32)HDIRTY_ID::OBJECT_HIERARCHY),			///< Object hierarchy mask.
	TAG								= (1 << (UInt32)HDIRTY_ID::TAG),										///< Tag data mask.
	MATERIAL					= (1 << (UInt32)HDIRTY_ID::MATERIAL),							///< %Material data mask.
	SHADER						= (1 << (UInt32)HDIRTY_ID::SHADER),								///< Shader data mask.
	RENDERSETTINGS		= (1 << (UInt32)HDIRTY_ID::RENDERSETTINGS),				///< %Render settings mask.
	VP								= (1 << (UInt32)HDIRTY_ID::VP),										///< Videopost mask.
	FILTER						= (1 << (UInt32)HDIRTY_ID::FILTER),								///< Filter data mask.
	NBITS							= (1 << (UInt32)HDIRTY_ID::NBITS),									///< N-bits data mask.

	ALL								= -1			///< All.
} MAXON_ENUM_FLAGS(HDIRTYFLAGS);
/// @}

/// @addtogroup ROTATIONORDER
/// @ingroup group_enumeration
/// @{
enum class ROTATIONORDER : UChar
{
	YXZGLOBAL	= 0,			///< Global YXZ order.
	YZXGLOBAL	= 1,			///< Global YZX order.
	ZYXGLOBAL	= 2,			///< Global ZYX order.
	ZXYGLOBAL	= 3,			///< Global ZXY order.
	XZYGLOBAL	= 4,			///< Global XZY order.
	XYZGLOBAL	= 5,			///< Global XYZ order.

	YXZLOCAL	= 3,			///< Local YXZ order.
	YZXLOCAL	= 4,			///< Local YZX order.
	ZYXLOCAL	= 5,			///< Local ZYX order.
	ZXYLOCAL	= 0,			///< Local ZXY order.
	XZYLOCAL	= 1,			///< Local XZY order.
	XYZLOCAL	= 2,			///< Local XYZ order.

	HPB				= 6,			///< HPB order.
	DEFAULT		= 6				///< Default order (HPB).
} MAXON_ENUM_LIST(ROTATIONORDER);
/// @}

/// @addtogroup ROTATIONINTERPOLATION_QUATERNION
/// @ingroup group_enumeration
/// @{
/// @since R18
enum class ROTATIONINTERPOLATION_QUATERNION : UChar
{
	SLERP = 2,	///< Spherical LERP Interpolation (linear).
	CUBIC = 3		///< Smooth Cubic Interpolation (formerly known as Losch).
} MAXON_ENUM_LIST(ROTATIONINTERPOLATION_QUATERNION);
/// @}

/// @addtogroup CURVEINTERPOLATION_MODE
/// @ingroup group_enumeration
/// @{
/// @since R24
enum class CURVEINTERPOLATION_MODE
{
	R23, ///< hermite evaluation with some tangent issues

	CURRENT ///< Spline evaluation
} MAXON_ENUM_LIST(CURVEINTERPOLATION_MODE);
/// @}

/// @addtogroup BUILDFLAGS
/// @ingroup group_enumeration
/// @{
/// Flags for building documents and objects.
/// @see Hierarchy::Run BaseDocument::ExecutePasses HierarchyHelp::GetBuildFlags
enum class BUILDFLAGS : UInt16
{
	NONE							= 0,						///< None.
	INTERNALRENDERER	= (1 << 1),			///< Rendering in the editor.
	EXTERNALRENDERER	= (1 << 2),			///< Rendering externally.
	ISOPARM						= (1 << 3),			///< Generate isoparm objects.
	EXPORTONLY				= (1 << 4),			///< Exporting (e.g. Alembic).
	INTERACTIVEEDITOR = (1 << 5),			///< currently running in the active viewport window (viewscheduler or mainthread)
} MAXON_ENUM_FLAGS(BUILDFLAGS);
/// @}

/// @addtogroup EXECUTIONFLAGS
/// @ingroup group_enumeration
/// @{
/// Flags for the execution of a certain point in the pipeline.
/// @see PriorityList::Add ObjectData::Execute TagData::Execute SceneHookData::Execute
enum class EXECUTIONFLAGS
{
	NONE						= 0,									///< None.
	ANIMATION				= (1 << 1),						///< Animation is calculated.
	EXPRESSION			= (1 << 2),						///< Expressions are calculated.
	CACHEBUILDING		= (1 << 3),						///< Cache building is done.
	CAMERAONLY			= (1 << 4),						///< Only camera dependent expressions shall be executed.
	INDRAG					= (1 << 5),						///< Pipeline is done within scrubbing.
	INMOVE					= (1 << 6),						///< Pipeline is done within moving.
	RENDER					= (1 << 7),			///< The external renderer (Picture Viewer) is running.
	ALLOW_PRIORITYSHIFT	= (1 << 8)			///< Allow to shift the priority with the priority shift tag. @markPrivate @since R18
} MAXON_ENUM_FLAGS(EXECUTIONFLAGS);
/// @}

/// @addtogroup SCENEHOOKDRAW
/// @ingroup group_enumeration
/// @{
enum class SCENEHOOKDRAW
{
	NONE												= 0,						///< None.
	DRAW_PASS										= (1 << 0),			///< Normal drawing pass.
	HIGHLIGHT_PASS_BEFORE_TOOL	= (1 << 1),			///< Highlight pass before tool drawing.
	HIGHLIGHT_PASS							= (1 << 2),			///< Highlight pass.
	HIGHLIGHT_PASS_INV					= (1 << 3),			///< Inverted highlight pass.
	DRAW_PASS_AFTER_CLEAR				= (1 << 4)			///< Immediately after clearing the viewport.
} MAXON_ENUM_FLAGS(SCENEHOOKDRAW);
/// @}

/// @addtogroup DESCFLAGS_DESC
/// @ingroup group_enumeration
/// @{
/// @see NodeData::GetDDescription C4DAtom::GetDescription
enum class DESCFLAGS_DESC
{
	NONE									= 0,						///< None.
	RESOLVEMULTIPLEDATA		= (1 << 0),			///< Private and unused.
	LOADED								= (1 << 1),			///< Set if elements have been added to the description, either by loading or manual addition.
	RECURSIONLOCK					= (1 << 2),			///< @markPrivate
	DONTLOADDEFAULT				= (1 << 3),			///< Do not load defaults. Used internally for old plugin tools.
	MAPTAGS								= (1 << 4),			///< If set, the object description will also contain the tag's descriptions (as sub-containers).
	NEEDDEFAULTVALUE			= (1 << 5),			///< Set if @em "Reset to Default" was called by the user.
	TRISTATE							= (1 << 6),			///< @markInternal Set when 2 or more objects are shown.
	EXPORTHELPSYMBOLSMODE	= (1 << 7),			///< @markInternal Used for help file symbol generator export.
	MATREFLECTANCEOVERLAP	= (1 << 8),			///< @markInternal Used in materials and in tristate (i.e. 2 or more materials are selected) to indicate if the reflectance layer setup overlaps between all materials. @since R18
	XPRESSO								= (1 << 9),			///< Set from XPresso. Can be used e.g. to hide parameters in XPresso ports. @since R19
	PRESET								= (1 << 10),		///< @markInternal Can be used to adapt code when asked for default description by the preset system
} MAXON_ENUM_FLAGS(DESCFLAGS_DESC);
/// @}

/// @addtogroup DESCFLAGS_GET
/// @ingroup group_enumeration
/// @{
/// @see for NodeData::GetDParameter C4DAtom::GetParameter
enum class DESCFLAGS_GET
{
	NONE												= 0,						///< None.
	PARAM_GET										= (1 << 1),			///< Parameter retrieved.
	NO_GLOBALDATA								= (1 << 4),			///< @markPrivate
	NO_GEDATADEFAULTVALUE				= (1 << 5),			///< If set, the GeData default type will not be initialized for C4DAtom::GetParameter.
	ALLOW_TRISTATE							= (1 << 6),			///< If set, is permitted to return GeData of type DA_TRISTATE to indicate that there are multiple values.
	PRIVATE_GETDEFAULTVALUEONLY = (1 << 7),			///< If set, only the default value will be returned (works only with AMEmulationNode)
} MAXON_ENUM_FLAGS(DESCFLAGS_GET);
/// @}

/// @addtogroup DESCFLAGS_SET
/// @ingroup group_enumeration
/// @{
/// @see for NodeData::SetDParameter C4DAtom::SetParameter
enum class DESCFLAGS_SET
{
	NONE									= 0,						///< None.
	PARAM_SET							= (1 << 1),			///< Parameter set.
	USERINTERACTION				= (1 << 2),			///< Set when the GUI is calling @c SetParameter().
																				///< @note This is the only time when C4DAtom::SetParameter is allowed to use the user interaction elements (e.g. open dialogs, display messages etc.).
	DONTCHECKMINMAX				= (1 << 3),			///< No check is internally done if the parameter passed is within the [min/max] range of the description, to save some time.
	DONTAFFECTINHERITANCE	= (1 << 6),			///< No parameter inheritance, for render settings and post effects only.
	FORCESET							= (1 << 7),			///< Force the set value without @em GetParameter/@em Compare.
																				///< @warning Use only for calls where for sure the value was changed!
	DONTFREESPLINECACHE		= (1 << 8),			///< @markPrivate @since R16.038
	INDRAG								= (1 << 9),			///< Gadget (e.g. Slider) in dragging mode (not finished). @note Only used when DESCFLAGS_SET::USERINTERACTION is set. @since R17.053
	INRESETTODEFAULT			= (1 << 10)			///< Set if the set operation is a "reset to default". @since R20.015
} MAXON_ENUM_FLAGS(DESCFLAGS_SET);
/// @}

/// @addtogroup DESCFLAGS_ENABLE
/// @ingroup group_enumeration
/// @{
enum class DESCFLAGS_ENABLE
{
	NONE = 0			///< None.
} MAXON_ENUM_FLAGS(DESCFLAGS_ENABLE);
/// @}

/// @addtogroup HIERARCHYCLONEFLAGS
/// @ingroup group_enumeration
/// @{
/// @see BaseObject::GetAndCheckHierarchyClone BaseObject::GetHierarchyClone
enum class HIERARCHYCLONEFLAGS
{
	NONE			= 0,						///< None.
	ASIS			= (1 << 0),			///< Objects unchanged. (Used by e.g. @ref Oarray.)
	ASPOLY		= (1 << 1),			///< Objects cloned as polygons. (Used by e.g. HyperNURBS.)
	ASLINE		= (1 << 2),			///< Objects cloned as line objects.
	ASSPLINE	= (1 << 3),			///< Objects cloned as splines.
	ASVOLUME	= (1 << 4),			///< Objects cloned as volumes.
} MAXON_ENUM_FLAGS(HIERARCHYCLONEFLAGS);
/// @}

/// @addtogroup CHECKVALUEFORMAT
/// @ingroup group_enumeration
/// @{
/// @see	ErrorStringDialog()\n
///				GeModalDialog::CheckReal
enum class CHECKVALUEFORMAT
{
	NOTHING	= 0,			///< No unit.
	DEGREE	= 1,			///< Degrees.
	PERCENT	= 2,			///< Percent.
	METER		= 3,			///< Meter. Working unit.
	INT			= 5				///< Integer.
} MAXON_ENUM_LIST(CHECKVALUEFORMAT);
/// @}

/// @addtogroup CHECKVALUERANGE
/// @ingroup group_enumeration
/// @{
/// @see	ErrorStringDialog()\n
///				GeModalDialog Check Methods
enum class CHECKVALUERANGE
{
	GREATER					= 0,			///< val > x
	GREATEROREQUAL	= 1,			///< val >= x
	LESS						= 2,			///< val < x
	LESSOREQUAL			= 3,			///< val <= x
	BETWEEN					= 4,			///< x > val > y
	BETWEENOREQUAL	= 5,			///< x >= val >= y
	BETWEENOREQUALX	= 6,			///< x >= val > y
	BETWEENOREQUALY	= 7,			///< x > val >= y
	DIFFERENT				= 8				///< x != val
} MAXON_ENUM_LIST(CHECKVALUERANGE);
/// @}

/// @addtogroup PAINTMESHFLAGS
/// @ingroup group_enumeration
/// @{
enum class PAINTMESHFLAGS
{
	NONE			= 0,							///< None.

	QUAD			= (1 << 1),				///< Polygon is quadrangle.
	SEL				= (1 << 6),				///< Polygon is selected.

	SELA			= (1 << 2),				///< Point a selected.
	SELB			= (1 << 3),				///< Point b selected.
	SELC			= (1 << 4),				///< Point c selected.
	SELD			= (1 << 5),				///< Point d selected.

	TA				= (1 << 7),				///< Point a temporary selection for link mode.
	TB				= (1 << 8),				///< Point b temporary selection for link mode.
	TC				= (1 << 9),				///< Point c temporary selection for link mode.
	TD				= (1 << 10),			///< Point d temporary selection for link mode.

	INACTIVE	= (1 << 11),			///< No draw, no change possible.

	EDGEA			= (1 << 12),			///< Edge a is N-gon line.
	EDGEB			= (1 << 13),			///< Edge b is N-gon line.
	EDGEC			= (1 << 14),			///< Edge c is N-gon line.
	EDGED			= (1 << 15)				///< Edge d is N-gon line.
} MAXON_ENUM_FLAGS(PAINTMESHFLAGS);
/// @}

/// @addtogroup GETBRANCHINFO
/// @ingroup group_enumeration
/// @{
/// @see NodeData::GetBranchInfo GeListNode::GetBranchInfo
enum class GETBRANCHINFO
{
	NONE							= 0,						///< None.
	ONLYWITHCHILDREN	= (1 << 1),			///< Only return branch if it is in use, i.e. has content.
	GELISTNODES				= (1 << 3),			///< @markPrivate
	ONLYMODIFIABLE		= (1 << 4),			///< @markPrivate
	ONLYWITHANIMATION = (1 << 5),			///< Only return branch if animation flag is set.
} MAXON_ENUM_FLAGS(GETBRANCHINFO);
/// @}

/// @addtogroup BRANCHINFOFLAGS
/// @ingroup group_enumeration
/// @{
/// @see BranchInfo::flags
enum class BRANCHINFOFLAGS
{
	NONE						= 0,						///< None.
	ANIMATE					= (1 << 0),			///< Animate the nodes in this branch.
	HIDEINTIMELINE	= (1 << 4),			///< If set, this branch will not show up in the timeline.
	HASFIELDS				= (1 << 5)			///< If set, this branch will contain FieldLayers and will display in the FieldsList
} MAXON_ENUM_FLAGS(BRANCHINFOFLAGS);
/// @}

/// @addtogroup GETACTIVEOBJECTFLAGS
/// @ingroup group_enumeration
/// @{
/// @see BaseDocument::GetActiveObjects
enum class GETACTIVEOBJECTFLAGS
{
	NONE						= 0,						///< None.
	CHILDREN				= (1 << 0),			///< Child objects are added to the selection too, provided they are selected. Otherwise only the topmost parent of each chain is added.
	SELECTIONORDER	= (1 << 1)			///< The selection array is sorted in the selection order, e.g. the first selected object is the first element in the array.
} MAXON_ENUM_FLAGS(GETACTIVEOBJECTFLAGS);
/// @}

/// @addtogroup DRAWPASS
/// @ingroup group_enumeration
/// @{
enum class DRAWPASS
{
	OBJECT			= 0,		///< Object pass.
	BOX					= 1,		///< Box pass.
	HANDLES			= 2,		///< Handle pass.
	HIGHLIGHTS	= 3,		///< Highlight pass.
	XRAY				= 4			///< X-Ray pass.
} MAXON_ENUM_LIST(DRAWPASS);
/// @}

/// @addtogroup FORMAT_FILES
/// @ingroup group_enumeration
/// @{
/// Import/export formats.
#define FORMAT_PREF	1000			///< Preferences.
#define FORMAT_WAV	1018			///< WAV sound.
#define FORMAT_L4D	1020			///< Layout.
#define FORMAT_P4D	1022			///< Layout.

#define FORMAT_STL_IMPORT				1001020			///< STL import.
#define FORMAT_STL_EXPORT				1001021			///< STL export.
#define FORMAT_C4DIMPORT				1001025			///< @C4D import.
#define FORMAT_C4DEXPORT				1001026			///< @C4D export.
#define FORMAT_VRML1IMPORT			1001031			///< VRML 1 import.
#define FORMAT_VRML1EXPORT			1001032			///< VRML 1 export.
#define FORMAT_VRML2IMPORT			1001033			///< VRML 2 import.
#define FORMAT_VRML2EXPORT			1001034			///< VRML 2 export.
#define FORMAT_DXFIMPORT				1001035			///< DXF import.
#define FORMAT_DXFEXPORT				1001036			///< DXF export.
#define FORMAT_3DSIMPORT				1001037			///< 3DS import.
#define FORMAT_3DSEXPORT				1001038			///< 3DS export.
#define FORMAT_OBJIMPORT				1001039			///< Old OBJ import (R16 and older).
#define FORMAT_OBJEXPORT				1001040			///< Old OBJ export (R16 and older).
#define FORMAT_Q3DIMPORT				1001041			///< QuickDraw 3D import.
#define FORMAT_Q3DEXPORT				1001042			///< QuickDraw 3D export.
#define FORMAT_AIIMPORT					1001045			///< Adobe Illustrator AI import.
#define FORMAT_DEMIMPORT				1001046			///< DEM import.
#define FORMAT_D3DEXPORT				1001047			///< Direct3D export.
#define FORMAT_BVH_IMPORT				1001048			///< BVH import.
#define FORMAT_AI_EXPORT				1012074			///< Adobe Illustrator AI export.
#define FORMAT_ALLPLAN_EXPORT		1016440			///< Allplan XML export.
#define FORMAT_DWG_IMPORT				1021372			///< AutoCAD DWG import.
#define FORMAT_DAE14IMPORT			1022315			///< Collada 14 import.
#define FORMAT_DAE14EXPORT			1022316			///< Collada 14 export.
#define FORMAT_DAE15IMPORT			1025754			///< Collada 15 import.
#define FORMAT_DAE15EXPORT			1025755			///< Collada 15 export.
#define	FORMAT_FBX_IMPORT				1026369			///< FBX import.
#define	FORMAT_FBX_EXPORT				1026370			///< FBX export.
#define FORMAT_ABCIMPORT				1028081			///< Alembic import.
#define FORMAT_ABCEXPORT				1028082			///< Alembic export.
#define FORMAT_OBJ2IMPORT				1030177			///< New OBJ import (R17 and newer). @since R17.048
#define FORMAT_OBJ2EXPORT				1030178			///< New OBJ export (R17 and newer). @since R17.048
#define FORMAT_SKPIMPORT				1033845			///< SketchUp import. @since R17.048
#define FORMAT_STEPIMPORT				1039777			///< Step import. @since R20
#define FORMAT_CATIAIMPORT			1039778			///< Catia V5 import. @since R20
#define FORMAT_IGESIMPORT				1039779			///< Iges import. @since R20
#define FORMAT_JTIMPORT					1039780			///< Jt import. @since R20
#define FORMAT_SOLIDWORKSIMPORT	1039781			///< Solidworks import. @since R20
#define FORMAT_VDB_IMPORT				1039864			///< Volume VDB import.
#define FORMAT_VDB_EXPORT				1039865			///< Volume VDB export.
#define FORMAT_GLTFEXPORT				1041129			///< glTF export. @since R22
#define FORMAT_GLTFIMPORT				1060210			///< glTF import. @since 2023.200
#define FORMAT_FORGERIMPORT			1057656			///< forger import. @since R25
#define FORMAT_FORGEREXPORT			1057664			///< forger export. @since R25
#define FORMAT_USDIMPORT				1055178			///< USD inport. @since R23
#define FORMAT_USDEXPORT				1055179			///< USD export. @since R23
#define FORMAT_GOZIMPORT				1053589			///< goz inport. @since R22

/// @}

/// A special constant that sets the (yellowish) highlight transparency mode.
static const Int32 HIGHLIGHT_TRANSPARENCY = -140;

/// Hermite factor.
#define HERMITEFAK	4.0

#define CREATE_GL_HAS_ROOT	1
#define CREATE_GL_IS_ROOT		2

#define DELETE_GL_HAS_ROOT	1
#define DELETE_GL_IS_ROOT		2

/// @addtogroup SAVEPROJECT
/// @ingroup group_enumeration
/// @{
/// @see SaveProject()
enum class SAVEPROJECT
{
	NONE												= 0,							///< None.
	ASSETS											= (1 << 1),				///< Pass if the assets will be taken into account.
	SCENEFILE										= (1 << 2),				///< Pass if the scene will be taken into account.
	DIALOGSALLOWED							= (1 << 3),				///< Show dialogs like error messages, a file selection for missing assets or alerts if necessary.
	SHOWMISSINGASSETDIALOG			= (1 << 4),				///< If an asset is missing show a warning dialog. Flag can be set without @ref SAVEPROJECT::DIALOGSALLOWED.
	ADDTORECENTLIST							= (1 << 5),				///< Add document to the recent list.
	DONTCOPYFILES								= (1 << 6),				///< Does the same as without this flag but does not copy the files to the destination. Flag used to simulate the function.
	PROGRESSALLOWED							= (1 << 7),				///< Show the progress bar in the main window.
	DONTTOUCHDOCUMENT						= (1 << 8),				///< Document will be in the same state as before the call was made.
	DONTFAILONMISSINGASSETS			= (1 << 9),				///< If this flag is passed, the function does not fail anymore when assets are missing.
	ISNET												= (1 << 10),			///< @markPrivate Set only if NET module is collecting assets.
	USEDOCUMENTNAMEASFILENAME		= (1 << 11),			///< Use the document name as the file name to save as project.
	DONTCLEARSUGGESTEDFOLDER		= (1 << 12),			///< Do not change asset paths of nodes.
	WITHCACHES									= (1 << 13),			///< Save the project assets with Global Illumination / Ambient Occlusion caches. @see ASSETDATA_FLAG_WITHCACHES @since R17.048
	DONTGENERATEPAINTTEX				= (1 << 14),			///< Does the same as without this flag but does not generate the textures from painted materials. @since R17.053
	ASSETLINKS_COPY_FILEASSETS	= (1 << 15),			///< copy file assets (assets://) to the tex folder
	ASSETLINKS_COPY_NODEASSETS	= (1 << 16),			///< copy node assets to the scene repository
} MAXON_ENUM_FLAGS(SAVEPROJECT);
/// @}

/// @addtogroup ICONDATAFLAGS
/// @ingroup group_enumeration
/// @{
/// @see IconData::flags
enum class ICONDATAFLAGS
{
	NONE							= 0,						///< None.
	APPLYCOLORPROFILE	= (1 << 0),			///< Apply color profile.
	DISABLED					= (1 << 1)			///< Disabled.
} MAXON_ENUM_FLAGS(ICONDATAFLAGS);
/// @}

/// @addtogroup USERAREAFLAGS
/// @ingroup group_enumeration
/// @{
enum class USERAREAFLAGS
{
	NONE				= (0),					///< None.
	TABSTOP			= (1 << 0),			///< Tab stop.
	HANDLEFOCUS	= (1 << 1),			///< Handles focus.
	COREMESSAGE	= (1 << 2),			///< Receives core messages.
															///< @see The article @link page_manual_coremessages Core Messages@endlink.
	SYNCMESSAGE	= (1 << 3),			///< Receives sync messages.
	DONT_MIRROR	= (1 << 30)			///< Do not mirror the user area.
} MAXON_ENUM_FLAGS(USERAREAFLAGS);
/// @}

/// @addtogroup RESOURCEIMAGE
/// @ingroup group_enumeration
/// @{
/// @C4D bitmap resource IDs.
#define RESOURCEIMAGE_EMPTY_TRI_RIGHT							310002010
#define RESOURCEIMAGE_RED_TRI_RIGHT								310002011
#define RESOURCEIMAGE_EMPTY_RED_TRI_RIGHT					310002012
#define RESOURCEIMAGE_YELLOW_DIAMOND							310002013
#define RESOURCEIMAGE_YELLOW_TRI_RIGHT						310002014
#define RESOURCEIMAGE_YELLOW_TRI_LEFT							310002015
#define RESOURCEIMAGE_EMPTY_YELLOW_DIAMOND				310002016
#define RESOURCEIMAGE_YELLOW_CIRCLE								310002017
#define RESOURCEIMAGE_EMPTY_YELLOW_CIRCLE					310002018
#define RESOURCEIMAGE_EMPTY_BLUE_CIRCLE						310002019
#define RESOURCEIMAGE_BLUE_CIRCLE									310002020
#define RESOURCEIMAGE_EMPTY_YELLOW_CIRCLE_LEFT		310002021
#define RESOURCEIMAGE_EMPTY_YELLOW_CIRCLE_RIGHT		310002022
#define RESOURCEIMAGE_EMPTY_TRI_LEFT							310002001
#define RESOURCEIMAGE_RED_TRI_LEFT								310002002
#define RESOURCEIMAGE_EMPTY_RED_TRI_LEFT					310002003
#define RESOURCEIMAGE_EMPTY_DIAMOND								310002004
#define RESOURCEIMAGE_RED_DIAMOND									310002005
#define RESOURCEIMAGE_EMPTY_RED_DIAMOND						310002006
#define RESOURCEIMAGE_EMPTY_CIRCLE								200000122
#define RESOURCEIMAGE_RED_CIRCLE									300000121
#define RESOURCEIMAGE_EMPTY_RED_CIRCLE						300000122
#define RESOURCEIMAGE_KEYFRAME_BUTTON_UP					440000141
#define RESOURCEIMAGE_KEYFRAME_BUTTON_OVER				440000142
#define RESOURCEIMAGE_KEYFRAME_BUTTON_DOWN				440000143
#define RESOURCEIMAGE_KEYFRAME_BUTTON_EDGE				440000178
#define RESOURCEIMAGE_PIN													9000
#define RESOURCEIMAGE_SUBGROUP										12678
#define RESOURCEIMAGE_UNLOCKED										12679
#define RESOURCEIMAGE_LOCKED											-12679
#define RESOURCEIMAGE_HISTOGRAM										12680
#define RESOURCEIMAGE_PLUS												300000118
#define RESOURCEIMAGE_MINUS												300000119
#define RESOURCEIMAGE_FOLDER											300000123
#define RESOURCEIMAGE_OPENED											300000124
#define RESOURCEIMAGE_CLOSED											300000125
#define RESOURCEIMAGE_ARROWLEFT										300000126
#define RESOURCEIMAGE_ARROWRIGHT									300000127
#define RESOURCEIMAGE_ARROWUP											300000128
#define RESOURCEIMAGE_AMDUPLICATE									300000129
#define RESOURCEIMAGE_MOVE												13563
#define RESOURCEIMAGE_SCALE												13564
#define RESOURCEIMAGE_ROTATE											13565
#define RESOURCEIMAGE_VIEWCHANGE									13640
#define RESOURCEIMAGE_FULLSCREEN									17301
#define RESOURCEIMAGE_CLOSERRELEASED							12097
#define RESOURCEIMAGE_CLOSERPRESSED								-12097
#define RESOURCEIMAGE_CANCEL											300000130
#define RESOURCEIMAGE_OK													300000131
#define RESOURCEIMAGE_OKCANCEL										300000132
#define RESOURCEIMAGE_BOOLGROUP										300000133
#define RESOURCEIMAGE_ADAPTERGROUP								300000134
#define RESOURCEIMAGE_CALCULATEGROUP							300000135
#define RESOURCEIMAGE_DEFAULTGROUP								300000136
#define RESOURCEIMAGE_DEFAULTOPERATOR							300000137
#define RESOURCEIMAGE_GENERALGROUP								300000138
#define RESOURCEIMAGE_ITERATORGROUP								300000139
#define RESOURCEIMAGE_LOGICALGROUP								300000140
#define RESOURCEIMAGE_TPGROUP											300000141
#define RESOURCEIMAGE_COFFEESCRIPT								300000142
#define RESOURCEIMAGE_PYTHONSCRIPT								1022749
#define RESOURCEIMAGE_UVWTAG_SECONDSTATE					300000143
#define RESOURCEIMAGE_INSTANCEOBJECT_SECONDSTATE	300000144
#define RESOURCEIMAGE_LIGHT_SHADOWS								300000145
#define RESOURCEIMAGE_LIGHT_SPOT									300000146
#define RESOURCEIMAGE_LIGHT_SPOTSHADOWS						300000147
#define RESOURCEIMAGE_LIGHT_PARALLEL							300000148
#define RESOURCEIMAGE_LIGHT_PARALLELSHADOWS				300000149
#define RESOURCEIMAGE_LIGHT_AREA									300000150
#define RESOURCEIMAGE_LIGHT_AREASHADOWS						300000151
#define RESOURCEIMAGE_BASEDRAW										300000152
#define RESOURCEIMAGE_CTRACK											300000153
#define RESOURCEIMAGE_BASEKEY											300000154
#define RESOURCEIMAGE_BASESEQUENCE								300000155
#define RESOURCEIMAGE_BASETRACK										300000156
#define RESOURCEIMAGE_UNKNOWN											300000157
#define RESOURCEIMAGE_BASESHADER									300000158
#define RESOURCEIMAGE_PAINTBITMAP									300000159
#define RESOURCEIMAGE_MULTIPLE										300000160
#define RESOURCEIMAGE_EYEACTIVE										300000161
#define RESOURCEIMAGE_EYEINACTIVE									300000162
#define RESOURCEIMAGE_PENACTIVE										300000163
#define RESOURCEIMAGE_PENINACTIVE									300000164
#define RESOURCEIMAGE_ALPHAACTIVE									300000165
#define RESOURCEIMAGE_ALPHAINACTIVE								300000166
#define RESOURCEIMAGE_LINKEDACTIVE								300000167
#define RESOURCEIMAGE_LINKEDINACTIVE							300000168
#define RESOURCEIMAGE_BPAXIS											300000169
#define RESOURCEIMAGE_BPCROSSED										300000170
#define RESOURCEIMAGE_MOCCATREEVIEWNO							300000171
#define RESOURCEIMAGE_MOCCATREEVIEWYES						300000172
#define RESOURCEIMAGE_MOCCATREEVIEWLOCKED					300000173
#define RESOURCEIMAGE_MOCCAIKTAG1									300000174
#define RESOURCEIMAGE_MOCCAIKTAG2									300000175
#define RESOURCEIMAGE_MOCCAIKTAG3									300000176
#define RESOURCEIMAGE_MOCCAIKTAG4									300000177
#define RESOURCEIMAGE_MOCCAIKTAG5									300000178
#define RESOURCEIMAGE_MOCCAIKTAG6									300000185
#define RESOURCEIMAGE_BITMAPFILTERPLUS						300000179
#define RESOURCEIMAGE_BITMAPFILTERMINUS						300000180
#define RESOURCEIMAGE_CLOTHING1										300000181
#define RESOURCEIMAGE_CLOTHING2										300000182
#define RESOURCEIMAGE_CLOTHING3										300000183
#define RESOURCEIMAGE_CLOTHING4										300000184
#define RESOURCEIMAGE_CLEARSELECTION							300000187
#define RESOURCEIMAGE_GENERICCOMMAND							300000188
#define RESOURCEIMAGE_TIMELINE_KEY1								300000191
#define RESOURCEIMAGE_TIMELINE_KEY2								300000192
#define RESOURCEIMAGE_AMMODELOCK_1								300000193
#define RESOURCEIMAGE_AMMODELOCK_2								300000194
#define RESOURCEIMAGE_SCENEBROWSER_HOME						300000195
#define RESOURCEIMAGE_SCENEBROWSER_FILTER1				300000196
#define RESOURCEIMAGE_SCENEBROWSER_FILTER2				300000197
#define RESOURCEIMAGE_SCENEBROWSER_FIND1					300000198
#define RESOURCEIMAGE_SCENEBROWSER_FIND2					300000199
#define RESOURCEIMAGE_SCENEBROWSER_PATH1					300000200
#define RESOURCEIMAGE_SCENEBROWSER_PATH2					300000201
#define RESOURCEIMAGE_TIMELINE_STATE1							300000202
#define RESOURCEIMAGE_TIMELINE_STATE2							300000203
#define RESOURCEIMAGE_TIMELINE_STATE3							300000204
#define RESOURCEIMAGE_TIMELINE_STATE4							300000205
#define RESOURCEIMAGE_TIMELINE_STATE5							300000206
#define RESOURCEIMAGE_TIMELINE_STATE6							300000207
#define RESOURCEIMAGE_TIMELINE_KEYSTATE1					300000208
#define RESOURCEIMAGE_TIMELINE_KEYSTATE2					300000209
#define RESOURCEIMAGE_TIMELINE_KEYSTATE3					300000210
#define RESOURCEIMAGE_TIMELINE_KEYSTATE4					300000211
#define RESOURCEIMAGE_LAYERMANAGER_STATE1					300000212
#define RESOURCEIMAGE_LAYERMANAGER_STATE2					300000213
#define RESOURCEIMAGE_LAYERMANAGER_STATE3					300000214
#define RESOURCEIMAGE_LAYERMANAGER_STATE4					300000215
#define RESOURCEIMAGE_LAYERMANAGER_STATE5					300000216
#define RESOURCEIMAGE_LAYERMANAGER_STATE6					300000217
#define RESOURCEIMAGE_LAYERMANAGER_STATE7					300000218
#define RESOURCEIMAGE_LAYERMANAGER_STATE8					300000219
#define RESOURCEIMAGE_LAYERMANAGER_STATE9					300000220
#define RESOURCEIMAGE_LAYERMANAGER_STATE10				300000221
#define RESOURCEIMAGE_LAYERMANAGER_STATE11				300000222
#define RESOURCEIMAGE_LAYERMANAGER_STATE12				300000223
#define RESOURCEIMAGE_LAYERMANAGER_STATE13				300000224
#define RESOURCEIMAGE_LAYERMANAGER_STATE14				300000225
#define RESOURCEIMAGE_LAYERMANAGER_STATE15				300000226
#define RESOURCEIMAGE_LAYERMANAGER_STATE16				300000227
#define RESOURCEIMAGE_LAYERMANAGER_STATE17				300000228
#define RESOURCEIMAGE_LAYERMANAGER_STATE18				300000229
#define RESOURCEIMAGE_OBJECTMANAGER_STATE1				300000230
#define RESOURCEIMAGE_OBJECTMANAGER_STATE2				300000231
#define RESOURCEIMAGE_OBJECTMANAGER_STATE3				300000232
#define RESOURCEIMAGE_OBJECTMANAGER_STATE4				300000233
#define RESOURCEIMAGE_OBJECTMANAGER_DOT1					300000234
#define RESOURCEIMAGE_OBJECTMANAGER_DOT2					300000235
#define RESOURCEIMAGE_OBJECTMANAGER_DOT3					300000236
#define RESOURCEIMAGE_OBJECTMANAGER_DOT4					300000237
#define RESOURCEIMAGE_OBJECTMANAGER_LOCK					300000238
#define RESOURCEIMAGE_TIMELINE_FOLDER1						300000239
#define RESOURCEIMAGE_TIMELINE_FOLDER2						300000240
#define RESOURCEIMAGE_TIMELINE_FOLDER3						300000241
#define RESOURCEIMAGE_TIMELINE_FOLDER4						300000242
#define RESOURCEIMAGE_TIMELINE_ROOT1							300000243
#define RESOURCEIMAGE_TIMELINE_ROOT2							300000244
#define RESOURCEIMAGE_TIMELINE_ROOT3							300000245
#define RESOURCEIMAGE_OBJECTMANAGER_DISP1					300000246
#define RESOURCEIMAGE_OBJECTMANAGER_DISP2					300000247
#define RESOURCEIMAGE_OBJECTMANAGER_DISP3					300000248
#define RESOURCEIMAGE_OBJECTMANAGER_DISP4					300000249
#define RESOURCEIMAGE_BROWSER_DESKTOP							300000251
#define RESOURCEIMAGE_BROWSER_HOME								300000252
#define RESOURCEIMAGE_BROWSER_PRESET							300000253
#define RESOURCEIMAGE_BROWSER_CATALOG							300000254
#define RESOURCEIMAGE_BROWSER_SEARCH							300000255
#define RESOURCEIMAGE_BROWSER_PLAY								300000256
#define RESOURCEIMAGE_BROWSER_PAUSE								300000257
#define RESOURCEIMAGE_BROWSER_SMALLVIEW						300000258
#define RESOURCEIMAGE_BROWSER_BIGVIEW							300000259
#define RESOURCEIMAGE_ONLINEHELP_HOME							300000260
#define RESOURCEIMAGE_ARROWDOWN										300000263
#define RESOURCEIMAGE_EYETRISTATE									300000264
#define RESOURCEIMAGE_PREVIOUSPAGE								1022433
#define RESOURCEIMAGE_FOLLOWINGPAGE								1022434
#define RESOURCEIMAGE_LIGHT_PHOTOMETRIC						300000265
#define RESOURCEIMAGE_LIGHT_PHOTOMETRICSHADOWS		300000266
#define RESOURCEIMAGE_MENU_OPTIONS								200000283
#define RESOURCEIMAGE_PICKSESSION									200000270
#define RESOURCEIMAGE_PICKSESSION2								200000271
#define HOTKEY_RESIZE_BRUSH												440000144
#define RESOURCEIMAGE_LAYERMANAGER_STATE19				1028287
#define RESOURCEIMAGE_LAYERMANAGER_STATE20				1028288
/// @}

#ifndef __API_INTERN__

	/// @addtogroup HOTKEY
	/// @ingroup group_enumeration
	/// @{
	#define HOTKEY_CAMERA_MOVE		13563				///< Camera move.
	#define HOTKEY_CAMERA_SCALE		13564				///< Camera scale.
	#define HOTKEY_CAMERA_ROTATE	13565				///< Camera rotate.

	#define HOTKEY_OBJECT_MOVE		13566				///< Object move.
	#define HOTKEY_OBJECT_SCALE		13567				///< Object scale.
	#define HOTKEY_OBJECT_ROTATE	13568				///< Object rotate.

	#define HOTKEY_MODEL_SCALE	13569					///< Model scale.
	#define HOTKEY_ZOOM					13570					///< Zoom.
	#define HOTKEY_SELECT_FREE	13571					///< Freehand selection.
	#define HOTKEY_SELECT_LIVE	13572					///< Live selection.
	#define HOTKEY_SELECT_RECT	13573					///< Rectangle selection.

	#define HOTKEY_PARENT_MOVE 440000088			///< Parent object move.
	/// @}

	/// @addtogroup IDM
	/// @ingroup group_enumeration
	/// @{
	#define IDM_UNDO				12105			///< Undo.
	#define IDM_REDO				12297			///< Redo.
	#define IDM_CUT					12106			///< Cut.
	#define IDM_COPY				12107			///< Copy.
	#define IDM_PASTE				12108			///< Paste.
	#define IDM_DELETE			12109			///< Delete.
	#define IDM_SELECTALL		12112			///< Select all.
	#define IDM_SELECTNONE	12113			///< Select none.
	#define IDM_INVERSION		12374			///< Invert selection.
	#define IDM_KEY_LAST		12415			///< Last key.
	#define IDM_KEY_NEXT		12416			///< Next key.
	/// @}

#endif

/// @addtogroup EXECUTIONPRIORITY
/// @ingroup group_enumeration
/// @{
/// Predefined calling points for objects, tags and scene hooks.
/// @see PriorityList::Add ObjectData::Execute TagData::Execute SceneHookData::Execute
#define EXECUTIONPRIORITY_INITIAL				1000				///< Initial.
#define EXECUTIONPRIORITY_ANIMATION			2000				///< Animation.
#define EXECUTIONPRIORITY_ANIMATION_NLA	2010				///< NLA.
#define EXECUTIONPRIORITY_EXPRESSION		3000				///< Expression.
#define EXECUTIONPRIORITY_DYNAMICS			4000				///< Dynamics.
#define EXECUTIONPRIORITY_GENERATOR			5000				///< Generators.
#define EXECUTIONPRIORITY_SCENENODE			10000				///<  Scene nodes.
#define EXECUTIONPRIORITY_FORCE					2147483647	///< Highest priority that will ensure execution even if the execution pipeline is cancelled before. Only use this to e.g. release locks or do super-fast non-blocking operations.
/// @}

/// @addtogroup EXECUTIONRESULT
/// @ingroup group_enumeration
/// @{
/// Predefined result codes for objects, tags and scene hooks execution.
/// @see ObjectData::Execute TagData::Execute SceneHookData::Execute
enum class EXECUTIONRESULT
{
	OK					= 0,			///< OK.
	USERBREAK		= 1,			///< %User break.
	OUTOFMEMORY	= 2				///< Not enough memory.
} MAXON_ENUM_LIST(EXECUTIONRESULT);
/// @}

/// @addtogroup DLG
/// @ingroup group_enumeration
/// @{
enum
{
	DLG_OK			= 1,			///< OK button.
	DLG_CANCEL	= 2			///< Cancel button.
};
/// @}

/// @addtogroup IMAGERESULT
/// @ingroup group_enumeration
/// @{
/// Result codes for image initialization, open, save etc.
enum class IMAGERESULT
{
	OK							=  1,		///< Image loaded/created.
	NOTEXISTING			= -1,		///< Image does not exist.
	WRONGTYPE				= -2,		///< Image has the wrong type.
	OUTOFMEMORY			= -3,		///< Not enough memory.
	FILEERROR				= -4,		///< File error.
	FILESTRUCTURE		= -5,		///< Invalid file structure.
	MISC_ERROR			= -6,		///< Unknown error.
	PARAM_ERROR			= -7,		///< Parameter error.
	THREADCANCELED	= -8		///< Thread canceled while working.
} MAXON_ENUM_LIST(IMAGERESULT);
/// @}

/// @addtogroup STRINGENCODING
/// @ingroup group_enumeration
/// @{
enum class STRINGENCODING
{
	XBIT			= 0,		///< An OS dependent encoding. Only use this if data is passed to an OS functions. The actual coding is unspecified.
										///< @note Previously it has been said that this encoding is @em UTF-8. That is not true.
										///< 	BIT8			= 1,		<i>8</i>-bit ASCII. Discards Unicode information.
	BIT7			= 2,		///< <i>7</i>-bit ASCII. Does not understand any international characters, e.g. \"&aring;&auml;&uuml;&ouml;\".
	BIT7HEX		= 3,		///< <i>7</i>-bit ASCII, with any non <i>7</i>-bit characters encoded in the text as e.g. "\uEFA0".
	UTF8			= 4			///< UTF-<i>8</i> encoding.
										///< HTML			= 5, HTML encoding.
} MAXON_ENUM_LIST(STRINGENCODING);
/// @}

/// @addtogroup THREADMODE
/// @ingroup group_enumeration
/// @{
enum class THREADMODE
{
	DEPRECATED_SYNCHRONOUS	= 0,			///< Synchronous thread. @markDeprecated
	ASYNC										= 1,			///< Asynchronous thread.
	PRIVATE_OPENGL					= 3				///< @markPrivate @since R18
} MAXON_ENUM_LIST(THREADMODE);
/// @}

/// @addtogroup THREADPRIORITYEX
/// @ingroup group_enumeration
/// @{
enum class THREADPRIORITYEX
{
	NORMAL	= 0,				///< Normal.
	ABOVE	= 1000,			///< Above.
	BELOW	= 1001,			///< Below.
	LOWEST	= 1002			///< Lowest.
} MAXON_ENUM_LIST(THREADPRIORITYEX);
/// @}

/// @addtogroup HYPERFILEARRAY
/// @ingroup group_enumeration
/// @{
enum class HYPERFILEARRAY
{
	CHAR	= 1,			///< ::Char array.
	WORD	= 2,			///< ::Int16 array.
	LONG	= 3,			///< ::Int32 array.
	LLONG	= 4,			///< ::Int64 array.
	SREAL	= 5,			///< ::Float32 array.
	LREAL	= 6,			///< ::Float64 array.
	REAL	= 7				///< ::Float array.
} MAXON_ENUM_LIST(HYPERFILEARRAY);
/// @}

/// @addtogroup FILEERROR
/// @ingroup group_enumeration
/// @{
enum class FILEERROR
{
	NONE				=  0,			///< No error.
	OPEN				= -1,			///< Problems opening the file.
	CLOSE				= -2,			///< Problems closing the file.
	READ				= -3,			///< Problems reading the file.
	WRITE				= -4,			///< Problems writing the file.
	SEEK				= -5,			///< Problems seeking the file.
	INVALID			= -6,			///< Invalid parameter or operation (e.g. writing in read-mode).
	OUTOFMEMORY	= -7,			///< Not enough memory.
	USERBREAK		= -8,			///< %User break.

	// The following errors can only occur with an HyperFile
	WRONG_VALUE			= -100,			///< Other value detected than expected.
	CHUNK_NUMBER		= -102,			///< Wrong number of chunks or sub-chunks detected.
	VALUE_NO_CHUNK	= -103,			///< There was a value without any enclosing START/STOP chunks.
	FILEEND					= -104,			///< The file end was reached without finishing reading.
	UNKNOWN_VALUE		= -105			///< Unknown value detected.
} MAXON_ENUM_LIST(FILEERROR);
/// @}

/// @addtogroup FILEOPEN
/// @ingroup group_enumeration
/// @{
enum class FILEOPEN
{
	APPEND				= 0,		///< Open an existing file for writing and set the position to the end of that file.
	READ					= 1,		///< Open the file for reading.
	WRITE					= 2,		///< Create a new file for writing.\n
												///< @warning If the file name points to an existing file, it will be overwritten.
	READWRITE			= 3,		///< Open the file for both reading and writing.
	READ_NOCACHE	= 4,		///< @markPrivate
	SHAREDREAD		= 5,		///< @markPrivate
	SHAREDWRITE		= 6			///< @markPrivate
} MAXON_ENUM_LIST(FILEOPEN);
/// @}

/// @addtogroup LOCATION
/// @ingroup group_enumeration
/// @{
enum class LOCATION
{
	DISK					= 1,			///< Disk storage.
	IPCONNECTION	= 2,			///< Target is IP connection.
	MEMORY				= 3				///< Target is a memory location.
} MAXON_ENUM_LIST(LOCATION);
/// @}

/// @addtogroup FILESEEK
/// @ingroup group_enumeration
/// @{
enum class FILESEEK
{
	START			= 0,			///< The position is given relative to the start of the file.
	RELATIVE_	= 2				///< The position is given relative to the current position.
} MAXON_ENUM_LIST(FILESEEK);
/// @}

/// @addtogroup FILEDIALOG
/// @ingroup group_enumeration
/// @{
enum class FILEDIALOG
{
	NONE				= 0,			///< Never show an error dialog.
	ANY					= 1,			///< Show an error dialog for any error.
	IGNOREOPEN	= 2				///< Do not show an error dialog if the file does not exist, otherwise like @ref FILEDIALOG::ANY.
} MAXON_ENUM_LIST(FILEDIALOG);
/// @}

/// @addtogroup FILESELECT
/// @ingroup group_enumeration
/// @{
enum class FILESELECT
{
	LOAD				= 0,			///< Load dialog.
	SAVE				= 1,			///< Save dialog.
	DIRECTORY	= 2				///< Folder selection dialog.
} MAXON_ENUM_LIST(FILESELECT);
/// @}

/// @addtogroup FILESELECTTYPE
/// @ingroup group_enumeration
/// @{
enum class FILESELECTTYPE
{
	ANYTHING		= 0,			///< Any file.
	IMAGES			= 1,			///< Image files.
	SCENES			= 2,			///< 3D scene files.
	BODYPAINT		= 4				///< @BP3D files.
} MAXON_ENUM_LIST(FILESELECTTYPE);
/// @}

/// @addtogroup OPERATINGSYSTEM
/// @ingroup group_enumeration
/// @{
enum class OPERATINGSYSTEM
{
	WIN		= 1,			///< Windows.
	OSX		= 2,			///< OS X.
	LINUX	= 3,			///< Linux.
	_IOS 	= 4				///< iOS.
} MAXON_ENUM_LIST(OPERATINGSYSTEM);
/// @}

/// @addtogroup BYTEORDER
/// @ingroup group_enumeration
/// @{
enum class BYTEORDER
{
	// V_ unfortunately has to be used here due to conflicts with MAC OS
	V_MOTOROLA	= 1,			///< Motorola, big endian.
	V_INTEL			= 2				///< Intel, little endian.
} MAXON_ENUM_LIST(BYTEORDER);
/// @}

/// @addtogroup HYPERFILEVALUE
/// @ingroup group_enumeration
/// @{
enum class HYPERFILEVALUE
{
	NONE								=  0,			///< None.

	START								=  1,			///< Marks the start of a chunk.
	STOP								=  2,			///< Marks the end of a chunk.
	CSTOP								=  3,			///< Marks the end of a container. @markInternal
	CHAR								= 11,			///< ::Char.
	UCHAR								= 12,			///< ::UChar.
	INT16								= 13,			///< ::Int16.
	UINT16							= 14,			///< ::UInt16.
	INT32								= 15,			///< ::Int32.
	UINT32							= 16,			///< ::UInt32.
	INT64								= 17,			///< ::Int64.
	UINT64							= 18,			///< ::UInt64.
	FLOAT								= 19,			///< ::Float.
	FLOAT64							= 20,			///< ::Float64.
	BOOLEAN							= 21,			///< ::Bool.
	TIME								= 22,			///< BaseTime.
	VECTOR							= 23,			///< ::Vector.
	VECTOR64						= 24,			///< ::Vector64.
	MATRIX							= 25,			///< ::Matrix.
	MATRIX64						= 26,			///< ::Matrix64.
	VECTOR32						= 27,			///< ::Vector32.
	MATRIX32						= 28,			///< ::Matrix32.
	FLOAT32							= 29,			///< ::Float32.

	MEMORY							= 128,			///< Memory.
	IMAGE								= 129,			///< Image.
	STRING							= 130,			///< String.
	FILENAME						= 131,			///< Filename.
	CONTAINER						= 132,			///< BaseContainer.
	ALIASLINK						= 138,			///< BaseLink.
	LMEMORY							= 139,			///< Long memory.
	VECTOR_ARRAY_EX			= 133,			///< @markDeprecated
	POLYGON_ARRAY_EX		= 134,			///< @markDeprecated
	UINT16_ARRAY_EX			= 135,			///< @markDeprecated
	PARTICLE_ARRAY_EX		= 136,			///< @markDeprecated
	SREAL_ARRAY_EX			= 137,			///< @markDeprecated
	ARRAY								= 140,			///< Array.
	UUID								= 141				///< C4DUuid.
} MAXON_ENUM_LIST(HYPERFILEVALUE);
/// @}

/// @addtogroup FINDANIM
/// @ingroup group_enumeration
/// @{
enum class FINDANIM
{
	EXACT	= 0,			///< Exact.
	LEFT	= 1,			///< Search left.
	RIGHT	= 2				///< Search right.
} MAXON_ENUM_LIST(FINDANIM);
/// @}

/// @addtogroup CCURVE
/// @ingroup group_enumeration
/// @{
enum class CCURVE
{
	CURVE			= 1,			///< Standard curve.
	HLE_BASE		= 2,			///< Internal reduced modification reference curve.
	HLE_CURVE	= 3,			///< Reduced Modification Curve - Curve.
	SS_CURVE		= 4,			///< Snapshot 1.

	// Multiple Snapshots
	SS_CURVE2	= 5,			///< Snapshot 2.
	SS_CURVE3	= 6,			///< Snapshot 3.
	SS_CURVE4	= 7,			///< Snapshot 4.
	SS_CURVE5	= 8,			///< Snapshot 5.

	// Scale and Move HLE Curve
	HLE_SCALE	= 9,			///< Reduced modification curve - scale.
	HLE_MOVE		= 10			///< Reduced modification curve - move.
} MAXON_ENUM_LIST(CCURVE);
/// @}

/// @addtogroup CLOOP
/// @ingroup group_enumeration
/// @{
enum class CLOOP
{
	OFF						= 0,			///< No loop.
	CONSTANT			= 1,			///< Constant.
	CONTINUE			= 2,			///< Continue.
	REPEAT				= 3,			///< Repeat.
	OFFSETREPEAT	= 4,			///< Offset repeat.
	OSCILLATE			= 5,			///< Oscillate.
	LOOP					= 6				///< Loop.
} MAXON_ENUM_LIST(CLOOP);
/// @}

/// @addtogroup CINTERPOLATION
/// @ingroup group_enumeration
/// @{
enum class CINTERPOLATION : UChar
{
	SPLINE	= 1,			///< Spline.
	LINEAR	= 2,			///< Linear.
	STEP		= 3,			///< Step.

	DUMMY		= 4
} MAXON_ENUM_LIST(CINTERPOLATION);
/// @}

/// @addtogroup CAUTOMODE
/// @ingroup group_enumeration
/// @{
/// @since R17.032
enum class CAUTOMODE : UChar
{
	CLASSIC			= 1,				///< AutoTangent first implementation.
	FIXEDSLOPE	= 2,				///< AutoTangent with fixed slope for given time.
} MAXON_ENUM_LIST(CAUTOMODE);
/// @}

/// @addtogroup CKEYPRESET
/// @ingroup group_enumeration
/// @{
/// @since R17.032
enum class CKEYPRESET
{
	AUTO_CLAMP										= 1,			///< Auto, Auto Angle, Clamp.
	AUTO_OVERSHOOT								= 2,			///< Auto, Auto Angle, remove Overshooting.
	FIXED_OVERSHOOTWEIGHTED				= 3,			///< Auto, Fixed Angle, remove Overshooting, weighted.
	CUSTOM												= 4,			///< User Defined.
	AUTO_OVERSHOOTWEIGHTED				= 5,			///< Auto, Auto Angle, remove Overshooting, weighted.
} MAXON_ENUM_LIST(CKEYPRESET);
/// @}

/// @addtogroup CLIPBOARDTYPE
/// @ingroup group_enumeration
/// @{
enum class CLIPBOARDTYPE
{
	EMPTY		= 0,			///< Clipboard is empty.
	STRING	= 1,			///< Clipboard contains a string.
	BITMAP	= 2				///< Clipboard contains a bitmap.
} MAXON_ENUM_LIST(CLIPBOARDTYPE);
/// @}

/// @addtogroup EDGESELECTIONTYPE
/// @ingroup group_enumeration
/// @{
/// @see PolygonObject::GetSelectedEdges PolygonObject::SetSelectedEdges() PolygonObject::GetEdgeSelection
enum class EDGESELECTIONTYPE
{
	SELECTION	= 0,			///< Selected edges.
	HIDDEN		= 1,			///< Hidden edges.
	PHONG			= 2				///< Phong edges.
} MAXON_ENUM_LIST(EDGESELECTIONTYPE);
/// @}

/// @addtogroup REGISTRYTYPE
/// @ingroup group_enumeration
/// @{
enum class REGISTRYTYPE
{
	ANY							=  0,
	WINDOW					=  1,
	OBJECT					=  2,
	TAG							=  6,
	MATERIAL				=  7,
	SHADER					=  8,
	SOUND						= 10,
	LAYOUT					= 11,
	BITMAPFILTER		= 12,
	VIDEOPOST				= 13,
	SCENEHOOK				= 14,
	NODE						= 15,
	DESCRIPTION			= 16,
	LIBRARY					= 17,
	CUSTOMDATATYPE	= 18,
	RESOURCEDATATYPE = 19,
	SCENELOADER			= 20,
	SCENESAVER			= 21,
	CTRACK					= 23,
	CSEQ						= 24,
	CKEY						= 25,
	PAINTER					= 26,
	GV_VALUE				= 27,
	GV_VALGROUP			= 28,
	GV_OPGROUP			= 29,
	GV_OPCLASS			= 30,
	GV_DATA					= 31,
	GADGETS					= 32,
	PREFS						= 33,
	FIELDLAYER				= 34
} MAXON_ENUM_LIST(REGISTRYTYPE);
/// @}

/// @addtogroup MODELINGCOMMANDMODE
/// @ingroup group_enumeration
/// @{
enum class MODELINGCOMMANDMODE
{
	ALL								= 0,			///< All points/polygons.
	POINTSELECTION		= 1,			///< Only the current point selection.
	POLYGONSELECTION	= 2,			///< Only the current polygon selection.
	EDGESELECTION			= 3				///< Only the current edge selection.
} MAXON_ENUM_LIST(MODELINGCOMMANDMODE);
/// @}

/// @addtogroup MODELINGCOMMANDFLAGS
/// @ingroup group_enumeration
/// @{
enum class MODELINGCOMMANDFLAGS
{
	NONE								= 0,						///< None.
	CREATEUNDO					= (1 << 0),			///< Creates undo and inserts newly created objects into ModelingCommandData::doc, instead of returning in ModelingCommandData::result.
	IMPORTER						= (1 << 1),			///< Can be used by importer plugins to avoid additional checks for polygon meshes (e.g conversion of posemorph tags).
	USEGLOBALSYMMETRY		= (1 << 2)			///< Set to let the command to recieve the symmetry settings from the global context.
} MAXON_ENUM_FLAGS(MODELINGCOMMANDFLAGS);
/// @}

/// @addtogroup PLUGINTYPE
/// @ingroup group_enumeration
/// @{
enum class PLUGINTYPE
{
	ANY									=  0,			///< Any type.

	SHADER							=  1,			///< 2D shader. (ShaderData)
	MATERIAL						=  2,			///< 3D shader. (MaterialData)
	COMMAND							=  4,			///< Command. (CommandData)
	OBJECT							=  5,			///< Object. (ObjectData)
	TAG									=  6,			///< Tag. (TagData)
	BITMAPFILTER				=  7,			///< Bitmap filter. (BitmapLoaderData, BitmapSaverData)
	VIDEOPOST						=  8,			///< Videopost effect. (VideoPostData)
	TOOL								=  9,			///< Tool. (ToolData)
	SCENEHOOK						= 10,			///< Scene hook. (SceneHookData)
	NODE								= 11,			///< Node. (NodeData)
	LIBRARY							= 12,			///< Library. (C4DLibrary)
	BITMAPLOADER				= 13,			///< Bitmap loader. (BitmapLoaderData)
	BITMAPSAVER					= 14,			///< Bitmap saver. (BitmapSaverData)
	SCENELOADER					= 15,			///< Scene loader. (SceneLoaderData)
	SCENESAVER					= 16,			///< Scene saver. (SceneSaverData)
	COREMESSAGE					= 17,			///< Core message.
	CUSTOMGUI						= 18,			///< Custom GUI. (CustomGuiData)
	CUSTOMDATATYPE			= 19,			///< Custom datatype. (CustomDataTypeClass)
	RESOURCEDATATYPE		= 20,			///< Resource datatype.
	MANAGERINFORMATION	= 21,			///< Manager information.
	CTRACK							= 32,			///< Track. (CTrackData)
	FALLOFF							= 33,			///< Falloff. (FalloffData)
	VMAPTRANSFER				= 34,			///< Used by VAMP. @markPrivate
	PREFS								= 35,			///< Preference hook. (PrefsDialogObject)
	SNAP								= 36,			///< Snap. (SnapData)
	FIELDLAYER					= 37,			///< FieldLayer. (FieldLayer)
	DESCRIPTION         = 38,     ///< Description (not in registry)
} MAXON_ENUM_LIST(PLUGINTYPE);
/// @}

/// @addtogroup DRAWRESULT
/// @ingroup group_enumeration
/// @{
enum class DRAWRESULT
{
	FAILURE	= 0,			///< There was an error while drawing.
	OK			= 1,			///< Something was drawn.
	SKIP		= 2				///< There was nothing to draw in this pass.
} MAXON_ENUM_LIST(DRAWRESULT);
/// @}

/// @addtogroup DISPLAYMODE
/// @ingroup group_enumeration
/// @{
enum class DISPLAYMODE
{
	UNKNOWN					= -1,			///< Unknown.
	GOURAUD					= 0,			///< Gouraud shading.
	QUICK						= 1,			///< Quick shading.
	WIRE						= 2,			///< Wireframe.
	ISOPARM					= 3,			///< Isoparm.
	SHADEDBOX				= 4,			///< Shaded box.
	BOX							= 5,			///< Box.
	SKELETON				= 6,			///< Skeleton.
	GOURAUDWIRE			= 7,			///< Gouraud wireframe.
	GOURAUDISOPARM	= 8,			///< Gouraud isoparm.
	QUICKWIRE				= 9,			///< Quick wireframe.
	QUICKISOPARM		= 10,			///< Quick isoparm.
	FLATWIRE				= 11,			///< Flat wireframe.
	FLATISOPARM			= 12,			///< Flat isoparm.
	FLATBOX					= 13,			///< Flat box.
	HIDDENWIRE			= 14,			///< Hidden line wireframe.
	HIDDENISOPARM		= 15,			///< Hidden line isoparm.
	HIDDENBOX				= 16,			///< Hidden line box.
	SHADEDBOXWIRE		= 17,			///< Shaded box wireframe.
	QUICKBOXWIRE		= 18,			///< Quick shaded box wireframe.
	QUICKBOX				= 19,			///< Quick shaded box.

	PRIVATE_ISOLINE	= 100,			///< @markPrivate
	PRIVATE_FLAT		= 1100,			///< @markPrivate
	PRIVATE_HIDDEN	= 1400			///< @markPrivate
} MAXON_ENUM_LIST(DISPLAYMODE);
/// @}

/// @addtogroup DOCUMENTSETTINGS
/// @ingroup group_enumeration
/// @{
/// Container IDs for the document settings.\n
/// The valid IDs are listed in @em ddoc.h (see @em ddoc.res for the container definition).
/// @see BaseDocument::GetData BaseDocument::SetData BaseDocument::GetSettingsInstance
enum class DOCUMENTSETTINGS
{
	GENERAL					= 0,			///< General settings.
	MODELING				= 1,			///< Modeler settings. (See @ref MDATA options.)
	DOCUMENT				= 2,			///< Document settings.
	ANIMATIONSYSTEM	= 7,			///< Timeline settings. @markPrivate
	TOOLS						= 8				///< Tools settings.
} MAXON_ENUM_LIST(DOCUMENTSETTINGS);
/// @}

/// @addtogroup VERSIONTYPE
/// @ingroup group_enumeration
/// @{
enum class VERSIONTYPE
{
	UNKNOWN						= 0,			///< Unknown version.

	LITE							= 1,			///< @C4D Lite. Lite is feature-restricted in many ways and does not allow for loading of plugins.
	BENCHMARK					= 2,			///< Cinebench. Cinebench is restricted to a subset of libraries.
	UPDATER_EX				= 3,			///< No longer used.

	TEAMRENDER_CLIENT	= 4,			///< @C4D Teamrender client.
	TEAMRENDER_SERVER	= 5,			///< @C4D Teamrender server.

	CINEMA4D					= 10,			///< @C4D Cinema 4D.

	COMMANDLINE				= 11,			///< Command line application. Note that this is different from GeGetCinemaInfo(CINEMAINFO::FORBID_GUI). The regular app can run without UI, but is not necessarily a special command line executable.

	CINEWARE					= 12,			///< Cineware - The renderer used in AfterEffects, Vectorworks, Archicad and Allplan. Runs without UI and does not allow for plugins. Since R23 it's also available as dynamic library.

	CPYTHON						= 14,			///< Python - The python executable. Runs without UI.
	CPYTHON3					= 15,			///< Python 3 - The python executable. Runs without UI. Unused, use CPYTHON to address c4dpy
} MAXON_ENUM_LIST(VERSIONTYPE);
/// @}

/// @addtogroup LAYERSETMODE
/// @ingroup group_enumeration
/// @{
enum class LAYERSETMODE
{
	LAYERS,					///< Layers / layer Sets.
	LAYERMASKS,			///< Layer masks.
	ALPHAS,					///< Alpha channels.
	LAYERALPHA,			///< Layer alpha.
	DISABLED				///< Disabled.
} MAXON_ENUM_LIST(LAYERSETMODE);
/// @}

#define ID_MT_SOURCECOUNTER	465001520			///< Int32 @markPrivate

/// Maximum number of global texture paths available.
#define MAX_GLOBAL_TEXTURE_PATHS 10

/// @addtogroup OBJECTCATEGORY
/// @ingroup group_enumeration
/// @{
enum class OBJECTCATEGORY
{
	NULLOBJECT					= 0,
	POLYGON							= 1,
	SPLINE							= 2,
	GENERATOR						= 3,
	HYPERNURBS					= 4,
	UNUSED1							= 5,
	DEFORMER						= 6,
	CAMERA							= 7,
	LIGHT								= 8,
	SCENE								= 9,
	PARTICLE						= 10,
	OTHER								= 11,
	UNUSED2							= 12,
	GRID								= 13,
	HORIZON							= 14,
	WORLDAXIS						= 15,
	BOUNDS							= 16,
	HUD									= 17,
	SDS									= 18,
	HIGHLIGHTING				= 19,
	MULTIAXIS						= 20,
	OBJECTHANDLES				= 21,
	HANDLEBANDS					= 22,
	SDSCAGE							= 23,
	NGONLINES						= 24,
	JOINT								= 25,
	OBJECTHIGHLIGHTING	= 26,
	GUIDELINES					= 27,
	POI									= 28,
	GRADIENT						= 29,
	BASEGRID						= 30,
	HANDLES							= 31,
	HAIR								= 32,
	FIELD								= 33
} MAXON_ENUM_LIST(OBJECTCATEGORY);
/// @}

/// @addtogroup SELECTIONFILTERBIT
/// @ingroup group_enumeration
/// @{
enum class SELECTIONFILTERBIT
{
	NONE				= 0,																					///< None.
	NULLOBJECT	= (1 << Int32(OBJECTCATEGORY::NULLOBJECT)),		///< Null.
	POLYGON			= (1 << Int32(OBJECTCATEGORY::POLYGON)),			///< Polygon.
	SPLINE			= (1 << Int32(OBJECTCATEGORY::SPLINE)),				///< Spline.
	GENERATOR		= (1 << Int32(OBJECTCATEGORY::GENERATOR)),		///< Generator.
	HYPERNURBS	= (1 << Int32(OBJECTCATEGORY::HYPERNURBS)),		///< Subdivision Surface.
	DEFORMER		= (1 << Int32(OBJECTCATEGORY::DEFORMER)),			///< Deformer.
	CAMERA			= (1 << Int32(OBJECTCATEGORY::CAMERA)),				///< Camera.
	LIGHT				= (1 << Int32(OBJECTCATEGORY::LIGHT)),				///< Light.
	SCENE				= (1 << Int32(OBJECTCATEGORY::SCENE)),				///< Scene.
	PARTICLE		= (1 << Int32(OBJECTCATEGORY::PARTICLE)),			///< Particle.
	OTHER				= (1 << Int32(OBJECTCATEGORY::OTHER)),				///< Other.
	JOINT				= (1 << Int32(OBJECTCATEGORY::JOINT))					///< Joint.
} MAXON_ENUM_FLAGS(SELECTIONFILTERBIT);
/// @}

/// @addtogroup OBJECTSTATE
/// @ingroup group_enumeration
/// @{
enum class OBJECTSTATE
{
	EDITOR							= 0,		///< Editor visibility.
	RENDER							= 1,		///< Renderer visibility.
	DEFORM							= 2,		///< Deform state.
	REAL_DEFORM					= 3,		///< Real Deform state (MODE_ON, MODE_OFF, MODE_UNKNOWN).
	EDITOR_HIERARCHICAL = 4,		///< Hierarchical editor mode (MODE_ON, MODE_OFF)
	RENDER_HIERARCHICAL	= 5,		///< Hierarchical render mode (MODE_ON, MODE_OFF)
} MAXON_ENUM_LIST(OBJECTSTATE);
/// @}

/// @addtogroup DISPLAYFILTER
/// @ingroup group_enumeration
/// @{
/// @see BaseDraw::GetDisplayFilter
/// @note ::DISPLAYFILTER::NULLOBJECT to ::DISPLAYFILTER::OTHER match @ref SELECTIONFILTERBIT.
enum class DISPLAYFILTER : UInt64
{
	NONE								= UInt64(0),																									///< None.
	NULLOBJECT					= (UInt64(1) << (UInt64)OBJECTCATEGORY::NULLOBJECT),					///< Null.
	POLYGON							= (UInt64(1) << (UInt64)OBJECTCATEGORY::POLYGON),							///< Polygon.
	SPLINE							= (UInt64(1) << (UInt64)OBJECTCATEGORY::SPLINE),							///< Spline.
	GENERATOR						= (UInt64(1) << (UInt64)OBJECTCATEGORY::GENERATOR),						///< Generator.
	HYPERNURBS					= (UInt64(1) << (UInt64)OBJECTCATEGORY::HYPERNURBS),					///< Subdivision Surface.
	UNUSED1							= (UInt64(1) << (UInt64)OBJECTCATEGORY::UNUSED1),							///< Unused.
	DEFORMER						= (UInt64(1) << (UInt64)OBJECTCATEGORY::DEFORMER),						///< Deformer.
	CAMERA							= (UInt64(1) << (UInt64)OBJECTCATEGORY::CAMERA),							///< Camera.
	LIGHT								= (UInt64(1) << (UInt64)OBJECTCATEGORY::LIGHT),								///< Light.
	SCENE								= (UInt64(1) << (UInt64)OBJECTCATEGORY::SCENE),								///< Scene.
	PARTICLE						= (UInt64(1) << (UInt64)OBJECTCATEGORY::PARTICLE),						///< %Particle.
	OTHER								= (UInt64(1) << (UInt64)OBJECTCATEGORY::OTHER),								///< Other.
	UNUSED2							= (UInt64(1) << (UInt64)OBJECTCATEGORY::UNUSED2),							///< Unused.
	GRID								= (UInt64(1) << (UInt64)OBJECTCATEGORY::GRID),								///< Grid.
	HORIZON							= (UInt64(1) << (UInt64)OBJECTCATEGORY::HORIZON),							///< Horizon.
	WORLDAXIS						= (UInt64(1) << (UInt64)OBJECTCATEGORY::WORLDAXIS),						///< World axis.
	BOUNDS							= (UInt64(1) << (UInt64)OBJECTCATEGORY::BOUNDS),							///< Bounding-box. @markDeprecated
	HUD									= (UInt64(1) << (UInt64)OBJECTCATEGORY::HUD),									///< HUD.
	SDS									= (UInt64(1) << (UInt64)OBJECTCATEGORY::SDS),									///< HN mesh.
	HIGHLIGHTING				= (UInt64(1) << (UInt64)OBJECTCATEGORY::HIGHLIGHTING),				///< Highlight select.
	MULTIAXIS						= (UInt64(1) << (UInt64)OBJECTCATEGORY::MULTIAXIS),						///< Multi-select axes.
	OBJECTHANDLES				= (UInt64(1) << (UInt64)OBJECTCATEGORY::OBJECTHANDLES),				///< Highlight handles.
	HANDLEBANDS					= (UInt64(1) << (UInt64)OBJECTCATEGORY::HANDLEBANDS),					///< Axis bands.
	SDSCAGE							= (UInt64(1) << (UInt64)OBJECTCATEGORY::SDSCAGE),							///< HN cage.
	NGONLINES						= (UInt64(1) << (UInt64)OBJECTCATEGORY::NGONLINES),						///< N-gon lines.
	JOINT								= (UInt64(1) << (UInt64)OBJECTCATEGORY::JOINT),								///< Joint objects.
	OBJECTHIGHLIGHTING	= (UInt64(1) << (UInt64)OBJECTCATEGORY::OBJECTHIGHLIGHTING),	///< @markPrivate
	GUIDELINES					= (UInt64(1) << (UInt64)OBJECTCATEGORY::GUIDELINES),					///< Axis guidelines.
	POI									= (UInt64(1) << (UInt64)OBJECTCATEGORY::POI),									///< Navigation cross.
	GRADIENT						= (UInt64(1) << (UInt64)OBJECTCATEGORY::GRADIENT),						///< %Gradient.
	BASEGRID						= (UInt64(1) << (UInt64)OBJECTCATEGORY::BASEGRID),						///< Base grid.
	HANDLES							= (UInt64(1) << (UInt64)OBJECTCATEGORY::HANDLES),							///< Handles.
	HAIR								= (UInt64(1) << (UInt64)OBJECTCATEGORY::HAIR),								///< Hair @since R22
	FIELD								= (UInt64(1) << (UInt64)OBJECTCATEGORY::FIELD)								///< Field @since R22
} MAXON_ENUM_FLAGS(DISPLAYFILTER);
/// @}

/// @addtogroup DISPLAYEDITSTATE
/// @ingroup group_enumeration
/// @{
/// @see BaseDraw::GetEditState
enum class DISPLAYEDITSTATE
{
	NONE			= 0,						///< None.
	SDS				= (1 << 0),			///< SDS edit state.
	DEFORM		= (1 << 1),			///< Deformed edit state.

	DOCUMENT	= -1			///< Document edit state.
} MAXON_ENUM_FLAGS(DISPLAYEDITSTATE);
/// @}

/// @addtogroup THREADTYPE
/// @ingroup group_enumeration
/// @{
enum class THREADTYPE
{
	NONE						= 0,						///< None.
	EDITORREDRAW		= (1 << 0),			///< Editor redraw.
	RENDEREDITOR		= (1 << 1),			///< Editor render.
	RENDEREXTERNAL	= (1 << 2)			///< External render.
} MAXON_ENUM_FLAGS(THREADTYPE);
/// @}

/// @addtogroup RENDERPROGRESSTYPE
/// @ingroup group_enumeration
/// @{
enum class RENDERPROGRESSTYPE
{
	BEFORERENDERING			= 0,			///< Before rendering.
	DURINGRENDERING			= 1,			///< During rendering.
	AFTERRENDERING			= 2,			///< After rendering.
	GLOBALILLUMINATION	= 3,			///< GI prepass.
	QUICK_PREVIEW				= 4,			///< Quick Preview rendering. @since R17.048
	AMBIENTOCCLUSION		= 5,			///< AO prepass. @since CR17.054 / R18.021
	CANCELLED						= 6				///< Rendering cancelled. @since R2024
} MAXON_ENUM_LIST(RENDERPROGRESSTYPE);
/// @}

/// @addtogroup RDATA_SAVECALLBACK_CMD
/// @ingroup group_enumeration
/// @{
enum class RDATA_SAVECALLBACK_CMD
{
	OPEN	= 1,			///< Open call.
	WRITE	= 2,			///< Write call.
	CLOSE	= 3				///< Close call.
} MAXON_ENUM_LIST(RDATA_SAVECALLBACK_CMD);
/// @}

/// @addtogroup VPGETINFO
/// @ingroup group_enumeration
/// @{
enum class VPGETINFO
{
	XRESOLUTION	= 0,			///< X resolution.
	YRESOLUTION	= 1,			///< Y resolution.
	BITDEPTH		= 2,			///< Bit depth.
	CPP					= 3,			///< Colors per pixel.
	VISIBLE			= 4,			///< Visibility.
	LINEOFFSET	= 5				///< Offset of component in line.
} MAXON_ENUM_LIST(VPGETINFO);
/// @}

/// @addtogroup DRAWOBJECT
/// @ingroup group_enumeration
/// @{
enum class DRAWOBJECT
{
	NONE							= 0,							///< None.
	FORCELINES				= (1 << 0),				///< Force wireframe display, independent of view settings.
	NOBACKCULL				= (1 << 1),				///< Force no backface culling, independent of view settings.
	LOCALMATRIX				= (1 << 2),				///< Object drawn will be drawn relative to the currently processed object (used when called from the draw method in a base object).
	EDITMODE					= (1 << 3),				///< Object is drawn in edit-mode style.
	FORCEBASE					= (1 << 9),				///< The draw call is only executed for the base class, and thus not for the instanciated object, if passed to BaseDraw::DrawObject() and the object type is an instance of either @ref Opoint or @ref Opolygon.\n
																			///< This way, you can do a draw call without running into a recursion if you are in your from points/polygons derived object.
	FORCEPOINTS				= (1 << 10),			///< Force points display.
	NO_EOGL						= (1 << 11),			///< No Extended OpenGL.
	USE_OBJECT_COLOR	= (1 << 12),			///< Use the object's color.
	USE_CUSTOM_COLOR	= (1 << 13),			///< Use a custom color.
	XRAY_ON						= (1 << 14),			///< Enables X-Ray mode.
	XRAY_OFF					= (1 << 15),			///< Disables X-Ray mode.
	IMMEDIATELY				= (1 << 16),			///< Draws an object immediately. Usually all objects are collected in a Z-depth sorted list before drawing. This flag is used for objects which are immediately deleted after drawing.\n
																			/// @code
																			/// DRAWRESULT MyObject::Draw(BaseObject* op, DRAWPASS drawpass, BaseDraw* bd, BaseDrawHelp* bh)
																			/// {
																			/// 	...
																			///
																			/// 	cube = BaseObject::Alloc(cube);
																			/// 	DrawObject(cube, DRAWOBJECT::IMMEDIATELY);
																			/// 	BaseObject::Free(cube);
																			///
																			/// 	...
																			/// }
																			/// @endcode
	Z_OFFSET					= (1 << 17),			///< Do not change the Z offset during BaseDraw::DrawObject().
	PRIVATE_ANY				= (1 << 30)				///< @markPrivate
} MAXON_ENUM_FLAGS(DRAWOBJECT);
/// @}

/// @addtogroup RENDERFLAGS
/// @ingroup group_enumeration
/// @{
enum class RENDERFLAGS
{
	NONE											= 0,						///< None.
	EXTERNAL									= (1 << 0),			///< External render.
	NODOCUMENTCLONE						= (1 << 1),			///< Set to avoid an automatic clone of the scene sent to RenderDocument().
	SHOWERRORS								= (1 << 2),			///< Show error messages.
	PREVIEWRENDER							= (1 << 3),			///< Preview render.
	IRR												= (1 << 4),			///< Interactive region render.
	CREATE_PICTUREVIEWER			= (1 << 5),			///< %Render in a new Picture Viewer.
	OPEN_PICTUREVIEWER				= (1 << 6),			///< Open the Picture Viewer.
	KEEP_CONTEXT							= (1 << 7),			///< @markPrivate
	BATCHRENDER								= (1 << 8),			///< %Render in Batch %Render. @markPrivate
	NET												= (1 << 9),			///< Use NET System for rendering.
	DONTANIMATE								= (1 << 10),		///< Do not animate document before rendering. This should only be used in combination with @ref RENDERFLAGS::PREVIEWRENDER.@since R17.032
	PREVIEWSETTINGS						= (1 << 11),		///< Use preview settings. @since R19
	RENDERQUEUEERRORS 				= (1 << 12),		///< Cancel Render Queue rendering if scene has missing assets. @markPrivate. @since R21
	FORCE_LINEAR_COLOR_PROFILE= (1 << 13),		///< Force linear color profile.

	INTERNAL_USE_CURRENT_QUEUE= (1 << 30),		///< Internal flag which tells the renderer to use the current destination queue
	INTERNAL_SPECIAL_PREVIEW	= (1 << 31),		///< Internal flag for special preview rendering of node materials. do not use!
} MAXON_ENUM_FLAGS(RENDERFLAGS);
/// @}

/// @addtogroup WRITEMODE
/// @ingroup group_enumeration
/// @{
enum class WRITEMODE
{
	STANDARD							= 0,		///< Standard.
	ASSEMBLE_MOVIE				= 1,		///< Assemble movie.
	ASSEMBLE_SINGLEIMAGE	= 2			///< Assemble single image.
} MAXON_ENUM_LIST(WRITEMODE);
/// @}

/// @addtogroup NETRENDERFLAGS
/// @ingroup group_enumeration
/// @{
enum class NETRENDERFLAGS
{
	NONE													= 0,						///< None.
	OPEN_PICTUREVIEWER						= (1 << 0),			///< Open Picture Viewer.
	SHOWERRORS										= (1 << 2),			///< Show errors.
	DELETEAFTERRENDERING					= (1 << 3),			///< Delete after rendering.
	NOPEERTOPEERASSETDISTRIBUTION	= (1 << 4),			///< No peer-to-peer asset distribution. Automatically set by local preferences.
	NOREQUESTONDEMAND							= (1 << 5),			///< No request on demand. Automatically set by local preferences.
	EXCLUDECLIENTONLOADINGERROR		= (1 << 6),			///< Exclude client on rendering error. Automatically set by local preferences.
	SAVERESULTSINREPOSITORY				= (1 << 7),			///< Save results in repository.
	ASSEMBLEB3DFILESIMMEDIATLEY		= (1 << 8),			///< Assemble @BP3D files immediately.
	NOWRITETEST										= (1 << 9),			///< No write test for @BP3D files.
	HANDLEWARNINGASERROR					= (1 << 10),		///< Handle warnings as errors.
	KEEPB3DFILESAFTERASSEMBLING		= (1 << 11)			///< Keep the @BP3D files on assembling.
} MAXON_ENUM_FLAGS(NETRENDERFLAGS);
/// @}

/// @addtogroup CHECKISRUNNING
/// @ingroup group_enumeration
/// @{
enum class CHECKISRUNNING
{
	ANIMATIONRUNNING				= 0,			///< Animation running.
	VIEWDRAWING							= 1,			///< View drawing.
	EDITORRENDERING					= 2,			///< Editor rendering.
	EXTERNALRENDERING				= 3,			///< External rendering.
	PAINTERUPDATING					= 4,			///< Painter updating.
	MATERIALPREVIEWRUNNING	= 5,			///< %Material preview running.
	EVENTSYSTEM							= 6,			///< Event System.
	BAKING									= 7,			///< Baking.
	INTERACTIVERENDERING		= 8				///< Interactive rendering.
} MAXON_ENUM_LIST(CHECKISRUNNING);
/// @}

/// @addtogroup BAKE_TEX_ERR
/// @ingroup group_enumeration
/// @{
enum class BAKE_TEX_ERR
{
	NONE								= 0,				///< None.
	NO_DOC							= 3000,			///< No document.
	NO_MEM							= 3001,			///< No more memory available.
	NO_RENDER_DOC				= 3002,			///< No render document.
	NO_TEXTURE_TAG			= 3003,			///< @c textag is @formatConstant{nullptr} or not in @c doc.
	NO_OBJECT						= 3004,			///< One of the tags is not assigned to an object or to another object.
	NO_UVW_TAG					= 3005,			///< UVW tag is missing.
	TEXTURE_MISSING			= 3006,			///< No texture.
	WRONG_BITMAP				= 3007,			///< MultipassBitmap was used, but it has the wrong type or wrong resolution.
	USERBREAK						= 3008,			///< %User break.
	NO_OPTIMAL_MAPPING	= 3009,			///< Optimal mapping failed.
	NO_SOURCE_UVW_TAG		= 3010			///< UVW tag for the source object is missing.
} MAXON_ENUM_LIST(BAKE_TEX_ERR);
/// @}

/// @addtogroup GL_MESSAGE
/// @ingroup group_enumeration
/// @{
enum class GL_MESSAGE
{
	OK							= 1,
	ERROR_					= 0,
	FORCE_EMULATION	= 2
} MAXON_ENUM_LIST(GL_MESSAGE);
/// @}

/// @addtogroup VIEWPORT_PICK_FLAGS
/// @ingroup group_enumeration
/// @{
enum class VIEWPORT_PICK_FLAGS
{
	NONE											= 0,						///< None.
	ALLOW_OGL									= (1 << 0),			///< Allow OpenGL.
	DONT_STOP_THREADS					= (1 << 1),			///< Do not stop threads.
	USE_SEL_FILTER						= (1 << 2),			///< Use selection filter.
	OGL_ONLY_TOPMOST					= (1 << 3),			///< Picks only topmost object. Use this only when the object pointer is not needed. Only works with OpenGL.
	OGL_ONLY_VISIBLE					= (1 << 4),			///< Picks only visible. Only has an effect when calling ViewportSelect::PickObject() that takes ViewportPixel as argument . Only works with OpenGL.
	OGL_IGNORE_Z							= (1 << 5),			///< Picks ignore Z position. Set this to only check if an object (and which) was hit, not its Z position. Only works with OpenGL.
	OGL_ONLY_TOPMOST_WITH_OBJ	= (1 << 6),			///< Picks only topmost object but returns the topmost object with its Z position. Only works with OpenGL.
	NO_DEPTH_CORRECTION				= (1 << 7),			///< To support old tools, the matrix is usually corrected so that the depth can be in the [-1, 1] range. With this option set, this does not happen any more.
} MAXON_ENUM_FLAGS(VIEWPORT_PICK_FLAGS);
/// @}

/// @addtogroup SHADERPOPUP
/// @ingroup group_enumeration
/// @{
#define SHADERPOPUP_SETSHADER					99989			///< Set a shader . @formatParam{param} points to a BaseShader. (param = @c reinterpret_cast<Int32>(shader))
#define SHADERPOPUP_SETFILENAME				99990			///< Set a bitmap. @formatParam{param} points to a Filename. (param = @c reinterpret_cast<Int32>(&fn))
#define SHADERPOPUP_LOADIMAGE					99991			///< Open file dialog and set user result.
#define SHADERPOPUP_EDITPARAMS				99999			///< Edit shaders in the Attribute Manager.
#define SHADERPOPUP_RELOADIMAGE				99998			///< Reload the image. (Only works for a single bitmap shader.)
#define SHADERPOPUP_EDITIMAGE					99997			///< Edit image in external application. (Only works for a single bitmap shader.)
#define SHADERPOPUP_LOCATEIMAGE				99996			///< Show image in finder/explorer. (Only works for a single bitmap shader.) @since R17.032
#define SHADERPOPUP_COPYCHANNEL				99995			///< Copy the shader to the copy buffer. (Only works for a single shader.)
#define SHADERPOPUP_PASTECHANNEL			99994			///< Paste the copy buffer. (Works for multiple shaders.)
#define SHADERPOPUP_CREATENEWTEXTURE	99993			///< Create a new @BP3D texture. (Only works for a single shader.)
#define SHADERPOPUP_CLEARSHADER				99992			///< Clear the shaders.
/// @}

/// @addtogroup DEFAULTFILENAME_SHADER
/// @ingroup group_enumeration
/// @{
#define DEFAULTFILENAME_SHADER_SURFACES	1001			///< Surfaces.
#define DEFAULTFILENAME_SHADER_EFFECTS	1002			///< Effects.
#define DEFAULTFILENAME_SHADER_VOLUME		1003			///< Volume.
/// @}

/// @addtogroup BACKGROUNDHANDLERCOMMAND
/// @ingroup group_enumeration
/// @{
enum class BACKGROUNDHANDLERCOMMAND
{
	ISRUNNING		= 100,			///< Return @formatConstant{true} if the handler is currently running, otherwise @formatConstant{false}.
	STOP				= 101,			///< Stop the current activity. Return @formatConstant{true} when the activity has stopped.
	START				= 102,			///< Check if there is something to do. If not, return false. In case there is something to do, directly start this job and return @formatConstant{true}.\n
													///< There is also the possibility to do a small job synchronously and return false (pretend as if nothing was started).
													///< @note	As the background handler is processed in the main application thread this means that if you process something unthreaded, the complete application will be blocked.\n
													///<				For example some code that takes @em 10 seconds means that the user will not be able to click on any button or stop anything during that time.\n
													///<				That is why only extremely short tasks must be directly processed, otherwise start an asynchronous thread.
	REMOVE			= 103				///< The handler is being removed. Return @formatConstant{true}.
} MAXON_ENUM_LIST(BACKGROUNDHANDLERCOMMAND);
/// @}

/// @addtogroup BACKGROUNDHANDLER_PRIORITY
/// @ingroup group_enumeration
/// @{
#define BACKGROUNDHANDLER_PRIORITY_RENDERACTIVEMATERIAL			5000			///< Priority for "Render active material".
#define BACKGROUNDHANDLER_PRIORITY_REDRAWVIEW								4000			///< Priority for "Redraw view".
#define BACKGROUNDHANDLER_PRIORITY_RENDERINACTIVEMATERIALS	3000			///< Priority for "Render inactive materials".
#define BACKGROUNDHANDLER_PRIORITY_RENDEREXTERNAL						-1000			///< Priority for "Render external".
#define BACKGROUNDHANDLER_PRIORITY_REDRAWANTS								-2000			///< Priority for "Redraw ants".
/// @}

/// @addtogroup BACKGROUNDHANDLERFLAGS
/// @ingroup group_enumeration
/// @{
enum class BACKGROUNDHANDLERFLAGS
{
	NONE								= 0,						///< None.
	VIEWREDRAW					= (1 << 0),			///< View redraw.
	EDITORRENDDER				= (1 << 1),			///< Editor render.
	MATERIALPREVIEW			= (1 << 2),			///< %Material preview.
	RENDEREXTERNAL			= (1 << 3),			///< %Render external.
	PRIVATE_VIEWREDRAW	= (1 << 4),			///< @markPrivate

	SHUTDOWN						= -1						///< Shutdown.
} MAXON_ENUM_FLAGS(BACKGROUNDHANDLERFLAGS);
/// @}

/// @C4D background handler type class.
#define BACKGROUNDHANDLER_TYPECLASS_C4D	1000

/// @markPrivate
#define ID_SNIPER_BACKGROUNDHANDLER		430000027

/// @addtogroup IDENTIFYFILE
/// @ingroup group_enumeration
/// @{
enum class IDENTIFYFILE
{
	NONE					= 0,						///< None.
	SCENE					= (1 << 0),			///< Scene file.
	IMAGE					= (1 << 1),			///< Image file.
	MOVIE					= (1 << 2),			///< Movie file.
	SKIPQUICKTIME	= (1 << 3),			///< Skip files that require QuickTime.
	SCRIPT				= (1 << 4),			///< Script file.
	SOUND					= (1 << 6),			///< Sound file.
	LAYOUT				= (1 << 7),			///< Layout file.
	PYTHON				= (1 << 8),			///< Python file.

	FASTDETECTION = (1 << 31),		///< maps to FILEFORMATDETECTIONFLAGS::FASTDETECTION
} MAXON_ENUM_FLAGS(IDENTIFYFILE);
/// @}

/// @addtogroup CALCHARDSHADOW
/// @ingroup group_enumeration
/// @{
enum class CALCHARDSHADOW
{
	NONE							= 0,							///< None.
	TRANSPARENCY			= (1 << 0),				///< Transparencies/alphas for in-between objects will be evaluated.
	SPECIALGISHADOW		= (1 << 29),			///< @markPrivate
	SPECIALSELFSHADOW	= (1 << 30)				///< @markPrivate
} MAXON_ENUM_FLAGS(CALCHARDSHADOW);
/// @}

/// @addtogroup ILLUMINATEFLAGS
/// @ingroup group_enumeration
/// @{
enum class ILLUMINATEFLAGS
{
	NONE															= 0,							///< None.
	SHADOW														= (1 << 0),				///< Full shadow calculations.
	NOENVIRONMENT											= (1 << 1),				///< Shadow calculations are enabled but no environment shading will be calculated.
	DISABLESHADOWMAP_CORRECTION				= (1 << 20),			///< Shadow maps evaluate the normal at a surface point, to avoid the problem of self-shadowing (that is otherwise inherent due to the way the algorithm works).\n
																											///< If a free point is sampled in space (where no surface is) this correction has to be disabled though, otherwise wrong results will be returned.
	DISABLESHADOWCASTERMP_CORRECTION	= (1 << 21),			///< @markPrivate
	LIGHTDIRNORMALS										= (1 << 22),			///< @markPrivate
	NODISTANCEFALLOFF									= (1 << 23),			///< Do not take distance falloff into account.
	NOGRAIN														= (1 << 24),			///< Do not take grain into account.
	BACKLIGHT													= (1 << 25)				///< Take backlight into account.
} MAXON_ENUM_FLAGS(ILLUMINATEFLAGS);
/// @}

/// @addtogroup RAYBIT
/// @ingroup group_enumeration
/// @{
enum class RAYBIT
{
	NONE								= 0,							///< None.
	REFLECTION					= (1 << 0),				///< Ray chain contains a reflection ray.
	TRANSPARENCY				= (1 << 1),				///< Ray chain contains a transparency ray (note: refractions are not contained).
	REFRACTION					= (1 << 2),				///< Ray chain contains a refraction ray.
	CUSTOM							= (1 << 3),				///< Ray chain contains a custom ray.

	CURR_REFLECTION		= (1 << 4),				///< Current ray is a reflection ray.
	CURR_TRANSPARENCY	= (1 << 5),				///< Current ray is a transparency ray.
	CURR_REFRACTION		= (1 << 6),				///< Current ray is a refraction ray.
	CURR_CUSTOM				= (1 << 7),				///< Current ray is a custom ray.

	VOLUMETRICLIGHT		= (1 << 8),				///< Current ray is used to calculate a volumetric light.
	ALLOWVLMIX				= (1 << 9),				///< Custom mixing of visible light sources allowed for this ray; bit must be deleted by shader if used.

	GI								= (1 << 10),			///< Current ray is a Global Illumination ray.
	BLURRY						= (1 << 11),			///< Current ray is a blurry ray.
	SSS								= (1 << 12),			///< Current ray is a subsurface ray.

	AO								= (1 << 13),			///< Current ray is an Ambient Occlusion ray.
	COMPOSITING				= (1 << 14)				///< Current ray is a compositing ray.
} MAXON_ENUM_FLAGS(RAYBIT);
/// @}

/// @addtogroup VOLUMEINFO
/// @ingroup group_enumeration
/// @{
enum class VOLUMEINFO : UInt32
{
	NONE								= 0,							///< None.
	REFLECTION					= 0x00000002,			///< Calculates reflections.
	TRANSPARENCY				= 0x00000004,			///< Calculates transparency.
	ALPHA								= 0x00000008,			///< Calculates alpha.
	CHANGENORMAL				= 0x00002000,			///< Calculates bump mapping.
	DISPLACEMENT				= 0x00004000,			///< Calculates displacement mapping.
	ENVREQUIRED					= 0x00100000,			///< Needs environment reflection data.
	DUDVREQUIRED				= 0x00200000,			///< Needs du/dv bump mapping data.
	MIPSAT							= 0x02000000,			///< Requires MIP/SAT data.
	VOLUMETRIC					= 0x20000000,			///< Is volumetric.
	TRANSFORM						= 0x00000010,			///< Needs back-transformed data.
	EVALUATEPROJECTION	= 0x04000000,			///< Requires material tag projections.
	PRIVATE_GLOW				= 0x10000000,			///< Calculates glow. @markPrivate
	INITCALCULATION			= 0x80000000,			///< Needs MaterialData::InitCalculation() call.
	FINAL_ALPHA					= 0x40000000,			///< Writes final alpha value. @since R18
	ISNBMMATERIAL				= 0x01000000			///< @markPrivate
} MAXON_ENUM_FLAGS(VOLUMEINFO);
/// @}

/// @addtogroup VIDEOPOSTINFO
/// @ingroup group_enumeration
/// @{
enum class VIDEOPOSTINFO
{
	NONE										= 0,							///< None.
	STOREFRAGMENTS					= (1 << 0),				///< The videopost needs fragment information for whole image at @ref VIDEOPOSTCALL::INNER/@ref VIDEOPOSTCALL::RENDER.
	EXECUTELINE							= (1 << 4),				///< The videopost uses VideoPostData::ExecuteLine.
	EXECUTEPIXEL						= (1 << 5),				///< The videopost uses VideoPostData::ExecutePixel.
	REQUEST_MOTIONMATRIX		= (1 << 6),				///< The videopost needs the motion matrix.
	REQUEST_MOTIONGEOMETRY	= (1 << 7),				///< The videopost needs the motion geometry.
	CALCVOLUMETRIC					= (1 << 8),				///< If set, VideoPostData::CalcVolumetric() is called for each ray.
	CALCSHADOW							= (1 << 9),				///< If set, VideoPostData::CalcShadow() is called for each ray.
	CUSTOMLENS							= (1 << 10),			///< The videopost will provide custom lens rays with VideoPostData::CreateRay.
	GLOBALILLUMINATION			= (1 << 11),			///< If set, VideoPostData::ComputeDiffuseGI is called for each ray.
	CAUSTICS								= (1 << 12),			///< If set VideoPostData::ComputeDiffuseCaustic() and VideoPostData::ComputeVolumeCaustic() are called for each ray.
	CUSTOMLENS_EXTENDED			= (1 << 13),			///< The videopost will provide custom extended lens rays with VideoPostData::CreateExtendedRay.
	NETFRAME								= (1 << 14),			///< The videopost is a NET frame hook.
	NETRUNONSERVER					= (1 << 15),			///< The videopost can be run on the NET server.
	NETCREATEBUFFER					= (1 << 16),			///< The videopost creates a buffer for the NET Client in VideoPostData::NetCreateBuffer.
	NETCREATEBUFFER_MULTI		= (1 << 17),			///< The videopost creates multiple buffers for the NET Client in VideoPostData::NetCreateBuffer (called consecutively). @since R16.038
	REQUEST_MOTIONFULL		 	= (1 << 18), 			///< The videopost requires complete motion blur information. @since R17.032
} MAXON_ENUM_FLAGS(VIDEOPOSTINFO);
/// @}

/// @addtogroup SHADERINFO
/// @ingroup group_enumeration
/// @{
/// Information flags for BaseShader::GetRenderInfo.
enum class SHADERINFO
{
	NONE							= 0,							///< None.
	TRANSFORM					= 0x00000004,			///< Channel needs back-transformed data. (Required for BaseVolumeData::back_p.)
	BUMP_SUPPORT			= 0x00000010,			///< Channel shader supports the new bump system. This is strongly recommended for all shaders except simple 2D (UV) samplers.
	ALPHA_SUPPORT			= 0x00000020,			///< Channel shader supports alpha output.
	REFLECTIONS				= 0x00000040,			///< Channel shader computes reflections.
	DUDVREQUIRED			= 0x00000080,			///< Channel shader needs du/dv bump mapping data. See BaseVolumeData::ddu and BaseVolumeData::ddv.
	DYNAMICSUBSHADERS	= 0x00000100,			///< Channel shader has a dynamic list of sub-shaders in its description.
	TRANSPARENCIES		= 0x00000200,			///< Deprecated, not used anymore.
	TIMEDEPENDENT			= 0x00000400			///< Channel shader changes over time.
} MAXON_ENUM_FLAGS(SHADERINFO);
/// @}

/// @addtogroup SAMPLEBUMP
/// @ingroup group_enumeration
/// @{
/// Flags for sampling bump mapping in the rendering API.
enum class SAMPLEBUMP
{
	NONE				= 0,						///< None.
	MIPFALLOFF	= (1 << 0)			///< Additional bump change over distance is considered.
} MAXON_ENUM_FLAGS(SAMPLEBUMP);
/// @}

/// @addtogroup INITCALCULATION
/// @ingroup group_enumeration
/// @{
/// %Material calculation types for the rendering API.
/// @see BaseMaterial::InitCalculation MaterialData::InitCalculation
enum class INITCALCULATION
{
	SURFACE				= 0,			///< Called during rendering for surface calculation.
	TRANSPARENCY	= 1,			///< Called during rendering for shadow rays computation.
	DISPLACEMENT	= 3				///< Called before rendering for displace calculation.
} MAXON_ENUM_LIST(INITCALCULATION);
/// @}

/// @addtogroup FIELDLAYER_FLAG
/// @ingroup group_enumeration
/// @{
/// %FieldLayer status values for execution and display.
/// @see FieldLayer::GetLayerFlags
enum class FIELDLAYER_FLAG
{
	NONE										= 0,						///< Default state
	SKIP										= (1 << 0),			///< Layer calculation is disabled, e.g. the linked object on a standard layer's deform mode is false.
	HIDE										= (1 << 2),			///< Layer should be completely ignored from both calculation and GUI display, e.g. the linked object has been deleted.
	MODIFYDATA							= (1 << 3),			///< The layer modifies existing data and needs the values from layers beneath it in the layerlist in the "results" array inside of Sample.
	PRESERVEALPHA						= (1 << 4),			///< The layer doesn't adjust the existing alpha and it's color changes should be applied ignoring any alpha values.
	NOCHILDVALUE						= (1 << 5),			///< Children of this layer wont output their value.
	NOCHILDCOLOR						= (1 << 6),			///< Children of this layer wont output their color.
	NOCHILDDIRECTION				= (1 << 7),			///< Children of this layer wont output their direction.
	TEMPORARY								= (1 << 8),			///< Don't save this layer with the list or duplicate it (outside of undo)
	NOCHILDROTATION					= (1 << 9)			///< Children of this layer wont output their direction.
} MAXON_ENUM_FLAGS(FIELDLAYER_FLAG);
/// @}


#define ID_SCRIPTFOLDER	1026688			///< @markPrivate

#define ID_PYTHONSCRIPT	1026256			///< ID for a BaseList2D object that holds a Python script. To load Python scripts use:
																		///< @code
																		/// BaseList2D* op = (BaseList2D*)AllocListNode(ID_PYTHONSCRIPT);
																		/// if (op && ReadHyperFile(nullptr, op, fn, 'scrp', nullptr)==FILEERROR::NONE)
																		/// {
																		/// 	BaseBitmap* ptr = nullptr;
																		/// 	op->Message(MSG_SCRIPT_RETRIEVEBITMAP, &ptr);
																		///
																		/// 	String script = op->GetDataInstanceRef().GetString(PYTHONSCRIPT_TEXT);
																		/// }
																		///
																		/// ...
																		///
																		/// blDelete(op);
																		/// @endcode
																		///< To access scripts loaded by @C4D use GetScriptHead().\n
																		///< The container for the Python script node contains the following settings: @enumerateEnum{PYTHONSCRIPT}
																		///< The node responds to the following messages: @enumerateEnum{MSG_SCRIPT}

/// @addtogroup COFFEESCRIPT
/// @ingroup group_containerid
/// @{
#define COFFEESCRIPT_TEXT					1000			///< String Script.
#define COFFEESCRIPT_SHOWINMENU		1002			///< ::Bool Show in menu.
#define COFFEESCRIPT_ADDEVENT			1003			///< ::Bool Add event.
#define COFFEESCRIPT_SCRIPTENABLE	1006			///< ::Bool Enable script.

#define COFFEESCRIPT_CONTAINER 65536			///< BaseContainer The ID offset for data that is stored per language.\n
																					///< This container does not need to be available. If it is not present for a language, then the English version ("US") is used.\n
																					///< This lets calculate the offset for a given name (e.g. "JP"):
																					/// @code
																					/// static Int32 LanguageToID(const String &str)
																					/// {
																					/// 	return Int32(str[0])*256+Int32(str[1]);
																					/// }
																					///
																					/// BaseContainer* lc = bc->GetContainerInstance(COFFEESCRIPT_CONTAINER+LanguageToID("JP"));
																					/// if (!lc)
																					/// 	return;
																					///
																					/// 	...
																					/// @endcode

#define COFFEESCRIPT_SCRIPTNAME	1			///< String Script name.
#define COFFEESCRIPT_SCRIPTHELP	2			///< String Script help string.
/// @}

/// @addtogroup MSG_SCRIPT
/// @ingroup group_enumeration
/// @{
#define MSG_SCRIPT_EXECUTE				1001184			///< Execute the script. (No arguments.)
#define MSG_SCRIPT_RETRIEVEBITMAP	1001185			///< Retrieves the script bitmap. Pass a pointer to the script's bitmap:
																							/// @code
																							/// BaseBitmap* ptr = nullptr;
																							/// op->Message(MSG_SCRIPT_RETRIEVEBITMAP, &ptr);
																							/// @endcode
/// @}

/// @addtogroup PYTHONSCRIPT
/// @ingroup group_containerid
/// @{
#define PYTHONSCRIPT_TEXT					1000			///< String Script.
#define PYTHONSCRIPT_SHOWINMENU		1002			///< ::Bool Show in menu.
#define PYTHONSCRIPT_ADDEVENT			1003			///< ::Bool Add event.
#define PYTHONSCRIPT_SCRIPTENABLE	1006			///< ::Bool Enable script.

#define PYTHONSCRIPT_CONTAINER 65536			///< BaseContainer The ID offset for data that is stored per language.\n
																					///< This container does not need to be available. If it is not present for a language, then the English version ("US") is used.\n
																					///< This lets calculate the offset for a given name (e.g. "JP"):
																					/// @code
																					/// static Int32 LanguageToID(const String &str)
																					/// {
																					/// 	return Int32(str[0])*256+Int32(str[1]);
																					/// }
																					///
																					/// BaseContainer* lc = bc->GetContainerInstance(PYTHONSCRIPT_CONTAINER+LanguageToID("JP"));
																					/// if (!lc)
																					/// 	return;
																					///
																					/// ...
																					/// @endcode

#define PYTHONSCRIPT_SCRIPTNAME	1			///< String Script name.
#define PYTHONSCRIPT_SCRIPTHELP	2			///< String Script help string.
#define PYTHONSCRIPT_SCRIPTPATH	3			///< String Script path, empty if temporary script.
/// @}

/// @addtogroup BASEDRAW
/// @ingroup group_enumeration
/// @{
#define BASEDRAW_DRAWPORTTYPE				1888			///< Drawport type: @enumerateEnum{DRAWPORT_TYPE}
#define BASEDRAW_IS_SHADOWPASS			1889			///< Is shadow pass.
#define BASEDRAW_IS_RENDERASEDITOR	1890			///< Is render as editor pass.
#define BASEDRAW_IS_OGL_PREPASS			1891			///< Is OpenGL prepass.
#define BASEDRAW_IS_PICK_OBJECT			1892			///< Is object picking pass.
/// @}

/// @addtogroup MULTIPASSCHANNEL
/// @ingroup group_enumeration
/// @{
enum class MULTIPASSCHANNEL
{
	NONE						= 0,						///< None.
	IMAGELAYER			= (1 << 0),			///< Image layer.
	MATERIALCHANNEL	= (1 << 1)			///< %Material channel.
} MAXON_ENUM_LIST(MULTIPASSCHANNEL);
/// @}

/// @addtogroup DLG_TYPE
/// @ingroup group_enumeration
/// @{
enum class DLG_TYPE
{
	MODAL = 10,											///< Modal dialog.
	MODAL_RESIZEABLE,								///< Resizable modal dialog.
	MODAL_POPUPEDIT,								///< Modal Dialog without menu bar and window frame.

	ASYNC = 20,											///< Non-modal (asynchronous) dialog.
	ASYNC_POPUP_RESIZEABLE,					///< Non-modal (asynchronous) dialog. Resizable popup dialog style (no menu bar).
	ASYNC_POPUPEDIT,								///< Non-modal (asynchronous) dialog. Popup dialog style (no menu bar, no window frame).
	ASYNC_TOOLBAR,									///< Non-modal (asynchronous) dialog. Toolbar style with no minimize/maximize buttons, but close button

	ASYNC_FULLSCREEN_WORK = 30,			///< Non-modal (asynchronous) dialog. Fullscreen over desktop area.
	ASYNC_FULLSCREEN_MONITOR,				///< Non-modal (asynchronous) dialog. Fullscreen over the whole monitor area.

	DUMMY
} MAXON_ENUM_LIST(DLG_TYPE);
/// @}

/// @addtogroup MULTIMSG_ROUTE
/// @ingroup group_enumeration
/// @{
enum class MULTIMSG_ROUTE
{
	NONE = 0,									 ///< None.
	UP = 1,										 ///< Send to parents.
	ROOT = 2,									 ///< Send to root object.
	DOWN = 3,									 ///< Send to children.
	BROADCAST = 4,						 ///< Broadcast the message, i.e. distribute it to all branches given by GeListNode::GetBranchInfo.
	BROADCAST_ONLYOBJECTS = 5, ///< Broadcast the message only to children objects
} MAXON_ENUM_LIST(MULTIMSG_ROUTE);
/// @}

/// @addtogroup VPGETFRAGMENTS
/// @ingroup group_enumeration
/// @{
enum class VPGETFRAGMENTS
{
	NONE	= 0,						///< None.
	Z_P		= (1 << 0),			///< Get VPFragment::z and VPFragment::p.
	N			= (1 << 1)			///< Get VPFragment::n.
} MAXON_ENUM_FLAGS(VPGETFRAGMENTS);
/// @}

#define MSG_GICSEX						1000969
#define MSG_GINEW							1021096
#define ID_OLDCAUSTICS				1000970			///< ID of the old Caustics videopost effect.
#define VPglobalillumination	1021096			///< Global Illumination video post ID.
#define VPGIShadingChain			1026950			///< @markPrivate
#define VPAOShadingChain			1029427			///< @markPrivate
#define VPbirender						1028868			///< Videopost birender.
#define VPPhLensDistortion		1031709			///< Videopost Lens Distortion. @since R17.032

#define MSG_2DCAMERASETTINGSCACHE 1034264 ///< Internal message for handling of non-destructive 2D Camera Navigation mode
#define MSG_PH_2DTRACK_MODE_MCOMMAND_EXECUTE 1036105 // Assigned to Steve Baines for 'Msg TrkObj 2' from www.plugincafe.com on 151009.
#define MSG_PH_2DTRACK_MODE_MCOMMAND_IS_ENABLED 1039952 // Assigned to Steve Baines from www.plugincafe.com on 170926

/// @addtogroup NAV2DCAMERASETTINGSCACHEMODE
/// @ingroup group_enumeration
/// @{
enum class NAV2DCAMERASETTINGSCACHEMODE
{
	REVERT = 0,
	STOREIFIN2D = 1,
	STOREIFIN2DANDNOTALREADYSTORED = 2,
	FORCESTORE = 3,
	RET_CHANGED = 1000,
	RET_NOCHANGE = 1001,
	INVALID = 99999
} MAXON_ENUM_LIST(NAV2DCAMERASETTINGSCACHEMODE);
/// @}


/// @addtogroup SIGNALMODE
/// @ingroup group_enumeration
/// @{
enum class SIGNALMODE
{
	// V_ unfortunately has to be used here due to conflicts with MAC OS
	V_DEFAULT		= 0,			///< Default mode.
	V_RESERVED	= 1				///< Reserved.
} MAXON_ENUM_LIST(SIGNALMODE);
/// @}

/// @addtogroup QUALIFIER
/// @ingroup group_enumeration
/// @{
enum class QUALIFIER
{
	NONE			= 0,						///< None.
	SHIFT			= (1 << 0),			///< @em SHIFT key.
	CTRL			= (1 << 1),			///< @em CTRL key.
	ALT				= (1 << 2),			///< @em ALT key.
	MOUSEHIT	= (1 << 10)			///< Indication in ObjectData::DetectHandle that the user pressed the mouse (ObjectData::DetectHandle is also called for cursor information, when hovering over a handle).\n
														///< For instance if @ref QUALIFIER::MOUSEHIT and @ref QUALIFIER::CTRL are set, ObjectData::DetectHandle could create a new element.
} MAXON_ENUM_FLAGS(QUALIFIER);
/// @}

/// @addtogroup CODEEDITOR
/// @ingroup group_containerid
/// @{
#define CODEEDITOR_SETMODE					'setm'			///< @ref SCRIPTMODE Set the script mode.
#define CODEEDITOR_GETSTRING				'gets'			///< String Return the script string.
#define CODEEDITOR_SETSTRING				'sets'			///< String Store the script string.
#define CODEEDITOR_COMPILE					'comp'			///< BaseContainer Compile the script: @enumerateEnum{CODEEDITOR_GETERROR}
/// @addtogroup CODEEDITOR_GETERROR
/// @ingroup group_containerid
/// @{
#define CODEEDITOR_GETERROR_RES			'resr'			///< ::Bool Compilation result. @formatConstant{true} if the compilation was successful, otherwise @formatConstant{false}.
#define CODEEDITOR_GETERROR_STRING	'ress'			///< String Error message.
#define CODEEDITOR_GETERROR_LINE		'resl'			///< ::Int32 Error line.
#define CODEEDITOR_GETERROR_POS			'resp'			///< ::Int32 Error position.
/// @}
#define CODEEDITOR_EXECUTE					'exec'			///< ::Bool Return @formatConstant{true} if the script was executed successfully, otherwise @formatConstant{false}.
#define CODEEDITOR_DISABLEUNDO			'dsud'			///< ::Bool Set to @formatConstant{true} to disable undo.
#define CODEEDITOR_STOREUNDO				'stun'			///< ::Bool Store undo.
#define CODEEDITOR_RESTOREUNDO			'reun'			///< ::Bool Restore undo.
#define CODEEDITOR_GETID						'reid'			///< DescID Return the description ID for the script string parameter.
/// @}

/// @markPrivate
#define BASECONTAINER_TEMPORARY	440000180

/// @addtogroup DIALOG
/// @ingroup group_enumeration
/// @{
enum
{
	DIALOG_PIN = 1,													///< ::Int32 flags
	DIALOG_CHECKBOX,												///< ::Int32 id, ::Int32 flags, String *name
	DIALOG_STATICTEXT,											///< ::Int32 id, ::Int32 flags, String *name, ::Int32 borderstyle
	DIALOG_BUTTON,													///< ::Int32 id, ::Int32 flags, String *name
	DIALOG_ARROWBUTTON,											///< ::Int32 id, ::Int32 flags, ::Int32 arrowtype
	DIALOG_EDITTEXT,												///< ::Int32 id, ::Int32 flags
	DIALOG_EDITNUMBER,											///< ::Int32 id, ::Int32 flags
	DIALOG_EDITNUMBERUD,										///< ::Int32 id, ::Int32 flags
	DIALOG_EDITSLIDER,											///< ::Int32 id, ::Int32 flags
	DIALOG_SLIDER,													///< ::Int32 id, ::Int32 flags
	DIALOG_COLORFIELD,											///< ::Int32 id, ::Int32 flags
	DIALOG_COLORCHOOSER,										///< ::Int32 id, ::Int32 flags
	DIALOG_USERAREA,												///< ::Int32 id, ::Int32 flags
	DIALOG_RADIOGROUP,											///< ::Int32 id, ::Int32 flags
	DIALOG_COMBOBOX,												///< ::Int32 id, ::Int32 flags
	DIALOG_POPUPBUTTON,											///< ::Int32 id, ::Int32 flags
	DIALOG_CHILD,														///< ::Int32 id, ::Int32 subid, String *child);
	DIALOG_FREECHILDREN,										///< ::Int32 id
	DIALOG_DLGGROUP,												///< ::Int32 flags
	DIALOG_SETTITLE,												///< String *name
	DIALOG_GROUPSPACE,											///< ::Int32 spacex, ::Int32 spacey
	DIALOG_GROUPBORDER,											///< @ref BORDER borderstyle
	DIALOG_GROUPBORDERSIZE,									///< ::Int32 left, ::Int32 top, ::Int32 right, ::Int32 bottom
	DIALOG_SETIDS,													///< ::Int32 left, ::Int32 top, ::Int32 right, ::Int32 bottom
	DIALOG_LAYOUTCHANGED,										///< Relayout dialog
	DIALOG_ACTIVATE,												///< Activate gadget
	DIALOG_ADDSUBMENU,											///< Add submenu, String *text
	DIALOG_ENDSUBMENU,											///< Add submenu, String *text
	DIALOG_ADDMENUCMD,											///< Add menu text, String *text, ::Int32 cmdid
	DIALOG_FLUSHMENU,												///< Delete all menu entries
	DIALOG_INIT,														///< Create new layout
	DIALOG_CHECKNUMBERS,										///< Range check of all dialog elements
	DELME_DIALOG_SETGROUP,									///< Set group as insert group
	DIALOG_FLUSHGROUP,											///< Flush all elements of this group and set insert point to this group
	DIALOG_SETMENU,													///< Set and display menu in manager
	DIALOG_SCREEN2LOCALX,										///< @markDeprecated Screen2Local coordinates
	DIALOG_SCREEN2LOCALY,										///< @markDeprecated Screen2Local coordinates
	DIALOG_ADDMENUSTR,											///< Add menu text, String *text, ::Int32 id
	DIALOG_RADIOBUTTON,											///< ::Int32 id, ::Int32 flags, String *name
	DIALOG_ADDMENUSEP,											///< Add menu separator
	DIALOG_SEPARATOR,												///< Add separator
	DIALOG_MULTILINEEDITTEXT,								///< Add multi-line edit field
	DIALOG_INITMENUSTR,											///< Enable/disable/check/uncheck menu strings
	DIALOG_RADIOTEXT,												///< ::Int32 id, ::Int32 flags, String *name
	DIALOG_MENURESOURCE,										///< @markPrivate for painter
	DIALOG_LISTVIEW,												///< ::Int32 id, ::Int32 flags
	DIALOG_SUBDIALOG,												///< ::Int32 id, ::Int32 flags
	DIALOG_CHECKCLOSE,											///< CheckClose message for dialog
	DIALOG_GETTRISTATE,											///< Get the TriState flag of the specified gadget
	DIALOG_SDK,															///< ::Int32 id, ::Int32 flags, String *name
	DIALOG_SCROLLGROUP,											///< Create scroll group
	DIALOG_ISOPEN,													///< Returns @formatConstant{true} if the dialog is open
	DIALOG_REMOVEGADGET,										///< Removes an element from the layout
	DIALOG_MENUGROUPBEGIN,									///< Menu group begin
	DIALOG_NOMENUBAR,												///< Removes the menubar
	DIALOG_SAVEWEIGHTS,											///< Store the weights of a group
	DIALOG_LOADWEIGHTS,											///< Restore the weights of a group
	DIALOG_EDITSHORTCUT,										///< Edit field to enter shortcuts
	DIALOG_ISVISIBLE,												///< Returns @formatConstant{true} if the dialog is visible (e.g. @formatConstant{false} if tabbed behind)
	DIALOG_HIDEELEMENT,											///< Hides the element
	DIALOG_SETDEFAULTCOLOR,									///< Set the mapcolor for a color to another value e.g. @ref COLOR_BG = @em (1,1,1)
	DIALOG_COMBOBUTTON,											///< ComboButton
	DIALOG_PRIVATE_NOSTOPEDITORTHREADS,			///< @markPrivate No parameters
	DIALOG_ISACTIVE,												///< Gadget has the focus. @since R18
	DIALOG_USERAREA_OSWINDOWREF,						///< @markPrivate Creates a wrapper to a maxon::OSWindowRef user area
	DIALOG_DISABLEREDRAW,										///< @markPrivate Bool: True/False to enable/disable redraw.
	DIALOG_SCREEN2LOCALXY,									///< @markPrivate Screen2Local coordinates
	DIALOG_HIDEOREXPAND,										///< @markPrivate Internal functionality to hide or shrink docked windows
	DIALOG_ISMINIMIZED,											///< Returns @formatConstant{true} if the dialog is minimized in the dock or task bar.
	DIALOG_USERAREA_DRAWPORT_WINDOWREF,			///< @markPrivate Creates a wrapper to a maxon::OSWindowRef user area. The window is a drawport window.
	DIALOG_ISDOCKEDORTABBED,								///< Returns DIALOG_ISDOCKED | DIALOG_ISTABBED, 0 if individual window
		#define DIALOG_ISDOCKED	(1 << 0)				///< set if the dialog is docked in the layout
		#define DIALOG_ISTABBED (1 << 1)				///< set if the dialog is tabbed
	DIALOG_GLOBALSTATUSBAR,									///< Adds a global status bar to the dialog
	DIALOG_NOTEXTMENU,											///< Hides the text menu, useful to fill all the menu area with gadgets added with @ref GeDialog::GroupBeginInMenuLine()
	DIALOG_FORCEALLOWMOUSEWHEEL,						///< Set to true to force to allow to receive mouse wheel events even if gadget is not on focus. @since 2023.200
	DIALOG_SETGROUPBACKGROUNDCOLORID,				///< ::Int32 Sets the group background color ID. @since 2024.000
	DIALOG_SETGROUPBACKGROUNDCOLORRGB,			///< ::Int32 red, ::Int32 green, ::Int32 blue. Sets the group background color RGB values. @since 2024.000
	DIALOG_SETGROUPINNERBACKGROUNDCOLORID,	///< ::Int32 Sets the group inner background color ID. @since 2024.000
	DIALOG_SETGROUPINNERBACKGROUNDCOLORRGB,	///< ::Int32 red, ::Int32 green, ::Int32 blue. Sets the group inner background color RGB values. @since 2024.000
	DIALOG_
};
/// @}

/// @addtogroup EDITTEXT
/// @ingroup group_enumeration
/// @{
/// @see	GeDialog::AddEditText\n
///				GeDialog::SetString(const GadgetPtr& id, const String& text, Int32 tristate = 0, Int32 flags = 0)\n
///				GeDialog::SetString(const GadgetPtr& id, const BaseContainer* bc, Int32 bcid, Int32 flags = 0)\n
///				GeDialog::SetString(const GadgetPtr& id, const TriState<String>& tri, Int32 flags = 0)
#define EDITTEXT_PASSWORD								(1 << 0) ///< Password field.
#define EDITTEXT_HELPTEXT								(1 << 1) ///< Sets the help text for an edit field. This text appears if the edit field is empty.
#define EDITTEXT_IGNORELEFTRIGHTIFEMPTY (1 << 2) ///< Ignore Left Right Keys if edit field is empty.
#define EDITTEXT_ENABLECLEARBUTTON			(1 << 3) ///< Displays a clear button within the edit field.
#define EDITTEXT_CURSORUPDOWNBUTTONS		(1 << 4) ///< Returns messages if cursor up/down is pressed (BFM_ACTION_KEYUP, BFM_ACTION_KEYDOWN).
#define EDITTEXT_NOENTERKEYFORWARDING		(1 << 5) ///< Blocks the forwarding of the keyboard Enter key.

/// @}

/// @addtogroup LV
/// @ingroup group_enumeration
/// @{
enum
{
	LV_GETLINECOUNT							= 1,			///< Request the number of lines of the listview.
	LV_GETCOLUMNCOUNT						= 2,			///< Request the number of columns of the listview.
	LV_GETLINEHEIGHT						= 3,			///< Ask for the height of the specific line.
	LV_GETCOLUMNWIDTH						= 4,			///< Ask for the width of the specific column in line.
	LV_GETCOLUMTYPE							= 5,			///< Ask for the type of the specific column in line.

	LV_COLUMN_TEXT							= C4D_FOUR_BYTE(0, 't', 'x', 't'),			///< Text.
	LV_COLUMN_EDITTEXT					= C4D_FOUR_BYTE(0, 'e', 'd', 't'),			///< Edit text.
	LV_COLUMN_BMP								= C4D_FOUR_BYTE(0, 'b', 'm', 'p'),			///< Bitmap.
	LV_COLUMN_CHECKBOX					= C4D_FOUR_BYTE(0, 'c', 'h', 'k'),			///< Checkbox.
	LV_COLUMN_BUTTON						= C4D_FOUR_BYTE(0, 'b', 't', 'n'),			///< Button.
	LV_COLUMN_USERDRAW					= C4D_FOUR_BYTE(0, 'u', 's', 'r'),			///< %User draw.
	LV_COLUMN_COLORVIEW					= C4D_FOUR_BYTE(0, 'c', 'l', 'v'),			///< Color view.

	LV_GETCOLUMDATA							= 6,				///< Ask for the data of the column in line.
	LV_GETLINESELECTED					= 7,				///< Ask if line is selected.
	LV_GETCOLSPACE							= 8,				///< Ask for space in pixels between 2 columns.
	LV_GETLINESPACE							= 9,				///< Ask for space in pixels between 2 lines.
	LV_GETFIXEDLAYOUT						= 10,				///< Ask for fixed layout.
	LV_DESTROYLISTVIEW					= 11,				///< Destroy listview and all data.
	LV_INITCACHE								= 12,				///< @markInternal
	LV_NOAUTOCOLUMN							= 13,				///< Ask for fast layout: if @formatConstant{false}, eachline is asked for the width, if @formatConstant{true}, only the first line is asked for the column width; huge speedup.

	LV_LMOUSEDOWN								= 50,				///< Mouse down at line, column.
	LV_ACTION										= 51,				///< Gadget command, col, @c data1 = msg.
	LV_USERDRAW									= 52,				///< %User draw.
	LV_REDRAW										= 53,				///< Redraw the listview (super message).
	LV_DATACHANGED							= 54,				///< Layout data has changed.
	LV_SHOWLINE									= 55,				///< Scroll line into the visible area.
	LV_DRAGRECEIVE							= 56,				///< Drag receive.
	LV_RMOUSEDOWN								= 57,				///< Mouse down at line, column.

	LV_SIMPLE_SELECTIONCHANGED	= 100,			///< Simple listview: selection changed.
	LV_SIMPLE_CHECKBOXCHANGED		= 101,			///< Simple listview: checkbox changed.
	LV_SIMPLE_FOCUSITEM					= 102,			///< Simple listview: set focus to item.
	LV_SIMPLE_BUTTONCLICK				= 103,			///< Simple listview: button click.
	LV_SIMPLE_ITEM_ID						= 1,				///< Item ID.
	LV_SIMPLE_COL_ID						= 2,				///< Column ID.
	LV_SIMPLE_DATA							= 3,				///< Data.
	LV_SIMPLE_DOUBLECLICK				= 104,			///< Simple listview: double-click.
	LV_SIMPLE_FOCUSITEM_NC			= 105,			///< Simple listview: focus item, but no change.
	LV_SIMPLE_RMOUSE						= 106,			///< Simple listview: right mouse click.
	LV_SIMPLE_USERDRAW					= 107,			///< Simple listview: user draw.
	LV_PYTHON_CLEANUP						= 108,			///< Cleanup of Python references.
	LV_GETBUBBLEHELP						= 109,			///< Ask for Bubble Help String.

	// Result types
	LV_RES_INT		= 'long',																///< Result int.
	LV_RES_BITMAP	= C4D_FOUR_BYTE(0, 'b', 'm', 'p'),			///< Result bitmap.
	LV_RES_STRING	= 'strg',																///< Result string.
	LV_RES_VECTOR	= C4D_FOUR_BYTE(0, 'v', 'e', 'c'),			///< Result vector.
	LV_RES_NIL		= C4D_FOUR_BYTE(0, 'n', 'i', 'l'),			///< Result nil.

	LV__
};
/// @}

typedef UChar PIX;

/// @addtogroup NOTIFY_EVENT
/// @ingroup group_enumeration
/// @{
/// @markPrivate
enum class NOTIFY_EVENT
{
	NONE					= -1,
	ALL						= 10,
	ANY						= 11,

	PRE_DEFORM		= 100,
	POST_DEFORM		= 101,
	UNDO					= 102,
	MESSAGE				= 103,
	FREE					= 104,

	COPY					= 107,
	CACHE					= 108,
	REMOVE				= 109,
	CLONE					= 110,
	INSERT				= 111,
	SELECTIONBIT	= 112,
	HIGHLIGHTBIT	= 113,

	SETNAME				= 200,
} MAXON_ENUM_LIST(NOTIFY_EVENT);
/// @}

/// @addtogroup NOTIFY_EVENT_FLAG
/// @ingroup group_enumeration
/// @{
/// @markPrivate
enum class NOTIFY_EVENT_FLAG
{
	REMOVED					= (1 << 0),

	COPY_UNDO				= (1 << 10),
	COPY_CACHE			= (1 << 11),
	COPY_DUPLICATE	= (1 << 12),
	ONCE						= (1 << 13),
	COPY						= ((1 << 10) | (1 << 11) | (1 << 12)),

	NONE						= 0
} MAXON_ENUM_FLAGS(NOTIFY_EVENT_FLAG);
/// @}

/// @addtogroup DESCIDSTATE
/// @ingroup group_enumeration
/// @{
enum class DESCIDSTATE
{
	NONE						= 0,					///< None.
	LOCKED					= 1 << 0,			///< Description element is locked.
	HIDDEN					= 1 << 1,			///< Description element is hidden.
	OVERRIDE				= 1 << 2,			///< Description is overridden. @since R17.032
	FORBIDOVERRIDE	= 1 << 3			///< Description cannot be overridden. @since R17.032
} MAXON_ENUM_FLAGS(DESCIDSTATE);
/// @}

/// @addtogroup BASEDRAW_HOOK_MESSAGE
/// @ingroup group_enumeration
/// @{
enum class BASEDRAW_HOOK_MESSAGE
{
	ADAPTVIEW					= 1,			///< The user clicked on "Adapt View" menu.
	SET_SCENE_CAMERA	= 2,			///< The user changed the scene camera. The corresponding data is BDSetSceneCameraMsg.
	DELETEBASEDRAW		= 3				///< The base draw is deleted.
} MAXON_ENUM_LIST(BASEDRAW_HOOK_MESSAGE);
/// @}

/// @addtogroup CINEMAINFO
/// @ingroup group_enumeration
/// @{
enum class CINEMAINFO
{
	TABLETT						= 4,			///< Tablet.
	OPENGL						= 7,			///< OpenGL.
	TABLETT_HIRES			= 8,			///< High resolution tablet.
	FORBID_GUI				= 9,			///< Forbid GUI.
	MINIMAL_VIEWPORT	= 10,			///< Minimal viewport configuration. (formerly FORBID_HWOGL, @since R18) @since R21
	LISTEN						= 11,			///< Listen.
	WATCH_PID					= 12,			///< Watch process ID.
	SETFOREGROUND			= 13,			///< Set foreground.
	FORCEDIALOG			 	= 14			///< Force dialogs
} MAXON_ENUM_FLAGS(CINEMAINFO);
/// @}

/// @addtogroup PROTOCOL
/// @ingroup group_enumeration
/// @{
enum class PROTOCOL
{
	ZERO	= 0,				///< None.
	IPV4	= 1000,			///< IPv4.
	IPV6							///< IPv6.
} MAXON_ENUM_LIST(PROTOCOL);
/// @}


/// @addtogroup RESOLVERESULT
/// @ingroup group_enumeration
/// @{
enum class RESOLVERESULT
{
	OK				= 0,			///< Ok.
	UNKNOWN		= 1,			///< Unknown error while resolving address.
} MAXON_ENUM_LIST(RESOLVERESULT);
/// @}

/// @addtogroup SERVERJOBLIST
/// @ingroup group_enumeration
/// @{
enum class SERVERJOBLIST
{
	INACTIVE = 1000,			///<
	ACTIVE,								///<
	DOWNLOAD,							///<
	ALL										///<
} MAXON_ENUM_LIST(SERVERJOBLIST);
/// @}

/// @addtogroup EDITION
/// @ingroup group_enumeration
/// @{
enum class EDITION
{
	C4D				= (1 << 0),									///< @C4D
	NETCLIENT	= (1 << 1),									///< NET client.
	NETSERVER	= (1 << 2),									///< NET server.
	NET				= (1 << 1) | (1 << 2),			///< NET.
} MAXON_ENUM_FLAGS(EDITION);
/// @}

/// @addtogroup JOBCOMMAND
/// @ingroup group_enumeration
/// @{
enum class JOBCOMMAND
{
	NONE = 1000,			///< Do nothing.
	FETCHJOB,					///< Fetch job.
	ALLOCATESPACE,		///< Allocate space.
	DOWNLOAD,					///< Download.
	RENDER,						///< %Render.
	DELETE_,					///< Delete.
	STOPANDDELETE,		///< Stop and delete.
	ASSEMBLE,					///< Assemble.
	END								///< End.
} MAXON_ENUM_LIST(JOBCOMMAND);
/// @}

/// @addtogroup RENDERTARGET
/// @ingroup group_containerid
/// @{
enum class RENDERTARGET
{
	ALL = 1000,	///< Use all machines.
	SPECIFIED,		///< C4DUuid.
	MINMAX				///< Minimum/maximum. <i>1000</i>:min <i>1001</i>:max
} MAXON_ENUM_LIST(RENDERTARGET);
/// @}

/// @addtogroup JOBSTATE
/// @ingroup group_enumeration
/// @{
enum class JOBSTATE
{
	IDLE = 1000,								///< Idle.

	PREPARING_RUNNING,					///< Preparing running. Preparing only for server in @link ::THREADMODE::ASYNC async@endlink mode for NetRenderService::StartRendering.
	PREPARING_FAILED,						///< Preparing failed.
	PREPARING_OK,								///< Preparing ok.

	RENDER_RUNNING,							///< %Render running.
	TE_RENDER_PAUSED,						///< %Render paused. Currently not used
	RENDER_OK,									///< %Render ok.
	RENDER_FAILED,							///< %Render failed.

	ALLOCATESPACE_RUNNING,			///< Allocate space running.
	ALLOCATESPACE_OK,						///< Allocate space ok.
	ALLOCATESPACE_FAILED,				///< Allocated space failed.

	DOWNLOAD_RUNNING,						///< Download running.
	DOWNLOAD_OK,								///< Download ok.
	DOWNLOAD_FAILED,						///< Download failed.

	ASSEMBLE_RUNNING,						///< Assemble running.
	ASSEMBLE_OK,								///< Assemble ok.
	ASSEMBLE_FAILED,						///< Assemble failed.

	STOPPED,										///< Stopped.
	QUEUED,											///< Queued.
	PENDING,										///< non-native state which is only available in the server when no machine is involved in a running job
	QUEUED_WAITING,							///< Queued waiting. @since R18
	ASSEMBLE_PENDING						///< Allocate space running. @since R17.053
} MAXON_ENUM_LIST(JOBSTATE);
/// @}

/// @addtogroup ZEROCONFMACHINESTATE
/// @ingroup group_enumeration
/// @{
enum class ZEROCONFMACHINESTATE
{
	ONLINE		= 1,			///< Online.
	OFFLINE	= 2,			///< Offline.
	REMOVED	= 3,			///< Removed.
	UPDATE		= 4,			///< Update.
} MAXON_ENUM_LIST(ZEROCONFMACHINESTATE);
/// @}

/// @addtogroup ZEROCONFACTION
/// @ingroup group_enumeration
/// @{
enum class ZEROCONFACTION
{
	NONE		= 0,						///< None.
	RESOLVE	= (1 << 0),			///< Resolve.
	MONITOR	= (1 << 1)			///< Monitor.
} MAXON_ENUM_FLAGS(ZEROCONFACTION);
/// @}

/// @addtogroup ZEROCONFERROR
/// @ingroup group_enumeration
/// @{
enum class ZEROCONFERROR
{
	OK												= 0,					///< No error.
	UNKNOWN										= -65537,			///< Unknown. @c 0xFFFEFFFF
	NOSUCHNAME								= -65538,			///< No such name.
	NOMEMORY									= -65539,			///< No memory.
	BADPARAM									= -65540,			///< Bad parameter.
	BADREFERENCE							= -65541,			///< Bad reference.
	BADSTATE									= -65542,			///< Bad state.
	BADFLAGS									= -65543,			///< Bad flags.
	UNSUPPORTED								= -65544,			///< Unsupported.
	NOTINITIALIZED						= -65545,			///< Not initialized.
	ALREADYREGISTERED					= -65547,			///< Already registered.
	NAMECONFLICT							= -65548,			///< Name conflict.
	INVALID										= -65549,			///< Invalid.
	FIREWALL									= -65550,			///< Firewall.
	INCOMPATIBLE							= -65551,			///< Client Library incompatible with daemon.
	BADINTERFACEINDEX					= -65552,			///< Bad interface index.
	REFUSED										= -65553,			///< Refused.
	NOSUCHRECORD							= -65554,			///< No such record.
	NOAUTH										= -65555,			///< No authentication.
	NOSUCHKEY									= -65556,			///< No such key.
	NATTRAVERSAL							= -65557,			///< NAT traversal.
	DOUBLENAT									= -65558,			///< Double NAT.
	BADTIME										= -65559,			///< Bad time. Codes up to here existed in Tiger.
	BADSIGNAL									= -65560,			///< Bad SIG.
	BADKEY										= -65561,			///< Bad key.
	TRANSIENT									= -65562,			///< Transient.
	SERVICENOTRUNNING					= -65563,			///< Background daemon not running.
	NATPORTMAPPINGUNSUPPORTED	= -65564,			///< NAT does not support NAT_PMP or UPNP.
	NATPORTMAPPINGDISABLED		= -65565,			///< NAT supports NAT-PMP or UPNP but it is disabled by the administrator.
	NOROUTER									= -65566,			///< No router currently configured (probably no network connectivity).
	POLLINGMODE								= -65567			///< Polling mode.
} MAXON_ENUM_LIST(ZEROCONFERROR);
/// @}

/// @addtogroup RENDERSETTING_STATICTAB
/// @ingroup group_enumeration
/// @{
#define RENDERSETTING_STATICTAB_OUTPUT				1			///< %Render settings Output tab.
#define RENDERSETTING_STATICTAB_SAVE					2			///< %Render settings Save tab.
#define RENDERSETTING_STATICTAB_MULTIPASS			3			///< %Render settings Multi-Pass tab.
#define RENDERSETTING_STATICTAB_ANTIALIASING	4			///< %Render settings Anti-Aliasing tab.
#define RENDERSETTING_STATICTAB_OPTIONS				5			///< %Render settings Options tab.
#define RENDERSETTING_STATICTAB_STEREO				6			///< %Render settings Stereoscopic tab.
#define RENDERSETTING_STATICTAB_NET						7			///< %Render settings NET tab.
#define RENDERSETTING_STATICTAB_OVERRIDEMAT		8			///< %Render settings Global Material Override tab. @since R17.032
/// @}

/// @addtogroup COMPONENT_SELECTION_MODES
/// @ingroup group_enumeration
/// @{
/// Modes used by Convert Selection dialog.
/// @since R19
enum class COMPONENT_SELECTION_MODES
{
	POINTS				= 0,								 ///< Points selection mode.
	EDGES					= 1,								 ///< Edges selection mode.
	POLYGONS			= 2,								 ///< Polygons selection mode.
	UVPOINTS			= 3,								 ///< UV Points selection mode.
	UVPOLYGONS		= 4,								 ///< UV Polygons selection mode.
	CURRENT				= 5,								 ///< Current component selection mode.
	UVEDGES				= 6									 ///< UV Edges selection mode. @since R22
} MAXON_ENUM_LIST(COMPONENT_SELECTION_MODES);
/// @}

/// @addtogroup FIELDSAMPLE_FLAG
/// @ingroup group_enumeration
/// @{
enum class FIELDSAMPLE_FLAG
{
	VALUE			= 0,														///< Sample only the value at the current point (minimum must still sample the value)
	DIRECTION	= (1 << 0),											///< Sample the velocity at the current point
	COLOR			= (1 << 1),											///< Sample the color at the current point
	ROTATION	= (1 << 2),											///< Sample the rotational velocity at the current point
	ALL				= VALUE | DIRECTION | COLOR,		///< Sample all channels at the current point minus rotation
	NONLINEARCOLOR	= (1 << 3)								///< Deliver the color in non-linear sRGB colorspace (see Document Linear Color Workflow settings)
} MAXON_ENUM_FLAGS(FIELDSAMPLE_FLAG);
/// @}

/// @addtogroup FIELDOBJECTSAMPLE_FLAG
/// @ingroup group_enumeration
/// @{
enum class FIELDOBJECTSAMPLE_FLAG
{
	NONE										= 0,						///< No flags
	DISABLEDIRECTIONFALLOFF = (1 << 0)			///< @Markprivate Disables remapping the direction magnitude by the value parameter in order that fieldlayers may use that to blend instead in normal mode
} MAXON_ENUM_FLAGS(FIELDOBJECTSAMPLE_FLAG);
/// @}

/// @addtogroup FIELDOBJECT_FLAG
/// @ingroup group_enumeration
/// @{
enum class FIELDOBJECT_FLAG
{
	NONE											= 0,								///< No flags
	INLINE										= (1 << 0),					///< Field calculates using the current values of the field stack.
	GENERATINGCOLOR						= (1 << 1),					///< The Field is currently outputting color.
	PRESERVEALPHA							= (1 << 2),					///< The Field doesn't modify alpha, any color it produces is directly applied to the existing color ignoring the alpha blending.
	SKIP											= (1 << 3)					///< The Field should be skipped.
} MAXON_ENUM_FLAGS(FIELDOBJECT_FLAG);
/// @}

#define MESSAGE_ACTIVE_NODESPACE_CHANGED	1050506			///< @Markprivate

/// @addtogroup VIEWPORT_RENDER_ID
/// @ingroup group_enumeration
/// @{
enum class VIEWPORT_RENDER_ID
{
	RENDER_OBJECT = 0,	///< Return the Id of the render object.
	DATA_SETTER = 1			///< Return the Id of the data setter.
} MAXON_ENUM_LIST(VIEWPORT_RENDER_ID);
/// @}

struct ViewportRenderIDMessageData
{
	VIEWPORT_RENDER_ID typeId;	///< Requested type of viewport render ID
	const Char* viewportId;					///< The resulting viewport render ID
};

/// @addtogroup GETALLASSETSRESULT
/// @ingroup group_enumeration
/// @{
/// Result codes for GetAllAssets(). @since R22
enum class GETALLASSETSRESULT
{
	FAILED		= 0,		///< Function call went wrong.
	OK				= 1,		///< Function succeeded and all assets exists.
	MISSING		= 2			///< Function succeeded but some assets cannot be found.
} MAXON_ENUM_LIST(GETALLASSETSRESULT);
/// @}

/// @addtogroup VIEWMANAGERTYPE
/// @ingroup group_enumeration
/// @{
/// Result codes for GeGetActiveViewportType(). @since R23
enum class VIEWPORTTYPE
{
	NONE			= 0,		///< No viewport is active.
	MAIN_VIEW = 1,		///< Main 3D viewport is active.
	UV_VIEW		= 2			///< UV viewport is active.
} MAXON_ENUM_LIST(VIEWPORTTYPE);
/// @}

/// @addtogroup SCENENODES_IDS
/// @ingroup group_enumeration
/// @{
/// Classic API Scene Nodes related IDs. @since R23

enum class SCENENODES_IDS
{
    SCENEHOOK_ID                = 1054188,        ///< SceneHook ID
    MSGUPDATE_LEGACYOBJ_ID      = 180420109,      ///< Legacy Objects Update Message ID.
    PERSISTENT_HASH_LOW_ID      = 180420112       ///< Persistent Hash ID.
} MAXON_ENUM_LIST(SCENENODES_IDS);
/// @}

enum class FOLDMODE
{
	NONE,
	HIDEMYSELF,
	EXPAND1STEP,
	EXPANDCOMPLETELY,
} MAXON_ENUM_LIST(FOLDMODE);

/// @internal for GetDrawStateData()
enum class TAGBITS
{
	NONE = 0,
	TDISPLAY = 1 << 0,
	TCOMPOSITING = 1 << 1,
	TTEXTURE = 1 << 2,
} MAXON_ENUM_FLAGS(TAGBITS);

enum class ACCESSED_OBJECTS_MASK;
enum class METHOD_ID;
class AccessedObjectsCallback;

#ifdef CINEWARE_NAMESPACE_ENABLE
	CINEWARE_NAMESPACE_END
#endif

#endif // GE_PREPASS_H__
