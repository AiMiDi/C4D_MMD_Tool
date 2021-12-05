#ifdef __API_INTERN__
	#error "Not in kernel"
#endif

#include "lib_sculpt.h"
#include "c4d_basedocument.h"
#include "c4d_general.h"

SculptLibrary *lib_sculpt = nullptr;

static SculptLibrary *CheckSculptLib(Int32 offset)
{
	return (SculptLibrary*)CheckLib(LIBRARY_SCULPT, offset, (C4DLibrary**)&lib_sculpt);
}

#define SculptLibCall(b) 		SculptLibrary *lib = CheckSculptLib(LIBOFFSET(SculptLibrary, b)); \
	if (!lib || !lib->b) return; \
	(lib->b)

#define SculptLibCallR(a, b)  SculptLibrary *lib = CheckSculptLib(LIBOFFSET(SculptLibrary, b)); \
	if (!lib || !lib->b) return a; \
	return (lib->b)

//==============================================================================
SculptObject *SculptTag::GetSculptObject() { SculptLibCallR(nullptr, sculpttagGetSculptObject)(this); }

//==============================================================================

// SculptLayerData
Int32						SculptLayerData::GetSubdivisionLevel() { SculptLibCallR(0, sculptlayerdataGetSubdivisionLevel)(this); }
Int32						SculptLayerData::GetPointCount() { SculptLibCallR(0, sculptlayerdataGetPointCount)(this); }
Bool						SculptLayerData::GetOffset(Int32 index, Vector &offset) { SculptLibCallR(false, sculptlayerdataGetOffset)(this, index, offset); }
void						SculptLayerData::SetOffset(Int32 index, const Vector &fullOffset) { SculptLibCall(sculptlayerdataSetOffset)(this, index, fullOffset); }
void						SculptLayerData::AddOffset(Int32 index, const Vector &offset) { SculptLibCall(sculptlayerdataAddOffset)(this, index, offset); }
Bool						SculptLayerData::GetMask(Int32 index, Float32 &mask) { SculptLibCallR(false, sculptlayerdataGetMask)(this, index, mask); }
void						SculptLayerData::SetMask(Int32 index, Float32 mask) { SculptLibCall(sculptlayerdataSetMask)(this, index, mask); }
void						SculptLayerData::AddToMask(Int32 index, Float32 mask) { SculptLibCall(sculptlayerdataAddToMask)(this, index, mask); }
Bool						SculptLayerData::HasMask() { SculptLibCallR(false, sculptlayerdataHasMask)(this); }
void						SculptLayerData::ClearMask() { SculptLibCall(sculptlayerdataClearMask)(this); }
void						SculptLayerData::ClearLayer() { SculptLibCall(sculptlayerdataClearLayer)(this); }
void						SculptLayerData::InitializeAllPointData() { SculptLibCall(sculptlayerdataInitializeAllPointData)(this); }
void						SculptLayerData::InitializeAllMaskData() { SculptLibCall(sculptlayerdataInitializeAllMaskData)(this); }
void						SculptLayerData::TouchPointForUndo(Int32 index) { SculptLibCall(sculptlayerdataTouchPointForUndo)(this, index); }
void						SculptLayerData::TouchMaskForUndo(Int32 index) { SculptLibCall(sculptlayerdataTouchMaskForUndo)(this, index); }


// SculptLayerBase
Bool						SculptLayerBase::Select() { SculptLibCallR(false, sculptlayerbaseSelect)(this); }
Bool						SculptLayerBase::IsVisible() { SculptLibCallR(false, sculptlayerbaseIsVisible)(this); }
void						SculptLayerBase::SetVisible(Bool value) { SculptLibCall(sculptlayerbaseSetVisible)(this, value); }
Bool						SculptLayerBase::IsLocked()	{ SculptLibCallR(false, sculptlayerbaseIsLocked)(this); }
void						SculptLayerBase::SetLocked(Bool value) { SculptLibCall(sculptlayerbaseSetLocked)(this, value); }
Float						SculptLayerBase::GetStrength()	{ SculptLibCallR(1.0, sculptlayerbaseGetStrength)(this); }
void						SculptLayerBase::SetStrength(Float value) { SculptLibCall(sculptlayerbaseSetStrength)(this, value); }

