#if 1
#ifdef CINEWARE_NAMESPACE_ENABLE
CINEWARE_NAMESPACE_BEGIN
#endif
namespace enum51
{
	enum class LINESTYLE
	{
		NORMAL,
		DOTTED,
		DASHED,
		DASHED_INV,
		DASHED_BIG,
	} ;
	static const maxon::UInt64 LINESTYLE_values[] = {maxon::UInt64(enum51::LINESTYLE::NORMAL), maxon::UInt64(enum51::LINESTYLE::DOTTED), maxon::UInt64(enum51::LINESTYLE::DASHED), maxon::UInt64(enum51::LINESTYLE::DASHED_INV), maxon::UInt64(enum51::LINESTYLE::DASHED_BIG)};
	static const maxon::EnumInfo LINESTYLE_info{"LINESTYLE", SIZEOF(LINESTYLE), false, "NORMAL\0DOTTED\0DASHED\0DASHED_INV\0DASHED_BIG\0", LINESTYLE_values, std::extent<decltype(LINESTYLE_values)>::value};
}
const maxon::EnumInfo& PrivateGetEnumInfo_LINESTYLE51(){ return enum51::LINESTYLE_info; }
namespace enum63
{
	enum class SERVERMESSAGE
	{
		NONE		= 0,				///< None.
	
		WARNING	= 1000,			///< Warning.
		ERROR_	= 1001,			///< Error.
		INFO		= 1002			///< Info.
	} ;
	static const maxon::UInt64 SERVERMESSAGE_values[] = {maxon::UInt64(enum63::SERVERMESSAGE::NONE), maxon::UInt64(enum63::SERVERMESSAGE::WARNING), maxon::UInt64(enum63::SERVERMESSAGE::ERROR_), maxon::UInt64(enum63::SERVERMESSAGE::INFO)};
	static const maxon::EnumInfo SERVERMESSAGE_info{"SERVERMESSAGE", SIZEOF(SERVERMESSAGE), false, "NONE\0WARNING\0ERROR_\0INFO\0", SERVERMESSAGE_values, std::extent<decltype(SERVERMESSAGE_values)>::value};
}
const maxon::EnumInfo& PrivateGetEnumInfo_SERVERMESSAGE63(){ return enum63::SERVERMESSAGE_info; }
namespace enum75
{
	enum class RENDERJOBLIST
	{
		INACTIVE	= 1 << 1,			///< Inactive.
		ACTIVE		= 1 << 2,			///< Active.
		LOAD			= 1 << 3,			///< Load.
		ALL				= 14					///< All: @ref RENDERJOBLIST::INACTIVE | @ref RENDERJOBLIST::ACTIVE | @ref RENDERJOBLIST::LOAD.
	} ;
	static const maxon::UInt64 RENDERJOBLIST_values[] = {maxon::UInt64(enum75::RENDERJOBLIST::INACTIVE), maxon::UInt64(enum75::RENDERJOBLIST::ACTIVE), maxon::UInt64(enum75::RENDERJOBLIST::LOAD), maxon::UInt64(enum75::RENDERJOBLIST::ALL)};
	static const maxon::EnumInfo RENDERJOBLIST_info{"RENDERJOBLIST", SIZEOF(RENDERJOBLIST), true, "INACTIVE\0ACTIVE\0LOAD\0ALL\0", RENDERJOBLIST_values, std::extent<decltype(RENDERJOBLIST_values)>::value};
}
const maxon::EnumInfo& PrivateGetEnumInfo_RENDERJOBLIST75(){ return enum75::RENDERJOBLIST_info; }
namespace enum87
{
	enum class MESSAGERESULT
	{
		OK = 1000,					///< Ok.
		NETWORKERROR,				///< Network error.
		UNKNOWNERROR,				///< Unknown error.
		MEMORYERROR					///< Memory error.
	} ;
	static const maxon::UInt64 MESSAGERESULT_values[] = {maxon::UInt64(enum87::MESSAGERESULT::OK), maxon::UInt64(enum87::MESSAGERESULT::NETWORKERROR), maxon::UInt64(enum87::MESSAGERESULT::UNKNOWNERROR), maxon::UInt64(enum87::MESSAGERESULT::MEMORYERROR)};
	static const maxon::EnumInfo MESSAGERESULT_info{"MESSAGERESULT", SIZEOF(MESSAGERESULT), false, "OK\0NETWORKERROR\0UNKNOWNERROR\0MEMORYERROR\0", MESSAGERESULT_values, std::extent<decltype(MESSAGERESULT_values)>::value};
}
const maxon::EnumInfo& PrivateGetEnumInfo_MESSAGERESULT87(){ return enum87::MESSAGERESULT_info; }
namespace enum98
{
	enum class MACHINELIST
	{
		ONLINE	= 1 << 1,			///< Online.
		OFFLINE	= 1 << 0,			///< Offline.
		ALL			= 7,					///< All: @ref MACHINELIST::ONLINE | @ref MACHINELIST::OFFLINE.
	} ;
	static const maxon::UInt64 MACHINELIST_values[] = {maxon::UInt64(enum98::MACHINELIST::ONLINE), maxon::UInt64(enum98::MACHINELIST::OFFLINE), maxon::UInt64(enum98::MACHINELIST::ALL)};
	static const maxon::EnumInfo MACHINELIST_info{"MACHINELIST", SIZEOF(MACHINELIST), true, "ONLINE\0OFFLINE\0ALL\0", MACHINELIST_values, std::extent<decltype(MACHINELIST_values)>::value};
}
const maxon::EnumInfo& PrivateGetEnumInfo_MACHINELIST98(){ return enum98::MACHINELIST_info; }
namespace enum128
{
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
	} ;
	static const maxon::UInt64 VERIFICATIONBIT_values[] = {maxon::UInt64(enum128::VERIFICATIONBIT::NONE), maxon::UInt64(enum128::VERIFICATIONBIT::ONLINE), maxon::UInt64(enum128::VERIFICATIONBIT::VERIFIED), maxon::UInt64(enum128::VERIFICATIONBIT::VERIFIEDME), maxon::UInt64(enum128::VERIFICATIONBIT::SHARED), maxon::UInt64(enum128::VERIFICATIONBIT::VERIFYING), maxon::UInt64(enum128::VERIFICATIONBIT::FAILURE), maxon::UInt64(enum128::VERIFICATIONBIT::SECURITYTOKENCHANGED), maxon::UInt64(enum128::VERIFICATIONBIT::WRONGBUILDID), maxon::UInt64(enum128::VERIFICATIONBIT::WRONGARCHITECTURE), maxon::UInt64(enum128::VERIFICATIONBIT::NOTREACHABLE), maxon::UInt64(enum128::VERIFICATIONBIT::NOANSWER), maxon::UInt64(enum128::VERIFICATIONBIT::WRONGSECURITYTOKEN), maxon::UInt64(enum128::VERIFICATIONBIT::DEMONOTACTIVATED), maxon::UInt64(enum128::VERIFICATIONBIT::REMOVING), maxon::UInt64(enum128::VERIFICATIONBIT::NORENDERSUPPORT), maxon::UInt64(enum128::VERIFICATIONBIT::INITIALIZING), maxon::UInt64(enum128::VERIFICATIONBIT::VERIFICATIONESTABLISHED)};
	static const maxon::EnumInfo VERIFICATIONBIT_info{"VERIFICATIONBIT", SIZEOF(VERIFICATIONBIT), true, "NONE\0ONLINE\0VERIFIED\0VERIFIEDME\0SHARED\0VERIFYING\0FAILURE\0SECURITYTOKENCHANGED\0WRONGBUILDID\0WRONGARCHITECTURE\0NOTREACHABLE\0NOANSWER\0WRONGSECURITYTOKEN\0DEMONOTACTIVATED\0REMOVING\0NORENDERSUPPORT\0INITIALIZING\0VERIFICATIONESTABLISHED\0", VERIFICATIONBIT_values, std::extent<decltype(VERIFICATIONBIT_values)>::value};
}
const maxon::EnumInfo& PrivateGetEnumInfo_VERIFICATIONBIT128(){ return enum128::VERIFICATIONBIT_info; }
namespace enum142
{
	enum class RENDERJOBCREATOR
	{
		BATCHRENDER						= (1 << 0),
		PICTUREVIEWER					= (1 << 1),
		USER									= (1 << 2),
		WATCHDIRECTORY				= (1 << 3),
		WATCHDIRECTORYSTARTUP	= (1 << 4),
		OTHER									= (1 << 5)
	} ;
	static const maxon::UInt64 RENDERJOBCREATOR_values[] = {maxon::UInt64(enum142::RENDERJOBCREATOR::BATCHRENDER), maxon::UInt64(enum142::RENDERJOBCREATOR::PICTUREVIEWER), maxon::UInt64(enum142::RENDERJOBCREATOR::USER), maxon::UInt64(enum142::RENDERJOBCREATOR::WATCHDIRECTORY), maxon::UInt64(enum142::RENDERJOBCREATOR::WATCHDIRECTORYSTARTUP), maxon::UInt64(enum142::RENDERJOBCREATOR::OTHER)};
	static const maxon::EnumInfo RENDERJOBCREATOR_info{"RENDERJOBCREATOR", SIZEOF(RENDERJOBCREATOR), true, "BATCHRENDER\0PICTUREVIEWER\0USER\0WATCHDIRECTORY\0WATCHDIRECTORYSTARTUP\0OTHER\0", RENDERJOBCREATOR_values, std::extent<decltype(RENDERJOBCREATOR_values)>::value};
}
const maxon::EnumInfo& PrivateGetEnumInfo_RENDERJOBCREATOR142(){ return enum142::RENDERJOBCREATOR_info; }
namespace enum150
{
	enum class DETAILSELECTOR
	{
		NONE									= 0,
		SELECTED							= (1 << 0),
		NONSELECTED						= (1 << 1)
	} ;
	static const maxon::UInt64 DETAILSELECTOR_values[] = {maxon::UInt64(enum150::DETAILSELECTOR::NONE), maxon::UInt64(enum150::DETAILSELECTOR::SELECTED), maxon::UInt64(enum150::DETAILSELECTOR::NONSELECTED)};
	static const maxon::EnumInfo DETAILSELECTOR_info{"DETAILSELECTOR", SIZEOF(DETAILSELECTOR), true, "NONE\0SELECTED\0NONSELECTED\0", DETAILSELECTOR_values, std::extent<decltype(DETAILSELECTOR_values)>::value};
}
const maxon::EnumInfo& PrivateGetEnumInfo_DETAILSELECTOR150(){ return enum150::DETAILSELECTOR_info; }
namespace enum163
{
	enum class STATUSNETSTATE
	{
		NONE = 0,					///< None.
		DISABLE,						///< Disable.
		IDLE,							///< Idle.
		BUSY,							///< Busy.
		BUSY2,							///< Busy 2.
		CRITICAL						///< Critical.
	} ;
	static const maxon::UInt64 STATUSNETSTATE_values[] = {maxon::UInt64(enum163::STATUSNETSTATE::NONE), maxon::UInt64(enum163::STATUSNETSTATE::DISABLE), maxon::UInt64(enum163::STATUSNETSTATE::IDLE), maxon::UInt64(enum163::STATUSNETSTATE::BUSY), maxon::UInt64(enum163::STATUSNETSTATE::BUSY2), maxon::UInt64(enum163::STATUSNETSTATE::CRITICAL)};
	static const maxon::EnumInfo STATUSNETSTATE_info{"STATUSNETSTATE", SIZEOF(STATUSNETSTATE), true, "NONE\0DISABLE\0IDLE\0BUSY\0BUSY2\0CRITICAL\0", STATUSNETSTATE_values, std::extent<decltype(STATUSNETSTATE_values)>::value};
}
const maxon::EnumInfo& PrivateGetEnumInfo_STATUSNETSTATE163(){ return enum163::STATUSNETSTATE_info; }
namespace enum171
{
	enum class HOTKEYFLAGS
	{
		NONE = 0,
		MOUSE = 1 << 0,
		KEYBOARD = 1 << 1,
	} ;
	static const maxon::UInt64 HOTKEYFLAGS_values[] = {maxon::UInt64(enum171::HOTKEYFLAGS::NONE), maxon::UInt64(enum171::HOTKEYFLAGS::MOUSE), maxon::UInt64(enum171::HOTKEYFLAGS::KEYBOARD)};
	static const maxon::EnumInfo HOTKEYFLAGS_info{"HOTKEYFLAGS", SIZEOF(HOTKEYFLAGS), true, "NONE\0MOUSE\0KEYBOARD\0", HOTKEYFLAGS_values, std::extent<decltype(HOTKEYFLAGS_values)>::value};
}
const maxon::EnumInfo& PrivateGetEnumInfo_HOTKEYFLAGS171(){ return enum171::HOTKEYFLAGS_info; }
namespace enum261
{
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
	
	} ;
	static const maxon::UInt64 ASSETDATA_FLAG_values[] = {maxon::UInt64(enum261::ASSETDATA_FLAG::NONE), maxon::UInt64(enum261::ASSETDATA_FLAG::CURRENTFRAMEONLY), maxon::UInt64(enum261::ASSETDATA_FLAG::TEXTURESONLY), maxon::UInt64(enum261::ASSETDATA_FLAG::NET), maxon::UInt64(enum261::ASSETDATA_FLAG::CURRENTTAKEONLY), maxon::UInt64(enum261::ASSETDATA_FLAG::WITHCACHES), maxon::UInt64(enum261::ASSETDATA_FLAG::NOSUBSTANCES), maxon::UInt64(enum261::ASSETDATA_FLAG::MULTIPLEUSE), maxon::UInt64(enum261::ASSETDATA_FLAG::NOMISSING), maxon::UInt64(enum261::ASSETDATA_FLAG::NODOCUMENT), maxon::UInt64(enum261::ASSETDATA_FLAG::COLLECT_NODES_ASSETS), maxon::UInt64(enum261::ASSETDATA_FLAG::DONOTRESOLVE)};
	static const maxon::EnumInfo ASSETDATA_FLAG_info{"ASSETDATA_FLAG", SIZEOF(ASSETDATA_FLAG), true, "NONE\0CURRENTFRAMEONLY\0TEXTURESONLY\0NET\0CURRENTTAKEONLY\0WITHCACHES\0NOSUBSTANCES\0MULTIPLEUSE\0NOMISSING\0NODOCUMENT\0COLLECT_NODES_ASSETS\0DONOTRESOLVE\0", ASSETDATA_FLAG_values, std::extent<decltype(ASSETDATA_FLAG_values)>::value};
}
const maxon::EnumInfo& PrivateGetEnumInfo_ASSETDATA_FLAG261(){ return enum261::ASSETDATA_FLAG_info; }
namespace enum282
{
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
	} ;
	static const maxon::UInt64 SAVEBIT_values[] = {maxon::UInt64(enum282::SAVEBIT::NONE), maxon::UInt64(enum282::SAVEBIT::ALPHA), maxon::UInt64(enum282::SAVEBIT::MULTILAYER), maxon::UInt64(enum282::SAVEBIT::USESELECTEDLAYERS), maxon::UInt64(enum282::SAVEBIT::USE16BITCHANNELS), maxon::UInt64(enum282::SAVEBIT::GREYSCALE), maxon::UInt64(enum282::SAVEBIT::INTERNALNET), maxon::UInt64(enum282::SAVEBIT::DONTMERGE), maxon::UInt64(enum282::SAVEBIT::USE32BITCHANNELS), maxon::UInt64(enum282::SAVEBIT::SAVERENDERRESULT), maxon::UInt64(enum282::SAVEBIT::FIRSTALPHA_ONLY), maxon::UInt64(enum282::SAVEBIT::KEEP_COLOR_MODE)};
	static const maxon::EnumInfo SAVEBIT_info{"SAVEBIT", SIZEOF(SAVEBIT), true, "NONE\0ALPHA\0MULTILAYER\0USESELECTEDLAYERS\0USE16BITCHANNELS\0GREYSCALE\0INTERNALNET\0DONTMERGE\0USE32BITCHANNELS\0SAVERENDERRESULT\0FIRSTALPHA_ONLY\0KEEP_COLOR_MODE\0", SAVEBIT_values, std::extent<decltype(SAVEBIT_values)>::value};
}
const maxon::EnumInfo& PrivateGetEnumInfo_SAVEBIT282(){ return enum282::SAVEBIT_info; }
namespace enum311
{
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
		SUPPRESSOPTIONSDIALOG = (1 << 31),											///< Suppress the options dialog (if DIALOGSALLOWED was specified), so that errors would show up
	} ;
	static const maxon::UInt64 SCENEFILTER_values[] = {maxon::UInt64(enum311::SCENEFILTER::NONE), maxon::UInt64(enum311::SCENEFILTER::OBJECTS), maxon::UInt64(enum311::SCENEFILTER::MATERIALS), maxon::UInt64(enum311::SCENEFILTER::DIALOGSALLOWED), maxon::UInt64(enum311::SCENEFILTER::PROGRESSALLOWED), maxon::UInt64(enum311::SCENEFILTER::MERGESCENE), maxon::UInt64(enum311::SCENEFILTER::NONEWMARKERS), maxon::UInt64(enum311::SCENEFILTER::SAVECACHES), maxon::UInt64(enum311::SCENEFILTER::NOUNDO), maxon::UInt64(enum311::SCENEFILTER::SAVE_BINARYCACHE), maxon::UInt64(enum311::SCENEFILTER::IDENTIFY_ONLY), maxon::UInt64(enum311::SCENEFILTER::ONLY_RENDERDATA), maxon::UInt64(enum311::SCENEFILTER::IGNOREMISSINGPLUGINSINNONACTIVERENDERDATA), maxon::UInt64(enum311::SCENEFILTER::IGNOREXREFS), maxon::UInt64(enum311::SCENEFILTER::DONTCORRECTOUTPUTFORMAT), maxon::UInt64(enum311::SCENEFILTER::SKIPOLDERTHANV13), maxon::UInt64(enum311::SCENEFILTER::PREVIEWONLY), maxon::UInt64(enum311::SCENEFILTER::DOCUMENTPREFSONLY), maxon::UInt64(enum311::SCENEFILTER::SUPPRESSOPTIONSDIALOG)};
	static const maxon::EnumInfo SCENEFILTER_info{"SCENEFILTER", SIZEOF(SCENEFILTER), true, "NONE\0OBJECTS\0MATERIALS\0DIALOGSALLOWED\0PROGRESSALLOWED\0MERGESCENE\0NONEWMARKERS\0SAVECACHES\0NOUNDO\0SAVE_BINARYCACHE\0IDENTIFY_ONLY\0ONLY_RENDERDATA\0IGNOREMISSINGPLUGINSINNONACTIVERENDERDATA\0IGNOREXREFS\0DONTCORRECTOUTPUTFORMAT\0SKIPOLDERTHANV13\0PREVIEWONLY\0DOCUMENTPREFSONLY\0SUPPRESSOPTIONSDIALOG\0", SCENEFILTER_values, std::extent<decltype(SCENEFILTER_values)>::value};
}
const maxon::EnumInfo& PrivateGetEnumInfo_SCENEFILTER311(){ return enum311::SCENEFILTER_info; }
namespace enum325
{
	enum class OVERVIEW
	{
		DEFAULT		= 0,
		AKTU			= 1,
		SCENE			= 2,
		COMPLETE	= 3,
		SELECTED	= 4
	} ;
	static const maxon::UInt64 OVERVIEW_values[] = {maxon::UInt64(enum325::OVERVIEW::DEFAULT), maxon::UInt64(enum325::OVERVIEW::AKTU), maxon::UInt64(enum325::OVERVIEW::SCENE), maxon::UInt64(enum325::OVERVIEW::COMPLETE), maxon::UInt64(enum325::OVERVIEW::SELECTED)};
	static const maxon::EnumInfo OVERVIEW_info{"OVERVIEW", SIZEOF(OVERVIEW), true, "DEFAULT\0AKTU\0SCENE\0COMPLETE\0SELECTED\0", OVERVIEW_values, std::extent<decltype(OVERVIEW_values)>::value};
}
const maxon::EnumInfo& PrivateGetEnumInfo_OVERVIEW325(){ return enum325::OVERVIEW_info; }
namespace enum347
{
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
		MULTILINE					= 0x0080			///< If the message is more than @em 255 characters and @em 4 lines then this bit should be set for Mac compatibility.\n
																		///< The dialog is then restricted to only an OK button with limited keyboard support.
	} ;
	static const maxon::UInt64 GEMB_values[] = {maxon::UInt64(enum347::GEMB::OK), maxon::UInt64(enum347::GEMB::OKCANCEL), maxon::UInt64(enum347::GEMB::ABORTRETRYIGNORE), maxon::UInt64(enum347::GEMB::YESNOCANCEL), maxon::UInt64(enum347::GEMB::YESNO), maxon::UInt64(enum347::GEMB::RETRYCANCEL), maxon::UInt64(enum347::GEMB::FORCEDIALOG), maxon::UInt64(enum347::GEMB::ICONSTOP), maxon::UInt64(enum347::GEMB::ICONQUESTION), maxon::UInt64(enum347::GEMB::ICONEXCLAMATION), maxon::UInt64(enum347::GEMB::ICONASTERISK), maxon::UInt64(enum347::GEMB::MULTILINE)};
	static const maxon::EnumInfo GEMB_info{"GEMB", SIZEOF(GEMB), true, "OK\0OKCANCEL\0ABORTRETRYIGNORE\0YESNOCANCEL\0YESNO\0RETRYCANCEL\0FORCEDIALOG\0ICONSTOP\0ICONQUESTION\0ICONEXCLAMATION\0ICONASTERISK\0MULTILINE\0", GEMB_values, std::extent<decltype(GEMB_values)>::value};
}
const maxon::EnumInfo& PrivateGetEnumInfo_GEMB347(){ return enum347::GEMB_info; }
namespace enum365
{
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
	} ;
	static const maxon::UInt64 GEMB_R_values[] = {maxon::UInt64(enum365::GEMB_R::V_UNDEFINED), maxon::UInt64(enum365::GEMB_R::V_OK), maxon::UInt64(enum365::GEMB_R::V_CANCEL), maxon::UInt64(enum365::GEMB_R::V_ABORT), maxon::UInt64(enum365::GEMB_R::V_RETRY), maxon::UInt64(enum365::GEMB_R::V_IGNORE), maxon::UInt64(enum365::GEMB_R::V_YES), maxon::UInt64(enum365::GEMB_R::V_NO)};
	static const maxon::EnumInfo GEMB_R_info{"GEMB_R", SIZEOF(GEMB_R), false, "V_UNDEFINED\0V_OK\0V_CANCEL\0V_ABORT\0V_RETRY\0V_IGNORE\0V_YES\0V_NO\0", GEMB_R_values, std::extent<decltype(GEMB_R_values)>::value};
}
const maxon::EnumInfo& PrivateGetEnumInfo_GEMB_R365(){ return enum365::GEMB_R_info; }
namespace enum377
{
	enum class MOUSEDRAGRESULT
	{
		ESCAPE		= 1,			///< Drag aborted.
		FINISHED	= 2,			///< Drag finished.
		CONTINUE	= 3				///< Drag still in progress.
	} ;
	static const maxon::UInt64 MOUSEDRAGRESULT_values[] = {maxon::UInt64(enum377::MOUSEDRAGRESULT::ESCAPE), maxon::UInt64(enum377::MOUSEDRAGRESULT::FINISHED), maxon::UInt64(enum377::MOUSEDRAGRESULT::CONTINUE)};
	static const maxon::EnumInfo MOUSEDRAGRESULT_info{"MOUSEDRAGRESULT", SIZEOF(MOUSEDRAGRESULT), false, "ESCAPE\0FINISHED\0CONTINUE\0", MOUSEDRAGRESULT_values, std::extent<decltype(MOUSEDRAGRESULT_values)>::value};
}
const maxon::EnumInfo& PrivateGetEnumInfo_MOUSEDRAGRESULT377(){ return enum377::MOUSEDRAGRESULT_info; }
namespace enum392
{
	enum class MOUSEDRAGFLAGS
	{
		NONE										= 0,						///< None.
		DONTHIDEMOUSE						= (1 << 0),			///< Show mouse pointer during drag.
		NOMOVE									= (1 << 1),			///< @c MouseDrag() returns @ref MOUSEDRAGRESULT::CONTINUE even if mouse is not moved. Otherwise @c MouseDrag() only returns if mouse is moved.
		EVERYPACKET							= (1 << 2),			///< Receive every packet of the queue, otherwise only data of the last packet.
		COMPENSATEVIEWPORTORG		= (1 << 3),			///< Compensates the viewport origin during drag.
		AIRBRUSH								= (1 << 4)			///< Airbrush mode.
	} ;
	static const maxon::UInt64 MOUSEDRAGFLAGS_values[] = {maxon::UInt64(enum392::MOUSEDRAGFLAGS::NONE), maxon::UInt64(enum392::MOUSEDRAGFLAGS::DONTHIDEMOUSE), maxon::UInt64(enum392::MOUSEDRAGFLAGS::NOMOVE), maxon::UInt64(enum392::MOUSEDRAGFLAGS::EVERYPACKET), maxon::UInt64(enum392::MOUSEDRAGFLAGS::COMPENSATEVIEWPORTORG), maxon::UInt64(enum392::MOUSEDRAGFLAGS::AIRBRUSH)};
	static const maxon::EnumInfo MOUSEDRAGFLAGS_info{"MOUSEDRAGFLAGS", SIZEOF(MOUSEDRAGFLAGS), true, "NONE\0DONTHIDEMOUSE\0NOMOVE\0EVERYPACKET\0COMPENSATEVIEWPORTORG\0AIRBRUSH\0", MOUSEDRAGFLAGS_values, std::extent<decltype(MOUSEDRAGFLAGS_values)>::value};
}
const maxon::EnumInfo& PrivateGetEnumInfo_MOUSEDRAGFLAGS392(){ return enum392::MOUSEDRAGFLAGS_info; }
namespace enum406
{
	enum class INITRENDERRESULT
	{
		OK						= 0,				///< Everything is OK, there was no error.
		OUTOFMEMORY		= -100,			///< Not enough memory.
		ASSETMISSING	= -101,			///< Assets (textures etc.) are missing.
		UNKNOWNERROR	= -102,			///< Unknown error.
		USERBREAK			= -103			///< Thread has been canceled. @since R17.032 Was @c INITRENDERRESULT_THREADEDLOCK.
	} ;
	static const maxon::UInt64 INITRENDERRESULT_values[] = {maxon::UInt64(enum406::INITRENDERRESULT::OK), maxon::UInt64(enum406::INITRENDERRESULT::OUTOFMEMORY), maxon::UInt64(enum406::INITRENDERRESULT::ASSETMISSING), maxon::UInt64(enum406::INITRENDERRESULT::UNKNOWNERROR), maxon::UInt64(enum406::INITRENDERRESULT::USERBREAK)};
	static const maxon::EnumInfo INITRENDERRESULT_info{"INITRENDERRESULT", SIZEOF(INITRENDERRESULT), false, "OK\0OUTOFMEMORY\0ASSETMISSING\0UNKNOWNERROR\0USERBREAK\0", INITRENDERRESULT_values, std::extent<decltype(INITRENDERRESULT_values)>::value};
}
const maxon::EnumInfo& PrivateGetEnumInfo_INITRENDERRESULT406(){ return enum406::INITRENDERRESULT_info; }
namespace enum428
{
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
	} ;
	static const maxon::UInt64 RENDERRESULT_values[] = {maxon::UInt64(enum428::RENDERRESULT::OK), maxon::UInt64(enum428::RENDERRESULT::OUTOFMEMORY), maxon::UInt64(enum428::RENDERRESULT::ASSETMISSING), maxon::UInt64(enum428::RENDERRESULT::SAVINGFAILED), maxon::UInt64(enum428::RENDERRESULT::USERBREAK), maxon::UInt64(enum428::RENDERRESULT::GICACHEMISSING), maxon::UInt64(enum428::RENDERRESULT::NOMACHINE), maxon::UInt64(enum428::RENDERRESULT::UNAVAILABLE), maxon::UInt64(enum428::RENDERRESULT::FAILED), maxon::UInt64(enum428::RENDERRESULT::PROJECTNOTFOUND), maxon::UInt64(enum428::RENDERRESULT::ERRORLOADINGPROJECT), maxon::UInt64(enum428::RENDERRESULT::NOOUTPUTSPECIFIED)};
	static const maxon::EnumInfo RENDERRESULT_info{"RENDERRESULT", SIZEOF(RENDERRESULT), false, "OK\0OUTOFMEMORY\0ASSETMISSING\0SAVINGFAILED\0USERBREAK\0GICACHEMISSING\0NOMACHINE\0UNAVAILABLE\0FAILED\0PROJECTNOTFOUND\0ERRORLOADINGPROJECT\0NOOUTPUTSPECIFIED\0", RENDERRESULT_values, std::extent<decltype(RENDERRESULT_values)>::value};
}
const maxon::EnumInfo& PrivateGetEnumInfo_RENDERRESULT428(){ return enum428::RENDERRESULT_info; }
namespace enum482
{
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
	} ;
	static const maxon::UInt64 COLORMODE_values[] = {maxon::UInt64(enum482::COLORMODE::ILLEGAL), maxon::UInt64(enum482::COLORMODE::ALPHA), maxon::UInt64(enum482::COLORMODE::GRAY), maxon::UInt64(enum482::COLORMODE::AGRAY), maxon::UInt64(enum482::COLORMODE::RGB), maxon::UInt64(enum482::COLORMODE::ARGB), maxon::UInt64(enum482::COLORMODE::CMYK), maxon::UInt64(enum482::COLORMODE::ACMYK), maxon::UInt64(enum482::COLORMODE::MASK), maxon::UInt64(enum482::COLORMODE::AMASK), maxon::UInt64(enum482::COLORMODE::ILLEGALw), maxon::UInt64(enum482::COLORMODE::GRAYw), maxon::UInt64(enum482::COLORMODE::AGRAYw), maxon::UInt64(enum482::COLORMODE::RGBw), maxon::UInt64(enum482::COLORMODE::ARGBw), maxon::UInt64(enum482::COLORMODE::MASKw), maxon::UInt64(enum482::COLORMODE::ILLEGALf), maxon::UInt64(enum482::COLORMODE::GRAYf), maxon::UInt64(enum482::COLORMODE::AGRAYf), maxon::UInt64(enum482::COLORMODE::RGBf), maxon::UInt64(enum482::COLORMODE::ARGBf), maxon::UInt64(enum482::COLORMODE::MASKf)};
	static const maxon::EnumInfo COLORMODE_info{"COLORMODE", SIZEOF(COLORMODE), true, "ILLEGAL\0ALPHA\0GRAY\0AGRAY\0RGB\0ARGB\0CMYK\0ACMYK\0MASK\0AMASK\0ILLEGALw\0GRAYw\0AGRAYw\0RGBw\0ARGBw\0MASKw\0ILLEGALf\0GRAYf\0AGRAYf\0RGBf\0ARGBf\0MASKf\0", COLORMODE_values, std::extent<decltype(COLORMODE_values)>::value};
}
const maxon::EnumInfo& PrivateGetEnumInfo_COLORMODE482(){ return enum482::COLORMODE_info; }
namespace enum505
{
	enum class COLORSPACETRANSFORMATION
	{
		NONE						= 0,			///< None.
		LINEAR_TO_SRGB	= 1,			///< Linear to sRGB color space transformation.
		SRGB_TO_LINEAR	= 2,			///< sRGB to linear color space transformation.
	
		LINEAR_TO_VIEW	= 10,			///< Linear to display color space transformation.
		SRGB_TO_VIEW		= 11,			///< sRGB to display color space transformation.
		
