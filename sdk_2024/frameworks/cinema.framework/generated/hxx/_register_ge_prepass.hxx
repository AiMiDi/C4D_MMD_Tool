#if 1
#ifdef CINEWARE_NAMESPACE_ENABLE
CINEWARE_NAMESPACE_BEGIN
#endif
namespace enum58
{
	enum class LINESTYLE
	{
		NORMAL,
		DOTTED,
		DASHED,
		DASHED_INV,
		DASHED_BIG,
	} ;
	static const maxon::UInt64 LINESTYLE_values[] = {maxon::UInt64(enum58::LINESTYLE::NORMAL), maxon::UInt64(enum58::LINESTYLE::DOTTED), maxon::UInt64(enum58::LINESTYLE::DASHED), maxon::UInt64(enum58::LINESTYLE::DASHED_INV), maxon::UInt64(enum58::LINESTYLE::DASHED_BIG)};
	static const maxon::EnumInfo LINESTYLE_info{"LINESTYLE", SIZEOF(LINESTYLE), false, "NORMAL\0DOTTED\0DASHED\0DASHED_INV\0DASHED_BIG\0", LINESTYLE_values, std::extent<decltype(LINESTYLE_values)>::value};
}
const maxon::EnumInfo& PrivateGetEnumInfo_LINESTYLE58(){ return enum58::LINESTYLE_info; }
namespace enum70
{
	enum class SERVERMESSAGE
	{
		NONE		= 0,				///< None.
	
