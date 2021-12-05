#ifndef GRADIENTMATH_H__
#define GRADIENTMATH_H__

#include "maxon/lib_math.h"
#include "maxon/algorithms.h"
#include "maxon/sort.h"
#include "maxon/datatypelib.h"

namespace maxon
{

/// This class is a data container for gradient knots. Each knot is defined by an index and a position in a 1D range.
/// @tparam T_Float									The type of real-valued position, recommended are Float, Float32 and Float64.
/// @tparam T_Int										The type of index, recommended are Int, Int32 and Int64.
/// We recommend to match the bitdepth of index and position.
template <typename T_Float, typename T_Int>
struct IndexedGradientKnot
{
	//----------------------------------------------------------------------------------------
	/// Constructs a gradient knot.
	/// @param[in] index							The index of the knot.
	/// @param[in] value							The position of the knot.
	//----------------------------------------------------------------------------------------
	IndexedGradientKnot(T_Int index, T_Float value) : _index(index), _position(value)
	{
	}

	//----------------------------------------------------------------------------------------
	/// Lesser comparison of two knots. First criterion is the position of the knots.
	/// If the knot positions match ordinal comparison of the indices is done.
	/// @param[in] other							The knot to compare with.
	/// @return												True if the knot is smaller, false otherwise.
	//----------------------------------------------------------------------------------------
	Bool operator <(const IndexedGradientKnot& other) const
	{
		// If two knots have the same position, use the order of knot.
		return LexicographicalLessThan(_position, other._position, _index, other._index);
	}

	T_Int _index = -1;
	T_Float _position = 0.0;
};

/// This class organizes a collection of gradient knots.
/// Knots can be added in arbitrary order and are sorted as a finalization step.
/// To avoid re-ordering data associated with the knots, e.g. colors, we maintain the original indices
/// for data lookup.
/// @tparam T_Float									The type of real-valued position, recommended are Float, Float32 and Float64.
/// @tparam T_Int										The type of index, recommended are Int, Int32 and Int64.
/// We recommend to match the bitdepth of index and position.
template <typename T_Float, typename T_Int>
class SortedGradientKnots
{
public:
	using FloatType = T_Float;
	using IntType = T_Int;
	using IndexedKnotType = IndexedGradientKnot<FloatType, IntType>;

	//----------------------------------------------------------------------------------------
	/// Removes all knots.
	//----------------------------------------------------------------------------------------
	void Reset()
	{
		_knots.Reset();
		_inversePermutation.Reset();
	}

	//----------------------------------------------------------------------------------------
	/// Allocates the memory required for knot storage. If the amount of knots is known beforehand
	/// we recommend to pre-allocate memory to avoid any memory allocations during knot insertion.
	/// @param[in] numKnots							The number of knots to reserve memory for.
	/// @return													OK on success.
	//----------------------------------------------------------------------------------------
	Result<void> ReserveMemory(IntType numKnots)
	{
		return _knots.SetCapacityHint(numKnots, COLLECTION_RESIZE_FLAGS::FIT_TO_SIZE);
	}

	//----------------------------------------------------------------------------------------
	/// Inserts a knot at the provided position. The index of the knot is implicit.ertion.
	/// @param[in] position						The position of the knot.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	Result<void> InsertKnot(FloatType position)
	{
		iferr_scope;
		IndexedKnotType knot(IntType(_knots.GetCount()), position);
		_knots.Append(std::move(knot)) iferr_return;
		return OK;
	}

	//----------------------------------------------------------------------------------------
	/// Return the knot left to the requested position if there is one. If there is none, the 
	/// knot right next to the requested position is returned.
	/// Please note that this function is unsafe for empty gradients.
	/// @param[in] samplePosition			The requested position.
	/// @return												The requested knot.
	//----------------------------------------------------------------------------------------
	const IndexedKnotType& GetSampleKnot(FloatType samplePosition) const
	{
		const IntType upperPermutedIndex = IntType(UpperBound(_knots, IndexedKnotType(0, samplePosition)) - _knots.Begin());
		const IntType leftPermutedIndex = Max(IntType(0), upperPermutedIndex - 1);

		DebugAssert(UInt(leftPermutedIndex) < UInt(_knots.GetCount()));
		return _knots[leftPermutedIndex];
	}

