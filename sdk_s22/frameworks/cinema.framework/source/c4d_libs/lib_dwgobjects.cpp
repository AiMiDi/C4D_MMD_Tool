#include "c4d_library.h"
#include "lib_dwgobjects.h"

DWGObjectsLib* lib_dwg = nullptr;

static DWGObjectsLib *CheckLibI(Int32 offset)
{
	return (DWGObjectsLib*)CheckLib(DWGOBJECTS_LIB, offset, (C4DLibrary**)&lib_dwg);
}

#define DWGObjectsLibCall(b) 		DWGObjectsLib *lib = CheckLibI(LIBOFFSET(DWGObjectsLib, b)); \
	if (!lib || !lib->b) return; \
	(((RijndaelCipher*)this)->*lib->b)

#define DWGObjectsLibCallR(a, b)  DWGObjectsLib *lib = CheckLibI(LIBOFFSET(DWGObjectsLib, b)); \
	if (!lib || !lib->b) return a; \
	return (((RijndaelCipher*)this)->*lib->b)


xBaseCurveData* xBaseCurveClass::AllocCurve(Int32 type)
{
	DWGObjectsLib *lib = CheckLibI(LIBOFFSET(DWGObjectsLib, AllocCurve)); if (!lib) return nullptr;
	return (this->*lib->AllocCurve)(type);
}

Bool xBaseCurveClass::Update(GeListNode *node)
{
	DWGObjectsLib *lib = CheckLibI(LIBOFFSET(DWGObjectsLib, Update)); if (!lib) return false;
	return (this->*lib->Update)(node);
}

Int32 xBaseCurveClass::GetSubDivision()
{
	DWGObjectsLib *lib = CheckLibI(LIBOFFSET(DWGObjectsLib, GetSubDivision)); if (!lib) return 0;
	return (this->*lib->GetSubDivision)();
}

void xBaseCurveClass::SetSubDivision(Int32 subdiv)
{
	DWGObjectsLib *lib = CheckLibI(LIBOFFSET(DWGObjectsLib, SetSubDivision)); if (!lib) return;
	(this->*lib->SetSubDivision)(subdiv);
}

void xBaseGeometryData::Initialize(GeListNode *node)
{
	DWGObjectsLib *lib = CheckLibI(LIBOFFSET(DWGObjectsLib, Initialize)); if (!lib) return;
	(this->*lib->Initialize)(node);
}

void xLineCurveData::SetStartPoint(const Vector &v)
{
	DWGObjectsLib *lib = CheckLibI(LIBOFFSET(DWGObjectsLib, SetStartPoint)); if (!lib) return;
	(this->*lib->SetStartPoint)(v);
}

void xLineCurveData::SetEndPoint(const Vector &v)
{
	DWGObjectsLib *lib = CheckLibI(LIBOFFSET(DWGObjectsLib, SetEndPoint)); if (!lib) return;
	(this->*lib->SetEndPoint)(v);
}

void xCircularCurveData::SetCenter(Float x, Float y)
{
	DWGObjectsLib *lib = CheckLibI(LIBOFFSET(DWGObjectsLib, SetCenter)); if (!lib) return;
	(this->*lib->SetCenter)(x, y);
}

void xCircularCurveData::SetZValue(Float z)
{
	DWGObjectsLib *lib = CheckLibI(LIBOFFSET(DWGObjectsLib, SetZValue)); if (!lib) return;
	(this->*lib->SetZValue)(z);
}

void xCircularCurveData::SetStartPoint(Float x, Float y)
{
	DWGObjectsLib *lib = CheckLibI(LIBOFFSET(DWGObjectsLib, SetStartPoint2)); if (!lib) return;
	(this->*lib->SetStartPoint2)(x, y);
}

void xCircularCurveData::SetEndPoint(Float x, Float y)
{
	DWGObjectsLib *lib = CheckLibI(LIBOFFSET(DWGObjectsLib, SetEndPoint2)); if (!lib) return;
	(this->*lib->SetEndPoint2)(x, y);
}

