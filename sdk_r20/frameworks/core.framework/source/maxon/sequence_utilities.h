#ifndef SEQUENCE_UTILITIES_H__
#define SEQUENCE_UTILITIES_H__

#include "maxon/apibase.h"

namespace maxon
{


template <typename SEQUENCE, size_t VALUE> struct AppendToIndexSequence;

template <size_t VALUE, size_t... SEQ> struct AppendToIndexSequence<std::index_sequence<SEQ...>, VALUE>
{
	using type = std::index_sequence<SEQ..., VALUE>;
};

namespace details
{

template <Bool ZERO_BASED, typename SEQUENCE, size_t SUM, size_t... VALUES> struct PartialSumSequenceHelper;

template <Bool ZERO_BASED, typename SEQUENCE, size_t SUM> struct PartialSumSequenceHelper<ZERO_BASED, SEQUENCE, SUM>
{
	using type = SEQUENCE;
};

template <Bool ZERO_BASED, typename SEQUENCE, size_t SUM, size_t X, size_t... REST>
struct PartialSumSequenceHelper<ZERO_BASED, SEQUENCE, SUM, X, REST...>
	: public PartialSumSequenceHelper<ZERO_BASED, typename AppendToIndexSequence<SEQUENCE, ZERO_BASED ? SUM : SUM + X>::type, SUM + X,
			REST...>
{
};

}

template <Bool ZERO_BASED, size_t... VALUES> using PartialSumSequence = typename maxon::details::PartialSumSequenceHelper<ZERO_BASED, std::index_sequence<>, 0, VALUES...>::type;


template <typename T, size_t INDEX, T VALUE, T... REST> struct SequenceElement : public SequenceElement<T, INDEX - 1, REST...>
{
};

template <typename T, T VALUE, T... REST> struct SequenceElement<T, 0, VALUE, REST...>
{
	static const T value = VALUE;
};


template <typename SEQUENCE, size_t INDEX> struct IndexSequenceElement;

template <size_t INDEX, size_t... VALUES> struct IndexSequenceElement<std::index_sequence<VALUES...>, INDEX> : public SequenceElement<size_t, INDEX, VALUES...>
{
};


template <typename T, T... VALUES> struct GetSequenceElement
{
	static T Get(Int index)
	{
		DebugAssert(UInt(index) < UInt(sizeof...(VALUES)));
		return _values[index];
	}

	static const T _values[sizeof...(VALUES)];
};

template <typename T, T... VALUES> const T GetSequenceElement<T, VALUES...>::_values[sizeof...(VALUES)] = {VALUES...};

template <typename T, T V0> struct GetSequenceElement<T, V0>
{
	static T Get(Int index)
	{
		DebugAssert(index == 0);
		return V0;
	}
};

template <typename T, T V0, T V1> struct GetSequenceElement<T, V0, V1>
{
	static T Get(typename std::conditional<std::is_integral<T>::value, const DummyParamType&, Int>::type index)
	{
		DebugAssert(UInt(index) < UInt(2));
		return index ? V1 : V0;
	}

	static T Get(typename std::conditional<std::is_integral<T>::value, Int, const DummyParamType&>::type index)
	{
		DebugAssert(UInt(index) < UInt(2));
		T mask = typename std::make_signed<T>::type(index) - 1; // mask will be 0000... for index 1 and 1111... for index 0
		return (mask & V0) | (~mask & V1);
	}
};


template <typename SEQUENCE> struct GetIndexSequenceElement;

template <size_t... VALUES> struct GetIndexSequenceElement<std::index_sequence<VALUES...>> : public GetSequenceElement<size_t, VALUES...>
{
};


//----------------------------------------------------------------------------------------
/// IndexInIndexSequence finds the index of I in the template type SEQENCE which has to be an std::index_sequence type.
/// The index can be found in the member #value of IndexInIndexSequence. If there is no unique such index
/// because I doesn't exist at all in SEQUENCE or exists more than once, a negative value is used.
/// @tparam I											Value to search for.
/// @tparam SEQUENCE							An std::index_sequence type.
//----------------------------------------------------------------------------------------
template <size_t I, typename SEQUENCE> struct IndexInIndexSequence
{
	static const Int value = LIMIT<Int>::MIN;
	static const Bool found = false;
};

template <size_t I, size_t X, size_t... LIST> struct IndexInIndexSequence<I, std::index_sequence<X, LIST...>>
{
	using Rest = IndexInIndexSequence<I, std::index_sequence<LIST...>>;
	static const Bool found = Rest::found || I == X;
	static const Int value = I != X ? Rest::value + 1 : Rest::found ? LIMIT<Int>::MIN : 0;
};


} // namespace maxon

#endif // SEQUENCE_UTILITIES_H__
