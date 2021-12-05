#include "lib_hair.h"
#include "c4d_objectdata.h"
#include "c4d_scenehookplugin.h"

//////////////////////////////////////////////////////////////////////////

HairObjectLib*	 lib_hair = nullptr;
HairColliderLib* lib_hair_collider = nullptr;

static HairObjectLib* CheckHairObjectLib(Int32 offset)
{
	return (HairObjectLib*)CheckLib(LIBRARY_HAIR, offset, (C4DLibrary**)&lib_hair);
}

static HairColliderLib* CheckHairColliderLib(Int32 offset)
{
	return (HairColliderLib*)CheckLib(LIBRARY_HAIR_COLLIDER, offset, (C4DLibrary**)&lib_hair_collider);
}

#define HairObjectLibCall(b) HairObjectLib * lib = CheckHairObjectLib(LIBOFFSET(HairObjectLib, b));	\
	if (!lib || !lib->b) return; \
	(lib->b)

#define HairObjectLibCallR(a, b) HairObjectLib * lib = CheckHairObjectLib(LIBOFFSET(HairObjectLib, b));	\
	if (!lib || !lib->b) return a; \
	return (lib->b)

#define HairColliderLibCall(b) HairColliderLib * lib = CheckHairColliderLib(LIBOFFSET(HairColliderLib, b));	\
	if (!lib || !lib->b) return; \
	(((iHairCollider*)this)->*lib->b)

#define HairColliderLibCallR(a, b) HairColliderLib * lib = CheckHairColliderLib(LIBOFFSET(HairColliderLib, b));	\
	if (!lib || !lib->b) return a; \
	return (((iHairCollider*)this)->*lib->b)

//////////////////////////////////////////////////////////////////////////


#ifndef __API_INTERN__

Bool HairObject::Lock(BaseDocument* pDoc, BaseThread* pThread, Bool bValidate, Int32 flags) { HairObjectLibCallR(false, Lock) (this, pDoc, pThread, bValidate, flags); }
void HairObject::Unlock() { HairObjectLibCall(Unlock) (this); }
Bool HairObject::IsLocked() { HairObjectLibCallR(false, hairIsLocked) (this); }
#endif

HairGuides* HairObject::GetGuides() { HairObjectLibCallR(nullptr, GetGuides) (this); }
HairGuides* HairObject::GetDynamicGuides() { HairObjectLibCallR(nullptr, GetDynamicGuides) (this); }
Bool HairObject::GetRootObject(BaseObject** pObject, BaseTag** pTag, RootObjectData* pData) { HairObjectLibCallR(false, GetRootObject) (this, pObject, pTag, pData); }
HairGuides* HairObject::GenerateHair(Int32 flags, Int32 count, Int32 segments, HairMaterialData** pMaterial, HairInterpolationMap* pMap) { HairObjectLibCallR(nullptr, GenerateHair) (this, flags, count, segments, pMaterial, pMap); }
Bool HairObject::SetGuides(HairGuides* guides, Bool clone) { HairObjectLibCallR(false, SetGuides) (this, guides, clone); }
void HairObject::RemoveGuides() { HairObjectLibCall(RemoveGuides) (this); }
Bool HairObject::Update(BaseDocument* doc)
{
	ObjectData* odata = GetNodeData<ObjectData>();
	if (!odata)
		return false;
	return odata->Execute(this, doc, nullptr, 0, EXECUTIONFLAGS::EXPRESSION) == EXECUTIONRESULT::OK;
}
HairMaterialData* HairObject::InitMaterials(const InitRenderStruct& irs, BaseDocument* pDoc, HairGuides* guides, VolumeData* vd) { HairObjectLibCallR(nullptr, InitMaterials) (irs, this, pDoc, guides, vd); }
void HairObject::FreeMaterials(HairMaterialData*& pMaterials) { HairObjectLibCall(FreeMaterials) (this, pMaterials); }


//////////////////////////////////////////////////////////////////////////

