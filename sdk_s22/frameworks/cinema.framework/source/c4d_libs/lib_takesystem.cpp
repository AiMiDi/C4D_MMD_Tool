#include "lib_takesystem.h"

static TakeSystemLibrary* take_lib_cache = nullptr;

static TakeSystemLibrary* CheckTakeSystemLib(Int32 offset)
{
	return (TakeSystemLibrary*)CheckLib(ID_TAKESYSTEM_LIB, offset, (C4DLibrary**)&take_lib_cache);
}

Bool BaseOverrideGroup::GetObjectsInGroup(AtomArray& selection)
{
	TakeSystemLibrary* lib = CheckTakeSystemLib(LIBOFFSET(TakeSystemLibrary, GetObjectsInGroup));
	if (!lib || !lib->GetObjectsInGroup)
		return false;
	return (((iBaseOverrideGroup*)this)->*(lib->GetObjectsInGroup))(selection);
}

void BaseOverrideGroup::AddToGroup(TakeData* takeData, BaseList2D* node)
{
	TakeSystemLibrary* lib = CheckTakeSystemLib(LIBOFFSET(TakeSystemLibrary, AddToGroup));
	if (!lib || !lib->AddToGroup)
		return;
	(((iBaseOverrideGroup*)this)->*(lib->AddToGroup))((iTakeData*)takeData, node);
}

void BaseOverrideGroup::RemoveFromGroup(TakeData* takeData, BaseList2D* node)
{
	TakeSystemLibrary* lib = CheckTakeSystemLib(LIBOFFSET(TakeSystemLibrary, RemoveFromGroup));
	if (!lib || !lib->RemoveFromGroup)
		return;
	(((iBaseOverrideGroup*)this)->*(lib->RemoveFromGroup))((iTakeData*)takeData, node);
}

BaseTag* BaseOverrideGroup::AddTag(TakeData* takeData, Int32 type, BaseMaterial* mat)
{
	TakeSystemLibrary* lib = CheckTakeSystemLib(LIBOFFSET(TakeSystemLibrary, AddTag));
	if (!lib || !lib->AddTag)
		return nullptr;
	return (((iBaseOverrideGroup*)this)->*(lib->AddTag))((iTakeData*)takeData, type, mat);
}

void BaseOverrideGroup::RemoveTag(TakeData* takeData, Int32 type)
{
	TakeSystemLibrary* lib = CheckTakeSystemLib(LIBOFFSET(TakeSystemLibrary, RemoveTag));
	if (!lib || !lib->RemoveTag)
		return;
	(((iBaseOverrideGroup*)this)->*(lib->RemoveTag))((iTakeData*)takeData, type);
}

Int32 BaseOverrideGroup::GetEditorMode()
{
	TakeSystemLibrary* lib = CheckTakeSystemLib(LIBOFFSET(TakeSystemLibrary, GetEditorMode));
	if (!lib || !lib->GetEditorMode)
		return NOTOK;
	return (((iBaseOverrideGroup*)this)->*(lib->GetEditorMode))();
}

Int32 BaseOverrideGroup::GetRenderMode()
{
	TakeSystemLibrary* lib = CheckTakeSystemLib(LIBOFFSET(TakeSystemLibrary, GetRenderMode));
	if (!lib || !lib->GetRenderMode)
		return NOTOK;
	return (((iBaseOverrideGroup*)this)->*(lib->GetRenderMode))();
}

void BaseOverrideGroup::SetEditorMode(Int32 mode)
{
	TakeSystemLibrary* lib = CheckTakeSystemLib(LIBOFFSET(TakeSystemLibrary, SetEditorMode));
	if (!lib || !lib->SetEditorMode)
		return;
	(((iBaseOverrideGroup*)this)->*(lib->SetEditorMode))(mode);
}

void BaseOverrideGroup::SetRenderMode(Int32 mode)
{
	TakeSystemLibrary* lib = CheckTakeSystemLib(LIBOFFSET(TakeSystemLibrary, SetRenderMode));
	if (!lib || !lib->SetRenderMode)
		return;
	(((iBaseOverrideGroup*)this)->*(lib->SetRenderMode))(mode);
}