	//----------------------------------------------------------------------------------------
	/// Return the knot left to a knot if there is one. If not, the knot itself is returned. 
	/// Please note that this function is unsafe for empty gradients.
	/// @param[in] knot								The knot to query.
	/// @return												The requested neighboring knot.
	//----------------------------------------------------------------------------------------
	const IndexedKnotType& GetLeft(const IndexedKnotType& knot) const
	{
		IntType permutedIndex = _inversePermutation[knot._index];
		IntType leftPermutedIndex = Max(IntType(0), permutedIndex - 1);

		DebugAssert(UInt(leftPermutedIndex) < UInt(_knots.GetCount()));
		return _knots[leftPermutedIndex];
	}

	//----------------------------------------------------------------------------------------
	/// Return the knot right to a knot if there is one. If not, the knot itself is returned. 
	/// Please note that this function is unsafe for empty gradients.
	/// @param[in] knot								The knot to query.
	/// @return												The requested neighboring knot.
	//----------------------------------------------------------------------------------------
	const IndexedKnotType& GetRight(const IndexedKnotType& knot) const
	{
		IntType permutedIndex = _inversePermutation[knot._index];
		IntType rightPermutedIndex = Min(IntType(_knots.GetCount() - 1), permutedIndex + 1);

		DebugAssert(UInt(rightPermutedIndex) < UInt(_knots.GetCount()));
		return _knots[rightPermutedIndex];
	}

	//----------------------------------------------------------------------------------------
	/// Returns the knot at a specific index.
	/// @param[in] knotIndex					The index of the knot to retrieve.
	/// @return												The requested knot.
	//----------------------------------------------------------------------------------------
	const IndexedKnotType& GetKnot(IntType knotIndex) const
	{
		DebugAssert(UInt(knotIndex) < UInt(_knots.GetCount()));
		return _knots[knotIndex];
	}

	//----------------------------------------------------------------------------------------
	/// Returns the number of knots contained.
	/// @return												The number of knots.
	//----------------------------------------------------------------------------------------
	IntType GetCount() const
	{
		return IntType(_knots.GetCount());
	}

	//----------------------------------------------------------------------------------------
	/// Checks whether the knot series is empty. 
	/// @return												True if there are no knots.
	//----------------------------------------------------------------------------------------
	Bool IsEmpty() const
	{
		return _knots.IsEmpty();
	}

	//----------------------------------------------------------------------------------------
	/// Sorts the knots in ascending order. 
	/// The original ordering from knot insertion is preserved as an inverse permutation for later data lookup
	/// with the original indices.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	Result<void> Sort()
	{
		iferr_scope;

		SimpleSort<> knotSort;
		knotSort.Sort(_knots);

		const IntType numKnots = IntType(_knots.GetCount());

		_inversePermutation.Resize(numKnots) iferr_return;

		for (IntType i = 0; i < numKnots; ++i)
			_inversePermutation[_knots[i]._index] = i;

		return OK;
	}

private:

	BaseArray<IndexedKnotType> _knots;
	BaseArray<T_Int> _inversePermutation;
};

// TODO: (Maik) consider options for making error handling of GetKnotValueFunc and its siblings optional.

/// This class implements the gradient blending operation for a series of knots with different interpolation modes.
/// For performance reasons interpolation modes are handled as unsigned integers.
/// @tparam T_ModeNone										The index of constant / stairstep interpolation of 1 knot.
/// @tparam T_ModeLinearKnot							The index of linear interpolation between 2 knots.
/// @tparam T_ModeSmoothKnot							The index of the smooth-stepped linear interpolation between 2 knots.
/// @tparam T_ModeBlend										The index of the box-stepped linear interpolation between 2 knots.
/// @tparam T_ModeCubicKnot								The index of the cubic interpolation between 4 knots.
/// @tparam T_ModeCubicBias								The index of the cubic interpolation between 2 knots.
template <UInt T_ModeNone = 0, UInt T_ModeLinearKnot = 1,
	UInt T_ModeSmoothKnot = 2, UInt T_ModeBlend = 3,
	UInt T_ModeCubicKnot = 4, UInt T_ModeCubicBias = 5>
class IndexedGradientSampler
{
	static const UInt InterpolationNone = T_ModeNone;
	static const UInt InterpolationLinearKnot = T_ModeLinearKnot;
	static const UInt InterpolationSmoothKnot = T_ModeSmoothKnot;
	static const UInt InterpolationBlend = T_ModeBlend;
	static const UInt InterpolationCubicKnot = T_ModeCubicKnot;
	static const UInt InterpolationCubicBias = T_ModeCubicBias;

