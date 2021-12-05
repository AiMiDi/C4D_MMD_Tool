#ifndef NURBSCURVE_H__
#define NURBSCURVE_H__

#include "NURBSMath.h"
#include "maxon/utilities/resultbase.h"

namespace maxon
{

enum class NURBSCURVE_CONTINUITY
{
	OPEN     = 0, ///< Open spline with No continuity between first and last point.
	CLOSED   = 1, ///< Closed spline with position continuity (sharp cusp) between first and last point. Replaces any previous knot vector with a clamped uniform knot vector.
	PERIODIC = 2  ///< Closed spline with C2 continuity between first and last point. Replaces any previous knot vector with an unclamped uniform knot vector.
} MAXON_ENUM_LIST(NURBSCURVE_CONTINUITY);

class NURBSTests
{
public:
	void TestFunc();
};

template<Int D = DYNAMICDEGREE>
class NURBSCurveWithContinuity : public NURBSCurve<D>
{
	using Interface = typename NURBSCurve<D>::Interface;
	MAXON_IMPLEMENTATION_SIMPLE(NURBSCurveWithContinuity);

public:

	NURBSCurveWithContinuity() : NURBSCurve<D>(_clsMTable) { }

	// allocate needed memory
	// must be called once before accessing any of the other routines, otherwise you get an error
	template<typename Dummy = Result<void>>
	std::enable_if_t<D != DYNAMICDEGREE, Dummy> Init(Int points, NURBSCURVE_CONTINUITY continuity = NURBSCURVE_CONTINUITY::OPEN)
	{
		return InitInternal(points, D, continuity);
	}


	// allocate needed memory
	// must be called once before accessing any of the other routines, otherwise you get an error
	template<typename Dummy = Result<void>>
	std::enable_if_t<D == DYNAMICDEGREE, Dummy> Init(Int points, Int degree, NURBSCURVE_CONTINUITY continuity = NURBSCURVE_CONTINUITY::OPEN)
	{
		return InitInternal(points, degree, continuity);
	}

#if 0 // Disabled for now
// TODO: (Jan) please comment
	template<Int OtherN, typename Dummy = Result<void>>
	std::enable_if_t<D == DYNAMICDEGREE, Dummy> Init(Int targetDegree, const NURBSCurveWithContinuity<OtherN>& other)
	{
		iferr_scope;

		DebugAssert(targetDegree > 0);

		this->_curveDegree = targetDegree;

		return InitInternal(other);
	}


	template<Int OtherN, typename Dummy = Result<void>>
	std::enable_if_t<D != DYNAMICDEGREE, Dummy> Init(const NURBSCurveWithContinuity<OtherN>& other)
	{
		iferr_scope;

		this->_curveDegree = D;

		return InitInternal(other);
	}
#endif

	Result<Vector> EvaluateAt(Float s) const
	{
		return NURBSCurve<D>::EvaluateAt(AdjustT(s));
	}
	
	
	Result<Vector> DeriveAt(Float s) const
	{
		return NURBSCurve<D>::DeriveAt(AdjustT(s));
	}


	Int GetPointCount() const
	{
		return _numPoints;
	}


	Result<Vector> GetPoint(Int i) const
	{
		if (MAXON_UNLIKELY(i >= _numPoints))
		{
			return IllegalArgumentError(MAXON_SOURCE_LOCATION, "Supplied point index is out of range!"_s);
		}
		return NURBSCurve<D>::GetPoint(i);
	}


	Result<Vector4d> GetPointWithWeight(Int i) const
	{
		if (MAXON_UNLIKELY(i >= _numPoints))
		{
			return IllegalArgumentError(MAXON_SOURCE_LOCATION, "Supplied point index is out of range!"_s);
		}
		return NURBSCurve<D>::GetPointWithWeight(i);
	}


	const Block<const Vector4d> GetPointsWithWeights() const
	{
		const Block<const Vector4d>& points = NURBSCurve<D>::GetPointsWithWeights();
		return Block<const Vector4d>(points.GetFirst(), _numPoints);
	}


