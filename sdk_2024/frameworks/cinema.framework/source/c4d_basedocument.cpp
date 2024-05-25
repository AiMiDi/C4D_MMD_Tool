#include "c4d_basedocument.h"
#include "c4d_general.h"
#include "c4d_videopost.h"
#include "lib_ca.h"

#ifdef CINEWARE_NAMESPACE_ENABLE
	CINEWARE_NAMESPACE_BEGIN
#endif

//---------------------- LAYERS --------------------------------------------------------
LayerObject* LayerObject::Alloc()
{
	return C4DOS_Bd->DlAlloc();
}

void LayerObject::Free(LayerObject*& bl)
{
	C4DOS_Bl->Free(bl);
	bl = nullptr;
}

//------------------------------------------------------------------------------


RenderData* RenderData::Alloc()
{
	return C4DOS_Bd->RdAlloc();
}

void RenderData::Free(RenderData*& bl)
{
	C4DOS_Bl->Free(bl);
	bl = nullptr;
}

BaseVideoPost* RenderData::GetFirstVideoPost()
{
	return C4DOS_Bd->RdGetFirstVideoPost(this);
}

void RenderData::InsertVideoPost(BaseVideoPost* pvp, BaseVideoPost* pred)
{
	C4DOS_Bd->RdInsertVideoPost(this, pvp, pred);
}

void RenderData::InsertVideoPostLast(BaseVideoPost* pvp)
{
	BaseVideoPost* first = C4DOS_Bd->RdGetFirstVideoPost(this);
	if (!first)
	{
		C4DOS_Bd->RdInsertVideoPost(this, pvp, nullptr);
		return;
	}
	pvp->InsertUnderLast(first->GetListHead());
}

MultipassObject* RenderData::GetFirstMultipass()
{
	return C4DOS_Bd->RdGetFirstMultipass(this);
}

void RenderData::InsertMultipass(MultipassObject* obj, MultipassObject* pred)
{
	C4DOS_Bd->RdInsertMultipass(this, obj, pred);
}

BaseDocument* BaseDocument::Alloc()
{
	return C4DOS_Bd->Alloc();
}

void BaseDocument::Free(BaseDocument*& bl)
{
	C4DOS_Bl->Free(bl);
	bl = nullptr;
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
	C4DOS_Bd->SetData(this, type, &bc);
}

BaseObject* BaseDocument::GetFirstObject() const
{
	return C4DOS_Bd->GetFirstObject(this);
}

BaseMaterial* BaseDocument::GetFirstMaterial() const
{
	return C4DOS_Bd->GetFirstMaterial(this);
}

RenderData* BaseDocument::GetFirstRenderData() const
{
	return C4DOS_Bd->GetFirstRenderData(this);
}

BaseSceneHook* BaseDocument::GetFirstSceneHook() const
{
	return C4DOS_Bd->GetFirstSceneHook(this);
}

void BaseDocument::InsertRenderData(RenderData* rd, RenderData* parent, RenderData* pred)
{
	C4DOS_Bd->InsertRenderData(this, rd, parent, pred);
}

void BaseDocument::InsertRenderDataLast(RenderData* rd)
{
	C4DOS_Bd->InsertRenderDataLast(this, rd);
}

void BaseDocument::InsertMaterial(BaseMaterial* mat, BaseMaterial* pred, Bool checknames)
{
	C4DOS_Bd->InsertMaterial(this, mat, pred, checknames);
}

void BaseDocument::InsertObject(BaseObject* op, BaseObject* parent, BaseObject* pred, Bool checknames, Bool sendNotification)
{
	C4DOS_Bd->InsertObject(this, op, parent, pred, checknames, sendNotification);
}

RenderData* BaseDocument::GetActiveRenderData()
{
	return C4DOS_Bd->GetActiveRenderData(this);
}

BaseObject* BaseDocument::GetRealActiveObject(AtomArray* help, Bool* multi)
{
	return C4DOS_Bd->GetRealActiveObject(this, help, multi);
}

BaseObject* BaseDocument::GetHelperAxis()
{
	return C4DOS_Bd->GetHelperAxis(this);
}

