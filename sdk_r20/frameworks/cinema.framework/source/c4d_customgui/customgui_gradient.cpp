#include "customgui_gradient.h"
#include "c4d_gui.h"

static CustomGuiGradientLib *lib_gradient = nullptr;

static CustomGuiGradientLib *CheckGradientLib(Int32 offset)
{
	return (CustomGuiGradientLib*)CheckLib(CUSTOMGUI_GRADIENT, offset, (C4DLibrary**)&lib_gradient);
}

#define GradientCall(b) 			CustomGuiGradientLib *lib = CheckGradientLib(LIBOFFSET(CustomGuiGradientLib, b)); \
															if (!lib || !lib->b) return; \
															(((iGradient*)this)->*lib->b)

#define GradientCallR(a, b) 		CustomGuiGradientLib *lib = CheckGradientLib(LIBOFFSET(CustomGuiGradientLib, b)); \
															if (!lib || !lib->b) return a; \
															return (((iGradient*)this)->*lib->b)

#define GradientGuiCall(b) 		CustomGuiGradientLib *lib = CheckGradientLib(LIBOFFSET(CustomGuiGradientLib, b)); \
															if (!lib || !lib->b) return; \
															(((iGradientCustomGui*)this)->*lib->b)

#define GradientGuiCallR(a, b) CustomGuiGradientLib *lib = CheckGradientLib(LIBOFFSET(CustomGuiGradientLib, b)); \
															if (!lib || !lib->b) return a; \
															return (((iGradientCustomGui*)this)->*lib->b)

Bool Gradient::InvertKnots()
{
	GradientCallR(false, InvertKnots)();
}

Bool Gradient::DoubleKnots()
{
	GradientCallR(false, DoubleKnots)();
}

Bool Gradient::DistributeKnots()
{
	GradientCallR(false, DistributeKnots)();
}

void Gradient::FlushKnots()
{
	GradientCall(FlushKnots)();
}

maxon::Result<void> Gradient::InitRender(const InitRenderStruct &irs)
{
	GradientCallR(maxon::UnexpectedError(MAXON_SOURCE_LOCATION, "Gradient::InitRender() not found."_s), InitRender)(irs);
}

void Gradient::FreeRender()
{
	GradientCall(FreeRender)();
}

Vector Gradient::CalcGradientPixel(Float pos) const
{
	GradientCallR(Vector(0.0), CalcGradientPixel)(pos);
}

Int32 Gradient::GetKnotCount() const
{
	GradientCallR(0, GetKnotCount)();
}

Int32 Gradient::GetRenderKnotCount() const
{
	GradientCallR(0, GetRenderKnotCount)();
}

Int32 Gradient::InsertKnot(const GradientKnot &knot)
{
	GradientCallR(NOTOK, InsertKnot)(knot);
}

Bool Gradient::RemoveKnot(Int32 index)
{
	GradientCallR(false, RemoveKnot)(index);
}

const GradientKnot *Gradient::GetRenderKnot(Int32 index) const
{
	GradientCallR(nullptr, GetRenderKnot)(index);
}

GradientKnot Gradient::GetKnot(Int32 index) const
{
	GradientCallR(GradientKnot(), GetKnot)(index);
}

void Gradient::SetKnot(Int32 index, const GradientKnot &k)
{
	GradientCall(SetKnot)(index, k);
}

GeData Gradient::GetData(Int32 id) const
{
	GradientCallR(GeData(), iGetData)(id);
}

Bool Gradient::SetData(Int32 id, const GeData &data)
{
	GradientCallR(false, iSetData)(id, data);
}

Gradient* Gradient::GetAlphaGradient()
{
	GradientCallR(nullptr, GetAlphaGradient)();
}

Gradient* Gradient::AllocAlphaGradient()
{
	GradientCallR(nullptr, AllocAlphaGradient)();
}

Gradient *Gradient::Alloc()
{
	CustomGuiGradientLib *lib = CheckGradientLib(LIBOFFSET(CustomGuiGradientLib, AllocGradient));
	if (!lib || !lib->AllocGradient) return nullptr;
	return lib->AllocGradient();
}

void Gradient::Free(Gradient *&grad)
{
	CustomGuiGradientLib *lib = CheckGradientLib(LIBOFFSET(CustomGuiGradientLib, FreeGradient));
	if (lib && lib->FreeGradient) lib->FreeGradient(grad);
	grad = nullptr;
}

UInt32 Gradient::GetChecksum() const
{
	GradientCallR(0, GetChecksum)();
}

void Gradient::GetGradient(maxon::Gradient& gradient) const
{
	GradientCall(GetInternalGradient)(gradient);
}

void Gradient::SetGradient(maxon::Gradient& gradient)
{
	GradientCall(SetInternalGradient)(gradient);
}

void Gradient::ConvertToAlphaGradient()
{
	GradientCall(ConvertToAlphaGradient)();
}

Bool Gradient::CopyFrom(const Gradient *src)
{
	CustomGuiGradientLib *lib = CheckGradientLib(LIBOFFSET(CustomGuiGradientLib, CopyFrom));
	if (!lib || !lib->CopyFrom) return false;
	return (((iGradient*)this)->*lib->CopyFrom)(src);
}

void Gradient::ConvertToAlphaGradient(BaseContainer* bc, Int32 id)
{
	Gradient* pGradient = (Gradient*)bc->GetCustomDataType(id, CUSTOMDATATYPE_GRADIENT);
	if (pGradient)
		pGradient->ConvertToAlphaGradient();
}

Gradient* GradientCustomGui::GetGradient()
{
	GradientGuiCallR(nullptr, GetGradient)();
}

Bool GradientCustomGui::SetGradient(Gradient *grad)
{
	GradientGuiCallR(false, SetGradient)(grad);
}

maxon::Result<maxon::BaseArray<Int32>> GradientCustomGui::GetActiveKnots(Bool bias)
{
	GradientGuiCallR(maxon::UnexpectedError(MAXON_SOURCE_LOCATION, "GradientCustomGui::GetActiveKnots() not found."_s), GetActiveKnots)(bias);
}

maxon::Result<void> GradientCustomGui::SetActiveKnots(const maxon::BaseArray<Int32>& activeIndexList, Bool bias, Bool addToSelection)
{
	GradientGuiCallR(maxon::UnexpectedError(MAXON_SOURCE_LOCATION, "GradientCustomGui::SetActiveKnots() not found."_s), SetActiveKnots)(activeIndexList, bias, addToSelection);
}
