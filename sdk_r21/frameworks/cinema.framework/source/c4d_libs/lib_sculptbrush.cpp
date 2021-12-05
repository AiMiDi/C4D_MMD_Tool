#ifdef __API_INTERN__
	#error "Not in kernel"
#endif

#include "lib_sculptbrush.h"
#include "c4d_basedocument.h"
#include "c4d_toolplugin.h"
#include "c4d_resource.h"

SculptBrushBaseLibrary *lib_SculptBrushBase = nullptr;

static SculptBrushBaseLibrary *CheckSculptBrushBaseLibrary(Int32 offset)
{
	return (SculptBrushBaseLibrary*)CheckLib(LIBRARY_SCULPTBRUSH, offset, (C4DLibrary**)&lib_SculptBrushBase);
}

#define SculptBrushBaseLibraryCall(b) 		SculptBrushBaseLibrary *lib = CheckSculptBrushBaseLibrary(LIBOFFSET(SculptBrushBaseLibrary, b)); \
															if (!lib || !lib->b) return; \
															(((iSculptBrushBase*)this)->*lib->b)

#define SculptBrushBaseLibraryCallR(a, b)  SculptBrushBaseLibrary *lib = CheckSculptBrushBaseLibrary(LIBOFFSET(SculptBrushBaseLibrary, b)); \
															if (!lib || !lib->b) return a; \
															return (((iSculptBrushBase*)this)->*lib->b)

#define BrushLibraryCall(b) 	SculptBrushBaseLibrary *lib = CheckSculptBrushBaseLibrary(LIBOFFSET(SculptBrushBaseLibrary, b)); \
	if (!lib || !lib->b) return; \
	(lib->b)

#define BrushLibraryCallR(a, b)  SculptBrushBaseLibrary *lib = CheckSculptBrushBaseLibrary(LIBOFFSET(SculptBrushBaseLibrary, b)); \
	if (!lib || !lib->b) return a; \
	return (lib->b)


//================================================
// BrushDabData
//================================================
const BaseContainer *	BrushDabData::GetData()				{ BrushLibraryCallR(nullptr, brushDabDataGetData)(this); }
const SculptObject *	BrushDabData::GetObject()			{ BrushLibraryCallR(nullptr, brushDabDataGetObject)(this); }
const BrushPointData *	BrushDabData::GetPointData()		{ BrushLibraryCallR(nullptr, brushDabDataGetPointData)(this); }
const BrushPolyData *	BrushDabData::GetPolyData()			{ BrushLibraryCallR(nullptr, brushDabDataGetPolyData)(this); }
PolygonObject *			BrushDabData::GetPolygonObject()	{ BrushLibraryCallR(nullptr, brushDabDataGetPolygonObject)(this); }
PolygonObject *			BrushDabData::GetBaseObject()		{ BrushLibraryCallR(nullptr, brushDabDataGetBaseObject)(this); }
Int32					BrushDabData::GetPointCount()		{ BrushLibraryCallR(0, brushDabDataGetPointCount)(this); }
Int32					BrushDabData::GetPolyCount()		{ BrushLibraryCallR(0, brushDabDataGetPolyCount)(this); }
Neighbor *				BrushDabData::GetNeighbor()			{ BrushLibraryCallR(nullptr, brushDabDataGetNeighbor)(this); }
SculptLayer *			BrushDabData::GetLayer()			{ BrushLibraryCallR(nullptr, brushDabDataGetLayer)(this); }
const Vector *			BrushDabData::GetPoints()			{ BrushLibraryCallR(nullptr, brushDabDataGetPoints)(this); }
const Vector32 *		BrushDabData::GetOriginalPoints()	{ BrushLibraryCallR(nullptr, brushDabDataGetOriginalPoints)(this); }
Vector					BrushDabData::GetNormal()			{ BrushLibraryCallR(Vector(), brushDabDataGetNormal)(this); }
Float					BrushDabData::GetBrushStrength()	{ BrushLibraryCallR(0, brushDabDataGetBrushStrength)(this); }
Float					BrushDabData::GetBrushRadius()		{ BrushLibraryCallR(0, brushDabDataGetBrushRadius)(this); }
Vector					BrushDabData::GetMousePos3D()		{ BrushLibraryCallR(Vector(), brushDabDataGetMousePos3D)(this); }
Vector					BrushDabData::GetHitPoint()			{ BrushLibraryCallR(Vector(), brushDabDataGetHitPoint)(this); }
Vector					BrushDabData::GetLastHitPoint()		{ BrushLibraryCallR(Vector(), brushDabDataGetLastHitPoint)(this); }
Vector					BrushDabData::GetEyePoint()			{ BrushLibraryCallR(Vector(), brushDabDataGetEyePoint)(this); }
Bool					BrushDabData::IsMirroredDab()		{ BrushLibraryCallR(false, brushDabDataIsMirroredDab)(this); }
OVERRIDE					BrushDabData::GetBrushOverride()	{ BrushLibraryCallR(OVERRIDE::NONE, brushDabDataGetBrushOverride)(this); }
BaseDraw *				BrushDabData::GetBaseDraw()			{ BrushLibraryCallR(nullptr, brushDabDataGetBaseDraw)(this); }
void					BrushDabData::GetAveragePointAndNormal(Vector &averagePoint, Vector &normal) { BrushLibraryCall(brushDabDataGetAveragePointAndNormal)(this, averagePoint, normal); }
Vector				BrushDabData::GetDrawDirectionNormal() { BrushLibraryCallR(Vector(), brushDabDataGetDrawDirectionNormal)(this); }
Float					BrushDabData::GetBrushFalloff(Int32 index, Vector32 *pRetStencilColor, Float *pCustomDistance) { BrushLibraryCallR(0, brushDabDataGetBrushFalloff)(this, index, pRetStencilColor, pCustomDistance); }
Float					BrushDabData::GetBrushFalloffFromPos(const Vector &pos) { BrushLibraryCallR(0, brushDabDataGetBrushFalloffFromPos)(this, pos); }
void					BrushDabData::OffsetPoint(Int32 index, const Vector &offset, Vector32 *pVertexColor, SCULPTOFFSETFLAGS flags) { BrushLibraryCall(brushDabDataOffsetPoint)(this, index, offset, pVertexColor, flags); }
Bool					BrushDabData::IsPreviewDab() { BrushLibraryCallR(false, brushDabDataIsPreviewDab)(this); }
void					BrushDabData::OffsetPreviewPoint(Int32 index, const Vector &offset, SCULPTOFFSETFLAGS flags) { BrushLibraryCall(brushDabDataOffsetPreviewPoint)(this, index, offset, flags); }
void					BrushDabData::ApplySmooth()	{ BrushLibraryCall(brushDabDataApplySmooth)(this); }
const Vector32*			BrushDabData::GetVertexNormals() { BrushLibraryCallR(nullptr, brushDabDataGetVertexNormals)(this); }
Float					BrushDabData::GetAutoScaleValue(Bool noRadius) { BrushLibraryCallR(1, brushDabDataGetAutoScaleValue)(this, noRadius); }
void					BrushDabData::DirtyAllPoints(SCULPTBRUSHDATATYPE type) { BrushLibraryCall(brushDabDataDirtyAllPoints)(this, type); }
Bool					BrushDabData::IsPointModified(Int32 index) { BrushLibraryCallR(false, brushDabDataIsPointModified)(this, index); }
Float					BrushDabData::GetStencilColor(const Vector &point, Vector32 *pRetColor, Vector32 *pRetCoords, SAMPLEMODE mode) { BrushLibraryCallR(0, brushDabDataGetStencilColor)(this, point, pRetColor, pRetCoords, mode); }
Float					BrushDabData::GetStampColor(const Vector &point, Float distanceFromHitPoint, Vector32 *pRetColor, Vector32 *pRetCoords, SAMPLEMODE mode) { BrushLibraryCallR(0, brushDabDataGetStampColor)(this, point, distanceFromHitPoint, pRetColor, pRetCoords, mode); }
const BaseBitmap* BrushDabData::GetStamp() { BrushLibraryCallR(nullptr, brushDabDataGetStamp)(this); }
const BaseBitmap* BrushDabData::GetStencil() { BrushLibraryCallR(nullptr, brushDabDataGetStencil)(this); }
SculptBrushToolData*	BrushDabData::GetBrush() { BrushLibraryCallR(nullptr, brushDabDataGetBrush)(this); }
Int32					BrushDabData::GetStrokeInstanceID() { BrushLibraryCallR(0, brushDabDataGetStrokeInstanceID)(this); }
Bool					BrushDabData::IsSculptObject() { BrushLibraryCallR(false, brushDabDataIsSculptObject)(this); }
Vector				BrushDabData::GetMirrorPoint(const Vector &point, Bool isNormal) { BrushLibraryCallR(Vector(), brushDabDataGetMirrorPoint)(this, point, isNormal); }
Float32			 *BrushDabData::GetMaskCache() {BrushLibraryCallR(nullptr, brushDabDataGetMaskCache)(this); }
Float32				BrushDabData::PointPolysAverage(Int32 vertex, Float32 *values) {BrushLibraryCallR(0.0f, brushDabDataPointPolysAverageFloat32)(this, vertex, values); }
Vector				BrushDabData::PointPolysAverage(Int32 vertex, Vector *values) {BrushLibraryCallR(Vector(), brushDabDataPointPolysAverageVector)(this, vertex, values); }
Bool					BrushDabData::IsPointInFillArea(const Vector &p) {BrushLibraryCallR(false, brushDabDataIsPointInFillArea)(this, p); }
Bool					BrushDabData::IsBackface() {BrushLibraryCallR(false, brushDabDataIsBackface)(this); }
const Vector32*		BrushDabData::GetFaceNormals() { BrushLibraryCallR(nullptr, brushDabDataGetFaceNormals)(this); }
Int32					BrushDabData::GetHitPolygon()			{ BrushLibraryCallR(-1, brushDabDataGetHitPolygon)(this); }
const Vector32*			BrushDabData::GetOriginalVertexNormals() { BrushLibraryCallR(nullptr, brushDabDataGetOriginalVertexNormals)(this); }

