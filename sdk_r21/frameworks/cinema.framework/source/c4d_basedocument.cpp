#include "c4d_basedocument.h"
#include "c4d_general.h"
#include "lib_ca.h"

#define BdCall(fnc) (this->*C4DOS.Bd->fnc)

//---------------------- LAYERS --------------------------------------------------------
LayerObject* LayerObject::Alloc(void)
{
	return C4DOS.Bd->DlAlloc();
}

void LayerObject::Free(LayerObject*& bl)
{
	C4DOS.Bl->Free(bl);
	bl = nullptr;
}

//------------------------------------------------------------------------------


RenderData* RenderData::Alloc(void)
{
	return C4DOS.Bd->RdAlloc();
}

void RenderData::Free(RenderData*& bl)
{
	C4DOS.Bl->Free(bl);
	bl = nullptr;
}

BaseVideoPost* RenderData::GetFirstVideoPost()
{
	return C4DOS.Bd->RdGetFirstVideoPost(this);
}

void RenderData::InsertVideoPost(BaseVideoPost* pvp, BaseVideoPost* pred)
{
	C4DOS.Bd->RdInsertVideoPost(this, pvp, pred);
}

void RenderData::InsertVideoPostLast(BaseVideoPost* pvp)
{
	BaseVideoPost* first = C4DOS.Bd->RdGetFirstVideoPost(this);
	if (!first)
	{
		C4DOS.Bd->RdInsertVideoPost(this, pvp, nullptr);
		return;
	}
	((BaseList2D*)pvp)->InsertUnderLast(((BaseList2D*)first)->GetListHead());
}

MultipassObject* RenderData::GetFirstMultipass()
{
	return C4DOS.Bd->RdGetFirstMultipass(this);
}

void RenderData::InsertMultipass(MultipassObject* obj, MultipassObject* pred)
{
	C4DOS.Bd->RdInsertMultipass(this, obj, pred);
}

BaseDocument* BaseDocument::Alloc(void)
{
	return C4DOS.Bd->Alloc();
}

void BaseDocument::Free(BaseDocument*& bl)
{
	C4DOS.Bl->Free(bl);
	bl = nullptr;
}

BaseContainer BaseDocument::GetData(DOCUMENTSETTINGS type)
{
	return C4DOS.Bd->GetData(this, type);
}

BaseContainer* BaseDocument::GetSettingsInstance(Int32 type)
{
	return C4DOS.Bd->GetDataInstance(this, type);
}

NetRenderDocumentContext* BaseDocument::GetNetRenderDocumentContext() const
{
	return BdCall(GetNetRenderDocumentContext) ();
}

void BaseDocument::SetNetRenderDocumentContext(NetRenderDocumentContext* context)
{
	BdCall(SetNetRenderDocumentContext)(context);
}

void BaseDocument::SetData(DOCUMENTSETTINGS type, const BaseContainer& bc)
{
	C4DOS.Bd->SetData(this, type, &bc);
}

BaseObject* BaseDocument::GetFirstObject(void)
{
	return C4DOS.Bd->GetFirstObject(this);
}

BaseMaterial* BaseDocument::GetFirstMaterial(void)
{
	return C4DOS.Bd->GetFirstMaterial(this);
}

RenderData* BaseDocument::GetFirstRenderData(void)
{
	return C4DOS.Bd->GetFirstRenderData(this);
}

void BaseDocument::InsertRenderData(RenderData* rd, RenderData* parent, RenderData* pred)
{
	C4DOS.Bd->InsertRenderData(this, rd, parent, pred);
}

void BaseDocument::InsertRenderDataLast(RenderData* rd)
{
	C4DOS.Bd->InsertRenderDataLast(this, rd);
}

void BaseDocument::InsertMaterial(BaseMaterial* mat, BaseMaterial* pred, Bool checknames)
{
	C4DOS.Bd->InsertMaterial(this, mat, pred, checknames);
}

void BaseDocument::InsertObject(BaseObject* op, BaseObject* parent, BaseObject* pred, Bool checknames)
{
	C4DOS.Bd->InsertObject(this, op, parent, pred, checknames);
}

RenderData* BaseDocument::GetActiveRenderData(void)
{
	return C4DOS.Bd->GetActiveRenderData(this);
}

BaseObject* BaseDocument::GetActiveObject(void)
{
	return C4DOS.Bd->GetActiveObject(this);
}