BaseBitmap* BaseDocument::GetDocPreviewBitmap()
{
	return BdCall(GetDocPreviewBitmap) ();
}

BaseContainer	BaseDocument::GetAllTextures(const AtomArray* ar)
{
	return C4DOS_Bd->GetAllTextures(this, false, ar);
}

BaseContainer	BaseDocument::GetAllTextures(Bool isNet, const AtomArray* ar)
{
	return C4DOS_Bd->GetAllTextures(this, isNet, ar);
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
	C4DOS_Bd->SetActiveRenderData(this, rd);
}

void BaseDocument::Flush()
{
	C4DOS_Bd->FlushAll(this);
}

BaseObject* BaseDocument::GetHighest(Int32 type, Bool editor)
{
	return C4DOS_Bd->GetHighest(this, type, editor);
}

BaseMaterial* BaseDocument::SearchMaterial(const maxon::String& str)
{
	return C4DOS_Bd->SearchMaterial(this, str);
}

BaseObject* BaseDocument::SearchObject(const maxon::String& str)
{
	return C4DOS_Bd->SearchObject(this, str);
}

Bool BaseDocument::GetChanged()
{
	GeData dat;
	if (!this->GetParameter(ConstDescID(DescLevel(DOCUMENT_USERCHANGE)), dat, DESCFLAGS_GET::NONE))
		return false;
	return dat.GetInt32() != 0;
}

void BaseDocument::SetChanged()
{
	this->SetParameter(ConstDescID(DescLevel(DOCUMENT_USERCHANGE)), true, DESCFLAGS_SET::DONTCHECKMINMAX);
}

void BaseDocument::SetDocumentName(const Filename& fn)
{
	this->SetParameter(ConstDescID(DescLevel(DOCUMENT_NAME)), fn, DESCFLAGS_SET::DONTCHECKMINMAX);
}

void BaseDocument::SetDocumentPath(const Filename& fn)
{
	this->SetParameter(ConstDescID(DescLevel(DOCUMENT_PATH)), fn, DESCFLAGS_SET::DONTCHECKMINMAX);
}

Filename BaseDocument::GetDocumentName() const
{
	GeData dat;
	if (!this->GetParameter(ConstDescID(DescLevel(DOCUMENT_NAME)), dat, DESCFLAGS_GET::NONE))
		return Filename();
	return dat.GetFilename();
}

Filename BaseDocument::GetDocumentPath() const
{
	GeData dat;
	if (!this->GetParameter(ConstDescID(DescLevel(DOCUMENT_PATH)), dat, DESCFLAGS_GET::NONE))
		return Filename();
	return dat.GetFilename();
}

Float BaseDocument::GetLOD() const
{
	GeData dat;
	if (!this->GetParameter(ConstDescID(DescLevel(DOCUMENT_LOD)), dat, DESCFLAGS_GET::NONE))
		return 0.0;
	return dat.GetFloat();
}

Int32 BaseDocument::GetFps() const
{
	GeData dat;
	if (!GetParameter(ConstDescID(DescLevel(DOCUMENT_FPS)), dat, DESCFLAGS_GET::NONE))
		return 0;
	return dat.GetInt32();
}

BaseTime BaseDocument::GetMinTime() const
{
	GeData dat;
	if (!this->GetParameter(ConstDescID(DescLevel(DOCUMENT_MINTIME)), dat, DESCFLAGS_GET::NONE))
		return BaseTime();
	return dat.GetTime();
}

void BaseDocument::ForceCreateBaseDraw()
{
	C4DOS_Bd->ForceCreateBaseDraw(this);
}

BaseTime BaseDocument::GetUsedMinTime(BaseList2D* check_op)
{
	return C4DOS_Bd->GetUsedTime(this, check_op, true);
}

BaseTime BaseDocument::GetUsedMaxTime(BaseList2D* check_op)
{
	return C4DOS_Bd->GetUsedTime(this, check_op, false);
}

BaseTime BaseDocument::GetMaxTime() const
{
	GeData dat;
	if (!this->GetParameter(ConstDescID(DescLevel(DOCUMENT_MAXTIME)), dat, DESCFLAGS_GET::NONE))
		return BaseTime();
	return dat.GetTime();
}

