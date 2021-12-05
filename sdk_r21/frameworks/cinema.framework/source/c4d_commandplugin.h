/////////////////////////////////////////////////////////////
// Cinema 4D SDK                                           //
/////////////////////////////////////////////////////////////
// (c) MAXON Computer GmbH, all rights reserved            //
/////////////////////////////////////////////////////////////

#ifndef C4D_COMMANDPLUGIN_H__
#define C4D_COMMANDPLUGIN_H__

#include "ge_math.h"
#include "c4d_commanddata.h"
#include "c4d_baseplugin.h"

/// @cond IGNORE

// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF

struct COMMANDPLUGIN : public STATICPLUGIN
{
	String*			help;
	BaseBitmap*	command_icon;

	Bool				(CommandData::*Execute)(BaseDocument* doc, GeDialog* parentManager);
	Int32				(CommandData::*GetState)(BaseDocument* doc, GeDialog* parentManager);
	Bool				(CommandData::*RestoreLayout)(void* secret);
	void				(CommandData::*MessageEx)(const BaseContainer& bc);
	String			(CommandData::*GetScriptName)(void);
	Bool				(CommandData::*GetSubContainer)(BaseDocument* doc, BaseContainer& submenu, GeDialog* parentManager);
	Bool				(CommandData::*ExecuteSubID)(BaseDocument* doc, Int32 subid, GeDialog* parentManager);
	Bool				(CommandData::*Message)(Int32 type, void* data);
	Bool				(CommandData::*ExecuteOptionID)(BaseDocument* doc, Int32 plugid, Int32 subid, GeDialog* parentManager);

	void* reserved[(32 - 9) * C4DPL_MEMBERMULTIPLIER - 2];
};

struct MANAGERINFORMATION : public STATICPLUGIN
{
	Int32 info;

	void* reserved[32 * C4DPL_MEMBERMULTIPLIER - 1];
};

// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF

/// @endcond

#endif // C4D_COMMANDPLUGIN_H__