// CustomSculptBrushBase
//================================================
CustomSculptBrushBase* CustomSculptBrushBase::Alloc()
{
	SculptBrushBaseLibrary *lib = CheckSculptBrushBaseLibrary(LIBOFFSET(SculptBrushBaseLibrary, Alloc)); if (!lib) return nullptr;
	return (CustomSculptBrushBase*)lib->Alloc();
}

void CustomSculptBrushBase::Free(CustomSculptBrushBase *&p)
{
	if (!p) return;
	SculptBrushBaseLibrary *lib = CheckSculptBrushBaseLibrary(LIBOFFSET(SculptBrushBaseLibrary, Free)); if (!lib) return;
	iSculptBrushBase* i = (iSculptBrushBase*)p;
	lib->Free(i);
	p = nullptr;
}

Bool CustomSculptBrushBase::InitTool(BaseDocument* doc, BaseContainer& data, BaseThread* bt, SculptBrushToolData *tool) { SculptBrushBaseLibraryCallR(false, InitTool)(doc, data, bt, tool); }
void CustomSculptBrushBase::FreeTool(BaseDocument* doc, BaseContainer& data, SculptBrushToolData *tool) { SculptBrushBaseLibraryCall(FreeTool)(doc, data, tool); }
void CustomSculptBrushBase::InitDefaultSettings(BaseDocument *doc, BaseContainer &data, SculptBrushToolData *tool) { SculptBrushBaseLibraryCall(InitDefaultSettings)(doc, data, tool); }
Bool CustomSculptBrushBase::GetDEnabling(BaseDocument* doc, BaseContainer& data, const DescID& id, const GeData& t_data, DESCFLAGS_ENABLE flags, const BaseContainer* itemdesc, SculptBrushToolData *tool) { SculptBrushBaseLibraryCallR(false, GetDEnabling)(doc, data, id, t_data, flags, itemdesc, tool); }
Bool CustomSculptBrushBase::SetDParameter(BaseDocument* doc, BaseContainer& data, const DescID& id, const GeData& t_data, DESCFLAGS_SET& flags, SculptBrushToolData *tool) { SculptBrushBaseLibraryCallR(false, SetDParameter)(doc, data, id, t_data, flags, tool); }
Bool CustomSculptBrushBase::GetDDescription(BaseDocument* doc, BaseContainer& data, Description* description, DESCFLAGS_DESC& flags, SculptBrushToolData *tool) { SculptBrushBaseLibraryCallR(false, GetDDescription)(doc, data, description, flags, tool); }
Bool CustomSculptBrushBase::Message(BaseDocument *doc, BaseContainer &data, Int32 type, void *t_data, SculptBrushToolData *tool) { SculptBrushBaseLibraryCallR(false, Message)(doc, data, type, t_data, tool); }
Bool CustomSculptBrushBase::TranslateDescID(BaseDocument* doc, BaseContainer& data, const DescID& id, DescID& res_id, C4DAtom*& res_at, SculptBrushToolData *tool) { SculptBrushBaseLibraryCallR(false, TranslateDescID)(doc, data, id, res_id, res_at, tool); }
Bool CustomSculptBrushBase::GetCursorInfo(BaseDocument* doc, BaseContainer& data, BaseDraw* bd, Float x, Float y, BaseContainer& bc, SculptBrushToolData *tool) { SculptBrushBaseLibraryCallR(false, GetCursorInfo)(doc, data, bd, x, y, bc, tool); }
Bool CustomSculptBrushBase::MouseInput(BaseDocument* doc, BaseContainer& data, BaseDraw* bd, EditorWindow* win, const BaseContainer& msg, SculptBrushToolData *tool) { SculptBrushBaseLibraryCallR(false, MouseInput)(doc, data, bd, win, msg, tool); }
Bool CustomSculptBrushBase::KeyboardInput(BaseDocument* doc, BaseContainer& data, BaseDraw* bd, EditorWindow* win, const BaseContainer& msg, SculptBrushToolData *tool) { SculptBrushBaseLibraryCallR(false, KeyboardInput)(doc, data, bd, win, msg, tool); }
Int32 CustomSculptBrushBase::GetState(BaseDocument *doc, SculptBrushToolData *tool) { SculptBrushBaseLibraryCallR(0, GetState)(doc, tool); }
TOOLDRAW CustomSculptBrushBase::Draw(BaseDocument *doc, BaseContainer &data, BaseDraw *bd, BaseDrawHelp *bh, BaseThread *bt, TOOLDRAWFLAGS flags, SculptBrushToolData *tool) { SculptBrushBaseLibraryCallR(TOOLDRAW::NONE, Draw)(doc, data, bd, bh, bt, flags, tool); }
Bool CustomSculptBrushBase::GetDParameter(BaseDocument* doc, BaseContainer& data, const DescID& id, GeData& t_data, DESCFLAGS_GET& flags, SculptBrushToolData *tool) { SculptBrushBaseLibraryCallR(true, GetDParameter)(doc, data, id, t_data, flags, tool); }
Bool CustomSculptBrushBase::DisplayControl(BaseDocument* doc, BaseObject* op, BaseObject* chainstart, BaseDraw* bd, BaseDrawHelp* bh, ControlDisplayStruct& cds, SculptBrushToolData *tool) { SculptBrushBaseLibraryCallR(true, DisplayControl)(doc, op, chainstart, bd, bh, cds, tool); }
Bool CustomSculptBrushBase::InitDisplayControl(BaseDocument* doc, BaseContainer& data, BaseDraw* bd, const AtomArray* active, SculptBrushToolData *tool) { SculptBrushBaseLibraryCallR(true, InitDisplayControl)(doc, data, bd, active, tool); }
void CustomSculptBrushBase::FreeDisplayControl(SculptBrushToolData *tool) { SculptBrushBaseLibraryCall(FreeDisplayControl)(tool); }