BaseTime BaseDocument::GetLoopMinTime() const
{
	GeData dat;
	if (!this->GetParameter(ConstDescID(DescLevel(DOCUMENT_LOOPMINTIME)), dat, DESCFLAGS_GET::NONE))
		return BaseTime();
	return dat.GetTime();
}

BaseTime BaseDocument::GetLoopMaxTime() const
{
	GeData dat;
	if (!this->GetParameter(ConstDescID(DescLevel(DOCUMENT_LOOPMAXTIME)), dat, DESCFLAGS_GET::NONE))
		return BaseTime();
	return dat.GetTime();
}

Bool BaseDocument::GetRenderLod() const
{
	GeData dat;
	if (!this->GetParameter(ConstDescID(DescLevel(DOCUMENT_RENDERLOD)), dat, DESCFLAGS_GET::NONE))
		return 0;
	return dat.GetInt32() != 0;
}

void BaseDocument::SetLOD(Float lod)
{
	this->SetParameter(ConstDescID(DescLevel(DOCUMENT_LOD)), lod, DESCFLAGS_SET::DONTCHECKMINMAX);
}

void BaseDocument::SetFps(Int32 fps)
{
	this->SetParameter(ConstDescID(DescLevel(DOCUMENT_FPS)), fps, DESCFLAGS_SET::DONTCHECKMINMAX);
}

void BaseDocument::SetMinTime(const BaseTime& t)
{
	this->SetParameter(ConstDescID(DescLevel(DOCUMENT_MINTIME)), t, DESCFLAGS_SET::DONTCHECKMINMAX);
}

void BaseDocument::SetMaxTime(const BaseTime& t)
{
	this->SetParameter(ConstDescID(DescLevel(DOCUMENT_MAXTIME)), t, DESCFLAGS_SET::DONTCHECKMINMAX);
}

void BaseDocument::SetLoopMinTime(const BaseTime& t)
{
	this->SetParameter(ConstDescID(DescLevel(DOCUMENT_LOOPMINTIME)), t, DESCFLAGS_SET::DONTCHECKMINMAX);
}

void BaseDocument::SetLoopMaxTime(const BaseTime& t)
{
	this->SetParameter(ConstDescID(DescLevel(DOCUMENT_LOOPMAXTIME)), t, DESCFLAGS_SET::DONTCHECKMINMAX);
}

void BaseDocument::SetRenderLod(Bool lod)
{
	this->SetParameter(ConstDescID(DescLevel(DOCUMENT_RENDERLOD)), lod, DESCFLAGS_SET::DONTCHECKMINMAX);
}

Int32 BaseDocument::GetMode() const
{
	GeData dat;
	if (!const_cast<BaseDocument*>(this)->GetParameter(ConstDescID(DescLevel(DOCUMENT_MODE)), dat, DESCFLAGS_GET::NONE))
		return 0;
	return dat.GetInt32();
}

void BaseDocument::SetMode(Int32 mode, const maxon::Id& group)
{
	BdCall(SetMode)(mode, group);
}

Int32 BaseDocument::GetAction() const
{
	GeData dat;
	if (!const_cast<BaseDocument*>(this)->GetParameter(ConstDescID(DescLevel(DOCUMENT_ACTION)), dat, DESCFLAGS_GET::NONE))
		return 0;
	return dat.GetInt32();
}

Bool BaseDocument::IsEditMode() const
{
	Int32 mode = GetMode();
	return mode == Mpoints || mode == Mpolygons || mode == Medges;
}

Bool BaseDocument::IsAxisEnabled() const
{
	return BdCall(IsAxisEnabled) ();
}

void BaseDocument::SetTime(const BaseTime& t)
{
	this->SetParameter(ConstDescID(DescLevel(DOCUMENT_TIME)), t, DESCFLAGS_SET::DONTCHECKMINMAX);
}

void BaseDocument::SetMode(Int32 m)
{
	this->SetParameter(ConstDescID(DescLevel(DOCUMENT_MODE)), m, DESCFLAGS_SET::DONTCHECKMINMAX);
}

