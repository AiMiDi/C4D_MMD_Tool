#include "lib_birender.h"
#include "c4d_objectdata.h"
#include "c4d_scenehookplugin.h"
#include "c4d_tools.h"
#include "c4d_basedocument.h"

BiRenderLib *lib_birender = nullptr;

static BiRenderLib *CheckBiRenderLib(Int32 offset)
{
	return (BiRenderLib*)CheckLib(LIBRARY_BIRENDER, offset, (C4DLibrary**)&lib_birender);
}

#define BiRenderLibCall(b) 	BiRenderLib *lib = CheckBiRenderLib(LIBOFFSET(BiRenderLib, b)); \
															if (!lib || !lib->b) return; \
															(lib->b)

#define BiRenderLibCallR(a, b)  BiRenderLib *lib = CheckBiRenderLib(LIBOFFSET(BiRenderLib, b)); \
															if (!lib || !lib->b) return a; \
															return (lib->b)

// BiRenderObject

Int32 BiRenderObject::GetVertexCount() { BiRenderLibCallR(0, biopGetVertexCount)(this); }
Vector *BiRenderObject::GetVertices() { BiRenderLibCallR(nullptr, biopGetVertices)(this); }
Int32 BiRenderObject::GetCurveCount() { BiRenderLibCallR(0, biopGetCurveCount)(this); }
Bool BiRenderObject::SetCurveCount(Int32 curvecount, Int32 segmentcount, const birender::Segment* segments, const Vector *vertices, const Float32 *thickness, birender::SETCURVE_FLAGS flags) { BiRenderLibCallR(false, biopSetCurveCount)(this, curvecount, segmentcount, segments, vertices, thickness, flags); }
Int32 BiRenderObject::GetSegmentCount() { BiRenderLibCallR(0, biopGetSegmentCount)(this); }
birender::Segment *BiRenderObject::GetSegments() { BiRenderLibCallR(nullptr, biopGetSegments)(this); }
Float32 *BiRenderObject::GetThickness() { BiRenderLibCallR(nullptr, biopGetThickness)(this); }
birender::INTERPOLATION_TYPE BiRenderObject::GetInterpolation() { BiRenderLibCallR(birender::INTERPOLATION_TYPE::NONE, biopGetInterpolation)(this); }
void BiRenderObject::SetInterpolation(birender::INTERPOLATION_TYPE itype) { BiRenderLibCall(biopSetInterpolation)(this, itype); }
birender::COORD_SPACE BiRenderObject::GetCoordSpace() { BiRenderLibCallR(birender::COORD_SPACE::NONE, biopGetCoordSpace)(this); }
Bool BiRenderObject::SetCoordSpace(birender::COORD_SPACE coord, BiRenderVideoPost *bipost) { BiRenderLibCallR(false, biopSetCoordSpace)(this, coord, bipost); }
birender::JOINT_TYPE BiRenderObject::GetJointType() { BiRenderLibCallR(birender::JOINT_TYPE::NONE, biopGetJointType)(this); }
void BiRenderObject::SetJointType(birender::JOINT_TYPE jtype) { BiRenderLibCall(biopSetJointType)(this, jtype); }
birender::CAP_TYPE BiRenderObject::GetStartCapType() { BiRenderLibCallR(birender::CAP_TYPE::NONE, biopGetStartCapType)(this); }
void BiRenderObject::SetStartCapType(birender::CAP_TYPE ctype) { BiRenderLibCall(biopSetStartCapType)(this, ctype); }
void BiRenderObject::SetMiterLimit(Float theta) { BiRenderLibCall(biopSetMiterLimit)(this, theta); }
void BiRenderObject::SetStartCapSize(Float capw, Float caph) { BiRenderLibCall(biopSetStartCapSize)(this, capw, caph); }
Vector BiRenderObject::GetStartCapSize() { BiRenderLibCallR(Vector(), biopGetStartCapSize)(this); }
void BiRenderObject::SetShadingCallback(birender::ShadingCallback* callback, birender::CallbackData* calldata) { BiRenderLibCall(biopSetShadingCallback)(this, callback, calldata); }
void BiRenderObject::SetRenderCallback(birender::RenderCallback* callback, birender::CallbackData* calldata) { BiRenderLibCall(biopSetRenderCallback)(this, callback, calldata); }
birender::OBJECT_FLAG BiRenderObject::GetFlags() { BiRenderLibCallR(birender::OBJECT_FLAG::NONE, biopGetFlags)(this); }
void BiRenderObject::SetFlags(birender::OBJECT_FLAG flags, birender::FLAG_STATE state) { BiRenderLibCall(biopSetFlags)(this, flags, state); }
birender::BLEND_MODE BiRenderObject::GetBlend() { BiRenderLibCallR(birender::BLEND_MODE::NONE, biopGetBlend)(this); }
birender::BLEND_MODE BiRenderObject::GetSelfBlend() { BiRenderLibCallR(birender::BLEND_MODE::NONE, biopGetSelfBlend)(this); }
void BiRenderObject::SetBlend(birender::BLEND_MODE mode) { BiRenderLibCall(biopSetBlend)(this, mode); }
void BiRenderObject::SetSelfBlend(birender::BLEND_MODE mode) { BiRenderLibCall(biopSetSelfBlend)(this, mode); }
void BiRenderObject::SetRayObject(const RayObject *rayObject) { BiRenderLibCall(biopSetRayObject)(this, rayObject); }
const RayObject* BiRenderObject::GetRayObject() { BiRenderLibCallR(nullptr, biopGetRayObject)(this); }
void BiRenderObject::Sample(birender::LineRenderData& lineData, VolumeData* voldata, BiRenderVideoPost* bipost, Vector32* pxCol, Float32* pxAlpha, Int32 cpuIndex) { BiRenderLibCall(biopSample)(this, lineData, voldata, bipost, pxCol, pxAlpha, cpuIndex); }
void BiRenderObject::SetObject(BaseList2D *object) { BiRenderLibCall(biopSetObject)(this, object); }
BaseList2D *BiRenderObject::GetObject(BaseDocument *doc) { BiRenderLibCallR(nullptr, biopGetObject)(this, doc); }
birender::CAP_TYPE BiRenderObject::GetEndCapType() { BiRenderLibCallR(birender::CAP_TYPE::NONE, biopGetEndCapType)(this); }
void BiRenderObject::SetEndCapType(birender::CAP_TYPE ctype) { BiRenderLibCall(biopSetEndCapType)(this, ctype); }
void BiRenderObject::SetEndCapSize(Float capw, Float caph) { BiRenderLibCall(biopSetEndCapSize)(this, capw, caph); }
Vector BiRenderObject::GetEndCapSize() { BiRenderLibCallR(Vector(), biopGetEndCapSize)(this); }
Float BiRenderObject::GetMiterLimit() { BiRenderLibCallR(0.0, biopGetMiterLimit)(this); }
void BiRenderObject::SetStartCapCustom(BaseShader *shader) { BiRenderLibCall(biopSetStartCapCustom)(this, shader); }
void BiRenderObject::SetEndCapCustom(BaseShader *shader) { BiRenderLibCall(biopSetEndCapCustom)(this, shader); }
void BiRenderObject::SetOwner(Int32 id) { BiRenderLibCall(biopSetOwner)(this, id); }
Int32 BiRenderObject::GetOwner() { BiRenderLibCallR(NOTOK, biopGetOwner)(this); }