BaseObject* BaseDocument::GetRealActiveObject(AtomArray* help, Bool* multi)
{
	return C4DOS.Bd->GetRealActiveObject(this, help, multi);
}

BaseObject* BaseDocument::GetHelperAxis(void)
{
	return C4DOS.Bd->GetHelperAxis(this);
}

BaseBitmap* BaseDocument::GetDocPreviewBitmap()
{
	return BdCall(GetDocPreviewBitmap) ();
}

BaseContainer	BaseDocument::GetAllTextures(const AtomArray* ar)
{
	return C4DOS.Bd->GetAllTextures(this, false, ar);
}

BaseContainer	BaseDocument::GetAllTextures(Bool isNet, const AtomArray* ar)
{
	return C4DOS.Bd->GetAllTextures(this, isNet, ar);
}

BaseMaterial* BaseDocument::GetActiveMaterial(void)
{
	return C4DOS.Bd->GetActiveMaterial(this);
}

BaseTag* BaseDocument::GetActiveTag(void)
{
	return C4DOS.Bd->GetActiveTag(this, nullptr);
}

void BaseDocument::SetActiveObject(BaseObject* op, Int32 mode)
{
	BdCall(SetActiveObject) (op, mode);
}

void BaseDocument::SetActiveMaterial(BaseMaterial* mat, Int32 mode)
{
	BdCall(SetActiveMaterial) (mat, mode);
}

void BaseDocument::SetSelection(BaseList2D* bl, Int32 mode)
{
	BdCall(SetSelection) (bl, mode);
}

void BaseDocument::SetActiveTag(BaseTag* tag, Int32 mode)
{
	BdCall(SetActiveTag) (tag, mode);
}

void BaseDocument::GetActiveObjects(AtomArray& selection, GETACTIVEOBJECTFLAGS flags) const
{
	BdCall(GetActiveObjects) (selection, flags);
}

void BaseDocument::GetActivePolygonObjects(AtomArray& selection, Bool children) const
{
	BdCall(GetActivePolygonObjects) (selection, children);
}

void BaseDocument::GetActiveObjectsFilter(AtomArray& selection, Bool children, Int32 type, Int32 instanceof) const
{
	BdCall(GetActiveObjectsFilter) (selection, children, type, instanceof);
}

void BaseDocument::GetActiveTags(AtomArray& selection) const
{
	BdCall(GetActiveTags) (selection);
}

void BaseDocument::GetActiveMaterials(AtomArray& selection) const
{
	BdCall(GetActiveMaterials) (selection);
}

void BaseDocument::GetSelection(AtomArray& selection) const
{
	BdCall(GetSelection) (selection);
}

void BaseDocument::SetActiveRenderData(RenderData* rd)
{
	C4DOS.Bd->SetActiveRenderData(this, rd);
}

void BaseDocument::Flush(void)
{
	C4DOS.Bd->FlushAll(this);
}

BaseObject* BaseDocument::GetHighest(Int32 type, Bool editor)
{
	return C4DOS.Bd->GetHighest(this, type, editor);
}

BaseMaterial* BaseDocument::SearchMaterial(const maxon::String& str)
{
	return C4DOS.Bd->SearchMaterial(this, str);
}

BaseObject* BaseDocument::SearchObject(const maxon::String& str)
{
	return C4DOS.Bd->SearchObject(this, str);
}

Bool BaseDocument::GetChanged(void)
{
	GeData dat;
	if (!this->GetParameter(DescLevel(DOCUMENT_USERCHANGE), dat, DESCFLAGS_GET::NONE))
		return false;
	return dat.GetInt32() != 0;
}

void BaseDocument::SetChanged(void)
{
	this->SetParameter(DescLevel(DOCUMENT_USERCHANGE), true, DESCFLAGS_SET::DONTCHECKMINMAX);
}

void BaseDocument::SetDocumentName(const Filename& fn)
{
	this->SetParameter(DescLevel(DOCUMENT_NAME), fn, DESCFLAGS_SET::DONTCHECKMINMAX);
}

void BaseDocument::SetDocumentPath(const Filename& fn)
{
	this->SetParameter(DescLevel(DOCUMENT_PATH), fn, DESCFLAGS_SET::DONTCHECKMINMAX);
}

Filename BaseDocument::GetDocumentName(void)
{
	GeData dat;
	if (!this->GetParameter(DescLevel(DOCUMENT_NAME), dat, DESCFLAGS_GET::NONE))
		return Filename();
	return dat.GetFilename();
}