HairGuides* HairGuides::Alloc(Int32 count, Int32 segments) { HairObjectLibCallR(nullptr, AllocGuides) (count, segments); }
void HairGuides::Free(HairGuides*& guides) { HairObjectLibCall(FreeGuides) (guides); }
Int32 HairGuides::GetCount() { HairObjectLibCallR(0, GetGuideCount) (this); }
Int32 HairGuides::GetSegmentCount() { HairObjectLibCallR(0, GetGuideSegmentCount) (this); }
Vector* HairGuides::GetPoints() { HairObjectLibCallR(nullptr, GetGuidePoints) (this); }
HairGuideDynamics* HairGuides::GetDynamics() { HairObjectLibCallR(nullptr, GetGuideDynamics) (this); }
Matrix HairGuides::GetMg() { HairObjectLibCallR(Matrix(), GetGuideMg) (this); }
void HairGuides::SetMg(const Matrix& mg) { HairObjectLibCall(SetGuideMg) (this, mg); }
HairRootData HairGuides::GetRoot(Int32 index) { HairObjectLibCallR(HairRootData(), GetGuideRoot) (this, index); }
void HairGuides::SetRoot(Int32 index, const HairRootData& root, Bool update) { HairObjectLibCall(SetGuideRoot) (this, index, root, update); }
HairObject* HairGuides::GetObject() { HairObjectLibCallR(nullptr, GetGuideObject) (this); }
Bool HairGuides::GetSelected(Int32 mode, BaseSelect* select) { HairObjectLibCallR(false, GetGuideSelected) (this, mode, select); }
Bool HairGuides::CopyFrom(const HairGuides* src) { HairObjectLibCallR(false, CopyGuidesFrom) (this, src); }
Bool HairGuides::SetSelected(Int32 mode, BaseSelect* select) { HairObjectLibCallR(false, SetGuideSelected) (this, mode, select); }
Bool HairGuides::ConvertSelection(Int32 from_mode, Int32 to_mode, BaseSelect* from_select, BaseSelect* to_select) { HairObjectLibCallR(false, ConvertGuideSelection) (this, from_mode, to_mode, from_select, to_select); }
Vector HairGuides::GetTangent(Int32 guide, Int32 segment, Float t) { HairObjectLibCallR(Vector(0.0), GetGuideTangent) (this, guide, segment, t); }
SplineObject* HairGuides::CreateSpline() { HairObjectLibCallR(nullptr, CreateGuideSpline) (this); }

void HairGuides::ToLocal() { HairObjectLibCall(guideToLocal) (this); }
void HairGuides::ToWorld() { HairObjectLibCall(guideToWorld) (this); }
void HairGuides::ToInitial(Bool align) { HairObjectLibCall(guideToInitial) (this, align); }
void HairGuides::UndisplaceRoots() { HairObjectLibCall(guideUndisplaceRoots) (this); }
void HairGuides::DisplaceRoots() { HairObjectLibCall(guideDisplaceRoots) (this); }

Bool HairGuides::GetRootAxis(Int32 index, Matrix& m, Bool bAlign, Bool bLocal, Bool bInitial, Bool bZAxis) { HairObjectLibCallR(false, guideGetRootAxis) (this, index, m, bAlign, bLocal, bInitial, bZAxis); }
Vector HairGuides::GetRootUV(Int32 index) { HairObjectLibCallR(Vector(), guideGetRootUV) (this, index); }
Bool HairGuides::GetRootData(Int32 index, Vector* p, Vector* n, Int32* ply_id, Bool bLocal, Bool bDisplaced, Bool bInitial) { HairObjectLibCallR(false, guideGetRootData) (this, index, p, n, ply_id, bLocal, bDisplaced, bInitial); }

Matrix* HairGuides::GetTransformMatrix() { HairObjectLibCallR(nullptr, guideGetTransformMatrix) (this); }
void HairGuides::SetTransformMatrix(Matrix* tm) { HairObjectLibCall(guideSetTransformMatrix) (this, tm); }
Bool HairGuides::Delete(BaseSelect* bs) { HairObjectLibCallR(false, guideDelete) (this, bs); }
Bool HairGuides::AddRoot(Int32 ply_id, Float s, Float t, Float len) { HairObjectLibCallR(false, guideAddRoot) (this, ply_id, s, t, len); }
Bool HairGuides::GetRootObject(RootObjectData* pData) { HairObjectLibCallR(false, guideGetRootObject) (this, pData); }
Bool HairGuides::LinkToObject(HairObject* pHair) { HairObjectLibCallR(false, guideLinkToObject) (this, pHair); }