BaseTag* BaseOverrideGroup::GetTag(Int32 type)
{
	TakeSystemLibrary* lib = CheckTakeSystemLib(LIBOFFSET(TakeSystemLibrary, GetTag));
	if (!lib || !lib->GetTag)
		return nullptr;
	return (((iBaseOverrideGroup*)this)->*(lib->GetTag))(type);
}

BaseTake* BaseOverrideGroup::GetTake()
{
	TakeSystemLibrary* lib = CheckTakeSystemLib(LIBOFFSET(TakeSystemLibrary, GetTake));
	if (!lib || !lib->GetTake)
		return nullptr;
	return (BaseTake*)(((iBaseOverrideGroup*)this)->*(lib->GetTake))();
}

Bool BaseOverrideGroup::Find(TakeData* takeData, BaseObject* op)
{
	TakeSystemLibrary* lib = CheckTakeSystemLib(LIBOFFSET(TakeSystemLibrary, Find));
	if (!lib || !lib->Find)
		return false;
	return (((iBaseOverrideGroup*)this)->*(lib->Find))((iTakeData*)takeData, op);
}

Bool BaseTake::IsMain()
{
	TakeSystemLibrary* lib = CheckTakeSystemLib(LIBOFFSET(TakeSystemLibrary, IsMain));
	if (!lib || !lib->IsMain)
		return false;
	return (((iBaseTake*)this)->*(lib->IsMain))();
}

Bool BaseTake::SearchHierarchy(BaseTake* op)
{
	TakeSystemLibrary* lib = CheckTakeSystemLib(LIBOFFSET(TakeSystemLibrary, SearchHierarchy));
	if (!lib || !lib->SearchHierarchy)
		return false;
	return (((iBaseTake*)this)->*(lib->SearchHierarchy))((iBaseTake*)op);
}

Bool BaseTake::GetOverrides(AtomArray& selection)
{
	TakeSystemLibrary* lib = CheckTakeSystemLib(LIBOFFSET(TakeSystemLibrary, GetOverrides));
	if (!lib || !lib->GetOverrides)
		return false;
	return (((iBaseTake*)this)->*(lib->GetOverrides))(selection);
}

Bool BaseTake::GetOverrideGroups(AtomArray& selection)
{
	TakeSystemLibrary* lib = CheckTakeSystemLib(LIBOFFSET(TakeSystemLibrary, GetOverrideGroups));
	if (!lib || !lib->GetOverrideGroups)
		return false;
	return (((iBaseTake*)this)->*(lib->GetOverrideGroups))(selection);
}

BaseOverride* BaseTake::FindOrAddOverrideParam(TakeData* takeData, BaseList2D* node, const DescID& descID, const GeData& overrideValue, const GeData& backupValue, Bool deleteAnim)
{
	TakeSystemLibrary* lib = CheckTakeSystemLib(LIBOFFSET(TakeSystemLibrary, IsMain));
	if (!lib || !lib->FindOrAddOverrideParam)
		return nullptr;
	return (BaseOverride*)(((iBaseTake*)this)->*(lib->FindOrAddOverrideParam))((iTakeData*)takeData, node, descID, overrideValue, backupValue, deleteAnim);
}

BaseOverride* BaseTake::OverrideNode(TakeData* takeData, BaseList2D* node, Bool deleteAnim)
{
	TakeSystemLibrary* lib = CheckTakeSystemLib(LIBOFFSET(TakeSystemLibrary, OverrideNode));
	if (!lib || !lib->OverrideNode)
		return nullptr;
	return (BaseOverride*)(((iBaseTake*)this)->*(lib->OverrideNode))((iTakeData*)takeData, node, deleteAnim);
}

void BaseTake::AutoTake(TakeData* takeData, BaseList2D* node, BaseList2D* undo)
{
	TakeSystemLibrary* lib = CheckTakeSystemLib(LIBOFFSET(TakeSystemLibrary, AutoTake));
	if (!lib || !lib->AutoTake)
		return;
	(((iBaseTake*)this)->*(lib->AutoTake))((iTakeData*)takeData, node, undo);
}

void BaseTake::DeleteOverride(TakeData* takeData, BaseList2D* node, const DescID& descID)
{
	TakeSystemLibrary* lib = CheckTakeSystemLib(LIBOFFSET(TakeSystemLibrary, DeleteOverride));
	if (!lib || !lib->DeleteOverride)
		return;
	(((iBaseTake*)this)->*(lib->DeleteOverride))((iTakeData*)takeData, node, descID);
}