void BaseDocument::SetAction(Int32 a)
{
	this->SetParameter(ConstDescID(DescLevel(DOCUMENT_ACTION)), a, DESCFLAGS_SET::DONTCHECKMINMAX | DESCFLAGS_SET::FORCESET);
}

void InsertBaseDocument(BaseDocument* doc)
{
	C4DOS_Ge->InsertBaseDocument(doc);
}

void SetActiveDocument(BaseDocument* doc)
{
	C4DOS_Ge->SetActiveDocument(doc);
}

BaseDocument* GetActiveDocument()
{
	return C4DOS_Ge->GetActiveDocument();
}

BaseDocument* GetFirstDocument()
{
	return C4DOS_Ge->GetFirstDocument();
}

void KillDocument(BaseDocument*& doc)
{
	C4DOS_Ge->KillDocument(doc);
	doc = nullptr;
}

Bool LoadFile(const Filename& name, Bool allowAsync)
{
	return C4DOS_Ge->LoadFile(&name, allowAsync);
}

BaseDocument* LoadDocument(const Filename& name, SCENEFILTER loadflags, BaseThread* thread, maxon::String* errorString, const ProgressDelegate& progressDelegate)
{
	BaseDocument* doc = BaseDocument::Alloc();
	if (!doc)
		return nullptr;

	maxon::Url url = MaxonConvert(name, MAXONCONVERTMODE::NONE);

	if (progressDelegate.IsPopulated())
	{
		url.SetData(maxon::ConstDataPtr(maxon::Id("progress")), maxon::Data(progressDelegate)) iferr_ignore();
	}

	if (!C4DOS_Ge->LoadDocument(doc, MaxonConvert(url), loadflags, thread, nullptr, errorString))
		blDelete(doc);
	return doc;
}

Bool MergeDocument(BaseDocument* doc, const Filename& name, SCENEFILTER loadflags, BaseThread* thread, maxon::String* errorString, const ProgressDelegate& progressDelegate)
{
	maxon::Url url = MaxonConvert(name, MAXONCONVERTMODE::NONE);

	if (progressDelegate.IsPopulated())
	{
		url.SetData(maxon::ConstDataPtr(maxon::Id("progress")), maxon::Data(progressDelegate)) iferr_ignore();
	}

	return C4DOS_Ge->LoadDocument(doc, MaxonConvert(url), loadflags | SCENEFILTER::MERGESCENE, thread, nullptr, errorString);
}

Bool SaveDocument(BaseDocument* doc, const Filename& name, SAVEDOCUMENTFLAGS saveflags, Int32 format)
{
	return C4DOS_Ge->SaveDocument(doc, name, saveflags, format);
}

RENDERRESULT RenderDocument(BaseDocument* doc, const BaseContainer& rdata, ProgressHook* prog, void* private_data, BaseBitmap* bmp, RENDERFLAGS renderflags, BaseThread* th, WriteProgressHook* wprog, void* data)
{
	return C4DOS_Ge->RenderDocument(doc, wprog, prog, private_data, bmp, &rdata, renderflags, th, data);
}

Bool SaveProject(BaseDocument* doc, SAVEPROJECT flags, Filename targetPath, maxon::BaseArray<AssetEntry>* assets, maxon::BaseArray<AssetEntry>* missingAssets)
{
	return C4DOS_Ge->SaveProject(doc, flags, targetPath, assets, missingAssets);
}

GETALLASSETSRESULT GetAllAssets(BaseDocument* doc, Bool allowDialogs, maxon::BaseArray<AssetEntry>& assets, Filename& lastPath, ASSETDATA_FLAG flags)
{
	return C4DOS_Ge->GetAllAssets(doc, allowDialogs, assets, lastPath, flags, nullptr);
}

Bool BaseDocument::StartUndo()
{
	return C4DOS_Bd->StartUndo(this);
}

Bool BaseDocument::EndUndo()
{
	return C4DOS_Bd->EndUndo(this);
}

Bool BaseDocument::AddUndo(UNDOTYPE type, void* data, Bool allowFromThread)
{
	return C4DOS_Bd->AddUndo(this, type, data, allowFromThread);
}

Bool BaseDocument::AddUndo(BaseDraw* bd)
{
	return C4DOS_Bd->AddUndoBD(this, bd);
}