void xCircularCurveData::SetIsClockWise(Bool value)
{
	DWGObjectsLib *lib = CheckLibI(LIBOFFSET(DWGObjectsLib, SetIsClockWise)); if (!lib) return;
	(this->*lib->SetIsClockWise)(value);
}

void xConicCurveData::SetZValue(Float z)
{
	DWGObjectsLib *lib = CheckLibI(LIBOFFSET(DWGObjectsLib, SetZValue2)); if (!lib) return;
	(this->*lib->SetZValue2)(z);
}

void xConicCurveData::SetStartPoint(Float x, Float y)
{
	DWGObjectsLib *lib = CheckLibI(LIBOFFSET(DWGObjectsLib, SetStartPoint3)); if (!lib) return;
	(this->*lib->SetStartPoint3)(x, y);
}

void xConicCurveData::SetEndPoint(Float x, Float y)
{
	DWGObjectsLib *lib = CheckLibI(LIBOFFSET(DWGObjectsLib, SetEndPoint3)); if (!lib) return;
	(this->*lib->SetEndPoint3)(x, y);
}

void xConicCurveData::SetCoefficients(const ConicCurveCoeffcients &coeff)
{
	DWGObjectsLib *lib = CheckLibI(LIBOFFSET(DWGObjectsLib, SetCoefficients1)); if (!lib) return;
	(this->*lib->SetCoefficients1)(coeff);
}

void xConicCurveData::SetCoefficients(Float a, Float b, Float c, Float d, Float e, Float f)
{
	DWGObjectsLib *lib = CheckLibI(LIBOFFSET(DWGObjectsLib, SetCoefficients2)); if (!lib) return;
	(this->*lib->SetCoefficients2)(a, b, c, d, e, f);
}

void xNurbsKnots::SetPeriodic(Bool state)
{
	DWGObjectsLib *lib = CheckLibI(LIBOFFSET(DWGObjectsLib, SetPeriodic)); if (!lib) return;
	(this->*lib->SetPeriodic)(state);
}

void xNurbsKnots::Set(Int32 i, Float value)
{
	DWGObjectsLib *lib = CheckLibI(LIBOFFSET(DWGObjectsLib, Set)); if (!lib) return;
	(this->*lib->Set)(i, value);
}

Float xNurbsKnots::GetMinValue(void)
{
	DWGObjectsLib *lib = CheckLibI(LIBOFFSET(DWGObjectsLib, GetMinValue)); if (!lib) return 0.0;
	return (this->*lib->GetMinValue)();
}

Float xNurbsKnots::GetMaxValue(void)
{
	DWGObjectsLib *lib = CheckLibI(LIBOFFSET(DWGObjectsLib, GetMaxValue)); if (!lib) return 0.0;
	return (this->*lib->GetMaxValue)();
}

Bool xNurbsCurveData::ResizeObject(Int32 count, Int32 degree)
{
	DWGObjectsLib *lib = CheckLibI(LIBOFFSET(DWGObjectsLib, ResizeObject4)); if (!lib) return false;
	return (this->*lib->ResizeObject4)(count, degree);
}

void xNurbsCurveData::SetClosed(Bool value)
{
	DWGObjectsLib *lib = CheckLibI(LIBOFFSET(DWGObjectsLib, SetClosed)); if (!lib) return;
	(this->*lib->SetClosed)(value);
}

void xNurbsCurveData::SetPoint(Int32 index, const Vector& position, const Float& weight)
{
	DWGObjectsLib *lib = CheckLibI(LIBOFFSET(DWGObjectsLib, SetPoint)); if (!lib) return;
	(this->*lib->SetPoint)(index, position, weight);
}

xNurbsKnots* xNurbsCurveData::GetKnots()
{
	DWGObjectsLib *lib = CheckLibI(LIBOFFSET(DWGObjectsLib, GetKnots2)); if (!lib) return nullptr;
	return (this->*lib->GetKnots2)();
}

void xNurbsCurveData::SetParameterRange(Float min, Float max)
{
	DWGObjectsLib *lib = CheckLibI(LIBOFFSET(DWGObjectsLib, SetParameterRange)); if (!lib) return;
	(this->*lib->SetParameterRange)(min, max);
}