Filename BaseDocument::GetDocumentPath(void)
{
	GeData dat;
	if (!this->GetParameter(DescLevel(DOCUMENT_PATH), dat, DESCFLAGS_GET::NONE))
		return Filename();
	return dat.GetFilename();
}

Float BaseDocument::GetLOD(void)
{
	GeData dat;
	if (!this->GetParameter(DescLevel(DOCUMENT_LOD), dat, DESCFLAGS_GET::NONE))
		return 0.0;
	return dat.GetFloat();
}

Int32 BaseDocument::GetFps(void) const
{
	GeData dat;
	if (!((BaseDocument*)this)->GetParameter(DescLevel(DOCUMENT_FPS), dat, DESCFLAGS_GET::NONE))
		return 0;
	return dat.GetInt32();
}

BaseTime BaseDocument::GetMinTime(void)
{
	GeData dat;
	if (!this->GetParameter(DescLevel(DOCUMENT_MINTIME), dat, DESCFLAGS_GET::NONE))
		return BaseTime();
	return dat.GetTime();
}

void BaseDocument::ForceCreateBaseDraw(void)
{
	C4DOS.Bd->ForceCreateBaseDraw(this);
}

BaseTime BaseDocument::GetUsedMinTime(BaseList2D* check_op)
{
	return C4DOS.Bd->GetUsedTime(this, check_op, true);
}

BaseTime BaseDocument::GetUsedMaxTime(BaseList2D* check_op)
{
	return C4DOS.Bd->GetUsedTime(this, check_op, false);
}

BaseTime BaseDocument::GetMaxTime(void)
{
	GeData dat;
	if (!this->GetParameter(DescLevel(DOCUMENT_MAXTIME), dat, DESCFLAGS_GET::NONE))
		return BaseTime();
	return dat.GetTime();
}

BaseTime BaseDocument::GetLoopMinTime(void)
{
	GeData dat;
	if (!this->GetParameter(DescLevel(DOCUMENT_LOOPMINTIME), dat, DESCFLAGS_GET::NONE))
		return BaseTime();
	return dat.GetTime();
}

BaseTime BaseDocument::GetLoopMaxTime(void)
{
	GeData dat;
	if (!this->GetParameter(DescLevel(DOCUMENT_LOOPMAXTIME), dat, DESCFLAGS_GET::NONE))
		return BaseTime();
	return dat.GetTime();
}

Bool BaseDocument::GetRenderLod(void)
{
	GeData dat;
	if (!this->GetParameter(DescLevel(DOCUMENT_RENDERLOD), dat, DESCFLAGS_GET::NONE))
		return 0;
	return dat.GetInt32() != 0;
}

void BaseDocument::SetLOD(Float lod)
{
	this->SetParameter(DescLevel(DOCUMENT_LOD), lod, DESCFLAGS_SET::DONTCHECKMINMAX);
}

void BaseDocument::SetFps(Int32 fps)
{
	this->SetParameter(DescLevel(DOCUMENT_FPS), fps, DESCFLAGS_SET::DONTCHECKMINMAX);
}

void BaseDocument::SetMinTime(const BaseTime& t)
{
	this->SetParameter(DescLevel(DOCUMENT_MINTIME), t, DESCFLAGS_SET::DONTCHECKMINMAX);
}

void BaseDocument::SetMaxTime(const BaseTime& t)
{
	this->SetParameter(DescLevel(DOCUMENT_MAXTIME), t, DESCFLAGS_SET::DONTCHECKMINMAX);
}

void BaseDocument::SetLoopMinTime(const BaseTime& t)
{
	this->SetParameter(DescLevel(DOCUMENT_LOOPMINTIME), t, DESCFLAGS_SET::DONTCHECKMINMAX);
}

void BaseDocument::SetLoopMaxTime(const BaseTime& t)
{
	this->SetParameter(DescLevel(DOCUMENT_LOOPMAXTIME), t, DESCFLAGS_SET::DONTCHECKMINMAX);
}

void BaseDocument::SetRenderLod(Bool lod)
{
	this->SetParameter(DescLevel(DOCUMENT_RENDERLOD), lod, DESCFLAGS_SET::DONTCHECKMINMAX);
}

BaseTime BaseDocument::GetTime(void)
{
	GeData dat;
	if (!this->GetParameter(DescLevel(DOCUMENT_TIME), dat, DESCFLAGS_GET::NONE))
		return BaseTime();
	return dat.GetTime();
}