// Virtual
void CustomSculptBrushBase::StartStroke(Int32 strokeCount, const BaseContainer &data)  { SculptBrushBaseLibraryCall(StartStroke)(strokeCount, data); }
void CustomSculptBrushBase::StartStrokeInstance(Int32 strokeInstanceID)  { SculptBrushBaseLibraryCall(StartStrokeInstance)(strokeInstanceID); }
void CustomSculptBrushBase::StartSymmetry()  { SculptBrushBaseLibraryCall(StartSymmetry)(); }
void CustomSculptBrushBase::StartStrokeInstanceDabs(Int32 strokeInstanceID)  { SculptBrushBaseLibraryCall(StartStrokeInstanceDabs)(strokeInstanceID); }
void CustomSculptBrushBase::StartDab(Int32 strokeInstanceID)  { SculptBrushBaseLibraryCall(StartDab)(strokeInstanceID); }
void CustomSculptBrushBase::EndDab(Int32 strokeInstanceID)  { SculptBrushBaseLibraryCall(EndDab)(strokeInstanceID); }
void CustomSculptBrushBase::EndStrokeInstanceDabs(Int32 strokeInstanceID)  { SculptBrushBaseLibraryCall(EndStrokeInstanceDabs)(strokeInstanceID); }
void CustomSculptBrushBase::EndSymmetry()  { SculptBrushBaseLibraryCall(EndSymmetry)(); }
void CustomSculptBrushBase::EndStrokeInstance(Int32 strokeInstanceID)  { SculptBrushBaseLibraryCall(EndStrokeInstance)(strokeInstanceID); }
void CustomSculptBrushBase::EndStroke()  { SculptBrushBaseLibraryCall(EndStroke)(); }
void CustomSculptBrushBase::MouseData(Int32 strokeInstanceID, const BaseContainer &brushData, const SculptMouseData &md) { SculptBrushBaseLibraryCall(MouseData)(strokeInstanceID, brushData, md); }


void CustomSculptBrushBase::OverwriteLoadedPresetSettings(BaseContainer &data) { SculptBrushBaseLibraryCall(OverwriteLoadedPresetSettings)(data); }
void CustomSculptBrushBase::PostInitDefaultSettings(BaseDocument *doc, BaseContainer &data) { SculptBrushBaseLibraryCall(PostInitDefaultSettings)(doc, data); }
Bool CustomSculptBrushBase::GetEnabling(Int32 id) { SculptBrushBaseLibraryCallR(true, GetEnabling)(id); }
Bool CustomSculptBrushBase::HandleNonModelPickMode(BaseDocument* doc, BaseContainer& data, BaseDraw* bd, EditorWindow* win, const BaseContainer& msg) { SculptBrushBaseLibraryCallR(true, HandleNonModelPickMode)(doc, data, bd, win, msg); }
Bool CustomSculptBrushBase::HandleFillTool(BaseDocument* doc, BaseContainer& data, BaseDraw* bd, EditorWindow* win, const BaseContainer& msg) { SculptBrushBaseLibraryCallR(true, HandleFillTool)(doc, data, bd, win, msg); }