xBaseSurfaceData*	xBaseSurfaceClass::AllocSurface(Int32 type)
{
	DWGObjectsLib *lib = CheckLibI(LIBOFFSET(DWGObjectsLib, AllocSurface)); if (!lib) return nullptr;
	return (this->*lib->AllocSurface)(type);
}

Bool xBaseSurfaceClass::Update(GeListNode *node)
{
	DWGObjectsLib *lib = CheckLibI(LIBOFFSET(DWGObjectsLib, Update2)); if (!lib) return false;
	return (this->*lib->Update2)(node);
}

void xBaseSurfaceClass::SetSubU(Int32 subu)
{
	DWGObjectsLib *lib = CheckLibI(LIBOFFSET(DWGObjectsLib, SetSubU)); if (!lib) return;
	(this->*lib->SetSubU)(subu);
}

void xBaseSurfaceClass::SetSubV(Int32 subv)
{
	DWGObjectsLib *lib = CheckLibI(LIBOFFSET(DWGObjectsLib, SetSubV)); if (!lib) return;
	(this->*lib->SetSubV)(subv);
}

void xExtrudeSurfaceData::SetDirection(const Vector &v)
{
	DWGObjectsLib *lib = CheckLibI(LIBOFFSET(DWGObjectsLib, SetDirection)); if (!lib) return;
	(this->*lib->SetDirection)(v);
}

void xBaseCurveClass::SetOutput(Int32 output)
{
	DWGObjectsLib *lib = CheckLibI(LIBOFFSET(DWGObjectsLib, SetOutput)); if (!lib) return;
	(this->*lib->SetOutput)(output);
}

void xBaseCurveData::SetPlanar(Bool planar)
{
	DWGObjectsLib *lib = CheckLibI(LIBOFFSET(DWGObjectsLib, SetPlanar)); if (!lib) return;
	(this->*lib->SetPlanar)(planar);
}

void xLineCurveData::SetLimit(Float v)
{
	DWGObjectsLib *lib = CheckLibI(LIBOFFSET(DWGObjectsLib, SetLimit)); if (!lib) return;
	(this->*lib->SetLimit)(v);
}

void xLineCurveData::SetLineType(LineCurveTypeEnum type)
{
	DWGObjectsLib *lib = CheckLibI(LIBOFFSET(DWGObjectsLib, SetLineType)); if (!lib) return;
	(this->*lib->SetLineType)(type);
}

Float xCircularCurveData::GetParameterMax(GeListNode *node)
{
	DWGObjectsLib *lib = CheckLibI(LIBOFFSET(DWGObjectsLib, GetParameterMax)); if (!lib) return 0.0;
	return (this->*lib->GetParameterMax)(node);
}

Float xCircularCurveData::GetParameterMin(GeListNode *node)
{
	DWGObjectsLib *lib = CheckLibI(LIBOFFSET(DWGObjectsLib, GetParameterMin)); if (!lib) return 0.0;
	return (this->*lib->GetParameterMin)(node);
}

Float xNurbsKnots::Get(Int32 i)
{
	DWGObjectsLib *lib = CheckLibI(LIBOFFSET(DWGObjectsLib, Get)); if (!lib) return 0.0;
	return (this->*lib->Get)(i);
}

void xBaseCurvePoint::SetPosition(const Vector &vector)
{
	DWGObjectsLib *lib = CheckLibI(LIBOFFSET(DWGObjectsLib, SetPosition)); if (!lib) return;
	(this->*lib->SetPosition)(vector);
}

static Vector dummyvector;

const Vector &xBaseCurvePoint::GetPosition()
{
	DWGObjectsLib *lib = CheckLibI(LIBOFFSET(DWGObjectsLib, GetPosition)); if (!lib) return dummyvector;
	return (this->*lib->GetPosition)();
}

void xNurbsCurvePoint::SetWeight(Float w)
{
	DWGObjectsLib *lib = CheckLibI(LIBOFFSET(DWGObjectsLib, SetWeight)); if (!lib) return;
	(this->*lib->SetWeight)(w);
}

