#ifndef NURBSMATH_H__
#define NURBSMATH_H__

#include "maxon/vector4d.h"
#include "matrix_nxm.h"
#include "maxon/algorithms.h"

namespace maxon
{

class NURBSCurveInterface
{
	MAXON_INTERFACE_SIMPLE_VIRTUAL(NURBSCurveInterface, MAXON_REFERENCE_NORMAL);

public:

	MAXON_METHOD Result<Vector> EvaluateAt(Float s) const;

	MAXON_METHOD Result<Vector> DeriveAt(Float s) const;

	MAXON_METHOD Result<Int> GetDegree() const;

	MAXON_METHOD Result<Int> GetMaxDegree() const;

	MAXON_METHOD Int GetPointCount() const;

	MAXON_METHOD Result<Int> GetWeightCount() const;

	MAXON_METHOD Result<Vector> GetPoint(Int i) const;

	MAXON_METHOD Result<Vector4d> GetPointWithWeight(Int i) const;

	MAXON_METHOD const Block<const Vector4d> GetPointsWithWeights() const;

	MAXON_METHOD Result<Float> GetWeight(Int i) const;

	MAXON_METHOD Result<void> SetPoint(Int i, const Vector& point);

	MAXON_METHOD Result<void> SetPointWithWeight(Int i, const Vector4d& point);

	MAXON_METHOD Result<void> ChangePoints(const Block<Vector>& points);

	MAXON_METHOD Result<void> SetPointsWithWeights(const Block<const Vector4d>& points);

	MAXON_METHOD Result<void> SetWeight(Int i, Float weight);

	MAXON_METHOD Result<void> ChangeWeights(const Block<const Float>& weights);

	MAXON_METHOD Result<void> ChangeWeights(const Block<const Float32>& weights);
};


#include "NURBSMath1.hxx"
#include "NURBSMath2.hxx"


namespace detail
{


Vector4d HomogeneousToNormal(const Vector4d& p);


Vector4d NormalToHomogeneous(const Vector4d& p);


template <Int N, typename T>
class StackArrayHelper
{
public:

	ResultOk<void> Resize(Int cnt)
	{
		DebugAssert(cnt == N);
		return OK;
	}

	Int GetCount() const
	{
		return N;
	}

	T& operator[](Int location)
	{
		DebugAssert(location < N);
		return _data[location];
	}

	const T& operator[](Int location) const
	{
		DebugAssert(location < N);
		return _data[location];
	}

private:
	T _data[N];
};


template <typename T, Int N, Int M = N>
class StackMatrixHelper
{
public:

	ResultOk<void> Resize(Int countX, Int countY)
	{
		DebugAssert(countX == N && countY == M);
		return OK;
	}

	T& operator()(Int x, Int y)
	{
		DebugAssert(x < N && y < M);
		return _data[x][y];
	}

	const T& operator()(Int x, Int y) const
	{
		DebugAssert(x < N && y < M);
		return _data[x][y];
	}

private:
	T _data[N][M];
};


// When the degree used for the NURBS curve is set to be dynamic, then the compile-time cache sizes will be 0.
// Thus we need to check for 0 to decide if we want to use stack- or heap-based containers.
static constexpr Int SMALLSTACK = 0;

// Three different containers aliases that are represented by wrapped C-style arrays on the stack when we have a compile-time size,
// or by heap-based container classes.
template <Int N, typename T>
using SmallStackArray = typename std::conditional_t<N == SMALLSTACK, BaseArray<T>, StackArrayHelper<N, T>>;

template <Int N, typename T>
using SmallSquareStackMatrix = typename std::conditional_t<N == SMALLSTACK, MatrixNxM<T>, StackMatrixHelper<T, N, N>>;

template <Int N, Int M, typename T>
using SmallStackMatrix = typename std::conditional_t<N == SMALLSTACK || M == SMALLSTACK, MatrixNxM<T>, StackMatrixHelper<T, N, M>>;


} // namespace detail


enum class NURBSCURVE_KNOTMODE
{
	CLAMPED_UNIFORM = 0,	///< Clamped uniform (open uniform / quasi uniform) NURBS/B-Spline/Bezier knot vector with end knots of multiplicity of degree. Internal knots are uniform e.g. [0, 0, 0, 1/3, 2/3, 1, 1, 1]. If there are no internal knots then the spline is equal to a bezier spline of same degree e.g. [0, 0, 0, 0, 1, 1, 1, 1]
	CLAMPED_CHORDAL = 1,	///< Clamped nonuniform knot vector whose inner knots are computed according to the actual position of control points in space according to the chord length method. Works only correct if SetPoints has been called before since the routines needs to compute the point distances.
	CLAMPED_CENTRIPETAL = 2,	///< Clamped nonuniform knot vector whose inner knots are computed according to the actual position of control points in space according to the centripetal method.Works only correct if SetPoints has been called before since the routines needs to compute the point distances.
	UNCLAMPED_UNIFORM = 3, 	///< uniform knot vector e.g. [0.0, 0.25, 0.5, 0.75, 1.0]. Mostly useful for periodic (closed) splines
	USER_DEFINED = 4 	///< Arbitrary knot vector, supplied by the user.
} MAXON_ENUM_LIST(NURBSCURVE_KNOTMODE);


struct KnotInfo
{
	Int firstPosition = 0;
	Int multiplicity = 0;
	Bool innerKnot = false;
};


// When creating a NURBS curve the user may supply DYNAMICDEGREE as an indicator that the degree shall not be part
// of the curve's type. This will prevent performance optimization by using stack-allocated caches.
static constexpr Int DYNAMICDEGREE = -1;


template<Int D = DYNAMICDEGREE>
class NURBSCurve : protected NURBSCurveInterface
{
	MAXON_IMPLEMENTATION_SIMPLE(NURBSCurve);
	static_assert(D != 0, "Degree 0 curve is not allowed!");

protected:

	// This constructor is necessary to forward the constructor call from the derived classes to the base interface
	// where it will initialize the function table.
	explicit NURBSCurve(const Interface::MTable& derivedTable) : NURBSCurveInterface(derivedTable) { }

public:

	NURBSCurve() : NURBSCurveInterface(_clsMTable) { }

	// allocate needed memory
	// must be called once before accessing any of the other routines, otherwise you get an error
	template<typename Dummy = Result<void>>
	std::enable_if_t<D != DYNAMICDEGREE, Dummy> Init(Int points, NURBSCURVE_KNOTMODE mode = NURBSCURVE_KNOTMODE::CLAMPED_UNIFORM)
	{
		return InitInternal(points, D, mode);
	}