Bool CustomSculptBrushBase::DrawNonModelPickMode(BaseDocument *doc, BaseContainer &data, BaseDraw *bd, BaseDrawHelp *bh, BaseThread *bt, TOOLDRAWFLAGS flags) { SculptBrushBaseLibraryCallR(true, DrawNonModelPickMode)(doc, data, bd, bh, bt, flags); }
void CustomSculptBrushBase::FloodSelectedLayer(SculptObject *pSculpt, SculptLayer *pLayer, const BaseContainer& brushData, Int32 function, Bool preview, Float *customStrength, const Vector32 *pVertexNormals) { SculptBrushBaseLibraryCall(FloodSelectedLayer)(pSculpt, pLayer, brushData, function, preview, customStrength, pVertexNormals); }
void CustomSculptBrushBase::FloodSelectedLayerWithChannel(SculptObject* pSculpt, SculptLayer *pLayer, const BaseContainer& brushData, Int32 function, BaseChannel *pChannel, Bool preview, Float *customStrength, const Vector32 *pVertexNormals) { SculptBrushBaseLibraryCall(FloodSelectedLayerWithChannel)(pSculpt, pLayer, brushData, function, pChannel, preview, customStrength, pVertexNormals); }
void CustomSculptBrushBase::FloodSelectedLayerWithBitmap(SculptObject* pSculpt, SculptLayer *pLayer, const BaseContainer& brushData, Int32 function, BaseBitmap *pBitmap, Bool preview, Float *customStrength, const Vector32 *pVertexNormals) { SculptBrushBaseLibraryCall(FloodSelectedLayerWithBitmap)(pSculpt, pLayer, brushData, function, pBitmap, preview, customStrength, pVertexNormals); }

Bool CustomSculptBrushBase::HasDrawMode(Int32 mode) { SculptBrushBaseLibraryCallR(true, HasDrawMode)(mode); }

// Non-Virtual
Bool CustomSculptBrushBase::Flood(BaseDocument* doc, BaseDraw* bd, const BaseContainer& brushData, Int32 button) { SculptBrushBaseLibraryCallR(false, Flood)(doc, bd, brushData, button); }
Bool CustomSculptBrushBase::FloodWithChannel(BaseDocument* doc, BaseDraw* bd, const BaseContainer& brushData, BaseChannel *pChannel, Int32 button) { SculptBrushBaseLibraryCallR(false, FloodWithChannel)(doc, bd, brushData, pChannel, button); }
Bool CustomSculptBrushBase::FloodWithBitmap(BaseDocument* doc, BaseDraw* bd, const BaseContainer& brushData, BaseBitmap *pBitmap, Int32 button) { SculptBrushBaseLibraryCallR(false, FloodWithBitmap)(doc, bd, brushData, pBitmap, button); }
void CustomSculptBrushBase::EnableSpecialDrawGizmo(){ SculptBrushBaseLibraryCall(EnableSpecialDrawGizmo)(); }
void CustomSculptBrushBase::DisableSpecialDrawGizmo(){ SculptBrushBaseLibraryCall(DisableSpecialDrawGizmo)(); }
void CustomSculptBrushBase::SetMouseDrag(Bool value){ SculptBrushBaseLibraryCall(SetMouseDrag)(value); }
Bool CustomSculptBrushBase::IsMouseDrag(){ SculptBrushBaseLibraryCallR(false, IsMouseDrag)(); }
void CustomSculptBrushBase::CacheObjects(BaseDocument *doc) { SculptBrushBaseLibraryCall(CacheObjects)(doc); }
Int32 CustomSculptBrushBase::GetSelectionCacheCount(){ SculptBrushBaseLibraryCallR(0, GetSelectionCacheCount)(); }
BaseList2D *CustomSculptBrushBase::GetSelectionCacheObject(Int32 index){ SculptBrushBaseLibraryCallR(nullptr, GetSelectionCacheObject)(index); }
Float CustomSculptBrushBase::GetBrushStrength(Bool original){ SculptBrushBaseLibraryCallR(0, GetBrushStrength)(original); }
void CustomSculptBrushBase::InitZoomScale(BaseDocument *doc){ SculptBrushBaseLibraryCall(InitZoomScale)(doc); }
Bool CustomSculptBrushBase::HasModifier(){ SculptBrushBaseLibraryCallR(false, HasModifier)(); }
Bool CustomSculptBrushBase::HasRespectSelections(){ SculptBrushBaseLibraryCallR(false, HasRespectSelections)(); }


// Presets
Bool CustomSculptBrushBase::WritePresetData(HyperFile *hf)				{ SculptBrushBaseLibraryCallR(false, WritePresetData)(hf); }
Bool CustomSculptBrushBase::ReadPresetData(HyperFile *hf, Int32 level)	{ SculptBrushBaseLibraryCallR(false, ReadPresetData)(hf, level); }
Bool CustomSculptBrushBase::WriteStampPresetData(HyperFile *hf)			{ SculptBrushBaseLibraryCallR(false, WriteStampPresetData)(hf); }
Bool CustomSculptBrushBase::ReadStampPresetData(HyperFile *hf, Int32 level) { SculptBrushBaseLibraryCallR(false, ReadStampPresetData)(hf, level); }
Bool CustomSculptBrushBase::WriteSplinePresetData(HyperFile *hf)			{ SculptBrushBaseLibraryCallR(false, WriteSplinePresetData)(hf); }
Bool CustomSculptBrushBase::ReadSplinePresetData(HyperFile *hf, Int32 level) { SculptBrushBaseLibraryCallR(false, ReadSplinePresetData)(hf, level); }
void CustomSculptBrushBase::UpdateSettingsAfterPresetLoad(BaseContainer *data) { SculptBrushBaseLibraryCall(UpdateSettingsAfterPresetLoad)(data); }
void CustomSculptBrushBase::UpdateStencilAfterPresetLoad(BaseContainer *data) { SculptBrushBaseLibraryCall(UpdateStencilAfterPresetLoad)(data); }

const BaseBitmap *CustomSculptBrushBase::GetStamp() { SculptBrushBaseLibraryCallR(nullptr, GetStamp)(); }
const BaseBitmap *CustomSculptBrushBase::GetStencil() { SculptBrushBaseLibraryCallR(nullptr, GetStencil)(); }

//////////////////////////////////////////////////////////////////////////

Bool SculptBrushToolData::InitTool(BaseDocument* doc, BaseContainer& data, BaseThread* bt)
{
	if (!m_pBrushBase) m_pBrushBase = CustomSculptBrushBase::Alloc();
	if (!m_pBrushBase) return false;
	return m_pBrushBase->InitTool(doc, data, bt, this);
}

void SculptBrushToolData::FreeTool(BaseDocument* doc, BaseContainer& data)
{
	if (m_pBrushBase) m_pBrushBase->FreeTool(doc, data, this);
}