Float xNurbsCurvePoint::GetWeight()
{
	DWGObjectsLib *lib = CheckLibI(LIBOFFSET(DWGObjectsLib, GetWeight)); if (!lib) return 0.0;
	return (this->*lib->GetWeight)();
}

void xNurbsCurveData::SetPolynomial(Bool value)
{
	DWGObjectsLib *lib = CheckLibI(LIBOFFSET(DWGObjectsLib, SetPolynomial3)); if (!lib) return;
	(this->*lib->SetPolynomial3)(value);
}

xNurbsCurvePoint* xNurbsCurveData::GetPoint(Int32 index)
{
	DWGObjectsLib *lib = CheckLibI(LIBOFFSET(DWGObjectsLib, GetPoint)); if (!lib) return nullptr;
	return (this->*lib->GetPoint)(index);
}

void xBaseSurfaceClass::SetOutput(Int32 output)
{
	DWGObjectsLib *lib = CheckLibI(LIBOFFSET(DWGObjectsLib, SetOutput2)); if (!lib) return;
	(this->*lib->SetOutput2)(output);
}

void xBaseSurfaceClass::SetNormalsActive(Bool normals_active)
{
	DWGObjectsLib *lib = CheckLibI(LIBOFFSET(DWGObjectsLib, SetNormalsActive)); if (!lib) return;
	(this->*lib->SetNormalsActive)(normals_active);
}

void xBaseSurfaceClass::SetNormalsSwap(Bool normals_swap)
{
	DWGObjectsLib *lib = CheckLibI(LIBOFFSET(DWGObjectsLib, SetNormalsSwap)); if (!lib) return;
	(this->*lib->SetNormalsSwap)(normals_swap);
}

void xPlaneSurfaceData::SetCoefficients(Float a, Float b, Float c, Float d)
{
	DWGObjectsLib *lib = CheckLibI(LIBOFFSET(DWGObjectsLib, SetCoefficients)); if (!lib) return;
	(this->*lib->SetCoefficients)(a, b, c, d);
}

void xPlaneSurfaceData::SetDisplayPosition(const Vector &v)
{
	DWGObjectsLib *lib = CheckLibI(LIBOFFSET(DWGObjectsLib, SetDisplayPosition)); if (!lib) return;
	(this->*lib->SetDisplayPosition)(v);
}

void xPlaneSurfaceData::SetDisplaySize(Float s)
{
	DWGObjectsLib *lib = CheckLibI(LIBOFFSET(DWGObjectsLib, SetDisplaySize)); if (!lib) return;
	(this->*lib->SetDisplaySize)(s);
}

void xPlaneSurfaceData::SetLimit(Float v)
{
	DWGObjectsLib *lib = CheckLibI(LIBOFFSET(DWGObjectsLib, SetLimit2)); if (!lib) return;
	(this->*lib->SetLimit2)(v);
}

void xPlaneSurfaceData::SetPlaneType(PlaneSurfaceTypeEnum type)
{
	DWGObjectsLib *lib = CheckLibI(LIBOFFSET(DWGObjectsLib, SetPlaneType)); if (!lib) return;
	(this->*lib->SetPlaneType)(type);
}

void xPolynomCurvePoint::SetCoeff(Int32 number, const Vector &vector)
{
	DWGObjectsLib *lib = CheckLibI(LIBOFFSET(DWGObjectsLib, SetCoeff)); if (!lib) return;
	(this->*lib->SetCoeff)(number, vector);
}

Bool xPolynomCurveData::ResizeObject(Int32 count, Int32 degree)
{
	DWGObjectsLib *lib = CheckLibI(LIBOFFSET(DWGObjectsLib, ResizeObject2)); if (!lib) return false;
	return (this->*lib->ResizeObject2)(count, degree);
}

Float* xPolynomCurveData::GetBreakPoint(Int32 index)
{
	DWGObjectsLib *lib = CheckLibI(LIBOFFSET(DWGObjectsLib, GetBreakPoint)); if (!lib) return nullptr;
	return (this->*lib->GetBreakPoint)(index);
}