		OCIO_INPUT_LOW_TO_RENDERING		= SRGB_TO_LINEAR,		///< @markPrivate
		OCIO_RENDERING_TO_INPUT				= LINEAR_TO_SRGB,		///< @markPrivate
		OCIO_RENDERING_TO_VIEW 				= LINEAR_TO_VIEW,		///< @markPrivate
		OCIO_INPUT_TO_VIEW 						= SRGB_TO_VIEW,			///< @markPrivate
		OCIO_VIEW_TO_RENDERING				= 22,								///< @markPrivate
		OCIO_VIEW_TO_INPUT						= 23,								///< @markPrivate
		OCIO_INPUT_HIGH_TO_RENDERING	= 24,								///< @markPrivate
	} ;
	static const maxon::UInt64 COLORSPACETRANSFORMATION_values[] = {maxon::UInt64(enum505::COLORSPACETRANSFORMATION::NONE), maxon::UInt64(enum505::COLORSPACETRANSFORMATION::LINEAR_TO_SRGB), maxon::UInt64(enum505::COLORSPACETRANSFORMATION::SRGB_TO_LINEAR), maxon::UInt64(enum505::COLORSPACETRANSFORMATION::LINEAR_TO_VIEW), maxon::UInt64(enum505::COLORSPACETRANSFORMATION::SRGB_TO_VIEW), maxon::UInt64(enum505::COLORSPACETRANSFORMATION::OCIO_INPUT_LOW_TO_RENDERING), maxon::UInt64(enum505::COLORSPACETRANSFORMATION::OCIO_RENDERING_TO_INPUT), maxon::UInt64(enum505::COLORSPACETRANSFORMATION::OCIO_RENDERING_TO_VIEW), maxon::UInt64(enum505::COLORSPACETRANSFORMATION::OCIO_INPUT_TO_VIEW), maxon::UInt64(enum505::COLORSPACETRANSFORMATION::OCIO_VIEW_TO_RENDERING), maxon::UInt64(enum505::COLORSPACETRANSFORMATION::OCIO_VIEW_TO_INPUT), maxon::UInt64(enum505::COLORSPACETRANSFORMATION::OCIO_INPUT_HIGH_TO_RENDERING)};
	static const maxon::EnumInfo COLORSPACETRANSFORMATION_info{"COLORSPACETRANSFORMATION", SIZEOF(COLORSPACETRANSFORMATION), false, "NONE\0LINEAR_TO_SRGB\0SRGB_TO_LINEAR\0LINEAR_TO_VIEW\0SRGB_TO_VIEW\0OCIO_INPUT_LOW_TO_RENDERING\0OCIO_RENDERING_TO_INPUT\0OCIO_RENDERING_TO_VIEW\0OCIO_INPUT_TO_VIEW\0OCIO_VIEW_TO_RENDERING\0OCIO_VIEW_TO_INPUT\0OCIO_INPUT_HIGH_TO_RENDERING\0", COLORSPACETRANSFORMATION_values, std::extent<decltype(COLORSPACETRANSFORMATION_values)>::value};
}
const maxon::EnumInfo& PrivateGetEnumInfo_COLORSPACETRANSFORMATION505(){ return enum505::COLORSPACETRANSFORMATION_info; }
namespace enum517
{
	enum class VIEW_WINDOW_COLOR_SPACE : Int32
	{
		UNDEFINED	= 0,			///< Undefined, e.g. if there is no ViewWindow for the BaseDraw.
		LINEAR		= 1,			///< Linear.
		SRGB			= 2,			///< sRGB.
	} ;
	static const maxon::UInt64 VIEW_WINDOW_COLOR_SPACE_values[] = {maxon::UInt64(enum517::VIEW_WINDOW_COLOR_SPACE::UNDEFINED), maxon::UInt64(enum517::VIEW_WINDOW_COLOR_SPACE::LINEAR), maxon::UInt64(enum517::VIEW_WINDOW_COLOR_SPACE::SRGB)};
	static const maxon::EnumInfo VIEW_WINDOW_COLOR_SPACE_info{"VIEW_WINDOW_COLOR_SPACE", SIZEOF(VIEW_WINDOW_COLOR_SPACE), false, "UNDEFINED\0LINEAR\0SRGB\0", VIEW_WINDOW_COLOR_SPACE_values, std::extent<decltype(VIEW_WINDOW_COLOR_SPACE_values)>::value};
}
const maxon::EnumInfo& PrivateGetEnumInfo_VIEW_WINDOW_COLOR_SPACE517(){ return enum517::VIEW_WINDOW_COLOR_SPACE_info; }
namespace enum532
{
	enum class PIXELCNT
	{
		NONE									= 0,							///< None.
		DITHERING							= (1 << 0),				///< Allow dithering.
		B3DLAYERS							= (1 << 1),				///< Merge @BP3D layers (MultipassBitmap).
		APPLYALPHA						= (1 << 2),				///< Apply alpha layers to the result (PaintLayer).
		INTERNAL_SETLINE			= (1 << 29),			///< Internal SetLine indicator. @markPrivate
		INTERNAL_ALPHAVALUE		= (1 << 30)				///< Get also the alpha value (RGBA <i>32</i>-bit). @markPrivate
	} ;
	static const maxon::UInt64 PIXELCNT_values[] = {maxon::UInt64(enum532::PIXELCNT::NONE), maxon::UInt64(enum532::PIXELCNT::DITHERING), maxon::UInt64(enum532::PIXELCNT::B3DLAYERS), maxon::UInt64(enum532::PIXELCNT::APPLYALPHA), maxon::UInt64(enum532::PIXELCNT::INTERNAL_SETLINE), maxon::UInt64(enum532::PIXELCNT::INTERNAL_ALPHAVALUE)};
	static const maxon::EnumInfo PIXELCNT_info{"PIXELCNT", SIZEOF(PIXELCNT), true, "NONE\0DITHERING\0B3DLAYERS\0APPLYALPHA\0INTERNAL_SETLINE\0INTERNAL_ALPHAVALUE\0", PIXELCNT_values, std::extent<decltype(PIXELCNT_values)>::value};
}
const maxon::EnumInfo& PrivateGetEnumInfo_PIXELCNT532(){ return enum532::PIXELCNT_info; }
namespace enum546
{
	enum class INITBITMAPFLAGS
	{
		NONE			= 0,						///< None.
		GRAYSCALE	= (1 << 0),			///< Initialize as grayscale bitmap.
		SYSTEM		= (1 << 1),			///< @markPrivate
		DPNULL		= (1 << 2)			///< @markPrivate
	} ;
	static const maxon::UInt64 INITBITMAPFLAGS_values[] = {maxon::UInt64(enum546::INITBITMAPFLAGS::NONE), maxon::UInt64(enum546::INITBITMAPFLAGS::GRAYSCALE), maxon::UInt64(enum546::INITBITMAPFLAGS::SYSTEM), maxon::UInt64(enum546::INITBITMAPFLAGS::DPNULL)};
	static const maxon::EnumInfo INITBITMAPFLAGS_info{"INITBITMAPFLAGS", SIZEOF(INITBITMAPFLAGS), true, "NONE\0GRAYSCALE\0SYSTEM\0DPNULL\0", INITBITMAPFLAGS_values, std::extent<decltype(INITBITMAPFLAGS_values)>::value};
}
const maxon::EnumInfo& PrivateGetEnumInfo_INITBITMAPFLAGS546(){ return enum546::INITBITMAPFLAGS_info; }
namespace enum558
{
	enum class MPB_GETLAYERS
	{
		NONE	= 0,						///< None.
		ALPHA	= (1 << 1),			///< Get alpha layers.
		IMAGE	= (1 << 2)			///< Get image layers.
	} ;
	static const maxon::UInt64 MPB_GETLAYERS_values[] = {maxon::UInt64(enum558::MPB_GETLAYERS::NONE), maxon::UInt64(enum558::MPB_GETLAYERS::ALPHA), maxon::UInt64(enum558::MPB_GETLAYERS::IMAGE)};
	static const maxon::EnumInfo MPB_GETLAYERS_info{"MPB_GETLAYERS", SIZEOF(MPB_GETLAYERS), true, "NONE\0ALPHA\0IMAGE\0", MPB_GETLAYERS_values, std::extent<decltype(MPB_GETLAYERS_values)>::value};
}
const maxon::EnumInfo& PrivateGetEnumInfo_MPB_GETLAYERS558(){ return enum558::MPB_GETLAYERS_info; }
namespace enum578
{
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
	} ;
	static const maxon::UInt64 MPBTYPE_values[] = {maxon::UInt64(enum578::MPBTYPE::SHOW), maxon::UInt64(enum578::MPBTYPE::SAVE), maxon::UInt64(enum578::MPBTYPE::PERCENT), maxon::UInt64(enum578::MPBTYPE::BLENDMODE), maxon::UInt64(enum578::MPBTYPE::COLORMODE), maxon::UInt64(enum578::MPBTYPE::BITMAPTYPE), maxon::UInt64(enum578::MPBTYPE::NAME), maxon::UInt64(enum578::MPBTYPE::DPI), maxon::UInt64(enum578::MPBTYPE::USERID), maxon::UInt64(enum578::MPBTYPE::USERSUBID), maxon::UInt64(enum578::MPBTYPE::FORCEBLEND)};
	static const maxon::EnumInfo MPBTYPE_info{"MPBTYPE", SIZEOF(MPBTYPE), false, "SHOW\0SAVE\0PERCENT\0BLENDMODE\0COLORMODE\0BITMAPTYPE\0NAME\0DPI\0USERID\0USERSUBID\0FORCEBLEND\0", MPBTYPE_values, std::extent<decltype(MPBTYPE_values)>::value};
}
const maxon::EnumInfo& PrivateGetEnumInfo_MPBTYPE578(){ return enum578::MPBTYPE_info; }
namespace enum598
{
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
	} ;
	static const maxon::UInt64 LENGTHUNIT_values[] = {maxon::UInt64(enum598::LENGTHUNIT::PIXEL), maxon::UInt64(enum598::LENGTHUNIT::KM), maxon::UInt64(enum598::LENGTHUNIT::M), maxon::UInt64(enum598::LENGTHUNIT::CM), maxon::UInt64(enum598::LENGTHUNIT::MM), maxon::UInt64(enum598::LENGTHUNIT::UM), maxon::UInt64(enum598::LENGTHUNIT::NM), maxon::UInt64(enum598::LENGTHUNIT::MILE), maxon::UInt64(enum598::LENGTHUNIT::YARD), maxon::UInt64(enum598::LENGTHUNIT::FEET), maxon::UInt64(enum598::LENGTHUNIT::INCH)};
	static const maxon::EnumInfo LENGTHUNIT_info{"LENGTHUNIT", SIZEOF(LENGTHUNIT), false, "PIXEL\0KM\0M\0CM\0MM\0UM\0NM\0MILE\0YARD\0FEET\0INCH\0", LENGTHUNIT_values, std::extent<decltype(LENGTHUNIT_values)>::value};
}
const maxon::EnumInfo& PrivateGetEnumInfo_LENGTHUNIT598(){ return enum598::LENGTHUNIT_info; }
namespace enum615
{
	enum class SPLINETYPE
	{
		LINEAR								= 0,		///< Linear.
		CUBIC									= 1,		///< Cubic.
		AKIMA									= 2,		///< Akima.
		BSPLINE								= 3,		///< B-Spline.
		BEZIER								= 4,		///< Bezier.
		RESERVEDSPLINETYPE1		= 5,		///< @markInternal @since R17.032
		RESERVEDSPLINETYPE2		= 6			///< @markInternal @since R17.032
	} ;
	static const maxon::UInt64 SPLINETYPE_values[] = {maxon::UInt64(enum615::SPLINETYPE::LINEAR), maxon::UInt64(enum615::SPLINETYPE::CUBIC), maxon::UInt64(enum615::SPLINETYPE::AKIMA), maxon::UInt64(enum615::SPLINETYPE::BSPLINE), maxon::UInt64(enum615::SPLINETYPE::BEZIER), maxon::UInt64(enum615::SPLINETYPE::RESERVEDSPLINETYPE1), maxon::UInt64(enum615::SPLINETYPE::RESERVEDSPLINETYPE2)};
	static const maxon::EnumInfo SPLINETYPE_info{"SPLINETYPE", SIZEOF(SPLINETYPE), false, "LINEAR\0CUBIC\0AKIMA\0BSPLINE\0BEZIER\0RESERVEDSPLINETYPE1\0RESERVEDSPLINETYPE2\0", SPLINETYPE_values, std::extent<decltype(SPLINETYPE_values)>::value};
}
const maxon::EnumInfo& PrivateGetEnumInfo_SPLINETYPE615(){ return enum615::SPLINETYPE_info; }
namespace enum628
{
	enum class BREAKTANGENTS
	{
		// V_ unfortunately has to be used here due to conflicts with MAC OS
		V_FALSE	=	0,			///< Do not break any tangents.
		V_TRUE	=	1,			///< Break the tangents.
		V_AUTO	= 2				///< Only break the tangents if the tangents are already broken.
	} ;
	static const maxon::UInt64 BREAKTANGENTS_values[] = {maxon::UInt64(enum628::BREAKTANGENTS::V_FALSE), maxon::UInt64(enum628::BREAKTANGENTS::V_TRUE), maxon::UInt64(enum628::BREAKTANGENTS::V_AUTO)};
	static const maxon::EnumInfo BREAKTANGENTS_info{"BREAKTANGENTS", SIZEOF(BREAKTANGENTS), false, "V_FALSE\0V_TRUE\0V_AUTO\0", BREAKTANGENTS_values, std::extent<decltype(BREAKTANGENTS_values)>::value};
}
const maxon::EnumInfo& PrivateGetEnumInfo_BREAKTANGENTS628(){ return enum628::BREAKTANGENTS_info; }
namespace enum640
{
	enum class TANGENTSIDE
	{
		NONE	=	-1,			///< No tangent handles being modified.
		LEFT	= 0,			///< Modify the left tangent handle.
		RIGHT	= 1,			///< Modify the right tangent handle.
	} ;
	static const maxon::UInt64 TANGENTSIDE_values[] = {maxon::UInt64(enum640::TANGENTSIDE::NONE), maxon::UInt64(enum640::TANGENTSIDE::LEFT), maxon::UInt64(enum640::TANGENTSIDE::RIGHT)};
	static const maxon::EnumInfo TANGENTSIDE_info{"TANGENTSIDE", SIZEOF(TANGENTSIDE), false, "NONE\0LEFT\0RIGHT\0", TANGENTSIDE_values, std::extent<decltype(TANGENTSIDE_values)>::value};
}
const maxon::EnumInfo& PrivateGetEnumInfo_TANGENTSIDE640(){ return enum640::TANGENTSIDE_info; }
namespace enum654
{
	enum class TANGENTTRANSFORMFLAG
	{
		NONE					=	0,																					///< No transform flag.
		LOCK_LENGTH		=	(1 << 0),																		///< Fix the length of the tangents, only change the rotation.
		LOCK_ANGLE		=	(1 << 1),																		///< Fix the angle of the tangents, only change the length.
		BREAK_SCALE		=	(1 << 2),																		///< Only scale one handle (but rotate both).
		BREAK					=	TANGENTTRANSFORMFLAG::BREAK_SCALE|(1 << 3)		///< Only modify one handle.
	} ;
	static const maxon::UInt64 TANGENTTRANSFORMFLAG_values[] = {maxon::UInt64(enum654::TANGENTTRANSFORMFLAG::NONE), maxon::UInt64(enum654::TANGENTTRANSFORMFLAG::LOCK_LENGTH), maxon::UInt64(enum654::TANGENTTRANSFORMFLAG::LOCK_ANGLE), maxon::UInt64(enum654::TANGENTTRANSFORMFLAG::BREAK_SCALE), maxon::UInt64(enum654::TANGENTTRANSFORMFLAG::BREAK)};
	static const maxon::EnumInfo TANGENTTRANSFORMFLAG_info{"TANGENTTRANSFORMFLAG", SIZEOF(TANGENTTRANSFORMFLAG), true, "NONE\0LOCK_LENGTH\0LOCK_ANGLE\0BREAK_SCALE\0BREAK\0", TANGENTTRANSFORMFLAG_values, std::extent<decltype(TANGENTTRANSFORMFLAG_values)>::value};
}
const maxon::EnumInfo& PrivateGetEnumInfo_TANGENTTRANSFORMFLAG654(){ return enum654::TANGENTTRANSFORMFLAG_info; }
namespace enum668
{
	enum class SPLINEBOOL_AXIS
	{
		NONE			= 0,			///< No axis.
		SCREEN		=	1,			///< Project into the current screen.
		ZY				=	2,			///< Project on the ZY (X axis) plane.
		XZ				= 3,			///< Project on the XZ (Y axis) plane.
		XY				= 4				///< Project on the XY (Z axis) plane.
	} ;
	static const maxon::UInt64 SPLINEBOOL_AXIS_values[] = {maxon::UInt64(enum668::SPLINEBOOL_AXIS::NONE), maxon::UInt64(enum668::SPLINEBOOL_AXIS::SCREEN), maxon::UInt64(enum668::SPLINEBOOL_AXIS::ZY), maxon::UInt64(enum668::SPLINEBOOL_AXIS::XZ), maxon::UInt64(enum668::SPLINEBOOL_AXIS::XY)};
	static const maxon::EnumInfo SPLINEBOOL_AXIS_info{"SPLINEBOOL_AXIS", SIZEOF(SPLINEBOOL_AXIS), false, "NONE\0SCREEN\0ZY\0XZ\0XY\0", SPLINEBOOL_AXIS_values, std::extent<decltype(SPLINEBOOL_AXIS_values)>::value};
}
const maxon::EnumInfo& PrivateGetEnumInfo_SPLINEBOOL_AXIS668(){ return enum668::SPLINEBOOL_AXIS_info; }
namespace enum683
{
	enum class SPLINEBOOL_MODE
	{
		AMINUSB				=	0,			///< Subtract B from A.
		BMINUSA				=	1,			///< Subtract A from B.
		UNION					=	2,			///< Union of both A and B.
		AND						=	3,			///< And intersection (overlap) of region of A and B.
		OR						=	4,			///< Or intersection (outside of overlap) of region of A and B.
		INTERSECTION	=	5,			///< Intersection (all segments inside and out) of region of A and B.
	} ;
	static const maxon::UInt64 SPLINEBOOL_MODE_values[] = {maxon::UInt64(enum683::SPLINEBOOL_MODE::AMINUSB), maxon::UInt64(enum683::SPLINEBOOL_MODE::BMINUSA), maxon::UInt64(enum683::SPLINEBOOL_MODE::UNION), maxon::UInt64(enum683::SPLINEBOOL_MODE::AND), maxon::UInt64(enum683::SPLINEBOOL_MODE::OR), maxon::UInt64(enum683::SPLINEBOOL_MODE::INTERSECTION)};
	static const maxon::EnumInfo SPLINEBOOL_MODE_info{"SPLINEBOOL_MODE", SIZEOF(SPLINEBOOL_MODE), false, "AMINUSB\0BMINUSA\0UNION\0AND\0OR\0INTERSECTION\0", SPLINEBOOL_MODE_values, std::extent<decltype(SPLINEBOOL_MODE_values)>::value};
}
const maxon::EnumInfo& PrivateGetEnumInfo_SPLINEBOOL_MODE683(){ return enum683::SPLINEBOOL_MODE_info; }
namespace enum695
{
	enum class PARTICLEFLAGS
	{
		NONE		= 0,						///< None.
		VISIBLE	= (1 << 0),			///< %Particle is visible.
		ALIVE		= (1 << 1)			///< %Particle is alive.
	} ;
	static const maxon::UInt64 PARTICLEFLAGS_values[] = {maxon::UInt64(enum695::PARTICLEFLAGS::NONE), maxon::UInt64(enum695::PARTICLEFLAGS::VISIBLE), maxon::UInt64(enum695::PARTICLEFLAGS::ALIVE)};
	static const maxon::EnumInfo PARTICLEFLAGS_info{"PARTICLEFLAGS", SIZEOF(PARTICLEFLAGS), true, "NONE\0VISIBLE\0ALIVE\0", PARTICLEFLAGS_values, std::extent<decltype(PARTICLEFLAGS_values)>::value};
}
const maxon::EnumInfo& PrivateGetEnumInfo_PARTICLEFLAGS695(){ return enum695::PARTICLEFLAGS_info; }
namespace enum823
{
	enum class NBIT
	{
		NONE									= 0,			///< None.
	
		TL1_FOLD							= 1,			///< Folding bit for Timeline 1.
		TL2_FOLD							= 2,			///< Folding bit for Timeline 2.
		TL3_FOLD							= 3,			///< Folding bit for Timeline 3.
		TL4_FOLD							= 4,			///< Folding bit for Timeline 4.
	
		TL1_SELECT						= 5,			///< Selection bit for Timeline 1.
		TL2_SELECT						= 6,			///< Selection bit for Timeline 2.
		TL3_SELECT						= 7,			///< Selection bit for Timeline 3.
		TL4_SELECT						= 8,			///< Selection bit for Timeline 4.
	
		TL1_TDRAW							= 9,			///< @markPrivate
		TL2_TDRAW							= 10,			///< @markPrivate
		TL3_TDRAW							= 11,			///< @markPrivate
		TL4_TDRAW							= 12,			///< @markPrivate
	
		CKEY_ACTIVE						= 13,			///< Active point of animation path in editor.
	
		OM1_FOLD							= 14,			///< Folding bit for Object Manager 1.
		OM2_FOLD							= 15,			///< Folding bit for Object Manager 2.
		OM3_FOLD							= 16,			///< Folding bit for Object Manager 3.
		OM4_FOLD							= 17,			///< Folding bit for Object Manager 4.
	
		TL1_FOLDTR						= 18,			///< Track folding for Timeline 1.
		TL2_FOLDTR						= 19,			///< Track folding for Timeline 2.
		TL3_FOLDTR						= 20,			///< Track folding for Timeline 3.
		TL4_FOLDTR						= 21,			///< Track folding for Timeline 4.
	
		TL1_FOLDFC						= 22,			///< F-Curve folding for Timeline 1.
		TL2_FOLDFC						= 23,			///< F-Curve folding for Timeline 2.
		TL3_FOLDFC						= 24,			///< F-Curve folding for Timeline 3.
		TL4_FOLDFC						= 25,			///< F-Curve folding for Timeline 4.
	
		SOURCEOPEN						= 26,			///< Source open in motion clip hierarchy tree.
	
		TL1_HIDE							= 27,			///< Hide in Timeline 1.
		TL2_HIDE							= 28,			///< Hide in Timeline 2.
		TL3_HIDE							= 29,			///< Hide in Timeline 3.
		TL4_HIDE							= 30,			///< Hide in Timeline 4.
	
		SOLO_ANIM							= 31,			///< Solo animation.
		SOLO_LAYER						= 32,			///< Solo layer.
	
		TL1_SELECT2						= 33,			///< @markPrivate
		TL2_SELECT2						= 34,			///< @markPrivate
		TL3_SELECT2						= 35,			///< @markPrivate
		TL4_SELECT2						= 36,			///< @markPrivate
	
		SOLO_MOTION						= 37,			///< Solo motion.
	
		CKEY_LOCK_T						= 38,			///< Lock key time.
		CKEY_LOCK_V						= 39,			///< Lock key value.
		CKEY_MUTE							= 40,			///< Mute key.
		CKEY_CLAMP						= 41,			///< Clamp key tangents.
	
		CKEY_BREAK						= 42,			///< Break key tangents.
		CKEY_KEEPVISUALANGLE	= 43,			///< Keep visual angle.
	
		CKEY_LOCK_O						= 44,			///< Lock key tangents angles.
		CKEY_LOCK_L						= 45,			///< Lock key tangents length.
		CKEY_AUTO							= 46,			///< Key auto tangents.
		CKEY_ZERO_O_OLD				= 48,			///< @markDeprecated
		CKEY_ZERO_L_OLD				= 49,			///< @markDeprecated
	
		// This is a legacy mode use TL(1-2-3-4)_SELECT2 instead.
		TL1_FCSELECT					= 50,			///< F-Curve selection bit for Timeline 1.
		TL2_FCSELECT					= 51,			///< F-Curve selection bit for Timeline 2.
		TL3_FCSELECT					= 52,			///< F-Curve selection bit for Timeline 3.
		TL4_FCSELECT					= 53,			///< F-Curve selection bit for Timeline 4.
	
		CKEY_BREAKDOWN				= 54,			///< @markPrivate
	
		TL1_FOLDMOTION				= 55,			///< Motion clip folding for Timeline 1.
		TL2_FOLDMOTION				= 56,			///< Motion clip folding for Timeline 2.
		TL3_FOLDMOTION				= 57,			///< Motion clip folding for Timeline 3.
		TL4_FOLDMOTION				= 58,			///< Motion clip folding for Timeline 4.
	
		TL1_SELECTMOTION			= 59,			///< Motion clip selection for Timeline 1.
		TL2_SELECTMOTION			= 60,			///< Motion clip selection for Timeline 2.
		TL3_SELECTMOTION			= 61,			///< Motion clip selection for Timeline 3.
		TL4_SELECTMOTION			= 62,			///< Motion clip selection for Timeline 4.
	
		OHIDE								= 63,				///< Hide object/tag in Object Manager or material in %Material Manager. @note OHIDE should not be used to store BaseList2Ds that do not interact with the user, as they clutter the manager and thus decrease its performance. Instead a special branch should be used to store these BaseList2Ds.
		TL_TBAKE							= 64,			///< @markPrivate
	
		TL1_FOLDSM						= 66,			///< @markPrivate
		TL2_FOLDSM						= 67,			///< @markPrivate
		TL3_FOLDSM						= 68,			///< @markPrivate
		TL4_FOLDSM						= 69,			///< @markPrivate
	