void SculptBrushToolData::InitDefaultSettings(BaseDocument *doc, BaseContainer &data)
{
	if (!m_pBrushBase) m_pBrushBase = CustomSculptBrushBase::Alloc();
	if (m_pBrushBase) m_pBrushBase->InitDefaultSettings(doc, data, this);
}

Bool SculptBrushToolData::GetDEnabling(BaseDocument* doc, BaseContainer& data, const DescID& id, const GeData& t_data, DESCFLAGS_ENABLE flags, const BaseContainer* itemdesc)
{
	if (!SUPER::GetDEnabling(doc, data, id, t_data, flags, itemdesc)) return false;
	if (!GetEnabling(id[0].id)) return false;
	return (m_pBrushBase)?m_pBrushBase->GetDEnabling(doc, data, id, t_data, flags, itemdesc, this):false;
}

Bool SculptBrushToolData::SetDParameter(BaseDocument* doc, BaseContainer& data, const DescID& id, const GeData& t_data, DESCFLAGS_SET& flags)
{
	if (m_pBrushBase)
	{
		m_pBrushBase->SetDParameter(doc, data, id, t_data, flags, this);
		return true;
	}
	return false;
}

Bool SculptBrushToolData::GetDDescription(BaseDocument* doc, BaseContainer& data, Description* description, DESCFLAGS_DESC& flags)
{
	if (!m_pBrushBase) m_pBrushBase = CustomSculptBrushBase::Alloc();
	if (!SUPER::GetDDescription(doc, data, description, flags)) return false;
	return (m_pBrushBase)?m_pBrushBase->GetDDescription(doc, data, description, flags, this):false;
}

Bool SculptBrushToolData::Message(BaseDocument *doc, BaseContainer &data, Int32 type, void *t_data)
{
	Bool ret = (m_pBrushBase)?m_pBrushBase->Message(doc, data, type, t_data, this):false;
	if (!ret) ret = SUPER::Message(doc, data, type, t_data);
	return ret;
}

Bool SculptBrushToolData::TranslateDescID(BaseDocument* doc, BaseContainer& data, const DescID& id, DescID& res_id, C4DAtom*& res_at)
{
	Bool ret = (m_pBrushBase)?m_pBrushBase->TranslateDescID(doc, data, id, res_id, res_at, this):false;
	if (!ret) ret = SUPER::TranslateDescID(doc, data, id, res_id, res_at);
	return ret;
}

Bool SculptBrushToolData::GetCursorInfo(BaseDocument* doc, BaseContainer& data, BaseDraw* bd, Float x, Float y, BaseContainer& bc)
{
	return (m_pBrushBase)?m_pBrushBase->GetCursorInfo(doc, data, bd, x, y, bc, this):false;
}

Bool SculptBrushToolData::MouseInput(BaseDocument* doc, BaseContainer& data, BaseDraw* bd, EditorWindow* win, const BaseContainer& msg)
{
	Bool ret = (m_pBrushBase)?m_pBrushBase->MouseInput(doc, data, bd, win, msg, this):false;
	if (!ret) ret = SUPER::MouseInput(doc, data, bd, win, msg);
	return ret;
}

Bool SculptBrushToolData::KeyboardInput(BaseDocument* doc, BaseContainer& data, BaseDraw* bd, EditorWindow* win, const BaseContainer& msg)
{
	Bool ret = (m_pBrushBase)?m_pBrushBase->KeyboardInput(doc, data, bd, win, msg, this):false;
	if (!ret) ret = SUPER::KeyboardInput(doc, data, bd, win, msg);
	return ret;
}

Int32 SculptBrushToolData::GetState(BaseDocument *doc)
{
	if (!m_pBrushBase) m_pBrushBase = CustomSculptBrushBase::Alloc();
	return (m_pBrushBase)?m_pBrushBase->GetState(doc, this) : 0;
}

TOOLDRAW SculptBrushToolData::Draw(BaseDocument *doc, BaseContainer &data, BaseDraw *bd, BaseDrawHelp *bh, BaseThread *bt, TOOLDRAWFLAGS flags)
{
	return (m_pBrushBase)?m_pBrushBase->Draw(doc, data, bd, bh, bt, flags, this) : TOOLDRAW::NONE;
}

Bool SculptBrushToolData::GetDParameter(BaseDocument* doc, BaseContainer& data, const DescID& id, GeData& t_data, DESCFLAGS_GET& flags)
{
	return (m_pBrushBase)?m_pBrushBase->GetDParameter(doc, data, id, t_data, flags, this) : true;
}

Bool SculptBrushToolData::DisplayControl(BaseDocument* doc, BaseObject* op, BaseObject* chainstart, BaseDraw* bd, BaseDrawHelp* bh, ControlDisplayStruct& cds)
{
	return (m_pBrushBase)?m_pBrushBase->DisplayControl(doc, op, chainstart, bd, bh, cds, this) : true;
}

Bool SculptBrushToolData::InitDisplayControl(BaseDocument* doc, BaseContainer& data, BaseDraw* bd, const AtomArray* active)
{
	return (m_pBrushBase)?m_pBrushBase->InitDisplayControl(doc, data, bd, active, this) : true;
}

void SculptBrushToolData::FreeDisplayControl(void)
{
	if (m_pBrushBase) m_pBrushBase->FreeDisplayControl(this);
}

void SculptBrushToolData::StartStroke(Int32 strokeCount, const BaseContainer &data)
{
	if (m_pBrushBase) m_pBrushBase->StartStroke(strokeCount, data);
}

void SculptBrushToolData::EndStroke()
{
	if (m_pBrushBase) m_pBrushBase->EndStroke();
}

void SculptBrushToolData::MouseData(Int32 strokeInstanceID, const BaseContainer &brushData, const SculptMouseData &md)
{
	if (m_pBrushBase) m_pBrushBase->MouseData(strokeInstanceID, brushData, md);
}

void SculptBrushToolData::StartStrokeInstance(Int32 strokeInstanceID)
{
	if (m_pBrushBase) m_pBrushBase->StartStrokeInstance(strokeInstanceID);
}

void SculptBrushToolData::EndStrokeInstance(Int32 strokeInstanceID)
{
	if (m_pBrushBase) m_pBrushBase->EndStrokeInstance(strokeInstanceID);
}

void SculptBrushToolData::StartStrokeInstanceDabs(Int32 strokeInstanceID)
{
	if (m_pBrushBase) m_pBrushBase->StartStrokeInstanceDabs(strokeInstanceID);
}

void SculptBrushToolData::EndStrokeInstanceDabs(Int32 strokeInstanceID)
{
	if (m_pBrushBase) m_pBrushBase->EndStrokeInstanceDabs(strokeInstanceID);
}