xPolynomCurvePoint* xPolynomCurveData::GetPoint(Int32 index)
{
	DWGObjectsLib *lib = CheckLibI(LIBOFFSET(DWGObjectsLib, GetPoint2)); if (!lib) return nullptr;
	return (this->*lib->GetPoint2)(index);
}

Int32 xPolynomCurveData::GetPointCount(GeListNode *node)
{
	DWGObjectsLib *lib = CheckLibI(LIBOFFSET(DWGObjectsLib, GetPointCount2)); if (!lib) return 0;
	return (this->*lib->GetPointCount2)(node);
}

void xPolynomCurveData::InitClosed()
{
	DWGObjectsLib *lib = CheckLibI(LIBOFFSET(DWGObjectsLib, InitClosed)); if (!lib) return;
	(this->*lib->InitClosed)();
}

void xPolynomSurfacePoint::SetUVCoeff(Int32 uindex, Int32 vindex, const Vector &vector)
{
	DWGObjectsLib *lib = CheckLibI(LIBOFFSET(DWGObjectsLib, SetUVCoeff)); if (!lib) return;
	(this->*lib->SetUVCoeff)(uindex, vindex, vector);
}

Bool xPolynomSurfaceData::ResizeObject(Int32 ucount, Int32 vcount, Int32 udegree, Int32 vdegree)
{
	DWGObjectsLib *lib = CheckLibI(LIBOFFSET(DWGObjectsLib, ResizeObject3)); if (!lib) return false;
	return (this->*lib->ResizeObject3)(ucount, vcount, udegree, vdegree);
}

Float* xPolynomSurfaceData::GetUBreakPoint(Int32 index)
{
	DWGObjectsLib *lib = CheckLibI(LIBOFFSET(DWGObjectsLib, GetUBreakPoint)); if (!lib) return nullptr;
	return (this->*lib->GetUBreakPoint)(index);
}

Float* xPolynomSurfaceData::GetVBreakPoint(Int32 index)
{
	DWGObjectsLib *lib = CheckLibI(LIBOFFSET(DWGObjectsLib, GetVBreakPoint)); if (!lib) return nullptr;
	return (this->*lib->GetVBreakPoint)(index);
}

xPolynomSurfacePoint*	xPolynomSurfaceData::GetPoint(Int32 uindex, Int32 vindex)
{
	DWGObjectsLib *lib = CheckLibI(LIBOFFSET(DWGObjectsLib, GetPoint3)); if (!lib) return nullptr;
	return (this->*lib->GetPoint3)(uindex, vindex);
}

Int32 xPolynomSurfaceData::GetPointCount(GeListNode *node)
{
	DWGObjectsLib *lib = CheckLibI(LIBOFFSET(DWGObjectsLib, GetPointCount3)); if (!lib) return 0;
	return (this->*lib->GetPointCount3)(node);
}

void xPolynomSurfaceData::InitClosed()
{
	DWGObjectsLib *lib = CheckLibI(LIBOFFSET(DWGObjectsLib, InitClosed3)); if (!lib) return;
	(this->*lib->InitClosed3)();
}

void xRotateSurfaceData::SetStartAngle(Float angle)
{
	DWGObjectsLib *lib = CheckLibI(LIBOFFSET(DWGObjectsLib, SetStartAngle)); if (!lib) return;
	(this->*lib->SetStartAngle)(angle);
}

void xRotateSurfaceData::SetEndAngle(Float angle)
{
	DWGObjectsLib *lib = CheckLibI(LIBOFFSET(DWGObjectsLib, SetEndAngle)); if (!lib) return;
	(this->*lib->SetEndAngle)(angle);
}

void xRotateSurfaceData::SetInvert(Bool state)
{
	DWGObjectsLib *lib = CheckLibI(LIBOFFSET(DWGObjectsLib, SetInvert)); if (!lib) return;
	(this->*lib->SetInvert)(state);
}