		SUBOBJECT							= 70,			///< @markPrivate
		LINK_ACTIVE						= 71,			///< @markPrivate
		THIDE									= 72,			///< Hide object in Timeline.
		SUBOBJECT_AM					= 74,			///< @markPrivate
		PROTECTION						= 75,			///< PSR protection.
		NOANIM								= 76,			///< No animation.
		NOSELECT							= 77,			///< No selection.
		EHIDE									= 78,			///< Hide in viewport.
		REF										= 79,			///< XRef.
		REF_NO_DD							= 80,			///< XRef object no drag and drop. @markPrivate
		REF_OHIDE							= 81,			///< XRef object hide. @markPrivate
		NO_DD									= 82,			///< No drag and drop duplication.
		HIDEEXCEPTVIEWSELECT	= 83,			///< Hide in viewport except to viewport select.
		CKEY_WEIGHTEDTANGENT	= 84,			///< Weighted tangent. @since R17.032
		CKEY_REMOVEOVERSHOOT	= 85,			///< Gradual clamp of tangent to avoid over shooting. @since R17.032
		CKEY_AUTOWEIGHT				= 86,			///< Weight still adjusted even if angle is user defined. @since R17.032
		TAKE_LOCK							= 87,			///< A node in an override group cannot be changed. @since R17.032
		TAKE_OBJINGROUP				= 88,			///< The object is overridden by an override group. @since R17.032
		TAKE_EGROUPOVERIDDEN	= 89,			///< The object editor visibility is overridden by an override group. @since R17.032
		TAKE_RGROUPOVERIDDEN	= 90,			///< The object render visibility is overridden by an override group. @since R17.032
		CKEY_BREAKDOWNCOLOR		= 91,			///< The key is a golden pose. @since R18
		NO_DELETE							= 92,			///< No delete in Object Manager. @since R18
		LOD_HIDE							= 93,			///< Used by LOD object to hide itself outside the view. @since R19
		LOD_PRIVATECACHE			= 94,			///< @markPrivate @since R19
		AHIDE_FOR_HOST				= 95,			///< Hide Tag data in Attribute Manager when host object selected (tabs otherwise automatically added) @since R20
		NODE_TEMP							= 96,			///< @markPrivate @since R 23
		MAX										= 97,			///< Maximum @ref NBIT.
	} ;
	static const maxon::UInt64 NBIT_values[] = {maxon::UInt64(enum823::NBIT::NONE), maxon::UInt64(enum823::NBIT::TL1_FOLD), maxon::UInt64(enum823::NBIT::TL2_FOLD), maxon::UInt64(enum823::NBIT::TL3_FOLD), maxon::UInt64(enum823::NBIT::TL4_FOLD), maxon::UInt64(enum823::NBIT::TL1_SELECT), maxon::UInt64(enum823::NBIT::TL2_SELECT), maxon::UInt64(enum823::NBIT::TL3_SELECT), maxon::UInt64(enum823::NBIT::TL4_SELECT), maxon::UInt64(enum823::NBIT::TL1_TDRAW), maxon::UInt64(enum823::NBIT::TL2_TDRAW), maxon::UInt64(enum823::NBIT::TL3_TDRAW), maxon::UInt64(enum823::NBIT::TL4_TDRAW), maxon::UInt64(enum823::NBIT::CKEY_ACTIVE), maxon::UInt64(enum823::NBIT::OM1_FOLD), maxon::UInt64(enum823::NBIT::OM2_FOLD), maxon::UInt64(enum823::NBIT::OM3_FOLD), maxon::UInt64(enum823::NBIT::OM4_FOLD), maxon::UInt64(enum823::NBIT::TL1_FOLDTR), maxon::UInt64(enum823::NBIT::TL2_FOLDTR), maxon::UInt64(enum823::NBIT::TL3_FOLDTR), maxon::UInt64(enum823::NBIT::TL4_FOLDTR), maxon::UInt64(enum823::NBIT::TL1_FOLDFC), maxon::UInt64(enum823::NBIT::TL2_FOLDFC), maxon::UInt64(enum823::NBIT::TL3_FOLDFC), maxon::UInt64(enum823::NBIT::TL4_FOLDFC), maxon::UInt64(enum823::NBIT::SOURCEOPEN), maxon::UInt64(enum823::NBIT::TL1_HIDE), maxon::UInt64(enum823::NBIT::TL2_HIDE), maxon::UInt64(enum823::NBIT::TL3_HIDE), maxon::UInt64(enum823::NBIT::TL4_HIDE), maxon::UInt64(enum823::NBIT::SOLO_ANIM), maxon::UInt64(enum823::NBIT::SOLO_LAYER), maxon::UInt64(enum823::NBIT::TL1_SELECT2), maxon::UInt64(enum823::NBIT::TL2_SELECT2), maxon::UInt64(enum823::NBIT::TL3_SELECT2), maxon::UInt64(enum823::NBIT::TL4_SELECT2), maxon::UInt64(enum823::NBIT::SOLO_MOTION), maxon::UInt64(enum823::NBIT::CKEY_LOCK_T), maxon::UInt64(enum823::NBIT::CKEY_LOCK_V), maxon::UInt64(enum823::NBIT::CKEY_MUTE), maxon::UInt64(enum823::NBIT::CKEY_CLAMP), maxon::UInt64(enum823::NBIT::CKEY_BREAK), maxon::UInt64(enum823::NBIT::CKEY_KEEPVISUALANGLE), maxon::UInt64(enum823::NBIT::CKEY_LOCK_O), maxon::UInt64(enum823::NBIT::CKEY_LOCK_L), maxon::UInt64(enum823::NBIT::CKEY_AUTO), maxon::UInt64(enum823::NBIT::CKEY_ZERO_O_OLD), maxon::UInt64(enum823::NBIT::CKEY_ZERO_L_OLD), maxon::UInt64(enum823::NBIT::TL1_FCSELECT), maxon::UInt64(enum823::NBIT::TL2_FCSELECT), maxon::UInt64(enum823::NBIT::TL3_FCSELECT), maxon::UInt64(enum823::NBIT::TL4_FCSELECT), maxon::UInt64(enum823::NBIT::CKEY_BREAKDOWN), maxon::UInt64(enum823::NBIT::TL1_FOLDMOTION), maxon::UInt64(enum823::NBIT::TL2_FOLDMOTION), maxon::UInt64(enum823::NBIT::TL3_FOLDMOTION), maxon::UInt64(enum823::NBIT::TL4_FOLDMOTION), maxon::UInt64(enum823::NBIT::TL1_SELECTMOTION), maxon::UInt64(enum823::NBIT::TL2_SELECTMOTION), maxon::UInt64(enum823::NBIT::TL3_SELECTMOTION), maxon::UInt64(enum823::NBIT::TL4_SELECTMOTION), maxon::UInt64(enum823::NBIT::OHIDE), maxon::UInt64(enum823::NBIT::TL_TBAKE), maxon::UInt64(enum823::NBIT::TL1_FOLDSM), maxon::UInt64(enum823::NBIT::TL2_FOLDSM), maxon::UInt64(enum823::NBIT::TL3_FOLDSM), maxon::UInt64(enum823::NBIT::TL4_FOLDSM), maxon::UInt64(enum823::NBIT::SUBOBJECT), maxon::UInt64(enum823::NBIT::LINK_ACTIVE), maxon::UInt64(enum823::NBIT::THIDE), maxon::UInt64(enum823::NBIT::SUBOBJECT_AM), maxon::UInt64(enum823::NBIT::PROTECTION), maxon::UInt64(enum823::NBIT::NOANIM), maxon::UInt64(enum823::NBIT::NOSELECT), maxon::UInt64(enum823::NBIT::EHIDE), maxon::UInt64(enum823::NBIT::REF), maxon::UInt64(enum823::NBIT::REF_NO_DD), maxon::UInt64(enum823::NBIT::REF_OHIDE), maxon::UInt64(enum823::NBIT::NO_DD), maxon::UInt64(enum823::NBIT::HIDEEXCEPTVIEWSELECT), maxon::UInt64(enum823::NBIT::CKEY_WEIGHTEDTANGENT), maxon::UInt64(enum823::NBIT::CKEY_REMOVEOVERSHOOT), maxon::UInt64(enum823::NBIT::CKEY_AUTOWEIGHT), maxon::UInt64(enum823::NBIT::TAKE_LOCK), maxon::UInt64(enum823::NBIT::TAKE_OBJINGROUP), maxon::UInt64(enum823::NBIT::TAKE_EGROUPOVERIDDEN), maxon::UInt64(enum823::NBIT::TAKE_RGROUPOVERIDDEN), maxon::UInt64(enum823::NBIT::CKEY_BREAKDOWNCOLOR), maxon::UInt64(enum823::NBIT::NO_DELETE), maxon::UInt64(enum823::NBIT::LOD_HIDE), maxon::UInt64(enum823::NBIT::LOD_PRIVATECACHE), maxon::UInt64(enum823::NBIT::AHIDE_FOR_HOST), maxon::UInt64(enum823::NBIT::NODE_TEMP), maxon::UInt64(enum823::NBIT::MAX)};
	static const maxon::EnumInfo NBIT_info{"NBIT", SIZEOF(NBIT), false, "NONE\0TL1_FOLD\0TL2_FOLD\0TL3_FOLD\0TL4_FOLD\0TL1_SELECT\0TL2_SELECT\0TL3_SELECT\0TL4_SELECT\0TL1_TDRAW\0TL2_TDRAW\0TL3_TDRAW\0TL4_TDRAW\0CKEY_ACTIVE\0OM1_FOLD\0OM2_FOLD\0OM3_FOLD\0OM4_FOLD\0TL1_FOLDTR\0TL2_FOLDTR\0TL3_FOLDTR\0TL4_FOLDTR\0TL1_FOLDFC\0TL2_FOLDFC\0TL3_FOLDFC\0TL4_FOLDFC\0SOURCEOPEN\0TL1_HIDE\0TL2_HIDE\0TL3_HIDE\0TL4_HIDE\0SOLO_ANIM\0SOLO_LAYER\0TL1_SELECT2\0TL2_SELECT2\0TL3_SELECT2\0TL4_SELECT2\0SOLO_MOTION\0CKEY_LOCK_T\0CKEY_LOCK_V\0CKEY_MUTE\0CKEY_CLAMP\0CKEY_BREAK\0CKEY_KEEPVISUALANGLE\0CKEY_LOCK_O\0CKEY_LOCK_L\0CKEY_AUTO\0CKEY_ZERO_O_OLD\0CKEY_ZERO_L_OLD\0TL1_FCSELECT\0TL2_FCSELECT\0TL3_FCSELECT\0TL4_FCSELECT\0CKEY_BREAKDOWN\0TL1_FOLDMOTION\0TL2_FOLDMOTION\0TL3_FOLDMOTION\0TL4_FOLDMOTION\0TL1_SELECTMOTION\0TL2_SELECTMOTION\0TL3_SELECTMOTION\0TL4_SELECTMOTION\0OHIDE\0TL_TBAKE\0TL1_FOLDSM\0TL2_FOLDSM\0TL3_FOLDSM\0TL4_FOLDSM\0SUBOBJECT\0LINK_ACTIVE\0THIDE\0SUBOBJECT_AM\0PROTECTION\0NOANIM\0NOSELECT\0EHIDE\0REF\0REF_NO_DD\0REF_OHIDE\0NO_DD\0HIDEEXCEPTVIEWSELECT\0CKEY_WEIGHTEDTANGENT\0CKEY_REMOVEOVERSHOOT\0CKEY_AUTOWEIGHT\0TAKE_LOCK\0TAKE_OBJINGROUP\0TAKE_EGROUPOVERIDDEN\0TAKE_RGROUPOVERIDDEN\0CKEY_BREAKDOWNCOLOR\0NO_DELETE\0LOD_HIDE\0LOD_PRIVATECACHE\0AHIDE_FOR_HOST\0NODE_TEMP\0MAX\0", NBIT_values, std::extent<decltype(NBIT_values)>::value};
}
const maxon::EnumInfo& PrivateGetEnumInfo_NBIT823(){ return enum823::NBIT_info; }
namespace enum841
{
	enum class CREATEJOBRESULT
	{
		OK							= 0,			///< Ok.
		OUTOFMEMORY			= 1,			///< Out of memory.
		ASSETMISSING		= 2,			///< Asset missing.
		SAVINGFAILED		= 3,			///< Saving failed.
		REPOSITORYERROR	= 4				///< Repository error.
	} ;
	static const maxon::UInt64 CREATEJOBRESULT_values[] = {maxon::UInt64(enum841::CREATEJOBRESULT::OK), maxon::UInt64(enum841::CREATEJOBRESULT::OUTOFMEMORY), maxon::UInt64(enum841::CREATEJOBRESULT::ASSETMISSING), maxon::UInt64(enum841::CREATEJOBRESULT::SAVINGFAILED), maxon::UInt64(enum841::CREATEJOBRESULT::REPOSITORYERROR)};
	static const maxon::EnumInfo CREATEJOBRESULT_info{"CREATEJOBRESULT", SIZEOF(CREATEJOBRESULT), true, "OK\0OUTOFMEMORY\0ASSETMISSING\0SAVINGFAILED\0REPOSITORYERROR\0", CREATEJOBRESULT_values, std::extent<decltype(CREATEJOBRESULT_values)>::value};
}
const maxon::EnumInfo& PrivateGetEnumInfo_CREATEJOBRESULT841(){ return enum841::CREATEJOBRESULT_info; }
namespace enum854
{
	enum class NBITCONTROL
	{
		SET							= 1,				///< Set bit.
		CLEAR						= 2,				///< Clear bit.
		TOGGLE					= 3,				///< Toggle bit.
		PRIVATE_NODIRTY	= 0xf0			///< @markPrivate
	} ;
	static const maxon::UInt64 NBITCONTROL_values[] = {maxon::UInt64(enum854::NBITCONTROL::SET), maxon::UInt64(enum854::NBITCONTROL::CLEAR), maxon::UInt64(enum854::NBITCONTROL::TOGGLE), maxon::UInt64(enum854::NBITCONTROL::PRIVATE_NODIRTY)};
	static const maxon::EnumInfo NBITCONTROL_info{"NBITCONTROL", SIZEOF(NBITCONTROL), true, "SET\0CLEAR\0TOGGLE\0PRIVATE_NODIRTY\0", NBITCONTROL_values, std::extent<decltype(NBITCONTROL_values)>::value};
}
const maxon::EnumInfo& PrivateGetEnumInfo_NBITCONTROL854(){ return enum854::NBITCONTROL_info; }
namespace enum1707
{
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
	} ;
	static const maxon::UInt64 VOLUMECOMMANDTYPE_values[] = {maxon::UInt64(enum1707::VOLUMECOMMANDTYPE::NONE), maxon::UInt64(enum1707::VOLUMECOMMANDTYPE::VOLUMETOMESH), maxon::UInt64(enum1707::VOLUMECOMMANDTYPE::MESHTOVOLUME), maxon::UInt64(enum1707::VOLUMECOMMANDTYPE::VOLUMEBOOLE), maxon::UInt64(enum1707::VOLUMECOMMANDTYPE::PARTICLESTOVOLUME), maxon::UInt64(enum1707::VOLUMECOMMANDTYPE::SPLINETOVOLUME), maxon::UInt64(enum1707::VOLUMECOMMANDTYPE::FILTER), maxon::UInt64(enum1707::VOLUMECOMMANDTYPE::SDFFILTER), maxon::UInt64(enum1707::VOLUMECOMMANDTYPE::SDFTOFOG), maxon::UInt64(enum1707::VOLUMECOMMANDTYPE::FOGTOSDF), maxon::UInt64(enum1707::VOLUMECOMMANDTYPE::RESAMPLE), maxon::UInt64(enum1707::VOLUMECOMMANDTYPE::MIX), maxon::UInt64(enum1707::VOLUMECOMMANDTYPE::FIELDTOVOLUME), maxon::UInt64(enum1707::VOLUMECOMMANDTYPE::CREATESPHEREVOLUME), maxon::UInt64(enum1707::VOLUMECOMMANDTYPE::CREATEPLATONICVOLUME)};
	static const maxon::EnumInfo VOLUMECOMMANDTYPE_info{"VOLUMECOMMANDTYPE", SIZEOF(VOLUMECOMMANDTYPE), false, "NONE\0VOLUMETOMESH\0MESHTOVOLUME\0VOLUMEBOOLE\0PARTICLESTOVOLUME\0SPLINETOVOLUME\0FILTER\0SDFFILTER\0SDFTOFOG\0FOGTOSDF\0RESAMPLE\0MIX\0FIELDTOVOLUME\0CREATESPHEREVOLUME\0CREATEPLATONICVOLUME\0", VOLUMECOMMANDTYPE_values, std::extent<decltype(VOLUMECOMMANDTYPE_values)>::value};
}
const maxon::EnumInfo& PrivateGetEnumInfo_VOLUMECOMMANDTYPE1707(){ return enum1707::VOLUMECOMMANDTYPE_info; }
namespace enum1722
{
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
	} ;
	static const maxon::UInt64 GRIDTYPE_values[] = {maxon::UInt64(enum1722::GRIDTYPE::NONE), maxon::UInt64(enum1722::GRIDTYPE::FLOAT), maxon::UInt64(enum1722::GRIDTYPE::DOUBLE), maxon::UInt64(enum1722::GRIDTYPE::INT32), maxon::UInt64(enum1722::GRIDTYPE::INT64), maxon::UInt64(enum1722::GRIDTYPE::INTVECTOR32), maxon::UInt64(enum1722::GRIDTYPE::VECTOR32), maxon::UInt64(enum1722::GRIDTYPE::VECTOR64), maxon::UInt64(enum1722::GRIDTYPE::STRING), maxon::UInt64(enum1722::GRIDTYPE::BOOLEAN)};
	static const maxon::EnumInfo GRIDTYPE_info{"GRIDTYPE", SIZEOF(GRIDTYPE), false, "NONE\0FLOAT\0DOUBLE\0INT32\0INT64\0INTVECTOR32\0VECTOR32\0VECTOR64\0STRING\0BOOLEAN\0", GRIDTYPE_values, std::extent<decltype(GRIDTYPE_values)>::value};
}
const maxon::EnumInfo& PrivateGetEnumInfo_GRIDTYPE1722(){ return enum1722::GRIDTYPE_info; }
namespace enum1732
{
	enum class GRIDCLASS
	{
		NONE = 0,
		SDF = 1,
		FOG = 2,
		STAGGERED = 3,
		UNKNOWN = 4
	} ;
	static const maxon::UInt64 GRIDCLASS_values[] = {maxon::UInt64(enum1732::GRIDCLASS::NONE), maxon::UInt64(enum1732::GRIDCLASS::SDF), maxon::UInt64(enum1732::GRIDCLASS::FOG), maxon::UInt64(enum1732::GRIDCLASS::STAGGERED), maxon::UInt64(enum1732::GRIDCLASS::UNKNOWN)};
	static const maxon::EnumInfo GRIDCLASS_info{"GRIDCLASS", SIZEOF(GRIDCLASS), false, "NONE\0SDF\0FOG\0STAGGERED\0UNKNOWN\0", GRIDCLASS_values, std::extent<decltype(GRIDCLASS_values)>::value};
}
const maxon::EnumInfo& PrivateGetEnumInfo_GRIDCLASS1732(){ return enum1732::GRIDCLASS_info; }
namespace enum1747
{
	enum class VOLUMETOMESHSETTINGS
	{
		NONE = 0,
		ISO = 1,				///< ::Float Iso value to extract the mesh at.
		ADAPTIVE = 2		///< ::Float Adaptivity value for curvature based mesh reduction.
	} ;
	static const maxon::UInt64 VOLUMETOMESHSETTINGS_values[] = {maxon::UInt64(enum1747::VOLUMETOMESHSETTINGS::NONE), maxon::UInt64(enum1747::VOLUMETOMESHSETTINGS::ISO), maxon::UInt64(enum1747::VOLUMETOMESHSETTINGS::ADAPTIVE)};
	static const maxon::EnumInfo VOLUMETOMESHSETTINGS_info{"VOLUMETOMESHSETTINGS", SIZEOF(VOLUMETOMESHSETTINGS), false, "NONE\0ISO\0ADAPTIVE\0", VOLUMETOMESHSETTINGS_values, std::extent<decltype(VOLUMETOMESHSETTINGS_values)>::value};
}
const maxon::EnumInfo& PrivateGetEnumInfo_VOLUMETOMESHSETTINGS1747(){ return enum1747::VOLUMETOMESHSETTINGS_info; }
namespace enum1763
{
	enum class MESHTOVOLUMESETTINGS
	{
		NONE = 0,
		GRIDSIZE = 1,							///< ::Float Grid voxel cube size.
		BANDWIDTH_INTERIOR = 2,		///< ::Int32 Voxel Bandwidth amount around the mesh interior.
		BANDWIDTH_EXTERIOR = 3,		///< ::Int32 Voxel Bandwidth amount around the mesh exterior.
		USE_POINTS = 4,						///< ::Bool Use the vertices of the Mesh as particles for SDF construction.
		RADIUS = 5,								///< ::Float Radius for particle SDF construction if USE_POINTS is true.
		UNSIGNED_DISTANCE_FIELD = 6	///< ::Bool If true an unsigned distance field is created instead of a signed distance field.
	} ;
	static const maxon::UInt64 MESHTOVOLUMESETTINGS_values[] = {maxon::UInt64(enum1763::MESHTOVOLUMESETTINGS::NONE), maxon::UInt64(enum1763::MESHTOVOLUMESETTINGS::GRIDSIZE), maxon::UInt64(enum1763::MESHTOVOLUMESETTINGS::BANDWIDTH_INTERIOR), maxon::UInt64(enum1763::MESHTOVOLUMESETTINGS::BANDWIDTH_EXTERIOR), maxon::UInt64(enum1763::MESHTOVOLUMESETTINGS::USE_POINTS), maxon::UInt64(enum1763::MESHTOVOLUMESETTINGS::RADIUS), maxon::UInt64(enum1763::MESHTOVOLUMESETTINGS::UNSIGNED_DISTANCE_FIELD)};
	static const maxon::EnumInfo MESHTOVOLUMESETTINGS_info{"MESHTOVOLUMESETTINGS", SIZEOF(MESHTOVOLUMESETTINGS), false, "NONE\0GRIDSIZE\0BANDWIDTH_INTERIOR\0BANDWIDTH_EXTERIOR\0USE_POINTS\0RADIUS\0UNSIGNED_DISTANCE_FIELD\0", MESHTOVOLUMESETTINGS_values, std::extent<decltype(MESHTOVOLUMESETTINGS_values)>::value};
}
const maxon::EnumInfo& PrivateGetEnumInfo_MESHTOVOLUMESETTINGS1763(){ return enum1763::MESHTOVOLUMESETTINGS_info; }
namespace enum1778
{
	enum class PARTICLESTOVOLUMESETTINGS
	{
		NONE = 0,
		GRIDSIZE = 1,				///< ::Float Grid voxel cube size.
		BANDWIDTH = 2,			///< ::Int32 Voxel Bandwidth amount around a particle.
		RADIUS = 3,					///< ::Float Radius of the SDF around a particle.
		VELOCITY_SCALE = 4,	///< ::Float Velocity expansion scale.
		USE_PARTICLE_SIZE = 5 	///< ::Bool If true it overrides the radius with the particle size.
	} ;
	static const maxon::UInt64 PARTICLESTOVOLUMESETTINGS_values[] = {maxon::UInt64(enum1778::PARTICLESTOVOLUMESETTINGS::NONE), maxon::UInt64(enum1778::PARTICLESTOVOLUMESETTINGS::GRIDSIZE), maxon::UInt64(enum1778::PARTICLESTOVOLUMESETTINGS::BANDWIDTH), maxon::UInt64(enum1778::PARTICLESTOVOLUMESETTINGS::RADIUS), maxon::UInt64(enum1778::PARTICLESTOVOLUMESETTINGS::VELOCITY_SCALE), maxon::UInt64(enum1778::PARTICLESTOVOLUMESETTINGS::USE_PARTICLE_SIZE)};
	static const maxon::EnumInfo PARTICLESTOVOLUMESETTINGS_info{"PARTICLESTOVOLUMESETTINGS", SIZEOF(PARTICLESTOVOLUMESETTINGS), false, "NONE\0GRIDSIZE\0BANDWIDTH\0RADIUS\0VELOCITY_SCALE\0USE_PARTICLE_SIZE\0", PARTICLESTOVOLUMESETTINGS_values, std::extent<decltype(PARTICLESTOVOLUMESETTINGS_values)>::value};
}
const maxon::EnumInfo& PrivateGetEnumInfo_PARTICLESTOVOLUMESETTINGS1778(){ return enum1778::PARTICLESTOVOLUMESETTINGS_info; }
namespace enum1793
{
	enum class SPLINETOVOLUMESETTINGS
	{
		NONE = 0,
		GRIDSIZE = 1,				///< ::Float Grid voxel cube size.
		BANDWIDTH = 2,			///< ::Int32 Voxel Bandwidth amount around a Spline.
		RADIUS = 3,					///< ::Float Radius of the SDF around a Spline.
		DENSITY = 4,				///< ::Float Sampling density on the Spline.
		SCALESEGMENT = 5		///< ::Bool If true each spline segment will be scaled individually by the scalespline.
	} ;
	static const maxon::UInt64 SPLINETOVOLUMESETTINGS_values[] = {maxon::UInt64(enum1793::SPLINETOVOLUMESETTINGS::NONE), maxon::UInt64(enum1793::SPLINETOVOLUMESETTINGS::GRIDSIZE), maxon::UInt64(enum1793::SPLINETOVOLUMESETTINGS::BANDWIDTH), maxon::UInt64(enum1793::SPLINETOVOLUMESETTINGS::RADIUS), maxon::UInt64(enum1793::SPLINETOVOLUMESETTINGS::DENSITY), maxon::UInt64(enum1793::SPLINETOVOLUMESETTINGS::SCALESEGMENT)};
	static const maxon::EnumInfo SPLINETOVOLUMESETTINGS_info{"SPLINETOVOLUMESETTINGS", SIZEOF(SPLINETOVOLUMESETTINGS), false, "NONE\0GRIDSIZE\0BANDWIDTH\0RADIUS\0DENSITY\0SCALESEGMENT\0", SPLINETOVOLUMESETTINGS_values, std::extent<decltype(SPLINETOVOLUMESETTINGS_values)>::value};
}
const maxon::EnumInfo& PrivateGetEnumInfo_SPLINETOVOLUMESETTINGS1793(){ return enum1793::SPLINETOVOLUMESETTINGS_info; }
namespace enum1815
{
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
	} ;
	static const maxon::UInt64 FILTERSETTINGS_values[] = {maxon::UInt64(enum1815::FILTERSETTINGS::NONE), maxon::UInt64(enum1815::FILTERSETTINGS::FILTERTYPE), maxon::UInt64(enum1815::FILTERSETTINGS::ITERATIONS), maxon::UInt64(enum1815::FILTERSETTINGS::RADIUS), maxon::UInt64(enum1815::FILTERSETTINGS::OFFSET), maxon::UInt64(enum1815::FILTERSETTINGS::FALLOFF), maxon::UInt64(enum1815::FILTERSETTINGS::REMAP_OLD_MIN), maxon::UInt64(enum1815::FILTERSETTINGS::REMAP_OLD_MAX), maxon::UInt64(enum1815::FILTERSETTINGS::REMAP_NEW_MIN), maxon::UInt64(enum1815::FILTERSETTINGS::REMAP_NEW_MAX), maxon::UInt64(enum1815::FILTERSETTINGS::STRENGTH), maxon::UInt64(enum1815::FILTERSETTINGS::SPLINE), maxon::UInt64(enum1815::FILTERSETTINGS::INVERTPOINT)};
	static const maxon::EnumInfo FILTERSETTINGS_info{"FILTERSETTINGS", SIZEOF(FILTERSETTINGS), false, "NONE\0FILTERTYPE\0ITERATIONS\0RADIUS\0OFFSET\0FALLOFF\0REMAP_OLD_MIN\0REMAP_OLD_MAX\0REMAP_NEW_MIN\0REMAP_NEW_MAX\0STRENGTH\0SPLINE\0INVERTPOINT\0", FILTERSETTINGS_values, std::extent<decltype(FILTERSETTINGS_values)>::value};
}
const maxon::EnumInfo& PrivateGetEnumInfo_FILTERSETTINGS1815(){ return enum1815::FILTERSETTINGS_info; }
namespace enum1833
{
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
	} ;
	static const maxon::UInt64 SDFFILTERSETTINGS_values[] = {maxon::UInt64(enum1833::SDFFILTERSETTINGS::NONE), maxon::UInt64(enum1833::SDFFILTERSETTINGS::FILTERTYPE), maxon::UInt64(enum1833::SDFFILTERSETTINGS::ITERATIONS), maxon::UInt64(enum1833::SDFFILTERSETTINGS::STENCILWIDTH), maxon::UInt64(enum1833::SDFFILTERSETTINGS::FILTERACCURACY), maxon::UInt64(enum1833::SDFFILTERSETTINGS::OFFSET), maxon::UInt64(enum1833::SDFFILTERSETTINGS::HALFWIDTH), maxon::UInt64(enum1833::SDFFILTERSETTINGS::FALLOFF), maxon::UInt64(enum1833::SDFFILTERSETTINGS::STRENGTH)};
	static const maxon::EnumInfo SDFFILTERSETTINGS_info{"SDFFILTERSETTINGS", SIZEOF(SDFFILTERSETTINGS), false, "NONE\0FILTERTYPE\0ITERATIONS\0STENCILWIDTH\0FILTERACCURACY\0OFFSET\0HALFWIDTH\0FALLOFF\0STRENGTH\0", SDFFILTERSETTINGS_values, std::extent<decltype(SDFFILTERSETTINGS_values)>::value};
}
const maxon::EnumInfo& PrivateGetEnumInfo_SDFFILTERSETTINGS1833(){ return enum1833::SDFFILTERSETTINGS_info; }
namespace enum1844
{
	enum class BOOLESETTINGS
	{
		NONE = 0,
		BOOLETYPE = 1				///< ::Int32 The Boole type (union, difference, intersection).
	} ;
	static const maxon::UInt64 BOOLESETTINGS_values[] = {maxon::UInt64(enum1844::BOOLESETTINGS::NONE), maxon::UInt64(enum1844::BOOLESETTINGS::BOOLETYPE)};
	static const maxon::EnumInfo BOOLESETTINGS_info{"BOOLESETTINGS", SIZEOF(BOOLESETTINGS), false, "NONE\0BOOLETYPE\0", BOOLESETTINGS_values, std::extent<decltype(BOOLESETTINGS_values)>::value};
}
const maxon::EnumInfo& PrivateGetEnumInfo_BOOLESETTINGS1844(){ return enum1844::BOOLESETTINGS_info; }
namespace enum1857
{
	enum class BOOLTYPE
	{
		NONE = 0,
		UNION = 1,
		DIFF = 2,
		INTERSECT = 3,
	} ;
	static const maxon::UInt64 BOOLTYPE_values[] = {maxon::UInt64(enum1857::BOOLTYPE::NONE), maxon::UInt64(enum1857::BOOLTYPE::UNION), maxon::UInt64(enum1857::BOOLTYPE::DIFF), maxon::UInt64(enum1857::BOOLTYPE::INTERSECT)};
	static const maxon::EnumInfo BOOLTYPE_info{"BOOLTYPE", SIZEOF(BOOLTYPE), false, "NONE\0UNION\0DIFF\0INTERSECT\0", BOOLTYPE_values, std::extent<decltype(BOOLTYPE_values)>::value};
}
const maxon::EnumInfo& PrivateGetEnumInfo_BOOLTYPE1857(){ return enum1857::BOOLTYPE_info; }
namespace enum1868
{
	enum class MIXSETTINGS
	{
		NONE = 0,
		MIXTYPE = 1				///< ::Int32 The Mix type (Normal, Max, Mix, Add, Subtract, Multiply, Divide).
	} ;
	static const maxon::UInt64 MIXSETTINGS_values[] = {maxon::UInt64(enum1868::MIXSETTINGS::NONE), maxon::UInt64(enum1868::MIXSETTINGS::MIXTYPE)};
	static const maxon::EnumInfo MIXSETTINGS_info{"MIXSETTINGS", SIZEOF(MIXSETTINGS), false, "NONE\0MIXTYPE\0", MIXSETTINGS_values, std::extent<decltype(MIXSETTINGS_values)>::value};
}
const maxon::EnumInfo& PrivateGetEnumInfo_MIXSETTINGS1868(){ return enum1868::MIXSETTINGS_info; }
namespace enum1885
{
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
	} ;
	static const maxon::UInt64 MIXTYPE_values[] = {maxon::UInt64(enum1885::MIXTYPE::NONE), maxon::UInt64(enum1885::MIXTYPE::NORMAL), maxon::UInt64(enum1885::MIXTYPE::MAX), maxon::UInt64(enum1885::MIXTYPE::MIN), maxon::UInt64(enum1885::MIXTYPE::ADD), maxon::UInt64(enum1885::MIXTYPE::SUBTRACT), maxon::UInt64(enum1885::MIXTYPE::MULTIPLY), maxon::UInt64(enum1885::MIXTYPE::DIVIDE)};
	static const maxon::EnumInfo MIXTYPE_info{"MIXTYPE", SIZEOF(MIXTYPE), false, "NONE\0NORMAL\0MAX\0MIN\0ADD\0SUBTRACT\0MULTIPLY\0DIVIDE\0", MIXTYPE_values, std::extent<decltype(MIXTYPE_values)>::value};
}
const maxon::EnumInfo& PrivateGetEnumInfo_MIXTYPE1885(){ return enum1885::MIXTYPE_info; }
namespace enum1896
{
	enum class SDFTOFOGSETTINGS
	{
		NONE = 0,
		FALLOFFCUTOFF = 1				///< ::Float Distance for the falloff from the surface.
	} ;
	static const maxon::UInt64 SDFTOFOGSETTINGS_values[] = {maxon::UInt64(enum1896::SDFTOFOGSETTINGS::NONE), maxon::UInt64(enum1896::SDFTOFOGSETTINGS::FALLOFFCUTOFF)};
	static const maxon::EnumInfo SDFTOFOGSETTINGS_info{"SDFTOFOGSETTINGS", SIZEOF(SDFTOFOGSETTINGS), false, "NONE\0FALLOFFCUTOFF\0", SDFTOFOGSETTINGS_values, std::extent<decltype(SDFTOFOGSETTINGS_values)>::value};
}
const maxon::EnumInfo& PrivateGetEnumInfo_SDFTOFOGSETTINGS1896(){ return enum1896::SDFTOFOGSETTINGS_info; }
namespace enum1907
{
	enum class FOGTOSDFSETTINGS
	{
		NONE = 0,
		ISO = 1				///< ::Float Iso value to extract the SDF at.
	} ;
	static const maxon::UInt64 FOGTOSDFSETTINGS_values[] = {maxon::UInt64(enum1907::FOGTOSDFSETTINGS::NONE), maxon::UInt64(enum1907::FOGTOSDFSETTINGS::ISO)};
	static const maxon::EnumInfo FOGTOSDFSETTINGS_info{"FOGTOSDFSETTINGS", SIZEOF(FOGTOSDFSETTINGS), false, "NONE\0ISO\0", FOGTOSDFSETTINGS_values, std::extent<decltype(FOGTOSDFSETTINGS_values)>::value};
}
const maxon::EnumInfo& PrivateGetEnumInfo_FOGTOSDFSETTINGS1907(){ return enum1907::FOGTOSDFSETTINGS_info; }
namespace enum1919
{
	enum class RESAMPLESETTINGS
	{
		NONE = 0,
		GRIDSIZE = 1,						///< ::Float New grid voxel cube size.
		INTERPOLATIONTYPE = 2		///< ::Int32 The Interpolation type (nearest, linear, quadratic).
	} ;
	static const maxon::UInt64 RESAMPLESETTINGS_values[] = {maxon::UInt64(enum1919::RESAMPLESETTINGS::NONE), maxon::UInt64(enum1919::RESAMPLESETTINGS::GRIDSIZE), maxon::UInt64(enum1919::RESAMPLESETTINGS::INTERPOLATIONTYPE)};
	static const maxon::EnumInfo RESAMPLESETTINGS_info{"RESAMPLESETTINGS", SIZEOF(RESAMPLESETTINGS), false, "NONE\0GRIDSIZE\0INTERPOLATIONTYPE\0", RESAMPLESETTINGS_values, std::extent<decltype(RESAMPLESETTINGS_values)>::value};
}
const maxon::EnumInfo& PrivateGetEnumInfo_RESAMPLESETTINGS1919(){ return enum1919::RESAMPLESETTINGS_info; }
namespace enum1932
{
	enum class RESAMPLEINTERPOLATIONTYPE
	{
		NONE = 0,
		NEAREST = 1,
		LINEAR = 2,
		QUADRATIC = 3
	} ;
	static const maxon::UInt64 RESAMPLEINTERPOLATIONTYPE_values[] = {maxon::UInt64(enum1932::RESAMPLEINTERPOLATIONTYPE::NONE), maxon::UInt64(enum1932::RESAMPLEINTERPOLATIONTYPE::NEAREST), maxon::UInt64(enum1932::RESAMPLEINTERPOLATIONTYPE::LINEAR), maxon::UInt64(enum1932::RESAMPLEINTERPOLATIONTYPE::QUADRATIC)};
	static const maxon::EnumInfo RESAMPLEINTERPOLATIONTYPE_info{"RESAMPLEINTERPOLATIONTYPE", SIZEOF(RESAMPLEINTERPOLATIONTYPE), false, "NONE\0NEAREST\0LINEAR\0QUADRATIC\0", RESAMPLEINTERPOLATIONTYPE_values, std::extent<decltype(RESAMPLEINTERPOLATIONTYPE_values)>::value};
}
const maxon::EnumInfo& PrivateGetEnumInfo_RESAMPLEINTERPOLATIONTYPE1932(){ return enum1932::RESAMPLEINTERPOLATIONTYPE_info; }
namespace enum1945
{
	enum class FIELDTOVOLUMESETTINGS
	{
		NONE = 0,
		BOUNDINGBOXMIN = 1,	///< ::Vector The lower left point of the boundingbox.
		BOUNDINGBOXMAX = 2,	///< ::Vector The upper right point of the boundingbox.
		GRIDSIZE = 3,				///< ::Float Grid voxel cube size.
	} ;
	static const maxon::UInt64 FIELDTOVOLUMESETTINGS_values[] = {maxon::UInt64(enum1945::FIELDTOVOLUMESETTINGS::NONE), maxon::UInt64(enum1945::FIELDTOVOLUMESETTINGS::BOUNDINGBOXMIN), maxon::UInt64(enum1945::FIELDTOVOLUMESETTINGS::BOUNDINGBOXMAX), maxon::UInt64(enum1945::FIELDTOVOLUMESETTINGS::GRIDSIZE)};
	static const maxon::EnumInfo FIELDTOVOLUMESETTINGS_info{"FIELDTOVOLUMESETTINGS", SIZEOF(FIELDTOVOLUMESETTINGS), false, "NONE\0BOUNDINGBOXMIN\0BOUNDINGBOXMAX\0GRIDSIZE\0", FIELDTOVOLUMESETTINGS_values, std::extent<decltype(FIELDTOVOLUMESETTINGS_values)>::value};
}
const maxon::EnumInfo& PrivateGetEnumInfo_FIELDTOVOLUMESETTINGS1945(){ return enum1945::FIELDTOVOLUMESETTINGS_info; }
namespace enum1959
{
	enum class CREATESPHEREVOLUMESETTINGS
	{
		NONE = 0,
		RADIUS = 1,					///< ::Float The radius of the sphere.
		POSITION = 2,				///< ::Vector The world position of the sphere.
		BANDWIDTH = 3,			///< ::Int32 Voxel Bandwidth amount around a sphere.
		GRIDSIZE = 4,				///< ::Float Grid voxel cube size.
	} ;
	static const maxon::UInt64 CREATESPHEREVOLUMESETTINGS_values[] = {maxon::UInt64(enum1959::CREATESPHEREVOLUMESETTINGS::NONE), maxon::UInt64(enum1959::CREATESPHEREVOLUMESETTINGS::RADIUS), maxon::UInt64(enum1959::CREATESPHEREVOLUMESETTINGS::POSITION), maxon::UInt64(enum1959::CREATESPHEREVOLUMESETTINGS::BANDWIDTH), maxon::UInt64(enum1959::CREATESPHEREVOLUMESETTINGS::GRIDSIZE)};
	static const maxon::EnumInfo CREATESPHEREVOLUMESETTINGS_info{"CREATESPHEREVOLUMESETTINGS", SIZEOF(CREATESPHEREVOLUMESETTINGS), false, "NONE\0RADIUS\0POSITION\0BANDWIDTH\0GRIDSIZE\0", CREATESPHEREVOLUMESETTINGS_values, std::extent<decltype(CREATESPHEREVOLUMESETTINGS_values)>::value};
}
const maxon::EnumInfo& PrivateGetEnumInfo_CREATESPHEREVOLUMESETTINGS1959(){ return enum1959::CREATESPHEREVOLUMESETTINGS_info; }
namespace enum1974
{
	enum class CREATEPLATONICVOLUMESETTINGS
	{
		NONE = 0,
		FACES = 1,					///< ::Int32 The amount of faces of the platonic i.e. Tetrahedron = 4, Cube = 6, Octahedron = 8.
		SIZE = 2,						///< ::Float The size of the platonic.
		POSITION = 3,				///< ::Vector The world position of the platonic.
		BANDWIDTH = 4,			///< ::Int32 Voxel Bandwidth amount around the platonic.
		GRIDSIZE = 5,				///< ::Float Grid voxel cube size.
	} ;
	static const maxon::UInt64 CREATEPLATONICVOLUMESETTINGS_values[] = {maxon::UInt64(enum1974::CREATEPLATONICVOLUMESETTINGS::NONE), maxon::UInt64(enum1974::CREATEPLATONICVOLUMESETTINGS::FACES), maxon::UInt64(enum1974::CREATEPLATONICVOLUMESETTINGS::SIZE), maxon::UInt64(enum1974::CREATEPLATONICVOLUMESETTINGS::POSITION), maxon::UInt64(enum1974::CREATEPLATONICVOLUMESETTINGS::BANDWIDTH), maxon::UInt64(enum1974::CREATEPLATONICVOLUMESETTINGS::GRIDSIZE)};
	static const maxon::EnumInfo CREATEPLATONICVOLUMESETTINGS_info{"CREATEPLATONICVOLUMESETTINGS", SIZEOF(CREATEPLATONICVOLUMESETTINGS), false, "NONE\0FACES\0SIZE\0POSITION\0BANDWIDTH\0GRIDSIZE\0", CREATEPLATONICVOLUMESETTINGS_values, std::extent<decltype(CREATEPLATONICVOLUMESETTINGS_values)>::value};
}
const maxon::EnumInfo& PrivateGetEnumInfo_CREATEPLATONICVOLUMESETTINGS1974(){ return enum1974::CREATEPLATONICVOLUMESETTINGS_info; }
namespace enum2638
{
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
	} ;
	static const maxon::UInt64 EVENT_values[] = {maxon::UInt64(enum2638::EVENT::NONE), maxon::UInt64(enum2638::EVENT::FORCEREDRAW), maxon::UInt64(enum2638::EVENT::ANIMATE), maxon::UInt64(enum2638::EVENT::NOEXPRESSION), maxon::UInt64(enum2638::EVENT::GLHACK), maxon::UInt64(enum2638::EVENT::CAMERAEXPRESSION), maxon::UInt64(enum2638::EVENT::ENQUEUE_REDRAW), maxon::UInt64(enum2638::EVENT::DONT_OVERWRITE_RENDERING)};
	static const maxon::EnumInfo EVENT_info{"EVENT", SIZEOF(EVENT), true, "NONE\0FORCEREDRAW\0ANIMATE\0NOEXPRESSION\0GLHACK\0CAMERAEXPRESSION\0ENQUEUE_REDRAW\0DONT_OVERWRITE_RENDERING\0", EVENT_values, std::extent<decltype(EVENT_values)>::value};
}
const maxon::EnumInfo& PrivateGetEnumInfo_EVENT2638(){ return enum2638::EVENT_info; }
namespace enum2668
{
	enum class DRAWFLAGS
	{
		NONE												= 0,							///< None.
		NO_THREAD										= (1 << 1),				///< Synchronous call.
		NO_ANIMATION								= (1 << 8),				///< Ignore all animation.
		ONLY_ACTIVE_VIEW						= (1 << 10),			///< Only redraw the active view.
		NO_EXPRESSIONS							= (1 << 12),			///< Ignore expressions.
		INDRAG											= (1 << 13),			///< In drag.
		NO_HIGHLIGHT_PLANE					= (1 << 14),			///< The entire view is drawn, not just the highlight plane.
		FORCEFULLREDRAW							= (1 << 15),			///< Force full redraw.
		ONLY_CAMERAEXPRESSION				= (1 << 16),			///< Camera expression.
		INMOVE											= (1 << 17),			///< In move.
		ONLY_BASEDRAW								= (1 << 22),			///< Draw specific base draw only.
		ONLY_HIGHLIGHT							= (1 << 18),			///< Only highlights.
		STATICBREAK									= (1 << 19),			///< If the display is done in the main thread (@C4D only does this during animation playback) this allows that a special thread is used to poll the escape key.
		NO_PRESENT									= (1 << 23),			///< Prevents the drawport from swapping buffers.
																									///< @note Use only in combination with @ref DRAWFLAGS::NO_THREAD.
		PRIVATE_NO_WAIT_GL_FINISHED	= (1 << 3),				///< @markPrivate
		PRIVATE_ONLYBACKGROUND			= (1 << 4),				///< @markPrivate
		PRIVATE_NOBLIT							= (1 << 9),				///< @markPrivate
		PRIVATE_OPENGLHACK					= (1 << 11),			///< @markPrivate
		PRIVATE_ONLY_PREPARE				= (1 << 21),			///< @markPrivate
		PRIVATE_NO_3DCLIPPING				= (1 << 24),			///< @markPrivate
		DONT_OVERWRITE_RENDERING		= (1 << 25)				///< @markPrivate
	} ;
	static const maxon::UInt64 DRAWFLAGS_values[] = {maxon::UInt64(enum2668::DRAWFLAGS::NONE), maxon::UInt64(enum2668::DRAWFLAGS::NO_THREAD), maxon::UInt64(enum2668::DRAWFLAGS::NO_ANIMATION), maxon::UInt64(enum2668::DRAWFLAGS::ONLY_ACTIVE_VIEW), maxon::UInt64(enum2668::DRAWFLAGS::NO_EXPRESSIONS), maxon::UInt64(enum2668::DRAWFLAGS::INDRAG), maxon::UInt64(enum2668::DRAWFLAGS::NO_HIGHLIGHT_PLANE), maxon::UInt64(enum2668::DRAWFLAGS::FORCEFULLREDRAW), maxon::UInt64(enum2668::DRAWFLAGS::ONLY_CAMERAEXPRESSION), maxon::UInt64(enum2668::DRAWFLAGS::INMOVE), maxon::UInt64(enum2668::DRAWFLAGS::ONLY_BASEDRAW), maxon::UInt64(enum2668::DRAWFLAGS::ONLY_HIGHLIGHT), maxon::UInt64(enum2668::DRAWFLAGS::STATICBREAK), maxon::UInt64(enum2668::DRAWFLAGS::NO_PRESENT), maxon::UInt64(enum2668::DRAWFLAGS::PRIVATE_NO_WAIT_GL_FINISHED), maxon::UInt64(enum2668::DRAWFLAGS::PRIVATE_ONLYBACKGROUND), maxon::UInt64(enum2668::DRAWFLAGS::PRIVATE_NOBLIT), maxon::UInt64(enum2668::DRAWFLAGS::PRIVATE_OPENGLHACK), maxon::UInt64(enum2668::DRAWFLAGS::PRIVATE_ONLY_PREPARE), maxon::UInt64(enum2668::DRAWFLAGS::PRIVATE_NO_3DCLIPPING), maxon::UInt64(enum2668::DRAWFLAGS::DONT_OVERWRITE_RENDERING)};
	static const maxon::EnumInfo DRAWFLAGS_info{"DRAWFLAGS", SIZEOF(DRAWFLAGS), true, "NONE\0NO_THREAD\0NO_ANIMATION\0ONLY_ACTIVE_VIEW\0NO_EXPRESSIONS\0INDRAG\0NO_HIGHLIGHT_PLANE\0FORCEFULLREDRAW\0ONLY_CAMERAEXPRESSION\0INMOVE\0ONLY_BASEDRAW\0ONLY_HIGHLIGHT\0STATICBREAK\0NO_PRESENT\0PRIVATE_NO_WAIT_GL_FINISHED\0PRIVATE_ONLYBACKGROUND\0PRIVATE_NOBLIT\0PRIVATE_OPENGLHACK\0PRIVATE_ONLY_PREPARE\0PRIVATE_NO_3DCLIPPING\0DONT_OVERWRITE_RENDERING\0", DRAWFLAGS_values, std::extent<decltype(DRAWFLAGS_values)>::value};
}
const maxon::EnumInfo& PrivateGetEnumInfo_DRAWFLAGS2668(){ return enum2668::DRAWFLAGS_info; }
namespace enum2683
{
	enum class ANIMATEFLAGS
	{
		NONE					= 0,						///< None.
		NO_PARTICLES	= (1 << 2),			///< Ignore particles.
		NO_CHILDREN		= (1 << 6),			///< Do not animate children.
		INRENDER			= (1 << 7),			///< Prepare to render scene.
		NO_MINMAX			= (1 << 8),			///< @markPrivate
		NO_NLA				= (1 << 9),			///< @markPrivate
		NLA_SUM				= (1 << 10)			///< @markPrivate
	} ;
	static const maxon::UInt64 ANIMATEFLAGS_values[] = {maxon::UInt64(enum2683::ANIMATEFLAGS::NONE), maxon::UInt64(enum2683::ANIMATEFLAGS::NO_PARTICLES), maxon::UInt64(enum2683::ANIMATEFLAGS::NO_CHILDREN), maxon::UInt64(enum2683::ANIMATEFLAGS::INRENDER), maxon::UInt64(enum2683::ANIMATEFLAGS::NO_MINMAX), maxon::UInt64(enum2683::ANIMATEFLAGS::NO_NLA), maxon::UInt64(enum2683::ANIMATEFLAGS::NLA_SUM)};
	static const maxon::EnumInfo ANIMATEFLAGS_info{"ANIMATEFLAGS", SIZEOF(ANIMATEFLAGS), true, "NONE\0NO_PARTICLES\0NO_CHILDREN\0INRENDER\0NO_MINMAX\0NO_NLA\0NLA_SUM\0", ANIMATEFLAGS_values, std::extent<decltype(ANIMATEFLAGS_values)>::value};
}
const maxon::EnumInfo& PrivateGetEnumInfo_ANIMATEFLAGS2683(){ return enum2683::ANIMATEFLAGS_info; }
namespace enum2702
{
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
	} ;
	static const maxon::UInt64 SAVEDOCUMENTFLAGS_values[] = {maxon::UInt64(enum2702::SAVEDOCUMENTFLAGS::NONE), maxon::UInt64(enum2702::SAVEDOCUMENTFLAGS::DIALOGSALLOWED), maxon::UInt64(enum2702::SAVEDOCUMENTFLAGS::SAVEAS), maxon::UInt64(enum2702::SAVEDOCUMENTFLAGS::DONTADDTORECENTLIST), maxon::UInt64(enum2702::SAVEDOCUMENTFLAGS::AUTOSAVE), maxon::UInt64(enum2702::SAVEDOCUMENTFLAGS::SAVECACHES), maxon::UInt64(enum2702::SAVEDOCUMENTFLAGS::EXPORTDIALOG), maxon::UInt64(enum2702::SAVEDOCUMENTFLAGS::CRASHSITUATION), maxon::UInt64(enum2702::SAVEDOCUMENTFLAGS::NO_SHADERCACHE)};
	static const maxon::EnumInfo SAVEDOCUMENTFLAGS_info{"SAVEDOCUMENTFLAGS", SIZEOF(SAVEDOCUMENTFLAGS), true, "NONE\0DIALOGSALLOWED\0SAVEAS\0DONTADDTORECENTLIST\0AUTOSAVE\0SAVECACHES\0EXPORTDIALOG\0CRASHSITUATION\0NO_SHADERCACHE\0", SAVEDOCUMENTFLAGS_values, std::extent<decltype(SAVEDOCUMENTFLAGS_values)>::value};
}
const maxon::EnumInfo& PrivateGetEnumInfo_SAVEDOCUMENTFLAGS2702(){ return enum2702::SAVEDOCUMENTFLAGS_info; }
namespace enum2740
{
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
		PRIVATE_BODYPAINT_NODATA					= (1 << 29),			///< @markPrivate
		PRIVATE_BODYPAINT_CONVERTLAYER		= (1 << 30)				///< @markPrivate
	
	} ;
	static const maxon::UInt64 COPYFLAGS_values[] = {maxon::UInt64(enum2740::COPYFLAGS::NONE), maxon::UInt64(enum2740::COPYFLAGS::NO_HIERARCHY), maxon::UInt64(enum2740::COPYFLAGS::NO_ANIMATION), maxon::UInt64(enum2740::COPYFLAGS::NO_BITS), maxon::UInt64(enum2740::COPYFLAGS::NO_MATERIALPREVIEW), maxon::UInt64(enum2740::COPYFLAGS::NO_BRANCHES), maxon::UInt64(enum2740::COPYFLAGS::DOCUMENT), maxon::UInt64(enum2740::COPYFLAGS::NO_NGONS), maxon::UInt64(enum2740::COPYFLAGS::CACHE_BUILD), maxon::UInt64(enum2740::COPYFLAGS::RECURSIONCHECK), maxon::UInt64(enum2740::COPYFLAGS::PRIVATE_IDENTMARKER), maxon::UInt64(enum2740::COPYFLAGS::PRIVATE_NO_INTERNALS), maxon::UInt64(enum2740::COPYFLAGS::PRIVATE_NO_PLUGINLAYER), maxon::UInt64(enum2740::COPYFLAGS::PRIVATE_UNDO), maxon::UInt64(enum2740::COPYFLAGS::PRIVATE_CONTAINER_COPY_DIRTY), maxon::UInt64(enum2740::COPYFLAGS::PRIVATE_CONTAINER_COPY_IDENTICAL), maxon::UInt64(enum2740::COPYFLAGS::PRIVATE_NO_TAGS), maxon::UInt64(enum2740::COPYFLAGS::PRIVATE_DELETE), maxon::UInt64(enum2740::COPYFLAGS::PRIVATE_CLIPBOARD_COPY), maxon::UInt64(enum2740::COPYFLAGS::PRIVATE_NO_ASSETS), maxon::UInt64(enum2740::COPYFLAGS::PRIVATE_NO_RESULTASSETS), maxon::UInt64(enum2740::COPYFLAGS::PRIVATE_NO_LOGS), maxon::UInt64(enum2740::COPYFLAGS::PRIVATE_RENDER), maxon::UInt64(enum2740::COPYFLAGS::PRIVATE_MOGRAPH_CLONE), maxon::UInt64(enum2740::COPYFLAGS::PRIVATE_BODYPAINT_NODATA), maxon::UInt64(enum2740::COPYFLAGS::PRIVATE_BODYPAINT_CONVERTLAYER)};
	static const maxon::EnumInfo COPYFLAGS_info{"COPYFLAGS", SIZEOF(COPYFLAGS), true, "NONE\0NO_HIERARCHY\0NO_ANIMATION\0NO_BITS\0NO_MATERIALPREVIEW\0NO_BRANCHES\0DOCUMENT\0NO_NGONS\0CACHE_BUILD\0RECURSIONCHECK\0PRIVATE_IDENTMARKER\0PRIVATE_NO_INTERNALS\0PRIVATE_NO_PLUGINLAYER\0PRIVATE_UNDO\0PRIVATE_CONTAINER_COPY_DIRTY\0PRIVATE_CONTAINER_COPY_IDENTICAL\0PRIVATE_NO_TAGS\0PRIVATE_DELETE\0PRIVATE_CLIPBOARD_COPY\0PRIVATE_NO_ASSETS\0PRIVATE_NO_RESULTASSETS\0PRIVATE_NO_LOGS\0PRIVATE_RENDER\0PRIVATE_MOGRAPH_CLONE\0PRIVATE_BODYPAINT_NODATA\0PRIVATE_BODYPAINT_CONVERTLAYER\0", COPYFLAGS_values, std::extent<decltype(COPYFLAGS_values)>::value};
}
const maxon::EnumInfo& PrivateGetEnumInfo_COPYFLAGS2740(){ return enum2740::COPYFLAGS_info; }
namespace enum2770
{
	enum class UNDOTYPE
	{
		NONE												= 0,				///< None.
	
		CHANGE											= 40,				///< Any change to an object, including hierarchy modifications; modification in positioning (object has been moved from A to B), substructures etc. (Needs to be called @b before the change.)
		CHANGE_NOCHILDREN						= 41,				///< Same as @ref UNDOTYPE::CHANGE, but without child modifications. (Needs to be called @b before the change.)
		CHANGE_SMALL								= 42,				///< Change to local data only (e.g. data container). No substructures (e.g. no tags on an object) and no children. (Needs to be called @b before the change.)
		CHANGE_SELECTION						= 43,				///< Change to point/poly/edge selection only. (Needs to be called @b before the change.)
	
		NEWOBJ											= 44,				///< New object/material/tag etc. was created. (Needs to be called @b after action.)
		DELETEOBJ										= 45,				///< Object/node/tag etc. to be deleted. (Needs to be called @b before action.)
	
		ACTIVATE										= 46,				///< Automatically managed by BaseDocument::SetActiveObject(), BaseDocument::SetActiveTag(), BaseDocument::SetActiveMaterial() etc. No need to use manually.
		DEACTIVATE									= 47,				///< Automatically managed by BaseDocument::SetActiveObject(), BaseDocument::SetActiveTag(), BaseDocument::SetActiveMaterial() etc. No need to use manually.
	
		BITS												= 48,				///< Change to object bits, e.g. selection status. (Needs to be called @b before the change.)
		HIERARCHY_PSR								= 49,				///< Change in hierarchical placement and PSR values. (Needs to be called @b before the change.)
	