Int32 HairGuides::GetFlags() { HairObjectLibCallR(false, guideGetFlags) (this); }
Int32 HairGuides::SetFlags(Int32 flags) { HairObjectLibCallR(false, guideSetFlags) (this, flags); }

//////////////////////////////////////////////////////////////////////////

HairGuides* HairGuideDynamics::GetGuides() { HairObjectLibCallR(nullptr, GetDynamicsGuides) (this); }

Vector HairGuideDynamics::GetPosition(Int32 i) { HairObjectLibCallR(Vector(), GetDynamicsPosition) (this, i); }
void HairGuideDynamics::SetPosition(Int32 i, const Vector& p) { HairObjectLibCall(SetDynamicsPosition) (this, i, p); }
Vector HairGuideDynamics::GetLastPosition(Int32 i) { HairObjectLibCallR(Vector(), GetDynamicsLastPosition) (this, i); }
void HairGuideDynamics::SetLastPosition(Int32 i, const Vector& p) { HairObjectLibCall(SetDynamicsLastPosition) (this, i, p); }
Vector HairGuideDynamics::GetVelocity(Int32 i) { HairObjectLibCallR(Vector(), GetDynamicsVelocity) (this, i); }
void HairGuideDynamics::SetVelocity(Int32 i, const Vector& v) { HairObjectLibCall(SetDynamicsVelocity) (this, i, v); }
Float HairGuideDynamics::GetMass(Int32 i) { HairObjectLibCallR(0.0, GetDynamicsMass) (this, i); }
void HairGuideDynamics::SetMass(Int32 i, Float m) { HairObjectLibCall(SetDynamicsMass) (this, i, m); }
Vector HairGuideDynamics::GetForce(Int32 i) { HairObjectLibCallR(Vector(), GetDynamicsForce) (this, i); }
void HairGuideDynamics::AddForce(Int32 i, const Vector& f) { HairObjectLibCall(AddDynamicsForce) (this, i, f); }
Int32 HairGuideDynamics::GetPolygonIntersections(HairPolygonHit** hits) { HairObjectLibCallR(0, GetDynamicsPolygonIntersections) (this, hits); }

//////////////////////////////////////////////////////////////////////////

Int32 HairLibrary::GetMode(BaseDocument* doc) { HairObjectLibCallR(0, hairGetMode) (doc); }
void HairLibrary::SetMode(BaseDocument* doc, Int32 mode) { HairObjectLibCall(hairSetMode) (doc, mode); }
Bool HairLibrary::GetHairGlobal(BaseDocument* doc) { HairObjectLibCallR(0, hairGetHairGlobal) (doc); }
void HairLibrary::SetHairGlobal(BaseDocument* doc, Bool enable) { HairObjectLibCall(hairSetHairGlobal) (doc, enable); }
Vector HairLibrary::BlendColors(Int32 mode, const Vector& colA, const Vector& colB) { HairObjectLibCallR(Vector(0.0), hairBlendColors) (mode, colA, colB); }
Vector HairLibrary::MixST(Float s, Float t, const Vector& pa, const Vector& pb, const Vector& pc, const Vector& pd, Bool bQuad) { HairObjectLibCallR(Vector(0.0), hairMixST) (s, t, pa, pb, pc, pd, bQuad); }
Float HairLibrary::MixST(Float s, Float t, Float va, Float vb, Float vc, Float vd, Bool bQuad) { HairObjectLibCallR(0, hairMixSTReal) (s, t, va, vb, vc, vd, bQuad); }
void HairLibrary::GetPolyPointST(const Vector& p, Float& s, Float& t, const Vector& pa, const Vector& pb, const Vector& pc, const Vector& pd, Bool bQuad) { HairObjectLibCall(hairGetPolyPointST) (p, s, t, pa, pb, pc, pd, bQuad); }
void* HairLibrary::GetHook(BaseDocument* doc, Int32 type) { HairObjectLibCallR(nullptr, hairGetHook) (doc, type); }
void* HairLibrary::SetHook(BaseDocument* doc, Int32 type, void* fn) { HairObjectLibCallR(nullptr, hairSetHook) (doc, type, fn); }
BaseContainer* HairLibrary::GetPrefsInstance() { HairObjectLibCallR(nullptr, hairGetPrefsInstance) (); }
Int32 HairLibrary::GetHairVersion() { HairObjectLibCallR(0, hairGetHairVersion) (); }