	//----------------------------------------------------------------------------------------
	/// Applies the bias blending to a weight. 
	/// @tparam FloatType							The type of real number.
	/// @param[in] weight							The original unbiased weight.
	/// @param[in] bias								The bias to apply.
	/// @return												The biased weight.
	//----------------------------------------------------------------------------------------
	template <typename FloatType>
	static inline FloatType GetBiasedWeight(FloatType weight, FloatType bias)
	{
		if (weight < bias)
			return Blend(FloatType(0.0), FloatType(0.5), BoxStep(FloatType(0.0), bias, weight));
		else
			return Blend(FloatType(0.5), FloatType(1.0), BoxStep(bias, FloatType(1.0), weight));
	}

	//----------------------------------------------------------------------------------------
	/// Computes the four blend weights of cubic interpolation.
	/// @tparam FloatType							The type of real number.
	/// @param[in] a									The original weight.
	/// @return												The cubic blend weights.
	//----------------------------------------------------------------------------------------
	template <typename FloatType>
	static inline Vec4<FloatType> GetCubicBlendWeights(FloatType a)
	{
		Vec4<FloatType> weights;

		const FloatType inverseA = FloatType(1.0) - a;

		weights.x = inverseA * inverseA * inverseA;
		weights.y = (FloatType(3.0) * a) * (inverseA * inverseA);
		weights.z = (FloatType(3.0) * (a * a)) * inverseA;
		weights.w = a * a * a;
		return weights;
	}

	//----------------------------------------------------------------------------------------
	/// Linearly interpolates between two values.
	/// @tparam ValueType							The type of value to interpolate.
	/// @tparam FloatType							The type of real number.
	/// @tparam IntType								The type of index.
	/// @tparam GetKnotValueFunc			The type of value sample function.
	/// @param[in] leftIndex					The index of the left knot.
	/// @param[in] rightIndex					The index of the right knot.
	/// @param[in] weight							The interpolation weight between the 2 knots.
	/// @param[in] getKnotValue				The value sample function.
	/// @return												The interpolated value on success.
	//----------------------------------------------------------------------------------------
	template <typename ValueType, typename FloatType, typename IntType, typename GetKnotValueFunc>
	static inline Result<ValueType> BlendTwoValuesLinear(IntType leftIndex, IntType rightIndex, FloatType weight, const GetKnotValueFunc& getKnotValue)
	{
		iferr_scope;

		const ValueType leftValue = getKnotValue(leftIndex) iferr_return;
		ValueType rightValue = leftValue;
		if (rightIndex != leftIndex)
		{
			rightValue = getKnotValue(rightIndex) iferr_return;
		}
		return Blend(leftValue, rightValue, weight);
	}