// SculptLayer
SculptLayerData*SculptLayer::GetFirstSculptLayerData() { SculptLibCallR(nullptr, sculptlayerGetFirstSculptLayerData)(this); }
SculptLayerData*SculptLayer::GetCurrentSculptLayerData() { SculptLibCallR(nullptr, sculptlayerGetCurrentSculptLayerData)(this); }
Int32						SculptLayer::GetPointCount() { SculptLibCallR(0, sculptlayerGetPointCount)(this); }
Bool						SculptLayer::GetOffset(Int32 index, Vector &offset) { SculptLibCallR(false, sculptlayerGetOffset)(this, index, offset); }
void						SculptLayer::SetOffset(Int32 index, const Vector &fullOffset) { SculptLibCall(sculptlayerSetOffset)(this, index, fullOffset); }
void						SculptLayer::AddOffset(Int32 index, const Vector &offset) { SculptLibCall(sculptlayerAddOffset)(this, index, offset); }
Bool						SculptLayer::GetMask(Int32 index, Float32 &mask) { SculptLibCallR(false, sculptlayerGetMask)(this, index, mask); }
void						SculptLayer::SetMask(Int32 index, Float32 mask) { SculptLibCall(sculptlayerSetMask)(this, index, mask); }
void						SculptLayer::AddToMask(Int32 index, Float32 mask) { SculptLibCall(sculptlayerAddToMask)(this, index, mask); }
Bool						SculptLayer::IsBaseLayer() { SculptLibCallR(false, sculptlayerIsBaseLayer)(this); }
Bool						SculptLayer::HasMask() { SculptLibCallR(false, sculptlayerHasMask)(this); }
Bool						SculptLayer::IsMaskEnabled() { SculptLibCallR(false, sculptlayerIsMaskEnabled)(this); }
void						SculptLayer::SetMaskEnabled(Bool value) { SculptLibCall(sculptlayerSetMaskEnabled)(this, value); }
void						SculptLayer::ClearMask() { SculptLibCall(sculptlayerClearMask)(this); }
void						SculptLayer::ClearLayer() { SculptLibCall(sculptlayerClearLayer)(this); }
void						SculptLayer::InitializeAllPointData() { SculptLibCall(sculptlayerInitializeAllPointData)(this); }
void						SculptLayer::InitializeAllMaskData() { SculptLibCall(sculptlayerInitializeAllMaskData)(this); }
void						SculptLayer::TouchPointForUndo(Int32 index) { SculptLibCall(sculptlayerTouchPointForUndo)(this, index); }
void						SculptLayer::TouchMaskForUndo(Int32 index) { SculptLibCall(sculptlayerTouchMaskForUndo)(this, index); }


