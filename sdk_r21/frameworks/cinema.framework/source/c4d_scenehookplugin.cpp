#include "c4d_memory.h"
#include "c4d_general.h"
#include "c4d_scenehookplugin.h"

Bool SceneHookData::MouseInput(BaseSceneHook* node, BaseDocument* doc, BaseDraw* bd, EditorWindow* win, const BaseContainer& msg)
{
	return false;
}

Bool SceneHookData::DisplayControl(BaseDocument* doc, BaseObject* op, BaseObject* chainstart, BaseDraw* bd, BaseDrawHelp* bh, ControlDisplayStruct& cds)
{
	return false;
}

Bool SceneHookData::InitDisplayControl(BaseSceneHook* node, BaseDocument* doc, BaseDraw* bd, const AtomArray* active)
{
	return false;
}

void SceneHookData::FreeDisplayControl(void)
{

}

Bool SceneHookData::KeyboardInput(BaseSceneHook* node, BaseDocument* doc, BaseDraw* bd, EditorWindow* win, const BaseContainer& msg)
{
	return false;
}

Bool SceneHookData::GetCursorInfo(BaseSceneHook* node, BaseDocument* doc, BaseDraw* bd, Float x, Float y, BaseContainer& bc)
{
	return false;
}

Bool SceneHookData::Draw(BaseSceneHook* node, BaseDocument* doc, BaseDraw* bd, BaseDrawHelp* bh, BaseThread* bt, SCENEHOOKDRAW flags)
{
	return true;
}

Bool SceneHookData::AddToExecution(BaseSceneHook* node, PriorityList* list)
{
	return false;
}

EXECUTIONRESULT SceneHookData::InitSceneHook(BaseSceneHook* node, BaseDocument* doc, BaseThread* bt)
{
	return EXECUTIONRESULT::OK;
}

void SceneHookData::FreeSceneHook(BaseSceneHook* node, BaseDocument* doc)
{
}

EXECUTIONRESULT SceneHookData::Execute(BaseSceneHook* node, BaseDocument* doc, BaseThread* bt, Int32 priority, EXECUTIONFLAGS flags)
{
	return EXECUTIONRESULT::OK;
}

static void FillSceneHookPlugin(SCENEHOOKPLUGIN* np, DataAllocator* npalloc, Int32 info, Int32 disklevel, Int32 priority)
{
	FillNodePlugin(np, info, npalloc, nullptr, disklevel);

	np->draw_priority	= priority;
	np->MouseInput = &SceneHookData::MouseInput;
	np->GetCursorInfo	= &SceneHookData::GetCursorInfo;
	np->Draw = &SceneHookData::Draw;
	np->AddToExecution = &SceneHookData::AddToExecution;
	np->InitSceneHook	 = &SceneHookData::InitSceneHook;
	np->FreeSceneHook	 = &SceneHookData::FreeSceneHook;
	np->Execute	= &SceneHookData::Execute;
	np->KeyboardInput	 = &SceneHookData::KeyboardInput;
	np->DisplayControl = &SceneHookData::DisplayControl;
	np->InitDisplayControl = &SceneHookData::InitDisplayControl;
	np->FreeDisplayControl = &SceneHookData::FreeDisplayControl;
}

Bool RegisterSceneHookPlugin(Int32 id, const maxon::String& str, Int32 info, DataAllocator* npalloc, Int32 priority, Int32 disklevel)
{
	SCENEHOOKPLUGIN np;
	ClearMem(&np, sizeof(np));
	FillSceneHookPlugin(&np, npalloc, info, disklevel, priority);
	return GeRegisterPlugin(PLUGINTYPE::SCENEHOOK, id, str, &np, sizeof(np));
}