Int32 BaseDocument::GetMode(void)
{
	GeData dat;
	if (!this->GetParameter(DescLevel(DOCUMENT_MODE), dat, DESCFLAGS_GET::NONE))
		return 0;
	return dat.GetInt32();
}

Int32 BaseDocument::GetAction(void)
{
	GeData dat;
	if (!this->GetParameter(DescLevel(DOCUMENT_ACTION), dat, DESCFLAGS_GET::NONE))
		return 0;
	return dat.GetInt32();
}

Bool BaseDocument::IsEditMode(void)
{
	Int32 mode = GetMode();
	return mode == Mpoints || mode == Mpolygons || mode == Medges;
}

Bool BaseDocument::IsAxisEnabled(void)
{
	return BdCall(IsAxisEnabled) ();
}

void BaseDocument::SetTime(const BaseTime& t)
{
	this->SetParameter(DescLevel(DOCUMENT_TIME), t, DESCFLAGS_SET::DONTCHECKMINMAX);
}

void BaseDocument::SetMode(Int32 m)
{
	this->SetParameter(DescLevel(DOCUMENT_MODE), m, DESCFLAGS_SET::DONTCHECKMINMAX);
}

void BaseDocument::SetAction(Int32 a)
{
	this->SetParameter(DescLevel(DOCUMENT_ACTION), a, DESCFLAGS_SET::DONTCHECKMINMAX | DESCFLAGS_SET::FORCESET);
}

void InsertBaseDocument(BaseDocument* doc)
{
	C4DOS.Ge->InsertBaseDocument(doc);
}

void SetActiveDocument(BaseDocument* doc)
{
	C4DOS.Ge->SetActiveDocument(doc);
}

BaseDocument* GetActiveDocument(void)
{
	return C4DOS.Ge->GetActiveDocument();
}

BaseDocument* GetFirstDocument(void)
{
	return C4DOS.Ge->GetFirstDocument();
}

void KillDocument(BaseDocument*& doc)
{
	C4DOS.Ge->KillDocument(doc);
	doc = nullptr;
}

Bool LoadFile(const Filename& name)
{
	return C4DOS.Ge->LoadFile(&name);
}

BaseDocument* LoadDocument(const Filename& name, SCENEFILTER loadflags, BaseThread* thread, maxon::String* errorString)
{
	BaseDocument* doc = BaseDocument::Alloc();
	if (!doc)
		return nullptr;
	if (!C4DOS.Ge->LoadDocument(doc, name, loadflags, thread, nullptr, errorString))
		blDelete(doc);
	return doc;
}

Bool MergeDocument(BaseDocument* doc, const Filename& name, SCENEFILTER loadflags, BaseThread* thread, maxon::String* errorString)
{
	return C4DOS.Ge->LoadDocument(doc, name, loadflags | SCENEFILTER::MERGESCENE, thread, nullptr, errorString);
}

Bool SaveDocument(BaseDocument* doc, const Filename& name, SAVEDOCUMENTFLAGS saveflags, Int32 format)
{
	return C4DOS.Ge->SaveDocument(doc, name, saveflags, format);
}

RENDERRESULT RenderDocument(BaseDocument* doc, const BaseContainer& rdata, ProgressHook* prog, void* private_data, BaseBitmap* bmp, RENDERFLAGS renderflags, BaseThread* th, WriteProgressHook* wprog, void* data)
{
	return C4DOS.Ge->RenderDocument(doc, wprog, prog, private_data, bmp, &rdata, renderflags, th, data);
}

Bool SaveProject(BaseDocument* doc, SAVEPROJECT flags, Filename targetPath, maxon::BaseArray<AssetEntry>* assets, maxon::BaseArray<AssetEntry>* missingAssets)
{
	return C4DOS.Ge->SaveProject(doc, flags, targetPath, assets, missingAssets);
}

Bool GetAllAssets(BaseDocument* doc, Bool allowDialogs, maxon::BaseArray<AssetEntry>& assets, Filename& lastPath, ASSETDATA_FLAG flags)
{
	return C4DOS.Ge->GetAllAssets(doc, allowDialogs, assets, lastPath, flags, nullptr);
}

Bool BaseDocument::StartUndo(void)
{
	return C4DOS.Bd->StartUndo(this);
}

Bool BaseDocument::EndUndo(void)
{
	return C4DOS.Bd->EndUndo(this);
}

Bool BaseDocument::AddUndo(UNDOTYPE type, void* data, Bool allowFromThread)
{
	return C4DOS.Bd->AddUndo(this, type, data, allowFromThread);
}