BaseOverride* BaseTake::FindOverride(TakeData* takeData, BaseList2D* node)
{
	TakeSystemLibrary* lib = CheckTakeSystemLib(LIBOFFSET(TakeSystemLibrary, FindOverride));
	if (!lib || !lib->FindOverride)
		return nullptr;
	return (BaseOverride*)(((iBaseTake*)this)->*(lib->FindOverride))((iTakeData*)takeData, node);
}

BaseOverride* BaseTake::FindOverrideInHierarchy(TakeData* takeData, BaseList2D* node, const DescID& descID, BaseTake*& resultTake)
{
	TakeSystemLibrary* lib = CheckTakeSystemLib(LIBOFFSET(TakeSystemLibrary, FindOverrideInHierarchy));
	if (!lib || !lib->FindOverrideInHierarchy)
		return nullptr;
	return (BaseOverride*)(((iBaseTake*)this)->*(lib->FindOverrideInHierarchy))((iTakeData*)takeData, node, descID, (iBaseTake*&)resultTake);
}

BaseOverrideGroup* BaseTake::AddOverrideGroup()
{
	TakeSystemLibrary* lib = CheckTakeSystemLib(LIBOFFSET(TakeSystemLibrary, AddOverrideGroup));
	if (!lib || !lib->AddOverrideGroup)
		return nullptr;
	return (BaseOverrideGroup*)(((iBaseTake*)this)->*(lib->AddOverrideGroup))();
}

BaseOverrideGroup* BaseTake::GetFirstOverrideGroup()
{
	TakeSystemLibrary* lib = CheckTakeSystemLib(LIBOFFSET(TakeSystemLibrary, GetFirstOverrideGroup));
	if (!lib || !lib->GetFirstOverrideGroup)
		return nullptr;
	return (BaseOverrideGroup*)(((iBaseTake*)this)->*(lib->GetFirstOverrideGroup))();
}

void BaseTake::DeleteOverrideGroup(TakeData* takeData, BaseOverrideGroup* og)
{
	TakeSystemLibrary* lib = CheckTakeSystemLib(LIBOFFSET(TakeSystemLibrary, DeleteOverrideGroup));
	if (!lib || !lib->DeleteOverrideGroup)
		return;
	(((iBaseTake*)this)->*(lib->DeleteOverrideGroup))((iTakeData*)takeData, (iBaseOverrideGroup*)og);
}

BaseObject* BaseTake::GetCamera(TakeData* takeData)
{
	TakeSystemLibrary* lib = CheckTakeSystemLib(LIBOFFSET(TakeSystemLibrary, GetCamera));
	if (!lib || !lib->GetCamera)
		return nullptr;
	return (((iBaseTake*)this)->*(lib->GetCamera))((iTakeData*)takeData);
}

BaseObject* BaseTake::GetEffectiveCamera(TakeData* takeData, BaseTake*& resultTake)
{
	TakeSystemLibrary* lib = CheckTakeSystemLib(LIBOFFSET(TakeSystemLibrary, GetEffectiveCamera));
	if (!lib || !lib->GetEffectiveCamera)
		return nullptr;
	return (((iBaseTake*)this)->*(lib->GetEffectiveCamera))((iTakeData*)takeData, (iBaseTake*&)resultTake);
}

void BaseTake::SetCamera(TakeData* takeData, BaseObject* camera)
{
	TakeSystemLibrary* lib = CheckTakeSystemLib(LIBOFFSET(TakeSystemLibrary, SetCamera));
	if (!lib || !lib->SetCamera)
		return;
	(((iBaseTake*)this)->*(lib->SetCamera))((iTakeData*)takeData, camera);
}

RenderData* BaseTake::GetRenderData(TakeData* takeData)
{
	TakeSystemLibrary* lib = CheckTakeSystemLib(LIBOFFSET(TakeSystemLibrary, GetRenderData));
	if (!lib || !lib->GetRenderData)
		return nullptr;
	return (((iBaseTake*)this)->*(lib->GetRenderData))((iTakeData*)takeData);
}