void xUVPairFF::SetPeriodicU(Bool u)
{
	DWGObjectsLib *lib = CheckLibI(LIBOFFSET(DWGObjectsLib, SetPeriodicU)); if (!lib) return;
	(this->*lib->SetPeriodicU)(u);
}

void xUVPairFF::SetPeriodicV(Bool v)
{
	DWGObjectsLib *lib = CheckLibI(LIBOFFSET(DWGObjectsLib, SetPeriodicV)); if (!lib) return;
	(this->*lib->SetPeriodicV)(v);
}

void xUVPairFF::SetU(Int32 idx, Float u)
{
	DWGObjectsLib *lib = CheckLibI(LIBOFFSET(DWGObjectsLib, SetU)); if (!lib) return;
	(this->*lib->SetU)(idx, u);
}

void xUVPairFF::SetV(Int32 idx, Float v)
{
	DWGObjectsLib *lib = CheckLibI(LIBOFFSET(DWGObjectsLib, SetV)); if (!lib) return;
	(this->*lib->SetV)(idx, v);
}

Float xUVPairFF::GetU(Int32 idx)
{
	DWGObjectsLib *lib = CheckLibI(LIBOFFSET(DWGObjectsLib, GetU)); if (!lib) return 0.0;
	return (this->*lib->GetU)(idx);
}

Float xUVPairFF::GetV(Int32 idx)
{
	DWGObjectsLib *lib = CheckLibI(LIBOFFSET(DWGObjectsLib, GetV)); if (!lib) return 0.0;
	return (this->*lib->GetV)(idx);
}

xUVPairFF* xNurbsSurfaceData::GetKnots()
{
	DWGObjectsLib *lib = CheckLibI(LIBOFFSET(DWGObjectsLib, GetKnots)); if (!lib) return nullptr;
	return (this->*lib->GetKnots)();
}

void xNurbsSurfaceData::SetPolynomial(Bool p)
{
	DWGObjectsLib *lib = CheckLibI(LIBOFFSET(DWGObjectsLib, SetPolynomial2)); if (!lib) return;
	(this->*lib->SetPolynomial2)(p);
}

void xNurbsSurfaceData::SetUClosed(Bool c)
{
	DWGObjectsLib *lib = CheckLibI(LIBOFFSET(DWGObjectsLib, SetUClosed)); if (!lib) return;
	(this->*lib->SetUClosed)(c);
}

void xNurbsSurfaceData::SetVClosed(Bool c)
{
	DWGObjectsLib *lib = CheckLibI(LIBOFFSET(DWGObjectsLib, SetVClosed)); if (!lib) return;
	(this->*lib->SetVClosed)(c);
}

Bool xNurbsSurfaceData::ResizeObject(Int32 ucount, Int32 vcount, Int32 udegree, Int32 vdegree)
{
	DWGObjectsLib *lib = CheckLibI(LIBOFFSET(DWGObjectsLib, ResizeObject5)); if (!lib) return false;
	return (this->*lib->ResizeObject5)(ucount, vcount, udegree, vdegree);
}

void xNurbsSurfaceData::SetUParameterRange(Float min, Float max)
{
	DWGObjectsLib *lib = CheckLibI(LIBOFFSET(DWGObjectsLib, SetUParameterRange)); if (!lib) return;
	(this->*lib->SetUParameterRange)(min, max);
}

void xNurbsSurfaceData::SetVParameterRange(Float min, Float max)
{
	DWGObjectsLib *lib = CheckLibI(LIBOFFSET(DWGObjectsLib, SetVParameterRange)); if (!lib) return;
	(this->*lib->SetVParameterRange)(min, max);
}

Int32 xNurbsSurfaceData::GetUPointCount(GeListNode *node)
{
	DWGObjectsLib *lib = CheckLibI(LIBOFFSET(DWGObjectsLib, GetUPointCount2)); if (!lib) return 0;
	return (this->*lib->GetUPointCount2)(node);
}