Bool BaseDocument::AddUndo(BaseDraw* bd)
{
	return C4DOS.Bd->AddUndoBD(this, bd);
}

Bool BaseDocument::DoUndo(Bool multiple)
{
	return C4DOS.Bd->DoUndo(this, multiple);
}

Bool BaseDocument::DoRedo(void)
{
	return C4DOS.Bd->DoRedo(this);
}


void BaseDocument::AnimateObject(BaseList2D* op, const BaseTime& time, ANIMATEFLAGS flags)
{
	C4DOS.Bd->AnimateObject(this, op, time, flags);
}

BaseDocument* BaseDocument::Polygonize(Bool keepanimation)
{
	BaseDocument* dst = BaseDocument::Alloc();
	if (!dst)
		return nullptr;
	BaseObject*					nx = nullptr, *res = nullptr, *op = nullptr;
	BaseContainer				ctr;
	ModelingCommandData cd;
	cd.doc = dst;
	cd.bc	 = &ctr;
	ctr.SetBool(MDATA_CURRENTSTATETOOBJECT_KEEPANIMATION, keepanimation);

	if (!CopyTo(dst, COPYFLAGS::NONE, nullptr))
		goto error;

	for (op = dst->GetFirstObject(); op; op = nx)
	{
		nx = op->GetNext();

		cd.op = op;
		if (!SendModelingCommand(MCOMMAND_CURRENTSTATETOOBJECT, cd))
			goto error;
		if (!cd.result)
			goto error;
		res = (BaseObject*)cd.result->GetIndex(0);

		if (!res)
			goto error;

		res->InsertBefore(op);
		AtomArray::Free(cd.result);
		blDelete(op);
	}

	return dst;

error:
	blDelete(dst);
	AtomArray::Free(cd.result);
	return nullptr;
}

BaseDraw* BaseDocument::GetActiveBaseDraw(void)
{
	return C4DOS.Bd->GetActiveBaseDraw(this);
}

BaseDraw* BaseDocument::GetRenderBaseDraw(void)
{
	return C4DOS.Bd->GetRenderBaseDraw(this);
}

BaseDraw* BaseDocument::GetBaseDraw(Int32 num)
{
	return C4DOS.Bd->GetBaseDraw(this, num);
}

Int32 BaseDocument::GetBaseDrawCount()
{
	return C4DOS.Bd->GetBaseDrawCount(this);
}

Int32 BaseDocument::GetSplinePlane(void)
{
	return C4DOS.Bd->GetSplinePlane(this);
}

void BaseDocument::SetRewind(Int32 flags)
{
	C4DOS.Bd->SetRewind(this, flags);
}

TakeData* BaseDocument::GetTakeData()
{
	return BdCall(GetTakeData) ();
}

static void* HAlloc(void* main) { return ((Hierarchy*)main)->Alloc(); }
static void HFree(void* main, void* data) { ((Hierarchy*)main)->Free(data); }
static void HCopyTo(void* main, void* src, void* dst) { ((Hierarchy*)main)->CopyTo(src, dst); }
static Bool HDo(void* main, void* data, BaseObject* op, const Matrix& mg, Bool controlobject) { return ((Hierarchy*)main)->Do(data, op, mg, controlobject); }

Bool Hierarchy::Run(BaseDocument* t_doc, Bool spheres, Float lod, Bool uselod, BUILDFLAGS flags, void* startdata, BaseThread* t_bt)
{
	doc = t_doc;
	bt	= t_bt;
	return C4DOS.Bd->RunHierarchy(this, doc, spheres, lod, uselod, flags, startdata, bt, HAlloc, HFree, HCopyTo, HDo);
}

GeListHead* BaseDocument::GetLayerObjectRoot(void)
{
	return C4DOS.Bd->GetLayerObjectRoot(this);
}

Bool BaseDocument::CollectSounds(BaseSound* snd, const BaseTime& from, const BaseTime& to)
{
	return C4DOS.Bd->CollectSounds(this, snd, from, to);
}

Bool BaseDocument::ExecutePasses(BaseThread* bt, Bool animation, Bool expressions, Bool caches, BUILDFLAGS flags)
{
	return BdCall(ExecutePasses) (bt, animation, expressions, caches, flags);
}

const PickSessionDataStruct* BaseDocument::GetPickSession() const
{
	return BdCall(GetPickSession) ();
}

