#ifndef GENERICFUNCTION_H__
#define GENERICFUNCTION_H__

#include "maxon/object.h"
#include "maxon/dynamic_tuple.h"

namespace maxon
{

//----------------------------------------------------------------------------------------
/// @MAXON_ANNOTATION{refprefix=Generic}
//----------------------------------------------------------------------------------------
class FunctionInterface : MAXON_INTERFACE_BASES(Object)
{
	MAXON_INTERFACE(FunctionInterface, MAXON_REFERENCE_CONST, "net.maxon.interface.function");
public:
	MAXON_METHOD const FunctionDataType* GetFunctionType() const;

	MAXON_METHOD Result<void> Invoke(DynamicTupleInterface* outputs, DynamicTupleInterface* inputs) const;

	MAXON_METHOD Result<void> Invoke(DynamicTupleInterface* outputs, DynamicTupleInterface* inputs, Data& cacheData) const;

	MAXON_METHOD ConstDataPtr GetConstantValue(const Member& output) const;
};


#include "genericfunction1.hxx"

template <typename> class Function;

namespace details
{
template <typename SIG> class FunctionWrapper;

template <typename RESULT, typename... ARGS> class FunctionWrapper<Function<RESULT(ARGS...)>>
{
public:
	template <typename F> static Result<void> Invoke(F* function, DynamicTupleInterface* outputs, DynamicTupleInterface* inputs)
	{
		Generic* inPtrs[sizeof...(ARGS)];
		inputs->GetMemberPointers(inPtrs, NamedTuple<ARGS...>::GetDataType());
		Generic* outPtr = outputs->GetMemberPointer(RESULT::GetInstance());
		RESULT::Get(outPtr) = (*function)(GetParam<ARGS>(inPtrs)...);
		return OK;
	}

private:
	template <typename P> static typename P::GetType GetParam(Generic* const* params)
	{
		return P::Get(params[ParameterPack<ARGS...>::template IndexOf<P>::value]);
	}
};
}


class FunctionLib
{
	MAXON_INTERFACE_NONVIRTUAL(FunctionLib, MAXON_REFERENCE_NONE, "net.maxon.interface.functionlib");
public:
	static MAXON_METHOD Class<GenericFunction> GetConstantFunctionClass();

	//----------------------------------------------------------------------------------------
	/// @param[in] value							TODO: (Ole) please document.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<GenericFunction> CreateConstantFunction(InternedId outputId, const DataType* resultType, const ConstDataPtr& value);

	template <typename RESULT> static Result<Function<RESULT()>> CreateConstantFunction(const typename std::decay<typename RESULT::Type>::type& value)
	{
		iferr_scope;
		GenericFunction g = CreateConstantFunction(RESULT::GetId(), GetDataType<typename RESULT::Type, GET_DATATYPE_POLICY::NO_DECAY>(), ConstDataPtr(value)) iferr_return;
		return std::move(reinterpret_cast<Function<RESULT()>&>(g));
	}

	using DestructWrapper = void (*) (const void*);
	using InvokeWrapper = Result<void> (*) (void*, DynamicTupleInterface* outputs, DynamicTupleInterface* inputs);

