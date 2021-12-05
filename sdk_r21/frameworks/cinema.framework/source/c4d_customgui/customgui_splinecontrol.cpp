#include "customgui_splinecontrol.h"
#include "c4d_string.h"
#include "c4d_gui.h"


static CustomGuiSplineLib *lib_SplineControl = nullptr;


static CustomGuiSplineLib *CheckCustomGuiSplineLib(Int32 offset)
{
	return (CustomGuiSplineLib*)CheckLib(CUSTOMGUI_SPLINE, offset, (C4DLibrary**)&lib_SplineControl);
}

#define SplineCall(b)       CustomGuiSplineLib *lib = CheckCustomGuiSplineLib(LIBOFFSET(CustomGuiSplineLib, b)); \
															if (!lib || !lib->b) return; \
															(((iSpline*)this)->*lib->b)

#define SplineCallR(a, b)     CustomGuiSplineLib *lib = CheckCustomGuiSplineLib(LIBOFFSET(CustomGuiSplineLib, b)); \
															if (!lib || !lib->b) return a; \
															return (((iSpline*)this)->*lib->b)

#define SplineGuiCall(b)     CustomGuiSplineLib *lib = CheckCustomGuiSplineLib(LIBOFFSET(CustomGuiSplineLib, b)); \
															if (!lib || !lib->b) return; \
															(((iSplineCustomGui*)this)->*lib->b)

#define SplineGuiCallR(a, b) CustomGuiSplineLib *lib = CheckCustomGuiSplineLib(LIBOFFSET(CustomGuiSplineLib, b)); \
															if (!lib || !lib->b) return a; \
															return (((iSplineCustomGui*)this)->*lib->b)


Int32 SplineData::GetKnotCount() const { SplineCallR(-1, GetKnotCount)(); }
CustomSplineKnot* SplineData::GetKnot(Int32 l) { SplineCallR(nullptr, GetKnot)(l); }
Bool SplineData::SetKnot(Int32 l, const CustomSplineKnot& knot) { SplineCallR(false, SetKnot)(l, knot); }
Vector SplineData::GetPoint(Float r) const { SplineCallR(Vector(0, 0, 0), GetPoint)(r); }

void SplineData::DeleteAllPoints() { SplineCall(DeleteAllPoints)(); }
Bool SplineData::MakePointBuffer(Int32 lPoints) { SplineCallR(false, MakePointBuffer)(lPoints); }
Bool SplineData::MakeLinearSplineBezier(Int32 lPoints) { SplineCallR(false, MakeLinearSplineBezier)(lPoints); }
Bool SplineData::MakeLinearSplineLinear(Int32 lPoints) { SplineCallR(false, MakeLinearSplineLinear)(lPoints); }
Bool SplineData::MakeSquareSpline(Int32 lPoints) { SplineCallR(false, MakeSquareSpline)(lPoints); }
Bool SplineData::MakeCubicSpline(Int32 lPoints) { SplineCallR(false, MakeCubicSpline)(lPoints); }
Bool SplineData::MakeRootSpline(Int32 lPoints) { SplineCallR(false, MakeRootSpline)(lPoints); }
Bool SplineData::MakeInversSpline(Int32 lPoints) { SplineCallR(false, MakeInversSpline)(lPoints); }
Bool SplineData::MakeSinSpline(Int32 lPoints) { SplineCallR(false, MakeSinSpline)(lPoints); }
Bool SplineData::MakeAbsCosSpline(Int32 lPoints) { SplineCallR(false, MakeAbsCosSpline)(lPoints); }
Bool SplineData::MakeUserSpline(const maxon::String &str, Int32 lPoints) { SplineCallR(false, MakeUserSpline)(str, lPoints); }
void SplineData::SelectAll() { SplineCall(SelectAll)(); }
void SplineData::Flip() { SplineCall(Flip)(); }
void SplineData::Mirror() { SplineCall(Mirror)(); }
void SplineData::Maximum() { SplineCall(Maximum)(); }
void SplineData::Minimum() { SplineCall(Minimum)(); }
void SplineData::SortKnots(Int32 &lActiveKnot) { SplineCall(SortKnots)(lActiveKnot); }
Int32 SplineData::InsertKnot(Float x, Float y, Int32 lFlags) { SplineCallR(-1, InsertKnot)(x, y, lFlags); }
Bool SplineData::DeleteKnot(Int32 a) { SplineCallR(false, DeleteKnot)(a); }
Int32 SplineData::GetSelectCount() const { SplineCallR(0, GetSelectCount)(); }
void SplineData::SetUserCallback(SplineDataCallback fn, void* pData) { SplineCall(SetUserCallback)(fn, pData); }
SplineDataCallback SplineData::GetUserCallback(void *&pData) const { SplineCallR(nullptr, GetUserCallback)(pData); }