		WARNING	= 1000,			///< Warning.
		ERROR_	= 1001,			///< Error.
		INFO		= 1002			///< Info.
	} ;
	static const maxon::UInt64 SERVERMESSAGE_values[] = {maxon::UInt64(enum70::SERVERMESSAGE::NONE), maxon::UInt64(enum70::SERVERMESSAGE::WARNING), maxon::UInt64(enum70::SERVERMESSAGE::ERROR_), maxon::UInt64(enum70::SERVERMESSAGE::INFO)};
	static const maxon::EnumInfo SERVERMESSAGE_info{"SERVERMESSAGE", SIZEOF(SERVERMESSAGE), false, "NONE\0WARNING\0ERROR_\0INFO\0", SERVERMESSAGE_values, std::extent<decltype(SERVERMESSAGE_values)>::value};
}
const maxon::EnumInfo& PrivateGetEnumInfo_SERVERMESSAGE70(){ return enum70::SERVERMESSAGE_info; }
namespace enum82
{
	enum class RENDERJOBLIST
	{
		INACTIVE	= 1 << 1,			///< Inactive.
		ACTIVE		= 1 << 2,			///< Active.
		LOAD			= 1 << 3,			///< Load.
		ALL				= 14					///< All: @ref RENDERJOBLIST::INACTIVE | @ref RENDERJOBLIST::ACTIVE | @ref RENDERJOBLIST::LOAD.
	} ;
	static const maxon::UInt64 RENDERJOBLIST_values[] = {maxon::UInt64(enum82::RENDERJOBLIST::INACTIVE), maxon::UInt64(enum82::RENDERJOBLIST::ACTIVE), maxon::UInt64(enum82::RENDERJOBLIST::LOAD), maxon::UInt64(enum82::RENDERJOBLIST::ALL)};
	static const maxon::EnumInfo RENDERJOBLIST_info{"RENDERJOBLIST", SIZEOF(RENDERJOBLIST), true, "INACTIVE\0ACTIVE\0LOAD\0ALL\0", RENDERJOBLIST_values, std::extent<decltype(RENDERJOBLIST_values)>::value};
}
const maxon::EnumInfo& PrivateGetEnumInfo_RENDERJOBLIST82(){ return enum82::RENDERJOBLIST_info; }
namespace enum94
{
	enum class MESSAGERESULT
	{
		OK = 1000,					///< Ok.
		NETWORKERROR,				///< Network error.
		UNKNOWNERROR,				///< Unknown error.
		MEMORYERROR					///< Memory error.
	} ;
	static const maxon::UInt64 MESSAGERESULT_values[] = {maxon::UInt64(enum94::MESSAGERESULT::OK), maxon::UInt64(enum94::MESSAGERESULT::NETWORKERROR), maxon::UInt64(enum94::MESSAGERESULT::UNKNOWNERROR), maxon::UInt64(enum94::MESSAGERESULT::MEMORYERROR)};
	static const maxon::EnumInfo MESSAGERESULT_info{"MESSAGERESULT", SIZEOF(MESSAGERESULT), false, "OK\0NETWORKERROR\0UNKNOWNERROR\0MEMORYERROR\0", MESSAGERESULT_values, std::extent<decltype(MESSAGERESULT_values)>::value};
}
const maxon::EnumInfo& PrivateGetEnumInfo_MESSAGERESULT94(){ return enum94::MESSAGERESULT_info; }
namespace enum105
{
	enum class MACHINELIST
	{
		ONLINE	= 1 << 1,			///< Online.
		OFFLINE	= 1 << 0,			///< Offline.
		ALL			= 7,					///< All: @ref MACHINELIST::ONLINE | @ref MACHINELIST::OFFLINE.
	} ;
	static const maxon::UInt64 MACHINELIST_values[] = {maxon::UInt64(enum105::MACHINELIST::ONLINE), maxon::UInt64(enum105::MACHINELIST::OFFLINE), maxon::UInt64(enum105::MACHINELIST::ALL)};
	static const maxon::EnumInfo MACHINELIST_info{"MACHINELIST", SIZEOF(MACHINELIST), true, "ONLINE\0OFFLINE\0ALL\0", MACHINELIST_values, std::extent<decltype(MACHINELIST_values)>::value};
}
const maxon::EnumInfo& PrivateGetEnumInfo_MACHINELIST105(){ return enum105::MACHINELIST_info; }
namespace enum135
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
	static const maxon::UInt64 VERIFICATIONBIT_values[] = {maxon::UInt64(enum135::VERIFICATIONBIT::NONE), maxon::UInt64(enum135::VERIFICATIONBIT::ONLINE), maxon::UInt64(enum135::VERIFICATIONBIT::VERIFIED), maxon::UInt64(enum135::VERIFICATIONBIT::VERIFIEDME), maxon::UInt64(enum135::VERIFICATIONBIT::SHARED), maxon::UInt64(enum135::VERIFICATIONBIT::VERIFYING), maxon::UInt64(enum135::VERIFICATIONBIT::FAILURE), maxon::UInt64(enum135::VERIFICATIONBIT::SECURITYTOKENCHANGED), maxon::UInt64(enum135::VERIFICATIONBIT::WRONGBUILDID), maxon::UInt64(enum135::VERIFICATIONBIT::WRONGARCHITECTURE), maxon::UInt64(enum135::VERIFICATIONBIT::NOTREACHABLE), maxon::UInt64(enum135::VERIFICATIONBIT::NOANSWER), maxon::UInt64(enum135::VERIFICATIONBIT::WRONGSECURITYTOKEN), maxon::UInt64(enum135::VERIFICATIONBIT::DEMONOTACTIVATED), maxon::UInt64(enum135::VERIFICATIONBIT::REMOVING), maxon::UInt64(enum135::VERIFICATIONBIT::NORENDERSUPPORT), maxon::UInt64(enum135::VERIFICATIONBIT::INITIALIZING), maxon::UInt64(enum135::VERIFICATIONBIT::VERIFICATIONESTABLISHED)};
	static const maxon::EnumInfo VERIFICATIONBIT_info{"VERIFICATIONBIT", SIZEOF(VERIFICATIONBIT), true, "NONE\0ONLINE\0VERIFIED\0VERIFIEDME\0SHARED\0VERIFYING\0FAILURE\0SECURITYTOKENCHANGED\0WRONGBUILDID\0WRONGARCHITECTURE\0NOTREACHABLE\0NOANSWER\0WRONGSECURITYTOKEN\0DEMONOTACTIVATED\0REMOVING\0NORENDERSUPPORT\0INITIALIZING\0VERIFICATIONESTABLISHED\0", VERIFICATIONBIT_values, std::extent<decltype(VERIFICATIONBIT_values)>::value};
}
const maxon::EnumInfo& PrivateGetEnumInfo_VERIFICATIONBIT135(){ return enum135::VERIFICATIONBIT_info; }
namespace enum149
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
	static const maxon::UInt64 RENDERJOBCREATOR_values[] = {maxon::UInt64(enum149::RENDERJOBCREATOR::BATCHRENDER), maxon::UInt64(enum149::RENDERJOBCREATOR::PICTUREVIEWER), maxon::UInt64(enum149::RENDERJOBCREATOR::USER), maxon::UInt64(enum149::RENDERJOBCREATOR::WATCHDIRECTORY), maxon::UInt64(enum149::RENDERJOBCREATOR::WATCHDIRECTORYSTARTUP), maxon::UInt64(enum149::RENDERJOBCREATOR::OTHER)};
	static const maxon::EnumInfo RENDERJOBCREATOR_info{"RENDERJOBCREATOR", SIZEOF(RENDERJOBCREATOR), true, "BATCHRENDER\0PICTUREVIEWER\0USER\0WATCHDIRECTORY\0WATCHDIRECTORYSTARTUP\0OTHER\0", RENDERJOBCREATOR_values, std::extent<decltype(RENDERJOBCREATOR_values)>::value};
}
const maxon::EnumInfo& PrivateGetEnumInfo_RENDERJOBCREATOR149(){ return enum149::RENDERJOBCREATOR_info; }
namespace enum157
{
	enum class DETAILSELECTOR
	{
		NONE									= 0,
		SELECTED							= (1 << 0),
		NONSELECTED						= (1 << 1)
	} ;
	static const maxon::UInt64 DETAILSELECTOR_values[] = {maxon::UInt64(enum157::DETAILSELECTOR::NONE), maxon::UInt64(enum157::DETAILSELECTOR::SELECTED), maxon::UInt64(enum157::DETAILSELECTOR::NONSELECTED)};
	static const maxon::EnumInfo DETAILSELECTOR_info{"DETAILSELECTOR", SIZEOF(DETAILSELECTOR), true, "NONE\0SELECTED\0NONSELECTED\0", DETAILSELECTOR_values, std::extent<decltype(DETAILSELECTOR_values)>::value};
}
const maxon::EnumInfo& PrivateGetEnumInfo_DETAILSELECTOR157(){ return enum157::DETAILSELECTOR_info; }
namespace enum170
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
	static const maxon::UInt64 STATUSNETSTATE_values[] = {maxon::UInt64(enum170::STATUSNETSTATE::NONE), maxon::UInt64(enum170::STATUSNETSTATE::DISABLE), maxon::UInt64(enum170::STATUSNETSTATE::IDLE), maxon::UInt64(enum170::STATUSNETSTATE::BUSY), maxon::UInt64(enum170::STATUSNETSTATE::BUSY2), maxon::UInt64(enum170::STATUSNETSTATE::CRITICAL)};
	static const maxon::EnumInfo STATUSNETSTATE_info{"STATUSNETSTATE", SIZEOF(STATUSNETSTATE), true, "NONE\0DISABLE\0IDLE\0BUSY\0BUSY2\0CRITICAL\0", STATUSNETSTATE_values, std::extent<decltype(STATUSNETSTATE_values)>::value};
}
const maxon::EnumInfo& PrivateGetEnumInfo_STATUSNETSTATE170(){ return enum170::STATUSNETSTATE_info; }
namespace enum178
{
	enum class HOTKEYFLAGS
	{
		NONE = 0,
		MOUSE = 1 << 0,
		KEYBOARD = 1 << 1,
	} ;
	static const maxon::UInt64 HOTKEYFLAGS_values[] = {maxon::UInt64(enum178::HOTKEYFLAGS::NONE), maxon::UInt64(enum178::HOTKEYFLAGS::MOUSE), maxon::UInt64(enum178::HOTKEYFLAGS::KEYBOARD)};
	static const maxon::EnumInfo HOTKEYFLAGS_info{"HOTKEYFLAGS", SIZEOF(HOTKEYFLAGS), true, "NONE\0MOUSE\0KEYBOARD\0", HOTKEYFLAGS_values, std::extent<decltype(HOTKEYFLAGS_values)>::value};
}
const maxon::EnumInfo& PrivateGetEnumInfo_HOTKEYFLAGS178(){ return enum178::HOTKEYFLAGS_info; }
namespace enum268
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
		WITHFONTS						 = (1 << 11),	///< Also return fonts. @since 2024
	} ;
	static const maxon::UInt64 ASSETDATA_FLAG_values[] = {maxon::UInt64(enum268::ASSETDATA_FLAG::NONE), maxon::UInt64(enum268::ASSETDATA_FLAG::CURRENTFRAMEONLY), maxon::UInt64(enum268::ASSETDATA_FLAG::TEXTURESONLY), maxon::UInt64(enum268::ASSETDATA_FLAG::NET), maxon::UInt64(enum268::ASSETDATA_FLAG::CURRENTTAKEONLY), maxon::UInt64(enum268::ASSETDATA_FLAG::WITHCACHES), maxon::UInt64(enum268::ASSETDATA_FLAG::NOSUBSTANCES), maxon::UInt64(enum268::ASSETDATA_FLAG::MULTIPLEUSE), maxon::UInt64(enum268::ASSETDATA_FLAG::NOMISSING), maxon::UInt64(enum268::ASSETDATA_FLAG::NODOCUMENT), maxon::UInt64(enum268::ASSETDATA_FLAG::COLLECT_NODES_ASSETS), maxon::UInt64(enum268::ASSETDATA_FLAG::DONOTRESOLVE), maxon::UInt64(enum268::ASSETDATA_FLAG::WITHFONTS)};
	static const maxon::EnumInfo ASSETDATA_FLAG_info{"ASSETDATA_FLAG", SIZEOF(ASSETDATA_FLAG), true, "NONE\0CURRENTFRAMEONLY\0TEXTURESONLY\0NET\0CURRENTTAKEONLY\0WITHCACHES\0NOSUBSTANCES\0MULTIPLEUSE\0NOMISSING\0NODOCUMENT\0COLLECT_NODES_ASSETS\0DONOTRESOLVE\0WITHFONTS\0", ASSETDATA_FLAG_values, std::extent<decltype(ASSETDATA_FLAG_values)>::value};
}
const maxon::EnumInfo& PrivateGetEnumInfo_ASSETDATA_FLAG268(){ return enum268::ASSETDATA_FLAG_info; }
namespace enum289
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
	static const maxon::UInt64 SAVEBIT_values[] = {maxon::UInt64(enum289::SAVEBIT::NONE), maxon::UInt64(enum289::SAVEBIT::ALPHA), maxon::UInt64(enum289::SAVEBIT::MULTILAYER), maxon::UInt64(enum289::SAVEBIT::USESELECTEDLAYERS), maxon::UInt64(enum289::SAVEBIT::USE16BITCHANNELS), maxon::UInt64(enum289::SAVEBIT::GREYSCALE), maxon::UInt64(enum289::SAVEBIT::INTERNALNET), maxon::UInt64(enum289::SAVEBIT::DONTMERGE), maxon::UInt64(enum289::SAVEBIT::USE32BITCHANNELS), maxon::UInt64(enum289::SAVEBIT::SAVERENDERRESULT), maxon::UInt64(enum289::SAVEBIT::FIRSTALPHA_ONLY), maxon::UInt64(enum289::SAVEBIT::KEEP_COLOR_MODE)};
	static const maxon::EnumInfo SAVEBIT_info{"SAVEBIT", SIZEOF(SAVEBIT), true, "NONE\0ALPHA\0MULTILAYER\0USESELECTEDLAYERS\0USE16BITCHANNELS\0GREYSCALE\0INTERNALNET\0DONTMERGE\0USE32BITCHANNELS\0SAVERENDERRESULT\0FIRSTALPHA_ONLY\0KEEP_COLOR_MODE\0", SAVEBIT_values, std::extent<decltype(SAVEBIT_values)>::value};
}
const maxon::EnumInfo& PrivateGetEnumInfo_SAVEBIT289(){ return enum289::SAVEBIT_info; }
namespace enum319
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
		DOCUMENTINFOGUIALLOWED = (1 << 19),											///< Custom dialogs can be displayed while reacting to DocumentInfo Messages.
		SUPPRESSOPTIONSDIALOG = (1 << 31),											///< Suppress the options dialog (if DIALOGSALLOWED was specified), so that errors would show up
	} ;
	static const maxon::UInt64 SCENEFILTER_values[] = {maxon::UInt64(enum319::SCENEFILTER::NONE), maxon::UInt64(enum319::SCENEFILTER::OBJECTS), maxon::UInt64(enum319::SCENEFILTER::MATERIALS), maxon::UInt64(enum319::SCENEFILTER::DIALOGSALLOWED), maxon::UInt64(enum319::SCENEFILTER::PROGRESSALLOWED), maxon::UInt64(enum319::SCENEFILTER::MERGESCENE), maxon::UInt64(enum319::SCENEFILTER::NONEWMARKERS), maxon::UInt64(enum319::SCENEFILTER::SAVECACHES), maxon::UInt64(enum319::SCENEFILTER::NOUNDO), maxon::UInt64(enum319::SCENEFILTER::SAVE_BINARYCACHE), maxon::UInt64(enum319::SCENEFILTER::IDENTIFY_ONLY), maxon::UInt64(enum319::SCENEFILTER::ONLY_RENDERDATA), maxon::UInt64(enum319::SCENEFILTER::IGNOREMISSINGPLUGINSINNONACTIVERENDERDATA), maxon::UInt64(enum319::SCENEFILTER::IGNOREXREFS), maxon::UInt64(enum319::SCENEFILTER::DONTCORRECTOUTPUTFORMAT), maxon::UInt64(enum319::SCENEFILTER::SKIPOLDERTHANV13), maxon::UInt64(enum319::SCENEFILTER::PREVIEWONLY), maxon::UInt64(enum319::SCENEFILTER::DOCUMENTPREFSONLY), maxon::UInt64(enum319::SCENEFILTER::DOCUMENTINFOGUIALLOWED), maxon::UInt64(enum319::SCENEFILTER::SUPPRESSOPTIONSDIALOG)};
	static const maxon::EnumInfo SCENEFILTER_info{"SCENEFILTER", SIZEOF(SCENEFILTER), true, "NONE\0OBJECTS\0MATERIALS\0DIALOGSALLOWED\0PROGRESSALLOWED\0MERGESCENE\0NONEWMARKERS\0SAVECACHES\0NOUNDO\0SAVE_BINARYCACHE\0IDENTIFY_ONLY\0ONLY_RENDERDATA\0IGNOREMISSINGPLUGINSINNONACTIVERENDERDATA\0IGNOREXREFS\0DONTCORRECTOUTPUTFORMAT\0SKIPOLDERTHANV13\0PREVIEWONLY\0DOCUMENTPREFSONLY\0DOCUMENTINFOGUIALLOWED\0SUPPRESSOPTIONSDIALOG\0", SCENEFILTER_values, std::extent<decltype(SCENEFILTER_values)>::value};
}
const maxon::EnumInfo& PrivateGetEnumInfo_SCENEFILTER319(){ return enum319::SCENEFILTER_info; }
namespace enum333
{
	enum class OVERVIEW
	{
		DEFAULT		= 0,
		AKTU			= 1,
		SCENE			= 2,
		COMPLETE	= 3,
		SELECTED	= 4
	} ;
	static const maxon::UInt64 OVERVIEW_values[] = {maxon::UInt64(enum333::OVERVIEW::DEFAULT), maxon::UInt64(enum333::OVERVIEW::AKTU), maxon::UInt64(enum333::OVERVIEW::SCENE), maxon::UInt64(enum333::OVERVIEW::COMPLETE), maxon::UInt64(enum333::OVERVIEW::SELECTED)};
	static const maxon::EnumInfo OVERVIEW_info{"OVERVIEW", SIZEOF(OVERVIEW), true, "DEFAULT\0AKTU\0SCENE\0COMPLETE\0SELECTED\0", OVERVIEW_values, std::extent<decltype(OVERVIEW_values)>::value};
}
const maxon::EnumInfo& PrivateGetEnumInfo_OVERVIEW333(){ return enum333::OVERVIEW_info; }
namespace enum359
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
		DEFBUTTON1				= 0x0000,			///< Default button set to first button.
		DEFBUTTON2				= 0x0100,			///< Default button set to second button.
		DEFBUTTON3				= 0x0200,			///< Default button set to third button.
		DEFBUTTON4				= 0x0300,			///< Default button set to fourth button.
		MULTILINE					= 0x0080			///< If the message is more than @em 255 characters and @em 4 lines then this bit should be set for Mac compatibility.\n
																		///< The dialog is then restricted to only an OK button with limited keyboard support.
	} ;
	static const maxon::UInt64 GEMB_values[] = {maxon::UInt64(enum359::GEMB::OK), maxon::UInt64(enum359::GEMB::OKCANCEL), maxon::UInt64(enum359::GEMB::ABORTRETRYIGNORE), maxon::UInt64(enum359::GEMB::YESNOCANCEL), maxon::UInt64(enum359::GEMB::YESNO), maxon::UInt64(enum359::GEMB::RETRYCANCEL), maxon::UInt64(enum359::GEMB::FORCEDIALOG), maxon::UInt64(enum359::GEMB::ICONSTOP), maxon::UInt64(enum359::GEMB::ICONQUESTION), maxon::UInt64(enum359::GEMB::ICONEXCLAMATION), maxon::UInt64(enum359::GEMB::ICONASTERISK), maxon::UInt64(enum359::GEMB::DEFBUTTON1), maxon::UInt64(enum359::GEMB::DEFBUTTON2), maxon::UInt64(enum359::GEMB::DEFBUTTON3), maxon::UInt64(enum359::GEMB::DEFBUTTON4), maxon::UInt64(enum359::GEMB::MULTILINE)};
	static const maxon::EnumInfo GEMB_info{"GEMB", SIZEOF(GEMB), true, "OK\0OKCANCEL\0ABORTRETRYIGNORE\0YESNOCANCEL\0YESNO\0RETRYCANCEL\0FORCEDIALOG\0ICONSTOP\0ICONQUESTION\0ICONEXCLAMATION\0ICONASTERISK\0DEFBUTTON1\0DEFBUTTON2\0DEFBUTTON3\0DEFBUTTON4\0MULTILINE\0", GEMB_values, std::extent<decltype(GEMB_values)>::value};
}
const maxon::EnumInfo& PrivateGetEnumInfo_GEMB359(){ return enum359::GEMB_info; }
namespace enum377
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
	static const maxon::UInt64 GEMB_R_values[] = {maxon::UInt64(enum377::GEMB_R::V_UNDEFINED), maxon::UInt64(enum377::GEMB_R::V_OK), maxon::UInt64(enum377::GEMB_R::V_CANCEL), maxon::UInt64(enum377::GEMB_R::V_ABORT), maxon::UInt64(enum377::GEMB_R::V_RETRY), maxon::UInt64(enum377::GEMB_R::V_IGNORE), maxon::UInt64(enum377::GEMB_R::V_YES), maxon::UInt64(enum377::GEMB_R::V_NO)};
	static const maxon::EnumInfo GEMB_R_info{"GEMB_R", SIZEOF(GEMB_R), false, "V_UNDEFINED\0V_OK\0V_CANCEL\0V_ABORT\0V_RETRY\0V_IGNORE\0V_YES\0V_NO\0", GEMB_R_values, std::extent<decltype(GEMB_R_values)>::value};
}
const maxon::EnumInfo& PrivateGetEnumInfo_GEMB_R377(){ return enum377::GEMB_R_info; }
namespace enum389
{
	enum class MOUSEDRAGRESULT
	{
		ESCAPE		= 1,			///< Drag aborted.
		FINISHED	= 2,			///< Drag finished.
		CONTINUE	= 3				///< Drag still in progress.
	} ;
	static const maxon::UInt64 MOUSEDRAGRESULT_values[] = {maxon::UInt64(enum389::MOUSEDRAGRESULT::ESCAPE), maxon::UInt64(enum389::MOUSEDRAGRESULT::FINISHED), maxon::UInt64(enum389::MOUSEDRAGRESULT::CONTINUE)};
	static const maxon::EnumInfo MOUSEDRAGRESULT_info{"MOUSEDRAGRESULT", SIZEOF(MOUSEDRAGRESULT), false, "ESCAPE\0FINISHED\0CONTINUE\0", MOUSEDRAGRESULT_values, std::extent<decltype(MOUSEDRAGRESULT_values)>::value};
}
const maxon::EnumInfo& PrivateGetEnumInfo_MOUSEDRAGRESULT389(){ return enum389::MOUSEDRAGRESULT_info; }
namespace enum404
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
	static const maxon::UInt64 MOUSEDRAGFLAGS_values[] = {maxon::UInt64(enum404::MOUSEDRAGFLAGS::NONE), maxon::UInt64(enum404::MOUSEDRAGFLAGS::DONTHIDEMOUSE), maxon::UInt64(enum404::MOUSEDRAGFLAGS::NOMOVE), maxon::UInt64(enum404::MOUSEDRAGFLAGS::EVERYPACKET), maxon::UInt64(enum404::MOUSEDRAGFLAGS::COMPENSATEVIEWPORTORG), maxon::UInt64(enum404::MOUSEDRAGFLAGS::AIRBRUSH)};
	static const maxon::EnumInfo MOUSEDRAGFLAGS_info{"MOUSEDRAGFLAGS", SIZEOF(MOUSEDRAGFLAGS), true, "NONE\0DONTHIDEMOUSE\0NOMOVE\0EVERYPACKET\0COMPENSATEVIEWPORTORG\0AIRBRUSH\0", MOUSEDRAGFLAGS_values, std::extent<decltype(MOUSEDRAGFLAGS_values)>::value};
}
const maxon::EnumInfo& PrivateGetEnumInfo_MOUSEDRAGFLAGS404(){ return enum404::MOUSEDRAGFLAGS_info; }
namespace enum418
{
	enum class INITRENDERRESULT
	{
		OK						= 0,				///< Everything is OK, there was no error.
		OUTOFMEMORY		= -100,			///< Not enough memory.
		ASSETMISSING	= -101,			///< Assets (textures etc.) are missing.
		UNKNOWNERROR	= -102,			///< Unknown error.
		USERBREAK			= -103			///< Thread has been canceled. @since R17.032 Was @c INITRENDERRESULT_THREADEDLOCK.
	} ;
	static const maxon::UInt64 INITRENDERRESULT_values[] = {maxon::UInt64(enum418::INITRENDERRESULT::OK), maxon::UInt64(enum418::INITRENDERRESULT::OUTOFMEMORY), maxon::UInt64(enum418::INITRENDERRESULT::ASSETMISSING), maxon::UInt64(enum418::INITRENDERRESULT::UNKNOWNERROR), maxon::UInt64(enum418::INITRENDERRESULT::USERBREAK)};
	static const maxon::EnumInfo INITRENDERRESULT_info{"INITRENDERRESULT", SIZEOF(INITRENDERRESULT), false, "OK\0OUTOFMEMORY\0ASSETMISSING\0UNKNOWNERROR\0USERBREAK\0", INITRENDERRESULT_values, std::extent<decltype(INITRENDERRESULT_values)>::value};
}
const maxon::EnumInfo& PrivateGetEnumInfo_INITRENDERRESULT418(){ return enum418::INITRENDERRESULT_info; }
namespace enum440
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
	static const maxon::UInt64 RENDERRESULT_values[] = {maxon::UInt64(enum440::RENDERRESULT::OK), maxon::UInt64(enum440::RENDERRESULT::OUTOFMEMORY), maxon::UInt64(enum440::RENDERRESULT::ASSETMISSING), maxon::UInt64(enum440::RENDERRESULT::SAVINGFAILED), maxon::UInt64(enum440::RENDERRESULT::USERBREAK), maxon::UInt64(enum440::RENDERRESULT::GICACHEMISSING), maxon::UInt64(enum440::RENDERRESULT::NOMACHINE), maxon::UInt64(enum440::RENDERRESULT::UNAVAILABLE), maxon::UInt64(enum440::RENDERRESULT::FAILED), maxon::UInt64(enum440::RENDERRESULT::PROJECTNOTFOUND), maxon::UInt64(enum440::RENDERRESULT::ERRORLOADINGPROJECT), maxon::UInt64(enum440::RENDERRESULT::NOOUTPUTSPECIFIED)};
	static const maxon::EnumInfo RENDERRESULT_info{"RENDERRESULT", SIZEOF(RENDERRESULT), false, "OK\0OUTOFMEMORY\0ASSETMISSING\0SAVINGFAILED\0USERBREAK\0GICACHEMISSING\0NOMACHINE\0UNAVAILABLE\0FAILED\0PROJECTNOTFOUND\0ERRORLOADINGPROJECT\0NOOUTPUTSPECIFIED\0", RENDERRESULT_values, std::extent<decltype(RENDERRESULT_values)>::value};
}
const maxon::EnumInfo& PrivateGetEnumInfo_RENDERRESULT440(){ return enum440::RENDERRESULT_info; }
namespace enum494
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
	static const maxon::UInt64 COLORMODE_values[] = {maxon::UInt64(enum494::COLORMODE::ILLEGAL), maxon::UInt64(enum494::COLORMODE::ALPHA), maxon::UInt64(enum494::COLORMODE::GRAY), maxon::UInt64(enum494::COLORMODE::AGRAY), maxon::UInt64(enum494::COLORMODE::RGB), maxon::UInt64(enum494::COLORMODE::ARGB), maxon::UInt64(enum494::COLORMODE::CMYK), maxon::UInt64(enum494::COLORMODE::ACMYK), maxon::UInt64(enum494::COLORMODE::MASK), maxon::UInt64(enum494::COLORMODE::AMASK), maxon::UInt64(enum494::COLORMODE::ILLEGALw), maxon::UInt64(enum494::COLORMODE::GRAYw), maxon::UInt64(enum494::COLORMODE::AGRAYw), maxon::UInt64(enum494::COLORMODE::RGBw), maxon::UInt64(enum494::COLORMODE::ARGBw), maxon::UInt64(enum494::COLORMODE::MASKw), maxon::UInt64(enum494::COLORMODE::ILLEGALf), maxon::UInt64(enum494::COLORMODE::GRAYf), maxon::UInt64(enum494::COLORMODE::AGRAYf), maxon::UInt64(enum494::COLORMODE::RGBf), maxon::UInt64(enum494::COLORMODE::ARGBf), maxon::UInt64(enum494::COLORMODE::MASKf)};
	static const maxon::EnumInfo COLORMODE_info{"COLORMODE", SIZEOF(COLORMODE), true, "ILLEGAL\0ALPHA\0GRAY\0AGRAY\0RGB\0ARGB\0CMYK\0ACMYK\0MASK\0AMASK\0ILLEGALw\0GRAYw\0AGRAYw\0RGBw\0ARGBw\0MASKw\0ILLEGALf\0GRAYf\0AGRAYf\0RGBf\0ARGBf\0MASKf\0", COLORMODE_values, std::extent<decltype(COLORMODE_values)>::value};
}
const maxon::EnumInfo& PrivateGetEnumInfo_COLORMODE494(){ return enum494::COLORMODE_info; }
namespace enum523
{
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
	} ;
	static const maxon::UInt64 COLORSPACETRANSFORMATION_values[] = {maxon::UInt64(enum523::COLORSPACETRANSFORMATION::NONE), maxon::UInt64(enum523::COLORSPACETRANSFORMATION::LINEAR_TO_SRGB), maxon::UInt64(enum523::COLORSPACETRANSFORMATION::SRGB_TO_LINEAR), maxon::UInt64(enum523::COLORSPACETRANSFORMATION::LINEAR_TO_VIEW), maxon::UInt64(enum523::COLORSPACETRANSFORMATION::SRGB_TO_VIEW), maxon::UInt64(enum523::COLORSPACETRANSFORMATION::OCIO_INPUT_LOW_TO_RENDERING), maxon::UInt64(enum523::COLORSPACETRANSFORMATION::OCIO_RENDERING_TO_INPUT_LOW), maxon::UInt64(enum523::COLORSPACETRANSFORMATION::OCIO_RENDERING_TO_VIEW), maxon::UInt64(enum523::COLORSPACETRANSFORMATION::OCIO_INPUT_LOW_TO_VIEW), maxon::UInt64(enum523::COLORSPACETRANSFORMATION::OCIO_VIEW_TO_RENDERING), maxon::UInt64(enum523::COLORSPACETRANSFORMATION::OCIO_VIEW_TO_INPUT_LOW), maxon::UInt64(enum523::COLORSPACETRANSFORMATION::OCIO_INPUT_HIGH_TO_RENDERING), maxon::UInt64(enum523::COLORSPACETRANSFORMATION::OCIO_RENDERING_TO_DISPLAY), maxon::UInt64(enum523::COLORSPACETRANSFORMATION::OCIO_DISPLAY_TO_RENDERING), maxon::UInt64(enum523::COLORSPACETRANSFORMATION::OCIO_SRGB_TO_RENDERING), maxon::UInt64(enum523::COLORSPACETRANSFORMATION::OCIO_RENDERING_TO_SRGB), maxon::UInt64(enum523::COLORSPACETRANSFORMATION::OCIO_LINEAR_TO_RENDERING), maxon::UInt64(enum523::COLORSPACETRANSFORMATION::OCIO_RENDERING_TO_LINEAR)};
	static const maxon::EnumInfo COLORSPACETRANSFORMATION_info{"COLORSPACETRANSFORMATION", SIZEOF(COLORSPACETRANSFORMATION), false, "NONE\0LINEAR_TO_SRGB\0SRGB_TO_LINEAR\0LINEAR_TO_VIEW\0SRGB_TO_VIEW\0OCIO_INPUT_LOW_TO_RENDERING\0OCIO_RENDERING_TO_INPUT_LOW\0OCIO_RENDERING_TO_VIEW\0OCIO_INPUT_LOW_TO_VIEW\0OCIO_VIEW_TO_RENDERING\0OCIO_VIEW_TO_INPUT_LOW\0OCIO_INPUT_HIGH_TO_RENDERING\0OCIO_RENDERING_TO_DISPLAY\0OCIO_DISPLAY_TO_RENDERING\0OCIO_SRGB_TO_RENDERING\0OCIO_RENDERING_TO_SRGB\0OCIO_LINEAR_TO_RENDERING\0OCIO_RENDERING_TO_LINEAR\0", COLORSPACETRANSFORMATION_values, std::extent<decltype(COLORSPACETRANSFORMATION_values)>::value};
}
const maxon::EnumInfo& PrivateGetEnumInfo_COLORSPACETRANSFORMATION523(){ return enum523::COLORSPACETRANSFORMATION_info; }
namespace enum535
{
	enum class VIEW_WINDOW_COLOR_SPACE : Int32
	{
		UNDEFINED	= 0,			///< Undefined, e.g. if there is no ViewWindow for the BaseDraw.
		LINEAR		= 1,			///< Linear.
		SRGB			= 2,			///< sRGB.
	} ;
	static const maxon::UInt64 VIEW_WINDOW_COLOR_SPACE_values[] = {maxon::UInt64(enum535::VIEW_WINDOW_COLOR_SPACE::UNDEFINED), maxon::UInt64(enum535::VIEW_WINDOW_COLOR_SPACE::LINEAR), maxon::UInt64(enum535::VIEW_WINDOW_COLOR_SPACE::SRGB)};
	static const maxon::EnumInfo VIEW_WINDOW_COLOR_SPACE_info{"VIEW_WINDOW_COLOR_SPACE", SIZEOF(VIEW_WINDOW_COLOR_SPACE), false, "UNDEFINED\0LINEAR\0SRGB\0", VIEW_WINDOW_COLOR_SPACE_values, std::extent<decltype(VIEW_WINDOW_COLOR_SPACE_values)>::value};
}
const maxon::EnumInfo& PrivateGetEnumInfo_VIEW_WINDOW_COLOR_SPACE535(){ return enum535::VIEW_WINDOW_COLOR_SPACE_info; }
namespace enum550
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
	static const maxon::UInt64 PIXELCNT_values[] = {maxon::UInt64(enum550::PIXELCNT::NONE), maxon::UInt64(enum550::PIXELCNT::DITHERING), maxon::UInt64(enum550::PIXELCNT::B3DLAYERS), maxon::UInt64(enum550::PIXELCNT::APPLYALPHA), maxon::UInt64(enum550::PIXELCNT::INTERNAL_SETLINE), maxon::UInt64(enum550::PIXELCNT::INTERNAL_ALPHAVALUE)};
	static const maxon::EnumInfo PIXELCNT_info{"PIXELCNT", SIZEOF(PIXELCNT), true, "NONE\0DITHERING\0B3DLAYERS\0APPLYALPHA\0INTERNAL_SETLINE\0INTERNAL_ALPHAVALUE\0", PIXELCNT_values, std::extent<decltype(PIXELCNT_values)>::value};
}
const maxon::EnumInfo& PrivateGetEnumInfo_PIXELCNT550(){ return enum550::PIXELCNT_info; }
namespace enum564
{
	enum class INITBITMAPFLAGS
	{
		NONE			= 0,						///< None.
		GRAYSCALE	= (1 << 0),			///< Initialize as grayscale bitmap.
		SYSTEM		= (1 << 1),			///< @markPrivate
		DPNULL		= (1 << 2)			///< @markPrivate
	} ;
	static const maxon::UInt64 INITBITMAPFLAGS_values[] = {maxon::UInt64(enum564::INITBITMAPFLAGS::NONE), maxon::UInt64(enum564::INITBITMAPFLAGS::GRAYSCALE), maxon::UInt64(enum564::INITBITMAPFLAGS::SYSTEM), maxon::UInt64(enum564::INITBITMAPFLAGS::DPNULL)};
	static const maxon::EnumInfo INITBITMAPFLAGS_info{"INITBITMAPFLAGS", SIZEOF(INITBITMAPFLAGS), true, "NONE\0GRAYSCALE\0SYSTEM\0DPNULL\0", INITBITMAPFLAGS_values, std::extent<decltype(INITBITMAPFLAGS_values)>::value};
}
const maxon::EnumInfo& PrivateGetEnumInfo_INITBITMAPFLAGS564(){ return enum564::INITBITMAPFLAGS_info; }
namespace enum576
{
	enum class MPB_GETLAYERS
	{
		NONE	= 0,						///< None.
		ALPHA	= (1 << 1),			///< Get alpha layers.
		IMAGE	= (1 << 2)			///< Get image layers.
	} ;
	static const maxon::UInt64 MPB_GETLAYERS_values[] = {maxon::UInt64(enum576::MPB_GETLAYERS::NONE), maxon::UInt64(enum576::MPB_GETLAYERS::ALPHA), maxon::UInt64(enum576::MPB_GETLAYERS::IMAGE)};
	static const maxon::EnumInfo MPB_GETLAYERS_info{"MPB_GETLAYERS", SIZEOF(MPB_GETLAYERS), true, "NONE\0ALPHA\0IMAGE\0", MPB_GETLAYERS_values, std::extent<decltype(MPB_GETLAYERS_values)>::value};
}
const maxon::EnumInfo& PrivateGetEnumInfo_MPB_GETLAYERS576(){ return enum576::MPB_GETLAYERS_info; }
namespace enum596
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
	static const maxon::UInt64 MPBTYPE_values[] = {maxon::UInt64(enum596::MPBTYPE::SHOW), maxon::UInt64(enum596::MPBTYPE::SAVE), maxon::UInt64(enum596::MPBTYPE::PERCENT), maxon::UInt64(enum596::MPBTYPE::BLENDMODE), maxon::UInt64(enum596::MPBTYPE::COLORMODE), maxon::UInt64(enum596::MPBTYPE::BITMAPTYPE), maxon::UInt64(enum596::MPBTYPE::NAME), maxon::UInt64(enum596::MPBTYPE::DPI), maxon::UInt64(enum596::MPBTYPE::USERID), maxon::UInt64(enum596::MPBTYPE::USERSUBID), maxon::UInt64(enum596::MPBTYPE::FORCEBLEND)};
	static const maxon::EnumInfo MPBTYPE_info{"MPBTYPE", SIZEOF(MPBTYPE), false, "SHOW\0SAVE\0PERCENT\0BLENDMODE\0COLORMODE\0BITMAPTYPE\0NAME\0DPI\0USERID\0USERSUBID\0FORCEBLEND\0", MPBTYPE_values, std::extent<decltype(MPBTYPE_values)>::value};
}
const maxon::EnumInfo& PrivateGetEnumInfo_MPBTYPE596(){ return enum596::MPBTYPE_info; }
namespace enum616
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
	static const maxon::UInt64 LENGTHUNIT_values[] = {maxon::UInt64(enum616::LENGTHUNIT::PIXEL), maxon::UInt64(enum616::LENGTHUNIT::KM), maxon::UInt64(enum616::LENGTHUNIT::M), maxon::UInt64(enum616::LENGTHUNIT::CM), maxon::UInt64(enum616::LENGTHUNIT::MM), maxon::UInt64(enum616::LENGTHUNIT::UM), maxon::UInt64(enum616::LENGTHUNIT::NM), maxon::UInt64(enum616::LENGTHUNIT::MILE), maxon::UInt64(enum616::LENGTHUNIT::YARD), maxon::UInt64(enum616::LENGTHUNIT::FEET), maxon::UInt64(enum616::LENGTHUNIT::INCH)};
	static const maxon::EnumInfo LENGTHUNIT_info{"LENGTHUNIT", SIZEOF(LENGTHUNIT), false, "PIXEL\0KM\0M\0CM\0MM\0UM\0NM\0MILE\0YARD\0FEET\0INCH\0", LENGTHUNIT_values, std::extent<decltype(LENGTHUNIT_values)>::value};
}
const maxon::EnumInfo& PrivateGetEnumInfo_LENGTHUNIT616(){ return enum616::LENGTHUNIT_info; }
namespace enum633
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
	static const maxon::UInt64 SPLINETYPE_values[] = {maxon::UInt64(enum633::SPLINETYPE::LINEAR), maxon::UInt64(enum633::SPLINETYPE::CUBIC), maxon::UInt64(enum633::SPLINETYPE::AKIMA), maxon::UInt64(enum633::SPLINETYPE::BSPLINE), maxon::UInt64(enum633::SPLINETYPE::BEZIER), maxon::UInt64(enum633::SPLINETYPE::RESERVEDSPLINETYPE1), maxon::UInt64(enum633::SPLINETYPE::RESERVEDSPLINETYPE2)};
	static const maxon::EnumInfo SPLINETYPE_info{"SPLINETYPE", SIZEOF(SPLINETYPE), false, "LINEAR\0CUBIC\0AKIMA\0BSPLINE\0BEZIER\0RESERVEDSPLINETYPE1\0RESERVEDSPLINETYPE2\0", SPLINETYPE_values, std::extent<decltype(SPLINETYPE_values)>::value};
}
const maxon::EnumInfo& PrivateGetEnumInfo_SPLINETYPE633(){ return enum633::SPLINETYPE_info; }
namespace enum646
{
	enum class BREAKTANGENTS
	{
		// V_ unfortunately has to be used here due to conflicts with MAC OS
		V_FALSE	=	0,			///< Do not break any tangents.
		V_TRUE	=	1,			///< Break the tangents.
		V_AUTO	= 2				///< Only break the tangents if the tangents are already broken.
	} ;
	static const maxon::UInt64 BREAKTANGENTS_values[] = {maxon::UInt64(enum646::BREAKTANGENTS::V_FALSE), maxon::UInt64(enum646::BREAKTANGENTS::V_TRUE), maxon::UInt64(enum646::BREAKTANGENTS::V_AUTO)};
	static const maxon::EnumInfo BREAKTANGENTS_info{"BREAKTANGENTS", SIZEOF(BREAKTANGENTS), false, "V_FALSE\0V_TRUE\0V_AUTO\0", BREAKTANGENTS_values, std::extent<decltype(BREAKTANGENTS_values)>::value};
}
const maxon::EnumInfo& PrivateGetEnumInfo_BREAKTANGENTS646(){ return enum646::BREAKTANGENTS_info; }
namespace enum658
{
	enum class TANGENTSIDE
	{
		NONE	=	-1,			///< No tangent handles being modified.
		LEFT	= 0,			///< Modify the left tangent handle.
		RIGHT	= 1,			///< Modify the right tangent handle.
	} ;
	static const maxon::UInt64 TANGENTSIDE_values[] = {maxon::UInt64(enum658::TANGENTSIDE::NONE), maxon::UInt64(enum658::TANGENTSIDE::LEFT), maxon::UInt64(enum658::TANGENTSIDE::RIGHT)};
	static const maxon::EnumInfo TANGENTSIDE_info{"TANGENTSIDE", SIZEOF(TANGENTSIDE), false, "NONE\0LEFT\0RIGHT\0", TANGENTSIDE_values, std::extent<decltype(TANGENTSIDE_values)>::value};
}
const maxon::EnumInfo& PrivateGetEnumInfo_TANGENTSIDE658(){ return enum658::TANGENTSIDE_info; }
namespace enum672
{
	enum class TANGENTTRANSFORMFLAG
	{
		NONE					=	0,																					///< No transform flag.
		LOCK_LENGTH		=	(1 << 0),																		///< Fix the length of the tangents, only change the rotation.
		LOCK_ANGLE		=	(1 << 1),																		///< Fix the angle of the tangents, only change the length.
		BREAK_SCALE		=	(1 << 2),																		///< Only scale one handle (but rotate both).
		BREAK					=	TANGENTTRANSFORMFLAG::BREAK_SCALE|(1 << 3)		///< Only modify one handle.
	} ;
	static const maxon::UInt64 TANGENTTRANSFORMFLAG_values[] = {maxon::UInt64(enum672::TANGENTTRANSFORMFLAG::NONE), maxon::UInt64(enum672::TANGENTTRANSFORMFLAG::LOCK_LENGTH), maxon::UInt64(enum672::TANGENTTRANSFORMFLAG::LOCK_ANGLE), maxon::UInt64(enum672::TANGENTTRANSFORMFLAG::BREAK_SCALE), maxon::UInt64(enum672::TANGENTTRANSFORMFLAG::BREAK)};
	static const maxon::EnumInfo TANGENTTRANSFORMFLAG_info{"TANGENTTRANSFORMFLAG", SIZEOF(TANGENTTRANSFORMFLAG), true, "NONE\0LOCK_LENGTH\0LOCK_ANGLE\0BREAK_SCALE\0BREAK\0", TANGENTTRANSFORMFLAG_values, std::extent<decltype(TANGENTTRANSFORMFLAG_values)>::value};
}
const maxon::EnumInfo& PrivateGetEnumInfo_TANGENTTRANSFORMFLAG672(){ return enum672::TANGENTTRANSFORMFLAG_info; }
namespace enum686
{
	enum class SPLINEBOOL_AXIS
	{
		NONE			= 0,			///< No axis.
		SCREEN		=	1,			///< Project into the current screen.
		ZY				=	2,			///< Project on the ZY (X axis) plane.
		XZ				= 3,			///< Project on the XZ (Y axis) plane.
		XY				= 4				///< Project on the XY (Z axis) plane.
	} ;
	static const maxon::UInt64 SPLINEBOOL_AXIS_values[] = {maxon::UInt64(enum686::SPLINEBOOL_AXIS::NONE), maxon::UInt64(enum686::SPLINEBOOL_AXIS::SCREEN), maxon::UInt64(enum686::SPLINEBOOL_AXIS::ZY), maxon::UInt64(enum686::SPLINEBOOL_AXIS::XZ), maxon::UInt64(enum686::SPLINEBOOL_AXIS::XY)};
	static const maxon::EnumInfo SPLINEBOOL_AXIS_info{"SPLINEBOOL_AXIS", SIZEOF(SPLINEBOOL_AXIS), false, "NONE\0SCREEN\0ZY\0XZ\0XY\0", SPLINEBOOL_AXIS_values, std::extent<decltype(SPLINEBOOL_AXIS_values)>::value};
}
const maxon::EnumInfo& PrivateGetEnumInfo_SPLINEBOOL_AXIS686(){ return enum686::SPLINEBOOL_AXIS_info; }
namespace enum701
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
	static const maxon::UInt64 SPLINEBOOL_MODE_values[] = {maxon::UInt64(enum701::SPLINEBOOL_MODE::AMINUSB), maxon::UInt64(enum701::SPLINEBOOL_MODE::BMINUSA), maxon::UInt64(enum701::SPLINEBOOL_MODE::UNION), maxon::UInt64(enum701::SPLINEBOOL_MODE::AND), maxon::UInt64(enum701::SPLINEBOOL_MODE::OR), maxon::UInt64(enum701::SPLINEBOOL_MODE::INTERSECTION)};
	static const maxon::EnumInfo SPLINEBOOL_MODE_info{"SPLINEBOOL_MODE", SIZEOF(SPLINEBOOL_MODE), false, "AMINUSB\0BMINUSA\0UNION\0AND\0OR\0INTERSECTION\0", SPLINEBOOL_MODE_values, std::extent<decltype(SPLINEBOOL_MODE_values)>::value};
}
const maxon::EnumInfo& PrivateGetEnumInfo_SPLINEBOOL_MODE701(){ return enum701::SPLINEBOOL_MODE_info; }
namespace enum713
{
	enum class PARTICLEFLAGS
	{
		NONE		= 0,						///< None.
		VISIBLE	= (1 << 0),			///< %Particle is visible.
		ALIVE		= (1 << 1)			///< %Particle is alive.
	} ;
	static const maxon::UInt64 PARTICLEFLAGS_values[] = {maxon::UInt64(enum713::PARTICLEFLAGS::NONE), maxon::UInt64(enum713::PARTICLEFLAGS::VISIBLE), maxon::UInt64(enum713::PARTICLEFLAGS::ALIVE)};
	static const maxon::EnumInfo PARTICLEFLAGS_info{"PARTICLEFLAGS", SIZEOF(PARTICLEFLAGS), true, "NONE\0VISIBLE\0ALIVE\0", PARTICLEFLAGS_values, std::extent<decltype(PARTICLEFLAGS_values)>::value};
}
const maxon::EnumInfo& PrivateGetEnumInfo_PARTICLEFLAGS713(){ return enum713::PARTICLEFLAGS_info; }
namespace enum843
{
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
	} ;
	static const maxon::UInt64 NBIT_values[] = {maxon::UInt64(enum843::NBIT::NONE), maxon::UInt64(enum843::NBIT::TL1_FOLD), maxon::UInt64(enum843::NBIT::TL2_FOLD), maxon::UInt64(enum843::NBIT::TL3_FOLD), maxon::UInt64(enum843::NBIT::TL4_FOLD), maxon::UInt64(enum843::NBIT::TL1_SELECT), maxon::UInt64(enum843::NBIT::TL2_SELECT), maxon::UInt64(enum843::NBIT::TL3_SELECT), maxon::UInt64(enum843::NBIT::TL4_SELECT), maxon::UInt64(enum843::NBIT::TL1_TDRAW), maxon::UInt64(enum843::NBIT::TL2_TDRAW), maxon::UInt64(enum843::NBIT::TL3_TDRAW), maxon::UInt64(enum843::NBIT::TL4_TDRAW), maxon::UInt64(enum843::NBIT::CKEY_ACTIVE), maxon::UInt64(enum843::NBIT::OM1_FOLD), maxon::UInt64(enum843::NBIT::OM2_FOLD), maxon::UInt64(enum843::NBIT::OM3_FOLD), maxon::UInt64(enum843::NBIT::OM4_FOLD), maxon::UInt64(enum843::NBIT::TL1_FOLDTR), maxon::UInt64(enum843::NBIT::TL2_FOLDTR), maxon::UInt64(enum843::NBIT::TL3_FOLDTR), maxon::UInt64(enum843::NBIT::TL4_FOLDTR), maxon::UInt64(enum843::NBIT::TL1_FOLDFC), maxon::UInt64(enum843::NBIT::TL2_FOLDFC), maxon::UInt64(enum843::NBIT::TL3_FOLDFC), maxon::UInt64(enum843::NBIT::TL4_FOLDFC), maxon::UInt64(enum843::NBIT::SOURCEOPEN), maxon::UInt64(enum843::NBIT::TL1_HIDE), maxon::UInt64(enum843::NBIT::TL2_HIDE), maxon::UInt64(enum843::NBIT::TL3_HIDE), maxon::UInt64(enum843::NBIT::TL4_HIDE), maxon::UInt64(enum843::NBIT::SOLO_ANIM), maxon::UInt64(enum843::NBIT::SOLO_LAYER), maxon::UInt64(enum843::NBIT::TL1_SELECT2), maxon::UInt64(enum843::NBIT::TL2_SELECT2), maxon::UInt64(enum843::NBIT::TL3_SELECT2), maxon::UInt64(enum843::NBIT::TL4_SELECT2), maxon::UInt64(enum843::NBIT::SOLO_MOTION), maxon::UInt64(enum843::NBIT::CKEY_LOCK_T), maxon::UInt64(enum843::NBIT::CKEY_LOCK_V), maxon::UInt64(enum843::NBIT::CKEY_MUTE), maxon::UInt64(enum843::NBIT::CKEY_CLAMP), maxon::UInt64(enum843::NBIT::CKEY_BREAK), maxon::UInt64(enum843::NBIT::CKEY_KEEPVISUALANGLE), maxon::UInt64(enum843::NBIT::CKEY_LOCK_O), maxon::UInt64(enum843::NBIT::CKEY_LOCK_L), maxon::UInt64(enum843::NBIT::CKEY_AUTO), maxon::UInt64(enum843::NBIT::CKEY_ZERO_O_OLD), maxon::UInt64(enum843::NBIT::CKEY_ZERO_L_OLD), maxon::UInt64(enum843::NBIT::TL1_FCSELECT), maxon::UInt64(enum843::NBIT::TL2_FCSELECT), maxon::UInt64(enum843::NBIT::TL3_FCSELECT), maxon::UInt64(enum843::NBIT::TL4_FCSELECT), maxon::UInt64(enum843::NBIT::CKEY_BREAKDOWN), maxon::UInt64(enum843::NBIT::TL1_FOLDMOTION), maxon::UInt64(enum843::NBIT::TL2_FOLDMOTION), maxon::UInt64(enum843::NBIT::TL3_FOLDMOTION), maxon::UInt64(enum843::NBIT::TL4_FOLDMOTION), maxon::UInt64(enum843::NBIT::TL1_SELECTMOTION), maxon::UInt64(enum843::NBIT::TL2_SELECTMOTION), maxon::UInt64(enum843::NBIT::TL3_SELECTMOTION), maxon::UInt64(enum843::NBIT::TL4_SELECTMOTION), maxon::UInt64(enum843::NBIT::OHIDE), maxon::UInt64(enum843::NBIT::TL_TBAKE), maxon::UInt64(enum843::NBIT::TL1_FOLDSM), maxon::UInt64(enum843::NBIT::TL2_FOLDSM), maxon::UInt64(enum843::NBIT::TL3_FOLDSM), maxon::UInt64(enum843::NBIT::TL4_FOLDSM), maxon::UInt64(enum843::NBIT::SUBOBJECT), maxon::UInt64(enum843::NBIT::LINK_ACTIVE), maxon::UInt64(enum843::NBIT::THIDE), maxon::UInt64(enum843::NBIT::SUBOBJECT_AM), maxon::UInt64(enum843::NBIT::PROTECTION), maxon::UInt64(enum843::NBIT::NOANIM), maxon::UInt64(enum843::NBIT::NOSELECT), maxon::UInt64(enum843::NBIT::EHIDE), maxon::UInt64(enum843::NBIT::REF), maxon::UInt64(enum843::NBIT::REF_NO_DD), maxon::UInt64(enum843::NBIT::REF_OHIDE), maxon::UInt64(enum843::NBIT::NO_DD), maxon::UInt64(enum843::NBIT::HIDEEXCEPTVIEWSELECT), maxon::UInt64(enum843::NBIT::CKEY_WEIGHTEDTANGENT), maxon::UInt64(enum843::NBIT::CKEY_REMOVEOVERSHOOT), maxon::UInt64(enum843::NBIT::CKEY_AUTOWEIGHT), maxon::UInt64(enum843::NBIT::TAKE_LOCK), maxon::UInt64(enum843::NBIT::TAKE_OBJINGROUP), maxon::UInt64(enum843::NBIT::TAKE_EGROUPOVERIDDEN), maxon::UInt64(enum843::NBIT::TAKE_RGROUPOVERIDDEN), maxon::UInt64(enum843::NBIT::CKEY_BREAKDOWNCOLOR), maxon::UInt64(enum843::NBIT::NO_DELETE), maxon::UInt64(enum843::NBIT::LOD_HIDE), maxon::UInt64(enum843::NBIT::LOD_PRIVATECACHE), maxon::UInt64(enum843::NBIT::AHIDE_FOR_HOST), maxon::UInt64(enum843::NBIT::NODE_TEMP), maxon::UInt64(enum843::NBIT::FORBID_COLOR_CONVERSION), maxon::UInt64(enum843::NBIT::TAG_ADDEDTOCACHE), maxon::UInt64(enum843::NBIT::MAX)};
	static const maxon::EnumInfo NBIT_info{"NBIT", SIZEOF(NBIT), false, "NONE\0TL1_FOLD\0TL2_FOLD\0TL3_FOLD\0TL4_FOLD\0TL1_SELECT\0TL2_SELECT\0TL3_SELECT\0TL4_SELECT\0TL1_TDRAW\0TL2_TDRAW\0TL3_TDRAW\0TL4_TDRAW\0CKEY_ACTIVE\0OM1_FOLD\0OM2_FOLD\0OM3_FOLD\0OM4_FOLD\0TL1_FOLDTR\0TL2_FOLDTR\0TL3_FOLDTR\0TL4_FOLDTR\0TL1_FOLDFC\0TL2_FOLDFC\0TL3_FOLDFC\0TL4_FOLDFC\0SOURCEOPEN\0TL1_HIDE\0TL2_HIDE\0TL3_HIDE\0TL4_HIDE\0SOLO_ANIM\0SOLO_LAYER\0TL1_SELECT2\0TL2_SELECT2\0TL3_SELECT2\0TL4_SELECT2\0SOLO_MOTION\0CKEY_LOCK_T\0CKEY_LOCK_V\0CKEY_MUTE\0CKEY_CLAMP\0CKEY_BREAK\0CKEY_KEEPVISUALANGLE\0CKEY_LOCK_O\0CKEY_LOCK_L\0CKEY_AUTO\0CKEY_ZERO_O_OLD\0CKEY_ZERO_L_OLD\0TL1_FCSELECT\0TL2_FCSELECT\0TL3_FCSELECT\0TL4_FCSELECT\0CKEY_BREAKDOWN\0TL1_FOLDMOTION\0TL2_FOLDMOTION\0TL3_FOLDMOTION\0TL4_FOLDMOTION\0TL1_SELECTMOTION\0TL2_SELECTMOTION\0TL3_SELECTMOTION\0TL4_SELECTMOTION\0OHIDE\0TL_TBAKE\0TL1_FOLDSM\0TL2_FOLDSM\0TL3_FOLDSM\0TL4_FOLDSM\0SUBOBJECT\0LINK_ACTIVE\0THIDE\0SUBOBJECT_AM\0PROTECTION\0NOANIM\0NOSELECT\0EHIDE\0REF\0REF_NO_DD\0REF_OHIDE\0NO_DD\0HIDEEXCEPTVIEWSELECT\0CKEY_WEIGHTEDTANGENT\0CKEY_REMOVEOVERSHOOT\0CKEY_AUTOWEIGHT\0TAKE_LOCK\0TAKE_OBJINGROUP\0TAKE_EGROUPOVERIDDEN\0TAKE_RGROUPOVERIDDEN\0CKEY_BREAKDOWNCOLOR\0NO_DELETE\0LOD_HIDE\0LOD_PRIVATECACHE\0AHIDE_FOR_HOST\0NODE_TEMP\0FORBID_COLOR_CONVERSION\0TAG_ADDEDTOCACHE\0MAX\0", NBIT_values, std::extent<decltype(NBIT_values)>::value};
}
const maxon::EnumInfo& PrivateGetEnumInfo_NBIT843(){ return enum843::NBIT_info; }
namespace enum861
{
	enum class CREATEJOBRESULT
	{
		OK							= 0,			///< Ok.
		OUTOFMEMORY			= 1,			///< Out of memory.
		ASSETMISSING		= 2,			///< Asset missing.
		SAVINGFAILED		= 3,			///< Saving failed.
		REPOSITORYERROR	= 4				///< Repository error.
	} ;
	static const maxon::UInt64 CREATEJOBRESULT_values[] = {maxon::UInt64(enum861::CREATEJOBRESULT::OK), maxon::UInt64(enum861::CREATEJOBRESULT::OUTOFMEMORY), maxon::UInt64(enum861::CREATEJOBRESULT::ASSETMISSING), maxon::UInt64(enum861::CREATEJOBRESULT::SAVINGFAILED), maxon::UInt64(enum861::CREATEJOBRESULT::REPOSITORYERROR)};
	static const maxon::EnumInfo CREATEJOBRESULT_info{"CREATEJOBRESULT", SIZEOF(CREATEJOBRESULT), true, "OK\0OUTOFMEMORY\0ASSETMISSING\0SAVINGFAILED\0REPOSITORYERROR\0", CREATEJOBRESULT_values, std::extent<decltype(CREATEJOBRESULT_values)>::value};
}
const maxon::EnumInfo& PrivateGetEnumInfo_CREATEJOBRESULT861(){ return enum861::CREATEJOBRESULT_info; }
namespace enum874
{
	enum class NBITCONTROL
	{
		SET							= 1,				///< Set bit.
		CLEAR						= 2,				///< Clear bit.
		TOGGLE					= 3,				///< Toggle bit.
		PRIVATE_NODIRTY	= 0xf0			///< @markPrivate
	} ;
	static const maxon::UInt64 NBITCONTROL_values[] = {maxon::UInt64(enum874::NBITCONTROL::SET), maxon::UInt64(enum874::NBITCONTROL::CLEAR), maxon::UInt64(enum874::NBITCONTROL::TOGGLE), maxon::UInt64(enum874::NBITCONTROL::PRIVATE_NODIRTY)};
	static const maxon::EnumInfo NBITCONTROL_info{"NBITCONTROL", SIZEOF(NBITCONTROL), true, "SET\0CLEAR\0TOGGLE\0PRIVATE_NODIRTY\0", NBITCONTROL_values, std::extent<decltype(NBITCONTROL_values)>::value};
}
const maxon::EnumInfo& PrivateGetEnumInfo_NBITCONTROL874(){ return enum874::NBITCONTROL_info; }
namespace enum1889
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
	static const maxon::UInt64 VOLUMECOMMANDTYPE_values[] = {maxon::UInt64(enum1889::VOLUMECOMMANDTYPE::NONE), maxon::UInt64(enum1889::VOLUMECOMMANDTYPE::VOLUMETOMESH), maxon::UInt64(enum1889::VOLUMECOMMANDTYPE::MESHTOVOLUME), maxon::UInt64(enum1889::VOLUMECOMMANDTYPE::VOLUMEBOOLE), maxon::UInt64(enum1889::VOLUMECOMMANDTYPE::PARTICLESTOVOLUME), maxon::UInt64(enum1889::VOLUMECOMMANDTYPE::SPLINETOVOLUME), maxon::UInt64(enum1889::VOLUMECOMMANDTYPE::FILTER), maxon::UInt64(enum1889::VOLUMECOMMANDTYPE::SDFFILTER), maxon::UInt64(enum1889::VOLUMECOMMANDTYPE::SDFTOFOG), maxon::UInt64(enum1889::VOLUMECOMMANDTYPE::FOGTOSDF), maxon::UInt64(enum1889::VOLUMECOMMANDTYPE::RESAMPLE), maxon::UInt64(enum1889::VOLUMECOMMANDTYPE::MIX), maxon::UInt64(enum1889::VOLUMECOMMANDTYPE::FIELDTOVOLUME), maxon::UInt64(enum1889::VOLUMECOMMANDTYPE::CREATESPHEREVOLUME), maxon::UInt64(enum1889::VOLUMECOMMANDTYPE::CREATEPLATONICVOLUME)};
	static const maxon::EnumInfo VOLUMECOMMANDTYPE_info{"VOLUMECOMMANDTYPE", SIZEOF(VOLUMECOMMANDTYPE), false, "NONE\0VOLUMETOMESH\0MESHTOVOLUME\0VOLUMEBOOLE\0PARTICLESTOVOLUME\0SPLINETOVOLUME\0FILTER\0SDFFILTER\0SDFTOFOG\0FOGTOSDF\0RESAMPLE\0MIX\0FIELDTOVOLUME\0CREATESPHEREVOLUME\0CREATEPLATONICVOLUME\0", VOLUMECOMMANDTYPE_values, std::extent<decltype(VOLUMECOMMANDTYPE_values)>::value};
}
const maxon::EnumInfo& PrivateGetEnumInfo_VOLUMECOMMANDTYPE1889(){ return enum1889::VOLUMECOMMANDTYPE_info; }
namespace enum1904
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
	static const maxon::UInt64 GRIDTYPE_values[] = {maxon::UInt64(enum1904::GRIDTYPE::NONE), maxon::UInt64(enum1904::GRIDTYPE::FLOAT), maxon::UInt64(enum1904::GRIDTYPE::DOUBLE), maxon::UInt64(enum1904::GRIDTYPE::INT32), maxon::UInt64(enum1904::GRIDTYPE::INT64), maxon::UInt64(enum1904::GRIDTYPE::INTVECTOR32), maxon::UInt64(enum1904::GRIDTYPE::VECTOR32), maxon::UInt64(enum1904::GRIDTYPE::VECTOR64), maxon::UInt64(enum1904::GRIDTYPE::STRING), maxon::UInt64(enum1904::GRIDTYPE::BOOLEAN)};
	static const maxon::EnumInfo GRIDTYPE_info{"GRIDTYPE", SIZEOF(GRIDTYPE), false, "NONE\0FLOAT\0DOUBLE\0INT32\0INT64\0INTVECTOR32\0VECTOR32\0VECTOR64\0STRING\0BOOLEAN\0", GRIDTYPE_values, std::extent<decltype(GRIDTYPE_values)>::value};
}
const maxon::EnumInfo& PrivateGetEnumInfo_GRIDTYPE1904(){ return enum1904::GRIDTYPE_info; }
namespace enum1914
{
	enum class GRIDCLASS
	{
		NONE = 0,
		SDF = 1,
		FOG = 2,
		STAGGERED = 3,
		UNKNOWN = 4
	} ;
	static const maxon::UInt64 GRIDCLASS_values[] = {maxon::UInt64(enum1914::GRIDCLASS::NONE), maxon::UInt64(enum1914::GRIDCLASS::SDF), maxon::UInt64(enum1914::GRIDCLASS::FOG), maxon::UInt64(enum1914::GRIDCLASS::STAGGERED), maxon::UInt64(enum1914::GRIDCLASS::UNKNOWN)};
	static const maxon::EnumInfo GRIDCLASS_info{"GRIDCLASS", SIZEOF(GRIDCLASS), false, "NONE\0SDF\0FOG\0STAGGERED\0UNKNOWN\0", GRIDCLASS_values, std::extent<decltype(GRIDCLASS_values)>::value};
}
const maxon::EnumInfo& PrivateGetEnumInfo_GRIDCLASS1914(){ return enum1914::GRIDCLASS_info; }
namespace enum1924
{
	enum class VECTORGRIDTYPE
	{
		INVARIANT = 0,							// Does not transform (e.g., tuple, uvw, color)
		COVARIANT = 1,							// Apply inverse-transpose transformation: w = 0, ignores translation (e.g., gradient/normal)
		COVARIANT_NORMALIZE = 2,		// Apply inverse-transpose transformation: w = 0, ignores translation, vectors are renormalized (e.g., unit normal)
		CONTRAVARIANT_RELATIVE = 3, // Apply "regular" transformation: w = 0, ignores translation (e.g., displacement, velocity, acceleration)
		CONTRAVARIANT_ABSOLUTE = 4	// Apply "regular" transformation: w = 1, vector translates (e.g., position)
	} ;
	static const maxon::UInt64 VECTORGRIDTYPE_values[] = {maxon::UInt64(enum1924::VECTORGRIDTYPE::INVARIANT), maxon::UInt64(enum1924::VECTORGRIDTYPE::COVARIANT), maxon::UInt64(enum1924::VECTORGRIDTYPE::COVARIANT_NORMALIZE), maxon::UInt64(enum1924::VECTORGRIDTYPE::CONTRAVARIANT_RELATIVE), maxon::UInt64(enum1924::VECTORGRIDTYPE::CONTRAVARIANT_ABSOLUTE)};
	static const maxon::EnumInfo VECTORGRIDTYPE_info{"VECTORGRIDTYPE", SIZEOF(VECTORGRIDTYPE), false, "INVARIANT\0COVARIANT\0COVARIANT_NORMALIZE\0CONTRAVARIANT_RELATIVE\0CONTRAVARIANT_ABSOLUTE\0", VECTORGRIDTYPE_values, std::extent<decltype(VECTORGRIDTYPE_values)>::value};
}
const maxon::EnumInfo& PrivateGetEnumInfo_VECTORGRIDTYPE1924(){ return enum1924::VECTORGRIDTYPE_info; }
namespace enum1939
{
	enum class VOLUMETOMESHSETTINGS
	{
		NONE = 0,
		ISO = 1,				///< ::Float Iso value to extract the mesh at.
		ADAPTIVE = 2		///< ::Float Adaptivity value for curvature based mesh reduction.
	} ;
	static const maxon::UInt64 VOLUMETOMESHSETTINGS_values[] = {maxon::UInt64(enum1939::VOLUMETOMESHSETTINGS::NONE), maxon::UInt64(enum1939::VOLUMETOMESHSETTINGS::ISO), maxon::UInt64(enum1939::VOLUMETOMESHSETTINGS::ADAPTIVE)};
	static const maxon::EnumInfo VOLUMETOMESHSETTINGS_info{"VOLUMETOMESHSETTINGS", SIZEOF(VOLUMETOMESHSETTINGS), false, "NONE\0ISO\0ADAPTIVE\0", VOLUMETOMESHSETTINGS_values, std::extent<decltype(VOLUMETOMESHSETTINGS_values)>::value};
}
const maxon::EnumInfo& PrivateGetEnumInfo_VOLUMETOMESHSETTINGS1939(){ return enum1939::VOLUMETOMESHSETTINGS_info; }
namespace enum1955
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
	static const maxon::UInt64 MESHTOVOLUMESETTINGS_values[] = {maxon::UInt64(enum1955::MESHTOVOLUMESETTINGS::NONE), maxon::UInt64(enum1955::MESHTOVOLUMESETTINGS::GRIDSIZE), maxon::UInt64(enum1955::MESHTOVOLUMESETTINGS::BANDWIDTH_INTERIOR), maxon::UInt64(enum1955::MESHTOVOLUMESETTINGS::BANDWIDTH_EXTERIOR), maxon::UInt64(enum1955::MESHTOVOLUMESETTINGS::USE_POINTS), maxon::UInt64(enum1955::MESHTOVOLUMESETTINGS::RADIUS), maxon::UInt64(enum1955::MESHTOVOLUMESETTINGS::UNSIGNED_DISTANCE_FIELD)};
	static const maxon::EnumInfo MESHTOVOLUMESETTINGS_info{"MESHTOVOLUMESETTINGS", SIZEOF(MESHTOVOLUMESETTINGS), false, "NONE\0GRIDSIZE\0BANDWIDTH_INTERIOR\0BANDWIDTH_EXTERIOR\0USE_POINTS\0RADIUS\0UNSIGNED_DISTANCE_FIELD\0", MESHTOVOLUMESETTINGS_values, std::extent<decltype(MESHTOVOLUMESETTINGS_values)>::value};
}
const maxon::EnumInfo& PrivateGetEnumInfo_MESHTOVOLUMESETTINGS1955(){ return enum1955::MESHTOVOLUMESETTINGS_info; }
namespace enum1971
{
	enum class PARTICLESTOVOLUMESETTINGS
	{
		NONE = 0,
		GRIDSIZE = 1,				///< ::Float Grid voxel cube size.
		BANDWIDTH = 2,			///< ::Int32 Voxel Bandwidth amount around a particle.
		RADIUS = 3,					///< ::Float Radius of the SDF around a particle.
		VELOCITY_SCALE = 4,	///< ::Float Velocity expansion scale.
		USE_PARTICLE_SIZE = 5, 	///< ::Bool If true it overrides the radius with the particle size.
		PARTICLEOFFSET = 6 ///< ::Matrix Extra transform for the particles applied before conversion.
	} ;
	static const maxon::UInt64 PARTICLESTOVOLUMESETTINGS_values[] = {maxon::UInt64(enum1971::PARTICLESTOVOLUMESETTINGS::NONE), maxon::UInt64(enum1971::PARTICLESTOVOLUMESETTINGS::GRIDSIZE), maxon::UInt64(enum1971::PARTICLESTOVOLUMESETTINGS::BANDWIDTH), maxon::UInt64(enum1971::PARTICLESTOVOLUMESETTINGS::RADIUS), maxon::UInt64(enum1971::PARTICLESTOVOLUMESETTINGS::VELOCITY_SCALE), maxon::UInt64(enum1971::PARTICLESTOVOLUMESETTINGS::USE_PARTICLE_SIZE), maxon::UInt64(enum1971::PARTICLESTOVOLUMESETTINGS::PARTICLEOFFSET)};
	static const maxon::EnumInfo PARTICLESTOVOLUMESETTINGS_info{"PARTICLESTOVOLUMESETTINGS", SIZEOF(PARTICLESTOVOLUMESETTINGS), false, "NONE\0GRIDSIZE\0BANDWIDTH\0RADIUS\0VELOCITY_SCALE\0USE_PARTICLE_SIZE\0PARTICLEOFFSET\0", PARTICLESTOVOLUMESETTINGS_values, std::extent<decltype(PARTICLESTOVOLUMESETTINGS_values)>::value};
}
const maxon::EnumInfo& PrivateGetEnumInfo_PARTICLESTOVOLUMESETTINGS1971(){ return enum1971::PARTICLESTOVOLUMESETTINGS_info; }
namespace enum1986
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
	static const maxon::UInt64 SPLINETOVOLUMESETTINGS_values[] = {maxon::UInt64(enum1986::SPLINETOVOLUMESETTINGS::NONE), maxon::UInt64(enum1986::SPLINETOVOLUMESETTINGS::GRIDSIZE), maxon::UInt64(enum1986::SPLINETOVOLUMESETTINGS::BANDWIDTH), maxon::UInt64(enum1986::SPLINETOVOLUMESETTINGS::RADIUS), maxon::UInt64(enum1986::SPLINETOVOLUMESETTINGS::DENSITY), maxon::UInt64(enum1986::SPLINETOVOLUMESETTINGS::SCALESEGMENT)};
	static const maxon::EnumInfo SPLINETOVOLUMESETTINGS_info{"SPLINETOVOLUMESETTINGS", SIZEOF(SPLINETOVOLUMESETTINGS), false, "NONE\0GRIDSIZE\0BANDWIDTH\0RADIUS\0DENSITY\0SCALESEGMENT\0", SPLINETOVOLUMESETTINGS_values, std::extent<decltype(SPLINETOVOLUMESETTINGS_values)>::value};
}
const maxon::EnumInfo& PrivateGetEnumInfo_SPLINETOVOLUMESETTINGS1986(){ return enum1986::SPLINETOVOLUMESETTINGS_info; }
namespace enum2008
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
	static const maxon::UInt64 FILTERSETTINGS_values[] = {maxon::UInt64(enum2008::FILTERSETTINGS::NONE), maxon::UInt64(enum2008::FILTERSETTINGS::FILTERTYPE), maxon::UInt64(enum2008::FILTERSETTINGS::ITERATIONS), maxon::UInt64(enum2008::FILTERSETTINGS::RADIUS), maxon::UInt64(enum2008::FILTERSETTINGS::OFFSET), maxon::UInt64(enum2008::FILTERSETTINGS::FALLOFF), maxon::UInt64(enum2008::FILTERSETTINGS::REMAP_OLD_MIN), maxon::UInt64(enum2008::FILTERSETTINGS::REMAP_OLD_MAX), maxon::UInt64(enum2008::FILTERSETTINGS::REMAP_NEW_MIN), maxon::UInt64(enum2008::FILTERSETTINGS::REMAP_NEW_MAX), maxon::UInt64(enum2008::FILTERSETTINGS::STRENGTH), maxon::UInt64(enum2008::FILTERSETTINGS::SPLINE), maxon::UInt64(enum2008::FILTERSETTINGS::INVERTPOINT)};
	static const maxon::EnumInfo FILTERSETTINGS_info{"FILTERSETTINGS", SIZEOF(FILTERSETTINGS), false, "NONE\0FILTERTYPE\0ITERATIONS\0RADIUS\0OFFSET\0FALLOFF\0REMAP_OLD_MIN\0REMAP_OLD_MAX\0REMAP_NEW_MIN\0REMAP_NEW_MAX\0STRENGTH\0SPLINE\0INVERTPOINT\0", FILTERSETTINGS_values, std::extent<decltype(FILTERSETTINGS_values)>::value};
}
const maxon::EnumInfo& PrivateGetEnumInfo_FILTERSETTINGS2008(){ return enum2008::FILTERSETTINGS_info; }
namespace enum2026
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
	static const maxon::UInt64 SDFFILTERSETTINGS_values[] = {maxon::UInt64(enum2026::SDFFILTERSETTINGS::NONE), maxon::UInt64(enum2026::SDFFILTERSETTINGS::FILTERTYPE), maxon::UInt64(enum2026::SDFFILTERSETTINGS::ITERATIONS), maxon::UInt64(enum2026::SDFFILTERSETTINGS::STENCILWIDTH), maxon::UInt64(enum2026::SDFFILTERSETTINGS::FILTERACCURACY), maxon::UInt64(enum2026::SDFFILTERSETTINGS::OFFSET), maxon::UInt64(enum2026::SDFFILTERSETTINGS::HALFWIDTH), maxon::UInt64(enum2026::SDFFILTERSETTINGS::FALLOFF), maxon::UInt64(enum2026::SDFFILTERSETTINGS::STRENGTH)};
	static const maxon::EnumInfo SDFFILTERSETTINGS_info{"SDFFILTERSETTINGS", SIZEOF(SDFFILTERSETTINGS), false, "NONE\0FILTERTYPE\0ITERATIONS\0STENCILWIDTH\0FILTERACCURACY\0OFFSET\0HALFWIDTH\0FALLOFF\0STRENGTH\0", SDFFILTERSETTINGS_values, std::extent<decltype(SDFFILTERSETTINGS_values)>::value};
}
const maxon::EnumInfo& PrivateGetEnumInfo_SDFFILTERSETTINGS2026(){ return enum2026::SDFFILTERSETTINGS_info; }
namespace enum2038
{
	enum class BOOLESETTINGS
	{
		NONE = 0,
		BOOLETYPE = 1,				///< ::Int32 The Boole type (union, difference, intersection).
		SMOOTHRADIUS = 2			///< ::Float The radius for the boolean.
	} ;
	static const maxon::UInt64 BOOLESETTINGS_values[] = {maxon::UInt64(enum2038::BOOLESETTINGS::NONE), maxon::UInt64(enum2038::BOOLESETTINGS::BOOLETYPE), maxon::UInt64(enum2038::BOOLESETTINGS::SMOOTHRADIUS)};
	static const maxon::EnumInfo BOOLESETTINGS_info{"BOOLESETTINGS", SIZEOF(BOOLESETTINGS), false, "NONE\0BOOLETYPE\0SMOOTHRADIUS\0", BOOLESETTINGS_values, std::extent<decltype(BOOLESETTINGS_values)>::value};
}
const maxon::EnumInfo& PrivateGetEnumInfo_BOOLESETTINGS2038(){ return enum2038::BOOLESETTINGS_info; }
namespace enum2051
{
	enum class BOOLTYPE
	{
		NONE = 0,
		UNION = 1,
		DIFF = 2,
		INTERSECT = 3,
	} ;
	static const maxon::UInt64 BOOLTYPE_values[] = {maxon::UInt64(enum2051::BOOLTYPE::NONE), maxon::UInt64(enum2051::BOOLTYPE::UNION), maxon::UInt64(enum2051::BOOLTYPE::DIFF), maxon::UInt64(enum2051::BOOLTYPE::INTERSECT)};
	static const maxon::EnumInfo BOOLTYPE_info{"BOOLTYPE", SIZEOF(BOOLTYPE), false, "NONE\0UNION\0DIFF\0INTERSECT\0", BOOLTYPE_values, std::extent<decltype(BOOLTYPE_values)>::value};
}
const maxon::EnumInfo& PrivateGetEnumInfo_BOOLTYPE2051(){ return enum2051::BOOLTYPE_info; }
namespace enum2062
{
	enum class MIXSETTINGS
	{
		NONE = 0,
		MIXTYPE = 1				///< ::Int32 The Mix type (Normal, Max, Mix, Add, Subtract, Multiply, Divide).
	} ;
	static const maxon::UInt64 MIXSETTINGS_values[] = {maxon::UInt64(enum2062::MIXSETTINGS::NONE), maxon::UInt64(enum2062::MIXSETTINGS::MIXTYPE)};
	static const maxon::EnumInfo MIXSETTINGS_info{"MIXSETTINGS", SIZEOF(MIXSETTINGS), false, "NONE\0MIXTYPE\0", MIXSETTINGS_values, std::extent<decltype(MIXSETTINGS_values)>::value};
}
const maxon::EnumInfo& PrivateGetEnumInfo_MIXSETTINGS2062(){ return enum2062::MIXSETTINGS_info; }
namespace enum2079
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
	static const maxon::UInt64 MIXTYPE_values[] = {maxon::UInt64(enum2079::MIXTYPE::NONE), maxon::UInt64(enum2079::MIXTYPE::NORMAL), maxon::UInt64(enum2079::MIXTYPE::MAX), maxon::UInt64(enum2079::MIXTYPE::MIN), maxon::UInt64(enum2079::MIXTYPE::ADD), maxon::UInt64(enum2079::MIXTYPE::SUBTRACT), maxon::UInt64(enum2079::MIXTYPE::MULTIPLY), maxon::UInt64(enum2079::MIXTYPE::DIVIDE)};
	static const maxon::EnumInfo MIXTYPE_info{"MIXTYPE", SIZEOF(MIXTYPE), false, "NONE\0NORMAL\0MAX\0MIN\0ADD\0SUBTRACT\0MULTIPLY\0DIVIDE\0", MIXTYPE_values, std::extent<decltype(MIXTYPE_values)>::value};
}
const maxon::EnumInfo& PrivateGetEnumInfo_MIXTYPE2079(){ return enum2079::MIXTYPE_info; }
namespace enum2090
{
	enum class SDFTOFOGSETTINGS
	{
		NONE = 0,
		FALLOFFCUTOFF = 1				///< ::Float Distance for the falloff from the surface.
	} ;
	static const maxon::UInt64 SDFTOFOGSETTINGS_values[] = {maxon::UInt64(enum2090::SDFTOFOGSETTINGS::NONE), maxon::UInt64(enum2090::SDFTOFOGSETTINGS::FALLOFFCUTOFF)};
	static const maxon::EnumInfo SDFTOFOGSETTINGS_info{"SDFTOFOGSETTINGS", SIZEOF(SDFTOFOGSETTINGS), false, "NONE\0FALLOFFCUTOFF\0", SDFTOFOGSETTINGS_values, std::extent<decltype(SDFTOFOGSETTINGS_values)>::value};
}
const maxon::EnumInfo& PrivateGetEnumInfo_SDFTOFOGSETTINGS2090(){ return enum2090::SDFTOFOGSETTINGS_info; }
namespace enum2101
{
	enum class FOGTOSDFSETTINGS
	{
		NONE = 0,
		ISO = 1				///< ::Float Iso value to extract the SDF at.
	} ;
	static const maxon::UInt64 FOGTOSDFSETTINGS_values[] = {maxon::UInt64(enum2101::FOGTOSDFSETTINGS::NONE), maxon::UInt64(enum2101::FOGTOSDFSETTINGS::ISO)};
	static const maxon::EnumInfo FOGTOSDFSETTINGS_info{"FOGTOSDFSETTINGS", SIZEOF(FOGTOSDFSETTINGS), false, "NONE\0ISO\0", FOGTOSDFSETTINGS_values, std::extent<decltype(FOGTOSDFSETTINGS_values)>::value};
}
const maxon::EnumInfo& PrivateGetEnumInfo_FOGTOSDFSETTINGS2101(){ return enum2101::FOGTOSDFSETTINGS_info; }
namespace enum2113
{
	enum class RESAMPLESETTINGS
	{
		NONE = 0,
		GRIDSIZE = 1,						///< ::Float New grid voxel cube size.
		INTERPOLATIONTYPE = 2		///< ::Int32 The Interpolation type (nearest, linear, quadratic).
	} ;
	static const maxon::UInt64 RESAMPLESETTINGS_values[] = {maxon::UInt64(enum2113::RESAMPLESETTINGS::NONE), maxon::UInt64(enum2113::RESAMPLESETTINGS::GRIDSIZE), maxon::UInt64(enum2113::RESAMPLESETTINGS::INTERPOLATIONTYPE)};
	static const maxon::EnumInfo RESAMPLESETTINGS_info{"RESAMPLESETTINGS", SIZEOF(RESAMPLESETTINGS), false, "NONE\0GRIDSIZE\0INTERPOLATIONTYPE\0", RESAMPLESETTINGS_values, std::extent<decltype(RESAMPLESETTINGS_values)>::value};
}
const maxon::EnumInfo& PrivateGetEnumInfo_RESAMPLESETTINGS2113(){ return enum2113::RESAMPLESETTINGS_info; }
namespace enum2126
{
	enum class RESAMPLEINTERPOLATIONTYPE
	{
		NONE = 0,
		NEAREST = 1,
		LINEAR = 2,
		QUADRATIC = 3
	} ;
	static const maxon::UInt64 RESAMPLEINTERPOLATIONTYPE_values[] = {maxon::UInt64(enum2126::RESAMPLEINTERPOLATIONTYPE::NONE), maxon::UInt64(enum2126::RESAMPLEINTERPOLATIONTYPE::NEAREST), maxon::UInt64(enum2126::RESAMPLEINTERPOLATIONTYPE::LINEAR), maxon::UInt64(enum2126::RESAMPLEINTERPOLATIONTYPE::QUADRATIC)};
	static const maxon::EnumInfo RESAMPLEINTERPOLATIONTYPE_info{"RESAMPLEINTERPOLATIONTYPE", SIZEOF(RESAMPLEINTERPOLATIONTYPE), false, "NONE\0NEAREST\0LINEAR\0QUADRATIC\0", RESAMPLEINTERPOLATIONTYPE_values, std::extent<decltype(RESAMPLEINTERPOLATIONTYPE_values)>::value};
}
const maxon::EnumInfo& PrivateGetEnumInfo_RESAMPLEINTERPOLATIONTYPE2126(){ return enum2126::RESAMPLEINTERPOLATIONTYPE_info; }
namespace enum2139
{
	enum class FIELDTOVOLUMESETTINGS
	{
		NONE = 0,
		BOUNDINGBOXMIN = 1,	///< ::Vector The lower left point of the boundingbox.
		BOUNDINGBOXMAX = 2,	///< ::Vector The upper right point of the boundingbox.
		GRIDSIZE = 3,				///< ::Float Grid voxel cube size.
	} ;
	static const maxon::UInt64 FIELDTOVOLUMESETTINGS_values[] = {maxon::UInt64(enum2139::FIELDTOVOLUMESETTINGS::NONE), maxon::UInt64(enum2139::FIELDTOVOLUMESETTINGS::BOUNDINGBOXMIN), maxon::UInt64(enum2139::FIELDTOVOLUMESETTINGS::BOUNDINGBOXMAX), maxon::UInt64(enum2139::FIELDTOVOLUMESETTINGS::GRIDSIZE)};
	static const maxon::EnumInfo FIELDTOVOLUMESETTINGS_info{"FIELDTOVOLUMESETTINGS", SIZEOF(FIELDTOVOLUMESETTINGS), false, "NONE\0BOUNDINGBOXMIN\0BOUNDINGBOXMAX\0GRIDSIZE\0", FIELDTOVOLUMESETTINGS_values, std::extent<decltype(FIELDTOVOLUMESETTINGS_values)>::value};
}
const maxon::EnumInfo& PrivateGetEnumInfo_FIELDTOVOLUMESETTINGS2139(){ return enum2139::FIELDTOVOLUMESETTINGS_info; }
namespace enum2153
{
	enum class CREATESPHEREVOLUMESETTINGS
	{
		NONE = 0,
		RADIUS = 1,					///< ::Float The radius of the sphere.
		POSITION = 2,				///< ::Vector The world position of the sphere.
		BANDWIDTH = 3,			///< ::Int32 Voxel Bandwidth amount around a sphere.
		GRIDSIZE = 4,				///< ::Float Grid voxel cube size.
	} ;
	static const maxon::UInt64 CREATESPHEREVOLUMESETTINGS_values[] = {maxon::UInt64(enum2153::CREATESPHEREVOLUMESETTINGS::NONE), maxon::UInt64(enum2153::CREATESPHEREVOLUMESETTINGS::RADIUS), maxon::UInt64(enum2153::CREATESPHEREVOLUMESETTINGS::POSITION), maxon::UInt64(enum2153::CREATESPHEREVOLUMESETTINGS::BANDWIDTH), maxon::UInt64(enum2153::CREATESPHEREVOLUMESETTINGS::GRIDSIZE)};
	static const maxon::EnumInfo CREATESPHEREVOLUMESETTINGS_info{"CREATESPHEREVOLUMESETTINGS", SIZEOF(CREATESPHEREVOLUMESETTINGS), false, "NONE\0RADIUS\0POSITION\0BANDWIDTH\0GRIDSIZE\0", CREATESPHEREVOLUMESETTINGS_values, std::extent<decltype(CREATESPHEREVOLUMESETTINGS_values)>::value};
}
const maxon::EnumInfo& PrivateGetEnumInfo_CREATESPHEREVOLUMESETTINGS2153(){ return enum2153::CREATESPHEREVOLUMESETTINGS_info; }
namespace enum2168
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
	static const maxon::UInt64 CREATEPLATONICVOLUMESETTINGS_values[] = {maxon::UInt64(enum2168::CREATEPLATONICVOLUMESETTINGS::NONE), maxon::UInt64(enum2168::CREATEPLATONICVOLUMESETTINGS::FACES), maxon::UInt64(enum2168::CREATEPLATONICVOLUMESETTINGS::SIZE), maxon::UInt64(enum2168::CREATEPLATONICVOLUMESETTINGS::POSITION), maxon::UInt64(enum2168::CREATEPLATONICVOLUMESETTINGS::BANDWIDTH), maxon::UInt64(enum2168::CREATEPLATONICVOLUMESETTINGS::GRIDSIZE)};
	static const maxon::EnumInfo CREATEPLATONICVOLUMESETTINGS_info{"CREATEPLATONICVOLUMESETTINGS", SIZEOF(CREATEPLATONICVOLUMESETTINGS), false, "NONE\0FACES\0SIZE\0POSITION\0BANDWIDTH\0GRIDSIZE\0", CREATEPLATONICVOLUMESETTINGS_values, std::extent<decltype(CREATEPLATONICVOLUMESETTINGS_values)>::value};
}
const maxon::EnumInfo& PrivateGetEnumInfo_CREATEPLATONICVOLUMESETTINGS2168(){ return enum2168::CREATEPLATONICVOLUMESETTINGS_info; }
namespace enum2778
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
	static const maxon::UInt64 EVENT_values[] = {maxon::UInt64(enum2778::EVENT::NONE), maxon::UInt64(enum2778::EVENT::FORCEREDRAW), maxon::UInt64(enum2778::EVENT::ANIMATE), maxon::UInt64(enum2778::EVENT::NOEXPRESSION), maxon::UInt64(enum2778::EVENT::GLHACK), maxon::UInt64(enum2778::EVENT::CAMERAEXPRESSION), maxon::UInt64(enum2778::EVENT::ENQUEUE_REDRAW), maxon::UInt64(enum2778::EVENT::DONT_OVERWRITE_RENDERING)};
	static const maxon::EnumInfo EVENT_info{"EVENT", SIZEOF(EVENT), true, "NONE\0FORCEREDRAW\0ANIMATE\0NOEXPRESSION\0GLHACK\0CAMERAEXPRESSION\0ENQUEUE_REDRAW\0DONT_OVERWRITE_RENDERING\0", EVENT_values, std::extent<decltype(EVENT_values)>::value};
}
const maxon::EnumInfo& PrivateGetEnumInfo_EVENT2778(){ return enum2778::EVENT_info; }
namespace enum2812
{
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
	} ;
	static const maxon::UInt64 DRAWFLAGS_values[] = {maxon::UInt64(enum2812::DRAWFLAGS::NONE), maxon::UInt64(enum2812::DRAWFLAGS::NO_THREAD), maxon::UInt64(enum2812::DRAWFLAGS::NO_ANIMATION), maxon::UInt64(enum2812::DRAWFLAGS::ONLY_ACTIVE_VIEW), maxon::UInt64(enum2812::DRAWFLAGS::NO_EXPRESSIONS), maxon::UInt64(enum2812::DRAWFLAGS::INDRAG), maxon::UInt64(enum2812::DRAWFLAGS::NO_HIGHLIGHT_PLANE), maxon::UInt64(enum2812::DRAWFLAGS::FORCEFULLREDRAW), maxon::UInt64(enum2812::DRAWFLAGS::ONLY_CAMERAEXPRESSION), maxon::UInt64(enum2812::DRAWFLAGS::INMOVE), maxon::UInt64(enum2812::DRAWFLAGS::ONLY_BASEDRAW), maxon::UInt64(enum2812::DRAWFLAGS::ONLY_HIGHLIGHT), maxon::UInt64(enum2812::DRAWFLAGS::STATICBREAK), maxon::UInt64(enum2812::DRAWFLAGS::NO_PRESENT), maxon::UInt64(enum2812::DRAWFLAGS::PRIVATE_NO_WAIT_GL_FINISHED), maxon::UInt64(enum2812::DRAWFLAGS::PRIVATE_ONLYBACKGROUND), maxon::UInt64(enum2812::DRAWFLAGS::PRIVATE_NOBLIT), maxon::UInt64(enum2812::DRAWFLAGS::PRIVATE_OPENGLHACK), maxon::UInt64(enum2812::DRAWFLAGS::PRIVATE_ONLY_PREPARE), maxon::UInt64(enum2812::DRAWFLAGS::PRIVATE_NO_3DCLIPPING), maxon::UInt64(enum2812::DRAWFLAGS::DONT_OVERWRITE_RENDERING), maxon::UInt64(enum2812::DRAWFLAGS::SKIP_IF_THREADED_DRAW_ACTIVE), maxon::UInt64(enum2812::DRAWFLAGS::DRAW_WITH_BLOCKED_INTERACTION), maxon::UInt64(enum2812::DRAWFLAGS::SELECTION_ONLY), maxon::UInt64(enum2812::DRAWFLAGS::BUILD_AS_EXTERNALRENDERER)};
	static const maxon::EnumInfo DRAWFLAGS_info{"DRAWFLAGS", SIZEOF(DRAWFLAGS), true, "NONE\0NO_THREAD\0NO_ANIMATION\0ONLY_ACTIVE_VIEW\0NO_EXPRESSIONS\0INDRAG\0NO_HIGHLIGHT_PLANE\0FORCEFULLREDRAW\0ONLY_CAMERAEXPRESSION\0INMOVE\0ONLY_BASEDRAW\0ONLY_HIGHLIGHT\0STATICBREAK\0NO_PRESENT\0PRIVATE_NO_WAIT_GL_FINISHED\0PRIVATE_ONLYBACKGROUND\0PRIVATE_NOBLIT\0PRIVATE_OPENGLHACK\0PRIVATE_ONLY_PREPARE\0PRIVATE_NO_3DCLIPPING\0DONT_OVERWRITE_RENDERING\0SKIP_IF_THREADED_DRAW_ACTIVE\0DRAW_WITH_BLOCKED_INTERACTION\0SELECTION_ONLY\0BUILD_AS_EXTERNALRENDERER\0", DRAWFLAGS_values, std::extent<decltype(DRAWFLAGS_values)>::value};
}
const maxon::EnumInfo& PrivateGetEnumInfo_DRAWFLAGS2812(){ return enum2812::DRAWFLAGS_info; }
namespace enum2827
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
	static const maxon::UInt64 ANIMATEFLAGS_values[] = {maxon::UInt64(enum2827::ANIMATEFLAGS::NONE), maxon::UInt64(enum2827::ANIMATEFLAGS::NO_PARTICLES), maxon::UInt64(enum2827::ANIMATEFLAGS::NO_CHILDREN), maxon::UInt64(enum2827::ANIMATEFLAGS::INRENDER), maxon::UInt64(enum2827::ANIMATEFLAGS::NO_MINMAX), maxon::UInt64(enum2827::ANIMATEFLAGS::NO_NLA), maxon::UInt64(enum2827::ANIMATEFLAGS::NLA_SUM)};
	static const maxon::EnumInfo ANIMATEFLAGS_info{"ANIMATEFLAGS", SIZEOF(ANIMATEFLAGS), true, "NONE\0NO_PARTICLES\0NO_CHILDREN\0INRENDER\0NO_MINMAX\0NO_NLA\0NLA_SUM\0", ANIMATEFLAGS_values, std::extent<decltype(ANIMATEFLAGS_values)>::value};
}
const maxon::EnumInfo& PrivateGetEnumInfo_ANIMATEFLAGS2827(){ return enum2827::ANIMATEFLAGS_info; }
namespace enum2846
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
	static const maxon::UInt64 SAVEDOCUMENTFLAGS_values[] = {maxon::UInt64(enum2846::SAVEDOCUMENTFLAGS::NONE), maxon::UInt64(enum2846::SAVEDOCUMENTFLAGS::DIALOGSALLOWED), maxon::UInt64(enum2846::SAVEDOCUMENTFLAGS::SAVEAS), maxon::UInt64(enum2846::SAVEDOCUMENTFLAGS::DONTADDTORECENTLIST), maxon::UInt64(enum2846::SAVEDOCUMENTFLAGS::AUTOSAVE), maxon::UInt64(enum2846::SAVEDOCUMENTFLAGS::SAVECACHES), maxon::UInt64(enum2846::SAVEDOCUMENTFLAGS::EXPORTDIALOG), maxon::UInt64(enum2846::SAVEDOCUMENTFLAGS::CRASHSITUATION), maxon::UInt64(enum2846::SAVEDOCUMENTFLAGS::NO_SHADERCACHE)};
	static const maxon::EnumInfo SAVEDOCUMENTFLAGS_info{"SAVEDOCUMENTFLAGS", SIZEOF(SAVEDOCUMENTFLAGS), true, "NONE\0DIALOGSALLOWED\0SAVEAS\0DONTADDTORECENTLIST\0AUTOSAVE\0SAVECACHES\0EXPORTDIALOG\0CRASHSITUATION\0NO_SHADERCACHE\0", SAVEDOCUMENTFLAGS_values, std::extent<decltype(SAVEDOCUMENTFLAGS_values)>::value};
}
const maxon::EnumInfo& PrivateGetEnumInfo_SAVEDOCUMENTFLAGS2846(){ return enum2846::SAVEDOCUMENTFLAGS_info; }
namespace enum2885
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
		PRIVATE_FASTCOPYFROMPARENT				= (1 << 28),			///< @markPrivate
		PRIVATE_BODYPAINT_NODATA					= (1 << 29),			///< @markPrivate
		PRIVATE_BODYPAINT_CONVERTLAYER		= (1 << 30),			///< @markPrivate
		WITH_MODIFIED_MATRIX							= (1 << 31)				///< Activates to copy the modified matrix of an object.
	} ;
	static const maxon::UInt64 COPYFLAGS_values[] = {maxon::UInt64(enum2885::COPYFLAGS::NONE), maxon::UInt64(enum2885::COPYFLAGS::NO_HIERARCHY), maxon::UInt64(enum2885::COPYFLAGS::NO_ANIMATION), maxon::UInt64(enum2885::COPYFLAGS::NO_BITS), maxon::UInt64(enum2885::COPYFLAGS::NO_MATERIALPREVIEW), maxon::UInt64(enum2885::COPYFLAGS::NO_BRANCHES), maxon::UInt64(enum2885::COPYFLAGS::DOCUMENT), maxon::UInt64(enum2885::COPYFLAGS::NO_NGONS), maxon::UInt64(enum2885::COPYFLAGS::CACHE_BUILD), maxon::UInt64(enum2885::COPYFLAGS::RECURSIONCHECK), maxon::UInt64(enum2885::COPYFLAGS::PRIVATE_IDENTMARKER), maxon::UInt64(enum2885::COPYFLAGS::PRIVATE_NO_INTERNALS), maxon::UInt64(enum2885::COPYFLAGS::PRIVATE_NO_PLUGINLAYER), maxon::UInt64(enum2885::COPYFLAGS::PRIVATE_UNDO), maxon::UInt64(enum2885::COPYFLAGS::PRIVATE_CONTAINER_COPY_DIRTY), maxon::UInt64(enum2885::COPYFLAGS::PRIVATE_CONTAINER_COPY_IDENTICAL), maxon::UInt64(enum2885::COPYFLAGS::PRIVATE_NO_TAGS), maxon::UInt64(enum2885::COPYFLAGS::PRIVATE_DELETE), maxon::UInt64(enum2885::COPYFLAGS::PRIVATE_CLIPBOARD_COPY), maxon::UInt64(enum2885::COPYFLAGS::PRIVATE_NO_ASSETS), maxon::UInt64(enum2885::COPYFLAGS::PRIVATE_NO_RESULTASSETS), maxon::UInt64(enum2885::COPYFLAGS::PRIVATE_NO_LOGS), maxon::UInt64(enum2885::COPYFLAGS::PRIVATE_RENDER), maxon::UInt64(enum2885::COPYFLAGS::PRIVATE_MOGRAPH_CLONE), maxon::UInt64(enum2885::COPYFLAGS::PRIVATE_FASTCOPYFROMPARENT), maxon::UInt64(enum2885::COPYFLAGS::PRIVATE_BODYPAINT_NODATA), maxon::UInt64(enum2885::COPYFLAGS::PRIVATE_BODYPAINT_CONVERTLAYER), maxon::UInt64(enum2885::COPYFLAGS::WITH_MODIFIED_MATRIX)};
	static const maxon::EnumInfo COPYFLAGS_info{"COPYFLAGS", SIZEOF(COPYFLAGS), true, "NONE\0NO_HIERARCHY\0NO_ANIMATION\0NO_BITS\0NO_MATERIALPREVIEW\0NO_BRANCHES\0DOCUMENT\0NO_NGONS\0CACHE_BUILD\0RECURSIONCHECK\0PRIVATE_IDENTMARKER\0PRIVATE_NO_INTERNALS\0PRIVATE_NO_PLUGINLAYER\0PRIVATE_UNDO\0PRIVATE_CONTAINER_COPY_DIRTY\0PRIVATE_CONTAINER_COPY_IDENTICAL\0PRIVATE_NO_TAGS\0PRIVATE_DELETE\0PRIVATE_CLIPBOARD_COPY\0PRIVATE_NO_ASSETS\0PRIVATE_NO_RESULTASSETS\0PRIVATE_NO_LOGS\0PRIVATE_RENDER\0PRIVATE_MOGRAPH_CLONE\0PRIVATE_FASTCOPYFROMPARENT\0PRIVATE_BODYPAINT_NODATA\0PRIVATE_BODYPAINT_CONVERTLAYER\0WITH_MODIFIED_MATRIX\0", COPYFLAGS_values, std::extent<decltype(COPYFLAGS_values)>::value};
}
const maxon::EnumInfo& PrivateGetEnumInfo_COPYFLAGS2885(){ return enum2885::COPYFLAGS_info; }
namespace enum2915
{
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
	} ;
	static const maxon::UInt64 UNDOTYPE_values[] = {maxon::UInt64(enum2915::UNDOTYPE::NONE), maxon::UInt64(enum2915::UNDOTYPE::CHANGE), maxon::UInt64(enum2915::UNDOTYPE::CHANGE_NOCHILDREN), maxon::UInt64(enum2915::UNDOTYPE::CHANGE_SMALL), maxon::UInt64(enum2915::UNDOTYPE::CHANGE_SELECTION), maxon::UInt64(enum2915::UNDOTYPE::NEWOBJ), maxon::UInt64(enum2915::UNDOTYPE::DELETEOBJ), maxon::UInt64(enum2915::UNDOTYPE::ACTIVATE), maxon::UInt64(enum2915::UNDOTYPE::DEACTIVATE), maxon::UInt64(enum2915::UNDOTYPE::BITS), maxon::UInt64(enum2915::UNDOTYPE::HIERARCHY_PSR), maxon::UInt64(enum2915::UNDOTYPE::PRIVATE_STRING), maxon::UInt64(enum2915::UNDOTYPE::PRIVATE_MULTISELECTIONAXIS), maxon::UInt64(enum2915::UNDOTYPE::START), maxon::UInt64(enum2915::UNDOTYPE::END)};
	static const maxon::EnumInfo UNDOTYPE_info{"UNDOTYPE", SIZEOF(UNDOTYPE), false, "NONE\0CHANGE\0CHANGE_NOCHILDREN\0CHANGE_SMALL\0CHANGE_SELECTION\0NEWOBJ\0DELETEOBJ\0ACTIVATE\0DEACTIVATE\0BITS\0HIERARCHY_PSR\0PRIVATE_STRING\0PRIVATE_MULTISELECTIONAXIS\0START\0END\0", UNDOTYPE_values, std::extent<decltype(UNDOTYPE_values)>::value};
}
const maxon::EnumInfo& PrivateGetEnumInfo_UNDOTYPE2915(){ return enum2915::UNDOTYPE_info; }
namespace enum2932
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
	static const maxon::UInt64 DRAWHANDLE_values[] = {maxon::UInt64(enum2932::DRAWHANDLE::MINI), maxon::UInt64(enum2932::DRAWHANDLE::SMALL), maxon::UInt64(enum2932::DRAWHANDLE::MIDDLE), maxon::UInt64(enum2932::DRAWHANDLE::BIG), maxon::UInt64(enum2932::DRAWHANDLE::CUSTOM), maxon::UInt64(enum2932::DRAWHANDLE::POINTSIZE), maxon::UInt64(enum2932::DRAWHANDLE::SELPOINTSIZE)};
	static const maxon::EnumInfo DRAWHANDLE_info{"DRAWHANDLE", SIZEOF(DRAWHANDLE), false, "MINI\0SMALL\0MIDDLE\0BIG\0CUSTOM\0POINTSIZE\0SELPOINTSIZE\0", DRAWHANDLE_values, std::extent<decltype(DRAWHANDLE_values)>::value};
}
const maxon::EnumInfo& PrivateGetEnumInfo_DRAWHANDLE2932(){ return enum2932::DRAWHANDLE_info; }
namespace enum2945
{
	enum class DRAW_ALPHA
	{
		NONE								= 10,			///< No alpha.
		INVERTED						= 11,			///< Generates inverted alpha.
		NORMAL							= 12,			///< Generates alpha channel from the image's alpha channel. If no alpha channel exists, the alpha value is set to @em 100%.
		FROM_IMAGE					= 13,			///< Generates the alpha channel from the RGB image information.
		NORMAL_FROM_IMAGE		= 14			///< Generates alpha channel from the image's alpha channel. If no alpha channel exists, the alpha value is generated from the RGB image.
	} ;
	static const maxon::UInt64 DRAW_ALPHA_values[] = {maxon::UInt64(enum2945::DRAW_ALPHA::NONE), maxon::UInt64(enum2945::DRAW_ALPHA::INVERTED), maxon::UInt64(enum2945::DRAW_ALPHA::NORMAL), maxon::UInt64(enum2945::DRAW_ALPHA::FROM_IMAGE), maxon::UInt64(enum2945::DRAW_ALPHA::NORMAL_FROM_IMAGE)};
	static const maxon::EnumInfo DRAW_ALPHA_info{"DRAW_ALPHA", SIZEOF(DRAW_ALPHA), false, "NONE\0INVERTED\0NORMAL\0FROM_IMAGE\0NORMAL_FROM_IMAGE\0", DRAW_ALPHA_values, std::extent<decltype(DRAW_ALPHA_values)>::value};
}
const maxon::EnumInfo& PrivateGetEnumInfo_DRAW_ALPHA2945(){ return enum2945::DRAW_ALPHA_info; }
namespace enum2972
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
	static const maxon::UInt64 DRAW_TEXTUREFLAGS_values[] = {maxon::UInt64(enum2972::DRAW_TEXTUREFLAGS::NONE), maxon::UInt64(enum2972::DRAW_TEXTUREFLAGS::COLOR_IMAGE_TO_LINEAR), maxon::UInt64(enum2972::DRAW_TEXTUREFLAGS::COLOR_SRGB_TO_LINEAR), maxon::UInt64(enum2972::DRAW_TEXTUREFLAGS::COLOR_IMAGE_TO_SRGB), maxon::UInt64(enum2972::DRAW_TEXTUREFLAGS::COLOR_LINEAR_TO_SRGB), maxon::UInt64(enum2972::DRAW_TEXTUREFLAGS::COLOR_CORRECTION_MASK), maxon::UInt64(enum2972::DRAW_TEXTUREFLAGS::USE_PROFILE_COLOR), maxon::UInt64(enum2972::DRAW_TEXTUREFLAGS::ALLOW_FLOATINGPOINT), maxon::UInt64(enum2972::DRAW_TEXTUREFLAGS::TILE), maxon::UInt64(enum2972::DRAW_TEXTUREFLAGS::TEMPORARY), maxon::UInt64(enum2972::DRAW_TEXTUREFLAGS::INTERPOLATION_NEAREST), maxon::UInt64(enum2972::DRAW_TEXTUREFLAGS::INTERPOLATION_LINEAR), maxon::UInt64(enum2972::DRAW_TEXTUREFLAGS::INTERPOLATION_LINEAR_MIPMAP), maxon::UInt64(enum2972::DRAW_TEXTUREFLAGS::INTERPOLATION_MASK)};
	static const maxon::EnumInfo DRAW_TEXTUREFLAGS_info{"DRAW_TEXTUREFLAGS", SIZEOF(DRAW_TEXTUREFLAGS), true, "NONE\0COLOR_IMAGE_TO_LINEAR\0COLOR_SRGB_TO_LINEAR\0COLOR_IMAGE_TO_SRGB\0COLOR_LINEAR_TO_SRGB\0COLOR_CORRECTION_MASK\0USE_PROFILE_COLOR\0ALLOW_FLOATINGPOINT\0TILE\0TEMPORARY\0INTERPOLATION_NEAREST\0INTERPOLATION_LINEAR\0INTERPOLATION_LINEAR_MIPMAP\0INTERPOLATION_MASK\0", DRAW_TEXTUREFLAGS_values, std::extent<decltype(DRAW_TEXTUREFLAGS_values)>::value};
}
const maxon::EnumInfo& PrivateGetEnumInfo_DRAW_TEXTUREFLAGS2972(){ return enum2972::DRAW_TEXTUREFLAGS_info; }
namespace enum2984
{
	enum class TOOLDRAW
	{
		NONE				= 0,						///< None.
		HANDLES			= (1 << 0),			///< The active objects handles will be drawn.
		AXIS				= (1 << 1),			///< The active objects axes will be drawn.
		HIGHLIGHTS	= (1 << 2)			///< The highlights will be drawn.
	} ;
	static const maxon::UInt64 TOOLDRAW_values[] = {maxon::UInt64(enum2984::TOOLDRAW::NONE), maxon::UInt64(enum2984::TOOLDRAW::HANDLES), maxon::UInt64(enum2984::TOOLDRAW::AXIS), maxon::UInt64(enum2984::TOOLDRAW::HIGHLIGHTS)};
	static const maxon::EnumInfo TOOLDRAW_info{"TOOLDRAW", SIZEOF(TOOLDRAW), true, "NONE\0HANDLES\0AXIS\0HIGHLIGHTS\0", TOOLDRAW_values, std::extent<decltype(TOOLDRAW_values)>::value};
}
const maxon::EnumInfo& PrivateGetEnumInfo_TOOLDRAW2984(){ return enum2984::TOOLDRAW_info; }
namespace enum2997
{
	enum class TOOLDRAWFLAGS
	{
		NONE			= 0,						///< None.
		INVERSE_Z	= (1 << 0),			///< Inverse Z-buffer mode. If set, the drawing engine of @C4D will only draw elements if they are further away from the camera than other objects.\n
															///< This is mostly used for help lines (such as the semi-transparent axis inside of objects).
															/// @note This mode only works when all objects are drawn so it should be passed last.
		HIGHLIGHT	= (1 << 1)			///< Highlight mode.
	} ;
	static const maxon::UInt64 TOOLDRAWFLAGS_values[] = {maxon::UInt64(enum2997::TOOLDRAWFLAGS::NONE), maxon::UInt64(enum2997::TOOLDRAWFLAGS::INVERSE_Z), maxon::UInt64(enum2997::TOOLDRAWFLAGS::HIGHLIGHT)};
	static const maxon::EnumInfo TOOLDRAWFLAGS_info{"TOOLDRAWFLAGS", SIZEOF(TOOLDRAWFLAGS), true, "NONE\0INVERSE_Z\0HIGHLIGHT\0", TOOLDRAWFLAGS_values, std::extent<decltype(TOOLDRAWFLAGS_values)>::value};
}
const maxon::EnumInfo& PrivateGetEnumInfo_TOOLDRAWFLAGS2997(){ return enum2997::TOOLDRAWFLAGS_info; }
namespace enum3148
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
	static const maxon::UInt64 DIRTYFLAGS_values[] = {maxon::UInt64(enum3148::DIRTYFLAGS::NONE), maxon::UInt64(enum3148::DIRTYFLAGS::MATRIX), maxon::UInt64(enum3148::DIRTYFLAGS::DATA), maxon::UInt64(enum3148::DIRTYFLAGS::SELECT), maxon::UInt64(enum3148::DIRTYFLAGS::CACHE), maxon::UInt64(enum3148::DIRTYFLAGS::CHILDREN), maxon::UInt64(enum3148::DIRTYFLAGS::DESCRIPTION), maxon::UInt64(enum3148::DIRTYFLAGS::SELECTION_OBJECTS), maxon::UInt64(enum3148::DIRTYFLAGS::SELECTION_TAGS), maxon::UInt64(enum3148::DIRTYFLAGS::SELECTION_MATERIALS), maxon::UInt64(enum3148::DIRTYFLAGS::ALL)};
	static const maxon::EnumInfo DIRTYFLAGS_info{"DIRTYFLAGS", SIZEOF(DIRTYFLAGS), true, "NONE\0MATRIX\0DATA\0SELECT\0CACHE\0CHILDREN\0DESCRIPTION\0SELECTION_OBJECTS\0SELECTION_TAGS\0SELECTION_MATERIALS\0ALL\0", DIRTYFLAGS_values, std::extent<decltype(DIRTYFLAGS_values)>::value};
}
const maxon::EnumInfo& PrivateGetEnumInfo_DIRTYFLAGS3148(){ return enum3148::DIRTYFLAGS_info; }
namespace enum3169
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
	static const maxon::UInt64 HDIRTY_ID_values[] = {maxon::UInt64(enum3169::HDIRTY_ID::ANIMATION), maxon::UInt64(enum3169::HDIRTY_ID::OBJECT), maxon::UInt64(enum3169::HDIRTY_ID::OBJECT_MATRIX), maxon::UInt64(enum3169::HDIRTY_ID::OBJECT_HIERARCHY), maxon::UInt64(enum3169::HDIRTY_ID::TAG), maxon::UInt64(enum3169::HDIRTY_ID::MATERIAL), maxon::UInt64(enum3169::HDIRTY_ID::SHADER), maxon::UInt64(enum3169::HDIRTY_ID::RENDERSETTINGS), maxon::UInt64(enum3169::HDIRTY_ID::VP), maxon::UInt64(enum3169::HDIRTY_ID::FILTER), maxon::UInt64(enum3169::HDIRTY_ID::NBITS), maxon::UInt64(enum3169::HDIRTY_ID::MAX)};
	static const maxon::EnumInfo HDIRTY_ID_info{"HDIRTY_ID", SIZEOF(HDIRTY_ID), false, "ANIMATION\0OBJECT\0OBJECT_MATRIX\0OBJECT_HIERARCHY\0TAG\0MATERIAL\0SHADER\0RENDERSETTINGS\0VP\0FILTER\0NBITS\0MAX\0", HDIRTY_ID_values, std::extent<decltype(HDIRTY_ID_values)>::value};
}
const maxon::EnumInfo& PrivateGetEnumInfo_HDIRTY_ID3169(){ return enum3169::HDIRTY_ID_info; }
namespace enum3192
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
	static const maxon::UInt64 HDIRTYFLAGS_values[] = {maxon::UInt64(enum3192::HDIRTYFLAGS::NONE), maxon::UInt64(enum3192::HDIRTYFLAGS::ANIMATION), maxon::UInt64(enum3192::HDIRTYFLAGS::OBJECT), maxon::UInt64(enum3192::HDIRTYFLAGS::OBJECT_MATRIX), maxon::UInt64(enum3192::HDIRTYFLAGS::OBJECT_HIERARCHY), maxon::UInt64(enum3192::HDIRTYFLAGS::TAG), maxon::UInt64(enum3192::HDIRTYFLAGS::MATERIAL), maxon::UInt64(enum3192::HDIRTYFLAGS::SHADER), maxon::UInt64(enum3192::HDIRTYFLAGS::RENDERSETTINGS), maxon::UInt64(enum3192::HDIRTYFLAGS::VP), maxon::UInt64(enum3192::HDIRTYFLAGS::FILTER), maxon::UInt64(enum3192::HDIRTYFLAGS::NBITS), maxon::UInt64(enum3192::HDIRTYFLAGS::ALL)};
	static const maxon::EnumInfo HDIRTYFLAGS_info{"HDIRTYFLAGS", SIZEOF(HDIRTYFLAGS), true, "NONE\0ANIMATION\0OBJECT\0OBJECT_MATRIX\0OBJECT_HIERARCHY\0TAG\0MATERIAL\0SHADER\0RENDERSETTINGS\0VP\0FILTER\0NBITS\0ALL\0", HDIRTYFLAGS_values, std::extent<decltype(HDIRTYFLAGS_values)>::value};
}
const maxon::EnumInfo& PrivateGetEnumInfo_HDIRTYFLAGS3192(){ return enum3192::HDIRTYFLAGS_info; }
namespace enum3216
{
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
	} ;
	static const maxon::UInt64 ROTATIONORDER_values[] = {maxon::UInt64(enum3216::ROTATIONORDER::YXZGLOBAL), maxon::UInt64(enum3216::ROTATIONORDER::YZXGLOBAL), maxon::UInt64(enum3216::ROTATIONORDER::ZYXGLOBAL), maxon::UInt64(enum3216::ROTATIONORDER::ZXYGLOBAL), maxon::UInt64(enum3216::ROTATIONORDER::XZYGLOBAL), maxon::UInt64(enum3216::ROTATIONORDER::XYZGLOBAL), maxon::UInt64(enum3216::ROTATIONORDER::YXZLOCAL), maxon::UInt64(enum3216::ROTATIONORDER::YZXLOCAL), maxon::UInt64(enum3216::ROTATIONORDER::ZYXLOCAL), maxon::UInt64(enum3216::ROTATIONORDER::ZXYLOCAL), maxon::UInt64(enum3216::ROTATIONORDER::XZYLOCAL), maxon::UInt64(enum3216::ROTATIONORDER::XYZLOCAL), maxon::UInt64(enum3216::ROTATIONORDER::HPB), maxon::UInt64(enum3216::ROTATIONORDER::DEFAULT)};
	static const maxon::EnumInfo ROTATIONORDER_info{"ROTATIONORDER", SIZEOF(ROTATIONORDER), false, "YXZGLOBAL\0YZXGLOBAL\0ZYXGLOBAL\0ZXYGLOBAL\0XZYGLOBAL\0XYZGLOBAL\0YXZLOCAL\0YZXLOCAL\0ZYXLOCAL\0ZXYLOCAL\0XZYLOCAL\0XYZLOCAL\0HPB\0DEFAULT\0", ROTATIONORDER_values, std::extent<decltype(ROTATIONORDER_values)>::value};
}
const maxon::EnumInfo& PrivateGetEnumInfo_ROTATIONORDER3216(){ return enum3216::ROTATIONORDER_info; }
namespace enum3227
{
	enum class ROTATIONINTERPOLATION_QUATERNION : UChar
	{
		SLERP = 2,	///< Spherical LERP Interpolation (linear).
		CUBIC = 3		///< Smooth Cubic Interpolation (formerly known as Losch).
	} ;
	static const maxon::UInt64 ROTATIONINTERPOLATION_QUATERNION_values[] = {maxon::UInt64(enum3227::ROTATIONINTERPOLATION_QUATERNION::SLERP), maxon::UInt64(enum3227::ROTATIONINTERPOLATION_QUATERNION::CUBIC)};
	static const maxon::EnumInfo ROTATIONINTERPOLATION_QUATERNION_info{"ROTATIONINTERPOLATION_QUATERNION", SIZEOF(ROTATIONINTERPOLATION_QUATERNION), false, "SLERP\0CUBIC\0", ROTATIONINTERPOLATION_QUATERNION_values, std::extent<decltype(ROTATIONINTERPOLATION_QUATERNION_values)>::value};
}
const maxon::EnumInfo& PrivateGetEnumInfo_ROTATIONINTERPOLATION_QUATERNION3227(){ return enum3227::ROTATIONINTERPOLATION_QUATERNION_info; }
namespace enum3239
{
	enum class CURVEINTERPOLATION_MODE
	{
		R23, ///< hermite evaluation with some tangent issues
	
