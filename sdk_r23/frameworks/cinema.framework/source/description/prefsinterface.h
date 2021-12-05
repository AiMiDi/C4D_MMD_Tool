#ifndef PREFSINTERFACE_H__
#define PREFSINTERFACE_H__

enum
{
	PREF_INTERFACE_MAIN_GROUP															= 999,
	PREF_INTERFACE_LANGUAGE																= 1000,
	PREF_INTERFACE_SCHEME																	= 1001,
	PREF_INTERFACE_NEWFEATUREHIGHLIGHT										= 1002,
	PREF_INTERFACE_BUBBLE																	= 1003,
	PREF_INTERFACE_MENUICONS															= 1004,
	PREF_INTERFACE_MENUSCUT																= 1005,
	PREF_INTERFACE_NEWFEATUREHIGHLIGHT_RESET							= 1006,
	PREF_INTERFACE_NEWFEATUREHIGHLIGHT_RESET_WARNING			= 1007,
	PREF_INTERFACE_STD																		= 1008,
	PREF_INTERFACE_EDITSTD																= 1009,
	PREF_INTERFACE_RESETSTD																= 1010,
	PREF_INTERFACE_FONTSTD																= 1011,
	PREF_INTERFACE_MONO																		= 1012,
	PREF_INTERFACE_EDITMONO																= 1013,
	PREF_INTERFACE_RESETMONO															= 1014,
	PREF_INTERFACE_FONTMONO																= 1015,
	PREF_INTERFACE_NEWFEATUREHIGHLIGHT_FADE								= 1016,
	PREF_INTERFACE_AMLIMIT																= 1018,
	PREF_INTERFACE_INSERTAT																= 1019,
		PREF_INTERFACE_I_TOP																	= 0,
		PREF_INTERFACE_I_PREV																	= 1,
		PREF_INTERFACE_I_NEXT																	= 2,
		PREF_INTERFACE_I_PARENT																= 3,
		PREF_INTERFACE_I_CHILD																= 4,
		PREF_INTERFACE_I_ROOT																	= 5,
	PREF_INTERFACE_PASTEAT																= 1020,
	PREF_INTERFACE_CENTEROBJECT														= 1021,

	PREF_INTERFACE_MACMENU																= 1022,
	PREF_INTERFACE_MACDUMMY																= 1023,
	PREF_INTERFACE_SCRIPTWORDWRAP													= 1024,
	PREF_INTERFACE_FONTBIG																= 1025,
	PREF_INTERFACE_HIDEFIELDGRAPH													= 1026,		// LONG CYCLE
		PREF_INTERFACE_HIDEFIELDGRAPH_OFF											= 0,
		PREF_INTERFACE_HIDEFIELDGRAPH_ON											= 1,
		PREF_INTERFACE_HIDEFIELDGRAPH_INFIELDS								= 2,

	PREF_INTERFACE_SIMPLEFIELDUI													= 1027,		// BOOL

	PREFS_INTERFACE_FONTSGROUP														= 2000,
    
    PREF_INTERFACE_BASIC                                                            = 3000,
    PREF_INTERFACE_HELP                                                             = 3100,
    PREF_INTERFACE_ONLINEHELP                                                       = 3101,
    PREF_INTERFACE_EXTERNALHELP                                                     = 3102,
    PREF_INTERFACE_OPTIONS                                                          = 3200,

	PREFS_INTERFACE_DUMMY
};

#endif // PREFSINTERFACE_H__