Bool SplineData::SetZero(Bool bY, Bool bAll) { SplineCallR(false, SetZero)(bY, bAll); }
Bool SplineData::SetType(Int32 id, Bool bAll) { SplineCallR(false, SetType)(id, bAll); }
Bool SplineData::InitDefaultFlag(Int32 flag) { SplineCallR(false, InitDefaultFlag)(flag); }
Bool SplineData::CopyTo(SplineData* pDest) { SplineCallR(false, CopyTo)(pDest); }

void SplineData::SetTension(Float tension) { SplineCall(SetTension)(tension); }
Float SplineData::GetTension() const { SplineCallR(0.0, GetTension)(); }

SplineData* SplineData::Alloc()
{
	CustomGuiSplineLib *lib = CheckCustomGuiSplineLib(LIBOFFSET(CustomGuiSplineLib, Spline_Alloc));
	if (!lib || !lib->Spline_Alloc) return nullptr;
	return lib->Spline_Alloc();
}

void SplineData::Free(SplineData *&pData)
{
	CustomGuiSplineLib *lib = CheckCustomGuiSplineLib(LIBOFFSET(CustomGuiSplineLib, Spline_Free));
	if (!lib || !lib->Spline_Free) return;
	lib->Spline_Free(pData);
}


SplineControlFunctionTable SplineControlInternalFunctionTable;
SplineControlMessagesF SplineControlFunctions;

void SplineCustomGui::SetMessageFunctions(SplineControlMessages* pFuncs)
{
	CustomGuiSplineLib *lib = CheckCustomGuiSplineLib(LIBOFFSET(CustomGuiSplineLib, SetMessageFunctions));
	if (!lib || !lib->SetMessageFunctions) return;

	SplineControlFunctionTable* f = &SplineControlInternalFunctionTable;
	ClearMem(f, sizeof(SplineControlFunctionTable), 0);

	f->KnotMoved = &SplineControlMessagesF::KnotMoved;
	f->KnotInserted = &SplineControlMessagesF::KnotInserted;

	(((iSplineCustomGui*)this)->*lib->SetMessageFunctions)(f, sizeof(SplineControlFunctionTable), &SplineControlFunctions, pFuncs);
}


SplineData* SplineCustomGui::GetSplineData(void) { SplineGuiCallR(nullptr, GetSplineData)(); }
Bool SplineCustomGui::SetSpline(SplineData* pData) { SplineGuiCallR(false, SetSpline)(pData); }
void SplineCustomGui::SetCustomColor(Bool bSet, Vector col) { SplineGuiCall(SetCustomColor)(bSet, col); }
void SplineCustomGui::SetLabelText(maxon::String* strXMin, maxon::String* strXMax, maxon::String* strYMin, maxon::String* strYMax, maxon::String* strX, maxon::String* strY)
	{ SplineGuiCall(SetLabelText)(strXMin, strXMax, strYMin, strYMax, strX, strY); }
void SplineCustomGui::GetScreenPosition(const Vector &v, Int32 &x, Int32 &y) const
	{ SplineGuiCall(GetScreenPosition)(v, x, y); }
void SplineCustomGui::GetValue(const Int32 x, const Int32 y, Vector &v) const
{ SplineGuiCall(GetValue)(x, y, v); }
Bool SplineCustomGui::Command(Int32 id, const BaseContainer &msg)
	{ SplineGuiCallR(false, Command)(id, msg); }
Bool SplineData::GetRange(Float* xmin, Float* xmax, Float* xsteps, Float* ymin, Float* ymax, Float* ysteps) const
	{ SplineCallR(false, GetRange)(xmin, xmax, xsteps, ymin, ymax, ysteps); }

void SplineData::SetRange(Float xmin, Float xmax, Float xsteps, Float ymin, Float ymax, Float ysteps)
{ SplineCall(SetRange)(xmin, xmax, xsteps, ymin, ymax, ysteps); }

void SplineData::AdaptRange(Float xmin, Float xmax, Float xsteps, Float ymin, Float ymax, Float ysteps)
{ SplineCall(AdaptRange)(xmin, xmax, xsteps, ymin, ymax, ysteps); }

Bool CustomSplineKnot::operator == (CustomSplineKnot& k)
{
	return vPos == k.vPos /*&& lFlagsOld == k.lFlagsOld*/ && bSelect == k.bSelect
		&& vTangentLeft == k.vTangentLeft && vTangentRight == k.vTangentRight && lFlagsSettings == k.lFlagsSettings;
}

Bool CustomSplineKnot::operator != (CustomSplineKnot& k)
{
	return !(*this == k);
}

// version 0 functions
void SplineControlMessagesF::KnotMoved(SplineControlMessages* pFuncs, Float x, Float y)
{
	pFuncs->KnotMoved(x, y);
}

void SplineControlMessagesF::KnotInserted(SplineControlMessages* pFuncs, Int32 lKnot, Float x, Float y)
{
	pFuncs->KnotInserted(lKnot, x, y);
}