//////////////////////////////////////////////////////////////////////////

Bool HairSelectionTag::GetSelected(BaseSelect* bs) { HairObjectLibCallR(false, HairSelectionGetSelected) (this, bs); }
Bool HairSelectionTag::SetSelected(BaseSelect* bs) { HairObjectLibCallR(false, HairSelectionSetSelected) (this, bs); }
Int32 HairSelectionTag::GetSelectionType() { HairObjectLibCallR(0, HairSelectionGetType) (this); }
void HairSelectionTag::SetSelectionType(Int32 mode) { HairObjectLibCall(HairSelectionSetType) (this, mode); }
Int32 HairSelectionTag::GetCount() { HairObjectLibCallR(0, HairSelectionGetCount) (this); }
Int32 HairSelectionTag::GetSegments() { HairObjectLibCallR(0, HairSelectionGetSegments) (this); }

//////////////////////////////////////////////////////////////////////////

Int32 HairVertexMapTag::GetCount() { HairObjectLibCallR(0, HairVertexGetCount) (this); }
Int32 HairVertexMapTag::GetSegments() { HairObjectLibCallR(0, HairVertexGetSegments) (this); }
Int32 HairVertexMapTag::GetPointCount() { HairObjectLibCallR(0, HairVertexGetPointCount) (this); }
UInt16* HairVertexMapTag::GetMap() { HairObjectLibCallR(nullptr, HairVertexGetMap) (this); }

//////////////////////////////////////////////////////////////////////////

Int32 HairTangentTag::GetPolygonsSegments() { HairObjectLibCallR(0, HairTangentGetPolygonsSegments) (this); }
Int32 HairTangentTag::GetPointCount() { HairObjectLibCallR(0, HairTangentGetPointCount) (this); }
Int32 HairTangentTag::GetCount() { HairObjectLibCallR(0, HairTangentGetCount) (this); }
Int32 HairTangentTag::GetSegments() { HairObjectLibCallR(0, HairTangentGetSegments) (this); }
Vector* HairTangentTag::GetTangent() { HairObjectLibCallR(nullptr, HairTangentGetTangent) (this); }

//////////////////////////////////////////////////////////////////////////

Int32 HairMaterialData::GetCount() { HairObjectLibCallR(0, matGetCount) (this); }
Int32 HairMaterialData::GetGuideMaterial(Int32 i, Int32 prev) { HairObjectLibCallR(NOTOK, matGetGuideMaterial) (this, i, prev); }
BaseTag* HairMaterialData::GetMaterialTag(Int32 i) { HairObjectLibCallR(nullptr, matGetMaterialTag) (this, i); }
Bool HairMaterialData::ApplyMaterial(Int32 i, HairGuides* guides, VolumeData* vd, Int32 vindex) { HairObjectLibCallR(false, matApplyMaterial) (this, i, guides, vd, vindex); }
Bool HairMaterialData::ApplyMaterials(HairGuides* guides, VolumeData* vd, Int32 vindex) { HairObjectLibCallR(false, matApplyMaterials) (this, guides, vd, vindex); }
Float HairMaterialData::GetThickness(Int32 guide, Float t, Int32 i) { HairObjectLibCallR(0.0, matGetThickness) (this, guide, t, i); }
Vector HairMaterialData::GetColor(Int32 guide, Float t, const Vector& r, const Vector& wp, const Vector& p, const Vector& n, VolumeData* vd, const RayHitID& plyid, Int32 i) { HairObjectLibCallR(Vector(0.0), matGetColor) (this, guide, t, r, wp, p, n, vd, plyid, i); }
Vector HairMaterialData::GetBackColor(Int32 guide, Float t, const Vector& col, const Vector& r, const Vector& wp, const Vector& p, const Vector& n, VolumeData* vd, const RayHitID& plyid, Int32 i) { HairObjectLibCallR(Vector(0.0), matGetBackColor) (this, guide, t, col, r, wp, p, n, vd, plyid, i); }
Bool HairMaterialData::GetSpecularColor(Int32 guide, Float t, const Vector& wp, const Vector& p, const Vector& n, VolumeData* vd, const RayHitID& plyid, Vector& speccol, Vector& ispeccol) { HairObjectLibCallR(false, matGetSpecularColor) (this, guide, t, wp, p, n, vd, plyid, speccol, ispeccol); }
Float HairMaterialData::GetTransparency(Int32 guide, Float t, const Vector& p, const Vector& n, VolumeData* vd, Int32 i) { HairObjectLibCallR(0.0, matGetTransparency) (this, guide, t, p, n, vd, i); }
Bool HairMaterialData::GetTagSelection(Int32 i, BaseSelect* bs) { HairObjectLibCallR(false, matGetTagSelection) (this, i, bs); }
Bool HairMaterialData::GetMaterialData(Int32 guide, Float& shadows, Float& selfshadows, Float& backshadows, Float& transparency, Float& diffuse, Float& reflect, Float& transmit, Bool& roughenable, Float& roughvar, Float& roughness, Bool& specularenable, Float& specular, Float& specularpower, Float& specularback, Bool& ispecularenable, Bool& ispecularshader, Float& ispecular, Float& ispecularpower, Float& ispecularmix, Float& ispecularblend) { HairObjectLibCallR(false, matGetMaterialData) (this, guide, shadows, selfshadows, backshadows, transparency, diffuse, reflect, transmit, roughenable, roughvar, roughness, specularenable, specular, specularpower, specularback, ispecularenable, ispecularshader, ispecular, ispecularpower, ispecularmix, ispecularblend); }
Bool HairMaterialData::GetGIData(Int32 guide, Bool& receive, Float& strength) { HairObjectLibCallR(false, matGetGIData) (this, guide, receive, strength); }
Bool HairMaterialData::AdjustHUV(Int32 guide, Vector& huv, Float tline) { HairObjectLibCallR(false, matAdjustHUV) (this, guide, huv, tline); }