Bool BaseDocument::DoUndo(Bool multiple)
{
	return C4DOS_Bd->DoUndo(this, multiple);
}

Bool BaseDocument::DoRedo()
{
	return C4DOS_Bd->DoRedo(this);
}


void BaseDocument::AnimateObject(BaseList2D* op, const BaseTime& time, ANIMATEFLAGS flags)
{
	C4DOS_Bd->AnimateObject(this, op, time, flags);
}

BaseDocument* BaseDocument::Polygonize(Bool keepanimation)
{
	BaseDocument* dst = BaseDocument::Alloc();
	if (!dst)
		return nullptr;

	BaseContainer	ctr;
	ModelingCommandData cd;

	cd.doc = dst;
	cd.bc = &ctr;
	ctr.SetBool(MDATA_CURRENTSTATETOOBJECT_KEEPANIMATION, keepanimation);

	auto fin = finally_opt
	{
		blDelete(dst);
		AtomArray::Free(cd.result);
	};

	if (!CopyTo(dst, COPYFLAGS::NONE, nullptr))
		return nullptr;

	BaseObject* nx = nullptr;

	// first pass generates all objects
	ctr.SetBool(MDATA_CURRENTSTATETOOBJECT_NOGENERATE, true);
	for (BaseObject* op = dst->GetFirstObject(); op; op = nx)
	{
		nx = op->GetNext();

		cd.op = op;
		if (!SendModelingCommand(MCOMMAND_CURRENTSTATETOOBJECT, cd))
			return nullptr;

		AtomArray::Free(cd.result);
	}

	maxon::BaseArray<BaseObject*> toAdd;

	// second pass clones all objects
	ctr.SetBool(MDATA_CURRENTSTATETOOBJECT_NOGENERATE, false);
	for (BaseObject* op = dst->GetFirstObject(); op; op = nx)
	{
		nx = op->GetNext();

		cd.op = op;

		if (!SendModelingCommand(MCOMMAND_CURRENTSTATETOOBJECT, cd))
			return nullptr;

		if (!cd.result)
			return nullptr;
		BaseObject* res = (BaseObject*)cd.result->GetIndex(0);

		if (!res)
			return nullptr;

		iferr (toAdd.Append(res))
			return nullptr;

		AtomArray::Free(cd.result);
	}

	// third pass deletes all objects
	for (BaseObject* op = dst->GetFirstObject(); op; op = nx)
	{
		nx = op->GetNext();
		blDelete(op);
	}

	// lastly add the new objects
	BaseObject* prev = nullptr;
	for (BaseObject* newObject : toAdd)
	{
		dst->InsertObject(newObject, nullptr, prev);
		prev = newObject;
	}

	fin.Disable();

	return dst;
}

BaseDraw* BaseDocument::GetActiveBaseDraw() const
{
	return C4DOS_Bd->GetActiveBaseDraw(this);
}

BaseDraw* BaseDocument::GetRenderBaseDraw() const
{
	return C4DOS_Bd->GetRenderBaseDraw(this);
}

BaseDraw* BaseDocument::GetBaseDraw(Int32 num) const
{
	return C4DOS_Bd->GetBaseDraw(this, num);
}

Int32 BaseDocument::GetBaseDrawCount() const
{
	return C4DOS_Bd->GetBaseDrawCount(this);
}

Int32 BaseDocument::GetSplinePlane()
{
	return C4DOS_Bd->GetSplinePlane(this);
}

void BaseDocument::SetRewind(Int32 flags)
{
	C4DOS_Bd->SetRewind(this, flags);
}

TakeData* BaseDocument::GetTakeData() const
{
	return BdCall(GetTakeData) ();
}

static void* HAlloc(void* main) { return static_cast<Hierarchy*>(main)->Alloc(); }
static void HFree(void* main, void* data) { static_cast<Hierarchy*>(main)->Free(data); }
static void HCopyTo(void* main, void* src, void* dst) { static_cast<Hierarchy*>(main)->CopyTo(src, dst); }
static Bool HDo(void* main, void* data, BaseObject* op, const Matrix& mg, Bool controlobject) { return static_cast<Hierarchy*>(main)->Do(data, op, mg, controlobject); }

