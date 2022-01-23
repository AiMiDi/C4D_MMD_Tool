#ifndef FRIBEXPORT_H__
#define FRIBEXPORT_H__

enum
{
	RIBEXPORT_GROUP									= 9999,

	RIBEXPORT_RENDERSETTINGS				= 10000,	// LONG
		RIBEXPORT_RENDERSETTINGS_CURRENT 	= 0,

	RIBEXPORT_EXPORTAS							= 30105,	// LONG
		RIBEXPORT_EXPORTAS_FULLSCENE			= 0,
		RIBEXPORT_EXPORTAS_ARCHIVEGEOANDLIGHTS	= 1,
		RIBEXPORT_EXPORTAS_ARCHIVEGEOONLY		= 2,
		RIBEXPORT_EXPORTAS_ARCHIVELIGHTSONLY	= 3,


	RIBEXPORT_DISPLAYNAME					= 10001,
	RIBEXPORT_DISPLAYPRESET					= 10002,
		RIBEXPORT_DISPLAYPRESET_CUSTOM		= 0,
		RIBEXPORT_DISPLAYPRESET_FRAMEBUFFER	= 1,
		RIBEXPORT_DISPLAYPRESET_FILE		= 2,
	RIBEXPORT_DISPLAYDRIVER					= 10003,

	RIBEXPORT_RIBSTYLE							= 70001,
		RIBEXPORT_RIBSTYLE_ARCHIVES		= 0,
		RIBEXPORT_RIBSTYLE_FLAT				= 1,

	RIBEXPORT_EXPORTMAINRIB					= 30112,	// Bool
	RIBEXPORT_EXPORTSHADERS					= 30109,	// Bool
	RIBEXPORT_EXPORTCOMPILESHADERS			= 30102,	// Bool
	RIBEXPORT_EXPORTTEXTURES				= 30108,	// Bool
	RIBEXPORT_EXPORTMAKETEXTURES			= 30103,	// Bool
	RIBEXPORT_EXPORTARCHIVES				= 30104,	// Bool
	RIBEXPORT_FLATDIRECTORY					= 30110,	// Bool (no subdirs like archives, textures, shaders)
	RIBEXPORT_COPYAUXFILES					= 30111,	// Bool (copy over shader headers, default shaders, dsos, display drivers)
	RIBEXPORT_ONLYSELECTED					= 30106		// Bool
};

#endif // FRIBEXPORT_H__