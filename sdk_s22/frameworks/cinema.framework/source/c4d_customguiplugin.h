/////////////////////////////////////////////////////////////
// Cinema 4D SDK                                           //
/////////////////////////////////////////////////////////////
// (c) MAXON Computer GmbH, all rights reserved            //
/////////////////////////////////////////////////////////////

#ifndef C4D_CUSTOMGUIPLUGIN_H__
#define C4D_CUSTOMGUIPLUGIN_H__

#include "ge_math.h"
#include "c4d_customguidata.h"
#include "c4d_baseplugin.h"

/// @cond IGNORE

// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF

struct CUSTOMGUIPLUGIN : public STATICPLUGIN
{
	CDialog*						(CustomGuiData::*Alloc							)(const BaseContainer &settings);
	void								(CustomGuiData::*Free								)(CDialog *dlg, void *userdata);
	const Char*					(CustomGuiData::*GetResourceSym			)();
	CustomProperty*			(CustomGuiData::*GetProperties			)();
	Int32								(CustomGuiData::*GetResourceDataType)(Int32 *&table);

	void* reserved[(32-5)*C4DPL_MEMBERMULTIPLIER];
};

#define CallCustomGuiCmd(plug, fnc)	(((CustomGuiData*)(((CUSTOMGUIPLUGIN *)plug->GetPluginStructure())->adr))->*((CUSTOMGUIPLUGIN *)plug->GetPluginStructure())->fnc)

// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF

/// @endcond

//----------------------------------------------------------------------------------------
/// Finds registered custom GUI plugin structures from a @formatParam{type} ID.
/// @param[in] type								The type ID.
/// @return												The found plugin structure, or @formatConstant{nullptr}. @cinemaOwnsPointed{plugin structure}
//----------------------------------------------------------------------------------------
CUSTOMGUIPLUGIN *FindCustomGuiPlugin(Int32 type);

#endif // C4D_CUSTOMGUIPLUGIN_H__
