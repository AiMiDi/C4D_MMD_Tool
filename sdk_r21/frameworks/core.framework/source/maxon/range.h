#ifndef RANGE_H__
#define RANGE_H__

#include "maxon/datatype.h"
#include "maxon/vector2d.h"

namespace maxon
{

/// @addtogroup MATH
/// @{

template <typename T> T PrivateRangeValueTypeHelper(OverloadRank0);
template <typename T> typename T::ValueType PrivateRangeValueTypeHelper(OverloadRank1);

//----------------------------------------------------------------------------------------
/// A Range represents a closed interval of values min ... max. If T is a vector type, this is actually a multi-dimensional
/// interval such as a rectangle for two-dimensional vectors or an axis-aligned (bounding) box in three dimensions.
///
/// To compare @p T values, range uses <tt>a.LessThanOrEqual(b)</tt> if possible, otherwise <tt>a <= b</tt>. The corresponding
/// order may be a partial order (as it is the case for vectors).
///
/// @tparam T											The underlying datatype, either a scalar type, or a vector type where T::ValueType specifies the type of the vector elements.
//----------------------------------------------------------------------------------------
template <typename T> class Range
{
public:
	using ScalarType = decltype(PrivateRangeValueTypeHelper<T>(OVERLOAD_MAX_RANK));

	//----------------------------------------------------------------------------------------
	/// Constructs an empty range. min is set to the maximum possible value, max to the minimum possible value.
	//----------------------------------------------------------------------------------------
	Range() : _minValue(LIMIT<ScalarType>::Max()), _maxValue(LIMIT<ScalarType>::Min()) { }

	//----------------------------------------------------------------------------------------
	/// Constructs a singleton range containing exactly v.
	/// @param[in] v									Initial value for the range.
	//----------------------------------------------------------------------------------------
	explicit Range(const T& v) : _minValue(v), _maxValue(v) { }

	//----------------------------------------------------------------------------------------
	/// Constructs the range rangeMin ... rangeMax.
	/// If rangeMin is not less than or equal to rangeMax, the range will be empty.
	/// @param[in] rangeMin						Initial minimum value for the range.
	/// @param[in] rangeMax						Initial maximum value for the range.
	//----------------------------------------------------------------------------------------
	Range(const T& rangeMin, const T& rangeMax) : _minValue(rangeMin), _maxValue(rangeMax) { }

	//----------------------------------------------------------------------------------------
	/// Resets the range to its initial state, i.e., to an empty range where min is set to the maximum possible value, max to the minimum possible value.
	//----------------------------------------------------------------------------------------
	void Reset() { _minValue = T(LIMIT<ScalarType>::Max()); _maxValue = T(LIMIT<ScalarType>::Min()); }

	//----------------------------------------------------------------------------------------
	/// Sets this range to a singleton range containing exactly v.
	/// @param[in] v									Singleton value for the range.
	//----------------------------------------------------------------------------------------
	void Set(const T& v) { _minValue = _maxValue = v; }

	//----------------------------------------------------------------------------------------
	/// Sets this range to rangeMin ... rangeMax.
	/// If rangeMin is not less than or equal to rangeMax, the range will be empty.
	/// @param[in] rangeMin						Minimum value for the range.
	/// @param[in] rangeMax						Maximum value for the range.
	//----------------------------------------------------------------------------------------
	void Set(const T& rangeMin, const T& rangeMax) { _minValue = rangeMin; _maxValue = rangeMax; }

	//----------------------------------------------------------------------------------------
	/// Extends this range if necessary so that it encloses p.
	/// @param[in] p									Value to include in this range.
	//----------------------------------------------------------------------------------------
	void Add(const T& p)
	{
		SetMin(_minValue, p);
		SetMax(_maxValue, p);
	}

	//----------------------------------------------------------------------------------------
	/// Extends this range if necessary so that it encloses the range given by rangeMin ... rangeMax.
	/// It that range is empty, nothing happens.
	/// @param[in] rangeMin						Minimum value of the other range to include.
	/// @param[in] rangeMax						Maximum value of the other range to include.
	//----------------------------------------------------------------------------------------
	void Add(const T& rangeMin, const T& rangeMax)
	{
		if (DefaultCompare::LessThanOrEqual(rangeMin, rangeMax))
		{
			SetMin(_minValue, rangeMin);
			SetMax(_maxValue, rangeMax);
		}
	}

	//----------------------------------------------------------------------------------------
	/// Extends this range if necessary so that it encloses the other range.
	/// It that range is empty, nothing happens.
	/// @param[in] range							Another range to include in this range.
	//----------------------------------------------------------------------------------------
	void Add(const Range& range)
	{
		if (DefaultCompare::LessThanOrEqual(range._minValue, range._maxValue))
		{
			SetMin(_minValue, range._minValue);
			SetMax(_maxValue, range._maxValue);
		}
	}

	//----------------------------------------------------------------------------------------
	/// Intersects this range with the range given by rangeMin ... rangeMax.
	/// @param[in] rangeMin						Minimum value of the other range for intersection.
	/// @param[in] rangeMax						Maximum value of the other range for intersection.
	//----------------------------------------------------------------------------------------
	void Intersect(const T& rangeMin, const T& rangeMax)
	{
		SetMax(_minValue, rangeMin);
		SetMin(_maxValue, rangeMax);
	}

	//----------------------------------------------------------------------------------------
	/// Intersects this range with the other range.
	/// @param[in] range							Another range to intersect with.
	//----------------------------------------------------------------------------------------
	void Intersect(const Range& range)
	{
		SetMax(_minValue, range._minValue);
		SetMin(_maxValue, range._maxValue);
	}

	//----------------------------------------------------------------------------------------
	/// Shifts this range by #shift. The value of #shift is added to the minimum and maximum value.
	/// @param[in] shift							Value to add to the bounds.
	//----------------------------------------------------------------------------------------
	Range& operator +=(const T& shift)
	{
		_minValue += shift;
		_maxValue += shift;
		return *this;
	}

	//----------------------------------------------------------------------------------------
	/// Shifts this range by #shift. The value of #shift is substracted from the minimum and maximum value.
	/// @param[in] shift							Value to subtract from the bounds.
	//----------------------------------------------------------------------------------------
	Range& operator -=(const T& shift)
	{
		_minValue -= shift;
		_maxValue -= shift;
		return *this;
	}

	//----------------------------------------------------------------------------------------
	/// Returns a new range which is given by this range, shifted by #shift. The value of #shift is added to the minimum and maximum value.
	/// @param[in] shift							Value to add to the bounds.
	/// @return												New range with shifted bounds.
	//----------------------------------------------------------------------------------------
	Range operator +(const T& shift) const
	{
		return Range(_minValue + shift, _maxValue + shift);
	}

	//----------------------------------------------------------------------------------------
	/// Returns a new range which is given by this range, shifted by #shift. The value of #shift is subtracted from the minimum and maximum value.
	/// @param[in] shift							Value to subtract from the bounds.
	/// @return												New range with shifted bounds.
	//----------------------------------------------------------------------------------------
	Range operator -(const T& shift) const
	{
		return Range(_minValue - shift, _maxValue - shift);
	}

	//----------------------------------------------------------------------------------------
	/// Tests if this range intersects with the other range
	/// @param[in] range							Another range to test the intersect with.
	/// @return												Return true if the ranges intersect, false otherwise
	//----------------------------------------------------------------------------------------
	Bool IsIntersecting(const Range& range) const
	{
		return DefaultCompare::LessThanOrEqual(this->GetMin(), range.GetMax()) && DefaultCompare::LessThanOrEqual(range.GetMin(), this->GetMax());
	}

	//----------------------------------------------------------------------------------------
	/// Returns true if this range is empty. In that case GetMin(), GetMax(), GetCenter(), GetDimension() will return a guaranteed, but incorrect value of 0.
	/// @return												True if range is empty.
	//----------------------------------------------------------------------------------------
	Bool IsEmpty() const { return !DefaultCompare::LessThanOrEqual(_minValue, _maxValue); }

	//----------------------------------------------------------------------------------------
	/// Returns true if this range is populated.
	/// @return												True if range is not empty.
	//----------------------------------------------------------------------------------------
	Bool IsPopulated() const { return DefaultCompare::LessThanOrEqual(_minValue, _maxValue); }

	//----------------------------------------------------------------------------------------
	/// Returns the minimum boundary. For an empty range, this will return T(0).
	/// @return												Minimum boundary, or T(0) for an empty range.
	//----------------------------------------------------------------------------------------
	T GetMin() const
	{
		return DefaultCompare::LessThanOrEqual(_minValue, _maxValue) ? _minValue : T(ScalarType(0));
	}

	//----------------------------------------------------------------------------------------
	/// Returns the maximum boundary. For an empty range, this will return T(0).
	/// @return												Maximum boundary, or T(0) for an empty range.
	//----------------------------------------------------------------------------------------
	T GetMax() const
	{
		return DefaultCompare::LessThanOrEqual(_minValue, _maxValue) ? _maxValue : T(ScalarType(0));
	}

	//----------------------------------------------------------------------------------------
	/// Returns the center of the range. For an empty range, this will return T(0).
	/// @return												Center of the range, or T(0) for an empty range.
	//----------------------------------------------------------------------------------------
	T GetCenter() const
	{
		return DefaultCompare::LessThanOrEqual(_minValue, _maxValue) ? (_maxValue + _minValue) * ScalarType(0.5) : T(ScalarType(0));
	}

	//----------------------------------------------------------------------------------------
	/// Returns the dimension of range. For an empty range, this will return T(0), otherwise the difference of maximum and minimum value.
	/// Note that for integral datatypes this does not calculate the number of elements (which is _maxValue - _minValue + 1). To do so you need to add 1 manually.
	/// @return												Dimension of the range, or T(0) for an empty range.
	//----------------------------------------------------------------------------------------
	T GetDimension() const
	{
		return DefaultCompare::LessThanOrEqual(_minValue, _maxValue) ? _maxValue - _minValue : T(ScalarType(0));
	}

	//----------------------------------------------------------------------------------------
	/// Tests if the given @p value is contained in this range.
	/// @param[in] value							Value to check.
	/// @return												True if the value is contained in the range.
	//----------------------------------------------------------------------------------------
	Bool Contains(const T& value) const
	{
		return DefaultCompare::LessThanOrEqual(_minValue, value) && DefaultCompare::LessThanOrEqual(value, _maxValue);
	}

	//----------------------------------------------------------------------------------------
	/// Tests if the given @p value is contained in this range.
	/// @param[in] value							Value to check.
	/// @return												True if the value is contained in the range.
	//----------------------------------------------------------------------------------------
	Bool Contains(const Range<T>& value) const
	{
		return DefaultCompare::LessThanOrEqual(_minValue, value.GetMin()) && DefaultCompare::LessThanOrEqual(value.GetMax(), _maxValue);
	}

	MAXON_OPERATOR_EQUALITY_HASHCODE(Range, _minValue, _maxValue);

	typename SFINAEHelper<String, T>::type ToString(const FormatStatement* format) const
	{
		return "["_s + GlobalToString(_minValue, format) + ","_s + GlobalToString(_maxValue, format) + "]"_s;
	}

	T _minValue; ///< The minimum boundary of this range.
	T _maxValue; ///< The maximum boundary of this range. If the minimum boundary is not less than or equal to this, the range is empty.
};

template <typename T> struct IsZeroInitialized<Range<T>> : public IsZeroInitialized<T> { };

namespace ParametricTypes
{
	MAXON_DECLARATION(ParametricType, Range, "net.maxon.parametrictype.range");
}

template <GET_DATATYPE_POLICY POLICY, typename T> inline Result<DataType> PrivateGetDataType(Range<T>**, OverloadRank0)
{
	iferr_scope;
	DataType t = CheckedGetDataType<T, POLICY | GET_DATATYPE_POLICY::NO_DECAY>() iferr_return;
	return ParametricTypes::Range().Instantiate(t);
}

/// Range with the precision of Float.
using Frame = Range<Vector2d>;

/// Range with the precision of Int.
using IntFrame = Range<IntVector2d>;


/// @}

} // namespace maxon

#endif // RANGE_H__