	// allocate needed memory
	// must be called once before accessing any of the other routines, otherwise you get an error
	template<typename Dummy = Result<void>>
	std::enable_if_t<D == DYNAMICDEGREE, Dummy> Init(Int points, Int degree, NURBSCURVE_KNOTMODE mode = NURBSCURVE_KNOTMODE::CLAMPED_UNIFORM)
	{
		return InitInternal(points, degree, mode);
	}

#if 0
	template<Int OtherN, typename Dummy = Result<void>>
	std::enable_if_t<D == DYNAMICDEGREE, Dummy> Init(Int targetDegree, const NURBSCurve<OtherN>& other)
	{
		iferr_scope;

		DebugAssert(targetDegree > 0);

		_curveDegree = targetDegree;

		return InitInternal(other);
	}


	template<Int OtherN, typename Dummy = Result<void>>
	std::enable_if_t<D != DYNAMICDEGREE, Dummy> Init(const NURBSCurve<OtherN>& other)
	{
		iferr_scope;

		_curveDegree = D;

		return InitInternal(other);
	}
#endif


	// delete all internal allocated mem and reset data
	void Reset()
	{
		_memInit = false;

		_points.Reset();
		_knots.Reset();
		_curveDegree = 0;
	}


	Result<Vector> EvaluateAt(Float s) const
	{
		iferr_scope;

		Float u = MapStoU(Clamp01(s));
		Int span = FindSpan(u) iferr_return;

		return EvaluateAt(u, span);
	}


	Result<Vector> DeriveAt(Float s) const
	{
		iferr_scope;

		Float u = MapStoU(Clamp01(s));
		Int span = FindSpan(u) iferr_return;

		return DeriveAt(u, span);
	}


	Result<Int> GetDegree() const
	{
		iferr_scope;

		if (MAXON_UNLIKELY(!_memInit))
			return IllegalStateError(MAXON_SOURCE_LOCATION, "Function 'Init' not called before."_s);

		return _curveDegree;
	}


	Result<Int> GetMaxDegree() const
	{
		iferr_scope;

		if (MAXON_UNLIKELY(!_memInit))
			return IllegalStateError(MAXON_SOURCE_LOCATION, "Function 'Init' not called before."_s);

		return _points.GetCount() + _curveDegree + 1;
	}


	Int GetPointCount() const
	{
		iferr_scope;

		if (MAXON_UNLIKELY(!_memInit))
			return 0;

		return _points.GetCount();
	}


	Result<Int> GetWeightCount() const
	{
		return GetPointCount();
	}
	

	Result<Vector> GetPoint(Int i) const
	{
		if (MAXON_UNLIKELY(i < 0 || i >= _points.GetCount()))
			return IllegalArgumentError(MAXON_SOURCE_LOCATION, "Point index outside range!"_s);

		return _points[i].GetVector3();
	}


	Result<Vector4d> GetPointWithWeight(Int i) const
	{
		if (MAXON_UNLIKELY(i < 0 || i >= _points.GetCount()))
			return IllegalArgumentError(MAXON_SOURCE_LOCATION, "Point index outside range!"_s);
		return _points[i];
	}


	const Block<const Vector4d> GetPointsWithWeights() const
	{
		return _points;
	}


	Result<Float> GetWeight(Int i) const
	{
		if (MAXON_UNLIKELY(i < 0 || i >= _points.GetCount()))
			return IllegalArgumentError(MAXON_SOURCE_LOCATION, "Point index outside range!"_s);

		return _points[i].w;
	}


	const BaseArray<Float>& GetKnots() const
	{
		return _knots;
	}


	NURBSCURVE_KNOTMODE GetKnotMode() const
	{
		return _knotMode;
	}


	Result<void> SetPoint(Int i, const Vector& point)
	{
		iferr_scope;

		if (MAXON_UNLIKELY(!_memInit))
			return IllegalStateError(MAXON_SOURCE_LOCATION, "Function 'Init' not called before."_s);

		if (MAXON_UNLIKELY(i < 0 || i >= _points.GetCount()))
			return IllegalArgumentError(MAXON_SOURCE_LOCATION, "Point index outside range."_s);

		_points[i] = Vector4d(point);

		return OK;
	}


	Result<void> SetPointWithWeight(Int i, const Vector4d& point)
	{
		iferr_scope;

		if (MAXON_UNLIKELY(!_memInit))
			return IllegalStateError(MAXON_SOURCE_LOCATION, "Function 'Init' not called before."_s);

		if (MAXON_UNLIKELY(i < 0 || i >= _points.GetCount()))
			return IllegalArgumentError(MAXON_SOURCE_LOCATION, "Point index outside range."_s);

		_points[i] = point;

		return OK;
	}


	Result<void> ChangePoints(const Block<const Vector>& points)
	{
		iferr_scope;

		if (MAXON_UNLIKELY(!_memInit))
			return IllegalStateError(MAXON_SOURCE_LOCATION, "Function 'Init' not called before."_s);

		if (MAXON_UNLIKELY(points.GetCount() != _points.GetCount()))
			return IllegalArgumentError(MAXON_SOURCE_LOCATION, "Wrong number of points."_s);

		for (Int i = 0; i < _points.GetCount(); ++i)
		{
			SetPoint(i, points[i]) iferr_return;
		}

		return OK;
	}


	Result<void> SetPoints(const Block<const Vector>& points)
	{
		iferr_scope;

		if (MAXON_UNLIKELY(!_memInit))
			return IllegalStateError(MAXON_SOURCE_LOCATION, "Function 'Init' not called before."_s);

		if (MAXON_UNLIKELY(points.GetCount() < _curveDegree + 1))
			return IllegalArgumentError(MAXON_SOURCE_LOCATION, "Not enough control points for this degree of curve."_s);

		Int newPointCount = points.GetCount();
		const Bool differentPointCount =  newPointCount != _points.GetCount();

		_points.Resize(newPointCount) iferr_return;

		for (Int i = 0; i < newPointCount; ++i)
		{
			_points[i] = Vector4d(points[i]);
		}

		if (differentPointCount)
		{
			_knots.Resize(newPointCount + _curveDegree + 1) iferr_return;
			InitKnots(_knotMode) iferr_return;
		}

		return OK;
	}