Bool Hierarchy::Run(BaseDocument* t_doc, Bool spheres, Float lod, Bool uselod, BUILDFLAGS flags, void* startdata, BaseThread* t_bt)
{
	doc = t_doc;
	bt	= t_bt;
	return C4DOS_Bd->RunHierarchy(this, doc, spheres, lod, uselod, flags, startdata, bt, HAlloc, HFree, HCopyTo, HDo);
}

GeListHead* BaseDocument::GetLayerObjectRoot()
{
	return C4DOS_Bd->GetLayerObjectRoot(this);
}

Bool BaseDocument::CollectSounds(BaseSound* snd, const BaseTime& from, const BaseTime& to)
{
	return C4DOS_Bd->CollectSounds(this, snd, from, to);
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

void BaseDocument::SetTrackDefaultInterpolationMode(CURVEINTERPOLATION_MODE mode)
{
	BdCall(SetTrackDefaultInterpolationMode)(mode);
}

CURVEINTERPOLATION_MODE BaseDocument::GetTrackDefaultInterpolationMode() const
{
	return BdCall(GetTrackDefaultInterpolationMode)();
}


Bool BaseDocument::HandleSelectedTextureFilename(BaseChannel* bc, const Filename& fn, Filename* resfilename, Bool undo, GEMB_R* already_answered)
{
	return C4DOS_Bd->HandleSelectedTextureFilename(this, bc, fn, resfilename, undo, already_answered);
}

Bool BaseDocument::ReceiveMaterials(BaseObject* op, AtomArray* mat, Bool clearfirst)
{
	return C4DOS_Bd->ReceiveMaterials(this, op, mat, clearfirst);
}

Bool BaseDocument::ReceiveNewTexture(BaseObject* op, const Filename& filename, Bool sdown, GEMB_R* already_answered)
{
	return C4DOS_Bd->ReceiveNewTexture(this, op, filename, sdown, already_answered);
}

#define ID_MODELING_INTERACTIVEMODELINGUNDO_RESTART_COMMAND	200000060
#define ID_MODELING_INTERACTIVEMODELINGUNDO_COMMAND					200000061

Bool InteractiveModeling_Rewind(BaseDocument* doc)
{
	StopDrawViewsThread();
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
	StopDrawViewsThread();
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
	C4DOS_Bd->RunAnimation(doc, forward, stop);
}

void SetDocumentTime(BaseDocument* doc, const BaseTime& time)
{
	C4DOS_Bd->SetDocumentTime(doc, time);
}

BaseDocument* IsolateObjects(BaseDocument* doc, const AtomArray& t_objects)
{
	return C4DOS_Bd->IsolateObjects(doc, t_objects);
}

Bool CloseAllDocuments()
{
	return C4DOS_Bd->CloseAllDocuments();
}

Bool StopExternalRenderer()
{
	return C4DOS_Bd->StopExternalRenderer();
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

Filename BaseDocument::GetOcioConfigPath(Bool fullPath) const
{
	return BdCall(GetOcioConfigPath)(fullPath);
}

const maxon::OcioConfig& BaseDocument::GetOcioConfig() const
{
	return BdCall(GetOcioConfig)();
}

void BaseDocument::GetOcioProfiles(maxon::ColorProfile& renderingColorSpace, maxon::ColorProfile& displayColorSpace, maxon::ColorProfile& viewTransform, maxon::ColorProfile& viewTransformThumbnails) const
{
	return BdCall(GetOcioProfiles)(renderingColorSpace, displayColorSpace, viewTransform, viewTransformThumbnails);
}

void BaseDocument::GetOcioConfigAndProfiles(maxon::OcioConfig& ocioConfig, maxon::ColorProfile& renderingColorSpace, maxon::ColorProfile& displayColorSpace, 
	maxon::ColorProfile& viewTransform, maxon::ColorProfile& viewTransformThumbnails) const
{
	return BdCall(GetOcioConfigAndProfiles)(ocioConfig, renderingColorSpace, displayColorSpace, viewTransform, viewTransformThumbnails);
}

void BaseDocument::GetActiveOcioColorSpacesNames(maxon::CString& renderingColorSpace, maxon::CString& displayColorSpace, maxon::CString& viewTransform, 
	maxon::CString& viewTransformThumbnails) const
{
	return BdCall(GetActiveOcioColorSpacesNames)(renderingColorSpace, displayColorSpace, viewTransform, viewTransformThumbnails);
}

const maxon::BaseArray<maxon::CString>& BaseDocument::GetOcioColorSpaceNames()
{
	return BdCall(GetOcioColorSpaceNames)();
}

const maxon::BaseArray<maxon::CString>& BaseDocument::GetOcioRenderingColorSpaceNames()
{
	return BdCall(GetOcioRenderingColorSpaceNames)();
}

const BaseContainer& BaseDocument::GetOcioColorSpacesPopupMenu() const
{
	return BdCall(GetOcioColorSpacesPopupMenu)();
}

const maxon::BaseArray<maxon::CString>& BaseDocument::GetOcioDisplayColorSpaceNames()
{
	return BdCall(GetOcioDisplayColorSpaceNames)();
}

const maxon::BaseArray<maxon::CString>& BaseDocument::GetOcioViewTransformNames()
{
	return BdCall(GetOcioViewTransformNames)();
}

maxon::CString BaseDocument::GetNameFromColorSpaceId(Int32 category, Int32 index) const
{
	return BdCall(GetNameFromColorSpaceId)(category, index);
}

Int32 BaseDocument::GetColorSpaceIdFromName(Int32 category, const maxon::CString& name) const
{
	return BdCall(GetColorSpaceIdFromName)(category, name);
}

void BaseDocument::CopyLinearWorkflow(const BaseDocument *src, BaseDocument *dst, Bool isMaterialPreview)
{
	return C4DOS_Bd->CopyLinearWorkflow(src, dst, isMaterialPreview);
}

void BaseDocument::UpdateOcioColorSpaces()
{
	BdCall(UpdateOcioColorSpaces)();
}

const OcioConverterRef& BaseDocument::GetColorConverter() const
{
	return BdCall(GetColorConverter)();
}

const OcioConverterRef& BaseDocument::GetBasicColorConverter()
{
	const OcioConverterRef& converter = C4DOS_Bd->GetBasicColorConverter();
	return converter;
}

const OcioConverterRef& BaseDocument::GetColorConverterForActiveDocument()
{
	const OcioConverterRef& converter = C4DOS_Bd->GetColorConverterForActiveDocument();
	return converter;
}

maxon::Result<void> BaseDocument::PrivateSetBaseRepository(const maxon::UpdatableAssetRepositoryRef& baseRepo)
{
	iferr_scope;

	#define ID_ADDSCENEREPOSITORYBASE 1058913
	SetParameter(ConstDescID(DescLevel(ID_ADDSCENEREPOSITORYBASE)), GeData((void*)&baseRepo, VOIDVALUETYPE::VOIDVALUE), DESCFLAGS_SET::DONTCHECKMINMAX | DESCFLAGS_SET::FORCESET);

	return maxon::OK;
}

Bool BaseSceneHook::DisplayControl(BaseDocument *doc, BaseObject *op, BaseObject *chainstart, BaseDraw *bd, BaseDrawHelp *bh, ControlDisplayStruct &cds) const
{
	return AtCall(DisplayControl)(doc, op, chainstart, bd, bh, cds);
}

Bool BaseSceneHook::InitDisplayControl(BaseDocument* doc, BaseDraw* bd, const AtomArray* active)
{
	return AtCall(InitDisplayControl)(doc, bd, active);
}

void BaseSceneHook::FreeDisplayControl()
{
	AtCall(FreeDisplayControl)();
}

void BaseSceneHook::Draw(BaseDocument* doc, BaseDraw* bd, BaseDrawHelp* bh, BaseThread* bt, SCENEHOOKDRAW flags)
{
	AtCall(Draw)(doc, bd, bh, bt, flags);
}

maxon::DocumentModeControllerRef& BaseDocument::GetModeController()
{
	return BdCall(GetModeController) ();
}

#ifdef CINEWARE_NAMESPACE_ENABLE
	CINEWARE_NAMESPACE_END
#endif
