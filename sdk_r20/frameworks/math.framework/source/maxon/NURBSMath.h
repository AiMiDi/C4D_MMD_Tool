#ifndef NURBSMATH_H__
#define NURBSMATH_H__

#include "maxon/vector4d.h"
#include "matrix_nxm.h"

namespace maxon
{

enum class NURBSCURVE_KNOTMODE
{
	CLAMPED_UNIFORM	    = 0,	///< Clamped uniform (open uniform / quasi uniform) NURBS/B-Spline/Bezier knot vector with end knots of multiplicity of degree. Internal knots are uniform e.g. [0, 0, 0, 1/3, 2/3, 1, 1, 1]. If there are no internal knots then the spline is equal to a bezier spline of same degree e.g. [0, 0, 0, 0, 1, 1, 1, 1]
	CLAMPED_CHORDAL     = 1,	///< Clamped nonuniform knot vector whose inner knots are computed according to the actual position of control points in space according to the chord length method. Works only correct if SetPoints has been called before since the routines needs to compute the point distances.
	CLAMPED_CENTRIPETAL = 2,	///< Clamped nonuniform knot vector whose inner knots are computed according to the actual position of control points in space according to the centripetal method.Works only correct if SetPoints has been called before since the routines needs to compute the point distances.
	UNCLAMPED_UNIFORM   = 3 	///< uniform knot vector e.g. [0.0, 0.25, 0.5, 0.75, 1.0]. Mostly useful for periodic (closed) splines
} MAXON_ENUM_LIST(NURBSCURVE_KNOTMODE);

struct KnotInfo
{
	Int  firstPosition = 0;
	Int  multiplicity  = 0;
	Bool innerKnot     = false;
};

class NurbsCurve;

class BaseNURBSCurve
{
	friend class NURBSCurve;

public:
	// allocate needed memory
	// must be called once before accessing any of the other routines, otherwise you get an error
	Result<void> Init(Int pcnt, Int degree);

	// delete all internal allocated mem and reset data
	void Reset();

	// resets all knot data, leaves point&weigth data untouched
	Result<void> ChangeDegree(Int newDegree, NURBSCURVE_KNOTMODE knotMode = NURBSCURVE_KNOTMODE::CLAMPED_UNIFORM);

	Result<Vector> EvaluateAt(Float s);
	Result<Vector> EvaluateAt(Float u, Int span);

	Result<Vector> DeriveAt(Float s);
	Result<Vector> DeriveAt(Float u, Int span);

	Result<Int> GetDegree();
	Result<Int> GetMaxDegree(); // points + degree + 1

	Result<Int> GetPointCount();
	Result<Int> GetWeightCount(); // identical with PointCount()
	Result<Int> GetKnotCount(); // equals points + degree + 1;

	Result<KnotInfo> GetKnotInfo(Int i);

	Result<Vector> GetPoint(Int i);
	Result<Float> GetWeight(Int i);
	Result<Float> GetKnot(Int i);

	// set points
	Result<void> SetPoint(Int i, const Vector& point);
	Result<void> SetPoints(const BaseArray<Vector>& points);

	// set weigths
	Result<void> SetWeight(Int i, Float weight);
	Result<void> SetWeights(const BaseArray<Float>& weights);

	// set knots
	Result<void> SetKnot(Int i, Float knot);
	Result<void> SetKnots(NURBSCURVE_KNOTMODE mode);

	// The knot vector can, by its definition, be any sequence of numbers provided that each one is greater than or equal to the preceding one.
	Result<void> SetKnots(const BaseArray<Float>& knots);

	Result<void> InsertKnot(Float s, Int nTimes);
	Result<void> InsertKnot(Float u, Int span, Int nTimes);

	Float GetUmin();
	Float GetUmax();

	Result<Int> FindSpan(Float u);

	// s is [0.0, 1.0]
	Float MapStoU(Float s);

	// u is [Umin, Umax]
	Float MapUtoS(Float u);

protected:
	// main data
	Int                 _curveDegree = 0;
	BaseArray<Vector4d> _points;
	BaseArray<Float>    _knots;

	// initialization flags
	Bool                _dirty   = true; // signal if data has been changed and caches musst be rebuild
	Bool                _memInit = false;

	Result <void> _CheckForKnotConsistency();
	Result<void> _InitKnots(NURBSCURVE_KNOTMODE mode);
	Result<void> _ComputeBasisFunctions(Float u, Int span, Int maxDegree);
	Result<Vector4d> _ComputeHomogeneousC(Float u, Int span, Int degree);

private:
	// cache for computation
	MatrixNxM<Float>  _basis; // holds basis function and its derivates up to degree 2
	BaseArray<Float> _left;
	BaseArray<Float> _right;
	MatrixNxM<Float> _ndu;
	MatrixNxM<Float> _a;
};

} // namespace maxon

#endif // NURBSMATH_H__