		PRIVATE_STRING							= 9996,			///< @markPrivate
		PRIVATE_MULTISELECTIONAXIS	= 9997,			///< @markPrivate
		START												= 9998,			///< @markPrivate
		END													= 9999			///< @markPrivate
	} ;
	static const maxon::UInt64 UNDOTYPE_values[] = {maxon::UInt64(enum2770::UNDOTYPE::NONE), maxon::UInt64(enum2770::UNDOTYPE::CHANGE), maxon::UInt64(enum2770::UNDOTYPE::CHANGE_NOCHILDREN), maxon::UInt64(enum2770::UNDOTYPE::CHANGE_SMALL), maxon::UInt64(enum2770::UNDOTYPE::CHANGE_SELECTION), maxon::UInt64(enum2770::UNDOTYPE::NEWOBJ), maxon::UInt64(enum2770::UNDOTYPE::DELETEOBJ), maxon::UInt64(enum2770::UNDOTYPE::ACTIVATE), maxon::UInt64(enum2770::UNDOTYPE::DEACTIVATE), maxon::UInt64(enum2770::UNDOTYPE::BITS), maxon::UInt64(enum2770::UNDOTYPE::HIERARCHY_PSR), maxon::UInt64(enum2770::UNDOTYPE::PRIVATE_STRING), maxon::UInt64(enum2770::UNDOTYPE::PRIVATE_MULTISELECTIONAXIS), maxon::UInt64(enum2770::UNDOTYPE::START), maxon::UInt64(enum2770::UNDOTYPE::END)};
	static const maxon::EnumInfo UNDOTYPE_info{"UNDOTYPE", SIZEOF(UNDOTYPE), false, "NONE\0CHANGE\0CHANGE_NOCHILDREN\0CHANGE_SMALL\0CHANGE_SELECTION\0NEWOBJ\0DELETEOBJ\0ACTIVATE\0DEACTIVATE\0BITS\0HIERARCHY_PSR\0PRIVATE_STRING\0PRIVATE_MULTISELECTIONAXIS\0START\0END\0", UNDOTYPE_values, std::extent<decltype(UNDOTYPE_values)>::value};
}
const maxon::EnumInfo& PrivateGetEnumInfo_UNDOTYPE2770(){ return enum2770::UNDOTYPE_info; }
namespace enum2787
{
	enum class DRAWHANDLE
	{
		MINI					= 0,			///< Tiny point.
		SMALL					= 1,			///< Small point.
		MIDDLE				= 2,			///< Medium point.
		BIG						= 3,			///< Handle used by object generators and deformers.
		CUSTOM				= 4,			///< Custom handle.
		POINTSIZE			= 5,			///< Use the point size to draw the handle.
		SELPOINTSIZE	= 6				///< Use the size of selected points to draw the handle.
	} ;
	static const maxon::UInt64 DRAWHANDLE_values[] = {maxon::UInt64(enum2787::DRAWHANDLE::MINI), maxon::UInt64(enum2787::DRAWHANDLE::SMALL), maxon::UInt64(enum2787::DRAWHANDLE::MIDDLE), maxon::UInt64(enum2787::DRAWHANDLE::BIG), maxon::UInt64(enum2787::DRAWHANDLE::CUSTOM), maxon::UInt64(enum2787::DRAWHANDLE::POINTSIZE), maxon::UInt64(enum2787::DRAWHANDLE::SELPOINTSIZE)};
	static const maxon::EnumInfo DRAWHANDLE_info{"DRAWHANDLE", SIZEOF(DRAWHANDLE), false, "MINI\0SMALL\0MIDDLE\0BIG\0CUSTOM\0POINTSIZE\0SELPOINTSIZE\0", DRAWHANDLE_values, std::extent<decltype(DRAWHANDLE_values)>::value};
}
const maxon::EnumInfo& PrivateGetEnumInfo_DRAWHANDLE2787(){ return enum2787::DRAWHANDLE_info; }
namespace enum2800
{
	enum class DRAW_ALPHA
	{
		NONE								= 10,			///< No alpha.
		INVERTED						= 11,			///< Generates inverted alpha.
		NORMAL							= 12,			///< Generates alpha channel from the image's alpha channel. If no alpha channel exists, the alpha value is set to @em 100%.
		FROM_IMAGE					= 13,			///< Generates the alpha channel from the RGB image information.
		NORMAL_FROM_IMAGE		= 14			///< Generates alpha channel from the image's alpha channel. If no alpha channel exists, the alpha value is generated from the RGB image.
	} ;
	static const maxon::UInt64 DRAW_ALPHA_values[] = {maxon::UInt64(enum2800::DRAW_ALPHA::NONE), maxon::UInt64(enum2800::DRAW_ALPHA::INVERTED), maxon::UInt64(enum2800::DRAW_ALPHA::NORMAL), maxon::UInt64(enum2800::DRAW_ALPHA::FROM_IMAGE), maxon::UInt64(enum2800::DRAW_ALPHA::NORMAL_FROM_IMAGE)};
	static const maxon::EnumInfo DRAW_ALPHA_info{"DRAW_ALPHA", SIZEOF(DRAW_ALPHA), false, "NONE\0INVERTED\0NORMAL\0FROM_IMAGE\0NORMAL_FROM_IMAGE\0", DRAW_ALPHA_values, std::extent<decltype(DRAW_ALPHA_values)>::value};
}
const maxon::EnumInfo& PrivateGetEnumInfo_DRAW_ALPHA2800(){ return enum2800::DRAW_ALPHA_info; }
namespace enum2827
{
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
	
	} ;
	static const maxon::UInt64 DRAW_TEXTUREFLAGS_values[] = {maxon::UInt64(enum2827::DRAW_TEXTUREFLAGS::NONE), maxon::UInt64(enum2827::DRAW_TEXTUREFLAGS::COLOR_IMAGE_TO_LINEAR), maxon::UInt64(enum2827::DRAW_TEXTUREFLAGS::COLOR_SRGB_TO_LINEAR), maxon::UInt64(enum2827::DRAW_TEXTUREFLAGS::COLOR_IMAGE_TO_SRGB), maxon::UInt64(enum2827::DRAW_TEXTUREFLAGS::COLOR_LINEAR_TO_SRGB), maxon::UInt64(enum2827::DRAW_TEXTUREFLAGS::COLOR_CORRECTION_MASK), maxon::UInt64(enum2827::DRAW_TEXTUREFLAGS::USE_PROFILE_COLOR), maxon::UInt64(enum2827::DRAW_TEXTUREFLAGS::ALLOW_FLOATINGPOINT), maxon::UInt64(enum2827::DRAW_TEXTUREFLAGS::TILE), maxon::UInt64(enum2827::DRAW_TEXTUREFLAGS::TEMPORARY), maxon::UInt64(enum2827::DRAW_TEXTUREFLAGS::INTERPOLATION_NEAREST), maxon::UInt64(enum2827::DRAW_TEXTUREFLAGS::INTERPOLATION_LINEAR), maxon::UInt64(enum2827::DRAW_TEXTUREFLAGS::INTERPOLATION_LINEAR_MIPMAP), maxon::UInt64(enum2827::DRAW_TEXTUREFLAGS::INTERPOLATION_MASK)};
	static const maxon::EnumInfo DRAW_TEXTUREFLAGS_info{"DRAW_TEXTUREFLAGS", SIZEOF(DRAW_TEXTUREFLAGS), true, "NONE\0COLOR_IMAGE_TO_LINEAR\0COLOR_SRGB_TO_LINEAR\0COLOR_IMAGE_TO_SRGB\0COLOR_LINEAR_TO_SRGB\0COLOR_CORRECTION_MASK\0USE_PROFILE_COLOR\0ALLOW_FLOATINGPOINT\0TILE\0TEMPORARY\0INTERPOLATION_NEAREST\0INTERPOLATION_LINEAR\0INTERPOLATION_LINEAR_MIPMAP\0INTERPOLATION_MASK\0", DRAW_TEXTUREFLAGS_values, std::extent<decltype(DRAW_TEXTUREFLAGS_values)>::value};
}
const maxon::EnumInfo& PrivateGetEnumInfo_DRAW_TEXTUREFLAGS2827(){ return enum2827::DRAW_TEXTUREFLAGS_info; }
namespace enum2839
{
	enum class TOOLDRAW
	{
		NONE				= 0,						///< None.
		HANDLES			= (1 << 0),			///< The active objects handles will be drawn.
		AXIS				= (1 << 1),			///< The active objects axes will be drawn.
		HIGHLIGHTS	= (1 << 2)			///< The highlights will be drawn.
	} ;
	static const maxon::UInt64 TOOLDRAW_values[] = {maxon::UInt64(enum2839::TOOLDRAW::NONE), maxon::UInt64(enum2839::TOOLDRAW::HANDLES), maxon::UInt64(enum2839::TOOLDRAW::AXIS), maxon::UInt64(enum2839::TOOLDRAW::HIGHLIGHTS)};
	static const maxon::EnumInfo TOOLDRAW_info{"TOOLDRAW", SIZEOF(TOOLDRAW), true, "NONE\0HANDLES\0AXIS\0HIGHLIGHTS\0", TOOLDRAW_values, std::extent<decltype(TOOLDRAW_values)>::value};
}
const maxon::EnumInfo& PrivateGetEnumInfo_TOOLDRAW2839(){ return enum2839::TOOLDRAW_info; }
namespace enum2852
{
	enum class TOOLDRAWFLAGS
	{
		NONE			= 0,						///< None.
		INVERSE_Z	= (1 << 0),			///< Inverse Z-buffer mode. If set, the drawing engine of @C4D will only draw elements if they are further away from the camera than other objects.\n
															///< This is mostly used for help lines (such as the semi-transparent axis inside of objects).
															/// @note This mode only works when all objects are drawn so it should be passed last.
		HIGHLIGHT	= (1 << 1)			///< Highlight mode.
	} ;
	static const maxon::UInt64 TOOLDRAWFLAGS_values[] = {maxon::UInt64(enum2852::TOOLDRAWFLAGS::NONE), maxon::UInt64(enum2852::TOOLDRAWFLAGS::INVERSE_Z), maxon::UInt64(enum2852::TOOLDRAWFLAGS::HIGHLIGHT)};
	static const maxon::EnumInfo TOOLDRAWFLAGS_info{"TOOLDRAWFLAGS", SIZEOF(TOOLDRAWFLAGS), true, "NONE\0INVERSE_Z\0HIGHLIGHT\0", TOOLDRAWFLAGS_values, std::extent<decltype(TOOLDRAWFLAGS_values)>::value};
}
const maxon::EnumInfo& PrivateGetEnumInfo_TOOLDRAWFLAGS2852(){ return enum2852::TOOLDRAWFLAGS_info; }
namespace enum2996
{
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
	} ;
	static const maxon::UInt64 DIRTYFLAGS_values[] = {maxon::UInt64(enum2996::DIRTYFLAGS::NONE), maxon::UInt64(enum2996::DIRTYFLAGS::MATRIX), maxon::UInt64(enum2996::DIRTYFLAGS::DATA), maxon::UInt64(enum2996::DIRTYFLAGS::SELECT), maxon::UInt64(enum2996::DIRTYFLAGS::CACHE), maxon::UInt64(enum2996::DIRTYFLAGS::CHILDREN), maxon::UInt64(enum2996::DIRTYFLAGS::DESCRIPTION), maxon::UInt64(enum2996::DIRTYFLAGS::SELECTION_OBJECTS), maxon::UInt64(enum2996::DIRTYFLAGS::SELECTION_TAGS), maxon::UInt64(enum2996::DIRTYFLAGS::SELECTION_MATERIALS), maxon::UInt64(enum2996::DIRTYFLAGS::ALL)};
	static const maxon::EnumInfo DIRTYFLAGS_info{"DIRTYFLAGS", SIZEOF(DIRTYFLAGS), true, "NONE\0MATRIX\0DATA\0SELECT\0CACHE\0CHILDREN\0DESCRIPTION\0SELECTION_OBJECTS\0SELECTION_TAGS\0SELECTION_MATERIALS\0ALL\0", DIRTYFLAGS_values, std::extent<decltype(DIRTYFLAGS_values)>::value};
}
const maxon::EnumInfo& PrivateGetEnumInfo_DIRTYFLAGS2996(){ return enum2996::DIRTYFLAGS_info; }
namespace enum3017
{
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
	} ;
	static const maxon::UInt64 HDIRTY_ID_values[] = {maxon::UInt64(enum3017::HDIRTY_ID::ANIMATION), maxon::UInt64(enum3017::HDIRTY_ID::OBJECT), maxon::UInt64(enum3017::HDIRTY_ID::OBJECT_MATRIX), maxon::UInt64(enum3017::HDIRTY_ID::OBJECT_HIERARCHY), maxon::UInt64(enum3017::HDIRTY_ID::TAG), maxon::UInt64(enum3017::HDIRTY_ID::MATERIAL), maxon::UInt64(enum3017::HDIRTY_ID::SHADER), maxon::UInt64(enum3017::HDIRTY_ID::RENDERSETTINGS), maxon::UInt64(enum3017::HDIRTY_ID::VP), maxon::UInt64(enum3017::HDIRTY_ID::FILTER), maxon::UInt64(enum3017::HDIRTY_ID::NBITS), maxon::UInt64(enum3017::HDIRTY_ID::MAX)};
	static const maxon::EnumInfo HDIRTY_ID_info{"HDIRTY_ID", SIZEOF(HDIRTY_ID), false, "ANIMATION\0OBJECT\0OBJECT_MATRIX\0OBJECT_HIERARCHY\0TAG\0MATERIAL\0SHADER\0RENDERSETTINGS\0VP\0FILTER\0NBITS\0MAX\0", HDIRTY_ID_values, std::extent<decltype(HDIRTY_ID_values)>::value};
}
const maxon::EnumInfo& PrivateGetEnumInfo_HDIRTY_ID3017(){ return enum3017::HDIRTY_ID_info; }
namespace enum3040
{
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
	} ;
	static const maxon::UInt64 HDIRTYFLAGS_values[] = {maxon::UInt64(enum3040::HDIRTYFLAGS::NONE), maxon::UInt64(enum3040::HDIRTYFLAGS::ANIMATION), maxon::UInt64(enum3040::HDIRTYFLAGS::OBJECT), maxon::UInt64(enum3040::HDIRTYFLAGS::OBJECT_MATRIX), maxon::UInt64(enum3040::HDIRTYFLAGS::OBJECT_HIERARCHY), maxon::UInt64(enum3040::HDIRTYFLAGS::TAG), maxon::UInt64(enum3040::HDIRTYFLAGS::MATERIAL), maxon::UInt64(enum3040::HDIRTYFLAGS::SHADER), maxon::UInt64(enum3040::HDIRTYFLAGS::RENDERSETTINGS), maxon::UInt64(enum3040::HDIRTYFLAGS::VP), maxon::UInt64(enum3040::HDIRTYFLAGS::FILTER), maxon::UInt64(enum3040::HDIRTYFLAGS::NBITS), maxon::UInt64(enum3040::HDIRTYFLAGS::ALL)};
	static const maxon::EnumInfo HDIRTYFLAGS_info{"HDIRTYFLAGS", SIZEOF(HDIRTYFLAGS), true, "NONE\0ANIMATION\0OBJECT\0OBJECT_MATRIX\0OBJECT_HIERARCHY\0TAG\0MATERIAL\0SHADER\0RENDERSETTINGS\0VP\0FILTER\0NBITS\0ALL\0", HDIRTYFLAGS_values, std::extent<decltype(HDIRTYFLAGS_values)>::value};
}
const maxon::EnumInfo& PrivateGetEnumInfo_HDIRTYFLAGS3040(){ return enum3040::HDIRTYFLAGS_info; }
namespace enum3064
{
	enum class ROTATIONORDER
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
	} ;
	static const maxon::UInt64 ROTATIONORDER_values[] = {maxon::UInt64(enum3064::ROTATIONORDER::YXZGLOBAL), maxon::UInt64(enum3064::ROTATIONORDER::YZXGLOBAL), maxon::UInt64(enum3064::ROTATIONORDER::ZYXGLOBAL), maxon::UInt64(enum3064::ROTATIONORDER::ZXYGLOBAL), maxon::UInt64(enum3064::ROTATIONORDER::XZYGLOBAL), maxon::UInt64(enum3064::ROTATIONORDER::XYZGLOBAL), maxon::UInt64(enum3064::ROTATIONORDER::YXZLOCAL), maxon::UInt64(enum3064::ROTATIONORDER::YZXLOCAL), maxon::UInt64(enum3064::ROTATIONORDER::ZYXLOCAL), maxon::UInt64(enum3064::ROTATIONORDER::ZXYLOCAL), maxon::UInt64(enum3064::ROTATIONORDER::XZYLOCAL), maxon::UInt64(enum3064::ROTATIONORDER::XYZLOCAL), maxon::UInt64(enum3064::ROTATIONORDER::HPB), maxon::UInt64(enum3064::ROTATIONORDER::DEFAULT)};
	static const maxon::EnumInfo ROTATIONORDER_info{"ROTATIONORDER", SIZEOF(ROTATIONORDER), false, "YXZGLOBAL\0YZXGLOBAL\0ZYXGLOBAL\0ZXYGLOBAL\0XZYGLOBAL\0XYZGLOBAL\0YXZLOCAL\0YZXLOCAL\0ZYXLOCAL\0ZXYLOCAL\0XZYLOCAL\0XYZLOCAL\0HPB\0DEFAULT\0", ROTATIONORDER_values, std::extent<decltype(ROTATIONORDER_values)>::value};
}
const maxon::EnumInfo& PrivateGetEnumInfo_ROTATIONORDER3064(){ return enum3064::ROTATIONORDER_info; }
namespace enum3075
{
	enum class ROTATIONINTERPOLATION_QUATERNION
	{
		SLERP = 2,	///< Spherical LERP Interpolation (linear).
		CUBIC = 3		///< Smooth Cubic Interpolation (formerly known as Losch).
	} ;
	static const maxon::UInt64 ROTATIONINTERPOLATION_QUATERNION_values[] = {maxon::UInt64(enum3075::ROTATIONINTERPOLATION_QUATERNION::SLERP), maxon::UInt64(enum3075::ROTATIONINTERPOLATION_QUATERNION::CUBIC)};
	static const maxon::EnumInfo ROTATIONINTERPOLATION_QUATERNION_info{"ROTATIONINTERPOLATION_QUATERNION", SIZEOF(ROTATIONINTERPOLATION_QUATERNION), false, "SLERP\0CUBIC\0", ROTATIONINTERPOLATION_QUATERNION_values, std::extent<decltype(ROTATIONINTERPOLATION_QUATERNION_values)>::value};
}
const maxon::EnumInfo& PrivateGetEnumInfo_ROTATIONINTERPOLATION_QUATERNION3075(){ return enum3075::ROTATIONINTERPOLATION_QUATERNION_info; }
namespace enum3087
{
	enum class CURVEINTERPOLATION_MODE
	{
		R23, ///< hermite evaluation with some tangent issues
	
