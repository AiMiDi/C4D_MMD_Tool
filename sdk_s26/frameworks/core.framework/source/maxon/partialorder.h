#ifndef PARTIALORDER_H__
#define PARTIALORDER_H__

#include "maxon/basearray.h"

namespace maxon
{

namespace details
{
template <typename COMPARE> struct LessThanOrEqualAsLessThan
{
	template <typename T> static Bool LessThan(const T& a, const T& b)
	{
		return COMPARE::LessThanOrEqual(a, b);
	}
};
}

//----------------------------------------------------------------------------------------
/// MaximalElements finds the maximal elements of a set of values with a partial order.
/// A maximal element of such a set is an element which is not less than any other element of the set.
/// A partially ordered set may have more than one maximal element.
///
/// To use MaximalElements, add all values via the Append function. Afterwards, you can use MaximalElements
/// like an array, it then will contain the maximal elements of all added values.
///
/// For comparison, MaximalElements uses the operator < on the values by default (or <= when KEEP_DUPLICATES is true), but you can override this with the #COMPARE parameter.
///
/// @tparam T											The type of values. There has to be a partial order on @p T defined by COMPARE.
/// @tparam ARRAY									An array selector template to choose the array implementation to use.
/// @tparam COMPARE								The static LessThan function (or LessThanOrEqual when KEEP_DUPLICATES is true) of COMPARE is used for value comparisons.
/// @tparam KEEP_DUPLICATES				If true, elements of the set which are equal will be kept each in the array, otherwise only one of them will be in the array.
/// @tparam MINIMAL								If true, find the minimal elements instead. Still only < or <= are used.
///
/// @see MinimalElements
//----------------------------------------------------------------------------------------
template <typename T, typename ARRAY = BaseArraySelector<>, typename COMPARE = DefaultCompare, Bool KEEP_DUPLICATES = false, Bool MINIMAL = false> class MaximalElements : private ARRAY::template Type<T>
{
	using Super = typename ARRAY::template Type<T>;
	using Cmp = typename std::conditional<KEEP_DUPLICATES, COMPARE, maxon::details::LessThanOrEqualAsLessThan<COMPARE>>::type;

public:
	using Super::GetCount;
	using Super::IsEmpty;
	using Super::IsPopulated;
	using Super::ToString;
	using Super::Flush;
	using Super::Reset;
	using Super::Begin;
	using Super::End;
	using Super::operator [];
	using typename Super::ConstIterator;
	using typename Super::ValueType;

	const Super& GetUnderlyingArray() const
	{
		return *this;
	}

	Super& GetUnderlyingArray()
	{
		return *this;
	}

	Result<void> Append(const T& value)
	{
		return AppendImpl(value);
	}

	Result<void> Append(T&& value)
	{
		return AppendImpl(std::move(value));
	}

private:
	template <typename A> Result<void> AppendImpl(A&& value)
	{
#ifdef MAXON_TARGET_DEBUG
		Bool max = false;
#endif
		for (auto it = this->End(); it != this->Begin(); )
		{
			--it;
			if (MINIMAL ? COMPARE::LessThan(value, *it) : COMPARE::LessThan(*it, value))
			{
				if (this->Erase(it) == decltype(it)())
					DebugStop("This cannot happen.");
#ifdef MAXON_TARGET_DEBUG
				max = true;
#endif
			}
			else if (MINIMAL ? Cmp::LessThan(*it, value) : Cmp::LessThan(value, *it))
			{
				DebugAssert(!max);
				return OK;
			}
		}
		return Super::Append(std::forward<A>(value));
	}
};


//----------------------------------------------------------------------------------------
/// MinimalElements finds the minimal elements of a set of values with a partial order.
/// A minimal element of such a set is an element which is not greater than any other element of the set.
/// A partially ordered set may have more than one minimal element.
///
/// To use MinimalElements, add all values via the Append function. Afterwards, you can use MinimalElements
/// like an array, it then will contain the minimal elements of all added values.
///
/// For comparison, MinimalElements uses the operator < on the values by default (or <= when KEEP_DUPLICATES is true), but you can override this with the #COMPARE parameter.
///
/// @tparam T											The type of values. There has to be a partial order on @p T defined by COMPARE.
/// @tparam ARRAY									An array selector template to choose the array implementation to use.
/// @tparam COMPARE								The static LessThan function (or LessThanOrEqual when KEEP_DUPLICATES is true) of COMPARE is used for value comparisons.
/// @tparam KEEP_DUPLICATES				If true, elements of the set which are equal will be kept each in the array, otherwise only one of them will be in the array.
///
/// @see MaximalElements
//----------------------------------------------------------------------------------------
template <typename T, typename ARRAY = BaseArraySelector<>, typename COMPARE = DefaultCompare, Bool KEEP_DUPLICATES = false> using MinimalElements = MaximalElements<T, ARRAY, COMPARE, KEEP_DUPLICATES, true>;

} // namespace maxon

#endif // PARTIALORDER_H__
