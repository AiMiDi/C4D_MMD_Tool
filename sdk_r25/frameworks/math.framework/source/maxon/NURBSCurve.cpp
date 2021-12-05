#include "maxon/general_math.h"
#include "NURBSCurve.h"
#include "NURBSMath.h"

namespace maxon
{

#if 0
Result<void> NURBSCurve::Init(Int points, Int degree, NURBSCURVE_CONTINUITY continuity)
{
	_continuity = continuity;

	return BaseNURBSCurve::Init(points, degree);
}


Result<void> NURBSCurve::DirtDevil()
{
	iferr_scope;

	if (MAXON_UNLIKELY(!_memInit))
		return IllegalStateError(MAXON_SOURCE_LOCATION, "Function 'Init' not called before."_s);

	if (_dirty)
	{
		if (_continuity == NURBSCURVE_CONTINUITY::CLOSED)
		{
			Int pointCount = _points.GetCount();

			_curve.Init(pointCount + 1, _curveDegree) iferr_return;

			for (Int i = 0; i < pointCount; ++i)
				_curve._points[i] = _points[i];

			_curve._points[pointCount] = _points[0];

			_curve.InitKnots(NURBSCURVE_KNOTMODE::CLAMPED_UNIFORM) iferr_return;

			_dirty = false;
		}
		else if (_continuity == NURBSCURVE_CONTINUITY::PERIODIC)
		{
			Int pointCount = _points.GetCount();

			_curve.Init(pointCount + _curveDegree, _curveDegree) iferr_return;

			for (Int i = 0; i < pointCount; ++i)
				_curve._points[i] = _points[i];

			for (Int i = 0; i < _curveDegree; ++i)
				_curve._points[pointCount + i] = _points[i];

			_curve.InitKnots(NURBSCURVE_KNOTMODE::UNCLAMPED_UNIFORM) iferr_return;

			_dirty = false;
		}
	}
	return OK;
}


Result<Vector> NURBSCurve::EvaluateAt(Float u, Int span)
{
	iferr_scope;

	DirtDevil() iferr_return;

	Vector res = Vector(0.0);
	if (_continuity == NURBSCURVE_CONTINUITY::OPEN)
	{
		res = BaseNURBSCurve::EvaluateAt(u, span) iferr_return;
	}
	else if (_continuity == NURBSCURVE_CONTINUITY::CLOSED)
	{
		res = _curve.EvaluateAt(u, span) iferr_return;
	}
	else if (_continuity == NURBSCURVE_CONTINUITY::PERIODIC)
	{
		res = _curve.EvaluateAt(u, span) iferr_return;
	}
	else
	{
		return IllegalArgumentError(MAXON_SOURCE_LOCATION, FormatString("Continuity mode @ not implemented.", _continuity));
	}

	return res;
}

Result<Vector> NURBSCurve::EvaluateAt(Float s)
{
	iferr_scope;

	DirtDevil() iferr_return;

	Vector res = Vector(0.0);
	if (_continuity == NURBSCURVE_CONTINUITY::OPEN)
	{
		res = BaseNURBSCurve::EvaluateAt(s) iferr_return;
	}
	else if (_continuity == NURBSCURVE_CONTINUITY::CLOSED)
	{
		res = _curve.EvaluateAt(s) iferr_return;
	}
	else if (_continuity == NURBSCURVE_CONTINUITY::PERIODIC)
	{
		res = _curve.EvaluateAt(s) iferr_return;
	}
	else
	{
		return IllegalArgumentError(MAXON_SOURCE_LOCATION, FormatString("Continuity mode @ not implemented.", _continuity));
	}

	return res;
}

Result<Vector> NURBSCurve::DeriveAt(Float u, Int span)
{
	iferr_scope;

	DirtDevil() iferr_return;

	Vector res = Vector(0.0);
	if (_continuity == NURBSCURVE_CONTINUITY::OPEN)
	{
		res = BaseNURBSCurve::DeriveAt(u, span) iferr_return;
	}
	else if (_continuity == NURBSCURVE_CONTINUITY::CLOSED)
	{
		res = _curve.DeriveAt(u, span) iferr_return;
	}
	else if (_continuity == NURBSCURVE_CONTINUITY::PERIODIC)
	{
		res = _curve.DeriveAt(u, span) iferr_return;
	}
	else
	{
		return IllegalArgumentError(MAXON_SOURCE_LOCATION, FormatString("Continuity mode @ not implemented.", _continuity));
	}

	return res;
}

Result<Vector> NURBSCurve::DeriveAt(Float s)
{
	iferr_scope;

	DirtDevil() iferr_return;

	Vector res = Vector(0.0);
	if (_continuity == NURBSCURVE_CONTINUITY::OPEN)
	{
		res = BaseNURBSCurve::DeriveAt(s) iferr_return;
	}
	else if (_continuity == NURBSCURVE_CONTINUITY::CLOSED)
	{
		res = _curve.DeriveAt(s) iferr_return;
	}
	else if (_continuity == NURBSCURVE_CONTINUITY::PERIODIC)
	{
		res = _curve.DeriveAt(s) iferr_return;
	}
	else
	{
		return IllegalArgumentError(MAXON_SOURCE_LOCATION, FormatString("Continuity mode @ not implemented.", _continuity));
	}

	return res;
}


void NURBSCurve::SetContinuity(NURBSCURVE_CONTINUITY continuity)
{
	if (_continuity == continuity)
		return;

	_dirty = true;
	_continuity = continuity;

	if (_continuity == NURBSCURVE_CONTINUITY::OPEN)
	{
		_curve.Reset();
	}
}

#endif



void NURBSTests::TestFunc()
{
	NURBSCurve<-1> testCurveDynamic;
	testCurveDynamic.Init(10, 3) iferr_ignore("test code");

	NURBSCurve<4> testCurveStatic;
	testCurveStatic.Init(10) iferr_ignore("test code");


	testCurveDynamic.EvaluateAt(0) iferr_ignore("test code");
	testCurveDynamic.DeriveAt(0) iferr_ignore("test code");
	testCurveStatic.EvaluateAt(0) iferr_ignore("test code");
	testCurveStatic.DeriveAt(0) iferr_ignore("test code");

	NURBSCurveWithContinuity<3> myCurve;

	NURBSCurve<5> testCurveHigherStaticDegree;
	//testCurveHigherStaticDegree.Init(testCurveStatic) iferr_ignore("test code");

	NURBSCurve<-1> testCurveHigherDynamicDegree;
	//testCurveHigherDynamicDegree.Init(5, testCurveStatic) iferr_ignore("test code");

}

} // namespace maxon
