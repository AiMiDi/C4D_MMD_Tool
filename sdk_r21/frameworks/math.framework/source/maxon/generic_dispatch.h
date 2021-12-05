#ifndef GENERIC_DISPATCH_H__
#define GENERIC_DISPATCH_H__

#include "maxon/array.h"
#include "matrix_nxm.h"

namespace maxon
{

//----------------------------------------------------------------------------------------
/// DefaultReification can be used as template argument to Dispatch1.
/// It supports generic arguments of the types
/// - Data
/// - ArrayInterface
/// - WritableArrayInterface
//----------------------------------------------------------------------------------------
class DefaultReification
{
public:
	//-----------------------  Data -----------------------------------------------
	static const DataType& GetType(const Data& arg)
	{
		return arg.GetType();
	}

	template <typename T> static const T& Reify(const Data& data)
	{
		return *data.GetPtr<T>();
	}

	template <typename T> static T& Reify(Data& data)
	{
		return *data.GetPtr<T>();
	}

	template <typename T> static T&& Reify(Data&& data)
	{
		return std::move(*data.GetPtr<T>());
	}


	//-----------------------  ArrayInterface -----------------------------------------------
	static const DataType& GetType(const ArrayInterface<Generic>& arg)
	{
		return arg.GetValueDataType();
	}

	template <typename T, typename T2> static const ArrayInterface<T>& Reify(const ArrayInterface<T2>& array)
	{
		return reinterpret_cast<const ArrayInterface<T>&>(array);
	}

	template <typename T, typename T2> static ArrayInterface<T>& Reify(ArrayInterface<T2>& array)
	{
		return reinterpret_cast<ArrayInterface<T>&>(array);
	}

	template <typename T, typename T2> static ArrayInterface<T>&& Reify(ArrayInterface<T2>&& array)
	{
		return std::move(reinterpret_cast<ArrayInterface<T>&>(array));
	}


	//-----------------------  WritableArrayInterface -----------------------------------------------
	static const DataType& GetType(WritableArrayInterface<Generic>& arg)
	{
		return arg.GetValueDataType();
	}

	template <typename T, typename T2> static WritableArrayInterface<T>& Reify(WritableArrayInterface<T2>& array)
	{
		return reinterpret_cast<WritableArrayInterface<T>&>(array);
	}

	template <typename T, typename T2> static WritableArrayInterface<T>&& Reify(WritableArrayInterface<T2>&& array)
	{
		return std::move(reinterpret_cast<WritableArrayInterface<T>&>(array));
	}

	//-----------------------  MatrixNxM -----------------------------------------------
	static const DataType& GetType(const MatrixNxMInterface& arg)
	{
		return arg.GetValueDataType();
	}

	template <typename T> static MatrixNxM<T>& Reify(const MatrixNxMInterface& array)
	{
		return reinterpret_cast<MatrixNxM<T>&>(array.GetMatrix());
	}

	static const DataType& GetType(const ConstMatrixNxMInterface& arg)
	{
		return arg.GetValueDataType();
	}

