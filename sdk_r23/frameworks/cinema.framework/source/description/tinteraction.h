#ifndef TINTERACTION_H__
#define TINTERACTION_H__

enum
{
	INTERACTIONTAG_GROUP_PROXY					= 900,			//Group
	INTERACTIONTAG_GROUP_OUTPUT,
	INTERACTIONTAG_GROUP_POLYINFO,
	INTERACTIONTAG_GROUP_SCRIPT,

	INTERACTIONTAG_GROUP_INTERACTION,
	INTERACTIONTAG_GROUP_DISPLAY,
	INTERACTIONTAG_GROUP_SCRIPTING,
	INTERACTIONTAG_GROUP_DYNAMICPROXY,

	INTERACTIONTAG_SCRIPT_LANGUAGE_NONE				= 0,
	INTERACTIONTAG_SCRIPT_LANGUAGE_PYTHON			= 1,
	INTERACTIONTAG_SCRIPT_LANGUAGE_COFFEE			= 2,

	INTERACTIONTAG_SELECTEDTWEAKMODE_INVOKE		=	0,
	INTERACTIONTAG_SELECTEDTWEAKMODE_DISABLE	=	1,
	INTERACTIONTAG_SELECTEDTWEAKMODE_ALWAYS		=	2,

	INTERACTIONTAG_MOUSE_BUTTON_UP						=	0,
	INTERACTIONTAG_MOUSE_BUTTON_LEFT					=	1,
	INTERACTIONTAG_MOUSE_BUTTON_RIGHT					=	2,

	INTERACTIONTAG_ENABLE								= 1000,			//Bool
	INTERACTIONTAG_TWEAKABLE,												//Bool
	INTERACTIONTAG_MOUSE_BUTTON,										//Int
	INTERACTIONTAG_HIDE_MOUSE,											//Bool
	INTERACTIONTAG_HIGHLIGHT,												//Bool
	INTERACTIONTAG_HIGHLIGHT_PROXY,									//Bool
	INTERACTIONTAG_SELECT,													//Bool
	INTERACTIONTAG_SELECT_PROXY,										//Bool
	INTERACTIONTAG_XPIXELS,													//Int
	INTERACTIONTAG_YPIXELS,													//Int
	INTERACTIONTAG_MOUSE_TRAVEL,										//Float
	INTERACTIONTAG_WORLD_DELTA,											//Vector
	INTERACTIONTAG_PROXY_OBJECT,										//Link
	INTERACTIONTAG_SCRIPT_PY,												//String
	INTERACTIONTAG_SCRIPT_COF,											//String
	INTERACTIONTAG_EDIT_SCRIPT,											//Button
	INTERACTIONTAG_SCRIPT_LANGUAGE,									//Int
	INTERACTIONTAG_HIDE_OBJECT,											//Bool
	INTERACTIONTAG_OBJECT_TWEAKED,									//Bool
	INTERACTIONTAG_XMOUSE,													//Int
	INTERACTIONTAG_YMOUSE,													//Int
	INTERACTIONTAG_DISABLEMOVE,											//Bool
	INTERACTIONTAG_SELECTEDTWEAKMODE,								//Int
	INTERACTIONTAG_OBJECT_SELECTED,									//Bool
	INTERACTIONTAG_OBJECT_HIGHLIGHTED,							//Bool
	INTERACTIONTAG_TWEAK_PROXY,											//Bool
	INTERACTIONTAG_USEPOLYINFO,											//Bool
	INTERACTIONTAG_LIVEPOLYINFO,										//Bool
	INTERACTIONTAG_POLYINFO_HIT,										//Bool
	INTERACTIONTAG_POLYINFO_HITPOINT,								//Vector
	INTERACTIONTAG_POLYINFO_POLYGON,								//Int
	INTERACTIONTAG_POLYINFO_EDGE,										//Int
	INTERACTIONTAG_POLYINFO_POINT,									//Int
	INTERACTIONTAG_POLYINFO_SELECTIONTAG,						//BaseLink
	INTERACTIONTAG_POLYINFO_SELECTIONTAGINDEX,			//Int
	INTERACTIONTAG_MOUSE_PRESSURE,									//Float
	INTERACTIONTAG_MOUSE_TILT,											//Float
	INTERACTIONTAG_MOUSE_ANGLE,											//Float
	INTERACTIONTAG_MOUSE_WHEEL,											//Float
	INTERACTIONTAG_USERIGHTMOUSE,										//Bool
	INTERACTIONTAG_POLYINFO_USETAGPROXY,						//Bool

	INTERACTIONTAG_POLYINFO_TAGPROXY			= 2000,		//Baselink

	INTERACTIONTAG_DUMMY___
};
#endif // TINTERACTION_H__