		CURRENT ///< Spline evaluation
	} ;
	static const maxon::UInt64 CURVEINTERPOLATION_MODE_values[] = {maxon::UInt64(enum3087::CURVEINTERPOLATION_MODE::R23), maxon::UInt64(enum3087::CURVEINTERPOLATION_MODE::CURRENT)};
	static const maxon::EnumInfo CURVEINTERPOLATION_MODE_info{"CURVEINTERPOLATION_MODE", SIZEOF(CURVEINTERPOLATION_MODE), false, "R23\0CURRENT\0", CURVEINTERPOLATION_MODE_values, std::extent<decltype(CURVEINTERPOLATION_MODE_values)>::value};
}
const maxon::EnumInfo& PrivateGetEnumInfo_CURVEINTERPOLATION_MODE3087(){ return enum3087::CURVEINTERPOLATION_MODE_info; }
namespace enum3102
{
	enum class BUILDFLAGS
	{
		NONE							= 0,						///< None.
		INTERNALRENDERER	= (1 << 1),			///< Rendering in the editor.
		EXTERNALRENDERER	= (1 << 2),			///< Rendering externally.
		ISOPARM						= (1 << 3),			///< Generate isoparm objects.
		EXPORTONLY				= (1 << 4)			///< Exporting (e.g. Alembic).
	} ;
	static const maxon::UInt64 BUILDFLAGS_values[] = {maxon::UInt64(enum3102::BUILDFLAGS::NONE), maxon::UInt64(enum3102::BUILDFLAGS::INTERNALRENDERER), maxon::UInt64(enum3102::BUILDFLAGS::EXTERNALRENDERER), maxon::UInt64(enum3102::BUILDFLAGS::ISOPARM), maxon::UInt64(enum3102::BUILDFLAGS::EXPORTONLY)};
	static const maxon::EnumInfo BUILDFLAGS_info{"BUILDFLAGS", SIZEOF(BUILDFLAGS), true, "NONE\0INTERNALRENDERER\0EXTERNALRENDERER\0ISOPARM\0EXPORTONLY\0", BUILDFLAGS_values, std::extent<decltype(BUILDFLAGS_values)>::value};
}
const maxon::EnumInfo& PrivateGetEnumInfo_BUILDFLAGS3102(){ return enum3102::BUILDFLAGS_info; }
namespace enum3121
{
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
	} ;
	static const maxon::UInt64 EXECUTIONFLAGS_values[] = {maxon::UInt64(enum3121::EXECUTIONFLAGS::NONE), maxon::UInt64(enum3121::EXECUTIONFLAGS::ANIMATION), maxon::UInt64(enum3121::EXECUTIONFLAGS::EXPRESSION), maxon::UInt64(enum3121::EXECUTIONFLAGS::CACHEBUILDING), maxon::UInt64(enum3121::EXECUTIONFLAGS::CAMERAONLY), maxon::UInt64(enum3121::EXECUTIONFLAGS::INDRAG), maxon::UInt64(enum3121::EXECUTIONFLAGS::INMOVE), maxon::UInt64(enum3121::EXECUTIONFLAGS::RENDER), maxon::UInt64(enum3121::EXECUTIONFLAGS::ALLOW_PRIORITYSHIFT)};
	static const maxon::EnumInfo EXECUTIONFLAGS_info{"EXECUTIONFLAGS", SIZEOF(EXECUTIONFLAGS), true, "NONE\0ANIMATION\0EXPRESSION\0CACHEBUILDING\0CAMERAONLY\0INDRAG\0INMOVE\0RENDER\0ALLOW_PRIORITYSHIFT\0", EXECUTIONFLAGS_values, std::extent<decltype(EXECUTIONFLAGS_values)>::value};
}
const maxon::EnumInfo& PrivateGetEnumInfo_EXECUTIONFLAGS3121(){ return enum3121::EXECUTIONFLAGS_info; }
namespace enum3135
{
	enum class SCENEHOOKDRAW
	{
		NONE												= 0,						///< None.
		DRAW_PASS										= (1 << 0),			///< Normal drawing pass.
		HIGHLIGHT_PASS_BEFORE_TOOL	= (1 << 1),			///< Highlight pass before tool drawing.
		HIGHLIGHT_PASS							= (1 << 2),			///< Highlight pass.
		HIGHLIGHT_PASS_INV					= (1 << 3),			///< Inverted highlight pass.
		DRAW_PASS_AFTER_CLEAR				= (1 << 4)			///< Immediately after clearing the viewport.
	} ;
	static const maxon::UInt64 SCENEHOOKDRAW_values[] = {maxon::UInt64(enum3135::SCENEHOOKDRAW::NONE), maxon::UInt64(enum3135::SCENEHOOKDRAW::DRAW_PASS), maxon::UInt64(enum3135::SCENEHOOKDRAW::HIGHLIGHT_PASS_BEFORE_TOOL), maxon::UInt64(enum3135::SCENEHOOKDRAW::HIGHLIGHT_PASS), maxon::UInt64(enum3135::SCENEHOOKDRAW::HIGHLIGHT_PASS_INV), maxon::UInt64(enum3135::SCENEHOOKDRAW::DRAW_PASS_AFTER_CLEAR)};
	static const maxon::EnumInfo SCENEHOOKDRAW_info{"SCENEHOOKDRAW", SIZEOF(SCENEHOOKDRAW), true, "NONE\0DRAW_PASS\0HIGHLIGHT_PASS_BEFORE_TOOL\0HIGHLIGHT_PASS\0HIGHLIGHT_PASS_INV\0DRAW_PASS_AFTER_CLEAR\0", SCENEHOOKDRAW_values, std::extent<decltype(SCENEHOOKDRAW_values)>::value};
}
const maxon::EnumInfo& PrivateGetEnumInfo_SCENEHOOKDRAW3135(){ return enum3135::SCENEHOOKDRAW_info; }
namespace enum3157
{
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
		NEUTRON_OM_LINK				= (1 << 11)			///< @markInternal Set when the description of a Neutron object shall use OM links for link scene ports.
	} ;
	static const maxon::UInt64 DESCFLAGS_DESC_values[] = {maxon::UInt64(enum3157::DESCFLAGS_DESC::NONE), maxon::UInt64(enum3157::DESCFLAGS_DESC::RESOLVEMULTIPLEDATA), maxon::UInt64(enum3157::DESCFLAGS_DESC::LOADED), maxon::UInt64(enum3157::DESCFLAGS_DESC::RECURSIONLOCK), maxon::UInt64(enum3157::DESCFLAGS_DESC::DONTLOADDEFAULT), maxon::UInt64(enum3157::DESCFLAGS_DESC::MAPTAGS), maxon::UInt64(enum3157::DESCFLAGS_DESC::NEEDDEFAULTVALUE), maxon::UInt64(enum3157::DESCFLAGS_DESC::TRISTATE), maxon::UInt64(enum3157::DESCFLAGS_DESC::EXPORTHELPSYMBOLSMODE), maxon::UInt64(enum3157::DESCFLAGS_DESC::MATREFLECTANCEOVERLAP), maxon::UInt64(enum3157::DESCFLAGS_DESC::XPRESSO), maxon::UInt64(enum3157::DESCFLAGS_DESC::PRESET), maxon::UInt64(enum3157::DESCFLAGS_DESC::NEUTRON_OM_LINK)};
	static const maxon::EnumInfo DESCFLAGS_DESC_info{"DESCFLAGS_DESC", SIZEOF(DESCFLAGS_DESC), true, "NONE\0RESOLVEMULTIPLEDATA\0LOADED\0RECURSIONLOCK\0DONTLOADDEFAULT\0MAPTAGS\0NEEDDEFAULTVALUE\0TRISTATE\0EXPORTHELPSYMBOLSMODE\0MATREFLECTANCEOVERLAP\0XPRESSO\0PRESET\0NEUTRON_OM_LINK\0", DESCFLAGS_DESC_values, std::extent<decltype(DESCFLAGS_DESC_values)>::value};
}
const maxon::EnumInfo& PrivateGetEnumInfo_DESCFLAGS_DESC3157(){ return enum3157::DESCFLAGS_DESC_info; }
namespace enum3172
{
	enum class DESCFLAGS_GET
	{
		NONE												= 0,						///< None.
		PARAM_GET										= (1 << 1),			///< Parameter retrieved.
		NO_GLOBALDATA								= (1 << 4),			///< @markPrivate
		NO_GEDATADEFAULTVALUE				= (1 << 5),			///< If set, the GeData default type will not be initialized for C4DAtom::GetParameter.
		ALLOW_TRISTATE							= (1 << 6),			///< If set, is permitted to return GeData of type DA_TRISTATE to indicate that there are multiple values.
		PRIVATE_GETDEFAULTVALUEONLY = (1 << 7),			///< If set, only the default value will be returned (works only with AMEmulationNode)
	} ;
	static const maxon::UInt64 DESCFLAGS_GET_values[] = {maxon::UInt64(enum3172::DESCFLAGS_GET::NONE), maxon::UInt64(enum3172::DESCFLAGS_GET::PARAM_GET), maxon::UInt64(enum3172::DESCFLAGS_GET::NO_GLOBALDATA), maxon::UInt64(enum3172::DESCFLAGS_GET::NO_GEDATADEFAULTVALUE), maxon::UInt64(enum3172::DESCFLAGS_GET::ALLOW_TRISTATE), maxon::UInt64(enum3172::DESCFLAGS_GET::PRIVATE_GETDEFAULTVALUEONLY)};
	static const maxon::EnumInfo DESCFLAGS_GET_info{"DESCFLAGS_GET", SIZEOF(DESCFLAGS_GET), true, "NONE\0PARAM_GET\0NO_GLOBALDATA\0NO_GEDATADEFAULTVALUE\0ALLOW_TRISTATE\0PRIVATE_GETDEFAULTVALUEONLY\0", DESCFLAGS_GET_values, std::extent<decltype(DESCFLAGS_GET_values)>::value};
}
const maxon::EnumInfo& PrivateGetEnumInfo_DESCFLAGS_GET3172(){ return enum3172::DESCFLAGS_GET_info; }
namespace enum3192
{
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
	} ;
	static const maxon::UInt64 DESCFLAGS_SET_values[] = {maxon::UInt64(enum3192::DESCFLAGS_SET::NONE), maxon::UInt64(enum3192::DESCFLAGS_SET::PARAM_SET), maxon::UInt64(enum3192::DESCFLAGS_SET::USERINTERACTION), maxon::UInt64(enum3192::DESCFLAGS_SET::DONTCHECKMINMAX), maxon::UInt64(enum3192::DESCFLAGS_SET::DONTAFFECTINHERITANCE), maxon::UInt64(enum3192::DESCFLAGS_SET::FORCESET), maxon::UInt64(enum3192::DESCFLAGS_SET::DONTFREESPLINECACHE), maxon::UInt64(enum3192::DESCFLAGS_SET::INDRAG), maxon::UInt64(enum3192::DESCFLAGS_SET::INRESETTODEFAULT)};
	static const maxon::EnumInfo DESCFLAGS_SET_info{"DESCFLAGS_SET", SIZEOF(DESCFLAGS_SET), true, "NONE\0PARAM_SET\0USERINTERACTION\0DONTCHECKMINMAX\0DONTAFFECTINHERITANCE\0FORCESET\0DONTFREESPLINECACHE\0INDRAG\0INRESETTODEFAULT\0", DESCFLAGS_SET_values, std::extent<decltype(DESCFLAGS_SET_values)>::value};
}
const maxon::EnumInfo& PrivateGetEnumInfo_DESCFLAGS_SET3192(){ return enum3192::DESCFLAGS_SET_info; }
namespace enum3201
{
	enum class DESCFLAGS_ENABLE
	{
		NONE = 0			///< None.
	} ;
	static const maxon::UInt64 DESCFLAGS_ENABLE_values[] = {maxon::UInt64(enum3201::DESCFLAGS_ENABLE::NONE)};
	static const maxon::EnumInfo DESCFLAGS_ENABLE_info{"DESCFLAGS_ENABLE", SIZEOF(DESCFLAGS_ENABLE), true, "NONE\0", DESCFLAGS_ENABLE_values, std::extent<decltype(DESCFLAGS_ENABLE_values)>::value};
}
const maxon::EnumInfo& PrivateGetEnumInfo_DESCFLAGS_ENABLE3201(){ return enum3201::DESCFLAGS_ENABLE_info; }
namespace enum3216
{
	enum class HIERARCHYCLONEFLAGS
	{
		NONE			= 0,						///< None.
		ASIS			= (1 << 0),			///< Objects unchanged. (Used by e.g. @ref Oarray.)
		ASPOLY		= (1 << 1),			///< Objects cloned as polygons. (Used by e.g. HyperNURBS.)
		ASLINE		= (1 << 2),			///< Objects cloned as line objects.
		ASSPLINE	= (1 << 3),			///< Objects cloned as splines.
		ASVOLUME	= (1 << 4),			///< Objects cloned as volumes.
	} ;
	static const maxon::UInt64 HIERARCHYCLONEFLAGS_values[] = {maxon::UInt64(enum3216::HIERARCHYCLONEFLAGS::NONE), maxon::UInt64(enum3216::HIERARCHYCLONEFLAGS::ASIS), maxon::UInt64(enum3216::HIERARCHYCLONEFLAGS::ASPOLY), maxon::UInt64(enum3216::HIERARCHYCLONEFLAGS::ASLINE), maxon::UInt64(enum3216::HIERARCHYCLONEFLAGS::ASSPLINE), maxon::UInt64(enum3216::HIERARCHYCLONEFLAGS::ASVOLUME)};
	static const maxon::EnumInfo HIERARCHYCLONEFLAGS_info{"HIERARCHYCLONEFLAGS", SIZEOF(HIERARCHYCLONEFLAGS), true, "NONE\0ASIS\0ASPOLY\0ASLINE\0ASSPLINE\0ASVOLUME\0", HIERARCHYCLONEFLAGS_values, std::extent<decltype(HIERARCHYCLONEFLAGS_values)>::value};
}
const maxon::EnumInfo& PrivateGetEnumInfo_HIERARCHYCLONEFLAGS3216(){ return enum3216::HIERARCHYCLONEFLAGS_info; }
namespace enum3231
{
	enum class CHECKVALUEFORMAT
	{
		NOTHING	= 0,			///< No unit.
		DEGREE	= 1,			///< Degrees.
		PERCENT	= 2,			///< Percent.
		METER		= 3,			///< Meter. Working unit.
		INT			= 5				///< Integer.
	} ;
	static const maxon::UInt64 CHECKVALUEFORMAT_values[] = {maxon::UInt64(enum3231::CHECKVALUEFORMAT::NOTHING), maxon::UInt64(enum3231::CHECKVALUEFORMAT::DEGREE), maxon::UInt64(enum3231::CHECKVALUEFORMAT::PERCENT), maxon::UInt64(enum3231::CHECKVALUEFORMAT::METER), maxon::UInt64(enum3231::CHECKVALUEFORMAT::INT)};
	static const maxon::EnumInfo CHECKVALUEFORMAT_info{"CHECKVALUEFORMAT", SIZEOF(CHECKVALUEFORMAT), false, "NOTHING\0DEGREE\0PERCENT\0METER\0INT\0", CHECKVALUEFORMAT_values, std::extent<decltype(CHECKVALUEFORMAT_values)>::value};
}
const maxon::EnumInfo& PrivateGetEnumInfo_CHECKVALUEFORMAT3231(){ return enum3231::CHECKVALUEFORMAT_info; }
namespace enum3250
{
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
	} ;
	static const maxon::UInt64 CHECKVALUERANGE_values[] = {maxon::UInt64(enum3250::CHECKVALUERANGE::GREATER), maxon::UInt64(enum3250::CHECKVALUERANGE::GREATEROREQUAL), maxon::UInt64(enum3250::CHECKVALUERANGE::LESS), maxon::UInt64(enum3250::CHECKVALUERANGE::LESSOREQUAL), maxon::UInt64(enum3250::CHECKVALUERANGE::BETWEEN), maxon::UInt64(enum3250::CHECKVALUERANGE::BETWEENOREQUAL), maxon::UInt64(enum3250::CHECKVALUERANGE::BETWEENOREQUALX), maxon::UInt64(enum3250::CHECKVALUERANGE::BETWEENOREQUALY), maxon::UInt64(enum3250::CHECKVALUERANGE::DIFFERENT)};
	static const maxon::EnumInfo CHECKVALUERANGE_info{"CHECKVALUERANGE", SIZEOF(CHECKVALUERANGE), false, "GREATER\0GREATEROREQUAL\0LESS\0LESSOREQUAL\0BETWEEN\0BETWEENOREQUAL\0BETWEENOREQUALX\0BETWEENOREQUALY\0DIFFERENT\0", CHECKVALUERANGE_values, std::extent<decltype(CHECKVALUERANGE_values)>::value};
}
const maxon::EnumInfo& PrivateGetEnumInfo_CHECKVALUERANGE3250(){ return enum3250::CHECKVALUERANGE_info; }
namespace enum3279
{
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
	} ;
	static const maxon::UInt64 PAINTMESHFLAGS_values[] = {maxon::UInt64(enum3279::PAINTMESHFLAGS::NONE), maxon::UInt64(enum3279::PAINTMESHFLAGS::QUAD), maxon::UInt64(enum3279::PAINTMESHFLAGS::SEL), maxon::UInt64(enum3279::PAINTMESHFLAGS::SELA), maxon::UInt64(enum3279::PAINTMESHFLAGS::SELB), maxon::UInt64(enum3279::PAINTMESHFLAGS::SELC), maxon::UInt64(enum3279::PAINTMESHFLAGS::SELD), maxon::UInt64(enum3279::PAINTMESHFLAGS::TA), maxon::UInt64(enum3279::PAINTMESHFLAGS::TB), maxon::UInt64(enum3279::PAINTMESHFLAGS::TC), maxon::UInt64(enum3279::PAINTMESHFLAGS::TD), maxon::UInt64(enum3279::PAINTMESHFLAGS::INACTIVE), maxon::UInt64(enum3279::PAINTMESHFLAGS::EDGEA), maxon::UInt64(enum3279::PAINTMESHFLAGS::EDGEB), maxon::UInt64(enum3279::PAINTMESHFLAGS::EDGEC), maxon::UInt64(enum3279::PAINTMESHFLAGS::EDGED)};
	static const maxon::EnumInfo PAINTMESHFLAGS_info{"PAINTMESHFLAGS", SIZEOF(PAINTMESHFLAGS), true, "NONE\0QUAD\0SEL\0SELA\0SELB\0SELC\0SELD\0TA\0TB\0TC\0TD\0INACTIVE\0EDGEA\0EDGEB\0EDGEC\0EDGED\0", PAINTMESHFLAGS_values, std::extent<decltype(PAINTMESHFLAGS_values)>::value};
}
const maxon::EnumInfo& PrivateGetEnumInfo_PAINTMESHFLAGS3279(){ return enum3279::PAINTMESHFLAGS_info; }
namespace enum3293
{
	enum class GETBRANCHINFO
	{
		NONE							= 0,						///< None.
		ONLYWITHCHILDREN	= (1 << 1),			///< Only return branch if it is in use, i.e. has content.
		GELISTNODES				= (1 << 3),			///< @markPrivate
		ONLYMODIFIABLE		= (1 << 4),			///< @markPrivate
		ONLYWITHANIMATION = (1 << 5),			///< Only return branch if animation flag is set.
	} ;
	static const maxon::UInt64 GETBRANCHINFO_values[] = {maxon::UInt64(enum3293::GETBRANCHINFO::NONE), maxon::UInt64(enum3293::GETBRANCHINFO::ONLYWITHCHILDREN), maxon::UInt64(enum3293::GETBRANCHINFO::GELISTNODES), maxon::UInt64(enum3293::GETBRANCHINFO::ONLYMODIFIABLE), maxon::UInt64(enum3293::GETBRANCHINFO::ONLYWITHANIMATION)};
	static const maxon::EnumInfo GETBRANCHINFO_info{"GETBRANCHINFO", SIZEOF(GETBRANCHINFO), true, "NONE\0ONLYWITHCHILDREN\0GELISTNODES\0ONLYMODIFIABLE\0ONLYWITHANIMATION\0", GETBRANCHINFO_values, std::extent<decltype(GETBRANCHINFO_values)>::value};
}
const maxon::EnumInfo& PrivateGetEnumInfo_GETBRANCHINFO3293(){ return enum3293::GETBRANCHINFO_info; }
namespace enum3306
{
	enum class BRANCHINFOFLAGS
	{
		NONE						= 0,						///< None.
		ANIMATE					= (1 << 0),			///< Animate the nodes in this branch.
		HIDEINTIMELINE	= (1 << 4),			///< If set, this branch will not show up in the timeline.
		HASFIELDS				= (1 << 5)			///< If set, this branch will contain FieldLayers and will display in the FieldsList
	} ;
	static const maxon::UInt64 BRANCHINFOFLAGS_values[] = {maxon::UInt64(enum3306::BRANCHINFOFLAGS::NONE), maxon::UInt64(enum3306::BRANCHINFOFLAGS::ANIMATE), maxon::UInt64(enum3306::BRANCHINFOFLAGS::HIDEINTIMELINE), maxon::UInt64(enum3306::BRANCHINFOFLAGS::HASFIELDS)};
	static const maxon::EnumInfo BRANCHINFOFLAGS_info{"BRANCHINFOFLAGS", SIZEOF(BRANCHINFOFLAGS), true, "NONE\0ANIMATE\0HIDEINTIMELINE\0HASFIELDS\0", BRANCHINFOFLAGS_values, std::extent<decltype(BRANCHINFOFLAGS_values)>::value};
}
const maxon::EnumInfo& PrivateGetEnumInfo_BRANCHINFOFLAGS3306(){ return enum3306::BRANCHINFOFLAGS_info; }
namespace enum3318
{
	enum class GETACTIVEOBJECTFLAGS
	{
		NONE						= 0,						///< None.
		CHILDREN				= (1 << 0),			///< Child objects are added to the selection too, provided they are selected. Otherwise only the topmost parent of each chain is added.
		SELECTIONORDER	= (1 << 1)			///< The selection array is sorted in the selection order, e.g. the first selected object is the first element in the array.
	} ;
	static const maxon::UInt64 GETACTIVEOBJECTFLAGS_values[] = {maxon::UInt64(enum3318::GETACTIVEOBJECTFLAGS::NONE), maxon::UInt64(enum3318::GETACTIVEOBJECTFLAGS::CHILDREN), maxon::UInt64(enum3318::GETACTIVEOBJECTFLAGS::SELECTIONORDER)};
	static const maxon::EnumInfo GETACTIVEOBJECTFLAGS_info{"GETACTIVEOBJECTFLAGS", SIZEOF(GETACTIVEOBJECTFLAGS), true, "NONE\0CHILDREN\0SELECTIONORDER\0", GETACTIVEOBJECTFLAGS_values, std::extent<decltype(GETACTIVEOBJECTFLAGS_values)>::value};
}
const maxon::EnumInfo& PrivateGetEnumInfo_GETACTIVEOBJECTFLAGS3318(){ return enum3318::GETACTIVEOBJECTFLAGS_info; }
namespace enum3331
{
	enum class DRAWPASS
	{
		OBJECT			= 0,		///< Object pass.
		BOX					= 1,		///< Box pass.
		HANDLES			= 2,		///< Handle pass.
		HIGHLIGHTS	= 3,		///< Highlight pass.
		XRAY				= 4			///< X-Ray pass.
	} ;
	static const maxon::UInt64 DRAWPASS_values[] = {maxon::UInt64(enum3331::DRAWPASS::OBJECT), maxon::UInt64(enum3331::DRAWPASS::BOX), maxon::UInt64(enum3331::DRAWPASS::HANDLES), maxon::UInt64(enum3331::DRAWPASS::HIGHLIGHTS), maxon::UInt64(enum3331::DRAWPASS::XRAY)};
	static const maxon::EnumInfo DRAWPASS_info{"DRAWPASS", SIZEOF(DRAWPASS), false, "OBJECT\0BOX\0HANDLES\0HIGHLIGHTS\0XRAY\0", DRAWPASS_values, std::extent<decltype(DRAWPASS_values)>::value};
}
const maxon::EnumInfo& PrivateGetEnumInfo_DRAWPASS3331(){ return enum3331::DRAWPASS_info; }
namespace enum3425
{
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
	} ;
	static const maxon::UInt64 SAVEPROJECT_values[] = {maxon::UInt64(enum3425::SAVEPROJECT::NONE), maxon::UInt64(enum3425::SAVEPROJECT::ASSETS), maxon::UInt64(enum3425::SAVEPROJECT::SCENEFILE), maxon::UInt64(enum3425::SAVEPROJECT::DIALOGSALLOWED), maxon::UInt64(enum3425::SAVEPROJECT::SHOWMISSINGASSETDIALOG), maxon::UInt64(enum3425::SAVEPROJECT::ADDTORECENTLIST), maxon::UInt64(enum3425::SAVEPROJECT::DONTCOPYFILES), maxon::UInt64(enum3425::SAVEPROJECT::PROGRESSALLOWED), maxon::UInt64(enum3425::SAVEPROJECT::DONTTOUCHDOCUMENT), maxon::UInt64(enum3425::SAVEPROJECT::DONTFAILONMISSINGASSETS), maxon::UInt64(enum3425::SAVEPROJECT::ISNET), maxon::UInt64(enum3425::SAVEPROJECT::USEDOCUMENTNAMEASFILENAME), maxon::UInt64(enum3425::SAVEPROJECT::DONTCLEARSUGGESTEDFOLDER), maxon::UInt64(enum3425::SAVEPROJECT::WITHCACHES), maxon::UInt64(enum3425::SAVEPROJECT::DONTGENERATEPAINTTEX), maxon::UInt64(enum3425::SAVEPROJECT::ASSETLINKS_COPY_FILEASSETS), maxon::UInt64(enum3425::SAVEPROJECT::ASSETLINKS_COPY_NODEASSETS)};
	static const maxon::EnumInfo SAVEPROJECT_info{"SAVEPROJECT", SIZEOF(SAVEPROJECT), true, "NONE\0ASSETS\0SCENEFILE\0DIALOGSALLOWED\0SHOWMISSINGASSETDIALOG\0ADDTORECENTLIST\0DONTCOPYFILES\0PROGRESSALLOWED\0DONTTOUCHDOCUMENT\0DONTFAILONMISSINGASSETS\0ISNET\0USEDOCUMENTNAMEASFILENAME\0DONTCLEARSUGGESTEDFOLDER\0WITHCACHES\0DONTGENERATEPAINTTEX\0ASSETLINKS_COPY_FILEASSETS\0ASSETLINKS_COPY_NODEASSETS\0", SAVEPROJECT_values, std::extent<decltype(SAVEPROJECT_values)>::value};
}
const maxon::EnumInfo& PrivateGetEnumInfo_SAVEPROJECT3425(){ return enum3425::SAVEPROJECT_info; }
namespace enum3437
{
	enum class ICONDATAFLAGS
	{
		NONE							= 0,						///< None.
		APPLYCOLORPROFILE	= (1 << 0),			///< Apply color profile.
		DISABLED					= (1 << 1)			///< Disabled.
	} ;
	static const maxon::UInt64 ICONDATAFLAGS_values[] = {maxon::UInt64(enum3437::ICONDATAFLAGS::NONE), maxon::UInt64(enum3437::ICONDATAFLAGS::APPLYCOLORPROFILE), maxon::UInt64(enum3437::ICONDATAFLAGS::DISABLED)};
	static const maxon::EnumInfo ICONDATAFLAGS_info{"ICONDATAFLAGS", SIZEOF(ICONDATAFLAGS), true, "NONE\0APPLYCOLORPROFILE\0DISABLED\0", ICONDATAFLAGS_values, std::extent<decltype(ICONDATAFLAGS_values)>::value};
}
const maxon::EnumInfo& PrivateGetEnumInfo_ICONDATAFLAGS3437(){ return enum3437::ICONDATAFLAGS_info; }
namespace enum3452
{
	enum class USERAREAFLAGS
	{
		NONE				= (0),					///< None.
		TABSTOP			= (1 << 0),			///< Tab stop.
		HANDLEFOCUS	= (1 << 1),			///< Handles focus.
		COREMESSAGE	= (1 << 2),			///< Receives core messages.
																///< @see The article @link page_manual_coremessages Core Messages@endlink.
		SYNCMESSAGE	= (1 << 3),			///< Receives sync messages.
		DONT_MIRROR	= (1 << 30)			///< Do not mirror the user area.
	} ;
	static const maxon::UInt64 USERAREAFLAGS_values[] = {maxon::UInt64(enum3452::USERAREAFLAGS::NONE), maxon::UInt64(enum3452::USERAREAFLAGS::TABSTOP), maxon::UInt64(enum3452::USERAREAFLAGS::HANDLEFOCUS), maxon::UInt64(enum3452::USERAREAFLAGS::COREMESSAGE), maxon::UInt64(enum3452::USERAREAFLAGS::SYNCMESSAGE), maxon::UInt64(enum3452::USERAREAFLAGS::DONT_MIRROR)};
	static const maxon::EnumInfo USERAREAFLAGS_info{"USERAREAFLAGS", SIZEOF(USERAREAFLAGS), true, "NONE\0TABSTOP\0HANDLEFOCUS\0COREMESSAGE\0SYNCMESSAGE\0DONT_MIRROR\0", USERAREAFLAGS_values, std::extent<decltype(USERAREAFLAGS_values)>::value};
}
const maxon::EnumInfo& PrivateGetEnumInfo_USERAREAFLAGS3452(){ return enum3452::USERAREAFLAGS_info; }
#ifndef __API_INTERN__
#endif
namespace enum3713
{
	enum class EXECUTIONRESULT
	{
		OK					= 0,			///< OK.
		USERBREAK		= 1,			///< %User break.
		OUTOFMEMORY	= 2				///< Not enough memory.
	} ;
	static const maxon::UInt64 EXECUTIONRESULT_values[] = {maxon::UInt64(enum3713::EXECUTIONRESULT::OK), maxon::UInt64(enum3713::EXECUTIONRESULT::USERBREAK), maxon::UInt64(enum3713::EXECUTIONRESULT::OUTOFMEMORY)};
	static const maxon::EnumInfo EXECUTIONRESULT_info{"EXECUTIONRESULT", SIZEOF(EXECUTIONRESULT), false, "OK\0USERBREAK\0OUTOFMEMORY\0", EXECUTIONRESULT_values, std::extent<decltype(EXECUTIONRESULT_values)>::value};
}
const maxon::EnumInfo& PrivateGetEnumInfo_EXECUTIONRESULT3713(){ return enum3713::EXECUTIONRESULT_info; }
namespace enum3741
{
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
	} ;
	static const maxon::UInt64 IMAGERESULT_values[] = {maxon::UInt64(enum3741::IMAGERESULT::OK), maxon::UInt64(enum3741::IMAGERESULT::NOTEXISTING), maxon::UInt64(enum3741::IMAGERESULT::WRONGTYPE), maxon::UInt64(enum3741::IMAGERESULT::OUTOFMEMORY), maxon::UInt64(enum3741::IMAGERESULT::FILEERROR), maxon::UInt64(enum3741::IMAGERESULT::FILESTRUCTURE), maxon::UInt64(enum3741::IMAGERESULT::MISC_ERROR), maxon::UInt64(enum3741::IMAGERESULT::PARAM_ERROR), maxon::UInt64(enum3741::IMAGERESULT::THREADCANCELED)};
	static const maxon::EnumInfo IMAGERESULT_info{"IMAGERESULT", SIZEOF(IMAGERESULT), false, "OK\0NOTEXISTING\0WRONGTYPE\0OUTOFMEMORY\0FILEERROR\0FILESTRUCTURE\0MISC_ERROR\0PARAM_ERROR\0THREADCANCELED\0", IMAGERESULT_values, std::extent<decltype(IMAGERESULT_values)>::value};
}
const maxon::EnumInfo& PrivateGetEnumInfo_IMAGERESULT3741(){ return enum3741::IMAGERESULT_info; }
namespace enum3756
{
	enum class STRINGENCODING
	{
		XBIT			= 0,		///< An OS dependent encoding. Only use this if data is passed to an OS functions. The actual coding is unspecified.
											///< @note Previously it has been said that this encoding is @em UTF-8. That is not true.
											///< 	BIT8			= 1,		<i>8</i>-bit ASCII. Discards Unicode information.
		BIT7			= 2,		///< <i>7</i>-bit ASCII. Does not understand any international characters, e.g. \"&aring;&auml;&uuml;&ouml;\".
		BIT7HEX		= 3,		///< <i>7</i>-bit ASCII, with any non <i>7</i>-bit characters encoded in the text as e.g. "\uEFA0".
		UTF8			= 4			///< UTF-<i>8</i> encoding.
											///< HTML			= 5, HTML encoding.
	} ;
	static const maxon::UInt64 STRINGENCODING_values[] = {maxon::UInt64(enum3756::STRINGENCODING::XBIT), maxon::UInt64(enum3756::STRINGENCODING::BIT7), maxon::UInt64(enum3756::STRINGENCODING::BIT7HEX), maxon::UInt64(enum3756::STRINGENCODING::UTF8)};
	static const maxon::EnumInfo STRINGENCODING_info{"STRINGENCODING", SIZEOF(STRINGENCODING), false, "XBIT\0BIT7\0BIT7HEX\0UTF8\0", STRINGENCODING_values, std::extent<decltype(STRINGENCODING_values)>::value};
}
const maxon::EnumInfo& PrivateGetEnumInfo_STRINGENCODING3756(){ return enum3756::STRINGENCODING_info; }
namespace enum3767
{
	enum class THREADMODE
	{
		DEPRECATED_SYNCHRONOUS	= 0,			///< Synchronous thread. @markDeprecated
		ASYNC										= 1,			///< Asynchronous thread.
		PRIVATE_OPENGL					= 3				///< @markPrivate @since R18
	} ;
	static const maxon::UInt64 THREADMODE_values[] = {maxon::UInt64(enum3767::THREADMODE::DEPRECATED_SYNCHRONOUS), maxon::UInt64(enum3767::THREADMODE::ASYNC), maxon::UInt64(enum3767::THREADMODE::PRIVATE_OPENGL)};
	static const maxon::EnumInfo THREADMODE_info{"THREADMODE", SIZEOF(THREADMODE), false, "DEPRECATED_SYNCHRONOUS\0ASYNC\0PRIVATE_OPENGL\0", THREADMODE_values, std::extent<decltype(THREADMODE_values)>::value};
}
const maxon::EnumInfo& PrivateGetEnumInfo_THREADMODE3767(){ return enum3767::THREADMODE_info; }
namespace enum3779
{
	enum class THREADPRIORITYEX
	{
		NORMAL	= 0,				///< Normal.
		ABOVE	= 1000,			///< Above.
		BELOW	= 1001,			///< Below.
		LOWEST	= 1002			///< Lowest.
	} ;
	static const maxon::UInt64 THREADPRIORITYEX_values[] = {maxon::UInt64(enum3779::THREADPRIORITYEX::NORMAL), maxon::UInt64(enum3779::THREADPRIORITYEX::ABOVE), maxon::UInt64(enum3779::THREADPRIORITYEX::BELOW), maxon::UInt64(enum3779::THREADPRIORITYEX::LOWEST)};
	static const maxon::EnumInfo THREADPRIORITYEX_info{"THREADPRIORITYEX", SIZEOF(THREADPRIORITYEX), false, "NORMAL\0ABOVE\0BELOW\0LOWEST\0", THREADPRIORITYEX_values, std::extent<decltype(THREADPRIORITYEX_values)>::value};
}
const maxon::EnumInfo& PrivateGetEnumInfo_THREADPRIORITYEX3779(){ return enum3779::THREADPRIORITYEX_info; }
namespace enum3794
{
	enum class HYPERFILEARRAY
	{
		CHAR	= 1,			///< ::Char array.
		WORD	= 2,			///< ::Int16 array.
		LONG	= 3,			///< ::Int32 array.
		LLONG	= 4,			///< ::Int64 array.
		SREAL	= 5,			///< ::Float32 array.
		LREAL	= 6,			///< ::Float64 array.
		REAL	= 7				///< ::Float array.
	} ;
	static const maxon::UInt64 HYPERFILEARRAY_values[] = {maxon::UInt64(enum3794::HYPERFILEARRAY::CHAR), maxon::UInt64(enum3794::HYPERFILEARRAY::WORD), maxon::UInt64(enum3794::HYPERFILEARRAY::LONG), maxon::UInt64(enum3794::HYPERFILEARRAY::LLONG), maxon::UInt64(enum3794::HYPERFILEARRAY::SREAL), maxon::UInt64(enum3794::HYPERFILEARRAY::LREAL), maxon::UInt64(enum3794::HYPERFILEARRAY::REAL)};
	static const maxon::EnumInfo HYPERFILEARRAY_info{"HYPERFILEARRAY", SIZEOF(HYPERFILEARRAY), false, "CHAR\0WORD\0LONG\0LLONG\0SREAL\0LREAL\0REAL\0", HYPERFILEARRAY_values, std::extent<decltype(HYPERFILEARRAY_values)>::value};
}
const maxon::EnumInfo& PrivateGetEnumInfo_HYPERFILEARRAY3794(){ return enum3794::HYPERFILEARRAY_info; }
namespace enum3818
{
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
	} ;
	static const maxon::UInt64 FILEERROR_values[] = {maxon::UInt64(enum3818::FILEERROR::NONE), maxon::UInt64(enum3818::FILEERROR::OPEN), maxon::UInt64(enum3818::FILEERROR::CLOSE), maxon::UInt64(enum3818::FILEERROR::READ), maxon::UInt64(enum3818::FILEERROR::WRITE), maxon::UInt64(enum3818::FILEERROR::SEEK), maxon::UInt64(enum3818::FILEERROR::INVALID), maxon::UInt64(enum3818::FILEERROR::OUTOFMEMORY), maxon::UInt64(enum3818::FILEERROR::USERBREAK), maxon::UInt64(enum3818::FILEERROR::WRONG_VALUE), maxon::UInt64(enum3818::FILEERROR::CHUNK_NUMBER), maxon::UInt64(enum3818::FILEERROR::VALUE_NO_CHUNK), maxon::UInt64(enum3818::FILEERROR::FILEEND), maxon::UInt64(enum3818::FILEERROR::UNKNOWN_VALUE)};
	static const maxon::EnumInfo FILEERROR_info{"FILEERROR", SIZEOF(FILEERROR), false, "NONE\0OPEN\0CLOSE\0READ\0WRITE\0SEEK\0INVALID\0OUTOFMEMORY\0USERBREAK\0WRONG_VALUE\0CHUNK_NUMBER\0VALUE_NO_CHUNK\0FILEEND\0UNKNOWN_VALUE\0", FILEERROR_values, std::extent<decltype(FILEERROR_values)>::value};
}
const maxon::EnumInfo& PrivateGetEnumInfo_FILEERROR3818(){ return enum3818::FILEERROR_info; }
namespace enum3834
{
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
	} ;
	static const maxon::UInt64 FILEOPEN_values[] = {maxon::UInt64(enum3834::FILEOPEN::APPEND), maxon::UInt64(enum3834::FILEOPEN::READ), maxon::UInt64(enum3834::FILEOPEN::WRITE), maxon::UInt64(enum3834::FILEOPEN::READWRITE), maxon::UInt64(enum3834::FILEOPEN::READ_NOCACHE), maxon::UInt64(enum3834::FILEOPEN::SHAREDREAD), maxon::UInt64(enum3834::FILEOPEN::SHAREDWRITE)};
	static const maxon::EnumInfo FILEOPEN_info{"FILEOPEN", SIZEOF(FILEOPEN), false, "APPEND\0READ\0WRITE\0READWRITE\0READ_NOCACHE\0SHAREDREAD\0SHAREDWRITE\0", FILEOPEN_values, std::extent<decltype(FILEOPEN_values)>::value};
}
const maxon::EnumInfo& PrivateGetEnumInfo_FILEOPEN3834(){ return enum3834::FILEOPEN_info; }
namespace enum3845
{
	enum class LOCATION
	{
		DISK					= 1,			///< Disk storage.
		IPCONNECTION	= 2,			///< Target is IP connection.
		MEMORY				= 3				///< Target is a memory location.
	} ;
	static const maxon::UInt64 LOCATION_values[] = {maxon::UInt64(enum3845::LOCATION::DISK), maxon::UInt64(enum3845::LOCATION::IPCONNECTION), maxon::UInt64(enum3845::LOCATION::MEMORY)};
	static const maxon::EnumInfo LOCATION_info{"LOCATION", SIZEOF(LOCATION), false, "DISK\0IPCONNECTION\0MEMORY\0", LOCATION_values, std::extent<decltype(LOCATION_values)>::value};
}
const maxon::EnumInfo& PrivateGetEnumInfo_LOCATION3845(){ return enum3845::LOCATION_info; }
namespace enum3855
{
	enum class FILESEEK
	{
		START			= 0,			///< The position is given relative to the start of the file.
		RELATIVE_	= 2				///< The position is given relative to the current position.
	} ;
	static const maxon::UInt64 FILESEEK_values[] = {maxon::UInt64(enum3855::FILESEEK::START), maxon::UInt64(enum3855::FILESEEK::RELATIVE_)};
	static const maxon::EnumInfo FILESEEK_info{"FILESEEK", SIZEOF(FILESEEK), false, "START\0RELATIVE_\0", FILESEEK_values, std::extent<decltype(FILESEEK_values)>::value};
}
const maxon::EnumInfo& PrivateGetEnumInfo_FILESEEK3855(){ return enum3855::FILESEEK_info; }
namespace enum3866
{
	enum class FILEDIALOG
	{
		NONE				= 0,			///< Never show an error dialog.
		ANY					= 1,			///< Show an error dialog for any error.
		IGNOREOPEN	= 2				///< Do not show an error dialog if the file does not exist, otherwise like @ref FILEDIALOG::ANY.
	} ;
	static const maxon::UInt64 FILEDIALOG_values[] = {maxon::UInt64(enum3866::FILEDIALOG::NONE), maxon::UInt64(enum3866::FILEDIALOG::ANY), maxon::UInt64(enum3866::FILEDIALOG::IGNOREOPEN)};
	static const maxon::EnumInfo FILEDIALOG_info{"FILEDIALOG", SIZEOF(FILEDIALOG), false, "NONE\0ANY\0IGNOREOPEN\0", FILEDIALOG_values, std::extent<decltype(FILEDIALOG_values)>::value};
}
const maxon::EnumInfo& PrivateGetEnumInfo_FILEDIALOG3866(){ return enum3866::FILEDIALOG_info; }
namespace enum3877
{
	enum class FILESELECT
	{
		LOAD				= 0,			///< Load dialog.
		SAVE				= 1,			///< Save dialog.
		DIRECTORY	= 2				///< Folder selection dialog.
	} ;
	static const maxon::UInt64 FILESELECT_values[] = {maxon::UInt64(enum3877::FILESELECT::LOAD), maxon::UInt64(enum3877::FILESELECT::SAVE), maxon::UInt64(enum3877::FILESELECT::DIRECTORY)};
	static const maxon::EnumInfo FILESELECT_info{"FILESELECT", SIZEOF(FILESELECT), false, "LOAD\0SAVE\0DIRECTORY\0", FILESELECT_values, std::extent<decltype(FILESELECT_values)>::value};
}
const maxon::EnumInfo& PrivateGetEnumInfo_FILESELECT3877(){ return enum3877::FILESELECT_info; }
namespace enum3889
{
	enum class FILESELECTTYPE
	{
		ANYTHING		= 0,			///< Any file.
		IMAGES			= 1,			///< Image files.
		SCENES			= 2,			///< 3D scene files.
		BODYPAINT		= 4				///< @BP3D files.
	} ;
	static const maxon::UInt64 FILESELECTTYPE_values[] = {maxon::UInt64(enum3889::FILESELECTTYPE::ANYTHING), maxon::UInt64(enum3889::FILESELECTTYPE::IMAGES), maxon::UInt64(enum3889::FILESELECTTYPE::SCENES), maxon::UInt64(enum3889::FILESELECTTYPE::BODYPAINT)};
	static const maxon::EnumInfo FILESELECTTYPE_info{"FILESELECTTYPE", SIZEOF(FILESELECTTYPE), false, "ANYTHING\0IMAGES\0SCENES\0BODYPAINT\0", FILESELECTTYPE_values, std::extent<decltype(FILESELECTTYPE_values)>::value};
}
const maxon::EnumInfo& PrivateGetEnumInfo_FILESELECTTYPE3889(){ return enum3889::FILESELECTTYPE_info; }
namespace enum3900
{
	enum class OPERATINGSYSTEM
	{
		WIN		= 1,			///< Windows.
		OSX		= 2,			///< OS X.
		LINUX	= 3				///< Linux.
	} ;
	static const maxon::UInt64 OPERATINGSYSTEM_values[] = {maxon::UInt64(enum3900::OPERATINGSYSTEM::WIN), maxon::UInt64(enum3900::OPERATINGSYSTEM::OSX), maxon::UInt64(enum3900::OPERATINGSYSTEM::LINUX)};
	static const maxon::EnumInfo OPERATINGSYSTEM_info{"OPERATINGSYSTEM", SIZEOF(OPERATINGSYSTEM), false, "WIN\0OSX\0LINUX\0", OPERATINGSYSTEM_values, std::extent<decltype(OPERATINGSYSTEM_values)>::value};
}
const maxon::EnumInfo& PrivateGetEnumInfo_OPERATINGSYSTEM3900(){ return enum3900::OPERATINGSYSTEM_info; }
namespace enum3911
{
	enum class BYTEORDER
	{
		// V_ unfortunately has to be used here due to conflicts with MAC OS
		V_MOTOROLA	= 1,			///< Motorola, big endian.
		V_INTEL			= 2				///< Intel, little endian.
	} ;
	static const maxon::UInt64 BYTEORDER_values[] = {maxon::UInt64(enum3911::BYTEORDER::V_MOTOROLA), maxon::UInt64(enum3911::BYTEORDER::V_INTEL)};
	static const maxon::EnumInfo BYTEORDER_info{"BYTEORDER", SIZEOF(BYTEORDER), false, "V_MOTOROLA\0V_INTEL\0", BYTEORDER_values, std::extent<decltype(BYTEORDER_values)>::value};
}
const maxon::EnumInfo& PrivateGetEnumInfo_BYTEORDER3911(){ return enum3911::BYTEORDER_info; }
namespace enum3958
{
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
	} ;
	static const maxon::UInt64 HYPERFILEVALUE_values[] = {maxon::UInt64(enum3958::HYPERFILEVALUE::NONE), maxon::UInt64(enum3958::HYPERFILEVALUE::START), maxon::UInt64(enum3958::HYPERFILEVALUE::STOP), maxon::UInt64(enum3958::HYPERFILEVALUE::CSTOP), maxon::UInt64(enum3958::HYPERFILEVALUE::CHAR), maxon::UInt64(enum3958::HYPERFILEVALUE::UCHAR), maxon::UInt64(enum3958::HYPERFILEVALUE::INT16), maxon::UInt64(enum3958::HYPERFILEVALUE::UINT16), maxon::UInt64(enum3958::HYPERFILEVALUE::INT32), maxon::UInt64(enum3958::HYPERFILEVALUE::UINT32), maxon::UInt64(enum3958::HYPERFILEVALUE::INT64), maxon::UInt64(enum3958::HYPERFILEVALUE::UINT64), maxon::UInt64(enum3958::HYPERFILEVALUE::FLOAT), maxon::UInt64(enum3958::HYPERFILEVALUE::FLOAT64), maxon::UInt64(enum3958::HYPERFILEVALUE::BOOLEAN), maxon::UInt64(enum3958::HYPERFILEVALUE::TIME), maxon::UInt64(enum3958::HYPERFILEVALUE::VECTOR), maxon::UInt64(enum3958::HYPERFILEVALUE::VECTOR64), maxon::UInt64(enum3958::HYPERFILEVALUE::MATRIX), maxon::UInt64(enum3958::HYPERFILEVALUE::MATRIX64), maxon::UInt64(enum3958::HYPERFILEVALUE::VECTOR32), maxon::UInt64(enum3958::HYPERFILEVALUE::MATRIX32), maxon::UInt64(enum3958::HYPERFILEVALUE::FLOAT32), maxon::UInt64(enum3958::HYPERFILEVALUE::MEMORY), maxon::UInt64(enum3958::HYPERFILEVALUE::IMAGE), maxon::UInt64(enum3958::HYPERFILEVALUE::STRING), maxon::UInt64(enum3958::HYPERFILEVALUE::FILENAME), maxon::UInt64(enum3958::HYPERFILEVALUE::CONTAINER), maxon::UInt64(enum3958::HYPERFILEVALUE::ALIASLINK), maxon::UInt64(enum3958::HYPERFILEVALUE::LMEMORY), maxon::UInt64(enum3958::HYPERFILEVALUE::VECTOR_ARRAY_EX), maxon::UInt64(enum3958::HYPERFILEVALUE::POLYGON_ARRAY_EX), maxon::UInt64(enum3958::HYPERFILEVALUE::UINT16_ARRAY_EX), maxon::UInt64(enum3958::HYPERFILEVALUE::PARTICLE_ARRAY_EX), maxon::UInt64(enum3958::HYPERFILEVALUE::SREAL_ARRAY_EX), maxon::UInt64(enum3958::HYPERFILEVALUE::ARRAY), maxon::UInt64(enum3958::HYPERFILEVALUE::UUID)};
	static const maxon::EnumInfo HYPERFILEVALUE_info{"HYPERFILEVALUE", SIZEOF(HYPERFILEVALUE), false, "NONE\0START\0STOP\0CSTOP\0CHAR\0UCHAR\0INT16\0UINT16\0INT32\0UINT32\0INT64\0UINT64\0FLOAT\0FLOAT64\0BOOLEAN\0TIME\0VECTOR\0VECTOR64\0MATRIX\0MATRIX64\0VECTOR32\0MATRIX32\0FLOAT32\0MEMORY\0IMAGE\0STRING\0FILENAME\0CONTAINER\0ALIASLINK\0LMEMORY\0VECTOR_ARRAY_EX\0POLYGON_ARRAY_EX\0UINT16_ARRAY_EX\0PARTICLE_ARRAY_EX\0SREAL_ARRAY_EX\0ARRAY\0UUID\0", HYPERFILEVALUE_values, std::extent<decltype(HYPERFILEVALUE_values)>::value};
}
const maxon::EnumInfo& PrivateGetEnumInfo_HYPERFILEVALUE3958(){ return enum3958::HYPERFILEVALUE_info; }
namespace enum3969
{
	enum class FINDANIM
	{
		EXACT	= 0,			///< Exact.
		LEFT	= 1,			///< Search left.
		RIGHT	= 2				///< Search right.
	} ;
	static const maxon::UInt64 FINDANIM_values[] = {maxon::UInt64(enum3969::FINDANIM::EXACT), maxon::UInt64(enum3969::FINDANIM::LEFT), maxon::UInt64(enum3969::FINDANIM::RIGHT)};
	static const maxon::EnumInfo FINDANIM_info{"FINDANIM", SIZEOF(FINDANIM), false, "EXACT\0LEFT\0RIGHT\0", FINDANIM_values, std::extent<decltype(FINDANIM_values)>::value};
}
const maxon::EnumInfo& PrivateGetEnumInfo_FINDANIM3969(){ return enum3969::FINDANIM_info; }
namespace enum3991
{
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
	} ;
	static const maxon::UInt64 CCURVE_values[] = {maxon::UInt64(enum3991::CCURVE::CURVE), maxon::UInt64(enum3991::CCURVE::HLE_BASE), maxon::UInt64(enum3991::CCURVE::HLE_CURVE), maxon::UInt64(enum3991::CCURVE::SS_CURVE), maxon::UInt64(enum3991::CCURVE::SS_CURVE2), maxon::UInt64(enum3991::CCURVE::SS_CURVE3), maxon::UInt64(enum3991::CCURVE::SS_CURVE4), maxon::UInt64(enum3991::CCURVE::SS_CURVE5), maxon::UInt64(enum3991::CCURVE::HLE_SCALE), maxon::UInt64(enum3991::CCURVE::HLE_MOVE)};
	static const maxon::EnumInfo CCURVE_info{"CCURVE", SIZEOF(CCURVE), false, "CURVE\0HLE_BASE\0HLE_CURVE\0SS_CURVE\0SS_CURVE2\0SS_CURVE3\0SS_CURVE4\0SS_CURVE5\0HLE_SCALE\0HLE_MOVE\0", CCURVE_values, std::extent<decltype(CCURVE_values)>::value};
}
const maxon::EnumInfo& PrivateGetEnumInfo_CCURVE3991(){ return enum3991::CCURVE_info; }
namespace enum4006
{
	enum class CLOOP
	{
		OFF						= 0,			///< No loop.
		CONSTANT			= 1,			///< Constant.
		CONTINUE			= 2,			///< Continue.
		REPEAT				= 3,			///< Repeat.
		OFFSETREPEAT	= 4,			///< Offset repeat.
		OSCILLATE			= 5,			///< Oscillate.
		LOOP					= 6				///< Loop.
	} ;
	static const maxon::UInt64 CLOOP_values[] = {maxon::UInt64(enum4006::CLOOP::OFF), maxon::UInt64(enum4006::CLOOP::CONSTANT), maxon::UInt64(enum4006::CLOOP::CONTINUE), maxon::UInt64(enum4006::CLOOP::REPEAT), maxon::UInt64(enum4006::CLOOP::OFFSETREPEAT), maxon::UInt64(enum4006::CLOOP::OSCILLATE), maxon::UInt64(enum4006::CLOOP::LOOP)};
	static const maxon::EnumInfo CLOOP_info{"CLOOP", SIZEOF(CLOOP), false, "OFF\0CONSTANT\0CONTINUE\0REPEAT\0OFFSETREPEAT\0OSCILLATE\0LOOP\0", CLOOP_values, std::extent<decltype(CLOOP_values)>::value};
}
const maxon::EnumInfo& PrivateGetEnumInfo_CLOOP4006(){ return enum4006::CLOOP_info; }
namespace enum4019
{
	enum class CINTERPOLATION
	{
		SPLINE	= 1,			///< Spline.
		LINEAR	= 2,			///< Linear.
		STEP		= 3,			///< Step.
	