	template <typename T> static const MatrixNxM<T>& Reify(const ConstMatrixNxMInterface& array)
	{
		return reinterpret_cast<const MatrixNxM<T>&>(array.GetMatrix());
	}

};


//----------------------------------------------------------------------------------------
/// Dispatch1 can be used to dispatch a generic invocation to a non-generic
/// function based on the runtime (reified) type of the first argument. You have to put
/// the non-generic functions in a class (typically you'll only have a single function template
/// which covers all cases, but you may also use several overloaded functions), and they
/// have to be named @c Do:
/// @code
/// class MyAlgorithm
/// {
/// public:
///		template <typename T> static Result<void> Do(const ArrayInterface<T>& array, Int someParam);
/// };
/// @endcode
/// Then if you have a <tt>ArrayInterface<Generic></tt>, you can dispatch to the matching
/// template instantiation by writing
/// @code
/// Dispatch1<MyAlgorithm, std::tuple<Int, Float, Vector>>::Do(array, 42) iferr_return;
/// @endcode
/// This would dispatch the types Int, Float and Vector, for all other types an error will be returned.
///
/// If you want to dispatch based on the second argument, use Dispatch2. You can also nest Dispatch2 within Dispatch1
/// for a double-dispatch as in
/// @code
/// class MyAlgorithm2
/// {
/// public:
///		template <typename T1, typename T2> static Result<void> Do(const ArrayInterface<T1>& array1, const ArrayInterface<T2>& array2, Int someParam);
/// };
/// ...
/// Dispatch1<Dispatch2<MyAlgorithm2, std::tuple<Int, Float>>, std::tuple<Int, Float>>::Do(array1, array2, 42) iferr_return;
/// @endcode
/// This would allow all combinations of Int and Float. Note that for a large number of combinations, the compiler has to create a lot of code.
///
/// @tparam ALGORITHM							The algorithm to invoke. The class has to contain a function template and/or overloaded functions named @c Do.
///																These functions will be invoked based on the reified type of the generic argument.
/// @tparam TYPES									List of types which shall be supported of the form <tt>std::tuple<TYPE1, TYPE2, ...></tt>.
///																If the runtime type doesn't match one of these types, an error is returned.
/// @tparam REIFICATION						The reification class is used to obtain the runtime DataType from the generic argument.
///																It has to contain a GetType function for this purpose, and also a function template which
///																converts the generic argument into the reified argument. By default, DefaultReification
///																is used which supports Data, ArrayInterface and WritableArrayInterface.
//----------------------------------------------------------------------------------------
template <typename ALGORITHM, typename TYPES, typename REIFICATION = DefaultReification> class Dispatch1;

#ifdef MAXON_COMPILER_MSVC
#pragma warning(push)
#pragma warning(disable:4706)	// assignment within conditional expression
#endif

template <typename ALGORITHM, typename REIFICATION, typename... TYPES> class Dispatch1<ALGORITHM, std::tuple<TYPES...>, REIFICATION>
{
public:
	using FirstType = typename SFINAEHelper<TYPES...>::type;

	template <typename G, typename... ARGS> static auto Do(G&& genericArg, ARGS&&... args) -> decltype(ALGORITHM::Do(REIFICATION::template Reify<FirstType>(std::forward<G>(genericArg)), std::forward<ARGS>(args)...))
	{
		Bool found = false;
		decltype(ALGORITHM::Do(REIFICATION::template Reify<FirstType>(std::forward<G>(genericArg)), std::forward<ARGS>(args)...)) result;
		const DataType& t = REIFICATION::GetType(genericArg);
#ifdef MAXON_COMPILER_GCC
	#pragma GCC diagnostic push // GCC bug 65866
	#pragma GCC diagnostic ignored "-Wsequence-point"
#endif
		// TODO: (Ole) add std::forward once this has been fixed in MSVC
		ForEach{ ((t.Is<TYPES>()) && (result = ALGORITHM::Do(REIFICATION::template Reify<TYPES>(std::forward<G>(genericArg)), args...), found = true))... };
#ifdef MAXON_COMPILER_GCC
	#pragma GCC diagnostic pop
#endif
		if (!found)
			return UnsupportedArgumentError(SourceLocation(__FILE__, __LINE__), FormatString("Generic argument has unsupported type @.", t));
		return result;
	}
};


//----------------------------------------------------------------------------------------
/// Dispatch2 is similar to Dispatch1, but it dispatches based on the second argument instead of the first.
//----------------------------------------------------------------------------------------
template <typename ALGORITHM, typename TYPES, typename REIFICATION = DefaultReification> class Dispatch2;

template <typename ALGORITHM, typename REIFICATION, typename... TYPES> class Dispatch2<ALGORITHM, std::tuple<TYPES...>, REIFICATION>
{
public:
	using FirstType = typename SFINAEHelper<TYPES...>::type;

	template <typename ARG1, typename G, typename... ARGS> static auto Do(ARG1&& arg1, G&& genericArg, ARGS&&... args) -> decltype(ALGORITHM::Do(std::forward<ARG1>(arg1), REIFICATION::template Reify<FirstType>(std::forward<G>(genericArg)), std::forward<ARGS>(args)...))
	{
		Bool found = false;
		decltype(ALGORITHM::Do(std::forward<ARG1>(arg1), REIFICATION::template Reify<FirstType>(std::forward<G>(genericArg)), std::forward<ARGS>(args)...)) result;
		const DataType& t = REIFICATION::GetType(genericArg);
#ifdef MAXON_COMPILER_GCC
	#pragma GCC diagnostic push // GCC bug 65866
	#pragma GCC diagnostic ignored "-Wsequence-point"
#endif
		// TODO: (Ole) add std::forward once this has been fixed in MSVC
		ForEach{((t.Is<TYPES>()) && (result = ALGORITHM::Do(std::forward<ARG1>(arg1), REIFICATION::template Reify<TYPES>(std::forward<G>(genericArg)), args...), found = true))...};
#ifdef MAXON_COMPILER_GCC
	#pragma GCC diagnostic pop
#endif
		if (!found)
			return UnsupportedArgumentError(SourceLocation(__FILE__, __LINE__), FormatString("Generic argument has unsupported type @.", t));
		return result;
	}
};


#ifdef MAXON_COMPILER_MSVC
#pragma warning(pop)
#endif


} // namespace maxon

#endif // GENERIC_DISPATCH_H__