RenderData* BaseTake::GetEffectiveRenderData(TakeData* takeData, BaseTake*& resultTake)
{
	TakeSystemLibrary* lib = CheckTakeSystemLib(LIBOFFSET(TakeSystemLibrary, GetEffectiveRenderData));
	if (!lib || !lib->GetEffectiveRenderData)
		return nullptr;
	return (((iBaseTake*)this)->*(lib->GetEffectiveRenderData))((iTakeData*)takeData, (iBaseTake*&)resultTake);
}

void BaseTake::SetRenderData(TakeData* takeData, RenderData* rData)
{
	TakeSystemLibrary* lib = CheckTakeSystemLib(LIBOFFSET(TakeSystemLibrary, SetRenderData));
	if (!lib || !lib->SetRenderData)
		return;
	(((iBaseTake*)this)->*(lib->SetRenderData))((iTakeData*)takeData, rData);
}

Bool BaseTake::IsChecked()
{
	TakeSystemLibrary* lib = CheckTakeSystemLib(LIBOFFSET(TakeSystemLibrary, IsChecked));
	if (!lib || !lib->IsChecked)
		return false;
	return (((iBaseTake*)this)->*(lib->IsChecked))();
}

void BaseTake::SetChecked(Bool status)
{
	TakeSystemLibrary* lib = CheckTakeSystemLib(LIBOFFSET(TakeSystemLibrary, SetChecked));
	if (!lib || !lib->SetChecked)
		return;
	(((iBaseTake*)this)->*(lib->SetChecked))(status);
}

void BaseTake::Reset()
{
	TakeSystemLibrary* lib = CheckTakeSystemLib(LIBOFFSET(TakeSystemLibrary, Reset));
	if (!lib || !lib->Reset)
		return;
	(((iBaseTake*)this)->*(lib->Reset))();
}

Bool BaseOverride::IsOverriddenParam (const DescID& descID)
{
	TakeSystemLibrary* lib = CheckTakeSystemLib(LIBOFFSET(TakeSystemLibrary, IsOverriddenParam));
	if (!lib || !lib->IsOverriddenParam)
		return false;
	return (((iBaseOverride*)this)->*(lib->IsOverriddenParam))(descID);
}

BaseList2D* BaseOverride::GetSceneNode()
{
	TakeSystemLibrary* lib = CheckTakeSystemLib(LIBOFFSET(TakeSystemLibrary, GetSceneNode));
	if (!lib || !lib->GetSceneNode)
		return nullptr;
	return (((iBaseOverride*)this)->*(lib->GetSceneNode))();
}

BaseTake* BaseOverride::GetOwnerTake(TakeData* takeData)
{
	TakeSystemLibrary* lib = CheckTakeSystemLib(LIBOFFSET(TakeSystemLibrary, GetOwnerTake));
	if (!lib || !lib->GetOwnerTake)
		return nullptr;
	return (BaseTake*)(((iBaseOverride*)this)->*(lib->GetOwnerTake))((iTakeData*)takeData);
}

Bool BaseOverride::IsInGroup(TakeData* takeData, BaseOverrideGroup*& resGroup)
{
	TakeSystemLibrary* lib = CheckTakeSystemLib(LIBOFFSET(TakeSystemLibrary, IsInGroup));
	if (!lib || !lib->IsInGroup)
		return false;
	return (((iBaseOverride*)this)->*(lib->IsInGroup))((iTakeData*)takeData, (iBaseOverrideGroup*&)resGroup);
}

Bool BaseOverride::GetAllOverrideDescID(maxon::BaseArray<DescID>& result)
{
	TakeSystemLibrary* lib = CheckTakeSystemLib(LIBOFFSET(TakeSystemLibrary, GetAllOverrideDescID));
	if (!lib || !lib->GetAllOverrideDescID)
		return false;
	return (((iBaseOverride*)this)->*(lib->GetAllOverrideDescID))(result);
}

void BaseOverride::UpdateSceneNode(TakeData* takeData, const DescID& descID)
{
	TakeSystemLibrary* lib = CheckTakeSystemLib(LIBOFFSET(TakeSystemLibrary, UpdateSceneNode));
	if (!lib || !lib->UpdateSceneNode)
		return;
	(((iBaseOverride*)this)->*(lib->UpdateSceneNode))((iTakeData*)takeData, descID);
}