		DUMMY		= 4
	} ;
	static const maxon::UInt64 CINTERPOLATION_values[] = {maxon::UInt64(enum4019::CINTERPOLATION::SPLINE), maxon::UInt64(enum4019::CINTERPOLATION::LINEAR), maxon::UInt64(enum4019::CINTERPOLATION::STEP), maxon::UInt64(enum4019::CINTERPOLATION::DUMMY)};
	static const maxon::EnumInfo CINTERPOLATION_info{"CINTERPOLATION", SIZEOF(CINTERPOLATION), false, "SPLINE\0LINEAR\0STEP\0DUMMY\0", CINTERPOLATION_values, std::extent<decltype(CINTERPOLATION_values)>::value};
}
const maxon::EnumInfo& PrivateGetEnumInfo_CINTERPOLATION4019(){ return enum4019::CINTERPOLATION_info; }
namespace enum4030
{
	enum class CAUTOMODE
	{
		CLASSIC			= 1,				///< AutoTangent first implementation.
		FIXEDSLOPE	= 2,				///< AutoTangent with fixed slope for given time.
	} ;
	static const maxon::UInt64 CAUTOMODE_values[] = {maxon::UInt64(enum4030::CAUTOMODE::CLASSIC), maxon::UInt64(enum4030::CAUTOMODE::FIXEDSLOPE)};
	static const maxon::EnumInfo CAUTOMODE_info{"CAUTOMODE", SIZEOF(CAUTOMODE), false, "CLASSIC\0FIXEDSLOPE\0", CAUTOMODE_values, std::extent<decltype(CAUTOMODE_values)>::value};
}
const maxon::EnumInfo& PrivateGetEnumInfo_CAUTOMODE4030(){ return enum4030::CAUTOMODE_info; }
namespace enum4044
{
	enum class CKEYPRESET
	{
		AUTO_CLAMP										= 1,			///< Auto, Auto Angle, Clamp.
		AUTO_OVERSHOOT								= 2,			///< Auto, Auto Angle, remove Overshooting.
		FIXED_OVERSHOOTWEIGHTED				= 3,			///< Auto, Fixed Angle, remove Overshooting, weighted.
		CUSTOM												= 4,			///< User Defined.
		AUTO_OVERSHOOTWEIGHTED				= 5,			///< Auto, Auto Angle, remove Overshooting, weighted.
	} ;
	static const maxon::UInt64 CKEYPRESET_values[] = {maxon::UInt64(enum4044::CKEYPRESET::AUTO_CLAMP), maxon::UInt64(enum4044::CKEYPRESET::AUTO_OVERSHOOT), maxon::UInt64(enum4044::CKEYPRESET::FIXED_OVERSHOOTWEIGHTED), maxon::UInt64(enum4044::CKEYPRESET::CUSTOM), maxon::UInt64(enum4044::CKEYPRESET::AUTO_OVERSHOOTWEIGHTED)};
	static const maxon::EnumInfo CKEYPRESET_info{"CKEYPRESET", SIZEOF(CKEYPRESET), false, "AUTO_CLAMP\0AUTO_OVERSHOOT\0FIXED_OVERSHOOTWEIGHTED\0CUSTOM\0AUTO_OVERSHOOTWEIGHTED\0", CKEYPRESET_values, std::extent<decltype(CKEYPRESET_values)>::value};
}
const maxon::EnumInfo& PrivateGetEnumInfo_CKEYPRESET4044(){ return enum4044::CKEYPRESET_info; }
namespace enum4055
{
	enum class CLIPBOARDTYPE
	{
		EMPTY		= 0,			///< Clipboard is empty.
		STRING	= 1,			///< Clipboard contains a string.
		BITMAP	= 2				///< Clipboard contains a bitmap.
	} ;
	static const maxon::UInt64 CLIPBOARDTYPE_values[] = {maxon::UInt64(enum4055::CLIPBOARDTYPE::EMPTY), maxon::UInt64(enum4055::CLIPBOARDTYPE::STRING), maxon::UInt64(enum4055::CLIPBOARDTYPE::BITMAP)};
	static const maxon::EnumInfo CLIPBOARDTYPE_info{"CLIPBOARDTYPE", SIZEOF(CLIPBOARDTYPE), false, "EMPTY\0STRING\0BITMAP\0", CLIPBOARDTYPE_values, std::extent<decltype(CLIPBOARDTYPE_values)>::value};
}
const maxon::EnumInfo& PrivateGetEnumInfo_CLIPBOARDTYPE4055(){ return enum4055::CLIPBOARDTYPE_info; }
namespace enum4067
{
	enum class EDGESELECTIONTYPE
	{
		SELECTION	= 0,			///< Selected edges.
		HIDDEN		= 1,			///< Hidden edges.
		PHONG			= 2				///< Phong edges.
	} ;
	static const maxon::UInt64 EDGESELECTIONTYPE_values[] = {maxon::UInt64(enum4067::EDGESELECTIONTYPE::SELECTION), maxon::UInt64(enum4067::EDGESELECTIONTYPE::HIDDEN), maxon::UInt64(enum4067::EDGESELECTIONTYPE::PHONG)};
	static const maxon::EnumInfo EDGESELECTIONTYPE_info{"EDGESELECTIONTYPE", SIZEOF(EDGESELECTIONTYPE), false, "SELECTION\0HIDDEN\0PHONG\0", EDGESELECTIONTYPE_values, std::extent<decltype(EDGESELECTIONTYPE_values)>::value};
}
const maxon::EnumInfo& PrivateGetEnumInfo_EDGESELECTIONTYPE4067(){ return enum4067::EDGESELECTIONTYPE_info; }
namespace enum4105
{
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
	} ;
	static const maxon::UInt64 REGISTRYTYPE_values[] = {maxon::UInt64(enum4105::REGISTRYTYPE::ANY), maxon::UInt64(enum4105::REGISTRYTYPE::WINDOW), maxon::UInt64(enum4105::REGISTRYTYPE::OBJECT), maxon::UInt64(enum4105::REGISTRYTYPE::TAG), maxon::UInt64(enum4105::REGISTRYTYPE::MATERIAL), maxon::UInt64(enum4105::REGISTRYTYPE::SHADER), maxon::UInt64(enum4105::REGISTRYTYPE::SOUND), maxon::UInt64(enum4105::REGISTRYTYPE::LAYOUT), maxon::UInt64(enum4105::REGISTRYTYPE::BITMAPFILTER), maxon::UInt64(enum4105::REGISTRYTYPE::VIDEOPOST), maxon::UInt64(enum4105::REGISTRYTYPE::SCENEHOOK), maxon::UInt64(enum4105::REGISTRYTYPE::NODE), maxon::UInt64(enum4105::REGISTRYTYPE::DESCRIPTION), maxon::UInt64(enum4105::REGISTRYTYPE::LIBRARY), maxon::UInt64(enum4105::REGISTRYTYPE::CUSTOMDATATYPE), maxon::UInt64(enum4105::REGISTRYTYPE::RESOURCEDATATYPE), maxon::UInt64(enum4105::REGISTRYTYPE::SCENELOADER), maxon::UInt64(enum4105::REGISTRYTYPE::SCENESAVER), maxon::UInt64(enum4105::REGISTRYTYPE::CTRACK), maxon::UInt64(enum4105::REGISTRYTYPE::CSEQ), maxon::UInt64(enum4105::REGISTRYTYPE::CKEY), maxon::UInt64(enum4105::REGISTRYTYPE::PAINTER), maxon::UInt64(enum4105::REGISTRYTYPE::GV_VALUE), maxon::UInt64(enum4105::REGISTRYTYPE::GV_VALGROUP), maxon::UInt64(enum4105::REGISTRYTYPE::GV_OPGROUP), maxon::UInt64(enum4105::REGISTRYTYPE::GV_OPCLASS), maxon::UInt64(enum4105::REGISTRYTYPE::GV_DATA), maxon::UInt64(enum4105::REGISTRYTYPE::GADGETS), maxon::UInt64(enum4105::REGISTRYTYPE::PREFS), maxon::UInt64(enum4105::REGISTRYTYPE::FIELDLAYER)};
	static const maxon::EnumInfo REGISTRYTYPE_info{"REGISTRYTYPE", SIZEOF(REGISTRYTYPE), false, "ANY\0WINDOW\0OBJECT\0TAG\0MATERIAL\0SHADER\0SOUND\0LAYOUT\0BITMAPFILTER\0VIDEOPOST\0SCENEHOOK\0NODE\0DESCRIPTION\0LIBRARY\0CUSTOMDATATYPE\0RESOURCEDATATYPE\0SCENELOADER\0SCENESAVER\0CTRACK\0CSEQ\0CKEY\0PAINTER\0GV_VALUE\0GV_VALGROUP\0GV_OPGROUP\0GV_OPCLASS\0GV_DATA\0GADGETS\0PREFS\0FIELDLAYER\0", REGISTRYTYPE_values, std::extent<decltype(REGISTRYTYPE_values)>::value};
}
const maxon::EnumInfo& PrivateGetEnumInfo_REGISTRYTYPE4105(){ return enum4105::REGISTRYTYPE_info; }
namespace enum4117
{
	enum class MODELINGCOMMANDMODE
	{
		ALL								= 0,			///< All points/polygons.
		POINTSELECTION		= 1,			///< Only the current point selection.
		POLYGONSELECTION	= 2,			///< Only the current polygon selection.
		EDGESELECTION			= 3				///< Only the current edge selection.
	} ;
	static const maxon::UInt64 MODELINGCOMMANDMODE_values[] = {maxon::UInt64(enum4117::MODELINGCOMMANDMODE::ALL), maxon::UInt64(enum4117::MODELINGCOMMANDMODE::POINTSELECTION), maxon::UInt64(enum4117::MODELINGCOMMANDMODE::POLYGONSELECTION), maxon::UInt64(enum4117::MODELINGCOMMANDMODE::EDGESELECTION)};
	static const maxon::EnumInfo MODELINGCOMMANDMODE_info{"MODELINGCOMMANDMODE", SIZEOF(MODELINGCOMMANDMODE), false, "ALL\0POINTSELECTION\0POLYGONSELECTION\0EDGESELECTION\0", MODELINGCOMMANDMODE_values, std::extent<decltype(MODELINGCOMMANDMODE_values)>::value};
}
const maxon::EnumInfo& PrivateGetEnumInfo_MODELINGCOMMANDMODE4117(){ return enum4117::MODELINGCOMMANDMODE_info; }
namespace enum4128
{
	enum class MODELINGCOMMANDFLAGS
	{
		NONE				= 0,						///< None.
		CREATEUNDO	= (1 << 0),			///< Creates undo and inserts newly created objects into ModelingCommandData::doc, instead of returning in ModelingCommandData::result.
		IMPORTER		= (1 << 0)			///< Can be used by importer plugins to avoid additional checks for polygon meshes (e.g conversion of posemorph tags).
	} ;
	static const maxon::UInt64 MODELINGCOMMANDFLAGS_values[] = {maxon::UInt64(enum4128::MODELINGCOMMANDFLAGS::NONE), maxon::UInt64(enum4128::MODELINGCOMMANDFLAGS::CREATEUNDO), maxon::UInt64(enum4128::MODELINGCOMMANDFLAGS::IMPORTER)};
	static const maxon::EnumInfo MODELINGCOMMANDFLAGS_info{"MODELINGCOMMANDFLAGS", SIZEOF(MODELINGCOMMANDFLAGS), true, "NONE\0CREATEUNDO\0IMPORTER\0", MODELINGCOMMANDFLAGS_values, std::extent<decltype(MODELINGCOMMANDFLAGS_values)>::value};
}
const maxon::EnumInfo& PrivateGetEnumInfo_MODELINGCOMMANDFLAGS4128(){ return enum4128::MODELINGCOMMANDFLAGS_info; }
namespace enum4164
{
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
		FIELDLAYER					= 37			///< FieldLayer. (FieldLayer)
	} ;
	static const maxon::UInt64 PLUGINTYPE_values[] = {maxon::UInt64(enum4164::PLUGINTYPE::ANY), maxon::UInt64(enum4164::PLUGINTYPE::SHADER), maxon::UInt64(enum4164::PLUGINTYPE::MATERIAL), maxon::UInt64(enum4164::PLUGINTYPE::COMMAND), maxon::UInt64(enum4164::PLUGINTYPE::OBJECT), maxon::UInt64(enum4164::PLUGINTYPE::TAG), maxon::UInt64(enum4164::PLUGINTYPE::BITMAPFILTER), maxon::UInt64(enum4164::PLUGINTYPE::VIDEOPOST), maxon::UInt64(enum4164::PLUGINTYPE::TOOL), maxon::UInt64(enum4164::PLUGINTYPE::SCENEHOOK), maxon::UInt64(enum4164::PLUGINTYPE::NODE), maxon::UInt64(enum4164::PLUGINTYPE::LIBRARY), maxon::UInt64(enum4164::PLUGINTYPE::BITMAPLOADER), maxon::UInt64(enum4164::PLUGINTYPE::BITMAPSAVER), maxon::UInt64(enum4164::PLUGINTYPE::SCENELOADER), maxon::UInt64(enum4164::PLUGINTYPE::SCENESAVER), maxon::UInt64(enum4164::PLUGINTYPE::COREMESSAGE), maxon::UInt64(enum4164::PLUGINTYPE::CUSTOMGUI), maxon::UInt64(enum4164::PLUGINTYPE::CUSTOMDATATYPE), maxon::UInt64(enum4164::PLUGINTYPE::RESOURCEDATATYPE), maxon::UInt64(enum4164::PLUGINTYPE::MANAGERINFORMATION), maxon::UInt64(enum4164::PLUGINTYPE::CTRACK), maxon::UInt64(enum4164::PLUGINTYPE::FALLOFF), maxon::UInt64(enum4164::PLUGINTYPE::VMAPTRANSFER), maxon::UInt64(enum4164::PLUGINTYPE::PREFS), maxon::UInt64(enum4164::PLUGINTYPE::SNAP), maxon::UInt64(enum4164::PLUGINTYPE::FIELDLAYER)};
	static const maxon::EnumInfo PLUGINTYPE_info{"PLUGINTYPE", SIZEOF(PLUGINTYPE), false, "ANY\0SHADER\0MATERIAL\0COMMAND\0OBJECT\0TAG\0BITMAPFILTER\0VIDEOPOST\0TOOL\0SCENEHOOK\0NODE\0LIBRARY\0BITMAPLOADER\0BITMAPSAVER\0SCENELOADER\0SCENESAVER\0COREMESSAGE\0CUSTOMGUI\0CUSTOMDATATYPE\0RESOURCEDATATYPE\0MANAGERINFORMATION\0CTRACK\0FALLOFF\0VMAPTRANSFER\0PREFS\0SNAP\0FIELDLAYER\0", PLUGINTYPE_values, std::extent<decltype(PLUGINTYPE_values)>::value};
}
const maxon::EnumInfo& PrivateGetEnumInfo_PLUGINTYPE4164(){ return enum4164::PLUGINTYPE_info; }
namespace enum4175
{
	enum class DRAWRESULT
	{
		FAILURE	= 0,			///< There was an error while drawing.
		OK			= 1,			///< Something was drawn.
		SKIP		= 2				///< There was nothing to draw in this pass.
	} ;
	static const maxon::UInt64 DRAWRESULT_values[] = {maxon::UInt64(enum4175::DRAWRESULT::FAILURE), maxon::UInt64(enum4175::DRAWRESULT::OK), maxon::UInt64(enum4175::DRAWRESULT::SKIP)};
	static const maxon::EnumInfo DRAWRESULT_info{"DRAWRESULT", SIZEOF(DRAWRESULT), false, "FAILURE\0OK\0SKIP\0", DRAWRESULT_values, std::extent<decltype(DRAWRESULT_values)>::value};
}
const maxon::EnumInfo& PrivateGetEnumInfo_DRAWRESULT4175(){ return enum4175::DRAWRESULT_info; }
namespace enum4208
{
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
	} ;
	static const maxon::UInt64 DISPLAYMODE_values[] = {maxon::UInt64(enum4208::DISPLAYMODE::UNKNOWN), maxon::UInt64(enum4208::DISPLAYMODE::GOURAUD), maxon::UInt64(enum4208::DISPLAYMODE::QUICK), maxon::UInt64(enum4208::DISPLAYMODE::WIRE), maxon::UInt64(enum4208::DISPLAYMODE::ISOPARM), maxon::UInt64(enum4208::DISPLAYMODE::SHADEDBOX), maxon::UInt64(enum4208::DISPLAYMODE::BOX), maxon::UInt64(enum4208::DISPLAYMODE::SKELETON), maxon::UInt64(enum4208::DISPLAYMODE::GOURAUDWIRE), maxon::UInt64(enum4208::DISPLAYMODE::GOURAUDISOPARM), maxon::UInt64(enum4208::DISPLAYMODE::QUICKWIRE), maxon::UInt64(enum4208::DISPLAYMODE::QUICKISOPARM), maxon::UInt64(enum4208::DISPLAYMODE::FLATWIRE), maxon::UInt64(enum4208::DISPLAYMODE::FLATISOPARM), maxon::UInt64(enum4208::DISPLAYMODE::FLATBOX), maxon::UInt64(enum4208::DISPLAYMODE::HIDDENWIRE), maxon::UInt64(enum4208::DISPLAYMODE::HIDDENISOPARM), maxon::UInt64(enum4208::DISPLAYMODE::HIDDENBOX), maxon::UInt64(enum4208::DISPLAYMODE::SHADEDBOXWIRE), maxon::UInt64(enum4208::DISPLAYMODE::QUICKBOXWIRE), maxon::UInt64(enum4208::DISPLAYMODE::QUICKBOX), maxon::UInt64(enum4208::DISPLAYMODE::PRIVATE_ISOLINE), maxon::UInt64(enum4208::DISPLAYMODE::PRIVATE_FLAT), maxon::UInt64(enum4208::DISPLAYMODE::PRIVATE_HIDDEN)};
	static const maxon::EnumInfo DISPLAYMODE_info{"DISPLAYMODE", SIZEOF(DISPLAYMODE), false, "UNKNOWN\0GOURAUD\0QUICK\0WIRE\0ISOPARM\0SHADEDBOX\0BOX\0SKELETON\0GOURAUDWIRE\0GOURAUDISOPARM\0QUICKWIRE\0QUICKISOPARM\0FLATWIRE\0FLATISOPARM\0FLATBOX\0HIDDENWIRE\0HIDDENISOPARM\0HIDDENBOX\0SHADEDBOXWIRE\0QUICKBOXWIRE\0QUICKBOX\0PRIVATE_ISOLINE\0PRIVATE_FLAT\0PRIVATE_HIDDEN\0", DISPLAYMODE_values, std::extent<decltype(DISPLAYMODE_values)>::value};
}
const maxon::EnumInfo& PrivateGetEnumInfo_DISPLAYMODE4208(){ return enum4208::DISPLAYMODE_info; }
namespace enum4224
{
	enum class DOCUMENTSETTINGS
	{
		GENERAL					= 0,			///< General settings.
		MODELING				= 1,			///< Modeler settings. (See @ref MDATA options.)
		DOCUMENT				= 2,			///< Document settings.
		ANIMATIONSYSTEM	= 7,			///< Timeline settings. @markPrivate
		TOOLS						= 8				///< Tools settings.
	} ;
	static const maxon::UInt64 DOCUMENTSETTINGS_values[] = {maxon::UInt64(enum4224::DOCUMENTSETTINGS::GENERAL), maxon::UInt64(enum4224::DOCUMENTSETTINGS::MODELING), maxon::UInt64(enum4224::DOCUMENTSETTINGS::DOCUMENT), maxon::UInt64(enum4224::DOCUMENTSETTINGS::ANIMATIONSYSTEM), maxon::UInt64(enum4224::DOCUMENTSETTINGS::TOOLS)};
	static const maxon::EnumInfo DOCUMENTSETTINGS_info{"DOCUMENTSETTINGS", SIZEOF(DOCUMENTSETTINGS), false, "GENERAL\0MODELING\0DOCUMENT\0ANIMATIONSYSTEM\0TOOLS\0", DOCUMENTSETTINGS_values, std::extent<decltype(DOCUMENTSETTINGS_values)>::value};
}
const maxon::EnumInfo& PrivateGetEnumInfo_DOCUMENTSETTINGS4224(){ return enum4224::DOCUMENTSETTINGS_info; }
namespace enum4249
{
	enum class VERSIONTYPE
	{
		UNKNOWN						= 0,			///< Unknown version.
	
		LITE							= 1,			///< @C4D Lite. Lite is feature-restricted in many ways and does not allow for loading of plugins.
		BENCHMARK					= 2,			///< Cinebench. Cinebench is restricted to a subset of libraries.
		UPDATER						= 3,			///< Online updater. The Online updater only loads a limited subset of libraries.
	
		TEAMRENDER_CLIENT	= 4,			///< @C4D Teamrender client.
		TEAMRENDER_SERVER	= 5,			///< @C4D Teamrender server.
	
		CINEMA4D					= 10,			///< @C4D Cinema 4D.
	
		COMMANDLINE				= 11,			///< Command line application. Note that this is different from GeGetCinemaInfo(CINEMAINFO::FORBID_GUI). The regular app can run without UI, but is not necessarily a special command line executable.
	
		CINEWARE					= 12,			///< Cineware - The renderer used in AfterEffects, Vectorworks, Archicad and Allplan. Runs without UI and does not allow for plugins. Since R23 it's also available as dynamic library.
	
		CPYTHON						= 14,			///< Python - The python executable. Runs without UI.
		CPYTHON3					= 15,			///< Python 3 - The python executable. Runs without UI.
	} ;
	static const maxon::UInt64 VERSIONTYPE_values[] = {maxon::UInt64(enum4249::VERSIONTYPE::UNKNOWN), maxon::UInt64(enum4249::VERSIONTYPE::LITE), maxon::UInt64(enum4249::VERSIONTYPE::BENCHMARK), maxon::UInt64(enum4249::VERSIONTYPE::UPDATER), maxon::UInt64(enum4249::VERSIONTYPE::TEAMRENDER_CLIENT), maxon::UInt64(enum4249::VERSIONTYPE::TEAMRENDER_SERVER), maxon::UInt64(enum4249::VERSIONTYPE::CINEMA4D), maxon::UInt64(enum4249::VERSIONTYPE::COMMANDLINE), maxon::UInt64(enum4249::VERSIONTYPE::CINEWARE), maxon::UInt64(enum4249::VERSIONTYPE::CPYTHON), maxon::UInt64(enum4249::VERSIONTYPE::CPYTHON3)};
	static const maxon::EnumInfo VERSIONTYPE_info{"VERSIONTYPE", SIZEOF(VERSIONTYPE), false, "UNKNOWN\0LITE\0BENCHMARK\0UPDATER\0TEAMRENDER_CLIENT\0TEAMRENDER_SERVER\0CINEMA4D\0COMMANDLINE\0CINEWARE\0CPYTHON\0CPYTHON3\0", VERSIONTYPE_values, std::extent<decltype(VERSIONTYPE_values)>::value};
}
const maxon::EnumInfo& PrivateGetEnumInfo_VERSIONTYPE4249(){ return enum4249::VERSIONTYPE_info; }
namespace enum4262
{
	enum class LAYERSETMODE
	{
		LAYERS,					///< Layers / layer Sets.
		LAYERMASKS,			///< Layer masks.
		ALPHAS,					///< Alpha channels.
		LAYERALPHA,			///< Layer alpha.
		DISABLED				///< Disabled.
	} ;
	static const maxon::UInt64 LAYERSETMODE_values[] = {maxon::UInt64(enum4262::LAYERSETMODE::LAYERS), maxon::UInt64(enum4262::LAYERSETMODE::LAYERMASKS), maxon::UInt64(enum4262::LAYERSETMODE::ALPHAS), maxon::UInt64(enum4262::LAYERSETMODE::LAYERALPHA), maxon::UInt64(enum4262::LAYERSETMODE::DISABLED)};
	static const maxon::EnumInfo LAYERSETMODE_info{"LAYERSETMODE", SIZEOF(LAYERSETMODE), false, "LAYERS\0LAYERMASKS\0ALPHAS\0LAYERALPHA\0DISABLED\0", LAYERSETMODE_values, std::extent<decltype(LAYERSETMODE_values)>::value};
}
const maxon::EnumInfo& PrivateGetEnumInfo_LAYERSETMODE4262(){ return enum4262::LAYERSETMODE_info; }
namespace enum4309
{
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
	} ;
	static const maxon::UInt64 OBJECTCATEGORY_values[] = {maxon::UInt64(enum4309::OBJECTCATEGORY::NULLOBJECT), maxon::UInt64(enum4309::OBJECTCATEGORY::POLYGON), maxon::UInt64(enum4309::OBJECTCATEGORY::SPLINE), maxon::UInt64(enum4309::OBJECTCATEGORY::GENERATOR), maxon::UInt64(enum4309::OBJECTCATEGORY::HYPERNURBS), maxon::UInt64(enum4309::OBJECTCATEGORY::UNUSED1), maxon::UInt64(enum4309::OBJECTCATEGORY::DEFORMER), maxon::UInt64(enum4309::OBJECTCATEGORY::CAMERA), maxon::UInt64(enum4309::OBJECTCATEGORY::LIGHT), maxon::UInt64(enum4309::OBJECTCATEGORY::SCENE), maxon::UInt64(enum4309::OBJECTCATEGORY::PARTICLE), maxon::UInt64(enum4309::OBJECTCATEGORY::OTHER), maxon::UInt64(enum4309::OBJECTCATEGORY::UNUSED2), maxon::UInt64(enum4309::OBJECTCATEGORY::GRID), maxon::UInt64(enum4309::OBJECTCATEGORY::HORIZON), maxon::UInt64(enum4309::OBJECTCATEGORY::WORLDAXIS), maxon::UInt64(enum4309::OBJECTCATEGORY::BOUNDS), maxon::UInt64(enum4309::OBJECTCATEGORY::HUD), maxon::UInt64(enum4309::OBJECTCATEGORY::SDS), maxon::UInt64(enum4309::OBJECTCATEGORY::HIGHLIGHTING), maxon::UInt64(enum4309::OBJECTCATEGORY::MULTIAXIS), maxon::UInt64(enum4309::OBJECTCATEGORY::OBJECTHANDLES), maxon::UInt64(enum4309::OBJECTCATEGORY::HANDLEBANDS), maxon::UInt64(enum4309::OBJECTCATEGORY::SDSCAGE), maxon::UInt64(enum4309::OBJECTCATEGORY::NGONLINES), maxon::UInt64(enum4309::OBJECTCATEGORY::JOINT), maxon::UInt64(enum4309::OBJECTCATEGORY::OBJECTHIGHLIGHTING), maxon::UInt64(enum4309::OBJECTCATEGORY::GUIDELINES), maxon::UInt64(enum4309::OBJECTCATEGORY::POI), maxon::UInt64(enum4309::OBJECTCATEGORY::GRADIENT), maxon::UInt64(enum4309::OBJECTCATEGORY::BASEGRID), maxon::UInt64(enum4309::OBJECTCATEGORY::HANDLES), maxon::UInt64(enum4309::OBJECTCATEGORY::HAIR), maxon::UInt64(enum4309::OBJECTCATEGORY::FIELD)};
	static const maxon::EnumInfo OBJECTCATEGORY_info{"OBJECTCATEGORY", SIZEOF(OBJECTCATEGORY), false, "NULLOBJECT\0POLYGON\0SPLINE\0GENERATOR\0HYPERNURBS\0UNUSED1\0DEFORMER\0CAMERA\0LIGHT\0SCENE\0PARTICLE\0OTHER\0UNUSED2\0GRID\0HORIZON\0WORLDAXIS\0BOUNDS\0HUD\0SDS\0HIGHLIGHTING\0MULTIAXIS\0OBJECTHANDLES\0HANDLEBANDS\0SDSCAGE\0NGONLINES\0JOINT\0OBJECTHIGHLIGHTING\0GUIDELINES\0POI\0GRADIENT\0BASEGRID\0HANDLES\0HAIR\0FIELD\0", OBJECTCATEGORY_values, std::extent<decltype(OBJECTCATEGORY_values)>::value};
}
const maxon::EnumInfo& PrivateGetEnumInfo_OBJECTCATEGORY4309(){ return enum4309::OBJECTCATEGORY_info; }
namespace enum4330
{
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
	} ;
	static const maxon::UInt64 SELECTIONFILTERBIT_values[] = {maxon::UInt64(enum4330::SELECTIONFILTERBIT::NONE), maxon::UInt64(enum4330::SELECTIONFILTERBIT::NULLOBJECT), maxon::UInt64(enum4330::SELECTIONFILTERBIT::POLYGON), maxon::UInt64(enum4330::SELECTIONFILTERBIT::SPLINE), maxon::UInt64(enum4330::SELECTIONFILTERBIT::GENERATOR), maxon::UInt64(enum4330::SELECTIONFILTERBIT::HYPERNURBS), maxon::UInt64(enum4330::SELECTIONFILTERBIT::DEFORMER), maxon::UInt64(enum4330::SELECTIONFILTERBIT::CAMERA), maxon::UInt64(enum4330::SELECTIONFILTERBIT::LIGHT), maxon::UInt64(enum4330::SELECTIONFILTERBIT::SCENE), maxon::UInt64(enum4330::SELECTIONFILTERBIT::PARTICLE), maxon::UInt64(enum4330::SELECTIONFILTERBIT::OTHER), maxon::UInt64(enum4330::SELECTIONFILTERBIT::JOINT)};
	static const maxon::EnumInfo SELECTIONFILTERBIT_info{"SELECTIONFILTERBIT", SIZEOF(SELECTIONFILTERBIT), true, "NONE\0NULLOBJECT\0POLYGON\0SPLINE\0GENERATOR\0HYPERNURBS\0DEFORMER\0CAMERA\0LIGHT\0SCENE\0PARTICLE\0OTHER\0JOINT\0", SELECTIONFILTERBIT_values, std::extent<decltype(SELECTIONFILTERBIT_values)>::value};
}
const maxon::EnumInfo& PrivateGetEnumInfo_SELECTIONFILTERBIT4330(){ return enum4330::SELECTIONFILTERBIT_info; }
namespace enum4344
{
	enum class OBJECTSTATE
	{
		EDITOR							= 0,		///< Editor visibility.
		RENDER							= 1,		///< Renderer visibility.
		DEFORM							= 2,		///< Deform state.
		REAL_DEFORM					= 3,		///< Real Deform state (MODE_ON, MODE_OFF, MODE_UNKNOWN).
		EDITOR_HIERARCHICAL = 4,		///< Hierarchical editor mode (MODE_ON, MODE_OFF)
		RENDER_HIERARCHICAL	= 5,		///< Hierarchical render mode (MODE_ON, MODE_OFF)
	} ;
	static const maxon::UInt64 OBJECTSTATE_values[] = {maxon::UInt64(enum4344::OBJECTSTATE::EDITOR), maxon::UInt64(enum4344::OBJECTSTATE::RENDER), maxon::UInt64(enum4344::OBJECTSTATE::DEFORM), maxon::UInt64(enum4344::OBJECTSTATE::REAL_DEFORM), maxon::UInt64(enum4344::OBJECTSTATE::EDITOR_HIERARCHICAL), maxon::UInt64(enum4344::OBJECTSTATE::RENDER_HIERARCHICAL)};
	static const maxon::EnumInfo OBJECTSTATE_info{"OBJECTSTATE", SIZEOF(OBJECTSTATE), false, "EDITOR\0RENDER\0DEFORM\0REAL_DEFORM\0EDITOR_HIERARCHICAL\0RENDER_HIERARCHICAL\0", OBJECTSTATE_values, std::extent<decltype(OBJECTSTATE_values)>::value};
}
const maxon::EnumInfo& PrivateGetEnumInfo_OBJECTSTATE4344(){ return enum4344::OBJECTSTATE_info; }
namespace enum4389
{
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
	} ;
	static const maxon::UInt64 DISPLAYFILTER_values[] = {maxon::UInt64(enum4389::DISPLAYFILTER::NONE), maxon::UInt64(enum4389::DISPLAYFILTER::NULLOBJECT), maxon::UInt64(enum4389::DISPLAYFILTER::POLYGON), maxon::UInt64(enum4389::DISPLAYFILTER::SPLINE), maxon::UInt64(enum4389::DISPLAYFILTER::GENERATOR), maxon::UInt64(enum4389::DISPLAYFILTER::HYPERNURBS), maxon::UInt64(enum4389::DISPLAYFILTER::UNUSED1), maxon::UInt64(enum4389::DISPLAYFILTER::DEFORMER), maxon::UInt64(enum4389::DISPLAYFILTER::CAMERA), maxon::UInt64(enum4389::DISPLAYFILTER::LIGHT), maxon::UInt64(enum4389::DISPLAYFILTER::SCENE), maxon::UInt64(enum4389::DISPLAYFILTER::PARTICLE), maxon::UInt64(enum4389::DISPLAYFILTER::OTHER), maxon::UInt64(enum4389::DISPLAYFILTER::UNUSED2), maxon::UInt64(enum4389::DISPLAYFILTER::GRID), maxon::UInt64(enum4389::DISPLAYFILTER::HORIZON), maxon::UInt64(enum4389::DISPLAYFILTER::WORLDAXIS), maxon::UInt64(enum4389::DISPLAYFILTER::BOUNDS), maxon::UInt64(enum4389::DISPLAYFILTER::HUD), maxon::UInt64(enum4389::DISPLAYFILTER::SDS), maxon::UInt64(enum4389::DISPLAYFILTER::HIGHLIGHTING), maxon::UInt64(enum4389::DISPLAYFILTER::MULTIAXIS), maxon::UInt64(enum4389::DISPLAYFILTER::OBJECTHANDLES), maxon::UInt64(enum4389::DISPLAYFILTER::HANDLEBANDS), maxon::UInt64(enum4389::DISPLAYFILTER::SDSCAGE), maxon::UInt64(enum4389::DISPLAYFILTER::NGONLINES), maxon::UInt64(enum4389::DISPLAYFILTER::JOINT), maxon::UInt64(enum4389::DISPLAYFILTER::OBJECTHIGHLIGHTING), maxon::UInt64(enum4389::DISPLAYFILTER::GUIDELINES), maxon::UInt64(enum4389::DISPLAYFILTER::POI), maxon::UInt64(enum4389::DISPLAYFILTER::GRADIENT), maxon::UInt64(enum4389::DISPLAYFILTER::BASEGRID), maxon::UInt64(enum4389::DISPLAYFILTER::HANDLES), maxon::UInt64(enum4389::DISPLAYFILTER::HAIR), maxon::UInt64(enum4389::DISPLAYFILTER::FIELD)};
	static const maxon::EnumInfo DISPLAYFILTER_info{"DISPLAYFILTER", SIZEOF(DISPLAYFILTER), true, "NONE\0NULLOBJECT\0POLYGON\0SPLINE\0GENERATOR\0HYPERNURBS\0UNUSED1\0DEFORMER\0CAMERA\0LIGHT\0SCENE\0PARTICLE\0OTHER\0UNUSED2\0GRID\0HORIZON\0WORLDAXIS\0BOUNDS\0HUD\0SDS\0HIGHLIGHTING\0MULTIAXIS\0OBJECTHANDLES\0HANDLEBANDS\0SDSCAGE\0NGONLINES\0JOINT\0OBJECTHIGHLIGHTING\0GUIDELINES\0POI\0GRADIENT\0BASEGRID\0HANDLES\0HAIR\0FIELD\0", DISPLAYFILTER_values, std::extent<decltype(DISPLAYFILTER_values)>::value};
}
const maxon::EnumInfo& PrivateGetEnumInfo_DISPLAYFILTER4389(){ return enum4389::DISPLAYFILTER_info; }
namespace enum4403
{
	enum class DISPLAYEDITSTATE
	{
		NONE			= 0,						///< None.
		SDS				= (1 << 0),			///< SDS edit state.
		DEFORM		= (1 << 1),			///< Deformed edit state.
	