Int32 xNurbsSurfaceData::GetVPointCount(GeListNode *node)
{
	DWGObjectsLib *lib = CheckLibI(LIBOFFSET(DWGObjectsLib, GetVPointCount2)); if (!lib) return 0;
	return (this->*lib->GetVPointCount2)(node);
}

xNurbsCurvePoint* xNurbsSurfaceData::GetPoint(Int32 uindex, Int32 vindex)
{
	DWGObjectsLib *lib = CheckLibI(LIBOFFSET(DWGObjectsLib, GetPoint4)); if (!lib) return nullptr;
	return (this->*lib->GetPoint4)(uindex, vindex);
}

xMappedCurveData* xMappedCurveClass::AllocMapped(Int32 type)
{
	DWGObjectsLib *lib = CheckLibI(LIBOFFSET(DWGObjectsLib, AllocMapped)); if (!lib) return nullptr;
	return (this->*lib->AllocMapped)(type);
}

Bool xMappedCurveClass::Update(GeListNode *node)
{
	DWGObjectsLib *lib = CheckLibI(LIBOFFSET(DWGObjectsLib, Update3)); if (!lib) return false;
	return (this->*lib->Update3)(node);
}

void xStandardMappedCurveData::SetSegmented(Bool value)
{
	DWGObjectsLib *lib = CheckLibI(LIBOFFSET(DWGObjectsLib, SetSegmented)); if (!lib) return;
	(this->*lib->SetSegmented)(value);
}

void xSegmentMappedCurveData::SetReversed(Bool value)
{
	DWGObjectsLib *lib = CheckLibI(LIBOFFSET(DWGObjectsLib, SetReversed)); if (!lib) return;
	(this->*lib->SetReversed)(value);
}

xTrimmedSurfaceData* xTrimmedSurfaceClass::AllocTrimmed(Int32 type)
{
	DWGObjectsLib *lib = CheckLibI(LIBOFFSET(DWGObjectsLib, AllocTrimmed)); if (!lib) return nullptr;
	return (this->*lib->AllocTrimmed)(type);
}

void xTrimmedSurfaceClass::SetPrecision(Float precision)
{
	DWGObjectsLib *lib = CheckLibI(LIBOFFSET(DWGObjectsLib, SetPrecision4)); if (!lib) return;
	(this->*lib->SetPrecision4)(precision);
}

Bool xTrimmedSurfaceClass::Update(GeListNode *node)
{
	DWGObjectsLib *lib = CheckLibI(LIBOFFSET(DWGObjectsLib, Update4)); if (!lib) return false;
	return (this->*lib->Update4)(node);
}

void xStandardTrimmedSurfaceData::SetFirstOuter(Bool value)
{
	DWGObjectsLib *lib = CheckLibI(LIBOFFSET(DWGObjectsLib, SetFirstOuter)); if (!lib) return;
	(this->*lib->SetFirstOuter)(value);
}



Bool xConvertToPolygons(BaseObject *oroot, BaseObject *destination, Int32 flags)
{
	DWGObjectsLib *lib = CheckLibI(LIBOFFSET(DWGObjectsLib, xConvertToPolygons)); if (!lib) return false;
	return (*lib->xConvertToPolygons)(oroot, destination, flags);
}

Bool xConvertToPolygonGroups(BaseObject *oroot, BaseObject *destination, Int32 flags)
{
	DWGObjectsLib *lib = CheckLibI(LIBOFFSET(DWGObjectsLib, xConvertToPolygonGroups)); if (!lib) return false;
	return (*lib->xConvertToPolygonGroups)(oroot, destination, flags);
}

Bool xCenterAxis(BaseObject *oroot)
{
	DWGObjectsLib *lib = CheckLibI(LIBOFFSET(DWGObjectsLib, xCenterAxis)); if (!lib) return false;
	return (*lib->xCenterAxis)(oroot);
}

Bool xFilterModelSpaceCurves(BaseObject *oroot)
{
	DWGObjectsLib *lib = CheckLibI(LIBOFFSET(DWGObjectsLib, xFilterModelSpaceCurves)); if (!lib) return false;
	return (*lib->xFilterModelSpaceCurves)(oroot);
}
