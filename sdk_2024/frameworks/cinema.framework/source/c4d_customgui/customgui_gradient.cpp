#include "customgui_gradient.h"
#include "c4d_gui.h"

#ifdef CINEWARE_NAMESPACE_ENABLE
	CINEWARE_NAMESPACE_BEGIN
#endif

static CustomGuiGradientLib *lib_gradient = nullptr;

static CustomGuiGradientLib *CheckGradientLib(Int32 offset)
{
	return CheckLib<CustomGuiGradientLib>(CUSTOMGUI_GRADIENT, offset, lib_gradient);
}

#define GradientCall(b) 			CustomGuiGradientLib *lib = CheckGradientLib(LIBOFFSET(CustomGuiGradientLib, b)); \
															if (!lib || !lib->b) return; \
															(reinterpret_cast<iGradient*>(this)->*lib->b)

#define GradientCallC(b) 			CustomGuiGradientLib *lib = CheckGradientLib(LIBOFFSET(CustomGuiGradientLib, b)); \
															if (!lib || !lib->b) return; \
															(reinterpret_cast<const iGradient*>(this)->*lib->b)

#define GradientCallR(a, b) 		CustomGuiGradientLib *lib = CheckGradientLib(LIBOFFSET(CustomGuiGradientLib, b)); \
															if (!lib || !lib->b) return a; \
															return (reinterpret_cast<iGradient*>(this)->*lib->b)

#define GradientCallRC(a, b) 		CustomGuiGradientLib *lib = CheckGradientLib(LIBOFFSET(CustomGuiGradientLib, b)); \
															if (!lib || !lib->b) return a; \
															return (reinterpret_cast<const iGradient*>(this)->*lib->b)

#define GradientGuiCall(b) 		CustomGuiGradientLib *lib = CheckGradientLib(LIBOFFSET(CustomGuiGradientLib, b)); \
															if (!lib || !lib->b) return; \
															(reinterpret_cast<iGradientCustomGui*>(this)->*lib->b)

#define GradientGuiCallR(a, b) CustomGuiGradientLib *lib = CheckGradientLib(LIBOFFSET(CustomGuiGradientLib, b)); \
															if (!lib || !lib->b) return a; \
															return (reinterpret_cast<iGradientCustomGui*>(this)->*lib->b)

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

maxon::Result<maxon::GradientRenderData> Gradient::PrepareRenderData(const InitRenderStruct &irs) const
{
	GradientCallRC(maxon::UnexpectedError(MAXON_SOURCE_LOCATION, "Gradient::PrepareRenderData() not found."_s), PrepareRenderData)(irs);
}

maxon::Result<GradientRenderDataTuple> Gradient::PrepareRenderDataWithAlpha(const InitRenderStruct &irs) const
{
	GradientCallRC(maxon::UnexpectedError(MAXON_SOURCE_LOCATION, "Gradient::PrepareRenderDataWithAlpha() not found."_s), PrepareRenderDataWithAlpha)(irs);
}

Int32 Gradient::GetKnotCount() const
{
	GradientCallRC(0, GetKnotCount)();
}

Int32 Gradient::InsertKnot(const maxon::GradientKnot &knot)
{
	GradientCallR(NOTOK, InsertKnot)(knot);
}

Bool Gradient::RemoveKnot(Int32 index)
{
	GradientCallR(false, RemoveKnot)(index);
}

maxon::GradientKnot Gradient::GetKnot(Int32 index) const
{
	GradientCallRC(maxon::GradientKnot(), GetKnot)(index);
}

void Gradient::SetKnot(Int32 index, const maxon::GradientKnot &k)
{
	GradientCall(SetKnot)(index, k);
}

GeData Gradient::GetData(Int32 id) const
{
	GradientCallRC(GeData(), iGetData)(id);
}

Bool Gradient::SetData(Int32 id, const GeData &data)
{
	GradientCallR(false, iSetData)(id, data);
}

Gradient* Gradient::GetAlphaGradient()
{
	GradientCallR(nullptr, GetAlphaGradient)();
}

const Gradient* Gradient::GetAlphaGradient() const
{
	return MAXON_REMOVE_CONST(this)->GetAlphaGradient();
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
	GradientCallRC(0, GetChecksum)();
}

void Gradient::GetGradient(maxon::Gradient& gradient) const
{
	GradientCallC(GetInternalGradient)(gradient);
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
	return (reinterpret_cast<iGradient*>(this)->*lib->CopyFrom)(src);
}

void Gradient::ConvertToAlphaGradient(BaseContainer* bc, Int32 id)
{
	GeData data = bc->GetData(id);
	Gradient* gradient = data.GetCustomDataTypeWritable<Gradient>();
	if (gradient)
		return;
	gradient->ConvertToAlphaGradient();
	bc->SetData(id, std::move(data));
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

#ifdef CINEWARE_NAMESPACE_ENABLE
	CINEWARE_NAMESPACE_END
#endif