// BiRenderLib

BiRenderObject *BiRenderVideoPost::Append() { BiRenderLibCallR(nullptr, bivpAppend)(this); }
Bool BiRenderVideoPost::RemoveObject(Int32 index) { BiRenderLibCallR(false, bivpRemove)(this, index); }
void BiRenderVideoPost::Flush() { BiRenderLibCall(bivpFlush)(this); }
Int32 BiRenderVideoPost::GetCount() { BiRenderLibCallR(0, bivpGetCount)(this); }
BiRenderObject *BiRenderVideoPost::GetObject(Int32 index) { BiRenderLibCallR(nullptr, bivpGetObject)(this, index); }
Float BiRenderVideoPost::GetAAWidth() { BiRenderLibCallR(0.0, bivpGetAAWidth)(this); }
void BiRenderVideoPost::SetAAWidth(Float aaw) { BiRenderLibCall(bivpSetAAWidth)(this, aaw); }
birender::RENDER_TYPE BiRenderVideoPost::GetRenderer() { BiRenderLibCallR(birender::RENDER_TYPE::NONE, bivpGetRenderer)(this); }
void BiRenderVideoPost::SetRenderer(birender::RENDER_TYPE type) { BiRenderLibCall(bivpSetRenderer)(this, type); }
birender::RENDER_FLAG BiRenderVideoPost::GetFlags() { BiRenderLibCallR(birender::RENDER_FLAG::NONE, bivpGetFlags)(this); }
void BiRenderVideoPost::SetFlags(birender::RENDER_FLAG flags, birender::FLAG_STATE state) { BiRenderLibCall(bivpSetFlags)(this, flags, state); }
Vector BiRenderVideoPost::CalcShadow(const RayLight* light, VolumeData *volData, Int32 cpuIndex, const Vector &p, const Vector &n, const Vector &rayv, Float delta) { BiRenderLibCallR(Vector(), bivpCalcShadow)(this, light, volData, cpuIndex, p, n, rayv, delta); }
void BiRenderVideoPost::SetShadow(birender::SHADOW_TYPE type, Float transDelta, Float distDelta, Int32 resolution, Int32 samples, Float aa) { BiRenderLibCall(bivpSetShadow)(this, type, transDelta, distDelta, resolution, samples, aa); }
Int32 BiRenderVideoPost::AddBuffer(const String &name, birender::MPBUFFER_FLAGS flags, Int32 vpID) { BiRenderLibCallR(NOTOK, bivpAddBuffer)(this, name, flags, vpID); }
void BiRenderVideoPost::SetShadowState(Int32 cpuIndex, bool enabled) { BiRenderLibCall(bivpSetShadowState)(this, cpuIndex, enabled); }

BiRenderVideoPost *BiRenderVideoPost::GetVideoPost(BaseDocument *doc)
{
	RenderData *renderData = doc->GetActiveRenderData();
	if (renderData == nullptr)
		return nullptr;

	BaseVideoPost *vpNode = renderData->GetFirstVideoPost();
	while (vpNode != nullptr)
	{
		if (vpNode->GetType() == VPbirender)
			return static_cast<BiRenderVideoPost*>(vpNode);

		vpNode = vpNode->GetNext();
	}

	return nullptr;
}

BiRenderVideoPost *BiRenderVideoPost::GetVideoPost(VolumeData *vd)
{
	if (vd == nullptr)
		return nullptr;

	BaseVideoPost *vpNode = (BaseVideoPost*)vd->FindVideoPost(VPbirender);
	if (vpNode == nullptr)
		return nullptr;

	return static_cast<BiRenderVideoPost*>(vpNode);
}