void SculptBrushToolData::StartSymmetry()
{
	if (m_pBrushBase) m_pBrushBase->StartSymmetry();
}

void SculptBrushToolData::EndSymmetry()
{
	if (m_pBrushBase) m_pBrushBase->EndSymmetry();
}

void SculptBrushToolData::StartDab(Int32 strokeInstanceID)
{
	if (m_pBrushBase) m_pBrushBase->StartDab(strokeInstanceID);
}

void SculptBrushToolData::EndDab(Int32 strokeInstanceID)
{
	if (m_pBrushBase) m_pBrushBase->EndDab(strokeInstanceID);
}

void SculptBrushToolData::OverwriteLoadedPresetSettings(BaseContainer &data)
{
	if (m_pBrushBase) m_pBrushBase->OverwriteLoadedPresetSettings(data);
}

void SculptBrushToolData::PostInitDefaultSettings(BaseDocument *doc, BaseContainer &data)
{
	if (m_pBrushBase) m_pBrushBase->PostInitDefaultSettings(doc, data);
}

Bool SculptBrushToolData::GetEnabling(Int32 id)
{
	return (m_pBrushBase)?m_pBrushBase->GetEnabling(id) : false;
}

Bool SculptBrushToolData::GetCustomData(Int32 strokeInstanceID, SculptCustomData *pData)
{
	return false;
}

Bool SculptBrushToolData::HandleFillTool(BaseDocument* doc, BaseContainer& data, BaseDraw* bd, EditorWindow* win, const BaseContainer& msg)
{
	return (m_pBrushBase)?m_pBrushBase->HandleFillTool(doc, data, bd, win, msg) : true;
}

Bool SculptBrushToolData::HandleNonModelPickMode(BaseDocument* doc, BaseContainer& data, BaseDraw* bd, EditorWindow* win, const BaseContainer& msg)
{
	return (m_pBrushBase)?m_pBrushBase->HandleNonModelPickMode(doc, data, bd, win, msg) : true;
}

Bool SculptBrushToolData::DrawNonModelPickMode(BaseDocument *doc, BaseContainer &data, BaseDraw *bd, BaseDrawHelp *bh, BaseThread *bt, TOOLDRAWFLAGS flags)
{
	return (m_pBrushBase)?m_pBrushBase->DrawNonModelPickMode(doc, data, bd, bh, bt, flags) : true;
}

void SculptBrushToolData::FloodSelectedLayer(SculptObject *pSculpt, SculptLayer *pLayer, const BaseContainer& brushData, Int32 function, Bool preview, Float *customStrength, const Vector32 *pVertexNormals)
{
	if (m_pBrushBase) m_pBrushBase->FloodSelectedLayer(pSculpt, pLayer, brushData, function, preview, customStrength, pVertexNormals);
}

void SculptBrushToolData::FloodSelectedLayerWithChannel(SculptObject *pSculpt, SculptLayer *pLayer, const BaseContainer& brushData, Int32 function, BaseChannel *pChannel, Bool preview, Float *customStrength, const Vector32 *pVertexNormals)
{
	if (m_pBrushBase) m_pBrushBase->FloodSelectedLayerWithChannel(pSculpt, pLayer, brushData, function, pChannel, preview, customStrength, pVertexNormals);
}

void SculptBrushToolData::FloodSelectedLayerWithBitmap(SculptObject *pSculpt, SculptLayer *pLayer, const BaseContainer& brushData, Int32 function, BaseBitmap *pBitmap, Bool preview, Float *customStrength, const Vector32 *pVertexNormals)
{
	if (m_pBrushBase) m_pBrushBase->FloodSelectedLayerWithBitmap(pSculpt, pLayer, brushData, function, pBitmap, preview, customStrength, pVertexNormals);
}

Bool SculptBrushToolData::HasDrawMode(Int32 mode)
{
	if (m_pBrushBase) return m_pBrushBase->HasDrawMode(mode);
	return false;
}

// Non Virtual
Bool SculptBrushToolData::Flood(BaseDocument* doc, BaseDraw* bd, const BaseContainer& brushData, Int32 button)
{
	return (m_pBrushBase)?m_pBrushBase->Flood(doc, bd, brushData, button) : false;
}
Bool SculptBrushToolData::FloodWithChannel(BaseDocument* doc, BaseDraw* bd, const BaseContainer& brushData, BaseChannel *pChannel, Int32 button)
{
	return (m_pBrushBase)?m_pBrushBase->FloodWithChannel(doc, bd, brushData, pChannel, button) : false;
}
Bool SculptBrushToolData::FloodWithBitmap(BaseDocument* doc, BaseDraw* bd, const BaseContainer& brushData, BaseBitmap *pBitmap, Int32 button)
{
	return (m_pBrushBase)?m_pBrushBase->FloodWithBitmap(doc, bd, brushData, pBitmap, button) : false;
}

void SculptBrushToolData::EnableSpecialDrawGizmo()
{
	if (m_pBrushBase) m_pBrushBase->EnableSpecialDrawGizmo();
}

void SculptBrushToolData::DisableSpecialDrawGizmo()
{
	if (m_pBrushBase) m_pBrushBase->DisableSpecialDrawGizmo();
}

void SculptBrushToolData::SetMouseDrag(Bool value)
{
	if (m_pBrushBase) m_pBrushBase->SetMouseDrag(value);
}

Bool SculptBrushToolData::IsMouseDrag()
{
	return (m_pBrushBase)?m_pBrushBase->IsMouseDrag() : false;
}

void SculptBrushToolData::CacheObjects(BaseDocument *doc)
{
	if (m_pBrushBase) m_pBrushBase->CacheObjects(doc);
}

Int32 SculptBrushToolData::GetSelectionCacheCount()
{
	return (m_pBrushBase)?m_pBrushBase->GetSelectionCacheCount() : 0;
}

BaseList2D *SculptBrushToolData::GetSelectionCacheObject(Int32 index)
{
	return (m_pBrushBase)?m_pBrushBase->GetSelectionCacheObject(index) : nullptr;
}

Float SculptBrushToolData::GetBrushStrength(Bool original)
{
	return (m_pBrushBase)?m_pBrushBase->GetBrushStrength(original) : 1.0;
}

void SculptBrushToolData::InitZoomScale(BaseDocument *doc)
{
	if (m_pBrushBase) m_pBrushBase->InitZoomScale(doc);
}

Bool SculptBrushToolData::HasModifier()
{
	if (m_pBrushBase) return m_pBrushBase->HasModifier();
	return false;
}