	//----------------------------------------------------------------------------------------
	/// Computes the biased cubic interpolation between two values.
	/// @tparam ValueType							The type of value to interpolate.
	/// @tparam FloatType							The type of real number.
	/// @tparam IntType								The type of index.
	/// @tparam GetKnotValueFunc			The type of value sample function.
	/// @param[in] leftIndex					The index of the left knot.
	/// @param[in] rightIndex					The index of the right knot.
	/// @param[in] biasLeft						The bias towards the left knot.
	/// @param[in] biasRight					The bias towards the right knot.
	/// @param[in] cubicWeights				The cubic weights.
	/// @param[in] getKnotValue				The value sample function.
	/// @return												The interpolated value.
	//----------------------------------------------------------------------------------------
	template <typename ValueType, typename FloatType, typename IntType, typename GetKnotValueFunc>
	static inline Result<ValueType> BlendTwoValuesCubic(IntType leftIndex, IntType rightIndex, FloatType biasLeft, FloatType biasRight, const Vec4<FloatType>& cubicWeights, const GetKnotValueFunc& getKnotValue)
	{
		iferr_scope;

		const ValueType leftValue = getKnotValue(leftIndex) iferr_return;
		ValueType rightValue = leftValue;
		if (rightIndex != leftIndex)
		{
			rightValue = getKnotValue(rightIndex) iferr_return;
		}
		const ValueType valueA = leftValue;
		const ValueType valueB = Blend(leftValue, rightValue, biasLeft);
		const ValueType valueC = Blend(leftValue, rightValue, biasRight);
		const ValueType valueD = rightValue;

		const ValueType blendedColor = (cubicWeights.x * valueA) + (cubicWeights.y * valueB) + (cubicWeights.z * valueC) + (cubicWeights.w * valueD);
		return blendedColor;
	}

	//----------------------------------------------------------------------------------------
	/// Computes the interpolation between four values.
	/// @tparam ValueType							The type of value to interpolate.
	/// @tparam FloatType							The type of real number.
	/// @tparam IntType								The type of index.
	/// @tparam GetKnotValueFunc			The type of value sample function.
	/// @param[in] index0							The index of the first knot.
	/// @param[in] index1							The index of the second knot.
	/// @param[in] index2							The index of the third knot.
	/// @param[in] index3							The index of the fourth knot.
	/// @param[in] weight							The interpolation weight.
	/// @param[in] getKnotValue				The value sample function.
	/// @return												The interpolated value on success.
	//----------------------------------------------------------------------------------------
	template <typename ValueType, typename FloatType, typename IntType, typename GetKnotValueFunc>
	static inline Result<ValueType> BlendFourValues(IntType index0, IntType index1, IntType index2, IntType index3, FloatType weight, const GetKnotValueFunc& getKnotValue)
	{
		iferr_scope;

		const ValueType value0 = getKnotValue(index0) iferr_return;
		ValueType value1 = value0;
		if (index1 != index0)
		{
			value1 = getKnotValue(index1) iferr_return;
		}
		ValueType value2 = value1;
		if (index2 != index1)
		{
			value2 = getKnotValue(index2) iferr_return;
		}
		ValueType value3 = value2;
		if (index3 != index2)
		{
			value3 = getKnotValue(index3) iferr_return;
		}
		const FloatType CR00 = FloatType(-0.5);
		const FloatType CR01 = FloatType( 1.5);
		const FloatType CR02 = FloatType(-1.5);
		const FloatType CR03 = FloatType( 0.5);
		const FloatType CR10 = FloatType( 1.0);
		const FloatType CR11 = FloatType(-2.5);
		const FloatType CR12 = FloatType( 2.0);
		const FloatType CR13 = FloatType(-0.5);
		const FloatType CR20 = FloatType(-0.5);
		const FloatType CR21 = FloatType( 0.0);
		const FloatType CR22 = FloatType( 0.5);
		const FloatType CR23 = FloatType( 0.0);
		const FloatType CR30 = FloatType( 0.0);
		const FloatType CR31 = FloatType( 1.0);
		const FloatType CR32 = FloatType( 0.0);
		const FloatType CR33 = FloatType( 0.0);

		const ValueType c0 = CR00 * value0 + CR01 * value1 + CR02 * value2 + CR03 * value3;
		const ValueType c1 = CR10 * value0 + CR11 * value1 + CR12 * value2 + CR13 * value3;
		const ValueType c2 = CR20 * value0 + CR21 * value1 + CR22 * value2 + CR23 * value3;
		const ValueType c3 = CR30 * value0 + CR31 * value1 + CR32 * value2 + CR33 * value3;

		ValueType blendedValue = ((c0 * weight + c1) * weight + c2) * weight + c3;

		const ValueType minValue = Min(value0, Min(value1, Min(value2, value3)));
		const ValueType maxValue = Max(value0, Max(value1, Max(value2, value3)));

		// Avoid overshoot of cubic interpolation by clamping to the value range of the support points.
		blendedValue = Max(blendedValue, minValue);
		blendedValue = Min(blendedValue, maxValue);
		return blendedValue;
	}

public:

