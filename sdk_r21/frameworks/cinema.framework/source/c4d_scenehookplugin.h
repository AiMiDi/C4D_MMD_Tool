/////////////////////////////////////////////////////////////
// Cinema 4D SDK                                           //
/////////////////////////////////////////////////////////////
// (c) MAXON Computer GmbH, all rights reserved            //
/////////////////////////////////////////////////////////////

#ifndef C4D_SCENEHOOKPLUGIN_H__
#define C4D_SCENEHOOKPLUGIN_H__

#include "ge_math.h"
#include "c4d_scenehookdata.h"
#include "c4d_nodeplugin.h"

/// @cond IGNORE

// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF

struct SCENEHOOKPLUGIN : public NODEPLUGIN
{
	public:
		Int32 draw_priority;

		Bool						(SceneHookData::*MouseInput					)(BaseSceneHook *node, BaseDocument *doc, BaseDraw *bd, EditorWindow *win, const BaseContainer &msg);
		Bool						(SceneHookData::*GetCursorInfo			)(BaseSceneHook *node, BaseDocument *doc, BaseDraw *bd, Float x, Float y, BaseContainer &bc);
		Bool						(SceneHookData::*Draw								)(BaseSceneHook *node, BaseDocument *doc, BaseDraw *bd, BaseDrawHelp *bh, BaseThread *bt, SCENEHOOKDRAW flags);

		Bool						(SceneHookData::*AddToExecution			)(BaseSceneHook *node, PriorityList *list);
		EXECUTIONRESULT	(SceneHookData::*InitSceneHook			)(BaseSceneHook *node, BaseDocument *doc, BaseThread *bt);
		void						(SceneHookData::*FreeSceneHook			)(BaseSceneHook *node, BaseDocument *doc);
		EXECUTIONRESULT	(SceneHookData::*Execute						)(BaseSceneHook *node, BaseDocument *doc, BaseThread *bt, Int32 priority, EXECUTIONFLAGS flags);

		Bool						(SceneHookData::*KeyboardInput			)(BaseSceneHook *node, BaseDocument *doc, BaseDraw *bd, EditorWindow *win, const BaseContainer &msg);

		Bool						(SceneHookData::*InitDisplayControl	)(BaseSceneHook *node, BaseDocument* doc, BaseDraw* bd, const AtomArray* active);
		void						(SceneHookData::*FreeDisplayControl	)(void);

		Bool						(SceneHookData::*DisplayControl			)(BaseDocument *doc, BaseObject *op, BaseObject *chainstart, BaseDraw *bd, BaseDrawHelp *bh, ControlDisplayStruct &cds);

		void* reserved[(32-11)*C4DPL_MEMBERMULTIPLIER-1];
};

// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF

/// @endcond

#endif // C4D_SCENEHOOKPLUGIN_H__