	template <typename FUNC, typename FN> static Result<FUNC> CreateWrapper(FN&& function)
	{
		iferr_scope;
		using F = typename std::decay<FN>::type;
		F* fn = NewObj(F, std::forward<FN>(function)) iferr_return;
		GenericFunction g = PrivateCreateWrapper(fn, GetDataType<FUNC>(), (FunctionLib::DestructWrapper) &Destruct<F>, (InvokeWrapper) &maxon::details::FunctionWrapper<FUNC>::template Invoke<F>) iferr_return;
		return std::move(reinterpret_cast<FUNC&>(g));
	}

private:
	static MAXON_METHOD Result<GenericFunction> PrivateCreateWrapper(void* function, const DataType* type, DestructWrapper destruct, InvokeWrapper invoke);
};


namespace details
{
template <typename RESULT> struct FunctionResultHelper
{
	using type = NamedTuple<RESULT>;
	using ResultType = typename GetMemberType<RESULT>::type::Type;
};

template <typename... ARGS> struct FunctionResultHelper<Tuple<ARGS...>>
{
	using type = NamedTuple<ARGS...>;
	using ResultType = typename type::TupleType;
};

template <typename... ARGS> struct FunctionResultHelper<NamedTuple<ARGS...>>
{
	using type = NamedTuple<ARGS...>;
	using ResultType = typename type::TupleType;
};
}

template <typename RESULT, typename... ARGS> class Function<RESULT(ARGS...)> : public GenericFunction
{
public:
	using ResultHelper = maxon::details::FunctionResultHelper<RESULT>;
	using Outputs = typename ResultHelper::type;
	using Inputs = NamedTuple<ARGS...>;

	template <typename SRC> struct CheckSrc
	{
		static const Bool value = std::is_same<SRC, RESULT(ARGS...)>::value || (Inputs::ALL_NAMED && Outputs::ALL_NAMED && Inputs::template ContainsAll<typename Function<SRC>::Inputs>::value && Function<SRC>::Outputs::template ContainsAll<Outputs>::value);
	};

	Function() = default;

	template <typename SRC, typename = typename std::enable_if<CheckSrc<SRC>::value>::type>
	Function(const Function<SRC>& src) : GenericFunction(src)
	{
	}

	template <typename SRC, typename = typename std::enable_if<CheckSrc<SRC>::value>::type>
	Function(Function<SRC>&& src) : GenericFunction(std::move(src))
	{
	}

	template <typename SRC, typename = typename std::enable_if<CheckSrc<SRC>::value>::type>
	Function& operator =(const Function<SRC>& src)
	{
		this->GenericFunction::operator =(src);
		return *this;
	}

	template <typename SRC, typename = typename std::enable_if<CheckSrc<SRC>::value>::type>
	Function& operator =(Function<SRC>&& src)
	{
		this->GenericFunction::operator =(std::move(src));
		return *this;
	}

	Result<typename ResultHelper::ResultType> operator ()(typename GetMemberType<ARGS>::type::Type... params) const
	{
		iferr_scope;
		DynamicTupleImpl<Inputs> p{params...};
		DynamicTupleImpl<Outputs, true> r;
		Invoke(r.ToInterface(), p.ToInterface()) iferr_return;
		if (std::is_same<typename ResultHelper::ResultType, typename Outputs::TupleType>::value)
			return reinterpret_cast<typename ResultHelper::ResultType&&>(r._value);
		else
			return reinterpret_cast<typename ResultHelper::ResultType&&>(reinterpret_cast<typename Outputs::TupleType&>(r._value).template Get<0>());
	}

	Result<typename ResultHelper::ResultType> operator ()(typename GetMemberType<ARGS>::type::Type... params, Data& cacheData) const
	{
		iferr_scope;
		DynamicTupleImpl<Inputs> p{params...};
		DynamicTupleImpl<Outputs, true> r;
		Invoke(r.ToInterface(), p.ToInterface(), cacheData) iferr_return;
		if (std::is_same<typename ResultHelper::ResultType, typename Outputs::TupleType>::value)
			return reinterpret_cast<typename ResultHelper::ResultType&&>(r._value);
		else
			return reinterpret_cast<typename ResultHelper::ResultType&&>(reinterpret_cast<typename Outputs::TupleType&>(r._value).template Get<0>());
	}
};


template <GET_DATATYPE_POLICY POLICY, typename SIG> inline Result<const DataType*> PrivateGetDataType(Function<SIG>*, OverloadRank0)
{
	return DataTypeLib::GetFunctionType(Function<SIG>::Outputs::GetDataType(), Function<SIG>::Inputs::GetDataType());
}

#include "genericfunction2.hxx"

} // namespace maxon

#endif // GENERICFUNCTION_H__