	Result<void> SetPoint(Int i, const Vector& point)
	{
		iferr_scope;

		if (MAXON_UNLIKELY(i < 0 || i >= _numPoints))
			return IllegalArgumentError(MAXON_SOURCE_LOCATION, "Point index outside range."_s);

		NURBSCurve<D>::SetPoint(i, point) iferr_return;

		if (_continuity == NURBSCURVE_CONTINUITY::CLOSED)
		{
			if (i == 0)
			{
				NURBSCurve<D>::SetPoint(_numPoints, point) iferr_return;
			}
		}
		else if (_continuity == NURBSCURVE_CONTINUITY::PERIODIC && i < this->_curveDegree)
		{
			NURBSCurve<D>::SetPoint(_numPoints + i, point) iferr_return;
		}

		return OK;
	}


	Result<void> SetPointWithWeight(Int i, const Vector4d& point)
	{
		iferr_scope;

		if (MAXON_UNLIKELY(i < 0 || i >= _numPoints))
			return IllegalArgumentError(MAXON_SOURCE_LOCATION, "Point index outside range."_s);

		NURBSCurve<D>::SetPointWithWeight(i, point) iferr_return;

		if (_continuity == NURBSCURVE_CONTINUITY::CLOSED)
		{
			if (i == 0)
			{
				NURBSCurve<D>::SetPointWithWeight(_numPoints, point) iferr_return;
			}
		}
		else if (this->_continuity == NURBSCURVE_CONTINUITY::PERIODIC && i < this->_curveDegree)
		{
			NURBSCurve<D>::SetPointWithWeight(_numPoints + i, point) iferr_return;
		}

		return OK;
	}


	Result<void> ChangePoints(const Block<const Vector>& points)
	{
		iferr_scope;

		if (MAXON_UNLIKELY(points.GetCount() != _numPoints))
			return IllegalArgumentError(MAXON_SOURCE_LOCATION, "Point index outside range."_s);

		for (Int i = 0; i < _numPoints; ++i)
		{
			NURBSCurve<D>::SetPoint(i, points[i]) iferr_return;
		}

		if (_continuity == NURBSCURVE_CONTINUITY::CLOSED)
		{
			NURBSCurve<D>::SetPoint(_numPoints, *points.GetFirst()) iferr_return;
		}
		else if (this->_continuity == NURBSCURVE_CONTINUITY::PERIODIC)
		{
			for (Int i = 0; i < this->_curveDegree; ++i)
			{
				NURBSCurve<D>::SetPoint(_numPoints + i, points[i]) iferr_return;
			}
		}

		return OK;
	}


	Result<void> SetPointsWithWeights(const Block<const Vector4d>& points)
	{
		iferr_scope;

		_numPoints = points.GetCount();

		Int pointCount = _numPoints;
		
		if (_continuity == NURBSCURVE_CONTINUITY::CLOSED)
		{
			++pointCount;
		}
		else if (_continuity == NURBSCURVE_CONTINUITY::PERIODIC)
		{
			pointCount += this->_curveDegree;
		}

		InitInternal(pointCount, this->_curveDegree, _continuity) iferr_return;

		NURBSCurve<D>::SetPointWithWeight(_numPoints, *points.GetFirst()) iferr_return;

		if (_continuity == NURBSCURVE_CONTINUITY::CLOSED)
		{
			NURBSCurve<D>::SetPointWithWeight(_numPoints, *points.GetFirst()) iferr_return;
		}
		else if (_continuity == NURBSCURVE_CONTINUITY::PERIODIC)
		{
			for (Int i = 0; i < this->_curveDegree; ++i)
			{
				NURBSCurve<D>::SetPointWithWeight(_numPoints + i, points[i]) iferr_return;
			}
		}

		return OK;
	}


	Result<void> ChangeWeights(const Block<const Float32>& weights)
	{
		return ChangeWeightsInternal(weights);
	}