//////////////////////////////////////////////////////////////////////////

Int32 HairVideoPost::GetObjectCount() { HairObjectLibCallR(0, vpGetObjectCount) (this); }
void HairVideoPost::GetObject(Int32 i, HairRenderObject* hro) { HairObjectLibCall(vpGetObject) (this, i, hro); }
Int32 HairVideoPost::FindObject(BaseList2D* bl) { HairObjectLibCallR(NOTOK, vpFindObject) (this, bl); }

UInt32 HairVideoPost::GetCompositeFlags(Int32 oindex) { HairObjectLibCallR(0, vpGetCompositeFlags) (this, oindex); }

void HairVideoPost::Sample(Int32 oindex, VolumeData* vd, Int32 cpu, Int32 lid, Int32 seg, Int32 p, Float lined, const Vector& linep, const Vector& v, Vector& col, const Vector& n, const Vector& lp, const Vector& t, const Vector& r, Vector huv, Int32 flags) { HairObjectLibCall(vpSample) (this, oindex, vd, cpu, lid, seg, p, lined, linep, v, col, n, lp, t, r, huv, flags); }
Float HairVideoPost::SampleTransparency(Int32 oindex, VolumeData* vd, Int32 lid, Int32 seg, Int32 p, Float lined, const Vector& n, const Vector& linep, const Vector& lp, Vector huv, Int32 cpu, Int32 flags, const RayLight* light) { HairObjectLibCallR(1.0, vpSampleTransparency) (this, oindex, vd, lid, seg, p, lined, n, linep, lp, huv, cpu, flags, light); }

//////////////////////////////////////////////////////////////////////////

HairCollider* HairCollider::Alloc()
{
	HairColliderLib* lib = CheckHairColliderLib(LIBOFFSET(HairColliderLib, Alloc));
	if (!lib)
		return nullptr;
	return (HairCollider*)lib->Alloc();
}

void HairCollider::Free(HairCollider*& p)
{
	if (!p)
		return;
	HairColliderLib* lib = CheckHairColliderLib(LIBOFFSET(HairColliderLib, Free));
	if (!lib)
		return;
	iHairCollider* i = (iHairCollider*)p;
	lib->Free(i);
	p = nullptr;
}