	Result<void> SetPointsWithWeights(const Block<const Vector4d>& points)
	{
		iferr_scope;

		if (MAXON_UNLIKELY(!_memInit))
			return IllegalStateError(MAXON_SOURCE_LOCATION, "Function 'Init' not called before."_s);

		if (MAXON_UNLIKELY(points.GetCount() < _curveDegree + 1))
			return IllegalArgumentError(MAXON_SOURCE_LOCATION, "Not enough control points for this degree of curve."_s);

		Int newPointCount = points.GetCount();
		const Bool differentPointCount = newPointCount != _points.GetCount();

		_points.CopyFrom(points) iferr_return;
		
		if (differentPointCount)
		{
			_knots.Resize(newPointCount + _curveDegree + 1) iferr_return;
			InitKnots(_knotMode) iferr_return;
		}

		return OK;
	}


	Result<void> SetWeight(Int i, Float weight)
	{
		iferr_scope;

		if (MAXON_UNLIKELY(!_memInit))
			return IllegalStateError(MAXON_SOURCE_LOCATION, "Function 'Init' not called before."_s);

		if (MAXON_UNLIKELY(i < 0 || i >= _points.GetCount()))
			return IllegalArgumentError(MAXON_SOURCE_LOCATION, "Weight index outside range."_s);

		if (MAXON_UNLIKELY(weight < 0))
			return IllegalArgumentError(MAXON_SOURCE_LOCATION, "Weight is negative."_s);

		_points[i].w = weight;

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


	Result<void> SetKnot(Int i, Float knot)
	{
		iferr_scope;

		if (MAXON_UNLIKELY(!_memInit))
			return IllegalStateError(MAXON_SOURCE_LOCATION, "Function 'Init' not called before."_s);

		if (MAXON_UNLIKELY(i < 0 || i >= _knots.GetCount()))
			return IllegalArgumentError(MAXON_SOURCE_LOCATION, "Knot index outside range."_s);

		_knots[i] = knot;

		// We might want to only do the consistency check during debug. If a faulty knot was set, this will then just lead to
		// Undefined spline behavior. However, it would not lead to crashes or anything. This might be a performance improvement.
		return CheckForKnotConsistency();
	}


	Result<void> SetKnots(NURBSCURVE_KNOTMODE mode)
	{
		iferr_scope;

		if (MAXON_UNLIKELY(!_memInit))
			return IllegalStateError(MAXON_SOURCE_LOCATION, "Function 'Init' not called before."_s);

		return InitKnots(mode);
	}


	// The knot vector can, by its definition, be any sequence of numbers provided that each one is greater than or equal to the preceding one.
	Result<void> SetKnots(const BaseArray<Float>& knots)
	{
		iferr_scope;

		if (MAXON_UNLIKELY(!_memInit))
			return IllegalStateError(MAXON_SOURCE_LOCATION, "Function 'Init' not called before."_s);

		if (MAXON_UNLIKELY(knots.GetCount() != _knots.GetCount()))
			return IllegalArgumentError(MAXON_SOURCE_LOCATION, "Wrong number of knots."_s);

		_knots.CopyFrom(knots) iferr_return;

		// We might want to only do the consistency check during debug. If a faulty knot was set, this will then just lead to
		// Undefined spline behavior. However, it would not lead to crashes or anything. This might be a performance improvement.
		return CheckForKnotConsistency();
	}


	Result<void> InsertKnot(Float s, Int nTimes)
	{
		iferr_scope;

		Float u = MapStoU(s);
		Int span = FindSpan(u) iferr_return;

		return InsertKnot(u, span, nTimes);
	}
	

protected:


	// This function gets the points for the original and the derived point at u and then calculates the difference 
	// between those points while respecting their homogeneous coordinates in a way that is not totally clear to me
	// and multiplies it by the width of the knot vector.
	Result<Vector> DeriveAt(Float u, Int span) const
	{
		iferr_scope;

		// holds basis function and its derivatives up to degree 2
		detail::SmallStackMatrix<2 + 1, D + 1, Float> basisFunctions;
		basisFunctions.Resize(2 + 1, _curveDegree + 1) iferr_return;

		ComputeBasisFunctions(u, span, 1, basisFunctions) iferr_return;

		Vector4d C0 = CalculatePointFromBasisFunctions(span, 0, basisFunctions) iferr_return;
		Vector4d C1 = CalculatePointFromBasisFunctions(span, 1, basisFunctions) iferr_return;

		Vector A0 = detail::HomogeneousToNormal(C0).GetVector3();
		Vector A1 = C1.GetVector3();

		Float  w0 = C0.w;
		Float  w1 = C1.w;

		return (A1 - w1 * A0) * Inverse(w0) * (GetUmax() - GetUmin());
	}


	/// This algorithm inserts nTimes new points into the knot vector.
	/// The naive way would be to simply insert new points into the vector and be done with it.
	/// This would change curve though and the goal of this function is to add additional points into both the knot vector and the
	/// control point vector so that the shape of the curve remains unchanged.
	/// 
	/// This algorithm is also described in the NURBS book on page 151.
	/// Inserting a new control point and knot works similarly to the deCasteljau algorithm.
	/// When inserting new knots, we need to calculate the appropriate control knots that will keep the curve shape the same.
	/// This is done by linearly interpolating the original control points with an interpolation factor alpha.
	/// This alpha value is calculated for the relevant control points that affect the insertion location.
	/// It is determined by the normalized position of the new knot inside the knot-space width of the original basis functions.
	Result<void> InsertKnot(Float u, Int span, Int nTimes)
	{
		iferr_scope;

		if (MAXON_UNLIKELY(!_memInit))
			return IllegalStateError(MAXON_SOURCE_LOCATION, "Function 'Init' has not been called before."_s);

		if (MAXON_UNLIKELY(span < 0 || span >= _knots.GetCount() - 1))
			return IllegalArgumentError(MAXON_SOURCE_LOCATION, "span outside knot range"_s);

		KnotInfo info = GetKnotInfo(span) iferr_return;

		if (info.multiplicity + nTimes > _curveDegree)
			return IllegalArgumentError(MAXON_SOURCE_LOCATION, "Multiplicity of final knot higher than degree of curve."_s);

		// save old data
		BaseArray<Vector4d> oldPoints;
		BaseArray<Float> oldKnots;

		oldPoints.CopyFrom(_points) iferr_return;
		oldKnots.CopyFrom(_knots) iferr_return;

		Init(_points.GetCount() + nTimes, _curveDegree) iferr_return;

		Int i, j, l;
		// For all knots before the new ones copy them over.
		for (i = 0; i <= span; ++i)
			_knots[i] = oldKnots[i];

		// Add all the new knots.
		for (i = 1; i <= nTimes; ++i)
			_knots[span + i] = u;

		// Copy over all the old knots after the new ones.
		for (i = span + 1; i < oldKnots.GetCount(); ++i)
			_knots[i + nTimes] = oldKnots[i];

		// save unaltered control points
		BaseArray<Vector4d> rtemp;
		rtemp.Resize(_curveDegree + 1) iferr_return;

		// Copy over the control points that are not affected by the newly inserted knots before the ones that are.
		for (i = 0; i <= span - _curveDegree; ++i)
			_points[i] = oldPoints[i];

		// Copy over the control points that are not affected by the newly inserted knots after the ones that are.
		for (i = span; i < oldPoints.GetCount(); ++i)
			_points[i + nTimes] = oldPoints[i];

		// Save the original control points that will be replaced by by new ones. Since newly inserted points with
		// a multiplicity bigger than 0 will reduce the number of original control points that affect the the span where the points are inserted
		// we reduce the termination point by the multiplicity.
		for (i = 0; i <= _curveDegree - info.multiplicity; ++i)
			// New control point calculation happens in homogeneous space, so we need to convert.
			rtemp[i] = detail::NormalToHomogeneous(oldPoints[span - _curveDegree + i]);

		Float alpha;
		l = 0;
		for (j = 1; j <= nTimes; ++j)
		{
			l = span - _curveDegree + j;
			for (i = 0; i <= _curveDegree - j - info.multiplicity; ++i)
			{
				// Calculate interpolation factor.
				alpha = (u - oldKnots[l + i]) * Inverse(oldKnots[i + span + 1] - oldKnots[l + i]);
				// Overwrite old control point with newly, interpolated point.
				rtemp[i] = alpha * rtemp[i + 1] + (1.0_f - alpha) * rtemp[i];
			}
			// Since this algorithm overwrites the "new control points" vector for every new inserted knot, only the first and last new control point of the
			// previously inserted knot will remain and we copy it over. Since the calculations happened in homogeneous space, we need to convert them back.
			_points[l] = detail::HomogeneousToNormal(rtemp[0]);
			_points[span + nTimes - j] = detail::HomogeneousToNormal(rtemp[_curveDegree - j]);
		}

		// After we have added the last knot, where we once again only added the first and last calculated new control point to the final points
		// We then need to copy over the new control points between those two, which will not be overwritten by another iteration.
		l = span - _curveDegree + nTimes;
		for (i = l + 1; i < span; ++i)
			_points[i] = detail::HomogeneousToNormal(rtemp[i - l]);

		return OK;
	}


	Result<Vector> EvaluateAt(Float u, Int span) const
	{
		iferr_scope;

		if (MAXON_UNLIKELY(!_memInit))
			return IllegalStateError(MAXON_SOURCE_LOCATION, "Function 'Init' has not been called before."_s);

		if (MAXON_UNLIKELY(span < 0 || span >= _knots.GetCount() - 1))
			return IllegalArgumentError(MAXON_SOURCE_LOCATION, "span outside knot range"_s);

		// This might need a fuzzy match due to numerical errors.
		if (MAXON_UNLIKELY(u < _knots[span] || u > _knots[span + 1]))
			return IllegalArgumentError(MAXON_SOURCE_LOCATION, "u outside knot span"_s);


		// holds basis function and its derivatives up to degree 2
		detail::SmallStackMatrix<2 + 1, D + 1, Float> basisFunctions;
		basisFunctions.Resize(2 + 1, _curveDegree + 1) iferr_return;

		ComputeBasisFunctions(u, span, 0, basisFunctions) iferr_return;

		Vector4d resultPoint = CalculatePointFromBasisFunctions(span, 0, basisFunctions) iferr_return;

		// Since the Point was calculated with the homogeneous points (multiplied with their weights), we still 
		// need to normalize the resulting point by the accumulated weights, which is simply done by converting 
		// the homogeneous point back to a normal point.
		return detail::HomogeneousToNormal(resultPoint).GetVector3();
	}


	// s is [0.0, 1.0]
	Float MapStoU(Float s) const
	{
		Float umin = GetUmin();
		Float umax = GetUmax();
		return s * (umax - umin) + umin;
	}


	// u is [Umin, Umax]
	Float MapUtoS(Float u) const
	{
		Float umin = GetUmin();
		Float umax = GetUmax();
		return (u - umin) * Inverse(umax - umin);
	}


	Float GetUmin() const
	{
		// Why not [0] here? If the knot vector is clamped,
		// then we have the same value at [0] as we would have at [_curveDegree]
		// and if it's not clamped, then the [_curveDegree] doesn't yet make sense to me.
		// The reason might be, that we do not allow the evaluation of the curve in locations where we do not have degree + 1 base functions > 0.
		return _knots[_curveDegree];
	}


	Float GetUmax() const
	{
		// Same issue here as with GetUMin
		return _knots[_knots.GetCount() - _curveDegree - 1];
	}


	Result<Int> FindSpan(Float u) const
	{
		Int knotCount = _knots.GetCount();

		if (u < _knots[0] || u > _knots[knotCount - 1])
			return IllegalArgumentError(MAXON_SOURCE_LOCATION, "Parameter u outside knot range."_s);

		// The limits of the clamped case span searches might be improved by considering that a knot vector where too many knots are the same would lead to a degenerate (illegal) curve anyways.

		if (CompareFloatTolerant(u, _knots[knotCount - 1]))
		{
			// Search for last possible real span when having a clamped knot vector
			// If the last knot equals u, then we want to find the index of the first knot that is unequal to u, since that is the last span that has any knot-space width.
			Int res = knotCount - 1;
			do
			{
				--res;
			} while (res > 0 && _knots[res] == _knots[res + 1]);

			return res;
		}
		else if (CompareFloatTolerant(u, _knots[0]))
		{
			// search for first real span when having a clamped knot vector
			Int res = 0;
			while ((res < knotCount - 1) && CompareFloatTolerant(_knots[res], _knots[res + 1]))
				++res;

			return res;
		}

		// Possible performance improvements by initializing low and high differently when working with clamped knot vectors.

		// search span with binary search
		Int low = 0;
		Int high = knotCount - 1;
		Int mid = (low + high) / 2;

		while (u < _knots[mid] || u >= _knots[mid + 1])
		{
			if (u < _knots[mid])
				high = mid;
			else
				low = mid;
			mid = (low + high) / 2;
		}

		// Why was the following check not done in the cases where u == _knots[0] and u == _knots[knotCount - 1]?
		// If we are going to assume that we always have clamped vectors, then all the other algorithms should also be adjusted to this assumption.

		// safety check due to numerical inaccuracies
		if (MAXON_UNLIKELY(mid > knotCount - _curveDegree - 2))
			mid = knotCount - _curveDegree - 2;

		if (MAXON_UNLIKELY(mid < 0))
			mid = 0;

		return mid;
	}


	Result<KnotInfo> GetKnotInfo(Int k)
	{
		iferr_scope;

		Int knotCount = _knots.GetCount();

		if (MAXON_UNLIKELY(k < 0 || k >= knotCount))
			return IllegalArgumentError(MAXON_SOURCE_LOCATION, "Knot index outside range"_s);

		KnotInfo info;

		info.multiplicity = 0;

		for (Int i = knotCount - 1; i >= 0; --i)
		{
			if (_knots[i] == _knots[k])
			{
				info.firstPosition = i;
				info.multiplicity++;
			}
		}

		// Check if the knot is an outer knot and negate that value.
		info.innerKnot = !((info.multiplicity == _curveDegree + 1) && (info.firstPosition == 0 || info.firstPosition == knotCount - _curveDegree - 1));

		return info;
	}


	Result<void> CheckForKnotConsistency()
	{
		iferr_scope;

		Int knotCount = _knots.GetCount();
		KnotInfo info;

		for (Int i = 1; i < knotCount; i += info.multiplicity)
		{
			if (MAXON_UNLIKELY(_knots[i] < _knots[i - 1]))
				return IllegalStateError(MAXON_SOURCE_LOCATION, FormatString("Knot @ is not equal or greater than knot @.", i, i - 1));

			info = GetKnotInfo(i) iferr_return;

			if (info.innerKnot)
			{
				if (MAXON_UNLIKELY(info.multiplicity > _curveDegree))
					return IllegalStateError(MAXON_SOURCE_LOCATION, FormatString("Multiplicity of inner knot @ higher than degree of curve.", info.firstPosition));
			}
			else
			{
				if (MAXON_UNLIKELY(info.multiplicity > _curveDegree + 1))
					return IllegalStateError(MAXON_SOURCE_LOCATION, FormatString("Multiplicity of outer knot @ higher than degree + 1 of curve.", info.firstPosition));
			}
		}

		return OK;
	}


	Result<void> InitKnots(NURBSCURVE_KNOTMODE mode)
	{
		iferr_scope;

		Int pointCount = _points.GetCount();
		Int knotCount = _knots.GetCount();
		Int degree = knotCount - pointCount - 1;

		if (MAXON_UNLIKELY(pointCount < 1))
			return IllegalArgumentError(MAXON_SOURCE_LOCATION, "Wrong number of points."_s);

		if (MAXON_UNLIKELY(degree < 1))
			return IllegalArgumentError(MAXON_SOURCE_LOCATION, "Wrong number of points and knots."_s);

		switch (mode)
		{
			case NURBSCURVE_KNOTMODE::UNCLAMPED_UNIFORM:
			{
				for (Int k = 0; k < knotCount; ++k)
					_knots[k] = Float(k) * Inverse(Float(knotCount - 1));

				break;
			}

			case NURBSCURVE_KNOTMODE::CLAMPED_CHORDAL:
			case NURBSCURVE_KNOTMODE::CLAMPED_CENTRIPETAL:
			{
				BaseArray <Float> t; // summed chord lengths
				t.Resize(pointCount) iferr_return;

				// calculate chord length per point segment
				Float total = 0.0_f;
				t[0] = 0.0_f;

				for (Int p = 1; p < pointCount; ++p)
				{
					Float len = (_points[p].GetVector3() - _points[p - 1].GetVector3()).GetLength();

					if (mode == NURBSCURVE_KNOTMODE::CLAMPED_CENTRIPETAL)
						len = Sqrt(len);

					total += len;
					t[p] = total;
				}

				if (MAXON_UNLIKELY(total == 0.0_f))
					return IllegalArgumentError(MAXON_SOURCE_LOCATION, "Degenerate spline with total chord length zero."_s);

				// normalize chord lengths by total length
				total = Inverse(total);
				for (Float& it : t)
				{
					it *= total;
				}
				// DiagnosticOutput(FormatString("-- length @", t));


				// map chord length parameters to clamped knot vector
				for (Int k = 0; k <= degree; ++k)
				{
					_knots[k] = 0.0_f;
					_knots[knotCount - 1 - k] = 1.0_f;
				}

				// DiagnosticOutput(FormatString("-- Knots @", knots));

				for (Int k = degree + 1; k < knotCount - degree - 1; ++k)
				{
					Float average = 0.0_f;
					for (Int j = 0; j < degree; j++)
					{
						average += t[k + j - degree];
					}

					_knots[k] = average * Inverse(Float(degree));
				}
				break;
			}

			case NURBSCURVE_KNOTMODE::CLAMPED_UNIFORM:
			{
				const Int lastOfLeadingClampedValuesIndex = degree;
				const Int firstOfTrailingClampedValuesIndex = knotCount - 1 - degree;
				for (Int k = 0; k <= lastOfLeadingClampedValuesIndex; k++)
				{
					_knots[k] = 0.0_f;
					_knots[firstOfTrailingClampedValuesIndex + k] = 1.0_f;
				}

				const Int totalTDistance = firstOfTrailingClampedValuesIndex - lastOfLeadingClampedValuesIndex;
				const Float inverseOfInnerNodeTLength = Inverse(Float(totalTDistance));
				for (Int k = 1; k < totalTDistance; ++k)
				{
					_knots[lastOfLeadingClampedValuesIndex + k] = Float(k) * inverseOfInnerNodeTLength;
				}
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


	/// This functions calculates all basis functions of degree 1 to n that overlap the knot span "span".
	/// Since for a span that contains the parameter u only one basis function of degree 0 is not 0
	/// this creates a triangular hierarchy of basis functions where each hierarchy level contains degree + 1
	/// basis functions.
	/// 
	/// This algorithm maps this triangle to an index range from 0 to "curve degree" instead of working with the
	/// knot vector indices of the involved basis functions. This reduces memory requirements.
	/// 
	/// This Algorithm stores this hierarchy in the upper left triangle of a matrix (if 0,0 is the upper left corner)
	/// At 0,0 there is the degree 0 basis function value for u, which is always 1.
	/// 
	/// Calculating the interpolation factors for the parent basis functions requires us to normalize the parameter u
	/// in the knot-space width of each of the parent basis functions.
	/// Instead of always looking up the knot values for each basis function and then recalculating the normalization
	/// the algorithm instead stores the distance of the parameter u to all relevant knots to the left of u into an array.
	/// It does the same for all relevant knots to the right of it. This reduces the amount of computation in the inner loops.
	/// Bot vectors store their values in increasing distance order. They also exclude the very left most knot for the the
	/// basis function N0,n (the left-most basis function of degree n) because this distance is only ever needed to calculate
	/// the factor for the basis function N0,j-1. This "parent" basis function does not have any dependence on
	/// the single basis function of degree 0 that is not 0. So this basis function can also never be > 0.
	/// The same thing is true for the right-most relevant knot.
	/// That is why we don't need to store the distance to those knots and also why we don't even need to calculate the factor or look up
	/// the value of the lower degree base function for them.
	/// 
	/// Preventing the lookup and calculation is done by always excluding the calculation for all left-side basis functions of degree n-1.
	/// We can do this, because both the knot-space width and the "parent" basis function right-side "parent" of a basis function Ni is the same as the
	/// knot-space width and parent basis function of the left-side parent for the basis function Ni+1.
	/// So by simply taking the right parent, calculating the inverse knot-space width with the "distance from parameter u to right-most knot"
	/// of that parent basis function, you get the right part of the basis function Ni and then you use that same inverse width
	/// and the same value from the right parent basis function and multiply it with the "distance from parameter u to right-most knot
	/// of the parent basis function" to get the complete left term of the calculation for the basis function Ni+1.
	/// This is done as an optimization to reduce calculation overhead and also allows us to ignore the left parent for any N0,i,
	/// because we can pre-initialize the "saved" parent basis function as 0.
	/// Finally the last basis function of a hierarchy level is mirrored to the first: It only has a value for the left parent basis function.
	/// So now we don't need to calculate any value, we can just store the "saved" value, which represents the left part of the basis function equation
	/// to our triangle. 
	/// 
	/// The other half of our matrix (minus the diagonal center line, which is used by the basis function values) that forms the other triangle is used to 
	/// store the basis functions' widths in knot space.
	/// 
	/// The reason we don't run this algorithm in an array and just overwrite the basis functions for any Ni,j where j < n where our curve degree is n,
	/// is that we want to reuse these values in subsequent derivatives calculations. The same applies to the width values.
	/// 
	/// 
	/// The second part of this algorithm is the calculation of the derivatives of the basis functions for each degree of derivation from 1 to k, where k
	/// is the highest level of derivation that we are interested in.
	/// 
	/// The formula for this is: 
	/// N_(i,p)_(k) = (p! / (p - k)! ) * Sum_(j=0,k)( A_(k,j) * N_(i+j,p-k)
	/// Where i is the i-th basis function we are trying to calculate the derivative for.
	/// p is the degree of our basis functions, k is the k-th degree of derivation
	/// N_(i,p)_(k) is the k-th derivative of the i-th basis function of degree p.
	/// N_(i+j,p-k) is the i + j -th basis function at the degree p - k, which we already precomputed in the previous part of the algorithm.
	/// A is a recursively defined part of the equation that is defined as follows:
	/// 
	/// A_(0,0) = 1
	/// A_(k,0) = A_(k-1,0) / ( U_(i+p-k+1) - U_i )
	/// A_(k,j) = ( A_(k-1,j) - A_(k-1,k-1) ) / ( U_(i+p+j-k+1) - U_(i+k) )   for j = 1,...,k-1
	/// A_(k,k) = -A_(k-1,k-1) / ( U_(i+p+1) - U_(i+k) )
	/// 
	/// Where the U_(xxx) are the basis function knot-space widths that were calculated in the previous part of the algorithm.
	///
	maxon::Result<void> ComputeBasisFunctions(Float u, Int span, Int maxDerivationDegree, detail::SmallStackMatrix<2 + 1, D + 1, Float>& basisFunctionsOutput) const
	{
		iferr_scope;

		// The following memory allocation code is used to speed up the allocations of the required arrays and matrices
		// by using stack allocation, which is faster than the heap allocation. We do this instead of keeping the memory
		// as member memory because we want this function to be thread safe.
		SetMin(maxDerivationDegree, _curveDegree);

		const Int storageSize = _curveDegree + 1;

		detail::SmallStackArray<D + 1, Float> distancesToLeftKnots;
		distancesToLeftKnots.Resize(storageSize) iferr_return;

		detail::SmallStackArray<D + 1, Float> distancesToRightKnots;
		distancesToRightKnots.Resize(storageSize) iferr_return;

		detail::SmallSquareStackMatrix<D + 1, Float> storageMatrix;
		storageMatrix.Resize(storageSize, storageSize) iferr_return;

		detail::SmallStackMatrix<2, D + 1, Float> aCoefficientStorage;
		aCoefficientStorage.Resize(2, storageSize) iferr_return;

		Float preComputedLeftPartOfNextFunction;
		Float preNormalizedRightParentFunction;
		Int j;
		Int basisFunctionIndex;
		Int k;

		// The only interesting basis function for degree 0 is 1 for every u in its knot-space.
		storageMatrix(0, 0) = 1.0_f;
		// For each hierarchy level of basis functions
		for (j = 1; j <= _curveDegree; ++j)
		{
			// Extend the knot distances. When we go up one degree in the hierarchy, we need one more distance to the left and right
			// for the extra basis function and the increased knot-size of the basis functions.
			distancesToLeftKnots[j] = u - _knots[span + 1 - j];
			distancesToRightKnots[j] = _knots[span + j] - u;

			// pre-initialize the precomputed left part of the basis function equation to 0 because the first 
			// basis function N0,j will always have a left parent basis function that is 0.
			preComputedLeftPartOfNextFunction = 0.0_f;

			// For each basis function of degree j except the last one...
			for (basisFunctionIndex = 0; basisFunctionIndex < j; ++basisFunctionIndex)
			{
				// Store the width of the right-side parent basis function in knot-space
				// to lower triangle in the matrix for later use outside of basis function calculation. 
				storageMatrix(j, basisFunctionIndex) = distancesToRightKnots[basisFunctionIndex + 1] + distancesToLeftKnots[j - basisFunctionIndex];

				// The value from the previous degree is the value of the right parent basis function.
				// This is unintuitive, because depictions of the algorithm usually arrange the 
				// basis functions in knot-space. This would make the right parent appear to have a different knot index
				// Than the parent. The memory layout that was used here only stores the relevant basis functions,
				// which form a triangle, and arranges the triangle, so that it is left-oriented, instead of looking like
				// a pyramid.
				// We pre-divide with the knot-space width of the right parent basis function, because this value will be used both
				// for the calculation of this basis function as the factor for the right side of the equation, as well as for the
				// precomputed left side of the following basis function, just with different factors.
				preNormalizedRightParentFunction = storageMatrix(basisFunctionIndex, j - 1) * Inverse(storageMatrix(j, basisFunctionIndex));

				// Store the value for the basis function to the triangle inside our storage matrix. 
				// This value is calculated as the precomputed left part of the basis function added to the right parent function multiplied with its factor.
				storageMatrix(basisFunctionIndex, j) = preComputedLeftPartOfNextFunction + distancesToRightKnots[basisFunctionIndex + 1] * preNormalizedRightParentFunction;

				// pre-compute the left part of the next basis function by taking the basis function 
				// that is the "right" parent of the current basis function and multiplying it by the left factor of that parent basis function.
				preComputedLeftPartOfNextFunction = distancesToLeftKnots[j - basisFunctionIndex] * preNormalizedRightParentFunction;
			}
			// The last basis function of degree j does not have a right parent function that is > 0 so we can just store the precomuted left part to the triangle.
			storageMatrix(j, j) = preComputedLeftPartOfNextFunction;
		}

		// Copy basis functions of the highest degree to the output storage.
		for (j = 0; j <= _curveDegree; ++j)
			basisFunctionsOutput(0, j) = storageMatrix(j, _curveDegree);

		// compute the derivatives for each basis function that we previously calculated.
		for (basisFunctionIndex = 0; basisFunctionIndex <= _curveDegree; ++basisFunctionIndex)
		{
			// These are alternating indices into the A storage that always contains the previously calculated values for A.
			// Since the algorithm only needs to know the previously calculated values of A for the new values of A, it is enough to
			// have a data storage with 2 rows and alternate the indices.
			Int previousRowIndex = 0;
			Int currentRowIndex = 1; // alternate rows in array a

			// A_(0,0) is defined to be the recursion termination and is 1, therefore we can pre-set this value and thereby we have the first row
			// for k == 0 already defined. Since k == 0 means no derivation, we can start with k = 1 and use this already defined row.
			aCoefficientStorage(0, 0) = 1.0;

			// Compute all derivatives for the basis function starting at 1 because 0 doesn't make sense for derivatives and ending at the maximum degree of derivation we need.
			for (k = 1; k <= maxDerivationDegree; ++k)
			{
				Float sumValue = 0.0_f;
				Int rk = basisFunctionIndex - k;
				Int pk = _curveDegree - k;

				// The basis functions for degree Ni,p-k are 0 for any i < k (the triangle of values basis functions we previously calculated shows that)
				// So we don't need to calculate that part of the function at all.
				// The parts that we are omitting here are always going to be the first iterations of the summation in the equation.
				// Since the very first part has a special case where we calculate A_k,0 we can omit the calculation of that special case here.
				if (basisFunctionIndex >= k)
				{
					// Calculate the value of A for A_(k,0)  by accessing the value of A from the previous degree and retrieving the knot-vector space basis function width from storage
					// and store it in the current row of the A storage.
					aCoefficientStorage(currentRowIndex, 0) = aCoefficientStorage(previousRowIndex, 0) * Inverse(storageMatrix(pk + 1, rk));
					// Lookup the previously calculated basis function from storage and multiply it with the new A-value and initialize the sum value with it.
					sumValue = aCoefficientStorage(currentRowIndex, 0) * storageMatrix(rk, pk);
				}

				// Set the initial loop offset to be the difference between the i in N_i and the degree of derivation k since we know that we will only get values for 
				// i that are at least as high as k
				Int jStart = -rk;
				// If the difference was -1 or higher then that means that we either skip the first basis function because it will be 0, or we will have only valid ones (case i==k)
				// however when we have only valid ones, then we also want to skip the first calculation, because that was already done by the special case handling above.
				if (rk >= -1)
					jStart = 1;

				// Since we have previously only stored as many basis functions as we have curve degree, since all others are 0 we should only ever iterate over "_curvedegree" number of basis splines.
				// If the starting i (r in this case) of N_i is above 0 we need to reduce the iteration length accordingly by subtracting r from our loop endpoint.
				Int jEnd = _curveDegree - basisFunctionIndex;
				// If our starting N_i is smaller than the number of basis functions - k, that means that we can loop though all but the last K without hitting the last
				// basis function N_p because N_i+j will never reach N_p.
				if (basisFunctionIndex - 1 <= pk)
					// Then set the final loop value to be the second to last k, since the last k has special handling.
					jEnd = k - 1;

				// Calculate the sum for all non-special case summands.
				for (j = jStart; j <= jEnd; j++)
				{
					// Calculate the value of A for A_(k,j)  by accessing the value of A from the previous degree and retrieving the knot-vector space basis function width from storage
					// and store it in the current row of the A storage.
					aCoefficientStorage(currentRowIndex, j) = (aCoefficientStorage(previousRowIndex, j) - aCoefficientStorage(previousRowIndex, j - 1)) * Inverse(storageMatrix(pk + 1, rk + j));
					// Lookup the previously calculated basis function from storage and multiply it with the new A-value and initialize the sum value with it.
					sumValue += aCoefficientStorage(currentRowIndex, j) * storageMatrix(rk + j, pk);
				}

				// If r is small enough to allow us to iterate over all K so that N_i+j will not go over N_p then we can handle the last special case for j == k
				if (basisFunctionIndex <= pk)
				{
					aCoefficientStorage(currentRowIndex, k) = -aCoefficientStorage(previousRowIndex, k - 1) * Inverse(storageMatrix(pk + 1, basisFunctionIndex));
					sumValue += aCoefficientStorage(currentRowIndex, k) * storageMatrix(basisFunctionIndex, pk);
				}
				// Store the derivative in the output matrix.
				basisFunctionsOutput(k, basisFunctionIndex) = sumValue;
				// Switch rows (We only ever need to store the previous row of As, since the algorithm doesn't need any other input, so we just alternate
				// the index into the two rows we have.
				j = previousRowIndex; previousRowIndex = currentRowIndex; currentRowIndex = j;
			}
		}

		// This multiplies the previously calculated derivatives with the correct factor from the formula. The factor is: p! / (p-k)!
		// So for k = 1 it would be p, for k = 2 it would be p * (p - 1), for k = 3 it would be p * (p - 1) * (p - 2).
		// This can be solved by simply initializing the factor with p and then iterating over k and multiplying the factor with p - k every time.
		basisFunctionIndex = _curveDegree;
		// For each basis function hierarchy level of degree k
		for (k = 1; k <= maxDerivationDegree; ++k)
		{
			// For each basis function of that level
			for (j = 0; j <= _curveDegree; ++j)
				basisFunctionsOutput(k, j) *= Float(basisFunctionIndex);

			// Update the factor for the next iteration.
			basisFunctionIndex *= _curveDegree - k;
		}

		return OK;
	}


	Result<Int> GetKnotCount() const
	{
		iferr_scope;

		if (MAXON_UNLIKELY(!_memInit))
			return IllegalStateError(MAXON_SOURCE_LOCATION, "Function 'Init' not called before."_s);

		return _knots.GetCount();
	}


	Result<Vector4d> CalculatePointFromBasisFunctions(Int span, Int deg, const detail::SmallStackMatrix<2 + 1, D + 1, Float>& basisFunctions) const
	{
		iferr_scope;

		Vector4d sum = Vector4d(0.0_f, 0.0_f, 0.0_f, 0.0_f);
		for (Int j = 0; j <= _curveDegree; ++j)
			// The NURBS-specific weights for the points are encoded in the 4th dimension of the control points.
			// Turning the points to homogeneous points basically multiplies the weights with the points.
			sum += basisFunctions(deg, j) * detail::NormalToHomogeneous(_points[span - _curveDegree + j]);

		return sum;
	}


	Result<void> InitInternal(Int numPoints, Int degree, NURBSCURVE_KNOTMODE mode)
	{
		iferr_scope;

		if (MAXON_UNLIKELY(degree < 1))
			return IllegalArgumentError(MAXON_SOURCE_LOCATION, "Degree must be at least 1."_s);

		if (MAXON_UNLIKELY(numPoints < degree + 1))
			return IllegalArgumentError(MAXON_SOURCE_LOCATION, "Not enough control points for this degree of curve."_s);

		_memInit = false;

		_curveDegree = degree;

		_points.Resize(numPoints) iferr_return;
		for (Vector4d& it : _points)
		{
			it = Vector4d(0.0_f, 0.0_f, 0.0_f, 1.0_f);
		}

		_knots.Resize(numPoints + _curveDegree + 1) iferr_return;

		InitKnots(mode) iferr_return;

		_knotMode = mode;
		_memInit = true;
		return OK;
	}


	Result<void> InitInternal(Int degree, const BaseArray<Vector4d>& points, const BaseArray<Float>& knots)
	{
		iferr_scope;

		if (MAXON_UNLIKELY(degree < 1))
			return IllegalArgumentError(MAXON_SOURCE_LOCATION, "Degree must be at least 1."_s);

		if (MAXON_UNLIKELY(points.GetCount() < degree + 1))
			return IllegalArgumentError(MAXON_SOURCE_LOCATION, "Not enough control points for this degree of curve."_s);

		if (MAXON_UNLIKELY(points.GetCount() + degree + 1 != knots.GetCount()))
			return IllegalArgumentError(MAXON_SOURCE_LOCATION, "Not enough knots for this many points and this degree of curve."_s);

		_memInit = false;

		_curveDegree = degree;

		_points.CopyFrom(points) iferr_return;

		_knots.CopyFrom(knots) iferr_return;

		_knotMode = NURBSCURVE_KNOTMODE::USER_DEFINED;

		_memInit = true;
		return OK;
	}


	template<Int OtherN>
	Result<void> InitInternal(const NURBSCurve<OtherN>& other)
	{
		iferr_scope;

		_memInit = false;

		SetPointsWithWeights(other.GetPointsWithWeights()) iferr_return;

		Int otherDegree = other.GetDegree() iferr_return;
		if (otherDegree != _curveDegree)
		{
			_knots.Resize(_points.GetCount() + _curveDegree + 1) iferr_return;
			InitKnots(NURBSCURVE_KNOTMODE::CLAMPED_UNIFORM) iferr_return;
		}
		else
		{
			_knots.CopyFrom(other.GetKnots()) iferr_return;
		}

		_knotMode = other.GetKnotMode();

		_memInit = true;

		return OK;
	}


	Result<Float> GetKnot(Int i) const
	{
		if (MAXON_UNLIKELY(i < 0 || i >= _knots.GetCount()))
			return IllegalArgumentError(MAXON_SOURCE_LOCATION, "Knot index outside range"_s);

		return _knots[i];
	}


	template<typename T>
	Result<void> ChangeWeightsInternal(const Block<const T>& weights)
	{
		iferr_scope;

		if (MAXON_UNLIKELY(!_memInit))
			return IllegalStateError(MAXON_SOURCE_LOCATION, "Function 'Init' not called before."_s);

		if (MAXON_UNLIKELY(weights.GetCount() != _points.GetCount()))
			return IllegalArgumentError(MAXON_SOURCE_LOCATION, "Wrong number of weights."_s);

		for (Int i = 0; i < _points.GetCount(); ++i)
		{
			SetWeight(i, weights[i]) iferr_return;
		}

		return OK;
	}

protected:

	Int _curveDegree = 0;

private:

	NURBSCURVE_KNOTMODE _knotMode = NURBSCURVE_KNOTMODE::CLAMPED_UNIFORM;
	BaseArray<Vector4d> _points;
	BaseArray<Float> _knots;

	Bool _memInit = false;
};

template<Int D>
MAXON_IMPLEMENTATION_REGISTER_SIMPLE(NURBSCurve<D>);

} // namespace maxon

#endif // NURBSMATH_H__