Bool TakeData::Set(BaseDocument* doc)
{
	TakeSystemLibrary* lib = CheckTakeSystemLib(LIBOFFSET(TakeSystemLibrary, Set));
	if (!lib || !lib->Set)
		return false;
	return (((iTakeData*)this)->*(lib->Set))(doc);
}

BaseDocument* TakeData::GetDocument()
{
	TakeSystemLibrary* lib = CheckTakeSystemLib(LIBOFFSET(TakeSystemLibrary, GetDocument));
	if (!lib || !lib->GetDocument)
		return nullptr;
	return (((iTakeData*)this)->*(lib->GetDocument))();
}

BaseTake* TakeData::GetMainTake()
{
	TakeSystemLibrary* lib = CheckTakeSystemLib(LIBOFFSET(TakeSystemLibrary, GetMainTake));
	if (!lib || !lib->GetMainTake)
		return nullptr;
	return (BaseTake*)(((iTakeData*)this)->*(lib->GetMainTake))();
}

TAKE_MODE TakeData::GetTakeMode()
{
	TakeSystemLibrary* lib = CheckTakeSystemLib(LIBOFFSET(TakeSystemLibrary, GetTakeMode));
	if (!lib || !lib->GetTakeMode)
		return TAKE_MODE::MANUAL;
	return (((iTakeData*)this)->*(lib->GetTakeMode))();
}

OVERRIDEENABLING TakeData::GetOverrideEnabling()
{
	TakeSystemLibrary* lib = CheckTakeSystemLib(LIBOFFSET(TakeSystemLibrary, GetOverrideEnabling));
	if (!lib || !lib->GetOverrideEnabling)
		return OVERRIDEENABLING::NONE;
	return (((iTakeData*)this)->*(lib->GetOverrideEnabling))();
}

Bool TakeData::CheckOverrideEnabling(OVERRIDEENABLING mask)
{
	TakeSystemLibrary* lib = CheckTakeSystemLib(LIBOFFSET(TakeSystemLibrary, CheckOverrideEnabling));
	if (!lib || !lib->CheckOverrideEnabling)
		return false;
	return (((iTakeData*)this)->*(lib->CheckOverrideEnabling))(mask);
}

void TakeData::GetTakeSelection(AtomArray& selection, Bool children)
{
	TakeSystemLibrary* lib = CheckTakeSystemLib(LIBOFFSET(TakeSystemLibrary, GetTakeSelection));
	if (!lib || !lib->GetTakeSelection)
		return;
	(((iTakeData*)this)->*(lib->GetTakeSelection))(selection, children);
}

BaseTake* TakeData::GetCurrentTake()
{
	TakeSystemLibrary* lib = CheckTakeSystemLib(LIBOFFSET(TakeSystemLibrary, GetCurrentTake));
	if (!lib || !lib->GetCurrentTake)
		return nullptr;

	return (BaseTake*)(((iTakeData*)this)->*(lib->GetCurrentTake))();
}

Bool TakeData::SetCurrentTake(BaseTake* take)
{
	TakeSystemLibrary* lib = CheckTakeSystemLib(LIBOFFSET(TakeSystemLibrary, SetCurrentTake));
	if (!lib || !lib->SetCurrentTake)
		return false;

	return (((iTakeData*)this)->*(lib->SetCurrentTake))((iBaseTake*)take);
}

BaseDocument* TakeData::TakeToDocument(BaseTake* take)
{
	TakeSystemLibrary* lib = CheckTakeSystemLib(LIBOFFSET(TakeSystemLibrary, TakeToDocument));
	if (!lib || !lib->TakeToDocument)
		return nullptr;

	return (((iTakeData*)this)->*(lib->TakeToDocument))((iBaseTake*)take);
}

Bool TakeData::SaveTakesWithAssets(Bool selected)
{
	TakeSystemLibrary* lib = CheckTakeSystemLib(LIBOFFSET(TakeSystemLibrary, SaveTakesWithAssets));
	if (!lib || !lib->SaveTakesWithAssets)
		return false;

	return (((iTakeData*)this)->*(lib->SaveTakesWithAssets))(selected);
}