	//----------------------------------------------------------------------------------------
	/// Samples the gradient at the requested position.
	/// @tparam ValueType											The type of value to sample.
	/// @tparam SortedKnotsType								The type of sorted knot sequence.
	/// @tparam GetKnotValueFunc							The type of value sample function.
	/// @tparam GetKnotInterpolationModeFunc	The type of interpolation mode sample function.
	/// @tparam GetKnotBiasFunc								The type of bias sample function.
	/// @param[in] absolutePosition						The position to sample in the gradient.
	/// @param[in] sortedKnots								The sorted knot sequence.
	/// @param[in] getKnotValue								The value sample function..
	/// @param[in] getKnotInterpolationMode		The interpolation mode sample function.
	/// @param[in] getKnotBias								The bias sample function.
	/// @return																The sampled value on success, error otherwise.
	//----------------------------------------------------------------------------------------
	template <typename ValueType, typename SortedKnotsType, typename GetKnotValueFunc, typename GetKnotInterpolationModeFunc, typename GetKnotBiasFunc>
	Result<ValueType> Sample(typename SortedKnotsType::FloatType absolutePosition, const SortedKnotsType& sortedKnots, const GetKnotValueFunc& getKnotValue, const GetKnotInterpolationModeFunc& getKnotInterpolationMode, const GetKnotBiasFunc& getKnotBias) const
	{
		iferr_scope;

		using FloatType = typename SortedKnotsType::FloatType;
		using IntType = typename SortedKnotsType::IntType;
		using IndexedKnotType = typename SortedKnotsType::IndexedKnotType;

		if (sortedKnots.IsEmpty() == true)
		{
			return ValueType();
		}

		const IndexedKnotType& leftKnot = sortedKnots.GetSampleKnot(absolutePosition);
		const IndexedKnotType& rightKnot = sortedKnots.GetRight(leftKnot);

		const FloatType delta = rightKnot._position - leftKnot._position;

		if (delta == 0)
		{
			// If two knots have identical positions, return the value of the first one
			return getKnotValue(leftKnot._index);
		}

		const UInt interpolationMode = getKnotInterpolationMode(leftKnot._index) iferr_return;

		if (interpolationMode == InterpolationNone)
		{
			// We early-out for constant interpolation as we do not require the knot bias.
			return getKnotValue(leftKnot._index);
		}

		const FloatType relativePosition = (absolutePosition - leftKnot._position) / delta;
		const FloatType bias = getKnotBias(leftKnot._index) iferr_return;

		switch (interpolationMode)
		{
			case InterpolationNone:
			{
				// We add this already handled case to force a compile error if there's collisions among the mode indices.
				break;
			}
			case InterpolationLinearKnot:
			{
				const FloatType weight = GetBiasedWeight(relativePosition, bias);
				return BlendTwoValuesLinear<ValueType>(leftKnot._index, rightKnot._index, weight, getKnotValue);
			}
			case InterpolationSmoothKnot:
			{
				const FloatType weight = GetBiasedWeight(relativePosition, bias);
				return BlendTwoValuesLinear<ValueType>(leftKnot._index, rightKnot._index, SmoothStep(FloatType(0.0), FloatType(1.0), weight), getKnotValue);
			}
			case InterpolationBlend:
			{
				if (relativePosition < bias)
				{
					return getKnotValue(leftKnot._index);
				}
				const FloatType weight = Blend(FloatType(0.0), FloatType(1.0), BoxStep(bias, FloatType(1.0), relativePosition));
				return BlendTwoValuesLinear<ValueType>(leftKnot._index, rightKnot._index, weight, getKnotValue);
			}
			case InterpolationCubicKnot:
			{
				const IndexedKnotType& knot0 = sortedKnots.GetLeft(leftKnot);
				const IndexedKnotType& knot1 = leftKnot;
				const IndexedKnotType& knot2 = rightKnot;
				const IndexedKnotType& knot3 = sortedKnots.GetRight(knot2);

				const FloatType weight = GetBiasedWeight(relativePosition, bias);
				return BlendFourValues<ValueType>(knot0._index, knot1._index, knot2._index, knot3._index, weight, getKnotValue);
			}
			case InterpolationCubicBias:
			{
				const FloatType biasLeft = Blend(FloatType(0.0), FloatType(1.0) - bias, FloatType(0.75));
				const FloatType biasRight = Blend(FloatType(1.0) - bias, FloatType(1.0), FloatType(0.25));
				const Vec4<FloatType> cubicWeights = GetCubicBlendWeights(relativePosition);
				return BlendTwoValuesCubic<ValueType>(leftKnot._index, rightKnot._index, biasLeft, biasRight, cubicWeights, getKnotValue);
			}
		}
		return IllegalStateError(MAXON_SOURCE_LOCATION, "Unknown gradient interpolation mode."_s);
	}
};

/// This class adds a little convenience to setup a gradient for a set of interpolation modes given as MAXON_ATTRIBUTE.
/// For example, a gradient can be configured as such:
/// @code
///
/// // We setup the knot sequence.
/// maxon::Color knotValues[2] = { maxon::Color(0), maxon::Color(1) };
/// maxon::SortedGradientKnots<Float, Int> sortedKnots;
/// sortedKnots.InsertKnot(0.0) iferr_return;
/// sortedKnots.InsertKnot(1.0) iferr_return;
/// sortedKnots.Sort() iferr_return;
/// 
/// // We setup the gradient sampler instance.
/// using InterpolationNone = decltype(maxonexample::DATATYPE::PORTBUNDLE::GRADIENT::INTERPOLATION_ENUM_NONE);
/// using InterpolationLinearKnot = decltype(maxonexample::DATATYPE::PORTBUNDLE::GRADIENT::INTERPOLATION_ENUM_LINEARKNOT);
/// using InterpolationSmoothKnot = decltype(maxonexample::DATATYPE::PORTBUNDLE::GRADIENT::INTERPOLATION_ENUM_SMOOTHKNOT);
/// using InterpolationBlend = decltype(maxonexample::DATATYPE::PORTBUNDLE::GRADIENT::INTERPOLATION_ENUM_BLEND);
/// using InterpolationCubicKnot = decltype(maxonexample::DATATYPE::PORTBUNDLE::GRADIENT::INTERPOLATION_ENUM_CUBICKNOT);
/// using InterpolationCubicBias = decltype(maxonexample::DATATYPE::PORTBUNDLE::GRADIENT::INTERPOLATION_ENUM_CUBICBIAS);
/// maxon::GradientSampler<InterpolationNone, InterpolationLinearKnot, InterpolationSmoothKnot, InterpolationBlend, InterpolationCubicKnot, InterpolationCubicBias> gradientSampler;
/// 
/// auto GetKnotValue = [&knotValues](Int index)
/// {
/// 	return knotValues[index];
/// };
/// 
/// auto GetKnotInterpolationMode = [](Int index)
/// {
/// 	return InterpolationLinearKnot::HASHCODE::value;
/// };
/// 
/// auto GetKnotBias = [](Int index)
/// {
/// 	return Float(0.5);
/// };
/// 
/// // We sample the gradient in the middle.
/// const maxon::Color gray = gradientSampler.Sample<maxon::Color>(0.5, sortedKnots, GetKnotValue, GetKnotInterpolationMode, GetKnotBias) iferr_return;
///
/// @endcode
template <typename T_ModeNone, typename T_ModeLinearKnot, typename T_ModeSmoothKnot, typename T_ModeBlend, typename T_ModeCubicKnot, typename T_ModeCubicBias>
class GradientSampler : 
	public IndexedGradientSampler <T_ModeNone::HASHCODE::value, T_ModeLinearKnot::HASHCODE::value,
	T_ModeSmoothKnot::HASHCODE::value, T_ModeBlend::HASHCODE::value,
	T_ModeCubicKnot::HASHCODE::value, T_ModeCubicBias::HASHCODE::value>
{
};

} // namespace maxon

#endif // GRADIENTMATH_H__
