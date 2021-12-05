#include "maxon/general_math.h"
#include "maxon/NURBSMath.h"
#include "maxon/matrix_nxm.h"

namespace maxon
{

static Vector4d HomogeneousToNormal(const Vector4d& p)
{
	if (MAXON_UNLIKELY(p.w == 0.0))
		return p;

	Vector4d r;
	Float    w = Inverse(p.w);

	r.x = p.x * w;
	r.y = p.y * w;
	r.z = p.z * w;
	r.w = p.w;

	return r;
}

static Vector4d NormalToHomogeneous(const Vector4d& p)
{
	Vector4d r;

	r.x = p.x * p.w;
	r.y = p.y * p.w;
	r.z = p.z * p.w;
	r.w = p.w;

	return r;
}

Result<KnotInfo> BaseNURBSCurve::GetKnotInfo(Int k)
{
	iferr_scope;

	Int   i;
	Int   kCnt = _knots.GetCount();

	if (MAXON_UNLIKELY(k < 0 || k >= kCnt))
		return IllegalArgumentError(MAXON_SOURCE_LOCATION, "Knot index outside range"_s);

	KnotInfo info;

	info.firstPosition = k;
	info.multiplicity  = 1;

	// search to the right
	for (i = k+1; i < kCnt; i++)
	{
		if (_knots[i] == _knots[k])
			info.multiplicity++;
	}

	// search to the left
	for (i = k-1; i >= 0; i--)
	{
		if (_knots[i] == _knots[k])
		{
			info.firstPosition = i;
			info.multiplicity++;
		}
	}

	info.innerKnot = !((info.multiplicity == _curveDegree+1) && (info.firstPosition == 0 || info.firstPosition == kCnt - _curveDegree - 1));

	return info;
}

Result <void> BaseNURBSCurve::_CheckForKnotConsistency()
{
	iferr_scope;

	Int      kCnt = _knots.GetCount();
	KnotInfo info;

	for (Int i = 1; i < kCnt; )
	{
		if (_knots[i] < _knots[i-1])
			return IllegalStateError(MAXON_SOURCE_LOCATION, FormatString("Knot @ is not equal or greater than knot @.", i, i-1));

		info = GetKnotInfo(i) iferr_return;

		if (info.innerKnot)
		{
			if (info.multiplicity > _curveDegree)
				return IllegalStateError(MAXON_SOURCE_LOCATION, FormatString("Multiplicity of inner knot @ higher than degree of curve.", info.firstPosition));
		}
		else
		{
			if (info.multiplicity > _curveDegree + 1)
				return IllegalStateError(MAXON_SOURCE_LOCATION, FormatString("Multiplicity of outer knot @ higher than degree+1 of curve.", info.firstPosition));
		}

		i += info.multiplicity;
	}

	return OK;
}

Result<void> BaseNURBSCurve::_InitKnots(NURBSCURVE_KNOTMODE mode)
{
	iferr_scope;

	Int pCnt = _points.GetCount();
	Int kCnt = _knots.GetCount();
	Int degree = kCnt - pCnt - 1;

	if (MAXON_UNLIKELY(pCnt < 1))
		return IllegalArgumentError(MAXON_SOURCE_LOCATION, "Wrong number of points."_s);

	if (MAXON_UNLIKELY(degree < 1))
		return IllegalArgumentError(MAXON_SOURCE_LOCATION, "Wrong number of points and knots."_s);

	switch (mode)
	{
		case NURBSCURVE_KNOTMODE::UNCLAMPED_UNIFORM:
		{
			for (Int k = 0; k <= kCnt-1; k++)
				_knots[k] = Float(k) * Inverse(Float(kCnt-1));

			break;
		}

		case NURBSCURVE_KNOTMODE::CLAMPED_CHORDAL:
		case NURBSCURVE_KNOTMODE::CLAMPED_CENTRIPETAL:
		{
			BaseArray <Float> t; // summed chord lengths
			t.Resize(pCnt) iferr_return;

			// calculate chord length per point segment
			Float total = 0.0;
			t[0]        = 0.0;

			for (Int p = 1; p < pCnt; p++)
			{
				Float	len = (_points[p].GetVector3() - _points[p-1].GetVector3()).GetLength();

				if (mode == NURBSCURVE_KNOTMODE::CLAMPED_CENTRIPETAL)
					len = Sqrt(len);

				total += len;
				t[p] = total;
			}

			if (MAXON_UNLIKELY(total == 0.0))
				return IllegalArgumentError(MAXON_SOURCE_LOCATION, "Degenerate spline with total chord length zero."_s);

			// normalize chord lengths by total length
			total = Inverse(total);
			for (Float& it : t)
				it *= total;

			// DiagnosticOutput(FormatString("-- length @", t));


			// map chord length parameters to clamped knot vector
			for (Int k = 0; k <= degree; k++)
			{
				_knots[k]            = 0.0;
				_knots[kCnt - 1 - k] = 1.0;
			}

			// DiagnosticOutput(FormatString("-- Knots @", knots));

			for (Int k = degree + 1; k < kCnt - degree - 1; k++)
			{
				Float average = 0.0;
				for (Int j = 0; j < degree; j++)
					average += t[k + j - degree];

				_knots[k] = average * Inverse(Float(degree));
			}
			break;
		}

		case NURBSCURVE_KNOTMODE::CLAMPED_UNIFORM:
		{
			for (Int k = 0; k <= degree; k++)
			{
				_knots[k]            = 0.0;
				_knots[kCnt - 1 - k] = 1.0;
			}

			Int k1 = degree;
			Int k2 = kCnt - degree - 1;
			for (Int k = k1; k <= k2; k++)
				_knots[k] = Float(k-k1) * Inverse(Float(k2 - k1));

			break;
		}

		default:
		{
			return IllegalArgumentError(MAXON_SOURCE_LOCATION, "Unknown knot mode."_s);
		}
	}

	// DiagnosticOutput(FormatString("Knots @", _knots));
	return OK;
}

Result<void> BaseNURBSCurve::Init(Int points, Int degree)
{
	iferr_scope;

	_memInit = false;

	if (degree < 1)
		return IllegalArgumentError(MAXON_SOURCE_LOCATION, "Degree must be at least 1."_s);

	if (points < degree + 1)
		return IllegalArgumentError(MAXON_SOURCE_LOCATION, "Not enough control points for this degree of curve."_s);

	_curveDegree = degree;
	_points.Resize(points) iferr_return;
	_knots .Resize(points + degree +1) iferr_return;

	// default values
	for (Vector4d& it : _points)
		it = Vector4d(0.0, 0.0, 0.0, 1.0);

	// default knots
	_InitKnots(NURBSCURVE_KNOTMODE::CLAMPED_UNIFORM) iferr_return;

	_memInit = true;
	return OK;
}

void BaseNURBSCurve::Reset()
{
	_memInit = false;
	_dirty   = true;

	_points.Reset();
	_knots.Reset();
	_curveDegree = 0;
}

Result<void> BaseNURBSCurve::ChangeDegree(Int newDegree, NURBSCURVE_KNOTMODE knotMode)
{
	iferr_scope;

	_memInit = false;
	_dirty   = true;

	if (newDegree < 1)
		return IllegalArgumentError(MAXON_SOURCE_LOCATION, "New degree must be at least 1."_s);

	if (_points.GetCount() < newDegree + 1)
		return IllegalArgumentError(MAXON_SOURCE_LOCATION, "Not enough control points for this new degree of curve."_s);

	_curveDegree = newDegree;
	_knots.Resize(_points.GetCount() + _curveDegree + 1) iferr_return;

	_InitKnots(knotMode) iferr_return;

	_memInit = true;
	return OK;
}


Result<void> BaseNURBSCurve::InsertKnot(Float s, Int nTimes)
{
	iferr_scope;

	Float u    = MapStoU(s);
	Int   span = FindSpan(u) iferr_return;

	return InsertKnot(u, span, nTimes);
}

Result<void> BaseNURBSCurve::InsertKnot(Float u, Int span, Int nTimes)
{
	iferr_scope;

	if (MAXON_UNLIKELY(!_memInit))
		return IllegalStateError(MAXON_SOURCE_LOCATION, "Function 'Init' has not been called before."_s);

	if (MAXON_UNLIKELY(span < 0 || span >= _knots.GetCount()-1))
		return IllegalArgumentError(MAXON_SOURCE_LOCATION, "span outside knot range"_s);

	KnotInfo info = GetKnotInfo(span) iferr_return;

	if (info.multiplicity + nTimes > _curveDegree)
		return IllegalArgumentError(MAXON_SOURCE_LOCATION, "Multiplicity of final knot higher than degree of curve."_s);

	// save old data
	BaseArray<Vector4d> oPoints;
	BaseArray<Float>       oKnots;

	oPoints .CopyFrom(_points) iferr_return;
	oKnots  .CopyFrom(_knots) iferr_return;

	// resize data
	Init(_points.GetCount() + nTimes, _curveDegree) iferr_return;

	// load new knot vector
	Int i, j, l;
	for (i = 0; i <= span; i++)
		_knots[i] = oKnots[i];

	for (i = 1; i <= nTimes; i++)
		_knots[span+i] = u;

	for (i = span+1; i < oKnots.GetCount(); i++)
		_knots[i+nTimes] = oKnots[i];

	// save unaltered control points
	BaseArray<Vector4d> rtemp; rtemp.Resize(_curveDegree+1) iferr_return;

	for (i = 0; i <= span-_curveDegree; i++)
		_points[i]  = oPoints[i];

	for (i = span; i < oPoints.GetCount(); i++)
		_points [i+nTimes] = oPoints[i];

	for (i = 0; i <= _curveDegree - info.multiplicity; i++)
		rtemp[i] = NormalToHomogeneous(oPoints[span - _curveDegree +i]);

	// Insert the knot nTimes
	Float alpha;
	l = 0;
	for (j = 1; j <= nTimes; j++)
	{
		l = span - _curveDegree + j;
		for (i = 0; i <= _curveDegree - j - info.multiplicity; i++)
		{
			alpha    = (u - oKnots[l+i]) * Inverse(oKnots[i+span+1] - oKnots[l+i]);
			rtemp[i] = alpha*rtemp[i+1] + (1.0_f - alpha)*rtemp[i];
		}

		_points[l]                 = HomogeneousToNormal(rtemp[0]);
		_points[span + nTimes - j] = HomogeneousToNormal(rtemp[_curveDegree - j]);
	}

	// load remaining control points
	l = span - _curveDegree + nTimes;
	for (i = l+1; i < span; i++)
		_points[i]  = HomogeneousToNormal(rtemp[i-l]);

	return OK;
}


Result<void> BaseNURBSCurve::_ComputeBasisFunctions(Float u, Int span, Int maxDegree)
{
	iferr_scope;

	SetMin(maxDegree, _curveDegree);

	// alloc mem if necessary
	_left .Resize(_curveDegree+1) iferr_return;
	_right.Resize(_curveDegree+1) iferr_return;
	_ndu  .Resize(_curveDegree+1, _curveDegree+1) iferr_return;
	_a    .Resize(_curveDegree+1, _curveDegree+1) iferr_return;
	_basis.Resize(2+1, _curveDegree+1) iferr_return;

  Float saved, temp;
  Int j, r, k;

  _ndu(0, 0) = 1.0;
  for (j = 1; j <= _curveDegree; j++)
	{
    _left[j]  = u - _knots[span+1-j];
    _right[j] = _knots[span+j] - u;
    saved    = 0.0;
    
    for (r = 0; r < j; r++)
		{
      // lower triangle
      _ndu(j, r) = _right[r+1] + _left[j-r];
      temp       = _ndu(r, j-1) * Inverse(_ndu(j, r));

			// upper triangle
      _ndu(r, j) = saved + _right[r+1] * temp;
      saved      = _left[j-r] * temp;
    }

    _ndu(j, j) = saved;
  }

  for (j = 0; j <= _curveDegree; j++)
    _basis(0, j) = _ndu(j, _curveDegree);

  // compute the derivatives
	for (r = 0; r <= _curveDegree; r++)
	{
    Int s1 = 0;
		Int s2 = 1; // alternate rows in array a

    _a(0, 0) = 1.0;

    // compute the kth derivative
    for (k = 1; k <= maxDegree; k++)
		{
      Float d  = 0.0;
      Int   rk = r - k;
			Int   pk = _curveDegree - k;

      if (r >= k)
			{
				_a(s2, 0) = _a(s1, 0) * Inverse(_ndu(pk+1, rk));
				d         = _a(s2, 0) * _ndu(rk, pk);
      }

		  Int j1 = -rk;
  	  if (rk >= -1)
				j1 = 1;

			Int j2 = _curveDegree - r;
      if (r-1 <= pk)
				j2 = k-1;

      for (j = j1; j <= j2; j++)
			{
				_a(s2, j) = (_a(s1, j) - _a(s1, j-1)) * Inverse(_ndu(pk+1, rk+j));
				d += _a(s2, j) * _ndu(rk+j, pk);
      }
      
      if (r <= pk)
			{
				_a(s2, k) = -_a(s1, k-1) * Inverse(_ndu(pk+1, r));
				d += _a(s2, k) * _ndu(r, pk);
      }
      _basis(k, r) = d;
      j = s1; s1 = s2; s2 = j; // switch rows
    }
  }

  // multiply through by the correct factors
  r = _curveDegree;
  for (k = 1; k <= maxDegree; k++)
	{
    for (j = 0; j <= _curveDegree; j++)
      _basis(k, j) *= Float(r);

		r *= _curveDegree - k;
  }
	
	return OK;
}

Result<Vector> BaseNURBSCurve::GetPoint(Int i)
{
	if (MAXON_UNLIKELY(i < 0 || i >= _points.GetCount()))
		return IllegalArgumentError(MAXON_SOURCE_LOCATION, "Point index outside range"_s);

	return _points[i].GetVector3();
}

Result<Float> BaseNURBSCurve::GetWeight(Int i)
{
	if (MAXON_UNLIKELY(i < 0 || i >= _points.GetCount()))
		return IllegalArgumentError(MAXON_SOURCE_LOCATION, "Point index outside range"_s);

	return _points[i].w;
}

Result<Float> BaseNURBSCurve::GetKnot(Int i)
{
	if (MAXON_UNLIKELY(i < 0 || i >= _knots.GetCount()))
		return IllegalArgumentError(MAXON_SOURCE_LOCATION, "Knot index outside range"_s);

	return _knots[i];
}

Result<Int> BaseNURBSCurve::FindSpan(Float u)
{
	Int kCnt = _knots.GetCount();

	if (u < _knots[0] || u > _knots[kCnt-1])
	  return IllegalArgumentError(MAXON_SOURCE_LOCATION, "Parameter u outside knot range."_s);

	if (CompareFloatTolerant(u, _knots[kCnt-1]))
	{
		// search for last possible real span when having a clamped knot vector
		Int res = kCnt - 1;
		while (res > 1 && _knots[res] == _knots[res-1])
			res--;

    return res > 1 ? res-1 : res;
	}
	else if (CompareFloatTolerant(u, _knots[0]))
	{
		// search for first real span when having a clamped knot vector
		Int res = 0;
		while ((res < kCnt-1) && CompareFloatTolerant(_knots[res], _knots[res+1]))
			res++;

    return res;
	}

	// search span with midpoint algorithm
  Int low  = 0;
  Int high = kCnt-1;
  Int mid = (low+high) / 2;

  while (u < _knots[mid] || u >= _knots[mid+1])
	{
    if (u < _knots[mid])
      high = mid;
    else
      low = mid;
    mid = (low+high) / 2;
  }

	// safety check due to numerical inaccuracies
	if (MAXON_UNLIKELY(mid > kCnt - _curveDegree - 2))
		mid = kCnt - _curveDegree - 2;

	if (MAXON_UNLIKELY(mid < 0))
		mid = 0;

  return mid;
}

Float BaseNURBSCurve::GetUmin()
{
	return _knots[_curveDegree];
}

Float BaseNURBSCurve::GetUmax()
{
	return _knots[_knots.GetCount()-_curveDegree-1];
}

Float BaseNURBSCurve::MapStoU(Float s)
{
	Float umin = GetUmin();
	Float umax = GetUmax();
	return s*(umax - umin) + umin;
}

Float BaseNURBSCurve::MapUtoS(Float u)
{
	Float umin = GetUmin();
	Float umax = GetUmax();
	return (u - umin) * Inverse(umax - umin);
}

Result<Vector> BaseNURBSCurve::EvaluateAt(Float u, Int span)
{
	iferr_scope;

	if (MAXON_UNLIKELY(!_memInit))
		return IllegalStateError(MAXON_SOURCE_LOCATION, "Function 'Init' has not been called before."_s);

	if (MAXON_UNLIKELY(span < 0 || span >= _knots.GetCount()-1))
		return IllegalArgumentError(MAXON_SOURCE_LOCATION, "span outside knot range"_s);

	if (MAXON_UNLIKELY(u < _knots[span] || u > _knots[span+1]))
		return IllegalArgumentError(MAXON_SOURCE_LOCATION, "u outside knot span"_s);

	_ComputeBasisFunctions(u, span, 0) iferr_return;

	Vector4d C = _ComputeHomogeneousC(u, span, 0) iferr_return;

	return HomogeneousToNormal(C).GetVector3();
}

Result<Vector4d> BaseNURBSCurve::_ComputeHomogeneousC(Float u, Int span, Int deg)
{
	iferr_scope;

	Vector4d sum = Vector4d(0.0, 0.0, 0.0, 0.0);
  for (Int j = 0; j <= _curveDegree; j++)
		sum += _basis(deg, j) * NormalToHomogeneous(_points[span - _curveDegree + j]);

	return sum;
}

Result<Vector> BaseNURBSCurve::DeriveAt(Float u, Int span)
{
	iferr_scope;

	_ComputeBasisFunctions(u, span, 1) iferr_return;

	Vector4d C0 = _ComputeHomogeneousC(u, span, 0) iferr_return;
	Vector4d C1 = _ComputeHomogeneousC(u, span, 1) iferr_return;

	Vector A0 = HomogeneousToNormal(C0).GetVector3();
	Vector A1 = C1.GetVector3();

	Float  w0 = C0.w;
	Float  w1 = C1.w;

	return (A1 - w1*A0) * Inverse(w0) * (GetUmax() - GetUmin());
}

Result<Vector> BaseNURBSCurve::EvaluateAt(Float s)
{
	iferr_scope;

	Float u    = MapStoU(Clamp01(s));
	Int   span = FindSpan(u) iferr_return;

	return EvaluateAt(u, span);
}

Result<Vector> BaseNURBSCurve::DeriveAt(Float s)
{
	iferr_scope;

	Float u    = MapStoU(Clamp01(s));
	Int   span = FindSpan(u) iferr_return;

	return DeriveAt(u, span);
}

Result<Int> BaseNURBSCurve::GetDegree()
{
	iferr_scope;

	if (!_memInit)
		return IllegalStateError(MAXON_SOURCE_LOCATION, "Function 'Init' not called before."_s);

	return _curveDegree;
}

Result<Int> BaseNURBSCurve::GetMaxDegree()
{
	iferr_scope;

	if (!_memInit)
		return IllegalStateError(MAXON_SOURCE_LOCATION, "Function 'Init' not called before."_s);

	return _points.GetCount() + _curveDegree + 1;
}


Result<Int> BaseNURBSCurve::GetPointCount()
{
	iferr_scope;

	if (!_memInit)
		return IllegalStateError(MAXON_SOURCE_LOCATION, "Function 'Init' not called before."_s);

	return _points.GetCount();
}

Result<Int> BaseNURBSCurve::GetWeightCount()
{
	return GetPointCount();
}

Result<Int> BaseNURBSCurve::GetKnotCount()
{
	iferr_scope;

	if (!_memInit)
		return IllegalStateError(MAXON_SOURCE_LOCATION, "Function 'Init' not called before."_s);

	return _knots.GetCount();
}

Result<void> BaseNURBSCurve::SetPoint(Int i, const Vector& point)
{
	iferr_scope;

	_dirty = true;

	if (!_memInit)
		return IllegalStateError(MAXON_SOURCE_LOCATION, "Function 'Init' not called before."_s);

	if (i < 0 || i >= _points.GetCount())
		return IllegalArgumentError(MAXON_SOURCE_LOCATION, "Point index outside range."_s);

	_points[i] = Vector4d(point);

	return OK;
}

Result<void> BaseNURBSCurve::SetWeight(Int i, Float weight)
{
	iferr_scope;

	_dirty = true;

	if (!_memInit)
		return IllegalStateError(MAXON_SOURCE_LOCATION, "Function 'Init' not called before."_s);

	if (i < 0 || i >= _points.GetCount())
		return IllegalArgumentError(MAXON_SOURCE_LOCATION, "Weight index outside range."_s);

	if (weight < 0)
		return IllegalArgumentError(MAXON_SOURCE_LOCATION, "Weight is negative."_s);

	_points[i].w = weight;

	return OK;
}

Result<void> BaseNURBSCurve::SetKnot(Int i, Float knot)
{
	iferr_scope;

	_dirty = true;

	if (!_memInit)
		return IllegalStateError(MAXON_SOURCE_LOCATION, "Function 'Init' not called before."_s);

	if (i < 0 || i >= _knots.GetCount())
		return IllegalArgumentError(MAXON_SOURCE_LOCATION, "Knot index outside range."_s);

	_knots[i] = knot;

	return _CheckForKnotConsistency();
}


Result<void> BaseNURBSCurve::SetPoints(const BaseArray<Vector>& points)
{
	iferr_scope;

	_dirty = true;

	if (!_memInit)
		return IllegalStateError(MAXON_SOURCE_LOCATION, "Function 'Init' not called before."_s);

	if (points.GetCount() != _points.GetCount())
		return IllegalArgumentError(MAXON_SOURCE_LOCATION, "Wrong number of points."_s);

	for (Int i = 0; i < _points.GetCount(); i++)
	{
		SetPoint(i, points[i]) iferr_return;
	}

	return OK;
}

Result<void> BaseNURBSCurve::SetWeights(const BaseArray<Float>& weights)
{
	iferr_scope;

	_dirty = true;

	if (!_memInit)
		return IllegalStateError(MAXON_SOURCE_LOCATION, "Function 'Init' not called before."_s);

	if (weights.GetCount() != _points.GetCount())
		return IllegalArgumentError(MAXON_SOURCE_LOCATION, "Wrong number of weights."_s);

	for (Int i = 0; i < _points.GetCount(); i++)
	{
		SetWeight(i, weights[i]) iferr_return;
	}

	return OK;
}

Result<void> BaseNURBSCurve::SetKnots(NURBSCURVE_KNOTMODE mode)
{
	iferr_scope;

	_dirty = true;

	if (!_memInit)
		return IllegalStateError(MAXON_SOURCE_LOCATION, "Function 'Init' not called before."_s);

	return _InitKnots(mode);
}

Result<void> BaseNURBSCurve::SetKnots(const BaseArray<Float>& knots)
{
	iferr_scope;

	_dirty = true;

	if (!_memInit)
		return IllegalStateError(MAXON_SOURCE_LOCATION, "Function 'Init' not called before."_s);

	if (knots.GetCount() != _knots.GetCount())
		return IllegalArgumentError(MAXON_SOURCE_LOCATION, "Wrong number of knots."_s);

	_knots.CopyFrom(knots) iferr_return;

	return _CheckForKnotConsistency();
}

#if 0
void BaseNURBSCurve::_ComputeBasisFunctions(Float u, Int span, Int degree)
{
	_N[0] = 1.0;

	for (Int j = 1; j <= degree; j++)
	{
		_left[j]  = u - _knots[span + 1 - j];
		_right[j] = _knots[span + j] - u;

		Float temp, saved = 0.0;
		for (Int r = 0; r < j; r++)
		{
			temp  = _N[r] * Inverse(_right[r+1] + _left[j-r]);
			_N[r] = saved + _right[r+1] * temp;
			saved = _left[j-r] * temp;
		}
		_N[j] = saved;
	}
}

void BaseNURBSCurve::_ComputeBasisFunctions(Float u, Int span, Int degree, BaseArray<Float>& basis)
{
	_ComputeBasisFunctions(u, span, degree);

	for (Int i = 0; i < _points.GetCount(); i++)
		basis[i] = 0.0;

	for (Int i = 0; i <= degree; i++)
		basis[span - degree + i] = _N[i];
}


Result<Float> BaseNURBSCurve::_ComputeOneBasisFunction(Float u, Int span, Int degree)
{
	iferr_scope;

	Int kCnt = _knots.GetCount();
	Int m    = _knots[kCnt-1];

	if ((span == 0 && u == _knots[0]) || (span == m-degree-1 && u == _knots[m]))
		return 1.0;

	if (u < _knots[span] || u >= _knots[span+degree+1])
		return 0.0;

	// Init zero degree functions
	BaseArray<Float> N; N.Resize(_curveDegree+1) iferr_return;

	for (Int j = 0; j <= degree; j++)
	{
		if (u >= _knots[span+j] && u < _knots[span+j+1])
			N[j] = 1.0;
		else
		  N[j] = 0.0;
	}

	// compute triangular table
	Float Nip   = 0.0;
	Float saved = 0.0;
	Float temp;
	for (Int k = 1; k <= degree; k++)
	{
		if (N[0] == 0.0)
			saved = 0.0;
		else
			saved = (u - _knots[span]) * N[0] * Inverse(_knots[span+k] - _knots[span]);

		for (Int j = 0; j < degree-k+1; j++)
		{
			Float uleft  = _knots[span+j+1];
			Float uright = _knots[span+j+k+1];
			if (N[j+1] == 0.0)
			{
				N[j]  = saved;
				saved = 0.0;
			}
			else
			{
				temp  = N[j+1] * Inverse(uright - uleft);
				N[j]  = saved + (uright - u) * temp;
				saved = (u - uleft) * temp;
			}
		}
		Nip = N[0];
	}

	return Nip;
}

Float BaseNURBSCurve::_wik(Int span, Int degree, const BaseArray<Float>& N0)
{
	Float w = 0.0;
	for (Int i = 0; i <= degree; i++)
		w += N0[span - degree + i] * _points[span - degree + i].w;

	return w;
}

Float BaseNURBSCurve::_delta(Int i, Int span, const BaseArray<Float>& N0, const BaseArray<Float>& N1)
{
	Float l = 0.0;

	for (Int j = 0; j < i; j++)
	{
		for (Int k = i; k < _points.GetCount(); k++)
		{
			l += (N1[k] * N0[j] - N0[k] * N1[j]) * _points[j].w * _points[k].w;
		}
	}

	Float w = _wik(span, _curveDegree, N0);

	return l * Inverse(w*w);
}



#endif


} // namespace maxon