		DOCUMENT	= -1			///< Document edit state.
	} ;
	static const maxon::UInt64 DISPLAYEDITSTATE_values[] = {maxon::UInt64(enum4403::DISPLAYEDITSTATE::NONE), maxon::UInt64(enum4403::DISPLAYEDITSTATE::SDS), maxon::UInt64(enum4403::DISPLAYEDITSTATE::DEFORM), maxon::UInt64(enum4403::DISPLAYEDITSTATE::DOCUMENT)};
	static const maxon::EnumInfo DISPLAYEDITSTATE_info{"DISPLAYEDITSTATE", SIZEOF(DISPLAYEDITSTATE), true, "NONE\0SDS\0DEFORM\0DOCUMENT\0", DISPLAYEDITSTATE_values, std::extent<decltype(DISPLAYEDITSTATE_values)>::value};
}
const maxon::EnumInfo& PrivateGetEnumInfo_DISPLAYEDITSTATE4403(){ return enum4403::DISPLAYEDITSTATE_info; }
namespace enum4415
{
	enum class THREADTYPE
	{
		NONE						= 0,						///< None.
		EDITORREDRAW		= (1 << 0),			///< Editor redraw.
		RENDEREDITOR		= (1 << 1),			///< Editor render.
		RENDEREXTERNAL	= (1 << 2)			///< External render.
	} ;
	static const maxon::UInt64 THREADTYPE_values[] = {maxon::UInt64(enum4415::THREADTYPE::NONE), maxon::UInt64(enum4415::THREADTYPE::EDITORREDRAW), maxon::UInt64(enum4415::THREADTYPE::RENDEREDITOR), maxon::UInt64(enum4415::THREADTYPE::RENDEREXTERNAL)};
	static const maxon::EnumInfo THREADTYPE_info{"THREADTYPE", SIZEOF(THREADTYPE), true, "NONE\0EDITORREDRAW\0RENDEREDITOR\0RENDEREXTERNAL\0", THREADTYPE_values, std::extent<decltype(THREADTYPE_values)>::value};
}
const maxon::EnumInfo& PrivateGetEnumInfo_THREADTYPE4415(){ return enum4415::THREADTYPE_info; }
namespace enum4429
{
	enum class RENDERPROGRESSTYPE
	{
		BEFORERENDERING			= 0,			///< Before rendering.
		DURINGRENDERING			= 1,			///< During rendering.
		AFTERRENDERING			= 2,			///< After rendering.
		GLOBALILLUMINATION	= 3,			///< GI prepass.
		QUICK_PREVIEW				= 4,			///< Quick Preview rendering. @since R17.048
		AMBIENTOCCLUSION		= 5				///< AO prepass. @since CR17.054 / R18.021
	} ;
	static const maxon::UInt64 RENDERPROGRESSTYPE_values[] = {maxon::UInt64(enum4429::RENDERPROGRESSTYPE::BEFORERENDERING), maxon::UInt64(enum4429::RENDERPROGRESSTYPE::DURINGRENDERING), maxon::UInt64(enum4429::RENDERPROGRESSTYPE::AFTERRENDERING), maxon::UInt64(enum4429::RENDERPROGRESSTYPE::GLOBALILLUMINATION), maxon::UInt64(enum4429::RENDERPROGRESSTYPE::QUICK_PREVIEW), maxon::UInt64(enum4429::RENDERPROGRESSTYPE::AMBIENTOCCLUSION)};
	static const maxon::EnumInfo RENDERPROGRESSTYPE_info{"RENDERPROGRESSTYPE", SIZEOF(RENDERPROGRESSTYPE), false, "BEFORERENDERING\0DURINGRENDERING\0AFTERRENDERING\0GLOBALILLUMINATION\0QUICK_PREVIEW\0AMBIENTOCCLUSION\0", RENDERPROGRESSTYPE_values, std::extent<decltype(RENDERPROGRESSTYPE_values)>::value};
}
const maxon::EnumInfo& PrivateGetEnumInfo_RENDERPROGRESSTYPE4429(){ return enum4429::RENDERPROGRESSTYPE_info; }
namespace enum4440
{
	enum class RDATA_SAVECALLBACK_CMD
	{
		OPEN	= 1,			///< Open call.
		WRITE	= 2,			///< Write call.
		CLOSE	= 3				///< Close call.
	} ;
	static const maxon::UInt64 RDATA_SAVECALLBACK_CMD_values[] = {maxon::UInt64(enum4440::RDATA_SAVECALLBACK_CMD::OPEN), maxon::UInt64(enum4440::RDATA_SAVECALLBACK_CMD::WRITE), maxon::UInt64(enum4440::RDATA_SAVECALLBACK_CMD::CLOSE)};
	static const maxon::EnumInfo RDATA_SAVECALLBACK_CMD_info{"RDATA_SAVECALLBACK_CMD", SIZEOF(RDATA_SAVECALLBACK_CMD), false, "OPEN\0WRITE\0CLOSE\0", RDATA_SAVECALLBACK_CMD_values, std::extent<decltype(RDATA_SAVECALLBACK_CMD_values)>::value};
}
const maxon::EnumInfo& PrivateGetEnumInfo_RDATA_SAVECALLBACK_CMD4440(){ return enum4440::RDATA_SAVECALLBACK_CMD_info; }
namespace enum4454
{
	enum class VPGETINFO
	{
		XRESOLUTION	= 0,			///< X resolution.
		YRESOLUTION	= 1,			///< Y resolution.
		BITDEPTH		= 2,			///< Bit depth.
		CPP					= 3,			///< Colors per pixel.
		VISIBLE			= 4,			///< Visibility.
		LINEOFFSET	= 5				///< Offset of component in line.
	} ;
	static const maxon::UInt64 VPGETINFO_values[] = {maxon::UInt64(enum4454::VPGETINFO::XRESOLUTION), maxon::UInt64(enum4454::VPGETINFO::YRESOLUTION), maxon::UInt64(enum4454::VPGETINFO::BITDEPTH), maxon::UInt64(enum4454::VPGETINFO::CPP), maxon::UInt64(enum4454::VPGETINFO::VISIBLE), maxon::UInt64(enum4454::VPGETINFO::LINEOFFSET)};
	static const maxon::EnumInfo VPGETINFO_info{"VPGETINFO", SIZEOF(VPGETINFO), false, "XRESOLUTION\0YRESOLUTION\0BITDEPTH\0CPP\0VISIBLE\0LINEOFFSET\0", VPGETINFO_values, std::extent<decltype(VPGETINFO_values)>::value};
}
const maxon::EnumInfo& PrivateGetEnumInfo_VPGETINFO4454(){ return enum4454::VPGETINFO_info; }
namespace enum4490
{
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
	} ;
	static const maxon::UInt64 DRAWOBJECT_values[] = {maxon::UInt64(enum4490::DRAWOBJECT::NONE), maxon::UInt64(enum4490::DRAWOBJECT::FORCELINES), maxon::UInt64(enum4490::DRAWOBJECT::NOBACKCULL), maxon::UInt64(enum4490::DRAWOBJECT::LOCALMATRIX), maxon::UInt64(enum4490::DRAWOBJECT::EDITMODE), maxon::UInt64(enum4490::DRAWOBJECT::FORCEBASE), maxon::UInt64(enum4490::DRAWOBJECT::FORCEPOINTS), maxon::UInt64(enum4490::DRAWOBJECT::NO_EOGL), maxon::UInt64(enum4490::DRAWOBJECT::USE_OBJECT_COLOR), maxon::UInt64(enum4490::DRAWOBJECT::USE_CUSTOM_COLOR), maxon::UInt64(enum4490::DRAWOBJECT::XRAY_ON), maxon::UInt64(enum4490::DRAWOBJECT::XRAY_OFF), maxon::UInt64(enum4490::DRAWOBJECT::IMMEDIATELY), maxon::UInt64(enum4490::DRAWOBJECT::Z_OFFSET), maxon::UInt64(enum4490::DRAWOBJECT::PRIVATE_ANY)};
	static const maxon::EnumInfo DRAWOBJECT_info{"DRAWOBJECT", SIZEOF(DRAWOBJECT), true, "NONE\0FORCELINES\0NOBACKCULL\0LOCALMATRIX\0EDITMODE\0FORCEBASE\0FORCEPOINTS\0NO_EOGL\0USE_OBJECT_COLOR\0USE_CUSTOM_COLOR\0XRAY_ON\0XRAY_OFF\0IMMEDIATELY\0Z_OFFSET\0PRIVATE_ANY\0", DRAWOBJECT_values, std::extent<decltype(DRAWOBJECT_values)>::value};
}
const maxon::EnumInfo& PrivateGetEnumInfo_DRAWOBJECT4490(){ return enum4490::DRAWOBJECT_info; }
namespace enum4516
{
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
	} ;
	static const maxon::UInt64 RENDERFLAGS_values[] = {maxon::UInt64(enum4516::RENDERFLAGS::NONE), maxon::UInt64(enum4516::RENDERFLAGS::EXTERNAL), maxon::UInt64(enum4516::RENDERFLAGS::NODOCUMENTCLONE), maxon::UInt64(enum4516::RENDERFLAGS::SHOWERRORS), maxon::UInt64(enum4516::RENDERFLAGS::PREVIEWRENDER), maxon::UInt64(enum4516::RENDERFLAGS::IRR), maxon::UInt64(enum4516::RENDERFLAGS::CREATE_PICTUREVIEWER), maxon::UInt64(enum4516::RENDERFLAGS::OPEN_PICTUREVIEWER), maxon::UInt64(enum4516::RENDERFLAGS::KEEP_CONTEXT), maxon::UInt64(enum4516::RENDERFLAGS::BATCHRENDER), maxon::UInt64(enum4516::RENDERFLAGS::NET), maxon::UInt64(enum4516::RENDERFLAGS::DONTANIMATE), maxon::UInt64(enum4516::RENDERFLAGS::PREVIEWSETTINGS), maxon::UInt64(enum4516::RENDERFLAGS::RENDERQUEUEERRORS), maxon::UInt64(enum4516::RENDERFLAGS::FORCE_LINEAR_COLOR_PROFILE), maxon::UInt64(enum4516::RENDERFLAGS::INTERNAL_USE_CURRENT_QUEUE), maxon::UInt64(enum4516::RENDERFLAGS::INTERNAL_SPECIAL_PREVIEW)};
	static const maxon::EnumInfo RENDERFLAGS_info{"RENDERFLAGS", SIZEOF(RENDERFLAGS), true, "NONE\0EXTERNAL\0NODOCUMENTCLONE\0SHOWERRORS\0PREVIEWRENDER\0IRR\0CREATE_PICTUREVIEWER\0OPEN_PICTUREVIEWER\0KEEP_CONTEXT\0BATCHRENDER\0NET\0DONTANIMATE\0PREVIEWSETTINGS\0RENDERQUEUEERRORS\0FORCE_LINEAR_COLOR_PROFILE\0INTERNAL_USE_CURRENT_QUEUE\0INTERNAL_SPECIAL_PREVIEW\0", RENDERFLAGS_values, std::extent<decltype(RENDERFLAGS_values)>::value};
}
const maxon::EnumInfo& PrivateGetEnumInfo_RENDERFLAGS4516(){ return enum4516::RENDERFLAGS_info; }
namespace enum4527
{
	enum class WRITEMODE
	{
		STANDARD							= 0,		///< Standard.
		ASSEMBLE_MOVIE				= 1,		///< Assemble movie.
		ASSEMBLE_SINGLEIMAGE	= 2			///< Assemble single image.
	} ;
	static const maxon::UInt64 WRITEMODE_values[] = {maxon::UInt64(enum4527::WRITEMODE::STANDARD), maxon::UInt64(enum4527::WRITEMODE::ASSEMBLE_MOVIE), maxon::UInt64(enum4527::WRITEMODE::ASSEMBLE_SINGLEIMAGE)};
	static const maxon::EnumInfo WRITEMODE_info{"WRITEMODE", SIZEOF(WRITEMODE), false, "STANDARD\0ASSEMBLE_MOVIE\0ASSEMBLE_SINGLEIMAGE\0", WRITEMODE_values, std::extent<decltype(WRITEMODE_values)>::value};
}
const maxon::EnumInfo& PrivateGetEnumInfo_WRITEMODE4527(){ return enum4527::WRITEMODE_info; }
namespace enum4547
{
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
	} ;
	static const maxon::UInt64 NETRENDERFLAGS_values[] = {maxon::UInt64(enum4547::NETRENDERFLAGS::NONE), maxon::UInt64(enum4547::NETRENDERFLAGS::OPEN_PICTUREVIEWER), maxon::UInt64(enum4547::NETRENDERFLAGS::SHOWERRORS), maxon::UInt64(enum4547::NETRENDERFLAGS::DELETEAFTERRENDERING), maxon::UInt64(enum4547::NETRENDERFLAGS::NOPEERTOPEERASSETDISTRIBUTION), maxon::UInt64(enum4547::NETRENDERFLAGS::NOREQUESTONDEMAND), maxon::UInt64(enum4547::NETRENDERFLAGS::EXCLUDECLIENTONLOADINGERROR), maxon::UInt64(enum4547::NETRENDERFLAGS::SAVERESULTSINREPOSITORY), maxon::UInt64(enum4547::NETRENDERFLAGS::ASSEMBLEB3DFILESIMMEDIATLEY), maxon::UInt64(enum4547::NETRENDERFLAGS::NOWRITETEST), maxon::UInt64(enum4547::NETRENDERFLAGS::HANDLEWARNINGASERROR), maxon::UInt64(enum4547::NETRENDERFLAGS::KEEPB3DFILESAFTERASSEMBLING)};
	static const maxon::EnumInfo NETRENDERFLAGS_info{"NETRENDERFLAGS", SIZEOF(NETRENDERFLAGS), true, "NONE\0OPEN_PICTUREVIEWER\0SHOWERRORS\0DELETEAFTERRENDERING\0NOPEERTOPEERASSETDISTRIBUTION\0NOREQUESTONDEMAND\0EXCLUDECLIENTONLOADINGERROR\0SAVERESULTSINREPOSITORY\0ASSEMBLEB3DFILESIMMEDIATLEY\0NOWRITETEST\0HANDLEWARNINGASERROR\0KEEPB3DFILESAFTERASSEMBLING\0", NETRENDERFLAGS_values, std::extent<decltype(NETRENDERFLAGS_values)>::value};
}
const maxon::EnumInfo& PrivateGetEnumInfo_NETRENDERFLAGS4547(){ return enum4547::NETRENDERFLAGS_info; }
namespace enum4564
{
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
	} ;
	static const maxon::UInt64 CHECKISRUNNING_values[] = {maxon::UInt64(enum4564::CHECKISRUNNING::ANIMATIONRUNNING), maxon::UInt64(enum4564::CHECKISRUNNING::VIEWDRAWING), maxon::UInt64(enum4564::CHECKISRUNNING::EDITORRENDERING), maxon::UInt64(enum4564::CHECKISRUNNING::EXTERNALRENDERING), maxon::UInt64(enum4564::CHECKISRUNNING::PAINTERUPDATING), maxon::UInt64(enum4564::CHECKISRUNNING::MATERIALPREVIEWRUNNING), maxon::UInt64(enum4564::CHECKISRUNNING::EVENTSYSTEM), maxon::UInt64(enum4564::CHECKISRUNNING::BAKING), maxon::UInt64(enum4564::CHECKISRUNNING::INTERACTIVERENDERING)};
	static const maxon::EnumInfo CHECKISRUNNING_info{"CHECKISRUNNING", SIZEOF(CHECKISRUNNING), false, "ANIMATIONRUNNING\0VIEWDRAWING\0EDITORRENDERING\0EXTERNALRENDERING\0PAINTERUPDATING\0MATERIALPREVIEWRUNNING\0EVENTSYSTEM\0BAKING\0INTERACTIVERENDERING\0", CHECKISRUNNING_values, std::extent<decltype(CHECKISRUNNING_values)>::value};
}
const maxon::EnumInfo& PrivateGetEnumInfo_CHECKISRUNNING4564(){ return enum4564::CHECKISRUNNING_info; }
namespace enum4584
{
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
	} ;
	static const maxon::UInt64 BAKE_TEX_ERR_values[] = {maxon::UInt64(enum4584::BAKE_TEX_ERR::NONE), maxon::UInt64(enum4584::BAKE_TEX_ERR::NO_DOC), maxon::UInt64(enum4584::BAKE_TEX_ERR::NO_MEM), maxon::UInt64(enum4584::BAKE_TEX_ERR::NO_RENDER_DOC), maxon::UInt64(enum4584::BAKE_TEX_ERR::NO_TEXTURE_TAG), maxon::UInt64(enum4584::BAKE_TEX_ERR::NO_OBJECT), maxon::UInt64(enum4584::BAKE_TEX_ERR::NO_UVW_TAG), maxon::UInt64(enum4584::BAKE_TEX_ERR::TEXTURE_MISSING), maxon::UInt64(enum4584::BAKE_TEX_ERR::WRONG_BITMAP), maxon::UInt64(enum4584::BAKE_TEX_ERR::USERBREAK), maxon::UInt64(enum4584::BAKE_TEX_ERR::NO_OPTIMAL_MAPPING), maxon::UInt64(enum4584::BAKE_TEX_ERR::NO_SOURCE_UVW_TAG)};
	static const maxon::EnumInfo BAKE_TEX_ERR_info{"BAKE_TEX_ERR", SIZEOF(BAKE_TEX_ERR), false, "NONE\0NO_DOC\0NO_MEM\0NO_RENDER_DOC\0NO_TEXTURE_TAG\0NO_OBJECT\0NO_UVW_TAG\0TEXTURE_MISSING\0WRONG_BITMAP\0USERBREAK\0NO_OPTIMAL_MAPPING\0NO_SOURCE_UVW_TAG\0", BAKE_TEX_ERR_values, std::extent<decltype(BAKE_TEX_ERR_values)>::value};
}
const maxon::EnumInfo& PrivateGetEnumInfo_BAKE_TEX_ERR4584(){ return enum4584::BAKE_TEX_ERR_info; }
namespace enum4595
{
	enum class GL_MESSAGE
	{
		OK							= 1,
		ERROR_					= 0,
		FORCE_EMULATION	= 2
	} ;
	static const maxon::UInt64 GL_MESSAGE_values[] = {maxon::UInt64(enum4595::GL_MESSAGE::OK), maxon::UInt64(enum4595::GL_MESSAGE::ERROR_), maxon::UInt64(enum4595::GL_MESSAGE::FORCE_EMULATION)};
	static const maxon::EnumInfo GL_MESSAGE_info{"GL_MESSAGE", SIZEOF(GL_MESSAGE), false, "OK\0ERROR_\0FORCE_EMULATION\0", GL_MESSAGE_values, std::extent<decltype(GL_MESSAGE_values)>::value};
}
const maxon::EnumInfo& PrivateGetEnumInfo_GL_MESSAGE4595(){ return enum4595::GL_MESSAGE_info; }
namespace enum4612
{
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
	} ;
	static const maxon::UInt64 VIEWPORT_PICK_FLAGS_values[] = {maxon::UInt64(enum4612::VIEWPORT_PICK_FLAGS::NONE), maxon::UInt64(enum4612::VIEWPORT_PICK_FLAGS::ALLOW_OGL), maxon::UInt64(enum4612::VIEWPORT_PICK_FLAGS::DONT_STOP_THREADS), maxon::UInt64(enum4612::VIEWPORT_PICK_FLAGS::USE_SEL_FILTER), maxon::UInt64(enum4612::VIEWPORT_PICK_FLAGS::OGL_ONLY_TOPMOST), maxon::UInt64(enum4612::VIEWPORT_PICK_FLAGS::OGL_ONLY_VISIBLE), maxon::UInt64(enum4612::VIEWPORT_PICK_FLAGS::OGL_IGNORE_Z), maxon::UInt64(enum4612::VIEWPORT_PICK_FLAGS::OGL_ONLY_TOPMOST_WITH_OBJ), maxon::UInt64(enum4612::VIEWPORT_PICK_FLAGS::NO_DEPTH_CORRECTION)};
	static const maxon::EnumInfo VIEWPORT_PICK_FLAGS_info{"VIEWPORT_PICK_FLAGS", SIZEOF(VIEWPORT_PICK_FLAGS), true, "NONE\0ALLOW_OGL\0DONT_STOP_THREADS\0USE_SEL_FILTER\0OGL_ONLY_TOPMOST\0OGL_ONLY_VISIBLE\0OGL_IGNORE_Z\0OGL_ONLY_TOPMOST_WITH_OBJ\0NO_DEPTH_CORRECTION\0", VIEWPORT_PICK_FLAGS_values, std::extent<decltype(VIEWPORT_PICK_FLAGS_values)>::value};
}
const maxon::EnumInfo& PrivateGetEnumInfo_VIEWPORT_PICK_FLAGS4612(){ return enum4612::VIEWPORT_PICK_FLAGS_info; }
namespace enum4652
{
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
	} ;
	static const maxon::UInt64 BACKGROUNDHANDLERCOMMAND_values[] = {maxon::UInt64(enum4652::BACKGROUNDHANDLERCOMMAND::ISRUNNING), maxon::UInt64(enum4652::BACKGROUNDHANDLERCOMMAND::STOP), maxon::UInt64(enum4652::BACKGROUNDHANDLERCOMMAND::START), maxon::UInt64(enum4652::BACKGROUNDHANDLERCOMMAND::REMOVE)};
	static const maxon::EnumInfo BACKGROUNDHANDLERCOMMAND_info{"BACKGROUNDHANDLERCOMMAND", SIZEOF(BACKGROUNDHANDLERCOMMAND), false, "ISRUNNING\0STOP\0START\0REMOVE\0", BACKGROUNDHANDLERCOMMAND_values, std::extent<decltype(BACKGROUNDHANDLERCOMMAND_values)>::value};
}
const maxon::EnumInfo& PrivateGetEnumInfo_BACKGROUNDHANDLERCOMMAND4652(){ return enum4652::BACKGROUNDHANDLERCOMMAND_info; }
namespace enum4678
{
	enum class BACKGROUNDHANDLERFLAGS
	{
		NONE								= 0,						///< None.
		VIEWREDRAW					= (1 << 0),			///< View redraw.
		EDITORRENDDER				= (1 << 1),			///< Editor render.
		MATERIALPREVIEW			= (1 << 2),			///< %Material preview.
		RENDEREXTERNAL			= (1 << 3),			///< %Render external.
		PRIVATE_VIEWREDRAW	= (1 << 4),			///< @markPrivate
	
		SHUTDOWN						= -1						///< Shutdown.
	} ;
	static const maxon::UInt64 BACKGROUNDHANDLERFLAGS_values[] = {maxon::UInt64(enum4678::BACKGROUNDHANDLERFLAGS::NONE), maxon::UInt64(enum4678::BACKGROUNDHANDLERFLAGS::VIEWREDRAW), maxon::UInt64(enum4678::BACKGROUNDHANDLERFLAGS::EDITORRENDDER), maxon::UInt64(enum4678::BACKGROUNDHANDLERFLAGS::MATERIALPREVIEW), maxon::UInt64(enum4678::BACKGROUNDHANDLERFLAGS::RENDEREXTERNAL), maxon::UInt64(enum4678::BACKGROUNDHANDLERFLAGS::PRIVATE_VIEWREDRAW), maxon::UInt64(enum4678::BACKGROUNDHANDLERFLAGS::SHUTDOWN)};
	static const maxon::EnumInfo BACKGROUNDHANDLERFLAGS_info{"BACKGROUNDHANDLERFLAGS", SIZEOF(BACKGROUNDHANDLERFLAGS), true, "NONE\0VIEWREDRAW\0EDITORRENDDER\0MATERIALPREVIEW\0RENDEREXTERNAL\0PRIVATE_VIEWREDRAW\0SHUTDOWN\0", BACKGROUNDHANDLERFLAGS_values, std::extent<decltype(BACKGROUNDHANDLERFLAGS_values)>::value};
}
const maxon::EnumInfo& PrivateGetEnumInfo_BACKGROUNDHANDLERFLAGS4678(){ return enum4678::BACKGROUNDHANDLERFLAGS_info; }
namespace enum4701
{
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
		PYTHON				= (1 << 8)			///< Python file.
	} ;
	static const maxon::UInt64 IDENTIFYFILE_values[] = {maxon::UInt64(enum4701::IDENTIFYFILE::NONE), maxon::UInt64(enum4701::IDENTIFYFILE::SCENE), maxon::UInt64(enum4701::IDENTIFYFILE::IMAGE), maxon::UInt64(enum4701::IDENTIFYFILE::MOVIE), maxon::UInt64(enum4701::IDENTIFYFILE::SKIPQUICKTIME), maxon::UInt64(enum4701::IDENTIFYFILE::SCRIPT), maxon::UInt64(enum4701::IDENTIFYFILE::SOUND), maxon::UInt64(enum4701::IDENTIFYFILE::LAYOUT), maxon::UInt64(enum4701::IDENTIFYFILE::PYTHON)};
	static const maxon::EnumInfo IDENTIFYFILE_info{"IDENTIFYFILE", SIZEOF(IDENTIFYFILE), true, "NONE\0SCENE\0IMAGE\0MOVIE\0SKIPQUICKTIME\0SCRIPT\0SOUND\0LAYOUT\0PYTHON\0", IDENTIFYFILE_values, std::extent<decltype(IDENTIFYFILE_values)>::value};
}
const maxon::EnumInfo& PrivateGetEnumInfo_IDENTIFYFILE4701(){ return enum4701::IDENTIFYFILE_info; }
namespace enum4713
{
	enum class CALCHARDSHADOW
	{
		NONE							= 0,							///< None.
		TRANSPARENCY			= (1 << 0),				///< Transparencies/alphas for in-between objects will be evaluated.
		SPECIALGISHADOW		= (1 << 29),			///< @markPrivate
		SPECIALSELFSHADOW	= (1 << 30)				///< @markPrivate
	} ;
	static const maxon::UInt64 CALCHARDSHADOW_values[] = {maxon::UInt64(enum4713::CALCHARDSHADOW::NONE), maxon::UInt64(enum4713::CALCHARDSHADOW::TRANSPARENCY), maxon::UInt64(enum4713::CALCHARDSHADOW::SPECIALGISHADOW), maxon::UInt64(enum4713::CALCHARDSHADOW::SPECIALSELFSHADOW)};
	static const maxon::EnumInfo CALCHARDSHADOW_info{"CALCHARDSHADOW", SIZEOF(CALCHARDSHADOW), true, "NONE\0TRANSPARENCY\0SPECIALGISHADOW\0SPECIALSELFSHADOW\0", CALCHARDSHADOW_values, std::extent<decltype(CALCHARDSHADOW_values)>::value};
}
const maxon::EnumInfo& PrivateGetEnumInfo_CALCHARDSHADOW4713(){ return enum4713::CALCHARDSHADOW_info; }
namespace enum4731
{
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
	} ;
	static const maxon::UInt64 ILLUMINATEFLAGS_values[] = {maxon::UInt64(enum4731::ILLUMINATEFLAGS::NONE), maxon::UInt64(enum4731::ILLUMINATEFLAGS::SHADOW), maxon::UInt64(enum4731::ILLUMINATEFLAGS::NOENVIRONMENT), maxon::UInt64(enum4731::ILLUMINATEFLAGS::DISABLESHADOWMAP_CORRECTION), maxon::UInt64(enum4731::ILLUMINATEFLAGS::DISABLESHADOWCASTERMP_CORRECTION), maxon::UInt64(enum4731::ILLUMINATEFLAGS::LIGHTDIRNORMALS), maxon::UInt64(enum4731::ILLUMINATEFLAGS::NODISTANCEFALLOFF), maxon::UInt64(enum4731::ILLUMINATEFLAGS::NOGRAIN), maxon::UInt64(enum4731::ILLUMINATEFLAGS::BACKLIGHT)};
	static const maxon::EnumInfo ILLUMINATEFLAGS_info{"ILLUMINATEFLAGS", SIZEOF(ILLUMINATEFLAGS), true, "NONE\0SHADOW\0NOENVIRONMENT\0DISABLESHADOWMAP_CORRECTION\0DISABLESHADOWCASTERMP_CORRECTION\0LIGHTDIRNORMALS\0NODISTANCEFALLOFF\0NOGRAIN\0BACKLIGHT\0", ILLUMINATEFLAGS_values, std::extent<decltype(ILLUMINATEFLAGS_values)>::value};
}
const maxon::EnumInfo& PrivateGetEnumInfo_ILLUMINATEFLAGS4731(){ return enum4731::ILLUMINATEFLAGS_info; }
namespace enum4759
{
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
	} ;
	static const maxon::UInt64 RAYBIT_values[] = {maxon::UInt64(enum4759::RAYBIT::NONE), maxon::UInt64(enum4759::RAYBIT::REFLECTION), maxon::UInt64(enum4759::RAYBIT::TRANSPARENCY), maxon::UInt64(enum4759::RAYBIT::REFRACTION), maxon::UInt64(enum4759::RAYBIT::CUSTOM), maxon::UInt64(enum4759::RAYBIT::CURR_REFLECTION), maxon::UInt64(enum4759::RAYBIT::CURR_TRANSPARENCY), maxon::UInt64(enum4759::RAYBIT::CURR_REFRACTION), maxon::UInt64(enum4759::RAYBIT::CURR_CUSTOM), maxon::UInt64(enum4759::RAYBIT::VOLUMETRICLIGHT), maxon::UInt64(enum4759::RAYBIT::ALLOWVLMIX), maxon::UInt64(enum4759::RAYBIT::GI), maxon::UInt64(enum4759::RAYBIT::BLURRY), maxon::UInt64(enum4759::RAYBIT::SSS), maxon::UInt64(enum4759::RAYBIT::AO), maxon::UInt64(enum4759::RAYBIT::COMPOSITING)};
	static const maxon::EnumInfo RAYBIT_info{"RAYBIT", SIZEOF(RAYBIT), true, "NONE\0REFLECTION\0TRANSPARENCY\0REFRACTION\0CUSTOM\0CURR_REFLECTION\0CURR_TRANSPARENCY\0CURR_REFRACTION\0CURR_CUSTOM\0VOLUMETRICLIGHT\0ALLOWVLMIX\0GI\0BLURRY\0SSS\0AO\0COMPOSITING\0", RAYBIT_values, std::extent<decltype(RAYBIT_values)>::value};
}
const maxon::EnumInfo& PrivateGetEnumInfo_RAYBIT4759(){ return enum4759::RAYBIT_info; }
namespace enum4783
{
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
	} ;
	static const maxon::UInt64 VOLUMEINFO_values[] = {maxon::UInt64(enum4783::VOLUMEINFO::NONE), maxon::UInt64(enum4783::VOLUMEINFO::REFLECTION), maxon::UInt64(enum4783::VOLUMEINFO::TRANSPARENCY), maxon::UInt64(enum4783::VOLUMEINFO::ALPHA), maxon::UInt64(enum4783::VOLUMEINFO::CHANGENORMAL), maxon::UInt64(enum4783::VOLUMEINFO::DISPLACEMENT), maxon::UInt64(enum4783::VOLUMEINFO::ENVREQUIRED), maxon::UInt64(enum4783::VOLUMEINFO::DUDVREQUIRED), maxon::UInt64(enum4783::VOLUMEINFO::MIPSAT), maxon::UInt64(enum4783::VOLUMEINFO::VOLUMETRIC), maxon::UInt64(enum4783::VOLUMEINFO::TRANSFORM), maxon::UInt64(enum4783::VOLUMEINFO::EVALUATEPROJECTION), maxon::UInt64(enum4783::VOLUMEINFO::PRIVATE_GLOW), maxon::UInt64(enum4783::VOLUMEINFO::INITCALCULATION), maxon::UInt64(enum4783::VOLUMEINFO::FINAL_ALPHA), maxon::UInt64(enum4783::VOLUMEINFO::ISNBMMATERIAL)};
	static const maxon::EnumInfo VOLUMEINFO_info{"VOLUMEINFO", SIZEOF(VOLUMEINFO), true, "NONE\0REFLECTION\0TRANSPARENCY\0ALPHA\0CHANGENORMAL\0DISPLACEMENT\0ENVREQUIRED\0DUDVREQUIRED\0MIPSAT\0VOLUMETRIC\0TRANSFORM\0EVALUATEPROJECTION\0PRIVATE_GLOW\0INITCALCULATION\0FINAL_ALPHA\0ISNBMMATERIAL\0", VOLUMEINFO_values, std::extent<decltype(VOLUMEINFO_values)>::value};
}
const maxon::EnumInfo& PrivateGetEnumInfo_VOLUMEINFO4783(){ return enum4783::VOLUMEINFO_info; }
namespace enum4808
{
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
	} ;
	static const maxon::UInt64 VIDEOPOSTINFO_values[] = {maxon::UInt64(enum4808::VIDEOPOSTINFO::NONE), maxon::UInt64(enum4808::VIDEOPOSTINFO::STOREFRAGMENTS), maxon::UInt64(enum4808::VIDEOPOSTINFO::EXECUTELINE), maxon::UInt64(enum4808::VIDEOPOSTINFO::EXECUTEPIXEL), maxon::UInt64(enum4808::VIDEOPOSTINFO::REQUEST_MOTIONMATRIX), maxon::UInt64(enum4808::VIDEOPOSTINFO::REQUEST_MOTIONGEOMETRY), maxon::UInt64(enum4808::VIDEOPOSTINFO::CALCVOLUMETRIC), maxon::UInt64(enum4808::VIDEOPOSTINFO::CALCSHADOW), maxon::UInt64(enum4808::VIDEOPOSTINFO::CUSTOMLENS), maxon::UInt64(enum4808::VIDEOPOSTINFO::GLOBALILLUMINATION), maxon::UInt64(enum4808::VIDEOPOSTINFO::CAUSTICS), maxon::UInt64(enum4808::VIDEOPOSTINFO::CUSTOMLENS_EXTENDED), maxon::UInt64(enum4808::VIDEOPOSTINFO::NETFRAME), maxon::UInt64(enum4808::VIDEOPOSTINFO::NETRUNONSERVER), maxon::UInt64(enum4808::VIDEOPOSTINFO::NETCREATEBUFFER), maxon::UInt64(enum4808::VIDEOPOSTINFO::NETCREATEBUFFER_MULTI), maxon::UInt64(enum4808::VIDEOPOSTINFO::REQUEST_MOTIONFULL)};
	static const maxon::EnumInfo VIDEOPOSTINFO_info{"VIDEOPOSTINFO", SIZEOF(VIDEOPOSTINFO), true, "NONE\0STOREFRAGMENTS\0EXECUTELINE\0EXECUTEPIXEL\0REQUEST_MOTIONMATRIX\0REQUEST_MOTIONGEOMETRY\0CALCVOLUMETRIC\0CALCSHADOW\0CUSTOMLENS\0GLOBALILLUMINATION\0CAUSTICS\0CUSTOMLENS_EXTENDED\0NETFRAME\0NETRUNONSERVER\0NETCREATEBUFFER\0NETCREATEBUFFER_MULTI\0REQUEST_MOTIONFULL\0", VIDEOPOSTINFO_values, std::extent<decltype(VIDEOPOSTINFO_values)>::value};
}
const maxon::EnumInfo& PrivateGetEnumInfo_VIDEOPOSTINFO4808(){ return enum4808::VIDEOPOSTINFO_info; }
namespace enum4825
{
	enum class SHADERINFO
	{
		NONE							= 0,							///< None.
		TRANSFORM					= 0x00000004,			///< Channel needs back-transformed data. (Required for BaseVolumeData::back_p.)
		BUMP_SUPPORT			= 0x00000010,			///< Channel shader supports the new bump system. This is strongly recommended for all shaders except simple 2D (UV) samplers.
		ALPHA_SUPPORT			= 0x00000020,			///< Channel shader supports alpha output.
		REFLECTIONS				= 0x00000040,			///< Channel shader computes reflections.
		DUDVREQUIRED			= 0x00000080,			///< Channel shader needs du/dv bump mapping data. See BaseVolumeData::ddu and BaseVolumeData::ddv.
		DYNAMICSUBSHADERS	= 0x00000100,			///< Channel shader has a dynamic list of sub-shaders in its description.
		TRANSPARENCIES		= 0x00000200			///< Deprecated, not used anymore.
	} ;
	static const maxon::UInt64 SHADERINFO_values[] = {maxon::UInt64(enum4825::SHADERINFO::NONE), maxon::UInt64(enum4825::SHADERINFO::TRANSFORM), maxon::UInt64(enum4825::SHADERINFO::BUMP_SUPPORT), maxon::UInt64(enum4825::SHADERINFO::ALPHA_SUPPORT), maxon::UInt64(enum4825::SHADERINFO::REFLECTIONS), maxon::UInt64(enum4825::SHADERINFO::DUDVREQUIRED), maxon::UInt64(enum4825::SHADERINFO::DYNAMICSUBSHADERS), maxon::UInt64(enum4825::SHADERINFO::TRANSPARENCIES)};
	static const maxon::EnumInfo SHADERINFO_info{"SHADERINFO", SIZEOF(SHADERINFO), true, "NONE\0TRANSFORM\0BUMP_SUPPORT\0ALPHA_SUPPORT\0REFLECTIONS\0DUDVREQUIRED\0DYNAMICSUBSHADERS\0TRANSPARENCIES\0", SHADERINFO_values, std::extent<decltype(SHADERINFO_values)>::value};
}
const maxon::EnumInfo& PrivateGetEnumInfo_SHADERINFO4825(){ return enum4825::SHADERINFO_info; }
namespace enum4836
{
	enum class SAMPLEBUMP
	{
		NONE				= 0,						///< None.
		MIPFALLOFF	= (1 << 0)			///< Additional bump change over distance is considered.
	} ;
	static const maxon::UInt64 SAMPLEBUMP_values[] = {maxon::UInt64(enum4836::SAMPLEBUMP::NONE), maxon::UInt64(enum4836::SAMPLEBUMP::MIPFALLOFF)};
	static const maxon::EnumInfo SAMPLEBUMP_info{"SAMPLEBUMP", SIZEOF(SAMPLEBUMP), true, "NONE\0MIPFALLOFF\0", SAMPLEBUMP_values, std::extent<decltype(SAMPLEBUMP_values)>::value};
}
const maxon::EnumInfo& PrivateGetEnumInfo_SAMPLEBUMP4836(){ return enum4836::SAMPLEBUMP_info; }
namespace enum4849
{
	enum class INITCALCULATION
	{
		SURFACE				= 0,			///< Called during rendering for surface calculation.
		TRANSPARENCY	= 1,			///< Called during rendering for shadow rays computation.
		DISPLACEMENT	= 3				///< Called before rendering for displace calculation.
	} ;
	static const maxon::UInt64 INITCALCULATION_values[] = {maxon::UInt64(enum4849::INITCALCULATION::SURFACE), maxon::UInt64(enum4849::INITCALCULATION::TRANSPARENCY), maxon::UInt64(enum4849::INITCALCULATION::DISPLACEMENT)};
	static const maxon::EnumInfo INITCALCULATION_info{"INITCALCULATION", SIZEOF(INITCALCULATION), false, "SURFACE\0TRANSPARENCY\0DISPLACEMENT\0", INITCALCULATION_values, std::extent<decltype(INITCALCULATION_values)>::value};
}
const maxon::EnumInfo& PrivateGetEnumInfo_INITCALCULATION4849(){ return enum4849::INITCALCULATION_info; }
namespace enum4870
{
	enum class FIELDLAYER_FLAG
	{
		NONE										= 0,						///< Default state
		SKIP										= (1 << 0),			///< Layer calculation is disabled, e.g. the linked object on a standard layer's deform mode is false.
		ERRORSKIP								= (1 << 1),			///< Layer calculation is disabled due to a non critical error in InitializeSampling or as user specified in GetFieldLayerFlags.
		HIDE										= (1 << 2),			///< Layer should be completely ignored from both calculation and GUI display, e.g. the linked object has been deleted.
		MODIFYDATA							= (1 << 3),			///< The layer modifies existing data and needs the values from layers beneath it in the layerlist in the "results" array inside of Sample.
		PRESERVEALPHA						= (1 << 4),			///< The layer doesn't adjust the existing alpha and it's color changes should be applied ignoring any alpha values.
		NOCHILDVALUE						= (1 << 5),			///< Children of this layer wont output their value.
		NOCHILDCOLOR						= (1 << 6),			///< Children of this layer wont output their color.
		NOCHILDDIRECTION				= (1 << 7),			///< Children of this layer wont output their direction.
		TEMPORARY								= (1 << 8),			///< Don't save this layer with the list or duplicate it (outside of undo)
		NOCHILDROTATION					= (1 << 9)			///< Children of this layer wont output their direction.
	} ;
	static const maxon::UInt64 FIELDLAYER_FLAG_values[] = {maxon::UInt64(enum4870::FIELDLAYER_FLAG::NONE), maxon::UInt64(enum4870::FIELDLAYER_FLAG::SKIP), maxon::UInt64(enum4870::FIELDLAYER_FLAG::ERRORSKIP), maxon::UInt64(enum4870::FIELDLAYER_FLAG::HIDE), maxon::UInt64(enum4870::FIELDLAYER_FLAG::MODIFYDATA), maxon::UInt64(enum4870::FIELDLAYER_FLAG::PRESERVEALPHA), maxon::UInt64(enum4870::FIELDLAYER_FLAG::NOCHILDVALUE), maxon::UInt64(enum4870::FIELDLAYER_FLAG::NOCHILDCOLOR), maxon::UInt64(enum4870::FIELDLAYER_FLAG::NOCHILDDIRECTION), maxon::UInt64(enum4870::FIELDLAYER_FLAG::TEMPORARY), maxon::UInt64(enum4870::FIELDLAYER_FLAG::NOCHILDROTATION)};
	static const maxon::EnumInfo FIELDLAYER_FLAG_info{"FIELDLAYER_FLAG", SIZEOF(FIELDLAYER_FLAG), true, "NONE\0SKIP\0ERRORSKIP\0HIDE\0MODIFYDATA\0PRESERVEALPHA\0NOCHILDVALUE\0NOCHILDCOLOR\0NOCHILDDIRECTION\0TEMPORARY\0NOCHILDROTATION\0", FIELDLAYER_FLAG_values, std::extent<decltype(FIELDLAYER_FLAG_values)>::value};
}
const maxon::EnumInfo& PrivateGetEnumInfo_FIELDLAYER_FLAG4870(){ return enum4870::FIELDLAYER_FLAG_info; }
namespace enum4981
{
	enum class MULTIPASSCHANNEL
	{
		NONE						= 0,						///< None.
		IMAGELAYER			= (1 << 0),			///< Image layer.
		MATERIALCHANNEL	= (1 << 1)			///< %Material channel.
	} ;
	static const maxon::UInt64 MULTIPASSCHANNEL_values[] = {maxon::UInt64(enum4981::MULTIPASSCHANNEL::NONE), maxon::UInt64(enum4981::MULTIPASSCHANNEL::IMAGELAYER), maxon::UInt64(enum4981::MULTIPASSCHANNEL::MATERIALCHANNEL)};
	static const maxon::EnumInfo MULTIPASSCHANNEL_info{"MULTIPASSCHANNEL", SIZEOF(MULTIPASSCHANNEL), false, "NONE\0IMAGELAYER\0MATERIALCHANNEL\0", MULTIPASSCHANNEL_values, std::extent<decltype(MULTIPASSCHANNEL_values)>::value};
}
const maxon::EnumInfo& PrivateGetEnumInfo_MULTIPASSCHANNEL4981(){ return enum4981::MULTIPASSCHANNEL_info; }
namespace enum5001
{
	enum class DLG_TYPE
	{
		MODAL = 10,											///< Modal dialog.
		MODAL_RESIZEABLE,								///< Resizable modal dialog.
	
		ASYNC = 20,											///< Non-modal (asynchronous) dialog.
		ASYNC_POPUP_RESIZEABLE,					///< Non-modal (asynchronous) dialog. Resizable popup dialog style (no menu bar).
		ASYNC_POPUPEDIT,								///< Non-modal (asynchronous) dialog. Popup dialog style (no menu bar, no window frame).
		ASYNC_TOOLBAR,									///< Non-modal (asynchronous) dialog. Toolbar style with no minimize/maximize buttons, but close button
	
		ASYNC_FULLSCREEN_WORK = 30,			///< Non-modal (asynchronous) dialog. Fullscreen over desktop area.
		ASYNC_FULLSCREEN_MONITOR,				///< Non-modal (asynchronous) dialog. Fullscreen over the whole monitor area.
	