void BaseDocument::StartPickSession(PickSessionDataStruct* psd)
{
	BdCall(StartPickSession) (psd);
}

void BaseDocument::StopPickSession(Bool cancel)
{
	BdCall(StopPickSession) (cancel);
}

Bool BaseDocument::GetDefaultKey(CKey* pKey, Bool& bOverdub) const
{
	return BdCall(GetDefaultKey) (pKey, bOverdub);
}

void BaseDocument::SetDefaultKey(CKey* pKey, Bool bOverdub)
{
	BdCall(SetDefaultKey) (pKey, bOverdub);
}


Bool BaseDocument::HandleSelectedTextureFilename(BaseChannel* bc, const Filename& fn, Filename* resfilename, Bool undo, GEMB_R* already_answered)
{
	return C4DOS.Bd->HandleSelectedTextureFilename(this, bc, fn, resfilename, undo, already_answered);
}

Bool BaseDocument::ReceiveMaterials(BaseObject* op, AtomArray* mat, Bool clearfirst)
{
	return C4DOS.Bd->ReceiveMaterials(this, op, mat, clearfirst);
}

Bool BaseDocument::ReceiveNewTexture(BaseObject* op, const Filename& filename, Bool sdown, GEMB_R* already_answered)
{
	return C4DOS.Bd->ReceiveNewTexture(this, op, filename, sdown, already_answered);
}

#define ID_MODELING_INTERACTIVEMODELINGUNDO_RESTART_COMMAND	200000060
#define ID_MODELING_INTERACTIVEMODELINGUNDO_COMMAND					200000061

Bool InteractiveModeling_Rewind(BaseDocument* doc)
{
	ModelingCommandData	 mu;
	AutoAlloc<AtomArray> active;
	if (!doc || !active)
		return true;
	doc->GetActiveObjects(*active, GETACTIVEOBJECTFLAGS::CHILDREN);
	mu.arr = active;
	mu.doc = doc;
	return SendModelingCommand(ID_MODELING_INTERACTIVEMODELINGUNDO_COMMAND, mu);
}

Bool InteractiveModeling_Restart(BaseDocument* doc)
{
	ModelingCommandData	 mu;
	AutoAlloc<AtomArray> active;
	if (!doc || !active)
		return true;
	doc->GetActiveObjects(*active, GETACTIVEOBJECTFLAGS::CHILDREN);
	mu.arr = active;
	mu.doc = doc;
	return SendModelingCommand(ID_MODELING_INTERACTIVEMODELINGUNDO_RESTART_COMMAND, mu);
}

void RunAnimation(BaseDocument* doc, Bool forward, Bool stop)
{
	C4DOS.Bd->RunAnimation(doc, forward, stop);
}

void SetDocumentTime(BaseDocument* doc, const BaseTime& time)
{
	C4DOS.Bd->SetDocumentTime(doc, time);
}

BaseDocument* IsolateObjects(BaseDocument* doc, const AtomArray& t_objects)
{
	return C4DOS.Bd->IsolateObjects(doc, t_objects);
}

Bool CloseAllDocuments()
{
	return C4DOS.Bd->CloseAllDocuments();
}

Bool StopExternalRenderer()
{
	return C4DOS.Bd->StopExternalRenderer();
}

void BaseDocument::SetHighlightedObject(BaseObject* op, Int32 mode/*= SELECTION_NEW*/)
{
	BdCall(SetHighlightedObject) (op, mode);
}

void BaseDocument::SetHighlightedObjects(AtomArray& selection, Int32 mode/*= SELECTION_NEW*/)
{
	BdCall(SetHighlightedObjects) (selection, mode);
}

void BaseDocument::GetHighlightedObjects(AtomArray& selection) const
{
	BdCall(GetHighlightedObjects) (selection);
}
void BaseDocument::SetTargetObject(BaseObject* op)
{
	BdCall(SetTargetObject) (op);
}

BaseObject* BaseDocument::GetTargetObject() const
{
	return BdCall(GetTargetObject) ();
}

maxon::Result<const maxon::UpdatableAssetRepositoryRef&> BaseDocument::GetSceneRepository(Bool create)
{
	return BdCall(GetSceneRepository)(create);
}
void BaseDocument::SetTemporaryManipulatorObject(BaseObject* temp)
{
	BdCall(SetTemporaryManipulatorObject) (temp);
}

BaseObject* BaseDocument::GetTemporaryManipulatorObject() const
{
	return BdCall(GetTemporaryManipulatorObject) ();
}