		CURRENT ///< Spline evaluation
	} ;
	static const maxon::UInt64 CURVEINTERPOLATION_MODE_values[] = {maxon::UInt64(enum3239::CURVEINTERPOLATION_MODE::R23), maxon::UInt64(enum3239::CURVEINTERPOLATION_MODE::CURRENT)};
	static const maxon::EnumInfo CURVEINTERPOLATION_MODE_info{"CURVEINTERPOLATION_MODE", SIZEOF(CURVEINTERPOLATION_MODE), false, "R23\0CURRENT\0", CURVEINTERPOLATION_MODE_values, std::extent<decltype(CURVEINTERPOLATION_MODE_values)>::value};
}
const maxon::EnumInfo& PrivateGetEnumInfo_CURVEINTERPOLATION_MODE3239(){ return enum3239::CURVEINTERPOLATION_MODE_info; }
namespace enum3255
{
	enum class BUILDFLAGS : UInt16
	{
		NONE							= 0,						///< None.
		INTERNALRENDERER	= (1 << 1),			///< Rendering in the editor.
		EXTERNALRENDERER	= (1 << 2),			///< Rendering externally.
		ISOPARM						= (1 << 3),			///< Generate isoparm objects.
		EXPORTONLY				= (1 << 4),			///< Exporting (e.g. Alembic).
		INTERACTIVEEDITOR = (1 << 5),			///< currently running in the active viewport window (viewscheduler or mainthread)
	} ;
	static const maxon::UInt64 BUILDFLAGS_values[] = {maxon::UInt64(enum3255::BUILDFLAGS::NONE), maxon::UInt64(enum3255::BUILDFLAGS::INTERNALRENDERER), maxon::UInt64(enum3255::BUILDFLAGS::EXTERNALRENDERER), maxon::UInt64(enum3255::BUILDFLAGS::ISOPARM), maxon::UInt64(enum3255::BUILDFLAGS::EXPORTONLY), maxon::UInt64(enum3255::BUILDFLAGS::INTERACTIVEEDITOR)};
	static const maxon::EnumInfo BUILDFLAGS_info{"BUILDFLAGS", SIZEOF(BUILDFLAGS), true, "NONE\0INTERNALRENDERER\0EXTERNALRENDERER\0ISOPARM\0EXPORTONLY\0INTERACTIVEEDITOR\0", BUILDFLAGS_values, std::extent<decltype(BUILDFLAGS_values)>::value};
}
const maxon::EnumInfo& PrivateGetEnumInfo_BUILDFLAGS3255(){ return enum3255::BUILDFLAGS_info; }
namespace enum3274
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
	static const maxon::UInt64 EXECUTIONFLAGS_values[] = {maxon::UInt64(enum3274::EXECUTIONFLAGS::NONE), maxon::UInt64(enum3274::EXECUTIONFLAGS::ANIMATION), maxon::UInt64(enum3274::EXECUTIONFLAGS::EXPRESSION), maxon::UInt64(enum3274::EXECUTIONFLAGS::CACHEBUILDING), maxon::UInt64(enum3274::EXECUTIONFLAGS::CAMERAONLY), maxon::UInt64(enum3274::EXECUTIONFLAGS::INDRAG), maxon::UInt64(enum3274::EXECUTIONFLAGS::INMOVE), maxon::UInt64(enum3274::EXECUTIONFLAGS::RENDER), maxon::UInt64(enum3274::EXECUTIONFLAGS::ALLOW_PRIORITYSHIFT)};
	static const maxon::EnumInfo EXECUTIONFLAGS_info{"EXECUTIONFLAGS", SIZEOF(EXECUTIONFLAGS), true, "NONE\0ANIMATION\0EXPRESSION\0CACHEBUILDING\0CAMERAONLY\0INDRAG\0INMOVE\0RENDER\0ALLOW_PRIORITYSHIFT\0", EXECUTIONFLAGS_values, std::extent<decltype(EXECUTIONFLAGS_values)>::value};
}
const maxon::EnumInfo& PrivateGetEnumInfo_EXECUTIONFLAGS3274(){ return enum3274::EXECUTIONFLAGS_info; }
namespace enum3288
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
	static const maxon::UInt64 SCENEHOOKDRAW_values[] = {maxon::UInt64(enum3288::SCENEHOOKDRAW::NONE), maxon::UInt64(enum3288::SCENEHOOKDRAW::DRAW_PASS), maxon::UInt64(enum3288::SCENEHOOKDRAW::HIGHLIGHT_PASS_BEFORE_TOOL), maxon::UInt64(enum3288::SCENEHOOKDRAW::HIGHLIGHT_PASS), maxon::UInt64(enum3288::SCENEHOOKDRAW::HIGHLIGHT_PASS_INV), maxon::UInt64(enum3288::SCENEHOOKDRAW::DRAW_PASS_AFTER_CLEAR)};
	static const maxon::EnumInfo SCENEHOOKDRAW_info{"SCENEHOOKDRAW", SIZEOF(SCENEHOOKDRAW), true, "NONE\0DRAW_PASS\0HIGHLIGHT_PASS_BEFORE_TOOL\0HIGHLIGHT_PASS\0HIGHLIGHT_PASS_INV\0DRAW_PASS_AFTER_CLEAR\0", SCENEHOOKDRAW_values, std::extent<decltype(SCENEHOOKDRAW_values)>::value};
}
const maxon::EnumInfo& PrivateGetEnumInfo_SCENEHOOKDRAW3288(){ return enum3288::SCENEHOOKDRAW_info; }
namespace enum3309
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
	} ;
	static const maxon::UInt64 DESCFLAGS_DESC_values[] = {maxon::UInt64(enum3309::DESCFLAGS_DESC::NONE), maxon::UInt64(enum3309::DESCFLAGS_DESC::RESOLVEMULTIPLEDATA), maxon::UInt64(enum3309::DESCFLAGS_DESC::LOADED), maxon::UInt64(enum3309::DESCFLAGS_DESC::RECURSIONLOCK), maxon::UInt64(enum3309::DESCFLAGS_DESC::DONTLOADDEFAULT), maxon::UInt64(enum3309::DESCFLAGS_DESC::MAPTAGS), maxon::UInt64(enum3309::DESCFLAGS_DESC::NEEDDEFAULTVALUE), maxon::UInt64(enum3309::DESCFLAGS_DESC::TRISTATE), maxon::UInt64(enum3309::DESCFLAGS_DESC::EXPORTHELPSYMBOLSMODE), maxon::UInt64(enum3309::DESCFLAGS_DESC::MATREFLECTANCEOVERLAP), maxon::UInt64(enum3309::DESCFLAGS_DESC::XPRESSO), maxon::UInt64(enum3309::DESCFLAGS_DESC::PRESET)};
	static const maxon::EnumInfo DESCFLAGS_DESC_info{"DESCFLAGS_DESC", SIZEOF(DESCFLAGS_DESC), true, "NONE\0RESOLVEMULTIPLEDATA\0LOADED\0RECURSIONLOCK\0DONTLOADDEFAULT\0MAPTAGS\0NEEDDEFAULTVALUE\0TRISTATE\0EXPORTHELPSYMBOLSMODE\0MATREFLECTANCEOVERLAP\0XPRESSO\0PRESET\0", DESCFLAGS_DESC_values, std::extent<decltype(DESCFLAGS_DESC_values)>::value};
}
const maxon::EnumInfo& PrivateGetEnumInfo_DESCFLAGS_DESC3309(){ return enum3309::DESCFLAGS_DESC_info; }
namespace enum3324
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
	static const maxon::UInt64 DESCFLAGS_GET_values[] = {maxon::UInt64(enum3324::DESCFLAGS_GET::NONE), maxon::UInt64(enum3324::DESCFLAGS_GET::PARAM_GET), maxon::UInt64(enum3324::DESCFLAGS_GET::NO_GLOBALDATA), maxon::UInt64(enum3324::DESCFLAGS_GET::NO_GEDATADEFAULTVALUE), maxon::UInt64(enum3324::DESCFLAGS_GET::ALLOW_TRISTATE), maxon::UInt64(enum3324::DESCFLAGS_GET::PRIVATE_GETDEFAULTVALUEONLY)};
	static const maxon::EnumInfo DESCFLAGS_GET_info{"DESCFLAGS_GET", SIZEOF(DESCFLAGS_GET), true, "NONE\0PARAM_GET\0NO_GLOBALDATA\0NO_GEDATADEFAULTVALUE\0ALLOW_TRISTATE\0PRIVATE_GETDEFAULTVALUEONLY\0", DESCFLAGS_GET_values, std::extent<decltype(DESCFLAGS_GET_values)>::value};
}
const maxon::EnumInfo& PrivateGetEnumInfo_DESCFLAGS_GET3324(){ return enum3324::DESCFLAGS_GET_info; }
namespace enum3344
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
	static const maxon::UInt64 DESCFLAGS_SET_values[] = {maxon::UInt64(enum3344::DESCFLAGS_SET::NONE), maxon::UInt64(enum3344::DESCFLAGS_SET::PARAM_SET), maxon::UInt64(enum3344::DESCFLAGS_SET::USERINTERACTION), maxon::UInt64(enum3344::DESCFLAGS_SET::DONTCHECKMINMAX), maxon::UInt64(enum3344::DESCFLAGS_SET::DONTAFFECTINHERITANCE), maxon::UInt64(enum3344::DESCFLAGS_SET::FORCESET), maxon::UInt64(enum3344::DESCFLAGS_SET::DONTFREESPLINECACHE), maxon::UInt64(enum3344::DESCFLAGS_SET::INDRAG), maxon::UInt64(enum3344::DESCFLAGS_SET::INRESETTODEFAULT)};
	static const maxon::EnumInfo DESCFLAGS_SET_info{"DESCFLAGS_SET", SIZEOF(DESCFLAGS_SET), true, "NONE\0PARAM_SET\0USERINTERACTION\0DONTCHECKMINMAX\0DONTAFFECTINHERITANCE\0FORCESET\0DONTFREESPLINECACHE\0INDRAG\0INRESETTODEFAULT\0", DESCFLAGS_SET_values, std::extent<decltype(DESCFLAGS_SET_values)>::value};
}
const maxon::EnumInfo& PrivateGetEnumInfo_DESCFLAGS_SET3344(){ return enum3344::DESCFLAGS_SET_info; }
namespace enum3353
{
	enum class DESCFLAGS_ENABLE
	{
		NONE = 0			///< None.
	} ;
	static const maxon::UInt64 DESCFLAGS_ENABLE_values[] = {maxon::UInt64(enum3353::DESCFLAGS_ENABLE::NONE)};
	static const maxon::EnumInfo DESCFLAGS_ENABLE_info{"DESCFLAGS_ENABLE", SIZEOF(DESCFLAGS_ENABLE), true, "NONE\0", DESCFLAGS_ENABLE_values, std::extent<decltype(DESCFLAGS_ENABLE_values)>::value};
}
const maxon::EnumInfo& PrivateGetEnumInfo_DESCFLAGS_ENABLE3353(){ return enum3353::DESCFLAGS_ENABLE_info; }
namespace enum3368
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
	static const maxon::UInt64 HIERARCHYCLONEFLAGS_values[] = {maxon::UInt64(enum3368::HIERARCHYCLONEFLAGS::NONE), maxon::UInt64(enum3368::HIERARCHYCLONEFLAGS::ASIS), maxon::UInt64(enum3368::HIERARCHYCLONEFLAGS::ASPOLY), maxon::UInt64(enum3368::HIERARCHYCLONEFLAGS::ASLINE), maxon::UInt64(enum3368::HIERARCHYCLONEFLAGS::ASSPLINE), maxon::UInt64(enum3368::HIERARCHYCLONEFLAGS::ASVOLUME)};
	static const maxon::EnumInfo HIERARCHYCLONEFLAGS_info{"HIERARCHYCLONEFLAGS", SIZEOF(HIERARCHYCLONEFLAGS), true, "NONE\0ASIS\0ASPOLY\0ASLINE\0ASSPLINE\0ASVOLUME\0", HIERARCHYCLONEFLAGS_values, std::extent<decltype(HIERARCHYCLONEFLAGS_values)>::value};
}
const maxon::EnumInfo& PrivateGetEnumInfo_HIERARCHYCLONEFLAGS3368(){ return enum3368::HIERARCHYCLONEFLAGS_info; }
namespace enum3383
{
	enum class CHECKVALUEFORMAT
	{
		NOTHING	= 0,			///< No unit.
		DEGREE	= 1,			///< Degrees.
		PERCENT	= 2,			///< Percent.
		METER		= 3,			///< Meter. Working unit.
		INT			= 5				///< Integer.
	} ;
	static const maxon::UInt64 CHECKVALUEFORMAT_values[] = {maxon::UInt64(enum3383::CHECKVALUEFORMAT::NOTHING), maxon::UInt64(enum3383::CHECKVALUEFORMAT::DEGREE), maxon::UInt64(enum3383::CHECKVALUEFORMAT::PERCENT), maxon::UInt64(enum3383::CHECKVALUEFORMAT::METER), maxon::UInt64(enum3383::CHECKVALUEFORMAT::INT)};
	static const maxon::EnumInfo CHECKVALUEFORMAT_info{"CHECKVALUEFORMAT", SIZEOF(CHECKVALUEFORMAT), false, "NOTHING\0DEGREE\0PERCENT\0METER\0INT\0", CHECKVALUEFORMAT_values, std::extent<decltype(CHECKVALUEFORMAT_values)>::value};
}
const maxon::EnumInfo& PrivateGetEnumInfo_CHECKVALUEFORMAT3383(){ return enum3383::CHECKVALUEFORMAT_info; }
namespace enum3402
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
	static const maxon::UInt64 CHECKVALUERANGE_values[] = {maxon::UInt64(enum3402::CHECKVALUERANGE::GREATER), maxon::UInt64(enum3402::CHECKVALUERANGE::GREATEROREQUAL), maxon::UInt64(enum3402::CHECKVALUERANGE::LESS), maxon::UInt64(enum3402::CHECKVALUERANGE::LESSOREQUAL), maxon::UInt64(enum3402::CHECKVALUERANGE::BETWEEN), maxon::UInt64(enum3402::CHECKVALUERANGE::BETWEENOREQUAL), maxon::UInt64(enum3402::CHECKVALUERANGE::BETWEENOREQUALX), maxon::UInt64(enum3402::CHECKVALUERANGE::BETWEENOREQUALY), maxon::UInt64(enum3402::CHECKVALUERANGE::DIFFERENT)};
	static const maxon::EnumInfo CHECKVALUERANGE_info{"CHECKVALUERANGE", SIZEOF(CHECKVALUERANGE), false, "GREATER\0GREATEROREQUAL\0LESS\0LESSOREQUAL\0BETWEEN\0BETWEENOREQUAL\0BETWEENOREQUALX\0BETWEENOREQUALY\0DIFFERENT\0", CHECKVALUERANGE_values, std::extent<decltype(CHECKVALUERANGE_values)>::value};
}
const maxon::EnumInfo& PrivateGetEnumInfo_CHECKVALUERANGE3402(){ return enum3402::CHECKVALUERANGE_info; }
namespace enum3431
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
	static const maxon::UInt64 PAINTMESHFLAGS_values[] = {maxon::UInt64(enum3431::PAINTMESHFLAGS::NONE), maxon::UInt64(enum3431::PAINTMESHFLAGS::QUAD), maxon::UInt64(enum3431::PAINTMESHFLAGS::SEL), maxon::UInt64(enum3431::PAINTMESHFLAGS::SELA), maxon::UInt64(enum3431::PAINTMESHFLAGS::SELB), maxon::UInt64(enum3431::PAINTMESHFLAGS::SELC), maxon::UInt64(enum3431::PAINTMESHFLAGS::SELD), maxon::UInt64(enum3431::PAINTMESHFLAGS::TA), maxon::UInt64(enum3431::PAINTMESHFLAGS::TB), maxon::UInt64(enum3431::PAINTMESHFLAGS::TC), maxon::UInt64(enum3431::PAINTMESHFLAGS::TD), maxon::UInt64(enum3431::PAINTMESHFLAGS::INACTIVE), maxon::UInt64(enum3431::PAINTMESHFLAGS::EDGEA), maxon::UInt64(enum3431::PAINTMESHFLAGS::EDGEB), maxon::UInt64(enum3431::PAINTMESHFLAGS::EDGEC), maxon::UInt64(enum3431::PAINTMESHFLAGS::EDGED)};
	static const maxon::EnumInfo PAINTMESHFLAGS_info{"PAINTMESHFLAGS", SIZEOF(PAINTMESHFLAGS), true, "NONE\0QUAD\0SEL\0SELA\0SELB\0SELC\0SELD\0TA\0TB\0TC\0TD\0INACTIVE\0EDGEA\0EDGEB\0EDGEC\0EDGED\0", PAINTMESHFLAGS_values, std::extent<decltype(PAINTMESHFLAGS_values)>::value};
}
const maxon::EnumInfo& PrivateGetEnumInfo_PAINTMESHFLAGS3431(){ return enum3431::PAINTMESHFLAGS_info; }
namespace enum3445
{
	enum class GETBRANCHINFO
	{
		NONE							= 0,						///< None.
		ONLYWITHCHILDREN	= (1 << 1),			///< Only return branch if it is in use, i.e. has content.
		GELISTNODES				= (1 << 3),			///< @markPrivate
		ONLYMODIFIABLE		= (1 << 4),			///< @markPrivate
		ONLYWITHANIMATION = (1 << 5),			///< Only return branch if animation flag is set.
	} ;
	static const maxon::UInt64 GETBRANCHINFO_values[] = {maxon::UInt64(enum3445::GETBRANCHINFO::NONE), maxon::UInt64(enum3445::GETBRANCHINFO::ONLYWITHCHILDREN), maxon::UInt64(enum3445::GETBRANCHINFO::GELISTNODES), maxon::UInt64(enum3445::GETBRANCHINFO::ONLYMODIFIABLE), maxon::UInt64(enum3445::GETBRANCHINFO::ONLYWITHANIMATION)};
	static const maxon::EnumInfo GETBRANCHINFO_info{"GETBRANCHINFO", SIZEOF(GETBRANCHINFO), true, "NONE\0ONLYWITHCHILDREN\0GELISTNODES\0ONLYMODIFIABLE\0ONLYWITHANIMATION\0", GETBRANCHINFO_values, std::extent<decltype(GETBRANCHINFO_values)>::value};
}
const maxon::EnumInfo& PrivateGetEnumInfo_GETBRANCHINFO3445(){ return enum3445::GETBRANCHINFO_info; }
namespace enum3458
{
	enum class BRANCHINFOFLAGS
	{
		NONE						= 0,						///< None.
		ANIMATE					= (1 << 0),			///< Animate the nodes in this branch.
		HIDEINTIMELINE	= (1 << 4),			///< If set, this branch will not show up in the timeline.
		HASFIELDS				= (1 << 5)			///< If set, this branch will contain FieldLayers and will display in the FieldsList
	} ;
	static const maxon::UInt64 BRANCHINFOFLAGS_values[] = {maxon::UInt64(enum3458::BRANCHINFOFLAGS::NONE), maxon::UInt64(enum3458::BRANCHINFOFLAGS::ANIMATE), maxon::UInt64(enum3458::BRANCHINFOFLAGS::HIDEINTIMELINE), maxon::UInt64(enum3458::BRANCHINFOFLAGS::HASFIELDS)};
	static const maxon::EnumInfo BRANCHINFOFLAGS_info{"BRANCHINFOFLAGS", SIZEOF(BRANCHINFOFLAGS), true, "NONE\0ANIMATE\0HIDEINTIMELINE\0HASFIELDS\0", BRANCHINFOFLAGS_values, std::extent<decltype(BRANCHINFOFLAGS_values)>::value};
}
const maxon::EnumInfo& PrivateGetEnumInfo_BRANCHINFOFLAGS3458(){ return enum3458::BRANCHINFOFLAGS_info; }
namespace enum3470
{
	enum class GETACTIVEOBJECTFLAGS
	{
		NONE						= 0,						///< None.
		CHILDREN				= (1 << 0),			///< Child objects are added to the selection too, provided they are selected. Otherwise only the topmost parent of each chain is added.
		SELECTIONORDER	= (1 << 1)			///< The selection array is sorted in the selection order, e.g. the first selected object is the first element in the array.
	} ;
	static const maxon::UInt64 GETACTIVEOBJECTFLAGS_values[] = {maxon::UInt64(enum3470::GETACTIVEOBJECTFLAGS::NONE), maxon::UInt64(enum3470::GETACTIVEOBJECTFLAGS::CHILDREN), maxon::UInt64(enum3470::GETACTIVEOBJECTFLAGS::SELECTIONORDER)};
	static const maxon::EnumInfo GETACTIVEOBJECTFLAGS_info{"GETACTIVEOBJECTFLAGS", SIZEOF(GETACTIVEOBJECTFLAGS), true, "NONE\0CHILDREN\0SELECTIONORDER\0", GETACTIVEOBJECTFLAGS_values, std::extent<decltype(GETACTIVEOBJECTFLAGS_values)>::value};
}
const maxon::EnumInfo& PrivateGetEnumInfo_GETACTIVEOBJECTFLAGS3470(){ return enum3470::GETACTIVEOBJECTFLAGS_info; }
namespace enum3483
{
	enum class DRAWPASS
	{
		OBJECT			= 0,		///< Object pass.
		BOX					= 1,		///< Box pass.
		HANDLES			= 2,		///< Handle pass.
		HIGHLIGHTS	= 3,		///< Highlight pass.
		XRAY				= 4			///< X-Ray pass.
	} ;
	static const maxon::UInt64 DRAWPASS_values[] = {maxon::UInt64(enum3483::DRAWPASS::OBJECT), maxon::UInt64(enum3483::DRAWPASS::BOX), maxon::UInt64(enum3483::DRAWPASS::HANDLES), maxon::UInt64(enum3483::DRAWPASS::HIGHLIGHTS), maxon::UInt64(enum3483::DRAWPASS::XRAY)};
	static const maxon::EnumInfo DRAWPASS_info{"DRAWPASS", SIZEOF(DRAWPASS), false, "OBJECT\0BOX\0HANDLES\0HIGHLIGHTS\0XRAY\0", DRAWPASS_values, std::extent<decltype(DRAWPASS_values)>::value};
}
const maxon::EnumInfo& PrivateGetEnumInfo_DRAWPASS3483(){ return enum3483::DRAWPASS_info; }
namespace enum3581
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
	static const maxon::UInt64 SAVEPROJECT_values[] = {maxon::UInt64(enum3581::SAVEPROJECT::NONE), maxon::UInt64(enum3581::SAVEPROJECT::ASSETS), maxon::UInt64(enum3581::SAVEPROJECT::SCENEFILE), maxon::UInt64(enum3581::SAVEPROJECT::DIALOGSALLOWED), maxon::UInt64(enum3581::SAVEPROJECT::SHOWMISSINGASSETDIALOG), maxon::UInt64(enum3581::SAVEPROJECT::ADDTORECENTLIST), maxon::UInt64(enum3581::SAVEPROJECT::DONTCOPYFILES), maxon::UInt64(enum3581::SAVEPROJECT::PROGRESSALLOWED), maxon::UInt64(enum3581::SAVEPROJECT::DONTTOUCHDOCUMENT), maxon::UInt64(enum3581::SAVEPROJECT::DONTFAILONMISSINGASSETS), maxon::UInt64(enum3581::SAVEPROJECT::ISNET), maxon::UInt64(enum3581::SAVEPROJECT::USEDOCUMENTNAMEASFILENAME), maxon::UInt64(enum3581::SAVEPROJECT::DONTCLEARSUGGESTEDFOLDER), maxon::UInt64(enum3581::SAVEPROJECT::WITHCACHES), maxon::UInt64(enum3581::SAVEPROJECT::DONTGENERATEPAINTTEX), maxon::UInt64(enum3581::SAVEPROJECT::ASSETLINKS_COPY_FILEASSETS), maxon::UInt64(enum3581::SAVEPROJECT::ASSETLINKS_COPY_NODEASSETS)};
	static const maxon::EnumInfo SAVEPROJECT_info{"SAVEPROJECT", SIZEOF(SAVEPROJECT), true, "NONE\0ASSETS\0SCENEFILE\0DIALOGSALLOWED\0SHOWMISSINGASSETDIALOG\0ADDTORECENTLIST\0DONTCOPYFILES\0PROGRESSALLOWED\0DONTTOUCHDOCUMENT\0DONTFAILONMISSINGASSETS\0ISNET\0USEDOCUMENTNAMEASFILENAME\0DONTCLEARSUGGESTEDFOLDER\0WITHCACHES\0DONTGENERATEPAINTTEX\0ASSETLINKS_COPY_FILEASSETS\0ASSETLINKS_COPY_NODEASSETS\0", SAVEPROJECT_values, std::extent<decltype(SAVEPROJECT_values)>::value};
}
const maxon::EnumInfo& PrivateGetEnumInfo_SAVEPROJECT3581(){ return enum3581::SAVEPROJECT_info; }
namespace enum3593
{
	enum class ICONDATAFLAGS
	{
		NONE							= 0,						///< None.
		APPLYCOLORPROFILE	= (1 << 0),			///< Apply color profile.
		DISABLED					= (1 << 1)			///< Disabled.
	} ;
	static const maxon::UInt64 ICONDATAFLAGS_values[] = {maxon::UInt64(enum3593::ICONDATAFLAGS::NONE), maxon::UInt64(enum3593::ICONDATAFLAGS::APPLYCOLORPROFILE), maxon::UInt64(enum3593::ICONDATAFLAGS::DISABLED)};
	static const maxon::EnumInfo ICONDATAFLAGS_info{"ICONDATAFLAGS", SIZEOF(ICONDATAFLAGS), true, "NONE\0APPLYCOLORPROFILE\0DISABLED\0", ICONDATAFLAGS_values, std::extent<decltype(ICONDATAFLAGS_values)>::value};
}
const maxon::EnumInfo& PrivateGetEnumInfo_ICONDATAFLAGS3593(){ return enum3593::ICONDATAFLAGS_info; }
namespace enum3608
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
	static const maxon::UInt64 USERAREAFLAGS_values[] = {maxon::UInt64(enum3608::USERAREAFLAGS::NONE), maxon::UInt64(enum3608::USERAREAFLAGS::TABSTOP), maxon::UInt64(enum3608::USERAREAFLAGS::HANDLEFOCUS), maxon::UInt64(enum3608::USERAREAFLAGS::COREMESSAGE), maxon::UInt64(enum3608::USERAREAFLAGS::SYNCMESSAGE), maxon::UInt64(enum3608::USERAREAFLAGS::DONT_MIRROR)};
	static const maxon::EnumInfo USERAREAFLAGS_info{"USERAREAFLAGS", SIZEOF(USERAREAFLAGS), true, "NONE\0TABSTOP\0HANDLEFOCUS\0COREMESSAGE\0SYNCMESSAGE\0DONT_MIRROR\0", USERAREAFLAGS_values, std::extent<decltype(USERAREAFLAGS_values)>::value};
}
const maxon::EnumInfo& PrivateGetEnumInfo_USERAREAFLAGS3608(){ return enum3608::USERAREAFLAGS_info; }
#ifndef __API_INTERN__
#endif
namespace enum3869
{
	enum class EXECUTIONRESULT
	{
		OK					= 0,			///< OK.
		USERBREAK		= 1,			///< %User break.
		OUTOFMEMORY	= 2				///< Not enough memory.
	} ;
	static const maxon::UInt64 EXECUTIONRESULT_values[] = {maxon::UInt64(enum3869::EXECUTIONRESULT::OK), maxon::UInt64(enum3869::EXECUTIONRESULT::USERBREAK), maxon::UInt64(enum3869::EXECUTIONRESULT::OUTOFMEMORY)};
	static const maxon::EnumInfo EXECUTIONRESULT_info{"EXECUTIONRESULT", SIZEOF(EXECUTIONRESULT), false, "OK\0USERBREAK\0OUTOFMEMORY\0", EXECUTIONRESULT_values, std::extent<decltype(EXECUTIONRESULT_values)>::value};
}
const maxon::EnumInfo& PrivateGetEnumInfo_EXECUTIONRESULT3869(){ return enum3869::EXECUTIONRESULT_info; }
namespace enum3897
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
	static const maxon::UInt64 IMAGERESULT_values[] = {maxon::UInt64(enum3897::IMAGERESULT::OK), maxon::UInt64(enum3897::IMAGERESULT::NOTEXISTING), maxon::UInt64(enum3897::IMAGERESULT::WRONGTYPE), maxon::UInt64(enum3897::IMAGERESULT::OUTOFMEMORY), maxon::UInt64(enum3897::IMAGERESULT::FILEERROR), maxon::UInt64(enum3897::IMAGERESULT::FILESTRUCTURE), maxon::UInt64(enum3897::IMAGERESULT::MISC_ERROR), maxon::UInt64(enum3897::IMAGERESULT::PARAM_ERROR), maxon::UInt64(enum3897::IMAGERESULT::THREADCANCELED)};
	static const maxon::EnumInfo IMAGERESULT_info{"IMAGERESULT", SIZEOF(IMAGERESULT), false, "OK\0NOTEXISTING\0WRONGTYPE\0OUTOFMEMORY\0FILEERROR\0FILESTRUCTURE\0MISC_ERROR\0PARAM_ERROR\0THREADCANCELED\0", IMAGERESULT_values, std::extent<decltype(IMAGERESULT_values)>::value};
}
const maxon::EnumInfo& PrivateGetEnumInfo_IMAGERESULT3897(){ return enum3897::IMAGERESULT_info; }
namespace enum3912
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
	static const maxon::UInt64 STRINGENCODING_values[] = {maxon::UInt64(enum3912::STRINGENCODING::XBIT), maxon::UInt64(enum3912::STRINGENCODING::BIT7), maxon::UInt64(enum3912::STRINGENCODING::BIT7HEX), maxon::UInt64(enum3912::STRINGENCODING::UTF8)};
	static const maxon::EnumInfo STRINGENCODING_info{"STRINGENCODING", SIZEOF(STRINGENCODING), false, "XBIT\0BIT7\0BIT7HEX\0UTF8\0", STRINGENCODING_values, std::extent<decltype(STRINGENCODING_values)>::value};
}
const maxon::EnumInfo& PrivateGetEnumInfo_STRINGENCODING3912(){ return enum3912::STRINGENCODING_info; }
namespace enum3923
{
	enum class THREADMODE
	{
		DEPRECATED_SYNCHRONOUS	= 0,			///< Synchronous thread. @markDeprecated
		ASYNC										= 1,			///< Asynchronous thread.
		PRIVATE_OPENGL					= 3				///< @markPrivate @since R18
	} ;
	static const maxon::UInt64 THREADMODE_values[] = {maxon::UInt64(enum3923::THREADMODE::DEPRECATED_SYNCHRONOUS), maxon::UInt64(enum3923::THREADMODE::ASYNC), maxon::UInt64(enum3923::THREADMODE::PRIVATE_OPENGL)};
	static const maxon::EnumInfo THREADMODE_info{"THREADMODE", SIZEOF(THREADMODE), false, "DEPRECATED_SYNCHRONOUS\0ASYNC\0PRIVATE_OPENGL\0", THREADMODE_values, std::extent<decltype(THREADMODE_values)>::value};
}
const maxon::EnumInfo& PrivateGetEnumInfo_THREADMODE3923(){ return enum3923::THREADMODE_info; }
namespace enum3935
{
	enum class THREADPRIORITYEX
	{
		NORMAL	= 0,				///< Normal.
		ABOVE	= 1000,			///< Above.
		BELOW	= 1001,			///< Below.
		LOWEST	= 1002			///< Lowest.
	} ;
	static const maxon::UInt64 THREADPRIORITYEX_values[] = {maxon::UInt64(enum3935::THREADPRIORITYEX::NORMAL), maxon::UInt64(enum3935::THREADPRIORITYEX::ABOVE), maxon::UInt64(enum3935::THREADPRIORITYEX::BELOW), maxon::UInt64(enum3935::THREADPRIORITYEX::LOWEST)};
	static const maxon::EnumInfo THREADPRIORITYEX_info{"THREADPRIORITYEX", SIZEOF(THREADPRIORITYEX), false, "NORMAL\0ABOVE\0BELOW\0LOWEST\0", THREADPRIORITYEX_values, std::extent<decltype(THREADPRIORITYEX_values)>::value};
}
const maxon::EnumInfo& PrivateGetEnumInfo_THREADPRIORITYEX3935(){ return enum3935::THREADPRIORITYEX_info; }
namespace enum3950
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
	static const maxon::UInt64 HYPERFILEARRAY_values[] = {maxon::UInt64(enum3950::HYPERFILEARRAY::CHAR), maxon::UInt64(enum3950::HYPERFILEARRAY::WORD), maxon::UInt64(enum3950::HYPERFILEARRAY::LONG), maxon::UInt64(enum3950::HYPERFILEARRAY::LLONG), maxon::UInt64(enum3950::HYPERFILEARRAY::SREAL), maxon::UInt64(enum3950::HYPERFILEARRAY::LREAL), maxon::UInt64(enum3950::HYPERFILEARRAY::REAL)};
	static const maxon::EnumInfo HYPERFILEARRAY_info{"HYPERFILEARRAY", SIZEOF(HYPERFILEARRAY), false, "CHAR\0WORD\0LONG\0LLONG\0SREAL\0LREAL\0REAL\0", HYPERFILEARRAY_values, std::extent<decltype(HYPERFILEARRAY_values)>::value};
}
const maxon::EnumInfo& PrivateGetEnumInfo_HYPERFILEARRAY3950(){ return enum3950::HYPERFILEARRAY_info; }
namespace enum3974
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
	static const maxon::UInt64 FILEERROR_values[] = {maxon::UInt64(enum3974::FILEERROR::NONE), maxon::UInt64(enum3974::FILEERROR::OPEN), maxon::UInt64(enum3974::FILEERROR::CLOSE), maxon::UInt64(enum3974::FILEERROR::READ), maxon::UInt64(enum3974::FILEERROR::WRITE), maxon::UInt64(enum3974::FILEERROR::SEEK), maxon::UInt64(enum3974::FILEERROR::INVALID), maxon::UInt64(enum3974::FILEERROR::OUTOFMEMORY), maxon::UInt64(enum3974::FILEERROR::USERBREAK), maxon::UInt64(enum3974::FILEERROR::WRONG_VALUE), maxon::UInt64(enum3974::FILEERROR::CHUNK_NUMBER), maxon::UInt64(enum3974::FILEERROR::VALUE_NO_CHUNK), maxon::UInt64(enum3974::FILEERROR::FILEEND), maxon::UInt64(enum3974::FILEERROR::UNKNOWN_VALUE)};
	static const maxon::EnumInfo FILEERROR_info{"FILEERROR", SIZEOF(FILEERROR), false, "NONE\0OPEN\0CLOSE\0READ\0WRITE\0SEEK\0INVALID\0OUTOFMEMORY\0USERBREAK\0WRONG_VALUE\0CHUNK_NUMBER\0VALUE_NO_CHUNK\0FILEEND\0UNKNOWN_VALUE\0", FILEERROR_values, std::extent<decltype(FILEERROR_values)>::value};
}
const maxon::EnumInfo& PrivateGetEnumInfo_FILEERROR3974(){ return enum3974::FILEERROR_info; }
namespace enum3990
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
	static const maxon::UInt64 FILEOPEN_values[] = {maxon::UInt64(enum3990::FILEOPEN::APPEND), maxon::UInt64(enum3990::FILEOPEN::READ), maxon::UInt64(enum3990::FILEOPEN::WRITE), maxon::UInt64(enum3990::FILEOPEN::READWRITE), maxon::UInt64(enum3990::FILEOPEN::READ_NOCACHE), maxon::UInt64(enum3990::FILEOPEN::SHAREDREAD), maxon::UInt64(enum3990::FILEOPEN::SHAREDWRITE)};
	static const maxon::EnumInfo FILEOPEN_info{"FILEOPEN", SIZEOF(FILEOPEN), false, "APPEND\0READ\0WRITE\0READWRITE\0READ_NOCACHE\0SHAREDREAD\0SHAREDWRITE\0", FILEOPEN_values, std::extent<decltype(FILEOPEN_values)>::value};
}
const maxon::EnumInfo& PrivateGetEnumInfo_FILEOPEN3990(){ return enum3990::FILEOPEN_info; }
namespace enum4001
{
	enum class LOCATION
	{
		DISK					= 1,			///< Disk storage.
		IPCONNECTION	= 2,			///< Target is IP connection.
		MEMORY				= 3				///< Target is a memory location.
	} ;
	static const maxon::UInt64 LOCATION_values[] = {maxon::UInt64(enum4001::LOCATION::DISK), maxon::UInt64(enum4001::LOCATION::IPCONNECTION), maxon::UInt64(enum4001::LOCATION::MEMORY)};
	static const maxon::EnumInfo LOCATION_info{"LOCATION", SIZEOF(LOCATION), false, "DISK\0IPCONNECTION\0MEMORY\0", LOCATION_values, std::extent<decltype(LOCATION_values)>::value};
}
const maxon::EnumInfo& PrivateGetEnumInfo_LOCATION4001(){ return enum4001::LOCATION_info; }
namespace enum4011
{
	enum class FILESEEK
	{
		START			= 0,			///< The position is given relative to the start of the file.
		RELATIVE_	= 2				///< The position is given relative to the current position.
	} ;
	static const maxon::UInt64 FILESEEK_values[] = {maxon::UInt64(enum4011::FILESEEK::START), maxon::UInt64(enum4011::FILESEEK::RELATIVE_)};
	static const maxon::EnumInfo FILESEEK_info{"FILESEEK", SIZEOF(FILESEEK), false, "START\0RELATIVE_\0", FILESEEK_values, std::extent<decltype(FILESEEK_values)>::value};
}
const maxon::EnumInfo& PrivateGetEnumInfo_FILESEEK4011(){ return enum4011::FILESEEK_info; }
namespace enum4022
{
	enum class FILEDIALOG
	{
		NONE				= 0,			///< Never show an error dialog.
		ANY					= 1,			///< Show an error dialog for any error.
		IGNOREOPEN	= 2				///< Do not show an error dialog if the file does not exist, otherwise like @ref FILEDIALOG::ANY.
	} ;
	static const maxon::UInt64 FILEDIALOG_values[] = {maxon::UInt64(enum4022::FILEDIALOG::NONE), maxon::UInt64(enum4022::FILEDIALOG::ANY), maxon::UInt64(enum4022::FILEDIALOG::IGNOREOPEN)};
	static const maxon::EnumInfo FILEDIALOG_info{"FILEDIALOG", SIZEOF(FILEDIALOG), false, "NONE\0ANY\0IGNOREOPEN\0", FILEDIALOG_values, std::extent<decltype(FILEDIALOG_values)>::value};
}
const maxon::EnumInfo& PrivateGetEnumInfo_FILEDIALOG4022(){ return enum4022::FILEDIALOG_info; }
namespace enum4033
{
	enum class FILESELECT
	{
		LOAD				= 0,			///< Load dialog.
		SAVE				= 1,			///< Save dialog.
		DIRECTORY	= 2				///< Folder selection dialog.
	} ;
	static const maxon::UInt64 FILESELECT_values[] = {maxon::UInt64(enum4033::FILESELECT::LOAD), maxon::UInt64(enum4033::FILESELECT::SAVE), maxon::UInt64(enum4033::FILESELECT::DIRECTORY)};
	static const maxon::EnumInfo FILESELECT_info{"FILESELECT", SIZEOF(FILESELECT), false, "LOAD\0SAVE\0DIRECTORY\0", FILESELECT_values, std::extent<decltype(FILESELECT_values)>::value};
}
const maxon::EnumInfo& PrivateGetEnumInfo_FILESELECT4033(){ return enum4033::FILESELECT_info; }
namespace enum4045
{
	enum class FILESELECTTYPE
	{
		ANYTHING		= 0,			///< Any file.
		IMAGES			= 1,			///< Image files.
		SCENES			= 2,			///< 3D scene files.
		BODYPAINT		= 4				///< @BP3D files.
	} ;
	static const maxon::UInt64 FILESELECTTYPE_values[] = {maxon::UInt64(enum4045::FILESELECTTYPE::ANYTHING), maxon::UInt64(enum4045::FILESELECTTYPE::IMAGES), maxon::UInt64(enum4045::FILESELECTTYPE::SCENES), maxon::UInt64(enum4045::FILESELECTTYPE::BODYPAINT)};
	static const maxon::EnumInfo FILESELECTTYPE_info{"FILESELECTTYPE", SIZEOF(FILESELECTTYPE), false, "ANYTHING\0IMAGES\0SCENES\0BODYPAINT\0", FILESELECTTYPE_values, std::extent<decltype(FILESELECTTYPE_values)>::value};
}
const maxon::EnumInfo& PrivateGetEnumInfo_FILESELECTTYPE4045(){ return enum4045::FILESELECTTYPE_info; }
namespace enum4057
{
	enum class OPERATINGSYSTEM
	{
		WIN		= 1,			///< Windows.
		OSX		= 2,			///< OS X.
		LINUX	= 3,			///< Linux.
		_IOS 	= 4				///< iOS.
	} ;
	static const maxon::UInt64 OPERATINGSYSTEM_values[] = {maxon::UInt64(enum4057::OPERATINGSYSTEM::WIN), maxon::UInt64(enum4057::OPERATINGSYSTEM::OSX), maxon::UInt64(enum4057::OPERATINGSYSTEM::LINUX), maxon::UInt64(enum4057::OPERATINGSYSTEM::_IOS)};
	static const maxon::EnumInfo OPERATINGSYSTEM_info{"OPERATINGSYSTEM", SIZEOF(OPERATINGSYSTEM), false, "WIN\0OSX\0LINUX\0_IOS\0", OPERATINGSYSTEM_values, std::extent<decltype(OPERATINGSYSTEM_values)>::value};
}
const maxon::EnumInfo& PrivateGetEnumInfo_OPERATINGSYSTEM4057(){ return enum4057::OPERATINGSYSTEM_info; }
namespace enum4068
{
	enum class BYTEORDER
	{
		// V_ unfortunately has to be used here due to conflicts with MAC OS
		V_MOTOROLA	= 1,			///< Motorola, big endian.
		V_INTEL			= 2				///< Intel, little endian.
	} ;
	static const maxon::UInt64 BYTEORDER_values[] = {maxon::UInt64(enum4068::BYTEORDER::V_MOTOROLA), maxon::UInt64(enum4068::BYTEORDER::V_INTEL)};
	static const maxon::EnumInfo BYTEORDER_info{"BYTEORDER", SIZEOF(BYTEORDER), false, "V_MOTOROLA\0V_INTEL\0", BYTEORDER_values, std::extent<decltype(BYTEORDER_values)>::value};
}
const maxon::EnumInfo& PrivateGetEnumInfo_BYTEORDER4068(){ return enum4068::BYTEORDER_info; }
namespace enum4115
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
	static const maxon::UInt64 HYPERFILEVALUE_values[] = {maxon::UInt64(enum4115::HYPERFILEVALUE::NONE), maxon::UInt64(enum4115::HYPERFILEVALUE::START), maxon::UInt64(enum4115::HYPERFILEVALUE::STOP), maxon::UInt64(enum4115::HYPERFILEVALUE::CSTOP), maxon::UInt64(enum4115::HYPERFILEVALUE::CHAR), maxon::UInt64(enum4115::HYPERFILEVALUE::UCHAR), maxon::UInt64(enum4115::HYPERFILEVALUE::INT16), maxon::UInt64(enum4115::HYPERFILEVALUE::UINT16), maxon::UInt64(enum4115::HYPERFILEVALUE::INT32), maxon::UInt64(enum4115::HYPERFILEVALUE::UINT32), maxon::UInt64(enum4115::HYPERFILEVALUE::INT64), maxon::UInt64(enum4115::HYPERFILEVALUE::UINT64), maxon::UInt64(enum4115::HYPERFILEVALUE::FLOAT), maxon::UInt64(enum4115::HYPERFILEVALUE::FLOAT64), maxon::UInt64(enum4115::HYPERFILEVALUE::BOOLEAN), maxon::UInt64(enum4115::HYPERFILEVALUE::TIME), maxon::UInt64(enum4115::HYPERFILEVALUE::VECTOR), maxon::UInt64(enum4115::HYPERFILEVALUE::VECTOR64), maxon::UInt64(enum4115::HYPERFILEVALUE::MATRIX), maxon::UInt64(enum4115::HYPERFILEVALUE::MATRIX64), maxon::UInt64(enum4115::HYPERFILEVALUE::VECTOR32), maxon::UInt64(enum4115::HYPERFILEVALUE::MATRIX32), maxon::UInt64(enum4115::HYPERFILEVALUE::FLOAT32), maxon::UInt64(enum4115::HYPERFILEVALUE::MEMORY), maxon::UInt64(enum4115::HYPERFILEVALUE::IMAGE), maxon::UInt64(enum4115::HYPERFILEVALUE::STRING), maxon::UInt64(enum4115::HYPERFILEVALUE::FILENAME), maxon::UInt64(enum4115::HYPERFILEVALUE::CONTAINER), maxon::UInt64(enum4115::HYPERFILEVALUE::ALIASLINK), maxon::UInt64(enum4115::HYPERFILEVALUE::LMEMORY), maxon::UInt64(enum4115::HYPERFILEVALUE::VECTOR_ARRAY_EX), maxon::UInt64(enum4115::HYPERFILEVALUE::POLYGON_ARRAY_EX), maxon::UInt64(enum4115::HYPERFILEVALUE::UINT16_ARRAY_EX), maxon::UInt64(enum4115::HYPERFILEVALUE::PARTICLE_ARRAY_EX), maxon::UInt64(enum4115::HYPERFILEVALUE::SREAL_ARRAY_EX), maxon::UInt64(enum4115::HYPERFILEVALUE::ARRAY), maxon::UInt64(enum4115::HYPERFILEVALUE::UUID)};
	static const maxon::EnumInfo HYPERFILEVALUE_info{"HYPERFILEVALUE", SIZEOF(HYPERFILEVALUE), false, "NONE\0START\0STOP\0CSTOP\0CHAR\0UCHAR\0INT16\0UINT16\0INT32\0UINT32\0INT64\0UINT64\0FLOAT\0FLOAT64\0BOOLEAN\0TIME\0VECTOR\0VECTOR64\0MATRIX\0MATRIX64\0VECTOR32\0MATRIX32\0FLOAT32\0MEMORY\0IMAGE\0STRING\0FILENAME\0CONTAINER\0ALIASLINK\0LMEMORY\0VECTOR_ARRAY_EX\0POLYGON_ARRAY_EX\0UINT16_ARRAY_EX\0PARTICLE_ARRAY_EX\0SREAL_ARRAY_EX\0ARRAY\0UUID\0", HYPERFILEVALUE_values, std::extent<decltype(HYPERFILEVALUE_values)>::value};
}
const maxon::EnumInfo& PrivateGetEnumInfo_HYPERFILEVALUE4115(){ return enum4115::HYPERFILEVALUE_info; }
namespace enum4126
{
	enum class FINDANIM
	{
		EXACT	= 0,			///< Exact.
		LEFT	= 1,			///< Search left.
		RIGHT	= 2				///< Search right.
	} ;
	static const maxon::UInt64 FINDANIM_values[] = {maxon::UInt64(enum4126::FINDANIM::EXACT), maxon::UInt64(enum4126::FINDANIM::LEFT), maxon::UInt64(enum4126::FINDANIM::RIGHT)};
	static const maxon::EnumInfo FINDANIM_info{"FINDANIM", SIZEOF(FINDANIM), false, "EXACT\0LEFT\0RIGHT\0", FINDANIM_values, std::extent<decltype(FINDANIM_values)>::value};
}
const maxon::EnumInfo& PrivateGetEnumInfo_FINDANIM4126(){ return enum4126::FINDANIM_info; }
namespace enum4148
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
	static const maxon::UInt64 CCURVE_values[] = {maxon::UInt64(enum4148::CCURVE::CURVE), maxon::UInt64(enum4148::CCURVE::HLE_BASE), maxon::UInt64(enum4148::CCURVE::HLE_CURVE), maxon::UInt64(enum4148::CCURVE::SS_CURVE), maxon::UInt64(enum4148::CCURVE::SS_CURVE2), maxon::UInt64(enum4148::CCURVE::SS_CURVE3), maxon::UInt64(enum4148::CCURVE::SS_CURVE4), maxon::UInt64(enum4148::CCURVE::SS_CURVE5), maxon::UInt64(enum4148::CCURVE::HLE_SCALE), maxon::UInt64(enum4148::CCURVE::HLE_MOVE)};
	static const maxon::EnumInfo CCURVE_info{"CCURVE", SIZEOF(CCURVE), false, "CURVE\0HLE_BASE\0HLE_CURVE\0SS_CURVE\0SS_CURVE2\0SS_CURVE3\0SS_CURVE4\0SS_CURVE5\0HLE_SCALE\0HLE_MOVE\0", CCURVE_values, std::extent<decltype(CCURVE_values)>::value};
}
const maxon::EnumInfo& PrivateGetEnumInfo_CCURVE4148(){ return enum4148::CCURVE_info; }
namespace enum4163
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
	static const maxon::UInt64 CLOOP_values[] = {maxon::UInt64(enum4163::CLOOP::OFF), maxon::UInt64(enum4163::CLOOP::CONSTANT), maxon::UInt64(enum4163::CLOOP::CONTINUE), maxon::UInt64(enum4163::CLOOP::REPEAT), maxon::UInt64(enum4163::CLOOP::OFFSETREPEAT), maxon::UInt64(enum4163::CLOOP::OSCILLATE), maxon::UInt64(enum4163::CLOOP::LOOP)};
	static const maxon::EnumInfo CLOOP_info{"CLOOP", SIZEOF(CLOOP), false, "OFF\0CONSTANT\0CONTINUE\0REPEAT\0OFFSETREPEAT\0OSCILLATE\0LOOP\0", CLOOP_values, std::extent<decltype(CLOOP_values)>::value};
}
const maxon::EnumInfo& PrivateGetEnumInfo_CLOOP4163(){ return enum4163::CLOOP_info; }
namespace enum4176
{
	enum class CINTERPOLATION : UChar
	{
		SPLINE	= 1,			///< Spline.
		LINEAR	= 2,			///< Linear.
		STEP		= 3,			///< Step.
	