// Sculpt Object
Int32					SculptObject::GetSubdivisionCount() { SculptLibCallR(0, sculptobjGetSubdivisionCount)(this); }
PolygonObject*			SculptObject::GetPolygonCopy(Int32 subdivisionLevel, Bool includeTopLevels) { SculptLibCallR(nullptr, sculptobjGetPolygonCopy)(this, subdivisionLevel, includeTopLevels); }
PolygonObject *			SculptObject::GetOriginalObject() { SculptLibCallR(nullptr, sculptobjGetOriginalObject)(this); }
PolygonObject *SculptObject::GetDisplayPolygonObject() { SculptLibCallR(nullptr, sculptobjGetDisplayPolygonObject)(this); }
Int32					SculptObject::GetPolygonCount()		{ SculptLibCallR(0, sculptobjGetPolygonCount)(this);	}
Int32					SculptObject::GetPointCount()		{ SculptLibCallR(0, sculptobjGetPointCount)(this);	}
SculptLayerBase*		SculptObject::GetCurrentLayer()		{ SculptLibCallR(nullptr, sculptobjGetCurrentLayer)(this);	}
Int32					SculptObject::GetCurrentLevel()		{ SculptLibCallR(0, sculptobjGetCurrentLevel)(this);	}
UInt32					SculptObject::GetMemoryUsage()		{ SculptLibCallR(0, sculptobjGetMemoryUsage)(this);		}
Bool					SculptObject::Hit(BaseDraw* bd, Float mx, Float my, Bool backfaces, SculptHitData  &hitData) { SculptLibCallR(false, sculptobjHitScreen)(this, bd, mx, my, backfaces, hitData);	}
Bool					SculptObject::Hit(const Vector &rayp, const Vector &rayv, Bool backfaces, SculptHitData  &hitData) { SculptLibCallR(false, sculptobjHitObject)(this, rayp, rayv, backfaces, hitData);	}
SculptLayer*			SculptObject::AddLayer() { SculptLibCallR(nullptr, sculptobjAddLayer)(this); }
SculptFolder*			SculptObject::AddFolder() { SculptLibCallR(nullptr, sculptobjAddFolder)(this); }
Bool					SculptObject::DeleteSelectedLayer() { SculptLibCallR(false, sculptobjDeleteSelectedLayer)(this); }
void					SculptObject::Update() { SculptLibCall(sculptobjUpdate)(this); }
const Vector32 *		SculptObject::GetVertexNormals() { SculptLibCallR(nullptr, sculptobjGetVertexNormals)(this); }
Vector *				SculptObject::GetPointW() { SculptLibCallR(nullptr, sculptobjGetPointW)(this); }
const Vector *			SculptObject::GetPointR() { SculptLibCallR(nullptr, sculptobjGetPointR)(this); }
Bool					SculptObject::Subdivide() { SculptLibCallR(false, sculptobjSubdivide)(this); }
Bool					SculptObject::IncreaseSubdivisionLevel() { SculptLibCallR(false, sculptobjIncreaseSubdivisionLevel)(this); }
Bool					SculptObject::DecreaseSubdivisionLevel() { SculptLibCallR(false, sculptobjDecreaseSubdivisionLevel)(this); }
SculptLayerBase*		SculptObject::GetFirstLayer() { SculptLibCallR(nullptr, sculptobjGetFirstLayer)(this); }
SculptLayer*			SculptObject::GetBaseLayer() { SculptLibCallR(nullptr, sculptobjGetBaseLayer)(this); }
Bool					SculptObject::IsFrozen() { SculptLibCallR(false, sculptobjIsFrozen)(this); }
void					SculptObject::SetFrozen(Bool value) { SculptLibCall(sculptobjSetFrozen)(this, value); }
void					SculptObject::UpdateCollision() { SculptLibCall(sculptobjUpdateCollision)(this); }
void					SculptObject::NeedCollisionUpdate(Bool fullUpdate) { SculptLibCall(sculptobjNeedCollisionUpdate)(this, fullUpdate); }
Bool					SculptObject::GetAllowDeformations() { SculptLibCallR(false, sculptobjGetAllowDeformations)(this); }
void					SculptObject::SetAllowDeformations(Bool value) { SculptLibCall(sculptobjSetAllowDeformations)(this, value); }
void					SculptObject::OffsetPoint(SculptLayer *pLayer, Vector *pPoints, Bool useMask, Float opacity, Int32 index, const Vector &offset, Bool respectLayerStrength) { SculptLibCall(sculptobjOffsetPoint)(this, pLayer, pPoints, useMask, opacity, index, offset, respectLayerStrength); }
void					SculptObject::OffsetPreviewPoint(SculptLayer *pLayer, Bool useMask, Float opacity, Int32 index, const Vector &offset, Bool respectLayerStrength) { SculptLibCall(sculptobjOffsetPreviewPoint)(this, pLayer, useMask, opacity, index, offset, respectLayerStrength); }
void					SculptObject::SetPreviewPoint(SculptLayer *pLayer, Bool useMask, Float opacity, Int32 index, const Vector &offset, Bool respectLayerStrength) { SculptLibCall(sculptobjSetPreviewPoint)(this, pLayer, useMask, opacity, index, offset, respectLayerStrength); }
SculptLayerSystem *		SculptObject::GetLayerSystem() { SculptLibCallR(nullptr, sculptobjGetLayerSystem)(this); }
void					SculptObject::StartUndo() { SculptLibCall(sculptobjStartUndo)(this); }
void					SculptObject::EndUndo() { SculptLibCall(sculptobjEndUndo)(this); }
void					SculptObject::Smooth(Int32 count, Bool respectMask) { SculptLibCall(sculptobjSmooth)(this, count, respectMask); }
Float32 *			SculptObject::GetMaskCache() { SculptLibCallR(nullptr, sculptobjGetMaskCache)(this); }
Float32				SculptObject::PointPolysAverage(Int32 vertex, Float32 *values) { SculptLibCallR(0.0f, sculptobjPointPolysAverageFloat32)(this, vertex, values); }
Vector				SculptObject::PointPolysAverage(Int32 vertex, Vector *values) { SculptLibCallR(Vector(), sculptobjPointPolysAverageVector)(this, vertex, values); }
void					SculptObject::UpdateMask(Bool fullUpdate) { SculptLibCall(sculptobjUpdateMask)(this, fullUpdate); }
void					SculptObject::InitOpenGL(BaseDraw *bd) { SculptLibCall(sculptobjInitOpenGL)(this, bd); }
Bool					SculptObject::IsPointSelected(Int32 index) { SculptLibCallR(false, sculptobjIsPointSelected)(this, index); }
Bool					SculptObject::IsPolygonSelected(Int32 index) { SculptLibCallR(false, sculptobjIsPolygonSelected)(this, index); }
Bool					SculptObject::GetPolygon(Int32 index, CPolygon &cpoly) { SculptLibCallR(false, sculptobjGetPolygon)(this, index, cpoly); }
const Vector32 *	SculptObject::GetFaceNormals() { SculptLibCallR(nullptr, sculptobjGetFaceNormals)(this); }