		DUMMY
	} ;
	static const maxon::UInt64 DLG_TYPE_values[] = {maxon::UInt64(enum5001::DLG_TYPE::MODAL), maxon::UInt64(enum5001::DLG_TYPE::MODAL_RESIZEABLE), maxon::UInt64(enum5001::DLG_TYPE::ASYNC), maxon::UInt64(enum5001::DLG_TYPE::ASYNC_POPUP_RESIZEABLE), maxon::UInt64(enum5001::DLG_TYPE::ASYNC_POPUPEDIT), maxon::UInt64(enum5001::DLG_TYPE::ASYNC_TOOLBAR), maxon::UInt64(enum5001::DLG_TYPE::ASYNC_FULLSCREEN_WORK), maxon::UInt64(enum5001::DLG_TYPE::ASYNC_FULLSCREEN_MONITOR), maxon::UInt64(enum5001::DLG_TYPE::DUMMY)};
	static const maxon::EnumInfo DLG_TYPE_info{"DLG_TYPE", SIZEOF(DLG_TYPE), false, "MODAL\0MODAL_RESIZEABLE\0ASYNC\0ASYNC_POPUP_RESIZEABLE\0ASYNC_POPUPEDIT\0ASYNC_TOOLBAR\0ASYNC_FULLSCREEN_WORK\0ASYNC_FULLSCREEN_MONITOR\0DUMMY\0", DLG_TYPE_values, std::extent<decltype(DLG_TYPE_values)>::value};
}
const maxon::EnumInfo& PrivateGetEnumInfo_DLG_TYPE5001(){ return enum5001::DLG_TYPE_info; }
namespace enum5014
{
	enum class MULTIMSG_ROUTE
	{
		NONE				= 0,			///< None.
		UP					= 1,			///< Send to parents.
		ROOT				= 2,			///< Send to root object.
		DOWN				= 3,			///< Send to children.
		BROADCAST		= 4				///< Broadcast the message, i.e. distribute it to all branches given by GeListNode::GetBranchInfo.
	} ;
	static const maxon::UInt64 MULTIMSG_ROUTE_values[] = {maxon::UInt64(enum5014::MULTIMSG_ROUTE::NONE), maxon::UInt64(enum5014::MULTIMSG_ROUTE::UP), maxon::UInt64(enum5014::MULTIMSG_ROUTE::ROOT), maxon::UInt64(enum5014::MULTIMSG_ROUTE::DOWN), maxon::UInt64(enum5014::MULTIMSG_ROUTE::BROADCAST)};
	static const maxon::EnumInfo MULTIMSG_ROUTE_info{"MULTIMSG_ROUTE", SIZEOF(MULTIMSG_ROUTE), false, "NONE\0UP\0ROOT\0DOWN\0BROADCAST\0", MULTIMSG_ROUTE_values, std::extent<decltype(MULTIMSG_ROUTE_values)>::value};
}
const maxon::EnumInfo& PrivateGetEnumInfo_MULTIMSG_ROUTE5014(){ return enum5014::MULTIMSG_ROUTE_info; }
namespace enum5025
{
	enum class VPGETFRAGMENTS
	{
		NONE	= 0,						///< None.
		Z_P		= (1 << 0),			///< Get VPFragment::z and VPFragment::p.
		N			= (1 << 1)			///< Get VPFragment::n.
	} ;
	static const maxon::UInt64 VPGETFRAGMENTS_values[] = {maxon::UInt64(enum5025::VPGETFRAGMENTS::NONE), maxon::UInt64(enum5025::VPGETFRAGMENTS::Z_P), maxon::UInt64(enum5025::VPGETFRAGMENTS::N)};
	static const maxon::EnumInfo VPGETFRAGMENTS_info{"VPGETFRAGMENTS", SIZEOF(VPGETFRAGMENTS), true, "NONE\0Z_P\0N\0", VPGETFRAGMENTS_values, std::extent<decltype(VPGETFRAGMENTS_values)>::value};
}
const maxon::EnumInfo& PrivateGetEnumInfo_VPGETFRAGMENTS5025(){ return enum5025::VPGETFRAGMENTS_info; }
namespace enum5053
{
	enum class NAV2DCAMERASETTINGSCACHEMODE
	{
		REVERT = 0,
		STOREIFIN2D = 1,
		STOREIFIN2DANDNOTALREADYSTORED = 2,
		FORCESTORE = 3,
		RET_CHANGED = 1000,
		RET_NOCHANGE = 1001,
		INVALID = 99999
	} ;
	static const maxon::UInt64 NAV2DCAMERASETTINGSCACHEMODE_values[] = {maxon::UInt64(enum5053::NAV2DCAMERASETTINGSCACHEMODE::REVERT), maxon::UInt64(enum5053::NAV2DCAMERASETTINGSCACHEMODE::STOREIFIN2D), maxon::UInt64(enum5053::NAV2DCAMERASETTINGSCACHEMODE::STOREIFIN2DANDNOTALREADYSTORED), maxon::UInt64(enum5053::NAV2DCAMERASETTINGSCACHEMODE::FORCESTORE), maxon::UInt64(enum5053::NAV2DCAMERASETTINGSCACHEMODE::RET_CHANGED), maxon::UInt64(enum5053::NAV2DCAMERASETTINGSCACHEMODE::RET_NOCHANGE), maxon::UInt64(enum5053::NAV2DCAMERASETTINGSCACHEMODE::INVALID)};
	static const maxon::EnumInfo NAV2DCAMERASETTINGSCACHEMODE_info{"NAV2DCAMERASETTINGSCACHEMODE", SIZEOF(NAV2DCAMERASETTINGSCACHEMODE), false, "REVERT\0STOREIFIN2D\0STOREIFIN2DANDNOTALREADYSTORED\0FORCESTORE\0RET_CHANGED\0RET_NOCHANGE\0INVALID\0", NAV2DCAMERASETTINGSCACHEMODE_values, std::extent<decltype(NAV2DCAMERASETTINGSCACHEMODE_values)>::value};
}
const maxon::EnumInfo& PrivateGetEnumInfo_NAV2DCAMERASETTINGSCACHEMODE5053(){ return enum5053::NAV2DCAMERASETTINGSCACHEMODE_info; }
namespace enum5065
{
	enum class SIGNALMODE
	{
		// V_ unfortunately has to be used here due to conflicts with MAC OS
		V_DEFAULT		= 0,			///< Default mode.
		V_RESERVED	= 1				///< Reserved.
	} ;
	static const maxon::UInt64 SIGNALMODE_values[] = {maxon::UInt64(enum5065::SIGNALMODE::V_DEFAULT), maxon::UInt64(enum5065::SIGNALMODE::V_RESERVED)};
	static const maxon::EnumInfo SIGNALMODE_info{"SIGNALMODE", SIZEOF(SIGNALMODE), false, "V_DEFAULT\0V_RESERVED\0", SIGNALMODE_values, std::extent<decltype(SIGNALMODE_values)>::value};
}
const maxon::EnumInfo& PrivateGetEnumInfo_SIGNALMODE5065(){ return enum5065::SIGNALMODE_info; }
namespace enum5079
{
	enum class QUALIFIER
	{
		NONE			= 0,						///< None.
		SHIFT			= (1 << 0),			///< @em SHIFT key.
		CTRL			= (1 << 1),			///< @em CTRL key.
		ALT				= (1 << 2),			///< @em ALT key.
		MOUSEHIT	= (1 << 10)			///< Indication in ObjectData::DetectHandle that the user pressed the mouse (ObjectData::DetectHandle is also called for cursor information, when hovering over a handle).\n
															///< For instance if @ref QUALIFIER::MOUSEHIT and @ref QUALIFIER::CTRL are set, ObjectData::DetectHandle could create a new element.
	} ;
	static const maxon::UInt64 QUALIFIER_values[] = {maxon::UInt64(enum5079::QUALIFIER::NONE), maxon::UInt64(enum5079::QUALIFIER::SHIFT), maxon::UInt64(enum5079::QUALIFIER::CTRL), maxon::UInt64(enum5079::QUALIFIER::ALT), maxon::UInt64(enum5079::QUALIFIER::MOUSEHIT)};
	static const maxon::EnumInfo QUALIFIER_info{"QUALIFIER", SIZEOF(QUALIFIER), true, "NONE\0SHIFT\0CTRL\0ALT\0MOUSEHIT\0", QUALIFIER_values, std::extent<decltype(QUALIFIER_values)>::value};
}
const maxon::EnumInfo& PrivateGetEnumInfo_QUALIFIER5079(){ return enum5079::QUALIFIER_info; }
namespace enum5294
{
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
	} ;
	static const maxon::UInt64 NOTIFY_EVENT_values[] = {maxon::UInt64(enum5294::NOTIFY_EVENT::NONE), maxon::UInt64(enum5294::NOTIFY_EVENT::ALL), maxon::UInt64(enum5294::NOTIFY_EVENT::ANY), maxon::UInt64(enum5294::NOTIFY_EVENT::PRE_DEFORM), maxon::UInt64(enum5294::NOTIFY_EVENT::POST_DEFORM), maxon::UInt64(enum5294::NOTIFY_EVENT::UNDO), maxon::UInt64(enum5294::NOTIFY_EVENT::MESSAGE), maxon::UInt64(enum5294::NOTIFY_EVENT::FREE), maxon::UInt64(enum5294::NOTIFY_EVENT::COPY), maxon::UInt64(enum5294::NOTIFY_EVENT::CACHE), maxon::UInt64(enum5294::NOTIFY_EVENT::REMOVE), maxon::UInt64(enum5294::NOTIFY_EVENT::CLONE), maxon::UInt64(enum5294::NOTIFY_EVENT::INSERT), maxon::UInt64(enum5294::NOTIFY_EVENT::SELECTIONBIT), maxon::UInt64(enum5294::NOTIFY_EVENT::HIGHLIGHTBIT), maxon::UInt64(enum5294::NOTIFY_EVENT::SETNAME)};
	static const maxon::EnumInfo NOTIFY_EVENT_info{"NOTIFY_EVENT", SIZEOF(NOTIFY_EVENT), false, "NONE\0ALL\0ANY\0PRE_DEFORM\0POST_DEFORM\0UNDO\0MESSAGE\0FREE\0COPY\0CACHE\0REMOVE\0CLONE\0INSERT\0SELECTIONBIT\0HIGHLIGHTBIT\0SETNAME\0", NOTIFY_EVENT_values, std::extent<decltype(NOTIFY_EVENT_values)>::value};
}
const maxon::EnumInfo& PrivateGetEnumInfo_NOTIFY_EVENT5294(){ return enum5294::NOTIFY_EVENT_info; }
namespace enum5312
{
	enum class NOTIFY_EVENT_FLAG
	{
		REMOVED					= (1 << 0),
	
		COPY_UNDO				= (1 << 10),
		COPY_CACHE			= (1 << 11),
		COPY_DUPLICATE	= (1 << 12),
		ONCE						= (1 << 13),
		COPY						= ((1 << 10) | (1 << 11) | (1 << 12)),
	
		NONE						= 0
	} ;
	static const maxon::UInt64 NOTIFY_EVENT_FLAG_values[] = {maxon::UInt64(enum5312::NOTIFY_EVENT_FLAG::REMOVED), maxon::UInt64(enum5312::NOTIFY_EVENT_FLAG::COPY_UNDO), maxon::UInt64(enum5312::NOTIFY_EVENT_FLAG::COPY_CACHE), maxon::UInt64(enum5312::NOTIFY_EVENT_FLAG::COPY_DUPLICATE), maxon::UInt64(enum5312::NOTIFY_EVENT_FLAG::ONCE), maxon::UInt64(enum5312::NOTIFY_EVENT_FLAG::COPY), maxon::UInt64(enum5312::NOTIFY_EVENT_FLAG::NONE)};
	static const maxon::EnumInfo NOTIFY_EVENT_FLAG_info{"NOTIFY_EVENT_FLAG", SIZEOF(NOTIFY_EVENT_FLAG), true, "REMOVED\0COPY_UNDO\0COPY_CACHE\0COPY_DUPLICATE\0ONCE\0COPY\0NONE\0", NOTIFY_EVENT_FLAG_values, std::extent<decltype(NOTIFY_EVENT_FLAG_values)>::value};
}
const maxon::EnumInfo& PrivateGetEnumInfo_NOTIFY_EVENT_FLAG5312(){ return enum5312::NOTIFY_EVENT_FLAG_info; }
namespace enum5325
{
	enum class DESCIDSTATE
	{
		NONE						= 0,					///< None.
		LOCKED					= 1 << 0,			///< Description element is locked.
		HIDDEN					= 1 << 1,			///< Description element is hidden.
		OVERRIDE				= 1 << 2,			///< Description is overridden. @since R17.032
		FORBIDOVERRIDE	= 1 << 3			///< Description cannot be overridden. @since R17.032
	} ;
	static const maxon::UInt64 DESCIDSTATE_values[] = {maxon::UInt64(enum5325::DESCIDSTATE::NONE), maxon::UInt64(enum5325::DESCIDSTATE::LOCKED), maxon::UInt64(enum5325::DESCIDSTATE::HIDDEN), maxon::UInt64(enum5325::DESCIDSTATE::OVERRIDE), maxon::UInt64(enum5325::DESCIDSTATE::FORBIDOVERRIDE)};
	static const maxon::EnumInfo DESCIDSTATE_info{"DESCIDSTATE", SIZEOF(DESCIDSTATE), true, "NONE\0LOCKED\0HIDDEN\0OVERRIDE\0FORBIDOVERRIDE\0", DESCIDSTATE_values, std::extent<decltype(DESCIDSTATE_values)>::value};
}
const maxon::EnumInfo& PrivateGetEnumInfo_DESCIDSTATE5325(){ return enum5325::DESCIDSTATE_info; }
namespace enum5336
{
	enum class BASEDRAW_HOOK_MESSAGE
	{
		ADAPTVIEW					= 1,			///< The user clicked on "Adapt View" menu.
		SET_SCENE_CAMERA	= 2,			///< The user changed the scene camera. The corresponding data is BDSetSceneCameraMsg.
		DELETEBASEDRAW		= 3				///< The base draw is deleted.
	} ;
	static const maxon::UInt64 BASEDRAW_HOOK_MESSAGE_values[] = {maxon::UInt64(enum5336::BASEDRAW_HOOK_MESSAGE::ADAPTVIEW), maxon::UInt64(enum5336::BASEDRAW_HOOK_MESSAGE::SET_SCENE_CAMERA), maxon::UInt64(enum5336::BASEDRAW_HOOK_MESSAGE::DELETEBASEDRAW)};
	static const maxon::EnumInfo BASEDRAW_HOOK_MESSAGE_info{"BASEDRAW_HOOK_MESSAGE", SIZEOF(BASEDRAW_HOOK_MESSAGE), false, "ADAPTVIEW\0SET_SCENE_CAMERA\0DELETEBASEDRAW\0", BASEDRAW_HOOK_MESSAGE_values, std::extent<decltype(BASEDRAW_HOOK_MESSAGE_values)>::value};
}
const maxon::EnumInfo& PrivateGetEnumInfo_BASEDRAW_HOOK_MESSAGE5336(){ return enum5336::BASEDRAW_HOOK_MESSAGE_info; }
namespace enum5353
{
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
	} ;
	static const maxon::UInt64 CINEMAINFO_values[] = {maxon::UInt64(enum5353::CINEMAINFO::TABLETT), maxon::UInt64(enum5353::CINEMAINFO::OPENGL), maxon::UInt64(enum5353::CINEMAINFO::TABLETT_HIRES), maxon::UInt64(enum5353::CINEMAINFO::FORBID_GUI), maxon::UInt64(enum5353::CINEMAINFO::MINIMAL_VIEWPORT), maxon::UInt64(enum5353::CINEMAINFO::LISTEN), maxon::UInt64(enum5353::CINEMAINFO::WATCH_PID), maxon::UInt64(enum5353::CINEMAINFO::SETFOREGROUND), maxon::UInt64(enum5353::CINEMAINFO::FORCEDIALOG)};
	static const maxon::EnumInfo CINEMAINFO_info{"CINEMAINFO", SIZEOF(CINEMAINFO), true, "TABLETT\0OPENGL\0TABLETT_HIRES\0FORBID_GUI\0MINIMAL_VIEWPORT\0LISTEN\0WATCH_PID\0SETFOREGROUND\0FORCEDIALOG\0", CINEMAINFO_values, std::extent<decltype(CINEMAINFO_values)>::value};
}
const maxon::EnumInfo& PrivateGetEnumInfo_CINEMAINFO5353(){ return enum5353::CINEMAINFO_info; }
namespace enum5364
{
	enum class PROTOCOL
	{
		ZERO	= 0,				///< None.
		IPV4	= 1000,			///< IPv4.
		IPV6							///< IPv6.
	} ;
	static const maxon::UInt64 PROTOCOL_values[] = {maxon::UInt64(enum5364::PROTOCOL::ZERO), maxon::UInt64(enum5364::PROTOCOL::IPV4), maxon::UInt64(enum5364::PROTOCOL::IPV6)};
	static const maxon::EnumInfo PROTOCOL_info{"PROTOCOL", SIZEOF(PROTOCOL), false, "ZERO\0IPV4\0IPV6\0", PROTOCOL_values, std::extent<decltype(PROTOCOL_values)>::value};
}
const maxon::EnumInfo& PrivateGetEnumInfo_PROTOCOL5364(){ return enum5364::PROTOCOL_info; }
namespace enum5375
{
	enum class RESOLVERESULT
	{
		OK				= 0,			///< Ok.
		UNKNOWN		= 1,			///< Unknown error while resolving address.
	} ;
	static const maxon::UInt64 RESOLVERESULT_values[] = {maxon::UInt64(enum5375::RESOLVERESULT::OK), maxon::UInt64(enum5375::RESOLVERESULT::UNKNOWN)};
	static const maxon::EnumInfo RESOLVERESULT_info{"RESOLVERESULT", SIZEOF(RESOLVERESULT), false, "OK\0UNKNOWN\0", RESOLVERESULT_values, std::extent<decltype(RESOLVERESULT_values)>::value};
}
const maxon::EnumInfo& PrivateGetEnumInfo_RESOLVERESULT5375(){ return enum5375::RESOLVERESULT_info; }
namespace enum5387
{
	enum class SERVERJOBLIST
	{
		INACTIVE = 1000,			///<
		ACTIVE,								///<
		DOWNLOAD,							///<
		ALL										///<
	} ;
	static const maxon::UInt64 SERVERJOBLIST_values[] = {maxon::UInt64(enum5387::SERVERJOBLIST::INACTIVE), maxon::UInt64(enum5387::SERVERJOBLIST::ACTIVE), maxon::UInt64(enum5387::SERVERJOBLIST::DOWNLOAD), maxon::UInt64(enum5387::SERVERJOBLIST::ALL)};
	static const maxon::EnumInfo SERVERJOBLIST_info{"SERVERJOBLIST", SIZEOF(SERVERJOBLIST), false, "INACTIVE\0ACTIVE\0DOWNLOAD\0ALL\0", SERVERJOBLIST_values, std::extent<decltype(SERVERJOBLIST_values)>::value};
}
const maxon::EnumInfo& PrivateGetEnumInfo_SERVERJOBLIST5387(){ return enum5387::SERVERJOBLIST_info; }
namespace enum5399
{
	enum class EDITION
	{
		C4D				= (1 << 0),									///< @C4D
		NETCLIENT	= (1 << 1),									///< NET client.
		NETSERVER	= (1 << 2),									///< NET server.
		NET				= (1 << 1) | (1 << 2),			///< NET.
	} ;
	static const maxon::UInt64 EDITION_values[] = {maxon::UInt64(enum5399::EDITION::C4D), maxon::UInt64(enum5399::EDITION::NETCLIENT), maxon::UInt64(enum5399::EDITION::NETSERVER), maxon::UInt64(enum5399::EDITION::NET)};
	static const maxon::EnumInfo EDITION_info{"EDITION", SIZEOF(EDITION), true, "C4D\0NETCLIENT\0NETSERVER\0NET\0", EDITION_values, std::extent<decltype(EDITION_values)>::value};
}
const maxon::EnumInfo& PrivateGetEnumInfo_EDITION5399(){ return enum5399::EDITION_info; }
namespace enum5416
{
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
	} ;
	static const maxon::UInt64 JOBCOMMAND_values[] = {maxon::UInt64(enum5416::JOBCOMMAND::NONE), maxon::UInt64(enum5416::JOBCOMMAND::FETCHJOB), maxon::UInt64(enum5416::JOBCOMMAND::ALLOCATESPACE), maxon::UInt64(enum5416::JOBCOMMAND::DOWNLOAD), maxon::UInt64(enum5416::JOBCOMMAND::RENDER), maxon::UInt64(enum5416::JOBCOMMAND::DELETE_), maxon::UInt64(enum5416::JOBCOMMAND::STOPANDDELETE), maxon::UInt64(enum5416::JOBCOMMAND::ASSEMBLE), maxon::UInt64(enum5416::JOBCOMMAND::END)};
	static const maxon::EnumInfo JOBCOMMAND_info{"JOBCOMMAND", SIZEOF(JOBCOMMAND), false, "NONE\0FETCHJOB\0ALLOCATESPACE\0DOWNLOAD\0RENDER\0DELETE_\0STOPANDDELETE\0ASSEMBLE\0END\0", JOBCOMMAND_values, std::extent<decltype(JOBCOMMAND_values)>::value};
}
const maxon::EnumInfo& PrivateGetEnumInfo_JOBCOMMAND5416(){ return enum5416::JOBCOMMAND_info; }
namespace enum5427
{
	enum class RENDERTARGET
	{
		ALL = 1000,	///< Use all machines.
		SPECIFIED,		///< C4DUuid.
		MINMAX				///< Minimum/maximum. <i>1000</i>:min <i>1001</i>:max
	} ;
	static const maxon::UInt64 RENDERTARGET_values[] = {maxon::UInt64(enum5427::RENDERTARGET::ALL), maxon::UInt64(enum5427::RENDERTARGET::SPECIFIED), maxon::UInt64(enum5427::RENDERTARGET::MINMAX)};
	static const maxon::EnumInfo RENDERTARGET_info{"RENDERTARGET", SIZEOF(RENDERTARGET), false, "ALL\0SPECIFIED\0MINMAX\0", RENDERTARGET_values, std::extent<decltype(RENDERTARGET_values)>::value};
}
const maxon::EnumInfo& PrivateGetEnumInfo_RENDERTARGET5427(){ return enum5427::RENDERTARGET_info; }
namespace enum5463
{
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
	} ;
	static const maxon::UInt64 JOBSTATE_values[] = {maxon::UInt64(enum5463::JOBSTATE::IDLE), maxon::UInt64(enum5463::JOBSTATE::PREPARING_RUNNING), maxon::UInt64(enum5463::JOBSTATE::PREPARING_FAILED), maxon::UInt64(enum5463::JOBSTATE::PREPARING_OK), maxon::UInt64(enum5463::JOBSTATE::RENDER_RUNNING), maxon::UInt64(enum5463::JOBSTATE::TE_RENDER_PAUSED), maxon::UInt64(enum5463::JOBSTATE::RENDER_OK), maxon::UInt64(enum5463::JOBSTATE::RENDER_FAILED), maxon::UInt64(enum5463::JOBSTATE::ALLOCATESPACE_RUNNING), maxon::UInt64(enum5463::JOBSTATE::ALLOCATESPACE_OK), maxon::UInt64(enum5463::JOBSTATE::ALLOCATESPACE_FAILED), maxon::UInt64(enum5463::JOBSTATE::DOWNLOAD_RUNNING), maxon::UInt64(enum5463::JOBSTATE::DOWNLOAD_OK), maxon::UInt64(enum5463::JOBSTATE::DOWNLOAD_FAILED), maxon::UInt64(enum5463::JOBSTATE::ASSEMBLE_RUNNING), maxon::UInt64(enum5463::JOBSTATE::ASSEMBLE_OK), maxon::UInt64(enum5463::JOBSTATE::ASSEMBLE_FAILED), maxon::UInt64(enum5463::JOBSTATE::STOPPED), maxon::UInt64(enum5463::JOBSTATE::QUEUED), maxon::UInt64(enum5463::JOBSTATE::PENDING), maxon::UInt64(enum5463::JOBSTATE::QUEUED_WAITING), maxon::UInt64(enum5463::JOBSTATE::ASSEMBLE_PENDING)};
	static const maxon::EnumInfo JOBSTATE_info{"JOBSTATE", SIZEOF(JOBSTATE), false, "IDLE\0PREPARING_RUNNING\0PREPARING_FAILED\0PREPARING_OK\0RENDER_RUNNING\0TE_RENDER_PAUSED\0RENDER_OK\0RENDER_FAILED\0ALLOCATESPACE_RUNNING\0ALLOCATESPACE_OK\0ALLOCATESPACE_FAILED\0DOWNLOAD_RUNNING\0DOWNLOAD_OK\0DOWNLOAD_FAILED\0ASSEMBLE_RUNNING\0ASSEMBLE_OK\0ASSEMBLE_FAILED\0STOPPED\0QUEUED\0PENDING\0QUEUED_WAITING\0ASSEMBLE_PENDING\0", JOBSTATE_values, std::extent<decltype(JOBSTATE_values)>::value};
}
const maxon::EnumInfo& PrivateGetEnumInfo_JOBSTATE5463(){ return enum5463::JOBSTATE_info; }
namespace enum5475
{
	enum class ZEROCONFMACHINESTATE
	{
		ONLINE		= 1,			///< Online.
		OFFLINE	= 2,			///< Offline.
		REMOVED	= 3,			///< Removed.
		UPDATE		= 4,			///< Update.
	} ;
	static const maxon::UInt64 ZEROCONFMACHINESTATE_values[] = {maxon::UInt64(enum5475::ZEROCONFMACHINESTATE::ONLINE), maxon::UInt64(enum5475::ZEROCONFMACHINESTATE::OFFLINE), maxon::UInt64(enum5475::ZEROCONFMACHINESTATE::REMOVED), maxon::UInt64(enum5475::ZEROCONFMACHINESTATE::UPDATE)};
	static const maxon::EnumInfo ZEROCONFMACHINESTATE_info{"ZEROCONFMACHINESTATE", SIZEOF(ZEROCONFMACHINESTATE), false, "ONLINE\0OFFLINE\0REMOVED\0UPDATE\0", ZEROCONFMACHINESTATE_values, std::extent<decltype(ZEROCONFMACHINESTATE_values)>::value};
}
const maxon::EnumInfo& PrivateGetEnumInfo_ZEROCONFMACHINESTATE5475(){ return enum5475::ZEROCONFMACHINESTATE_info; }
namespace enum5486
{
	enum class ZEROCONFACTION
	{
		NONE		= 0,						///< None.
		RESOLVE	= (1 << 0),			///< Resolve.
		MONITOR	= (1 << 1)			///< Monitor.
	} ;
	static const maxon::UInt64 ZEROCONFACTION_values[] = {maxon::UInt64(enum5486::ZEROCONFACTION::NONE), maxon::UInt64(enum5486::ZEROCONFACTION::RESOLVE), maxon::UInt64(enum5486::ZEROCONFACTION::MONITOR)};
	static const maxon::EnumInfo ZEROCONFACTION_info{"ZEROCONFACTION", SIZEOF(ZEROCONFACTION), true, "NONE\0RESOLVE\0MONITOR\0", ZEROCONFACTION_values, std::extent<decltype(ZEROCONFACTION_values)>::value};
}
const maxon::EnumInfo& PrivateGetEnumInfo_ZEROCONFACTION5486(){ return enum5486::ZEROCONFACTION_info; }
namespace enum5525
{
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
	} ;
	static const maxon::UInt64 ZEROCONFERROR_values[] = {maxon::UInt64(enum5525::ZEROCONFERROR::OK), maxon::UInt64(enum5525::ZEROCONFERROR::UNKNOWN), maxon::UInt64(enum5525::ZEROCONFERROR::NOSUCHNAME), maxon::UInt64(enum5525::ZEROCONFERROR::NOMEMORY), maxon::UInt64(enum5525::ZEROCONFERROR::BADPARAM), maxon::UInt64(enum5525::ZEROCONFERROR::BADREFERENCE), maxon::UInt64(enum5525::ZEROCONFERROR::BADSTATE), maxon::UInt64(enum5525::ZEROCONFERROR::BADFLAGS), maxon::UInt64(enum5525::ZEROCONFERROR::UNSUPPORTED), maxon::UInt64(enum5525::ZEROCONFERROR::NOTINITIALIZED), maxon::UInt64(enum5525::ZEROCONFERROR::ALREADYREGISTERED), maxon::UInt64(enum5525::ZEROCONFERROR::NAMECONFLICT), maxon::UInt64(enum5525::ZEROCONFERROR::INVALID), maxon::UInt64(enum5525::ZEROCONFERROR::FIREWALL), maxon::UInt64(enum5525::ZEROCONFERROR::INCOMPATIBLE), maxon::UInt64(enum5525::ZEROCONFERROR::BADINTERFACEINDEX), maxon::UInt64(enum5525::ZEROCONFERROR::REFUSED), maxon::UInt64(enum5525::ZEROCONFERROR::NOSUCHRECORD), maxon::UInt64(enum5525::ZEROCONFERROR::NOAUTH), maxon::UInt64(enum5525::ZEROCONFERROR::NOSUCHKEY), maxon::UInt64(enum5525::ZEROCONFERROR::NATTRAVERSAL), maxon::UInt64(enum5525::ZEROCONFERROR::DOUBLENAT), maxon::UInt64(enum5525::ZEROCONFERROR::BADTIME), maxon::UInt64(enum5525::ZEROCONFERROR::BADSIGNAL), maxon::UInt64(enum5525::ZEROCONFERROR::BADKEY), maxon::UInt64(enum5525::ZEROCONFERROR::TRANSIENT), maxon::UInt64(enum5525::ZEROCONFERROR::SERVICENOTRUNNING), maxon::UInt64(enum5525::ZEROCONFERROR::NATPORTMAPPINGUNSUPPORTED), maxon::UInt64(enum5525::ZEROCONFERROR::NATPORTMAPPINGDISABLED), maxon::UInt64(enum5525::ZEROCONFERROR::NOROUTER), maxon::UInt64(enum5525::ZEROCONFERROR::POLLINGMODE)};
	static const maxon::EnumInfo ZEROCONFERROR_info{"ZEROCONFERROR", SIZEOF(ZEROCONFERROR), false, "OK\0UNKNOWN\0NOSUCHNAME\0NOMEMORY\0BADPARAM\0BADREFERENCE\0BADSTATE\0BADFLAGS\0UNSUPPORTED\0NOTINITIALIZED\0ALREADYREGISTERED\0NAMECONFLICT\0INVALID\0FIREWALL\0INCOMPATIBLE\0BADINTERFACEINDEX\0REFUSED\0NOSUCHRECORD\0NOAUTH\0NOSUCHKEY\0NATTRAVERSAL\0DOUBLENAT\0BADTIME\0BADSIGNAL\0BADKEY\0TRANSIENT\0SERVICENOTRUNNING\0NATPORTMAPPINGUNSUPPORTED\0NATPORTMAPPINGDISABLED\0NOROUTER\0POLLINGMODE\0", ZEROCONFERROR_values, std::extent<decltype(ZEROCONFERROR_values)>::value};
}
const maxon::EnumInfo& PrivateGetEnumInfo_ZEROCONFERROR5525(){ return enum5525::ZEROCONFERROR_info; }
namespace enum5555
{
	enum class COMPONENT_SELECTION_MODES
	{
		POINTS				= 0,								 ///< Points selection mode.
		EDGES					= 1,								 ///< Edges selection mode.
		POLYGONS			= 2,								 ///< Polygons selection mode.
		UVPOINTS			= 3,								 ///< UV Points selection mode.
		UVPOLYGONS		= 4,								 ///< UV Polygons selection mode.
		CURRENT				= 5,								 ///< Current component selection mode.
		UVEDGES				= 6									 ///< UV Edges selection mode. @since R22
	} ;
	static const maxon::UInt64 COMPONENT_SELECTION_MODES_values[] = {maxon::UInt64(enum5555::COMPONENT_SELECTION_MODES::POINTS), maxon::UInt64(enum5555::COMPONENT_SELECTION_MODES::EDGES), maxon::UInt64(enum5555::COMPONENT_SELECTION_MODES::POLYGONS), maxon::UInt64(enum5555::COMPONENT_SELECTION_MODES::UVPOINTS), maxon::UInt64(enum5555::COMPONENT_SELECTION_MODES::UVPOLYGONS), maxon::UInt64(enum5555::COMPONENT_SELECTION_MODES::CURRENT), maxon::UInt64(enum5555::COMPONENT_SELECTION_MODES::UVEDGES)};
	static const maxon::EnumInfo COMPONENT_SELECTION_MODES_info{"COMPONENT_SELECTION_MODES", SIZEOF(COMPONENT_SELECTION_MODES), false, "POINTS\0EDGES\0POLYGONS\0UVPOINTS\0UVPOLYGONS\0CURRENT\0UVEDGES\0", COMPONENT_SELECTION_MODES_values, std::extent<decltype(COMPONENT_SELECTION_MODES_values)>::value};
}
const maxon::EnumInfo& PrivateGetEnumInfo_COMPONENT_SELECTION_MODES5555(){ return enum5555::COMPONENT_SELECTION_MODES_info; }
namespace enum5569
{
	enum class FIELDSAMPLE_FLAG
	{
		VALUE			= 0,														///< Sample only the value at the current point (minimum must still sample the value)
		DIRECTION	= (1 << 0),											///< Sample the velocity at the current point
		COLOR			= (1 << 1),											///< Sample the color at the current point
		ROTATION	= (1 << 2),											///< Sample the rotational velocity at the current point
		ALL				= VALUE | DIRECTION | COLOR,		///< Sample all channels at the current point minus rotation
		NONLINEARCOLOR	= (1 << 3)								///< Deliver the color in non-linear sRGB colorspace (see Document Linear Color Workflow settings)
	} ;
	static const maxon::UInt64 FIELDSAMPLE_FLAG_values[] = {maxon::UInt64(enum5569::FIELDSAMPLE_FLAG::VALUE), maxon::UInt64(enum5569::FIELDSAMPLE_FLAG::DIRECTION), maxon::UInt64(enum5569::FIELDSAMPLE_FLAG::COLOR), maxon::UInt64(enum5569::FIELDSAMPLE_FLAG::ROTATION), maxon::UInt64(enum5569::FIELDSAMPLE_FLAG::ALL), maxon::UInt64(enum5569::FIELDSAMPLE_FLAG::NONLINEARCOLOR)};
	static const maxon::EnumInfo FIELDSAMPLE_FLAG_info{"FIELDSAMPLE_FLAG", SIZEOF(FIELDSAMPLE_FLAG), true, "VALUE\0DIRECTION\0COLOR\0ROTATION\0ALL\0NONLINEARCOLOR\0", FIELDSAMPLE_FLAG_values, std::extent<decltype(FIELDSAMPLE_FLAG_values)>::value};
}
const maxon::EnumInfo& PrivateGetEnumInfo_FIELDSAMPLE_FLAG5569(){ return enum5569::FIELDSAMPLE_FLAG_info; }
namespace enum5579
{
	enum class FIELDOBJECTSAMPLE_FLAG
	{
		NONE										= 0,						///< No flags
		DISABLEDIRECTIONFALLOFF = (1 << 0)			///< @Markprivate Disables remapping the direction magnitude by the value parameter in order that fieldlayers may use that to blend instead in normal mode
	} ;
	static const maxon::UInt64 FIELDOBJECTSAMPLE_FLAG_values[] = {maxon::UInt64(enum5579::FIELDOBJECTSAMPLE_FLAG::NONE), maxon::UInt64(enum5579::FIELDOBJECTSAMPLE_FLAG::DISABLEDIRECTIONFALLOFF)};
	static const maxon::EnumInfo FIELDOBJECTSAMPLE_FLAG_info{"FIELDOBJECTSAMPLE_FLAG", SIZEOF(FIELDOBJECTSAMPLE_FLAG), true, "NONE\0DISABLEDIRECTIONFALLOFF\0", FIELDOBJECTSAMPLE_FLAG_values, std::extent<decltype(FIELDOBJECTSAMPLE_FLAG_values)>::value};
}
const maxon::EnumInfo& PrivateGetEnumInfo_FIELDOBJECTSAMPLE_FLAG5579(){ return enum5579::FIELDOBJECTSAMPLE_FLAG_info; }
namespace enum5593
{
	enum class FIELDOBJECT_FLAG
	{
		NONE											= 0,								///< No flags
		INLINE										= (1 << 0),					///< Field calculates using the current values of the field stack.
		GENERATINGCOLOR						= (1 << 1),					///< The Field is currently outputting color.
		PRESERVEALPHA							= (1 << 2),					///< The Field doesn't modify alpha, any color it produces is directly applied to the existing color ignoring the alpha blending.
		SKIP											= (1 << 3),					///< The Field should be skipped.
		ERRORSKIP									= (1 << 4)					///< The Field is currently experiencing an error.
	} ;
	static const maxon::UInt64 FIELDOBJECT_FLAG_values[] = {maxon::UInt64(enum5593::FIELDOBJECT_FLAG::NONE), maxon::UInt64(enum5593::FIELDOBJECT_FLAG::INLINE), maxon::UInt64(enum5593::FIELDOBJECT_FLAG::GENERATINGCOLOR), maxon::UInt64(enum5593::FIELDOBJECT_FLAG::PRESERVEALPHA), maxon::UInt64(enum5593::FIELDOBJECT_FLAG::SKIP), maxon::UInt64(enum5593::FIELDOBJECT_FLAG::ERRORSKIP)};
	static const maxon::EnumInfo FIELDOBJECT_FLAG_info{"FIELDOBJECT_FLAG", SIZEOF(FIELDOBJECT_FLAG), true, "NONE\0INLINE\0GENERATINGCOLOR\0PRESERVEALPHA\0SKIP\0ERRORSKIP\0", FIELDOBJECT_FLAG_values, std::extent<decltype(FIELDOBJECT_FLAG_values)>::value};
}
const maxon::EnumInfo& PrivateGetEnumInfo_FIELDOBJECT_FLAG5593(){ return enum5593::FIELDOBJECT_FLAG_info; }
namespace enum5605
{
	enum class VIEWPORT_RENDER_ID
	{
		RENDER_OBJECT = 0,	///< Return the Id of the render object.
		DATA_SETTER = 1			///< Return the Id of the data setter.
	} ;
	static const maxon::UInt64 VIEWPORT_RENDER_ID_values[] = {maxon::UInt64(enum5605::VIEWPORT_RENDER_ID::RENDER_OBJECT), maxon::UInt64(enum5605::VIEWPORT_RENDER_ID::DATA_SETTER)};
	static const maxon::EnumInfo VIEWPORT_RENDER_ID_info{"VIEWPORT_RENDER_ID", SIZEOF(VIEWPORT_RENDER_ID), false, "RENDER_OBJECT\0DATA_SETTER\0", VIEWPORT_RENDER_ID_values, std::extent<decltype(VIEWPORT_RENDER_ID_values)>::value};
}
const maxon::EnumInfo& PrivateGetEnumInfo_VIEWPORT_RENDER_ID5605(){ return enum5605::VIEWPORT_RENDER_ID_info; }
namespace enum5623
{
	enum class GETALLASSETSRESULT
	{
		FAILED		= 0,		///< Function call went wrong.
		OK				= 1,		///< Function succeeded and all assets exists.
		MISSING		= 2			///< Function succeeded but some assets cannot be found.
	} ;
	static const maxon::UInt64 GETALLASSETSRESULT_values[] = {maxon::UInt64(enum5623::GETALLASSETSRESULT::FAILED), maxon::UInt64(enum5623::GETALLASSETSRESULT::OK), maxon::UInt64(enum5623::GETALLASSETSRESULT::MISSING)};
	static const maxon::EnumInfo GETALLASSETSRESULT_info{"GETALLASSETSRESULT", SIZEOF(GETALLASSETSRESULT), false, "FAILED\0OK\0MISSING\0", GETALLASSETSRESULT_values, std::extent<decltype(GETALLASSETSRESULT_values)>::value};
}
const maxon::EnumInfo& PrivateGetEnumInfo_GETALLASSETSRESULT5623(){ return enum5623::GETALLASSETSRESULT_info; }
namespace enum5635
{
	enum class VIEWPORTTYPE
	{
		NONE			= 0,		///< No viewport is active.
		MAIN_VIEW = 1,		///< Main 3D viewport is active.
		UV_VIEW		= 2			///< UV viewport is active.
	} ;
	static const maxon::UInt64 VIEWPORTTYPE_values[] = {maxon::UInt64(enum5635::VIEWPORTTYPE::NONE), maxon::UInt64(enum5635::VIEWPORTTYPE::MAIN_VIEW), maxon::UInt64(enum5635::VIEWPORTTYPE::UV_VIEW)};
	static const maxon::EnumInfo VIEWPORTTYPE_info{"VIEWPORTTYPE", SIZEOF(VIEWPORTTYPE), false, "NONE\0MAIN_VIEW\0UV_VIEW\0", VIEWPORTTYPE_values, std::extent<decltype(VIEWPORTTYPE_values)>::value};
}
const maxon::EnumInfo& PrivateGetEnumInfo_VIEWPORTTYPE5635(){ return enum5635::VIEWPORTTYPE_info; }
namespace enum5648
{
	enum class SCENENODES_IDS
	{
	    SCENEHOOK_ID                = 1054188,        ///< SceneHook ID
	    MSGUPDATE_LEGACYOBJ_ID      = 180420109,      ///< Legacy Objects Update Message ID.
	    PERSISTENT_HASH_LOW_ID      = 180420112       ///< Persistent Hash ID.
	} ;
	static const maxon::UInt64 SCENENODES_IDS_values[] = {maxon::UInt64(enum5648::SCENENODES_IDS::SCENEHOOK_ID), maxon::UInt64(enum5648::SCENENODES_IDS::MSGUPDATE_LEGACYOBJ_ID), maxon::UInt64(enum5648::SCENENODES_IDS::PERSISTENT_HASH_LOW_ID)};
	static const maxon::EnumInfo SCENENODES_IDS_info{"SCENENODES_IDS", SIZEOF(SCENENODES_IDS), false, "SCENEHOOK_ID\0MSGUPDATE_LEGACYOBJ_ID\0PERSISTENT_HASH_LOW_ID\0", SCENENODES_IDS_values, std::extent<decltype(SCENENODES_IDS_values)>::value};
}
const maxon::EnumInfo& PrivateGetEnumInfo_SCENENODES_IDS5648(){ return enum5648::SCENENODES_IDS_info; }
namespace enum5657
{
	enum class FOLDMODE
	{
		NONE,
		HIDEMYSELF,
		EXPAND1STEP,
		EXPANDCOMPLETELY,
	} ;
	static const maxon::UInt64 FOLDMODE_values[] = {maxon::UInt64(enum5657::FOLDMODE::NONE), maxon::UInt64(enum5657::FOLDMODE::HIDEMYSELF), maxon::UInt64(enum5657::FOLDMODE::EXPAND1STEP), maxon::UInt64(enum5657::FOLDMODE::EXPANDCOMPLETELY)};
	static const maxon::EnumInfo FOLDMODE_info{"FOLDMODE", SIZEOF(FOLDMODE), false, "NONE\0HIDEMYSELF\0EXPAND1STEP\0EXPANDCOMPLETELY\0", FOLDMODE_values, std::extent<decltype(FOLDMODE_values)>::value};
}
const maxon::EnumInfo& PrivateGetEnumInfo_FOLDMODE5657(){ return enum5657::FOLDMODE_info; }
#ifdef CINEWARE_NAMESPACE_ENABLE
CINEWARE_NAMESPACE_END
#endif
#endif