BaseTake* TakeData::AddTake(const String& name, BaseTake* parent, BaseTake* cloneFrom)
{
	TakeSystemLibrary* lib = CheckTakeSystemLib(LIBOFFSET(TakeSystemLibrary, AddTake));
	if (!lib || !lib->AddTake)
		return nullptr;
	return (BaseTake*)(((iTakeData*)this)->*(lib->AddTake))(name, (iBaseTake*)parent, (iBaseTake*)cloneFrom);
}

void TakeData::DeleteTake(BaseTake* take)
{
	TakeSystemLibrary* lib = CheckTakeSystemLib(LIBOFFSET(TakeSystemLibrary, DeleteTake));
	if (!lib || !lib->DeleteTake)
		return;
	(((iTakeData*)this)->*(lib->DeleteTake))((iBaseTake*)take);
}

void TakeData::InsertTake(BaseTake* takeToMove, BaseTake* destTake, Int32 insertMode)
{
	TakeSystemLibrary* lib = CheckTakeSystemLib(LIBOFFSET(TakeSystemLibrary, InsertTake));
	if (!lib || !lib->InsertTake)
		return;

	(((iTakeData*)this)->*(lib->InsertTake))((iBaseTake*)takeToMove, (iBaseTake*)destTake, insertMode);
}

BaseOverride*	TakeData::FindOverrideCounterPart(BaseOverride* overrideNode, const DescID& descID, BaseTake*& resultTake)
{
	TakeSystemLibrary* lib = CheckTakeSystemLib(LIBOFFSET(TakeSystemLibrary, FindOverrideCounterPart));
	if (!lib || !lib->FindOverrideCounterPart)
		return nullptr;

	return (BaseOverride*)(((iTakeData*)this)->*(lib->FindOverrideCounterPart))((iBaseOverride*)overrideNode, descID, (iBaseTake*&)resultTake);
}

void TakeData::SendNodeToRepository(BaseList2D* parent, BaseList2D* node)
{
	TakeSystemLibrary* lib = CheckTakeSystemLib(LIBOFFSET(TakeSystemLibrary, SendNodeToRepository));
	if (!lib || !lib->SendNodeToRepository)
		return;

	(((iTakeData*)this)->*(lib->SendNodeToRepository))(parent, node);
}

BaseList2D* TakeData::GetNodeFromRepository(BaseList2D* parent, BaseList2D* node)
{
	TakeSystemLibrary* lib = CheckTakeSystemLib(LIBOFFSET(TakeSystemLibrary, GetNodeFromRepository));
	if (!lib || !lib->GetNodeFromRepository)
		return nullptr;

	return (((iTakeData*)this)->*(lib->GetNodeFromRepository))(parent, node);
}

Bool TakeData::GetUndoState()
{
	TakeSystemLibrary* lib = CheckTakeSystemLib(LIBOFFSET(TakeSystemLibrary, GetUndoState));
	if (!lib || !lib->GetUndoState)
		return false;

	return (((iTakeData*)this)->*(lib->GetUndoState))();
}

void TakeData::SetUndoState(Bool state)
{
	TakeSystemLibrary* lib = CheckTakeSystemLib(LIBOFFSET(TakeSystemLibrary, SetUndoState));
	if (!lib || !lib->SetUndoState)
		return;

	(((iTakeData*)this)->*(lib->SetUndoState))(state);
}

void TakeData::ResetSystem()
{
	TakeSystemLibrary* lib = CheckTakeSystemLib(LIBOFFSET(TakeSystemLibrary, Reset));
	if (!lib || !lib->Reset)
		return;
	(((iTakeData*)this)->*(lib->ResetSystem))();
}

Bool IsTakeRenderRunning()
{
	TakeSystemLibrary* lib = CheckTakeSystemLib(LIBOFFSET(TakeSystemLibrary, IsTakeRenderRunning));
	if (!lib || !lib->IsTakeRenderRunning)
		return false;

	return lib->IsTakeRenderRunning();
}

void StopTakeRender()
{
	TakeSystemLibrary* lib = CheckTakeSystemLib(LIBOFFSET(TakeSystemLibrary, StopTakeRender));
	if (!lib || !lib->StopTakeRender)
		return;

	return lib->StopTakeRender();
}
