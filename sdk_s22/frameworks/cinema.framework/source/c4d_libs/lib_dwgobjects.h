/////////////////////////////////////////////////////////////
// IGES 4D    : GENERIC CURVE AND SURFACES LIBRARY         //
/////////////////////////////////////////////////////////////
// VERSION    : Cinema 4D                                  //
/////////////////////////////////////////////////////////////
// (c) 2003-2004 MAXON Computer GmbH, Stefan Bauer         //
/////////////////////////////////////////////////////////////

#ifndef LIB_DWGOBJECTS_H__
#define LIB_DWGOBJECTS_H__

#include "c4d_library.h"
#include "lib_dwgobjectsdef.h"
#include "c4d_objectdata.h"

#ifndef _INTERNAL_USE_ONLY_

class xBaseCurveData;

class xBaseCurveClass : public NodeData
{
		xBaseCurveClass();
		~xBaseCurveClass();
	public:
		xBaseCurveData *AllocCurve(Int32 type);

		Bool Update(GeListNode *node);

		Int32 GetSubDivision();
		void SetSubDivision(Int32 subdiv);

		void SetOutput(Int32 output);
};

class xBaseGeometryData
{
		xBaseGeometryData() { }
		~xBaseGeometryData() {}
	public:
		void Initialize(GeListNode *node);
};

class xBaseCurveData : public xBaseGeometryData
{
		xBaseCurveData();
		~xBaseCurveData();
	public:
		void SetPlanar(Bool planar);
};

class xLineCurveData : public xBaseCurveClass
{
		xLineCurveData();
		~xLineCurveData();
	public:
		void SetStartPoint(const Vector &v);
		void SetEndPoint(const Vector &v);
		void SetLimit(Float v);
		void SetLineType(LineCurveTypeEnum type);
};

class xCircularCurveData : public xBaseCurveData
{
		xCircularCurveData();
		~xCircularCurveData();
	public:
		void SetCenter(Float x, Float y);
		void SetZValue(Float z);
		void SetStartPoint(Float x, Float y);
		void SetEndPoint(Float x, Float y);
		void SetIsClockWise(Bool value);

		Float GetParameterMax(GeListNode *node = nullptr);
		Float GetParameterMin(GeListNode *node = nullptr);
};

class xConicCurveData : public xBaseCurveData
{
		xConicCurveData();
		~xConicCurveData();
	public:
		void SetZValue(Float z);
		void SetStartPoint(Float x, Float y);
		void SetEndPoint(Float x, Float y);
		void SetCoefficients(const ConicCurveCoeffcients &coeff);
		void SetCoefficients(Float a, Float b, Float c, Float d, Float e, Float f);
};

class xNurbsKnots
{
		xNurbsKnots();
		~xNurbsKnots();
	public:

		void SetPeriodic(Bool state);
		void Set(Int32 i, Float value);
		Float GetMinValue(void);
		Float GetMaxValue(void);
		Float Get(Int32 i);
};

class xBaseCurvePoint
{
		xBaseCurvePoint();
		~xBaseCurvePoint();
	public:
		void SetPosition(const Vector &vector);
		const Vector &GetPosition();
};

class xNurbsCurvePoint : public xBaseCurvePoint
{
		xNurbsCurvePoint();
		~xNurbsCurvePoint();
	public:
		void SetWeight(Float w);
		Float GetWeight();
};

class xNurbsCurveData : public xBaseCurveData
{
		xNurbsCurveData();
		~xNurbsCurveData();
	public:
		Bool ResizeObject(Int32 count, Int32 degree);
		void SetClosed(Bool value);
		void SetPoint(Int32 index, const Vector& position, const Float& weight);
		xNurbsKnots *GetKnots();
		void SetParameterRange(Float min, Float max);
		void SetPolynomial(Bool value);
		xNurbsCurvePoint* GetPoint(Int32 index);
};

class xCompositeCurveData : public xBaseCurveData
{
		xCompositeCurveData();
		~xCompositeCurveData();
	public:
};

class xBaseSurfaceData;