		DUMMY		= 4
	} ;
	static const maxon::UInt64 CINTERPOLATION_values[] = {maxon::UInt64(enum4176::CINTERPOLATION::SPLINE), maxon::UInt64(enum4176::CINTERPOLATION::LINEAR), maxon::UInt64(enum4176::CINTERPOLATION::STEP), maxon::UInt64(enum4176::CINTERPOLATION::DUMMY)};
	static const maxon::EnumInfo CINTERPOLATION_info{"CINTERPOLATION", SIZEOF(CINTERPOLATION), false, "SPLINE\0LINEAR\0STEP\0DUMMY\0", CINTERPOLATION_values, std::extent<decltype(CINTERPOLATION_values)>::value};
}
const maxon::EnumInfo& PrivateGetEnumInfo_CINTERPOLATION4176(){ return enum4176::CINTERPOLATION_info; }
namespace enum4187
{
	enum class CAUTOMODE : UChar
	{
		CLASSIC			= 1,				///< AutoTangent first implementation.
		FIXEDSLOPE	= 2,				///< AutoTangent with fixed slope for given time.
	} ;
	static const maxon::UInt64 CAUTOMODE_values[] = {maxon::UInt64(enum4187::CAUTOMODE::CLASSIC), maxon::UInt64(enum4187::CAUTOMODE::FIXEDSLOPE)};
	static const maxon::EnumInfo CAUTOMODE_info{"CAUTOMODE", SIZEOF(CAUTOMODE), false, "CLASSIC\0FIXEDSLOPE\0", CAUTOMODE_values, std::extent<decltype(CAUTOMODE_values)>::value};
}
const maxon::EnumInfo& PrivateGetEnumInfo_CAUTOMODE4187(){ return enum4187::CAUTOMODE_info; }
namespace enum4201
{
	enum class CKEYPRESET
	{
		AUTO_CLAMP										= 1,			///< Auto, Auto Angle, Clamp.
		AUTO_OVERSHOOT								= 2,			///< Auto, Auto Angle, remove Overshooting.
		FIXED_OVERSHOOTWEIGHTED				= 3,			///< Auto, Fixed Angle, remove Overshooting, weighted.
		CUSTOM												= 4,			///< User Defined.
		AUTO_OVERSHOOTWEIGHTED				= 5,			///< Auto, Auto Angle, remove Overshooting, weighted.
	} ;
	static const maxon::UInt64 CKEYPRESET_values[] = {maxon::UInt64(enum4201::CKEYPRESET::AUTO_CLAMP), maxon::UInt64(enum4201::CKEYPRESET::AUTO_OVERSHOOT), maxon::UInt64(enum4201::CKEYPRESET::FIXED_OVERSHOOTWEIGHTED), maxon::UInt64(enum4201::CKEYPRESET::CUSTOM), maxon::UInt64(enum4201::CKEYPRESET::AUTO_OVERSHOOTWEIGHTED)};
	static const maxon::EnumInfo CKEYPRESET_info{"CKEYPRESET", SIZEOF(CKEYPRESET), false, "AUTO_CLAMP\0AUTO_OVERSHOOT\0FIXED_OVERSHOOTWEIGHTED\0CUSTOM\0AUTO_OVERSHOOTWEIGHTED\0", CKEYPRESET_values, std::extent<decltype(CKEYPRESET_values)>::value};
}
const maxon::EnumInfo& PrivateGetEnumInfo_CKEYPRESET4201(){ return enum4201::CKEYPRESET_info; }
namespace enum4212
{
	enum class CLIPBOARDTYPE
	{
		EMPTY		= 0,			///< Clipboard is empty.
		STRING	= 1,			///< Clipboard contains a string.
		BITMAP	= 2				///< Clipboard contains a bitmap.
	} ;
	static const maxon::UInt64 CLIPBOARDTYPE_values[] = {maxon::UInt64(enum4212::CLIPBOARDTYPE::EMPTY), maxon::UInt64(enum4212::CLIPBOARDTYPE::STRING), maxon::UInt64(enum4212::CLIPBOARDTYPE::BITMAP)};
	static const maxon::EnumInfo CLIPBOARDTYPE_info{"CLIPBOARDTYPE", SIZEOF(CLIPBOARDTYPE), false, "EMPTY\0STRING\0BITMAP\0", CLIPBOARDTYPE_values, std::extent<decltype(CLIPBOARDTYPE_values)>::value};
}
const maxon::EnumInfo& PrivateGetEnumInfo_CLIPBOARDTYPE4212(){ return enum4212::CLIPBOARDTYPE_info; }
namespace enum4224
{
	enum class EDGESELECTIONTYPE
	{
		SELECTION	= 0,			///< Selected edges.
		HIDDEN		= 1,			///< Hidden edges.
		PHONG			= 2				///< Phong edges.
	} ;
	static const maxon::UInt64 EDGESELECTIONTYPE_values[] = {maxon::UInt64(enum4224::EDGESELECTIONTYPE::SELECTION), maxon::UInt64(enum4224::EDGESELECTIONTYPE::HIDDEN), maxon::UInt64(enum4224::EDGESELECTIONTYPE::PHONG)};
	static const maxon::EnumInfo EDGESELECTIONTYPE_info{"EDGESELECTIONTYPE", SIZEOF(EDGESELECTIONTYPE), false, "SELECTION\0HIDDEN\0PHONG\0", EDGESELECTIONTYPE_values, std::extent<decltype(EDGESELECTIONTYPE_values)>::value};
}
const maxon::EnumInfo& PrivateGetEnumInfo_EDGESELECTIONTYPE4224(){ return enum4224::EDGESELECTIONTYPE_info; }
namespace enum4262
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
	static const maxon::UInt64 REGISTRYTYPE_values[] = {maxon::UInt64(enum4262::REGISTRYTYPE::ANY), maxon::UInt64(enum4262::REGISTRYTYPE::WINDOW), maxon::UInt64(enum4262::REGISTRYTYPE::OBJECT), maxon::UInt64(enum4262::REGISTRYTYPE::TAG), maxon::UInt64(enum4262::REGISTRYTYPE::MATERIAL), maxon::UInt64(enum4262::REGISTRYTYPE::SHADER), maxon::UInt64(enum4262::REGISTRYTYPE::SOUND), maxon::UInt64(enum4262::REGISTRYTYPE::LAYOUT), maxon::UInt64(enum4262::REGISTRYTYPE::BITMAPFILTER), maxon::UInt64(enum4262::REGISTRYTYPE::VIDEOPOST), maxon::UInt64(enum4262::REGISTRYTYPE::SCENEHOOK), maxon::UInt64(enum4262::REGISTRYTYPE::NODE), maxon::UInt64(enum4262::REGISTRYTYPE::DESCRIPTION), maxon::UInt64(enum4262::REGISTRYTYPE::LIBRARY), maxon::UInt64(enum4262::REGISTRYTYPE::CUSTOMDATATYPE), maxon::UInt64(enum4262::REGISTRYTYPE::RESOURCEDATATYPE), maxon::UInt64(enum4262::REGISTRYTYPE::SCENELOADER), maxon::UInt64(enum4262::REGISTRYTYPE::SCENESAVER), maxon::UInt64(enum4262::REGISTRYTYPE::CTRACK), maxon::UInt64(enum4262::REGISTRYTYPE::CSEQ), maxon::UInt64(enum4262::REGISTRYTYPE::CKEY), maxon::UInt64(enum4262::REGISTRYTYPE::PAINTER), maxon::UInt64(enum4262::REGISTRYTYPE::GV_VALUE), maxon::UInt64(enum4262::REGISTRYTYPE::GV_VALGROUP), maxon::UInt64(enum4262::REGISTRYTYPE::GV_OPGROUP), maxon::UInt64(enum4262::REGISTRYTYPE::GV_OPCLASS), maxon::UInt64(enum4262::REGISTRYTYPE::GV_DATA), maxon::UInt64(enum4262::REGISTRYTYPE::GADGETS), maxon::UInt64(enum4262::REGISTRYTYPE::PREFS), maxon::UInt64(enum4262::REGISTRYTYPE::FIELDLAYER)};
	static const maxon::EnumInfo REGISTRYTYPE_info{"REGISTRYTYPE", SIZEOF(REGISTRYTYPE), false, "ANY\0WINDOW\0OBJECT\0TAG\0MATERIAL\0SHADER\0SOUND\0LAYOUT\0BITMAPFILTER\0VIDEOPOST\0SCENEHOOK\0NODE\0DESCRIPTION\0LIBRARY\0CUSTOMDATATYPE\0RESOURCEDATATYPE\0SCENELOADER\0SCENESAVER\0CTRACK\0CSEQ\0CKEY\0PAINTER\0GV_VALUE\0GV_VALGROUP\0GV_OPGROUP\0GV_OPCLASS\0GV_DATA\0GADGETS\0PREFS\0FIELDLAYER\0", REGISTRYTYPE_values, std::extent<decltype(REGISTRYTYPE_values)>::value};
}
const maxon::EnumInfo& PrivateGetEnumInfo_REGISTRYTYPE4262(){ return enum4262::REGISTRYTYPE_info; }
namespace enum4274
{
	enum class MODELINGCOMMANDMODE
	{
		ALL								= 0,			///< All points/polygons.
		POINTSELECTION		= 1,			///< Only the current point selection.
		POLYGONSELECTION	= 2,			///< Only the current polygon selection.
		EDGESELECTION			= 3				///< Only the current edge selection.
	} ;
	static const maxon::UInt64 MODELINGCOMMANDMODE_values[] = {maxon::UInt64(enum4274::MODELINGCOMMANDMODE::ALL), maxon::UInt64(enum4274::MODELINGCOMMANDMODE::POINTSELECTION), maxon::UInt64(enum4274::MODELINGCOMMANDMODE::POLYGONSELECTION), maxon::UInt64(enum4274::MODELINGCOMMANDMODE::EDGESELECTION)};
	static const maxon::EnumInfo MODELINGCOMMANDMODE_info{"MODELINGCOMMANDMODE", SIZEOF(MODELINGCOMMANDMODE), false, "ALL\0POINTSELECTION\0POLYGONSELECTION\0EDGESELECTION\0", MODELINGCOMMANDMODE_values, std::extent<decltype(MODELINGCOMMANDMODE_values)>::value};
}
const maxon::EnumInfo& PrivateGetEnumInfo_MODELINGCOMMANDMODE4274(){ return enum4274::MODELINGCOMMANDMODE_info; }
namespace enum4286
{
	enum class MODELINGCOMMANDFLAGS
	{
		NONE								= 0,						///< None.
		CREATEUNDO					= (1 << 0),			///< Creates undo and inserts newly created objects into ModelingCommandData::doc, instead of returning in ModelingCommandData::result.
		IMPORTER						= (1 << 1),			///< Can be used by importer plugins to avoid additional checks for polygon meshes (e.g conversion of posemorph tags).
		USEGLOBALSYMMETRY		= (1 << 2)			///< Set to let the command to recieve the symmetry settings from the global context.
	} ;
	static const maxon::UInt64 MODELINGCOMMANDFLAGS_values[] = {maxon::UInt64(enum4286::MODELINGCOMMANDFLAGS::NONE), maxon::UInt64(enum4286::MODELINGCOMMANDFLAGS::CREATEUNDO), maxon::UInt64(enum4286::MODELINGCOMMANDFLAGS::IMPORTER), maxon::UInt64(enum4286::MODELINGCOMMANDFLAGS::USEGLOBALSYMMETRY)};
	static const maxon::EnumInfo MODELINGCOMMANDFLAGS_info{"MODELINGCOMMANDFLAGS", SIZEOF(MODELINGCOMMANDFLAGS), true, "NONE\0CREATEUNDO\0IMPORTER\0USEGLOBALSYMMETRY\0", MODELINGCOMMANDFLAGS_values, std::extent<decltype(MODELINGCOMMANDFLAGS_values)>::value};
}
const maxon::EnumInfo& PrivateGetEnumInfo_MODELINGCOMMANDFLAGS4286(){ return enum4286::MODELINGCOMMANDFLAGS_info; }
namespace enum4323
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
		FIELDLAYER					= 37,			///< FieldLayer. (FieldLayer)
		DESCRIPTION         = 38,     ///< Description (not in registry)
	} ;
	static const maxon::UInt64 PLUGINTYPE_values[] = {maxon::UInt64(enum4323::PLUGINTYPE::ANY), maxon::UInt64(enum4323::PLUGINTYPE::SHADER), maxon::UInt64(enum4323::PLUGINTYPE::MATERIAL), maxon::UInt64(enum4323::PLUGINTYPE::COMMAND), maxon::UInt64(enum4323::PLUGINTYPE::OBJECT), maxon::UInt64(enum4323::PLUGINTYPE::TAG), maxon::UInt64(enum4323::PLUGINTYPE::BITMAPFILTER), maxon::UInt64(enum4323::PLUGINTYPE::VIDEOPOST), maxon::UInt64(enum4323::PLUGINTYPE::TOOL), maxon::UInt64(enum4323::PLUGINTYPE::SCENEHOOK), maxon::UInt64(enum4323::PLUGINTYPE::NODE), maxon::UInt64(enum4323::PLUGINTYPE::LIBRARY), maxon::UInt64(enum4323::PLUGINTYPE::BITMAPLOADER), maxon::UInt64(enum4323::PLUGINTYPE::BITMAPSAVER), maxon::UInt64(enum4323::PLUGINTYPE::SCENELOADER), maxon::UInt64(enum4323::PLUGINTYPE::SCENESAVER), maxon::UInt64(enum4323::PLUGINTYPE::COREMESSAGE), maxon::UInt64(enum4323::PLUGINTYPE::CUSTOMGUI), maxon::UInt64(enum4323::PLUGINTYPE::CUSTOMDATATYPE), maxon::UInt64(enum4323::PLUGINTYPE::RESOURCEDATATYPE), maxon::UInt64(enum4323::PLUGINTYPE::MANAGERINFORMATION), maxon::UInt64(enum4323::PLUGINTYPE::CTRACK), maxon::UInt64(enum4323::PLUGINTYPE::FALLOFF), maxon::UInt64(enum4323::PLUGINTYPE::VMAPTRANSFER), maxon::UInt64(enum4323::PLUGINTYPE::PREFS), maxon::UInt64(enum4323::PLUGINTYPE::SNAP), maxon::UInt64(enum4323::PLUGINTYPE::FIELDLAYER), maxon::UInt64(enum4323::PLUGINTYPE::DESCRIPTION)};
	static const maxon::EnumInfo PLUGINTYPE_info{"PLUGINTYPE", SIZEOF(PLUGINTYPE), false, "ANY\0SHADER\0MATERIAL\0COMMAND\0OBJECT\0TAG\0BITMAPFILTER\0VIDEOPOST\0TOOL\0SCENEHOOK\0NODE\0LIBRARY\0BITMAPLOADER\0BITMAPSAVER\0SCENELOADER\0SCENESAVER\0COREMESSAGE\0CUSTOMGUI\0CUSTOMDATATYPE\0RESOURCEDATATYPE\0MANAGERINFORMATION\0CTRACK\0FALLOFF\0VMAPTRANSFER\0PREFS\0SNAP\0FIELDLAYER\0DESCRIPTION\0", PLUGINTYPE_values, std::extent<decltype(PLUGINTYPE_values)>::value};
}
const maxon::EnumInfo& PrivateGetEnumInfo_PLUGINTYPE4323(){ return enum4323::PLUGINTYPE_info; }
namespace enum4334
{
	enum class DRAWRESULT
	{
		FAILURE	= 0,			///< There was an error while drawing.
		OK			= 1,			///< Something was drawn.
		SKIP		= 2				///< There was nothing to draw in this pass.
	} ;
	static const maxon::UInt64 DRAWRESULT_values[] = {maxon::UInt64(enum4334::DRAWRESULT::FAILURE), maxon::UInt64(enum4334::DRAWRESULT::OK), maxon::UInt64(enum4334::DRAWRESULT::SKIP)};
	static const maxon::EnumInfo DRAWRESULT_info{"DRAWRESULT", SIZEOF(DRAWRESULT), false, "FAILURE\0OK\0SKIP\0", DRAWRESULT_values, std::extent<decltype(DRAWRESULT_values)>::value};
}
const maxon::EnumInfo& PrivateGetEnumInfo_DRAWRESULT4334(){ return enum4334::DRAWRESULT_info; }
namespace enum4367
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
	static const maxon::UInt64 DISPLAYMODE_values[] = {maxon::UInt64(enum4367::DISPLAYMODE::UNKNOWN), maxon::UInt64(enum4367::DISPLAYMODE::GOURAUD), maxon::UInt64(enum4367::DISPLAYMODE::QUICK), maxon::UInt64(enum4367::DISPLAYMODE::WIRE), maxon::UInt64(enum4367::DISPLAYMODE::ISOPARM), maxon::UInt64(enum4367::DISPLAYMODE::SHADEDBOX), maxon::UInt64(enum4367::DISPLAYMODE::BOX), maxon::UInt64(enum4367::DISPLAYMODE::SKELETON), maxon::UInt64(enum4367::DISPLAYMODE::GOURAUDWIRE), maxon::UInt64(enum4367::DISPLAYMODE::GOURAUDISOPARM), maxon::UInt64(enum4367::DISPLAYMODE::QUICKWIRE), maxon::UInt64(enum4367::DISPLAYMODE::QUICKISOPARM), maxon::UInt64(enum4367::DISPLAYMODE::FLATWIRE), maxon::UInt64(enum4367::DISPLAYMODE::FLATISOPARM), maxon::UInt64(enum4367::DISPLAYMODE::FLATBOX), maxon::UInt64(enum4367::DISPLAYMODE::HIDDENWIRE), maxon::UInt64(enum4367::DISPLAYMODE::HIDDENISOPARM), maxon::UInt64(enum4367::DISPLAYMODE::HIDDENBOX), maxon::UInt64(enum4367::DISPLAYMODE::SHADEDBOXWIRE), maxon::UInt64(enum4367::DISPLAYMODE::QUICKBOXWIRE), maxon::UInt64(enum4367::DISPLAYMODE::QUICKBOX), maxon::UInt64(enum4367::DISPLAYMODE::PRIVATE_ISOLINE), maxon::UInt64(enum4367::DISPLAYMODE::PRIVATE_FLAT), maxon::UInt64(enum4367::DISPLAYMODE::PRIVATE_HIDDEN)};
	static const maxon::EnumInfo DISPLAYMODE_info{"DISPLAYMODE", SIZEOF(DISPLAYMODE), false, "UNKNOWN\0GOURAUD\0QUICK\0WIRE\0ISOPARM\0SHADEDBOX\0BOX\0SKELETON\0GOURAUDWIRE\0GOURAUDISOPARM\0QUICKWIRE\0QUICKISOPARM\0FLATWIRE\0FLATISOPARM\0FLATBOX\0HIDDENWIRE\0HIDDENISOPARM\0HIDDENBOX\0SHADEDBOXWIRE\0QUICKBOXWIRE\0QUICKBOX\0PRIVATE_ISOLINE\0PRIVATE_FLAT\0PRIVATE_HIDDEN\0", DISPLAYMODE_values, std::extent<decltype(DISPLAYMODE_values)>::value};
}
const maxon::EnumInfo& PrivateGetEnumInfo_DISPLAYMODE4367(){ return enum4367::DISPLAYMODE_info; }
namespace enum4383
{
	enum class DOCUMENTSETTINGS
	{
		GENERAL					= 0,			///< General settings.
		MODELING				= 1,			///< Modeler settings. (See @ref MDATA options.)
		DOCUMENT				= 2,			///< Document settings.
		ANIMATIONSYSTEM	= 7,			///< Timeline settings. @markPrivate
		TOOLS						= 8				///< Tools settings.
	} ;
	static const maxon::UInt64 DOCUMENTSETTINGS_values[] = {maxon::UInt64(enum4383::DOCUMENTSETTINGS::GENERAL), maxon::UInt64(enum4383::DOCUMENTSETTINGS::MODELING), maxon::UInt64(enum4383::DOCUMENTSETTINGS::DOCUMENT), maxon::UInt64(enum4383::DOCUMENTSETTINGS::ANIMATIONSYSTEM), maxon::UInt64(enum4383::DOCUMENTSETTINGS::TOOLS)};
	static const maxon::EnumInfo DOCUMENTSETTINGS_info{"DOCUMENTSETTINGS", SIZEOF(DOCUMENTSETTINGS), false, "GENERAL\0MODELING\0DOCUMENT\0ANIMATIONSYSTEM\0TOOLS\0", DOCUMENTSETTINGS_values, std::extent<decltype(DOCUMENTSETTINGS_values)>::value};
}
const maxon::EnumInfo& PrivateGetEnumInfo_DOCUMENTSETTINGS4383(){ return enum4383::DOCUMENTSETTINGS_info; }
namespace enum4408
{
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
	} ;
	static const maxon::UInt64 VERSIONTYPE_values[] = {maxon::UInt64(enum4408::VERSIONTYPE::UNKNOWN), maxon::UInt64(enum4408::VERSIONTYPE::LITE), maxon::UInt64(enum4408::VERSIONTYPE::BENCHMARK), maxon::UInt64(enum4408::VERSIONTYPE::UPDATER_EX), maxon::UInt64(enum4408::VERSIONTYPE::TEAMRENDER_CLIENT), maxon::UInt64(enum4408::VERSIONTYPE::TEAMRENDER_SERVER), maxon::UInt64(enum4408::VERSIONTYPE::CINEMA4D), maxon::UInt64(enum4408::VERSIONTYPE::COMMANDLINE), maxon::UInt64(enum4408::VERSIONTYPE::CINEWARE), maxon::UInt64(enum4408::VERSIONTYPE::CPYTHON), maxon::UInt64(enum4408::VERSIONTYPE::CPYTHON3)};
	static const maxon::EnumInfo VERSIONTYPE_info{"VERSIONTYPE", SIZEOF(VERSIONTYPE), false, "UNKNOWN\0LITE\0BENCHMARK\0UPDATER_EX\0TEAMRENDER_CLIENT\0TEAMRENDER_SERVER\0CINEMA4D\0COMMANDLINE\0CINEWARE\0CPYTHON\0CPYTHON3\0", VERSIONTYPE_values, std::extent<decltype(VERSIONTYPE_values)>::value};
}
const maxon::EnumInfo& PrivateGetEnumInfo_VERSIONTYPE4408(){ return enum4408::VERSIONTYPE_info; }
namespace enum4421
{
	enum class LAYERSETMODE
	{
		LAYERS,					///< Layers / layer Sets.
		LAYERMASKS,			///< Layer masks.
		ALPHAS,					///< Alpha channels.
		LAYERALPHA,			///< Layer alpha.
		DISABLED				///< Disabled.
	} ;
	static const maxon::UInt64 LAYERSETMODE_values[] = {maxon::UInt64(enum4421::LAYERSETMODE::LAYERS), maxon::UInt64(enum4421::LAYERSETMODE::LAYERMASKS), maxon::UInt64(enum4421::LAYERSETMODE::ALPHAS), maxon::UInt64(enum4421::LAYERSETMODE::LAYERALPHA), maxon::UInt64(enum4421::LAYERSETMODE::DISABLED)};
	static const maxon::EnumInfo LAYERSETMODE_info{"LAYERSETMODE", SIZEOF(LAYERSETMODE), false, "LAYERS\0LAYERMASKS\0ALPHAS\0LAYERALPHA\0DISABLED\0", LAYERSETMODE_values, std::extent<decltype(LAYERSETMODE_values)>::value};
}
const maxon::EnumInfo& PrivateGetEnumInfo_LAYERSETMODE4421(){ return enum4421::LAYERSETMODE_info; }
namespace enum4468
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
	static const maxon::UInt64 OBJECTCATEGORY_values[] = {maxon::UInt64(enum4468::OBJECTCATEGORY::NULLOBJECT), maxon::UInt64(enum4468::OBJECTCATEGORY::POLYGON), maxon::UInt64(enum4468::OBJECTCATEGORY::SPLINE), maxon::UInt64(enum4468::OBJECTCATEGORY::GENERATOR), maxon::UInt64(enum4468::OBJECTCATEGORY::HYPERNURBS), maxon::UInt64(enum4468::OBJECTCATEGORY::UNUSED1), maxon::UInt64(enum4468::OBJECTCATEGORY::DEFORMER), maxon::UInt64(enum4468::OBJECTCATEGORY::CAMERA), maxon::UInt64(enum4468::OBJECTCATEGORY::LIGHT), maxon::UInt64(enum4468::OBJECTCATEGORY::SCENE), maxon::UInt64(enum4468::OBJECTCATEGORY::PARTICLE), maxon::UInt64(enum4468::OBJECTCATEGORY::OTHER), maxon::UInt64(enum4468::OBJECTCATEGORY::UNUSED2), maxon::UInt64(enum4468::OBJECTCATEGORY::GRID), maxon::UInt64(enum4468::OBJECTCATEGORY::HORIZON), maxon::UInt64(enum4468::OBJECTCATEGORY::WORLDAXIS), maxon::UInt64(enum4468::OBJECTCATEGORY::BOUNDS), maxon::UInt64(enum4468::OBJECTCATEGORY::HUD), maxon::UInt64(enum4468::OBJECTCATEGORY::SDS), maxon::UInt64(enum4468::OBJECTCATEGORY::HIGHLIGHTING), maxon::UInt64(enum4468::OBJECTCATEGORY::MULTIAXIS), maxon::UInt64(enum4468::OBJECTCATEGORY::OBJECTHANDLES), maxon::UInt64(enum4468::OBJECTCATEGORY::HANDLEBANDS), maxon::UInt64(enum4468::OBJECTCATEGORY::SDSCAGE), maxon::UInt64(enum4468::OBJECTCATEGORY::NGONLINES), maxon::UInt64(enum4468::OBJECTCATEGORY::JOINT), maxon::UInt64(enum4468::OBJECTCATEGORY::OBJECTHIGHLIGHTING), maxon::UInt64(enum4468::OBJECTCATEGORY::GUIDELINES), maxon::UInt64(enum4468::OBJECTCATEGORY::POI), maxon::UInt64(enum4468::OBJECTCATEGORY::GRADIENT), maxon::UInt64(enum4468::OBJECTCATEGORY::BASEGRID), maxon::UInt64(enum4468::OBJECTCATEGORY::HANDLES), maxon::UInt64(enum4468::OBJECTCATEGORY::HAIR), maxon::UInt64(enum4468::OBJECTCATEGORY::FIELD)};
	static const maxon::EnumInfo OBJECTCATEGORY_info{"OBJECTCATEGORY", SIZEOF(OBJECTCATEGORY), false, "NULLOBJECT\0POLYGON\0SPLINE\0GENERATOR\0HYPERNURBS\0UNUSED1\0DEFORMER\0CAMERA\0LIGHT\0SCENE\0PARTICLE\0OTHER\0UNUSED2\0GRID\0HORIZON\0WORLDAXIS\0BOUNDS\0HUD\0SDS\0HIGHLIGHTING\0MULTIAXIS\0OBJECTHANDLES\0HANDLEBANDS\0SDSCAGE\0NGONLINES\0JOINT\0OBJECTHIGHLIGHTING\0GUIDELINES\0POI\0GRADIENT\0BASEGRID\0HANDLES\0HAIR\0FIELD\0", OBJECTCATEGORY_values, std::extent<decltype(OBJECTCATEGORY_values)>::value};
}
const maxon::EnumInfo& PrivateGetEnumInfo_OBJECTCATEGORY4468(){ return enum4468::OBJECTCATEGORY_info; }
namespace enum4489
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
	static const maxon::UInt64 SELECTIONFILTERBIT_values[] = {maxon::UInt64(enum4489::SELECTIONFILTERBIT::NONE), maxon::UInt64(enum4489::SELECTIONFILTERBIT::NULLOBJECT), maxon::UInt64(enum4489::SELECTIONFILTERBIT::POLYGON), maxon::UInt64(enum4489::SELECTIONFILTERBIT::SPLINE), maxon::UInt64(enum4489::SELECTIONFILTERBIT::GENERATOR), maxon::UInt64(enum4489::SELECTIONFILTERBIT::HYPERNURBS), maxon::UInt64(enum4489::SELECTIONFILTERBIT::DEFORMER), maxon::UInt64(enum4489::SELECTIONFILTERBIT::CAMERA), maxon::UInt64(enum4489::SELECTIONFILTERBIT::LIGHT), maxon::UInt64(enum4489::SELECTIONFILTERBIT::SCENE), maxon::UInt64(enum4489::SELECTIONFILTERBIT::PARTICLE), maxon::UInt64(enum4489::SELECTIONFILTERBIT::OTHER), maxon::UInt64(enum4489::SELECTIONFILTERBIT::JOINT)};
	static const maxon::EnumInfo SELECTIONFILTERBIT_info{"SELECTIONFILTERBIT", SIZEOF(SELECTIONFILTERBIT), true, "NONE\0NULLOBJECT\0POLYGON\0SPLINE\0GENERATOR\0HYPERNURBS\0DEFORMER\0CAMERA\0LIGHT\0SCENE\0PARTICLE\0OTHER\0JOINT\0", SELECTIONFILTERBIT_values, std::extent<decltype(SELECTIONFILTERBIT_values)>::value};
}
const maxon::EnumInfo& PrivateGetEnumInfo_SELECTIONFILTERBIT4489(){ return enum4489::SELECTIONFILTERBIT_info; }
namespace enum4503
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
	static const maxon::UInt64 OBJECTSTATE_values[] = {maxon::UInt64(enum4503::OBJECTSTATE::EDITOR), maxon::UInt64(enum4503::OBJECTSTATE::RENDER), maxon::UInt64(enum4503::OBJECTSTATE::DEFORM), maxon::UInt64(enum4503::OBJECTSTATE::REAL_DEFORM), maxon::UInt64(enum4503::OBJECTSTATE::EDITOR_HIERARCHICAL), maxon::UInt64(enum4503::OBJECTSTATE::RENDER_HIERARCHICAL)};
	static const maxon::EnumInfo OBJECTSTATE_info{"OBJECTSTATE", SIZEOF(OBJECTSTATE), false, "EDITOR\0RENDER\0DEFORM\0REAL_DEFORM\0EDITOR_HIERARCHICAL\0RENDER_HIERARCHICAL\0", OBJECTSTATE_values, std::extent<decltype(OBJECTSTATE_values)>::value};
}
const maxon::EnumInfo& PrivateGetEnumInfo_OBJECTSTATE4503(){ return enum4503::OBJECTSTATE_info; }
namespace enum4548
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
	static const maxon::UInt64 DISPLAYFILTER_values[] = {maxon::UInt64(enum4548::DISPLAYFILTER::NONE), maxon::UInt64(enum4548::DISPLAYFILTER::NULLOBJECT), maxon::UInt64(enum4548::DISPLAYFILTER::POLYGON), maxon::UInt64(enum4548::DISPLAYFILTER::SPLINE), maxon::UInt64(enum4548::DISPLAYFILTER::GENERATOR), maxon::UInt64(enum4548::DISPLAYFILTER::HYPERNURBS), maxon::UInt64(enum4548::DISPLAYFILTER::UNUSED1), maxon::UInt64(enum4548::DISPLAYFILTER::DEFORMER), maxon::UInt64(enum4548::DISPLAYFILTER::CAMERA), maxon::UInt64(enum4548::DISPLAYFILTER::LIGHT), maxon::UInt64(enum4548::DISPLAYFILTER::SCENE), maxon::UInt64(enum4548::DISPLAYFILTER::PARTICLE), maxon::UInt64(enum4548::DISPLAYFILTER::OTHER), maxon::UInt64(enum4548::DISPLAYFILTER::UNUSED2), maxon::UInt64(enum4548::DISPLAYFILTER::GRID), maxon::UInt64(enum4548::DISPLAYFILTER::HORIZON), maxon::UInt64(enum4548::DISPLAYFILTER::WORLDAXIS), maxon::UInt64(enum4548::DISPLAYFILTER::BOUNDS), maxon::UInt64(enum4548::DISPLAYFILTER::HUD), maxon::UInt64(enum4548::DISPLAYFILTER::SDS), maxon::UInt64(enum4548::DISPLAYFILTER::HIGHLIGHTING), maxon::UInt64(enum4548::DISPLAYFILTER::MULTIAXIS), maxon::UInt64(enum4548::DISPLAYFILTER::OBJECTHANDLES), maxon::UInt64(enum4548::DISPLAYFILTER::HANDLEBANDS), maxon::UInt64(enum4548::DISPLAYFILTER::SDSCAGE), maxon::UInt64(enum4548::DISPLAYFILTER::NGONLINES), maxon::UInt64(enum4548::DISPLAYFILTER::JOINT), maxon::UInt64(enum4548::DISPLAYFILTER::OBJECTHIGHLIGHTING), maxon::UInt64(enum4548::DISPLAYFILTER::GUIDELINES), maxon::UInt64(enum4548::DISPLAYFILTER::POI), maxon::UInt64(enum4548::DISPLAYFILTER::GRADIENT), maxon::UInt64(enum4548::DISPLAYFILTER::BASEGRID), maxon::UInt64(enum4548::DISPLAYFILTER::HANDLES), maxon::UInt64(enum4548::DISPLAYFILTER::HAIR), maxon::UInt64(enum4548::DISPLAYFILTER::FIELD)};
	static const maxon::EnumInfo DISPLAYFILTER_info{"DISPLAYFILTER", SIZEOF(DISPLAYFILTER), true, "NONE\0NULLOBJECT\0POLYGON\0SPLINE\0GENERATOR\0HYPERNURBS\0UNUSED1\0DEFORMER\0CAMERA\0LIGHT\0SCENE\0PARTICLE\0OTHER\0UNUSED2\0GRID\0HORIZON\0WORLDAXIS\0BOUNDS\0HUD\0SDS\0HIGHLIGHTING\0MULTIAXIS\0OBJECTHANDLES\0HANDLEBANDS\0SDSCAGE\0NGONLINES\0JOINT\0OBJECTHIGHLIGHTING\0GUIDELINES\0POI\0GRADIENT\0BASEGRID\0HANDLES\0HAIR\0FIELD\0", DISPLAYFILTER_values, std::extent<decltype(DISPLAYFILTER_values)>::value};
}
const maxon::EnumInfo& PrivateGetEnumInfo_DISPLAYFILTER4548(){ return enum4548::DISPLAYFILTER_info; }
namespace enum4562
{
	enum class DISPLAYEDITSTATE
	{
		NONE			= 0,						///< None.
		SDS				= (1 << 0),			///< SDS edit state.
		DEFORM		= (1 << 1),			///< Deformed edit state.
	