//==============================================================================

SculptObject *GetSelectedSculptObject(BaseDocument *doc, Bool includeHiddenObjects)
{
	if (doc)
	{
		AutoAlloc<AtomArray> selection;
		doc->GetActiveObjects(selection, GETACTIVEOBJECTFLAGS::NONE);

		Int32 a;
		for (a = 0; a < selection->GetCount(); ++a)
		{
			C4DAtom *atom = selection->GetIndex(a);

			if (atom && atom->IsInstanceOf(Obase))
			{
				BaseObject *pBase = (BaseObject*)atom;
				if (IsObjectEnabled(pBase) || includeHiddenObjects)
				{
					BaseTag *pTag = pBase->GetTag(Tsculpt);
					if (pTag)
					{
						SculptTag *pSculptTag = (SculptTag*)pTag;
						return pSculptTag->GetSculptObject();
					}
				}
			}
		}

		doc->GetActiveTags(selection);
		for (a = 0; a < selection->GetCount(); ++a)
		{
			C4DAtom *atom = selection->GetIndex(a);
			if (atom && atom->IsInstanceOf(Tsculpt))
			{
				BaseTag *pTag = (BaseTag*)atom;
				BaseObject *pParentObject = pTag->GetObject();
				if (IsObjectEnabled(pParentObject) || includeHiddenObjects)
				{
					SculptTag *pSculptTag = (SculptTag*)pTag;
					return pSculptTag->GetSculptObject();
				}
			}
		}
	}
	return nullptr;
}

void EnsureSculptObjectReady(PolygonObject *obj, BaseDocument *doc)
{
	ModelingCommandData cd;
	if (!obj || !doc) return;

	BaseObject		*op = obj;
	BaseContainer bc;

	bc.SetBool(MDATA_CURRENTSTATETOOBJECT_NOGENERATE, true);

	cd.doc = doc;
	cd.op = op;
	cd.bc = &bc;

	SendModelingCommand(MCOMMAND_CURRENTSTATETOOBJECT, cd);
}

SculptObject *MakeSculptObject(PolygonObject *poly, BaseDocument *doc, Bool addUndo)
{
	if (!poly) return nullptr;
	SculptTag *pSculptTag  = (SculptTag*)poly->GetTag(Tsculpt);
	if (!pSculptTag)
	{
		if (addUndo)
		{
			doc->StartUndo();
			doc->AddUndo(UNDOTYPE::CHANGE, poly);
			doc->EndUndo();
		}
		pSculptTag = (SculptTag*)poly->MakeTag(Tsculpt);
		if (!pSculptTag) return nullptr;
		EnsureSculptObjectReady(poly, doc);
	}
	return pSculptTag->GetSculptObject();
}


// Return true if op is visible in the viewport
static Bool IsObjectEnabledCheck(BaseObject *op)
{
	if (!op) return false;

	// Check the editor mode
	if (op->GetEditorMode() == MODE_OFF) return false;
	if (op->GetEditorMode() == MODE_UNDEF)
	{
		if (op->GetUp())
		{
			return IsObjectEnabledCheck(op->GetUp());
		}
		else
		{
			return true;
		}
	}
	return true;
}

// Return true if op is visible in the viewport and the layer is visible.
Bool IsObjectEnabled(BaseObject *op)
{
	if (!op) return false;

	// Check the layer that this object is in. If its in a hidden layer then its not visible to the user.
	const LayerData *pLayerData = op->GetLayerData(op->GetDocument());
	if (pLayerData && !pLayerData->view)
	{
		return false;
	}

	return IsObjectEnabledCheck(op);
}