class xBaseSurfaceClass : public ObjectData
{
		xBaseSurfaceClass();
		~xBaseSurfaceClass();
	public:
		xBaseSurfaceData *AllocSurface(Int32 type);

		Bool Update(GeListNode *node);

		void SetSubU(Int32 subu);
		void SetSubV(Int32 subv);
		void SetOutput(Int32 output);
		void SetNormalsActive(Bool normals_active);
		void SetNormalsSwap(Bool normals_swap);
};

class xBaseSurfaceData : public xBaseGeometryData
{
		xBaseSurfaceData();
		~xBaseSurfaceData();
	public:
};

class xExtrudeSurfaceData : public xBaseSurfaceData
{
		xExtrudeSurfaceData();
		~xExtrudeSurfaceData();

	public:
		void SetDirection(const Vector &v);
};

class xPlaneSurfaceData : public xBaseSurfaceData
{
		xPlaneSurfaceData();
		~xPlaneSurfaceData();
	public:
		void SetCoefficients(Float a, Float b, Float c, Float d);
		void SetDisplayPosition(const Vector &v);
		void SetDisplaySize(Float s);
		void SetLimit(Float v);
		void SetPlaneType(PlaneSurfaceTypeEnum type);
};

class xPolynomCurvePoint : public xBaseCurvePoint
{
		xPolynomCurvePoint();
		~xPolynomCurvePoint();
	public:
		void SetCoeff(Int32 number, const Vector &vector);
};

class xPolynomCurveData : public xBaseCurveData
{
		xPolynomCurveData();
		~xPolynomCurveData();
	public:
		Bool ResizeObject(Int32 count, Int32 degree);
		Float* GetBreakPoint(Int32 index);
		xPolynomCurvePoint* GetPoint(Int32 index);
		Int32 GetPointCount(GeListNode *node = nullptr);
		void InitClosed();
};

class xPolynomSurfacePoint : public xPolynomCurvePoint
{
		xPolynomSurfacePoint();
		~xPolynomSurfacePoint();
	public:
		void SetUVCoeff(Int32 uindex, Int32 vindex, const Vector &vector);
};

class xPolynomSurfaceData : public xBaseSurfaceData
{
		xPolynomSurfaceData();
		~xPolynomSurfaceData();
	public:
		Bool ResizeObject(Int32 ucount, Int32 vcount, Int32 udegree, Int32 vdegree);
		Float* GetUBreakPoint(Int32 index);
		Float* GetVBreakPoint(Int32 index);
		xPolynomSurfacePoint* GetPoint(Int32 uindex, Int32 vindex);
		Int32 GetPointCount(GeListNode *node = nullptr);
		void InitClosed();
};

class xRotateSurfaceData : public xBaseSurfaceData
{
		xRotateSurfaceData();
		~xRotateSurfaceData();
	public:
		void SetStartAngle(Float angle);
		void SetEndAngle(Float angle);
		void SetInvert(Bool state);
};

class xUVPairFF
{
		xUVPairFF();
		~xUVPairFF();
	public:
		void SetPeriodicU(Bool u);
		void SetPeriodicV(Bool v);
		void SetU(Int32 idx, Float u);
		void SetV(Int32 idx, Float v);
		Float GetU(Int32 idx);
		Float GetV(Int32 idx);
};

class xNurbsSurfaceData : public xBaseSurfaceData
{
		xNurbsSurfaceData();
		~xNurbsSurfaceData();
	public:
		xUVPairFF* GetKnots();
		void SetPolynomial(Bool p);
		void SetUClosed(Bool c);
		void SetVClosed(Bool c);
		Bool ResizeObject(Int32 ucount, Int32 vcount, Int32 udegree, Int32 vdegree);
		void SetUParameterRange(Float min, Float max);
		void SetVParameterRange(Float min, Float max);
		Int32 GetUPointCount(GeListNode *node = nullptr);
		Int32 GetVPointCount(GeListNode *node = nullptr);
		xNurbsCurvePoint* GetPoint(Int32 uindex, Int32 vindex);
};

class xMappedCurveData;