	Result<void> ChangeWeights(const Block<const Float>& weights)
	{
		return ChangeWeightsInternal(weights);
	}


	Result<void> SetKnots(NURBSCURVE_KNOTMODE mode)
	{
		// We could just reset it to open after doing this instead. Needs some more thinking about.
		return IllegalStateError(MAXON_SOURCE_LOCATION, "Calling This function on a curve with periodic or closed continuity will break the continuity."_s);
	}

	Result<void> SetKnots(const BaseArray<Float>& knots)
	{
		// We could just reset it to open after doing this instead. Needs some more thinking about.
		return IllegalStateError(MAXON_SOURCE_LOCATION, "Calling This function on a curve with periodic or closed continuity will break the continuity."_s);
	}

private:

	MAXON_ATTRIBUTE_FORCE_INLINE Float AdjustT(Float s) const
	{
		if (_continuity == NURBSCURVE_CONTINUITY::PERIODIC)
		{
			Float minimumT = 1.0_f - (1.0_f / Float(_numPoints));

			s += minimumT;
			s = FMod(s, 1.0_f);
		}
		else // for open and closed
		{
			s = Clamp01(s);
		}

		return s;
	}


	Result<void> InitInternal(Int numPoints, Int degree, NURBSCURVE_CONTINUITY continuity)
	{
		iferr_scope;

		_numPoints = numPoints;

		_continuity = continuity;

		switch (continuity)
		{
			case NURBSCURVE_CONTINUITY::OPEN:
				return CallParentInit(numPoints, degree, NURBSCURVE_KNOTMODE::CLAMPED_UNIFORM);
				break;
			case NURBSCURVE_CONTINUITY::CLOSED:
				return CallParentInit(numPoints + 1, degree, NURBSCURVE_KNOTMODE::CLAMPED_UNIFORM);
				break;
			case NURBSCURVE_CONTINUITY::PERIODIC:
				return CallParentInit(numPoints + degree, degree, NURBSCURVE_KNOTMODE::UNCLAMPED_UNIFORM);
				break;
		}

		return OK;
	}


	template<typename Dummy = Result<void>>
	std::enable_if_t<D != DYNAMICDEGREE, Dummy> CallParentInit(Int numPoints, Int degree, NURBSCURVE_KNOTMODE mode)
	{
		return NURBSCurve<D>::Init(numPoints, mode);
	}


	template<typename Dummy = Result<void>>
	std::enable_if_t<D == DYNAMICDEGREE, Dummy> CallParentInit(Int numPoints, Int degree, NURBSCURVE_KNOTMODE mode)
	{
		return NURBSCurve<D>::Init(numPoints, degree, mode);
	}


	template<typename T>
	Result<void> ChangeWeightsInternal(const Block<const T>& weights)
	{
		iferr_scope;

		if (MAXON_UNLIKELY(weights.GetCount() != _numPoints))
			return IllegalArgumentError(MAXON_SOURCE_LOCATION, "Point index outside range."_s);

		for (Int i = 0; i < _numPoints; ++i)
		{
			NURBSCurve<D>::SetWeight(i, Float(weights[i])) iferr_return;
		}

		if (_continuity == NURBSCURVE_CONTINUITY::CLOSED)
		{
			NURBSCurve<D>::SetWeight(_numPoints, Float(*weights.GetFirst())) iferr_return;
		}
		else if (_continuity == NURBSCURVE_CONTINUITY::PERIODIC)
		{
			for (Int i = 0; i < this->_curveDegree; ++i)
			{
				NURBSCurve<D>::SetWeight(_numPoints + i, Float(weights[i])) iferr_return;
			}
		}

		return OK;
	}

private:

	using ParentType = NURBSCurve<D>;

	Int _numPoints = 0;
	NURBSCURVE_CONTINUITY _continuity = NURBSCURVE_CONTINUITY::OPEN;
};

template<Int D>
MAXON_IMPLEMENTATION_REGISTER_SIMPLE(NURBSCurveWithContinuity<D>);
} // namespace maxon

#endif // NURBSCURVE_H__