Bool SculptBrushToolData::HasRespectSelections()
{
	if (m_pBrushBase) return m_pBrushBase->HasRespectSelections();
	return false;
}

// Presets
Bool SculptBrushToolData::WritePresetData(HyperFile *hf)				{ 	if (m_pBrushBase) { return m_pBrushBase->WritePresetData(hf); } return false; }
Bool SculptBrushToolData::ReadPresetData(HyperFile *hf, Int32 level)		{ 	if (m_pBrushBase) { return m_pBrushBase->ReadPresetData(hf, level); } return false; }
Bool SculptBrushToolData::WriteStampPresetData(HyperFile *hf)			{ 	if (m_pBrushBase) { return m_pBrushBase->WriteStampPresetData(hf); } return false; }
Bool SculptBrushToolData::ReadStampPresetData(HyperFile *hf, Int32 level) { 	if (m_pBrushBase) { return m_pBrushBase->ReadStampPresetData(hf, level); } return false; }
Bool SculptBrushToolData::WriteSplinePresetData(HyperFile *hf)			{ 	if (m_pBrushBase) { return m_pBrushBase->WriteSplinePresetData(hf); } return false; }
Bool SculptBrushToolData::ReadSplinePresetData(HyperFile *hf, Int32 level) { 	if (m_pBrushBase) { return m_pBrushBase->ReadSplinePresetData(hf, level); } return false; }
void SculptBrushToolData::UpdateSettingsAfterPresetLoad(BaseContainer *data) { 	if (m_pBrushBase) m_pBrushBase->UpdateSettingsAfterPresetLoad(data); }
void SculptBrushToolData::UpdateStencilAfterPresetLoad(BaseContainer *data) { 	if (m_pBrushBase) m_pBrushBase->UpdateStencilAfterPresetLoad(data); }
const BaseBitmap *SculptBrushToolData::GetStamp()							 { 	if (m_pBrushBase) { return m_pBrushBase->GetStamp(); } return nullptr; }
const BaseBitmap *SculptBrushToolData::GetStencil()							 { 	if (m_pBrushBase) { return m_pBrushBase->GetStencil(); } return nullptr; }

Bool SculptBrushToolData::ApplyPythonDab(BrushDabData *dab) { return false; }

//================================================
// SculptBrushParams
//================================================
SculptBrushParams* SculptBrushParams::Alloc() { BrushLibraryCallR(nullptr, sculptbrushparamsAlloc)(); }
void SculptBrushParams::Free(SculptBrushParams *&params) { BrushLibraryCall(sculptbrushparamsFree)(params); }
void SculptBrushParams::EnableStencil(Bool enable) { BrushLibraryCall(sculptbrushparamsEnableStencil)(this, enable); }
void SculptBrushParams::EnableStamp(Bool enable) { BrushLibraryCall(sculptbrushparamsEnableStamp)(this, enable); }
void SculptBrushParams::EnableInvertCheckbox(Bool enable) { BrushLibraryCall(sculptbrushparamsEnableInvertCheckbox)(this, enable); }
void SculptBrushParams::EnableBuildup(Bool enable) { BrushLibraryCall(sculptbrushparamsEnableBuildup)(this, enable); }
void SculptBrushParams::EnableNonModelPickMode(Bool enable) { BrushLibraryCall(sculptbrushparamsEnableNonModelPickMode)(this, enable); }
void SculptBrushParams::EnableFlood(Bool enable) { BrushLibraryCall(sculptbrushparamsEnableFlood)(this, enable); }
void SculptBrushParams::EnableMultiThreading(Bool enable) { BrushLibraryCall(sculptbrushparamsEnableMultiThreading)(this, enable); }
void SculptBrushParams::EnableToolSpecificSmooth(Bool enable) { BrushLibraryCall(sculptbrushparamsEnableToolSpecificSmooth)(this, enable); }
void SculptBrushParams::EnableBrushAccess(Bool enable) { BrushLibraryCall(sculptbrushparamsEnableBrushAccess)(this, enable); }
void SculptBrushParams::EnableModifier(Bool enable) { BrushLibraryCall(sculptbrushparamsEnableModifier)(this, enable); }
void SculptBrushParams::EnablePython(Bool enable) { BrushLibraryCall(sculptbrushparamsEnablePython)(this, enable); }
void SculptBrushParams::EnableDrawDirection(Bool enable) { BrushLibraryCall(sculptbrushparamsEnableDrawDirection)(this, enable); }
void SculptBrushParams::EnableCustomStamp(Bool enable) { BrushLibraryCall(sculptbrushparamsEnableCustomStamp)(this, enable); }
void SculptBrushParams::EnableRespectSelections(Bool enable) { BrushLibraryCall(sculptbrushparamsEnableRespectSelections)(this, enable); }
void SculptBrushParams::EnableFillToolIsolatedPointRemover(Bool enable) { BrushLibraryCall(sculptbrushparamsEnableFillToolIsolatedPointRemover)(this, enable); }
void SculptBrushParams::EnablePressureHUD(Bool enable) { BrushLibraryCall(sculptbrushparamsEnablePressureHUD)(this, enable); }
void SculptBrushParams::EnableMouseData(Bool enable) { BrushLibraryCall(sculptbrushparamsEnableMouseData)(this, enable); }
void SculptBrushParams::EnableBackfaceSculpting(Bool enable) { BrushLibraryCall(sculptbrushparamsEnableBackfaceSculpting)(this, enable); }

void SculptBrushParams::SetFloodType(SCULPTBRUSHDATATYPE type) { BrushLibraryCall(sculptbrushparamsSetFloodType)(this, type); }
void SculptBrushParams::SetBrushMode(SCULPTBRUSHMODE mode) { BrushLibraryCall(sculptbrushparamsSetBrushMode)(this, mode); }
void SculptBrushParams::SetFirstHitPointType(FIRSTHITPPOINTTYPE type) { BrushLibraryCall(sculptbrushparamsSetFirstHitPointType)(this, type); }
void SculptBrushParams::SetUndoType(SCULPTBRUSHDATATYPE type) { BrushLibraryCall(sculptbrushparamsSetUndoType)(this, type); }
void SculptBrushParams::SetPolygonObjectDirtyFlags(DIRTYFLAGS flags) { BrushLibraryCall(sculptbrushparamsSetPolygonObjectDirtyFlags)(this, flags); }
void SculptBrushParams::SetMovePointFunc(Bool (*surfaceMovePointFunc)(BrushDabData *dab)) { BrushLibraryCall(sculptbrushparamsSetMovePointFunc)(this, surfaceMovePointFunc); }