class xMappedCurveClass : public ObjectData
{
		xMappedCurveClass();
		~xMappedCurveClass();
	public:
		xMappedCurveData *AllocMapped(Int32 type);
		Bool Update(GeListNode *node);
};

class xMappedCurveData : public xBaseGeometryData
{
		xMappedCurveData();
		~xMappedCurveData();
	public:

};

class xStandardMappedCurveData : public xMappedCurveData
{
		xStandardMappedCurveData();
		~xStandardMappedCurveData();
	public:
		void SetSegmented(Bool value);
};

class xSegmentMappedCurveData : public xMappedCurveData
{
		xSegmentMappedCurveData();
		~xSegmentMappedCurveData();
	public:
		void SetReversed(Bool value);
};

class xTrimmedSurfaceData;

class xTrimmedSurfaceClass : public ObjectData
{
		xTrimmedSurfaceClass();
		~xTrimmedSurfaceClass();
	public:
		xTrimmedSurfaceData *AllocTrimmed(Int32 type);
		void SetPrecision(Float precision);
		Bool Update(GeListNode *node);
};

class xTrimmedSurfaceData : public xBaseGeometryData
{
		xTrimmedSurfaceData();
		~xTrimmedSurfaceData();
	public:
};

class xStandardTrimmedSurfaceData : public xTrimmedSurfaceData
{
		xStandardTrimmedSurfaceData();
		~xStandardTrimmedSurfaceData();
	public:
		void SetFirstOuter(Bool value);
};

#else
	#define xBaseCurveClass								BaseCurveClass
	#define xBaseGeometryData							BaseGeometryData
	#define xBaseCurveData								BaseCurveData
	#define xLineCurveData								LineCurveData
	#define xCircularCurveData						CircularCurveData
	#define xConicCurveData								ConicCurveData
	#define xNurbsKnots										NurbsKnots
	#define xNurbsCurveData								NurbsCurveData
	#define xCompositeCurveData						CompositeCurveData
	#define xBaseSurfaceClass							BaseSurfaceClass
	#define xBaseSurfaceData							BaseSurfaceData
	#define xExtrudeSurfaceData						ExtrudeSurfaceData
	#define xBaseCurvePoint								BaseCurvePoint
	#define xNurbsCurvePoint							NurbsCurvePoint
	#define xPlaneSurfaceData							PlaneSurfaceData
	#define xPolynomCurvePoint						PolynomCurvePoint
	#define xPolynomCurveData							PolynomCurveData
	#define xPolynomSurfacePoint					PolynomSurfacePoint
	#define xPolynomSurfaceData						PolynomSurfaceData
	#define xRotateSurfaceData						RotateSurfaceData
	#define xUVPairFF											UVPairFF
	#define xNurbsSurfaceData							NurbsSurfaceData
	#define xMappedCurveClass							MappedCurveClass
	#define xMappedCurveData							MappedCurveData
	#define xStandardMappedCurveData			StandardMappedCurveData
	#define xSegmentMappedCurveData				SegmentMappedCurveData
	#define xTrimmedSurfaceClass					TrimmedSurfaceClass
	#define xTrimmedSurfaceData						TrimmedSurfaceData
	#define xStandardTrimmedSurfaceData		StandardTrimmedSurfaceData
#endif

// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF

#define DWGOBJECTS_LIB 200000212

struct DWGObjectsLib : public C4DLibrary
{
	Bool									(xBaseCurveClass::*Update)(GeListNode *node);
	xBaseCurveData* 			(xBaseCurveClass::*AllocCurve)(Int32 type);
	Int32									(xBaseCurveClass::*GetSubDivision)();
	void									(xBaseCurveClass::*SetSubDivision)(Int32 subdiv);
	void									(xBaseCurveClass::*SetOutput)(Int32 output);

	void									(xBaseCurveData::*SetPlanar)(Bool planar);

	void									(xBaseGeometryData::*Initialize)(GeListNode *node);

	void									(xLineCurveData::*SetStartPoint)(const Vector &v);
	void									(xLineCurveData::*SetEndPoint)(const Vector &v);
	void									(xLineCurveData::*SetLimit)(Float v);
	void									(xLineCurveData::*SetLineType)(LineCurveTypeEnum type);