Bool HairCollider::Init(HairGuides* hair) { HairColliderLibCallR(false, Init) (hair); }
void HairCollider::Release() { HairColliderLibCall(Release) (); }
Int32 HairCollider::GetClosestPoint(const Vector& p) { HairColliderLibCallR(NOTOK, GetClosestPoint) (p); }
Bool HairCollider::GetParticleIntersection(const Vector& p, const Vector& v, Float r, Int32* guide, Int32* segment, Float* segt, Float* rayt) { HairColliderLibCallR(false, GetParticleIntersection) (p, v, r, guide, segment, segt, rayt); }
Bool HairCollider::GetClosestSegment(const Vector& p, Int32* guide, Int32* segment, Float* segt) { HairColliderLibCallR(false, GetClosestSegment) (p, guide, segment, segt); }

//////////////////////////////////////////////////////////////////////////

Float64 HairInterpolationMap::GetTotalWeight(Int32 index)
{
	if (!m_pMap)
		return 0.0;

	Float64 total = 0.0;
	Int32		i, j = index * m_WeightCount;

	for (i = 0; i < m_WeightCount; i++)
	{
		if (m_pMap[j + i].m_Index == NOTOK)
			continue;
		total += m_pMap[j + i].m_Weight;
	}

	return total;
}

Float64 HairInterpolationMap::GetTotalInvWeight(Int32 index)
{
	if (!m_pMap)
		return 0.0;

	Float64 total = 0.0;
	Int32		i, j = index * m_WeightCount;

	if (m_pMap[j].m_Weight < 2e-4)
		return 1.0;

	for (i = 0; i < m_WeightCount; i++)
	{
		if (m_pMap[j + i].m_Index == NOTOK)
			continue;
		total += 1.0 / m_pMap[j + i].m_Weight;
	}

	return total;
}

Float32 HairInterpolationMap::GetInterpolateReal(Int32 index, Float32* v)
{
	if (!v)
		return 0.0;
	if (!m_pMap)
		return *v;

	Int32 i, j = index * m_WeightCount;

	if (m_pMap[j].m_Weight < 2e-4)
		return *v;

	Float64 total = GetTotalInvWeight(index);
	Float64 rv = 0.0;

	if (total == 0.0)
		return *v;

	for (i = 0; i < m_WeightCount; i++)
	{
		if (m_pMap[j + i].m_Index == NOTOK)
			continue;
		rv += v[i] / m_pMap[j + i].m_Weight;
	}

	return Float32(rv / total);
}

Float64 HairInterpolationMap::GetInterpolateReal(Int32 index, Float64* v)
{
	if (!v)
		return 0.0;
	if (!m_pMap)
		return *v;

	Int32 i, j = index * m_WeightCount;

	if (m_pMap[j].m_Weight < 2e-4)
		return *v;

	Float64 total = GetTotalInvWeight(index);
	Float64 rv = 0.0;

	if (total == 0.0)
		return *v;

	for (i = 0; i < m_WeightCount; i++)
	{
		if (m_pMap[j + i].m_Index == NOTOK)
			continue;
		rv += v[i] / m_pMap[j + i].m_Weight;
	}

	return rv / total;
}

Vector32 HairInterpolationMap::GetInterpolatedVector(Int32 index, Vector32* v)
{
	if (!v)
		return Vector32(0.0);
	if (!m_pMap)
		return *v;

	Int32 i, j = index * m_WeightCount;

	if (m_pMap[j].m_Weight < 2e-4)
		return *v;

	Float64	 total = GetTotalInvWeight(index);
	Vector64 rv = Vector64(0.0);

	if (total == 0.0)
		return *v;

	for (i = 0; i < m_WeightCount; i++)
	{
		if (m_pMap[j + i].m_Index == NOTOK)
			continue;
		rv += (Vector64)v[i] / m_pMap[j + i].m_Weight;
	}

	return (Vector32)(rv / total);
}

Vector64 HairInterpolationMap::GetInterpolatedVector(Int32 index, Vector64* v)
{
	if (!v)
		return Vector64(0.0);
	if (!m_pMap)
		return *v;

	Int32 i, j = index * m_WeightCount;

	if (m_pMap[j].m_Weight < 2e-4)
		return *v;

	Float64	 total = GetTotalInvWeight(index);
	Vector64 rv = Vector64(0.0);

	if (total == 0.0)
		return *v;

	for (i = 0; i < m_WeightCount; i++)
	{
		if (m_pMap[j + i].m_Index == NOTOK)
			continue;
		rv += v[i] / m_pMap[j + i].m_Weight;
	}

	return rv / total;
}