		DOCUMENT	= -1			///< Document edit state.
	} ;
	static const maxon::UInt64 DISPLAYEDITSTATE_values[] = {maxon::UInt64(enum4562::DISPLAYEDITSTATE::NONE), maxon::UInt64(enum4562::DISPLAYEDITSTATE::SDS), maxon::UInt64(enum4562::DISPLAYEDITSTATE::DEFORM), maxon::UInt64(enum4562::DISPLAYEDITSTATE::DOCUMENT)};
	static const maxon::EnumInfo DISPLAYEDITSTATE_info{"DISPLAYEDITSTATE", SIZEOF(DISPLAYEDITSTATE), true, "NONE\0SDS\0DEFORM\0DOCUMENT\0", DISPLAYEDITSTATE_values, std::extent<decltype(DISPLAYEDITSTATE_values)>::value};
}
const maxon::EnumInfo& PrivateGetEnumInfo_DISPLAYEDITSTATE4562(){ return enum4562::DISPLAYEDITSTATE_info; }
namespace enum4574
{
	enum class THREADTYPE
	{
		NONE						= 0,						///< None.
		EDITORREDRAW		= (1 << 0),			///< Editor redraw.
		RENDEREDITOR		= (1 << 1),			///< Editor render.
		RENDEREXTERNAL	= (1 << 2)			///< External render.
	} ;
	static const maxon::UInt64 THREADTYPE_values[] = {maxon::UInt64(enum4574::THREADTYPE::NONE), maxon::UInt64(enum4574::THREADTYPE::EDITORREDRAW), maxon::UInt64(enum4574::THREADTYPE::RENDEREDITOR), maxon::UInt64(enum4574::THREADTYPE::RENDEREXTERNAL)};
	static const maxon::EnumInfo THREADTYPE_info{"THREADTYPE", SIZEOF(THREADTYPE), true, "NONE\0EDITORREDRAW\0RENDEREDITOR\0RENDEREXTERNAL\0", THREADTYPE_values, std::extent<decltype(THREADTYPE_values)>::value};
}
const maxon::EnumInfo& PrivateGetEnumInfo_THREADTYPE4574(){ return enum4574::THREADTYPE_info; }
namespace enum4589
{
	enum class RENDERPROGRESSTYPE
	{
		BEFORERENDERING			= 0,			///< Before rendering.
		DURINGRENDERING			= 1,			///< During rendering.
		AFTERRENDERING			= 2,			///< After rendering.
		GLOBALILLUMINATION	= 3,			///< GI prepass.
		QUICK_PREVIEW				= 4,			///< Quick Preview rendering. @since R17.048
		AMBIENTOCCLUSION		= 5,			///< AO prepass. @since CR17.054 / R18.021
		CANCELLED						= 6				///< Rendering cancelled. @since R2024
	} ;
	static const maxon::UInt64 RENDERPROGRESSTYPE_values[] = {maxon::UInt64(enum4589::RENDERPROGRESSTYPE::BEFORERENDERING), maxon::UInt64(enum4589::RENDERPROGRESSTYPE::DURINGRENDERING), maxon::UInt64(enum4589::RENDERPROGRESSTYPE::AFTERRENDERING), maxon::UInt64(enum4589::RENDERPROGRESSTYPE::GLOBALILLUMINATION), maxon::UInt64(enum4589::RENDERPROGRESSTYPE::QUICK_PREVIEW), maxon::UInt64(enum4589::RENDERPROGRESSTYPE::AMBIENTOCCLUSION), maxon::UInt64(enum4589::RENDERPROGRESSTYPE::CANCELLED)};
	static const maxon::EnumInfo RENDERPROGRESSTYPE_info{"RENDERPROGRESSTYPE", SIZEOF(RENDERPROGRESSTYPE), false, "BEFORERENDERING\0DURINGRENDERING\0AFTERRENDERING\0GLOBALILLUMINATION\0QUICK_PREVIEW\0AMBIENTOCCLUSION\0CANCELLED\0", RENDERPROGRESSTYPE_values, std::extent<decltype(RENDERPROGRESSTYPE_values)>::value};
}
const maxon::EnumInfo& PrivateGetEnumInfo_RENDERPROGRESSTYPE4589(){ return enum4589::RENDERPROGRESSTYPE_info; }
namespace enum4600
{
	enum class RDATA_SAVECALLBACK_CMD
	{
		OPEN	= 1,			///< Open call.
		WRITE	= 2,			///< Write call.
		CLOSE	= 3				///< Close call.
	} ;
	static const maxon::UInt64 RDATA_SAVECALLBACK_CMD_values[] = {maxon::UInt64(enum4600::RDATA_SAVECALLBACK_CMD::OPEN), maxon::UInt64(enum4600::RDATA_SAVECALLBACK_CMD::WRITE), maxon::UInt64(enum4600::RDATA_SAVECALLBACK_CMD::CLOSE)};
	static const maxon::EnumInfo RDATA_SAVECALLBACK_CMD_info{"RDATA_SAVECALLBACK_CMD", SIZEOF(RDATA_SAVECALLBACK_CMD), false, "OPEN\0WRITE\0CLOSE\0", RDATA_SAVECALLBACK_CMD_values, std::extent<decltype(RDATA_SAVECALLBACK_CMD_values)>::value};
}
const maxon::EnumInfo& PrivateGetEnumInfo_RDATA_SAVECALLBACK_CMD4600(){ return enum4600::RDATA_SAVECALLBACK_CMD_info; }
namespace enum4614
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
	static const maxon::UInt64 VPGETINFO_values[] = {maxon::UInt64(enum4614::VPGETINFO::XRESOLUTION), maxon::UInt64(enum4614::VPGETINFO::YRESOLUTION), maxon::UInt64(enum4614::VPGETINFO::BITDEPTH), maxon::UInt64(enum4614::VPGETINFO::CPP), maxon::UInt64(enum4614::VPGETINFO::VISIBLE), maxon::UInt64(enum4614::VPGETINFO::LINEOFFSET)};
	static const maxon::EnumInfo VPGETINFO_info{"VPGETINFO", SIZEOF(VPGETINFO), false, "XRESOLUTION\0YRESOLUTION\0BITDEPTH\0CPP\0VISIBLE\0LINEOFFSET\0", VPGETINFO_values, std::extent<decltype(VPGETINFO_values)>::value};
}
const maxon::EnumInfo& PrivateGetEnumInfo_VPGETINFO4614(){ return enum4614::VPGETINFO_info; }
namespace enum4650
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
	static const maxon::UInt64 DRAWOBJECT_values[] = {maxon::UInt64(enum4650::DRAWOBJECT::NONE), maxon::UInt64(enum4650::DRAWOBJECT::FORCELINES), maxon::UInt64(enum4650::DRAWOBJECT::NOBACKCULL), maxon::UInt64(enum4650::DRAWOBJECT::LOCALMATRIX), maxon::UInt64(enum4650::DRAWOBJECT::EDITMODE), maxon::UInt64(enum4650::DRAWOBJECT::FORCEBASE), maxon::UInt64(enum4650::DRAWOBJECT::FORCEPOINTS), maxon::UInt64(enum4650::DRAWOBJECT::NO_EOGL), maxon::UInt64(enum4650::DRAWOBJECT::USE_OBJECT_COLOR), maxon::UInt64(enum4650::DRAWOBJECT::USE_CUSTOM_COLOR), maxon::UInt64(enum4650::DRAWOBJECT::XRAY_ON), maxon::UInt64(enum4650::DRAWOBJECT::XRAY_OFF), maxon::UInt64(enum4650::DRAWOBJECT::IMMEDIATELY), maxon::UInt64(enum4650::DRAWOBJECT::Z_OFFSET), maxon::UInt64(enum4650::DRAWOBJECT::PRIVATE_ANY)};
	static const maxon::EnumInfo DRAWOBJECT_info{"DRAWOBJECT", SIZEOF(DRAWOBJECT), true, "NONE\0FORCELINES\0NOBACKCULL\0LOCALMATRIX\0EDITMODE\0FORCEBASE\0FORCEPOINTS\0NO_EOGL\0USE_OBJECT_COLOR\0USE_CUSTOM_COLOR\0XRAY_ON\0XRAY_OFF\0IMMEDIATELY\0Z_OFFSET\0PRIVATE_ANY\0", DRAWOBJECT_values, std::extent<decltype(DRAWOBJECT_values)>::value};
}
const maxon::EnumInfo& PrivateGetEnumInfo_DRAWOBJECT4650(){ return enum4650::DRAWOBJECT_info; }
namespace enum4676
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
	static const maxon::UInt64 RENDERFLAGS_values[] = {maxon::UInt64(enum4676::RENDERFLAGS::NONE), maxon::UInt64(enum4676::RENDERFLAGS::EXTERNAL), maxon::UInt64(enum4676::RENDERFLAGS::NODOCUMENTCLONE), maxon::UInt64(enum4676::RENDERFLAGS::SHOWERRORS), maxon::UInt64(enum4676::RENDERFLAGS::PREVIEWRENDER), maxon::UInt64(enum4676::RENDERFLAGS::IRR), maxon::UInt64(enum4676::RENDERFLAGS::CREATE_PICTUREVIEWER), maxon::UInt64(enum4676::RENDERFLAGS::OPEN_PICTUREVIEWER), maxon::UInt64(enum4676::RENDERFLAGS::KEEP_CONTEXT), maxon::UInt64(enum4676::RENDERFLAGS::BATCHRENDER), maxon::UInt64(enum4676::RENDERFLAGS::NET), maxon::UInt64(enum4676::RENDERFLAGS::DONTANIMATE), maxon::UInt64(enum4676::RENDERFLAGS::PREVIEWSETTINGS), maxon::UInt64(enum4676::RENDERFLAGS::RENDERQUEUEERRORS), maxon::UInt64(enum4676::RENDERFLAGS::FORCE_LINEAR_COLOR_PROFILE), maxon::UInt64(enum4676::RENDERFLAGS::INTERNAL_USE_CURRENT_QUEUE), maxon::UInt64(enum4676::RENDERFLAGS::INTERNAL_SPECIAL_PREVIEW)};
	static const maxon::EnumInfo RENDERFLAGS_info{"RENDERFLAGS", SIZEOF(RENDERFLAGS), true, "NONE\0EXTERNAL\0NODOCUMENTCLONE\0SHOWERRORS\0PREVIEWRENDER\0IRR\0CREATE_PICTUREVIEWER\0OPEN_PICTUREVIEWER\0KEEP_CONTEXT\0BATCHRENDER\0NET\0DONTANIMATE\0PREVIEWSETTINGS\0RENDERQUEUEERRORS\0FORCE_LINEAR_COLOR_PROFILE\0INTERNAL_USE_CURRENT_QUEUE\0INTERNAL_SPECIAL_PREVIEW\0", RENDERFLAGS_values, std::extent<decltype(RENDERFLAGS_values)>::value};
}
const maxon::EnumInfo& PrivateGetEnumInfo_RENDERFLAGS4676(){ return enum4676::RENDERFLAGS_info; }
namespace enum4687
{
	enum class WRITEMODE
	{
		STANDARD							= 0,		///< Standard.
		ASSEMBLE_MOVIE				= 1,		///< Assemble movie.
		ASSEMBLE_SINGLEIMAGE	= 2			///< Assemble single image.
	} ;
	static const maxon::UInt64 WRITEMODE_values[] = {maxon::UInt64(enum4687::WRITEMODE::STANDARD), maxon::UInt64(enum4687::WRITEMODE::ASSEMBLE_MOVIE), maxon::UInt64(enum4687::WRITEMODE::ASSEMBLE_SINGLEIMAGE)};
	static const maxon::EnumInfo WRITEMODE_info{"WRITEMODE", SIZEOF(WRITEMODE), false, "STANDARD\0ASSEMBLE_MOVIE\0ASSEMBLE_SINGLEIMAGE\0", WRITEMODE_values, std::extent<decltype(WRITEMODE_values)>::value};
}
const maxon::EnumInfo& PrivateGetEnumInfo_WRITEMODE4687(){ return enum4687::WRITEMODE_info; }
namespace enum4707
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
	static const maxon::UInt64 NETRENDERFLAGS_values[] = {maxon::UInt64(enum4707::NETRENDERFLAGS::NONE), maxon::UInt64(enum4707::NETRENDERFLAGS::OPEN_PICTUREVIEWER), maxon::UInt64(enum4707::NETRENDERFLAGS::SHOWERRORS), maxon::UInt64(enum4707::NETRENDERFLAGS::DELETEAFTERRENDERING), maxon::UInt64(enum4707::NETRENDERFLAGS::NOPEERTOPEERASSETDISTRIBUTION), maxon::UInt64(enum4707::NETRENDERFLAGS::NOREQUESTONDEMAND), maxon::UInt64(enum4707::NETRENDERFLAGS::EXCLUDECLIENTONLOADINGERROR), maxon::UInt64(enum4707::NETRENDERFLAGS::SAVERESULTSINREPOSITORY), maxon::UInt64(enum4707::NETRENDERFLAGS::ASSEMBLEB3DFILESIMMEDIATLEY), maxon::UInt64(enum4707::NETRENDERFLAGS::NOWRITETEST), maxon::UInt64(enum4707::NETRENDERFLAGS::HANDLEWARNINGASERROR), maxon::UInt64(enum4707::NETRENDERFLAGS::KEEPB3DFILESAFTERASSEMBLING)};
	static const maxon::EnumInfo NETRENDERFLAGS_info{"NETRENDERFLAGS", SIZEOF(NETRENDERFLAGS), true, "NONE\0OPEN_PICTUREVIEWER\0SHOWERRORS\0DELETEAFTERRENDERING\0NOPEERTOPEERASSETDISTRIBUTION\0NOREQUESTONDEMAND\0EXCLUDECLIENTONLOADINGERROR\0SAVERESULTSINREPOSITORY\0ASSEMBLEB3DFILESIMMEDIATLEY\0NOWRITETEST\0HANDLEWARNINGASERROR\0KEEPB3DFILESAFTERASSEMBLING\0", NETRENDERFLAGS_values, std::extent<decltype(NETRENDERFLAGS_values)>::value};
}
const maxon::EnumInfo& PrivateGetEnumInfo_NETRENDERFLAGS4707(){ return enum4707::NETRENDERFLAGS_info; }
namespace enum4724
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
	static const maxon::UInt64 CHECKISRUNNING_values[] = {maxon::UInt64(enum4724::CHECKISRUNNING::ANIMATIONRUNNING), maxon::UInt64(enum4724::CHECKISRUNNING::VIEWDRAWING), maxon::UInt64(enum4724::CHECKISRUNNING::EDITORRENDERING), maxon::UInt64(enum4724::CHECKISRUNNING::EXTERNALRENDERING), maxon::UInt64(enum4724::CHECKISRUNNING::PAINTERUPDATING), maxon::UInt64(enum4724::CHECKISRUNNING::MATERIALPREVIEWRUNNING), maxon::UInt64(enum4724::CHECKISRUNNING::EVENTSYSTEM), maxon::UInt64(enum4724::CHECKISRUNNING::BAKING), maxon::UInt64(enum4724::CHECKISRUNNING::INTERACTIVERENDERING)};
	static const maxon::EnumInfo CHECKISRUNNING_info{"CHECKISRUNNING", SIZEOF(CHECKISRUNNING), false, "ANIMATIONRUNNING\0VIEWDRAWING\0EDITORRENDERING\0EXTERNALRENDERING\0PAINTERUPDATING\0MATERIALPREVIEWRUNNING\0EVENTSYSTEM\0BAKING\0INTERACTIVERENDERING\0", CHECKISRUNNING_values, std::extent<decltype(CHECKISRUNNING_values)>::value};
}
const maxon::EnumInfo& PrivateGetEnumInfo_CHECKISRUNNING4724(){ return enum4724::CHECKISRUNNING_info; }
namespace enum4744
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
	static const maxon::UInt64 BAKE_TEX_ERR_values[] = {maxon::UInt64(enum4744::BAKE_TEX_ERR::NONE), maxon::UInt64(enum4744::BAKE_TEX_ERR::NO_DOC), maxon::UInt64(enum4744::BAKE_TEX_ERR::NO_MEM), maxon::UInt64(enum4744::BAKE_TEX_ERR::NO_RENDER_DOC), maxon::UInt64(enum4744::BAKE_TEX_ERR::NO_TEXTURE_TAG), maxon::UInt64(enum4744::BAKE_TEX_ERR::NO_OBJECT), maxon::UInt64(enum4744::BAKE_TEX_ERR::NO_UVW_TAG), maxon::UInt64(enum4744::BAKE_TEX_ERR::TEXTURE_MISSING), maxon::UInt64(enum4744::BAKE_TEX_ERR::WRONG_BITMAP), maxon::UInt64(enum4744::BAKE_TEX_ERR::USERBREAK), maxon::UInt64(enum4744::BAKE_TEX_ERR::NO_OPTIMAL_MAPPING), maxon::UInt64(enum4744::BAKE_TEX_ERR::NO_SOURCE_UVW_TAG)};
	static const maxon::EnumInfo BAKE_TEX_ERR_info{"BAKE_TEX_ERR", SIZEOF(BAKE_TEX_ERR), false, "NONE\0NO_DOC\0NO_MEM\0NO_RENDER_DOC\0NO_TEXTURE_TAG\0NO_OBJECT\0NO_UVW_TAG\0TEXTURE_MISSING\0WRONG_BITMAP\0USERBREAK\0NO_OPTIMAL_MAPPING\0NO_SOURCE_UVW_TAG\0", BAKE_TEX_ERR_values, std::extent<decltype(BAKE_TEX_ERR_values)>::value};
}
const maxon::EnumInfo& PrivateGetEnumInfo_BAKE_TEX_ERR4744(){ return enum4744::BAKE_TEX_ERR_info; }
namespace enum4755
{
	enum class GL_MESSAGE
	{
		OK							= 1,
		ERROR_					= 0,
		FORCE_EMULATION	= 2
	} ;
	static const maxon::UInt64 GL_MESSAGE_values[] = {maxon::UInt64(enum4755::GL_MESSAGE::OK), maxon::UInt64(enum4755::GL_MESSAGE::ERROR_), maxon::UInt64(enum4755::GL_MESSAGE::FORCE_EMULATION)};
	static const maxon::EnumInfo GL_MESSAGE_info{"GL_MESSAGE", SIZEOF(GL_MESSAGE), false, "OK\0ERROR_\0FORCE_EMULATION\0", GL_MESSAGE_values, std::extent<decltype(GL_MESSAGE_values)>::value};
}
const maxon::EnumInfo& PrivateGetEnumInfo_GL_MESSAGE4755(){ return enum4755::GL_MESSAGE_info; }
namespace enum4772
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
	static const maxon::UInt64 VIEWPORT_PICK_FLAGS_values[] = {maxon::UInt64(enum4772::VIEWPORT_PICK_FLAGS::NONE), maxon::UInt64(enum4772::VIEWPORT_PICK_FLAGS::ALLOW_OGL), maxon::UInt64(enum4772::VIEWPORT_PICK_FLAGS::DONT_STOP_THREADS), maxon::UInt64(enum4772::VIEWPORT_PICK_FLAGS::USE_SEL_FILTER), maxon::UInt64(enum4772::VIEWPORT_PICK_FLAGS::OGL_ONLY_TOPMOST), maxon::UInt64(enum4772::VIEWPORT_PICK_FLAGS::OGL_ONLY_VISIBLE), maxon::UInt64(enum4772::VIEWPORT_PICK_FLAGS::OGL_IGNORE_Z), maxon::UInt64(enum4772::VIEWPORT_PICK_FLAGS::OGL_ONLY_TOPMOST_WITH_OBJ), maxon::UInt64(enum4772::VIEWPORT_PICK_FLAGS::NO_DEPTH_CORRECTION)};
	static const maxon::EnumInfo VIEWPORT_PICK_FLAGS_info{"VIEWPORT_PICK_FLAGS", SIZEOF(VIEWPORT_PICK_FLAGS), true, "NONE\0ALLOW_OGL\0DONT_STOP_THREADS\0USE_SEL_FILTER\0OGL_ONLY_TOPMOST\0OGL_ONLY_VISIBLE\0OGL_IGNORE_Z\0OGL_ONLY_TOPMOST_WITH_OBJ\0NO_DEPTH_CORRECTION\0", VIEWPORT_PICK_FLAGS_values, std::extent<decltype(VIEWPORT_PICK_FLAGS_values)>::value};
}
const maxon::EnumInfo& PrivateGetEnumInfo_VIEWPORT_PICK_FLAGS4772(){ return enum4772::VIEWPORT_PICK_FLAGS_info; }
namespace enum4812
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
	static const maxon::UInt64 BACKGROUNDHANDLERCOMMAND_values[] = {maxon::UInt64(enum4812::BACKGROUNDHANDLERCOMMAND::ISRUNNING), maxon::UInt64(enum4812::BACKGROUNDHANDLERCOMMAND::STOP), maxon::UInt64(enum4812::BACKGROUNDHANDLERCOMMAND::START), maxon::UInt64(enum4812::BACKGROUNDHANDLERCOMMAND::REMOVE)};
	static const maxon::EnumInfo BACKGROUNDHANDLERCOMMAND_info{"BACKGROUNDHANDLERCOMMAND", SIZEOF(BACKGROUNDHANDLERCOMMAND), false, "ISRUNNING\0STOP\0START\0REMOVE\0", BACKGROUNDHANDLERCOMMAND_values, std::extent<decltype(BACKGROUNDHANDLERCOMMAND_values)>::value};
}
const maxon::EnumInfo& PrivateGetEnumInfo_BACKGROUNDHANDLERCOMMAND4812(){ return enum4812::BACKGROUNDHANDLERCOMMAND_info; }
namespace enum4838
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
	static const maxon::UInt64 BACKGROUNDHANDLERFLAGS_values[] = {maxon::UInt64(enum4838::BACKGROUNDHANDLERFLAGS::NONE), maxon::UInt64(enum4838::BACKGROUNDHANDLERFLAGS::VIEWREDRAW), maxon::UInt64(enum4838::BACKGROUNDHANDLERFLAGS::EDITORRENDDER), maxon::UInt64(enum4838::BACKGROUNDHANDLERFLAGS::MATERIALPREVIEW), maxon::UInt64(enum4838::BACKGROUNDHANDLERFLAGS::RENDEREXTERNAL), maxon::UInt64(enum4838::BACKGROUNDHANDLERFLAGS::PRIVATE_VIEWREDRAW), maxon::UInt64(enum4838::BACKGROUNDHANDLERFLAGS::SHUTDOWN)};
	static const maxon::EnumInfo BACKGROUNDHANDLERFLAGS_info{"BACKGROUNDHANDLERFLAGS", SIZEOF(BACKGROUNDHANDLERFLAGS), true, "NONE\0VIEWREDRAW\0EDITORRENDDER\0MATERIALPREVIEW\0RENDEREXTERNAL\0PRIVATE_VIEWREDRAW\0SHUTDOWN\0", BACKGROUNDHANDLERFLAGS_values, std::extent<decltype(BACKGROUNDHANDLERFLAGS_values)>::value};
}
const maxon::EnumInfo& PrivateGetEnumInfo_BACKGROUNDHANDLERFLAGS4838(){ return enum4838::BACKGROUNDHANDLERFLAGS_info; }
namespace enum4863
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
		PYTHON				= (1 << 8),			///< Python file.
	
		FASTDETECTION = (1 << 31),		///< maps to FILEFORMATDETECTIONFLAGS::FASTDETECTION
	} ;
	static const maxon::UInt64 IDENTIFYFILE_values[] = {maxon::UInt64(enum4863::IDENTIFYFILE::NONE), maxon::UInt64(enum4863::IDENTIFYFILE::SCENE), maxon::UInt64(enum4863::IDENTIFYFILE::IMAGE), maxon::UInt64(enum4863::IDENTIFYFILE::MOVIE), maxon::UInt64(enum4863::IDENTIFYFILE::SKIPQUICKTIME), maxon::UInt64(enum4863::IDENTIFYFILE::SCRIPT), maxon::UInt64(enum4863::IDENTIFYFILE::SOUND), maxon::UInt64(enum4863::IDENTIFYFILE::LAYOUT), maxon::UInt64(enum4863::IDENTIFYFILE::PYTHON), maxon::UInt64(enum4863::IDENTIFYFILE::FASTDETECTION)};
	static const maxon::EnumInfo IDENTIFYFILE_info{"IDENTIFYFILE", SIZEOF(IDENTIFYFILE), true, "NONE\0SCENE\0IMAGE\0MOVIE\0SKIPQUICKTIME\0SCRIPT\0SOUND\0LAYOUT\0PYTHON\0FASTDETECTION\0", IDENTIFYFILE_values, std::extent<decltype(IDENTIFYFILE_values)>::value};
}
const maxon::EnumInfo& PrivateGetEnumInfo_IDENTIFYFILE4863(){ return enum4863::IDENTIFYFILE_info; }
namespace enum4875
{
	enum class CALCHARDSHADOW
	{
		NONE							= 0,							///< None.
		TRANSPARENCY			= (1 << 0),				///< Transparencies/alphas for in-between objects will be evaluated.
		SPECIALGISHADOW		= (1 << 29),			///< @markPrivate
		SPECIALSELFSHADOW	= (1 << 30)				///< @markPrivate
	} ;
	static const maxon::UInt64 CALCHARDSHADOW_values[] = {maxon::UInt64(enum4875::CALCHARDSHADOW::NONE), maxon::UInt64(enum4875::CALCHARDSHADOW::TRANSPARENCY), maxon::UInt64(enum4875::CALCHARDSHADOW::SPECIALGISHADOW), maxon::UInt64(enum4875::CALCHARDSHADOW::SPECIALSELFSHADOW)};
	static const maxon::EnumInfo CALCHARDSHADOW_info{"CALCHARDSHADOW", SIZEOF(CALCHARDSHADOW), true, "NONE\0TRANSPARENCY\0SPECIALGISHADOW\0SPECIALSELFSHADOW\0", CALCHARDSHADOW_values, std::extent<decltype(CALCHARDSHADOW_values)>::value};
}
const maxon::EnumInfo& PrivateGetEnumInfo_CALCHARDSHADOW4875(){ return enum4875::CALCHARDSHADOW_info; }
namespace enum4893
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
	static const maxon::UInt64 ILLUMINATEFLAGS_values[] = {maxon::UInt64(enum4893::ILLUMINATEFLAGS::NONE), maxon::UInt64(enum4893::ILLUMINATEFLAGS::SHADOW), maxon::UInt64(enum4893::ILLUMINATEFLAGS::NOENVIRONMENT), maxon::UInt64(enum4893::ILLUMINATEFLAGS::DISABLESHADOWMAP_CORRECTION), maxon::UInt64(enum4893::ILLUMINATEFLAGS::DISABLESHADOWCASTERMP_CORRECTION), maxon::UInt64(enum4893::ILLUMINATEFLAGS::LIGHTDIRNORMALS), maxon::UInt64(enum4893::ILLUMINATEFLAGS::NODISTANCEFALLOFF), maxon::UInt64(enum4893::ILLUMINATEFLAGS::NOGRAIN), maxon::UInt64(enum4893::ILLUMINATEFLAGS::BACKLIGHT)};
	static const maxon::EnumInfo ILLUMINATEFLAGS_info{"ILLUMINATEFLAGS", SIZEOF(ILLUMINATEFLAGS), true, "NONE\0SHADOW\0NOENVIRONMENT\0DISABLESHADOWMAP_CORRECTION\0DISABLESHADOWCASTERMP_CORRECTION\0LIGHTDIRNORMALS\0NODISTANCEFALLOFF\0NOGRAIN\0BACKLIGHT\0", ILLUMINATEFLAGS_values, std::extent<decltype(ILLUMINATEFLAGS_values)>::value};
}
const maxon::EnumInfo& PrivateGetEnumInfo_ILLUMINATEFLAGS4893(){ return enum4893::ILLUMINATEFLAGS_info; }
namespace enum4921
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
	static const maxon::UInt64 RAYBIT_values[] = {maxon::UInt64(enum4921::RAYBIT::NONE), maxon::UInt64(enum4921::RAYBIT::REFLECTION), maxon::UInt64(enum4921::RAYBIT::TRANSPARENCY), maxon::UInt64(enum4921::RAYBIT::REFRACTION), maxon::UInt64(enum4921::RAYBIT::CUSTOM), maxon::UInt64(enum4921::RAYBIT::CURR_REFLECTION), maxon::UInt64(enum4921::RAYBIT::CURR_TRANSPARENCY), maxon::UInt64(enum4921::RAYBIT::CURR_REFRACTION), maxon::UInt64(enum4921::RAYBIT::CURR_CUSTOM), maxon::UInt64(enum4921::RAYBIT::VOLUMETRICLIGHT), maxon::UInt64(enum4921::RAYBIT::ALLOWVLMIX), maxon::UInt64(enum4921::RAYBIT::GI), maxon::UInt64(enum4921::RAYBIT::BLURRY), maxon::UInt64(enum4921::RAYBIT::SSS), maxon::UInt64(enum4921::RAYBIT::AO), maxon::UInt64(enum4921::RAYBIT::COMPOSITING)};
	static const maxon::EnumInfo RAYBIT_info{"RAYBIT", SIZEOF(RAYBIT), true, "NONE\0REFLECTION\0TRANSPARENCY\0REFRACTION\0CUSTOM\0CURR_REFLECTION\0CURR_TRANSPARENCY\0CURR_REFRACTION\0CURR_CUSTOM\0VOLUMETRICLIGHT\0ALLOWVLMIX\0GI\0BLURRY\0SSS\0AO\0COMPOSITING\0", RAYBIT_values, std::extent<decltype(RAYBIT_values)>::value};
}
const maxon::EnumInfo& PrivateGetEnumInfo_RAYBIT4921(){ return enum4921::RAYBIT_info; }
namespace enum4945
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
	static const maxon::UInt64 VOLUMEINFO_values[] = {maxon::UInt64(enum4945::VOLUMEINFO::NONE), maxon::UInt64(enum4945::VOLUMEINFO::REFLECTION), maxon::UInt64(enum4945::VOLUMEINFO::TRANSPARENCY), maxon::UInt64(enum4945::VOLUMEINFO::ALPHA), maxon::UInt64(enum4945::VOLUMEINFO::CHANGENORMAL), maxon::UInt64(enum4945::VOLUMEINFO::DISPLACEMENT), maxon::UInt64(enum4945::VOLUMEINFO::ENVREQUIRED), maxon::UInt64(enum4945::VOLUMEINFO::DUDVREQUIRED), maxon::UInt64(enum4945::VOLUMEINFO::MIPSAT), maxon::UInt64(enum4945::VOLUMEINFO::VOLUMETRIC), maxon::UInt64(enum4945::VOLUMEINFO::TRANSFORM), maxon::UInt64(enum4945::VOLUMEINFO::EVALUATEPROJECTION), maxon::UInt64(enum4945::VOLUMEINFO::PRIVATE_GLOW), maxon::UInt64(enum4945::VOLUMEINFO::INITCALCULATION), maxon::UInt64(enum4945::VOLUMEINFO::FINAL_ALPHA), maxon::UInt64(enum4945::VOLUMEINFO::ISNBMMATERIAL)};
	static const maxon::EnumInfo VOLUMEINFO_info{"VOLUMEINFO", SIZEOF(VOLUMEINFO), true, "NONE\0REFLECTION\0TRANSPARENCY\0ALPHA\0CHANGENORMAL\0DISPLACEMENT\0ENVREQUIRED\0DUDVREQUIRED\0MIPSAT\0VOLUMETRIC\0TRANSFORM\0EVALUATEPROJECTION\0PRIVATE_GLOW\0INITCALCULATION\0FINAL_ALPHA\0ISNBMMATERIAL\0", VOLUMEINFO_values, std::extent<decltype(VOLUMEINFO_values)>::value};
}
const maxon::EnumInfo& PrivateGetEnumInfo_VOLUMEINFO4945(){ return enum4945::VOLUMEINFO_info; }
namespace enum4970
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
	static const maxon::UInt64 VIDEOPOSTINFO_values[] = {maxon::UInt64(enum4970::VIDEOPOSTINFO::NONE), maxon::UInt64(enum4970::VIDEOPOSTINFO::STOREFRAGMENTS), maxon::UInt64(enum4970::VIDEOPOSTINFO::EXECUTELINE), maxon::UInt64(enum4970::VIDEOPOSTINFO::EXECUTEPIXEL), maxon::UInt64(enum4970::VIDEOPOSTINFO::REQUEST_MOTIONMATRIX), maxon::UInt64(enum4970::VIDEOPOSTINFO::REQUEST_MOTIONGEOMETRY), maxon::UInt64(enum4970::VIDEOPOSTINFO::CALCVOLUMETRIC), maxon::UInt64(enum4970::VIDEOPOSTINFO::CALCSHADOW), maxon::UInt64(enum4970::VIDEOPOSTINFO::CUSTOMLENS), maxon::UInt64(enum4970::VIDEOPOSTINFO::GLOBALILLUMINATION), maxon::UInt64(enum4970::VIDEOPOSTINFO::CAUSTICS), maxon::UInt64(enum4970::VIDEOPOSTINFO::CUSTOMLENS_EXTENDED), maxon::UInt64(enum4970::VIDEOPOSTINFO::NETFRAME), maxon::UInt64(enum4970::VIDEOPOSTINFO::NETRUNONSERVER), maxon::UInt64(enum4970::VIDEOPOSTINFO::NETCREATEBUFFER), maxon::UInt64(enum4970::VIDEOPOSTINFO::NETCREATEBUFFER_MULTI), maxon::UInt64(enum4970::VIDEOPOSTINFO::REQUEST_MOTIONFULL)};
	static const maxon::EnumInfo VIDEOPOSTINFO_info{"VIDEOPOSTINFO", SIZEOF(VIDEOPOSTINFO), true, "NONE\0STOREFRAGMENTS\0EXECUTELINE\0EXECUTEPIXEL\0REQUEST_MOTIONMATRIX\0REQUEST_MOTIONGEOMETRY\0CALCVOLUMETRIC\0CALCSHADOW\0CUSTOMLENS\0GLOBALILLUMINATION\0CAUSTICS\0CUSTOMLENS_EXTENDED\0NETFRAME\0NETRUNONSERVER\0NETCREATEBUFFER\0NETCREATEBUFFER_MULTI\0REQUEST_MOTIONFULL\0", VIDEOPOSTINFO_values, std::extent<decltype(VIDEOPOSTINFO_values)>::value};
}
const maxon::EnumInfo& PrivateGetEnumInfo_VIDEOPOSTINFO4970(){ return enum4970::VIDEOPOSTINFO_info; }
namespace enum4988
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
		TRANSPARENCIES		= 0x00000200,			///< Deprecated, not used anymore.
		TIMEDEPENDENT			= 0x00000400			///< Channel shader changes over time.
	} ;
	static const maxon::UInt64 SHADERINFO_values[] = {maxon::UInt64(enum4988::SHADERINFO::NONE), maxon::UInt64(enum4988::SHADERINFO::TRANSFORM), maxon::UInt64(enum4988::SHADERINFO::BUMP_SUPPORT), maxon::UInt64(enum4988::SHADERINFO::ALPHA_SUPPORT), maxon::UInt64(enum4988::SHADERINFO::REFLECTIONS), maxon::UInt64(enum4988::SHADERINFO::DUDVREQUIRED), maxon::UInt64(enum4988::SHADERINFO::DYNAMICSUBSHADERS), maxon::UInt64(enum4988::SHADERINFO::TRANSPARENCIES), maxon::UInt64(enum4988::SHADERINFO::TIMEDEPENDENT)};
	static const maxon::EnumInfo SHADERINFO_info{"SHADERINFO", SIZEOF(SHADERINFO), true, "NONE\0TRANSFORM\0BUMP_SUPPORT\0ALPHA_SUPPORT\0REFLECTIONS\0DUDVREQUIRED\0DYNAMICSUBSHADERS\0TRANSPARENCIES\0TIMEDEPENDENT\0", SHADERINFO_values, std::extent<decltype(SHADERINFO_values)>::value};
}
const maxon::EnumInfo& PrivateGetEnumInfo_SHADERINFO4988(){ return enum4988::SHADERINFO_info; }
namespace enum4999
{
	enum class SAMPLEBUMP
	{
		NONE				= 0,						///< None.
		MIPFALLOFF	= (1 << 0)			///< Additional bump change over distance is considered.
	} ;
	static const maxon::UInt64 SAMPLEBUMP_values[] = {maxon::UInt64(enum4999::SAMPLEBUMP::NONE), maxon::UInt64(enum4999::SAMPLEBUMP::MIPFALLOFF)};
	static const maxon::EnumInfo SAMPLEBUMP_info{"SAMPLEBUMP", SIZEOF(SAMPLEBUMP), true, "NONE\0MIPFALLOFF\0", SAMPLEBUMP_values, std::extent<decltype(SAMPLEBUMP_values)>::value};
}
const maxon::EnumInfo& PrivateGetEnumInfo_SAMPLEBUMP4999(){ return enum4999::SAMPLEBUMP_info; }
namespace enum5012
{
	enum class INITCALCULATION
	{
		SURFACE				= 0,			///< Called during rendering for surface calculation.
		TRANSPARENCY	= 1,			///< Called during rendering for shadow rays computation.
		DISPLACEMENT	= 3				///< Called before rendering for displace calculation.
	} ;
	static const maxon::UInt64 INITCALCULATION_values[] = {maxon::UInt64(enum5012::INITCALCULATION::SURFACE), maxon::UInt64(enum5012::INITCALCULATION::TRANSPARENCY), maxon::UInt64(enum5012::INITCALCULATION::DISPLACEMENT)};
	static const maxon::EnumInfo INITCALCULATION_info{"INITCALCULATION", SIZEOF(INITCALCULATION), false, "SURFACE\0TRANSPARENCY\0DISPLACEMENT\0", INITCALCULATION_values, std::extent<decltype(INITCALCULATION_values)>::value};
}
const maxon::EnumInfo& PrivateGetEnumInfo_INITCALCULATION5012(){ return enum5012::INITCALCULATION_info; }
namespace enum5032
{
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
	} ;
	static const maxon::UInt64 FIELDLAYER_FLAG_values[] = {maxon::UInt64(enum5032::FIELDLAYER_FLAG::NONE), maxon::UInt64(enum5032::FIELDLAYER_FLAG::SKIP), maxon::UInt64(enum5032::FIELDLAYER_FLAG::HIDE), maxon::UInt64(enum5032::FIELDLAYER_FLAG::MODIFYDATA), maxon::UInt64(enum5032::FIELDLAYER_FLAG::PRESERVEALPHA), maxon::UInt64(enum5032::FIELDLAYER_FLAG::NOCHILDVALUE), maxon::UInt64(enum5032::FIELDLAYER_FLAG::NOCHILDCOLOR), maxon::UInt64(enum5032::FIELDLAYER_FLAG::NOCHILDDIRECTION), maxon::UInt64(enum5032::FIELDLAYER_FLAG::TEMPORARY), maxon::UInt64(enum5032::FIELDLAYER_FLAG::NOCHILDROTATION)};
	static const maxon::EnumInfo FIELDLAYER_FLAG_info{"FIELDLAYER_FLAG", SIZEOF(FIELDLAYER_FLAG), true, "NONE\0SKIP\0HIDE\0MODIFYDATA\0PRESERVEALPHA\0NOCHILDVALUE\0NOCHILDCOLOR\0NOCHILDDIRECTION\0TEMPORARY\0NOCHILDROTATION\0", FIELDLAYER_FLAG_values, std::extent<decltype(FIELDLAYER_FLAG_values)>::value};
}
const maxon::EnumInfo& PrivateGetEnumInfo_FIELDLAYER_FLAG5032(){ return enum5032::FIELDLAYER_FLAG_info; }
namespace enum5143
{
	enum class MULTIPASSCHANNEL
	{
		NONE						= 0,						///< None.
		IMAGELAYER			= (1 << 0),			///< Image layer.
		MATERIALCHANNEL	= (1 << 1)			///< %Material channel.
	} ;
	static const maxon::UInt64 MULTIPASSCHANNEL_values[] = {maxon::UInt64(enum5143::MULTIPASSCHANNEL::NONE), maxon::UInt64(enum5143::MULTIPASSCHANNEL::IMAGELAYER), maxon::UInt64(enum5143::MULTIPASSCHANNEL::MATERIALCHANNEL)};
	static const maxon::EnumInfo MULTIPASSCHANNEL_info{"MULTIPASSCHANNEL", SIZEOF(MULTIPASSCHANNEL), false, "NONE\0IMAGELAYER\0MATERIALCHANNEL\0", MULTIPASSCHANNEL_values, std::extent<decltype(MULTIPASSCHANNEL_values)>::value};
}
const maxon::EnumInfo& PrivateGetEnumInfo_MULTIPASSCHANNEL5143(){ return enum5143::MULTIPASSCHANNEL_info; }
namespace enum5164
{
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
	} ;
	static const maxon::UInt64 DLG_TYPE_values[] = {maxon::UInt64(enum5164::DLG_TYPE::MODAL), maxon::UInt64(enum5164::DLG_TYPE::MODAL_RESIZEABLE), maxon::UInt64(enum5164::DLG_TYPE::MODAL_POPUPEDIT), maxon::UInt64(enum5164::DLG_TYPE::ASYNC), maxon::UInt64(enum5164::DLG_TYPE::ASYNC_POPUP_RESIZEABLE), maxon::UInt64(enum5164::DLG_TYPE::ASYNC_POPUPEDIT), maxon::UInt64(enum5164::DLG_TYPE::ASYNC_TOOLBAR), maxon::UInt64(enum5164::DLG_TYPE::ASYNC_FULLSCREEN_WORK), maxon::UInt64(enum5164::DLG_TYPE::ASYNC_FULLSCREEN_MONITOR), maxon::UInt64(enum5164::DLG_TYPE::DUMMY)};
	static const maxon::EnumInfo DLG_TYPE_info{"DLG_TYPE", SIZEOF(DLG_TYPE), false, "MODAL\0MODAL_RESIZEABLE\0MODAL_POPUPEDIT\0ASYNC\0ASYNC_POPUP_RESIZEABLE\0ASYNC_POPUPEDIT\0ASYNC_TOOLBAR\0ASYNC_FULLSCREEN_WORK\0ASYNC_FULLSCREEN_MONITOR\0DUMMY\0", DLG_TYPE_values, std::extent<decltype(DLG_TYPE_values)>::value};
}
const maxon::EnumInfo& PrivateGetEnumInfo_DLG_TYPE5164(){ return enum5164::DLG_TYPE_info; }
namespace enum5178
{
	enum class MULTIMSG_ROUTE
	{
		NONE = 0,									 ///< None.
		UP = 1,										 ///< Send to parents.
		ROOT = 2,									 ///< Send to root object.
		DOWN = 3,									 ///< Send to children.
		BROADCAST = 4,						 ///< Broadcast the message, i.e. distribute it to all branches given by GeListNode::GetBranchInfo.
		BROADCAST_ONLYOBJECTS = 5, ///< Broadcast the message only to children objects
	} ;
	static const maxon::UInt64 MULTIMSG_ROUTE_values[] = {maxon::UInt64(enum5178::MULTIMSG_ROUTE::NONE), maxon::UInt64(enum5178::MULTIMSG_ROUTE::UP), maxon::UInt64(enum5178::MULTIMSG_ROUTE::ROOT), maxon::UInt64(enum5178::MULTIMSG_ROUTE::DOWN), maxon::UInt64(enum5178::MULTIMSG_ROUTE::BROADCAST), maxon::UInt64(enum5178::MULTIMSG_ROUTE::BROADCAST_ONLYOBJECTS)};
	static const maxon::EnumInfo MULTIMSG_ROUTE_info{"MULTIMSG_ROUTE", SIZEOF(MULTIMSG_ROUTE), false, "NONE\0UP\0ROOT\0DOWN\0BROADCAST\0BROADCAST_ONLYOBJECTS\0", MULTIMSG_ROUTE_values, std::extent<decltype(MULTIMSG_ROUTE_values)>::value};
}
const maxon::EnumInfo& PrivateGetEnumInfo_MULTIMSG_ROUTE5178(){ return enum5178::MULTIMSG_ROUTE_info; }
namespace enum5189
{
	enum class VPGETFRAGMENTS
	{
		NONE	= 0,						///< None.
		Z_P		= (1 << 0),			///< Get VPFragment::z and VPFragment::p.
		N			= (1 << 1)			///< Get VPFragment::n.
	} ;
	static const maxon::UInt64 VPGETFRAGMENTS_values[] = {maxon::UInt64(enum5189::VPGETFRAGMENTS::NONE), maxon::UInt64(enum5189::VPGETFRAGMENTS::Z_P), maxon::UInt64(enum5189::VPGETFRAGMENTS::N)};
	static const maxon::EnumInfo VPGETFRAGMENTS_info{"VPGETFRAGMENTS", SIZEOF(VPGETFRAGMENTS), true, "NONE\0Z_P\0N\0", VPGETFRAGMENTS_values, std::extent<decltype(VPGETFRAGMENTS_values)>::value};
}
const maxon::EnumInfo& PrivateGetEnumInfo_VPGETFRAGMENTS5189(){ return enum5189::VPGETFRAGMENTS_info; }
namespace enum5217
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
	static const maxon::UInt64 NAV2DCAMERASETTINGSCACHEMODE_values[] = {maxon::UInt64(enum5217::NAV2DCAMERASETTINGSCACHEMODE::REVERT), maxon::UInt64(enum5217::NAV2DCAMERASETTINGSCACHEMODE::STOREIFIN2D), maxon::UInt64(enum5217::NAV2DCAMERASETTINGSCACHEMODE::STOREIFIN2DANDNOTALREADYSTORED), maxon::UInt64(enum5217::NAV2DCAMERASETTINGSCACHEMODE::FORCESTORE), maxon::UInt64(enum5217::NAV2DCAMERASETTINGSCACHEMODE::RET_CHANGED), maxon::UInt64(enum5217::NAV2DCAMERASETTINGSCACHEMODE::RET_NOCHANGE), maxon::UInt64(enum5217::NAV2DCAMERASETTINGSCACHEMODE::INVALID)};
	static const maxon::EnumInfo NAV2DCAMERASETTINGSCACHEMODE_info{"NAV2DCAMERASETTINGSCACHEMODE", SIZEOF(NAV2DCAMERASETTINGSCACHEMODE), false, "REVERT\0STOREIFIN2D\0STOREIFIN2DANDNOTALREADYSTORED\0FORCESTORE\0RET_CHANGED\0RET_NOCHANGE\0INVALID\0", NAV2DCAMERASETTINGSCACHEMODE_values, std::extent<decltype(NAV2DCAMERASETTINGSCACHEMODE_values)>::value};
}
const maxon::EnumInfo& PrivateGetEnumInfo_NAV2DCAMERASETTINGSCACHEMODE5217(){ return enum5217::NAV2DCAMERASETTINGSCACHEMODE_info; }
namespace enum5229
{
	enum class SIGNALMODE
	{
		// V_ unfortunately has to be used here due to conflicts with MAC OS
		V_DEFAULT		= 0,			///< Default mode.
		V_RESERVED	= 1				///< Reserved.
	} ;
	static const maxon::UInt64 SIGNALMODE_values[] = {maxon::UInt64(enum5229::SIGNALMODE::V_DEFAULT), maxon::UInt64(enum5229::SIGNALMODE::V_RESERVED)};
	static const maxon::EnumInfo SIGNALMODE_info{"SIGNALMODE", SIZEOF(SIGNALMODE), false, "V_DEFAULT\0V_RESERVED\0", SIGNALMODE_values, std::extent<decltype(SIGNALMODE_values)>::value};
}
const maxon::EnumInfo& PrivateGetEnumInfo_SIGNALMODE5229(){ return enum5229::SIGNALMODE_info; }
namespace enum5243
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
	static const maxon::UInt64 QUALIFIER_values[] = {maxon::UInt64(enum5243::QUALIFIER::NONE), maxon::UInt64(enum5243::QUALIFIER::SHIFT), maxon::UInt64(enum5243::QUALIFIER::CTRL), maxon::UInt64(enum5243::QUALIFIER::ALT), maxon::UInt64(enum5243::QUALIFIER::MOUSEHIT)};
	static const maxon::EnumInfo QUALIFIER_info{"QUALIFIER", SIZEOF(QUALIFIER), true, "NONE\0SHIFT\0CTRL\0ALT\0MOUSEHIT\0", QUALIFIER_values, std::extent<decltype(QUALIFIER_values)>::value};
}
const maxon::EnumInfo& PrivateGetEnumInfo_QUALIFIER5243(){ return enum5243::QUALIFIER_info; }
namespace enum5465
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
	static const maxon::UInt64 NOTIFY_EVENT_values[] = {maxon::UInt64(enum5465::NOTIFY_EVENT::NONE), maxon::UInt64(enum5465::NOTIFY_EVENT::ALL), maxon::UInt64(enum5465::NOTIFY_EVENT::ANY), maxon::UInt64(enum5465::NOTIFY_EVENT::PRE_DEFORM), maxon::UInt64(enum5465::NOTIFY_EVENT::POST_DEFORM), maxon::UInt64(enum5465::NOTIFY_EVENT::UNDO), maxon::UInt64(enum5465::NOTIFY_EVENT::MESSAGE), maxon::UInt64(enum5465::NOTIFY_EVENT::FREE), maxon::UInt64(enum5465::NOTIFY_EVENT::COPY), maxon::UInt64(enum5465::NOTIFY_EVENT::CACHE), maxon::UInt64(enum5465::NOTIFY_EVENT::REMOVE), maxon::UInt64(enum5465::NOTIFY_EVENT::CLONE), maxon::UInt64(enum5465::NOTIFY_EVENT::INSERT), maxon::UInt64(enum5465::NOTIFY_EVENT::SELECTIONBIT), maxon::UInt64(enum5465::NOTIFY_EVENT::HIGHLIGHTBIT), maxon::UInt64(enum5465::NOTIFY_EVENT::SETNAME)};
	static const maxon::EnumInfo NOTIFY_EVENT_info{"NOTIFY_EVENT", SIZEOF(NOTIFY_EVENT), false, "NONE\0ALL\0ANY\0PRE_DEFORM\0POST_DEFORM\0UNDO\0MESSAGE\0FREE\0COPY\0CACHE\0REMOVE\0CLONE\0INSERT\0SELECTIONBIT\0HIGHLIGHTBIT\0SETNAME\0", NOTIFY_EVENT_values, std::extent<decltype(NOTIFY_EVENT_values)>::value};
}
const maxon::EnumInfo& PrivateGetEnumInfo_NOTIFY_EVENT5465(){ return enum5465::NOTIFY_EVENT_info; }
namespace enum5483
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
	static const maxon::UInt64 NOTIFY_EVENT_FLAG_values[] = {maxon::UInt64(enum5483::NOTIFY_EVENT_FLAG::REMOVED), maxon::UInt64(enum5483::NOTIFY_EVENT_FLAG::COPY_UNDO), maxon::UInt64(enum5483::NOTIFY_EVENT_FLAG::COPY_CACHE), maxon::UInt64(enum5483::NOTIFY_EVENT_FLAG::COPY_DUPLICATE), maxon::UInt64(enum5483::NOTIFY_EVENT_FLAG::ONCE), maxon::UInt64(enum5483::NOTIFY_EVENT_FLAG::COPY), maxon::UInt64(enum5483::NOTIFY_EVENT_FLAG::NONE)};
	static const maxon::EnumInfo NOTIFY_EVENT_FLAG_info{"NOTIFY_EVENT_FLAG", SIZEOF(NOTIFY_EVENT_FLAG), true, "REMOVED\0COPY_UNDO\0COPY_CACHE\0COPY_DUPLICATE\0ONCE\0COPY\0NONE\0", NOTIFY_EVENT_FLAG_values, std::extent<decltype(NOTIFY_EVENT_FLAG_values)>::value};
}
const maxon::EnumInfo& PrivateGetEnumInfo_NOTIFY_EVENT_FLAG5483(){ return enum5483::NOTIFY_EVENT_FLAG_info; }
namespace enum5496
{
	enum class DESCIDSTATE
	{
		NONE						= 0,					///< None.
		LOCKED					= 1 << 0,			///< Description element is locked.
		HIDDEN					= 1 << 1,			///< Description element is hidden.
		OVERRIDE				= 1 << 2,			///< Description is overridden. @since R17.032
		FORBIDOVERRIDE	= 1 << 3			///< Description cannot be overridden. @since R17.032
	} ;
	static const maxon::UInt64 DESCIDSTATE_values[] = {maxon::UInt64(enum5496::DESCIDSTATE::NONE), maxon::UInt64(enum5496::DESCIDSTATE::LOCKED), maxon::UInt64(enum5496::DESCIDSTATE::HIDDEN), maxon::UInt64(enum5496::DESCIDSTATE::OVERRIDE), maxon::UInt64(enum5496::DESCIDSTATE::FORBIDOVERRIDE)};
	static const maxon::EnumInfo DESCIDSTATE_info{"DESCIDSTATE", SIZEOF(DESCIDSTATE), true, "NONE\0LOCKED\0HIDDEN\0OVERRIDE\0FORBIDOVERRIDE\0", DESCIDSTATE_values, std::extent<decltype(DESCIDSTATE_values)>::value};
}
const maxon::EnumInfo& PrivateGetEnumInfo_DESCIDSTATE5496(){ return enum5496::DESCIDSTATE_info; }
namespace enum5507
{
	enum class BASEDRAW_HOOK_MESSAGE
	{
		ADAPTVIEW					= 1,			///< The user clicked on "Adapt View" menu.
		SET_SCENE_CAMERA	= 2,			///< The user changed the scene camera. The corresponding data is BDSetSceneCameraMsg.
		DELETEBASEDRAW		= 3				///< The base draw is deleted.
	} ;
	static const maxon::UInt64 BASEDRAW_HOOK_MESSAGE_values[] = {maxon::UInt64(enum5507::BASEDRAW_HOOK_MESSAGE::ADAPTVIEW), maxon::UInt64(enum5507::BASEDRAW_HOOK_MESSAGE::SET_SCENE_CAMERA), maxon::UInt64(enum5507::BASEDRAW_HOOK_MESSAGE::DELETEBASEDRAW)};
	static const maxon::EnumInfo BASEDRAW_HOOK_MESSAGE_info{"BASEDRAW_HOOK_MESSAGE", SIZEOF(BASEDRAW_HOOK_MESSAGE), false, "ADAPTVIEW\0SET_SCENE_CAMERA\0DELETEBASEDRAW\0", BASEDRAW_HOOK_MESSAGE_values, std::extent<decltype(BASEDRAW_HOOK_MESSAGE_values)>::value};
}
const maxon::EnumInfo& PrivateGetEnumInfo_BASEDRAW_HOOK_MESSAGE5507(){ return enum5507::BASEDRAW_HOOK_MESSAGE_info; }
namespace enum5524
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
	static const maxon::UInt64 CINEMAINFO_values[] = {maxon::UInt64(enum5524::CINEMAINFO::TABLETT), maxon::UInt64(enum5524::CINEMAINFO::OPENGL), maxon::UInt64(enum5524::CINEMAINFO::TABLETT_HIRES), maxon::UInt64(enum5524::CINEMAINFO::FORBID_GUI), maxon::UInt64(enum5524::CINEMAINFO::MINIMAL_VIEWPORT), maxon::UInt64(enum5524::CINEMAINFO::LISTEN), maxon::UInt64(enum5524::CINEMAINFO::WATCH_PID), maxon::UInt64(enum5524::CINEMAINFO::SETFOREGROUND), maxon::UInt64(enum5524::CINEMAINFO::FORCEDIALOG)};
	static const maxon::EnumInfo CINEMAINFO_info{"CINEMAINFO", SIZEOF(CINEMAINFO), true, "TABLETT\0OPENGL\0TABLETT_HIRES\0FORBID_GUI\0MINIMAL_VIEWPORT\0LISTEN\0WATCH_PID\0SETFOREGROUND\0FORCEDIALOG\0", CINEMAINFO_values, std::extent<decltype(CINEMAINFO_values)>::value};
}
const maxon::EnumInfo& PrivateGetEnumInfo_CINEMAINFO5524(){ return enum5524::CINEMAINFO_info; }
namespace enum5535
{
	enum class PROTOCOL
	{
		ZERO	= 0,				///< None.
		IPV4	= 1000,			///< IPv4.
		IPV6							///< IPv6.
	} ;
	static const maxon::UInt64 PROTOCOL_values[] = {maxon::UInt64(enum5535::PROTOCOL::ZERO), maxon::UInt64(enum5535::PROTOCOL::IPV4), maxon::UInt64(enum5535::PROTOCOL::IPV6)};
	static const maxon::EnumInfo PROTOCOL_info{"PROTOCOL", SIZEOF(PROTOCOL), false, "ZERO\0IPV4\0IPV6\0", PROTOCOL_values, std::extent<decltype(PROTOCOL_values)>::value};
}
const maxon::EnumInfo& PrivateGetEnumInfo_PROTOCOL5535(){ return enum5535::PROTOCOL_info; }
namespace enum5546
{
	enum class RESOLVERESULT
	{
		OK				= 0,			///< Ok.
		UNKNOWN		= 1,			///< Unknown error while resolving address.
	} ;
	static const maxon::UInt64 RESOLVERESULT_values[] = {maxon::UInt64(enum5546::RESOLVERESULT::OK), maxon::UInt64(enum5546::RESOLVERESULT::UNKNOWN)};
	static const maxon::EnumInfo RESOLVERESULT_info{"RESOLVERESULT", SIZEOF(RESOLVERESULT), false, "OK\0UNKNOWN\0", RESOLVERESULT_values, std::extent<decltype(RESOLVERESULT_values)>::value};
}
const maxon::EnumInfo& PrivateGetEnumInfo_RESOLVERESULT5546(){ return enum5546::RESOLVERESULT_info; }
namespace enum5558
{
	enum class SERVERJOBLIST
	{
		INACTIVE = 1000,			///<
		ACTIVE,								///<
		DOWNLOAD,							///<
		ALL										///<
	} ;
	static const maxon::UInt64 SERVERJOBLIST_values[] = {maxon::UInt64(enum5558::SERVERJOBLIST::INACTIVE), maxon::UInt64(enum5558::SERVERJOBLIST::ACTIVE), maxon::UInt64(enum5558::SERVERJOBLIST::DOWNLOAD), maxon::UInt64(enum5558::SERVERJOBLIST::ALL)};
	static const maxon::EnumInfo SERVERJOBLIST_info{"SERVERJOBLIST", SIZEOF(SERVERJOBLIST), false, "INACTIVE\0ACTIVE\0DOWNLOAD\0ALL\0", SERVERJOBLIST_values, std::extent<decltype(SERVERJOBLIST_values)>::value};
}
const maxon::EnumInfo& PrivateGetEnumInfo_SERVERJOBLIST5558(){ return enum5558::SERVERJOBLIST_info; }
namespace enum5570
{
	enum class EDITION
	{
		C4D				= (1 << 0),									///< @C4D
		NETCLIENT	= (1 << 1),									///< NET client.
		NETSERVER	= (1 << 2),									///< NET server.
		NET				= (1 << 1) | (1 << 2),			///< NET.
	} ;
	static const maxon::UInt64 EDITION_values[] = {maxon::UInt64(enum5570::EDITION::C4D), maxon::UInt64(enum5570::EDITION::NETCLIENT), maxon::UInt64(enum5570::EDITION::NETSERVER), maxon::UInt64(enum5570::EDITION::NET)};
	static const maxon::EnumInfo EDITION_info{"EDITION", SIZEOF(EDITION), true, "C4D\0NETCLIENT\0NETSERVER\0NET\0", EDITION_values, std::extent<decltype(EDITION_values)>::value};
}
const maxon::EnumInfo& PrivateGetEnumInfo_EDITION5570(){ return enum5570::EDITION_info; }
namespace enum5587
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
	static const maxon::UInt64 JOBCOMMAND_values[] = {maxon::UInt64(enum5587::JOBCOMMAND::NONE), maxon::UInt64(enum5587::JOBCOMMAND::FETCHJOB), maxon::UInt64(enum5587::JOBCOMMAND::ALLOCATESPACE), maxon::UInt64(enum5587::JOBCOMMAND::DOWNLOAD), maxon::UInt64(enum5587::JOBCOMMAND::RENDER), maxon::UInt64(enum5587::JOBCOMMAND::DELETE_), maxon::UInt64(enum5587::JOBCOMMAND::STOPANDDELETE), maxon::UInt64(enum5587::JOBCOMMAND::ASSEMBLE), maxon::UInt64(enum5587::JOBCOMMAND::END)};
	static const maxon::EnumInfo JOBCOMMAND_info{"JOBCOMMAND", SIZEOF(JOBCOMMAND), false, "NONE\0FETCHJOB\0ALLOCATESPACE\0DOWNLOAD\0RENDER\0DELETE_\0STOPANDDELETE\0ASSEMBLE\0END\0", JOBCOMMAND_values, std::extent<decltype(JOBCOMMAND_values)>::value};
}
const maxon::EnumInfo& PrivateGetEnumInfo_JOBCOMMAND5587(){ return enum5587::JOBCOMMAND_info; }
namespace enum5598
{
	enum class RENDERTARGET
	{
		ALL = 1000,	///< Use all machines.
		SPECIFIED,		///< C4DUuid.
		MINMAX				///< Minimum/maximum. <i>1000</i>:min <i>1001</i>:max
	} ;
	static const maxon::UInt64 RENDERTARGET_values[] = {maxon::UInt64(enum5598::RENDERTARGET::ALL), maxon::UInt64(enum5598::RENDERTARGET::SPECIFIED), maxon::UInt64(enum5598::RENDERTARGET::MINMAX)};
	static const maxon::EnumInfo RENDERTARGET_info{"RENDERTARGET", SIZEOF(RENDERTARGET), false, "ALL\0SPECIFIED\0MINMAX\0", RENDERTARGET_values, std::extent<decltype(RENDERTARGET_values)>::value};
}
const maxon::EnumInfo& PrivateGetEnumInfo_RENDERTARGET5598(){ return enum5598::RENDERTARGET_info; }
namespace enum5634
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
	static const maxon::UInt64 JOBSTATE_values[] = {maxon::UInt64(enum5634::JOBSTATE::IDLE), maxon::UInt64(enum5634::JOBSTATE::PREPARING_RUNNING), maxon::UInt64(enum5634::JOBSTATE::PREPARING_FAILED), maxon::UInt64(enum5634::JOBSTATE::PREPARING_OK), maxon::UInt64(enum5634::JOBSTATE::RENDER_RUNNING), maxon::UInt64(enum5634::JOBSTATE::TE_RENDER_PAUSED), maxon::UInt64(enum5634::JOBSTATE::RENDER_OK), maxon::UInt64(enum5634::JOBSTATE::RENDER_FAILED), maxon::UInt64(enum5634::JOBSTATE::ALLOCATESPACE_RUNNING), maxon::UInt64(enum5634::JOBSTATE::ALLOCATESPACE_OK), maxon::UInt64(enum5634::JOBSTATE::ALLOCATESPACE_FAILED), maxon::UInt64(enum5634::JOBSTATE::DOWNLOAD_RUNNING), maxon::UInt64(enum5634::JOBSTATE::DOWNLOAD_OK), maxon::UInt64(enum5634::JOBSTATE::DOWNLOAD_FAILED), maxon::UInt64(enum5634::JOBSTATE::ASSEMBLE_RUNNING), maxon::UInt64(enum5634::JOBSTATE::ASSEMBLE_OK), maxon::UInt64(enum5634::JOBSTATE::ASSEMBLE_FAILED), maxon::UInt64(enum5634::JOBSTATE::STOPPED), maxon::UInt64(enum5634::JOBSTATE::QUEUED), maxon::UInt64(enum5634::JOBSTATE::PENDING), maxon::UInt64(enum5634::JOBSTATE::QUEUED_WAITING), maxon::UInt64(enum5634::JOBSTATE::ASSEMBLE_PENDING)};
	static const maxon::EnumInfo JOBSTATE_info{"JOBSTATE", SIZEOF(JOBSTATE), false, "IDLE\0PREPARING_RUNNING\0PREPARING_FAILED\0PREPARING_OK\0RENDER_RUNNING\0TE_RENDER_PAUSED\0RENDER_OK\0RENDER_FAILED\0ALLOCATESPACE_RUNNING\0ALLOCATESPACE_OK\0ALLOCATESPACE_FAILED\0DOWNLOAD_RUNNING\0DOWNLOAD_OK\0DOWNLOAD_FAILED\0ASSEMBLE_RUNNING\0ASSEMBLE_OK\0ASSEMBLE_FAILED\0STOPPED\0QUEUED\0PENDING\0QUEUED_WAITING\0ASSEMBLE_PENDING\0", JOBSTATE_values, std::extent<decltype(JOBSTATE_values)>::value};
}
const maxon::EnumInfo& PrivateGetEnumInfo_JOBSTATE5634(){ return enum5634::JOBSTATE_info; }
namespace enum5646
{
	enum class ZEROCONFMACHINESTATE
	{
		ONLINE		= 1,			///< Online.
		OFFLINE	= 2,			///< Offline.
		REMOVED	= 3,			///< Removed.
		UPDATE		= 4,			///< Update.
	} ;
	static const maxon::UInt64 ZEROCONFMACHINESTATE_values[] = {maxon::UInt64(enum5646::ZEROCONFMACHINESTATE::ONLINE), maxon::UInt64(enum5646::ZEROCONFMACHINESTATE::OFFLINE), maxon::UInt64(enum5646::ZEROCONFMACHINESTATE::REMOVED), maxon::UInt64(enum5646::ZEROCONFMACHINESTATE::UPDATE)};
	static const maxon::EnumInfo ZEROCONFMACHINESTATE_info{"ZEROCONFMACHINESTATE", SIZEOF(ZEROCONFMACHINESTATE), false, "ONLINE\0OFFLINE\0REMOVED\0UPDATE\0", ZEROCONFMACHINESTATE_values, std::extent<decltype(ZEROCONFMACHINESTATE_values)>::value};
}
const maxon::EnumInfo& PrivateGetEnumInfo_ZEROCONFMACHINESTATE5646(){ return enum5646::ZEROCONFMACHINESTATE_info; }
namespace enum5657
{
	enum class ZEROCONFACTION
	{
		NONE		= 0,						///< None.
		RESOLVE	= (1 << 0),			///< Resolve.
		MONITOR	= (1 << 1)			///< Monitor.
	} ;
	static const maxon::UInt64 ZEROCONFACTION_values[] = {maxon::UInt64(enum5657::ZEROCONFACTION::NONE), maxon::UInt64(enum5657::ZEROCONFACTION::RESOLVE), maxon::UInt64(enum5657::ZEROCONFACTION::MONITOR)};
	static const maxon::EnumInfo ZEROCONFACTION_info{"ZEROCONFACTION", SIZEOF(ZEROCONFACTION), true, "NONE\0RESOLVE\0MONITOR\0", ZEROCONFACTION_values, std::extent<decltype(ZEROCONFACTION_values)>::value};
}
const maxon::EnumInfo& PrivateGetEnumInfo_ZEROCONFACTION5657(){ return enum5657::ZEROCONFACTION_info; }
namespace enum5696
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
	static const maxon::UInt64 ZEROCONFERROR_values[] = {maxon::UInt64(enum5696::ZEROCONFERROR::OK), maxon::UInt64(enum5696::ZEROCONFERROR::UNKNOWN), maxon::UInt64(enum5696::ZEROCONFERROR::NOSUCHNAME), maxon::UInt64(enum5696::ZEROCONFERROR::NOMEMORY), maxon::UInt64(enum5696::ZEROCONFERROR::BADPARAM), maxon::UInt64(enum5696::ZEROCONFERROR::BADREFERENCE), maxon::UInt64(enum5696::ZEROCONFERROR::BADSTATE), maxon::UInt64(enum5696::ZEROCONFERROR::BADFLAGS), maxon::UInt64(enum5696::ZEROCONFERROR::UNSUPPORTED), maxon::UInt64(enum5696::ZEROCONFERROR::NOTINITIALIZED), maxon::UInt64(enum5696::ZEROCONFERROR::ALREADYREGISTERED), maxon::UInt64(enum5696::ZEROCONFERROR::NAMECONFLICT), maxon::UInt64(enum5696::ZEROCONFERROR::INVALID), maxon::UInt64(enum5696::ZEROCONFERROR::FIREWALL), maxon::UInt64(enum5696::ZEROCONFERROR::INCOMPATIBLE), maxon::UInt64(enum5696::ZEROCONFERROR::BADINTERFACEINDEX), maxon::UInt64(enum5696::ZEROCONFERROR::REFUSED), maxon::UInt64(enum5696::ZEROCONFERROR::NOSUCHRECORD), maxon::UInt64(enum5696::ZEROCONFERROR::NOAUTH), maxon::UInt64(enum5696::ZEROCONFERROR::NOSUCHKEY), maxon::UInt64(enum5696::ZEROCONFERROR::NATTRAVERSAL), maxon::UInt64(enum5696::ZEROCONFERROR::DOUBLENAT), maxon::UInt64(enum5696::ZEROCONFERROR::BADTIME), maxon::UInt64(enum5696::ZEROCONFERROR::BADSIGNAL), maxon::UInt64(enum5696::ZEROCONFERROR::BADKEY), maxon::UInt64(enum5696::ZEROCONFERROR::TRANSIENT), maxon::UInt64(enum5696::ZEROCONFERROR::SERVICENOTRUNNING), maxon::UInt64(enum5696::ZEROCONFERROR::NATPORTMAPPINGUNSUPPORTED), maxon::UInt64(enum5696::ZEROCONFERROR::NATPORTMAPPINGDISABLED), maxon::UInt64(enum5696::ZEROCONFERROR::NOROUTER), maxon::UInt64(enum5696::ZEROCONFERROR::POLLINGMODE)};
	static const maxon::EnumInfo ZEROCONFERROR_info{"ZEROCONFERROR", SIZEOF(ZEROCONFERROR), false, "OK\0UNKNOWN\0NOSUCHNAME\0NOMEMORY\0BADPARAM\0BADREFERENCE\0BADSTATE\0BADFLAGS\0UNSUPPORTED\0NOTINITIALIZED\0ALREADYREGISTERED\0NAMECONFLICT\0INVALID\0FIREWALL\0INCOMPATIBLE\0BADINTERFACEINDEX\0REFUSED\0NOSUCHRECORD\0NOAUTH\0NOSUCHKEY\0NATTRAVERSAL\0DOUBLENAT\0BADTIME\0BADSIGNAL\0BADKEY\0TRANSIENT\0SERVICENOTRUNNING\0NATPORTMAPPINGUNSUPPORTED\0NATPORTMAPPINGDISABLED\0NOROUTER\0POLLINGMODE\0", ZEROCONFERROR_values, std::extent<decltype(ZEROCONFERROR_values)>::value};
}
const maxon::EnumInfo& PrivateGetEnumInfo_ZEROCONFERROR5696(){ return enum5696::ZEROCONFERROR_info; }
namespace enum5726
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
	static const maxon::UInt64 COMPONENT_SELECTION_MODES_values[] = {maxon::UInt64(enum5726::COMPONENT_SELECTION_MODES::POINTS), maxon::UInt64(enum5726::COMPONENT_SELECTION_MODES::EDGES), maxon::UInt64(enum5726::COMPONENT_SELECTION_MODES::POLYGONS), maxon::UInt64(enum5726::COMPONENT_SELECTION_MODES::UVPOINTS), maxon::UInt64(enum5726::COMPONENT_SELECTION_MODES::UVPOLYGONS), maxon::UInt64(enum5726::COMPONENT_SELECTION_MODES::CURRENT), maxon::UInt64(enum5726::COMPONENT_SELECTION_MODES::UVEDGES)};
	static const maxon::EnumInfo COMPONENT_SELECTION_MODES_info{"COMPONENT_SELECTION_MODES", SIZEOF(COMPONENT_SELECTION_MODES), false, "POINTS\0EDGES\0POLYGONS\0UVPOINTS\0UVPOLYGONS\0CURRENT\0UVEDGES\0", COMPONENT_SELECTION_MODES_values, std::extent<decltype(COMPONENT_SELECTION_MODES_values)>::value};
}
const maxon::EnumInfo& PrivateGetEnumInfo_COMPONENT_SELECTION_MODES5726(){ return enum5726::COMPONENT_SELECTION_MODES_info; }
namespace enum5740
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
	static const maxon::UInt64 FIELDSAMPLE_FLAG_values[] = {maxon::UInt64(enum5740::FIELDSAMPLE_FLAG::VALUE), maxon::UInt64(enum5740::FIELDSAMPLE_FLAG::DIRECTION), maxon::UInt64(enum5740::FIELDSAMPLE_FLAG::COLOR), maxon::UInt64(enum5740::FIELDSAMPLE_FLAG::ROTATION), maxon::UInt64(enum5740::FIELDSAMPLE_FLAG::ALL), maxon::UInt64(enum5740::FIELDSAMPLE_FLAG::NONLINEARCOLOR)};
	static const maxon::EnumInfo FIELDSAMPLE_FLAG_info{"FIELDSAMPLE_FLAG", SIZEOF(FIELDSAMPLE_FLAG), true, "VALUE\0DIRECTION\0COLOR\0ROTATION\0ALL\0NONLINEARCOLOR\0", FIELDSAMPLE_FLAG_values, std::extent<decltype(FIELDSAMPLE_FLAG_values)>::value};
}
const maxon::EnumInfo& PrivateGetEnumInfo_FIELDSAMPLE_FLAG5740(){ return enum5740::FIELDSAMPLE_FLAG_info; }
namespace enum5750
{
	enum class FIELDOBJECTSAMPLE_FLAG
	{
		NONE										= 0,						///< No flags
		DISABLEDIRECTIONFALLOFF = (1 << 0)			///< @Markprivate Disables remapping the direction magnitude by the value parameter in order that fieldlayers may use that to blend instead in normal mode
	} ;
	static const maxon::UInt64 FIELDOBJECTSAMPLE_FLAG_values[] = {maxon::UInt64(enum5750::FIELDOBJECTSAMPLE_FLAG::NONE), maxon::UInt64(enum5750::FIELDOBJECTSAMPLE_FLAG::DISABLEDIRECTIONFALLOFF)};
	static const maxon::EnumInfo FIELDOBJECTSAMPLE_FLAG_info{"FIELDOBJECTSAMPLE_FLAG", SIZEOF(FIELDOBJECTSAMPLE_FLAG), true, "NONE\0DISABLEDIRECTIONFALLOFF\0", FIELDOBJECTSAMPLE_FLAG_values, std::extent<decltype(FIELDOBJECTSAMPLE_FLAG_values)>::value};
}
const maxon::EnumInfo& PrivateGetEnumInfo_FIELDOBJECTSAMPLE_FLAG5750(){ return enum5750::FIELDOBJECTSAMPLE_FLAG_info; }
namespace enum5763
{
	enum class FIELDOBJECT_FLAG
	{
		NONE											= 0,								///< No flags
		INLINE										= (1 << 0),					///< Field calculates using the current values of the field stack.
		GENERATINGCOLOR						= (1 << 1),					///< The Field is currently outputting color.
		PRESERVEALPHA							= (1 << 2),					///< The Field doesn't modify alpha, any color it produces is directly applied to the existing color ignoring the alpha blending.
		SKIP											= (1 << 3)					///< The Field should be skipped.
	} ;
	static const maxon::UInt64 FIELDOBJECT_FLAG_values[] = {maxon::UInt64(enum5763::FIELDOBJECT_FLAG::NONE), maxon::UInt64(enum5763::FIELDOBJECT_FLAG::INLINE), maxon::UInt64(enum5763::FIELDOBJECT_FLAG::GENERATINGCOLOR), maxon::UInt64(enum5763::FIELDOBJECT_FLAG::PRESERVEALPHA), maxon::UInt64(enum5763::FIELDOBJECT_FLAG::SKIP)};
	static const maxon::EnumInfo FIELDOBJECT_FLAG_info{"FIELDOBJECT_FLAG", SIZEOF(FIELDOBJECT_FLAG), true, "NONE\0INLINE\0GENERATINGCOLOR\0PRESERVEALPHA\0SKIP\0", FIELDOBJECT_FLAG_values, std::extent<decltype(FIELDOBJECT_FLAG_values)>::value};
}
const maxon::EnumInfo& PrivateGetEnumInfo_FIELDOBJECT_FLAG5763(){ return enum5763::FIELDOBJECT_FLAG_info; }
namespace enum5775
{
	enum class VIEWPORT_RENDER_ID
	{
		RENDER_OBJECT = 0,	///< Return the Id of the render object.
		DATA_SETTER = 1			///< Return the Id of the data setter.
	} ;
	static const maxon::UInt64 VIEWPORT_RENDER_ID_values[] = {maxon::UInt64(enum5775::VIEWPORT_RENDER_ID::RENDER_OBJECT), maxon::UInt64(enum5775::VIEWPORT_RENDER_ID::DATA_SETTER)};
	static const maxon::EnumInfo VIEWPORT_RENDER_ID_info{"VIEWPORT_RENDER_ID", SIZEOF(VIEWPORT_RENDER_ID), false, "RENDER_OBJECT\0DATA_SETTER\0", VIEWPORT_RENDER_ID_values, std::extent<decltype(VIEWPORT_RENDER_ID_values)>::value};
}
const maxon::EnumInfo& PrivateGetEnumInfo_VIEWPORT_RENDER_ID5775(){ return enum5775::VIEWPORT_RENDER_ID_info; }
namespace enum5793
{
	enum class GETALLASSETSRESULT
	{
		FAILED		= 0,		///< Function call went wrong.
		OK				= 1,		///< Function succeeded and all assets exists.
		MISSING		= 2			///< Function succeeded but some assets cannot be found.
	} ;
	static const maxon::UInt64 GETALLASSETSRESULT_values[] = {maxon::UInt64(enum5793::GETALLASSETSRESULT::FAILED), maxon::UInt64(enum5793::GETALLASSETSRESULT::OK), maxon::UInt64(enum5793::GETALLASSETSRESULT::MISSING)};
	static const maxon::EnumInfo GETALLASSETSRESULT_info{"GETALLASSETSRESULT", SIZEOF(GETALLASSETSRESULT), false, "FAILED\0OK\0MISSING\0", GETALLASSETSRESULT_values, std::extent<decltype(GETALLASSETSRESULT_values)>::value};
}
const maxon::EnumInfo& PrivateGetEnumInfo_GETALLASSETSRESULT5793(){ return enum5793::GETALLASSETSRESULT_info; }
namespace enum5805
{
	enum class VIEWPORTTYPE
	{
		NONE			= 0,		///< No viewport is active.
		MAIN_VIEW = 1,		///< Main 3D viewport is active.
		UV_VIEW		= 2			///< UV viewport is active.
	} ;
	static const maxon::UInt64 VIEWPORTTYPE_values[] = {maxon::UInt64(enum5805::VIEWPORTTYPE::NONE), maxon::UInt64(enum5805::VIEWPORTTYPE::MAIN_VIEW), maxon::UInt64(enum5805::VIEWPORTTYPE::UV_VIEW)};
	static const maxon::EnumInfo VIEWPORTTYPE_info{"VIEWPORTTYPE", SIZEOF(VIEWPORTTYPE), false, "NONE\0MAIN_VIEW\0UV_VIEW\0", VIEWPORTTYPE_values, std::extent<decltype(VIEWPORTTYPE_values)>::value};
}
const maxon::EnumInfo& PrivateGetEnumInfo_VIEWPORTTYPE5805(){ return enum5805::VIEWPORTTYPE_info; }
namespace enum5818
{
	enum class SCENENODES_IDS
	{
	    SCENEHOOK_ID                = 1054188,        ///< SceneHook ID
	    MSGUPDATE_LEGACYOBJ_ID      = 180420109,      ///< Legacy Objects Update Message ID.
	    PERSISTENT_HASH_LOW_ID      = 180420112       ///< Persistent Hash ID.
	} ;
	static const maxon::UInt64 SCENENODES_IDS_values[] = {maxon::UInt64(enum5818::SCENENODES_IDS::SCENEHOOK_ID), maxon::UInt64(enum5818::SCENENODES_IDS::MSGUPDATE_LEGACYOBJ_ID), maxon::UInt64(enum5818::SCENENODES_IDS::PERSISTENT_HASH_LOW_ID)};
	static const maxon::EnumInfo SCENENODES_IDS_info{"SCENENODES_IDS", SIZEOF(SCENENODES_IDS), false, "SCENEHOOK_ID\0MSGUPDATE_LEGACYOBJ_ID\0PERSISTENT_HASH_LOW_ID\0", SCENENODES_IDS_values, std::extent<decltype(SCENENODES_IDS_values)>::value};
}
const maxon::EnumInfo& PrivateGetEnumInfo_SCENENODES_IDS5818(){ return enum5818::SCENENODES_IDS_info; }
namespace enum5827
{
	enum class FOLDMODE
	{
		NONE,
		HIDEMYSELF,
		EXPAND1STEP,
		EXPANDCOMPLETELY,
	} ;
	static const maxon::UInt64 FOLDMODE_values[] = {maxon::UInt64(enum5827::FOLDMODE::NONE), maxon::UInt64(enum5827::FOLDMODE::HIDEMYSELF), maxon::UInt64(enum5827::FOLDMODE::EXPAND1STEP), maxon::UInt64(enum5827::FOLDMODE::EXPANDCOMPLETELY)};
	static const maxon::EnumInfo FOLDMODE_info{"FOLDMODE", SIZEOF(FOLDMODE), false, "NONE\0HIDEMYSELF\0EXPAND1STEP\0EXPANDCOMPLETELY\0", FOLDMODE_values, std::extent<decltype(FOLDMODE_values)>::value};
}
const maxon::EnumInfo& PrivateGetEnumInfo_FOLDMODE5827(){ return enum5827::FOLDMODE_info; }
namespace enum5836
{
	enum class TAGBITS
	{
		NONE = 0,
		TDISPLAY = 1 << 0,
		TCOMPOSITING = 1 << 1,
		TTEXTURE = 1 << 2,
	} ;
	static const maxon::UInt64 TAGBITS_values[] = {maxon::UInt64(enum5836::TAGBITS::NONE), maxon::UInt64(enum5836::TAGBITS::TDISPLAY), maxon::UInt64(enum5836::TAGBITS::TCOMPOSITING), maxon::UInt64(enum5836::TAGBITS::TTEXTURE)};
	static const maxon::EnumInfo TAGBITS_info{"TAGBITS", SIZEOF(TAGBITS), true, "NONE\0TDISPLAY\0TCOMPOSITING\0TTEXTURE\0", TAGBITS_values, std::extent<decltype(TAGBITS_values)>::value};
}
const maxon::EnumInfo& PrivateGetEnumInfo_TAGBITS5836(){ return enum5836::TAGBITS_info; }
#ifdef CINEWARE_NAMESPACE_ENABLE
CINEWARE_NAMESPACE_END
#endif
#endif