	void									(xCircularCurveData::*SetCenter)(Float x, Float y);
	void									(xCircularCurveData::*SetZValue)(Float z);
	void									(xCircularCurveData::*SetStartPoint2)(Float x, Float y);
	void									(xCircularCurveData::*SetEndPoint2)(Float x, Float y);
	void									(xCircularCurveData::*SetIsClockWise)(Bool value);
	Float									(xCircularCurveData::*GetParameterMax)(GeListNode *node);
	Float									(xCircularCurveData::*GetParameterMin)(GeListNode *node);

	void									(xConicCurveData::*SetZValue2)(Float z);
	void									(xConicCurveData::*SetStartPoint3)(Float x, Float y);
	void									(xConicCurveData::*SetEndPoint3)(Float x, Float y);
	void									(xConicCurveData::*SetCoefficients1)(const ConicCurveCoeffcients &coeff);
	void									(xConicCurveData::*SetCoefficients2)(Float a, Float b, Float c, Float d, Float e, Float f);

	void									(xNurbsKnots::*SetPeriodic)(Bool state);
	void									(xNurbsKnots::*Set)(Int32 i, Float value);
	Float									(xNurbsKnots::*GetMinValue)(void);
	Float									(xNurbsKnots::*GetMaxValue)(void);
	Float									(xNurbsKnots::*Get)(Int32 i);

	void									(xBaseCurvePoint::*SetPosition)(const Vector &vector);
	const Vector &				(xBaseCurvePoint::*GetPosition)();

	void									(xNurbsCurvePoint::*SetWeight)(Float w);
	Float									(xNurbsCurvePoint::*GetWeight)();

	Bool									(xNurbsCurveData::*ResizeObject4)(Int32 count, Int32 degree);
	void									(xNurbsCurveData::*SetClosed)(Bool value);
	void									(xNurbsCurveData::*SetPoint)(Int32 index, const Vector& position, const Float& weight);
	xNurbsKnots*					(xNurbsCurveData::*GetKnots2)();
	void									(xNurbsCurveData::*SetParameterRange)(Float min, Float max);
	void									(xNurbsCurveData::*SetPolynomial3)(Bool value);
	xNurbsCurvePoint* 		(xNurbsCurveData::*GetPoint)(Int32 index);

	xBaseSurfaceData*			(xBaseSurfaceClass::*AllocSurface)(Int32 type);
	Bool									(xBaseSurfaceClass::*Update2)(GeListNode *node);
	void									(xBaseSurfaceClass::*SetSubU)(Int32 subu);
	void									(xBaseSurfaceClass::*SetSubV)(Int32 subv);
	void 									(xBaseSurfaceClass::*SetOutput2)(Int32 output);
	void									(xBaseSurfaceClass::*SetNormalsActive)(Bool normals_active);
	void									(xBaseSurfaceClass::*SetNormalsSwap)(Bool normals_swap);

	void									(xExtrudeSurfaceData::*SetDirection)(const Vector &v);

	void									(xPlaneSurfaceData::*SetCoefficients)(Float a, Float b, Float c, Float d);
	void									(xPlaneSurfaceData::*SetDisplayPosition)(const Vector &v);
	void									(xPlaneSurfaceData::*SetDisplaySize)(Float s);
	void									(xPlaneSurfaceData::*SetLimit2)(Float v);
	void 									(xPlaneSurfaceData::*SetPlaneType)(PlaneSurfaceTypeEnum type);

	void									(xPolynomCurvePoint::*SetCoeff)(Int32 number, const Vector &vector);

	Bool									(xPolynomCurveData::*ResizeObject2)(Int32 count, Int32 degree);
	Float*									(xPolynomCurveData::*GetBreakPoint)(Int32 index);
	xPolynomCurvePoint*		(xPolynomCurveData::*GetPoint2)(Int32 index);
	Int32									(xPolynomCurveData::*GetPointCount2)(GeListNode *node);
	void									(xPolynomCurveData::*InitClosed)();

