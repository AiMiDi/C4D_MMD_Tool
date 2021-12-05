#ifndef NURBSCURVE_H__
#define NURBSCURVE_H__

#include "NURBSMath.h"

namespace maxon
{

enum class NURBSCURVE_CONTINUITY
{
	OPEN     = 0, ///< Open spline with No continuity between first and last point.
	CLOSED   = 1, ///< Closed spline with position continuity (sharp cusp) between first and last point. Replaces any previous knot vector with a clamped uniform knot vector.
	PERIODIC = 2  ///< Closed spline with C2 continuity between first and last point. Replaces any previous knot vector with an unclamped uniform knot vector.
} MAXON_ENUM_LIST(NURBSCURVE_CONTINUITY);

class NURBSCurve : public BaseNURBSCurve
{
public:
	// allocate needed memory
	// default weigths to 1.0 and knots to CLAMPED_UNIFORM
	// must be called once before accessing any of the other routines, otherwise you get an error
	Result<void> Init(Int points, Int degree, NURBSCURVE_CONTINUITY continuity);

	void SetContinuity(NURBSCURVE_CONTINUITY continuity);

	Result<Vector> EvaluateAt(Float s);
	Result<Vector> EvaluateAt(Float u, Int span);

	Result<Vector> DeriveAt(Float s);
	Result<Vector> DeriveAt(Float u, Int span);

private:
	Result<void> DirtDevil();

	// main data
	NURBSCURVE_CONTINUITY _continuity = NURBSCURVE_CONTINUITY::OPEN;
	BaseNURBSCurve        _curve; // used for closed and periodic splines
};




} // namespace maxon

#endif // NURBSCURVE_H__
