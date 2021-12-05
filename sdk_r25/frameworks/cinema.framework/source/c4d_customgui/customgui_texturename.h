/////////////////////////////////////////////////////////////
// Cinema 4D SDK                                           //
/////////////////////////////////////////////////////////////
// (c) MAXON Computer GmbH, all rights reserved            //
/////////////////////////////////////////////////////////////

#ifndef CUSTOMGUI_TEXTURENAME_H__
#define CUSTOMGUI_TEXTURENAME_H__

#include "customgui_base.h"
#include "c4d_basecontainer.h"
#include "c4d_gui.h"

/// Texure name custom GUI ID.
#define CUSTOMGUI_TEXTURENAME	1000484

//----------------------------------------------------------------------------------------
/// Texture name custom GUI (@ref CUSTOMGUI_TEXTURENAME).
//----------------------------------------------------------------------------------------
class TexturenameCustomGui : public BaseCustomGui<CUSTOMGUI_TEXTURENAME>
{
		TexturenameCustomGui();
		~TexturenameCustomGui();

	public:
};

/// @cond IGNORE

// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF

#ifndef _INTERNAL_DEF_
	class iTexturenameCustomGui : public iBaseCustomGui
	{
		iTexturenameCustomGui(const BaseContainer &settings, CUSTOMGUIPLUGIN *plugin) : iBaseCustomGui(settings, plugin) { }
	};
#else
	class iTexturenameCustomGui;
#endif

struct CustomGuiTexturenameLib : public BaseCustomGuiLib
{
};

// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF

/// @endcond

#endif // CUSTOMGUI_TEXTURENAME_H__