	void 									(xPolynomSurfacePoint::*SetUVCoeff)(Int32 uindex, Int32 vindex, const Vector &vector);

	Bool									(xPolynomSurfaceData::*ResizeObject3)(Int32 ucount, Int32 vcount, Int32 udegree, Int32 vdegree);
	Float*									(xPolynomSurfaceData::*GetUBreakPoint)(Int32 index);
	Float*									(xPolynomSurfaceData::*GetVBreakPoint)(Int32 index);
	xPolynomSurfacePoint*	(xPolynomSurfaceData::*GetPoint3)(Int32 uindex, Int32 vindex);
	Int32									(xPolynomSurfaceData::*GetPointCount3)(GeListNode *node);
	void									(xPolynomSurfaceData::*InitClosed3)();

	void									(xRotateSurfaceData::*SetStartAngle)(Float angle);
	void									(xRotateSurfaceData::*SetEndAngle)(Float angle);
	void 									(xRotateSurfaceData::*SetInvert)(Bool state);

	void									(xUVPairFF::*SetPeriodicU)(Bool u);
	void									(xUVPairFF::*SetPeriodicV)(Bool v);
	void 									(xUVPairFF::*SetU)(Int32 idx, Float u);
	void 									(xUVPairFF::*SetV)(Int32 idx, Float v);
	Float 									(xUVPairFF::*GetU)(Int32 idx);
	Float 									(xUVPairFF::*GetV)(Int32 idx);

	xUVPairFF*						(xNurbsSurfaceData::*GetKnots)();
	void									(xNurbsSurfaceData::*SetPolynomial2)(Bool p);
	void									(xNurbsSurfaceData::*SetUClosed)(Bool c);
	void 									(xNurbsSurfaceData::*SetVClosed)(Bool c);
	Bool									(xNurbsSurfaceData::*ResizeObject5)(Int32 ucount, Int32 vcount, Int32 udegree, Int32 vdegree);
	void									(xNurbsSurfaceData::*SetUParameterRange)(Float min, Float max);
	void									(xNurbsSurfaceData::*SetVParameterRange)(Float min, Float max);
	Int32									(xNurbsSurfaceData::*GetUPointCount2)(GeListNode *node);
	Int32									(xNurbsSurfaceData::*GetVPointCount2)(GeListNode *node);
	xNurbsCurvePoint*			(xNurbsSurfaceData::*GetPoint4)(Int32 uindex, Int32 vindex);

	xMappedCurveData *		(xMappedCurveClass::*AllocMapped)(Int32 type);
	Bool									(xMappedCurveClass::*Update3)(GeListNode *node);

	void									(xStandardMappedCurveData::*SetSegmented)(Bool value);

	void									(xSegmentMappedCurveData::*SetReversed)(Bool value);

	xTrimmedSurfaceData *	(xTrimmedSurfaceClass::*AllocTrimmed)(Int32 type);
	void									(xTrimmedSurfaceClass::*SetPrecision4)(Float precision);
	Bool									(xTrimmedSurfaceClass::*Update4)(GeListNode *node);

	void									(xStandardTrimmedSurfaceData::*SetFirstOuter)(Bool value);

	Bool									(*xConvertToPolygons)(BaseObject *oroot, BaseObject *destination, Int32 flags);
	Bool									(*xConvertToPolygonGroups)(BaseObject *oroot, BaseObject *destination, Int32 flags);
	Bool									(*xCenterAxis)(BaseObject *oroot);
	Bool									(*xFilterModelSpaceCurves)(BaseObject *oroot);
};

#define CONVERT_CACHES (1 << 0)
#define CONVERT_TOONE  (1 << 1)

Bool xConvertToPolygons(BaseObject *oroot, BaseObject *destination, Int32 flags);
Bool xConvertToPolygonGroups(BaseObject *oroot, BaseObject *destination, Int32 flags);
Bool xCenterAxis(BaseObject *oroot);
Bool xFilterModelSpaceCurves(BaseObject *oroot);

// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF

#endif // LIB_DWGOBJECTS_H__