SculptFlagChecker *SculptFlagChecker::Alloc() { BrushLibraryCallR(nullptr, sculptflagcheckerAlloc)(); }
void SculptFlagChecker::Free(SculptFlagChecker *&fc) { BrushLibraryCall(sculptflagcheckerFree)(fc); }
Bool SculptFlagChecker::Init(UInt32 count) { BrushLibraryCallR(false, sculptflagcheckerInit)(this, count); }
void SculptFlagChecker::Clear() { BrushLibraryCall(sculptflagcheckerClear)(this); }
UInt32 SculptFlagChecker::GetCount() { BrushLibraryCallR(0, sculptflagcheckerGetCount)(this); }
void SculptFlagChecker::Set(UInt32 val) { BrushLibraryCall(sculptflagcheckerSet)(this, val); }
Bool SculptFlagChecker::CheckSet(UInt32 val) { BrushLibraryCallR(false, sculptflagcheckerCheckSet)(this, val); }
Bool SculptFlagChecker::Check(UInt32 val) { BrushLibraryCallR(false, sculptflagcheckerCheck)(this, val); }
void SculptFlagChecker::UnSet(UInt32 val) { BrushLibraryCall(sculptflagcheckerUnSet)(this, val); }

SculptPointPolysIterator *SculptPointPolysIterator::Alloc() { BrushLibraryCallR(nullptr, sculptpointpolyiteratorAlloc)(); }
void SculptPointPolysIterator::Free(SculptPointPolysIterator *&itr) { BrushLibraryCall(sculptpointpolyiteratorFree)(itr); }
Bool SculptPointPolysIterator::Init(const SculptObject *pObj, Int32 vertex) { BrushLibraryCallR(false, sculptpointpolyiteratorInit)(this, pObj, vertex); }
void SculptPointPolysIterator::Next() { BrushLibraryCall(sculptpointpolyiteratorNext)(this); }
Bool SculptPointPolysIterator::IsValid() { BrushLibraryCallR(false, sculptpointpolyiteratorIsValid)(this); }
CPolygon SculptPointPolysIterator::GetPolygon() { BrushLibraryCallR(CPolygon(), sculptpointpolyiteratorGetPolygon)(this); }
Int32 SculptPointPolysIterator::GetIndex() { BrushLibraryCallR(0, sculptpointpolyiteratorGetIndex)(this); }

SculptModifierInterface *SculptModifierInterface::Alloc() { BrushLibraryCallR(nullptr, sculptmodifierinterfaceAlloc)(); }
void SculptModifierInterface::Free(SculptModifierInterface *&brush) { BrushLibraryCall(sculptmodifierinterfaceFree)(brush); }
Bool		SculptModifierInterface::Init(PolygonObject *poly) { BrushLibraryCallR(0, sculptmodifierinterfaceInit)(this, poly); }
void		SculptModifierInterface::Clear() { BrushLibraryCall(sculptmodifierinterfaceClear)(this); }
BaseContainer SculptModifierInterface::GetDefaultData() { BrushLibraryCallR(BaseContainer(), sculptmodifierinterfaceGetDefaultData)(this); }
Int32		SculptModifierInterface::GetModifierCount() { BrushLibraryCallR(0, sculptmodifierinterfaceGetModifierCount)(this); }
Bool		SculptModifierInterface::GetModifierInfo(Int32 index, Int32 &modifierId, String &name) { BrushLibraryCallR(false, sculptmodifierinterfaceGetModifierInfo)(this, index, modifierId, name); }
Bool		SculptModifierInterface::SetData(const BaseContainer &brushData, const BaseContainer &modifierData) { BrushLibraryCallR(false, sculptmodifierinterfaceSetData)(this, brushData, modifierData); }
Bool		SculptModifierInterface::ApplyModifier(Int32 modifierId, Int32 vertex, const BaseContainer &brushData, const BaseContainer &modifierData, Vector *pHitPoint, Vector *pLastHitPoint, Bool respectSelections) { BrushLibraryCallR(false, sculptmodifierinterfaceApplyModifierPoly)(this, modifierId, vertex, brushData, modifierData, pHitPoint, pLastHitPoint, respectSelections); }

//================================================
// Stand alone methods
//================================================
Bool AddSculptBrushModifierFunction(Int32 id, String name, SCULPTBRUSHMODE mode, SCULPTBRUSHDATATYPE type, maxon::BaseArray<Int32> *brushFilters, maxon::BaseArray<Int32> *brushRestrictions, Bool hide)
{
	BrushLibraryCallR(false, sculptbrushAddModifierFunc)(id, name, mode, type, brushFilters, brushRestrictions, hide);
}

Bool IsSculptBrush(Int32 toolID)
{
	BasePlugin *pPlugin = FindPlugin(toolID, PLUGINTYPE::TOOL);
	if (pPlugin)
	{
		return (pPlugin->GetInfo() & (PLUGINFLAG_TOOL_SCULPTBRUSH)) != 0;
	}
	return false;
}

SculptBrushToolData *GetSelectedSculptBrush(BaseDocument *doc)
{
	if (!doc)
		return nullptr;

	Int32 toolID = doc->GetAction();
	BasePlugin* pPlugin = FindPlugin(toolID, PLUGINTYPE::TOOL);
	if (!pPlugin)
		return nullptr;

	Bool isSculptBrush = (pPlugin->GetInfo() & PLUGINFLAG_TOOL_SCULPTBRUSH) != 0;
	if (!isSculptBrush)
		return nullptr;

	TOOLPLUGIN *toolPlugin = (TOOLPLUGIN *)pPlugin->GetPluginStructure();
	if (toolPlugin)
	{
		return (SculptBrushToolData*)toolPlugin->adr;
	}

	return nullptr;
}

Bool RegisterBrushModifier(Int32 id, const String &name, DataAllocator *g, SCULPTBRUSHMODE mode, SCULPTBRUSHDATATYPE type, const String &res, Bool hide, maxon::BaseArray<Int32> *brushFilters, maxon::BaseArray<Int32> *brushRestrictions, Int32 diskLevel)
{
	if (!RegisterNodePlugin(id, name, PLUGINFLAG_HIDE|PLUGINFLAG_HIDEPLUGINMENU, g, nullptr, diskLevel, nullptr)) return false;
	if (!RegisterDescription(id, res)) return false;
	if (!AddSculptBrushModifierFunction(id, name, mode, type, brushFilters, brushRestrictions, hide)) return false;
	return true;
}
